/* Automap screen. */

#include "global.h"
#include "game.h"

// sub_080B38A8 @ 0x080B38A8
/* Automap open/close steps (gFieldState.unk1E); returns 1 when open, -1 when closed. */
s32 sub_080B38A8(void)
{
    s32 result = 0;

    switch (gFieldState.unk1E)
    {
    case 0:
        sub_080C14FC();
        Tilemap_FillRect(0, gUnk_02000000, 1, 0, 0x1C, 0x0D);
        DmaFill16(3, 0, gUnk_03002EB0, 0x100);
        VBlankTask_AddCounted(BgPicture_SetupStepTask, 1);
        break;
    case 2:
        if (BgPicture_LoadStep(0) == 1)
            gFieldState.unk1E++;
        break;
    case 6:
    {
        u16 i;
        u8 *p;

        sub_080B0778();
        gFieldState.unk1E++;
        p = (u8 *)gPaletteBuffer;
        for (i = 0; i < 32; i++, p++)
        {
            if (*p != 0)
                break;
        }
        if (i == 32)
        {
            PalFade_FadeRangeInFromBlack(0, 0x80, 1);
            PalFade_FadeRangeInFromBlack(0x100, 0xD0, 1);
        }
        break;
    }
    case 7:
        if (PalFade_AllDone() == 1)
        {
            gFieldState.unk1E++;
            gHudState[0x1A] = 0;
            if (Flag_Test(0x105))
            {
                Flag_Clear(0x102);
                Flag_Clear(0x106);
                Flag_Clear(0x105);
            }
        }
        break;
    case 8:
        result = 1;
        break;
    case 9:
        if (sub_080B092C() == 0)
        {
            sub_080C14FC();
            gFieldState.unk1E = 0x14;
            sub_080B7530(0);
        }
        break;
    case 0x1C:
        sub_080C3818(1);
        if (View_IsSideOpen(0) == 0 && View_IsSideOpen(1) == 0 && View_IsSideOpen(3) == 0)
        {
            gFieldState.unk02 = sub_080B1A1C(gFieldState.unk02);
            sub_080B2030(gFieldState.unk0A, gFieldState.unk02, 3);
        }
        else
        {
            sub_080B05A4();
            Field_SetState(0x1F);
            sub_080B2840(0, 0, 0);
            gFieldState.unk1E = 0;
        }
        result = -1;
        break;
    default:
        VBlankTask_AddCounted(BgPicture_SetupStepTask, 1);
        break;
    }
    return result;
}


// sub_080B3ADC @ 0x080B3ADC
void sub_080B3ADC(void)
{
    DmaCopy32S(3, gBgPictureBuffer, (void *)0x06004040, 0x1000);
}

// sub_080B3B00 @ 0x080B3B00
void sub_080B3B00(void)
{
    DmaCopy32S(3, gBgPictureBuffer, (void *)0x06005040, 0xFC0);
    DmaCopy32S(3, gBgPictureBuffer + 0xFC0, (void *)0x06008040, 0x40);
}

// sub_080B3B3C @ 0x080B3B3C
void sub_080B3B3C(void)
{
    DmaCopy32S(3, gBgPictureBuffer, (void *)0x06008080, 0x1000);
}

// sub_080B3B60 @ 0x080B3B60
void sub_080B3B60(void)
{
    u8 *src = gBgPictureBuffer;

    if (gUnk_03003BA0 == 0)
    {
        DmaCopy32S(3, src, (void *)0x06009080, 0x1000);
    }
    else
    {
        DmaCopy32S(3, src, (void *)0x06008E00, 0x1000);
    }
}

// sub_080B3BA4 @ 0x080B3BA4
void sub_080B3BA4(void)
{
    u8 *src = gBgPictureBuffer;

    if (gUnk_03003BA0 == 0)
    {
        DmaCopy32S(3, src, (void *)0x0600A080, 0x1000);
    }
    else
    {
        DmaCopy32S(3, src, (void *)0x06009E00, 0x1000);
    }
}

// sub_080B3BE8 @ 0x080B3BE8
void sub_080B3BE8(void)
{
    u8 *src = gBgPictureBuffer;

    if (gUnk_03003BA0 == 0)
    {
        DmaCopy32S(3, src, (void *)0x0600B080, 0xB00);
    }
    else
    {
        DmaCopy32S(3, src, (void *)0x0600AE00, 0xD80);
    }
}

// sub_080B3C34 @ 0x080B3C34
void sub_080B3C34(u32 idx, u32 now)
{
    VoidFunc func = gUnknown_081625D4[idx];

    if (func != NULL)
    {
        if (now == 0)
            VBlankTask_AddCounted(func, 1);
        else
            func();
    }
}

// BgPicture_LoadPiece @ 0x080B3C5C
/* Loads the next piece (gBgPicturePiece) of the background picture into the buffer at
   0x0200AFC8 and queues its upload (sub_080B3C34). Huffman pieces take two calls: the
   Huffman stage goes to buffer+0x1000 and bit 15 of the piece index is set, the next call
   LZ77-decodes that into the buffer. gBgPicturePiece becomes 0xFFFF when all are done; with
   gUnk_03003BA0 set the pieces from 8 on are uploaded through slots 3 and up. */
void BgPicture_LoadPiece(u32 now)
{
    u16 *map = &gUnk_03004534; /* declared before bg: wins the register tie with it */
    struct BgPicture *bg = sub_080C5EF0(*map);
    const void *src;
    const void *src2;
    u16 huff2;
    u32 zero;

    if (gUnk_03003BA0 == 0)
    {
        u32 huff = gBgPicturePiece & 0x8000; /* one variable per half */
        if (huff)
        {
            gBgPicturePiece &= 0x7FFF;
            LZ77UnCompWram(gBgPictureBuffer + 0x1000, gBgPictureBuffer);
            sub_080B3C34(gBgPicturePiece, now);
            gBgPicturePiece++;
        }
        else
        {
            src = sub_080C5F04(*map, gBgPicturePiece);
            if (src != NULL)
            {
                zero = huff;
                CpuFastSet(&zero, gBgPictureBuffer, 0x01000400);
                if (bg->kind == 1)
                {
                    LZ77UnCompWram(src, gBgPictureBuffer);
                    sub_080B3C34(gBgPicturePiece, now);
                    gBgPicturePiece++;
                }
                else if (bg->kind == 2)
                {
                    HuffUnComp(src, gBgPictureBuffer + 0x1000);
                    gBgPicturePiece |= 0x8000;
                }
            }
            else
            {
                gBgPicturePiece = 0xFFFF;
            }
        }
        return;
    }

    huff2 = gBgPicturePiece & 0x8000;
    if (huff2)
    {
        gBgPicturePiece &= 0x7FFF;
        LZ77UnCompWram(gBgPictureBuffer + 0x1000, gBgPictureBuffer);
        if (gBgPicturePiece < 8)
            sub_080B3C34(gBgPicturePiece, now);
        else
            sub_080B3C34(gBgPicturePiece - 5, now);
        gBgPicturePiece++;
        return;
    }
    src2 = sub_080C5F04(*map, gBgPicturePiece);
    if (src2 != NULL)
    {
        zero = huff2;
        CpuFastSet(&zero, gBgPictureBuffer, 0x01000400);
        if (gBgPicturePiece < 8)
        {
            if (bg->kind == 1)
            {
                LZ77UnCompWram(src2, gBgPictureBuffer);
                sub_080B3C34(gBgPicturePiece, now);
                gBgPicturePiece++;
            }
            else if (bg->kind == 2)
            {
                HuffUnComp(src2, gBgPictureBuffer + 0x1000);
                gBgPicturePiece |= 0x8000;
            }
        }
        else
        {
            if (bg->kind == 1)
            {
                LZ77UnCompWram(src2, gBgPictureBuffer);
                sub_080B3C34(gBgPicturePiece - 5, now);
                gBgPicturePiece++;
            }
            else if (bg->kind == 2)
            {
                HuffUnComp(src2, gBgPictureBuffer + 0x1000);
                gBgPicturePiece |= 0x8000;
            }
        }
    }
    else
    {
        if (gBgPicturePiece < 8)
            gBgPicturePiece = 8;
        else
            gBgPicturePiece = 0xFFFF;
    }
}
