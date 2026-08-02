#!/usr/bin/env python3
"""Script-window shop list item/equipment names -> pooled English (patch_shopname).

Shop_InitItemList 0x08133b18 builds the event-window buy/sell pages (script states
0x22/0x25 items, 0x28/0x2A equipment): per row it copies EXACTLY 8 tokens from the
record's pDisplayText into the staging buffer 0x0203DB08, and FUN_08133a80 appends
them as 8 glyph records on the 13px grid.  The records hold the inline JP names
(over-budget English never fit the in-record slots), so shop lists drew JP
(user report 2026-06-13, junk/weapon shop).

Fix = the patch_battlename marker idea on the message-window substrate: the copy
loop is replaced by a cave that writes ONE marker token 0xF000|itemId (+ 7 zero
tokens) into the staging buffer when ITEM_TABLE[itemId] holds a pooled English
name; cave_msgwin expands the marker at draw time — full-length VWF name at the
row's column anchor, pair-packed into the 8 chunk slots the row's records own
(zero-token records draw nothing).  Untranslated / out-of-range ids keep the
original 8-token JP copy byte-for-byte.

Hook: the staging load + dead loop head @0x08133D68 (`ldr r5,[0x08133dd8]` +
`lsl r0,r4,#1`) becomes `bl cave`; the next instruction @0x08133D6C becomes
`b 0x08133d7e` so the copy loop's body (whose back-branch lands mid-bl) is never
re-entered.  At the hook r6 = item id, r3 = record name ptr; r2 (row counter),
r6, r7 (price table offset), r8 (disable flag) must survive — the cave touches
only r0/r1/r3/r4/r5, all dead after the loop.
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

import rom_layout as rommap  # noqa: E402

HOOK = 0x08133D68
HOOK_OLD = bytes.fromhex("1b4d6000")     # ldr r5,[0x08133dd8] ; lsl r0,r4,#1
SKIP = 0x08133D6C
SKIP_OLD = bytes.fromhex("4019")         # add r0,r0,r5 (dead copy-loop body)
SKIP_NEW = bytes.fromhex("07e0")         # b 0x08133d7e (past the dead loop)

STAGING = 0x0203DB08                     # = DAT_08133dd8 (8-token row staging)

# entry (bl from hook): r6 = item id, r3 = JP name ptr.
CAVE_ASM = """
    ldr  r5, [pc, #0]      /* STAGING */
    ldr  r0, [pc, #0]      /* ITEM_TABLE */
    ldr  r1, [pc, #0]      /* ITEM_COUNT */
    cmp  r6, r1
    bcs  s_jp
    lsls r4, r6, #2
    ldr  r0, [r0, r4]      /* pooled EN name ptr, or 0 */
    cmp  r0, #0
    beq  s_jp
    movs r0, #0xF0
    lsls r0, r0, #8        /* 0xF000 */
    orrs r0, r6            /* marker = 0xF000 | id */
    strh r0, [r5, #0]
    movs r0, #0
    strh r0, [r5, #2]
    strh r0, [r5, #4]
    strh r0, [r5, #6]
    strh r0, [r5, #8]
    strh r0, [r5, #10]
    strh r0, [r5, #12]
    strh r0, [r5, #14]
    bx   lr
s_jp:
    movs r4, #0
s_loop:
    ldrh r0, [r3]
    lsls r1, r4, #1
    adds r1, r1, r5
    strh r0, [r1, #0]
    adds r3, #2
    adds r4, #1
    cmp  r4, #7
    bls  s_loop
    bx   lr
"""

LITERALS = [STAGING, rommap.ITEM_TABLE, rommap.ITEM_COUNT]


def apply(p):
    cave = p.cave_asm(CAVE_ASM, LITERALS, name="shopname")
    p.bl(HOOK, cave, HOOK_OLD, name="shopname marker")
    p.patch(SKIP, SKIP_OLD, SKIP_NEW, name="shopname skip dead copy loop")
    print(f"shopname: marker cave @0x{cave:08X} (staging 0x{STAGING:08X})")
