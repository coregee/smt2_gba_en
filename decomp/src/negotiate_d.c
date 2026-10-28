/* Script VM opcode handlers 0x3E3-0x401: negotiation end and battle hand-off. */

#include "global.h"
#include "scriptops2.h"

// ScriptOp_3E3 @ 0x08138B9C
void ScriptOp_3E3(void)
{
    u16 mode = SCRIPT_READ();
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ();
    u16 f;
    u16 v;

    target = target << 16 | lo;
    f = Demon_GetField(gUnk_0203DB7C, 9);
    if (mode == 1)
    {
        v = Random_Byte() & 3;
        v += f;
    }
    else if (mode == 2)
    {
        v = Random_Byte() & 7;
        v += f;
    }
    else
    {
        v = Random_Byte() & 7;
        v += f;
        v += 3;
    }
    if (v)
        v--;
    if (v >= (s32)Combatant_GetStat(0, 4))
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_3E4 @ 0x08138C48
void ScriptOp_3E4(void)
{
}

// ScriptOp_3E5 @ 0x08138C4C
void ScriptOp_3E5(void)
{
}

/* Ends the negotiation with result k and stops the script. */
// Negotiate_End @ 0x08138C50
void Negotiate_End(u16 k)
{
    gUnk_03006670 = 0;
    gUnk_0203DB70 = k;
    sub_080EFA88(k);
    switch (k)
    {
    case 1:
        sub_080EFA20(-2);
        break;
    case 2:
        sub_080EFA44(-2);
        break;
    }
    gMsgGlyphCount = 0;
    gTextColumn = 0;
    gTextLine = 0;
    gScriptPc = 0;
    gUnk_0203DB46 = 1;
    sub_0813EB6C(0);
    gScriptWaitState = 0;
    Font_ResetGlyphSpriteCache(0x180);
    Task_End(gUnk_030069E4);
    gScriptYield = 1;
}

// sub_08138CE8 @ 0x08138CE8
u32 sub_08138CE8(void)
{
    if ((u8)Battle_IsPartyDefeated() == 1)
    {
        Negotiate_End(7);
        return 2;
    }
    if (!sub_080ED9F4())
    {
        Negotiate_End(0xC);
        return 1;
    }
    return 0;
}

// ScriptOp_3E6 @ 0x08138D18
void ScriptOp_3E6(struct Task *task)
{
    Negotiate_End(SCRIPT_READ());
    gUnk_0203DB86 = 0;
    task->result = 1;
}

// ScriptOp_401 @ 0x08138D50
void ScriptOp_401(void)
{
    u16 v = SCRIPT_READ();

    v |= 0x100;
    gUnk_0203DB28[0] = v;
    gUnk_03006970[0] = 1;
    gUnk_0203DB66 = 1;
    if (v == 0x110)
    {
        gUnk_0203DB28[1] = 0x10F;
        gUnk_03006970[1] = 1;
        gUnk_0203DB68 = 1;
    }
    else
        gUnk_0203DB68 = 0;
}

// sub_08138DB8 @ 0x08138DB8
void sub_08138DB8(void)
{
    gScriptPc++;
}
