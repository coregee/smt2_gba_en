#!/usr/bin/env python3
"""Level-up screen "残りポイント" (Points left) label -> English (patch_levelup).

The stat-allocation screen draws the label at (0x30, 0x74) with Text_DrawString (0x080ac908,
fixed-pitch per-glyph via Font_DrawGlyph) from the literal @0x080cb0b4 -> 0x084F00C8 "残りポイント".
English "Points left:" is too wide at fixed 0xc pitch (it would run into the value column at x=0x88),
so we use the patch_menu pointer trick on Font_DrawGlyph (0x080ac8d0): repoint the literal to a pooled
English string and retarget the draw call Text_DrawString -> Font_DrawGlyph.  The menu hook sees a ROM
pointer as the "code" arg and renders the whole string VWF at (x,y) (the [sp] pitch arg is ignored).

Run AFTER patch_menu.py (installs the Font_DrawGlyph pointer hook).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

import rom_layout as rommap
from text.script import tr

LABEL_LIT  = 0x080CB0B4               # literal slot holding the 残りポイント string ptr
LABEL_JP   = 0x084F00C8               # = "残りポイント"
COVERED_TEXT_ADDRS = (LABEL_JP,)      # read-side coverage (lib/cave_coverage.py)
DRAW_CALL  = 0x080CB090               # bl Text_DrawString(0x080ac908)
DRAW_OLD   = bytes.fromhex("e1f73afc")  # bl 0x080ac908
FONT_DRAWGLYPH = 0x080AC8D0           # patch_menu pointer hook draws a pooled string VWF


def apply(p):
    cur = int.from_bytes(p.read(LABEL_LIT, 4), "little")
    if cur != LABEL_JP:
        raise SystemExit(f"patch_levelup: literal @0x{LABEL_LIT:08X}: expected 0x{LABEL_JP:08X}, found 0x{cur:08X}")
    blob = tr.encode("Points left:") + b"\x00\x00"
    if rommap.FARDATA_LEVELUP + len(blob) > rommap.FARDATA_NOITEM:
        raise SystemExit(f"patch_levelup: pool overruns FARDATA_NOITEM (0x{rommap.FARDATA_NOITEM:08X})")
    p.write(rommap.FARDATA_LEVELUP, blob)
    p.write(LABEL_LIT, rommap.FARDATA_LEVELUP.to_bytes(4, "little"))
    p.bl(DRAW_CALL, FONT_DRAWGLYPH, DRAW_OLD, name="levelup Points-left -> Font_DrawGlyph")
    print(f"levelup: 残りポイント -> 'Points left:' VWF @0x{rommap.FARDATA_LEVELUP:08X}")
