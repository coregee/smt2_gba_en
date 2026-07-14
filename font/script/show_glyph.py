#!/usr/bin/env python3
"""Glyph bitmap visualizer for SMT2 GBA font data.

Usage:
    python font/script/show_glyph.py 017b
    python font/script/show_glyph.py 017b --all-modes
    python font/script/show_glyph.py 017b --mode 1bpp_2bpr
"""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

ROM_BASE = 0x08000000
DEFAULT_ROM = Path(__file__).resolve().parents[2] / "rom" / "Shin Megami Tensei II (Japan).gba"
FONT_BANK_TABLE_ADDR = 0x0815ED88
GLYPH_WIDTH = 0x0C   # 12px
GLYPH_HEIGHT = 0x0D  # 13px
GLYPH_SLOT_BYTES = 0x20  # bytes per column stride

BANK_TABLE: dict[int, int] = {
    0x00: 0x081C3978,
    0x01: 0x081C7978,
    0x02: 0x081C7978,
    0x03: 0x081CB978,
    0x04: 0x081CF978,
    0x05: 0x081D3978,
    0x06: 0x081D7978,
    0x07: 0x081DB978,
    0x08: 0x081DF978,
    0x09: 0x081E3978,
    0x0A: 0x081E7978,
    0x0B: 0x081EB978,
    0x0C: 0x081EF978,
    0x0D: 0x081F3978,
    0x0E: 0x081F7978,
    0x0F: 0x081FB978,
    0x10: 0x081FF978,
    0x11: 0x08203978,
}


def glyph_rom_offset(code: int) -> int | None:
    hi = (code >> 8) & 0xFF
    lo = code & 0xFF
    bank_addr = BANK_TABLE.get(hi)
    if bank_addr is None:
        return None
    row = lo >> 4
    col = lo & 0x0F
    bank_offset = row * 0x400 + col * GLYPH_SLOT_BYTES
    return (bank_addr - ROM_BASE) + bank_offset


# ---------------------------------------------------------------------------
# Decompressor (matches FUN_080abf24 in the ROM)
# ---------------------------------------------------------------------------

def decompress_font_slot(src: bytes) -> bytes:
    """Convert one 32-byte 2bpp font ROM slot to 64 bytes of GBA 4bpp data (2 tiles).

    The ROM font stores each glyph slot as packed 2bpp pixels (4 per byte).
    FUN_080abf24 expands each input byte into two 4bpp output bytes:
      out[2i]   = (b & 0xC0) >> 6  |  (b & 0x30)      <- pixels 0, 1 of the byte
      out[2i+1] = (b & 0x0C) >> 2  |  (b & 0x03) << 4  <- pixels 2, 3
    32 bytes in -> 64 bytes out = two consecutive GBA 8x8 4bpp tiles.
    """
    out = bytearray(64)
    for i, b in enumerate(src[:32]):
        base = i * 2
        out[base]     = ((b & 0xC0) >> 6) | (b & 0x30)
        out[base + 1] = ((b & 0x0C) >> 2) | ((b & 0x03) << 4)
    return bytes(out)


def _read_4bpp_pixel(tile: bytes, x: int, y: int) -> int:
    """Read one nibble (pixel) from a 32-byte GBA 8x8 4bpp tile."""
    byte_idx = y * 4 + x // 2
    if byte_idx >= len(tile):
        return 0
    b = tile[byte_idx]
    return b & 0x0F if x % 2 == 0 else (b >> 4) & 0x0F


def render_decompressed_glyph(rom: bytes, off: int, w: int, h: int) -> list[str]:
    """Decompress both font passes for a glyph and try all tile arrangements.

    Each 32-byte slot decompresses to 64 bytes = 2 GBA 8x8 4bpp tiles.
    The second slot source is 0x80 bytes after the first in the font bank.
    We try two likely arrangements and show both:
      A) Two passes stacked vertically: pass1=rows 0-7, pass2=rows 8-15 (8px wide)
      B) Two passes side by side: pass1=left 8px, pass2=right 8px (up to 16px wide, 8 rows)
    """
    src1 = rom[off      : off + 32]
    src2 = rom[off + 0x80 : off + 0x80 + 32]
    decomp1 = decompress_font_slot(src1)   # 64 bytes = tile A + tile B
    decomp2 = decompress_font_slot(src2)   # 64 bytes = tile C + tile D
    tileA, tileB = decomp1[:32], decomp1[32:]
    tileC, tileD = decomp2[:32], decomp2[32:]

    # 2x2 tile arrangement: tileA=top-left, tileB=top-right, tileC=bottom-left, tileD=bottom-right
    rows = []
    for y in range(min(h, 16)):
        tile_l = tileA if y < 8 else tileC
        tile_r = tileB if y < 8 else tileD
        left  = "".join("##" if _read_4bpp_pixel(tile_l, x, y % 8) else "  " for x in range(8))
        right = "".join("##" if _read_4bpp_pixel(tile_r, x, y % 8) else "  " for x in range(min(w - 8, 8)))
        rows.append(left + right)
    return rows


# ---------------------------------------------------------------------------
# Rendering modes
# ---------------------------------------------------------------------------

def render_1bpp_2bpr(data: bytes, w: int, h: int) -> list[str]:
    """1bpp, 2 bytes per row, MSB of first byte = leftmost pixel."""
    rows = []
    for y in range(h):
        byte0 = data[y * 2]
        byte1 = data[y * 2 + 1]
        word = (byte0 << 8) | byte1
        row = ""
        for x in range(w):
            bit = (word >> (15 - x)) & 1
            row += "##" if bit else "  "
        rows.append(row)
    return rows


def render_1bpp_2bpr_lsb(data: bytes, w: int, h: int) -> list[str]:
    """1bpp, 2 bytes per row, LSB of first byte = leftmost pixel."""
    rows = []
    for y in range(h):
        byte0 = data[y * 2]
        byte1 = data[y * 2 + 1]
        word = byte0 | (byte1 << 8)
        row = ""
        for x in range(w):
            bit = (word >> x) & 1
            row += "##" if bit else "  "
        rows.append(row)
    return rows


def render_1bpp_2bpr_nibble_swap(data: bytes, w: int, h: int) -> list[str]:
    """1bpp, 2 bytes per row, but each nibble's bits reversed (GBA tile-ish)."""
    rows = []
    for y in range(h):
        byte0 = data[y * 2]
        byte1 = data[y * 2 + 1]
        row = ""
        for x in range(w):
            if x < 8:
                bit = (byte0 >> x) & 1
            else:
                bit = (byte1 >> (x - 8)) & 1
            row += "##" if bit else "  "
        rows.append(row)
    return rows


def render_gba_4bpp(data: bytes, w: int, h: int) -> list[str]:
    """Standard GBA 4bpp 8x8 tile — ignores w/h, always renders 8x8."""
    rows = []
    for y in range(8):
        row = ""
        for x in range(4):
            b = data[y * 4 + x]
            lo = b & 0xF
            hi = (b >> 4) & 0xF
            row += "##" if lo else "  "
            row += "##" if hi else "  "
        rows.append(row)
    return rows


def render_column_major_1bpp(data: bytes, w: int, h: int) -> list[str]:
    """1bpp, column-major: bytes[0..h_bytes-1] = column 0, etc."""
    h_bytes = (h + 7) // 8
    grid = [["  "] * w for _ in range(h)]
    for x in range(w):
        col_off = x * h_bytes
        for by in range(h_bytes):
            if col_off + by >= len(data):
                break
            b = data[col_off + by]
            for bit in range(8):
                y = by * 8 + bit
                if y < h:
                    grid[y][x] = "##" if (b >> (7 - bit)) & 1 else "  "
    return ["".join(row) for row in grid]


def render_1bpp_pack12(data: bytes, w: int, h: int) -> list[str]:
    """1bpp packed: each row is w bits packed into bytes, no row padding."""
    rows = []
    bit_pos = 0
    for _y in range(h):
        row = ""
        for _x in range(w):
            byte_i = bit_pos // 8
            bit_i = 7 - (bit_pos % 8)
            bit = (data[byte_i] >> bit_i) & 1 if byte_i < len(data) else 0
            row += "##" if bit else "  "
            bit_pos += 1
        rows.append(row)
    return rows


def render_1bpp_pack12_lsb(data: bytes, w: int, h: int) -> list[str]:
    """1bpp packed LSB-first: each row is w bits LSB-first."""
    rows = []
    bit_pos = 0
    for _y in range(h):
        row = ""
        for _x in range(w):
            byte_i = bit_pos // 8
            bit_i = bit_pos % 8
            bit = (data[byte_i] >> bit_i) & 1 if byte_i < len(data) else 0
            row += "##" if bit else "  "
            bit_pos += 1
        rows.append(row)
    return rows


MODES: dict[str, tuple] = {
    "1bpp_2bpr":            (render_1bpp_2bpr,            "1bpp, 2 bytes/row, MSB-first (most likely)"),
    "1bpp_2bpr_lsb":        (render_1bpp_2bpr_lsb,        "1bpp, 2 bytes/row, LSB-first"),
    "1bpp_2bpr_nibble":     (render_1bpp_2bpr_nibble_swap,"1bpp, 2 bytes/row, nibble-reversed"),
    "gba_4bpp":             (render_gba_4bpp,             "GBA 4bpp 8x8 tile (first tile only)"),
    "column_major":         (render_column_major_1bpp,    "1bpp column-major"),
    "1bpp_packed_msb":      (render_1bpp_pack12,          "1bpp tightly packed, MSB-first"),
    "1bpp_packed_lsb":      (render_1bpp_pack12_lsb,      "1bpp tightly packed, LSB-first"),
}


def print_render(name: str, desc: str, rows: list[str]) -> None:
    border = "+" + "-" * (len(rows[0]) if rows else 0) + "+"
    print(f"\n[{name}] {desc}")
    print(border)
    for row in rows:
        print(f"|{row}|")
    print(border)


def show_hex(data: bytes) -> None:
    print("\nRaw bytes (hex):")
    for i in range(0, len(data), 8):
        chunk = data[i:i+8]
        hex_str = " ".join(f"{b:02X}" for b in chunk)
        bin_str = " ".join(f"{b:08b}" for b in chunk)
        print(f"  [{i:02X}] {hex_str}  {bin_str}")


def main() -> int:
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")

    parser = argparse.ArgumentParser(description="Show SMT2 GBA font glyph bitmap")
    parser.add_argument("code", help="Glyph code in hex, e.g. 017b")
    parser.add_argument(
        "rom",
        nargs="?",
        default=str(DEFAULT_ROM),
        help="Path to the GBA ROM",
    )
    parser.add_argument("--mode", choices=list(MODES), default=None)
    parser.add_argument("--all-modes", action="store_true", help="Render with every mode")
    parser.add_argument("--extra-bytes", type=int, default=0,
                        help="Read N additional bytes beyond 0x20 (try 0x20 for two-tile)")
    args = parser.parse_args()

    code = int(args.code, 16)
    rom = Path(args.rom).read_bytes()

    off = glyph_rom_offset(code)
    if off is None:
        print(f"No known bank for glyph 0x{code:04X} (high byte 0x{(code>>8):02X})")
        return 1

    read_bytes = GLYPH_SLOT_BYTES + args.extra_bytes
    data = rom[off : off + read_bytes]
    print(f"Glyph 0x{code:04X}  ROM offset 0x{off:08X}  ({GLYPH_WIDTH}x{GLYPH_HEIGHT}px)  {read_bytes} bytes")
    show_hex(data)

    # Always try the decompressor first (the correct ROM format)
    decomp_rows = render_decompressed_glyph(rom, off, GLYPH_WIDTH, GLYPH_HEIGHT)
    print_render("decompress", "2bpp→4bpp decompressor (FUN_080abf24, uses tile + tile+0x80)", decomp_rows)

    if args.all_modes:
        modes_to_run = list(MODES.items())
    elif args.mode:
        modes_to_run = [(args.mode, MODES[args.mode])]
    else:
        modes_to_run = []

    for mode_name, (fn, desc) in modes_to_run:
        rows = fn(data[:GLYPH_SLOT_BYTES], GLYPH_WIDTH, GLYPH_HEIGHT)
        print_render(mode_name, desc, rows)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
