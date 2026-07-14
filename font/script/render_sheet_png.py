#!/usr/bin/env python3
"""Render a raw GBA font sheet to a labelled PNG contact sheet (for eyeballing the
full glyph inventory + typefaces). Complements render_glyph.py (which renders the
banked 2bpp main sheet by glyph CODE); this one dumps a FLAT sheet by cell INDEX.

Sheets:
  ascii8 : 4bpp, 8x8 cells, 0x20 bytes each, base 0x081ad7b8 (DAT_080acaac).
           A full small font — digits + Latin (thick "status" face) + kana (thin face).

Usage:
    python font/script/render_sheet_png.py            # -> font/review/font8_contact.png
    python font/script/render_sheet_png.py 0 0x200    # index range
"""
import sys
from pathlib import Path

try:
    from font.script._boot import REVIEW, ROM as ROM_PATH
except ModuleNotFoundError:
    from _boot import REVIEW, ROM as ROM_PATH

ROM = ROM_PATH.read_bytes()

ASCII8_BASE = 0x1AD7B8   # file offset (0x081ad7b8 - 0x08000000)
CELL = 0x20              # bytes per 8x8 4bpp cell
COLS = 32               # cells per row in the contact sheet
SCALE = 5


def cell_pixels(idx: int):
    """8x8 grid of 4bpp values (0-15) for an ascii8 cell."""
    base = ASCII8_BASE + idx * CELL
    grid = [[0] * 8 for _ in range(8)]
    for y in range(8):
        for x in range(8):
            b = ROM[base + y * 4 + (x >> 1)]
            grid[y][x] = (b >> 4) if (x & 1) else (b & 0xF)
    return grid


def render(lo: int, hi: int, out: Path):
    from PIL import Image, ImageDraw
    n = hi - lo
    rows = (n + COLS - 1) // COLS
    margin = 40
    cw = 8 * SCALE + 1
    img = Image.new("RGB", (margin + COLS * cw, margin + rows * cw), (32, 32, 40))
    d = ImageDraw.Draw(img)
    # column headers (low nibble)
    for c in range(COLS):
        d.text((margin + c * cw + 2, 2), f"{c:x}", fill=(140, 140, 160))
    for k in range(n):
        idx = lo + k
        r, c = divmod(k, COLS)
        ox = margin + c * cw
        oy = margin + r * cw
        if c == 0:
            d.text((2, oy + cw // 2 - 4), f"{idx:#05x}", fill=(160, 160, 180))
        g = cell_pixels(idx)
        for y in range(8):
            for x in range(8):
                v = g[y][x]
                if v:
                    col = 255 - int(v / 15 * 255)
                    for dy in range(SCALE):
                        for dx in range(SCALE):
                            img.putpixel((ox + x * SCALE + dx, oy + y * SCALE + dy), (col, col, col))
    out.parent.mkdir(parents=True, exist_ok=True)
    img.save(out)
    print(f"wrote {out}  ({n} cells {lo:#x}..{hi-1:#x}, {img.width}x{img.height})")


def main() -> None:
    lo = int(sys.argv[1], 0) if len(sys.argv) > 1 else 0
    hi = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x200
    render(lo, hi, REVIEW / "font8_contact.png")


if __name__ == "__main__":
    raise SystemExit(main())
