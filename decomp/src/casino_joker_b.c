/* Joker and Stars: main loop, reel rendering and the reel/payline script commands
   (0x08144C0C-0x08145783). */

#include "global.h"
#include "casino.h"

/* Bet (A up, SELECT+A max 8, B down), R spins (or stops), L quits. */
// JokerStars_Update @ 0x08144C0C
void JokerStars_Update(void)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;
    u32 i;

    switch (s->state)
    {
    case 0:
        break;
    case 1:
        Task_Create(gUnknown_0879A304, 0xFFFF);
        s->state = 0;
        break;
    case 2:
    {
        if ((gRepeatedKeys & 1) && s->spinning == 0)
        {
            u32 n = 1;

            if (gUnk_030031D0 & 4)
                n = 8;
            if (s->bet != 8)
            {
                s->bet += n;
                if (s->bet > 8)
                    s->bet = 8;
                s->unk96 = 0;
            }
            Sound_Play(0x160);
        }
        else if ((gRepeatedKeys & 2) && s->spinning == 0)
        {
            if (s->bet != 0)
            {
                s->bet--;
                s->unk96 = 0;
            }
            Sound_Play(0x160);
        }
        else if (gKeysNew & 0x100)
        {
            if (s->spinning == 0)
            {
                if (s->bet != 0 && sub_080C31F0() >= s->bet)
                {
                    Sound_Play(0x15A);
                    sub_081457FC();
                    s->unkA4 = 0;
                    s->unk96 = 0;
                    sub_080C31B4(-s->bet);
                    JokerStars_SetSlot(3, 1, 0, 0);
                }
            }
            else
            {
                Sound_Play(0x15A);
                sub_081457FC();
                s->unkA4 = 0;
                s->unk96 = 0;
                JokerStars_SetSlot(3, 3, 0, 0);
            }
        }
        else if ((gKeysNew & 0x200) && s->slotFrame[0] == 0)
        {
            Sound_Play(0x158);
            JokerStars_Quit();
        }
        if (s->state == 2)
        {
            if (s->spinning == 0)
            {
                if (s->bet != 0 && sub_080C31F0() >= s->bet && s->slotFrame[1] == 0)
                {
                    if (!((gFrameCounter >> 4) & 1))
                        JokerStars_SetSlot(3, 1, 0, 0);
                    else
                        JokerStars_SetSlot(3, 2, 0, 0);
                }
                else
                    JokerStars_SetSlot(3, 1, 0, 0);
            }
            else if (s->slotFrame[1] == 0)
            {
                if (!((gFrameCounter >> 4) & 1))
                    JokerStars_SetSlot(3, 3, 0, 0);
                else
                    JokerStars_SetSlot(3, 4, 0, 0);
            }
            else
                JokerStars_SetSlot(3, 3, 0, 0);
        }
        break;
    }
    }
    if (s->state > 1 && s->state != 3)
        JokerStars_RenderReels();
    for (i = 0; i < 9; i++)
        Sprite_Draw(gUnknown_0879A16C[i], 0, 0, 2, 0, gUnknown_0879A190[i].x, gUnknown_0879A190[i].y);
    if (s->slotFrame[0] != 1)
    {
        JokerStars_DrawSlot(2, 8, 6);
        if (s->state == 3)
        {
            if (!((gFrameCounter >> 3) & 1))
                JokerStars_SetSlot(2, 1, 0, 0);
            else
                JokerStars_SetSlot(2, 2, 0, 0);
        }
    }
    if ((gFrameCounter & 3) == 0)
    {
        if (s->bet != 0)
        {
            if (s->slotFrame[0] == 0)
                s->slotFrame[0] = 4;
            else if (s->slotFrame[0] != 1)
                s->slotFrame[0]--;
        }
        else if (s->slotFrame[0] != 0)
        {
            if (s->slotFrame[0] != 4)
                s->slotFrame[0]++;
            else
                s->slotFrame[0] = 0;
        }
    }
    JokerStars_DrawSlot(0, 7, 4);
    JokerStars_DrawSlot(3, 0xBA, 6);
    JokerStars_DrawSlot(1, 0xBB, 4);
    JokerStars_DrawSlot(5, 7, 0x29);
    JokerStars_DrawSlot(6, 7, 0x36);
    JokerStars_DrawSlot(7, 7, 0x43);
    JokerStars_DrawSlot(8, 7, 0x50);
    JokerStars_DrawSlot(4, 7, 0x5D);
    JokerStars_DrawSlot(10, 6, 0x87);
    JokerStars_DrawSlot(11, 6, 0x93);
    JokerStars_DrawSlot(12, 0x87, 0x7B);
    JokerStars_DrawSlot(13, 0x87, 0x87);
    JokerStars_DrawSlot(9, 0x87, 0x93);
    JokerStars_DrawNumber(s->win, 6, 0xE, 0x1D);
    JokerStars_DrawNumber(sub_080C31F0(), 6, 0xC4, 0x1D);
    JokerStars_DrawPaylines();
    JokerStars_DrawPayTable();
    sub_081451FC();
}

// JokerStars_SetState @ 0x08144FA8
void JokerStars_SetState(u32 unused, u16 value)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;

    s->state = value;
}

// JokerStars_DmaReelTiles @ 0x08144FB4
void JokerStars_DmaReelTiles(void)
{
    DmaSet(3, 0x02005004, 0x06016000, 0x84000800);
}

/* Copies one 32-pixel row of a 4-tile-wide sprite (4 words, 0x20 apart). */
// JokerStars_CopyPixelRow @ 0x08144FD8
void JokerStars_CopyPixelRow(const u32 *src, u32 *dst)
{
    u32 i;

    for (i = 0; i < 4; i++)
    {
        *dst = *src;
        src += 8;
        dst += 8;
    }
}

/* Renders the 25 visible pixel rows of reel `reel` from its strip into the OBJ buffer at
   0x02005004 (the symbol graphics have three palette shades, 0xC00 bytes apart), then
   queues the DMA to OBJ VRAM 0x06016000. */
// JokerStars_RenderReel @ 0x08144FF0
#ifdef NONMATCHING
void JokerStars_RenderReel(u16 reel, s16 px, const u16 *strip)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;
    u32 shade = s->shade[reel] * 0xC00;
    s16 top = px - 2;
    u32 i;
    u32 y;

    if (top < 0)
        top += 480;
    for (i = 0; i < 25; i++)
    {
        y = top + i;
        if (y > 479)
            y -= 480;
        { u16 sym = *(u16 *)((u32)strip + ((y / 20) << 1));
        JokerStars_CopyPixelRow((const u32 *)(gUnknown_0879A52C[sym] + gUnknown_0879A56C[y % 20] + shade + (u32)gUnknown_0879896C),
                     (u32 *)(gUnknown_0879A548[reel] + gUnknown_0879A56C[i] + 0x02005004)); }
    }
    VBlankTask_AddCounted(JokerStars_DmaReelTiles, 1);
}
#else
NAKED
void JokerStars_RenderReel(u16 reel, s16 px, const u16 *strip)
{
    asm_unified(
        ".L08144FF0:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #8\n"
        "    str r2, [sp]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    ldr r0, .L081450B0\n"
        "    lsls r2, r3, #1\n"
        "    adds r0, #0x4c\n"
        "    adds r2, r2, r0\n"
        "    ldrh r2, [r2]\n"
        "    lsls r0, r2, #1\n"
        "    adds r0, r0, r2\n"
        "    lsls r0, r0, #0xa\n"
        "    mov sl, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    ldr r0, .L081450B4\n"
        "    adds r1, r1, r0\n"
        "    lsrs r2, r1, #0x10\n"
        "    asrs r0, r1, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L0814502C\n"
        "    movs r1, #0xf0\n"
        "    lsls r1, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        ".L0814502C:\n"
        "    movs r6, #0\n"
        "    lsls r2, r2, #0x10\n"
        "    mov sb, r2\n"
        "    lsls r1, r3, #2\n"
        "    ldr r7, .L081450B8\n"
        "    ldr r0, .L081450BC\n"
        "    adds r1, r1, r0\n"
        "    mov r8, r1\n"
        "    str r7, [sp, #4]\n"
        ".L0814503E:\n"
        "    mov r3, sb\n"
        "    asrs r0, r3, #0x10\n"
        "    adds r5, r0, r6\n"
        "    ldr r0, .L081450C0\n"
        "    cmp r5, r0\n"
        "    bls .L0814504E\n"
        "    ldr r0, .L081450C4\n"
        "    adds r5, r5, r0\n"
        ".L0814504E:\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #0x14\n"
        "    bl __udivsi3\n"
        "    lsls r0, r0, #1\n"
        "    ldr r1, [sp]\n"
        "    adds r0, r1, r0\n"
        "    ldr r1, .L081450C8\n"
        "    ldrh r4, [r0]\n"
        "    lsls r4, r4, #2\n"
        "    adds r4, r4, r1\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #0x14\n"
        "    bl __umodsi3\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r0, r7\n"
        "    ldr r2, [r4]\n"
        "    ldr r0, [r0]\n"
        "    adds r2, r2, r0\n"
        "    add r2, sl\n"
        "    ldr r0, .L081450CC\n"
        "    adds r2, r2, r0\n"
        "    mov r3, r8\n"
        "    ldr r1, [r3]\n"
        "    ldr r3, [sp, #4]\n"
        "    ldm r3!, {r0}\n"
        "    str r3, [sp, #4]\n"
        "    adds r1, r1, r0\n"
        "    ldr r0, .L081450D0\n"
        "    adds r1, r1, r0\n"
        "    adds r0, r2, #0\n"
        "    bl JokerStars_CopyPixelRow\n"
        "    adds r6, #1\n"
        "    cmp r6, #0x18\n"
        "    bls .L0814503E\n"
        "    ldr r0, .L081450D4\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    add sp, #8\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L081450B0: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L081450B4: .4byte 0xFFFE0000\n"
        ".L081450B8: .4byte gUnknown_0879A56C\n"
        ".L081450BC: .4byte gUnknown_0879A548\n"
        ".L081450C0: .4byte 0x000001DF\n"
        ".L081450C4: .4byte 0xFFFFFE20\n"
        ".L081450C8: .4byte gUnknown_0879A52C\n"
        ".L081450CC: .4byte gUnknown_0879896C\n"
        ".L081450D0: .4byte 0x02005004 @ EWRAM+0x5004\n"
        ".L081450D4: .4byte JokerStars_DmaReelTiles\n"
    );
}
#endif


/* Moves reel `reel` by `speed` (16.16) and wraps it into 0-479. Past the end it is set
   to 480 - pos instead of pos - 480. */
// JokerStars_MoveReel @ 0x081450D8
#ifdef NONMATCHING
void JokerStars_MoveReel(u16 reel, s32 speed)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;
    union JokerPos *p = &s->pos[reel];
    u32 v = p->v + speed;
    s32 hi;
    s32 n;

    p->v = v;
    hi = (s32)v >> 16;
    if (hi < 0)
        n = hi + 480;
    else if (hi > 479)
        n = 480 - hi;
    else
        return;
    p->v = (v & 0xFFFF) | (n << 16);
}
#else
NAKED
void JokerStars_MoveReel(u16 reel, s32 speed)
{
    asm_unified(
        ".L081450D8:\n"
        "    push {r4, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r2, .L081450F8\n"
        "    lsrs r0, r0, #0xe\n"
        "    adds r0, #4\n"
        "    adds r3, r0, r2\n"
        "    ldr r0, [r3]\n"
        "    adds r2, r0, r1\n"
        "    str r2, [r3]\n"
        "    asrs r1, r2, #0x10\n"
        "    cmp r1, #0\n"
        "    bge .L081450FC\n"
        "    movs r4, #0xf0\n"
        "    lsls r4, r4, #1\n"
        "    adds r0, r1, r4\n"
        "    b .L0814510A\n"
        ".L081450F8: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L081450FC:\n"
        "    ldr r0, .L0814511C\n"
        "    cmp r1, r0\n"
        "    ble .L08145114\n"
        "    movs r4, #0xf0\n"
        "    lsls r4, r4, #1\n"
        "    adds r0, r4, #0\n"
        "    subs r0, r0, r1\n"
        ".L0814510A:\n"
        "    ldr r1, .L08145120\n"
        "    ands r2, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    orrs r2, r0\n"
        "    str r2, [r3]\n"
        ".L08145114:\n"
        "    pop {r4}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L0814511C: .4byte 0x000001DF\n"
        ".L08145120: .4byte 0x0000FFFF\n"
    );
}
#endif


/* Draws `count` pay-table sprites for the current bet, 23 pixels apart. */
// sub_08145124 @ 0x08145124
void sub_08145124(u16 x, u16 y, u16 count, const u32 *table)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;
    u32 i;

    table += s->bet * count;
    for (i = 0; i < count; i++)
    {
        Sprite_Draw(gUnknown_0879A928[*table++], 0, 0, 0, 0, x, y);
        x += 23;
    }
}

// JokerStars_DrawPayTable @ 0x08145194
void JokerStars_DrawPayTable(void)
{
    sub_08145124(0x38, 0x78, 1, gUnknown_0879A5EC);
    sub_08145124(0xB, 0x8B, 5, gUnknown_0879A610);
    sub_08145124(0xB, 0x97, 5, gUnknown_0879A6C4);
    sub_08145124(0x8C, 0x7F, 4, gUnknown_0879A778);
    sub_08145124(0x8C, 0x8B, 4, gUnknown_0879A808);
    sub_08145124(0x8C, 0x97, 4, gUnknown_0879A898);
}

// sub_081451FC @ 0x081451FC
void sub_081451FC(void)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;
    u16 x = 0xB4;
    u16 y = 0x61;
    u32 i;

    if (s->unkA4 != 0)
    {
        for (i = 0; i < s->unkA4; i++)
        {
            Sprite_Draw(gUnknown_0879AA24[i], 0, 0, 0, 0, x, y);
            y -= 12;
        }
    }
}

// JokerStars_Quit @ 0x08145260
void JokerStars_Quit(void)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;

    Task_Create(gUnknown_0879AA3C, 0xFFFF);
    s->state = 3;
}

// sub_08145284 @ 0x08145284
void sub_08145284(struct Task *task, s32 speed)
{
    JokerStars_MoveReel(task->data.h[0], speed);
}

/* Symbol under reel `reel`'s window. */
// JokerStars_GetReelSymbol @ 0x08145290
u16 JokerStars_GetReelSymbol(u16 reel)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;
    const u16 *strip = s->strip[reel];
    u32 p = (u32)s->pos[reel].v >> 16;

    return strip[p / 20];
}

/* Stops the task's reel on a random symbol different from the current one. The check
   uses the strip pointer read before a forced strip (0x0879C7C4) is replaced, so after a
   forced spin the "different symbol" test is made against the old strip. */
// sub_081452BC @ 0x081452BC
void sub_081452BC(struct Task *task)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;
    u32 r = (Random_Byte() * 24) >> 8;
    const u16 *strip = s->strip[task->data.h[0]];
    u16 cur = JokerStars_GetReelSymbol(task->data.h[0]);

    if (strip == gUnknown_0879C7C4)
    {
        JokerStars_RandomizeReel(task->data.h[0]);
        cur = JokerStars_GetReelSymbol(task->data.h[0]);
    }
    while (strip[r] == cur)
    {
        r++;
        if (r == 24)
            r = 0;
    }
    s->pos[task->data.h[0]].v = r * 20 << 16;
}

// sub_08145334 @ 0x08145334
void sub_08145334(struct Task *task)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;

    s->tasks[task->data.h[0]] = NULL;
}

/* Kind 5 forces the reel onto the special strip 0x0879C7C4 at symbol 2. */
// sub_08145348 @ 0x08145348
void sub_08145348(struct Task *task)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;
    u16 reel = task->data.h[0];

    if (task->data.sh[1] == 5)
    {
        s->pos[reel].v = 0x280000;
        s->strip[reel] = gUnknown_0879C7C4;
    }
}

/* Starts the stop task of reel `reel` (K&R definition: callers pass -1 unnarrowed). */
// sub_08145378 @ 0x08145378
struct Task *sub_08145378(reel, kind)
    u16 reel;
    u16 kind;
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;
    struct Task *t = Task_Create(gUnknown_0879AA94, 0xFFFF);

    t->data.h[0] = reel;
    t->data.h[1] = kind;
    s->tasks[reel] = t;
    return t;
}

// sub_081453B0 @ 0x081453B0
void sub_081453B0(struct Task *task, u32 reel)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;

    task->result = 0;
    if (s->hl[reel] == 0)
    {
        sub_08145378((u16)reel, -1);
        task->result = 1;
    }
}

// sub_081453E4 @ 0x081453E4
void sub_081453E4(struct Task *task, u32 reel)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;

    task->result = 0;
    if (s->hl[reel] == 0)
    {
        s->tasks[reel]->wait = 1;
        task->result = 1;
    }
}

/* Script condition: all reel stop tasks finished. */
// sub_08145418 @ 0x08145418
void sub_08145418(struct Task *task)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;
    u32 i;

    task->result = 0;
    for (i = 0; i < 9; i++)
    {
        if (s->tasks[i] != NULL)
            return;
    }
    task->result = 1;
}

/* Script condition: payline `line` (1-8) is bet and wins. */
// sub_08145440 @ 0x08145440
void sub_08145440(struct Task *task, u32 line)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;

    task->result = 0;
    if (s->bet >= line && JokerStars_CheckLine(gUnknown_0879AC18[line][0], gUnknown_0879AC18[line][1], gUnknown_0879AC18[line][2]) >= 0)
        task->result = 1;
}

/* Sets the palette shade of the three reels of payline `line`. */
// sub_08145488 @ 0x08145488
void sub_08145488(struct Task *task, u32 line, u32 shade)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;
    u32 a = gUnknown_0879AC18[line][0] - 1;
    u32 b = gUnknown_0879AC18[line][1] - 1;
    u32 c = gUnknown_0879AC18[line][2] - 1;

    s->shade[a] = shade;
    s->shade[b] = shade;
    s->shade[c] = shade;
}

/* Number of stars (symbol 6) showing. */
// JokerStars_CountStars @ 0x081454CC
u32 JokerStars_CountStars(void)
{
    u32 n = 0;
    u32 i;

    for (i = 0; i < 9; i++)
    {
        if (JokerStars_GetReelSymbol(i) == 6)
            n++;
    }
    return n;
}

// sub_081454F4 @ 0x081454F4
#ifdef NONMATCHING
void sub_081454F4(struct Task *task)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;
    u32 n;

    task->result = 0;
    n = JokerStars_CountStars();
    if (n > 3)
    {
        s->starsLeft = n;
        s->unkA4 = 0;
        s->stars = n;
        task->result = 1;
    }
}
#else
NAKED
void sub_081454F4(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, lr}\n"
        "    adds r5, r0, #0\n"
        "    ldr r4, .L08145528\n"
        "    movs r2, #0\n"
        "    strh r2, [r5, #0x1c]\n"
        "    bl JokerStars_CountStars\n"
        "    adds r2, r0, #0\n"
        "    cmp r2, #3\n"
        "    bls .L08145520\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0xa6\n"
        "    strh r2, [r0]\n"
        "    adds r1, r4, #0\n"
        "    adds r1, #0xa4\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0xa8\n"
        "    strh r2, [r0]\n"
        "    movs r0, #1\n"
        "    strh r0, [r5, #0x1c]\n"
        ".L08145520:\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L08145528: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
    );
}
#endif


// sub_0814552C @ 0x0814552C
void sub_0814552C(struct Task *task)
{
    if (JokerStars_CountStars() > 3)
        task->result = 1;
    else
        task->result = 0;
}

// sub_08145548 @ 0x08145548
void sub_08145548(struct Task *task)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;

    task->result = 0;
    s->unkA4++;
    if (--s->starsLeft <= 3)
        task->result = 1;
}

// sub_08145578 @ 0x08145578
void sub_08145578(void)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;
    u32 i;

    for (i = 0; i < 9; i++)
        s->hl[i] = 0;
}

// sub_08145594 @ 0x08145594
void sub_08145594(struct Task *task, u32 spinning)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;

    task->result = 0;
    if (s->spinning != spinning)
    {
        s->spinning = spinning;
        task->result = 1;
        if (spinning == 0)
            sub_08145578();
    }
}

// sub_081455C0 @ 0x081455C0
void sub_081455C0(u16 sym)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;
    u32 i;

    for (i = 0; i < 9; i++)
    {
        if (JokerStars_GetReelSymbol(i) == sym)
            s->hl[i] = 1;
    }
}

/* Star bonus by star count: 4 highlights the stars, 5 the jokers (symbol 1); 6-8 respin
   the reels outside a fixed shape (6: all but the centre, 7: the edges, 8: the corners),
   step 0 starts the forced stops, 1 stops them, 2 highlights the shape. */
// sub_081455F8 @ 0x081455F8
void sub_081455F8(struct Task *task, u32 step)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;

    task->result = 0;
    sub_08145578();
    switch (s->stars)
    {
    case 4:
        sub_081455C0(6);
        break;
    case 5:
        sub_081455C0(1);
        break;
    case 6:
        if (step == 0)
        {
            s->hl[2] = 1;
            s->hl[1] = 1;
            s->hl[0] = 1;
            s->hl[5] = 1;
            s->hl[3] = 1;
            s->hl[8] = 1;
            s->hl[7] = 1;
            s->hl[6] = 1;
            sub_08145378(4, 5);
            task->result = 1;
        }
        else if (step == 1)
            sub_081453E4(task, 4);
        else
            s->hl[4] = 1;
        break;
    case 7:
        if (step == 0)
        {
            s->hl[2] = 1;
            s->hl[0] = 1;
            s->hl[4] = 1;
            s->hl[8] = 1;
            s->hl[6] = 1;
            sub_08145378(1, 5);
            sub_08145378(3, 5);
            sub_08145378(5, 5);
            sub_08145378(7, 5);
            task->result = 1;
        }
        else if (step == 1)
        {
            sub_081453E4(task, 1);
            sub_081453E4(task, 3);
            sub_081453E4(task, 5);
            sub_081453E4(task, 7);
        }
        else
        {
            s->hl[1] = 1;
            s->hl[3] = 1;
            s->hl[5] = 1;
            s->hl[7] = 1;
        }
        break;
    case 8:
        if (step == 0)
        {
            s->hl[1] = 1;
            s->hl[5] = 1;
            s->hl[4] = 1;
            s->hl[3] = 1;
            s->hl[7] = 1;
            sub_08145378(0, 5);
            sub_08145378(2, 5);
            sub_08145378(6, 5);
            sub_08145378(8, 5);
            task->result = 1;
        }
        else if (step == 1)
        {
            sub_081453E4(task, 0);
            sub_081453E4(task, 2);
            sub_081453E4(task, 6);
            sub_081453E4(task, 8);
        }
        else
        {
            s->hl[0] = 1;
            s->hl[2] = 1;
            s->hl[6] = 1;
            s->hl[8] = 1;
        }
        break;
    case 9:
        break;
    }
}
