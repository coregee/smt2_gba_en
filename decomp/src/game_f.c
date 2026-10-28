/* Map cell attributes. Each map has a list of cells: {x, y, record..., -2}, ended by -1.
   A record starts with a word whose low half is its type; gUnknown_0816222C[type] is its
   length in words. */

#include "global.h"
#include "game.h"

/* NONMATCHING: the cell pointer and the loaded word swap r2/r3. */
// FieldMap_CellRecordsRel @ 0x080B2EFC
#ifdef NONMATCHING
/* Attribute records of the cell fwd squares ahead and side squares to the right of the player. */
u32 *FieldMap_CellRecordsRel(u16 fwd, u16 side)
{
    u32 *p;
    u16 x, y;

    p = sub_080C8B10(gUnk_03004614, gUnk_03004514)->unk94;
    x = gFieldState.unk12;
    y = gFieldState.unk14;

    switch (gFieldState.unk02)
    {
    case 0:
        x += fwd;
        y += side;
        break;
    case 1:
        x -= side;
        y += fwd;
        break;
    case 2:
        x -= fwd;
        y -= side;
        break;
    case 3:
        x += side;
        y -= fwd;
        break;
    }
    if ((s16)x < 0 || (s16)y < 0 || x >= gFieldState.unk1A || y >= gFieldState.unk1C)
        return NULL;
next:
    if (*p == -1)
        return NULL;
    if (p[0] == x && p[1] == y)
        return p + 2;
    p += 2;
    do
        p += gUnknown_0816222C[*p & 0xFFFF];
    while (*p != -2);
    p++;
    goto next;
}
#else
NAKED
u32 *FieldMap_CellRecordsRel(u16 fwd, u16 side)
{
    asm_unified(
        ".L080B2EFC:\n"
        "    push {r4, r5, r6, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r5, r1, #0x10\n"
        "    ldr r0, .L080B2F2C\n"
        "    ldrh r0, [r0]\n"
        "    ldr r1, .L080B2F30\n"
        "    ldrh r1, [r1]\n"
        "    bl sub_080C8B10\n"
        "    adds r0, #0x94\n"
        "    ldr r3, [r0]\n"
        "    ldr r0, .L080B2F34\n"
        "    ldrh r4, [r0, #0x12]\n"
        "    ldrh r1, [r0, #0x14]\n"
        "    ldrh r0, [r0, #2]\n"
        "    cmp r0, #1\n"
        "    beq .L080B2F4C\n"
        "    cmp r0, #1\n"
        "    bgt .L080B2F38\n"
        "    cmp r0, #0\n"
        "    beq .L080B2F42\n"
        "    b .L080B2F6C\n"
        ".L080B2F2C: .4byte 0x03004614 @ IWRAM+0x4614\n"
        ".L080B2F30: .4byte 0x03004514 @ IWRAM+0x4514\n"
        ".L080B2F34: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B2F38:\n"
        "    cmp r0, #2\n"
        "    beq .L080B2F56\n"
        "    cmp r0, #3\n"
        "    beq .L080B2F60\n"
        "    b .L080B2F6C\n"
        ".L080B2F42:\n"
        "    adds r0, r4, r6\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    adds r0, r1, r5\n"
        "    b .L080B2F68\n"
        ".L080B2F4C:\n"
        "    subs r0, r4, r5\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    adds r0, r1, r6\n"
        "    b .L080B2F68\n"
        ".L080B2F56:\n"
        "    subs r0, r4, r6\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    subs r0, r1, r5\n"
        "    b .L080B2F68\n"
        ".L080B2F60:\n"
        "    adds r0, r4, r5\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    subs r0, r1, r6\n"
        ".L080B2F68:\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        ".L080B2F6C:\n"
        "    lsls r0, r4, #0x10\n"
        "    cmp r0, #0\n"
        "    blt .L080B2F90\n"
        "    lsls r0, r1, #0x10\n"
        "    cmp r0, #0\n"
        "    blt .L080B2F90\n"
        "    ldr r0, .L080B2F94\n"
        "    ldrh r2, [r0, #0x1a]\n"
        "    cmp r4, r2\n"
        "    bhs .L080B2F90\n"
        "    ldrh r0, [r0, #0x1c]\n"
        "    cmp r1, r0\n"
        "    bhs .L080B2F90\n"
        ".L080B2F86:\n"
        "    ldr r2, [r3]\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r2, r0\n"
        "    bne .L080B2F98\n"
        ".L080B2F90:\n"
        "    movs r0, #0\n"
        "    b .L080B2FD4\n"
        ".L080B2F94: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B2F98:\n"
        "    cmp r2, r4\n"
        "    bne .L080B2FA8\n"
        "    ldr r0, [r3, #4]\n"
        "    cmp r0, r1\n"
        "    bne .L080B2FA8\n"
        "    adds r0, r3, #0\n"
        "    adds r0, #8\n"
        "    b .L080B2FD4\n"
        ".L080B2FA8:\n"
        "    adds r3, #8\n"
        "    ldr r6, .L080B2FCC\n"
        "    ldr r5, .L080B2FD0\n"
        "    movs r2, #2\n"
        "    rsbs r2, r2, #0\n"
        ".L080B2FB2:\n"
        "    ldr r0, [r3]\n"
        "    ands r0, r5\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r0, r6\n"
        "    ldr r0, [r0]\n"
        "    lsls r0, r0, #2\n"
        "    adds r3, r3, r0\n"
        "    ldr r0, [r3]\n"
        "    cmp r0, r2\n"
        "    bne .L080B2FB2\n"
        "    adds r3, #4\n"
        "    b .L080B2F86\n"
        "    .byte 0x00, 0x00\n"
        ".L080B2FCC: .4byte gUnknown_0816222C\n"
        ".L080B2FD0: .4byte 0x0000FFFF\n"
        ".L080B2FD4:\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
    );
}

#endif

// FieldMap_CellRecordsOffset @ 0x080B2FDC
/* FieldMap_CellRecordsRel as if facing direction 0. */
u32 *FieldMap_CellRecordsOffset(u16 dx, u16 dy)
{
    u16 dir = gFieldState.unk02;
    u32 *r;

    gFieldState.unk02 = 0;
    r = FieldMap_CellRecordsRel(dx, dy);
    gFieldState.unk02 = dir;
    return r;
}

// FieldMap_CellRecordsAt @ 0x080B3000
/* Attribute records of cell (x, y). */
u32 *FieldMap_CellRecordsAt(u32 x, u32 y)
{
    u16 dir = gFieldState.unk02;
    u16 oldX = gFieldState.unk12;
    u16 oldY = gFieldState.unk14;
    u32 *r;

    gFieldState.unk02 = 0;
    gFieldState.unk12 = x;
    gFieldState.unk14 = y;
    r = FieldMap_CellRecordsRel(0, 0);
    gFieldState.unk02 = dir;
    gFieldState.unk12 = oldX;
    gFieldState.unk14 = oldY;
    return r;
}

/* NONMATCHING: the record pointer and the loaded word swap r2/r3. */
// FieldMap_FindRecord @ 0x080B3038
#ifdef NONMATCHING
/* First record of the given type in a cell's record list, or NULL. */
u32 *FieldMap_FindRecord(u32 *p, u16 type)
{
    u32 t;

    if (p == NULL)
        return NULL;
next:
    if (*p == -2)
        return NULL;
    t = *p & 0xFFFF;
    if (t == type)
        return p;
    p += gUnknown_0816222C[t];
    goto next;
}
#else
NAKED
u32 *FieldMap_FindRecord(u32 *p, u16 type)
{
    asm_unified(
        ".L080B3038:\n"
        "    push {r4, lr}\n"
        "    adds r3, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r4, r1, #0x10\n"
        "    cmp r3, #0\n"
        "    beq .L080B304E\n"
        ".L080B3044:\n"
        "    ldr r2, [r3]\n"
        "    movs r0, #2\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r2, r0\n"
        "    bne .L080B3052\n"
        ".L080B304E:\n"
        "    movs r0, #0\n"
        "    b .L080B3072\n"
        ".L080B3052:\n"
        "    ldr r1, .L080B3068\n"
        "    ands r1, r2\n"
        "    cmp r1, r4\n"
        "    beq .L080B3070\n"
        "    ldr r0, .L080B306C\n"
        "    lsls r1, r1, #2\n"
        "    adds r1, r1, r0\n"
        "    ldr r0, [r1]\n"
        "    lsls r0, r0, #2\n"
        "    adds r3, r3, r0\n"
        "    b .L080B3044\n"
        ".L080B3068: .4byte 0x0000FFFF\n"
        ".L080B306C: .4byte gUnknown_0816222C\n"
        ".L080B3070:\n"
        "    adds r0, r3, #0\n"
        ".L080B3072:\n"
        "    pop {r4}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}

#endif

// FieldMap_HasRecordRel @ 0x080B3078
/* TRUE when the cell (fwd, side) relative to the player has a record of the given type. */
u32 FieldMap_HasRecordRel(u16 fwd, u16 side, u16 type)
{
    u32 r = (u32)FieldMap_FindRecord(FieldMap_CellRecordsRel(fwd, side), type);

    if (r != 0)
        r = 1;
    return r;
}

/* NONMATCHING: the original reuses the gGameState base for both saved-position bytes; register allocation then differs. */
// sub_080B30A0 @ 0x080B30A0
#ifdef NONMATCHING
/* Finds the sub-map containing the saved position and places the player there. */
void sub_080B30A0(void)
{
    u16 count = sub_080C8B3C(gUnk_03004614);
    u32 x = gGameState.unk18C2;
    u32 y = gGameState.unk18C3 & 0x3F;
    struct MapHeader *map = sub_080C8B10(gUnk_03004614, 0);
    u16 i;

    for (i = 0; i < count; i++, map++)
    {
        if (map->x0 <= x && map->y0 <= y && map->x1 >= x && map->y1 >= y && sub_080B7944(map, x, y) == 1)
        {
            gFieldState.unk12 = x - map->x0;
            gFieldState.unk14 = y - map->y0;
            gFieldState.unk02 = gFieldState.unk04 = gGameState.unk18C3 >> 6;
            Field_SavePrevPosition();
            gPaletteTarget[0] = *gUnk_03004630;
            Palette_CopyWithEffect(3, gUnk_03004630, &gPaletteTarget[0xE0], 0x40, 0x20);
            Palette_CopyWithEffect(3, gUnk_03004510, &gPaletteTarget[0xD0], 0x20, 0x20);
            return;
        }
        if (count - 1 == gUnk_03004514)
            return;
        gUnk_03004514++;
        sub_080ADFEC(gUnk_03004544);
        sub_080AE234();
    }
}
#else
NAKED
void sub_080B30A0(void)
{
    asm_unified(
        ".L080B30A0:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #4\n"
        "    ldr r4, .L080B3160\n"
        "    ldrh r0, [r4]\n"
        "    bl sub_080C8B3C\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sb, r0\n"
        "    ldr r0, .L080B3164\n"
        "    ldr r2, .L080B3168\n"
        "    adds r1, r0, r2\n"
        "    ldrb r5, [r1]\n"
        "    ldr r1, .L080B316C\n"
        "    adds r0, r0, r1\n"
        "    ldrb r0, [r0]\n"
        "    movs r6, #0x3f\n"
        "    ands r6, r0\n"
        "    ldrh r0, [r4]\n"
        "    movs r1, #0\n"
        "    bl sub_080C8B10\n"
        "    adds r4, r0, #0\n"
        "    movs r7, #0\n"
        "    cmp r7, sb\n"
        "    bhs .L080B31AC\n"
        "    ldr r2, .L080B3170\n"
        "    mov r8, r2\n"
        "    ldr r0, .L080B3174\n"
        "    mov sl, r0\n"
        ".L080B30E4:\n"
        "    ldrh r0, [r4, #8]\n"
        "    cmp r0, r5\n"
        "    bhi .L080B3180\n"
        "    ldrh r0, [r4, #0xa]\n"
        "    cmp r0, r6\n"
        "    bhi .L080B3180\n"
        "    ldrh r0, [r4, #0xc]\n"
        "    cmp r0, r5\n"
        "    blo .L080B3180\n"
        "    ldrh r0, [r4, #0xe]\n"
        "    cmp r0, r6\n"
        "    blo .L080B3180\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r5, #0\n"
        "    adds r2, r6, #0\n"
        "    bl sub_080B7944\n"
        "    cmp r0, #1\n"
        "    bne .L080B3180\n"
        "    ldrh r0, [r4, #8]\n"
        "    subs r0, r5, r0\n"
        "    mov r1, r8\n"
        "    strh r0, [r1, #0x12]\n"
        "    ldrh r0, [r4, #0xa]\n"
        "    subs r0, r6, r0\n"
        "    strh r0, [r1, #0x14]\n"
        "    ldr r0, .L080B3164\n"
        "    ldr r2, .L080B316C\n"
        "    adds r0, r0, r2\n"
        "    ldrb r0, [r0]\n"
        "    lsrs r0, r0, #6\n"
        "    strh r0, [r1, #4]\n"
        "    strh r0, [r1, #2]\n"
        "    bl Field_SavePrevPosition\n"
        "    ldr r0, .L080B3178\n"
        "    ldr r1, [r0]\n"
        "    ldrh r0, [r1]\n"
        "    mov r2, sl\n"
        "    strh r0, [r2]\n"
        "    movs r0, #0x20\n"
        "    str r0, [sp]\n"
        "    movs r0, #3\n"
        "    movs r2, #0xe0\n"
        "    lsls r2, r2, #1\n"
        "    add r2, sl\n"
        "    movs r3, #0x40\n"
        "    bl Palette_CopyWithEffect\n"
        "    ldr r0, .L080B317C\n"
        "    ldr r1, [r0]\n"
        "    movs r2, #0x20\n"
        "    str r2, [sp]\n"
        "    movs r0, #3\n"
        "    movs r2, #0xd0\n"
        "    lsls r2, r2, #1\n"
        "    add r2, sl\n"
        "    movs r3, #0x20\n"
        "    bl Palette_CopyWithEffect\n"
        "    b .L080B31AC\n"
        "    .byte 0x00, 0x00\n"
        ".L080B3160: .4byte 0x03004614 @ IWRAM+0x4614\n"
        ".L080B3164: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080B3168: .4byte 0x000018C2\n"
        ".L080B316C: .4byte 0x000018C3\n"
        ".L080B3170: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B3174: .4byte 0x030029B0 @ IWRAM+0x29B0\n"
        ".L080B3178: .4byte 0x03004630 @ IWRAM+0x4630\n"
        ".L080B317C: .4byte 0x03004510 @ IWRAM+0x4510\n"
        ".L080B3180:\n"
        "    mov r0, sb\n"
        "    subs r0, #1\n"
        "    ldr r2, .L080B31BC\n"
        "    ldr r1, [r2]\n"
        "    cmp r0, r1\n"
        "    beq .L080B31AC\n"
        "    adds r0, r1, #1\n"
        "    str r0, [r2]\n"
        "    ldr r0, .L080B31C0\n"
        "    ldrh r0, [r0]\n"
        "    bl sub_080ADFEC\n"
        "    bl sub_080AE234\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    movs r0, #0x9a\n"
        "    lsls r0, r0, #2\n"
        "    adds r4, r4, r0\n"
        "    cmp r7, sb\n"
        "    blo .L080B30E4\n"
        ".L080B31AC:\n"
        "    add sp, #4\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080B31BC: .4byte 0x03004514 @ IWRAM+0x4514\n"
        ".L080B31C0: .4byte 0x03004544 @ IWRAM+0x4544\n"
    );
}

#endif


/* NONMATCHING: the zero constant and the wrapped flag swap between sl and a stack slot, and the y loop is entered through its bottom test. */
// sub_080B31C4 @ 0x080B31C4
#ifdef NONMATCHING
/* Searches the maps for a cell with a record of the given type (and value) and moves the
   player there; returns 0 when the type has no search rule. */
u32 sub_080B31C4(u32 unused, u16 type, u16 value)
{
    u32 wrapped = 0;
    u16 x, y;
    u32 *rec;

    for (;;)
    {
        gFieldState.unk12 = 0;
        gFieldState.unk14 = 0;
        for (y = 0; y < gFieldState.unk1C; y++)
        {
            for (x = 0; x < gFieldState.unk1A; x++)
            {
                rec = FieldMap_FindRecord(FieldMap_CellRecordsOffset(x, y), type);
                if (rec == NULL)
                    continue;
                if (type == 1)
                {
                    if (((u16 *)rec)[2] != value)
                        continue;
                }
                else if (type == 2)
                {
                    if (((u16 *)rec)[2] != value)
                        continue;
                }
                else if (type == 0x1B)
                {
                    if (((u16 *)rec)[3] != value)
                        continue;
                }
                else if (type == 0x1C)
                {
                    if (((u16 *)rec)[3] != value)
                        continue;
                }
                else if (type == 3)
                {
                    if (((u16 *)rec)[2] != value)
                        continue;
                }
                else if (type == 10 && ((u16 *)rec)[1] != value)
                {
                    rec = NULL;
                }
                if (rec != NULL)
                    goto found;
            }
        }
        if (type == 1)
        {
            gUnk_03004514--;
        }
        else if (type == 2 || (u16)(type - 0x1B) <= 1)
        {
            gUnk_03004514++;
        }
        else if (type == 3)
        {
            if (gUnk_03004514 > gUnk_03004634)
                gUnk_03004514++;
            else
                gUnk_03004514--;
        }
        else if (type == 10)
        {
            if (wrapped == 0)
            {
                gUnk_03004514 = wrapped;
                wrapped = 1;
            }
            else
            {
                gUnk_03004514++;
                if (sub_080C8B3C(gUnk_03004614) == gUnk_03004514)
                {
                    if (gUnk_03004614 == 0x4F)
                    {
                        gUnk_03004614 = 0;
                        gUnk_03004514 = 0;
                    }
                    else
                    {
                        gUnk_03004614++;
                        gUnk_03004514 = 0;
                    }
                }
            }
        }
        else
        {
            return 0;
        }
        sub_080AE234();
    }
found:
    gFieldState.unk12 += x;
    gFieldState.unk14 += y;
    Field_SavePrevPosition();
    gGameState.unkA38 = 0;
    return 1;
}
#else
NAKED
u32 sub_080B31C4(u32 unused, u16 type, u16 value)
{
    asm_unified(
        ".L080B31C4:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #8\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r4, r1, #0x10\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r7, r2, #0x10\n"
        "    movs r0, #0\n"
        "    str r0, [sp]\n"
        "    ldr r1, .L080B322C\n"
        "    mov r8, r1\n"
        "    mov sl, r0\n"
        "    ldr r0, .L080B3230\n"
        "    mov sb, r0\n"
        ".L080B31E6:\n"
        "    mov r0, sl\n"
        "    mov r1, r8\n"
        "    strh r0, [r1, #0x12]\n"
        "    strh r0, [r1, #0x14]\n"
        "    movs r6, #0\n"
        "    ldr r2, .L080B322C\n"
        "    ldrh r1, [r1, #0x1c]\n"
        "    cmp r6, r1\n"
        "    bhs .L080B3272\n"
        ".L080B31F8:\n"
        "    movs r5, #0\n"
        "    ldrh r0, [r2, #0x1a]\n"
        "    cmp r5, r0\n"
        "    bhs .L080B3266\n"
        "    ldr r2, .L080B322C\n"
        ".L080B3202:\n"
        "    adds r0, r5, #0\n"
        "    adds r1, r6, #0\n"
        "    str r2, [sp, #4]\n"
        "    bl FieldMap_CellRecordsOffset\n"
        "    adds r1, r4, #0\n"
        "    bl FieldMap_FindRecord\n"
        "    adds r1, r0, #0\n"
        "    ldr r2, [sp, #4]\n"
        "    cmp r1, #0\n"
        "    beq .L080B3258\n"
        "    cmp r4, #1\n"
        "    beq .L080B3240\n"
        "    cmp r4, #2\n"
        "    beq .L080B3240\n"
        "    cmp r4, #0x1b\n"
        "    bne .L080B3234\n"
        "    ldrh r0, [r1, #6]\n"
        "    b .L080B3242\n"
        "    .byte 0x00, 0x00\n"
        ".L080B322C: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B3230: .4byte 0x03004514 @ IWRAM+0x4514\n"
        ".L080B3234:\n"
        "    cmp r4, #0x1c\n"
        "    bne .L080B323C\n"
        "    ldrh r0, [r1, #6]\n"
        "    b .L080B3242\n"
        ".L080B323C:\n"
        "    cmp r4, #3\n"
        "    bne .L080B3248\n"
        ".L080B3240:\n"
        "    ldrh r0, [r1, #4]\n"
        ".L080B3242:\n"
        "    cmp r0, r7\n"
        "    beq .L080B3254\n"
        "    b .L080B3258\n"
        ".L080B3248:\n"
        "    cmp r4, #0xa\n"
        "    bne .L080B3254\n"
        "    ldrh r0, [r1, #2]\n"
        "    cmp r0, r7\n"
        "    beq .L080B3254\n"
        "    movs r1, #0\n"
        ".L080B3254:\n"
        "    cmp r1, #0\n"
        "    bne .L080B330A\n"
        ".L080B3258:\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    mov r1, r8\n"
        "    ldrh r1, [r1, #0x1a]\n"
        "    cmp r5, r1\n"
        "    blo .L080B3202\n"
        ".L080B3266:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldrh r0, [r2, #0x1c]\n"
        "    cmp r6, r0\n"
        "    blo .L080B31F8\n"
        ".L080B3272:\n"
        "    cmp r4, #1\n"
        "    bne .L080B327E\n"
        "    mov r1, sb\n"
        "    ldr r0, [r1]\n"
        "    subs r0, #1\n"
        "    b .L080B3294\n"
        ".L080B327E:\n"
        "    cmp r4, #2\n"
        "    beq .L080B328E\n"
        "    adds r0, r4, #0\n"
        "    subs r0, #0x1b\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bhi .L080B329C\n"
        ".L080B328E:\n"
        "    mov r1, sb\n"
        "    ldr r0, [r1]\n"
        "    adds r0, #1\n"
        ".L080B3294:\n"
        "    str r0, [r1]\n"
        ".L080B3296:\n"
        "    bl sub_080AE234\n"
        "    b .L080B31E6\n"
        ".L080B329C:\n"
        "    cmp r4, #3\n"
        "    bne .L080B32BE\n"
        "    ldr r2, .L080B32B0\n"
        "    ldr r0, .L080B32B4\n"
        "    ldr r1, [r2]\n"
        "    ldrh r0, [r0]\n"
        "    cmp r1, r0\n"
        "    bls .L080B32B8\n"
        "    adds r0, r1, #1\n"
        "    b .L080B32BA\n"
        ".L080B32B0: .4byte 0x03004514 @ IWRAM+0x4514\n"
        ".L080B32B4: .4byte 0x03004634 @ IWRAM+0x4634\n"
        ".L080B32B8:\n"
        "    subs r0, r1, #1\n"
        ".L080B32BA:\n"
        "    str r0, [r2]\n"
        "    b .L080B3296\n"
        ".L080B32BE:\n"
        "    cmp r4, #0xa\n"
        "    bne .L080B3334\n"
        "    ldr r0, [sp]\n"
        "    cmp r0, #0\n"
        "    bne .L080B32D2\n"
        "    mov r1, sb\n"
        "    str r0, [r1]\n"
        "    movs r0, #1\n"
        "    str r0, [sp]\n"
        "    b .L080B3296\n"
        ".L080B32D2:\n"
        "    ldr r6, .L080B32F8\n"
        "    ldr r0, [r6]\n"
        "    adds r0, #1\n"
        "    str r0, [r6]\n"
        "    ldr r5, .L080B32FC\n"
        "    ldrh r0, [r5]\n"
        "    bl sub_080C8B3C\n"
        "    ldr r1, [r6]\n"
        "    cmp r0, r1\n"
        "    bne .L080B3296\n"
        "    ldr r0, [r5]\n"
        "    cmp r0, #0x4f\n"
        "    bne .L080B3300\n"
        "    mov r1, sl\n"
        "    str r1, [r5]\n"
        "    str r1, [r6]\n"
        "    b .L080B3296\n"
        "    .byte 0x00, 0x00\n"
        ".L080B32F8: .4byte 0x03004514 @ IWRAM+0x4514\n"
        ".L080B32FC: .4byte 0x03004614 @ IWRAM+0x4614\n"
        ".L080B3300:\n"
        "    adds r0, #1\n"
        "    str r0, [r5]\n"
        "    mov r0, sl\n"
        "    str r0, [r6]\n"
        "    b .L080B3296\n"
        ".L080B330A:\n"
        "    mov r1, r8\n"
        "    ldrh r0, [r1, #0x12]\n"
        "    adds r0, r5, r0\n"
        "    strh r0, [r1, #0x12]\n"
        "    ldrh r0, [r1, #0x14]\n"
        "    adds r0, r6, r0\n"
        "    strh r0, [r1, #0x14]\n"
        "    bl Field_SavePrevPosition\n"
        "    ldr r0, .L080B332C\n"
        "    ldr r1, .L080B3330\n"
        "    adds r0, r0, r1\n"
        "    mov r1, sl\n"
        "    strh r1, [r0]\n"
        "    movs r0, #1\n"
        "    b .L080B3336\n"
        "    .byte 0x00, 0x00\n"
        ".L080B332C: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080B3330: .4byte 0x00000A38\n"
        ".L080B3334:\n"
        "    movs r0, #0\n"
        ".L080B3336:\n"
        "    add sp, #8\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
    );
}

#endif


// FieldMap_FindRecordInMap @ 0x080B3348
/* First record of the given type anywhere in map mapId (all sub-maps), or NULL. */
u32 *FieldMap_FindRecordInMap(u16 mapId, u16 type)
{
    u16 count;
    u32 savedMap = (u16)gUnk_03004614;
    u32 savedSub = (u16)gUnk_03004514;
    u16 savedX = gFieldState.unk12;
    u16 savedY = gFieldState.unk14;
    u32 *rec = NULL;
    u16 sub, x, y;

    count = sub_080C8B3C(mapId);
    for (sub = 0; sub < count; sub++)
    {
        sub_080C8B10(mapId, sub);
        gUnk_03004614 = mapId;
        gUnk_03004514 = sub;
        sub_080AE234();
        gFieldState.unk12 = 0;
        gFieldState.unk14 = 0;
        for (y = 0; y < gFieldState.unk1C; y++)
        {
            for (x = 0; x < gFieldState.unk1A; x++)
            {
                rec = FieldMap_FindRecord(FieldMap_CellRecordsOffset(x, y), type);
                if (rec != NULL)
                    goto done;
            }
        }
    }
done:
    gUnk_03004614 = savedMap;
    gUnk_03004514 = savedSub;
    gFieldState.unk12 = savedX;
    gFieldState.unk14 = savedY;
    sub_080AE234();
    return rec;
}

// sub_080B343C @ 0x080B343C
/* Moves the view-open counter unk2E by delta, clamped to 0..0x21. */
void sub_080B343C(s16 delta)
{
    if (delta < 0)
    {
        gFieldState.unk2E += (u16)delta;
        if ((s16)gFieldState.unk2E < 0)
            gFieldState.unk2E = 0;
    }
    else
    {
        gFieldState.unk2E += (u16)delta;
        if (gFieldState.unk2E > 0x21)
            gFieldState.unk2E = 0x21;
    }
}

// sub_080B3478 @ 0x080B3478
void sub_080B3478(u8 *task, u32 flag)
{
    if (flag == 0)
    {
        if (View_GetWall(0, 0, 0) == 2)
            sub_080B343C(2);
        else if (!(gFrameCounter & 3))
            sub_080B343C(1);
        if (gFieldState.unk2E <= 0x20)
            *(u16 *)(task + 0x1C) = 0;
        else
            *(u16 *)(task + 0x1C) = 1;
    }
    else
    {
        gUnk_03000038 = 0x3F;
        gUnk_03000039 = 0x3F;
        gUnk_0300003A = 0x3F;
    }
}

// sub_080B34E8 @ 0x080B34E8
void sub_080B34E8(void)
{
    DmaCopy32(3, gUnknown_081622D0, (void *)0x06016000, 0x1C0);
}

// sub_080B350C @ 0x080B350C
void sub_080B350C(void)
{
    const void *src = sub_080C8B10(gUnk_03004614, gUnk_03004514)->variants[gGameState.unkA38].data[54];

    DmaCopy32(3, src, (void *)0x06016000, 0x400);
}

// sub_080B3560 @ 0x080B3560
void sub_080B3560(u32 unused)
{
    if (gUnk_03004614 != 0x42)
        sub_080C51D4(0x6B);
    else
        sub_080C51D4(0x6C);
}

// sub_080B3584 @ 0x080B3584
void sub_080B3584(u32 a)
{
    s32 r = View_GetWall(0, 0, 0);
    u32 kind = sub_080B2938();

    if (r == 2)
    {
        VBlankTask_AddCounted(sub_080AE1C4, 1);
        sub_080B3560(a);
        if (kind == 2)
            VBlankTask_AddCounted(sub_080B34E8, 1);
        else if (kind == 3)
            VBlankTask_AddCounted(sub_080B350C, 1);
    }
    else
    {
        VBlankTask_AddCounted(sub_080AE1FC, 1);
        sub_080C51D4(0x6D);
    }
    if (Palette_IsBg13Black() == 0)
    {
        u16 *pal;

        if (FieldMap_HasRecordRel(0, 0, 6) == 0)
            pal = gUnk_03003FC8;
        else
            pal = gUnk_0200F854;
        Palette_CopyWithEffect(3, pal, &gPaletteBuffer[0x1D0], 0x20, 0x10);
    }
    else
    {
        Palette_FillWithEffect(3, 0, &gPaletteBuffer[0x1D0], 0x20, 0x10);
    }
    Palette_MarkDirty();
}
