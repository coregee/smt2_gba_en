#ifndef GUARD_BATTLEDISP_H
#define GUARD_BATTLEDISP_H

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

#define DmaFill16(dmaNum, value, dest, size) DMA_FILL(dmaNum, value, dest, size, 16)
#define DmaFill32(dmaNum, value, dest, size) DMA_FILL(dmaNum, value, dest, size, 32)
#define DmaCopy32(dmaNum, src, dest, size) DmaSet(dmaNum, src, dest, (0x8000 | 0x0400) << 16 | ((size) / 4))
#define DmaCopy16(dmaNum, src, dest, size) DmaSet(dmaNum, src, dest, 0x8000 << 16 | ((size) / 2))

#define CpuFill32(value, dest, size)                                                    {                                                                                       vu32 tmp = (vu32)(value);                                                           CpuSet((void *)&tmp, dest, 0x05000000 | ((size) / 4 & 0x1FFFFF));               }

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
    u16 unk1E;          /* 0x1E */
    void (*onFrame)(struct Task *);
    union
    {
        u32 w[0x10];
        u16 h[0x20];
        u8 raw[0x40];
    } data;             /* 0x24 */
};

/* ---- staff roll (0x0815C140-0x0815CAE8) ---- */

/* Character-object task data (task + 0x24). */
struct StaffRollObj
{
    u8 pad00[8];
    s16 x;              /* 0x08 */
    s16 y;              /* 0x0A */
};

/* Sprite scaling block of a character object (task data + 0x24). */
struct ObjScale
{
    u16 on;
    u16 x;
    u16 y;
    u16 unk6;
};

/* One walking segment of the staff-roll character, copied from gUnknown_087F2C50. */
struct StaffRollPath
{
    u16 id;             /* 0x00 */
    u16 x;              /* 0x02 */
    u16 y;              /* 0x04 */
    u16 arg;            /* 0x06 */
    u16 tx;             /* 0x08: target */
    u16 ty;             /* 0x0A */
    u16 scale;          /* 0x0C */
    u16 scaleStep;      /* 0x0E: added every third frame */
};

/* Staff-roll state at 0x0203B454 (0x100 bytes, cleared on entry). */
struct StaffRoll
{
    u32 textDone;       /* 0x00: the text list reached its end marker */
    u32 scroll;         /* 0x04: scroll position in pixels */
    u32 row;            /* 0x08: first visible row of gUnknown_087F28B0 */
    u32 unk0C;
    u32 frame;          /* 0x10 */
    s16 dx;             /* 0x14: |target - start| of the current segment */
    s16 dy;             /* 0x16 */
    u16 stepX;          /* 0x18 */
    u16 stepY;          /* 0x1A */
    u16 signX;          /* 0x1C */
    u16 signY;          /* 0x1E */
    u16 accum;          /* 0x20: Bresenham error term */
    u16 next;           /* 0x22: set by sub_0815C828 when the pause ends */
    u16 timer;          /* 0x24 */
    u16 scale;          /* 0x26 */
    u16 segment;        /* 0x28 */
    u16 pad2A;
    struct StaffRollPath path[8];  /* 0x2C */
    struct Task *obj;   /* 0xAC */
};

struct StaffRollLine
{
    s32 type;           /* 0 text, 1-3 sprite (x 4/120/108), <0 end of text, -2 end */
    const void *ptr;
};

extern struct StaffRoll gUnk_0203B454;
extern const struct StaffRollLine gUnknown_087F28B0[];
extern const u32 gUnknown_087F2C50[][8];
extern const u32 gUnknown_087F2DD4[];
extern const u16 gUnknown_087F2D50[];
extern const u8 gUnknown_081B6270[], gUnknown_081B6594[], gUnknown_081B68BC[];
extern const u16 gUnknown_085426E0[];
extern u8 gUnk_0200F874[];
extern u16 gUnk_02000000[];
extern u16 gUnk_03000006, gUnk_03000040, gUnk_0203DB6A;
extern u8 gUnk_03000030, gUnk_03000031, gUnk_03000032, gUnk_03000033, gUnk_03000034,
    gUnk_03000035, gUnk_03000036, gUnk_03000037, gUnk_03000038, gUnk_03000039, gUnk_0300003A;
extern u16 gPaletteTarget[0x200];
extern u16 gPaletteBuffer[0x200];
extern u16 gUnk_03002D50[];
extern s32 gYesNoResult;
extern u32 gUnk_03004614, gUnk_03004514, gUnk_0200AB04;
extern u16 gFieldState[];

void CpuSet(const void *src, void *dest, u32 control);
void LZ77UnCompWram(const void *src, void *dest);
void SetMainCallback(VoidFunc func);
void Palette_MarkDirty(void);
void Task_ClearAll(void);
void Windows_Init(void);
void Task_RunAll(void);
struct Task *Task_Create(const void *script, u32 parent);
void Task_End(struct Task *task);
bool32 Task_IsFree(u32 task);
void Font_DrawGlyphTinted(u16 code, void *canvas, u16 x, u16 y, u8 tint);
void VBlankTask_AddCounted(VoidFunc func, u32 count);
void Sprite_Draw(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
struct Task *CharObj_Create(u32 a, u16 b, u16 c, u16 d, u16 e, u32 f);
u32 BgPicture_StartTask(u16 id);
void Palette_CopyWithEffect(u32 a0, const void *src, void *dst, u32 a3, u32 a4);
void *PalFade_FadeRangeWithDuration(u16 start, u16 count, u16 delay, u16 duration);
u32 Window_CreateOpen(u32 x, u32 y, u32 w, u32 h, u32 bg);
void Font_ResetGlyphSpriteCache(u16 baseTile);
u32 YesNo_Create(u32 a);
void Window_Close(u32 win, u32 erase);
u32 Flag_Test(u32 flag);
void Flag_Set(u32 flag);
void sub_080C2A50(u32 a, u32 b);
void Game_NewGame(void);
u32 SaveScreen_Open(u16 mode, u16 arg1);
void Text_DrawSpriteString(const u16 *str, u16 a1, u16 a2, u16 x, u16 y, u16 advance);
void sub_080D5B8C(u16 mode);
void sub_080C1450(void);
void sub_080C1384(void);

void sub_0815C140(void);
void sub_0815C16C(void);
void sub_0815C1A8(void);
void sub_0815C380(void);
void sub_0815C75C(u16 id, u16 x, u16 y, u16 arg, u16 scale);
void sub_0815C7CC(void);
void sub_0815C7E0(u16 dx, u16 dy, u16 scale);
void sub_0815C828(void);
void sub_0815C860(void);
void sub_0815CAB4(void);
void sub_0815CAE8(void);

/* ---- battle setup and display (0x080E47A8-0x080EA37C) ---- */

#define DmaSet3(src, dest, control)                             {                                                                   vu32 *dmaRegs = (vu32 *)(REG_BASE + 0xD4);                      dmaRegs[0] = (vu32)(src);                                       dmaRegs[1] = (vu32)(dest);                                      dmaRegs[2] = (vu32)(control);                                   dmaRegs[2];                                                 }

#define DmaSet3Wait(src, dest, control)                         {                                                                   vu32 *dmaRegs = (vu32 *)(REG_BASE + 0xD4);                      dmaRegs[0] = (vu32)(src);                                       dmaRegs[1] = (vu32)(dest);                                      dmaRegs[2] = (vu32)(control);                                   dmaRegs[2];                                                     while (dmaRegs[2] & 0x80000000)                                     ;                                                       }

/* Battle start arguments, kept at 0x0203C200 + 0x1154. */
struct C15cBattleArgs
{
    u16 unk0;
    u16 kind;           /* 0x02: low nibble of the start flags */
    u16 a1;             /* 0x04 */
    u16 a2;             /* 0x06 */
    u16 a3;             /* 0x08 */
    u16 a4;             /* 0x0A */
};

/* One battle unit record (0x80 bytes) at 0x0203C200 + 0x9A0. */
struct C15cUnit
{
    u8 pad00[0xE];
    u16 unkE;           /* 0x0E */
    u16 unk10;          /* 0x10 */
    u8 pad12[6];
    u16 unk18;          /* 0x18 */
    u8 pad1A[0x80 - 0x1A];
};

/* Palette pulse (task data): 16 colours of src are tinted by level * (r, g, b) / 256 into
   dst; level runs between 0 and max. */
struct C15cPulse
{
    u8 r;               /* 0x00 */
    u8 g;               /* 0x01 */
    u8 b;               /* 0x02 */
    u8 max;             /* 0x03 */
    s8 level;           /* 0x04 */
    s8 dir;             /* 0x05: 1 = rising */
    u8 unk6;
    u8 unk7;
    u16 src[16];        /* 0x08 */
    u16 *dst;           /* 0x28 */
};

/* Battle demon sprite slot (0x40 bytes) at 0x0203C200 + 0xDA0. */
struct C15cDemonSprite
{
    u8 unk0;
    u8 unk1;            /* 0x01: frame timer */
    u8 bank;            /* 0x02: graphics bank in 0x02001000 / animation frame */
    u8 upload;          /* 0x03: 1 = DMA the bank to OBJ VRAM at the next VBlank */
    u8 unk4;            /* 0x04: state */
    s8 unk5;            /* 0x05: shake step */
    s8 unk6;            /* 0x06: x offset */
    s8 unk7;            /* 0x07: y offset */
    s16 x;              /* 0x08: 0x7FFF = default position */
    s16 y;              /* 0x0A */
    const void *def;    /* 0x0C */
    u8 unk10;           /* 0x10: priority */
    u8 unk11;           /* 0x11: layer */
    u16 demonId;        /* 0x12 */
    struct C15cPulse pulse; /* 0x14 */
};

struct C15cWin
{
    u32 window;
    u32 yesno;          /* 0x04 */
};

/* Status icon of a battle unit (12 bytes) at 0x0203C200 + 0xE60. */
struct C15cIcon
{
    u8 slot;            /* 0x00 */
    u8 icon;            /* 0x01: StatusIcon_FromStatus index */
    u8 tile;            /* 0x02 */
    s8 unk3;            /* 0x03: palette */
    u16 unk4;           /* 0x04 */
    s16 unk6;           /* 0x06: y offset */
    u8 shown;           /* 0x08 */
    u8 unk9;            /* 0x09 */
    u8 unkA;            /* 0x0A */
    u8 unkB;            /* 0x0B */
};

/* Battle message window state (0x190 bytes) at 0x0203C200 + 0x7E0 (struct BFlowMsg). */
struct C15cMsg
{
    u8 mode;            /* 0x00 */
    u8 unk1;
    u8 delay;           /* 0x02 */
    u8 typed;           /* 0x03 */
    u8 done;            /* 0x04 */
    u8 row;             /* 0x05 */
    u8 lines;           /* 0x06 */
    u8 locked;          /* 0x07 */
    u8 pad08[0x188];
};

struct C15cPortrait
{
    u8 pad00[0xC];
    u16 x;              /* 0x0C */
    u16 y;              /* 0x0E */
    u8 pad10[8];
};

/* The battle EWRAM block at 0x0203C200. */
struct C15cBattle
{
    u32 unk000;                   /* 0x000 */
    struct Task *tasks[3];        /* 0x004 */ /* per enemy sprite slot; tasks[2] also the intro task */
    u8 pad010[0x680];
    u8 unk690;                    /* 0x690 */
    u8 pad691[0x1];
    u8 unk692;                    /* 0x692 */
    u8 unk693;                    /* 0x693 */
    u8 pad694[0x1];
    u8 unk695;                    /* 0x695 */ /* target group cursor */
    u8 pad696[0xE4];
    u16 tiles77A[0x20];           /* 0x77A */ /* tilemap row DMAd to VRAM 0x06000300 */
    u8 pad7BA[0x26];
    struct C15cMsg msg;           /* 0x7E0 */
    u32 unk970;                   /* 0x970 */
    u32 unk974;                   /* 0x974 */
    s16 state;                    /* 0x978 */
    s16 substate;                 /* 0x97A */
    s16 phase;                    /* 0x97C */
    s16 unk97E;                   /* 0x97E */
    u32 encounter;                /* 0x980 */
    u32 unk984;                   /* 0x984 */
    u32 pick[2];                  /* 0x988 */
    u32 groups[2];                /* 0x990 */ /* demon id of each enemy group */
    s16 counts[2];                /* 0x998 */ /* enemies per group */
    s16 unk99C;                   /* 0x99C */
    u16 unk99E;                   /* 0x99E */
    struct C15cUnit units[8];     /* 0x9A0 */
    struct C15cDemonSprite sprites[2]; /* 0xDA0 */
    u8 padE20[0x40];
    struct C15cIcon icons[8];     /* 0xE60 */
    u8 unkEC0;                    /* 0xEC0 */
    u8 padEC1[0x2];
    u8 unkEC3;                    /* 0xEC3 */
    u8 unkEC4;                    /* 0xEC4 */
    u8 unkEC5;                    /* 0xEC5 */
    u8 padEC6[0x6];
    s16 unkECC;                   /* 0xECC */ /* last index of the action order */
    s16 unkECE;                   /* 0xECE */ /* current index into the action order */
    u8 padED0[0x20];
    u16 unkEF0[0x10];             /* 0xEF0 */
    u16 unkF10[0x10];             /* 0xF10 */
    u16 unkF30[0x10];             /* 0xF30 */ /* chosen skill high halves, by party member */
    u8 padF50[0x10];
    s16 unkF60;                   /* 0xF60 */ /* auto-battle mode from sub_080C2BA4 */
    s16 unkF62;                   /* 0xF62 */
    u16 unkF64;                   /* 0xF64 */
    s16 unkF66;                   /* 0xF66 */
    s16 unkF68;                   /* 0xF68 */
    s16 unkF6A;                   /* 0xF6A */
    u8 bstate[0x1A0];             /* 0xF6C */ /* battle state, reached through gUnk_03006434 */
    struct C15cWin win;           /* 0x110C */
    u16 *vblankTask;              /* 0x1114 */
    u16 *vbl[2];                  /* 0x1118 */ /* per sprite slot; slot 2 would land on unk1120 */
    u8 unk1120;                   /* 0x1120 */ /* 1 = the chosen command cannot be used */
    u8 unk1121;                   /* 0x1121 */
    u8 unk1122;                   /* 0x1122 */
    u8 unk1123;                   /* 0x1123 */
    u8 pad1124[0x30];
    struct C15cBattleArgs args;   /* 0x1154 */
    struct C15cPortrait portrait; /* 0x1160 */
    u8 pad1178[0x10];
    u8 unk1188;                   /* 0x1188 */
    u8 unk1189;                   /* 0x1189 */
    u16 unk118A;                  /* 0x118A */
    u16 unk118C;                  /* 0x118C */
    u8 pad118E[0xA];
    u16 group;                    /* 0x1198 */
    u16 timer;                    /* 0x119A */
    u16 unk119C;                  /* 0x119C */
    u16 unk119E;                  /* 0x119E */
    s16 step;                     /* 0x11A0 */
    u8 pad11A2[0x2];
    u16 unk11A4;                  /* 0x11A4 */
    u16 unk11A6;                  /* 0x11A6 */
    u16 unk11A8;                  /* 0x11A8 */
    u16 unk11AA;                  /* 0x11AA */
    u16 unk11AC;                  /* 0x11AC */
    s16 unk11AE;                  /* 0x11AE */
};

extern u8 gUnk_0203C200[];
#define BB ((struct C15cBattle *)gUnk_0203C200)

/* Battle IWRAM state at 0x030063A0. */
struct C15cBattleIw
{
    u16 active;         /* 0x00 */
    u16 unk02;
    u16 unk04;
    u16 unk06;          /* 0x06 */
    u16 unk08;
    u16 unk0A;          /* 0x0A */
    u16 unk0C;          /* 0x0C */
    u16 unk0E;
    u16 unk10;
    u16 unk12;          /* 0x12 */
    u16 unk14;          /* 0x14 */
    u16 unk16;          /* 0x16 */
    struct Task *task18;/* 0x18 */
};
extern struct C15cBattleIw gUnk_030063A0;

extern u8 gUnk_0300003D;
extern u16 gUnk_030031B4, gUnk_030031EC;
extern VoidFunc gMainCallback;
extern u16 gUnk_03002D70[], gUnk_03002D90[];
extern const u32 gUnknown_086BEF88[], gUnknown_086BE738[];
extern const u16 gUnknown_086BE584[];
extern const s8 gUnknown_086BE5A4[][2];
extern const u16 gUnknown_086BF72C[];

struct DemonAnimFrame
{
    const void *def;
    u16 duration;               /* 0xFFFF ends the list */
    u16 pad;
};

struct DemonAnim
{
    u32 unk0;
    const struct DemonAnimFrame *frames;        /* 0x04 */
};

struct DemonGfxRecord
{
    u8 kind;                    /* 0x00: 0 = animated sprite */
    u8 attr;                    /* 0x01: bit 7 frame list, bits 6-7 = 0xC0 masked pulse */
    u16 pad02;
    const void *palette;        /* 0x04 */
    const struct DemonAnim *anim; /* 0x08 */
    const void *gfx[2][2];      /* 0x0C */
};

void sub_080E44F8(void);
void BattleState_Init(void);
void sub_080ED938(u32 v);
void sub_080ED90C(u16 v);
void sub_080E74DC(void);
void Combatant_UpdateStats(s32 who);
void sub_080C7C60(void);
void BattleMsg_SetLocked(u8 locked);
void sub_080E5668(VoidFunc func);
void sub_080E5674(void);
void sub_080B0888(void);
void sub_080C7054(void);
const struct DemonGfxRecord *Demon_GetGfxRecord(u16 id);
s32 sub_080C2644(u32 id);
void sub_080D977C(void);
void PalFade_FadeRangeInFromBlack(u16 start, u16 count, u16 delay);
void sub_080ED878(void);
void sub_080ED900(u32 v);
void BattleFlags_Mask(s32 v);
u32 sub_080ED5B4(s32 table, s32 who);
u32 Random_Byte(void);
u32 Battle_IsTwoSided(void);
s16 sub_080ED610(s32 id);
void sub_0813E908(u16 a, u16 b);
u32 sub_080ED67C(s32 id);
void Battle_InitEnemyUnit(s32 slot, s32 id);
u8 *Demon_GetRecord(u16 id);
void sub_080EF8F8(u32 v);
void sub_080E8C58(u16 g0, u16 g1, u16 arg);
u8 sub_080E8D64(void);
u32 sub_080ED32C(u16 i);
void sub_080EC9AC(u8 id, u8 side, u16 arg, u32 unused);
void sub_080ECF70(u16 a);
void Battle_LoadGroupPalette(u16 group);
u8 sub_080ECB10(void);
void sub_080E8DEC(void);
void sub_080E845C(u8 a, s8 b, s8 c);
u32 sub_080EDAD0(void);
u32 sub_080EDAEC(s32 id);
void sub_080E760C(void);
void sub_080E7C98(void);
void sub_080E8DB4(u16 group);
void sub_080E7484(void);
void sub_080E51FC(void);

s32 sub_080EF90C(void);
s32 sub_080EF954(void);
void sub_080C8048(s32 a0, u32 x, u32 y, u32 a3);
void sub_08126F14(void);
void Combatant_RecalcStats(s32 who);
void sub_080AF018(void);
void sub_080AEFFC(void);
void sub_080B9080(void);
void sub_080B08AC(void);
void sub_080C700C(void);
void sub_080E9008(void);
void sub_080C7C94(void);
void Music_Play(u16 se);
u32 sub_080AD608(u16 a, u16 b);
void Music_FadeOut(u32 a);
u32 sub_080AD67C(u16 id);
void sub_080B9058(void);
u32 PalFade_AllDone(void);
extern u16 gHudState[];
extern u8 gGameState[];
#define GS ((struct C15cGameState *)gGameState)
/* World-map state at 0x030069F0 (as in c151.h). */
struct WorldMap
{
    u32 state;      /* 0x00 */
    u16 mode;       /* 0x04 */
    u16 unk06;
    u16 map;        /* 0x08 */
};
extern struct WorldMap gWorldMap;

/* Fields of gGameState used here. */
struct C15cGameState
{
    u8 pad000[0xA20];
    s8 order[0x20];     /* 0xA20: party order, indexed by the battle turn slot */
    u8 padA40[0x80];
    u16 unkAC0;         /* 0xAC0: nonzero on the world map */
};
extern u8 gUnk_030000B4[];
extern u8 gUnk_02001000[];

void HuffUnComp(const void *src, void *dest);
void CpuFastSet(const void *src, void *dest, u32 control);
u32 Palette_IsBg13Black(void);
void *PalFade_FadeRangeInFromBlackTagged(u16 start, u16 count, u16 delay, u16 tag);
void sub_080E86B4(u16 *dst, struct C15cPulse *p, u16 id);
u8 Demon_LoadGfx(u16 id, u8 half, u8 step, u8 pal);
extern u8 gBgPictureBuffer[];

u32 sub_080F3040(s32 who);
u32 Combatant_GetEquip(s32 who, s32 slot);
s32 sub_080F3190(void);
s32 sub_080F4410(s32 who);
u32 sub_080F31E0(void);
u16 sub_0812B3A4(u8 mode);
u32 BattleMenu_BuildSkillList(u8 mode, s32 who);
void sub_08126D50(u8 id, u8 parts);
void sub_080C7AE0(void);
extern s32 gUnk_03000058;
void sub_080E5940(void);
void sub_080E5990(void);

/* Menu cursor (0x28 bytes), as in menucur.h. */
struct MenuCursor
{
    u8 state;       /* 0x00 */
    u8 delay;       /* 0x01 */
    u8 mode;        /* 0x02 */
    u8 flags;       /* 0x03 */
    u16 keys;       /* 0x04 */
    u16 columns;    /* 0x06 */
    u16 rows;       /* 0x08 */
    u16 count;      /* 0x0A */
    u16 top;        /* 0x0C */
    u16 onScreen;   /* 0x0E */
    u16 perColumn;  /* 0x10 */
    u16 index;      /* 0x12 */
    u16 unk14;
    u16 column;     /* 0x16 */
    u16 row;        /* 0x18 */
    u16 seMove;     /* 0x1A */
    u16 sePage;     /* 0x1C */
    u16 seA;        /* 0x1E */
    u16 seB;        /* 0x20 */
    u16 seLR;       /* 0x22 */
    u16 seStart;    /* 0x24 */
    u16 seSelect;   /* 0x26 */
};
u8 sub_081268E4(u8 id, struct MenuCursor *src);
void sub_08126870(void);
void sub_080C7ACC(void);

struct MenuCursor *sub_08126D1C(u8 id);
void sub_08126A08(u8 id);
void BattleMenu_SetMode(u8 mode, const u16 *src);
s32 sub_080F30CC(s32 slot);
void sub_080C6FF0(void);
void sub_080C7038(void);
void sub_080EC948(void);
void sub_081269B0(u8 id);
void BattleMenu_Reset(void);
void BattleMsg_SetDone(u8 done);
u32 sub_080C3620(s32 who);
u8 sub_080E6130(u8 slot);
void MenuCursor_SetIndex(u8 id, u16 index);
u16 *Battle_BuildActorPrompt(u8 slot);
void sub_080C8490(s32 slot);
extern vu16 gKeysNew;
extern const u8 gUnknown_080008B0[];
extern const u16 gUnknown_086BE5D2[];
extern const u16 gUnknown_086BE5DA[];
extern const u16 *const gUnknown_086BE5EC[];
extern const u8 gUnknown_086BE610[][5];

void sub_080F2FEC(s16 *out, s16 *pos);
void sub_080C35C4(s32 who, u16 v);
void sub_080C8480(s32 slot);
extern const u16 *const gUnknown_086BE620[];
extern const u16 gUnknown_086BE606[];
extern const u16 gUnknown_081230DC[];

u32 sub_080C35E4(s32 who);
u32 Battle_CanUseCommand(s32 who, s32 kind, s32 *msg);
u16 *Battle_GetMessage(u16 id);
u16 *Menu_ExpandListTemplate(const u16 *tmpl, u32 arg);
u8 *Party_GetMember(u16 id);
s32 sub_080EF5FC(u8 *c, s32 who);
s16 sub_080E6E08(void);
void sub_080F2F94(s16 *out, s16 *pos);
u8 BattleMsg_IsDone(void);
extern const u8 gUnknown_08000868[];
extern const u16 gUnknown_086BE5FC[];
extern void (*const gUnknown_086BE654[])(void);

u8 sub_08126928(u8 id, u8 type, u16 columns, u16 rows, u16 perColumn);
u32 sub_080C7AF0(void);
u8 sub_080F332C(u32 a);
u32 sub_080F33E8(void);
u16 sub_080F3398(void);
extern const u16 gUnknown_0812326A[];
extern const u8 gUnknown_086BE67C[][3];
extern const u16 *const gUnknown_086BE684[];

void sub_0812C490(u8 a, u8 b);
u32 sub_0812C4D4(void);
void Combatant_SetChosenSkill(s32 who, u8 skill);
void sub_081293F8(u8 mode);
u32 sub_08129440(void);
void sub_0812B194(u8 mode, u16 value);
u32 sub_0812B1D4(void);
void sub_080EA210(void);

u32 sub_080F3060(void);
void sub_080EDA4C(s32 who, s32 target);
void sub_080ECB38(void);
extern u8 gUnk_03000050;
void sub_080E6DBC(u16 n);

extern u8 gUnk_03000051;
void BattleMsg_Close(void);
void sub_080C84A0(void);
void sub_081269D0(void);

extern struct Task gTasks[64];
extern u8 gUnk_030010B4[];
extern u8 gUnk_030063C0;
extern const u8 gUnknown_081A81B8[];
extern const u8 gUnknown_086BE6A4[][4];
void sub_080E7318(void);
void sub_080E7364(void);
u8 StatusIcon_FromStatus(u16 status);
void sub_080E7A44(struct Task *t);

u16 Combatant_IsDead(s32 who);
s32 Combatant_IsUsed(s32 who);
void sub_080E7538(u8 slot, u8 mode, u8 arg);
extern const u8 gUnknown_086BE707[], gUnknown_086BE70F[], gUnknown_086BE713[];

u16 Combatant_GetStatus(s32 who);
s32 Battle_GetHp(s32 who);
s32 Battle_GetMaxHp(s32 who);
u8 *Battle_GetCombatant(u16 idx);
u8 StatusIcon_ForCombatant(u16 who);

void *memset(void *dst, int c, u32 n);
void sub_080E7968(void);
extern const void *const gUnknown_086BE718[];

void sub_080AA514(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y,
                  u16 objMode);
u8 sub_080E8738(u8 slot);
u32 sub_080E7D30(u16 id);

u32 sub_080EDA24(u32 i);
extern u32 gFrameCounter;

u32 DemonSprite_StepShake(struct C15cDemonSprite *s);
void DemonSprite_LoadPalette(u8 slot, u8 kind);
u16 sub_080E8AC0(u16 id);
void sub_080E847C(struct C15cPulse *p);
void sub_080E8590(struct C15cPulse *p, u16 mask);
extern const u8 gUnknown_080F649C[];
extern const u8 gUnknown_086BE75C[][5];
extern const void *const gUnknown_086BE884[];
extern const u32 gUnknown_086BE89C[];
struct C15cShake
{
    struct
    {
        u16 x;
        u16 y;
    } d[10];
};
extern const struct C15cShake gUnknown_086BE7BC;

u32 VBlankTask_Add(VoidFunc func);
extern u8 *gUnk_03006434;
void sub_080E5528(void);

struct Task *CharObj_FindInGroup(u16 key, u16 id);
void sub_080BDE1C(u16 id, u32 a);
void Combatant_SetStatus(s32 who, u32 bits);
void CharTask_Unregister(struct Task *t);
extern struct Task *gCharTasks[];
extern const u32 gUnknown_086BEA18[], gUnknown_086BEB18[];
void sub_080E55BC(void);
void sub_080E5610(void);

u32 sub_080C2BA4(void);
void sub_080F00FC(u16 m);
s32 Combatant_IsInParty(s32 who);
void sub_080C84C0(void);
void sub_080E926C(); /* K&R: callers pass s16 values */
void sub_080E91F0(); /* K&R: callers pass an s16 */
extern u16 gUnk_030031D0;
extern s16 gUnk_03000052;
extern const u16 gUnknown_08126368[];

s32 Combatant_GetChosenSkill(s32 who);
u32 sub_0812B37C(void);
s32 Battle_GetMp(s32 who);
u32 sub_080ED6CC(s32 id);
u32 sub_080ED694(s32 id);
s32 Combatant_IsAlive(s32 who);
u8 *Action_GetRecord(u16 id);
s32 sub_080C10B4(s32 item);
u16 sub_0812B1E0(s32 who, u8 n);
extern s8 gUnk_030050E0[];

void sub_080F3120(void);
void sub_080F2D4C(void);
void Battle_BuildActionOrder(void);
s16 Battle_GetLastOrderIndex(void);
s32 sub_080EFFC4(s16 i);
u32 sub_080F0434(s32 who);
void Party_FixFormation(void);
void Party_BuildMemberNameTiles(void);
void Hud_LoadAllMemberFaces(void);
u32 sub_080ED9F4(void);
u32 Battle_IsPartyDefeated(void);
u16 sub_080ED8F4(void);
void sub_080EF2A0(void);

s32 sub_080F0168(void);
s32 sub_080F01EC(s32 i);
u32 sub_080F0194(s32 who);
u16 *MessageBox_ComposeRaceNameText(u32 id, const u16 *tmpl);
u16 sub_080E980C(void);
extern const u16 gUnknown_086BEC18[];
extern const u16 gUnknown_08124284[];

s32 Party_GetSkillCount(s32 who);
u32 sub_080AB890(u32 a, u32 b, u32 c, u32 d, u32 e);
void Window_SetHeight(u32 window, u32 h);
extern s16 gUnk_0300005C;
extern const u32 gUnknown_086BF708[];
u16 *sub_080E9870(void);

#endif /* GUARD_BATTLEDISP_H */
