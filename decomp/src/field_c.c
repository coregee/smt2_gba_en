#include "global.h"
#include "field.h"

// sub_080B011C @ 0x080B011C
void sub_080B011C(u16 a)
{
    switch (a)
    {
    case 0:
        Flag_Set(0xEC);
        break;
    case 1:
        Flag_Clear(0xED);
        break;
    case 2:
        Flag_Set(0x101);
        break;
    }
}

// sub_080B0158 @ 0x080B0158
void sub_080B0158(void)
{
    if (!sub_080ADF40())
    {
        const void *src = gUnk_03003B94;
        FIELD_DMA3_SET(src, 0x06004000, 0x84000800);
    }
    sub_080B2880();
}

// sub_080B018C @ 0x080B018C
void sub_080B018C(void)
{
    if (!sub_080ADF40())
    {
        const void *src = (u8 *)gUnk_03003B94 + 0x2000;
        FIELD_DMA3_SET(src, 0x06004400, 0x84000700);
    }
    sub_080B2880();
}

// sub_080B01C8 @ 0x080B01C8
void sub_080B01C8(void)
{
    if (!sub_080ADF40())
    {
        const void *src = (u8 *)gUnk_03003B94 + 0x3C00;
        FIELD_DMA3_SET(src, 0x06004400, 0x84000700);
    }
    sub_080B2880();
}

/* Whether the player's square has no wall on side dir. */
// View_IsSideOpen @ 0x080B0204
bool32 View_IsSideOpen(u16 dir)
{
    const struct ViewCell *cell = &gViewCells[5][4];
    u16 wall;

    switch (dir)
    {
    case 0:
        wall = cell->walls[0];
        break;
    case 1:
        wall = cell->walls[1];
        break;
    case 2:
        wall = cell->walls[2];
        break;
    case 3:
        wall = cell->walls[3];
        break;
    default:
        return FALSE;
    }
    if (wall != 0)
        return FALSE;
    return TRUE;
}

/* Wall code on side dir of the view cell (dx, dy) relative to the player (cell [5][4]).
   Callers pass -1/-2 for the squares behind/left: as u16 these index far outside
   gViewCells, which only works because EWRAM mirrors every 256 KB
   (0xFFFF * 0x6C and 0xFFFF * 12 are both -size modulo 0x40000). */
// View_GetWall @ 0x080B0248
#ifdef NONMATCHING
u32 View_GetWall(u16 dir, u16 dx, u16 dy)
{
    const struct ViewCell *cell = &gViewCells[5 + dy][4 + dx];
    u16 wall;

    switch (dir)
    {
    case 0:
        wall = cell->walls[0];
        break;
    case 1:
        wall = cell->walls[1];
        break;
    case 2:
        wall = cell->walls[2];
        break;
    case 3:
        wall = cell->walls[3];
        break;
    default:
        return 0;
    }
    if (wall != 0)
        return wall;
    return 0;
}
#else
NAKED
u32 View_GetWall(u16 dir, u16 dx, u16 dy)
{
    asm_unified(
        ".L080B0248:\n"
        "    push {r4, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    adds r4, r3, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    movs r0, #0x6c\n"
        "    muls r2, r0, r2\n"
        "    ldr r0, .L080B0278\n"
        "    adds r2, r2, r0\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #2\n"
        "    adds r2, r2, r0\n"
        "    cmp r3, #1\n"
        "    beq .L080B028A\n"
        "    cmp r3, #1\n"
        "    bgt .L080B027C\n"
        "    cmp r3, #0\n"
        "    beq .L080B0286\n"
        "    b .L080B0298\n"
        "    .byte 0x00, 0x00\n"
        ".L080B0278: .4byte 0x0200AD54 @ EWRAM+0xAD54\n"
        ".L080B027C:\n"
        "    cmp r4, #2\n"
        "    beq .L080B028E\n"
        "    cmp r4, #3\n"
        "    beq .L080B0292\n"
        "    b .L080B0298\n"
        ".L080B0286:\n"
        "    ldrh r0, [r2, #4]\n"
        "    b .L080B0294\n"
        ".L080B028A:\n"
        "    ldrh r0, [r2, #6]\n"
        "    b .L080B0294\n"
        ".L080B028E:\n"
        "    ldrh r0, [r2, #8]\n"
        "    b .L080B0294\n"
        ".L080B0292:\n"
        "    ldrh r0, [r2, #0xa]\n"
        ".L080B0294:\n"
        "    cmp r0, #0\n"
        "    bne .L080B029A\n"
        ".L080B0298:\n"
        "    movs r0, #0\n"
        ".L080B029A:\n"
        "    pop {r4}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

/* Steps one square in direction dir (clamped to the map) and marks it visited;
   gUnk_03003FF4 = 1 when the step was taken. */
// Field_Step @ 0x080B02A0
void Field_Step(u16 dir)
{
    Field_SavePrevPosition();
    switch (dir)
    {
    case 0:
        if (gFieldState.unk14 != 0)
            gFieldState.unk14--;
        break;
    case 1:
        if (gFieldState.unk12 != gFieldState.unk1A - 1)
            gFieldState.unk12++;
        break;
    case 2:
        if (!sub_080ADF40())
        {
            if (gFieldState.unk14 != gFieldState.unk1C - 1)
                gFieldState.unk14++;
        }
        else
        {
            gUnk_03003FF4 = 0;
            return;
        }
        break;
    case 3:
        if (gFieldState.unk12 != 0)
            gFieldState.unk12--;
        break;
    }
    Automap_SetVisited(gFieldState.unk12, gFieldState.unk14);
    gUnk_03003FF4 = 1;
}

// sub_080B0350 @ 0x080B0350
u32 sub_080B0350(void)
{
    u32 a = sub_080C1D9C() & 0xF0;
    u32 b = sub_080C1D9C() & 0xFF;

    if (a == 0)
    {
        if (sub_080F3F44() & 0x100)
            sub_080F3F58(~0x100);
    }
    else if (b == 0x80)
    {
        if (sub_080F3F44() & 0x20)
            sub_080F3F58(~0x20);
        if (sub_080F3F44() & 0x40)
            sub_080F3F58(~0x40);
    }
    sub_080C1AB0();
    return 0;
}

/* After a step: runs the square's event, encounter or terrain effect. Returns 1 when
   something took over (state changed), else sets the field state to `state`. */
// sub_080B03BC @ 0x080B03BC
#ifdef NONMATCHING
u32 sub_080B03BC(u16 state)
{
    u16 saved = sub_080C221C();
    u16 a, b;
    void *ev = sub_080C1B74(&a, &b);

    if (gUnk_03003FF4 != 0)
    {
        void *ev2 = sub_080C1E20();

        sub_080C20EC();
        if (state == 1 && Door_TryOpen() == 1)
        {
            gFieldState.unk00 = 0x1A;
            return 0;
        }
        if (ev2 != NULL)
            sub_080B9274(ev2);
        else if (ev != NULL)
            sub_080BEC3C(ev, a, b);
        else if (sub_080B0350() == 0 && gFieldState.unk5C == 0)
            goto nothing;
        else
            sub_080B90F4();
        Field_SetState(0x1A);
        return 1;

    nothing:
        if (RandomEvent_Try())
            return 1;
        if (sub_080C2280(0) == 1)
        {
            u32 wall = View_GetWall(0, 0, 1);

            if (sub_080B6170() == 0xFFFF && (wall == 2 || wall == 3) && FieldMap_CellRecordsRel(0, 1))
            {
                sub_080C2230(saved);
            }
            else
            {
                sub_080AF034();
                return 1;
            }
        }
    }
    Field_SetState(state);
    return 0;
}
#else
NAKED
u32 sub_080B03BC(u16 state)
{
    asm_unified(
        ".L080B03BC:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    sub sp, #4\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    bl sub_080C221C\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        "    mov r4, sp\n"
        "    adds r4, #2\n"
        "    mov r0, sp\n"
        "    adds r1, r4, #0\n"
        "    bl sub_080C1B74\n"
        "    adds r6, r0, #0\n"
        "    ldr r0, .L080B0408\n"
        "    ldrh r0, [r0]\n"
        "    adds r7, r4, #0\n"
        "    cmp r0, #0\n"
        "    beq .L080B04A8\n"
        "    bl sub_080C1E20\n"
        "    adds r4, r0, #0\n"
        "    bl sub_080C20EC\n"
        "    cmp r5, #1\n"
        "    bne .L080B0410\n"
        "    bl Door_TryOpen\n"
        "    cmp r0, #1\n"
        "    bne .L080B0410\n"
        "    ldr r1, .L080B040C\n"
        "    movs r0, #0x1a\n"
        "    strh r0, [r1]\n"
        "    b .L080B04AE\n"
        ".L080B0408: .4byte 0x03003FF4 @ IWRAM+0x3FF4\n"
        ".L080B040C: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B0410:\n"
        "    cmp r4, #0\n"
        "    beq .L080B041C\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080B9274\n"
        "    b .L080B0444\n"
        ".L080B041C:\n"
        "    cmp r6, #0\n"
        "    beq .L080B042E\n"
        "    mov r0, sp\n"
        "    ldrh r1, [r0]\n"
        "    ldrh r2, [r7]\n"
        "    adds r0, r6, #0\n"
        "    bl sub_080BEC3C\n"
        "    b .L080B0444\n"
        ".L080B042E:\n"
        "    bl sub_080B0350\n"
        "    cmp r0, #0\n"
        "    bne .L080B0440\n"
        "    ldr r0, .L080B0450\n"
        "    adds r0, #0x5c\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    beq .L080B0454\n"
        ".L080B0440:\n"
        "    bl sub_080B90F4\n"
        ".L080B0444:\n"
        "    movs r0, #0x1a\n"
        "    bl Field_SetState\n"
        "    movs r0, #1\n"
        "    b .L080B04B0\n"
        "    .byte 0x00, 0x00\n"
        ".L080B0450: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B0454:\n"
        "    bl RandomEvent_Try\n"
        "    cmp r0, #0\n"
        "    beq .L080B0460\n"
        "    movs r0, #1\n"
        "    b .L080B04B0\n"
        ".L080B0460:\n"
        "    movs r0, #0\n"
        "    bl sub_080C2280\n"
        "    cmp r0, #1\n"
        "    bne .L080B04A8\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #1\n"
        "    bl View_GetWall\n"
        "    adds r4, r0, #0\n"
        "    bl sub_080B6170\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r1, .L080B049C\n"
        "    cmp r0, r1\n"
        "    bne .L080B04A0\n"
        "    subs r0, r4, #2\n"
        "    cmp r0, #1\n"
        "    bhi .L080B04A0\n"
        "    movs r0, #0\n"
        "    movs r1, #1\n"
        "    bl FieldMap_CellRecordsRel\n"
        "    cmp r0, #0\n"
        "    beq .L080B04A0\n"
        "    mov r0, r8\n"
        "    bl sub_080C2230\n"
        "    b .L080B04A8\n"
        ".L080B049C: .4byte 0xFFFF0000\n"
        ".L080B04A0:\n"
        "    bl sub_080AF034\n"
        "    movs r0, #1\n"
        "    b .L080B04B0\n"
        ".L080B04A8:\n"
        "    adds r0, r5, #0\n"
        "    bl Field_SetState\n"
        ".L080B04AE:\n"
        "    movs r0, #0\n"
        ".L080B04B0:\n"
        "    add sp, #4\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif
