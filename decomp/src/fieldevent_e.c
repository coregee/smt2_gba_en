/* World-map coordinates to sub-maps, warps by global position, misc field helpers. */

#include "global.h"
#include "fieldevent.h"

#define AREA_CHECK(i)                                               \
    if (((const u32 *)&h->areas[i])[1] == 0)                        \
        return 1;                                                   \
    if (Rect_IsOutside(h->areas[i].r, x, y) == 0)                     \
        return 0;

// SubMap_IsOutsideExclusions @ 0x080B7944
/* 1 when (x, y) is outside every excluded area of sub-map h (up to 16 rectangles, the list
   ends at an empty one). */
u32 SubMap_IsOutsideExclusions(struct SubMap *h, u16 x, u16 y)
{
    AREA_CHECK(0)
    AREA_CHECK(1)
    AREA_CHECK(2)
    AREA_CHECK(3)
    AREA_CHECK(4)
    AREA_CHECK(5)
    AREA_CHECK(6)
    AREA_CHECK(7)
    AREA_CHECK(8)
    AREA_CHECK(9)
    AREA_CHECK(10)
    AREA_CHECK(11)
    AREA_CHECK(12)
    AREA_CHECK(13)
    AREA_CHECK(14)
    AREA_CHECK(15)
    return 1;
}

// Warp_ToWorldPosition @ 0x080B7AFC
/* Warps to world position (x, y): finds the map and sub-map whose bounds contain it, marks it
   on the automap and starts the warp. Bits 6-7 of y are the facing. */
#ifdef NONMATCHING
void Warp_ToWorldPosition(u16 mode, u16 x, u16 y, u16 dir, u16 flag)
{
    u16 saved = gGameState.unkAC0;
    u16 lx, ly, map, n, i, facing;
    u16 foundMap, foundSub;
    struct SubMap *h;

    if (gMainCallback == sub_080D977C)
    {
        sub_080BF300(x, y);
        return;
    }
    if (gUnk_03003BB8 == 1)
    {
        gUnk_03003BB8 = 0;
        sub_080C2CC0();
    }
    if (flag == 1)
    {
        gUnk_03003BB8 = flag;
        gGameState.unkAC0 = flag;
        if (saved == 0)
            Encounter_SetCounter(0);
        if (mode == 1)
            sub_080B7738(0, 0, x, y, dir, 0);
        else
            sub_080B778C(0, 0, x, y, dir, 0);
        return;
    }

    lx = x;
    ly = y & 0x3F;
    for (map = 0; ; map++)
    {
        n = sub_080C8B3C(map);
        h = DungeonMap_GetFloor(map, 0);
        if (h == NULL)
            break;
        for (i = 0; i < n; i++, h++)
        {
            if (h->x0 <= lx && h->y0 <= ly && h->x1 >= lx && h->y1 >= ly && SubMap_IsOutsideExclusions(h, lx, ly) == 1)
            {
                foundMap = map;
                foundSub = i;
                lx -= h->x0;
                ly -= h->y0;
                break;
            }
        }
        if (i != n)
            break;
    }

    Automap_SetVisitedRaw(x, y & 0x3F);
    if (x == 0x14 && (y & 0x3F) == 0xD)
        Automap_SetVisitedRaw(0x14, 0xE);
    if (x == 0x77 && (y & 0x3F) == 0xA)
        Automap_SetVisitedRaw(0x77, 0xB);
    facing = ((y >> 5) & 6) >> 1;
    if (gGameState.unkAC0 == 1 && Palette_IsBg13Black() == 1)
        sub_080C1384();
    if (saved == 1)
        Encounter_SetCounter(0);
    gUnk_03004530 = 0x19;
    gUnk_03003BB8 = 0;
    gGameState.unkAC0 = 0;
    if (gUnk_03004614 != foundMap)
        sub_080C2CC0();
    if (saved == 1)
        sub_080B7F2C(foundMap, (u8)x, (u8)y);
    sub_080AE294();
    if (sub_080C8AF8(foundMap) == 1)
        sub_080C7C94();
    else
        sub_080C7C60();
    if (mode != 1)
        sub_080B764C(foundMap, foundSub, lx, ly, facing, 0);
    else
        sub_080B75E8(foundMap, foundSub, lx, ly, facing, 0);
}
#else
NAKED
void Warp_ToWorldPosition(u16 mode, u16 x, u16 y, u16 dir, u16 flag)
{
    asm_unified(
        ".L080B7AFC:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x1c\n"
        "    ldr r4, [sp, #0x3c]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #8]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    mov sl, r1\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    str r2, [sp, #0xc]\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r6, r3, #0x10\n"
        "    mov r8, r6\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    ldr r0, .L080B7B48\n"
        "    movs r1, #0xac\n"
        "    lsls r1, r1, #4\n"
        "    adds r7, r0, r1\n"
        "    ldrh r2, [r7]\n"
        "    str r2, [sp, #0x18]\n"
        "    ldr r0, .L080B7B4C\n"
        "    ldr r1, [r0]\n"
        "    ldr r0, .L080B7B50\n"
        "    cmp r1, r0\n"
        "    bne .L080B7B54\n"
        "    mov r0, sl\n"
        "    ldr r1, [sp, #0xc]\n"
        "    bl sub_080BF300\n"
        "    b .L080B7D30\n"
        "    .byte 0x00, 0x00\n"
        ".L080B7B48: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080B7B4C: .4byte 0x030020E4 @ IWRAM+0x20E4\n"
        ".L080B7B50: .4byte sub_080D977C\n"
        ".L080B7B54:\n"
        "    ldr r5, .L080B7B94\n"
        "    ldr r0, [r5]\n"
        "    cmp r0, #1\n"
        "    bne .L080B7B64\n"
        "    movs r0, #0\n"
        "    str r0, [r5]\n"
        "    bl sub_080C2CC0\n"
        ".L080B7B64:\n"
        "    cmp r4, #1\n"
        "    bne .L080B7BAC\n"
        "    str r4, [r5]\n"
        "    movs r5, #0\n"
        "    strh r4, [r7]\n"
        "    ldr r0, [sp, #0x18]\n"
        "    cmp r0, #0\n"
        "    bne .L080B7B7A\n"
        "    movs r0, #0\n"
        "    bl Encounter_SetCounter\n"
        ".L080B7B7A:\n"
        "    ldr r1, [sp, #8]\n"
        "    cmp r1, #1\n"
        "    bne .L080B7B98\n"
        "    str r6, [sp]\n"
        "    str r5, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    mov r2, sl\n"
        "    ldr r3, [sp, #0xc]\n"
        "    bl sub_080B7738\n"
        "    b .L080B7D30\n"
        "    .byte 0x00, 0x00\n"
        ".L080B7B94: .4byte 0x03003BB8 @ IWRAM+0x3BB8\n"
        ".L080B7B98:\n"
        "    mov r2, r8\n"
        "    str r2, [sp]\n"
        "    str r5, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    mov r2, sl\n"
        "    ldr r3, [sp, #0xc]\n"
        "    bl sub_080B778C\n"
        "    b .L080B7D30\n"
        ".L080B7BAC:\n"
        "    mov r7, sl\n"
        "    movs r0, #0x3f\n"
        "    ldr r1, [sp, #0xc]\n"
        "    ands r1, r0\n"
        "    mov sb, r1\n"
        "    movs r2, #0\n"
        "    mov r8, r2\n"
        "    b .L080B7C22\n"
        ".L080B7BBC:\n"
        "    mov r0, r8\n"
        "    str r0, [sp, #0x10]\n"
        "    str r5, [sp, #0x14]\n"
        "    ldrh r0, [r4, #8]\n"
        "    subs r0, r7, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    ldrh r0, [r4, #0xa]\n"
        "    mov r1, sb\n"
        "    subs r0, r1, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sb, r0\n"
        "    b .L080B7C14\n"
        ".L080B7BD8:\n"
        "    movs r5, #0\n"
        "    cmp r5, r6\n"
        "    bhs .L080B7C14\n"
        ".L080B7BDE:\n"
        "    ldrh r0, [r4, #8]\n"
        "    cmp r0, r7\n"
        "    bhi .L080B7C04\n"
        "    ldrh r0, [r4, #0xa]\n"
        "    cmp r0, sb\n"
        "    bhi .L080B7C04\n"
        "    ldrh r0, [r4, #0xc]\n"
        "    cmp r0, r7\n"
        "    blo .L080B7C04\n"
        "    ldrh r0, [r4, #0xe]\n"
        "    cmp r0, sb\n"
        "    blo .L080B7C04\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r7, #0\n"
        "    mov r2, sb\n"
        "    bl SubMap_IsOutsideExclusions\n"
        "    cmp r0, #1\n"
        "    beq .L080B7BBC\n"
        ".L080B7C04:\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    movs r2, #0x9a\n"
        "    lsls r2, r2, #2\n"
        "    adds r4, r4, r2\n"
        "    cmp r5, r6\n"
        "    blo .L080B7BDE\n"
        ".L080B7C14:\n"
        "    cmp r5, r6\n"
        "    bne .L080B7C38\n"
        "    mov r0, r8\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        ".L080B7C22:\n"
        "    mov r0, r8\n"
        "    bl sub_080C8B3C\n"
        "    adds r6, r0, #0\n"
        "    mov r0, r8\n"
        "    movs r1, #0\n"
        "    bl DungeonMap_GetFloor\n"
        "    adds r4, r0, #0\n"
        "    cmp r4, #0\n"
        "    bne .L080B7BD8\n"
        ".L080B7C38:\n"
        "    movs r4, #0x3f\n"
        "    ldr r0, [sp, #0xc]\n"
        "    ands r4, r0\n"
        "    mov r0, sl\n"
        "    adds r1, r4, #0\n"
        "    bl Automap_SetVisitedRaw\n"
        "    mov r1, sl\n"
        "    cmp r1, #0x14\n"
        "    bne .L080B7C58\n"
        "    cmp r4, #0xd\n"
        "    bne .L080B7C58\n"
        "    movs r0, #0x14\n"
        "    movs r1, #0xe\n"
        "    bl Automap_SetVisitedRaw\n"
        ".L080B7C58:\n"
        "    mov r2, sl\n"
        "    cmp r2, #0x77\n"
        "    bne .L080B7C70\n"
        "    movs r0, #0x3f\n"
        "    ldr r1, [sp, #0xc]\n"
        "    ands r0, r1\n"
        "    cmp r0, #0xa\n"
        "    bne .L080B7C70\n"
        "    movs r0, #0x77\n"
        "    movs r1, #0xb\n"
        "    bl Automap_SetVisitedRaw\n"
        ".L080B7C70:\n"
        "    ldr r0, .L080B7CF0\n"
        "    movs r2, #0xac\n"
        "    lsls r2, r2, #4\n"
        "    adds r0, r0, r2\n"
        "    ldrh r2, [r0]\n"
        "    ldr r1, [sp, #0xc]\n"
        "    lsrs r0, r1, #5\n"
        "    movs r1, #6\n"
        "    ands r0, r1\n"
        "    lsrs r4, r0, #1\n"
        "    cmp r2, #1\n"
        "    bne .L080B7C94\n"
        "    bl Palette_IsBg13Black\n"
        "    cmp r0, #1\n"
        "    bne .L080B7C94\n"
        "    bl sub_080C1384\n"
        ".L080B7C94:\n"
        "    ldr r2, [sp, #0x18]\n"
        "    cmp r2, #1\n"
        "    bne .L080B7CA0\n"
        "    movs r0, #0\n"
        "    bl Encounter_SetCounter\n"
        ".L080B7CA0:\n"
        "    ldr r1, .L080B7CF4\n"
        "    movs r0, #0x19\n"
        "    str r0, [r1]\n"
        "    ldr r0, .L080B7CF8\n"
        "    movs r1, #0\n"
        "    str r1, [r0]\n"
        "    ldr r0, .L080B7CF0\n"
        "    movs r2, #0xac\n"
        "    lsls r2, r2, #4\n"
        "    adds r0, r0, r2\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L080B7CFC\n"
        "    ldr r0, [r0]\n"
        "    ldr r1, [sp, #0x10]\n"
        "    cmp r0, r1\n"
        "    beq .L080B7CC4\n"
        "    bl sub_080C2CC0\n"
        ".L080B7CC4:\n"
        "    ldr r2, [sp, #0x18]\n"
        "    cmp r2, #1\n"
        "    bne .L080B7CDC\n"
        "    mov r0, sl\n"
        "    lsls r1, r0, #0x18\n"
        "    lsrs r1, r1, #0x18\n"
        "    ldr r0, [sp, #0xc]\n"
        "    lsls r2, r0, #0x18\n"
        "    lsrs r2, r2, #0x18\n"
        "    ldr r0, [sp, #0x10]\n"
        "    bl sub_080B7F2C\n"
        ".L080B7CDC:\n"
        "    bl sub_080AE294\n"
        "    ldr r0, [sp, #0x10]\n"
        "    bl sub_080C8AF8\n"
        "    cmp r0, #1\n"
        "    bne .L080B7D00\n"
        "    bl sub_080C7C94\n"
        "    b .L080B7D04\n"
        ".L080B7CF0: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080B7CF4: .4byte 0x03004530 @ IWRAM+0x4530\n"
        ".L080B7CF8: .4byte 0x03003BB8 @ IWRAM+0x3BB8\n"
        ".L080B7CFC: .4byte 0x03004614 @ IWRAM+0x4614\n"
        ".L080B7D00:\n"
        "    bl sub_080C7C60\n"
        ".L080B7D04:\n"
        "    ldr r1, [sp, #8]\n"
        "    cmp r1, #1\n"
        "    beq .L080B7D1E\n"
        "    str r4, [sp]\n"
        "    movs r0, #0\n"
        "    str r0, [sp, #4]\n"
        "    ldr r0, [sp, #0x10]\n"
        "    ldr r1, [sp, #0x14]\n"
        "    adds r2, r7, #0\n"
        "    mov r3, sb\n"
        "    bl sub_080B764C\n"
        "    b .L080B7D30\n"
        ".L080B7D1E:\n"
        "    str r4, [sp]\n"
        "    movs r0, #0\n"
        "    str r0, [sp, #4]\n"
        "    ldr r0, [sp, #0x10]\n"
        "    ldr r1, [sp, #0x14]\n"
        "    adds r2, r7, #0\n"
        "    mov r3, sb\n"
        "    bl sub_080B75E8\n"
        ".L080B7D30:\n"
        "    add sp, #0x1c\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

// sub_080B7D40 @ 0x080B7D40
/* Facing from which the player, at its world position, is next to (x, y); -1 if not. */
s32 sub_080B7D40(u16 x, u16 y)
{
    s32 dir = -1;
    u16 px, py;

    sub_080C1F50(gFieldState.unk12, gFieldState.unk14, &px, &py);
    if (!(gUnk_0200AB04 & 0x8000))
    {
        switch (gFieldState.unk02)
        {
        case 0:
        case 2:
            if (py - y == 1 && px == x)
                dir = 0;
            if (y - py == 1 && px == x)
                dir = 2;
            break;
        case 1:
        case 3:
            if (px - x == 1 && py == y)
                dir = 3;
            if (x - px == 1 && py == y)
                dir = 1;
            break;
        }
    }
    return dir;
}

// sub_080B7DF8 @ 0x080B7DF8
u32 sub_080B7DF8(struct Task *task)
{
    u32 r = 0;

    if (*(u16 *)task->data == 1)
        r = 1;
    return r;
}

// sub_080B7E0C @ 0x080B7E0C
struct Task *sub_080B7E0C(u16 arg)
{
    u16 v;
    struct Task *task;

    if (arg == 0)
        v = 2;
    else
        gUnk_03004530 = v = 0x1A;
    task = Task_Create(gUnknown_081644B4, 0xFFFF);
    *(u16 *)&task->data[4] = v;
    return task;
}

// sub_080B7E3C @ 0x080B7E3C
/* Like Warp_ToWorldPosition: warps to world position (x, y) through task gUnknown_08164670. */
struct Task *sub_080B7E3C(u16 unused, u16 x, u16 y, u16 unused2, u32 arg)
{
    u16 lx, ly, map, i, facing;
    u32 n;
    u16 foundMap, foundSub;
    u32 t;
    struct SubMap *h;
    struct Task *task;

    lx = x;
    ly = y & 0x3F;
    for (map = 0; n = sub_080C8B3C(map), h = DungeonMap_GetFloor(map, 0), t = y >> 5, h != NULL; map++)
    {
        for (i = 0; i < n; i++, h++)
        {
            if (h->x0 <= lx && h->y0 <= ly && h->x1 >= lx && h->y1 >= ly && SubMap_IsOutsideExclusions(h, lx, ly) == 1)
            {
                foundMap = map;
                foundSub = i;
                lx -= h->x0;
                ly -= h->y0;
                break;
            }
        }
        if (i != n)
            break;
    }
    facing = (t & 6) >> 1;
    sub_080C2CC0();
    task = Task_Create(gUnknown_08164670, 0xFFFF);
    Warp_SetDestination(foundMap, foundSub, lx, ly, facing, arg);
    gWarpDest.unk0A = 1;
    return task;
}

// sub_080B7F2C @ 0x080B7F2C
void sub_080B7F2C(u16 map, u8 x, u8 y)
{
    sub_080C2D48(gUnk_03003FC4, map);
    gGameState.unk18C2 = x;
    gGameState.unk18C3 = y;
}

// sub_080B7F70 @ 0x080B7F70
void sub_080B7F70(void)
{
    gUnk_0300003C = 0;
}

// sub_080B7F7C @ 0x080B7F7C
/* Raises gUnk_0300003C by 16 every 3 frames up to n*16, then lowers it back to 0. */
void sub_080B7F7C(struct Task *task, u32 n)
{
    struct PulseData *d = (struct PulseData *)task->data;

    task->result = 0;
    if (--d->timer == 0)
    {
        d->timer = 3;
        if (d->falling == 0)
        {
            gUnk_0300003C += 0x10;
            if (gUnk_0300003C > n * 16)
            {
                d->falling = 1;
                Sound_Play(0x153);
            }
        }
        else
        {
            gUnk_0300003C -= 0x10;
            if (gUnk_0300003C == 0)
            {
                d->falling = 0;
                task->result = 1;
            }
        }
    }
    sub_080B0AE0();
}

// sub_080B7FE8 @ 0x080B7FE8
void sub_080B7FE8(void)
{
    PalFade_FadeRangeToWhite(0x80, 0x80, 6);
    PalFade_FadeRangeToWhite(0x1D0, 0x30, 6);
}

// sub_080B8004 @ 0x080B8004
void sub_080B8004(void)
{
    PalFade_FadeRangeToBlack(0x80, 0x80, 6);
    PalFade_FadeRangeToBlack(0x1D0, 0x30, 6);
}

// sub_080B8020 @ 0x080B8020
/* Declared with a return value but returns nothing. */
u32 sub_080B8020(void)
{
    struct Task *task = Task_Create(gUnknown_081646C0, 0xFFFF);

    ((struct PulseData *)task->data)->timer = 3;
    gUnk_03004534 = 0x77;
}

// sub_080B8048 @ 0x080B8048
void sub_080B8048(struct Task *task, u32 step)
{
    if (step == 0)
    {
        Map_SetGraphicsPointers(gUnk_03004614, gUnk_03004514);
        sub_080AE234();
        sub_080AD7F0();
        gFieldState.unk34 = step;
    }
    else
    {
        sub_080B2840(0, 0, 0);
    }
}

// sub_080B8088 @ 0x080B8088
void sub_080B8088(struct Task *task, u32 step)
{
    task->result = 0;
    if (step == 0)
    {
        if (gUnk_0200AB04 & 0x8000)
        {
            gFieldLoadStep = 0;
            gUnk_0200AB04 &= ~0x8000;
            sub_080C14FC();
            VBlankTask_AddCounted(sub_080C153C, 1);
            task->result = 1;
        }
    }
    else if (gFieldLoadStep == 0xFFFF)
    {
        task->result = 1;
    }
    else
    {
        VBlankTask_AddCounted(Field_LoadGraphicsStep, 1);
        task->result = 0;
    }
}

// sub_080B80F8 @ 0x080B80F8
struct Task *sub_080B80F8(void)
{
    struct Task *task;
    struct Task *old = sub_080B78A4();

    if (old != NULL)
    {
        task = Task_Create(gUnknown_08164788, 0xFFFF);
        Task_End(old);
    }
    else if (Palette_IsBg13Black() == 0 && !(gUnk_0200AB04 & 0x8000))
    {
        task = Task_Create(gUnknown_08164990, 0xFFFF);
    }
    else
    {
        task = Task_Create(gUnknown_081648AC, 0xFFFF);
    }
    return task;
}

// sub_080B8160 @ 0x080B8160
u32 sub_080B8160(const u16 *p)
{
    u32 r = 0;

    if (*p == 0)
        r = 1;
    return r;
}

// sub_080B8174 @ 0x080B8174
/* The original saw sub_080B1A30/sub_080B2030 with word-sized parameters (the u16 prototypes
   load the arguments in the other order). */
void sub_080B8174(void)
{
    u16 v = 0xC;
    struct FieldState *fs = &gFieldState;
    u32 dir = fs->unk02;
    u32 wall = View_GetWall(0, 0, 0);

    if (wall == 3)
    {
        ((void (*)(u32, u32))sub_080B1A30)(0xC, dir);
    }
    else if (wall == 2)
    {
        fs->unk0A = v;
        ((void (*)(u32, u32, u32))sub_080B2030)(0xC, dir, 3);
        fs->unk46 = 1;
    }
    else
    {
        fs->unk0A = v;
        ((void (*)(u32, u32, u32))sub_080B2030)(0xC, dir, 2);
        fs->unk46 = 1;
    }
}

// sub_080B81C0 @ 0x080B81C0
void sub_080B81C0(struct Task *task)
{
    struct BlinkData *d = (struct BlinkData *)task->data;

    if (d->y != 0x52)
        Sprite_DrawBlended(gUnknown_0800107C, 9, 0, 3, 0, d->x, d->y);
    else if (!((d->timer >> 4) & 1))
        Sprite_DrawBlended(gUnknown_0800107C, 9, 0, 3, 0, d->x, d->y);
    if (d->y == 0x52)
        d->timer++;
}

// sub_080B822C @ 0x080B822C
void sub_080B822C(struct Task *task)
{
    struct BlinkData *d = (struct BlinkData *)task->data;

    task->unk1E = 1;
    if (d->y == 0x52 && (gKeysNew & 2))
    {
        task->result = 1;
        gFieldState.unk3E = 1;
    }
    else if (gFieldState.unk00 == 1)
    {
        task->result = 0;
    }
    else
    {
        task->result = 1;
    }
    if (d->y != 0x52)
        d->y -= 2;
}

// sub_080B8280 @ 0x080B8280
void sub_080B8280(void)
{
    gFieldState.unk40 = 0;
}

// sub_080B828C @ 0x080B828C
struct Task *sub_080B828C(void)
{
    struct Task *task = Task_Create(gUnknown_08164A48, 0xFFFF);
    struct BlinkData *d = (struct BlinkData *)task->data;

    d->x = 0x60;
    d->y = 0x6A;
    Sound_Play(0x6A);
    return task;
}

// sub_080B82B4 @ 0x080B82B4
void sub_080B82B4(struct Task *task)
{
    struct ItemTaskData *d = (struct ItemTaskData *)task->data;
    u16 id;
    u32 r;

    if (((struct ItemTaskData *)task->data)->rec->u.id == 0x11F)
    {
        if (sub_080C2414(((struct ItemTaskData *)task->data)->rec->unk8) != 0 || (r = Moon_GetPhase() & 0xF0) != 0)
            goto set;
        goto clear;
    }
    r = sub_080C2414(((struct ItemTaskData *)task->data)->rec->unk8);
    if (r == 0)
        goto clear;
set:
    id = ((struct ItemTaskData *)task->data)->rec->count + 1;
    d->flag = 1;
    goto done;
clear:
    id = ((struct ItemTaskData *)task->data)->rec->count;
    d->flag = r;
done:
    d->handle = CharObj_Create(0, id, 0x50, 5, 0, 0);
}

// sub_080B8324 @ 0x080B8324
void sub_080B8324(struct Task *task)
{
    task->unk1E = ((struct ItemTaskData *)task->data)->flag;
}

// sub_080B832C @ 0x080B832C
/* Shows `text` for the treasure task (the arguments are not used here). */
void sub_080B832C(struct Task *task, const u16 *text)
{
    sub_080AF1E8(0x20);
}

// sub_080B8338 @ 0x080B8338
void sub_080B8338(struct Task *task)
{
    if (gFieldState.unk00 == 0x20)
        task->result = 1;
    else
        task->result = 0;
}
