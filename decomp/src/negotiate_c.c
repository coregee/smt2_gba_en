/* Script VM opcode handlers 0x44C, 0x412 and the demon negotiation response selector. */

#include "global.h"
#include "scriptops2.h"

// ScriptOp_44C @ 0x081385D0
void ScriptOp_44C(void)
{
    Negotiate_CallReply(SCRIPT_READ());
}

// ScriptOp_412 @ 0x081385F8
void ScriptOp_412(void)
{
    sub_0813848C(SCRIPT_READ());
    gMsgGlyphCount = 0;
    gTextColumn = 0;
    gTextLine = 0;
    Font_ResetGlyphSpriteCache(0x180);
}

/* TRUE when any item 0x12C-0x159 is owned. */
// sub_08138640 @ 0x08138640
u16 sub_08138640(void)
{
    u16 i;

    for (i = 0x12C; i <= 0x159; i++)
    {
        if (Inventory_GetCount(i))
            return 1;
    }
    return 0;
}

// sub_08138670 @ 0x08138670
u16 sub_08138670(void)
{
    if (Inventory_GetCount(0x11F))
        return 1;
    return 0;
}

/* TRUE when a living stock demon has id 0x16A-0x17B. */
// sub_08138690 @ 0x08138690
u16 sub_08138690(void)
{
    s32 n = Stock_GetCapacity();
    s32 i;

    for (i = 4; i < n + 4; i++)
    {
        if (Combatant_IsAlive(i))
        {
            s16 id = Combatant_GetDemonId(i);

            if (id >= 0x16A && id <= 0x17B)
                return 1;
        }
    }
    return 0;
}

/* Operand: low byte = mode, high byte = count - 1 of the jump targets that follow.
   Picks one target from the demon's reaction checks for the given mode. */
// Negotiate_SelectResponse @ 0x081386DC
void Negotiate_SelectResponse(void)
{
    u32 t[32];
    u16 v = SCRIPT_READ();
    u32 n = (v >> 8) + 1;
    u32 mode = v & 0xFF;
    u16 i;

    for (i = 0; i < n; i++)
    {
        u16 lo = SCRIPT_READ();
        u32 x = SCRIPT_READ() << 16 | lo;

        t[i] = x;
    }
    if (mode == 1)
    {
        if (!sub_081376AC(0x40))
            goto first;
        if (sub_081376AC(0x40))
            gScriptJumpTarget = (u16 *)t[2];
        else
            gScriptJumpTarget = (u16 *)t[1];
    }
    else if (mode == 2)
    {
        if (sub_08137720(1))
            goto first;
        if (!Flag_Test(9))
            goto check_mood;
    mood_ok:
        if (sub_0813C4FC(1))
        {
            if (sub_081376AC(0x80))
                gScriptJumpTarget = (u16 *)t[1];
            else
                gScriptJumpTarget = (u16 *)t[2];
        }
        else
            gScriptJumpTarget = (u16 *)t[4];
        return;
    check_mood:
        if (sub_081379CC(1))
            goto mood_ok;
        gScriptJumpTarget = (u16 *)t[3];
    }
    else if (mode == 3)
    {
        if (sub_08137720(1))
            goto first;
        if (sub_0813C4FC(1))
            gScriptJumpTarget = (u16 *)t[1];
        else if (sub_081376AC(0x40))
            gScriptJumpTarget = (u16 *)t[2];
        else if (sub_081376AC(0x80))
            gScriptJumpTarget = (u16 *)t[3];
        else
            gScriptJumpTarget = (u16 *)t[4];
    }
    else if (mode == 4)
    {
        if (sub_08137720(1))
            goto first;
        if (sub_08137720(2))
            gScriptJumpTarget = (u16 *)t[1];
        else
        {
            sub_0813821C(2);
            if (sub_081376AC(0x80))
                gScriptJumpTarget = (u16 *)t[2];
            else if (sub_081376AC(0x40))
                gScriptJumpTarget = (u16 *)t[3];
            else
                gScriptJumpTarget = (u16 *)t[4];
        }
    }
    else if (mode == 5)
    {
        if (sub_08137720(1))
            goto first;
        if (sub_08137720(2))
            gScriptJumpTarget = (u16 *)t[1];
        else
        {
            sub_0813821C(2);
            if (sub_081376AC(0x80))
                gScriptJumpTarget = (u16 *)t[2];
            else if (sub_081376AC(0x80))
                gScriptJumpTarget = (u16 *)t[3];
            else
                gScriptJumpTarget = (u16 *)t[4];
        }
    }
    else if (mode == 6)
    {
        if (sub_08137720(1))
            goto first;
        if (sub_0813C4FC(2))
            gScriptJumpTarget = (u16 *)t[1];
        else if (sub_0813C4FC(3))
            gScriptJumpTarget = (u16 *)t[2];
        else
        {
            i = sub_0813AC98();
            if (i == 1)
                gScriptJumpTarget = (u16 *)t[3];
            else if (i == 2)
                gScriptJumpTarget = (u16 *)t[4];
            else
                gScriptJumpTarget = (u16 *)t[5];
        }
    }
    else if (mode == 7)
    {
        if (sub_08137720(1))
            goto first;
        if (sub_08137720(2))
        {
            if (sub_081376AC(0x80))
                gScriptJumpTarget = (u16 *)t[3];
            else
                gScriptJumpTarget = (u16 *)t[4];
        }
        else
        {
            sub_0813821C(2);
            if (sub_081376AC(0x40))
                gScriptJumpTarget = (u16 *)t[1];
            else
                gScriptJumpTarget = (u16 *)t[2];
        }
    }
    else if (mode == 8)
    {
        if (sub_08137720(1))
        {
            i = sub_08138338();
            if (i == 0)
                goto first;
            if (i == 1)
            {
                gScriptJumpTarget = (u16 *)t[1];
                return;
            }
            if (i == 2)
            {
                gScriptJumpTarget = (u16 *)t[2];
                return;
            }
            if (i == 3)
            {
                if (sub_0813BF78())
                    gScriptJumpTarget = (u16 *)t[3];
                else if (sub_0813BF58())
                    gScriptJumpTarget = (u16 *)t[5];
                else
                    gScriptJumpTarget = (u16 *)t[4];
                return;
            }
        }
        if (sub_0813C4FC(2))
            gScriptJumpTarget = (u16 *)t[6];
        else
        {
            i = sub_0813AC98();
            if (i == 1)
                gScriptJumpTarget = (u16 *)t[7];
            else if (i == 2)
                gScriptJumpTarget = (u16 *)t[8];
            else
                gScriptJumpTarget = (u16 *)t[9];
        }
    }
    else if (mode == 10)
        gScriptJumpTarget = (u16 *)t[gUnk_0203DB72];
    else if (mode == 11)
    {
        if (Combatant_GetLevel(0) <= 20)
        {
            if (!sub_08138640())
                goto first;
            gScriptJumpTarget = (u16 *)t[1];
        }
        else if (sub_08138640())
        {
            if (sub_08138670())
            {
                if (sub_08138690())
                    gScriptJumpTarget = (u16 *)t[5];
                else
                    gScriptJumpTarget = (u16 *)t[6];
            }
            else if (sub_08138690())
                gScriptJumpTarget = (u16 *)t[7];
            else
                gScriptJumpTarget = (u16 *)t[1];
        }
        else if (sub_08138670())
        {
            if (sub_08138690())
                gScriptJumpTarget = (u16 *)t[4];
            else
                gScriptJumpTarget = (u16 *)t[2];
        }
        else
        {
            if (!sub_08138690())
                goto first;
            gScriptJumpTarget = (u16 *)t[3];
        }
    }
    return;
first:
    gScriptJumpTarget = (u16 *)t[0];
}
