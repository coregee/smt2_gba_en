#!/usr/bin/env python3
"""Tinted twin of patch_menu.py: let any fixed-position TINTED menu glyph become a string.

patch_menu.py hooks the opaque Font_DrawGlyph (0x080ac8d0) so a label whose literal is a
ROM pointer renders as a pooled VWF string. But many labels are drawn through the *tinted*
single-glyph path Font_DrawGlyphTinted (0x080ac980) instead — battle skill-name arrays
(FUN_0812{72cc,7394,745c,756c}), item/equipment labels, etc. — and those bypass the menu
hook. This patch gives the tinted path the same pointer trick.

Hook site: the code arg is masked to 16 bits at 0x080ac990 (`lsl r0,#0x10; lsr r0,#0x10`),
so the `>= 0x08000000` pointer test must run BEFORE the mask. We replace those two
instructions with `bl CAVE`. In the cave:
  - code < 0x08000000  -> redo the mask, `bx lr` (lr = 0x080ac994, set by the hook bl).
  - code >= pointer    -> draw the pooled string one glyph at a time via recursive
                          Font_DrawGlyphTinted calls (re-passing the tint, the 5th stack
                          arg the callee reads at [sp,#0x28]), advancing X by the VWF width
                          table, then replicate the function epilogue to return.
Japanese is untouched: a real u16 code is always < 0x08000000, so it takes the redo-mask
path with byte-identical behaviour. Run AFTER patch_menu.py (shares the width table).

tr.py pack translates a tinted label exactly like a menu one: write English to a pool and
set the slot's literal to that pointer (blank extra slots).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

import rom_layout as rommap

B = rommap.ROM_BASE

HOOK = 0x080AC990          # Font_DrawGlyphTinted: `lsl r0,#0x10; lsr r0,#0x10` (00 04 00 0c)
HOOK_OLD = bytes.fromhex("0004000c")
DRAW_TINTED = rommap.Font_DrawGlyphTinted
WIDTH_TBL = rommap.WIDTH_TABLE

# entry (via bl from the hook): r0=code/ptr(32b, UNMASKED), r4=X, r5=Y, r6=tint(raw),
# r8=canvas; lr=0x080ac994 (resume). Function frame already set up (sub sp,#0x14 + pushes).
CAVE_ASM = """
    ldr  r1, [pc, #0x40]   /* 0x08000000 */
    cmp  r0, r1
    bhs  ptr               /* code looks like a ROM pointer -> string */
    lsls r0, r0, #0x10     /* redo replaced mask: r0 = code & 0xffff (lsls = Thumb-1 narrow) */
    lsrs r0, r0, #0x10
    bx   lr                /* resume at 0x080ac994 (normal one-glyph path) */
ptr:
    lsls r6, r6, #0x18     /* mask tint to a byte (function does this at 0x080ac99c) */
    lsrs r6, r6, #0x18
    push {r7}              /* AAPCS: the function frame does not preserve r7 */
    adds  r7, r0, #0   /* r7 = string ptr */
mloop:
    ldrh r0, [r7]
    cmp  r0, #0
    beq  mdone
    mov  r1, r8            /* canvas */
    adds  r2, r4, #0   /* X */
    adds  r3, r5, #0   /* Y */
    push {r6}              /* 5th arg = tint (callee reads [sp,#0x28]) */
    bl   #0x080ac980       /* draw one glyph tinted (code < ptr -> normal path) */
    add  sp, #4
    ldrh r0, [r7]
    ldr  r1, [pc, #0x10]   /* WIDTH_TBL */
    ldrb r1, [r1, r0]
    adds  r4, r4, r1   /* X += width (VWF) */
    adds r7, #2
    b    mloop
mdone:
    pop  {r7}
    add  sp, #0x14         /* replicate Font_DrawGlyphTinted epilogue */
    pop  {r3}
    mov  r8, r3
    pop  {r4, r5, r6}
    pop  {r0}
    bx   r0
"""


def apply(p):
    cave = p.cave_asm(CAVE_ASM, [B, WIDTH_TBL], name="menutinted")
    p.bl(HOOK, cave, HOOK_OLD)
