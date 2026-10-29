#!/usr/bin/env python3
"""Shop "quantity owned" header (SELECT in a shop) -> English (patch_shopowned).

Pressing SELECT on a shop's item list or "How many?" step shows a header in the message window:
13 glyph codes written from code, 選択中のアイテムの所持数, then the two-digit count of the
highlighted item (Shop_InitItemList 0x08133B18 mode != 0, and the toggle sub_081305D8).  The
translation only relocated the glyph list, so the header stayed Japanese, overlapped (the kanji
took the prompt's English x positions) and cut at the prompt's record count.  Confirmed on screen
(decomp/docs/translation-findings.md, "Confirmed on screen").

cave_shopowned.c replaces the four header writers / restorers: the show hooks write LABEL on
one 13px-step row (reflowed VWF by cave_msgwin) and raise the record count to 15; the restore
hooks put the prompt back.  Run AFTER patch_msgwin (relocated glyph list + renderer).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

import rom_layout as rommap
from text.script import tr

SRC = Path(__file__).resolve().parent / "cave_shopowned.c"

LABEL = "Owned: "               # + the two count digits ("Owned: 02"); at most 13 glyphs
NLABEL = 13

HOOKS = [   # (site, original bytes, veneer)
    (0x0813062E, "15481880", "owned_show_veneer1"),     # sub_081305D8: ldr r0,=0xBD9 ; strh r0,[r3]
    (0x08133B44, "17481080", "owned_show_veneer2"),     # Shop_InitItemList: ldr r0,=0xBD9 ; strh r0,[r2]
    (0x081305E6, "0022074c", "owned_restore_veneer1"),  # sub_081305D8: movs r2,#0 ; ldr r4,=list
    (0x08133BBC, "0025114b", "owned_restore_veneer2"),  # Shop_InitItemList: movs r5,#0 ; ldr r3,=list
]


def apply(p):
    label = tr.encode(LABEL)
    if len(label) > NLABEL * 2:
        raise SystemExit(f"patch_shopowned: {LABEL!r} exceeds {NLABEL} glyphs")
    label += b"\x00" * (NLABEL * 2 - len(label))         # 0 = blank slot
    p.data(label, at=rommap.FARDATA_SHOPOWNED, name="shop owned label")
    p.cave_c(SRC, name="shopowned")
    sy = p.cave_c_syms
    for site, old, veneer in HOOKS:
        p.bl(site, sy[veneer], old, name=f"shop owned {veneer}")
    print(f"shopowned: owned-count header -> {LABEL.strip()!r} (4 hooks)")
