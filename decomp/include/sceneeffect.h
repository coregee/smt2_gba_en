#ifndef GUARD_SCENEEFFECT_H
#define GUARD_SCENEEFFECT_H

#include "global.h"

/* Field event effects 0x080BA1AC-0x080BD878. Declarations copied from game.h / bflow.h
   are kept here so this header can be used alone. */

typedef void (*VoidFunc)(void);

#define DmaSet(dmaNum, src, dest, control)                      \
{                                                               \
    vu32 *dmaRegs = (vu32 *)(0x040000B0 + 12 * (dmaNum));       \
    dmaRegs[0] = (vu32)(src);                                   \
    dmaRegs[1] = (vu32)(dest);                                  \
    dmaRegs[2] = (vu32)(control);                               \
    dmaRegs[2];                                                 \
}

/* Variant whose source is evaluated before the DMA register address. */
#define DmaSetS(dmaNum, src, dest, control)                     {                                                                   const void *_src = (const void *)(src);                         vu32 *dmaRegs = (vu32 *)(0x040000B0 + 12 * (dmaNum));           dmaRegs[0] = (vu32)_src;                                        dmaRegs[1] = (vu32)(dest);                                      dmaRegs[2] = (vu32)(control);                                   dmaRegs[2];                                                 }

#define DMA_FILL32(dmaNum, value, dest, size)                                       \
{                                                                                   \
    vu32 tmp = (vu32)(value);                                                       \
    DmaSet(dmaNum, &tmp, dest, (0x8000 | 0x0400 | 0x0100) << 16 | ((size) / 4));    \
}

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

/* Field state at 0x03004550 (same layout as in game.h). */
struct Unk03004550
{
    u16 unk00;
    u16 unk02;          /* facing */
    u16 unk04;
    u16 unk06;
    s16 unk08;
    u16 unk0A;
    u16 unk0C;
    u16 unk0E;
    u16 unk10;
    u16 unk12;          /* x */
    u16 unk14;          /* y */
    u16 unk16;
    u16 unk18;
    u16 unk1A;
    u16 unk1C;
    u16 unk1E;
    u16 unk20;
    u16 unk22;
    u32 unk24;
    u16 unk28;
    u16 unk2A;
    u16 unk2C;
    u16 unk2E;
    u16 unk30;
    u16 unk32;
    u16 unk34;
    u16 unk36;
    u16 unk38;
    u16 unk3A;
    u16 unk3C;
    u16 unk3E;
    u32 unk40;
    u16 unk44;
    u16 unk46;
    u16 unk48;
    u16 unk4A;
    u16 unk4C;
    u16 unk4E;
    u16 unk50;
    u16 unk52;
    u16 unk54;
    u16 unk56;
    u32 unk58;
    u16 unk5C;
    u16 unk5E;
};
extern struct Unk03004550 gFieldState;

struct PalFade;

/* Code copied to IWRAM (called through fixed addresses). */
typedef void (*IwramFunc)(const void *);
#define IwramFunc_3BC1 ((IwramFunc)0x03003BC1)
#define IwramFunc_4011 ((IwramFunc)0x03004011)

struct MapHeader
{
    u8 pad00[0x06];
    s16 unk06;
};
struct MapHeader *DungeonMap_GetFloor(u16 a, u16 b);

void LZ77UnCompWram(const void *src, void *dst);
void VBlankTask_AddCounted(VoidFunc func, u32 count);
void Palette_CopyWithEffect(u32 a0, const void *src, void *dst, u32 a3, u32 a4);
struct PalFade *PalFade_FadeRangeInFromBlackTagged(u16 start, u16 count, u16 delay, u16 tag);
void PalFade_FadeRangeInFromBlack(u16 start, u16 count, u16 delay);
void Sprite_Draw(const void *def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y);
void sub_080B29A8(u16 mode);
u16 sub_080B1A1C(u16 a);
void sub_080B2880(void);
void sub_080ADF64(void);
void sub_080C1F50(u16 a, u16 b, u16 *x, u16 *y);
struct Task *Task_Create(const void *script, u32 parent);

extern void *gUnk_03003FC0;
extern struct PalFade *gUnk_0300452C;
extern u16 gUnk_03004614;
extern u8 gUnk_02001000[];
extern u16 gUnk_0300000E;
extern u8 gUnk_03000038;
extern u8 gUnk_03000039;
extern u8 gUnk_0300003A;
extern u16 gPaletteTarget[0x200];

/* 0x080BA1AC.. */
void sub_080BA170(void);
void sub_080BA1F8(void);
void Elevator_SetScroll(struct Task *task);
u32 sub_080BA5E0(s16 dx, s16 dy);

/* Elevator task data (task->data). pos is applied to the BG3 V-offset shadow 0x0300000E
   (0xA8 pixels per floor); unk30/unk32 are the door sprite offsets (0x8000 = hidden). */
struct ElevatorData
{
    u32 unk00;
    u32 unk04;
    u32 from;               /* 0x08: index into floors */
    u32 to;                 /* 0x0C */
    u8 pad10[0x10];
    u16 floors[8];          /* 0x20 */
    u16 unk30;              /* 0x30 */
    u16 unk32;
    union
    {
        u32 full;
        struct
        {
            u16 frac;
            u16 whole;
        } part;
    } speed;                /* 0x34 */
    u16 pos;                /* 0x38 */
    u16 dist;               /* 0x3A */
};

struct StepEffect
{
    const void *data;
    s16 dx;
    s16 dy;
};
extern const struct StepEffect gUnknown_08173D04[], gUnknown_08173FBC[], gUnknown_08174144[], gUnknown_0817410C[];
extern const u16 gUnknown_0817417C[][4];

extern const u8 gUnknown_08173578[];
extern const u8 gUnknown_08165AD4[], gUnknown_081660D4[];
extern const u16 gUnknown_08165A54[], gUnknown_08165A94[], gUnknown_08165AB4[];
extern const u8 gUnknown_08002D08[], gUnknown_08002D44[], gUnknown_08002CAC[], gUnknown_08002C88[], gUnknown_08002C70[];

/* 0x080BA758.. */
void CpuSet(const void *src, void *dest, u32 control);
void Tilemap_CopyRectSkipZero(const void *src, void *buf, u32 a2, u32 a3, u32 x, u32 y, u32 w, u32 h);
u32 BgPicture_StartTask(u32 a);
void CharObj_End(struct Task *t, u32 a);
void Window_Close(void *window, u32 arg1);
struct Task *CharObj_Create(u32 a, u16 b, u16 c, u16 d, u16 e, u32 f);
void sub_080BA758(void);
void SceneEffect_Stop(void);
void sub_080BA9CC(void);
void sub_080BA9F0(struct Task *task);
void sub_080BAA14(struct Task *task);
void sub_080BAA38(void);
void sub_080BAB98(void);
void sub_080BACC4(void);
void sub_080BAD28(void);

extern u32 gUnk_03004638;
extern struct Task *gSceneEffectTask;
extern u32 gUnk_0200AB04;
extern u16 gUnk_02000000[];
extern u16 gUnk_03000004;
extern u16 gUnk_03000006;
extern u8 gUnk_03000030;
extern u8 gUnk_03000031;
extern u8 gUnk_03000034;
extern u8 gUnk_03000035;
extern u32 gFrameCounter;
extern struct Task *gCharTasks[8];
extern void *gMsgWindow;
extern u16 gMsgWindowOpen;

extern const u8 gUnknown_08182270[], gUnknown_08182688[];
extern const u32 gUnknown_08182AA0[];
extern const void *const gUnknown_08182B20[], *const gUnknown_08182B54[];
extern const u8 gUnknown_08182F4C[], gUnknown_081831B4[], gUnknown_08183474[], gUnknown_08182CC4[];
extern const u16 gUnknown_08183454[], gUnknown_08183434[];
extern const u8 gUnknown_0800781C[], gUnknown_08007844[];

/* 0x080BAEA8.. */
struct Task *Char_FindById(u16 id);
u32 Palette_IsBg13Black(void);
void Palette_MarkDirty(void);
struct PalFade *PalFade_FadeRangeToBlack(u16 start, u16 count, u16 delay);
struct PalFade *PalFade_FadeRangeToWhite(u16 start, u16 count, u16 delay);
struct PalFade *PalFade_FadeRangeToBlackWithDuration(u16 start, u16 count, u16 delay, u16 duration);
u32 Random_Byte(void);
void sub_080C1440(void);
void sub_080C7C60(void);
void sub_080C48CC(struct Task *t, u16 x, u16 y);
void Flag_Set(u32 flag);
void Flag_Clear(u32 flag);
u32 Flag_Test(u32 flag);
void sub_080BAECC(void);
void sub_080BAF7C(void);

extern u16 gPaletteBuffer[0x200];
extern u16 gUnk_03000040;
extern const u8 gUnknown_081839F4[], gUnknown_081845E4[], gUnknown_08184BC4[], gUnknown_0818596C[], gUnknown_08186524[];
extern const u16 gUnknown_08184BA4[];

/* 0x080BB33C.. */
/* Scaled sprite effect data (task->data). The affine blocks are {unused, scaleX, scaleY,
   angle}, the layout Sprite_DrawSharedAffine expects behind its sprite pointer. */
struct AffineEffect
{
    u16 affine[4];      /* 0x00 */
    u16 x;              /* 0x08 */
    u16 y;              /* 0x0A */
    u16 unk0C;
    u16 ringOn;         /* 0x0E */
    u16 ringFrame;      /* 0x10 */
    u16 ring[4];        /* 0x12: affine block of the ring sprite */
    u16 shrink;         /* 0x1A */
    u16 glowOn;         /* 0x1C */
    u16 glowFrame;      /* 0x1E */
    u16 unk20;
    u16 pad22;
    u16 *wait;          /* 0x24: from BgPicture_StartTask */
};

struct AffineEffect2
{
    u16 affine[4];      /* 0x00 */
    u16 x;              /* 0x08 */
    u16 y;              /* 0x0A */
    u16 timer;          /* 0x0C */
    u16 pad0E;
    u16 *wait;          /* 0x10: from BgPicture_StartTask */
};

void ObjList_ScalePositions(const void **def, u16 scaleX, u16 scaleY, u32 n);
void Sprite_DrawSharedAffine(const void **def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y,
                  u8 matrix);
void Sound_Play(u32 se);
void sub_080C14FC(void);
void sub_080C153C(void);
void Tilemap_FillRect(u32 value, u16 *map, u16 x, u16 y, u16 w, u16 h);
void sub_080BB318(void);
void sub_080BB61C(void);
void sub_080BB8A0(void);

extern void *gUnk_03004640;
extern u16 gRepeatedKeys;
extern u16 gHudState[];
extern u8 gUnk_03003800[];
extern const void *const gUnknown_080073B0[], *const gUnknown_08007174[], *const gUnknown_080071FC[], *const gUnknown_080071B0[];
extern const void *const *const gUnknown_081894B4[], *const *const gUnknown_081894C8[];
extern const u8 gUnknown_08186EB0[], gUnknown_081873FC[], gUnknown_08187D00[], gUnknown_081892C8[];
extern const u16 gUnknown_08189434[], gUnknown_08189454[], gUnknown_08189474[], gUnknown_08189494[];
extern const u8 gUnknown_08189570[], gUnknown_08189BFC[];
extern const u16 gUnknown_08189BDC[], gUnknown_0818B1C0[];

/* 0x080BB964.. */
struct GfxRow
{
    const void *gfx;
    const u8 *pals;
};

void sub_080BB868(const void *src, const u8 *pals, void *dst, u16 *map);
void sub_080BB928(void);
void sub_080BBA1C(void);
void sub_080BBA64(struct Task *task);

extern u8 gUnk_0300003B;
extern u8 gAutomapCells[];
extern u16 gUnk_0300000C;
extern u16 gUnk_03004534;
extern const u8 gUnknown_08181238[], gUnknown_08181F84[], gUnknown_08180BA0[];
extern const u16 gUnknown_08181138[];
extern const struct GfxRow gUnknown_0818B2E0[];

/* 0x080BBCFC.. */
void Task_End(struct Task *task);
void sub_080B8AE0(u32 a, u32 b);
void sub_080BBCD8(void);
void sub_080BBCFC(void);
void sub_080BC028(void);

extern const u8 gUnknown_08174294[], gUnknown_08174D18[], gUnknown_0818C0C8[];
extern const u16 gUnknown_08174CF8[], gUnknown_081755F0[], gUnknown_0817748C[], gUnknown_0818C5E0[];
extern const void *const gUnknown_0818B5F0[];
extern const void *const gUnknown_0818B60C[], *const gUnknown_0818B720[], *const gUnknown_0818B834[], *const gUnknown_0818B960[];

/* 0x080BC0A4.. */
void sub_0815851C(const void **def);
void sub_080BA7A0(u32 which);
void sub_080BA7CC(const void *const *srcs, const u8 *rows, u32 width, s32 row, s32 mirror);
void sub_080BAD88(struct Task *task, u32 id, u32 dx, u32 dy);
void Char_EndById(struct Task *task, u16 id);
void sub_080B0820(void);
void sub_080B0778(void);
void BgPicture_LoadPalette(void);

extern const void *const gUnknown_0800786C[];
extern const void *const gUnknown_0818F010[];
extern const u8 gUnknown_0818EEA0[];

/* 0x080BC5A8.. */
/* Only the palette field of these records is used here. */
struct CharGfxRecord
{
    u8 pad00[0x24];
    const u16 *palette;     /* 0x24 */
};
struct DemonGfxRecord
{
    u16 flags;
    u16 pad02;
    const u16 *palette;     /* 0x04 */
};
struct CharGfxRecord *Char_GetRecord(u16 id);
struct DemonGfxRecord *sub_080D8248(u16 id);
void sub_080BC560(void);
void sub_080BC584(void);
void sub_080BC978(void);

extern u8 gUnk_03000032;
extern u8 gUnk_03000033;
extern u8 gUnk_03000036;
extern u8 gUnk_03000037;
extern const u8 gUnknown_08554E10[], gUnknown_08555260[], gUnknown_08552CE0[], gUnknown_085537C8[], gUnknown_08554300[], gUnknown_08554AE4[];
extern const u16 gUnknown_08555694[], gUnknown_08554AC4[], gUnknown_08554DF0[];
extern const void *const gUnknown_0818F54C[];

/* 0x080BCA6C.. */
void sub_080BCC14(void);

extern const void *const gUnknown_0818F634[];
extern const u8 gUnknown_0818F564[], gUnknown_0818F650[], gUnknown_0818F760[];
extern const void *const gUnknown_08006170[];
extern const u8 gUnknown_08532ABC[];
extern const u16 gUnknown_08532D50[];

/* 0x080BCCB4.. */
void sub_080C3818(u32 a);
void sub_080B04BC(void);
void sub_080C1450(void);
struct PalFade *PalFade_FadeRangeWithDuration(u16 start, u16 count, u16 delay, u16 duration);
void sub_080BCDC4(struct Task *task);
void sub_080BCE0C(struct Task *task);

extern u32 gUnk_030068F0[];
extern u16 gUnk_0203DB28[];

/* 0x080BCFB0.. */
void sub_080C6E30(u32 a);
void sub_080BCEF0(void);
void sub_080BCFB0(struct Task *task);
void sub_080BD01C(void);
void sub_080BD130(void);

extern const u8 gUnknown_08194C78[];
extern const u16 gUnknown_08195278[], gUnknown_08196438[], gUnknown_08196C80[];
extern const void *const gUnknown_080075D8[], *const gUnknown_080075A0[];
extern const void *const *const gUnknown_08196CA0[];

/* Two-sprite scaled animation (task->data), see sub_080BD154 / sub_080BD1C4. */
struct AffineAnim
{
    u16 affine[4];      /* 0x00: unused, scaleX, scaleY, angle */
    u16 frame;          /* 0x08 */
    u16 timer;          /* 0x0A */
    u16 x2;             /* 0x0C */
    u16 y2;             /* 0x0E */
    u16 x1;             /* 0x10 */
    u16 y1;             /* 0x12 */
};

/* Data of the object tasks in gCharTasks (created by CharObj_Create). */
struct ObjData
{
    u16 unk00;
    u16 palSlot;        /* 0x02: 0 -> palette 14, 1 -> 15, else 13 */
    u16 hasPal;         /* 0x04 */
    u16 id;             /* 0x06 */
    u16 x;              /* 0x08 */
    u16 y;              /* 0x0A */
    u16 unk0C;
    u16 unk0E;
    u16 unk10;          /* 0x10 */
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 frame;          /* 0x18 */
};

struct ShakeData
{
    u16 unk00[3];
    s16 shakeY;         /* 0x06 */
    s16 shakeX;         /* 0x08 */
};

/* Scrolling picture rows (task->data), see sub_080BBA64. */
struct RowScroll
{
    u16 row;            /* 0x00: next source row (counts down) */
    u16 mapRow;         /* 0x02: destination tilemap row, 0-63 */
    u16 slot;           /* 0x04: destination 1 KB tile slot, 0-15 */
};

/* 0x080BD2A8.. */
void sub_080BD334(void);
void sub_080BD468(void);

extern u16 gDispRegs;
extern u16 gUnk_03000002;
extern const u16 gUnknown_081974F4[];

/* 0x080BD5CC.. */
void Sprite_DrawSharedAffineDouble(const void **def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y,
                  u8 matrix, u16 objMode);
void sub_080E9044(u32 h, u16 i);
void Palette_FillWithEffect(u32 a0, u32 a1, void *dest, u32 size, u32 a4);

extern u32 gUnk_030069C0;
extern const void *const gUnknown_080078A8[];
extern const u16 gUnknown_0818C600[];

#endif /* GUARD_SCENEEFFECT_H */
