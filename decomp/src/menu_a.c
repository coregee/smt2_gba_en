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

/* NONMATCHING: only the order of the x/y zero-extensions in the prologue differs. */
// SaveScreen_DrawLocationName @ 0x080D035C
#ifdef NONMATCHING
void SaveScreen_DrawLocationName(struct GameState *state, u16 mode, u16 x, u16 y)
{
    u16 *str;
    u16 i = 0;
    u16 ty = y - 4;

    if (mode != 3 && !GameState_TestFlag(state, 0x163) && GameState_TestFlag(state, 0xEE))
        str = gUnknown_084F20A8;
    else
        str = Location_GetNameCellFromCoords(state->unkA32, state->unkA34, state->unkA2E, state->unkA30);

    while (*str != 0 && *str != 0x301 && *str != 0x57)
    {
        Font_DrawGlyphTinted(*str, gUnk_0200F874, x, ty, 8);
        str++;
        x += 12;
        i++;
        if (i > 15)
            break;
    }
}
#else
NAKED
void SaveScreen_DrawLocationName(struct GameState *state, u16 mode, u16 x, u16 y)
{
    asm_unified(
        ".L080D035C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    sub sp, #4\n"
        "    adds r4, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    lsls r2, r2, #0x10\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r6, r2, #0x10\n"
        "    ldr r0, .L080D0398\n"
        "    adds r3, r3, r0\n"
        "    lsrs r3, r3, #0x10\n"
        "    mov r8, r3\n"
        "    cmp r1, #3\n"
        "    beq .L080D03A4\n"
        "    ldr r1, .L080D039C\n"
        "    adds r0, r4, #0\n"
        "    bl GameState_TestFlag\n"
        "    cmp r0, #0\n"
        "    bne .L080D03A4\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0xee\n"
        "    bl GameState_TestFlag\n"
        "    cmp r0, #0\n"
        "    beq .L080D03A4\n"
        "    ldr r4, .L080D03A0\n"
        "    b .L080D03C4\n"
        ".L080D0398: .4byte 0xFFFC0000\n"
        ".L080D039C: .4byte 0x00000163\n"
        ".L080D03A0: .4byte gUnknown_084F20A8\n"
        ".L080D03A4:\n"
        "    ldr r1, .L080D0418\n"
        "    adds r0, r4, r1\n"
        "    ldrh r0, [r0]\n"
        "    ldr r2, .L080D041C\n"
        "    adds r1, r4, r2\n"
        "    ldrh r1, [r1]\n"
        "    ldr r3, .L080D0420\n"
        "    adds r2, r4, r3\n"
        "    ldrh r2, [r2]\n"
        "    movs r5, #0xa3\n"
        "    lsls r5, r5, #4\n"
        "    adds r3, r4, r5\n"
        "    ldrh r3, [r3]\n"
        "    bl Location_GetNameCellFromCoords\n"
        "    adds r4, r0, #0\n"
        ".L080D03C4:\n"
        "    movs r5, #0\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #0\n"
        "    beq .L080D040A\n"
        "    ldr r1, .L080D0424\n"
        "    cmp r0, r1\n"
        "    beq .L080D040A\n"
        "    cmp r0, #0x57\n"
        "    beq .L080D040A\n"
        "    adds r7, r1, #0\n"
        ".L080D03D8:\n"
        "    ldrh r0, [r4]\n"
        "    movs r1, #8\n"
        "    str r1, [sp]\n"
        "    ldr r1, .L080D0428\n"
        "    adds r2, r6, #0\n"
        "    mov r3, r8\n"
        "    bl Font_DrawGlyphTinted\n"
        "    adds r4, #2\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0xc\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #0xf\n"
        "    bhi .L080D040A\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #0\n"
        "    beq .L080D040A\n"
        "    cmp r0, r7\n"
        "    beq .L080D040A\n"
        "    cmp r0, #0x57\n"
        "    bne .L080D03D8\n"
        ".L080D040A:\n"
        "    add sp, #4\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080D0418: .4byte 0x00000A32\n"
        ".L080D041C: .4byte 0x00000A34\n"
        ".L080D0420: .4byte 0x00000A2E\n"
        ".L080D0424: .4byte 0x00000301\n"
        ".L080D0428: .4byte 0x0200F874 @ EWRAM+0xF874\n"
    );
}
#endif

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
