#!/usr/bin/env python3
"""Decouple the human-status 魔 from the 命 literal so 命中 can be translated.

The human status drawer FUN_080cbb34 builds the magic-row 魔 by COMPUTING it from the 命中
label literal: `sub r6,#0x3b` turns 命 (0x0FFE) into 魔 (0x0FC3), reusing r6. The moment 命中
is translated, that literal becomes a POOL POINTER (>= 0x08000000), so 魔 = pointer-0x3b is a
bogus pointer -> the menu-label hook treats it as a string and runs off reading memory until
it hits a 0 (hang + VRAM corruption).

This patch replaces `sub r6,#0x3b; add r0,r6,#0` (4 bytes @0x080cbbde) with a `bl` to a tiny
cave that loads a real "Mag" string pointer. 魔 then no longer depends on 命 (命中 is free to
translate) and both magic rows render "Mag" + their per-row suffix (威->Pwr / 効->Eff, set in
menu_status.json). Run AFTER patch_menu.py (the menu hook draws the pointer string).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from font.atlas import character_codes  # noqa: E402
from engine.script import rommap                                     # noqa: E402
from engine.script.cave_builders import sidecar_cave            # noqa: E402

B = rommap.ROM_BASE

HOOK = 0x080CBBDE          # FUN_080cbb34: `sub r6,#0x3b; add r0,r6,#0` (3b 3e 30 1c)
HOOK_OLD = bytes.fromhex("3b3e301c")
MAG = "Mag"
# cave: r6 = &"Mag", redo the replaced `adds r0,r6,#0`, bx lr (shared sidecar_cave, load_reg=r6).


def char2code():
    return character_codes()


def apply(p):
    c2c = char2code()
    mag = b"".join(c2c[ch].to_bytes(2, "little") for ch in MAG) + b"\x00\x00"
    mag_addr = p.data(mag, name="Mag")
    sidecar_cave(p, name="humanmag", hook=HOOK, hook_old=HOOK_OLD, ptr=mag_addr,
                 redo="adds r0, r6, #0", load_reg="r6")
