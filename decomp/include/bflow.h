#ifndef GUARD_BFLOW_H
#define GUARD_BFLOW_H

#include "global.h"

/* Battle message flow (0x080EBED4-0x080ECFFF) and script opcode handlers 0x32A-0x33A
   (0x081332BC-0x08134000). Declarations copied from btext.h / script.h are kept
   separate so this header can be used alone. */

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

/* Battle message window (same layout as struct BattleMsg in btext.h). */
struct BFlowMsg
{
    u8 mode;
    u8 unk1;
    u8 delay;
    u8 typed;
    u8 done;            /* 0x04 */
    u8 row;
    u8 lines;
    u8 locked;          /* 0x07 */
    u16 *src;
    u16 text[0x40];
    u16 text2[0x40];
    u16 compose[0x40];  /* 0x10C */
    u16 autoClose;
    u16 autoCloseTimer;
};

/* Animated demon portrait / sprite at 0x0203D360. */
struct PortraitFrame
{
    const void *sprite;
    u16 duration;       /* 0x100 = jump back loopBack frames */
    u8 loopBack;
    u8 pad7;
};

struct Portrait
{
    u8 state;           /* 0x00 */
    u8 unk1;
    u8 id;              /* 0x02: index into gUnknown_0876CE10 (0xD2 = palette-cycled) */
    u8 sel;             /* 0x03 */
    u8 frame;           /* 0x04 */
    u8 tick;            /* 0x05 */
    u16 unk6;           /* 0x06 */
    u8 palPhase;        /* 0x08 */
    u8 pad9[3];
    u16 x;              /* 0x0C */
    u16 y;              /* 0x0E */
    const struct PortraitFrame *frames; /* 0x10 */
    struct Task *task;  /* 0x14 */
};

struct PortraitInfo     /* gUnknown_0876CE10, 0x18 bytes each */
{
    const struct PortraitFrame *const *anim;    /* anim[1] = frame list */
    const u16 *palette;
    const void *gfx[4];
};

/* The battle EWRAM block at 0x0203C200. Only fields used here are named. */
struct BattleFlow
{
    u8 filler0[0x10];
    u32 handles[6];             /* 0x010 */
    u8 filler28[4];
    struct Task *fadeTask;      /* 0x02C */
    u8 filler30[0x695 - 0x30];
    u8 unk695;                  /* 0x695 */
    u8 filler696[0x7E0 - 0x696];
    struct BFlowMsg msg;        /* 0x7E0 */
    struct Task *msgTask;       /* 0x970 */
    void *window;               /* 0x974 */
    s16 state;                  /* 0x978 */
    s16 substate;               /* 0x97A */
    u16 unk97C;
    u16 unk97E;                 /* 0x97E */
    u8 filler980[0x10];
    u32 combatants[2];          /* 0x990 */
    u8 filler998[0xEC0 - 0x998];
    u8 unkEC0;                  /* 0xEC0 */
    u8 fillerEC1[0xF68 - 0xEC1];
    s16 unkF68;                 /* 0xF68 */
    s16 unkF6A;                 /* 0xF6A */
    u8 fillerF6C[0x1122 - 0xF6C];
    u8 unk1122;                 /* 0x1122 */
    u8 filler1123[0x1160 - 0x1123];
    struct Portrait portrait;   /* 0x1160 */
    u8 filler1178[0x1189 - 0x1178];
    u8 unk1189;                 /* 0x1189 */
    u8 filler118A[2];
    u16 portraitDx;             /* 0x118C */
    u16 unk118E;                /* 0x118E */
    u8 filler1190[0x11A8 - 0x1190];
    u16 unk11A8;                /* 0x11A8 */
    u8 filler11AA[0x11B2 - 0x11AA];
    u16 unk11B2;                /* 0x11B2 */
};

struct FadeData         /* task data of gUnknown_086BF86C */
{
    u8 a;
    s8 b;
    s8 level;
    u8 tick;
    s8 count;
};

extern u8 gUnk_0203C200[];
#define BFLOW ((struct BattleFlow *)gUnk_0203C200)

struct BattleFlowIwram  /* 0x030063A0 */
{
    u8 filler0[0xC];
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
};
extern struct BattleFlowIwram gUnk_030063A0;
extern u8 *gUnk_03006434;
extern u16 gHudState[];

void *memset(void *dst, int c, u32 n);

/* btext / battle */
void BattleMenu_SetMode(u8 mode, u16 *src);
void BattleMenu_SetModeAutoClose(u8 mode, u16 *src);
void BattleMenu_Reset(void);
u8 BattleMsg_IsDone(void);
void BattleMsg_SetLocked(u8 locked);
u16 *Menu_ExpandListTemplate(u16 *tmpl, u32 arg);
u16 *MessageBox_ComposeSpeciesText(u32 a0, u32 a1, u32 a2, u32 a3, const u16 *tmpl);
u16 *MessageBox_ComposeNameText(u32 who, const u16 *tmpl);
u8 *Battle_GetCombatant(u16 idx);
void Combatant_DecodeName(u8 *combatant, u16 *dst);
bool32 Combatant_IsInParty(u16 idx);
bool32 Combatant_IsAlive(u16 idx);
s32 sub_080F4968(void);
void Window_SetHeight(void *window, u32 h);
void Window_Close(void *window, u32 arg1);
struct Task *Task_Create(const void *script, u32 parent);
void Task_End(struct Task *task);
u32 Flag_Test(u32 flag);
u16 Combatant_GetStatus(u32 who);

/* region 1 */
u16 *MessageBox_ComposeWrappedText(u16 *src, u32 who);
u16 *Battle_GetMessage(u16 id);
void sub_080EC948(void);
void BattleMsg_SetDone(u8 done);
void sub_080ECF60(u16 se);
void sub_080EC2E4(void);
u8 BattleSprite_Animate(struct Portrait *p);
u32 sub_080ECB98(u16 id, u8 bank);
u32 sub_080ECB6C(u16 id, u8 bank);
void BattleSprite_DmaBank0(void);
void BattleSprite_DmaBank1(void);

void sub_080EA210(void);
u32 Battle_IsTwoSided(void);
u32 sub_080EDA24(u32 i);
u32 sub_080ED9F4(void);
void sub_080C84A0(void);
u16 sub_080EDE70(void);
void sub_080ED920(u16 a);
void sub_080ED90C(u16 a);
u32 sub_080ED8F4(void);
void sub_080C700C(void);
void sub_080C7054(void);
s32 sub_080EFA9C(void);
s16 Battle_ActiveSide(void);
void sub_080E5A18(u32 a);
void sub_080E5A3C(void);
void sub_0813EB84(u16 a, u16 b);
u16 sub_080E6FA0(void);
void sub_0813E914(void);
void sub_080C7430(void);
void sub_080C7648(void);
u32 sub_0813EB60(void);
void sub_080EEF98(void);
void sub_080C7414(void);
void sub_080C762C(void);
void sub_080C6FF0(void);
void sub_080C7038(void);
s32 sub_080EDF0C(void);
u16 sub_080EFEDC(void);
s32 Battle_IsPartyDefeated(void);
void sub_080B9058(void);
void sub_080C140C(u32 a, u32 b);
void sub_080C1440(void);
void Palette_CopyWithEffect(u32 a0, const void *src, void *dst, u32 a3, u32 a4);
void Palette_MarkDirty(void);
u16 Color_ApplyEffect(u16 color);
void Sprite_DrawPlain(const void *sprite, u32 a1, u32 a2, u32 a3, u32 a4, u32 x, u32 y);
void VBlankTask_AddCounted(void (*func)(void), u32 count);
void sub_08126D34(u16 a);
u32 sub_080C88C0(u16 a);
u32 sub_080C8890(u16 a);
u32 sub_080C88A8(u16 a);
u32 sub_080C88D8(u16 a);
s32 sub_080C88F0(u32 h);
void Music_Play(u16 se);
void sub_080E845C(u8 a, s8 b, s8 c);

extern const u16 *const gUnknown_0876FB54[];
extern const struct PortraitInfo gUnknown_0876CE10[];
extern const u16 gUnknown_086BF72C[];
extern const u32 gUnknown_086BF734[];
extern const u32 gUnknown_086BF840[];
extern const u32 gUnknown_086BF86C[];
extern const u16 gUnknown_086BE5DA[];
extern const u16 gUnknown_081267E0[];
extern const u16 gUnknown_081267BA[];
extern const u16 gUnknown_081267A6[];
extern const u16 gUnknown_081265BE[];
extern const u16 gUnknown_0812490C[];
extern const u16 gUnknown_0812466C[];
extern const u16 gUnknown_0812634E[];
extern const u16 gUnknown_08126254[];
extern const u16 gUnknown_081262BE[];
extern u8 gBgPictureBuffer[];
extern u8 gUnk_030000B4[];
extern u8 gUnk_030010B4[];
extern u16 gPaletteBuffer[0x200];   /* 0x03002DB0, uploaded to PLTT */

/* ---- script VM (region 2), copied from script.h ---- */
extern u16 *gScriptBase;
extern u16 gScriptPc;
extern u16 *gScriptJumpTarget;
extern s16 gScriptWaitState;
extern u16 gScriptYield;
extern u16 *gUnk_0203DAC8[];        /* gosub return bases; [0] = 0x33A continuation */
extern u16 gUnk_0203DB28[];
extern u16 gUnk_03006970[];
extern u16 gUnk_0203DB68;
extern u32 gUnk_030068F0[];
extern u32 gUnk_030069C0[];
extern u16 gScriptSubstBuf[16];
extern u16 gMsgGlyphCount;           /* glyph queue count (gMsgGlyphQueue) */
extern u16 gNewKeys;

#define SCRIPT_READ() (gScriptBase[gScriptPc++])

void sub_080C3818(u32 a);
void CharObj_End(u32 h, u32 a);
void sub_080E9044(u32 h, u16 i);
u32 Money_Get(void);
void Magnetite_Add(u16 a);
void Money_Add(s32 v);
u16 Random_Byte(void);
bool8 Inventory_GetCount(u16 item);
u32 sub_080C4C7C(u16 item);
u32 sub_080D3400(u32 a, u32 b, u16 c);
u32 sub_080D2268(u16 id);
void Font_ResetGlyphSpriteCache(u32 arg);
void MsgWindow_DrawItemCount(u16 a);
u16 Party_CountEquipped(s16 a, u16 item);
s32 Equip_CanEquip(s16 a, u8 item);
u8 *Action_GetRecord(u16 id);
u8 *Equipment_GetRecord36_MidRange(u16 id);
u8 *Item_GetRecord(u16 id);

extern u16 gUnk_030065F8;
extern u16 gUnk_0203DB62;
extern u16 gUnk_03006914;
extern s16 gMsgGlyphList2Count;           /* entry count of gMsgGlyphList2 */
extern u16 gMsgGlyphList2[];         /* glyph queue: (glyph, x, y, palette) per entry, 25 entries */
extern u16 gMsgGlyphQueue[];         /* glyph queue: (glyph, x, y, palette) per entry, 64 entries */
extern u16 gUnk_030069D0;
extern u16 gUnk_030069D8[];
extern u16 gShopItemIds[];         /* shop item ids, 0xFFFF-terminated */
extern u32 gShopItemPrices[];         /* shop item prices */
extern s16 gUnk_03006688;
extern u16 gUnk_03006820[];
extern u16 gUnk_03006940;
extern s16 gUnk_0300696C;
extern u16 gUnk_030065E4;
extern u32 gUnk_030068A4;
extern u16 gUnk_0300699C;
extern u16 gUnk_03006848;
extern u16 gUnk_03006680;
extern s16 gUnk_03006898;

struct PartyMember      /* gGameState: 0x80 bytes each */
{
    u8 filler0[0xE];
    u16 unkE;           /* non-zero = slot used */
    u16 flags;          /* 0x10: 0xA000 = cannot act */
    u8 filler12[0x6E];
};
extern struct PartyMember gGameState[];

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

struct ShopIcon         /* gUnk_03006920, 8 bytes each */
{
    u16 visible;
    u16 tile;
    u16 flag;
    u16 pad6;
};
extern struct ShopIcon gUnk_03006920[];

extern const void *const gUnknown_08790330[];
extern const u16 gUnknown_08790130[];
extern const u16 gUnknown_0879038A[];   /* text row y positions */
extern const u16 gUnknown_0878FC64[];
extern const u32 gUnknown_0878FD58[];
extern const u32 gUnknown_0878FCD0[];
extern const u16 gUnknown_0807DED2[];
extern const u16 gUnknown_0807E088[];
extern const u16 gUnknown_0807D988[];
extern const u16 gUnknown_0807D984[];

extern u16 gUnk_03006844;
extern u16 gTextColumn;
extern u16 gTextLine;
extern u16 gUnk_0203DB4A;
extern u16 gUnk_03006678[2];        /* [0] = cursor shown, [1] = its y */
extern u16 gUnk_0203DB88[];         /* item id list, 0xFFFF-terminated */
extern u16 gUnk_030068D8;
extern const u16 gScriptDigitGlyphs[];
extern const u16 gUnknown_08790390[];
void MsgWindow_RestoreGlyphs(void);

void Shop_InitItemList(u16 first, u16 mode);
void MsgGlyphQueue_PushSubstClamped(u16 x, u16 y, u16 pal, u16 n);
void MsgGlyphQueue_PushSubst(u16 x, u16 y, u16 pal, u16 n);
void Script_QueuePartyNames(u16 base, u16 mode);
u16 sub_08133A60(u16 id);
void Shop_QueueNameRow(u16 row, u16 pal);

#endif /* GUARD_BFLOW_H */
