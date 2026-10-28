#ifndef GUARD_MENU2_H
#define GUARD_MENU2_H

#include "global.h"

/* Script task (64 slots of 100 bytes at 0x02009004); data at 0x24 is task-specific. */
struct Task
{
    u16 state;
    u16 id;
    u16 parent;
    u8 unk06;                    /* byte written by the prize/yes-no code */
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

/* Status/description screen state (gMenuState, 0x0203A454), as used from 0x080D2F04 on. */
struct StatusMenu2
{
    u16 mode;
    u16 page;                    /* 0x02: stats page 0..3 */
    u16 id;                      /* 0x04 */
    u16 member;                  /* 0x06 */
    u16 unk08;
    u16 arrowBlink;              /* 0x0A */
    u16 arrowTimer;              /* 0x0C */
    u16 pad0E;
    u16 descPage;                /* 0x10 */
    u16 descPageCount;           /* 0x12 */
    u8 pad14[0x22 - 0x14];
    u16 unk22;
    u8 pad24[0x9C - 0x24];
    u16 unk9C;
    u16 unk9E;
    u16 unkA0;
    u16 itemA2;
    u16 itemA4;
};

/* Casino prize list (task data). */
struct PrizeList
{
    struct Task *window;
    u16 cursor;
    u16 top;                     /* first row shown */
    u16 count;
};

struct WipeData
{
    u32 unk00;
    u16 step;
};

/* Demon/record list (task data) used from sub_080D40E8. */
struct RecordList
{
    u32 unk00;
    u32 unk04;
    u16 cursor;                  /* 0x08 */
    u16 top;                     /* 0x0A */
    u16 count;                   /* 0x0C */
    u16 filter;                  /* 0x0E: passed to sub_080D45F0 */
};

/* gMenuState as used by sub_080D3B18/sub_080D3B58: a header word and two small bitfields. */
struct FlagState
{
    u32 magic;                   /* 0x13240800 */
    u32 unk04[2];
    u8 pad0C[0x34 - 0x0C];
    u32 unk34;
    u8 bits[8];                  /* 0x38: bit (id - 0x100) */
};
#define FLAG_STATE ((struct FlagState *)&gMenuState)

/* gMenuState as used by the slot machine (sub_080D4AA8..). */
struct SlotMenu
{
    u16 glyphs[4];               /* 0x00: 0xFFFF = blank */
    u16 slot;                    /* 0x08: next glyph slot (0..3) */
    u16 flash;                   /* 0x0A: countdown after a key press; lines lit with palette 0xD while nonzero */
    u16 unk0C;
    u16 row;                     /* 0x0E */
    u16 col;                     /* 0x10 */
    u16 pad12;
    u32 window14;                /* 0x14 */
    u32 bet;                     /* 0x18 */
    u16 unk1C;
    u16 pad1E;
    u8 digits[8];                /* 0x20: entered number, 0xFF = empty */

    struct Task *window28;
    struct Task *window2C;
};
#define SLOT_MENU ((struct SlotMenu *)&gMenuState)

/* gMenuState as used by the scene scripts (sub_080D5C20, sub_080D6254). */
struct SceneMenu
{
    u16 mode;
    u16 pad02[6];
    u16 vars[8];                 /* 0x0E */
};
#define SCENE_MENU ((struct SceneMenu *)&gMenuState)

struct SaveMenu;
extern struct SaveMenu gMenuState;
#define STATUS_MENU2 ((struct StatusMenu2 *)&gMenuState)

/* Live game state (gGameState, 0x030046C0); fields as in menu.h plus the ones used here. */
struct GameState
{
    u8 pad000[8];
    u32 unk008;                  /* first party member: experience? (set to 208250 by Debug_SetupTestGame) */
    u8 pad00C;
    u8 unk00D;                   /* first party member: level? */
    u8 pad00E[0xA00 - 0x0E];
    u8 names[4][8];
    u8 padA20[0xAC3 - 0xA20];
    u8 unkAC3;
    u8 padAC4[0xAD8 - 0xAC4];
    u32 unkAD8;                  /* 0xAD8: money; drawn by sub_080C7664 in the status/shop windows */
    u32 unkADC;
    u32 unkAE0;
    u8 padAE4[0x15E8 - 0xAE4];
    u8 flags[0x100];
};

extern struct GameState gGameState;

extern struct Task gTasks[64];
extern vu16 gKeysNew;
extern u16 gRepeatedKeys;
extern u32 gYesNoResult;
extern u16 gScriptItemCheckId;
extern s32 gUnk_0203DB2C;
extern u16 gUnk_0203DB28;
extern u32 gUnk_03003BB4;
extern u32 gUnk_030037F0;
extern const u8 gUnknown_084F9FE0[];
extern const u8 gUnknown_084FA860[];
extern const u8 gUnknown_084FAD60[];
extern const u8 gUnknown_084FB260[];
extern const u8 gUnknown_084FB760[];
extern const u8 gUnknown_084FBC60[];
extern const u8 gUnknown_084FC160[];
extern const u8 gUnknown_084FC660[];
extern const u8 gUnknown_084FCB60[];
extern const u8 gUnknown_081B9BB0[];
extern const u8 gUnknown_081BA3B0[];
/* BG scroll registers (gDispRegs, 0x03000000, copied to REG_BG0HOFS..). */
extern u16 gDispRegs, gUnk_03000002, gUnk_03000004, gUnk_03000006;
extern u16 gUnk_03000008, gUnk_0300000A, gUnk_0300000C, gUnk_0300000E;
extern u8 gUnk_03000038;
extern u8 gUnk_03000039;
extern u8 gUnk_0300003A;
extern u8 gWindowMap[];
extern u16 gPaletteBuffer[];
extern u32 gUnk_0203BB68;
extern struct Task *gUnk_030069E4;
extern u16 gUnk_0200E7D4[];
extern u16 gUnk_03002BB0[];
extern u16 gUnk_03002BD0[];
extern u16 gUnk_03002FB0[];
extern u16 gUnk_03002FD0[];
extern const u8 gUnknown_08002AB0[];
extern const u8 gUnknown_08002AF8[];
extern const u16 gUnknown_084F94E8[];
extern const u16 gUnknown_084F9508[];
extern const u32 gUnknown_084F9C94[];
extern const u8 gUnknown_08509640[];
extern const u32 gUnknown_08509CF8[];
extern const u32 gUnknown_08509CD0[];
extern u16 gPaletteTarget[];
extern const u8 gUnknown_084F4140[];
extern const u8 gUnknown_084F5214[];
extern const u8 gUnknown_084F6108[];
extern const u8 gUnknown_084F6F7C[];
extern const u8 gUnknown_084F7C5C[];
extern const u8 gUnknown_084F89E0[];
extern const u8 gUnknown_084F8FF0[];
extern const u8 gUnknown_084F8760[];
extern const u16 gUnknown_084F9528[32][32];
extern const u16 gUnknown_084F93E8[];
extern struct Task *gUnk_03003FF0;
extern u16 gUnk_03000040;
extern u8 gUnk_0300003C;
extern u16 gUnk_0203DB6A;
extern const u16 gUnknown_084F404C[];
extern const u32 gUnknown_084F4028[];
extern const u32 gUnknown_084F4054[];
extern const u32 gUnknown_084F40D8[];
extern const u32 gUnknown_084F9A28[];
extern u32 gFrameCounter;
extern const u16 gUnknown_084F3FDC[];
extern const u16 gUnknown_084F3FF0[];
extern const u16 gUnknown_084F3FFC[];
extern const u16 gUnknown_084F4014[];
extern u16 gUnk_03003110[];
extern const u32 *const gUnknown_087F02B8[];
extern const u8 gUnknown_084F3AF0[];
extern const u16 gUnknown_084F3F30[];
extern const void *const gUnknown_084F3FB0[];
extern const u8 gUnknown_08002A3C[];
extern const u8 gUnknown_08002A64[];
extern const u8 gUnknown_08002A7C[];
extern const u8 gUnknown_0800080C[];
extern u16 gFieldState;
extern u8 gUnk_02001000[];
extern const void *gUnknown_084F3838[];
extern const u8 gUnknown_0815C090[];
extern const u8 gUnknown_0815C0DE[];
extern const u8 gUnknown_0815C110[];
extern const u8 gUnknown_0805C3D0[];
extern const u32 gUnknown_084F1514[];
extern const u32 gUnknown_084F36B0[];
extern const u8 gUnknown_08002A94[];
extern struct Task *gUnk_03003FEC;
extern u16 gUnk_0203B454[];
extern u16 gWindowTilemapBuffer[32][32];
extern u8 gUnk_0200F874[];
extern u16 gUnk_03003150[];
extern u8 gBgPictureBuffer[];
extern u8 gUnk_0200BEC8[];

extern const void *gUnknown_084F3150[];
extern const u8 gUnknown_084F3148[];
extern const u8 gUnknown_084F316C[];
extern const u8 gUnknown_084F3174[];
extern const u32 gUnknown_084F317C[];
extern const u32 gUnknown_084F31E0[];
extern const u32 gUnknown_084F3204[];
extern const u32 gUnknown_084F3228[];
extern const u32 gUnknown_084F32B4[];
extern const u32 gUnknown_084F3498[];
extern const u8 gUnknown_081B5810[];
extern u8 gUnk_0203BB6C[];
extern u16 gUnk_02000800[32][32];
extern u16 gUnk_02000000[32][32];
extern const u16 gUnknown_081B93B0[32][32];
extern const u16 gUnknown_08770A24[];
extern const u8 gUnknown_084F367C[];
extern const u8 gUnknown_084F3680[];
extern const u8 gUnknown_084F3684[];
extern const u8 gUnknown_084F368C[];
extern const u8 gUnknown_084F3694[];
extern const u8 gUnknown_084F369C[];
extern const u8 gUnknown_084F36A0[];
extern const u8 gUnknown_084F36A8[];

/* Item combination table (12 bytes per entry, id -1 ends it). */
struct ComboEntry
{
    s16 id;
    u16 items[3];                /* items[1], items[2] optional (0) */
    u16 bit;                     /* bit in the FlagState bitfield, 0 = none */
    u16 pad0A;
};
extern const struct ComboEntry gUnknown_084F3754[];
extern const u8 gUnknown_080014B0[];
extern const u8 gUnknown_080014C0[];
extern const u8 gUnknown_080014D8[];
extern const u8 gUnknown_08002A4C[];
extern const u16 gUnknown_081B8170[32][32];
extern const u8 gUnknown_081B5710[];

#define DmaSet3(src, dest, control)              \
{                                                \
    vu32 *dmaRegs = (vu32 *)(REG_BASE + 0xD4);   \
    dmaRegs[0] = (vu32)(src);                    \
    dmaRegs[1] = (vu32)(dest);                   \
    dmaRegs[2] = (vu32)(control);                \
    dmaRegs[2];                                  \
}

#define DMA3_FILL32(value, dest, control)        {                                                    vu32 tmp = (value);                              DmaSet3(&tmp, dest, control);                }

/* Engine functions */
u8 *NumberToDigits(u32 n);
void Sprite_Draw(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
void Sprite_DrawSingle(const void *tmpl, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
void FontSprite_DrawGlyph(u16 glyph, u16 a1, u16 a2, u16 x, u16 y);
void FontSprite_DrawGlyphTinted(u16 glyph, u16 a1, u16 a2, u16 x, u16 y, u16 palette);
struct Task *Task_Create(const u32 *script, u32 parent);
void Task_End(struct Task *task);
void CpuSet(const void *src, void *dst, u32 control);
struct Task *TextWindow_CreateOpen(u16 x, u16 y, u16 w, u16 h, u16 screen);
void TextWindow_Close(struct Task *task, s32 now);
void VBlankTask_AddCounted(void (*func)(void), u16 count);
void Tilemap_FillRect(u16 value, u16 (*map)[32], u16 x, u16 y, u16 w, u16 h);
void Tilemap_CopyRectSkipZero(const u16 (*src)[32], u16 (*dst)[32], u16 tileAdd, u16 palette, u16 x, u16 y, u16 w, u16 h);
void Canvas_FillRect(u8 color, u8 *dst, u16 x, u16 y, u16 w, u16 h);
void Palette_FillWithEffect(u32 a0, u32 a1, u16 *dst, u32 a3, u32 a4);
void Palette_MarkDirty(void);
void sub_080C51D4(u32 se);
u8 *Action_GetRecord(u16 id);
u8 *sub_080BF648(u16 id);
void sub_080BF468(u16 id, u32 a1, s32 *out);
s32 sub_080C31F0(void);
void sub_080C8048(s32 a0, u32 x, u32 y, u32 a3);
void sub_080C4B14(u32 a0, u32 a1, u32 x, u32 y);
void sub_080C4B78(u32 a0, u32 a1, u32 x, u32 y);
void sub_080C4A4C(u32 a0, u32 a1, u32 x, u16 y);
void sub_080C4AB0(u32 a0, u32 a1, u32 x, u32 y);
void sub_080C49EC(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
u32 sub_080C5B10(u16 id);
void sub_080C7664(u16 x, u16 y, u32 a2);
void sub_080C6558(void);
void Font_ResetGlyphSpriteCache(u16 baseTile);
void Task_Signal(struct Task *task);
void Flag_Set(u32 flag);
u32 Flag_Test(u32 flag);
void sub_080C6764(void);
u16 sub_080DABCC(u32 a);
u8 sub_080C32D4(u16 a);
u16 PalFade_AllDone(void);
void *PalFade_FadeRangeWithDuration(u16 start, u16 count, u16 delay, u16 duration);
void PalFade_Init(u32 keepPalettes);
void sub_080C0074(u8 a, u32 b, u32 c);
void sub_080BF938(u8 a);
void sub_080C1440(void);
u32 Title_HasExtraUnlocked(void);
u32 SaveSlot_AnyValid(void);
u32 SaveSlot_IsValid(u32 slot);
void *PalFade_FadeInFromBlack(u16 delay);
void *PalFade_FadeToBlack(u16 delay);
void sub_080C1450(void);
void Task_ClearAll(void);
void VBlankTasks_Init(void);
void sub_080C5170(u16 se);
void SetMainCallback(void (*func)(void));
void Task_RunAll(void);
void Window_Close(u32 win, u32 erase);
void Text_DrawSpriteString(const u16 *str, u16 a1, u16 a2, u16 x, u16 y, u16 advance);
void LZ77UnCompWram(const void *src, void *dst);
void Palette_CopyWithEffect(u32 a0, const void *src, void *dst, u32 size, u32 a4);
u32 Window_Create(u16 x, u16 y, u16 w, u16 h, u16 bg);
void *PalFade_FadeRangeToBlack(u16 start, u16 count, u16 delay);
struct Task *Task_GetParent(struct Task *task);
u16 sub_080C2244(void);
void sub_080ECA60(u32 a0, u32 a1, u32 a2, u32 a3);
u32 sub_080ECB10(void);
u32 sub_080C4618(u16 a0, u16 a1, u16 a2, u16 a3, u32 a4, u32 a5);
void sub_080AF178(u16 a, const void *script);
s32 sub_081571DC(u16 id);
void sub_080C30AC(s32 v);
void sub_080C33AC(u16 a);
void sub_080C3328(u16 a);
void sub_080C062C(u16 a);
void sub_080C0290(u8 a, u32 b);
void sub_080C48F0(u32 h, u32 a);
void sub_080C51BC(u32 a);
u32 Palette_IsBg13Black(void);
void Flag_Clear(u32 flag);
void sub_080CCE5C(const void *str, u32 x, u32 y, u32 a3);
void sub_080CCF44(u32 num, u32 x, u32 y, u32 a3);
s32 sub_0815B864(u32 id);
void Tilemap_CopyRectStride(const u16 *src, u16 (*dst)[32], u16 tileAdd, u16 palette, u16 x, u16 y, u16 w, u16 h, u16 srcWidth);
u8 *sub_080C3560(u16 item);
void sub_080DA5DC(struct Task *task);
void sub_080DA608(struct Task *task);
void sub_080DF954(u32 a0, void *a1, void *a2);

/* Status screen (menu_d.c) */
void sub_080D1F0C(void);
void sub_080D1FFC(void);
void sub_080D2028();
void sub_080D21C4(u16 *x, u16 *y);
void sub_080D21F8();
u16 Action_CountDescriptionBreaks(u16 id);
void sub_080D2D58(void);
void Item_RenderDescription(u32 arg0);

/* This region */
void sub_080D2F04(u16 id, u16 x, u16 y);
void sub_080D3170(u16 idx, u16 x, u16 y, u16 flag);
void sub_080D3698(void);
s32 sub_080D3B58(u16 id, u16 flag);
void ComboBits_Set(u16 i);
void sub_080D3E64(void);
void sub_080D3EA0(void);
void sub_080D40AC(void);
void sub_080D3F04(struct Task *task, u32 id, u32 vblank);
s32 sub_080D45B8(u16 id);
u32 ComboBits_Test(u16 i);
void sub_080D3EC8(void);
void sub_080D49C8(void);
void sub_080D4A84(void);
u16 Keypad_GetKeyPalette(u16 pos);
void sub_080D4C58(struct Task *task);
void Keypad_DrawKeys(struct Task *task);
u32 Keypad_GetNumber(void);
void sub_080D54F0(void);
void sub_080D54FC(void);
void sub_080D59E8(void);
void sub_080D5A48(void);
void sub_080D5B64(void);
void sub_080D5B8C(u16 mode);
void sub_080D5BE4(void);
u16 sub_080D45F0(u16 *list, u16 a1);

#endif /* GUARD_MENU2_H */
