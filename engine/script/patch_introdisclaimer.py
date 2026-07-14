#!/usr/bin/env python3
"""Boot fiction-disclaimer -> proportional English (cave_introdisclaimer.c).

The disclaimer "このゲームは　フィクションであり…" is drawn at boot by
Intro_DrawDisclaimer 0x080D67BC, a fixed-pitch 3-row (17/16/17 full-width glyphs) renderer
reached only via an intro cutscene STEP record whose fn-ptr lives at 0x08509EEC (-> 0x080D67BD).
Fixed-pitch + the 64-cell glyph-cache cap make English impossible in that renderer, so we
swap the step's fn-ptr to cave_introdisclaimer.intro_draw, which draws the pooled English
(the intro_disclaimer section repointed the renderer's string-ptr literal 0x080D6868 to it)
through Text_DrawSpriteString — the existing VWF strip path (cave_runtext / patch_spritebuf).

Depends on patch_spritebuf (the cave_runtext hook on Text_DrawSpriteString) being applied.
"""
import struct as _struct

try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from engine.script import rommap

# intro cutscene step record fn-ptr slot -> stock renderer 0x080D67BC (thumb 0x080D67BD)
FNPTR_SLOT = rommap.INTRO_DISCLAIMER_FNPTR        # 0x08509EEC
FNPTR_OLD = _struct.pack("<I", 0x080D67BC | 1).hex()   # "bd670d08"


def apply(p):
    p.cave_c(Path(__file__).resolve().parent / "cave_introdisclaimer.c", name="introdisc")
    fn = p.cave_c_syms["cave_entry"] | 1
    p.patch(FNPTR_SLOT, FNPTR_OLD, _struct.pack("<I", fn), name="introdisc-fnptr")
