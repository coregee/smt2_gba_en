/* Script VM text substitution: opcodes 0x31A-0x32F and 0x36E build a short string in
   gScriptSubstBuf (16 words) and divert the VM into it; the string ends with 0x318, which
   returns to the saved position (ScriptOp_ReturnFromSubst). */

#include "global.h"
#include "script.h"

// ScriptOp_Substitute @ 0x08132B40
/* Close: same size and block layout as the original; what differs is the register choice
   (i/val/mode) and the address add order in the 0x328/0x329 table lookups. */
#ifdef NONMATCHING
void ScriptOp_Substitute(void)
{
    s32 val = 0;
    s16 mode = 0;
    s16 i, j, n;
    u16 *src;
    u16 c;
    u16 digits[8];

    for (i = 0; i < 16; i++)
        gScriptSubstBuf[i] = 0;
    if (gScriptCurOp == 0x327)
        val = SCRIPT_READ();
    gScriptSubstSavedPc = gScriptPc;
    gScriptSubstSavedBase = gScriptBase;
    if (gScriptCurOp == 0x36E)
    {
        gScriptSubstBuf[0] = 0x52;
        gScriptSubstBuf[1] = 0x318;
    }
    else
    {
        switch (gScriptCurOp)
        {
        case 0x31A:
            Combatant_DecodeName(&gGameState[0], gScriptSubstBuf);
            gScriptSubstBuf[8] = 0;
            mode = 1;
            break;
        case 0x31B:
            Combatant_DecodeName(sub_080C10E4(0x8001), gScriptSubstBuf);
            gScriptSubstBuf[8] = 0;
            mode = 1;
            break;
        case 0x31C:
            Combatant_DecodeName(sub_080C10E4(0x8002), gScriptSubstBuf);
            gScriptSubstBuf[8] = 0;
            mode = 1;
            break;
        case 0x31D:
            if (gUnk_03006670 == 1)
            {
                if (Combatant_IsUsed(2))
                    Combatant_DecodeName(&gGameState[2], gScriptSubstBuf);
                else
                    Combatant_DecodeName(&gGameState[1], gScriptSubstBuf);
            }
            else
                Combatant_DecodeName(&gGameState[1], gScriptSubstBuf);
            gScriptSubstBuf[8] = 0;
            mode = 1;
            break;
        case 0x325:
            Combatant_DecodeName(&gGameState[2], gScriptSubstBuf);
            gScriptSubstBuf[8] = 0;
            mode = 1;
            break;
        case 0x32E:
            Combatant_DecodeName(sub_080C10E4(0x8000), gScriptSubstBuf);
            gScriptSubstBuf[8] = 0;
            mode = 1;
            break;
        case 0x31E:
        {
            u16 id;

            if (gUnk_03006670 == 1)
                id = gUnk_0203DB7C;
            else
                id = gUnk_0203DB28[0];
            src = (u16 *)(Demon_GetRecord(id) + 0x22);
        }
            for (i = 0; i < 8; i++)
                gScriptSubstBuf[i] = *src++;
            break;
        case 0x31F:
        {
            u16 id;

            if (gUnk_03006670 == 1)
                id = gUnk_0203DB7C;
            else
                id = gUnk_0203DB28[0];
            src = Race_GetName(*(s8 *)Demon_GetRecord(id));
        }
            for (i = 0; i < 8; i++)
                gScriptSubstBuf[i] = *src++;
            break;
        case 0x327:
            if (val == 0)
            {
                src = Race_GetName(*(s8 *)Demon_GetRecord(gUnk_0203DB28[1]));
                for (i = 0; i < 8; i++)
                    gScriptSubstBuf[i] = *src++;
            }
            else if (val == 1)
            {
                src = (u16 *)(sub_080BF5C0(gUnk_0203DB80) + 6);
                for (i = 0; i < 8; i++)
                    gScriptSubstBuf[i] = *src++;
            }
            else if (val == 2)
            {
                val = gUnk_0203DB30;
                goto number;
            }
            else if (val == 3)
            {
                val = Inventory_GetCount(0x11F);
                goto number;
            }
            break;
        case 0x320:
            for (i = 0; i < 4 && Combatant_IsAlive(i) != 1; i++)
                ;
            Combatant_DecodeName(&gGameState[i], gScriptSubstBuf);
            if (gScriptSubstBuf[7] != 0)
                j = 8;
            else
            {
                for (j = 6; j > 0; j--)
                {
                    if (gScriptSubstBuf[j] != 0 && gScriptSubstBuf[j + 1] == 0)
                        break;
                }
                j++;
            }
            n = 0;
            for (i = 0; i < 4; i++)
            {
                if (Combatant_IsUsed(i))
                    n++;
            }
            if (n > 1)
                gScriptSubstBuf[j++] = 0xC8F;
            gScriptSubstBuf[j] = 0x318;
            mode = 2;
            break;
        case 0x321:
            if (gScriptItemCheckId > 0xCF)
                src = (u16 *)(Action_GetRecord(gScriptItemCheckId) + 0xC);
            else if (gScriptItemCheckId > 0x7F)
                src = (u16 *)(Equipment_GetRecord36_MidRange(gScriptItemCheckId) + 0x14);
            else
                src = (u16 *)(Item_GetRecord(gScriptItemCheckId) + 0x14);
            for (i = 0; i < 8; i++)
                gScriptSubstBuf[i] = *src++;
            break;
        case 0x322:
        {
            u16 id;

            if (gUnk_03006670 == 1)
                id = gUnk_0203DB7E;
            else
                id = gUnk_0203DB28[1];
            src = (u16 *)(Demon_GetRecord(id) + 0x22);
        }
            for (i = 0; i < 8; i++)
                gScriptSubstBuf[i] = *src++;
            break;
        case 0x323:
            val = gUnk_0203DB2C;
        number:
                if (val == 0)
                {
                    digits[0] = gScriptDigitGlyphs[0];
                    for (i = 1; i < 8; i++)
                        digits[i] = 0;
                }
                else
                {
                    for (i = 0; i < 8; i++)
                    {
                        if (val == 0)
                            digits[i] = 0;
                        else
                        {
                            digits[i] = gScriptDigitGlyphs[val % 10];
                            val /= 10;
                        }
                    }
                }
                j = 0;
                for (i = 7; i >= 0; i--)
                {
                    if (digits[i] != 0)
                    {
                        gScriptSubstBuf[j] = digits[i];
                        j++;
                    }
                }
            break;
        case 0x32F:
            val = sub_080C31F0();
                if (val == 0)
                {
                    digits[0] = gScriptDigitGlyphs[0];
                    for (i = 1; i < 8; i++)
                        digits[i] = 0;
                }
                else
                {
                    for (i = 0; i < 8; i++)
                    {
                        if (val == 0)
                            digits[i] = 0;
                        else
                        {
                            digits[i] = gScriptDigitGlyphs[val % 10];
                            val /= 10;
                        }
                    }
                }
                j = 0;
                for (i = 7; i >= 0; i--)
                {
                    if (digits[i] != 0)
                    {
                        gScriptSubstBuf[j] = digits[i];
                        j++;
                    }
                }
            break;
        case 0x324:
            Combatant_DecodeName(&gGameState[gUnk_03006850], gScriptSubstBuf);
            gScriptSubstBuf[8] = 0;
            mode = 1;
            break;
        case 0x328:
        {
            const u16 (*t)[10];

            i = 0;
            t = (const u16 (*)[10])gUnknown_0878F9CC;
            c = t[gUnk_0203DB72][1];
            while (c != 0x301)
            {
                gScriptSubstBuf[i] = c;
                i++;
                if (i > 9)
                    break;
                {
                    s32 k = i + 1;

                    c = t[gUnk_0203DB72][k];
                }
            }
            break;
        }
        case 0x329:
            for (i = 0; i < 10; i++)
            {
                c = *(gUnknown_0878EF04 + i + gUnk_030069A0[gUnk_0300696C] * 10);
                if (c == 0x301)
                    break;
                gScriptSubstBuf[i] = c;
            }
            break;
        }

        /* Terminate after the last character. Modes 0 and 1 do the same; mode 2 (0x320)
           placed its own terminator. */
        switch (mode)
        {
        case 0:
            for (i = 14; i >= 0; i--)
            {
                if (gScriptSubstBuf[i] != 0
                 && (gScriptSubstBuf[i + 1] == 0 || gScriptSubstBuf[i + 1] == 0x318))
                {
                    gScriptSubstBuf[i + 1] = 0x318;
                    break;
                }
            }
            break;
        case 1:
            for (i = 14; i >= 0; i--)
            {
                if (gScriptSubstBuf[i] != 0
                 && (gScriptSubstBuf[i + 1] == 0 || gScriptSubstBuf[i + 1] == 0x318))
                {
                    gScriptSubstBuf[i + 1] = 0x318;
                    break;
                }
            }
            break;
        case 2:
            break;
        }
    }
    gScriptBase = gScriptSubstBuf;
    gScriptPc = 0;
}
#else
NAKED
void ScriptOp_Substitute(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x10\n"
        "    movs r5, #0\n"
        "    mov sb, r5\n"
        "    movs r6, #0\n"
        "    ldr r7, .L08132BC0\n"
        "    ldr r0, .L08132BC4\n"
        "    mov ip, r0\n"
        "    ldr r1, .L08132BC8\n"
        "    mov sl, r1\n"
        "    ldr r4, .L08132BCC\n"
        "    ldr r2, .L08132BD0\n"
        "    mov r8, r2\n"
        "    ldr r3, .L08132BD4\n"
        "    movs r2, #0\n"
        ".L08132B66:\n"
        "    lsls r1, r6, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r0, r3\n"
        "    strh r2, [r0]\n"
        "    adds r1, #1\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r6, r1, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    cmp r1, #0xf\n"
        "    ble .L08132B66\n"
        "    adds r2, r7, #0\n"
        "    ldrh r1, [r2]\n"
        "    ldr r0, .L08132BD8\n"
        "    cmp r1, r0\n"
        "    bne .L08132B9A\n"
        "    mov r3, ip\n"
        "    ldrh r0, [r3]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r3]\n"
        "    lsls r0, r0, #0x10\n"
        "    mov r3, sl\n"
        "    ldr r1, [r3]\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r1\n"
        "    ldrh r5, [r0]\n"
        ".L08132B9A:\n"
        "    mov r1, ip\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r4]\n"
        "    mov r3, sl\n"
        "    ldr r0, [r3]\n"
        "    mov r1, r8\n"
        "    str r0, [r1]\n"
        "    ldrh r1, [r2]\n"
        "    ldr r0, .L08132BDC\n"
        "    cmp r1, r0\n"
        "    bne .L08132BE0\n"
        "    movs r0, #0x52\n"
        "    ldr r2, .L08132BD4\n"
        "    strh r0, [r2]\n"
        "    movs r0, #0xc6\n"
        "    lsls r0, r0, #2\n"
        "    strh r0, [r2, #2]\n"
        "    b .L08133296\n"
        "    .byte 0x00, 0x00\n"
        ".L08132BC0: .4byte 0x0203DB44 @ EWRAM+0x3DB44\n"
        ".L08132BC4: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L08132BC8: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L08132BCC: .4byte 0x0203DB4E @ EWRAM+0x3DB4E\n"
        ".L08132BD0: .4byte 0x030068CC @ IWRAM+0x68CC\n"
        ".L08132BD4: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L08132BD8: .4byte 0x00000327\n"
        ".L08132BDC: .4byte 0x0000036E\n"
        ".L08132BE0:\n"
        "    ldrh r0, [r7]\n"
        "    ldr r3, .L08132BF8\n"
        "    adds r0, r0, r3\n"
        "    cmp r0, #0x15\n"
        "    bls .L08132BEC\n"
        "    b .L081331DA\n"
        ".L08132BEC:\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L08132BFC\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        "    .byte 0x00, 0x00\n"
        ".L08132BF8: .4byte 0xFFFFFCE6\n"
        ".L08132BFC: .4byte gUnknown_08132C00\n"
        "    .global gUnknown_08132C00\n"
        "gUnknown_08132C00:\n"
        ".L08132C00: @ jump table\n"
        "    .4byte .L08132C58\n"
        "    .4byte .L08132C60\n"
        "    .4byte .L08132C68\n"
        "    .4byte .L08132C74\n"
        "    .4byte .L08132D00\n"
        "    .4byte .L08132D48\n"
        "    .4byte .L08132E3C\n"
        "    .4byte .L08132F0C\n"
        "    .4byte .L08132F60\n"
        "    .4byte .L08132FAC\n"
        "    .4byte .L08133114\n"
        "    .4byte .L08132CC4\n"
        "    .4byte .L081331DA\n"
        "    .4byte .L08132D9C\n"
        "    .4byte .L0813313C\n"
        "    .4byte .L08133198\n"
        "    .4byte .L081331DA\n"
        "    .4byte .L081331DA\n"
        "    .4byte .L081331DA\n"
        "    .4byte .L081331DA\n"
        "    .4byte .L08132CE0\n"
        "    .4byte .L08133060\n"
        ".L08132C58:\n"
        "    ldr r0, .L08132C5C\n"
        "    b .L08132CC6\n"
        ".L08132C5C: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L08132C60:\n"
        "    ldr r0, .L08132C64\n"
        "    b .L08132CE4\n"
        ".L08132C64: .4byte 0x00008001\n"
        ".L08132C68:\n"
        "    ldr r0, .L08132C70\n"
        "    bl sub_080C10E4\n"
        "    b .L0813311E\n"
        ".L08132C70: .4byte 0x00008002\n"
        ".L08132C74:\n"
        "    ldr r0, .L08132C8C\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #1\n"
        "    bne .L08132CA8\n"
        "    movs r0, #2\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L08132C94\n"
        "    ldr r0, .L08132C90\n"
        "    b .L08132C96\n"
        "    .byte 0x00, 0x00\n"
        ".L08132C8C: .4byte 0x03006670 @ IWRAM+0x6670\n"
        ".L08132C90: .4byte 0x030047C0 @ IWRAM+0x47C0\n"
        ".L08132C94:\n"
        "    ldr r0, .L08132CA0\n"
        ".L08132C96:\n"
        "    ldr r1, .L08132CA4\n"
        "    bl Combatant_DecodeName\n"
        "    b .L08132CB0\n"
        "    .byte 0x00, 0x00\n"
        ".L08132CA0: .4byte 0x03004740 @ IWRAM+0x4740\n"
        ".L08132CA4: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L08132CA8:\n"
        "    ldr r0, .L08132CBC\n"
        "    ldr r1, .L08132CC0\n"
        "    bl Combatant_DecodeName\n"
        ".L08132CB0:\n"
        "    ldr r1, .L08132CC0\n"
        "    movs r0, #0\n"
        "    strh r0, [r1, #0x10]\n"
        "    movs r3, #1\n"
        "    mov sb, r3\n"
        "    b .L081331DA\n"
        ".L08132CBC: .4byte 0x03004740 @ IWRAM+0x4740\n"
        ".L08132CC0: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L08132CC4:\n"
        "    ldr r0, .L08132CD8\n"
        ".L08132CC6:\n"
        "    ldr r4, .L08132CDC\n"
        "    adds r1, r4, #0\n"
        "    bl Combatant_DecodeName\n"
        "    movs r0, #0\n"
        "    strh r0, [r4, #0x10]\n"
        "    movs r0, #1\n"
        "    mov sb, r0\n"
        "    b .L081331DA\n"
        ".L08132CD8: .4byte 0x030047C0 @ IWRAM+0x47C0\n"
        ".L08132CDC: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L08132CE0:\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #8\n"
        ".L08132CE4:\n"
        "    bl sub_080C10E4\n"
        "    ldr r4, .L08132CFC\n"
        "    adds r1, r4, #0\n"
        "    bl Combatant_DecodeName\n"
        "    movs r0, #0\n"
        "    strh r0, [r4, #0x10]\n"
        "    movs r1, #1\n"
        "    mov sb, r1\n"
        "    b .L081331DA\n"
        "    .byte 0x00, 0x00\n"
        ".L08132CFC: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L08132D00:\n"
        "    ldr r0, .L08132D0C\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #1\n"
        "    bne .L08132D14\n"
        "    ldr r0, .L08132D10\n"
        "    b .L08132D16\n"
        ".L08132D0C: .4byte 0x03006670 @ IWRAM+0x6670\n"
        ".L08132D10: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L08132D14:\n"
        "    ldr r0, .L08132D40\n"
        ".L08132D16:\n"
        "    ldrh r0, [r0]\n"
        "    bl Demon_GetRecord\n"
        "    adds r3, r0, #0\n"
        "    adds r3, #0x22\n"
        "    movs r6, #0\n"
        "    ldr r4, .L08132D44\n"
        ".L08132D24:\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    lsls r1, r0, #1\n"
        "    adds r1, r1, r4\n"
        "    ldrh r2, [r3]\n"
        "    strh r2, [r1]\n"
        "    adds r3, #2\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #7\n"
        "    ble .L08132D24\n"
        "    b .L081331DA\n"
        ".L08132D40: .4byte 0x0203DB28 @ EWRAM+0x3DB28\n"
        ".L08132D44: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L08132D48:\n"
        "    ldr r0, .L08132D54\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #1\n"
        "    bne .L08132D5C\n"
        "    ldr r0, .L08132D58\n"
        "    b .L08132D5E\n"
        ".L08132D54: .4byte 0x03006670 @ IWRAM+0x6670\n"
        ".L08132D58: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L08132D5C:\n"
        "    ldr r0, .L08132D94\n"
        ".L08132D5E:\n"
        "    ldrh r0, [r0]\n"
        "    bl Demon_GetRecord\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Race_GetName\n"
        "    adds r3, r0, #0\n"
        "    movs r6, #0\n"
        "    ldr r4, .L08132D98\n"
        ".L08132D78:\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    lsls r1, r0, #1\n"
        "    adds r1, r1, r4\n"
        "    ldrh r2, [r3]\n"
        "    strh r2, [r1]\n"
        "    adds r3, #2\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #7\n"
        "    ble .L08132D78\n"
        "    b .L081331DA\n"
        ".L08132D94: .4byte 0x0203DB28 @ EWRAM+0x3DB28\n"
        ".L08132D98: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L08132D9C:\n"
        "    cmp r5, #0\n"
        "    bne .L08132DE0\n"
        "    ldr r0, .L08132DD8\n"
        "    ldrh r0, [r0, #2]\n"
        "    bl Demon_GetRecord\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Race_GetName\n"
        "    adds r3, r0, #0\n"
        "    movs r6, #0\n"
        "    ldr r4, .L08132DDC\n"
        ".L08132DBC:\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    lsls r1, r0, #1\n"
        "    adds r1, r1, r4\n"
        "    ldrh r2, [r3]\n"
        "    strh r2, [r1]\n"
        "    adds r3, #2\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #7\n"
        "    ble .L08132DBC\n"
        "    b .L081331DA\n"
        ".L08132DD8: .4byte 0x0203DB28 @ EWRAM+0x3DB28\n"
        ".L08132DDC: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L08132DE0:\n"
        "    cmp r5, #1\n"
        "    bne .L08132E18\n"
        "    ldr r0, .L08132E10\n"
        "    ldrh r0, [r0]\n"
        "    bl sub_080BF5C0\n"
        "    adds r3, r0, #6\n"
        "    movs r6, #0\n"
        "    ldr r4, .L08132E14\n"
        ".L08132DF2:\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    lsls r1, r0, #1\n"
        "    adds r1, r1, r4\n"
        "    ldrh r2, [r3]\n"
        "    strh r2, [r1]\n"
        "    adds r3, #2\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #7\n"
        "    ble .L08132DF2\n"
        "    b .L081331DA\n"
        "    .byte 0x00, 0x00\n"
        ".L08132E10: .4byte 0x0203DB80 @ EWRAM+0x3DB80\n"
        ".L08132E14: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L08132E18:\n"
        "    cmp r5, #2\n"
        "    bne .L08132E24\n"
        "    ldr r0, .L08132E20\n"
        "    b .L08132FAE\n"
        ".L08132E20: .4byte 0x0203DB30 @ EWRAM+0x3DB30\n"
        ".L08132E24:\n"
        "    cmp r5, #3\n"
        "    beq .L08132E2A\n"
        "    b .L081331DA\n"
        ".L08132E2A:\n"
        "    ldr r0, .L08132E38\n"
        "    bl Inventory_GetCount\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r5, r0, #0x18\n"
        "    b .L08132FB0\n"
        "    .byte 0x00, 0x00\n"
        ".L08132E38: .4byte 0x0000011F\n"
        ".L08132E3C:\n"
        "    movs r1, #0\n"
        "    b .L08132E46\n"
        ".L08132E40:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        ".L08132E46:\n"
        "    lsls r0, r1, #0x10\n"
        "    asrs r4, r0, #0x10\n"
        "    cmp r4, #3\n"
        "    bgt .L08132E58\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_IsAlive\n"
        "    cmp r0, #1\n"
        "    bne .L08132E40\n"
        ".L08132E58:\n"
        "    lsls r0, r4, #7\n"
        "    ldr r1, .L08132F00\n"
        "    adds r0, r0, r1\n"
        "    ldr r4, .L08132F04\n"
        "    adds r1, r4, #0\n"
        "    bl Combatant_DecodeName\n"
        "    ldrh r0, [r4, #0xe]\n"
        "    movs r6, #8\n"
        "    cmp r0, #0\n"
        "    bne .L08132EA2\n"
        "    movs r6, #6\n"
        "    ldr r2, .L08132F04\n"
        ".L08132E72:\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r1, r0, #0x10\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    beq .L08132E8E\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #1\n"
        "    ldr r3, .L08132F04\n"
        "    adds r0, r0, r3\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    beq .L08132E98\n"
        ".L08132E8E:\n"
        "    subs r0, r1, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bgt .L08132E72\n"
        ".L08132E98:\n"
        "    lsls r0, r6, #0x10\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #9\n"
        "    adds r0, r0, r1\n"
        "    lsrs r6, r0, #0x10\n"
        ".L08132EA2:\n"
        "    movs r5, #0\n"
        "    movs r1, #0\n"
        ".L08132EA6:\n"
        "    lsls r0, r1, #0x10\n"
        "    asrs r4, r0, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L08132EBE\n"
        "    lsls r0, r5, #0x10\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #9\n"
        "    adds r0, r0, r2\n"
        "    lsrs r5, r0, #0x10\n"
        ".L08132EBE:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #3\n"
        "    ble .L08132EA6\n"
        "    lsls r0, r5, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    ble .L08132EEA\n"
        "    ldr r2, .L08132F04\n"
        "    adds r1, r6, #0\n"
        "    lsls r0, r1, #0x10\n"
        "    movs r3, #0x80\n"
        "    lsls r3, r3, #9\n"
        "    adds r0, r0, r3\n"
        "    lsrs r6, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    asrs r1, r1, #0xf\n"
        "    adds r1, r1, r2\n"
        "    ldr r0, .L08132F08\n"
        "    strh r0, [r1]\n"
        ".L08132EEA:\n"
        "    ldr r0, .L08132F04\n"
        "    lsls r1, r6, #0x10\n"
        "    asrs r1, r1, #0xf\n"
        "    adds r1, r1, r0\n"
        "    movs r0, #0xc6\n"
        "    lsls r0, r0, #2\n"
        "    strh r0, [r1]\n"
        "    movs r0, #2\n"
        "    mov sb, r0\n"
        "    b .L081331DA\n"
        "    .byte 0x00, 0x00\n"
        ".L08132F00: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L08132F04: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L08132F08: .4byte 0x00000C8F\n"
        ".L08132F0C:\n"
        "    ldr r1, .L08132F20\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #0xcf\n"
        "    bls .L08132F24\n"
        "    bl Action_GetRecord\n"
        "    adds r3, r0, #0\n"
        "    adds r3, #0xc\n"
        "    b .L08132F3A\n"
        "    .byte 0x00, 0x00\n"
        ".L08132F20: .4byte 0x0203DB50 @ EWRAM+0x3DB50\n"
        ".L08132F24:\n"
        "    cmp r0, #0x7f\n"
        "    bls .L08132F30\n"
        "    ldrh r0, [r1]\n"
        "    bl Equipment_GetRecord36_MidRange\n"
        "    b .L08132F36\n"
        ".L08132F30:\n"
        "    ldrh r0, [r1]\n"
        "    bl Item_GetRecord\n"
        ".L08132F36:\n"
        "    adds r3, r0, #0\n"
        "    adds r3, #0x14\n"
        ".L08132F3A:\n"
        "    movs r6, #0\n"
        "    ldr r4, .L08132F5C\n"
        ".L08132F3E:\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    lsls r1, r0, #1\n"
        "    adds r1, r1, r4\n"
        "    ldrh r2, [r3]\n"
        "    strh r2, [r1]\n"
        "    adds r3, #2\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #7\n"
        "    ble .L08132F3E\n"
        "    b .L081331DA\n"
        "    .byte 0x00, 0x00\n"
        ".L08132F5C: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L08132F60:\n"
        "    ldr r0, .L08132F70\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #1\n"
        "    bne .L08132F78\n"
        "    ldr r0, .L08132F74\n"
        "    ldrh r0, [r0]\n"
        "    b .L08132F7C\n"
        "    .byte 0x00, 0x00\n"
        ".L08132F70: .4byte 0x03006670 @ IWRAM+0x6670\n"
        ".L08132F74: .4byte 0x0203DB7E @ EWRAM+0x3DB7E\n"
        ".L08132F78:\n"
        "    ldr r0, .L08132FA4\n"
        "    ldrh r0, [r0, #2]\n"
        ".L08132F7C:\n"
        "    bl Demon_GetRecord\n"
        "    adds r3, r0, #0\n"
        "    adds r3, #0x22\n"
        "    movs r6, #0\n"
        "    ldr r4, .L08132FA8\n"
        ".L08132F88:\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    lsls r1, r0, #1\n"
        "    adds r1, r1, r4\n"
        "    ldrh r2, [r3]\n"
        "    strh r2, [r1]\n"
        "    adds r3, #2\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #7\n"
        "    ble .L08132F88\n"
        "    b .L081331DA\n"
        ".L08132FA4: .4byte 0x0203DB28 @ EWRAM+0x3DB28\n"
        ".L08132FA8: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L08132FAC:\n"
        "    ldr r0, .L08132FD8\n"
        ".L08132FAE:\n"
        "    ldr r5, [r0]\n"
        ".L08132FB0:\n"
        "    cmp r5, #0\n"
        "    bne .L08132FE0\n"
        "    mov r0, sp\n"
        "    ldr r1, .L08132FDC\n"
        "    ldrh r1, [r1]\n"
        "    strh r1, [r0]\n"
        "    movs r6, #1\n"
        "    movs r2, #0\n"
        ".L08132FC0:\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    lsls r1, r0, #1\n"
        "    .2byte 0x4469 @ add r1, sp, r1\n"
        "    strh r2, [r1]\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #7\n"
        "    ble .L08132FC0\n"
        "    b .L0813302A\n"
        ".L08132FD8: .4byte 0x0203DB2C @ EWRAM+0x3DB2C\n"
        ".L08132FDC: .4byte gScriptDigitGlyphs\n"
        ".L08132FE0:\n"
        "    movs r6, #0\n"
        "    ldr r7, .L08132FF4\n"
        ".L08132FE4:\n"
        "    cmp r5, #0\n"
        "    bne .L08132FF8\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0xf\n"
        "    .2byte 0x4468 @ add r0, sp, r0\n"
        "    strh r5, [r0]\n"
        "    b .L0813301A\n"
        "    .byte 0x00, 0x00\n"
        ".L08132FF4: .4byte gScriptDigitGlyphs\n"
        ".L08132FF8:\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0xf\n"
        "    mov r1, sp\n"
        "    adds r4, r1, r0\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #0xa\n"
        "    bl __modsi3\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r7\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r4]\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #0xa\n"
        "    bl __divsi3\n"
        "    adds r5, r0, #0\n"
        ".L0813301A:\n"
        "    lsls r0, r6, #0x10\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #9\n"
        "    adds r0, r0, r2\n"
        "    lsrs r6, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #7\n"
        "    ble .L08132FE4\n"
        ".L0813302A:\n"
        "    movs r1, #0\n"
        "    movs r6, #7\n"
        "    ldr r4, .L0813305C\n"
        ".L08133030:\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r3, r0, #0x10\n"
        "    lsls r0, r3, #1\n"
        "    .2byte 0x4468 @ add r0, sp, r0\n"
        "    ldrh r2, [r0]\n"
        "    cmp r2, #0\n"
        "    beq .L0813304E\n"
        "    lsls r1, r1, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r0, r4\n"
        "    strh r2, [r0]\n"
        "    adds r1, #1\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        ".L0813304E:\n"
        "    subs r0, r3, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L08133030\n"
        "    b .L081331DA\n"
        "    .byte 0x00, 0x00\n"
        ".L0813305C: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L08133060:\n"
        "    bl sub_080C31F0\n"
        "    adds r5, r0, #0\n"
        "    cmp r5, #0\n"
        "    bne .L08133094\n"
        "    mov r0, sp\n"
        "    ldr r1, .L08133090\n"
        "    ldrh r1, [r1]\n"
        "    strh r1, [r0]\n"
        "    movs r6, #1\n"
        "    movs r2, #0\n"
        ".L08133076:\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    lsls r1, r0, #1\n"
        "    .2byte 0x4469 @ add r1, sp, r1\n"
        "    strh r2, [r1]\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #7\n"
        "    ble .L08133076\n"
        "    b .L081330DE\n"
        "    .byte 0x00, 0x00\n"
        ".L08133090: .4byte gScriptDigitGlyphs\n"
        ".L08133094:\n"
        "    movs r6, #0\n"
        "    ldr r7, .L081330A8\n"
        ".L08133098:\n"
        "    cmp r5, #0\n"
        "    bne .L081330AC\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0xf\n"
        "    .2byte 0x4468 @ add r0, sp, r0\n"
        "    strh r5, [r0]\n"
        "    b .L081330CE\n"
        "    .byte 0x00, 0x00\n"
        ".L081330A8: .4byte gScriptDigitGlyphs\n"
        ".L081330AC:\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0xf\n"
        "    mov r3, sp\n"
        "    adds r4, r3, r0\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #0xa\n"
        "    bl __modsi3\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r7\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r4]\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #0xa\n"
        "    bl __divsi3\n"
        "    adds r5, r0, #0\n"
        ".L081330CE:\n"
        "    lsls r0, r6, #0x10\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #9\n"
        "    adds r0, r0, r1\n"
        "    lsrs r6, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #7\n"
        "    ble .L08133098\n"
        ".L081330DE:\n"
        "    movs r1, #0\n"
        "    movs r6, #7\n"
        "    ldr r4, .L08133110\n"
        ".L081330E4:\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r3, r0, #0x10\n"
        "    lsls r0, r3, #1\n"
        "    .2byte 0x4468 @ add r0, sp, r0\n"
        "    ldrh r2, [r0]\n"
        "    cmp r2, #0\n"
        "    beq .L08133102\n"
        "    lsls r1, r1, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r0, r4\n"
        "    strh r2, [r0]\n"
        "    adds r1, #1\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        ".L08133102:\n"
        "    subs r0, r3, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L081330E4\n"
        "    b .L081331DA\n"
        "    .byte 0x00, 0x00\n"
        ".L08133110: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L08133114:\n"
        "    ldr r0, .L08133130\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #7\n"
        "    ldr r1, .L08133134\n"
        "    adds r0, r0, r1\n"
        ".L0813311E:\n"
        "    ldr r4, .L08133138\n"
        "    adds r1, r4, #0\n"
        "    bl Combatant_DecodeName\n"
        "    movs r0, #0\n"
        "    strh r0, [r4, #0x10]\n"
        "    movs r2, #1\n"
        "    mov sb, r2\n"
        "    b .L081331DA\n"
        ".L08133130: .4byte 0x03006850 @ IWRAM+0x6850\n"
        ".L08133134: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L08133138: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L0813313C:\n"
        "    movs r6, #0\n"
        "    ldr r4, .L08133188\n"
        "    ldr r3, .L0813318C\n"
        "    ldrh r1, [r3]\n"
        "    lsls r0, r1, #2\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, #2\n"
        "    adds r0, r0, r4\n"
        "    ldrh r2, [r0]\n"
        "    ldr r0, .L08133190\n"
        "    cmp r2, r0\n"
        "    beq .L081331DA\n"
        "    ldr r7, .L08133194\n"
        "    adds r5, r0, #0\n"
        ".L0813315A:\n"
        "    lsls r1, r6, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r0, r7\n"
        "    strh r2, [r0]\n"
        "    adds r1, #1\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r6, r1, #0x10\n"
        "    asrs r0, r1, #0x10\n"
        "    cmp r0, #9\n"
        "    bgt .L081331DA\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #1\n"
        "    ldrh r2, [r3]\n"
        "    lsls r1, r2, #2\n"
        "    adds r1, r1, r2\n"
        "    lsls r1, r1, #2\n"
        "    adds r0, r0, r1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r2, [r0]\n"
        "    cmp r2, r5\n"
        "    bne .L0813315A\n"
        "    b .L081331DA\n"
        ".L08133188: .4byte gUnknown_0878F9CC\n"
        ".L0813318C: .4byte 0x0203DB72 @ EWRAM+0x3DB72\n"
        ".L08133190: .4byte 0x00000301\n"
        ".L08133194: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L08133198:\n"
        "    movs r6, #0\n"
        "    ldr r3, .L08133228\n"
        "    mov r8, r3\n"
        "    ldr r0, .L0813322C\n"
        "    mov ip, r0\n"
        "    ldr r4, .L08133230\n"
        "    ldr r7, .L08133234\n"
        ".L081331A6:\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r5, r0, #0x10\n"
        "    lsls r3, r5, #1\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r7, r1]\n"
        "    lsls r0, r0, #1\n"
        "    add r0, ip\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r0, r2]\n"
        "    lsls r0, r1, #2\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r3, r0\n"
        "    add r0, r8\n"
        "    ldrh r2, [r0]\n"
        "    cmp r2, r4\n"
        "    beq .L081331DA\n"
        "    ldr r1, .L08133238\n"
        "    adds r0, r3, r1\n"
        "    strh r2, [r0]\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #9\n"
        "    ble .L081331A6\n"
        ".L081331DA:\n"
        "    mov r2, sb\n"
        "    cmp r2, #1\n"
        "    beq .L08133248\n"
        "    ldr r3, .L0813323C\n"
        "    mov ip, r3\n"
        "    ldr r0, .L08133240\n"
        "    mov sl, r0\n"
        "    cmp r2, #1\n"
        "    bgt .L08133296\n"
        "    cmp r2, #0\n"
        "    bne .L08133296\n"
        "    movs r6, #0xe\n"
        "    ldr r7, .L08133238\n"
        "    movs r5, #0xc6\n"
        "    lsls r5, r5, #2\n"
        ".L081331F8:\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r2, r0, #0x10\n"
        "    lsls r1, r2, #1\n"
        "    adds r1, r1, r7\n"
        "    ldrh r1, [r1]\n"
        "    adds r3, r0, #0\n"
        "    cmp r1, #0\n"
        "    beq .L0813321A\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #1\n"
        "    ldr r1, .L08133238\n"
        "    adds r0, r0, r1\n"
        "    ldrh r2, [r0]\n"
        "    cmp r2, #0\n"
        "    beq .L0813327A\n"
        "    cmp r2, r5\n"
        "    beq .L0813327A\n"
        ".L0813321A:\n"
        "    ldr r2, .L08133244\n"
        "    adds r0, r3, r2\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L081331F8\n"
        "    b .L08133296\n"
        "    .byte 0x00, 0x00\n"
        ".L08133228: .4byte gUnknown_0878EF04\n"
        ".L0813322C: .4byte 0x030069A0 @ IWRAM+0x69A0\n"
        ".L08133230: .4byte 0x00000301\n"
        ".L08133234: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L08133238: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L0813323C: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L08133240: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L08133244: .4byte 0xFFFF0000\n"
        ".L08133248:\n"
        "    movs r6, #0xe\n"
        "    ldr r3, .L08133280\n"
        "    mov ip, r3\n"
        "    ldr r0, .L08133284\n"
        "    mov sl, r0\n"
        "    ldr r7, .L08133288\n"
        "    movs r5, #0xc6\n"
        "    lsls r5, r5, #2\n"
        ".L08133258:\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r2, r0, #0x10\n"
        "    lsls r1, r2, #1\n"
        "    adds r1, r1, r7\n"
        "    ldrh r1, [r1]\n"
        "    adds r3, r0, #0\n"
        "    cmp r1, #0\n"
        "    beq .L0813328C\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #1\n"
        "    ldr r1, .L08133288\n"
        "    adds r0, r0, r1\n"
        "    ldrh r2, [r0]\n"
        "    cmp r2, #0\n"
        "    beq .L0813327A\n"
        "    cmp r2, r5\n"
        "    bne .L0813328C\n"
        ".L0813327A:\n"
        "    strh r5, [r0]\n"
        "    b .L08133296\n"
        "    .byte 0x00, 0x00\n"
        ".L08133280: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L08133284: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L08133288: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L0813328C:\n"
        "    ldr r2, .L081332B4\n"
        "    adds r0, r3, r2\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L08133258\n"
        ".L08133296:\n"
        "    ldr r3, .L081332B8\n"
        "    mov r0, sl\n"
        "    str r3, [r0]\n"
        "    movs r0, #0\n"
        "    mov r1, ip\n"
        "    strh r0, [r1]\n"
        "    add sp, #0x10\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L081332B4: .4byte 0xFFFF0000\n"
        ".L081332B8: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
    );
}
#endif
