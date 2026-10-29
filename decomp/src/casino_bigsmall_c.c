/* Casino minigame started by 0x08149BBC: drawing and coin count-up (0x0814A1FC-). */

#include "global.h"
#include "casino2.h"

// sub_0814A1FC @ 0x0814A1FC
void sub_0814A1FC(void)
{
    struct C145Game5 *s = gGame5;

    if (s->blink > 20)
    {
        if (s->unk018 == 1)
            Sprite_Draw(gUnknown_0814F790, 0, 0, 0, 0, 0x82, 0x19);
        else if (s->unk019 == 1)
            Sprite_Draw(gUnknown_0814F7A8, 0, 0, 0, 0, 0x82, 0x38);
        if (s->blink > 40)
            s->blink = 0;
    }
    s->blink++;
}

/* Draws a 6-digit number right-aligned at x. */
// BigSmall_DrawNumber6 @ 0x0814A26C
void BigSmall_DrawNumber6(u32 n, u16 x, u16 y, u16 priority)
{
    u8 *d = NumberToDigits(n);
    const void *const *glyphs = gUnknown_0879DDD4;

    Sprite_Draw(glyphs[d[0]], 0, 0, priority, 0, x, y & 0xFF);
    Sprite_Draw(glyphs[d[1]], 0, 0, priority, 0, x - 8, y & 0xFF);
    Sprite_Draw(glyphs[d[2]], 0, 0, priority, 0, x - 0x10, y & 0xFF);
    Sprite_Draw(glyphs[d[3]], 0, 0, priority, 0, x - 0x18, y & 0xFF);
    Sprite_Draw(glyphs[d[4]], 0, 0, priority, 0, x - 0x20, y & 0xFF);
    Sprite_Draw(glyphs[d[5]], 0, 0, priority, 0, x - 0x28, y & 0xFF);
}

/* Count-up step while A is held: the largest power of ten (up to 10000) not above n. */
// BigSmall_GetCountStep @ 0x0814A36C
s32 BigSmall_GetCountStep(u32 n)
{
    u32 step = 10000;
    u32 i;

    if (n == 0)
        return 0;
    for (i = 0; i < 5; i++)
    {
        if (n / step != 0)
            return step;
        step /= 10;
    }
    return step;
}

/* Counts the won coins up to the target; reaching 10240 (the cap) ends with phase 9. */
// BigSmall_CountUpCoins @ 0x0814A3A8
void BigSmall_CountUpCoins(void)
{
    struct C145Game5 *s = gGame5;

    if ((gFrameCounter & 3) == 0)
    {
        Sound_Play(0x159);
        if (gRepeatedKeys & 1)
            s->step = BigSmall_GetCountStep(s->shown);
        else
            s->step = 5;
        s->shown += s->step;
        if (s->shown >= s->target)
        {
            s->shown = s->target;
            s->unk034 = s->coins;
            if (s->target == 0x2800)
                s->phase = 9;
            else
                s->phase = 7;
        }
    }
}
