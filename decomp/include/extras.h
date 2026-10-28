#ifndef GUARD_EXTRAS_H
#define GUARD_EXTRAS_H

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

/* Task data of the menus at 0x080D9B64.. (task + 0x24). */
struct C0d9Menu
{
    u16 cursor;                  /* 0x00 */
    u16 unk02;
    const void *spr04;           /* 0x04 */
    const void *spr08;           /* 0x08 */
    u16 unk0C;
    u16 unk0E;
    u16 unk10;
    u16 unk12;
    const void *spr14;           /* 0x14 */
    const void *spr18;           /* 0x18 */
    struct Task *win;            /* 0x1C */
    u32 unk20;
    u8 items[7];                 /* 0x24 */
    u8 count;                    /* 0x2B */
};

#define DmaFill32_3(value, dest, control)        {                                                    vu32 tmp = (vu32)(value);                        DmaSet3(&tmp, dest, control);                }

#define DmaFill16_3(value, dest, control)        {                                                    vu16 tmp = (vu16)(value);                        DmaSet3(&tmp, dest, control);                }

#define DmaSet3(src, dest, control)              \
{                                                \
    vu32 *dmaRegs = (vu32 *)(REG_BASE + 0xD4);   \
    dmaRegs[0] = (vu32)(src);                    \
    dmaRegs[1] = (vu32)(dest);                   \
    dmaRegs[2] = (vu32)(control);                \
    dmaRegs[2];                                  \
}

/* gGameState (0x030046C0): only the fields used here. */
struct GameState
{
    u8 pad000[0x18B0];
    u32 saveSlot;                /* 0x18B0 */
};
extern struct GameState gGameState;

extern u32 gUnk_0300609C;
extern u8 gUnk_02000000[];
extern u8 gUnk_02001000[];
extern u8 gBgPictureBuffer[];
extern u8 gUnk_02024074[];
extern u8 gUnk_0201D874[];
extern u16 gPaletteTarget[];
extern u16 gPaletteBuffer[];
extern u8 gUnk_03000030, gUnk_03000031, gUnk_03000032, gUnk_03000033;
extern u8 gUnk_03000034, gUnk_03000035, gUnk_03000036, gUnk_03000037;
extern u8 gUnk_03000038, gUnk_03000039, gUnk_0300003A;
extern vu16 gKeysNew;
extern u16 gRepeatedKeys;
extern u32 gYesNoResult;
extern u32 gFrameCounter;
extern u8 gUnk_030061C0[], gUnk_030062B0[], gUnk_030060A0[];
extern u16 gUnk_03006380;
extern u32 gUnk_03006360;
extern u8 gUnk_03006368, gUnk_030062F0, gUnk_03003970, gUnk_030062F4, gUnk_03006370;
extern u16 gUnk_03006364;
extern u8 gUnk_03006340[];
void arm_08032B7C(void);
void SerialTimer3Intr(void);
extern const u8 gUnknown_0858712C[], gUnknown_08586C2C[];
extern u8 gUnk_02002000[], gUnk_02004000[];
extern const u8 gUnknown_08587130[], gUnknown_085874EC[], gUnknown_08588050[], gUnknown_085887D4[];
extern const u8 gUnknown_08588FA4[], gUnknown_0858979C[];
extern u32 gUnk_0200AB04;
extern u16 gDispRegs, gUnk_03000002, gUnk_03000004, gUnk_03000008, gUnk_0300000A, gUnk_0300000C;
extern u8 gUnk_02030C74[];
extern const u8 gUnknown_08589C3C[], gUnknown_08589C7C[], gUnknown_08587830[], gUnknown_08589B3C[];

/* Task data of the card game at 0x080DD278.. */
struct C0d9Cards
{
    u8 b[0x15];
    u8 cards[27];                /* 0x15 */
};

/* 0x020399E0 as used by the mini program at 0x080DDEDC (rotation/scaling parameters). */
struct C0d9Bg
{
    u16 *fade;                   /* 0x00: PalFade_FadeInFromBlack result (first u16: busy) */
    u16 exit;                    /* 0x04: 1 = leave to sub_080D9608 */
    u16 unk06;
    s16 unk08, unk0A, unk0C, unk0E; /* 0x08: BG2 PA..PD */
    s32 unk10, unk14;            /* 0x10: BG2X/BG2Y */
    s16 unk18, unk1A;            /* 0x18: centre in the bitmap */
    u16 unk1C;                   /* 0x1C: angle */
    s16 unk1E, unk20;            /* 0x1E: scale x/y */
    u16 unk22;
    s16 unk24, unk26;            /* 0x24: centre on screen */
    u16 unk28;                   /* 0x28: scale step */
    u16 unk2A;
    s32 unk2C, unk30;
    s16 unk34, unk36;            /* 0x34: script state, 0x36: load step */
};
#define gC0d9Bg (*(struct C0d9Bg *)&gUnk_020399E0)
extern u16 gUnk_030031B4;
extern const u8 gUnknown_08580E40[];
extern const u8 gUnknown_08008784[], gUnknown_08008750[], gUnknown_080087A0[], gUnknown_0800876C[];
extern const u8 gUnknown_08008C54[], gUnknown_08008C64[], gUnknown_08008C7C[], gUnknown_08008C8C[];
extern const u8 gUnknown_08008C9C[], gUnknown_08008CB4[], gUnknown_08008CC4[], gUnknown_08008CD4[];
extern const u8 gUnknown_08008CEC[];
extern u8 gUnk_02003000[];
extern const u8 gUnknown_0857D5C0[], gUnknown_085805C0[], gUnknown_08581140[], gUnknown_08581240[];
extern const void *const gUnknown_08583BEC[];

/* gUnknown_08583E84: per demon, the event script and two marker positions (0x14 bytes). */
struct C0d9MapRec
{
    const void *script;
    u32 x1, y1;
    u32 x2, y2;
};
extern const struct C0d9MapRec gUnknown_08583E84[];
extern u8 gUnk_0200F874[];
extern const u16 *const gUnknown_0858329C[];
extern const u16 gUnknown_0800974E[];
extern const u32 gUnknown_08583CA0[];
extern const u16 *const gUnknown_0858367C[];
extern const u16 *const gUnknown_08583788[];
extern struct Task gTasks[64];
extern const u16 gUnknown_0858325A[];
extern const u32 gUnknown_0858326C[];
extern const u8 gUnknown_0857F500[];
extern const u16 *const gUnknown_08582D28[];
extern const u16 gUnknown_080095B4[];
extern u32 gUnk_03004690[];
extern u16 gStatusList[];
extern const u16 gUnknown_08583258[];

/* Compendium state at 0x020399E0 (only the fields used here). */
struct C0d9Dict
{
    u8 pad00[0x38];
    u32 selected;                /* 0x38: demon id (list entry & 0x7FFF) */
    u16 unk3C;
    u16 unk3E;
    u16 mode;                    /* 0x40 */
    u16 arg;                     /* 0x42 */
    u16 unk44;
    u16 unk46;
    u32 task;                    /* 0x48 */
};
extern struct C0d9Dict gUnk_020399E0;
#define gDict gUnk_020399E0
extern const u8 gUnknown_0800853C[];
extern const u16 gUnknown_085829BC[];
extern const u16 gUnknown_08009534[], gUnknown_08009540[];
extern const void *const gUnknown_085829CC[];
extern u8 gUnk_03002EB0[];
extern u16 gWindowTilemapBuffer[];
extern u16 gUnk_0300000E, gUnk_03000006;

/* gFieldState (0x03004550): only the fields used here. */
struct FieldState
{
    u16 state;
};
extern struct FieldState gFieldState;
extern u32 gUnk_03006090[];
extern u8 gUnk_03004740[];

/* 8 bytes at gGameState + 0x80 (0x03004740), seeded by sub_080DAB88 when zero. */
union C0d9Code
{
    u32 w[2];
    u8 b[8];
    s8 s[8];
};
extern u16 gUnk_0203B454[];
extern const u8 gUnknown_08008E8C[], gUnknown_08002BE8[], gUnknown_08002B34[], gUnknown_08002B68[];
extern const u8 gUnknown_08002BA4[], gUnknown_08002BD8[], gUnknown_081B6A64[];
extern const u8 gUnknown_08008F58[], gUnknown_08008F68[];
extern const void *const gUnknown_08582410[];
extern const u16 *const gUnknown_08582438[];
extern const u16 gUnknown_08009550[];

/* gMenuState (0x0203A454) as used here. */
struct C0d9MenuState
{
    u32 magic00;                 /* 0x00: 0x13240800 */
    u32 unk04[2];                /* 0x04: copy of 0x03006090 */
    u8 pad0C[0x28];
    u32 magic;                   /* 0x34: 0x13240800 once received */
    u8 flags[0x30];              /* 0x38: received flags, one bit each (visions 300..363 / demons) */
    u8 pad68[0x10];
    struct Task *task;           /* 0x78 */
    struct Task *listTask;       /* 0x7C */
    void (*onFrame)(struct Task *); /* 0x80 */
    void (*listOnFrame)(struct Task *); /* 0x84 */
};
extern struct C0d9MenuState gMenuState;
extern struct Task *gUnk_03006098;
extern const u8 gUnknown_08008D28[], gUnknown_08008E20[], gUnknown_08008DA4[], gUnknown_08008EC8[];
extern const u8 gUnknown_08008DD8[], gUnknown_08008F10[], gUnknown_08008D7C[];

extern const u8 gUnknown_081B6C30[];
extern const u8 gUnknown_08580A60[];
extern const u8 gUnknown_08580880[];
extern const u8 gUnknown_08573AF4[];
extern const u8 gUnknown_0857D9C0[];
extern const void *const gUnknown_085814A0[];
extern const void *const gUnknown_085814B4[];
extern const u8 gUnknown_080083DC[];
extern const u8 gUnknown_080083C4[];
extern const u32 gUnknown_08581568[];
extern const u16 *const gUnknown_08581598[];

/* BIOS / library */
void HuffUnComp(const void *src, void *dest);
void LZ77UnCompWram(const void *src, void *dest);

/* other code */
void Font_ResetGlyphSpriteCache(u32 baseTile);
void Wave_Update(void);
void Task_RunAll(void);
void VBlankTask_AddCounted(void (*func)(void), u32 count);
void Palette_CopyWithEffect(u32 a0, const void *src, void *dst, u32 a3, u32 a4);
void PalFade_FadeRangeInFromBlackTagged(u16 start, u16 count, u16 delay, u16 tag);
void PalFade_FadeRangeToBlackTagged(u16 start, u16 count, u16 delay, u16 tag);
void PalFade_FadeRangeInFromBlack(u16 start, u16 count, u16 delay);
void PalFade_FadeRangeToBlack(u16 start, u16 count, u16 delay);
void Tilemap_FillRect(u16 value, void *map, u16 x, u16 y, u16 w, u16 h);
void Tilemap_CopyRectSkipZero(const void *src, void *dst, u16 tileAdd, u16 palette, u16 x, u16 y, u16 w, u16 h);
void Sprite_Draw(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
struct Task *Window_Create(u16 x, u16 y, u16 w, u16 h, u16 bg);
struct Task *Window_CreateOpen(u16 x, u16 y, u16 w, u16 h, u16 bg);
void Window_Close(); /* (struct Task *win, u32 erase); some callers pass only the window */
void Sound_Play(u32 se);
struct Task *Task_Create(const u32 *script, u32 parent);
struct Task *Task_GetParent(struct Task *task);
void Text_DrawSpriteString(const u16 *str, u16 a1, u16 a2, u16 x, u16 y, u16 advance);
u32 SaveSlot_Write(u32 slot, struct GameState *src);
void SetMainCallback(void (*func)(void));
void Palette_MarkDirty(void);
void Task_End(struct Task *task);
void sub_080C4AB0(u32 a0, u32 a1, u32 x, u32 y);
u8 *NumberToDigits(u32 n);
void CpuSet(const void *src, void *dst, u32 control);
void sub_080DF954(u32 a0, void *a1, void *a2);
u8 Inventory_GetCount(u16 id);
void Inventory_AddItem(u16 id);
void sub_080AE2D0(void);
u8 *Action_GetRecord(u16 id);
void FontSprite_DrawGlyph(u16 glyph, u32 a1, u32 a2, u16 x, u16 y);
void FontSprite_DrawGlyphTinted(u16 glyph, u16 a1, u16 a2, u16 x, u16 y, u16 palette);
void sub_080C4A4C(u32 a0, u32 a1, u32 x, u16 y);
void sub_080AF218(u32 a0, const void *script);
void sub_080C3818(u32 a);
void PlayTime_Tick(void);
u16 *PalFade_FadeInFromBlack(u16 delay);
s16 FixedInverse8(s16 a);
s16 FixedMul8(s16 a, s16 b);
extern const s16 gSineTable[];
void sub_080D9608(void);
void sub_080D5B8C(u32 mode);
u16 Random_Byte(void);
void Music_Play(u32 se);
void Task_ClearAll(void);
void *memset(void *dst, int c, unsigned long n);
void *memcpy(void *dst, const void *src, unsigned long n);
void sub_08153378(const void *src, u32 a1, u32 n);
u16 sub_080C2600(u16 id);
void m4aMPlayAllStop(void);
void Tilemap_CopyRect(const void *src, void *dst, u16 tileAdd, u16 palette, u16 x, u16 y, u16 w, u16 h);
void Dict_BuildList(struct Task *task, u32 mode, u32 arg);
u32 Dict_CountListed(void);
u32 sub_080DB8D4(void);
const u16 *Race_GetName(u16 race);
u8 *Demon_GetRecord(u16 id);
void sub_080C2674(u32 id);
u16 sub_080C263C(u16 id);
u32 sub_080E8E00(u16 a0, u16 demon);
void sub_080E8F80(u32 a0, u32 x, u32 y, u32 a3);
void Sprite_DrawFraction(u32 a, u32 b, u16 x, u16 y);
u16 Vision_BuildList(u32 a);
u32 Vision_CountListed(void);
u16 sub_080C2A84(u32);
s32 sub_080C2644(u32);
s32 sub_080C2734(u32);

/* this region */
void sub_080D9868(void);
void sub_080D9A14(void);
void sub_080D9A38(void);
void sub_080D9A5C(void);
void sub_080D9B64(struct Task *task);
void sub_080D9B34(); /* called with a task in r0 by sub_080DC0B0 */
void sub_080D9BAC(void);
void sub_080D9C24(struct Task *task);
void sub_080D9D8C(); /* called with the task in r0 by sub_080DB9C4 */
void sub_080DB938(void);
void sub_080DCD74(void);
const void *Dict_GetMapScript(u16 id);
void Cards_Deal(struct Task *task);
void sub_080DDFAC(void);
u8 sub_080DE0F8(void);
void sub_080DE208(void);
u8 sub_080DE21C(void);
void sub_080DE258(void);
void sub_080DE2C0(void);
void Mini_ZoomBg2Affine(void);
void Mini_UploadBg2Affine(void);
void sub_080DE85C(void);
void sub_080DE98C(void);
u8 sub_080DE9A8(void);
void sub_080DEA9C(void);
u8 sub_080DEAB0(void);
void sub_080DEAE4(void);
void sub_080DEB4C(void);
void Mini_UpdateBg2Affine(void);
void Link_InitSerial(void);
void sub_080DEEE8(void);
void sub_080DEF00(void);
u32 sub_080DEF50(void *buf);
void sub_080DF05C(void *buf);
void sub_080DE0DC(void);
void sub_080DCF20(struct Task *task);
void sub_080D9D24(void);
void sub_080DE78C(void);
void sub_080DA290(void);
void sub_080DA574(void);
void sub_080DA634(void);
void sub_080DA6D4(void);
void sub_080DB0BC(void);
u32 sub_080DB3E4(u16 id);
void sub_080DB464(); /* sub_080DC418 passes the task */
void sub_080DC418(struct Task *task);

#endif /* GUARD_EXTRAS_H */
