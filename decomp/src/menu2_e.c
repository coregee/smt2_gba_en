#include "global.h"
#include "menu2.h"

/* Masks the 0xF00-word sprite buffer at 0x02001000 with one of four patterns per call
   (a four-step wipe); result 1 once all four steps are done. */
// sub_080D49EC @ 0x080D49EC
void sub_080D49EC(struct Task *task)
{
    struct WipeData *data = (struct WipeData *)task->data.w;

    if (data->step < 4)
    {
        u32 *dst = (u32 *)gUnk_02001000;
        u16 i;

        for (i = 0; i < 0x78; i++)
        {
            const u32 *mask = gUnknown_087F02B8[data->step];
            *dst++ &= *mask++;
            *dst++ &= *mask++;
            *dst++ &= *mask++;
            *dst++ &= *mask++;
            *dst++ &= *mask++;
            *dst++ &= *mask++;
            *dst++ &= *mask++;
            *dst++ &= *mask;
        }
        VBlankTask_AddCounted(sub_080D49C8, 1);
        data->step++;
        task->result = 0;
    }
    else
        task->result = 1;
}

// sub_080D4A84 @ 0x080D4A84
void sub_080D4A84(void)
{
    DmaSet3(gBgPictureBuffer, (void *)0x06015000, 0x84000400);
}

// sub_080D4AA8 @ 0x080D4AA8
void sub_080D4AA8(void)
{
    struct SlotMenu *menu = SLOT_MENU;

    LZ77UnCompWram(gUnknown_084F3AF0, gBgPictureBuffer);
    DmaSet3(gUnknown_081B5710, gBgPictureBuffer + 0xF00, 0x84000040);
    Palette_CopyWithEffect(3, gUnknown_084F3F30, gUnk_03003110, 0x60, 0x10);
    Palette_CopyWithEffect(3, gUnknown_084F3F30 + 0x30, gUnk_03003110 + 0x40, 0x20, 0x10);
    Palette_MarkDirty();
    VBlankTask_AddCounted(sub_080D4A84, 1);
    menu->window14 = Window_Create(2, 0xB, 0x1A, 2, 0);
}

// sub_080D4B48 @ 0x080D4B48
void sub_080D4B48(void)
{
    struct SlotMenu *menu = SLOT_MENU;
    u16 mode = menu->unk0C;

    if (mode == 1)
    {
        menu->window28 = TextWindow_CreateOpen(0x17, 0, 6, 3, mode);
        menu->window2C = TextWindow_CreateOpen(0x17, 6, 6, 5, mode);
    }
}

/* Palette for slot-machine line `pos`: lit when it matches the current (row, col) selection. */
// Keypad_GetKeyPalette @ 0x080D4B80
u16 Keypad_GetKeyPalette(u16 pos)
{
    struct SlotMenu *menu = SLOT_MENU;
    u16 pal = 0xC;

    if (menu->flash != 0)
        pal = 0xD;
    switch (pos)
    {
    case 0:
        if (menu->row == 0 && menu->col == 3)
            return pal;
        break;
    case 1:
        if (menu->row == 0 && menu->col == 2)
            return pal;
        break;
    case 2:
        if (menu->row == 1 && menu->col == 2)
            return pal;
        break;
    case 3:
        if (menu->row == 2 && menu->col == 2)
            return pal;
        break;
    case 4:
        if (menu->row == 0 && menu->col == 1)
            return pal;
        break;
    case 5:
        if (menu->row == 1 && menu->col == 1)
            return pal;
        break;
    case 6:
        if (menu->row == 2 && menu->col == 1)
            return pal;
        break;
    case 7:
        if (menu->row == 0 && menu->col == 0)
            return pal;
        break;
    case 8:
        if (menu->row == 1 && menu->col == 0)
            return pal;
        break;
    case 9:
        if (menu->row == 2 && menu->col == 0)
            return pal;
        break;
    case 10:
        if (menu->row == 1 && menu->col == 3)
            return pal;
        if (menu->row == 2 && menu->col == 3)
            return pal;
        break;
    }
    return 0xB;
}

// sub_080D4C58 @ 0x080D4C58
void sub_080D4C58(struct Task *task)
{
    struct SlotMenu *menu = SLOT_MENU;

    Sprite_Draw(gUnknown_08002A4C, 0, 0, 0, 0x2F8, 0xBA, 3);
    sub_080C8048(sub_080C31F0(), 0xB8, 0xB, 0);
    Sprite_Draw(gUnknown_08002A64, 0, 0, 0, 0x2F8, 0xBA, 0x33);
    Sprite_Draw(gUnknown_0800080C, 0, 0, 0, 1, 0xB8, 0x3B);
    sub_080C8048(gGameState.unkAD8, 0xB8, 0x3B, 0);
    Sprite_Draw(gUnknown_08002A7C, 0, 0, 0, 0x2F8, 0xBA, 0x43);
    sub_080C8048(gUnk_030037F0 * menu->bet, 0xB8, 0x4B, 0);
}

// Keypad_DrawKeys @ 0x080D4D14
void Keypad_DrawKeys(struct Task *task)
{
    u32 row, col;

    for (row = 0; row < 3; row++)
    {
        for (col = 0; col < 3; col++)
        {
            u32 pos = row * 3 + col + 1;
            Sprite_Draw(gUnknown_084F3FB0[pos], 0, Keypad_GetKeyPalette(pos), 0, 0x280, 0x64 + col * 12, 0x82 - row * 12);
        }
    }
    Sprite_Draw(gUnknown_084F3FB0[0], 0, Keypad_GetKeyPalette(0), 0, 0x280, 0x64, 0x8E);
    Sprite_Draw(gUnknown_084F3FB0[10], 0, Keypad_GetKeyPalette(10), 0, 0x280, 0x6E, 0x8E);
    Sprite_Draw(gUnknown_08002A3C, 1, 0xC, 0, 0x280, 0x60, 0x68);
}

// Keypad_Draw @ 0x080D4DF4
void Keypad_Draw(struct Task *task)
{
    struct SlotMenu *menu = SLOT_MENU;
    u32 i;

    Font_ResetGlyphSpriteCache(0x180);
    if (menu->unk0C == 0)
    {
        if (task->wait != -1)
            Keypad_DrawKeys(task);
        Text_DrawSpriteString(gUnknown_084F3FDC, 0, 0, 0x10, 0x59, 0xC);
        for (i = 0; i < 4; i++)
        {
            if (menu->glyphs[i] != 0xFFFF)
                FontSprite_DrawGlyph(gUnknown_084F4014[menu->glyphs[i]], 0, 0, 0x7C + i * 12, 0x59);
        }
    }
    else
    {
        Keypad_DrawKeys(task);
        if (menu->unk1C != 0)
        {
            Text_DrawSpriteString(gUnknown_084F3FFC, 0, 0, 0x10, 0x59, 0xC);
            if (!((gFrameCounter >> 4) & 1))
                sub_080C4AB0(0, 0, 0xD6, 0x61);
        }
        else
        {
            Text_DrawSpriteString(gUnknown_084F3FF0, 0, 0, 0x10, 0x59, 0xC);
            for (i = 0; i < 8; i++)
            {
                if (menu->digits[i] != 0xFF)
                    FontSprite_DrawGlyph(gUnknown_084F4014[menu->digits[i]], 0, 0, 0x4C + i * 12, 0x59);
            }
        }
        sub_080D4C58(task);
    }
}

/* Number of digits entered so far. */
// Keypad_CountDigits @ 0x080D4F20
u16 Keypad_CountDigits(void)
{
    struct SlotMenu *menu = SLOT_MENU;
    u32 i;

    for (i = 0; i < 8; i++)
    {
        if (menu->digits[i] == 0xFF)
            return i;
    }
    return 0;
}

/* Value of the entered digits (right-aligned, 0xFF slots skipped). */
// Keypad_GetNumber @ 0x080D4F48
u32 Keypad_GetNumber(void)
{
    struct SlotMenu *menu = SLOT_MENU;
    u32 mult = 1;
    u32 sum = 0;
    u32 i;

    for (i = 0; i < 8; i++)
    {
        if (menu->digits[7 - i] != 0xFF)
        {
            sum += menu->digits[7 - i] * mult;
            mult *= 10;
        }
    }
    return sum;
}

/* TRUE when the player's money covers `n` times the bet. */
// Keypad_CanAfford @ 0x080D4F7C
u32 Keypad_CanAfford(u32 n)
{
    struct SlotMenu *menu = SLOT_MENU;
    u32 ok = 0;

    if (gGameState.unkAD8 >= menu->bet * n)
        ok = 1;
    return ok;
}

/* First lit slot-machine line (0..10), or 10. */
// Keypad_GetSelectedKey @ 0x080D4FA8
u16 Keypad_GetSelectedKey(void)
{
    u32 i;

    for (i = 0; i <= 10; i++)
    {
        if (Keypad_GetKeyPalette(i) != 0xB)
            return i;
    }
    return 10;
}

/* Slot machine input. Mode 0 (unk0C == 0): pick four symbols; otherwise enter the bet digits.
   The d-pad moves the (row, col) cursor over the 3x4 symbol grid. */
// Keypad_HandleInput @ 0x080D4FD0
void Keypad_HandleInput(struct Task *task)
{
    struct SlotMenu *menu = SLOT_MENU;
    u16 n, d;
    u32 i;

    task->result = 0;
    if (menu->unk0C == 0)
    {
        if (menu->flash != 0)
        {
            if (--menu->flash != 0)
                return;
            if (menu->slot != 3)
            {
                menu->slot++;
                return;
            }
            task->result = 1;
            Task_GetParent(task)->wait = 1;
            return;
        }
        if (gKeysNew & 1)
        {
            if (Keypad_GetSelectedKey() == 10)
            {
                task->result = 1;
                Task_GetParent(task)->wait = 1;
            }
            else
            {
                menu->glyphs[menu->slot] = Keypad_GetSelectedKey();
                menu->flash = 10;
            }
            sub_080C51D4(0x65);
            return;
        }
        if (gKeysNew & 2)
        {
            if (menu->slot != 0)
                menu->slot--;
            menu->glyphs[menu->slot] = 0xFFFF;
            sub_080C51D4(0x66);
            return;
        }
    }
    else
    {
        if (menu->unk1C != 0)
        {
            if (!(gKeysNew & 1))
                return;
            sub_080C30AC(Keypad_GetNumber() * menu->bet);
            for (i = 0; i < 8; i++)
                menu->digits[i] |= 0xFF;
            gUnk_030037F0 = 0;
            menu->unk1C = 0;
            sub_080C51D4(0x65);
            return;
        }
        if (menu->flash != 0 && --menu->flash != 0)
            return;
        if (gKeysNew & 1)
        {
            if (Keypad_GetSelectedKey() == 10)
                task->result = 1;
            else
            {
                n = Keypad_CountDigits();
                d = Keypad_GetSelectedKey();
                if (n != 0 || d != 0)
                {
                    u8 *p;
                    sub_080C30AC(Keypad_GetNumber() * menu->bet);
                    p = &SLOT_MENU->digits[n];
                    *p = d;
                    if (!Keypad_CanAfford(Keypad_GetNumber()))
                    {
                        *p = 0xFF;
                        menu->unk1C = 1;
                    }
                    else
                    {
                        menu->flash = 10;
                        gUnk_030037F0 = Keypad_GetNumber();
                        if (gUnk_030037F0 > 49999)
                            task->result = 1;
                    }
                    sub_080C30AC(-(Keypad_GetNumber() * menu->bet));
                }
            }
            sub_080C51D4(0x65);
            return;
        }
        if (gKeysNew & 2)
        {
            n = Keypad_CountDigits();
            if (n != 0)
                n--;
            sub_080C30AC(Keypad_GetNumber() * menu->bet);
            menu->digits[n] = 0xFF;
            sub_080C30AC(-(Keypad_GetNumber() * menu->bet));
            gUnk_030037F0 = Keypad_GetNumber();
            sub_080C51D4(0x66);
            return;
        }
    }

    if (gRepeatedKeys & 0x40)
    {
        if (menu->col != 0)
            menu->col--;
        else
            menu->col = 3;
        sub_080C51D4(100);
    }
    else if (gRepeatedKeys & 0x80)
    {
        if (menu->col != 3)
            menu->col++;
        else
            menu->col = 0;
        sub_080C51D4(100);
    }
    if (gRepeatedKeys & 0x20)
    {
        if (menu->row != 0)
        {
            menu->row--;
            if (menu->col == 3 && menu->row == 1)
                menu->row = 0;
        }
        else
            menu->row = 2;
        sub_080C51D4(100);
    }
    else if (gRepeatedKeys & 0x10)
    {
        if (menu->row != 2)
        {
            menu->row++;
            if (menu->col == 3 && menu->row == 2)
                menu->row = 0;
        }
        else
            menu->row = 0;
        sub_080C51D4(100);
    }
}
