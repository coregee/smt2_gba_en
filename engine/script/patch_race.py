#!/usr/bin/env python3
"""Demon-race repoint + VWF hook (status top bar, FUN_080c99c4).

The top bar draws the race name with Text_DrawStringTinted(racePtr, buf, X=0x18, Y=8,
tint=6, step=0xc) — fixed 12px, green. racePtr = names_race[race] (0x081A5C34, 0x10 stride,
name@+0, ~7-glyph inline field). We replace that one call (@0x080c9ae0) with a cave that
draws the race name VARIABLE-WIDTH (advance via the VWF table), green; and if the field
starts with 0xFFFF the real text is a pool pointer at field+2 (read as two halfwords —
the +2 slot is not 4-aligned) so the 3 long race names (Amatsukami/Demonoid/Shinshou)
fit too. tr.py pack writes 0xFFFF + pointer for every translated names_race entry (sentinel
fields always repoint so the draw path is uniformly VWF; this cave draws VWF either way).

Run AFTER patch_vwf.py (cave reads the width table).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from engine.script import rommap

B = rommap.ROM_BASE

HOOK = 0x080C9AE0          # `bl Text_DrawStringTinted` (race draw)
HOOK_OLD = bytes.fromhex("e2f772ff")
DRAW_GLYPH_T = rommap.Font_DrawGlyphTinted   # Font_DrawGlyphTinted(code, buf, X, Y, tint)
WIDTH_TBL = rommap.WIDTH_TABLE               # VWF advance table (code-indexed)

# entry (bl from hook): r0=racePtr, r1=buf, r2=X(0x18), r3=Y(8). Draws green VWF and returns.
CAVE_ASM = """
    push {r4, r5, r6, r7, lr}
    sub  sp, #4            /* stack slot for Font_DrawGlyphTinted's 5th arg (tint) */
    adds  r7, r1, #0   /* r7 = buf */
    adds  r4, r2, #0   /* r4 = X */
    adds  r5, r3, #0   /* r5 = Y */
    ldrh r1, [r0]
    movs r2, #1
    lsls r2, r2, #16
    subs r2, #1           /* r2 = 0xFFFF sentinel */
    cmp  r1, r2
    bne  r_have
    adds r0, #2           /* field+2: pool pointer (read as 2 halfwords - may be unaligned) */
    ldrh r1, [r0]
    ldrh r0, [r0, #2]
    lsls r0, r0, #16
    orrs r0, r1
r_have:
    adds  r6, r0, #0   /* r6 = string pointer */
r_loop:
    ldrh r0, [r6]
    cmp  r0, #0
    beq  r_done
    movs r1, #6
    str  r1, [sp, #0]     /* tint = 6 (green) */
    adds  r1, r7, #0   /* buf */
    adds  r2, r4, #0   /* X */
    adds  r3, r5, #0   /* Y */
    bl   #0x080ac980
    ldrh r0, [r6]
    ldr  r1, [pc, #0]    /* WIDTH_TBL */
    ldrb r1, [r1, r0]
    adds  r4, r4, r1   /* X += VWF width */
    adds r6, #2
    b    r_loop
r_done:
    add  sp, #4
    pop  {r4, r5, r6, r7, pc}
"""

LITERALS = [WIDTH_TBL]


def apply(p):
    cave = p.cave_asm(CAVE_ASM, LITERALS, name="race")
    p.bl(HOOK, cave, HOOK_OLD)
