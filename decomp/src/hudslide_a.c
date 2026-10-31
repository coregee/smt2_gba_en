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
   wide; first visible column col, row row) to (x, y) and queues the upload. The position update
   is written in both arms of an if/else: the join label ends cse's block, so col/row/x/y are
   not known constants at the copy (they stay in registers and row * 32 is not folded). */

// Hud_SlidePartyPanel @ 0x080C7070
/* The party panel (top left, 7x3) slides in from the left. */
void Hud_SlidePartyPanel(u16 *state, u16 *timer, u16 *step)
{
    u16 col = 0;
    u16 row = 0;
    u16 x = 1;
    u16 w = 7;
    u16 h = 3;
    u16 cx;
    const u16 *src;

    if (*state == 1)
    {
        Tilemap_FillRect(0, gWindowTilemapBuffer, 0, 0, 8, h);
        if (x < *step)
        {
            w -= (u16)(*step - 1);
            col = *step - 1;
            x -= *step;
        }
        else
            x -= *step;
        if (w != 0)
        {
            src = (const u16 *)gUnknown_081B8270;
            cx = x;
            src += row * 32 + col;
            if ((s16)cx <= -1)
                cx = 0;
            Tilemap_CopyRectSkipZero(src, gWindowTilemapBuffer,
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
            w -= (u16)(*step - 1);
            col = *step - 1;
            x -= *step;
        }
        else
            x -= *step;
        if ((s16)w > 0)
        {
            src = (const u16 *)gUnknown_081B8270;
            cx = x;
            src += row * 32 + col;
            if ((s16)cx <= -1)
                cx = 0;
            Tilemap_CopyRectSkipZero(src, gWindowTilemapBuffer,
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
    cx = 0; /* dead store (deleted by flow): makes cx, not x, what cse tests in the clamps */
}

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
void sub_080C726C(void)
{
    u16 col = 0;
    u16 row = 0;
    u16 x = 0xD;
    u16 y = 0;
    u16 w = 4;
    u16 h = 2;
    u16 cy;
    const u16 *src;

    if (gHud->state[2] == 1)
    {
        Tilemap_FillRect(0, gWindowTilemapBuffer, 0xD, 0, w, h);
        if (y < gHud->step[2])
        {
            h -= gHud->step[2];
            row = y + gHud->step[2];
            y -= gHud->step[2];
        }
        else
            y -= gHud->step[2];
        if (h != 0)
        {
            src = (const u16 *)gUnknown_081B92B0;
            cy = y;
            src += row * 32 + col;
            if ((s16)cy < 0)
                cy = 0;
            Tilemap_CopyRectSkipZero(src, gWindowTilemapBuffer,
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
            row = y + gHud->step[2];
            y -= gHud->step[2];
        }
        else
            y -= gHud->step[2];
        if ((s16)h > 0)
        {
            src = (const u16 *)gUnknown_081B92B0;
            cy = y;
            src += row * 32 + col;
            if ((s16)cy < 0)
                cy = 0;
            Tilemap_CopyRectSkipZero(src, gWindowTilemapBuffer,
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
    /* Dead store: needed to match. It keeps cy live to the end, which makes cse use cy
       (not y) as the canonical register of the pair, so the clamp tests cy. */
    cy = 0;
}

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
    const u16 *src;

    if (gHud->state[3] == 1)
    {
        Tilemap_FillRect(0, gWindowTilemapBuffer, 0x15, 0, 9, h);
        if (gHud->step[3] + 0x1D > 0x1E)
        {
            w -= gHud->step[3];
            col = gHud->step[3];
            x += gHud->step[3];
        }
        else
            x += gHud->step[3];
        if (w != 0)
        {
            src = (const u16 *)gUnknown_081B8170;
            cx = x;
            src += row * 32 + col;
            if ((s16)cx <= -1)
                cx = 0;
            Tilemap_CopyRectSkipZero(src, gWindowTilemapBuffer,
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
            x += gHud->step[3];
        }
        else
            x += gHud->step[3];
        if ((s16)w > 0)
        {
            src = (const u16 *)gUnknown_081B8170;
            cx = x;
            src += row * 32 + col;
            if ((s16)cx <= -1)
                cx = 0;
            Tilemap_CopyRectSkipZero(src, gWindowTilemapBuffer,
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
        Sprite_Draw(gUnknown_080007FC, 0, pal, 0, 0, x * 8 + 2, y + 5);
        sub_080C7FD0(Magnetite_Get(), x * 8 + 8, y + 5, 0, pal);
    }
    /* Dead store: keeps cx live to the end so that cse tests cx, not x, in the clamp. */
    cx = 0;
}

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
void sub_080C76B4(void)
{
    u16 col = 0;
    u16 row = 0;
    u16 x = 0x15;
    u16 y = 2;
    u16 w = 8;
    u16 h = 2;
    u16 cx;
    const u16 *src;

    if (gHud->state[4] == 1)
    {
        Tilemap_FillRect(0, gWindowTilemapBuffer, 0x15, 2, 10, y);
        /* sliding in tests > 2, sliding out > 1 */
        if (gHud->step[4] + 0x1C > 0x1E)
        {
            w -= gHud->step[4];
            col = gHud->step[4];
            x += gHud->step[4];
        }
        else
            x += gHud->step[4];
        if (w != 0)
        {
            src = (const u16 *)gUnknown_081B8170;
            cx = x;
            src += row * 32 + col;
            if ((s16)cx <= -1)
                cx = 0;
            Tilemap_CopyRectSkipZero(src, gWindowTilemapBuffer,
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
            x += gHud->step[4];
        }
        else
            x += gHud->step[4];
        if ((s16)w > 0)
        {
            src = (const u16 *)gUnknown_081B8170;
            cx = x;
            src += row * 32 + col;
            if ((s16)cx <= -1)
                cx = 0;
            Tilemap_CopyRectSkipZero(src, gWindowTilemapBuffer,
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
    /* Dead store: keeps cx live to the end so that cse tests cx, not x, in the clamp. */
    cx = 0;
}

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
    const u16 *src;

    if (gHud->state[6] == 1)
    {
        Tilemap_FillRect(0, gWindowTilemapBuffer, 0x16, 0, 8, h);
        if (gHud->step[6] + 0x1C > 0x1E)
        {
            w -= gHud->step[6];
            col = gHud->step[6];
            x += gHud->step[6];
        }
        else
            x += gHud->step[6];
        if (w != 0)
        {
            src = (const u16 *)gUnknown_081B7170;
            cx = x;
            src += row * 32 + col;
            if ((s16)cx < 0)
                cx = 0;
            Tilemap_CopyRectSkipZero(src, gWindowTilemapBuffer,
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
            x += gHud->step[6];
        }
        else
            x += gHud->step[6];
        if ((s16)w > 0)
        {
            src = (const u16 *)gUnknown_081B7170;
            cx = x;
            src += row * 32 + col;
            if ((s16)cx < 0)
                cx = 0;
            Tilemap_CopyRectSkipZero(src, gWindowTilemapBuffer,
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
        /* Only this y is written relative to the panel row (y = 0): the reference gives y the
           register priority the original has (sb, with row in sl). */
        Sprite_Draw(gUnknown_08000A74, 1, 0, 1, 0, x * 8 + 0xC, y + 0xA);
        Sprite_Draw(gUnknown_0834A3CC[rot & 3], 1, 0, 1, 0, x * 8 + 0x16, 6);
        Sprite_Draw(gUnknown_0834A3CC[(rot + 1) & 3], 1, 0, 1, 0, x * 8 + 0x22, 0x12);
        Sprite_Draw(gUnknown_0834A3CC[(rot + 2) & 3], 1, 0, 1, 0, x * 8 + 0x16, 0x1E);
        Sprite_Draw(gUnknown_0834A3CC[(rot + 3) & 3], 1, 0, 1, 0, x * 8 + 0xA, 0x12);
    }
    /* Dead store: keeps cx live to the end so that cse tests cx, not x, in the clamp. */
    cx = 0;
}

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
void sub_080C7AFC(void)
{
    u16 col = 0;
    u16 row = 0;
    u16 y = 3;
    u16 w = 6;
    u16 h = 8;
    u16 x = 0x17;
    u16 cx;
    const u16 *src;

    if (gHud->state[7] == 1)
    {
        Tilemap_FillRect(0, gWindowTilemapBuffer, 0x17, 3, 8, h);
        if (gHud->step[7] + 0x1D > 0x1E)
        {
            w -= gHud->step[7];
            col = gHud->step[7];
            x += gHud->step[7];
        }
        else
            x += gHud->step[7];
        if (w != 0)
        {
            src = gUnknown_0834A3DC;
            cx = x;
            src += row * 32 + col;
            if ((s16)cx < 0)
                cx = 0;
            Tilemap_CopyRectSkipZero(src, gWindowTilemapBuffer, 0, 0, cx, y, w, h);
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
            x += gHud->step[7];
        }
        else
            x += gHud->step[7];
        if ((s16)w > 0)
        {
            src = gUnknown_0834A3DC;
            cx = x;
            src += row * 32 + col;
            if ((s16)cx < 0)
                cx = 0;
            Tilemap_CopyRectSkipZero(src, gWindowTilemapBuffer, 0, 0, cx, y, w, h);
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
