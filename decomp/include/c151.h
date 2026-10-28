#ifndef GUARD_C151_H
#define GUARD_C151_H

#include "global.h"

typedef void (*VoidFunc)(void);

/* World (overworld) map record, 0xD8 bytes each at gFieldMapAreas. */
struct MapRecord
{
    const void *gfx[8];             /* 0x00: Huffman+LZ77 tile sheets */
    const void *maps[2][16];        /* 0x20: tilemaps per BG layer; maps[l][1] != 0 means
                                       the layer is decompressed into EWRAM */
    u32 unkA0;                      /* palette */
    u32 unkA4;
    const void *objGfx[8];          /* 0xA8 */
    u16 width;                      /* 0xC8: pixels */
    u16 height;                     /* 0xCA */
    u16 originX;                    /* 0xCC: map cells */
    u16 originY;                    /* 0xCE */
    u8 padD0[8];
};

/* World-map state at 0x030069F0 (0x3C bytes, saved with the game). */
struct WorldMap
{
    u32 state;      /* 0x00 */
    u16 mode;       /* 0x04 */
    u16 unk06;
    u16 map;        /* 0x08 */
    u16 unk0A;
    u16 x;          /* 0x0C: pixels */
    u16 y;          /* 0x0E */
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 unk1A;      /* raster line counter */
    u16 unk1C;
    u16 unk1E;
    u16 unk20;
    u16 unk22;
    u16 unk24;
    u16 unk26;
    u16 unk28;
    u16 unk2A;
    u16 unk2C;
    u16 unk2E;
    u16 unk30;
    u16 unk32;
    u16 unk34;
    u16 unk36;
    u16 unk38;
    u16 unk3A;
};

struct GameState
{
    u8 pad0000[0x18C0];
    u8 unk18C0;
    u8 unk18C1;
    u8 unk18C2;
    u8 unk18C3;
    u8 pad18C4[2];
    u8 unk18C6;
};

struct WarpEntry
{
    u8 map;
    u8 kind;
    u16 x;
    u16 y;
    u8 vals[10];
};

extern struct WorldMap gWorldMap;
extern struct GameState gGameState;
extern struct MapRecord gFieldMapAreas[];
extern const u16 gUnknown_087DF93C[];
extern u16 gWarpDest[];
extern u32 gUnk_03004614;
extern u8 gUnk_0200F874[];
extern u8 gUnk_0201F874[];
extern VoidFunc gIntrTable[14];
extern u16 gPaletteTarget[0x200];

extern u8 gUnk_03000030, gUnk_03000031, gUnk_03000034, gUnk_03000035, gUnk_03000038;
extern const u16 gUnknown_087DF95C[];
extern const u32 gUnknown_087DFBA0[], gUnknown_087DFEF0[], gUnknown_087DFF58[], gUnknown_087DFFC0[],
    gUnknown_087E0998[], gUnknown_087E0DA0[], gUnknown_087E0F54[], gUnknown_087E0DD0[],
    gUnknown_087E0028[], gUnknown_087E0090[], gUnknown_087E0120[];
extern u8 gUnk_02000000[];
extern u8 gUnk_02000800[];
extern u8 gUnk_02001000[];
extern u8 gUnk_02005004[];
extern u8 gBgPictureBuffer[];
extern u8 gUnk_02030C74[];
extern const u8 gUnknown_087DDE08[], gUnknown_087DE4C8[];
extern const u16 gUnknown_087DE8C4[];
extern const u16 gUnknown_087DFB88[];
extern const u16 gUnknown_087DFB90[];
extern const struct WarpEntry gUnknown_087DFAD8[];
extern const u16 gUnknown_087DFA58[][2];

u32 Flag_Test(u32 flag);
void CpuSet(const void *src, void *dest, u32 control);
void HuffUnComp(const void *src, void *dest);
void LZ77UnCompWram(const void *src, void *dest);
void VBlankTask_AddCounted(void (*func)(void), u32 count);
void VBlankTask_AddAlways(void (*func)(void));
struct Task *Task_Create(const void *script, u32 parent);
void sub_080C2F44(u32 a, u32 b, u32 c);
void sub_080C67C0(void *a, u32 b);
void Palette_CopyWithEffect(u32 a0, const void *src, void *dst, u32 a3, u32 a4);

struct MapRecord *FieldMap_GetArea(u16 id);
void *sub_08151FD8(u16 layer);
void sub_0815201C(void);
void WorldMap_StartWindowRaster(void);
void WorldMap_WindowRasterIrq(void);
void WorldMap_InstallWindowRaster(void);
void WorldMap_CopyTilemapView(const u16 *src, u16 *dst, u16 x, u16 y, u16 width, u16 height);
void WorldMap_UpdateLayer(u16 a);
void WorldMap_UploadTiles(void);
void sub_08152708(void);
void sub_0815272C(void);
void sub_08152824(void);
u8 *WorldMap_GetBlocks(void);
void WorldMap_TryStep(u16 a);
void WorldMap_UpdateScroll(void);
void WorldMap_HandleInput(void);
void WorldMap_Walk(void);
void WorldMap_DrawSprites(void);
void WorldMap_AnimateTiles(void);

#endif /* GUARD_C151_H */
