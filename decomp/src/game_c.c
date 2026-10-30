/* Field helpers after the field main loop. */

#include "global.h"
#include "game.h"

// sub_080B1A1C @ 0x080B1A1C
u16 sub_080B1A1C(u16 a)
{
    return gUnknown_0815F2FC[a][1];
}

// sub_080B1A30 @ 0x080B1A30
void sub_080B1A30(u16 a, u16 b)
{
    gFieldState.unk0A = a;
    sub_080B2030(a, b, 3);
}

// sub_080B1A4C @ 0x080B1A4C
void sub_080B1A4C(u16 a, u16 b)
{
    s32 r = View_IsSideOpen(2);
    u16 saved;

    if (r == 1)
    {
        sub_080B09C4(0, 1);
        Field_Step(a);
        sub_080B2840(1, 0, 0);
        gFieldState.unk08 = r;
        gFieldState.unk3E = 0;
    }
    else if (b == 1)
    {
        Task_Create(gUnknown_08165380, 0xFFFF);
        Field_SetState(0x1A);
        return;
    }
    else
    {
        gFieldState.unk08 = 0;
        Sound_Play(0x69);
        gFieldState.unk3E = 1;
    }
    gFieldState.unk1E = 12;
    gFieldState.unk06 = a;
    saved = gUnk_03003FF4;
    Field_SetState(5);
    gUnk_03003FF4 = saved;
}

// sub_080B1AD8 @ 0x080B1AD8
void sub_080B1AD8(u16 a, u16 b)
{
    struct Unk03004550 *s = &gFieldState;
    s32 r = View_GetWall(0, 0, 0);

    if (r == 3)
    {
        sub_080B1A30(a, b);
    }
    else if (r == 2)
    {
        s->unk0A = a;
        sub_080B2030(a, b, 3);
    }
    else
    {
        s->unk0A = a;
        sub_080B2030(a, b, 2);
    }
    if (r != 1)
        gFieldState.unk3E = 0;
    else
        gFieldState.unk3E = r;
}

// sub_080B1B58 @ 0x080B1B58
s32 sub_080B1B58(void)
{
    if (sub_080C8AF8(gUnk_03004614) == 1 && gHudState[2] != 0)
        return 0;
    if (sub_080C8AF8(gUnk_03004614) == 1 && gHudState[0] != 0)
        return 0;
    if (sub_080C8AF8(gUnk_03004614) == 1 && gHudState[3] != 0)
        return 0;
    if (sub_080B78A4() != 0)
        return 0;
    if (Palette_IsBg13Black() == 1)
        return 0;
    if (PalFade_AllDone() == 0)
        return 0;
    return 1;
}

// sub_080B1BC4 @ 0x080B1BC4
void sub_080B1BC4(void)
{
    Field_SetState(10);
    gUnk_03003BB8 = 0;
}

// sub_080B1BDC @ 0x080B1BDC
void sub_080B1BDC(void)
{
    if (sub_080B953C() == 1)
    {
        sub_080AD6E4(0);
        gFieldState.unk1E = 0;
        gFieldState.unk2E = 0x22;
        sub_080C7218();
        sub_080C6FF0();
        sub_080C7414();
    }
    else if (sub_080F3190() != 0)
    {
        sub_0812A730();
    }
}

/* NONMATCHING: keys stays in a stack slot and unk3A is reloaded in the original; registers differ. */
// Field_HandleInput @ 0x080B1C18
/* Field input: events under the player, menu/map keys, then movement from the D-pad. */
/* keys is volatile in the original: it is kept on the stack and re-read at every test. The
   first read of gFieldState.unk3A is volatile too (the later one is a fresh load). */
void Field_HandleInput(vu16 keys)
{
    u16 dest = 0xFFFF;
    u16 dir = gFieldState.unk02;
    u16 move = 0;
    u8 stairs = FALSE;
    struct FieldEvent *ev;
    u16 id;
    u16 unused;
    u32 r;

    Automap_SetVisited(gFieldState.unk12, gFieldState.unk14);
    if (gFieldState.unk40 == 0 && gFieldState.unk3E == 0
        && (ev = FieldEvent_FindAt(gFieldState.unk12, gFieldState.unk14, gFieldState.unk02, &id)) != NULL
        && id != 0xFFFF
        && sub_080C2480(id) == 1
        && sub_080AF0AC(ev->script) != 0)
    {
        gFieldState.unk40 = sub_080B828C();
        return;
    }
    if ((r = sub_080B1B58()) == 1)
    {
        if (((volatile struct Unk03004550 *)&gFieldState)->unk3A & 1)
        {
            if (gFieldState.unk40 != 0)
            {
                if (*(u16 *)(gFieldState.unk40 + 0x1E) != 0)
                {
                    struct FieldEvent *ev2 = FieldEvent_FindAt(gFieldState.unk12, gFieldState.unk14, gFieldState.unk02, &unused);
                    sub_080AF7E8(ev2, ev2, 0);
                }
            }
            else if (!Flag_Test(0xAE))
            {
                sub_08128B84(0);
                Field_SetState(10);
            }
            return;
        }
        if ((gFieldState.unk3A & 8) && sub_080B9568() == 1)
        {
            Sound_Play(0x67);
            sub_0812D0FC(0);
            Field_SetState(10);
            gUnk_03003BB8 = 0;
            if (FieldMap_HasRecordRel(0, 0, 6) != 1)
            {
                gUnk_0300452C = PalFade_FadeRangeToBlackWithDuration(0xD0, 0x30, 4, 4);
                if (gPaletteBuffer[0] != 0)
                    PalFade_FadeRangeToBlackWithDuration(0, 1, 4, 4);
            }
            return;
        }
        if (gFieldState.unk3A & 0x100)
        {
            if (sub_0812A730() != 0)
            {
                if (sub_080F3190() == 0)
                    Sound_Play(0x65);
                sub_080B1BC4();
            }
            return;
        }
    }
    if ((BattleFlags_Get() & 0x100) && gFieldState.unk58 == 0)
        gFieldState.unk58 = sub_080C57B4();
    if (sub_080B1B58() == 1)
    {
        if (keys & 2)
        {
            if (keys & 0x10)
            {
                dest = gUnknown_0815F324[dir][0];
                move = 1;
            }
            else if (keys & 0x20)
            {
                dest = gUnknown_0815F324[dir][1];
                move = 2;
            }
            else if (keys & 0x80)
            {
                dest = gUnknown_0815F31C[dir];
                stairs = TRUE;
            }
            else if (keys & 0x40)
            {
                dest = gUnknown_0815F2FC[dir][0];
                gFieldState.unk0A = 8;
            }
            else if (keys & 0x200)
            {
                sub_080B1BDC();
            }
        }
        else
        {
            if (keys & 0x10)
            {
                dest = gUnknown_0815F2FC[dir][3];
            }
            else if (keys & 0x20)
            {
                dest = gUnknown_0815F2FC[dir][2];
            }
            else if (keys & 0x80)
            {
                dest = gUnknown_0815F2FC[dir][1];
            }
            else if (keys & 0x40)
            {
                dest = gUnknown_0815F2FC[dir][0];
                gFieldState.unk0A = 12;
            }
            else if (keys & 0x200)
            {
                sub_080B1BDC();
            }
        }
    }
    if (dest == 0xFFFF)
        return;
    if (move != 0)
    {
        gFieldState.unk1E = 12;
        gFieldState.unk08 = move;
        gFieldState.unk06 = dest;
        Field_SetState(8);
        gFieldState.unk3E = 0;
        if (gFieldState.unk08 == 1)
        {
            if (View_IsSideOpen(1) == 1)
            {
                gUnk_03004540 = -16;
            }
            else
            {
                gUnk_03004540 = -8;
                gFieldState.unk3E = 1;
            }
        }
        else
        {
            if (View_IsSideOpen(3) == 1)
            {
                gUnk_03004540 = 16;
            }
            else
            {
                gUnk_03004540 = 8;
                gFieldState.unk3E = 1;
            }
        }
        sub_080B2840(3, gUnk_03004540, 0);
    }
    else if (stairs == TRUE)
    {
        sub_080B1A4C(dest, 0);
    }
    else if (dest != gFieldState.unk02)
    {
        if (keys & 0x10)
            move = 1;
        else if (keys & 0x20)
            move = -1;
        else if (keys & 0x80)
            move = 1;
        sub_080B2064(dest, move);
        Field_SetState(6);
        gFieldState.unk3E = 0;
    }
    else
    {
        sub_080B1AD8(gFieldState.unk0A, gFieldState.unk02);
    }
}

// Field_SetFacing @ 0x080B200C
/* Turns to dir; returns 1 when already facing it. */
u32 Field_SetFacing(u16 dir)
{
    if (dir != gFieldState.unk02)
    {
        gFieldState.unk04 = gFieldState.unk02;
        gFieldState.unk02 = dir;
        return 0;
    }
    return 1;
}

// sub_080B2030 @ 0x080B2030
void sub_080B2030(u16 a, u16 b, u16 state)
{
    sub_080B2840(1, 0, 0);
    gFieldState.unk1E = a;
    gFieldState.unk06 = b;
    Field_SetState(state);
}

// sub_080B2064 @ 0x080B2064
void sub_080B2064(u16 a, u16 b)
{
    sub_080B2840(2, 0, 0);
    gFieldState.unk1E = 0x10;
    gFieldState.unk08 = b;
    gFieldState.unk06 = a;
}

// sub_080B2090 @ 0x080B2090
s32 sub_080B2090(void)
{
    struct Unk03004550 *s = &gFieldState;
    u16 step = s->unk1E;
    u16 busy;

    s->unk1E--;
    if (s->unk1E == 8)
    {
        if (s->unk0E != 0)
            goto wait;
        sub_080AE494(sub_080B01C8);
        s->unk2E = 0x22;
    }
    else if (s->unk1E == 7)
    {
        Field_SetFacing((s->unk02 + s->unk08) & 3);
        sub_080B2840(0, 0, 0);
    }
    else if (s->unk1E == 0)
    {
        if ((busy = s->unk0E) != 0)
            goto wait;
        sub_080AE494(sub_080B0158);
        s->unk2E = busy;
        if (s->unk02 == s->unk06)
            return 1;
        return 7;
    }
    return -1;
wait:
    s->unk1E = step;
    return -1;
}

/* NONMATCHING: readable C only (708 bytes); not matched. */
// FieldView_BlitPixels @ 0x080B210C
/* Draws a 4bpp sprite layer into the field view's tile buffer, pixel by pixel, skipping
   transparent (0) pixels of the destination: srcX/srcY/dstX/dstY in pixels, the buffers are
   32-byte tiles in rows of 0x400 bytes. dir = 1 copies left to right, otherwise mirrored. The
   destination x is shifted by the view scroll (unk28) and clipped to columns 8..0xE7. */
void FieldView_BlitPixels(const struct ViewBlit *b)
{
    u16 srcX = b->srcX;
    u16 srcY = b->srcY;
    u16 dstX = b->dstX;
    u16 dstY = b->dstY;
    u16 w = b->w;
    u16 h = b->h;
    u16 dir = b->dir;
    const u8 *src = *b->src;
    u8 *dst = b->dst;
    u16 row, col;
    u16 sx, dx;
    u8 pix, v, *p;

    gUnk_030045F4 = 1;
    if (gUnk_03004614 != 0x4A || gUnk_03004514 != 4)
    {
        dstX = dstX + gFieldState.unk28;
        if (dir == 1)
        {
            if ((s16)dstX < 8)
            {
                u16 cut = 8 - dstX;
                dstX = dstX + cut;
                srcX = srcX + cut;
                w = w - cut;
            }
            else if (dstX + w > 0xE8)
            {
                u16 cut = dstX + w - 0xE8;
                w = w - cut;
            }
        }
        else
        {
            if ((s16)(dstX - w) < 8)
            {
                u16 cut = 8 - (dstX - w);
                w = w - cut;
            }
            else if (dstX > 0xE8)
            {
                u16 cut = dstX - 0xE8;
                dstX = dstX - cut;
                srcX = srcX + cut;
                w = w - cut;
            }
        }
    }
    if ((s16)w > 0)
    {
        for (row = 0; row < h; row++)
        {
            sx = srcX;
            dx = dstX;
            for (col = 0; col < w; )
            {
                if (!(dx & 1))
                {
                    pix = *(src + ((srcY >> 3) << 10) + ((sx >> 3) << 5) + ((srcY & 7) << 2) + ((sx & 7) >> 1));
                    p = dst + ((dstY >> 3) << 10) + ((dx >> 3) << 5) + ((dstY & 7) << 2) + ((dx & 7) >> 1);
                    v = *p;
                    if (!(v & 0xF))
                    {
                        v |= pix & 0xF;
                        gUnk_030045F4 = 1;
                    }
                    *p = v;
                    dx = dx + dir;
                    p = dst + ((dstY >> 3) << 10) + ((dx >> 3) << 5) + ((dstY & 7) << 2) + ((dx & 7) >> 1);
                    v = *p;
                    if (!(v & 0xF0))
                    {
                        v |= pix & 0xF0;
                        gUnk_030045F4 = 1;
                    }
                    *p = v;
                    sx++;
                    col++;
                }
                else
                {
                    pix = *(src + ((srcY >> 3) << 10) + ((sx >> 3) << 5) + ((srcY & 7) << 2) + ((sx & 7) >> 1));
                    p = dst + ((dstY >> 3) << 10) + ((dx >> 3) << 5) + ((dstY & 7) << 2) + ((dx & 7) >> 1);
                    v = *p;
                    if (!(v & 0xF0))
                    {
                        v |= (pix & 0xF) << 4;
                        gUnk_030045F4 = 1;
                    }
                    *p = v;
                    dx = dx + dir;
                    p = dst + ((dstY >> 3) << 10) + ((dx >> 3) << 5) + ((dstY & 7) << 2) + ((dx & 7) >> 1);
                    v = *p;
                    if (!(v & 0xF))
                    {
                        v |= pix >> 4;
                        gUnk_030045F4 = 1;
                    }
                    *p = v;
                    sx++;
                    col++;
                }
                sx++;
                dx = dx + dir;
                col++;
            }
            srcY++;
            dstY++;
        }
        gFieldState.unk2C = 0;
    }
}


/* NONMATCHING: readable C only (1136 bytes, unrolled tile copies); not matched. */
// FieldView_BlitTiles @ 0x080B23D0
#ifdef NONMATCHING
/* Copies whole 8x8 tiles of a view layer into the tile buffer (dir = 1), or mirrored
   (each 4bpp row reversed nibble by nibble, tiles right to left), with the same x clipping
   as FieldView_BlitPixels. unk2C counts the frames since the last change (0 -> 1 -> 2 -> 3 -> 0). */
#define MIRROR_ROW(v) (((v) << 28 & 0xF0000000) | ((v) << 20 & 0x0F000000) | ((v) << 12 & 0x00F00000) \
                     | ((v) << 4 & 0x000F0000) | ((v) >> 4 & 0xF000) | ((v) >> 12 & 0xF00)        \
                     | ((v) >> 20 & 0xF0) | ((v) >> 28 & 0xF))
void FieldView_BlitTiles(const struct ViewBlit *b)
{
    u32 w;
    u32 cols;
    u32 h;
    u16 rows;
    u16 dstX;
    u16 r, c;
    u16 srcOff;
    u16 dstOff;
    const u8 *src;
    u8 *dst;
    u16 dir;
    s32 cut;
    s32 t;
    const u32 *s;
    u32 *d;
    u32 v;

    w = b->w;
    cols = w >> 3;
    h = b->h;
    rows = h >> 3;
    dstX = b->dstX + gFieldState.unk28;
    srcOff = (b->srcX >> 3) << 5;
    dstOff = (dstX >> 3) << 5;
    src = *b->src;
    dst = b->dst;
    if (w & 7)
        cols++;
    if (h & 7)
        rows++;
    if (b->dir == 1)
    {
        if ((s16)dstX < 8)
        {
            t = (s16)(8 - dstX);
            cut = t / 8;
            v = cut * 0x20;
            dstOff += v;
            srcOff += v;
            cols = (u16)(cols - cut);
        }
        else if ((s32)(dstX + w) > 0xE8)
        {
            cols = (u16)(cols - (s16)(dstX + w - 0xE8) / 8);
        }
    }
    else
    {
        t = dstX - w;
        if ((s16)t < 8)
        {
            cols = (u16)(cols - (s16)(8 - t) / 8);
        }
        else if (dstX > 0xE8)
        {
            t = (s16)(dstX - 0xE8);
            cut = t / 8;
            dstOff -= cut * 0x20;
            srcOff += cut * 0x20;
            cols = (u16)(cols - cut);
        }
    }
    if ((s16)cols <= 0)
        return;
    if (b->dir == 1)
    {
        for (r = 0; r < rows; r++)
        {
            s = (const u32 *)(src + ((b->srcY + r * 8) >> 3) * 0x400);
            d = (u32 *)(dst + ((b->dstY + r * 8) >> 3) * 0x400);
            s = (const u32 *)((u8 *)s + srcOff);
            d = (u32 *)((u8 *)d + dstOff);
            for (c = 0; c < cols; c++)
            {
                *d++ = *s++;
                *d++ = *s++;
                *d++ = *s++;
                *d++ = *s++;
                *d++ = *s++;
                *d++ = *s++;
                *d++ = *s++;
                *d++ = *s++;
            }
        }
    }
    else
    {
        for (r = 0; r < rows; r++)
        {
            s = (const u32 *)(src + ((b->srcY + r * 8) >> 3) * 0x400);
            d = (u32 *)(dst + ((b->dstY + r * 8) >> 3) * 0x400);
            s = (const u32 *)((u8 *)s + srcOff);
            d = (u32 *)((u8 *)d + dstOff);
            for (c = 0; c < cols; c++)
            {
                v = *s++; *d++ = MIRROR_ROW(v);
                v = *s++; *d++ = MIRROR_ROW(v);
                v = *s++; *d++ = MIRROR_ROW(v);
                v = *s++; *d++ = MIRROR_ROW(v);
                v = *s++; *d++ = MIRROR_ROW(v);
                v = *s++; *d++ = MIRROR_ROW(v);
                v = *s++; *d++ = MIRROR_ROW(v);
                v = *s++; *d++ = MIRROR_ROW(v);
                d -= 16;
            }
        }
    }
    if (gFieldState.unk2C == 0)
        gFieldState.unk2C++;
    else if (gFieldState.unk2C > 2)
        gFieldState.unk2C = 0;
    else
        gFieldState.unk2C++;
}
#else
NAKED
void FieldView_BlitTiles(const struct ViewBlit *b)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x24\n"
        "    str r0, [sp]\n"
        "    ldrh r5, [r0, #0x10]\n"
        "    lsrs r0, r5, #3\n"
        "    str r0, [sp, #4]\n"
        "    ldr r1, [sp]\n"
        "    ldrh r3, [r1, #0x12]\n"
        "    lsrs r2, r3, #3\n"
        "    str r2, [sp, #8]\n"
        "    ldr r2, .L080B247C\n"
        "    ldrh r1, [r2, #0x28]\n"
        "    ldr r4, [sp]\n"
        "    ldrh r4, [r4, #0xc]\n"
        "    adds r1, r1, r4\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r4, r1, #0x10\n"
        "    adds r6, r4, #0\n"
        "    ldr r7, [sp]\n"
        "    ldrh r0, [r7, #8]\n"
        "    lsrs r0, r0, #3\n"
        "    lsls r0, r0, #0x15\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0x10]\n"
        "    lsrs r1, r1, #0x13\n"
        "    lsls r1, r1, #0x15\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #0x14]\n"
        "    ldr r0, [r7]\n"
        "    ldr r0, [r0]\n"
        "    str r0, [sp, #0x18]\n"
        "    ldr r0, [r7, #4]\n"
        "    str r0, [sp, #0x1c]\n"
        "    movs r1, #7\n"
        "    adds r0, r5, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080B242A\n"
        "    ldr r2, [sp, #4]\n"
        "    adds r2, #1\n"
        "    str r2, [sp, #4]\n"
        ".L080B242A:\n"
        "    ands r3, r1\n"
        "    cmp r3, #0\n"
        "    beq .L080B243A\n"
        "    ldr r0, [sp, #8]\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #8]\n"
        ".L080B243A:\n"
        "    ldr r3, [sp]\n"
        "    ldrh r0, [r3, #0x14]\n"
        "    adds r7, r0, #0\n"
        "    cmp r7, #1\n"
        "    bne .L080B249A\n"
        "    lsls r0, r4, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #7\n"
        "    bgt .L080B2480\n"
        "    movs r0, #8\n"
        "    subs r0, r0, r4\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r1, r0, #0x10\n"
        "    adds r0, r1, #0\n"
        "    cmp r1, #0\n"
        "    bge .L080B245C\n"
        "    adds r0, r1, #7\n"
        ".L080B245C:\n"
        "    asrs r3, r0, #3\n"
        "    lsls r2, r3, #5\n"
        "    ldr r4, [sp, #0x14]\n"
        "    adds r0, r4, r2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0x14]\n"
        "    ldr r4, [sp, #0x10]\n"
        "    adds r0, r4, r2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0x10]\n"
        "    ldr r1, [sp, #4]\n"
        "    subs r0, r1, r3\n"
        "    b .L080B24EA\n"
        "    .byte 0x00, 0x00\n"
        ".L080B247C: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B2480:\n"
        "    adds r0, r4, r5\n"
        "    cmp r0, #0xe8\n"
        "    ble .L080B24F0\n"
        "    subs r0, #0xe8\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L080B2492\n"
        "    adds r0, #7\n"
        ".L080B2492:\n"
        "    asrs r0, r0, #3\n"
        "    ldr r2, [sp, #4]\n"
        "    subs r0, r2, r0\n"
        "    b .L080B24EA\n"
        ".L080B249A:\n"
        "    subs r1, r4, r5\n"
        "    lsls r0, r1, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #7\n"
        "    bgt .L080B24BA\n"
        "    movs r0, #8\n"
        "    subs r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L080B24B2\n"
        "    adds r0, #7\n"
        ".L080B24B2:\n"
        "    asrs r0, r0, #3\n"
        "    ldr r3, [sp, #4]\n"
        "    subs r0, r3, r0\n"
        "    b .L080B24EA\n"
        ".L080B24BA:\n"
        "    cmp r6, #0xe8\n"
        "    bls .L080B24F0\n"
        "    adds r0, r6, #0\n"
        "    subs r0, #0xe8\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r2, r0, #0x10\n"
        "    adds r0, r2, #0\n"
        "    cmp r2, #0\n"
        "    bge .L080B24CE\n"
        "    adds r0, r2, #7\n"
        ".L080B24CE:\n"
        "    asrs r1, r0, #3\n"
        "    lsls r3, r1, #5\n"
        "    ldr r4, [sp, #0x14]\n"
        "    subs r0, r4, r3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0x14]\n"
        "    ldr r4, [sp, #0x10]\n"
        "    adds r0, r4, r3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0x10]\n"
        "    ldr r2, [sp, #4]\n"
        "    subs r0, r2, r1\n"
        ".L080B24EA:\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #4]\n"
        ".L080B24F0:\n"
        "    ldr r3, [sp, #4]\n"
        "    lsls r0, r3, #0x10\n"
        "    cmp r0, #0\n"
        "    bgt .L080B24FA\n"
        "    b .L080B282C\n"
        ".L080B24FA:\n"
        "    cmp r7, #1\n"
        "    bne .L080B2578\n"
        "    movs r4, #0\n"
        "    ldr r7, [sp, #8]\n"
        "    cmp r4, r7\n"
        "    blo .L080B2508\n"
        "    b .L080B2806\n"
        ".L080B2508:\n"
        "    ldr r1, [sp]\n"
        "    ldrh r0, [r1, #0xa]\n"
        "    lsls r2, r4, #3\n"
        "    adds r0, r0, r2\n"
        "    asrs r0, r0, #3\n"
        "    lsls r0, r0, #0xa\n"
        "    ldr r3, [sp, #0x18]\n"
        "    adds r0, r3, r0\n"
        "    ldrh r1, [r1, #0xe]\n"
        "    adds r1, r1, r2\n"
        "    asrs r1, r1, #3\n"
        "    lsls r1, r1, #0xa\n"
        "    ldr r7, [sp, #0x1c]\n"
        "    adds r1, r7, r1\n"
        "    ldr r2, [sp, #0x10]\n"
        "    adds r3, r0, r2\n"
        "    ldr r7, [sp, #0x14]\n"
        "    adds r1, r1, r7\n"
        "    movs r0, #0\n"
        "    str r0, [sp, #0xc]\n"
        "    adds r4, #1\n"
        "    str r4, [sp, #0x20]\n"
        "    ldr r2, [sp, #4]\n"
        "    cmp r0, r2\n"
        "    bhs .L080B256A\n"
        ".L080B253A:\n"
        "    ldm r3!, {r0}\n"
        "    stm r1!, {r0}\n"
        "    ldm r3!, {r0}\n"
        "    stm r1!, {r0}\n"
        "    ldm r3!, {r0}\n"
        "    stm r1!, {r0}\n"
        "    ldm r3!, {r0}\n"
        "    stm r1!, {r0}\n"
        "    ldm r3!, {r0}\n"
        "    stm r1!, {r0}\n"
        "    ldm r3!, {r0}\n"
        "    stm r1!, {r0}\n"
        "    ldm r3!, {r0}\n"
        "    stm r1!, {r0}\n"
        "    ldm r3!, {r0}\n"
        "    stm r1!, {r0}\n"
        "    ldr r0, [sp, #0xc]\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0xc]\n"
        "    ldr r4, [sp, #4]\n"
        "    cmp r0, r4\n"
        "    blo .L080B253A\n"
        ".L080B256A:\n"
        "    ldr r7, [sp, #0x20]\n"
        "    lsls r0, r7, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    ldr r0, [sp, #8]\n"
        "    cmp r4, r0\n"
        "    blo .L080B2508\n"
        "    b .L080B2806\n"
        ".L080B2578:\n"
        "    movs r4, #0\n"
        "    ldr r1, [sp, #8]\n"
        "    cmp r4, r1\n"
        "    blo .L080B2582\n"
        "    b .L080B2806\n"
        ".L080B2582:\n"
        "    ldr r2, [sp]\n"
        "    ldrh r0, [r2, #0xa]\n"
        "    lsls r2, r4, #3\n"
        "    adds r0, r0, r2\n"
        "    asrs r0, r0, #3\n"
        "    lsls r0, r0, #0xa\n"
        "    ldr r3, [sp, #0x18]\n"
        "    adds r0, r3, r0\n"
        "    ldr r7, [sp]\n"
        "    ldrh r1, [r7, #0xe]\n"
        "    adds r1, r1, r2\n"
        "    asrs r1, r1, #3\n"
        "    lsls r1, r1, #0xa\n"
        "    ldr r2, [sp, #0x1c]\n"
        "    adds r1, r2, r1\n"
        "    ldr r3, [sp, #0x10]\n"
        "    adds r5, r0, r3\n"
        "    ldr r7, [sp, #0x14]\n"
        "    adds r2, r1, r7\n"
        "    movs r0, #0\n"
        "    str r0, [sp, #0xc]\n"
        "    adds r4, #1\n"
        "    str r4, [sp, #0x20]\n"
        "    ldr r1, [sp, #4]\n"
        "    cmp r0, r1\n"
        "    blo .L080B25B8\n"
        "    b .L080B27F8\n"
        ".L080B25B8:\n"
        "    movs r3, #0xf0\n"
        "    lsls r3, r3, #0x14\n"
        "    mov sl, r3\n"
        "    movs r4, #0xf0\n"
        "    lsls r4, r4, #0x10\n"
        "    mov sb, r4\n"
        "    movs r7, #0xf0\n"
        "    lsls r7, r7, #0xc\n"
        "    mov r8, r7\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #8\n"
        "    mov ip, r0\n"
        "    movs r6, #0xf0\n"
        "    movs r4, #0xf\n"
        ".L080B25D4:\n"
        "    ldm r5!, {r3}\n"
        "    lsls r1, r3, #0x1c\n"
        "    movs r7, #0xf0\n"
        "    lsls r7, r7, #0x18\n"
        "    ands r1, r7\n"
        "    lsls r0, r3, #0x14\n"
        "    mov r7, sl\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #0xc\n"
        "    mov r7, sb\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #4\n"
        "    mov r7, r8\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #4\n"
        "    mov r7, ip\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0xc\n"
        "    movs r7, #0xf0\n"
        "    lsls r7, r7, #4\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x14\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x1c\n"
        "    ands r0, r4\n"
        "    orrs r1, r0\n"
        "    stm r2!, {r1}\n"
        "    ldm r5!, {r3}\n"
        "    lsls r1, r3, #0x1c\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0x18\n"
        "    ands r1, r0\n"
        "    lsls r0, r3, #0x14\n"
        "    mov r7, sl\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #0xc\n"
        "    mov r7, sb\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #4\n"
        "    mov r7, r8\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #4\n"
        "    mov r7, ip\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0xc\n"
        "    movs r7, #0xf0\n"
        "    lsls r7, r7, #4\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x14\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x1c\n"
        "    ands r0, r4\n"
        "    orrs r1, r0\n"
        "    stm r2!, {r1}\n"
        "    ldm r5!, {r3}\n"
        "    lsls r1, r3, #0x1c\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0x18\n"
        "    ands r1, r0\n"
        "    lsls r0, r3, #0x14\n"
        "    mov r7, sl\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #0xc\n"
        "    mov r7, sb\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #4\n"
        "    mov r7, r8\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #4\n"
        "    mov r7, ip\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0xc\n"
        "    movs r7, #0xf0\n"
        "    lsls r7, r7, #4\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x14\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x1c\n"
        "    ands r0, r4\n"
        "    orrs r1, r0\n"
        "    stm r2!, {r1}\n"
        "    ldm r5!, {r3}\n"
        "    lsls r1, r3, #0x1c\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0x18\n"
        "    ands r1, r0\n"
        "    lsls r0, r3, #0x14\n"
        "    mov r7, sl\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #0xc\n"
        "    mov r7, sb\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #4\n"
        "    mov r7, r8\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #4\n"
        "    mov r7, ip\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0xc\n"
        "    movs r7, #0xf0\n"
        "    lsls r7, r7, #4\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x14\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x1c\n"
        "    ands r0, r4\n"
        "    orrs r1, r0\n"
        "    stm r2!, {r1}\n"
        "    ldm r5!, {r3}\n"
        "    lsls r1, r3, #0x1c\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0x18\n"
        "    ands r1, r0\n"
        "    lsls r0, r3, #0x14\n"
        "    mov r7, sl\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #0xc\n"
        "    mov r7, sb\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #4\n"
        "    mov r7, r8\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #4\n"
        "    mov r7, ip\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0xc\n"
        "    movs r7, #0xf0\n"
        "    lsls r7, r7, #4\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x14\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x1c\n"
        "    ands r0, r4\n"
        "    orrs r1, r0\n"
        "    stm r2!, {r1}\n"
        "    ldm r5!, {r3}\n"
        "    lsls r1, r3, #0x1c\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0x18\n"
        "    ands r1, r0\n"
        "    lsls r0, r3, #0x14\n"
        "    mov r7, sl\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #0xc\n"
        "    mov r7, sb\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #4\n"
        "    mov r7, r8\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #4\n"
        "    mov r7, ip\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0xc\n"
        "    movs r7, #0xf0\n"
        "    lsls r7, r7, #4\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x14\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x1c\n"
        "    ands r0, r4\n"
        "    orrs r1, r0\n"
        "    stm r2!, {r1}\n"
        "    ldm r5!, {r3}\n"
        "    lsls r1, r3, #0x1c\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0x18\n"
        "    ands r1, r0\n"
        "    lsls r0, r3, #0x14\n"
        "    mov r7, sl\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #0xc\n"
        "    mov r7, sb\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #4\n"
        "    mov r7, r8\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #4\n"
        "    mov r7, ip\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0xc\n"
        "    movs r7, #0xf0\n"
        "    lsls r7, r7, #4\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x14\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x1c\n"
        "    ands r0, r4\n"
        "    orrs r1, r0\n"
        "    stm r2!, {r1}\n"
        "    ldm r5!, {r3}\n"
        "    lsls r1, r3, #0x1c\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0x18\n"
        "    ands r1, r0\n"
        "    lsls r0, r3, #0x14\n"
        "    mov r7, sl\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #0xc\n"
        "    mov r7, sb\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #4\n"
        "    mov r7, r8\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #4\n"
        "    mov r7, ip\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0xc\n"
        "    movs r7, #0xf0\n"
        "    lsls r7, r7, #4\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x14\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x1c\n"
        "    ands r0, r4\n"
        "    orrs r1, r0\n"
        "    stm r2!, {r1}\n"
        "    subs r2, #0x40\n"
        "    ldr r0, [sp, #0xc]\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0xc]\n"
        "    ldr r1, [sp, #4]\n"
        "    cmp r0, r1\n"
        "    bhs .L080B27F8\n"
        "    b .L080B25D4\n"
        ".L080B27F8:\n"
        "    ldr r2, [sp, #0x20]\n"
        "    lsls r0, r2, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    ldr r3, [sp, #8]\n"
        "    cmp r4, r3\n"
        "    bhs .L080B2806\n"
        "    b .L080B2582\n"
        ".L080B2806:\n"
        "    ldr r2, .L080B2818\n"
        "    ldrh r0, [r2, #0x2c]\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #0\n"
        "    bne .L080B281C\n"
        "    adds r0, #1\n"
        "    strh r0, [r2, #0x2c]\n"
        "    b .L080B282C\n"
        "    .byte 0x00, 0x00\n"
        ".L080B2818: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B281C:\n"
        "    cmp r1, #2\n"
        "    bls .L080B2826\n"
        "    movs r0, #0\n"
        "    strh r0, [r2, #0x2c]\n"
        "    b .L080B282C\n"
        ".L080B2826:\n"
        "    adds r0, #1\n"
        "    ldr r4, .L080B283C\n"
        "    strh r0, [r4, #0x2c]\n"
        ".L080B282C:\n"
        "    add sp, #0x24\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080B283C: .4byte 0x03004550 @ IWRAM+0x4550\n"
    );
}

#endif
