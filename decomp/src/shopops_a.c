/* Script VM opcode handlers 0x33B-0x35F: shop lists, choices, alignment and party checks. */

#include "global.h"
#include "scriptops3.h"

// sub_08134250 @ 0x08134250
#ifdef NONMATCHING
void sub_08134250(u16 first)
{
    u16 i, j, id;
    u16 pal;
    u16 *name;
    u32 price;

    pal = 0;
    gMsgGlyphList2Count = pal;
    gUnk_0300699C = 1;
    if (first == 0)
    {
        gUnk_03006848 = pal;
        gUnk_03006680 = 1;
    }
    else if (first == 9)
    {
        gUnk_03006848 = 1;
        gUnk_03006680 = 0;
    }
    else
    {
        gUnk_03006848 = 1;
        gUnk_03006680 = 1;
    }
    for (i = 0; i < 100; i++)
        gMsgGlyphList2[i] = 0;
    i = first;
    if (i >= first + 3)
        return;
    goto check;
    do
    {
        price = gShopItemPrices[i];
        pal = 4;
        if (price != 0)
            pal = 0;
        name = (u16 *)(Action_GetRecord(id) + 0xC);
        for (j = 0; j < 16; j++)
            gScriptSubstBuf[j] = 0;
        for (j = 0; j < 8; j++)
            gScriptSubstBuf[j] = *name++;
        sub_08133724(0x27, gUnknown_0879038A[i - first], pal, 8);
        gUnk_03006620[i - first].unk0 = 1;
        gUnk_03006624[(i - first) * 4] = gShopItemPrices[i];
        gUnk_03006620[i - first].unk8 = 0x80;
        gUnk_03006620[i - first].y = gUnknown_0878FC64[i - first];
        gUnk_03006620[i - first].palette = pal;
        i++;
        if (i >= first + 3)
            return;
    check:
        id = gShopItemIds[i];
    } while (id != 0xFFFF);
}
#else
NAKED
void sub_08134250(u16 first)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #4\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        "    movs r7, #0\n"
        "    ldr r0, .L0813427C\n"
        "    strh r7, [r0]\n"
        "    ldr r0, .L08134280\n"
        "    movs r1, #1\n"
        "    strh r1, [r0]\n"
        "    mov r0, r8\n"
        "    cmp r0, #0\n"
        "    bne .L08134288\n"
        "    ldr r0, .L08134284\n"
        "    strh r7, [r0]\n"
        "    b .L081342A4\n"
        "    .byte 0x00, 0x00\n"
        ".L0813427C: .4byte 0x0300669C @ IWRAM+0x669C\n"
        ".L08134280: .4byte 0x0300699C @ IWRAM+0x699C\n"
        ".L08134284: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L08134288:\n"
        "    mov r3, r8\n"
        "    cmp r3, #9\n"
        "    bne .L081342A0\n"
        "    ldr r0, .L08134298\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L0813429C\n"
        "    strh r7, [r0]\n"
        "    b .L081342A8\n"
        ".L08134298: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L0813429C: .4byte 0x03006680 @ IWRAM+0x6680\n"
        ".L081342A0:\n"
        "    ldr r0, .L081342C8\n"
        "    strh r1, [r0]\n"
        ".L081342A4:\n"
        "    ldr r0, .L081342CC\n"
        "    strh r1, [r0]\n"
        ".L081342A8:\n"
        "    movs r4, #0\n"
        "    ldr r2, .L081342D0\n"
        "    movs r1, #0\n"
        ".L081342AE:\n"
        "    lsls r0, r4, #1\n"
        "    adds r0, r0, r2\n"
        "    strh r1, [r0]\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #0x63\n"
        "    bls .L081342AE\n"
        "    mov r4, r8\n"
        "    adds r0, r4, #3\n"
        "    cmp r4, r0\n"
        "    bge .L0813437A\n"
        "    b .L0813436C\n"
        ".L081342C8: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L081342CC: .4byte 0x03006680 @ IWRAM+0x6680\n"
        ".L081342D0: .4byte 0x0203DA00 @ EWRAM+0x3DA00\n"
        ".L081342D4:\n"
        "    lsls r0, r4, #2\n"
        "    ldr r3, .L0813438C\n"
        "    adds r1, r0, r3\n"
        "    ldr r1, [r1]\n"
        "    movs r7, #4\n"
        "    mov sb, r0\n"
        "    cmp r1, #0\n"
        "    beq .L081342E6\n"
        "    movs r7, #0\n"
        ".L081342E6:\n"
        "    adds r0, r2, #0\n"
        "    bl Action_GetRecord\n"
        "    adds r3, r0, #0\n"
        "    adds r3, #0xc\n"
        "    movs r2, #0\n"
        "    adds r0, r4, #1\n"
        "    str r0, [sp]\n"
        "    mov r1, r8\n"
        "    subs r5, r4, r1\n"
        "    movs r0, #3\n"
        "    add r0, r8\n"
        "    mov sl, r0\n"
        "    ldr r4, .L08134390\n"
        "    movs r1, #0\n"
        ".L08134304:\n"
        "    lsls r0, r2, #1\n"
        "    adds r0, r0, r4\n"
        "    strh r1, [r0]\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #0xf\n"
        "    bls .L08134304\n"
        "    movs r2, #0\n"
        "    ldr r6, .L08134394\n"
        "    ldr r4, .L08134390\n"
        ".L0813431A:\n"
        "    lsls r0, r2, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r1, [r3]\n"
        "    strh r1, [r0]\n"
        "    adds r3, #2\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #7\n"
        "    bls .L0813431A\n"
        "    lsls r4, r5, #1\n"
        "    adds r0, r4, r6\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x27\n"
        "    adds r2, r7, #0\n"
        "    movs r3, #8\n"
        "    bl sub_08133724\n"
        "    lsls r1, r5, #4\n"
        "    ldr r3, .L08134398\n"
        "    adds r2, r1, r3\n"
        "    movs r0, #1\n"
        "    strh r0, [r2]\n"
        "    ldr r0, .L0813439C\n"
        "    adds r1, r1, r0\n"
        "    ldr r0, .L0813438C\n"
        "    add r0, sb\n"
        "    ldr r0, [r0]\n"
        "    str r0, [r1]\n"
        "    movs r0, #0x80\n"
        "    strh r0, [r2, #8]\n"
        "    ldr r0, .L081343A0\n"
        "    adds r4, r4, r0\n"
        "    ldrh r0, [r4]\n"
        "    strh r0, [r2, #0xa]\n"
        "    strh r7, [r2, #0xc]\n"
        "    ldr r1, [sp]\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, sl\n"
        "    bge .L0813437A\n"
        ".L0813436C:\n"
        "    ldr r0, .L081343A4\n"
        "    lsls r1, r4, #1\n"
        "    adds r1, r1, r0\n"
        "    ldrh r2, [r1]\n"
        "    ldr r0, .L081343A8\n"
        "    cmp r2, r0\n"
        "    bne .L081342D4\n"
        ".L0813437A:\n"
        "    add sp, #4\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L0813438C: .4byte 0x0203BD74 @ EWRAM+0x3BD74\n"
        ".L08134390: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L08134394: .4byte gUnknown_0879038A\n"
        ".L08134398: .4byte 0x03006620 @ IWRAM+0x6620\n"
        ".L0813439C: .4byte 0x03006624 @ IWRAM+0x6624\n"
        ".L081343A0: .4byte gUnknown_0878FC64\n"
        ".L081343A4: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L081343A8: .4byte 0x0000FFFF\n"
    );
}
#endif

// ScriptOp_33B @ 0x081343AC
#ifdef NONMATCHING
void ScriptOp_33B(void)
{
    u16 lo;
    u32 target;
    u16 i;

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
    gUnk_0203DAC8[4] = 0;
    for (i = 0; i < 256; i++)
    {
        gShopItemIds[i] |= 0xFFFF;
        gShopItemPrices[i] = -1;
    }
    gUnk_03006688 = gUnknown_0878EFB8[gUnk_03006914][0] + 1;
    for (i = 0; i < gUnk_03006688; i++)
    {
        gShopItemIds[i] = gUnknown_0878EFB8[gUnk_03006914][i + 1];
        gShopItemPrices[i] = sub_080C4C60(gShopItemIds[i]);
    }
    gScriptWaitState = 0x22;
    for (i = 0; i < 15; i++)
        gUnk_03006820[i] = gMsgGlyphQueue[i * 4];
    gUnk_03006940 = gUnk_030065E4 = gUnk_0300696C = 0;
    Shop_InitItemList(0, 0);
    gUnk_030068A4 = sub_080D3400(1, (u16)gUnk_03006898, gShopItemIds[0]);
    Task_Create(gUnknown_0878FD58, 0xFFFF);
    gScriptYield = 1;
}
#else
NAKED
void ScriptOp_33B(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    ldr r3, .L0813451C\n"
        "    ldrh r0, [r3]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r3]\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r2, .L08134520\n"
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
        "    ldr r5, .L08134524\n"
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
        "    adds r0, r1, #1\n"
        "    strh r0, [r3]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0xf\n"
        "    adds r1, r1, r4\n"
        "    ldrh r2, [r1]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r3]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #0x10\n"
        "    orrs r0, r2\n"
        "    str r0, [r5, #8]\n"
        "    adds r0, r1, #1\n"
        "    strh r0, [r3]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0xf\n"
        "    adds r1, r1, r4\n"
        "    ldrh r2, [r1]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r3]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #0x10\n"
        "    orrs r0, r2\n"
        "    str r0, [r5, #0xc]\n"
        "    movs r0, #0\n"
        "    str r0, [r5, #0x10]\n"
        "    movs r5, #0\n"
        "    ldr r7, .L08134528\n"
        "    ldr r0, .L0813452C\n"
        "    mov r8, r0\n"
        "    ldr r1, .L08134530\n"
        "    mov ip, r1\n"
        "    ldr r6, .L08134534\n"
        "    ldr r0, .L08134538\n"
        "    adds r4, r0, #0\n"
        "    ldr r3, .L0813453C\n"
        "    movs r2, #1\n"
        "    rsbs r2, r2, #0\n"
        ".L08134450:\n"
        "    lsls r1, r5, #1\n"
        "    adds r1, r1, r6\n"
        "    ldrh r0, [r1]\n"
        "    orrs r0, r4\n"
        "    strh r0, [r1]\n"
        "    lsls r0, r5, #2\n"
        "    adds r0, r0, r3\n"
        "    str r2, [r0]\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #0xff\n"
        "    bls .L08134450\n"
        "    mov r1, ip\n"
        "    ldrh r0, [r1]\n"
        "    lsls r0, r0, #6\n"
        "    add r0, r8\n"
        "    ldrh r0, [r0]\n"
        "    adds r0, #1\n"
        "    strh r0, [r7]\n"
        "    movs r5, #0\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r7, r1]\n"
        "    cmp r5, r0\n"
        "    bge .L081344B8\n"
        "    mov r7, r8\n"
        "    ldr r6, .L08134534\n"
        ".L08134486:\n"
        "    lsls r2, r5, #1\n"
        "    adds r2, r2, r6\n"
        "    adds r4, r5, #1\n"
        "    lsls r1, r4, #1\n"
        "    ldr r0, .L08134530\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #6\n"
        "    adds r1, r1, r0\n"
        "    adds r1, r1, r7\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r2]\n"
        "    ldrh r0, [r2]\n"
        "    bl sub_080C4C60\n"
        "    ldr r2, .L0813453C\n"
        "    lsls r1, r5, #2\n"
        "    adds r1, r1, r2\n"
        "    str r0, [r1]\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r5, r4, #0x10\n"
        "    ldr r0, .L08134528\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    cmp r5, r0\n"
        "    blt .L08134486\n"
        ".L081344B8:\n"
        "    ldr r1, .L08134540\n"
        "    movs r0, #0x22\n"
        "    strh r0, [r1]\n"
        "    movs r5, #0\n"
        "    ldr r4, .L08134544\n"
        "    ldr r6, .L08134548\n"
        "    ldr r7, .L0813454C\n"
        "    ldr r3, .L08134550\n"
        "    ldr r2, .L08134554\n"
        ".L081344CA:\n"
        "    lsls r1, r5, #1\n"
        "    adds r1, r1, r3\n"
        "    lsls r0, r5, #3\n"
        "    adds r0, r0, r2\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r1]\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #0xe\n"
        "    bls .L081344CA\n"
        "    movs r0, #0\n"
        "    strh r0, [r4]\n"
        "    strh r0, [r6]\n"
        "    strh r0, [r7]\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    bl Shop_InitItemList\n"
        "    ldr r0, .L08134558\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L08134534\n"
        "    ldrh r2, [r0]\n"
        "    movs r0, #1\n"
        "    bl sub_080D3400\n"
        "    ldr r1, .L0813455C\n"
        "    str r0, [r1]\n"
        "    ldr r0, .L08134560\n"
        "    ldr r1, .L08134538\n"
        "    bl Task_Create\n"
        "    ldr r1, .L08134564\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L0813451C: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L08134520: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L08134524: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8\n"
        ".L08134528: .4byte 0x03006688 @ IWRAM+0x6688\n"
        ".L0813452C: .4byte gUnknown_0878EFB8\n"
        ".L08134530: .4byte 0x03006914 @ IWRAM+0x6914\n"
        ".L08134534: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L08134538: .4byte 0x0000FFFF\n"
        ".L0813453C: .4byte 0x0203BD74 @ EWRAM+0x3BD74\n"
        ".L08134540: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L08134544: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08134548: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L0813454C: .4byte 0x030065E4 @ IWRAM+0x65E4\n"
        ".L08134550: .4byte 0x03006820 @ IWRAM+0x6820\n"
        ".L08134554: .4byte 0x0203D800 @ EWRAM+0x3D800\n"
        ".L08134558: .4byte 0x03006898 @ IWRAM+0x6898\n"
        ".L0813455C: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L08134560: .4byte gUnknown_0878FD58\n"
        ".L08134564: .4byte 0x0203DB6E @ EWRAM+0x3DB6E\n"
    );
}
#endif

// ScriptOp_33C @ 0x08134568
void ScriptOp_33C(void)
{
    u16 lo;
    u32 target;

    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    if (gUnk_030069A8 < 0xD0 && sub_080CDB74(gUnk_03006898, gUnk_030069A8) == 0)
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_33D @ 0x081345CC
void ScriptOp_33D(void)
{
    s32 sell = 0;
    u16 i;
    u16 lo;
    u32 target;

    for (i = 0; i < 15; i++)
        gUnk_03006820[i] = gMsgGlyphQueue[i * 4];
    gUnk_030065FC = SCRIPT_READ();
    if (gUnk_030065FC == 0xFF)
    {
        gUnk_030065FC = 1;
        sell = 1;
    }
    gScriptWaitState = 0x25;
    if (sell)
        gScriptWaitState = 0x2A;
    Shop_InitItemList(gUnk_03006940, gUnk_030065E4);
    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    gUnk_0203DAC8[0] = (u16 *)target;
    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    gUnk_0203DAC8[1] = (u16 *)target;
    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    gUnk_0203DAC8[2] = (u16 *)target;
    gMsgGlyphList2[gMsgGlyphList2Count * 4] = 0x3E;
    gMsgGlyphList2[gMsgGlyphList2Count * 4 + 1] = 0xBC;
    gMsgGlyphList2[gMsgGlyphList2Count * 4 + 2] = gUnknown_0879038A[gUnk_0300696C];
    gMsgGlyphList2[gMsgGlyphList2Count * 4 + 3] = 0;
    gMsgGlyphList2Count = 0x19;
    gUnk_03006620[3].unk0 = 1;
    gUnk_03006620[3].price = (s16)(gUnk_030065FC % 10);
    gUnk_03006620[3].unk8 = 0x98;
    gUnk_03006620[3].y = gUnknown_0878FC64[gUnk_0300696C];
    gUnk_03006620[3].palette = 0;
    gUnk_03006620[4].unk0 = 1;
    gUnk_03006620[4].price = (s16)(gUnk_030065FC / 10);
    gUnk_03006620[4].unk8 = 0x90;
    gUnk_03006620[4].y = gUnknown_0878FC64[gUnk_0300696C];
    gUnk_03006620[4].palette = 0;
    gUnk_030068A4 = sub_080D3400(2, (u16)gUnk_03006898, gShopItemIds[gUnk_0300696C + gUnk_03006940]);
    gUnk_03006694 = sub_080C4C60(gShopItemIds[gUnk_0300696C + gUnk_03006940]);
    gScriptWaitState = 0x25;
    if (sell)
    {
        gScriptWaitState = 0x2A;
        gUnk_03006694 = sub_080C4C7C(gShopItemIds[gUnk_0300696C + gUnk_03006940]);
    }
    gUnk_0203DB2C = gUnk_030065FC * gUnk_03006694;
    if (gUnk_0203DB2C > 999999)
        gUnk_0203DB2C = 999999;
    Task_Create(gUnknown_0878FF8C, 0xFFFF);
    gScriptYield = 1;
}

// ScriptOp_33E @ 0x08134854
void ScriptOp_33E(void)
{
    u16 lo;
    u32 target;

    lo = SCRIPT_READ();
    target = SCRIPT_READ();
    target = target << 16 | lo;
    if (gUnk_030069A8 >= 0xD0)
        gScriptJumpTarget = (u16 *)target;
    if (sub_080CDB74(gUnk_03006898, gUnk_030069A8) == 0)
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_33F @ 0x081348B8
void ScriptOp_33F(void)
{
    u16 i;

    for (i = 0; i < gUnk_030065FC; i++)
        Inventory_AddItem(gScriptItemCheckId);
    sub_080CDFBC(gUnk_03006898, gScriptItemCheckId);
}

// ScriptOp_340 @ 0x081348FC
void ScriptOp_340(void)
{
}

// ScriptOp_Choice @ 0x08134900
#ifdef NONMATCHING
void ScriptOp_Choice(void)
{
    u16 op, n;
    s16 i;
    u16 lo;
    u32 target;

    gUnk_030065E0 = 0xFFFF;
    op = SCRIPT_READ();
    n = op >> 8;
    gUnk_03006844 = op & 0xFF;
    if (gUnk_03006844 > 3)
        gUnk_03006844 = 0;
    if (gUnk_03006844 == 1 || gUnk_03006844 == 3)
        MsgWindow_SaveGlyphs();
    for (i = 0; i < 20; i++)
        gUnk_0203DB88[i] |= 0xFFFF;
    gUnk_03006604 = n;
    for (i = 0; i < gUnk_03006604 + 1; i++)
    {
        gUnk_0203DB88[i] = SCRIPT_READ();
        lo = SCRIPT_READ();
        target = SCRIPT_READ();
        target = target << 16 | lo;
        gUnk_0203DAC8[i] = (u16 *)target;
    }
    gUnk_03006940 = 0;
    gUnk_0300696C = 0;
    sub_0812F2B4((u16)gUnk_03006844);
    gScriptYield = 1;
    Task_Create(gUnknown_0878FC80, 0xFFFF);
    gScriptWaitState = 0xD;
}
#else
NAKED
void ScriptOp_Choice(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    ldr r1, .L08134A14\n"
        "    ldr r2, .L08134A18\n"
        "    adds r0, r2, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r2, .L08134A1C\n"
        "    ldrh r0, [r2]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r2]\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r1, .L08134A20\n"
        "    ldr r1, [r1]\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r1\n"
        "    ldrh r1, [r0]\n"
        "    lsrs r5, r1, #8\n"
        "    movs r0, #0xff\n"
        "    ands r0, r1\n"
        "    ldr r1, .L08134A24\n"
        "    strh r0, [r1]\n"
        "    cmp r0, #3\n"
        "    ble .L08134938\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        ".L08134938:\n"
        "    movs r7, #0\n"
        "    ldrsh r0, [r1, r7]\n"
        "    cmp r0, #1\n"
        "    beq .L08134944\n"
        "    cmp r0, #3\n"
        "    bne .L08134948\n"
        ".L08134944:\n"
        "    bl MsgWindow_SaveGlyphs\n"
        ".L08134948:\n"
        "    movs r1, #0\n"
        "    ldr r6, .L08134A28\n"
        "    ldr r0, .L08134A2C\n"
        "    mov sb, r0\n"
        "    ldr r2, .L08134A30\n"
        "    mov sl, r2\n"
        "    ldr r4, .L08134A34\n"
        "    ldr r7, .L08134A18\n"
        "    adds r3, r7, #0\n"
        ".L0813495A:\n"
        "    lsls r0, r1, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    lsls r2, r0, #1\n"
        "    adds r2, r2, r4\n"
        "    ldrh r1, [r2]\n"
        "    orrs r1, r3\n"
        "    strh r1, [r2]\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #0x13\n"
        "    ble .L0813495A\n"
        "    strh r5, [r6]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r6, r2]\n"
        "    adds r0, #1\n"
        "    cmp r1, r0\n"
        "    bge .L081349DE\n"
        "    ldr r7, .L08134A34\n"
        "    mov r8, r7\n"
        "    ldr r5, .L08134A1C\n"
        "    ldr r0, .L08134A20\n"
        "    mov ip, r0\n"
        ".L0813498C:\n"
        "    lsls r3, r1, #0x10\n"
        "    asrs r3, r3, #0x10\n"
        "    lsls r1, r3, #1\n"
        "    add r1, r8\n"
        "    ldrh r0, [r5]\n"
        "    adds r2, r0, #1\n"
        "    strh r2, [r5]\n"
        "    lsls r0, r0, #0x10\n"
        "    mov r7, ip\n"
        "    ldr r4, [r7]\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r1]\n"
        "    adds r1, r2, #1\n"
        "    strh r1, [r5]\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0xf\n"
        "    adds r2, r2, r4\n"
        "    ldrh r2, [r2]\n"
        "    adds r0, r1, #1\n"
        "    strh r0, [r5]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0xf\n"
        "    adds r1, r1, r4\n"
        "    ldrh r1, [r1]\n"
        "    lsls r1, r1, #0x10\n"
        "    orrs r1, r2\n"
        "    lsls r0, r3, #2\n"
        "    ldr r2, .L08134A38\n"
        "    adds r0, r0, r2\n"
        "    str r1, [r0]\n"
        "    adds r3, #1\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r1, r3, #0x10\n"
        "    asrs r3, r3, #0x10\n"
        "    movs r7, #0\n"
        "    ldrsh r0, [r6, r7]\n"
        "    adds r0, #1\n"
        "    cmp r3, r0\n"
        "    blt .L0813498C\n"
        ".L081349DE:\n"
        "    movs r0, #0\n"
        "    mov r1, sb\n"
        "    strh r0, [r1]\n"
        "    mov r2, sl\n"
        "    strh r0, [r2]\n"
        "    ldr r7, .L08134A24\n"
        "    ldrh r0, [r7]\n"
        "    bl sub_0812F2B4\n"
        "    ldr r1, .L08134A3C\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L08134A40\n"
        "    ldr r1, .L08134A18\n"
        "    bl Task_Create\n"
        "    ldr r1, .L08134A44\n"
        "    movs r0, #0xd\n"
        "    strh r0, [r1]\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L08134A14: .4byte 0x030065E0 @ IWRAM+0x65E0\n"
        ".L08134A18: .4byte 0x0000FFFF\n"
        ".L08134A1C: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L08134A20: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L08134A24: .4byte 0x03006844 @ IWRAM+0x6844\n"
        ".L08134A28: .4byte 0x03006604 @ IWRAM+0x6604\n"
        ".L08134A2C: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08134A30: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L08134A34: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L08134A38: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8\n"
        ".L08134A3C: .4byte 0x0203DB6E @ EWRAM+0x3DB6E\n"
        ".L08134A40: .4byte gUnknown_0878FC80\n"
        ".L08134A44: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
    );
}
#endif

// ScriptOp_352 @ 0x08134A48
void ScriptOp_352(void)
{
    u16 id = SCRIPT_READ();

    if (id < 100)
        Music_Play(id);
    else
        Sound_Play(id);
}

// ScriptOp_353 @ 0x08134A78
void ScriptOp_353(void)
{
    s32 d = SCRIPT_READ();

    d <<= 8;

    if (d > 0x7FFF)
        d |= 0xFFFF0000;
    Combatant_AddAlignment(0, d);
    Combatant_AddAlignment(1, d);
}

// ScriptOp_354 @ 0x08134AC0
void ScriptOp_354(void)
{
}

// ScriptOp_355 @ 0x08134AC4
void ScriptOp_355(void)
{
    u16 lo;
    u32 hi;
    s32 a = Combatant_GetAlignment(0);

    if (a == 0)
    {
        lo = SCRIPT_READ();
        hi = gScriptBase[gScriptPc];
        goto jump;
    }
    if (a == 2)
    {
        lo = gScriptBase[gScriptPc + 2];
        hi = gScriptBase[gScriptPc + 3];
    jump:
        hi <<= 16;
        hi |= lo;
        gScriptJumpTarget = (u16 *)hi;
        return;
    }
    gScriptPc += 4;
}

// ScriptOp_356 @ 0x08134B34
#ifdef NONMATCHING
void ScriptOp_356(void)
{
    u16 range; u16 min, max; u32 v;
    u16 lo;
    u32 target;

    range = SCRIPT_READ();
    max = (range & 0xFF) + 1;
    min = (range >> 8) & 0xFF;
    v = sub_080C0794(0) >> 8;
    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    if (v >= min && v < max)
        gScriptJumpTarget = (u16 *)target;
}
#else
NAKED
void ScriptOp_356(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    ldr r5, .L08134B9C\n"
        "    ldrh r0, [r5]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r5]\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r1, .L08134BA0\n"
        "    mov r8, r1\n"
        "    ldr r1, [r1]\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r1\n"
        "    ldrh r4, [r0]\n"
        "    movs r1, #0xff\n"
        "    adds r0, r4, #0\n"
        "    ands r0, r1\n"
        "    adds r6, r0, #1\n"
        "    lsrs r4, r4, #8\n"
        "    ands r4, r1\n"
        "    movs r0, #0\n"
        "    bl sub_080C0794\n"
        "    lsrs r7, r0, #8\n"
        "    ldrh r0, [r5]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r5]\n"
        "    lsls r0, r0, #0x10\n"
        "    mov r3, r8\n"
        "    ldr r2, [r3]\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r2\n"
        "    ldrh r3, [r0]\n"
        "    adds r0, r1, #1\n"
        "    strh r0, [r5]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0xf\n"
        "    adds r1, r1, r2\n"
        "    ldrh r0, [r1]\n"
        "    lsls r1, r0, #0x10\n"
        "    orrs r1, r3\n"
        "    cmp r7, r4\n"
        "    blo .L08134B92\n"
        "    cmp r7, r6\n"
        "    bhs .L08134B92\n"
        "    ldr r0, .L08134BA4\n"
        "    str r1, [r0]\n"
        ".L08134B92:\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L08134B9C: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L08134BA0: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L08134BA4: .4byte 0x030068E4 @ IWRAM+0x68E4\n"
    );
}
#endif

// ScriptOp_357 @ 0x08134BA8
void ScriptOp_357(void)
{
    u16 level = SCRIPT_READ();
    u16 lo;
    u32 target;

    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    if (Combatant_GetLevel(0) <= level)
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_358 @ 0x08134C00
void ScriptOp_358(void)
{
    gUnk_0203DB5C = SCRIPT_READ();
    gScriptWaitState = 0xF;
    gScriptYield = 1;
}

// sub_08134C3C @ 0x08134C3C
u32 sub_08134C3C(void)
{
    return 0;
}

// ScriptOp_359 @ 0x08134C40
void ScriptOp_359(void)
{
    s32 count = 0;
    u16 idx, id;
    s32 n;
    u32 i;
    u16 lo;
    u32 hi;

    idx = SCRIPT_READ();
    id = gUnk_0203DB28[idx - 1];
    n = Stock_GetCapacity();
    for (i = 4; i < n + 4; i++)
    {
        if (Combatant_IsUsed(i) && Combatant_GetDemonId(i) == id)
            count++;
    }
    if (count)
    {
        gScriptPc += 2;
    }
    else
    {
        lo = SCRIPT_READ();
        hi = gScriptBase[gScriptPc];
        hi <<= 16;
        hi |= lo;
        gScriptJumpTarget = (u16 *)hi;
    }
}
