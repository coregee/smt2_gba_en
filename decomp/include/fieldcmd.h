#ifndef GUARD_FIELDCMD_H
#define GUARD_FIELDCMD_H

#include "global.h"

/* Field event commands 0x080B89B0-0x080BA1AC and 0x080BD878-0x080BF908. Declarations
   copied from other headers are kept here so this header can be used alone. */

typedef void (*VoidFunc)(void);

#define DmaSet(dmaNum, src, dest, control)                      \
{                                                               \
    vu32 *dmaRegs = (vu32 *)(0x040000B0 + 12 * (dmaNum));       \
    dmaRegs[0] = (vu32)(src);                                   \
    dmaRegs[1] = (vu32)(dest);                                  \
    dmaRegs[2] = (vu32)(control);                               \
    dmaRegs[2];                                                 \
}

#define DMA_FILL(dmaNum, value, dest, size, bit)                                    \
{                                                                                   \
    vu##bit tmp = (vu##bit)(value);                                                 \
    DmaSet(dmaNum, &tmp, dest, (0x8000 | (bit == 32 ? 0x0400 : 0) | 0x0100) << 16 | ((size) / (bit / 8))); \
}
#define DmaFill16(dmaNum, value, dest, size) DMA_FILL(dmaNum, value, dest, size, 16)
#define DmaFill32(dmaNum, value, dest, size) DMA_FILL(dmaNum, value, dest, size, 32)

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
    u16 unk1E;
    void (*onFrame)(struct Task *);
    union
    {
        u32 w[0x10];
        u16 h[0x20];
        u8 raw[0x40];
    } data;             /* 0x24 */
};

/* Field state at 0x03004550. */
struct FieldState
{
    u16 unk00;
    u16 unk02;          /* facing */
    u16 unk04;
    u16 unk06;
    s16 unk08;
    u16 unk0A;
    u16 unk0C;
    u16 unk0E;
    u16 unk10;
    u16 unk12;          /* x */
    u16 unk14;          /* y */
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
    u32 unk58;
    u16 unk5C;
    u16 unk5E;
    u16 unk60;
    u16 unk62;          /* random-event index chosen by RandomEvent_CheckCell */
};
extern struct FieldState gFieldState;

/* Other modules. */
#define DmaCopy32(dmaNum, src, dest, size) DmaSet(dmaNum, src, dest, (0x8000 | 0x0400) << 16 | ((size) / 4))
#define DmaCopy16(dmaNum, src, dest, size) DmaSet(dmaNum, src, dest, 0x8000 << 16 | ((size) / 2))

struct Task *Task_Create(const void *script, u32 parent);
void Task_End(struct Task *task);
void Palette_CopyWithEffect(u32 a0, const void *src, void *dst, u32 a3, u32 a4);
void Palette_FillWithEffect(u32 a0, u32 a1, void *dest, u32 size, u32 a4);
void Palette_MarkDirty(void);
s32 FieldMap_HasRecordRel(u32 a, u32 b, u32 c);
u16 *sub_080C5F60(u16 a);
u8 *Party_GetMember(u16 id);
s32 Combatant_IsDead(s32 id);
s32 Combatant_IsUsed(s32 a);
u16 Combatant_GetStatus(u32 who);
u32 Random_Byte(void);
void Combatant_SetStatus(s32 a, u32 b);
void sub_080C8490(u32 slot);
void sub_080C86F4(u16 slot);
s32 Combatant_GetAlignment(u32 a);
s32 Battle_GetMaxHp(s32 a);
s32 Battle_GetHp(s32 a);
void Combatant_Damage(s32 id, s32 n);
void sub_080B8874(struct Task *task, u32 step, u32 a, u32 b);
void sub_080B832C(struct Task *task, const u16 *text);
void Text_CopyToMenuBuffer(const u16 *src);
void Field_SetState(u32 state);
void *PalFade_FadeToBlack(u16 delay);
void sub_080AF060(const void *script);
void sub_080AF1E8(u16 a);

extern u16 gPaletteBuffer[0x200];
extern u16 gPaletteTarget[0x200];
extern u16 gMenuState[];
extern u16 gUnk_0203DB28[];
extern u32 gUnk_0203DB2C;
extern u16 gUnk_0200E7D4[];
extern u16 gUnk_03004534;
extern void *gUnk_03004630;
extern void *gUnk_03004510;
extern u16 gUnk_0200F814[];
extern u16 gUnk_0200F7F4[];

extern const u16 gUnknown_081BB7B0[];
extern const u16 gUnknown_080034EA[], gUnknown_08003432[], gUnknown_08003452[], gUnknown_08003472[], gUnknown_08003492[], gUnknown_080034B2[];
extern const u32 gUnknown_08164EDC[], gUnknown_08164F78[], gUnknown_08164FD0[], gUnknown_0816514C[], gUnknown_081651B4[], gUnknown_081651E8[], gUnknown_0816522C[];
extern const u32 gUnknown_0807CF14[];

u32 Window_Create(u32 x, u32 y, u32 w, u32 h, u32 bg);
void Window_Close(void *window, u32 arg1);
void Combatant_DecodeName(u8 *combatant, u16 *dst);
void FontSprite_DrawGlyph(u16 glyph, u32 a1, u32 a2, u16 x, u16 y);
void Text_DrawSpriteString(const void *str, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
u8 *Demon_GetRecord(u16 id);
s32 sub_080C5108(void);
u32 Flag_Test(u32 flag);
void Flag_Set(u32 flag);
void Flag_Clear(u32 flag);
void Field_Step(u16 dir);
u16 sub_080B1A1C(u16 a);
struct Task *sub_080B80F8(void);
s32 sub_080B8160(u32);
u32 View_GetWall(u16 dir, u16 dx, u16 dy);
u32 sub_080B2938(void);
void sub_080B343C(s16 delta);
void sub_080B2AB0(void);
void VBlankTask_AddCounted(VoidFunc func, u32 count);
void DungeonMap_LoadDoorGfx(void);
void sub_080B34E8(void);
void sub_080B350C(void);
void sub_080AE1FC(void);
void sub_080B2880(void);

extern u16 gKeysNew;
extern u16 gUnk_0300000E;
extern u8 gUnk_03000038, gUnk_03000039, gUnk_0300003A;
extern u32 gUnk_0200AB04;
extern const u16 gUnknown_081652D8[];
extern const u32 gUnknown_081652E4[];

u32 *FieldMap_CellRecordsRel(u16 fwd, u16 side);
u16 *FieldMap_FindRecord(u32 *p, u16 type);
s32 sub_080F3190(void);
void sub_080C4AB0(u32 a0, u32 a1, u32 x, u32 y);
void *PalFade_FadeRangeWithDuration(u16 start, u16 count, u16 delay, u16 duration);
struct MapHeader *DungeonMap_GetFloor(u16 map, u16 floor);
void Map_SetGraphicsPointers(u32 map, u32 sub);
void Map_LoadGraphicsStep(u16 map, u16 sub, u32 *done);
void sub_080C1F50(u16 a, u16 b, u16 *x, u16 *y);

extern u16 gFieldLoadStep;
extern u32 gUnk_03004614;
extern u32 gUnk_03004514;
extern void *gUnk_0300452C;
/* Save data at 0x030046C0 (only the fields used here). */
struct GameState
{
    u8 pad0000[0xAC0];
    u16 unkAC0;
};
extern struct GameState gGameState;
extern const u32 gUnknown_08165444[];
extern const u16 gUnknown_08165574[];
extern const u16 gUnknown_080A54AC[];
extern const u32 gUnknown_081C1270[], gUnknown_08165614[];

u32 TextWindow_Create(u32 x, u32 y, u32 w, u32 h, u32 a4);
s32 TextWindow_IsDone(u32 window);
void TextWindow_Close(u32 window, u32 now);
u8 *NumberToDigits(u32 value);
void sub_080B2064(u16 dir, u16 b);
s32 sub_080B2090(void);
void sub_080AE494(VoidFunc func);
void sub_080B2840(u32 a, u32 b, u32 c);
void Field_LoadGraphicsStep(void);
void sub_080B0158(void);
void sub_080C7218(void);
void sub_080C7414(void);
void sub_080C6FF0(void);
void sub_080C7234(void);
void sub_080C7430(void);
void sub_080C700C(void);
void sub_080C49EC(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
u32 sub_080B31C4(u16 unused, u16 type, u16 value);
void sub_080B2030(u16 a, u16 b, u16 c);
void sub_080C51D4(u32 se);
void sub_080AE234(void);
void sub_080AE294(void);

extern const u16 *gUnk_03004000;
extern u16 gUnk_03004634;
extern const u16 gUnknown_08165674[], gUnknown_0816567E[], gUnknown_0816567A[], gUnknown_08165654[];

/* One floor of a dungeon map (DungeonMap_GetFloor). */
struct MapHeader
{
    u8 pad00[0x06];
    s16 floor;          /* 0x06: shown as B<n>F when negative */
};

/* Elevator floor lists (gUnknown_081655F8). */
struct FloorRef
{
    u16 map;
    u16 floor;
};
struct FloorTable
{
    u16 count;          /* followed by count FloorRefs (at offset 2) */
};
extern const struct FloorTable *const gUnknown_081655F8[];

/* Data of the elevator floor menu task. */
struct FloorMenu
{
    u32 textWin;        /* 0x00 */
    u32 win;            /* 0x04 */
    u32 cursor;         /* 0x08 */
    u32 prevFloor;      /* 0x0C */
    u32 drawn;          /* 0x10 */
    u32 loadDone;       /* 0x14 */
    u16 useTable;       /* 0x18: floors from gUnknown_081655F8[tableId] instead of floors[] */
    u16 tableId;        /* 0x1A */
    u16 count;          /* 0x1C */
    u16 cursorInit;     /* 0x1E */
    u16 floors[8];      /* 0x20: floor numbers of the current map */
    u16 unk30;          /* 0x30: elevator door sprite offsets (see sceneeffect.h) */
    u16 unk32;
};
#define FLOOR_MENU(task) ((struct FloorMenu *)(task)->data.raw)

u32 sub_080C8B3C(u16 map);
u32 *FieldMap_CellRecordsOffset(u16 dx, u16 dy);
void LZ77UnCompWram(const void *src, void *dest);
void CpuSet(const void *src, void *dest, u32 control);
void Sprite_Draw(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);

extern struct Task *gUnk_03003FEC;
extern u8 gUnk_02001000[];
extern u16 gUnk_02000000[];
extern const u8 gUnknown_08002CBC[], gUnknown_08002CCC[];
extern const u16 gUnknown_084C0D50[];
extern const u32 gUnknown_08165694[], gUnknown_08173594[];
extern const void *const gUnknown_08173488[][4];
extern const void *const gUnknown_081734E8[][5];
extern const void *const gUnknown_08173560[];

struct PalFade
{
    u16 active;
    u16 pad02;
    u16 unk04;
    u8 pad06[0x4A];
};
extern struct PalFade gPalFades[8];
void *PalFade_FadeRangeToBlack(u16 start, u16 count, u16 delay);
void *PalFade_FadeRangeToBlackWithDuration(u16 start, u16 count, u16 delay, u16 duration);
u32 Palette_IsBg13Black(void);
void sub_08157EB0(u32 a, u32 b, u32 c);
struct Task *Char_FindById(u16 id);
void Char_EndById(struct Task *task, u16 id);
void sub_080C1440(void);
void sub_080C33AC(u16 a);
void sub_080C3328(u16 a);
void m4aSongNumStop(u16 n);
void *VBlankTask_AddCountedAlways(VoidFunc func, u16 count);
void IntrDummy(void);
void sub_080D977C(void);

extern VoidFunc gMainCallback;
extern VoidFunc gIntrTable[14];
extern const s16 gSineTable[];
extern u16 gScriptItemCheckId;
extern u32 gFrameCounter;
extern void *gMsgWindow;
extern u16 gMsgWindowOpen;
extern u16 gUnk_03000004, gUnk_03000006, gUnk_0300000C, gUnk_03000042, gUnk_03000044;
extern u8 gUnk_03000030, gUnk_03000031, gUnk_03000032, gUnk_03000033, gUnk_03000034, gUnk_03000035, gUnk_03000036, gUnk_03000037;

void sub_080E8F80(u32 a0, u32 x, u32 y, u32 a3);
void *PalFade_FadeRangeToWhite(u16 start, u16 count, u16 delay);
void *PalFade_FadeInFromBlack(u16 delay);
void PalFade_Init(u32 keepPalettes);
void sub_080C51BC(u32 a);
void sub_080C3818(u32 a);
void sub_0813EE90(u32 a, u32 b);
void sub_080C1450(void);
void sub_080ADF64(void);
void Font_ResetGlyphSpriteCache(u32 baseTile);
void sub_080C1328(void);
void sub_080C1384(void);
void sub_080C14FC(void);
void sub_080C153C(void);
void Party_BuildMemberNameTiles(void);
void sub_080C6FD8(void);
void sub_080C65C8(void);
void sub_080C6764(void);
void sub_080AE304(void);
void BgPicture_LoadAll(void);
void SetMainCallback(VoidFunc func);
void FieldMain_Loop(void);

struct WinRect
{
    u16 x;
    u16 y;
    u16 w;
    u16 h;
    u16 bg;
    u16 curH;
    u16 unkC;
    u16 altFrame;
};
void Window_DrawFrame(struct WinRect *rect, u16 x, u16 y, u16 w, u16 h);
void WindowMap_QueueUpload(u32 bg);

struct CharObj;
struct CharGfxRecord
{
    u32 unk00;
    const void *gfx0;   /* 0x04 */
    const void *gfx1;   /* 0x08 */
};
struct CharGfxRecord *Char_GetRecord(u16 id);
void Char_LoadGfxHalf(struct CharObj *obj, const void *src, u32 a2, u32 half, u32 a4);
extern struct Task *gCharTasks[8];

/* Battle/arena state at 0x0203C200 (only the fields used here). */
struct Unk0203C200
{
    u8 pad000[0x990];
    u32 unk990;         /* 0x990: event id 0x103.. */
    u8 pad994[0xDAA - 0x994];
    u16 unkDAA;
    u8 padDAC[0xDEA - 0xDAC];
    u16 unkDEA;
};
extern struct Unk0203C200 gUnk_0203C200;
extern struct Task *gSceneEffectTask;
extern u8 gUnk_02028074[];
extern const void *gUnk_03003B94;

/* Door records (gUnknown_08198278, ended by x == 0xFF). */
struct DoorRec
{
    u8 x;
    u8 yDir;            /* y in bits 0-5, facing in bits 6-7 */
    u8 kind;            /* bits 0-3: 1/2 script door, 3 keypad door; bits 4-7: stat index */
    u8 id;              /* keypad code index / required stat value */
};
extern const struct DoorRec gUnknown_08198278[];
extern const u8 gUnknown_081982FD[];
extern const u32 gUnknown_08198128[], gUnknown_08198554[], gUnknown_08198648[], gUnknown_08198328[];
extern const u16 gUnknown_08002EFE[], gUnknown_08003192[];
extern const u16 *const gUnknown_0819853C[];
extern u32 gYesNoResult;
extern u16 gUnk_03003FF4;
u32 *Door_KeypadInitInputState(void);

u8 *Battle_GetCombatant(u16 idx);
u16 sub_080C1B50(void);
u32 Moon_GetPhase(void);
extern const u16 gUnknown_0819873C[], gUnknown_08198748[], gUnknown_0819875E[], gUnknown_0819876C[],
    gUnknown_08198780[], gUnknown_08198794[], gUnknown_081987A8[], gUnknown_081987BA[], gUnknown_081987C8[],
    gUnknown_081987D4[], gUnknown_081987E6[], gUnknown_081987FC[], gUnknown_0819880E[], gUnknown_08198822[],
    gUnknown_08198834[];
extern const u32 gUnknown_08198848[];
struct Unk030069F0
{
    u8 pad00[0x2C];
    u32 unk2C;
    u16 unk30;
    u16 unk32;
};
extern struct Unk030069F0 gUnk_030069F0;

s16 ScriptVM_RunAlt(const void *script);
void sub_080AF178(u16 a, const void *script);
const u8 *sub_080C5F40(u16 id, u32 half);
const void *sub_080C5F04(u16 id, u16 piece);
void sub_080C140C(u32 a, u32 b);
void Tilemap_OffsetRect(u16 (*map)[32], u16 tileAdd, u16 palette, u16 x, u16 y, u16 w, u16 h);
void Field_CopyIwramCode(void);
u8 *Action_GetRecord(u16 id);
u8 *Equipment_GetRecord36_MidRange(u16 id);
u8 *Item_GetRecord(u16 id);

/* One sub-map of a dungeon map (0x268 bytes). */
struct SubMap
{
    u8 pad00[8];
    u16 x0;             /* 0x08: covered world rectangle */
    u16 y0;
    u16 x1;
    u16 y1;
    u8 pad10[0x268 - 0x10];
};
s32 SubMap_IsOutsideExclusions(struct SubMap *h, u16 x, u16 y);

extern const u16 gUnknown_08198978[][3];
extern const void *const gUnknown_08198A98[];
extern const u32 gUnknown_08198AD0[];
extern const u8 gUnknown_08198B74[];
extern const u8 gUnknown_08198EB4[];
extern const u16 gUnknown_081B8370[], gUnknown_0857D9C0[];
extern u32 gUnk_03003FF8;

u16 sub_080F6278(void);
u16 sub_080F6390(void);
void Party_BuildSkillList(u32 who);
void Combatant_SetEquip(u32 a, u32 b, u32 c);
void Combatant_RecalcStats(u32 a);
extern u8 gUnk_030050C0[], gUnk_030050C8[], gUnk_030050D0[];
extern const u8 gUnknown_0819B9F4[], gUnknown_0819CB74[];
extern const u8 gUnknown_081A5A00[], gUnknown_081A5A20[], gUnknown_081A5A38[], gUnknown_081A59FC[], gUnknown_081A5A50[];
extern const u16 gUnknown_081A59F4[];

/* Records returned by Demon_GetRecord (only the name is used here). */
struct DemonRecord
{
    u8 pad00[0x22];
    u16 name[8];        /* 0x22 */
    u8 pad32[0x60 - 0x32];
};
extern struct DemonRecord gUnk_03005FC0;   /* copy made by Demon_GetRecord */

/* 28-byte records of gUnknown_0819B9F4 (only the name is used here). */
struct NameRecord28
{
    u8 pad00[6];
    u16 name[8];        /* 0x06 */
};
const u8 *sub_080BF5C0(u16 id);

/* 0x080B89B0.. */
void sub_080B9058(void);
void sub_080B9080(void);
void sub_080B9390(void);
void sub_080B9414(void);
u16 *Location_GetNameCellFromCoords(u16 map, u16 floor, u16 x, u16 y);
u16 *FieldMap_GetElevatorRecord(void);
u16 sub_080B9764(void);
const struct FloorTable *Elevator_GetFloorTable(struct FloorMenu *m);
const struct FloorRef *Elevator_GetFloorRef(struct FloorMenu *m, u16 i);
struct MapHeader *Elevator_GetFloor(struct FloorMenu *m, u16 i);
u16 Elevator_GetFloorCount(struct Task *task);
void Elevator_SetCursorToCurrentFloor(struct Task *task);
void Elevator_DrawFloorLabel(struct Task *task, struct MapHeader *floor, u32 row);
void sub_080BA2F0(struct Task *task);
void Elevator_BuildFloorList(struct FloorMenu *d, const u16 *rec);

/* 0x080BD878.. */
void sub_080BD8C8(void);
void Wave_VBlank(void);
void Wave_Disable(void);
void Wave_HBlank(void);
void Wave_Start(void);
void Wave_Stop(void);
void sub_080BDCC8(void);
void sub_080BE504(void);
void sub_080BE530(void);
const struct DoorRec *Door_FindAtPlayer(void);
void Bcd_Unpack3(const u8 *src, u8 *dst);
u32 sub_080BECA4(void);
u32 sub_080BECCC(void);
u32 RandomEvent_CheckCell(void);
void sub_080BEE74(void);
void sub_080BEEB0(void);
void sub_080BEF1C(void);
void sub_080BF1B8(void);
void sub_080BF254(void);
/* Data of the party-heal tasks (sub_080B8FF0 / sub_080B9014). */
struct HealData
{
    const u16 *params;  /* 0x00: params[1] = kind */
    u16 unk04;          /* 0x04 */
    u16 pad06;
    u16 amount[6];      /* 0x08: per party slot */
};
#define HEAL_DATA(task) ((struct HealData *)(task)->data.raw)

struct Task *sub_080B8AE0(u16 a, u16 b);
u32 sub_080B8B08(struct Task *t);
struct Task *sub_080B8B68(u16 a, u16 b);
u32 sub_080B8C18(u16 mode);

#endif /* GUARD_FIELDCMD_H */
