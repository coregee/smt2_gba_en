/* Script VM opcode handler 0x410: conditional jumps and screens for the event/casino
   scripts. Operands: mode, target 1, target 2. */

#include "global.h"
#include "scriptops2.h"

// ScriptOp_410 @ 0x081399F0
void ScriptOp_410(void)
{
    u16 mode = SCRIPT_READ();
    u16 lo = SCRIPT_READ();
    u32 t2;
    u32 t1 = SCRIPT_READ();
    u16 i, v;

    t1 = t1 << 16 | lo;
    lo = SCRIPT_READ();
    t2 = SCRIPT_READ();
    t2 = t2 << 16 | lo;
    if (mode == 1)
    {
        if (gUnknown_08790C1C[gUnk_03006914] > 4)
            gScriptJumpTarget = (u16 *)t2;
        else
            gScriptJumpTarget = (u16 *)t1;
    }
    else if (mode == 2)
    {
        if (gUnknown_08790C1C[gUnk_03006914] == 2)
            gScriptJumpTarget = (u16 *)t1;
    }
    else if (mode == 3)
    {
        if (gUnknown_08790C1C[gUnk_03006914] == 3)
            gScriptJumpTarget = (u16 *)t1;
    }
    else if (mode == 4)
    {
        if (gUnknown_08790C1C[gUnk_03006914] == 4)
            gScriptJumpTarget = (u16 *)t1;
    }
    else if (mode == 5)
    {
        if (gUnknown_08790C1C[gUnk_03006914] == 5)
            gScriptJumpTarget = (u16 *)t1;
    }
    else if (mode == 6)
    {
        if (gUnknown_08790C1C[gUnk_03006914] == 6)
            gScriptJumpTarget = (u16 *)t1;
    }
    else if (mode == 7)
    {
        if (gUnknown_08790C1C[gUnk_03006914] == 7)
            gScriptJumpTarget = (u16 *)t1;
    }
    else if (mode == 8)
    {
        if (sub_080C2A84(0) == 1 || sub_080C2A84(1) == 1 || sub_080C2A84(2) == 1)
            gScriptJumpTarget = (u16 *)t1;
    }
    else if (mode == 9)
    {
        sub_080D3A80();
        gUnk_0203DAC8[0] = (u16 *)t1;
        gScriptWaitState = 0x50;
        gScriptYield = 1;
    }
    else if (mode == 10)
    {
        gUnk_0203DAC8[0] = (u16 *)t1;
        sub_080D3AA0(2);
        gScriptWaitState = 0x50;
        gScriptYield = 1;
    }
    else if (mode == 11)
    {
        gUnk_0203DAC8[0] = (u16 *)t1;
        gUnk_0203DAC8[1] = (u16 *)t2;
        sub_080D3CAC();
        gScriptWaitState = 0x51;
        gScriptYield = 1;
    }
    else if (mode == 12)
    {
        /* jump 1 when no item 0x12C-0x159 is owned */
        for (i = 0x12C; i <= 0x159; i++)
        {
            if (Inventory_GetCount(i))
                return;
        }
        gScriptJumpTarget = (u16 *)t1;
    }
    else if (mode == 13)
    {
        if (Money_Get() < gUnk_0203DB2C)
            gScriptJumpTarget = (u16 *)t1;
    }
    else if (mode == 14)
    {
        if (Combatant_GetLevel(0) > 20 && Inventory_GetCount(0x11F))
            gScriptJumpTarget = (u16 *)t1;
    }
    else if (mode == 15)
    {
        gUnk_0203DAC8[0] = (u16 *)t1;
        gUnk_0203DAC8[1] = (u16 *)t2;
        sub_080D3DF0();
        gScriptWaitState = 0x51;
        gScriptYield = 1;
    }
    else if (mode == 16)
    {
        v = gShopItemIds[0];
        if (v == 2)
            sub_0813999C(3);
        else if (v == 1)
        {
            if (sub_081398C8() == 1)
                gScriptJumpTarget = (u16 *)t1;
        }
        else if (sub_081397D8() == 1)
            gScriptJumpTarget = (u16 *)t1;
    }
    else if (mode == 17)
    {
        i = gShopItemIds[2];
        v = gShopItemIds[0];
        if (v == 2)
        {
            if (i == 0xF3)
                gScriptJumpTarget = (u16 *)t1;
        }
        else if (v == 0)
        {
            if (i == 10)
                gScriptJumpTarget = (u16 *)t1;
        }
        else if (i == 5)
            gScriptJumpTarget = (u16 *)t1;
    }
    else if (mode == 18)
    {
        i = gShopItemIds[0];
        if (i == 0)
            gScriptJumpTarget = (u16 *)t1;
        else if (i == 1)
            gScriptJumpTarget = (u16 *)t2;
    }
    else if (mode == 19)
    {
        i = gShopItemIds[1];
        if (i == 0)
            gScriptJumpTarget = (u16 *)t1;
        else if (i == 1)
            gScriptJumpTarget = (u16 *)t2;
    }
    else if (mode == 20)
    {
        i = gShopItemIds[2];
        if ((u16)(i % 10) == 0)
            gScriptJumpTarget = (u16 *)t2;
    }
    else if (mode == 21)
    {
        if (Inventory_GetCount(0x11F) && Combatant_IsAlive(0) == 1 && Combatant_GetLevel(0) > 20)
        {
            /* the results are ignored: this loop has no effect */
            for (i = 0; i < 12; i++)
                Combatant_IsUsed(i + 4);
            if (Flag_Test(0xD4) != 1)
            {
                Flag_Set(0xD4);
                gScriptJumpTarget = (u16 *)t2;
            }
        }
    }
    else if (mode == 22)
    {
        gUnk_0203DAC8[0] = (u16 *)t1;
        gScriptWaitState = 10;
        gUnk_030068E0 = YesNo_Create(1);
        gScriptYield = 1;
    }
    else if (mode == 23)
    {
        if (!Stock_HasRoom())
            gScriptJumpTarget = (u16 *)t1;
        else if (sub_080C5C7C() > 2)
            gScriptJumpTarget = (u16 *)t2;
    }
    else
    {
        gScriptJumpTarget = (u16 *)t1;
        gUnk_03006840 = t2;
    }
}
