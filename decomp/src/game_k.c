/* Background picture palettes and the picture loading steps. */

#include "global.h"
#include "game.h"

// BgPicture_LoadPalette @ 0x080B4140
void BgPicture_LoadPalette(void)
{
    u16 *pal = sub_080C5F60(gUnk_03004534);

    if (gUnk_03004534 != 0x77)
    {
        if (gUnk_03004534 == 0xDA)
            Palette_CopyWithEffect(3, pal, &gPaletteTarget[0x70], 0x20, 0x20);
        else
            Palette_CopyWithEffect(3, pal, &gPaletteTarget[0x80], 0x100, 0x20);
    }
    else
    {
        DmaFill32(3, 0, &gPaletteTarget[0x80], 0x100);
    }
}

// sub_080B41B0 @ 0x080B41B0
void sub_080B41B0(void)
{
    BgPicture_LoadPalette();
    REG_DISPCNT |= 0x800;
}

// sub_080B41CC @ 0x080B41CC
void sub_080B41CC(void)
{
    REG_BG3CNT = 0x8607;
    REG_DISPCNT &= ~0x800;
    gUnk_0300000E = 0;
}

// BgPicture_SetupStepTask @ 0x080B41F8
/* VBlank task: one step of the background picture setup per call (step = unk1E). */
void BgPicture_SetupStepTask(void)
{
    sub_080C5EF0(gUnk_03004534);
    switch (gFieldState.unk1E)
    {
    case 0:
        sub_080B3E7C();
        break;
    case 1:
        sub_080B3E8C();
        break;
    case 3:
        sub_080B3ED0();
        break;
    case 4:
        BgPicture_BuildTilemap();
        break;
    case 5:
        sub_080B41B0();
        break;
    case 0x15:
        sub_080B41CC();
        break;
    case 0x16:
        DmaFill32(3, 0, (void *)0x02028074, 0x20);
        DmaCopy32(3, gUnk_03003B94, (void *)0x06004000, 0x2000);
        break;
    case 0x17:
    {
        u16 *pal = gUnk_03004630;

        gPaletteTarget[0] = *pal;
        Palette_CopyWithEffect(3, pal, &gPaletteTarget[0xE0], 0x40, 0x20);
        break;
    }
    case 0x18:
        Palette_CopyWithEffect(3, gUnk_03004510, &gPaletteTarget[0xD0], 0x20, 0x20);
        break;
    case 0x19:
        sub_080ADF64();
        break;
    case 0x14:
    case 0x1A:
        sub_080C153C();
        break;
    case 0x1B:
        REG_DISPCNT |= 0x800;
        gUnk_0200AB04 &= ~0x8000;
        break;
    }
    gFieldState.unk1E++;
}

// BgPicture_LoadAll @ 0x080B437C
/* Loads the whole background picture at once. */
void BgPicture_LoadAll(void)
{
    sub_080C14FC();
    Tilemap_FillRect(0, gUnk_02000000, 1, 0, 0x1C, 0x0D);
    sub_080B3E7C();
    sub_080B3E8C();
    while (BgPicture_LoadStep(1) != 1)
        ;
    sub_080B3ED0();
    BgPicture_BuildTilemap();
    sub_080B41B0();
}

/* NONMATCHING: agbcc reuses the register holding done (== 1) for the final store; the original loads the constant again. */
// sub_080B43C0 @ 0x080B43C0
/* Script task: scrolls BG1 vertically (0x0300000E) every other frame; task+0x24 = steps left,
   task+0x26 = 1 to scroll up. */
void sub_080B43C0(u8 *task)
{
    u16 *args = (u16 *)(task + 0x24);
    u32 done = 0;

    *(u16 *)(task + 0x1C) = 0;
    if (!(gFrameCounter & 1))
    {
        if (*(u16 *)(task + 0x24) != 0)
        {
            if (args[1] == 1)
            {
                if (gUnk_0300000E != 0)
                    gUnk_0300000E -= args[1];
            }
            else
            {
                gUnk_0300000E++;
            }
            args[0]--;
        }
        else
        {
            done = 1;
        }
    }
    if (done == 1)
    {
        /* A fresh 1: CSE would otherwise store `done`, known to be 1 here. */
        register u32 one asm("r0") = 1;
        *(u16 *)(task + 0x1C) = one;
    }
}


// sub_080B4420 @ 0x080B4420
u8 *sub_080B4420(u16 steps, u16 up)
{
    u8 *task = Task_Create(gUnknown_081625F4, 0xFFFF);

    *(u16 *)(task + 0x24) = steps;
    *(u16 *)(task + 0x26) = up;
    return task;
}

// sub_080B4448 @ 0x080B4448
u16 sub_080B4448(const u32 *p)
{
    const struct Unk08162618 *e = gUnknown_08162618;
    u32 i;

    for (i = 0; i <= 0x50; e++, i++)
    {
        if (p[1] == e->a && p[2] == e->b)
            return e->value;
    }
    return 0x3B4;
}
