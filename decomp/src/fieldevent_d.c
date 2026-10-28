/* Field task callbacks and helpers: palette fades around events, warps, task lookup. */

#include "global.h"
#include "fieldevent.h"

// sub_080B7424 @ 0x080B7424
void sub_080B7424(void)
{
    gHudState[0x1A] = 0;
}

// sub_080B7430 @ 0x080B7430
/* Fades the field palettes in from white. */
void sub_080B7430(void)
{
    u16 *pal = gPaletteTarget;
    u16 flag = 0;
    u32 white = 0x7FFF;

    pal[0] = white;
    Palette_FillWithEffect(3, white, &pal[0xE0], 0x40, 0x10);
    Palette_FillWithEffect(3, white, &pal[0xD0], 0x20, 0x10);
    PalFade_FadeRangeInFromBlack(0, 1, 1);
    gUnk_0300452C = PalFade_FadeRangeInFromBlack(0xD0, 0x30, 1);
    gFieldState.unk60 = flag;
}

// sub_080B7498 @ 0x080B7498
void sub_080B7498(void)
{
    const u16 *pal = gUnk_03004630;

    gPaletteTarget[0] = *pal;
    Palette_CopyWithEffect(3, pal, &gPaletteTarget[0xE0], 0x40, 0x20);
    Palette_CopyWithEffect(3, gUnk_03004510, &gPaletteTarget[0xD0], 0x20, 0x20);
    gUnk_0300452C = PalFade_FadeRangeWithDuration(0xD0, 0x30, 8, 0x20);
    gFieldState.unk60 = 1;
}

// sub_080B7500 @ 0x080B7500
void sub_080B7500(struct Task *task)
{
    task->result = 0;
    if (gPaletteBuffer[1] == 0)
    {
        sub_080B04BC();
        gUnk_0300452C = PalFade_FadeInFromBlack(1);
        task->result = 1;
    }
}

// sub_080B7530 @ 0x080B7530
void sub_080B7530(void)
{
    if (gUnk_03004534 == 0x2E)
        Task_Create(gUnknown_0834A0B0, 0xFFFF);
    else if (gUnk_03004534 == 0x6D)
        Task_Create(gUnknown_0834A150, 0xFFFF);
    else if (gUnk_03004534 == 0x5D)
        Task_Create(gUnknown_0834A1F0, 0xFFFF);
}

// sub_080B7578 @ 0x080B7578
void sub_080B7578(void)
{
    PalFade_FadeRangeToBlack(0x1D0, 0x2E, 1);
}

// Warp_SetDestination @ 0x080B758C
/* Sets both the warp destination and the current position. (Declared with a return value
   but returns nothing.) */
u32 Warp_SetDestination(u16 map, u16 floor, u16 x, u16 y, u16 dir, u32 arg)
{
    gUnk_03004614 = gWarpDest.map = map;
    gUnk_03004514 = gWarpDest.floor = floor;
    gFieldState.unk12 = gWarpDest.x = x;
    gFieldState.unk14 = gWarpDest.y = y;
    gFieldState.unk02 = gWarpDest.dir = dir;
    gWarpDest.unk0C = arg;
}

// sub_080B75E8 @ 0x080B75E8
struct Task *sub_080B75E8(u16 map, u16 floor, u16 x, u16 y, u16 dir, u32 arg)
{
    struct Task *task = Task_Create(gUnknown_081641B4, 0xFFFF);

    Warp_SetDestination(map, floor, x, y, dir, arg);
    gWarpDest.unk0A = 1;
    return task;
}

// sub_080B764C @ 0x080B764C
struct Task *sub_080B764C(u16 map, u16 floor, u16 x, u16 y, u16 dir, u32 arg)
{
    struct Task *task = sub_080B75E8(map, floor, x, y, dir, arg);

    gWarpDest.unk0A = 1;
    return task;
}

// sub_080B7684 @ 0x080B7684
void sub_080B7684(void)
{
    sub_080C2CD8((s8)gWorldMap[8], 0, 3);
    if (Flag_Test(0x108) && gFieldState.unk50 != 0)
    {
        sub_080B0C7C();
        gFieldState.unk50 = 0;
        Flag_Clear(0x108);
    }
}

// sub_080B76CC @ 0x080B76CC
void sub_080B76CC(void)
{
    gHudState[0x1A] = 1;
}

// sub_080B76D8 @ 0x080B76D8
void sub_080B76D8(void)
{
    if (Flag_Test(0xAE))
    {
        if (Flag_Test(0x5E))
            sub_080AF178(0xC, gUnknown_0804C354);
        else if (Flag_Test(0x5F))
            sub_080AF178(0xC, gUnknown_0804C564);
        else
            sub_080AF178(0xC, gUnknown_0804CB9C);
        gUnk_03003BB8 = 0;
        gGameState.unkAC0 = 0;
    }
}

// sub_080B7738 @ 0x080B7738
struct Task *sub_080B7738(u16 map, u16 floor, u16 x, u16 y, u16 dir, u32 arg)
{
    struct Task *task;

    if (Flag_Test(0xAE))
        task = Task_Create(gUnknown_08164460, 0xFFFF);
    else
        task = Task_Create(gUnknown_081643D0, 0xFFFF);
    gWarpDest.x = x & 0x7F;
    gWarpDest.y = y;
    gWarpDest.dir = dir;
    gWarpDest.unk0A = 1;
    return task;
}

// sub_080B778C @ 0x080B778C
struct Task *sub_080B778C(u16 map, u16 floor, u16 x, u16 y, u16 dir, u32 arg)
{
    struct Task *task = sub_080B7738(map, floor, x, y, dir, arg);

    gWarpDest.unk0A = 1;
    return task;
}

// sub_080B77C4 @ 0x080B77C4
void sub_080B77C4(struct Task *task)
{
    if (*(u16 *)&task->data[4] == 2)
    {
        task->result = 1;
        if (View_GetWall(0, 0, 0) == 0)
        {
            task->unk1E = 0;
            gUnk_03004530 = 0x1A;
        }
        else
        {
            gFieldState.unk2E = 0;
            task->unk1E = 1;
        }
    }
    else
    {
        task->result = 0;
    }
}

// sub_080B7808 @ 0x080B7808
void sub_080B7808(void)
{
    sub_080C3818(1);
    sub_080B1AD8(0xC, gFieldState.unk02);
    gFieldState.unk46 = 1;
}

// sub_080B782C @ 0x080B782C
void sub_080B782C(void)
{
    sub_080C3818(1);
    Task_Create(gUnknown_0816499C, 0xFFFF);
    Field_SetState(0x1A);
}

// sub_080B7850 @ 0x080B7850
void sub_080B7850(void)
{
    sub_080B2840(1, 0, 0);
}

// sub_080B7860 @ 0x080B7860
void sub_080B7860(struct Task *task)
{
    if (gFieldState.unk0E == 0)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080B787C @ 0x080B787C
void sub_080B787C(struct Task *task)
{
    if (gFieldState.unk5E == 0)
    {
        task->result = 1;
    }
    else
    {
        task->result = 0;
        gFieldState.unk5E = 0;
    }
}

// sub_080B78A4 @ 0x080B78A4
/* The running task whose frame callback is sub_080B7414, or NULL. */
struct Task *sub_080B78A4(void)
{
    u32 i;

    for (i = 0; i < 64; i++)
    {
        struct Task *task = &gTasks[i];

        if (task->state != 0 && task->onFrame == (void *)sub_080B7414)
            return task;
    }
    return NULL;
}

// sub_080B78DC @ 0x080B78DC
/* The running task whose frame callback is sub_080B2AB0, or NULL. */
struct Task *sub_080B78DC(void)
{
    u32 i;

    for (i = 0; i < 64; i++)
    {
        struct Task *task = &gTasks[i];

        if (task->state != 0 && task->onFrame == (void *)sub_080B2AB0)
            return task;
    }
    return NULL;
}

// Rect_IsOutside @ 0x080B7914
/* 0 when (x, y) is inside rect {x0, y0, x1, y1}, else 1. */
u16 Rect_IsOutside(const u16 *rect, u16 x, u16 y)
{
    if (rect[0] <= x && rect[1] <= y && rect[2] >= x && rect[3] >= y)
        return 0;
    else
        return 1;
}
