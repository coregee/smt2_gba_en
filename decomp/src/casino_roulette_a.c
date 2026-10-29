/* Russian Roulette (0x0814D688-0x0814E843). The player and the opponent each put up a demon;
   a six-chamber gun decides which one is lost. */

#include "global.h"
#include "casino3.h"

#define GR ((struct C14aRoulette *)gMenuState)

// sub_0814D688 @ 0x0814D688
void sub_0814D688(u32 unused, u32 value)
{
    GR->startScript = value;
}

/* Draws sprite slot n (frame 0 = hidden) at its stored position, or at (x, y) when none is
   stored. */
// RussianRoulette_DrawSlot @ 0x0814D694
void RussianRoulette_DrawSlot(u16 slot, u16 x, u16 y)
{
    struct C14aRoulette *s = GR;
    const void *const *frames = gUnknown_0879F334[slot];

    if (s->frame[slot] != 0)
    {
        if (s->x[slot] != 0 || s->y[slot] != 0)
        {
            x = s->x[slot];
            y = s->y[slot];
        }
        Sprite_Draw(frames[s->frame[slot]], 0, 0, 0, 0, x, y);
    }
}

/* Sets a slot's frame; x and y only when non-zero. */
// RussianRoulette_SetSlot @ 0x0814D70C
void RussianRoulette_SetSlot(u16 slot, u16 frame, u16 x, u16 y)
{
    struct C14aRoulette *s = GR;

    s->frame[slot] = frame;
    if (x != 0)
        s->x[slot] = x;
    if (y != 0)
        s->y[slot] = y;
}

// sub_0814D748 @ 0x0814D748
void sub_0814D748(u16 slot, u16 frame, u16 x, u16 y)
{
    struct C14aRoulette *s = GR;

    s->frame[slot] = frame;
    s->x[slot] = x;
    s->y[slot] = y;
}

/* Script command wrappers (task, slot, frame, x, y). */
// sub_0814D774 @ 0x0814D774
void sub_0814D774(u32 task, u16 slot, u16 frame, u16 x, u16 y)
{
    RussianRoulette_SetSlot(slot, frame, x, y);
}

// sub_0814D798 @ 0x0814D798
void sub_0814D798(u32 task, u16 slot, u16 frame, u16 x, u16 y)
{
    sub_0814D748(slot, frame, x, y);
}

/* Starts the game: lists the demons of the party (records 4-15 in use). */
// RussianRoulette_Init @ 0x0814D7BC
void RussianRoulette_Init(void)
{
    struct C14aRoulette *s = GR;
    u32 zero = 0;
    u32 zero2;
    u32 i;
    u16 n;

    CpuSet(&zero, s, 0x05000200);
    zero2 = 0;
    DmaSet3(&zero2, 0x06000000, 0x85001000);
    REG_BG0CNT = 0x4008;
    gUnk_03000002 = 0;
    gUnk_03000040 = 0;
    s->startScript = 1;
    RussianRoulette_SetSlot(0, 1, 0, 0);
    RussianRoulette_SetSlot(1, 0, 0, 0);
    RussianRoulette_SetSlot(2, 1, 0, 0);
    RussianRoulette_SetSlot(3, 1, 0, 0);
    RussianRoulette_SetSlot(4, 0, 0, 0);
    RussianRoulette_SetSlot(5, 0, 0, 0);
    RussianRoulette_SetSlot(6, 0, 0, 0);
    RussianRoulette_SetSlot(7, 0, 0, 0);
    RussianRoulette_SetSlot(8, 0, 0, 0);
    RussianRoulette_SetSlot(9, 0, 0, 0);
    RussianRoulette_SetSlot(10, 1, 0, 0);
    RussianRoulette_SetSlot(11, 0, 0, 0);
    RussianRoulette_SetSlot(12, 1, 0, 0);
    RussianRoulette_SetSlot(13, 1, 0, 0);
    RussianRoulette_SetSlot(14, 1, 0, 0);
    RussianRoulette_SetSlot(15, 0, 0, 0);
    RussianRoulette_SetSlot(16, 0, 0, 0);
    RussianRoulette_SetSlot(17, 0, 0, 0);
    for (i = 0; i < 12; i++)
    {
        s->mine[i] |= 0xFFFF;
        s->theirs[i] |= 0xFFFF;
    }
    n = 0;
    for (i = 4; i < 16; i++)
    {
        if (Combatant_IsUsed(i))
        {
            s->mine[n] = gGameState[i].id;
            n++;
        }
    }
    s->count = n;
}

// RussianRoulette_Update @ 0x0814D958
void RussianRoulette_Update(void)
{
    struct C14aRoulette *s = GR;

    switch (s->startScript)
    {
    case 1:
        Task_Create(gUnknown_0879F3C4, 0xFFFF);
        s->startScript = 0;
        break;
    case 2:
        sub_080BE4C4();
        s->startScript = 0;
        break;
    case 0:
        break;
    }
    RussianRoulette_DrawSlot(2, 0x10, 5);
    if (!((gFrameCounter >> 4) & 1))
        RussianRoulette_SetSlot(2, 1, 0, 0);
    else
        RussianRoulette_SetSlot(2, 2, 0, 0);
    RussianRoulette_DrawSlot(0, 7, 4);
    RussianRoulette_DrawSlot(3, 0xBB, 5);
    RussianRoulette_DrawSlot(1, 0xBB, 4);
    RussianRoulette_DrawSlot(4, 0x4F, 10);
    RussianRoulette_DrawSlot(5, 0x5E, 10);
    RussianRoulette_DrawSlot(6, 0x6D, 10);
    RussianRoulette_DrawSlot(7, 0x7C, 10);
    RussianRoulette_DrawSlot(8, 0x8B, 10);
    RussianRoulette_DrawSlot(9, 0x9A, 10);
    RussianRoulette_DrawSlot(10, 0, 0x20);
    RussianRoulette_DrawSlot(11, 0, 0x25);
    RussianRoulette_DrawSlot(14, 0xCF, 0x48);
    RussianRoulette_DrawSlot(13, 0xAC, 0x6C);
    RussianRoulette_DrawSlot(17, 0xF0, 100);
    RussianRoulette_DrawSlot(12, 0xA6, 0x50);
    RussianRoulette_DrawSlot(15, 0x5E, 0x1C);
    RussianRoulette_DrawSlot(16, 0x5E, 100);
}


/* One 8x8 character of the game's own font (tile 0x320 + c). */
// sub_0814DA70 @ 0x0814DA70
void sub_0814DA70(u8 c, u16 x, u16 y, u16 palette)
{
    Sprite_DrawSingle(gUnknown_0879F394, 0, palette, 0, c + 0x320, x, y);
}

/* Draws up to max characters of a byte string (ended by 0 or 0xFF), 8 pixels apart. */
// RussianRoulette_DrawText @ 0x0814DAAC
void RussianRoulette_DrawText(const u8 *str, u16 x, u16 y, u16 max, u16 palette)
{
    u16 i;
    u8 c;

    for (i = 0; i < max && (c = *str) != 0xFF && c != 0;)
    {
        sub_0814DA70(c, x, y, palette);
        i++;
        x += 8;
        str++;
    }
}


// sub_0814DB04 @ 0x0814DB04
void sub_0814DB04(u32 unused, u32 value)
{
    GR->startScript = value;
}

/* Script wait: result 1 once R is pressed. */
// sub_0814DB10 @ 0x0814DB10
void sub_0814DB10(struct C14aTask *task)
{
    u16 pressed = gKeysNew & 0x100;

    if (pressed)
    {
        Sound_Play(0x15A);
        pressed = 1;
    }
    task->result = pressed;
}

/* Blinks sprite slot 3 every 16 frames. */
// sub_0814DB3C @ 0x0814DB3C
void sub_0814DB3C(void)
{
    struct C14aRoulette *s = GR;

    if ((gFrameCounter & 0xF) == 0)
    {
        if (s->frame[3] == 1)
            s->frame[3] = 2;
        else if (s->frame[3] == 2)
            s->frame[3] = 1;
        else if (s->frame[3] == 3)
            s->frame[3] = 4;
        else if (s->frame[3] == 4)
            s->frame[3] = 3;
    }
}

/* Lists the hero's name and the party demons (grey when they cannot be bet). */
// sub_0814DB7C @ 0x0814DB7C
void sub_0814DB7C(void)
{
    struct C14aRoulette *s = GR;
    u16 x = 8;
    u16 i, y, id;
    u8 name[8];

    RussianRoulette_DrawText((const u8 *)gGameState, 8, 0x1A, 8, 0);
    y = 0x28;
    for (i = 0; i < 12; i++)
    {
        id = s->mine[i];
        if (id != 0xFFFF)
        {
            Name_Encode(Demon_GetRecord(id) + 0x22, name);
            if (RussianRoulette_CanBetDemon(Stock_FindDemon(id)->slot) == 1)
                RussianRoulette_DrawText(name, x, y, 8, 0);
            else
                RussianRoulette_DrawText(name, x, y, 8, 2);
        }
        y += 9;
    }
}

/* Choosing the demon to bet: up/down move, A accepts if the demon can be bet. */
// sub_0814DC20 @ 0x0814DC20
void sub_0814DC20(struct C14aTask *task)
{
    struct C14aRoulette *s = GR;
    u16 count = s->count;
    u32 ok;

    task->result = 0;
    if (gKeysNew & 1)
    {
        ok = RussianRoulette_CanBetDemon(Stock_FindDemon(s->mine[s->myPick])->slot);
        if (ok == 1)
        {
            Sound_Play(0x65);
            task->result = ok;
        }
        else
            Sound_Play(0x66);
    }
    else if (gRepeatedKeys & 0x40)
    {
        Sound_Play(0x64);
        if (s->myPick != 0)
            s->myPick--;
        else
            s->myPick = count - 1;
    }
    else if (gRepeatedKeys & 0x80)
    {
        Sound_Play(0x64);
        if (s->myPick != count - 1)
            s->myPick++;
        else
            s->myPick = 0;
    }
    RussianRoulette_SetSlot(11, 1, 0, s->myPick * 9 + 0x25);
}

// sub_0814DCF8 @ 0x0814DCF8
void sub_0814DCF8(void)
{
    RussianRoulette_DrawText(gUnknown_0879F39C, 8, 0x59, 8, 0);
    RussianRoulette_DrawText(gUnknown_0879F3A1, 8, 0x65, 8, 0);
}

/* Choosing between the two answers drawn by sub_0814DCF8. */
// sub_0814DD2C @ 0x0814DD2C
void sub_0814DD2C(struct C14aTask *task)
{
    struct C14aRoulette *s = GR;

    task->result = 0;
    if (gKeysNew & 1)
    {
        Sound_Play(0x65);
        task->result = 1;
    }
    else if (gRepeatedKeys & 0x40)
    {
        Sound_Play(0x64);
        if (s->side != 0)
            s->side--;
        else
            s->side = 1;
    }
    else if (gRepeatedKeys & 0x80)
    {
        Sound_Play(0x64);
        if (s->side != 1)
            s->side++;
        else
            s->side = 0;
    }
    RussianRoulette_SetSlot(11, 1, 0, s->side * 12 + 0x56);
}

/* Lists the opponent's name and demons. */
// sub_0814DDC8 @ 0x0814DDC8
void sub_0814DDC8(void)
{
    struct C14aRoulette *s = GR;
    u16 x, y, i, id;
    u8 name[8];

    if (gUnk_0203DB72 != 3)
        RussianRoulette_DrawText(gUnknown_0879F37C[gUnk_0203DB72], 8, 0x1A, 8, 0);
    else
        RussianRoulette_DrawText(gUnk_030050C8, 8, 0x1A, 8, 0);
    x = 8;
    y = 0x28;
    for (i = 0; i < 12; i++)
    {
        id = s->theirs[i];
        if (id != 0xFFFF)
        {
            Name_Encode(Demon_GetRecord(id) + 0x22, name);
            RussianRoulette_DrawText(name, x, y, 8, 0);
            y += 9;
        }
    }
}

/* The opponent's cursor walks down to the same list position as the player's choice. */
// sub_0814DE64 @ 0x0814DE64
void sub_0814DE64(struct C14aTask *task)
{
    struct C14aRoulette *s = GR;

    task->result = 0;
    if (s->myPick == s->theirPick)
    {
        Sound_Play(0x65);
        task->result = 1;
    }
    else
    {
        Sound_Play(0x64);
        s->theirPick++;
    }
    RussianRoulette_SetSlot(11, 1, 0, s->theirPick * 9 + 0x25);
}

// sub_0814DEBC @ 0x0814DEBC
void sub_0814DEBC(u32 task, s32 mode)
{
    struct C14aRoulette *s = GR;

    if (mode == 0)
        RussianRoulette_SetSlot(12, 1, 0xA6, 0x50);
    else if (mode == 1)
        s->y[12]++;
    else
        s->y[12]--;
}

// sub_0814DEF4 @ 0x0814DEF4
void sub_0814DEF4(u32 task, s32 mode)
{
    struct C14aRoulette *s = GR;

    if (mode == 0)
        RussianRoulette_SetSlot(17, 1, 0xF0, 100);
    else
        s->x[17] -= 2;
}

// sub_0814DF20 @ 0x0814DF20
void sub_0814DF20(u32 task, s32 mode, s32 dx, s32 dy)
{
    struct C14aRoulette *s = GR;

    if (mode == 0)
        sub_0814D748(10, 1, 0, 0x20);
    else
    {
        s->x[10] += dx;
        s->y[10] += dy;
    }
}

/* The two players and their bets, the one who shoots first on top. */
// sub_0814DF54 @ 0x0814DF54
#ifdef NONMATCHING
void sub_0814DF54(void)
{
    struct C14aRoulette *s = GR;
    u16 y1, y2, x3, y3, y4;
    u8 name[8];

    if (s->side == 0)
    {
        y1 = 0x38;
        y2 = 0x4C;
        x3 = 8;
        y3 = 0x78;
        y4 = 0x94;
    }
    else
    {
        y1 = 0x78;
        y2 = 0x94;
        x3 = 8;
        y3 = 0x38;
        y4 = 0x4C;
    }
    RussianRoulette_DrawText((const u8 *)gGameState, 8, y1, 8, 0);
    Name_Encode(Demon_GetRecord(s->mine[s->myPick]) + 0x22, name);
    RussianRoulette_DrawText(name, 0x5C, y2, 8, 0);
    if (gUnk_0203DB72 != 3)
        RussianRoulette_DrawText(gUnknown_0879F37C[gUnk_0203DB72], x3, y3, 8, 0);
    else
        RussianRoulette_DrawText((const u8 *)gGameState + 0xA08, x3, y3, 8, 0);
    Name_Encode(Demon_GetRecord(s->theirs[s->theirPick]) + 0x22, name);
    RussianRoulette_DrawText(name, 0x5C, y4, 8, 0);
}
#else
NAKED
void sub_0814DF54(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0xc\n"
        "    ldr r4, .L0814DF80\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0xcc\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L0814DF84\n"
        "    movs r2, #0x38\n"
        "    movs r0, #0x4c\n"
        "    mov r8, r0\n"
        "    movs r1, #8\n"
        "    mov sb, r1\n"
        "    movs r6, #0x78\n"
        "    movs r0, #0x94\n"
        "    mov sl, r0\n"
        "    b .L0814DF94\n"
        "    .byte 0x00, 0x00\n"
        ".L0814DF80: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L0814DF84:\n"
        "    movs r2, #0x78\n"
        "    movs r1, #0x94\n"
        "    mov r8, r1\n"
        "    movs r0, #8\n"
        "    mov sb, r0\n"
        "    movs r6, #0x38\n"
        "    movs r1, #0x4c\n"
        "    mov sl, r1\n"
        ".L0814DF94:\n"
        "    ldr r7, .L0814DFE8\n"
        "    movs r5, #0\n"
        "    str r5, [sp]\n"
        "    adds r0, r7, #0\n"
        "    movs r1, #8\n"
        "    movs r3, #8\n"
        "    bl RussianRoulette_DrawText\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0xc8\n"
        "    ldrh r1, [r0]\n"
        "    lsls r1, r1, #1\n"
        "    subs r0, #0x48\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    bl Demon_GetRecord\n"
        "    adds r0, #0x22\n"
        "    add r1, sp, #4\n"
        "    bl Name_Encode\n"
        "    str r5, [sp]\n"
        "    add r0, sp, #4\n"
        "    movs r1, #0x5c\n"
        "    mov r2, r8\n"
        "    movs r3, #8\n"
        "    bl RussianRoulette_DrawText\n"
        "    ldr r1, .L0814DFEC\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #3\n"
        "    beq .L0814DFF4\n"
        "    lsls r0, r0, #3\n"
        "    ldr r1, .L0814DFF0\n"
        "    adds r0, r0, r1\n"
        "    str r5, [sp]\n"
        "    mov r1, sb\n"
        "    adds r2, r6, #0\n"
        "    movs r3, #8\n"
        "    bl RussianRoulette_DrawText\n"
        "    b .L0814E004\n"
        ".L0814DFE8: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L0814DFEC: .4byte 0x0203DB72 @ EWRAM+0x3DB72\n"
        ".L0814DFF0: .4byte gUnknown_0879F37C\n"
        ".L0814DFF4:\n"
        "    ldr r1, .L0814E040\n"
        "    adds r0, r7, r1\n"
        "    str r5, [sp]\n"
        "    mov r1, sb\n"
        "    adds r2, r6, #0\n"
        "    movs r3, #8\n"
        "    bl RussianRoulette_DrawText\n"
        ".L0814E004:\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0xca\n"
        "    ldrh r1, [r0]\n"
        "    lsls r1, r1, #1\n"
        "    subs r0, #0x32\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    bl Demon_GetRecord\n"
        "    adds r0, #0x22\n"
        "    add r1, sp, #4\n"
        "    bl Name_Encode\n"
        "    movs r0, #0\n"
        "    str r0, [sp]\n"
        "    add r0, sp, #4\n"
        "    movs r1, #0x5c\n"
        "    mov r2, sl\n"
        "    movs r3, #8\n"
        "    bl RussianRoulette_DrawText\n"
        "    add sp, #0xc\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L0814E040: .4byte 0x00000A08\n"
    );
}
#endif

/* Loads the gun: chamber = (rand(0-7) * 3) / 4, so chambers 0 and 3 come up twice as often. */
// RussianRoulette_LoadGun @ 0x0814E044
void RussianRoulette_LoadGun(void)
{
    struct C14aRoulette *s = GR;

    s->chamber = ((Random_Byte() & 7) * 3) >> 2;
}

/* Pulls the trigger on chamber n (even n = player slot 15, odd = slot 16). result2 = 2 when the
   shot hits the player who went first (side), 1 the other one. */
// RussianRoulette_Fire @ 0x0814E064
void RussianRoulette_Fire(struct C14aTask *task, u32 n)
{
    struct C14aRoulette *s = GR;

    task->result2 = 0;
    if (s->chamber == n)
    {
        task->result = 1;
        if (!(n & 1))
        {
            RussianRoulette_SetSlot(15, 4, 0, 0);
            Sound_Play(0x18C);
        }
        else
        {
            RussianRoulette_SetSlot(16, 4, 0, 0);
            Sound_Play(0x18C);
        }
        if ((n & 1) == s->side)
            task->result2 = 2;
        else
            task->result2 = 1;
    }
}

/* Script wait for the player whose turn it is (n = shot number; even shots are the first
   player's): R pulls the trigger. On the opponent's turn it proceeds at once. */
// sub_0814E0CC @ 0x0814E0CC
void sub_0814E0CC(struct C14aTask *task, s32 n)
{
    struct C14aRoulette *s = GR;

    task->result = 0;
    if (s->side == 0)
    {
        if (n == 0 || n == 2 || n == 4)
            goto mine;
    }
    else if (n != 0 && n != 2 && n != 4)
    {
    mine:
        if (gKeysNew & 0x100)
            task->result = 1;
        else if (!((gFrameCounter >> 4) & 1))
            RussianRoulette_SetSlot(3, 3, 0, 0);
        else
            RussianRoulette_SetSlot(3, 4, 0, 0);
        goto done;
    }
    task->result = 1;
    RussianRoulette_SetSlot(3, 1, 0, 0);
done:
    if (task->result == 1)
    {
        RussianRoulette_SetSlot(13, 3, 0, 0);
        RussianRoulette_SetSlot(3, 3, 0, 0);
    }
}

/* Mode 0: reset the opponent's cursor; 1: step it to the player's choice; else: the player
   loses the bet demon (released). */
// sub_0814E174 @ 0x0814E174
void sub_0814E174(struct C14aTask *task, s32 mode)
{
    struct C14aRoulette *s = GR;

    task->result = 0;
    if (mode == 0)
        s->theirPick = mode;
    else if (mode == 1)
    {
        if (s->theirPick != s->myPick)
            s->theirPick++;
        else
            task->result = mode;
    }
    else
    {
        Party_Remove(Stock_FindDemon(s->mine[s->myPick])->slot, 1);
        s->mine[s->myPick] = 0xFFFF;
    }
    RussianRoulette_SetSlot(11, 1, 0, s->theirPick * 9 + 0x25);
}

// sub_0814E1FC @ 0x0814E1FC
void sub_0814E1FC(struct C14aTask *task, s32 mode)
{
    struct C14aRoulette *s = GR;

    task->result = 0;
    if (mode == 0)
        s->myPick = mode;
    else if (mode == 1)
    {
        if (s->myPick != s->count)
            s->myPick++;
        else
            task->result = mode;
    }
    RussianRoulette_SetSlot(11, 1, 0, s->myPick * 9 + 0x25);
}

/* result 1 when the stock is full (count >= the limit at gGameState+0xAC3). */
// sub_0814E24C @ 0x0814E24C
void sub_0814E24C(struct C14aTask *task)
{
    struct C14aRoulette *s = GR;
    u8 *g = (u8 *)gGameState;

    if (s->count >= g[0xAC3])
        task->result = 1;
    else
    {
        task->result = 0;
        s->myPick = s->count;
    }
}

// sub_0814E284 @ 0x0814E284
void sub_0814E284(void)
{
    RussianRoulette_DrawText(gUnknown_0879F3A6, 8, 0x1A, 8, 0);
    RussianRoulette_DrawText(gUnknown_0879F3AE, 8, 0x22, 8, 0);
    RussianRoulette_DrawText(gUnknown_0879F3B6, 8, 0x59, 8, 0);
    RussianRoulette_DrawText(gUnknown_0879F3BC, 8, 0x65, 8, 0);
}

/* Mode 0: reset; else the two-way choice of sub_0814DD2C, result2 = the answer. */
// sub_0814E2DC @ 0x0814E2DC
void sub_0814E2DC(struct C14aTask *task, s32 mode)
{
    struct C14aRoulette *s = GR;

    task->result = 0;
    task->result2 = 0;
    if (mode == 0)
    {
        s->side = 0;
        return;
    }
    if (gKeysNew & 1)
    {
        Sound_Play(0x65);
        task->result = 1;
        if ((task->result2 = s->side) == 1)
            s->myPick = 0;
    }
    else if (gRepeatedKeys & 0x40)
    {
        Sound_Play(0x64);
        if (s->side != 0)
            s->side--;
        else
            s->side = 1;
    }
    else if (gRepeatedKeys & 0x80)
    {
        Sound_Play(0x64);
        if (s->side != 1)
            s->side++;
        else
            s->side = 0;
    }
    RussianRoulette_SetSlot(11, 1, 0, s->side * 12 + 0x56);
}

// sub_0814E3A8 @ 0x0814E3A8
void sub_0814E3A8(void)
{
    struct C14aRoulette *s = GR;
    u16 x = 8;
    u16 i, y, id;
    u8 name[8];

    Name_Encode(Demon_GetRecord(s->theirs[s->theirPick]) + 0x22, name);
    RussianRoulette_DrawText(name, 8, 0x1A, 8, 0);
    y = 0x28;
    for (i = 0; i < 12; i++)
    {
        id = s->mine[i];
        if (id != 0xFFFF)
        {
            Name_Encode(Demon_GetRecord(id) + 0x22, name);
            RussianRoulette_DrawText(name, x, y, 8, 0);
        }
        y += 9;
    }
}

/* Settles the bet: mode 0 the player's demon is released, else the opponent's demon joins
   the stock in its place. */
// RussianRoulette_SettleBet @ 0x0814E438
void RussianRoulette_SettleBet(u32 task, s32 mode)
{
    struct C14aRoulette *s = GR;
    u16 id;
    struct C14aStockRec *m;

    if (mode == 0)
    {
        Party_Remove(Stock_FindDemon(s->mine[s->myPick])->slot, 1);
        s->mine[s->myPick] = 0xFFFF;
    }
    else
    {
        id = s->theirs[s->theirPick];
        Stock_AddDemon(id);
        s->mine[s->myPick] = id;
        m = Stock_FindByDemonId(id);
        m->unk18 = 0;
        m->status = 0x8000;
    }
}

/* theirs[slot] = the last of the 12 default demons (gUnknown_087A075A) the player does not
   have. */
// sub_0814E4AC @ 0x0814E4AC
void sub_0814E4AC(u32 slot)
{
    struct C14aRoulette *s = GR;
    u32 i, j;
    u8 found;

    for (i = 0; i < 12; i++)
    {
        found = 0;
        for (j = 0; j < s->count; j++)
        {
            if (gUnknown_087A075A[i] == s->mine[j])
            {
                found = 1;
                break;
            }
        }
        if (!found)
            s->theirs[slot] = gUnknown_087A075A[i];
    }
}

/* 1 when id is in the list gUnknown_087A0772 with its flag clear. */
// sub_0814E538 @ 0x0814E538
u32 sub_0814E538(u32 id)
{
    const struct C14aFlagged *p;
    s32 i;

    for (i = 0, p = gUnknown_087A0772; i <= 25; p++, i++)
    {
        if (p->id == id && !Flag_Test(p->flag))
            return 1;
    }
    return 0;
}

/* Decides how the opponent's demon for the player's pick (slot) is derived, trying the chains
   tblA, tblB, tblC = gUnknown_087A045C/055B/065A of the demon id against the party and the
   flagged list: mode[slot] = 0/10/20/30 (see RussianRoulette_MakeOpponentDemons), 2 = fall back to a default demon. */
// sub_0814E568 @ 0x0814E568
#ifdef NONMATCHING
void sub_0814E568(u32 slot)
{
    struct C14aRoulette *s = GR;
    u32 i, j, k;
    u8 v;

    for (i = 0; i < s->count; i++)
    {
        if (i == 0)
            s->mode[slot] = 0;
        v = gUnknown_087A045C[s->mine[slot]];
        if (v == s->mine[i] || (u8)sub_0814E538(v) == 1)
        {
            for (j = 0; j < s->count; j++)
            {
                if (j == 0)
                    s->mode[slot] = 10;
                if (gUnknown_087A055B[s->mine[slot]] == s->mine[j])
                {
                    for (k = 0; k < s->count; k++)
                    {
                        if (k == 0)
                            s->mode[slot] = 20;
                        v = gUnknown_087A065A[s->mine[slot]];
                        if (v == s->mine[k] || (u8)sub_0814E538(v) == 1)
                            goto fail;
                    }
                }
                if ((u8)sub_0814E538(gUnknown_087A055B[s->mine[slot]]) == 1)
                {
                    for (k = 0; k < s->count; k++)
                    {
                        if (k == 0)
                            s->mode[slot] = 30;
                        v = gUnknown_087A045C[gUnknown_087A065A[s->mine[slot]]];
                        if (v == s->mine[k] || (u8)sub_0814E538(v) == 1)
                            goto fail;
                    }
                }
            }
        }
    }
    return;
fail:
    s->mode[slot] = 2;
}
#else
NAKED
void sub_0814E568(u32 slot)
{
    asm_unified(
        ".L0814E568:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x18\n"
        "    str r0, [sp]\n"
        "    ldr r7, .L0814E6A8\n"
        "    movs r0, #0\n"
        "    str r0, [sp, #4]\n"
        "    ldrh r1, [r7, #2]\n"
        "    cmp r0, r1\n"
        "    blo .L0814E584\n"
        "    b .L0814E6DC\n"
        ".L0814E584:\n"
        "    ldr r2, [sp]\n"
        "    lsls r6, r2, #1\n"
        "    ldr r3, [sp, #4]\n"
        "    cmp r3, #0\n"
        "    bne .L0814E596\n"
        "    adds r0, r7, #0\n"
        "    adds r0, #0xb0\n"
        "    adds r0, r0, r6\n"
        "    strh r3, [r0]\n"
        ".L0814E596:\n"
        "    ldr r2, .L0814E6AC\n"
        "    adds r1, r7, #0\n"
        "    adds r1, #0x80\n"
        "    adds r0, r1, r6\n"
        "    ldrh r0, [r0]\n"
        "    adds r0, r0, r2\n"
        "    ldrb r2, [r0]\n"
        "    ldr r3, [sp, #4]\n"
        "    lsls r0, r3, #1\n"
        "    adds r0, r1, r0\n"
        "    mov sl, r1\n"
        "    ldrh r0, [r0]\n"
        "    cmp r2, r0\n"
        "    beq .L0814E5C2\n"
        "    adds r0, r2, #0\n"
        "    bl sub_0814E538\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    beq .L0814E5C2\n"
        "    b .L0814E6CE\n"
        ".L0814E5C2:\n"
        "    movs r0, #0\n"
        "    mov sb, r0\n"
        "    ldrh r1, [r7, #2]\n"
        "    cmp sb, r1\n"
        "    blo .L0814E5CE\n"
        "    b .L0814E6CE\n"
        ".L0814E5CE:\n"
        "    mov r8, sl\n"
        ".L0814E5D0:\n"
        "    mov r2, sb\n"
        "    cmp r2, #0\n"
        "    bne .L0814E5E0\n"
        "    adds r0, r7, #0\n"
        "    adds r0, #0xb0\n"
        "    adds r0, r0, r6\n"
        "    movs r1, #0xa\n"
        "    strh r1, [r0]\n"
        ".L0814E5E0:\n"
        "    mov r3, r8\n"
        "    adds r0, r3, r6\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L0814E6B0\n"
        "    adds r1, r1, r0\n"
        "    mov r2, sb\n"
        "    lsls r0, r2, #1\n"
        "    add r0, r8\n"
        "    ldrb r1, [r1]\n"
        "    ldrh r0, [r0]\n"
        "    cmp r1, r0\n"
        "    bne .L0814E644\n"
        "    movs r5, #0\n"
        "    ldrh r3, [r7, #2]\n"
        "    cmp r5, r3\n"
        "    bhs .L0814E644\n"
        "    adds r1, r7, #0\n"
        "    adds r1, #0xb0\n"
        "    adds r0, r1, r6\n"
        "    str r0, [sp, #0x14]\n"
        "    mov r2, sl\n"
        "    mov r4, sl\n"
        ".L0814E60C:\n"
        "    cmp r5, #0\n"
        "    bne .L0814E616\n"
        "    movs r0, #0x14\n"
        "    ldr r3, [sp, #0x14]\n"
        "    strh r0, [r3]\n"
        ".L0814E616:\n"
        "    adds r0, r2, r6\n"
        "    ldrh r0, [r0]\n"
        "    ldr r3, .L0814E6B4\n"
        "    adds r0, r0, r3\n"
        "    ldrb r0, [r0]\n"
        "    ldrh r3, [r4]\n"
        "    cmp r0, r3\n"
        "    beq .L0814E6A0\n"
        "    str r1, [sp, #8]\n"
        "    str r2, [sp, #0xc]\n"
        "    bl sub_0814E538\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    ldr r1, [sp, #8]\n"
        "    ldr r2, [sp, #0xc]\n"
        "    cmp r0, #1\n"
        "    beq .L0814E6A0\n"
        "    adds r4, #2\n"
        "    adds r5, #1\n"
        "    ldrh r0, [r7, #2]\n"
        "    cmp r5, r0\n"
        "    blo .L0814E60C\n"
        ".L0814E644:\n"
        "    mov r1, sl\n"
        "    adds r0, r1, r6\n"
        "    ldrh r0, [r0]\n"
        "    ldr r2, .L0814E6B0\n"
        "    adds r0, r0, r2\n"
        "    ldrb r0, [r0]\n"
        "    bl sub_0814E538\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bne .L0814E6C2\n"
        "    movs r5, #0\n"
        "    ldrh r3, [r7, #2]\n"
        "    cmp r5, r3\n"
        "    bhs .L0814E6C2\n"
        "    adds r1, r7, #0\n"
        "    adds r1, #0xb0\n"
        "    adds r2, r1, r6\n"
        "    mov r4, r8\n"
        ".L0814E66C:\n"
        "    cmp r5, #0\n"
        "    bne .L0814E674\n"
        "    movs r0, #0x1e\n"
        "    strh r0, [r2]\n"
        ".L0814E674:\n"
        "    mov r3, r8\n"
        "    adds r0, r3, r6\n"
        "    ldrh r0, [r0]\n"
        "    ldr r3, .L0814E6B4\n"
        "    adds r0, r0, r3\n"
        "    ldrb r0, [r0]\n"
        "    ldr r3, .L0814E6AC\n"
        "    adds r0, r0, r3\n"
        "    ldrb r0, [r0]\n"
        "    ldrh r3, [r4]\n"
        "    cmp r0, r3\n"
        "    beq .L0814E6A0\n"
        "    str r1, [sp, #8]\n"
        "    str r2, [sp, #0xc]\n"
        "    bl sub_0814E538\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    ldr r1, [sp, #8]\n"
        "    ldr r2, [sp, #0xc]\n"
        "    cmp r0, #1\n"
        "    bne .L0814E6B8\n"
        ".L0814E6A0:\n"
        "    adds r1, r1, r6\n"
        "    movs r0, #2\n"
        "    strh r0, [r1]\n"
        "    b .L0814E6DC\n"
        ".L0814E6A8: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L0814E6AC: .4byte gUnknown_087A045C\n"
        ".L0814E6B0: .4byte gUnknown_087A055B\n"
        ".L0814E6B4: .4byte gUnknown_087A065A\n"
        ".L0814E6B8:\n"
        "    adds r4, #2\n"
        "    adds r5, #1\n"
        "    ldrh r0, [r7, #2]\n"
        "    cmp r5, r0\n"
        "    blo .L0814E66C\n"
        ".L0814E6C2:\n"
        "    movs r1, #1\n"
        "    add sb, r1\n"
        "    ldrh r2, [r7, #2]\n"
        "    cmp sb, r2\n"
        "    bhs .L0814E6CE\n"
        "    b .L0814E5D0\n"
        ".L0814E6CE:\n"
        "    ldr r3, [sp, #4]\n"
        "    adds r3, #1\n"
        "    str r3, [sp, #4]\n"
        "    ldrh r0, [r7, #2]\n"
        "    cmp r3, r0\n"
        "    bhs .L0814E6DC\n"
        "    b .L0814E584\n"
        ".L0814E6DC:\n"
        "    add sp, #0x18\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

// sub_0814E6EC @ 0x0814E6EC
void sub_0814E6EC(u16 slot)
{
    struct C14aRoulette *s = GR;

    if (slot != s->myPick)
    {
        s->mode[slot] = 0;
        if (gUnknown_087A045C[s->mine[s->myPick]] == s->mine[slot] && s->mode[s->myPick] == 10)
            s->mode[slot] = 10;
        if ((u8)sub_0814E538(gUnknown_087A045C[s->mine[slot]]) == 1)
        {
            if (gUnknown_087A045C[s->mine[s->myPick]] == s->mine[slot])
                s->mode[slot] = 20;
            else
                s->mode[slot] = 10;
        }
    }
}

/* Builds the opponent's demons from the player's: mode 1 the same demon, 0 tblA[id],
   10 tblB[id], 20 tblC[id], 30 tblA[tblC[id]], 2 a default demon. */
// RussianRoulette_MakeOpponentDemons @ 0x0814E798
void RussianRoulette_MakeOpponentDemons(void)
{
    struct C14aRoulette *s = GR;
    u32 i;

    sub_0814E568(s->myPick);
    for (i = 0; i < s->count; i++)
        sub_0814E6EC((u16)i);
    for (i = 0; i < s->count; i++)
    {
        if (s->mode[i] == 2)
            sub_0814E4AC(i);
        else if (s->mode[i] == 1)
            s->theirs[i] = s->mine[i];
        else if (s->mode[i] == 0)
            s->theirs[i] = gUnknown_087A045C[s->mine[i]];
        else if (s->mode[i] == 10)
            s->theirs[i] = gUnknown_087A055B[s->mine[i]];
        else if (s->mode[i] == 20)
            s->theirs[i] = gUnknown_087A065A[s->mine[i]];
        else if (s->mode[i] == 30)
            s->theirs[i] = gUnknown_087A045C[gUnknown_087A065A[s->mine[i]]];
    }
}
