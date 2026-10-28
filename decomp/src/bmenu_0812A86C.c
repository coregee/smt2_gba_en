/* Battle menu: item and tactics submenus, item list sorting. */

#include "global.h"
#include "bmenu.h"

// sub_0812A86C @ 0x0812A86C
void sub_0812A86C(struct Task *task, u32 arg)
{
    struct C127Block *blk = C127_BLOCK;
    struct MenuCursor *c = sub_08126D1C(2);
    u16 row = c->row;
    u8 i;
    u16 y;

    sub_08126A08(2);
    if (arg == 1 && task->unk06 != 0)
        arg = 0;
    task->pad1E = 0;
    task->result = 0;
    if ((gKeysNew & 2) && arg == 0)
    {
        task->pad1E = 0xFF;
        task->result = 1;
    }
    else if (gKeysNew & 1)
    {
        task->pad1E = c->row;
        blk->unk697 = c->row;
        task->result = 1;
    }
    else if (c->state == 6)
    {
        if (blk->unk7E0 == 4)
        {
            BattleMenu_Reset();
            BattleMsg_Close();
        }
        else
        {
            sub_080EA210();
            BattleMenu_SetMode(4, gUnknown_08778ACC[c->row]);
        }
    }
    else if (row != c->row && blk->unk7E0 == 4)
    {
        BattleMenu_SetMode(4, gUnknown_08778ACC[c->row]);
    }
    Sprite_Draw(gUnknown_08000EE4, 0, 0, 0, 0, 0x4C, c->row * 12 + 10);
    for (i = 0; i < 4; i++)
    {
        Sprite_DrawSingle(gUnknown_08777F60[i], 0, 0, 0, 0, 0x50, y = i * 12 + 14);
        Sprite_DrawSingle(gUnknown_08777F60[i] + 8, 0, 0, 0, 0, 0x70, y);
        Sprite_DrawSingle(gUnknown_08778AC4, 0, 0, 0, 0, 0x80, y);
    }
}

// sub_0812A9EC @ 0x0812A9EC
void sub_0812A9EC(void)
{
    struct C127Block *blk = C127_BLOCK;

    if (blk->unk696 == 0)
    {
        sub_08128EB4();
    }
    else
    {
        if (blk->unk7E0 == 4)
            BattleMsg_Close();
        sub_081279D4();
        if (gFieldState.state == 0x1B)
        {
            Field_SetState(0x1E);
            gFieldState.unk1E = 0;
        }
        else
        {
            Field_SetState(1);
        }
        sub_080C7234();
        sub_080C762C();
        sub_080C7C94();
    }
    sub_081269B0(2);
}

// sub_0812AA54 @ 0x0812AA54
void sub_0812AA54(void)
{
    struct C127Block *blk = C127_BLOCK;

    if (blk->unk696 == 0)
    {
        sub_08128EB4();
    }
    else
    {
        sub_081279D4();
        if (gFieldState.state == 0x1B)
        {
            Field_SetState(0x1E);
            gFieldState.unk1E = 0;
        }
        else
        {
            Field_SetState(1);
        }
        sub_080C7234();
        sub_080C762C();
        sub_080C7C94();
    }
    BattleMsg_Close();
    sub_081269B0(2);
}

// sub_0812AAB0 @ 0x0812AAB0
void sub_0812AAB0(struct Task *task, u32 arg)
{
    struct C127Block *blk = C127_BLOCK;
    u16 n;

    blk->unk4C = TextWindow_Create(1, 0, 0xF, 0xA, 1);
    blk->unk50 = TextWindow_Create(0x11, 0, 0xC, 6, 1);
    sub_081272AC();
    n = sub_0812A668(blk->unk697);
    sub_081269B0(2);
    if (n <= 4)
        sub_08126928(2, 0, 1, n, n);
    else
        sub_08126928(2, 0x10, 1, n, 5);
    if (arg == 1)
        MenuCursor2_SaveRestore(1);
    sub_080EA210();
    BattleMenu_SetMode(4, gUnknown_08123DF0);
}

// sub_0812AB44 @ 0x0812AB44
void sub_0812AB44(void)
{
    struct MenuCursor *c = sub_08126D1C(2);

    BattleMenu_DrawListPage(1, c->top);
    sub_081283C4(2, c->index);
}

// sub_0812AB64 @ 0x0812AB64
void sub_0812AB64(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct MenuCursor *c = sub_08126D1C(2);
    u8 old = c->index;

    sub_08126A08(2);
    task->pad1E = 0;
    task->result = 0;
    if (gKeysNew & 2)
    {
        task->pad1E = 0x100;
        task->result = 1;
    }
    else if ((gKeysNew & 1) && !(blk->list[c->index] & 0x8000))
    {
        task->pad1E = c->index;
        task->result = 1;
        MenuCursor2_SaveRestore(0);
    }
    Sprite_Draw(gUnknown_08000EA4, 0, 0, 1, 0, 0xC, c->onScreen * 13 + 6);
    if (c->count > 5)
    {
        if (c->top != 0)
            Sprite_Draw(gUnknown_08000FF0, 0, 0, 1, 0, 0x74, 4);
        if (c->top + 5 != c->count)
            Sprite_Draw(gUnknown_08001000, 0, 0, 1, 0, 0x74, 0x43);
    }
    if (old != c->index)
    {
        BattleMenu_DrawListPage(1, c->top);
        sub_081283C4(2, c->index);
    }
}

/* Saves cursor 2 to gSavedMenuCursor (mode 0) or restores it and its position (mode 1). */
// MenuCursor2_SaveRestore @ 0x0812AC68
void MenuCursor2_SaveRestore(u16 mode)
{
    u8 *src;
    u8 *dst;
    u32 i;

    if (mode == 0)
    {
        src = (u8 *)sub_08126D1C(2);
        dst = (u8 *)&gSavedMenuCursor;
    }
    else
    {
        src = (u8 *)&gSavedMenuCursor;
        dst = (u8 *)sub_08126D1C(2);
    }
    for (i = 0; i < sizeof(struct MenuCursor); i++)
        *dst++ = *src++;
    if (mode == 1)
        MenuCursor_SetIndex(2, gSavedMenuCursor.index);
}

// sub_0812ACB8 @ 0x0812ACB8
void sub_0812ACB8(struct Task *task)
{
    sub_080CB01C(0, task->pad1E);
    sub_081269B0(2);
}

// sub_0812ACCC @ 0x0812ACCC
u16 sub_0812ACCC(u16 i)
{
    return C127_BLOCK->list[i];
}

/* Sorts the 0x15A (id, key) pairs at 0x030051AC by key through the canvas buffer and
   drops the empty ones (key -1). */
// Inventory_Sort @ 0x0812ACE4
void Inventory_Sort(void)
{
    struct C127SortEntry *buf = (struct C127SortEntry *)gUnk_030000B4;
    u32 zero = 0;
    struct C127SortEntry *src;
    s32 i;

    CpuFastSet(&zero, buf, 0x0100015A);
    src = (struct C127SortEntry *)gInventory;
    for (i = 0; i < 0x15A; i++)
    {
        if (*(u32 *)src == 0)
        {
            buf[i].id = 0;
            buf[i].key = 0xFFF;
        }
        else
        {
            buf[i].id = src->key;
            buf[i].key = src->id;
        }
        src++;
    }
    src = (struct C127SortEntry *)gInventory;
    Battle_SortEntriesInsertion(0, 0x15A, buf);
    for (i = 0; i < 0x15A; i++)
    {
        if (buf[i].key != -1)
        {
            src->id = buf[i].key;
            src->key = buf[i].id;
            src++;
        }
    }
}

// sub_0812AD70 @ 0x0812AD70
void sub_0812AD70(void)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk44 = Task_Create(gUnknown_08778E04, 0xFFFF);
}

// sub_0812AD90 @ 0x0812AD90
void sub_0812AD90(void)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk4C = TextWindow_Create(9, 1, 0xC, 7, 1);
    sub_080C7E24(gUnk_030000B4, gUnknown_08778DD0);
    VBlankTask_AddCounted(sub_08128F28, 1);
    BattleMsg_Close();
    sub_08126928(5, 1, 1, 4, 4);
}

// sub_0812ADE4 @ 0x0812ADE4
void sub_0812ADE4(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct MenuCursor *c = sub_08126D1C(5);
    u16 row = c->row;
    u8 i;
    u16 y;

    sub_08126A08(5);
    task->pad1E = 0;
    task->result = 0;
    if (gKeysNew & 2)
    {
        task->pad1E = 0x100;
        task->result = 1;
    }
    else if (gKeysNew & 1)
    {
        task->pad1E = c->row;
        task->result = 1;
        task->data.raw[0] = 0;
    }
    else if (c->state == 6)
    {
        if (blk->unk7E0 == 4)
        {
            BattleMenu_Reset();
            BattleMsg_Close();
        }
        else
        {
            sub_080EA210();
            BattleMenu_SetMode(4, gUnknown_08778DF4[c->row]);
        }
    }
    else if (row != c->row && blk->unk7E0 == 4)
    {
        BattleMenu_SetMode(4, gUnknown_08778DF4[c->row]);
    }
    Sprite_Draw(gUnknown_08000EE4, 0, 0, 0, 0, 0x4C, c->row * 12 + 10);
    for (i = 0; i < 4; i++)
    {
        Sprite_DrawSingle(gUnknown_08777F60[i], 0, 0, 0, 0, 0x58, y = i * 12 + 14);
        Sprite_DrawSingle(gUnknown_08777F60[i] + 8, 0, 0, 0, 0, 0x78, y);
    }
}

// sub_0812AF34 @ 0x0812AF34
void sub_0812AF34(void)
{
    sub_08128B84(1);
    sub_081269B0(5);
}

// sub_0812AF48 @ 0x0812AF48
void sub_0812AF48(struct Task *task)
{
    u16 n;

    sub_080EA210();
    n = sub_0812B320(0xFF);
    if (n == 0)
    {
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(gUnknown_08124C20, 0));
        task->result = n;
    }
    else
    {
        BattleMenu_SetMode(3, gUnknown_081244BA);
        Inventory_Sort();
        task->result = 1;
    }
}

// sub_0812AF94 @ 0x0812AF94
void sub_0812AF94(void)
{
    BattleMenu_SetMode(3, gUnknown_081244C4);
}

// sub_0812AFA8 @ 0x0812AFA8
void sub_0812AFA8(void)
{
    BattleMenu_Reset();
    BattleMsg_Close();
}

// sub_0812AFB8 @ 0x0812AFB8
void sub_0812AFB8(struct Task *task, u16 value)
{
    sub_0812B194(0, value);
}

// sub_0812AFC8 @ 0x0812AFC8
void sub_0812AFC8(struct Task *task)
{
    u32 r = sub_0812B1D4();
    struct C127Block *blk = C127_BLOCK;
    u32 hi;

    task->result = 0;
    task->pad1E = 0;
    if (r != 0xFFFFFFFF)
    {
        task->result = 1;
        hi = r & 0xFFFF0000;
        if (hi == 0xFFFE0000)
        {
            task->pad1E = 0x100;
        }
        else
        {
            hi >>= 16;
            blk->unkF30[hi] = hi;
            gUnk_030065C0[1] = r;
            gUnk_030065C0[3] = hi;
            gUnk_030065C0[2] = 8;
        }
    }
}
