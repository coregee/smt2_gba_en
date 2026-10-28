#include "global.h"
#include "sceneeffect.h"

// sub_080BD2A8 @ 0x080BD2A8
void sub_080BD2A8(struct Task *task)
{
    struct AffineAnim *d = (struct AffineAnim *)task->data.raw;

    if (!(gFrameCounter & 3))
        d->y2++;
}

// sub_080BD2C8 @ 0x080BD2C8
void sub_080BD2C8(struct Task *task)
{
    struct AffineAnim *d = (struct AffineAnim *)task->data.raw;

    task->result = 0;
    if (d->frame == 0xC)
    {
        d->y1 = d->y2;
        d->x1 = d->x2;
        if (d->affine[1] != 4)
        {
            d->affine[1] -= 2;
            d->affine[2] -= 2;
        }
        else
        {
            task->result = 1;
        }
    }
}

// sub_080BD2FC @ 0x080BD2FC
void sub_080BD2FC(struct Task *task, u32 delay)
{
    PalFade_FadeRangeToWhite(1, 0x1FF, delay);
}

// sub_080BD314 @ 0x080BD314
void sub_080BD314(void)
{
    Flag_Set(0xFD);
    Flag_Set(0x10D);
    Flag_Set(0x10E);
}

// sub_080BD334 @ 0x080BD334
void sub_080BD334(void)
{
    gUnk_03000030 = gUnk_03000032 = 0xE8;
    gUnk_03000031 = gUnk_03000033 = 8;
    gUnk_03000034 = gUnk_03000036 = 0x68;
    gUnk_03000035 = gUnk_03000037 = 0;
    gUnk_03000038 = 0x3F;
    gUnk_03000039 = 0x3F;
    gUnk_0300003A = 0;
    gUnk_0300003B = 0;
    gUnk_0300000E = 0;
    gUnk_0300000C = 0;
    gUnk_03000006 = 0;
    gUnk_03000004 = 0;
}

// sub_080BD3C4 @ 0x080BD3C4
void sub_080BD3C4(void)
{
    VBlankTask_AddCounted(sub_080BD334, 1);
}

// sub_080BD3D8 @ 0x080BD3D8
void sub_080BD3D8(struct Task *task)
{
    task->data.w[0] = sub_080B6DB4(0x6D);
}

// sub_080BD3EC @ 0x080BD3EC
void sub_080BD3EC(struct Task *task)
{
    if (*(u16 *)task->data.w[0] != 0)
        task->result = 0;
    else
        task->result = 1;
}

// sub_080BD404 @ 0x080BD404
void sub_080BD404(void)
{
    struct Task *t = sub_080BC230(0x11E);

    if (t != NULL)
        t->data.h[8] = 3;
}

// sub_080BD41C @ 0x080BD41C
void sub_080BD41C(void)
{
    PalFade_FadeRangeToBlackWithDuration(0x1E0, 0x10, 0x10, 8);
    PalFade_FadeRangeToBlackWithDuration(0x80, 0x80, 0x10, 8);
}

// sub_080BD43C @ 0x080BD43C
void sub_080BD43C(struct Task *task)
{
    task->data.w[0] = sub_080B6DB4(0x71);
}

// sub_080BD450 @ 0x080BD450
void sub_080BD450(struct Task *task)
{
    if (*(u16 *)task->data.w[0] != 0)
        task->result = 0;
    else
        task->result = 1;
}

// sub_080BD468 @ 0x080BD468
void sub_080BD468(void)
{
    DmaSet(3, gUnk_02000000, 0x06000000, 0x84000400);
    DmaSet(3, 0x02001000, 0x0600F800, 0x84000200);
    REG_DISPCNT = 0x7900;
    REG_BG0CNT = 0x800B;
    REG_BG3CNT = 0x8604;
    gUnk_03000030 = gUnk_03000032 = 0xE8;
    gUnk_03000031 = gUnk_03000033 = 8;
    gUnk_03000034 = gUnk_03000036 = 0x68;
    gUnk_03000035 = gUnk_03000037 = 0;
    gUnk_03000038 = 0x3F;
    gUnk_03000039 = 0x3F;
    gUnk_0300003A = 0;
    gUnk_0300003B = 0;
    gUnk_0300000E = 0;
    gUnk_0300000C = 0;
    gUnk_03000002 = 0;
    gUnk_03000000 = 0;
}

// sub_080BD550 @ 0x080BD550
void sub_080BD550(void)
{
    Tilemap_CopyRectSkipZero(gUnknown_081974F4, gUnk_02000000, 0x3C0, 8, 1, 0, 0x1C, 0xD);
    VBlankTask_AddCounted(sub_080BD468, 1);
}

// sub_080BD58C @ 0x080BD58C
void sub_080BD58C(void)
{
    Flag_Set(0xFD);
}

// sub_080BD598 @ 0x080BD598
void sub_080BD598(struct Task *task)
{
    struct Task *t = sub_080BC230(0x21);
    struct ObjData *d = (struct ObjData *)t->data.raw;

    task->result = 0;
    d->x--;
    d->unk00 |= 0x20;
    d->unk12 = 1;
    if (d->x <= 0x50)
        task->result = 1;
}
