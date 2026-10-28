#include "global.h"
#include "title.h"

/* gDemonGfxRecords + id * 0x1C (same table as Demon_GetGfxRecord). */
// sub_080D8248 @ 0x080D8248
struct DemonGfxRecord *sub_080D8248(u16 id)
{
    return &gUnknown_0872C774[id];
}

// sub_080D8260 @ 0x080D8260
void sub_080D8260(void)
{
    DmaSet3(0x02001000, 0x06016000, 0x84000800);
}

/* Loads the battle sprite of party demon gUnk_0203DB28[index] into character slot obj->slot. */
// sub_080D8284 @ 0x080D8284
void sub_080D8284(struct Task *task, u32 index)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    struct DemonGfxRecord *rec = sub_080D8248(gUnk_0203DB28[index]);
    u16 slot = obj->slot;

    obj->unk24 = index;
    if (slot == 0)
    {
        HuffUnComp(rec->gfx0, gUnk_0200AFC8);
        LZ77UnCompWram(gUnk_0200AFC8, gUnk_02001000);
        sub_080C3F4C(obj, rec->palette, 0x1E0, 0x20, 1);
        if (rec->gfx1 == NULL)
        {
            VBlankTask_AddCounted(sub_080C3EBC, 1);
        }
        else
        {
            HuffUnComp(rec->gfx1, gUnk_0200AFC8 + 0x1000);
            LZ77UnCompWram(gUnk_0200AFC8 + 0x1000, gUnk_02001000 + 0x1000);
            VBlankTask_AddCounted(sub_080D8260, 1);
        }
    }
    else if (slot == 1)
    {
        HuffUnComp(rec->gfx0, (void *)0x0200BFC8);
        LZ77UnCompWram((void *)0x0200BFC8, (void *)0x02002000);
        sub_080C3F4C(obj, rec->palette, 0x1F0, 0x20, slot);
        VBlankTask_AddCounted(sub_080C3EE0, 1);
    }
    else
    {
        HuffUnComp(rec->gfx0, (void *)0x0200CFC8);
        LZ77UnCompWram((void *)0x0200CFC8, (void *)0x02003000);
        sub_080C3F4C(obj, rec->palette, 0x1D0, 0x20, 1);
        VBlankTask_AddCounted(sub_080C3F04, 1);
    }
}

/* Draws the demon loaded by sub_080D8284, alternating its two cells every 16 frames.
   Slots other than 0..2 leave tile/palette uninitialised (never happens in practice). */
// sub_080D8384 @ 0x080D8384
void sub_080D8384(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    struct DemonGfxRecord *rec = sub_080D8248(gUnk_0203DB28[obj->unk24]);
    u16 frame = sub_080C4388(obj);
    const void **cells = rec->anim->cells;
    const void *sprite;
    u16 pal, tile;

    if (!((gFrameCounter >> 4) & 1))
        cells += 2;
    sprite = *cells;
    switch (obj->slot)
    {
    case 0:
        pal = 0xE;
        tile = 0x300;
        break;
    case 1:
        pal = 0xF;
        tile = 0x380;
        break;
    case 2:
        pal = 0xD;
        tile = 0x280;
        break;
    }
    sub_080C44CC(obj, sprite, frame, pal, obj->unk10, tile, obj->unk08 + 0x28,
                 obj->unk0A - (s16)(gUnk_0300000E - 0x58));
}

// sub_080D8428 @ 0x080D8428
void sub_080D8428(struct Task *task)
{
    sub_080D7A84(task, gUnknown_08005064);
}

// sub_080D8438 @ 0x080D8438
void sub_080D8438(struct Task *task)
{
    sub_080D7A84(task, gUnknown_08005088);
}

// sub_080D8448 @ 0x080D8448
void sub_080D8448(struct Task *task)
{
    task->data.h[5] = 1;
    sub_080D7A84(task, gUnknown_08005104);
}

// sub_080D845C @ 0x080D845C
void sub_080D845C(struct Task *task)
{
    sub_080D7A84(task, gUnknown_0800520C);
}

// sub_080D846C @ 0x080D846C
void sub_080D846C(struct Task *task)
{
    if ((gFrameCounter >> 4) & 1)
        sub_080C44B0(task);
}

// sub_080D848C @ 0x080D848C
void sub_080D848C(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;

    obj->anim = Task_Create(gUnknown_081A64A8, task->id);
}

// sub_080D84A8 @ 0x080D84A8
void sub_080D84A8(struct Task *task)
{
    if (task->data.h[3] == 0xF2)
    {
        if ((gFrameCounter >> 4) & 1)
            sub_080D7A84(task, gUnknown_080054D4);
        else
            sub_080D7A84(task, gUnknown_08005514);
    }
    else
    {
        sub_080D7A84(task, gUnknown_080054D4);
    }
}

// sub_080D84EC @ 0x080D84EC
void sub_080D84EC(struct Task *task)
{
    sub_080D7A84(task, gUnknown_08005554);
}

// sub_080D84FC @ 0x080D84FC
void sub_080D84FC(struct Task *task)
{
    if (task->data.h[3] == 0xF3)
    {
        if ((gFrameCounter >> 4) & 1)
            sub_080D7A84(task, gUnknown_0800559C);
        else
            sub_080D7A84(task, gUnknown_080055E4);
    }
    else
    {
        sub_080D7A84(task, gUnknown_0800559C);
    }
}

// sub_080D8540 @ 0x080D8540
void sub_080D8540(struct Task *task)
{
    sub_080D7A84(task, gUnknown_08005624);
}

// sub_080D8550 @ 0x080D8550
void sub_080D8550(struct Task *task)
{
    sub_080D7A84(task, gUnknown_08005664);
}

// sub_080D8560 @ 0x080D8560
void sub_080D8560(void)
{
    DmaSet3(0x02003000, 0x06015000, 0x84000200);
}

// sub_080D8584 @ 0x080D8584
void sub_080D8584(void)
{
    LZ77UnCompWram(gUnknown_085171C4, (void *)0x02003000);
    Palette_CopyWithEffect(3, gUnknown_08517414, gUnk_03003150, 0x20, 0x20);
    Palette_MarkDirty();
    VBlankTask_AddCounted(sub_080D8560, 1);
}

// sub_080D85C8 @ 0x080D85C8
void sub_080D85C8(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    u16 frame = sub_080C4388(obj);
    u16 y = obj->unk0A;

    sub_080C44CC(obj, gUnknown_085651B0[obj->id - 0x3B], frame, 0xD, obj->unk10, 0x280, obj->unk08, y);
}

// sub_080D8610 @ 0x080D8610
void sub_080D8610(struct Task *task, const void *sprite)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    u16 slot = obj->slot;
    u16 frame = sub_080C4388(obj);
    u16 y;

    y = obj->unk0A;
    y -= gUnk_0300000E;
    if (slot == 0)
        sub_080C44CC(obj, sprite, frame, 0xE, obj->unk10, 0x300, obj->unk08 + 0x28, y + 0x2C);
    else if (slot == 1)
        sub_080C44CC(obj, sprite, frame, 0xF, obj->unk10, 0x380, obj->unk08 + 0x28, y + 0x2C);
    else
        sub_080C44CC(obj, sprite, frame, 0xD, obj->unk10, 0x280, obj->unk08 + 0x28, y + 0x2C);
}

// sub_080D86C8 @ 0x080D86C8
void sub_080D86C8(struct Task *task)
{
    sub_080D8610(task, gUnknown_0800521C);
}

// sub_080D86D8 @ 0x080D86D8
void sub_080D86D8(struct Task *task)
{
    sub_080D8610(task, gUnknown_0800522C);
}

// sub_080D86E8 @ 0x080D86E8
void sub_080D86E8(struct Task *task)
{
    sub_080D8610(task, gUnknown_0800523C);
}

// sub_080D86F8 @ 0x080D86F8
void sub_080D86F8(struct Task *task)
{
    sub_080D8610(task, gUnknown_08005254);
}

// sub_080D8708 @ 0x080D8708
void sub_080D8708(struct Task *task)
{
    sub_080D8610(task, gUnknown_08005278);
}

// sub_080D8718 @ 0x080D8718
void sub_080D8718(struct Task *task)
{
    sub_080D8610(task, gUnknown_08005290);
}

// sub_080D8728 @ 0x080D8728
void sub_080D8728(struct Task *task)
{
    sub_080D8610(task, gUnknown_080052C0);
}

// sub_080D8738 @ 0x080D8738
void sub_080D8738(struct Task *task)
{
    sub_080D8610(task, gUnknown_080052F0);
}

// sub_080D8748 @ 0x080D8748
void sub_080D8748(struct Task *task)
{
    sub_080D8610(task, gUnknown_08005314);
}

// sub_080D8758 @ 0x080D8758
void sub_080D8758(struct Task *task)
{
    sub_080D8610(task, gUnknown_08005338);
}

// sub_080D8768 @ 0x080D8768
void sub_080D8768(void)
{
    DmaSet3(0x02003000, 0x06015000, 0x84000400);
}

/* Another character task (not `self`) showing character `id`, or NULL. */
// sub_080D878C @ 0x080D878C
struct Task *sub_080D878C(struct Task *self, u16 id)
{
    u32 i;
    struct Task **p;

    for (i = 0, p = gUnk_02036094; i < 6; p++, i++)
    {
        struct Task *t = *p;

        if (t != NULL && t != self && t->data.h[3] == id)
            return t;
    }
    return NULL;
}
