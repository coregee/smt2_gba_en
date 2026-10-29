#ifndef GUARD_WORLDMAP_H
#define GUARD_WORLDMAP_H

#include "global.h"

typedef void (*VoidFunc)(void);

/* World (overworld) map record, 0xD8 bytes each at gFieldMapAreas. */
struct MapRecord
{
    const void *gfx[8];             /* 0x00: Huffman+LZ77 tile sheets */
    const void *maps[2][16];        /* 0x20: tilemaps per BG layer */
    u32 unkA0;                      /* palette */
    u32 unkA4;
    const void *objGfx[8];          /* 0xA8: block data */
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
    u32 unk2C;
    u16 unk30;
    u16 unk32;
    u16 unk34;
    u16 unk36;
    u16 unk38;
    u16 unk3A;
};

/* Decompressed area work buffer: tiles then a byte per 16x16 block at +0x2000 (64 per row). */
struct FieldBlocks
{
    u8 walk[128][64];               /* low nibble 0 = blocked */
    u8 blocks[0x2000];              /* high nibble: zone */
};

struct WarpEntry
{
    u8 map;
    u8 kind;
    u16 x;
    u16 y;
    u8 vals[10];
};

/* Overworld position record (8 bytes, copied whole from the area's event records). */
struct WorldPos
{
    u8 unk0;
    u8 unk1;
    u8 x;           /* world cell */
    u8 y;
    u8 unk4;
    u8 unk5;
    u8 map;
    u8 unk7;
} __attribute__((aligned(4)));


extern struct WorldMap gWorldMap;
extern u16 gWarpDest[];
extern vu16 gKeysNew;
extern u16 gUnk_030031D0;
extern u16 gUnk_03000008, gUnk_0300000A, gUnk_0300000C, gUnk_0300000E;
extern u16 gPaletteTarget[0x200];
extern u16 gPaletteBuffer[0x200];
extern const u8 gUnknown_0803AE54[];
extern const u8 gUnknown_0804AE3C[];
extern const u8 gUnknown_081988DC[];
extern u8 gBgPictureBuffer[];
extern u8 gUnk_02000000[];
extern u8 gUnk_02000800[];
extern u8 gUnk_02001000[];
extern u8 gUnk_02005004[];
extern u8 gUnk_0200F874[];
extern u8 gUnk_0201F874[];
extern u8 gUnk_02030C74[];
extern const u8 gUnknown_087DDE08[], gUnknown_087DE4C8[];
extern const u16 gUnknown_087DE8C4[];
extern const u16 gUnknown_087DFB88[];
extern const u16 gUnknown_087DFB90[];
extern struct MapRecord gFieldMapAreas[];
extern VoidFunc gIntrTable[14];
extern u8 gUnk_03000030, gUnk_03000031, gUnk_03000034, gUnk_03000035, gUnk_03000038;
extern const u16 gUnknown_087DF95C[];
extern const u32 gUnknown_087DFBA0[], gUnknown_087DFEF0[], gUnknown_087DFF58[], gUnknown_087DFFC0[],
    gUnknown_087E0998[], gUnknown_087E0DA0[], gUnknown_087E0F54[], gUnknown_087E0DD0[],
    gUnknown_087E0028[], gUnknown_087E0090[], gUnknown_087E0120[];
extern const u16 gUnknown_087DFA58[][2];
extern const struct WarpEntry gUnknown_087DFAD8[];

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
void FieldMap_LoadTiles(u32 unused, u32 k);
void FieldMap_LoadBlockData(u32 unused, u32 k);
void FieldMap_LoadMapChunk(u32 unused, u32 k);
void WorldMap_UploadTiles(void);
void WorldMap_QueueTileUpload(void);
void sub_08152708(void);
void sub_0815272C(void);
void WorldMap_DrawLayer(u32 unused, u32 layer, u32 kind);
void WorldMap_LoadPalette(void);
void sub_08152824(void);
void WorldMap_LoadObjGfx(void);
void sub_081528B4(void);
struct FieldBlocks *WorldMap_GetBlocks(void);
u32 WorldMap_TryStep(u16 keys);
void WorldMap_UpdateScroll(void);
void sub_08153C14(u16 *x, u16 *y);
u32 sub_0812A7C4(void);
u32 Random_Byte(void);
s32 Encounter_Check(u32 a);
void *sub_080C1B74(u16 *a, u16 *b);
void sub_080C2168(void);
void sub_080C1DE0(void);
u32 sub_080C8B3C(u16 map);
u16 *DungeonMap_GetFloor(u16 map, u16 floor);
s32 SubMap_IsOutsideExclusions(void *h, u16 x, u16 y);
void sub_080C2D78(s8 a, s8 b);
void sub_080C2DC0(u32 a);
void sub_080C2DE0(u32 a, const void *b);
void sub_080C2E10(u32 a, u16 b);
void sub_080C2E44(u32 a, const void *b);
void *PalFade_FadeRangeWithDuration(u16 start, u16 count, u16 delay, u16 duration);
void Palette_MarkDirty(void);

struct Pair32
{
    u32 a, b;
};

/* Overworld event (8 bytes): runs script when the player stands on world cell (x & 0x7F, y). */
struct FieldEvent
{
    u8 x;
    u8 y;
    u8 map;
    u8 unk3;            /* matched against gWorldMap.unk1C */
    const u8 *script;
};

extern const struct WorldPos gUnknown_087DF344[];
extern const struct FieldEvent gUnknown_087DF54C[];
extern const u8 gUnknown_080560B6[], gUnknown_08056154[], gUnknown_080561F2[], gUnknown_08056290[],
    gUnknown_0805632E[], gUnknown_080563CC[], gUnknown_0805646A[], gUnknown_08056508[];
u32 ScriptVM_RunAlt(const u8 *script);

void WorldMap_HandleInput(void);
void WorldMap_Walk(void);
u16 WorldMap_GetDungeonAt(void);
void WorldMap_EnterLocation(void);
void sub_081532B0(void);
void sub_081532DC(void);
void sub_081532F4(void);
void sub_08153310(void);
void sub_08153324(void);
void sub_08153360(void);
void sub_08153378(const void *src, u16 line, u16 count);
void sub_081533A8(const void *src, u16 line, u16 count);
struct WorldPos *WorldMap_FindLocation(u16 x, u16 y, u16 map);
struct WorldPos *WorldMap_FindLocationByWorldPos(u16 x, u16 y);
struct FieldEvent *WorldMap_FindEvent(u16 x, u16 y, u16 map);
u32 WorldMap_GetEncounterTerrain(void);
u32 WorldMap_CheckSpecialEncounter(void);
u32 sub_081537C4(void);
void WorldMap_DrawSprites(void);
void WorldMap_AnimateTiles(void);

#define DMA3_SET(src, dest, control)                     {                                                            vu32 *dmaRegs = (vu32 *)0x040000D4;                      dmaRegs[0] = (u32)(src);                                 dmaRegs[1] = (u32)(dest);                                dmaRegs[2] = (u32)(control);                             dmaRegs[2];                                          }

#define DmaFill16_3(value, dest, control)        {                                                    vu16 tmp = (vu16)(value);                        DMA3_SET(&tmp, dest, control);               }

struct Task
{
    u16 state;
    u16 id;
    u16 parent;
    u16 pad06;
    u32 op;
    s32 wait;
    s32 pc;
    const u32 *script;
    u16 loopCount;
    u16 loopStart;
    u16 result;         /* 0x1C */
    u16 pad1E;
    void (*onFrame)(struct Task *);
    union
    {
        u32 w[0x10];
        u16 h[0x20];
        u8 raw[0x40];
    } data;             /* 0x24 */
};

/* Terrain pairs at 0x087E0188: area ids of the tiles on both sides of a step -> battle background. */
struct TerrainPair
{
    u8 a;
    u8 b;
    u8 bg;
    u8 pad;
};

extern const struct TerrainPair gUnknown_087E0188[];
extern const u16 gUnknown_087E043C[][2];
extern const u8 gUnknown_087E04A4[], gUnknown_087E0788[];
extern const u16 gUnknown_087E0978[];
extern u16 gUnk_03000004, gUnk_03000006;
u32 __umodsi3(u32 a, u32 b);
void Tilemap_OffsetRect(void *map, u16 tileAdd, u16 palette, u16 x, u16 y, u16 w, u16 h);
void *PalFade_FadeRangeInFromBlack(u16 start, u16 count, u16 delay);
void *PalFade_FadeRangeToBlackWithDuration(u16 start, u16 count, u16 delay, u16 duration);

/* Overworld sprite (16 bytes at 0x087E0F84, map 0xFFFF ends): shown while flag is set. */
struct MapSprite
{
    u16 map;
    u16 x;
    u16 y;
    u16 flag;
    const void *sprite;
    u16 palette;
    u16 pad;
};

extern const struct MapSprite gUnknown_087E0F84[];
extern const void *const gUnknown_087E0FD4[];
extern const u8 gUnknown_0800790C[];
extern const u16 gUnknown_081B8270[];
extern u32 gFrameCounter;
void Sprite_Draw(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
void *PalFade_FadeRangeToBlack(u16 start, u16 count, u16 delay);
void Music_FadeOut(u32 a);
u16 sub_080AD67C(u16 id);
void Music_Play(u32 a);
void Tilemap_CopyRectSkipZero(const void *src, void *buf, u32 a2, u32 a3, u32 x, u32 y, u32 w, u32 h);
void Flag_Set(u32 flag);

u16 WorldMap_GetStepDirection(void);
u32 WorldMap_GetNeighbourTerrain(void);
void sub_08153810(void);
void sub_08153834(void);
void sub_08153860(void);
void sub_08153890(void);
void sub_08153938(void);
void sub_08153974(struct Task *task);
void sub_08153990(u32 unused, u32 step);
void sub_08153A90(u32 unused, u32 on);
void sub_08153B0C(void);
void sub_08153B28(struct Task *task, u32 dx, u32 dy, const void *script);
void sub_08153BA0(struct Task *task, u32 dx, u32 dy, u32 x, u32 y);
void WorldMap_ToScreen(u16 x, u16 y, u16 *sx, u16 *sy);
void sub_08153D40(void);
void sub_08153D64(void);
void WorldMap_LoadAnimTiles(void);
extern const u8 gUnknown_087C5E10[], gUnknown_087C6358[];

struct CombatantStats
{
    u8 v[6];
    u8 pad[2];
};

/* One party member / stock demon / enemy: 0x80 bytes (gGameState.members[], battle units). */
struct Combatant
{
    u8 name[8];
    u32 unk8;
    u8 id;              /* 0x0C */
    u8 level;           /* 0x0D */
    u16 unkE;           /* 0x0E */
    u16 flags;          /* 0x10 */
    s16 demonId;        /* 0x12 */
    s16 unk14;
    u16 unk16;
    s16 hp;             /* 0x18 */
    s16 maxHp;          /* 0x1A */
    s16 mp;             /* 0x1C */
    s16 maxMp;          /* 0x1E */
    s8 equip[7];        /* 0x20 */
    u8 pad27;
    struct CombatantStats base;     /* 0x28 */
    struct CombatantStats bonus;    /* 0x30 */
    struct CombatantStats extra;    /* 0x38 */
    struct CombatantStats total;    /* 0x40 */
    s16 derived[8];     /* 0x48 */
    u16 unk58;
    u8 pad5A[3];
    u8 skills[32];      /* 0x5D */
    u8 pad7D[3];
};

struct GameState
{
    struct Combatant members[48];   /* 0x0000: 0..3 humans, 4..15 demon stock */
    u8 pad1800[0xC0];
    struct WorldPos pos;            /* 0x18C0 */
};

extern struct GameState gGameState;
#define gCombatants (gGameState.members)

struct FadeTask
{
    u8 pad0[0xC];
    s32 state;      /* 0x0C: -1 when done */
};

/* BEGIN GENERATED */
struct FusionMenu
{
    u16 mode;    /* 0x0: 1..5: which list / fusion kind */
    u16 unk2;    /* 0x2 */
    u8 pad0004[0x4];
    u16 sel;    /* 0x8 */
    u8 pad000A[0x2];
    struct FadeTask *fade;    /* 0xC */
    u8 pad0010[0xC];
    struct Combatant *members[12];    /* 0x1C: combatant records of the listed demons */
    struct Combatant *picks[3];    /* 0x4C */
    u8 pad0058[0x606];
    u16 count;    /* 0x65E */
    u8 pad0660[0xC];
    u16 pairs[12][2];    /* 0x66C */
    u8 pad069C[0xD78];
};

struct FusionCalc
{
    u8 pad0000[0x90];
    u16 ids[3];    /* 0x90: the materials, sorted */
    u8 pad0096[0xA];
    u16 result;    /* 0xA0 */
    u8 pad00A2[0x4];
    u8 unkA6;    /* 0xA6 */
    u8 pad00A7[0x19];
};
/* END GENERATED */

#define sFusion (*(struct FusionMenu *)gMenuState)
extern u16 gMenuState[];
extern struct FusionCalc gUnk_0203B868;
extern u16 gUnk_0203B854[];   /* chosen materials */
extern struct Combatant gUnk_030048C0[];
s32 Combatant_IsUsed(s32 id);
s32 Combatant_IsDead(s32 id);
void Canvas_BlitOrTinted(const u8 *src, u8 *dst, u16 srcX, u16 srcY, u16 dstX, u16 dstY, u16 w, u16 h, u8 tint);
u8 *Font_GetGlyphBitmap(u16 code);
void sub_0815B880(u16 n);
extern u32 gUnk_03003BB4;
extern const u8 gUnknown_087E0FE4[];
extern const u16 gUnknown_087E1BE4[];
u32 Fusion_IsRandomResult(void);
void Fusion_CalcTwo(void);
void Fusion_CheckResult(void);
void Fusion_CalcThree(void);
u32 Fusion_CalcItem(void);
s32 sub_0815B958(u16 id);
u16 sub_08153E24(u16 id);
u32 Stock_CountLiving(void);
void Fusion_ClearList(void);
u16 Fusion_BuildList(void);
void sub_08153F08(void);
u16 Fusion_CountList(void);
void sub_08153F6C(u16 i);
void sub_08153F8C(u16 icon, u8 *dst, u16 x, u16 y, u8 tint);
void sub_08153FC8(u16 glyph, u8 *dst, u16 x, u16 y, u8 tint);
void sub_08154038(u16 icon, u16 x, u16 y, u32 tint);
void Fusion_SortMaterials(void);
u8 Fusion_GetPairIcon(u16 id, u16 slot);
u16 Fusion_FindListSlot(u16 id);
u16 Stock_FindSlotByDemonId(u16 id);
void sub_0815438C(u16 id, u16 slot, u16 x, u16 y);
u32 Fusion_GetDemonByIndex(u16 id);
void sub_081543E8(struct FusionMenu *f, u16 sel, u16 y);
u32 sub_081544AC(u16 id);
void sub_0815468C(void);
void sub_08154698(void);
void sub_081546B4(struct Task *task);
void sub_081546D8(void);
u32 Fusion_AllHighRace(u16 a, u16 b, u16 c);
u32 Fusion_CanCreate(u16 a, u16 b, u16 c, u16 id);
void Fusion_DrawDemonName(u16 id, u16 x, u16 y, u16 tint);
void sub_08154900(u16 x, u16 y);
u16 Fusion_GetIndexByDemon(u16 id);
void Fusion_DrawLevel(u16 n, u16 x, u16 y, u16 tint);
void Field_SetState(u16 state);
void *sub_080B6B58(void (*func)(void), u32 a);
u8 *NumberToDigits(u32 n);
void DigitFont_DrawStringTinted(const u8 *str, u8 *canvas, u16 x, u16 y, u8 tint, u16 advance);
s8 *Demon_GetRecord(u16 id);
struct Combatant *Party_GetMember(u16 id);
struct Combatant *Stock_FindByDemonId(u16 demonId);
s16 sub_08134C3C(u16 id);
void Font_DrawGlyphTinted(u16 code, u8 *canvas, u16 x, u16 y, u8 tint);
const u16 *Race_GetName(u16 race);
void Fusion_DrawListRow(struct FusionMenu *f, u16 row, u16 y);
void sub_08154EC0(void);
void sub_08154EEC(void);
void Fusion_DrawListHeader(void);
void Fusion_DrawList(u16 top);
u32 sub_0815BAC4(s16 demonId);
void sub_0815B884(u16 a, u16 b, u16 c, u16 *out);
u8 Inventory_GetCount(u16 id);
void SmallFont_DrawAsciiTinted(const u8 *str, u8 *canvas, u16 x, u16 y, u8 tint, u16 advance);
extern const u8 gUnknown_087E13E4[];
extern const u8 gUnknown_087E1C2C[], gUnknown_087E1C34[], gUnknown_087E1C3C[], gUnknown_087E1C44[];
extern const u8 gUnknown_081B93B0[];
extern u16 gUnk_03000040;
extern u8 gDigits[8];
extern const u16 gUnknown_087E1956[];
extern const u16 gUnknown_087E1BF6[];   /* demon id per fusion index (id - 0x150) */

#endif /* GUARD_WORLDMAP_H */
