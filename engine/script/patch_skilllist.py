#!/usr/bin/env python3
"""List-row name drawers FUN_081272cc + FUN_08127394 — VWF + full-length names for EVERY list menu.

These twin row drawers render each list row's name with Font_DrawGlyphTinted into the IWRAM BG canvas
0x030000b4 at a FIXED 12px pitch, capped at 8 glyphs.  FUN_081272cc draws untinted (skill list, item-
use menu, party/ally list); FUN_08127394 is its tinted clone (COMP stock / fusion demon lists).  We
replace each with a VWF, full-length draw (engine/script/cave_skilllist.c) that also resolves long names:
  - skill names  -> the 0xFFFF repoint sentinel (+2 pool pointer), written by patch_names.
  - item/equip   -> ITEM_TABLE[id] (mapped from the inline pDisplayText pointer).
  - demon names  -> NAME_TABLE[id] (mapped from the demon record +0x22 name pointer).
Both caves live in one blob (cave_entry / cave_entry2); the patcher resolves each entry by symbol.

Hooks (both are `cmp r1,#4; bne ...`, bytes 04 29 3e d1 — same case-4 body size):
  FUN_081272cc @0x081272d6 -> cave_entry  (prologue: r5=name, r1=mode)
  FUN_08127394 @0x081273a2 -> cave_entry2 (prologue: r6=name, r1=mode, r5=tint)
Run AFTER patch_vwf.py (width table), patch_names.py (skill sentinels) and tr.py pack (NAME/ITEM tables).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

import rom_layout as rommap

SRC = Path(__file__).resolve().parent / "cave_skilllist.c"
B = rommap.ROM_BASE

HOOK = 0x081272D6          # FUN_081272cc dispatch `cmp r1,#4; bne 0x08127358`
HOOK_OLD = bytes.fromhex("04293ed1")
HOOK2 = 0x081273A2         # FUN_08127394 dispatch `cmp r1,#4; bne 0x08127424` (tinted sibling)
HOOK2_OLD = bytes.fromhex("04293ed1")
HOOK3 = 0x08154AB2         # Fusion_DrawCandidateRow pre-loop `mov r3,r10; add r3,#0x22` (resolve ptrs)
HOOK3_OLD = bytes.fromhex("53462233")
HOOK4 = 0x08154AE4         # Fusion_DrawCandidateRow name-loop head `mov r4,#0; ldr r1,[sp,#0x2c]` (VWF)
HOOK4_OLD = bytes.fromhex("00240b99")
HOOK5 = 0x0815480C         # FUN_081547d8 name-loop head `mov r4,#0; add r1,r5,#0` (result VWF)
HOOK5_OLD = bytes.fromhex("0024291c")
HOOK6 = 0x08155A4C         # Fusion_DrawMaterialHeader `mov r1,r9; add r1,#0x22` (redirect header name)
HOOK6_OLD = bytes.fromhex("49462231")
HOOK7 = 0x08155AF2         # Fusion_DrawMaterialHeader `movs r7,#0xc0; lsl r7,#0xc` (header name VWF advance)
HOOK7_OLD = bytes.fromhex("c0273f03")
CAP   = 0x08155AFE         # Fusion_DrawMaterialHeader name `cmp r1,#7` -> #0x13: raise the 8-glyph cap
CAP_OLD = bytes.fromhex("0729")     # NUL terminator still stops the loop at the real name length
HOOK8 = 0x08155A52         # Fusion_DrawMaterialHeader `mov r2,r10; lsl r5,r2,#0x10` (header race VWF)
HOOK8_OLD = bytes.fromhex("52461504")
HOOK9 = 0x081569CE         # Compendium demon-name setup `mov r9,r0; movs r5,#0` -> NAME_TABLE redirect
HOOK9_OLD = bytes.fromhex("81460025")
HOOK10 = 0x08156A28        # Compendium demon-name draw body (seen+unseen converge) -> wide strips
HOOK10_OLD = bytes.fromhex("6b004946")
HOOK11 = 0x08156838        # Compendium race glyph loop body -> VWF the race name (per-glyph, in cache)
HOOK11_OLD = bytes.fromhex("6300d819")
# Compendium RACE/NAME/LEVEL labels: route the 3 Text_DrawSpriteString calls through the glyph cache
# (label_str_vwf) instead of cave_runtext strips, so they survive a status-screen round-trip uncorrupted.
LBL = ((0x0815675A, "55f7ebfd"), (0x0815676C, "55f7e2fd"), (0x0815677E, "55f7d9fd"))
HOOK12 = 0x081568BC        # Compendium LEVEL-filter category draw -> English "Lv.." via glyph cache
HOOK12_OLD = bytes.fromhex("55f73afd")
# Compendium NAME-category draw (ex-kana ア行..ワ行; table COMP_NAME_LABELS repointed to the EN
# letter-bucket labels by patch_dictsort).  Same 0x80ac334 convention as the headers -> route
# through label_str_vwf for VWF English, matching the race/level categories.
HOOK_NAMECAT = 0x08156888
HOOK_NAMECAT_OLD = bytes.fromhex("55f754fd")
HOOK13 = 0x080F388E        # Battle Analyze skill-name loop (FUN_080f3850) -> sentinel-resolve + VWF English
HOOK13_OLD = bytes.fromhex("30880236")
RACE_REDIR = 0x080F3BF2    # Analyze race draw: redirect its JP race-name getter to the English one
RACE_REDIR_OLD = bytes.fromhex("f6f701ff")   # bl FUN_080ea9f8 -> bl Race_GetNamePtr
HOOK14 = 0x080F3BF6        # Analyze race name loop -> VWF (English from RACE_REDIR)
HOOK14_OLD = bytes.fromhex("041c0025")
HOOK15 = 0x080F3B44        # Analyze f30 affinity row -> sentinel-resolve + VWF
HOOK15_OLD = bytes.fromhex("20880234")
HOOK16 = 0x080F3B70        # Analyze pad affinity row -> sentinel-resolve + VWF
HOOK16_OLD = bytes.fromhex("20880234")
HOOK17 = 0x080F3BC8        # Analyze drop-item name -> ITEM_TABLE + VWF
HOOK17_OLD = bytes.fromhex("20880234")
HOOK18 = 0x080F3D16        # Battle top-bar enemy name (FUN_080f3c4c) -> NAME_TABLE English
HOOK18_OLD = bytes.fromhex("b8f70dfb")   # bl Text_DrawSpriteString
HOOK19 = 0x08128A44        # Field COMP demon-list panel RACE (Menu_DrawLabeledName) -> VWF
HOOK19_OLD = bytes.fromhex("00260025")   # mov r6,#0; mov r5,#0 (count/draw-loop setup we skip)
HOOK20 = 0x08155AE8        # Fusion_DrawMaterialHeader SWORD (race-0x2c) name advance -> VWF (completes HOOK7)
HOOK20_OLD = bytes.fromhex("069a0c32")   # ldr r2,[sp,#0x18]; adds r2,#0xc  (hardcoded sword-path pitch)
HOOK21 = 0x0812A464        # COMP demon-info BIG selected-demon name (loop after Combatant_GetRecord) -> NAME_TABLE VWF
HOOK21_OLD = bytes.fromhex("0024011c")   # movs r4,#0; adds r1,r0,#0 (cap-8 name-loop setup we replace)
HOOK22 = 0x080D2CBE        # Menu_DrawSkillRowTriple 3-up DEMON-name inner loop -> NAME_TABLE VWF (demon twin of cave_menuitemname)
HOOK22_OLD = bytes.fromhex("00246e1c")   # movs r4,#0; adds r6,r5,#1 (cap-8 demon-name loop setup we replace)
HOOK23 = 0x080D2F20        # FUN_080d2f04 two-demon compare-panel name drawer (loop after GetRecord) -> NAME_TABLE VWF
HOOK23_OLD = bytes.fromhex("0026011c")   # movs r6,#0; adds r1,r0,#0 (cap-8 name-loop setup we replace)


def apply(p):
    p.cave_c(SRC, name="skilllist")
    p.bl(HOOK, p.cave_c_syms["cave_entry"], HOOK_OLD)
    p.bl(HOOK2, p.cave_c_syms["cave_entry2"], HOOK2_OLD)
    p.bl(HOOK3, p.cave_c_syms["cave_entry3"], HOOK3_OLD)
    p.bl(HOOK4, p.cave_c_syms["cave_entry4"], HOOK4_OLD)
    p.bl(HOOK5, p.cave_c_syms["cave_entry5"], HOOK5_OLD)
    p.bl(HOOK6, p.cave_c_syms["cave_entry6"], HOOK6_OLD)
    p.bl(HOOK7, p.cave_c_syms["cave_entry7"], HOOK7_OLD)
    p.bl(HOOK8, p.cave_c_syms["cave_entry8"], HOOK8_OLD)
    p.bl(HOOK9, p.cave_c_syms["cave_entry9"], HOOK9_OLD)
    p.bl(HOOK10, p.cave_c_syms["cave_entry10"], HOOK10_OLD)
    p.bl(HOOK11, p.cave_c_syms["cave_entry11"], HOOK11_OLD)
    for addr, old in LBL:
        p.bl(addr, p.cave_c_syms["label_str_vwf"], bytes.fromhex(old))
    p.bl(HOOK12, p.cave_c_syms["comp_level_vwf"], HOOK12_OLD)
    p.bl(HOOK_NAMECAT, p.cave_c_syms["label_str_vwf"], HOOK_NAMECAT_OLD)  # NAME categories -> EN VWF
    p.bl(HOOK13, p.cave_c_syms["cave_entry13"], HOOK13_OLD)
    p.bl(RACE_REDIR, rommap.Race_GetNamePtr, RACE_REDIR_OLD)   # Analyze race -> English name getter
    p.bl(HOOK14, p.cave_c_syms["cave_entry14"], HOOK14_OLD)
    p.bl(HOOK15, p.cave_c_syms["cave_entry15"], HOOK15_OLD)
    p.bl(HOOK16, p.cave_c_syms["cave_entry16"], HOOK16_OLD)
    p.bl(HOOK17, p.cave_c_syms["cave_entry17"], HOOK17_OLD)
    p.bl(HOOK18, p.cave_c_syms["cave_entry18"], HOOK18_OLD)
    p.bl(HOOK19, p.cave_c_syms["cave_entry19"], HOOK19_OLD)   # Field COMP panel race -> VWF
    p.bl(HOOK20, p.cave_c_syms["cave_entry20"], HOOK20_OLD)   # Fusion material-header sword name -> VWF
    p.bl(HOOK21, p.cave_c_syms["cave_compname"], HOOK21_OLD)  # COMP big selected-demon name -> NAME_TABLE VWF
    p.bl(HOOK22, p.cave_c_syms["cave_tripledemon"], HOOK22_OLD)  # 3-up demon-name row -> NAME_TABLE VWF
    p.bl(HOOK23, p.cave_c_syms["cave_comparedemon"], HOOK23_OLD)  # two-demon compare panel name -> NAME_TABLE VWF
    p.patch(CAP, CAP_OLD, bytes.fromhex("1329"), name="hdr-namecap")   # cmp r1,#0x13
