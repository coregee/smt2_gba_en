#!/usr/bin/env python3
"""Demon status-screen "no drop" label: JP fixed-pitch romaji "NO ITEM" -> EN VWF "(No item)".

`Status_DrawDropItem 0x080cba7c` draws the demon's drop/held item field (combatant.f1a). When
`f1a == 0xFF` (no drop) it draws a fixed-pitch 6-glyph romaji label "NO ITEM" via six hardcoded
`Font_DrawGlyphTinted(code, buf, X, Y, 6)` calls at X = 0xc/0x18/0x30/0x3c/0x48/0x54 (tokens
N O  I T E M).  The other two branches (equipment / item-gem name) are already VWF (patch_drop /
patch_itemdrop), so this placeholder was the last fixed-width JP path on the drop line.

We replace the `f1a == 0xFF` branch (starts @0x080cbaa6, `ldr r5,[..buf]; mov r4,#6`) with a `bl`
to a cave that draws the pooled English "(No item)" variable-width (same tint 6, same X start
0xc / Y 0x49 / canvas STATUS_TEXT_BUF) then jumps to the function epilogue @0x080cbb28 — the six
original glyph draws become dead code.  Self-contained VWF loop (mirrors patch_drop); no dependency
on the patch_menutinted pointer hook.  Run AFTER patch_vwf.py (needs the width table).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from engine.script import rommap
from text.script import tr

HOOK = 0x080CBAA6                       # start of the f1a==0xFF branch: `ldr r5,[pc..]; mov r4,#6`
HOOK_OLD = bytes.fromhex("174d0624")
BUF = rommap.STATUS_TEXT_BUF            # status text canvas (= DAT_080cbb04 = 0x0200f874)
WIDTH_TBL = rommap.WIDTH_TABLE
EPI = 0x080CBB28 | 1                    # function epilogue (Thumb)
NOITEM = rommap.FARDATA_NOITEM         # pooled "(No item)" glyph string

# entry (bl from hook): registers free; frame has [sp,#0] reserved (the 5th-arg tint slot).
# r4/r5/r6 are pushed at function entry and restored by EPI, so clobbering them is safe; r7 is
# NOT saved by the function, so we keep BUF in the literal pool (re-loaded per glyph) and avoid it.
CAVE_ASM = """
    ldr  r4, [pc, #0]      /* NOITEM string ptr */
    movs r5, #0xc          /* X */
    movs r6, #0x6          /* tint */
nd_loop:
    ldrh r0, [r4]
    cmp  r0, #0
    beq  nd_done
    str  r6, [sp, #0]      /* tint (5th arg) */
    ldr  r1, [pc, #0]      /* BUF */
    adds  r2, r5, #0   /* X */
    movs r3, #0x49         /* Y */
    bl   #0x080ac980       /* rommap.Font_DrawGlyphTinted */
    ldrh r0, [r4]
    ldr  r1, [pc, #0]      /* WIDTH_TBL */
    ldrb r1, [r1, r0]
    adds r5, r5, r1        /* X += VWF width */
    adds r4, #2
    b    nd_loop
nd_done:
    ldr  r0, [pc, #0]      /* EPI */
    bx   r0
"""

LITERALS = [NOITEM, BUF, WIDTH_TBL, EPI]


def apply(p):
    blob = tr.encode("(No item)") + b"\x00\x00"
    if rommap.FARDATA_NOITEM + len(blob) > rommap.FARDATA_NAMEGRID_IDX:
        raise SystemExit(f"patch_noitemdrop: pool overruns FARDATA_NAMEGRID_IDX (0x{rommap.FARDATA_NAMEGRID_IDX:08X})")
    p.write(rommap.FARDATA_NOITEM, blob)
    cave = p.cave_asm(CAVE_ASM, LITERALS, name="noitemdrop")
    p.bl(HOOK, cave, HOOK_OLD, name="status drop NO ITEM -> (No item) VWF")
    print(f"noitemdrop: 'NO ITEM' -> '(No item)' VWF @0x{rommap.FARDATA_NOITEM:08X}")
