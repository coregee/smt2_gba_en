#include "global.h"
#include "title.h"

/* Draws a character sprite with the OBJ tile base / palette of its slot (0..5), or of the
   first three slots only while sub_080D7A04 reports 0. */
// Char_DrawBySlot @ 0x080D7A84
void Char_DrawBySlot(struct Task *task, const void *sprite)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    u16 slot = obj->slot;
    u16 frame = sub_080C4388(obj);
    u16 x;

    x = obj->unk0A;
    x -= gUnk_0300000E;

    sub_080D7A04(task);
    if (task->result == 0)
    {
        if (slot == 0)
            sub_080C44CC(obj, sprite, frame, 0xE, obj->unk10, 0x300, obj->unk08, x);
        else if (slot == 1)
            sub_080C44CC(obj, sprite, frame, 0xF, obj->unk10, 0x380, obj->unk08, x);
        else
            sub_080C44CC(obj, sprite, frame, 0xD, obj->unk10, 0x280, obj->unk08, x);
    }
    else
    {
        if (slot == 0)
            sub_080C44CC(obj, sprite, frame, 0xE, obj->unk10, 0x300, obj->unk08, x);
        else if (slot == 1)
            sub_080C44CC(obj, sprite, frame, 0xF, obj->unk10, 0x340, obj->unk08, x);
        else if (slot == 2)
            sub_080C44CC(obj, sprite, frame, 0xD, obj->unk10, 0x380, obj->unk08, x);
        else if (slot == 3)
            sub_080C44CC(obj, sprite, frame, 0xC, obj->unk10, 0x3C0, obj->unk08, x);
        else if (slot == 4)
            sub_080C44CC(obj, sprite, frame, 0xB, obj->unk10, 0x280, obj->unk08, x);
        else
            sub_080C44CC(obj, sprite, frame, 0xA, obj->unk10, 0x2C0, obj->unk08, x);
    }
}

// sub_080D7BB4 @ 0x080D7BB4
void sub_080D7BB4(struct Task *task)
{
    Char_DrawBySlot(task, gUnknown_080050C4);
}

// sub_080D7BC4 @ 0x080D7BC4
void sub_080D7BC4(struct Task *task, u16 value)
{
    task->data.h[5] = value;
}

// sub_080D7BC8 @ 0x080D7BC8
void sub_080D7BC8(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;

    obj->anim = Task_Create(gUnknown_0855FAB4, task->id);
}

/* Starts the character's animation script (record +0x28): first frame's duration, and its
   graphics if the frame asks for a load. */
// Char_StartAnim @ 0x080D7BE4
void Char_StartAnim(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    struct CharAnimFrame *frame = Char_GetRecord(obj->id)->anim;
    u16 load;

    obj->frameTimer = frame->duration;
    load = frame->loadGfx;
    if (load == 1)
    {
        sub_080D77FC(task, frame->gfx, 0, 0, 0);
        sub_080D77FC(task, frame->gfx, 0, 0, load);
        if (frame->se != 0)
            Sound_Play(frame->se);
    }
}

// Char_DrawAnimFrame @ 0x080D7C30
void Char_DrawAnimFrame(struct Task *task, struct CharAnimFrame *frame)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    u16 slot = obj->slot;
    u16 tile = frame->tile;
    u16 pal = frame->palette;
    const void *sprite;
    u16 id;

    if (tile == 0xFFFF)
    {
        tile = 0x300;
        if (slot != 0)
        {
            tile = 0x280;
            if (slot == 1)
                tile = 0x380;
        }
    }
    if (pal == 0xFFFF)
    {
        pal = 0xE;
        if (slot != 0)
        {
            pal = 0xD;
            if (slot == 1)
                pal = 0xF;
        }
    }
    sprite = frame->sprite;
    if (sprite == gUnknown_08004FF8)
        sprite = sub_080C43B4(obj);
    id = obj->id;
    if ((u16)(id - 0xAA) <= 1 || id == 0xF5)
        obj->unk10 = 1;
    sub_080C43F8(task, sprite, tile, pal);
}

/* Steps the character animation: 0xFFFF ends it, 0xFFFE loops to the first frame. */
// Char_StepAnim @ 0x080D7CA8
void Char_StepAnim(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    struct CharAnimFrame *frame;
    struct CharGfxRecord *rec = Char_GetRecord(obj->id);
    u16 load;

    frame = rec->anim;

    if (--obj->frameTimer == 0)
    {
        obj->frame++;
        frame += obj->frame;
        if (frame->duration == 0xFFFF)
        {
            CharObj_End(task, 0);
            return;
        }
        if (frame->duration == 0xFFFE)
        {
            obj->frame = 0;
            frame = rec->anim;
        }
        obj->frameTimer = frame->duration;
        if (frame->gfx[0] != NULL && (load = frame->loadGfx) == 1)
        {
            sub_080D77FC(task, frame->gfx, 1, 0, 0);
            sub_080D77FC(task, frame->gfx, 1, 0, load);
            if (frame->se != 0)
                Sound_Play(frame->se);
        }
        Char_DrawAnimFrame(task, frame);
    }
    else
    {
        frame += obj->frame;
        Char_DrawAnimFrame(task, frame);
    }
}

// sub_080D7D60 @ 0x080D7D60
void sub_080D7D60(const u8 *src)
{
    vu32 *dma = (vu32 *)(REG_BASE + 0xD4);

    dma[0] = (vu32)src;
    dma[1] = 0x06005C40;
    dma[2] = 0x840000F0;
    dma[2];
    dma[0] = (vu32)(src + 0x3C0);
    dma[1] = 0x06008040;
    dma[2] = 0x84000370;
    dma[2];
}

/* Builds a 28x5 tilemap patch: base map 0x081C25F4 plus palette (nibble + 8) per cell from
   src, then uploads it to BG map 0x06003200. */
// sub_080D7D98 @ 0x080D7D98
void sub_080D7D98(const u8 *src_)
{
    /* pin: col (11 loop-weighted refs) otherwise outranks src for r3 */
    register const u8 *src asm("r3") = src_;
    u16 *buf = gUnk_02000000;
    u16 *patch;
    u32 row, col;

    DmaSet3(gUnknown_081C25F4, buf, 0x84000400);
    row = 0;
    patch = buf + 0x100;
    do
    {
        u16 *p;
        u32 next;

        col = 0;
        next = row + 1;
        p = (u16 *)((row << 6) + (u32)buf);
        for (; col < 0x1C; col++)
        {
            u32 v = *src++;

            v &= 0xF;
            v += 8;
            p[0x101] += v << 12;
            p++;
        }
        row = next;
    } while (row < 5);
    DmaSet3(patch, 0x06003200, 0x84000050);
}

// sub_080D7E2C @ 0x080D7E2C
void sub_080D7E2C(void)
{
    sub_080D7D60(gUnknown_0855FBA4);
    sub_080D7D98(gUnknown_08563024);
}

// sub_080D7E48 @ 0x080D7E48
void sub_080D7E48(void)
{
    sub_080D7D60(gUnknown_08560D24);
    sub_080D7D98(gUnknown_085630B0);
}

// sub_080D7E64 @ 0x080D7E64
void sub_080D7E64(void)
{
    sub_080D7D60(gUnknown_08561EA4);
    sub_080D7D98(gUnknown_0856313C);
}

// sub_080D7E80 @ 0x080D7E80
void sub_080D7E80(struct Task *task)
{
    u32 *data = task->data.w;

    data[9] = 0;
    data[10] = 8;
}

/* Cycles the three frames above every 8 frames once palette fades are idle. */
// sub_080D7E8C @ 0x080D7E8C
void sub_080D7E8C(struct Task *task)
{
    u32 *data = task->data.w;

    if (PalFade_AllDone() == 0)
        return;
    if (Palette_IsBg13Black() == 1)
        return;
    if (--data[10] != 0)
        return;
    data[10] = 8;
    switch (data[9])
    {
    case 0:
        VBlankTask_AddCounted(sub_080D7E2C, 1);
        break;
    case 1:
        VBlankTask_AddCounted(sub_080D7E48, 1);
        break;
    case 2:
        VBlankTask_AddCounted(sub_080D7E64, 1);
        break;
    }
    if (++data[9] > 2)
        data[9] = 0;
}

// sub_080D7EFC @ 0x080D7EFC
void sub_080D7EFC(void)
{
    DmaSet3(0x02001000, 0x06015000, 0x84000400);
}

// sub_080D7F20 @ 0x080D7F20
void sub_080D7F20(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    LZ77UnCompWram(gUnknown_085632F4, gUnk_02001000);
    DmaSet3(gUnknown_08563A5C, gUnk_02001000 + 0xFC0, 0x84000010);
    Palette_CopyWithEffect(3, gUnknown_08563AC0, gUnk_03002D50, 0x20, 0x20);
    PalFade_FadeRangeInFromBlackTagged(0x1D0, 0x10, 1, 1);
    VBlankTask_AddCounted(sub_080D7EFC, 1);
    obj->unk08 = 0;
    obj->unk0A = 0x18;
    task->unk1E = 0;
}

// sub_080D7FA0 @ 0x080D7FA0
void sub_080D7FA0(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;

    Sprite_Draw(gUnknown_08002C88, 1, 0xD, 0, 0x280, 0x58 - obj->unk08, obj->unk0A);
    Sprite_Draw(gUnknown_08002C70, 1, 0xD, 0, 0x280, obj->unk08 + 0x78, obj->unk0A);
    if (task->unk1E != 0 && !((gFrameCounter >> 4) & 1))
    {
        if (task->unk1E == 1)
            Sprite_Draw(gUnknown_08002CBC, 1, 0xD, 0, 0x2FE, 0x64, obj->unk0A - 0x10);
        else
            Sprite_Draw(gUnknown_08002CCC, 1, 0xD, 0, 0x2FE, 0x64, obj->unk0A - 0x10);
    }
}

// sub_080D8064 @ 0x080D8064
void sub_080D8064(struct Task *task, u32 n)
{
    struct CharObj *obj = (struct CharObj *)&task->data;

    obj->unk0A += n;
    gUnk_0300000E -= n;
}

// sub_080D807C @ 0x080D807C
void sub_080D807C(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;

    sub_080B29A8(0);
    obj->unk08 = 0;
    task->unk1E = 0;
}

// sub_080D8098 @ 0x080D8098
void sub_080D8098(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;

    obj->unk08++;
}

// sub_080D80A4 @ 0x080D80A4
void sub_080D80A4(struct Task *task)
{
    task->unk1E = 0;
}

// sub_080D80AC @ 0x080D80AC
void sub_080D80AC(void)
{
    gUnk_03000038 = 0x3F;
    gUnk_03000039 = 0x3F;
    gUnk_0300003A = 0x3F;
}

// sub_080D80C8 @ 0x080D80C8
void sub_080D80C8(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    LZ77UnCompWram(gUnknown_08563BD8, gUnk_02001000);
    DmaSet3(gUnknown_08564358, gUnk_02001000 + 0xFC0, 0x84000010);
    Palette_CopyWithEffect(3, gUnknown_085643BC, gUnk_03002D50, 0x20, 0x20);
    PalFade_FadeRangeInFromBlackTagged(0x1D0, 0x10, 1, 1);
    VBlankTask_AddCounted(sub_080D7EFC, 1);
    obj->unk08 = 0;
    obj->unk0A = 0x18;
    task->unk1E = 0;
}

// sub_080D8148 @ 0x080D8148
void sub_080D8148(void)
{
    DmaSet3(0x02001000, 0x06016000, 0x84000400);
}

// sub_080D816C @ 0x080D816C
void sub_080D816C(void)
{
    HuffUnComp(gUnknown_086BF890, (void *)0x0200AFC8);
    LZ77UnCompWram((void *)0x0200AFC8, (void *)0x02001000);
    Palette_FillWithEffect(3, 0x7FFF, gUnk_03003170, 0x20, 0x10);
    Palette_MarkDirty();
    VBlankTask_AddCounted(sub_080D8148, 1);
}

// sub_080D81C0 @ 0x080D81C0
void sub_080D81C0(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    u16 frame = sub_080C4388(obj);

    if (!((gFrameCounter >> 4) & 1))
        sub_080C44CC(obj, gUnknown_08118CC4, frame, 0xE, obj->unk10, 0x300, obj->unk08 + 0x28, obj->unk0A - 0x13);
    else
        sub_080C44CC(obj, gUnknown_08118CE0, frame, 0xE, obj->unk10, 0x300, obj->unk08 + 0x28, obj->unk0A - 0x13);
}
