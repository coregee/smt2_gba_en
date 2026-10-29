#include "global.h"
#include "fieldcmd.h"

// sub_080BDE1C @ 0x080BDE1C
void sub_080BDE1C(u16 id)
{
    if (!Flag_Test(0x10A))
        return;
    switch (id)
    {
    case 0x10F:
        sub_080E8F80(1, 0xA1, 0x56, 3);
        break;
    case 0x110:
        sub_080E8F80(0, 0x50, 0x56, 3);
        break;
    case 0x125:
        sub_080E8F80(0, 0x78, 0x6A, 3);
        break;
    case 0x128:
        sub_080E8F80(0, 0x78, 0x6A, 3);
        break;
    case 0x103:
    case 0x111:
    case 0x113:
    case 0x114:
    case 0x115:
    case 0x118:
    case 0x119:
    case 0x11A:
    case 0x11B:
    case 0x11C:
    case 0x11D:
    case 0x11E:
    case 0x11F:
    case 0x120:
    case 0x121:
    case 0x122:
    case 0x123:
    case 0x124:
    case 0x126:
    case 0x127:
    case 0x129:
    case 0x12A:
    case 0x12B:
    case 0x12C:
    case 0x12E:
    case 0x12F:
        sub_080E8F80(0, 0x78, 0x56, 3);
        break;
    case 0x12D:
        sub_080E8F80(0, 0x78, 0x56, 3);
        break;
    }
}

// sub_080BDF3C @ 0x080BDF3C
void sub_080BDF3C(u16 id)
{
    if (!Flag_Test(0x10A))
        return;
    switch (id)
    {
    case 0x22:
        gUnk_0300000E = 0x48;
        break;
    case 0x3A:
        gUnk_0300000E = 0x68;
        break;
    case 0x51:
        gUnk_0300000E = 0x40;
        break;
    case 0x70:
        gUnk_0300000E = 0x20;
        break;
    case 0x53:
        gUnk_0300000E = 0x40;
        break;
    case 0x5D:
        gUnk_0300000E = 0x40;
        break;
    case 0x5E:
        gUnk_0300000E = 0x40;
        break;
    case 0x54:
        gUnk_0300000E = 0x40;
        break;
    case 0x3B:
    case 0x3C:
    case 0x50:
        gUnk_0300000E = 0x60;
        break;
    }
}

// sub_080BE114 @ 0x080BE114
void sub_080BE114(void)
{
    PalFade_FadeRangeToBlack(0x80, 0x80, 1);
    PalFade_FadeRangeToBlack(0x1D0, 0x30, 1);
}

// sub_080BE130 @ 0x080BE130
/* Sets up the scroll task data: d[0] start scroll (BG3 shadow 0x0300000E), d[1] count,
   d[2]/d[3] scroll period/timer, d[4]/d[5] count period/timer, by event and picture. */
void sub_080BE130(struct Task *task)
{
    u16 *d = task->data.h;
    struct Unk0203C200 *st = &gUnk_0203C200;

    task->data.h[0] = gUnk_0300000E;
    d[1] = 0;
    d[2] = 4;
    d[3] = 4;
    d[4] = 2;
    d[5] = 2;
    switch (st->unk990)
    {
    case 0x103:
    case 0x10F:
    case 0x110:
        d[1] = 0x28;
        break;
    case 0x115:
        d[1] = 5;
        d[5] = 7;
        d[4] = 7;
        break;
    case 0x123:
        d[1] = 0x1E;
        d[5] = 7;
        d[4] = 7;
        break;
    case 0x122:
        d[1] = 0x23;
        d[5] = 7;
        d[4] = 7;
        break;
    case 0x121:
        d[1] = 0x23;
        d[5] = 7;
        d[4] = 7;
        break;
    case 0x120:
        d[1] = 0x23;
        d[5] = 7;
        d[4] = 7;
        break;
    case 0x11F:
        d[1] = 0x23;
        d[5] = 7;
        d[4] = 7;
        break;
    case 0x11E:
        d[1] = 0x23;
        d[5] = 7;
        d[4] = 7;
        break;
    case 0x11D:
        d[1] = 0x23;
        d[5] = 7;
        d[4] = 7;
        break;
    case 0x11C:
        d[1] = 0x23;
        d[5] = 7;
        d[4] = 7;
        break;
    case 0x11B:
        d[1] = 0x23;
        d[5] = 7;
        d[4] = 7;
        break;
    case 0x11A:
        d[1] = 0x23;
        d[5] = 7;
        d[4] = 7;
        break;
    case 0x119:
        d[1] = 0x23;
        d[5] = 7;
        d[4] = 7;
        break;
    case 0x118:
        d[1] = 0x23;
        d[5] = 7;
        d[4] = 7;
        break;
    case 0x114:
        d[1] = 0x25;
        d[5] = 7;
        d[4] = 7;
        break;
    case 0x126:
        d[1] = 0x1E;
        d[5] = 8;
        d[4] = 8;
        break;
    case 0x12F:
        d[1] = 0x24;
        d[5] = 7;
        d[4] = 7;
        break;
    case 0x127:
        d[1] = 0x23;
        d[5] = 7;
        d[4] = 7;
        break;
    case 0x128:
        d[1] = 0xF;
        d[5] = 7;
        d[4] = 7;
        break;
    case 0x111:
    case 0x113:
    case 0x124:
    case 0x12C:
        d[1] = 0x22;
        d[5] = 7;
        d[4] = 7;
        break;
    }
    /* The same picture list as sub_080BDF3C; only 0x3B/0x3C scroll faster. */
    switch (gUnk_03004534)
    {
    case 0x22:
    case 0x3A:
    case 0x51:
    case 0x70:
    case 0x53:
    case 0x5D:
    case 0x5E:
    case 0x54:
    case 0x50:
        break;
    case 0x3B:
    case 0x3C:
        d[2] = 1;
        d[3] = 1;
        break;
    }
}

// sub_080BE3F4 @ 0x080BE3F4
void sub_080BE3F4(struct Task *task)
{
    u16 *d = task->data.h;
    struct Unk0203C200 *st = &gUnk_0203C200;

    task->result = 0;
    if (--d[3] == 0)
    {
        d[3] = d[2];
        if (task->data.h[0] != 0)
        {
            gUnk_0300000E--;
            task->data.h[0]--;
        }
    }
    if (--d[5] == 0)
    {
        d[5] = d[4];
        if (d[1] != 0)
        {
            st->unkDAA++;
            d[1]--;
            if (st->unk990 == 0x110)
                st->unkDEA++;
        }
    }
    if (*(u32 *)d == 0)
        task->result = 1;
}

// sub_080BE484 @ 0x080BE484
void sub_080BE484(void)
{
    Music_FadeOut(1);
}

// sub_080BE490 @ 0x080BE490
void sub_080BE490(void)
{
    PalFade_FadeRangeToWhite(0x1D0, 0x30, 4);
}

// sub_080BE4A4 @ 0x080BE4A4
void sub_080BE4A4(void)
{
    gUnk_0200AB04 = 0;
}

// sub_080BE4B0 @ 0x080BE4B0
void sub_080BE4B0(void)
{
    sub_080C3818(1);
    PalFade_Init(0);
}

// sub_080BE4C4 @ 0x080BE4C4
void sub_080BE4C4(void)
{
    gSceneEffectTask->wait = 1;
}

// sub_080BE4D4 @ 0x080BE4D4
void sub_080BE4D4(void)
{
    PalFade_FadeToBlack(1);
    gHudState[0x1A] = 1;
}

// sub_080BE4EC @ 0x080BE4EC
void sub_080BE4EC(struct Task *task)
{
    Casino_Start((task->data.h[0] & 0xF0) >> 4, task->data.h[0] & 0xF);
}

// sub_080BE504 @ 0x080BE504
void sub_080BE504(void)
{
    DmaFill32(3, 0, (void *)0x06000000, 0x4000);
    sub_080C1450();
}

// sub_080BE530 @ 0x080BE530
void sub_080BE530(void)
{
    DmaFill32(3, 0, gUnk_02028074, 0x20);
    DmaCopy32(3, gUnk_03003B94, (void *)0x06004000, 0x2000);
    sub_080ADF64();
}

// sub_080BE57C @ 0x080BE57C
/* Reload steps after returning to the field (step 0x100: fade in and resume). */
void sub_080BE57C(struct Task *task, u32 step)
{
    switch (step)
    {
    case 0:
        Font_ResetGlyphSpriteCache(0x180);
        sub_080C1328();
        sub_080C1384();
        VBlankTask_AddCounted(sub_080BE504, 1);
        break;
    case 1:
        sub_080C14FC();
        VBlankTask_AddCounted(sub_080C153C, 1);
        break;
    case 2:
        Party_BuildMemberNameTiles();
        Hud_LoadAllMemberFaces();
        sub_080C65C8();
        sub_080C6764();
        break;
    case 3:
    {
        struct
        {
            struct WinRect rect;
            u32 unk10;
        } frame;

        frame.rect.h = 8;
        frame.rect.altFrame = 0;
        Window_DrawFrame(&frame.rect, 2, 0xB, 0x1A, 8);
        WindowMap_QueueUpload(0);
        break;
    }
    case 4:
    {
        u16 i;

        for (i = 0; i <= 3; i++)
        {
            if (gCharTasks[i] != NULL)
            {
                u16 *obj = gCharTasks[i]->data.h;
                struct CharGfxRecord *rec = Char_GetRecord(obj[3]);

                Char_LoadGfxHalf((struct CharObj *)obj, rec->gfx0, 0, 0, 0);
                Char_LoadGfxHalf((struct CharObj *)obj, rec->gfx1, 0, 1, 0);
            }
        }
        break;
    }
    case 5:
        if (!(gUnk_0200AB04 & 0x8000))
        {
            const u16 *src = gUnk_03004630;
            u16 *pal = gPaletteTarget;

            pal[0] = src[0];
            Palette_CopyWithEffect(3, src, &pal[0xE0], 0x40, 0x20);
            Palette_CopyWithEffect(3, gUnk_03004510, &pal[0xD0], 0x20, 0x20);
            VBlankTask_AddCounted(sub_080BE530, 1);
            sub_080AE304();
        }
        else
        {
            BgPicture_LoadAll();
        }
        break;
    case 6:
        gHudState[0x1A] = 0;
        sub_080C1440();
        break;
    case 0x100:
        PalFade_FadeInFromBlack(1);
        SetMainCallback(FieldMain_Loop);
        break;
    }
}
