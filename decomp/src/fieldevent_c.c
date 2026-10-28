/* Field task callbacks: pictures, warps between maps, script waits. */

#include "global.h"
#include "fieldevent.h"

// sub_080B6B58 @ 0x080B6B58
struct Task *sub_080B6B58(void (*func)(void), u32 kind)
{
    struct Task *task = Task_Create(gUnknown_08163BE8, 0xFFFF);
    struct FadeTaskData *d = (struct FadeTaskData *)task->data;

    d->func = func;
    if (gFieldState.unk48 == 1)
        gFieldState.unk48 = 2;
    if (gFieldState.unk4C == 1)
        gFieldState.unk4C = 2;
    if (gFieldState.unk50 == 1)
        gFieldState.unk50 = 2;
    d->kind = kind;
    return task;
}

// sub_080B6BB0 @ 0x080B6BB0
struct Task *sub_080B6BB0(void (*func)(void))
{
    struct Task *task = Task_Create(gUnknown_08163E78, 0xFFFF);

    ((struct FadeTaskData *)task->data)->func = func;
    if (gFieldState.unk48 == 1)
        gFieldState.unk48 = 2;
    if (gFieldState.unk4C == 1)
        gFieldState.unk4C = 2;
    if (gFieldState.unk50 == 1)
        gFieldState.unk50 = 2;
    return task;
}

// sub_080B6C00 @ 0x080B6C00
void sub_080B6C00(struct Task *task, u32 step)
{
    switch (step)
    {
    case 0:
        VBlankTask_AddCounted(sub_080B3E8C, 1);
        break;
    case 1:
        if (BgPicture_LoadStep(0) == 0)
            task->result = 0;
        else
            task->result = 1;
        break;
    case 2:
        VBlankTask_AddCounted(sub_080B3ED0, 1);
        break;
    case 3:
        VBlankTask_AddCounted(BgPicture_BuildTilemap, 1);
        break;
    case 4:
        VBlankTask_AddCounted(sub_080B41B0, 1);
        break;
    }
}

// sub_080B6C74 @ 0x080B6C74
/* Once flag 0x10F is set, fades the picture palette in and clears the flag. */
void sub_080B6C74(struct Task *task)
{
    u32 r = Flag_Test(0x10F);

    if (r != 0)
    {
        BgPicture_LoadPalette();
        if (gUnk_03004534 == 0xDA)
            Palette_CopyWithEffect(3, &gPaletteTarget[0x70], &gPaletteBuffer[0x70], 0x20, 0x20);
        else
            Palette_CopyWithEffect(3, &gPaletteTarget[0x80], &gPaletteBuffer[0x80], 0x100, 0x20);
        Palette_MarkDirty();
        Flag_Clear(0x10F);
        r = 1;
    }
    task->result = r;
}

// sub_080B6CE8 @ 0x080B6CE8
void sub_080B6CE8(void)
{
    gUnk_03000042 += 0xFF;
}

// sub_080B6CF8 @ 0x080B6CF8
void sub_080B6CF8(void)
{
    DmaFill32(3, 0, (void *)0x06001000, 0x1000);
    REG_BG2CNT = 0x840A;
}

// sub_080B6D2C @ 0x080B6D2C
void sub_080B6D2C(void)
{
    sub_080C1440();
    VBlankTask_AddCounted(sub_080B6CF8, 1);
}

// sub_080B6D44 @ 0x080B6D44
void sub_080B6D44(void)
{
    DmaCopy32(3, gUnk_02000000, (void *)0x06002000, 0x500);
}

// sub_080B6D68 @ 0x080B6D68
void sub_080B6D68(void)
{
    DmaCopy32(3, gUnknown_0857D9C0, gUnk_02000000, 0x500);
    VBlankTask_AddCounted(sub_080B6D44, 1);
}

// sub_080B6D9C @ 0x080B6D9C
void sub_080B6D9C(struct Task *task)
{
    u32 r = sub_080B38A8();

    if (r != 1)
        r = 0;
    task->result = r;
}

// BgPicture_StartTask @ 0x080B6DB4
/* Starts the task that shows background picture `pic`. */
struct Task *BgPicture_StartTask(u32 pic)
{
    struct Task *task;
    u32 flag;
    u16 zero;

    if (gMainCallback == sub_080D977C)
    {
        if (pic == 0x6D)
        {
            task = Task_Create(gUnknown_0834A0D4, 0xFFFF);
            gFieldState.unk1E = 0;
        }
        else if (pic == 0x2E)
        {
            task = Task_Create(gUnknown_0834A01C, 0xFFFF);
            gFieldState.unk1E = 0;
        }
        else
        {
            task = Task_Create(gUnknown_08164074, 0xFFFF);
        }
        gUnk_03004534 = pic;
        flag = Flag_Test(0x10F);
        if (flag == 0)
        {
            zero = flag;
            CpuSet(&zero, &gPaletteBuffer[0x80], 0x01000080);
            gPaletteBuffer[0] = flag;
            Palette_MarkDirty();
        }
    }
    else if ((gUnk_0200AB04 & 0x8000) && gUnk_03004534 == pic)
    {
        task = Task_Create(gUnknown_081641A8, 0xFFFF);
    }
    else if (pic == 0x2E)
    {
        task = Task_Create(gUnknown_0834A01C, 0xFFFF);
        gFieldState.unk1E = 0;
        gUnk_03004534 = pic;
    }
    else if (pic == 0x6D)
    {
        task = Task_Create(gUnknown_0834A0D4, 0xFFFF);
        gFieldState.unk1E = 0;
        gUnk_03004534 = pic;
    }
    else if (pic == 0x5D)
    {
        task = Task_Create(gUnknown_0834A174, 0xFFFF);
        gFieldState.unk1E = 0;
        gUnk_03004534 = pic;
    }
    else
    {
        task = Task_Create(gUnknown_0816417C, 0xFFFF);
        gFieldState.unk1E = flag = 0;
        gUnk_03004534 = pic;
        if (gUnk_0200AB04 & 0x8000)
        {
            zero = flag;
            CpuSet(&zero, &gPaletteBuffer[0x80], 0x01000080);
            gPaletteBuffer[0] = flag;
            Palette_MarkDirty();
        }
    }
    return task;
}

// sub_080B6F28 @ 0x080B6F28
void sub_080B6F28(const struct ScaleParams *p)
{
    gScaleState.row = 0;
    gScaleState.srcRow = p->srcY;
    gScaleState.dstRow = p->dstY;
    gScaleState.accX = 0;
    gScaleState.accY = 0;
}

// Picture_ScaleStep @ 0x080B6F40
/* Scales up to 16 rows of a picture per call (see struct ScaleParams); returns 0 when all
   p->h rows are done. Destination pixels are ORed in. */
#ifdef NONMATCHING
u32 Picture_ScaleStep(const struct ScaleParams *p)
{
    u16 srcX0 = p->srcX;
    u16 srcRow = gScaleState.srcRow;
    u16 dstX0 = p->dstX;
    u16 dstRow = gScaleState.dstRow;
    u16 stepX = p->stepX;
    u16 stepY = p->stepY;
    u16 w = p->w;
    u16 h = p->h;
    const u8 *src = *p->src;
    u8 *dst = p->dst;
    u32 accX = gScaleState.accX;
    u32 accY = gScaleState.accY;
    u16 n;
    u16 sx, dx, i;

    for (n = 0; n < 16; n++)
    {

        if (gScaleState.row >= h)
            return 0;
        sx = srcX0;
        dx = dstX0;
        for (i = 0; i < w; i++)
        {
            u8 *d = TILE_PIXEL_BYTE(dst, dx, dstRow);
            u8 dv = *d;
            u8 sv = *TILE_PIXEL_BYTE(src, sx, srcRow);

            if (!(dx & 1))
            {
                if (!(sx & 1))
                    dv |= sv & 0xF;
                else
                    dv |= sv >> 4;
            }
            else
            {
                if (!(sx & 1))
                    dv |= sv << 4;
                else
                    dv |= sv & 0xF0;
            }
            *d = dv;
            dx++;
            accX += stepX;
            if (accX >= w)
            {
                sx++;
                accX -= w;
            }
        }
        dstRow++;
        accY += stepY;
        if (accY >= h)
        {
            srcRow++;
            accY -= h;
        }
        gScaleState.row++;
    }
    gScaleState.accX = accX;
    gScaleState.accY = accY;
    gScaleState.srcRow = srcRow;
    gScaleState.dstRow = dstRow;
    return 1;
}
#else
NAKED
u32 Picture_ScaleStep(const struct ScaleParams *p)
{
    asm_unified(
        ".L080B6F40:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x38\n"
        "    ldrh r1, [r0, #8]\n"
        "    str r1, [sp]\n"
        "    ldr r2, .L080B6F8C\n"
        "    ldrh r3, [r2, #8]\n"
        "    mov sb, r3\n"
        "    ldrh r1, [r0, #0xc]\n"
        "    str r1, [sp, #4]\n"
        "    ldrh r3, [r2, #0xa]\n"
        "    ldrh r1, [r0, #0x10]\n"
        "    str r1, [sp, #8]\n"
        "    ldrh r1, [r0, #0x12]\n"
        "    str r1, [sp, #0xc]\n"
        "    ldrh r1, [r0, #0x18]\n"
        "    mov r8, r1\n"
        "    ldrh r1, [r0, #0x1a]\n"
        "    str r1, [sp, #0x10]\n"
        "    ldr r1, [r0]\n"
        "    ldr r1, [r1]\n"
        "    str r1, [sp, #0x18]\n"
        "    ldr r0, [r0, #4]\n"
        "    str r0, [sp, #0x1c]\n"
        "    ldrh r7, [r2, #4]\n"
        "    ldrh r1, [r2, #6]\n"
        "    movs r4, #0\n"
        ".L080B6F7C:\n"
        "    ldr r2, .L080B6F8C\n"
        "    ldrh r0, [r2, #2]\n"
        "    ldr r2, [sp, #0x10]\n"
        "    cmp r0, r2\n"
        "    blo .L080B6F90\n"
        "    movs r0, #0\n"
        "    b .L080B70A8\n"
        "    .byte 0x00, 0x00\n"
        ".L080B6F8C: .4byte 0x03004520 @ IWRAM+0x4520\n"
        ".L080B6F90:\n"
        "    ldr r5, [sp]\n"
        "    ldr r6, [sp, #4]\n"
        "    movs r0, #0\n"
        "    str r0, [sp, #0x14]\n"
        "    adds r2, r3, #1\n"
        "    str r2, [sp, #0x2c]\n"
        "    ldr r0, [sp, #0xc]\n"
        "    adds r1, r1, r0\n"
        "    str r1, [sp, #0x28]\n"
        "    adds r4, #1\n"
        "    str r4, [sp, #0x30]\n"
        "    ldr r1, [sp, #0x14]\n"
        "    cmp r1, r8\n"
        "    bhs .L080B706A\n"
        "    lsrs r0, r3, #3\n"
        "    lsls r0, r0, #0xa\n"
        "    ldr r2, [sp, #0x1c]\n"
        "    adds r0, r2, r0\n"
        "    str r0, [sp, #0x20]\n"
        "    movs r0, #7\n"
        "    mov sl, r0\n"
        "    ands r3, r0\n"
        "    lsls r3, r3, #2\n"
        "    str r3, [sp, #0x24]\n"
        ".L080B6FC0:\n"
        "    lsrs r1, r6, #3\n"
        "    lsls r1, r1, #5\n"
        "    ldr r2, [sp, #0x20]\n"
        "    adds r1, r2, r1\n"
        "    ldr r3, [sp, #0x24]\n"
        "    adds r1, r1, r3\n"
        "    adds r0, r6, #0\n"
        "    mov r2, sl\n"
        "    ands r0, r2\n"
        "    lsrs r0, r0, #1\n"
        "    adds r1, r1, r0\n"
        "    mov ip, r1\n"
        "    ldrb r4, [r1]\n"
        "    mov r3, sb\n"
        "    lsrs r0, r3, #3\n"
        "    lsls r0, r0, #0xa\n"
        "    lsrs r3, r5, #3\n"
        "    lsls r3, r3, #5\n"
        "    str r3, [sp, #0x34]\n"
        "    mov r2, sb\n"
        "    mov r1, sl\n"
        "    ands r2, r1\n"
        "    lsls r2, r2, #2\n"
        "    adds r1, r5, #0\n"
        "    mov r3, sl\n"
        "    ands r1, r3\n"
        "    lsrs r1, r1, #1\n"
        "    ldr r3, [sp, #0x18]\n"
        "    adds r0, r3, r0\n"
        "    ldr r3, [sp, #0x34]\n"
        "    adds r0, r0, r3\n"
        "    adds r0, r0, r2\n"
        "    adds r0, r0, r1\n"
        "    ldrb r1, [r0]\n"
        "    adds r2, r1, #0\n"
        "    adds r0, r6, #0\n"
        "    movs r3, #1\n"
        "    ands r0, r3\n"
        "    cmp r0, #0\n"
        "    bne .L080B7026\n"
        "    adds r0, r5, #0\n"
        "    ands r0, r3\n"
        "    cmp r0, #0\n"
        "    bne .L080B7020\n"
        "    movs r0, #0xf\n"
        "    ands r1, r0\n"
        "    orrs r4, r1\n"
        "    b .L080B7040\n"
        ".L080B7020:\n"
        "    lsrs r0, r1, #4\n"
        "    orrs r4, r0\n"
        "    b .L080B7040\n"
        ".L080B7026:\n"
        "    adds r0, r5, #0\n"
        "    movs r3, #1\n"
        "    ands r0, r3\n"
        "    cmp r0, #0\n"
        "    bne .L080B703A\n"
        "    lsls r0, r1, #4\n"
        "    orrs r4, r0\n"
        "    lsls r0, r4, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    b .L080B7040\n"
        ".L080B703A:\n"
        "    movs r0, #0xf0\n"
        "    ands r2, r0\n"
        "    orrs r4, r2\n"
        ".L080B7040:\n"
        "    mov r0, ip\n"
        "    strb r4, [r0]\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldr r1, [sp, #8]\n"
        "    adds r7, r7, r1\n"
        "    cmp r7, r8\n"
        "    blo .L080B705C\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    mov r2, r8\n"
        "    subs r7, r7, r2\n"
        ".L080B705C:\n"
        "    ldr r0, [sp, #0x14]\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0x14]\n"
        "    cmp r0, r8\n"
        "    blo .L080B6FC0\n"
        ".L080B706A:\n"
        "    ldr r3, [sp, #0x2c]\n"
        "    lsls r0, r3, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    ldr r1, [sp, #0x28]\n"
        "    ldr r0, [sp, #0x10]\n"
        "    cmp r1, r0\n"
        "    blo .L080B7086\n"
        "    mov r0, sb\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sb, r0\n"
        "    ldr r2, [sp, #0x10]\n"
        "    subs r1, r1, r2\n"
        ".L080B7086:\n"
        "    ldr r2, [sp, #0x30]\n"
        "    lsls r0, r2, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    ldr r2, .L080B70B8\n"
        "    ldrh r0, [r2, #2]\n"
        "    adds r0, #1\n"
        "    strh r0, [r2, #2]\n"
        "    cmp r4, #0xf\n"
        "    bhi .L080B709A\n"
        "    b .L080B6F7C\n"
        ".L080B709A:\n"
        "    adds r0, r2, #0\n"
        "    strh r7, [r0, #4]\n"
        "    strh r1, [r0, #6]\n"
        "    mov r1, sb\n"
        "    strh r1, [r0, #8]\n"
        "    strh r3, [r0, #0xa]\n"
        "    movs r0, #1\n"
        ".L080B70A8:\n"
        "    add sp, #0x38\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        ".L080B70B8: .4byte 0x03004520 @ IWRAM+0x4520\n"
    );
}
#endif

// sub_080B70BC @ 0x080B70BC
/* Queues a warp to (map, floor) at (x, y) facing dir and switches the main callback. */
void sub_080B70BC(u16 map, u16 floor, u16 x, u16 y, u16 dir, u32 arg)
{
    gWarpDest.x = x;
    gWarpDest.y = y;
    gWarpDest.dir = dir;
    gWarpDest.unk0C = arg;
    gUnk_03004610 = 0;
    gUnk_03004514 = floor;
    gUnk_03004614 = map;
    gUnk_03004544 = 4;
    SetMainCallback(sub_080C1560);
}

// sub_080B710C @ 0x080B710C
void sub_080B710C(u16 map, u16 floor, u16 x, u16 y, u16 dir, u32 arg)
{
    gWarpDest.x = x;
    gWarpDest.y = y;
    gWarpDest.dir = dir;
    gWarpDest.unk0C = arg;
    gUnk_03004610 = 0;
    gUnk_03004514 = floor;
    gUnk_03004614 = map;
    gUnk_03004544 = 6;
    SetMainCallback(sub_080C1560);
}

// sub_080B715C @ 0x080B715C
void sub_080B715C(struct Task *task, u16 value)
{
    *(u16 *)task->data = value;
}

// sub_080B7160 @ 0x080B7160
void sub_080B7160(struct Task *task)
{
    if (sub_0813EB78() == 0)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080B717C @ 0x080B717C
void sub_080B717C(void)
{
    REG_DISPCNT &= 0xF7FF;
}

// sub_080B7190 @ 0x080B7190
void sub_080B7190(void)
{
    REG_BG3CNT = 0x8607;
    REG_DISPCNT |= 0x800;
}

// sub_080B71B4 @ 0x080B71B4
void sub_080B71B4(struct Task *task, u32 step)
{
    switch (step)
    {
    case 0:
        VBlankTask_AddCounted(sub_080B717C, 1);
        gUnk_0200AB04 &= ~0x8000;
        break;
    case 1:
        sub_080C14FC();
        VBlankTask_AddCounted(sub_080C153C, 1);
        break;
    case 2:
        VBlankTask_AddCounted(sub_080ADF64, 1);
        break;
    case 3:
        VBlankTask_AddCounted(sub_080B7190, 1);
        sub_080C3818(1);
        break;
    }
}

// sub_080B721C @ 0x080B721C
u32 sub_080B721C(const u16 *rec)
{
    if (rec != NULL
        && (rec[1] == 0xE || rec[1] == 0x24 || rec[1] == 0x25 || rec[1] == 0x26
            || rec[1] == 0x27 || rec[1] == 0x28))
        return TRUE;
    return FALSE;
}

// sub_080B7248 @ 0x080B7248
/* Warp step 0: enters the destination map and marks the arrival square on the automap. */
void sub_080B7248(struct Task *task, u32 step)
{
    if (step == 0)
    {
        s32 recs;
        u16 *a, *b, *c, *d, *e, *f, *g;

        gUnk_03004614 = gWarpDest.map;
        gUnk_03004514 = gWarpDest.floor;
        Map_SetGraphicsPointers(gUnk_03004614, gUnk_03004514);
        sub_080AE234();
        Field_SetPosition(gWarpDest.x, gWarpDest.y);
        gFieldState.unk02 = gWarpDest.dir;
        sub_080AD7F0();
        gFieldState.unk34 = step;
        recs = FieldMap_CellRecordsRel(0, 1);
        a = FieldMap_FindRecord(recs, 4);
        b = FieldMap_FindRecord(recs, 0x23);
        c = FieldMap_FindRecord(recs, 1);
        d = FieldMap_FindRecord(recs, 2);
        e = FieldMap_FindRecord(recs, 0x1B);
        f = FieldMap_FindRecord(recs, 0x1C);
        g = FieldMap_FindRecord(recs, 0xC);
        if (a != NULL || c != NULL || d != NULL || e != NULL || f != NULL || g != NULL
            || sub_080B721C(b))
            Automap_SetVisitedAhead(gFieldState.unk12, gFieldState.unk14, gFieldState.unk02);
        Automap_SetVisited(gFieldState.unk12, gFieldState.unk14);
        if (gUnk_03004614 == 0x4A && gUnk_03004514 == 3 && gFieldState.unk12 == 0 && gFieldState.unk14 == 1)
            Automap_SetVisitedAhead(gFieldState.unk12, gFieldState.unk14, gFieldState.unk02);
    }
    else
    {
        VBlankTask_AddCounted(sub_080ADF64, 1);
        sub_080B2840(0, 0, 0);
    }
}

// sub_080B7368 @ 0x080B7368
void sub_080B7368(struct Task *task)
{
    if (gUnk_03003FF8 == 0)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080B7384 @ 0x080B7384
void sub_080B7384(void)
{
    u32 has = FieldMap_HasRecordRel(0, 0, 0x19);

    if (has == 1)
    {
        gFieldState.unk36 = FieldMap_FindRecord(FieldMap_CellRecordsRel(0, 0), 0x19)[1];
        gFieldState.unk34 = has;
    }
}

// sub_080B73B8 @ 0x080B73B8
void sub_080B73B8(struct Task *task, u32 arg)
{
    gUnk_03003FF4 = 1;
    if (sub_0813EB78() == 0 && sub_080AF8D0((u16)arg, (u16)arg, 0) != 0)
        task->result = 1;
    else
        task->result = 0;
    gUnk_03003FF4 = 0;
}

// sub_080B73FC @ 0x080B73FC
void sub_080B73FC(void)
{
    if (sub_0813EB78() == 0)
        Field_SetState(1);
}

// sub_080B7414 @ 0x080B7414
void sub_080B7414(void)
{
}

// sub_080B7418 @ 0x080B7418
void sub_080B7418(void)
{
    sub_080C3818(1);
}
