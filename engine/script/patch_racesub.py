#!/usr/bin/env python3
"""Make Race_GetName resolve the over-budget race-name 0xFFFF sentinel (encounter intro / taunts /
victory / info screen).

THE BUG (user report 2026-06-21): entering an encounter with a demon whose RACE name is 8 glyphs
("Demonoid", "Shinshou") broke the intro line ("{RACE} {DEMON} appeared! ...") — it rendered just
the race name and dropped the rest.

ROOT CAUSE. names_race is route="sentinel": a race name is stored INLINE in a 16-byte cell of
g_wRaceNameTable (0x081A5C34, stride 0x10) = 8 u16 tokens. tr.py packs a name that fits the budget
(<=7 glyphs + 0x0000 terminator = 8 tokens) inline as glyphs; an over-budget name (8 glyphs leaves
no room for the terminator) takes the _arm_sentinel arm instead, writing `0xFFFF` at cell[0] + a
4-byte pool pointer at cell+2 (the real EN string lives in the pool). patch_race's status-bar cave
already resolves that sentinel, but the BATTLE/EVENT composers don't:

  Race_GetName(race)                     -> race*0x10 + 0x081A5C34  (raw cell pointer)
  MessageBox_ComposeSpeciesText 0x031f   -> copy Race_GetName(...) until 0x0000   (encounter intro)
  MessageBox_ComposeRaceNameText         -> copy Race_GetName(...) until 0x0000   (victory line)
  ScriptOp_DrawCharOrSubstitute 0x031f   -> copy Race_GetName(...) until 0x0000   (taunts/field)
  Demon_DrawInfoScreen                   -> draws Race_GetName(...)                (info screen)

All copy from the cell start until a 0x0000.  For a short name the cell holds real glyphs -> fine.
For an over-budget name the cell is [0xFFFF, ptr_lo, ptr_hi, 0x0000] -> they copy the raw sentinel
+ pointer halfwords, NOT the name (= the broken intro).  43 of 45 races are <=7 glyphs so only the
two 8-glyph races ever hit it.

THE FIX.  Race_GetName is the single choke point every race-name reader goes through, so resolve
the sentinel there: if cell[0] == 0xFFFF, return the pool pointer at cell+2 (read as two halfwords,
the +2 slot is not 4-aligned) instead of the cell pointer.  For the 43 short names cell[0] is a
glyph, so it returns the inline pointer exactly as before (zero behaviour change).  Every consumer
copies/draws from a terminated glyph string either way; the pool string is one too.  patch_race's
status-bar cave still works (it now receives the already-resolved pointer; its own 0xFFFF branch
just never triggers).

The 5-instruction leaf can't grow in place, so the entry is redirected to a cave with the classic
`ldr r3,[pc,#0]; bx r3` trampoline (preserves r0/lr, clobbers only scratch r3 — exactly what
rompatch.bl_far does).  The original literal pool word (the base) at +0x0C is left dead in place.
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

import struct

RACE_GETNAME = 0x080C068C                       # Race_GetName entry (leaf)
RACE_GETNAME_OLD = "0004000b01494018"           # lsl r0,#0x10 ; lsr r0,#0xc ; ldr r1,[pc,#4] ; add r0,r0,r1
RACE_NAME_TABLE = 0x081A5C34                     # g_wRaceNameTable base (== [0x080C0698])

# Sentinel-aware Race_GetName: r0 = race -> pointer to the race-name glyph string.
#   short name: inline cell pointer (unchanged);  over-budget: pooled-string pointer from cell+2.
#
# HARDENED (2026-07-05, MiSTer crash post-mortem): two frozen savestates proved this
# cave once returned 0x00000020 — a value UNCONSTRUCTIBLE from the ROM's cells for ANY
# 16-bit race input (exhaustively scanned), i.e. the three cell reads themselves were
# served wrong at runtime ([cell] floated to 0xFFFF = accidental sentinel match, then
# near-zero lo/hi).  The composer's race copy then ran from the wild pointer into CPU
# open bus (never a terminator) and flooded the EWRAM mirrors — sound/scroll shadows
# destroyed, main loop never returned, battle lockup.  Defense in depth with
# patch_racecap (copy bounded to 15 tokens): validate the rebuilt pointer is cart
# space; anything else returns the raw cell — worst case one garbled name.
CAVE_ASM = """
    lsls r0, r0, #16
    lsrs r0, r0, #12       /* r0 = (race & 0xffff) * 0x10 */
    ldr  r1, [pc, #0]      /* r1 = g_wRaceNameTable base */
    adds  r0, r0, r1   /* r0 = &cell */
    ldrh r1, [r0]
    movs r2, #1
    lsls r2, r2, #16
    subs r2, #1            /* r2 = 0xFFFF sentinel */
    cmp  r1, r2
    bne  rg_done
    ldrh r1, [r0, #2]      /* over budget: pool pointer at cell+2 (two unaligned halfwords) */
    ldrh r3, [r0, #4]
    lsls r3, r3, #16
    orrs r3, r1            /* r3 = rebuilt pooled pointer */
    lsrs r1, r3, #25       /* cart space 0x08-0x09xxxxxx <=> top 7 bits == 4 */
    cmp  r1, #4
    bne  rg_done           /* implausible -> return &cell (safe inline fallback) */
    adds r0, r3, #0
rg_done:
    bx   lr
"""
LITERALS = [RACE_NAME_TABLE]


def apply(p):
    cave = p.cave_asm(CAVE_ASM, LITERALS, name="racesub")
    # In-place trampoline at the function entry (preserve r0/lr; jump to the Thumb cave).
    tramp = b"\x00\x4b\x18\x47" + struct.pack("<I", cave | 1)   # ldr r3,[pc,#0] ; bx r3 ; .word cave|1
    p.patch(RACE_GETNAME, RACE_GETNAME_OLD, tramp, name="race_getname->racesub")
