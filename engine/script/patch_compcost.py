#!/usr/bin/env python3
"""VWF the macca-cost NUMBER in the Cathedral-of-Shadows summon/confirm window.

The summon-confirm prompt ("Summoning will cost / ћ9440  macca. / Is this okay?") is composed
by Comp_RenderMessage (the big msg-id switch @0x080ce8xx-0x080ceabe, undisassembled region).
Its line-2 number is drawn by a dedicated helper Comp_DrawSummonCost @0x080cead0:

  Math_IntToDigits8(cost) -> 8-digit buffer (DAT_080a9d78); draw the macca symbol glyph 0x52,
  then each significant digit (glyph 0xCC..0xD5 = '0'..'9', from the digit table @0x084F0EAC)
  via FontSprite_DrawGlyph (OAM glyph-cache, 0x080AC218), advancing X by a FIXED 0xC per glyph.

The digit glyphs are the SAME left-aligned, VWF-trimmed English glyphs patch_vwf produces, but
this helper hardcodes a 12px pitch, so "9440" reserves full JP-cell width (the user's report).
Fix: replace the per-digit fixed advance with the glyph's real WIDTH_TABLE width — exactly what
patch_spritebuf/patch_descvwf do for the flowing-text printers, just for this bespoke drawer.

  Per-digit advance @0x080ceb34 (8 B), reached ONLY for a DRAWN digit (the leading-zero skip
  branches around it), with r5=X cursor, r4=loopIndex<<24, r8=&digits[0], r9=digit glyph table:
      add r0,r5,#0 ; add r0,#0xc ; lsl r0,#0x10 ; lsr r5,#0x10      (x = (x+12) & 0xffff)
  -> bl CAVE; the cave re-derives this digit's glyph code (digits[7-loopIndex] -> table) and does
     x = (x + widthTable[code]) & 0xffff.  The macca symbol's own advance (@0x080ceaf8) is left at
     12px (it's a JP-range glyph, not left-aligned, so a one-cell gap before the number is correct);
     "macca." trails at numberEndX+0xC in the caller, so shrinking the number pulls it in for free.

Run AFTER patch_vwf.py (needs the left-aligned digit glyphs + the width table).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from engine.script import rommap

WIDTH_TBL = rommap.WIDTH_TABLE

# Comp_DrawSummonCost per-digit advance: `add r0,r5,#0; add r0,#0xc; lsl r0,#0x10; lsr r5,#0x10`.
P = 0x080CEB34
ADV_OLD = bytes.fromhex("281c0c300004050c")   # 28 1c 0c 30 00 04 05 0c  (8 bytes)

# entry (bl from the site): r5=X, r4=loopIndex<<24, r8=&digits[0] (LSB-first), r9=digit glyph
# table (0x084F0EAC).  digit = digits[7 - loopIndex] (MSB-first draw order); glyph = table[digit].
# r0-r3 + lr are scratch here (clobbered by the preceding FontSprite_DrawGlyph). Returns X in r5.
CAVE_ASM = """
    mov  r1, r8          /* r1 = &digits[0] */
    adds r1, #0x7        /* r1 = &digits[7] (most significant) */
    asrs r0, r4, #0x18   /* r0 = loopIndex (r4 = loopIndex<<24) */
    subs r0, r1, r0      /* r0 = &digits[7 - loopIndex] = this digit */
    ldrb r0, [r0]        /* r0 = digit value 0..9 */
    lsls r0, r0, #1      /* *2 (u16 table) */
    mov  r1, r9          /* r1 = digit glyph table */
    adds r0, r0, r1      /* &table[digit] */
    ldrh r0, [r0]        /* r0 = glyph code 0xCC..0xD5 */
    ldr  r1, [pc, #0]    /* = WIDTH_TBL */
    ldrb r0, [r1, r0]    /* r0 = VWF width */
    adds r5, r5, r0      /* X += width */
    lsls r5, r5, #0x10
    lsrs r5, r5, #0x10   /* X &= 0xffff */
    bx   lr
"""

LITERALS = [WIDTH_TBL]


def apply(p):
    cave = p.cave_asm(CAVE_ASM, LITERALS, name="compcost")
    p.bl(P, cave, ADV_OLD, name="compcost-digit-adv")   # bl + 2 nop (8-byte site)
    print(f"compcost: summon-cost number VWF (digit advance @0x{P:08X} -> width table)")
