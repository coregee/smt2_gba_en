#!/usr/bin/env python3
"""Reference-site CENSUS — Phase 1 of the text-layout refactor (docs/smt1-coverage-audit.md).

The shipped SMT1 translation proved the DDS engine reaches ~1 in 5 *system* strings through
isolated code-literal / record-field pointers, NOT contiguous pointer tables. Our coverage
audit (audit_text_coverage.py) only scans contiguous tables, so it is blind to that class.

This census enumerates EVERY 32-bit word in the ROM that points at a glyph-token string, then
classifies each reference site two ways:
  * by SHAPE   — `table` (part of a >=4 contiguous run of text pointers) vs `isolated`
                 (a lone literal-pool constant or a record field — the audit's blind spot)
  * by OWNERSHIP — `claimed` (target inside a section's claimed span) vs `unclaimed`

The headline number is **isolated + unclaimed**: text references the current audit cannot see
and no section owns = provable gaps. Reuses the existing detector + claimed-set so it stays
consistent with the audit.

Output: text/review/text-refs-census.csv + console summary.
Run: python -m text.script.tools.census_refs
"""
from __future__ import annotations
import csv, sys
from pathlib import Path

try:
    from text.script.tools._boot import REVIEW, ROM
except ModuleNotFoundError:
    from _boot import REVIEW, ROM

import json  # noqa: E402
from text.script import sections, tr  # noqa: E402
from text.script.tools.scan_text_banks import score_text  # noqa: E402
from text.script.tools.audit_text_coverage import claimed_spans  # noqa: E402

ROM_BASE = 0x08000000
CSV_OUT = REVIEW / "text-refs-census.csv"
TR_DIR = tr.TR
NEAR_WIN = 64        # a target within this many bytes of a translated addr is likely the
                     # SAME string reached by another route (VM walk enters mid-stream) ->
                     # a 2nd, un-repointed reference (leak risk), not a missing source.

FRAC = 0.85          # stricter than the table audit (0.80): isolated singletons need it
MIN_GLYPHS = 4       # at least 4 glyph codes to count as a string target
RUN_TABLE = 4        # >=4 consecutive text pointers (stride 4) = a table


def u32(rom, o): return int.from_bytes(rom[o:o + 4], "little")


def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")
    rom = ROM.read_bytes()
    n = len(rom)
    pool_lo = tr.POOL_START

    # claimed set (same logic the audit uses), as a sorted span list for fast lookup
    spans = sorted(claimed_spans(rom))
    def claiming(addr):
        return sorted({sec for lo, hi, sec in spans if lo <= addr + 6 and addr < hi})

    # every translated addr (any section's JSON) -> nearest-translation triage for the
    # UNCLAIMED set: separates "second reference to translated text" from "missing source".
    tr_addr = {}
    for jf in TR_DIR.glob("*.json"):
        try:
            data = json.loads(jf.read_text(encoding="utf-8"))
        except Exception:
            continue
        for e in (data if isinstance(data, list) else []):
            for a in ([e["addr"]] if e.get("addr") else []) + list(e.get("addrs") or ()):
                tr_addr[int(a, 16)] = jf.stem
    tr_sorted = sorted(tr_addr)

    # content fingerprint of every translated original (CJK-only), to catch DUPLICATE
    # string tables: same JP text stored at a 2nd ROM address, read by another code path,
    # that we translated at the first copy but never repointed here (a JP-leak path).
    def cjk(s):
        return "".join(c for c in s if "぀" <= c <= "ヿ"
                       or "一" <= c <= "鿿")
    orig_blob_parts = []
    for jf in TR_DIR.glob("*.json"):
        try:
            data = json.loads(jf.read_text(encoding="utf-8"))
        except Exception:
            continue
        for e in (data if isinstance(data, list) else []):
            o = e.get("original")
            if isinstance(o, str):
                orig_blob_parts.append(cjk(o))
    orig_blob = "\n".join(orig_blob_parts)
    def content_match(ptr):
        try:
            t, _ = tr.decode(rom, ptr, 60)
        except Exception:
            return False
        c = cjk(t)
        if len(c) < 5:
            return False
        return any(c[i:i + 5] in orig_blob for i in range(0, len(c) - 4, 2))

    import bisect
    def near_tr(t):
        i = bisect.bisect_left(tr_sorted, t)
        best = None
        for j in (i - 1, i):
            if 0 <= j < len(tr_sorted):
                a = tr_sorted[j]
                if abs(a - t) <= NEAR_WIN and (best is None or abs(a - t) < abs(best - t)):
                    best = a
        return (tr_addr[best], best - t) if best is not None else ("", "")

    # 1. every 4-aligned word that points at a glyph-token string
    hits = []                                   # (off, ptr)
    for off in range(0, n - 4, 4):
        if off + ROM_BASE >= pool_lo:           # ignore our own build pool
            continue
        ptr = u32(rom, off)
        if ROM_BASE <= ptr < ROM_BASE + n and ptr % 2 == 0:
            frac, ln, _ = score_text(rom, ptr)
            if frac >= FRAC and ln >= MIN_GLYPHS:
                hits.append((off, ptr))

    # 2. shape: contiguous stride-4 runs => table; else isolated
    shape = {}                                  # off -> "table" | "isolated"
    i = 0
    hofs = [h[0] for h in hits]
    hset = set(hofs)
    runlen = {}
    j = 0
    while j < len(hofs):
        k = j
        while k + 1 < len(hofs) and hofs[k + 1] == hofs[k] + 4:
            k += 1
        rl = k - j + 1
        for m in range(j, k + 1):
            shape[hofs[m]] = "table" if rl >= RUN_TABLE else "isolated"
            runlen[hofs[m]] = rl
        j = k + 1

    # 3. classify + emit
    rows = []
    for off, ptr in hits:
        site = ROM_BASE + off
        # skip a pointer word that itself sits inside a claimed string span (rare)
        if any(lo <= site < hi for lo, hi, _ in spans):
            continue
        sec = claiming(ptr)
        _f, _g, sample = score_text(rom, ptr, 36)
        if sec:
            triage, nf = "", ""
        else:
            nf, _nd = near_tr(ptr)
            if nf or content_match(ptr):
                # leak-risk = points at text we DID translate (by addr or JP content) at
                # another location, but this reference path was never repointed -> JP leak.
                triage = "leak-risk"
            else:
                # no translation anywhere. Split real prose (a notice gap) from non-prose
                # noise: digit/charset/symbol tables + padding runs have few distinct CJK.
                try:
                    dt, _ = tr.decode(rom, ptr, 60)
                except Exception:
                    dt = ""
                distinct = len(set(c for c in dt if "぀" <= c <= "ヿ" or "一" <= c <= "鿿"))
                triage = "MISSING" if distinct >= 3 else "noise"
        rows.append({
            "site": f"{site:08X}",
            "shape": shape[off],
            "run": runlen[off],
            "owned": "claimed" if sec else "UNCLAIMED",
            "section": "+".join(sec),
            "triage": triage,
            "near_tr": nf,
            "target": f"{ptr:08X}",
            "sample": sample[:36],
        })

    CSV_OUT.parent.mkdir(parents=True, exist_ok=True)
    with CSV_OUT.open("w", newline="", encoding="utf-8") as fh:
        w = csv.DictWriter(fh, fieldnames=list(rows[0].keys()))
        w.writeheader(); w.writerows(rows)

    # 4. summary matrix
    def cnt(shape=None, owned=None):
        return sum(1 for r in rows
                   if (shape is None or r["shape"] == shape)
                   and (owned is None or r["owned"] == owned))
    total = len(rows)
    print(f"text-pointer reference sites (excl. build pool): {total}")
    print(f"  by shape  : table={cnt(shape='table')}  isolated={cnt(shape='isolated')}")
    print(f"  by owner  : claimed={cnt(owned='claimed')}  UNCLAIMED={cnt(owned='UNCLAIMED')}")
    print("  matrix:")
    print(f"            claimed   UNCLAIMED")
    for s in ("table", "isolated"):
        print(f"    {s:9} {cnt(s,'claimed'):7}   {cnt(s,'UNCLAIMED'):7}")
    iso_unc = [r for r in rows if r["shape"] == "isolated" and r["owned"] == "UNCLAIMED"]
    leak = [r for r in iso_unc if r["triage"] == "leak-risk"]
    missing = [r for r in iso_unc if r["triage"] == "MISSING"]
    noise = [r for r in iso_unc if r["triage"] == "noise"]
    uniq_missing = {}
    for r in missing:
        uniq_missing.setdefault(r["target"], r)
    print(f"\nUNCLAIMED isolated references: {len(iso_unc)} sites")
    print(f"  (b) leak-risk: text translated elsewhere, this ref path not repointed: "
          f"{len(leak)} sites")
    print(f"  (a) MISSING:   real prose, no translation anywhere (never noticed):    "
          f"{len(missing)} sites, {len(uniq_missing)} unique targets")
    print(f"      noise:     digit/charset/symbol/padding (not translatable):        "
          f"{len(noise)} sites")
    print("\n  MISSING sample (unique targets):")
    for r in list(uniq_missing.values())[:30]:
        print(f"    site {r['site']} -> {r['target']}  {r['sample']}")
    print(f"\nwrote {CSV_OUT}")


if __name__ == "__main__":
    raise SystemExit(main())
