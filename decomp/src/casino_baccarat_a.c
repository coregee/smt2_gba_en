/* Baccarat: start (0x08145E44). */

#include "global.h"
#include "casino2.h"

// Baccarat_Init @ 0x08145E44
void Baccarat_Init(void)
{
    struct Baccarat *s = gBaccarat;
    u16 i = 0;
    u32 zero = 0;

    CpuSet(&zero, s, 0x05000200);
    REG_BG0CNT = 0x4008;
    gUnk_03000002 = i;
    gUnk_03000040 = i;
    s->state = 1;
    s->coinsTarget = s->coins = sub_080C31F0() * 100;
    s->cursor = 0x1E;
    s->unk03C = 0x154;
    s->unk03E = 0x40;
    s->unk040 = 0x50;
    s->obj[0].x = 0x3A;
    s->obj[0].y = 0x25;
    s->obj[1].x = 0x3A;
    s->obj[1].y = 0x4B;
    s->obj[2].x = 0x3A;
    s->obj[2].y = 0x4B;
    for (; i < 6; i++)
    {
        s->card[i].pos = 0xFC;
        s->card[i].target = gUnknown_0879C8EC[i].target;
        s->card[i].unk06 = gUnknown_0879C8EC[i].unk06;
        s->card[i].unk08 = gUnknown_0879C8EC[i].unk08;
    }
    for (i = 0; i < 64; i++)
    {
        s->rec[i].unk00 = 0;
        s->rec[i].unk04 = 0;
    }
}
