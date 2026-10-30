#include "global.h"
#include "menu2.h"

// sub_080D4714 @ 0x080D4714
void sub_080D4714(struct Task *task)
{
    u16 *data = task->data.h;

    task->data.h[0] = task->unk1E;
    data[1] = 0;
    if ((Random_Byte() & 0xFF) == 0 && !Stock_FindByDemonId(0xFB))
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

// sub_080D478C @ 0x080D478C
void sub_080D478C(struct Task *task)
{
    u16 *data = task->data.h;

    Flag_Set(0x10C);
    if (data[1] == 0)
        gUnk_0203DB28 = task->data.h[0];
    else
        gUnk_0203DB28 = data[1];
    *(u32 *)&data[4] = CharObj_Create(0, 0x1C1, 0x50, 4, 0, 0);
}

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

    Money_Add(-Compendium_GetPrice(task->data.h[0]));
    for (i = 0; i < n; i++)
        Inventory_RemoveItem(0x11F);
    if (data[1] == 0)
        Stock_AddDemon(data[0]);
    else
        Stock_AddDemon(data[1]);
}

// sub_080D489C @ 0x080D489C
void sub_080D489C(struct Task *task)
{
    if (task->data.w[2] != 0)
        CharObj_End(task->data.w[2], 0);
    sub_080AF178(0xC, gUnknown_0805C3D0);
}

// sub_080D48BC @ 0x080D48BC
void sub_080D48BC(void)
{
    Music_FadeOut(1);
}

// sub_080D48C8 @ 0x080D48C8
void sub_080D48C8(struct Task *task)
{
    u16 *data = task->data.h;
    s32 n = sub_080D45B8(task->data.h[0]);
    u8 *item = Stock_FindByDemonId(task->data.h[0]);
    s32 i;

    Money_Add(-Compendium_GetPrice(task->data.h[0]));
    if (data[1] == 0)
    {
        for (i = 0; i < n; i++)
            Inventory_AddItem(0x11F);
    }
    Party_Remove(item[0xC], 1);
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

// sub_080D4954 @ 0x080D4954
void sub_080D4954(struct Task *task)
{
    u16 *data = task->data.h;
    u16 *dst;
    u16 v;
    u32 zero;

    Flag_Set(0x10C);
    /* written through a pointer, with the zero for the stack arguments set before the store */
    dst = &gUnk_0203DB28;
    v = data[0];
    zero = 0;
    *dst = v;
    *(u32 *)&data[4] = CharObj_Create(0, 0x1C1, 0x50, 4, zero, zero);
}

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
