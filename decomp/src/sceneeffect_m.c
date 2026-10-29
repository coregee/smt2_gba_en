#include "global.h"
#include "sceneeffect.h"

// sub_080BD5CC @ 0x080BD5CC
void sub_080BD5CC(struct Task *task)
{
    struct AffineAnim *d = (struct AffineAnim *)task->data.raw;

    LZ77UnCompWram(gUnknown_0818C0C8, (void *)0x02001000);
    Palette_CopyWithEffect(3, gUnknown_0818C600, &gPaletteBuffer[0x1D0], 0x20, 0x20);
    Palette_MarkDirty();
    VBlankTask_AddCounted(sub_080BC028, 1);
    task->data.h[0] = 1;
    d->affine[1] = 0x140;
    d->affine[2] = 0x140;
    d->affine[3] = 0;
}

// sub_080BD628 @ 0x080BD628
void sub_080BD628(struct Task *task, u32 objMode)
{
    u16 *d = task->data.h;
    const void *def[2];

    def[0] = gUnknown_080078A8[0];
    def[1] = d;
    ObjList_ScalePositions(def, d[1], d[2], 0);
    def[0] = gUnk_03003800;
    def[1] = d;
    Sprite_DrawSharedAffineDouble(def, 0, 0xD, 0, 0x280, 0x78, 0x2B, 0, objMode);
}

// sub_080BD680 @ 0x080BD680
void sub_080BD680(struct Task *task)
{
    u16 *d = task->data.h;

    LZ77UnCompWram(gUnknown_0818C0C8, (void *)0x02001000);
    Palette_CopyWithEffect(3, gUnknown_0818C5E0, &gPaletteBuffer[0x1D0], 0x20, 0x20);
    Palette_MarkDirty();
    VBlankTask_AddCounted(sub_080BC028, 1);
    task->data.h[0] = 1;
    d[1] = 4;
    d[2] = 4;
    d[3] = 0;
}

// sub_080BD6D8 @ 0x080BD6D8
void sub_080BD6D8(struct Task *task)
{
    struct AffineAnim *d = (struct AffineAnim *)task->data.raw;
    const void *const *tbl = gUnknown_080078A8;
    u16 zero = 0;
    const void *def[2];

    def[0] = *tbl;
    def[1] = d;
    ObjList_ScalePositions(def, d->affine[1], d->affine[2], 0);
    def[0] = gUnk_03003800;
    def[1] = d;
    Sprite_DrawSharedAffineDouble(def, 0, 0xD, 0, 0x280, 0x78, 0x27, zero, zero);
}

// sub_080BD72C @ 0x080BD72C
void sub_080BD72C(struct Task *task, u32 delta)
{
    u16 *d = task->data.h;

    d[1] += delta;
    d[2] += delta;
}

// sub_080BD73C @ 0x080BD73C
void sub_080BD73C(void)
{
    sub_080E9044(gUnk_030069C0, 0);
    gUnk_030069C0 = 0;
}

// sub_080BD758 @ 0x080BD758
/* Shows the two demons of gUnk_0203DB28 (ids 0x22 and 0x47) as objects 0x1C1/0x1C0. */
void sub_080BD758(void)
{
    u16 *ids = gUnk_0203DB28;
    u16 zero = 0;

    ids[0] = 0x22;
    gUnk_030068F0[0] = (u32)CharObj_Create(0, 0x1C1, 0x50, 0x43, zero, zero);
    ids[1] = 0x47;
    gUnk_030068F0[1] = (u32)CharObj_Create(1, 0x1C0, 0x50, 0x43, zero, zero);
}

// sub_080BD7A4 @ 0x080BD7A4
void sub_080BD7A4(struct Task *task, u32 mode)
{
    if (mode == 0)
    {
        Palette_FillWithEffect(3, 0x7FFF, &gPaletteBuffer[0x1E0], 0x20, 0x10);
        Palette_FillWithEffect(3, 0x7FFF, &gPaletteBuffer[0x1F0], 0x20, 0x10);
        Palette_MarkDirty();
    }
    else
    {
        Palette_CopyWithEffect(3, sub_080D8248(gUnk_0203DB28[0])->palette, &gPaletteTarget[0x1E0], 0x20, 0x20);
        Palette_CopyWithEffect(3, sub_080D8248(gUnk_0203DB28[1])->palette, &gPaletteTarget[0x1F0], 0x20, 0x20);
        PalFade_FadeRangeWithDuration(0x1E0, 0x20, 1, 0x20);
    }
}

// sub_080BD830 @ 0x080BD830
void sub_080BD830(void)
{
    struct ObjData *a = (struct ObjData *)((struct Task *)gUnk_030068F0[0])->data.raw;
    struct ObjData *b = (struct ObjData *)((struct Task *)gUnk_030068F0[1])->data.raw;

    if (gFrameCounter & 1)
    {
        a->x--;
        b->x++;
    }
}

// sub_080BD864 @ 0x080BD864
void sub_080BD864(void)
{
    sub_080B8AE0(0x7FFF, 1);
}
