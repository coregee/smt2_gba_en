#!/usr/bin/env python3
"""Build the translated ROM from source: font + VWF + all translation sections.

Single-process pipeline: load the base ROM once into a RomPatcher, run every patch module's
`apply(p)` in order (font injection, the VWF/printer hooks, the id->table name caves, …), write the
font ROM, then `tr.pack` the translation pool/text on top -> rom/smt2-en.gba.  Code caves are
auto-allocated from the free pool (rommap.CAVE_POOL_*) — no hand-picked addresses.

Usage:  python engine/script/build_rom.py
Output: rom/smt2-en.gba   (base ROM untouched)
"""
import importlib
import os
import sys

try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path
from text.script import tr
from engine.script.rompatch import RomPatcher, plan_pool_layout
from font import ENGINE_PATCHES as FONT_PATCHES
from graphics import ENGINE_PATCHES as GRAPHICS_PATCHES

# Battle demon names (robust path, docs/text-pipeline-overview.md): patch_battlename makes the
# name-copy sites emit a 1-u16 MARKER (0xF000|id); patch_spritebuf's strip renderer expands it through
# NAME_TABLE. This beats the cap-8 / fixed-length copy loops uniformly for names of any length.
# Patch modules, applied in THIS ORDER.  Cave PLACEMENT is now order-independent: build() runs a
# best-fit-decreasing planner (rompatch.plan_pool_layout), so a later big cave can no longer be
# starved by earlier small ones — the old "big caves first / place small ones late" hand-tuning is
# GONE.  What still matters is TRUE build-time data dependencies; the one that exists:
#   * patch_vwf AFTER patch_font — patch_vwf measures the glyph bitmaps patch_font injects.
# The "AFTER patch_X" one-liners below are runtime hook-composition reminders (the order they're in
# is fine, but it's no longer about cave sizing).  To add a patch: drop patch_*.py in this dir and
# add its name here; position only matters if it has a real data dep on another patch's ROM writes.
PATCH_NAMES = (
    "patch_msgwin",         # message-window strip renderer (largest cave; placement now automatic)
    "patch_font", "patch_vwf", "patch_fontmirror", "patch_descvwf", "patch_spritebuf",
    "patch_names", "patch_menu", "patch_menutinted", "patch_humanmag", "patch_equipstat", "patch_statpage",
    "patch_levelup",   # level-up "残りポイント" -> "Points left:" (after patch_menu's Font_DrawGlyph hook)
    "patch_positions", "patch_resist", "patch_race",
    "patch_racesub",        # Race_GetName resolves the over-budget race-name 0xFFFF sentinel
                            # (encounter intro / taunts / victory line break on 8-glyph races)
    "patch_name", "patch_drop",
    "patch_itemname", "patch_itemdrop", "patch_skilllist",
    "patch_element_narrow", "patch_dialog", "patch_battlemenu", "patch_battlewedge", "patch_battlename",
    "patch_dialogitemname",  # {ITEM_NAME} (0x0321) in event-VM dialogue -> EN ITEM_TABLE (sibling of battlename's nego copy)
    "patch_battleitemname",  # {ITEM_NAME} (0x0321) in BATTLE-composed text (Menu_ExpandListTemplate case 0xb) -> EN ITEM_TABLE
    "patch_namemove", "patch_defaultnames",
    "patch_partyname",      # {=2003} (0x320) "first-alive name + 達" -> EN ("Hawk" / "Hawk's party")
    "patch_nameentry",      # EN-friendly name-entry grid (Uppercase/Lowercase/Symbols); AFTER patch_defaultnames (shares the FARDATA charset)
    "patch_shopname", "patch_exchangelist",
    "patch_offerlist",      # negotiation gem/item-offer list (FUN_08133f14) -> EN ITEM_TABLE markers
    "patch_casinolist",     # casino coin->item prize list (CasinoPrize_DrawRows 0x080d37bc) -> EN ITEM_TABLE (VWF strip)
    "patch_casinoprize",    # casino minigame PRIZE box (Code Breaker FUN_0814c318) -> EN ITEM_TABLE VWF (template)
    "patch_menuitemname",   # item-detail 3-up + demon held-item names (BG canvas) -> EN ITEM_TABLE VWF

    "patch_markerlist",
    "patch_compcost",       # VWF the macca-cost number in the COMP summon/confirm window
    "patch_dictname",
    "patch_dictsort",       # pure-data: dictionary NAME page (kana sort -> EN alphabetical buckets)
    "patch_parentrace",     # pure-data: demon-dictionary "parent race" (clan family) names -> English
    "patch_dictstatus",     # demon-dictionary STATUS screen stat labels -> English (repoint + 3 micro-caves)
    "patch_vision",         # DDS "素材補完" (Visionary) service: item list names + prompt -> English
    "patch_areaname",       # pure-data: English current-area names spliced into script msgs (op 0x328)
    "patch_roomlabels",     # pure-data: 3D room-preview facility labels (JAKYOU->CATHEDRAL, ...) -> EN
    "patch_titlegfx",       # pure-data: graphics/assets/*.png baked-text graphics
    # AFTER patch_spritebuf (cave_runtext strip): boot fiction-disclaimer via the strip path.
    "patch_introdisclaimer",
    # AFTER patch_spritebuf (clip) + patch_vwf (g_wMsgTextCol pixel accumulator): pixel-pace typewriters.
    "patch_typewriter",
    "patch_namehuman",      # status-screen + skill/equip-list human-name loops
    "patch_noitemdrop",     # status-screen "NO ITEM" no-drop label -> "(No item)"
    "patch_savevwf",        # save/load-screen location-name drawers (disjoint from defaultnames' hook)
    "patch_elevator",       # elevator floor-select list: "２２階" -> "22F"/"B3F" via patch_spritebuf
    # AFTER patch_spritebuf (cave_runtext strip): passcode keypad prompt (strip) vs entered digits
    # (stock glyph cache) shared OBJ row 0 -> digits clobbered the prompt tiles; pre-warm the digit
    # glyphs so the prompt strip floats to row 1.
    "patch_keypad",
    # Cap the composer's uncapped race-name copy (the 2026-07 MiSTer runaway).
    "patch_racecap",
)

# Font and baked graphics are explicit asset stages embedded in the engine's dependency
# order. They declare ownership without regrouping patches, which would change when ROM
# data becomes visible to later patch modules.
PATCH_STAGES = {
    "font": FONT_PATCHES,
    "graphics": GRAPHICS_PATCHES,
}
_stage_names = [name for names in PATCH_STAGES.values() for name in names]
if len(_stage_names) != len(set(_stage_names)):
    raise RuntimeError("a patch module is registered to more than one asset stage")
_unknown_stage_names = set(_stage_names) - set(PATCH_NAMES)
if _unknown_stage_names:
    raise RuntimeError(f"asset stages reference unknown patches: {sorted(_unknown_stage_names)}")
PATCH_STAGE_BY_NAME = {
    name: stage
    for stage, names in PATCH_STAGES.items()
    for name in names
}
PATCHES = [
    importlib.import_module(f"engine.script.{name}")
    for name in PATCH_NAMES
]

# Diagnostic beacon hooks (battle-entry lockup localization on hardware/FPGA):
# opt-in so normal builds stay byte-identical.  SMT2_DIAG=1 python build_rom.py
if os.environ.get("SMT2_DIAG"):
    PATCHES.append(importlib.import_module("engine.script.patch_diagbeacon"))

BASE = PATHS.source_rom
FONT_OUT = PATHS.build_path("smt2-en-font.gba")
OUT = PATHS.build_path("smt2-en.gba")


def _fresh_rom():
    """A fresh 16 MB working ROM: the 8 MB base zero-padded up to ROM_TARGET_SIZE so the FAR code
    caves (rommap.FARCAVE_POOL_SPANS, in the upper padding, reached via near trampolines) are
    writable during the patch phase.  tr.pack's pool stays low (~9 MB) and its final pad is then a
    no-op, so the far caves survive."""
    rom = bytearray(BASE.read_bytes())
    if len(rom) < rommap.ROM_TARGET_SIZE:
        rom.extend(b"\x00" * (rommap.ROM_TARGET_SIZE - len(rom)))
    return rom


def build_patcher():
    """Two-pass build so cave placement is independent of PATCH_ORDER (best-fit-decreasing).

    Pass 1 runs every patch over a throwaway ROM, placing pool caves in a non-failing SCRATCH region
    just above the far pool, purely to MEASURE each cave's size in apply() order (the cave bodies and
    hooks written there are discarded).  We then compute a best-fit-decreasing placement plan and run
    the REAL pass 2 consuming it.  Returns the pass-2 patcher (no files written; see build()).  No
    hand-picked cave addresses."""
    # ---- pass 1: measure pool-cave sizes (scratch pool can't fragment-fail, so any order works) ----
    scratch = (max(hi for _lo, hi in rommap.FARCAVE_POOL_SPANS), rommap.ROM_BASE + rommap.ROM_TARGET_SIZE)
    p1 = RomPatcher(_fresh_rom(), pool=scratch)
    for mod in PATCHES:
        mod.apply(p1)
    # The BFD planner assumes the near spans start empty, so no fixed (at=) / far cave may sit inside one.
    for a, s, name in p1.caves:
        for lo, hi in rommap.CAVE_POOL_SPANS:
            if a < hi and a + s > lo:
                raise SystemExit(f"fixed/far cave '{name}' @0x{a:08X}+{s} overlaps near span "
                                 f"0x{lo:08X}-0x{hi:08X}; the BFD planner assumes near spans start empty")
    plan = plan_pool_layout(p1._plan_log, list(rommap.CAVE_POOL_SPANS))

    # ---- pass 2: the real build, every pool cave placed where the plan says ----
    p = RomPatcher(_fresh_rom())
    p._plan = plan
    for mod in PATCHES:
        mod.apply(p)
    if p._req_ord != len(plan):
        raise SystemExit(f"pass 2 made {p._req_ord} pool requests but the plan has {len(plan)} — "
                         "the two passes diverged (a cave's allocation is non-deterministic)")
    return p


def build():
    """build_patcher() + write the font ROM (pre-pack) and the final translated ROM."""
    p = build_patcher()
    FONT_OUT.parent.mkdir(parents=True, exist_ok=True)
    FONT_OUT.write_bytes(p.rom)              # font ROM (pre-pack intermediate)
    OUT.write_bytes(tr.pack(p.rom))          # + translation pool/text -> final ROM
    return p


def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")
    p = build()
    print(p.summary())
    print(f"built {OUT}")


if __name__ == "__main__":
    raise SystemExit(main())
