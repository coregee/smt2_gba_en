#include "global.h"
#include "extras.h"

/* Number of entries in the compendium list (0xFFFF = none). */
// Dict_CountListed @ 0x080DB8A4
u32 Dict_CountListed(void)
{
    u32 n = 0;
    u32 i;
    u16 *list = gStatusList;

    for (i = 0; i <= 0x17B; i++)
    {
        if (list[i] != 0xFFFF)
            n++;
    }
    return n;
}

// sub_080DB8D4 @ 0x080DB8D4
u32 sub_080DB8D4(void)
{
    u32 n = 0;
    u32 i;

    for (i = 0; i <= 0x17B; i++)
    {
        if (gStatusList[i] != 0xFFFF && sub_080C2644(gStatusList[i] & 0x7FFF))
            n++;
    }
    return n;
}

// sub_080DB920 @ 0x080DB920
void sub_080DB920(struct Task *task)
{
    u32 n = Dict_CountListed();

    if (n != 0)
        n = 1;
    task->result = n;
}

/* Draws the selected demon's name (up to 8 glyphs) at (0x7E, 7). */
// sub_080DB938 @ 0x080DB938
void sub_080DB938(void)
{
    struct C0d9Dict *dict = &gDict;
    u8 *rec = Demon_GetRecord(dict->selected);
    u16 x = 0x7E;
    u16 y = 7;
    const u16 *name;
    u16 i;

    if (sub_080C2644(dict->selected))
        name = (const u16 *)(rec + 0x22);
    else
        name = gUnknown_0858325A;
    for (i = 0; name[i] != 0; )
    {
        FontSprite_DrawGlyph(name[i], 0, 0, x, y);
        x += 12;
        i++;
        if (i > 7)
            break;
    }
}

// sub_080DB9AC @ 0x080DB9AC
void sub_080DB9AC(void)
{
    Task_Create(gUnknown_0858326C, 0xFFFF);
}

// sub_080DB9C4 @ 0x080DB9C4
void sub_080DB9C4(struct Task *task)
{
    u32 i;

    for (i = 0; i < 64; i++)
    {
        struct Task *t = &gTasks[i];

        if (t->state != 0 && t->onFrame == (void *)sub_080DB938)
            Task_End(t);
    }
    sub_080D9D8C(task);
}

// sub_080DBA04 @ 0x080DBA04
void sub_080DBA04(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;

    d->unk0C = gDict.unk44;
    d->unk0E = gDict.unk46;
}
