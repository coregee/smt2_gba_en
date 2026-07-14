#!/usr/bin/env python3
"""Automap marker-list location names -> VWF strip path (cave_markerlist.c).

The marker-list screen (MarkerScreen_RenderObject 0x080b52e0, state 3) draws 4 slot rows.
Empty slots draw "(No data)" via Text_DrawSpriteString 0x080AC334 (already a packed VWF
strip via cave_runtext / patch_spritebuf).  Non-empty slots drew their LOCATION NAME via
MarkerList_DrawLocationName 0x080c8bfc, whose loop emitted each glyph through the lower
primitive 0x080ac218 (fixed 12px, feeding the SHARED glyph sprite cache directly).  Those
raw allocations raced the cave_runtext strips for cells/OAM in the same cache, so the rows
garbled and the longer English prompt corrupted the list.

Fix: replace the `bl @0x080b54f6` (call to MarkerList_DrawLocationName) with our cave,
which reproduces the coords->cell lookup, copies the cell's location tokens (<=16, stop at
the 0x57 '@' pad), and draws them through the SAME Text_DrawSpriteString the "(No data)"
row uses.  Every marker-screen text call then shares cave_runtext's coordinated VWF strip
packer: no cache collision, proportional location names, fewer OAM sprites.

Depends on patch_spritebuf (cave_runtext hook on Text_DrawSpriteString) being applied.
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

# Route EVERY marker-screen text draw through our position-keyed renderer so cell layout is
# stable (no cave_runtext bump = no flicker).  Orig bytes = drift guard.
#   0x080b52c8  adds r6,r0,#0; adds r7,r6,#0      -> cave_init  (cache invalidation + restore)
#   0x080b52f0  bl MarkerHeader_DrawLocationName  -> cave_entry (current-location header)
#   0x080b54f6  bl MarkerList_DrawLocationName    -> cave_loc   (placed-marker name row)
HOOK_INIT   = (0x080B52C8, "061c371c")
HOOK_HEADER = (0x080B52F0, "13f044fc")
HOOK_LOC    = (0x080B54F6, "13f081fb")
# every `bl Text_DrawSpriteString` in the handler (prompts / captions / "(No data)") -> cave_draw
# prompt/caption draws -> cave_draw (y-keyed: captions chunks 0-1, prompts chunk 2)
HOOK_DRAWS = [
    (0x080B530C, "f7f712f8"), (0x080B5340, "f6f7f8ff"), (0x080B53C4, "f6f7b6ff"),
    (0x080B53E4, "f6f7a6ff"), (0x080B5404, "f6f796ff"), (0x080B5424, "f6f786ff"),
    (0x080B5436, "f6f77dff"), (0x080B5454, "f6f76eff"), (0x080B5466, "f6f765ff"),
    (0x080B548C, "f6f752ff"),
]
# empty-slot "(No data)" -> cave_nodata (slot-floored, can't flash in the banner row)
HOOK_NODATA = (0x080B5518, "f6f70cff")
# The same header drawer (MarkerHeader_DrawLocationName 0x080c8b7c) also draws the automap /
# map-view LOCATION BANNER from three other sites — all with identical args (x=0x12, y=0x59).
# Route them through cave_entry too: the banner becomes VWF and lands in the SAME cells as
# the marker menu's header, so it's consistent and doesn't flicker on menu open/close.
HOOK_BANNER = [
    (0x080B4770, "14f004fa"), (0x080B4EF0, "13f044fe"), (0x080B5CF4, "12f042ff"),
]


def apply(p):
    p.cave_c(Path(__file__).resolve().parent / "cave_markerlist.c", name="markerlist")
    p.bl(HOOK_INIT[0],   p.cave_c_syms["cave_init"],  HOOK_INIT[1],   name="markerlist-init")
    p.bl(HOOK_HEADER[0], p.cave_c_syms["cave_entry"], HOOK_HEADER[1], name="markerlist-header")
    p.bl(HOOK_LOC[0],    p.cave_c_syms["cave_loc"],   HOOK_LOC[1],    name="markerlist-loc")
    for i, (addr, old) in enumerate(HOOK_DRAWS):
        p.bl(addr, p.cave_c_syms["cave_draw"], old, name=f"markerlist-draw{i}")
    p.bl(HOOK_NODATA[0], p.cave_c_syms["cave_nodata"], HOOK_NODATA[1], name="markerlist-nodata")
    for i, (addr, old) in enumerate(HOOK_BANNER):
        p.bl(addr, p.cave_c_syms["cave_entry"], old, name=f"markerlist-banner{i}")
