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
void sub_081459B4(struct Task *task)
{
    struct CasinoState *s = gCasino;
    struct C145TaskData *d = (struct C145TaskData *)&task->data;
    u32 v;

    if (task->data.h[0] == 9)
    {
        v = gUnknown_0879B5A0[s->unk98];
    }
    else
    {
        switch (d->h2)
        {
        case 0:
            v = gUnknown_0879B804[s->unk98 - 1][d->h0 - 5];
            break;
        case 3:
            v = gUnknown_0879B704[s->unk98 - 1][d->h0 - 5];
            break;
        case 4:
            v = gUnknown_0879B784[s->unk98 - 1][d->h0 - 5];
            break;
        case 1:
            v = gUnknown_0879B5C4[s->unk98 - 1][d->h0 - 4];
            break;
        case 2:
            v = gUnknown_0879B664[s->unk98 - 1][d->h0 - 4];
            break;
        }
    }
    d->w8 = v;
}

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
