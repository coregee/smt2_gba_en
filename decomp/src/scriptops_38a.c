/* Script VM opcode handlers 0x38A-0x3D6. */

#include "global.h"
#include "scriptops2.h"

// ScriptOp_38A @ 0x08136D58
void ScriptOp_38A(void)
{
}

// ScriptOp_38B @ 0x08136D5C
#ifdef NONMATCHING
void ScriptOp_38B(void)
{
    u16 a = SCRIPT_READ();
    u16 b = SCRIPT_READ();

    gUnk_03006964 = sub_080B4420(gUnknown_0879041E[b * 2 + 1], gUnknown_0879041E[b * 2]);
    if (a & 0xF0)
        sub_080ECF80();
    gScriptYield = 1;
    gScriptWaitState = 0x34;
}
#else
NAKED
void ScriptOp_38B(void)
{
    asm_unified(
        "    push {r4, lr}\n"
        "    ldr r3, .L08136DB8\n"
        "    ldrh r0, [r3]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r3]\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r2, .L08136DBC\n"
        "    ldr r2, [r2]\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r2\n"
        "    ldrh r4, [r0]\n"
        "    adds r0, r1, #1\n"
        "    strh r0, [r3]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0xf\n"
        "    adds r1, r1, r2\n"
        "    ldrh r1, [r1]\n"
        "    ldr r2, .L08136DC0\n"
        "    lsls r0, r1, #1\n"
        "    lsls r1, r1, #2\n"
        "    adds r1, r1, r2\n"
        "    ldrh r1, [r1]\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r0, [r0]\n"
        "    bl sub_080B4420\n"
        "    ldr r1, .L08136DC4\n"
        "    str r0, [r1]\n"
        "    movs r0, #0xf0\n"
        "    ands r4, r0\n"
        "    cmp r4, #0\n"
        "    beq .L08136DA4\n"
        "    bl sub_080ECF80\n"
        ".L08136DA4:\n"
        "    ldr r1, .L08136DC8\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L08136DCC\n"
        "    movs r0, #0x34\n"
        "    strh r0, [r1]\n"
        "    pop {r4}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L08136DB8: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L08136DBC: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L08136DC0: .4byte gUnknown_0879041E\n"
        ".L08136DC4: .4byte 0x03006964 @ IWRAM+0x6964\n"
        ".L08136DC8: .4byte 0x0203DB6E @ EWRAM+0x3DB6E\n"
        ".L08136DCC: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
    );
}
#endif

// ScriptOp_38C @ 0x08136DD0
void ScriptOp_38C(void)
{
}

// ScriptOp_38D @ 0x08136DD4
void ScriptOp_38D(void)
{
    u8 have = sub_080C32D4(gScriptItemCheckId);
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ() << 16 | lo;

    if (have + Party_CountEquipped(0xFF, gScriptItemCheckId) > 0x62)
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_390 @ 0x08136E34
void ScriptOp_390(void)
{
}

// ScriptOp_391 @ 0x08136E38
void ScriptOp_391(void)
{
}

// ScriptOp_392 @ 0x08136E3C
void ScriptOp_392(void)
{
    gUnk_0203DB58 = 0;
    gMsgGlyphCount = 0;
    gTextColumn = 0;
    gTextLine = 0;
    gUnk_0203DB4A = 0;
    if (gMsgWindowOpen)
    {
        Window_Close(gMsgWindow, 1);
        gMsgWindowOpen = 0;
    }
    Font_ResetGlyphSpriteCache(0x180);
    gUnk_030068E0 = SaveScreen_Open(3, 1);
    gScriptWaitState = 0x2B;
    gScriptYield = 1;
}

// ScriptOp_394 @ 0x08136EB8
void ScriptOp_394(void)
{
}

// ScriptOp_395 @ 0x08136EBC
void ScriptOp_395(void)
{
    u16 i = SCRIPT_READ();

    gScriptPc++;
    sub_080C4580(gUnk_030068F0[i & 0xF]);
}

// ScriptOp_396 @ 0x08136EF8
void ScriptOp_396(void)
{
    gScriptPc++;
}

// ScriptOp_398 @ 0x08136F08
void ScriptOp_398(void)
{
}

// ScriptOp_399 @ 0x08136F0C
void ScriptOp_399(void)
{
}

// ScriptOp_39A @ 0x08136F10
void ScriptOp_39A(void)
{
}

// ScriptOp_39B @ 0x08136F14
#ifdef NONMATCHING
void ScriptOp_39B(void)
{
    u16 i, j;
    u8 k;
    u16 lo;
    u16 *p;

    MsgWindow_SaveGlyphs();
    lo = SCRIPT_READ();
    p = (u16 *)(SCRIPT_READ() << 16 | lo);
    gUnk_0203DAC8[0] = p;
    lo = SCRIPT_READ();
    p = (u16 *)(SCRIPT_READ() << 16 | lo);
    gUnk_0203DAC8[1] = p;
    for (i = 0; i < 20; i++)
        gUnk_0203DB88[i] |= 0xFFFF;
    k = gUnk_03006914;
    if (k != 1)
        k = 0;
    j = 1;
    gUnk_03006604 = gUnknown_0878EEDC[k][0];
    for (i = 0; i < gUnk_03006604 + 1; i++)
        gUnk_0203DB88[i] = gUnknown_0878EEDC[k][j++];
    gUnk_03006940 = 0;
    gUnk_0300696C = 0;
    gUnk_03006844 = 4;
    sub_0812F2B4(4);
    Task_Create(gUnknown_0878FC80, 0xFFFF);
    gScriptYield = 1;
    gScriptWaitState = 0xD;
}
#else
NAKED
void ScriptOp_39B(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    bl MsgWindow_SaveGlyphs\n"
        "    ldr r3, .L08137020\n"
        "    ldrh r0, [r3]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r3]\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r2, .L08137024\n"
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
        "    ldr r5, .L08137028\n"
        "    str r0, [r5]\n"
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
        "    str r0, [r5, #4]\n"
        "    movs r3, #0\n"
        "    ldr r4, .L0813702C\n"
        "    ldr r0, .L08137030\n"
        "    adds r2, r0, #0\n"
        ".L08136F70:\n"
        "    lsls r0, r3, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r1, [r0]\n"
        "    orrs r1, r2\n"
        "    strh r1, [r0]\n"
        "    adds r0, r3, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    cmp r3, #0x13\n"
        "    bls .L08136F70\n"
        "    ldr r0, .L08137034\n"
        "    ldrb r1, [r0]\n"
        "    cmp r1, #1\n"
        "    beq .L08136F8E\n"
        "    movs r1, #0\n"
        ".L08136F8E:\n"
        "    ldr r2, .L08137038\n"
        "    ldr r5, .L0813703C\n"
        "    movs r4, #1\n"
        "    lsls r0, r1, #2\n"
        "    adds r0, r0, r1\n"
        "    lsls r1, r0, #2\n"
        "    adds r0, r1, r5\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r2]\n"
        "    movs r3, #0\n"
        "    movs r6, #0\n"
        "    ldrsh r0, [r2, r6]\n"
        "    adds r0, #1\n"
        "    ldr r6, .L08137040\n"
        "    mov r8, r6\n"
        "    ldr r6, .L08137044\n"
        "    mov sb, r6\n"
        "    ldr r6, .L08137048\n"
        "    mov sl, r6\n"
        "    cmp r3, r0\n"
        "    bge .L08136FE8\n"
        "    ldr r0, .L0813702C\n"
        "    mov ip, r0\n"
        "    adds r7, r5, #0\n"
        "    adds r5, r1, #0\n"
        "    adds r6, r2, #0\n"
        ".L08136FC2:\n"
        "    lsls r2, r3, #1\n"
        "    add r2, ip\n"
        "    adds r1, r4, #0\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r5\n"
        "    adds r1, r1, r7\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r2]\n"
        "    adds r0, r3, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r6, r1]\n"
        "    adds r0, #1\n"
        "    cmp r3, r0\n"
        "    blt .L08136FC2\n"
        ".L08136FE8:\n"
        "    movs r0, #0\n"
        "    mov r6, r8\n"
        "    strh r0, [r6]\n"
        "    mov r1, sb\n"
        "    strh r0, [r1]\n"
        "    movs r0, #4\n"
        "    mov r6, sl\n"
        "    strh r0, [r6]\n"
        "    movs r0, #4\n"
        "    bl sub_0812F2B4\n"
        "    ldr r0, .L0813704C\n"
        "    ldr r1, .L08137030\n"
        "    bl Task_Create\n"
        "    ldr r1, .L08137050\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L08137054\n"
        "    movs r0, #0xd\n"
        "    strh r0, [r1]\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L08137020: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L08137024: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L08137028: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8\n"
        ".L0813702C: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L08137030: .4byte 0x0000FFFF\n"
        ".L08137034: .4byte 0x03006914 @ IWRAM+0x6914\n"
        ".L08137038: .4byte 0x03006604 @ IWRAM+0x6604\n"
        ".L0813703C: .4byte gUnknown_0878EEDC\n"
        ".L08137040: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08137044: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L08137048: .4byte 0x03006844 @ IWRAM+0x6844\n"
        ".L0813704C: .4byte gUnknown_0878FC80\n"
        ".L08137050: .4byte 0x0203DB6E @ EWRAM+0x3DB6E\n"
        ".L08137054: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
    );
}
#endif

// ScriptOp_39C @ 0x08137058
void ScriptOp_39C(void)
{
}

// ScriptOp_39F @ 0x0813705C
void ScriptOp_39F(void)
{
    gUnk_03006698 = SCRIPT_READ();
    gUnk_03006914 = gUnk_03006698 | 0x100;
    gUnk_03006674 = gScriptBase;
    gUnk_030069E0 = gScriptPc;
    gUnk_03006600 = 1;
    gScriptBase = gUnknown_0803BAD6;
    gScriptPc = 0;
}

// ScriptOp_3A3 @ 0x081370C0
void ScriptOp_3A3(void)
{
    sub_080C30AC(-gUnk_0203DB2C);
}

// ScriptOp_3A4 @ 0x081370D4
void ScriptOp_3A4(void)
{
    gUnk_0300699C = 0;
    sub_080C30AC(gUnk_0203DB2C);
}

// ScriptOp_3A5 @ 0x081370F0
void ScriptOp_3A5(void)
{
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ();
    u16 i;

    target = target << 16 | lo;
    for (i = 0; i < 0x100 && !sub_080C32D4(i); i++)
        ;
    if (i == 0x100)
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_3A6 @ 0x08137150
void ScriptOp_3A6(void)
{
}

// ScriptOp_3A8 @ 0x08137154
void ScriptOp_3A8(void)
{
}

// ScriptOp_3A9 @ 0x08137158
void ScriptOp_3A9(void)
{
}

// ScriptOp_3AB @ 0x0813715C
void ScriptOp_3AB(void)
{
}

// ScriptOp_3AC @ 0x08137160
void ScriptOp_3AC(void)
{
    gUnk_03006964 = sub_080B8020();
    gScriptWaitState = 0x36;
    gScriptYield = 1;
}

// ScriptOp_3AE @ 0x08137188
void ScriptOp_3AE(void)
{
}

// ScriptOp_3B1 @ 0x0813718C
void ScriptOp_3B1(void)
{
}

// ScriptOp_3B2 @ 0x08137190
void ScriptOp_3B2(void)
{
}

// ScriptOp_3B3 @ 0x08137194
void ScriptOp_3B3(void)
{
}

// ScriptOp_3B6 @ 0x08137198
void ScriptOp_3B6(void)
{
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ();
    u16 n;
    u16 i;

    target = target << 16 | lo;
    n = 0;
    for (i = 0x40; i < 0x50; i++)
    {
        if (sub_080C32D4(i))
            n++;
    }
    if (n)
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_3B9 @ 0x081371F8
void ScriptOp_3B9(void)
{
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ();
    u16 i, n;
    u16 skip;

    target = target << 16 | lo;
    for (n = 0; n < 20; n++)
        gUnk_0203DB88[n] |= 0xFFFF;
    skip = (gUnk_0203DB72 & 0xF) | 0xF0;
    i = 0xF0;
    n = 0;
    for (; i < 0xFD; i++)
    {
        if (Flag_Test(i) && i != skip)
            gUnk_0203DB88[n++] = i + 0xFFA0;
    }
    if (gUnk_0203DB88[0] == 0xFFFF)
        gScriptJumpTarget = (u16 *)target;
    else
        gUnk_03006604 = n - 1;
}

// ScriptOp_3BA @ 0x081372BC
void ScriptOp_3BA(void)
{
}

// ScriptOp_3BB @ 0x081372C0
void ScriptOp_3BB(void)
{
    gScriptPc++;
    gScriptYield = 1;
    gScriptWaitState = 0x3F;
}

// ScriptOp_3BD @ 0x081372E4
void ScriptOp_3BD(void)
{
}

// ScriptOp_3BE @ 0x081372E8
void ScriptOp_3BE(void)
{
}

// ScriptOp_3BF @ 0x081372EC
void ScriptOp_3BF(void)
{
}

// ScriptOp_3C0 @ 0x081372F0
void ScriptOp_3C0(void)
{
    if (!Flag_Test(0x23) || (u8)gUnk_0203DB72 != 0)
        Flag_Set((gUnk_0203DB72 & 0xF) + 0xF0);
}

// ScriptOp_3C2 @ 0x0813731C
void ScriptOp_3C2(void)
{
}

// ScriptOp_3C4 @ 0x08137320
void ScriptOp_3C4(void)
{
}

// ScriptOp_3C5 @ 0x08137324
void ScriptOp_3C5(void)
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
    gUnk_0300668C = 0;
    sub_0812DC24();
    gScriptWaitState = 0x1E;
    gScriptYield = 1;
}

/* Alignment step: x * 0x100, sign-extended from 16 bits. */
// sub_081373C0 @ 0x081373C0
s32 sub_081373C0(u32 x)
{
    x <<= 8;
    if (x > 0x7FFF)
        x |= 0xFFFF0000;
    return x;
}

// ScriptOp_3C7 @ 0x081373E0
void ScriptOp_3C7(void)
{
    s32 a = 0;
    s32 b;
    u16 mode = SCRIPT_READ();

    if (mode == 0)
    {
        gUnk_0203DB34 = a;
        return;
    }
    if (gUnk_0203DB34 == 0)
        return;
    if (mode == 1)
    {
        a = -1;
        b = a;
    }
    else if (mode == 2)
    {
        a = 1;
        b = 1;
    }
    else
    {
        b = (sub_080C0794(0) >> 8 > 0x7F) ? -1 : 1;
        a = (sub_080C0794(1) >> 8 > 0x7F) ? -1 : 1;
    }
    b = sub_081373C0(b);
    a = sub_081373C0(a);
    Combatant_AddAlignment(0, b);
    Combatant_AddAlignment(1, a);
}

// ScriptOp_3C6 @ 0x08137478
void ScriptOp_3C6(void)
{
    u16 kind = SCRIPT_READ();
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ();
    s32 attr;

    target = target << 16 | lo;
    if (kind == 0x65)
    {
        u16 id = sub_080D2268(gUnk_030069A8);
        u32 item;

        if (id == 6)
            return;
        item = Combatant_GetEquip(gUnk_03006898, id) & 0xFF;
        if (item == 0xFF)
            return;
        Item_GetAttribute(item, 6, &attr);
        if (!(attr & 1))
            return;
    }
    else if (gFieldState.facing != kind)
        return;
    gScriptJumpTarget = (u16 *)target;
}

// sub_08137518 @ 0x08137518
void sub_08137518(u16 id, s16 n)
{
    u16 i;

    id += 0x120;
    if (n >= 0)
    {
        for (i = 0; i < n; i++)
            sub_080C3328(id);
    }
    else
    {
        n = -n;
        for (i = 0; i < n; i++)
            sub_080C33AC(id);
    }
}

// sub_0813756C @ 0x0813756C
u8 sub_0813756C(u16 id)
{
    return sub_080C32D4(id + 0x120);
}

// ScriptOp_3CA @ 0x08137584
void ScriptOp_3CA(void)
{
}

// ScriptOp_3CB @ 0x08137588
void ScriptOp_3CB(void)
{
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ() << 16 | lo;

    if ((Moon_GetPhase() & 0xF0) == 0x80)
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_3CC @ 0x081375D0
void ScriptOp_3CC(void)
{
}

// ScriptOp_3CD @ 0x081375D4
#ifdef NONMATCHING
void ScriptOp_3CD(void)
{
    u16 arg = SCRIPT_READ();
    u16 idx;
    u16 *p;

    if (gUnk_0300685C < 0x40)
    {
        u16 f = Demon_GetField(gUnk_0203DB7C, 0xB);
        u32 a = sub_0815B958(f) & 0xFF;
        u32 a2 = a;
        u32 b = sub_0815B970((sub_080C0794(0) & 0xFF00) >> 8) & 0xFF;

        if (b != 1)
        {
            if (b == 0)
            {
                if (a != 2)
                    goto done;
            }
            else if (a2 != 0)
                goto done;
            gUnk_0300685C += 0x40;
        }
    }
done:
    idx = (gUnk_0300685C >> 4) * 2;
    if (arg)
        idx |= 1;
    if (!(idx & 1))
        sub_0815BAC8(gUnk_0203DB7C, 1);
    gScriptBase = gUnknown_08032D7C;
    p = &gUnknown_08032D7C[(u16)(idx * 2)];
    gScriptJumpTarget = (u16 *)(p[1] << 16 | p[0]);
}
#else
NAKED
void ScriptOp_3CD(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    ldr r2, .L08137638\n"
        "    ldrh r0, [r2]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r2]\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r1, .L0813763C\n"
        "    ldr r1, [r1]\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r1\n"
        "    ldrh r7, [r0]\n"
        "    ldr r0, .L08137640\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0x3f\n"
        "    bhi .L08137654\n"
        "    ldr r0, .L08137644\n"
        "    ldrh r0, [r0]\n"
        "    movs r1, #0xb\n"
        "    bl Demon_GetField\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    adds r0, r1, #0\n"
        "    bl sub_0815B958\n"
        "    movs r4, #0xff\n"
        "    adds r5, r4, #0\n"
        "    ands r5, r0\n"
        "    adds r6, r5, #0\n"
        "    movs r0, #0\n"
        "    bl sub_080C0794\n"
        "    movs r2, #0xff\n"
        "    lsls r2, r2, #8\n"
        "    adds r1, r2, #0\n"
        "    ands r0, r1\n"
        "    lsrs r1, r0, #8\n"
        "    adds r0, r1, #0\n"
        "    bl sub_0815B970\n"
        "    adds r1, r4, #0\n"
        "    ands r1, r0\n"
        "    cmp r1, #1\n"
        "    beq .L08137654\n"
        "    cmp r1, #0\n"
        "    bne .L08137648\n"
        "    cmp r5, #2\n"
        "    bne .L08137654\n"
        "    b .L0813764C\n"
        "    .byte 0x00, 0x00\n"
        ".L08137638: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L0813763C: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L08137640: .4byte 0x0300685C @ IWRAM+0x685C\n"
        ".L08137644: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L08137648:\n"
        "    cmp r6, #0\n"
        "    bne .L08137654\n"
        ".L0813764C:\n"
        "    ldr r1, .L08137668\n"
        "    ldrb r0, [r1]\n"
        "    adds r0, #0x40\n"
        "    strb r0, [r1]\n"
        ".L08137654:\n"
        "    ldr r0, .L08137668\n"
        "    ldrb r4, [r0]\n"
        "    lsrs r4, r4, #4\n"
        "    lsls r4, r4, #1\n"
        "    cmp r7, #0\n"
        "    beq .L0813766C\n"
        "    movs r0, #1\n"
        "    orrs r4, r0\n"
        "    b .L0813767C\n"
        "    .byte 0x00, 0x00\n"
        ".L08137668: .4byte 0x0300685C @ IWRAM+0x685C\n"
        ".L0813766C:\n"
        "    movs r0, #0\n"
        "    cmp r0, #0\n"
        "    bne .L0813767C\n"
        "    ldr r0, .L0813769C\n"
        "    ldrh r0, [r0]\n"
        "    movs r1, #1\n"
        "    bl sub_0815BAC8\n"
        ".L0813767C:\n"
        "    lsls r0, r4, #0x11\n"
        "    ldr r1, .L081376A0\n"
        "    ldr r2, .L081376A4\n"
        "    str r2, [r1]\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r2\n"
        "    ldrh r1, [r0]\n"
        "    ldrh r0, [r0, #2]\n"
        "    lsls r0, r0, #0x10\n"
        "    orrs r0, r1\n"
        "    ldr r1, .L081376A8\n"
        "    str r0, [r1]\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L0813769C: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L081376A0: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L081376A4: .4byte gUnknown_08032D7C\n"
        ".L081376A8: .4byte 0x030068E4 @ IWRAM+0x68E4\n"
    );
}
#endif

// sub_081376AC @ 0x081376AC
u16 sub_081376AC(u16 n)
{
    if ((u16)Random_Byte() < n)
        return 1;
    return 0;
}

// ScriptOp_3CE @ 0x081376CC
void ScriptOp_3CE(void)
{
    u16 n = SCRIPT_READ();
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ() << 16 | lo;

    if (sub_081376AC(n))
        gScriptJumpTarget = (u16 *)target;
}

/* Level check against the demon being talked to (gUnk_0203DB7C). */
// sub_08137720 @ 0x08137720
u16 sub_08137720(u16 mode)
{
    s32 level = Combatant_GetLevel(0);
    s32 v;

    switch (mode)
    {
    case 0:
    case 1:
        if (level < (s32)(Demon_GetField(gUnk_0203DB7C, 0) & 0xFF))
            goto yes;
    no:
        return 0;
    case 2:
        v = (u16)Demon_GetField(gUnk_0203DB7C, 0) + (Random_Byte() & 3) + 1;
        break;
    case 3:
        v = (u16)Demon_GetField(gUnk_0203DB7C, 0) + (Random_Byte() & mode) + 6;
        break;
    default:
        v = (u16)Demon_GetField(gUnk_0203DB7C, 0) + (Random_Byte() & 3) - 1;
        break;
    }
    if (level > (v & 0xFF))
        goto no;
yes:
    return 1;
}

// ScriptOp_3CF @ 0x081377D0
void ScriptOp_3CF(void)
{
    u16 n = SCRIPT_READ();
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ() << 16 | lo;

    if (sub_08137720(n))
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_3D0 @ 0x08137824
void ScriptOp_3D0(void)
{
    u16 n = SCRIPT_READ();
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ() << 16 | lo;

    if (Combatant_GetStat(0, 1) <= n)
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_3D1 @ 0x08137878
void ScriptOp_3D1(void)
{
    u16 mode = SCRIPT_READ();
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ();
    u16 v;

    target = target << 16 | lo;
    if (mode == 1)
    {
        v = Random_Byte() & 7;
        if (v)
            v--;
    }
    else if (mode == 2)
        v = (Random_Byte() & 7) + 3;
    else
        v = Random_Byte() & 0xF;
    v &= 0xFF;
    if (v >= Combatant_GetLuck(0))
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_3D2 @ 0x08137908
void ScriptOp_3D2(void)
{
    u16 n = SCRIPT_READ();
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ() << 16 | lo;

    if (Combatant_GetStat(0, 2) <= n)
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_3D3 @ 0x0813795C
void ScriptOp_3D3(void)
{
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ() << 16 | lo;
    u32 sum;
    u16 v;

    sum = Random_Byte() & 7;
    sum += Random_Byte() & 7;
    sum += Random_Byte() & 7;
    v = sum - 1;
    if (v >= Combatant_GetStrength(0))
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_3D4 @ 0x081379C8
void ScriptOp_3D4(void)
{
}

// sub_081379CC @ 0x081379CC
#ifdef NONMATCHING
u16 sub_081379CC(u16 mode)
{
    u16 m = mode;
    s32 x = sub_080EF90C();
    s32 v;

    if (mode == 1)
        v = (Random_Byte() & 3) + 6;
    else if (mode == 2)
        v = (Random_Byte() & 7) + 5;
    else
    {
        if (m == 3)
        {
            v = (Random_Byte() & 7) + 10;
            if (v >= x)
                return 1;
            return 0;
        }
        return; /* returns nothing: r0 still holds x */
    }
    if (v < x)
        return 0;
    return 1;
}
#else
NAKED
u16 sub_081379CC(u16 mode)
{
    asm_unified(
        ".L081379CC:\n"
        "    push {r4, r5, r6, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    adds r6, r4, #0\n"
        "    bl sub_080EF90C\n"
        "    adds r5, r0, #0\n"
        "    cmp r4, #1\n"
        "    bne .L081379EA\n"
        "    bl Random_Byte\n"
        "    movs r1, #3\n"
        "    ands r1, r0\n"
        "    adds r1, #6\n"
        "    b .L081379F8\n"
        ".L081379EA:\n"
        "    cmp r4, #2\n"
        "    bne .L08137A00\n"
        "    bl Random_Byte\n"
        "    movs r1, #7\n"
        "    ands r1, r0\n"
        "    adds r1, #5\n"
        ".L081379F8:\n"
        "    cmp r1, r5\n"
        "    blt .L08137A12\n"
        "    movs r0, #1\n"
        "    b .L08137A18\n"
        ".L08137A00:\n"
        "    cmp r6, #3\n"
        "    bne .L08137A18\n"
        "    bl Random_Byte\n"
        "    movs r1, #7\n"
        "    ands r1, r0\n"
        "    adds r1, #0xa\n"
        "    cmp r1, r5\n"
        "    bge .L08137A16\n"
        ".L08137A12:\n"
        "    movs r0, #0\n"
        "    b .L08137A18\n"
        ".L08137A16:\n"
        "    movs r0, #1\n"
        ".L08137A18:\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// ScriptOp_3D5 @ 0x08137A20
void ScriptOp_3D5(void)
{
    u16 n = SCRIPT_READ();
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ() << 16 | lo;

    if (sub_081379CC(n))
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_3D6 @ 0x08137A74
void ScriptOp_3D6(void)
{
    s32 x = sub_080EF954();
    u16 mode = SCRIPT_READ();
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ();
    s32 v;

    target = target << 16 | lo;
    if (mode == 1)
    {
        v = Random_Byte();
        v &= 3;
        v += 6;
    }
    else if (mode == 2)
    {
        v = Random_Byte();
        v &= 7;
        v += 5;
    }
    else
    {
        v = Random_Byte();
        v &= 7;
        v += 9;
    }
    if (v >= x)
        gScriptJumpTarget = (u16 *)target;
}
