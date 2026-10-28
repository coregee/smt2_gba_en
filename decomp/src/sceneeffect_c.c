#include "global.h"
#include "sceneeffect.h"

// sub_080BAEA8 @ 0x080BAEA8
void sub_080BAEA8(struct Task *task)
{
    if (Char_FindById(0x190)->wait == -1)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080BAECC @ 0x080BAECC
void sub_080BAECC(void)
{
    DmaSet(3, 0x02001000, 0x06013000, 0x84000700);
}

// sub_080BAEF0 @ 0x080BAEF0
void sub_080BAEF0(void)
{
    LZ77UnCompWram(gUnknown_081839F4, gUnk_02001000);
    LZ77UnCompWram(gUnknown_081845E4, gUnk_02001000 + 0x1000);
    if (!Palette_IsBg13Black())
    {
        Palette_CopyWithEffect(3, gUnknown_08184BA4, &gPaletteBuffer[0x1F0], 0x20, 0x20);
        Palette_MarkDirty();
    }
    else
    {
        Palette_CopyWithEffect(3, gUnknown_08184BA4, &gPaletteTarget[0x1F0], 0x20, 0x20);
        PalFade_FadeRangeInFromBlackTagged(0x1F0, 0x10, 1, 1);
    }
    VBlankTask_AddCounted(sub_080BAECC, 1);
}

// sub_080BAF7C @ 0x080BAF7C
void sub_080BAF7C(void)
{
    DmaSet(3, 0x02001000, 0x0600E000, 0x84000800);
    DmaSet(3, gUnk_02000000, 0x06001000, 0x84000400);
}

// sub_080BAFB8 @ 0x080BAFB8
void sub_080BAFB8(struct Task *task, u32 step)
{
    switch (step)
    {
    case 0:
        LZ77UnCompWram(gUnknown_08184BC4, (void *)0x02001000);
        break;
    case 1:
        LZ77UnCompWram(gUnknown_0818596C, (void *)0x02002000);
        break;
    case 2:
        DMA_FILL32(3, 0, gUnk_02000000, 0x1000);
        LZ77UnCompWram(gUnknown_08186524, (void *)0x0200BFC8);
        Tilemap_CopyRectSkipZero((void *)0x0200BFC8, gUnk_02000000, 0x300, 7, 0, 0, 0x20, 0x24);
        break;
    case 3:
        VBlankTask_AddCounted(sub_080BAF7C, 1);
        gUnk_03000006 = 0xA8;
        gUnk_03000030 = 0xE8;
        gUnk_03000031 = 8;
        gUnk_03000034 = 0xE0;
        gUnk_03000035 = 0x68;
        gUnk_03000038 = 0x3D;
        break;
    }
}

// sub_080BB094 @ 0x080BB094
void sub_080BB094(struct Task *task, u32 mode)
{
    if (mode == 0)
    {
        sub_080C7C60();
    }
    else if (mode == 1)
    {
        gUnk_03000040 = 0x3C40;
        REG_BG1CNT = 0x820B;
    }
    else
    {
        sub_080C1440();
        gUnk_03000006 = 0;
        REG_BG1CNT = 0x8209;
    }
}

// sub_080BB0E4 @ 0x080BB0E4
void sub_080BB0E4(struct Task *task)
{
    u16 *d = task->data.h;

    task->result = 0;
    if (!(gFrameCounter & 7))
    {
        if (gUnk_0300000E != 0)
            gUnk_0300000E--;
        else
            task->result = 1;
    }
    if (task->result == 0 && !(gFrameCounter & 3))
    {
        gUnk_03000006--;
        if (++d[2] > 0x38)
            task->onFrame = NULL;
    }
}

// sub_080BB14C @ 0x080BB14C
void sub_080BB14C(void)
{
    u16 *d = Char_FindById(0x162)->data.h;

    d[5]--;
}

// sub_080BB164 @ 0x080BB164
void sub_080BB164(struct Task *task)
{
    u16 *d;
    u16 i;

    Char_FindById(0x162);
    d = task->data.h;
    if (!(gFrameCounter & 3))
    {
        for (i = 0; i < 6; i++)
        {
            if (gCharTasks[i] == NULL)
                break;
        }
        if (i != 6)
            sub_080C4618(i, 0x177, (Random_Byte() + 0x40) & 0x7F, d[2] + 0xE, 0, 0);
    }
}

// sub_080BB1DC @ 0x080BB1DC
void sub_080BB1DC(void)
{
    PalFade_FadeRangeToBlack(0x1E0, 0x10, 1);
}

// sub_080BB1F0 @ 0x080BB1F0
void sub_080BB1F0(void)
{
    gUnk_0300000E = 0;
    gUnk_03000006 = -40;
}

// sub_080BB20C @ 0x080BB20C
void sub_080BB20C(struct Task *task)
{
    u16 *d = task->data.h;

    d[2] = 0x73;
    d[3] = 6;
}

// sub_080BB218 @ 0x080BB218
void sub_080BB218(struct Task *task, u32 id, s32 dx)
{
    u16 *d = task->data.h;

    task->data.w[0] = (u32)sub_080C4618(0, id, d[2], d[3], 0, 0);
    d[2] -= dx;
}

// sub_080BB248 @ 0x080BB248
void sub_080BB248(struct Task *task, s32 dx)
{
    u16 *d = task->data.h;

    d[2] -= dx;
    sub_080C48CC((struct Task *)task->data.w[0], d[2], d[3]);
}

// sub_080BB264 @ 0x080BB264
void sub_080BB264(struct Task *task)
{
    sub_080C48F0((struct Task *)task->data.w[0], 0);
}

// sub_080BB274 @ 0x080BB274
void sub_080BB274(struct Task *task, u32 on)
{
    if (on == 1)
    {
        Flag_Set(0x102);
        Flag_Set(0x106);
    }
    else
    {
        Flag_Clear(0x102);
        Flag_Clear(0x106);
    }
}

// sub_080BB2A0 @ 0x080BB2A0
void sub_080BB2A0(void)
{
    /* Both branches are the same in the original. */
    if (!(gUnk_0200AB04 & 0x8000))
    {
        PalFade_FadeRangeToWhite(0x80, 0x80, 2);
        PalFade_FadeRangeToWhite(0x1D0, 0x30, 2);
    }
    else
    {
        PalFade_FadeRangeToWhite(0x80, 0x80, 2);
        PalFade_FadeRangeToWhite(0x1D0, 0x30, 2);
    }
}

// sub_080BB2E8 @ 0x080BB2E8
void sub_080BB2E8(void)
{
    PalFade_FadeRangeToBlackWithDuration(0x80, 0x80, 1, 0x20);
    PalFade_FadeRangeToBlackWithDuration(0x1D0, 0x30, 1, 0x20);
}

// sub_080BB308 @ 0x080BB308
void sub_080BB308(void)
{
    Flag_Set(0x105);
}

// sub_080BB318 @ 0x080BB318
void sub_080BB318(void)
{
    DmaSet(3, 0x02001000, 0x06013000, 0x84001200);
}
