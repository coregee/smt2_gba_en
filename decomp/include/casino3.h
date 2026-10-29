#ifndef GUARD_CASINO3_H
#define GUARD_CASINO3_H

#include "global.h"

/* Casino minigames 0x0814A414-0x0814E843. Each game keeps its whole state in the 0x800-byte
   block at 0x0203A454 (gMenuState; cleared by the game's init), so every game has its own
   view of the block below. */

/* Game ending at 0x0814AE1C (started in asm/code_08145784.s, command script 0x0879D100). */
struct C14aCardEntry
{
    u8 shown;       /* +0 */
    u8 pad1[3];
    u16 value;      /* +4 */
    u16 pad6;
};

struct C14aGameX
{
    u16 unk00;
    u16 pad02;
    u8 state;               /* 0x04 */
    u8 unk05;
    u16 timer;              /* 0x06 */
    u8 pad08[4];
    u16 unk0C;
    u8 pad0E[4];
    u16 number;             /* 0x12 */
    u8 pad14[6];
    u8 unk1A;
    u8 pad1B;
    u16 unk1C;
    u16 unk1E;
    u16 unk20;
    u16 unk22;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    u8 unk27;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    u8 unk3C;
    u8 pad3D;
    u16 unk3E;
    u16 unk40;
    u16 unk42;
    u16 unk44;
    u16 unk46;
    u16 unk48;
    u8 unk4A[10];
    u16 unk54;
    u16 count;              /* 0x56 */
    u16 unk58;
    u16 unk5A;
    u16 unk5C;
    u16 pad5E;
    struct C14aCardEntry entries[64];   /* 0x60 */
    u16 unk260;
    u16 unk262;
};

struct C14aSpritePos
{
    const void *def;
    u16 x;
    u8 y;
};

struct C14aPos
{
    u16 x;
    u8 y;
};

struct C14aPrize
{
    u16 item;
    u16 value;
};

extern u8 gMenuState[];   /* 0x0203A454, viewed through the per-game structs */
extern u32 gFrameCounter;
extern vu16 gKeysNew;
extern u16 gRepeatedKeys;
extern u16 gUnk_0300000C;
extern u16 gUnk_03000002, gUnk_03000040;

extern const u8 gUnknown_0814F7C0[], gUnknown_0814F7DC[];
extern const u8 gUnknown_0814F8B0[], gUnknown_0814F8C0[], gUnknown_0814F8D0[], gUnknown_0814F8E0[],
    gUnknown_0814F8F0[];
extern const u8 gUnknown_0814F900[], gUnknown_0814F910[], gUnknown_0814F920[], gUnknown_0814F930[],
    gUnknown_0814F940[];
extern const u8 gUnknown_0814F958[], gUnknown_0814F970[], gUnknown_0814F988[], gUnknown_0814F9A0[];
extern const struct C14aSpritePos gUnknown_0879DE24[];
extern const void *const gUnknown_0879DE74[];
extern const struct C14aPos gUnknown_0879DE9C[];
extern const u16 gUnknown_0879DF8C[][11][9];
extern const struct C14aPrize gUnknown_0879E2A4[][11];

void Sound_Play(u32 se);
u32 Random_Byte(void);
void Inventory_AddItem(u16 id);
void Font_ResetGlyphSpriteCache(u16 baseTile);
void Sprite_Draw(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
void FontSprite_DrawGlyphTinted(u16 glyph, u16 a1, u16 a2, u16 x, u16 y, u16 palette);
u32 BigSmall_GetCountStep(u32 value);

void sub_0814A9A4(void);
void sub_0814AA70(void);
void sub_0814AB5C(void);
void sub_0814AD74(void);

/* Code Breaker (0x0814AE1C-0x0814D7BB; command script 0x0879F064). */
struct C14aCbPeg
{
    u8 symbol;      /* +0 */
    u8 unk1;
    u8 shown;       /* +2 */
    u8 unk3;
};

struct C14aCbResult
{
    u8 hits;        /* right symbol, right place */
    u8 blows;       /* right symbol, wrong place */
    u8 pad[2];
};

struct C14aCodeBreaker
{
    u16 startScript;        /* 0x00 */
    u16 pad02;
    u8 state;               /* 0x04 */
    u8 level;               /* 0x05: 0-3 */
    u16 timer;              /* 0x06 */
    u16 timer2;             /* 0x08 */
    u16 unk0A;
    u16 unk0C;
    u16 unk0E;
    u16 unk10;
    u16 unk12;
    u8 dup;                 /* 0x14 */
    u8 pad15;
    u16 unk16;
    u8 unk18;
    u8 pad19;
    u16 cursor;             /* 0x1A */
    u8 unk1C;
    u8 pad1D;
    u16 cursorMin;          /* 0x1E: x of the leftmost cursor slot */
    u16 cursorMax;          /* 0x20 */
    u16 rand;               /* 0x22 */
    u8 up;                  /* 0x24 */
    u8 down;                /* 0x25 */
    u16 upAnim;             /* 0x26 */
    u16 downAnim;           /* 0x28 */
    u8 busy;                /* 0x2A */
    u8 row;                 /* 0x2B: first board slot of the current row (row * 5) */
    u16 prevRow;            /* 0x2C: board slot of the row compared with the current one */
    u8 symbols;             /* 0x2E: number of different symbols (5, 7, 8) */
    u8 digits;              /* 0x2F: code length (3, 4, 5) */
    u8 unk30;
    u8 pad31;
    u16 unk32;
    u16 unk34;
    u16 unk36;
    u8 unk38;
    u8 pad39;
    u16 unk3A;
    u16 unk3C;
    u8 unk3E;
    u8 unk3F;
    u16 unk40;
    u8 unk42;
    u8 unk43;
    u8 unk44;
    u8 pad45;
    u8 tot[2];              /* 0x46: rowTotal of the current and the compared row */
    u8 rowTotal[8];         /* 0x48: hits + blows of each row */
    u8 rowCount[8];         /* 0x50: different symbols in each guessed row */
    u8 rowMask[8];          /* 0x58: bit set of the symbols in each guessed row */
    u8 unk60;
    u8 unk61;
    u8 unk62;
    u8 unk63;
    u8 unk64;
    u8 unk65;
    u8 unk66;
    u8 guessA[5];           /* 0x67 */
    u8 guessB[5];           /* 0x6C */
    u8 unk71;
    u8 unk72;
    u8 unk73;
    u8 unk74;
    u8 pad75[3];
    struct C14aCbPeg board[40];         /* 0x78: 8 rows of 5 */
    struct C14aCbPeg secret[5];         /* 0x118 */
    struct C14aCbResult results[8];     /* 0x12C */
    u8 pad14C[0x20];
    struct C14aCbPeg table[8][5];       /* 0x16C */
    u8 ready;                           /* 0x20C */
};

/* Casino scene header at 0x0203B554 (struct CasinoScene in c13e.h). */
struct C14aScene
{
    u16 game;
    u16 arg;    /* difficulty chosen at the table */
};
#define C14A_SCENE ((struct C14aScene *)0x0203B554)

struct Task;
struct Task *Task_Create(const void *script, u32 parent);
u8 Inventory_GetCount(u16 id);
void Inventory_RemoveItem(u16 id);
void sub_080BE4C4(void);

extern const u32 gUnknown_0879F064[];
extern const u8 gUnknown_0814FBC4[], gUnknown_0814FBDC[], gUnknown_0814FBEC[], gUnknown_0814FBFC[],
    gUnknown_0814FC0C[], gUnknown_0814FC1C[], gUnknown_0814FC2C[], gUnknown_0814FC3C[];
extern const u8 gUnknown_0814FE04[], gUnknown_0814FE1C[], gUnknown_0814FE34[], gUnknown_0814FE4C[];
extern const struct C14aPos gUnknown_0879EB64[];
extern const u8 gUnknown_0814FCDC[], gUnknown_0814FCEC[], gUnknown_0814FCFC[], gUnknown_0814FD0C[],
    gUnknown_0814FD1C[], gUnknown_0814FD2C[], gUnknown_0814FD3C[], gUnknown_0814FD4C[];
extern const u8 gUnknown_0814FEC8[], gUnknown_0814FEEC[], gUnknown_0814FC54[], gUnknown_0814FC7C[];
extern const u8 gUnknown_0879EC04[][2];
extern const u16 gUnknown_0879EC14[][10][9];     /* prize messages, 8 glyphs + 0 each */
extern const void *const gUnknown_0879EF84[];   /* digit sprites */
extern const void *const gUnknown_0879EFAC[];
struct C14aPos16
{
    u16 x;
    u16 y;
};
extern const struct C14aPos16 gUnknown_0879EFBC[][5];
u8 Inventory_IsMaxed(u16 id);
extern const u8 gUnknown_0879F05C[];   /* 1 << n */
void sub_0814C624(u8 mask, u8 value);
void sub_0814CFDC(u8 pos, u8 value);
void sub_0814D058(u8 mask, u8 pos, u8 value);
void sub_0814C580(void);
void sub_0814C6C4(u8 value);
void sub_0814C6F4(u8 value);
void sub_0814C7A8(u8 value);
void sub_0814C878(u8 value);
void sub_0814C948(void);
void sub_0814CA18(u8 value);
void sub_0814CA34(u8 mask, u8 value);
void sub_0814CAD4(void);
void sub_0814CB90(void);
void sub_0814CC38(u8 row);
u8 sub_0814CD10(u8 mask, u8 row);
u8 sub_0814CD70(u8 rowA, u8 rowB);
void sub_0814CE90(u8 mask, u8 value);
void sub_0814CEA4(u8 mask, u8 value);
void sub_0814CEB8(u8 mask, u8 value);
void sub_0814CECC(void);
void sub_0814D0C4(void);
u8 *NumberToDigits(u32 value);
/* Where each board slot is drawn while the pegs are dealt: per level, 40 slots. */
struct C14aCbDeal
{
    u16 x;
    u8 y;
    u8 pad3;
    u8 slot;    /* board index */
    u8 last;    /* 1 on the final record */
    u16 pad6;
};
extern const struct C14aCbDeal gUnknown_0879E5C4[][40];
extern const void *const gUnknown_0879E58C[];
extern const struct C14aPos gUnknown_0879E5B0[];
extern const struct C14aPos gUnknown_0879EAC4[];
extern const struct C14aPrize gUnknown_0879EEE4[][10];

void sub_0814B524(void);
void sub_0814B6C4(void);
void sub_0814B7AC(void);
void sub_0814B838(void);
void sub_0814B894(void);
void sub_0814B8F4(void);
void sub_0814BB1C(void);
void sub_0814BC0C(void);
void CodeBreaker_ScoreRow(void);
void sub_0814BE8C(void);
void sub_0814BF7C(void);
void CodeBreaker_PickCode(void);
void sub_0814C130(void);
void sub_0814C230(void);
void sub_0814C318(void);
void sub_0814C3FC(u32 value, u16 x, u16 y, u16 priority);
void CodeBreaker_DrawNotes(void);
u16 sub_0814C52C(u16 cursor);
void CodeBreaker_UpdateNotes(void);

/* Russian Roulette (0x0814D688-0x0814E843; command script 0x0879F3C4). The player bets a party
   demon against the opponent's; sprite slots 0-17 are drawn from frame/x/y below. */
struct C14aRoulette
{
    u16 startScript;        /* 0x00: 1 = start the script, 2 = leave */
    u16 count;              /* 0x02: party demons listed */
    u16 chamber;            /* 0x04: 0-5 */
    u16 pad06;
    u16 frame[18];          /* 0x08: 0 = slot hidden */
    u16 pad2C[2];
    u16 x[18];              /* 0x30 */
    u16 pad54[2];
    u16 y[18];              /* 0x58 */
    u16 pad7C[2];
    u16 mine[12];           /* 0x80: demon ids of the player's party, 0xFFFF = none */
    u16 theirs[12];         /* 0x98: the opponent's */
    u16 mode[12];           /* 0xB0: how the opponent's demon is derived from mine (RussianRoulette_MakeOpponentDemons) */
    u16 myPick;             /* 0xC8 */
    u16 theirPick;          /* 0xCA */
    u16 side;               /* 0xCC */
};

struct C14aTask
{
    u8 pad[0x1C];
    u16 result;     /* 0x1C */
    u16 result2;    /* 0x1E */
};

#define DmaSet3(src, dest, control)                  {                                                    vu32 *dmaRegs = (vu32 *)(REG_BASE + 0xD4);         dmaRegs[0] = (vu32)(src);                        dmaRegs[1] = (vu32)(dest);                       dmaRegs[2] = (vu32)(control);                    dmaRegs[2];                                  }

struct C14aMember
{
    u8 pad00[0xC];
    u8 slot;        /* 0x0C */
    u8 pad0D[5];
    u16 id;         /* 0x12 */
    u8 pad14[0x6C];
};

extern struct C14aMember gGameState[];  /* 0x030046C0: the hero's name is its first 8 bytes */
extern u16 gUnk_0203DB72;    /* opponent: 0-2 use gUnknown_0879F37C, 3 the name at 0x030050C8 */
extern u8 gUnk_030050C8[];
extern const void *const *const gUnknown_0879F334[];
extern const u8 gUnknown_0879F37C[][8];
extern const u8 gUnknown_0879F394[];
extern const u8 gUnknown_0879F39C[], gUnknown_0879F3A1[];
extern const u32 gUnknown_0879F3C4[];
s32 Combatant_IsUsed(s32 id);
u8 *Demon_GetRecord(u16 id);
struct C14aMember *Stock_FindDemon(u16 id);
void Name_Encode(const u8 *glyphs, u8 *out);
void Sprite_DrawSingle(const void *tmpl, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
u32 sub_0814E844(u32 slot);
void Party_Remove(u16 who, u32 release);
s32 Stock_AddDemon(u16 id);
struct C14aStockRec
{
    u8 pad00[0x10];
    u16 status;     /* 0x10 */
    u8 pad12[6];
    u16 unk18;      /* 0x18 */
};
struct C14aStockRec *Stock_FindByDemonId(u16 id);
s32 Flag_Test(u16 flag);
extern const u8 gUnknown_0879F3A6[], gUnknown_0879F3AE[], gUnknown_0879F3B6[], gUnknown_0879F3BC[];
extern const u8 gUnknown_087A045C[], gUnknown_087A055B[], gUnknown_087A065A[];
extern const u16 gUnknown_087A075A[];
struct C14aFlagged
{
    u16 id;
    u16 flag;
};
extern const struct C14aFlagged gUnknown_087A0772[];
void RussianRoulette_DrawSlot(u16 slot, u16 x, u16 y);
void RussianRoulette_SetSlot(u16 slot, u16 frame, u16 x, u16 y);
void sub_0814D748(u16 slot, u16 frame, u16 x, u16 y);
void RussianRoulette_DrawText(const u8 *str, u16 x, u16 y, u16 max, u16 palette);
void sub_0814DA70(u8 c, u16 x, u16 y, u16 palette);

#endif /* GUARD_CASINO3_H */
