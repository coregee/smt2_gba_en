#include "global.h"
#include "fieldevent.h"

// sub_080B4BE8 @ 0x080B4BE8
/* Decompresses one quarter of the automap sprite graphics and queues its upload. */
void sub_080B4BE8(u32 unused, const void *src, u32 part)
{
    LZ77UnCompWram(src, gBgPictureBuffer);
    switch (part)
    {
    case 0:
        VBlankTask_AddCounted(sub_080B4B58, 1);
        break;
    case 1:
        VBlankTask_AddCounted(sub_080B4B7C, 1);
        break;
    case 2:
        VBlankTask_AddCounted(sub_080B4BA0, 1);
        break;
    case 3:
        VBlankTask_AddCounted(sub_080B4BC4, 1);
        gUnk_03003FEC = 0;
        break;
    }
}

// Automap_Update @ 0x080B4C48
/* Automap screen, one step per frame; the step is gFieldState.unk1E. */
void Automap_Update(void)
{
    switch (gFieldState.unk1E)
    {
    case 0:
        sub_080C14FC();
        gFieldState.unk1E = 10;
        if (gPaletteBuffer[0] != 0)
            gPaletteBuffer[0] = 0;
        Palette_FillWithEffect(3, 0, &gPaletteBuffer[0xE0], 0x40, 0x20);
        Palette_FillWithEffect(3, 0, &gPaletteBuffer[0xD0], 0x20, 0x20);
        Palette_FillWithEffect(3, 0, &gPaletteBuffer[0x1D0], 0x20, 0x10);
        Palette_MarkDirty();
        Font_ResetGlyphSpriteCache(0x180);
        gUnk_03003FFC = 0;
        sub_080C7C60();
        break;
    case 0xF:
        gUnk_03003FEC = Task_Create(gTitleMenuLoadScript, 0xFFFF);
        gFieldState.unk1E = 0x10;
        break;
    case 0x10:
        if (gUnk_03003FEC == 0)
            gFieldState.unk1E = 0x12;
        break;
    case 0x32:
        sub_080C14FC();
        gFieldState.unk1E++;
        Automap_BuildAroundPlayer();
        break;
    case 0x33:
        if (gUnk_0200E7D4[6] == 0)
        {
            Automap_DrawTilemap();
            gFieldState.unk1E++;
            gUnk_030045F8 = Window_Create(2, 0xB, 0x1A, 2, 0);
        }
        break;
    case 0x34:
        if (!Window_IsIdle(gUnk_030045F8))
            break;
        if ((gFieldState.unk3A & 0x200) || (gFieldState.unk3A & 2))
        {
            sub_080C14FC();
            gFieldState.unk1E = 100;
            if (gPaletteBuffer[0] != 0)
                gPaletteBuffer[0] = 0;
            Palette_FillWithEffect(3, 0, &gPaletteBuffer[0xE0], 0x40, 0x20);
            Palette_FillWithEffect(3, 0, &gPaletteBuffer[0xD0], 0x20, 0x20);
            Palette_FillWithEffect(3, 0, &gPaletteBuffer[0x1D0], 0x20, 0x10);
            Palette_MarkDirty();
            sub_080C7848();
            Window_Close(gUnk_030045F8, 1);
            if (gFieldState.unk32 == 0)
                sub_080C7C94();
            Sound_Play(0x66);
            break;
        }
        if ((gFieldState.unk3C & 0x80) && gUnk_0200DFC8 == 1)
        {
            if (gAutomapScroll >= 0 || Automap_HasCells() == 1)
            {
                gAutomapScroll--;
                gFieldState.unk1E = 0x37;
                Automap_BuildAroundPlayer();
            }
        }
        else if ((gFieldState.unk3C & 0x40) && gUnk_0200DFCA == 1)
        {
            if (gAutomapScroll <= 0 || Automap_HasCells() == 1)
            {
                gAutomapScroll++;
                gFieldState.unk1E = 0x37;
                Automap_BuildAroundPlayer();
            }
        }
        else if (gFieldState.unk3A & 4)
        {
            gUnk_03003FF0 = Window_CreateOpen(2, 2, 0x1A, 8, 0);
            gFieldState.unk1E = 0x35;
            Sound_Play(0x65);
        }
        else if (gFieldState.unk3A & 1)
        {
            sub_080B5D00();
            gFieldState.unk1E = 0x36;
            MarkerHeader_DrawLocationName(0, 0, 0x12, 0x59, 0xC);
            Sound_Play(0x65);
        }
        Automap_DrawSprites();
        break;
    case 0x35:
        if (Window_IsIdle(gUnk_03003FF0) == 1)
        {
            if (gFieldState.unk3A & 2)
            {
                Window_Close(gUnk_03003FF0, 1);
                gFieldState.unk1E = 0x34;
                gUnk_0200DFD0 = 0;
                Sound_Play(0x66);
            }
            else if (gUnk_0200DFD0 == 0 && (gFieldState.unk3A & 0x80))
            {
                gUnk_0200DFD0 = 1;
                Sound_Play(0x64);
            }
            else if (gUnk_0200DFD0 == 1 && (gFieldState.unk3A & 0x40))
            {
                gUnk_0200DFD0 = 0;
                Sound_Play(0x64);
            }

            if (gUnk_0200DFD0 == 0)
            {
                Sprite_Draw(gUnknown_08000410, 0, 0, 0, 0x240, 0x5C, 0x18);
                if (!((gFrameCounter >> 4) & 1))
                    sub_080C4AB0(0, 0, 0xD6, 0x48);
            }
            else
            {
                Sprite_Draw(gUnknown_08000470, 0, 0, 0, 0x240, 0x5C, 0x18);
                if (!((gFrameCounter >> 4) & 1))
                    sub_080C4A4C(0, 0, 0xD6, 0x14);
            }
        }
        Automap_DrawSprites();
        break;
    case 0x36:
        Automap_DrawSprites();
        break;
    case 0x37:
        Tilemap_CopyRectSkipZero(gUnknown_081B8D70, gUnk_02000000, 0, 0, 1, 0, 0x1C, 0xD);
        Automap_DrawTilemap();
        gFieldState.unk1E = 0x34;
        gUnk_0200DFCE = gAutomapScroll;
        Automap_DrawSprites();
        break;
    case 200:
        if (gFieldState.unk50 == 2)
            gFieldState.unk50 = 1;
        sub_080B2840(1, 0, 0);
        gFieldState.unk1E = 0xC;
        gFieldState.unk06 = gFieldState.unk02;
        Field_SetState(0x11);
        break;
    default:
        VBlankTask_AddCounted(Automap_VBlankStep, 1);
        break;
    }
}

// sub_080B5084 @ 0x080B5084
void sub_080B5084(void)
{
    sub_080C153C();
}

// sub_080B5090 @ 0x080B5090
void sub_080B5090(void)
{
    DmaFill32(3, 0, (void *)0x02005004, 0x4000);
    sub_080B2880();
}

// Automap_VBlankStep @ 0x080B50C0
/* VBlank half of the automap screen steps. */
void Automap_VBlankStep(void)
{
    switch (gFieldState.unk1E)
    {
    case 0xB:
        REG_BG3CNT = 0x860B;
        gFieldState.unk2E = 0x22;
        break;
    case 0xC:
        sub_080B5090();
        break;
    case 0xD:
        DmaCopy32(3, gUnknown_081A91B8, (void *)0x0600BC00, 0x4400);
        Tilemap_CopyRectSkipZero(gUnknown_081B8D70, gUnk_02000000, 0, 0, 1, 0, 0x1C, 0xD);
        break;
    case 0xE:
        DmaCopy32(3, gUnk_02000000, (void *)0x06003000, 0x1000);
        break;
    case 0x12:
        gFieldState.unk1E = 0x32;
        sub_080C7864();
        return;
    case 0x64:
        if (gUnk_0200E7D4[6] == 3)
        {
            if (gFieldState.unk32 == 0)
            {
                sub_080C7234();
                sub_080C700C();
                sub_080C7430();
            }
    case 0xA:
    case 0x32:
            sub_080C153C();
        }
        else
        {
            gFieldState.unk1E = 0x63;
        }
        break;
    case 0x65:
        REG_BG3CNT = 0x8607;
        sub_080ADF64();
        gFieldState.unk1E = 200;
        return;
    }
    gFieldState.unk1E++;
}
