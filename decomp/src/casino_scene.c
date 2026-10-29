/* Casino scene loader (0x0813EE90-0x0813F167): entry, main callbacks and the handlers the
   scene command scripts call to load tiles, palettes and tilemaps. */

#include "global.h"
#include "casino.h"

/* Starts casino game `game` (scene arg `arg`): clears the scene header and switches the
   main callback to the loader. */
// Casino_Start @ 0x0813EE90
void Casino_Start(u16 game, u16 arg)
{
    struct CasinoScene *scene = (struct CasinoScene *)0x0203B554;

    CpuFill32(0, scene, 0x300);
    scene->game = game;
    scene->arg = arg;
    SetMainCallback(Casino_InitCallback);
}

// Casino_InitCallback @ 0x0813EED0
void Casino_InitCallback(void)
{
    struct CasinoScene *scene = (struct CasinoScene *)0x0203B554;

    sub_080C1450();
    DmaFill32(3, 0, gUnk_02000000, 0x1000);
    DmaFill32(3, 0, (void *)0x06000000, 0x4000);
    Font_ResetGlyphSpriteCache(0x180);
    gUnknown_0879241C[scene->game]();
    SetMainCallback(Casino_MainCallback);
}

// Casino_MainCallback @ 0x0813EF40
void Casino_MainCallback(void)
{
    struct CasinoScene *scene = (struct CasinoScene *)0x0203B554;

    Task_RunAll();
    gUnknown_0879243C[scene->game]();
}

// CasinoScene_LoadTiles @ 0x0813EF64
void CasinoScene_LoadTiles(u32 unused, const void *src, u32 slot)
{
    HuffUnComp(src, gBgPictureBuffer);
    LZ77UnCompWram(gBgPictureBuffer, (void *)(0x02001000 + (slot << 12)));
}

// CasinoScene_DmaBgTiles @ 0x0813EF90
void CasinoScene_DmaBgTiles(void)
{
    DmaSet(3, 0x02001000, 0x06008000, 0x84002000);
}

// CasinoScene_QueueBgTiles @ 0x0813EFB4
void CasinoScene_QueueBgTiles(void)
{
    VBlankTask_AddCounted(CasinoScene_DmaBgTiles, 1);
}

// CasinoScene_DmaObjTiles @ 0x0813EFC8
void CasinoScene_DmaObjTiles(void)
{
    DmaSet(3, 0x02001000, 0x06010000, 0x84002000);
}

// CasinoScene_QueueObjTiles @ 0x0813EFEC
void CasinoScene_QueueObjTiles(void)
{
    VBlankTask_AddCounted(CasinoScene_DmaObjTiles, 1);
}

// CasinoScene_LoadBgPalette @ 0x0813F000
void CasinoScene_LoadBgPalette(u32 unused, const void *src)
{
    LZ77UnCompWram(src, gBgPictureBuffer);
    Palette_CopyWithEffect(3, gBgPictureBuffer, gPaletteTarget, 0x200, 0x20);
}

// CasinoScene_LoadObjPalette @ 0x0813F030
void CasinoScene_LoadObjPalette(u32 unused, const void *src)
{
    LZ77UnCompWram(src, gBgPictureBuffer);
    Palette_CopyWithEffect(3, gBgPictureBuffer, gPaletteTarget + 0x100, 0x200, 0x20);
}

// CasinoScene_DmaBgMap0 @ 0x0813F060
void CasinoScene_DmaBgMap0(void)
{
    DmaSet(3, gUnk_02000000, 0x06000000, 0x84000140);
}

// CasinoScene_DmaBgMap1 @ 0x0813F080
void CasinoScene_DmaBgMap1(void)
{
    DmaSet(3, gUnk_02000000, 0x06001000, 0x84000140);
}

// CasinoScene_DmaBgMap2 @ 0x0813F0A4
void CasinoScene_DmaBgMap2(void)
{
    DmaSet(3, gUnk_02000000, 0x06002000, 0x84000140);
}

// CasinoScene_DmaBgMap3 @ 0x0813F0C8
void CasinoScene_DmaBgMap3(void)
{
    DmaSet(3, gUnk_02000000, 0x06003000, 0x84000140);
}

// CasinoScene_LoadBgMap @ 0x0813F0EC
void CasinoScene_LoadBgMap(u32 unused, const void *src, u32 layer)
{
    LZ77UnCompWram(src, gUnk_02000000);
    switch (layer)
    {
    case 0:
        VBlankTask_AddCounted(CasinoScene_DmaBgMap0, 1);
        break;
    case 1:
        VBlankTask_AddCounted(CasinoScene_DmaBgMap1, 1);
        break;
    case 2:
        VBlankTask_AddCounted(CasinoScene_DmaBgMap2, 1);
        break;
    case 3:
        VBlankTask_AddCounted(CasinoScene_DmaBgMap3, 1);
        break;
    }
}

// CasinoScene_FadeIn @ 0x0813F144
void CasinoScene_FadeIn(void)
{
    PalFade_FadeInFromBlack(1);
}

// CasinoScene_FadeOut @ 0x0813F150
void CasinoScene_FadeOut(void)
{
    PalFade_FadeToBlack(1);
}

// sub_0813F15C @ 0x0813F15C
void sub_0813F15C(void)
{
    sub_080AB1A8();
}
