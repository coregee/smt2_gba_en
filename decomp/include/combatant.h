#ifndef GUARD_COMBATANT_H
#define GUARD_COMBATANT_H

#include "global.h"

/* Combatant records, party order and demon-name helpers, 0x080BF908-0x080C2D48.
   Declarations copied from other headers are kept here so this header can be used alone. */

#define DmaSet(dmaNum, src, dest, control)                      {                                                                   vu32 *dmaRegs = (vu32 *)(0x040000B0 + 12 * (dmaNum));           dmaRegs[0] = (vu32)(src);                                       dmaRegs[1] = (vu32)(dest);                                      dmaRegs[2] = (vu32)(control);                                   dmaRegs[2];                                                 }

#define DMA_FILL(dmaNum, value, dest, size, bit)                                    {                                                                                       vu##bit tmp = (vu##bit)(value);                                                     DmaSet(dmaNum, &tmp, dest, (0x8000 | (bit == 32 ? 0x0400 : 0) | 0x0100) << 16 | ((size) / (bit / 8))); }
#define DmaCopy32(dmaNum, src, dest, size) DmaSet(dmaNum, src, dest, (0x8000 | 0x0400) << 16 | ((size) / 4))
#define DmaCopy16(dmaNum, src, dest, size) DmaSet(dmaNum, src, dest, 0x8000 << 16 | ((size) / 2))
#define DmaFill16(dmaNum, value, dest, size) DMA_FILL(dmaNum, value, dest, size, 16)
#define DmaFill32(dmaNum, value, dest, size) DMA_FILL(dmaNum, value, dest, size, 32)

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
    u8 id;              /* 0x0C: own index; 0 = hero, < 4 = human */
    u8 level;           /* 0x0D */
    u16 unkE;           /* 0x0E: 0xC000 in party, 0x8000 stocked, 0 free */
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
    struct CombatantStats bonus;    /* 0x30: from equipment */
    struct CombatantStats extra;    /* 0x38 */
    struct CombatantStats total;    /* 0x40 */
    s16 derived[8];     /* 0x48 */
    u16 unk58;
    u8 pad5A[3];
    u8 skills[32];      /* 0x5D: 0xFF-terminated */
    u8 pad7D[3];
};

/* Demon records (Demon_GetRecord). */
struct DemonRecord
{
    s8 unk0;
    u8 level;
    u16 hp;
    u16 mp;
    u8 stats[6];
    u8 unkC;
    u8 padD[4];
    u8 skills[7];       /* 0x11 */
    u8 pad18[10];
    u16 name[8];        /* 0x22 */
};

struct PlayTimeB
{
    u8 hours;
    u8 minutes;
    u8 seconds;
    u8 frames;
};

union PlayTime
{
    struct PlayTimeB b;
    u8 raw[4];
    u32 all;
};

struct C0bfGameState
{
    struct Combatant members[20];
    u8 names[4][8];     /* 0xA00 */
    s8 order[6];        /* 0xA20: active party, member index or -1 */
    u8 padA26[2];
    u16 moon;           /* 0xA28: moon counter, phase in the high nibble */
    u16 moonPrev;       /* 0xA2A */
    u8 padA2C[0xA36 - 0xA2C];
    u16 unkA36;
    u16 unkA38;
    u8 padA3A[0xA3E - 0xA3A];
    u16 unkA3E;
    u8 padA40[0xAC0 - 0xA40];
    u16 unkAC0;
    u8 padAC2;
    u8 stockMax;        /* 0xAC3 */
    u16 unkAC4;
    u8 padAC6[0xAE4 - 0xAC6];
    union PlayTime playTime;    /* 0xAE4 */
    u8 padAE8[2];
    u16 encounter;      /* 0xAEA: random encounter counter */
    u8 padAEC[0x1054 - 0xAEC];
    u8 bits1054[0x10D4 - 0x1054];   /* demons seen */
    u8 bits10D4[0x1106 - 0x10D4];
    u8 bits1106[0x114C - 0x1106];
    struct
    {
        u16 a;
        u8 pad[6];
    } unk114C[8];
    u8 pad118C[0x15E8 - 0x118C];
    u8 flags[0x1750 - 0x15E8];      /* story flags (Flag_Test) */
    u8 bits1750[0x18A6 - 0x1750];
    u16 unk18A6;
    u8 pad18A8[0x18B4 - 0x18A8];
    u8 unk18B4;
    u8 unk18B5;
    u8 unk18B6;
    u8 pad18B7[0x18BB - 0x18B7];
    u8 unk18BB;
    u8 pad18BC[0x18D4 - 0x18BC];
    u8 unk18D4;
    u8 pad18D5[0x18F8 - 0x18D5];
};

/* gFieldState (0x03004550): only the fields used here. */
struct C0bfFieldState
{
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u8 pad06[0x12 - 0x06];
    u16 x;              /* 0x12 */
    u16 y;              /* 0x14 */
};
extern struct C0bfFieldState gFieldState;

extern struct C0bfGameState gGameState;

extern const u16 gUnknown_081A5A6C[];   /* name character -> glyph */
struct C0bfStatBonus { u8 item; u8 b; u8 c; u8 d; };
extern const struct C0bfStatBonus gUnknown_081A6ED4[];   /* stat bonuses, two 4-bit values per byte */

struct Combatant *Battle_GetCombatant(u16 idx);
u8 *Equipment_GetRecord36_MidRange(u16 id);
u8 *Item_GetRecord(u16 id);
void Item_GetAttribute(s32 id, s32 field, void *out);
u8 sub_080C32D4(u16 id);
s32 __divsi3(s32 a, s32 b);
u32 Flag_Test(u32 flag);
u8 *Demon_GetRecord(u16 id);
void sub_080C35C4(s32 who, s32 state);
void sub_080C3600(s32 who, s32 state);
u32 sub_080C351C(u16 demonId);
void sub_080C2674(u32 id);
void sub_080C28F8(u32 id);
u16 sub_080C2600(u16 id);
u32 sub_080C2734(u32 i);

extern const s8 gUnknown_081A5C2C[];
extern const u16 gUnknown_081A6044[];
extern const u16 gUnknown_081A6064[];
extern const u8 gUnknown_081A6084[];
extern const s32 gUnknown_081A60B4[];   /* experience per level */
extern const u8 gUnknown_081A6244[4][8];   /* default names */
extern const u32 gUnknown_081A91B8[];
extern const u32 gUnknown_081B13B8[];
extern const u16 gUnknown_081B6E30[];
extern const u16 gUnknown_081B6C30[];
extern u16 gPaletteTarget[];
extern u32 gUnk_0200AB04;
extern u32 gUnk_03004610;
extern u32 gUnk_03004514;
extern u32 gUnk_03004614;
extern u32 gUnk_03004544;
extern u32 gUnk_030045FC;
extern u16 gDispRegs, gUnk_03000002, gUnk_03000004, gUnk_03000006, gUnk_03000008, gUnk_0300000A,
    gUnk_0300000C, gUnk_0300000E, gUnk_03000040, gUnk_03000042, gUnk_03000044;
extern u8 gUnk_03000030, gUnk_03000031, gUnk_03000032, gUnk_03000033, gUnk_03000034,
    gUnk_03000035, gUnk_03000036, gUnk_03000037, gUnk_03000038, gUnk_03000039, gUnk_0300003A;
extern u16 gUnk_0200E7D4[];
extern u16 gUnk_02000000[];   /* EWRAM tilemap work buffer */
extern u32 gUnk_03003FF8;
extern u16 gUnk_03003FF4;
extern u32 gUnk_03003FC4;
extern u32 gUnk_03004618, gUnk_03004624;
extern u16 gUnk_030069F0[];
extern u32 gUnk_03002B50[];
extern const u32 gUnknown_081B8370[];
extern const u16 gUnknown_081B8270[];
extern const u16 gUnknown_081A6264[];
extern const u16 gUnknown_081A626A[];

void VBlankTasks_Init(void);
void Windows_Init(void);
void Font_ResetGlyphSpriteCache(u32 baseTile);
void Tilemap_OffsetRect(void *map, u16 tileAdd, u16 palette, u16 x, u16 y, u16 w, u16 h);
void Tilemap_CopyRectSkipZero(const void *src, void *buf, u32 a2, u32 a3, u32 x, u32 y, u32 w, u32 h);
void sub_080C65E8(void);
void sub_080C6734(void);
void sub_080AD7F0(void);
void sub_080AE234(void);
void Field_SetPosition(u16 x, u16 y);
void sub_080B30A0(u16 map);
void Map_LoadGraphicsStep(u16 map, u16 sub, u32 *done);
void sub_080ADFEC(u16 mode);
void Task_ClearAll(void);
void sub_080AE364(u16 mode);
u32 FieldMap_HasRecordRel(u16 a, u16 b, u16 c);
u32 sub_080AF8D0(u32 a, u32 b, u32 c);
void Palette_FillWithEffect(u32 a0, u32 a1, void *dest, u32 size, u32 a4);
u32 sub_080D0E74(void);
void sub_080C5170(u16 se);
u16 sub_080AD608(u16 a, u16 b);
u16 sub_080AD67C(u16 id);
void sub_080E44A4(void);
void *PalFade_FadeInFromBlack(u16 delay);
u16 PalFade_AllDone(void);
void CpuSet(const void *src, void *dest, u32 control);
void Field_SetState(u16 state);
void sub_080E5220(void);
void sub_080B0C90(void);
void Task_RunAll(void);
void sub_080C6804(void);
void sub_080C2EFC(void);
void sub_080C7CC8(void);
void sub_080C7CD8(void);
void sub_08151EEC(u16 a, u16 b, u16 c);
u32 sub_080C5108(void);
void sub_080B9058(void);
void sub_0815201C(void);
void sub_080F3F58(s32 v);
u32 sub_080F3F44(void);
void Flag_Set(u32 flag);
void Flag_Clear(u32 flag);
void sub_080CDC34(void);
void sub_080C84A0(void);
extern s8 gUnk_030050E0[];
extern u16 gUnk_0200E844;
extern u16 gUnk_0203A450[];
u16 sub_080C4F88(u16 a);
void sub_080B8B68(u32 a, u32 b);
void sub_080C51D4(u32 se);
void sub_080C4E48(u16 a, u32 *mask);
void sub_080C4C98(void);
u32 sub_080C3168(void);
s32 sub_080ED584(s32 demonId);
u32 sub_080C3114(s32 delta);
void sub_080C8490(s32 pos);
u16 *DungeonMap_GetFloor(u16 map, u16 floor);
u32 sub_080C5D0C(void);
void sub_080ED398(u32 *a, u32 *b, u32 zone);
void sub_080F450C(u32 *a, u32 *b);
u32 sub_080ED5B4(u32 enc, u32 i);
u8 *sub_080C5D48(u32 zone);
u8 *sub_080C5D98(void);
u32 Random_Next(void);
extern u8 gUnk_03004680[];
extern u8 gUnk_03004690[];
extern u8 gUnk_03004650[];
extern u8 gUnk_03006090[];
extern u32 gOptions;     /* options word (SRAM 0x0E000010) */
extern u16 gColorEffect[];
extern u16 gPaletteBuffer[];
extern const u16 gUnknown_081A6272[][2];
void sub_080C90FC(u32 flag);
u32 sub_080C90F8(u32 i);
u32 Dict_GetMapScript(u16 id);
u32 Sram_WriteVerified(const void *src, void *dst, u32 size);
u32 Sram_ReadVerified(const void *src, void *dst, u32 size);
void sub_080C3328(u16 id);
void Palette_MarkDirty(void);
void sub_080C1880(void);
void Moon_Advance(u16 n);

void sub_080F4190(s32 who);
s32 sub_080F401C(s32 a);
void sub_080C366C(void);
void sub_080C65C8(void);
u32 sub_080ED560(s32 id);
u16 sub_08131AB0(s16 a, u16 item);
void Party_InitMember(struct Combatant *c, u32 i);
void sub_080BF8D8(u32 i);
void Automap_SetVisitedRaw(u16 x, u16 y);
void Automap_ClearVisitedRaw(u16 x, u16 y);
void sub_080E4520(void);
void sub_080C271C(void);
void sub_080C27F0(void);
void sub_080C2968(void);
void ComboBits_Clear(void);
void SetMainCallback(void (*func)(void));
void sub_080C1560(void);
void Palette_CopyWithEffect(u32 a0, const void *src, void *dst, u32 a3, u32 a4);
void sub_080C67C0(void *a, u32 b);
extern const u8 gUnknown_081A5C34[][16];   /* race names */
extern const u8 gUnknown_081A5F24[][16];   /* parent race names */
extern const u8 gUnknown_081A6014[][16];

/* this region */
void sub_080BF908(s8 id, s16 *a, s16 *b);
void Combatant_RecalcStats(s32 who);
void Combatant_ApplyBackRow(s32 who, s32 mode);
void Equipment_SumStatBonuses(s8 *equip, u8 *out);
s32 Stat_CapBonus(s32 base, s32 bonus);
s32 sub_080BFE98(s32 a, s32 b, s32 c);
void sub_080BFEA8(struct Combatant *c);
void sub_080BFF0C(struct Combatant *c);
void sub_080BFF8C(u8 *a, u8 *b, u8 *out);
s32 Party_FindPosition(s32 id);
s32 Party_GetRow(s32 id);
u32 Combatant_GetEquip(s32 who, s32 slot);
struct Combatant *Party_GetMember(u16 id);
struct C0bfIds { s8 b[8]; };   /* filled with 0xFF, then used as u16 item ids */
u32 sub_080C0010(s32 who, struct C0bfIds *out);
void Combatant_SetEquip(s32 who, s32 slot, s32 item);
struct Combatant *Stock_FindDemon(u16 demonId);
u32 Party_Add(u16 who);
u32 Party_AddAt(u16 who, u16 slot);
void Party_Remove(u16 who, u16 release);
void Combatant_DecodeName(const u8 *name, u16 *out);
void sub_080C0378(const u8 *name, u16 *out);
u8 sub_080C03A8(u16 glyph);
u8 Name_EncodeChar(u16 glyph);
void Name_Encode(const u16 *glyphs, u8 *out);
void Combatant_InitDemon(struct Combatant *c, s32 who, s32 demonId);
void Member_InitDemon(s32 who, s32 demonId);
void Stats_CalcDerived(s32 level, const s8 *st, s16 *out);
void Combatant_CalcDerived(struct Combatant *c);
s32 Stock_AddDemon(u16 demonId);
const u8 *Race_GetName(u16 race);
const u8 *ParentRace_GetName(u16 race);
const u8 *sub_080C06AC(u16 id);
s32 Combatant_GetAlignment(s32 who);
s32 Combatant_AddAlignment(s32 who, s32 delta);
void sub_080C0774(s32 who, s32 v);
u16 sub_080C0794(s32 who);
s32 Alignment_AreCompatible(s32 a, s32 b);
s16 Combatant_GetDemonId(s32 who);
s16 sub_080C07FC(s32 who);
u16 Combatant_GetStatus(s32 who);
u32 Combatant_IsDead(s32 who);
void Combatant_OnStatusChange(s32 who, u16 newFlags, u16 oldFlags);
void Combatant_ClearStatus(s32 who, u16 mask);
u32 Combatant_SetStatus(s32 who, u16 bits);
s32 Combatant_ChangeHp(s32 who, s32 delta);
void Combatant_Damage(s32 who, s32 damage);
s32 Combatant_ChangeMp(s32 who, s32 delta);
u16 Combatant_GetStrength(s32 who);
u16 Combatant_GetIntelligence(s32 who);
u16 Combatant_GetMagic(s32 who);
u16 Combatant_GetVitality(s32 who);
u16 Combatant_GetAgility(s32 who);
u16 Combatant_GetLuck(s32 who);
s32 Stat_ClampBase(s32 v);
s32 Combatant_AddBaseStat(s32 who, u32 stat, s32 delta);
s32 Stock_GetCapacity(void);
void sub_080C1328(void);
void sub_080C1384(void);
void sub_080C1630(void);
void sub_080C1684(void);
void sub_080C17F0(void);
void FieldMain_Loop(void);
void sub_080C1A58(void);
void sub_080C1A9C(void);
s32 sub_080C1B50(void);
u16 sub_080C1CAC(u16 who);
u32 Moon_GetPhase(void);
u32 Moon_PhaseChanged(void);
void PlayTime_Tick(void);
u32 Random_Byte(void);
void sub_080C245C(u32 a);
void sub_080C1AF4(void);
void sub_080C1E60(u32 *mask);
u32 sub_080C2000(s32 mode);
u32 sub_080C2090(void);
u16 Encounter_GetCounter(void);
void Encounter_SetCounter(u16 v);
s32 Math_DivRound(s32 a, s32 b);
u32 sub_080C2254(s32 base, s32 level);
s32 Combatant_IsUsed(s32 who);
void sub_080C2A1C(u32 id);

#endif
