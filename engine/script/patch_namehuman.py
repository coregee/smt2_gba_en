#!/usr/bin/env python3
"""Human-name VWF: the fixed-pitch player/ally name loops on the status + skill/equip screens.

patch_name.py made the DEMON branch of the status screen (Status_DrawDemonInfo) variable-width,
but the HUMAN branches stayed fixed-pitch (12 px/glyph) — humans don't go through NAME_TABLE,
their name is the 8 charset indices at Combatant+0x00..07 decoded by Combatant_DecodeName into a
local glyph-token buffer, then drawn one glyph per 0xC px.  Three such loops:

  (1) Status_DrawDemonInfo 0x080c99c4, human branch @0x080c9b62 — name at X=0x78, white, on the
      status text canvas STATUS_TEXT_BUF; tokens decoded into the function's stack buffer (sp+8).
      (The demon branch @0x080c9b90 is already hooked by patch_name.py.)
  (2) Skill_DrawEquippedRow 0x080f3254 — the per-row party-member name on the skill/equip list.
      Two modes share one canvas (0x030000b4): the scrolling-canvas path (mode 4) draws at X=0x80,
      Y=4; the inline path (else) at X=i*0xC, Y=mode*0xD+8.  Both step a fixed 0xC.

Each cave replaces the fixed-pitch draw loop with the same shape as patch_name's demon cave:
walk the already-decoded token buffer (left-packed, 0 = empty slot = end), draw each glyph at a
running pixel X, and advance X by WIDTH_TABLE[token] instead of 0xC.  Names render proportional
and EN names (narrower than JP's 12 px cells) never overflow.  Run AFTER patch_vwf (WIDTH_TABLE).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

import rom_layout as rommap

BUF       = rommap.STATUS_TEXT_BUF        # 0x0200F874 status text canvas (== DAT_080c9b8c)
WIDTH_TBL = rommap.WIDTH_TABLE
FONT_TINT = 0x080AC980                    # Font_DrawGlyphTinted(token, canvas, X, Y, tint@[sp])
FONT_PLAIN = 0x080AC8D0                   # Font_DrawGlyph(token, canvas, X, Y)
SKILL_CANVAS = 0x030000B4                 # Skill_DrawEquippedRow canvas (== DAT_080f32e8/3328)

# --- (1) status screen, human branch ---------------------------------------------------------
# hook @0x080c9b62 `mov r6,#0; mov r5,#0xf0` (loop init) -> cave; cave draws then jumps to the
# function epilogue @0x080c9bb8.  At entry sp+8 = the decoded 8-token name buffer, r9 = Y(8).
STATUS_HOOK = 0x080C9B62
STATUS_OLD  = bytes.fromhex("0026f025")
STATUS_AFTER = 0x080C9BB8 | 1
STATUS_ASM = """
    add  r4, sp, #8        /* r4 = decoded name buffer (sp before push) */
    push {r4, r5, r6, r7, lr}
    sub  sp, #4            /* stack slot for Font_DrawGlyphTinted's 5th arg (tint) */
    mov  r6, r9            /* r6 = Y (8) */
    movs r5, #0x78         /* r5 = running X */
    movs r7, #8            /* glyph cap */
s_loop:
    ldrh r0, [r4]
    cmp  r0, #0
    beq  s_done            /* token 0 = empty slot = end of left-packed name */
    movs r1, #0
    str  r1, [sp, #0]      /* tint = 0 (white) */
    ldr  r1, [pc, #0]      /* BUF */
    adds  r2, r5, #0
    adds  r3, r6, #0
    bl   #0x080ac980       /* Font_DrawGlyphTinted */
    ldrh r0, [r4]
    ldr  r1, [pc, #0]      /* WIDTH_TBL */
    ldrb r1, [r1, r0]
    adds  r5, r5, r1   /* X += VWF width */
    adds r4, #2
    subs r7, #1
    bne  s_loop
s_done:
    add  sp, #4
    pop  {r4, r5, r6, r7}
    pop  {r3}              /* discard saved lr (we jump, not return) */
    ldr  r0, [pc, #0]      /* AFTER */
    bx   r0
"""
STATUS_LITERALS = [BUF, WIDTH_TBL, STATUS_AFTER]

# --- (2a) skill/equip list, inline path (else branch) ----------------------------------------
# hook @0x080f32f4 `mov r4,#0; mov r0,#0xd` (loop init / Y setup) -> cave; cave draws then jumps
# to the epilogue @0x080f3320.  At entry sp = the decoded name buffer, r5 = mode (row index).
INLINE_HOOK = 0x080F32F4
INLINE_OLD  = bytes.fromhex("00240d20")
INLINE_AFTER = 0x080F3320 | 1
INLINE_ASM = """
    mov  r4, sp           /* r4 = decoded name buffer (sp before push) */
    push {r4, r5, r6, r7, lr}
    movs r0, #0xd
    muls r5, r0           /* r5 = mode * 0xd */
    adds r5, #8           /* r5 = Y = mode*0xd + 8 */
    movs r6, #0           /* r6 = running X (base 0) */
    movs r7, #8           /* glyph cap */
i_loop:
    ldrh r0, [r4]
    cmp  r0, #0
    beq  i_done
    ldr  r1, [pc, #0]     /* SKILL_CANVAS */
    adds  r2, r6, #0
    adds  r3, r5, #0
    bl   #0x080ac8d0      /* Font_DrawGlyph */
    ldrh r0, [r4]
    ldr  r1, [pc, #0]     /* WIDTH_TBL */
    ldrb r1, [r1, r0]
    adds  r6, r6, r1
    adds r4, #2
    subs r7, #1
    bne  i_loop
i_done:
    pop  {r4, r5, r6, r7}
    pop  {r3}
    ldr  r0, [pc, #0]     /* AFTER */
    bx   r0
"""
INLINE_LITERALS = [SKILL_CANVAS, WIDTH_TBL, INLINE_AFTER]

# --- (2b) skill/equip list, scrolling-canvas path (mode 4) -----------------------------------
# hook @0x080f3276 `lsl r2,r4,#1; mov r0,sp` (start of the draw loop body) -> cave; cave draws
# then jumps back to the post-loop row-shuffle @0x080f32a0 (which still runs).  At entry sp = the
# decoded name buffer, r6 = sp+0x10 (used by the shuffle — preserved across the cave's push/pop).
MODE4_HOOK = 0x080F3276
MODE4_OLD  = bytes.fromhex("62006846")
MODE4_AFTER = 0x080F32A0 | 1
MODE4_ASM = """
    mov  r4, sp           /* r4 = decoded name buffer (sp before push) */
    push {r4, r5, r6, r7, lr}
    movs r5, #0x80        /* r5 = running X (base 0x80) */
    movs r7, #8           /* glyph cap */
m_loop:
    ldrh r0, [r4]
    cmp  r0, #0
    beq  m_done
    ldr  r1, [pc, #0]     /* SKILL_CANVAS */
    adds  r2, r5, #0
    movs r3, #4           /* Y = 4 */
    bl   #0x080ac8d0      /* Font_DrawGlyph */
    ldrh r0, [r4]
    ldr  r1, [pc, #0]     /* WIDTH_TBL */
    ldrb r1, [r1, r0]
    adds  r5, r5, r1
    adds r4, #2
    subs r7, #1
    bne  m_loop
m_done:
    pop  {r4, r5, r6, r7}  /* r6 restored to sp+0x10 for the shuffle */
    pop  {r3}
    ldr  r0, [pc, #0]      /* AFTER */
    bx   r0
"""
MODE4_LITERALS = [SKILL_CANVAS, WIDTH_TBL, MODE4_AFTER]


def apply(p):
    p.bl(STATUS_HOOK, p.cave_asm(STATUS_ASM, STATUS_LITERALS, name="namehuman_status"), STATUS_OLD)
    p.bl(INLINE_HOOK, p.cave_asm(INLINE_ASM, INLINE_LITERALS, name="namehuman_inline"), INLINE_OLD)
    p.bl(MODE4_HOOK, p.cave_asm(MODE4_ASM, MODE4_LITERALS, name="namehuman_mode4"), MODE4_OLD)
