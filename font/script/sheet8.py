#!/usr/bin/env python3
"""Codec for the small 4bpp 8x8 font sheet (ascii8) at ROM 0x081AD7B8 (DAT_080acaac).

Each glyph cell is 0x20 bytes: 8 rows x 4 bytes, two 4bpp pixels per byte, LOW nibble =
even x, HIGH nibble = odd x (matches Font_BlitGlyph8x8 / render_sheet_png.py). The sheet
holds three faces (short 8x8 blocky, tall 8x16 blocky = two stacked cells, thin 8x8 Latin
+ kana). See docs/font-system.md. Pairs with ttf_raster.py (rasteriser) and patch_font.py
(the 2bpp main-sheet codec).
"""
ROM_BASE = 0x08000000
SHEET_ADDR = 0x081AD7B8          # ROM address of cell 0
SHEET_OFF = SHEET_ADDR - ROM_BASE
CELL = 0x20                      # bytes per 8x8 4bpp cell


def cell_offset(idx: int) -> int:
    """File offset of cell `idx` within a ROM image."""
    return SHEET_OFF + idx * CELL


def decode_cell(data: bytes) -> list:
    """32-byte cell -> 8x8 grid of 4bpp values (0-15)."""
    g = [[0] * 8 for _ in range(8)]
    for y in range(8):
        for x in range(8):
            b = data[y * 4 + (x >> 1)]
            g[y][x] = (b >> 4) if (x & 1) else (b & 0x0F)
    return g


def encode_cell(grid: list) -> bytes:
    """8x8 grid (values 0-15) -> 32-byte cell (inverse of decode_cell)."""
    out = bytearray(CELL)
    for y in range(8):
        for x in range(8):
            v = grid[y][x] & 0x0F
            bi = y * 4 + (x >> 1)
            if x & 1:
                out[bi] = (out[bi] & 0x0F) | (v << 4)
            else:
                out[bi] = (out[bi] & 0xF0) | v
    return bytes(out)


def read_cell(rom: bytes, idx: int) -> list:
    off = cell_offset(idx)
    return decode_cell(rom[off:off + CELL])


def write_cell(rom: bytearray, idx: int, grid: list) -> None:
    off = cell_offset(idx)
    rom[off:off + CELL] = encode_cell(grid)


def selftest(rom: bytes, indices=(0x09, 0x17, 0x101, 0x120)) -> bool:
    """decode->encode of existing cells must be byte-identical."""
    ok = True
    for i in indices:
        off = cell_offset(i)
        orig = rom[off:off + CELL]
        if encode_cell(decode_cell(orig)) != orig:
            ok = False
            print(f"  sheet8 MISMATCH cell 0x{i:X}")
    return ok
