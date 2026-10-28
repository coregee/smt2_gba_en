#include "global.h"
#include "sceneeffect.h"

// sub_080BC0A4 @ 0x080BC0A4
void sub_080BC0A4(struct Task *task)
{
    u16 *d = task->data.h;
    const void *const *tbl = gUnknown_0800786C;
    u16 dx = d[1] * 40 / 255;
    u16 dy = d[1] * 36 / 255;
    const void *def[2];

    def[0] = tbl[0];
    def[1] = d;
    sub_0815851C(def);
    def[0] = gUnk_03003800;
    def[1] = d;
    Sprite_DrawSharedAffine(def, 0, 0xD, 0, 0x280, 0x2C - dx, 0x26 - dy, 0);
    Sprite_DrawSharedAffine(def, 0, 0xD, 0, 0x280, 0xC4 - dx, 0x26 - dy, 0);
}

// sub_080BC154 @ 0x080BC154
void sub_080BC154(struct Task *task)
{
    u16 *d = task->data.h;

    d[1] += 4;
    d[2] += 4;
}

// sub_080BC164 @ 0x080BC164
void sub_080BC164(struct Task *task)
{
    Char_EndById(task, 0xBE);
}

// sub_080BC170 @ 0x080BC170
void sub_080BC170(void)
{
    sub_080BA7A0(1);
    sub_080BA7CC(gUnknown_0818F010, gUnknown_0818EEA0, 0xE, 0x1A, 1);
}

// sub_080BC198 @ 0x080BC198
void sub_080BC198(void)
{
    u32 odd = gFrameCounter & 1;

    if (!odd)
    {
        CharObj_Create(3, 0xC8, (Random_Byte() & 0x7F) + 0x30, 0, odd, odd);
        CharObj_Create(4, 0xC9, (Random_Byte() & 0x7F) + 0x30, 0, odd, odd);
        CharObj_Create(5, 0xCA, (Random_Byte() & 0x7F) + 0x30, 0, odd, odd);
    }
}

// sub_080BC200 @ 0x080BC200
void sub_080BC200(void)
{
    gUnk_0300000E--;
    sub_080BA7CC(gUnknown_0818F010, gUnknown_0818EEA0, 0xE, 0x1A, 1);
}

// Char_FindById @ 0x080BC230
/* The object task (one of the 6 in gCharTasks) whose id (data.h[3]) is id, or NULL. */
struct Task *Char_FindById(u16 id)
{
    u32 i;

    for (i = 0; i < 6; i++)
    {
        struct Task *t = gCharTasks[i];

        if (t != NULL && t->data.h[3] == id)
            return t;
    }
    return NULL;
}

// Char_EndById @ 0x080BC260
void Char_EndById(struct Task *task, u16 id)
{
    struct Task *t = Char_FindById(id);

    if (t != NULL)
        CharObj_End(t, 0);
}

// sub_080BC278 @ 0x080BC278
void sub_080BC278(struct Task *task, u32 step)
{
    task->result = 0;
    switch (step)
    {
    case 0:
        Char_EndById(task, 0xB0);
        Char_EndById(task, 0xB1);
        CharObj_Create(2, 0xC5, 0x51, 0x40, 0, 0);
        break;
    case 1:
        CharObj_Create(2, 0xC6, 0x51, 0x40, 0, 0);
        break;
    case 2:
        sub_080BAD88(task, 0xC6, 0, -1);
        break;
    case 3:
    case 4:
        CharObj_Create(2, 0xC7, 0x50, -0x90, 0, 0);
        break;
    case 5:
        break;
    case 7:
        sub_080B0820();
        break;
    case 8:
        gUnk_0300000E = 0;
        break;
    case 9:
        BgPicture_LoadPalette();
        sub_080B0778();
        break;
    case 100:
        if (Char_FindById(0xC5)->wait == -1)
            task->result = 1;
        break;
    case 101:
        if (Char_FindById(0xC7)->wait == -1)
            task->result = 1;
        break;
    }
}

// sub_080BC4C8 @ 0x080BC4C8
void sub_080BC4C8(struct Task *task, u32 step)
{
    struct Task *t;

    if (step == 0)
    {
        t = Char_FindById(0xD8);
        if (t != NULL)
            CharObj_End(t, 0);
    }
    else if (step == 1)
    {
    }
    else if (step == 2)
    {
        t = Char_FindById(0xD9);
        if (t != NULL)
            CharObj_End(t, 0);
    }
}

// sub_080BC4FC @ 0x080BC4FC
void sub_080BC4FC(void)
{
    struct Task *t;

    t = Char_FindById(0xD9);
    if (t != NULL)
        t->data.h[8] = 1;
    t = Char_FindById(0x1BE);
    if (t != NULL)
        t->data.h[8] = 1;
    t = Char_FindById(0x1BF);
    if (t != NULL)
        t->data.h[8] = 1;
    t = Char_FindById(0x16B);
    if (t != NULL)
        t->data.h[8] = 1;
    t = Char_FindById(0x16C);
    if (t != NULL)
        t->data.h[8] = 1;
}

// sub_080BC560 @ 0x080BC560
void sub_080BC560(void)
{
    DmaSet(3, 0x02001000, 0x06016800, 0x84000300);
}

// sub_080BC584 @ 0x080BC584
void sub_080BC584(void)
{
    DmaSet(3, 0x02001000, 0x06013000, 0x84000E00);
}
