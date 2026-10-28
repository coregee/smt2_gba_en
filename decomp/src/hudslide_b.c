#include "global.h"
#include "status.h"

// sub_080C7CD8 @ 0x080C7CD8
/* Per-frame HUD work: the moon phase sprite, its animation and the danger palette cycle. */
void sub_080C7CD8(void)
{
    struct C0c6Hud *hud;
    u16 n;

    if (gWorldMap[0x1A] != 0)
        return;
    Sprite_Draw(gUnknown_080005A0, 0, 0, 0, 0, 10, 5);
    if ((gFrameCounter & 0xF) == 0)
    {
        gGameState.unkA27 = (gGameState.unkA27 + 1) & 7;
        VBlankTask_AddCounted(Hud_UploadMoonTiles, 1);
    }
    Sprite_Draw(gUnknown_080019D4, 0, 0xC, 0, 0xE0, 0x90, 0x90);
    if (PalFade_AllDone() == 1 && gUnk_0203A44E == 0)
    {
        hud = gHud;
        if (hud->unk38 == 0 || --hud->unk38 == 0)
        {
            sub_080C67C0(gPaletteBuffer, 0xC);
            n = sub_080C7E90();
            hud->unk32++;
            if (*(vu16 *)&hud->unk32 >= n)
                hud->unk32 = 0;
            Palette_MarkDirty();
        }
    }
}

// sub_080C7DAC @ 0x080C7DAC
void sub_080C7DAC(void)
{
    DmaCopy32(3, gUnk_0200E8D8, (void *)0x06016040, 0x180);
}

// Hud_RenderSpriteText @ 0x080C7DD0
/* Renders str (glyph codes, '.' and ' ') as sprite tiles and queues their upload; returns the
   length. 0x180 bytes = 12 tiles: longer strings overrun the upload. */
u16 Hud_RenderSpriteText(const u8 *str)
{
    u8 *buf = gUnk_0200E8D8;
    u16 n = 0;

    DmaFill32(3, 0, buf, 0x180);
    Hud_RenderGlyphTiles(buf, str);
    VBlankTask_AddCounted(sub_080C7DAC, 1);
loop:
    if (*str != 0)
    {
        n++;
        str++;
        goto loop;
    }
    return n;
}

// Hud_RenderGlyphTiles @ 0x080C7E24
void Hud_RenderGlyphTiles(u8 *dst, const u8 *str)
{
    u32 *d = (u32 *)dst;
    const u32 *src;
    u32 i;

    while (*str != 0)
    {
        if (*str == '.')
        {
            src = gUnknown_081AD898[0].w;
            for (i = 0, str++; i < 8; i++)
                *d++ = *src++;
        }
        else if (*str == ' ')
        {
            for (i = 0, str++; i < 8; i++)
                *d++ = 0;
        }
        else
        {
            src = gUnknown_081AD898[gUnknown_0834A5DC[*str - 0x2F] - 7].w;
            for (i = 0, str++; i < 8; i++)
                *d++ = *src++;
        }
    }
}

// sub_080C7E90 @ 0x080C7E90
u32 sub_080C7E90(void)
{
    if (!(gUnk_0200AB04 & 0x7FFF))
        return 0xE;
    return 0xB;
}

// sub_080C7EB4 @ 0x080C7EB4
#ifdef NONMATCHING
void sub_080C7EB4(const void *src, void *dst)
{
    u16 *d = dst;
    u32 pos = gHud->unk32;
    u16 n = sub_080C7E90();
    u32 i;

    for (i = 0; i < n; i++)
    {
        *d = Color_ApplyEffect(*((const u16 *)src - pos));
        if (++pos == n)
            pos = 0;
        d--;
    }
}
#else
NAKED
void sub_080C7EB4(const void *src, void *dst)
{
    asm_unified(
        ".L080C7EB4:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    mov r8, r0\n"
        "    adds r5, r1, #0\n"
        "    ldr r0, .L080C7EF8\n"
        "    ldrh r4, [r0, #0x32]\n"
        "    bl sub_080C7E90\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    movs r6, #0\n"
        "    cmp r6, r7\n"
        "    bhs .L080C7EEE\n"
        ".L080C7ED0:\n"
        "    lsls r0, r4, #1\n"
        "    mov r1, r8\n"
        "    subs r0, r1, r0\n"
        "    ldrh r0, [r0]\n"
        "    bl Color_ApplyEffect\n"
        "    strh r0, [r5]\n"
        "    adds r4, #1\n"
        "    cmp r4, r7\n"
        "    bne .L080C7EE6\n"
        "    movs r4, #0\n"
        ".L080C7EE6:\n"
        "    subs r5, #2\n"
        "    adds r6, #1\n"
        "    cmp r6, r7\n"
        "    blo .L080C7ED0\n"
        ".L080C7EEE:\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080C7EF8: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
    );
}
#endif

// Hud_UploadMoonTiles @ 0x080C7EFC
/* Uploads the moon sprite tiles for the current phase and animation frame. */
void Hud_UploadMoonTiles(void)
{
    const u8 *src = gUnknown_081BBA70;
    u32 idx = (Moon_GetPhase() >> 4) * 8 + gGameState.unkA27;

    src += idx * 0x80;
    DmaCopy32(3, src, (void *)0x06010120, 0x80);
    src = gUnknown_081BBA70 + gUnknown_0834A634[idx >> 3];
    DmaCopy32(3, src, (void *)0x06010020, 0x80);
}

// sub_080C7F64 @ 0x080C7F64
/* Draws v with up to 8 digits (leading zeros hidden), 6 pixels apart. */
void sub_080C7F64(u32 v, u16 x, u16 y, u16 layer)
{
    u8 *digits = NumberToDigits(v);
    u32 shown = 0;
    u32 i;

    for (i = 0; i < 8; i++, x += 6)
    {
        u8 d = digits[7 - i];

        if (i == 7 || shown == 1 || d != 0)
        {
            Sprite_Draw(gUnknown_0834A674[d], layer, 0, 1, 0, x, y);
            shown = 1;
        }
    }
}

// sub_080C7FD0 @ 0x080C7FD0
/* Same with the small digits, 5 pixels apart. */
void sub_080C7FD0(u32 v, u16 x, u16 y, u16 layer, u16 pal)
{
    u8 *digits = NumberToDigits(v);
    u32 shown = 0;
    u32 i;

    for (i = 0; i < 8; i++, x += 5)
    {
        u8 d = digits[7 - i];

        if (i == 7 || shown == 1 || d != 0)
        {
            Sprite_Draw(gUnknown_0834A69C[d], layer, pal, 1, 0, x, y);
            shown = 1;
        }
    }
}

// sub_080C8048 @ 0x080C8048
void sub_080C8048(u32 v, u16 x, u16 y, u16 layer)
{
    sub_080C7FD0(v, x, y, layer, 0);
}

// sub_080C8068 @ 0x080C8068
/* Draws the two halves of a gauge frame (kind 0x1E uses the other frame). */
void sub_080C8068(u16 layer, u16 pal, u16 prio, u16 tile, u16 x, u16 y)
{
    if (tile != 0x1E)
    {
        Sprite_DrawSingle(gUnknown_0834A6C4, layer, pal, prio, tile, x, y);
        Sprite_DrawSingle(gUnknown_0834A6C4 + 8, layer, pal, prio, tile, x, y);
    }
    else
    {
        Sprite_DrawSingle(gUnknown_0834A6D4, layer, pal, prio, tile, x, y);
        Sprite_DrawSingle(gUnknown_0834A6D4 + 8, layer, pal, prio, tile, x, y);
    }
}

// sub_080C8104 @ 0x080C8104
void sub_080C8104(u16 layer, u16 pal, u16 prio, u16 tile, u16 x, u16 y)
{
    Sprite_DrawSingle(gUnknown_0834A6E4, layer, pal, prio, tile, x, y);
}

// sub_080C8148 @ 0x080C8148
/* Copies the 8x8 tile at byte offset off of the gauge tile sheet to dst; returns dst + 1. */
u32 *sub_080C8148(u32 off, u32 *dst)
{
    const u32 *src = (const u32 *)(gUnknown_081AD5B8 + off);

    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    return dst;
}

// Hud_DrawGaugeValue @ 0x080C8174
/* Prints cur (or alt when cur > 999) as three 4-pixel digits into the 8x8-tile canvas. */
#ifdef NONMATCHING
void Hud_DrawGaugeValue(u32 cur, u32 alt, u8 *canvas)
{
    u8 *digits;
    u32 shown = 0;

    if (cur <= 999)
        digits = NumberToDigits(cur);
    else
        digits = NumberToDigits(alt);
    if (digits[2] != 0)
    {
        Canvas_BlitOr(&gUnknown_081B17B8[digits[2] * 32], canvas, 0, 0, 0, 0, 8, 8);
        shown = 1;
    }
    if (shown == 1 || digits[1] != 0)
        Canvas_BlitOr(&gUnknown_081B17B8[digits[1] * 32], canvas, 0, 0, 4, 0, 8, 8);
    Canvas_BlitOr(&gUnknown_081B17B8[digits[0] * 32], canvas, 0, 0, 8, 0, 8, 8);
}
#else
NAKED
void Hud_DrawGaugeValue(u32 cur, u32 alt, u8 *canvas)
{
    asm_unified(
        ".L080C8174:\n"
        "    push {r4, r5, r6, lr}\n"
        "    sub sp, #0x10\n"
        "    adds r3, r0, #0\n"
        "    adds r5, r2, #0\n"
        "    movs r6, #0\n"
        "    ldr r0, .L080C8188\n"
        "    cmp r3, r0\n"
        "    bhi .L080C818C\n"
        "    adds r0, r3, #0\n"
        "    b .L080C818E\n"
        ".L080C8188: .4byte 0x000003E7\n"
        ".L080C818C:\n"
        "    adds r0, r1, #0\n"
        ".L080C818E:\n"
        "    bl NumberToDigits\n"
        "    adds r4, r0, #0\n"
        "    ldrb r0, [r4, #2]\n"
        "    cmp r0, #0\n"
        "    beq .L080C81BA\n"
        "    lsls r0, r0, #5\n"
        "    ldr r1, .L080C8210\n"
        "    adds r2, r0, r1\n"
        "    movs r0, #0\n"
        "    str r0, [sp]\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #8\n"
        "    str r0, [sp, #8]\n"
        "    str r0, [sp, #0xc]\n"
        "    adds r0, r2, #0\n"
        "    adds r1, r5, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Canvas_BlitOr\n"
        "    movs r6, #1\n"
        ".L080C81BA:\n"
        "    cmp r6, #1\n"
        "    beq .L080C81C4\n"
        "    ldrb r0, [r4, #1]\n"
        "    cmp r0, #0\n"
        "    beq .L080C81E6\n"
        ".L080C81C4:\n"
        "    ldrb r0, [r4, #1]\n"
        "    lsls r0, r0, #5\n"
        "    ldr r1, .L080C8210\n"
        "    adds r2, r0, r1\n"
        "    movs r0, #4\n"
        "    str r0, [sp]\n"
        "    movs r0, #0\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #8\n"
        "    str r0, [sp, #8]\n"
        "    str r0, [sp, #0xc]\n"
        "    adds r0, r2, #0\n"
        "    adds r1, r5, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Canvas_BlitOr\n"
        ".L080C81E6:\n"
        "    ldrb r0, [r4]\n"
        "    lsls r0, r0, #5\n"
        "    ldr r1, .L080C8210\n"
        "    adds r2, r0, r1\n"
        "    movs r1, #8\n"
        "    str r1, [sp]\n"
        "    movs r0, #0\n"
        "    str r0, [sp, #4]\n"
        "    str r1, [sp, #8]\n"
        "    str r1, [sp, #0xc]\n"
        "    adds r0, r2, #0\n"
        "    adds r1, r5, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Canvas_BlitOr\n"
        "    add sp, #0x10\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080C8210: .4byte gUnknown_081B17B8\n"
    );
}
#endif

// Hud_DrawGauge @ 0x080C8214
/* Draws the HP (kind 0) or MP gauge of party slot 'slot' at (x, y): a 46-pixel bar built from
   six tiles and the value cur, both redrawn only when cur changed. */
#ifdef NONMATCHING
void Hud_DrawGauge(u16 slot, u16 kind, u16 x, u16 y, u16 max, u16 cur)
{
    u16 t = 7;
    u16 fill;
    u32 *tiles;
    u16 *last;
    u16 i;
    u16 tile;
    u8 *canvas;

    if (cur <= max)
        fill = cur * 46 / max;
    else
        fill = 46;
    if (kind == 0)
    {
        tiles = (u32 *)(gUnk_0200E8D8 + slot * 0x180);
        last = &gUnk_0200F7D8[slot][0];
    }
    else
    {
        tiles = (u32 *)(gUnk_0200E998 + slot * 0x180);
        last = &gUnk_0200F7D8[slot][1];
    }
    if (*last != cur)
    {
        *last = cur;
        tile = fill;
        if (tile > t)
            tile = 7;
        tiles = sub_080C8148(gUnknown_0834A6EC[tile], tiles);
        t += 8;
        for (i = 0; i < 4; i++)
        {
            if (fill > t)
                tile = 8;
            else if (fill <= t - 8)
                tile = 0;
            else
                tile = (fill - (i + 1) * 8) & 7;
            tiles = sub_080C8148(gUnknown_0834A70C[tile], tiles);
            t += 8;
        }
        if (fill == 46)
            tile = 7;
        else if (fill < 46 - 7)
            tile = 0;
        else
            tile = fill + 7 - 46;
        sub_080C8148(gUnknown_0834A730[tile], tiles);
        if (kind == 0)
            canvas = gUnk_0200F1D8 + slot * 0x100;
        else
            canvas = gUnk_0200F258 + slot * 0x100;
        DmaFill32(3, 0, canvas, 0x80);
        Hud_DrawGaugeValue(cur, max, canvas);
        gUnk_0200F7F0 = 1;
    }
    if (kind == 0)
    {
        sub_080C8068(7, 1, 1, slot * 12, x, y);
        sub_080C8104(7, 0, 1, slot * 8, x + 0x1D, y - 3);
    }
    else
    {
        sub_080C8068(7, 2, 1, slot * 12 + 6, x, y);
        sub_080C8104(7, 0, 1, slot * 8 + 4, x + 0x1D, y - 3);
    }
}
#else
NAKED
void Hud_DrawGauge(u16 slot, u16 kind, u16 x, u16 y, u16 max, u16 cur)
{
    asm_unified(
        ".L080C8214:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x2c\n"
        "    ldr r4, [sp, #0x4c]\n"
        "    ldr r5, [sp, #0x50]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #0xc]\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    str r2, [sp, #0x10]\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    str r3, [sp, #0x14]\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    str r4, [sp, #0x18]\n"
        "    lsls r5, r5, #0x10\n"
        "    lsrs r5, r5, #0x10\n"
        "    mov sb, r5\n"
        "    movs r0, #7\n"
        "    mov r8, r0\n"
        "    cmp sb, r4\n"
        "    bhi .L080C8260\n"
        "    movs r1, #0x2e\n"
        "    mov r0, sb\n"
        "    muls r0, r1, r0\n"
        "    adds r1, r4, #0\n"
        "    bl __divsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    b .L080C8262\n"
        ".L080C8260:\n"
        "    movs r5, #0x2e\n"
        ".L080C8262:\n"
        "    ldr r2, [sp, #0xc]\n"
        "    cmp r2, #0\n"
        "    bne .L080C8280\n"
        "    lsls r2, r6, #1\n"
        "    adds r0, r2, r6\n"
        "    lsls r0, r0, #7\n"
        "    ldr r1, .L080C8278\n"
        "    adds r3, r0, r1\n"
        "    lsls r1, r6, #2\n"
        "    ldr r0, .L080C827C\n"
        "    b .L080C828E\n"
        ".L080C8278: .4byte 0x0200E8D8 @ EWRAM+0xE8D8\n"
        ".L080C827C: .4byte 0x0200F7D8 @ EWRAM+0xF7D8\n"
        ".L080C8280:\n"
        "    lsls r2, r6, #1\n"
        "    adds r0, r2, r6\n"
        "    lsls r0, r0, #7\n"
        "    ldr r1, .L080C82E4\n"
        "    adds r3, r0, r1\n"
        "    lsls r1, r6, #2\n"
        "    ldr r0, .L080C82E8\n"
        ".L080C828E:\n"
        "    adds r1, r1, r0\n"
        "    mov sl, r2\n"
        "    ldrh r0, [r1]\n"
        "    lsls r2, r6, #3\n"
        "    str r2, [sp, #0x20]\n"
        "    ldr r2, [sp, #0x10]\n"
        "    adds r2, #0x1d\n"
        "    str r2, [sp, #0x28]\n"
        "    ldr r2, [sp, #0x14]\n"
        "    subs r2, #3\n"
        "    str r2, [sp, #0x1c]\n"
        "    cmp r0, sb\n"
        "    beq .L080C839C\n"
        "    mov r0, sb\n"
        "    strh r0, [r1]\n"
        "    adds r2, r5, #0\n"
        "    cmp r2, r8\n"
        "    bls .L080C82B4\n"
        "    movs r2, #7\n"
        ".L080C82B4:\n"
        "    ldr r1, .L080C82EC\n"
        "    lsls r0, r2, #2\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    adds r1, r3, #0\n"
        "    bl sub_080C8148\n"
        "    adds r3, r0, #0\n"
        "    mov r0, r8\n"
        "    adds r0, #8\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        "    movs r1, #0\n"
        "    movs r7, #4\n"
        "    lsls r2, r6, #8\n"
        "    str r2, [sp, #0x24]\n"
        "    cmp r1, r7\n"
        "    bge .L080C832C\n"
        ".L080C82DA:\n"
        "    cmp r5, r8\n"
        "    bls .L080C82F0\n"
        "    movs r2, #8\n"
        "    adds r4, r1, #1\n"
        "    b .L080C830A\n"
        ".L080C82E4: .4byte 0x0200E998 @ EWRAM+0xE998\n"
        ".L080C82E8: .4byte 0x0200F7DA @ EWRAM+0xF7DA\n"
        ".L080C82EC: .4byte gUnknown_0834A6EC\n"
        ".L080C82F0:\n"
        "    mov r0, r8\n"
        "    subs r0, #8\n"
        "    cmp r5, r0\n"
        "    bgt .L080C82FE\n"
        "    movs r2, #0\n"
        "    adds r4, r1, #1\n"
        "    b .L080C830A\n"
        ".L080C82FE:\n"
        "    adds r0, r1, #1\n"
        "    lsls r1, r0, #3\n"
        "    subs r2, r5, r1\n"
        "    movs r1, #7\n"
        "    ands r2, r1\n"
        "    adds r4, r0, #0\n"
        ".L080C830A:\n"
        "    ldr r1, .L080C8334\n"
        "    lsls r0, r2, #2\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    adds r1, r3, #0\n"
        "    bl sub_080C8148\n"
        "    adds r3, r0, #0\n"
        "    mov r0, r8\n"
        "    adds r0, #8\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        "    lsls r0, r4, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    cmp r1, r7\n"
        "    blt .L080C82DA\n"
        ".L080C832C:\n"
        "    cmp r5, #0x2e\n"
        "    bne .L080C8338\n"
        "    movs r2, #7\n"
        "    b .L080C834E\n"
        ".L080C8334: .4byte gUnknown_0834A70C\n"
        ".L080C8338:\n"
        "    movs r0, #0x2e\n"
        "    subs r0, #7\n"
        "    cmp r5, r0\n"
        "    bge .L080C8344\n"
        "    movs r2, #0\n"
        "    b .L080C834E\n"
        ".L080C8344:\n"
        "    adds r0, r5, #7\n"
        "    movs r1, #0x2e\n"
        "    subs r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        ".L080C834E:\n"
        "    ldr r0, .L080C836C\n"
        "    lsls r1, r2, #2\n"
        "    adds r1, r1, r0\n"
        "    ldr r0, [r1]\n"
        "    adds r1, r3, #0\n"
        "    bl sub_080C8148\n"
        "    ldr r2, [sp, #0xc]\n"
        "    cmp r2, #0\n"
        "    bne .L080C8374\n"
        "    ldr r0, .L080C8370\n"
        "    ldr r1, [sp, #0x24]\n"
        "    adds r3, r1, r0\n"
        "    b .L080C837A\n"
        "    .byte 0x00, 0x00\n"
        ".L080C836C: .4byte gUnknown_0834A730\n"
        ".L080C8370: .4byte 0x0200F1D8 @ EWRAM+0xF1D8\n"
        ".L080C8374:\n"
        "    ldr r0, .L080C83DC\n"
        "    ldr r2, [sp, #0x24]\n"
        "    adds r3, r2, r0\n"
        ".L080C837A:\n"
        "    movs r0, #0\n"
        "    str r0, [sp, #8]\n"
        "    ldr r0, .L080C83E0\n"
        "    add r1, sp, #8\n"
        "    str r1, [r0]\n"
        "    str r3, [r0, #4]\n"
        "    ldr r1, .L080C83E4\n"
        "    str r1, [r0, #8]\n"
        "    ldr r0, [r0, #8]\n"
        "    mov r0, sb\n"
        "    ldr r1, [sp, #0x18]\n"
        "    adds r2, r3, #0\n"
        "    bl Hud_DrawGaugeValue\n"
        "    ldr r1, .L080C83E8\n"
        "    movs r0, #1\n"
        "    str r0, [r1]\n"
        ".L080C839C:\n"
        "    ldr r2, [sp, #0xc]\n"
        "    cmp r2, #0\n"
        "    bne .L080C83EC\n"
        "    mov r0, sl\n"
        "    adds r3, r0, r6\n"
        "    lsls r3, r3, #0x12\n"
        "    lsrs r3, r3, #0x10\n"
        "    ldr r1, [sp, #0x10]\n"
        "    str r1, [sp]\n"
        "    ldr r2, [sp, #0x14]\n"
        "    str r2, [sp, #4]\n"
        "    movs r0, #7\n"
        "    movs r1, #1\n"
        "    movs r2, #1\n"
        "    bl sub_080C8068\n"
        "    lsls r3, r6, #0x13\n"
        "    lsrs r3, r3, #0x10\n"
        "    ldr r1, [sp, #0x28]\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp]\n"
        "    ldr r2, [sp, #0x1c]\n"
        "    lsls r0, r2, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #7\n"
        "    movs r1, #0\n"
        "    movs r2, #1\n"
        "    bl sub_080C8104\n"
        "    b .L080C842E\n"
        ".L080C83DC: .4byte 0x0200F258 @ EWRAM+0xF258\n"
        ".L080C83E0: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080C83E4: .4byte 0x85000020\n"
        ".L080C83E8: .4byte 0x0200F7F0 @ EWRAM+0xF7F0\n"
        ".L080C83EC:\n"
        "    mov r0, sl\n"
        "    adds r3, r0, r6\n"
        "    lsls r3, r3, #0x12\n"
        "    movs r1, #0xc0\n"
        "    lsls r1, r1, #0xb\n"
        "    adds r3, r3, r1\n"
        "    lsrs r3, r3, #0x10\n"
        "    ldr r2, [sp, #0x10]\n"
        "    str r2, [sp]\n"
        "    ldr r0, [sp, #0x14]\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #7\n"
        "    movs r1, #2\n"
        "    movs r2, #1\n"
        "    bl sub_080C8068\n"
        "    ldr r3, [sp, #0x20]\n"
        "    adds r3, #4\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    ldr r1, [sp, #0x28]\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp]\n"
        "    ldr r2, [sp, #0x1c]\n"
        "    lsls r0, r2, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #7\n"
        "    movs r1, #0\n"
        "    movs r2, #1\n"
        "    bl sub_080C8104\n"
        ".L080C842E:\n"
        "    add sp, #0x2c\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

