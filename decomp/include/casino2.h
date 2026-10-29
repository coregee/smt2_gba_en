#ifndef GUARD_CASINO2_H
#define GUARD_CASINO2_H

/* Casino minigames, 0x08145784-0x0814A413. */

#include "global.h"

#define DmaSet3(src, dest, control)              {                                                    vu32 *dmaRegs = (vu32 *)(REG_BASE + 0xD4);       dmaRegs[0] = (vu32)(src);                        dmaRegs[1] = (vu32)(dest);                       dmaRegs[2] = (vu32)(control);                    dmaRegs[2];                                  }

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

/* Task data (task + 0x24) as most minigame tasks use it. */
struct C145TaskData
{
    u16 h0;             /* 0x24 */
    u16 h2;             /* 0x26 */
    u16 h4;             /* 0x28 */
    u16 h6;             /* 0x2A */
    u32 w8;             /* 0x2C */
};

/* gMenuState (0x0203A454) as the casino games use it. */
struct CasinoState
{
    u16 unk00;
    u8 pad02[0x4A];
    u16 lit[9];         /* 0x4C */
    u8 pad5E[0x38];
    u16 unk96;
    u32 unk98;          /* 0x98: bet */
    u32 unk9C;
    u32 unkA0;          /* 0xA0: coins in play */
    u8 padA4[8];
    u32 lineSym[3];     /* 0xAC: symbols on the line being checked, jokers replaced */
    u32 lineOrig[3];    /* 0xB8: the same before replacement */
    u32 wild;           /* 0xC4: symbol the jokers stand for */
    u32 cellWin[9];     /* 0xC8 */
};

/* Baccarat state in gMenuState. */
struct BaccaratObj
{
    s8 frame;           /* 0x00 */
    u8 unk01;
    u16 x;              /* 0x02 */
    u16 y;              /* 0x04 */
    u16 unk06;
};

struct BaccaratCard
{
    u8 suit;            /* 0x00 */
    u8 rank;
    u16 pos;            /* 0x02 */
    u16 target;         /* 0x04 */
    u16 unk06;
    u16 unk08;
    u8 unk0A;
    u8 unk0B;
};

struct BaccaratRec
{
    u8 unk00;
    u8 pad01[3];
    u16 unk04;
    u16 pad06;
};

struct Baccarat
{
    u16 state;                  /* 0x000 */
    u8 pad002[2];
    u8 phase;                   /* 0x004 */
    u8 pad005[3];
    u32 coins;                  /* 0x008 */
    u32 coinsTarget;            /* 0x00C */
    u32 bet[3];                 /* 0x010 */
    u8 cursor;                  /* 0x01C: x of the bet cursor, 0x1E/0x37/0x50 */
    u8 unk01D;
    u8 betPlayer;               /* 0x01E: set while a player bet stands */
    u8 betBanker;               /* 0x01F: set while a banker bet stands */
    u8 unk020;
    u8 pad021[3];
    u8 unk024;
    u8 unk025;
    u8 unk026;
    u8 pad027;
    u16 suit;                   /* 0x028: drawn card */
    u16 rank;                   /* 0x02A */
    u16 dealt;                  /* 0x02C: cards dealt so far */
    u8 duplicate;               /* 0x02E */
    u8 winner;                  /* 0x02F: 0 player, 1 banker, 2 tie */
    u8 result;                  /* 0x030 */
    u8 unk031;
    u8 unk032;
    u8 pad033[2];
    u8 unk035;                  /* 0x035: card being turned */
    u8 unk036;
    u8 pad037;
    u8 unk038;
    u8 unk039;
    u16 unk03A;
    u16 unk03C;                 /* 0x03C */
    u16 unk03E;
    u16 unk040;
    u8 unk042;
    u8 pad043;
    u16 unk044;                 /* 0x044: results recorded on the road */
    u16 unk046;
    struct BaccaratRec rec[64]; /* 0x048 */
    u16 unk248;
    u8 pad24A[2];
    struct BaccaratObj obj[3];  /* 0x24C */
    struct BaccaratCard card[6];/* 0x264 */
    u8 gfxSuit[6];              /* 0x2AC */
    u8 gfxRank[6];              /* 0x2B2 */
    u8 unk2B8;
    u8 unk2B9;
};

/* Keno-like 8x8 number game state in gMenuState (0x081485A0-). */
struct C145Grid
{
    u16 state;                  /* 0x000 */
    u16 menu;                   /* 0x002: bit 15 = no menu cursor */
    u16 mark[64];               /* 0x004: bit 15 = marked by the player */
    u16 sprFrame[20];           /* 0x084 */
    u16 sprX[20];               /* 0x0AC */
    u16 sprY[20];               /* 0x0D4 */
    u16 cursorX;                /* 0x0FC */
    u16 cursorY;                /* 0x0FE */
    u16 cursorAnim;             /* 0x100 */
    u16 cell[64];               /* 0x102 */
    u16 pad182;
    u32 marked;                 /* 0x184: numbers marked, at most 16 */
    u32 drawn;                  /* 0x188 */
    u32 hits;                   /* 0x18C */
    u32 bet;                    /* 0x190 */
    u32 coins;                  /* 0x194 */
    u16 unk198;                 /* 0x198: blend coefficients, pulsed */
    s16 unk19A;
    u16 unk19C;
    s16 unk19E;
    u8 history[16][8];          /* 0x1A0: drawn numbers of the last 16 rounds, one bit each */
    u8 historyRow;              /* 0x220 */
    u8 lastHit;                 /* 0x221 */
    u8 pad222[2];
    u32 payout;                 /* 0x224 */
    u32 unk228;                 /* 0x228 */
    void *fade;                 /* 0x22C */
};

/* State of the game set up by 0x08149BBC, in gMenuState. */
struct C145Game5
{
    u16 state;                  /* 0x000 */
    u8 pad002[2];
    u8 phase;                   /* 0x004 */
    u8 pad005;
    u16 timer;                  /* 0x006 */
    u16 blink;                  /* 0x008 */
    u16 unk00A;
    u16 unk00C;
    u8 unk00E;
    u8 unk00F;
    u8 unk010;
    u8 pad011;
    u16 card;                   /* 0x012: 0-4 small, 5+ big */
    u16 unk014;
    u8 pickBig;                 /* 0x016 */
    u8 pickSmall;               /* 0x017 */
    u8 unk018;
    u8 unk019;
    u8 streak;                  /* 0x01A: doublings won; 99 = lost */
    u8 unk01B;
    u8 pad01C[2];
    u16 unk01E;
    u8 pad020[2];
    u16 unk022;
    u8 pad024;
    u8 unk025;
    u8 unk026;
    u8 unk027;
    u32 coins;                  /* 0x028 */
    s32 shown;                  /* 0x02C */
    s32 target;                 /* 0x030 */
    u32 unk034;
    s32 step;                   /* 0x038 */
    u8 pad03C[4];
    u16 unk040;
    u16 unk042;
    u16 unk044;
    u8 pad046[4];
    u8 unk04A[10];
    u8 pad054[6];
    u16 unk05A;
    u16 unk05C;
    u8 pad05E[0x204];
    u16 variant;                /* 0x262: by casino (gUnk_03004614) */
    u8 unk264;
};

extern u16 gMenuState[];
#define gBaccarat ((struct Baccarat *)gMenuState)
#define gGrid ((struct C145Grid *)gMenuState)
#define gGame5 ((struct C145Game5 *)gMenuState)
#define gCasino ((struct CasinoState *)gMenuState)

extern u32 gFrameCounter;
extern u16 gRepeatedKeys;

struct Task *Task_Create(const void *script, u32 parent);
void Sound_Play(u32 se);
void sub_080C31B4(s32 delta);
u16 JokerStars_GetReelSymbol(u16 cell);
void sub_08145488(struct Task *task, u16 a, u16 b);
void JokerStars_SetSlot(u16 a, u32 b, u32 c, u32 d);
u32 Casino_GetCountStep(u32 n);
u32 JokerStars_CountStars(void);
void CpuSet(const void *src, void *dest, u32 control);
u32 sub_080C31F0(void);
u8 *NumberToDigits(u32 n);
#ifdef CASINO2_SPRITE_DRAW_KR
/* The original file had no prototype in scope: arguments are passed unnarrowed. */
void Sprite_Draw();
#else
/* y as the callers here pass it (never narrowed). */
void Sprite_Draw(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u32 y);
#endif
extern u16 gDispRegs, gUnk_03000002, gUnk_03000040, gUnk_03000042, gUnk_03000044;
extern const void *const gUnknown_0879C7F4[];
extern const u8 gUnknown_081501DC[], gUnknown_081501AC[], gUnknown_08150454[], gUnknown_08150464[];
extern const u8 gUnknown_08150414[], gUnknown_0815042C[], gUnknown_08150444[], gUnknown_081503FC[];
extern const u8 gUnknown_08150348[];
extern const void *const gUnknown_0879C8D4[];
extern const u8 gUnknown_08150384[], gUnknown_0815039C[], gUnknown_081503B4[], gUnknown_081503CC[], gUnknown_081503E4[];
extern const u8 gUnknown_08150360[];
u32 Random_Byte(void);
void Baccarat_SetCardFace(u16 slot, u32 suit, u32 rank);
void VBlankTask_AddCounted(void (*func)(void), u32 count);
void sub_081484C8(void);
void sub_081484D4(void);
void sub_081484E0(void);
void sub_081484EC(void);
void sub_081484F8(void);
void sub_08148504(void);
extern const u8 gUnknown_08150284[], gUnknown_0815029C[], gUnknown_081502CC[], gUnknown_081502B4[], gUnknown_081502FC[];
extern const u8 gUnknown_08150314[], gUnknown_08150330[], gUnknown_081501F4[], gUnknown_0815023C[];
extern s16 gUnk_0300000C;
void Baccarat_ScrollRoad(void);
void sub_08147F68(void);
void sub_08147DB8(void);
void sub_08147E90(void);
struct BaccaratPos { s16 x, y; };
extern const struct BaccaratPos gUnknown_0879C92C[];
extern const void *const gUnknown_0879C820[];
extern const void *const gUnknown_0879C84C[];
extern const void *const gUnknown_0879C878[];
extern const void *const gBaccaratCardGfx[];
extern u32 gUnk_03003BB4;
void HuffUnComp(const void *src, void *dest);
void LZ77UnCompWram(const void *src, void *dest);
void Baccarat_UploadCardFace(u16 slot);
extern const void *const gUnknown_0879CE24[];
extern const void *const gUnknown_0879CE58[];
extern const void *const *const gUnknown_0879CEA8[];
void sub_08148718(u16 i, u16 frame, u16 x, u16 y);
void sub_08148754(u16 i, u16 frame, u16 x, u16 y);
void sub_081487C8(void);
void Keno_RecordHistory(void);
extern const u16 gUnknown_0879CEBC[][17];
extern const u8 gUnknown_081513A4[];
void Palette_CopyWithEffect(u32 a0, const void *src, void *dst, u32 a3, u32 a4);
u32 sub_081490E4(u32 step, u32 target);
void sub_08149120(struct Task *task, u32 step, u32 target);
extern const u32 gUnknown_0879D338[][13];
extern const u8 gUnknown_081519E8[], gUnknown_081519D0[], gUnknown_081519B4[];
void sub_080C31FC(u32 coins);
extern u16 gUnk_030031D0;               /* held keys */
void *PalFade_FadeRangeToWhite(u16 start, u16 count, u16 delay);
void *PalFade_FadeRangeWithDuration(u16 start, u16 count, u16 delay, u16 duration);
u16 PalFade_IsActive(void *fade);
extern const u8 gUnknown_0879D6AC[], gUnknown_0879DA00[], gUnknown_087B59DC[];
extern const void *const gUnknown_0879DDAC[];
extern const u16 gUnknown_0879DA14[][9];
extern const u32 gUnknown_0879DB48[][9];
extern const u8 gUnknown_08151B68[], gUnknown_08151B50[], gUnknown_08151B40[], gUnknown_08151B28[];
u32 sub_0814966C(u16 v, u16 a, u16 x, u16 y);
void sub_08149A10(void);
extern u32 gUnk_03004614;
extern const u8 gUnknown_0814F790[], gUnknown_0814F7A8[];
extern const void *const gUnknown_0879DDD4[];
s32 BigSmall_GetCountStep(u32 n);
extern vu16 gKeysNew;
extern const u8 gUnknown_0879E354[];
extern const u8 gUnknown_0814F824[], gUnknown_0814F7F4[], gUnknown_0814F888[], gUnknown_0814F858[];
extern const u8 gUnknown_0814F958[], gUnknown_0814F83C[], gUnknown_0814F8A0[], gUnknown_0814F768[];
extern const u8 gUnknown_0814F778[], gUnknown_0814F870[], gUnknown_0814F80C[];
extern const void *const gUnknown_0879DDFC[];
void sub_0814A1FC(void);
void BigSmall_DrawNumber6(u32 n, u16 x, u16 y, u16 priority);
void BigSmall_CountUpCoins(void);
void sub_0814A8B0(void);
void sub_0814AA04(void);
void sub_0814A684(void);
void sub_0814A568(void);
void sub_0814A5F0(void);
void sub_0814A4DC(void);
void BigSmall_NextNumber(void);
void BigSmall_AddResult(void);
void sub_0814A718(void);
void sub_0814A414(void);
void sub_080BE4C4(void);
void Sprite_DrawBlended(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u32 y);
extern const u8 gUnknown_0879D100[], gUnknown_0879D910[], gUnknown_0879D9B0[];
extern const void *const gUnknown_0879CD14[];
extern const void *const gUnknown_0879CE14[];
extern const u16 gUnknown_0879DDC4[];
bool32 Keno_CanStart(void);
void Keno_StartRound(void);
void sub_08149640(void);
void sub_08148618(void);
void Keno_DrawDigits(u32 n, u16 digits, u16 x, u16 y);
void sub_0814869C(u16 i, u16 x, u16 y);
void Keno_DrawPayTable(void);
struct BaccaratInit { u16 target, unk08, unk06, pad; };
extern const struct BaccaratInit gUnknown_0879C8EC[];

extern const u8 gUnknown_0879AC84[];
extern const u8 gUnknown_0879B550[];
extern const u8 gUnknown_0879B884[];
extern const u8 gUnknown_0879B8D4[];
struct C145Line { u32 cell[3]; };
extern const struct C145Line gUnknown_0879AC18[];
extern const u32 gUnknown_0879B53C[];
extern const u32 gUnknown_0879B5A0[];
extern const u32 gUnknown_0879B5C4[][5];
extern const u32 gUnknown_0879B664[][5];
extern const u32 gUnknown_0879B704[][4];
extern const u32 gUnknown_0879B784[][4];
extern const u32 gUnknown_0879B804[][4];

#endif /* GUARD_CASINO2_H */
