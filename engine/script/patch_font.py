#!/usr/bin/env python3
"""Encode authored glyphs into the 2bpp font format and inject them into a ROM.

Inverts render_glyph.py. A glyph is a 2x2 tile area; the four 16-byte 2bpp tiles
live at slot offsets +0x00 (TL), +0x10 (TR), +0x200 (BL), +0x210 (BR). Each tile
row = a big-endian u16, pixel x at bits (14 - 2x).

  selftest : re-encode existing ROM glyphs, assert byte-identical (encoder proof)
  patch    : inject custom_glyphs into a COPY of the ROM -> rom/smt2-en-font.gba
  verify   : render the authored glyphs back out of the patched ROM

Usage:
    python engine/script/patch_font.py            # selftest + patch + verify
    python engine/script/patch_font.py --selftest # encoder round-trip check only
"""
import argparse
import shutil
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from font.script.render_glyph import (  # noqa: E402
    decode_2bpp_tile,
    glyph_src_offset,
    render_glyph_pixels,
)
from font.script.custom_glyphs import (  # noqa: E402
    GLYPH_ART,
    custom_chars,
    custom_grids,
    with_shadow,
)

ROM_PATH = PATHS.source_rom
OUT_PATH = PATHS.build_path("smt2-en-font.gba")


def encode_2bpp_tile(tile) -> bytes:
    """8x8 grid of pixel values (0-3) -> 16-byte 2bpp tile (inverse of decode)."""
    out = bytearray(16)
    for y in range(8):
        word = 0
        for x in range(8):
            word |= (tile[y][x] & 3) << (14 - x * 2)
        out[y * 2] = (word >> 8) & 0xFF
        out[y * 2 + 1] = word & 0xFF
    return bytes(out)


def encode_glyph(grid):
    """16x16 grid -> (tl_tr[0x20], bl_br[0x20]) bytes for the slot at +0x00 / +0x200."""
    sub = lambda y0, x0: [[grid[y0 + y][x0 + x] for x in range(8)] for y in range(8)]
    tl = encode_2bpp_tile(sub(0, 0))
    tr = encode_2bpp_tile(sub(0, 8))
    bl = encode_2bpp_tile(sub(8, 0))
    br = encode_2bpp_tile(sub(8, 8))
    return tl + tr, bl + br


def selftest(rom: bytes) -> bool:
    """Encode existing glyphs from their rendered grid; must reproduce ROM bytes."""
    ok = True
    for code in (0x00DD, 0x00CC, 0x010C, 0x011C, 0x017A, 0x0804, 0x0001):
        off = glyph_src_offset(rom, code)
        grid = render_glyph_pixels(rom, code)
        tltr, blbr = encode_glyph(grid)
        orig_tltr = rom[off:off + 0x20]
        orig_blbr = rom[off + 0x200:off + 0x220]
        if tltr != orig_tltr or blbr != orig_blbr:
            ok = False
            print(f"  MISMATCH 0x{code:04X}: tl/tr {tltr == orig_tltr}, bl/br {blbr == orig_blbr}")
    print("encoder round-trip:", "OK (byte-identical)" if ok else "FAILED")
    return ok


def patch(rom: bytes) -> bytearray:
    out = bytearray(rom)
    grids = custom_grids()
    print(f"injecting {len(grids)} authored glyphs:")
    for code, grid in grids.items():
        grid = with_shadow(grid)
        off = glyph_src_offset(rom, code)
        tltr, blbr = encode_glyph(grid)
        out[off:off + 0x20] = tltr
        out[off + 0x200:off + 0x220] = blbr
        ch = GLYPH_ART[code][0]
        print(f"  0x{code:04X} {ch!r:>4}  @ 0x{0x08000000 + off:08X}")
    return out


def verify(patched: bytes) -> bool:
    ok = True
    for code, grid in custom_grids().items():
        want = with_shadow(grid)
        got = render_glyph_pixels(patched, code)
        if got != want:
            ok = False
            print(f"  VERIFY FAIL 0x{code:04X}")
    print("patched-ROM render-back:", "OK" if ok else "FAILED")
    return ok


def apply(p):
    # p.rom starts as the base ROM (build_rom loads it); inject the Latin font in place.
    if not selftest(bytes(p.rom)):
        raise SystemExit("patch_font: encoder is not byte-exact")
    p.rom[:] = patch(p.rom)
    if not verify(bytes(p.rom)):
        raise SystemExit("patch_font: patched ROM did not verify")
    print("font injected")
