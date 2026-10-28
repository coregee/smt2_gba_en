#ifndef GUARD_FIELDEVENT_H
#define GUARD_FIELDEVENT_H

#include "global.h"

struct Task;
struct TreasureRec;

/* DMA helpers (as in game.h). */
#define DMA_ENABLE      0x8000
#define DMA_START_NOW   0x0000
#define DMA_16BIT       0x0000
#define DMA_32BIT       0x0400
#define DMA_SRC_FIXED   0x0100
#define DMA_DEST_INC    0x0000

#define DmaSet(dmaNum, src, dest, control)                      {                                                                   vu32 *dmaRegs = (vu32 *)(0x040000B0 + 12 * (dmaNum));           dmaRegs[0] = (vu32)(src);                                       dmaRegs[1] = (vu32)(dest);                                      dmaRegs[2] = (vu32)(control);                                   dmaRegs[2];                                                 }

#define DMA_FILL(dmaNum, value, dest, size, bit)                                    {                                                                                       vu##bit tmp = (vu##bit)(value);                                                     DmaSet(dmaNum, &tmp, dest,                                                                 (DMA_ENABLE | DMA_START_NOW | DMA_##bit##BIT | DMA_SRC_FIXED | DMA_DEST_INC) << 16            | ((size)/(bit/8)));                                                     }

#define DmaFill16(dmaNum, value, dest, size) DMA_FILL(dmaNum, value, dest, size, 16)
#define DmaFill32(dmaNum, value, dest, size) DMA_FILL(dmaNum, value, dest, size, 32)

#define DMA_COPY(dmaNum, src, dest, size, bit)                                          DmaSet(dmaNum, src, dest,                                                                  (DMA_ENABLE | DMA_START_NOW | DMA_##bit##BIT | DMA_DEST_INC) << 16                 | ((size)/(bit/8)))

#define DmaCopy16(dmaNum, src, dest, size) DMA_COPY(dmaNum, src, dest, size, 16)
#define DmaCopy32(dmaNum, src, dest, size) DMA_COPY(dmaNum, src, dest, size, 32)

/* Field state at 0x03004550 (copied from field.h). */
struct FieldState
{
    u16 unk00;
    u16 unk02;          /* facing */
    u16 unk04;
    u16 unk06;
    u16 unk08;
    u16 unk0A;
    u16 unk0C;
    u16 unk0E;
    u16 unk10;
    u16 unk12;          /* x */
    u16 unk14;          /* y */
    u16 unk16;
    u16 unk18;
    u16 unk1A;          /* map width */
    u16 unk1C;          /* map height */
    u16 unk1E;
    const u16 *unk20;
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
    vu16 unk38;         /* held keys */
    vu16 unk3A;         /* new keys */
    vu16 unk3C;         /* repeated keys */
    u16 unk3E;
    u32 unk40;
    u16 unk44;
    u16 unk46;
    u16 unk48;
    u16 unk4A;
    u16 unk4C;
    u16 unk4E;
    u16 unk50;
    u16 unk52;
    u16 unk54;
    u16 unk56;
    u16 unk58;
    u16 unk5A;
    u16 unk5C;
    u16 unk5E;
    u16 unk60;
    u16 unk62;
    u32 unk64[0x10];
};
extern struct FieldState gFieldState;

/* Automap: 11 rows of 28 cells at 0x02005000 (copied from field.h). */
struct AutomapCell
{
    u16 flags;          /* 1 = visited square, bit 15 = event */
    u8 x;
    u8 y;
    u16 walls[4];
};
extern struct AutomapCell gAutomapCells[11][28];

/* Map markers (8 bytes each) at 0x03005808. */
struct MapMarker
{
    u8 x;
    u8 y;
    u8 unk2;
    u8 sprite;
    u16 map;
    u16 floor;
};
extern struct MapMarker gMapMarkers[8];

extern u16 gBgPictureBuffer[];
extern u16 gUnk_02000000[][32];    /* BG tilemap work buffer */
extern s16 gUnk_0200DFCE;
extern u16 gUnk_0200DFD2;
extern u16 gUnk_0200DFCA;
extern u16 gUnk_0200DFC8;
extern u32 gUnk_03003FFC;
extern u32 gUnk_03004614;
extern u32 gUnk_03004514;
extern const void *const gUnknown_081629E4[];
extern const void *const gUnknown_081629F8[];
extern const void *const gUnknown_08162A08[];

u16 sub_080C2BF0(void);
u16 Automap_IsVisitedUnchecked(u16 x, u16 y);
void Sprite_Draw(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
void MarkerHeader_DrawLocationName(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
void sub_080C4A4C(u32 a0, u32 a1, u32 x, u32 y);
void sub_080C4AB0(u32 a0, u32 a1, u32 x, u32 y);
void Automap_Build(u32 dir, s32 x, s32 y);
void CpuSet(const void *src, void *dst, u32 control);
s32 FieldMap_CellRecordsAt(u16 x, u16 y);
u16 *FieldMap_FindRecord(s32 recs, u32 type);
u32 Flag_Test(u32 flag);
u16 sub_080B4448(const void *cell);
void VBlankTask_AddCounted(void (*func)(void), u32 arg);

u16 sub_080B447C(void);
void Automap_CellToScreen(u16 x, u16 y, u16 *outX, u16 *outY);
void Automap_DrawMarkerSprite(u16 x, u16 y, const void *sprite);
void Automap_BuildIconMap(void);
void sub_080B5084(void);

extern u16 gPaletteBuffer[0x200];
extern u32 gFrameCounter;
extern u16 gHudState[];
extern struct Task *gUnk_03003FEC;
extern u32 gUnk_03003FF0;
extern u32 gUnk_030045F8;
extern s16 gAutomapScroll;
extern u16 gUnk_0200DFD0;
extern const u32 gTitleMenuLoadScript[];
extern const u16 gUnknown_081B8D70[];
extern const u8 gUnknown_08000410[];
extern const u8 gUnknown_08000470[];
extern const u8 gUnknown_081A91B8[];

void LZ77UnCompWram(const void *src, void *dst);
void sub_080B4B58(void);
void sub_080B4B7C(void);
void sub_080B4BA0(void);
void sub_080B4BC4(void);
void Automap_DrawTilemap(void);
void Automap_BuildAroundPlayer(void);
void Automap_DrawSprites(void);
u32 Automap_HasCells(void);
void Automap_VBlankStep(void);
void sub_080B5D00(void);
void sub_080C14FC(void);
void sub_080C153C(void);
void Palette_FillWithEffect(u32 a0, u32 a1, void *dest, u32 size, u32 a4);
void Palette_MarkDirty(void);
void Font_ResetGlyphSpriteCache(u32 baseTile);
void sub_080C7C60(void);
void sub_080C7C94(void);
void sub_080C7848(void);
void sub_080C7864(void);
void sub_080C7234(void);
void sub_080C700C(void);
void sub_080C7430(void);
struct Task *Task_Create(const void *script, u32 parent);
u32 Window_Create(u32 x, u32 y, u32 w, u32 h, u32 bg);
u32 Window_CreateOpen(u32 x, u32 y, u32 w, u32 h, u32 bg);
s32 Window_IsIdle(u32 win);
void Window_Close(u32 win, u32 erase);
void Sound_Play(u32 se);
void Tilemap_CopyRectSkipZero(const void *src, void *buf, u32 a2, u32 a3, u32 x, u32 y, u32 w, u32 h);
void sub_080B2840(u32 a, u32 b, u32 c);
void sub_080B2880(void);
void Field_SetState(u32 state);
void sub_080ADF64(void);

/* Script task (layout as in field.h; the data area is used per task kind). */
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
    u16 result;
    u16 unk1E;
    void (*onFrame)(struct Task *);
    u8 data[0x40];
};

/* Data of the automap marker task (gUnknown_08162C34). */
struct MarkerMenu
{
    u32 state;          /* 0 list, 1 placing, 2 kind choice, 3 viewing a marker */
    u32 cursor;         /* marker slot 0-7 */
    u32 top;            /* first slot shown (4 rows) */
    u32 kind;           /* marker sprite 0-4 */
    u16 x;              /* cursor cell on the automap */
    u16 y;
    u16 busy;
    u16 pad16;
    u32 window;
    u32 window1;
    u32 window2;
    u32 yesNo;
    u16 savedMap;
    u16 savedFloor;
    u16 savedX;
    u16 savedY;
    u16 savedScroll;
    u16 savedScroll2;
};

extern u16 gRepeatedKeys;
extern u32 gYesNoResult;
extern u16 gUnk_0200DFD2;
extern const u8 gUnknown_08000508[];
extern const u8 gUnknown_08000518[];
extern const u8 gUnknown_080004AC[];
extern const u8 gUnknown_080004C4[];
extern const u8 gUnknown_080004F8[];
extern const u16 gUnknown_08162B0C[];
extern const u16 gUnknown_08162B1C[];
extern const u16 gUnknown_08162B34[];
extern const u16 gUnknown_08162B56[];
extern const u16 gUnknown_08162B76[];
extern const u16 gUnknown_08162B8E[];
extern const u16 gUnknown_08162B9C[];
extern const u16 gUnknown_08162BA8[];
extern const u16 gUnknown_08162BBE[];
extern const u16 gUnknown_08162BD0[];
extern const u16 gUnknown_08162BE4[];
extern const u16 gUnknown_08162BF6[];
extern const u16 gUnknown_08162C06[];
extern const u16 gUnknown_08162C12[];
extern const u16 gUnknown_08162C26[];

void sub_080C6E30(u32 a);
void sub_080C8440(void);
void Text_DrawSpriteString(const u16 *str, u16 a1, u16 a2, u16 x, u16 y, u16 advance);
void MarkerList_DrawLocationName(u16 map, u16 floor, u16 x, u16 y, u16 a4, u16 a5, u16 sx, u16 sy);
u32 TextWindow_CreateOpen(u16 x, u16 y, u16 w, u16 h, u16 screen);
void TextWindow_Close(u32 window, u32 now);
u32 Task_IsFree(u32 task);
u32 YesNo_CreateWithTile(u32 a0, u32 tile);
void sub_080AE234(void);
void MarkerMenu_SetState(struct Task *task, u16 state);
void MarkerMenu_DrawCrosshair(struct Task *task, u16 palette);
void Automap_CellToMap(u16 cx, u16 cy, u16 *x, u16 *y);
u32 MarkerMenu_CanPlace(struct Task *task);
void MarkerMenu_Place(struct Task *task);
void MarkerMenu_Clear(struct Task *task);

/* Save data at 0x030046C0 (only the fields used here; see field.h). */
struct GameState
{
    u8 pad000[0xA20];
    s8 party[0x18];     /* demon ids in the party slots, -1 empty */
    u16 unkA38;         /* map variant */
    u8 padA3A[0xAC0 - 0xA3A];
    u16 unkAC0;
    u8 padAC2[0x18C2 - 0xAC2];
    u8 unk18C2;
    u8 unk18C3;
    u8 pad18C4[0x18D4 - 0x18C4];
    u8 unk18D4;
};
extern struct GameState gGameState;

struct MapVariant
{
    const void *data[0xE8 / 4];
};

struct MapHeader
{
    u8 pad00[8];
    u16 originX;
    u16 originY;
    u8 pad0C[0x90 - 0x0C];
    const u16 *unk90;
    u32 unk94;
    struct MapVariant variants[1];
};

extern u16 gUnk_0300000E;
extern u16 gFieldLoadStep;
extern const void *gUnk_03003BB4;
extern const u16 *gUnk_03004000;
extern const u32 gUnknown_08162C34[];
extern const u32 gUnknown_08162EAC[];
extern const u32 gUnknown_08163060[];
extern const u32 gUnknown_08163278[];
extern const u16 gUnknown_08163250[];
extern const u16 gUnknown_08163258[][4];

void *DungeonMap_GetFloor(u16 map, u16 floor);
s32 FieldMap_CellRecordsRel(u16 fwd, u16 side);
void Map_SetGraphicsPointers(u32 map, u32 sub);
void sub_080AD7F0(void);
void sub_080AE494(void (*func)(void));
void sub_080AE294(void);
void sub_080B0158(void);
void Field_Step(u16 dir);
void Field_LoadGraphicsStep(void);
void Flag_Set(u32 flag);
void Flag_Clear(u32 flag);
u32 Random_Next(void);
void sub_080B2064(u16 dir, u16 b);
s32 sub_080B2090(void);
void Field_HandleInput(u16 keys);
struct Task *Treasure_StartTask(const struct TreasureRec *rec);
u32 sub_080B31C4(u16 unused, u16 type, u16 value);

/* Data of the event-script task (gUnknown_081633D8). */
struct EventTaskData
{
    u16 arg;
    u16 pad02;
    const void *script;
};

/* Data of the location banner task (gUnknown_08163640). */
struct BannerData
{
    u16 index;          /* into gUnknown_08163444 */
    u16 shown;          /* letters revealed so far (max 10) */
    u16 timer;
};

/* Data of the fade/picture tasks. */
struct FadeTaskData
{
    void (*func)(void);
    void *fade;
    u32 kind;
};

struct Tile4bpp
{
    u32 data[8];
};

extern u32 gUnk_03004530;
extern u16 gUnk_0203DB7A;
extern u8 gBannerTiles[];
extern struct Task *gUnk_0203A3E4;
extern u16 gWindowTilemapBuffer[][32];
extern u32 gUnk_03003FF8;
extern u32 gUnk_0200AB04;
extern const u32 gUnknown_0816336C[];
extern const u32 gUnknown_081633D8[];
extern const u32 gUnknown_08163640[];
extern const u8 gUnknown_08163444[][10];
extern const u8 gUnknown_081AE018[];
extern const u16 gUnknown_081635B6[];
extern const u8 gUnknown_08163638[];
extern const u8 gUnknown_081B8870[];
extern const u8 gUnknown_081636E8[];

void sub_080C7218(void);
void sub_080C7414(void);
void sub_080AF060(const void *script);
void sub_080C6764(void);
void sub_080C1384(void);
void sub_080C1450(void);
void Sprite_DrawSingle(const void *tmpl, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
void Tilemap_FillRect(u32 value, void *map, u16 x, u16 y, u16 w, u16 h);
void *PalFade_FadeToBlack(u16 delay);
void *PalFade_FadeInFromBlack(u16 delay);
u16 PalFade_IsActive(void *fade);
u16 sub_080B6170(void);
void sub_080B6340(void);
void sub_080B6758(void);

struct CallbackTaskData
{
    void (*func)(void);
};

extern u16 gPaletteTarget[0x200];
extern u16 gBgPicturePiece;
void sub_080B3E7C(void);
void sub_080B3E8C(void);
void sub_080B3EA0(void);
void sub_080B3ED0(void);
void sub_080B41B0(void);
void BgPicture_BuildTilemap(void);
void BgPicture_LoadPiece(u32 now);
void sub_080C6558(void);

/* Picture scaling (Picture_ScaleStep): copies a w x h block of 4bpp pixels from a tile sheet
   (32 tiles per row) to another, stepping the source by stepX/w and stepY/h per pixel. */
/* Byte holding pixel (x, y) of a 4bpp tile sheet 32 tiles wide (as CANVAS_PIXEL_BYTE). */
#define TILE_PIXEL_BYTE(base, x, y)     ((base) + ((y) >> 3) * 0x400 + ((x) >> 3) * 32 + ((y) & 7) * 4 + ((x) & 7) / 2)

struct ScaleParams
{
    const u8 **src;
    u8 *dst;
    u16 srcX;
    u16 srcY;
    u16 dstX;
    u16 dstY;
    u16 stepX;
    u16 stepY;
    u16 pad14;
    u16 pad16;
    u16 w;
    u16 h;
};

struct ScaleState
{
    u16 pad00;
    u16 row;
    u16 accX;
    u16 accY;
    u16 srcRow;
    u16 dstRow;
};
#define gScaleState gScaleState
extern struct ScaleState gScaleState;

/* Warp destination at 0x03003FD0 (see sub_080B70BC / sub_080B7248). */
struct WarpDest
{
    u16 map;
    u16 floor;
    u16 x;
    u16 y;
    u16 dir;
    u16 unk0A;
    u32 unk0C;
};
extern struct WarpDest gWarpDest;

extern u16 gUnk_03004534;
extern u16 gUnk_03000042;
extern void (*gMainCallback)(void);
extern u32 gUnk_03004610;
extern u32 gUnk_03004544;
extern u16 gUnk_03003FF4;
extern const u32 gUnknown_08163BE8[];
extern const u32 gUnknown_08163E78[];
extern const u32 gUnknown_0834A0D4[];
extern const u32 gUnknown_0834A01C[];
extern const u32 gUnknown_0834A174[];
extern const u32 gUnknown_08164074[];
extern const u32 gUnknown_081641A8[];
extern const u32 gUnknown_0816417C[];
extern const u8 gUnknown_0857D9C0[];

s32 BgPicture_LoadStep(u32 now);
void BgPicture_LoadPalette(void);
void Palette_CopyWithEffect(u32 a0, const void *src, void *dst, u32 a3, u32 a4);
void sub_080C1440(void);
u32 sub_080B38A8(void);
void sub_080D977C(void);
void sub_080C1560(void);
void SetMainCallback(void (*func)(void));
u16 sub_0813EB78(void);
void sub_080C3818(u32 a);
void Field_SetPosition(u16 x, u16 y);
void Automap_SetVisitedAhead(u16 x, u16 y, u16 dir);
void Automap_SetVisited(u16 x, u16 y);
u32 FieldMap_HasRecordRel(u16 fwd, u16 side, u16 type);
u32 sub_080AF8D0(u32 a, u32 b, u32 c);
void sub_080B6CF8(void);
void sub_080B6D44(void);
u32 sub_080B721C(const u16 *rec);

extern void *gUnk_0300452C;
extern const u16 *gUnk_03004630;
extern const u16 *gUnk_03004510;
extern u8 gWorldMap[];
extern u32 gUnk_03003BB8;
extern struct Task gTasks[64];
extern const u32 gUnknown_0834A0B0[];
extern const u32 gUnknown_0834A150[];
extern const u32 gUnknown_0834A1F0[];
extern const u32 gUnknown_081641B4[];
extern const u32 gUnknown_08164460[];
extern const u32 gUnknown_081643D0[];
extern const u32 gUnknown_0816499C[];
extern const u8 gUnknown_0804C354[];
extern const u8 gUnknown_0804C564[];
extern const u8 gUnknown_0804CB9C[];

void *PalFade_FadeRangeInFromBlack(u16 start, u16 count, u16 delay);
void *PalFade_FadeRangeWithDuration(u16 start, u16 count, u16 delay, u16 duration);
void *PalFade_FadeRangeToBlack(u16 start, u16 count, u16 delay);
void sub_080B04BC(void);
void sub_080C2CD8(s32 a, s32 b, u32 c);
void sub_080B0C7C(void);
void sub_080AF178(u16 a, const void *script);
u32 View_GetWall(u16 dir, u16 dx, u16 dy);
void sub_080B1AD8(u16 a, u16 b);
void sub_080B7414(void);
void sub_080B2AB0(void);
u32 Warp_SetDestination(u16 map, u16 floor, u16 x, u16 y, u16 dir, u32 arg);
struct Task *sub_080B75E8(u16 map, u16 floor, u16 x, u16 y, u16 dir, u32 arg);
struct Task *sub_080B7738(u16 map, u16 floor, u16 x, u16 y, u16 dir, u32 arg);

/* One sub-map (0x268 bytes; DungeonMap_GetFloor(map, 0) returns the first of sub_080C8B3C(map)). */
struct MapArea
{
    u16 r[4];           /* x0, y0, x1, y1 */
};

struct SubMap
{
    u8 pad00[8];
    u16 x0;             /* world bounds */
    u16 y0;
    u16 x1;
    u16 y1;
    struct MapArea areas[16];   /* excluded rectangles */
    u8 pad90[0x268 - 0x90];
};

u16 Rect_IsOutside(const u16 *rect, u16 x, u16 y);
void sub_080BF300(u16 x, u16 y);
void sub_080C2CC0(void);
u32 sub_080C8B3C(u16 map);
void Automap_SetVisitedRaw(u16 x, u16 y);
u32 Palette_IsBg13Black(void);
void sub_080B7F2C(u16 map, u8 x, u8 y);
u32 sub_080C8AF8(u16 map);
void Encounter_SetCounter(u32 a);
struct Task *sub_080B764C(u16 map, u16 floor, u16 x, u16 y, u16 dir, u32 arg);
struct Task *sub_080B778C(u16 map, u16 floor, u16 x, u16 y, u16 dir, u32 arg);

struct PulseData
{
    u16 falling;
    u16 timer;
};

struct BlinkData
{
    u16 x;
    u16 y;
    u32 timer;
};

/* Treasure / event record (a map cell record: +2 count, +4 value, +8 flag). */
struct TreasureRec
{
    u16 unk0;
    u16 count;
    union
    {
        u32 value;      /* item id, or 0x8xxxxxxx money / 0x9xxxxxxx Magnetite amount */
        u16 id;
    } u;
    u16 unk8;
};

struct ItemTaskData
{
    const struct TreasureRec *rec;
    u32 handle;
    u32 handle2;
    u32 unk0C;
    const u16 *unk10;
    u16 flag;
    u16 pad16;
    u16 healed[8];
};

extern u16 gKeysNew;
extern u8 gUnk_0300003C;
extern u16 gUnk_03003FC4;
extern const u32 gUnknown_081644B4[];
extern const u32 gUnknown_08164670[];
extern const u32 gUnknown_081646C0[];
extern const u32 gUnknown_08164788[];
extern const u32 gUnknown_08164990[];
extern const u32 gUnknown_081648AC[];
extern const u32 gUnknown_08164A48[];
extern const u8 gUnknown_0800107C[];

void sub_080C1F50(u16 a, u16 b, u16 *x, u16 *y);
void Task_End(struct Task *task);
void sub_080B1A30(u16 a, u16 b);
void sub_080B2030(u16 a, u16 b, u16 c);
void Sprite_DrawBlended(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
u32 sub_080C2414(u16 a);
u32 Moon_GetPhase(void);
u32 CharObj_Create(u16 a0, u16 a1, u16 a2, u16 a3, u32 a4, u32 a5);
void sub_080AF1E8(u16 a);
void sub_080C2D48(u16 a, u16 b);
void *PalFade_FadeRangeToWhite(u16 start, u16 count, u16 delay);
void sub_080B0AE0(void);
struct Task *sub_080B78A4(void);
u32 SubMap_IsOutsideExclusions(struct SubMap *h, u16 x, u16 y);

extern u16 gMenuState[];
extern u16 gScriptItemCheckId;
extern u32 gUnk_0203DB2C;
extern u16 gUnk_0203DB28;
extern const u16 gUnknown_0805C088[];
extern const u16 gUnknown_0805C092[];
extern const u16 gUnknown_0805C09C[];
extern const u16 gUnknown_0805C0A6[];
extern const u16 gUnknown_0805C0B0[];
extern const u16 gUnknown_0805C0BA[];
extern const u16 gUnknown_0805C0C4[];
extern const u16 gUnknown_0805C0CE[];
extern const u16 gUnknown_0805C0D8[];
extern const u16 gUnknown_0805C0E2[];
extern const u16 gUnknown_0805C0EC[];
extern const u16 gUnknown_0805C0F6[];
extern const u16 gUnknown_08003502[];
extern const u16 gUnknown_080033A0[];
extern const u16 gUnknown_080033D6[];
extern const u16 gUnknown_080033BA[];
extern const u16 gUnknown_08003432[];
extern const u16 gUnknown_08003452[];
extern const u16 gUnknown_08003472[];
extern const u16 gUnknown_08003492[];
extern const u16 gUnknown_080034B2[];
extern const u16 gUnknown_08164A7C[];
extern const u32 gUnknown_08164AD4[];

void sub_080B832C(struct Task *task, const u16 *text);
u32 Inventory_IsMaxed(u16 a);
void sub_080C2438(u16 a);
void Inventory_AddItem(u16 a);
void Magnetite_Add(s32 a);
void Money_Add(s32 a);
void sub_080C7648(void);
void sub_080C762C(void);
s32 Combatant_IsUsed(s32 id);
s32 Combatant_IsDead(s32 id);
s32 Battle_GetHp(s32 id);
void Combatant_Damage(s32 id, s32 n);
void Combatant_SetStatus(s32 id, u32 status);
void sub_080C8490(u32 slot);
const u8 *Party_GetMember(u16 id);
u32 sub_080B8AE0(u16 a, u16 b);
s32 sub_080B8B08(u32 h);
void CharObj_End(u32 h, u32 a);
void Text_CopyToMenuBuffer(const u16 *src);
u16 Spring_GetKindAt(void);

#endif /* GUARD_FIELDEVENT_H */
