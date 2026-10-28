#include "global.h"
#include "menu2.h"

// sub_080D4714 @ 0x080D4714
void sub_080D4714(struct Task *task)
{
    u16 *data = task->data.h;

    task->data.h[0] = task->unk1E;
    data[1] = 0;
    if ((sub_080C2244() & 0xFF) == 0 && !sub_080C3560(0xFB))
        data[1] = 0xFB;
}

// sub_080D4744 @ 0x080D4744
void sub_080D4744(struct Task *task)
{
    if (Task_GetParent(task)->state != 0)
        task->result = 0;
    else
        task->result = 1;
}

// sub_080D4760 @ 0x080D4760
void sub_080D4760(void)
{
    sub_080ECA60(0xD1, 0, 0x81, 0);
}

// sub_080D4774 @ 0x080D4774
void sub_080D4774(struct Task *task)
{
    u32 r = sub_080ECB10();

    if (r != 1)
        r = 0;
    task->result = r;
}

/* NONMATCHING: the original passes an uninitialised first argument (r0 left over). */
// sub_080D478C @ 0x080D478C
#ifdef NONMATCHING
void sub_080D478C(struct Task *task)
{
    u16 *data = task->data.h;

    Flag_Set(0x10C);
    if (data[1] == 0)
        gUnk_0203DB28 = task->data.h[0];
    else
        gUnk_0203DB28 = data[1];
    /* The original never sets r0 here: the first argument is whatever was left in it. */
    *(u32 *)&data[4] = sub_080C4618(0, 0x1C1, 0x50, 4, 0, 0);
}
#else
NAKED
void sub_080D478C(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, lr}\n"
        "    sub sp, #8\n"
        "    adds r4, r0, #0\n"
        "    adds r5, r4, #0\n"
        "    adds r5, #0x24\n"
        "    movs r0, #0x86\n"
        "    lsls r0, r0, #1\n"
        "    bl Flag_Set\n"
        "    ldrh r1, [r5, #2]\n"
        "    cmp r1, #0\n"
        "    bne .L080D47B0\n"
        "    ldr r1, .L080D47AC\n"
        "    ldrh r0, [r4, #0x24]\n"
        "    strh r0, [r1]\n"
        "    b .L080D47B4\n"
        ".L080D47AC: .4byte 0x0203DB28 @ EWRAM+0x3DB28\n"
        ".L080D47B0:\n"
        "    ldr r0, .L080D47D0\n"
        "    strh r1, [r0]\n"
        ".L080D47B4:\n"
        "    ldr r1, .L080D47D4\n"
        "    movs r0, #0\n"
        "    str r0, [sp]\n"
        "    str r0, [sp, #4]\n"
        "    movs r2, #0x50\n"
        "    movs r3, #4\n"
        "    bl sub_080C4618\n"
        "    str r0, [r5, #8]\n"
        "    add sp, #8\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080D47D0: .4byte 0x0203DB28 @ EWRAM+0x3DB28\n"
        ".L080D47D4: .4byte 0x000001C1\n"
    );
}
#endif

// sub_080D47D8 @ 0x080D47D8
void sub_080D47D8(void)
{
    PalFade_FadeRangeToBlack(0x1E0, 0x10, 1);
}

// sub_080D47EC @ 0x080D47EC
void sub_080D47EC(struct Task *task)
{
    if (task->data.h[1] == 0)
        sub_080AF178(0x1A, gUnknown_084F3838[task->data.h[0] - 0x16A]);
    else
        sub_080AF178(0x1A, gUnknown_0815C090);
}

// sub_080D4824 @ 0x080D4824
void sub_080D4824(void)
{
    sub_080C6558();
    sub_080C6764();
}

// sub_080D4834 @ 0x080D4834
void sub_080D4834(struct Task *task)
{
    if (gFieldState == 0x1A)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080D4850 @ 0x080D4850
void sub_080D4850(struct Task *task)
{
    u16 *data = task->data.h;
    s32 n = sub_080D45B8(task->data.h[0]);
    s32 i;

    sub_080C30AC(-sub_081571DC(task->data.h[0]));
    for (i = 0; i < n; i++)
        sub_080C33AC(0x11F);
    if (data[1] == 0)
        sub_080C062C(data[0]);
    else
        sub_080C062C(data[1]);
}

// sub_080D489C @ 0x080D489C
void sub_080D489C(struct Task *task)
{
    if (task->data.w[2] != 0)
        sub_080C48F0(task->data.w[2], 0);
    sub_080AF178(0xC, gUnknown_0805C3D0);
}

// sub_080D48BC @ 0x080D48BC
void sub_080D48BC(void)
{
    sub_080C51BC(1);
}

// sub_080D48C8 @ 0x080D48C8
void sub_080D48C8(struct Task *task)
{
    u16 *data = task->data.h;
    s32 n = sub_080D45B8(task->data.h[0]);
    u8 *item = sub_080C3560(task->data.h[0]);
    s32 i;

    sub_080C30AC(-sub_081571DC(task->data.h[0]));
    if (data[1] == 0)
    {
        for (i = 0; i < n; i++)
            sub_080C3328(0x11F);
    }
    sub_080C0290(item[0xC], 1);
}

// sub_080D4918 @ 0x080D4918
void sub_080D4918(struct Task *task)
{
    if (task->data.h[1] == 0)
    {
        s32 *dst;
        sub_080AF178(0x1A, gUnknown_0815C0DE);
        dst = &gUnk_0203DB2C;
        *dst = sub_080D45B8(task->data.h[0]);
    }
    else
        sub_080AF178(0x1A, gUnknown_0815C110);
}

/* NONMATCHING: the zero for the stack arguments is materialised in r2 before the store. */
// sub_080D4954 @ 0x080D4954
#ifdef NONMATCHING
void sub_080D4954(struct Task *task)
{
    u16 *data = task->data.h;

    Flag_Set(0x10C);
    gUnk_0203DB28 = task->data.h[0];
    *(u32 *)&data[4] = sub_080C4618(0, 0x1C1, 0x50, 4, 0, 0);
}
#else
NAKED
void sub_080D4954(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, lr}\n"
        "    sub sp, #8\n"
        "    adds r4, r0, #0\n"
        "    adds r5, r4, #0\n"
        "    adds r5, #0x24\n"
        "    movs r0, #0x86\n"
        "    lsls r0, r0, #1\n"
        "    bl Flag_Set\n"
        "    ldr r1, .L080D4988\n"
        "    ldrh r0, [r4, #0x24]\n"
        "    movs r2, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L080D498C\n"
        "    str r2, [sp]\n"
        "    str r2, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r2, #0x50\n"
        "    movs r3, #4\n"
        "    bl sub_080C4618\n"
        "    str r0, [r5, #8]\n"
        "    add sp, #8\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080D4988: .4byte 0x0203DB28 @ EWRAM+0x3DB28\n"
        ".L080D498C: .4byte 0x000001C1\n"
    );
}
#endif

// sub_080D4990 @ 0x080D4990
void sub_080D4990(void)
{
    DmaSet3((void *)0x06016000, gUnk_02001000, 0x84000400);
}

// sub_080D49B4 @ 0x080D49B4
void sub_080D49B4(void)
{
    VBlankTask_AddCounted(sub_080D4990, 1);
}

// sub_080D49C8 @ 0x080D49C8
void sub_080D49C8(void)
{
    DmaSet3(gUnk_02001000, (void *)0x06016000, 0x84000400);
}
