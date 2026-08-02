#!/usr/bin/env python3
"""Item-detail 3-up name drawer -> English VWF (Menu_DrawItemNameTriple).

Menu_DrawItemNameTriple (via Item_RenderDescription) draws up to 3 item/equipment names glyph-by-glyph
via Font_DrawGlyphTinted at a fixed 0xc pitch, cap-8, from the JP record name -- so English never fit
and it drew Japanese.  cave_menuitemname.c replaces its inner cap-8 loop (0x080d2bfe..0x080d2c26) with
a veneer -> worker that draws ITEM_TABLE[id] variable-width (JP fallback), then branches PAST the dead
loop to 0x080d2c28, so only the name draw changes.

(The sibling demon held-item draw is already EN+VWF via patch_skilllist HOOK17.)
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

from pathlib import Path
from engine.script.cave_asm import thumb_bl

SRC = Path(__file__).resolve().parent / "cave_menuitemname.c"

A1_HOOK = 0x080D2BFE       # Menu_DrawItemNameTriple inner cap-8 loop -> bl veneer_triple + NOPs
A1_OLD  = "00246e1c6200d0190088121992004a441204120c002100910a494346d9f7b1fe601c0004040c072cecd9"


def apply(p):
    p.cave_c(SRC, name="menuitemname")
    cave = p.cave_c_syms["veneer_triple"]
    old = bytes.fromhex(A1_OLD)
    new = bytes.fromhex(thumb_bl(A1_HOOK, cave).hex()) + b"\xc0\x46" * ((len(old) - 4) // 2)
    p.patch(A1_HOOK, old, new, name="menuitem-triple")
    print(f"menuitemname: item-detail 3-up names -> EN ITEM_TABLE VWF, cave @0x{cave:08X}")
