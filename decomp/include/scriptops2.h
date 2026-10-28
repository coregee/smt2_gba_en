#ifndef GUARD_SCRIPTOPS2_H
#define GUARD_SCRIPTOPS2_H

#include "global.h"

/* Script VM opcode handlers 0x38A-0x437 (0x08136D58-0x0813A58F). Declarations are copied
   from script.h / other headers so this header can be used alone. */

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

extern u16 *gScriptBase;
extern u16 gScriptPc;
extern u16 *gScriptJumpTarget;
extern u16 gScriptWaitState;
extern u16 gScriptYield;
extern u16 gTextColumn;
extern u16 gTextLine;
extern u16 gMsgGlyphCount;
extern s16 gMsgWindowOpen;
extern u32 gMsgWindow;
extern u16 gScriptItemCheckId;

extern u32 gUnk_03006964;
extern u16 gUnk_0203DB58;
extern u16 gUnk_0203DB4A;
extern u32 gUnk_030068E0;
extern u32 gUnk_030068F0[];
extern u16 *gUnk_0203DAC8[];
extern u16 *gUnk_0203DACC;
extern u16 gUnk_0203DB88[];
extern u16 gUnk_03006914;
extern s16 gUnk_03006604;
extern const s16 gUnknown_0878EEDC[][10];
extern const u8 gUnknown_0878FC80[];
extern u16 gUnk_03006940;
extern s16 gUnk_0300696C;
extern s16 gUnk_03006844;
extern u16 gUnk_03006698;
extern u16 *gUnk_03006674;
extern u16 gUnk_030069E0;
extern s16 gUnk_03006600;
extern u16 gUnknown_0803BAD6[];
extern s32 gUnk_0203DB2C;
extern s16 gUnk_0300699C;
extern const u16 gUnknown_0879041E[];

u32 sub_080B4420(u16, u16);
void sub_080ECF80(void);
bool8 Inventory_GetCount(u16 item);
u16 Party_CountEquipped(s16 a, u16 item);
void Window_Close(u32 window, u32 now);
void Font_ResetGlyphSpriteCache(u32 arg);
u32 SaveScreen_Open(u16 mode, u16 arg1);
void sub_080C4580(u32);
void MsgWindow_SaveGlyphs(void);
void sub_0812F2B4(u32);
struct Task *Task_Create(const void *script, u32 parent);
void Money_Add(s32 v);
u32 sub_080B8020(void);

struct C136FieldState
{
    u16 state;
    u16 facing;
};
extern struct C136FieldState gFieldState;
extern u16 gUnk_0203DB72;
extern u32 gUnk_0203DB34;
extern u16 gUnk_0203DAD0[];
extern s16 gUnk_0300668C;
extern u16 gUnk_030069A8;
extern s16 gUnk_03006898;
extern u16 gUnk_0203DB7C;
extern u8 gUnk_0300685C;
extern u16 gUnknown_08032D7C[];

u32 Flag_Test(u32 flag);
void Flag_Set(u32 flag);
void sub_0812DC24(void);
u32 sub_080C0794(s32 who);
void Combatant_AddAlignment(s32 who, s32 d);
u32 sub_080D2268(u16 id);
u32 Combatant_GetEquip(s32 who, s32 slot);
void Item_GetAttribute(s32 id, s32 field, s32 *out);
void Inventory_RemoveItem(u16 id);
void Inventory_AddItem(u16 id);
u32 Moon_GetPhase(void);
u16 Demon_GetField(u16, u16);
u32 sub_0815B958(u16);
u32 sub_0815B970(u16);
void sub_0815BAC8(u16, u32);
u32 Random_Byte(void);
s16 Combatant_GetLevel(s32 who);
u32 Combatant_GetStat(s32 who, s32 x);
u16 Combatant_GetLuck(s32 who);
u16 Combatant_GetStrength(s32 who);
s32 sub_080EF90C(void);
s32 sub_080EF954(void);

struct C136Combatant
{
    u8 pad00[8];
    u32 unk08;          /* 0x08 (Battle_GetCombatant(0x8000): macca, capped at 1,676,500) */
    u8 pad0C[4];
    u16 flags;          /* 0x10 */
    u8 pad12[6];
    s16 hp;             /* 0x18 */
    s16 maxHp;          /* 0x1A */
    s16 mp;             /* 0x1C */
    s16 maxMp;          /* 0x1E */
};
struct C136Combatant *Battle_GetCombatant(u16 idx);
s32 Combatant_IsUsed(s32 id);
u16 Combatant_GetStatus(s32 who);
s32 Stock_GetCapacity(void);
u32 sub_0813BDCC(void);
void Script_JumpToStatusMessage(u32);
s32 sub_0813B268(void);
void Magnetite_Add(s32 a);
u32 Inventory_IsMaxed(u16 a);
void sub_0815B9B8(u16, u8 *, u8 *);
extern const u8 gUnknown_08790458[];

extern u32 gUnk_03006840;
extern u8 gUnk_030068B4;
extern u8 gUnk_030069E8;
extern u16 *gUnk_030068C4;
extern u16 gUnk_03006818;
extern s16 gUnk_0203DB64;
extern const u16 gUnknown_087904F2[];
extern u16 gUnknown_0803473C[], gUnknown_08033560[], gUnknown_08032DE0[], gUnknown_080341EC[];
extern u16 gUnknown_08034094[], gUnknown_0803526C[], gUnknown_080340B8[], gUnknown_08034138[];
extern u16 gUnknown_080367F2[], gUnknown_080366C2[], gUnknown_080367E2[], gUnknown_08037322[];
void sub_080EFA20(s16 d);
void sub_080EFA44(s16 d);

void Negotiate_PickReaction(void);
void sub_081380CC(u16 reaction);

void Negotiate_CallReply(u16 n);
void sub_0813848C(u16 n);
void sub_0813821C(u16 v);
u16 sub_08138338(void);
u16 sub_081376AC(u16 n);
u16 sub_08137720(u16 mode);
u16 sub_081379CC(u16 mode);
s32 Combatant_IsAlive(s32 id);
s16 Combatant_GetDemonId(s32 who);
u16 sub_0813C4FC(u16);
u16 sub_0813AC98(void);
u16 sub_0813BF78(void);
u16 sub_0813BF58(void);

extern u16 gUnk_03006670;
extern u16 gUnk_0203DB70;
extern u16 gUnk_0203DB46;
extern struct Task *gUnk_030069E4;
extern u16 gUnk_0203DB86;
extern u16 gUnk_0203DB28[];
extern u16 gUnk_03006970[];
extern u16 gUnk_0203DB66;
extern u16 gUnk_0203DB68;
void sub_080EFA88(u16);
s32 Battle_IsPartyDefeated(void);
s32 sub_080ED9F4(void);
void sub_0813EB6C(u16);
void Task_End(struct Task *task);

extern u16 gUnk_0203DB84;
extern const u8 gUnknown_0878FF48[];
void Keypad_OpenNumberEntry(u32 bet);
struct Task *sub_080BE6E0(u16 id);
s32 Stock_AddDemon(u16 demonId);
void Party_Remove(u16 who, u32 release);
void Party_FixFormation(void);
void CasinoPrize_DrawList(u16);
u16 CasinoPrize_GetSet(void);

void SceneEffect_Start(u16 set, u16 id);
void SceneEffect_End(u16 set, u16 id);

extern u16 gUnk_03006848;
extern u16 gUnk_03006680;
extern u16 gScriptSubstBuf[16];
extern u16 gMsgGlyphQueue[];
extern const u16 gScriptDigitGlyphs[];
extern const u16 gUnknown_0878FEA8[][16];
extern const u16 gUnknown_08790390[];
u8 *Action_GetRecord(u16 id);
u8 *Equipment_GetRecord36_MidRange(u16 id);
u8 *Item_GetRecord(u16 id);
void MsgWindow_RestoreGlyphs(void);
void MsgGlyphQueue_PushSubstClamped(u16 x, u16 y, u16 pal, u16 n);
s32 KeyItem_IsObtainable(u16);

/* Appends one entry to the 64-entry glyph queue gMsgGlyphQueue (count clamped to 63). */
#define QUEUE_GLYPH(glyph, x, y)                {                                                   u16 c_ = gMsgGlyphCount;                        u16 k_ = c_ * 4;                                gMsgGlyphQueue[k_++] = (glyph);                 gMsgGlyphQueue[k_++] = (x);                     gMsgGlyphQueue[k_++] = (y);                     gMsgGlyphQueue[k_] = 0;                         gMsgGlyphCount = c_ + 1;                        if (gMsgGlyphCount > 0x3F)                          gMsgGlyphCount = 0x3F;                  }

extern u16 gUnk_0203DB5C;
extern u32 gUnk_03006954;
extern u16 gUnk_03006990[];
extern u16 gUnk_030069CC;
void sub_080C700C(void);
u32 sub_080D3740(void);
void sub_080C7648(void);
void sub_080C6FF0(void);
void sub_080D3758(u32);
void sub_080C762C(void);
s32 Combatant_AddBaseStat(s32 who, u32 stat, s32 delta);
void Combatant_RecalcStats(s32 who);
void Combatant_RestoreHp(s32 who);
void Combatant_RestoreMp(s32 who);
void sub_080CDC34(void);

extern u16 gShopItemIds[];
extern u32 gUnk_0203DB30;
extern const u16 gUnknown_08790AE6[];
extern const u8 gUnknown_0879050A[][150];
extern const u8 gUnknown_087907F8[][150];
extern const u8 gUnknown_08790B26[];

extern u16 gMsgGlyphDelay;
struct C136GameState
{
    u8 pad0[0x18B4];
    u8 moonPhase;       /* 0x18B4 */
    u8 unk18B5;
    u8 unk18B6;
};
extern struct C136GameState gGameState;
s32 Combatant_GetMaxHp(u16 who);
s32 Combatant_ChangeHp(s32 who, s32 delta);

extern u16 gUnk_030065F0;
extern u16 gUnk_030065E0;
extern u16 gUnk_030068D8;
extern u32 gUnk_030037F0;
extern const u16 gUnknown_08790CC8[];
extern const u16 gUnknown_0878FDB4[];
extern const u16 gUnknown_0878FDCC[];
u32 Warp_ToWorldPosition(u16 mode, u16 x, u16 y, u16 dir, u16 flag);
void Party_RestoreHumans(void);
void Party_SnapshotHumans(void);
u32 Money_Get(void);
void sub_080C31B4(u32);
void sub_080D53FC(void);

extern const u16 gUnknown_08035BB8[];
extern const u8 gUnknown_08790C8A[];
extern const u16 gUnknown_08790C9A[];
extern u32 gUnk_030068B0;
u32 CharObj_Create(u16, u16, u16, u16, u32, u32);
u32 BgPicture_StartTask(u16);

extern const u16 gUnknown_08790C1C[];
u16 sub_080C2A84(u32 who);
void sub_080D3A80(void);
s32 sub_080D3AA0(u32);
void sub_080D3CAC(void);
void sub_080D3DF0(void);
u32 YesNo_Create(u32 a);
s32 Stock_HasRoom(void);
u32 sub_080C5C7C(void);
u16 sub_081397D8(void);
u16 sub_081398C8(void);
void sub_0813999C(u16 k);

#define SCRIPT_READ() (gScriptBase[gScriptPc++])

#endif /* GUARD_SCRIPTOPS2_H */
