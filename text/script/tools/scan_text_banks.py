#!/usr/bin/env python3
"""Scan the whole ROM for pointer tables that reference readable Japanese text.

Uses the full glyph map to score each candidate string's readability, finds dense
runs of u32 pointers into text, groups them into tables, and prints each table
with sample decodes — to locate text banks we haven't dumped yet (main story,
events, menus), distinct from the already-known negotiation/lore banks.
"""

from __future__ import annotations
import sys
from pathlib import Path

try:
    from text.script.tools._boot import PATHS, ROM
except ModuleNotFoundError:
    from _boot import PATHS, ROM

from font.atlas import GLYPH_MAP  # noqa: E402

ROM_BASE = 0x08000000

KNOWN_BANKS = [
    (0x08009000, 0x080A1000, "negotiation + lore target region"),
]


def u16(rom, o): return int.from_bytes(rom[o:o + 2], "little")
def u32(rom, o): return int.from_bytes(rom[o:o + 4], "little")


def score_text(rom, addr, max_codes=80):
    """Return (readable_fraction, n_glyphs, decoded) for a string at addr."""
    o = addr - ROM_BASE
    if o < 0 or o + 2 > len(rom):
        return 0.0, 0, ""
    good = total = 0
    out = []
    for k in range(max_codes):
        if o + k * 2 + 2 > len(rom):
            break
        c = u16(rom, o + k * 2)
        if c == 0 or c == 0x0301:
            break
        total += 1
        if c == 0x0300:
            out.append("/")
            good += 1
        elif 0x0300 <= c < 0x031C:
            out.append("·")
            good += 1
        elif c in GLYPH_MAP:
            out.append(GLYPH_MAP[c])
            good += 1
        else:
            out.append("□")
    if total == 0:
        return 0.0, 0, ""
    return good / total, total, "".join(out)


def in_known(addr):
    return any(lo <= addr < hi for lo, hi, _ in KNOWN_BANKS)


def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")
    rom = ROM.read_bytes()
    n = len(rom)

    min_frac = 0.80      # at least 80% of codes decode to glyphs/controls
    min_len = 4          # at least 4 codes
    min_run = 8          # at least 8 consecutive good pointers = a table

    runs = []
    run = []
    run_start = None
    for off in range(0, n - 4, 4):
        ptr = u32(rom, off)
        ok = False
        if ROM_BASE <= ptr < ROM_BASE + n and ptr % 2 == 0:
            frac, ln, _ = score_text(rom, ptr)
            if frac >= min_frac and ln >= min_len:
                ok = True
        if ok:
            if not run:
                run_start = off
            run.append(ptr)
        else:
            if len(run) >= min_run:
                runs.append((run_start, off, run))
            run = []
    if len(run) >= min_run:
        runs.append((run_start, n, run))

    # report unknown-bank tables, sorted by size, to a file
    unknown = [(start, ptrs) for start, end, ptrs in runs if not in_known(ptrs[0])]
    unknown.sort(key=lambda r: -len(r[1]))
    out = [f"found {len(runs)} runs total; {len(unknown)} outside known region\n"]
    for start, ptrs in unknown:
        src = ROM_BASE + start
        out.append(f"TABLE src=0x{src:08X} entries={len(ptrs)} "
                   f"targets~0x{min(ptrs):08X}-0x{max(ptrs):08X}")
        for p in ptrs[:3]:
            _, _, dec = score_text(rom, p, 50)
            out.append(f"    {dec[:46]}")
        out.append("")
    report = PATHS.text_dump_root / "text_banks_scan.txt"
    report.parent.mkdir(parents=True, exist_ok=True)
    report.write_text("\n".join(out), encoding="utf-8")
    print(f"wrote {report} ({len(unknown)} unknown-bank tables)")


if __name__ == "__main__":
    raise SystemExit(main())
