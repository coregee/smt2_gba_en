#ifndef GUARD_INVENTORY_H
#define GUARD_INVENTORY_H

#include "global.h"

/* Inventory, money, demon stock and graphics helpers, 0x080C2D48-0x080C6FD8.
   Declarations copied from other headers are kept here so this header can be used alone. */

#define DmaSet(dmaNum, src, dest, control)                      \
{                                                               \
    vu32 *dmaRegs = (vu32 *)(0x040000B0 + 12 * (dmaNum));       \
    dmaRegs[0] = (vu32)(src);                                   \
    dmaRegs[1] = (vu32)(dest);                                  \
    dmaRegs[2] = (vu32)(control);                               \
    dmaRegs[2];                                                 \
}
#define DmaCopy32(dmaNum, src, dest, size) DmaSet(dmaNum, src, dest, (0x8000 | 0x0400) << 16 | ((size) / 4))
#define DmaCopy16(dmaNum, src, dest, size) DmaSet(dmaNum, src, dest, 0x8000 << 16 | ((size) / 2))
#define DMA_FILL(dmaNum, value, dest, size, bit)                                    \
{                                                                                   \
    vu##bit tmp = (vu##bit)(value);                                                 \
    DmaSet(dmaNum, &tmp, dest, (0x8000 | (bit == 32 ? 0x0400 : 0) | 0x0100) << 16 | ((size) / (bit / 8))); \
}
#define DmaFill32(dmaNum, value, dest, size) DMA_FILL(dmaNum, value, dest, size, 32)
#define DmaFill16(dmaNum, value, dest, size) DMA_FILL(dmaNum, value, dest, size, 16)

struct C0c2InvEntry
{
    u16 id;
    u16 count;
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
    u8 unk16;
    s8 unk17;
    s16 hp;             /* 0x18 */
    s16 maxHp;          /* 0x1A */
    s16 mp;             /* 0x1C */
    s16 maxMp;          /* 0x1E */
    u8 equip[7];        /* 0x20: 0xFF = empty */
    u8 pad27;
    u8 base[8];         /* 0x28 */
    u8 bonus[8];        /* 0x30 */
    u8 extra[8];        /* 0x38 */
    u8 total[8];        /* 0x40 */
    s16 derived[8];     /* 0x48 */
    u16 unk58;
    u8 pad5A[3];
    u8 skills[32];      /* 0x5D: 0xFF-terminated */
    u8 pad7D[3];
};

/* gGameState (0x030046C0): only the fields used here. */
struct C0c2GameState
{
    struct Combatant members[20];
    u8 names[4][8];     /* 0xA00 */
    s8 order[6];        /* 0xA20: active party, member index or -1 */
    u8 padA26;
    u8 unkA27;          /* 0xA27: 0-7, advanced every 16 frames by Hud_Update */
    u8 padA28[0xA38 - 0xA28];
    u16 unkA38;
    u8 padA3A[0xAC0 - 0xA3A];
    u16 unkAC0;
    u8 unkAC2;
    u8 stockMax;        /* 0xAC3 */
    u8 padAC4[0xAC8 - 0xAC4];
    u16 unkAC8;         /* 0xAC8: bit set (sub_080C4BE4) */
    u8 bitsACA[0xAD8 - 0xACA];      /* sub_080C4C18 / sub_080C4C3C */
    u32 money;          /* 0xAD8: capped at 999999 */
    u32 magnetite;      /* 0xADC: capped at 99999 */
    u8 padAE0[0xAEC - 0xAE0];
    struct C0c2InvEntry inv[0x15A];    /* 0xAEC (= gInventory) */
    u8 pad1054[0x18A0 - 0x1054];
    u16 unk18A0;
    u16 unk18A2;
    u16 unk18A4;
    u16 unk18A6;
    u16 unk18A8;
    u16 unk18AA;
    u16 unk18AC;
    u16 unk18AE;
    u8 pad18B0[0x18C8 - 0x18B0];
    u32 coins[3];       /* 0x18C8: per-casino counters (sub_080C317C) */
    u8 pad18D4[0x18F8 - 0x18D4];
};
extern struct C0c2GameState gGameState;
extern struct C0c2InvEntry gInventory[0x15A];

/* gFieldState (0x03004550): only the fields used here. */
struct C0c2FieldState
{
    u16 unk00;          /* state */
    u16 facing;         /* 0x02 */
    u8 pad04[0x0E - 0x04];
    u16 unk0E;
    u16 pad10;
    u16 x;              /* 0x12 */
    u16 y;              /* 0x14 */
    u8 pad16[0x1A - 0x16];
    u16 width;          /* 0x1A */
    u16 height;         /* 0x1C */
    u16 unk1E;
    u16 *squares;       /* 0x20: width * height map squares */
    u8 pad24[0x58 - 0x24];
    u32 unk58;
};

/* 0x0200AF08: the 3x5 squares in front of the player (MiniView_SampleAhead), row 0 farthest. */
struct C0c2ViewCell
{
    u16 valid;
    u16 pad;
    u16 walls[4];       /* relative to the facing, from gUnknown_0815F2E6 shifts */
};
#define gMiniViewCells ((struct C0c2ViewCell (*)[3])0x0200AF08)

struct MapHeader
{
    u8 pad00[8];
    u16 originX;        /* 0x08 */
    u16 originY;        /* 0x0A */
};
extern u16 gUnk_03004514;
extern const u16 gUnknown_0815F2E6[];
extern u16 gWindowTilemapBuffer[];     /* mini view tilemap, DMA'd to 0x06001000 */
extern u8 gUnk_03000030, gUnk_03000031, gUnk_03000034, gUnk_03000035, gUnk_03000038;
extern const u8 gUnknown_080008C0[];
extern const u8 gUnknown_081A6674[];
extern struct C0c2FieldState gFieldState;

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

/* Data of the object tasks in gCharTasks (created by CharObj_Create). */
struct ObjData
{
    u16 unk00;
    u16 palSlot;        /* 0x02: 0 -> palette 14, 1 -> 15, else 13 */
    u16 hasPal;         /* 0x04 */
    u16 id;             /* 0x06 */
    u16 x;              /* 0x08 */
    u16 y;              /* 0x0A */
    u16 unk0C;
    u16 unk0E;
    u16 unk10;          /* 0x10 */
    u16 unk12;
    u16 unk14;          /* 0x14: glow direction, or (with unk16) the child task */
    u16 unk16;          /* 0x16: glow step */
    u16 frame;          /* 0x18 */
    u16 unk1A;
    u16 fadeIn;         /* 0x1C: sub_080C3F4C fades in from black */
    u16 fadeWhite;      /* 0x1E: sub_080C3F4C fades in from white */
    struct Task *child20;       /* 0x20: character objects' child task */
};

/* Char_GetRecord: character sprite records. */
struct CharGfxRecord
{
    u16 unk00;
    u16 unk02;          /* 0x02: non-zero blinks (sub_080C43B4) */
    const void *gfx[4][2];      /* 0x04 */
    const u16 *palette; /* 0x24 */
    const void *script; /* 0x28: task script of kind-2 records */
};
struct C0c2FieldEvent
{
    u32 unk0;
    const void *script;
};
extern u16 gUnk_0203DB28[2];
extern const u8 gUnknown_081A65B8[];
extern const u8 gUnknown_081A64A8[];
extern const u8 gUnknown_081A64F8[];
extern const u8 gUnknown_0855FB78[];
extern const u8 gUnknown_081A65DC[];
extern const u8 gUnknown_081A65E4[];
extern const u8 gUnknown_081A65EC[];
extern const u8 gUnknown_08000FF0[];
extern const u8 gUnknown_08008660[];
extern const u8 gUnknown_08001000[];
extern const u8 gUnknown_08008670[];
extern const u8 gUnknown_0800108C[];
extern const u8 gUnknown_0800876C[];
extern const u8 gUnknown_0800109C[];
extern const u8 gUnknown_08008750[];
extern void (*gMainCallback)(void);
extern u16 gUnk_0300000E;
extern struct Task *gUnk_030068F0[8];
extern const u8 gUnknown_08005028[];
extern const u8 gUnknown_08004FF8[];

/* Demon object tasks keep their child task in unk14/unk16. */
#define OBJ_CHILD(d) (*(struct Task **)&(d)->unk14)

/* gDemonGfxRecords (0x0872C774), 0x1C bytes each. */
struct DemonAnim
{
    u32 unk0;
    const void **frames;    /* 0x04 */
};
struct DemonGfxRecord
{
    u16 flags;
    u16 pad02;
    const void *palette;        /* 0x04 */
    struct DemonAnim *anim;     /* 0x08 */
    const void *gfx[2][2];      /* 0x0C: [half][step]: step 0 Huffman source */
};
extern const struct DemonGfxRecord gDemonGfxRecords[];

/* 0x0203C200 + 0xDA0 + slot * 0x40 (sub_080E8AA0): one battle demon sprite. */
struct C0c2DemonSprite
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 pad3[9];
    const void *def;    /* 0x0C */
    u16 pad10;
    u16 demonId;        /* 0x12 */
};

struct PalFade
{
    u16 active;
    u16 duration;   /* steps left, 0xFFFF = until the target is reached */
    u16 delay;      /* frames per step */
    u16 timer;
    u16 start;      /* first colour */
    u16 count;      /* number of colours */
    u16 waitTag;
    u16 pad;
    u16 accum[32];
};
extern u16 gPaletteBuffer[0x200];
extern const void *const gUnknown_08002C20[];
extern const void *const gUnknown_08002C58[];
extern const u8 gUnknown_081A647C[];
extern const u8 gUnknown_081A631C[];
extern const u8 gUnknown_081A6420[];

/* 0x02036074: reference-counted graphics slots, (users, id) pairs. */
struct C0c2GfxSlot
{
    u16 count;
    u16 id;
};
extern u16 gGfxSlots[8][2];   /* (count, id) pairs */
extern struct Task *gCharTasks[8];
extern u32 gUnk_030069C0[];

extern u32 gFrameCounter;
extern u16 gPaletteTarget[0x200];
extern u16 gUnk_03003FC4;
extern u16 gUnk_03004534;
extern u32 gUnk_0300453C;
extern u32 gUnk_03004544;
extern u32 gUnk_03004628;
extern u32 gUnk_03003BB8;
extern u32 gUnk_03004614;
extern u16 gWorldMap[];
extern u16 gUnk_0203A448;
extern u16 gUnk_0203A44A;
extern u16 gUnk_0203A44C;

extern const u32 gUnknown_081BABB0[];
extern const u32 gUnknown_081BB850[];
extern const u16 gUnknown_081BB7B0[];
extern const u16 gUnknown_081BB7D0[];
extern const u16 gUnknown_081BBA50[];
extern const u16 gUnknown_081A62F4[];
extern const void *const gUnknown_081A62B0[];
extern const u16 gUnknown_081A630C[];
extern const void *const gUnknown_081A62D4[];

void sub_080C12C0(u16 a, u16 b, u16 c);
void sub_080C1300(u16 a);
void Encounter_SetCounter(u16 v);
void sub_080C2CC0(void);
void Palette_CopyWithEffect(u32 a0, const void *src, void *dst, u32 a3, u32 a4);
s32 Combatant_GetAlignment(s32 who);
void Sprite_Draw(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
s16 ScriptVM_RunAlt(const void *script);
struct Combatant *Party_GetMember(u16 id);
struct Combatant *Battle_GetCombatant(u16 idx);
u16 Party_CountEquipped(s16 a, u16 item);
void sub_080C2764(u16 id);
void sub_080C2790(u16 id);
void Combatant_RecalcStats(s32 who);
void Party_BuildMemberNameTiles(void);
void Hud_LoadAllMemberFaces(void);
u16 Combatant_GetStatus(u32 who);
void sub_080E9044(struct Task *h, u16 i);
void CharObj_End(struct Task *t, u32 a);
struct PalFade *PalFade_FadeRangeToBlackTagged(u16 start, u16 count, u16 delay, u16 tag);
struct PalFade *PalFade_FadeRangeInFromBlackTagged(u16 start, u16 count, u16 delay, u16 tag);
struct PalFade *PalFade_FadeRangeInFromBlack(u16 start, u16 count, u16 delay);
struct Task *Task_GetParent(struct Task *task);
struct Task *Task_Create(const void *script, u32 parent);
void Task_End(struct Task *task);
void HuffUnComp(const void *src, void *dest);
void LZ77UnCompWram(const void *src, void *dest);
u32 Palette_IsBg13Black(void);
void Palette_MarkDirty(void);
void Palette_FillWithEffect(u32 a0, u16 color, void *dest, u32 size, u32 a4);
void VBlankTask_AddCounted(void (*func)(void), u32 count);
struct C0c2DemonSprite *sub_080E8AA0(u8 slot);
u32 sub_080E88C0(u8 slot);
u16 sub_080E8AC0(u16 id);
void sub_080E8A28(u8 slot, u16 id);
const struct DemonGfxRecord *Demon_GetGfxRecord(u16 id);
void sub_081583F4(const void **a);
void Sprite_DrawSharedAffine(const void **def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y,
                  u8 matrix);
u32 Flag_Test(u32 flag);
void Flag_Clear(u32 flag);
void sub_080C3910(void);
void sub_080C3934(void);
void sub_080C3958(void);
u32 GfxSlot_Acquire(struct Task *t, u16 id);
const struct CharGfxRecord *Char_GetRecord(u16 id);
u16 PalFade_AllDone(void);
void Sprite_DrawBlended(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
void sub_080D977C(void);
void sub_080C3EBC(void);
void sub_080C3EE0(void);
void sub_080C3F04(void);
void sub_080C3F28(void);
void sub_080C3F4C(struct ObjData *obj, const void *pal, u32 start, u32 size, u32 fade);
void CharObj_UpdateGlow(struct ObjData *d, u16 pal);
u16 sub_080C4388(struct ObjData *d);
const void *sub_080C43B4(struct ObjData *d);
void sub_080C43F8(struct Task *t, const void *def, u32 tile, u32 pal);
void sub_080C44CC(struct ObjData *d, const void *def, u16 layer, u16 pal, u16 prio, u16 tile, u16 x, u16 y);
u32 sub_080C423C(struct ObjData *d);
u16 Color_StepComponent(u16 cur, u16 target, u16 up);
void sub_080C457C(struct Task *t, u32 v);
const struct DemonGfxRecord *sub_080D8248(u16 id);
struct PalFade *PalFade_FadeRangeToBlackWithDuration(u16 start, u16 count, u16 delay, u16 duration);
struct C0c2FieldEvent *FieldEvent_FindAt(u16 x, u16 y, u16 dir, u16 *id);
void Sprite_DrawSingle(const void *tmpl, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
struct Task *CharObj_FindInGroup(u16 key, u16 id);
void sub_080C4614(u16 key);
u16 GfxSlot_FindShared(u16 id);
void sub_080C4598(struct Task *t);
void sub_080C4938(u16 n, u16 layer, u16 pal, u16 prio, u16 x, u16 y);
u8 *Item_GetRecord(u16 id);
u8 *Action_GetRecord(u16 id);
s32 Combatant_IsInParty(s32 who);
s32 Combatant_IsDead(s32 who);
s16 Combatant_GetLevel(s32 who);
s32 Combatant_ChangeHpCapped(s32 who, s32 delta);
s32 Combatant_ChangeHp(s32 who, s32 delta);
void Combatant_Damage(s32 who, s32 damage);
void Combatant_ClearStatus(s32 who, u16 mask);
u32 Combatant_SetStatus(s32 who, u16 bits);
s32 Combatant_IsUsed(s32 who);
s32 Battle_GetHp(s32 who);
void sub_080F4190(s32 who);
void sub_080C84A0(void);
void sub_080C8490(s32 pos);
u32 Random_Byte(void);
u32 Moon_GetPhase(void);
struct Task *sub_080B8AE0(u16 color, u16 b);
void m4aSongNumStart(u16 n);
void m4aSongNumStop(u16 n);
void m4aMPlayFadeOut(void *mplay, u16 speed);
void sub_080B710C(u16 a, u16 b, u16 c, u16 d, u16 e, u32 f);
void sub_080D0BA0(void);
void Field_SetState(u16 state);
void sub_080C2D78(s8 a, s8 b);
void Party_FixFormation(void);
u16 Party_DrainHpFromStrongest(u16 who);
void sub_080C4D74(u16 who);
u16 Random_ChanceIn16(u16 chance);
u32 Moon_GetFullness(void);
u32 Party_HasActiveHuman(void);
struct C0c2ViewCell;
struct MapHeader *DungeonMap_GetFloor(u16 map, u16 floor);
u32 SubMap_IsOutsideExclusions(struct MapHeader *m, u16 x, u16 y);
u16 sub_080B4448(const struct C0c2ViewCell *cell);
void View_BuildCells(u16 dir, u32 a);
u32 BattleFlags_Get(void);
void MiniView_SampleSquare(u16 x, u16 y, u16 col, u16 row);
void MiniView_SampleAhead(u32 dir);
void sub_080C55E0(void);
void MiniView_Draw(void);

struct Combatant *Stock_FindByDemonId(u16 demonId);
u16 sub_080C2A84(u32 who);
void Party_Remove(u16 who, u32 release);
s32 Stock_GetCapacity(void);
extern u8 gPartyOrderSave[6];     /* saved party order (Party_SaveOrderHeroOnly) */
extern const u16 gUnknown_081A66A0[];
struct C0c2Bytes4
{
    u8 b[4];
};
extern const u16 gUnknown_081A66B0[][32];     /* by world-map block (sub_080C5D0C) */
extern const struct C0c2Bytes4 gUnknown_081A6AB0[];
extern const struct C0c2Bytes4 gUnknown_081A6C60[];
extern const u8 gUnknown_081A6CD4[][16];
extern const u16 gUnknown_081A6F06[];
struct C0c2Spot
{
    u16 x;
    u16 yd;             /* bits 0-5 y, bits 6-7 facing */
    u16 value;
    u16 pad;
};
extern const struct C0c2Spot gUnknown_081A6F68[];
struct C0c2Rec5C
{
    u32 unk00;
    const void *a[8];       /* 0x04 */
    const void *b[9];       /* 0x24 */
    const void *unk48;      /* 0x48 */
    u32 unk4C;
    const void *unk50;      /* 0x50 */
    const void *unk54;      /* 0x54 */
    u32 unk58;
};
extern const struct C0c2Rec5C gUnknown_08341170[];
extern const u8 gUnknown_0822E194[];
extern u16 gUnk_03000040;
extern u16 gUnk_02000000[];
extern u32 gUnk_0200AB04;
extern u16 gUnk_0300000C, gUnk_03000006, gUnk_03000004;
extern u16 gUnk_0200F7D8[][2];
extern u8 gUnk_0200E8D8[];
extern u32 gUnk_0200F7F0;
extern struct Task gTasks[64];
struct C0c2Pos
{
    u16 x;
    u16 y;
};
struct C0c2Tile
{
    u32 w[8];
};
extern const void *const gUnknown_0834A254[];
extern const void *const gUnknown_0834A23C[];
extern const struct C0c2Pos gUnknown_0834A274[], gUnknown_0834A28C[], gUnknown_0834A2BC[];
extern const struct C0c2Pos gUnknown_0834A2D4[], gUnknown_0834A2A4[];
extern const u8 gUnknown_0800082C[], gUnknown_080005EC[], gUnknown_0834A26C[];
extern const struct C0c2Tile gUnknown_081AF7B8[];      /* 8x8 name glyphs by name byte */
extern const u32 gUnknown_081A81B8[];
struct C0c2FaceRef
{
    u32 tile;           /* word offset into gUnknown_081A81B8 */
    u32 palette;
};
extern const struct C0c2FaceRef gUnknown_0834A2EC[];
void sub_080D2F60(struct Task *t);
void Hud_DrawGauge(u16 slot, u16 kind, u16 x, u16 y, u16 max, u16 cur);
s16 Hud_GetMemberFace(s16 slot);
u32 sub_080C6FB8(u16 slot);
void sub_080C6AD8(u16 slot, u16 layer, u16 prio, u16 x, u16 y);
struct Task *sub_080C6BA8(void);
void sub_080C6E54(void);
void sub_080C6F00(void);
extern const u8 gUnknown_080005DC[];
void sub_080C700C(void);
void sub_080C7234(void);
void sub_080C7430(void);
void sub_080C6FF0(void);
void sub_080C7218(void);
void sub_080C7414(void);
void sub_080C726C(void);
void sub_080C7880(void);
void sub_080C7AFC(void);
void sub_080C71EC(void);
void sub_080C745C(void);
void sub_080C76B4(void);
u32 sub_080C7E90(void);
void sub_080C67C0(u16 *pal, u16 row);
void Hud_DrawMemberPanel(u16 slot, u16 x, u16 y);
extern const u8 gUnknown_081B8270[], gUnknown_081B92B0[], gUnknown_081B8170[];
extern const u16 gUnknown_0834A230[];
extern const u16 gUnknown_0834A224[];
extern const u8 gUnknown_081B7030[];
u32 sub_080C8AF8(u16 map);
void Hud_UploadMoonTiles(void);
void sub_080C8440(void);
u32 Encounter_GetDangerLevel(void);
void sub_080C7EB4(const void *src, void *dst);
void sub_080C6558(void);
void sub_080C65A4(void);
void sub_080C65C8(void);
extern const u8 gUnknown_0822E52C[], gUnknown_0822E174[], gUnknown_0824D1E4[], gUnknown_0824DF94[];
extern const u8 gUnknown_0824E75C[], gUnknown_0824EA9C[], gUnknown_0824EDDC[];
extern const u8 gUnknown_08245B80[], gUnknown_08245E28[], gUnknown_0824696C[];
extern const u8 gUnknown_082483CC[], gUnknown_082473CC[], gUnknown_082472CC[];
extern const u8 gUnknown_081B90B0[], gUnknown_081A7DB8[];
void Tilemap_CopyRectSkipZero(const void *src, void *buf, u32 a2, u32 a3, u32 x, u32 y, u32 w, u32 h);
void Tilemap_FillRect(u16 value, void *map, u16 x, u16 y, u16 w, u16 h);
void sub_080B04BC(void);
void sub_080B2840(u32 a, u32 b, u32 c);
void sub_080B0158(void);
void sub_080C1440(void);
void sub_080C7C94(void);
void sub_080C14FC(void);
void sub_080C153C(void);
void sub_080C5F78(void);
struct C0c2Area
{
    u8 pad00[0xCC];
    u16 originX;        /* 0xCC */
    u16 originY;        /* 0xCE */
};
struct C0c2Area *FieldMap_GetArea(u16 id);
void sub_080C1F50(u16 x, u16 y, u16 *bx, u16 *by);
void CpuSet(const void *src, void *dest, u32 control);
void sub_080C7C60(void);
void Encounter_SetCounter(u16 v);
u16 sub_080C5D58(void);
struct C0c2Rec5C *sub_080C5EF0(u16 id);
void Sound_Play(u16 se);
extern u16 gUnk_030031B4;   /* current song */
extern u16 gUnk_030031EC;   /* previous song */
extern u8 gUnk_0203F2E0[];  /* music player */
extern u16 gHudState[];
extern const u8 gUnknown_081A65F4[];
extern const u8 gUnknown_081A6634[];
void CharTask_Register(struct Task *t);
void CharTask_Unregister(struct Task *t);


/* this region */
void sub_080C2D48(u16 a, u16 b);
void sub_080C2E74(void);
struct C0c2InvEntry *Inventory_FindEntry(u16 id);
u32 Inventory_FindIndex(u16 id);
struct C0c2InvEntry *Inventory_FindFreeEntry(void);
u8 Inventory_GetCount(u16 id);
u32 *sub_080C317C(void);

#endif
