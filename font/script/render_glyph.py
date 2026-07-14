#!/usr/bin/env python3
"""Render an SMT2 GBA font glyph, faithful to FUN_080abf24.

Font format (decoded from FUN_080abf24 decompilation):
  - Source pixels are 2bpp, MSB-first (4 pixels per byte, pixel 0 = bits 7-6).
  - Layout is GBA 8x8 tile order. Each 8px tile row = 2 bytes.
  - A glyph occupies a 2x2 tile area (16x16), drawn clipped to 12x13:
      pass 1 (rows 0-7):  TL = src[0x00:0x10], TR = src[0x10:0x20]
      pass 2 (rows 8-15): BL = src[0x200:0x210], BR = src[0x210:0x220]
  - FUN_080abf24 expands each 2bpp byte to two 4bpp bytes but preserves pixel
    order and position, so we can read the 2bpp source directly.

Address formula (also from FUN_080abf24):
    bank   = *(u32*)(fontBankTable + (code>>8)*8)        ; fontBankTable=0x0815ED88
    glyph  = bank + ((code&0xff)>>4)*0x400 + (code&0xf)*0x20

Usage:
    python font/script/render_glyph.py 017b
    python font/script/render_glyph.py 017b --shades       # use .:+# for pixel values 0-3
    python font/script/render_glyph.py 017b --png out.png  # write a PNG (needs Pillow)
    python font/script/render_glyph.py 017b --full16       # show full 16x16, unclipped
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

ROM_BASE = 0x08000000
DEFAULT_ROM = Path(__file__).resolve().parents[2] / "rom" / "Shin Megami Tensei II (Japan).gba"
FONT_BANK_TABLE_ADDR = 0x0815ED88
GLYPH_W = 12
GLYPH_H = 13


def read_u32(rom: bytes, addr: int) -> int:
    off = addr - ROM_BASE
    return int.from_bytes(rom[off:off + 4], "little")


def glyph_src_offset(rom: bytes, code: int) -> int:
    hi = (code >> 8) & 0xFF
    bank = read_u32(rom, FONT_BANK_TABLE_ADDR + hi * 8)
    row = (code & 0xFF) >> 4
    col = code & 0x0F
    glyph_addr = bank + row * 0x400 + col * 0x20
    return glyph_addr - ROM_BASE


def decode_2bpp_tile(tile: bytes) -> list[list[int]]:
    """Decode a 16-byte 2bpp tile -> 8 rows x 8 pixel values (0-3), MSB-first."""
    rows = []
    for y in range(8):
        b0, b1 = tile[y * 2], tile[y * 2 + 1]
        word = (b0 << 8) | b1
        px = [(word >> (14 - x * 2)) & 0x3 for x in range(8)]
        rows.append(px)
    return rows


def render_glyph_pixels(rom: bytes, code: int) -> list[list[int]]:
    """Return a 16x16 grid of pixel values (0-3) for the glyph."""
    off = glyph_src_offset(rom, code)
    TL = decode_2bpp_tile(rom[off + 0x000: off + 0x010])
    TR = decode_2bpp_tile(rom[off + 0x010: off + 0x020])
    BL = decode_2bpp_tile(rom[off + 0x200: off + 0x210])
    BR = decode_2bpp_tile(rom[off + 0x210: off + 0x220])

    grid = [[0] * 16 for _ in range(16)]
    for y in range(8):
        for x in range(8):
            grid[y][x] = TL[y][x]
            grid[y][x + 8] = TR[y][x]
            grid[y + 8][x] = BL[y][x]
            grid[y + 8][x + 8] = BR[y][x]
    return grid


def to_ascii(grid: list[list[int]], w: int, h: int, shades: bool) -> list[str]:
    if shades:
        # value 2 = body (solid), value 3 = drop shadow (light), 1 = unused
        ramp = {0: "..", 1: "++", 2: "##", 3: "::"}
        cell = lambda v: ramp[v]
    else:
        cell = lambda v: "##" if v else "  "
    return ["".join(cell(grid[y][x]) for x in range(w)) for y in range(h)]


def main() -> int:
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")

    ap = argparse.ArgumentParser()
    ap.add_argument("code", help="Glyph code in hex, e.g. 017b")
    ap.add_argument("rom", nargs="?", default=str(DEFAULT_ROM))
    ap.add_argument("--shades", action="store_true", help="Render 4 gray levels, not just on/off")
    ap.add_argument("--full16", action="store_true", help="Show full 16x16 instead of 12x13")
    ap.add_argument("--png", metavar="PATH", help="Write a scaled PNG (requires Pillow)")
    ap.add_argument("--scale", type=int, default=16, help="PNG pixel scale (default 16)")
    args = ap.parse_args()

    code = int(args.code, 16)
    rom = Path(args.rom).read_bytes()
    off = glyph_src_offset(rom, code)
    grid = render_glyph_pixels(rom, code)

    w, h = (16, 16) if args.full16 else (GLYPH_W, GLYPH_H)

    print(f"Glyph 0x{code:04X}  src=0x{ROM_BASE + off:08X}  ({w}x{h})")
    border = "+" + "-" * (w * 2) + "+"
    print(border)
    for line in to_ascii(grid, w, h, args.shades):
        print(f"|{line}|")
    print(border)

    if args.png:
        try:
            from PIL import Image
        except ImportError:
            print("Pillow not installed: pip install Pillow", file=sys.stderr)
            return 1
        scale = args.scale
        img = Image.new("L", (w * scale, h * scale), 255)
        px = img.load()
        # body (2) darkest, drop shadow (3) light, 1 unused mid-gray
        levels = {0: 255, 1: 110, 2: 0, 3: 175}
        for y in range(h):
            for x in range(w):
                v = levels[grid[y][x]]
                for dy in range(scale):
                    for dx in range(scale):
                        px[x * scale + dx, y * scale + dy] = v
        img.save(args.png)
        print(f"wrote {args.png}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
