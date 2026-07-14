#!/usr/bin/env python3
"""Measure each glyph's ink width -> a variable-width-font (VWF) advance table.

The blit (FUN_080ac4e4) copies source region cols 2..13 / rows 2..14 of the 16x16
decoded glyph cell (srcX=srcY=2, W=12, H=13) to the cursor. So a glyph's *visible*
pixels live in grid columns 2..13. For VWF we measure, per glyph:
  left   = leftmost inked column within [2,13], relative to the drawn-region start (col 2)
  right  = rightmost inked column, same basis  (so ink spans [left, right] in 0..11)
  ink    = right - left + 1                     (true visible width)
  adv    = ink + GAP                            (recommended cursor advance, left-trimmed)
Blank glyphs (space) get a fixed SPACE advance. Output: font/generated/glyph_widths.tsv
(code, char, left, ink, adv) + a flat byte array font/generated/glyph_widths.bin for a
ROM patch (one advance byte per code 0x0000..MAXCODE), and an ASCII summary.
"""
import json
import sys
from pathlib import Path

try:
    from font.script._boot import CONFIG, GENERATED, ROM as ROM_PATH
except ModuleNotFoundError:
    from _boot import CONFIG, GENERATED, ROM as ROM_PATH

from font.script.render_glyph import render_glyph_pixels  # noqa: E402

ROM = ROM_PATH.read_bytes()

# authored glyphs (not in the base ROM) — measure these from their art, not the ROM
from font.script.custom_glyphs import custom_grids, with_shadow  # noqa: E402
CUSTOM = {c: with_shadow(g) for c, g in custom_grids().items()}

# drawn window inside the 16x16 decoded cell (matches the blit's srcX/srcY=2, 12x13)
COL0, COL1 = 2, 13          # inclusive visible columns
ROW0, ROW1 = 2, 14          # inclusive visible rows
GAP = 1                     # px between glyphs
SPACE_ADV = 5               # advance for a blank/space glyph
MAX_INK = COL1 - COL0 + 1   # 12


def measure(code: int):
    """Return (left, ink, adv) within the drawn window, or None on render fail."""
    if code in CUSTOM:
        g = CUSTOM[code]
    else:
        try:
            g = render_glyph_pixels(ROM, code)
        except Exception:
            return None
    cols = [c for c in range(COL0, COL1 + 1)
            if any(g[r][c] for r in range(ROW0, ROW1 + 1))]
    if not cols:
        return (0, 0, SPACE_ADV)            # blank -> space width
    left = min(cols) - COL0
    right = max(cols) - COL0
    ink = right - left + 1
    return (left, ink, ink + GAP)


def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")
    gmap = {int(k, 16): v for k, v in
            json.loads((CONFIG / "glyph_map_data.json").read_text(encoding="utf-8")).items()}

    rows = []
    for code in sorted(gmap):
        m = measure(code)
        if m is None:
            continue
        left, ink, adv = m
        rows.append((code, gmap[code], left, ink, adv))

    tsv = GENERATED / "glyph_widths.tsv"
    with tsv.open("w", encoding="utf-8") as f:
        f.write("code\tchar\tleft\tink\tadv\n")
        for code, ch, left, ink, adv in rows:
            f.write(f"{code:04X}\t{ch}\t{left}\t{ink}\t{adv}\n")

    # flat advance byte-array for a ROM patch, indexed by code (0x0000..max)
    maxcode = max(c for c, *_ in rows)
    arr = bytearray(maxcode + 1)
    for code, _ch, _l, _ink, adv in rows:
        arr[code] = min(adv, 255)
    (GENERATED / "glyph_widths.bin").write_bytes(arr)

    print(f"measured {len(rows)} glyphs -> {tsv}")
    print(f"flat advance table: {GENERATED/'glyph_widths.bin'} ({len(arr)} bytes, code-indexed)")

    # sanity summary: ASCII letters + a few kana/kanji
    by = {ch: adv for _c, ch, _l, _ink, adv in rows}
    from collections import Counter
    dist = Counter(adv for *_x, adv in rows)
    print("\nadvance distribution (px):", dict(sorted(dist.items())))
    print("\nASCII letter widths (advance px):")
    for word in ("iIl1", "mMW", "aceo", "ABXY", "0123"):
        print("  " + "  ".join(f"{c}={by.get(c, '?')}" for c in word))
    print("sample JP:", "  ".join(f"{c}={by.get(c, '?')}"
          for c in ("ア", "ん", "国", "魔", "、", "。", "　")))


if __name__ == "__main__":
    raise SystemExit(main())
