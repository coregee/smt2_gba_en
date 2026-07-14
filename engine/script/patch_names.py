#!/usr/bin/env python3
"""Name-repointing hook: let action/skill names exceed the inline 8-glyph field.

Skill names are drawn by ONE central function, FUN_080cd1f8(actionId, X, Y) — it
reads 8 fixed-width glyphs from the action record's name field (+0x06). We patch its
dispatch (@0x080cd210, `cmp r0,#0; bne`) to call a code cave that adds a SENTINEL
branch: if name[0]==0xFFFF, the real name is a pointer at record+0x08 -> draw it
VARIABLE-LENGTH and VARIABLE-WIDTH (advance by the VWF width table) so a long name
fits the same pixel slot; otherwise fall back to the original empty/8-glyph paths.

tr.py pack writes the sentinel (0xFFFF @ +0x06) + pool pointer (@ +0x08) for any skill
name over the 8-glyph budget. Run AFTER patch_vwf.py (cave reads the width table).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from engine.script import rommap

B = rommap.ROM_BASE

HOOK = 0x080CD210          # FUN_080cd1f8: `cmp r0,#0; bne 0x080cd238` (00 28 11 d1)
HOOK_OLD = bytes.fromhex("002811d1")
NAME_BUF = rommap.STATUS_TEXT_BUF   # tile buffer (DAT_080cd25c)
WIDTH_TBL = rommap.WIDTH_TABLE      # VWF advance table (code-indexed)
EMPTY_PATH = 0x080CD214 | 1   # original empty-name (blank-fill) path (Thumb)

# r0=name[0], r5=name ptr(record+6), r4=X, r7=Y on entry (via bl from the hook).
# Draws EVERY name variable-width: inline names straight from record+6 (capped at the
# 8-glyph field), long (sentinel) names from the pool pointer @record+8. Empty names
# (name[0]==0) fall back to the original blank-fill path. Offsets are placeholders —
# cave_asm rewrites each ldr-pc to its literal (order: NAME_BUF, WIDTH_TBL, EMPTY_PATH).
CAVE_ASM = """
    cmp  r0, #0
    beq  do_empty         /* name[0]==0 -> original blank-fill path */
    movs r1, #1
    lsls r1, r1, #16
    subs r1, #1           /* r1 = 0xFFFF (sentinel marker) */
    cmp  r0, r1
    bne  use_inline
    adds r1, r5, #2       /* sentinel: record+8 holds the pooled-name pointer */
    ldr  r6, [r1]
    movs r5, #16          /* pool string is 0-terminated; cap at 16 for safety */
    b    draw_loop
use_inline:
    adds r6, r5, #0       /* inline name lives at record+6 (r5) */
    movs r5, #8           /* cap at the fixed 8-glyph inline field */
draw_loop:
    ldrh r0, [r6]
    cmp  r0, #0
    beq  done
    ldr  r1, [pc, #0x24]  /* NAME_BUF */
    adds  r2, r4, #0
    adds  r3, r7, #0
    bl   #0x080ac8d0      /* rommap.Font_DrawGlyph */
    ldrh r0, [r6]
    ldr  r1, [pc, #0x1c]  /* WIDTH_TBL */
    ldrb r1, [r1, r0]
    adds  r4, r4, r1   /* X += VWF width */
    adds r6, #2
    subs r5, #1
    bne  draw_loop
done:
    add  sp, #4
    pop  {r4, r5, r6, r7, pc}
do_empty:
    ldr  r0, [pc, #0x10]  /* EMPTY_PATH */
    bx   r0
"""


def apply(p):
    cave = p.cave_asm(CAVE_ASM, [NAME_BUF, WIDTH_TBL, EMPTY_PATH], name="names")
    p.bl(HOOK, cave, HOOK_OLD)
