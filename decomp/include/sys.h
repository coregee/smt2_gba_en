#ifndef GUARD_SYS_H
#define GUARD_SYS_H

/* System code: AgbMain, interrupts, key input, VBlank tasks, OAM. */

#define DMA_ENABLE      0x8000
#define DMA_START_NOW   0x0000
#define DMA_16BIT       0x0000
#define DMA_32BIT       0x0400
#define DMA_SRC_FIXED   0x0100
#define DMA_DEST_INC    0x0000

#define DmaSet(dmaNum, src, dest, control)        \
{                                                 \
    vu32 *dmaRegs = (vu32 *)(0x040000B0 + 12 * (dmaNum)); \
    dmaRegs[0] = (vu32)(src);                     \
    dmaRegs[1] = (vu32)(dest);                    \
    dmaRegs[2] = (vu32)(control);                 \
    dmaRegs[2];                                   \
}

#define DMA_FILL(dmaNum, value, dest, size, bit)                                              \
{                                                                                             \
    vu##bit tmp = (vu##bit)(value);                                                           \
    DmaSet(dmaNum, &tmp, dest,                                                                \
           (DMA_ENABLE | DMA_START_NOW | DMA_##bit##BIT | DMA_SRC_FIXED | DMA_DEST_INC) << 16 \
         | ((size)/(bit/8)));                                                                 \
}

#define DmaFill16(dmaNum, value, dest, size) DMA_FILL(dmaNum, value, dest, size, 16)
#define DmaFill32(dmaNum, value, dest, size) DMA_FILL(dmaNum, value, dest, size, 32)

#define DMA_COPY(dmaNum, src, dest, size, bit)                                              \
    DmaSet(dmaNum, src, dest,                                                               \
           (DMA_ENABLE | DMA_START_NOW | DMA_##bit##BIT | DMA_DEST_INC) << 16 \
         | ((size)/(bit/8)))

#define DmaCopy16(dmaNum, src, dest, size) DMA_COPY(dmaNum, src, dest, size, 16)
#define DmaCopy32(dmaNum, src, dest, size) DMA_COPY(dmaNum, src, dest, size, 32)

typedef void (*VoidFunc)(void);

/* Key state with auto-repeat (0x03003968). */
struct KeyRepeat
{
    u16 prev;
    u16 held;
    u16 pressed;
    u8 timer;
    u8 unk7;
};

/* VBlank task slot (0x03003900, 10 slots). */
struct VBlankTask
{
    u16 state;     /* 0 free, 1 runs only when the main loop is idle, 2 runs every VBlank */
    u16 counter;   /* remaining runs, 0xFFFF = forever */
    VoidFunc func;
};

struct OamData
{
    /*0x00*/ u32 y:8;
    /*0x01*/ u32 affineMode:2;
             u32 objMode:2;
             u32 mosaic:1;
             u32 bpp:1;
             u32 shape:2;
    /*0x02*/ u32 x:9;
             u32 matrixNum:3;   /* only 3 bits: the game never uses matrices 8-31 */
             u32 hFlip:1;
             u32 vFlip:1;
             u32 size:2;
    /*0x04*/ u16 tileNum:10;
             u16 priority:2;
             u16 paletteNum:4;
    /*0x06*/ u16 affineParam;
};

/* The three OAM attributes, as stored in sprite data. */
struct OamTemplate
{
    u16 attr0;
    u16 attr1;
    u16 attr2;
};

/* Sprite queued for this frame (0x03002130, 128 entries), linked per layer. */
struct SpriteNode
{
    struct OamData oam;
    s8 next;
    u8 pad[3];
};

struct AffineSlot
{
    u16 unk0[4];
    s16 pa, pb, pc, pd;
};

extern struct OamData gOamBuffer[128];
extern struct SpriteNode gSpriteNodes[128];
/* Head of each layer's sprite list (-1 = empty).  A packed bitfield: clearing it compiles
   to a read-modify-write (ldrb/orr/strb) in Sprites_ClearLayers. */
struct SpriteLayer
{
    s8 head:8;
} __attribute__((packed));

extern struct SpriteLayer gSpriteLayers[10];
extern s8 gSpriteNodeCount;
extern u32 gUnk_030031C8;
extern u32 gAffineCount;
extern struct AffineSlot gAffineSlots[32];
extern u8 gDigits[8];
extern u16 gPaletteBuffer[];
extern u16 gWindowMap[64][32];
extern u16 gDispRegs;
extern u16 gUnk_03000002;
extern u16 gUnk_03000004;
extern u16 gUnk_03000006;
extern u16 gUnk_03000008;
extern u16 gUnk_0300000A;
extern u16 gUnk_0300000C;
extern u16 gUnk_0300000E;

extern const VoidFunc gIntrTableTemplate[14];
extern VoidFunc gIntrTable[14];
extern u16 gUnk_030031B4;
extern u16 gUnk_030031EC;
extern u32 gInMainLoop;
extern u32 gFrameCounter;
extern VoidFunc gMainCallback;
extern VoidFunc gVBlankCallback;
extern u32 gIntrMainBuffer[];
extern vu16 gVBlankFlag;
extern vu16 gHeldKeys;
extern vu16 gUnk_030031D0;
extern vu16 gNewKeys;
extern vu16 gKeysNew;
extern struct KeyRepeat gKeyRepeat;
extern u16 gRepeatedKeys;
extern struct VBlankTask gVBlankTasks[10];

void IntrMain(void);
void IntrDummy(void);
void m4aSoundInit(void);
void m4aSoundMain(void);
void m4aSoundVSync(void);
void Sram_FormatIfInvalid(void);
void InitMemory(void);
void ClearWorkRam(void);
void ClearVideoMemory(void);
void ClearVram(void);
void ResetOam(void);
void ClearPaletteRam(void);
void InitInterrupts(void);
void SetVBlankCallback(VoidFunc func);
void ClearVBlankFlag(void);
void AcknowledgeVBlank(void);
void Keys_Init(void);
void Keys_Read(void);
void VBlankTasks_Init(void);
void VBlankHandler(void);
struct VBlankTask *VBlankTask_FindFree(void);
struct VBlankTask *VBlankTask_Add(VoidFunc func);
struct VBlankTask *VBlankTask_AddCounted(VoidFunc func, u16 count);
void VBlankTasks_Run(u16 phase);
void Sprites_BeginFrame(void);
void Sprites_BuildOam(void);
void Sprites_ClearLayers(void);
void PalFade_Init(u32 arg);
bool32 Palette_IsDirty(void);
void Palette_ClearDirty(void);
void PalFade_UpdateAll(void);
void sub_080DF2E8(void);
void sub_080DF15C(void);
void sub_080C2998(void);
void Options_Load(void);
void sub_080D5B8C(u32 arg);
void Game_NewGame(void);
void System_CheckSoftReset(void);
void sub_080DF370(void);
void Random_Next(void);
void sub_080DF360(void);

/* Sprite definitions are two pointers: {count, count * 3 OAM halfwords} and an optional
   affine table {count, count * {angle, scaleX, scaleY}}. */

extern const s16 gSineTable[];   /* sine table, 256 steps per turn, cos = [a + 0x40] */

struct SpriteNode *Sprite_Alloc(u8 layer);
s16 FixedMul8(s16 a, s16 b);
s16 FixedDiv8(s16 a, s16 b);
s16 FixedInverse8(s16 a);
void Sprite_DrawWithMode(const u16 **def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y,
                  u16 objMode);

/* Palette fade (0x03002730, 8 slots): moves the palette buffer gPaletteBuffer towards the
   target palette gPaletteTarget. */
struct PalFade
{
    u16 active;
    u16 duration;   /* steps left, 0xFFFF = until the target is reached */
    u16 delay;      /* frames per step */
    u16 timer;
    u16 start;      /* first colour */
    u16 count;      /* number of colours */
    u16 waitTag;    /* bit 15: this fade's tag; otherwise wait while a fade tagged so runs */
    u16 pad;
    u16 accum[32];  /* per-component-value step accumulators (units of 1/1000) */
};

extern struct PalFade gPalFades[8];
extern u16 gPaletteTarget[0x200];
extern u32 gPaletteDirty;
extern const u16 gPalFadeStepTable[32];

void Palette_MarkDirty(void);
struct PalFade *PalFade_FindTagged(u16 tag);
void PalFade_AccumulateSteps(struct PalFade *fade);
void PalFade_WrapSteps(struct PalFade *fade);
u16 PalFade_StepComponent(struct PalFade *fade, u16 cur, u16 target);
void PalFade_Update(struct PalFade *fade);
struct PalFade *PalFade_FindFree(void);
void PalFade_Setup(struct PalFade *fade, u16 start, u16 count, u16 delay);
void Palette_FillWithEffect(u32 a0, u32 a1, void *dest, u32 size, u32 a4);
struct PalFade *PalFade_FadeInFromBlack(u16 delay);
struct PalFade *PalFade_FadeToBlack(u16 delay);
struct PalFade *PalFade_FadeRangeToWhite(u16 start, u16 count, u16 delay);
struct PalFade *PalFade_FadeRangeToBlack(u16 start, u16 count, u16 delay);
u16 PalFade_AllDone(void);

/* Window rectangle of a window object (object + 0x24); the window grows or shrinks one row
   per step between 2 rows and h. */
struct WinRect
{
    u16 x;
    u16 y;
    u16 w;
    u16 h;
    u16 bg;        /* 0-3: which 4 KB VRAM block the map buffer is uploaded to */
    u16 curH;
    u16 unkC;
    u16 altFrame;  /* 1: use the alternative frame tiles when h == 4 */
};

struct WindowObj
{
    u16 active;
    u8 unk2[0x1A];
    u16 done;
    u16 cmd;
    u8 unk20[4];
    struct WinRect rect;
};

extern u16 gWindowTilemapBuffer[0x400];
extern u32 gWindowCount;
extern u16 gHudState[0x20];
extern u16 gUnk_03004614;
extern const u16 gWindowFrameTiles[9];
extern const u16 gWindowFrameTilesAlt[9];
extern const u8 gUnknown_0815EB44[];

void Tilemap_FillRect(u16 value, u16 (*map)[32], u16 x, u16 y, u16 w, u16 h);
void WindowMap_UploadToBg0(void);
void WindowMap_UploadToBg1(void);
void WindowMap_UploadToBg2(void);
void WindowMap_UploadToBg3(void);
void Window_DrawFrame(struct WinRect *rect, u16 x, u16 y, u16 w, u16 h);
void WindowMap_QueueUpload(u32 bg);
void Window_Erase(struct WindowObj *win);
struct WindowObj *Window_Create(u16 x, u16 y, u16 w, u16 h, u16 bg);
void *Task_Create(const void *script, u16 arg);
void Task_End(void *obj);
u32 sub_080C8AF8(u16 arg);
void FieldMain_Loop(void);

#endif /* GUARD_SYS_H */
