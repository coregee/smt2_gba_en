#ifndef GUARD_FIELD_H
#define GUARD_FIELD_H

#include "global.h"

/* ---- Script tasks (copied from text.h) ---- */
struct TextWindow
{
    u16 x;
    u16 y;
    u16 w;
    u16 h;
    u16 screen;
    u16 curH;
    u32 unk0C;
    const u16 *frame;
};

struct YesNoCursor
{
    u32 unk0;
    s32 choice;
    u32 tile;
};

struct Task
{
    u16 state;          /* 0 free, 1 running, 0xFFFF paused */
    u16 id;
    u16 parent;
    u16 pad06;
    u32 op;             /* current opcode */
    s32 wait;           /* nonzero: run op's update handler instead of fetching */
    s32 pc;             /* index into script (words) */
    const u32 *script;
    u16 loopCount;
    u16 loopStart;
    u16 result;
    u16 unk1E;
    void (*onFrame)(struct Task *);
    union
    {
        struct TextWindow win;
        struct YesNoCursor yesNo;
        u16 h[0x20];
        u8 raw[0x40];
    } data;
};

extern const u32 *gTaskOpArgs;              /* current op's argument words */

struct Task *Task_Create(const u32 *script, u32 parent);
void Task_End(struct Task *task);
void Task_GotoLabel(struct Task *task, u32 label);

void sub_080C5170(u32 a);
void sub_080C51D4(u32 se);
void m4aSongNumStop(u16 n);
u32 Flag_Test(u32 flag);

/* The pret DmaSet idiom (as in text.h). */
#define FIELD_DMA3_SET(src, dest, control)               \
{                                                        \
    vu32 *dmaRegs = (vu32 *)0x040000D4;                  \
    dmaRegs[0] = (u32)(src);                             \
    dmaRegs[1] = (u32)(dest);                            \
    dmaRegs[2] = (u32)(control);                         \
    dmaRegs[2];                                          \
}

/* Save data at 0x030046C0 (only the fields used here; see menu.h). */
struct GameState
{
    u8 pad000[0xA2C];
    u16 unkA2C;
    u16 unkA2E;
    u16 unkA30;
    u16 unkA32;
    u16 unkA34;
    u16 padA36;
    u16 unkA38;
    u16 unkA3A;
    u16 unkA3C;
    u16 padA3E;
    u8 padA40[0x1188 - 0xA40];
    u8 visited[0x46][16];   /* automap: 1 bit per square, 128 squares per row */
};
extern struct GameState gGameState;

/* Per-variant graphics/palette pointers of a map (0xE8 bytes; variant = gGameState.unkA38). */
struct MapVariant
{
    const void *data[0xE8 / 4];
};

struct MapHeader
{
    u8 pad00[8];
    u16 originX;        /* added to map-local coordinates for the visited bits */
    u16 originY;
    u8 pad0C[0x90 - 0x0C];
    const u16 *unk90;
    u32 unk94;
    struct MapVariant variants[1];
};

struct MapHeader *DungeonMap_GetFloor(u16 a, u16 b);
s32 Picture_ScaleStep(const u8 *a);
void sub_080B6F28(const u8 *a);
void Palette_CopyDarkened(const u16 *src, u16 *dst, u16 count);
void Map_SetGraphicsPointers(u32 map, u32 sub);

extern const u8 gUnknown_0815F264[];
extern const u8 gUnknown_0815F280[];
extern const u8 gUnknown_0815F29C[];
extern void *gUnk_03004604;
extern void *gUnk_03003FCC;
extern void *gUnk_03003FC0;
extern void *gUnk_03003BB0;
extern const void *gUnk_03003BB4;
extern void *gUnk_03003B90;
extern void *gUnk_03004620;
extern const u16 *gUnk_03004510;
extern void *gUnk_03003B94;
extern const void *gUnk_0300462C;
extern const u16 *gUnk_03004630;
extern const void *gUnk_0300461C;
extern const void *gUnk_03003FE4;
extern const void *gUnk_03003FE8;
extern const u16 *gUnk_03003FC8;
extern u16 gUnk_0200F7F4[];
extern u16 gUnk_0200F814[];
extern u16 gUnk_0200F854[];

/* ---- Field state at 0x03004550 (layout still being worked out: u16 slots) ---- */
struct FieldState
{
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u16 unk06;
    u16 unk08;
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
    u16 unk38;
    u16 unk3A;
    u16 unk3C;
    u16 unk3E;
    u16 unk40;
    u16 unk42;
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
extern u32 gUnk_03004614;
extern u32 gUnk_03004514;
extern u16 gUnk_030069F0[];
extern s16 gAutomapScroll;
extern u16 gUnk_0200DFCE;
extern u16 gUnk_0200DFD0;
extern u16 gUnk_03003FF4;
extern u32 gUnk_03003FF8;
extern const u8 gUnknown_0815EFB4[];
extern const u16 gUnknown_0815F1B4[];
extern const u16 gUnknown_087DF93C[];
extern const u32 gUnknown_08165598[];

struct FlagTextEntry
{
    u16 flag;
    u16 ifClear;
    u16 ifSet;
    u16 pad;
};
extern const struct FlagTextEntry gUnknown_0815F214[];

void sub_080C1F50(u16 a, u16 b, u16 *x, u16 *y);
u16 sub_080C5E44(u16 a);
u16 sub_080C5E58(void);
s32 FieldMap_CellRecordsRel(u32 a, u32 b);
s32 FieldMap_FindRecord(s32 a, u32 b);
u32 View_GetWall(u16 dir, u16 dx, u16 dy);
void LocationBanner_Start(u16 a);
void sub_080B3878(u32 a);

u16 sub_080AD608(u16 unused0, u16 unused1);
u16 sub_080AD67C(u16 id);
bool32 sub_080AD750(void);
void sub_080AD76C(void);
void Field_SetState(u16 state);
u32 sub_080AD7FC(void);

extern u16 gPaletteTarget[0x200];
extern u16 gFieldLoadStep;
extern u16 gUnk_0300000E;
extern u32 gUnk_0203A3E8[];
extern const u8 gUnknown_081C2270[];
extern const u8 gUnknown_0848DE60[];
extern const u8 gUnknown_081C0A70[];
extern const u16 gUnknown_0815F2B8[];
extern u8 gUnk_03003BC0[];
extern u8 gUnk_03004010[];

void Palette_CopyWithEffect(u32 a0, const void *src, void *dst, u32 a3, u32 a4);
void BgPicture_LoadAll(void);
void DungeonMap_LoadDoorGfx(void);
void BattleFlags_Mask(s32 a);
void Encounter_SetCounter(u32 a);
void sub_080B2840(u32 a, u32 b, u32 c);
void sub_080B2CC0(void);
void sub_080B2880(void);
void sub_080AE494(void (*func)(void));
void FieldView_BlitPixels(void);
void FieldView_BlitTiles(void);

/* View cells around the player (12 bytes each, 9 per row) at 0x0200AB08. */
struct ViewCell
{
    u16 valid;
    u16 unk2;
    u16 walls[4];
};
#define gViewCells gViewCells
extern struct ViewCell gViewCells[][9];

extern u16 gUnk_03003B9C;
extern u16 gUnk_03004608;
extern u16 gWarpDest[];
extern u32 gUnk_030045FC;
extern const u16 gUnknown_0815F2E6[];

void VBlankTask_AddCounted(void (*func)(void), u32 arg);
void sub_080AE2D0(void);
void Field_CopyIwramCode(void);
void sub_080AE234(void);
void Field_SetPosition(u16 x, u16 y);
void sub_080AE304(void);
void sub_080B30A0(u16 a);
s32 FieldMap_HasRecordRel(u32 a, u32 b, u32 c);
void Automap_SetVisited(u16 x, u16 y);
void Automap_SetVisitedAhead(u16 x, u16 y, u16 dir);
void sub_080C20C8(void);
void sub_080C67C0(void *a, u32 b);

/* Automap: 11 rows of 28 cells at 0x02005000. */
struct AutomapCell
{
    u16 flags;          /* 1 = visited square, bit 15 = event */
    u8 x;
    u8 y;
    u16 walls[4];
};
#define gAutomapCells gAutomapCells
extern struct AutomapCell gAutomapCells[11][28];
extern u16 gUnk_0200DFC8;
extern u16 gUnk_0200DFCA;
extern u32 gUnk_03003BB8;
extern const u8 gUnknown_081B28B8[];

u16 Automap_IsVisited(u16 x, u16 y);
u16 sub_080B447C(void);
s32 FieldMap_CellRecordsAt(u16 x, u16 y);
void sub_080C7234(void);
void sub_080C7430(void);
void sub_080B628C(void);
void sub_080AEFAC(void);

extern const u8 gUnknown_08072766[];
extern const u8 gUnknown_08072B3A[];
extern const u8 gUnknown_080775A6[];
extern const u8 gUnknown_08052210[];
extern const u8 gUnknown_080522F8[];
extern const u8 gUnknown_0815F2EE[];
extern u32 gUnk_03004530;
extern u16 gUnk_0203DB7A;
extern const void *gUnk_0300453C;

void Flag_Set(u32 flag);
void Flag_Clear(u32 flag);
void ScriptVM_Init(const void *script, u32 a);
u16 sub_0813EB78(void);
s16 ScriptVM_RunAlt(const void *script);
s32 sub_080B721C(void);
s32 Combatant_IsUsed(s32 a);
s32 sub_0814E8B0(void);
u32 Random_Byte(void);
void sub_080B6308(u16 a, const void *script);
void sub_080AF060(const void *script);

extern const u32 gUnknown_0816499C[];
extern u16 gUnk_0203DB6A;
extern u32 gUnk_0200AB04;
extern u16 gUnk_0300460C;

void sub_080C3818(u32 a);
void sub_080AE574(u16 dir, u32 a);
s32 Palette_IsBg13Black(void);
s32 sub_080B78DC(void);
s32 sub_080B78A4(void);
s32 sub_080E54D4(void);
void sub_080B0820(void);
bool32 sub_080AF2BC(void);
void sub_080AF2E8(void);
void sub_080AF300(void);

extern u32 gUnk_03004538;
extern const u32 *gUnk_03004000;
extern const u8 gUnknown_08073AD0[];
extern const u8 gUnknown_08073AB2[];
extern const u8 gUnknown_08073ABC[];
extern const u8 gUnknown_08073AC6[];
extern const u8 gUnknown_08073AA8[];

s32 SubMap_IsOutsideExclusions(struct MapHeader *h, u16 x, u16 y);
void Automap_SetVisitedRaw(u16 x, u16 y);
void Automap_ClearVisitedRaw(u16 x, u16 y);
void Automap_SetVisited(u16 x, u16 y);
void sub_080AF178(u16 a, const void *script);
void sub_080AF1D0(u16 a, const void *script);
void sub_080AF6E4(u32 a, const u32 *b);
const u32 *sub_080C9084(u16 x, u16 y, u16 dir, u16 *flag);
void sub_080C24B8(u16 flag);

u32 Moon_GetPhase(void);
u32 BattleFlags_Get(void);
void sub_080C1AB0(void);
u16 Encounter_GetCounter(void);
void *sub_080C1B74(u16 *a, u16 *b);
void *sub_080C1E20(void);
void sub_080C20EC(void);
s32 Door_TryOpen(void);
void sub_080B9274(void *ev);
void sub_080BEC3C(void *ev, u16 a, u16 b);
void sub_080B90F4(void);
s32 RandomEvent_Try(void);
s32 Encounter_Check(u32 a);
u16 sub_080B6170(void);
void sub_080AF034(void);
void Field_SavePrevPosition(void);
bool32 sub_080ADF40(void);
u32 sub_080B0350(void);

#endif /* GUARD_FIELD_H */
