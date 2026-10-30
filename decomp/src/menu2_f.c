#include "global.h"
#include "menu2.h"

// sub_080D527C @ 0x080D527C
void sub_080D527C(void)
{
    struct SlotMenu *menu = SLOT_MENU;

    TextWindow_Close(menu->window28, 1);
    TextWindow_Close(menu->window2C, 1);
}

/* Door keypad: the entered code is digit0*1000 + ... (weights at 0x084F404C), 0xFFFF when a
   digit is still blank. Casino mode keeps the bet and starts the next task. */
// Keypad_StoreResult @ 0x080D529C
void Keypad_StoreResult(struct Task *task, u32 keepWindow)
{
    struct SlotMenu *menu = SLOT_MENU;
    u16 i;

    if (keepWindow == 0)
        Window_Close(menu->window14, 0);
    if (menu->unk0C == 0)
    {
        gYesNoResult = 0;
        for (i = 0; i < 4; i++)
        {
            if (menu->glyphs[i] == 0xFFFF)
            {
                gYesNoResult = 0xFFFF;
                return;
            }
            gYesNoResult += menu->glyphs[i] * gUnknown_084F404C[i];
        }
    }
    else
    {
        gUnk_030037F0 = Keypad_GetNumber();
        gUnk_03003FF0 = Task_Create(gUnknown_084F4028, 0xFFFF);
    }
}

// Door_KeypadInitInputState @ 0x080D5324
struct Task *Door_KeypadInitInputState(struct Task *parent)
{
    struct Task *task = Task_Create(gUnknown_084F4054, parent->id);
    struct SlotMenu *menu = SLOT_MENU;
    u32 zero = 0;

    CpuSet(&zero, menu, 0x05000200);
    menu->unk0C = 0;
    menu->glyphs[0] = 0xFFFF;
    menu->glyphs[1] = -1;
    menu->glyphs[2] = -1;
    menu->glyphs[3] = -1;
    menu->row = 1;
    menu->col = 1;
    return task;
}

/* Casino bet entry: like the keypad, in digit mode with the given bet unit. */
// Keypad_OpenNumberEntry @ 0x080D5374
void Keypad_OpenNumberEntry(u32 bet)
{
    struct Task *task = Task_Create(gUnknown_084F40D8, 0xFFFF);
    struct SlotMenu *menu = SLOT_MENU;
    u32 zero = 0;
    u32 i;

    CpuSet(&zero, menu, 0x05000200);
    menu->unk0C = 1;
    menu->bet = bet;
    for (i = 0; i < 8; i++)
        menu->digits[i] |= 0xFF;
    menu->row = 1;
    menu->col = 1;
    gUnk_030037F0 = 0;
    gUnk_03003FEC = task;
}

// sub_080D53E0 @ 0x080D53E0
u32 sub_080D53E0(void)
{
    u32 done = 0;

    if (gUnk_03003FEC->state == 0)
        done = 1;
    return done;
}

// sub_080D53FC @ 0x080D53FC
void sub_080D53FC(void)
{
    gUnk_03003FF0->wait = 1;
}

// sub_080D540C @ 0x080D540C
void sub_080D540C(void)
{
    sub_080C1450();
    gUnk_03000040 = 0;
    REG_DISPCNT &= 0xFEFF;
    REG_DISPCNT &= 0xFBFF;
    REG_DISPCNT &= 0xF7FF;
    REG_BG1CNT &= 0xFFBF;
    gUnk_0300003C = 0;
    DmaSet3(gUnk_02000000, (void *)0x06000000, 0x84001000);
    REG_IE = 0x2003;
    REG_DISPSTAT = 0x18;
    REG_IME = 1;
    Font_ResetGlyphSpriteCache(0x180);
    Task_ClearAll();
    VBlankTasks_Init();
    Task_Create(gUnknown_084F9A28, 0xFFFF);
    Music_Play(0x1C);
    gUnk_0203DB6A = 0;
    SetMainCallback(sub_080D54F0);
}

// sub_080D54E0 @ 0x080D54E0
void sub_080D54E0(void)
{
    SetMainCallback(sub_080D540C);
}

// sub_080D54F0 @ 0x080D54F0
void sub_080D54F0(void)
{
    Task_RunAll();
}

// sub_080D54FC @ 0x080D54FC
void sub_080D54FC(void)
{
    DmaSet3(gUnk_0200F874, (void *)0x06008000, 0x840012C0);
    DmaSet3(gUnk_0200F874 + 0x5000, (void *)0x06010000, 0x84000800);
    DmaSet3(gUnk_02000000, (void *)0x06001000, 0x84000140);
}

/* Loads the screen in steps (one per call): five LZ77 tile sheets, the sprites, then the
   tilemap with per-tile palettes from 0x084F8760, then fades in (7) or out (8). */
// sub_080D5554 @ 0x080D5554
void sub_080D5554(struct Task *task, u32 step)
{
    switch (step)
    {
    case 0:
        LZ77UnCompWram(gUnknown_084F4140, gUnk_0200F874);
        break;
    case 1:
        LZ77UnCompWram(gUnknown_084F5214, gUnk_0200F874 + 0x1000);
        break;
    case 2:
        LZ77UnCompWram(gUnknown_084F6108, gUnk_0200F874 + 0x2000);
        break;
    case 3:
        LZ77UnCompWram(gUnknown_084F6F7C, gUnk_0200F874 + 0x3000);
        break;
    case 4:
        LZ77UnCompWram(gUnknown_084F7C5C, gUnk_0200F874 + 0x4000);
        break;
    case 5:
        LZ77UnCompWram(gUnknown_084F89E0, gUnk_0200F874 + 0x5000);
        LZ77UnCompWram(gUnknown_084F8FF0, gUnk_0200F874 + 0x6000);
        break;
    case 6:
    {
        const u8 *pal = gUnknown_084F8760;
        u16 *map = (u16 *)gUnk_02000000;
        u16 x, y;

        Tilemap_CopyRectSkipZero(gUnknown_084F9528, gUnk_02000000, 0, 0, 0, 0, 0x1E, 0x14);
        for (y = 0; y < 0x14; y++)
        {
            for (x = 0; x < 0x1E; x++)
            {
                u16 *cell = &map[y * 32 + x];
                u16 c = *pal++;

                c &= 0xF;
                *cell = (*cell & 0xFFF) | (c << 12);
            }
        }
        Palette_CopyWithEffect(3, gUnknown_084F93E8, gPaletteTarget, 0x100, 0x20);
        VBlankTask_AddCounted(sub_080D54FC, 1);
        break;
    }
    case 7:
        PalFade_FadeInFromBlack(4);
        break;
    case 8:
        PalFade_FadeToBlack(4);
        break;
    }
}
