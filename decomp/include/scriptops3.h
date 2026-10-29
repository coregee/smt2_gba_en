#ifndef GUARD_SCRIPTOPS3_H
#define GUARD_SCRIPTOPS3_H

#include "global.h"

/* Script VM opcode handlers 0x33B-0x389 (0x08134250-0x08136D57) and 0x438-0x44C
   (0x0813A590-0x0813D117). Declarations are copied from other headers so this header can
   be used alone. */

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

#define SCRIPT_READ() (gScriptBase[gScriptPc++])

/* script VM state */
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
extern u16 gScriptSubstBuf[16];
extern u16 gUnk_0203DB4A;
extern u16 *gUnk_0203DAC8[];
extern u16 *gUnk_0203DACC;
extern u16 *gUnk_0203DAD0;
extern u16 *gUnk_0203DAD4;
extern u16 gUnk_0203DAD8;
extern u32 gUnk_0203DB2C;

/* message window glyph lists */
extern s16 gMsgGlyphList2Count;
extern u16 gMsgGlyphList2[];
extern u16 gMsgGlyphQueue[];
extern u16 gUnk_0300699C;
extern u16 gUnk_03006848;
extern u16 gUnk_03006680;
extern u16 gUnk_03006820[];

/* shop */
extern u16 gShopItemIds[];
extern u32 gShopItemPrices[];
extern s16 gUnk_03006688;
extern u16 gUnk_03006914;
extern s16 gUnk_03006940;
extern s16 gUnk_0300696C;
extern u16 gUnk_030065E4;
extern u32 gUnk_030068A4;
extern s16 gUnk_03006898;
extern s16 gUnk_030069A8;
extern s16 gUnk_030065FC;
extern u32 gUnk_03006694;

struct ShopRow          /* gUnk_03006620, 16 bytes each */
{
    u16 unk0;
    u16 pad2;
    u32 price;
    u16 unk8;
    u16 y;
    u16 palette;
    u16 padE;
};
extern struct ShopRow gUnk_03006620[];
extern u32 gUnk_03006624[];

extern const u16 gUnknown_0879038A[];
extern const u16 gUnknown_0878FC64[];
extern const s16 gUnknown_0878EFB8[][0x20];
extern const u32 gUnknown_0878FD58[];
extern const u32 gUnknown_0878FF8C[];

void sub_08133724(u16 x, u16 y, u16 pal, u16 n);
void Shop_InitItemList(u16 first, u16 mode);
u8 *Action_GetRecord(u16 id);
u32 sub_080C4C60(u16 item);
u32 sub_080C4C7C(u16 item);
u32 sub_080D3400(u32 a, u32 b, u16 c);
struct Task *Task_Create(const void *script, u32 parent);
s32 Equip_CanEquip(s16 a, u8 item);
void Inventory_AddItem(u16 item);
void sub_080CDFBC(u16 a, u16 item);

extern u16 gUnk_030065E0;
extern s16 gUnk_03006844;
extern s16 gUnk_03006604;
extern u16 gUnk_0203DB88[];
extern const u32 gUnknown_0878FC80[];
extern u16 gUnk_0203DB28[];
extern s16 gUnk_0203DB5C;

void MsgWindow_SaveGlyphs(void);
void MsgWindow_DrawItemList(u32);
void Music_Play(u16 se);
void Sound_Play(u32 se);
void Combatant_AddAlignment(s32 who, s32 d);
s32 Combatant_GetAlignment(s32 who);
u32 sub_080C0794(s32 who);
s16 Combatant_GetLevel(s32 who);
s32 Stock_GetCapacity(void);
s32 Combatant_IsUsed(s32 who);
s16 Combatant_GetDemonId(s32 who);
s32 Combatant_IsDead(s32 who);
s32 Combatant_IsInParty(s32 who);
void Combatant_ChangeHpPercent(s32 who, s32 d);
void sub_080C84A0(void);
u8 *Battle_GetCombatant(u16 idx);
s32 Combatant_IsAlive(s32 who);
void sub_080C08E8(s32 who, u32 mask);
u16 Combatant_GetStatus(s32 who);
s32 Combatant_ChangeHp(s32 who, s32 delta);
u32 Fusion_StartScreen(u32 a);
void Window_Close(u32 win, u32 erase);
void Font_ResetGlyphSpriteCache(u32 baseTile);
extern u16 gUnk_030068A8;
extern u32 gUnk_030068E0;
extern const u16 gUnknown_08790398[];
s16 Combatant_GetHp(u16 who);

struct PartyMember      /* gGameState: 0x80 bytes each */
{
    u8 filler0[0xE];
    u16 unkE;           /* non-zero = slot used */
    u16 flags;          /* 0x10: 0xA000 = cannot act */
    u8 filler12[6];
    s16 hp;             /* 0x18 */
    s16 maxHp;          /* 0x1A */
    s16 mp;             /* 0x1C */
    s16 maxMp;          /* 0x1E */
    u8 filler20[0x60];
};
extern struct PartyMember gGameState[];
extern u16 gUnk_0203DB72;
extern const u16 gUnknown_087903B8[];
extern const u16 gUnknown_087903BE[];
extern const u16 gUnknown_087903C4[];
void Combatant_ClearStatus(s32 who, u16 mask);
void Combatant_RestoreHp(s32 who);
void Combatant_RestoreMp(s32 who);
u16 *sub_0812DBF0(void);
s16 Combatant_GetMaxHp(u16 who);
s16 Combatant_GetMp(u16 who);
s16 Combatant_GetMaxMp(u16 who);
u32 Healer_HpMpCost(u16 who);
u32 Healer_StatusCost(u16 bits, u16 who);
u32 sub_081352F8(u16 who);
u32 sub_08135320(u16 who);
u32 sub_08135348(u16 who);
void sub_081360D4(s32 who);
u32 *BattleMenu_GetPriceList(void);
u32 Healer_TotalCost(u16 who);
extern u16 gUnk_0300668C;
extern u16 gUnk_0203DB74;
extern u32 gUnk_03006954;
extern u32 gUnk_03006964;
extern u32 gUnk_0200AB04;
void sub_0812DC24(void);
u32 Warp_ToWorldPosition(u16 mode, u16 x, u16 y, u16 dir, u16 flag);
void BgPicture_LoadPalette(void);
void sub_080B0778(void);
s32 sub_080B78A4(void);
void sub_080B05A4(void);
void sub_080B0820(void);
void sub_080B0620(void);
u32 sub_080B8AE0(u16 a, u16 b);
u32 sub_08157238(u8 a);
extern u16 gUnk_03006958;
extern u16 gUnk_03006678[];
u16 sub_08135A94(u8 a);
u32 sub_080B7E0C(u16 arg);
void sub_080B08AC(void);
void sub_080B0888(void);
u32 sub_080B9510(void);
void sub_080D34F0(u32 handle);
u8 Inventory_GetCount(u16 id);
void Inventory_RemoveItem(u16 id);
u32 sub_080D2268(u16 id);
void sub_080CDFF8(u16 a, u16 b);
void Money_Add(s32 v);
u32 Combatant_GetEquip(s32 who, s32 slot);
void Item_GetAttribute(s32 id, s32 field, s32 *out);
void Inventory_AddItem(u16 id);
void Combatant_SetLevel(s32 who, s32 level);
void sub_080C0F70(s32 who, u32 exp);
void Combatant_SetEquip(u32 who, u32 slot, u32 id);
u32 Random_Byte(void);
void Combatant_RecalcStats(s32 who);
void Hud_InvalidateGauges(void);
void Party_BuildSkillList(s32 who);
s32 sub_08136204(s32 who, u32 slot, s32 val);
s32 sub_08136270(s32 who, u32 slot, s32 val);
extern const s8 gUnknown_087903EE[];
void sub_08136114(void);
extern u16 gUnk_03004534;
extern u16 gUnk_030068A0;
extern u32 gUnk_030068B0;
u32 Party_Add(u16 who);
void Party_Remove(u16 who, u32 release);
void Party_BuildMemberNameTiles(void);
void Hud_LoadAllMemberFaces(void);
s32 Stock_FindDemonIndex(s32 demonId);
void Party_FixFormation(void);
u32 BgPicture_StartTask(u16 id);
u32 Flag_Test(u32 flag);
void Flag_Clear(u32 flag);
void Flag_Set(u32 flag);
void Party_SetupGuest(s32 mode);
struct GameStateOrder
{
    u8 filler0[0xA20];
    u8 order[6];        /* 0xA20: party formation, member ids (s8, -1 = empty) */
};
#define PARTY_ORDER(i) (((struct GameStateOrder *)gGameState)->order[i])
extern u16 gUnk_03006944;
extern s16 gUnk_030065E8;
extern u32 gUnk_03006938;
extern u16 *gUnk_030068D0;
extern u16 gUnk_03006610;
extern s16 gUnk_03006910;
extern const u16 gUnknown_08035ABC[];
extern const u16 gUnknown_0803534C[];
extern const u16 gUnknown_08073C5E[];
extern const u16 gUnknown_08074C28[];
extern const u16 gUnknown_08075BE8[];
extern const u16 gUnknown_08076C3C[];
extern const u16 gUnknown_08076F80[];
extern const u16 gUnknown_08077338[];
u32 NameEntry_Open(u16 target);
u32 sub_080B80F8(void);
void sub_08135180(u16 mode);
u16 sub_08130364();
u8 Inventory_IsMaxed(u16 id);
u32 sub_080B4420(u16 a, u16 b);
void SceneEffect_Start(u16 set, u16 id);
u32 sub_080F4360(u8 skill);
bool32 sub_08135370(void);
bool32 sub_08135420(void);
bool32 sub_081354B0(void);
bool32 sub_08135540(void);
bool32 sub_0813560C(void);
extern const u16 gUnknown_0879041E[];
extern u16 gUnk_03006990[];
extern u16 gUnk_030069CC;
extern u16 gUnk_0203DB7C;
extern const u8 gUnknown_08790CF0[];
u32 Moon_GetPhase(void);
u16 Demon_GetField(u16 id, u16 field);
extern u16 gUnk_030068D8;
extern u16 gUnk_03006980[];
extern const u16 gUnknown_0878FDB4[];
extern const u32 gUnknown_0878FD14[];
extern const u16 gUnknown_08790D80[];
extern const u16 gUnknown_08790DA0[];
void sub_080D347C(u16 a, u16 b, u16 c, u16 d, u16 e);
void sub_08130C6C(void);
u16 sub_0813E804(u16 id);
void Stock_AddDemon(u16 id);
void sub_08132350(u16 code);
void Combatant_SetStatus(s32 who, u32 status);
void Combatant_DecodeName(struct PartyMember *member, u16 *dst);
void MsgGlyphQueue_PushSubstClamped(u16 x, u16 y, u16 pal, u16 n);
void sub_0813BECC(u16 a);
u32 sub_0813AC98(void);
extern u32 gUnk_03006840;
extern const u16 gUnknown_080A0BC6[];
extern const u16 gUnknown_08032BBC[];
extern const u16 gUnknown_08790DC0[];
extern const u16 gUnknown_08790DDE[];
u16 Demon_GetRace(u16 id);
u8 sub_0813756C(u16 id);
void sub_08137518(u16 id, s16 n);
void sub_0813B264(void);
bool32 sub_0813B268(void);
void Script_JumpToStatusMessage(u32 msg);
extern u16 gUnk_03006690;
extern u8 gUnk_0300684C;
extern const u16 gUnknown_08790DFC[];
extern const u8 gUnknown_08790E1C[];
extern const u8 gUnknown_081A6ED4[];
extern const u32 gUnknown_0878FE64[];
void sub_080EF20C(s32 who);
void Demon_GetRaceAndAlign(u16 id, u8 *a, u8 *b);
u16 sub_08137B78(u16 a, u16 n);
u32 Magnetite_Get(void);
void Magnetite_Add(s32 delta);
u32 Money_Get(void);
s32 sub_080EF90C(void);
void sub_080EF930(s32 v);
void sub_08133F14(u16 first);
void sub_0813BE50(u16 n);
extern s16 gScriptWaitBusy;
extern s16 gUnk_0203DB48;
extern u16 gUnk_03006670;
extern u32 gYesNoResult;
extern s16 gUnk_0203DB52;
extern u16 gUnk_0203DB56;
extern u32 gUnk_030068C8;
extern u16 gUnk_0203DB62;
u16 sub_0813E854(u16 id);
void ItemStock_Add(u16 id, u32 n);
void ItemStock_Remove(u16 id, u32 n);
u32 Task_IsFree(u32 task);
s32 Task_GetState(u32 task);
s32 Window_IsIdle(u32 win);
u16 ScriptVM_GetTextSpeed(void);
void sub_080C762C(void);
u16 sub_0812685C(void);
void sub_08132890(void);
struct ShopIcon         /* gUnk_03006920, 8 bytes each */
{
    u16 visible;
    u16 tile;
    u16 flag;
    u16 pad6;
};
extern struct ShopIcon gUnk_03006920[];
extern u8 gUnk_0300685C;
extern u16 gUnk_0203DB7E;
u32 sub_0812F188(u16 i);
bool32 sub_0813DA6C(void);
s32 sub_080CE74C(u32 handle);
void Negotiate_CallReply(u16 n);
extern const u16 gUnknown_080A0C0A[];
s32 Combatant_GetStat(s32 who, s32 stat);
u32 sub_08137BB8(void);
u32 sub_080C5C14(u16 id);
u32 sub_0813BDCC(void);
bool32 sub_0813C4FC(u16 kind);
#endif /* GUARD_SCRIPTOPS3_H */
