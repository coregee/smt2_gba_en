#!/usr/bin/env python3
"""Elevator floor-select list -> Western VWF floor labels (patch_elevator).

The floor-button drawer FUN_080b9a4c (called twice from the floor-list renderer FUN_080b9ba4) builds
each row's label as Japanese building notation at a FIXED 12px pitch:
    above ground : <digits>階   ("２２階")
    basement     : 地下<digits>階 ("地下３階")
drawing the digits one glyph at a time at hardcoded X (0x9C/0xA8/...) and the 階 string via
Text_DrawSpriteString.  No VWF -> spaced-out full-width "２２階".

We hook the drawer at 0x080b9a70 (just after it has computed the row Y in r6 and the floor record in r5,
before the JP draw branches) -> cave_entry, which rebuilds the label as one ASCII string ("22F" above
ground, "B3F" basement) drawn ONCE via Text_DrawSpriteString.  All label glyphs are in the English VWF
range, so patch_spritebuf's Text_DrawSpriteString replacement packs them tight. The cave returns to the
stock epilogue @0x080b9b94 (the JP draw branches in between are now dead).

The drawer (and the 地下/階/digit literals) are referenced ONLY here (verified by a whole-ROM scan), so
nothing else is affected. Run after patch_spritebuf.
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

SRC = Path(__file__).resolve().parent / "cave_elevator.c"

HOOK = 0x080B9A70                          # movs r1,#6 ; ldrsh r0,[r5,r1]  (Y in r6, rec in r5)
HOOK_OLD = bytes.fromhex("0621685e")


def apply(p):
    p.cave_c(SRC, name="elevator")
    p.bl(HOOK, p.cave_c_syms["cave_entry"], HOOK_OLD)
    print("elevator: floor labels -> '<N>F' / 'B<N>F' (VWF via Text_DrawSpriteString)")
