#include "global.h"
#include "sceneeffect.h"

// sub_080BCA6C @ 0x080BCA6C
void sub_080BCA6C(struct Task *task, u32 frame)
{
    Sprite_Draw(gUnknown_0818F634[frame], 7, 0xF, 2, 0x240, 0x78, 0x46);
}

// sub_080BCA9C @ 0x080BCA9C
void sub_080BCA9C(struct Task *task, u32 which)
{
    u32 *d = task->data.w;

    if (which == 0)
        task->data.w[0] = (u32)Task_Create(gUnknown_0818F564, 0xFFFF);
    else
        d[1] = (u32)Task_Create(gUnknown_0818F650, 0xFFFF);
}

// sub_080BCAD4 @ 0x080BCAD4
void sub_080BCAD4(struct Task *task)
{
    u32 *d = task->data.w;

    Task_End((struct Task *)task->data.w[0]);
    Task_End((struct Task *)d[1]);
}

// sub_080BCAEC @ 0x080BCAEC
void sub_080BCAEC(struct Task *task)
{
    struct AffineAnim *d = (struct AffineAnim *)task->data.raw;

    d->affine[1] = 4;
    d->affine[2] = 4;
    d->affine[3] = 0;
}

// sub_080BCAFC @ 0x080BCAFC
void sub_080BCAFC(struct Task *task)
{
    u16 *d = task->data.h;
    const void *const *tbl = gUnknown_08006170;
    u16 dx = d[1] * 40 / 255;
    u16 dy = d[1] * 36 / 255;
    const void *def[2];

    def[0] = tbl[0];
    def[1] = d;
    sub_0815851C(def);
    def[0] = gUnk_03003800;
    def[1] = d;
    /* Draws the sprite table itself, not the scaled copy prepared in def. */
    if (gFrameCounter & 1)
        Sprite_Draw(tbl, 0, 0xD, 0, 0x3C0, d[5] + dx, d[6] - dy);
}

// sub_080BCB80 @ 0x080BCB80
void sub_080BCB80(struct Task *task, u32 delta)
{
    u16 *d = task->data.h;

    d[1] += delta;
    d[2] += delta;
}

// sub_080BCB90 @ 0x080BCB90
void sub_080BCB90(struct Task *task, u32 step)
{
    if (step == 0)
    {
        sub_080C4618(0, 0x195, 0xF0, -13, 0, 0);
    }
    else
    {
        u16 *d = Char_FindById(0x195)->data.h;

        d[4]--;
        gUnk_03000004++;
    }
}

// sub_080BCBD8 @ 0x080BCBD8
void sub_080BCBD8(struct Task *task, u32 step)
{
    if (step == 0)
    {
        sub_080C4618(1, 0xC0, 0x50, -45, 0, 0);
    }
    else
    {
        if (Char_FindById(0xC0) == NULL)
            task->result = 1;
        else
            task->result = 0;
    }
}

// sub_080BCC14 @ 0x080BCC14
void sub_080BCC14(void)
{
    DmaSet(3, 0x02001000, 0x06017800, 0x84000200);
}

// sub_080BCC38 @ 0x080BCC38
void sub_080BCC38(void)
{
    LZ77UnCompWram(gUnknown_08532ABC, (void *)0x02001000);
    Palette_CopyWithEffect(3, gUnknown_08532D50, &gPaletteBuffer[0x1D0], 0x20, 0x20);
    Palette_MarkDirty();
    VBlankTask_AddCounted(sub_080BCC14, 1);
}

// sub_080BCC7C @ 0x080BCC7C
void sub_080BCC7C(void)
{
    u16 *d = Task_Create(gUnknown_0818F760, 0xFFFF)->data.h;

    d[5] = (sub_080C2244() & 0x3F) + 0x30;
    d[6] = (sub_080C2244() & 0x3F) + 0xFFF3;
}
