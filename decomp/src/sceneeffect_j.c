#include "global.h"
#include "sceneeffect.h"

// sub_080BCCB4 @ 0x080BCCB4
void sub_080BCCB4(struct Task *task, u32 step)
{
    switch (step)
    {
    case 0:
        CharObj_Create(1, 0xCB, 0x50, 0x6B, 0, 0);
        break;
    case 1:
        gUnk_0300000E--;
        break;
    case 2:
        CharObj_Create(0, 0xC6, 0x50, -0x40, 0, 0);
        break;
    case 4:
        gUnk_0300000E++;
        /* fallthrough */
    case 3:
        sub_080BAD88(task, 0xC6, 0, 1);
        break;
    case 6:
        sub_080BCDC4(task);
        break;
    case 7:
        sub_080C3818(1);
        break;
    case 8:
        gUnk_030068F0[0] = (u32)CharObj_Create(0, 0x1C4, 0x50, 0x6B, 0, 0);
        break;
    case 9:
        sub_080BCE0C(task);
        break;
    }
}

// sub_080BCD84 @ 0x080BCD84
void sub_080BCD84(void)
{
    gHudState[0x1A] = 1;
    PalFade_FadeRangeToBlack(0, 0x200, 8);
}

// sub_080BCDA0 @ 0x080BCDA0
void sub_080BCDA0(struct Task *task, u32 id, u32 arg)
{
    CharObj_Create(0, id, 0x50, -45, arg, 0);
}

// sub_080BCDC4 @ 0x080BCDC4
void sub_080BCDC4(struct Task *task)
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

// sub_080BCE0C @ 0x080BCE0C
/* Fades the picture back in and reloads the palettes of the object sprites. */
void sub_080BCE0C(struct Task *task)
{
    u32 i;

    if (!(gUnk_0200AB04 & 0x8000))
    {
        sub_080B04BC();
        PalFade_FadeRangeWithDuration(0x80, 0x80, 2, 0x20);
    }
    else
    {
        BgPicture_LoadPalette();
        PalFade_FadeRangeWithDuration(0x80, 0x80, 2, 0x20);
    }
    for (i = 0; i < 6; i++)
    {
        if (gCharTasks[i] != NULL)
        {
            u16 *d = gCharTasks[i]->data.h;
            const u16 *pal = Char_GetRecord(d[3])->palette;

            if (d[3] == 0x1C1)
                pal = sub_080D8248(gUnk_0203DB28[0])->palette;
            else if (d[3] == 0x1C0)
                pal = sub_080D8248(gUnk_0203DB28[1])->palette;
            if (d[2] == 1)
            {
                if (d[1] == 0)
                    Palette_CopyWithEffect(3, pal, &gPaletteTarget[0x1E0], 0x20, 0x20);
                else if (d[1] == 1)
                    Palette_CopyWithEffect(3, pal, &gPaletteTarget[0x1F0], 0x20, 0x20);
                else
                    Palette_CopyWithEffect(3, pal, &gPaletteTarget[0x1D0], 0x20, 0x20);
            }
        }
    }
    PalFade_FadeRangeWithDuration(0x1D0, 0x30, 2, 0x20);
}

// sub_080BCEF0 @ 0x080BCEF0
void sub_080BCEF0(void)
{
    DMA_FILL32(3, 0, 0x06000000, 0x4000);
    DMA_FILL32(3, 0, 0x06004000, 0x80);
    DMA_FILL32(3, 0, 0x06008000, 0x80);
    sub_080C1450();
    gUnk_03000030 = gUnk_03000032 = 0xE8;
    gUnk_03000031 = gUnk_03000033 = 8;
    gUnk_03000034 = gUnk_03000036 = 0x68;
    gUnk_03000035 = gUnk_03000037 = 0;
    gUnk_03000038 = 0x3F;
    gUnk_03000039 = 0x3F;
    gUnk_0300003A = 0;
    gUnk_0300003B = 0;
}
