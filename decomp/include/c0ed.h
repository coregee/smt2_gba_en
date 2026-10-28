#ifndef GUARD_C0ED_H
#define GUARD_C0ED_H

#include "global.h"

/* Battle logic 0x080ED000-0x080F2AC7. Declarations copied from bflow.h / btext.h are kept
   here so this header can be used alone. */

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

/* Battle state at 0x0203D16C (= 0x0203C200 + 0xF6C), reached through gUnk_03006434. */
struct BattleState
{
    u16 flags;          /* 0x00 */
    u16 unk2;           /* 0x02 */
    u16 unk4;           /* 0x04 */
    s16 unk6;           /* 0x06: non-zero = two-sided battle (sub_080ED954) */
    u8 filler8[0x56 - 0x8];
    u16 unk56[8];       /* 0x56 */
    u8 filler66[0x78 - 0x66];
    u16 unk78[6][14];   /* 0x78 */
    u8 filler120[0x126 - 0x120];
    s16 unk126;         /* 0x126 */
    u16 unk128[2];      /* 0x128 */
    u16 unk12C[2];      /* 0x12C */
    u8 filler130[0x160 - 0x130];
    u32 unk160[8];      /* 0x160 */
};

extern struct BattleState *gUnk_03006434;
extern u8 *gUnk_03006438;
#define BSTATE gUnk_03006434

struct BattleUnit       /* 0x80 bytes; same layout as the party records in gGameState */
{
    u8 filler0[0xE];
    u16 unkE;           /* non-zero = slot used */
    u16 flags;          /* 0x10: 0x8000 = dead/absent */
    u8 filler12[0x6E];
};

/* The battle EWRAM block at 0x0203C200. Only fields used here are named. */
struct BattleFlow
{
    u8 filler0[0x974];
    void *window;               /* 0x974 */
    u8 filler978[0x984 - 0x978];
    u32 unk984;                 /* 0x984 */
    u8 filler988[0x990 - 0x988];
    u32 combatants[2];          /* 0x990 */
    u8 filler998[0x9A0 - 0x998];
    struct BattleUnit units[11];    /* 0x9A0 */
    u8 fillerF20[0x118C - 0xF20];
    u16 unk118C;                /* 0x118C */
    u8 filler118E[0x11A8 - 0x118E];
    u16 unk11A8;                /* 0x11A8 */
};

extern u8 gUnk_0203C200[];
#define BFLOW ((struct BattleFlow *)gUnk_0203C200)

void CpuSet(const void *src, void *dest, u32 control);
u32 __udivsi3(u32 a, u32 b);

/* elsewhere */
void sub_080EA210(void);
u16 *Menu_ExpandListTemplate(const u16 *tmpl, u32 arg);
u16 *MessageBox_ComposeSpeciesText(u32 a0, u32 a1, u32 a2, u32 a3, const u16 *tmpl);
u16 *MessageBox_ComposeNameText(u32 who, const u16 *tmpl);
void BattleMenu_SetMode(u8 mode, u16 *src);
void BattleMenu_Reset(void);
u8 BattleMsg_IsDone(void);
void Window_Close(void *window, u32 arg1);
u8 *sub_080C0148(u16 id);
u16 sub_080C0818(u32 who);
void sub_080C0290(u16 a, u32 b);
void sub_080C366C(void);
void Party_BuildMemberNameTiles(void);
void sub_080C6FD8(void);
u32 sub_080C2244(void);
u8 *sub_080C5D48(u16 id);
u32 Flag_Test(u32 flag);
u8 *sub_080BF648(u16 id);
u8 *sub_080BF5C0(u16 id);
s32 Race_GetParentId(s32 race);
s32 sub_080F4070(s32 a);
void sub_080F408C(s32 a, s16 v);
s32 sub_080F401C(s32 a);
s32 sub_080F4038(s32 a);
void sub_080F4054(s32 a, s16 v);
void sub_080C08F8(s32 a, u32 b);
void sub_080F4104(s32 a);

extern s8 gUnk_030050E0[];
extern u8 gUnk_0203A450[];
extern const u16 gUnknown_0876E6D4[];
extern const u8 gUnknown_0876E978[];
extern const u8 gUnknown_0872F234[];
struct RandTable
{
    const u8 *data;     /* rows of cumulative thresholds, 0 = skip */
    s32 stride;
};
extern const struct RandTable gUnknown_0876F660[];
extern const u8 gUnknown_0876F688[];
struct LevelTable       /* gUnknown_0876EBA8, 24 bytes each */
{
    u8 level[8];
    u16 value[8];
};
extern const struct LevelTable gUnknown_0876EBA8[];
extern const u16 gUnknown_0812466C[];
extern const u16 gUnknown_0812464E[];
extern const u16 gUnknown_0812463A[];
extern const u16 gUnknown_08124608[];
extern const u16 gUnknown_081245B4[];
extern const u16 gUnknown_081245F6[];
extern const u16 gUnknown_081245D2[];
extern const u16 gUnknown_0812461A[];

/* this region */
s16 sub_080EF99C(void);
u32 sub_080ED954(void);
u32 sub_080EDA24(s32 side);
u32 sub_080ED9F4(void);
s32 sub_080ED3FC(s32 table, s32 row);
s32 sub_080ED600(s32 row);
s32 sub_080ED464(s32 id);
u32 sub_080ED520(s32 id);
u32 sub_080ED560(s32 id);
u32 sub_080ED6CC(s32 id);
s32 sub_080ED9AC(s32 first, s32 count);
void sub_080ED35C(u32 *a, s32 *b, s8 idx);

#endif /* GUARD_C0ED_H */
