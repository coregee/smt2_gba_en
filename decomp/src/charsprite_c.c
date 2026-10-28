#include "global.h"
#include "title.h"

/* Loads the shared graphics for characters 0xAC..0xAF unless one of them is already shown. */
// sub_080D87C0 @ 0x080D87C0
void sub_080D87C0(struct Task *task)
{
    const u8 *src;
    u8 *dst;

    if (Char_FindOther(task, 0xAC) != NULL || Char_FindOther(task, 0xAD) != NULL
        || Char_FindOther(task, 0xAE) != NULL || Char_FindOther(task, 0xAF) != NULL)
        return;
    LZ77UnCompWram(gUnknown_0852C434, gUnk_02003000);
    LZ77UnCompWram(gUnknown_0852C8CC, gUnk_02003000 + 0x800);
    src = gUnknown_0852CC0C;
    dst = gUnk_03002D10;
    Palette_CopyWithEffect(3, src, dst, 0x20, 0x20);
    Palette_CopyWithEffect(3, src + 0x20, dst + 0x20, 0x20, 0x20);
    Palette_CopyWithEffect(3, src + 0x40, dst + 0x40, 0x20, 0x20);
    Palette_CopyWithEffect(3, src + 0x60, dst + 0x80, 0x20, 0x20);
    if (Palette_IsBg13Black() == 0)
    {
        DmaSet3(dst, gUnk_03003110, 0x84000008);
        DmaSet3(dst + 0x20, gUnk_03003110 + 0x20, 0x84000008);
        DmaSet3(dst + 0x40, gUnk_03003110 + 0x40, 0x84000008);
        DmaSet3(dst + 0x80, gUnk_03003110 + 0x80, 0x84000008);
        Palette_MarkDirty();
    }
    else
    {
        PalFade_FadeRangeInFromBlackTagged(0x1B0, 0x10, 1, 1);
        PalFade_FadeRangeInFromBlackTagged(0x1C0, 0x10, 1, 1);
        PalFade_FadeRangeInFromBlackTagged(0x1D0, 0x10, 1, 1);
        PalFade_FadeRangeInFromBlackTagged(0x1F0, 0x10, 1, 1);
    }
    VBlankTask_AddCounted(sub_080D8768, 1);
}

// sub_080D8924 @ 0x080D8924
void sub_080D8924(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    u16 frame = sub_080C4388(obj);

    switch (obj->id)
    {
    case 0xAC:
        sub_080C44CC(obj, gUnknown_0800536C, frame, 0xB, obj->unk10, 0x280, obj->unk08, obj->unk0A);
        break;
    case 0xAD:
        sub_080C44CC(obj, gUnknown_080053C4, frame, 0xB, obj->unk10, 0x280, obj->unk08, obj->unk0A);
        break;
    case 0xAE:
        sub_080C44CC(obj, gUnknown_080053F8, frame, 0xB, obj->unk10, 0x280, obj->unk08, obj->unk0A);
        break;
    case 0xAF:
        sub_080C44CC(obj, gUnknown_0800542C, frame, 0xC, obj->unk10, 0x280, obj->unk08, obj->unk0A);
        break;
    }
}

// sub_080D89AC @ 0x080D89AC
void sub_080D89AC(struct Task *task, const void *sprite)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    u16 slot = obj->slot;
    u16 frame = sub_080C4388(obj);
    u16 y;

    y = obj->unk0A;
    y -= gUnk_0300000E;
    if (slot == 0)
        sub_080C44CC(obj, sprite, frame, 0xE, obj->unk10, 0x300, obj->unk08 + 0x28, y - 0x12);
    else if (slot == 1)
        sub_080C44CC(obj, sprite, frame, 0xF, obj->unk10, 0x380, obj->unk08 + 0x28, y - 0x12);
    else
        sub_080C44CC(obj, sprite, frame, 0xD, obj->unk10, 0x280, obj->unk08 + 0x28, y - 0x12);
}

// sub_080D8A64 @ 0x080D8A64
void sub_080D8A64(struct Task *task)
{
    sub_080D89AC(task, gUnknown_08005460);
}

// sub_080D8A74 @ 0x080D8A74
void sub_080D8A74(struct Task *task)
{
    sub_080D89AC(task, gUnknown_08005494);
}

// sub_080D8A84 @ 0x080D8A84
void sub_080D8A84(void)
{
    DmaSet3(0x02001000, 0x06016000, 0x84000600);
}

// sub_080D8AA8 @ 0x080D8AA8
void sub_080D8AA8(void)
{
    LZ77UnCompWram(gUnknown_085332EC, gUnk_02001000);
    LZ77UnCompWram(gUnknown_08533788, gUnk_02001000 + 0x800);
    LZ77UnCompWram(gUnknown_08533C94, gUnk_02001000 + 0x1000);
    Palette_CopyWithEffect(3, gUnknown_085340D8, gUnk_03003170, 0x20, 0x20);
    Palette_MarkDirty();
    VBlankTask_AddCounted(sub_080D8A84, 1);
}

// sub_080D8B10 @ 0x080D8B10
void sub_080D8B10(struct Task *task)
{
    sub_080D89AC(task, gUnknown_08005810);
}

// sub_080D8B20 @ 0x080D8B20
void sub_080D8B20(struct Task *task)
{
    sub_080D89AC(task, gUnknown_08005850);
}

// sub_080D8B30 @ 0x080D8B30
void sub_080D8B30(struct Task *task)
{
    sub_080D89AC(task, gUnknown_08005898);
}

// sub_080D8B40 @ 0x080D8B40
void sub_080D8B40(struct Task *task)
{
    sub_080D89AC(task, gUnknown_080058EC);
}

// sub_080D8B50 @ 0x080D8B50
void sub_080D8B50(struct Task *task)
{
    sub_080D89AC(task, gUnknown_0800594C);
}

// sub_080D8B60 @ 0x080D8B60
void sub_080D8B60(struct Task *task)
{
    sub_080D89AC(task, gUnknown_080056AC);
}

// sub_080D8B70 @ 0x080D8B70
void sub_080D8B70(struct Task *task)
{
    sub_080D89AC(task, gUnknown_080056F8);
}

// sub_080D8B80 @ 0x080D8B80
void sub_080D8B80(struct Task *task)
{
    sub_080D89AC(task, gUnknown_08005744);
}

// sub_080D8B90 @ 0x080D8B90
void sub_080D8B90(struct Task *task)
{
    sub_080D89AC(task, gUnknown_08005790);
}

// sub_080D8BA0 @ 0x080D8BA0
void sub_080D8BA0(struct Task *task)
{
    sub_080D89AC(task, gUnknown_080057D0);
}

// sub_080D8BB0 @ 0x080D8BB0
void sub_080D8BB0(struct Task *task)
{
    sub_080D89AC(task, gUnknown_0800595C);
}

// sub_080D8BC0 @ 0x080D8BC0
void sub_080D8BC0(struct Task *task)
{
    sub_080D89AC(task, gUnknown_08005974);
}

// sub_080D8BD0 @ 0x080D8BD0
void sub_080D8BD0(struct Task *task)
{
    sub_080D89AC(task, gUnknown_0800598C);
}

// sub_080D8BE0 @ 0x080D8BE0
void sub_080D8BE0(struct Task *task)
{
    sub_080D89AC(task, gUnknown_080059A4);
}

// sub_080D8BF0 @ 0x080D8BF0
void sub_080D8BF0(struct Task *task)
{
    sub_080D89AC(task, gUnknown_080059B4);
}

// sub_080D8C00 @ 0x080D8C00
void sub_080D8C00(struct Task *task)
{
    sub_080D89AC(task, gUnknown_080059C4);
}

// sub_080D8C10 @ 0x080D8C10
void sub_080D8C10(void)
{
    DmaSet3(0x02001000, 0x06016000, 0x84000600);
}

/* Picks a random sprite (table 0x08565C08, 16 entries) and a random speed 1..2. */
// sub_080D8C34 @ 0x080D8C34
void sub_080D8C34(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    u32 speed;

    LZ77UnCompWram(gUnknown_08535510, gUnk_02001000);
    LZ77UnCompWram(gUnknown_08535988, gUnk_02001000 + 0x800);
    LZ77UnCompWram(gUnknown_08535FB8, gUnk_02001000 + 0x1000);
    Palette_CopyWithEffect(3, gUnknown_08536318, gUnk_03003170, 0x20, 0x20);
    Palette_MarkDirty();
    VBlankTask_AddCounted(sub_080D8C10, 1);
    obj->unk24 = (u32)gUnknown_08565C08[sub_080C2244() & 0xF];
    speed = (sub_080C2244() & 1) + 1;
    obj->unk28 = speed;
    obj->unk2C = speed;
    obj->unk30 = 0x50;
}

// sub_080D8CC8 @ 0x080D8CC8
void sub_080D8CC8(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    u16 frame = sub_080C4388(obj);

    sub_080C44CC(obj, (const void *)obj->unk24, frame, 0xE, 3, 0x300, obj->unk08, obj->unk0A - 0x20);
}

// sub_080D8D08 @ 0x080D8D08
void sub_080D8D08(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;

    task->result = 0;
    obj->unk2C = obj->unk28;
    obj->unk0A += 2;
    if (--obj->unk30 == 0)
        task->result = 1;
}

// sub_080D8D30 @ 0x080D8D30
void sub_080D8D30(struct Task *task)
{
    sub_080D89AC(task, gUnknown_08005B40);
}

// sub_080D8D40 @ 0x080D8D40
void sub_080D8D40(struct Task *task)
{
    struct CharAffine *p = (struct CharAffine *)&task->data.h[0x12];

    p->enabled = 1;
    p->scaleX = 0x100;
    p->scaleY = 0x100;
    p->angle = 0;
}

// sub_080D8D54 @ 0x080D8D54
void sub_080D8D54(struct Task *task, const void *src, u32 slot)
{
    HuffUnComp(src, gBgPictureBuffer);
    LZ77UnCompWram(gBgPictureBuffer, gUnk_02001000 + (slot << 11));
}

// sub_080D8D80 @ 0x080D8D80
void sub_080D8D80(void)
{
    DmaSet3(0x02001000, 0x06013000, 0x84000C00);
}

// sub_080D8DA4 @ 0x080D8DA4
void sub_080D8DA4(struct Task *task, const void *palette)
{
    Palette_CopyWithEffect(3, palette, gUnk_03003150, 0x40, 0x20);
    Palette_MarkDirty();
    VBlankTask_AddCounted(sub_080D8D80, 1);
}

// sub_080D8DD0 @ 0x080D8DD0
void sub_080D8DD0(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;

    sub_080C4388(obj);
    Sprite_Draw(gUnknown_08565CD8[obj->frame], 7, 0xD, 3, 0x180, obj->unk08 + 0x28, obj->unk0A + 0x58);
}

// sub_080D8E18 @ 0x080D8E18
void sub_080D8E18(struct Task *task, u16 frame)
{
    task->data.h[0xC] = frame;
}

// sub_080D8E1C @ 0x080D8E1C
void sub_080D8E1C(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;

    sub_080C4388(obj);
    if (obj->unk0C == 0)
        Sprite_Draw(gUnknown_08565DC4[obj->frame], 7, 0xD, 3, 0x180, obj->unk08 + 0x28, obj->unk0A + 0x58);
    else
        Sprite_Draw(gUnknown_08565DE8[obj->frame], 7, 0xD, 3, 0x180, obj->unk08 + 0x28, obj->unk0A + 0x58);
}
