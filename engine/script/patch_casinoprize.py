#!/usr/bin/env python3
"""Casino minigame PRIZE box item name -> English VWF (Code Breaker = the casino template).

The minigames draw the prize you're playing for from a per-game INLINE Japanese name table (not the
item record), so the PRIZE box showed Japanese (user report: Code Breaker "PRIZE: め組の纏").  Code
Breaker's prize-name draw is FUN_0814c318 (sole caller FUN_0814af14 @0x0814b008), which reads the
prize ITEM ID from the prize-id table and -- when not at max quantity -- draws the inline JP name.

cave_casinoprize.c reimplements FUN_0814c318: the at-max label path is kept verbatim, but the prize
NAME is drawn from ITEM_TABLE[prizeId] (English, VWF, centered) with a JP fallback for untranslated
ids.  We repoint the `bl FUN_0814c318` @0x0814b008.  See cave_casinoprize.c for the other minigames'
roll-out (same prize-id-table + inline-name pattern, per-game update functions).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

from pathlib import Path
from engine.script.cave_asm import thumb_bl

SRC = Path(__file__).resolve().parent / "cave_casinoprize.c"
HOOK = 0x0814B008          # `bl FUN_0814c318` in FUN_0814af14 (Code Breaker per-frame update)
ORIG = 0x0814C318          # FUN_0814c318 (the stock prize-name draw)

# Big & Small (group 0) prize-name draws FUN_0814a8b0: its two `bl FUN_0814adac` calls -> cave_bsname.
BS_DRAWSTR = 0x0814ADAC    # FUN_0814adac (the stock glyph-string drawer both sites call)
BS_SITES = [0x0814A93A, 0x0814A98C]   # state 2/7 branch, else branch


def apply(p):
    p.cave_c(SRC, name="casinoprize")
    cave = p.cave_c_syms["cave_cbprize"]
    p.bl(HOOK, cave, thumb_bl(HOOK, ORIG).hex(), name="casinoprize-cb")
    bs = p.cave_c_syms["cave_bsname"]
    for site in BS_SITES:
        p.bl(site, bs, thumb_bl(site, BS_DRAWSTR).hex(), name="casinoprize-bs")
    print(f"casinoprize: Code Breaker prize @0x{cave:08X}, Big&Small prize @0x{bs:08X} -> EN ITEM_TABLE VWF")
