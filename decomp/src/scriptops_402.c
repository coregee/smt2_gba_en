/* Script VM opcode handlers 0x402-0x409 and their alternate (skip) forms. */

#include "global.h"
#include "scriptops2.h"

/* Number entry (the casino bet keypad); the three targets are kept for the result. */
// ScriptOp_402 @ 0x08138DC8
void ScriptOp_402(void)
{
    u16 lo;
    u16 *p;

    lo = SCRIPT_READ();
    p = (u16 *)(SCRIPT_READ() << 16 | lo);
    gUnk_0203DAC8[0] = p;
    lo = SCRIPT_READ();
    p = (u16 *)(SCRIPT_READ() << 16 | lo);
    gUnk_0203DAC8[1] = p;
    lo = SCRIPT_READ();
    p = (u16 *)(SCRIPT_READ() << 16 | lo);
    gUnk_0203DAC8[2] = p;
    Keypad_OpenNumberEntry(gUnk_0203DB84);
    gScriptWaitState = 0x4D;
    gScriptYield = 1;
}

// ScriptOpAlt_402 @ 0x08138E60
void ScriptOpAlt_402(void)
{
}

// ScriptOp_403 @ 0x08138E64
void ScriptOp_403(void)
{
    sub_080BE6E0(SCRIPT_READ());
    gScriptWaitState = 0x4A;
    gScriptYield = 1;
}

// ScriptOpAlt_403 @ 0x08138EA0
void ScriptOpAlt_403(void)
{
    gScriptPc++;
}

/* Adds demon slot (operand) to the stock; jumps when the stock is full. */
// ScriptOp_404 @ 0x08138EB0
void ScriptOp_404(void)
{
    u16 slot = SCRIPT_READ();
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ();
    u32 n;
    u32 i;

    target = target << 16 | lo;
    n = Stock_GetCapacity();
    for (i = 0; i < n; i++)
    {
        if (!Combatant_IsUsed(i + 4))
        {
            Stock_AddDemon(gUnk_0203DB28[slot - 1]);
            return;
        }
    }
    gScriptJumpTarget = (u16 *)target;
}

// ScriptOpAlt_404 @ 0x08138F28
void ScriptOpAlt_404(void)
{
    gScriptPc += 3;
}

/* Removes the first stock demon whose id is in display slot (operand). */
// ScriptOp_405 @ 0x08138F38
void ScriptOp_405(void)
{
    u16 id = gUnk_0203DB28[SCRIPT_READ() - 1];
    s32 n = Stock_GetCapacity();
    u16 i;

    for (i = 4; i < n + 4; i++)
    {
        if (Combatant_IsUsed(i) && Combatant_GetDemonId(i) == id)
        {
            Party_Remove(i, 1);
            break;
        }
    }
    sub_080C366C();
}

// ScriptOpAlt_405 @ 0x08138FA8
void ScriptOpAlt_405(void)
{
    gScriptPc++;
}

// ScriptOp_406 @ 0x08138FB8
void ScriptOp_406(void)
{
    SceneEffect_Start(0, SCRIPT_READ());
    gScriptYield = 1;
}

// ScriptOpAlt_406 @ 0x08138FEC
void ScriptOpAlt_406(void)
{
    gScriptPc++;
}

// ScriptOp_407 @ 0x08138FFC
void ScriptOp_407(void)
{
    SceneEffect_End(0, SCRIPT_READ());
    gScriptYield = 1;
}

// ScriptOpAlt_407 @ 0x08139030
void ScriptOpAlt_407(void)
{
    gScriptPc++;
}

// ScriptOp_408 @ 0x08139040
void ScriptOp_408(void)
{
    SceneEffect_Start(1, SCRIPT_READ());
    gScriptWaitState = 0x4A;
    gScriptYield = 1;
}

// ScriptOpAlt_408 @ 0x0813907C
void ScriptOpAlt_408(void)
{
    gScriptPc++;
}

/* Casino prize exchange: draws the prize list and starts its menu task. */
// ScriptOp_409 @ 0x0813908C
void ScriptOp_409(void)
{
    u16 lo;
    u16 *p;

    lo = SCRIPT_READ();
    p = (u16 *)(SCRIPT_READ() << 16 | lo);
    gUnk_0203DAC8[0] = p;
    lo = SCRIPT_READ();
    p = (u16 *)(SCRIPT_READ() << 16 | lo);
    gUnk_0203DAC8[1] = p;
    lo = SCRIPT_READ();
    p = (u16 *)(SCRIPT_READ() << 16 | lo);
    gUnk_0203DAC8[2] = p;
    gScriptWaitState = 0x48;
    MsgWindow_SaveGlyphs();
    gUnk_03006940 = 0;
    gUnk_0300696C = 0;
    gUnk_03006844 = 1;
    CasinoPrize_DrawList(0);
    Task_Create(gUnknown_0878FF48, 0xFFFF);
    gScriptYield = 1;
}
