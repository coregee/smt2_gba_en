#ifndef GUARD_FUSION_H
#define GUARD_FUSION_H

/* Declarations for src/fusionlist_b.c, compendium_a.c, fusionroom_*.c, objaffine_a.c, fusioncalc_*.c (Cathedral of Shadows / fusion screens, 0x081551F8-0x0815BB90).
   Copied from the shared headers where needed so these files do not depend on them. */

#include "global.h"

typedef void (*VoidFunc)(void);

#define DmaSet3(src, dest, control)              \
{                                                \
    vu32 *dmaRegs = (vu32 *)(REG_BASE + 0xD4);   \
    dmaRegs[0] = (vu32)(src);                    \
    dmaRegs[1] = (vu32)(dest);                   \
    dmaRegs[2] = (vu32)(control);                \
    dmaRegs[2];                                  \
}

#define DmaFill32_3(value, dest, control)        \
{                                                \
    vu32 tmp = (vu32)(value);                    \
    DmaSet3(&tmp, dest, control);                \
}

#define DmaFill16_3(value, dest, control)        \
{                                                \
    vu16 tmp = (vu16)(value);                    \
    DmaSet3(&tmp, dest, control);                \
}

struct CombatantStats
{
    u8 v[6];
    u8 pad[2];
};

/* One party member / stock demon / enemy: 0x80 bytes. */
struct Combatant
{
    u8 name[8];
    u32 unk8;
    u8 id;              /* 0x0C */
    u8 level;           /* 0x0D */
    u16 unkE;           /* 0x0E: nonzero = slot used */
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
    struct CombatantStats bonus;    /* 0x30 */
    struct CombatantStats extra;    /* 0x38 */
    struct CombatantStats total;    /* 0x40 */
    s16 derived[8];     /* 0x48 */
    u16 unk58;
    u8 pad5A[3];
    u8 skills[32];      /* 0x5D */
    u8 pad7D[3];
};

/* Demon records (Demon_GetRecord). */
struct DemonRecord
{
    s8 race;
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

/* gGameState (0x030046C0): only the fields used here. */
struct GameState
{
    struct Combatant members[20];   /* 0x0000: 0..3 humans, 4..15 demon stock */
    u8 padA00[0xAD8 - 0xA00];
    u32 money;                      /* 0xAD8 */
    u32 magnetite;                  /* 0xADC */
    u8 padAE0[0x1074 - 0xAE0];
    u8 itemCounts[0x5E];            /* 0x1074: items 0x54-0xB1 */
};

extern struct GameState gGameState;

struct FadeTask
{
    u8 pad0[0xC];
    s32 state;      /* 0x0C: -1 when done */
};

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
    u16 unk1E;
    void (*onFrame)(struct Task *);
    union
    {
        u32 w[0x10];
        u16 h[0x20];
        u8 raw[0x40];
    } data;             /* 0x24 */
};

/* Task data of the material preview tasks (script 0x087E2E3C). */
struct MaterialTaskData
{
    u16 id;             /* 0x24: demon id */
    u16 slot;           /* 0x26 */
    void *win;          /* 0x28 */
    struct Task *obj;   /* 0x2C: demon sprite */
};

#define MATERIAL_DATA(task) ((struct MaterialTaskData *)(task)->data.raw)

struct CharGfxRecord
{
    u32 unk00;
    const void *gfx[2];     /* 0x04 */
};

/* Character object data (task data of a field character). */
struct CharObj
{
    u16 unk00;
    u16 slot;               /* 0x02 */
    u16 shown;              /* 0x04 */
    u16 id;                 /* 0x06: index into gCharGfxRecords */
};

/* gMenuState (0x0203A454) as the Cathedral of Shadows uses it. */
struct FusionState
{
    u16 mode;                       /* 0x000: 1..5 */
    u16 unk2;                       /* 0x002 */
    u16 cursor;                     /* 0x004: row on screen */
    u16 top;                        /* 0x006: first visible row */
    u16 sel;                        /* 0x008: material being chosen */
    u16 unkA;                       /* 0x00A */
    struct FadeTask *fade;          /* 0x00C */
    void *win10;                    /* 0x010 */
    void *win14;                    /* 0x014 */
    void *win18;                    /* 0x018 */
    struct Combatant *members[12];  /* 0x01C: the listed demons */
    struct Combatant *picks[3];     /* 0x04C */
    u8 pad058[4];
    struct Combatant results[12];   /* 0x05C */
    u16 unk65C;                     /* 0x65C: demon id */
    u16 count;                      /* 0x65E */
    u16 unk660;                     /* 0x660 */
    u8 pad662[2];
    u8 unk664;                      /* 0x664: list page (race / ...) */
    u8 unk665;                      /* 0x665: row on the page */
    u8 unk666;                      /* 0x666: row in the demon list */
    u8 pad667[2];
    u8 unk669;                      /* 0x669: first page row */
    u8 unk66A;                      /* 0x66A: first demon list row */
    u8 pad66B;
    u16 pairs[12][2];               /* 0x66C: demon id, random byte */
};

/* gMenuState as the fusion room (Cathedral of Shadows animation) uses it. */
struct FusionRoom
{
    u16 unk0;                       /* 0x00 */
    u8 pad02[4];
    u16 unk6;                       /* 0x06: dissolve step */
    const void *anim;               /* 0x08: room animation frames */
    u32 unkC;                       /* 0x0C */
    struct FadeTask *fade;          /* 0x10 */
    struct Task *savedTask;         /* 0x14: gCharTasks[0] while in the room */
    u16 savedSlot[2];               /* 0x18: gGfxSlots[0] */
    void *palFade;                  /* 0x1C */
    struct Task *objs[4];           /* 0x20: demon sprites of the materials / result */
    u16 unk30;                      /* 0x30 */
    u16 unk32;                      /* 0x32: palette line */
    void *win34;                    /* 0x34 */
    u8 pad38[0x78 - 0x38];
    u16 unk78;                      /* 0x78: capsule light toggle */
    u16 effectStep;                 /* 0x7A */
    void (*savedOnFrame)(struct Task *);  /* 0x7C */
    u16 unk80;                      /* 0x80 */
    u16 unk82;                      /* 0x82: result before the override */
    u16 effectTimer;                /* 0x84 */
};

/* Fusion calculation block at 0x0203B868. */
struct FusionCalc
{
    u8 cand[3];         /* 0x00: candidate results (sub_081594B4) */
    u8 pad03[0xD];
    u8 candLv[3];       /* 0x10 */
    u8 pad13[0x84 - 0x13];
    u16 save[3];        /* 0x84 */
    u16 orig[3];        /* 0x8A: the materials as chosen */
    u16 ids[3];         /* 0x90: the materials, sorted */
    u8 race[3];         /* 0x96 */
    u8 align[3];        /* 0x99 */
    u8 level[3];        /* 0x9C */
    u8 pad9F;
    u16 result;         /* 0xA0 */
    u8 resRace;         /* 0xA2 */
    s8 unkA3;           /* 0xA3 */
    u8 unkA4;           /* 0xA4 */
    u8 unkA5;           /* 0xA5 */
    u8 unkA6;           /* 0xA6: result flags */
    u8 padA7;
    u16 unkA8;          /* 0xA8 */
    u8 pad00AA[0x292 - 0xAA];
    u16 unk292;         /* 0x292 */
};

extern struct FusionCalc gUnk_0203B868;
extern const u8 gUnknown_087F1AD3[];   /* special two-way fusions: a, b, result; 0xFF ends */
extern const u8 gUnknown_087F1AF2[];
extern const u8 gUnknown_087F15E0[], gUnknown_087F15A0[], gUnknown_087F160B[], gUnknown_087F1611[], gUnknown_087F16BD[];
extern u32 gUnk_03006A38;
extern const u8 gUnknown_087F1514[];   /* first demon id of each race */
extern const u8 gUnknown_087F1961[];   /* special three-way fusions: a, b, c, result */
extern struct Task *gCharTasks[6];
extern u16 gGfxSlots[8][2];
extern const u32 gFusionRoomAnim[], gUnknown_087F01DC[];
extern const void *const gFusionRoomTiles[];
extern const u8 gUnknown_087EF03C[], gUnknown_087EF5A0[];
extern u16 gUnk_03000040, gUnk_03000042, gUnk_03000044;
extern const u8 gUnknown_087E5D48[], gUnknown_087EFB04[], gUnknown_087EFCD8[];
extern const u16 gUnknown_087EFF4C[], gUnknown_087EFFCC[], gUnknown_087EFFAC[];
extern const u32 *const gUnknown_087F02B8[];   /* 4 dissolve masks, 8 words (one tile row pattern) */
extern const u32 gUnknown_087F0F94[];
extern const u16 *const gUnknown_087F02C8[];
extern const u16 gUnknown_0815BB90[], gUnknown_0815BF92[];

struct FusionEffectSet
{
    const void *parts[3];
    const u16 *pal;
};

/* Fusion effect animation step: sprite and duration; NULL sprite ends. */
struct EffectFrame
{
    const void *sprite;
    u32 duration;
};

extern const struct FusionEffectSet gFusionEffectSets[];
extern const struct EffectFrame gUnknown_087F09E4[], gUnknown_087F0A9C[], gUnknown_087F0B6C[], gUnknown_087F0994[];
extern u8 gBgPictureBuffer[];
extern u8 gUnk_02008000[];
extern const void *const gFusionMistFrames[];
extern const u16 gUnknown_087F012C[];
extern const u8 gUnknown_08002134[];
extern u32 gMsgWindow;

/* OAM attributes 0-2 as kept in the OBJ buffer (6 bytes, no affine word). */
struct OamAttrs
{
    u16 y:8;
    u16 flags:6;
    u16 shape:2;
    u16 x:9;
    u16 flags1:5;
    u16 size:2;
    u16 attr2;
};

struct Oam6
{
    u16 attr[3];
};

extern u16 gUnk_03003800;                   /* OBJ count */
extern u16 gUnk_03003802[];                 /* OBJ attributes, 3 halfwords each */
extern s16 gUnk_03006A30[4];                /* affine matrix */
extern const u16 gUnknown_087F1494[4][4][2];   /* OBJ width, height by shape and size */
extern const u32 gUnknown_087F0308[], gUnknown_087F106C[], gUnknown_087F06D8[];

extern u16 gMenuState[];
#define sFusion (*(struct FusionState *)gMenuState)
#define sRoom (*(struct FusionRoom *)gMenuState)

extern struct Combatant *gUnk_0203A470[];  /* sFusion.members */
extern struct Combatant *gUnk_0203A4A0[];  /* sFusion.picks */
extern u16 gUnk_0203B854[];   /* chosen materials; [3] = result */
extern u8 gUnk_0203B860[];    /* result skills */
extern u8 gUnk_0203B918[];
extern struct FusionState gUnk_0203AC54;   /* copy of sFusion */
extern u16 gStatusList[];
extern u32 gUnk_030068E0;
extern u32 gUnk_03003BB4;
extern struct Combatant gUnk_030048C0[];
extern vu16 gKeysNew;
extern u16 gRepeatedKeys;
extern u32 gFrameCounter;
extern u32 gYesNoResult;
extern u8 gDigits[8];
extern u16 gPaletteTarget[0x200];
extern u16 gPaletteBuffer[0x200];
extern u8 gUnk_0200F874[];
extern u8 gUnk_02011874[];
extern u8 gUnk_02016874[];
extern s8 gUnk_030050E0[];

extern const void *const gUnknown_0834A23C[];
extern const u8 gUnknown_087E1C68[];
extern const u16 gUnknown_0815BE50[], gUnknown_0815BE68[], gUnknown_0815BE7E[], gUnknown_0815BE92[],
    gUnknown_0815BEA6[], gUnknown_0815BEBE[];
extern const u8 gUnknown_081B4F10[];
extern const u16 gUnknown_081B6E50[];
extern const u8 gUnknown_080018C0[], gUnknown_080018D8[];
extern const u32 gUnknown_087E24CC[], gUnknown_087E3360[], gUnknown_087E1C80[], gUnknown_087E2974[],
    gUnknown_087E35F4[], gUnknown_087E2094[];
extern const u8 gUnknown_087E248C[];   /* [16][4]: which fusion modes offer each item demon */
extern const u32 gUnknown_087E2E3C[], gUnknown_084F1368[];
extern const u8 gUnknown_081B93B0[];
extern const u8 gUnknown_087E3250[], gUnknown_087E3254[], gUnknown_087E325C[], gUnknown_087E3264[],
    gUnknown_087E326C[], gUnknown_087E3270[], gUnknown_087E3278[];
extern u8 gUnk_02000000[];
extern u8 gUnk_02001000[];
extern u8 gUnk_02005800[];
extern const u16 gUnknown_087E2E84[], gUnknown_087E3044[], gUnknown_08770A24[], gUnknown_081B8170[];
extern const u8 gUnknown_08002164[];
extern const u16 gUnknown_087E327E[], gUnknown_087E3288[], gUnknown_087E3292[];
extern const u8 gUnknown_08002198[], gUnknown_080021E4[], gUnknown_080007FC[];
extern const u16 gUnknown_087E3204[];
extern const u16 *const gUnknown_087E32A0[], *const gUnknown_087E3340[];
/* Compendium order of the alignment page: {demon id, alignment}, 0xFFFF ends. */
struct DemonAlign
{
    u16 id;
    u16 align;
};
extern const struct DemonAlign gUnknown_08585C34[];
extern const u8 gUnknown_087E1C44[], gUnknown_087E1C70[], gUnknown_087E1C74[], gUnknown_087E1C78[], gUnknown_087E1C7C[];

void *memset(void *dst, int c, unsigned long n);
void CpuSet(const void *src, void *dest, u32 control);
void *Window_CreateOpen(u16 x, u16 y, u16 w, u16 h, u16 bg);
void Window_Close(void *window, u32 arg1);
u8 *NumberToDigits(u32 n);
s32 Combatant_GetAlignment(s32 who);
s32 Combatant_IsUsed(s32 id);
s32 Combatant_IsDead(s32 id);
void SmallFont_DrawAsciiTinted(const u8 *str, u8 *canvas, u16 x, u16 y, u8 tint, u16 advance);
void Text_DrawSpriteString(const u16 *str, u16 a1, u16 a2, u16 x, u16 y, u16 advance);
void Font_ResetGlyphSpriteCache(u32 baseTile);
void sub_080C49EC(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
void sub_080C4A4C(u32 a0, u32 a1, u32 x, u32 y);
void sub_080C4AB0(u32 a0, u32 a1, u32 x, u32 y);
void Sprite_Draw(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
void Sprite_DrawSingle(const void *tmpl, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
void Palette_MarkDirty(void);
void Palette_CopyWithEffect(u32 a0, const void *src, void *dst, u32 a3, u32 a4);
void Canvas_FillRect(u8 color, u8 *dst, u16 x, u16 y, u16 w, u16 h);
void Sound_Play(u32 se);

void ObjAffineSet(void *src, void *dest, s32 count, s32 offset);
u32 Window_Create(u32 x, u32 y, u32 w, u32 h, u32 bg);
void HuffUnComp(const void *src, void *dest);
u8 *Item_GetRecord(u16 id);
u16 sub_0815B958(u16 id);
struct Combatant *Stock_FindDemon(u16 demonId);
void Inventory_RemoveItem(u16 id);
void Stock_AddDemon(u16 id);
void Money_Add(s32 v);
u32 Fusion_GetDemonByIndex(u16 id);
void Party_Remove(u16 who, u32 release);
void Inventory_AddItem(u16 id);
struct Combatant *Stock_FindByDemonId(u16 demonId);
void sub_080E5DA0(void);
void Fusion_ApplyResult(void);
void Party_FixFormation(void);
struct CharGfxRecord *Char_GetRecord(u16 id);
void Char_LoadGfxHalf(struct CharObj *obj, const void *src, u32 a2, u32 half, u32 a4);
void sub_080CE580(struct Task *t, u32 restore);
void *PalFade_FadeRangeWithDuration(u16 start, u16 count, u16 delay, u16 duration);
void sub_080C3E64(struct Task *t);
void sub_080C3EBC(void);
void sub_080C3EE0(void);
void sub_080C3F04(void);

void sub_080C1384(void);
void *PalFade_FadeRangeInFromBlackTagged(u16 start, u16 count, u16 delay, u16 tag);
u16 PalFade_IsActive(void *fade);
void sub_080C3C68(struct Task *t);
void Field_SetState(u16 state);
struct FadeTask *sub_080B6BB0(void (*func)(void));
void LZ77UnCompWram(const void *src, void *dest);
s32 sub_080C10A8(s32 id);
struct Combatant *Party_GetMember(u16 id);
u32 Money_Get(void);
u32 Fusion_IsRandomResult(void);
u32 Fusion_CalcTwo(void);
u32 Fusion_CalcThree(void);
void Fusion_SortMaterials(void);
u16 Fusion_RollAccident(void);
void Music_Play(u32 a);
u32 sub_080C28CC(u32 id);
const u16 *sub_080C9210(u16 kind);
void FontSprite_DrawGlyph(u16 glyph, u32 a1, u32 a2, u16 x, u16 y);
void FontSprite_DrawGlyphTinted(u16 glyph, u16 a1, u16 a2, u16 x, u16 y, u16 palette);
void sub_080C7664(u16 x, u16 y, u32 v);
u32 Magnetite_Get(void);
void sub_080C7FD0(u32 v, u16 x, u16 y, u16 layer, u16 pal);
void Tilemap_CopyRectSkipZero(const void *src, void *buf, u32 a2, u32 a3, u32 x, u32 y, u32 w, u32 h);
void Tilemap_CopyRectStride(const void *src, void *buf, u32 a2, u32 a3, u32 x, u32 y, u32 w, u32 h, u32 srcWidth);
struct FadeTask *sub_080B6B58(void (*func)(void), u32 a);
void sub_0815468C(void);
void SmallFont_DrawAscii(const u8 *str, u32 x, u32 y, u32 a3);
void SmallFont_DrawNumber(u32 num, u32 x, u32 y, u32 a3);
void sub_080C1440(void);
struct Task *DemonObj_Create(u16 a, u16 id, u16 x, u16 y, u16 e, u16 f);
void sub_080C3E40(struct Task *t, u16 v);
void DemonObj_End(struct Task *t, u32 a);
struct Task *Task_Create(const void *script, u32 parent);
u8 Inventory_GetCount(u16 id);
void Combatant_InitDemon(struct Combatant *c, s32 who, s32 demonId);
u16 Fusion_BuildList(void);
void *PalFade_FadeToBlack(u16 delay);
u32 sub_080CED00(void);
void sub_080C98A0(void);
u32 Fusion_CheckResult(void);
u16 sub_081572AC(void);
u32 Random_Byte(void);
void VBlankTask_AddCounted(void (*func)(void), u32 count);
struct DemonRecord *Demon_GetRecord(u16 id);
const u16 *Race_GetName(u16 race);
void DigitFont_DrawStringTinted(const u8 *str, u8 *canvas, u16 x, u16 y, u8 tint, u16 advance);
void Font_DrawGlyphTinted(u16 code, u8 *canvas, u16 x, u16 y, u8 tint);

/* fusionlist_a.c */
void Fusion_ClearList(void);
u16 Fusion_CountList(void);
void sub_08153F6C(u16 i);
u32 sub_081544AC(u16 id);
void sub_08153FC8(u16 glyph, u8 *dst, u16 x, u16 y, u8 tint);
void Fusion_DrawListHeader(void);
void Fusion_DrawList(u16 top);

/* fusion screens */
void sub_081551F8(void);
void sub_081552E8(struct Task *task, u32 arg1, const u16 *str);
void sub_08155374(void);
void sub_0815550C(struct Task *task);
u16 sub_08155518(void);
void Fusion_BuildMaterialList(void);
void sub_0815565C(u16 n);
void sub_081556C4(void);
void sub_081556F8(void);
void sub_0815571C(struct Task *task, u32 sel);
void Fusion_DrawMaterialHeader(u32 unused, u32 slot);
void sub_08155BB8(u32 a0, u32 slot, u32 step);
void sub_08155C40(struct Task *task);
void sub_08155C80(void);
void sub_08155DF4(void);
void sub_08155E24(struct Task *task);
void sub_08155EC0(u32 a0);
void sub_08155EF4(void);
void sub_08155F44(void);
void sub_08155F74(struct Task *task);
struct Task *Fusion_StartScreen(u16 mode);
struct Task *Fusion_ResumeScreen(void);
u16 sub_08156088(u32 a0, u32 a1, u32 a2);
void sub_08156134(void);
void sub_08156170(struct Task *task);
void sub_081561D0(struct Task *task);
void sub_08156218(struct Task *task);
void sub_0815627C(struct Task *task);
void sub_081562D0(struct Task *task);
void sub_081562EC(u16 slot, u16 id, struct Task *parent);
void sub_0815631C(struct Task *task);
void sub_0815637C(void);
void sub_081563B8(void);
void sub_081563F4(struct Task *task);
void sub_0815656C(void);
void sub_0815659C(void);
void sub_081565B4(struct Task *task, u32 step);
void sub_081566C4(void);
u8 sub_081566E0(void);
u16 sub_081566F4(void);
void sub_08156724(struct Task *task);
void sub_081567A4(struct Task *task);
void sub_08156924(struct Task *task);
void sub_08156AB0(struct Task *task);
void List_HandleScrollInput(struct Task *task, u16 count, u16 rows, u8 *cursor, u8 *top, u32 mode);
void sub_08156DB4(struct Task *task);
void sub_08156E2C(struct Task *task);
void sub_08156E64(void);
void sub_08156E98(struct Task *task);
void Compendium_BuildList(struct Task *task, u32 page, u32 row, u32 a3);
u32 Compendium_CountList(void);
u16 sub_08157238(u16 mode);
void sub_0815739C(void);
void sub_08157434(void);
void sub_08157440(void);
void sub_0815745C(struct Task *task);
void sub_08157480(void);
void Fusion_LoadRoomTiles(u32 unused, u32 k);
void sub_081574D0(void);
void sub_08157534(void);
void sub_081575D8(void);
void sub_0815764C(void);
void sub_08157698(void);
void sub_081576BC(struct Task *task);
void sub_081576E4(u32 a0, u32 slot);
void sub_081577A0(u32 a0, u32 slot);
void sub_081577E8(u32 a0, u32 kind, u32 line);
void sub_08157868(u32 a0, u32 slot);
void FusionRoom_DissolveSprite(struct Task *task, u32 slot);
void sub_0815795C(struct Task *parent, u32 line);
void sub_08157980(void);
const u16 *sub_081579A4(u16 id);
void FusionRoom_DrawResultMessage(struct Task *task);
void sub_08157B78(struct Task *task);
void sub_08157BB8(u32 a0, u32 k);
u32 sub_08157C2C(void);
void Fusion_Commit(void);
void sub_08157E8C(void);
u32 sub_08157EA4(void);
struct Task *sub_08157EB0(u16 kind, u32 a1, struct FadeTask *fade);
void sub_08157F5C(void);
void sub_08157F94(u32 a0, u32 frame);
u32 sub_08158030(void);
void sub_081580A8(void);
void Fusion_LoadEffectPart(u32 a0, u32 part);
const struct EffectFrame *sub_0815814C(void);
void sub_081581C0(void);
void sub_08158220(struct Task *task);
void sub_08158268(u32 a0);
void sub_081582BC(void);
void Fusion_LoadMistFrame(void);
void sub_0815834C(void);
void sub_081583A0(u32 a0, u32 k);
void sub_081583F4(const u16 **args);
void sub_0815851C(const u16 **args);
u32 sub_08158A34(void);
u32 Fusion_CalcPair(void);
u32 Fusion_FindSpecialPair(void);
u32 Fusion_FindSpecialTriple(void);
u32 sub_08158CA4(void);
u32 sub_08158CBC(void);
u32 sub_08158D20(void);
u32 Fusion_SetNoResult(void);
u32 sub_08158ED0(void);
u32 sub_08158F48(u32 race);
u32 sub_08159098(void);
void Fusion_RankDown(u16 id, u16 n);
void Fusion_RankUp(u16 id, u16 n);
s16 sub_08159568(u16 level);
void sub_08159604(u32 a, u32 b);

s16 sub_081594B4(u16 level);
u32 sub_08159144(void);
u32 sub_0815993C(void);
u32 sub_0815999C(void);
u32 Fusion_ThreeTwoRace8(void);
u32 Fusion_ThreeRace8(void);
u32 Fusion_ThreeHighRaceLast(void);
u32 Fusion_ThreeHighRaceMiddle(void);
u32 Fusion_ThreeHighRaceFirst(void);
u32 Fusion_ThreeDark(void);
u32 Fusion_ThreeRace16(void);
u32 Fusion_ThreeNormal(void);
s32 __modsi3(s32 a, s32 b);
s16 Fusion_FindRaceDemonByLevel(u16 level);
u32 sub_08158E00(void);
u32 sub_08158D08(void);
u32 sub_081593EC(void);
u32 sub_08158E78(void);
u32 sub_081590CC(void);
u32 sub_0815915C(void);
u32 sub_081592AC(void);
u32 sub_08158FA4(void);
u32 sub_0815937C(void);
u32 Compendium_CanSummon(u16 id);
s32 Compendium_GetPrice(u16 id);


/* fusioncalc_c.c: fusion tables and item counts */
u32 sub_080ED550(s32 id);
u32 Flag_Test(u32 flag);
u16 Fusion_GetIndexByDemon(u16 id);
u32 Fusion_CalcItem(void);
u16 sub_0815B824(u16 id);
u32 sub_0815B864(u32 id);
void sub_0815B880(u16 n);
void sub_0815B884(u16 a, u16 b, u16 c, u16 *out, u16 *out2);
u32 sub_0815B8F8(u16 id, u16 a);
u16 sub_0815B970(u16 x);
u8 Demon_GetLevel(u16 id);
void Demon_GetRaceAndAlign(u16 id, u8 *align, u8 *race);
u16 Demon_GetRace(u16 id);
u32 sub_0815BA28(u16 id);
u32 sub_0815BA7C(u16 id);
u32 sub_0815BAC4(void);
u32 ItemStock_Add(u16 item, u16 n);
u32 ItemStock_Remove(u16 item, u16 n);
u16 ItemStock_GetIndex(u16 item);
extern const u8 gUnknown_087F1CCC[], gUnknown_087F1D01[], gUnknown_087F153D[], gUnknown_087F1569[],
    gUnknown_087F1D22[];
extern const u16 gUnknown_087F1D72[];

#endif /* GUARD_FUSION_H */
