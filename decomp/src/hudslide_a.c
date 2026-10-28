#include "global.h"
#include "status.h"

// Hud_LoadAllMemberFaces @ 0x080C6FD8
void Hud_LoadAllMemberFaces(void)
{
    s32 i;

    for (i = 0; i < 6; i++)
        Hud_LoadMemberFace(i);
}

// sub_080C6FF0 @ 0x080C6FF0
void sub_080C6FF0(void)
{
    struct C0c6Hud *hud = gHud;

    if (hud->state[0] == 0)
    {
        hud->state[0] = 1;
        hud->step[0] = 0;
        hud->timer[0] = 1;
    }
}

// sub_080C700C @ 0x080C700C
void sub_080C700C(void)
{
    if (sub_080C8AF8(gMapId) && gHud->state[0] == 3)
    {
        gHud->state[0] = 2;
        gHud->timer[0] = 1;
    }
}

// sub_080C7038 @ 0x080C7038
void sub_080C7038(void)
{
    struct C0c6Hud *hud = gHud;

    if (hud->state[1] == 0)
    {
        hud->state[1] = 1;
        hud->step[1] = 0;
        hud->timer[1] = 1;
    }
}

// sub_080C7054 @ 0x080C7054
void sub_080C7054(void)
{
    if (gHud->state[1] == 3)
    {
        gHud->state[1] = 2;
        gHud->timer[1] = 1;
    }
}

/* The HUD panels slide in (state 1) and out (state 2) one tile per 'timer' frames. Each slide
   function clears the panel's rectangle, copies the visible part of the panel tilemap (32 tiles
   wide; first visible column col, row row) to (x, y) and queues the upload. The original keeps
   every constant of these functions in its own register and never folds row * 32, which no
   spelling tried so far reproduces. */

// Hud_SlidePartyPanel @ 0x080C7070
/* The party panel (top left, 7x3) slides in from the left. */
#ifdef NONMATCHING
void Hud_SlidePartyPanel(u16 *state, u16 *timer, u16 *step)
{
    u16 col = 0;
    u16 row = 0;
    u16 x = 1;
    u16 w = 7;
    u16 h = 3;
    u16 cx;

    if (*state == 1)
    {
        Tilemap_FillRect(0, gWindowTilemapBuffer, 0, 0, 8, h);
        if (x < *step)
        {
            col = *step - 1;
            w -= col;
        }
        x -= *step;
        if (w != 0)
        {
            cx = x;
            if ((s16)cx < 0)
                cx = 0;
            Tilemap_CopyRectSkipZero(&((const u16 *)gUnknown_081B8270)[row * 32 + col], gWindowTilemapBuffer,
                                     0, 0, cx, 0, w, h);
        }
        else
            *state = 3;
        sub_080C6764();
        if (--*timer == 0)
        {
            *timer = 1;
            *step += 1;
        }
    }
    else if (*state == 2)
    {
        Tilemap_FillRect(0, gWindowTilemapBuffer, 0, 0, 8, h);
        if (x < *step)
        {
            col = *step - 1;
            w -= col;
        }
        x -= *step;
        if ((s16)w > 0)
        {
            cx = x;
            if ((s16)cx < 0)
                cx = 0;
            Tilemap_CopyRectSkipZero(&((const u16 *)gUnknown_081B8270)[row * 32 + col], gWindowTilemapBuffer,
                                     0, 0, cx, 0, w, h);
            if (*step == 0)
                *state = 0;
        }
        sub_080C6764();
        if (--*timer == 0)
        {
            *timer = 1;
            *step -= 1;
        }
    }
    if (*state != 3)
        Sprite_Draw(gUnknown_080005A0, 0, 0, 0, 0, x * 8 + 2, 5);
}
#else
NAKED
void Hud_SlidePartyPanel(u16 *state, u16 *timer, u16 *step)
{
    asm_unified(
        ".L080C7070:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x10\n"
        "    mov sb, r0\n"
        "    adds r7, r1, #0\n"
        "    adds r4, r2, #0\n"
        "    movs r0, #0\n"
        "    mov r8, r0\n"
        "    movs r5, #1\n"
        "    movs r6, #7\n"
        "    movs r1, #3\n"
        "    mov sl, r1\n"
        "    mov r1, sb\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #1\n"
        "    bne .L080C7120\n"
        "    ldr r1, .L080C70F8\n"
        "    movs r0, #8\n"
        "    str r0, [sp]\n"
        "    mov r0, sl\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Tilemap_FillRect\n"
        "    ldrh r2, [r4]\n"
        "    cmp r5, r2\n"
        "    bhs .L080C70BE\n"
        "    subs r0, r2, #1\n"
        "    subs r1, r6, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r6, r1, #0x10\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        ".L080C70BE:\n"
        "    subs r0, r5, r2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r6, #0\n"
        "    beq .L080C7100\n"
        "    ldr r3, .L080C70FC\n"
        "    adds r2, r5, #0\n"
        "    movs r1, #0\n"
        "    lsls r0, r1, #5\n"
        "    add r0, r8\n"
        "    lsls r0, r0, #1\n"
        "    adds r3, r0, r3\n"
        "    lsls r0, r2, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L080C70DE\n"
        "    movs r2, #0\n"
        ".L080C70DE:\n"
        "    ldr r1, .L080C70F8\n"
        "    str r2, [sp]\n"
        "    movs r0, #0\n"
        "    str r0, [sp, #4]\n"
        "    str r6, [sp, #8]\n"
        "    mov r0, sl\n"
        "    str r0, [sp, #0xc]\n"
        "    adds r0, r3, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Tilemap_CopyRectSkipZero\n"
        "    b .L080C7106\n"
        ".L080C70F8: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C70FC: .4byte gUnknown_081B8270\n"
        ".L080C7100:\n"
        "    movs r0, #3\n"
        "    mov r1, sb\n"
        "    strh r0, [r1]\n"
        ".L080C7106:\n"
        "    bl sub_080C6764\n"
        "    ldrh r0, [r7]\n"
        "    subs r0, #1\n"
        "    strh r0, [r7]\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C71AA\n"
        "    movs r0, #1\n"
        "    strh r0, [r7]\n"
        "    ldrh r0, [r4]\n"
        "    adds r0, #1\n"
        "    b .L080C71A8\n"
        ".L080C7120:\n"
        "    cmp r0, #2\n"
        "    bne .L080C71AA\n"
        "    ldr r1, .L080C71E0\n"
        "    movs r0, #8\n"
        "    str r0, [sp]\n"
        "    mov r0, sl\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Tilemap_FillRect\n"
        "    ldrh r2, [r4]\n"
        "    cmp r5, r2\n"
        "    bhs .L080C714C\n"
        "    subs r0, r2, #1\n"
        "    subs r1, r6, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r6, r1, #0x10\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        ".L080C714C:\n"
        "    subs r0, r5, r2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    lsls r0, r6, #0x10\n"
        "    cmp r0, #0\n"
        "    ble .L080C7190\n"
        "    ldr r3, .L080C71E4\n"
        "    adds r2, r5, #0\n"
        "    movs r1, #0\n"
        "    lsls r0, r1, #5\n"
        "    add r0, r8\n"
        "    lsls r0, r0, #1\n"
        "    adds r3, r0, r3\n"
        "    lsls r0, r2, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L080C716E\n"
        "    movs r2, #0\n"
        ".L080C716E:\n"
        "    ldr r1, .L080C71E0\n"
        "    str r2, [sp]\n"
        "    movs r0, #0\n"
        "    str r0, [sp, #4]\n"
        "    str r6, [sp, #8]\n"
        "    mov r0, sl\n"
        "    str r0, [sp, #0xc]\n"
        "    adds r0, r3, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Tilemap_CopyRectSkipZero\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #0\n"
        "    bne .L080C7190\n"
        "    mov r1, sb\n"
        "    strh r0, [r1]\n"
        ".L080C7190:\n"
        "    bl sub_080C6764\n"
        "    ldrh r0, [r7]\n"
        "    subs r0, #1\n"
        "    strh r0, [r7]\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C71AA\n"
        "    movs r0, #1\n"
        "    strh r0, [r7]\n"
        "    ldrh r0, [r4]\n"
        "    subs r0, #1\n"
        ".L080C71A8:\n"
        "    strh r0, [r4]\n"
        ".L080C71AA:\n"
        "    mov r1, sb\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #3\n"
        "    beq .L080C71D0\n"
        "    ldr r0, .L080C71E8\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    lsls r1, r5, #3\n"
        "    adds r1, #2\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #5\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L080C71D0:\n"
        "    add sp, #0x10\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080C71E0: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C71E4: .4byte gUnknown_081B8270\n"
        ".L080C71E8: .4byte gUnknown_080005A0\n"
    );
}
#endif

// sub_080C71EC @ 0x080C71EC
void sub_080C71EC(void)
{
    struct C0c6Hud *hud = gHud;

    Hud_SlidePartyPanel(&hud->state[0], &hud->timer[0], &hud->step[0]);
    Hud_SlidePartyPanel(&hud->state[1], &hud->timer[1], &hud->step[1]);
}

// sub_080C7218 @ 0x080C7218
void sub_080C7218(void)
{
    struct C0c6Hud *hud = gHud;

    if (hud->state[2] == 0)
    {
        hud->state[2] = 1;
        hud->step[2] = 0;
        hud->timer[2] = 1;
    }
}

// sub_080C7234 @ 0x080C7234
void sub_080C7234(void)
{
    if (sub_080C8AF8(gMapId) && gHud->state[2] == 3)
    {
        gHud->state[2] = 2;
        gHud->timer[2] = 1;
        VBlankTask_AddCounted(sub_080C65A4, 1);
    }
}

// sub_080C726C @ 0x080C726C
/* The facing panel (4x2 at column 13) slides down from the top; while gGameState.unkAC0 is 1
   it does not slide out (and is not drawn). */
#ifdef NONMATCHING
void sub_080C726C(void)
{
    u16 col = 0;
    u16 row = 0;
    u16 x = 0xD;
    u16 y = 0;
    u16 w = 4;
    u16 h = 2;
    u16 cy;

    if (gHud->state[2] == 1)
    {
        Tilemap_FillRect(0, gWindowTilemapBuffer, 0xD, 0, w, h);
        if (y < gHud->step[2])
        {
            h -= gHud->step[2];
            row = gHud->step[2];
        }
        y = -gHud->step[2];
        if (h != 0)
        {
            cy = y;
            if ((s16)cy < 0)
                cy = 0;
            Tilemap_CopyRectSkipZero(&((const u16 *)gUnknown_081B92B0)[row * 32 + col], gWindowTilemapBuffer,
                                     0, 0, x, cy, w, h);
        }
        else
            gHud->state[2] = 3;
        sub_080C6764();
        if (--gHud->timer[2] == 0)
        {
            gHud->timer[2] = 1;
            gHud->step[2]++;
        }
    }
    else if (gHud->state[2] == 2)
    {
        if (gGameState.unkAC0 == 1)
            return;
        Tilemap_FillRect(0, gWindowTilemapBuffer, 0xD, 0, w, h);
        if (y < gHud->step[2])
        {
            h -= gHud->step[2];
            row = gHud->step[2];
        }
        y = -gHud->step[2];
        if ((s16)h > 0)
        {
            cy = y;
            if ((s16)cy < 0)
                cy = 0;
            Tilemap_CopyRectSkipZero(&((const u16 *)gUnknown_081B92B0)[row * 32 + col], gWindowTilemapBuffer,
                                     0, 0, x, cy, w, h);
            if (gHud->step[2] == 0)
                gHud->state[2] = 0;
        }
        sub_080C6764();
        if (--gHud->timer[2] == 0)
        {
            gHud->timer[2] = 1;
            gHud->step[2]--;
        }
    }
    if (gHud->state[2] != 3)
        Sprite_Draw(gUnknown_0834A214[gFieldState.facing], 0, 0, 0, 0, x * 8 + 8, y * 8 + 5);
}
#else
NAKED
void sub_080C726C(void)
{
    asm_unified(
        ".L080C726C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x10\n"
        "    movs r0, #0\n"
        "    mov sl, r0\n"
        "    movs r7, #0\n"
        "    movs r1, #0xd\n"
        "    mov sb, r1\n"
        "    movs r6, #0\n"
        "    movs r2, #4\n"
        "    mov r8, r2\n"
        "    movs r4, #2\n"
        "    ldr r5, .L080C72EC\n"
        "    ldrh r0, [r5, #4]\n"
        "    cmp r0, #1\n"
        "    bne .L080C7320\n"
        "    ldr r1, .L080C72F0\n"
        "    str r2, [sp]\n"
        "    str r4, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r2, #0xd\n"
        "    movs r3, #0\n"
        "    bl Tilemap_FillRect\n"
        "    ldrh r1, [r5, #0x14]\n"
        "    adds r2, r1, #0\n"
        "    cmp r6, r2\n"
        "    bhs .L080C72B2\n"
        "    subs r0, r4, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    adds r7, r2, #0\n"
        ".L080C72B2:\n"
        "    rsbs r0, r1, #0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r4, #0\n"
        "    beq .L080C72F8\n"
        "    ldr r3, .L080C72F4\n"
        "    adds r2, r6, #0\n"
        "    lsls r0, r7, #5\n"
        "    add r0, sl\n"
        "    lsls r0, r0, #1\n"
        "    adds r3, r0, r3\n"
        "    lsls r0, r2, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L080C72D0\n"
        "    movs r2, #0\n"
        ".L080C72D0:\n"
        "    ldr r1, .L080C72F0\n"
        "    mov r0, sb\n"
        "    str r0, [sp]\n"
        "    str r2, [sp, #4]\n"
        "    mov r2, r8\n"
        "    str r2, [sp, #8]\n"
        "    str r4, [sp, #0xc]\n"
        "    adds r0, r3, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Tilemap_CopyRectSkipZero\n"
        "    b .L080C72FE\n"
        "    .byte 0x00, 0x00\n"
        ".L080C72EC: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
        ".L080C72F0: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C72F4: .4byte gUnknown_081B92B0\n"
        ".L080C72F8:\n"
        "    ldr r1, .L080C731C\n"
        "    movs r0, #3\n"
        "    strh r0, [r1, #4]\n"
        ".L080C72FE:\n"
        "    bl sub_080C6764\n"
        "    ldr r1, .L080C731C\n"
        "    ldrh r0, [r1, #0x24]\n"
        "    subs r0, #1\n"
        "    strh r0, [r1, #0x24]\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C73B2\n"
        "    movs r0, #1\n"
        "    strh r0, [r1, #0x24]\n"
        "    ldrh r0, [r1, #0x14]\n"
        "    adds r0, #1\n"
        "    b .L080C73B0\n"
        "    .byte 0x00, 0x00\n"
        ".L080C731C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
        ".L080C7320:\n"
        "    cmp r0, #2\n"
        "    bne .L080C73B2\n"
        "    ldr r0, .L080C73FC\n"
        "    movs r1, #0xac\n"
        "    lsls r1, r1, #4\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #1\n"
        "    beq .L080C73EC\n"
        "    ldr r1, .L080C7400\n"
        "    mov r2, r8\n"
        "    str r2, [sp]\n"
        "    str r4, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r2, #0xd\n"
        "    movs r3, #0\n"
        "    bl Tilemap_FillRect\n"
        "    ldrh r1, [r5, #0x14]\n"
        "    adds r2, r1, #0\n"
        "    cmp r6, r2\n"
        "    bhs .L080C7354\n"
        "    subs r0, r4, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    adds r7, r2, #0\n"
        ".L080C7354:\n"
        "    rsbs r0, r1, #0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    lsls r0, r4, #0x10\n"
        "    cmp r0, #0\n"
        "    ble .L080C7396\n"
        "    ldr r3, .L080C7404\n"
        "    adds r2, r6, #0\n"
        "    lsls r0, r7, #5\n"
        "    add r0, sl\n"
        "    lsls r0, r0, #1\n"
        "    adds r3, r0, r3\n"
        "    lsls r0, r2, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L080C7374\n"
        "    movs r2, #0\n"
        ".L080C7374:\n"
        "    ldr r1, .L080C7400\n"
        "    mov r0, sb\n"
        "    str r0, [sp]\n"
        "    str r2, [sp, #4]\n"
        "    mov r2, r8\n"
        "    str r2, [sp, #8]\n"
        "    str r4, [sp, #0xc]\n"
        "    adds r0, r3, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Tilemap_CopyRectSkipZero\n"
        "    ldr r1, .L080C7408\n"
        "    ldrh r0, [r1, #0x14]\n"
        "    cmp r0, #0\n"
        "    bne .L080C7396\n"
        "    strh r0, [r1, #4]\n"
        ".L080C7396:\n"
        "    bl sub_080C6764\n"
        "    ldr r1, .L080C7408\n"
        "    ldrh r0, [r1, #0x24]\n"
        "    subs r0, #1\n"
        "    strh r0, [r1, #0x24]\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C73B2\n"
        "    movs r0, #1\n"
        "    strh r0, [r1, #0x24]\n"
        "    ldrh r0, [r1, #0x14]\n"
        "    subs r0, #1\n"
        ".L080C73B0:\n"
        "    strh r0, [r1, #0x14]\n"
        ".L080C73B2:\n"
        "    ldr r0, .L080C7408\n"
        "    ldrh r0, [r0, #4]\n"
        "    cmp r0, #3\n"
        "    beq .L080C73EC\n"
        "    ldr r1, .L080C740C\n"
        "    ldr r0, .L080C7410\n"
        "    ldrh r0, [r0, #2]\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    mov r2, sb\n"
        "    lsls r1, r2, #0x13\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #0xc\n"
        "    adds r1, r1, r2\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #4]\n"
        "    lsls r1, r6, #3\n"
        "    adds r1, #5\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L080C73EC:\n"
        "    add sp, #0x10\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080C73FC: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080C7400: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C7404: .4byte gUnknown_081B92B0\n"
        ".L080C7408: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
        ".L080C740C: .4byte gUnknown_0834A214\n"
        ".L080C7410: .4byte 0x03004550 @ IWRAM+0x4550\n"
    );
}
#endif

// sub_080C7414 @ 0x080C7414
void sub_080C7414(void)
{
    struct C0c6Hud *hud = gHud;

    if (hud->state[3] == 0)
    {
        hud->state[3] = 1;
        hud->step[3] = 0;
        hud->timer[3] = 1;
    }
}

// sub_080C7430 @ 0x080C7430
void sub_080C7430(void)
{
    if (sub_080C8AF8(gMapId) && gHud->state[3] == 3)
    {
        gHud->state[3] = 2;
        gHud->timer[3] = 1;
    }
}

// sub_080C745C @ 0x080C745C
/* The magnetite panel (8x2 at column 21) slides in from the right; the counter blinks while
   hud->blink counts. */
#ifdef NONMATCHING
void sub_080C745C(void)
{
    u16 col = 0;
    u16 row = 0;
    u16 x = 0x15;
    u16 y = 0;
    u16 w = 8;
    u16 h = 2;
    u16 pal;
    u16 cx;

    if (gHud->state[3] == 1)
    {
        Tilemap_FillRect(0, gWindowTilemapBuffer, 0x15, 0, 9, h);
        if (gHud->step[3] + 0x1D > 0x1E)
        {
            w -= gHud->step[3];
            col = gHud->step[3];
        }
        x = gHud->step[3] + 0x15;
        if (w != 0)
        {
            cx = x;
            if ((s16)cx < 0)
                cx = 0;
            Tilemap_CopyRectSkipZero(&((const u16 *)gUnknown_081B8170)[row * 32 + col], gWindowTilemapBuffer,
                                     0, 0, cx, y, w, h);
        }
        else
            gHud->state[3] = 3;
        sub_080C6764();
        if (--gHud->timer[3] == 0)
        {
            gHud->timer[3] = 1;
            gHud->step[3]++;
        }
    }
    else if (gHud->state[3] == 2)
    {
        Tilemap_FillRect(0, gWindowTilemapBuffer, 0x15, 0, 9, h);
        if (gHud->step[3] + 0x1D > 0x1E)
        {
            w -= gHud->step[3];
            col = gHud->step[3];
        }
        x = gHud->step[3] + 0x15;
        if ((s16)w > 0)
        {
            cx = x;
            if ((s16)cx < 0)
                cx = 0;
            Tilemap_CopyRectSkipZero(&((const u16 *)gUnknown_081B8170)[row * 32 + col], gWindowTilemapBuffer,
                                     0, 0, cx, y, w, h);
            if (gHud->step[3] == 0)
                gHud->state[3] = 0;
        }
        sub_080C6764();
        if (--gHud->timer[3] == 0)
        {
            gHud->timer[3] = 1;
            gHud->step[3]--;
        }
    }
    if (gHud->state[3] != 3)
    {
        pal = 0;
        if (gHud->blink != 0)
        {
            pal = 2;
            if (++gHud->blink > 3)
                gHud->blink = 0;
        }
        Sprite_Draw(gUnknown_080007FC, 0, pal, 0, 0, x * 8 + 2, 5);
        sub_080C7FD0(Magnetite_Get(), x * 8 + 8, 5, 0, pal);
    }
}
#else
NAKED
void sub_080C745C(void)
{
    asm_unified(
        ".L080C745C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x10\n"
        "    movs r6, #0\n"
        "    mov sl, r6\n"
        "    movs r7, #0x15\n"
        "    mov sb, r6\n"
        "    movs r4, #8\n"
        "    movs r0, #2\n"
        "    mov r8, r0\n"
        "    ldr r5, .L080C74A8\n"
        "    ldrh r0, [r5, #6]\n"
        "    cmp r0, #1\n"
        "    bne .L080C751C\n"
        "    ldr r1, .L080C74AC\n"
        "    movs r0, #9\n"
        "    str r0, [sp]\n"
        "    mov r0, r8\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r2, #0x15\n"
        "    movs r3, #0\n"
        "    bl Tilemap_FillRect\n"
        "    ldrh r1, [r5, #0x16]\n"
        "    adds r0, r1, #0\n"
        "    adds r0, #0x1d\n"
        "    cmp r0, #0x1e\n"
        "    ble .L080C74B0\n"
        "    subs r0, r4, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    adds r6, r1, #0\n"
        "    adds r0, r6, #0\n"
        "    b .L080C74B2\n"
        ".L080C74A8: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
        ".L080C74AC: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C74B0:\n"
        "    adds r0, r1, #0\n"
        ".L080C74B2:\n"
        "    adds r0, #0x15\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    cmp r4, #0\n"
        "    beq .L080C74F4\n"
        "    ldr r3, .L080C74EC\n"
        "    adds r2, r7, #0\n"
        "    mov r1, sl\n"
        "    lsls r0, r1, #5\n"
        "    adds r0, r0, r6\n"
        "    lsls r0, r0, #1\n"
        "    adds r3, r0, r3\n"
        "    lsls r0, r2, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L080C74D2\n"
        "    movs r2, #0\n"
        ".L080C74D2:\n"
        "    ldr r1, .L080C74F0\n"
        "    str r2, [sp]\n"
        "    mov r0, sb\n"
        "    str r0, [sp, #4]\n"
        "    str r4, [sp, #8]\n"
        "    mov r0, r8\n"
        "    str r0, [sp, #0xc]\n"
        "    adds r0, r3, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Tilemap_CopyRectSkipZero\n"
        "    b .L080C74FA\n"
        ".L080C74EC: .4byte gUnknown_081B8170\n"
        ".L080C74F0: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C74F4:\n"
        "    ldr r1, .L080C7518\n"
        "    movs r0, #3\n"
        "    strh r0, [r1, #6]\n"
        ".L080C74FA:\n"
        "    bl sub_080C6764\n"
        "    ldr r1, .L080C7518\n"
        "    ldrh r0, [r1, #0x26]\n"
        "    subs r0, #1\n"
        "    strh r0, [r1, #0x26]\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C75B2\n"
        "    movs r0, #1\n"
        "    strh r0, [r1, #0x26]\n"
        "    ldrh r0, [r1, #0x16]\n"
        "    adds r0, #1\n"
        "    b .L080C75B0\n"
        "    .byte 0x00, 0x00\n"
        ".L080C7518: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
        ".L080C751C:\n"
        "    cmp r0, #2\n"
        "    bne .L080C75B2\n"
        "    ldr r1, .L080C754C\n"
        "    movs r0, #9\n"
        "    str r0, [sp]\n"
        "    mov r0, r8\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r2, #0x15\n"
        "    movs r3, #0\n"
        "    bl Tilemap_FillRect\n"
        "    ldrh r1, [r5, #0x16]\n"
        "    adds r0, r1, #0\n"
        "    adds r0, #0x1d\n"
        "    cmp r0, #0x1e\n"
        "    ble .L080C7550\n"
        "    subs r0, r4, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    adds r6, r1, #0\n"
        "    adds r0, r6, #0\n"
        "    b .L080C7552\n"
        "    .byte 0x00, 0x00\n"
        ".L080C754C: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C7550:\n"
        "    adds r0, r1, #0\n"
        ".L080C7552:\n"
        "    adds r0, #0x15\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    lsls r0, r4, #0x10\n"
        "    cmp r0, #0\n"
        "    ble .L080C7596\n"
        "    ldr r3, .L080C761C\n"
        "    adds r2, r7, #0\n"
        "    mov r1, sl\n"
        "    lsls r0, r1, #5\n"
        "    adds r0, r0, r6\n"
        "    lsls r0, r0, #1\n"
        "    adds r3, r0, r3\n"
        "    lsls r0, r2, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L080C7574\n"
        "    movs r2, #0\n"
        ".L080C7574:\n"
        "    ldr r1, .L080C7620\n"
        "    str r2, [sp]\n"
        "    mov r0, sb\n"
        "    str r0, [sp, #4]\n"
        "    str r4, [sp, #8]\n"
        "    mov r0, r8\n"
        "    str r0, [sp, #0xc]\n"
        "    adds r0, r3, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Tilemap_CopyRectSkipZero\n"
        "    ldr r1, .L080C7624\n"
        "    ldrh r0, [r1, #0x16]\n"
        "    cmp r0, #0\n"
        "    bne .L080C7596\n"
        "    strh r0, [r1, #6]\n"
        ".L080C7596:\n"
        "    bl sub_080C6764\n"
        "    ldr r1, .L080C7624\n"
        "    ldrh r0, [r1, #0x26]\n"
        "    subs r0, #1\n"
        "    strh r0, [r1, #0x26]\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C75B2\n"
        "    movs r0, #1\n"
        "    strh r0, [r1, #0x26]\n"
        "    ldrh r0, [r1, #0x16]\n"
        "    subs r0, #1\n"
        ".L080C75B0:\n"
        "    strh r0, [r1, #0x16]\n"
        ".L080C75B2:\n"
        "    ldr r1, .L080C7624\n"
        "    ldrh r0, [r1, #6]\n"
        "    cmp r0, #3\n"
        "    beq .L080C760A\n"
        "    movs r6, #0\n"
        "    adds r1, #0x70\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #0\n"
        "    beq .L080C75D6\n"
        "    movs r6, #2\n"
        "    adds r0, #1\n"
        "    strh r0, [r1]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #3\n"
        "    bls .L080C75D6\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        ".L080C75D6:\n"
        "    ldr r0, .L080C7628\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    lsls r4, r7, #3\n"
        "    adds r1, r4, #2\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #4]\n"
        "    movs r5, #5\n"
        "    str r5, [sp, #8]\n"
        "    movs r1, #0\n"
        "    adds r2, r6, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    bl Magnetite_Get\n"
        "    adds r4, #8\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    str r6, [sp]\n"
        "    adds r1, r4, #0\n"
        "    adds r2, r5, #0\n"
        "    movs r3, #0\n"
        "    bl sub_080C7FD0\n"
        ".L080C760A:\n"
        "    add sp, #0x10\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080C761C: .4byte gUnknown_081B8170\n"
        ".L080C7620: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C7624: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
        ".L080C7628: .4byte gUnknown_080007FC\n"
    );
}
#endif

// sub_080C762C @ 0x080C762C
void sub_080C762C(void)
{
    struct C0c6Hud *hud = gHud;

    if (hud->state[4] == 0)
    {
        hud->state[4] = 1;
        hud->step[4] = 0;
        hud->timer[4] = 1;
    }
}

// sub_080C7648 @ 0x080C7648
void sub_080C7648(void)
{
    if (gHud->state[4] == 3)
    {
        gHud->state[4] = 2;
        gHud->timer[4] = 1;
    }
}

// sub_080C7664 @ 0x080C7664
/* Draws the money sign and amount v at tile (x, y). */
void sub_080C7664(u16 x, u16 y, u32 v)
{
    Sprite_Draw(gUnknown_0800080C, 0, 0, 0, 1, x * 8 + 2, y * 8 + 5);
    sub_080C8048(v, x * 8 + 8, y * 8 + 5, 0);
}

// sub_080C76B4 @ 0x080C76B4
/* The money panel (8x2 at column 21, row 2) slides in from the right. */
#ifdef NONMATCHING
void sub_080C76B4(void)
{
    u16 col = 0;
    u16 row = 0;
    u16 x = 0x15;
    u16 y = 2;
    u16 w = 8;
    u16 h = 2;
    u16 cx;

    if (gHud->state[4] == 1)
    {
        Tilemap_FillRect(0, gWindowTilemapBuffer, 0x15, 2, 10, y);
        /* sliding in tests > 2, sliding out > 1 */
        if (gHud->step[4] + 0x1C > 0x1E)
        {
            w -= gHud->step[4];
            col = gHud->step[4];
        }
        x = gHud->step[4] + 0x15;
        if (w != 0)
        {
            cx = x;
            if ((s16)cx < 0)
                cx = 0;
            Tilemap_CopyRectSkipZero(&((const u16 *)gUnknown_081B8170)[row * 32 + col], gWindowTilemapBuffer,
                                     0, 0, cx, y, w, h);
        }
        else
            gHud->state[4] = 3;
        sub_080C6764();
        if (--gHud->timer[4] == 0)
        {
            gHud->timer[4] = 1;
            gHud->step[4]++;
        }
    }
    else if (gHud->state[4] == 2)
    {
        Tilemap_FillRect(0, gWindowTilemapBuffer, 0x15, 2, 10, y);
        if (gHud->step[4] + 0x1D > 0x1E)
        {
            w -= gHud->step[4];
            col = gHud->step[4];
        }
        x = gHud->step[4] + 0x15;
        if ((s16)w > 0)
        {
            cx = x;
            if ((s16)cx < 0)
                cx = 0;
            Tilemap_CopyRectSkipZero(&((const u16 *)gUnknown_081B8170)[row * 32 + col], gWindowTilemapBuffer,
                                     0, 0, cx, y, w, h);
            if (gHud->step[4] == 0)
                gHud->state[4] = 0;
        }
        sub_080C6764();
        if (--gHud->timer[4] == 0)
        {
            gHud->timer[4] = 1;
            gHud->step[4]--;
        }
    }
    if (gHud->state[4] != 3)
        sub_080C7664(x, y, gGameState.money);
}
#else
NAKED
void sub_080C76B4(void)
{
    asm_unified(
        ".L080C76B4:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x10\n"
        "    movs r6, #0\n"
        "    mov sb, r6\n"
        "    movs r7, #0x15\n"
        "    movs r0, #2\n"
        "    mov r8, r0\n"
        "    movs r5, #8\n"
        "    mov sl, r0\n"
        "    ldr r4, .L080C7700\n"
        "    ldrh r0, [r4, #8]\n"
        "    cmp r0, #1\n"
        "    bne .L080C7774\n"
        "    ldr r1, .L080C7704\n"
        "    movs r0, #0xa\n"
        "    str r0, [sp]\n"
        "    mov r0, r8\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r2, #0x15\n"
        "    movs r3, #2\n"
        "    bl Tilemap_FillRect\n"
        "    ldrh r1, [r4, #0x18]\n"
        "    adds r0, r1, #0\n"
        "    adds r0, #0x1c\n"
        "    cmp r0, #0x1e\n"
        "    ble .L080C7708\n"
        "    subs r0, r5, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    adds r6, r1, #0\n"
        "    adds r0, r6, #0\n"
        "    b .L080C770A\n"
        ".L080C7700: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
        ".L080C7704: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C7708:\n"
        "    adds r0, r1, #0\n"
        ".L080C770A:\n"
        "    adds r0, #0x15\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    cmp r5, #0\n"
        "    beq .L080C774C\n"
        "    ldr r3, .L080C7744\n"
        "    adds r2, r7, #0\n"
        "    mov r1, sb\n"
        "    lsls r0, r1, #5\n"
        "    adds r0, r0, r6\n"
        "    lsls r0, r0, #1\n"
        "    adds r3, r0, r3\n"
        "    lsls r0, r2, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L080C772A\n"
        "    movs r2, #0\n"
        ".L080C772A:\n"
        "    ldr r1, .L080C7748\n"
        "    str r2, [sp]\n"
        "    mov r0, r8\n"
        "    str r0, [sp, #4]\n"
        "    str r5, [sp, #8]\n"
        "    mov r0, sl\n"
        "    str r0, [sp, #0xc]\n"
        "    adds r0, r3, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Tilemap_CopyRectSkipZero\n"
        "    b .L080C7752\n"
        ".L080C7744: .4byte gUnknown_081B8170\n"
        ".L080C7748: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C774C:\n"
        "    ldr r1, .L080C7770\n"
        "    movs r0, #3\n"
        "    strh r0, [r1, #8]\n"
        ".L080C7752:\n"
        "    bl sub_080C6764\n"
        "    ldr r1, .L080C7770\n"
        "    ldrh r0, [r1, #0x28]\n"
        "    subs r0, #1\n"
        "    strh r0, [r1, #0x28]\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C780A\n"
        "    movs r0, #1\n"
        "    strh r0, [r1, #0x28]\n"
        "    ldrh r0, [r1, #0x18]\n"
        "    adds r0, #1\n"
        "    b .L080C7808\n"
        "    .byte 0x00, 0x00\n"
        ".L080C7770: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
        ".L080C7774:\n"
        "    cmp r0, #2\n"
        "    bne .L080C780A\n"
        "    ldr r1, .L080C77A4\n"
        "    movs r0, #0xa\n"
        "    str r0, [sp]\n"
        "    mov r0, r8\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r2, #0x15\n"
        "    movs r3, #2\n"
        "    bl Tilemap_FillRect\n"
        "    ldrh r1, [r4, #0x18]\n"
        "    adds r0, r1, #0\n"
        "    adds r0, #0x1d\n"
        "    cmp r0, #0x1e\n"
        "    ble .L080C77A8\n"
        "    subs r0, r5, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    adds r6, r1, #0\n"
        "    adds r0, r6, #0\n"
        "    b .L080C77AA\n"
        "    .byte 0x00, 0x00\n"
        ".L080C77A4: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C77A8:\n"
        "    adds r0, r1, #0\n"
        ".L080C77AA:\n"
        "    adds r0, #0x15\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    lsls r0, r5, #0x10\n"
        "    cmp r0, #0\n"
        "    ble .L080C77EE\n"
        "    ldr r3, .L080C7834\n"
        "    adds r2, r7, #0\n"
        "    mov r1, sb\n"
        "    lsls r0, r1, #5\n"
        "    adds r0, r0, r6\n"
        "    lsls r0, r0, #1\n"
        "    adds r3, r0, r3\n"
        "    lsls r0, r2, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L080C77CC\n"
        "    movs r2, #0\n"
        ".L080C77CC:\n"
        "    ldr r1, .L080C7838\n"
        "    str r2, [sp]\n"
        "    mov r0, r8\n"
        "    str r0, [sp, #4]\n"
        "    str r5, [sp, #8]\n"
        "    mov r0, sl\n"
        "    str r0, [sp, #0xc]\n"
        "    adds r0, r3, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Tilemap_CopyRectSkipZero\n"
        "    ldr r1, .L080C783C\n"
        "    ldrh r0, [r1, #0x18]\n"
        "    cmp r0, #0\n"
        "    bne .L080C77EE\n"
        "    strh r0, [r1, #8]\n"
        ".L080C77EE:\n"
        "    bl sub_080C6764\n"
        "    ldr r1, .L080C783C\n"
        "    ldrh r0, [r1, #0x28]\n"
        "    subs r0, #1\n"
        "    strh r0, [r1, #0x28]\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C780A\n"
        "    movs r0, #1\n"
        "    strh r0, [r1, #0x28]\n"
        "    ldrh r0, [r1, #0x18]\n"
        "    subs r0, #1\n"
        ".L080C7808:\n"
        "    strh r0, [r1, #0x18]\n"
        ".L080C780A:\n"
        "    ldr r0, .L080C783C\n"
        "    ldrh r0, [r0, #8]\n"
        "    cmp r0, #3\n"
        "    beq .L080C7822\n"
        "    ldr r0, .L080C7840\n"
        "    ldr r1, .L080C7844\n"
        "    adds r0, r0, r1\n"
        "    ldr r2, [r0]\n"
        "    adds r0, r7, #0\n"
        "    mov r1, r8\n"
        "    bl sub_080C7664\n"
        ".L080C7822:\n"
        "    add sp, #0x10\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080C7834: .4byte gUnknown_081B8170\n"
        ".L080C7838: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C783C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
        ".L080C7840: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080C7844: .4byte 0x00000AD8\n"
    );
}
#endif

// sub_080C7848 @ 0x080C7848
void sub_080C7848(void)
{
    struct C0c6Hud *hud = gHud;

    if (hud->state[6] == 0)
    {
        hud->state[6] = 1;
        hud->step[6] = 0;
        hud->timer[6] = 1;
    }
}

// sub_080C7864 @ 0x080C7864
void sub_080C7864(void)
{
    if (gHud->state[6] == 3)
    {
        gHud->state[6] = 2;
        gHud->timer[6] = 1;
    }
}

// sub_080C7880 @ 0x080C7880
/* The compass panel (6x6 at column 22) slides in from the right; the four direction letters
   are drawn rotated by the automap rotation (sub_080B447C). */
#ifdef NONMATCHING
void sub_080C7880(void)
{
    u16 col = 0;
    u16 row = 0;
    u16 x = 0x16;
    u16 y = 0;
    u16 w = 6;
    u16 h = 6;
    u16 rot;
    u16 cx;

    if (gHud->state[6] == 1)
    {
        Tilemap_FillRect(0, gWindowTilemapBuffer, 0x16, 0, 8, h);
        if (gHud->step[6] + 0x1C > 0x1E)
        {
            w -= gHud->step[6];
            col = gHud->step[6];
        }
        x = gHud->step[6] + 0x16;
        if (w != 0)
        {
            cx = x;
            if ((s16)cx < 0)
                cx = 0;
            Tilemap_CopyRectSkipZero(&((const u16 *)gUnknown_081B7170)[row * 32 + col], gWindowTilemapBuffer,
                                     0, 0, cx, y, w, h);
        }
        else
            gHud->state[6] = 3;
        sub_080C6764();
        if (--gHud->timer[6] == 0)
        {
            gHud->timer[6] = 1;
            gHud->step[6]++;
        }
    }
    else if (gHud->state[6] == 2)
    {
        Tilemap_FillRect(0, gWindowTilemapBuffer, 0x16, 0, 8, h);
        if (gHud->step[6] + 0x1C > 0x1E)
        {
            w -= gHud->step[6];
            col = gHud->step[6];
        }
        x = gHud->step[6] + 0x16;
        if ((s16)w > 0)
        {
            cx = x;
            if ((s16)cx < 0)
                cx = 0;
            Tilemap_CopyRectSkipZero(&((const u16 *)gUnknown_081B7170)[row * 32 + col], gWindowTilemapBuffer,
                                     0, 0, cx, y, w, h);
            if (gHud->step[6] == 0)
                gHud->state[6] = 0;
        }
        sub_080C6764();
        if (--gHud->timer[6] == 0)
        {
            gHud->timer[6] = 1;
            gHud->step[6]--;
        }
    }
    if (gHud->state[6] != 3)
    {
        rot = sub_080B447C();
        Sprite_Draw(gUnknown_08000A74, 1, 0, 1, 0, x * 8 + 0xC, 0xA);
        Sprite_Draw(gUnknown_0834A3CC[rot & 3], 1, 0, 1, 0, x * 8 + 0x16, 6);
        Sprite_Draw(gUnknown_0834A3CC[(rot + 1) & 3], 1, 0, 1, 0, x * 8 + 0x22, 0x12);
        Sprite_Draw(gUnknown_0834A3CC[(rot + 2) & 3], 1, 0, 1, 0, x * 8 + 0x16, 0x1E);
        Sprite_Draw(gUnknown_0834A3CC[(rot + 3) & 3], 1, 0, 1, 0, x * 8 + 0xA, 0x12);
    }
}
#else
NAKED
void sub_080C7880(void)
{
    asm_unified(
        ".L080C7880:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x10\n"
        "    movs r6, #0\n"
        "    mov sl, r6\n"
        "    movs r5, #0x16\n"
        "    mov sb, r6\n"
        "    movs r7, #6\n"
        "    movs r0, #6\n"
        "    mov r8, r0\n"
        "    ldr r4, .L080C78D0\n"
        "    ldrh r0, [r4, #0xc]\n"
        "    cmp r0, #1\n"
        "    bne .L080C7944\n"
        "    ldr r1, .L080C78D4\n"
        "    movs r0, #8\n"
        "    str r0, [sp]\n"
        "    mov r2, r8\n"
        "    str r2, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r2, #0x16\n"
        "    movs r3, #0\n"
        "    bl Tilemap_FillRect\n"
        "    ldrh r1, [r4, #0x1c]\n"
        "    adds r0, r1, #0\n"
        "    adds r0, #0x1c\n"
        "    cmp r0, #0x1e\n"
        "    ble .L080C78D8\n"
        "    mov r2, r8\n"
        "    subs r0, r2, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r6, r1, #0\n"
        "    adds r0, r6, #0\n"
        "    b .L080C78DA\n"
        "    .byte 0x00, 0x00\n"
        ".L080C78D0: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
        ".L080C78D4: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C78D8:\n"
        "    adds r0, r1, #0\n"
        ".L080C78DA:\n"
        "    adds r0, #0x16\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r7, #0\n"
        "    beq .L080C791C\n"
        "    ldr r3, .L080C7914\n"
        "    adds r2, r5, #0\n"
        "    mov r1, sl\n"
        "    lsls r0, r1, #5\n"
        "    adds r0, r0, r6\n"
        "    lsls r0, r0, #1\n"
        "    adds r3, r0, r3\n"
        "    lsls r0, r2, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L080C78FA\n"
        "    movs r2, #0\n"
        ".L080C78FA:\n"
        "    ldr r1, .L080C7918\n"
        "    str r2, [sp]\n"
        "    mov r2, sb\n"
        "    str r2, [sp, #4]\n"
        "    str r7, [sp, #8]\n"
        "    mov r0, r8\n"
        "    str r0, [sp, #0xc]\n"
        "    adds r0, r3, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Tilemap_CopyRectSkipZero\n"
        "    b .L080C7922\n"
        ".L080C7914: .4byte gUnknown_081B7170\n"
        ".L080C7918: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C791C:\n"
        "    ldr r1, .L080C7940\n"
        "    movs r0, #3\n"
        "    strh r0, [r1, #0xc]\n"
        ".L080C7922:\n"
        "    bl sub_080C6764\n"
        "    ldr r1, .L080C7940\n"
        "    ldrh r0, [r1, #0x2c]\n"
        "    subs r0, #1\n"
        "    strh r0, [r1, #0x2c]\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C79DA\n"
        "    movs r0, #1\n"
        "    strh r0, [r1, #0x2c]\n"
        "    ldrh r0, [r1, #0x1c]\n"
        "    adds r0, #1\n"
        "    b .L080C79D8\n"
        "    .byte 0x00, 0x00\n"
        ".L080C7940: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
        ".L080C7944:\n"
        "    cmp r0, #2\n"
        "    bne .L080C79DA\n"
        "    ldr r1, .L080C7974\n"
        "    movs r0, #8\n"
        "    str r0, [sp]\n"
        "    mov r2, r8\n"
        "    str r2, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r2, #0x16\n"
        "    movs r3, #0\n"
        "    bl Tilemap_FillRect\n"
        "    ldrh r1, [r4, #0x1c]\n"
        "    adds r0, r1, #0\n"
        "    adds r0, #0x1c\n"
        "    cmp r0, #0x1e\n"
        "    ble .L080C7978\n"
        "    mov r2, r8\n"
        "    subs r0, r2, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r6, r1, #0\n"
        "    adds r0, r6, #0\n"
        "    b .L080C797A\n"
        ".L080C7974: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C7978:\n"
        "    adds r0, r1, #0\n"
        ".L080C797A:\n"
        "    adds r0, #0x16\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    lsls r0, r7, #0x10\n"
        "    cmp r0, #0\n"
        "    ble .L080C79BE\n"
        "    ldr r3, .L080C7AB8\n"
        "    adds r2, r5, #0\n"
        "    mov r1, sl\n"
        "    lsls r0, r1, #5\n"
        "    adds r0, r0, r6\n"
        "    lsls r0, r0, #1\n"
        "    adds r3, r0, r3\n"
        "    lsls r0, r2, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L080C799C\n"
        "    movs r2, #0\n"
        ".L080C799C:\n"
        "    ldr r1, .L080C7ABC\n"
        "    str r2, [sp]\n"
        "    mov r2, sb\n"
        "    str r2, [sp, #4]\n"
        "    str r7, [sp, #8]\n"
        "    mov r0, r8\n"
        "    str r0, [sp, #0xc]\n"
        "    adds r0, r3, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Tilemap_CopyRectSkipZero\n"
        "    ldr r1, .L080C7AC0\n"
        "    ldrh r0, [r1, #0x1c]\n"
        "    cmp r0, #0\n"
        "    bne .L080C79BE\n"
        "    strh r0, [r1, #0xc]\n"
        ".L080C79BE:\n"
        "    bl sub_080C6764\n"
        "    ldr r1, .L080C7AC0\n"
        "    ldrh r0, [r1, #0x2c]\n"
        "    subs r0, #1\n"
        "    strh r0, [r1, #0x2c]\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C79DA\n"
        "    movs r0, #1\n"
        "    strh r0, [r1, #0x2c]\n"
        "    ldrh r0, [r1, #0x1c]\n"
        "    subs r0, #1\n"
        ".L080C79D8:\n"
        "    strh r0, [r1, #0x1c]\n"
        ".L080C79DA:\n"
        "    ldr r0, .L080C7AC0\n"
        "    ldrh r0, [r0, #0xc]\n"
        "    cmp r0, #3\n"
        "    beq .L080C7AA6\n"
        "    bl sub_080B447C\n"
        "    adds r4, r0, #0\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    ldr r0, .L080C7AC4\n"
        "    movs r1, #0\n"
        "    mov sb, r1\n"
        "    str r1, [sp]\n"
        "    lsls r7, r5, #3\n"
        "    adds r1, r7, #0\n"
        "    adds r1, #0xc\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #0xa\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #1\n"
        "    movs r2, #0\n"
        "    movs r3, #1\n"
        "    bl Sprite_Draw\n"
        "    ldr r2, .L080C7AC8\n"
        "    mov r8, r2\n"
        "    movs r6, #3\n"
        "    adds r0, r4, #0\n"
        "    ands r0, r6\n"
        "    lsls r0, r0, #2\n"
        "    add r0, r8\n"
        "    ldr r0, [r0]\n"
        "    mov r1, sb\n"
        "    str r1, [sp]\n"
        "    adds r5, r7, #0\n"
        "    adds r5, #0x16\n"
        "    lsls r5, r5, #0x10\n"
        "    lsrs r5, r5, #0x10\n"
        "    str r5, [sp, #4]\n"
        "    movs r1, #6\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #1\n"
        "    movs r2, #0\n"
        "    movs r3, #1\n"
        "    bl Sprite_Draw\n"
        "    adds r0, r4, #1\n"
        "    ands r0, r6\n"
        "    lsls r0, r0, #2\n"
        "    add r0, r8\n"
        "    ldr r0, [r0]\n"
        "    mov r2, sb\n"
        "    str r2, [sp]\n"
        "    adds r1, r7, #0\n"
        "    adds r1, #0x22\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #0x12\n"
        "    mov sl, r1\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #1\n"
        "    movs r2, #0\n"
        "    movs r3, #1\n"
        "    bl Sprite_Draw\n"
        "    adds r0, r4, #2\n"
        "    ands r0, r6\n"
        "    lsls r0, r0, #2\n"
        "    add r0, r8\n"
        "    ldr r0, [r0]\n"
        "    mov r2, sb\n"
        "    str r2, [sp]\n"
        "    str r5, [sp, #4]\n"
        "    movs r1, #0x1e\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #1\n"
        "    movs r2, #0\n"
        "    movs r3, #1\n"
        "    bl Sprite_Draw\n"
        "    adds r4, #3\n"
        "    ands r4, r6\n"
        "    lsls r4, r4, #2\n"
        "    add r4, r8\n"
        "    ldr r0, [r4]\n"
        "    mov r1, sb\n"
        "    str r1, [sp]\n"
        "    adds r1, r7, #0\n"
        "    adds r1, #0xa\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #4]\n"
        "    mov r2, sl\n"
        "    str r2, [sp, #8]\n"
        "    movs r1, #1\n"
        "    movs r2, #0\n"
        "    movs r3, #1\n"
        "    bl Sprite_Draw\n"
        ".L080C7AA6:\n"
        "    add sp, #0x10\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080C7AB8: .4byte gUnknown_081B7170\n"
        ".L080C7ABC: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C7AC0: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
        ".L080C7AC4: .4byte gUnknown_08000A74\n"
        ".L080C7AC8: .4byte gUnknown_0834A3CC\n"
    );
}
#endif

// sub_080C7ACC @ 0x080C7ACC
void sub_080C7ACC(void)
{
    struct C0c6Hud *hud = gHud;

    hud->state[7] = 1;
    hud->step[7] = 0;
    hud->timer[7] = 1;
}

// sub_080C7AE0 @ 0x080C7AE0
void sub_080C7AE0(void)
{
    struct C0c6Hud *hud = gHud;

    hud->state[7] = 2;
    hud->timer[7] = 1;
}

// sub_080C7AF0 @ 0x080C7AF0
u16 sub_080C7AF0(void)
{
    return gHud->state[7];
}

// sub_080C7AFC @ 0x080C7AFC
/* Panel 7 (6x8 at column 23, row 3, tilemap gUnknown_0834A3DC) slides in from the right. */
#ifdef NONMATCHING
void sub_080C7AFC(void)
{
    u16 col = 0;
    u16 row = 0;
    u16 y = 3;
    u16 w = 6;
    u16 h = 8;
    u16 x;

    if (gHud->state[7] == 1)
    {
        Tilemap_FillRect(0, gWindowTilemapBuffer, 0x17, 3, 8, h);
        if (gHud->step[7] + 0x1D > 0x1E)
        {
            w -= gHud->step[7];
            col = gHud->step[7];
        }
        x = gHud->step[7] + 0x17;
        if (w != 0)
        {
            if ((s16)x < 0)
                x = 0;
            Tilemap_CopyRectSkipZero(&gUnknown_0834A3DC[row * 32 + col], gWindowTilemapBuffer, 0, 0, x, y, w, h);
        }
        else
            gHud->state[7] = 3;
        sub_080C6764();
        if (--gHud->timer[7] == 0)
        {
            gHud->timer[7] = 1;
            gHud->step[7]++;
        }
    }
    else if (gHud->state[7] == 2)
    {
        Tilemap_FillRect(0, gWindowTilemapBuffer, 0x17, 3, 8, h);
        if (gHud->step[7] + 0x1D > 0x1E)
        {
            w -= gHud->step[7];
            col = gHud->step[7];
        }
        x = gHud->step[7] + 0x17;
        if ((s16)w > 0)
        {
            if ((s16)x < 0)
                x = 0;
            Tilemap_CopyRectSkipZero(&gUnknown_0834A3DC[row * 32 + col], gWindowTilemapBuffer, 0, 0, x, y, w, h);
            if (gHud->step[7] == 0)
                gHud->state[7] = 0;
        }
        sub_080C6764();
        if (--gHud->timer[7] == 0)
        {
            gHud->timer[7] = 1;
            gHud->step[7]--;
        }
    }
}
#else
NAKED
void sub_080C7AFC(void)
{
    asm_unified(
        ".L080C7AFC:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sb\n"
        "    mov r6, r8\n"
        "    push {r6, r7}\n"
        "    sub sp, #0x10\n"
        "    movs r6, #0\n"
        "    mov r8, r6\n"
        "    movs r0, #3\n"
        "    mov sb, r0\n"
        "    movs r5, #6\n"
        "    movs r7, #8\n"
        "    ldr r4, .L080C7B40\n"
        "    ldrh r0, [r4, #0xe]\n"
        "    cmp r0, #1\n"
        "    bne .L080C7BB4\n"
        "    ldr r1, .L080C7B44\n"
        "    str r7, [sp]\n"
        "    str r7, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r2, #0x17\n"
        "    movs r3, #3\n"
        "    bl Tilemap_FillRect\n"
        "    ldrh r1, [r4, #0x1e]\n"
        "    adds r0, r1, #0\n"
        "    adds r0, #0x1d\n"
        "    cmp r0, #0x1e\n"
        "    ble .L080C7B48\n"
        "    subs r0, r5, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    adds r6, r1, #0\n"
        "    adds r0, r6, #0\n"
        "    b .L080C7B4A\n"
        ".L080C7B40: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
        ".L080C7B44: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C7B48:\n"
        "    adds r0, r1, #0\n"
        ".L080C7B4A:\n"
        "    adds r0, #0x17\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    cmp r5, #0\n"
        "    beq .L080C7B8C\n"
        "    ldr r3, .L080C7B84\n"
        "    adds r2, r1, #0\n"
        "    mov r1, r8\n"
        "    lsls r0, r1, #5\n"
        "    adds r0, r0, r6\n"
        "    lsls r0, r0, #1\n"
        "    adds r3, r0, r3\n"
        "    lsls r0, r2, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L080C7B6A\n"
        "    movs r2, #0\n"
        ".L080C7B6A:\n"
        "    ldr r1, .L080C7B88\n"
        "    str r2, [sp]\n"
        "    mov r0, sb\n"
        "    str r0, [sp, #4]\n"
        "    str r5, [sp, #8]\n"
        "    str r7, [sp, #0xc]\n"
        "    adds r0, r3, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Tilemap_CopyRectSkipZero\n"
        "    b .L080C7B92\n"
        "    .byte 0x00, 0x00\n"
        ".L080C7B84: .4byte gUnknown_0834A3DC\n"
        ".L080C7B88: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C7B8C:\n"
        "    ldr r1, .L080C7BB0\n"
        "    movs r0, #3\n"
        "    strh r0, [r1, #0xe]\n"
        ".L080C7B92:\n"
        "    bl sub_080C6764\n"
        "    ldr r1, .L080C7BB0\n"
        "    ldrh r0, [r1, #0x2e]\n"
        "    subs r0, #1\n"
        "    strh r0, [r1, #0x2e]\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C7C44\n"
        "    movs r0, #1\n"
        "    strh r0, [r1, #0x2e]\n"
        "    ldrh r0, [r1, #0x1e]\n"
        "    adds r0, #1\n"
        "    b .L080C7C42\n"
        "    .byte 0x00, 0x00\n"
        ".L080C7BB0: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
        ".L080C7BB4:\n"
        "    cmp r0, #2\n"
        "    bne .L080C7C44\n"
        "    ldr r1, .L080C7BE0\n"
        "    str r7, [sp]\n"
        "    str r7, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r2, #0x17\n"
        "    movs r3, #3\n"
        "    bl Tilemap_FillRect\n"
        "    ldrh r1, [r4, #0x1e]\n"
        "    adds r0, r1, #0\n"
        "    adds r0, #0x1d\n"
        "    cmp r0, #0x1e\n"
        "    ble .L080C7BE4\n"
        "    subs r0, r5, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    adds r6, r1, #0\n"
        "    adds r0, r6, #0\n"
        "    b .L080C7BE6\n"
        "    .byte 0x00, 0x00\n"
        ".L080C7BE0: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C7BE4:\n"
        "    adds r0, r1, #0\n"
        ".L080C7BE6:\n"
        "    adds r0, #0x17\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    lsls r0, r5, #0x10\n"
        "    cmp r0, #0\n"
        "    ble .L080C7C28\n"
        "    ldr r3, .L080C7C54\n"
        "    adds r2, r1, #0\n"
        "    mov r1, r8\n"
        "    lsls r0, r1, #5\n"
        "    adds r0, r0, r6\n"
        "    lsls r0, r0, #1\n"
        "    adds r3, r0, r3\n"
        "    lsls r0, r2, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L080C7C08\n"
        "    movs r2, #0\n"
        ".L080C7C08:\n"
        "    ldr r1, .L080C7C58\n"
        "    str r2, [sp]\n"
        "    mov r0, sb\n"
        "    str r0, [sp, #4]\n"
        "    str r5, [sp, #8]\n"
        "    str r7, [sp, #0xc]\n"
        "    adds r0, r3, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Tilemap_CopyRectSkipZero\n"
        "    ldr r1, .L080C7C5C\n"
        "    ldrh r0, [r1, #0x1e]\n"
        "    cmp r0, #0\n"
        "    bne .L080C7C28\n"
        "    strh r0, [r1, #0xe]\n"
        ".L080C7C28:\n"
        "    bl sub_080C6764\n"
        "    ldr r1, .L080C7C5C\n"
        "    ldrh r0, [r1, #0x2e]\n"
        "    subs r0, #1\n"
        "    strh r0, [r1, #0x2e]\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C7C44\n"
        "    movs r0, #1\n"
        "    strh r0, [r1, #0x2e]\n"
        "    ldrh r0, [r1, #0x1e]\n"
        "    subs r0, #1\n"
        ".L080C7C42:\n"
        "    strh r0, [r1, #0x1e]\n"
        ".L080C7C44:\n"
        "    add sp, #0x10\n"
        "    pop {r3, r4}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080C7C54: .4byte gUnknown_0834A3DC\n"
        ".L080C7C58: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C7C5C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
    );
}
#endif

// sub_080C7C60 @ 0x080C7C60
void sub_080C7C60(void)
{
    struct C0c6Hud *hud = gHud;

    hud->unk30 = 1;
    hud->state[5] = 3;
    Tilemap_FillRect(0, gWindowTilemapBuffer, 3, 0xC, 0x18, 1);
    sub_080C6764();
}

// sub_080C7C94 @ 0x080C7C94
void sub_080C7C94(void)
{
    struct C0c6Hud *hud = gHud;

    hud->unk30 = 0;
    hud->state[5] = 0;
    sub_080C6558();
    sub_080C6764();
}

// sub_080C7CB0 @ 0x080C7CB0
void sub_080C7CB0(void)
{
    gUnk_0203A44E = 0;
}

// sub_080C7CBC @ 0x080C7CBC
void sub_080C7CBC(void)
{
    gUnk_0203A44E = 1;
}

// sub_080C7CC8 @ 0x080C7CC8
void sub_080C7CC8(void)
{
    sub_080C7CBC();
    Hud_UploadMoonTiles();
}
