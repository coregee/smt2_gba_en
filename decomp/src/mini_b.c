#include "global.h"
#include "extras.h"

// sub_080DE0DC @ 0x080DE0DC
void sub_080DE0DC(void)
{
    if (sub_080DE0F8())
    {
        sub_080DE208();
        Task_RunAll();
        PlayTime_Tick();
    }
}

/* Loads the mini program's graphics one piece per frame; 1 when done. */
// sub_080DE0F8 @ 0x080DE0F8
u8 sub_080DE0F8(void)
{
    u8 *buf;

    switch (gC0d9Bg.unk36)
    {
    case 0:
        LZ77UnCompWram(gUnknown_08587130, (void *)0x02001000);
        gC0d9Bg.unk36++;
        return 0;
    case 1:
        LZ77UnCompWram(gUnknown_085874EC, buf = gUnk_02002000);
        DmaSet3((buf -= 0x1000), 0x06004000, 0x84000800);
        gC0d9Bg.unk36++;
        return 0;
    case 2:
        LZ77UnCompWram(gUnknown_08588050, gUnk_02001000);
        gC0d9Bg.unk36++;
        return 0;
    case 3:
        LZ77UnCompWram(gUnknown_085887D4, gUnk_02002000);
        gC0d9Bg.unk36++;
        return 0;
    case 4:
        LZ77UnCompWram(gUnknown_08588FA4, gUnk_02003000);
        gC0d9Bg.unk36++;
        return 0;
    case 5:
        LZ77UnCompWram(gUnknown_0858979C, buf = gUnk_02004000);
        DmaSet3((buf -= 0x3000), 0x06008000, 0x84000E00);
        gC0d9Bg.unk36++;
        gC0d9Bg.fade = PalFade_FadeInFromBlack(1);
    default:
        return 1;
    }
    gC0d9Bg.unk36++;
    return 0;
}

// sub_080DE208 @ 0x080DE208
void sub_080DE208(void)
{
    if (sub_080DE21C())
        sub_080DE258();
}

/* 1 when the fade is over and nothing is pending; exit 1 leaves to sub_080D9608. */
// sub_080DE21C @ 0x080DE21C
u8 sub_080DE21C(void)
{
    if (*gC0d9Bg.fade != 0)
        return 0;
    switch (gC0d9Bg.exit)
    {
    case 0:
        return 1;
    case 1:
        SetMainCallback(sub_080D9608);
        break;
    }
    gC0d9Bg.exit = 0;
    return 0;
}

/* START fades out and leaves; otherwise runs the script and the rotation. */
// sub_080DE258 @ 0x080DE258
void sub_080DE258(void)
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
        Mini_StepTimeline1();
        Mini_ZoomBg2Affine();
    }
}
