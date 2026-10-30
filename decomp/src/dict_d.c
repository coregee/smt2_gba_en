#include "global.h"
#include "extras.h"

/* Compendium list (fusion variant): entries with bit 15 set are drawn tinted. */
// sub_080DC2B0 @ 0x080DC2B0
void sub_080DC2B0(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    u16 count = Dict_CountListed();
    u16 x = 0x54;
    u16 y = 0x10;
    u32 row, i;

    Sprite_Draw(gUnknown_0800853C, 0, 7, 0, 0x100, 0x52, task->data.h[0] * 12 + 17);
    if (gDict.unk3E == 1)
    {
        for (row = 0; row < 6; row++)
        {
            u16 v = ((u16 *)0x0203B554)[d->unk02 + row];

            if (v != 0xFFFF)
            {
                u16 id = v & 0x7FFF;
                const u16 *name;

                if (sub_080C2644(id))
                    name = (const u16 *)(Demon_GetRecord(id) + 0x22);
                else
                    name = gUnknown_0858325A;
                for (i = 0; i < 8; i++)
                {
                    if (!(v & 0x8000))
                        FontSprite_DrawGlyph(name[i], 0, 0, x + i * 12, y + row * 12);
                    else
                        FontSprite_DrawGlyphTinted(name[i], 0, 0, x + i * 12, y + row * 12, 1);
                }
            }
        }
        if (d->unk02 != 0)
            sub_080C4A4C(0, 0, x + 0x60, y - 4);
        if (d->unk02 + 6 <= count - 1)
            sub_080C4AB0(0, 0, x + 0x60, y + 0x4C);
    }
    else
    {
        Text_DrawSpriteString(gUnknown_0800974E, 0, 0, x, y, 12);
    }
}

/* Remembers the list position and shows the selected demon. */
// sub_080DC418 @ 0x080DC418
void sub_080DC418(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    u16 *list = gStatusList;
    struct C0d9Dict *dict = &gDict;
    u16 cursor = task->data.h[0];
    u16 top = d->unk02;

    dict->unk3C = cursor + top;
    dict->unk44 = cursor;
    dict->unk46 = top;
    dict->selected = list[task->data.h[0] + d->unk02] & 0x7FFF;
    sub_080DB464(task);
}

/* Compendium list input; moving the cursor shows the new demon (sub_080DC418). */
// sub_080DC460 @ 0x080DC460
void sub_080DC460(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    struct Task *parent = Task_GetParent(task);
    u16 count = Dict_CountListed();
    u32 moved = 0;
    u16 rows;

    if (gDict.unk3E == 0)
        count = 1;
    rows = count;
    if (count > 5)
        rows = 6;
    task->result = moved;
    task->unk1E = moved;
    if ((gKeysNew & 1) && gDict.unk3E == 1)
    {
        moved = 1;
        Sound_Play(0x65);
        task->result = moved;
        parent->unk06 = 0;
    }
    else if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        task->result = 1;
        parent->unk06 = 1;
    }
    else if (gRepeatedKeys & 0x40)
    {
        if (d->cursor != 0)
        {
            d->cursor--;
            moved = 1;
            Sound_Play(0x64);
        }
        else if (d->unk02 != 0)
        {
            d->unk02--;
            moved = 1;
            Sound_Play(0x64);
        }
    }
    else
    {
        u16 down = gRepeatedKeys & 0x80;

        if (down)
        {
            if (d->cursor != rows - 1)
            {
                d->cursor++;
                moved = 1;
                Sound_Play(0x64);
            }
            else if (d->cursor == 5 && d->cursor + d->unk02 + 1 <= count - 1)
            {
                d->unk02++;
                moved = 1;
                Sound_Play(0x64);
            }
        }
        else if ((gRepeatedKeys & 0x200) && count > 6)
        {
            u32 cursor = d->cursor;
            u16 top = d->unk02;
            u16 t = cursor;

            if (t != 0)
            {
                d->cursor = down;
            }
            else
            {
                if (top > 4)
                    d->unk02 = top - 5;
                else
                    d->unk02 = t;
            }
            if (cursor != d->cursor || top != d->unk02)
            {
                moved = 1;
                Sound_Play(0x64);
            }
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
            {
                moved = 1;
                Sound_Play(0x64);
            }
        }
    }
    if (moved == 1)
        sub_080DC418(task);
}

/* Restores the list position saved by sub_080DC418, keeping the cursor in the window. */
// sub_080DC5C8 @ 0x080DC5C8
void sub_080DC5C8(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    struct C0d9Dict *dict = &gDict;

    if (dict->unk3E == 1)
    {
        u16 n = Dict_CountListed();

        if (n <= 6)
        {
            task->data.h[0] = dict->unk3C;
        }
        else if (dict->unk3C > n - 7)
        {
            u16 c = dict->unk3C - (n - 6);

            d->unk02 = dict->unk3C - c;
            task->data.h[0] = c;
        }
        else
        {
            d->unk02 = dict->unk3C;
        }
    }
    else
    {
        d->unk02 = 0;
    }
}

// sub_080DC618 @ 0x080DC618
void sub_080DC618(struct Task *task)
{
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
    else
    {
        u16 up = gRepeatedKeys & 0x40;

        if (up)
        {
            if (task->data.h[0] != 0)
                task->data.h[0]--;
            else
                task->data.h[0] = 2;
            Sound_Play(0x64);
        }
        else if (gRepeatedKeys & 0x80)
        {
            if (task->data.h[0] != 2)
                task->data.h[0]++;
            else
                task->data.h[0] = up;
            Sound_Play(0x64);
        }
    }
}

// sub_080DC6A4 @ 0x080DC6A4
void sub_080DC6A4(void)
{
    DmaSet3(gUnk_0200F874, 0x06010000, 0x84001400);
}

// sub_080DC6C8 @ 0x080DC6C8
u16 sub_080DC6C8(u16 id)
{
    return id;
}
