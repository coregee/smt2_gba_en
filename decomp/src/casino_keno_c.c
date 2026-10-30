/* 8x8 number game: draw steps and payout (0x081490E4-). */

#include "global.h"
#include "casino2.h"

/* Moves sprite 4 vertically by `step` towards `target`; TRUE once it is there. */
// sub_081490E4 @ 0x081490E4
u32 sub_081490E4(u32 step, u32 target)
{
    struct C145Grid *s = gGrid;
    u32 done;
    u16 *y = &s->sprY[4];

    done = FALSE;
    if (*y > target)
    {
        *y -= step;
        if (*y > target)
            goto out;
    }
    else
    {
        *y += step;
        if (*y < target)
            goto out;
    }
    *y = target;
    done = TRUE;
out:
    return done;
}

// sub_08149120 @ 0x08149120
void sub_08149120(struct Task *task, u32 step, u32 target)
{
    task->result = sub_081490E4(step, target);
}

// sub_08149134 @ 0x08149134
void sub_08149134(struct Task *task, u32 step)
{
    struct C145Grid *s = gGrid;
    /* gUnknown_0879CEBC[marked][hits], as byte-offset arithmetic (what matches) */
    u32 row = s->marked * sizeof(gUnknown_0879CEBC[0]);
    u32 col = (u32)&gUnknown_0879CEBC[0][s->hits];

    sub_08149120(task, step, *(const u16 *)(row + col));
}

// sub_0814916C @ 0x0814916C
void sub_0814916C(u32 unused, u32 state)
{
    struct C145Grid *s = gGrid;

    s->state = state;
    if (state == 2)
        s->menu &= 0x7FFF;
}

// sub_0814918C @ 0x0814918C
void sub_0814918C(u32 unused, const void *src)
{
    LZ77UnCompWram(src, (void *)0x0200AFC8);
    Palette_CopyWithEffect(3, (void *)0x0200AFC8, (void *)0x03002BB0, 0x200, 0x20);
}

/* Draws one number that has not come up yet. */
// Keno_DrawNumber @ 0x081491BC
#ifdef NONMATCHING
void Keno_DrawNumber(struct Task *task)
{
    struct C145Grid *s = gGrid;
    u32 r;
    u32 *hits;

    task->result = 0;
    hits = &s->hits;
retry:
    r = Random_Byte() & 0x3F;
    if (s->cell[r] != 0)
        goto retry;
    s->cell[r] = 1;
    if (s->mark[r] & 0x8000)
    {
        (*hits)++;
        task->result = 1;
        s->lastHit = r;
        Sound_Play(0x15D);
    }
    s->drawn++;
}
#else
NAKED
void Keno_DrawNumber(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    adds r6, r0, #0\n"
        "    ldr r4, .L08149224\n"
        "    movs r0, #0\n"
        "    strh r0, [r6, #0x1c]\n"
        "    movs r0, #0xc6\n"
        "    lsls r0, r0, #1\n"
        "    adds r7, r4, r0\n"
        ".L081491CC:\n"
        "    bl Random_Byte\n"
        "    adds r2, r0, #0\n"
        "    movs r0, #0x3f\n"
        "    ands r2, r0\n"
        "    lsls r3, r2, #1\n"
        "    movs r1, #0x81\n"
        "    lsls r1, r1, #1\n"
        "    adds r0, r4, r1\n"
        "    adds r1, r0, r3\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #0\n"
        "    bne .L081491CC\n"
        "    movs r5, #1\n"
        "    strh r5, [r1]\n"
        "    adds r0, r4, #4\n"
        "    adds r0, r0, r3\n"
        "    ldrh r0, [r0]\n"
        "    movs r3, #0x80\n"
        "    lsls r3, r3, #8\n"
        "    adds r1, r3, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08149210\n"
        "    ldr r0, [r7]\n"
        "    adds r0, #1\n"
        "    str r0, [r7]\n"
        "    strh r5, [r6, #0x1c]\n"
        "    ldr r1, .L08149228\n"
        "    adds r0, r4, r1\n"
        "    strb r2, [r0]\n"
        "    ldr r0, .L0814922C\n"
        "    bl Sound_Play\n"
        ".L08149210:\n"
        "    movs r3, #0xc4\n"
        "    lsls r3, r3, #1\n"
        "    adds r1, r4, r3\n"
        "    ldr r0, [r1]\n"
        "    adds r0, #1\n"
        "    str r0, [r1]\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L08149224: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L08149228: .4byte 0x00000221\n"
        ".L0814922C: .4byte 0x0000015D\n"
    );
}
#endif

// sub_08149230 @ 0x08149230
void sub_08149230(void)
{
    u8 c = gGrid->lastHit;
    u16 x;
    u16 y;

    x = (c & 7) * 15 + 8;
    y = (c / 8) * 11 + 0x27;
    if (c > 31)
        y += 0x1B;
    Sprite_Draw(gUnknown_081513A4, 0, 0, 0, 0, x, y);
}

/* Payout = bet x gUnknown_0879D338[numbers marked][hits]. */
// Keno_ComputePayout @ 0x08149280
void Keno_ComputePayout(struct Task *task)
{
    struct C145Grid *s = gGrid;
    struct C145TaskData *d = (struct C145TaskData *)&task->data;
    const u32 *row = gUnknown_0879D338[s->marked];
    u32 r;

    s->payout = s->bet * row[s->hits];
    r = row[s->hits];
    if (r != 0)
        task->result = 1;
    else
        task->result = 0;
    d->h0 = 0xF0;
    d->h2 = 0x5A;
}

// sub_081492DC @ 0x081492DC
void sub_081492DC(struct Task *task)
{
    Sprite_Draw(gUnknown_081519E8, 0, 0, 0, 0, task->data.h[0], task->data.h[1]);
}

// sub_08149304 @ 0x08149304
void sub_08149304(struct Task *task)
{
    Sprite_Draw(gUnknown_081519D0, 0, 0, 0, 0, task->data.h[0], task->data.h[1]);
}

// sub_0814932C @ 0x0814932C
void sub_0814932C(struct Task *task, u32 n)
{
    task->data.h[0] -= n;
}

/* Shows the payout as six digits. */
// sub_08149334 @ 0x08149334
#ifdef NONMATCHING
void sub_08149334(void)
{
    u16 x = 0x4C;
    u16 y0 = 0x44;
    u16 y;
    u32 n;
    u8 *d;
    u8 i;
    u32 k;

    Sprite_Draw(gUnknown_081519B4, 0, 0, 0, 0, x, y0);
    n = 6;
    d = NumberToDigits(gGrid->payout);
    i = n - 1;
    y = 0x4A;
    for (k = 0; k < n; k++)
    {
        Sprite_Draw(gUnknown_0879CE24[d[i]], 0, 0, 0, 0, x + 0x14, y);
        i--;
        x += 8;
    }
    gGrid->state = 5;
}
#else
NAKED
void sub_08149334(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0xc\n"
        "    movs r4, #0x4c\n"
        "    movs r2, #0x44\n"
        "    ldr r0, .L081493C8\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    str r4, [sp, #4]\n"
        "    str r2, [sp, #8]\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    movs r0, #6\n"
        "    mov sl, r0\n"
        "    ldr r1, .L081493CC\n"
        "    movs r2, #0x89\n"
        "    lsls r2, r2, #2\n"
        "    adds r0, r1, r2\n"
        "    ldr r0, [r0]\n"
        "    bl NumberToDigits\n"
        "    adds r7, r0, #0\n"
        "    movs r5, #5\n"
        "    movs r6, #0\n"
        "    ldr r0, .L081493D0\n"
        "    mov sb, r0\n"
        "    movs r1, #0x4a\n"
        "    mov r8, r1\n"
        ".L08149376:\n"
        "    adds r0, r7, r5\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #2\n"
        "    add r0, sb\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    adds r1, r4, #0\n"
        "    adds r1, #0x14\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #4]\n"
        "    mov r2, r8\n"
        "    str r2, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    subs r0, r5, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r5, r0, #0x18\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #8\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    adds r6, #1\n"
        "    cmp r6, sl\n"
        "    blo .L08149376\n"
        "    movs r0, #5\n"
        "    ldr r1, .L081493CC\n"
        "    strh r0, [r1]\n"
        "    add sp, #0xc\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L081493C8: .4byte gUnknown_081519B4\n"
        ".L081493CC: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L081493D0: .4byte gUnknown_0879CE24\n"
    );
}
#endif

/* Coins moved per frame while A is held: the largest power of ten not above n. */
// Casino_GetCountStep @ 0x081493D4
u32 Casino_GetCountStep(u32 n)
{
    u32 step = 10000000;
    u32 i;

    if (n == 0)
        return 0;
    for (i = 0; i < 8; i++)
    {
        if (n / step != 0)
            return step;
        step /= 10;
    }
    return step;
}

/* Pays out up to 999999 coins. */
// Keno_PayOut @ 0x08149410
void Keno_PayOut(struct Task *task)
{
    struct C145Grid *s = gGrid;
    u32 n = 1;

    task->result = 0;
    if (s->coins == 999999)
    {
        task->result = n;
        return;
    }
    if (gRepeatedKeys & 1)
        n = Casino_GetCountStep(s->payout);
    if (s->payout < n)
        n = s->payout;
    s->payout -= n;
    s->coins += n;
    if (s->coins > 999999)
        s->coins = 999999;
    if (s->payout == 0 || s->coins == 999999)
        task->result = 1;
}

// sub_08149494 @ 0x08149494
void sub_08149494(void)
{
    struct C145Grid *s = gGrid;

    s->bet = 0;
    sub_080C31FC(s->coins);
}

// sub_081494B8 @ 0x081494B8
void sub_081494B8(void)
{
    gGrid->unk228 = 30;
}

// sub_081494CC @ 0x081494CC
void sub_081494CC(struct Task *task)
{
    struct C145Grid *s = gGrid;
    u32 n = 1;

    task->result = 0;
    if (gUnk_030031D0 & 1)
        n = 3;
    if (s->unk228 < n)
        n = s->unk228;
    s->unk228 -= n;
    if (s->unk228 == 0)
        task->result = 1;
}

/* Starts a new round: clears the drawn numbers and the hit counts, keeps the marks. */
// Keno_StartRound @ 0x08149510
void Keno_StartRound(void)
{
    struct C145Grid *s = gGrid;
    u32 i;

    Task_Create(gUnknown_0879D6AC, 0xFFFF);
    s->state = 0;
    for (i = 0; i < 64; i++)
    {
        s->cell[i] = 0;
        s->mark[i] &= 0x8000;
    }
    s->drawn = 0;
    s->hits = 0;
    gDispRegs = 0xF0;
    s->menu |= 0x8000;
}

// sub_08149580 @ 0x08149580
void sub_08149580(void)
{
    struct C145Grid *s = gGrid;

    s->fade = PalFade_FadeRangeToWhite(0x140, 0x80, 2);
    gUnk_03000040 = 0;
}

// sub_081495AC @ 0x081495AC
void sub_081495AC(void)
{
    struct C145Grid *s = gGrid;
    u8 *buf = (u8 *)0x0200AFC8;

    LZ77UnCompWram(gUnknown_087B59DC, buf);
    Palette_CopyWithEffect(3, buf + 0x80, (void *)0x03002C30, 0x100, 0x20);
    s->fade = PalFade_FadeRangeWithDuration(0x140, 0x80, 2, 0x20);
    gUnk_03000040 = 0;
}

// sub_08149608 @ 0x08149608
void sub_08149608(struct Task *task)
{
    if (PalFade_IsActive(gGrid->fade) == 0)
        task->result = 1;
    else
        task->result = 0;
}

// sub_08149634 @ 0x08149634
void sub_08149634(void)
{
    gDispRegs = 0;
}

// sub_08149640 @ 0x08149640
void sub_08149640(void)
{
    struct C145Grid *s = gGrid;

    Sound_Play(0x158);
    Task_Create(gUnknown_0879DA00, 0xFFFF);
    s->state = 4;
}

/* Draws glyph v & 0xF (0-9 digits); 0xB draws gUnknown_0879DDAC[a] and returns 1. */
// sub_0814966C @ 0x0814966C
u32 sub_0814966C(u16 v, u16 a, u16 x, u16 y)
{
    u32 c = v & 0xF;

    switch (c)
    {
    case 0xB:
        Sprite_Draw(gUnknown_0879DDAC[a], 1, 0, 0, 0, x, y);
        return 1;
    case 0xA:
    case 0xC:
        Sprite_Draw(gUnknown_0879CE24[c], 1, 0, 0, 0, x, y);
        break;
    case 0xD:
    case 0xE:
        break;
    default:
        Sprite_Draw(gUnknown_0879CE24[c], 1, 0, 0, 0, x, y);
        break;
    }
    return 0;
}
