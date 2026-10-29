/* Code Breaker, part 1 (0x0814AE1C-0x0814C47B). */

#include "global.h"
#include "casino3.h"

#define GY ((struct C14aCodeBreaker *)gMenuState)

/* Called without a prototype here: the x argument is passed unnarrowed. */
void CasinoText_DrawString();

// sub_0814AE1C @ 0x0814AE1C
void sub_0814AE1C(u32 unused, u32 value)
{
    GY->startScript = value;
}

// CodeBreaker_Init @ 0x0814AE28
void CodeBreaker_Init(void)
{
    struct C14aScene *scene = C14A_SCENE;
    struct C14aCodeBreaker *s = GY;
    u32 zero = 0;
    u16 i;
    u16 arg;

    CpuSet(&zero, s, 0x05000200);
    REG_BG0CNT = 0x4008;
    gUnk_03000002 = 0;
    gUnk_03000040 = 0;
    s->startScript = 1;
    s->unk3C = 0x75;
    s->unk3A = 0x50;
    s->unk34 = 400;
    arg = scene->arg;
    switch (arg)
    {
    case 0:
        s->level = 0;
        s->digits = 3;
        s->symbols = 5;
        s->cursorMin = 0x14;
        s->cursorMax = 0x32;
        break;
    case 1:
        s->level = 1;
        s->digits = 4;
        s->symbols = 7;
        s->cursorMin = 0x14;
        s->cursorMax = 0x41;
        break;
    case 2:
        s->level = arg;
        s->digits = 5;
        s->symbols = 8;
        s->cursorMin = 0x14;
        s->cursorMax = 0x50;
        break;
    case 3:
        s->level = arg;
        s->digits = 5;
        s->symbols = 8;
        s->cursorMin = 0x14;
        s->cursorMax = 0x50;
        break;
    }
    for (i = 0; i < s->symbols; i++)
        s->table[i][0].symbol = i;
}

/* Per-frame update: R starts a game for one item 0xFE, L quits; in state 3 up/down change the
   symbol under the cursor, left/right move it (wrapping inside the row) and A submits. */
// CodeBreaker_Update @ 0x0814AF14
void CodeBreaker_Update(void)
{
    struct C14aCodeBreaker *s = GY;
    u16 i, j;

    if (s->startScript == 1)
    {
        Task_Create(gUnknown_0879F064, 0xFFFF);
        s->startScript = 0;
    }
    switch (s->level)
    {
    case 0:
        Sprite_Draw(gUnknown_0814FC1C, 0, 0, 0, 0, 0x49, 0x1A);
        break;
    case 1:
        Sprite_Draw(gUnknown_0814FC2C, 0, 0, 0, 0, 0x49, 0x1A);
        break;
    case 2:
        Sprite_Draw(gUnknown_0814FC3C, 0, 0, 0, 0, 0x49, 0x1A);
        break;
    case 3:
        Sprite_Draw(gUnknown_0814FC3C, 0, 0, 0, 0, 0x49, 0x1A);
        break;
    }
    if (s->unk18 == 1)
        Sprite_Draw(gUnknown_0814FE04, 0, 0, 0, 0, 8, 4);
    sub_0814B838();
    sub_0814B894();
    sub_0814B8F4();
    if (s->unk1C == 1)
        Sprite_Draw(gUnknown_0814FBEC, 0, 0, 0, 0, gUnknown_0879EB64[s->cursor].x, gUnknown_0879EB64[s->cursor].y);
    if (s->unk30 == 1)
        sub_0814BE8C();
    sub_0814C318();
    sub_0814C3FC(Inventory_GetCount(0xFE), 0xD7, 0x27, 0);
    if (s->ready == 1 && s->state == 0)
    {
        if ((gKeysNew & 0x100) && Inventory_GetCount(0xFE) != 0)
        {
            for (i = 0; i < 8; i++)
            {
                s->results[i].hits = 0;
                s->results[i].blows = 0;
            }
            for (i = 0; i < s->digits; i++)
            {
                s->secret[i].shown = 0;
                s->secret[i].symbol = 10;
            }
            for (i = 0; i < s->symbols; i++)
            {
                for (j = 0; j < s->digits; j++)
                {
                    s->table[i][j].unk3 = 0;
                    s->table[i][j].unk1 = 0;
                }
            }
            s->unk44 = 0;
            s->unk3F = 1;
            Inventory_RemoveItem(0xFE);
            s->state = 1;
            Sound_Play(0x15A);
        }
        else if ((gKeysNew & 0x100) && Inventory_GetCount(0xFE) == 0)
        {
            s->state = 99;
        }
        if (gKeysNew & 0x200)
        {
            Sound_Play(0x158);
            s->state = 99;
        }
    }
    if (s->state == 3)
    {
        if ((gKeysNew & 0x40) && s->busy == 0)
        {
            s->up = 1;
            s->busy = 1;
        }
        if ((gKeysNew & 0x80) && s->busy == 0)
        {
            s->down = 1;
            s->busy = 1;
        }
        if ((gKeysNew & 0x10) && s->busy == 0)
        {
            if (gUnknown_0879EB64[s->cursor].x == s->cursorMax)
                s->cursor = (u16)(s->cursor + 1) - s->digits;
            else
                s->cursor = s->cursor + 1;
        }
        if ((gKeysNew & 0x20) && s->busy == 0)
        {
            if (gUnknown_0879EB64[s->cursor].x == s->cursorMin)
                s->cursor = (u16)(s->cursor - 1) + s->digits;
            else
                s->cursor = s->cursor - 1;
        }
        if ((gKeysNew & 1) && s->busy == 0)
            s->state = 4;
    }
    switch (s->state)
    {
    case 0:
        if (s->timer > 0x14)
        {
            Sprite_Draw(gUnknown_0814FBC4, 0, 0, 0, 0, 0xBB, 5);
            if (s->timer > 0x28)
            {
                s->timer = 0;
                s->ready = 1;
            }
        }
        s->timer++;
        break;
    case 1:
        if (s->unk1C == 0)
            s->unk1C = 1;
        sub_0814B7AC();
        sub_0814B524();
        if (s->unk0E < s->digits)
            sub_0814B6C4();
        break;
    case 2:
        CodeBreaker_PickCode();
        break;
    case 3:
        if (s->up == 1)
            sub_0814BB1C();
        else if (s->down == 1)
            sub_0814BC0C();
        break;
    case 4:
        CodeBreaker_ScoreRow();
        break;
    case 5:
        sub_0814BF7C();
        break;
    case 6:
        sub_0814C130();
        break;
    case 7:
        sub_0814C230();
        break;
    case 8:
        Inventory_AddItem(gUnknown_0879EEE4[s->level][s->unk3F].item);
        s->state = 0;
        break;
    case 99:
        if (s->timer2 <= 5)
        {
            if (s->timer > 3)
                Sprite_Draw(gUnknown_0814FBDC, 0, 0, 0, 0, 8, 5);
            if (s->timer > 6)
            {
                s->timer = 0;
                s->timer2++;
            }
            s->timer++;
        }
        else
            sub_080BE4C4();
        break;
    }
    if (s->level != 3)
        CodeBreaker_DrawNotes();
}

/* Deals the board: one peg per call sequence, hidden (shown = 0) past the code length. */
// sub_0814B524 @ 0x0814B524
void sub_0814B524(void)
{
    struct C14aCodeBreaker *s = GY;

    if (s->unk0A <= 2)
        Sprite_Draw(gUnknown_0814FCEC, 0, 0, 0, 0, gUnknown_0879E5C4[s->level][s->unk10].x, gUnknown_0879E5C4[s->level][s->unk10].y);
    else if ((u16)(s->unk0A - 3) <= 1)
        Sprite_Draw(gUnknown_0814FD1C, 0, 0, 0, 0, gUnknown_0879E5C4[s->level][s->unk10].x, gUnknown_0879E5C4[s->level][s->unk10].y);
    else if ((u16)(s->unk0A - 5) <= 1)
        Sprite_Draw(gUnknown_0814FD0C, 0, 0, 0, 0, gUnknown_0879E5C4[s->level][s->unk10].x, gUnknown_0879E5C4[s->level][s->unk10].y);
    else if ((u16)(s->unk0A - 7) <= 1)
        Sprite_Draw(gUnknown_0814FCFC, 0, 0, 0, 0, gUnknown_0879E5C4[s->level][s->unk10].x, gUnknown_0879E5C4[s->level][s->unk10].y);
    else if (s->unk0A > 8)
    {
        Sprite_Draw(gUnknown_0814FCEC, 0, 0, 0, 0, gUnknown_0879E5C4[s->level][s->unk10].x, gUnknown_0879E5C4[s->level][s->unk10].y);
        Sound_Play(0x15B);
        if (s->unk0A > 12)
        {
            if (s->unk10 <= s->digits - 1)
            {
                s->board[gUnknown_0879E5C4[s->level][s->unk10].slot].symbol = 0;
                s->board[gUnknown_0879E5C4[s->level][s->unk10].slot].shown = 1;
            }
            else
            {
                s->board[gUnknown_0879E5C4[s->level][s->unk10].slot].symbol = 0;
                s->board[gUnknown_0879E5C4[s->level][s->unk10].slot].shown = 0;
            }
            if (gUnknown_0879E5C4[s->level][s->unk10].last != 1)
                s->unk10++;
            else
            {
                s->unk10 = 0;
                s->unk0E = 0;
                s->state = 2;
            }
            s->unk0A = 0;
        }
    }
    s->unk0A++;
}

/* Deals the hidden code row (symbol 8 = covered). */
// sub_0814B6C4 @ 0x0814B6C4
void sub_0814B6C4(void)
{
    struct C14aCodeBreaker *s = GY;

    if (s->unk0C <= 2)
        Sprite_Draw(gUnknown_0814FCEC, 0, 0, 0, 0, gUnknown_0879E5B0[s->unk0E].x, gUnknown_0879E5B0[s->unk0E].y);
    else if ((u16)(s->unk0C - 3) <= 1)
        Sprite_Draw(gUnknown_0814FD1C, 0, 0, 0, 0, gUnknown_0879E5B0[s->unk0E].x, gUnknown_0879E5B0[s->unk0E].y);
    else if ((u16)(s->unk0C - 5) <= 1)
        Sprite_Draw(gUnknown_0814FD0C, 0, 0, 0, 0, gUnknown_0879E5B0[s->unk0E].x, gUnknown_0879E5B0[s->unk0E].y);
    else if ((u16)(s->unk0C - 7) <= 1)
        Sprite_Draw(gUnknown_0814FCFC, 0, 0, 0, 0, gUnknown_0879E5B0[s->unk0E].x, gUnknown_0879E5B0[s->unk0E].y);
    else if (s->unk0C > 8)
    {
        Sprite_Draw(gUnknown_0814FCEC, 0, 0, 0, 0, gUnknown_0879E5B0[s->unk0E].x, gUnknown_0879E5B0[s->unk0E].y);
        Sound_Play(0x15B);
        if (s->unk0C > 12)
        {
            s->secret[s->unk0E].symbol = 8;
            s->unk0E++;
            s->unk0C = 0;
        }
    }
    s->unk0C++;
}

// sub_0814B7AC @ 0x0814B7AC
void sub_0814B7AC(void)
{
    struct C14aCodeBreaker *s = GY;

    if (s->unk16 <= 3)
        Sprite_Draw(gUnknown_0814FE4C, 1, 0, 0, 0, 8, 4);
    else if ((u16)(s->unk16 - 4) <= 2)
        Sprite_Draw(gUnknown_0814FE34, 1, 0, 0, 0, 8, 4);
    else if ((u16)(s->unk16 - 7) <= 2)
        Sprite_Draw(gUnknown_0814FE1C, 1, 0, 0, 0, 8, 4);
    else if (s->unk16 > 9)
    {
        Sprite_Draw(gUnknown_0814FE04, 1, 0, 0, 0, 8, 4);
        s->unk18 = 1;
    }
    s->unk16++;
}

// sub_0814B838 @ 0x0814B838
void sub_0814B838(void)
{
    struct C14aCodeBreaker *s = GY;
    u16 i;

    for (i = 0; i < 40; i++)
    {
        if (s->board[i].shown == 1)
            Sprite_Draw(gUnknown_0879E58C[s->board[i].symbol], 0, 0, 1, 0, gUnknown_0879EAC4[i].x, gUnknown_0879EAC4[i].y);
    }
}

// sub_0814B894 @ 0x0814B894
void sub_0814B894(void)
{
    struct C14aCodeBreaker *s = GY;
    u16 i;

    for (i = 0; i < 5; i++)
    {
        if (s->secret[i].shown == 1)
            Sprite_Draw(gUnknown_0879E58C[s->secret[i].symbol], 0, 0, 1, 0, gUnknown_0879E5B0[i].x, gUnknown_0879E5B0[i].y);
    }
}

/* Covers the board parts a level does not use. */
// sub_0814B8F4 @ 0x0814B8F4
void sub_0814B8F4(void)
{
    switch (GY->level)
    {
    case 0:
        Sprite_Draw(gUnknown_0814FCDC, 0, 0, 0, 0, 0x39, 0x21);
        Sprite_Draw(gUnknown_0814FCDC, 0, 0, 0, 0, 0x48, 0x21);
        Sprite_Draw(gUnknown_0814FEEC, 0, 0, 0, 0, 0x3D, 0x41);
        Sprite_Draw(gUnknown_0814FEEC, 0, 0, 0, 0, 0x4C, 0x41);
        Sprite_Draw(gUnknown_0814FEEC, 0, 0, 0, 0, 0xCA, 0x41);
        Sprite_Draw(gUnknown_0814FEEC, 0, 0, 0, 0, 0xD9, 0x41);
        Sprite_Draw(gUnknown_0814FEC8, 0, 0, 0, 0, 0x8E, 0x78);
        Sprite_Draw(gUnknown_0814FEC8, 0, 0, 0, 0, 0x8E, 0x83);
        Sprite_Draw(gUnknown_0814FEC8, 0, 0, 0, 0, 0x8E, 0x8E);
        break;
    case 1:
        Sprite_Draw(gUnknown_0814FCDC, 0, 0, 0, 0, 0x48, 0x21);
        Sprite_Draw(gUnknown_0814FEEC, 0, 0, 0, 0, 0x4C, 0x41);
        Sprite_Draw(gUnknown_0814FEEC, 0, 0, 0, 0, 0xD9, 0x41);
        Sprite_Draw(gUnknown_0814FEC8, 0, 0, 0, 0, 0x8E, 0x8E);
        break;
    case 2:
        break;
    case 3:
        Sprite_Draw(gUnknown_0814FEEC, 0, 0, 0, 0, 0xD9, 0x41);
        Sprite_Draw(gUnknown_0814FEC8, 0, 0, 0, 0, 0x8E, 0x41);
        Sprite_Draw(gUnknown_0814FEC8, 0, 0, 0, 0, 0x8E, 0x4C);
        Sprite_Draw(gUnknown_0814FEC8, 0, 0, 0, 0, 0x8E, 0x57);
        Sprite_Draw(gUnknown_0814FEC8, 0, 0, 0, 0, 0x8E, 0x62);
        Sprite_Draw(gUnknown_0814FEC8, 0, 0, 0, 0, 0x8E, 0x6D);
        Sprite_Draw(gUnknown_0814FEC8, 0, 0, 0, 0, 0x8E, 0x78);
        Sprite_Draw(gUnknown_0814FEC8, 0, 0, 0, 0, 0x8E, 0x83);
        Sprite_Draw(gUnknown_0814FEC8, 0, 0, 0, 0, 0x8E, 0x8E);
        break;
    }
}

/* Up pressed: rolls the symbol under the cursor forward. */
// sub_0814BB1C @ 0x0814BB1C
void sub_0814BB1C(void)
{
    struct C14aCodeBreaker *s = GY;

    if (s->upAnim <= 4)
        Sprite_Draw(gUnknown_0814FCFC, 0, 0, 0, 0, gUnknown_0879EAC4[s->cursor].x, gUnknown_0879EAC4[s->cursor].y);
    else if ((u16)(s->upAnim - 5) <= 3)
        Sprite_Draw(gUnknown_0814FD0C, 0, 0, 0, 0, gUnknown_0879EAC4[s->cursor].x, gUnknown_0879EAC4[s->cursor].y);
    else if ((u16)(s->upAnim - 9) <= 3)
        Sprite_Draw(gUnknown_0814FD1C, 0, 0, 0, 0, gUnknown_0879EAC4[s->cursor].x, gUnknown_0879EAC4[s->cursor].y);
    else if ((u16)(s->upAnim - 13) <= 3)
        Sprite_Draw(gUnknown_0814FD2C, 0, 0, 0, 0, gUnknown_0879EAC4[s->cursor].x, gUnknown_0879EAC4[s->cursor].y);
    else if ((u16)(s->upAnim - 17) <= 3)
        Sprite_Draw(gUnknown_0814FD3C, 0, 0, 0, 0, gUnknown_0879EAC4[s->cursor].x, gUnknown_0879EAC4[s->cursor].y);
    else if ((u16)(s->upAnim - 21) <= 3)
        Sprite_Draw(gUnknown_0814FD4C, 0, 0, 0, 0, gUnknown_0879EAC4[s->cursor].x, gUnknown_0879EAC4[s->cursor].y);
    else
    {
        Sound_Play(0x15B);
        if (s->board[s->cursor].symbol == s->symbols - 1)
            s->board[s->cursor].symbol = 0;
        else
            s->board[s->cursor].symbol++;
        s->upAnim = 0;
        s->up = 0;
        s->busy = 0;
    }
    s->upAnim++;
}

/* Down pressed: rolls it back. */
// sub_0814BC0C @ 0x0814BC0C
void sub_0814BC0C(void)
{
    struct C14aCodeBreaker *s = GY;

    if (s->downAnim <= 4)
        Sprite_Draw(gUnknown_0814FD4C, 0, 0, 0, 0, gUnknown_0879EAC4[s->cursor].x, gUnknown_0879EAC4[s->cursor].y);
    else if ((u16)(s->downAnim - 5) <= 3)
        Sprite_Draw(gUnknown_0814FD3C, 0, 0, 0, 0, gUnknown_0879EAC4[s->cursor].x, gUnknown_0879EAC4[s->cursor].y);
    else if ((u16)(s->downAnim - 9) <= 3)
        Sprite_Draw(gUnknown_0814FD2C, 0, 0, 0, 0, gUnknown_0879EAC4[s->cursor].x, gUnknown_0879EAC4[s->cursor].y);
    else if ((u16)(s->downAnim - 13) <= 3)
        Sprite_Draw(gUnknown_0814FD1C, 0, 0, 0, 0, gUnknown_0879EAC4[s->cursor].x, gUnknown_0879EAC4[s->cursor].y);
    else if ((u16)(s->downAnim - 17) <= 3)
        Sprite_Draw(gUnknown_0814FD0C, 0, 0, 0, 0, gUnknown_0879EAC4[s->cursor].x, gUnknown_0879EAC4[s->cursor].y);
    else if ((u16)(s->downAnim - 21) <= 3)
        Sprite_Draw(gUnknown_0814FCFC, 0, 0, 0, 0, gUnknown_0879EAC4[s->cursor].x, gUnknown_0879EAC4[s->cursor].y);
    else
    {
        Sound_Play(0x15B);
        if (s->board[s->cursor].symbol == 0)
            s->board[s->cursor].symbol = s->symbols - 1;
        else
            s->board[s->cursor].symbol--;
        s->downAnim = 0;
        s->down = 0;
        s->busy = 0;
    }
    s->downAnim++;
}

/* A pressed: scores the current row. A symbol in the right place is a hit; otherwise every
   other code position holding the same symbol counts as a blow (duplicates are not excluded). */
// CodeBreaker_ScoreRow @ 0x0814BCF4
void CodeBreaker_ScoreRow(void)
{
    struct C14aCodeBreaker *s = GY;
    u16 i, j;

    for (i = 0; i < s->digits; i++)
    {
        if (s->board[s->row + i].symbol == s->secret[i].symbol)
        {
            s->results[(u8)(s->row / 5)].hits++;
        }
        else
        {
            for (j = 0; j < s->digits; j++)
            {
                if (i != j && s->board[s->row + i].symbol == s->secret[j].symbol)
                    s->results[(u8)(s->row / 5)].blows++;
            }
        }
    }
    s->unk42 = s->results[(u8)(s->row / 5)].hits;
    s->unk43 = s->results[(u8)(s->row / 5)].blows;
    CodeBreaker_UpdateNotes();
    s->unk30 = 1;
    if (s->results[(u8)(s->row / 5)].hits == s->digits)
    {
        s->cursor = 0;
        s->row = 0;
        s->unk1C = 0;
        s->unk3E = 1;
        s->state = 6;
    }
    else if (s->row == 35)
    {
        s->cursor = 0;
        s->row = 0;
        s->unk1C = 0;
        s->unk18 = 0;
        s->unk3E = 0;
        s->state = 6;
    }
    else
    {
        s->row += 5;
        s->cursor += sub_0814C52C(s->cursor);
        s->unk3F++;
        s->state = 5;
    }
}

/* Draws the hit and blow markers of every scored row. */
// sub_0814BE8C @ 0x0814BE8C
#ifdef NONMATCHING
void sub_0814BE8C(void)
{
    struct C14aCodeBreaker *s = GY;
    u16 i, j;
    u32 zero = 0;

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < s->results[i].hits; j++)
        {
            Sprite_Draw(gUnknown_0814FBFC, 0, 0, 0, zero, s->unk32 + 0x63, gUnknown_0879EC04[i][0]);
            s->unk32 += 7;
        }
        for (j = 0; j < s->results[i].blows; j++)
        {
            Sprite_Draw(gUnknown_0814FC0C, 0, 0, 0, zero, s->unk32 + 0x63, gUnknown_0879EC04[i][0]);
            s->unk32 += 7;
        }
        s->unk32 = zero;
    }
}
#else
NAKED
void sub_0814BE8C(void)
{
    asm_unified(
        ".L0814BE8C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0xc\n"
        "    ldr r4, .L0814BF68\n"
        "    movs r0, #0\n"
        "    mov r8, r0\n"
        "    mov sb, r0\n"
        ".L0814BEA0:\n"
        "    movs r5, #0\n"
        "    mov r2, r8\n"
        "    lsls r1, r2, #2\n"
        "    adds r0, r4, r1\n"
        "    movs r2, #0x96\n"
        "    lsls r2, r2, #1\n"
        "    adds r0, r0, r2\n"
        "    adds r6, r1, #0\n"
        "    movs r1, #1\n"
        "    add r1, r8\n"
        "    mov sl, r1\n"
        "    ldrb r0, [r0]\n"
        "    cmp r5, r0\n"
        "    bhs .L0814BEFC\n"
        "    mov r2, r8\n"
        "    lsls r0, r2, #1\n"
        "    ldr r1, .L0814BF6C\n"
        "    adds r0, r0, r1\n"
        "    ldrb r7, [r0]\n"
        ".L0814BEC6:\n"
        "    mov r2, sb\n"
        "    str r2, [sp]\n"
        "    ldrh r0, [r4, #0x32]\n"
        "    adds r0, #0x63\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #4]\n"
        "    str r7, [sp, #8]\n"
        "    ldr r0, .L0814BF70\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    ldrh r0, [r4, #0x32]\n"
        "    adds r0, #7\n"
        "    strh r0, [r4, #0x32]\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    adds r0, r4, r6\n"
        "    movs r1, #0x96\n"
        "    lsls r1, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    ldrb r0, [r0]\n"
        "    cmp r5, r0\n"
        "    blo .L0814BEC6\n"
        ".L0814BEFC:\n"
        "    movs r5, #0\n"
        "    adds r0, r4, r6\n"
        "    ldr r2, .L0814BF74\n"
        "    adds r0, r0, r2\n"
        "    ldrb r0, [r0]\n"
        "    cmp r5, r0\n"
        "    bhs .L0814BF48\n"
        "    mov r1, r8\n"
        "    lsls r0, r1, #1\n"
        "    ldr r2, .L0814BF6C\n"
        "    adds r0, r0, r2\n"
        "    ldrb r7, [r0]\n"
        ".L0814BF14:\n"
        "    mov r0, sb\n"
        "    str r0, [sp]\n"
        "    ldrh r0, [r4, #0x32]\n"
        "    adds r0, #0x63\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #4]\n"
        "    str r7, [sp, #8]\n"
        "    ldr r0, .L0814BF78\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    ldrh r0, [r4, #0x32]\n"
        "    adds r0, #7\n"
        "    strh r0, [r4, #0x32]\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    adds r0, r4, r6\n"
        "    ldr r1, .L0814BF74\n"
        "    adds r0, r0, r1\n"
        "    ldrb r0, [r0]\n"
        "    cmp r5, r0\n"
        "    blo .L0814BF14\n"
        ".L0814BF48:\n"
        "    mov r2, sb\n"
        "    strh r2, [r4, #0x32]\n"
        "    mov r1, sl\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        "    cmp r0, #7\n"
        "    bls .L0814BEA0\n"
        "    add sp, #0xc\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L0814BF68: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L0814BF6C: .4byte gUnknown_0879EC04\n"
        ".L0814BF70: .4byte gUnknown_0814FBFC\n"
        ".L0814BF74: .4byte 0x0000012D\n"
        ".L0814BF78: .4byte gUnknown_0814FC0C\n"
    );
}
#endif

/* Deals a fresh row of pegs after a wrong guess. */
// sub_0814BF7C @ 0x0814BF7C
void sub_0814BF7C(void)
{
    struct C14aCodeBreaker *s = GY;

    if (s->unk0A <= 2)
        Sprite_Draw(gUnknown_0814FCEC, 0, 0, 0, 0, gUnknown_0879EAC4[s->unk10 + s->cursor].x, gUnknown_0879EAC4[s->unk10 + s->cursor].y);
    else if ((u16)(s->unk0A - 3) <= 1)
        Sprite_Draw(gUnknown_0814FD1C, 0, 0, 0, 0, gUnknown_0879EAC4[s->unk10 + s->cursor].x, gUnknown_0879EAC4[s->unk10 + s->cursor].y);
    else if ((u16)(s->unk0A - 5) <= 1)
        Sprite_Draw(gUnknown_0814FD0C, 0, 0, 0, 0, gUnknown_0879EAC4[s->unk10 + s->cursor].x, gUnknown_0879EAC4[s->unk10 + s->cursor].y);
    else if ((u16)(s->unk0A - 7) <= 1)
        Sprite_Draw(gUnknown_0814FCFC, 0, 0, 0, 0, gUnknown_0879EAC4[s->unk10 + s->cursor].x, gUnknown_0879EAC4[s->unk10 + s->cursor].y);
    else if (s->unk0A > 8)
    {
        Sprite_Draw(gUnknown_0814FCEC, 0, 0, 0, 0, gUnknown_0879EAC4[s->unk10 + s->cursor].x, gUnknown_0879EAC4[s->unk10 + s->cursor].y);
        Sound_Play(0x15B);
        if (s->unk0A > 12)
        {
            s->board[s->unk10 + s->cursor].symbol = 0;
            s->board[s->unk10 + s->cursor].shown = 1;
            if (s->unk10 == s->digits - 1)
            {
                s->unk10 = 0;
                s->state = 3;
            }
            else
            {
                s->unk10++;
                s->unk0A = 0;
            }
        }
    }
    s->unk0A++;
}

/* Picks the secret code: digits different symbols, (Random_Byte() * symbols) >> 8 each. */
// CodeBreaker_PickCode @ 0x0814C098
#ifdef NONMATCHING
void CodeBreaker_PickCode(void)
{
    struct C14aCodeBreaker *s = GY;
    u16 i;

    while (s->state != 3)
    {
        s->dup = 0;
        s->rand = Random_Byte() & 0xFF;
        s->rand = (s->rand * s->symbols) >> 8;
        for (i = 0; i < s->digits; i++)
        {
            if (s->secret[i].symbol == s->rand)
                s->dup = 1;
        }
        if (s->dup == 0)
        {
            s->secret[s->unk12].symbol = s->rand;
            s->unk12++;
        }
        if (s->unk12 == s->digits)
        {
            s->unk12 = 0;
            s->state = 3;
        }
    }
    s->state = 3;
}
#else
NAKED
void CodeBreaker_PickCode(void)
{
    asm_unified(
        ".L0814C098:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    ldr r4, .L0814C0A0\n"
        "    b .L0814C120\n"
        "    .byte 0x00, 0x00\n"
        ".L0814C0A0: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L0814C0A4:\n"
        "    movs r0, #0\n"
        "    strb r0, [r4, #0x14]\n"
        "    bl Random_Byte\n"
        "    movs r1, #0xff\n"
        "    ands r0, r1\n"
        "    strh r0, [r4, #0x22]\n"
        "    ldrh r1, [r4, #0x22]\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x2e\n"
        "    ldrb r0, [r0]\n"
        "    muls r0, r1, r0\n"
        "    asrs r1, r0, #8\n"
        "    strh r1, [r4, #0x22]\n"
        "    movs r2, #0\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x2f\n"
        "    adds r3, r0, #0\n"
        "    ldrb r0, [r3]\n"
        "    cmp r2, r0\n"
        "    bhs .L0814C0F4\n"
        "    movs r7, #0x8c\n"
        "    lsls r7, r7, #1\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    movs r6, #1\n"
        "    adds r1, r3, #0\n"
        ".L0814C0DA:\n"
        "    lsls r0, r2, #2\n"
        "    adds r0, r4, r0\n"
        "    adds r0, r0, r7\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, r5\n"
        "    bne .L0814C0E8\n"
        "    strb r6, [r4, #0x14]\n"
        ".L0814C0E8:\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    ldrb r0, [r1]\n"
        "    cmp r2, r0\n"
        "    blo .L0814C0DA\n"
        ".L0814C0F4:\n"
        "    ldrb r0, [r4, #0x14]\n"
        "    cmp r0, #0\n"
        "    bne .L0814C110\n"
        "    ldrh r0, [r4, #0x12]\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r4, r0\n"
        "    ldrh r1, [r4, #0x22]\n"
        "    movs r2, #0x8c\n"
        "    lsls r2, r2, #1\n"
        "    adds r0, r0, r2\n"
        "    strb r1, [r0]\n"
        "    ldrh r0, [r4, #0x12]\n"
        "    adds r0, #1\n"
        "    strh r0, [r4, #0x12]\n"
        ".L0814C110:\n"
        "    ldrh r0, [r4, #0x12]\n"
        "    ldrb r3, [r3]\n"
        "    cmp r0, r3\n"
        "    bne .L0814C120\n"
        "    movs r0, #0\n"
        "    strh r0, [r4, #0x12]\n"
        "    movs r0, #3\n"
        "    strb r0, [r4, #4]\n"
        ".L0814C120:\n"
        "    ldrb r0, [r4, #4]\n"
        "    cmp r0, #3\n"
        "    bne .L0814C0A4\n"
        "    movs r0, #3\n"
        "    strb r0, [r4, #4]\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

/* Uncovers the code at the end of a game. */
// sub_0814C130 @ 0x0814C130
void sub_0814C130(void)
{
    struct C14aCodeBreaker *s = GY;

    if (s->unk0C <= 2)
        Sprite_Draw(gUnknown_0814FCEC, 0, 0, 0, 0, gUnknown_0879E5B0[s->unk0E].x, gUnknown_0879E5B0[s->unk0E].y);
    else if ((u16)(s->unk0C - 3) <= 1)
        Sprite_Draw(gUnknown_0814FD1C, 0, 0, 0, 0, gUnknown_0879E5B0[s->unk0E].x, gUnknown_0879E5B0[s->unk0E].y);
    else if ((u16)(s->unk0C - 5) <= 1)
        Sprite_Draw(gUnknown_0814FD0C, 0, 0, 0, 0, gUnknown_0879E5B0[s->unk0E].x, gUnknown_0879E5B0[s->unk0E].y);
    else if ((u16)(s->unk0C - 7) <= 1)
        Sprite_Draw(gUnknown_0814FCFC, 0, 0, 0, 0, gUnknown_0879E5B0[s->unk0E].x, gUnknown_0879E5B0[s->unk0E].y);
    else if (s->unk0C > 8)
    {
        Sprite_Draw(gUnknown_0814FCEC, 0, 0, 0, 0, gUnknown_0879E5B0[s->unk0E].x, gUnknown_0879E5B0[s->unk0E].y);
        Sound_Play(0x15B);
        if (s->unk0C > 12)
        {
            s->secret[s->unk0E].shown = 1;
            if (s->unk0E == s->digits - 1)
            {
                s->unk0E = 0;
                s->unk0C = 0;
                s->state = 7;
            }
            else
            {
                s->unk0E++;
                s->unk0C = 0;
            }
        }
    }
    s->unk0C++;
}

/* Slides the win (gUnknown_0814FC54) or lose (gUnknown_0814FC7C) banner across the screen. */
// sub_0814C230 @ 0x0814C230
void sub_0814C230(void)
{
    struct C14aCodeBreaker *s = GY;

    if (s->unk36 == 0 && s->unk34 <= 0xD2)
    {
        if (s->unk3E == 0)
            Sound_Play(0x163);
        else
            Sound_Play(0x15E);
        s->unk38 = 1;
    }
    if (s->unk38 == 1 && ++s->unk36 == 0x1E)
        s->unk38 = 0;
    if (s->unk3E == 0)
        Sprite_Draw(gUnknown_0814FC7C, 0, 0, 0, 0, s->unk34 - s->unk3A, 0x3F);
    else
        Sprite_Draw(gUnknown_0814FC54, 0, 0, 0, 0, s->unk34 - s->unk3C, 0x3F);
    if (s->unk34 == 0)
    {
        s->unk34 = 400;
        s->unk36 = 0;
        if (s->unk3E == 1)
        {
            s->unk18 = 0;
            s->state = 8;
        }
        else
        {
            s->unk18 = 0;
            s->state = 0;
        }
    }
    if (s->unk38 == 0)
        s->unk34 -= 4;
}

/* Shows the prize for the current try count (gUnknown_0879EC14), or entry 9 when the prize item
   is already held 99 times. */
// sub_0814C318 @ 0x0814C318
void sub_0814C318(void)
{
    struct C14aCodeBreaker *s = GY;

    Font_ResetGlyphSpriteCache(0x380);
    if (Inventory_IsMaxed(gUnknown_0879EEE4[s->level][s->unk3F].item))
        CasinoText_DrawString(gUnknown_0879EC14[s->level][9], 0, 0, gUnknown_0879EEE4[s->level][9].value + 0x63, 0x1D, 10);
    else if ((u8)(s->unk3F - 1) <= 1)
        CasinoText_DrawString(gUnknown_0879EC14[s->level][s->unk3F], 0, 0, gUnknown_0879EEE4[s->level][s->unk3F].value + 0x64, 0x1D, 12);
    else
        CasinoText_DrawString(gUnknown_0879EC14[s->level][s->unk3F], 0, 0, gUnknown_0879EEE4[s->level][s->unk3F].value + 0x64, 0x1D, 10);
}

/* Draws a two-digit number (ones at x, tens at x - 8). */
// sub_0814C3FC @ 0x0814C3FC
void sub_0814C3FC(u32 value, u16 x, u16 y, u16 priority)
{
    u8 *digits = NumberToDigits(value);

    Sprite_Draw(gUnknown_0879EF84[digits[0]], 0, 0, priority, 0, x, y & 0xFF);
    Sprite_Draw(gUnknown_0879EF84[digits[1]], 0, 0, priority, 0, x - 8, y & 0xFF);
}

// CodeBreaker_DrawNotes @ 0x0814C47C
void CodeBreaker_DrawNotes(void)
{
    struct C14aCodeBreaker *s = GY;
    u16 i, j;

    for (i = 0; i < s->symbols; i++)
    {
        for (j = 0; j < s->digits; j++)
        {
            if (s->table[i][j].unk1 != 0)
                Sprite_Draw(gUnknown_0879EFAC[(s->table[i][j].unk1 + 1) & 0xFF], 1, 0, 0, 0,
                            gUnknown_0879EFBC[i][j].x, gUnknown_0879EFBC[i][j].y & 0xFF);
        }
    }
}
