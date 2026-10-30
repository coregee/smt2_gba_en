#include "global.h"
#include "battle.h"

/* defined in battle_080ED314.c returning u16; this caller re-extends the result */
u32 sub_080ED32C(u16 i);
u8 Battle_GetActionAnim(u16 a, u16 b);

struct F104CEntry
{
    u8 id[2];
    u16 alt;
};
extern const struct F104CEntry gUnknown_0876E1D8[];

// sub_080F104C @ 0x080F104C
u16 sub_080F104C(u16 a, u16 b)
{
    u8 v;

    if (gUnknown_0876E1D8[a].id[b] > 0xD1)
    {
        v = Battle_GetActionAnim(a, b);
        if (v > 0xDB)
            return gUnknown_0876E1D8[a].alt;
    }
    else
        v = gUnknown_0876E1D8[a].id[b];
    return sub_080ED32C(v);
}

