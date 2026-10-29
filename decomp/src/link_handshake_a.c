#include "global.h"
#include "options.h"

extern u8 gUnk_030062F0;

/* Link handshake (state gUnk_030062F0): in state 1, once the serial status gUnk_03006360 has
   bit 8 (and not bit 13), sends packet 0xC100 followed by the 8-byte id; in state 2, after
   sub_080DF6FC(0xC100) reports the reply, compares the id with the 8 bytes at +2 of the two
   16-byte receive slots at gUnk_03006340 and returns 1 when both are equal (NONMATCHING:
   id/pointer/counter get r6/r4/r5 instead of r4/r5/r6). */
// Link_ExchangeIds @ 0x080DF388
#ifdef NONMATCHING
u8 Link_ExchangeIds(u32 arg)
{
    u8 *id = (u8 *)arg;
    u8 diff[4];
    u8 i, j;
    u8 ret = 0;
    u8 *dst;

    switch (gUnk_030062F0)
    {
    case 0:
        break;
    case 1:
        if (gUnk_03006360 & 0x2000)
            return 0;
        if (gUnk_03006360 & 0x100)
        {
            gUnk_030062F0 = 2;
            gUnk_03006380[0] = 0xC100;
            dst = (u8 *)&gUnk_03006380[1];
            for (j = 0; j < 8; j++)
                *dst++ = *id++;
        }
        break;
    case 2:
        if (sub_080DF6FC(0xC100) == 1)
        {
            diff[0] = diff[1] = diff[2] = diff[3] = ret;
            for (i = 0; i < 2; i++)
            {
                dst = gUnk_03006340[i].data;
                diff[i] = 0;
                for (j = 0; j < 8; j++)
                {
                    if (id[j] != dst[j])
                        diff[i] = 1;
                }
            }
            if (diff[0] == 0 && diff[1] == 0 && diff[2] == 0 && diff[3] == 0)
            {
                ret = 1;
                gUnk_03006380[0] = 0;
            }
        }
        break;
    }
    return ret;
}
#else
NAKED
u8 Link_ExchangeIds(u32 arg)
{
    asm_unified(
        ".L080DF388:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    sub sp, #4\n"
        "    adds r4, r0, #0\n"
        "    movs r0, #0\n"
        "    mov r8, r0\n"
        "    ldr r2, .L080DF3A8\n"
        "    ldrb r0, [r2]\n"
        "    cmp r0, #1\n"
        "    beq .L080DF3AC\n"
        "    cmp r0, #1\n"
        "    ble .L080DF480\n"
        "    cmp r0, #2\n"
        "    beq .L080DF3F8\n"
        "    b .L080DF480\n"
        ".L080DF3A8: .4byte 0x030062F0 @ IWRAM+0x62F0\n"
        ".L080DF3AC:\n"
        "    ldr r0, .L080DF3C0\n"
        "    ldr r1, [r0]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #6\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080DF3C4\n"
        "    movs r0, #0\n"
        "    b .L080DF482\n"
        "    .byte 0x00, 0x00\n"
        ".L080DF3C0: .4byte 0x03006360 @ IWRAM+0x6360\n"
        ".L080DF3C4:\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080DF480\n"
        "    movs r0, #2\n"
        "    strb r0, [r2]\n"
        "    ldr r1, .L080DF3F4\n"
        "    movs r0, #0xc1\n"
        "    lsls r0, r0, #8\n"
        "    strh r0, [r1]\n"
        "    adds r5, r1, #2\n"
        "    movs r2, #0\n"
        ".L080DF3DE:\n"
        "    ldrb r0, [r4]\n"
        "    strb r0, [r5]\n"
        "    adds r4, #1\n"
        "    adds r5, #1\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r2, r0, #0x18\n"
        "    cmp r2, #7\n"
        "    bls .L080DF3DE\n"
        "    b .L080DF480\n"
        "    .byte 0x00, 0x00\n"
        ".L080DF3F4: .4byte 0x03006380 @ IWRAM+0x6380\n"
        ".L080DF3F8:\n"
        "    movs r0, #0xc1\n"
        "    lsls r0, r0, #8\n"
        "    bl sub_080DF6FC\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bne .L080DF480\n"
        "    mov r3, sp\n"
        "    mov r2, sp\n"
        "    mov r1, sp\n"
        "    mov r0, sp\n"
        "    mov r5, r8\n"
        "    strb r5, [r0, #3]\n"
        "    strb r5, [r1, #2]\n"
        "    strb r5, [r2, #1]\n"
        "    strb r5, [r3]\n"
        "    movs r3, #0\n"
        "    ldr r0, .L080DF490\n"
        "    mov ip, r0\n"
        "    movs r7, #1\n"
        ".L080DF422:\n"
        "    lsls r0, r3, #4\n"
        "    mov r1, ip\n"
        "    adds r5, r0, r1\n"
        "    mov r0, sp\n"
        "    adds r1, r0, r3\n"
        "    movs r0, #0\n"
        "    strb r0, [r1]\n"
        "    movs r2, #0\n"
        "    adds r6, r3, #1\n"
        "    adds r3, r1, #0\n"
        ".L080DF436:\n"
        "    adds r0, r4, r2\n"
        "    adds r1, r5, r2\n"
        "    ldrb r0, [r0]\n"
        "    ldrb r1, [r1]\n"
        "    cmp r0, r1\n"
        "    beq .L080DF444\n"
        "    strb r7, [r3]\n"
        ".L080DF444:\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r2, r0, #0x18\n"
        "    cmp r2, #7\n"
        "    bls .L080DF436\n"
        "    lsls r0, r6, #0x18\n"
        "    lsrs r3, r0, #0x18\n"
        "    cmp r3, #1\n"
        "    bls .L080DF422\n"
        "    mov r0, sp\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L080DF480\n"
        "    mov r0, sp\n"
        "    ldrb r0, [r0, #1]\n"
        "    cmp r0, #0\n"
        "    bne .L080DF480\n"
        "    mov r0, sp\n"
        "    ldrb r0, [r0, #2]\n"
        "    cmp r0, #0\n"
        "    bne .L080DF480\n"
        "    mov r0, sp\n"
        "    ldrb r0, [r0, #3]\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #0\n"
        "    bne .L080DF480\n"
        "    movs r5, #1\n"
        "    mov r8, r5\n"
        "    ldr r0, .L080DF494\n"
        "    strh r1, [r0]\n"
        ".L080DF480:\n"
        "    mov r0, r8\n"
        ".L080DF482:\n"
        "    add sp, #4\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L080DF490: .4byte 0x03006342 @ IWRAM+0x6342\n"
        ".L080DF494: .4byte 0x03006380 @ IWRAM+0x6380\n"
    );
}
#endif
