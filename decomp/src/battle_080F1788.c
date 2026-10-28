#include "global.h"
#include "battle.h"

u32 sub_080EDA64(s32 i);
u32 sub_080ED974(s32 who);

// sub_080F1788 @ 0x080F1788
u32 sub_080F1788(s16 i)
{
    u16 side = sub_080ED974(sub_080EDA64(i));
    s16 s = side;

    if (!sub_080EDA24(s))
        side = s ^ 1;
    if (side == 0)
        return 0;
    return 1;
}
