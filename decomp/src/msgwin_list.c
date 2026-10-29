/* Script message window: drawing the item list (names queued as glyphs) and its input. */

#include "global.h"
#include "bmenu2.h"

extern u16 *gScriptBase;
extern u16 gUnk_030069CC;
extern u16 gUnk_03006670;           /* 1 in battle */
extern u16 gUnk_030068B8;
extern const u16 gUnknown_0878FBA4[][16];  /* per list layout: (x, y) of each row, 0xFFFF-ended */
extern const u16 gUnknown_0878FC64[];      /* y of the three price slots */
/* name pointer tables, stored as halfword pairs (not word aligned) */
extern const u16 gUnknown_08036156[];
extern const u16 gUnknown_0803631E[];
extern const u16 gUnknown_08036666[];

u16 sub_0812F188(u16 i);
void MsgWindow_RestoreGlyphs(void);

struct MsgPriceSlot     /* gUnk_03006620: number sprites drawn by ScriptVM_DrawTask */
{
    u16 active;
    u16 pad2;
    u32 value;
    u16 unk8;
    u16 y;
    u16 attr;
    u16 padE;
};

/* Queues the names of the list entries 0x0203DB88[0x03006940...] (0xFFFF-ended, at most 8)
   as glyphs, one row per layout position. A name is a 0x301-ended glyph string reached
   through a pointer table (0x08036666 inside a sub-script, 0x08036156 in battle, else
   0x0803631E), drawn with a fixed 13-pixel advance. Layout 4 (shop) also shows each price
   in a number slot and greys out (attr 4) what the money does not cover. All rows share
   the 64-entry glyph queue: past that, every further glyph overwrites entry 63. */
/* NONMATCHING: same logic; the original keeps more values in stack slots (the zero price
   among them) and allocates the loop registers differently. */
// MsgWindow_DrawItemList @ 0x0812F2B4
#ifdef NONMATCHING
void MsgWindow_DrawItemList(u16 layout)
{
    u16 pos = 0;
    u32 price = 0;      /* also the zero stored below (the original reloads it from the stack) */
    u32 money = Money_Get();
    u16 entry;
    u16 *saved;
    s16 row;

    gUnk_030068B8 = 10;
    entry = gUnk_03006940;
    saved = gScriptBase;
    gMsgGlyphCount = price;
    gTextColumn = price;
    gTextLine = price;
    gUnk_0203DB4A = price;
    Font_ResetGlyphSpriteCache(0x180);
    if ((s16)gUnk_03006844 == 1 || (s16)gUnk_03006844 == 3 || (s16)gUnk_03006844 == 4)
        MsgWindow_RestoreGlyphs();
    row = 0;
    if (gUnk_0203DB88[entry] == 0xFFFF)
        goto done;
    while (gUnknown_0878FBA4[layout][pos] != 0xFFFF)
    {
        u16 x;
        u16 y;
        u16 attr;
        u16 k;
        u16 g;
        u16 id;
        const u16 *tbl;

        x = gUnknown_0878FBA4[layout][pos++];
        y = gUnknown_0878FBA4[layout][pos++];
        if (gUnk_030069CC)
            gScriptBase = (u16 *)gUnknown_08036666;
        else if (gUnk_03006670 == 1)
            gScriptBase = (u16 *)gUnknown_08036156;
        else
            gScriptBase = (u16 *)gUnknown_0803631E;
        id = gUnk_0203DB88[entry];
        tbl = &gScriptBase[(id & 0x7FFF) * 2];
        gScriptBase = (u16 *)(tbl[0] | (tbl[1] << 16));
        k = 0;
        attr = 0;
        if ((s16)gUnk_03006844 == 4)
        {
            price = sub_0812F188(id - 0x9D);
            if (money < price)
                attr = 4;
        }
        while ((g = gScriptBase[k++]) != 0x301)
        {
            u16 q = gMsgGlyphCount * 4;
            gMsgGlyphQueue[q++] = g;
            gMsgGlyphQueue[q++] = x;
            gMsgGlyphQueue[q++] = y;
            gMsgGlyphQueue[q++] = attr;
            if (++gMsgGlyphCount > 0x3F)
                gMsgGlyphCount = 0x3F;
            x += 13;
        }
        if ((s16)gUnk_03006844 == 4 && row < 3)
        {
            struct MsgPriceSlot *slot = &((struct MsgPriceSlot *)gUnk_03006620)[row];
            slot->active = 1;
            slot->value = price;
            slot->unk8 = 0x80;
            slot->y = gUnknown_0878FC64[row];
            slot->attr = attr;
        }
        entry++;
        if (++row > 7 || gUnk_0203DB88[entry] == 0xFFFF)
            break;
    }
done:
    gScriptBase = saved;
}
#else
NAKED
void MsgWindow_DrawItemList(u16 layout)
{
    asm_unified(
        ".L0812F2B4:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x1c\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    movs r0, #0\n"
        "    str r0, [sp]\n"
        "    movs r1, #0\n"
        "    str r1, [sp, #0xc]\n"
        "    bl Money_Get\n"
        "    str r0, [sp, #0x10]\n"
        "    ldr r1, .L0812F38C\n"
        "    movs r0, #0xa\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L0812F390\n"
        "    ldrh r4, [r0]\n"
        "    ldr r0, .L0812F394\n"
        "    ldr r0, [r0]\n"
        "    str r0, [sp, #8]\n"
        "    ldr r0, .L0812F398\n"
        "    mov r2, sp\n"
        "    ldrh r2, [r2, #0xc]\n"
        "    strh r2, [r0]\n"
        "    ldr r0, .L0812F39C\n"
        "    mov r3, sp\n"
        "    ldrh r3, [r3, #0xc]\n"
        "    strh r3, [r0]\n"
        "    ldr r0, .L0812F3A0\n"
        "    mov r5, sp\n"
        "    ldrh r5, [r5, #0xc]\n"
        "    strh r5, [r0]\n"
        "    ldr r0, .L0812F3A4\n"
        "    mov r7, sp\n"
        "    ldrh r7, [r7, #0xc]\n"
        "    strh r7, [r0]\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #1\n"
        "    bl Font_ResetGlyphSpriteCache\n"
        "    ldr r0, .L0812F3A8\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    cmp r0, #1\n"
        "    beq .L0812F31C\n"
        "    cmp r0, #3\n"
        "    beq .L0812F31C\n"
        "    cmp r0, #4\n"
        "    bne .L0812F320\n"
        ".L0812F31C:\n"
        "    bl MsgWindow_RestoreGlyphs\n"
        ".L0812F320:\n"
        "    movs r2, #0\n"
        "    mov sb, r2\n"
        "    ldr r1, .L0812F3AC\n"
        "    lsls r2, r4, #1\n"
        "    adds r0, r2, r1\n"
        "    ldrh r0, [r0]\n"
        "    ldr r3, .L0812F3B0\n"
        "    adds r5, r1, #0\n"
        "    cmp r0, r3\n"
        "    bne .L0812F336\n"
        "    b .L0812F50C\n"
        ".L0812F336:\n"
        "    lsls r6, r6, #5\n"
        "    str r6, [sp, #0x14]\n"
        ".L0812F33A:\n"
        "    ldr r3, [sp]\n"
        "    lsls r0, r3, #1\n"
        "    ldr r7, [sp, #0x14]\n"
        "    adds r0, r0, r7\n"
        "    ldr r1, .L0812F3B4\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    ldr r7, .L0812F3B0\n"
        "    cmp r0, r7\n"
        "    bne .L0812F350\n"
        "    b .L0812F50C\n"
        ".L0812F350:\n"
        "    adds r0, r3, #0\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp]\n"
        "    adds r1, r0, #0\n"
        "    lsls r0, r3, #1\n"
        "    ldr r3, [sp, #0x14]\n"
        "    adds r0, r0, r3\n"
        "    ldr r7, .L0812F3B4\n"
        "    adds r0, r0, r7\n"
        "    ldrh r6, [r0]\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp]\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r3\n"
        "    adds r1, r1, r7\n"
        "    ldrh r1, [r1]\n"
        "    str r1, [sp, #4]\n"
        "    ldr r0, .L0812F3B8\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    beq .L0812F3C0\n"
        "    ldr r0, .L0812F3BC\n"
        "    ldr r1, .L0812F394\n"
        "    str r0, [r1]\n"
        "    b .L0812F3E2\n"
        "    .byte 0x00, 0x00\n"
        ".L0812F38C: .4byte 0x030068B8 @ IWRAM+0x68B8\n"
        ".L0812F390: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812F394: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L0812F398: .4byte 0x0203DB3E @ EWRAM+0x3DB3E\n"
        ".L0812F39C: .4byte 0x0203DB38 @ EWRAM+0x3DB38\n"
        ".L0812F3A0: .4byte 0x0203DB3A @ EWRAM+0x3DB3A\n"
        ".L0812F3A4: .4byte 0x0203DB4A @ EWRAM+0x3DB4A\n"
        ".L0812F3A8: .4byte 0x03006844 @ IWRAM+0x6844\n"
        ".L0812F3AC: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L0812F3B0: .4byte 0x0000FFFF\n"
        ".L0812F3B4: .4byte gUnknown_0878FBA4\n"
        ".L0812F3B8: .4byte 0x030069CC @ IWRAM+0x69CC\n"
        ".L0812F3BC: .4byte gUnknown_08036666\n"
        ".L0812F3C0:\n"
        "    ldr r0, .L0812F3D0\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #1\n"
        "    bne .L0812F3DC\n"
        "    ldr r0, .L0812F3D4\n"
        "    ldr r3, .L0812F3D8\n"
        "    str r0, [r3]\n"
        "    b .L0812F3E2\n"
        ".L0812F3D0: .4byte 0x03006670 @ IWRAM+0x6670\n"
        ".L0812F3D4: .4byte gUnknown_08036156\n"
        ".L0812F3D8: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L0812F3DC:\n"
        "    ldr r0, .L0812F524\n"
        "    ldr r7, .L0812F528\n"
        "    str r0, [r7]\n"
        ".L0812F3E2:\n"
        "    adds r0, r2, r5\n"
        "    ldrh r3, [r0]\n"
        "    lsls r0, r3, #0x11\n"
        "    ldr r2, .L0812F528\n"
        "    ldr r1, [r2]\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r1\n"
        "    ldrh r1, [r0]\n"
        "    ldrh r0, [r0, #2]\n"
        "    lsls r0, r0, #0x10\n"
        "    orrs r0, r1\n"
        "    str r0, [r2]\n"
        "    movs r0, #0\n"
        "    str r0, [sp, #0x18]\n"
        "    mov r8, r0\n"
        "    ldr r0, .L0812F52C\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    cmp r0, #4\n"
        "    bne .L0812F422\n"
        "    adds r0, r3, #0\n"
        "    subs r0, #0x9d\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl sub_0812F188\n"
        "    str r0, [sp, #0xc]\n"
        "    ldr r2, [sp, #0x10]\n"
        "    cmp r2, r0\n"
        "    bhs .L0812F422\n"
        "    movs r3, #4\n"
        "    mov r8, r3\n"
        ".L0812F422:\n"
        "    ldr r1, [sp, #0x18]\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0x18]\n"
        "    ldr r2, .L0812F528\n"
        "    ldr r0, [r2]\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r0\n"
        "    ldrh r3, [r1]\n"
        "    ldr r0, .L0812F530\n"
        "    mov r5, sb\n"
        "    lsls r5, r5, #0x10\n"
        "    mov ip, r5\n"
        "    adds r4, #1\n"
        "    mov sl, r4\n"
        "    cmp r3, r0\n"
        "    beq .L0812F4AE\n"
        "    ldr r5, .L0812F534\n"
        "    ldr r4, .L0812F538\n"
        "    mov sb, r0\n"
        ".L0812F44C:\n"
        "    ldrh r2, [r5]\n"
        "    lsls r0, r2, #0x12\n"
        "    lsrs r0, r0, #0x10\n"
        "    movs r1, #1\n"
        "    orrs r1, r0\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r4\n"
        "    strh r3, [r0]\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r4\n"
        "    strh r6, [r1]\n"
        "    movs r7, #0x80\n"
        "    lsls r7, r7, #9\n"
        "    adds r1, r0, r7\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r4\n"
        "    mov r3, sp\n"
        "    ldrh r3, [r3, #4]\n"
        "    strh r3, [r0]\n"
        "    lsrs r1, r1, #0xf\n"
        "    adds r1, r1, r4\n"
        "    mov r7, r8\n"
        "    strh r7, [r1]\n"
        "    adds r2, #1\n"
        "    strh r2, [r5]\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    cmp r2, #0x3f\n"
        "    bls .L0812F48E\n"
        "    movs r0, #0x3f\n"
        "    strh r0, [r5]\n"
        ".L0812F48E:\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0xd\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldr r1, [sp, #0x18]\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0x18]\n"
        "    ldr r2, .L0812F528\n"
        "    ldr r0, [r2]\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r0\n"
        "    ldrh r3, [r1]\n"
        "    cmp r3, sb\n"
        "    bne .L0812F44C\n"
        ".L0812F4AE:\n"
        "    ldr r3, .L0812F52C\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r3, r5]\n"
        "    cmp r0, #4\n"
        "    bne .L0812F4E4\n"
        "    mov r7, ip\n"
        "    asrs r4, r7, #0x10\n"
        "    cmp r4, #2\n"
        "    bgt .L0812F4E4\n"
        "    ldr r1, .L0812F53C\n"
        "    lsls r2, r4, #4\n"
        "    adds r3, r2, r1\n"
        "    movs r0, #1\n"
        "    strh r0, [r3]\n"
        "    adds r1, #4\n"
        "    adds r2, r2, r1\n"
        "    ldr r0, [sp, #0xc]\n"
        "    str r0, [r2]\n"
        "    movs r0, #0x80\n"
        "    strh r0, [r3, #8]\n"
        "    ldr r1, .L0812F540\n"
        "    lsls r0, r4, #1\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r3, #0xa]\n"
        "    mov r1, r8\n"
        "    strh r1, [r3, #0xc]\n"
        ".L0812F4E4:\n"
        "    mov r2, sl\n"
        "    lsls r0, r2, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #9\n"
        "    add r0, ip\n"
        "    lsrs r3, r0, #0x10\n"
        "    mov sb, r3\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #7\n"
        "    bgt .L0812F50C\n"
        "    ldr r1, .L0812F544\n"
        "    lsls r2, r4, #1\n"
        "    adds r0, r2, r1\n"
        "    ldrh r0, [r0]\n"
        "    adds r5, r1, #0\n"
        "    ldr r7, .L0812F548\n"
        "    cmp r0, r7\n"
        "    beq .L0812F50C\n"
        "    b .L0812F33A\n"
        ".L0812F50C:\n"
        "    ldr r0, [sp, #8]\n"
        "    ldr r1, .L0812F528\n"
        "    str r0, [r1]\n"
        "    add sp, #0x1c\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L0812F524: .4byte gUnknown_0803631E\n"
        ".L0812F528: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L0812F52C: .4byte 0x03006844 @ IWRAM+0x6844\n"
        ".L0812F530: .4byte 0x00000301\n"
        ".L0812F534: .4byte 0x0203DB3E @ EWRAM+0x3DB3E\n"
        ".L0812F538: .4byte 0x0203D800 @ EWRAM+0x3D800\n"
        ".L0812F53C: .4byte 0x03006620 @ IWRAM+0x6620\n"
        ".L0812F540: .4byte gUnknown_0878FC64\n"
        ".L0812F544: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L0812F548: .4byte 0x0000FFFF\n"
    );
}
#endif


#define ROW (*(s16 *)&gUnk_0300696C)
#define TOP (*(s16 *)&gUnk_03006940)
#define MODE ((s16)gUnk_03006844)
#define LIST gUnk_0203DB88
#define END 0xFFFF

extern s16 gUnk_03006604;   /* entry count (the wrap-around cases treat it as the last row) */
void sub_0812F010(void);

/* Wait handler of the item list drawn by MsgWindow_DrawItemList. Layouts (0x03006844): 0 = 4 rows,
   1 and 4 = 3 rows (4: shop, with prices), 2 = 2 columns x 4 rows, 3 = 2 columns x 3 rows;
   in the 2-column layouts even rows are the left column. Up/down move (and scroll; the
   1-column layouts wrap when the whole list fits), left/right switch columns, L/R move a
   page. Scrolling redraws the list (MsgWindow_DrawItemList); every move plays SE 100 and updates the
   paging arrows (sub_0812F010). A takes the entry (gUnk_030065E0, wait state 0x19 when it
   was 0x18, else 0x0E); B, outside battle, cancels (wait state 0x37 or 0x1C). */
/* NONMATCHING: the original (0xC0A bytes, with long branches to its shared tails) repeats
   much of the per-layout code that is shared here. */
// MsgWindow_ItemListInput @ 0x0812F54C
#ifdef NONMATCHING
void MsgWindow_ItemListInput(struct Task *task)
{
    u16 k;
    s32 n;
    s16 last;

    gUnk_0300689C = gUnknown_0878FBA4[MODE][ROW * 2];
    gUnk_0300695C = gUnknown_0878FBA4[MODE][ROW * 2 + 1];
    if ((u16)(gUnk_03006844 - 2) <= 1)
        gUnk_030066A0 = 10;
    else if (MODE == 4)
        gUnk_030066A0 = 0x14;
    else
        gUnk_030066A0 = 0x13;
    gUnk_03006958 = 1;

    if (gRepeatedKeys & 0x200)
    {
        /* L: to the first row, then a page up */
        if (MODE == 0)
        {
            if (gUnk_03006604 <= 3)
                goto done;
            if (ROW != 0)
            {
                ROW = 0;
                goto sound;
            }
            if (TOP == 0)
                goto done;
            TOP = (TOP - 4 >= 0) ? TOP - 4 : 0;
            goto redraw;
        }
        else if (MODE == 4 || MODE == 1)
        {
            if (gUnk_03006604 <= 2)
                goto done;
            if (ROW != 0)
            {
                ROW = 0;
                goto sound;
            }
            if (TOP == 0)
                goto done;
            TOP = (TOP - 3 >= 0) ? TOP - 3 : 0;
            goto redraw;
        }
        else if (MODE == 2 || MODE == 3)
        {
            if (gUnk_03006604 <= (MODE == 2 ? 7 : 5))
                goto done;
            if ((u16)ROW <= 1)
            {
                if (TOP == 0)
                    goto done;
                TOP = (TOP - 6 >= 0) ? TOP - 6 : 0;
                goto redraw;
            }
            ROW = (ROW & 1) ? 1 : 0;
            goto sound;
        }
        goto done;
    }
    else if (gRepeatedKeys & 0x100)
    {
        /* R: to the last row, then a page down */
        if (MODE == 0)
        {
            if (gUnk_03006604 <= 3)
                goto done;
            if (ROW != 3)
            {
                ROW = 3;
                goto sound;
            }
            if (ROW + TOP == gUnk_03006604)
                goto done;
            if (ROW + TOP < gUnk_03006604 - 3)
                TOP += 4;
            else
                TOP = gUnk_03006604 - 3;
            goto redraw;
        }
        else if (MODE == 4 || MODE == 1)
        {
            if (gUnk_03006604 <= 2)
                goto done;
            if (ROW != 2)
            {
                ROW = 2;
                goto sound;
            }
            if (ROW + TOP == gUnk_03006604)
                goto done;
            if (ROW + TOP < gUnk_03006604 - 2)
                TOP += 3;
            else
                TOP = gUnk_03006604 - 2;
            goto redraw;
        }
        else if (MODE == 2)
        {
            if (gUnk_03006604 <= 7)
                goto done;
            if (ROW == 7)
            {
                for (k = 2; k <= 7; k += 2)
                {
                    if (LIST[TOP + ROW + k] == END)
                    {
                        if (k == 2 && LIST[TOP + ROW + 1] != END)
                        {
                            ROW--;
                            TOP += 2;
                            goto redraw;
                        }
                        k -= 2;
                        break;
                    }
                }
                if (k == 0)
                    goto done;
                TOP += k;
                goto redraw;
            }
            if (ROW == 6)
            {
                k = 2;
                if (LIST[TOP + 8] == END)
                    goto done;
                do
                {
                    k += 2;
                    if (k > 7)
                        goto page2;
                } while (LIST[TOP + 6 + k] != END);
                k -= 2;
            page2:
                if (k == 0)
                    goto done;
                TOP += k;
                goto redraw;
            }
            if (ROW == 0 || ROW == 2 || ROW == 4)
            {
                if (LIST[TOP + 6] != END)
                    ROW = 6;
                else if (LIST[TOP + 4] != END && ROW <= 3)
                    ROW = 4;
                else if (LIST[TOP + 2] != END && ROW <= 1)
                    ROW = 2;
                else
                    goto done;
            }
            else
            {
                if (LIST[TOP + 7] != END)
                    ROW = 7;
                else if (LIST[TOP + 5] != END && ROW <= 4)
                    ROW = 5;
                else if (LIST[TOP + 3] != END && ROW <= 2)
                    ROW = 3;
                else if (LIST[TOP + ROW + 1] != END)
                    ROW++;
                else
                    goto done;
            }
            goto sound;
        }
        else if (MODE == 3)
        {
            if (gUnk_03006604 <= 5)
                goto done;
            if (ROW == 5)
            {
                for (k = 2; k < 8; k += 2)
                {
                    if (LIST[TOP + 5 + k] == END)
                    {
                        if (k == 2 && LIST[TOP + 6] != END)
                        {
                            ROW = 4;
                            TOP += 2;
                            goto redraw;
                        }
                        k -= 2;
                        break;
                    }
                }
                if (k == 8)
                    k = 6;
                if (k == 0)
                    goto done;
                TOP += k;
                goto redraw;
            }
            if (ROW == 4)
            {
                k = 2;
                if (LIST[TOP + 6] == END)
                    k = 0;
                else
                {
                    do
                    {
                        k += 2;
                        if (k > 7)
                            goto page3;
                    } while (LIST[TOP + 4 + k] != END);
                    k -= 2;
                }
            page3:
                if (k == 8)
                    k = 6;
                if (k == 0)
                    goto done;
                TOP += k;
                goto redraw;
            }
            if (ROW == 0 || ROW == 2)
            {
                if (LIST[TOP + 4] != END)
                    ROW = 4;
                else if (LIST[TOP + 2] != END && ROW <= 1)
                    ROW = 2;
                else
                    goto done;
            }
            else
            {
                if (LIST[TOP + 5] != END)
                    ROW = 5;
                else if (LIST[TOP + 3] != END && ROW <= 2)
                    ROW = 3;
                else if (LIST[TOP + ROW + 1] != END)
                    ROW++;
                else
                    goto done;
            }
            goto sound;
        }
        goto done;
    }
    else if (gRepeatedKeys & 0x40)
    {
        /* up */
        if ((u16)gUnk_03006844 < 2 || MODE == 4)
        {
            if (ROW != 0)
            {
                ROW--;
                goto sound;
            }
            if (TOP != 0)
                TOP--;
            else if (MODE == 0)
            {
                if (gUnk_03006604 > 3)
                    goto done;
                ROW = gUnk_03006604;
            }
            else
            {
                if ((MODE != 1 && MODE != 4) || gUnk_03006604 > 2)
                    goto done;
                ROW = gUnk_03006604;
            }
            goto redraw;
        }
        if ((u16)ROW < 2)
        {
            if (TOP < 2)
                goto done;
            TOP -= 2;
            goto redraw;
        }
        ROW -= 2;
        goto sound;
    }
    else if (gRepeatedKeys & 0x80)
    {
        /* down */
        if (MODE == 0)
        {
            if (gUnk_03006604 < 3)
            {
                if (ROW == gUnk_03006604)
                    ROW = 0;
                else
                    ROW++;
                goto sound;
            }
            if (ROW != 3)
            {
                ROW++;
                goto sound;
            }
            if (LIST[TOP + 4] != END)
                TOP++;
            else
            {
                if (gUnk_03006604 != 3)
                    goto done;
                ROW = 0;
            }
            goto redraw;
        }
        else if (MODE == 1 || MODE == 4)
        {
            if (gUnk_03006604 < 2)
            {
                if (ROW == gUnk_03006604)
                {
                    if (MODE != 1)
                        goto done;
                    ROW = 0;
                }
                else
                    ROW++;
                goto sound;
            }
            if (ROW != 2)
            {
                ROW++;
                goto sound;
            }
            if (LIST[TOP + 3] != END)
            {
                TOP++;
                goto redraw;
            }
            if ((MODE != 1 && MODE != 4) || gUnk_03006604 != 2)
                goto done;
            ROW = 0;
            goto sound;
        }
        else if (MODE == 2 || MODE == 3)
        {
            /* the last row is 7 (layout 2) or 5 (layout 3) */
            last = (MODE == 2) ? 7 : 5;
            if (gUnk_03006604 < last)
            {
                if (LIST[TOP + ROW + 2] == END)
                    goto done;
                ROW += 2;
                goto sound;
            }
            if (ROW > last - 2)
            {
                n = TOP + ROW;
                if (n > 15)
                    goto done;
                if (LIST[n + 2] == END)
                {
                    if (ROW != last || LIST[n + 1] == END)
                        goto done;
                    ROW--;
                }
                TOP += 2;
                goto redraw;
            }
            if (LIST[TOP + ROW + 2] == END)
            {
                if (ROW != last || LIST[TOP + ROW + 1] == END)
                    goto done;
                ROW++;
            }
            else
                ROW += 2;
            goto sound;
        }
        goto done;
    }
    else if (gRepeatedKeys & 0x20)
    {
        /* left: from the right column, or wrapping from the left one */
        if ((u16)(gUnk_03006844 - 2) > 1)
            goto done;
        if (ROW == 1 || ROW == 3 || ROW == 5 || ROW == 7)
            ROW--;
        else
        {
            if (TOP + ROW >= gUnk_03006604)
                goto done;
            ROW++;
        }
        goto sound;
    }
    else if (gRepeatedKeys & 0x10)
    {
        /* right */
        if ((u16)(gUnk_03006844 - 2) > 1)
            goto done;
        if (ROW == 0 || ROW == 2 || ROW == 4 || ROW == 6)
        {
            if (TOP + ROW >= gUnk_03006604)
                goto done;
            ROW++;
        }
        else
            ROW--;
        goto sound;
    }
    else if (gNewKeys & 1)
    {
        task->result = 1;
        Sound_Play(0x65);
        gUnk_030065E0 = LIST[TOP + ROW];
        if ((s16)gScriptWaitState == 0x18)
            gScriptWaitState = 0x19;
        else
            gScriptWaitState = 0x0E;
        goto done;
    }
    else if ((gNewKeys & 2) && gUnk_03006670 == 0)
    {
        task->result = 1;
        Sound_Play(0x66);
        if ((s16)gScriptWaitState == 0x18)
            gScriptWaitState = 0x37;
        else
            gScriptWaitState = 0x1C;
    }
    goto done;
redraw:
    MsgWindow_DrawItemList(gUnk_03006844);
sound:
    Sound_Play(100);
done:
    sub_0812F010();
}
#else
NAKED
void MsgWindow_ItemListInput(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sb\n"
        "    mov r6, r8\n"
        "    push {r6, r7}\n"
        "    mov r8, r0\n"
        "    ldr r4, .L0812F5A4\n"
        "    ldr r5, .L0812F5A8\n"
        "    ldr r3, .L0812F5AC\n"
        "    movs r0, #0\n"
        "    ldrsh r1, [r3, r0]\n"
        "    lsls r1, r1, #2\n"
        "    ldr r2, .L0812F5B0\n"
        "    movs r6, #0\n"
        "    ldrsh r0, [r2, r6]\n"
        "    lsls r0, r0, #5\n"
        "    adds r1, r1, r0\n"
        "    adds r1, r1, r5\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r4]\n"
        "    ldr r4, .L0812F5B4\n"
        "    movs r7, #0\n"
        "    ldrsh r0, [r3, r7]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #1\n"
        "    movs r6, #0\n"
        "    ldrsh r1, [r2, r6]\n"
        "    lsls r1, r1, #5\n"
        "    adds r0, r0, r1\n"
        "    adds r0, r0, r5\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r4]\n"
        "    ldrh r1, [r2]\n"
        "    subs r0, r1, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    adds r6, r3, #0\n"
        "    mov ip, r2\n"
        "    cmp r0, #1\n"
        "    bhi .L0812F5BC\n"
        "    ldr r1, .L0812F5B8\n"
        "    movs r0, #0xa\n"
        "    b .L0812F5D4\n"
        "    .byte 0x00, 0x00\n"
        ".L0812F5A4: .4byte 0x0300689C @ IWRAM+0x689C\n"
        ".L0812F5A8: .4byte gUnknown_0878FBA4\n"
        ".L0812F5AC: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L0812F5B0: .4byte 0x03006844 @ IWRAM+0x6844\n"
        ".L0812F5B4: .4byte 0x0300695C @ IWRAM+0x695C\n"
        ".L0812F5B8: .4byte 0x030066A0 @ IWRAM+0x66A0\n"
        ".L0812F5BC:\n"
        "    lsls r0, r1, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #4\n"
        "    bne .L0812F5D0\n"
        "    ldr r1, .L0812F5CC\n"
        "    movs r0, #0x14\n"
        "    b .L0812F5D4\n"
        "    .byte 0x00, 0x00\n"
        ".L0812F5CC: .4byte 0x030066A0 @ IWRAM+0x66A0\n"
        ".L0812F5D0:\n"
        "    ldr r1, .L0812F614\n"
        "    movs r0, #0x13\n"
        ".L0812F5D4:\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L0812F618\n"
        "    movs r2, #1\n"
        "    strh r2, [r0]\n"
        "    ldr r0, .L0812F61C\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L0812F5EC\n"
        "    b .L0812F780\n"
        ".L0812F5EC:\n"
        "    mov r7, ip\n"
        "    movs r0, #0\n"
        "    ldrsh r1, [r7, r0]\n"
        "    cmp r1, #0\n"
        "    bne .L0812F64E\n"
        "    ldr r0, .L0812F620\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r0, r2]\n"
        "    cmp r0, #3\n"
        "    bgt .L0812F604\n"
        "    bl .L08130146\n"
        ".L0812F604:\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r6, r3]\n"
        "    cmp r0, #0\n"
        "    beq .L0812F624\n"
        "    strh r1, [r6]\n"
        "    bl .L0813013A\n"
        "    .byte 0x00, 0x00\n"
        ".L0812F614: .4byte 0x030066A0 @ IWRAM+0x66A0\n"
        ".L0812F618: .4byte 0x03006958 @ IWRAM+0x6958\n"
        ".L0812F61C: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L0812F620: .4byte 0x03006604 @ IWRAM+0x6604\n"
        ".L0812F624:\n"
        "    ldr r2, .L0812F640\n"
        "    ldrh r3, [r2]\n"
        "    movs r4, #0\n"
        "    ldrsh r0, [r2, r4]\n"
        "    cmp r0, #0\n"
        "    bne .L0812F634\n"
        "    bl .L08130146\n"
        ".L0812F634:\n"
        "    subs r0, #4\n"
        "    cmp r0, #0\n"
        "    blt .L0812F644\n"
        "    subs r0, r3, #4\n"
        "    strh r0, [r2]\n"
        "    b .L0812F646\n"
        ".L0812F640: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812F644:\n"
        "    strh r1, [r2]\n"
        ".L0812F646:\n"
        "    mov r6, ip\n"
        "    ldrh r0, [r6]\n"
        "    bl .L08130136\n"
        ".L0812F64E:\n"
        "    cmp r1, #4\n"
        "    beq .L0812F656\n"
        "    cmp r1, #1\n"
        "    bne .L0812F6A2\n"
        ".L0812F656:\n"
        "    ldr r0, .L0812F674\n"
        "    movs r7, #0\n"
        "    ldrsh r0, [r0, r7]\n"
        "    cmp r0, #2\n"
        "    bgt .L0812F664\n"
        "    bl .L08130146\n"
        ".L0812F664:\n"
        "    movs r0, #0\n"
        "    ldrsh r2, [r6, r0]\n"
        "    cmp r2, #0\n"
        "    beq .L0812F678\n"
        "    movs r0, #0\n"
        "    strh r0, [r6]\n"
        "    bl .L0813013A\n"
        ".L0812F674: .4byte 0x03006604 @ IWRAM+0x6604\n"
        ".L0812F678:\n"
        "    ldr r1, .L0812F694\n"
        "    ldrh r3, [r1]\n"
        "    movs r4, #0\n"
        "    ldrsh r0, [r1, r4]\n"
        "    cmp r0, #0\n"
        "    bne .L0812F688\n"
        "    bl .L08130146\n"
        ".L0812F688:\n"
        "    subs r0, #3\n"
        "    cmp r0, #0\n"
        "    blt .L0812F698\n"
        "    subs r0, r3, #3\n"
        "    strh r0, [r1]\n"
        "    b .L0812F69A\n"
        ".L0812F694: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812F698:\n"
        "    strh r2, [r1]\n"
        ".L0812F69A:\n"
        "    mov r6, ip\n"
        "    ldrh r0, [r6]\n"
        "    bl .L08130136\n"
        ".L0812F6A2:\n"
        "    cmp r1, #2\n"
        "    bne .L0812F710\n"
        "    ldr r0, .L0812F6E0\n"
        "    movs r7, #0\n"
        "    ldrsh r0, [r0, r7]\n"
        "    cmp r0, #7\n"
        "    bgt .L0812F6B4\n"
        "    bl .L08130146\n"
        ".L0812F6B4:\n"
        "    ldrh r0, [r6]\n"
        "    lsls r1, r0, #0x10\n"
        "    lsrs r0, r1, #0x10\n"
        "    cmp r0, #1\n"
        "    bhi .L0812F6F4\n"
        "    ldr r1, .L0812F6E4\n"
        "    ldrh r2, [r1]\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r1, r3]\n"
        "    cmp r0, #0\n"
        "    bne .L0812F6CE\n"
        "    bl .L08130146\n"
        ".L0812F6CE:\n"
        "    subs r0, #6\n"
        "    cmp r0, #0\n"
        "    blt .L0812F6E8\n"
        "    subs r0, r2, #6\n"
        "    strh r0, [r1]\n"
        "    mov r5, ip\n"
        "    ldrh r0, [r5]\n"
        "    bl .L08130136\n"
        ".L0812F6E0: .4byte 0x03006604 @ IWRAM+0x6604\n"
        ".L0812F6E4: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812F6E8:\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    mov r6, ip\n"
        "    ldrh r0, [r6]\n"
        "    bl .L08130136\n"
        ".L0812F6F4:\n"
        "    asrs r0, r1, #0x10\n"
        "    cmp r0, #2\n"
        "    beq .L0812F702\n"
        "    cmp r0, #4\n"
        "    beq .L0812F702\n"
        "    cmp r0, #6\n"
        "    bne .L0812F70A\n"
        ".L0812F702:\n"
        "    movs r0, #0\n"
        "    strh r0, [r6]\n"
        "    bl .L0813013A\n"
        ".L0812F70A:\n"
        "    strh r2, [r6]\n"
        "    bl .L0813013A\n"
        ".L0812F710:\n"
        "    cmp r1, #3\n"
        "    beq .L0812F718\n"
        "    bl .L08130146\n"
        ".L0812F718:\n"
        "    ldr r0, .L0812F754\n"
        "    movs r7, #0\n"
        "    ldrsh r0, [r0, r7]\n"
        "    cmp r0, #5\n"
        "    bgt .L0812F726\n"
        "    bl .L08130146\n"
        ".L0812F726:\n"
        "    ldrh r0, [r6]\n"
        "    lsls r1, r0, #0x10\n"
        "    lsrs r0, r1, #0x10\n"
        "    cmp r0, #1\n"
        "    bhi .L0812F768\n"
        "    ldr r1, .L0812F758\n"
        "    ldrh r2, [r1]\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r1, r3]\n"
        "    cmp r0, #0\n"
        "    bne .L0812F740\n"
        "    bl .L08130146\n"
        ".L0812F740:\n"
        "    subs r0, #6\n"
        "    cmp r0, #0\n"
        "    blt .L0812F75C\n"
        "    subs r0, r2, #6\n"
        "    strh r0, [r1]\n"
        "    mov r5, ip\n"
        "    ldrh r0, [r5]\n"
        "    bl .L08130136\n"
        "    .byte 0x00, 0x00\n"
        ".L0812F754: .4byte 0x03006604 @ IWRAM+0x6604\n"
        ".L0812F758: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812F75C:\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    mov r6, ip\n"
        "    ldrh r0, [r6]\n"
        "    bl .L08130136\n"
        ".L0812F768:\n"
        "    asrs r0, r1, #0x10\n"
        "    cmp r0, #2\n"
        "    beq .L0812F772\n"
        "    cmp r0, #4\n"
        "    bne .L0812F77A\n"
        ".L0812F772:\n"
        "    movs r0, #0\n"
        "    strh r0, [r6]\n"
        "    bl .L0813013A\n"
        ".L0812F77A:\n"
        "    strh r2, [r6]\n"
        "    bl .L0813013A\n"
        ".L0812F780:\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L0812F78C\n"
        "    b .L0812FC24\n"
        ".L0812F78C:\n"
        "    mov r7, ip\n"
        "    movs r0, #0\n"
        "    ldrsh r4, [r7, r0]\n"
        "    cmp r4, #0\n"
        "    bne .L0812F7F0\n"
        "    ldr r3, .L0812F7B8\n"
        "    ldrh r4, [r3]\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r3, r1]\n"
        "    cmp r0, #3\n"
        "    bgt .L0812F7A6\n"
        "    bl .L08130146\n"
        ".L0812F7A6:\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r6, r2]\n"
        "    cmp r0, #3\n"
        "    beq .L0812F7BC\n"
        "    movs r0, #3\n"
        "    strh r0, [r6]\n"
        "    bl .L0813013A\n"
        "    .byte 0x00, 0x00\n"
        ".L0812F7B8: .4byte 0x03006604 @ IWRAM+0x6604\n"
        ".L0812F7BC:\n"
        "    movs r5, #0\n"
        "    ldrsh r1, [r6, r5]\n"
        "    ldr r2, .L0812F7E0\n"
        "    movs r6, #0\n"
        "    ldrsh r0, [r2, r6]\n"
        "    adds r1, r1, r0\n"
        "    movs r7, #0\n"
        "    ldrsh r0, [r3, r7]\n"
        "    cmp r1, r0\n"
        "    bne .L0812F7D4\n"
        "    bl .L08130146\n"
        ".L0812F7D4:\n"
        "    subs r0, #3\n"
        "    cmp r1, r0\n"
        "    bge .L0812F7E4\n"
        "    ldrh r0, [r2]\n"
        "    adds r0, #4\n"
        "    b .L0812F7E6\n"
        ".L0812F7E0: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812F7E4:\n"
        "    subs r0, r4, #3\n"
        ".L0812F7E6:\n"
        "    strh r0, [r2]\n"
        "    mov r1, ip\n"
        "    ldrh r0, [r1]\n"
        "    bl .L08130136\n"
        ".L0812F7F0:\n"
        "    cmp r4, #4\n"
        "    beq .L0812F7F8\n"
        "    cmp r4, #1\n"
        "    bne .L0812F850\n"
        ".L0812F7F8:\n"
        "    ldr r3, .L0812F818\n"
        "    ldrh r4, [r3]\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r3, r2]\n"
        "    cmp r0, #2\n"
        "    bgt .L0812F808\n"
        "    bl .L08130146\n"
        ".L0812F808:\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r6, r5]\n"
        "    cmp r0, #2\n"
        "    beq .L0812F81C\n"
        "    movs r0, #2\n"
        "    strh r0, [r6]\n"
        "    bl .L0813013A\n"
        ".L0812F818: .4byte 0x03006604 @ IWRAM+0x6604\n"
        ".L0812F81C:\n"
        "    movs r7, #0\n"
        "    ldrsh r1, [r6, r7]\n"
        "    ldr r2, .L0812F840\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r2, r5]\n"
        "    adds r1, r1, r0\n"
        "    movs r6, #0\n"
        "    ldrsh r0, [r3, r6]\n"
        "    cmp r1, r0\n"
        "    bne .L0812F834\n"
        "    bl .L08130146\n"
        ".L0812F834:\n"
        "    subs r0, #2\n"
        "    cmp r1, r0\n"
        "    bge .L0812F844\n"
        "    ldrh r0, [r2]\n"
        "    adds r0, #3\n"
        "    b .L0812F846\n"
        ".L0812F840: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812F844:\n"
        "    subs r0, r4, #2\n"
        ".L0812F846:\n"
        "    strh r0, [r2]\n"
        "    mov r7, ip\n"
        "    ldrh r0, [r7]\n"
        "    bl .L08130136\n"
        ".L0812F850:\n"
        "    cmp r4, #2\n"
        "    beq .L0812F856\n"
        "    b .L0812FA64\n"
        ".L0812F856:\n"
        "    ldr r0, .L0812F8B0\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    cmp r0, #7\n"
        "    bgt .L0812F864\n"
        "    bl .L08130146\n"
        ".L0812F864:\n"
        "    movs r2, #0\n"
        "    ldrsh r4, [r6, r2]\n"
        "    cmp r4, #7\n"
        "    bne .L0812F8DE\n"
        "    movs r5, #2\n"
        "    ldr r3, .L0812F8B4\n"
        "    mov sb, r3\n"
        "    ldr r2, .L0812F8B8\n"
        "    mov r7, sb\n"
        "    movs r4, #0\n"
        "    ldrsh r1, [r7, r4]\n"
        "    adds r3, r6, #0\n"
        "    movs r6, #0\n"
        "    ldrsh r0, [r3, r6]\n"
        "    adds r1, r1, r0\n"
        "    ldr r0, .L0812F8BC\n"
        "    mov r8, r0\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #1\n"
        "    adds r6, r0, r2\n"
        ".L0812F88C:\n"
        "    adds r0, r1, r5\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r4, [r0]\n"
        "    cmp r4, r8\n"
        "    bne .L0812F8C0\n"
        "    cmp r5, #2\n"
        "    bne .L0812F8A6\n"
        "    ldrh r0, [r6]\n"
        "    cmp r0, r4\n"
        "    beq .L0812F8A6\n"
        "    bl .L08130114\n"
        ".L0812F8A6:\n"
        "    subs r0, r5, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    b .L0812F8CA\n"
        "    .byte 0x00, 0x00\n"
        ".L0812F8B0: .4byte 0x03006604 @ IWRAM+0x6604\n"
        ".L0812F8B4: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812F8B8: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L0812F8BC: .4byte 0x0000FFFF\n"
        ".L0812F8C0:\n"
        "    adds r0, r5, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #7\n"
        "    bls .L0812F88C\n"
        ".L0812F8CA:\n"
        "    cmp r5, #0\n"
        "    bne .L0812F8D2\n"
        "    bl .L08130146\n"
        ".L0812F8D2:\n"
        "    mov r1, sb\n"
        "    ldrh r0, [r1]\n"
        "    adds r0, r5, r0\n"
        "    strh r0, [r1]\n"
        "    bl .L08130132\n"
        ".L0812F8DE:\n"
        "    cmp r4, #6\n"
        "    bne .L0812F958\n"
        "    movs r5, #2\n"
        "    ldr r3, .L0812F94C\n"
        "    ldr r2, .L0812F950\n"
        "    movs r4, #0\n"
        "    ldrsh r0, [r2, r4]\n"
        "    movs r7, #0\n"
        "    ldrsh r1, [r6, r7]\n"
        "    adds r0, r0, r1\n"
        "    adds r0, #2\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r3\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L0812F954\n"
        "    mov sb, r2\n"
        "    adds r2, r3, #0\n"
        "    cmp r1, r0\n"
        "    bne .L0812F908\n"
        "    bl .L08130146\n"
        ".L0812F908:\n"
        "    adds r0, r5, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #7\n"
        "    bhi .L0812F932\n"
        "    mov r1, sb\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r1, r3]\n"
        "    movs r4, #0\n"
        "    ldrsh r1, [r6, r4]\n"
        "    adds r0, r0, r1\n"
        "    adds r0, r0, r5\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L0812F954\n"
        "    cmp r1, r0\n"
        "    bne .L0812F908\n"
        "    subs r0, r5, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        ".L0812F932:\n"
        "    cmp r5, #0\n"
        "    bne .L0812F93A\n"
        "    bl .L08130146\n"
        ".L0812F93A:\n"
        "    mov r6, sb\n"
        "    ldrh r0, [r6]\n"
        "    adds r0, r5, r0\n"
        "    strh r0, [r6]\n"
        "    mov r7, ip\n"
        "    ldrh r0, [r7]\n"
        "    bl .L08130136\n"
        "    .byte 0x00, 0x00\n"
        ".L0812F94C: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L0812F950: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812F954: .4byte 0x0000FFFF\n"
        ".L0812F958:\n"
        "    cmp r4, #0\n"
        "    beq .L0812F964\n"
        "    cmp r4, #2\n"
        "    beq .L0812F964\n"
        "    cmp r4, #4\n"
        "    bne .L0812F9D4\n"
        ".L0812F964:\n"
        "    ldr r2, .L0812F984\n"
        "    ldr r1, .L0812F988\n"
        "    movs r0, #0\n"
        "    ldrsh r5, [r1, r0]\n"
        "    adds r0, r5, #6\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r4, [r0]\n"
        "    ldr r0, .L0812F98C\n"
        "    mov sb, r1\n"
        "    cmp r4, r0\n"
        "    beq .L0812F990\n"
        "    movs r0, #6\n"
        "    strh r0, [r6]\n"
        "    bl .L0813013A\n"
        ".L0812F984: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L0812F988: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812F98C: .4byte 0x0000FFFF\n"
        ".L0812F990:\n"
        "    adds r0, r5, #4\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, r4\n"
        "    beq .L0812F9AA\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r6, r1]\n"
        "    cmp r0, #3\n"
        "    bgt .L0812F9AA\n"
        "    movs r0, #4\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L0812F9AA:\n"
        "    mov r3, sb\n"
        "    movs r4, #0\n"
        "    ldrsh r0, [r3, r4]\n"
        "    adds r0, #2\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L0812F9D0\n"
        "    cmp r1, r0\n"
        "    bne .L0812F9C0\n"
        "    b .L08130146\n"
        ".L0812F9C0:\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r6, r5]\n"
        "    cmp r0, #1\n"
        "    ble .L0812F9CA\n"
        "    b .L08130146\n"
        ".L0812F9CA:\n"
        "    movs r0, #2\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L0812F9D0: .4byte 0x0000FFFF\n"
        ".L0812F9D4:\n"
        "    ldr r2, .L0812F9F4\n"
        "    ldr r1, .L0812F9F8\n"
        "    movs r7, #0\n"
        "    ldrsh r3, [r1, r7]\n"
        "    adds r0, r3, #7\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r5, [r0]\n"
        "    ldr r0, .L0812F9FC\n"
        "    mov sb, r1\n"
        "    cmp r5, r0\n"
        "    beq .L0812FA00\n"
        "    movs r0, #7\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        "    .byte 0x00, 0x00\n"
        ".L0812F9F4: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L0812F9F8: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812F9FC: .4byte 0x0000FFFF\n"
        ".L0812FA00:\n"
        "    adds r0, r3, #5\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, r5\n"
        "    beq .L0812FA16\n"
        "    cmp r4, #4\n"
        "    bgt .L0812FA16\n"
        "    movs r0, #5\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L0812FA16:\n"
        "    mov r1, sb\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r1, r3]\n"
        "    adds r0, #3\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L0812FA38\n"
        "    cmp r1, r0\n"
        "    beq .L0812FA3C\n"
        "    movs r4, #0\n"
        "    ldrsh r0, [r6, r4]\n"
        "    cmp r0, #2\n"
        "    bgt .L0812FA3C\n"
        "    movs r0, #3\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L0812FA38: .4byte 0x0000FFFF\n"
        ".L0812FA3C:\n"
        "    mov r5, sb\n"
        "    movs r7, #0\n"
        "    ldrsh r0, [r5, r7]\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r6, r3]\n"
        "    adds r0, r0, r1\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L0812FA60\n"
        "    cmp r1, r0\n"
        "    bne .L0812FA58\n"
        "    b .L08130146\n"
        ".L0812FA58:\n"
        "    ldrh r0, [r6]\n"
        "    adds r0, #1\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L0812FA60: .4byte 0x0000FFFF\n"
        ".L0812FA64:\n"
        "    cmp r4, #3\n"
        "    beq .L0812FA6A\n"
        "    b .L08130146\n"
        ".L0812FA6A:\n"
        "    ldr r0, .L0812FAC0\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r0, r5]\n"
        "    cmp r0, #5\n"
        "    bgt .L0812FA76\n"
        "    b .L08130146\n"
        ".L0812FA76:\n"
        "    movs r7, #0\n"
        "    ldrsh r5, [r6, r7]\n"
        "    cmp r5, #5\n"
        "    bne .L0812FAF4\n"
        "    movs r5, #2\n"
        "    ldr r0, .L0812FAC4\n"
        "    mov sb, r0\n"
        "    ldr r2, .L0812FAC8\n"
        "    mov r7, sb\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r7, r3]\n"
        "    adds r3, r6, #0\n"
        "    movs r4, #0\n"
        "    ldrsh r0, [r3, r4]\n"
        "    adds r1, r1, r0\n"
        "    ldr r6, .L0812FACC\n"
        "    mov r8, r6\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #1\n"
        "    adds r6, r0, r2\n"
        ".L0812FA9E:\n"
        "    adds r0, r1, r5\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r4, [r0]\n"
        "    cmp r4, r8\n"
        "    bne .L0812FAD0\n"
        "    cmp r5, #2\n"
        "    bne .L0812FAB6\n"
        "    ldrh r0, [r6]\n"
        "    cmp r0, r4\n"
        "    beq .L0812FAB6\n"
        "    b .L08130126\n"
        ".L0812FAB6:\n"
        "    subs r0, r5, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    b .L0812FADA\n"
        "    .byte 0x00, 0x00\n"
        ".L0812FAC0: .4byte 0x03006604 @ IWRAM+0x6604\n"
        ".L0812FAC4: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812FAC8: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L0812FACC: .4byte 0x0000FFFF\n"
        ".L0812FAD0:\n"
        "    adds r0, r5, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #7\n"
        "    bls .L0812FA9E\n"
        ".L0812FADA:\n"
        "    cmp r5, #8\n"
        "    bne .L0812FAE0\n"
        "    movs r5, #6\n"
        ".L0812FAE0:\n"
        "    cmp r5, #0\n"
        "    bne .L0812FAE6\n"
        "    b .L08130146\n"
        ".L0812FAE6:\n"
        "    mov r7, sb\n"
        "    ldrh r0, [r7]\n"
        "    adds r0, r5, r0\n"
        "    strh r0, [r7]\n"
        "    mov r1, ip\n"
        "    ldrh r0, [r1]\n"
        "    b .L08130136\n"
        ".L0812FAF4:\n"
        "    cmp r5, #4\n"
        "    bne .L0812FB74\n"
        "    movs r5, #2\n"
        "    ldr r3, .L0812FB20\n"
        "    ldr r2, .L0812FB24\n"
        "    movs r4, #0\n"
        "    ldrsh r0, [r2, r4]\n"
        "    movs r7, #0\n"
        "    ldrsh r1, [r6, r7]\n"
        "    adds r0, r0, r1\n"
        "    adds r0, #2\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r3\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L0812FB28\n"
        "    mov sb, r2\n"
        "    adds r2, r3, #0\n"
        "    cmp r1, r0\n"
        "    bne .L0812FB2C\n"
        "    movs r5, #0\n"
        "    b .L0812FB56\n"
        "    .byte 0x00, 0x00\n"
        ".L0812FB20: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L0812FB24: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812FB28: .4byte 0x0000FFFF\n"
        ".L0812FB2C:\n"
        "    adds r0, r5, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #7\n"
        "    bhi .L0812FB56\n"
        "    mov r1, sb\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r1, r3]\n"
        "    movs r4, #0\n"
        "    ldrsh r1, [r6, r4]\n"
        "    adds r0, r0, r1\n"
        "    adds r0, r0, r5\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L0812FB70\n"
        "    cmp r1, r0\n"
        "    bne .L0812FB2C\n"
        "    subs r0, r5, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        ".L0812FB56:\n"
        "    cmp r5, #8\n"
        "    bne .L0812FB5C\n"
        "    movs r5, #6\n"
        ".L0812FB5C:\n"
        "    cmp r5, #0\n"
        "    bne .L0812FB62\n"
        "    b .L08130146\n"
        ".L0812FB62:\n"
        "    mov r6, sb\n"
        "    ldrh r0, [r6]\n"
        "    adds r0, r5, r0\n"
        "    strh r0, [r6]\n"
        "    mov r7, ip\n"
        "    ldrh r0, [r7]\n"
        "    b .L08130136\n"
        ".L0812FB70: .4byte 0x0000FFFF\n"
        ".L0812FB74:\n"
        "    cmp r5, #0\n"
        "    beq .L0812FB7C\n"
        "    cmp r5, #2\n"
        "    bne .L0812FBBE\n"
        ".L0812FB7C:\n"
        "    ldr r3, .L0812FB98\n"
        "    ldr r0, .L0812FB9C\n"
        "    movs r1, #0\n"
        "    ldrsh r2, [r0, r1]\n"
        "    adds r0, r2, #4\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r3\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L0812FBA0\n"
        "    cmp r1, r0\n"
        "    beq .L0812FBA4\n"
        "    movs r0, #4\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L0812FB98: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L0812FB9C: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812FBA0: .4byte 0x0000FFFF\n"
        ".L0812FBA4:\n"
        "    adds r0, r2, #2\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r3\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, r1\n"
        "    bne .L0812FBB2\n"
        "    b .L08130146\n"
        ".L0812FBB2:\n"
        "    cmp r5, #1\n"
        "    ble .L0812FBB8\n"
        "    b .L08130146\n"
        ".L0812FBB8:\n"
        "    movs r0, #2\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L0812FBBE:\n"
        "    ldr r2, .L0812FBDC\n"
        "    ldr r1, .L0812FBE0\n"
        "    movs r3, #0\n"
        "    ldrsh r7, [r1, r3]\n"
        "    adds r0, r7, #5\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r3, [r0]\n"
        "    ldr r0, .L0812FBE4\n"
        "    mov sb, r1\n"
        "    cmp r3, r0\n"
        "    beq .L0812FBE8\n"
        "    movs r0, #5\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L0812FBDC: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L0812FBE0: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812FBE4: .4byte 0x0000FFFF\n"
        ".L0812FBE8:\n"
        "    adds r0, r7, #3\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, r3\n"
        "    beq .L0812FBFC\n"
        "    cmp r5, #2\n"
        "    bgt .L0812FBFC\n"
        "    strh r4, [r6]\n"
        "    b .L0813013A\n"
        ".L0812FBFC:\n"
        "    mov r4, sb\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r4, r5]\n"
        "    movs r7, #0\n"
        "    ldrsh r1, [r6, r7]\n"
        "    adds r0, r0, r1\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L0812FC20\n"
        "    cmp r1, r0\n"
        "    bne .L0812FC18\n"
        "    b .L08130146\n"
        ".L0812FC18:\n"
        "    ldrh r0, [r6]\n"
        "    adds r0, #1\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L0812FC20: .4byte 0x0000FFFF\n"
        ".L0812FC24:\n"
        "    movs r0, #0x40\n"
        "    ands r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    cmp r7, #0\n"
        "    beq .L0812FCD6\n"
        "    mov r1, ip\n"
        "    ldrh r0, [r1]\n"
        "    lsls r2, r0, #0x10\n"
        "    lsrs r0, r2, #0x10\n"
        "    cmp r0, #1\n"
        "    bls .L0812FC42\n"
        "    asrs r0, r2, #0x10\n"
        "    cmp r0, #4\n"
        "    bne .L0812FCAC\n"
        ".L0812FC42:\n"
        "    ldrh r1, [r6]\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r6, r3]\n"
        "    cmp r0, #0\n"
        "    bne .L0812FCA6\n"
        "    ldr r1, .L0812FC74\n"
        "    ldrh r3, [r1]\n"
        "    movs r4, #0\n"
        "    ldrsh r0, [r1, r4]\n"
        "    cmp r0, #0\n"
        "    bne .L0812FCA0\n"
        "    asrs r0, r2, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L0812FC7C\n"
        "    ldr r0, .L0812FC78\n"
        "    ldrh r1, [r0]\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r0, r5]\n"
        "    cmp r0, #3\n"
        "    ble .L0812FC6C\n"
        "    b .L08130146\n"
        ".L0812FC6C:\n"
        "    strh r1, [r6]\n"
        "    mov r6, ip\n"
        "    ldrh r0, [r6]\n"
        "    b .L08130136\n"
        ".L0812FC74: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812FC78: .4byte 0x03006604 @ IWRAM+0x6604\n"
        ".L0812FC7C:\n"
        "    cmp r0, #1\n"
        "    beq .L0812FC86\n"
        "    cmp r0, #4\n"
        "    beq .L0812FC86\n"
        "    b .L08130146\n"
        ".L0812FC86:\n"
        "    ldr r0, .L0812FC9C\n"
        "    ldrh r1, [r0]\n"
        "    movs r7, #0\n"
        "    ldrsh r0, [r0, r7]\n"
        "    cmp r0, #2\n"
        "    ble .L0812FC94\n"
        "    b .L08130146\n"
        ".L0812FC94:\n"
        "    strh r1, [r6]\n"
        "    mov r1, ip\n"
        "    ldrh r0, [r1]\n"
        "    b .L08130136\n"
        ".L0812FC9C: .4byte 0x03006604 @ IWRAM+0x6604\n"
        ".L0812FCA0:\n"
        "    subs r0, r3, #1\n"
        "    strh r0, [r1]\n"
        "    b .L08130132\n"
        ".L0812FCA6:\n"
        "    subs r0, r1, #1\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L0812FCAC:\n"
        "    ldrh r0, [r6]\n"
        "    cmp r0, #1\n"
        "    bhi .L0812FCD0\n"
        "    ldr r1, .L0812FCCC\n"
        "    ldrh r2, [r1]\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r1, r3]\n"
        "    cmp r0, #1\n"
        "    bgt .L0812FCC0\n"
        "    b .L08130146\n"
        ".L0812FCC0:\n"
        "    subs r0, r2, #2\n"
        "    strh r0, [r1]\n"
        "    mov r4, ip\n"
        "    ldrh r0, [r4]\n"
        "    b .L08130136\n"
        "    .byte 0x00, 0x00\n"
        ".L0812FCCC: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812FCD0:\n"
        "    subs r0, #2\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L0812FCD6:\n"
        "    movs r0, #0x80\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L0812FCE0\n"
        "    b .L0812FFCC\n"
        ".L0812FCE0:\n"
        "    mov r5, ip\n"
        "    movs r0, #0\n"
        "    ldrsh r3, [r5, r0]\n"
        "    cmp r3, #0\n"
        "    bne .L0812FD5A\n"
        "    ldr r0, .L0812FD28\n"
        "    movs r1, #0\n"
        "    ldrsh r4, [r0, r1]\n"
        "    cmp r4, #2\n"
        "    ble .L0812FD46\n"
        "    ldrh r1, [r6]\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r6, r2]\n"
        "    cmp r0, #3\n"
        "    bne .L0812FD40\n"
        "    ldr r2, .L0812FD2C\n"
        "    ldr r5, .L0812FD30\n"
        "    movs r7, #0\n"
        "    ldrsh r0, [r5, r7]\n"
        "    movs r7, #0\n"
        "    ldrsh r1, [r6, r7]\n"
        "    adds r0, r0, r1\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L0812FD34\n"
        "    cmp r1, r0\n"
        "    bne .L0812FD38\n"
        "    cmp r4, #3\n"
        "    beq .L0812FD20\n"
        "    b .L08130146\n"
        ".L0812FD20:\n"
        "    strh r3, [r6]\n"
        "    mov r1, ip\n"
        "    ldrh r0, [r1]\n"
        "    b .L08130136\n"
        ".L0812FD28: .4byte 0x03006604 @ IWRAM+0x6604\n"
        ".L0812FD2C: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L0812FD30: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812FD34: .4byte 0x0000FFFF\n"
        ".L0812FD38:\n"
        "    ldrh r0, [r5]\n"
        "    adds r0, #1\n"
        "    strh r0, [r5]\n"
        "    b .L08130132\n"
        ".L0812FD40:\n"
        "    adds r0, r1, #1\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L0812FD46:\n"
        "    ldrh r1, [r6]\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r6, r5]\n"
        "    cmp r0, r4\n"
        "    bne .L0812FD54\n"
        "    strh r3, [r6]\n"
        "    b .L0813013A\n"
        ".L0812FD54:\n"
        "    adds r0, r1, #1\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L0812FD5A:\n"
        "    cmp r3, #1\n"
        "    beq .L0812FD62\n"
        "    cmp r3, #4\n"
        "    bne .L0812FDE4\n"
        ".L0812FD62:\n"
        "    ldr r0, .L0812FDA8\n"
        "    movs r1, #0\n"
        "    ldrsh r4, [r0, r1]\n"
        "    cmp r4, #1\n"
        "    ble .L0812FDCA\n"
        "    ldrh r1, [r6]\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r6, r2]\n"
        "    cmp r0, #2\n"
        "    bne .L0812FDC4\n"
        "    ldr r5, .L0812FDAC\n"
        "    mov r8, r5\n"
        "    ldr r5, .L0812FDB0\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r5, r1]\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r6, r2]\n"
        "    adds r0, r0, r1\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #1\n"
        "    add r0, r8\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L0812FDB4\n"
        "    cmp r1, r0\n"
        "    bne .L0812FDB8\n"
        "    cmp r3, #1\n"
        "    beq .L0812FD9E\n"
        "    cmp r3, #4\n"
        "    beq .L0812FD9E\n"
        "    b .L08130146\n"
        ".L0812FD9E:\n"
        "    cmp r4, #2\n"
        "    beq .L0812FDA4\n"
        "    b .L08130146\n"
        ".L0812FDA4:\n"
        "    strh r7, [r6]\n"
        "    b .L0813013A\n"
        ".L0812FDA8: .4byte 0x03006604 @ IWRAM+0x6604\n"
        ".L0812FDAC: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L0812FDB0: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812FDB4: .4byte 0x0000FFFF\n"
        ".L0812FDB8:\n"
        "    ldrh r0, [r5]\n"
        "    adds r0, #1\n"
        "    strh r0, [r5]\n"
        "    mov r3, ip\n"
        "    ldrh r0, [r3]\n"
        "    b .L08130136\n"
        ".L0812FDC4:\n"
        "    adds r0, r1, #1\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L0812FDCA:\n"
        "    ldrh r1, [r6]\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r6, r5]\n"
        "    cmp r0, r4\n"
        "    bne .L0812FDDE\n"
        "    cmp r3, #1\n"
        "    beq .L0812FDDA\n"
        "    b .L08130146\n"
        ".L0812FDDA:\n"
        "    strh r7, [r6]\n"
        "    b .L0813013A\n"
        ".L0812FDDE:\n"
        "    adds r0, r1, #1\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L0812FDE4:\n"
        "    cmp r3, #2\n"
        "    bne .L0812FED4\n"
        "    ldr r0, .L0812FE28\n"
        "    movs r7, #0\n"
        "    ldrsh r0, [r0, r7]\n"
        "    cmp r0, #6\n"
        "    ble .L0812FEA2\n"
        "    ldrh r5, [r6]\n"
        "    movs r0, #0\n"
        "    ldrsh r3, [r6, r0]\n"
        "    cmp r3, #5\n"
        "    ble .L0812FE58\n"
        "    ldr r4, .L0812FE2C\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r4, r2]\n"
        "    adds r0, r3, #0\n"
        "    adds r1, r1, r0\n"
        "    cmp r1, #0xf\n"
        "    ble .L0812FE0C\n"
        "    b .L08130146\n"
        ".L0812FE0C:\n"
        "    ldr r7, .L0812FE30\n"
        "    adds r0, r1, #2\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r7\n"
        "    ldrh r2, [r0]\n"
        "    ldr r0, .L0812FE34\n"
        "    cmp r2, r0\n"
        "    beq .L0812FE38\n"
        "    ldrh r0, [r4]\n"
        "    adds r0, #2\n"
        "    strh r0, [r4]\n"
        "    mov r1, ip\n"
        "    ldrh r0, [r1]\n"
        "    b .L08130136\n"
        ".L0812FE28: .4byte 0x03006604 @ IWRAM+0x6604\n"
        ".L0812FE2C: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812FE30: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L0812FE34: .4byte 0x0000FFFF\n"
        ".L0812FE38:\n"
        "    cmp r3, #7\n"
        "    beq .L0812FE3E\n"
        "    b .L08130146\n"
        ".L0812FE3E:\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r7\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, r2\n"
        "    bne .L0812FE4C\n"
        "    b .L08130146\n"
        ".L0812FE4C:\n"
        "    subs r0, r5, #1\n"
        "    strh r0, [r6]\n"
        "    ldrh r0, [r4]\n"
        "    adds r0, #2\n"
        "    strh r0, [r4]\n"
        "    b .L08130132\n"
        ".L0812FE58:\n"
        "    ldr r4, .L0812FE7C\n"
        "    ldr r0, .L0812FE80\n"
        "    movs r7, #0\n"
        "    ldrsh r1, [r0, r7]\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r6, r2]\n"
        "    adds r1, r1, r0\n"
        "    adds r0, r1, #2\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r2, [r0]\n"
        "    ldr r0, .L0812FE84\n"
        "    cmp r2, r0\n"
        "    beq .L0812FE88\n"
        "    adds r0, r5, #2\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        "    .byte 0x00, 0x00\n"
        ".L0812FE7C: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L0812FE80: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812FE84: .4byte 0x0000FFFF\n"
        ".L0812FE88:\n"
        "    cmp r3, #7\n"
        "    beq .L0812FE8E\n"
        "    b .L08130146\n"
        ".L0812FE8E:\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, r2\n"
        "    bne .L0812FE9C\n"
        "    b .L08130146\n"
        ".L0812FE9C:\n"
        "    adds r0, r5, #1\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L0812FEA2:\n"
        "    ldr r2, .L0812FEC8\n"
        "    ldr r0, .L0812FECC\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r0, r3]\n"
        "    movs r4, #0\n"
        "    ldrsh r1, [r6, r4]\n"
        "    adds r0, r0, r1\n"
        "    adds r0, #2\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L0812FED0\n"
        "    cmp r1, r0\n"
        "    bne .L0812FEC0\n"
        "    b .L08130146\n"
        ".L0812FEC0:\n"
        "    ldrh r0, [r6]\n"
        "    adds r0, #2\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L0812FEC8: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L0812FECC: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812FED0: .4byte 0x0000FFFF\n"
        ".L0812FED4:\n"
        "    cmp r3, #3\n"
        "    beq .L0812FEDA\n"
        "    b .L08130146\n"
        ".L0812FEDA:\n"
        "    ldr r0, .L0812FF1C\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r0, r5]\n"
        "    cmp r0, #4\n"
        "    ble .L0812FF9A\n"
        "    ldrh r5, [r6]\n"
        "    movs r7, #0\n"
        "    ldrsh r3, [r6, r7]\n"
        "    cmp r3, #3\n"
        "    ble .L0812FF50\n"
        "    ldr r4, .L0812FF20\n"
        "    movs r0, #0\n"
        "    ldrsh r1, [r4, r0]\n"
        "    adds r0, r3, #0\n"
        "    adds r1, r1, r0\n"
        "    cmp r1, #0xf\n"
        "    ble .L0812FEFE\n"
        "    b .L08130146\n"
        ".L0812FEFE:\n"
        "    ldr r7, .L0812FF24\n"
        "    adds r0, r1, #2\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r7\n"
        "    ldrh r2, [r0]\n"
        "    ldr r0, .L0812FF28\n"
        "    cmp r2, r0\n"
        "    beq .L0812FF2C\n"
        "    ldrh r0, [r4]\n"
        "    adds r0, #2\n"
        "    strh r0, [r4]\n"
        "    mov r3, ip\n"
        "    ldrh r0, [r3]\n"
        "    b .L08130136\n"
        "    .byte 0x00, 0x00\n"
        ".L0812FF1C: .4byte 0x03006604 @ IWRAM+0x6604\n"
        ".L0812FF20: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812FF24: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L0812FF28: .4byte 0x0000FFFF\n"
        ".L0812FF2C:\n"
        "    cmp r3, #5\n"
        "    beq .L0812FF32\n"
        "    b .L08130146\n"
        ".L0812FF32:\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r7\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, r2\n"
        "    bne .L0812FF40\n"
        "    b .L08130146\n"
        ".L0812FF40:\n"
        "    subs r0, r5, #1\n"
        "    strh r0, [r6]\n"
        "    ldrh r0, [r4]\n"
        "    adds r0, #2\n"
        "    strh r0, [r4]\n"
        "    mov r4, ip\n"
        "    ldrh r0, [r4]\n"
        "    b .L08130136\n"
        ".L0812FF50:\n"
        "    ldr r4, .L0812FF74\n"
        "    ldr r0, .L0812FF78\n"
        "    movs r7, #0\n"
        "    ldrsh r1, [r0, r7]\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r6, r2]\n"
        "    adds r1, r1, r0\n"
        "    adds r0, r1, #2\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r2, [r0]\n"
        "    ldr r0, .L0812FF7C\n"
        "    cmp r2, r0\n"
        "    beq .L0812FF80\n"
        "    adds r0, r5, #2\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        "    .byte 0x00, 0x00\n"
        ".L0812FF74: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L0812FF78: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812FF7C: .4byte 0x0000FFFF\n"
        ".L0812FF80:\n"
        "    cmp r3, #5\n"
        "    beq .L0812FF86\n"
        "    b .L08130146\n"
        ".L0812FF86:\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, r2\n"
        "    bne .L0812FF94\n"
        "    b .L08130146\n"
        ".L0812FF94:\n"
        "    adds r0, r5, #1\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L0812FF9A:\n"
        "    ldr r2, .L0812FFC0\n"
        "    ldr r0, .L0812FFC4\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r0, r3]\n"
        "    movs r4, #0\n"
        "    ldrsh r1, [r6, r4]\n"
        "    adds r0, r0, r1\n"
        "    adds r0, #2\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L0812FFC8\n"
        "    cmp r1, r0\n"
        "    bne .L0812FFB8\n"
        "    b .L08130146\n"
        ".L0812FFB8:\n"
        "    ldrh r0, [r6]\n"
        "    adds r0, #2\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L0812FFC0: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L0812FFC4: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0812FFC8: .4byte 0x0000FFFF\n"
        ".L0812FFCC:\n"
        "    movs r0, #0x20\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08130028\n"
        "    mov r5, ip\n"
        "    ldrh r0, [r5]\n"
        "    subs r0, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bls .L0812FFE4\n"
        "    b .L08130146\n"
        ".L0812FFE4:\n"
        "    ldrh r2, [r6]\n"
        "    movs r7, #0\n"
        "    ldrsh r0, [r6, r7]\n"
        "    cmp r0, #1\n"
        "    beq .L0812FFFA\n"
        "    cmp r0, #3\n"
        "    beq .L0812FFFA\n"
        "    cmp r0, #5\n"
        "    beq .L0812FFFA\n"
        "    cmp r0, #7\n"
        "    bne .L08130002\n"
        ".L0812FFFA:\n"
        "    ldrh r0, [r6]\n"
        "    subs r0, #1\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L08130002:\n"
        "    ldr r0, .L08130020\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r0, r3]\n"
        "    movs r4, #0\n"
        "    ldrsh r0, [r6, r4]\n"
        "    adds r1, r1, r0\n"
        "    ldr r0, .L08130024\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r0, r5]\n"
        "    cmp r1, r0\n"
        "    blt .L0813001A\n"
        "    b .L08130146\n"
        ".L0813001A:\n"
        "    adds r0, r2, #1\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L08130020: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08130024: .4byte 0x03006604 @ IWRAM+0x6604\n"
        ".L08130028:\n"
        "    movs r0, #0x10\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08130082\n"
        "    mov r7, ip\n"
        "    ldrh r0, [r7]\n"
        "    subs r0, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bls .L08130040\n"
        "    b .L08130146\n"
        ".L08130040:\n"
        "    ldrh r0, [r6]\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r6, r2]\n"
        "    cmp r1, #0\n"
        "    beq .L08130056\n"
        "    cmp r1, #2\n"
        "    beq .L08130056\n"
        "    cmp r1, #4\n"
        "    beq .L08130056\n"
        "    cmp r1, #6\n"
        "    bne .L0813007C\n"
        ".L08130056:\n"
        "    ldr r0, .L08130074\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r0, r3]\n"
        "    movs r4, #0\n"
        "    ldrsh r0, [r6, r4]\n"
        "    adds r1, r1, r0\n"
        "    ldr r0, .L08130078\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r0, r5]\n"
        "    cmp r1, r0\n"
        "    bge .L08130146\n"
        "    ldrh r0, [r6]\n"
        "    adds r0, #1\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L08130074: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08130078: .4byte 0x03006604 @ IWRAM+0x6604\n"
        ".L0813007C:\n"
        "    subs r0, #1\n"
        "    strh r0, [r6]\n"
        "    b .L0813013A\n"
        ".L08130082:\n"
        "    ldr r3, .L081300C4\n"
        "    ldrh r1, [r3]\n"
        "    movs r2, #1\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L081300E0\n"
        "    mov r6, r8\n"
        "    strh r2, [r6, #0x1c]\n"
        "    movs r0, #0x65\n"
        "    bl Sound_Play\n"
        "    ldr r3, .L081300C8\n"
        "    ldr r2, .L081300CC\n"
        "    ldr r0, .L081300D0\n"
        "    movs r7, #0\n"
        "    ldrsh r0, [r0, r7]\n"
        "    ldr r1, .L081300D4\n"
        "    movs r4, #0\n"
        "    ldrsh r1, [r1, r4]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r3]\n"
        "    ldr r1, .L081300D8\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r1, r5]\n"
        "    cmp r0, #0x18\n"
        "    bne .L081300DC\n"
        "    movs r0, #0x19\n"
        "    b .L08130144\n"
        "    .byte 0x00, 0x00\n"
        ".L081300C4: .4byte 0x030031C4 @ IWRAM+0x31C4\n"
        ".L081300C8: .4byte 0x030065E0 @ IWRAM+0x65E0\n"
        ".L081300CC: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L081300D0: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L081300D4: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L081300D8: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L081300DC:\n"
        "    movs r0, #0xe\n"
        "    b .L08130144\n"
        ".L081300E0:\n"
        "    ldrh r1, [r3]\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08130146\n"
        "    ldr r0, .L0813010C\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L08130146\n"
        "    mov r6, r8\n"
        "    strh r2, [r6, #0x1c]\n"
        "    movs r0, #0x66\n"
        "    bl Sound_Play\n"
        "    ldr r1, .L08130110\n"
        "    movs r7, #0\n"
        "    ldrsh r0, [r1, r7]\n"
        "    cmp r0, #0x18\n"
        "    bne .L08130142\n"
        "    movs r0, #0x37\n"
        "    b .L08130144\n"
        "    .byte 0x00, 0x00\n"
        ".L0813010C: .4byte 0x03006670 @ IWRAM+0x6670\n"
        ".L08130110: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L08130114:\n"
        "    ldrh r0, [r3]\n"
        "    subs r0, #1\n"
        "    strh r0, [r3]\n"
        "    ldrh r0, [r7]\n"
        "    adds r0, #2\n"
        "    strh r0, [r7]\n"
        "    mov r1, ip\n"
        "    ldrh r0, [r1]\n"
        "    b .L08130136\n"
        ".L08130126:\n"
        "    ldrh r0, [r3]\n"
        "    subs r0, #1\n"
        "    strh r0, [r3]\n"
        "    ldrh r0, [r7]\n"
        "    adds r0, #2\n"
        "    strh r0, [r7]\n"
        ".L08130132:\n"
        "    mov r2, ip\n"
        "    ldrh r0, [r2]\n"
        ".L08130136:\n"
        "    bl MsgWindow_DrawItemList\n"
        ".L0813013A:\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        "    b .L08130146\n"
        ".L08130142:\n"
        "    movs r0, #0x1c\n"
        ".L08130144:\n"
        "    strh r0, [r1]\n"
        ".L08130146:\n"
        "    bl sub_0812F010\n"
        "    pop {r3, r4}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif
