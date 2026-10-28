#include "global.h"
#include "extras.h"

/* Two-way choice: up from side 1 or down from side 0 switches (answer 1); B cancels. */
// sub_080DCC04 @ 0x080DCC04
void sub_080DCC04(struct Task *task, u32 side)
{
    task->result = 0;
    task->unk1E = 0;
    if (gKeysNew & 1)
        return;
    if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        task->result = 1;
    }
    else if ((gRepeatedKeys & 0x40) && side == 1)
    {
        task->result = side;
        task->unk1E = side;
        Sound_Play(0x64);
    }
    else if ((gRepeatedKeys & 0x80) && side == 0)
    {
        task->result = 1;
        task->unk1E = 1;
        Sound_Play(0x64);
    }
}

// sub_080DCC78 @ 0x080DCC78
void sub_080DCC78(void)
{
    u16 x = 0x10;
    u16 y = 8;

    Sprite_Draw(gUnknown_08008C54, 0, 8, 0, 0, x, y);
    Sprite_Draw(gUnknown_08008C64, 0, 8, 0, 0, 0x50, 8);
    Sprite_Draw(gUnknown_08008C7C, 0, 8, 0, 0, 0x90, 8);
    Sprite_Draw(gUnknown_08008C8C, 0, 8, 0, 0, 0x10, 0x48);
    Sprite_Draw(gUnknown_08008C9C, 0, 8, 0, 0, 0x50, 0x48);
    Sprite_Draw(gUnknown_08008CB4, 0, 8, 0, 0, 0x90, 0x48);
    Sprite_Draw(gUnknown_08008CC4, 0, 8, 0, 0, 0x10, 0x88);
    Sprite_Draw(gUnknown_08008CD4, 0, 8, 0, 0, 0x50, 0x88);
    Sprite_Draw(gUnknown_08008CEC, 0, 8, 0, 0, 0x90, 0x88);
}

// sub_080DCD74 @ 0x080DCD74
void sub_080DCD74(void)
{
    DmaSet3(gUnk_02003000, 0x0600EC00, 0x84000500);
    DmaSet3(gUnknown_0857D5C0, 0x06012F00, 0x84000020);
    sub_080D9D24();
}

// sub_080DCDB8 @ 0x080DCDB8
void sub_080DCDB8(struct Task *task)
{
    u16 *pal;

    gUnk_03000038 |= 0x3F;
    Tilemap_CopyRect(gUnknown_085805C0, gUnk_0201D874, 0x360, 7, 4, 1, 0x16, 0xB);
    Palette_CopyWithEffect(3, gUnknown_08581140, pal = gPaletteTarget + 0x270, 0x20, 0x20);
    Palette_CopyWithEffect(3, gUnknown_08581240, pal + 0x120, 0x20, 0x20);
    Palette_MarkDirty();
    VBlankTask_AddCounted(sub_080DCD74, 1);
    task->data.h[0] = 0;
    task->data.h[1] = 4;
}

// sub_080DCE4C @ 0x080DCE4C
void sub_080DCE4C(void)
{
    sub_080AF218(0x24, (gUnknown_08583E84 + gDict.selected)->script);
}

// sub_080DCE70 @ 0x080DCE70
void sub_080DCE70(struct Task *task)
{
    if (gFieldState.state == 0x24)
        task->result = 1;
    else
        task->result = 0;
}

/* Blinks the two markers of the selected demon's map record. */
// sub_080DCE8C @ 0x080DCE8C
void sub_080DCE8C(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    const struct C0d9MapRec *rec = &gUnknown_08583E84[gDict.selected];

    if (--d->unk02 == 0)
    {
        d->unk02 = 4;
        if (++task->data.h[0] == 3)
            task->data.h[0] = 0;
    }
    Sprite_Draw(gUnknown_08583BEC[d->cursor], 0, 9, 0, 0x178, rec->x1, rec->y1);
    Sprite_Draw(gUnknown_08583BEC[d->cursor], 0, 9, 0, 0x178, rec->x2, rec->y2);
}

/* Recomputes the saved list window (unk44 cursor, unk46 top) from the index unk3C. */
// sub_080DCF20 @ 0x080DCF20
void sub_080DCF20(struct Task *task)
{
    u16 n = Dict_CountListed();

    if (n <= 6)
    {
        gDict.unk44 = gDict.unk3C;
        gDict.unk46 = 0;
    }
    else if (gDict.unk3C > n - 7)
    {
        u16 c = gDict.unk3C - (n - 6);

        gDict.unk46 = gDict.unk3C - c;
        gDict.unk44 = c;
    }
    else
    {
        gDict.unk46 = gDict.unk3C;
        gDict.unk44 = 0;
    }
}

/* Map page input: up/down picks the marker, L/R steps through the compendium (with a
   30-frame lock after each step). */
// sub_080DCF80 @ 0x080DCF80
void sub_080DCF80(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    u16 count = Dict_CountListed();
    u32 moved = 0;

    task->result = moved;
    task->unk1E = moved;
    if ((gKeysNew & 1) && d->unk12 == 0)
    {
        if (sub_080C2644(gDict.selected))
        {
            task->unk1E = task->data.h[0] + 1;
            Sound_Play(0x65);
            task->result = 1;
        }
        else
        {
            Sound_Play(0x66);
        }
    }
    else if ((gKeysNew & 2) && d->unk12 == 0)
    {
        Sound_Play(0x66);
        task->result = 1;
    }
    else if ((gRepeatedKeys & 0x40) && d->unk12 == 0)
    {
        if (d->cursor != 0)
            d->cursor--;
        else
            d->cursor = 1;
        Sound_Play(0x64);
    }
    else if ((gRepeatedKeys & 0x80) && d->unk12 == 0)
    {
        if (d->cursor != 1)
            d->cursor++;
        else
            d->cursor = d->unk12;
        Sound_Play(0x64);
    }
    else if ((gRepeatedKeys & 0x100) && d->unk12 == 0)
    {
        if (gDict.unk3C != count - 1)
            gDict.unk3C++;
        else
            gDict.unk3C = d->unk12;
        sub_080DCF20(task);
        moved = 1;
    }
    else if ((gRepeatedKeys & 0x200) && d->unk12 == 0)
    {
        u16 i = gDict.unk3C;

        if (i == 0)
            i = count;
        gDict.unk3C = i - 1;
        sub_080DCF20(task);
        moved = 1;
    }
    if (moved == 1)
    {
        u16 *list = gUnk_0203B554;

        gDict.selected = list[gDict.unk3C] & 0x7FFF;
        sub_080DB464(task);
        d->unk12 = 30;
    }
    if (d->unk12 != 0)
        d->unk12--;
    if (((gFrameCounter >> 3) & 1) == 0)
    {
        Sprite_Draw(gUnknown_08008784, 0, 7, 0, 0x100, 0x10, 0x78);
        Sprite_Draw(gUnknown_08008750, 0, 7, 0, 0x100, 0xC9, 0x78);
    }
    else
    {
        Sprite_Draw(gUnknown_080087A0, 0, 7, 0, 0x100, 0x10, 0x78);
        Sprite_Draw(gUnknown_0800876C, 0, 7, 0, 0x100, 0xC9, 0x78);
    }
}
