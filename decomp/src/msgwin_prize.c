/* Script message window: the casino prize exchange window (opened by the script, prizes from
   gUnknown_0878FEA8, see casinoprize_a.c). gUnk_0300696C is the cursor row (0-2) and
   gUnk_03006940 the first listed prize. */

#include "global.h"
#include "bmenu2.h"

extern const u16 gUnknown_0878FBA4[][16];  /* cursor x, y per row, by window layout */
extern const u16 gUnknown_0878FEA8[][16];  /* per prize set: count, then (item, price) */
extern u16 gScriptItemCheckId;

u16 CasinoPrize_GetSet(void);
void CasinoPrize_DrawList(u16 first);
u32 sub_080C31F0(void);
void sub_080C31B4(s32 delta);
void Inventory_AddItem(u16 id);

#define sTop (*(s16 *)&gUnk_03006940)

/* Wait handler: up/down move the cursor (scrolling the list at the ends), L/R jump a page.
   A buys the prize when the coins (sub_080C31F0) cover the price (0xFFFF = 100000, never)
   and fewer than 99 are owned (inventory + equipped), jumping to the script's 3rd target;
   otherwise to the 1st (too few coins) or 2nd (too many owned). B ends the wait. */
// CasinoPrize_ExchangeInput @ 0x08131400
void CasinoPrize_ExchangeInput(struct Task *task)
{
    u32 price = 0;     /* also the zero stored below (keeps the original register use) */
    u16 set;

    set = CasinoPrize_GetSet();
    gUnk_0300689C = gUnknown_0878FBA4[(s16)gUnk_03006844][gUnk_0300696C * 2] - 2;
    gUnk_0300695C = gUnknown_0878FBA4[(s16)gUnk_03006844][gUnk_0300696C * 2 + 1];
    gUnk_030066A0 = 0x17;
    if (gUnk_0300696C == 2)
        gUnk_030066A0 = 0x16;
    gUnk_03006958 = 1;
    if (gRepeatedKeys & 0x200)
    {
        if (gUnk_0300696C != 0)
        {
            gUnk_0300696C = price;
            Sound_Play(100);
        }
        else
        {
            if (sTop - 3 >= 0)
                sTop -= 3;
            else
                sTop = price;
            CasinoPrize_DrawList(gUnk_03006940);
            Sound_Play(100);
        }
    }
    else if (gRepeatedKeys & 0x100)
    {
        if (gUnk_0300696C != 2)
        {
            gUnk_0300696C = 2;
            return;
        }
        if (gUnk_0300696C + sTop < gUnknown_0878FEA8[set][0] - 2)
            sTop += 3;
        else
            sTop = gUnknown_0878FEA8[set][0] - 2;
        CasinoPrize_DrawList(gUnk_03006940);
        Sound_Play(100);
    }
    else if (gRepeatedKeys & 0x40)
    {
        if (gUnk_0300696C != 0)
        {
            gUnk_0300696C--;
            Sound_Play(100);
        }
        else
        {
            if (sTop == 0)
                return;
            sTop--;
            CasinoPrize_DrawList(gUnk_03006940);
            Sound_Play(100);
        }
    }
    else if (gRepeatedKeys & 0x80)
    {
        if (gUnk_0300696C == 2)
        {
            if (gUnk_0300696C + sTop >= gUnknown_0878FEA8[set][0])
                return;
            sTop++;
            CasinoPrize_DrawList(gUnk_03006940);
            Sound_Play(100);
        }
        else
        {
            gUnk_0300696C++;
            Sound_Play(100);
        }
    }
    else if (gNewKeys & 1)
    {
        task->result = 1;
        gScriptWaitState = price;
        gScriptItemCheckId = gUnknown_0878FEA8[set][(gUnk_0300696C + sTop) * 2 + 1];
        price = gUnknown_0878FEA8[set][(gUnk_0300696C + sTop) * 2 + 2];
        if (price == 0xFFFF)
            price = 100000;
        if (sub_080C31F0() < price)
        {
            gScriptJumpTarget = gUnk_0203DAC8[0];
            Sound_Play(0x66);
        }
        else if ((u8)Inventory_GetCount(gScriptItemCheckId)
                     + Party_CountEquipped(0xFF, gScriptItemCheckId) > 98)
        {
            gScriptJumpTarget = gUnk_0203DAC8[1];
            Sound_Play(0x66);
        }
        else
        {
            Inventory_AddItem(gScriptItemCheckId);
            sub_080C31B4(-price);
            gScriptJumpTarget = gUnk_0203DAC8[2];
            Sound_Play(0x65);
        }
    }
    else if (gNewKeys & 2)
    {
        task->result = 1;
        gScriptWaitState = 0;
        Sound_Play(0x66);
    }
}
