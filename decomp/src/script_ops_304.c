/* Script VM opcode handlers 0x304-0x319. */

#include "global.h"
#include "script.h"

// ScriptOp_304 @ 0x081323D4
void ScriptOp_304(void)
{
    u16 a = SCRIPT_READ();
    u16 b = SCRIPT_READ();
    u16 c = SCRIPT_READ();
    u16 hi = c >> 8;
    u16 lo = c & 0xFF;
    u16 f1 = a & 0x10;
    u32 t1 = f1 != 0;
    u16 f2 = a & 0x20;
    u32 t2 = f2 != 0;

    gUnk_030068F0[a & 0xF] = CharObj_Create(a, b, hi, lo, t1, t2);
    if (*(u32 *)(Char_GetRecord(b) + 0x28) != 0)
        gScriptYield = 1;
}

// ScriptOp_305 @ 0x08132464
void ScriptOp_305(void)
{
    gUnk_030068B0 = BgPicture_StartTask(SCRIPT_READ());
    gScriptWaitState = 2;
    gScriptYield = 1;
}

// ScriptOp_SkipOperand @ 0x081324A8
void ScriptOp_SkipOperand(void)
{
    gScriptPc++;
}

// ScriptOp_307 @ 0x081324B8
void ScriptOp_307(void)
{
    u16 i = SCRIPT_READ();

    if (gUnk_030069C0[i] != 0)
    {
        sub_080E9044(gUnk_030069C0[i], i);
        gUnk_030069C0[i] = 0;
    }
    else
    {
        CharObj_End(gUnk_030068F0[i], 0);
        gUnk_030068F0[i] = 0;
    }
}

// ScriptOp_308 @ 0x0813250C
void ScriptOp_308(void)
{
    gUnk_0203DB28[0] = (u8)SCRIPT_READ();
    gUnk_03006970[0] = 1;
    gUnk_0203DB66 = 1;
}

// ScriptOpAlt_Skip3 @ 0x08132544
void ScriptOpAlt_Skip3(void)
{
    gScriptPc += 3;
}

// ScriptOpAlt_Skip2 @ 0x08132554
void ScriptOpAlt_Skip2(void)
{
    gScriptPc += 2;
}

// ScriptOpAlt_Skip1 @ 0x08132564
void ScriptOpAlt_Skip1(void)
{
    gScriptPc += 1;
}

// ScriptOp_309 @ 0x08132574
void ScriptOp_309(void)
{
    u16 a = SCRIPT_READ();
    u32 i = a & 0xF;

    gUnk_030069C0[a] = sub_080E8E00(a, gUnk_0203DB28[i]);
}

// ScriptOp_SetItemCheckId @ 0x081325BC
void ScriptOp_SetItemCheckId(void)
{
    gScriptItemCheckId = SCRIPT_READ();
}

// ScriptOp_JumpIfItemMissing @ 0x081325E4
void ScriptOp_JumpIfItemMissing(void)
{
    u16 flag = gScriptItemCheckId;
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ();

    target = target << 16 | lo;
    if (flag > 299)
    {
        if (KeyItem_IsObtainable(flag) == 1)
        {
            Inventory_AddItem(flag);
            gScriptItemCheckId = flag;
            return;
        }
    }
    else if (Inventory_GetCount(flag))
        return;
    gScriptJumpTarget = (u16 *)target;
}

// ScriptOpAlt_30B @ 0x08132654
void ScriptOpAlt_30B(void)
{
    u16 flag = gScriptItemCheckId;
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ();

    target = target << 16 | lo;
    if (flag > 299)
    {
        if (KeyItem_IsObtainable(flag) == 1)
        {
            gScriptItemCheckId = flag;
            return;
        }
    }
    else if (Inventory_GetCount(flag))
        return;
    gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_JumpIfFlag @ 0x081326C0
// Jumps when Flag_Test(id) (or, for id 0x114, sub_080C2A84(2)) returns 1.
void ScriptOp_JumpIfFlag(void)
{
    u16 id = SCRIPT_READ();
    u16 lo;
    u32 target;

    if (id == 0x114)
    {
        if (sub_080C2A84(2) == 1)
        {
            lo = SCRIPT_READ();
            target = gScriptBase[gScriptPc];
            target <<= 16;
            target |= lo;
            gScriptJumpTarget = (u16 *)target;
        }
        else
        {
            gScriptPc += 2;
        }
    }
    else
    {
        if (Flag_Test(id) == 1)
        {
            lo = SCRIPT_READ();
            target = gScriptBase[gScriptPc];
            target <<= 16;
            target |= lo;
            gScriptJumpTarget = (u16 *)target;
        }
        else
        {
            gScriptPc += 2;
        }
    }
}

// ScriptOp_30D @ 0x08132734
void ScriptOp_30D(void)
{
    u16 b = 0;
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ();
    u16 a, bits;

    target = target << 16 | lo;
    if (Combatant_IsUsed(1) == 0 && Combatant_IsUsed(2) == 0)
        return;
    a = gGameState[0].unk18;
    if (Combatant_IsUsed(1) != 0)
        b = gGameState[1].unk18;
    if (Combatant_IsUsed(2) != 0)
        b = gGameState[2].unk18;
    if (a != 0 && b != 0)
    {
        bits = Combatant_GetStatus(0);
        if (Combatant_IsUsed(1) == 0)
            bits |= Combatant_GetStatus(1);
        if (Combatant_IsUsed(2) == 0)
            bits |= Combatant_GetStatus(2);
        if (!(bits & 0x3000))
            return;
    }
    gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_30E @ 0x081327F8
void ScriptOp_30E(void)
{
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ();

    target = target << 16 | lo;
    gUnk_0203DAC8[0] = (u16 *)target;
    gScriptWaitState = 10;
    gUnk_030068E0 = YesNo_Create(0);
    gScriptYield = 1;
}

// ScriptOp_Jump @ 0x08132858
void ScriptOp_Jump(void)
{
    u16 lo = gScriptBase[gScriptPc];
    u32 target;

    gScriptPc++;
    target = gScriptBase[gScriptPc];
    target <<= 16;
    target |= lo;
    gScriptJumpTarget = (u16 *)target;
}

// sub_08132890 @ 0x08132890
void sub_08132890(void)
{
    if (gUnk_0203DB66 & gUnk_0203DB68)
        sub_080E47A8(1, gUnk_0203DB28[0], gUnk_0203DB28[1], gUnk_03006970[0], gUnk_03006970[1]);
    else if (gUnk_0203DB66 != 0 && gUnk_0203DB68 == 0)
        sub_080E47A8(1, gUnk_0203DB28[0], 0xFFFF, gUnk_03006970[0], 0);
    else
        sub_080E47A8(1, 0xFFFF, gUnk_0203DB28[1], 0, gUnk_03006970[1]);
}

// ScriptOp_CloseMessage @ 0x0813291C
void ScriptOp_CloseMessage(void)
{
    if (SCRIPT_READ() != 0)
        Flag_Set(0xD5);
    else
        Flag_Clear(0xD5);
    gScriptWaitState = 7;
    sub_08132890();
    gUnk_0203DB68 = 0;
    gMsgGlyphCount = 0;
    gTextColumn = 0;
    gTextLine = 0;
    gUnk_0203DB4A = 0;
    if (gMsgWindowOpen != 0)
    {
        Window_Close(gMsgWindow, 1);
        gMsgWindowOpen = 0;
    }
    Font_ResetGlyphSpriteCache(0x180);
    gScriptYield = 1;
}

// ScriptOp_311 @ 0x081329BC
void ScriptOp_311(void)
{
    u16 v = SCRIPT_READ();

    gUnk_030068A8 = v;
}

// ScriptOp_SetFlag @ 0x081329E4
void ScriptOp_SetFlag(void)
{
    Flag_Set(SCRIPT_READ());
}

// ScriptOp_Delay @ 0x08132A0C
void ScriptOp_Delay(void)
{
    if (gUnk_0203DB48 == 1)
    {
        gUnk_0203DB5C = 1;
        gScriptWaitState = 15;
        gScriptYield = 1;
    }
    else
    {
        gUnk_0203DB5C = 20;
        gScriptWaitState = 15;
        gScriptYield = 1;
    }
}

// ScriptOp_316 @ 0x08132A5C
void ScriptOp_316(void)
{
    gScriptWaitState = 3;
    Task_Create(gUnknown_087900EC, 0xFFFF);
    gUnk_0203DB56 = 1;
    gUnk_0203DB54 = 30;
    gUnk_0203DB52 = 1;
    gScriptYield = 1;
}

// ScriptOp_341 @ 0x08132AA0
void ScriptOp_341(void)
{
    gScriptWaitState = 3;
    Task_Create(gUnknown_087900EC, 0xFFFF);
    gScriptYield = 1;
}

// ScriptOp_317 @ 0x08132ACC
void ScriptOp_317(void)
{
    gScriptWaitState = 5;
    Task_Create(gUnknown_087900A0, 0xFFFF);
    gScriptYield = 1;
}

// ScriptOp_ReturnFromSubst @ 0x08132AF8
void ScriptOp_ReturnFromSubst(void)
{
    gScriptPc = gScriptSubstSavedPc;
    gScriptBase = gScriptSubstSavedBase;
}

// ScriptOp_ClearFlag @ 0x08132B1C
void ScriptOp_ClearFlag(void)
{
    u16 a = gScriptBase[gScriptPc];

    gScriptPc++;
    Flag_Clear(a);
}
