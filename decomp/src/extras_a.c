#include "global.h"
#include "extras.h"

// sub_080D977C @ 0x080D977C
void sub_080D977C(void)
{
    if (gUnk_0300609C == 0)
        Font_ResetGlyphSpriteCache(0x180);
    Wave_Update();
    Task_RunAll();
}

/* Script op: Huffman + LZ77 decode into 0x02001000 + offset. */
// sub_080D97A0 @ 0x080D97A0
void sub_080D97A0(struct Task *task, const void *src, u32 offset)
{
    u8 *dst = gUnk_02001000 + offset;

    HuffUnComp(src, gBgPictureBuffer);
    LZ77UnCompWram(gBgPictureBuffer, dst);
}

// sub_080D97C8 @ 0x080D97C8
void sub_080D97C8(struct Task *task, void (*func)(void))
{
    VBlankTask_AddCounted(func, 1);
}

// sub_080D97D8 @ 0x080D97D8
void sub_080D97D8(void)
{
    u8 *buf = gUnk_02001000;

    DmaSet3(buf, 0x06004040, 0x840007F0);
}

// sub_080D97FC @ 0x080D97FC
void sub_080D97FC(void)
{
    u8 *buf = gUnk_02001000;

    DmaSet3(buf + 0x1FC0, 0x06008040, 0x84000ED0);
}

// sub_080D9824 @ 0x080D9824
void sub_080D9824(void)
{
    u8 *buf = gUnk_02001000;

    DmaSet3(buf + 0x1FC0, 0x06008040, 0x84000370);
    DmaSet3(buf + 0x4000, 0x06008E00, 0x84000B60);
}

// sub_080D9868 @ 0x080D9868
void sub_080D9868(void)
{
    DmaSet3(gUnk_02000000, 0x06003040, 0x84000200);
}

/* Copies a 32x26 tilemap to 0x02000000 and adds a palette (8 + low nibble) from attr to
   the 28 tiles from column 1 of each row. */
// sub_080D988C @ 0x080D988C
void sub_080D988C(struct Task *task, const void *map, const u8 *attr)
{
    u16 *buf = (u16 *)gUnk_02000000;
    u32 y, x;

    DmaSet3(map, buf, 0x84000400);
    y = 0;
    do
    {
        u16 *p;
        u32 next;
        u32 two = 2;

        x = 0;
        next = y + 1;
        {
            u32 off = y << 6;

            two += (u32)buf;    /* p = &buf[1 + y * 32] */
            p = (u16 *)(off + two);
        }
        for (; x < 0x1C; x++)
        {
            u32 v = *attr++;

            v &= 0xF;
            v += 8;
            *p += v << 12;
            p++;
        }
        y = next;
    } while (y < 26);
    VBlankTask_AddCounted(sub_080D9868, 1);
}

/* Same, mirrored: 14 attributes per row applied from both ends. */
// sub_080D98EC @ 0x080D98EC
void sub_080D98EC(struct Task *task, const void *map, const u8 *attr)
{
    u16 *buf = (u16 *)gUnk_02000000;
    u32 y, x;
    u16 *p, *q;

    DmaSet3(map, buf, 0x84000400);
    y = 0;
    do
    {
        u32 next;

        x = 0;
        {
            u32 k = y * 32;
            u32 two = 2;    /* p = &buf[1 + y * 32]; q = &buf[y * 32 + 28] */

            next = y + 1;
            k += 28;
            p = (u16 *)((y << 6) + ((u32)buf + two));
            q = (u16 *)((k << 1) + (u32)buf);
        }
        for (; x < 14; x++)
        {
            u32 v = *attr++;

            v &= 0xF;
            v += 8;
            v <<= 12;
            *p += v;
            *q += v;
            q--;
            p++;
        }
        y = next;
    } while (y < 26);
    VBlankTask_AddCounted(sub_080D9868, 1);
}

// sub_080D9968 @ 0x080D9968
void sub_080D9968(struct Task *task, const void *pal)
{
    Palette_CopyWithEffect(3, pal, gPaletteTarget + 0x80, 0x100, 0x20);
}

// sub_080D9988 @ 0x080D9988
void sub_080D9988(void)
{
    PalFade_FadeRangeInFromBlackTagged(0x80, 0x80, 1, 0x8001);
}

// sub_080D99A0 @ 0x080D99A0
void sub_080D99A0(void)
{
    PalFade_FadeRangeToBlackTagged(0x80, 0x80, 1, 0x8001);
}

// sub_080D99B8 @ 0x080D99B8
void sub_080D99B8(void)
{
    Palette_CopyWithEffect(3, gUnknown_081B6C30, gPaletteTarget + 0x100, 0x100, 0x20);
    Palette_CopyWithEffect(3, gUnknown_08580A60, gPaletteTarget + 0x170, 0x20, 0x20);
    PalFade_FadeRangeInFromBlack(0x80, 0x180, 1);
}

// sub_080D9A00 @ 0x080D9A00
void sub_080D9A00(void)
{
    PalFade_FadeRangeToBlack(0x80, 0x180, 1);
}

// sub_080D9A14 @ 0x080D9A14
void sub_080D9A14(void)
{
    DmaSet3(gUnk_02024074, 0x06002000, 0x84000140);
}

// sub_080D9A38 @ 0x080D9A38
void sub_080D9A38(void)
{
    DmaSet3(0x02006000, 0x06010000, 0x84000800);
}

// sub_080D9A5C @ 0x080D9A5C
void sub_080D9A5C(void)
{
    DmaSet3(gUnknown_08573AF4, 0x06012000, 0x84000200);
}

// sub_080D9A80 @ 0x080D9A80
void sub_080D9A80(void)
{
    DmaSet3(gUnk_02001000, 0x0600BC00, 0x84001100);
    sub_080D9A14();
    sub_080D9A38();
    sub_080D9A5C();
}

// sub_080D9AB4 @ 0x080D9AB4
void sub_080D9AB4(void)
{
    Palette_CopyWithEffect(3, gUnknown_08580880, gPaletteTarget, 0x20, 0x20);
    Palette_CopyWithEffect(3, gUnknown_081B6C30, gPaletteTarget + 0x100, 0x100, 0x20);
    Palette_CopyWithEffect(3, gUnknown_08580A60, gPaletteTarget + 0x170, 0x20, 0x20);
    gPaletteBuffer[0] = 0;
    gPaletteTarget[0] = 0;
    DmaSet3(gUnknown_0857D9C0, gUnk_02024074, 0x84000140);
}

// sub_080D9B34 @ 0x080D9B34
void sub_080D9B34(void)
{
    Tilemap_FillRect(0, gUnk_02024074, 1, 1, 28, 18);
    VBlankTask_AddCounted(sub_080D9A14, 1);
}

// sub_080D9B64 @ 0x080D9B64
void sub_080D9B64(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;

    Sprite_Draw(d->spr18, 0, 7, 0, 0x100, 0x10, task->data.h[0] * 11 + 14);
    Sprite_Draw(d->spr14, 0, 7, 0, 0, 0x10, 0x10);
}

// sub_080D9BAC @ 0x080D9BAC
void sub_080D9BAC(void)
{
    DmaSet3(gUnk_02024074, 0x06002000, 0x84000400);
}

// sub_080D9BD0 @ 0x080D9BD0
void sub_080D9BD0(struct Task *task, const void *map, u32 w, u32 h, const void *spr14, const void *spr18, u32 cursor)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;

    Tilemap_CopyRectSkipZero(map, gUnk_02024074, 0, 0, 1, 1, w, h);
    VBlankTask_AddCounted(sub_080D9BAC, 1);
    task->onFrame = sub_080D9B64;
    task->data.h[0] = cursor;
    d->spr14 = spr14;
    d->spr18 = spr18;
}

// sub_080D9C24 @ 0x080D9C24
void sub_080D9C24(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    u32 i;

    Sprite_Draw(d->spr18, 0, 7, 0, 0x100, 0x10, task->data.h[0] * 11 + 14);
    for (i = 0; i < d->count; i++)
    {
        Sprite_Draw(gUnknown_085814A0[i], 0, 7, 0, 0, 0x10, i * 11 + 17);
        Sprite_Draw(gUnknown_085814B4[d->items[i] - 1], 0, 7, 0, 0, 0x20, i * 11 + 17);
    }
}

// sub_080D9CD0 @ 0x080D9CD0
void sub_080D9CD0(struct Task *task, const void *map, u32 w, u32 h, const void *spr14, const void *spr18, u32 cursor)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;

    Tilemap_CopyRectSkipZero(map, gUnk_02024074, 0, 0, 1, 1, w, h);
    VBlankTask_AddCounted(sub_080D9BAC, 1);
    task->onFrame = sub_080D9C24;
    task->data.h[0] = cursor;
    d->spr14 = spr14;
    d->spr18 = spr18;
}

// sub_080D9D24 @ 0x080D9D24
void sub_080D9D24(void)
{
    DmaSet3(gUnk_0201D874, 0x06001000, 0x84000400);
}

// sub_080D9D48 @ 0x080D9D48
void sub_080D9D48(struct Task *task, const void *map, u32 x, u32 y, u32 w, u32 h)
{
    Tilemap_CopyRectSkipZero(map, gUnk_0201D874, 0, 0, x, y, w, h);
    VBlankTask_AddCounted(sub_080D9D24, 1);
}

// sub_080D9D8C @ 0x080D9D8C
void sub_080D9D8C(void)
{
    Tilemap_FillRect(0, gUnk_0201D874, 1, 1, 28, 18);
    VBlankTask_AddCounted(sub_080D9D24, 1);
}

// sub_080D9DBC @ 0x080D9DBC
void sub_080D9DBC(struct Task *task, u32 x, u32 y, u32 w, u32 h)
{
    Tilemap_FillRect(0, gUnk_0201D874, x, y, w, h);
    VBlankTask_AddCounted(sub_080D9D24, 1);
}

/* Window 0 rectangle (WIN0H/WIN0V shadows at 0x03000030..). */
// sub_080D9E00 @ 0x080D9E00
void sub_080D9E00(struct Task *task, u8 left, u8 right)
{
    gUnk_03000030 = right;
    gUnk_03000031 = left;
    gUnk_03000034 = 0x58;
    gUnk_03000035 = 8;
    gUnk_03000038 = 0x2B;
}

// sub_080D9E30 @ 0x080D9E30
void sub_080D9E30(struct Task *task, u8 left, u8 right)
{
    gUnk_03000030 = right;
    gUnk_03000031 = left;
    gUnk_03000034 = 0x58;
    gUnk_03000035 = 0x58;
    gUnk_03000038 = 0x2B;
}

// sub_080D9E60 @ 0x080D9E60
void sub_080D9E60(struct Task *task, u32 delta)
{
    gUnk_03000035 += delta;
}

// sub_080D9E70 @ 0x080D9E70
void sub_080D9E70(void)
{
    gUnk_03000030 = 0xE8;
    gUnk_03000031 = 8;
    gUnk_03000034 = 0x98;
    gUnk_03000035 = 8;
    gUnk_03000038 = 0x29;
}

// sub_080D9EA4 @ 0x080D9EA4
void sub_080D9EA4(void)
{
    gUnk_03000030 = 0xE8;
    gUnk_03000031 = 8;
    gUnk_03000034 = 0x98;
    gUnk_03000035 = 0x98;
    gUnk_03000038 = 0x29;
}

// sub_080D9ED8 @ 0x080D9ED8
void sub_080D9ED8(struct Task *task, u32 delta)
{
    gUnk_03000035 += delta;
}

// sub_080D9EE8 @ 0x080D9EE8
void sub_080D9EE8(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;

    if (d->win == NULL)
    {
        d->win = Window_Create(2, 12, 26, 6, 0);
        d->win->parent = task->id;
    }
}

// sub_080D9F14 @ 0x080D9F14
void sub_080D9F14(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;

    if (d->win == NULL)
    {
        d->win = Window_CreateOpen(2, 12, 26, 6, 0);
        d->win->parent = task->id;
    }
}

// sub_080D9F40 @ 0x080D9F40
void sub_080D9F40(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;

    if (d->win != NULL)
    {
        d->win->onFrame = NULL;
        Window_Close(d->win);
        d->win = NULL;
    }
}

// sub_080D9F5C @ 0x080D9F5C
void sub_080D9F5C(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;

    if (d->win != NULL)
        d->win->onFrame = NULL;
}

// sub_080D9F6C @ 0x080D9F6C
void sub_080D9F6C(struct Task *task, void (*onFrame)(struct Task *))
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;

    if (d->win != NULL)
        d->win->onFrame = onFrame;
}
