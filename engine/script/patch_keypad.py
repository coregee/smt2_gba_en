#!/usr/bin/env python3
"""Passcode number-pad keypad ("Enter the code:") VRAM-collision fix (patch_keypad).

The keypad door (Door_KeypadInitInputState 0x080d5324; display object class 0x084f4054, handler
0x080d4df4) draws its prompt and the entered digits on ONE OBJ-text line (Y=89):

  * the PROMPT  via Text_DrawSpriteString  -> the EN build reroutes this through the strip renderer
    (cave_runtext / cave_strip.h), which floats the line at OBJ-cache row floorRow = (used+15)>>4;
  * the DIGITS  via raw Font_DrawGlyphSprite -> the STOCK per-glyph cache, the one text path that
    bypasses the strip; it fills cells bottom-up from cell 0.

Both share the OBJ glyph-cache block (base tile 0x180).  The keypad draws the prompt while the
cache is still empty (used count 0) so floorRow = 0 and the prompt strip lands in row 0; the digit
loop then caches into row 0 too and its tiles OVERWRITE the prompt's strip tiles -> the prompt
positions render the digit glyphs (the user-reported "the entered code is drawn on top of 'Enter
the code:'"; the digits also draw correctly at their own x).  This is exactly the strip's own
documented hazard (cave_runtext.c: "the per-glyph path's engine-cache growth collided with the
strip cells").

Fix: replace the keypad's Font_ResetGlyphSpriteCache(0x180) call (0x080d4e00) with a cave that does
the same reset and then PRE-WARMS the cache with the 10 digit glyphs ('0'..'9' = 0xCC..0xD5).  The
used count is 10 before any strip draws this frame, so the prompt's floorRow becomes 1 and the strip
puts it in row 1; row 0 is left to the digit cells, which the keypad's digit loop then REUSES
(already cached).  No row is shared -> no VRAM collision.  Digits keep their fixed-pitch positions,
the prompt stays VWF, and both the input phase (digits @x=124) and post-confirm phase (@x=76) are
covered because the reset runs once at the top of the handler each frame.

Run AFTER patch_spritebuf (the cave_runtext strip hook on Text_DrawSpriteString must be installed).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from pathlib import Path

SRC = Path(__file__).resolve().parent / "cave_keypad.c"

# keypad display handler 0x080d4df4: `movs r0,#0xc0; lsls r0,#1; bl Font_ResetGlyphSpriteCache`.
RESET_SITE = 0x080D4E00
RESET_OLD = bytes.fromhex("c0204000d7f774f9")


def apply(p):
    p.cave_c(SRC, name="keypad")
    fn = p.cave_c_syms["cave_entry"]
    p.bl(RESET_SITE, fn, RESET_OLD, name="keypad reset+digit-precache")
    print("keypad: reset+precache cave installed (prompt strip -> row 1; digits keep row 0)")
