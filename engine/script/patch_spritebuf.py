#!/usr/bin/env python3
"""Running-buffer rewrite of the OAM sprite-text printer Text_DrawSpriteString (FUN_080ac334).

The stock printer emits one hardware OAM sprite per glyph; English's higher glyph count
overflows the 128-OAM hardware limit and UI sprites get dropped (party panel "flicker").
This replaces the per-glyph loop with a C renderer (engine/script/cave_runtext.c) that paints
the string into a packed VWF strip in the glyph cache's own EWRAM staging buffer, reuses the
engine's deferred DMA to commit it to OBJ VRAM, and covers it with wide 32x16 sprites — a few
sprites per line instead of one per glyph. See docs/text-render-hooks.md and cave_runtext.c.

Build: compile cave_runtext.c with devkitARM (Thumb, armv4t), link at CAVE with the naked
veneer (cave_entry, section .text.entry) first, objcopy to a flat blob, inject at CAVE.

Hook: at 0x080ac360 (right after the stock prologue unpacks the args; caller lr already saved
to the stack) replace `b 0x080ac38a; mov r0,#0xc0` (13 e0 c0 20) with `bl CAVE`. The veneer
marshals the unpacked regs into the AAPCS call, runs the worker, then jumps to the stock
epilogue at 0x080ac398. The rest of the original loop becomes dead code.

This renderer owns VWF advancement and marker expansion for the complete sprite-string path.
Run AFTER patch_vwf.py (needs left-aligned glyphs + the width table).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from engine.script import rommap

SRC = Path(__file__).resolve().parent / "cave_runtext.c"
B = rommap.ROM_BASE

HOOK = 0x080AC360          # `b 0x080ac38a; mov r0,#0xc0`
HOOK_OLD = bytes.fromhex("13e0c020")


def apply(p):
    cave = p.cave_c(SRC, name="spritebuf")
    p.bl(HOOK, cave, HOOK_OLD)
