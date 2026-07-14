#!/usr/bin/env python3
"""Text-coverage regression audit: prove every pointer-table-reachable text in the ROM
is owned by a translation section (or is explicitly accounted for).

CLAIMED set — derived from the SAME extractor code `tr.py extract` runs (tr.extract_all),
plus curated sections' JSON entries: every string addr a section owns, as byte spans.

CANDIDATE set — the ROM-wide pointer-table scan (scan_text_banks logic, min_run lowered
to 4): every dense run of u32 pointers into readable text.

Each candidate table is scored by how many of its targets fall inside claimed spans:
  covered        every target claimed
  partial        some targets claimed
  UNCOVERED      no target claimed             -> exit 1 (new text bank found!)
  covered-code / dead / slots                  -> explicitly accounted for in KNOWN
Plus a DOUBLE-CLAIMED check: no two sections may claim overlapping spans (that is the
"one string, two injection mechanisms" hazard) -> exit 1.

Output: text/review/text-coverage.csv + console summary.
Run after any manifest/extractor change:
    python -m text.script.tools.audit_text_coverage
"""
from __future__ import annotations
import csv
import json
import sys
from pathlib import Path

try:
    from text.script.tools._boot import REVIEW, ROM
except ModuleNotFoundError:
    from _boot import REVIEW, ROM

from text.script import sections, tr  # noqa: E402
from font.atlas import GLYPH_MAP  # noqa: E402
from text.script.tools.scan_text_banks import score_text  # noqa: E402

ROM_BASE = 0x08000000
TR_DIR = tr.TR
CSV_OUT = REVIEW / "text-coverage.csv"

# Pointer tables that are accounted for WITHOUT a translation section. Keyed by table
# source addr. status: covered-code (a build cave already renders English), slots
# (the run is table slots / pointer data, not text), dead (no live reader found).
KNOWN = {
    0x087E3340: ("covered-code", "compendium level ranges: cave_skilllist.c "
                                 "comp_level_vwf synthesizes 'Lv10-19' by address "
                                 "identity (rommap.LEVEL_CAT_BASE) — repoint would break it"),
    0x08032DDC: ("covered-debug", "slot 0 = the orphaned dev debug-menu script "
                                  "(docs/debug-menu.md, no live dispatch); slots 1+ are "
                                  "the negotiation dialogue table (dialogue section)"),
}


def claimed_spans(rom):
    """[(lo, hi, sec_id)] — every byte span of ROM text some section owns."""
    spans = []

    def add_field(sec_id, f):
        # Span length from re-ENCODING the original: byte-exact for story entries whose
        # {=hex} opcode tokens carry args (a raw decode stops at the first 0x0000 arg
        # word and underestimates how far the walker actually consumed). Story entries
        # without "max" ended at a capture-stop, not a terminator — no +2 pad.
        pad = 0 if (sec_id == "story" and "max" not in f) else 2
        orig = f.get("original")
        # A decode flag like <0013> (an op-operand word with no glyph, e.g. 0x445
        # SkillEffect_Exec's effect id) is NOT text: tr.encode would mis-size it as the
        # literal chars '<','0',... and over-read the span into the next table (a false
        # double-claim). Use the ROM decode — it stops at the true 0x0000/0x0301
        # terminator — for those, and when encode can't round-trip.
        try:
            if not orig or "<" in orig:
                raise ValueError
            nbytes = len(tr.encode(orig)) + pad
        except (ValueError, KeyError):
            _t, c = tr.decode(rom, int((f.get("addr") or f["addrs"][0]), 16), 800)
            nbytes = len(c) * 2 + pad
        for a in ([f["addr"]] if f.get("addr") else []) + list(f.get("addrs") or ()):
            lo = int(a, 16)
            spans.append((lo, lo + nbytes, sec_id))

    fresh = tr.extract_all(rom)
    for sec in sections.SECTIONS:
        if sec.source.kind == "msg_id_table":
            # claim every slot target — the extractor dedups identical templates by
            # text and records one addr, but every duplicate copy is owned (its slot
            # is repointed via the entry's ids)
            spans.extend((lo, hi, sec.id) for lo, hi in tr.owned_addrs(rom, [sec.id]))
            continue
        if sec.curated:
            entries = json.loads((TR_DIR / f"{sec.id}.json").read_text(encoding="utf-8"))
            if sec.route == "block_rebuild":
                # Per-fragment spans (single source of truth = tr.owned_addrs): the block is NOT
                # gap-free — a 0x66a hole between the first fragment and the main run holds OTHER
                # sections' strings (system_battle_log battle-log lines, the menu_comp prompt, the
                # names_race battle-copy race names), so the old bounding box double-claimed them.
                # The rebuild relocates only its own fragments, so only those bytes are owned.
                spans.extend((lo, hi, sec.id) for lo, hi in tr.owned_addrs(rom, [sec.id]))
                continue
            if sec.route == "label":
                for e in entries:           # glyph literals in code: 2 bytes per slot
                    for lit, _x in e.get("slots", ()):
                        lo = int(lit, 16)
                        spans.append((lo, lo + 2, sec.id))
                continue
        else:
            entries = fresh[sec.id]
        for e in entries:
            for f in tr.fields(e):
                add_field(sec.id, f)
    return spans


def find_tables(rom, min_run=4, min_frac=0.80, min_len=4):
    """scan_text_banks run-finder with a lower run threshold."""
    runs, run, run_start = [], [], None
    for off in range(0, len(rom) - 4, 4):
        ptr = int.from_bytes(rom[off:off + 4], "little")
        ok = False
        if ROM_BASE <= ptr < ROM_BASE + len(rom) and ptr % 2 == 0:
            frac, ln, _ = score_text(rom, ptr)
            if frac >= min_frac and ln >= min_len:
                ok = True
        if ok:
            if not run:
                run_start = off
            run.append(ptr)
        else:
            if len(run) >= min_run:
                runs.append((ROM_BASE + run_start, run))
            run = []
    if len(run) >= min_run:
        runs.append((ROM_BASE + run_start, run))
    return runs


def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")
    rom = ROM.read_bytes()

    spans = claimed_spans(rom)
    spans.sort()
    # DOUBLE-CLAIM: overlapping spans from two different sections
    doubles = []
    for (alo, ahi, asec), (blo, bhi, bsec) in zip(spans, spans[1:]):
        if blo < ahi and asec != bsec:
            doubles.append((alo, ahi, asec, blo, bhi, bsec))

    def claiming(addr):
        # A few-byte forward tolerance: walkers that start capture at the first GLYPH
        # claim a span beginning just after a string's leading control codes / a
        # preceding pointer's high half — the table's target addr is the same string.
        return sorted({sec for lo, hi, sec in spans
                       if lo <= addr + 6 and addr < hi})

    pool_lo = tr.POOL_START                  # ignore tables inside our own build pool
    tables = [(src, ptrs) for src, ptrs in find_tables(rom)
              if src < pool_lo and not any(lo <= src < hi for lo, hi, _ in spans)]

    rows, n_uncovered = [], 0
    for src, ptrs in tables:
        secs_hit = sorted({s for p in ptrs for s in claiming(p)})
        covered = sum(1 for p in ptrs if claiming(p))
        pct = 100 * covered // len(ptrs)
        if src in KNOWN:
            status, note = KNOWN[src]
        elif pct == 100:
            status, note = "covered", ""
        elif pct > 0:
            status, note = "partial", ""
        else:
            status, note = "UNCOVERED", ""
            n_uncovered += 1
        _f, _n, sample = score_text(rom, ptrs[0], 40)
        rows.append({"table_addr": f"{src:08X}", "entries": len(ptrs),
                     "target_lo": f"{min(ptrs):08X}", "target_hi": f"{max(ptrs):08X}",
                     "covered_pct": pct, "claiming_sections": "+".join(secs_hit),
                     "status": status, "sample": sample[:40], "note": note})

    CSV_OUT.parent.mkdir(parents=True, exist_ok=True)
    with CSV_OUT.open("w", newline="", encoding="utf-8") as fh:
        w = csv.DictWriter(fh, fieldnames=["table_addr", "entries", "target_lo",
                                           "target_hi", "covered_pct",
                                           "claiming_sections", "status", "sample",
                                           "note"])
        w.writeheader()
        w.writerows(rows)

    by_status = {}
    for r in rows:
        by_status[r["status"]] = by_status.get(r["status"], 0) + 1
    print(f"claimed spans: {len(spans)} from {len(sections.SECTIONS)} sections")
    print(f"candidate tables (min_run=4, outside claimed/pool): {len(rows)} -> "
          + ", ".join(f"{k}={v}" for k, v in sorted(by_status.items())))
    for r in rows:
        if r["status"] in ("UNCOVERED", "partial"):
            print(f"  {r['status']:9} {r['table_addr']} x{r['entries']} "
                  f"({r['covered_pct']}% via {r['claiming_sections'] or '-'}) {r['sample']}")
    if doubles:
        print(f"DOUBLE-CLAIMED spans: {len(doubles)}")
        for alo, ahi, asec, blo, bhi, bsec in doubles[:10]:
            print(f"  {asec} [{alo:08X},{ahi:08X}) overlaps {bsec} [{blo:08X},{bhi:08X})")
    print(f"wrote {CSV_OUT}")
    if n_uncovered or doubles:
        print(f"AUDIT FAIL: {n_uncovered} uncovered table(s), {len(doubles)} double-claim(s)")
        return 1
    print("AUDIT PASS")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
