#!/usr/bin/env python3
"""Narrow element/attribute-name repoint + VWF hook (equip screen, FUN_080cd8c4).

FUN_080cd8c4 draws the equipped item's element/attribute label from the NARROW name
table at 0x084F06D6 (0x0A stride, 4-glyph right-aligned cell), via
Text_DrawStringTinted(strPtr, buf, X, Y, tint=4, step=0xc) — fixed 12px. strPtr =
table[record.bCategory] (the table is the "menu_element_narrow" bank in tr.py). The cell
is only 10 bytes, so English longer than 4 glyphs can't be written inline.

We replace that one call (the `bl` @0x080cd8f6) with a cave: if the field's first u16 is
0xFFFF the real text is a pool pointer at field+2 (read as two halfwords — the +2 slot is
not 4-aligned), drawn VARIABLE-width (advance via the VWF table), tint 4; otherwise we
tail-call the original Text_DrawStringTinted so untranslated JP renders pixel-identical
(fixed 12px). tr.py pack writes 0xFFFF + pointer for every over-budget translated
menu_element_narrow entry (it's a SENTINEL bank); short English that fits stays inline and
takes the JP/fixed path, which is fine since only one category label is on screen at a time.

Run AFTER patch_vwf.py (cave reads the width table).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

import rom_layout as rommap

B = rommap.ROM_BASE

HOOK = 0x080CD8F6          # `bl Text_DrawStringTinted` (narrow element-label draw, FUN_080cd8c4)
HOOK_OLD = bytes.fromhex("dff767f8")
HOOK_WIDE = 0x080CD8AE     # `bl Text_DrawStringTinted` (WIDE element-label draw, FUN_080cd87c) — same
HOOK_WIDE_OLD = bytes.fromhex("dff78bf8")   # signature (strPtr,buf,X,Y,tint=4,step=0xc) -> reuse the cave
DRAW_GLYPH_T = rommap.Font_DrawGlyphTinted   # Font_DrawGlyphTinted(code, buf, X, Y, tint)
DRAW_STRING_T = 0x080AC9C8                    # Text_DrawStringTinted (original fixed-step drawer)
WIDTH_TBL = rommap.WIDTH_TABLE               # VWF advance table (code-indexed)

# entry (bl from hook): r0=strPtr, r1=buf, r2=X, r3=Y. tint=4, step=0xc (as the original).
CAVE_ASM = f"""
    push {{r4, r5, r6, r7, lr}}
    sub  sp, #8           /* 2 stack-arg slots (tint, step) */
    ldrh r7, [r0]
    movs r6, #1
    lsls r6, r6, #16
    subs r6, #1           /* r6 = 0xFFFF sentinel */
    cmp  r7, r6
    beq  e_vwf
    /* ---- untranslated / short-inline: original Text_DrawStringTinted(r0,r1,r2,r3, 4, 0xc) ---- */
    movs r6, #4
    str  r6, [sp, #0]     /* tint = 4 */
    movs r6, #0xc
    str  r6, [sp, #4]     /* step = 0xc (fixed 12px) */
    bl   #{DRAW_STRING_T:#x}
    b    e_done
e_vwf:
    adds  r7, r1, #0   /* r7 = buf */
    adds  r4, r2, #0   /* r4 = X */
    adds  r5, r3, #0   /* r5 = Y */
    adds r0, #2           /* field+2: pool pointer (read as 2 halfwords - may be unaligned) */
    ldrh r1, [r0]
    ldrh r0, [r0, #2]
    lsls r0, r0, #16
    orrs r0, r1
    adds  r6, r0, #0   /* r6 = pooled string pointer */
e_loop:
    ldrh r0, [r6]
    cmp  r0, #0
    beq  e_done
    movs r1, #4
    str  r1, [sp, #0]     /* tint = 4 */
    adds  r1, r7, #0   /* buf */
    adds  r2, r4, #0   /* X */
    adds  r3, r5, #0   /* Y */
    bl   #{DRAW_GLYPH_T:#x}
    ldrh r0, [r6]
    ldr  r1, [pc, #0]    /* WIDTH_TBL */
    ldrb r1, [r1, r0]
    adds  r4, r4, r1   /* X += VWF width */
    adds r6, #2
    b    e_loop
e_done:
    add  sp, #8
    pop  {{r4, r5, r6, r7, pc}}
"""

LITERALS = [WIDTH_TBL]


def apply(p):
    cave = p.cave_asm(CAVE_ASM, LITERALS, name="element_narrow")
    p.bl(HOOK, cave, HOOK_OLD)
    p.bl(HOOK_WIDE, cave, HOOK_WIDE_OLD)   # wide table (menu_element) -> same sentinel/VWF cave
