/* Joker and Stars: line checks, win counting, star bonus and coin payout (0x08145784-0x08145E43). */

#include "global.h"
#include "casino2.h"

// sub_08145784 @ 0x08145784
void sub_08145784(void)
{
    gCasino->unk96 = 1;
}

/* Moves coins from the play counter back to the purse, faster while A is held. */
// JokerStars_PayOutCoins @ 0x08145794
void JokerStars_PayOutCoins(struct Task *task, u32 arg)
{
    struct CasinoState *s = gCasino;
    s32 n;

    task->result = 0;
    if (arg == 0)
    {
        if (s->unkA0 != 0)
            task->result = 1;
    }
    else
    {
        n = 1;
        if (gRepeatedKeys & 1)
            n = Casino_GetCountStep(s->unkA0);
        Sound_Play(0x159);
        s->unkA0 -= n;
        sub_080C31B4(n);
        if (s->unkA0 == 0)
            task->result = 1;
    }
}

// sub_081457FC @ 0x081457FC
void sub_081457FC(void)
{
    struct CasinoState *s = gCasino;

    Task_Create(gUnknown_0879AC84, 0xFFFF);
    s->unk00 = 4;
}

// sub_08145820 @ 0x08145820
void sub_08145820(struct Task *task)
{
    struct C145TaskData *d = (struct C145TaskData *)&task->data;
    u16 a, b, c;
    u16 r;

    a = JokerStars_GetReelSymbol(gUnknown_0879AC18[task->data.h[0]].cell[0] - 1);
    b = JokerStars_GetReelSymbol(gUnknown_0879AC18[task->data.h[0]].cell[1] - 1);
    c = JokerStars_GetReelSymbol(gUnknown_0879AC18[task->data.h[0]].cell[2] - 1);
    if (a != 5)
        r = a;
    else if (b != 5)
        r = b;
    else if (c != 5)
        r = c;
    d->w8 = gUnknown_0879B53C[r];
    d->h2 = r;
}

// sub_081458C0 @ 0x081458C0
void sub_081458C0(struct Task *task)
{
    struct CasinoState *s = gCasino;
    struct C145TaskData *d = (struct C145TaskData *)&task->data;
    s32 n = 1;

    if (gRepeatedKeys & 1)
        n = Casino_GetCountStep(d->w8);
    d->w8 -= n;
    s->unkA0 += n;
    if (d->w8 != 0)
        task->result = 0;
    else
        task->result = 1;
}

// sub_0814590C @ 0x0814590C
void sub_0814590C(struct Task *task)
{
    struct C145TaskData *d = (struct C145TaskData *)&task->data;

    sub_08145488(task, task->data.h[0], 0);
    JokerStars_SetSlot(d->h2 + 4, 0, 0, 0);
}

// sub_08145934 @ 0x08145934
void sub_08145934(struct Task *task)
{
    struct C145TaskData *d = (struct C145TaskData *)&task->data;

    if (((gFrameCounter >> 2) & 1) == 0)
    {
        sub_08145488(task, task->data.h[0], 1);
        Sound_Play(0x15E);
        JokerStars_SetSlot(d->h2 + 4, 1, 0, 0);
    }
    else
    {
        sub_08145488(task, task->data.h[0], 0);
        JokerStars_SetSlot(d->h2 + 4, 0, 0, 0);
    }
}

// sub_08145998 @ 0x08145998
void sub_08145998(struct Task *task, u32 arg)
{
    Task_Create(gUnknown_0879B550, task->id)->data.h[0] = arg;
}

// sub_081459B4 @ 0x081459B4
#ifdef NONMATCHING
void sub_081459B4(struct Task *task)
{
    struct CasinoState *s = gCasino;
    struct C145TaskData *d = (struct C145TaskData *)&task->data;
    const u32 (*t4)[4];
    const u32 (*t5)[5];
    u32 v;
    u32 row, col;

    if (task->data.h[0] == 9)
    {
        v = gUnknown_0879B5A0[s->unk98];
    }
    else
    {
        switch (d->h2)
        {
        case 0:
            t4 = gUnknown_0879B804;
            goto four;
        case 3:
            t4 = gUnknown_0879B704;
            goto four;
        case 4:
            t4 = gUnknown_0879B784;
        four:
            col = d->h0 - 5;
            row = s->unk98 - 1;
            v = *(const u32 *)(col * 4 + row * 16 + (u32)t4);
            break;
        case 1:
            t5 = gUnknown_0879B5C4;
            goto five;
        case 2:
            t5 = gUnknown_0879B664;
        five:
            col = d->h0 - 4;
            row = s->unk98 - 1;
            v = ((const u32 *)t5)[row * 5 + col];
            break;
        }
    }
    d->w8 = v;
}
#else
NAKED
void sub_081459B4(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, lr}\n"
        "    ldr r5, .L081459D0\n"
        "    adds r4, r0, #0\n"
        "    adds r4, #0x24\n"
        "    ldrh r0, [r0, #0x24]\n"
        "    cmp r0, #9\n"
        "    bne .L081459D8\n"
        "    ldr r1, .L081459D4\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x98\n"
        "    ldr r0, [r0]\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r0, r1\n"
        "    b .L08145A50\n"
        ".L081459D0: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L081459D4: .4byte gUnknown_0879B5A0\n"
        ".L081459D8:\n"
        "    ldrh r0, [r4, #2]\n"
        "    cmp r0, #4\n"
        "    bhi .L08145A52\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L081459E8\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        ".L081459E8: .4byte gUnknown_081459EC\n"
        "    .global gUnknown_081459EC\n"
        "gUnknown_081459EC:\n"
        ".L081459EC: @ jump table\n"
        "    .4byte .L08145A00\n"
        "    .4byte .L08145A30\n"
        "    .4byte .L08145A38\n"
        "    .4byte .L08145A08\n"
        "    .4byte .L08145A10\n"
        ".L08145A00:\n"
        "    ldr r2, .L08145A04\n"
        "    b .L08145A12\n"
        ".L08145A04: .4byte gUnknown_0879B804\n"
        ".L08145A08:\n"
        "    ldr r2, .L08145A0C\n"
        "    b .L08145A12\n"
        ".L08145A0C: .4byte gUnknown_0879B704\n"
        ".L08145A10:\n"
        "    ldr r2, .L08145A2C\n"
        ".L08145A12:\n"
        "    ldrh r1, [r4]\n"
        "    subs r1, #5\n"
        "    lsls r1, r1, #2\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x98\n"
        "    ldr r0, [r0]\n"
        "    subs r0, #1\n"
        "    lsls r0, r0, #4\n"
        "    adds r1, r1, r0\n"
        "    adds r1, r1, r2\n"
        "    ldr r1, [r1]\n"
        "    b .L08145A52\n"
        "    .byte 0x00, 0x00\n"
        ".L08145A2C: .4byte gUnknown_0879B784\n"
        ".L08145A30:\n"
        "    ldr r3, .L08145A34\n"
        "    b .L08145A3A\n"
        ".L08145A34: .4byte gUnknown_0879B5C4\n"
        ".L08145A38:\n"
        "    ldr r3, .L08145A5C\n"
        ".L08145A3A:\n"
        "    ldrh r2, [r4]\n"
        "    subs r2, #4\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x98\n"
        "    ldr r1, [r0]\n"
        "    subs r1, #1\n"
        "    lsls r0, r1, #2\n"
        "    adds r0, r0, r1\n"
        "    adds r0, r0, r2\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r0, r3\n"
        ".L08145A50:\n"
        "    ldr r1, [r0]\n"
        ".L08145A52:\n"
        "    str r1, [r4, #8]\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L08145A5C: .4byte gUnknown_0879B664\n"
    );
}
#endif

// sub_08145A60 @ 0x08145A60
void sub_08145A60(struct Task *task)
{
    struct CasinoState *s = gCasino;
    struct C145TaskData *d = (struct C145TaskData *)&task->data;
    s32 n = 1;

    if (gRepeatedKeys & 1)
        n = Casino_GetCountStep(d->w8);
    d->w8 -= n;
    s->unkA0 += n;
    if (d->w8 != 0)
        task->result = 0;
    else
        task->result = 1;
}

// sub_08145AAC @ 0x08145AAC
void sub_08145AAC(struct Task *task)
{
    struct CasinoState *s = gCasino;
    struct C145TaskData *d = (struct C145TaskData *)&task->data;
    u32 i;
    u16 *p;

    for (i = 0, p = s->lit; i < 9; p++, i++)
    {
        if (JokerStars_GetReelSymbol(i) == d->h2)
        {
            if (((gFrameCounter >> 2) & 1) == 0)
                *p = 1;
            else
                *p = 0;
        }
    }
    if (((gFrameCounter >> 2) & 1) == 0)
        JokerStars_SetSlot(d->h2 + 9, 1, 0, 0);
    else
        JokerStars_SetSlot(d->h2 + 9, 0, 0, 0);
}

// sub_08145B30 @ 0x08145B30
void sub_08145B30(struct Task *task)
{
    struct CasinoState *s = gCasino;
    struct C145TaskData *d = (struct C145TaskData *)&task->data;
    u32 i;
    u16 *p;

    for (i = 0; i < 9; i++)
        s->lit[i] = 0;
    JokerStars_SetSlot(d->h2 + 9, 0, 0, 0);
}

// sub_08145B60 @ 0x08145B60
void sub_08145B60(struct Task *task, u32 sym)
{
    u32 count = 0;
    u32 i;
    struct C145TaskData *d;

    task->result = 0;
    for (i = 0; i < 9; i++)
    {
        if (JokerStars_GetReelSymbol(i) == sym)
            count++;
    }
    switch (sym)
    {
    case 0:
    case 3:
    case 4:
        if (count > 4)
            task->result = 1;
        break;
    case 1:
    case 2:
        if (count > 3)
            task->result = 1;
        break;
    }
    if (task->result == 1)
    {
        d = (struct C145TaskData *)&Task_Create(gUnknown_0879B884, task->id)->data;
        d->h2 = sym;
        d->h0 = count;
    }
}

// sub_08145BD8 @ 0x08145BD8
void sub_08145BD8(struct Task *task)
{
    task->data.w[2] = 200;
}

// sub_08145BE0 @ 0x08145BE0
void sub_08145BE0(struct Task *task)
{
    struct CasinoState *s = gCasino;
    struct C145TaskData *d = (struct C145TaskData *)&task->data;
    s32 n = 1;

    if (gRepeatedKeys & 1)
        n = Casino_GetCountStep(d->w8);
    d->w8 -= n;
    s->unkA0 += n;
    if (d->w8 != 0)
        task->result = 0;
    else
        task->result = 1;
}

// sub_08145C2C @ 0x08145C2C
void sub_08145C2C(struct Task *task)
{
    struct CasinoState *s = gCasino;
    struct C145TaskData *d = (struct C145TaskData *)&task->data;
    u32 i;
    u16 *p;

    for (i = 0, p = s->lit; i < 9; p++, i++)
    {
        if (JokerStars_GetReelSymbol(i) == d->h2)
        {
            if (((gFrameCounter >> 2) & 1) == 0)
                *p = 1;
            else
                *p = 0;
        }
    }
}

// sub_08145C7C @ 0x08145C7C
void sub_08145C7C(void)
{
    struct CasinoState *s = gCasino;
    u32 i;

    for (i = 0; i < 9; i++)
        s->lit[i] = 0;
}

// JokerStars_CheckAllStars @ 0x08145C98
void JokerStars_CheckAllStars(struct Task *task)
{
    u32 n = JokerStars_CountStars();
    struct Task *t;

    task->result = 0;
    if (n == 9)
    {
        t = Task_Create(gUnknown_0879B8D4, task->id);
        t->data.h[1] = 6;
        t->data.h[0] = n;
        task->result = 1;
    }
}

/* Checks one line of three cells (1-based). Symbol 6 never wins, symbol 5 is wild.
   Returns the winning symbol and marks the cells, or -1. */
// JokerStars_CheckLine @ 0x08145CC8
s32 JokerStars_CheckLine(s32 c0, s32 c1, s32 c2)
{
    struct CasinoState *s = gCasino;

    s->lineSym[0] = s->lineOrig[0] = JokerStars_GetReelSymbol(c0 - 1);
    s->lineSym[1] = s->lineOrig[1] = JokerStars_GetReelSymbol(c1 - 1);
    s->lineSym[2] = s->lineOrig[2] = JokerStars_GetReelSymbol(c2 - 1);
    if (s->lineSym[0] == 6 || s->lineSym[1] == 6 || s->lineSym[2] == 6)
        return -1;
    if (s->lineSym[0] == 5 || s->lineSym[1] == 5 || s->lineSym[2] == 5)
    {
        if (s->lineSym[0] != 5)
            s->wild = s->lineSym[0];
        else if (s->lineSym[1] != 5)
            s->wild = s->lineSym[1];
        else if (s->lineSym[2] != 5)
            s->wild = s->lineSym[2];
        if (s->lineSym[0] == 5)
            s->lineSym[0] = s->wild;
        if (s->lineSym[1] == 5)
            s->lineSym[1] = s->wild;
        if (s->lineSym[2] == 5)
            s->lineSym[2] = s->wild;
        if (s->lineSym[0] == s->lineSym[1] && s->lineSym[0] == s->lineSym[2])
        {
            s->cellWin[c0 - 1] = s->lineOrig[0];
            s->cellWin[c1 - 1] = s->lineOrig[1];
            s->cellWin[c2 - 1] = s->lineOrig[2];
            return s->wild;
        }
    }
    else if (s->lineSym[0] == s->lineSym[1] && s->lineSym[1] == s->lineSym[2])
    {
        s->cellWin[c0 - 1] = s->lineOrig[0];
        s->cellWin[c1 - 1] = s->lineOrig[1];
        s->cellWin[c2 - 1] = s->lineOrig[2];
        return s->lineSym[0];
    }
    return -1;
}
