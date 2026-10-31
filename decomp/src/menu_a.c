#include "global.h"
#include "menu.h"

// Menu_DrawCombatantName8px @ 0x080D0288
void Menu_DrawCombatantName8px(u8 *name, u16 x, u16 y)
{
    u32 i = 0;

    while (name[i] != 0xFF)
    {
        Canvas_BlitOr(gUnknown_081AF7B8 + name[i] * 32, gUnk_0200F874, 0, 0, x + i * 8, y, 8, 8);
        i++;
        if (i > 7)
            break;
    }
    SmallFont_DrawAscii(gUnknown_084F20A4, x + 0x48, y + 1, 0);
    if (name[13] < 10)
        SmallFont_DrawNumber(name[13], x + 0x58, y + 1, 0);
    else
        SmallFont_DrawNumber(name[13], x + 0x60, y + 1, 0);
}

// GameState_TestFlag @ 0x080D0340
u32 GameState_TestFlag(struct GameState *save, u32 bit)
{
    return (save->flags[bit >> 3] >> (bit & 7)) & 1;
}

// SaveScreen_DrawLocationName @ 0x080D035C
void SaveScreen_DrawLocationName(struct GameState *state, u16 mode, u16 x, u16 y)
{
    u16 *str;
    u16 i;
    u16 cx;
    u16 ty;

    cx = x;
    /* Two statements: the extra RTL insn lengthens cx's live range so i outranks it for r5. */
    ty = y;
    ty += -4;

    if (mode != 3 && !GameState_TestFlag(state, 0x163) && GameState_TestFlag(state, 0xEE))
        str = gUnknown_084F20A8;
    else
        str = Location_GetNameCellFromCoords(state->unkA32, state->unkA34, state->unkA2E, state->unkA30);

    i = 0;
    while (*str != 0 && *str != 0x301 && *str != 0x57)
    {
        Font_DrawGlyphTinted(*str, gUnk_0200F874, cx, ty, 8);
        str++;
        cx += 12;
        i++;
        if (i > 15)
            break;
    }
}

// SaveScreen_DrawTokenString @ 0x080D042C
void SaveScreen_DrawTokenString(u16 *str, u16 y)
{
    u16 x = 0x39;
    u16 ty = y - 4;
    u16 i = 0;

    while (*str != 0 && *str != 0x301)
    {
        Font_DrawGlyphTinted(*str, gUnk_0200F874, x, ty, 8);
        str++;
        x += 12;
        i++;
        if (i > 7)
            break;
    }
}

/* NONMATCHING: the only difference is that state and ty swap registers (sb/r8). */
// SaveScreen_DrawSlot @ 0x080D0498
void SaveScreen_DrawSlot(u32 unused, u32 slot)
{
    u16 ty;
    u16 x;
    u16 i;
    struct GameState *state;
    struct PartyMember *member;
    u16 y = slot * 40 + 30;
    u16 *str;
    u16 *tok;
    u32 n, k;

    if (slot == 3)
        y = 0x46;
    else
    {
        SmallFont_DrawAscii(gUnknown_084F20EC, 13, y, 4);
        SmallFont_DrawNumber(slot + 1, 0x2D, y, 4);
    }

    if (SaveSlot_IsValid(slot) == 1 && SaveSlot_Read(slot, &gSaveSlotPreview, 1) == 1)
    {
        state = &gSaveSlotPreview;
        if (!GameState_TestFlag(state, 0xEE))
            PlayTime_Draw(state->unkAE4, 0xB4, y + 22, 0);
        else
            PlayTime_Draw(state->unkAE4, 0xB4, y + 22, 10);

        if (state->unkAC0 == 0)
        {
            if (slot == 3)
                SaveScreen_DrawLocationName(state, 3, 0x2D, y);
            else
            {
                tok = sub_080C8B54(state->unkA32);
                if (tok == NULL)
                {
                    DungeonMap_GetFloor(state->unkA32, state->unkA34);
                    SaveScreen_DrawLocationName(state, slot, 0x39, y);
                }
                else
                    SaveScreen_DrawTokenString(tok, y);
            }
        }
        else
        {
            u16 *a40 = (u16 *)state->unkA40;

            str = gUnknown_080A94AC[a40[0x13]];
            x = 0x39;
            ty = y - 4;
            for (i = 0; i < 9 && *str != 0x57; i++)
            {
                Font_DrawGlyphTinted(*str, gUnk_0200F874, x, ty, 8);
                str++;
                x += 12;
            }
        }

        n = 0;
        for (k = 0; k < 4; k++)
        {
            member = &state->party[k];
            if (member->unk0E != 0)
            {
                switch (n)
                {
                case 0:
                    Menu_DrawCombatantName8px(member->name, 13, y + 11);
                    break;
                case 1:
                    Menu_DrawCombatantName8px(member->name, 13, y + 22);
                    break;
                case 2:
                    Menu_DrawCombatantName8px(member->name, 0x7C, y + 11);
                    break;
                }
                n++;
            }
        }
    }
    else
    {
        SmallFont_DrawAscii(gUnknown_084F20F4, 13, y + 11, 2);
        SmallFont_DrawAscii(gUnknown_084F20F8, 0x25, y + 11, 2);
    }
}
