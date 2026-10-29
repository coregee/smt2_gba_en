#ifndef GUARD_OPTIONS_H
#define GUARD_OPTIONS_H

#include "global.h"
/* status.h declares Equip_CanEquip with an s16 first parameter; the definition here takes an int. */
#define Equip_CanEquip sub_080CDB74_status_h
#include "status.h"
#undef Equip_CanEquip
s32 Equip_CanEquip(s32 who, u8 item);

/* Status screen helpers and equipment/item drawers, 0x080CD3E8-0x080D0288;
   battle item lists and helpers, 0x080DF6D0-0x080E2364. */

u8 *Item_GetRecord(u16 id);
void Sprite_Draw(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
extern const u8 gUnknown_084F02DE[], gUnknown_084F0320[], gUnknown_084F0324[], gUnknown_084F0328[];
extern const u8 gUnknown_084F0194[], gUnknown_084F00F0[], gUnknown_084F00F8[], gUnknown_084F0100[];
extern const u8 gUnknown_084F0108[], gUnknown_084F010C[], gUnknown_084F011C[], gUnknown_084F0124[];
extern const u8 gUnknown_084F012C[], gUnknown_084F0134[], gUnknown_084F013C[], gUnknown_084F0144[];
extern const u8 gUnknown_084F014C[], gUnknown_084F0154[];
extern const u16 gUnknown_084F032C[][7], gUnknown_084F06D6[][5];
extern const void *const gUnknown_084F0974[];
extern u16 gUnk_03000004;

void sub_080CD90C(u16 n, u16 x, u16 pal, u16 y, u16 tile);

s16 sub_080C07FC(s32 who);
s32 Combatant_GetAlignment(s32 who);
void CpuSet(const void *src, void *dest, u32 control);
s32 sub_080CDAE4(s16 align, s32 attr);
s32 sub_080CDB18(u32 kind, s32 attr);

/* gMenuState+0x50: the confirmation window of the equipment screen (inside C0c6Status.pad4C). */
#define MENU_WINDOW50(m) (*(void **)&(m)->pad4C[4])
extern const u16 gUnknown_084F0994[][2];
extern const u16 gUnknown_084F09B0[];
void *Window_CreateOpen(u16 x, u16 y, u16 w, u16 h, u16 bg);
void Window_Close(void *window, u32 erase);
void Text_DrawSpriteString(const u16 *str, u16 a1, u16 a2, u16 x, u16 y, u16 advance);
void Inventory_AddItem(u16 id);
u32 sub_080D2268(u16 id);
void sub_080C9D5C(struct Task *t);
void sub_080C9E08(struct Task *t);
void Equip_ClearSlot(u16 who, u16 slot);
void sub_080CDBD4(void);
void sub_080CDBE8(u16 lo, u16 hi);
void Hud_InvalidateGauges(void);
void Combatant_SetEquipSlot(struct Combatant *c, u16 slot, u16 v);
void Inventory_RemoveItem(u16 id);
void sub_080C08E8(); /* (s32 who, u32 mask); called here with one argument */
void Equip_EquipItem(u16 who, u16 item, u16 keep);
extern const u32 gUnknown_084F09C8[];
s32 Combatant_GetBaseStat(s32 who, s32 stat);
#define MENU_WINDOW4C(m) (*(void **)&(m)->pad4C[0])
s32 Combatant_AddBaseStat(s32 who, u32 stat, s32 delta);
void *YesNo_Create(u32 a);
void sub_080CB068(void);
s32 sub_080CE2A8(struct Combatant *c);
extern u32 gYesNoResult;
u32 Task_IsFree(void *task);
extern const u16 gUnknown_084F0CA0[];
extern void *gUnk_020360B4[8];
void sub_080BF8D8(u32 i);
extern u32 gUnk_03003BB4;
extern u16 gUnk_03004608;
extern const u32 gUnknown_084F0CBC[];
extern u16 gUnk_03004600;
void Party_BuildSkillList(s32 who);
s32 Combatant_IsUsed(s32 who);
s32 Stock_GetCapacity(void);
u32 Fusion_AllHighRace(u16 a, u16 b, u16 c);
s32 Compendium_GetPrice(u16 id);
u16 Comp_DrawSummonCost(s32 value, u16 x, u16 y);
extern const u16 gUnknown_0815BF4A[], gUnknown_0815BF0E[], gUnknown_0815BF62[], gUnknown_0815BF7C[];
extern const u16 gUnknown_0815BED4[], gUnknown_0815BF36[], gUnknown_0815BEFA[], gUnknown_0815BFBE[];
extern const u16 gUnknown_0815BFCC[], gUnknown_0815BFD6[];
extern const u16 gUnknown_084F0EAC[];
void sub_08157EB0(u32 a, struct Task *t, struct C0c6Fade *fade);
u32 Fusion_ResumeScreen(u32 a);
extern u32 gUnk_030068E0;
void sub_080C1384(void);
extern const u32 gUnknown_084F0EC0[];

#define DmaSet3(src, dest, control)              {                                                    vu32 *dmaRegs = (vu32 *)(REG_BASE + 0xD4);       dmaRegs[0] = (vu32)(src);                        dmaRegs[1] = (vu32)(dest);                       dmaRegs[2] = (vu32)(control);                    dmaRegs[2];                                  }
#define DmaFill32_3(value, dest, control)        {                                                    vu32 tmp = (vu32)(value);                        DmaSet3(&tmp, dest, control);                }
void sub_08154EC0(void);
void sub_080C981C(u16 a);
void Status_DrawScreen(void);
void sub_080CEE4C(void);
extern u8 gUnk_0203AC54[];
void sub_080CEE78(void);
u16 sub_080D45F0(u16 *list, u16 a1);
extern struct Task gTasks[64];
void Task_Pause(struct Task *task);
void Task_Resume(struct Task *task);
void sub_080D3F04(struct Task *task, u32 id, u32 vblank);
extern const u16 gUnknown_0815C0AA[], gUnknown_0815BFEA[];
s32 sub_080D45B8(u16 id);
u32 Money_Get(void);
u16 FontSprite_DrawNumber(s32 value, u16 x, u16 y);
extern const u16 gUnknown_0815C02C[], gUnknown_0815C048[], gUnknown_0815C05A[], gUnknown_0815C06E[];
extern const u16 gUnknown_0815C082[];
extern u16 gUnk_0203DB6A;
void sub_080AE2D0(void);
extern u32 gWindowCount;
extern s32 gOpenWindowCount;
void sub_080C6E30(u32 a);
extern struct GameState gSaveSlotPreview;
extern const u32 gUnknown_084F3880[], gUnknown_084F39B4[];
/* gMenuState+0x08 holds a fade task pointer in the option screens (over C0c6Status.unk08/0A). */
#define MENU_FADE08(m) (*(struct C0c6Fade **)&(m)->unk08)
void sub_0812D0FC(u32 a);
void sub_080CF5C0(void);
extern const u8 gUnknown_081B93B0[];
extern u16 gUnk_03000040;
u32 sub_080C2AFC(void);
u32 Settings_GetBattleMsgSpeed(void);
u32 sub_080C2B6C(void);
u32 sub_080C2BA4(void);
u32 sub_080C2BF0(void);
u32 sub_080C2C30(void);
u32 sub_080C2C70(void);
void sub_080C2B14(u16 v);
void sub_080C2B4C(u16 v);
void sub_080C2B84(u16 v);
void sub_080C2BCC(u16 v);
void sub_080C2C0C(u16 v);
void sub_080C2C4C(u16 v);
void sub_080C2C9C(u16 v);
void BgPicture_LoadPalette(void);
void sub_080B04BC(void);
void Palette_CopyWithEffect(u32 a0, const void *src, void *dst, u32 size, u32 a4);
void Palette_MarkDirty(void);
extern u16 gPaletteTarget[], gPaletteBuffer[];
extern u16 gUnk_0201B874[];
/* Option screen labels (ASCII, drawn with DigitFont_DrawAscii). */
extern const u8 gUnknown_084F18A0[], gUnknown_084F18A4[], gUnknown_084F18AC[], gUnknown_084F18B4[];
extern const u8 gUnknown_084F18BC[], gUnknown_084F18C0[], gUnknown_084F18C8[], gUnknown_084F18CC[];
extern const u8 gUnknown_084F18D0[], gUnknown_084F18D8[], gUnknown_084F18E0[], gUnknown_084F18E8[];
extern const u8 gUnknown_084F18F0[], gUnknown_084F18F4[], gUnknown_084F18F8[], gUnknown_084F1900[];
extern const u8 gUnknown_084F1908[], gUnknown_084F1910[], gUnknown_084F1918[], gUnknown_084F1920[];
extern const u8 gUnknown_084F1924[], gUnknown_084F1928[];
void Options_DrawHelp(u16 row);
u16 Options_GetValue(u16 i);
extern const u8 gUnknown_084F1930[];
/* Options: [0] number of choices, [1..3] the values stored by Options_SetValue. */
extern const u16 gUnknown_084F1938[][4];
void sub_080CF61C(void);
void Options_DrawRow(u32 unused, u32 row);
void Options_DrawAll(u32 a);
void sub_080CFC04(u32 a);
void Options_SetValue(u16 i, u16 v);
/* gMenuState as used by the options (CONFIG) screen. */
struct C0cdOptions
{
    u16 row;                    /* 0x00: 0-6 options, 7 EXIT */
    u16 scroll;                 /* 0x02: 1 = row 0 hidden, EXIT shown */
    u16 blink;                  /* 0x04 */
    u16 fromMenu;               /* 0x06: set by Options_Create; 0 = opened from the title screen */
    struct C0c6Fade *fade;      /* 0x08 */
    void *win[9];               /* 0x0C */
};
#define gOptions (*(struct C0cdOptions *)&gMenuState)
#define DmaFill16_3(value, dest, control)        {                                                    vu16 tmp = (vu16)(value);                        DmaSet3(&tmp, dest, control);                }
void sub_080D5B8C(u32 a);
void sub_080CFF84(void);
extern const u32 gUnknown_084F1970[];
extern const u16 *const gUnknown_084F1D5C[8][4];
extern u8 gUnk_02013C74[];
/* gMenuState as used by the shared message window helpers 0x080D0084-0x080D01A4. */
struct C0cdMsgMenu
{
    u16 mode;                   /* 0x00 */
    u16 sel;                    /* 0x02 */
    u16 vblankQueued;           /* 0x04: sub_080D0264 */
    u8 pad06[0x0C - 0x06];
    struct C0c6Fade *fade;      /* 0x0C */
    u8 pad10[0x20 - 0x10];
    void *window;               /* 0x20 */
    void *yesNo;                /* 0x24 */
    u32 shown;                  /* 0x28 */
    const void *msg;            /* 0x2C */
};
#define gMsgMenu (*(struct C0cdMsgMenu *)&gMenuState)
void Field_SetState(u16 state);
void SmallFont_DrawAsciiTinted(const u8 *str, u8 *canvas, u16 x, u16 y, u8 tint, u16 advance);
void sub_080D0118(void);
void sub_080D0238(void);

/* ---- 0x080DF6D0-: link cable block transfer ---- */

/* Transfer state at 0x03006300. */
struct C0cdLink
{
    u16 seq;                    /* 0x00: incremented per transfer */
    u16 block;                  /* 0x02: current 12-byte block */
    u16 unk04;
    u16 size;                   /* 0x06: bytes to send */
    u16 sent;                   /* 0x08 */
    u16 recv;                   /* 0x0A */
    u16 sum;                    /* 0x0C: checksum of the data (Link_Checksum) */
    u16 unk0E[2];               /* 0x0E */
    u8 pad12[0x18 - 0x12];
    const u8 *src;              /* 0x18 */
    u8 *dst[2];                 /* 0x1C: receive pointers per player */
    u8 pad24[0x2C - 0x24];
    u32 out[2];                 /* 0x2C */
};
/* Received packets (0x03006340) of the two players: a u16 header then 12 data bytes. */
struct C0cdLinkPacket
{
    u16 hdr;
    u8 data[14];
};
extern struct C0cdLink gUnk_03006300;
extern struct C0cdLinkPacket gUnk_03006340[2];
extern u16 gUnk_03006380[8];
extern u8 gShopItemIds[0x100];
extern u8 gShopItemPrices[2][0x100];
extern u8 gUnk_0300636C;
u16 Link_Checksum(u16 n, const u8 *p);
u8 sub_080DF6FC(u16 hdr);
extern u16 gUnk_03006390;
void Link_StartTransfer(u16 size, const u8 *data, u32 *out);
u8 sub_080DF760(void);
u32 sub_080DF7B8(void);
u32 sub_080DF990(void);
u8 sub_080DFB98(void);
void SpriteFont_DrawAscii(u16 c, u16 pal, u16 x, u16 y);
extern u32 gUnk_03006360;

/* Two six-digit amounts edited digit by digit (sub_080DFF08). */
struct C0cdLinkBet
{
    s8 cursor;                  /* 0x00: digit 0-5 */
    s8 digits[12];              /* 0x01: a then b, six decimal digits each */
    u8 pad0D[3];
    u32 a;                      /* 0x10 */
    u32 b;                      /* 0x14 */
    u32 maxA;                   /* 0x18 */
    u32 maxB;                   /* 0x1C: money */
};
/* One player's link record (0x58 bytes): ours at 0x0203B554 (over gStatusList), the other
   player's at 0x0203B5AC, followed by the amount entry at 0x0203B604. */
struct C0cdLinkData
{
    u32 magic;                  /* 0x00: 0x15273950 */
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 money;                  /* 0x10 */
    u32 unk14;
    u32 mag;                    /* 0x18 */
    u8 unk1C;
    u8 pad1D[3];
    u32 unk20;
    u8 demonCount;              /* 0x24: entries used in demons */
    u8 offerCount;              /* 0x25: entries used in offers */
    u16 demons[12];             /* 0x26: offered demon ids, 0xFFFF = free */
    u8 pad3E[2];
    struct C0c2InvEntry offers[5];  /* 0x40: id 0xFFFF = free */
    u16 unk54;
    u16 unk56;
};
struct C0cdLinkAll
{
    struct C0cdLinkData rec[2];
    struct C0cdLinkBet bet;     /* 0xB0 */
};
/* Five-digit entry kept in a task's data (+0x50) by sub_080E03C4/sub_080E0434. */
struct C0cdLinkEntry
{
    s8 cursor;
    s8 digits[5];
    u8 pad06[2];
    u32 value;                  /* 0x08 */
    u32 max;                    /* 0x0C */
};
#define gLink (*(struct C0cdLinkAll *)gStatusList)
#define gLinkData (gLink.rec[0])
void sub_080E02B0(struct C0cdLinkData *d, struct C0cdLinkBet *bet);
void sub_080E06EC(struct C0cdLinkData *d, struct C0cdLinkEntry *e);
void LinkTrade_ClearItemOffers(struct C0cdLinkData *d);
void LinkTrade_ClearDemonOffers(struct C0cdLinkData *d);
u32 Magnetite_Get(void);
void DigitFont_DrawStringTinted(const u8 *str, u8 *canvas, u16 x, u16 y, u8 tint, u16 advance);
extern const u8 gUnknown_08589C94[], gUnknown_08589CA0[];
extern u8 gUnk_02001000[];
extern const u16 *const gUnknown_08589CA8[];
extern const u16 gUnknown_08580F80[];
extern u16 gUnk_030030F0[];
extern const u8 gUnknown_080087C8[];
/* Selection state kept in a task's data (+0x50) by sub_080E077C. */
struct C0cdLinkSel
{
    s8 cursor;
    s8 digits[2];               /* 0x01: two-digit count */
    u8 pad03;
    u16 unk4;                   /* 0x04: item id */
    u16 unk6;                   /* 0x06: count */
};
s32 Item_GetSlotMask(s32 item);
/* Item list built by sub_080E0864 at 0x0203C4D0 (ends with 0xFFFF, 0xFFFF). */
extern u8 gUnk_0203C200[];
u8 sub_08126928(u8 id, u8 type, u16 columns, u16 rows, u16 perColumn);
extern const u32 gUnknown_0858A818[];
u16 sub_080E0864(u32 mask);
/* Menu cursor state (as in menucur.h). */
struct MenuCursor
{
    u8 state;
    u8 delay;
    u8 mode;
    u8 flags;
    u16 keys;
    u16 columns;    /* 0x06 */
    u16 rows;       /* 0x08 */
    u16 count;      /* 0x0A */
    u16 top;        /* 0x0C */
    u16 onScreen;   /* 0x0E */
    u16 perColumn;  /* 0x10 */
    u16 index;      /* 0x12 */
    u16 unk14;
    u16 column;     /* 0x16 */
    u16 row;        /* 0x18 */
    u16 seMove;     /* 0x1A */
    u16 sePage;     /* 0x1C */
    u16 seA;        /* 0x1E */
};
struct MenuCursor *sub_08126D1C(u8 id);
void *memset(void *dst, int c, unsigned long n);
u8 *Action_GetRecord(u16 id);
void Text_DrawSpriteStringTinted(const u16 *str, u16 a1, u16 a2, u16 x, u16 y, u16 advance, u16 palette);
extern const u8 gUnknown_0800853C[];
u8 LinkTrade_IsItemOffered(struct C0cdLinkData *d, u16 id);
u8 sub_080E0D08(struct C0cdLinkData *d);
u8 LinkTrade_AddItemOffer(struct C0cdLinkData *d, u16 id, u16 count);
u8 LinkTrade_RemoveItemOffer(struct C0cdLinkData *d, u16 id);
void sub_08126A08(u8 id);
void sub_081269B0(u8 id);
void sub_080D9B64(struct Task *t);
void sub_080E1030(struct C0cdLinkData *d, struct C0cdLinkData *marks);
void sub_080E1644(struct C0cdLinkData *d, struct C0cdLinkData *marks);
u16 BattleMenu_BuildMemberList(u8 mode);
s32 sub_0815B8F8(s16 id, u32 a);
u8 LinkTrade_IsDemonOffered(struct C0cdLinkData *d, u16 id);
u8 sub_080E156C(struct C0cdLinkData *d);
u8 LinkTrade_AddDemonOffer(struct C0cdLinkData *d, u16 id);
u8 LinkTrade_RemoveDemonOffer(struct C0cdLinkData *d, u16 id);
/* Demon pick state at the start of a task's data (sub_080E1218, sub_080E1280). */
struct C0cdLinkPick
{
    u8 unk0;
    u8 pad1;
    u16 id;                     /* 0x02: demon id */
};
u8 sub_080DF388(u32 a);
extern u16 gUnk_03006394;
extern const u32 gUnknown_0858B180[], gUnknown_0858B1BC[];
u8 sub_080DF4B8(void);
u8 Link_TransferStep(void);
void Link_Exchange(u16 size, const u8 *data, u32 dst);
extern const u32 gUnknown_0858B1F8[], gUnknown_0858B228[];
extern const u16 gUnknown_0800980C[];
extern const u16 *const gUnknown_0858B250[];
extern u8 gUnk_03006398;
void Money_Add(s32 v);
void Magnetite_Add(s32 delta);
void Party_Remove(u16 who, u32 release);
s32 Stock_AddDemon(u16 demonId);
void sub_080C29E8(u16 id);
u32 SaveSlot_Write(u32 slot, void *src);
/* libgcc soft-float helpers (unnamed in symbols.tsv): __floatsidf, __adddf3, __muldf3,
   __truncdfsf2, __fixsfsi.  Called explicitly because match.py cannot resolve the libcall names. */
double __floatsidf(s32 v);
double __adddf3(double a, double b);
double __muldf3(double a, double b);
float __truncdfsf2(double a);
s32 __fixsfsi(float a);
void Party_FixOrderAfterTrade(void);
s16 sub_08134C3C(u16 id);
s32 sub_0815BA28(u16 id);
s16 Combatant_GetLevel(s32 who);
struct C0c2InvEntry *sub_080E0E04(struct C0cdLinkData *d, u16 id);

#endif
