#ifndef GUARD_C126_H
#define GUARD_C126_H

/* Code 0x081267F4-0x0812BF54: menu cursors, menu window graphics. Declarations copied from
   other headers where needed (those headers are not included here). */

#define DmaSet3(src, dest, control)              \
{                                                \
    vu32 *dmaRegs = (vu32 *)(REG_BASE + 0xD4);   \
    dmaRegs[0] = (vu32)(src);                    \
    dmaRegs[1] = (vu32)(dest);                   \
    dmaRegs[2] = (vu32)(control);                \
    dmaRegs[2];                                  \
}

/* DMA3 transfer followed by a busy wait for it to finish. */
#define DmaSet3Wait(src, dest, control)          \
{                                                \
    vu32 *dmaRegs = (vu32 *)(REG_BASE + 0xD4);   \
    dmaRegs[0] = (vu32)(src);                    \
    dmaRegs[1] = (vu32)(dest);                   \
    dmaRegs[2] = (vu32)(control);                \
    dmaRegs[2];                                  \
    while (dmaRegs[2] & 0x80000000)              \
        ;                                        \
}

#define DmaFill3Wait(value, dest, control)       \
{                                                \
    vu32 tmp = (value);                          \
    DmaSet3Wait(&tmp, dest, control);            \
}

typedef void (*VoidFunc)(void);

/* Menu cursor: 8 slots of 0x28 bytes at 0x03006480, updated by sub_08126A08. */
struct MenuCursor
{
    u8 state;       /* 0x00: 0 = free, 1 = idle, 2 = delayed, 3 = A, 4 = B, 5 = START,
                       6 = SELECT, 7 = L, 8 = R, 0xD = moved */
    u8 delay;       /* 0x01 */
    u8 mode;        /* 0x02: 0 = L/R report, 1 = L/R page */
    u8 flags;       /* 0x03: bit 0 = wrap vertically */
    u16 keys;       /* 0x04: repeated keys of the last update */
    u16 columns;    /* 0x06 */
    u16 rows;       /* 0x08 */
    u16 count;      /* 0x0A: columns * rows */
    u16 top;        /* 0x0C: first visible index */
    u16 onScreen;   /* 0x0E: index - top */
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
extern struct MenuCursor gUnk_03006480[];

struct Unk030063A0
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u8 filler8[4];
    u16 unkC;
    u16 unkE;
    u8 filler10[4];
    u16 unk14;
};
extern struct Unk030063A0 gUnk_030063A0;
/* The battle EWRAM block at 0x0203C200. Only fields used here are named. */
struct C126Block
{
    u8 filler0[0x998];
    u16 unk998;
};
extern u8 gUnk_0203C200[];
#define BLOCK ((struct C126Block *)gUnk_0203C200)

extern vu16 gKeysNew;      /* read as volatile: every test reloads it */
extern u16 gRepeatedKeys;
extern u16 gPaletteBuffer[0x200];
extern u16 gPaletteTarget[0x200];
extern u16 gWindowTilemapBuffer[];
extern u8 gUnk_030012B4[];
extern u8 gUnk_030000B4[];

void CpuSet(const void *src, void *dst, u32 control);
void CpuFastSet(const void *src, void *dst, u32 control);
u32 __udivsi3(u32 a, u32 b);
u32 __umodsi3(u32 a, u32 b);
void m4aSongNumStart(u16 n);
void Palette_CopyWithEffect(u32 a0, const void *src, void *dst, u32 a3, u32 a4);
void Palette_MarkDirty(void);
void VBlankTask_AddCounted(VoidFunc func, u32 count);

extern const u16 gUnknown_08777D34[];
extern const u32 gUnknown_08772534[];
extern const u16 gUnknown_08772514[];
extern const u16 gUnknown_08771ED4[];
extern const u8 gUnknown_08770ED4[];
extern const u8 gUnknown_08770C54[];
extern const u16 gUnknown_08770A24[];

/* this region */
void sub_08126850(void);
void sub_08126898(struct MenuCursor *c);
u8 sub_081268E4(u8 id, struct MenuCursor *src);
void sub_081269B0(u8 id);
void sub_08126A08(u8 id);
void sub_08126D34(u16 se);
void sub_08126F84(void);
void sub_08126FEC(void);
void sub_08127054(void);
void sub_08127090(void);
void sub_080E5668(VoidFunc func);
void sub_081270CC(u8 x, u8 y, u8 w, u8 h, const u16 *src);
void sub_0812712C(void);
void sub_081271C0(void);

#endif /* GUARD_C126_H */
