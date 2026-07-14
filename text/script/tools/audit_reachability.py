#!/usr/bin/env python3
"""Reachability-based event-VM coverage audit (the read-side keystone).

`tr.extract_story_vm` is a LINEAR byte-scan of the event-VM bank; `scriptrefs`
heuristically pattern-matches (lo,hi) pointer pairs. NEITHER follows the VM's actual
control flow. This tool walks the engine's control-flow graph (lib/vmflow.py, built
from text/config/opcode_spec.json) from real entry points to answer what the existing
audits can't:

  * TRANSLATE  — a leaf message reachable by jump/choice that no Section extracts (the
    branch-reachable orphan class + interior-target QA bugs).
  * dispatch/interior/duplicate — classified out (control flow / already-captured / dup).
  * CLAIMED-BUT-UNREACHABLE — an extracted entry nothing reaches (NOT reliable until the
    gosub-return pop-stack is modeled; reported as a lead).

Roots = claimed Section entry starts in the bank UNION structural pointer/literal sites
(refmap targets whose ref-site is not inside a claimed prose span). Output:
text/review/text-reachability.csv. Run after any extractor change.
"""
from __future__ import annotations

import csv
from pathlib import Path

try:
    from text.script.tools._boot import REVIEW, ROM, ROOT
except ModuleNotFoundError:
    from _boot import REVIEW, ROM, ROOT

from text.script import tr, vmflow  # noqa: E402
from text.script.tools.audit_text_coverage import claimed_spans  # noqa: E402

CSV_OUT = REVIEW / "text-reachability.csv"
BANK_LO, BANK_HI = 0x08016000, 0x080A8C00                 # the story Section's walk range


def main():
    rom = ROM.read_bytes()
    glyph_map = tr.GLYPH_MAP

    spans = claimed_spans(rom)
    claimed_starts = {lo for lo, _hi, _s in spans if BANK_LO <= lo < BANK_HI}
    owned = set()
    for lo, hi, _s in spans:
        owned.update(range(lo, hi, 2))

    def claimed(addr):                                     # +6 leading tolerance (audit convention)
        return any((addr + d) in owned for d in (0, 2, 4, 6))

    # root = a bank address pointed at by a STRUCTURAL u32 (pointer-table slot or code
    # `ldr` literal) — some ref-site is NOT inside a claimed prose span. Catches the
    # negotiation/dialogue tables (0x0803xxxx, inside the wide bank) and code literals,
    # while excluding (lo,hi) pairs embedded in strings / in-stream jump operands (edges).
    refs = vmflow.build_refmap(rom)
    ext_roots = {t for t, sites in refs.items()
                 if BANK_LO <= t < BANK_HI and any(s not in owned for s in sites)}

    visited, edge_targets, edge_src = vmflow.reachable(
        rom, BANK_LO, BANK_HI, claimed_starts | ext_roots, glyph_map)

    import bisect
    span_list = sorted((lo, hi) for lo, hi, _s in spans if BANK_LO <= lo < BANK_HI)
    span_lo = [lo for lo, _h in span_list]

    def containing(addr):                                  # claimed entry whose span holds addr
        i = bisect.bisect_right(span_lo, addr) - 1
        return span_list[i][0] if i >= 0 and addr < span_list[i][1] else None

    # Classify every reachable branch/jump target by where its MESSAGE actually starts
    # (prose_start skips the dispatch prefix). The headline is the coverage PROOF: of the
    # targets that lead to prose, how many land in an already-captured entry.
    gaps = vmflow.find_leaf_gaps(rom, BANK_LO, BANK_HI, glyph_map, owned, claimed_starts)
    captured = dispatch = 0
    interior = []                                          # (target, entry_start): repoint sites
    for t in sorted(edge_targets):
        g = vmflow.prose_start(rom, t, BANK_LO, BANK_HI, glyph_map)
        if g is None:
            dispatch += 1
            continue
        if claimed(g):
            captured += 1
            es = containing(g)
            if es is not None and t != es:                # jump into a captured entry's interior
                interior.append((t, es))
    reach_prose = captured + len(gaps)

    # --- remap correctness guard: does scriptrefs (the heuristic (lo,hi) scan that drives
    # interior-target repointing) catch every REAL VM jump-edge vmflow finds? A miss = a jump
    # whose target won't be pool-remapped on translation = a branch-loop ("answer No -> JP")
    # bug. Today: 3 known misses, all into the degenerate truncated entry 080A1064. This guard
    # turns that into a regression check — a future opcode/jump that slips past scriptrefs shows
    # up here, not as an in-game softlock. (Byte-neutral: an audit, not a behaviour change.)
    import scriptrefs                                       # noqa: E402
    from text.script import sections as _sections  # noqa: E402
    secdata = tr.extract_all(rom)
    story_id = next(s.id for s in _sections.SECTIONS if s.source.kind == "story_vm")
    sa, oa = set(), set()
    for sid, data in secdata.items():
        for e in data:
            for f in tr.fields(e):
                for a in (f.get("addrs") or ([f["addr"]] if "addr" in f else [])):
                    v = int(a, 16)
                    if BANK_LO <= v < BANK_HI:
                        (sa if sid == story_id else oa).add(v)
    br = scriptrefs.BankRefs(rom, BANK_LO, BANK_HI, sa, oa, glyph_map, tr.CHAR2CODE, tr.ZERO_WIDTH)
    sr_sites = {t for _o, t in br.sites}
    missed = sorted(edge_targets - sr_sites)               # real jump-edges scriptrefs won't repoint
    KNOWN_MISS = 3                                          # the 080A1064 truncated-entry choice rows

    CSV_OUT.parent.mkdir(parents=True, exist_ok=True)
    with CSV_OUT.open("w", newline="", encoding="utf-8") as fh:
        w = csv.writer(fh)
        w.writerow(["finding", "addr", "entry_or_via", "glyphs", "n", "sample"])
        for r in sorted(gaps, key=lambda r: r["addr"]):    # genuine uncaptured prose (expect 0)
            w.writerow(["translate", f"{r['addr']:08X}", f"{r['via']:08X}", r["glyphs"], r["n"], r["text"][:56]])
        for t, es in interior:                             # interior jump → needs pool repoint
            txt, _c = tr.decode(rom, es, 60)
            w.writerow(["interior-target", f"{t:08X}", f"{es:08X}", "", "", txt[:40]])

    print(f"event-VM bank {BANK_LO:08X}..{BANK_HI:08X}")
    print(f"  external roots (tables/lits) : {len(ext_roots)}")
    print(f"  distinct branch/jump targets : {len(edge_targets)}")
    print(f"  dispatch/choice blocks       : {dispatch}  (control flow — no message)")
    print(f"  reachable prose messages     : {reach_prose}")
    print(f"    -> already captured        : {captured}")
    print(f"    -> GENUINELY uncaptured    : {len(gaps)}  (coverage gap)")
    print(f"  COVERAGE: {'PASS — linear walk owns all reachable prose' if not gaps else 'GAPS FOUND'}")
    print(f"  interior-target repoints     : {len(interior)}  (jump into a captured entry — scriptrefs must remap)")
    print(f"  scriptrefs remap guard       : {len(missed)} VM jump-edge(s) NOT caught by scriptrefs "
          f"({'OK — only the known 080A1064 misses' if len(missed) <= KNOWN_MISS else 'REGRESSION — new uncaught jump!'})")
    for t in missed:
        es = containing(t)
        print(f"    miss {t:08X}" + (f" -> inside {es:08X}" if es else " (no entry)"))
    print(f"  -> {CSV_OUT.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
