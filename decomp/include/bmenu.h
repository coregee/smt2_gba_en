#ifndef GUARD_BMENU_H
#define GUARD_BMENU_H

/* Code 0x081272CC-0x0812BF54: battle menu drawing and command menus. Declarations copied
   from other headers where needed (those headers are not included here). */

#include "menucur.h"

struct Task
{
    u16 state;
    u16 id;
    u16 parent;
    u8 unk06;
    u8 pad07;
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

/* One party member / stock demon / enemy: 0x80 bytes (copied from c0bf.h). */
struct Combatant
{
    u8 name[12];
    u8 race;            /* 0x0C: < 4 = human */
    u8 level;           /* 0x0D */
    u16 unkE;           /* 0x0E: 0xC000 in party, 0x8000 stocked, 0 free */
    u16 flags;          /* 0x10 */
    s16 demonId;        /* 0x12 */
    u16 unk14;
    u16 unk16;
    s16 hp;             /* 0x18 */
    s16 maxHp;          /* 0x1A */
    s16 mp;             /* 0x1C */
    s16 maxMp;          /* 0x1E */
    s8 equip[7];        /* 0x20 */
    u8 pad27;
    u8 base[6];         /* 0x28: base stats */
    u8 pad2E[2];
    u8 bonus[6];        /* 0x30 */
    u8 pad36[2];
    u8 extra[6];        /* 0x38 */
    u8 pad3E[2];
    u8 total[6];        /* 0x40 */
    u8 pad46[2];
    s16 unk48;
    s16 unk4A;
    s16 unk4C;
    s16 unk4E;
    s16 unk50;
    s16 unk52;
    s16 unk54;
    s16 unk56;
    u16 unk58;
    u8 pad5A[0x80 - 0x5A];
};

struct C127SortEntry
{
    u16 id;
    s16 key;
};

/* Demon record (Demon_GetRecord): only the fields used here. */
struct C127DemonRecord
{
    u8 pad00[0x22];
    u16 name[8];        /* 0x22 */
};

/* The battle EWRAM block at 0x0203C200 (gUnk_0203C200). Only fields used here. */
struct C127Block
{
    u8 pad000[0x40];
    struct Task *unk40;     /* 0x40: menu task */
    struct Task *unk44;     /* 0x44: submenu task */
    struct Task *unk48;     /* 0x48 */
    u32 unk4C;              /* 0x4C: text window (a task) */
    u32 unk50;
    u8 pad054[0x2D0 - 0x54];
    u16 list[0x110];    /* 0x2D0: menu entry list, 0xFFFF-terminated */
    u8 pad4F0[0x691 - 0x4F0];
    u8 unk691;          /* 0x691: index into gGameState.order */
    u8 unk692;          /* 0x692: selected member slot */
    u8 pad693;
    u8 unk694;
    u8 pad695;
    u8 unk696;
    u8 unk697;
    u8 pad698[0x7E0 - 0x698];
    u8 unk7E0;          /* 0x7E0: gBattleMsg.mode (4 = window open) */
    u8 pad7E1[0x974 - 0x7E1];
    u32 unk974;         /* 0x974: window */
    u8 pad978[0xEF0 - 0x978];
    s16 unkEF0[16];     /* 0xEF0 */
    s16 unkF10[16];     /* 0xF10 */
    u16 unkF30[0x1B];   /* 0xF30 */
    s16 unkF66;         /* 0xF66 */
    u8 padF68[0x110C - 0xF68];
    struct C127Sub110C
    {
        u32 unk0;
        u32 yesno;      /* 0x1110: yes/no window task */
    } unk110C;
    u8 pad1114[0x118E - 0x1114];
    u16 unk118E;        /* 0x118E */
};
#define C127_BLOCK ((struct C127Block *)gUnk_0203C200)

struct C127GameState
{
    struct Combatant members[20];
    u8 names[4][8];     /* 0xA00 */
    s8 order[6];        /* 0xA20: active party, member index or -1 */
    u8 padA26[0xAC0 - 0xA26];
    u16 unkAC0;
};
extern struct C127GameState gGameState;

/* gFieldState (0x03004550): only the fields used here. */
struct C127FieldState
{
    u16 state;
    u8 pad02[0x1E - 2];
    u16 unk1E;
};
extern struct C127FieldState gFieldState;

void Font_DrawGlyphTinted(u16 code, u8 *canvas, u16 x, u16 y, u8 tint);
void DigitFont_DrawGlyphTinted(u16 index, u8 *canvas, u16 x, u16 y, u8 tint);
u8 *NumberToDigits(u32 value);
struct MenuCursor *sub_08126D1C(u8 id);
struct Combatant *Party_GetMember(u16 id);
s32 Combatant_IsDead(s32 id);
bool32 Combatant_IsInParty(u16 idx);
void Combatant_DecodeName(struct Combatant *c, u16 *dst);
u8 *Demon_GetRecord(u16 id);
u8 *sub_080BF5C0(u16 id);
u8 *Action_GetRecord(u16 id);
u8 *Item_GetRecord(u16 id);
u8 *Equipment_GetRecord36_MidRange(u16 id);
s32 sub_080C29B0(s16 id);
s32 __divsi3(s32 a, s32 b);
struct Task *Task_Create(const void *script, u32 parent);
void BattleMenu_Reset(void);
void sub_080C7218(void);
void sub_080C7648(void);
void sub_080C7C60(void);
void sub_080C700C(void);
void sub_080C7430(void);
void sub_080C7234(void);
void sub_080C762C(void);
void sub_080C7C94(void);
void sub_080C6FF0(void);
void sub_080C7414(void);
void sub_080C7E24(void *dst, const void *src);
u16 *Battle_GetMessage(u16 id);
u16 *Menu_ExpandListTemplate(const u16 *tmpl, u32 arg);
void BattleMenu_SetMode(u8 mode, const u16 *src);
void BattleMsg_Close(void);
void sub_080EA210(void);
void sub_080EA2AC(void);
void sub_080ECF70(u32 sound);
void sub_080C51D4(u32 se);
void Sprite_Draw(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
void Sprite_DrawSingle(const void *tmpl, s32 layer, s32 palette, s32 priority, s32 tile, s32 x, s32 y);
void Field_SetState(u16 state);
u32 Flag_Test(u32 flag);
u32 TextWindow_Create(u32 x, u32 y, u32 w, u32 h, u32 a4);
void TextWindow_Close(u32 window, u32 now);
s32 sub_080F3190(void);
u8 sub_08126928(u8 id, u8 type, u16 columns, u16 rows, u16 perColumn);
void sub_08126E4C(u8 unused, u8 parts);
void sub_08126F4C(void);
void sub_080CE258(u32 a, u32 b);
s32 Party_CountMembers(void);
void sub_080AD6E4(u32 a);
s32 sub_080F4504(void);
s32 Party_CountDemons(void);
u32 sub_080C3100(void);
s32 Alignment_AreCompatible(s32 a, s32 b);
u32 sub_080C5CC0(void);
void sub_080D3688(void);
void sub_080D3654(u32 a, u32 b);
u32 sub_080C8AAC(u32 a, u32 b);
void sub_080C8ADC(u32 w, u32 b);
u16 sub_080C8AF4(u32 w);
s32 BattleMsg_IsDone(void);
void sub_081272AC(void);
void Party_Remove(u16 a, u32 b);
void sub_080C30AC(s32 v);
void Party_AddAt(u32 a, u32 b);
void sub_080C366C(void);
void Party_BuildMemberNameTiles(void);
void sub_080C6FD8(void);
struct Combatant *Battle_GetCombatant(u16 idx);
u16 *sub_080EAF1C(struct Combatant *c, u16 a);
u16 *Battle_BuildNamePrependText(u16 who, const u16 *tmpl);
s32 sub_0815B8F8(u16 id, u32 a);
void sub_080F41B0(u16 id);
u32 YesNo_Create(u32 a);
bool32 Task_IsFree(u32 task);
void Window_Close(void *window, u32 arg1);
void BattleMsg_SetDone(u8 done);
void FontSprite_DrawGlyph(u16 glyph, u32 a1, u32 a2, u16 x, u16 y);
s32 Combatant_IsAlive(s32 id);
u16 *sub_080C9210(u8 a);
s32 sub_080C2554(u16 id);
void sub_080B1BC4(void);
void sub_080CB01C(u32 a, u16 b);
void Battle_SortEntriesInsertion(u16 lo, u16 hi, void *a);
void sub_080F3E54(u16 item, s32 a);
void Item_GetAttribute(s32 id, s32 field, s32 *out);
void sub_0812E780(s16 a, void *b, const u16 *c, u32 d);
u16 sub_080F1678(u32 a, u32 b);
void sub_0812EA98(s16 a);
s16 Party_FirstActiveHuman(void);
bool8 sub_080C32D4(u16 item);
u16 sub_080F3040(s32 who);
s32 sub_080C35E4(s32 who);
s32 Combatant_GetChosenSkill(s32 who);
u32 sub_080AB890(u32 a, u32 b, u32 c, u32 d, u32 e);
void Task_End(struct Task *task);
s16 sub_080E6E08(void);
u16 sub_080EDA64(u16 who);
void sub_0812EE8C(u32 a, struct Task *task);
s32 FieldMap_HasRecordRel(u32 a, u32 b, u32 c);
void sub_080B0888(void);
void *PalFade_FadeRangeToBlackWithDuration(u16 start, u16 count, u16 delay, u16 duration);
void sub_080C33AC(u16 id);
void Flag_Set(u32 flag);
void sub_080E471C(u16 a, u32 b, u32 c, u32 d);
void sub_0812EF8C(void);
u32 sub_0812EEC4(void);
void Text_DrawSpriteString(const u16 *str, u16 a1, u16 a2, u16 x, u16 y, u16 advance);

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
extern u16 gUnk_0200E7D4[];
extern const u8 gUnknown_08772294[];
extern const u16 gUnknown_08777D44[];
extern const u8 gUnknown_08777D54[18][8];    /* status names, 8 bytes each */
extern const u16 *const gUnknown_08777DE4[];
extern const u32 gUnknown_08777EB8[];
extern const u8 gUnknown_08000868[];
extern const u8 gUnknown_08000E58[];
extern const u16 gUnknown_08777E94[];
extern const u16 *const gUnknown_08777EA0[];
extern const u8 gUnknown_08777F2C[];
extern const u8 gUnknown_08777F60[][16];
extern const u8 gUnknown_08777F68[][16];
extern const u16 *const gUnknown_08777FE0[];
extern const u32 gUnknown_08778000[];
extern const u32 gUnknown_0877812C[];
extern const u32 gUnknown_08778160[];
extern u16 gShopItemIds;
extern u16 gUnk_030065C0[];
extern u32 gYesNoResult;
extern const u16 gUnknown_08124BF4[];
extern const u16 gUnknown_08124C38[];
extern const u16 gUnknown_08124CE6[];
extern const u32 gUnknown_087795D8[];
extern u32 gUnk_0200AB04;
extern u32 gUnk_03004614;
extern u32 gUnk_03003BB8;
extern const u8 gUnknown_08000F8C[];
extern const u16 gUnknown_08124D72[];
extern const u32 gUnknown_08779418[];
extern u16 gUnk_03006440;
extern u16 gUnk_03006478;
extern s8 gUnk_030050E0[];
extern const u16 gUnknown_08124D5E[];
extern const u32 gUnknown_087790C4[];
extern const u16 gUnknown_08124BD2[];
extern const u16 gUnknown_08124CC8[];
extern struct MenuCursor gSavedMenuCursor;   /* saved copy of cursor 2 */
extern u16 gInventory[];
extern const u16 *const gUnknown_08778ACC[];
extern const u8 gUnknown_08000EE4[];
extern const u8 gUnknown_08778AC4[];
extern const u16 gUnknown_08123DF0[];
extern const u32 gUnknown_08778E04[];
extern const u8 gUnknown_08778DD0[];
extern const u16 *const gUnknown_08778DF4[];
extern const u16 gUnknown_08124C20[];
extern const u16 gUnknown_081244BA[];
extern const u16 gUnknown_081244C4[];
extern const u32 gUnknown_087787F8[];
extern const u32 gUnknown_08778ADC[];
extern const u32 gUnknown_08778CB4[];
extern const u16 gUnknown_08124A62[];
extern const u8 gUnknown_08778A9C[];
extern const u16 gUnknown_0812437C[];
extern const u16 gUnknown_081243C6[];
extern const u16 gUnknown_081243B0[];
extern const u16 gUnknown_0800354A[];
extern const u16 gUnknown_08003556[];
extern const u16 gUnknown_08003568[];
extern const u32 gUnknown_087784CC[];
extern const u32 gUnknown_08778614[];
extern const u16 gUnknown_0812416C[];
extern const u16 gUnknown_08124154[];
extern const u16 gUnknown_08124182[];
extern const u16 gUnknown_0812439A[];
extern const u16 gUnknown_08124364[];
extern const u16 gUnknown_0812410A[];
extern const u16 gUnknown_081240F0[];
extern const u16 gUnknown_081240A0[];
extern const u16 gUnknown_081240BC[];
extern const u8 gUnknown_08000EA4[];
extern const u8 gUnknown_08000FF0[];
extern const u8 gUnknown_08001000[];

/* this region */
void sub_081272CC(u16 *str, u8 row);
void sub_08127394(u16 *str, u8 row, u8 tint);
void sub_0812745C(u16 value, u8 row);
void sub_0812756C(u16 value, u8 row, u8 tint);
void sub_08127678(u16 value, u8 row);
void sub_081277AC(u16 value, u8 row);
void MenuCursor_SetIndex(u8 id, u16 index);
void sub_081279D4(void);
void sub_08127A38(struct Task *task);
u16 BattleMenu_BuildMemberList(u8 mode);
void sub_08127D70(void);
void sub_08127E04(void);
bool32 sub_08127E98(u16 id);
void BattleMenu_DrawListPage(u8 mode, u16 start);
void sub_0812834C(void);
void sub_08128388(void);
u32 sub_0812839C(u16 id);
void sub_081283C4(u8 mode, u16 index);
void BattleMenu_DrawHp(u16 cur, u16 max);
void BattleMenu_DrawMp(u16 cur, u16 max);
void sub_0812876C(u16 value, u8 tint);
void BattleMenu_DrawStatus(u16 flags, u16 race);
void Menu_DrawLabeledName();
void sub_08128AAC(u16 value);
void sub_08128B84(u8 mode);
void sub_08128C28(struct Task *task);
void sub_08128D54(void);
void sub_08128DE0(struct Task *task);
void sub_08128E28(void);
void sub_08128E80(void);
void sub_08128EB4(void);
void sub_08128F28(void);
void sub_08128F60(void);
void sub_08129030(struct Task *task, u32 mode);
void sub_08129068(struct Task *task);
void sub_08129214(struct Task *task, u32 value);
void sub_0812922C(void);
void sub_08129298(void);
void sub_081292EC(void);
void sub_0812931C(void);
void sub_0812935C(struct Task *task);
void sub_081293F8(u8 mode);
u8 sub_08129440(void);
bool32 sub_08129460(void);
void sub_081294B0(struct Task *task, u32 arg);
void sub_081295D4(void);
void sub_081295F4(void);
void sub_08129604(struct Task *task, u32 arg);
void sub_08129838(struct Task *task);
void sub_08129850(void);
void sub_08129880(void);
void sub_081298AC(void);
void sub_081298DC(struct Task *task);
void sub_08129994(struct Task *task);
void sub_081299C8(struct Task *task, u32 arg);
void sub_08129B34(struct Task *task, const u16 *msg);
void sub_08129B40(struct Task *task, const u16 *tmpl);
void sub_08129B58(struct Task *task, u16 id);
void sub_08129B74(struct Task *task, u32 arg);
void sub_08129C00(void);
void sub_08129C20(struct Task *task);
void sub_08129D08(struct Task *task);
void sub_08129D58(void);
void sub_08129D78(struct Task *task);
void sub_08129DF4(void);
void sub_08129E14(struct Task *task);
void sub_08129EE4(struct Task *task);
void sub_08129EFC(void);
void sub_08129F10(void);
void sub_08129F3C(struct Task *task);
void sub_08129F5C(struct Task *task);
void sub_08129FDC(void);
void sub_08129FFC(struct Task *task, u32 arg);
void sub_0812A09C(void);
void sub_0812A0BC(struct Task *task, u32 arg);
void sub_0812A1C8(struct Task *task);
void sub_0812A228(struct Task *task);
void sub_0812A248(struct Task *task);
void sub_0812A274(void);
void sub_0812A288(void);
void sub_0812A298(struct Task *task);
void sub_0812A2EC(struct Task *task);
void sub_0812A338(struct Task *task);
void sub_0812A39C(struct Task *task);
void sub_0812A50C(struct Task *task);
void sub_0812A53C(void);
void sub_0812A55C(struct Task *task);
void sub_0812A588(void);
void sub_0812A594(void);
void sub_0812A5A0(void);
void sub_0812A5B8(struct Task *task, u32 value);
void sub_0812A5C4(struct Task *task);
void sub_0812A61C(struct Task *task, u32 arg);
struct Task *sub_0812A640(void);
u16 sub_0812A668(u8 kind);
void sub_0812A6F0(void);
void sub_0812A710(void);
u32 sub_0812A730(void);
u32 sub_0812A7C4(void);
void sub_0812A7E4(struct Task *task);
void sub_0812A86C(struct Task *task, u32 arg);
void sub_0812A9EC(void);
void sub_0812AA54(void);
void sub_0812AAB0(struct Task *task, u32 arg);
void sub_0812AB44(void);
void sub_0812AB64(struct Task *task);
void MenuCursor2_SaveRestore(u16 mode);
void sub_0812ACB8(struct Task *task);
u16 sub_0812ACCC(u16 i);
void Inventory_Sort(void);
void sub_0812AD70(void);
void sub_0812AD90(void);
void sub_0812ADE4(struct Task *task);
void sub_0812AF34(void);
void sub_0812AF48(struct Task *task);
void sub_0812AF94(void);
void sub_0812AFA8(void);
void sub_0812AFB8(struct Task *task, u16 value);
void sub_0812AFC8(struct Task *task);
void sub_0812B028(struct Task *task);
void sub_0812B138(struct Task *task);
void sub_0812B194(u8 mode, u16 value);
u32 sub_0812B1D4(void);
u16 sub_0812B1E0(s32 who, u8 n);
u16 sub_0812B260(u8 mode);
u16 sub_0812B320(u16 limit);
u32 sub_0812B37C(void);
u16 sub_0812B3A4(u8 mode);
void MenuCursor4_SaveRestore(u16 mode);
void sub_0812B490(struct Task *task);
void sub_0812B57C(void);
void sub_0812B598(void);
void sub_0812B5D8(struct Task *task);
void sub_0812B6F4(void);
void sub_0812B740(struct Task *task);
void sub_0812B784(struct Task *task);
void sub_0812B794(struct Task *task);
void sub_0812B878(void);
void sub_0812B898(struct Task *task);
void sub_0812B978(void);
void sub_0812B9AC(struct Task *task);
void sub_0812BA0C(struct Task *task);
void sub_0812BA1C(struct Task *task);
void sub_0812BA38(struct Task *task, u32 mode);
void sub_0812BB04(void);
void sub_0812BB10(void);
void sub_0812BB40(struct Task *task, const u16 *tmpl);
void sub_0812BB58(struct Task *task, const u16 *tmpl);
void sub_0812BB70(struct Task *task);
void sub_0812BB94(struct Task *task);
void sub_0812BBE4(struct Task *task);
u16 *Inventory_Find(u16 id);
void sub_0812BCF4(struct Task *task);
void sub_0812BD1C(struct Task *task);
void sub_0812BD9C(struct Task *task);
void sub_0812BE84(void);
void sub_0812BEB8(struct Task *task);

/* called from this region, defined in later code */
void sub_08126F84(void);
void sub_08126FEC(void);
void sub_08127054(void);
void sub_0812C0D0(void);
void sub_0812CC70(u32 a);
void sub_0812CE78(void);
void sub_0812E734(void);

#endif /* GUARD_BMENU_H */
