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
#ifdef NONMATCHING
void ScriptOp_439(void)
{
    u16 i = 1;

    gScriptPc += 2;
    gUnk_03006964 = sub_080B4420(gUnknown_0879041E[i], gUnknown_0879041E[0]);
    gScriptYield = i;
    gScriptWaitState = 0x34;
}
#else
NAKED
void ScriptOp_439(void)
{
    asm_unified(
        "    push {r4, lr}\n"
        "    ldr r1, .L0813A874\n"
        "    ldrh r0, [r1]\n"
        "    adds r0, #2\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L0813A878\n"
        "    ldrh r1, [r0]\n"
        "    movs r4, #1\n"
        "    ldrh r0, [r0, #2]\n"
        "    bl sub_080B4420\n"
        "    ldr r1, .L0813A87C\n"
        "    str r0, [r1]\n"
        "    ldr r0, .L0813A880\n"
        "    strh r4, [r0]\n"
        "    ldr r1, .L0813A884\n"
        "    movs r0, #0x34\n"
        "    strh r0, [r1]\n"
        "    pop {r4}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L0813A874: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L0813A878: .4byte gUnknown_0879041E\n"
        ".L0813A87C: .4byte 0x03006964 @ IWRAM+0x6964\n"
        ".L0813A880: .4byte 0x0203DB6E @ EWRAM+0x3DB6E\n"
        ".L0813A884: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
    );
}
#endif

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
    sub_0812F2B4(3);
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
#ifdef NONMATCHING
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
    sub_0812F2B4(1);
    gScriptYield = 1;
    Task_Create(gUnknown_0878FC80, 0xFFFF);
    gScriptWaitState = 0xD;
}
#else
NAKED
void ScriptOp_441(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    ldr r3, .L0813AC50\n"
        "    ldrh r0, [r3]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r3]\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r2, .L0813AC54\n"
        "    ldr r4, [r2]\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r4\n"
        "    ldrh r5, [r0]\n"
        "    adds r2, r1, #1\n"
        "    strh r2, [r3]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0xf\n"
        "    adds r1, r1, r4\n"
        "    ldrh r0, [r1]\n"
        "    lsls r0, r0, #0x10\n"
        "    orrs r0, r5\n"
        "    ldr r5, .L0813AC58\n"
        "    str r0, [r5, #0x38]\n"
        "    adds r0, r2, #1\n"
        "    strh r0, [r3]\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0xf\n"
        "    adds r2, r2, r4\n"
        "    ldrh r2, [r2]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r3]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #0x10\n"
        "    orrs r0, r2\n"
        "    str r0, [r5, #0x3c]\n"
        "    ldr r1, .L0813AC5C\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    bl MsgWindow_SaveGlyphs\n"
        "    movs r3, #0\n"
        "    movs r2, #0\n"
        "    ldr r4, .L0813AC60\n"
        "    movs r5, #0xff\n"
        ".L0813ABDA:\n"
        "    lsls r0, r2, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r1, [r0]\n"
        "    adds r0, r5, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0xff\n"
        "    beq .L0813ABF2\n"
        "    lsls r0, r3, #0x10\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #9\n"
        "    adds r0, r0, r1\n"
        "    lsrs r3, r0, #0x10\n"
        ".L0813ABF2:\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #4\n"
        "    bls .L0813ABDA\n"
        "    ldr r1, .L0813AC64\n"
        "    lsls r0, r3, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    subs r0, #1\n"
        "    strh r0, [r1]\n"
        "    movs r2, #0\n"
        "    ldr r5, .L0813AC68\n"
        "    ldr r6, .L0813AC6C\n"
        "    ldr r7, .L0813AC70\n"
        "    ldr r4, .L0813AC74\n"
        "    ldr r3, .L0813AC60\n"
        ".L0813AC12:\n"
        "    lsls r0, r2, #1\n"
        "    adds r1, r0, r4\n"
        "    adds r0, r0, r3\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r1]\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #4\n"
        "    bls .L0813AC12\n"
        "    movs r0, #0\n"
        "    strh r0, [r5]\n"
        "    strh r0, [r6]\n"
        "    movs r0, #1\n"
        "    strh r0, [r7]\n"
        "    movs r4, #1\n"
        "    movs r0, #1\n"
        "    bl sub_0812F2B4\n"
        "    ldr r0, .L0813AC78\n"
        "    strh r4, [r0]\n"
        "    ldr r0, .L0813AC7C\n"
        "    ldr r1, .L0813AC80\n"
        "    bl Task_Create\n"
        "    ldr r1, .L0813AC84\n"
        "    movs r0, #0xd\n"
        "    strh r0, [r1]\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L0813AC50: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L0813AC54: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L0813AC58: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8\n"
        ".L0813AC5C: .4byte 0x030069CC @ IWRAM+0x69CC\n"
        ".L0813AC60: .4byte 0x03006990 @ IWRAM+0x6990\n"
        ".L0813AC64: .4byte 0x03006604 @ IWRAM+0x6604\n"
        ".L0813AC68: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0813AC6C: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L0813AC70: .4byte 0x03006844 @ IWRAM+0x6844\n"
        ".L0813AC74: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L0813AC78: .4byte 0x0203DB6E @ EWRAM+0x3DB6E\n"
        ".L0813AC7C: .4byte gUnknown_0878FC80\n"
        ".L0813AC80: .4byte 0x0000FFFF\n"
        ".L0813AC84: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
    );
}
#endif

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
#ifdef NONMATCHING
void ScriptOp_442(void)
{
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
            for (i = 0; i < cap; i++)
            {
                if (!Combatant_IsUsed(i + 4))
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
#else
NAKED
void ScriptOp_442(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    sub sp, #4\n"
        "    movs r6, #0\n"
        "    ldr r3, .L0813AD4C\n"
        "    ldrh r0, [r3]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r3]\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r2, .L0813AD50\n"
        "    ldr r2, [r2]\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r2\n"
        "    ldrh r5, [r0]\n"
        "    mov ip, r5\n"
        "    adds r0, r1, #1\n"
        "    strh r0, [r3]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0xf\n"
        "    adds r1, r1, r2\n"
        "    ldrh r4, [r1]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r3]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r2\n"
        "    ldrh r0, [r0]\n"
        "    mov r8, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    orrs r0, r4\n"
        "    mov r8, r0\n"
        "    adds r0, r1, #1\n"
        "    strh r0, [r3]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0xf\n"
        "    adds r1, r1, r2\n"
        "    ldrh r4, [r1]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r3]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r2\n"
        "    ldrh r7, [r0]\n"
        "    lsls r7, r7, #0x10\n"
        "    orrs r7, r4\n"
        "    cmp r5, #0\n"
        "    bne .L0813ADC4\n"
        "    bl Stock_GetCapacity\n"
        "    adds r5, r0, #0\n"
        "    movs r6, #4\n"
        "    adds r5, #4\n"
        "    adds r4, r5, #0\n"
        "    b .L0813AD5A\n"
        "    .byte 0x00, 0x00\n"
        ".L0813AD4C: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L0813AD50: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L0813AD54:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        ".L0813AD5A:\n"
        "    cmp r6, r4\n"
        "    blt .L0813AD60\n"
        "    b .L0813B118\n"
        ".L0813AD60:\n"
        "    adds r0, r6, #0\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L0813AD54\n"
        "    adds r0, r6, #0\n"
        "    bl Combatant_GetDemonId\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    ldr r1, .L0813ADBC\n"
        "    ldrh r1, [r1]\n"
        "    cmp r0, r1\n"
        "    bne .L0813AD54\n"
        "    cmp r6, r5\n"
        "    blt .L0813AD82\n"
        "    b .L0813B118\n"
        ".L0813AD82:\n"
        "    adds r0, r6, #0\n"
        "    bl Combatant_GetStatus\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #8\n"
        "    ands r0, r4\n"
        "    cmp r0, #0\n"
        "    beq .L0813AD98\n"
        "    b .L0813B0D2\n"
        ".L0813AD98:\n"
        "    cmp r4, #0\n"
        "    beq .L0813AD9E\n"
        "    b .L0813B0BA\n"
        ".L0813AD9E:\n"
        "    ldr r0, .L0813ADC0\n"
        "    lsls r2, r6, #7\n"
        "    adds r2, r2, r0\n"
        "    movs r1, #0x1a\n"
        "    ldrsh r0, [r2, r1]\n"
        "    lsrs r1, r0, #0x1f\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #0xf\n"
        "    lsrs r4, r0, #0x10\n"
        "    movs r1, #0x18\n"
        "    ldrsh r0, [r2, r1]\n"
        "    cmp r4, r0\n"
        "    bge .L0813ADBA\n"
        "    b .L0813B118\n"
        ".L0813ADBA:\n"
        "    b .L0813B0BA\n"
        ".L0813ADBC: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813ADC0: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L0813ADC4:\n"
        "    cmp r5, #1\n"
        "    bne .L0813ADE8\n"
        "    ldr r0, .L0813ADE4\n"
        "    ldrh r0, [r0]\n"
        "    movs r1, #0xb\n"
        "    bl Demon_GetField\n"
        "    movs r4, #0xff\n"
        "    ands r4, r0\n"
        "    cmp r4, #0x6f\n"
        "    bhi .L0813ADDC\n"
        "    b .L0813B0BA\n"
        ".L0813ADDC:\n"
        "    cmp r4, #0x8f\n"
        "    bhi .L0813ADE2\n"
        "    b .L0813B118\n"
        ".L0813ADE2:\n"
        "    b .L0813B0D2\n"
        ".L0813ADE4: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813ADE8:\n"
        "    cmp r5, #2\n"
        "    bne .L0813AE08\n"
        "    bl sub_0813AC98\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #0\n"
        "    bne .L0813ADFA\n"
        "    b .L0813B118\n"
        ".L0813ADFA:\n"
        "    cmp r4, #1\n"
        "    bne .L0813AE00\n"
        "    b .L0813B0BA\n"
        ".L0813AE00:\n"
        "    cmp r4, #2\n"
        "    beq .L0813AE06\n"
        "    b .L0813B118\n"
        ".L0813AE06:\n"
        "    b .L0813B0D2\n"
        ".L0813AE08:\n"
        "    cmp r5, #3\n"
        "    bne .L0813AE38\n"
        "    movs r0, #0\n"
        "    bl sub_080C0794\n"
        "    adds r4, r0, #0\n"
        "    movs r1, #0xff\n"
        "    lsls r1, r1, #8\n"
        "    adds r0, r1, #0\n"
        "    ands r4, r0\n"
        "    ldr r0, .L0813AE30\n"
        "    cmp r4, r0\n"
        "    bhi .L0813AE24\n"
        "    b .L0813B0BA\n"
        ".L0813AE24:\n"
        "    ldr r0, .L0813AE34\n"
        "    cmp r4, r0\n"
        "    bhi .L0813AE2C\n"
        "    b .L0813B118\n"
        ".L0813AE2C:\n"
        "    b .L0813B0D2\n"
        "    .byte 0x00, 0x00\n"
        ".L0813AE30: .4byte 0x00006FFF\n"
        ".L0813AE34: .4byte 0x00008FFF\n"
        ".L0813AE38:\n"
        "    subs r0, r5, #4\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bhi .L0813AEC4\n"
        "    ldr r0, .L0813AE7C\n"
        "    mov r1, r8\n"
        "    str r1, [r0]\n"
        "    str r7, [r0, #4]\n"
        "    ldr r1, .L0813AE80\n"
        "    movs r0, #0xff\n"
        "    strh r0, [r1]\n"
        "    cmp r5, #4\n"
        "    bne .L0813AE90\n"
        "    movs r0, #0\n"
        "    bl sub_0813BECC\n"
        "    ldr r0, .L0813AE84\n"
        "    ldrh r4, [r0]\n"
        "    movs r0, #3\n"
        "    movs r1, #0\n"
        "    adds r2, r4, #0\n"
        "    bl sub_080D3400\n"
        "    ldr r1, .L0813AE88\n"
        "    str r0, [r1]\n"
        "    ldr r3, .L0813AE8C\n"
        "    str r3, [sp]\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r3, #0\n"
        "    adds r2, r3, #0\n"
        "    bl sub_080D347C\n"
        "    b .L0813B07A\n"
        ".L0813AE7C: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8\n"
        ".L0813AE80: .4byte 0x030068D8 @ IWRAM+0x68D8\n"
        ".L0813AE84: .4byte gUnknown_0878FDB4\n"
        ".L0813AE88: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L0813AE8C: .4byte 0x0000FFFF\n"
        ".L0813AE90:\n"
        "    movs r0, #0x10\n"
        "    bl sub_0813BECC\n"
        "    bl sub_08130C6C\n"
        "    movs r0, #4\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    bl sub_080D3400\n"
        "    ldr r1, .L0813AEBC\n"
        "    str r0, [r1]\n"
        "    ldr r4, .L0813AEC0\n"
        "    ldrh r0, [r4]\n"
        "    ldrh r1, [r4, #2]\n"
        "    ldrh r2, [r4, #4]\n"
        "    ldrh r3, [r4, #6]\n"
        "    ldrh r4, [r4, #8]\n"
        "    str r4, [sp]\n"
        "    bl sub_080D347C\n"
        "    b .L0813B07A\n"
        ".L0813AEBC: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L0813AEC0: .4byte 0x03006980 @ IWRAM+0x6980\n"
        ".L0813AEC4:\n"
        "    cmp r5, #6\n"
        "    bne .L0813AF18\n"
        "    ldr r0, .L0813AF04\n"
        "    mov r1, r8\n"
        "    str r1, [r0]\n"
        "    str r7, [r0, #4]\n"
        "    ldr r1, .L0813AF08\n"
        "    ldr r0, .L0813AF0C\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r1]\n"
        "    movs r0, #0xf0\n"
        "    bl sub_0813BECC\n"
        "    bl sub_08130C6C\n"
        "    movs r0, #4\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    bl sub_080D3400\n"
        "    ldr r1, .L0813AF10\n"
        "    str r0, [r1]\n"
        "    ldr r4, .L0813AF14\n"
        "    ldrh r0, [r4]\n"
        "    ldrh r1, [r4, #2]\n"
        "    ldrh r2, [r4, #4]\n"
        "    ldrh r3, [r4, #6]\n"
        "    ldrh r4, [r4, #8]\n"
        "    str r4, [sp]\n"
        "    bl sub_080D347C\n"
        "    b .L0813B07A\n"
        ".L0813AF04: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8\n"
        ".L0813AF08: .4byte 0x030068D8 @ IWRAM+0x68D8\n"
        ".L0813AF0C: .4byte 0x0203DB50 @ EWRAM+0x3DB50\n"
        ".L0813AF10: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L0813AF14: .4byte 0x03006980 @ IWRAM+0x6980\n"
        ".L0813AF18:\n"
        "    cmp r5, #7\n"
        "    bne .L0813AF58\n"
        "    ldr r0, .L0813AF54\n"
        "    ldrh r0, [r0]\n"
        "    bl sub_0813E804\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L0813AF2C\n"
        "    b .L0813B0D2\n"
        ".L0813AF2C:\n"
        "    bl Stock_GetCapacity\n"
        "    adds r5, r0, #0\n"
        "    movs r4, #0\n"
        "    cmp r6, r5\n"
        "    blt .L0813AF3A\n"
        "    b .L0813B0BA\n"
        ".L0813AF3A:\n"
        "    adds r0, r4, #4\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    bne .L0813AF46\n"
        "    b .L0813B0E0\n"
        ".L0813AF46:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, r5\n"
        "    blt .L0813AF3A\n"
        "    b .L0813B0BA\n"
        "    .byte 0x00, 0x00\n"
        ".L0813AF54: .4byte 0x0203DB28 @ EWRAM+0x3DB28\n"
        ".L0813AF58:\n"
        "    cmp r5, #8\n"
        "    beq .L0813AF5E\n"
        "    b .L0813B098\n"
        ".L0813AF5E:\n"
        "    ldr r0, .L0813AFAC\n"
        "    mov r1, r8\n"
        "    str r1, [r0]\n"
        "    str r7, [r0, #4]\n"
        "    movs r3, #0\n"
        "    ldr r5, .L0813AFB0\n"
        "    ldr r2, .L0813AFB4\n"
        "    movs r1, #0\n"
        ".L0813AF6E:\n"
        "    lsls r0, r3, #1\n"
        "    adds r0, r0, r2\n"
        "    strh r1, [r0]\n"
        "    adds r0, r3, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    cmp r3, #0xf\n"
        "    bls .L0813AF6E\n"
        "    ldr r4, .L0813AFB4\n"
        "    adds r0, r5, #0\n"
        "    adds r1, r4, #0\n"
        "    bl Combatant_DecodeName\n"
        "    movs r3, #0xe\n"
        "    movs r2, #0xc6\n"
        "    lsls r2, r2, #2\n"
        ".L0813AF8E:\n"
        "    lsls r0, r3, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    beq .L0813AFB8\n"
        "    adds r0, r3, #1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r1, [r0]\n"
        "    cmp r1, #0\n"
        "    beq .L0813AFA8\n"
        "    cmp r1, r2\n"
        "    bne .L0813AFB8\n"
        ".L0813AFA8:\n"
        "    strh r2, [r0]\n"
        "    b .L0813AFC2\n"
        ".L0813AFAC: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8\n"
        ".L0813AFB0: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L0813AFB4: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L0813AFB8:\n"
        "    subs r0, r3, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    cmp r3, #0\n"
        "    bne .L0813AF8E\n"
        ".L0813AFC2:\n"
        "    ldr r0, .L0813B000\n"
        "    ldrh r1, [r0]\n"
        "    adds r3, #1\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    movs r0, #0x27\n"
        "    movs r2, #0\n"
        "    bl MsgGlyphQueue_PushSubstClamped\n"
        "    movs r3, #0\n"
        "    ldr r2, .L0813B004\n"
        "    movs r1, #0\n"
        ".L0813AFDA:\n"
        "    lsls r0, r3, #1\n"
        "    adds r0, r0, r2\n"
        "    strh r1, [r0]\n"
        "    adds r0, r3, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    cmp r3, #0xf\n"
        "    bls .L0813AFDA\n"
        "    movs r0, #1\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L0813B00C\n"
        "    ldr r0, .L0813B008\n"
        "    ldr r1, .L0813B004\n"
        "    bl Combatant_DecodeName\n"
        "    b .L0813B014\n"
        "    .byte 0x00, 0x00\n"
        ".L0813B000: .4byte gUnknown_0879038A\n"
        ".L0813B004: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L0813B008: .4byte 0x03004740 @ IWRAM+0x4740\n"
        ".L0813B00C:\n"
        "    ldr r0, .L0813B040\n"
        "    ldr r1, .L0813B044\n"
        "    bl Combatant_DecodeName\n"
        ".L0813B014:\n"
        "    movs r3, #0xe\n"
        "    ldr r4, .L0813B044\n"
        "    ldr r6, .L0813B048\n"
        "    adds r5, r4, #0\n"
        "    movs r2, #0xc6\n"
        "    lsls r2, r2, #2\n"
        ".L0813B020:\n"
        "    lsls r0, r3, #1\n"
        "    adds r0, r0, r5\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    beq .L0813B04C\n"
        "    adds r0, r3, #1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r1, [r0]\n"
        "    cmp r1, #0\n"
        "    beq .L0813B03A\n"
        "    cmp r1, r2\n"
        "    bne .L0813B04C\n"
        ".L0813B03A:\n"
        "    strh r2, [r0]\n"
        "    b .L0813B056\n"
        "    .byte 0x00, 0x00\n"
        ".L0813B040: .4byte 0x030047C0 @ IWRAM+0x47C0\n"
        ".L0813B044: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L0813B048: .4byte gUnknown_0879038A\n"
        ".L0813B04C:\n"
        "    subs r0, r3, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    cmp r3, #0\n"
        "    bne .L0813B020\n"
        ".L0813B056:\n"
        "    ldrh r1, [r6, #2]\n"
        "    adds r3, #1\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    movs r0, #0x27\n"
        "    movs r2, #0\n"
        "    bl MsgGlyphQueue_PushSubstClamped\n"
        "    ldr r1, .L0813B084\n"
        "    movs r0, #0x48\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L0813B088\n"
        "    movs r0, #2\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L0813B08C\n"
        "    ldr r1, .L0813B090\n"
        "    bl Task_Create\n"
        ".L0813B07A:\n"
        "    ldr r1, .L0813B094\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    b .L0813B118\n"
        "    .byte 0x00, 0x00\n"
        ".L0813B084: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L0813B088: .4byte 0x03006688 @ IWRAM+0x6688\n"
        ".L0813B08C: .4byte gUnknown_0878FD14\n"
        ".L0813B090: .4byte 0x0000FFFF\n"
        ".L0813B094: .4byte 0x0203DB6E @ EWRAM+0x3DB6E\n"
        ".L0813B098:\n"
        "    mov r0, ip\n"
        "    cmp r0, #9\n"
        "    bne .L0813B118\n"
        "    movs r0, #0x3a\n"
        "    bl sub_08132350\n"
        "    movs r4, #0x80\n"
        "    lsls r4, r4, #2\n"
        "    movs r0, #0\n"
        "    bl Combatant_GetStatus\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    adds r0, r6, #0\n"
        "    ands r0, r4\n"
        "    cmp r0, #0\n"
        "    beq .L0813B0C8\n"
        ".L0813B0BA:\n"
        "    ldr r0, .L0813B0C4\n"
        "    mov r1, r8\n"
        "    str r1, [r0]\n"
        "    b .L0813B118\n"
        "    .byte 0x00, 0x00\n"
        ".L0813B0C4: .4byte 0x030068E4 @ IWRAM+0x68E4\n"
        ".L0813B0C8:\n"
        "    ldr r0, .L0813B0D8\n"
        "    ldrh r0, [r0, #0xc]\n"
        "    ands r0, r6\n"
        "    cmp r0, #0\n"
        "    beq .L0813B108\n"
        ".L0813B0D2:\n"
        "    ldr r0, .L0813B0DC\n"
        "    str r7, [r0]\n"
        "    b .L0813B118\n"
        ".L0813B0D8: .4byte gUnknown_08790D80\n"
        ".L0813B0DC: .4byte 0x030068E4 @ IWRAM+0x68E4\n"
        ".L0813B0E0:\n"
        "    ldr r0, .L0813B0FC\n"
        "    ldrh r0, [r0]\n"
        "    bl Inventory_RemoveItem\n"
        "    ldr r0, .L0813B100\n"
        "    ldrh r0, [r0]\n"
        "    bl Inventory_RemoveItem\n"
        "    ldr r0, .L0813B104\n"
        "    ldrh r0, [r0]\n"
        "    bl Stock_AddDemon\n"
        "    b .L0813B118\n"
        "    .byte 0x00, 0x00\n"
        ".L0813B0FC: .4byte 0x0203DB50 @ EWRAM+0x3DB50\n"
        ".L0813B100: .4byte 0x030068D8 @ IWRAM+0x68D8\n"
        ".L0813B104: .4byte 0x0203DB28 @ EWRAM+0x3DB28\n"
        ".L0813B108:\n"
        "    ldr r0, .L0813B124\n"
        "    ldrh r0, [r0, #0xc]\n"
        "    ands r6, r0\n"
        "    orrs r6, r4\n"
        "    movs r0, #0\n"
        "    adds r1, r6, #0\n"
        "    bl Combatant_SetStatus\n"
        ".L0813B118:\n"
        "    add sp, #4\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L0813B124: .4byte gUnknown_08790DA0\n"
    );
}
#endif

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
    sub_080CDC34();
}
