/* Joker and Stars (casino game 7): sprite slots, number display, setup and reel strips
   (0x081447E4-0x08144C0B). Nine reels in a 3x3 grid, eight paylines. */

#include "global.h"
#include "casino.h"

/* Draws sprite slot `slot` with its current frame, at its stored position if it has one. */
// JokerStars_DrawSlot @ 0x081447E4
void JokerStars_DrawSlot(u16 slot, u16 x, u16 y)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;
    const void *const *frames = gUnknown_0879A264[slot];

    if (s->slotFrame[slot] != 0)
    {
        if (s->slotX[slot] != 0 || s->slotY[slot] != 0)
        {
            x = s->slotX[slot];
            y = s->slotY[slot];
        }
        Sprite_Draw(frames[s->slotFrame[slot]], 1, 0, 0, 0, x, y);
    }
}

// JokerStars_SetSlot @ 0x08144868
void JokerStars_SetSlot(u16 slot, u16 frame, u16 x, u16 y)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;

    s->slotFrame[slot] = frame;
    if (x != 0)
        s->slotX[slot] = x;
    if (y != 0)
        s->slotY[slot] = y;
}

// JokerStars_SetSlotPos @ 0x081448A8
void JokerStars_SetSlotPos(u16 slot, u16 frame, u16 x, u16 y)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;

    s->slotFrame[slot] = frame;
    s->slotX[slot] = x;
    s->slotY[slot] = y;
}

/* Script commands wrapping the two above. */
// sub_081448D8 @ 0x081448D8
void sub_081448D8(struct Task *task, u32 slot, u32 frame, u32 x, u32 y)
{
    JokerStars_SetSlot(slot, frame, x, y);
}

// sub_081448FC @ 0x081448FC
void sub_081448FC(struct Task *task, u32 slot, u32 frame, u32 x, u32 y)
{
    JokerStars_SetSlotPos(slot, frame, x, y);
}

/* Draws the lowest `digits` digits of value, left to right, 5 pixels apart. */
// JokerStars_DrawNumber @ 0x08144920
void JokerStars_DrawNumber(u32 value, u16 digits, u16 x, u16 y)
{
    u8 *d = NumberToDigits(value);
    u8 i = digits - 1;
    u32 n;

    for (n = 0; n < digits; n++)
    {
        Sprite_Draw(gUnknown_0879A29C[d[i]], 1, 0, 0, 0, x, y);
        i--;
        x += 5;
    }
}

/* Payline markers for the current bet (blinking while unk96 is set). */
// JokerStars_DrawPaylines @ 0x08144998
void JokerStars_DrawPaylines(void)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;
    u32 i;

    if (s->bet != 0 && (s->unk96 == 0 || !((gFrameCounter >> 4) & 1)))
    {
        for (i = 0; i < s->bet; i++)
            Sprite_Draw(gUnknown_0879A2E4[i], 1, 0, 0, 0, gUnknown_0879A2C4[i][0], gUnknown_0879A2C4[i][1]);
    }
}

/* Picks reel `reel`'s strip for the current machine and a random start symbol. */
// JokerStars_RandomizeReel @ 0x08144A08
void JokerStars_RandomizeReel(u16 reel)
{
    struct CasinoScene *scene = (struct CasinoScene *)0x0203B554;
    struct JokerStars *s = (struct JokerStars *)gMenuState;
    const u16 **row = gUnknown_0879C6A4[scene->arg];

    s->strip[reel] = row[reel];
    s->pos[reel].v = ((Random_Byte() * 24) >> 8) * 20 << 16;
}

// JokerStars_Init @ 0x08144A58
void JokerStars_Init(void)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;
    u32 i;

    CpuFill32(0, s, 0x800);
    REG_BG0CNT = 0x4008;
    gUnk_03000002 = 0;
    gUnk_03000040 = 0;
    DmaFill32(3, 0, (void *)0x02005004, 0x2000);
    s->state = 1;
    JokerStars_SetSlot(0, 0, 0, 0);
    JokerStars_SetSlot(1, 0, 0, 0);
    JokerStars_SetSlot(2, 1, 0, 0);
    JokerStars_SetSlot(3, 1, 0, 0);
    JokerStars_SetSlot(5, 0, 0, 0);
    JokerStars_SetSlot(6, 0, 0, 0);
    JokerStars_SetSlot(7, 0, 0, 0);
    JokerStars_SetSlot(8, 0, 0, 0);
    JokerStars_SetSlot(4, 0, 0, 0);
    JokerStars_SetSlot(10, 0, 0, 0);
    JokerStars_SetSlot(11, 0, 0, 0);
    JokerStars_SetSlot(12, 0, 0, 0);
    JokerStars_SetSlot(13, 0, 0, 0);
    JokerStars_SetSlot(9, 0, 0, 0);
    for (i = 0; i < 9; i++)
        JokerStars_RandomizeReel(i);
}

// JokerStars_RenderReels @ 0x08144B70
void JokerStars_RenderReels(void)
{
    struct JokerStars *s = (struct JokerStars *)gMenuState;

    JokerStars_RenderReel(0, s->pos[0].p.px, s->strip[0]);
    JokerStars_RenderReel(1, s->pos[1].p.px, s->strip[1]);
    JokerStars_RenderReel(2, s->pos[2].p.px, s->strip[2]);
    JokerStars_RenderReel(3, s->pos[3].p.px, s->strip[3]);
    JokerStars_RenderReel(4, s->pos[4].p.px, s->strip[4]);
    JokerStars_RenderReel(5, s->pos[5].p.px, s->strip[5]);
    JokerStars_RenderReel(6, s->pos[6].p.px, s->strip[6]);
    JokerStars_RenderReel(7, s->pos[7].p.px, s->strip[7]);
    JokerStars_RenderReel(8, s->pos[8].p.px, s->strip[8]);
}

// sub_08144C00 @ 0x08144C00
void sub_08144C00(void)
{
    JokerStars_RenderReels();
}
