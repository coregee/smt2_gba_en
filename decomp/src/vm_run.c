/* Script VM main loop, message-window glyph queue and per-frame renderer, VM init,
   the pre-scan interpreter (ScriptVM_RunAlt) and demon-record helpers. */

#include "global.h"
#include "vm.h"

// ScriptVM_Run @ 0x0813DB34
void ScriptVM_Run(struct ScriptTask *task)
{
    u16 n;
    u16 i;

    gUnknown_08790FDC[gScriptWaitState](task);
    if (gScriptWaitBusy == 1)
        return;
    gScriptYield = 0;
    for (;;)
    {
        if (gScriptJumpTarget != NULL)
        {
            gScriptBase = gScriptJumpTarget;
            gScriptJumpTarget = NULL;
            gScriptPc = 0;
        }
        gScriptCurOp = gScriptBase[gScriptPc];
        gScriptPc++;
        if ((u16)(gScriptCurOp - 0x300) <= 0x170)
        {
            gScriptOpTable[(u16)(gScriptCurOp - 0x300)](task);
            if (gScriptYield == 1)
                return;
            continue;
        }
        if (gMsgWindowOpen == 0 && gUnk_03006670 == 0)
        {
            if (gUnk_0203DB7A != 0)
                gMsgWindow = Window_Create(1, 12, 28, 7, 0);
            else
                gMsgWindow = Window_Create(2, 11, 26, 8, 0);
            gScriptPc--;
            gMsgWindowOpen = 1;
            gScriptWaitState = 1;
            return;
        }
        n = gMsgGlyphCount;
        i = n * 4;
        gMsgGlyphQueue[i++] = gScriptCurOp;
        gMsgGlyphQueue[i++] = gTextColumn * 13 + 17;
        gMsgGlyphQueue[i++] = gTextLine * 13 + gMsgTextTop;
        gMsgGlyphQueue[i] = 0;
        if ((u16)(gMsgGlyphCount = n + 1) > 0x3F)
            gMsgGlyphCount = 0x3F;
        gTextColumn++;
        if (gUnk_0203DB48 != 1)
            break;
    }
    gScriptWaitState = 15;
    gUnk_0203DB5C = gMsgGlyphDelay;
    if (gHeldKeys & 2)
        gUnk_0203DB48 = 1;
}

// sub_0813DD2C @ 0x0813DD2C
void sub_0813DD2C(struct ScriptTask *task)
{
    if (gUnk_03006670 == 0 && gMsgWindowOpen != 0)
        Window_Close(gMsgWindow, 0);
    task->unk1C = 0;
}

// sub_0813DD64 @ 0x0813DD64
#ifdef NONMATCHING
void sub_0813DD64(struct ScriptTask *task)
{
    if (gUnk_03006670 == 0 && gMsgWindowOpen != 0)
    {
        if (Window_IsIdle(gMsgWindow) == 1)
        {
            gMsgWindowOpen = gUnk_03006670;
            task->unk1C = 1;
        }
    }
    else
    {
        task->unk1C = 1;
    }
}
#else
NAKED
void sub_0813DD64(struct ScriptTask *task)
{
    asm_unified(
        "    push {r4, r5, r6, lr}\n"
        "    adds r4, r0, #0\n"
        "    ldr r0, .L0813DD8C\n"
        "    ldrh r5, [r0]\n"
        "    cmp r5, #0\n"
        "    bne .L0813DD98\n"
        "    ldr r6, .L0813DD90\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r6, r1]\n"
        "    cmp r0, #0\n"
        "    beq .L0813DD98\n"
        "    ldr r0, .L0813DD94\n"
        "    ldr r0, [r0]\n"
        "    bl Window_IsIdle\n"
        "    cmp r0, #1\n"
        "    bne .L0813DD9C\n"
        "    strh r5, [r6]\n"
        "    b .L0813DD9A\n"
        "    .byte 0x00, 0x00\n"
        ".L0813DD8C: .4byte 0x03006670 @ IWRAM+0x6670\n"
        ".L0813DD90: .4byte 0x0203DB6C @ EWRAM+0x3DB6C\n"
        ".L0813DD94: .4byte 0x03006968 @ IWRAM+0x6968\n"
        ".L0813DD98:\n"
        "    movs r0, #1\n"
        ".L0813DD9A:\n"
        "    strh r0, [r4, #0x1c]\n"
        ".L0813DD9C:\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// sub_0813DDA4 @ 0x0813DDA4
void sub_0813DDA4(void)
{
    sub_080AF3FC();
}

// sub_0813DDB0 @ 0x0813DDB0
void sub_0813DDB0(struct ScriptTask *task)
{
    task->unk1C = 0;
}

// sub_0813DDB8 @ 0x0813DDB8
void sub_0813DDB8(struct ScriptTask *task)
{
    task->unk1C = 0;
}

// sub_0813DDC0 @ 0x0813DDC0
void sub_0813DDC0(struct ScriptTask *task)
{
    task->unk1C = 0;
}

// sub_0813DDC8 @ 0x0813DDC8
void sub_0813DDC8(void)
{
    gScriptWaitState = 4;
}

// sub_0813DDD4 @ 0x0813DDD4
void sub_0813DDD4(struct ScriptTask *task)
{
    task->unk1C = 0;
}

// sub_0813DDDC @ 0x0813DDDC
void sub_0813DDDC(struct ScriptTask *task)
{
    if (gUnk_0203DB4A == 0)
        task->unk1C = 1;
    else
        gUnk_0203DB4A--;
}

// ScriptVM_ClearPage @ 0x0813DE04
void ScriptVM_ClearPage(void)
{
    gMsgGlyphCount = 0;
    gTextColumn = 0;
    gTextLine = 0;
    gScriptWaitState = 6;
    Font_ResetGlyphSpriteCache(0x180);
    gUnk_0203DB48 = ScriptVM_GetTextSpeed();
}

// ScriptTask_WaitForKey @ 0x0813DE44
void ScriptTask_WaitForKey(struct ScriptTask *task)
{
    if ((gNewKeys & 1) || (gNewKeys & 0x40) || (gNewKeys & 0x80) || (gNewKeys & 0x10)
        || (gNewKeys & 0x20) || (gNewKeys & 2))
    {
        sub_080C51D4(0x65);
        task->unk1C = 1;
    }
}

// ScriptVM_ScrollGlyphsUp @ 0x0813DE9C
void ScriptVM_ScrollGlyphsUp(void)
{
    s16 i;

    for (i = 0; i < gMsgGlyphCount; i++)
        gMsgGlyphQueue[i * 4 + 2] -= 13;
}

// ScriptVM_DrawTask @ 0x0813DED8
void ScriptVM_DrawTask(struct ScriptTask *task)
{
    s16 i;

    if (gMsgGlyphCount != 0)
    {
        for (i = 0; i < gMsgGlyphCount; i++)
        {
            s32 j = i * 4;
            u16 y = gMsgGlyphQueue[j + 2];

            if (y >= gMsgTextTop)
                FontSprite_DrawGlyphTinted(gMsgGlyphQueue[i * 4], 0, 0, gMsgGlyphQueue[j + 1], y,
                                           gMsgGlyphQueue[j + 3]);
        }
    }
    if (gUnk_0300699C != 0)
    {
        for (i = 0; i < gMsgGlyphList2Count; i++)
        {
            s32 j = i * 4;

            FontSprite_DrawGlyphTinted(gMsgGlyphList2[i * 4], 0, 0, gMsgGlyphList2[j + 1],
                                       gMsgGlyphList2[j + 2], gMsgGlyphList2[j + 3]);
        }
    }
    for (i = 0; i < 5; i++)
    {
        if (gUnk_03006620[i].active)
            Sprite_DrawNumber8(gUnk_03006620[i].handle, gUnk_03006620[i].a, gUnk_03006620[i].b,
                         gUnk_03006620[i].c);
    }
    if (gUnk_030069D0 == 1)
    {
        sub_080C6B40(gUnk_030069D8[0], 0, 0, 0x17, 0x66);
    }
    else if (gUnk_030069D0 == 2)
    {
        sub_080C6B40(gUnk_030069D8[0], 0, 0, 0x17, 0x66);
        sub_080C6B40(gUnk_030069D8[1], 0, 0, 0x17, 0x74);
    }
    else if (gUnk_030069D0 == 3)
    {
        sub_080C6B40(gUnk_030069D8[0], 0, 0, 0x17, 0x66);
        sub_080C6B40(gUnk_030069D8[1], 0, 0, 0x17, 0x74);
        sub_080C6B40(gUnk_030069D8[2], 0, 0, 0x17, 0x83);
    }
    if (gUnk_03006920[0].active)
        sub_080D3170(gUnk_03006920[0].a, 0x12, 0x66, gUnk_03006920[0].b);
    if (gUnk_03006920[1].active)
        sub_080D3170(gUnk_03006920[1].a, 0x12, 0x74, gUnk_03006920[1].b);
    if (gUnk_03006920[2].active)
        sub_080D3170(gUnk_03006920[2].a, 0x12, 0x83, gUnk_03006920[2].b);
    if (gUnk_03006958)
        sub_080C49EC(gUnk_030066A0, 4, 0, gUnk_0300689C, gUnk_0300695C);
    if (gUnk_03006678[0])
        sub_080C49EC(0x13, 4, 0, 0x1F, gUnk_03006678[1]);
    if (gUnk_0203DB46 == 1)
        task->unk1C = 1;
    if (gUnk_0203DB52)
    {
        if (gUnk_0203DB7A)
            sub_080C4AB0(0, 0, 0xD5, 0x8D);
        else
            sub_080C4AB0(0, 0, 0xD5, 0x8D);
    }
    if (gUnk_03006848)
        sub_080C4A4C(0, 0, gUnknown_087923DC[(gUnk_03006848 << 1)], gUnknown_087923DC[(gUnk_03006848 << 1) + 1]);
    if (gUnk_03006680)
        sub_080C4AB0(0, 0, gUnknown_087923FC[(gUnk_03006680 << 1)], gUnknown_087923FC[(gUnk_03006680 << 1) + 1]);
}

// ScriptVM_Init @ 0x0813E184
void ScriptVM_Init(u16 *script, u16 battle)
{
    u16 i;

    gUnk_0203DB86 = gUnk_030069CC = gUnk_030065F0 = 0;
    gMsgGlyphDelay = 2;
    if (gUnk_0203DB7A == 1)
        gMsgTextTop = 0x61;
    else if (gUnk_0203DB7A == 2)
        gMsgTextTop = 0x69;
    else
        gMsgTextTop = 0x59;
    gUnk_030069D0 = 0;
    sub_0813EB6C(1);
    gUnk_03006670 = battle;
    gUnk_03006914 = 0xFF;
    gUnk_030068AC = 0;
    gUnk_03006958 = 0;
    gUnk_030065E4 = 0;
    gUnk_0203DB2C = 0;
    gUnk_03006678[0] = gUnk_03006678[2] = gUnk_030068A0 = 0;
    gUnk_0300693C = 0;
    gScriptWaitState = 0;
    gMsgGlyphList2Count = 0;
    gUnk_0300699C = 0;
    gScriptBase = script;
    gScriptJumpTarget = NULL;
    gUnk_030065FC = 0;
    for (i = 0; i < 5; i++)
        gUnk_03006620[i].active = 0;
    for (i = 0; i < 3; i++)
        gUnk_03006920[i].active = 0;
    gUnk_0203DB52 = 0;
    gUnk_0203DB56 = 0;
    gUnk_030069C0[0] = 0;
    gUnk_030069C0[1] = 0;
    gUnk_030068F0[0] = 0;
    gUnk_030068F0[1] = 0;
    gUnk_030068F0[2] = 0;
    gUnk_030068F0[3] = 0;
    gUnk_030068F0[4] = 0;
    gUnk_030068F0[5] = 0;
    gUnk_030068F0[6] = 0;
    gUnk_030068F0[7] = 0;
    gUnk_0203DB66 = 0;
    gUnk_0203DB68 = 0;
    gUnk_0203DB64 = 0;
    gUnk_030068C4 = NULL;
    gUnk_03006818 = 0;
    gUnk_03006600 = 0;
    gUnk_030065EC = 0;
    gUnk_030068D0 = NULL;
    gUnk_03006610 = 0;
    gUnk_03006910 = 0;
    gUnk_0203DB48 = ScriptVM_GetTextSpeed();
    gUnk_0203DB4A = 0;
    gMsgGlyphCount = 0;
    gTextColumn = 0;
    gTextLine = 0;
    gScriptCurOp = 0;
    gScriptPc = 0;
    gUnk_0203DB46 = 0;
    gMsgWindowOpen = 0;
    gMsgWindow = 0;
    gUnk_030068B0 = NULL;
    gUnk_030068A4 = 0;
    gUnk_030065F4 = Task_Create(gUnknown_08790024, 0xFFFF);
    Task_Create(gUnknown_0878FB48, 0xFFFF);
    gUnk_030069E4 = Task_Create(gUnknown_0878FB84, 0xFFFF);
    gUnk_03006848 = 0;
    gUnk_03006680 = 0;
    gScriptSubstBuf[8] = 0x318;
}

// ScriptVM_GetTextSpeed @ 0x0813E408
u16 ScriptVM_GetTextSpeed(void)
{
    u32 speed;

    if (gUnk_03006670 == 1)
        speed = Settings_GetBattleMsgSpeed();
    else
        speed = sub_080C2AFC();
    return speed;
}

// ScriptVM_RunAlt @ 0x0813E428
u32 ScriptVM_RunAlt(u16 *script)
{
    struct ScriptTask *task = gUnk_030068B0;

    gUnk_030065F0 = 1;
    gUnk_0203DB76 = gUnk_0203DB72;
    gUnk_0203DB78 = gUnk_0203DB74;
    gUnk_030068C0 = gScriptBase;
    gUnk_030068DC = gScriptPc;
    gScriptBase = script;
    gScriptJumpTarget = NULL;
    gScriptPc = 0;
    gUnk_0203DB5E = 0;
    gUnk_0203DB60 = 0;
    gScriptYield = 0;
    ScriptVM_SaveFlags();
    while (1)
    {
        if (gScriptJumpTarget != NULL)
        {
            gScriptBase = gScriptJumpTarget;
            gScriptJumpTarget = NULL;
            gScriptPc = 0;
        }
        gScriptCurOp = gScriptBase[gScriptPc];
        gScriptPc++;
        if ((u16)(gScriptCurOp - 0x300) > 0x170)
            break;
        gScriptOpAltTable[(u16)(gScriptCurOp - 0x300)](task);
        if (gUnk_0203DB5E == 1)
        {
            if (gUnk_0203DB60 == 1)
            {
                ScriptVM_RestoreState();
                return 1;
            }
            break;
        }
        if (gUnk_0203DB5E == 2)
        {
            ScriptVM_RestoreState();
            return 0;
        }
        if (gScriptYield == 1)
            break;
    }
    ScriptVM_RestoreState();
    return 2;
}

// ScriptVM_SaveFlags @ 0x0813E544
void ScriptVM_SaveFlags(void)
{
    u16 i;

    for (i = 0; i < 0x168; i++)
        gScriptFlagsBackup[i] = gUnk_03005CA8[i];
}

// ScriptVM_RestoreState @ 0x0813E574
#ifdef NONMATCHING
void ScriptVM_RestoreState(void)
{
    u16 i;

    for (i = 0; i < 0x168; i++)
        gUnk_03005CA8[i] = gScriptFlagsBackup[i];
    gScriptBase = gUnk_030068C0;
    gScriptPc = gUnk_030068DC;
    gUnk_0203DB72 = gUnk_0203DB76;
    gUnk_0203DB74 = gUnk_0203DB78;
    gUnk_030065F0 = 0;
}
#else
NAKED
void ScriptVM_RestoreState(void)
{
    asm_unified(
        ".L0813E574:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    movs r2, #0\n"
        "    ldr r0, .L0813E5DC\n"
        "    mov r8, r0\n"
        "    ldr r1, .L0813E5E0\n"
        "    mov sb, r1\n"
        "    ldr r6, .L0813E5E4\n"
        "    ldr r0, .L0813E5E8\n"
        "    mov sl, r0\n"
        "    ldr r7, .L0813E5EC\n"
        "    ldr r1, .L0813E5F0\n"
        "    mov ip, r1\n"
        "    ldr r5, .L0813E5F4\n"
        "    ldr r4, .L0813E5F8\n"
        "    ldr r3, .L0813E5FC\n"
        ".L0813E59A:\n"
        "    adds r1, r2, r5\n"
        "    adds r0, r2, r4\n"
        "    ldrb r0, [r0]\n"
        "    strb r0, [r1]\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, r3\n"
        "    bls .L0813E59A\n"
        "    mov r1, r8\n"
        "    ldr r0, [r1]\n"
        "    ldr r1, .L0813E600\n"
        "    str r0, [r1]\n"
        "    ldrh r0, [r6]\n"
        "    mov r1, sb\n"
        "    strh r0, [r1]\n"
        "    ldrh r0, [r7]\n"
        "    mov r1, sl\n"
        "    strh r0, [r1]\n"
        "    mov r1, ip\n"
        "    ldrh r0, [r1]\n"
        "    ldr r1, .L0813E604\n"
        "    strh r0, [r1]\n"
        "    movs r0, #0\n"
        "    ldr r1, .L0813E608\n"
        "    strh r0, [r1]\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L0813E5DC: .4byte 0x030068C0 @ IWRAM+0x68C0\n"
        ".L0813E5E0: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L0813E5E4: .4byte 0x030068DC @ IWRAM+0x68DC\n"
        ".L0813E5E8: .4byte 0x0203DB72 @ EWRAM+0x3DB72\n"
        ".L0813E5EC: .4byte 0x0203DB76 @ EWRAM+0x3DB76\n"
        ".L0813E5F0: .4byte 0x0203DB78 @ EWRAM+0x3DB78\n"
        ".L0813E5F4: .4byte 0x03005CA8 @ IWRAM+0x5CA8\n"
        ".L0813E5F8: .4byte 0x030066B0 @ IWRAM+0x66B0\n"
        ".L0813E5FC: .4byte 0x00000167\n"
        ".L0813E600: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L0813E604: .4byte 0x0203DB74 @ EWRAM+0x3DB74\n"
        ".L0813E608: .4byte 0x030065F0 @ IWRAM+0x65F0\n"
    );
}
#endif

// Demon_GetField @ 0x0813E60C
u16 Demon_GetField(u16 id, u16 field)
{
    u16 v = 0;

    switch (field)
    {
    case 0:
        v = sub_080BF648(id)[1];
        break;
    case 1:
    case 2:
        v = *(u16 *)(sub_080BF648(id) + 2);
        break;
    case 3:
    case 4:
        v = *(u16 *)(sub_080BF648(id) + 4);
        break;
    case 5:
        v = (s8)sub_080BF648(id)[6];
        break;
    case 6:
        v = (s8)sub_080BF648(id)[7];
        break;
    case 7:
        v = (s8)sub_080BF648(id)[8];
        break;
    case 8:
        v = (s8)sub_080BF648(id)[9];
        break;
    case 9:
        v = (s8)sub_080BF648(id)[10];
        break;
    case 10:
        v = (s8)sub_080BF648(id)[11];
        break;
    case 11:
        v = sub_080BF648(id)[12];
        break;
    case 12:
        v = sub_080BF648(id)[13];
        break;
    case 13:
        v = (s8)sub_080BF648(id)[14];
        break;
    case 14:
        v = (s8)sub_080BF648(id)[15];
        break;
    case 15:
        v = (s8)sub_080BF648(id)[16];
        break;
    case 16:
        v = sub_080BF648(id)[17];
        break;
    case 17:
        v = sub_080BF648(id)[18];
        break;
    case 18:
        v = sub_080BF648(id)[19];
        break;
    case 19:
        v = sub_080BF648(id)[20];
        break;
    case 20:
        v = sub_080BF648(id)[21];
        break;
    case 21:
        v = sub_080BF648(id)[22];
        break;
    case 22:
        v = sub_080BF648(id)[23];
        break;
    case 23:
        v = sub_080BF648(id)[24];
        break;
    case 24:
        v = sub_080BF648(id)[25];
        break;
    case 25:
        v = *(u16 *)(sub_080BF648(id) + 26);
        break;
    case 26:
        v = sub_080BF648(id)[28];
        break;
    case 27:
        v = sub_080BF648(id)[29];
        break;
    case 28:
        v = sub_080BF648(id)[30];
        break;
    case 29:
        v = sub_080BF648(id)[31];
        break;
    case 30:
        v = sub_080BF648(id)[32];
        break;
    case 31:
        v = sub_080BF648(id)[33];
        break;
    }
    return v;
}

// sub_0813E804 @ 0x0813E804
u16 sub_0813E804(u16 id)
{
    u32 count = 0;
    s32 n = sub_080C104C();
    u16 i;

    for (i = 4; i < n + 4; i++)
    {
        if (sub_080C09B0(i) != 0 && sub_080C07E0(i) == id)
            count++;
    }
    if (sub_08134C3C(id) != 0)
        count++;
    return count;
}

// sub_0813E854 @ 0x0813E854
#ifdef NONMATCHING
u16 sub_0813E854(u16 id)
{
    u32 lo = id & 0xFF;
    u16 v;

    if (lo < 0x54)
        goto call;
    if (lo > 0xB1)
        goto call;
    v = gGameState.unk1074[(u16)(lo - 0x54)];
    gUnk_03006860 = 0;
    return v;
call:
    v = Demon_GetField(id, 0x1E);
    gUnk_03006860 = 1;
    return v;
}
#else
NAKED
u16 sub_0813E854(u16 id)
{
    asm_unified(
        ".L0813E854:\n"
        "    push {lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    movs r2, #0xff\n"
        "    ands r2, r0\n"
        "    cmp r2, #0x53\n"
        "    bls .L0813E88C\n"
        "    cmp r2, #0xb1\n"
        "    bhi .L0813E88C\n"
        "    adds r0, r2, #0\n"
        "    subs r0, #0x54\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    ldr r1, .L0813E880\n"
        "    ldr r2, .L0813E884\n"
        "    adds r1, r1, r2\n"
        "    adds r0, r0, r1\n"
        "    ldrb r2, [r0]\n"
        "    ldr r1, .L0813E888\n"
        "    movs r0, #0\n"
        "    b .L0813E89A\n"
        "    .byte 0x00, 0x00\n"
        ".L0813E880: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L0813E884: .4byte 0x00001074\n"
        ".L0813E888: .4byte 0x03006860 @ IWRAM+0x6860\n"
        ".L0813E88C:\n"
        "    movs r1, #0x1e\n"
        "    bl Demon_GetField\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    ldr r1, .L0813E8A4\n"
        "    movs r0, #1\n"
        ".L0813E89A:\n"
        "    strh r0, [r1]\n"
        "    adds r0, r2, #0\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L0813E8A4: .4byte 0x03006860 @ IWRAM+0x6860\n"
    );
}
#endif

// sub_0813E8A8 @ 0x0813E8A8
u16 sub_0813E8A8(void)
{
    u16 a;
    u16 b;

    if ((sub_080C1D9C() & 0xF0) != 0x80)
    {
        a = sub_0813E854(gUnk_0203DB7C);
        if (gUnk_03006860 == 0)
        {
            b = sub_0813E854(gUnk_0203DB7E);
            if (gUnk_03006860 == 0 && b < a && sub_0813E804(gUnk_0203DB7E) == 0)
                return 1;
        }
    }
    return 0;
}

// sub_0813E908 @ 0x0813E908
void sub_0813E908(u16 a, u16 b)
{
    gUnk_0203DB28[0] = a;
    gUnk_0203DB28[1] = b;
}

// sub_0813E914 @ 0x0813E914
#ifdef NONMATCHING
void sub_0813E914(void)
{
    u8 bonus;
    u32 v;
    u16 t;
    u16 diff;
    u16 *script;
    u32 idx;
    u16 lo;
    u32 target;

    gUnk_0203DB7A = 0;
    gUnk_0300684C &= 3;
    bonus = 0;
    v = Demon_GetField(gUnk_0203DB7C, 11) & 0xFF;
    if (v < 0x70)
    {
        v = (u16)sub_080C0794(0) >> 8;
        if (v < 0x70)
            bonus = 4;
    }
    else if (v >= 0x90)
    {
        v = (u16)sub_080C0794(0) >> 8;
        if (v >= 0x90)
            bonus = 4;
    }
    diff = gUnk_0203DB7C - 0x54;
    if (diff > 0x5D)
        v = Demon_GetField(gUnk_0203DB7C, 0x1E) & 0xFF;
    else if (gUnk_0203DB7C <= 0xB1)
        v = gGameState.unk1074[diff];
    v >>= 3;
    gUnk_030068B4 = v + bonus;
    sub_080EF930(gUnk_030068B4);
    t = sub_080C0F8C(0);
    v = (((u16)(t - Demon_GetField(gUnk_0203DB7C, 0)) >> 1) + 8) & 0xFF;
    if (v & 0x80)
        gUnk_030069E8 = 0;
    else if (v > 0x1F)
        gUnk_030069E8 = 0x1F;
    else
        gUnk_030069E8 = v;
    sub_080EF978(gUnk_030069E8);
    gUnk_0300685C.raw = Demon_GetField(gUnk_0203DB7C, 0x1F);
    sub_080C0818(0);
    if (sub_0813E804(gUnk_0203DB7C) != 0)
    {
        sub_0815BAC8(gUnk_0203DB7C, 3);
        script = gUnknown_08084020;
    }
    else
    {
        if (gUnk_0203DB7E != 0xFFFF && sub_0813E8A8() != 0)
        {
            u16 tmp = gUnk_0203DB7E;
            u16 w;

            gUnk_0203DB7E = gUnk_0203DB7C;
            gUnk_0203DB7C = tmp;
            w = Demon_GetField(gUnk_0203DB7C, 0x1F);
            gUnk_0300685C.raw = w;
            idx = gUnk_0300685C.bits.hi;
            gScriptBase = gUnknown_08032C78;
            lo = gScriptBase[idx * 2];
            target = gScriptBase[idx * 2 + 1];
            target = target << 16 | lo;
            ScriptVM_Init((u16 *)target, 1);
            gUnk_0203DB70 = 0xFFFF;
            goto done;
        }
        if ((sub_080C1D9C() & 0xF0) == 0x80)
        {
            idx = gUnk_0300685C.bits.hi;
            gScriptBase = gUnknown_08032D4C;
            lo = gScriptBase[idx * 2];
            target = gScriptBase[idx * 2 + 1];
            target = target << 16 | lo;
            script = (u16 *)target;
        }
        else if (Demon_GetField(gUnk_0203DB7C, 0) > (s16)sub_080C0F8C(0))
        {
            idx = gUnk_0300685C.bits.hi;
            gScriptBase = gUnknown_08032CA8;
            lo = gScriptBase[idx * 2];
            target = gScriptBase[idx * 2 + 1];
            target = target << 16 | lo;
            script = (u16 *)target;
        }
        else
        {
            script = gUnknown_08084020;
        }
    }
    ScriptVM_Init(script, 1);
    gUnk_0203DB70 = 0xFFFF;
done:
    gUnk_03004530 = 10;
}
#else
NAKED
void sub_0813E914(void)
{
    asm_unified(
        ".L0813E914:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    ldr r1, .L0813E950\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r2, .L0813E954\n"
        "    ldrb r1, [r2]\n"
        "    movs r0, #3\n"
        "    ands r0, r1\n"
        "    strb r0, [r2]\n"
        "    movs r4, #0\n"
        "    ldr r0, .L0813E958\n"
        "    ldrh r0, [r0]\n"
        "    movs r1, #0xb\n"
        "    bl Demon_GetField\n"
        "    movs r6, #0xff\n"
        "    ands r6, r0\n"
        "    cmp r6, #0x6f\n"
        "    bhi .L0813E95C\n"
        "    movs r0, #0\n"
        "    bl sub_080C0794\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x18\n"
        "    cmp r6, #0x6f\n"
        "    bhi .L0813E970\n"
        "    b .L0813E96E\n"
        "    .byte 0x00, 0x00\n"
        ".L0813E950: .4byte 0x0203DB7A @ EWRAM+0x3DB7A\n"
        ".L0813E954: .4byte 0x0300684C @ IWRAM+0x684C\n"
        ".L0813E958: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813E95C:\n"
        "    cmp r6, #0x8f\n"
        "    bls .L0813E970\n"
        "    movs r0, #0\n"
        "    bl sub_080C0794\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x18\n"
        "    cmp r6, #0x8f\n"
        "    bls .L0813E970\n"
        ".L0813E96E:\n"
        "    movs r4, #4\n"
        ".L0813E970:\n"
        "    ldr r3, .L0813E990\n"
        "    ldrh r1, [r3]\n"
        "    adds r0, r1, #0\n"
        "    subs r0, #0x54\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #0x5d\n"
        "    bls .L0813E994\n"
        "    ldrh r0, [r3]\n"
        "    movs r1, #0x1e\n"
        "    bl Demon_GetField\n"
        "    movs r6, #0xff\n"
        "    ands r6, r0\n"
        "    b .L0813E9A6\n"
        "    .byte 0x00, 0x00\n"
        ".L0813E990: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813E994:\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #0xb1\n"
        "    bhi .L0813E9A6\n"
        "    ldr r0, .L0813E9E4\n"
        "    ldr r1, .L0813E9E8\n"
        "    adds r0, r0, r1\n"
        "    adds r0, r2, r0\n"
        "    ldrb r6, [r0]\n"
        ".L0813E9A6:\n"
        "    lsrs r6, r6, #3\n"
        "    ldr r1, .L0813E9EC\n"
        "    adds r0, r6, r4\n"
        "    strb r0, [r1]\n"
        "    ldrb r0, [r1]\n"
        "    bl sub_080EF930\n"
        "    ldr r4, .L0813E9F0\n"
        "    movs r5, #0xff\n"
        "    movs r0, #0\n"
        "    bl sub_080C0F8C\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldrh r0, [r4]\n"
        "    movs r1, #0\n"
        "    bl Demon_GetField\n"
        "    subs r0, r6, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x11\n"
        "    adds r6, #8\n"
        "    ands r6, r5\n"
        "    movs r0, #0x80\n"
        "    ands r0, r6\n"
        "    cmp r0, #0\n"
        "    beq .L0813E9F8\n"
        "    ldr r1, .L0813E9F4\n"
        "    movs r0, #0\n"
        "    b .L0813EA00\n"
        "    .byte 0x00, 0x00\n"
        ".L0813E9E4: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L0813E9E8: .4byte 0x00001074\n"
        ".L0813E9EC: .4byte 0x030068B4 @ IWRAM+0x68B4\n"
        ".L0813E9F0: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813E9F4: .4byte 0x030069E8 @ IWRAM+0x69E8\n"
        ".L0813E9F8:\n"
        "    cmp r6, #0x1f\n"
        "    bls .L0813EA0C\n"
        "    ldr r1, .L0813EA08\n"
        "    movs r0, #0x1f\n"
        ".L0813EA00:\n"
        "    strb r0, [r1]\n"
        "    adds r0, r1, #0\n"
        "    b .L0813EA10\n"
        "    .byte 0x00, 0x00\n"
        ".L0813EA08: .4byte 0x030069E8 @ IWRAM+0x69E8\n"
        ".L0813EA0C:\n"
        "    ldr r0, .L0813EA44\n"
        "    strb r6, [r0]\n"
        ".L0813EA10:\n"
        "    ldrb r0, [r0]\n"
        "    bl sub_080EF978\n"
        "    ldr r5, .L0813EA48\n"
        "    ldrh r0, [r5]\n"
        "    ldr r2, .L0813EA4C\n"
        "    mov r8, r2\n"
        "    movs r1, #0x1f\n"
        "    bl Demon_GetField\n"
        "    mov r1, r8\n"
        "    strb r0, [r1]\n"
        "    movs r0, #0\n"
        "    bl sub_080C0818\n"
        "    ldrh r0, [r5]\n"
        "    bl sub_0813E804\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L0813EA50\n"
        "    ldrh r0, [r5]\n"
        "    movs r1, #3\n"
        "    bl sub_0815BAC8\n"
        "    b .L0813EB30\n"
        ".L0813EA44: .4byte 0x030069E8 @ IWRAM+0x69E8\n"
        ".L0813EA48: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813EA4C: .4byte 0x0300685C @ IWRAM+0x685C\n"
        ".L0813EA50:\n"
        "    ldr r4, .L0813EAA0\n"
        "    ldrh r0, [r4]\n"
        "    ldr r7, .L0813EAA4\n"
        "    cmp r0, r7\n"
        "    beq .L0813EAB4\n"
        "    bl sub_0813E8A8\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L0813EAB4\n"
        "    ldrh r2, [r4]\n"
        "    ldrh r0, [r5]\n"
        "    strh r0, [r4]\n"
        "    strh r2, [r5]\n"
        "    ldrh r0, [r5]\n"
        "    movs r1, #0x1f\n"
        "    bl Demon_GetField\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    mov r2, r8\n"
        "    strb r6, [r2]\n"
        "    lsls r0, r6, #0x18\n"
        "    lsrs r2, r0, #0x1c\n"
        "    ldr r0, .L0813EAA8\n"
        "    ldr r1, .L0813EAAC\n"
        "    str r1, [r0]\n"
        "    lsls r0, r2, #2\n"
        "    adds r0, r0, r1\n"
        "    ldrh r1, [r0]\n"
        "    ldrh r0, [r0, #2]\n"
        "    lsls r0, r0, #0x10\n"
        "    orrs r0, r1\n"
        "    movs r1, #1\n"
        "    bl ScriptVM_Init\n"
        "    ldr r0, .L0813EAB0\n"
        "    strh r7, [r0]\n"
        "    b .L0813EB40\n"
        "    .byte 0x00, 0x00\n"
        ".L0813EAA0: .4byte 0x0203DB7E @ EWRAM+0x3DB7E\n"
        ".L0813EAA4: .4byte 0x0000FFFF\n"
        ".L0813EAA8: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L0813EAAC: .4byte gUnknown_08032C78\n"
        ".L0813EAB0: .4byte 0x0203DB70 @ EWRAM+0x3DB70\n"
        ".L0813EAB4:\n"
        "    bl sub_080C1D9C\n"
        "    movs r1, #0xf0\n"
        "    ands r1, r0\n"
        "    cmp r1, #0x80\n"
        "    bne .L0813EAE8\n"
        "    ldr r1, .L0813EADC\n"
        "    ldrb r0, [r1]\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r2, r0, #0x1c\n"
        "    ldr r0, .L0813EAE0\n"
        "    ldr r1, .L0813EAE4\n"
        "    str r1, [r0]\n"
        "    lsls r0, r2, #2\n"
        "    adds r0, r0, r1\n"
        "    ldrh r1, [r0]\n"
        "    ldrh r0, [r0, #2]\n"
        "    lsls r0, r0, #0x10\n"
        "    orrs r0, r1\n"
        "    b .L0813EB32\n"
        ".L0813EADC: .4byte 0x0300685C @ IWRAM+0x685C\n"
        ".L0813EAE0: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L0813EAE4: .4byte gUnknown_08032D4C\n"
        ".L0813EAE8:\n"
        "    ldr r0, .L0813EB20\n"
        "    ldrh r0, [r0]\n"
        "    movs r1, #0\n"
        "    bl Demon_GetField\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    movs r0, #0\n"
        "    bl sub_080C0F8C\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r6, r0\n"
        "    ble .L0813EB30\n"
        "    ldr r1, .L0813EB24\n"
        "    ldrb r0, [r1]\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r2, r0, #0x1c\n"
        "    ldr r0, .L0813EB28\n"
        "    ldr r1, .L0813EB2C\n"
        "    str r1, [r0]\n"
        "    lsls r0, r2, #2\n"
        "    adds r0, r0, r1\n"
        "    ldrh r1, [r0]\n"
        "    ldrh r0, [r0, #2]\n"
        "    lsls r0, r0, #0x10\n"
        "    orrs r0, r1\n"
        "    b .L0813EB32\n"
        ".L0813EB20: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813EB24: .4byte 0x0300685C @ IWRAM+0x685C\n"
        ".L0813EB28: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L0813EB2C: .4byte gUnknown_08032CA8\n"
        ".L0813EB30:\n"
        "    ldr r0, .L0813EB50\n"
        ".L0813EB32:\n"
        "    movs r1, #1\n"
        "    bl ScriptVM_Init\n"
        "    ldr r1, .L0813EB54\n"
        "    ldr r2, .L0813EB58\n"
        "    adds r0, r2, #0\n"
        "    strh r0, [r1]\n"
        ".L0813EB40:\n"
        "    ldr r1, .L0813EB5C\n"
        "    movs r0, #0xa\n"
        "    str r0, [r1]\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L0813EB50: .4byte gUnknown_08084020\n"
        ".L0813EB54: .4byte 0x0203DB70 @ EWRAM+0x3DB70\n"
        ".L0813EB58: .4byte 0x0000FFFF\n"
        ".L0813EB5C: .4byte 0x03004530 @ IWRAM+0x4530\n"
    );
}
#endif

// sub_0813EB60 @ 0x0813EB60
u16 sub_0813EB60(void)
{
    return gUnk_0203DB70;
}

// sub_0813EB6C @ 0x0813EB6C
void sub_0813EB6C(u16 a)
{
    gUnk_0203DB6A = a;
}

// sub_0813EB78 @ 0x0813EB78
u16 sub_0813EB78(void)
{
    return gUnk_0203DB6A;
}

// sub_0813EB84 @ 0x0813EB84
void sub_0813EB84(u16 a, u16 b)
{
    u32 *p;

    gUnk_0203DB7C = a;
    gUnk_0203DB7E = b;
    gUnk_0300684C = 0;
    p = gUnk_0203DB30;
    *p = sub_080EDA24(1);
}
