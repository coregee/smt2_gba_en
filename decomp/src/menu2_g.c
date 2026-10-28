#include "global.h"
#include "menu2.h"

// sub_080D56DC @ 0x080D56DC
void sub_080D56DC(struct Task *task)
{
    u16 *data = task->data.h;

    if (task->data.h[0] == 1)
        Sprite_Draw(gUnknown_08002AB0, 0, 0, 0, 0, 0x68, 0x10);
    if (data[1] == 1)
        Sprite_Draw(gUnknown_08002AF8, 0, 0, 0, 0, 0x78, 0x64);
}

// sub_080D5730 @ 0x080D5730
void sub_080D5730(void)
{
    sub_080D5B8C(0);
}

/* Flash steps: whiten an OBJ palette, then fade it back to the target colours. */
// sub_080D573C @ 0x080D573C
void sub_080D573C(struct Task *task, u32 step)
{
    u16 *data = task->data.h;

    switch (step)
    {
    case 0:
        Palette_FillWithEffect(3, 0x7FFF, gUnk_03002FB0, 0x20, 0x10);
        Palette_MarkDirty();
        data[0] = 1;
        break;
    case 1:
        Palette_CopyWithEffect(3, gUnknown_084F94E8, gUnk_03002BB0, 0x20, 0x20);
        PalFade_FadeRangeWithDuration(0x100, 0x10, 6, 0x20);
        break;
    case 2:
        Palette_FillWithEffect(3, 0x7FFF, gUnk_03002FD0, 0x20, 0x10);
        Palette_MarkDirty();
        data[1] = 1;
        break;
    case 3:
        Palette_CopyWithEffect(3, gUnknown_084F9508, gUnk_03002BD0, 0x20, 0x20);
        PalFade_FadeRangeWithDuration(0x110, 0x10, 6, 0x20);
        break;
    case 4:
        Palette_FillWithEffect(3, 0x7FFF, gUnk_03002BD0, 0x20, 0x10);
        PalFade_FadeRangeWithDuration(0x110, 0x10, 6, 0x20);
        break;
    case 5:
        data[1] = 0;
        break;
    case 6:
        Palette_FillWithEffect(3, 0x7FFF, gUnk_03002BB0, 0x20, 0x10);
        PalFade_FadeRangeWithDuration(0x100, 0x10, 6, 0x20);
        break;
    case 7:
        data[0] = 0;
        break;
    }
}

// sub_080D5854 @ 0x080D5854
void sub_080D5854(struct Task *task, u32 white)
{
    if (white == 0)
    {
        REG_BG1CNT |= 0x40;
        gUnk_0300003C = 0;
    }
    else
    {
        Palette_FillWithEffect(3, 0x7FFF, gPaletteTarget, 0x100, 0x10);
        PalFade_FadeRangeWithDuration(0, 0x80, 0x10, 0x20);
    }
}

// sub_080D58A4 @ 0x080D58A4
void sub_080D58A4(void)
{
    if ((gFrameCounter & 0x1F) == 0 && (gUnk_0300003C & 0xF) != 0xF)
        gUnk_0300003C += 0x11;
}

// sub_080D58D0 @ 0x080D58D0
void sub_080D58D0(void)
{
    PalFade_FadeToBlack(4);
    gUnk_0200E7D4[0x1A] = 1;
}

// sub_080D58E8 @ 0x080D58E8
void sub_080D58E8(void)
{
    u32 zero = 0;

    CpuSet(&zero, &gMenuState, 0x05000200);
    Task_Create(gUnknown_084F9C94, 0xFFFF);
}

/* Debug/test start: sets up the first party member, fills the inventory, adds twelve
   demons and gives 10000 of three currencies. */
// Debug_SetupTestGame @ 0x080D5918
void Debug_SetupTestGame(void)
{
    u32 i, j;

    gGameState.unkAC3 = 0xC;
    for (i = 0; i < 7; i++)
    {
        Combatant_SetEquip(0, i, gUnknown_08509640[i]);
        Combatant_RecalcStats(0);
    }
    gGameState.unk00D = 50;
    gGameState.unk008 = 208250;
    for (i = 0; i < 0xFF; i++)
    {
        for (j = 0; j < 50; j++)
            sub_080C3328(i);
    }
    Stock_AddDemon(0x6E);
    Stock_AddDemon(0x71);
    Stock_AddDemon(0x40);
    Stock_AddDemon(0x64);
    Stock_AddDemon(0xAE);
    Stock_AddDemon(0x7D);
    Stock_AddDemon(0x59);
    Stock_AddDemon(0xB);
    Stock_AddDemon(0x4D);
    Stock_AddDemon(0x9C);
    Stock_AddDemon(0x6B);
    Stock_AddDemon(0x76);
    gGameState.unkADC = 10000;
    gGameState.unkAD8 = 10000;
    gGameState.unkAE0 = 10000;
}

// sub_080D59E8 @ 0x080D59E8
void sub_080D59E8(void)
{
    gDispRegs = 0;
    gUnk_03000002 = 0xFFFF;
    gUnk_03000004 = 0xFFE0;
    gUnk_03000006 = 0xFFE8;
    gUnk_03000008 = 0xFFE0;
    gUnk_0300000A = 0xFFE8;
    gUnk_0300000C = 0;
    gUnk_0300000E = 0;
}

// sub_080D5A48 @ 0x080D5A48
void sub_080D5A48(void)
{
    u32 zero;
    u32 zero2;
    u32 zero3;

    REG_DISPCNT = 0x7F00;
    REG_BG0CNT = 0x8004;
    REG_BG1CNT = 0x820D;
    REG_BG2CNT = 0x840E;
    REG_BG3CNT = 0x4607;
    gUnk_03000038 = 0x3F;
    gUnk_03000039 = 0x3F;
    gUnk_0300003A = 0x3F;
    sub_080D59E8();
    sub_080C1440();
    PalFade_Init(0);
    zero = 0;
    CpuSet(&zero, gWindowMap, 0x05000400);
    zero2 = 0;
    CpuSet(&zero2, gWindowTilemapBuffer, 0x05000200);
    REG_IE = 0x2003;
    REG_DISPSTAT = 0x18;
    REG_IME = 1;
    sub_080C5170(0);
    gUnk_0203DB6A = 0;
    Font_ResetGlyphSpriteCache(0x180);
    Task_ClearAll();
    zero3 = 0;
    CpuSet(&zero3, &gMenuState, 0x05000200);
    Task_Create(gUnknown_08509CF8, 0xFFFF);
    gUnk_030069E4 = Task_Create(gUnknown_08509CD0, 0xFFFF);
    SetMainCallback(sub_080D5BE4);
}

// sub_080D5B64 @ 0x080D5B64
void sub_080D5B64(void)
{
    vu16 zero = 0;

    DmaSet3(&zero, (void *)0x06000000, 0x81002000);
}

// sub_080D5B8C @ 0x080D5B8C
void sub_080D5B8C(u16 mode)
{
    u32 zero;

    gUnk_0203BB68 = mode;
    if (Title_HasExtraUnlocked() == 0 && mode == 4)
        gUnk_0203BB68 = 3;
    SetMainCallback(sub_080D5A48);
    zero = 0;
    CpuSet(&zero, gPaletteBuffer, 0x05000100);
    Palette_MarkDirty();
    VBlankTask_AddCounted(sub_080D5B64, 1);
}

// sub_080D5BE4 @ 0x080D5BE4
void sub_080D5BE4(void)
{
    Task_RunAll();
}

// sub_080D5BF0 @ 0x080D5BF0
void sub_080D5BF0(struct Task *task)
{
    task->unk1E = gUnk_0203BB68;
}

// sub_080D5BFC @ 0x080D5BFC
void sub_080D5BFC(void)
{
    u16 *menu = (u16 *)&gMenuState;
    u32 r;

    if ((r = SaveSlot_AnyValid()) == 1)
        menu[4] = r;
    if ((r = SaveSlot_IsValid(3)) == 1)
        menu[5] = r;
}
