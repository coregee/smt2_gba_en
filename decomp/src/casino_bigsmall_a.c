/* Casino minigame started by 0x08149BBC. */

#include "global.h"
#include "casino2.h"

// BigSmall_Init @ 0x08149BBC
void BigSmall_Init(void)
{
    struct C145Game5 *s = gGame5;
    u32 zero = 0;

    CpuSet(&zero, s, 0x05000200);
    REG_BG0CNT = 0x4008;
    gUnk_03000002 = 0;
    gUnk_03000040 = 0;
    s->state = 1;
    s->coins = sub_080C31F0();
    s->unk00F = 8;
    s->unk018 = 1;
    s->pickBig = 1;
    s->unk040 = 0x154;
    s->unk042 = 0x40;
    s->unk044 = 0x50;
    switch (gUnk_03004614)
    {
    case 3:
        s->variant = 0;
        break;
    case 0x26:
        s->variant = 1;
        break;
    case 0x30:
        s->variant = 2;
        break;
    case 0x40:
        s->variant = 3;
        break;
    }
}
