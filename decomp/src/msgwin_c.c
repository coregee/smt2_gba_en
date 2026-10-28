/* Script message window: list windows (state reset and the entry table lookup). */

#include "global.h"
#include "bmenu2.h"

// sub_08130C38 @ 0x08130C38
void sub_08130C38(void)
{
    gUnk_03006848 = 0;
    gUnk_03006680 = 0;
}

// sub_08130C4C @ 0x08130C4C
void sub_08130C4C(struct Task *task)
{
    task->result = 0;
    gUnk_0300696C = 0;
    gUnk_03006940 = 0;
    gUnk_030068AC = 0;
}

/* Fills the five entries at 0x03006980: from table 0x0878FDEC (row = list top + cursor)
   when 0x030068D8 is 0xFF, else one entry looked up in the (limit, value) pairs at
   0x0878FDCC. */
// sub_08130C6C @ 0x08130C6C
#ifdef NONMATCHING
void sub_08130C6C(void)
{
    u16 i;
    u16 n;
    u16 v;

    gUnk_03006980[0] = 0xFFFF;
    gUnk_03006980[1] = -1;
    gUnk_03006980[2] = -1;
    gUnk_03006980[3] = -1;
    gUnk_03006980[4] = -1;
    v = gUnk_030068D8;
    if (v == 0xFF)
    {
        u16 row = gUnk_0300696C + gUnk_03006940;

        for (i = 0; i < 5; i++)
            gUnk_03006980[i] = gUnknown_0878FDEC[row * 5 + i];
    }
    else
    {
        n = gUnk_03006940 + (v - 0x120 + gUnk_0300696C);
        i = 0;
        while (n >= gUnknown_0878FDCC[i])
            i += 2;
        gUnk_03006980[0] = gUnknown_0878FDCC[i + 1];
    }
}
#else
NAKED
void sub_08130C6C(void)
{
    asm_unified(
        ".L08130C6C:\n"
        "    push {r4, r5, lr}\n"
        "    ldr r1, .L08130CBC\n"
        "    ldr r0, .L08130CC0\n"
        "    strh r0, [r1]\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    strh r0, [r1, #2]\n"
        "    strh r0, [r1, #4]\n"
        "    strh r0, [r1, #6]\n"
        "    strh r0, [r1, #8]\n"
        "    ldr r0, .L08130CC4\n"
        "    ldrh r2, [r0]\n"
        "    adds r5, r1, #0\n"
        "    cmp r2, #0xff\n"
        "    bne .L08130CD4\n"
        "    ldr r1, .L08130CC8\n"
        "    ldr r0, .L08130CCC\n"
        "    ldrh r0, [r0]\n"
        "    ldrh r1, [r1]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    movs r2, #0\n"
        "    ldr r4, .L08130CD0\n"
        "    lsls r0, r1, #2\n"
        "    adds r3, r0, r1\n"
        ".L08130CA0:\n"
        "    lsls r1, r2, #1\n"
        "    adds r1, r1, r5\n"
        "    adds r0, r3, r2\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r1]\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #4\n"
        "    bls .L08130CA0\n"
        "    b .L08130D0E\n"
        "    .byte 0x00, 0x00\n"
        ".L08130CBC: .4byte 0x03006980 @ IWRAM+0x6980\n"
        ".L08130CC0: .4byte 0x0000FFFF\n"
        ".L08130CC4: .4byte 0x030068D8 @ IWRAM+0x68D8\n"
        ".L08130CC8: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L08130CCC: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08130CD0: .4byte gUnknown_0878FDEC\n"
        ".L08130CD4:\n"
        "    ldr r0, .L08130D14\n"
        "    ldr r3, .L08130D18\n"
        "    adds r1, r2, r3\n"
        "    ldrh r0, [r0]\n"
        "    adds r1, r1, r0\n"
        "    ldr r0, .L08130D1C\n"
        "    ldrh r0, [r0]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    movs r2, #0\n"
        "    ldr r3, .L08130D20\n"
        "    adds r4, r3, #0\n"
        "    ldrh r0, [r3]\n"
        "    cmp r1, r0\n"
        "    blo .L08130D04\n"
        ".L08130CF4:\n"
        "    adds r0, r2, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    lsls r0, r2, #1\n"
        "    adds r0, r0, r3\n"
        "    ldrh r0, [r0]\n"
        "    cmp r1, r0\n"
        "    bhs .L08130CF4\n"
        ".L08130D04:\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r5]\n"
        ".L08130D0E:\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L08130D14: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L08130D18: .4byte 0xFFFFFEE0\n"
        ".L08130D1C: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08130D20: .4byte gUnknown_0878FDCC\n"
    );
}
#endif
