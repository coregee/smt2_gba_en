/* cave_extract.c -- the ex-appraiser's demon EXTRACTION / RETURN screen -> English VWF.
 *
 * Script op 0x445 sub-ops 0x1D (extract, list filter 0) / 0x1E (return, filter 1) open a record
 * list (task script 0x084F36B0) whose rows and cost prompt are drawn on the OBJ glyph cache
 * (FontSprite_DrawGlyph), fixed 12px pitch, straight from JP data:
 *
 *  (1) the LIST (drawer 0x080D4190, 6 rows at x=12, y=row*12+2): each row copies 8 glyphs of
 *      Demon_GetRecord(id)+0x22, the JP record name.  extract_list_veneer (bl @0x080D41E4)
 *      VWF-draws NAME_TABLE[id] instead (record name for untranslated ids and the party members'
 *      player-named records), then resumes at the row-loop tail @0x080D4216.
 *
 *  (2) the cost PROMPT (sub_080CF250): walks the string from literal 0x080CF2C4 (extract,
 *      0x0815BFEA) / 0x080CF2C0 (return, 0x0815C0AA): 0x0300 = new line back to x 0x12,
 *      0x0301 = end, 0x00CC = the Memory Chip cost (sub_080D45B8), 0x00CD = the macca price
 *      (Compendium_GetPrice), other codes drawn 12px apart.  patch_extract repoints the two
 *      literals at English strings using the same codes; extract_prompt_veneer (bl @0x080CF292,
 *      r6 = string, r7 = demon id) draws them with the width table and resumes at the epilogue.
 *      English prose must not contain the digits '0'/'1' (glyphs 0xCC/0xCD are the placeholders).
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#include <rommap.h>

typedef void (*fsg_fn)(u16 code, int p2, int p3, int x, int y);
typedef u8  *(*digits_fn)(u32 n);
typedef u32  (*cost_fn)(u16 id);
#define FontSprite_DrawGlyph ((fsg_fn)(RM_FontSprite_DrawGlyph | 1))
#define NumberToDigits       ((digits_fn)0x080A9CC1u)   /* 8 digits, least significant first */
#define Extract_GetChipCost  ((cost_fn)0x080D45B9u)     /* sub_080D45B8: Memory Chips needed */
#define Compendium_GetPrice  ((cost_fn)0x081571DDu)
#define DIGIT_GLYPHS ((const u16 *)0x084F0EACu)         /* '0'..'9' = 0xCC..0xD5 */
#define WIDTH_TBL  ((const u8 *)RM_WIDTH_TABLE)
#define NAME_TABLE ((const u16 *const *)RM_NAME_TABLE)
#define LIST_IDS   ((const u16 *)0x0203B454u)           /* the list's demon ids */

#define LIST_X     12
#define LIST_XMAX  0x78     /* the scroll arrows sit at x 0x7A */
#define PROMPT_X   0x12
#define PROMPT_Y   0x5B

__attribute__((used, section(".text.entry")))
void cave_entry(void) {}

static int adv(u16 g) { return (g >= RM_ENG_LO && g < RM_ENG_HI) ? WIDTH_TBL[g] : 12; }

static int draw_number(u32 n, int x, int y)
{
    const u8 *d = NumberToDigits(n);
    int i, shown = 0;
    for (i = 7; i >= 0; --i) {
        if (shown || d[i] != 0 || i == 0) {
            u16 g = DIGIT_GLYPHS[d[i]];
            FontSprite_DrawGlyph(g, 0, 0, x, y);
            x += adv(g);
            shown = 1;
        }
    }
    return x;
}

__attribute__((used, noinline))
void extract_prompt(const u16 *s, u16 demon)
{
    int x = PROMPT_X, y = PROMPT_Y;
    for (; *s != 0x0301 && *s != 0; ++s) {
        u16 g = *s;
        if (g == 0x0300) {
            x = PROMPT_X;
            y += 12;
        } else if (g == 0x00CC) {
            x = draw_number(Extract_GetChipCost(demon), x, y);
        } else if (g == 0x00CD) {
            x = draw_number(Compendium_GetPrice(demon), x, y);
        } else {
            if (g != RM_ENG_LO)                      /* spaces take width, not a cache cell */
                FontSprite_DrawGlyph(g, 0, 0, x, y);
            x += adv(g);
        }
    }
}

/* list row: r9 = &list (task data+0x24: +0x0A top), r4 = row, r0 = Demon_GetRecord(id) (a copy). */
__attribute__((used, noinline))
void extract_list_name(const u16 *list, u32 row, const u8 *rec)
{
    u16 id = LIST_IDS[list[5] + row];
    const u16 *s = (const u16 *)(rec + 0x22);
    int x = LIST_X, y = row * 12 + 2, i, n = 8;
    /* party members' records (0x106/0x108/0x109/0x10C/0x10E) carry the player's names */
    int player = id == 0x106 || id == 0x108 || id == 0x109 || id == 0x10C || id == 0x10E;
    if (!player && id < RM_NAME_COUNT && NAME_TABLE[id]) {
        s = NAME_TABLE[id];
        n = 24;
    }
    for (i = 0; i < n; ++i) {
        u16 g = s[i];
        int w;
        if (g == 0 || g == 0x0301)
            break;
        w = adv(g);
        if (x + w > LIST_XMAX)
            break;
        if (g != RM_ENG_LO)
            FontSprite_DrawGlyph(g, 0, 0, x, y);
        x += w;
    }
}

/* bl from 0x080D41E4 (replacing `movs r6,#0 ; lsls r1,r4,#1`); r8 = row+1 is already set for the
 * row-loop tail @0x080D4216. */
__attribute__((naked, used, section(".text.entry")))
void extract_list_veneer(void)
{
    __asm__ volatile(
        "mov  r2, r0            \n"   /* arg3 = record copy */
        "mov  r1, r4            \n"   /* arg2 = row         */
        "mov  r0, r9            \n"   /* arg1 = list        */
        "bl   extract_list_name \n"
        "ldr  r0, =0x080D4217   \n"
        "bx   r0                \n"
    );
}

/* bl from 0x080CF292 (replacing `movs r4,#0x12 ; movs r5,#0x5b`): r6 = message, r7 = demon id. */
__attribute__((naked, used, section(".text.entry")))
void extract_prompt_veneer(void)
{
    __asm__ volatile(
        "mov  r1, r7            \n"
        "mov  r0, r6            \n"
        "bl   extract_prompt    \n"
        "ldr  r0, =0x080CF313   \n"   /* epilogue */
        "bx   r0                \n"
    );
}
