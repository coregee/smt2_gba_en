/* Casino minigame on an 8x8 board of 64 numbers (0x081485A0-). */

#include "global.h"
#include "casino2.h"

/* Draws the low `digits` digits of n, most significant first, from x rightwards. */
// Keno_DrawDigits @ 0x081485A0
void Keno_DrawDigits(u32 n, u16 digits, u16 x, u16 y)
{
    u8 *d = NumberToDigits(n);
    u8 i = digits - 1;
    u32 k;

    for (k = 0; k < digits; k++)
    {
        Sprite_Draw(gUnknown_0879CE24[d[i]], 1, 0, 0, 0, x, y);
        i--;
        x += 8;
    }
}

// sub_08148618 @ 0x08148618
void sub_08148618(void)
{
    struct C145Grid *s = gGrid;
    u16 x, y;

    if (s->state == 3)
    {
        x = s->cursorX * 15 + 4;
        y = s->cursorY * 11 + 0x24;
        if (s->cursorY > 3)
            y += 0x1B;
        Sprite_Draw(gUnknown_0879CE58[s->cursorAnim], 1, 0, 0, 0, x, y);
        if ((gFrameCounter & 7) == 0)
            s->cursorAnim = (s->cursorAnim + 1) & 3;
    }
}

// sub_0814869C @ 0x0814869C
void sub_0814869C(u16 i, u16 x, u16 y)
{
    struct C145Grid *s = gGrid;
    const void *const *tbl = gUnknown_0879CEA8[i];

    if (s->sprFrame[i] != 0)
    {
        if (s->sprX[i] != 0 || s->sprY[i] != 0)
        {
            x = s->sprX[i];
            y = s->sprY[i];
        }
        Sprite_Draw(tbl[s->sprFrame[i]], 1, 0, 0, 0, x, y);
    }
}

// sub_08148718 @ 0x08148718
void sub_08148718(u16 i, u16 frame, u16 x, u16 y)
{
    struct C145Grid *s = gGrid;

    s->sprFrame[i] = frame;
    if (x != 0)
        s->sprX[i] = x;
    if (y != 0)
        s->sprY[i] = y;
}

// sub_08148754 @ 0x08148754
void sub_08148754(u16 i, u16 frame, u16 x, u16 y)
{
    struct C145Grid *s = gGrid;

    s->sprFrame[i] = frame;
    s->sprX[i] = x;
    s->sprY[i] = y;
}

// sub_08148780 @ 0x08148780
void sub_08148780(u32 unused, u16 i, u16 frame, u16 x, u16 y)
{
    sub_08148718(i, frame, x, y);
}

// sub_081487A4 @ 0x081487A4
void sub_081487A4(u32 unused, u16 i, u16 frame, u16 x, u16 y)
{
    sub_08148754(i, frame, x, y);
}

// sub_081487C8 @ 0x081487C8
void sub_081487C8(void)
{
    gUnk_03000040 = 0x2E40;
}

/* Starts the game. The draw is warmed up by sixteen rounds of sixteen numbers out of 64. */
// Keno_Init @ 0x081487D8
void Keno_Init(void)
{
    struct C145Grid *s = gGrid;
    u32 zero = 0;
    u32 zero2;
    u16 r;
    u32 j, i;

    CpuSet(&zero, s, 0x05000200);
    zero2 = 0;
    DmaSet3(&zero2, 0x06000000, 0x85001000);
    REG_BG0CNT = 0x4008;
    gUnk_03000002 = 0;
    gDispRegs = 0xF0;
    sub_081487C8();
    s->unk198 = 8;
    s->unk19A = 8;
    s->unk19C = 0x10;
    s->unk19E = 0;
    gUnk_03000042 = (s->unk19A << 8) | s->unk198;
    gUnk_03000044 = s->unk19C;
    s->state = 1;
    for (j = 0; j < 16; j++)
    {
        for (i = 0; i < 16; i++)
        {
        pick:
            r = Random_Byte() & 0x3F;
            if (s->cell[r] != 0)
                goto pick;
            s->cell[r] = 1;
        }
        Keno_RecordHistory();
        for (i = 0; i < 64; i++)
            s->cell[i] = 0;
    }
    sub_08148718(0, 0, 0, 0);
    sub_08148718(1, 0, 0, 0);
    sub_08148718(2, 0, 0, 0);
    sub_08148718(3, 1, 0, 0);
    sub_08148718(4, 1, 0, 0);
    s->sprX[4] = 0x87;
    s->sprY[4] = 0xA0;
    s->coins = sub_080C31F0();
}

// Keno_CanStart @ 0x08148928
bool32 Keno_CanStart(void)
{
    struct C145Grid *s = gGrid;
    bool32 r;

    if (s->state != 2 && s->state != 3)
        return FALSE;
    r = FALSE;
    if (s->bet != 0 && s->marked != 0)
        r = TRUE;
    return r;
}
