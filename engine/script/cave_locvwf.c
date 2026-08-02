/* cave_locvwf.c — VWF advance for the three save/load-screen location-name drawers.
 *
 * The save/load (file select) screen draws location text FIXED-PITCH: each glyph token is
 * blitted into the BG canvas 0x0200f874 by Font_DrawGlyphTinted and x is bumped by a constant
 * 0xc.  The English location_names section packs proportional text, so the file-select / region
 * banner reads gappy (user report).  Font_BlitGlyph OR-blits a 0xc-wide cell at the pixel x it
 * is given, so VWF is just "advance x by the glyph's real width" — same idea as the 8px-name
 * cave (cave_name8vwf / patch_defaultnames' SAVE_CAVE_ASM).
 *
 * Three loops share a byte-identical x-advance (docs/save-screen.md "fixed-pitch location-name
 * drawers"):
 *   #1 SaveScreen_DrawLocationName 0x080d035c  (advance @0x080d03ea)
 *   #2 SaveScreen_DrawTokenString  0x080d042c  (advance @0x080d0462)
 *   #3 inline loop in SaveScreen_DrawFileSlot  (advance @0x080d05c6)
 * each:  adds r0,r6,#0 ; adds r0,#0xc ; lsls r0,#0x10 ; lsrs r6,r0,#0x10   (r6 = (x+0xc)&0xffff)
 * with r4 already pointing at the NEXT token (the just-drawn token is [r4-2]) and r6 = x.
 *
 * patch_savevwf replaces the first two instructions with `bl cave_entry` and NOPs the lsls/lsrs;
 * this cave reads the just-drawn token, looks up its width (English glyphs RM_ENG_LO..RM_ENG_HI
 * take the VWF width table; everything else — JP/full-width — keeps the stock 0xc, so untranslated
 * cells render byte-identically), sets r6 = (x + width) & 0xffff and returns.  The loop's own
 * terminator/count logic (0 / 0x301 / 0x57 '@' pad) is left untouched.  r4/r6 are preserved
 * (only r0/r1 are scratch, both dead at the hook's continuation). */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#include <rommap.h>

__attribute__((naked, used, section(".text.entry")))
void cave_entry(void)
{
    __asm__ volatile(
        "sub  r0, r4, #2       \n"   /* just-drawn token = [r4 - 2] */
        "ldrh r0, [r0]         \n"
        "ldr  r1, =%c0         \n"   /* RM_ENG_LO */
        "cmp  r0, r1           \n"
        "blo  1f               \n"   /* < ENG_LO -> not English: fixed 0xc */
        "ldr  r1, =%c1         \n"   /* RM_ENG_HI */
        "cmp  r0, r1           \n"
        "bhs  1f               \n"   /* >= ENG_HI -> not English: fixed 0xc */
        "ldr  r1, =%c2         \n"   /* RM_WIDTH_TABLE */
        "ldrb r1, [r1, r0]     \n"   /* English glyph: VWF advance */
        "b    2f               \n"
        "1:                    \n"
        "mov  r1, #0xc         \n"
        "2:                    \n"
        "add  r6, r6, r1       \n"
        "lsl  r6, r6, #0x10    \n"   /* match the stock 16-bit x truncation */
        "lsr  r6, r6, #0x10    \n"
        "bx   lr               \n"
        :: "i"(RM_ENG_LO), "i"(RM_ENG_HI), "i"(RM_WIDTH_TABLE)
    );
}

/* cave_entry_r5 — same VWF advance, but for the in-game map-banner drawer FUN_080c8b7c, whose
 * x lives in r5 (and whose stock step is the variable r7, not a constant 0xc).  patch_savevwf
 * `bl`s the site's `add r0,r5,r7 ; lsl r0,#0x10` (4 B) and NOPs the trailing `lsr r5,r0,#0x10`,
 * so this returns the new r5 = (x + width) & 0xffff.  r4 = next token (just-drawn = [r4-2]);
 * r4/r6/r7-r10 preserved, only r0/r1 scratch. */
__attribute__((naked, used, section(".text.entry")))
void cave_entry_r5(void)
{
    __asm__ volatile(
        "sub  r0, r4, #2       \n"
        "ldrh r0, [r0]         \n"
        "ldr  r1, =%c0         \n"   /* RM_ENG_LO */
        "cmp  r0, r1           \n"
        "blo  1f               \n"
        "ldr  r1, =%c1         \n"   /* RM_ENG_HI */
        "cmp  r0, r1           \n"
        "bhs  1f               \n"
        "ldr  r1, =%c2         \n"   /* RM_WIDTH_TABLE */
        "ldrb r1, [r1, r0]     \n"
        "b    2f               \n"
        "1:                    \n"
        "mov  r1, #0xc         \n"
        "2:                    \n"
        "add  r5, r5, r1       \n"
        "lsl  r5, r5, #0x10    \n"
        "lsr  r5, r5, #0x10    \n"
        "bx   lr               \n"
        :: "i"(RM_ENG_LO), "i"(RM_ENG_HI), "i"(RM_WIDTH_TABLE)
    );
}
