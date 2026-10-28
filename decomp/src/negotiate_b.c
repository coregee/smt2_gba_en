/* Script VM opcode handlers 0x3D7-0x3E2: demon negotiation (reactions, mood counters and
   the jumps into the per-personality reply scripts). */

#include "global.h"
#include "scriptops2.h"

// ScriptOp_3D7 @ 0x081380DC
void ScriptOp_3D7(void)
{
    u16 mode = SCRIPT_READ();
    u16 lo = SCRIPT_READ();
    u16 *p = (u16 *)(SCRIPT_READ() << 16 | lo);

    gUnk_03006840 = (u32)p;
    if (mode == 0)
        Negotiate_PickReaction();
    else if (mode == 1)
        sub_081380CC(1);
    else if (mode == 2)
        sub_081380CC(2);
    else if (mode == 6)
        sub_081380CC(6);
}

// ScriptOp_3D8 @ 0x08138154
void ScriptOp_3D8(void)
{
}

// ScriptOp_3D9 @ 0x08138158
void ScriptOp_3D9(void)
{
}

// ScriptOp_3DA @ 0x0813815C
void ScriptOp_3DA(void)
{
}

// ScriptOp_3DB @ 0x08138160
void ScriptOp_3DB(void)
{
}

// ScriptOp_3DC @ 0x08138164
void ScriptOp_3DC(void)
{
}

// ScriptOp_3DD @ 0x08138168
void ScriptOp_3DD(void)
{
}

// ScriptOp_3DE @ 0x0813816C
void ScriptOp_3DE(void)
{
}

/* Adds the operand to the counter gUnk_030068B4; 0xFF/0xFE/0xFD subtract 1/2/3 (floored at 0). */
// ScriptOp_3DF @ 0x08138170
void ScriptOp_3DF(void)
{
    u16 v = SCRIPT_READ();
    u16 d;

    if (v == 0xFF)
    {
        d = 0xFFFF;
        if (gUnk_030068B4 <= 1)
            gUnk_030068B4 = 0;
        else
            gUnk_030068B4 -= 1;
    }
    else if (v == 0xFE)
    {
        d = 0xFFFE;
        if (gUnk_030068B4 <= 2)
            gUnk_030068B4 = 0;
        else
            gUnk_030068B4 -= 2;
    }
    else if (v == 0xFD)
    {
        d = 0xFFFD;
        if (gUnk_030068B4 <= 3)
            gUnk_030068B4 = 0;
        else
            gUnk_030068B4 -= 3;
    }
    else
    {
        d = v;
        gUnk_030068B4 += d;
    }
    sub_080EFA20(d);
    if (gUnk_030068B4 & 0x80)
        gUnk_030068B4 = 0;
}

/* Same for the counter gUnk_030069E8, with 0xFF-0xFA subtracting 1-6. */
// sub_0813821C @ 0x0813821C
void sub_0813821C(u16 v)
{
    u16 d;

    if (v == 0xFF)
    {
        d = 0xFFFF;
        if (gUnk_030069E8 <= 1)
            gUnk_030069E8 = 0;
        else
            gUnk_030069E8 -= 1;
    }
    else if (v == 0xFE)
    {
        d = 0xFFFE;
        if (gUnk_030069E8 <= 2)
            gUnk_030069E8 = 0;
        else
            gUnk_030069E8 -= 2;
    }
    else if (v == 0xFD)
    {
        d = 0xFFFD;
        if (gUnk_030069E8 <= 3)
            gUnk_030069E8 = 0;
        else
            gUnk_030069E8 -= 3;
    }
    else if (v == 0xFC)
    {
        d = 0xFFFC;
        if (gUnk_030069E8 <= 4)
            gUnk_030069E8 = 0;
        else
            gUnk_030069E8 -= 4;
    }
    else if (v == 0xFB)
    {
        d = 0xFFFB;
        if (gUnk_030069E8 <= 5)
            gUnk_030069E8 = 0;
        else
            gUnk_030069E8 -= 5;
    }
    else if (v == 0xFA)
    {
        d = 0xFFFA;
        if (gUnk_030069E8 <= 6)
            gUnk_030069E8 = 0;
        else
            gUnk_030069E8 -= 6;
    }
    else
    {
        d = v;
        gUnk_030069E8 += d;
    }
    sub_080EFA44(d);
    if (gUnk_030069E8 & 0x80)
        gUnk_030069E8 = 0;
}

// ScriptOp_3E0 @ 0x08138310
void ScriptOp_3E0(void)
{
    sub_0813821C(SCRIPT_READ());
}

// sub_08138338 @ 0x08138338
u16 sub_08138338(void)
{
    u16 r = Random_Byte();

    return r % 4;
}

/* Jumps to one of the 4 targets that follow, chosen at random. */
// ScriptOp_3E1 @ 0x08138350
void ScriptOp_3E1(void)
{
    u16 lo;
    u16 k = sub_08138338() * 2;
    u16 *t;

    gScriptPc += k;
    lo = SCRIPT_READ();
    t = (u16 *)(gScriptBase[gScriptPc] << 16 | lo);
    gScriptJumpTarget = t;
}

/* Calls reply n of the demon's personality (gUnk_0300685C >> 4): saves the script position
   and jumps into that personality's reply table. */
// Negotiate_CallReply @ 0x08138390
#ifdef NONMATCHING
void Negotiate_CallReply(u16 n)
{
    u8 b;
    u32 p;
    u16 idx;

    gUnk_030068C4 = gScriptBase;
    gUnk_03006818 = gScriptPc;
    gUnk_0203DB64 = 1;
    b = gUnk_0300685C;
    p = b >> 4;
    idx = ((b & 0xF) + n * gUnknown_087904F2[p]) * 2;
    if (p == 0)
        gScriptBase = gUnknown_0803473C;
    else if (p == 1)
        gScriptBase = gUnknown_08033560;
    else if (p == 2)
        gScriptBase = gUnknown_08032DE0;
    else if (p == 3)
        gScriptBase = gUnknown_080341EC;
    else if (p == 4)
        gScriptBase = gUnknown_0803473C;
    else if (p == 5)
        gScriptBase = gUnknown_08033560;
    else if (p == 6)
        gScriptBase = gUnknown_08032DE0;
    else if (p == 7)
        gScriptBase = gUnknown_080341EC;
    else if (p == 8)
        gScriptBase = gUnknown_08034094;
    else if (p == 9)
        gScriptBase = gUnknown_0803526C;
    else if (p == 10)
        gScriptBase = gUnknown_080340B8;
    else
        gScriptBase = gUnknown_08034138;
    gScriptJumpTarget = (u16 *)(gScriptBase[idx + 1] << 16 | gScriptBase[idx]);
}
#else
NAKED
void Negotiate_CallReply(u16 n)
{
    asm_unified(
        ".L08138390:\n"
        "    push {r4, r5, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    ldr r2, .L081383D0\n"
        "    ldr r4, .L081383D4\n"
        "    ldr r1, [r4]\n"
        "    str r1, [r2]\n"
        "    ldr r2, .L081383D8\n"
        "    ldr r1, .L081383DC\n"
        "    ldrh r1, [r1]\n"
        "    strh r1, [r2]\n"
        "    ldr r2, .L081383E0\n"
        "    movs r1, #1\n"
        "    strh r1, [r2]\n"
        "    ldr r1, .L081383E4\n"
        "    ldrb r3, [r1]\n"
        "    lsrs r5, r3, #4\n"
        "    ldr r2, .L081383E8\n"
        "    lsls r1, r5, #1\n"
        "    adds r1, r1, r2\n"
        "    ldrh r2, [r1]\n"
        "    movs r1, #0xf\n"
        "    ands r1, r3\n"
        "    muls r0, r2, r0\n"
        "    adds r1, r1, r0\n"
        "    lsls r1, r1, #0x11\n"
        "    lsrs r2, r1, #0x10\n"
        "    cmp r5, #0\n"
        "    bne .L081383F0\n"
        "    ldr r0, .L081383EC\n"
        "    b .L0813846A\n"
        "    .byte 0x00, 0x00\n"
        ".L081383D0: .4byte 0x030068C4 @ IWRAM+0x68C4\n"
        ".L081383D4: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L081383D8: .4byte 0x03006818 @ IWRAM+0x6818\n"
        ".L081383DC: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L081383E0: .4byte 0x0203DB64 @ EWRAM+0x3DB64\n"
        ".L081383E4: .4byte 0x0300685C @ IWRAM+0x685C\n"
        ".L081383E8: .4byte gUnknown_087904F2\n"
        ".L081383EC: .4byte gUnknown_0803473C\n"
        ".L081383F0:\n"
        "    cmp r5, #1\n"
        "    bne .L081383FC\n"
        "    ldr r0, .L081383F8\n"
        "    b .L0813846A\n"
        ".L081383F8: .4byte gUnknown_08033560\n"
        ".L081383FC:\n"
        "    cmp r5, #2\n"
        "    bne .L08138408\n"
        "    ldr r0, .L08138404\n"
        "    b .L0813846A\n"
        ".L08138404: .4byte gUnknown_08032DE0\n"
        ".L08138408:\n"
        "    cmp r5, #3\n"
        "    bne .L08138414\n"
        "    ldr r0, .L08138410\n"
        "    b .L0813846A\n"
        ".L08138410: .4byte gUnknown_080341EC\n"
        ".L08138414:\n"
        "    cmp r5, #4\n"
        "    bne .L08138420\n"
        "    ldr r0, .L0813841C\n"
        "    b .L0813846A\n"
        ".L0813841C: .4byte gUnknown_0803473C\n"
        ".L08138420:\n"
        "    cmp r5, #5\n"
        "    bne .L0813842C\n"
        "    ldr r0, .L08138428\n"
        "    b .L0813846A\n"
        ".L08138428: .4byte gUnknown_08033560\n"
        ".L0813842C:\n"
        "    cmp r5, #6\n"
        "    bne .L08138438\n"
        "    ldr r0, .L08138434\n"
        "    b .L0813846A\n"
        ".L08138434: .4byte gUnknown_08032DE0\n"
        ".L08138438:\n"
        "    cmp r5, #7\n"
        "    bne .L08138444\n"
        "    ldr r0, .L08138440\n"
        "    b .L0813846A\n"
        ".L08138440: .4byte gUnknown_080341EC\n"
        ".L08138444:\n"
        "    cmp r5, #8\n"
        "    bne .L08138450\n"
        "    ldr r0, .L0813844C\n"
        "    b .L0813846A\n"
        ".L0813844C: .4byte gUnknown_08034094\n"
        ".L08138450:\n"
        "    cmp r5, #9\n"
        "    bne .L0813845C\n"
        "    ldr r0, .L08138458\n"
        "    b .L0813846A\n"
        ".L08138458: .4byte gUnknown_0803526C\n"
        ".L0813845C:\n"
        "    cmp r5, #0xa\n"
        "    bne .L08138468\n"
        "    ldr r0, .L08138464\n"
        "    b .L0813846A\n"
        ".L08138464: .4byte gUnknown_080340B8\n"
        ".L08138468:\n"
        "    ldr r0, .L08138484\n"
        ".L0813846A:\n"
        "    str r0, [r4]\n"
        "    ldr r1, [r4]\n"
        "    lsls r0, r2, #1\n"
        "    adds r0, r0, r1\n"
        "    ldrh r1, [r0]\n"
        "    ldrh r0, [r0, #2]\n"
        "    lsls r0, r0, #0x10\n"
        "    orrs r0, r1\n"
        "    ldr r1, .L08138488\n"
        "    str r0, [r1]\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L08138484: .4byte gUnknown_08034138\n"
        ".L08138488: .4byte 0x030068E4 @ IWRAM+0x68E4\n"
    );
}
#endif

// sub_0813848C @ 0x0813848C
#ifdef NONMATCHING
void sub_0813848C(u16 n)
{
    u8 b;
    u32 p;
    u16 idx;

    gUnk_030068C4 = gScriptBase;
    gUnk_03006818 = gScriptPc;
    gUnk_0203DB64 = 1;
    b = gUnk_0300685C;
    p = b >> 4;
    idx = ((b & 0xF) + n * gUnknown_087904F2[p]) * 2;
    if (p == 0)
        gScriptBase = gUnknown_080367F2;
    else if (p == 1)
        gScriptBase = gUnknown_080366C2;
    else if (p == 2)
        gScriptBase = gUnknown_080366C2;
    else if (p == 3)
        gScriptBase = gUnknown_080367E2;
    else if (p == 4)
        gScriptBase = gUnknown_080367F2;
    else if (p == 5)
        gScriptBase = gUnknown_080366C2;
    else if (p == 6)
        gScriptBase = gUnknown_080366C2;
    else if (p == 7)
        gScriptBase = gUnknown_080367E2;
    else if (p == 8)
        gScriptBase = gUnknown_080367E2;
    else if (p == 9)
        gScriptBase = gUnknown_08037322;
    else if (p == 10)
        gScriptBase = gUnknown_080367E2;
    else
        gScriptBase = gUnknown_080367E2;
    gScriptJumpTarget = (u16 *)(gScriptBase[idx + 1] << 16 | gScriptBase[idx]);
}
#else
NAKED
void sub_0813848C(u16 n)
{
    asm_unified(
        ".L0813848C:\n"
        "    push {r4, r5, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    ldr r2, .L081384CC\n"
        "    ldr r4, .L081384D0\n"
        "    ldr r1, [r4]\n"
        "    str r1, [r2]\n"
        "    ldr r2, .L081384D4\n"
        "    ldr r1, .L081384D8\n"
        "    ldrh r1, [r1]\n"
        "    strh r1, [r2]\n"
        "    ldr r2, .L081384DC\n"
        "    movs r1, #1\n"
        "    strh r1, [r2]\n"
        "    ldr r1, .L081384E0\n"
        "    ldrb r3, [r1]\n"
        "    lsrs r5, r3, #4\n"
        "    ldr r2, .L081384E4\n"
        "    lsls r1, r5, #1\n"
        "    adds r1, r1, r2\n"
        "    ldrh r2, [r1]\n"
        "    movs r1, #0xf\n"
        "    ands r1, r3\n"
        "    muls r0, r2, r0\n"
        "    adds r1, r1, r0\n"
        "    lsls r1, r1, #0x11\n"
        "    lsrs r2, r1, #0x10\n"
        "    cmp r5, #0\n"
        "    bne .L081384EC\n"
        "    ldr r0, .L081384E8\n"
        "    b .L08138566\n"
        "    .byte 0x00, 0x00\n"
        ".L081384CC: .4byte 0x030068C4 @ IWRAM+0x68C4\n"
        ".L081384D0: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L081384D4: .4byte 0x03006818 @ IWRAM+0x6818\n"
        ".L081384D8: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L081384DC: .4byte 0x0203DB64 @ EWRAM+0x3DB64\n"
        ".L081384E0: .4byte 0x0300685C @ IWRAM+0x685C\n"
        ".L081384E4: .4byte gUnknown_087904F2\n"
        ".L081384E8: .4byte gUnknown_080367F2\n"
        ".L081384EC:\n"
        "    cmp r5, #1\n"
        "    bne .L081384F8\n"
        "    ldr r0, .L081384F4\n"
        "    b .L08138566\n"
        ".L081384F4: .4byte gUnknown_080366C2\n"
        ".L081384F8:\n"
        "    cmp r5, #2\n"
        "    bne .L08138504\n"
        "    ldr r0, .L08138500\n"
        "    b .L08138566\n"
        ".L08138500: .4byte gUnknown_080366C2\n"
        ".L08138504:\n"
        "    cmp r5, #3\n"
        "    bne .L08138510\n"
        "    ldr r0, .L0813850C\n"
        "    b .L08138566\n"
        ".L0813850C: .4byte gUnknown_080367E2\n"
        ".L08138510:\n"
        "    cmp r5, #4\n"
        "    bne .L0813851C\n"
        "    ldr r0, .L08138518\n"
        "    b .L08138566\n"
        ".L08138518: .4byte gUnknown_080367F2\n"
        ".L0813851C:\n"
        "    cmp r5, #5\n"
        "    bne .L08138528\n"
        "    ldr r0, .L08138524\n"
        "    b .L08138566\n"
        ".L08138524: .4byte gUnknown_080366C2\n"
        ".L08138528:\n"
        "    cmp r5, #6\n"
        "    bne .L08138534\n"
        "    ldr r0, .L08138530\n"
        "    b .L08138566\n"
        ".L08138530: .4byte gUnknown_080366C2\n"
        ".L08138534:\n"
        "    cmp r5, #7\n"
        "    bne .L08138540\n"
        "    ldr r0, .L0813853C\n"
        "    b .L08138566\n"
        ".L0813853C: .4byte gUnknown_080367E2\n"
        ".L08138540:\n"
        "    cmp r5, #8\n"
        "    bne .L0813854C\n"
        "    ldr r0, .L08138548\n"
        "    b .L08138566\n"
        ".L08138548: .4byte gUnknown_080367E2\n"
        ".L0813854C:\n"
        "    cmp r5, #9\n"
        "    bne .L08138558\n"
        "    ldr r0, .L08138554\n"
        "    b .L08138566\n"
        ".L08138554: .4byte gUnknown_08037322\n"
        ".L08138558:\n"
        "    cmp r5, #0xa\n"
        "    bne .L08138564\n"
        "    ldr r0, .L08138560\n"
        "    b .L08138566\n"
        ".L08138560: .4byte gUnknown_080367E2\n"
        ".L08138564:\n"
        "    ldr r0, .L08138580\n"
        ".L08138566:\n"
        "    str r0, [r4]\n"
        "    ldr r1, [r4]\n"
        "    lsls r0, r2, #1\n"
        "    adds r0, r0, r1\n"
        "    ldrh r1, [r0]\n"
        "    ldrh r0, [r0, #2]\n"
        "    lsls r0, r0, #0x10\n"
        "    orrs r0, r1\n"
        "    ldr r1, .L08138584\n"
        "    str r0, [r1]\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L08138580: .4byte gUnknown_080367E2\n"
        ".L08138584: .4byte 0x030068E4 @ IWRAM+0x68E4\n"
    );
}
#endif

// ScriptOp_3E2_40F @ 0x08138588
void ScriptOp_3E2_40F(void)
{
    Negotiate_CallReply(SCRIPT_READ());
    gMsgGlyphCount = 0;
    gTextColumn = 0;
    gTextLine = 0;
    Font_ResetGlyphSpriteCache(0x180);
}
