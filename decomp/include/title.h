#ifndef GUARD_TITLE_H
#define GUARD_TITLE_H

#include "global.h"

/* Script task (64 slots of 100 bytes at 0x02009004); data at 0x24 is task-specific. */
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
    u16 result;
    u16 unk1E;
    void (*onFrame)(struct Task *);
    union
    {
        u32 w[0x10];
        u16 h[0x20];
        u8 raw[0x40];
    } data;
};

/* gMenuState (0x0203A454) as used by the title screen (0x080D6274..). */
struct TitleMenu
{
    u16 mode;
    u16 cursor;                  /* 0x02: menu row; also copied to/from gUnk_0203BB68 */
    u16 blinkTimer;              /* 0x04 */
    u16 blink;                   /* 0x06: "press start" shown while 0 */
    u16 unk08;                   /* 0x08: row 1 enabled */
    u16 unk0A;                   /* 0x0A: row 2 enabled */
    u16 idle;                    /* 0x0C: frames left before the attract demo */
    u16 unk0E;
    s16 unk10;
};

/* Event character sprite (task data at +0x24 of a character task). */
struct CharObj
{
    u16 unk00;
    u16 slot;                    /* 0x02: 0..5, selects the 2 KB buffer / VRAM block / palette */
    u16 shown;                   /* 0x04 */
    u16 id;                      /* 0x06: index into gCharGfxRecords */
    u16 unk08;
    u16 unk0A;
    u16 unk0C;
    u16 unk0E;
    u16 unk10;                   /* 0x10 */
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 frame;                   /* 0x18: animation frame index */
    u16 frameTimer;              /* 0x1A */
    u16 unk1C;
    u16 unk1E;
    struct Task *anim;           /* 0x20 */
    u32 unk24;                   /* 0x24: party index (Char_LoadPartyDemonGfx) or sprite (sub_080D8C34) */
    u32 unk28;
    u32 unk2C;
    u32 unk30;
};

/* Task data +0x24 (CharObj.unk24..) as set by sub_080D8D40 (guess: affine parameters). */
struct CharAffine
{
    u16 enabled;
    u16 scaleX;
    u16 scaleY;
    u16 angle;
};

struct DemonAnim
{
    u32 unk00;
    const void **cells;          /* 0x04 */
};

/* gDemonGfxRecords (0x0872C774), 0x1C bytes each. */
struct DemonGfxRecord
{
    u16 flags;
    u16 pad02;
    const void *palette;         /* 0x04 */
    struct DemonAnim *anim;      /* 0x08 */
    const void *gfx0;            /* 0x0C: tiles 0-127 */
    u32 unk10;
    const void *gfx1;            /* 0x14: tiles 128-255 */
    u32 unk18;
};

/* Character animation frame (record +0x28 points at a list of these). */
struct CharAnimFrame
{
    const void *gfx[2];          /* 0x00: halves loaded with sub_080D77FC */
    const void *sprite;          /* 0x08: gUnknown_08004FF8 = ask sub_080C43B4 */
    u16 duration;                /* 0x0C: 0xFFFF end, 0xFFFE loop */
    u16 unk0E;
    u16 tile;                    /* 0x10: OBJ tile base, 0xFFFF = by slot */
    u16 palette;                 /* 0x12: 0xFFFF = by slot */
    u16 loadGfx;                 /* 0x14 */
    u16 se;                      /* 0x16 */
};

/* gCharGfxRecords (0x08568D78), 0x2C bytes each. */
struct CharGfxRecord
{
    u32 type;
    const void *gfx[4][2];       /* 4 poses x 2 halves of 2 KB */
    const void *palette;         /* 0x24 */
    struct CharAnimFrame *anim;  /* 0x28 */
};

/* gGameState (0x030046C0): only the fields used here. */
struct GameState
{
    u8 pad000[0xAC0];
    u16 unkAC0;                  /* 0xAC0 */
};
extern struct GameState gGameState;

struct SaveMenu;
extern struct SaveMenu gMenuState;
#define TITLE ((struct TitleMenu *)&gMenuState)

extern vu16 gKeysNew;
extern u32 gUnk_0203BB68;
extern u8 gUnk_0200F874[];
extern u16 gPaletteTarget[];
extern u16 gUnk_03002BB0[];
extern u16 gUnk_03002FB0[];
extern u16 gUnk_03000004, gUnk_03000006;
extern u8 gUnk_03000030, gUnk_03000031, gUnk_03000034, gUnk_03000035;
extern u8 gUnk_03000038, gUnk_0300003A;
extern u16 gUnk_03000040;
extern u8 gUnk_03000042, gUnk_03000043;
extern u8 gUnk_03000032, gUnk_03000033, gUnk_03000036, gUnk_03000037, gUnk_03000039;
extern u16 gUnk_03000008, gUnk_0300000C;
extern u16 gUnk_030031D0;
extern struct Task *gMsgWindow;
extern struct Task *gUnk_03006954;
extern struct Task *gUnk_03006938;
extern const u16 gUnknown_08509680[];
extern const u8 gUnknown_0813ECB4[];
extern const u8 gUnknown_0813ECD0[];
extern const u8 gUnknown_0813ECEC[];
extern const u8 gUnknown_0813ED2C[];

extern const u8 gUnknown_084F9CD0[];
extern const u8 gUnknown_0850485C[];
extern const u8 gUnknown_084FA4E0[];
extern const u8 gUnknown_084FA500[];
extern const u8 gUnknown_084FD060[];
extern const u8 gUnknown_084FA660[];
extern const u8 gUnknown_085029CC[];
extern const u8 gUnknown_08508AC0[];
extern const u8 gUnknown_084FA620[];
extern const u8 gUnknown_081B6C30[];
extern const u16 gUnknown_08509648[];
extern const u8 gUnknown_081B5DD4[];
extern const u8 gUnknown_081B7110[];
extern const u8 gUnknown_081B7130[];
extern const u8 gUnknown_0813EBD4[];
extern const u16 gUnknown_085096C4[];
extern const u8 gUnknown_0813EE88[];
extern const u8 gUnknown_0813EE20[];
extern const u8 gUnknown_0813EE3C[];
extern const u8 gUnknown_080017A4[];
extern const u8 gUnknown_0813ED6C[];
extern const u8 gUnknown_0813ED84[];
extern const u8 gUnknown_0813EDF0[];
extern const u8 gUnknown_0813ED9C[];
extern const u8 gUnknown_0813EE08[];
extern const u8 gUnknown_0813EDC0[];
extern const u8 gUnknown_0813EDD8[];
extern const u8 gUnknown_0813EE58[];
extern const u8 gUnknown_0813EC98[];

extern struct Task *gUnk_030069E4;
extern struct Task *gUnk_030065F4;
extern struct Task *gCharTasks[6];
extern const u32 gUnknown_08509764[];
extern const u32 gUnknown_085097A0[];
extern const u32 gUnknown_08509728[];
extern const u32 gUnknown_085097DC[];
extern const u32 gUnknown_08509CD0[];
extern const u32 gUnknown_0855FA84[];
extern u16 gUnk_0300000E;
extern u16 gUnk_02000000[];
extern u8 gUnk_02001000[];
extern u8 gBgPictureBuffer[];
extern u8 gUnk_02003000[];
extern u8 gUnk_03002D10[];
extern u8 gUnk_03003110[];
extern const u8 gUnknown_0852C434[], gUnknown_0852C8CC[], gUnknown_0852CC0C[];
extern const u8 gUnknown_0800536C[], gUnknown_080053C4[], gUnknown_080053F8[], gUnknown_0800542C[];
extern const u8 gUnknown_08005460[], gUnknown_08005494[];
extern const u8 gUnknown_085332EC[], gUnknown_08533788[], gUnknown_08533C94[], gUnknown_085340D8[];
extern const u8 gUnknown_08005810[], gUnknown_08005850[], gUnknown_08005898[], gUnknown_080058EC[];
extern const u8 gUnknown_0800594C[], gUnknown_080056AC[], gUnknown_080056F8[], gUnknown_08005744[];
extern const u8 gUnknown_08005790[], gUnknown_080057D0[], gUnknown_0800595C[], gUnknown_08005974[];
extern const u8 gUnknown_0800598C[], gUnknown_080059A4[], gUnknown_080059B4[], gUnknown_080059C4[];
extern const u8 gUnknown_08005B40[];
extern const u8 gUnknown_08535510[], gUnknown_08535988[], gUnknown_08535FB8[], gUnknown_08536318[];
extern const void *const gUnknown_08565C08[];
extern const void *const gUnknown_08565CD8[];
extern const void *const gUnknown_08565DC4[];
extern const void *const gUnknown_08565DE8[];
extern const void *const *const gUnknown_08565F20[];
extern const void *const *const gUnknown_08565FE4[];
extern u8 gUnk_03003800[];
extern const u8 gUnknown_08005028[];
extern const u8 gUnknown_08566C34[], gUnknown_08567060[], gUnknown_085673D0[], gUnknown_085677A4[];
extern const u8 gUnknown_08567894[];
extern const void *const gUnknown_085678B4[];
extern const void *const gUnknown_0856793C[];
extern const u8 gUnknown_08567A04[], gUnknown_08567F4C[], gUnknown_08568218[], gUnknown_085683D0[];
extern const void *const gUnknown_085683F0[];
extern const u8 gUnknown_0853131C[], gUnknown_08531914[], gUnknown_08532034[], gUnknown_08532744[];
extern const u8 gUnknown_08532A9C[];
extern const void *const gUnknown_08568C14[];
extern const u8 gUnknown_08550398[], gUnknown_08550EBC[];
extern const u8 gUnknown_080061A0[];
extern struct CharGfxRecord gCharGfxRecords[];
extern u8 gUnk_0201D874[], gUnk_02024074[];
extern u32 gUnk_03006098, gUnk_0300609C;
extern const u32 gUnknown_085816B8[];
extern u16 gUnk_0203DB28[];
extern u16 gUnk_03003150[];
extern struct DemonGfxRecord gDemonGfxRecords[];
extern const void *const gUnknown_085651B0[];
extern const u32 gUnknown_081A64A8[];
extern const u8 gUnknown_085171C4[];
extern const u8 gUnknown_08517414[];
extern const u8 gUnknown_08005064[], gUnknown_08005088[], gUnknown_08005104[], gUnknown_0800520C[];
extern const u8 gUnknown_080054D4[], gUnknown_08005514[], gUnknown_08005554[], gUnknown_0800559C[];
extern const u8 gUnknown_080055E4[], gUnknown_08005624[], gUnknown_08005664[];
extern const u8 gUnknown_0800521C[], gUnknown_0800522C[], gUnknown_0800523C[], gUnknown_08005254[];
extern const u8 gUnknown_08005278[], gUnknown_08005290[], gUnknown_080052C0[], gUnknown_080052F0[];
extern const u8 gUnknown_08005314[], gUnknown_08005338[];
extern u8 gUnk_03000039;
extern u32 gFrameCounter;
extern u16 gUnk_03002D50[];
extern u16 gUnk_03003170[];
extern const u8 gUnknown_080050C4[];
extern const u32 gUnknown_0855FAB4[];
extern const u8 gUnknown_08004FF8[];
extern const u8 gUnknown_081C25F4[];
extern const u8 gUnknown_0855FBA4[];
extern const u8 gUnknown_08563024[];
extern const u8 gUnknown_08560D24[];
extern const u8 gUnknown_085630B0[];
extern const u8 gUnknown_08561EA4[];
extern const u8 gUnknown_0856313C[];
extern const u8 gUnknown_085632F4[];
extern const u8 gUnknown_08563A5C[];
extern const u8 gUnknown_08563AC0[];
extern const u8 gUnknown_08002C88[];
extern const u8 gUnknown_08002C70[];
extern const u8 gUnknown_08002CBC[];
extern const u8 gUnknown_08002CCC[];
extern const u8 gUnknown_08563BD8[];
extern const u8 gUnknown_08564358[];
extern const u8 gUnknown_085643BC[];
extern const u8 gUnknown_086BF890[];
extern const u8 gUnknown_08118CC4[];
extern const u8 gUnknown_08118CE0[];
extern void (*const gUnknown_0855FA9C[])(void);

#define DmaSet3(src, dest, control)              \
{                                                \
    vu32 *dmaRegs = (vu32 *)(REG_BASE + 0xD4);   \
    dmaRegs[0] = (vu32)(src);                    \
    dmaRegs[1] = (vu32)(dest);                   \
    dmaRegs[2] = (vu32)(control);                \
    dmaRegs[2];                                  \
}

/* BIOS / library */
void CpuSet(const void *src, void *dst, u32 control);
void HuffUnComp(const void *src, void *dest);
void LZ77UnCompWram(const void *src, void *dest);
void RLUnCompWram(const void *src, void *dest);

/* other code */
void Sprite_Draw(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
void Sprite_DrawBlended(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
void sub_0815862C(const void **def, u16 scaleX, u16 scaleY, u32 n);
void Sprite_DrawSharedAffine(const void **def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y,
                             u8 matrix);
void FontSprite_DrawGlyph(u16 glyph, u32 a1, u32 a2, u16 x, u16 y);
void Palette_CopyWithEffect(u32 a0, const void *src, void *dst, u32 a3, u32 a4);
void Palette_FillWithEffect(u32 a0, u32 a1, void *dest, u32 size, u32 a4);
void Palette_MarkDirty(void);
void *PalFade_FadeInFromBlack(u16 delay);
struct PalFade *PalFade_FadeToBlack(u16 delay);
u16 PalFade_AllDone(void);
void VBlankTask_AddCounted(void (*func)(void), u32 count);
void SetMainCallback(void (*func)(void));
void Task_End(struct Task *task);
struct Task *Task_Create(const u32 *script, u32 parent);
void Task_Pause(struct Task *task);
void Task_Resume(struct Task *task);
void Task_Signal(struct Task *task);
struct Task *Task_GetParent(struct Task *task);
struct CharGfxRecord *Char_GetRecord(u16 id);
void Char_LoadGfxHalf(struct CharObj *obj, const void *src, u32 a2, u32 half, u32 a4);
void sub_080C3F4C(struct CharObj *obj, const void *palette, u32 index, u32 size, u32 a4);
void CharObj_End(struct Task *task, u32 a);
void sub_080C41F4(struct Task *task);
u16 sub_080C4388(struct CharObj *obj);
void sub_080C44CC(struct CharObj *obj, const void *sprite, u16 frame, u32 pal, u16 a4, u16 tile, u16 x, u16 y);
const void *sub_080C43B4(struct CharObj *obj);
void sub_080C43F8(struct Task *task, const void *sprite, u16 tile, u16 pal);
void sub_080B29A8(u16 mode);
void sub_080C3EBC(void);
void sub_080C3EE0(void);
void sub_080C3F04(void);
void sub_080C44B0(struct Task *task);
void Font_ResetGlyphSpriteCache(u32 baseTile);
void Windows_Init(void);
void Task_ClearAll(void);
void sub_080AE2D0(void);
void sub_080D977C(void);
u16 Random_Byte(void);
s32 Palette_IsBg13Black(void);
struct PalFade *PalFade_FadeRangeInFromBlackTagged(u16 start, u16 count, u16 delay, u16 tag);
u32 *FieldMap_CellRecordsRel(u16 fwd, u16 side);
u16 *FieldMap_FindRecord(u32 *p, u16 type);
struct PalFade *PalFade_FadeRangeToBlackTagged(u16 start, u16 count, u16 delay, u16 tag);
u32 SaveScreen_Open(u16 mode, u16 arg1);
void Music_Play(u16 se);
void Sound_Play(u32 se);
void Music_FadeOut(u32 a);
u16 sub_080C2A84(u32);
s32 sub_080C2644(u32);
s32 sub_080C2734(u32);
void Game_NewGame(void);
void sub_080B70BC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
void sub_080CFFE0(u32);
void sub_080C1450(void);
void sub_080C1328(void);
void sub_080C1384(void);
void sub_080D5C20(void);
void sub_080DDEDC(void);

/* this region */
u32 Title_HasExtraUnlocked(void);
void sub_080D7A04(struct Task *task);
void sub_080D77FC(struct Task *task, const void **base, u32 a2, u32 pose, u32 half);
void Char_DrawBySlot(struct Task *task, const void *sprite);
void Char_DrawAnimFrame(struct Task *task, struct CharAnimFrame *frame);
void sub_080D7D60(const u8 *src);
void sub_080D7D98(const u8 *src);
void sub_080D7E2C(void);
void sub_080D7E48(void);
void sub_080D7E64(void);
void sub_080D7EFC(void);
void sub_080D8148(void);
void sub_080D7794(void);
struct Task *Char_FindOther(struct Task *self, u16 id);
void sub_080D8768(void);
void sub_080D89AC(struct Task *task, const void *sprite);
void sub_080D8A84(void);
void sub_080D8C10(void);
void sub_080D8D80(void);
void sub_080D9448(void);

#endif /* GUARD_TITLE_H */
