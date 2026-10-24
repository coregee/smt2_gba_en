/* Program entry, hardware init, interrupts, key input and VBlank tasks. */

#include "global.h"
#include "sys.h"

// AgbMain @ 0x080A96CC
void AgbMain(void)
{
    u32 i;
    const VoidFunc *src;
    VoidFunc *dst;

    REG_WAITCNT = 0x4014;
    InitMemory();
    for (i = 0, src = gIntrTableTemplate, dst = gIntrTable; i < 14; i++)
        *dst++ = *src++;
    Sram_FormatIfInvalid();
    m4aSoundInit();
    gUnk_030031B4 = 0;
    gUnk_030031EC = 0;
    gInMainLoop = 0;
    InitInterrupts();
    VBlankTasks_Init();
    Keys_Init();
    gFrameCounter = 0;
    PalFade_Init(0);
    sub_080DF2E8();
    sub_080C2998();
    sub_080C2AA8();
    sub_080D5B8C(0);
    sub_080C10F4();
    for (;;)
    {
        gInMainLoop = 1;
        Keys_Read();
        System_CheckSoftReset();
        sub_080DF370();
        m4aSoundMain();
        Sprites_BeginFrame();
        gMainCallback();
        Sprites_BuildOam();
        PalFade_UpdateAll();
        gFrameCounter++;
        Random_Next();
        sub_080DF360();
        gInMainLoop = 0;
        VBlankIntrWait();
    }
}

// InitMemory @ 0x080A9794
void InitMemory(void)
{
    ClearWorkRam();
    ClearVideoMemory();
}

// ClearWorkRam @ 0x080A97A4
void ClearWorkRam(void)
{
    DmaFill32(3, 0, (void *)0x02000000, 0x40000);
    DmaFill32(3, 0, (void *)0x03000000, 0x7E00);
}

// ClearVideoMemory @ 0x080A97E0
void ClearVideoMemory(void)
{
    ClearVram();
    ResetOam();
    ClearPaletteRam();
}

// ClearVram @ 0x080A97F4
void ClearVram(void)
{
    DmaFill16(3, 0, (void *)0x06000000, 0x18000);
}

// ResetOam @ 0x080A981C
/* Hides all 128 OAM entries and sets the 32 affine matrices to identity. */
void ResetOam(void)
{
    vu16 *oam = (vu16 *)0x07000000;
    s32 i;

    for (i = 0; i < 32; i++)
    {
        *oam++ = 0x200; *oam++ = 0; *oam++ = 0; *oam++ = 0x100;
        *oam++ = 0x200; *oam++ = 0; *oam++ = 0; *oam++ = 0;
        *oam++ = 0x200; *oam++ = 0; *oam++ = 0; *oam++ = 0;
        *oam++ = 0x200; *oam++ = 0; *oam++ = 0; *oam++ = 0x100;
    }
}

// ClearPaletteRam @ 0x080A9880
void ClearPaletteRam(void)
{
    DmaFill16(3, 0, (void *)0x05000000, 0x400);
}

// FixedMul8 @ 0x080A98A8
s16 FixedMul8(s16 a, s16 b)
{
    s32 r;

    r = a * b;
    r = r / 256;
    return r;
}

// FixedDiv8 @ 0x080A98C4
s16 FixedDiv8(s16 a, s16 b)
{
    return (a << 8) / b;
}

// FixedInverse8 @ 0x080A98DC
s16 FixedInverse8(s16 a)
{
    s32 one = 0x10000;

    return one / a;
}

// InitInterrupts @ 0x080A98F4
void InitInterrupts(void)
{
    ClearVBlankFlag();
    gVBlankCallback = IntrDummy;
    DmaCopy16(3, IntrMain, gIntrMainBuffer, 0x200);
    *(u32 **)0x03007FFC = gIntrMainBuffer;
}

// SetVBlankCallback @ 0x080A9934
void SetVBlankCallback(VoidFunc func)
{
    gVBlankCallback = func;
    if (func == NULL)
        gVBlankCallback = IntrDummy;
}

// VBlankIntr @ 0x080A9950
void VBlankIntr(void)
{
    if (gVBlankCallback != NULL)
        gVBlankCallback();
    AcknowledgeVBlank();
}

// HBlankIntr @ 0x080A996C
void HBlankIntr(void)
{
}

// IntrDummy @ 0x080A9970
void IntrDummy(void)
{
}

// ClearVBlankFlag @ 0x080A9974
void ClearVBlankFlag(void)
{
    gVBlankFlag &= ~1;
}

// AcknowledgeVBlank @ 0x080A9988
void AcknowledgeVBlank(void)
{
    REG_IF = 1;
    gVBlankFlag = 1;
}

// WaitForVBlank @ 0x080A999C
/* Waits for the next VBlank with Halt. */
void WaitForVBlank(void)
{
    ClearVBlankFlag();
    do
        asm("swi 0x2");
    while (!(gVBlankFlag & 1));
}

// Keys_Init @ 0x080A99BC
void Keys_Init(void)
{
    gHeldKeys = gUnk_030031D0 = 0;
    gNewKeys = gKeysNew = 0;
    gKeyRepeat.prev = 0xFFFF;
    gKeyRepeat.held = 0;
    gRepeatedKeys = 0;
    gKeyRepeat.pressed = 0;
    gKeyRepeat.timer = 0;
    gKeyRepeat.unk7 = 0;
}

// Keys_Read @ 0x080A9A04
/* Reads the keypad: new presses, held keys, and an auto-repeating "pressed" mask. */
void Keys_Read(void)
{
    u16 keys = REG_KEYINPUT ^ 0x3FF;
    struct KeyRepeat *k;

    gKeysNew = gNewKeys = keys & ~gHeldKeys;
    gUnk_030031D0 = gHeldKeys = keys;
    k = &gKeyRepeat;
    k->held = gUnk_030031D0;
    k->pressed = k->held & ~k->prev;
    if (k->prev != k->held)
        k->unk7 = 8;
    if (k->held & k->prev)
    {
        if (k->timer > 15)
        {
            k->timer -= 2;
            k->unk7 = 16;
            gRepeatedKeys = k->held;
        }
        else
        {
            gRepeatedKeys = 0;
            k->timer++;
        }
    }
    else
    {
        k->timer = 0;
        k->unk7 = 8;
        gRepeatedKeys = k->pressed;
    }
    k->prev = k->held;
}

// SetMainCallback @ 0x080A9AB4
void SetMainCallback(VoidFunc func)
{
    gMainCallback = func;
}

// VBlankTasks_Init @ 0x080A9AC0
void VBlankTasks_Init(void)
{
    DmaFill32(3, 0, gVBlankTasks, sizeof(gVBlankTasks));
    SetVBlankCallback(VBlankHandler);
}

// VBlankHandler @ 0x080A9AF4
/* VBlank handler: during an idle main loop copies the scroll registers, OAM and (when dirty)
   palettes; on a lag frame only the scroll registers, and runs the sound mixer itself. */
void VBlankHandler(void)
{
    m4aSoundVSync();
    sub_080DF15C();
    if (gInMainLoop == 0)
    {
        DmaCopy32(3, &gDispRegs, &REG_BG0HOFS, 0x44);
        DmaCopy32(3, gOamBuffer, (void *)0x07000000, 0x400);
        if (Palette_IsDirty() == 1)
        {
            DmaCopy32(3, gPaletteBuffer, (void *)0x05000000, 0x400);
            Palette_ClearDirty();
        }
        VBlankTasks_Run(1);
    }
    else
    {
        REG_BG0HOFS = gDispRegs;
        REG_BG0VOFS = gUnk_03000002;
        REG_BG1HOFS = gUnk_03000004;
        REG_BG1VOFS = gUnk_03000006;
        REG_BG2HOFS = gUnk_03000008;
        REG_BG2VOFS = gUnk_0300000A;
        REG_BG3HOFS = gUnk_0300000C;
        REG_BG3VOFS = gUnk_0300000E;
        VBlankTasks_Run(2);
        m4aSoundMain();
    }
    *(u16 *)0x03007FF8 = 1;
}

// VBlankTask_FindFree @ 0x080A9BE8
struct VBlankTask *VBlankTask_FindFree(void)
{
    u32 i;
    struct VBlankTask *task;

    for (i = 0, task = gVBlankTasks; i < 10; task++, i++)
    {
        if (task->state == 0)
            return task;
    }
    return NULL;
}

// VBlankTask_Add @ 0x080A9C0C
struct VBlankTask *VBlankTask_Add(VoidFunc func)
{
    struct VBlankTask *task = VBlankTask_FindFree();

    if (task != NULL)
    {
        task->state = 1;
        task->counter = 0xFFFF;
        task->func = func;
    }
    return task;
}

// VBlankTask_AddAlways @ 0x080A9C30
struct VBlankTask *VBlankTask_AddAlways(VoidFunc func)
{
    struct VBlankTask *task = VBlankTask_Add(func);

    task->state = 2;
    return task;
}

// VBlankTask_AddCounted @ 0x080A9C40
struct VBlankTask *VBlankTask_AddCounted(VoidFunc func, u16 count)
{
    struct VBlankTask *task = VBlankTask_FindFree();

    if (task != NULL)
    {
        task->state = 1;
        task->counter = count;
        task->func = func;
    }
    return task;
}

// VBlankTask_AddCountedAlways @ 0x080A9C64
struct VBlankTask *VBlankTask_AddCountedAlways(VoidFunc func, u16 count)
{
    struct VBlankTask *task = VBlankTask_AddCounted(func, count);

    task->state = 2;
    return task;
}

// VBlankTasks_Run @ 0x080A9C78
void VBlankTasks_Run(u16 phase)
{
    u32 i;

    for (i = 0; i < 10; i++)
    {
        struct VBlankTask *task = &gVBlankTasks[i];

        if (task->state != 0 && task->state >= phase)
        {
            task->func();
            if (task->counter != 0xFFFF)
            {
                if (--task->counter == 0)
                    task->state = 0;
            }
        }
    }
}

// NumberToDigits @ 0x080A9CC0
/* Splits n (mod 10^8) into eight decimal digits, least significant first. */
u8 *NumberToDigits(u32 n)
{
    u8 *digits = gDigits;

    digits[0] = 0;
    digits[1] = 0;
    digits[2] = 0;
    digits[3] = 0;
    digits[4] = 0;
    digits[5] = 0;
    digits[6] = 0;
    digits[7] = 0;
    if (n != 0)
    {
        n %= 100000000;
        digits[7] = n / 10000000;
        n %= 10000000;
        digits[6] = n / 1000000;
        n %= 1000000;
        digits[5] = n / 100000;
        n %= 100000;
        digits[4] = n / 10000;
        n %= 10000;
        digits[3] = n / 1000;
        n %= 1000;
        digits[2] = n / 100;
        n %= 100;
        digits[1] = n / 10;
        digits[0] = n % 10;
    }
    return digits;
}

// Sprites_BeginFrame @ 0x080A9D90
void Sprites_BeginFrame(void)
{
    gUnk_030031C8 = 0;
    gAffineCount = 0;
    Sprites_ClearLayers();
    DmaFill32(3, 0, gAffineSlots, sizeof(gAffineSlots));
}

// Sprites_BuildOam @ 0x080A9DD0
/* Builds the OAM buffer from the per-layer sprite lists, hides the unused entries and
   writes the affine matrices. */
void Sprites_BuildOam(void)
{
    struct OamData *dst = gOamBuffer;
    u8 count = 0;
    u8 i;
    s8 idx;
    struct OamData *oam;

    for (i = 0; i < 10; i++)
    {
        for (idx = gSpriteLayers[i].head; idx >= 0; idx = gSpriteNodes[idx].next)
        {
            *dst++ = gSpriteNodes[idx].oam;
            count++;
        }
    }
    for (i = count; (s8)i >= 0; i++)
        gOamBuffer[i].affineMode = 2;
    for (i = 0; i < 32; i++)
    {
        oam = &gOamBuffer[i * 4];
        (oam++)->affineParam = gAffineSlots[i].pa;
        (oam++)->affineParam = gAffineSlots[i].pb;
        (oam++)->affineParam = gAffineSlots[i].pc;
        oam->affineParam = gAffineSlots[i].pd;
    }
}

// Sprites_ClearLayers @ 0x080A9E78
void Sprites_ClearLayers(void)
{
    u8 i;

    for (i = 0; i < 10; i++)
        gSpriteLayers[i].head = -1;
    gSpriteNodeCount = 0;
}

// Sprite_Alloc @ 0x080A9EA8
/* Takes the next free sprite node and links it at the head of the given layer. */
struct SpriteNode *Sprite_Alloc(u8 layer)
{
    if (gSpriteNodeCount < 0)
        return NULL;
    gSpriteNodes[(u8)gSpriteNodeCount].next = gSpriteLayers[layer].head;
    gSpriteLayers[layer].head = gSpriteNodeCount;
    gSpriteNodeCount++;
    gUnk_030031C8++;
    return &gSpriteNodes[(u8)gSpriteNodeCount - 1];
}
