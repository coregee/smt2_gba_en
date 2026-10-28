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
            sub_080C51D4(frame->se);
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
            sub_080C48F0(task, 0);
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
                sub_080C51D4(frame->se);
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
/* NONMATCHING: same instructions and size; the loop constants 0xF / 0x202 and the counters land in different registers */
// sub_080D7D98 @ 0x080D7D98
#ifdef NONMATCHING
void sub_080D7D98(const u8 *src)
{
    u16 *buf = gUnk_02000000;
    u16 *patch;
    u32 row, col;

    DmaSet3(gUnknown_081C25F4, buf, 0x84000400);
    patch = buf + 0x100;
    for (row = 0; row < 5; row++)
    {
        u16 *p = buf + row * 32;

        for (col = 0; col < 0x1C; col++)
        {
            u32 v = *src++;
            p[0x101] += ((v & 0xF) + 8) << 12;
            p++;
        }
    }
    DmaSet3(patch, 0x06003200, 0x84000050);
}
#else
NAKED
void sub_080D7D98(const u8 *src)
{
    asm_unified(
        ".L080D7D98:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sb\n"
        "    mov r6, r8\n"
        "    push {r6, r7}\n"
        "    adds r3, r0, #0\n"
        "    ldr r0, .L080D7E10\n"
        "    mov ip, r0\n"
        "    ldr r1, .L080D7E14\n"
        "    ldr r0, .L080D7E18\n"
        "    str r0, [r1]\n"
        "    mov r7, ip\n"
        "    str r7, [r1, #4]\n"
        "    ldr r0, .L080D7E1C\n"
        "    str r0, [r1, #8]\n"
        "    ldr r0, [r1, #8]\n"
        "    movs r0, #0\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #2\n"
        "    add r1, ip\n"
        "    mov r8, r1\n"
        "    movs r7, #0xf\n"
        "    mov sb, r7\n"
        "    ldr r6, .L080D7E20\n"
        ".L080D7DC6:\n"
        "    movs r4, #0\n"
        "    adds r5, r0, #1\n"
        "    lsls r0, r0, #6\n"
        "    mov r1, ip\n"
        "    adds r2, r0, r1\n"
        ".L080D7DD0:\n"
        "    ldrb r0, [r3]\n"
        "    adds r3, #1\n"
        "    mov r7, sb\n"
        "    ands r0, r7\n"
        "    adds r0, #8\n"
        "    adds r1, r2, r6\n"
        "    lsls r0, r0, #0xc\n"
        "    ldrh r7, [r1]\n"
        "    adds r0, r0, r7\n"
        "    strh r0, [r1]\n"
        "    adds r2, #2\n"
        "    adds r4, #1\n"
        "    cmp r4, #0x1b\n"
        "    bls .L080D7DD0\n"
        "    adds r0, r5, #0\n"
        "    cmp r0, #4\n"
        "    bls .L080D7DC6\n"
        "    ldr r1, .L080D7E14\n"
        "    mov r0, r8\n"
        "    str r0, [r1]\n"
        "    ldr r0, .L080D7E24\n"
        "    str r0, [r1, #4]\n"
        "    ldr r0, .L080D7E28\n"
        "    str r0, [r1, #8]\n"
        "    ldr r0, [r1, #8]\n"
        "    pop {r3, r4}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080D7E10: .4byte 0x02000000 @ EWRAM\n"
        ".L080D7E14: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080D7E18: .4byte gUnknown_081C25F4\n"
        ".L080D7E1C: .4byte 0x84000400\n"
        ".L080D7E20: .4byte 0x00000202\n"
        ".L080D7E24: .4byte 0x06003200 @ VRAM+0x3200\n"
        ".L080D7E28: .4byte 0x84000050\n"
    );
}
#endif

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
