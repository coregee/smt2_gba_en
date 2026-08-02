/* cave_vision.c -- "素材補完" (Material/Visionary Completion) service item lists -> English VWF.
 *
 * TWO list drawers (different screens, same OBJ-glyph-cache substrate, same fix): the DDS terminal's
 * Vision_DrawItemList (0x080dadf8, vis_*) and the NPC appraiser's list drawer (0x080d37bc, vis2_*).
 *
 * Vision_DrawItemList (0x080dadf8) lists the player's items that can yield a "vision" (幻想); each
 * row's name is drawn glyph-by-glyph via FontSprite_DrawGlyph (the OBJ glyph cache, same substrate
 * as the demon dictionary), fixed 0xc pitch, cap-8, from Item_GetRecord(id)+0xc (the JP item name)
 * or the "????????" default (0x085829bc) for unavailable items -- so English never fit and the list
 * drew Japanese.  Stay on the glyph cache: VWF-draw the pooled English item name (ITEM_TABLE[id])
 * when the item is available + translated, else the caller's JP/"????????" pointer.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

#include <rommap.h>

typedef void (*fsg_fn)(u16 code, int p2, int p3, int x, int y);   /* FontSprite_DrawGlyph(g,_,_,x,y) */
#define FontSprite_DrawGlyph ((fsg_fn)(RM_FontSprite_DrawGlyph | 1))
#define WIDTH_TBL  ((const u8 *)RM_WIDTH_TABLE)
#define ITEM_TABLE ((const u16 *const *)RM_ITEM_TABLE)
#define UNKNOWN_NAME ((const u16 *)0x085829BCu)            /* "????????" (unavailable/unidentified) */

/* gc-sections linker root (ENTRY); never called. */
__attribute__((used, section(".text.entry")))
void cave_entry(void) {}

/* item name VWF on the glyph cache: stop at NUL / 0x0301 / cap / x past the list field. */
static void draw_item_vwf(const u16 *s, int x, int y)
{
    int i;
    if (!s) return;
    for (i = 0; i < 40; ++i) {
        u16 g = s[i];
        if (g == 0 || g == 0x0301) break;
        if (x >= 0xE0) break;
        FontSprite_DrawGlyph(g, 0, 0, x, y);
        x += (g >= RM_ENG_LO && g < RM_ENG_HI) ? WIDTH_TBL[g] : 0xc;
    }
}

/* pick pooled English (available + translated) or the caller's JP/"????????" pointer. */
__attribute__((used, noinline))
void vis_item_vwf(u16 id, const u16 *jp, int x, int y)
{
    const u16 *s = jp;
    if (jp != UNKNOWN_NAME && id < RM_ITEM_COUNT && ITEM_TABLE[id])
        s = ITEM_TABLE[id];
    draw_item_vwf(s, x, y);
}

/* ------------------------------------------------------------------------------------------------
 * Second visionary/material item list: the NPC "appraiser" list drawer @0x080d37bc.  6 rows, no
 * quantities, redrawn EVERY frame (the breakpoint trace showed Item_GetRecord32 firing ~40x/frame).
 * The stock loop drew each row name as ONE OBJ SPRITE PER GLYPH (Font_DrawGlyphSprite normal /
 * 0x080ac2a0 grayed) -> 6 rows x ~10 glyphs overran the OBJ sprite budget and flickered the
 * party-panel sprites.  Route the names through the shared OBJ sprite-STRIP core (cave_strip.h): one
 * cached strip per item + a few wide covering sprites = far fewer OAM entries.  The eligibility gray
 * (stock 0x080ac2a0's displayParam, which Sprite_DrawSingle uses as the sprite palette) is carried as
 * the strip's palOff (2 = grayed).
 *
 * KEYED BY ITEM ID (not screen position): a row's strip persists in its OBJ cells across scroll, so
 * scrolling only re-emits the visible items at their new Y and blits the ONE newly-revealed item --
 * no full-list re-blit.  This whole cave lives in FAR ROM (patch_vision uses cave_c_far + bl_far), so
 * the strip core's size is no longer constrained by the scarce near cave pool.
 * ---------------------------------------------------------------------------------------------- */
typedef int (*elig_fn)(u32 id);
#define Item_IsListEligible ((elig_fn)0x080C5B11u)        /* FUN_080c5b10: 1 = normal, 0 = grayed */

#define STRIP_STATE RM_VISION_STRIP                       /* own StripState (top-EWRAM scratch)     */
#define STRIP_MARK  0                                     /* names already resolved -> no markers   */
#include "cave_strip.h"

__attribute__((used, noinline))
void vis2_item_vwf(u16 id, const u16 *jp, int y)
{
    int elig = Item_IsListEligible(id);
    const u16 *s = jp;
    int n = 0;
    if (id < RM_ITEM_COUNT && ITEM_TABLE[id])
        s = ITEM_TABLE[id];
    while (n < 40 && s[n] && s[n] != 0x0301) ++n;
    /* key = item id (tagged nonzero): the slot core keeps this item's strip cells stable across
     * scroll.  x=0xc, grp/prio 0 and pitch 0xc match the stock Font_DrawGlyphSprite call; palOff 2 =
     * grayed; reveal=STRIP_ALL (no typewriter on this list). */
    strip_run(0x56020000u | id, s, n, 0xc, y, STRIP_ALL, 0, 0, 0xc, elig ? 0 : 2);
}

/* row-name veneer (bl from 0x080d3824, replacing `movs r0,#0xc ; lsls r5,r0,#0x10`): r7 = item id,
 * r8 = JP name ptr (record+0xc), r6 = row y.  Strips the row name, then branches PAST the dead
 * per-glyph loop to the row-loop tail @0x080d386a (sb/sl row state preserved by the AAPCS call). */
__attribute__((naked, used, section(".text.entry")))
void vis2_list_veneer(void)
{
    __asm__ volatile(
        "mov  r1, r8          \n"   /* arg2 = JP name ptr (record+0xc) */
        "mov  r0, r7          \n"   /* arg1 = item id                  */
        "mov  r2, r6          \n"   /* arg3 = row y                    */
        "bl   vis2_item_vwf   \n"
        "ldr  r0, =0x080D386B \n"   /* resume at the row-loop tail (Thumb) */
        "bx   r0              \n"
    );
}

/* list-row name veneer (bl from 0x080dae8a, replacing `movs r6,#0 ; movs r2,#0x6c`): r4 = item id,
 * r0 = JP/"????????" name ptr, x = 0x6c, y = [sp+0x18]>>16.  Draws the row name, then branches PAST
 * the dead per-glyph loop to the next-row continuation @0x080daec4 (r8 row index preserved by the
 * AAPCS call; [sp+0x18] untouched). */
__attribute__((naked, used, section(".text.entry")))
void vis_list_veneer(void)
{
    __asm__ volatile(
        "ldr  r3, [sp, #0x18]  \n"   /* y << 16            */
        "lsr  r3, r3, #0x10    \n"   /* arg4 = y           */
        "mov  r1, r0           \n"   /* arg2 = JP/???? ptr */
        "mov  r0, r4           \n"   /* arg1 = item id     */
        "movs r2, #0x6c        \n"   /* arg3 = x           */
        "bl   vis_item_vwf     \n"
        "ldr  r0, =0x080DAEC5  \n"   /* resume past the loop (Thumb) */
        "bx   r0               \n"
    );
}
