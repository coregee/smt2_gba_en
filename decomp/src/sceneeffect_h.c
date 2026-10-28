#include "global.h"
#include "sceneeffect.h"

// sub_080BC5A8 @ 0x080BC5A8
void sub_080BC5A8(struct Task *task, u32 step)
{
    if (step == 0)
    {
        struct Task *t;

        sub_080C4618(2, 0xD9, 0x78, 0x46, 0, 0);
        t = sub_080BC230(0xD8);
        if (t != NULL)
            sub_080C48F0(t, 0);
        LZ77UnCompWram(gUnknown_08554E10, gUnk_02001000);
        LZ77UnCompWram(gUnknown_08555260, gUnk_02001000 + 0x800);
        Palette_CopyWithEffect(3, gUnknown_08555694, &gPaletteBuffer[0x1F0], 0x20, 0x20);
        Palette_MarkDirty();
        VBlankTask_AddCounted(sub_080BC560, 1);
    }
    else if (step == 1)
    {
        sub_080C4618(4, 0x16B, 0x78, 0x36, 0, 0);
        sub_080C4618(5, 0x16C, 0x78, 0x46, 0, 0);
        LZ77UnCompWram(gUnknown_08552CE0, gUnk_02001000);
        LZ77UnCompWram(gUnknown_085537C8, gUnk_02001000 + 0x1000);
        LZ77UnCompWram(gUnknown_08554300, gUnk_02001000 + 0x2000);
        LZ77UnCompWram(gUnknown_08554AE4, gUnk_02001000 + 0x3000);
        Palette_CopyWithEffect(3, gUnknown_08554AC4, &gPaletteBuffer[0x1D0], 0x20, 0x20);
        Palette_CopyWithEffect(3, gUnknown_08554DF0, &gPaletteBuffer[0x1E0], 0x20, 0x20);
        Palette_MarkDirty();
        VBlankTask_AddCounted(sub_080BC584, 1);
    }
    else if (step == 2)
    {
        sub_080C4618(2, 0x1BE, 0x78, 0x46, 0, 0);
        sub_080C4618(3, 0x1BF, 0x78, 0x46, 0, 0);
        sub_080C4618(0, 0x16D, 0x78, 0x36, 0, 0);
    }
}

// sub_080BC710 @ 0x080BC710
void sub_080BC710(struct Task *task, u32 still)
{
    struct ObjData *d;

    sub_080BC230(0x1BE);
    if (still == 0)
    {
        d = (struct ObjData *)sub_080BC230(0x1BE)->data.raw;
        d->y--;
        d = (struct ObjData *)sub_080BC230(0x16D)->data.raw;
        d->y--;
    }
    d = (struct ObjData *)sub_080BC230(0x1BF)->data.raw;
    d->y++;
    d = (struct ObjData *)sub_080BC230(0x16B)->data.raw;
    d->y++;
    d = (struct ObjData *)sub_080BC230(0x16C)->data.raw;
    d->y++;
    if (Flag_Test(0xC6))
    {
        gUnk_03000030 = gUnk_03000032 = 0xE8;
        gUnk_03000031 = gUnk_03000033 = 8;
        gUnk_03000034 = gUnk_03000036 = 0x68;
        gUnk_03000035 = gUnk_03000037 = 0;
        gUnk_03000038 = 0x3F;
        gUnk_03000039 = 0x3F;
        gUnk_0300003A = 0;
        gUnk_0300003B = 0;
    }
    else
    {
        gUnk_03000030 = 0xE8;
        gUnk_03000031 = 8;
        gUnk_03000034 = 0xE0;
        gUnk_03000035 = 0x68;
        gUnk_03000038 = 0x3D;
    }
    gUnk_03000006--;
}

// sub_080BC83C @ 0x080BC83C
void sub_080BC83C(void)
{
    gUnk_03000006 = 0;
    gUnk_03000038 = 0x3F;
    VBlankTask_AddCounted(sub_080BAD28, 1);
}

// sub_080BC864 @ 0x080BC864
void sub_080BC864(void)
{
    struct Task *t;

    t = sub_080BC230(0x1BB);
    if (t != NULL)
        t->data.h[8] = 1;
    t = sub_080BC230(0x1BD);
    if (t != NULL)
        t->data.h[8] = 1;
    t = sub_080BC230(0x1B9);
    if (t != NULL)
        t->data.h[8] = 1;
    t = sub_080BC230(0x1BA);
    if (t != NULL)
        t->data.h[8] = 1;
}

// sub_080BC8B8 @ 0x080BC8B8
void sub_080BC8B8(void)
{
    sub_080C4618(3, 0x1BB, 0x78, 0x46, 0, 0);
}

// sub_080BC8D8 @ 0x080BC8D8
void sub_080BC8D8(struct Task *task, u32 frame)
{
    u16 *d = sub_080BC230(0x1BB)->data.h;

    sub_080D95F4(d[3]);
    d[0xC] = frame;
    if (frame == 3 || frame == 4)
    {
        d = sub_080BC230(0x1B9)->data.h;
        d[5]--;
        d = sub_080BC230(0x1BA)->data.h;
        d[5]--;
    }
}

// sub_080BC924 @ 0x080BC924
void sub_080BC924(void)
{
    sub_080B8AE0(0x7FFF, 1);
    sub_080C4618(4, 0x1BD, 0x78, 0x46, 0, 0);
    sub_080C4618(5, 0x1B9, 0x78, 0x36, 0, 0);
    sub_080C4618(6, 0x1BA, 0x78, 0x3E, 0, 0);
}

// sub_080BC978 @ 0x080BC978
void sub_080BC978(void)
{
    DmaSet(3, 0x02001800, 0x06013000, 0x84000C00);
}

// sub_080BC99C @ 0x080BC99C
void sub_080BC99C(void)
{
    LZ77UnCompWram(gUnknown_085537C8, gUnk_02001000);
    LZ77UnCompWram(gUnknown_08554300, gUnk_02001000 + 0x1000);
    LZ77UnCompWram(gUnknown_08174D18, gUnk_02001000 + 0x2000);
    Palette_CopyWithEffect(3, gUnknown_08554AC4, &gPaletteBuffer[0x1E0], 0x20, 0x20);
    Palette_CopyWithEffect(3, gUnknown_081755F0, &gPaletteBuffer[0x1F0], 0x20, 0x20);
    Palette_MarkDirty();
    VBlankTask_AddCounted(sub_080BC978, 1);
}

// sub_080BCA1C @ 0x080BCA1C
void sub_080BCA1C(void)
{
    PalFade_FadeRangeToBlackWithDuration(0x1E0, 0x10, 1, 0x20);
    PalFade_FadeRangeToBlackWithDuration(0x1F0, 0x10, 1, 0x20);
}

// sub_080BCA40 @ 0x080BCA40
void sub_080BCA40(struct Task *task, u32 frame)
{
    Sprite_Draw(gUnknown_0818F54C[frame], 0, 0xE, 0, 0xC0, 0x78, 0x46);
}
