#include "global.h"
#include "title.h"

/* Scaled character sprite (affine block at +0x48) while unk0C == 0, else frame + 2 unscaled. */
// sub_080D8EA0 @ 0x080D8EA0
void sub_080D8EA0(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    const void *def[2];
    struct CharAffine *aff;
    u16 frame;
    u16 big;
    const void *const *entry;

    sub_080C4388(obj);
    frame = obj->frame;
    aff = (struct CharAffine *)&obj->unk24;
    big = obj->unk0C;
    if (big == 0)
    {
        entry = gUnknown_08565F20[frame];
        def[0] = *entry;
        def[1] = aff;
        sub_0815862C(def, aff->scaleX, aff->scaleY, 0x10);
        def[0] = gUnk_03003800;
        def[1] = aff;
        Sprite_DrawSharedAffine(def, 0, 0xD, 3, 0x180, obj->unk08 + 0x28, obj->unk0A + 0x58, big);
    }
    else
    {
        entry = gUnknown_08565F20[frame + 2];
        Sprite_Draw(entry, 0, 0xD, 3, 0x180, obj->unk08 + 0x28, obj->unk0A + 0x58);
    }
}

// sub_080D8F48 @ 0x080D8F48
void sub_080D8F48(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    const void *def[2];
    struct CharAffine *aff;
    u16 frame;
    u16 big;
    const void *const *entry;

    sub_080C4388(obj);
    frame = obj->frame;
    aff = (struct CharAffine *)&obj->unk24;
    big = obj->unk0C;
    if (big == 0)
    {
        entry = gUnknown_08565FE4[frame];
        def[0] = *entry;
        def[1] = aff;
        sub_0815862C(def, aff->scaleX, aff->scaleY, 0x10);
        def[0] = gUnk_03003800;
        def[1] = aff;
        Sprite_DrawSharedAffine(def, 0, 0xD, 3, 0x180, obj->unk08 + 0x28, obj->unk0A + 0x58, big);
    }
    else
    {
        entry = gUnknown_08565FE4[frame + 4];
        Sprite_Draw(entry, 0, 0xD, 3, 0x180, obj->unk08 + 0x28, obj->unk0A + 0x58);
    }
}

/* Two halves drawn mirrored around x = 0x50 at a distance of unk24 (a door opening?). */
// sub_080D8FF0 @ 0x080D8FF0
void sub_080D8FF0(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;

    obj->unk08 = 0x3D - obj->unk24;
    obj->unk0A = 0;
    sub_080C43F8(task, gUnknown_08004FF8, 0, 0);
    obj->unk08 = obj->unk24 + 0x63;
    obj->unk0A = 0;
    sub_080C43F8(task, gUnknown_08005028, 0, 0);
}

// sub_080D9034 @ 0x080D9034
void sub_080D9034(struct Task *task)
{
    task->data.w[9] = 0;
}

// sub_080D903C @ 0x080D903C
void sub_080D903C(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    u8 all;

    obj->unk24++;
    gUnk_03000030 = 0x3D;
    gUnk_03000031 = 0;
    gUnk_03000034 = 0x47;
    gUnk_03000035 = 0;
    gUnk_03000038 = (all = 0x3F) & ~0x10;   /* window 0: everything but OBJ */
    gUnk_03000032 = 0xF0;
    gUnk_03000033 = 0xB3;
    gUnk_03000036 = 0x47;
    gUnk_03000037 = 0;
    gUnk_03000039 = 0x2F;
    gUnk_0300003A = all;
}

// sub_080D90B4 @ 0x080D90B4
void sub_080D90B4(void)
{
    gUnk_03000038 = 0x3F;
    gUnk_03000039 = 0x3F;
    gUnk_0300003A = 0x3F;
}

// sub_080D90D0 @ 0x080D90D0
void sub_080D90D0(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;

    obj->unk08 = 0x4D - obj->unk24;
    obj->unk0A = 0x20;
    sub_080C43F8(task, gUnknown_08004FF8, 0, 0);
    obj->unk08 = obj->unk24 + 0x53;
    obj->unk0A = 0x20;
    sub_080C43F8(task, gUnknown_08005028, 0, 0);
}

// sub_080D9114 @ 0x080D9114
void sub_080D9114(struct Task *task)
{
    task->data.w[9] = 0;
}

// sub_080D911C @ 0x080D911C
void sub_080D911C(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    u8 all;

    obj->unk24++;
    gUnk_03000030 = 0x4D;
    gUnk_03000031 = 0;
    gUnk_03000034 = 0x57;
    gUnk_03000035 = 0;
    gUnk_03000038 = (all = 0x3F) & ~0x10;   /* window 0: everything but OBJ */
    gUnk_03000032 = 0xF0;
    gUnk_03000033 = 0xA3;
    gUnk_03000036 = 0x57;
    gUnk_03000037 = 0;
    gUnk_03000039 = 0x2F;
    gUnk_0300003A = all;
}

// sub_080D9194 @ 0x080D9194
void sub_080D9194(void)
{
    gUnk_03000038 = 0x3F;
    gUnk_03000039 = 0x3F;
    gUnk_0300003A = 0x3F;
}

// sub_080D91B0 @ 0x080D91B0
void sub_080D91B0(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    u16 x = obj->unk08;

    sub_080C43F8(task, gUnknown_08004FF8, 0, 0);
    obj->unk08 += 0x50;
    sub_080C43F8(task, gUnknown_08005028, 0, 0);
    obj->unk08 = x;
}

// sub_080D91E8 @ 0x080D91E8
void sub_080D91E8(void)
{
    DmaSet3(0x02001000, 0x06014C00, 0x84000D00);
}

// sub_080D920C @ 0x080D920C
void sub_080D920C(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;

    LZ77UnCompWram(gUnknown_08566C34, gUnk_02001000);
    LZ77UnCompWram(gUnknown_08567060, gUnk_02001000 + 0x1000);
    LZ77UnCompWram(gUnknown_085673D0, gUnk_02001000 + 0x2000);
    LZ77UnCompWram(gUnknown_085677A4, gUnk_02001000 + 0x3000);
    sub_080C3F4C(obj, gUnknown_08567894, 0x1E0, 0x20, 1);
    VBlankTask_AddCounted(sub_080D91E8, 1);
    obj->unk24 = 0;
    obj->shown = 1;
}

// sub_080D9288 @ 0x080D9288
void sub_080D9288(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;

    sub_080C4388(obj);
    Sprite_Draw(gUnknown_085678B4[obj->unk24], 9, 0xE, 3, 0x260, obj->unk08 + 0x28, obj->unk0A + 0x58);
}

// sub_080D92D0 @ 0x080D92D0
void sub_080D92D0(struct Task *task, u32 frame)
{
    task->data.w[9] = frame;
}

// sub_080D92D4 @ 0x080D92D4
void sub_080D92D4(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;

    sub_080C4388(obj);
    Sprite_DrawBlended(gUnknown_0856793C[obj->unk24], 8, 0xF, 3, 0x180, obj->unk08 + 0x28, obj->unk0A + 0x58);
}

// sub_080D931C @ 0x080D931C
void sub_080D931C(struct Task *task, u32 frame)
{
    task->data.w[9] = frame;
}

// sub_080D9320 @ 0x080D9320
void sub_080D9320(void)
{
    DmaSet3(0x02001000, 0x06015000, 0x84000B00);
}

// sub_080D9344 @ 0x080D9344
void sub_080D9344(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;

    LZ77UnCompWram(gUnknown_08567A04, gUnk_02001000);
    LZ77UnCompWram(gUnknown_08567F4C, gUnk_02001000 + 0x1000);
    LZ77UnCompWram(gUnknown_08568218, gUnk_02001000 + 0x2000);
    Palette_CopyWithEffect(3, gUnknown_085683D0, gUnk_03003170, 0x20, 0x20);
    Palette_MarkDirty();
    VBlankTask_AddCounted(sub_080D9320, 1);
    obj->unk24 = 0;
    obj->shown = 1;
}

/* Frames 0..9 blended, later frames opaque. */
// sub_080D93B8 @ 0x080D93B8
void sub_080D93B8(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    u16 layer = sub_080C4388(obj);

    if (obj->unk24 <= 9)
        Sprite_DrawBlended(gUnknown_085683F0[obj->unk24], layer, 0xE, 3, 0x280, obj->unk08 + 0x28, obj->unk0A + 0x30);
    else
        Sprite_Draw(gUnknown_085683F0[obj->unk24], layer, 0xE, 3, 0x280, obj->unk08 + 0x28, obj->unk0A + 0x30);
}

// sub_080D943C @ 0x080D943C
void sub_080D943C(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;

    obj->unk24++;
}

// sub_080D9448 @ 0x080D9448
void sub_080D9448(void)
{
    DmaSet3(0x02001000, 0x06013000, 0x84000E00);
}
