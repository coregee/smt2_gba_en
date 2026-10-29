/* cave_shopowned.c -- the shop "quantity owned" header (SELECT in a shop) -> English.
 *
 * SELECT on the shop item list or the "How many?" step toggles 0x030065E4; while it is set the
 * first 15 records of the message-window glyph list are replaced by a 13-glyph label written
 * straight from code, 選択中のアイテムの所持数, plus the two count digits that
 * MsgWindow_DrawItemCount writes into records 13/14.  Two writers: Shop_InitItemList
 * (0x08133B18, mode != 0) and sub_081305D8 (the toggle); the saved prompt tokens (0x03006820)
 * come back through the restore loops in the same two functions.
 *
 * Only the TOKENS of those records were rewritten, so in the English build the label (a) took the
 * x positions of the prompt's glyphs (the kanji, drawn on the stock path, overlapped), and (b) was
 * cut at the prompt's record count (9 for "How many?", so the count never showed).  The show hook
 * writes the English label (FARDATA_SHOPOWNED, 0 = blank slot) on one row at 13px appender steps
 * (cave_msgwin reflows such a run with the width table) and raises the count to 15; the restore
 * hooks put back the prompt's tokens, positions and count (saved at SHOP_OWNED_SAVE).
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#include <rommap.h>

typedef struct { u16 tok, x, y, flag; } Rec;
#define RECS   ((volatile Rec *)RM_MSG_GLYPH_LIST2)
#define COUNT  (*(volatile u16 *)RM_MSG_GLYPH_COUNT)
#define SAVED_TOKENS ((const volatile u16 *)0x03006820u)  /* prompt tokens 0..14 */
#define LABEL  ((const u16 *)RM_FARDATA_SHOPOWNED)         /* 13 tokens */
#define SAVE   ((volatile u16 *)RM_SHOP_OWNED_SAVE)        /* count, then x,y of records 0..14 */
#define NSLOT  15
#define NLABEL 13

__attribute__((used, section(".text.entry")))
void cave_entry(void) {}

static int label_shown(void)
{
    int k;
    if (COUNT != NSLOT)
        return 0;
    for (k = 0; k < NLABEL; ++k)
        if (RECS[k].tok != LABEL[k])
            return 0;
    return 1;
}

__attribute__((used, noinline))
void shop_owned_show(void)
{
    int k, m = 0;
    u16 x0, y0, f0;
    if (!label_shown()) {
        SAVE[0] = COUNT;
        for (k = 0; k < NSLOT; ++k) {
            SAVE[1 + 2 * k] = RECS[k].x;
            SAVE[2 + 2 * k] = RECS[k].y;
        }
    }
    x0 = SAVE[1];
    y0 = SAVE[2];
    f0 = RECS[0].flag;
    for (k = 0; k < NSLOT; ++k) {
        u16 t = k < NLABEL ? LABEL[k] : RECS[k].tok;   /* 13/14: the count digits */
        if (k < NLABEL)
            RECS[k].tok = t;
        RECS[k].x = x0 + 13 * m;     /* blank slots don't advance (cave_msgwin skips them) */
        RECS[k].y = y0;
        RECS[k].flag = f0;
        if (t != 0 || k >= NLABEL)
            ++m;
    }
    COUNT = NSLOT;
}

__attribute__((used, noinline))
void shop_owned_restore(void)
{
    int k, was = label_shown();
    for (k = 0; k < NSLOT; ++k)
        RECS[k].tok = SAVED_TOKENS[k];
    if (was) {
        for (k = 0; k < NSLOT; ++k) {
            RECS[k].x = SAVE[1 + 2 * k];
            RECS[k].y = SAVE[2 + 2 * k];
        }
        COUNT = SAVE[0];
    }
}

/* sub_081305D8 show: bl from 0x0813062E after the token save loop; resume at the count call. */
__attribute__((naked, used, section(".text.entry")))
void owned_show_veneer1(void)
{
    __asm__ volatile(
        "bl   shop_owned_show   \n"
        "ldr  r0, =0x08130671   \n"
        "bx   r0                \n"
    );
}

/* Shop_InitItemList show (mode != 0): bl from 0x08133B44; resume at the count call setup. */
__attribute__((naked, used, section(".text.entry")))
void owned_show_veneer2(void)
{
    __asm__ volatile(
        "bl   shop_owned_show   \n"
        "ldr  r0, =0x08133B87   \n"
        "bx   r0                \n"
    );
}

/* sub_081305D8 restore: bl from 0x081305E6; resume at the epilogue. */
__attribute__((naked, used, section(".text.entry")))
void owned_restore_veneer1(void)
{
    __asm__ volatile(
        "bl   shop_owned_restore \n"
        "ldr  r0, =0x08130677    \n"
        "bx   r0                 \n"
    );
}

/* Shop_InitItemList restore (mode 0): bl from 0x08133BBC; r5 = 15 as after the stock loop. */
__attribute__((naked, used, section(".text.entry")))
void owned_restore_veneer2(void)
{
    __asm__ volatile(
        "bl   shop_owned_restore \n"
        "movs r5, #15            \n"
        "ldr  r0, =0x08133BD9    \n"
        "bx   r0                 \n"
    );
}
