#include "global.h"
#include "menu.h"

// sub_080D0674 @ 0x080D0674
void sub_080D0674(void)
{
    REG_BG1CNT = 0x8205;
    REG_BG2CNT = 0x8406;
    gUnk_03000040 = 0;
    DmaSet3(gUnknown_081B93B0, 0x06001000, 0x84000200);
}

// SaveScreen_DrawPage @ 0x080D06BC
void SaveScreen_DrawPage(u32 arg0, u32 page)
{
    struct SaveMenu *menu = &gMenuState;

    switch (page)
    {
    case 0:
    {
        vu32 zero = 0;
        DmaSet3(&zero, gUnk_0200F874, 0x85002000);
        if (menu->u.save.window[0] == 0)
            menu->u.save.window[0] = TextWindow_CreateOpenWithFrame(1, 0, 0x1C, 2, 2, gUnknown_084F20FE);
        switch (menu->mode)
        {
        case 0:
        case 4:
            sub_080CCEC8(gUnknown_084F2110, 0x68, 12, 4);
            break;
        case 1:
            sub_080CCEC8(gUnknown_084F2118, 0x58, 12, 4);
            break;
        case 2:
            sub_080CCEC8(gUnknown_084F2124, 0x68, 12, 4);
            break;
        case 3:
            sub_080CCEC8(gUnknown_084F212C, 0x68, 12, 4);
            break;
        }
        VBlankTask_AddCounted(sub_080D0674, 1);
        sub_080D0264();
        break;
    }
    case 1:
        if (menu->u.save.window[1] == 0)
            menu->u.save.window[1] = TextWindow_CreateOpenWithFrame(1, 2, 0x1C, 5, 2, gUnknown_084F20FE);
        SaveScreen_DrawSlot(arg0, 0);
        sub_080D0264();
        break;
    case 2:
        if (menu->u.save.window[2] == 0)
            menu->u.save.window[2] = TextWindow_CreateOpenWithFrame(1, 7, 0x1C, 5, 2, gUnknown_084F20FE);
        if ((u16)(menu->mode - 1) < 2)
            SaveScreen_DrawSlot(arg0, 3);
        else
            SaveScreen_DrawSlot(arg0, 1);
        sub_080D0264();
        break;
    case 3:
        if (menu->u.save.window[3] == 0)
            menu->u.save.window[3] = TextWindow_CreateOpenWithFrame(1, 12, 0x1C, 5, 2, gUnknown_084F20FE);
        SaveScreen_DrawSlot(arg0, 2);
        sub_080D0264();
        break;
    }
}

// BgMap_SetPaletteRect @ 0x080D0834
void BgMap_SetPaletteRect(u16 (*map)[32], u16 pal, u16 x, u16 y, u16 w, u16 h)
{
    u16 row, col;

    for (row = 0; row < h; row++)
        for (col = 0; col < w; col++)
        {
            u16 *p = &map[row + y][col + x];
            *p = (*p & 0xFFF) | (pal << 12);
        }
}

// sub_080D08B8 @ 0x080D08B8
void sub_080D08B8(void)
{
    BgMap_SetPaletteRect((void *)0x06002000, 0, 1, 2, 0x1C, 15);
    BgMap_SetPaletteRect((void *)0x06002000, 4, 1, 2, 0x1C, 5);
}

// sub_080D08F0 @ 0x080D08F0
void sub_080D08F0(void)
{
    BgMap_SetPaletteRect((void *)0x06002000, 0, 1, 2, 0x1C, 15);
    BgMap_SetPaletteRect((void *)0x06002000, 4, 1, 7, 0x1C, 5);
}

// sub_080D0928 @ 0x080D0928
void sub_080D0928(void)
{
    BgMap_SetPaletteRect((void *)0x06002000, 0, 1, 2, 0x1C, 15);
    BgMap_SetPaletteRect((void *)0x06002000, 4, 1, 12, 0x1C, 5);
}

// sub_080D0960 @ 0x080D0960
void sub_080D0960(void)
{
    struct SaveMenu *menu = &gMenuState;

    if (menu->u.save.unk28 == 2)
        Text_DrawSpriteString(menu->u.save.unk2C, 0, 0, 10, 0x69, 12);
    if (menu->u.save.unk28 == 1)
        menu->u.save.unk28 = 2;
    if (menu->unk08 == 1)
    {
        switch (menu->cursor)
        {
        case 0:
            VBlankTask_AddCounted(sub_080D08B8, 1);
            break;
        case 1:
            VBlankTask_AddCounted(sub_080D08F0, 1);
            break;
        case 2:
            VBlankTask_AddCounted(sub_080D0928, 1);
            break;
        }
    }
}

// sub_080D09D8 @ 0x080D09D8
void sub_080D09D8(u16 *obj, u32 keys)
{
    if (keys & gKeysNew)
    {
        obj[14] = 1;
        Sound_Play(0x65);
    }
    else
        obj[14] = 0;
    if (!((gFrameCounter >> 4) & 1))
        Sprite_Draw(gUnknown_08001000, 0, 0, 0, 0, 0xDD, 0x95);
}

// sub_080D0A2C @ 0x080D0A2C
void sub_080D0A2C(void *arg0)
{
    const u8 *str;

    switch (gMenuState.cursor)
    {
    case 0:
        str = gUnknown_084F1F7C;
        break;
    case 1:
        str = gUnknown_084F1FA8;
        break;
    case 2:
        str = gUnknown_084F1FD4;
        break;
    }
    sub_080D0084(arg0, str, 1);
}

// SaveScreen_HandleInput @ 0x080D0A74
void SaveScreen_HandleInput(struct MenuTask *task)
{
    struct SaveMenu *menu = &gMenuState;

    task->unk1C = 0;
    task->unk1E = 0;
    if (gKeysNew & 1)
    {
        if (SaveSlot_IsValid(menu->cursor) == 1)
        {
            task->unk1C = 1;
            task->unk1E = 1;
            Sound_Play(0x65);
        }
        else
            Sound_Play(0x66);
    }
    else if (gKeysNew & 2)
    {
        task->unk1C = 1;
        task->unk1E = 0x80;
        Sound_Play(0x66);
    }
    else if (gRepeatedKeys & 0x40)
    {
        if (menu->cursor != 0)
            menu->cursor--;
        else
            menu->cursor = 2;
        Sound_Play(0x64);
    }
    else if (gRepeatedKeys & 0x80)
    {
        if (menu->cursor != 2)
            menu->cursor++;
        else
            menu->cursor = 0;
        Sound_Play(0x64);
    }
    menu->unk08 = 1;
}

// LoadScreen_Confirm @ 0x080D0B18
void LoadScreen_Confirm(struct MenuTask *task, u32 cancelled)
{
    struct SaveMenu *menu = &gMenuState;

    if (!cancelled)
    {
        task->unk1E = SaveSlot_Read(menu->cursor, &gGameState, 0);
        if (menu->mode == 4)
            Flag_Clear(0x108);
    }
    else if (menu->mode != 4)
        sub_080B710C(gGameState.unkA32, gGameState.unkA34, gGameState.unkA2E,
                     gGameState.unkA30, gGameState.unkA2C, 0);
    else
        SetMainCallback(sub_080D96BC);
}

// sub_080D0BA0 @ 0x080D0BA0
void sub_080D0BA0(void)
{
    u8 *src = gGameState.unkA40;
    u8 *dst = gUnk_030069F0;
    u32 i;

    for (i = 0; i < 0x3C; i++)
        dst[i] = src[i];
    sub_080C2CD8((s8)gGameState.unkA3A, (s8)gGameState.unkA3C, 1);
}

// sub_080D0BF0 @ 0x080D0BF0
void sub_080D0BF0(struct MenuTask *task, u32 cancelled)
{
    if (!cancelled)
    {
        Game_NewGame();
        task->unk1E = SaveSlot_Read(3, &gGameState, 0);
        if (task->unk1E == 1)
            task->unk1E = SaveSlot_ClearSuspend();
    }
    else
    {
        struct GameState *state = &gGameState;
        u16 inBattle = state->unkAC0;

        if (inBattle == 0)
            sub_080B710C(state->unkA32, state->unkA34, state->unkA2E, state->unkA30, state->unkA2C, inBattle);
        else
            sub_080D0BA0();
    }
}

/* NONMATCHING: GCC reuses different field-offset constants and registers. */
// GameState_StoreLocation @ 0x080D0C74
#ifdef NONMATCHING
void GameState_StoreLocation(u32 mode)
{
    struct GameState *state = &gGameState;
    struct Unk03004550 *src = &gFieldState;
    u32 i;

    state->unkA2C = src->unk02;
    state->unkA2E = src->unk12;
    state->unkA30 = src->unk14;
    state->unkA32 = gUnk_03004614;
    state->unkA34 = gUnk_03004514;
    for (i = 0; i < 0x3C; i++)
        state->unkA40[i] = gUnk_030069F0[i];
    state->unkA3A = gUnk_03003FC4;
    state->unkA3C = gUnk_03004618;
    if (mode != 3)
    {
        state->unk18B0 = mode;
        state->unk18A0 = src->unk02;
        state->unk18A2 = src->unk12;
        state->unk18A4 = src->unk14;
        state->unk18A6 = gUnk_03004614;
        state->unk18A8 = gUnk_03004514;
        state->unk18AA = state->unkA38;
        state->unkAC2 = state->unkAC0;
    }
    if (Flag_Test(0xE5))
        sub_080C2A50(3, 1);
}
#else
NAKED
void GameState_StoreLocation(u32 mode)
{
    asm_unified(
        ".L080D0C74:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    mov r8, r0\n"
        "    ldr r1, .L080D0D60\n"
        "    ldr r3, .L080D0D64\n"
        "    ldrh r2, [r3, #2]\n"
        "    ldr r4, .L080D0D68\n"
        "    adds r0, r1, r4\n"
        "    strh r2, [r0]\n"
        "    ldrh r2, [r3, #0x12]\n"
        "    ldr r5, .L080D0D6C\n"
        "    adds r0, r1, r5\n"
        "    strh r2, [r0]\n"
        "    ldrh r2, [r3, #0x14]\n"
        "    movs r6, #0xa3\n"
        "    lsls r6, r6, #4\n"
        "    adds r0, r1, r6\n"
        "    strh r2, [r0]\n"
        "    ldr r5, .L080D0D70\n"
        "    ldr r2, [r5]\n"
        "    adds r4, #6\n"
        "    adds r0, r1, r4\n"
        "    strh r2, [r0]\n"
        "    ldr r4, .L080D0D74\n"
        "    ldr r2, [r4]\n"
        "    adds r6, #4\n"
        "    adds r0, r1, r6\n"
        "    strh r2, [r0]\n"
        "    ldr r0, .L080D0D78\n"
        "    mov ip, r0\n"
        "    movs r2, #0xa4\n"
        "    lsls r2, r2, #4\n"
        "    adds r7, r1, r2\n"
        "    movs r2, #0\n"
        "    adds r6, r1, #0\n"
        "    mov sb, r5\n"
        "    mov sl, r4\n"
        "    ldr r4, .L080D0D7C\n"
        ".L080D0CC6:\n"
        "    adds r0, r7, r2\n"
        "    mov r5, ip\n"
        "    adds r1, r5, r2\n"
        "    ldrb r1, [r1]\n"
        "    strb r1, [r0]\n"
        "    adds r2, #1\n"
        "    cmp r2, #0x3b\n"
        "    bls .L080D0CC6\n"
        "    ldr r1, [r4]\n"
        "    ldr r2, .L080D0D80\n"
        "    adds r0, r6, r2\n"
        "    strh r1, [r0]\n"
        "    ldr r4, .L080D0D84\n"
        "    ldr r1, [r4]\n"
        "    ldr r5, .L080D0D88\n"
        "    adds r0, r6, r5\n"
        "    strh r1, [r0]\n"
        "    mov r0, r8\n"
        "    cmp r0, #3\n"
        "    beq .L080D0D3E\n"
        "    ldr r1, .L080D0D8C\n"
        "    adds r0, r6, r1\n"
        "    mov r2, r8\n"
        "    str r2, [r0]\n"
        "    ldrh r1, [r3, #2]\n"
        "    movs r4, #0xc5\n"
        "    lsls r4, r4, #5\n"
        "    adds r0, r6, r4\n"
        "    strh r1, [r0]\n"
        "    ldrh r1, [r3, #0x12]\n"
        "    ldr r5, .L080D0D90\n"
        "    adds r0, r6, r5\n"
        "    strh r1, [r0]\n"
        "    ldrh r1, [r3, #0x14]\n"
        "    ldr r2, .L080D0D94\n"
        "    adds r0, r6, r2\n"
        "    strh r1, [r0]\n"
        "    mov r4, sb\n"
        "    ldr r1, [r4]\n"
        "    adds r5, #4\n"
        "    adds r0, r6, r5\n"
        "    strh r1, [r0]\n"
        "    mov r0, sl\n"
        "    ldr r1, [r0]\n"
        "    adds r2, #4\n"
        "    adds r0, r6, r2\n"
        "    strh r1, [r0]\n"
        "    ldr r4, .L080D0D98\n"
        "    adds r0, r6, r4\n"
        "    ldrh r1, [r0]\n"
        "    adds r5, #4\n"
        "    adds r0, r6, r5\n"
        "    strh r1, [r0]\n"
        "    movs r1, #0xac\n"
        "    lsls r1, r1, #4\n"
        "    adds r0, r6, r1\n"
        "    ldrh r1, [r0]\n"
        "    ldr r2, .L080D0D9C\n"
        "    adds r0, r6, r2\n"
        "    strb r1, [r0]\n"
        ".L080D0D3E:\n"
        "    movs r0, #0xe5\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    beq .L080D0D50\n"
        "    movs r0, #3\n"
        "    movs r1, #1\n"
        "    bl sub_080C2A50\n"
        ".L080D0D50:\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080D0D60: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080D0D64: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080D0D68: .4byte 0x00000A2C\n"
        ".L080D0D6C: .4byte 0x00000A2E\n"
        ".L080D0D70: .4byte 0x03004614 @ IWRAM+0x4614\n"
        ".L080D0D74: .4byte 0x03004514 @ IWRAM+0x4514\n"
        ".L080D0D78: .4byte 0x030069F0 @ IWRAM+0x69F0\n"
        ".L080D0D7C: .4byte 0x03003FC4 @ IWRAM+0x3FC4\n"
        ".L080D0D80: .4byte 0x00000A3A\n"
        ".L080D0D84: .4byte 0x03004618 @ IWRAM+0x4618\n"
        ".L080D0D88: .4byte 0x00000A3C\n"
        ".L080D0D8C: .4byte 0x000018B0\n"
        ".L080D0D90: .4byte 0x000018A2\n"
        ".L080D0D94: .4byte 0x000018A4\n"
        ".L080D0D98: .4byte 0x00000A38\n"
        ".L080D0D9C: .4byte 0x00000AC2\n"
    );
}
#endif

// SaveScreen_WriteSuspend @ 0x080D0DA0
void SaveScreen_WriteSuspend(struct MenuTask *task)
{
    struct SaveMenu *menu = &gMenuState;

    GameState_StoreLocation(3);
    task->unk1E = SaveSlot_Write(3, &gGameState);
    if (task->unk1E == 1)
        menu->unk02 = 0;
}

// sub_080D0DD0 @ 0x080D0DD0
void sub_080D0DD0(struct MenuTask *task)
{
    struct SaveMenu *menu = &gMenuState;

    task->unk1C = 0;
    task->unk1E = 0;
    if (gKeysNew & 1)
    {
        task->unk1C = 1;
        task->unk1E = 1;
        Sound_Play(0x65);
    }
    else if (gKeysNew & 2)
    {
        task->unk1C = 1;
        task->unk1E = 0x80;
        Sound_Play(0x66);
        gYesNoResult = 1;
    }
    else if (gRepeatedKeys & 0x40)
    {
        if (menu->cursor != 0)
            menu->cursor--;
        else
            menu->cursor = 2;
        Sound_Play(0x64);
    }
    else if (gRepeatedKeys & 0x80)
    {
        if (menu->cursor != 2)
            menu->cursor++;
        else
            menu->cursor = 0;
        Sound_Play(0x64);
    }
    menu->unk08 = 1;
}

// sub_080D0E74 @ 0x080D0E74
u32 sub_080D0E74(void)
{
    u32 ret = 0;

    if (gUnk_03004614 == 0 && gFieldState.unk12 == 2 && gFieldState.unk14 == 6)
        ret = 1;
    return ret;
}

/* NONMATCHING: only menu/p swap registers (r6/r4). */
// SaveScreen_WriteSlot @ 0x080D0EA0
#ifdef NONMATCHING
void SaveScreen_WriteSlot(struct MenuTask *task)
{
    struct SaveMenu *menu = &gMenuState;
    struct Unk03004550 *p;
    u16 v;

    if (menu->unk02 != 2)
    {
        if (sub_080D0E74() == 1)
        {
            if (!Flag_Test(2))
                goto skip;
            p = &gFieldState;
            v = p->unk02 = 3;
        }
        else
        {
            p = &gFieldState;
            v = p->unk02;
        }
        Field_Step(sub_080B1A1C(v));
        p->unk02 = sub_080B1A1C(p->unk02);
    }
skip:
    if (menu->unk02 != 4)
    {
        Flag_Set(0xCB);
        Flag_Set(0x163);
    }
    GameState_StoreLocation(menu->cursor);
    task->unk1E = SaveSlot_Write(menu->cursor, &gGameState);
    if (menu->unk02 != 2)
    {
        p = &gFieldState;
        Field_Step(sub_080B1A1C(p->unk02));
        p->unk02 = sub_080B1A1C(p->unk02);
    }
    gUnk_03003BB4 = 0;
    gYesNoResult = 0;
    if (menu->unk02 != 4)
        menu->unk02 = 0;
}
#else
NAKED
void SaveScreen_WriteSlot(struct MenuTask *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    adds r7, r0, #0\n"
        "    ldr r6, .L080D0EC8\n"
        "    ldrh r0, [r6, #2]\n"
        "    cmp r0, #2\n"
        "    beq .L080D0EE8\n"
        "    bl sub_080D0E74\n"
        "    cmp r0, #1\n"
        "    bne .L080D0ED0\n"
        "    movs r0, #2\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    beq .L080D0EE8\n"
        "    ldr r4, .L080D0ECC\n"
        "    movs r0, #3\n"
        "    strh r0, [r4, #2]\n"
        "    b .L080D0ED4\n"
        "    .byte 0x00, 0x00\n"
        ".L080D0EC8: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L080D0ECC: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080D0ED0:\n"
        "    ldr r4, .L080D0F40\n"
        "    ldrh r0, [r4, #2]\n"
        ".L080D0ED4:\n"
        "    bl sub_080B1A1C\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Field_Step\n"
        "    ldrh r0, [r4, #2]\n"
        "    bl sub_080B1A1C\n"
        "    strh r0, [r4, #2]\n"
        ".L080D0EE8:\n"
        "    ldrh r0, [r6, #2]\n"
        "    cmp r0, #4\n"
        "    beq .L080D0EFA\n"
        "    movs r0, #0xcb\n"
        "    bl Flag_Set\n"
        "    ldr r0, .L080D0F44\n"
        "    bl Flag_Set\n"
        ".L080D0EFA:\n"
        "    ldrh r0, [r6, #6]\n"
        "    bl GameState_StoreLocation\n"
        "    ldrh r0, [r6, #6]\n"
        "    ldr r1, .L080D0F48\n"
        "    bl SaveSlot_Write\n"
        "    movs r5, #0\n"
        "    strh r0, [r7, #0x1e]\n"
        "    ldrh r0, [r6, #2]\n"
        "    cmp r0, #2\n"
        "    beq .L080D0F2A\n"
        "    ldr r4, .L080D0F40\n"
        "    ldrh r0, [r4, #2]\n"
        "    bl sub_080B1A1C\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Field_Step\n"
        "    ldrh r0, [r4, #2]\n"
        "    bl sub_080B1A1C\n"
        "    strh r0, [r4, #2]\n"
        ".L080D0F2A:\n"
        "    ldr r0, .L080D0F4C\n"
        "    str r5, [r0]\n"
        "    ldr r0, .L080D0F50\n"
        "    str r5, [r0]\n"
        "    ldrh r0, [r6, #2]\n"
        "    cmp r0, #4\n"
        "    beq .L080D0F3A\n"
        "    strh r5, [r6, #2]\n"
        ".L080D0F3A:\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080D0F40: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080D0F44: .4byte 0x00000163\n"
        ".L080D0F48: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080D0F4C: .4byte 0x03003BB4 @ IWRAM+0x3BB4\n"
        ".L080D0F50: .4byte 0x030031CC @ IWRAM+0x31CC\n"
    );
}
#endif

// sub_080D0F54 @ 0x080D0F54
void sub_080D0F54(void)
{
    gUnk_03003BB4 = 0;
}

// SaveScreen_Close @ 0x080D0F60
void SaveScreen_Close(void)
{
    struct SaveMenu *menu = &gMenuState;

    if (menu->u.save.window[0] != 0)
        TextWindow_Close(menu->u.save.window[0], 1);
    if (menu->u.save.window[1] != 0)
        TextWindow_Close(menu->u.save.window[1], 1);
    if (menu->u.save.window[2] != 0)
        TextWindow_Close(menu->u.save.window[2], 1);
    if (menu->u.save.window[3] != 0)
        TextWindow_Close(menu->u.save.window[3], 1);
    if (menu->u.save.unk20 != 0)
        Window_Close(menu->u.save.unk20, 1);

    if (menu->unk02 == 0)
        Music_Play(menu->unk0A);
    if (menu->unk02 == 0)
    {
        if (menu->mode == 0)
            sub_080D5B8C(1);
        else if (menu->mode == 1)
            sub_080D5B8C(2);
        else if (menu->mode == 2)
            sub_080D5B8C(0);
        else if (menu->mode == 3)
            *(u32 *)(menu->u.save.unk0C + 0xC) = 1;
    }
    else if (menu->unk02 == 1)
    {
        *(u32 *)(menu->u.save.unk0C + 0xC) = 1;
        if (menu->mode == 2)
            Music_Play(menu->unk0A);
    }
    else if (menu->unk02 == 2)
        *(u32 *)(menu->u.save.unk0C + 0xC) = 1;
    else if (menu->unk02 == 3)
        sub_080D5B8C(3);
    else if (menu->unk02 == 4)
        sub_080D5B8C(0);
}

// sub_080D1024 @ 0x080D1024
void sub_080D1024(void)
{
    vu16 zero;

    zero = 0;
    DmaSet3(&zero, 0x06000000, 0x81000800);
    zero = 0;
    DmaSet3(&zero, 0x06001000, 0x81000800);
    zero = 0;
    DmaSet3(&zero, 0x06002000, 0x81000800);
}

// sub_080D106C @ 0x080D106C
void sub_080D106C(void)
{
    sub_080C6558();
    CpuSet(gWindowTilemapBuffer, gUnk_02018874, 0x04000200);
    VBlankTask_AddCounted(sub_080D1024, 1);
}

// sub_080D1098 @ 0x080D1098
void sub_080D1098(void)
{
    struct SaveMenu *menu = &gMenuState;

    if (menu->unk02 == 0 || menu->mode == 2)
        Music_FadeOut(4);
}

// sub_080D10B8 @ 0x080D10B8
void sub_080D10B8(void)
{
    struct SaveMenu *menu = &gMenuState;

    if (menu->unk02 == 0)
        Music_Play(0x16);
    else if (menu->mode == 2)
    {
        switch (Combatant_GetAlignment(0))
        {
        case 0:
            Music_Play(0x0E);
            break;
        case 1:
            Music_Play(7);
            break;
        case 2:
            Music_Play(0x14);
            break;
        }
    }
}

// SaveScreen_Open @ 0x080D110C
u32 SaveScreen_Open(u16 mode, u16 arg1)
{
    struct SaveMenu *menu;
    u32 ret = Task_Create(gUnknown_084F2134, 0xFFFF);
    u32 zero;

    menu = &gMenuState;
    zero = 0;
    CpuSet(&zero, menu, 0x05000200);
    menu->mode = mode;
    menu->unk02 = arg1;
    menu->unk0A = gUnk_030031B4;
    if (mode == 3)
    {
        menu->cursor = gGameState.unk18B0;
        Flag_Clear(0xC4);
        Flag_Clear(0xCA);
    }
    return ret;
}

/* Formats the SRAM image when the header magic/version do not match. */
// Sram_FormatIfInvalid @ 0x080D1180
void Sram_FormatIfInvalid(void)
{
    u32 header[8];
    u32 zero;
    u32 i;
    struct SramImage *buf;

    if (Sram_ReadVerified(SRAM_BASE, header, 0x20) && (header[0] != 0x10241179 || header[1] != 0x11))
    {
        buf = (struct SramImage *)gUnk_0200F874;
        zero = 0;
        CpuSet(&zero, buf, 0x05002000);
        buf->magic = 0x10241179;
        buf->version = 0x11;
        buf->unk10 = 0x2A95;
        buf->unk6C9C = 0xFFFF;
        buf->unk6C9E = -1;
        buf->unk6CA0 = 0;
        buf->unk6CA2 = 0x17;
        for (i = 0; i < 3; i++)
        {
            sub_0815CBB4(buf, SRAM_BASE, 0x8000);
            if (sub_0815CC24(buf, SRAM_BASE, 0x8000) == 0)
                break;
        }
    }
}

// Sram_WriteVerified @ 0x080D1230
u32 Sram_WriteVerified(const void *src, void *dst, u32 size)
{
    u32 i;

    for (i = 0; i < 3; i++)
    {
        sub_0815CBB4(src, dst, size);
        if (sub_0815CC24(src, dst, size) == 0)
            return 1;
    }
    return 0;
}

// SaveSlot_Write @ 0x080D1264
u32 SaveSlot_Write(u32 slot, struct GameState *src)
{
    u8 *sram = SRAM_BASE;
    u32 size;
    u32 sum;
    u32 i;

    if (Sram_WriteVerified(src, sram + 0x9C + slot * SAVE_SLOT_STRIDE, size = SAVE_SLOT_SIZE))
    {
        sum = 0;
        for (i = 0; i < size; i++)
            sum += ((u8 *)src)[i];
        if (Sram_WriteVerified(&sum, sram + 0x8C + slot * 4, 4))
        {
            sum = 1;
            if (Sram_WriteVerified(&sum, sram + 0x7C + slot * 4, 4))
            {
                sub_080C2704();
                sub_080C27BC();
                sub_080C2950();
                sub_080C2980();
                return 1;
            }
        }
    }
    return 0;
}

// Sram_ReadVerified @ 0x080D12F4
u32 Sram_ReadVerified(const void *src, void *dst, u32 size)
{
    u32 i;

    for (i = 0; i < 3; i++)
    {
        sub_0815CB50(src, dst, size);
        if (sub_0815CC24(src, dst, size) == 0)
            return 1;
    }
    return 0;
}

// SaveSlot_Read @ 0x080D1328
u32 SaveSlot_Read(u32 slot, struct GameState *dst, u32 noApply)
{
    u32 size;
    u32 stored;
    u32 sum;
    u32 i;

    if (!Sram_ReadVerified((u8 *)0x0E00009C + slot * SAVE_SLOT_STRIDE, dst, size = SAVE_SLOT_SIZE))
        return 0;
    if (!Sram_ReadVerified((u8 *)0x0E00008C + slot * 4, &stored, 4))
        return 0;
    sum = 0;
    for (i = 0; i < size; i++)
        sum += ((u8 *)dst)[i];
    if (sum != stored)
        return 0;
    if (noApply == 0)
    {
        sub_080C271C();
        sub_080C27F0();
        sub_080C2968();
        ComboBits_Clear();
    }
    return 1;
}

// SaveSlot_ClearSuspend @ 0x080D13A8
u32 SaveSlot_ClearSuspend(void)
{
    u32 zero = 0;

    if (!Sram_WriteVerified(&zero, (u8 *)0x0E000088, 4))
        return 0;
    return 1;
}

// SaveSlot_IsValid @ 0x080D13D0
u32 SaveSlot_IsValid(u32 slot)
{
    u32 valid;

    if (!Sram_ReadVerified((u8 *)0x0E00007C + slot * 4, &valid, 4))
        return 0;
    return valid == 1;
}

// sub_080D1404 @ 0x080D1404
void sub_080D1404(struct MenuTask *task)
{
    struct SaveMenu *menu = &gMenuState;

    if ((u16)(menu->mode - 1) < 2)
        task->unk1E = SaveSlot_IsValid(3);
    else
        task->unk1E = SaveSlot_IsValid(menu->cursor);
}

// SaveSlot_AnyValid @ 0x080D1430
/* TRUE when any of the three normal save slots holds a valid save. */
u32 SaveSlot_AnyValid(void)
{
    u32 i;

    for (i = 0; i < 3; i++)
    {
        if (SaveSlot_IsValid(i) == 1)
            return 1;
    }
    return 0;
}

// sub_080D1450 @ 0x080D1450
void sub_080D1450(void)
{
    struct SaveMenu *menu = &gMenuState;

    DmaSet3(gBgPictureBuffer, 0x06015000, 0x84000400);
    DmaSet3(gUnknown_084F2BFC, 0x06001340, 0x84000070);
    menu->u.name.gfxQueued = 0;
}

// sub_080D1498 @ 0x080D1498
void sub_080D1498(void)
{
    struct SaveMenu *menu = &gMenuState;

    if (menu->u.name.gfxQueued == 0)
    {
        VBlankTask_AddCounted(sub_080D1450, 1);
        menu->u.name.gfxQueued = 1;
    }
}

// sub_080D14BC @ 0x080D14BC
void sub_080D14BC(u32 arg0, u32 phase)
{
    if (phase == 0)
    {
        LZ77UnCompWram(gUnknown_084F2974, gBgPictureBuffer);
        Palette_CopyWithEffect(3, gUnknown_084F2DBC, &gUnk_03002E10[0x1A0], 0x20, 0x10);
        Palette_CopyWithEffect(3, gUnknown_081B6E90, gUnk_03002E10, 0x20, 0x10);
        Palette_MarkDirty();
        sub_080C6E30(1);
        gUnk_03000004 = 0xFFF8;
        gUnk_03000040 = phase;
        sub_080D1498();
    }
}

// sub_080D1538 @ 0x080D1538
void sub_080D1538(void)
{
    DmaSet3(gUnk_02000000, 0x06011800, 0x84000200);
}

// NameEntry_RenderName @ 0x080D155C
/* Renders the name typed so far into sprite tiles. */
void NameEntry_RenderName(void)
{
    struct SaveMenu *menu = &gMenuState;
    u16 glyphs[8];
    u32 i;

    Combatant_DecodeName(menu->u.name.name, glyphs);
    for (i = 0; i < 8; i++)
        Font_CopyGlyphCell(Font_GetGlyphBitmap(glyphs[i]), gUnk_02000000 + i * 0x40);
    VBlankTask_AddCounted(sub_080D1538, 1);
    gUnk_0200E7D4[0x1F] = 1;
    gUnk_0200E7D4[0x20] = 1;
}

// sub_080D15B0 @ 0x080D15B0
void sub_080D15B0(void)
{
    struct SaveMenu *menu = &gMenuState;

    Font_ResetGlyphSpriteCache(0x180);
    menu->u.name.window = Window_Create(2, 11, 0x1A, 2, 0);
}
