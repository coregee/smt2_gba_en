#!/usr/bin/env python3
"""Shop/inventory/equip-menu item+equipment name repoint + VWF via the id->name pool table.

FUN_080bf37c(itemId, p2, p3, X, p5, pitch) is the *unified* menu name drawer: for itemId < 0xD0
it reads the EquipmentRecord36 name (+0x14), else the ItemRecord32 name (+0x0C), then draws up to
8 fixed-width glyphs through FUN_080ac218 (the OAM sprite-glyph primitive), advancing X by `pitch`
each glyph. This one function feeds the shop list, the inventory list and the equip menu, so the
status-only patch_drop hook didn't cover any of them — over-budget names (e.g. "Attack Knife",
26B > the 18B in-record budget) stayed Japanese here.

tr.py pack now mirrors every equipment (id 0x00-0xCF) AND item (id 0xD0-0x159) name into the
ITEM_TABLE id->pooled-pointer table (any length). This cave hooks the draw loop: if table[id] is a
pooled English name it draws it variable-width and jumps to the epilogue; otherwise it restores the
one replaced setup instruction and falls back into the original fixed-width loop (untranslated and
out-of-range ids stay byte-for-byte as before). Run AFTER patch_vwf.py.

We replace `mov r6,#0; b loop_cond` @0x080bf3de (the draw-loop entry, with the masked id still in
r6 and the JP name ptr in r4) with a bl to the cave. The epilogue @0x080bf406 restores r4-r10 from
the stack, so the cave may clobber them freely; sp is left untouched so the epilogue unwinds cleanly.
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from engine.script import rommap

B = rommap.ROM_BASE

HOOK = 0x080BF3DE          # draw-loop entry: `mov r6,#0` + `b 0x080bf400`
HOOK_OLD = bytes.fromhex("00260ee0")
ITEM_TABLE = rommap.ITEM_TABLE
ITEM_COUNT = rommap.ITEM_COUNT   # id >= this -> original fixed-width path
WIDTH_TBL = rommap.WIDTH_TABLE
EPI = 0x080BF406 | 1       # function epilogue (Thumb)
CONT = 0x080BF400 | 1      # original draw-loop condition check (Thumb), after r6 := 0

# entry (bl from hook): r6=masked itemId, r4=JP name ptr, r7=X, r10=p2, r9=p3, r8=p5, r5=pitch.
# [sp,#0] is the scratch slot the original uses for FUN_080ac218's 5th arg. We don't push, so the
# epilogue's `add sp,#4; pop {...}` still unwinds the original frame.
CAVE_ASM = """
    ldr  r1, [pc, #0]      /* ITEM_COUNT */
    cmp  r6, r1
    bhs  m_orig            /* id >= table size -> original fixed-width path (no OOB read) */
    ldr  r0, [pc, #0]      /* ITEM_TABLE */
    lsls r1, r6, #2
    ldr  r1, [r0, r1]      /* r1 = table[id] = pooled name ptr, or 0 */
    cmp  r1, #0
    beq  m_orig            /* no override -> original */
    adds  r4, r1, #0   /* r4 = pooled English name ptr (drawn VWF) */
    movs r6, #0            /* r6 = glyph counter */
m_loop:
    ldrh r0, [r4]
    cmp  r0, #0
    beq  m_done
    mov  r1, r8            /* p5 */
    str  r1, [sp, #0]
    mov  r1, r10           /* p2 */
    mov  r2, r9            /* p3 */
    adds  r3, r7, #0   /* X */
    bl   #0x080ac218       /* rommap.FontSprite_DrawGlyph */
    ldrh r0, [r4]
    ldr  r1, [pc, #0]      /* WIDTH_TBL */
    ldrb r1, [r1, r0]
    adds r7, r7, r1        /* X += VWF width */
    lsls r7, r7, #0x10     /* keep X a ushort, as the original loop does */
    lsrs r7, r7, #0x10
    adds r4, #2
    adds r6, #1
    cmp  r6, #0x1f         /* safety cap (terminator is the real stop) */
    bls  m_loop
m_done:
    ldr  r0, [pc, #0]      /* EPI */
    bx   r0
m_orig:
    movs r6, #0            /* reproduce the replaced `mov r6,#0` then rejoin the original loop */
    ldr  r0, [pc, #0]      /* CONT */
    bx   r0
"""

LITERALS = [ITEM_COUNT, ITEM_TABLE, WIDTH_TBL, EPI, CONT]


def apply(p):
    cave = p.cave_asm(CAVE_ASM, LITERALS, name="itemname")
    p.bl(HOOK, cave, HOOK_OLD)
