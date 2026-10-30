#include "global.h"
#include "title.h"

/* Opening sequence steps (task callbacks); task data bytes 0x24.. are counters. */

/* NONMATCHING: the x offset -50 is loaded as a 16-bit 0xFFCE and sign-extended at run time, and the task lives in r3 (register allocation) */
// sub_080D6EA0 @ 0x080D6EA0
#ifdef NONMATCHING
void sub_080D6EA0(struct Task *task)
{
    if (task->data.raw[1] != 0)
    {
        task->data.raw[1]--;
        return;
    }
    if (gKeysNew & 8)
    {
        task->unk1E = 1;
        return;
    }
    if (task->data.raw[2] != 0)
    {
        task->data.raw[2]--;
    }
    else
    {
        task->data.raw[2] = 3;
        task->data.raw[0]--;
    }
    if (task->data.raw[0] == 0)
    {
        task->result = 1;
        return;
    }
    Sprite_Draw(gUnknown_0813EC98, 0, 0, 0, 0, -50 + task->data.raw[0], 0);
}
#else
NAKED
void sub_080D6EA0(struct Task *task)
{
    asm_unified(
        "    push {lr}\n"
        "    sub sp, #0xc\n"
        "    adds r3, r0, #0\n"
        "    adds r1, r3, #0\n"
        "    adds r1, #0x25\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0\n"
        "    beq .L080D6EB6\n"
        "    subs r0, #1\n"
        "    strb r0, [r1]\n"
        "    b .L080D6F1C\n"
        ".L080D6EB6:\n"
        "    ldr r0, .L080D6EC8\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #8\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080D6ECC\n"
        "    movs r0, #1\n"
        "    strh r0, [r3, #0x1e]\n"
        "    b .L080D6F1C\n"
        ".L080D6EC8: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L080D6ECC:\n"
        "    adds r1, r3, #0\n"
        "    adds r1, #0x26\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0\n"
        "    beq .L080D6EE0\n"
        "    subs r0, #1\n"
        "    strb r0, [r1]\n"
        "    adds r2, r3, #0\n"
        "    adds r2, #0x24\n"
        "    b .L080D6EF0\n"
        ".L080D6EE0:\n"
        "    movs r0, #3\n"
        "    strb r0, [r1]\n"
        "    adds r1, r3, #0\n"
        "    adds r1, #0x24\n"
        "    ldrb r0, [r1]\n"
        "    subs r0, #1\n"
        "    strb r0, [r1]\n"
        "    adds r2, r1, #0\n"
        ".L080D6EF0:\n"
        "    ldrb r0, [r2]\n"
        "    cmp r0, #0\n"
        "    bne .L080D6EFC\n"
        "    movs r0, #1\n"
        "    strh r0, [r3, #0x1c]\n"
        "    b .L080D6F1C\n"
        ".L080D6EFC:\n"
        "    ldr r1, .L080D6F24\n"
        "    lsls r1, r1, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    ldrb r2, [r2]\n"
        "    adds r1, r1, r2\n"
        "    ldr r0, .L080D6F28\n"
        "    movs r2, #0\n"
        "    str r2, [sp]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #4]\n"
        "    str r2, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L080D6F1C:\n"
        "    add sp, #0xc\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080D6F24: .4byte 0x0000FFCE\n"
        ".L080D6F28: .4byte gUnknown_0813EC98\n"
    );
}
#endif

// sub_080D6F2C @ 0x080D6F2C
void sub_080D6F2C(struct Task *task)
{
    gUnk_03000030 = 0xF0;
    gUnk_03000031 = 0;
    gUnk_03000034 = 0x96;
    gUnk_03000035 = 0x70;
    gUnk_0300003A &= 0xEF;
    task->data.raw[0] = 0xA0;
    task->data.raw[2] = 3;
    task->data.raw[1] = 8;
    task->data.raw[3] = 1;
    task->result = 0;
    task->data.raw[4] = 0;
    task->data.raw[5] = 0;
}

/* NONMATCHING: 4 lines off: the second y step (s16 v + 0x40) builds the 0x400000 constant in r0 instead of r1 */
// sub_080D6F90 @ 0x080D6F90
#ifdef NONMATCHING
void sub_080D6F90(struct Task *task)
{
    u32 y;
    s16 v;

    if (gKeysNew & 8)
    {
        task->unk1E = 1;
        return;
    }
    if (task->data.raw[1] != 0)
    {
        task->data.raw[1]--;
        return;
    }
    if (task->data.raw[2] != 0)
    {
        task->data.raw[2]--;
    }
    else
    {
        task->data.raw[2] = 3;
        task->data.raw[0]--;
        if (task->data.raw[4] != 0xFF)
        {
            task->data.raw[4]++;
        }
        else if (++task->data.raw[5] == 0x40)
        {
            task->result = 1;
            return;
        }
    }
    y = task->data.raw[0];
    if ((s8)task->data.raw[4] >= 0)
        Sprite_Draw(gUnknown_0813ECB4, 0, 0, 0, 0, 0x78, y);
    v = y + 0x40;
    v &= 0xFF;
    Sprite_Draw(gUnknown_0813ECD0, 0, 0, 0, 0, 0x78, v);
    if (task->data.raw[4] > 0x40)
    {
        v += 0x40;
        v &= 0xFF;
        Sprite_Draw(gUnknown_0813ECEC, 0, 0, 0, 0, 0x78, v);
        v += 0x40;
        v &= 0xFF;
        Sprite_Draw(gUnknown_0813ED2C, 0, 0, 0, 0, 0x78, v);
    }
}
#else
NAKED
void sub_080D6F90(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    sub sp, #0xc\n"
        "    adds r3, r0, #0\n"
        "    ldr r0, .L080D6FAC\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #8\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080D6FB0\n"
        "    movs r0, #1\n"
        "    strh r0, [r3, #0x1e]\n"
        "    b .L080D7096\n"
        ".L080D6FAC: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L080D6FB0:\n"
        "    adds r1, r3, #0\n"
        "    adds r1, #0x25\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0\n"
        "    beq .L080D6FC0\n"
        "    subs r0, #1\n"
        "    strb r0, [r1]\n"
        "    b .L080D7096\n"
        ".L080D6FC0:\n"
        "    adds r1, r3, #0\n"
        "    adds r1, #0x26\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0\n"
        "    beq .L080D6FD6\n"
        "    subs r0, #1\n"
        "    strb r0, [r1]\n"
        "    subs r1, #2\n"
        "    adds r5, r3, #0\n"
        "    adds r5, #0x28\n"
        "    b .L080D7010\n"
        ".L080D6FD6:\n"
        "    movs r0, #3\n"
        "    strb r0, [r1]\n"
        "    adds r1, r3, #0\n"
        "    adds r1, #0x24\n"
        "    ldrb r0, [r1]\n"
        "    subs r0, #1\n"
        "    strb r0, [r1]\n"
        "    adds r0, r3, #0\n"
        "    adds r0, #0x28\n"
        "    ldrb r4, [r0]\n"
        "    adds r2, r4, #0\n"
        "    adds r5, r0, #0\n"
        "    cmp r2, #0xff\n"
        "    beq .L080D6FF8\n"
        "    adds r0, r4, #1\n"
        "    strb r0, [r5]\n"
        "    b .L080D7010\n"
        ".L080D6FF8:\n"
        "    adds r2, r3, #0\n"
        "    adds r2, #0x29\n"
        "    ldrb r0, [r2]\n"
        "    adds r0, #1\n"
        "    strb r0, [r2]\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #0x40\n"
        "    bne .L080D7010\n"
        "    movs r0, #1\n"
        "    strh r0, [r3, #0x1c]\n"
        "    b .L080D7096\n"
        ".L080D7010:\n"
        "    ldrb r4, [r1]\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r5, r0]\n"
        "    cmp r0, #0\n"
        "    blt .L080D7030\n"
        "    ldr r0, .L080D70A4\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    movs r1, #0x78\n"
        "    str r1, [sp, #4]\n"
        "    str r4, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L080D7030:\n"
        "    adds r1, r4, #0\n"
        "    adds r1, #0x40\n"
        "    movs r0, #0xff\n"
        "    mov r8, r0\n"
        "    ands r1, r0\n"
        "    ldr r0, .L080D70A8\n"
        "    movs r7, #0\n"
        "    str r7, [sp]\n"
        "    movs r6, #0x78\n"
        "    str r6, [sp, #4]\n"
        "    lsls r4, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    ldrb r0, [r5]\n"
        "    cmp r0, #0x40\n"
        "    bls .L080D7096\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #0xf\n"
        "    adds r0, r4, r1\n"
        "    asrs r1, r0, #0x10\n"
        "    mov r0, r8\n"
        "    ands r1, r0\n"
        "    ldr r0, .L080D70AC\n"
        "    str r7, [sp]\n"
        "    str r6, [sp, #4]\n"
        "    lsls r4, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #0xf\n"
        "    adds r4, r4, r1\n"
        "    asrs r4, r4, #0x10\n"
        "    ldr r0, .L080D70B0\n"
        "    str r7, [sp]\n"
        "    str r6, [sp, #4]\n"
        "    mov r1, r8\n"
        "    ands r4, r1\n"
        "    str r4, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L080D7096:\n"
        "    add sp, #0xc\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080D70A4: .4byte gUnknown_0813ECB4\n"
        ".L080D70A8: .4byte gUnknown_0813ECD0\n"
        ".L080D70AC: .4byte gUnknown_0813ECEC\n"
        ".L080D70B0: .4byte gUnknown_0813ED2C\n"
    );
}
#endif

