/* cave_introdisclaimer.c — boot "this game is a work of fiction" disclaimer, in English.
 *
 * The stock renderer Intro_DrawDisclaimer 0x080D67BC draws the disclaimer as 3 hardcoded
 * fixed-pitch (13px) rows of 17/16/17 FULL-WIDTH glyphs, read sequentially from the string
 * @0x085096C4 via FontSprite_DrawGlyph (one cached OAM sprite per glyph).  Fixed-pitch + a
 * 64-cell glyph-cache cap make English (half-width, proportional, ~80+ glyphs) impossible
 * there.  patch_introdisclaimer repoints the intro cutscene step fn-ptr @0x08509EEC to
 * intro_draw below, so this runs INSTEAD of the stock renderer (every frame, like it).
 *
 * We draw the pooled English (the intro_disclaimer section repointed 0x080D6868 to it) through
 * Text_DrawSpriteString — already the VWF strip path (cave_runtext / patch_spritebuf): glyphs
 * pack into ~16px strip cells covered by a few wide sprites (no per-glyph OAM, no cache-cap
 * overflow), and 0x0300 ({n}) newlines split it into rows.  We author the line breaks; here we
 * just measure to centre the block and pick the vertical start so it sits where the JP did.   */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#include "rommap.h"

typedef void (*dss_fn)(const u16 *str, u32 p2, u32 p3, int startX, int startY, int pitch);
#define DrawSpriteString ((dss_fn)(RM_Text_DrawSpriteString | 1))
#define WIDTH ((const u8 *)RM_WIDTH_TABLE)

#define NEWLINE 0x0300
#define TERM    0x0301
#define PITCH   13          /* row height (the stock renderer used 13px rows too) */

static u16 gw(u16 g) { return (g < 0x1300) ? WIDTH[g] : 13; }   /* VWF advance, table default 13 */

/* named cave_entry + .text.entry so it is the ELF entry root (gc-sections keeps the blob).
 * The cutscene calls it as an ordinary no-arg function. */
__attribute__((used, section(".text.entry")))
void cave_entry(void)
{
    const u16 *s = *(const u16 *const *)RM_INTRO_DISCLAIMER_STR_PTR;
    const u16 *p;
    int n = 1, w = 0, maxw = 0;

    if (!s || s[0] == 0 || s[0] == TERM) return;

    /* count lines and find the widest (for block centring) */
    for (p = s; *p && *p != TERM; ++p) {
        if (*p == NEWLINE) { if (w > maxw) maxw = w; w = 0; ++n; }
        else w += gw(*p);
    }
    if (w > maxw) maxw = w;

    int startX = (240 - maxw) / 2; if (startX < 0) startX = 0;
    int startY = 69 - (n - 1) * PITCH / 2;   /* JP block centred on y~69 (rows 56/69/82) */
    if (startY < 0) startY = 0;

    /* one call: cave_runtext splits on NEWLINE and lays each row at startY + L*PITCH */
    DrawSpriteString(s, 0, 0, startX, startY, PITCH);
}
