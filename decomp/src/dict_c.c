#include "global.h"
#include "extras.h"

// sub_080DBCAC @ 0x080DBCAC
void sub_080DBCAC(struct Task *task)
{
    struct Task *parent = Task_GetParent(task);

    Text_DrawSpriteString(gUnknown_0858329C[parent->data.h[0]], 0, 0, 0x14, 0x64, 0xC);
}

/* Compendium list: six names (8 glyphs each, "?" entries for demons not met), the
   met/registered counts and the scroll arrows. */
// sub_080DBCDC @ 0x080DBCDC
void sub_080DBCDC(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    u16 y = 0x10;
    u16 count = Dict_CountListed();
    u16 x = 0x5C;
    u32 row, i;

    if (d->unk10 != 0)
        Sprite_Draw(gUnknown_0800853C, 0, 7, 0, 0x100, 0x5A, d->unk0C * 12 + 17);
    if (gDict.unk3E == 1)
    {
        for (row = 0; row < 6; row++)
        {
            u16 v = ((u16 *)0x0203B554)[d->unk0E + row];

            if (v != 0xFFFF)
            {
                u16 id = v & 0x7FFF;
                const u16 *name;

                if (sub_080C2644(id))
                    name = (const u16 *)(Demon_GetRecord(id) + 0x22);
                else
                    name = gUnknown_0858325A;
                for (i = 0; i < 8; i++)
                    FontSprite_DrawGlyph(name[i], 0, 0, x + i * 12, y + row * 12);
            }
        }
        if (d->unk0E != 0)
            sub_080C4A4C(0, 0, x + 0x60, y - 4);
        if (d->unk0E + 6 <= count - 1)
            sub_080C4AB0(0, 0, x + 0x60, y + 0x4C);
    }
    else
    {
        Text_DrawSpriteString(gUnknown_0800974E, 0, 0, x, y, 12);
    }
    Sprite_DrawFraction(sub_080DB8D4(), Dict_CountListed(), x + 0x25, y + 0x5A);
    if (d->unk10 == 0)
        Sprite_Draw(d->spr18, 0, 7, 0, 0x100, 0x10, d->cursor * 11 + 14);
    Sprite_Draw(d->spr14, 0, 7, 0, 0, 0x10, 0x10);
}

// sub_080DBE84 @ 0x080DBE84
void sub_080DBE84(struct Task *task)
{
    struct Task *parent = Task_GetParent(task);

    sub_080C3818(1);
    parent->wait = 1;
}

// sub_080DBE9C @ 0x080DBE9C
void sub_080DBE9C(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    u16 x = 0x54;
    u16 y = 0x10;
    u16 count = 43;
    u32 row, i;

    Sprite_Draw(gUnknown_0800853C, 0, 7, 0, 0x100, 0x52, task->data.h[0] * 12 + 17);
    for (row = 0; row < 6; row++)
    {
        u16 race = d->unk02 + row;
        const u16 *name;

        if (race > 0x28)
            race++;
        name = Race_GetName(race);
        for (i = 0; i < 8; i++)
            FontSprite_DrawGlyph(name[i], 0, 0, x + i * 12, y + row * 12);
    }
    if (d->unk02 != 0)
        sub_080C4A4C(0, 0, x + 0x60, y - 4);
    if (d->unk02 + 6 <= count - 1)
        sub_080C4AB0(0, 0, x + 0x60, y + 0x4C);
}

/* Generic scrolling list input: 6 visible rows, d->unk02 is the first row shown. */
// sub_080DBF7C @ 0x080DBF7C
void sub_080DBF7C(struct Task *task, u32 n)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    u16 count = n;
    u16 rows = count;

    if (count > 5)
        rows = 6;
    task->result = 0;
    task->unk1E = 0;
    if (gKeysNew & 1)
    {
        task->unk1E = task->data.h[0] + 1;
        Sound_Play(0x65);
        task->result = 1;
    }
    else if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        task->result = 1;
    }
    else if (gRepeatedKeys & 0x40)
    {
        if (task->data.h[0] != 0)
        {
            task->data.h[0]--;
            Sound_Play(0x64);
        }
        else if (d->unk02 != 0)
        {
            d->unk02--;
            Sound_Play(0x64);
        }
    }
    else
    {
        u16 down = gRepeatedKeys & 0x80;

        if (down)
        {
            if (task->data.h[0] != rows - 1)
            {
                task->data.h[0]++;
                Sound_Play(0x64);
            }
            else if (task->data.h[0] == 5 && task->data.h[0] + d->unk02 + 1 <= count - 1)
            {
                d->unk02++;
                Sound_Play(0x64);
            }
        }
        else if ((gRepeatedKeys & 0x200) && count > 6)
        {
            u32 cursor = task->data.h[0];
            u16 top = d->unk02;
            u16 t = cursor;

            if (t != 0)
            {
                task->data.h[0] = down;
            }
            else
            {
                if (top > 4)
                    d->unk02 = top - 5;
                else
                    d->unk02 = t;
            }
            if (cursor != d->cursor || top != d->unk02)
                Sound_Play(0x64);
        }
        else if ((gRepeatedKeys & 0x100) && count > 6)
        {
            u16 cursor = d->cursor;
            u16 top = d->unk02;

            if (d->cursor != 5)
                d->cursor = 5;
            else if (cursor + top + 6 < count - 1)
                d->unk02 = top + 6;
            else
                d->unk02 = count - 6;
            if (cursor != d->cursor || top != d->unk02)
                Sound_Play(0x64);
        }
    }
}

// sub_080DC0A0 @ 0x080DC0A0
void sub_080DC0A0(struct Task *task, u32 mode)
{
    Dict_BuildList(task, mode, task->data.h[0] + task->data.h[1]);
}

// sub_080DC0B0 @ 0x080DC0B0
void sub_080DC0B0(struct Task *task)
{
    struct Task *parent = Task_GetParent(task);
    struct Task *grandparent = Task_GetParent(parent);

    if (task->unk06 == 0)
    {
        Task_Create(gUnknown_08583CA0, grandparent->id);
        sub_080D9B34(parent);
        Task_End(parent);
        task->result = 1;
    }
    else
    {
        task->result = 0;
    }
}

/* List of up to 3-glyph names from gUnknown_0858367C (0x0301 ends a name); 10 entries. */
// sub_080DC0F0 @ 0x080DC0F0
void sub_080DC0F0(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    u16 x = 0x54;
    u16 y = 0x10;
    u16 count = 10;
    u32 row;

    Sprite_Draw(gUnknown_0800853C, 0, 7, 0, 0x100, 0x52, task->data.h[0] * 12 + 17);
    for (row = 0; row < 6; row++)
    {
        const u16 *name = gUnknown_0858367C[d->unk02 + row];
        u32 i;

        for (i = 0; name[i] != 0x301; )
        {
            FontSprite_DrawGlyph(name[i], 0, 0, x + i * 12, y + row * 12);
            i++;
            if (i > 2)
                break;
        }
    }
    if (d->unk02 != 0)
        sub_080C4A4C(0, 0, x + 0x60, y - 4);
    if (d->unk02 + 6 <= count - 1)
        sub_080C4AB0(0, 0, x + 0x60, y + 0x4C);
}

/* Eight-glyph names from gUnknown_08583788; 11 entries. */
// sub_080DC1D8 @ 0x080DC1D8
void sub_080DC1D8(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    u16 x = 0x54;
    u16 y = 0x10;
    u16 count = 11;
    u32 row, i;

    Sprite_Draw(gUnknown_0800853C, 0, 7, 0, 0x100, 0x52, task->data.h[0] * 12 + 17);
    for (row = 0; row < 6; row++)
    {
        const u16 *name = gUnknown_08583788[d->unk02 + row];

        for (i = 0; i < 8; i++)
            FontSprite_DrawGlyph(name[i], 0, 0, x + i * 12, y + row * 12);
    }
    if (d->unk02 != 0)
        sub_080C4A4C(0, 0, x + 0x60, y - 4);
    if (d->unk02 + 6 <= count - 1)
        sub_080C4AB0(0, 0, x + 0x60, y + 0x4C);
}
