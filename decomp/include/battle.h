#ifndef GUARD_BATTLE_H
#define GUARD_BATTLE_H

#include "global.h"

/* Battle logic 0x080ED000-0x080F2AC7. Declarations copied from bflow.h / btext.h are kept
   here so this header can be used alone. */

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

struct SortEntry
{
    u16 id;
    s16 key;
};

/* Battle state at 0x0203D16C (= 0x0203C200 + 0xF6C), reached through gUnk_03006434. */
struct BattleState
{
    u16 flags;          /* 0x00 */
    u16 unk2;           /* 0x02 */
    u16 unk4;           /* 0x04 */
    s16 unk6;           /* 0x06: non-zero = two-sided battle (Battle_IsTwoSided) */
    u8 filler8[0xC - 0x8];
    struct SortEntry order[15]; /* 0x0C: action order, ended by id 0xFFFF */
    u8 filler48[0x4C - 0x48];
    u32 unk4C;          /* 0x4C */
    u32 unk50;          /* 0x50 */
    s16 unk54;          /* 0x54 */
    u16 unk56[8];       /* 0x56 */
    u8 filler66[0x68 - 0x66];
    u32 unk68[4];       /* 0x68: per party member */
    s16 unk78[6][14];   /* 0x78: [0] = status flags per combatant (sub_080ED8C0 index) */
    s16 unk120;         /* 0x120 */
    s16 unk122;         /* 0x122: acting side (Battle_ActiveSide) */
    u16 unk124;         /* 0x124 */
    s16 unk126;         /* 0x126 */
    s16 unk128[2];      /* 0x128: per side */
    s16 unk12C[2];      /* 0x12C: per side */
    struct SortEntry targets[10];   /* 0x130: target list, ended by id 0xFFFF */
    u16 unk158;         /* 0x158 */
    u16 unk15A;         /* 0x15A */
    s32 unk15C;         /* 0x15C */
    u32 unk160[8];      /* 0x160 */
};

extern struct BattleState *gUnk_03006434;
extern u8 *gUnk_03006438;
#define BSTATE gUnk_03006434

struct BattleUnit       /* 0x80 bytes; same layout as the party records in gGameState */
{
    u8 filler0[0xE];
    u16 unkE;           /* non-zero = slot used */
    u16 flags;          /* 0x10: 0x8000 = dead/absent */
    u8 filler12[0x6E];
};

/* The battle EWRAM block at 0x0203C200. Only fields used here are named. */
struct BattleFlow
{
    u8 filler0[0x974];
    void *window;               /* 0x974 */
    u8 filler978[0x97C - 0x978];
    u16 unk97C;                 /* 0x97C */
    u16 unk97E;                 /* 0x97E */
    u8 filler980[0x984 - 0x980];
    u32 unk984;                 /* 0x984 */
    u8 filler988[0x990 - 0x988];
    u32 combatants[2];          /* 0x990 */
    u8 filler998[0x9A0 - 0x998];
    struct BattleUnit units[11];    /* 0x9A0 */
    u8 fillerF20[0x118C - 0xF20];
    u16 unk118C;                /* 0x118C */
    u16 unk118E;                /* 0x118E */
    u8 filler1190[0x11A8 - 0x1190];
    u16 unk11A8;                /* 0x11A8 */
    u8 filler11AA[0x11AC - 0x11AA];
    u16 unk11AC;                /* 0x11AC */
    u16 unk11AE;                /* 0x11AE */
    u16 unk11B0;                /* 0x11B0: critical-hit kind of the last damage roll */
};

extern u8 gUnk_0203C200[];
#define BFLOW ((struct BattleFlow *)gUnk_0203C200)

void CpuSet(const void *src, void *dest, u32 control);
u32 __udivsi3(u32 a, u32 b);

/* elsewhere */
void sub_080EA210(void);
u16 *Menu_ExpandListTemplate(const u16 *tmpl, u32 arg);
u16 *MessageBox_ComposeSpeciesText(u32 a0, u32 a1, u32 a2, u32 a3, const u16 *tmpl);
u16 *MessageBox_ComposeNameText(u32 who, const u16 *tmpl);
void BattleMenu_SetMode(u8 mode, u16 *src);
void BattleMenu_Reset(void);
u8 BattleMsg_IsDone(void);
void Window_Close(void *window, u32 arg1);
u8 *Party_GetMember(u16 id);
u16 Combatant_GetStatus(u32 who);
void Party_Remove(u16 a, u32 b);
void sub_080C366C(void);
void Party_BuildMemberNameTiles(void);
void sub_080C6FD8(void);
u32 Random_Byte(void);
u8 *sub_080C5D48(u16 id);
u32 Flag_Test(u32 flag);
u8 *Demon_GetRecord(u16 id);
u8 *sub_080BF5C0(u16 id);
s32 Race_GetParentId(s32 race);
s32 Battle_GetMp(s32 a);
void Battle_SetMp(s32 a, s16 v);
s32 Battle_GetHp(s32 a);
s32 Battle_GetMaxHp(s32 a);
void Battle_SetHp(s32 a, s16 v);
void Combatant_SetStatus(s32 a, u32 b);
void Combatant_ClearSlot(s32 a);

s16 Combatant_GetDemonId(u32 a);
u32 Moon_GetPhase(void);
void *memcpy(void *dst, const void *src, unsigned long n);

u8 *Battle_GetCombatant(u16 idx);
s32 sub_080C35E4(s32 who);
u32 Party_GetRow(s32 who);
s32 Math_DivRound(s32 a, s32 b);

u32 View_GetWall(u16 dir, u16 dx, u16 dy);
s32 Combatant_IsDead(s32 id);
s32 Combatant_IsUsed(s32 id);
u16 Combatant_GetAgility(s32 id);
u16 Combatant_GetLuck(s32 id);
u32 BattleFlags_Get(void);
s32 sub_080F43A4(s32 a);
s32 sub_080F43E0(s32 a);
s32 sub_080EFD84(s32 who);
s32 __divsi3(s32 a, s32 b);

s32 Combatant_IsAlignmentCompatible(s32 who, s32 target);
s32 sub_080F40EC(s32 slot);

void sub_08126834(s32 n);
s32 Combatant_IsAlive(s32 id);
void Battle_CopyEnemyUnit(s32 base, s32 slot);
void Combatant_RestoreHp(s32 id);
void Combatant_RestoreMp(s32 id);
void sub_080E760C(void);
void Combatant_ClearStatus(s32 id, u32 mask);
int rand(void);
u32 __umodsi3(u32 a, u32 b);
void Battle_RemoveDefeated(s32 a, s32 b);
u16 sub_080F030C(u16 a, u16 b);
s32 sub_080ED4A8(s32 id);
s32 sub_080EF5D0(s32 x);

u32 Combatant_GetEquip(s32 who, s32 slot);
void Item_GetAttribute(s32 id, s32 field, s32 *out);
void Combatant_AddAlignment(s32 a, s32 b);
s32 Combatant_GetSkill(s32 who, s32 i);
s32 Combatant_CountSkillsWithFlags(s32 who, s32 flag);
s32 sub_080F3190(void);
u32 sub_080ED694(s32 id);
s32 sub_080EF5E8(s32 id);
s32 sub_080EF8D0(void);
s32 sub_080EF90C(void);
void sub_080EF930(s32 v);
s32 sub_080EF954(void);
void sub_080EF978(s32 v);
void sub_080EFA20(s32 d);
void sub_080EFA44(s32 d);
s32 sub_080ED8C0(s32 who);
s32 sub_080EF828(void);
s32 sub_080EF710(s32 who);
s32 sub_080EF6E8(s32 who, s32 i);

s32 Battle_AddModifierClamped(s32 row, s32 who, s32 d);
s32 sub_080EFC9C(s32 row, s32 who, s32 d);

s32 Combatant_GetChosenSkill(s32 who);
u32 sub_080ED6A4(s32 id);
s32 sub_080EFFD8(s16 kind, s32 x);

void Stats_CalcDerived(u8 race, u8 *stats, u8 *out);
void Name_Encode(u8 *src, u8 *unit);
s32 Battle_IsEnemyId(s16 who);
void sub_080EE2E8(s16 who);
void Battle_BuildTargetList(s32 who);

s32 Combatant_GetAffinity(s32 who, s32 a);
u8 sub_080F3214(s32 who, s32 a);
s16 sub_080EE810(s32 id, s32 who);
void sub_080EDA7C(u32 v);
s32 sub_080EFBFC(s32 who);
s32 sub_080EFD3C(s32 who);
u32 sub_080EED64(u16 kind, u16 id);
s32 Battle_FinishDamage(u8 *a, u8 *d, s32 power);

struct Action             /* one queued battle action */
{
    s32 att;                /* 0x00 */
    s32 def;                /* 0x04 */
    s32 msg;                /* 0x08 */
    u8 filler0C[0x18 - 0xC];
    s32 dmg;                /* 0x18 */
};

u32 sub_080ED794(s32 id);
s32 sub_080EFDCC(s32 who);
s32 Battle_PhysicalDamage(s32 att, s32 def);
void sub_080F49B4(struct Action *act, s32 i);

void sub_080ED90C(u16 v);
void BattleFlags_Mask(s32 v);
void sub_080EFB8C(s32 who, s32 mask);
s32 sub_080EFAB0(s32 who);
void sub_080ED920(u32 v);
s32 sub_080EF878(void);
void sub_080EDA04(void);
void sub_080E74DC(void);
u32 sub_080EF224(s32 pos, s32 count);
void sub_080F41B0(void);
void Stock_AddDemon(u16 id);
void Stock_FindFreeSlot(void);
s32 Combatant_GetAlignment(s32 who);
u16 sub_080EDA90(void);
void sub_080F3E38(s32 msg);
void BattleFlags_Set(u16 f);
void sub_080F40C4(s32 id);
s32 Combatant_GetLevel(s32 who);
u32 sub_080EF538(s32 id);
u32 sub_080EF580(s32 id);
void sub_080EF6B4(s32 x);
void sub_080E7538(s32 slot, s32 b);
void sub_080F4190(s32 who);
void Party_FindPosition(s32 who);
void sub_080C8490(void);

struct Task *Task_Create(const void *script, u32 parent);
u16 *Battle_GetMessage(u16 id);
void BattleMenu_SetModeAutoClose(u8 mode, u16 *src);
void sub_080C35C4(s32 who, s32 state);
void sub_080F0344(u16 kind, u16 v);

extern const u32 gUnknown_0876F7DC[];
extern const u8 gUnknown_0876F79E[];
extern const u8 gUnknown_0876F6CA[];
extern const u16 gUnknown_0876F75A[][2];
extern u16 gUnk_030000AC;
extern const u8 gUnknown_0876F7CE[];
extern u16 gUnk_0203DB7C;
extern u8 gGameState[];
extern const u16 gUnknown_0876F7C6[];
extern const u16 gUnknown_0876F7BE[];
extern const u8 gUnknown_0876F78E[];
extern s8 gUnk_030050E0[];
extern const u8 gUnknown_0876F6B4[];
extern u8 gUnk_0203A450[];
extern const u16 gUnknown_0876E6D4[];
extern const u8 gUnknown_0876E978[];
extern const u8 gUnknown_0872F234[];
struct RandTable
{
    const u8 *data;     /* rows of cumulative thresholds, 0 = skip */
    s32 stride;
};
extern const struct RandTable gUnknown_0876F660[];
extern const u8 gUnknown_0876F688[];
struct LevelTable       /* gUnknown_0876EBA8, 24 bytes each */
{
    u8 level[8];
    u16 value[8];
};
extern const struct LevelTable gUnknown_0876EBA8[];
extern const u16 gUnknown_0812466C[];
extern const u16 gUnknown_0812464E[];
extern const u16 gUnknown_0812463A[];
extern const u16 gUnknown_08124608[];
extern const u16 gUnknown_081245B4[];
extern const u16 gUnknown_081245F6[];
extern const u16 gUnknown_081245D2[];
extern const u16 gUnknown_0812461A[];

/* this region */
s16 Battle_ActiveSide(void);
u32 Battle_IsTwoSided(void);
u32 sub_080EDA24(s32 side);
u32 sub_080ED9F4(void);
s32 sub_080ED3FC(s32 table, s32 row);
s32 sub_080ED600(s32 row);
s32 sub_080ED464(s32 id);
u32 sub_080ED520(s32 id);
u32 sub_080ED560(s32 id);
u32 sub_080ED6CC(s32 id);
s32 Battle_CountLivingUnits(s32 first, s32 count);
void sub_080ED35C(u32 *a, s32 *b, s8 idx);
u32 sub_080EDB04(void);
u32 sub_080EDAD0(void);
u16 sub_080ED8F4(void);
u32 sub_080ED92C(void);
void Battle_SortEntriesInsertion(u16 lo, u16 hi, struct SortEntry *a);

#endif /* GUARD_BATTLE_H */
