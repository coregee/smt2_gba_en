#include "global.h"
#include "field.h"

/* Fills automap cell [row][col] from map square (x, y) if it has been visited
   (Automap_IsVisited); wall code 3 shows as 2. Bit 15 of flags marks a square with an event. */
// Automap_FillCell @ 0x080AECD4
void Automap_FillCell(u16 x, u16 y, u16 col, u16 row)
{
    struct AutomapCell *cell = &gAutomapCells[row][col];

    if ((s16)x < 0 || x >= gFieldState.unk1A || (s16)y < 0 || y >= gFieldState.unk1C)
    {
        cell->flags = 0;
    }
    else if (Automap_IsVisited(x, y) != 0)
    {
        u16 dir = sub_080B447C();
        u16 square = gFieldState.unk20[y * gFieldState.unk1A + x];
        u32 i;

        for (i = 0; i < 4; i++)
        {
            cell->walls[i] = (square >> gUnknown_0815F2E6[dir]) & 3;
            cell->x = x;
            cell->y = y;
            if (cell->walls[i] == 3)
                cell->walls[i] = 2;
            dir = (dir + 1) & 3;
        }
        cell->flags = 1;
        if (FieldMap_FindRecord(FieldMap_CellRecordsAt(x, y), 6) != 0)
            cell->flags |= 0x8000;
    }
}

/* Builds the 28x11 automap around (x, y) seen facing dir, scrolled by gAutomapScroll rows,
   and sets the "more above"/"more below" flags gUnk_0200DFC8/gUnk_0200DFCA. */
// Automap_Build @ 0x080AEDB4
void Automap_Build(u32 dir, s32 x, s32 y)
{
    vu32 zero;
    u16 row, col;
    u16 rows = 11, cols = 28;
    s16 pos;

    gUnk_0200DFC8 = 0;
    gUnk_0200DFCA = 0;
    zero = 0;
    FIELD_DMA3_SET(&zero, gAutomapCells, 0x85000000 | (sizeof(struct AutomapCell) * 28 * 11 / 4));
    switch (dir)
    {
    case 0:
        x -= 13;
        y -= 5;
        break;
    case 1:
        x += 5;
        y -= 13;
        break;
    case 2:
        x += 13;
        y += 5;
        break;
    case 3:
        x -= 5;
        y += 13;
        break;
    }
    for (row = 0; row < rows; row++)
    {
        for (col = 0; col < cols; col++)
        {
            switch (dir)
            {
            case 0:
                Automap_FillCell(col + x, row + y - gAutomapScroll, col, row);
                break;
            case 1:
                Automap_FillCell(x - row + gAutomapScroll, col + y, col, row);
                break;
            case 2:
                Automap_FillCell(x - col, y - row + gAutomapScroll, col, row);
                break;
            case 3:
                Automap_FillCell(row + x - gAutomapScroll, y - col, col, row);
                break;
            }
        }
    }
    switch (dir)
    {
    case 0:
        if (gFieldState.unk1C > 11)
        {
            pos = y - gAutomapScroll;
            if (pos < gFieldState.unk1C - 9)
                gUnk_0200DFC8 = 1;
            if (pos > -2)
                gUnk_0200DFCA = 1;
        }
        break;
    case 1:
        if (gFieldState.unk1A > 11)
        {
            pos = gAutomapScroll + x;
            if (pos > 8)
                gUnk_0200DFC8 = 1;
            if (pos < gFieldState.unk1A + 1)
                gUnk_0200DFCA = 1;
        }
        break;
    case 2:
        if (gFieldState.unk1C > 11)
        {
            pos = gAutomapScroll + y;
            if (pos > 8)
                gUnk_0200DFC8 = 1;
            if (pos < gFieldState.unk1C + 1)
                gUnk_0200DFCA = 1;
        }
        break;
    case 3:
        if (gFieldState.unk1A > 11)
        {
            pos = x - gAutomapScroll;
            if (pos < gFieldState.unk1A - 9)
                gUnk_0200DFC8 = 1;
            if (pos > -2)
                gUnk_0200DFCA = 1;
        }
        break;
    }
}

// sub_080AEFAC @ 0x080AEFAC
void sub_080AEFAC(void)
{
    FIELD_DMA3_SET(gUnknown_081B28B8, 0x06011500, 0x84000100);
}

// sub_080AEFD0 @ 0x080AEFD0
void sub_080AEFD0(void)
{
    Field_SetState(0x16);
    gFieldState.unk1E = 0;
    sub_080C7234();
    sub_080C7430();
    VBlankTask_AddCounted(sub_080AEFAC, 1);
}

// sub_080AEFFC @ 0x080AEFFC
void sub_080AEFFC(void)
{
    Encounter_SetCounter(0);
    sub_080AEFD0();
    gFieldState.unk44 = 0;
}

// sub_080AF018 @ 0x080AF018
void sub_080AF018(void)
{
    Encounter_SetCounter(0);
    sub_080AEFD0();
    gFieldState.unk44 = 1;
}

// sub_080AF034 @ 0x080AF034
void sub_080AF034(void)
{
    gUnk_03003BB8 = 0;
    sub_080B628C();
}

// sub_080AF048 @ 0x080AF048
void sub_080AF048(void)
{
    Field_SetState(0x14);
    gFieldState.unk1E = 0;
}

/* Starts an event script (NULL: the default one). The script at gUnknown_08072766 is
   replaced by gUnknown_08072B3A once flag 0x100 is set (and sets it the first time). */
// sub_080AF060 @ 0x080AF060
void sub_080AF060(const void *script)
{
    if (script == gUnknown_08072766)
    {
        if (Flag_Test(0x100))
            script = gUnknown_08072B3A;
        else
            Flag_Set(0x100);
    }
    if (script == NULL)
        ScriptVM_Init(gUnknown_0815F2EE, 0);
    else
        ScriptVM_Init(script, 0);
}

/* Returns 1 when the script need not run, 0 when its random/flag condition fails, 2 for
   the gUnknown_080775A6 special case, else the result of ScriptVM_RunAlt. */
// sub_080AF0AC @ 0x080AF0AC
s32 sub_080AF0AC(const void *script)
{
    FieldMap_FindRecord(FieldMap_CellRecordsRel(0, 0), 0x23);
    if (sub_080B721C() != 0)
        return 1;
    if (script == gUnknown_08072766 && Flag_Test(0x100))
        script = gUnknown_08072B3A;
    if (script == gUnknown_080775A6)
    {
        s32 count = 0;
        s32 i;

        for (i = 4; i < 16; i++)
        {
            if (Combatant_IsUsed(i))
                count++;
        }
        if (count != 0 && RussianRoulette_CountBettableDemons() && !Flag_Test(0xCA))
        {
            Flag_Set(0xCA);
            if ((Random_Byte() & 0xFF) < 8)
                return 2;
        }
        return 0;
    }
    if (script == gUnknown_08052210 && (Random_Byte() & 1))
        return 0;
    if (script == gUnknown_080522F8 && (Random_Byte() & 3))
        return 0;
    if (script == NULL)
        return 1;
    return ScriptVM_RunAlt(script);
}

// sub_080AF178 @ 0x080AF178
void sub_080AF178(u16 a, const void *script)
{
    u16 busy = sub_0813EB78();

    if (busy == 0)
    {
        u32 zero;

        gUnk_03003BB8 = busy;
        gUnk_03004530 = a;
        zero = busy;
        CpuSet(&zero, (void *)0x02036094, 0x05000008);
        gUnk_0203DB7A = busy;
        sub_080AF060(script);
        Field_SetState(0x19);
    }
}

// sub_080AF1D0 @ 0x080AF1D0
void sub_080AF1D0(u16 a, const void *script)
{
    gUnk_03003BB8 = 0;
    sub_080B6308(a, script);
}

// sub_080AF1E8 @ 0x080AF1E8
void sub_080AF1E8(u16 a, const void *script)
{
    gUnk_03003BB8 = 0;
    gUnk_03004530 = a;
    gUnk_0203DB7A = 0;
    sub_080AF060(script);
    Field_SetState(0x19);
}

// sub_080AF218 @ 0x080AF218
void sub_080AF218(u16 a, const void *script)
{
    gUnk_03003BB8 = 0;
    gUnk_03004530 = a;
    gUnk_0203DB7A = 1;
    sub_080AF060(script);
    Field_SetState(0x19);
}

// sub_080AF24C @ 0x080AF24C
void sub_080AF24C(u16 a, const void *script)
{
    gUnk_03003BB8 = 0;
    gUnk_03004530 = a;
    gUnk_0203DB7A = 2;
    sub_080AF060(script);
    Field_SetState(0x19);
}

// sub_080AF280 @ 0x080AF280
void sub_080AF280(void)
{
    u32 zero = 0;

    CpuSet(&zero, (void *)0x02036094, 0x05000008);
    gUnk_0203DB7A = 0;
    sub_080AF060(gUnk_0300453C);
    Field_SetState(0x19);
}

// sub_080AF2BC @ 0x080AF2BC
bool32 sub_080AF2BC(void)
{
    bool32 ret = FALSE;

    if (FieldMap_HasRecordRel(0, 0, 0x13) == 1 || FieldMap_HasRecordRel(0, 0, 0x1E) == 1)
        ret = TRUE;
    return ret;
}

// sub_080AF2E8 @ 0x080AF2E8
void sub_080AF2E8(void)
{
    Flag_Clear(0x101);
    Field_SetState(1);
}

// sub_080AF300 @ 0x080AF300
#ifdef NONMATCHING
void sub_080AF300(void)
{
    sub_080C3818(1);
    Music_Play(sub_080AD608(gUnk_03004614, gUnk_03004514));
    sub_080AE234();
    View_BuildCells(gFieldState.unk02, 0);
    if (Palette_IsBg13Black() == 1)
        sub_080AF2E8();
    else if (View_GetWall(0, 0, 0) == 1 && View_GetWall(1, 0, 0) == 1 && View_GetWall(3, 0, 0) == 1)
    {
        if (Flag_Test(0x101))
            sub_080AF2E8();
        else
        {
            Task_Create(gUnknown_0816499C, 0xFFFF);
            Field_SetState(0x1A);
        }
    }
    else if (View_GetWall(0, 0, 0) == 3)
    {
        if (sub_080AF2BC() == 1 && sub_080B78DC() == 0 && !Flag_Test(0x101))
        {
            Task_Create(gUnknown_0816499C, 0xFFFF);
            Field_SetState(0x1A);
        }
        else
            sub_080AF2E8();
    }
    else if (View_GetWall(0, 0, 0) == 2 && sub_080B78DC() == 0)
    {
        if (sub_080AF2BC() == 1 && !Flag_Test(0x101))
        {
            Task_Create(gUnknown_0816499C, 0xFFFF);
            Field_SetState(0x1A);
        }
        else
            sub_080AF2E8();
    }
    else
        sub_080AF2E8();
}
#else
NAKED
void sub_080AF300(void)
{
    asm_unified(
        ".L080AF300:\n"
        "    push {lr}\n"
        "    movs r0, #1\n"
        "    bl sub_080C3818\n"
        "    ldr r0, .L080AF338\n"
        "    ldrh r0, [r0]\n"
        "    ldr r1, .L080AF33C\n"
        "    ldrh r1, [r1]\n"
        "    bl sub_080AD608\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Music_Play\n"
        "    bl sub_080AE234\n"
        "    ldr r0, .L080AF340\n"
        "    ldrh r0, [r0, #2]\n"
        "    movs r1, #0\n"
        "    bl View_BuildCells\n"
        "    bl Palette_IsBg13Black\n"
        "    cmp r0, #1\n"
        "    bne .L080AF344\n"
        ".L080AF332:\n"
        "    bl sub_080AF2E8\n"
        "    b .L080AF3F8\n"
        ".L080AF338: .4byte 0x03004614 @ IWRAM+0x4614\n"
        ".L080AF33C: .4byte 0x03004514 @ IWRAM+0x4514\n"
        ".L080AF340: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080AF344:\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    bl View_GetWall\n"
        "    cmp r0, #1\n"
        "    bne .L080AF380\n"
        "    movs r0, #1\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    bl View_GetWall\n"
        "    cmp r0, #1\n"
        "    bne .L080AF380\n"
        "    movs r0, #3\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    bl View_GetWall\n"
        "    cmp r0, #1\n"
        "    bne .L080AF380\n"
        "    ldr r0, .L080AF37C\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    beq .L080AF3D8\n"
        "    b .L080AF332\n"
        "    .byte 0x00, 0x00\n"
        ".L080AF37C: .4byte 0x00000101\n"
        ".L080AF380:\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    bl View_GetWall\n"
        "    cmp r0, #3\n"
        "    bne .L080AF3B0\n"
        "    bl sub_080AF2BC\n"
        "    cmp r0, #1\n"
        "    bne .L080AF332\n"
        "    bl sub_080B78DC\n"
        "    cmp r0, #0\n"
        "    bne .L080AF332\n"
        "    ldr r0, .L080AF3AC\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    beq .L080AF3D8\n"
        "    b .L080AF332\n"
        "    .byte 0x00, 0x00\n"
        ".L080AF3AC: .4byte 0x00000101\n"
        ".L080AF3B0:\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    bl View_GetWall\n"
        "    cmp r0, #2\n"
        "    bne .L080AF3F4\n"
        "    bl sub_080B78DC\n"
        "    cmp r0, #0\n"
        "    bne .L080AF3F4\n"
        "    bl sub_080AF2BC\n"
        "    cmp r0, #1\n"
        "    bne .L080AF332\n"
        "    ldr r0, .L080AF3E8\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L080AF332\n"
        ".L080AF3D8:\n"
        "    ldr r0, .L080AF3EC\n"
        "    ldr r1, .L080AF3F0\n"
        "    bl Task_Create\n"
        "    movs r0, #0x1a\n"
        "    bl Field_SetState\n"
        "    b .L080AF3F8\n"
        ".L080AF3E8: .4byte 0x00000101\n"
        ".L080AF3EC: .4byte gUnknown_0816499C\n"
        ".L080AF3F0: .4byte 0x0000FFFF\n"
        ".L080AF3F4:\n"
        "    bl sub_080AF2E8\n"
        ".L080AF3F8:\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

// sub_080AF3FC @ 0x080AF3FC
void sub_080AF3FC(void)
{
    gUnk_0203DB6A = 0;
    if (gUnk_03003BB8 == 1)
    {
        if (sub_080E54D4() == 0)
        {
            sub_080C3818(1);
            if (sub_080B78A4() == 0)
                Field_SetState(0x1D);
            else
                Field_SetState(10);
            gFieldState.unk1E = 0;
        }
        else
        {
            Field_SetState(gUnk_03004530);
        }
    }
    else if (gUnk_03004530 == 0x19)
    {
        gUnk_03004530 = 1;
        sub_080AF300();
    }
    else
    {
        Field_SetState(gUnk_03004530);
        if (gUnk_03004530 == 0xC)
        {
            if (gUnk_0200AB04 & 0x8000)
            {
                sub_080B0820();
                gFieldState.unk1E++;
                gUnk_0300460C = 0;
            }
            else
            {
                sub_080AF300();
            }
        }
    }
}

/* Marks map square (x, y) as visited for the automap (1 bit per square, 128 per row). */
// Automap_SetVisitedRaw @ 0x080AF4B8
#ifdef NONMATCHING
void Automap_SetVisitedRaw(u16 x, u16 y)
{
    gGameState.visited[y][x >> 3] |= 1 << (x & 7);
}
#else
NAKED
void Automap_SetVisitedRaw(u16 x, u16 y)
{
    asm_unified(
        ".L080AF4B8:\n"
        "    push {r4, r5, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    movs r3, #1\n"
        "    movs r5, #7\n"
        "    lsrs r0, r0, #0x13\n"
        "    ldr r2, .L080AF4E4\n"
        "    lsrs r1, r1, #0xc\n"
        "    adds r0, r0, r1\n"
        "    ldr r1, .L080AF4E8\n"
        "    adds r2, r2, r1\n"
        "    adds r0, r0, r2\n"
        "    ands r4, r5\n"
        "    lsls r3, r4\n"
        "    ldrb r1, [r0]\n"
        "    orrs r3, r1\n"
        "    strb r3, [r0]\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080AF4E4: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080AF4E8: .4byte 0x00001188\n"
    );
}
#endif

/* Marks map square (x, y) of the current map (map-local coordinates) as visited. */
// Automap_SetVisited @ 0x080AF4EC
void Automap_SetVisited(u16 x, u16 y)
{
    struct MapHeader *h = DungeonMap_GetFloor(gUnk_03004614, gUnk_03004514);

    x += h->originX;
    y += h->originY;
    if (SubMap_IsOutsideExclusions(h, x, y))
        Automap_SetVisitedRaw(x, y);
}

// Automap_ClearVisitedRaw @ 0x080AF538
#ifdef NONMATCHING
void Automap_ClearVisitedRaw(u16 x, u16 y)
{
    u8 bit = 1;
    u32 mask = 7;

    gGameState.visited[y][x >> 3] &= ~(bit << (x & mask));
}
#else
NAKED
void Automap_ClearVisitedRaw(u16 x, u16 y)
{
    asm_unified(
        ".L080AF538:\n"
        "    push {r4, r5, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    movs r4, #1\n"
        "    movs r5, #7\n"
        "    lsrs r0, r0, #0x13\n"
        "    ldr r2, .L080AF564\n"
        "    lsrs r1, r1, #0xc\n"
        "    adds r0, r0, r1\n"
        "    ldr r1, .L080AF568\n"
        "    adds r2, r2, r1\n"
        "    adds r0, r0, r2\n"
        "    ands r3, r5\n"
        "    lsls r4, r3\n"
        "    ldrb r1, [r0]\n"
        "    bics r1, r4\n"
        "    strb r1, [r0]\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080AF564: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080AF568: .4byte 0x00001188\n"
    );
}
#endif

// Automap_ClearVisited @ 0x080AF56C
void Automap_ClearVisited(u16 x, u16 y)
{
    struct MapHeader *h = DungeonMap_GetFloor(gUnk_03004614, gUnk_03004514);

    x += h->originX;
    y += h->originY;
    if (SubMap_IsOutsideExclusions(h, x, y))
        Automap_ClearVisitedRaw(x, y);
}

/* Marks the square in front of (x, y) when facing dir as visited. */
// Automap_SetVisitedAhead @ 0x080AF5B8
void Automap_SetVisitedAhead(u16 x, u16 y, u16 dir)
{
    switch (dir)
    {
    case 0:
        y++;
        break;
    case 1:
        x--;
        break;
    case 2:
        y--;
        break;
    case 3:
        x++;
        break;
    }
    if ((s16)x >= 0 && (s16)y >= 0 && x < gFieldState.unk1A && y < gFieldState.unk1C)
        Automap_SetVisited(x, y);
}

// Automap_IsVisited @ 0x080AF620
#ifdef NONMATCHING
u16 Automap_IsVisited(u16 x, u16 y)
{
    struct MapHeader *h = DungeonMap_GetFloor(gUnk_03004614, gUnk_03004514);

    x += h->originX;
    y += h->originY;
    if (SubMap_IsOutsideExclusions(h, x, y) == 0)
        return 0;
    return gGameState.visited[y][x >> 3] & (1 << (x & 7));
}
#else
NAKED
u16 Automap_IsVisited(u16 x, u16 y)
{
    asm_unified(
        ".L080AF620:\n"
        "    push {r4, r5, r6, lr}\n"
        "    adds r4, r0, #0\n"
        "    adds r5, r1, #0\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    lsls r5, r5, #0x10\n"
        "    lsrs r5, r5, #0x10\n"
        "    ldr r0, .L080AF674\n"
        "    ldrh r0, [r0]\n"
        "    ldr r1, .L080AF678\n"
        "    ldrh r1, [r1]\n"
        "    bl DungeonMap_GetFloor\n"
        "    ldrh r1, [r0, #8]\n"
        "    adds r4, r4, r1\n"
        "    lsls r6, r4, #0x10\n"
        "    lsrs r4, r6, #0x10\n"
        "    ldrh r1, [r0, #0xa]\n"
        "    adds r5, r5, r1\n"
        "    lsls r5, r5, #0x10\n"
        "    lsrs r5, r5, #0x10\n"
        "    adds r1, r4, #0\n"
        "    adds r2, r5, #0\n"
        "    bl SubMap_IsOutsideExclusions\n"
        "    cmp r0, #0\n"
        "    beq .L080AF684\n"
        "    movs r3, #7\n"
        "    lsrs r0, r6, #0x13\n"
        "    ldr r1, .L080AF67C\n"
        "    lsls r2, r5, #4\n"
        "    adds r0, r0, r2\n"
        "    ldr r2, .L080AF680\n"
        "    adds r1, r1, r2\n"
        "    adds r0, r0, r1\n"
        "    ldrb r0, [r0]\n"
        "    ands r3, r4\n"
        "    movs r1, #1\n"
        "    lsls r1, r3\n"
        "    ands r0, r1\n"
        "    b .L080AF686\n"
        "    .byte 0x00, 0x00\n"
        ".L080AF674: .4byte 0x03004614 @ IWRAM+0x4614\n"
        ".L080AF678: .4byte 0x03004514 @ IWRAM+0x4514\n"
        ".L080AF67C: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080AF680: .4byte 0x00001188\n"
        ".L080AF684:\n"
        "    movs r0, #0\n"
        ".L080AF686:\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

// Automap_IsVisitedUnchecked @ 0x080AF68C
#ifdef NONMATCHING
u16 Automap_IsVisitedUnchecked(u16 x, u16 y)
{
    u8 bit = 1;
    struct MapHeader *h = DungeonMap_GetFloor(gUnk_03004614, gUnk_03004514);
    u32 mask;

    x += h->originX;
    y += h->originY;
    mask = 7;
    return gGameState.visited[y][x >> 3] & (bit << (x & mask));
}
#else
NAKED
u16 Automap_IsVisitedUnchecked(u16 x, u16 y)
{
    asm_unified(
        ".L080AF68C:\n"
        "    push {r4, r5, r6, lr}\n"
        "    adds r4, r0, #0\n"
        "    adds r5, r1, #0\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    lsls r5, r5, #0x10\n"
        "    lsrs r5, r5, #0x10\n"
        "    movs r6, #1\n"
        "    ldr r0, .L080AF6D4\n"
        "    ldrh r0, [r0]\n"
        "    ldr r1, .L080AF6D8\n"
        "    ldrh r1, [r1]\n"
        "    bl DungeonMap_GetFloor\n"
        "    ldrh r1, [r0, #8]\n"
        "    adds r4, r4, r1\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r1, r4, #0x10\n"
        "    ldrh r0, [r0, #0xa]\n"
        "    adds r5, r5, r0\n"
        "    lsls r5, r5, #0x10\n"
        "    movs r2, #7\n"
        "    lsrs r4, r4, #0x13\n"
        "    ldr r0, .L080AF6DC\n"
        "    lsrs r5, r5, #0xc\n"
        "    adds r4, r4, r5\n"
        "    ldr r3, .L080AF6E0\n"
        "    adds r0, r0, r3\n"
        "    adds r4, r4, r0\n"
        "    ldrb r0, [r4]\n"
        "    ands r1, r2\n"
        "    lsls r6, r1\n"
        "    ands r0, r6\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        ".L080AF6D4: .4byte 0x03004614 @ IWRAM+0x4614\n"
        ".L080AF6D8: .4byte 0x03004514 @ IWRAM+0x4514\n"
        ".L080AF6DC: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080AF6E0: .4byte 0x00001188\n"
    );
}
#endif

// sub_080AF6E4 @ 0x080AF6E4
void sub_080AF6E4(u32 a, const u32 *b)
{
    gUnk_03004538 = a;
    gUnk_03004000 = b;
}

// sub_080AF6F8 @ 0x080AF6F8
void sub_080AF6F8(u32 a, const u32 *b, u32 c)
{
    const void *script = (const void *)b[1];

    sub_080AF6E4(a, b);
    gFieldState.unk1E = 0;
    if (c == 0)
        sub_080AF178(0xC, script);
    else
        sub_080AF1D0(0xC, script);
}

/* Whether a door-like event can be passed: 2 when the event blocks the facing direction
   (ev[4] nibbles, one per direction), 0 when the entry's side mask blocks the step just
   taken, else 1. */
// sub_080AF72C @ 0x080AF72C
#ifdef NONMATCHING
s32 sub_080AF72C(const u16 *ev)
{
    const u16 *ent = (const u16 *)FieldMap_FindRecord(FieldMap_CellRecordsRel(0, 0), 0x24);
    u16 x, y, prevX, prevY;
    u16 sides;

    if (ent == NULL)
        return 1;
    x = gFieldState.unk12;
    y = gFieldState.unk14;
    prevX = gFieldState.unk16;
    prevY = gFieldState.unk18;
    sides = ev[4];
    if (((sides & 0xF000) && gFieldState.unk02 == 0)
     || ((sides & 0x0F00) && gFieldState.unk02 == 1)
     || ((sides & 0x00F0) && gFieldState.unk02 == 2)
     || ((sides & 0x000F) && gFieldState.unk02 == 3))
        return 2;
    if (x == prevX && y < prevY)
    {
        if (ent[1] & 0x1000)
            return 0;
    }
    else if (x == prevX && y > prevY)
    {
        if (ent[1] & 0x10)
            return 0;
    }
    else if (x < prevX && y == prevY)
    {
        if (ent[1] & 1)
            return 0;
    }
    else if (x > prevX && y == prevY)
    {
        if (ent[1] & 0x100)
            return 0;
    }
    return 1;
}
#else
NAKED
s32 sub_080AF72C(const u16 *ev)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    mov r8, r0\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    bl FieldMap_CellRecordsRel\n"
        "    movs r1, #0x24\n"
        "    bl FieldMap_FindRecord\n"
        "    adds r3, r0, #0\n"
        "    cmp r3, #0\n"
        "    beq .L080AF7DC\n"
        "    ldr r1, .L080AF798\n"
        "    ldrh r7, [r1, #0x12]\n"
        "    ldrh r5, [r1, #0x14]\n"
        "    ldrh r6, [r1, #0x16]\n"
        "    ldrh r4, [r1, #0x18]\n"
        "    mov r0, r8\n"
        "    ldrh r2, [r0, #8]\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #8\n"
        "    ands r0, r2\n"
        "    cmp r0, #0\n"
        "    beq .L080AF766\n"
        "    ldrh r0, [r1, #2]\n"
        "    cmp r0, #0\n"
        "    beq .L080AF792\n"
        ".L080AF766:\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #4\n"
        "    ands r0, r2\n"
        "    cmp r0, #0\n"
        "    beq .L080AF776\n"
        "    ldrh r0, [r1, #2]\n"
        "    cmp r0, #1\n"
        "    beq .L080AF792\n"
        ".L080AF776:\n"
        "    movs r0, #0xf0\n"
        "    ands r0, r2\n"
        "    cmp r0, #0\n"
        "    beq .L080AF784\n"
        "    ldrh r0, [r1, #2]\n"
        "    cmp r0, #2\n"
        "    beq .L080AF792\n"
        ".L080AF784:\n"
        "    movs r0, #0xf\n"
        "    ands r0, r2\n"
        "    cmp r0, #0\n"
        "    beq .L080AF79C\n"
        "    ldrh r0, [r1, #2]\n"
        "    cmp r0, #3\n"
        "    bne .L080AF79C\n"
        ".L080AF792:\n"
        "    movs r0, #2\n"
        "    b .L080AF7DE\n"
        "    .byte 0x00, 0x00\n"
        ".L080AF798: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080AF79C:\n"
        "    cmp r7, r6\n"
        "    bne .L080AF7B6\n"
        "    cmp r5, r4\n"
        "    bhs .L080AF7AC\n"
        "    ldrh r1, [r3, #2]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #5\n"
        "    b .L080AF7D2\n"
        ".L080AF7AC:\n"
        "    cmp r5, r4\n"
        "    bls .L080AF7B6\n"
        "    ldrh r1, [r3, #2]\n"
        "    movs r0, #0x10\n"
        "    b .L080AF7D2\n"
        ".L080AF7B6:\n"
        "    cmp r7, r6\n"
        "    bhs .L080AF7C4\n"
        "    cmp r5, r4\n"
        "    bne .L080AF7C4\n"
        "    ldrh r1, [r3, #2]\n"
        "    movs r0, #1\n"
        "    b .L080AF7D2\n"
        ".L080AF7C4:\n"
        "    cmp r7, r6\n"
        "    bls .L080AF7DC\n"
        "    cmp r5, r4\n"
        "    bne .L080AF7DC\n"
        "    ldrh r1, [r3, #2]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        ".L080AF7D2:\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080AF7DC\n"
        "    movs r0, #0\n"
        "    b .L080AF7DE\n"
        ".L080AF7DC:\n"
        "    movs r0, #1\n"
        ".L080AF7DE:\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

// sub_080AF7E8 @ 0x080AF7E8
void sub_080AF7E8(u32 a, const u32 *b, u32 c)
{
    u16 flag;
    const u32 *ev = FieldEvent_FindAt(gFieldState.unk12, gFieldState.unk14, gFieldState.unk02, &flag);

    sub_080AF6E4(a, b);
    gFieldState.unk1E = 0;
    if (c == 0)
        sub_080AF178(0xC, (const void *)ev[1]);
    else
        sub_080AF1D0(0xC, (const void *)ev[1]);
    if (flag != 0xFFFF)
        sub_080C24B8(flag);
    gFieldState.unk3E = 1;
}

/* Runs one of five fixed scripts for kind 0x30..0x34. Other kinds pass an
   uninitialised pointer (original bug). */
// sub_080AF85C @ 0x080AF85C
const void *sub_080AF85C(u32 kind, u32 arg)
{
    const void *script;

    switch (kind)
    {
    case 0x30:
        script = gUnknown_08073AD0;
        break;
    case 0x31:
        script = gUnknown_08073AB2;
        break;
    case 0x32:
        script = gUnknown_08073ABC;
        break;
    case 0x33:
        script = gUnknown_08073AC6;
        break;
    case 0x34:
        script = gUnknown_08073AA8;
        break;
    }
    sub_080AF6E4(arg, (const u32 *)arg);
    gFieldState.unk1E = 0;
    sub_080AF178(0xC, script);
    return script;
}
