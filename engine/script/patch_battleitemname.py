#!/usr/bin/env python3
"""Item / equipment names in BATTLE-composed text -> English.

`{ITEM_NAME}` (opcode 0x0321) inside battle messages and menu lists is expanded by
`Menu_ExpandListTemplate 0x080EBCA4` (the battle/menu list-template expander, NOT the
event-VM `ScriptOp_DrawCharOrSubstitute` path that patch_dialogitemname covers).  Its
case 0xb (@0x080ebdfe) takes the item id from `param_2 >> 16`, resolves the record
(`Equipment_GetRecord36_Low/MidRange` for ids <0xd0, else `Item_GetRecord32`), reads its
`pDisplayText` into r8, and copies a FIXED 8 inline glyph tokens of the **Japanese** name
into the compose buffer.  So the in-battle "X used <item>" message (battle.json id 124)
and any other battle list/message {ITEM_NAME} drew Japanese — the user reported
"Aleph / used 傷薬" (傷薬 still JP while the actor name + prose were English; the actor
name is fine because case 0xa routes through the EN-aware Combatant_GetDisplayName).

English item/equipment names already live in ITEM_TABLE (id->pooled pointer, filled by
patch_itemname / tr.pack — the same table the dialogue/shop/inventory caves read).  This
is the exact battle sibling of patch_dialogitemname: replace the cap-8 copy loop with a
cave that prefers ITEM_TABLE[id] (else keeps the JP record name in r8) and STREAMS the
whole name (cap 15) into the compose buffer up to its 0x0000 / 0x0301 terminator.  The
name then flows as ordinary VWF glyph tokens through cave_runtext (real per-glyph widths,
no cap-8 truncation), and the surrounding text reflows tight after it.  One hook covers
EVERY battle-composed {ITEM_NAME}.  Untranslated / out-of-range ids fall back to the JP
record name (byte-safe; for ids >=0xff with no EN, r8 is the stock's stale value — the
pre-existing behavior, which the EN lookup actually repairs whenever a name exists).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from engine.script import rommap
from engine.script.cave_asm import thumb_bl

# the case-0xb cap-8 copy loop @0x080ebe2a..0x080ebe4a (34 B).  r5 = template ptr,
# r6 = compose cursor, r8 = JP pDisplayText, r9 = param_2 (item id = r9>>16).  Ends just
# before the SHARED join @0x080ebe4c (`add r5,r7`; also reached from case 0xa) -> the cave
# MUST leave r7 = r5+2 and must not touch 0x080ebe4c.
HOOK     = 0x080EBE2A
HOOK_OLD = "424600201188af1c00290ad031800232023601300006000e072802d811880029f4d1"

ITEM_TABLE = rommap.ITEM_TABLE   # id -> pooled English name ptr (0 = none); patch_itemname / tr.pack fill it
ITEM_COUNT = rommap.ITEM_COUNT

# Replaces the copy loop.  Sets r7 = r5+2 (the shared join restores r5 from it); resolves
# src = ITEM_TABLE[id] (id<count and non-null) else the stock JP r8; streams cap-15 into r6
# stopping at 0x0000 / 0x0301; advances r6.  Uses r0-r4 (r4 saved); leaves r5/r9/r10 intact.
CAVE_ASM = """
    push {r4}
    adds r7, r5, #2        /* template+1 token; 0x080ebe4c does r5 = r7 */
    mov  r3, r9
    lsrs r3, r3, #16       /* r3 = item id (param_2 >> 16) */
    mov  r2, r8            /* default src = JP pDisplayText */
    ldr  r0, [pc, #0]      /* ITEM_COUNT */
    cmp  r3, r0
    bhs  bi_copy           /* id >= count: keep JP */
    ldr  r0, [pc, #0]      /* ITEM_TABLE */
    lsls r1, r3, #2
    ldr  r0, [r0, r1]      /* ITEM_TABLE[id] */
    cmp  r0, #0
    beq  bi_copy
    adds r2, r0, #0        /* src = pooled English name */
bi_copy:
    movs r4, #0x03
    lsls r4, r4, #8
    adds r4, #0x01         /* r4 = 0x0301 string terminator */
    movs r1, #0            /* count */
bi_loop:
    cmp  r1, #15
    bhs  bi_done
    ldrh r0, [r2]
    cmp  r0, #0
    beq  bi_done
    cmp  r0, r4
    beq  bi_done
    strh r0, [r6]
    adds r2, #2
    adds r6, #2
    adds r1, #1
    b    bi_loop
bi_done:
    pop  {r4}
    bx   lr
"""
LITERALS = [ITEM_COUNT, ITEM_TABLE]


def apply(p):
    cave = p.cave_asm(CAVE_ASM, LITERALS, name="battleitemname")
    new = bytes.fromhex(thumb_bl(HOOK, cave).hex()) + b"\xc0\x46" * 15   # bl cave + 15 NOP (34 B)
    p.patch(HOOK, HOOK_OLD, new, name="battleitem-copy")
    print(f"battleitemname: {{ITEM_NAME}} (0x0321) battle sub -> EN ITEM_TABLE, cave @0x{cave:08X}")
