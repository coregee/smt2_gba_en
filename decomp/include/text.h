#ifndef GUARD_TEXT_H
#define GUARD_TEXT_H

#include "global.h"

/* The pret DmaSet idiom: the trailing read of the control register is in the original. */
#define TEXT_DMA3_SET(src, dest, control)                \
{                                                        \
    vu32 *dmaRegs = (vu32 *)0x040000D4;                  \
    dmaRegs[0] = (u32)(src);                             \
    dmaRegs[1] = (u32)(dest);                            \
    dmaRegs[2] = (u32)(control);                         \
    dmaRegs[2];                                          \
}

/* Window frame drawn into a BG tilemap buffer (lives in Task.data). */
struct TextWindow
{
    u16 x;              /* tiles */
    u16 y;
    u16 w;
    u16 h;              /* target height */
    u16 screen;         /* which VRAM screenblock to flush to, see TextWindow_QueueTilemapUpload */
    u16 curH;           /* height currently drawn (open/close animation) */
    u32 unk0C;
    const u16 *frame;   /* 9 tiles: corners/edges/fill; NULL = gDefaultWindowFrameTiles */
};

/* Two-option (yes/no) cursor sprite (lives in Task.data). */
struct YesNoCursor
{
    u32 unk0;
    s32 choice;         /* 0 or 1 */
    u32 tile;           /* OBJ tile number of the cursor graphics */
};

/* Script task: 64 slots of 100 bytes at 0x02009004 (gTasks). */
struct Task
{
    u16 state;          /* 0 free, 1 running, 0xFFFF paused */
    u16 id;
    u16 parent;
    u16 pad06;
    u32 op;             /* current opcode */
    s32 wait;           /* nonzero: run op's update handler instead of fetching */
    s32 pc;             /* index into script (words) */
    const u32 *script;
    u16 loopCount;
    u16 loopStart;
    u16 result;
    u16 unk1E;
    void (*onFrame)(struct Task *);
    union
    {
        struct TextWindow win;
        struct YesNoCursor yesNo;
        u16 h[0x20];
        u8 raw[0x40];
    } data;
};

extern u16 gWindowTilemapBuffer[32][32];      /* BG tilemap buffer */
extern s32 gOpenWindowCount;               /* open window count */
extern const u16 gDefaultWindowFrameTiles[9];  /* default window frame tiles */
extern const u32 gUnknown_0815EC40[];   /* window task script */

void sub_080AB9B0(void);
void sub_080AB9D0(void);
void TextWindow_UploadTilemapSbb4(void);
void TextWindow_UploadTilemapSbb6(void);
void VBlankTask_AddCounted(void (*func)(void), u32 arg);
void Tilemap_FillRect(u32 val, u16 *buf, u16 x, u16 y, u16 w, u16 h);
struct Task *Task_Create(const u32 *script, u32 parent);
void Task_End(struct Task *task);
void Hud_RenderGlyphTiles(void *dst, const void *src);
void Sound_Play(u32 se);
void Sprite_Draw(const void *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
/* OAM_EmitSprite (rom_layout.py): one sprite from a 3-u16 attribute template. */
void Sprite_DrawSingle(const void *tmpl, u16 a1, u16 palette, u16 a3, u16 tile, u16 x, u16 y);

extern u8 gBannerTiles[];              /* cursor graphics buffer */
extern u32 gUnk_03000048;               /* cursor OBJ tile */
extern u16 gKeysNew;               /* new keys */
extern s32 gYesNoResult;               /* last yes/no choice */
extern u16 gRepeatedKeys;               /* repeat keys */
extern const u8 gUnknown_0815ED28[];
extern const u8 gUnknown_08001058[];
extern const u8 gUnknown_0815ED30[];
extern const u8 gUnknown_0815ED38[];
extern const u32 gUnknown_0815ED40[];   /* yes/no task script */

/* ---- Main 16x16 font ----
   A glyph code's high byte selects a bank; in the bank, glyphs are 2bpp 8x8 tiles laid out as
   16 glyphs per 0x400-byte row: the top half of glyph (code & 0xFF) is the 32 bytes at
   ((code & 0xFF) >> 4) * 0x400 + (code & 0xF) * 0x20, the bottom half 0x200 bytes later. */
struct FontBank
{
    const u8 *glyphs;
    u32 unk4;
};

extern const struct FontBank gFontBankTable[];

/* Font_GetGlyphBitmap output: one glyph as 4bpp, 2x2 tiles in a 32-tile-wide canvas. */
extern u8 gGlyphBitmap[0x800];

/* OBJ glyph cache: up to `capacity` glyphs converted into gGlyphSpriteStaging (16 cells of 2x2
   tiles per 0x800-byte row) and DMA'd to OBJ VRAM at tile `baseTile`.  Slots are never freed
   individually; Font_ResetGlyphSpriteCache empties the cache. */
struct GlyphSpriteCache
{
    u16 baseTile;
    u16 count;
    u16 capacity;
    u16 uploadPending;
    u16 codes[64];
};

extern struct GlyphSpriteCache gGlyphSpriteCache;
extern u8 gGlyphSpriteStaging[];

u8 *Font_GetGlyphBitmap(u16 code);
void Font_SetGlyphSpriteCacheCapacity(u16 capacity);
void Font_ResetGlyphSpriteCache(u16 baseTile);
s16 Font_CacheGlyphSprite(u16 code);
void Font_UploadGlyphSpriteTiles(void);
s16 Font_FindGlyphSprite(u16 code);
void Font_CopyGlyphCell(u8 *bitmap, u8 *dst);
void FontSprite_DrawGlyph(u16 code, u16 a1, u16 a2, u16 x, u16 y);
void FontSprite_DrawGlyphTinted(u16 code, u16 a1, u16 a2, u16 x, u16 y, u16 palette);
void Text_DrawSpriteString(const u16 *str, u16 a1, u16 a2, u16 x, u16 y, u16 advance);
void Text_DrawSpriteStringTinted(const u16 *str, u16 a1, u16 a2, u16 x, u16 y, u16 advance, u16 palette);

extern const u16 gGlyphSpriteTemplate[];   /* 16x16 glyph sprite template */

#define TEXT_CODE_END      0x0000
#define TEXT_CODE_NEWLINE  0x0300
#define TEXT_CODE_END2     0x0301

u32 Random_Next(void);
extern u32 gRandomSeed;   /* random seed */
extern u32 gFrameCounter;   /* frame counter */

/* Byte holding pixel (x, y) of a 4bpp canvas 32 tiles (256 px) wide; low nibble = even x. */
#define CANVAS_PIXEL_BYTE(canvas, x, y)     ((canvas) + ((y) >> 3) * 0x400 + ((x) >> 3) * 32 + ((y) & 7) * 4 + ((x) & 7) / 2)

void Canvas_BlitOr(u8 *src, u8 *dst, u16 srcX, u16 srcY, u16 dstX, u16 dstY, u16 w, u16 h);

void Canvas_BlitOrTinted(u8 *src, u8 *dst, u16 srcX, u16 srcY, u16 dstX, u16 dstY, u16 w, u16 h, u8 tint);
void Canvas_FillRect(u8 color, u8 *dst, u16 x, u16 y, u16 w, u16 h);

void Font_DrawGlyph(u16 code, u8 *canvas, u16 x, u16 y);
void Text_DrawString(const u16 *str, u8 *canvas, u16 x, u16 y, u16 advance);
void Font_DrawGlyphTinted(u16 code, u8 *canvas, u16 x, u16 y, u8 tint);
void Text_DrawStringTinted(const u16 *str, u8 *canvas, u16 x, u16 y, u8 tint, u16 advance);
void SmallFont_DrawGlyph(u16 index, u8 *canvas, u16 x, u16 y);
void SmallFont_DrawGlyphTinted(u16 index, u8 *canvas, u16 x, u16 y, u8 tint);
void SmallFont_DrawAsciiTinted(const u8 *str, u8 *canvas, u16 x, u16 y, u8 tint, u16 advance);
void DigitFont_DrawGlyph(u16 index, u8 *canvas, u16 x, u16 y);
void DigitFont_DrawGlyphTinted(u16 index, u8 *canvas, u16 x, u16 y, u8 tint);
void DigitFont_DrawStringTinted(const u8 *str, u8 *canvas, u16 x, u16 y, u8 tint, u16 advance);
void System_CheckSoftReset(void);

extern u8 gSmallFontSheet[];          /* 8x8 small font sheet, 4bpp */
extern const u16 gUnknown_0815EE20[];   /* ASCII 0x20.. -> small font index */
extern const u16 gUnknown_0815EE96[];   /* '0'..'9' -> 8x10 digit index */
extern u8 gUnk_03003970;
extern u16 gUnk_030031D0;               /* held keys */

/* Global color effect applied by Color_ApplyEffect (mode from sub_080C2C70). */
struct ColorEffect
{
    s16 r, g, b;        /* mode 1: +n brightens by n/256 toward white, -n darkens */
    s16 desat;          /* other modes: percent of half the channel spread to remove */
};

extern struct ColorEffect gColorEffect;
u16 sub_080C2C70(void);
u16 Color_ApplyEffect(u16 color);

/* ---- Script tasks ---- */
#define TASK_COUNT        64
#define TASK_OP_LABEL     0x10241224   /* followed by the label id; skipped when run */
#define TASK_STATE_FREE   0
#define TASK_STATE_RUN    1
#define TASK_STATE_PAUSED 0xFFFF

struct TaskOp
{
    void (*start)(struct Task *task);   /* when the op is fetched (args at gTaskOpArgs) */
    void (*update)(struct Task *task);  /* every frame while task->wait != 0 */
};

extern struct Task gTasks[TASK_COUNT];
extern const u32 *gTaskOpArgs;              /* current op's argument words */
extern const struct TaskOp gTaskOpTable[];

void Task_ClearAll(void);
void Task_RunAll(void);
s32 Task_FindFreeSlot(void);
void Task_Pause(struct Task *task);
bool32 Task_IsPaused(struct Task *task);
void Task_Resume(struct Task *task);
void Task_GotoLabel(struct Task *task, u32 label);
u16 Task_GetState(struct Task *task);
void Task_Signal(struct Task *task);
struct Task *Task_GetParent(struct Task *task);

#endif /* GUARD_TEXT_H */
