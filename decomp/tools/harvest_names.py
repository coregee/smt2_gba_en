#!/usr/bin/env python3
"""Collect names for ROM functions/data and RAM variables from the translation project.

The patch scripts, C caves, rom_layout.py and text tools name engine functions they hook in
comments and constants (``Font_DrawGlyph = 0x080AC8D0``, ``Party_BuildMemberNameTiles
0x080C6E78``).  Those names came from an earlier Ghidra session that is now lost.  A pair
(name, address) is kept only if the trace confirms it: the address must be a function entry
for a function-style name, or an address the code references for a data name.  Call-site
mentions (``Name @0xSITE``) fail that test and are dropped.

Writes reference/symbols.tsv, merging with entries already there (existing names win, so
hand edits survive re-harvesting).
"""
from __future__ import annotations

import json
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from symbols import Sym, Symbols  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]
PROJECT = ROOT.parent
SCAN = ["engine", "text/script", "text/config", "font", "graphics", "rom_layout.py",
        "text/README.md", "font/README.md", "graphics/README.md"]

NAME = r"[A-Z][A-Za-z0-9]*_[A-Za-z0-9_]*[a-z][A-Za-z0-9_]*"   # Subsystem_Verb..., not ALL_CAPS
ADDR = r"0x0[2389][0-9A-Fa-f]{6}"
PAIR = re.compile(rf"\b({NAME})\b[^\n0-9A-Za-z_]{{0,6}}(?:=|\(|:|is|at)?\s*\(?\s*({ADDR})\b")
PAIR_REV = re.compile(rf"\b({ADDR})\b\s*[:=(]?\s*\(?({NAME})\b")
SKIP = re.compile(r"^(FUN|DAT|LAB|PTR|thunk|switch|caseD|s_|u_)_?")


def scan():
    hits = defaultdict(Counter)
    files = []
    for s in SCAN:
        p = PROJECT / s
        if p.is_file():
            files.append(p)
        elif p.is_dir():
            files += [f for f in p.rglob("*") if f.suffix in (".py", ".c", ".h", ".md", ".json")]
    for f in files:
        try:
            text = f.read_text(encoding="utf-8", errors="replace")
        except OSError:
            continue
        for m in PAIR.finditer(text):
            name, addr = m.group(1), int(m.group(2), 16)
            if not SKIP.match(name):
                hits[name][addr] += 1
        for m in PAIR_REV.finditer(text):
            addr, name = int(m.group(1), 16), m.group(2)
            if not SKIP.match(name):
                hits[name][addr] += 1
    return hits


def main():
    trace = json.loads((ROOT / "build" / "trace.json").read_text())
    entries = {f["addr"] for f in trace["functions"]}
    lits = set()
    rom = (ROOT / "baserom.gba").read_bytes()
    for f in trace["functions"]:
        for l in f["literals"]:
            o = l - 0x08000000
            lits.add(int.from_bytes(rom[o:o + 4], "little"))
    hits = scan()
    chosen: dict[int, tuple[str, int]] = {}
    rejected = []
    for name, addrs in hits.items():
        ok = [(a & ~1, n) for a, n in addrs.items()
              if (a & ~1) in entries or (a >> 24 in (2, 3) and a in lits)
              or (a >> 24 == 8 and a in lits and (a & ~1) not in entries)]
        if not ok:
            rejected.append((name, dict(addrs)))
            continue
        ok.sort(key=lambda x: -x[1])
        a, n = ok[0]
        prev = chosen.get(a)
        if prev is None or prev[1] < n:
            chosen[a] = (name, n)
    syms = Symbols.load(ROOT / "reference" / "symbols.tsv")
    rows = {s.addr: s for s in syms.by_addr.values()}
    added = 0
    for a, (name, n) in sorted(chosen.items()):
        if a in rows:
            continue
        kind = "func" if a in entries else ("ram" if a >> 24 in (2, 3) else "data")
        rows[a] = Sym(a, name, kind, "tentative",
                      "from translation patches (lost Ghidra session); verify")
        added += 1
    Symbols.save(ROOT / "reference" / "symbols.tsv", rows.values())
    print(f"{added} names added ({len(rows)} total); {len(rejected)} names had no confirmable address")
    for name, addrs in sorted(rejected)[:400]:
        print("  unconfirmed:", name, " ".join(f"{a:08X}" for a in addrs))


if __name__ == "__main__":
    main()
