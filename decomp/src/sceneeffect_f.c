#include "global.h"
#include "sceneeffect.h"

// sub_080BBCFC @ 0x080BBCFC
void sub_080BBCFC(void)
{
    DmaSet(3, 0x02001000, 0x06016800, 0x84000600);
}

// sub_080BBD20 @ 0x080BBD20
void sub_080BBD20(struct Task *task, u32 step)
{
    if (step == 0)
    {
        LZ77UnCompWram(gUnknown_08174294, (void *)0x02001000);
        Palette_CopyWithEffect(3, gUnknown_08174CF8, &gPaletteBuffer[0x1E0], 0x20, 0x20);
        VBlankTask_AddCounted(sub_080BBCD8, 1);
    }
    else if (step == 1)
    {
        LZ77UnCompWram(gUnknown_08174D18, (void *)0x02001000);
        Palette_CopyWithEffect(3, gUnknown_081755F0, &gPaletteBuffer[0x1F0], 0x20, 0x20);
        VBlankTask_AddCounted(sub_080BBCFC, 1);
    }
    else
    {
        u16 i = step - 2;

        LZ77UnCompWram(gUnknown_0818B5F0[i], (void *)(0x02001000 + i * 0x800));
        if (i == 6)
        {
            Palette_CopyWithEffect(3, gUnknown_0817748C, &gPaletteBuffer[0x1E0], 0x20, 0x20);
            VBlankTask_AddCounted(sub_080BBCD8, 1);
        }
    }
    Palette_MarkDirty();
}

// sub_080BBDE8 @ 0x080BBDE8
void sub_080BBDE8(struct Task *task, u32 frame)
{
    task->data.h[0] = frame;
}

// sub_080BBDEC @ 0x080BBDEC
/* Starts a child task at (x, y); slot 1/2 remembers it in data.w[3]/w[4]. */
void sub_080BBDEC(struct Task *task, const void *script, u32 x, u32 y, u32 slot)
{
    u32 *d = task->data.w;
    struct Task *child = Task_Create(script, task->id);
    u16 *cd = child->data.h;

    cd[1] = x;
    cd[2] = y;
    if (slot == 1)
        d[3] = (u32)child;
    if (slot == 2)
        d[4] = (u32)child;
}

// sub_080BBE20 @ 0x080BBE20
void sub_080BBE20(struct Task *task)
{
    u16 *d = task->data.h;

    Sprite_Draw(gUnknown_0818B60C[d[0]], 6, 0xE, 2, 0x180, d[1], d[2]);
}

// sub_080BBE54 @ 0x080BBE54
void sub_080BBE54(struct Task *task)
{
    u16 *d = task->data.h;

    Sprite_Draw(gUnknown_0818B720[d[0]], 9, 0xF, 3, 0x340, d[1], d[2]);
}

// sub_080BBE88 @ 0x080BBE88
void sub_080BBE88(struct Task *task)
{
    u16 *d = task->data.h;

    Sprite_Draw(gUnknown_0818B720[d[0]], 9, 0xF, 3, 0x340, d[1], d[2] + 0x38);
    if (!(gFrameCounter & 7) && ++d[0] == 13)
        d[0] = 7;
}

// sub_080BBEE8 @ 0x080BBEE8
void sub_080BBEE8(struct Task *task)
{
    u16 *d = task->data.h;

    d[2]--;
}

// sub_080BBEF4 @ 0x080BBEF4
void sub_080BBEF4(struct Task *task)
{
    Task_End((struct Task *)task->data.w[4]);
}

// sub_080BBF00 @ 0x080BBF00
void sub_080BBF00(struct Task *task)
{
    u16 *d = task->data.h;

    Sprite_Draw(gUnknown_0818B834[d[0]], 4, 0xE, 2, 0x180, d[1], d[2]);
}

// sub_080BBF34 @ 0x080BBF34
void sub_080BBF34(struct Task *task)
{
    u16 *d = task->data.h;

    Sprite_Draw(gUnknown_0818B960[d[0]], 7, 0xE, 2, 0x180, d[1], d[2]);
}

// sub_080BBF68 @ 0x080BBF68
void sub_080BBF68(struct Task *task)
{
    u16 *d = ((struct Task *)task->data.w[3])->data.h;

    d[2]--;
}

// sub_080BBF74 @ 0x080BBF74
void sub_080BBF74(void)
{
    sub_080B8AE0(0x7FFF, 1);
}

// sub_080BBF88 @ 0x080BBF88
void sub_080BBF88(void)
{
    PalFade_FadeRangeToBlack(0x1E0, 0x20, 1);
}

// sub_080BBF9C @ 0x080BBF9C
void sub_080BBF9C(struct Task *task)
{
    Task_End((struct Task *)task->data.w[3]);
}

// sub_080BBFA8 @ 0x080BBFA8
void sub_080BBFA8(void)
{
    sub_080C4618(0, 0x161, 0x28, 3, 0, 0);
}

// sub_080BBFC8 @ 0x080BBFC8
void sub_080BBFC8(struct Task *task)
{
    if (sub_080BC230(0x161)->wait == -1)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080BBFF0 @ 0x080BBFF0
void sub_080BBFF0(void)
{
    sub_080BC230(0x161)->wait = 1;
}

// sub_080BC004 @ 0x080BC004
void sub_080BC004(struct Task *task)
{
    if (sub_080BC230(0x161) == NULL)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080BC028 @ 0x080BC028
void sub_080BC028(void)
{
    DmaSet(3, 0x02001000, 0x06015000, 0x84000400);
}

// sub_080BC04C @ 0x080BC04C
void sub_080BC04C(struct Task *task)
{
    u16 *d = task->data.h;

    LZ77UnCompWram(gUnknown_0818C0C8, (void *)0x02001000);
    Palette_CopyWithEffect(3, gUnknown_0818C5E0, &gPaletteBuffer[0x1D0], 0x20, 0x20);
    Palette_MarkDirty();
    VBlankTask_AddCounted(sub_080BC028, 1);
    task->data.h[0] = 1;
    d[1] = 4;
    d[2] = 4;
    d[3] = 0;
}
