#include "global.h"
#include "c151.h"

#define DMA3_SET(src, dest, control)                     \
{                                                        \
    vu32 *dmaRegs = (vu32 *)0x040000D4;                  \
    dmaRegs[0] = (u32)(src);                             \
    dmaRegs[1] = (u32)(dest);                            \
    dmaRegs[2] = (u32)(control);                         \
    dmaRegs[2];                                          \
}

/* Maps 2 and 5 use alternate records (10, 11) until flags 0x11 / 0xEC are set. */
// sub_08151EB4 @ 0x08151EB4
struct MapRecord *sub_08151EB4(u16 id)
{
    if (id == 2 && !Flag_Test(0x11))
        id = 10;
    if (id == 5 && !Flag_Test(0xEC))
        id = 11;
    return &gUnknown_087DE924[id];
}

// sub_08151EEC @ 0x08151EEC
void sub_08151EEC(u32 a0, u32 a1, u16 mode)
{
    gUnk_03004614 = 0;
    switch (mode)
    {
    case 1:
        break;
    case 0:
    case 3:
    {
        u32 zero = 0;
        CpuSet(&zero, &gUnk_030069F0, 0x0500000F);
        if (mode != 3)
        {
            gUnk_030069F0.map = gGameState.unk18C6;
            gUnk_030069F0.x = gGameState.unk18C0 * 16 + 8;
            gUnk_030069F0.y = gGameState.unk18C1 * 16;
        }
        else
        {
            struct MapRecord *rec;
            u16 m = gUnk_03003FD0[4] >> 4;
            if (gUnknown_087DF93C[m] != 0xFFFF)
                m = gUnknown_087DF93C[m];
            gUnk_030069F0.map = m;
            rec = sub_08151EB4(gUnk_030069F0.map);
            gUnk_030069F0.x = (gUnk_03003FD0[2] - rec->originX) * 16 + 8;
            gUnk_030069F0.y = (gUnk_03003FD0[3] - rec->originY) * 16;
        }
        sub_0815251C(0);
        break;
    }
    case 2:
        gUnk_030069F0.x = gUnk_030069F0.unk10;
        gUnk_030069F0.y = gUnk_030069F0.unk12;
        break;
    }
    gUnk_030069F0.state = 0;
    gUnk_030069F0.mode = mode;
    sub_08152EF8();
    sub_08152420();
}

// sub_08151FD8 @ 0x08151FD8
void *sub_08151FD8(u16 layer)
{
    struct MapRecord *rec = sub_08151EB4(gUnk_030069F0.map);
    if (rec->maps[layer][1] == 0)
        return (void *)rec->maps[layer][0];
    if (layer == 0)
        return gUnk_0200F874;
    return gUnk_0201F874;
}

