#!/usr/bin/env python3
"""VWF advance hook for the central string printers Text_DrawString / Text_DrawStringTinted.

These two functions (0x080ac908 / 0x080ac9c8) are THE flowing-text printers used for
item/skill descriptions, the dialogue message box (MessageBox_DrawText), settings help,
and the demon-screen race/affinity labels. Each walks a u16 glyph string and advances the
cursor by a FIXED `step` per glyph (`x = (x + step) & 0xffff`), which is why English
descriptions render monospaced (see the field-magic screenshot in docs/font-rendering.md).

Both printers share the identical advance site:
    add r4,#2            (string ptr += 1, just before the advance)
    add r0,r5,r7         <- r5=X, r7=step
    lsl r0,r0,#0x10
    lsr r5,r0,#0x10      (x = (x+step) & 0xffff)
We replace the 6-byte advance (`add r0,r5,r7; lsl; lsr`) with `bl CAVE; nop`. The cave reads
the just-drawn glyph code at [r4-2]; for an English glyph (code 0xBC..0x117) it advances by
the VWF width table, otherwise it keeps the original fixed `step` (so every Japanese/kanji
string is byte-for-byte unchanged — JP printers pass step=12, English glyphs get trimmed
advance). The font is already left-aligned + the width table written by patch_vwf.py.

Run AFTER patch_vwf.py (needs the left-aligned glyphs + width table). Idempotent-ish:
asserts the original bytes before patching.
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from engine.script import rommap

B = rommap.ROM_BASE

WIDTH_TBL = rommap.WIDTH_TABLE
ENG_LO = rommap.ENG_LO     # English glyph code range; outside it = JP (keep fixed pitch)
ENG_HI = rommap.ENG_HI

# Identical advance at both printers: `add r0,r5,r7; lsl r0,r0,#0x10; lsr r5,r0,#0x10`.
P1 = 0x080AC95E            # Text_DrawString advance
P2 = 0x080ACA18            # Text_DrawStringTinted advance
ADV_OLD = bytes.fromhex("e8190004050c")
NOP = bytes.fromhex("c046")

# entry (bl from either site): r5=X, r7=step, r4=string ptr (already +2 past the glyph).
# r0-r3 and lr are scratch at both sites (reloaded next loop iteration). Returns X in r5.
CAVE_ASM = """
    subs r0, r4, #2       /* r0 -> the glyph just drawn */
    ldrh r0, [r0]         /* r0 = glyph code */
    cmp  r0, #0xbc        /* code < 0xBC -> not English */
    blo  use_step
    ldr  r1, [pc, #0]     /* = ENG_HI (0x118) */
    cmp  r0, r1
    bhs  use_step         /* code >= 0x118 -> not English */
    ldr  r1, [pc, #0]     /* = WIDTH_TBL */
    ldrb r1, [r1, r0]
    adds r5, r5, r1       /* English: X += VWF width */
    b    fin
use_step:
    adds r5, r5, r7       /* else: original fixed step */
fin:
    lsls r5, r5, #0x10
    lsrs r5, r5, #0x10
    bx   lr
"""

LITERALS = [ENG_HI, WIDTH_TBL]   # in ldr-pc order


def apply(p):
    cave = p.cave_asm(CAVE_ASM, LITERALS, name="descvwf")
    p.bl(P1, cave, ADV_OLD)   # Text_DrawString advance (bl + nop)
    p.bl(P2, cave, ADV_OLD)   # Text_DrawStringTinted advance
