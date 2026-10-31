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

u32 sub_0812F188(u16 i);           /* returns u16; the callers here use the full int */
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
/* gUnk_03006620 (u16[] in bmenu2.h) as the struct array it is; indexing a real array
   (not a cast pointer) gives the original base-then-index address order */
#define gMsgPriceSlots gUnknown_03006620
extern struct MsgPriceSlot gMsgPriceSlots[3];

/* Queues the names of the list entries 0x0203DB88[0x03006940...] (0xFFFF-ended, at most 8)
   as glyphs, one row per layout position. A name is a 0x301-ended glyph string reached
   through a pointer table (0x08036666 inside a sub-script, 0x08036156 in battle, else
   0x0803631E), drawn with a fixed 13-pixel advance. Layout 4 (shop) also shows each price
   in a number slot and greys out (attr 4) what the money does not cover. All rows share
   the 64-entry glyph queue: past that, every further glyph overwrites entry 63. */
// MsgWindow_DrawItemList @ 0x0812F2B4
void MsgWindow_DrawItemList(u16 layout)
{
    u16 pos;
    u16 y;
    u16 *saved;
    u32 price;
    u32 money;
    u16 entry;
    s16 row;

    pos = 0;
    price = 0;          /* also the zero stored below */
    money = Money_Get();

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
    while (gUnk_0203DB88[entry] != 0xFFFF)
    {
        u16 x;
        u16 attr;
        u16 k;
        u16 g;
        u16 id;
        u16 j;

        if (gUnknown_0878FBA4[layout][pos] == 0xFFFF)
            goto done;
        x = gUnknown_0878FBA4[layout][pos++];
        y = gUnknown_0878FBA4[layout][pos++];
        if (gUnk_030069CC)
            gScriptBase = (u16 *)gUnknown_08036666;
        else if (gUnk_03006670 == 1)
            gScriptBase = (u16 *)gUnknown_08036156;
        else
            gScriptBase = (u16 *)gUnknown_0803631E;
        id = gUnk_0203DB88[entry];
        j = id * 2;
        {
            u32 lo = gScriptBase[j];
            u32 hi = gScriptBase[j + 1];

            gScriptBase = (u16 *)((hi << 16) | lo);
        }
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
            u16 n = gMsgGlyphCount;
            u16 q = n * 4;

            gMsgGlyphQueue[q++] = g;
            gMsgGlyphQueue[q++] = x;
            gMsgGlyphQueue[q++] = y;
            gMsgGlyphQueue[q++] = attr;
            gMsgGlyphCount = n + 1;
            if ((u16)(n + 1) > 0x3F)
                gMsgGlyphCount = 0x3F;
            x += 13;
        }
        if ((s16)gUnk_03006844 == 4 && row < 3)
        {
            gMsgPriceSlots[row].active = 1;
            gMsgPriceSlots[row].value = price;
            gMsgPriceSlots[row].unk8 = 0x80;
            gMsgPriceSlots[row].y = gUnknown_0878FC64[row];
            gMsgPriceSlots[row].attr = attr;
        }
        entry++;
        if (++row > 7)
            break;
    }
done:
    gScriptBase = saved;
}


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
