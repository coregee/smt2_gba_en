#ifndef GUARD_STATUS_H
#define GUARD_STATUS_H

#include "global.h"
#include "inventory.h"

/* Field HUD, dungeon floor tables and status screens, 0x080C6FD8-0x080CD3E8. */

/* The field HUD state at 0x0200E7D4 (gHudState): per panel slide state, step and timer. */
struct C0c6Hud
{
    u16 state[8];       /* 0x00: 0 shown, 1 sliding in, 2 sliding out, 3 hidden */
    u16 step[8];        /* 0x10 */
    u16 timer[8];       /* 0x20 */
    u16 unk30;
    u16 unk32;          /* 0x32: danger palette cycle position */
    u16 unk34;
    u16 unk36;
    u16 unk38;          /* 0x38: frames until the next danger palette step */
    u16 pad3A[(0x48 - 0x3A) / 2];
    u16 unk48[6];
    u16 unk54[6];
    u16 altFace[6];     /* 0x60: show the status face (Hud_GetAltFace) */
    u16 pending;        /* 0x6C: tilemap upload queued (sub_080C6764) */
    u16 facesPending;   /* 0x6E */
    u16 blink;          /* 0x70: magnetite counter blink */
    u16 unk72;
};
#define gHud ((struct C0c6Hud *)gHudState)
#define gMapId (*(u16 *)&gUnk_03004614)

void Hud_LoadMemberFace(u16 i);
void sub_080C6764(void);
extern const u8 gUnknown_080005A0[];
extern const void *const gUnknown_0834A214[];
extern const u8 gUnknown_080007FC[], gUnknown_0800080C[], gUnknown_08000A74[], gUnknown_080019D4[];
extern const void *const gUnknown_0834A3CC[];
extern const u16 gUnknown_0834A3DC[];
extern const u8 gUnknown_081B7170[];
extern u16 gUnk_0203A44E;
u32 Magnetite_Get(void);
u16 sub_080B447C(void);
void sub_080C7FD0(u32 v, u16 x, u16 y, u16 layer, u16 pal);
void sub_080C8048(u32 v, u16 x, u16 y, u16 layer);
void sub_080C7664(u16 x, u16 y, u32 v);
void sub_080C7CBC(void);
void sub_080C7DAC(void);
void Hud_RenderGlyphTiles(u8 *dst, const u8 *str);
u16 Hud_RenderSpriteText(const u8 *str);
extern const struct C0c2Tile gUnknown_081AD898[];
extern const u16 gUnknown_0834A5DC[];
extern const u8 gUnknown_081BBA70[];
extern const u32 gUnknown_0834A634[];
extern const void *const gUnknown_0834A674[];
extern const void *const gUnknown_0834A69C[];
u8 *NumberToDigits(u32 value);
u16 Color_ApplyEffect(u16 color);

extern const u8 gUnknown_0834A6C4[], gUnknown_0834A6D4[], gUnknown_0834A6E4[];
extern const u8 gUnknown_081AD5B8[];
extern const u8 gUnknown_081B17B8[];
extern const u32 gUnknown_0834A6EC[], gUnknown_0834A70C[], gUnknown_0834A730[];
extern u8 gUnk_0200E998[], gUnk_0200F1D8[], gUnk_0200F258[];
void Canvas_BlitOr(const u8 *src, u8 *dst, u16 srcX, u16 srcY, u16 dstX, u16 dstY, u16 w, u16 h);
u32 *sub_080C8148(u32 off, u32 *dst);
void Hud_DrawGaugeValue(u32 cur, u32 alt, u8 *canvas);
void sub_080C8068(u16 layer, u16 pal, u16 prio, u16 tile, u16 x, u16 y);
void sub_080C8104(u16 layer, u16 pal, u16 prio, u16 tile, u16 x, u16 y);


/* Data of the cursor tasks (sub_080C8858, sub_080C8A78). */
struct C0c6CursorData
{
    u16 pos;            /* 0x00: index into gUnknown_0834A750 */
    u16 kind;           /* 0x02 */
    u16 step;           /* 0x04 */
    u16 locked;         /* 0x06 */
    u8 limit;           /* 0x08 */
    u8 count;           /* 0x09 */
};

struct C0c6MapInfo
{
    u16 unk0;
    u16 unk2;
    u32 unk4;
    u32 unk8;
    u32 unkC;
};
/* gDungeonMaps (0x084ED59C): 0x18 bytes per map. */
struct C0c6DungeonMap
{
    u8 *floors;         /* 0x268 bytes per floor */
    u32 unk4;
    struct C0c6MapInfo info;    /* 0x08 */
};
extern const struct C0c6DungeonMap gDungeonMaps[];
extern vu16 gKeysNew;
extern u32 gUnk_030037F0;
s32 sub_080C35E4(s32 who);
extern const u16 gUnknown_081B70D0[][16];
extern const u8 gUnknown_081B3F10[];
extern const struct C0c2Pos gUnknown_0834A750[];
extern const u8 gUnknown_080013DC[], gUnknown_080013F4[], gUnknown_0800140C[], gUnknown_08001424[];
extern const u8 gUnknown_0800143C[], gUnknown_08001454[];
extern const u8 gUnknown_0834A768[], gUnknown_0834A7C4[];
void sub_080C8464(s16 slot, u16 alt);
s16 Hud_GetStatusFace(s16 slot);
s16 Hud_GetAltFace(s16 slot);
void sub_080C8718(struct Task *t);
void sub_080C876C(void);
struct Task *sub_080C8858(u16 pos, u16 kind, u8 limit);
struct Task *sub_080C8A78(u16 locked, u16 kind, u16 pos);

u16 *Location_GetNameCellFromCoords(u16 map, u16 floor, u16 x, u16 y);
void FontSprite_DrawGlyph(u16 glyph, u32 a1, u32 a2, u16 x, u16 y);
extern const u16 *gUnk_03004630;
extern const u16 *gUnk_03004510;
extern struct PalFade gUnk_0203A3E8[];
extern u16 gUnk_030045B4;
void PalFade_Setup(struct PalFade *fade, u16 start, u16 count, u16 delay);
void PalFade_Update(struct PalFade *fade);
void Flag_Set(u32 flag);
typedef void (*VoidFunc)(void);
extern VoidFunc gIntrTable[14];
void IntrDummy(void);
void *VBlankTask_AddCountedAlways(VoidFunc func, u16 count);
struct C0c6Pal16
{
    u16 c[16];
};
extern const u16 gUnknown_083D8F78[];
/* gUnknown_084EDE54: field events by map square, ended by x 0xFFFF. */
struct C0c6EventSpot
{
    u16 x;
    u16 yd;             /* bits 0-5 y, bits 6-7 facing */
    const void *script;
    u16 id;
    u16 pad0A;
};
extern const struct C0c6EventSpot gUnknown_084EDE54[];
void sub_080C8C78(void);
void sub_080C8CD4(u32 i);
void sub_080C8E10(void);
void sub_080C8E30(void);
void sub_080C8E64(void);

/* gMenuState (0x0203A454) as used by the status screens here. */
struct C0c6Status
{
    u16 mode;           /* 0x00 */
    u16 sel;            /* 0x02: index into gStatusList */
    u16 page;           /* 0x04: status page 0-5 */
    u16 unk06;
    u16 unk08;
    u16 unk0A;
    u16 unk0C;
    u16 unk0E;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 hofs;           /* 0x1A: BG1/BG2 scroll from line 0x80 */
    u16 unk1C;
    u16 unk1E;
    u16 unk20;
    u16 unk22;
    u16 count;          /* 0x24: entries in gStatusList */
    u16 count2;         /* 0x26 */
    u16 unk28;
    u16 unk2A;
    u16 unk2C;
    u16 unk2E;
    u16 unk30;
    u16 unk32;
    u16 unk34;
    u16 unk36;
    struct C0c6Fade *fade;      /* 0x38: sub_080B6B58 */
    struct Task *sprite;        /* 0x3C */
    void *window40;
    void *window44;
    void *window48;
    u8 pad4C[0x54 - 0x4C];
    struct Combatant demon;     /* 0x54: demon built for display */
    struct Combatant saved;     /* 0xD4 */
    struct Combatant preview;   /* 0x154 */
};
extern struct C0c6Status gMenuState;
struct C0c6Fade
{
    u16 unk0;
    u16 unk2;
    u32 unk4;
    u32 unk8;
    s32 unkC;           /* -1 when done */
};
struct C0c6Fade *sub_080B6B58(void (*func)(void), u32 a);
void sub_0812CC70(u32 a);
void sub_08128B84(u32 a);
void sub_080EA178(void);
extern u16 gUnk_0203B854[];
extern const u8 gUnknown_081B5870[], gUnknown_081B4F10[], gUnknown_081B4FD0[], gUnknown_081B93B0[];
extern u8 gUnk_0200FC74[], gUnk_0200FFD4[];
u32 sub_080C964C(u16 which);
void sub_080C9994(void);
void sub_080C98E0(void);
extern u16 gStatusList[];
extern u8 gUnk_0200F874[];
extern const u16 gUnknown_084EEAE4[], gUnknown_084EEF28[], gUnknown_084EF368[], gUnknown_084EF7B0[];
void Combatant_InitDemon(struct Combatant *c, s32 who, s32 demonId);
u16 Fusion_GetDemonByIndex(u16 id);
void Item_GetAttribute(s32 id, s32 field, void *out);
void Font_ResetGlyphSpriteCache(u32 baseTile);
u16 sub_0812ACCC(u16 i);
u16 sub_080C9278(u16 i);
u16 sub_080C9290(u16 i);
u32 sub_080C92AC(u16 id);
struct Combatant *Status_GetCombatant(u16 i);
u32 sub_080C9388(u16 i);
u32 sub_080C93B4(u16 i);
const u16 *sub_080C9210(u16 kind);
void sub_080C93E0(void);
void sub_080C9414(void);

u8 *Demon_GetRecord(u16 id);
const u16 *Race_GetName(u16 race);
void Font_DrawGlyphTinted(u16 glyph, void *dst, u16 x, u16 y, u32 tint);
void Text_DrawStringTinted(const void *str, void *dst, u32 x, u32 y, u32 tint, u32 lineH);
void Combatant_DecodeName(struct Combatant *c, u16 *dst);
void DigitFont_DrawAscii(const u8 *str, u16 x, u16 y, u16 tint);
void DigitFont_DrawNumber(s32 value, u16 x, u16 y, u16 tint);
u32 sub_080C99B8(struct Combatant *c);
extern const u8 gUnknown_084EFAD4[], gUnknown_084EFAD8[];

void sub_080CB0B8(u32 a, struct Task *t);
void sub_080CB71C(u32 a, struct Task *t);
void sub_080CB7A0(u32 a, struct Task *t);
void sub_080CB8C8(u32 a, struct Task *t);
void sub_080CB928(u32 a, struct Task *t);
void Status_DrawDropItem(u32 a, struct Task *t);
void sub_080CBC8C(u32 a, struct Task *t);
void sub_080CC630(u32 a, struct Task *t);
void sub_080CC694(u32 a, struct Task *t);
void sub_080CC844(u32 a, struct Task *t);
void sub_080CCA10(u32 a, struct Task *t);
void sub_080CCAB4(u32 a, struct Task *t);
void sub_080CCD5C(u32 a, struct Task *t);
void sub_080C3E5C(struct Task *t, u16 a, u16 b);
void Canvas_FillRect(u8 color, u8 *dst, u16 x, u16 y, u16 w, u16 h);
void *TextWindow_CreateOpenWithFrame(u32 x, u32 y, u32 w, u32 h, u32 a4, const void *frame);
extern u16 gUnk_0203B454[];
extern const u8 gUnknown_084EFA9C[], gUnknown_084EFAAE[], gUnknown_084EFAC0[];
void sub_080C97F0(struct Task *t, u32 frame);
void sub_080C9854(struct Task *t, u32 frame);
void sub_080C9BCC(struct Task *t);
void sub_080C9D00(struct Task *t);
void sub_080C9D84(struct Task *t);
void Status_DrawDemonInfo(struct Task *t);

extern u16 gRepeatedKeys;
extern u16 gSavedMenuCursor[];
s32 sub_080C2554(s32 id);
void sub_080C4AB0(u32 a0, u32 a1, u32 x, u32 y);
void sub_080C49EC(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
void sub_080C9CD8(struct Task *t);
void sub_080CA684(void);
void sub_080CA694(s16 dir, u32 count);
u16 Inventory_ListRange(u16 lo, u16 hi);

void DemonObj_End(struct Task *t, u32 a);
void TextWindow_Close(void *window, u32 a);
void sub_080C4A4C(u32 a0, u32 a1, u32 x, u32 y);
extern u16 gUnk_03000008;
void Text_DrawString(const void *str, void *dst, u32 x, u32 y, u32 lineH);
extern const u8 gUnknown_084EFB44[];
extern const u16 gUnknown_084F00C8[];

void SmallFont_DrawAscii(const u8 *str, u16 x, u16 y, u16 tint);
void Status_DrawEquipName(u16 id, u16 x, u16 y, u16 tint);
void Status_DrawActionName(u16 id, u16 x, u16 y, u16 tint);
void Status_DrawSkillName(u16 id, u16 x, u16 y);
void sub_080CD260(u16 id, u16 x, u16 y, u16 y2);
void Status_DrawDemonDescription(u16 id, u16 x, u16 y);
u16 Combatant_GetEquipSlot(struct Combatant *c, u16 slot);
s32 sub_080CDB74(s16 who, u8 item);
u8 Inventory_GetCount(u16 id);
struct Combatant *Stock_FindByDemonId(u16 demonId);
u32 sub_0812C4E0(u16 id, u16 demon);
void Font_DrawGlyph(u16 glyph, void *dst, u16 x, u16 y);
extern u8 gUnk_0203B860[];
extern const u8 gUnknown_084F019C[], gUnknown_084F01A0[];
extern const u16 gUnknown_084F01A2[];

void Combatant_SetEquip(u8 who, u16 slot, u16 item);
void SmallFont_DrawNumber(s32 value, u16 x, u16 y, u16 tint);
void sub_080CC4B4(struct Combatant *old);
extern const u8 gUnknown_084F00DC[];

extern const u8 gUnknown_084F01B8[], gUnknown_084F01C0[], gUnknown_084F01C8[], gUnknown_084F01D0[];
extern const u8 gUnknown_084F01D8[], gUnknown_084F01E4[];
void sub_080CC7D4(void);

extern const u16 gUnknown_084F01F4[], gUnknown_084F0254[];
void SmallFont_DrawGlyphTinted(u16 index, u8 *canvas, u16 x, u16 y, u8 tint);
void DigitFont_DrawGlyphTinted(u16 index, u8 *canvas, u16 x, u16 y, u8 tint);

u8 *Equipment_GetRecord36_MidRange(u16 id);
u8 *sub_080BF5C0(u16 id);
s32 sub_0815B864(u32 id);
extern const u8 gUnknown_084F02B4[], gUnknown_084F02B8[], gUnknown_084F02BC[], gUnknown_084F02C0[];
extern const u8 gUnknown_084F02C4[], gUnknown_084F02C8[], gUnknown_084F00E0[], gUnknown_084F02DC[];
extern const u16 gUnknown_084F02CA[];

void sub_080CD330(u16 item, u16 x, u16 y, u16 tint);
void sub_080CD38C(u16 item, u16 x, u16 y, u16 tint);
void sub_080CD3E8(u16 item, u16 x, u16 y, u16 tint);
void sub_080CD45C(u16 item, u16 x, u16 y);
void sub_080CD50C(u16 item, u16 x, u16 y);
void sub_080CD668(u16 item, u16 x, u16 y, u16 tint);
void sub_080CD6C4(u16 item, u16 x, u16 y, u16 tint);
void sub_080CD720(u16 item, u16 x, u16 y);
void sub_080CD87C(u16 item, u16 x, u16 y);
extern const u8 gUnknown_084F01EC[];

#endif
