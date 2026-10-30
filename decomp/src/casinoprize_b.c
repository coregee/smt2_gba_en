/* Casino prize draws (0x081397D8-0x081399EF): pick a reward entry from the tables by
   random roll, casino state (gShopItemIds[1..3] reused here) and table row. */

#include "global.h"
#include "scriptops2.h"

/* Entry: {kind, id0, count0, id1, count1}; kind 2 fills both display slots. */
// sub_081397D8 @ 0x081397D8
#ifdef NONMATCHING
u16 sub_081397D8(void)
{
    u32 x = Random_Byte();
    u16 r;
    u16 diff, row, off;
    u8 kind;

    x &= 0x1F;
    r = gUnknown_08790AE6[x];
    if (gShopItemIds[3] == r)
    {
        if (r == 9)
            r = 0;
        else
            r++;
    }
    gShopItemIds[3] = r;
    r *= 5;
    diff = gShopItemIds[1];
    row = (u16)(gShopItemIds[2] - 1) >> 1;
    off = 0;
    if (diff != 0)
    {
        off = 100;
        if (diff == 1)
            off = 50;
    }
    r = off + r;
    kind = gUnknown_0879050A[row][r];
    gUnk_0203DB28[0] = gUnknown_0879050A[row][r + 1];
    gUnk_0203DB2C = gUnk_03006970[0] = gUnknown_0879050A[row][r + 2];
    gUnk_0203DB66 = 1;
    if (kind == 2)
    {
        gUnk_0203DB28[1] = gUnknown_0879050A[row][r + 3];
        gUnk_0203DB30 = gUnk_03006970[1] = gUnknown_0879050A[row][r + 4];
        gUnk_0203DB68 = 1;
    }
    return kind;
}
#else
NAKED
u16 sub_081397D8(void)
{
    asm_unified(
        ".L081397D8:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    bl Random_Byte\n"
        "    movs r1, #0x1f\n"
        "    ands r0, r1\n"
        "    ldr r1, .L08139800\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r1\n"
        "    ldrh r2, [r0]\n"
        "    ldr r0, .L08139804\n"
        "    ldrh r0, [r0, #6]\n"
        "    cmp r0, r2\n"
        "    bne .L0813980E\n"
        "    cmp r2, #9\n"
        "    bne .L08139808\n"
        "    movs r2, #0\n"
        "    b .L0813980E\n"
        "    .byte 0x00, 0x00\n"
        ".L08139800: .4byte gUnknown_08790AE6\n"
        ".L08139804: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L08139808:\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        ".L0813980E:\n"
        "    ldr r0, .L081398A4\n"
        "    strh r2, [r0, #6]\n"
        "    lsls r1, r2, #2\n"
        "    adds r1, r1, r2\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r2, r1, #0x10\n"
        "    ldrh r1, [r0, #2]\n"
        "    ldrh r0, [r0, #4]\n"
        "    subs r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x11\n"
        "    movs r3, #0\n"
        "    cmp r1, #0\n"
        "    beq .L08139832\n"
        "    movs r3, #0x64\n"
        "    cmp r1, #1\n"
        "    bne .L08139832\n"
        "    movs r3, #0x32\n"
        ".L08139832:\n"
        "    adds r0, r3, r2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    ldr r4, .L081398A8\n"
        "    movs r0, #0x96\n"
        "    adds r2, r5, #0\n"
        "    muls r2, r0, r2\n"
        "    adds r0, r3, r2\n"
        "    adds r0, r0, r4\n"
        "    ldrb r0, [r0]\n"
        "    adds r6, r0, #0\n"
        "    adds r0, r2, #1\n"
        "    adds r0, r3, r0\n"
        "    adds r0, r0, r4\n"
        "    ldrb r0, [r0]\n"
        "    ldr r1, .L081398AC\n"
        "    mov r8, r1\n"
        "    strh r0, [r1]\n"
        "    adds r0, r2, #2\n"
        "    adds r0, r3, r0\n"
        "    adds r0, r0, r4\n"
        "    ldrb r0, [r0]\n"
        "    ldr r1, .L081398B0\n"
        "    ldr r5, .L081398B4\n"
        "    mov ip, r5\n"
        "    strh r0, [r5]\n"
        "    ldr r7, .L081398B8\n"
        "    adds r5, r7, #0\n"
        "    str r0, [r1]\n"
        "    ldr r0, .L081398BC\n"
        "    movs r7, #1\n"
        "    strh r7, [r0]\n"
        "    cmp r6, #2\n"
        "    bne .L08139898\n"
        "    adds r0, r2, #3\n"
        "    adds r0, r3, r0\n"
        "    adds r0, r0, r4\n"
        "    ldrb r0, [r0]\n"
        "    mov r1, r8\n"
        "    strh r0, [r1, #2]\n"
        "    adds r0, r2, #4\n"
        "    adds r0, r3, r0\n"
        "    adds r0, r0, r4\n"
        "    ldrb r0, [r0]\n"
        "    ldr r1, .L081398C0\n"
        "    mov r2, ip\n"
        "    strh r0, [r2, #2]\n"
        "    ands r0, r5\n"
        "    str r0, [r1]\n"
        "    ldr r0, .L081398C4\n"
        "    strh r7, [r0]\n"
        ".L08139898:\n"
        "    adds r0, r6, #0\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        ".L081398A4: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L081398A8: .4byte gUnknown_0879050A\n"
        ".L081398AC: .4byte 0x0203DB28 @ EWRAM+0x3DB28\n"
        ".L081398B0: .4byte 0x0203DB2C @ EWRAM+0x3DB2C\n"
        ".L081398B4: .4byte 0x03006970 @ IWRAM+0x6970\n"
        ".L081398B8: .4byte 0x0000FFFF\n"
        ".L081398BC: .4byte 0x0203DB66 @ EWRAM+0x3DB66\n"
        ".L081398C0: .4byte 0x0203DB30 @ EWRAM+0x3DB30\n"
        ".L081398C4: .4byte 0x0203DB68 @ EWRAM+0x3DB68\n"
    );
}
#endif

// sub_081398C8 @ 0x081398C8
#ifdef NONMATCHING
u16 sub_081398C8(void)
{
    u32 x = Random_Byte();
    u16 r;
    u16 diff, row, off;
    u8 kind;

    x &= 0x1F;
    r = gUnknown_08790AE6[x] * 5;
    diff = gShopItemIds[1];
    row = gShopItemIds[2] - 1;
    off = 0;
    if (diff != 0)
    {
        off = 100;
        if (diff == 1)
            off = 50;
    }
    r = off + r;
    kind = gUnknown_087907F8[row][r];
    gUnk_0203DB28[0] = gUnknown_087907F8[row][r + 1];
    gUnk_0203DB2C = gUnk_03006970[0] = gUnknown_087907F8[row][r + 2];
    gUnk_0203DB66 = 1;
    if (kind == 2)
    {
        gUnk_0203DB28[1] = gUnknown_087907F8[row][r + 3];
        gUnk_0203DB30 = gUnk_03006970[1] = gUnknown_087907F8[row][r + 4];
        gUnk_0203DB68 = 1;
    }
    return kind;
}
#else
NAKED
u16 sub_081398C8(void)
{
    asm_unified(
        ".L081398C8:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    bl Random_Byte\n"
        "    movs r1, #0x1f\n"
        "    ands r0, r1\n"
        "    ldr r1, .L08139974\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r1\n"
        "    ldrh r1, [r0]\n"
        "    lsls r0, r1, #2\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    ldr r0, .L08139978\n"
        "    ldrh r2, [r0, #2]\n"
        "    ldrh r0, [r0, #4]\n"
        "    subs r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    movs r3, #0\n"
        "    cmp r2, #0\n"
        "    beq .L08139900\n"
        "    movs r3, #0x64\n"
        "    cmp r2, #1\n"
        "    bne .L08139900\n"
        "    movs r3, #0x32\n"
        ".L08139900:\n"
        "    adds r0, r3, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    ldr r4, .L0813997C\n"
        "    movs r0, #0x96\n"
        "    adds r2, r5, #0\n"
        "    muls r2, r0, r2\n"
        "    adds r0, r3, r2\n"
        "    adds r0, r0, r4\n"
        "    ldrb r0, [r0]\n"
        "    adds r6, r0, #0\n"
        "    adds r0, r2, #1\n"
        "    adds r0, r3, r0\n"
        "    adds r0, r0, r4\n"
        "    ldrb r0, [r0]\n"
        "    ldr r1, .L08139980\n"
        "    mov r8, r1\n"
        "    strh r0, [r1]\n"
        "    adds r0, r2, #2\n"
        "    adds r0, r3, r0\n"
        "    adds r0, r0, r4\n"
        "    ldrb r0, [r0]\n"
        "    ldr r1, .L08139984\n"
        "    ldr r5, .L08139988\n"
        "    mov ip, r5\n"
        "    strh r0, [r5]\n"
        "    ldr r7, .L0813998C\n"
        "    adds r5, r7, #0\n"
        "    str r0, [r1]\n"
        "    ldr r0, .L08139990\n"
        "    movs r7, #1\n"
        "    strh r7, [r0]\n"
        "    cmp r6, #2\n"
        "    bne .L08139966\n"
        "    adds r0, r2, #3\n"
        "    adds r0, r3, r0\n"
        "    adds r0, r0, r4\n"
        "    ldrb r0, [r0]\n"
        "    mov r1, r8\n"
        "    strh r0, [r1, #2]\n"
        "    adds r0, r2, #4\n"
        "    adds r0, r3, r0\n"
        "    adds r0, r0, r4\n"
        "    ldrb r0, [r0]\n"
        "    ldr r1, .L08139994\n"
        "    mov r2, ip\n"
        "    strh r0, [r2, #2]\n"
        "    ands r0, r5\n"
        "    str r0, [r1]\n"
        "    ldr r0, .L08139998\n"
        "    strh r7, [r0]\n"
        ".L08139966:\n"
        "    adds r0, r6, #0\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L08139974: .4byte gUnknown_08790AE6\n"
        ".L08139978: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L0813997C: .4byte gUnknown_087907F8\n"
        ".L08139980: .4byte 0x0203DB28 @ EWRAM+0x3DB28\n"
        ".L08139984: .4byte 0x0203DB2C @ EWRAM+0x3DB2C\n"
        ".L08139988: .4byte 0x03006970 @ IWRAM+0x6970\n"
        ".L0813998C: .4byte 0x0000FFFF\n"
        ".L08139990: .4byte 0x0203DB66 @ EWRAM+0x3DB66\n"
        ".L08139994: .4byte 0x0203DB30 @ EWRAM+0x3DB30\n"
        ".L08139998: .4byte 0x0203DB68 @ EWRAM+0x3DB68\n"
    );
}
#endif

// sub_0813999C @ 0x0813999C
void sub_0813999C(u16 k)
{
    u16 diff = gShopItemIds[1];
    u32 n;

    if (k == 3)
    {
        u16 i = gShopItemIds[2];
        u16 id = gUnknown_08790B26[i];

        gUnk_0203DB28[0] = id;
        n = 8;
        if (diff != 0)
        {
            n = 2;
            if (diff == 1)
                n = 4;
        }
        gUnk_0203DB2C = gUnk_03006970[0] = n;
        gUnk_0203DB66 = 1;
    }
}
