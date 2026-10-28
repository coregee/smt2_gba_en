#ifndef GUARD_BATTLE2_H
#define GUARD_BATTLE2_H

#include "global.h"

/* Battle code 0x080F2AC8-0x080F6387. Declarations copied from battle.h and others are kept
   here so this header can be used alone. */

/* One party member / stock demon / enemy: 0x80 bytes (gGameState.members[], battle units). */
struct Combatant
{
    u8 name[12];
    u8 race;            /* 0x0C */
    u8 level;           /* 0x0D */
    u16 unkE;           /* 0x0E: 0xC000 in party, 0x8000 stocked, 0 free */
    u16 flags;          /* 0x10 */
    s16 demonId;        /* 0x12 */
    u16 unk14;
    u8 unk16;
    u8 unk17;
    s16 hp;             /* 0x18 */
    s16 maxHp;          /* 0x1A */
    s16 mp;             /* 0x1C */
    s16 maxMp;          /* 0x1E */
    s8 equip[7];        /* 0x20 */
    u8 pad27;
    s8 base[6];         /* 0x28: base stats */
    u8 pad2E[0x5C - 0x2E];
    u8 unk5C;           /* 0x5C: chosen skill */
    u8 skills[32];      /* 0x5D: skill list, 0xFF-terminated */
    u8 pad7D[0x80 - 0x7D];
};

struct C0f2GameState
{
    struct Combatant members[20];
    u8 names[4][8];     /* 0xA00 */
    s8 order[6];        /* 0xA20: active party, member index or -1 */
    u8 padA26[0xAC0 - 0xA26];
    u16 unkAC0;         /* 0xAC0 */
    u8 padAC2[0x1146 - 0xAC2];
    u16 unk1146;        /* 0x1146: one-shot battle flags (0x200: next affinity check returns 0) */
    u8 pad1148[0x18BB - 0x1148];
    u8 unk18BB;         /* 0x18BB */
};

extern struct C0f2GameState gGameState;

struct BattleUnit       /* 0x80 bytes; same layout as the party records in gGameState */
{
    u8 filler0[0xE];
    u16 unkE;           /* 0x0E: non-zero = slot used */
    u16 flags;          /* 0x10: 0x8000 = dead/absent */
    u16 id;             /* 0x12: demon id */
    u8 filler14[0x17 - 0x14];
    u8 unk17;           /* 0x17 */
    s16 hp;             /* 0x18 */
    s16 maxHp;          /* 0x1A */
    u8 filler1C[0x5C - 0x1C];
    u8 unk5C;           /* 0x5C */
    u8 filler5D[0x80 - 0x5D];
};

#define DmaSet3Wait(src, dest, control)          {                                                    vu32 *dmaRegs = (vu32 *)(REG_BASE + 0xD4);       dmaRegs[0] = (vu32)(src);                        dmaRegs[1] = (vu32)(dest);                       dmaRegs[2] = (vu32)(control);                    dmaRegs[2];                                      while (dmaRegs[2] & 0x80000000)                      ;                                        }

#define DmaFill3Wait(value, dest, control)       {                                                    vu32 tmp = (value);                              DmaSet3Wait(&tmp, dest, control);            }

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
    u16 unk1E;          /* 0x1E */
    void (*onFrame)(struct Task *);
    union
    {
        u32 w[0x10];
        u16 h[0x20];
        u8 raw[0x40];
    } data;             /* 0x24 */
};

struct Portrait
{
    u8 filler0[0xC];
    u16 unkC;           /* 0x0C */
};

/* The battle EWRAM block at 0x0203C200. Only fields used here are named. */
struct BattleFlow
{
    u8 filler0[0x4];
    struct Task *task04;            /* 0x004 */
    u8 filler8[0x4C - 0x8];
    struct Task *win4C;             /* 0x04C */
    struct Task *win50;             /* 0x050 */
    struct Task *win54;             /* 0x054 */
    u8 filler58[0x693 - 0x58];
    u8 unk693;                      /* 0x693 */
    u8 unk694;                      /* 0x694 */
    u8 unk695;                      /* 0x695 */
    u8 filler696[0x974 - 0x696];
    void *window;                   /* 0x974 */
    s16 state;                      /* 0x978 */
    s16 substate;                   /* 0x97A */
    u16 unk97C;                     /* 0x97C */
    s16 unk97E;                     /* 0x97E */
    u8 filler980[0x990 - 0x980];
    u32 combatants[2];              /* 0x990 */
    u16 unk998;                     /* 0x998 */
    u16 unk99A;                     /* 0x99A */
    u8 filler99C[0x9A0 - 0x99C];
    struct BattleUnit units[8];     /* 0x9A0: combatants 0x10-0x17 */
    u8 fillerDA0[0xF50 - 0xDA0];
    s16 unkF50[8];                  /* 0xF50: per enemy unit */
    u8 fillerF60[0xF66 - 0xF60];
    s16 unkF66;                     /* 0xF66 */
    u8 fillerF68[0x113C - 0xF68];
    s16 unk113C;                    /* 0x113C */
    u8 filler113E[0x1160 - 0x113E];
    struct Portrait portrait;       /* 0x1160 */
    u8 filler1170[0x1190 - 0x1170];
    u16 unk1190;                    /* 0x1190: side being handled */
    u8 filler1192[0x11AC - 0x1192];
    u16 unk11AC;                    /* 0x11AC: party's once-per-turn slot (sub_080F59F8) */
    u16 unk11AE;                    /* 0x11AE: enemies' slot */
};

extern u8 gUnk_0203C200[];
#define BFLOW ((struct BattleFlow *)gUnk_0203C200)

struct SortEntry
{
    u16 id;
    s16 key;
};

/* Battle state at 0x0203D16C, reached through gUnk_03006434. */
struct BattleState
{
    u16 flags;          /* 0x00 */
    u16 unk2;           /* 0x02 */
    u16 unk4;           /* 0x04 */
    s16 unk6;           /* 0x06 */
    u8 filler8[0xC - 0x8];
    struct SortEntry order[15]; /* 0x0C: action order, ended by id 0xFFFF */
};

extern struct BattleState *gUnk_03006434;

/* Battle state at 0x0203D328, reached through gUnk_03006438. */
struct BattleState2
{
    u8 filler0[0x16];
    s16 unk16;          /* 0x16 */
    u8 filler18[0x1A - 0x18];
    s16 unk1A;          /* 0x1A */
    s16 unk1C;          /* 0x1C */
};

extern struct BattleState2 *gUnk_03006438;
#define BSTATE gUnk_03006434

/* elsewhere */
struct Combatant *Party_GetMember(u16 id);
u16 Combatant_GetStatus(s32 who);
s32 Combatant_IsAlive(s32 id);
u32 sub_080C5D0C(void);
s32 Combatant_SetStatus(s32 who, u16 a);
s32 sub_080ED3FC(s32 table, s32 row);
u32 Random_Byte(void);
s32 Combatant_IsDead(s32 id);
s32 Combatant_IsUsed(s32 id);
u8 *Demon_GetRecord(u16 id);
u8 *sub_080BF5C0(u16 id);
u32 sub_080ED694(s32 id);
s32 sub_080ED744(s32 who, s32 skill);
u16 sub_080EDA90(void);
u16 *Battle_GetMessage(s32 id);
u16 *Menu_ExpandListTemplate(u16 *tmpl, s32 arg);
void BattleMenu_SetModeAutoClose(u8 mode, u16 *src);
u32 __umodsi3(u32 a, u32 b);
void CpuFastSet(const void *src, void *dest, u32 control);
void Combatant_DecodeName(struct Combatant *c, u16 *dst);
void Font_DrawGlyph(u16 code, u8 *canvas, u16 x, u16 y);
void Font_DrawGlyphTinted(u16 code, u8 *canvas, u16 x, u16 y, u8 tint);
void SmallFont_DrawGlyphTinted(u16 index, u8 *canvas, u16 x, u16 y, u8 tint);
void SmallFont_DrawAsciiTinted(const u8 *str, u8 *canvas, u16 x, u16 y, u8 tint, u16 advance);
u8 *NumberToDigits(u32 value);
s32 sub_0815B864(u32 id);
void sub_081272AC(void);
u16 *sub_080EA9F8(u8 race);
void VBlankTask_AddCounted(void (*func)(void), u32 count);
u8 *Equipment_GetRecord36_MidRange(u16 id);
u8 *Action_GetRecord(u16 id);
void *memset(void *dst, int c, unsigned long n);
void sub_080C51D4(u32 se);
void Text_DrawSpriteString(const u16 *str, u16 a1, u16 a2, u16 x, u16 y, u16 advance);
void Sprite_Draw(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
void TextWindow_Close(struct Task *window, u32 now);
u32 Moon_GetPhase(void);
void sub_080C30AC(s32 a);
void sub_080C3328(u16 id);
void sub_080C33AC(u16 id);
u32 sub_080C3100(void);
u32 sub_080C3168(void);
u32 Combatant_GetEquip(s32 who, s32 slot);
void Item_GetAttribute(s32 id, s32 field, s32 *out);
s32 sub_080ED3D0(s32 aff, s32 kind);
s32 sub_080ED494(s32 race);
s16 Combatant_GetDemonId(s32 who);
u32 sub_080C0794(void);
void Combatant_AddAlignment(s32 a, s32 d);
void Party_AddAt(u16 who, u16 slot);
void Party_BuildMemberNameTiles(void);
void sub_080C6FD8(void);
void Party_Remove(u16 who, u32 release);
void Combatant_ClearStatus(s32 who, u32 mask);
void *memcpy(void *dst, const void *src, unsigned long n);
u32 sub_080ED6B8(u8 skill);
u32 Combatant_GetStat(s32 who, s32 x);

u8 *sub_080C5D98(void);
u32 Flag_Test(u32 flag);
void sub_080ED35C(s32 *a, s32 *b, u32 g);
struct Task *Task_Create(const void *script, u32 parent);

struct Action             /* one queued battle action */
{
    s32 att;                /* 0x00 */
    s32 def;                /* 0x04 */
    s32 msg;                /* 0x08 */
    s32 unkC;               /* 0x0C: 0 = no effect */
    s32 unk10;              /* 0x10: item effect index */
    u8 filler14[0x18 - 0x14];
    s32 dmg;                /* 0x18 */
    u32 unk1C;
};

void Palette_MarkDirty(void);
s32 sub_080EFBFC(s32 who);
s32 sub_080EFD14(s32 who, s32 d);
s32 sub_080EFD28(s32 who, s32 d);
s32 sub_080EFD3C(s32 who);
s32 sub_080EFD5C(s32 who, s32 d);
s32 sub_080EFD70(s32 who, s32 d);
s32 sub_080EFD84(s32 who);
s32 sub_080EFDA4(s32 who, s32 d);
s32 sub_080EFDB8(s32 who, s32 d);
s32 sub_080EFDCC(s32 who);
s32 sub_080EFDEC(s32 who, s32 d);
s32 sub_080EFE00(s32 who, s32 d);
s32 __divsi3(s32 a, s32 b);
u16 sub_080EFAB0(s32 who);
void sub_080EFAD0(s32 who, s16 mask);
u16 Combatant_GetLuck(s32 who);
u16 Combatant_GetIntelligence(s32 who);
u16 Combatant_GetMagic(s32 who);
s32 Math_DivRound(s32 a, s32 b);
s32 Combatant_IsHpFull(s32 who);
u32 sub_080ED794(s32 kind);
void Combatant_ChangeHpPercent(s32 who, s32 d);
void Combatant_RestoreHp(s32 who);
void sub_080C08E8(s32 who, u32 mask);
void sub_080C366C(void);
void sub_080E760C(void);
s32 sub_080C5240(void);
void sub_080C5224(void);
s32 sub_080C5320(void);
void sub_080C5304(void);
u32 sub_080ED8F4(void);
void sub_080ED90C(u16 v);
s32 Combatant_GetAlignment(s32 who);
s16 Combatant_GetLevel(s32 who);
void Combatant_SetLevel(s32 who, s32 level);
u32 Exp_GetForLevel(s32 level);
void sub_080C0F70(s32 who, u32 exp);
s32 Combatant_GetBaseStat(s32 who, s32 stat);
s32 Combatant_AddBaseStat(s32 who, u32 stat, s32 delta);
void sub_080EDA7C(u32 v);
void Combatant_ChangeHpCapped(s32 who, s32 d);
void Combatant_ChangeMpCapped(s32 who, s32 d);
s32 Combatant_IsMpFull(s32 who);
void Combatant_RestoreMp(s32 who);
void Combatant_UpdateStats(s32 who);
void sub_080C65C8(void);
s32 sub_080EFFF8(s32 who, s32 x);
void Battle_InitEnemyUnit(s32 slot, s32 id);
void sub_080ED938(u32 a);
void sub_080EF8F8(u32 a);
void Task_End(struct Task *task);
void sub_080E8C58(u16 id, u32 a, u32 b);

extern const u16 gUnknown_0876FB44[][2];

extern void (*const gUnknown_0876FA58[])(struct Action *);
extern const s32 gUnknown_0876FB2C[];
void sub_080C35C4(s32 who, s32 state);
void sub_08126834(s32 n);
s32 sub_080ED9F4(void);
u32 sub_080EF224(s32 pos, s32 count);
s32 Battle_AddModifierClamped(s32 row, s32 who, s32 d);
void Moon_Advance(u32 a);
u32 Party_GetRow(s32 who);

extern void (*const gUnknown_0876F940[])(struct Action *);
extern void (*const gUnknown_0876F8C0[])(struct Action *);
extern u16 gPaletteBuffer[];
extern u16 gUnk_0203D600[];
extern const u8 gUnknown_0876F89C[];
extern const u8 gUnknown_0876F87C[4];
extern const u8 gUnknown_0876F880[];
extern s8 gUnk_030050E0[6];
s32 sub_080C3114(s32 a);

extern const u8 gUnknown_08001000[];
extern const u8 gUnknown_08000FF0[];
void sub_081293F8(void);
u32 sub_08129440(void);
void sub_0812D390(void);
u32 sub_0812D5FC(void);
u32 sub_080EDAD0(void);
u32 Battle_IsTwoSided(void);
u32 sub_080EDA24(s32 side);
u32 sub_080C2554(u32 who);
void Window_SetHeight(void *window, u32 h);
void BattleMenu_Reset(void);
struct Task *TextWindow_Create(u32 x, u32 y, u32 w, u32 h, u32 a4);
void sub_080E6DBC(u32 a);
void sub_080ECB38(void);
void sub_080ECF70(u32 sound);
s32 BattleMsg_IsDone(void);
void BattleMsg_SetDone(u8 done);
void BattleMenu_SetMode(u8 mode, u16 *src);

extern u8 gUnk_030000B4[];
extern u8 gUnk_030002B4[];
extern u8 gUnk_030014B4[];
extern const u8 gUnknown_0876F81C[4][8];
extern const u8 gUnknown_0876F83C[3][8];
extern const u8 gUnknown_0876F854[3][8];
extern const u16 gUnknown_0876F86C[8];
extern u8 gWindowTilemapBuffer[];
extern const u8 gUnknown_08771F54[];
extern vu16 gKeysNew;
extern const u16 gUnknown_086BF72C[];
extern u16 gUnknown_08124A50[];
extern u16 gUnknown_08124A62[];
extern u16 gUnknown_081242CE[];

struct Unk03000088
{
    u32 unk0;
    u32 unk4;
};
extern struct Unk03000088 gUnk_03000088;
extern s16 gUnk_0203C174;
extern const u16 gUnknown_0876E938[];

/* this region */
s32 Battle_IsEnemyId(s32 who);
s32 sub_080F40EC(s32 slot);
s32 sub_080F30F8(s32 id);
s32 Battle_PickEnemySupportTarget(s32 skill);
struct Combatant *Battle_GetCombatant(u16 idx);
s32 sub_080F30CC(s32 slot);
s32 sub_080F30E4();
s32 Combatant_IsInParty(s32 who);
void Combatant_ClearSlot(s32 who);
void BattleFlags_Add(u16 mask);
u32 sub_080F3DD8(void);
s32 Battle_GetHp(s32 who);
s32 Battle_GetMaxHp(s32 who);
s32 Battle_GetMp(s32 who);
s32 Battle_GetMaxMp(s32 who);
void Battle_SetMp(s32 who, s32 v);
s32 sub_080F3214(s32 who, u16 a);
void sub_080F51D4(struct Action *a);
s32 Party_FindLowestStatTarget(s32 stat, u16 mask);
s32 sub_080F5938(void);
s32 Combatant_IsAlignmentCompatible(s32 a, s32 b);
void sub_080F3E38(s32 v);
s32 Combatant_GetChosenSkill(s32 who);
void Battle_SetHp(s32 who, s32 v);
void sub_080F4190(s32 who);
u32 BattleFlags_Get(void);
void BattleFlags_Mask();
void sub_080F413C(void);
u8 Combatant_GetSkill(s32 who, s32 i);
void Party_BuildSkillList(s32 who);
s32 Combatant_CountSkillsWithFlags(s32 who, u8 mask);
s16 sub_080F4410(s16 who);
void Battle_StartPaletteFlash(s32 kind, s32 x, s32 y, s32 w, s32 arg);
void Palette_CopyBrightened(u16 *src, u16 *dst, u16 n, u16 dr, u16 dg, u16 db);
void sub_080F40C4(s16 v);
void sub_080F49D4(s32 changed, struct Action *a);
void sub_080F4C90(struct Action *a, u16 mask, s32 msg);
s16 Battle_HealHp(s32 who, s32 d);
s32 sub_080F4D64(struct Action *a, s32 sh);
void sub_080F4DBC(struct Action *a, s32 sh);
void sub_080F4E48(struct Action *a, s32 sh);
void sub_080F5D28(struct Action *a, u16 kind);
void sub_080F60A4(struct Action *a, s32 al);
void sub_080F6178(struct Action *a, u16 bit, s32 msg);
void sub_080F4EE8(struct Action *a, s32 kind);
u16 sub_080F3040(s32 who);
u16 EnemyInfo_IsWindowDone(u8 which);
void EnemyInfo_DrawPage(u8 mode);
void EnemyInfo_UploadGfx(void);
void EnemyInfo_ClearGfx(void);
void EnemyInfo_DrawSkillNames(u8 *skills, u16 first, u16 n);
u16 EnemyInfo_HandleInput(void);
void EnemyInfo_Close(void);

#endif /* GUARD_BATTLE2_H */
