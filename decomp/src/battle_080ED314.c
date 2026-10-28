#include "global.h"
#include "battle.h"

// sub_080ED314 @ 0x080ED314
void sub_080ED314(void)
{
    BFLOW->unk118C += 2;
}

// sub_080ED32C @ 0x080ED32C
u16 sub_080ED32C(u16 i)
{
    return gUnknown_0876E6D4[i];
}

// sub_080ED33C @ 0x080ED33C
s32 sub_080ED33C(void)
{
    s32 n = 1;

    do
    {
        if (n > 4)
            break;
        if (Random_Byte() & 0xF)
            break;
        n++;
    } while (1);
    return n;
}


// sub_080ED35C @ 0x080ED35C
void sub_080ED35C(u32 *a, s32 *b, s8 idx)
{
    const u8 *p = &gUnknown_0876E978[(u8)idx * 4];

    *a = p[1];
    *b = sub_080ED600(p[0] & 0xF) + 1;
    BFLOW->unk984 = p[0];
}
