#include "global.h"
#include "sceneeffect.h"

// sub_080BCFB0 @ 0x080BCFB0
void sub_080BCFB0(struct Task *task)
{
    gHudState[0x1A] = 1;
}

// sub_080BCFBC @ 0x080BCFBC
void sub_080BCFBC(struct Task *task)
{
    sub_080C6E30(1);
    gHudState[0x18] = 1;
    sub_080BCFB0(task);
    gUnk_03004534 = 0;
    VBlankTask_AddCounted(sub_080BCEF0, 1);
}

// sub_080BCFF4 @ 0x080BCFF4
/* Huffman then LZ77 decompression of src to 0x02001000 + offset. */
void sub_080BCFF4(struct Task *task, const void *src, u32 offset)
{
    HuffUnComp(src, (void *)0x0200AFC8);
    LZ77UnCompWram((void *)0x0200AFC8, (u8 *)0x02001000 + offset);
}

// sub_080BD01C @ 0x080BD01C
void sub_080BD01C(void)
{
    DmaSet(3, gUnk_02000000, 0x06003000, 0x84000400);
    DmaSet(3, 0x02001000, 0x06004000, 0x84001500);
    REG_DISPCNT = 0x7800;
    gUnk_03000030 = gUnk_03000032 = 0xE8;
    gUnk_03000031 = gUnk_03000033 = 8;
    gUnk_03000034 = gUnk_03000036 = 0x68;
    gUnk_03000035 = gUnk_03000037 = 0;
    gUnk_03000038 = 0x3F;
    gUnk_03000039 = 0x3F;
    gUnk_0300003A = 0;
    gUnk_0300003B = 0;
    gUnk_0300000E = 0;
    gUnk_0300000C = 0;
}

// sub_080BD0E0 @ 0x080BD0E0
void sub_080BD0E0(void)
{
    HuffUnComp(gUnknown_08194C78, (void *)0x0200AFC8);
    LZ77UnCompWram((void *)0x0200AFC8, gUnk_02000000);
    Palette_CopyWithEffect(3, gUnknown_08195278, gPaletteTarget, 0x100, 0x20);
    VBlankTask_AddCounted(sub_080BD01C, 1);
}

// sub_080BD130 @ 0x080BD130
void sub_080BD130(void)
{
    DmaSet(3, 0x02001000, 0x06010000, 0x84001000);
}

// sub_080BD154 @ 0x080BD154
void sub_080BD154(struct Task *task)
{
    struct AffineAnim *d = (struct AffineAnim *)task->data.raw;

    Palette_CopyWithEffect(3, gUnknown_08196438, &gPaletteTarget[0x1E0], 0x20, 0x20);
    Palette_CopyWithEffect(3, gUnknown_08196C80, &gPaletteTarget[0x1F0], 0x20, 0x20);
    VBlankTask_AddCounted(sub_080BD130, 1);
    d->affine[1] = 0x100;
    d->affine[2] = 0x100;
    d->affine[3] = 0;
    d->frame = 0;
    d->timer = 0x20;
    d->x2 = 0x78;
    d->y2 = 0xFFF8;
    d->x1 = 0x118;
    d->y1 = 0x48;
}

// sub_080BD1C4 @ 0x080BD1C4
void sub_080BD1C4(struct Task *task)
{
    struct AffineAnim *d = (struct AffineAnim *)task->data.raw;
    const void *const *tbl;
    const void *def[2];

    if (!((gFrameCounter >> 2) & 1))
        tbl = gUnknown_080075A0;
    else
        tbl = gUnknown_080075D8;
    def[0] = *tbl;
    def[1] = d;
    sub_0815862C(def, d->affine[1], d->affine[2], 0);
    def[0] = gUnk_03003800;
    def[1] = d;
    if (d->affine[1] != 4)
        Sprite_DrawSharedAffine(def, 0, 0xF, 0, 0x140, d->x1, d->y1, 0);
    tbl = gUnknown_08196CA0[d->frame];
    def[0] = *tbl;
    def[1] = d;
    sub_0815862C(def, d->affine[1], d->affine[2], 0);
    def[0] = gUnk_03003800;
    def[1] = d;
    if (d->affine[1] != 4)
        Sprite_DrawSharedAffine(def, 0, 0xE, 0, 0, d->x2, d->y2, 0);
    if (d->frame != 0xC && --d->timer == 0)
    {
        d->timer = 0x20;
        d->frame++;
    }
    if (!(gFrameCounter & 3))
        gUnk_0300000E++;
}
