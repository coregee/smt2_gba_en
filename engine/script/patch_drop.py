#!/usr/bin/env python3
"""Drop/equipment-name repoint + VWF (status screen, FUN_080cd100) via a parallel id->name table.

FUN_080cd100(itemId, X, Y, tint) is the status item-name drawer (drop item, equipped slots;
3 callers). It draws 8 fixed glyphs from the equipment record's pDisplayText (+0x14). That
field is shared with shop/inventory (other drawers), so we don't touch it. Instead tr.py pack
writes a parallel table equipment-id -> pooled-name pointer at ITEM_TABLE (after the demon-name
table), and this cave looks the item up by id and draws the pooled name variable-width if
present, else runs the original path unchanged (so untranslated/shop draws are intact).

We replace `bl Equipment_GetRecord36_MidRange` @0x080cd13c (itemId still in r0) with a bl to the
cave: override -> draw pooled VWF (tint kept) and jump to the epilogue @0x080cd190; otherwise
re-issue the record fetch and continue at @0x080cd140. Run AFTER patch_vwf.py.
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from engine.script import rommap
from engine.script.cave_builders import idtable_vwf_cave

B = rommap.ROM_BASE

HOOK = 0x080CD13C          # `bl Equipment_GetRecord36_MidRange` (itemId in r0)
HOOK_OLD = bytes.fromhex("f2f70af9")
ITEM_TABLE = rommap.ITEM_TABLE
BUF = rommap.STATUS_TEXT_BUF   # status text buffer (DAT_080cd19c)
WIDTH_TBL = rommap.WIDTH_TABLE
EPI = 0x080CD190 | 1       # function epilogue (Thumb)
CONT = 0x080CD140 | 1      # original path: instruction after the replaced bl (Thumb)

# entry (bl from hook): r0=itemId, r4=X, r7=Y, r6=tint; frame already has [sp,#0] free.
def apply(p):
    # id->ITEM_TABLE VWF draw-loop via the shared builder (byte-identical to the former hand-asm).
    idtable_vwf_cave(
        p, name="drop", hook=HOOK, hook_old=HOOK_OLD,
        table=ITEM_TABLE, bounds=None,                       # equipment ids dense -> no OOB guard
        drawer=rommap.Font_DrawGlyphTinted, getter=rommap.Equipment_GetRecord36_MidRange,
        buf=BUF, width=WIDTH_TBL, epilogue=EPI, cont=CONT,
        id_reg="r0", x_reg="r4", y_reg="r7", ptr_reg="r5", tint_reg="r6", xadd="add",
    )
