#!/usr/bin/env python3
"""Status-screen *item/gem* drop name repoint + VWF (FUN_080cd1a0) — the >= 0xD0 sibling of patch_drop.

The demon status drop drawer `FUN_080cba7c` branches on the drop id: equipment (< 0xD0) goes to
`FUN_080cd100` (hooked by patch_drop.py), but items/gems (id >= 0xD0, masked `& 0x1FF`) go to a
SEPARATE drawer `FUN_080cd1a0` that patch_drop never touched — so gem drops (Emerald = item 0x122,
etc.) still drew fixed-width 8-glyph from `ItemRecord32->pDisplayText` (+0x0C) while every other
name field had gone VWF. `FUN_080cd1a0` receives the full item id (Item_GetRecord32 needs it), so the
same `ITEM_TABLE[id]` lookup tr.py already fills (equipment + items, ids 0x00-0x14F) resolves it.

This cave mirrors patch_drop: replace `bl Item_GetRecord32` @0x080cd1ba (itemId still in r0) with a
bl to the cave. If `ITEM_TABLE[id]` is a pooled name, draw it VWF (tint kept) and jump to the
epilogue @0x080cd1e8; otherwise re-issue the record fetch and continue at @0x080cd1be unchanged
(untranslated / out-of-range ids stay byte-for-byte original). Run AFTER patch_vwf.py.
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from engine.script import rommap
from engine.script.cave_builders import idtable_vwf_cave

B = rommap.ROM_BASE

HOOK = 0x080CD1BA          # `bl Item_GetRecord32` (itemId in r0)
HOOK_OLD = bytes.fromhex("f2f72df9")
ITEM_TABLE = rommap.ITEM_TABLE
ITEM_COUNT = rommap.ITEM_COUNT   # id >= this -> original path
BUF = rommap.STATUS_TEXT_BUF     # status text buffer (DAT_080cd1f4)
WIDTH_TBL = rommap.WIDTH_TABLE
EPI = 0x080CD1E8 | 1       # function epilogue (Thumb)
CONT = 0x080CD1BE | 1      # original path: instruction after the replaced bl (Thumb)

# entry (bl from hook): r0=itemId, r5=X, r8=Y, r6=tint; frame has [sp,#0] free (5th arg slot).
def apply(p):
    # id->ITEM_TABLE VWF draw-loop via the shared builder (byte-identical to the former hand-asm).
    # The OOB guard matters here: item/gem ids run past the table, unlike patch_drop's equipment.
    idtable_vwf_cave(
        p, name="itemdrop", hook=HOOK, hook_old=HOOK_OLD,
        table=ITEM_TABLE, bounds=ITEM_COUNT,                 # id >= count -> original (no OOB read)
        drawer=rommap.Font_DrawGlyphTinted, getter=rommap.Item_GetRecord32,
        buf=BUF, width=WIDTH_TBL, epilogue=EPI, cont=CONT,
        id_reg="r0", x_reg="r5", y_reg="r8", ptr_reg="r4", tint_reg="r6", xadd="adds",
    )
