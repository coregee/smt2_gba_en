/* Script VM opcode handlers 0x33B-0x35F: shop lists, choices, alignment and party checks. */

#include "global.h"
#include "scriptops3.h"

/* The original indexes these two tables through their constant addresses (index computed
   before the base is loaded), not through the extern symbols. */
#define SHOP_PRICES ((u32 *)0x0203BD74)               /* gShopItemPrices */
#define SHOP_ROWS   ((struct ShopRow *)0x03006620)    /* gUnk_03006620 */

// sub_08134250 @ 0x08134250
void sub_08134250(u16 first)
{
    u16 i, j, id;
    u16 pal;
    u16 *name;
    u32 price;

    pal = 0;
    gMsgGlyphList2Count = pal;
    gUnk_0300699C = 1;
    if (first == 0)
    {
        gUnk_03006848 = pal;
        gUnk_03006680 = 1;
    }
    else if (first == 9)
    {
        gUnk_03006848 = 1;
        gUnk_03006680 = 0;
    }
    else
    {
        gUnk_03006848 = 1;
        gUnk_03006680 = 1;
    }
    for (i = 0; i < 100; i++)
        gMsgGlyphList2[i] = 0;
    i = first;
    if (i >= first + 3)
        return;
    goto check;
    do
    {
        price = SHOP_PRICES[i];
        pal = 4;
        if (price != 0)
            pal = 0;
        name = (u16 *)(Action_GetRecord(id) + 0xC);
        for (j = 0; j < 16; j++)
            gScriptSubstBuf[j] = 0;
        for (j = 0; j < 8; j++)
            gScriptSubstBuf[j] = *name++;
        sub_08133724(0x27, gUnknown_0879038A[i - first], pal, 8);
        SHOP_ROWS[i - first].unk0 = 1;
        gUnk_03006624[(i - first) * 4] = SHOP_PRICES[i];
        SHOP_ROWS[i - first].unk8 = 0x80;
        SHOP_ROWS[i - first].y = gUnknown_0878FC64[i - first];
        SHOP_ROWS[i - first].palette = pal;
        i++;
        if (i >= first + 3)
            return;
    check:
        id = gShopItemIds[i];
    } while (id != 0xFFFF);
}

// ScriptOp_33B @ 0x081343AC
void ScriptOp_33B(void)
{
    u16 lo;
    u32 target;
    u16 i;

    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    gUnk_0203DAC8[0] = (u16 *)target;
    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    gUnk_0203DAC8[1] = (u16 *)target;
    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    gUnk_0203DAC8[2] = (u16 *)target;
    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    gUnk_0203DAC8[3] = (u16 *)target;
    gUnk_0203DAC8[4] = 0;
    for (i = 0; i < 256; i++)
    {
        gShopItemIds[i] |= 0xFFFF;
        gShopItemPrices[i] = -1;
    }
    gUnk_03006688 = gUnknown_0878EFB8[gUnk_03006914][0] + 1;
    for (i = 0; i < gUnk_03006688; i++)
    {
        gShopItemIds[i] = gUnknown_0878EFB8[gUnk_03006914][i + 1];
        gShopItemPrices[i] = sub_080C4C60(gShopItemIds[i]);
    }
    gScriptWaitState = 0x22;
    for (i = 0; i < 15; i++)
        gUnk_03006820[i] = gMsgGlyphQueue[i * 4];
    gUnk_03006940 = 0;
    gUnk_0300696C = 0;
    gUnk_030065E4 = 0;
    Shop_InitItemList(0, 0);
    gUnk_030068A4 = sub_080D3400(1, (u16)gUnk_03006898, gShopItemIds[0]);
    Task_Create(gUnknown_0878FD58, 0xFFFF);
    gScriptYield = 1;
}

// ScriptOp_33C @ 0x08134568
void ScriptOp_33C(void)
{
    u16 lo;
    u32 target;

    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    if (gUnk_030069A8 < 0xD0 && Equip_CanEquip(gUnk_03006898, gUnk_030069A8) == 0)
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_33D @ 0x081345CC
void ScriptOp_33D(void)
{
    s32 sell = 0;
    u16 i;
    u16 lo;
    u32 target;

    for (i = 0; i < 15; i++)
        gUnk_03006820[i] = gMsgGlyphQueue[i * 4];
    gUnk_030065FC = SCRIPT_READ();
    if (gUnk_030065FC == 0xFF)
    {
        gUnk_030065FC = 1;
        sell = 1;
    }
    gScriptWaitState = 0x25;
    if (sell)
        gScriptWaitState = 0x2A;
    Shop_InitItemList(gUnk_03006940, gUnk_030065E4);
    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    gUnk_0203DAC8[0] = (u16 *)target;
    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    gUnk_0203DAC8[1] = (u16 *)target;
    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    gUnk_0203DAC8[2] = (u16 *)target;
    gMsgGlyphList2[gMsgGlyphList2Count * 4] = 0x3E;
    gMsgGlyphList2[gMsgGlyphList2Count * 4 + 1] = 0xBC;
    gMsgGlyphList2[gMsgGlyphList2Count * 4 + 2] = gUnknown_0879038A[gUnk_0300696C];
    gMsgGlyphList2[gMsgGlyphList2Count * 4 + 3] = 0;
    gMsgGlyphList2Count = 0x19;
    gUnk_03006620[3].unk0 = 1;
    gUnk_03006620[3].price = (s16)(gUnk_030065FC % 10);
    gUnk_03006620[3].unk8 = 0x98;
    gUnk_03006620[3].y = gUnknown_0878FC64[gUnk_0300696C];
    gUnk_03006620[3].palette = 0;
    gUnk_03006620[4].unk0 = 1;
    gUnk_03006620[4].price = (s16)(gUnk_030065FC / 10);
    gUnk_03006620[4].unk8 = 0x90;
    gUnk_03006620[4].y = gUnknown_0878FC64[gUnk_0300696C];
    gUnk_03006620[4].palette = 0;
    gUnk_030068A4 = sub_080D3400(2, (u16)gUnk_03006898, gShopItemIds[gUnk_0300696C + gUnk_03006940]);
    gUnk_03006694 = sub_080C4C60(gShopItemIds[gUnk_0300696C + gUnk_03006940]);
    gScriptWaitState = 0x25;
    if (sell)
    {
        gScriptWaitState = 0x2A;
        gUnk_03006694 = sub_080C4C7C(gShopItemIds[gUnk_0300696C + gUnk_03006940]);
    }
    gUnk_0203DB2C = gUnk_030065FC * gUnk_03006694;
    if (gUnk_0203DB2C > 999999)
        gUnk_0203DB2C = 999999;
    Task_Create(gUnknown_0878FF8C, 0xFFFF);
    gScriptYield = 1;
}

// ScriptOp_33E @ 0x08134854
void ScriptOp_33E(void)
{
    u16 lo;
    u32 target;

    lo = SCRIPT_READ();
    target = SCRIPT_READ();
    target = target << 16 | lo;
    if (gUnk_030069A8 >= 0xD0)
        gScriptJumpTarget = (u16 *)target;
    if (Equip_CanEquip(gUnk_03006898, gUnk_030069A8) == 0)
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_33F @ 0x081348B8
void ScriptOp_33F(void)
{
    u16 i;

    for (i = 0; i < gUnk_030065FC; i++)
        Inventory_AddItem(gScriptItemCheckId);
    sub_080CDFBC(gUnk_03006898, gScriptItemCheckId);
}

// ScriptOp_340 @ 0x081348FC
void ScriptOp_340(void)
{
}

// ScriptOp_Choice @ 0x08134900
void ScriptOp_Choice(void)
{
    u16 op, n;
    s16 i;
    u16 lo;
    u32 target;

    gUnk_030065E0 = 0xFFFF;
    op = SCRIPT_READ();
    n = op >> 8;
    op &= 0xFF;
    gUnk_03006844 = op;
    if (gUnk_03006844 > 3)
        gUnk_03006844 = 0;
    if (gUnk_03006844 == 1 || gUnk_03006844 == 3)
        MsgWindow_SaveGlyphs();
    for (i = 0; i < 20; i++)
        gUnk_0203DB88[i] |= 0xFFFF;
    gUnk_03006604 = n;
    for (i = 0; i < gUnk_03006604 + 1; i++)
    {
        gUnk_0203DB88[i] = SCRIPT_READ();
        lo = SCRIPT_READ();
        target = SCRIPT_READ();
        target = target << 16 | lo;
        gUnk_0203DAC8[i] = (u16 *)target;
    }
    gUnk_03006940 = 0;
    gUnk_0300696C = 0;
    MsgWindow_DrawItemList((u16)gUnk_03006844);
    gScriptYield = 1;
    Task_Create(gUnknown_0878FC80, 0xFFFF);
    gScriptWaitState = 0xD;
}

// ScriptOp_352 @ 0x08134A48
void ScriptOp_352(void)
{
    u16 id = SCRIPT_READ();

    if (id < 100)
        Music_Play(id);
    else
        Sound_Play(id);
}

// ScriptOp_353 @ 0x08134A78
void ScriptOp_353(void)
{
    s32 d = SCRIPT_READ();

    d <<= 8;

    if (d > 0x7FFF)
        d |= 0xFFFF0000;
    Combatant_AddAlignment(0, d);
    Combatant_AddAlignment(1, d);
}

// ScriptOp_354 @ 0x08134AC0
void ScriptOp_354(void)
{
}

// ScriptOp_355 @ 0x08134AC4
void ScriptOp_355(void)
{
    u16 lo;
    u32 hi;
    s32 a = Combatant_GetAlignment(0);

    if (a == 0)
    {
        lo = SCRIPT_READ();
        hi = gScriptBase[gScriptPc];
        goto jump;
    }
    if (a == 2)
    {
        lo = gScriptBase[gScriptPc + 2];
        hi = gScriptBase[gScriptPc + 3];
    jump:
        hi <<= 16;
        hi |= lo;
        gScriptJumpTarget = (u16 *)hi;
        return;
    }
    gScriptPc += 4;
}

// ScriptOp_356 @ 0x08134B34
void ScriptOp_356(void)
{
    u32 range;
    u16 min, max;
    u32 v;
    u16 lo;
    u32 target;

    range = SCRIPT_READ();
    max = (range & 0xFF) + 1;
    min = (range >> 8) & 0xFF;
    v = sub_080C0794(0) >> 8;
    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    if (v >= min && v < max)
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_357 @ 0x08134BA8
void ScriptOp_357(void)
{
    u16 level = SCRIPT_READ();
    u16 lo;
    u32 target;

    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    if (Combatant_GetLevel(0) <= level)
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_358 @ 0x08134C00
void ScriptOp_358(void)
{
    gUnk_0203DB5C = SCRIPT_READ();
    gScriptWaitState = 0xF;
    gScriptYield = 1;
}

// sub_08134C3C @ 0x08134C3C
u32 sub_08134C3C(void)
{
    return 0;
}

// ScriptOp_359 @ 0x08134C40
void ScriptOp_359(void)
{
    s32 count = 0;
    u16 idx, id;
    s32 n;
    u32 i;
    u16 lo;
    u32 hi;

    idx = SCRIPT_READ();
    id = gUnk_0203DB28[idx - 1];
    n = Stock_GetCapacity();
    for (i = 4; i < n + 4; i++)
    {
        if (Combatant_IsUsed(i) && Combatant_GetDemonId(i) == id)
            count++;
    }
    if (count)
    {
        gScriptPc += 2;
    }
    else
    {
        lo = SCRIPT_READ();
        hi = gScriptBase[gScriptPc];
        hi <<= 16;
        hi |= lo;
        gScriptJumpTarget = (u16 *)hi;
    }
}
