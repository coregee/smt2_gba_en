#!/usr/bin/env python3
"""DDS demon-dictionary names -> pooled English VWF (patch_dictname).

The DDS terminal's "demon dictionary" (a compendium look-alike, separate code from the in-game
compendium) draws demon names GLYPH-BY-GLYPH via FontSprite_DrawGlyph (the OBJ glyph cache), fixed
0xc pitch, cap-8 -- so English never fit and never VWF'd.

Routing the name through cave_runtext STRIPS corrupted the screen (the dictionary is glyph-cache
heavy, so strips collide with the cache -- the same problem the compendium hit).  So the fix stays
on the glyph-cache substrate: cave_dictname.c replaces the per-glyph loop with a VARIABLE-width loop
using the SAME drawer (FontSprite_DrawGlyph), pulling the pooled English name from NAME_TABLE[species]
(JP fallback when untranslated/unseen).

This handles the DETAIL-panel name first (drawer @0x080db938; selected species [state 0x020399e0
+0x38], drawn at (0x7e,7)):
  hook @0x080db960 (`movs r4,#0; ldrh r0,[r5]`) -> bl cave_entry veneer
  skip @0x080db964 (`cmp r0,#0`)                 -> b 0x080db998 (past the dead per-glyph loop)
  at the hook r5 = JP name ptr (live).

The dictionary has THREE filter-mode SELECTOR columns (fn-ptr records 0x10c apart: race
@0x085835dc, kana @0x085836e8, level @0x085837f4), each drawn glyph-by-glyph at x=0x54, fixed
0xc, in the same per-row loop pattern as the names:
  - RACE column  (drawer @0x080dbe9c): Race_GetName(id) cells @g_wRaceNameTable 0x081a5c34 --
    names_race already wrote ENGLISH there (inline glyph tokens for short names, 0xFFFF+pool ptr
    for the 3 long ones: Demonoid/Shinshou/...).  cave_entry4 -> dict_race_vwf VWFs both.
  - LEVEL-RANGE column (drawer @0x080dc1d8): comp_levelrange slots @0x08583788 -> "Lv1-9".."Lv100"
    (8-glyph cells, space-padded, no terminator).  cave_entry5 -> dict_str_vwf VWFs, stops at pad.
  - NAME column (drawer @0x080dc0f0, ex-kana ア行..その他): REPURPOSED into EN alphabetical letter
    buckets by patch_dictsort (relabels table 0x0858367c, regenerates the sort table 0x08585c34).
    cave_entry5 (dict_str_vwf) VWFs the relabelled bucket strings -- same hook shape as level.

NOTE: the scrollable demon LIST (drawer @0x080dbd38, per-row at x=0x5c, species = stock[row]&0x7FFF)
is the same per-glyph pattern -- the next site to convert with dict_name_vwf.

Run AFTER patch_vwf (needs the width table).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

SRC = Path(__file__).resolve().parent / "cave_dictname.c"
SRC_INFO = Path(__file__).resolve().parent / "cave_dictinfo.c"   # full-info detail screen (separate blob)

# detail-panel name (drawn once at x=0x7e, y=7)
HOOK = 0x080DB960
HOOK_OLD = bytes.fromhex("00242888")     # movs r4,#0 ; ldrh r0,[r5]
SKIP = 0x080DB964
SKIP_OLD = bytes.fromhex("0028")         # cmp r0,#0
SKIP_NEW = bytes.fromhex("18e0")         # b 0x080db998 (past the dead per-glyph loop)

# scrollable demon LIST (per row, x=0x5c)
LIST_HOOK = 0x080DBD86
LIST_HOOK_OLD = bytes.fromhex("00266800")  # movs r6,#0 ; lsls r0,r5,#1
LIST_SKIP = 0x080DBD8A
LIST_SKIP_OLD = bytes.fromhex("6a1c")      # adds r2,r5,#1
LIST_SKIP_NEW = bytes.fromhex("16e0")      # b 0x080dbdba (next-row continuation, past the loop)

# race/level-SORTED list (per row, x=0x54; name ptr = combatant record+0x22)
SORT_HOOK = 0x080DC364
SORT_HOOK_OLD = bytes.fromhex("44468021")  # mov r4,r8 ; movs r1,#0x80
SORT_SKIP = 0x080DC368
SORT_SKIP_OLD = bytes.fromhex("0902")      # lsls r1,r1,#8
SORT_SKIP_NEW = bytes.fromhex("21e0")      # b 0x080dc3ae (next-row continuation, past the loop)

# FULL-INFO detail screen demon name (RacePanel 0x080dc6d0; BG-canvas Font_DrawGlyphTinted loop,
# NOT the OBJ glyph cache the columns use).  Hook the loop-init (movs r5,#0 ; movs r0,#0xb0),
# cave draws VWF EN then branches past the dead per-glyph loop to the alignment-label draw.
INFO_HOOK = 0x080DC776
INFO_HOOK_OLD = bytes.fromhex("0025b020")   # movs r5,#0 ; movs r0,#0xb0

# FULL-INFO detail screen PARENT RACE (RacePanel field A; ParentRace_GetName cell, drawn fixed-pitch
# by Text_DrawStringTinted).  Hook the cell-ptr setup (adds r0,r1,#0 ; mov r1,sl), cave VWF-draws the
# pooled English (patch_parentrace) then branches past the dead JP draw to the merge point.
PARENT_HOOK = 0x080DC744
PARENT_HOOK_OLD = bytes.fromhex("081c5146")  # adds r0,r1,#0 ; mov r1,sl

# RACE filter-category column (drawer @0x080dbe9c; per row, x=0x54; cell = Race_GetName result in r4)
RACE_HOOK = 0x080DBF10
RACE_HOOK_OLD = bytes.fromhex("20882b0c")  # ldrh r0,[r4] ; lsrs r3,r5,#0x10
RACE_SKIP = 0x080DBF14
RACE_SKIP_OLD = bytes.fromhex("0097")      # str r7,[sp]
RACE_SKIP_NEW = bytes.fromhex("0ae0")      # b 0x080dbf2c (next-row continuation, past the loop)

# LEVEL-RANGE filter-category column (drawer @0x080dc1d8; per row, x=0x54; label ptr in r4)
LVL_HOOK = 0x080DC23E
LVL_HOOK_OLD = bytes.fromhex("20882b0c")  # ldrh r0,[r4] ; lsrs r3,r5,#0x10
LVL_SKIP = 0x080DC242
LVL_SKIP_OLD = bytes.fromhex("0097")      # str r7,[sp]
LVL_SKIP_NEW = bytes.fromhex("0ae0")      # b 0x080dc25a (next-row continuation, past the loop)

# NAME filter-category column (drawer @0x080dc0f0; ex-kana selector, relabelled to EN letter
# buckets by patch_dictsort; per row, x=0x54, label ptr in r4).  Reuses cave_entry5 (dict_str_vwf).
NAME_HOOK = 0x080DC15C
NAME_HOOK_OLD = bytes.fromhex("20882b0c")  # ldrh r0,[r4] ; lsrs r3,r5,#0x10
NAME_SKIP = 0x080DC160
NAME_SKIP_OLD = bytes.fromhex("0097")      # str r7,[sp]
NAME_SKIP_NEW = bytes.fromhex("0de0")      # b 0x080dc17e (next-row continuation, past the loop)


def apply(p):
    p.cave_c(SRC, name="dictname")
    sy = p.cave_c_syms
    p.bl(HOOK, sy["cave_entry"], HOOK_OLD, name="dictname detail veneer")
    p.patch(SKIP, SKIP_OLD, SKIP_NEW, name="dictname detail skip per-glyph loop")
    p.bl(LIST_HOOK, sy["cave_entry2"], LIST_HOOK_OLD, name="dictname list veneer")
    p.patch(LIST_SKIP, LIST_SKIP_OLD, LIST_SKIP_NEW, name="dictname list skip per-glyph loop")
    p.bl(SORT_HOOK, sy["cave_entry3"], SORT_HOOK_OLD, name="dictname sorted-list veneer")
    p.patch(SORT_SKIP, SORT_SKIP_OLD, SORT_SKIP_NEW, name="dictname sorted skip per-glyph loop")
    p.bl(RACE_HOOK, sy["cave_entry4"], RACE_HOOK_OLD, name="dictname race-column veneer")
    p.patch(RACE_SKIP, RACE_SKIP_OLD, RACE_SKIP_NEW, name="dictname race skip per-glyph loop")
    p.bl(LVL_HOOK, sy["cave_entry5"], LVL_HOOK_OLD, name="dictname level-range veneer")
    p.patch(LVL_SKIP, LVL_SKIP_OLD, LVL_SKIP_NEW, name="dictname level-range skip per-glyph loop")
    p.bl(NAME_HOOK, sy["cave_entry5"], NAME_HOOK_OLD, name="dictname name-bucket veneer")
    p.patch(NAME_SKIP, NAME_SKIP_OLD, NAME_SKIP_NEW, name="dictname name-bucket skip per-glyph loop")
    p.cave_c(SRC_INFO, name="dictinfo")
    si = p.cave_c_syms
    p.bl(INFO_HOOK, si["cave_info_name"], INFO_HOOK_OLD, name="dictinfo full-info name veneer")
    p.bl(PARENT_HOOK, si["cave_info_parent"], PARENT_HOOK_OLD, name="dictinfo full-info parent-race veneer")
    print(f"dictname: detail @0x{sy['cave_entry']:08X}, list @0x{sy['cave_entry2']:08X}, "
          f"sorted @0x{sy['cave_entry3']:08X}, race @0x{sy['cave_entry4']:08X}, "
          f"level @0x{sy['cave_entry5']:08X}")
