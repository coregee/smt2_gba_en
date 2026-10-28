/* Field palette fades and VCOUNT/HBlank raster effects. */

#include "global.h"
#include "game.h"

// sub_080B04BC @ 0x080B04BC
void sub_080B04BC(void)
{
    if (FieldMap_HasRecordRel(0, 0, 6) == 0)
    {
        u16 *pal = gUnk_03004630;
        gPaletteTarget[0] = *pal;
        Palette_CopyWithEffect(3, pal, &gPaletteTarget[0xE0], 0x40, 0x20);
        Palette_CopyWithEffect(3, gUnk_03004510, &gPaletteTarget[0xD0], 0x20, 0x20);
        if (gMainCallback != sub_080D977C)
            Palette_CopyWithEffect(3, gUnk_03003FC8, &gPaletteTarget[0x1D0], 0x20, 0x10);
    }
    else
    {
        u16 *pal = gUnk_0200F814;
        gPaletteTarget[0] = *pal;
        Palette_CopyWithEffect(3, pal, &gPaletteTarget[0xE0], 0x40, 0x20);
        Palette_CopyWithEffect(3, gUnk_0200F7F4, &gPaletteTarget[0xD0], 0x20, 0x20);
        if (gMainCallback != sub_080D977C)
            Palette_CopyWithEffect(3, gUnk_0200F854, &gPaletteTarget[0x1D0], 0x20, 0x10);
    }
}

// sub_080B05A4 @ 0x080B05A4
void sub_080B05A4(void)
{
    u16 delay = 1;
    u32 r = Palette_IsBg13Black();

    if (r == 0)
    {
        gUnk_0300452C = (struct PalFade *)r;
    }
    else
    {
        sub_080B04BC();
        if (Flag_Test(0x105))
        {
            Flag_Set(0x102);
            Flag_Set(0x106);
            delay = 4;
        }
        gUnk_0300452C = PalFade_FadeRangeInFromBlackTagged(0xD0, 0x30, delay, 0x8001);
        PalFade_FadeRangeInFromBlack(0x1D0, 0x10, delay);
        if (gPaletteTarget[0] != 0)
            PalFade_FadeRangeInFromBlack(0, 1, delay);
    }
}

// sub_080B0620 @ 0x080B0620
void sub_080B0620(void)
{
    if (Palette_IsBg13Black() == 1)
    {
        gUnk_0300452C = NULL;
    }
    else
    {
        gUnk_0300452C = PalFade_FadeRangeToBlackTagged(0xD0, 0x30, 1, 0x8001);
        PalFade_FadeRangeToBlack(0x1D0, 0x10, 1);
        if (gPaletteBuffer[0] != 0)
            PalFade_FadeRangeToBlack(0, 1, 1);
    }
}

// sub_080B0678 @ 0x080B0678
void sub_080B0678(void)
{
    u16 *pal = gUnk_03004630;
    gPaletteTarget[0] = *pal;
    Palette_CopyWithEffect(3, pal, &gPaletteTarget[0xE0], 0x40, 0x20);
    Palette_CopyWithEffect(3, gUnk_03004510, &gPaletteTarget[0xD0], 0x20, 0x20);
    Palette_CopyWithEffect(3, gUnk_03003FC8, &gPaletteTarget[0x1D0], 0x20, 0x10);
    gUnk_0300452C = PalFade_FadeRangeWithDuration(0xD0, 0x30, 1, 0x20);
    PalFade_FadeRangeWithDuration(0x1D0, 0x10, 1, 0x20);
}

// sub_080B06FC @ 0x080B06FC
void sub_080B06FC(void)
{
    u16 *pal;

    gUnk_0300452C = PalFade_FadeRangeToBlack(0xD0, 0x30, 1);
    PalFade_FadeRangeToBlack(0x1D0, 0x10, 1);
    pal = gUnk_0200F814;
    gPaletteTarget[0] = *pal;
    Palette_CopyWithEffect(3, pal, &gPaletteTarget[0xE0], 0x40, 0x20);
    Palette_CopyWithEffect(3, gUnk_0200F7F4, &gPaletteTarget[0xD0], 0x20, 0x20);
    Palette_CopyWithEffect(3, gUnk_0200F854, &gPaletteTarget[0x1D0], 0x20, 0x10);
}

// sub_080B0778 @ 0x080B0778
void sub_080B0778(void)
{
    u16 delay = 1;
    u32 r = Palette_IsBg13Black();
    if (r == 0)
    {
        gUnk_0300452C = (struct PalFade *)r;
    }
    else
    {
        if (Flag_Test(0x105))
        {
            Flag_Set(0x102);
            Flag_Set(0x106);
            delay = 4;
        }
        if (gUnk_03004534 == 0xDA)
            gUnk_0300452C = PalFade_FadeRangeInFromBlackTagged(0x70, 0x10, delay, 0x8001);
        else
            gUnk_0300452C = PalFade_FadeRangeInFromBlackTagged(0x80, 0x80, delay, 0x8001);
        if (Flag_Test(0x10D))
        {
            gUnk_0300452C->duration = 8;
            Flag_Clear(0x10D);
        }
        if (Flag_Test(0xFD))
        {
            gUnk_0300452C->delay = 10;
            gUnk_0300452C->timer = 10;
            Flag_Clear(0xFD);
        }
    }
}

// sub_080B0820 @ 0x080B0820
void sub_080B0820(void)
{
    if (Palette_IsBg13Black() == 1)
    {
        gUnk_0300452C = NULL;
    }
    else
    {
        if (gUnk_03004534 == 0xDA)
            gUnk_0300452C = PalFade_FadeRangeToBlackTagged(0x70, 0x10, 1, 0x8001);
        else
            gUnk_0300452C = PalFade_FadeRangeToBlackTagged(0x80, 0x80, 1, 0x8001);
        sub_080C3818(0);
        if (gPaletteBuffer[0] != 0)
            PalFade_FadeRangeToBlack(0, 1, 1);
    }
}

// sub_080B0888 @ 0x080B0888
void sub_080B0888(void)
{
    if (!(gUnk_0200AB04 & 0x8000))
        PalFade_FadeRangeToBlackWithDuration(0xD0, 0x30, 1, 6);
}

// sub_080B08AC @ 0x080B08AC
void sub_080B08AC(void)
{
    u16 *pal;
    if (gUnk_0200AB04 & 0x8000)
    {
        pal = sub_080C5F60(gUnk_03004534);
        if (gUnk_03004534 == 0xDA)
        {
            Palette_CopyWithEffect(3, pal, &gPaletteTarget[0x70], 0x20, 0x20);
            PalFade_FadeRangeWithDuration(0x70, 0x10, 1, 0x10);
        }
        else
        {
            Palette_CopyWithEffect(3, pal, &gPaletteTarget[0x80], 0x100, 0x20);
            PalFade_FadeRangeWithDuration(0x80, 0x80, 1, 0x10);
        }
    }
    else
    {
        sub_080B04BC();
        PalFade_FadeRangeWithDuration(0xD0, 0x30, 1, 0x10);
    }
}

// sub_080B092C @ 0x080B092C
u32 sub_080B092C(void)
{
    u16 active;

    if (gUnk_0300452C == NULL)
        return 0;
    active = PalFade_IsActive(gUnk_0300452C);
    if (active == 0 && Flag_Test(0x105))
    {
        Flag_Clear(0x102);
        Flag_Clear(0x106);
        Flag_Clear(0x105);
    }
    return active;
}

// sub_080B097C @ 0x080B097C
void sub_080B097C(u8 *task)
{
    *(u16 *)(task + 0x1E) = sub_080B092C();
}

// Palette_IsBg13Black @ 0x080B098C
/* TRUE when all 32 bytes at 0x03002F50 are zero. */
u32 Palette_IsBg13Black(void)
{
    u8 *p = gUnk_03002F50;
    u16 i;

    for (i = 0; i < 32; i++, p++)
    {
        if (*p != 0)
            return 0;
    }
    return 1;
}

// sub_080B09B4 @ 0x080B09B4
void sub_080B09B4(u8 *task)
{
    *(u16 *)(task + 0x1E) = Palette_IsBg13Black();
}

// sub_080B09C4 @ 0x080B09C4
void sub_080B09C4(u16 x, u16 y)
{
    if (FieldMap_HasRecordRel(0, 0, 6) == 1)
    {
        if (FieldMap_HasRecordRel(x, y, 6) == 0)
            sub_080B0678();
    }
    else
    {
        if (FieldMap_HasRecordRel(x, y, 6) == 1)
            sub_080B06FC();
    }
}

// sub_080B0A08 @ 0x080B0A08
void sub_080B0A08(u16 a)
{
    if (sub_080B092C() == 0)
    {
        gFieldState.unk2E = 0;
        gUnk_03003FF4 = 1;
        if (sub_080AF8D0(2, 2, 0) == 0)
        {
            if (gFieldState.unk46 == 1)
                Field_SetState(1);
            else
                sub_080B03BC(1);
        }
        gFieldState.unk46 = 0;
        gUnk_03003FF4 = 0;
        if (a == 1)
            Automap_SetVisitedAhead(gFieldState.unk12, gFieldState.unk14, gFieldState.unk02);
    }
}

// sub_080B0A78 @ 0x080B0A78
void sub_080B0A78(void)
{
    REG_IE |= 4;
    REG_DISPSTAT &= 0xFF;
    REG_DISPSTAT |= 0x6724;
    REG_BG2CNT |= 0x40;
    REG_BG3CNT |= 0x40;
}

// sub_080B0ABC @ 0x080B0ABC
void sub_080B0ABC(void)
{
    REG_BG2CNT &= ~0x40;
    REG_BG3CNT &= ~0x40;
}

// sub_080B0AE0 @ 0x080B0AE0
void sub_080B0AE0(void)
{
    gIntrTable[2] = sub_080B0ABC;
    VBlankTask_AddCountedAlways(sub_080B0A78, 1);
}

// sub_080B0B00 @ 0x080B0B00
void sub_080B0B00(void)
{
    REG_IE &= ~4;
    REG_DISPSTAT &= ~0x24;
    REG_BG2CNT &= ~0x40;
    REG_BG3CNT &= ~0x40;
    gIntrTable[2] = IntrDummy;
}

// sub_080B0B54 @ 0x080B0B54
void sub_080B0B54(void)
{
    VBlankTask_AddCountedAlways(sub_080B0B00, 1);
}

// sub_080B0B68 @ 0x080B0B68
void sub_080B0B68(void)
{
    REG_IE |= 2;
    REG_DISPSTAT |= 0x10;
}

// sub_080B0B88 @ 0x080B0B88
void sub_080B0B88(void)
{
    REG_IE &= ~2;
    REG_DISPSTAT &= ~0x10;
    gIntrTable[1] = IntrDummy;
}

// Field_HBlankWobble @ 0x080B0BBC
/* HBlank handler: wobbles BG2/BG3 vertically on the top 100 lines. */
void Field_HBlankWobble(void)
{
    u8 line = *(u8 *)0x04000006;  /* REG_VCOUNT low byte */

    if (line < 100)
    {
        REG_BG2VOFS = (gSineTable[(gFieldState.unk52 + line) & 0xFF] / 4) & 3;
        REG_BG3VOFS = (gSineTable[(gFieldState.unk52 + line) & 0xFF] / 4) & 3;
    }
    else
    {
        REG_BG2VOFS = 0;
        REG_BG3VOFS = 0;
    }
}

// sub_080B0C38 @ 0x080B0C38
void sub_080B0C38(void)
{
    gIntrTable[1] = Field_HBlankWobble;
    if (!(gFrameCounter & 7))
        gFieldState.unk52 = (gFieldState.unk52 + 1) & 0xFF;
    VBlankTask_AddCountedAlways(sub_080B0B68, 1);
}

// sub_080B0C7C @ 0x080B0C7C
void sub_080B0C7C(void)
{
    VBlankTask_AddCountedAlways(sub_080B0B88, 1);
}
