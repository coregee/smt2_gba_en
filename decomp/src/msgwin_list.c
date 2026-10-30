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
#define MODE (*(s16 *)&gUnk_03006844)
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
// MsgWindow_ItemListInput @ 0x0812F54C
void MsgWindow_ItemListInput(struct Task *task)
{
    u16 k;

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
                { Sound_Play(100); goto done; }
            }
            if (TOP == 0)
                goto done;
            if (TOP - 4 >= 0)
                TOP -= 4;
            else
                TOP = 0;
            MsgWindow_DrawItemList(gUnk_03006844);
            { Sound_Play(100); goto done; }
        }
        else if (MODE == 4 || MODE == 1)
        {
            if (gUnk_03006604 <= 2)
                goto done;
            if (ROW != 0)
            {
                ROW = 0;
                { Sound_Play(100); goto done; }
            }
            if (TOP == 0)
                goto done;
            if (TOP - 3 >= 0)
                TOP -= 3;
            else
                TOP = 0;
            MsgWindow_DrawItemList(gUnk_03006844);
            { Sound_Play(100); goto done; }
        }
        else if (MODE == 2)
        {
            if (gUnk_03006604 <= 7)
                goto done;
            if ((u16)ROW <= 1)
            {
                if (TOP == 0)
                    goto done;
                if (TOP - 6 >= 0)
                {
                    TOP -= 6;
                    MsgWindow_DrawItemList(gUnk_03006844);
                    { Sound_Play(100); goto done; }
                }
                TOP = 0;
                MsgWindow_DrawItemList(gUnk_03006844);
                { Sound_Play(100); goto done; }
            }
            if (ROW == 2 || ROW == 4 || ROW == 6)
            {
                ROW = 0;
                { Sound_Play(100); goto done; }
            }
            ROW = 1;
            { Sound_Play(100); goto done; }
        }
        else if (MODE == 3)
        {
            if (gUnk_03006604 <= 5)
                goto done;
            if ((u16)ROW <= 1)
            {
                if (TOP == 0)
                    goto done;
                if (TOP - 6 >= 0)
                {
                    TOP -= 6;
                    MsgWindow_DrawItemList(gUnk_03006844);
                    { Sound_Play(100); goto done; }
                }
                TOP = 0;
                MsgWindow_DrawItemList(gUnk_03006844);
                { Sound_Play(100); goto done; }
            }
            if (ROW == 2 || ROW == 4)
            {
                ROW = 0;
                { Sound_Play(100); goto done; }
            }
            ROW = 1;
            { Sound_Play(100); goto done; }
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
                { Sound_Play(100); goto done; }
            }
            if (ROW + TOP == gUnk_03006604)
                goto done;
            if (ROW + TOP < gUnk_03006604 - 3)
                TOP += 4;
            else
                TOP = gUnk_03006604 - 3;
            MsgWindow_DrawItemList(gUnk_03006844);
            { Sound_Play(100); goto done; }
        }
        else if (MODE == 4 || MODE == 1)
        {
            if (gUnk_03006604 <= 2)
                goto done;
            if (ROW != 2)
            {
                ROW = 2;
                { Sound_Play(100); goto done; }
            }
            if (ROW + TOP == gUnk_03006604)
                goto done;
            if (ROW + TOP < gUnk_03006604 - 2)
                TOP += 3;
            else
                TOP = gUnk_03006604 - 2;
            MsgWindow_DrawItemList(gUnk_03006844);
            { Sound_Play(100); goto done; }
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
                            goto shift2;
                        k -= 2;
                        break;
                    }
                }
                if (k == 0)
                    goto done;
                TOP += k;
                MsgWindow_DrawItemList(gUnk_03006844);
                { Sound_Play(100); goto done; }
            }
            if (ROW == 6)
            {
                k = 2;
                if (LIST[TOP + ROW + 2] == END)
                    goto done;
            scan2:
                k += 2;
                if (k > 7)
                    goto page2;
                if (LIST[TOP + ROW + k] != END)
                    goto scan2;
                k -= 2;
            page2:
                if (k == 0)
                    goto done;
                TOP += k;
                MsgWindow_DrawItemList(gUnk_03006844);
                { Sound_Play(100); goto done; }
            }
            if (ROW == 0 || ROW == 2 || ROW == 4)
            {
                if (LIST[TOP + 6] != END)
                {
                    ROW = 6;
                    { Sound_Play(100); goto done; }
                }
                if (LIST[TOP + 4] != END && ROW <= 3)
                {
                    ROW = 4;
                    { Sound_Play(100); goto done; }
                }
                if (LIST[TOP + 2] == END)
                    goto done;
                if (ROW > 1)
                    goto done;
                ROW = 2;
                { Sound_Play(100); goto done; }
            }
            if (LIST[TOP + 7] != END)
            {
                ROW = 7;
                { Sound_Play(100); goto done; }
            }
            if (LIST[TOP + 5] != END && ROW <= 4)
            {
                ROW = 5;
                { Sound_Play(100); goto done; }
            }
            if (LIST[TOP + 3] != END && ROW <= 2)
            {
                ROW = 3;
                { Sound_Play(100); goto done; }
            }
            if (LIST[TOP + ROW + 1] == END)
                goto done;
            ROW++;
            { Sound_Play(100); goto done; }
        }
        else if (MODE == 3)
        {
            if (gUnk_03006604 <= 5)
                goto done;
            if (ROW == 5)
            {
                for (k = 2; k <= 7; k += 2)
                {
                    if (LIST[TOP + ROW + k] == END)
                    {
                        if (k == 2 && LIST[TOP + ROW + 1] != END)
                            goto shift3;
                        k -= 2;
                        break;
                    }
                }
                if (k == 8)
                    k = 6;
                if (k == 0)
                    goto done;
                TOP += k;
                MsgWindow_DrawItemList(gUnk_03006844);
                { Sound_Play(100); goto done; }
            }
            if (ROW == 4)
            {
                k = 2;
                if (LIST[TOP + ROW + 2] == END)
                    k = 0;
                else
                {
                scan3:
                    k += 2;
                    if (k > 7)
                        goto page3;
                    if (LIST[TOP + ROW + k] != END)
                        goto scan3;
                    k -= 2;
                }
            page3:
                if (k == 8)
                    k = 6;
                if (k == 0)
                    goto done;
                TOP += k;
                MsgWindow_DrawItemList(gUnk_03006844);
                { Sound_Play(100); goto done; }
            }
            if (ROW == 0 || ROW == 2)
            {
                if (LIST[TOP + 4] != END)
                {
                    ROW = 4;
                    { Sound_Play(100); goto done; }
                }
                if (LIST[TOP + 2] == END)
                    goto done;
                if (ROW > 1)
                    goto done;
                ROW = 2;
                { Sound_Play(100); goto done; }
            }
            if (LIST[TOP + 5] != END)
            {
                ROW = 5;
                { Sound_Play(100); goto done; }
            }
            if (LIST[TOP + 3] != END && ROW <= 2)
            {
                ROW = 3;
                { Sound_Play(100); goto done; }
            }
            if (LIST[TOP + ROW + 1] == END)
                goto done;
            ROW++;
            { Sound_Play(100); goto done; }
        }
        goto done;
    }
    else if ((u16)(gRepeatedKeys & 0x40))
    {
        /* up */
        if ((u16)gUnk_03006844 <= 1 || MODE == 4)
        {
            if (ROW == 0)
            {
                if (TOP == 0)
                {
                    if (MODE == 0)
                    {
                        if (gUnk_03006604 > 3)
                            goto done;
                        ROW = gUnk_03006604;
                        MsgWindow_DrawItemList(gUnk_03006844);
                        { Sound_Play(100); goto done; }
                    }
                    else if (MODE == 1 || MODE == 4)
                    {
                        if (gUnk_03006604 > 2)
                            goto done;
                        ROW = gUnk_03006604;
                        MsgWindow_DrawItemList(gUnk_03006844);
                        { Sound_Play(100); goto done; }
                    }
                    goto done;
                }
                TOP--;
                MsgWindow_DrawItemList(gUnk_03006844);
                { Sound_Play(100); goto done; }
            }
            ROW--;
            { Sound_Play(100); goto done; }
        }
        if ((u16)ROW <= 1)
        {
            if (TOP <= 1)
                goto done;
            TOP -= 2;
            MsgWindow_DrawItemList(gUnk_03006844);
            { Sound_Play(100); goto done; }
        }
        ROW -= 2;
        { Sound_Play(100); goto done; }
    }
    else if (gRepeatedKeys & 0x80)
    {
        /* down */
        if (MODE == 0)
        {
            if (gUnk_03006604 > 2)
            {
                if (ROW == 3)
                {
                    if (LIST[TOP + ROW + 1] == END)
                    {
                        if (gUnk_03006604 != 3)
                            goto done;
                        ROW = 0;
                        MsgWindow_DrawItemList(gUnk_03006844);
                        { Sound_Play(100); goto done; }
                    }
                    TOP++;
                    MsgWindow_DrawItemList(gUnk_03006844);
                    { Sound_Play(100); goto done; }
                }
                ROW++;
                { Sound_Play(100); goto done; }
            }
            if (ROW == gUnk_03006604)
            {
                ROW = 0;
                { Sound_Play(100); goto done; }
            }
            ROW++;
            { Sound_Play(100); goto done; }
        }
        else if (MODE == 1 || MODE == 4)
        {
            if (gUnk_03006604 > 1)
            {
                if (ROW == 2)
                {
                    if (LIST[TOP + ROW + 1] == END)
                    {
                        if (MODE != 1 && MODE != 4)
                            goto done;
                        if (gUnk_03006604 != 2)
                            goto done;
                        ROW = 0;
                        { Sound_Play(100); goto done; }
                    }
                    TOP++;
                    MsgWindow_DrawItemList(gUnk_03006844);
                    { Sound_Play(100); goto done; }
                }
                ROW++;
                { Sound_Play(100); goto done; }
            }
            if (ROW == gUnk_03006604)
            {
                if (MODE != 1)
                    goto done;
                ROW = 0;
                { Sound_Play(100); goto done; }
            }
            ROW++;
            { Sound_Play(100); goto done; }
        }
        else if (MODE == 2)
        {
            if (gUnk_03006604 > 6)
            {
                if (ROW > 5)
                {
                    s32 n = TOP + ROW;
                    if (n > 15)
                        goto done;
                    if (LIST[n + 2] != END)
                    {
                        TOP += 2;
                        MsgWindow_DrawItemList(gUnk_03006844);
                        { Sound_Play(100); goto done; }
                    }
                    if (ROW != 7)
                        goto done;
                    if (LIST[n + 1] == END)
                        goto done;
                    ROW--;
                    TOP += 2;
                    MsgWindow_DrawItemList(gUnk_03006844);
                    { Sound_Play(100); goto done; }
                }
                else
                {
                    if (LIST[TOP + ROW + 2] != END)
                    {
                        ROW += 2;
                        { Sound_Play(100); goto done; }
                    }
                    if (ROW != 7)
                        goto done;
                    if (LIST[TOP + ROW + 1] == END)
                        goto done;
                    ROW++;
                    { Sound_Play(100); goto done; }
                }
            }
            if (LIST[TOP + ROW + 2] == END)
                goto done;
            ROW += 2;
            { Sound_Play(100); goto done; }
        }
        else if (MODE == 3)
        {
            if (gUnk_03006604 > 4)
            {
                if (ROW > 3)
                {
                    s32 n = TOP + ROW;
                    if (n > 15)
                        goto done;
                    if (LIST[n + 2] != END)
                    {
                        TOP += 2;
                        MsgWindow_DrawItemList(gUnk_03006844);
                        { Sound_Play(100); goto done; }
                    }
                    if (ROW != 5)
                        goto done;
                    if (LIST[n + 1] == END)
                        goto done;
                    ROW--;
                    TOP += 2;
                    MsgWindow_DrawItemList(gUnk_03006844);
                    { Sound_Play(100); goto done; }
                }
                else
                {
                    if (LIST[TOP + ROW + 2] != END)
                    {
                        ROW += 2;
                        { Sound_Play(100); goto done; }
                    }
                    if (ROW != 5)
                        goto done;
                    if (LIST[TOP + ROW + 1] == END)
                        goto done;
                    ROW++;
                    { Sound_Play(100); goto done; }
                }
            }
            if (LIST[TOP + ROW + 2] == END)
                goto done;
            ROW += 2;
            { Sound_Play(100); goto done; }
        }
        goto done;
    }
    else if (gRepeatedKeys & 0x20)
    {
        /* left: from the right column, or wrapping from the left one */
        if ((u16)(gUnk_03006844 - 2) > 1)
            goto done;
        if (ROW == 1 || ROW == 3 || ROW == 5 || ROW == 7)
        {
            ROW--;
            { Sound_Play(100); goto done; }
        }
        if (TOP + ROW >= gUnk_03006604)
            goto done;
        ROW++;
        { Sound_Play(100); goto done; }
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
            { Sound_Play(100); goto done; }
        }
        ROW--;
        { Sound_Play(100); goto done; }
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
    else if (gNewKeys & 2)
    {
        if (gUnk_03006670 != 0)
            goto done;
        task->result = 1;
        Sound_Play(0x66);
        if ((s16)gScriptWaitState != 0x18)
            goto cancel;
        gScriptWaitState = 0x37;
    }
    goto done;
shift2:
    ROW--;
    TOP += 2;
    MsgWindow_DrawItemList(gUnk_03006844);
    { Sound_Play(100); goto done; }
shift3:
    ROW--;
    TOP += 2;
    MsgWindow_DrawItemList(gUnk_03006844);
    Sound_Play(100);
    goto done;
cancel:
    gScriptWaitState = 0x1C;
done:
    sub_0812F010();
}
