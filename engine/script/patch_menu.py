#!/usr/bin/env python3
"""Universal menu-label hook: let any fixed-position menu glyph become a full string.

Menu labels are drawn one glyph at a time by FUN_080ac8d0(code, buf, X, Y) at hardcoded
X (status screen, base stats, etc.). We hook it (@0x080ac8d4, replacing `add r6,r1; add
r4,r2`) with a cave: if the code arg is actually a ROM POINTER (>= 0x08000000) — which a
real glyph code never is — draw the pooled string it points to VARIABLE-WIDTH (advance by
the VWF width table) via recursive single-glyph calls; otherwise redo the two replaced
instructions and fall back to the normal one-glyph path.

tr.py pack then translates a label by writing English to the pool and setting the slot's
literal to that pointer (blanking any extra slots). Run AFTER patch_vwf.py / patch_names.py.
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from engine.script import rommap

B = rommap.ROM_BASE

HOOK = 0x080AC8D4          # FUN_080ac8d0: `add r6,r1,#0; add r4,r2,#0` (0e 1c 14 1c)
HOOK_OLD = bytes.fromhex("0e1c141c")
DRAW_GLYPH = rommap.Font_DrawGlyph
WIDTH_TBL = rommap.WIDTH_TABLE
BACK = 0x080AC8D8 | 1      # resume original at `add r5,r3,#0` (Thumb)

# entry (via bl from the hook): r0=code/ptr(32b), r1=buf, r2=X, r3=Y; frame already set up.
CAVE_ASM = """
    ldr  r6, [pc, #0x34]   /* 0x08000000 */
    cmp  r0, r6
    bhs  ptr               /* code looks like a ROM pointer -> string */
    cmp  r2, #0xF0         /* X >= 240: glyph is off the right edge -> skip drawing it */
    bhs  skip              /*   (stops a runaway cursor writing past the buffer = corruption) */
    adds r6, r1, #0        /* redo replaced: r6 = buf (adds = Thumb-1 16-bit) */
    adds r4, r2, #0        /* redo replaced: r4 = X */
    ldr  r2, [pc, #0x30]   /* 0x080ac8d9 (resume) */
    bx   r2
skip:
    add  sp, #0x10         /* off-screen: drop FUN_080ac8d0's frame, return without drawing */
    pop  {r4, r5, r6, pc}
ptr:
    push {r1}              /* save buf across the loop */
    adds  r6, r0, #0   /* string ptr */
    adds  r4, r2, #0   /* X */
    adds  r5, r3, #0   /* Y */
mloop:
    ldrh r0, [r6]
    cmp  r0, #0
    beq  mdone
    ldr  r1, [sp]
    adds  r2, r4, #0
    adds  r3, r5, #0
    bl   #0x080ac8d0       /* draw one glyph (code < ptr -> normal path) */
    ldrh r0, [r6]
    ldr  r1, [pc, #0x14]   /* WIDTH_TBL */
    ldrb r1, [r1, r0]
    adds  r4, r4, r1   /* X += width (VWF) */
    adds r6, #2
    b    mloop
mdone:
    pop  {r1}
    add  sp, #0x10         /* undo FUN_080ac8d0's sub sp,#0x10 */
    pop  {r4, r5, r6, pc}
"""


def apply(p):
    cave = p.cave_asm(CAVE_ASM, [B, BACK, WIDTH_TBL], name="menu")
    p.bl(HOOK, cave, HOOK_OLD)
