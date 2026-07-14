#!/usr/bin/env python3
"""Resist-text repointing + VWF hook (demon status screen, FUN_080cd2a0).

The status screen draws two inline resist lines from the demon record: line 1 from
record+0x32 (11 fixed slots), line 2 from record+0x48 (0-terminated). FUN_080cd2a0 is
the ONLY reader of those fields, so we can repoint them safely: if a line's first u16
is 0xFFFF, the real text is a pool pointer at field+2 — drawn variable-LENGTH and
variable-WIDTH (advance by the VWF width table); otherwise the original fixed-12px loop.

We hook at 0x080cd2d8 (after both field pointers r6=+0x32 / r4=+0x48 and X/Y are set up),
replacing `mov r7,#0xa; ldrh r0,[r6]`, and the cave draws BOTH lines then jumps to the
function epilogue at 0x080cd31e. tr.py pack writes 0xFFFF + pool pointer for EVERY translated
resist line (not just over-budget ones): the inline fallback is fixed-12px, so a short English
line that fit the budget would otherwise draw fixed-width while a long one drew VWF — repointing
all of them keeps the path uniformly VWF. Untranslated JP stays inline-fixed (pixel-identical;
the width table assigns JP glyphs 13px, not 12). Run AFTER patch_vwf.py (cave reads the width table).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from engine.script import rommap

B = rommap.ROM_BASE

HOOK = 0x080CD2D8          # `mov r7,#0xa; ldrh r0,[r6,#0]` (0a 27 30 88)
HOOK_OLD = bytes.fromhex("0a273088")
DRAW_GLYPH = rommap.Font_DrawGlyph   # Font_DrawGlyph(code, buf, X, Y)
BUF = rommap.STATUS_TEXT_BUF         # status text buffer (DAT_080cd32c)
WIDTH_TBL = rommap.WIDTH_TABLE       # VWF advance table (code-indexed)
EPI = 0x080CD31E | 1       # function epilogue (Thumb)

# entry (bl from hook): r6=record+0x32 (line1), r4=record+0x48 (line2), r5=X,
# r8=Y1, r9=X, r10=Y2. Font_DrawGlyph preserves r4-r7; we read the high regs up
# front. Stack stays balanced so the epilogue's pop {r3,r4,r5}/… still works.
CAVE_ASM = """
    mov  r0, r9           /* X (for line 2) */
    mov  r1, r10          /* Y2 */
    push {r0, r1, r4}     /* save X, Y2, field2 for line 2 */
    /* ---- LINE 1: field=r6 (+0x32), X=r5, Y=r8 ---- */
    mov  r7, r8           /* r7 = Y1 */
    ldrh r0, [r6]
    movs r1, #1
    lsls r1, r1, #16
    subs r1, #1           /* r1 = 0xFFFF sentinel */
    cmp  r0, r1
    bne  l1_inline
    adds r6, #2           /* field+2: pool pointer (read as 2 halfwords - may be unaligned) */
    ldrh r0, [r6]
    ldrh r6, [r6, #2]
    lsls r6, r6, #16
    orrs r6, r0          /* r6 = pooled string pointer */
l1_pool:
    ldrh r0, [r6]
    cmp  r0, #0
    beq  line2
    ldr  r1, [pc, #0]     /* BUF */
    adds  r2, r5, #0
    adds  r3, r7, #0
    bl   #0x080ac8d0
    ldrh r0, [r6]
    ldr  r1, [pc, #0]     /* WIDTH_TBL */
    ldrb r1, [r1, r0]
    adds  r5, r5, r1   /* X += VWF width */
    adds r6, #2
    b    l1_pool
l1_inline:
    movs r4, #11          /* original: 11 fixed slots */
l1_fixed:
    ldrh r0, [r6]
    ldr  r1, [pc, #0]     /* BUF */
    adds  r2, r5, #0
    adds  r3, r7, #0
    bl   #0x080ac8d0
    adds r5, #0xc
    adds r6, #2
    subs r4, #1
    bne  l1_fixed
line2:
    pop  {r5, r6, r7}     /* r5=X, r6=Y2, r7=field2 */
    ldrh r0, [r7]
    movs r1, #1
    lsls r1, r1, #16
    subs r1, #1
    cmp  r0, r1
    bne  l2_inline
    adds r7, #2           /* field+2: pool pointer (read as 2 halfwords - may be unaligned) */
    ldrh r0, [r7]
    ldrh r7, [r7, #2]
    lsls r7, r7, #16
    orrs r7, r0          /* r7 = pooled string pointer */
l2_pool:
    ldrh r0, [r7]
    cmp  r0, #0
    beq  cdone
    ldr  r1, [pc, #0]     /* BUF */
    adds  r2, r5, #0
    adds  r3, r6, #0
    bl   #0x080ac8d0
    ldrh r0, [r7]
    ldr  r1, [pc, #0]     /* WIDTH_TBL */
    ldrb r1, [r1, r0]
    adds  r5, r5, r1
    adds r7, #2
    b    l2_pool
l2_inline:
    movs r4, #11          /* original: 0-terminated, up to 11 */
l2_fixed:
    ldrh r0, [r7]
    cmp  r0, #0
    beq  cdone
    ldr  r1, [pc, #0]     /* BUF */
    adds  r2, r5, #0
    adds  r3, r6, #0
    bl   #0x080ac8d0
    adds r5, #0xc
    adds r7, #2
    subs r4, #1
    bne  l2_fixed
cdone:
    ldr  r0, [pc, #0]     /* EPI */
    bx   r0
"""

LITERALS = [BUF, WIDTH_TBL, BUF, BUF, WIDTH_TBL, BUF, EPI]   # in ldr-pc order


def apply(p):
    cave = p.cave_asm(CAVE_ASM, LITERALS, name="resist")
    p.bl(HOOK, cave, HOOK_OLD)
