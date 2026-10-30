/* Script message window: the shop's item list (buy and sell). */

#include "global.h"
#include "bmenu2.h"

extern u16 gShopItemIds[];     /* item ids of the list */
extern u32 gShopItemPrices[];     /* sale price of each list entry */
extern u16 gUnk_030069A8;       /* chosen item */
extern s16 gUnk_030065FC;       /* quantity */
extern u32 gUnk_0203DB2C;
extern u16 gScriptItemCheckId;
extern u16 gUnk_03006920[];
extern u16 gUnk_0300699C;
extern u16 gMsgGlyphList2Count;

void Shop_InitItemList(u16 top, u16 showOwned);
void sub_080D34A4(struct Task *task, u16 a, u16 b, u16 item);
u32 sub_080C4C60(u16 item);

#define ROW (*(s16 *)&gUnk_0300696C)
#define TOP (*(s16 *)&gUnk_03006940)
#define COUNT gUnk_03006688

/* Wait handler of the shop list (wait state 0x28 sell, else buy; 3 rows on screen, row
   0x0300696C, first entry 0x03006940, 0x03006688 entries in 0x0203BB74). Up/down move the
   cursor and scroll at the ends (wrapping when everything fits), L/R move a page; each move
   redraws the description (sub_080D34A4) and the list (Shop_InitItemList, which also draws the
   owned-count header when 0x030065E4 is set). SELECT toggles that header: see
   engine/script/patch_shopowned.py, which hooks Shop_InitItemList and sub_081305D8 for it.
   A on a sale: wait state 0x29, or 0x23 with the script's 3rd target (money would pass
   999,999). A on a purchase: wait state 0x23 and the quantity window with quantity 1 and the
   price in gUnk_0203DB2C, or the 3rd target (99 owned) / 1st target (too little money).
   B leaves (wait state 0x24, or 0 and the 2nd target when selling). */
// Shop_ListInput @ 0x08130694
void Shop_ListInput(struct Task *task)
{
    u16 id;
    u16 keys;   /* key mask; the dead `keys = 0` stores below decide how the compiler shares
                   the redraw code between the branches */

    gUnk_0300689C = gUnknown_0878FCC4[ROW * 2] + 14;
    gUnk_0300695C = gUnknown_0878FCC4[ROW * 2 + 1];
    gUnk_030066A0 = 0x13;
    gUnk_03006958 = 1;
    if (*(s16 *)&gUnk_030068D4 != 0)
    {
        (*(s16 *)&gUnk_030068D4)--;
        return;
    }
    if ((u16)(gNewKeys & 4))
    {
        gUnk_030065E4 ^= 1;
        Shop_InitItemList(gUnk_03006940, gUnk_030065E4);
        gUnk_030068D4 = 1;
        return;
    }
    if (gRepeatedKeys & 0x200)
    {
        if (ROW != 0)
        {
            ROW = 0;
            sub_080D34A4(gUnk_030068A4, 1, gUnk_03006898, gShopItemIds[ROW + TOP]);
            Sound_Play(100);
            goto list;
        }
        else if (TOP - 3 >= 0)
        {
            TOP -= 3;
            sub_080D34A4(gUnk_030068A4, 1, gUnk_03006898, gShopItemIds[ROW + TOP]);
            Sound_Play(100);
            goto list;
        }
        else if (TOP != 0)
        {
            TOP = 0;
            sub_080D34A4(gUnk_030068A4, 1, gUnk_03006898, gShopItemIds[ROW + TOP]);
            Sound_Play(100);
        }
        keys = 0;
    }
    else if (gRepeatedKeys & 0x100)
    {
        if (ROW != 2)
        {
            if (COUNT <= 2)
                ROW = COUNT - 1;
            else
                ROW = 2;
            Sound_Play(100);
            sub_080D34A4(gUnk_030068A4, 1, gUnk_03006898, gShopItemIds[ROW + TOP]);
            goto list;
        }
        else if (ROW + TOP < COUNT - 3)
        {
            TOP += 3;
            sub_080D34A4(gUnk_030068A4, 1, gUnk_03006898, gShopItemIds[ROW + TOP]);
            Sound_Play(100);
            goto list;
        }
        else if (TOP != COUNT - 3)
        {
            TOP = COUNT - 3;
            sub_080D34A4(gUnk_030068A4, 1, gUnk_03006898, gShopItemIds[ROW + TOP]);
            Sound_Play(100);
        }
        keys = 0;
    }
    else if ((keys = gRepeatedKeys & 0x40))
    {
        if (ROW != 0)
        {
            ROW--;
            sub_080D34A4(gUnk_030068A4, 1, gUnk_03006898, gShopItemIds[ROW + TOP]);
            Sound_Play(100);
            goto list;
        }
        else if (TOP != 0)
        {
            TOP--;
            sub_080D34A4(gUnk_030068A4, 1, gUnk_03006898, gShopItemIds[ROW + TOP]);
            Sound_Play(100);
            goto list;
        }
        else if (COUNT <= 3)
        {
            ROW = COUNT - 1;
            sub_080D34A4(gUnk_030068A4, 1, gUnk_03006898, gShopItemIds[ROW + TOP]);
            Sound_Play(100);
        }
        keys = 0;
    }
    else if ((u16)(gRepeatedKeys & 0x80))
    {
        u16 row = ROW;
        if (ROW == 2)
        {
            if (COUNT == 3)
            {
                ROW = 0;
                sub_080D34A4(gUnk_030068A4, 1, gUnk_03006898, gShopItemIds[ROW + TOP]);
                Sound_Play(100);
                goto list;
            }
            else if (ROW + TOP < COUNT - 1)
            {
                TOP++;
                sub_080D34A4(gUnk_030068A4, 1, gUnk_03006898, gShopItemIds[ROW + TOP]);
                Sound_Play(100);
                goto list;
            }
            else
                goto list;
        }
        else
        {
            if (COUNT <= 2)
            {
                if (ROW >= COUNT - 1)
                    ROW = 0;
                else
                    ROW = row + 1;
            }
            else
                ROW = row + 1;
            sub_080D34A4(gUnk_030068A4, 1, gUnk_03006898, gShopItemIds[ROW + TOP]);
            Sound_Play(100);
        }
    }
    else
        goto other;
list:
    Shop_InitItemList(gUnk_03006940, gUnk_030065E4);
    gUnk_030068D4 = 1;
    return;
other:
    if ((keys = gNewKeys & 1))
    {
        task->result = 1;
        sub_080D34F0(gUnk_030068A4);
        if ((s16)gScriptWaitState == 0x28)
        {
            gScriptWaitState = 0x29;
            gUnk_030069A8 = gShopItemIds[ROW + TOP];
            if (Money_Get() + gShopItemPrices[ROW + TOP] > 999999)
            {
                gUnk_0203DAC8[4] = gUnk_0203DAC8[2];
                gScriptWaitState = 0x23;
                gUnk_03006958 = 0;
                Sound_Play(0x66);
            }
            else
                Sound_Play(0x65);
        }
        else
        {
            gScriptWaitState = 0x23;
            id = gShopItemIds[ROW + TOP];
            if ((u8)Inventory_GetCount(id) + Party_CountEquipped(0xFF, id) > 98)
            {
                gUnk_0203DAC8[4] = gUnk_0203DAC8[2];
                gUnk_03006958 = 0;
                Sound_Play(0x66);
            }
            else if (sub_080C4C60(id) > Money_Get())
            {
                gUnk_0203DAC8[4] = gUnk_0203DAC8[0];
                gUnk_03006958 = 0;
                Sound_Play(0x66);
            }
            else
            {
                gUnk_0203DAC8[4] = 0;
                gUnk_030069A8 = id;
                gUnk_030065FC = 1;
                gUnk_0203DB2C = sub_080C4C60(gUnk_030069A8);
                gScriptItemCheckId = gUnk_030069A8;
                {
                    u16 *slots = gUnk_03006620;
                    gUnk_03006920[8] = 0;
                    gUnk_03006920[4] = 0;
                    gUnk_03006920[0] = 0;
                    slots[32] = 0;
                    slots[24] = 0;
                    slots[16] = 0;
                    slots[8] = 0;
                    slots[0] = 0;
                }
                gUnk_0300699C = 0;
                gMsgGlyphList2Count = 0;
                sub_080D34F0(gUnk_030068A4);
                gUnk_03006958 = 0;
                Sound_Play(0x65);
            }
        }
    }
    else if (gNewKeys & 2)
    {
        task->result = 1;
        if ((s16)gScriptWaitState == 0x28)
        {
            gScriptWaitState = 0;
            gScriptJumpTarget = gUnk_0203DAC8[1];
        }
        else
            gScriptWaitState = 0x24;
        gUnk_0300699C = 0;
        {
            u16 *slots = gUnk_03006620;
            gUnk_03006920[8] = 0;
            gUnk_03006920[4] = 0;
            gUnk_03006920[0] = 0;
            slots[32] = 0;
            slots[24] = 0;
            slots[16] = 0;
            slots[8] = 0;
            slots[0] = 0;
        }
        gUnk_03006958 = 0;
        sub_080D34F0(gUnk_030068A4);
        Sound_Play(0x66);
    }
}
