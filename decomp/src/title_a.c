#include "global.h"
#include "title.h"

// sub_080D6264 @ 0x080D6264
void sub_080D6264(struct Task *task, u16 se)
{
    sub_080C5170(se);
}

/* Title screen scene setup: loads graphics/palettes for gMenuState.mode, then queues the
   VBlank upload (sub_080D5C20). */
// Title_LoadScene @ 0x080D6274
void Title_LoadScene(struct Task *task, u16 mode)
{
    u32 zero;

    TITLE->mode = mode;
    TITLE->blinkTimer = 0x14;
    TITLE->cursor = gUnk_0203BB68;
    switch (TITLE->mode)
    {
    case 100:
        LZ77UnCompWram(gUnknown_084F9CD0, gUnk_0200F874);
        break;
    case 101:
        LZ77UnCompWram(gUnknown_0850485C, (void *)0x02001000);
        RLUnCompWram((void *)0x02001000, gUnk_0200F874);
        break;
    case 103:
        Palette_CopyWithEffect(3, gUnknown_084FA4E0, gPaletteTarget, 0x20, 0x20);
        Palette_CopyWithEffect(3, gUnknown_084FA500, gPaletteTarget + 0x100, 0x120, 0x20);
        PalFade_FadeInFromBlack(1);
        break;
    case 105:
        HuffUnComp(gUnknown_084FD060, (void *)0x02001000);
        RLUnCompWram((void *)0x02001000, gUnk_0200F874);
        break;
    case 107:
        Palette_CopyWithEffect(3, gUnknown_084FA660, gPaletteTarget, 0x200, 0x20);
        Palette_CopyWithEffect(3, gUnknown_084FA500, gPaletteTarget + 0x100, 0x200, 0x20);
        PalFade_FadeInFromBlack(1);
        break;
    case 108:
        HuffUnComp(gUnknown_085029CC, (void *)0x02001000);
        RLUnCompWram((void *)0x02001000, gUnk_0200F874);
        break;
    case 110:
        LZ77UnCompWram(gUnknown_08508AC0, (void *)0x02001000);
        RLUnCompWram((void *)0x02001000, gUnk_0200F874);
        break;
    case 111:
        gUnk_03000030 = 0xF0;
        gUnk_03000031 = 0;
        gUnk_03000034 = 0x96;
        gUnk_03000035 = 0;
        gUnk_03000038 = 0x3F;
        gUnk_0300003A = 0x3F;
        break;
    case 112:
        Palette_CopyWithEffect(3, gUnknown_084FA660, gPaletteTarget, 0x200, 0x20);
        Palette_CopyWithEffect(3, gUnknown_084FA620, gPaletteTarget + 0x100, 0x200, 0x20);
        PalFade_FadeInFromBlack(1);
        break;
    case 114:
        gUnk_03000042 = 0;
        gUnk_03000043 = 0x10;
        break;
    case 120:
        Palette_CopyWithEffect(3, gUnknown_081B6C30, gUnk_03002BB0, 0x40, 0x20);
        PalFade_FadeInFromBlack(1);
        break;
    case 127:
        gUnk_0300003A = 0x3F;
        gUnk_03000030 = 0xF0;
        gUnk_03000031 = 0;
        gUnk_03000035 = 0x78;
        gUnk_03000034 = 0x9F;
        gUnk_03000038 = 0x2F;
        Palette_CopyWithEffect(3, gUnknown_084FA620, gUnk_03002FB0, 0x200, 0x20);
        Palette_MarkDirty();
        gUnk_03000040 = 0x2E50;
        gUnk_03000042 = gUnknown_08509648[0];
        gUnk_03000043 = gUnknown_08509648[1];
        break;
    case 128:
        gUnk_03000040 = 0x3C42;
        break;
    case 129:
        break;
    case 0:
        zero = 0;
        CpuSet(&zero, gUnk_0200F874, 0x05002000);
        break;
    case 1:
        LZ77UnCompWram(gUnknown_081B5DD4, gUnk_0200F874);
        break;
    case 3:
        gUnk_03000040 = 0;
        gUnk_03000004 = 0xFFE8;
        gUnk_03000006 = 0xFFF0;
        if (gUnk_0203BB68 == 0)
        {
            gUnk_03000030 = 0xF0;
            gUnk_03000031 = 0;
            gUnk_03000034 = 0x3C;
            gUnk_03000035 = 0;
            gUnk_03000038 = 0x3D;
        }
        break;
    case 4:
        Palette_CopyWithEffect(3, gUnknown_081B7110, gPaletteTarget, 0x20, 0x20);
        Palette_CopyWithEffect(3, gUnknown_081B7130, gPaletteTarget + 0x100, 0x40, 0x20);
        PalFade_FadeInFromBlack(1);
        break;
    case 5:
        if (PalFade_AllDone() == 1)
            task->result = 1;
        else
            task->result = 0;
        break;
    case 6:
        PalFade_FadeToBlack(1);
        break;
    }
    VBlankTask_AddCounted(sub_080D5C20, 1);
}

// sub_080D6794 @ 0x080D6794
void sub_080D6794(void)
{
    Sprite_Draw(gUnknown_0813EBD4, 0, 0, 0, 0, 0x78, 0x40);
}

/* Three rows (17, 16, 17 glyphs) of the boot-time notice from the glyph list at 0x085096C4. */
// Intro_DrawDisclaimer @ 0x080D67BC
void Intro_DrawDisclaimer(void)
{
    u16 idx = 0;
    u16 x = 0;
    u16 i = 0;

    for (; i < 17; i++)
    {
        FontSprite_DrawGlyph(gUnknown_085096C4[idx++], 0, 0, x, 0x38);
        x += 13;
    }
    for (x = 13, i = 0; i < 16; i++)
    {
        FontSprite_DrawGlyph(gUnknown_085096C4[idx++], 0, 0, x, 0x45);
        x += 13;
    }
    for (x = 8, i = 0; i < 17; i++)
    {
        FontSprite_DrawGlyph(gUnknown_085096C4[idx++], 0, 0, x, 0x52);
        x += 13;
    }
}

// sub_080D686C @ 0x080D686C
void sub_080D686C(void)
{
    Sprite_Draw(gUnknown_0813EE88, 0, 0, 0, 0, 0x78, 0x18);
    Sprite_Draw(gUnknown_0813EE20, 0, 0, 0, 0, 0x42, 0x90);
    Sprite_Draw(gUnknown_0813EE3C, 0, 0, 0, 0, 0x80, 0x90);
}

// sub_080D68C8 @ 0x080D68C8
void sub_080D68C8(struct Task *task)
{
    task->result = 0;
}

// sub_080D68D0 @ 0x080D68D0
void sub_080D68D0(struct Task *task)
{
    struct TitleMenu *menu = TITLE;

    if (--task->data.raw[0x1E] == 0)
        task->result = 1;
    if (menu->unk10 == 1)
    {
        menu->unk10 = 0;
        task->result = 1;
    }
}

// sub_080D6900 @ 0x080D6900
void sub_080D6900(struct Task *task)
{
    struct TitleMenu *menu = TITLE;

    if (--task->data.raw[0x1E] == 0)
        task->result = 1;
    if (menu->unk10 == 1)
        task->unk1E = 1;
}

// sub_080D692C @ 0x080D692C
void sub_080D692C(struct Task *task, u32 n)
{
    gUnk_03000034 -= n;
}

// Title_DrawPressStart @ 0x080D693C
void Title_DrawPressStart(void)
{
    struct TitleMenu *menu = TITLE;

    Sprite_Draw(gUnknown_0813EE88, 0, 0, 0, 0, 0x78, 0x18);
    if (--menu->blinkTimer == 0)
    {
        menu->blinkTimer = 0x14;
        menu->blink = (menu->blink + 1) & 1;
    }
    if (menu->blink == 0)
        Sprite_Draw(gUnknown_080017A4, 0, 0, 0, 0, 0x38, 0x70);
    Sprite_Draw(gUnknown_0813EE20, 0, 0, 0, 0, 0x42, 0x90);
    Sprite_Draw(gUnknown_0813EE3C, 0, 0, 0, 0, 0x80, 0x90);
}

// sub_080D69D8 @ 0x080D69D8
void sub_080D69D8(void)
{
    Sprite_Draw(gUnknown_0813EE88, 0, 0, 0, 0, 0x78, 0x18);
    Sprite_Draw(gUnknown_0813EE20, 0, 0, 0, 0, 0x42, 0x90);
    Sprite_Draw(gUnknown_0813EE3C, 0, 0, 0, 0, 0x80, 0x90);
}

/* TRUE if any of the three save slots is valid or any of the checked flags is set. */
// Title_HasExtraUnlocked @ 0x080D6A34
u32 Title_HasExtraUnlocked(void)
{
    u32 i;

    if (sub_080C2A84(0) == 1 || sub_080C2A84(1) == 1 || sub_080C2A84(2) == 1)
        return 1;
    for (i = 0; i < 0x17C; i++)
    {
        if (sub_080C2644(i) != 0)
            return 1;
    }
    for (i = 0; i < 0x40; i++)
    {
        if (sub_080C2734(i + 300) != 0)
            return 1;
    }
    return 0;
}

/* Title menu: rows greyed when unavailable (unk08/unk0A), cursor sprite at row TITLE->cursor. */
// Title_DrawMenu @ 0x080D6A9C
void Title_DrawMenu(void)
{
    struct TitleMenu *menu = TITLE;

    Sprite_Draw(gUnknown_0813EE88, 0, 0, 0, 0, 0x78, 0x18);
    Sprite_Draw(gUnknown_0813ED6C, 0, 0, 0, 0, 0x58, 0x54);
    if (menu->unk08 == 1)
        Sprite_Draw(gUnknown_0813ED84, 0, 0, 0, 0, 0x54, 0x5F);
    else
        Sprite_Draw(gUnknown_0813EDF0, 0, 0, 0, 0, 0x54, 0x5F);
    if (menu->unk0A == 1)
        Sprite_Draw(gUnknown_0813ED9C, 0, 0, 0, 0, 0x58, 0x6A);
    else
        Sprite_Draw(gUnknown_0813EE08, 0, 0, 0, 0, 0x58, 0x6A);
    if (Title_HasExtraUnlocked() == 1)
    {
        Sprite_Draw(gUnknown_0813EDC0, 0, 0, 0, 0, 0x50, 0x75);
        Sprite_Draw(gUnknown_0813EDD8, 0, 0, 0, 0, 0x60, 0x80);
    }
    else
    {
        Sprite_Draw(gUnknown_0813EDD8, 0, 0, 0, 0, 0x60, 0x75);
    }
    Sprite_Draw(gUnknown_0813EE20, 0, 0, 0, 0, 0x42, 0x90);
    Sprite_Draw(gUnknown_0813EE3C, 0, 0, 0, 0, 0x80, 0x90);
    switch (menu->cursor)
    {
    case 0:
        Sprite_Draw(gUnknown_0813EE58, 1, 0, 0, 0, 0x48, 0x50);
        break;
    case 1:
        Sprite_Draw(gUnknown_0813EE58, 1, 0, 0, 0, 0x48, 0x5B);
        break;
    case 2:
        Sprite_Draw(gUnknown_0813EE58, 1, 0, 0, 0, 0x48, 0x66);
        break;
    case 3:
        Sprite_Draw(gUnknown_0813EE58, 1, 0, 0, 0, 0x48, 0x71);
        break;
    case 4:
        Sprite_Draw(gUnknown_0813EE58, 1, 0, 0, 0, 0x48, 0x7C);
        break;
    }
}

/* "Press start" wait: unk1E = 2 when the idle timer runs out, 1 on any key (cursor preset). */
// Title_WaitPressStart @ 0x080D6C8C
void Title_WaitPressStart(struct Task *task)
{
    struct TitleMenu *menu = TITLE;

    task->unk1E = 0;
    if (--menu->idle == 0)
    {
        task->unk1E = 2;
    }
    else if (gKeysNew & 0x3FF)
    {
        task->unk1E = 1;
        sub_080C51D4(0x65);
        if (menu->unk0A == 1)
            menu->cursor = 2;
        else if (menu->unk08 == 1)
            menu->cursor = 1;
        else
            menu->cursor = 0;
    }
}

/* Title menu input: A picks row cursor+1 (5 for the last row when it is hidden), B = 10,
   up/down wrap over 4 or 5 rows; 0x80 when idle too long. */
// Title_HandleMenuInput @ 0x080D6CEC
void Title_HandleMenuInput(struct Task *task)
{
    struct TitleMenu *menu = TITLE;
    u16 rows = 5;
    u16 keys;

    if (Title_HasExtraUnlocked() == 0)
        rows = 4;
    task->unk1E = 0;
    if (--menu->idle == 0)
    {
        task->unk1E = 0x80;
    }
    else if (gKeysNew & 1)
    {
        if (menu->cursor == 2 && menu->unk0A == 0)
            return;
        if (menu->cursor == 1 && menu->unk08 == 0)
            return;
        task->unk1E = menu->cursor + 1;
        if (Title_HasExtraUnlocked() == 0 && task->unk1E == 4)
            task->unk1E = 5;
        sub_080C51D4(0x65);
    }
    else if (gKeysNew & 2)
    {
        task->unk1E = 10;
        sub_080C51D4(0x66);
    }
    else if ((keys = gKeysNew & 0x40) != 0)
    {
        menu->idle = 900;
        sub_080C51D4(0x64);
        if (menu->cursor != 0)
            menu->cursor--;
        else
            menu->cursor = rows - 1;
    }
    else if (gKeysNew & 0x80)
    {
        menu->idle = 900;
        sub_080C51D4(0x64);
        if (menu->cursor != rows - 1)
            menu->cursor++;
        else
            menu->cursor = keys;
    }
}

// sub_080D6DD0 @ 0x080D6DD0
void sub_080D6DD0(void)
{
    Game_NewGame();
    sub_080B70BC(0, 0, 2, 6, 3, 0);
}

// sub_080D6DF0 @ 0x080D6DF0
void sub_080D6DF0(void)
{
    SaveScreen_Open(0, 0);
}

// sub_080D6E00 @ 0x080D6E00
void sub_080D6E00(void)
{
    SaveScreen_Open(1, 0);
}

// sub_080D6E10 @ 0x080D6E10
void sub_080D6E10(void)
{
    SetMainCallback(sub_080DDEDC);
}

// sub_080D6E20 @ 0x080D6E20
void sub_080D6E20(void)
{
    sub_080CFFE0(0);
}

// sub_080D6E2C @ 0x080D6E2C
void sub_080D6E2C(void)
{
    struct TitleMenu *menu = TITLE;
    u32 *saved = &gUnk_0203BB68;

    *saved = menu->cursor;
}

// sub_080D6E40 @ 0x080D6E40
void sub_080D6E40(void)
{
    sub_080C51BC(8);
}

// sub_080D6E4C @ 0x080D6E4C
void sub_080D6E4C(struct Task *task, u32 which)
{
    switch (which)
    {
    case 0:
        VBlankTask_AddCounted(sub_080C1450, 1);
        break;
    case 1:
        VBlankTask_AddCounted(sub_080C1328, 1);
        break;
    case 2:
        sub_080C1384();
        break;
    }
}

// sub_080D6E7C @ 0x080D6E7C
void sub_080D6E7C(void)
{
    TITLE->idle = 900;
}

// sub_080D6E8C @ 0x080D6E8C
void sub_080D6E8C(void)
{
}

// sub_080D6E90 @ 0x080D6E90
void sub_080D6E90(struct Task *task)
{
    struct TitleMenu *menu = TITLE;

    task->result = 0;
    task->unk1E = 0;
    menu->unk0E = 0;
}
