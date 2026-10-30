/* Script VM opcode handlers 0x438-0x441 and their pre-scan (ScriptOpAlt) twins. */

#include "global.h"
#include "scriptops3.h"

#define SUM_RESIST(who)                         \
    if (Combatant_IsAlive(who))                 \
    {                                           \
        n += sub_08130364(who, 0x9D);           \
        n += sub_08130364(who, 0x9E);           \
        n += sub_08130364(who, 0xA5);           \
        n += sub_08130364(who, 0xA0);           \
        n += sub_08130364(who, 0xA1);           \
        n += sub_08130364(who, 0xA2);           \
    }

// ScriptOp_438 @ 0x0813A590
void ScriptOp_438(void)
{
    u16 n = 0;
    u16 op = SCRIPT_READ();
    u16 lo;
    u32 target;

    lo = SCRIPT_READ();
    target = SCRIPT_READ();
    target = target << 16 | lo;
    if (op == 1)
    {
        if ((u16)sub_081354B0() == 1)
            gScriptJumpTarget = (u16 *)target;
    }
    else if (op == 2)
    {
        if ((u16)sub_08135370() == 1)
            gScriptJumpTarget = (u16 *)target;
    }
    else if (op == 3)
    {
        if ((u16)sub_08135420() == 1)
            gScriptJumpTarget = (u16 *)target;
    }
    else if (op == 4)
    {
        if ((u16)sub_08135540() == 1)
            gScriptJumpTarget = (u16 *)target;
    }
    else if (op == 5)
    {
        if ((u16)sub_0813560C() == 1)
            gScriptJumpTarget = (u16 *)target;
    }
    else if (op == 6)
    {
        SUM_RESIST(0)
        SUM_RESIST(1)
        SUM_RESIST(2)
        if (n != 0)
            gScriptJumpTarget = (u16 *)target;
    }
    else if (op == 7)
    {
        if (Combatant_IsAlive(0) == 1)
        {
            gUnk_03006898 = 0;
            n++;
        }
        if (Combatant_IsAlive(1) == 1)
        {
            gUnk_03006898 = 1;
            n++;
        }
        if (Combatant_IsAlive(2) == 1)
        {
            gUnk_03006898 = 2;
            n++;
        }
        if (n <= 1)
            gScriptJumpTarget = (u16 *)target;
    }
    else if (op == 8)
    {
        if (Inventory_IsMaxed(gScriptItemCheckId))
        {
            gScriptJumpTarget = (u16 *)target;
        }
        else
        {
            Inventory_AddItem(gScriptItemCheckId);
            Inventory_RemoveItem(gUnk_0203DB88[gUnk_0300696C + gUnk_03006940]);
        }
    }
    else if (op == 9)
    {
        Combatant_IsAlive(0);
        if (Combatant_IsAlive(1))
            n = 1;
        if (Combatant_IsAlive(2))
            n = 2;
        if (sub_08130364((s16)n, gUnk_030065E0))
        {
            Sound_Play(0x68);
            gScriptJumpTarget = (u16 *)target;
        }
    }
}

// ScriptOpAlt_438 @ 0x0813A838
void ScriptOpAlt_438(void)
{
    gScriptPc += 3;
}

// ScriptOp_439 @ 0x0813A848
void ScriptOp_439(void)
{
    u16 a, i;

    gScriptPc += 2;
    a = gUnknown_0879041E[0];
    i = 1;
    gUnk_03006964 = sub_080B4420(gUnknown_0879041E[i], a);
    gScriptYield = i;
    gScriptWaitState = 0x34;
}

// ScriptOpAlt_439 @ 0x0813A888
void ScriptOpAlt_439(void)
{
    gScriptPc += 2;
}

// ScriptOp_43A @ 0x0813A898
void ScriptOp_43A(void)
{
    gScriptPc++;
}

// ScriptOpAlt_43A @ 0x0813A8A8
void ScriptOpAlt_43A(void)
{
    gScriptPc++;
}

// ScriptOp_43B @ 0x0813A8B8
void ScriptOp_43B(void)
{
    gScriptPc++;
    SceneEffect_Start(1, 1);
    gScriptWaitState = 0x4A;
    gScriptYield = 1;
}

// ScriptOpAlt_43B @ 0x0813A8E8
void ScriptOpAlt_43B(void)
{
    gScriptPc++;
}

// ScriptOp_43C @ 0x0813A8F8
void ScriptOp_43C(void)
{
    gScriptPc++;
}

// ScriptOpAlt_43C @ 0x0813A908
void ScriptOpAlt_43C(void)
{
    gScriptPc++;
}

/* Jumps when demon gUnk_0203DB28[0] is not in the stock. */
// ScriptOp_43D @ 0x0813A918
void ScriptOp_43D(void)
{
    u16 lo;
    u32 target;
    u16 id;
    u32 cap, i;

    lo = SCRIPT_READ();
    target = SCRIPT_READ();
    target = target << 16 | lo;
    id = gUnk_0203DB28[0];
    cap = Stock_GetCapacity();
    for (i = 4; i < cap + 4; i++)
    {
        if (Combatant_IsUsed(i) && Combatant_GetDemonId(i) == id)
            return;
    }
    gScriptJumpTarget = (u16 *)target;
}

// ScriptOpAlt_43D @ 0x0813A988
void ScriptOpAlt_43D(void)
{
    gScriptPc += 2;
}

/* Jumps when no stock demon can be summoned (ids 0 and 0xDE, status 0xA000, and 0x8B while
   flag 0x23 is clear do not count). */
// ScriptOp_43E @ 0x0813A998
void ScriptOp_43E(void)
{
    u16 lo;
    u32 target;
    u32 cap, i;
    u16 id, status;

    lo = SCRIPT_READ();
    target = SCRIPT_READ();
    target = target << 16 | lo;
    cap = Stock_GetCapacity();
    for (i = 4; i < cap + 4; i++)
    {
        if (Combatant_IsUsed(i))
        {
            id = Combatant_GetDemonId(i);
            status = Combatant_GetStatus(i);
            if (id != 0 && id != 0xDE && !(status & 0xA000))
            {
                if (id != 0x8B || Flag_Test(0x23))
                    return;
            }
        }
    }
    gScriptJumpTarget = (u16 *)target;
}

// ScriptOpAlt_43E @ 0x0813AA28
void ScriptOpAlt_43E(void)
{
    gScriptPc += 2;
}

// ScriptOp_43F @ 0x0813AA38
void ScriptOp_43F(void)
{
    u16 lo;
    u32 target;

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
    MsgWindow_SaveGlyphs();
    gUnk_03006844 = 3;
    gUnk_03006940 = 0;
    gUnk_0300696C = 0;
    MsgWindow_DrawItemList(3);
    gScriptYield = 1;
    Task_Create(gUnknown_0878FC80, 0xFFFF);
    gScriptWaitState = 0x18;
}

// ScriptOpAlt_43F @ 0x0813AB18
void ScriptOpAlt_43F(void)
{
    gScriptPc += 8;
}

// ScriptOp_440 @ 0x0813AB28
void ScriptOp_440(void)
{
    u16 lo;
    u32 target;

    SCRIPT_READ(); lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    if (sub_080F4360(0x35) == 0)
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOpAlt_440 @ 0x0813AB70
void ScriptOpAlt_440(void)
{
    gScriptPc += 3;
}

/* Choice list built from the five entries at gUnk_03006990 (0xFF in the low byte = unused). */
// ScriptOp_441 @ 0x0813AB80
void ScriptOp_441(void)
{
    u16 lo;
    u32 target;
    s16 n;
    u16 i;

    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    gUnk_0203DAC8[14] = (u16 *)target;
    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    gUnk_0203DAC8[15] = (u16 *)target;
    gUnk_030069CC = 1;
    MsgWindow_SaveGlyphs();
    n = 0;
    for (i = 0; i < 5; i++)
    {
        if ((gUnk_03006990[i] & 0xFF) != 0xFF)
            n++;
    }
    gUnk_03006604 = n - 1;
    for (i = 0; i < 5; i++)
        gUnk_0203DB88[i] = gUnk_03006990[i];
    gUnk_03006940 = 0;
    gUnk_0300696C = 0;
    gUnk_03006844 = 1;
    MsgWindow_DrawItemList(gUnk_03006844);
    gScriptYield = 1;
    Task_Create(gUnknown_0878FC80, 0xFFFF);
    gScriptWaitState = 0xD;
}

// ScriptOpAlt_441 @ 0x0813AC88
void ScriptOpAlt_441(void)
{
    gScriptPc += 4;
}

/* Moon phase x demon field 0xC -> 0, 1 or 2 through the byte table gUnknown_08790CF0. */
// sub_0813AC98 @ 0x0813AC98
u32 sub_0813AC98(void)
{
    u32 i = (Moon_GetPhase() & 0xFF) >> 4;
    u8 v;

    i += (Demon_GetField(gUnk_0203DB7C, 0xC) & 0xF) >> 3;
    v = gUnknown_08790CF0[i];
    if (v < 0x13)
    {
        if (v >= 0xE)
            return 0;
        return 2;
    }
    return 1;
}

// ScriptOp_442 @ 0x0813ACDC
void ScriptOp_442(void)
{
    u16 k;
    u16 i = 0;
    u16 op = SCRIPT_READ();
    u16 lo, j;
    u32 target1, target2;
    s32 cap;

    lo = SCRIPT_READ();
    target1 = SCRIPT_READ();
    target1 = target1 << 16 | lo;
    lo = SCRIPT_READ();
    target2 = SCRIPT_READ();
    target2 = target2 << 16 | lo;
    if (op == 0)
    {
        /* demon gUnk_0203DB7C in the stock: t2 if dead, t1 if ailing or at half HP or less */
        cap = Stock_GetCapacity();
        for (i = 4; i < cap + 4; i++)
        {
            if (Combatant_IsUsed(i) && Combatant_GetDemonId(i) == gUnk_0203DB7C)
                break;
        }
        if (i < cap + 4)
        {
            lo = Combatant_GetStatus(i);
            if (lo & 0x8000)
                gScriptJumpTarget = (u16 *)target2;
            else if (lo != 0)
                gScriptJumpTarget = (u16 *)target1;
            else if ((lo = gGameState[i].maxHp / 2) >= gGameState[i].hp)
                gScriptJumpTarget = (u16 *)target1;
        }
    }
    else if (op == 1)
    {
        lo = Demon_GetField(gUnk_0203DB7C, 0xB) & 0xFF;
        if (lo < 0x70)
            gScriptJumpTarget = (u16 *)target1;
        else if (lo >= 0x90)
            gScriptJumpTarget = (u16 *)target2;
    }
    else if (op == 2)
    {
        lo = sub_0813AC98();
        if (lo == 0)
            ;
        else if (lo == 1)
            gScriptJumpTarget = (u16 *)target1;
        else if (lo == 2)
            gScriptJumpTarget = (u16 *)target2;
    }
    else if (op == 3)
    {
        lo = sub_080C0794(0) & 0xFF00;
        if (lo < 0x7000)
            gScriptJumpTarget = (u16 *)target1;
        else if (lo >= 0x9000)
            gScriptJumpTarget = (u16 *)target2;
    }
    else if ((u16)(op - 4) <= 1)
    {
        gUnk_0203DAC8[0] = (u16 *)target1;
        gUnk_0203DAC8[1] = (u16 *)target2;
        gUnk_030068D8 = 0xFF;
        if (op == 4)
        {
            sub_0813BECC(0);
            gUnk_030068A4 = sub_080D3400(3, 0, gUnknown_0878FDB4[0]);
            sub_080D347C(gUnknown_0878FDB4[0], 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF);
        }
        else
        {
            sub_0813BECC(0x10);
            sub_08130C6C();
            gUnk_030068A4 = sub_080D3400(4, 0, 0);
            sub_080D347C(gUnk_03006980[0], gUnk_03006980[1], gUnk_03006980[2], gUnk_03006980[3], gUnk_03006980[4]);
        }
        gScriptYield = 1;
    }
    else if (op == 6)
    {
        gUnk_0203DAC8[0] = (u16 *)target1;
        gUnk_0203DAC8[1] = (u16 *)target2;
        gUnk_030068D8 = gScriptItemCheckId;
        sub_0813BECC(0xF0);
        sub_08130C6C();
        gUnk_030068A4 = sub_080D3400(4, 0, 0);
        sub_080D347C(gUnk_03006980[0], gUnk_03006980[1], gUnk_03006980[2], gUnk_03006980[3], gUnk_03006980[4]);
        gScriptYield = 1;
    }
    else if (op == 7)
    {
        /* adds demon gUnk_0203DB28[0] to a free stock slot, using up both items */
        if ((u16)sub_0813E804(gUnk_0203DB28[0]) != 0)
        {
            gScriptJumpTarget = (u16 *)target2;
        }
        else
        {
            cap = Stock_GetCapacity();
            for (k = 0; k < cap; k++)
            {
                if (!Combatant_IsUsed(k + 4))
                {
                    Inventory_RemoveItem(gScriptItemCheckId);
                    Inventory_RemoveItem(gUnk_030068D8);
                    Stock_AddDemon(gUnk_0203DB28[0]);
                    return;
                }
            }
            gScriptJumpTarget = (u16 *)target1;
        }
    }
    else if (op == 8)
    {
        /* queues the names of party[0] and party[1] (party[2] when 1 is absent) */
        gUnk_0203DAC8[0] = (u16 *)target1;
        gUnk_0203DAC8[1] = (u16 *)target2;
        for (j = 0; j < 16; j++)
            gScriptSubstBuf[j] = 0;
        Combatant_DecodeName(&gGameState[0], gScriptSubstBuf);
        for (j = 14; j != 0; j--)
        {
            if (gScriptSubstBuf[j] != 0
             && (gScriptSubstBuf[j + 1] == 0 || gScriptSubstBuf[j + 1] == 0x318))
            {
                gScriptSubstBuf[j + 1] = 0x318;
                break;
            }
        }
        MsgGlyphQueue_PushSubstClamped(0x27, gUnknown_0879038A[0], 0, j + 1);
        for (j = 0; j < 16; j++)
            gScriptSubstBuf[j] = 0;
        if (Combatant_IsUsed(1))
            Combatant_DecodeName(&gGameState[1], gScriptSubstBuf);
        else
            Combatant_DecodeName(&gGameState[2], gScriptSubstBuf);
        for (j = 14; j != 0; j--)
        {
            if (gScriptSubstBuf[j] != 0
             && (gScriptSubstBuf[j + 1] == 0 || gScriptSubstBuf[j + 1] == 0x318))
            {
                gScriptSubstBuf[j + 1] = 0x318;
                break;
            }
        }
        MsgGlyphQueue_PushSubstClamped(0x27, gUnknown_0879038A[1], 0, j + 1);
        gScriptWaitState = 0x48;
        gUnk_03006688 = 2;
        Task_Create(gUnknown_0878FD14, 0xFFFF);
        gScriptYield = 1;
    }
    else if (op == 9)
    {
        sub_08132350(0x3A);
        lo = 0x200;
        i = Combatant_GetStatus(0);
        if (i & lo)
            gScriptJumpTarget = (u16 *)target1;
        else if (i & gUnknown_08790D80[6])
            gScriptJumpTarget = (u16 *)target2;
        else
            Combatant_SetStatus(0, (i & gUnknown_08790DA0[6]) | lo);
    }
}

// ScriptOpAlt_442 @ 0x0813B128
void ScriptOpAlt_442(void)
{
    gScriptPc += 5;
}

/* Demon gUnk_0203DB7C event: kind 0x22 -> t1 with 0203DB2C = level * 2; otherwise 1 in 8
   drains `level` from the hero's u32 at +8 (EXP?) and goes to t2, else t3. */
// ScriptOp_443 @ 0x0813B138
void ScriptOp_443(void)
{
    u16 lo;
    u32 t1, t2, t3;
    u16 r;

    SCRIPT_READ();
    lo = SCRIPT_READ();
    t1 = SCRIPT_READ() << 16 | lo;
    lo = SCRIPT_READ();
    t2 = SCRIPT_READ();
    t2 = t2 << 16 | lo;
    lo = SCRIPT_READ();
    t3 = SCRIPT_READ();
    t3 = t3 << 16 | lo;
    r = Demon_GetRace(gUnk_0203DB7C);
    if (r == 0x22)
    {
        gUnk_0203DB2C = (Demon_GetField(gUnk_0203DB7C, 0) & 0xFF) * 2;
        gScriptJumpTarget = (u16 *)t1;
    }
    else if ((r = Random_Byte() & 7) == 0)
    {
        gUnk_0203DB2C = Demon_GetField(gUnk_0203DB7C, 0) & 0xFF;
        if (*(u32 *)(Battle_GetCombatant(0x8000) + 8) <= gUnk_0203DB2C)
            *(u32 *)(Battle_GetCombatant(0x8000) + 8) = r;
        else
            *(u32 *)(Battle_GetCombatant(0x8000) + 8) -= gUnk_0203DB2C;
        gScriptJumpTarget = (u16 *)t2;
    }
    else
    {
        gScriptJumpTarget = (u16 *)t3;
    }
}

// ScriptOpAlt_443 @ 0x0813B254
void ScriptOpAlt_443(void)
{
    gScriptPc += 7;
}

// sub_0813B264 @ 0x0813B264
void sub_0813B264(void)
{
}

/* Adds one to counter gScriptItemCheckId - 0x120 (max 99). */
// sub_0813B268 @ 0x0813B268
bool32 sub_0813B268(void)
{
    if (sub_0813756C(gScriptItemCheckId - 0x120) < 99)
    {
        sub_08137518(gScriptItemCheckId - 0x120, 1);
        if (sub_0813756C(gScriptItemCheckId - 0x120) == 9)
            sub_0813B264();
        return TRUE;
    }
    return FALSE;
}

// ScriptOp_444 @ 0x0813B2C0
void ScriptOp_444(void)
{
    u16 lo;
    u32 target;

    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    gScriptItemCheckId = 0x127;
    if (sub_0813B268())
    {
        gScriptJumpTarget = (u16 *)gUnknown_080A0BC6;
        gUnk_03006840 = target;
    }
}

// ScriptOpAlt_444 @ 0x0813B324
void ScriptOpAlt_444(void)
{
}

/* Runs status message `msg` from the script pointer table gUnknown_08032BBC. */
// Script_JumpToStatusMessage @ 0x0813B328
void Script_JumpToStatusMessage(u32 msg)
{
    u16 *p;
    u16 lo;
    u32 hi;

    gScriptBase = (u16 *)gUnknown_08032BBC;
    p = &gScriptBase[(u16)(msg * 2)];
    lo = p[0];
    hi = p[1];
    hi <<= 16;
    hi |= lo;
    gScriptJumpTarget = (u16 *)hi;
}

/* Inflicts the status bits `bits` on `who`, bit by bit from bit 0, and shows a message
   for each. */
// Combatant_InflictStatus @ 0x0813B350
#ifdef NONMATCHING
void Combatant_InflictStatus(u16 bits, u16 who)
{
    u16 b = bits;
    s32 i;
    u16 status, msg;

    for (i = 15; i >= 0; i--)
    {
        if (b & 1)
        {
            b >>= 1;
            status = Combatant_GetStatus(who);
            if (bits & status)
            {
                msg = 0;
            }
            else if (status & gUnknown_08790D80[i])
            {
                msg = 1;
            }
            else
            {
                Combatant_SetStatus(who, (status & gUnknown_08790DA0[i]) | bits);
                if (i == 0)
                {
                    *(u16 *)(Battle_GetCombatant(who + 0x8000) + 0x18) = i;
                    continue;
                }
                if (i > 14)
                    continue;
                msg = (who > 15 ? gUnknown_08790DC0 : gUnknown_08790DDE)[i];
            }
            if (i != 1)
                Script_JumpToStatusMessage(msg);
        }
        else
        {
            b >>= 1;
        }
    }
}
#else
NAKED
void Combatant_InflictStatus(u16 bits, u16 who)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r7, r1, #0x10\n"
        "    mov r5, r8\n"
        "    movs r6, #0xf\n"
        ".L0813B364:\n"
        "    movs r0, #1\n"
        "    ands r0, r5\n"
        "    cmp r0, #0\n"
        "    beq .L0813B3EC\n"
        "    lsrs r5, r5, #1\n"
        "    adds r0, r7, #0\n"
        "    bl Combatant_GetStatus\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    adds r0, r1, #0\n"
        "    mov r2, r8\n"
        "    ands r0, r2\n"
        "    cmp r0, #0\n"
        "    beq .L0813B386\n"
        "    movs r0, #0\n"
        "    b .L0813B3DE\n"
        ".L0813B386:\n"
        "    ldr r0, .L0813B398\n"
        "    lsls r4, r6, #1\n"
        "    adds r0, r4, r0\n"
        "    ldrh r0, [r0]\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L0813B39C\n"
        "    movs r0, #1\n"
        "    b .L0813B3DE\n"
        ".L0813B398: .4byte gUnknown_08790D80\n"
        ".L0813B39C:\n"
        "    ldr r0, .L0813B3C4\n"
        "    adds r0, r4, r0\n"
        "    ldrh r0, [r0]\n"
        "    ands r1, r0\n"
        "    mov r0, r8\n"
        "    orrs r1, r0\n"
        "    adds r0, r7, #0\n"
        "    bl Combatant_SetStatus\n"
        "    cmp r6, #0\n"
        "    bne .L0813B3C8\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    adds r0, r7, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    strh r6, [r0, #0x18]\n"
        "    b .L0813B3EE\n"
        ".L0813B3C4: .4byte gUnknown_08790DA0\n"
        ".L0813B3C8:\n"
        "    cmp r6, #0xe\n"
        "    bgt .L0813B3EE\n"
        "    cmp r7, #0xf\n"
        "    bls .L0813B3D8\n"
        "    ldr r0, .L0813B3D4\n"
        "    b .L0813B3DA\n"
        ".L0813B3D4: .4byte gUnknown_08790DC0\n"
        ".L0813B3D8:\n"
        "    ldr r0, .L0813B3E8\n"
        ".L0813B3DA:\n"
        "    adds r0, r4, r0\n"
        "    ldrh r0, [r0]\n"
        ".L0813B3DE:\n"
        "    cmp r6, #1\n"
        "    beq .L0813B3EE\n"
        "    bl Script_JumpToStatusMessage\n"
        "    b .L0813B3EE\n"
        ".L0813B3E8: .4byte gUnknown_08790DDE\n"
        ".L0813B3EC:\n"
        "    lsrs r5, r5, #1\n"
        ".L0813B3EE:\n"
        "    subs r6, #1\n"
        "    cmp r6, #0\n"
        "    bge .L0813B364\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

/* Takes one from counter gScriptItemCheckId - 0x120. */
// sub_0813B400 @ 0x0813B400
void sub_0813B400(void)
{
    u16 id = gScriptItemCheckId - 0x120;

    if (sub_0813756C(id))
    {
        sub_08137518(id, -1);
        sub_0813B264();
    }
}

/* Halves the stat named by gUnk_030065E0 (0x9D-0xA5) into who's +0x38 table. */
// sub_0813B438 @ 0x0813B438
void sub_0813B438(u16 who)
{
    s8 *p = (s8 *)Battle_GetCombatant(who + 0x8000) + 0x28;

    switch (gUnk_030065E0)
    {
    case 0x9D:
    case 0xA3:
        sub_08136270(who, 0, p[0] / 2);
        break;
    case 0x9E:
    case 0xA4:
        sub_08136270(who, 1, p[1] / 2);
        break;
    case 0x9F:
    case 0xA5:
        sub_08136270(who, 2, p[2] / 2);
        break;
    case 0xA0:
        sub_08136270(who, 3, p[3] / 2);
        break;
    case 0xA1:
        sub_08136270(who, 4, p[4] / 2);
        break;
    case 0xA2:
        sub_08136270(who, 5, p[5] / 2);
        break;
    }
    Combatant_RecalcStats(who);
    Hud_InvalidateGauges();
}
