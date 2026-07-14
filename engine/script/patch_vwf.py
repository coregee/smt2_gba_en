#!/usr/bin/env python3
"""Apply the variable-width-font (VWF) hook to rom/smt2-en-font.gba (in place).

The event-VM lays out flowing text on a fixed 13px grid (see docs/font-rendering.md):
  pixelX = col*13 + 17   (mul @ 0x0813dc90)
  col   += 1  per glyph  (add @ 0x0813dcc8)
This makes `col` a PIXEL accumulator and advances it by each glyph's measured width:

  1. nop the X `mul r0,r5` @ 0x0813dc90  -> pixelX = col + 17
  2. replace `add r0,#1; strh r0,[r6]` @ 0x0813dcc8 with `bl CAVE`
  3. CAVE: col += widthTable[g_currentCode]; strh col,[r6]; bx lr
  4. width table (code-indexed advance bytes) in free ROM; English glyphs get their
     trimmed advance, everything else keeps 13 (so Japanese is unchanged)
  5. LEFT-ALIGN the English glyphs (shift ink to the cell's left) so the trimmed
     advance spaces them correctly without a runtime blit-trim.

Run AFTER patch_font.py. Idempotent-ish: asserts the original bytes before patching.
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from font.atlas import GLYPH_MAP, replacement_characters  # noqa: E402
from font.script.font_codec import (  # noqa: E402
    decode_main_glyph,
    encode_main_record,
    main_glyph_offset,
)
from engine.script import rommap                                                    # noqa: E402
B = rommap.ROM_BASE

CAVE_ADDR = 0x081A6DB4          # 0xFF gap, in bl range of the patch site
TABLE_ADDR = rommap.WIDTH_TABLE       # the VWF advance table this patch fills
TABLE_SIZE = rommap.WIDTH_TABLE_SIZE  # code-indexed advance bytes
DEFAULT_ADV = 13
GAP = 1
COL0, COL1, ROW0, ROW1 = 2, 13, 2, 14   # drawn window

P1_ADDR, P1_OLD, P1_NEW = 0x0813dc90, bytes.fromhex("6843"), bytes.fromhex("c046")  # mul -> nop
P2_ADDR, P2_OLD = 0x0813dcc8, bytes.fromhex("01303080")                              # add#1;strh -> bl


def cave_bytes():
    # push{r1,r2}; mov r1,r12; ldrh r1,[r1]; ldr r2,[pc,#0xC]; ldrb r2,[r2,r1];
    # add r0,r0,r2; strh r0,[r6]; pop{r1,r2}; bx lr; .pad; .word TABLE_ADDR
    # each pair below is one Thumb halfword in little-endian byte order:
    #   B406 push{r1,r2} | 4661 mov r1,r12 | 8809 ldrh r1,[r1] | 4A03 ldr r2,[pc,#0xC]
    #   5C52 ldrb r2,[r2,r1] | 1880 add r0,r0,r2 | 8030 strh r0,[r6] | BC06 pop{r1,r2}
    #   4770 bx lr | 0000 pad
    code = bytes.fromhex("06b4" "6146" "0988" "034a" "525c" "8018" "3080" "06bc" "7047" "0000")
    return code + TABLE_ADDR.to_bytes(4, "little")


def ink_cols(g):
    return [c for c in range(COL0, COL1 + 1) if any(g[r][c] for r in range(ROW0, ROW1 + 1))]


def english_codes(rom):
    """codes (0xBC..0x117) whose glyph is an ASCII letter/digit/space/punct."""
    out = set()
    for code, ch in GLYPH_MAP.items():
        if 0x00BC <= code <= 0x0117 and (ch.isascii() and (ch.isalnum() or not ch.isspace())):
            out.add(code)
    out.add(0x00BC)   # space
    out |= set(replacement_characters())
    return out


def apply(p):
    rom = p.rom
    # ---- safety guards ----
    p.expect(P1_ADDR, P1_OLD)
    p.expect(P2_ADDR, P2_OLD)
    cb = cave_bytes()
    assert all(b == 0xFF for b in p.read(CAVE_ADDR, len(cb))), "vwf cave region not free"
    assert all(b == 0xFF for b in p.read(TABLE_ADDR, TABLE_SIZE)), "width-table region not free"

    # ---- left-align English glyphs; collect advances ----
    eng = english_codes(rom)
    adv = {}
    aligned = 0
    for code in sorted(eng):
        g = decode_main_glyph(rom, code)
        cols = ink_cols(g)
        if not cols:                       # blank (space)
            adv[code] = 5
            continue
        left = min(cols) - COL0
        ink = max(cols) - COL0 - left + 1
        adv[code] = ink + GAP
        if left > 0:                       # shift ink to start at COL0
            ng = [[0] * 16 for _ in range(16)]
            for y in range(16):
                for x in range(16 - left):
                    ng[y][x] = g[y][x + left]
            record = encode_main_record(ng)
            off = main_glyph_offset(rom, code)
            rom[off:off + 0x20] = record[:0x20]
            rom[off + 0x200:off + 0x220] = record[0x20:]
            aligned += 1

    # ---- width table (default 13; English -> trimmed advance) ----
    table = bytearray([DEFAULT_ADV]) * TABLE_SIZE
    for code, a in adv.items():
        table[code] = min(a, 255)
    p.write(TABLE_ADDR, table)

    # ---- cave (0xFF region, direct) + the two code patches ----
    p.write(CAVE_ADDR, cb)
    p.patch(P1_ADDR, P1_OLD, P1_NEW, name="vwf-nop")     # mul -> nop
    p.bl(P2_ADDR, CAVE_ADDR, P2_OLD, name="vwf-bl")      # add#1;strh -> bl cave
    print(f"left-aligned {aligned} English glyphs; width table @0x{TABLE_ADDR:08X}")
