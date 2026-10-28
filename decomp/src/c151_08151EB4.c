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
// FieldMap_GetArea @ 0x08151EB4
struct MapRecord *FieldMap_GetArea(u16 id)
{
    if (id == 2 && !Flag_Test(0x11))
        id = 10;
    if (id == 5 && !Flag_Test(0xEC))
        id = 11;
    return &gFieldMapAreas[id];
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
        CpuSet(&zero, &gWorldMap, 0x0500000F);
        if (mode != 3)
        {
            gWorldMap.map = gGameState.unk18C6;
            gWorldMap.x = gGameState.unk18C0 * 16 + 8;
            gWorldMap.y = gGameState.unk18C1 * 16;
        }
        else
        {
            struct MapRecord *rec;
            u16 m = gWarpDest[4] >> 4;
            if (gUnknown_087DF93C[m] != 0xFFFF)
                m = gUnknown_087DF93C[m];
            gWorldMap.map = m;
            rec = FieldMap_GetArea(gWorldMap.map);
            gWorldMap.x = (gWarpDest[2] - rec->originX) * 16 + 8;
            gWorldMap.y = (gWarpDest[3] - rec->originY) * 16;
        }
        WorldMap_UpdateLayer(0);
        break;
    }
    case 2:
        gWorldMap.x = gWorldMap.unk10;
        gWorldMap.y = gWorldMap.unk12;
        break;
    }
    gWorldMap.state = 0;
    gWorldMap.mode = mode;
    WorldMap_UpdateScroll();
    WorldMap_InstallWindowRaster();
}

// sub_08151FD8 @ 0x08151FD8
void *sub_08151FD8(u16 layer)
{
    struct MapRecord *rec = FieldMap_GetArea(gWorldMap.map);
    if (rec->maps[layer][1] == 0)
        return (void *)rec->maps[layer][0];
    if (layer == 0)
        return gUnk_0200F874;
    return gUnk_0201F874;
}

