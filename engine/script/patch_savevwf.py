#!/usr/bin/env python3
"""Location-name VWF + 16-token cap-lift (save/load screen AND in-game map banner).

The save/load (file-select) screen and the in-game location banner both draw the location-name
table @0x080A548C *fixed-pitch* and *offset-indexed* (cell = base + idx*0x20, 16 u16 tokens, '@'
0x57 pad, no terminator).  Two problems:

  (1) Fixed pitch (x += 0xc) reads gappy now that the English names are proportional.
  (2) The 16-token cap forces abbreviations ("Old Government Building 15F" = 27 tokens won't fit;
      the location_names section warn-skips anything over 16, so those cells fell back to Japanese).

VWF (1) is the original purpose of this module (cave_locvwf):  the three save-screen loops share a
byte-identical advance `adds r0,r6,#0 ; adds r0,#0xc ; lsls r0,#0x10 ; lsrs r6,r0,#0x10` with r4 at
the NEXT token and r6 = x — we `bl` it to cave_entry (sets r6 = (x+width)&0xffff from the VWF width
table for English glyphs, 0xc for JP) and NOP the lsls/lsrs.

Cap-lift (2) — chosen approach "wider 0x40 far-table + redirect" (docs/save-screen.md):  build a
parallel copy of all 530 cells at 0x40 stride (32 tokens, 0x57 pad) in far data
(rommap.FARDATA_LOCTABLE), then redirect the TWO index computations that feed all five drawers to it
and raise the four glyph caps 16/9 -> 31.  The old 0x20 table is left in place as a graceful fallback
(an unhooked reader degrades to today's 16-token behavior, never corrupts).  Index sites:

  * Location_GetNameCellFromCoords 0x080b968c — the shared coords->cell source for the save-screen
    location line (SaveScreen_DrawLocationName) AND both banner drawers (FUN_080c8b7c/FUN_080c8bfc).
    Its tail is `lsl r0,r0,#1 ; ldr r1,[cell1] ; add r0,r0,r1` (cell = innermost*2 + cell-1 base).
    -> `lsl r0,r0,#2` (innermost*4) + literal = far cell 1, giving the SAME logical cell N in the
    0x40 table.
  * SaveScreen_DrawFileSlot region loop 0x080d0594+ — `[save+0xa66]*0x20 + cell-513 base` (the 17
    world-map region names, cells 513+). -> `*0x40` + literal = far cell 513.

Banner VWF:  FUN_080c8bfc's advance is byte-identical to the save-screen sites (r6=x, +0xc) so it
reuses cave_entry; FUN_080c8b7c uses r5=x with a variable step r7, so it gets cave_entry_r5.  Without
this the long EN names would render fixed-pitch and run off the 240px banner.

Pure-data far-table write goes through p.data(at=) (the build pre-extends the ROM to 16 MB, so the
far region is writable).  Runs late in build_rom (after the big caves claim their spans);
patch_defaultnames hooks the adjacent Menu_DrawCombatantName8px @0x080d02ca (disjoint bytes).
"""
import json
import struct

try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path
from text.script import tr

CAVE_SRC = Path(__file__).with_name("cave_locvwf.c")

ADV_OLD = "301c0c30"          # adds r0,r6,#0 ; adds r0,#0xc  (the bl-replaced half)
LSL_LSR_OLD = "0004060c"      # lsls r0,r0,#0x10 ; lsrs r6,r0,#0x10  (NOPed)
TWO_NOPS = bytes.fromhex("c046c046")

# (advance addr, label) — the r6=x / +0xc sites that reuse cave_entry
SITES = [
    (0x080D03EA, "save loc-name VWF (#1 DrawLocationName)"),
    (0x080D0462, "save title VWF (#2 DrawTokenString)"),
    (0x080D05C6, "save region-name VWF (#3 DrawFileSlot)"),
    (0x080C8C52, "banner VWF (#5 FUN_080c8bfc)"),          # r6=x, +0xc — same shape
]

# ---- cap-lift: the wider 0x40 far-table --------------------------------------------------------
LOC_JSON   = tr.TR / "location_names.json"
LOC_BASE   = 0x080A548C
OLD_STRIDE = 0x20
PAD_TOK    = 0x0057           # '@' pad; every drawer's loop stops at 0x57
USABLE     = rommap.LOCTABLE_STRIDE // 2 - 1   # 31 tokens (leave >=1 pad so the loop stops cleanly)


def _build_far_table(p):
    """Encode every location_names cell into a 0x40-stride blob at rommap.FARDATA_LOCTABLE."""
    ncells, stride = rommap.LOCTABLE_CELLS, rommap.LOCTABLE_STRIDE
    cells = [bytearray(struct.pack("<H", PAD_TOK) * (stride // 2)) for _ in range(ncells)]
    for e in json.loads(LOC_JSON.read_text(encoding="utf-8")):
        rep = e.get("replace", "")
        if not rep:
            continue
        idx = (int(e["addr"], 16) - LOC_BASE) // OLD_STRIDE
        if not (0 <= idx < ncells):
            raise SystemExit(f"loc far-table: cell idx {idx} (addr {e['addr']}) out of range")
        toks = tr.encode(rep)                       # bytes of u16 glyph tokens
        if len(toks) > USABLE * 2:
            raise SystemExit(f"loc far-table: {e['addr']} {rep!r} = {len(toks)//2} tokens "
                             f"> {USABLE}-token cell")
        cells[idx][0:len(toks)] = toks              # rest stays 0x57 pad
    p.data(b"".join(cells), at=rommap.FARDATA_LOCTABLE, name="location far-table (0x40 cells)")


def apply(p):
    cave = p.cave_c(CAVE_SRC, name="locvwf")          # cave_entry / cave_entry_r5 @ blob
    for adv, label in SITES:
        p.bl(adv, p.cave_c_syms["cave_entry"], ADV_OLD, name=label)
        p.patch(adv + 4, LSL_LSR_OLD, TWO_NOPS, name=label + " (nop x-trunc)")

    # ---- cap-lift: build the wider table, redirect the readers, raise the caps ----
    _build_far_table(p)
    far = rommap.FARDATA_LOCTABLE
    st  = rommap.LOCTABLE_STRIDE

    # Location_GetNameCellFromCoords 0x080b968c: cell = innermost*2 + cell-1 base  ->  far 0x40 table
    p.patch(0x080B96E8, "4000", bytes.fromhex("8000"),
            name="loc coords: lsl #1 -> #2 (0x40 stride)")
    p.patch(0x080B970C, "ac540a08", struct.pack("<I", far + 1 * st),
            name="loc coords: base -> far cell 1")

    # SaveScreen_DrawFileSlot region loop 0x080d0594+: [save+0xa66]*0x20 + cell-513  -> far cell 513
    p.patch(0x080D059C, "4001", bytes.fromhex("8001"),
            name="loc region: lsl #5 -> #6 (0x40 stride)")
    p.patch(0x080D05B0, "ac940a08", struct.pack("<I", far + 513 * st),
            name="loc region: base -> far cell 513")
    p.patch(0x080D05D4, "082d", bytes.fromhex("1e2d"), name="loc region: cap 9 -> 31")

    # Raise the per-loop glyph caps (were sized to the old 16-token cells)
    p.patch(0x080D03F8, "0f2d", bytes.fromhex("1e2d"), name="loc save-name: cap 16 -> 31")
    p.patch(0x080C8BE2, "0f2e", bytes.fromhex("1e2e"), name="loc banner #1: cap 16 -> 31")
    p.patch(0x080C8C5C, "0f2d", bytes.fromhex("1e2d"), name="loc banner #2: cap 16 -> 31")

    # Banner VWF advance: #1 (FUN_080c8b7c) uses r5=x / variable step -> cave_entry_r5
    p.bl(0x080C8BDA, p.cave_c_syms["cave_entry_r5"], "e8190004050c", name="banner VWF (#4 FUN_080c8b7c)")
