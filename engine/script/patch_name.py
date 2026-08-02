#!/usr/bin/env python3
"""Demon-name repoint + VWF (status screen, FUN_080c99c4) via a parallel id->name table.

The demon name is the misnamed "skills" loop in FUN_080c99c4: 8 fixed glyphs from the ROM
record +0x22 at X=0x78, white. That +0x22 field is SHARED by every other name display
(fusion/party/battle) with no central drawer, so we must NOT sentinel it. Instead tr.py
pack writes a parallel table demon-id -> pooled-name pointer at POOL_START (0x087F4240,
0x148 u32 entries, 0 = no override), and this cave (hooking only the status loop) looks the
name up by id ([r7+0x12], 0x20C-entry table covering all 524 combatant ids) and draws it
variable-width if present, else the original +0x22
name. So the status screen shows the English name without touching the shared field; other
screens stay Japanese until they're hooked too.

We replace `mov r6,#0; mov r5,#0xf0` @0x080c9b90 (the demon-branch loop entry) with a bl to
the cave, which draws then jumps to the function epilogue @0x080c9bb8. Run AFTER patch_vwf.py.
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

import rom_layout as rommap

B = rommap.ROM_BASE

HOOK = 0x080C9B90          # demon-branch name loop entry: `mov r6,#0; mov r5,#0xf0`
HOOK_OLD = bytes.fromhex("0026f025")
NAME_TABLE = rommap.NAME_TABLE
NAME_COUNT = rommap.NAME_COUNT   # table entry count (= real demons, ids 0-379)
BUF = rommap.STATUS_TEXT_BUF     # status text buffer (DAT_080c9bc8)
WIDTH_TBL = rommap.WIDTH_TABLE
AFTER = 0x080C9BB8 | 1     # function epilogue (after the name loop), Thumb

# entry (bl from hook): r10=record, r9=Y(8), r7=runtime slot. Draws name at X=0x78 white VWF.
# Combatant species ids run to 0x20B (524 enemies/demons) but the name table only has
# NAME_COUNT (0x148) entries, so ids >= NAME_COUNT must use the inline +0x22 name — without
# the bounds check they index past the table into the adjacent ITEM_TABLE and draw a weapon
# name (e.g. demon 368 パスカル/Pascal showed "Ankou's Scythe" = equipment id 40).
CAVE_ASM = """
    ldrh r0, [r7, #0x12]   /* demon id */
    push {r4, r5, r6, r7, lr}
    sub  sp, #4            /* stack slot for Font_DrawGlyphTinted's 5th arg (tint) */
    ldr  r1, [pc, #0]      /* NAME_COUNT */
    cmp  r0, r1
    bhs  n_inline          /* id >= table size -> inline name (avoid OOB read into ITEM_TABLE) */
    lsls r0, r0, #2
    ldr  r1, [pc, #0]      /* NAME_TABLE */
    ldr  r6, [r1, r0]      /* r6 = table[id] = pooled name ptr, or 0 */
    cmp  r6, #0
    bne  n_go
n_inline:
    mov  r6, r10           /* no override / OOB id: original inline name at record+0x22 */
    adds r6, #0x22
n_go:
    movs r4, #0x78         /* X = 0x78 */
    mov  r5, r9            /* Y */
    movs r7, #16           /* glyph cap (safety) */
n_loop:
    ldrh r0, [r6]
    cmp  r0, #0
    beq  n_done
    movs r1, #0
    str  r1, [sp, #0]     /* tint = 0 (white) */
    ldr  r1, [pc, #0]     /* BUF */
    adds  r2, r4, #0
    adds  r3, r5, #0
    bl   #0x080ac980      /* rommap.Font_DrawGlyphTinted */
    ldrh r0, [r6]
    ldr  r1, [pc, #0]     /* WIDTH_TBL */
    ldrb r1, [r1, r0]
    adds  r4, r4, r1   /* X += VWF width */
    adds r6, #2
    subs r7, #1
    bne  n_loop
n_done:
    add  sp, #4
    pop  {r4, r5, r6, r7}
    pop  {r3}             /* discard saved lr (we jump, not return) */
    ldr  r0, [pc, #0]     /* AFTER */
    bx   r0
"""

LITERALS = [NAME_COUNT, NAME_TABLE, BUF, WIDTH_TBL, AFTER]


def apply(p):
    cave = p.cave_asm(CAVE_ASM, LITERALS, name="name")
    p.bl(HOOK, cave, HOOK_OLD)
