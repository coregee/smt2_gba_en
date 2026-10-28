#include "global.h"
#include "title.h"

// sub_080D70B4 @ 0x080D70B4
void sub_080D70B4(struct Task *task)
{
    gUnk_03000004 = 0;
    gUnk_03000008 = 0;
    task->unk1E = 0;
}

/* Debug-style adjust: A/B step blend coefficient 0x42, R/L step 0x43, right/left scroll BG0. */
// sub_080D70CC @ 0x080D70CC
void sub_080D70CC(struct Task *task)
{
    if (gKeysNew & 1)
        gUnk_03000042 = (gUnk_03000042 + 1) & 0x1F;
    if (gKeysNew & 2)
        gUnk_03000042 = (gUnk_03000042 - 1) & 0x1F;
    if (gKeysNew & 0x100)
        gUnk_03000043 = (gUnk_03000043 + 1) & 0x1F;
    if (gKeysNew & 0x200)
        gUnk_03000043 = (gUnk_03000043 - 1) & 0x1F;
    if (gUnk_030031D0 & 0x20)
        gUnk_03000004 = (gUnk_03000004 + 1) & 0xFF;
    if (gUnk_030031D0 & 0x10)
        gUnk_03000004 = (gUnk_03000004 - 1) & 0xFF;
    if (gKeysNew & 8)
        task->unk1E = 1;
}

// sub_080D7184 @ 0x080D7184
void sub_080D7184(void)
{
    struct TitleMenu *menu = TITLE;

    gUnk_03000030 = 0xF0;
    gUnk_03000031 = 0;
    gUnk_03000034 = 0xA0;
    gUnk_03000035 = 0;
    gUnk_0300003A = 0x3F;
    gUnk_0300000C = 0;
    gUnk_03000008 = 0;
    gUnk_03000004 = 0;
    if (gMsgWindow->state != 0)
        Task_End(gMsgWindow);
    if (gUnk_03006954->state != 0)
        Task_End(gUnk_03006954);
    if (gUnk_03006938->state != 0)
        Task_End(gUnk_03006938);
    menu->unk0E = 1;
}

// sub_080D721C @ 0x080D721C
void sub_080D721C(struct Task *task)
{
    task->result = 0;
    task->data.raw[1] = 0;
    task->data.raw[2] = 0;
}

// sub_080D7230 @ 0x080D7230
void sub_080D7230(struct Task *task)
{
    struct TitleMenu *menu = TITLE;

    if (++task->data.raw[1] == 0x1E)
    {
        task->data.raw[1] = 0;
        task->data.raw[2]++;
        gUnk_03000042 = gUnknown_08509680[task->data.raw[2] * 2];
        gUnk_03000043 = gUnknown_08509680[task->data.raw[2] * 2 + 1];
        if (task->data.raw[2] == 0x10)
            task->result = 1;
    }
    if (menu->unk10 == 1)
        task->unk1E = 1;
}

// sub_080D72A4 @ 0x080D72A4
void sub_080D72A4(struct Task *task)
{
    task->result = 0;
    task->data.raw[1] = 0;
    task->data.raw[2] = 0;
    task->data.raw[3] = 0;
    task->data.raw[4] = 0;
}

// sub_080D72C0 @ 0x080D72C0
void sub_080D72C0(struct Task *task)
{
    struct TitleMenu *menu = TITLE;

    if (++task->data.raw[1] == 0x10)
    {
        task->data.raw[1] = 0;
        task->data.raw[2]++;
        gUnk_03000042 = gUnknown_08509680[task->data.raw[2] * 2];
        gUnk_03000043 = gUnknown_08509680[task->data.raw[2] * 2 + 1];
        if (task->data.raw[2] == 0x10)
            task->result = 1;
    }
    if (menu->unk10 == 1)
        task->unk1E = 1;
}

// sub_080D7334 @ 0x080D7334
void sub_080D7334(struct Task *task)
{
    task->result = 0;
    task->data.raw[0] = 0;
    task->data.raw[1] = 0;
}

// sub_080D7348 @ 0x080D7348
void sub_080D7348(struct Task *task)
{
    struct TitleMenu *menu = TITLE;

    if (++task->data.raw[1] == 10)
    {
        task->data.raw[1] = 0;
        task->data.raw[0]++;
        gUnk_03000034 = 0x9F - task->data.raw[0];
        if (task->data.raw[0] == 0x10)
            task->result = 1;
    }
    if (menu->unk10 == 1)
        task->unk1E = 1;
}

// sub_080D739C @ 0x080D739C
void sub_080D739C(struct Task *task)
{
    gUnk_03000032 = 0x64;
    gUnk_03000033 = 0;
    gUnk_03000036 = 0x6C;
    gUnk_03000037 = 0;
    gUnk_03000039 = 0x3F;
    task->data.raw[0] = 0x64;
    task->data.raw[2] = 5;
    task->data.raw[1] = 8;
    task->result = 0;
    task->unk1E = 0;
}

/* NONMATCHING: same 0xFFCE sign-extension as sub_080D6EA0 */
// sub_080D73EC @ 0x080D73EC
#ifdef NONMATCHING
void sub_080D73EC(struct Task *task)
{
    if (task->data.raw[1] != 0)
    {
        task->data.raw[1]--;
    }
    else
    {
        if (task->data.raw[2] != 0)
        {
            task->data.raw[2]--;
        }
        else
        {
            task->data.raw[2] = 5;
            task->data.raw[0]--;
            gUnk_03000032--;
        }
        if (task->data.raw[0] == 0)
        {
            task->result = 1;
            return;
        }
    }
    Sprite_Draw(gUnknown_0813EC98, 0, 0, 0, 0, -50 + task->data.raw[0], 8);
}
#else
NAKED
void sub_080D73EC(struct Task *task)
{
    asm_unified(
        "    push {lr}\n"
        "    sub sp, #0xc\n"
        "    adds r3, r0, #0\n"
        "    adds r1, r3, #0\n"
        "    adds r1, #0x25\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0\n"
        "    beq .L080D7406\n"
        "    subs r0, #1\n"
        "    strb r0, [r1]\n"
        "    adds r2, r3, #0\n"
        "    adds r2, #0x24\n"
        "    b .L080D7444\n"
        ".L080D7406:\n"
        "    adds r1, r3, #0\n"
        "    adds r1, #0x26\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0\n"
        "    beq .L080D741A\n"
        "    subs r0, #1\n"
        "    strb r0, [r1]\n"
        "    adds r2, r3, #0\n"
        "    adds r2, #0x24\n"
        "    b .L080D7432\n"
        ".L080D741A:\n"
        "    movs r0, #5\n"
        "    strb r0, [r1]\n"
        "    adds r1, r3, #0\n"
        "    adds r1, #0x24\n"
        "    ldrb r0, [r1]\n"
        "    subs r0, #1\n"
        "    strb r0, [r1]\n"
        "    ldr r2, .L080D7440\n"
        "    ldrb r0, [r2]\n"
        "    subs r0, #1\n"
        "    strb r0, [r2]\n"
        "    adds r2, r1, #0\n"
        ".L080D7432:\n"
        "    ldrb r0, [r2]\n"
        "    cmp r0, #0\n"
        "    bne .L080D7444\n"
        "    movs r0, #1\n"
        "    strh r0, [r3, #0x1c]\n"
        "    b .L080D7466\n"
        "    .byte 0x00, 0x00\n"
        ".L080D7440: .4byte 0x03000032 @ IWRAM+0x32\n"
        ".L080D7444:\n"
        "    ldr r1, .L080D746C\n"
        "    lsls r1, r1, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    ldrb r2, [r2]\n"
        "    adds r1, r1, r2\n"
        "    ldr r0, .L080D7470\n"
        "    movs r2, #0\n"
        "    str r2, [sp]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #8\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L080D7466:\n"
        "    add sp, #0xc\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080D746C: .4byte 0x0000FFCE\n"
        ".L080D7470: .4byte gUnknown_0813EC98\n"
    );
}
#endif

// sub_080D7474 @ 0x080D7474
void sub_080D7474(struct Task *task)
{
    gUnk_03000030 = 0xF0;
    gUnk_03000031 = 0;
    gUnk_03000034 = 0x96;
    gUnk_03000035 = 0x70;
    gUnk_0300003A &= 0xEF;
    task->data.raw[0] = 0xA0;
    task->data.raw[2] = 6;
    task->data.raw[1] = 0xF0;
    task->data.raw[3] = 0x78;
    task->result = 0;
    task->data.raw[0xC] = 0;
    task->data.raw[0xD] = 0;
}
