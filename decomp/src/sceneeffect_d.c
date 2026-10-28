#include "global.h"
#include "sceneeffect.h"

// sub_080BB33C @ 0x080BB33C
void sub_080BB33C(struct Task *task)
{
    struct AffineEffect *d = (struct AffineEffect *)task->data.raw;

    LZ77UnCompWram(gUnknown_08186EB0, gUnk_02001000);
    LZ77UnCompWram(gUnknown_081873FC, gUnk_02001000 + 0xC00);
    LZ77UnCompWram(gUnknown_08187D00, gUnk_02001000 + 0x2000);
    LZ77UnCompWram(gUnknown_081892C8, gUnk_02001000 + 0x4000);
    Palette_CopyWithEffect(3, gUnknown_08189434, &gPaletteTarget[0x1C0], 0x20, 0x20);
    Palette_CopyWithEffect(3, gUnknown_08189454, &gPaletteTarget[0x1D0], 0x20, 0x20);
    Palette_CopyWithEffect(3, gUnknown_08189474, &gPaletteTarget[0x1E0], 0x20, 0x20);
    Palette_CopyWithEffect(3, gUnknown_08189494, &gPaletteTarget[0x1F0], 0x20, 0x20);
    PalFade_FadeRangeInFromBlackTagged(0x1C0, 0x40, 1, 1);
    VBlankTask_AddCounted(sub_080BB318, 1);
    d->affine[0] = 1;
    d->affine[1] = 0x100;
    d->affine[2] = 0x100;
    d->affine[3] = 0;
    d->ring[0] = 1;
    d->ring[1] = 0x20;
    d->ring[2] = 0x20;
    d->ring[3] = 0;
    d->x = 0;
    d->y = 0;
    d->ringOn = 0;
    d->glowOn = 0;
    d->unk20 = 0;
    d->shrink = 0;
}

// sub_080BB430 @ 0x080BB430
void sub_080BB430(void)
{
    PalFade_FadeRangeToBlack(0x1C0, 0x40, 1);
}

// sub_080BB444 @ 0x080BB444
void sub_080BB444(struct Task *task)
{
    struct AffineEffect *d = (struct AffineEffect *)task->data.raw;
    u16 dx = d->affine[1] * 56 / 255;
    u16 dy = d->affine[1] * 48 / 255;
    const void *def[2];

    def[0] = gUnknown_080073B0[0];
    def[1] = d;
    sub_0815862C(def, d->affine[1], d->affine[2], 8);
    def[0] = gUnk_03003800;
    def[1] = d;
    Sprite_DrawSharedAffine(def, 4, 0xE, 3, 0x280, d->x, d->y, 0);
    if (d->glowOn)
    {
        def[0] = gUnknown_081894B4[d->glowFrame][0];
        def[1] = d;
        sub_0815862C(def, d->affine[1], d->affine[2], 8);
        def[0] = gUnk_03003800;
        def[1] = d;
        Sprite_DrawSharedAffine(def, 3, 0xF, 3, 0x380, d->x + dx, d->y + dy, 0);
        if (!(gFrameCounter & 3) && ++d->glowFrame == 5)
            d->glowFrame = 0;
    }
    if (d->ringOn)
    {
        def[0] = gUnknown_081894C8[d->ringFrame][0];
        def[1] = d->ring;
        sub_0815862C(def, d->ring[1], d->ring[2], 8);
        def[0] = gUnk_03003800;
        def[1] = d->ring;
        Sprite_DrawSharedAffine(def, 2, 0xD, 3, 0x1E0, d->x + 0x30, d->y + 0x34, 1);
        if (++d->ringFrame == 2)
            d->ringFrame = 0;
        if (d->ring[1] != 0x100)
        {
            d->ring[1] += 8;
            d->ring[2] += 8;
        }
        else
        {
            d->ringOn = 0;
        }
    }
    if (d->shrink == 1 && d->affine[1] != 0x18)
    {
        d->affine[1]--;
        d->affine[2]--;
    }
}

// sub_080BB5D0 @ 0x080BB5D0
void sub_080BB5D0(struct Task *task)
{
    struct AffineEffect *d = (struct AffineEffect *)task->data.raw;

    d->ringOn = 1;
    d->glowOn = 1;
    d->unk20 = 1;
    Sound_Play(0x98);
}

// sub_080BB5E8 @ 0x080BB5E8
void sub_080BB5E8(struct Task *task, u32 id)
{
    struct AffineEffect *d = (struct AffineEffect *)task->data.raw;

    d->wait = (u16 *)BgPicture_StartTask(id);
}

// sub_080BB5FC @ 0x080BB5FC
void sub_080BB5FC(struct Task *task)
{
    struct AffineEffect *d = (struct AffineEffect *)task->data.raw;

    if (*d->wait != 0)
    {
        task->result = 0;
    }
    else
    {
        task->result = 1;
        d->shrink = 1;
    }
}

// sub_080BB61C @ 0x080BB61C
void sub_080BB61C(void)
{
    DmaSet(3, 0x02001000, 0x06013000, 0x84001200);
}

// sub_080BB640 @ 0x080BB640
void sub_080BB640(struct Task *task)
{
    struct AffineEffect2 *d = (struct AffineEffect2 *)task->data.raw;

    gUnk_03004640 = d;
    d->affine[0] = 1;
    d->affine[1] = 0x100;
    d->affine[2] = 0x100;
    d->affine[3] = 0;
    d->x = 0x78;
    d->y = 0x44;
    d->timer = 8;
    LZ77UnCompWram(gUnknown_08189570, gUnk_02001000);
    LZ77UnCompWram(gUnknown_08189BFC, gUnk_02001000 + 0x1000);
    Palette_CopyWithEffect(3, gUnknown_08189BDC, &gPaletteTarget[0x1E0], 0x20, 0x20);
    Palette_CopyWithEffect(3, gUnknown_0818B1C0, &gPaletteTarget[0x1F0], 0x20, 0x20);
    PalFade_FadeRangeInFromBlackTagged(0x1E0, 0x20, 1, 1);
    VBlankTask_AddCounted(sub_080BB61C, 1);
}

// sub_080BB6E0 @ 0x080BB6E0
void sub_080BB6E0(struct Task *task, u32 id)
{
    struct AffineEffect2 *d = (struct AffineEffect2 *)task->data.raw;

    d->wait = (u16 *)BgPicture_StartTask(id);
}

// sub_080BB6F4 @ 0x080BB6F4
void sub_080BB6F4(struct Task *task)
{
    if (*(u16 *)task->data.w[4] != 0)
        task->result = 0;
    else
        task->result = 1;
}

// sub_080BB70C @ 0x080BB70C
void sub_080BB70C(struct Task *task)
{
    struct AffineEffect2 *d = (struct AffineEffect2 *)task->data.raw;
    const void *def[2];
    u8 matrix = 0;
    const void *const *tbl;

    gUnk_03004640 = d;
    tbl = gUnknown_08007174;
    def[0] = *tbl;
    def[1] = d;
    sub_0815862C(def, d->affine[1], d->affine[2], 8);
    def[0] = gUnk_03003800;
    def[1] = d;
    Sprite_DrawSharedAffine(def, 1, 0xE, 3, 0x180, d->x, d->y, matrix);
    if (!((gFrameCounter >> 2) & 1))
        tbl = gUnknown_080071B0;
    else
        tbl = gUnknown_080071FC;
    def[0] = *tbl;
    def[1] = d;
    sub_0815862C(def, d->affine[1], d->affine[2], 8);
    def[0] = gUnk_03003800;
    def[1] = d;
    Sprite_DrawSharedAffine(def, 0, 0xF, 3, 0x200, d->x, d->y, matrix);
}

// sub_080BB7B4 @ 0x080BB7B4
void sub_080BB7B4(struct Task *task, u32 which)
{
    if (which == 0)
        PalFade_FadeRangeToBlack(0x80, 0x80, 8);
    else
        PalFade_FadeRangeToBlack(0x1E0, 0x20, 1);
}

// sub_080BB7D8 @ 0x080BB7D8
void sub_080BB7D8(struct Task *task, u32 still)
{
    struct AffineEffect2 *d = (struct AffineEffect2 *)task->data.raw;

    if (d->affine[1] != 0x20)
    {
        d->affine[1]--;
        d->affine[2]--;
    }
    if (still == 0)
        gUnk_0300000E--;
    if (--d->timer == 0)
    {
        d->timer = 8;
        d->y--;
        d->x++;
    }
}

// sub_080BB820 @ 0x080BB820
/* Up/Down shrink or grow the sprite (looks like a leftover debug control). */
void sub_080BB820(struct Task *task)
{
    struct AffineEffect2 *d = (struct AffineEffect2 *)task->data.raw;
    if (gRepeatedKeys & 0x40)
    {
        if (d->affine[1] != 0)
        {
            d->affine[1]--;
            d->affine[2]--;
        }
    }
    else if (gRepeatedKeys & 0x80)
    {
        if (d->affine[1] != 0x200)
        {
            d->affine[1]++;
            d->affine[2]++;
        }
    }
}

// sub_080BB868 @ 0x080BB868
void sub_080BB868(const void *src, const u8 *pals, void *dst, u16 *map)
{
    s32 i;

    LZ77UnCompWram(src, dst);
    for (i = 0; i < 0x1D; i++)
    {
        u32 pal = *pals++;

        pal &= 0xF;
        pal += 8;
        *map = (*map & 0xFFF) | (pal << 12);
        map++;
    }
}

// sub_080BB8A0 @ 0x080BB8A0
void sub_080BB8A0(void)
{
    DMA_FILL32(3, 0, 0x06004000, 0x4000);
    DMA_FILL32(3, 0, 0x06003000, 0x1000);
}

// sub_080BB8E0 @ 0x080BB8E0
void sub_080BB8E0(void)
{
    sub_080C14FC();
    Tilemap_FillRect(0, gUnk_02000000, 1, 0, 0x1C, 0xD);
    VBlankTask_AddCounted(sub_080BB8A0, 1);
    VBlankTask_AddCounted(sub_080C153C, 1);
    gHudState[0x18] = 1;
}

// sub_080BB928 @ 0x080BB928
void sub_080BB928(void)
{
    DmaSet(3, 0x02001000, 0x0600E000, 0x84000500);
    DmaSet(3, gUnk_02000000, 0x06001000, 0x84000400);
}
