#!/usr/bin/env python3
"""Negotiation item/gem-OFFER list names -> pooled English (patch_offerlist).

When a demon demands a gem in negotiation, `FUN_0813becc` fills a RAM id list with the
12 gem ids (0x120..0x12B) and calls the list drawer `FUN_08133f14` ("Which gem will you
offer?").  Per row the drawer reads the item record's pDisplayText (`Item_GetRecord32(id)
+0xC`) and copies EXACTLY 8 tokens into the staging buffer 0x0203DB08, then
`FUN_08133e70(0x27, y, 0, 8)` appends them as 8 glyph records to g_MsgGlyphList (rendered
by cave_msgwin); the "xN" owned count comes from `Inventory_GetStoredQuantity`.

Because the records hold the inline JP name (English over the 7-glyph in-record budget
never fit the slots), gems whose English name is >7 glyphs drew JP (Amethyst/Aquamarine/
Sapphire/Turquoise) while short ones drew English (tr.pack's in-place inline write made the
record itself English) -- and the fixed-8 copy over-read short JP names into the next
record (the "アクアマ( 1" garble).  The English names already live in ITEM_TABLE (filled
for every id by tr.pack's item_table guard); this drawer just wasn't reading them.

Fix = the patch_shopname / patch_exchangelist marker on the message-window substrate: the
copy loop is replaced by a cave that writes ONE marker token 0xF000|itemId (+7 zero tokens)
into the staging buffer when ITEM_TABLE[itemId] holds a pooled English name; cave_msgwin's
render_list expands the 0xF000|id marker to the full VWF name at the row anchor (same
ITEM_TABLE path the shop list already uses).  Untranslated / out-of-range ids keep the
original 8-token JP copy byte-for-byte.

Hook: the staging load + loop head @0x0813400E (`ldr r4,[=staging]; lsl r0,r2,#1`) becomes
`bl cave`; @0x08134012 (`add r0,r0,r4`) becomes `b 0x08134024` (past the dead copy loop).
At the hook the item id is the function local at [sp,#0x4] and r3 = the JP record name ptr;
r5 (name-x table base) and r6 (row*2) are live after the loop and the cave leaves them
untouched (it uses only r0/r1/r2/r3/r4, all dead/reloaded after the loop).  Run AFTER
patch_msgwin (the renderer that expands the marker).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

import rom_layout as rommap  # noqa: E402

HOOK = 0x0813400E
HOOK_OLD = bytes.fromhex("5a4c5000")     # ldr r4,[0x08134178] ; lsl r0,r2,#1
SKIP = 0x08134012
SKIP_OLD = bytes.fromhex("0019")         # add r0,r0,r4 (dead copy-loop body)
SKIP_NEW = bytes.fromhex("07e0")         # b 0x08134024 (past the dead loop)

STAGING = 0x0203DB08                     # = DAT_08134178 (8-token row staging -> g_MsgGlyphList)

# entry (bl from hook): item id at [sp,#0x4] (function local), r3 = JP record name ptr.
# Marker cave (cf. patch_shopname): write 0xF000|id when ITEM_TABLE[id] is pooled, else copy the
# 8 JP tokens; cave_msgwin's render_list expands the 0xF000|id marker to the full VWF name.
CAVE_ASM = """
    ldr  r4, [pc, #0]      /* STAGING */
    ldr  r2, [sp, #4]      /* itemId (function local) */
    ldr  r0, [pc, #0]      /* ITEM_TABLE */
    ldr  r1, [pc, #0]      /* ITEM_COUNT */
    cmp  r2, r1
    bcs  o_jp
    lsls r1, r2, #2
    ldr  r0, [r0, r1]      /* pooled EN name ptr, or 0 */
    cmp  r0, #0
    beq  o_jp
    movs r0, #0xF0
    lsls r0, r0, #8        /* 0xF000 */
    orrs r0, r2            /* marker = 0xF000 | id */
    strh r0, [r4, #0]
    movs r0, #0
    strh r0, [r4, #2]
    strh r0, [r4, #4]
    strh r0, [r4, #6]
    strh r0, [r4, #8]
    strh r0, [r4, #10]
    strh r0, [r4, #12]
    strh r0, [r4, #14]
    bx   lr
o_jp:
    movs r2, #0
o_loop:
    ldrh r0, [r3]
    lsls r1, r2, #1
    adds r1, r1, r4
    strh r0, [r1, #0]
    adds r3, #2
    adds r2, #1
    cmp  r2, #7
    bls  o_loop
    bx   lr
"""

LITERALS = [STAGING, rommap.ITEM_TABLE, rommap.ITEM_COUNT]


def apply(p):
    cave = p.cave_asm(CAVE_ASM, LITERALS, name="offerlist")
    p.bl(HOOK, cave, HOOK_OLD, name="offerlist marker")
    p.patch(SKIP, SKIP_OLD, SKIP_NEW, name="offerlist skip dead copy loop")
    print(f"offerlist: marker cave @0x{cave:08X} (staging 0x{STAGING:08X})")
