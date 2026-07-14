#!/usr/bin/env python3
""""素材補完" (Material/Visionary Completion) service -> English (patch_vision).

There are TWO item-list drawers for this service on different screens, both fixed: the DDS terminal
(Vision_DrawItemList 0x080dadf8, hooked below) and the NPC appraiser's list (drawer @0x080d37bc;
6 rows, no quantities, gray/normal eligibility via FUN_080c5b10 — hooked at LIST2_HOOK 0x080d3824 ->
cave_vision's vis2_list_veneer).  This NPC list was found via a BizHawk Lua link-register trace
(it draws フォトフレーム/Photo Frame id 0x12C+ from Item record+0xc, glyph-by-glyph fixed-pitch).

Two JP spots on the DDS terminal service screen:

  (1) the ITEM LIST (Vision_DrawItemList 0x080dadf8): each row's name is drawn glyph-by-glyph via
      FontSprite_DrawGlyph from Item_GetRecord(id)+0xc (JP) or "????????".  cave_vision's
      vis_list_veneer (hooked at the per-glyph loop init @0x080dae8a) VWF-draws ITEM_TABLE[id]
      (pooled English) for available+translated items, else the JP/"????????" pointer.

  (2) the selection prompt (Vision_ComposePrompt 0x080daf50): drew "[item]から幻想を{NL}抽出しますか？"
      as OAM-sprite text (item name from the record, then two code-literal fragments).  English word
      order can't keep the item-first splice cleanly, so the prompt is made generic:
        - the JP item-name loop is skipped (force the pre-loop `beq` @0x080daf78 unconditional), and
        - the two fragments repoint to pooled English: "Extract a vision" / "from this item?".
      The selected item name is shown (in English) in the list right above, so naming it again here
      is unnecessary.  Also repoints the "素材がありません！" no-materials error -> "No materials!".

Run after patch_itemname (ITEM_TABLE) and patch_spritebuf (Text_DrawSpriteString VWF).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

SRC = Path(__file__).resolve().parent / "cave_vision.c"

from engine.script import rommap
from text.script import tr

# list-row name loop init: `movs r6,#0 ; movs r2,#0x6c`
LIST_HOOK = 0x080DAE8A
LIST_HOOK_OLD = bytes.fromhex("00266c22")

# Second visionary/material list — the NPC "appraiser" list drawer @0x080d37bc (different module
# from the DDS terminal's Vision_DrawItemList; 6 rows, no quantities).  Row-name loop init
# `movs r0,#0xc ; lsls r5,r0,#0x10` -> bl vis2_list_veneer (STRIP-renders ITEM_TABLE[id], gray/normal
# preserved, then resumes past the dead per-glyph loop).  Strip rendering (not per-glyph sprites)
# avoids the OBJ-sprite overrun that flickered the party panel.
LIST2_HOOK = 0x080D3824
LIST2_HOOK_OLD = bytes.fromhex("0c200504")

# prompt: skip the JP item-name loop (force the pre-loop `beq 0x80dafac` @0x080daf78 unconditional).
SKIP_ITEM = 0x080DAF78
SKIP_ITEM_OLD = bytes.fromhex("18d0")   # beq #0x80dafac
SKIP_ITEM_NEW = bytes.fromhex("18e0")   # b   #0x80dafac

# code/data literal SLOTS holding JP string pointers -> repoint to pooled English (drawn by the same
# printers).  The DDS terminal MENU rows are `CATEGORY＞hotkey{n}「label」` strings drawn whole via
# Text_DrawSpriteString by DDS_DrawMenuRow (0x080db2c0) from per-category cursor tables; the EN
# category prefix (DICTIONARY/VISIONARY/DICREAD) already rendered, only the 「label」 was JP.  All of
# ＞「」 encode in the EN font, so the whole formatted string is translated and the slot repointed.
LITERALS = [
    # --- Visionary (素材補完) service prompt + error ---
    (0x080DAFE4, 0x08009534, "Extract a vision"),       # から幻想を  (prompt line 1, x=0x14 after skip)
    (0x080DAFE8, 0x08009540, "from this item?"),         # 抽出しますか？(prompt line 2)
    (0x080DAA5C, 0x08009550, "No materials!"),            # 素材がありません！
    # --- DDS terminal menu rows (CATEGORY＞hotkey{n} "label", matching bank_sendback.json's DICREAD
    #     rows which already own the third menu table; style/quotes kept consistent with them) ---
    (0x08582438, 0x080094E8, 'VISIONARY＞S{n} "Select Item"'),   # 素材選択
    (0x0858243C, 0x0800950E, 'VISIONARY＞C{n} "Get Vision"'),    # 素材補完
    (0x08582D28, 0x08009564, 'DICTIONARY＞R{n} "Browse"'),       # 辞典閲覧
    (0x08582D2C, 0x0800958C, 'DICTIONARY＞C{n} "Register"'),     # 辞典補完
    (0x080DB310, 0x080095B4, "No demons to browse!"),            # 閲覧できる悪魔がいません！
]

# Read-side coverage: the JP text addresses this cave makes English (consumed by
# lib/cave_coverage.py so audit_orphans/audit_text_coverage don't false-flag them).
COVERED_TEXT_ADDRS = tuple(a for r in LITERALS for a in r[:2])


def apply(p):
    # FAR cave (out of BL range): it pulls in the cave_strip.h core (vis2 keyed-by-id strip), too
    # large for the scarce near pool.  Hooks reach it via near trampolines (p.bl_far).  The two list
    # veneers both set r3 before reading it (the trampoline clobbers r3), so this is safe.
    p.cave_c_far(SRC, name="vision")
    sy = p.cave_c_syms
    p.bl_far(LIST_HOOK, sy["vis_list_veneer"], LIST_HOOK_OLD, name="vision item-list name veneer")
    p.bl_far(LIST2_HOOK, sy["vis2_list_veneer"], LIST2_HOOK_OLD, name="vision NPC item-list name veneer")
    p.patch(SKIP_ITEM, SKIP_ITEM_OLD, SKIP_ITEM_NEW, name="vision prompt skip JP item name")

    far = [rommap.FARDATA_VISION]
    for slot, jp, en in LITERALS:
        cur = int.from_bytes(p.read(slot, 4), "little")
        if cur != jp:
            raise SystemExit(f"patch_vision: literal @0x{slot:08X}: expected 0x{jp:08X}, found 0x{cur:08X}")
        blob = tr.encode(en) + b"\x00\x00"
        addr = far[0]
        if addr + len(blob) > rommap.FARDATA_LEVELUP:
            raise SystemExit(f"patch_vision: pool overruns FARDATA_LEVELUP (0x{rommap.FARDATA_LEVELUP:08X})")
        p.write(addr, blob)
        p.write(slot, addr.to_bytes(4, "little"))
        far[0] = addr + len(blob)

    print(f"vision: list-name cave @0x{sy['vis_list_veneer']:08X}, prompt generic, "
          f"3 strings @0x{rommap.FARDATA_VISION:08X}")
