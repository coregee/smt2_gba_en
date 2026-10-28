#include "global.h"
#include "c0ed.h"

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
        if (sub_080C2244() & 0xF)
            break;
        n++;
    } while (1);
    return n;
}

