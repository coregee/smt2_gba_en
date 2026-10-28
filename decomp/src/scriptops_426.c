/* Script VM opcode handler 0x426. */

#include "global.h"
#include "scriptops2.h"

/* Sets up the event scene for gUnk_03006914 (0x1xx): the hero sprite, and up to four
   characters from the first entry of the scene list whose flag is set (0xFF = default).
   Entry: {flag, (id, target lo, target hi) ..., 0xFF}; ids go to gUnk_03006990,
   targets to gUnk_0203DAC8[10 + n]. */
// ScriptOp_426 @ 0x0813A020
#ifdef NONMATCHING
void ScriptOp_426(void)
{
    u16 c, i, n, k;
    u16 x;
    u16 f;
    u16 *list;
    u16 *e;
    u16 lo, hi;

    for (c = 0; c < 16; c++)
        gUnk_0203DAC8[c] = 0;
    if (gUnk_03006914 & 0xFF00)
    {
        if (gUnk_03006914 == 0x104)
            gUnk_030068F0[0] = sub_080C4618(0, 0x15, 0x50, 3, 0, 0);
        else if (gUnk_03006914 > 0x104)
            gUnk_030068F0[0] = sub_080C4618(0, 0xEF, 0x50, 3, 0, 0);
        else
            gUnk_030068F0[0] = sub_080C4618(0, 10, 0x50, 3, 0, 0);
        gUnk_03006990[0] = gUnk_03006990[1] = gUnk_03006990[2] = gUnk_03006990[3]
            = gUnk_03006990[4] = 0xFFFF;
        e = (u16 *)&gUnknown_08035BB8[(u8)gUnk_03006914 * 2];
        list = (u16 *)(e[1] << 16 | e[0]);
        i = 0;
    next:
        e = &list[i * 2];
        e = (u16 *)(e[1] << 16 | e[0]);
        f = e[0];
        if (Flag_Test(f) == 1 || f == 0xFF)
        {
            for (i = 1, n = 0; e[i] != 0xFF; n++)
            {
                gUnk_03006990[n] = e[i++];
                lo = e[i++];
                hi = e[i++];
                gUnk_0203DAC8[n + 10] = (u16 *)(hi << 16 | lo);
            }
        }
        else
        {
            i++;
            goto next;
        }
        k = 0;
        if ((u8)gUnk_03006990[0] != 0xFF)
        {
            do
            {
                if (++k > 3)
                    break;
            } while ((gUnk_03006990[k] & 0xFF) != 0xFF);
        }
        for (i = 0; i < 4; i++)
        {
            if ((u8)gUnk_03006990[i] != 0xFF)
                gUnk_030068F0[i + 1] = sub_080C4618(i + 1, gUnknown_08790C9A[gUnk_03006990[i]],
                                                    gUnknown_08790C8A[(k - 1) * 4 + i], 0, 0, 0);
        }
    }
    if (gUnk_03006914 <= 0x103)
        x = 8;
    else
    {
        x = 0x57;
        if (gUnk_03006914 == 0x104)
            x = 0x12;
    }
    gUnk_030068B0 = BgPicture_StartTask(x);
    gScriptWaitState = 2;
    gScriptYield = 1;
}
#else
NAKED
void ScriptOp_426(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    sub sp, #8\n"
        "    movs r1, #0\n"
        "    ldr r3, .L0813A064\n"
        "    movs r2, #0\n"
        ".L0813A02E:\n"
        "    lsls r0, r1, #2\n"
        "    adds r0, r0, r3\n"
        "    str r2, [r0]\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    cmp r1, #0xf\n"
        "    bls .L0813A02E\n"
        "    ldr r0, .L0813A068\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0xff\n"
        "    lsls r0, r0, #8\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L0813A04E\n"
        "    b .L0813A1C2\n"
        ".L0813A04E:\n"
        "    adds r0, r1, #0\n"
        "    movs r1, #0x82\n"
        "    lsls r1, r1, #1\n"
        "    cmp r0, r1\n"
        "    bne .L0813A06C\n"
        "    movs r0, #0\n"
        "    str r0, [sp]\n"
        "    str r0, [sp, #4]\n"
        "    movs r1, #0x15\n"
        "    b .L0813A082\n"
        "    .byte 0x00, 0x00\n"
        ".L0813A064: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8\n"
        ".L0813A068: .4byte 0x03006914 @ IWRAM+0x6914\n"
        ".L0813A06C:\n"
        "    cmp r0, r1\n"
        "    bls .L0813A07A\n"
        "    movs r0, #0\n"
        "    str r0, [sp]\n"
        "    str r0, [sp, #4]\n"
        "    movs r1, #0xef\n"
        "    b .L0813A082\n"
        ".L0813A07A:\n"
        "    movs r0, #0\n"
        "    str r0, [sp]\n"
        "    str r0, [sp, #4]\n"
        "    movs r1, #0xa\n"
        ".L0813A082:\n"
        "    movs r2, #0x50\n"
        "    movs r3, #3\n"
        "    bl sub_080C4618\n"
        "    ldr r1, .L0813A134\n"
        "    str r0, [r1]\n"
        "    ldr r1, .L0813A138\n"
        "    ldr r0, .L0813A13C\n"
        "    strh r0, [r1, #8]\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    strh r0, [r1, #6]\n"
        "    strh r0, [r1, #4]\n"
        "    strh r0, [r1, #2]\n"
        "    strh r0, [r1]\n"
        "    ldr r7, .L0813A140\n"
        "    ldr r0, .L0813A144\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r0, r7\n"
        "    ldrh r2, [r0]\n"
        "    ldrh r1, [r0, #2]\n"
        "    lsls r7, r1, #0x10\n"
        "    orrs r7, r2\n"
        "    movs r6, #0\n"
        ".L0813A0B4:\n"
        "    lsls r0, r6, #2\n"
        "    adds r0, r0, r7\n"
        "    ldrh r2, [r0]\n"
        "    ldrh r1, [r0, #2]\n"
        "    lsls r5, r1, #0x10\n"
        "    orrs r5, r2\n"
        "    ldrh r4, [r5]\n"
        "    adds r0, r4, #0\n"
        "    bl Flag_Test\n"
        "    cmp r0, #1\n"
        "    beq .L0813A0D0\n"
        "    cmp r4, #0xff\n"
        "    bne .L0813A14C\n"
        ".L0813A0D0:\n"
        "    movs r6, #1\n"
        "    movs r4, #0\n"
        "    ldrh r0, [r5, #2]\n"
        "    ldr r1, .L0813A138\n"
        "    mov r8, r1\n"
        "    cmp r0, #0xff\n"
        "    beq .L0813A154\n"
        "    mov ip, r8\n"
        "    ldr r7, .L0813A148\n"
        ".L0813A0E2:\n"
        "    lsls r3, r4, #1\n"
        "    add r3, ip\n"
        "    adds r1, r6, #0\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    adds r2, r6, #0\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r5\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r3]\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    adds r1, r6, #0\n"
        "    lsls r2, r2, #1\n"
        "    adds r2, r2, r5\n"
        "    ldrh r2, [r2]\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r5\n"
        "    ldrh r1, [r1]\n"
        "    lsls r1, r1, #0x10\n"
        "    orrs r1, r2\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0xa\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r0, r7\n"
        "    str r1, [r0]\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    lsls r0, r6, #1\n"
        "    adds r0, r0, r5\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0xff\n"
        "    bne .L0813A0E2\n"
        "    b .L0813A154\n"
        "    .byte 0x00, 0x00\n"
        ".L0813A134: .4byte 0x030068F0 @ IWRAM+0x68F0\n"
        ".L0813A138: .4byte 0x03006990 @ IWRAM+0x6990\n"
        ".L0813A13C: .4byte 0x0000FFFF\n"
        ".L0813A140: .4byte gUnknown_08035BB8\n"
        ".L0813A144: .4byte 0x03006914 @ IWRAM+0x6914\n"
        ".L0813A148: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8\n"
        ".L0813A14C:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    b .L0813A0B4\n"
        ".L0813A154:\n"
        "    movs r3, #0\n"
        "    mov r1, r8\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0xff\n"
        "    beq .L0813A17A\n"
        "    mov r2, r8\n"
        "    movs r4, #0xff\n"
        ".L0813A162:\n"
        "    adds r0, r3, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    cmp r3, #3\n"
        "    bhi .L0813A17A\n"
        "    lsls r0, r3, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r1, [r0]\n"
        "    adds r0, r4, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0xff\n"
        "    bne .L0813A162\n"
        ".L0813A17A:\n"
        "    movs r2, #0\n"
        "    ldr r0, .L0813A1D0\n"
        "    mov r8, r0\n"
        "    movs r5, #0\n"
        "    subs r0, r3, #1\n"
        "    lsls r7, r0, #2\n"
        ".L0813A186:\n"
        "    ldr r1, .L0813A1D4\n"
        "    lsls r0, r2, #1\n"
        "    adds r0, r0, r1\n"
        "    ldrb r6, [r0]\n"
        "    adds r4, r2, #1\n"
        "    cmp r6, #0xff\n"
        "    beq .L0813A1BA\n"
        "    ldr r1, .L0813A1D8\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r1\n"
        "    ldrh r1, [r0]\n"
        "    adds r0, r7, r2\n"
        "    add r0, r8\n"
        "    ldrb r2, [r0]\n"
        "    lsls r0, r4, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r5, [sp]\n"
        "    str r5, [sp, #4]\n"
        "    movs r3, #0\n"
        "    bl sub_080C4618\n"
        "    ldr r2, .L0813A1DC\n"
        "    lsls r1, r4, #2\n"
        "    adds r1, r1, r2\n"
        "    str r0, [r1]\n"
        ".L0813A1BA:\n"
        "    lsls r0, r4, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #3\n"
        "    bls .L0813A186\n"
        ".L0813A1C2:\n"
        "    ldr r0, .L0813A1E0\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L0813A1E4\n"
        "    cmp r1, r0\n"
        "    bhi .L0813A1E8\n"
        "    movs r6, #8\n"
        "    b .L0813A1F4\n"
        ".L0813A1D0: .4byte gUnknown_08790C8A\n"
        ".L0813A1D4: .4byte 0x03006990 @ IWRAM+0x6990\n"
        ".L0813A1D8: .4byte gUnknown_08790C9A\n"
        ".L0813A1DC: .4byte 0x030068F0 @ IWRAM+0x68F0\n"
        ".L0813A1E0: .4byte 0x03006914 @ IWRAM+0x6914\n"
        ".L0813A1E4: .4byte 0x00000103\n"
        ".L0813A1E8:\n"
        "    movs r0, #0x82\n"
        "    lsls r0, r0, #1\n"
        "    movs r6, #0x57\n"
        "    cmp r1, r0\n"
        "    bne .L0813A1F4\n"
        "    movs r6, #0x12\n"
        ".L0813A1F4:\n"
        "    adds r0, r6, #0\n"
        "    bl BgPicture_StartTask\n"
        "    ldr r1, .L0813A218\n"
        "    str r0, [r1]\n"
        "    ldr r1, .L0813A21C\n"
        "    movs r0, #2\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L0813A220\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    add sp, #8\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L0813A218: .4byte 0x030068B0 @ IWRAM+0x68B0\n"
        ".L0813A21C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L0813A220: .4byte 0x0203DB6E @ EWRAM+0x3DB6E\n"
    );
}
#endif
