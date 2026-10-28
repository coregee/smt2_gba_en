#include "global.h"
#include "menu2.h"

/* Draws the info panel (level, two classifications and a number) for record `id`. */
// sub_080D3F04 @ 0x080D3F04
void sub_080D3F04(struct Task *task, u32 id, u32 vblank)
{
    u16 x = 0x8A;
    u16 y = 0xD;
    u8 *rec = Demon_GetRecord(id);
    s32 kind = sub_0815B864(id);
    u32 value = sub_080D45B8(id);
    u32 zero;
    u32 zero2;

    zero = 0;
    CpuSet(&zero, gUnk_0200F874, 0x05000800);
    zero2 = 0;
    CpuSet(&zero2, gUnk_02000800, 0x05000200);
    Tilemap_CopyRectSkipZero(gUnknown_081B93B0, gUnk_02000800, 0x100, 0, 0, 0, 0x1E, 0xA);
    sub_080CCE5C(gUnknown_084F367C, x, y, 4);
    if (rec[1] < 10)
        sub_080CCF44(rec[1], 0xDC, 0xD, 0);
    else
        sub_080CCF44(rec[1], 0xDC, 0xD, 0);
    y += 10;
    sub_080CCE5C(gUnknown_084F3680, x, y, 4);
    if ((s8)rec[0] <= 12)
        sub_080CCE5C(gUnknown_084F3684, x + 0x32, y, 0);
    else if ((s8)rec[0] <= 26)
        sub_080CCE5C(gUnknown_084F368C, x + 0x22, y, 0);
    else
        sub_080CCE5C(gUnknown_084F3694, x + 0x3A, y, 0);
    y += 10;
    if (kind == 0)
        sub_080CCE5C(gUnknown_084F369C, x + 0x42, y, 0);
    else if (kind == 1)
        sub_080CCE5C(gUnknown_084F368C, x + 0x22, y, 0);
    else if (kind == 2)
        sub_080CCE5C(gUnknown_084F36A0, x + 0x32, y, 0);
    y += 10;
    sub_080CCE5C(gUnknown_084F36A8, x, y, 4);
    sub_080CCF44(value, x + 0x52, y, 0);
    if (vblank == 0)
        VBlankTask_AddCounted(sub_080D3EA0, 1);
    else
        VBlankTask_AddCounted(sub_080D3E64, 1);
}

// sub_080D40AC @ 0x080D40AC
void sub_080D40AC(void)
{
    DmaSet3(gUnk_02000000, (void *)0x06001000, 0x84000200);
    DmaSet3(gUnknown_081B5810, (void *)0x06012F00, 0x84000018);
}

// sub_080D40E8 @ 0x080D40E8
void sub_080D40E8(struct Task *task)
{
    struct RecordList *list = (struct RecordList *)task->data.w;
    u16 *ids = gUnk_0203B454;
    u32 zero;
    u32 zero2;

    zero = 0;
    CpuSet(&zero, ids, 0x05000040);
    list->count = sub_080D45F0(ids, list->filter);
    zero2 = 0;
    CpuSet(&zero2, gUnk_02000000, 0x05000200);
    Tilemap_CopyRectStride(gUnknown_08770A24, gUnk_02000000, 0, 0, 1, 0, 0x1C, 0xA, 0x1C);
    Tilemap_CopyRectSkipZero(gUnknown_081B8170, gUnk_02000000, 0, 0, 0x16, 6, 8, 2);
    VBlankTask_AddCounted(sub_080D40AC, 1);
    sub_080D3F04(task, ids[0], 0);
}

// sub_080D4190 @ 0x080D4190
void sub_080D4190(struct Task *task)
{
    struct RecordList *list = (struct RecordList *)task->data.w;
    u16 count = list->count;
    u16 x = 12, y = 2;
    u32 i, j;

    sub_080C49EC(0xB, 0, 0, 0xC, list->cursor * 12 + y);
    for (i = 0; i < 6; i++)
    {
        u16 id = gUnk_0203B454[list->top + i];
        if (id != 0)
        {
            u16 *name = (u16 *)(Demon_GetRecord(id) + 0x22);
            for (j = 0; j < 8; j++)
                FontSprite_DrawGlyph(name[j], 0, 0, x + j * 12, i * 12 + y);
        }
    }
    Sprite_Draw(gUnknown_08002A94, 0, 0, 0, 0x170, 0xB2, 0x35);
    sub_080C8048(Inventory_GetCount(0x11F), 0xB8, 0x35, 0);
    if (list->top != 0)
        sub_080C4A4C(0, 0, x + 0x6E, y + 2);
    if (list->top + 6 <= count - 1)
        sub_080C4AB0(0, 0, x + 0x6E, y + 0x44);
}

#define REDRAW() sub_080D3F04(task, ids[list->cursor + list->top], 0)

/* Record list input: A picks, B cancels (clears flag 0x162), up/down/L/R move and redraw the panel. */
// sub_080D429C @ 0x080D429C
void sub_080D429C(struct Task *task)
{
    struct RecordList *list = (struct RecordList *)task->data.w;
    u16 *ids = gUnk_0203B454;
    u16 count = list->count;
    u16 rows;

    task->result = 0;
    task->unk1E = 0;
    rows = count;
    if (count > 5)
        rows = 6;
    if (!PalFade_AllDone())
        return;
    if (Palette_IsBg13Black() == 1)
        return;
    if (gKeysNew & 1)
    {
        u16 id = ids[list->cursor + list->top];
        Sound_Play(0x65);
        task->unk1E = 1;
        task->result = 1;
        gYesNoResult = 0;
        gUnk_0203DB28 = id;
    }
    else if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        task->result = 1;
        task->unk1E = 0xFFFF;
        gYesNoResult = 1;
        Flag_Clear(0x162);
    }
    else if (gRepeatedKeys & 0x40)
    {
        if (list->cursor != 0)
        {
            list->cursor--;
            Sound_Play(100);
        }
        else if (list->top != 0)
        {
            list->top--;
            Sound_Play(100);
        }
        REDRAW();
    }
    else if (gRepeatedKeys & 0x80)
    {
        if (list->cursor != rows - 1)
        {
            list->cursor++;
            Sound_Play(100);
        }
        else if (list->cursor == 5 && list->cursor + list->top + 1 <= count - 1)
        {
            list->top++;
            Sound_Play(100);
        }
        REDRAW();
    }
    else if ((gRepeatedKeys & 0x200) && count > 6)
    {
        u16 cursor = list->cursor;
        u16 top = list->top;
        if (list->cursor != 0)
        {
            list->cursor = 0;
            REDRAW();
        }
        else if (list->top > 4)
        {
            list->top -= 5;
            REDRAW();
        }
        else
        {
            list->top = 0;
            REDRAW();
        }
        if (cursor != list->cursor || top != list->top)
            Sound_Play(100);
    }
    else if ((gRepeatedKeys & 0x100) && count > 6)
    {
        u16 cursor = list->cursor;
        u16 top = list->top;
        if (list->cursor != 5)
        {
            list->cursor = 5;
            REDRAW();
        }
        else if (list->cursor + list->top + 6 < count - 1)
        {
            list->top += 6;
            REDRAW();
        }
        else
        {
            list->top = count - 6;
            REDRAW();
        }
        if (cursor != list->cursor || top != list->top)
            Sound_Play(100);
    }
}

// sub_080D44A0 @ 0x080D44A0
void sub_080D44A0(struct Task *task)
{
    struct RecordList *list = (struct RecordList *)task->data.w;
    struct Task *child = Task_Create(gUnknown_084F1514, 0xFFFF);
    struct StatusMenu2 *menu = STATUS_MENU2;
    u32 zero = 0;

    CpuSet(&zero, menu, 0x05000200);
    menu->page = list->cursor + list->top;
    if (list->filter == 0)
        menu->mode = 0xB;
    else
        menu->mode = 0xC;
    menu->unk22 = 0;
    list->unk04 = (u32)child;
    gUnk_03003BB4 = 0;
}

// sub_080D4500 @ 0x080D4500
void sub_080D4500(struct Task *task)
{
    if (((struct Task *)task->data.w[1])->state == 0)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080D4518 @ 0x080D4518
void sub_080D4518(void)
{
    u32 zero = 0;

    CpuSet(&zero, gUnk_02000000, 0x05000200);
    VBlankTask_AddCounted(sub_080D40AC, 1);
    VBlankTask_AddCounted(sub_080D3EC8, 1);
    sub_080C6558();
    sub_080C6764();
}

// sub_080D4558 @ 0x080D4558
void sub_080D4558(struct Task *task)
{
    task->result = task->unk06;
}

// sub_080D4560 @ 0x080D4560
void sub_080D4560(u16 filter)
{
    struct Task *task = Task_Create(gUnknown_084F36B0, 0xFFFF);

    gUnk_03003FEC = task;
    task->data.h[7] = filter;
    gUnk_03003BB4 = 0;
}

// sub_080D4594 @ 0x080D4594
u32 sub_080D4594(void)
{
    u32 done;

    Font_ResetGlyphSpriteCache(0x180);
    done = 0;
    if (gUnk_03003FEC->state == 0)
        done = 1;
    return done;
}

// sub_080D45B8 @ 0x080D45B8
s32 sub_080D45B8(u16 id)
{
    s32 ret;

    if ((u16)(id - 0x16A) < 0x12)
        ret = gUnknown_084F3754[id - 0x16A].id;
    else
        ret = -1;
    return ret;
}

/* Fills `out` with the first items of the combination table entries that are available
   (mode 0: depends on flag 0x162 and the learnt bits; otherwise every owned item). */
// sub_080D45F0 @ 0x080D45F0
u16 sub_080D45F0(u16 *out, u16 mode)
{
    u16 n = 0;
    u16 idx = 0;
    const struct ComboEntry *e = gUnknown_084F3754;

    if (mode == 0)
    {
        Inventory_GetCount(0x11F);
        if (!Flag_Test(0x162))
        {
            for (; e->id != -1; e++)
            {
                if (Stock_FindByDemonId(e->items[0]))
                    continue;
                if (e->bit != 0)
                    continue;
                if (e->items[1] != 0 && Stock_FindByDemonId(e->items[1]))
                    continue;
                if (e->items[2] != 0 && Stock_FindByDemonId(e->items[2]))
                    continue;
                out[n] = e->items[0];
                n++;
            }
        }
        else
        {
            for (; e->id != -1; idx++, e++)
            {
                if (Stock_FindByDemonId(e->items[0]))
                    continue;
                if (e->bit == 0)
                    continue;
                if (e->items[1] != 0 && Stock_FindByDemonId(e->items[1]))
                    continue;
                if (e->items[2] != 0 && Stock_FindByDemonId(e->items[2]))
                    continue;
                if (ComboBits_Test(idx))
                {
                    out[n] = e->items[0];
                    n++;
                }
            }
        }
    }
    else
    {
        for (; e->id != -1; e++)
        {
            if (Stock_FindByDemonId(e->items[0]))
            {
                out[n] = e->items[0];
                n++;
            }
        }
    }
    return n;
}
