#ifndef GUARD_GAME_H
#define GUARD_GAME_H

/* Field/dungeon game code 0x080B04BC-0x080B447C. Declarations copied from sys.h/menu.h where
   needed (those headers are not included here). */

#define DMA_ENABLE      0x8000
#define DMA_START_NOW   0x0000
#define DMA_16BIT       0x0000
#define DMA_32BIT       0x0400
#define DMA_SRC_FIXED   0x0100
#define DMA_DEST_INC    0x0000

#define DmaSet(dmaNum, src, dest, control)        {                                                     vu32 *dmaRegs = (vu32 *)(0x040000B0 + 12 * (dmaNum));     dmaRegs[0] = (vu32)(src);                         dmaRegs[1] = (vu32)(dest);                        dmaRegs[2] = (vu32)(control);                     dmaRegs[2];                                   }

#define DMA_FILL(dmaNum, value, dest, size, bit)                                              {                                                                                                 vu##bit tmp = (vu##bit)(value);                                                               DmaSet(dmaNum, &tmp, dest,                                                                           (DMA_ENABLE | DMA_START_NOW | DMA_##bit##BIT | DMA_SRC_FIXED | DMA_DEST_INC) << 16          | ((size)/(bit/8)));                                                                 }

#define DmaFill16(dmaNum, value, dest, size) DMA_FILL(dmaNum, value, dest, size, 16)
#define DmaFill32(dmaNum, value, dest, size) DMA_FILL(dmaNum, value, dest, size, 32)

#define DMA_COPY(dmaNum, src, dest, size, bit)                                                  DmaSet(dmaNum, src, dest,                                                                          (DMA_ENABLE | DMA_START_NOW | DMA_##bit##BIT | DMA_DEST_INC) << 16          | ((size)/(bit/8)))

/* Variant whose source is evaluated before the DMA register address. */
#define DmaCopy32S(dmaNum, src, dest, size)                         {                                                                       const void *_src = (src);                                           DmaSet(dmaNum, _src, dest, (DMA_ENABLE | DMA_32BIT) << 16 | ((size) / 4)); }

#define DmaCopy16(dmaNum, src, dest, size) DMA_COPY(dmaNum, src, dest, size, 16)
#define DmaCopy32(dmaNum, src, dest, size) DMA_COPY(dmaNum, src, dest, size, 32)

typedef void (*VoidFunc)(void);

struct PalFade
{
    u16 active;
    u16 duration;
    u16 delay;
    u16 timer;
    u16 start;
    u16 count;
    u16 waitTag;
    u16 pad;
    u16 accum[32];
};

/* Field state at 0x03004550: unk00 is the state that the field main loop (sub_080B0C90)
   switches on, unk1E the step within that state. */
struct Unk03004550
{
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u16 unk06;
    s16 unk08;
    u16 unk0A;
    u16 unk0C;
    u16 unk0E;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 unk1A;
    u16 unk1C;
    u16 unk1E;
    u16 unk20;
    u16 unk22;
    u32 unk24;
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
    u16 unk3C;
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
    u32 unk58;
    u16 unk5C;
    u16 unk5E;
};

extern struct Unk03004550 gFieldState;
extern VoidFunc gMainCallback;
extern VoidFunc gIntrTable[14];
extern u32 gFrameCounter;
extern u16 gPaletteTarget[0x200];
extern u16 gPaletteBuffer[0x200];
extern const s16 gSineTable[];
extern struct PalFade *gUnk_0300452C;
extern u16 *gUnk_03004630;
extern u16 *gUnk_03004510;
extern u16 *gUnk_03003FC8;
extern u16 gUnk_0200F814[];
extern u16 gUnk_0200F7F4[];
extern u16 gUnk_0200F854[];
extern u32 gUnk_0200AB04;
extern u16 gUnk_03004534;
extern u8 gUnk_03002F50[32];
extern u16 gUnk_03003FF4;
extern u16 gUnk_03002A90[];
extern u16 gUnk_03002AB0[];

void IntrDummy(void);
struct VBlankTask *VBlankTask_AddCountedAlways(VoidFunc func, u16 count);
void Palette_CopyWithEffect(u32 a0, const void *src, void *dst, u32 a3, u32 a4);
struct PalFade *PalFade_FadeRangeInFromBlackTagged(u16 start, u16 count, u16 delay, u16 tag);
void PalFade_FadeRangeInFromBlack(u16 start, u16 count, u16 delay);
struct PalFade *PalFade_FadeRangeToBlackTagged(u16 start, u16 count, u16 delay, u16 tag);
struct PalFade *PalFade_FadeRangeToBlack(u16 start, u16 count, u16 delay);
struct PalFade *PalFade_FadeRangeWithDuration(u16 start, u16 count, u16 delay, u16 duration);
struct PalFade *PalFade_FadeRangeToBlackWithDuration(u16 start, u16 count, u16 delay, u16 duration);
u16 PalFade_IsActive(struct PalFade *fade);
u32 Flag_Test(u32 flag);
void Flag_Set(u32 flag);
void Flag_Clear(u32 flag);
void Field_SetState(u32 state);
void sub_080D977C(void);
void sub_080C3818(u32 a);
u16 *sub_080C5F60(u16 a);
u32 sub_080AF8D0(u32 a, u32 b, u32 c);
void sub_080B03BC(u32 a);
void Automap_SetVisitedAhead(u16 a, u16 b, u16 c);

extern const u16 gUnknown_0815F2FC[][4];
extern const u32 gUnknown_08165380[];
extern u32 gUnk_03004614;
extern u16 gUnk_0200E7D4[];
extern u32 gUnk_03003BB8;

u8 *Task_Create(const void *script, u32 parent);
void Sound_Play(u32 se);
s32 View_IsSideOpen(u32 a);
s32 View_GetWall(u32 a, u32 b, u32 c);
void Field_Step(u16 a);
void sub_080B2840(u32 a, u32 b, u32 c);
void sub_080B2030(u16 a, u16 b, u16 c);
s32 sub_080C8AF8(u16 a);
u16 PalFade_AllDone(void);
s32 sub_080B78A4(void);
s32 sub_080B953C(void);
void sub_080AD6E4(u32 a);
void sub_080C7218(void);
void sub_080C6FF0(void);
void sub_080C7414(void);
s32 sub_080F3190(void);
u16 sub_0812A730(void);
void sub_080B09C4(u16 x, u16 y);
void sub_080B1A30(u16 a, u16 b);

void sub_080AE494(VoidFunc func);
void sub_080B01C8(void);
void sub_080B0158(void);
u32 Field_SetFacing(u16 dir);
struct FieldEvent
{
    u32 unk0;
    const void *script;
};

extern const u16 gUnknown_0815F324[][2];
extern const u16 gUnknown_0815F31C[];
extern u16 gUnk_03004540;

void Automap_SetVisited(u16 x, u16 y);
struct FieldEvent *sub_080C9084(u16 x, u16 y, u16 dir, u16 *id);
s32 sub_080C2480(u16 id);
u16 sub_080AF0AC(const void *script);
u32 sub_080B828C(void);
void sub_080AF7E8(struct FieldEvent *a, struct FieldEvent *b, u32 c);
void sub_08128B84(u32 a);
s32 sub_080B9568(void);
void sub_0812D0FC(u32 a);
u32 BattleFlags_Get(void);
u32 sub_080C57B4(void);
void sub_080B1BC4(void);
void sub_080B1BDC(void);
s32 sub_080B1B58(void);
void sub_080B1A4C(u16 a, u16 b);
void sub_080B1AD8(u16 a, u16 b);
void sub_080B2064(u16 a, u16 b);

/* Window register shadows inside gDispRegs (0x03000000 = REG_BG0HOFS..). */
extern u8 gUnk_03000030;
extern u8 gUnk_03000031;
extern u8 gUnk_03000032;
extern u8 gUnk_03000033;
extern u8 gUnk_03000034;
extern u8 gUnk_03000035;
extern u8 gUnk_03000036;
extern u8 gUnk_03000037;
extern u8 gUnk_03000038;
extern u8 gUnk_03000039;
extern u8 gUnk_0300003A;
extern u32 gUnk_03004514;

u32 sub_080ADF40(void);
/* Argument block of the field view blitters FieldView_BlitPixels / FieldView_BlitTiles. */
struct ViewBlit
{
    const u8 **src;
    u8 *dst;
    u16 srcX;
    u16 srcY;
    u16 dstX;
    u16 dstY;
    u16 w;
    u16 h;
    u16 dir;        /* 1, or 0xFFFF for mirrored */
};

/* Code copied to IWRAM (called through fixed addresses). */
typedef void (*IwramFunc)(const void *);
#define IwramFunc_3BC1 ((IwramFunc)0x03003BC1)
#define IwramFunc_4011 ((IwramFunc)0x03004011)

struct ViewLayer
{
    const void *data;
    const void *alt;
    const void *extra;
    u32 mode;
};

struct ViewCond
{
    u8 pad00[0x10];
    const u16 *a;
    const u16 *b;
    const u16 *c;
    const u16 *d;
};

s32 FieldView_DrawLayer(const struct ViewLayer *layer, const struct ViewCond *cond);
void sub_080B28F8(const struct ViewLayer *a, const struct ViewCond *b);
s32 Picture_ScaleStep(const void *a);
extern u32 gUnk_03003FE8;
extern u32 gUnk_030045F4;
extern const u8 gUnknown_0815FD7C[][0x1C];
extern const u8 gUnknown_0815FDD0[], gUnknown_0815FDEC[], gUnknown_0815FE08[];

u16 Field_GetState(void);
u32 sub_080B2980(u16 x, u16 y);
u32 sub_080B2938(void);
void sub_080B29A8(u16 mode);
void sub_080AE574(u16 a, u32 b);
s32 sub_080BA6B4(u16 a);
void sub_080B2AB0(void);
void Sprite_Draw(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
extern u32 gUnk_0300461C;
extern const u8 gUnknown_08002CAC[], gUnknown_08002C88[], gUnknown_08002C70[], gUnknown_08002D78[], gUnknown_08002DAC[], gUnknown_08002DE8[], gUnknown_08002E24[];
extern const u8 gUnknown_08160A0C[][0x20], gUnknown_08160E0C[][0x20], gUnknown_0816120C[][0x20], gUnknown_0816160C[][0x20], gUnknown_08161A0C[][0x20], gUnknown_08161E0C[][0x20];
s32 FieldMap_GetElevatorRecord(void);

/* Save data at 0x030046C0 (only the fields used here; see menu.h/field.h). */
struct GameState
{
    u8 pad000[0xA38];
    u16 unkA38;
    u8 padA3A[0x18C2 - 0xA3A];
    u8 unk18C2;     /* saved x */
    u8 unk18C3;     /* saved y (bits 0-5) and direction (bits 6-7) */
};
extern struct GameState gGameState;

/* Per-variant data of a map (0xE8 bytes; variant = gGameState.unkA38). */
struct MapVariant
{
    const void *data[0xE8 / 4];
};

/* One sub-map (0x268 bytes); DungeonMap_GetFloor(map, 0) returns the first of an array. */
struct MapHeader
{
    u8 pad00[0x08];
    u16 x0;         /* bounds in global map coordinates */
    u16 y0;
    u16 x1;
    u16 y1;
    u8 pad10[0x90 - 0x10];
    const u16 *unk90;
    u32 *unk94;     /* cell attribute list, see FieldMap_CellRecordsRel */
    struct MapVariant variants[2];
};

struct MapHeader *DungeonMap_GetFloor(u16 a, u16 b);

u32 sub_080C8B3C(u16 map);
s32 SubMap_IsOutsideExclusions(struct MapHeader *map, u16 x, u16 y);
void Field_SavePrevPosition(void);
void sub_080ADFEC(u16 a);
void sub_080AE234(void);
u32 *FieldMap_CellRecordsOffset(u16 dx, u16 dy);
extern u16 gUnk_03004544;
extern u16 gUnk_03004634;
extern const u32 gUnknown_081622D0[];
void sub_080B343C(s16 delta);
void sub_080B3560(u32 unused);
void DungeonMap_LoadDoorGfx(void);
void sub_080AE1FC(void);
void sub_080B34E8(void);
void sub_080B350C(void);
void VBlankTask_AddCounted(VoidFunc func, u32 count);
void Palette_FillWithEffect(u32 a0, u32 a1, void *dest, u32 size, u32 a4);
void Palette_MarkDirty(void);

struct PalFade *PalFade_FadeToBlack(u16 delay);
void sub_080B0620(void);
void sub_080B05A4(void);
extern u16 gUnk_0300000E;
extern u32 gUnk_03003BB4;
extern u32 gUnk_0300462C;
extern u16 gFieldLoadStep;
void Map_SetGraphicsPointers(u32 map, u32 sub);
void sub_080AD7F0(void);
void Field_LoadGraphicsStep(void);
extern const u32 gUnknown_081625D0[], gUnknown_08162490[];

void sub_080C14FC(void);
void Tilemap_FillRect(u32 value, u16 *map, u16 x, u16 y, u16 w, u16 h);
extern u16 gUnk_03002EB0[];
extern u16 gUnk_02000000[];
extern u8 gBgPictureBuffer[];
extern u16 gUnk_03003BA0;
s32 BgPicture_LoadStep(u32 a);
void BgPicture_SetupStepTask(void);
void sub_080B0778(void);
void sub_080B7530(u32 a);
u16 sub_080B1A1C(u16 a);
extern const VoidFunc gUnknown_081625D4[];

/* Background picture descriptor returned by sub_080C5EF0 (only the fields used here). */
struct BgPicture
{
    u32 kind;       /* 1 = LZ77 pieces, 2 = Huffman */
    u8 pad04[0x4C - 0x04];
    u32 unk4C;
    u8 pad50[0x58 - 0x50];
    u32 unk58;
};

struct Unk08162618
{
    u32 a;
    u32 b;
    u16 value;
};

extern u16 gBgPicturePiece;
extern u32 *gUnk_03003B94;
extern const struct Unk08162618 gUnknown_08162618[];
extern const u32 gUnknown_081625F4[];
struct BgPicture *sub_080C5EF0(u16 id);
const void *sub_080C5F04(u16 id, u16 piece);
void sub_080C153C(void);
void BgPicture_LoadPiece(u32 now);
void sub_080B3C34(u32 idx, u32 now);
void BgPicture_BeginLoad(void);
void sub_080B3E7C(void);
void sub_080B3E8C(void);
void sub_080B3EA0(void);
void sub_080B3ED0(void);
void BgPicture_BuildTilemap(void);
void BgPicture_LoadPalette(void);
void sub_080B41B0(void);
void sub_080B41CC(void);
void sub_080ADF64(void);
const u8 *sub_080C5F40(u16 id, u32 half);
void sub_080BDF3C(u16 id);
void sub_0815C380(void);
extern u16 gUnk_03004608;
extern u16 gUnk_03004600;
extern const u16 gUnknown_081C25F0[], gUnknown_081C32F4[], gUnknown_081C2C74[], gUnknown_081C25F4[], gUnknown_081C32F8[];
void CharObj_Create(u32 a, u16 b, u32 c, u32 d, u32 e, u32 f);

void sub_080B04BC(void);
u32 Palette_IsBg13Black(void);
u32 sub_080B092C(void);
void sub_080B0678(void);
void sub_080B06FC(void);
u32 FieldMap_HasRecordRel(u16 a, u16 b, u16 c);
u32 *FieldMap_CellRecordsRel(u16 fwd, u16 side);
u32 *FieldMap_FindRecord(u32 *p, u16 type);
extern const s32 gUnknown_0816222C[];
void sub_080B0ABC(void);
void sub_080B0A78(void);
void sub_080B0B00(void);
void sub_080B0B68(void);
void sub_080B0B88(void);
void Field_HBlankWobble(void);

#endif /* GUARD_GAME_H */
