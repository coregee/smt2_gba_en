/* Script VM opcode handlers 0x427-0x437 and their alternate (skip) forms. */

#include "global.h"
#include "scriptops2.h"

// sub_0813A224 @ 0x0813A224
void sub_0813A224(void)
{
}

// ScriptOp_427 @ 0x0813A228
void ScriptOp_427(void)
{
}

// ScriptOpAlt_427 @ 0x0813A22C
void ScriptOpAlt_427(void)
{
}

// ScriptOp_428 @ 0x0813A230
void ScriptOp_428(void)
{
}

// ScriptOpAlt_428 @ 0x0813A234
void ScriptOpAlt_428(void)
{
}

/* Warps to world map position (operand 1: x << 8 | y, operand 2: direction). */
// ScriptOp_429 @ 0x0813A238
void ScriptOp_429(void)
{
    u16 pos = SCRIPT_READ();
    u16 dir = SCRIPT_READ();
    u16 x = pos >> 8;
    u16 y = pos & 0xFF;

    gScriptWaitState = 0x14;
    gUnk_03006954 = Warp_ToWorldPosition(0, x, y, dir, 1);
    gScriptYield = 1;
}

// sub_0813A298 @ 0x0813A298
void sub_0813A298(void)
{
    gScriptPc += 2;
}

// ScriptOp_42A @ 0x0813A2A8
void ScriptOp_42A(void)
{
}

// ScriptOpAlt_42A @ 0x0813A2AC
void ScriptOpAlt_42A(void)
{
}

// ScriptOp_42B @ 0x0813A2B0
void ScriptOp_42B(void)
{
    gScriptPc++;
    gScriptYield = 1;
}

// ScriptOpAlt_42B @ 0x0813A2C8
void ScriptOpAlt_42B(void)
{
    gScriptPc++;
}

// ScriptOp_42C @ 0x0813A2D8
void ScriptOp_42C(void)
{
}

// ScriptOpAlt_42C @ 0x0813A2DC
void ScriptOpAlt_42C(void)
{
}

// ScriptOp_42D @ 0x0813A2E0
void ScriptOp_42D(void)
{
}

// ScriptOpAlt_42D @ 0x0813A2E4
void ScriptOpAlt_42D(void)
{
}

// ScriptOp_42E @ 0x0813A2E8
void ScriptOp_42E(void)
{
}

// ScriptOpAlt_42E @ 0x0813A2EC
void ScriptOpAlt_42E(void)
{
}

// ScriptOp_42F @ 0x0813A2F0
void ScriptOp_42F(void)
{
}

// ScriptOpAlt_42F @ 0x0813A2F4
void ScriptOpAlt_42F(void)
{
}

// ScriptOp_430 @ 0x0813A2F8
void ScriptOp_430(void)
{
    Party_RestoreHumans();
}

// ScriptOpAlt_430 @ 0x0813A304
void ScriptOpAlt_430(void)
{
}

// ScriptOp_431 @ 0x0813A308
void ScriptOp_431(void)
{
}

// ScriptOpAlt_431 @ 0x0813A30C
void ScriptOpAlt_431(void)
{
}

/* Writes a fixed 3-glyph name (0x31 0x7C 0x65, 0xFF-padded to 8 bytes) into the name
   field of Battle_GetCombatant(0x8000). */
// ScriptOp_432 @ 0x0813A310
#ifdef NONMATCHING
void ScriptOp_432(void)
{
    gScriptPc++;
    ((u8 *)Battle_GetCombatant(0x8000))[0] = 0x31;
    ((u8 *)Battle_GetCombatant(0x8000))[1] = 0x7C;
    ((u8 *)Battle_GetCombatant(0x8000))[2] = 0x65;
    ((u8 *)Battle_GetCombatant(0x8000))[3] = 0xFF;
    ((s8 *)Battle_GetCombatant(0x8000))[4] = -1;
    ((s8 *)Battle_GetCombatant(0x8000))[5] = -1;
    ((s8 *)Battle_GetCombatant(0x8000))[6] = -1;
    ((s8 *)Battle_GetCombatant(0x8000))[7] = -1;
    Party_FixFormation();
}
#else
NAKED
void ScriptOp_432(void)
{
    asm_unified(
        "    push {r4, lr}\n"
        "    ldr r1, .L0813A380\n"
        "    ldrh r0, [r1]\n"
        "    adds r0, #1\n"
        "    strh r0, [r1]\n"
        "    movs r4, #0x80\n"
        "    lsls r4, r4, #8\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    movs r1, #0x31\n"
        "    strb r1, [r0]\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    movs r1, #0x7c\n"
        "    strb r1, [r0, #1]\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    movs r1, #0x65\n"
        "    strb r1, [r0, #2]\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    movs r1, #0xff\n"
        "    strb r1, [r0, #3]\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    movs r1, #1\n"
        "    rsbs r1, r1, #0\n"
        "    strb r1, [r0, #4]\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    movs r1, #1\n"
        "    rsbs r1, r1, #0\n"
        "    strb r1, [r0, #5]\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    movs r1, #1\n"
        "    rsbs r1, r1, #0\n"
        "    strb r1, [r0, #6]\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    movs r1, #1\n"
        "    rsbs r1, r1, #0\n"
        "    strb r1, [r0, #7]\n"
        "    bl Party_FixFormation\n"
        "    pop {r4}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L0813A380: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
    );
}
#endif

// ScriptOpAlt_432 @ 0x0813A384
void ScriptOpAlt_432(void)
{
    gScriptPc++;
}

// ScriptOp_433 @ 0x0813A394
void ScriptOp_433(void)
{
    Party_SnapshotHumans();
}

// ScriptOpAlt_433 @ 0x0813A3A0
void ScriptOpAlt_433(void)
{
}

// sub_0813A3A4 @ 0x0813A3A4
void sub_0813A3A4(s32 v)
{
    if (gUnk_030065F0 == 0)
        Money_Add(v);
}

/* Pays the fee for gUnk_030065E0 (table gUnknown_08790CC8); jumps when there is not enough. */
// ScriptOp_434 @ 0x0813A3C0
void ScriptOp_434(void)
{
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ() << 16 | lo;
    u16 fee;

    gUnk_0203DB2C = fee = gUnknown_08790CC8[gUnk_030065E0 - 0x61];
    if (Money_Get() < fee)
        gScriptJumpTarget = (u16 *)target;
    else
        sub_0813A3A4(-fee);
}

// ScriptOp_435 @ 0x0813A42C
void ScriptOp_435(void)
{
    u32 v = 0;
    u16 mode = SCRIPT_READ();
    u16 k, i;

    if (mode == 1)
        gScriptItemCheckId = gUnknown_0878FDB4[gScriptItemCheckId - 0x120];
    else if (mode == 2)
    {
        k = gUnk_030068D8 + gScriptItemCheckId - 0x240;
        i = 0;
        while (k >= gUnknown_0878FDCC[i])
            i += 2;
        gUnk_0203DB28[0] = gUnknown_0878FDCC[i + 1];
    }
    else if (mode == 3)
        gUnk_0203DB84 = 100;
    else if (mode == 4)
        gUnk_0203DB84 = 10;
    else if (mode == 5)
        sub_080C31B4(gUnk_030037F0);
    else if (mode == 6)
        sub_080D53FC();
    else if (mode == 7)
    {
        gMsgGlyphCount = v;
        gTextColumn = v;
        gTextLine = v;
        gUnk_0203DB4A = v;
        if (gMsgWindowOpen)
        {
            Window_Close(gMsgWindow, 1);
            gMsgWindowOpen = v;
        }
    }
    else if (mode == 8)
    {
        v = gUnk_030037F0 * gUnk_0203DB84;
        Money_Add(v);
    }
}

// ScriptOpAlt_435 @ 0x0813A570
void ScriptOpAlt_435(void)
{
    gScriptPc++;
}

// ScriptOp_436 @ 0x0813A580
void ScriptOp_436(void)
{
}

// ScriptOpAlt_436 @ 0x0813A584
void ScriptOpAlt_436(void)
{
}

// ScriptOp_437 @ 0x0813A588
void ScriptOp_437(void)
{
}

// ScriptOpAlt_437 @ 0x0813A58C
void ScriptOpAlt_437(void)
{
}
