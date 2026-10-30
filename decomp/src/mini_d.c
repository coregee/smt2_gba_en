#include "global.h"
#include "extras.h"

// sub_080DEA9C @ 0x080DEA9C
void sub_080DEA9C(void)
{
    if (sub_080DEAB0())
        sub_080DEAE4();
}

/* 1 while the fade runs or nothing is pending; exit 1 goes back to the title (sub_080D5B8C(3)). */
// sub_080DEAB0 @ 0x080DEAB0
u8 sub_080DEAB0(void)
{
    if (*gC0d9Bg.fade != 0)
        return 1;
    switch (gC0d9Bg.exit)
    {
    case 0:
        return 1;
    case 1:
        sub_080D5B8C(3);
        break;
    }
    gC0d9Bg.exit = 0;
    return 0;
}

// sub_080DEAE4 @ 0x080DEAE4
void sub_080DEAE4(void)
{
    if (gKeysNew & 8)
    {
        REG_DISPCNT &= 0xF0FF;
        gC0d9Bg.fade[0] = 1;
        *(s16 *)&gC0d9Bg.exit = 1;    /* stored as s16: the reused constant needs it */
        memset(gPaletteTarget, 0, 0x400);
        memset(gPaletteBuffer, 0, 0x400);
        Palette_MarkDirty();
    }
    else
    {
        Mini_StepTimeline2();
        Mini_UpdateBg2Affine();
    }
}
