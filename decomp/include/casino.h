#ifndef GUARD_CASINO_H
#define GUARD_CASINO_H

/* Casino minigames, 0x0813EE90-0x08145783: scene loading and the Super 27, Lucky Symbol and
   Joker and Stars games. */

#include "global.h"

typedef void (*VoidFunc)(void);

#define DmaSet(dmaNum, src, dest, control)                      \
{                                                               \
    vu32 *dmaRegs = (vu32 *)(0x040000B0 + 12 * (dmaNum));       \
    dmaRegs[0] = (vu32)(src);                                   \
    dmaRegs[1] = (vu32)(dest);                                  \
    dmaRegs[2] = (vu32)(control);                               \
    dmaRegs[2];                                                 \
}

#define DMA_FILL(dmaNum, value, dest, size, bit)                                    \
{                                                                                   \
    vu##bit tmp = (vu##bit)(value);                                                 \
    DmaSet(dmaNum, &tmp, dest, (0x8000 | (bit == 32 ? 0x0400 : 0) | 0x0100) << 16 | ((size) / (bit / 8))); \
}

#define DmaFill32(dmaNum, value, dest, size) DMA_FILL(dmaNum, value, dest, size, 32)
#define DmaCopy32(dmaNum, src, dest, size) DmaSet(dmaNum, src, dest, (0x8000 | 0x0400) << 16 | ((size) / 4))

#define CpuFill32(value, dest, size)                                     \
{                                                                        \
    vu32 tmp = (vu32)(value);                                            \
    CpuSet((void *)&tmp, dest, 0x05000000 | ((size) / 4 & 0x1FFFFF));    \
}

/* Casino scene header (0x0203B554, 0x300 bytes cleared on entry). */
struct CasinoScene
{
    u16 game;   /* index into the init/update tables 0x0879241C/0x0879243C */
    u16 arg;
};

/* Super 27 state (0x0203A454, 0x800 bytes cleared by Super27_Init). Three reels of 24
   symbols; sym[r][0..5] are the reel's six visible strip indices. */
struct Super27Card
{
    s32 value;
    u16 marked;
    u16 pad6;
};

struct Super27Line
{
    u32 index;
    u16 x;
    u16 y;
    u8 unk8;
    u8 pad9[3];
};

struct Super27
{
    u16 init;           /* 0x00 */
    u16 unk02;
    u16 mode;           /* 0x04 */
    u16 round;          /* 0x06 */
    u16 phase;          /* 0x08 */
    u16 reelPos[3];     /* 0x0A */
    u16 timer;          /* 0x10 */
    u16 blink;          /* 0x12 */
    u16 unk14;          /* 0x14 */
    u16 anim;           /* 0x16 */
    u16 unk18;          /* 0x18 */
    u16 heldCount;      /* 0x1A */
    u16 unk1C;          /* 0x1C */
    u16 unk1E;          /* 0x1E */
    u16 unk20;          /* 0x20 */
    u16 scroll;         /* 0x22 */
    u16 unk24;          /* 0x24 */
    u16 unk26;          /* 0x26 */
    u16 unk28;          /* 0x28 */
    u16 unk2A;          /* 0x2A */
    u16 unk2C;          /* 0x2C */
    u16 unk2E;          /* 0x2E */
    s32 win;            /* 0x30 */
    u32 target;         /* 0x34 */
    u16 line;           /* 0x38 */
    u16 unk3A;
    s32 coins;          /* 0x3C */
    u16 cardFound;      /* 0x40 */
    u16 rand;           /* 0x42 */
    u16 cardCount;      /* 0x44 */
    u16 sym[3][6];      /* 0x46 */
    u16 held[3];        /* 0x6A */
    s32 lineSym[3];     /* 0x70 */
    u16 reelOfs[3];     /* 0x7C */
    u16 unk82;
    struct Super27Card cards[6];  /* 0x84 */
    s32 winSym;         /* 0xB4 */
    struct Super27Line lines[3];  /* 0xB8; lines[2].unk8 (0xD8) is the start flag */
};

struct Super27Reel
{
    s32 sym;
    const void *sprite;
    const void *litSprite;
};

/* Pay table row (0x08794CDC, 9 symbols): sprite and position of the row on the pay board,
   the payout; symbol 8's row holds five random bonus amounts. */
struct Super27Pay
{
    const void *sprite;
    u16 x;
    u16 y;
    u16 pay[5];
    u16 pad;
};

extern struct Super27Pay gUnknown_08794CDC[];
extern const void *gUnknown_08794DFC[];

extern struct Super27Reel gUnknown_0879245C[][24];
extern struct Super27Reel gUnknown_087931DC[][24];
extern struct Super27Reel gUnknown_08793F5C[][24];
extern struct Super27Reel gUnknown_08794D90[];

/* Lucky Symbol state (0x0203A454, cleared by LuckySymbol_Init). Four reels of 24 symbols;
   up to three reels can be held (Left/Up/Right/Down). */
struct LuckyLine
{
    u32 index;          /* strip index of the symbol on the winning line */
    u8 layer;
    u8 pad5[3];
    u32 unk8;
};

struct LuckySymbol
{
    u16 init;           /* 0x00 */
    u16 unk02;
    u8 mode;            /* 0x04 */
    u8 reelOfs[4];      /* 0x05 */
    u8 held[4];         /* 0x09 */
    u8 pad0D;
    u16 reelPos[4];     /* 0x0E */
    u8 unk16[2];        /* 0x16 */
    s32 lineSym[4];     /* 0x18: middle-row symbol of each reel */
    u8 holdEnabled;     /* 0x28 */
    u8 heldCount;       /* 0x29 */
    u8 unk2A;           /* 0x2A */
    u8 phase;           /* 0x2B: spin phase 0-5 */
    u16 timer;          /* 0x2C */
    u8 round;           /* 0x2E */
    u8 unk2F;           /* 0x2F */
    u8 bonus;           /* 0x30: bonus symbol score */
    u8 unk31;           /* 0x31 */
    u8 unk32;           /* 0x32 (also read as a u16) */
    u8 unk33;           /* 0x33 */
    u8 rand;            /* 0x34 */
    u8 unk35;
    u16 bet;            /* 0x36 */
    u8 unk38;           /* 0x38 */
    u8 unk39;           /* 0x39 */
    u8 unk3A[2];
    s32 coins;          /* 0x3C */
    s32 win;            /* 0x40 */
    s32 payout;         /* 0x44 */
    s32 savedCoins;     /* 0x48 */
    s32 step;           /* 0x4C */
    u8 unk50;           /* 0x50 */
    u8 unk51;           /* 0x51 */
    u8 unk52;           /* 0x52 */
    u8 unk53;           /* 0x53 */
    u8 count;           /* 0x54 */
    u8 blink;           /* 0x55 */
    u8 unk56;           /* 0x56 */
    u8 unk57;           /* 0x57 */
    u8 newLamp[8];      /* 0x58: lamp lit this bonus game (blinking) */
    u8 lamp[8];         /* 0x60: pattern lamps */
    u16 sym[4][6];      /* 0x68 */
    u8 marks[13];       /* 0x98: bonus meter */
    u8 marksLeft;       /* 0xA5 */
    u8 markIdx;         /* 0xA6 */
    u8 marksDone;       /* 0xA7 */
    u16 markTimer;      /* 0xA8 */
    u8 unkAA[6];        /* 0xAA */
    struct LuckyLine lines[3];  /* 0xB0 */
    u32 line3Index;     /* 0xD4: fourth line, without the trailing word */
    u8 line3Layer;      /* 0xD8 */
    u8 padD9[3];
    u32 pattern;        /* 0xDC: winning pattern 0-7 */
    u8 unkE0[8];        /* 0xE0 */
    u8 started;         /* 0xE8 */
};

extern struct Super27Reel gUnknown_0879505C[][24];
extern struct Super27Reel gUnknown_08795DDC[][24];
extern struct Super27Reel gUnknown_08796B5C[][24];
extern struct Super27Reel gUnknown_087978DC[][24];

/* Pay board row: sprite and position. */
struct CasinoBoardRow
{
    const void *sprite;
    u16 x;
    u16 y;
    u16 pay[2];         /* three / four of a kind */
};

struct CasinoSpritePos
{
    const void *sprite;
    u16 x;
    u16 y;
};

extern struct CasinoBoardRow gUnknown_0879865C[];
extern struct CasinoSpritePos gUnknown_087986E4[];
extern const u8 gUnknown_0814F314[], gUnknown_0814F344[], gUnknown_0814F374[], gUnknown_0814F2E4[];
extern const u8 gUnknown_0814F10C[], gUnknown_0814F124[], gUnknown_0814F13C[], gUnknown_0814F154[];
extern const u8 gUnknown_0814F16C[], gUnknown_0814F184[], gUnknown_0814F19C[], gUnknown_0814F1B4[];
extern const u8 gUnknown_0814F1F4[], gUnknown_0814F204[], gUnknown_0814F214[], gUnknown_0814F224[];
extern const void *gUnknown_087986BC[];
extern const u8 gUnknown_0814F508[], gUnknown_0814F29C[], gUnknown_0814F2CC[], gUnknown_0814F2FC[];
extern const u8 gUnknown_0814F32C[], gUnknown_0814F35C[], gUnknown_0814F1CC[], gUnknown_0814F1E4[];
extern const u32 gUnknown_0879874C[];
extern vu16 gKeysNew;
extern vu16 gRepeatedKeys;

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
    u16 result;         /* 0x1C: condition result of a script command */
    u16 unk1E;
    void (*onFrame)(struct Task *);
    union
    {
        u32 w[0x10];
        u16 h[0x20];
        s16 sh[0x20];
        u8 raw[0x40];
    } data;             /* 0x24 */
};

/* Joker and Stars state (0x0203A454, cleared by JokerStars_Init). Nine reels in a 3x3 grid;
   reel positions are 16.16 pixels over a 480-pixel strip (24 symbols of 20 pixels). */
union JokerPos
{
    s32 v;
    struct
    {
        u16 frac;
        s16 px;
    } p;
    u16 h[2];
};

struct JokerStars
{
    u16 state;          /* 0x00: 1 start, 2 play, 3 quit */
    u16 unk02;
    union JokerPos pos[9];      /* 0x04 */
    struct Task *tasks[9];      /* 0x28: reel stop tasks */
    u16 shade[9];       /* 0x4C: palette row of each reel's graphics */
    u16 hl[9];          /* 0x5E: highlighted reels */
    const u16 *strip[9];        /* 0x70 */
    u16 spinning;       /* 0x94 */
    u16 unk96;          /* 0x96 */
    u32 bet;            /* 0x98: paylines bet (0-8) */
    u32 unk9C;          /* 0x9C */
    s32 win;            /* 0xA0 */
    u16 unkA4;          /* 0xA4 */
    u16 starsLeft;      /* 0xA6 */
    u16 stars;          /* 0xA8 */
    u8 padAA[0x42];     /* 0xAA */
    u16 slotFrame[20];  /* 0xEC: sprite slots */
    u16 slotX[20];      /* 0x114 */
    u16 slotY[20];      /* 0x13C */
};

struct JokerPosXY
{
    u32 x;
    u32 y;
};

extern const void *const *gUnknown_0879A264[];
extern const void *gUnknown_0879A29C[];
extern const u16 gUnknown_0879A2C4[][2];
extern const void *gUnknown_0879A2E4[];
extern const u16 *gUnknown_0879C6A4[][9];
extern const u16 gUnknown_0879C7C4[];
extern const void *gUnknown_0879A16C[];
extern struct JokerPosXY gUnknown_0879A190[];
extern const u32 gUnknown_0879A304[], gUnknown_0879AA3C[], gUnknown_0879AA94[];
extern const u32 gUnknown_0879AC18[][3];
extern const void *gUnknown_0879A928[];
extern const void *gUnknown_0879AA24[];
extern const u32 gUnknown_0879A5EC[], gUnknown_0879A610[], gUnknown_0879A6C4[];
extern const u32 gUnknown_0879A778[], gUnknown_0879A808[], gUnknown_0879A898[];
extern const u32 gUnknown_0879A52C[];
extern const u32 gUnknown_0879A548[];
extern const u32 gUnknown_0879A56C[];
extern const u8 gUnknown_0879896C[];
extern vu16 gUnk_030031D0;

/* Engine functions */
void SetMainCallback(VoidFunc func);
void Task_RunAll(void);
void VBlankTask_AddCounted(VoidFunc func, u32 count);
void Palette_CopyWithEffect(u32 a0, const void *src, void *dst, u32 a3, u32 a4);
void *PalFade_FadeInFromBlack(u16 delay);
void *PalFade_FadeToBlack(u16 delay);
void Sprite_Draw(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
void Sound_Play(u32 se);
struct Task *Task_Create(const void *script, u32 parent);
void Font_ResetGlyphSpriteCache(u32 baseTile);
void sub_080C1450(void);
void sub_080AB1A8(void);
s32 sub_080C31F0(void);
u8 *NumberToDigits(u32 n);
u32 Random_Byte(void);
extern u32 gFrameCounter;

/* This region */
void Casino_Start(u16 game, u16 arg);
void Casino_InitCallback(void);
void Casino_MainCallback(void);
void CasinoScene_LoadTiles(u32 unused, const void *src, u32 slot);
void CasinoScene_DmaBgTiles(void);
void CasinoScene_QueueBgTiles(void);
void CasinoScene_DmaObjTiles(void);
void CasinoScene_QueueObjTiles(void);
void CasinoScene_LoadBgPalette(u32 unused, const void *src);
void CasinoScene_LoadObjPalette(u32 unused, const void *src);
void CasinoScene_DmaBgMap0(void);
void CasinoScene_DmaBgMap1(void);
void CasinoScene_DmaBgMap2(void);
void CasinoScene_DmaBgMap3(void);
void CasinoScene_LoadBgMap(u32 unused, const void *src, u32 layer);
void CasinoScene_FadeIn(void);
void CasinoScene_FadeOut(void);
void sub_0813F15C(void);
void Super27_Init(void);
void Super27_Update(void);
void Super27_UpdateReelStrips(void);
void Super27_DrawReels(void);
void Super27_DrawHoldMarkers(void);
void Super27_DrawCards(void);
void Super27_CheckMiddleLine(void);
void Super27_ScanBonusLine(void);
void Super27_DrawWinHighlight(void);
void Super27_MarkCard(void);
void Super27_DrawMarkedCards(void);
void Super27_ClearHolds(void);
void Super27_SetPayout(void);
void Super27_DrawNumber(u32 value, u16 x, u16 y, u16 priority);
void Super27_CountPayout(void);
void Super27_SetInit(u32 unused, u16 value);
void LuckySymbol_Init(void);
void LuckySymbol_Update(void);
void LuckySymbol_UpdateReelStrips(void);
void LuckySymbol_DrawReels(void);
void LuckySymbol_DrawNumber(u32 value, u16 x, u16 y, u16 priority);
u32 Number_LeadingPowerOf10(u32 n);
void LuckySymbol_CountWin(void);
void LuckySymbol_PayWin(void);
void LuckySymbol_SpinReels(void);
void LuckySymbol_BlinkWinLine(void);
void LuckySymbol_DrawWinLine(void);
void LuckySymbol_CheckLine(void);
void LuckySymbol_CountBonusSymbols(void);
void LuckySymbol_DrawBonusMeter(void);
void LuckySymbol_ApplyBonus(void);
void LuckySymbol_SetPayout(u16 four);
void LuckySymbol_DrawHoldMarkers(void);
void LuckySymbol_LightLamps(void);
void LuckySymbol_DrawLamps(void);
void LuckySymbol_BlinkNewLamps(void);
void LuckySymbol_ApplyMultipliers(void);
void LuckySymbol_SetInit(u32 unused, u16 value);
void JokerStars_DrawSlot(u16 slot, u16 x, u16 y);
void JokerStars_SetSlot(u16 slot, u16 frame, u16 x, u16 y);
void JokerStars_SetSlotPos(u16 slot, u16 frame, u16 x, u16 y);
void JokerStars_DrawNumber(u32 value, u16 digits, u16 x, u16 y);
void JokerStars_DrawPaylines(void);
void JokerStars_RandomizeReel(u16 reel);
void JokerStars_RenderReels(void);
void JokerStars_RenderReel(u16 reel, s16 px, const u16 *strip);
void JokerStars_DmaReelTiles(void);
void JokerStars_CopyPixelRow(const u32 *src, u32 *dst);
void JokerStars_MoveReel(u16 reel, s32 speed);
void sub_08145124(u16 x, u16 y, u16 count, const u32 *table);
void JokerStars_DrawPayTable(void);
void sub_081451FC(void);
void JokerStars_Quit(void);
u16 JokerStars_GetReelSymbol(u16 reel);
struct Task *sub_08145378();
void sub_081453E4(struct Task *task, u32 reel);
u32 JokerStars_CountStars(void);
void sub_08145578(void);
void sub_081455C0(u16 sym);
void sub_081457FC(void);
s32 JokerStars_CheckLine(u32 a, u32 b, u32 c);
void sub_080C31B4(s32 delta);
void sub_080C31FC(s32 coins);
void sub_080BE4C4(void);

extern u8 gUnk_02000000[];
extern u8 gMenuState[];
extern u16 gUnk_03000002, gUnk_03000040;
extern u8 gBgPictureBuffer[];
extern u16 gPaletteTarget[0x200];
extern const u8 gUnknown_0814ECA0[], gUnknown_0814ECB0[], gUnknown_0814ECC0[];
extern const u8 gUnknown_0814EC10[], gUnknown_0814EC28[], gUnknown_0814EC40[], gUnknown_0814EC58[];
extern const u8 gUnknown_0814EC70[], gUnknown_0814EC80[], gUnknown_0814EC90[], gUnknown_0814ECD8[];
extern const u8 gUnknown_0814ECE8[], gUnknown_0814ED00[], gUnknown_0814EDB8[], gUnknown_0814EDD0[];
extern const u8 gUnknown_0814EDE8[], gUnknown_0814EE00[];
extern const u32 gUnknown_08794E24[];
extern const u8 gUnknown_087A4FA8[], gUnknown_087A51AC[];
extern u16 gDispRegs;
extern VoidFunc gUnknown_0879241C[];
extern VoidFunc gUnknown_0879243C[];

#endif
