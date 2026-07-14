/* cave_elevator.c  —  English VWF floor labels for the elevator floor-select list.
 *
 * The elevator floor-button drawer FUN_080b9a4c (called twice from the floor-list renderer
 * FUN_080b9ba4) builds each row's label as Japanese building notation drawn at a FIXED 12px pitch:
 *     above ground : <full-width digits>階   ("２２階")
 *     basement     : 地下<full-width digits>階 ("地下３階")
 * digits come from the "0123456789" glyph table @0x0816567E (tokens 0xCC..0xD5), the 地下/階 prefixes
 * from the standalone strings @0x08165674 / @0x0816567A.  The digits are drawn one glyph at a time via
 * Font_DrawGlyphSprite at hardcoded X (0x9C, 0xA8, ...) and the kanji via Text_DrawSpriteString — so the
 * label reads "２２階" fixed-pitch, no VWF.
 *
 * We hook the drawer just after it has computed the row Y (r6) and stashed the floor record (r5),
 * before the JP draw branches, and rebuild the label as a single ASCII string in Western elevator
 * notation — "22F" above ground, "B3F" in the basement — drawn ONCE via Text_DrawSpriteString.  Every
 * glyph ('0'..'9' = 0xCC..0xD5, 'B' = 0xDE, 'F' = 0xE2) is in the English VWF range 0xBC..0x117, so the
 * patch_spritebuf renders Text_DrawSpriteString through the width table -> tight "22F".
 *
 * Compiled by devkitARM (Thumb, armv4t), injected by engine/script/patch_elevator.py.
 * Run after patch_spritebuf.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

#include "rommap.h"   /* RM_* address defines, generated from lib/rommap.py */

typedef void (*tds_fn)(const u16 *str, int p2, int p3, int x, int y, int pitch);
#define Text_DrawSpriteString ((tds_fn)(RM_Text_DrawSpriteString | 1))

#define G_ZERO 0xCC   /* glyph token for '0'; '0'..'9' run contiguously 0xCC..0xD5 */
#define G_B    0xDE   /* glyph token for 'B' (basement prefix) */
#define G_F    0xE2   /* glyph token for 'F' (floor suffix) */
#define LABEL_X 0x9C  /* stock left edge of the digit field */

/* rec = the per-floor record (signed floor number at +6; negative = basement); y = stock row Y (r6). */
__attribute__((used, noinline))
void elevator_floor_label(const void *rec, int y)
{
    s16 floor = *(const s16 *)((const u8 *)rec + 6);
    u16 buf[8];
    int n = 0;
    int a, d2 = 0, d1 = 0;

    if (floor < 0) { buf[n++] = G_B; a = -floor; }
    else           {              a = floor;     }

    /* digit split without '/'/'%' (the -Os -nostdlib build can't link __aeabi_uidiv) */
    while (a >= 100) { a -= 100; ++d2; }
    while (a >= 10)  { a -= 10;  ++d1; }
    if (d2)          buf[n++] = (u16)(G_ZERO + d2);
    if (d2 || d1)    buf[n++] = (u16)(G_ZERO + d1);
    buf[n++] = (u16)(G_ZERO + a);
    buf[n++] = G_F;
    buf[n]   = 0;

    Text_DrawSpriteString(buf, 0, 0, LABEL_X, y, 0xC);
}

/* Hooked at 0x080b9a70 (replaces `movs r1,#6 ; ldrsh r0,[r5,r1]`): r5 = floor record, r6 = row Y are
 * already set.  Draw the English label, then jump to the stock epilogue @0x080b9b94 (the JP draw
 * branches in between are now dead). */
__attribute__((naked, used, section(".text.entry")))
void cave_entry(void)
{
    __asm__ volatile(
        "mov  r0, r5                 \n"   /* floor record ptr */
        "mov  r1, r6                 \n"   /* row Y */
        "bl   elevator_floor_label   \n"
        "ldr  r0, =0x080b9b95        \n"   /* stock epilogue @0x080b9b94 | thumb */
        "bx   r0                     \n"
    );
}
