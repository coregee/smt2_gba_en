#include "global.h"
#include "extras.h"

// sub_080DA518 @ 0x080DA518
void sub_080DA518(void)
{
    if (((gFrameCounter >> 4) & 1) == 0)
        Sprite_Draw(gUnknown_08008D7C, 0, 10, 0, 0x140, 0x12, 0x63);
    else
        Sprite_Draw(gUnknown_08008E8C, 0, 10, 0, 0x140, 0x12, 0x63);
}

// sub_080DA574 @ 0x080DA574
void sub_080DA574(void)
{
    if (((gFrameCounter >> 4) & 1) == 0)
    {
        Sprite_Draw(gUnknown_08002BE8, 0, 0, 0, 0x280, 0x12, 0x5B);
        Sprite_Draw(gUnknown_08002BE8, 0, 0, 0, 0x280, 0x12, 0x63);
        Sprite_Draw(gUnknown_08002BE8, 0, 0, 0, 0x280, 0x12, 0x6B);
    }
}

// sub_080DA5DC @ 0x080DA5DC
void sub_080DA5DC(void)
{
    Sprite_Draw(gUnknown_08002B34, 0, 0, 0, 0x280, 0x12, 0x5B);
    sub_080DA574();
}

// sub_080DA608 @ 0x080DA608
void sub_080DA608(void)
{
    Sprite_Draw(gUnknown_08002B68, 0, 0, 0, 0x280, 0x12, 0x5B);
    sub_080DA574();
}

// sub_080DA634 @ 0x080DA634
void sub_080DA634(void)
{
    DmaSet3(gBgPictureBuffer, 0x06015000, 0x84000200);
}

// sub_080DA658 @ 0x080DA658
void sub_080DA658(void)
{
    LZ77UnCompWram(gUnknown_081B6A64, gBgPictureBuffer);
    VBlankTask_AddCounted(sub_080DA634, 1);
}

// sub_080DA67C @ 0x080DA67C
void sub_080DA67C(void)
{
    Sprite_Draw(gUnknown_08002BA4, 0, 0, 0, 0x280, 0x12, 0x5B);
    sub_080DA574();
}

// sub_080DA6A8 @ 0x080DA6A8
void sub_080DA6A8(void)
{
    Sprite_Draw(gUnknown_08002BD8, 0, 0, 0, 0x280, 0x12, 0x5B);
    sub_080DA574();
}

// sub_080DA6D4 @ 0x080DA6D4
void sub_080DA6D4(void)
{
    DmaSet3(gBgPictureBuffer, 0x06015000, 0x84000200);
}

// sub_080DA6F8 @ 0x080DA6F8
void sub_080DA6F8(void)
{
    LZ77UnCompWram(gUnknown_081B6A64, gBgPictureBuffer);
    VBlankTask_AddCounted(sub_080DA6D4, 1);
}

/* Waits for any key; blinks a prompt sprite meanwhile. */
// sub_080DA71C @ 0x080DA71C
void sub_080DA71C(struct Task *task)
{
    u16 keys = gKeysNew & 0x3FF;

    if (keys)
    {
        task->result = 1;
        Sound_Play(0x65);
    }
    else
    {
        task->result = keys;
        if (((gFrameCounter >> 3) & 1) == 0)
            sub_080C4AB0(0, 0, 0xD5, 0x85);
    }
}

/* Draws "a/b" with sprite digits at (x, y). */
// Sprite_DrawFraction @ 0x080DA764
void Sprite_DrawFraction(u32 a, u32 b, u16 x, u16 y)
{
    u8 *dig;

    Sprite_Draw(gUnknown_08008F58, 6, 7, 1, 0, x, y);
    dig = NumberToDigits(a);
    if (a > 99)
    {
        Sprite_Draw(gUnknown_08582410[dig[2]], 6, 7, 1, 0, x + 0x18, y);
        Sprite_Draw(gUnknown_08582410[dig[1]], 6, 7, 1, 0, x + 0x1E, y);
        Sprite_Draw(gUnknown_08582410[dig[0]], 6, 7, 1, 0, x + 0x24, y);
    }
    else if (a > 9)
    {
        Sprite_Draw(gUnknown_08582410[dig[1]], 6, 7, 1, 0, x + 0x1E, y);
        Sprite_Draw(gUnknown_08582410[dig[0]], 6, 7, 1, 0, x + 0x24, y);
    }
    else
    {
        Sprite_Draw(gUnknown_08582410[dig[0]], 6, 7, 1, 0, x + 0x24, y);
    }
    Sprite_Draw(gUnknown_08008F68, 6, 7, 1, 0, x + 0x2A, y);
    dig = NumberToDigits(b);
    if (b > 99)
    {
        Sprite_Draw(gUnknown_08582410[dig[2]], 6, 7, 1, 0, x + 0x30, y);
        Sprite_Draw(gUnknown_08582410[dig[1]], 6, 7, 1, 0, x + 0x36, y);
        Sprite_Draw(gUnknown_08582410[dig[0]], 6, 7, 1, 0, x + 0x3C, y);
    }
    else if (b > 9)
    {
        Sprite_Draw(gUnknown_08582410[dig[1]], 6, 7, 1, 0, x + 0x30, y);
        Sprite_Draw(gUnknown_08582410[dig[0]], 6, 7, 1, 0, x + 0x36, y);
    }
    else
    {
        Sprite_Draw(gUnknown_08582410[dig[0]], 6, 7, 1, 0, x + 0x30, y);
    }
}

// sub_080DA958 @ 0x080DA958
void sub_080DA958(struct Task *task)
{
    struct C0d9MenuState *ms = &gMenuState;

    task->result = 0;
    task->unk1E = 0;
    ms->task = task;
    ms->onFrame = task->onFrame;
    if (gKeysNew & 1)
    {
        task->unk1E = task->data.h[0] + 1;
        Sound_Play(0x65);
        task->result = 1;
        if (task->unk1E == 1)
        {
            Vision_BuildList(1);
            if (Vision_CountListed() == 0)
                task->unk1E = 3;
        }
    }
    else if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        task->result = 1;
    }
    else
    {
        u16 up = gRepeatedKeys & 0x40;

        if (up)
        {
            if (task->data.h[0] != 0)
                task->data.h[0]--;
            else
                task->data.h[0] = 1;
            Sound_Play(0x64);
        }
        else if (gRepeatedKeys & 0x80)
        {
            if (task->data.h[0] != 1)
                task->data.h[0]++;
            else
                task->data.h[0] = up;
            Sound_Play(0x64);
        }
    }
}

// sub_080DAA0C @ 0x080DAA0C
void sub_080DAA0C(struct Task *task)
{
    struct Task *parent = Task_GetParent(task);

    Text_DrawSpriteString(gUnknown_08582438[parent->data.h[0]], 0, 0, 0x14, 0x64, 0xC);
}

// sub_080DAA3C @ 0x080DAA3C
void sub_080DAA3C(void)
{
    Text_DrawSpriteString(gUnknown_08009550, 0, 0, 0x14, 0x64, 0xC);
}

// sub_080DAA60 @ 0x080DAA60
void sub_080DAA60(void)
{
    REG_BG3CNT = 0x8607;
}

// sub_080DAA74 @ 0x080DAA74
void sub_080DAA74(void)
{
    REG_DISPCNT &= 0xF7FF;
}

// sub_080DAA88 @ 0x080DAA88
void sub_080DAA88(void)
{
    REG_DISPCNT |= 0x800;
}

// sub_080DAA9C @ 0x080DAA9C
void sub_080DAA9C(void)
{
    gUnk_03000038 = 0x3F;
}
