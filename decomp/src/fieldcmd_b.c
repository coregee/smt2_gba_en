#include "global.h"
#include "fieldcmd.h"

// sub_080B94E0 @ 0x080B94E0
void sub_080B94E0(void)
{
    gUnk_0300000E += 4;
}

// sub_080B94F0 @ 0x080B94F0
void sub_080B94F0(void)
{
    gUnk_0300000E -= 4;
}

// sub_080B9500 @ 0x080B9500
void sub_080B9500(void)
{
}

// sub_080B9504 @ 0x080B9504
void sub_080B9504(struct Task *task)
{
    task->data.h[0] = gUnk_0300000E;
}

// sub_080B9510 @ 0x080B9510
struct Task *sub_080B9510(void)
{
    return Task_Create(gUnknown_08165444, 0xFFFF);
}

// sub_080B9528 @ 0x080B9528
u32 sub_080B9528(struct Task *t)
{
    u32 done = 0;

    if (t->state == 0)
        done = 1;
    return done;
}

// sub_080B953C @ 0x080B953C
u32 sub_080B953C(void)
{
    s32 v;
    u32 r;

    if (FieldMap_FindRecord(FieldMap_CellRecordsRel(0, 0), 0x21))
        return 0;
    v = sub_080F3190();
    r = 0;
    if (v == 0)
        r = 1;
    return r;
}

// sub_080B9568 @ 0x080B9568
u32 sub_080B9568(void)
{
    return 1;
}

// sub_080B956C @ 0x080B956C
void sub_080B956C(struct Task *task)
{
    task->data.w[0] = Window_Create(2, 0xB, 0x1A, 2, 0);
}

// sub_080B958C @ 0x080B958C
void sub_080B958C(void)
{
    Text_DrawSpriteString(gUnknown_08165574, 0, 0, 0x12, 0x59, 0xC);
    sub_080C4AB0(0, 0, 0xD6, 0x5E);
}

// sub_080B95BC @ 0x080B95BC
void sub_080B95BC(struct Task *task)
{
    task->result = 0;
    if ((*(vu16 *)&gKeysNew & 1) || (*(vu16 *)&gKeysNew & 2))
        task->result = 1;
}

// sub_080B95E8 @ 0x080B95E8
void sub_080B95E8(struct Task *task)
{
    Window_Close((void *)task->data.w[0], 0);
    Field_SetState(0x12);
}

// sub_080B95FC @ 0x080B95FC
void sub_080B95FC(void)
{
    if (gGameState.unkAC0 == 0 && FieldMap_HasRecordRel(0, 0, 6) != 1)
    {
        const u16 *src = gUnk_03004630;
        u16 *pal = gPaletteTarget;

        pal[0] = src[0];
        Palette_CopyWithEffect(3, src, &pal[0xE0], 0x40, 0x20);
        Palette_CopyWithEffect(3, gUnk_03004510, &pal[0xD0], 0x20, 0x20);
        gUnk_0300452C = PalFade_FadeRangeWithDuration(0xD0, 0x30, 1, 0x10);
        if (pal[0] != 0)
            PalFade_FadeRangeWithDuration(0, 1, 1, 0x10);
    }
}

// Location_GetNameCellFromCoords @ 0x080B968C
#ifdef NONMATCHING
/* Returns the location-name cell for map/floor at x,y: temporarily switches the current
   map (0x03004614/0x03004514) so sub_080C1F50 converts the coordinates. */
u16 *Location_GetNameCellFromCoords(u16 map, u16 floor, u16 x, u16 y)
{
    u16 oldMap = gUnk_03004614;
    u16 oldFloor = gUnk_03004514;
    u16 cx, cy;
    u16 *cell;

    gUnk_03004614 = map;
    gUnk_03004514 = floor;
    sub_080C1F50(x, y, &cx, &cy);
    cell = (u16 *)&gUnknown_080A54AC[(((cy >> 2) & 3) + (cy >> 4) * 32 + (cx >> 4) * 4) * 64
                                     + ((cx >> 2) & 3) * 16];
    gUnk_03004614 = oldMap;
    gUnk_03004514 = oldFloor;
    return cell;
}
#else
NAKED
u16 *Location_GetNameCellFromCoords(u16 map, u16 floor, u16 x, u16 y)
{
    asm_unified(
        ".L080B968C:\n"
        "    push {r4, r5, r6, lr}\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6}\n"
        "    sub sp, #4\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    ldr r6, .L080B9704\n"
        "    ldrh r4, [r6]\n"
        "    mov sb, r4\n"
        "    ldr r5, .L080B9708\n"
        "    ldrh r4, [r5]\n"
        "    mov r8, r4\n"
        "    str r0, [r6]\n"
        "    str r1, [r5]\n"
        "    mov r4, sp\n"
        "    adds r4, #2\n"
        "    adds r0, r2, #0\n"
        "    adds r1, r3, #0\n"
        "    mov r2, sp\n"
        "    adds r3, r4, #0\n"
        "    bl sub_080C1F50\n"
        "    ldrh r1, [r4]\n"
        "    lsrs r0, r1, #2\n"
        "    movs r3, #3\n"
        "    ands r0, r3\n"
        "    lsrs r1, r1, #4\n"
        "    lsls r1, r1, #5\n"
        "    adds r0, r0, r1\n"
        "    mov r1, sp\n"
        "    ldrh r2, [r1]\n"
        "    lsrs r1, r2, #4\n"
        "    lsls r1, r1, #2\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #6\n"
        "    lsrs r2, r2, #2\n"
        "    ands r2, r3\n"
        "    lsls r2, r2, #4\n"
        "    adds r0, r0, r2\n"
        "    lsls r0, r0, #1\n"
        "    ldr r1, .L080B970C\n"
        "    adds r0, r0, r1\n"
        "    mov r1, sb\n"
        "    str r1, [r6]\n"
        "    mov r4, r8\n"
        "    str r4, [r5]\n"
        "    add sp, #4\n"
        "    pop {r3, r4}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        ".L080B9704: .4byte 0x03004614 @ IWRAM+0x4614\n"
        ".L080B9708: .4byte 0x03004514 @ IWRAM+0x4514\n"
        ".L080B970C: .4byte gUnknown_080A54AC\n"
    );
}
#endif

// Elevator_GetFloorTable @ 0x080B9710
const struct FloorTable *Elevator_GetFloorTable(struct FloorMenu *m)
{
    return gUnknown_081655F8[m->tableId];
}

// Elevator_GetFloorRef @ 0x080B9720
const struct FloorRef *Elevator_GetFloorRef(struct FloorMenu *m, u16 i)
{
    const struct FloorRef *f = (const struct FloorRef *)((const u16 *)Elevator_GetFloorTable(m) + 1);

    return &f[i];
}

// Elevator_GetFloor @ 0x080B9738
struct MapHeader *Elevator_GetFloor(struct FloorMenu *m, u16 i)
{
    const struct FloorRef *f = Elevator_GetFloorRef(m, i);

    return DungeonMap_GetFloor(f->map, f->floor);
}

// FieldMap_GetElevatorRecord @ 0x080B9750
u16 *FieldMap_GetElevatorRecord(void)
{
    return FieldMap_FindRecord(FieldMap_CellRecordsRel(0, 0), 3);
}

// sub_080B9764 @ 0x080B9764
u16 sub_080B9764(void)
{
    if (FieldMap_GetElevatorRecord()[1] == 0)
        return 0x5A;
    else
        return 0x5B;
}

// sub_080B977C @ 0x080B977C
void sub_080B977C(struct Task *task)
{
    if (sub_080B9764() == 0x5A || sub_080B9764() == 0x5B)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080B97A8 @ 0x080B97A8
void sub_080B97A8(struct Task *task, u32 step)
{
    struct FloorMenu *d = FLOOR_MENU(task);

    if (step == 0)
        d->loadDone = 1;
    Map_LoadGraphicsStep(sub_080B9764(), 0, &FLOOR_MENU(task)->loadDone);
    if (d->loadDone)
        task->result = 0;
    else
        task->result = 1;
}

// sub_080B97E0 @ 0x080B97E0
void sub_080B97E0(void)
{
    DmaCopy32(3, gUnknown_081C1270, (void *)0x06003000, 0x1000);
}

// sub_080B9804 @ 0x080B9804
void sub_080B9804(void)
{
}

// sub_080B9808 @ 0x080B9808
void sub_080B9808(void)
{
    Map_SetGraphicsPointers(sub_080B9764(), 0);
    gFieldLoadStep = 0;
}

// sub_080B9828 @ 0x080B9828
void sub_080B9828(void)
{
    DmaCopy32(3, gUnknown_08165614, (void *)0x06016000, 0x1000);
}

// sub_080B984C @ 0x080B984C
void sub_080B984C(struct Task *task)
{
    VBlankTask_AddCounted(Field_LoadGraphicsStep, 1);
    VBlankTask_AddCounted(sub_080B9828, 1);
    if (gFieldLoadStep == 0xFFFF)
    {
        task->result = 1;
        sub_080B2840(0, 0, 0);
    }
    else
    {
        task->result = 0;
    }
}

// sub_080B9898 @ 0x080B9898
void sub_080B9898(struct Task *task)
{
    if (gFieldState.unk0E == 0)
    {
        task->result = 1;
        sub_080AE494(sub_080B0158);
    }
    else
    {
        task->result = 0;
    }
}

// sub_080B98C0 @ 0x080B98C0
void sub_080B98C0(void)
{
    sub_080C7218();
    sub_080C7414();
    sub_080C6FF0();
    sub_080AE494(sub_080B0158);
}

// Elevator_GetFloorCount @ 0x080B98DC
u16 Elevator_GetFloorCount(struct Task *task)
{
    struct FloorMenu *d = FLOOR_MENU(task);

    if (d->useTable != 0)
        return Elevator_GetFloorTable(d)->count;
    return d->count;
}

// Elevator_SetCursorToCurrentFloor @ 0x080B98F8
/* Puts the cursor on the current floor. */
void Elevator_SetCursorToCurrentFloor(struct Task *task)
{
    struct FloorMenu *d = FLOOR_MENU(task);
    u16 i;
    u16 n;
    struct MapHeader *cur;

    if (d->useTable)
    {
        n = Elevator_GetFloorCount(task);
        cur = DungeonMap_GetFloor(gUnk_03004614, gUnk_03004514);
        for (i = 0; i < n; i++)
        {
            if (Elevator_GetFloor(d, i) == cur)
            {
                d->cursor = i;
                return;
            }
        }
    }
    else
    {
        d->cursor = d->cursorInit;
    }
}

// sub_080B9954 @ 0x080B9954
void sub_080B9954(struct Task *task)
{
    struct FloorMenu *d = FLOOR_MENU(task);
    u32 h = Elevator_GetFloorCount(task) * 2;

    if (h > 11)
        h = 11;
    if (h == 4)
        h = 5;
    Elevator_SetCursorToCurrentFloor(task);
    d->textWin = TextWindow_Create(0x13, 0, 9, (u16)h, 1);
    d->win = Window_Create(2, 0xB, 0x1A, 8, 0);
    gHudState[0x18] = 1;
}

// sub_080B99B0 @ 0x080B99B0
void sub_080B99B0(struct Task *task)
{
    s32 r = TextWindow_IsDone(task->data.w[0]);

    if (r != 1)
        r = 0;
    task->result = r;
}

// sub_080B99C8 @ 0x080B99C8
void sub_080B99C8(struct Task *task)
{
    struct FloorMenu *d = FLOOR_MENU(task);

    TextWindow_Close(task->data.w[0], 0);
    Window_Close((void *)d->win, 0);
    gHudState[0x18] = 0;
}

// sub_080B99F0 @ 0x080B99F0
void sub_080B99F0(struct Task *task, u32 step)
{
    if (step == 0)
        sub_080B2064(sub_080B1A1C(gFieldState.unk02), 1);
    else
        sub_080B2064(gFieldState.unk06, gFieldState.unk08);
}

// sub_080B9A24 @ 0x080B9A24
void sub_080B9A24(struct Task *task)
{
    s32 r = sub_080B2090();

    task->result = 0;
    if (r != -1)
    {
        task->result = 1;
        gFieldState.unk2E = 0;
    }
}

// Elevator_DrawFloorLabel @ 0x080B9A4C
#ifdef NONMATCHING
/* Draws the floor label ("<n>F" or "B<n>F", one or two digits) of menu row `row`. */
void Elevator_DrawFloorLabel(struct Task *task, struct MapHeader *floor, u32 row)
{
    u16 count = Elevator_GetFloorCount(task);
    u16 y = count * 13 - (u16)(row * 13 + 10);
    u16 n;
    u8 *dig;

    if (floor->floor < 0)
    {
        n = -floor->floor;
        dig = NumberToDigits(n);
        Text_DrawSpriteString(gUnknown_08165674, 0, 0, 0x9C, y, 0xC);
        if (n > 9)
        {
            FontSprite_DrawGlyph(gUnknown_0816567E[dig[1]], 0, 0, 0xB4, y);
            FontSprite_DrawGlyph(gUnknown_0816567E[dig[0]], 0, 0, 0xC0, y);
            Text_DrawSpriteString(gUnknown_0816567A, 0, 0, 0xCC, y, 0xC);
        }
        else
        {
            FontSprite_DrawGlyph(gUnknown_0816567E[dig[0]], 0, 0, 0xB4, y);
            Text_DrawSpriteString(gUnknown_0816567A, 0, 0, 0xC0, y, 0xC);
        }
    }
    else
    {
        n = floor->floor;
        dig = NumberToDigits(n);
        if (n > 9)
        {
            FontSprite_DrawGlyph(gUnknown_0816567E[dig[1]], 0, 0, 0x9C, y);
            FontSprite_DrawGlyph(gUnknown_0816567E[dig[0]], 0, 0, 0xA8, y);
            Text_DrawSpriteString(gUnknown_0816567A, 0, 0, 0xB4, y, 0xC);
        }
        else
        {
            FontSprite_DrawGlyph(gUnknown_0816567E[dig[0]], 0, 0, 0x9C, y);
            Text_DrawSpriteString(gUnknown_0816567A, 0, 0, 0xA8, y, 0xC);
        }
    }
}
#else
NAKED
void Elevator_DrawFloorLabel(struct Task *task, struct MapHeader *floor, u32 row)
{
    asm_unified(
        ".L080B9A4C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    sub sp, #8\n"
        "    adds r5, r1, #0\n"
        "    adds r4, r2, #0\n"
        "    bl Elevator_GetFloorCount\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    movs r2, #0xd\n"
        "    adds r1, r0, #0\n"
        "    muls r1, r2, r1\n"
        "    adds r0, r4, #0\n"
        "    muls r0, r2, r0\n"
        "    adds r0, #0xa\n"
        "    subs r1, r1, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r6, r1, #0x10\n"
        "    adds r7, r6, #0\n"
        "    movs r1, #6\n"
        "    ldrsh r0, [r5, r1]\n"
        "    cmp r0, #0\n"
        "    bge .L080B9B18\n"
        "    ldrh r4, [r5, #6]\n"
        "    rsbs r4, r4, #0\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl NumberToDigits\n"
        "    adds r5, r0, #0\n"
        "    ldr r0, .L080B9ADC\n"
        "    str r6, [sp]\n"
        "    movs r7, #0xc\n"
        "    str r7, [sp, #4]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0x9c\n"
        "    bl Text_DrawSpriteString\n"
        "    cmp r4, #9\n"
        "    bls .L080B9AE8\n"
        "    ldr r4, .L080B9AE0\n"
        "    ldrb r0, [r5, #1]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    str r6, [sp]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0xb4\n"
        "    bl FontSprite_DrawGlyph\n"
        "    ldrb r0, [r5]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    str r6, [sp]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0xc0\n"
        "    bl FontSprite_DrawGlyph\n"
        "    ldr r0, .L080B9AE4\n"
        "    str r6, [sp]\n"
        "    str r7, [sp, #4]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0xcc\n"
        "    bl Text_DrawSpriteString\n"
        "    b .L080B9B94\n"
        "    .byte 0x00, 0x00\n"
        ".L080B9ADC: .4byte gUnknown_08165674\n"
        ".L080B9AE0: .4byte gUnknown_0816567E\n"
        ".L080B9AE4: .4byte gUnknown_0816567A\n"
        ".L080B9AE8:\n"
        "    ldr r1, .L080B9B10\n"
        "    ldrb r0, [r5]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    str r6, [sp]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0xb4\n"
        "    bl FontSprite_DrawGlyph\n"
        "    ldr r0, .L080B9B14\n"
        "    str r6, [sp]\n"
        "    str r7, [sp, #4]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0xc0\n"
        "    bl Text_DrawSpriteString\n"
        "    b .L080B9B94\n"
        ".L080B9B10: .4byte gUnknown_0816567E\n"
        ".L080B9B14: .4byte gUnknown_0816567A\n"
        ".L080B9B18:\n"
        "    ldrh r4, [r5, #6]\n"
        "    adds r0, r4, #0\n"
        "    bl NumberToDigits\n"
        "    adds r5, r0, #0\n"
        "    cmp r4, #9\n"
        "    bls .L080B9B6C\n"
        "    ldr r4, .L080B9B64\n"
        "    ldrb r0, [r5, #1]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    str r6, [sp]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0x9c\n"
        "    bl FontSprite_DrawGlyph\n"
        "    ldrb r0, [r5]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    str r6, [sp]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0xa8\n"
        "    bl FontSprite_DrawGlyph\n"
        "    ldr r0, .L080B9B68\n"
        "    str r6, [sp]\n"
        "    movs r1, #0xc\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0xb4\n"
        "    bl Text_DrawSpriteString\n"
        "    b .L080B9B94\n"
        ".L080B9B64: .4byte gUnknown_0816567E\n"
        ".L080B9B68: .4byte gUnknown_0816567A\n"
        ".L080B9B6C:\n"
        "    ldr r1, .L080B9B9C\n"
        "    ldrb r0, [r5]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    str r7, [sp]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0x9c\n"
        "    bl FontSprite_DrawGlyph\n"
        "    ldr r0, .L080B9BA0\n"
        "    str r7, [sp]\n"
        "    movs r1, #0xc\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0xa8\n"
        "    bl Text_DrawSpriteString\n"
        ".L080B9B94:\n"
        "    add sp, #8\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080B9B9C: .4byte gUnknown_0816567E\n"
        ".L080B9BA0: .4byte gUnknown_0816567A\n"
    );
}
#endif

// Elevator_DrawMenu @ 0x080B9BA4
void Elevator_DrawMenu(struct Task *task)
{
    struct FloorMenu *d = FLOOR_MENU(task);
    u16 *rec;
    u16 n;
    u32 i;

    DungeonMap_GetFloor(gUnk_03004614, 0);
    rec = FieldMap_GetElevatorRecord();
    n = Elevator_GetFloorCount(task);
    if (d->drawn == 1)
    {
        if (d->useTable)
        {
            for (i = 0; i < n; i++)
                Elevator_DrawFloorLabel(task, Elevator_GetFloor(d, i), i);
        }
        else
        {
            for (i = 0; i < d->count; i++)
                Elevator_DrawFloorLabel(task, DungeonMap_GetFloor(gUnk_03004614, d->floors[i]), i);
        }
        Text_DrawSpriteString(gUnknown_08165654, 0, 0, 0x12, 0x59, 0xC);
    }
    if (rec[1] <= 1)
        sub_080B2AB0();
    else
        sub_080BA2F0(task);
}

// sub_080B9C6C @ 0x080B9C6C
void sub_080B9C6C(struct Task *task)
{
    FLOOR_MENU(task)->drawn = 1;
}

// Elevator_HandleInput @ 0x080B9C74
void Elevator_HandleInput(struct Task *task)
{
    u16 n = Elevator_GetFloorCount(task);
    struct FloorMenu *d = FLOOR_MENU(task);

    task->unk1E = 0;
    if (gFieldState.unk3A & 1)
    {
        Sound_Play(0x65);
        task->unk1E = 1;
    }
    else if (gFieldState.unk3A & 2)
    {
        Sound_Play(0x66);
        task->unk1E = 2;
    }
    else if (gFieldState.unk3C & 0x40)
    {
        if (d->cursor != n - 1)
        {
            d->cursor++;
            Sound_Play(0x64);
        }
    }
    else if (gFieldState.unk3C & 0x80)
    {
        if (d->cursor != 0)
        {
            d->cursor--;
            Sound_Play(0x64);
        }
    }
    sub_080C49EC(6, 0, 0, 0x9C, n * 13 - (u16)(d->cursor * 13 + 10));
}

// Elevator_MoveToSelectedFloor @ 0x080B9D18
/* Moves to the selected floor; result 0 when it is the current one. */
void Elevator_MoveToSelectedFloor(struct Task *task)
{
    struct FloorMenu *d = FLOOR_MENU(task);

    gUnk_03004634 = d->prevFloor = gUnk_03004514;
    if (d->useTable)
    {
        u16 sel = d->cursor;

        Elevator_SetCursorToCurrentFloor(task);
        if (sel != d->cursor)
        {
            const struct FloorRef *f = Elevator_GetFloorRef(d, sel);

            gUnk_03004614 = f->map;
            gUnk_03004514 = f->floor;
            sub_080AE234();
            sub_080AE294();
            sub_080B31C4(gUnk_03004614, 3, gUnk_03004000[2]);
            d->prevFloor = d->cursor;
            d->cursor = sel;
            task->result = 1;
        }
        else
        {
            task->result = 0;
        }
    }
    else
    {
        u16 f = d->floors[d->cursor];

        if (d->prevFloor != f)
        {
            gUnk_03004514 = f;
            sub_080AE234();
            sub_080AE294();
            sub_080B31C4(gUnk_03004614, 3, gUnk_03004000[2]);
            task->result = 1;
        }
        else
        {
            task->result = 0;
        }
    }
}

// sub_080B9DD4 @ 0x080B9DD4
void sub_080B9DD4(struct Task *task)
{
    struct FloorMenu *d = FLOOR_MENU(task);

    if (d->useTable)
    {
        struct MapHeader *sel = Elevator_GetFloor(d, d->cursor);

        if (sel == DungeonMap_GetFloor(gUnk_03004614, gUnk_03004514))
        {
            task->result = 1;
            return;
        }
    }
    else if (gUnk_03004514 == d->floors[d->cursor])
    {
        task->result = 1;
        return;
    }
    sub_080B343C(-2);
    if (gFieldState.unk2E == 0)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080B9E48 @ 0x080B9E48
void sub_080B9E48(struct Task *task, u32 step)
{
    sub_080C7234();
    sub_080C7430();
    sub_080C700C();
    sub_080B2030(gFieldState.unk0A, gFieldState.unk02, 3);
    if (step == 1)
        gFieldState.unk2E = 0x21;
}
