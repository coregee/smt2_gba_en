/* Battle menu: skill list reordering (swap two entries of the 0x030051AC table). */

#include "global.h"
#include "bmenu.h"

// sub_0812BBE4 @ 0x0812BBE4
void sub_0812BBE4(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct C127SortEntry *list = (struct C127SortEntry *)blk->list;
    struct MenuCursor *c = sub_08126D1C(4);
    u8 oldTop = c->top;

    sub_08126A08(4);
    task->pad1E = 0;
    task->result = 0;
    if (gKeysNew & 2)
    {
        task->pad1E = 0x100;
        task->result = 1;
    }
    else if (gKeysNew & 1)
    {
        task->pad1E = list[c->index].id;
        task->result = 1;
    }
    if (oldTop != c->top)
        BattleMenu_DrawListPage(5, c->top + (task->data.raw[8] << 8));
    Sprite_Draw(gUnknown_08000F8C, 0, 0, 1, 0, 0x14, c->onScreen * 13 + 6);
    if (c->count > 5)
    {
        if (c->top != 0)
            Sprite_Draw(gUnknown_08000FF0, 0, 0, 1, 0, 0x94, 4);
        if (c->top + 5 != c->count)
            Sprite_Draw(gUnknown_08001000, 0, 0, 1, 0, 0x94, 0x43);
    }
}

/* Finds the (id, count) entry for `id` in the table at 0x030051AC (no end check). */
// Inventory_Find @ 0x0812BCD4
u16 *Inventory_Find(u16 id)
{
    u16 *p = gInventory;

    while (*p != id)
        p += 2;
    return p;
}

// sub_0812BCF4 @ 0x0812BCF4
void sub_0812BCF4(struct Task *task)
{
    u32 *a = (u32 *)Inventory_Find(task->data.raw[8]);
    u32 *b = (u32 *)Inventory_Find(task->pad1E);
    u32 t = *a;

    *a = *b;
    *b = t;
    sub_0812B320(0xFF);
}

// sub_0812BD1C @ 0x0812BD1C
void sub_0812BD1C(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    u16 n = 0;

    task->pad1E = n;
    sub_080EA210();
    n = sub_0812B320(0xFF);
    if (n == 0)
    {
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(gUnknown_08124BF4, 0));
        task->pad1E = 1;
    }
    else
    {
        blk->unk4C = TextWindow_Create(1, 0, 0x13, 0xA, 1);
        sub_081272AC();
        if (n <= 4)
            sub_08126928(4, 0, 1, n, n);
        else
            sub_08126928(4, 0x10, 1, n, 5);
    }
}

// sub_0812BD9C @ 0x0812BD9C
void sub_0812BD9C(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct C127SortEntry *list = (struct C127SortEntry *)blk->list;
    struct MenuCursor *c = sub_08126D1C(4);
    u8 oldTop = c->top;

    sub_08126A08(4);
    task->pad1E = 0;
    task->result = 0;
    if (gKeysNew & 2)
    {
        task->pad1E = 0x100;
        task->result = 1;
    }
    else if (gKeysNew & 1)
    {
        task->data.raw[8] = list[c->index].id;
        task->result = 1;
    }
    if (oldTop != c->top)
        BattleMenu_DrawListPage(6, c->top);
    Sprite_Draw(gUnknown_08000F8C, 0, 0, 1, 0, 0x14, c->onScreen * 13 + 6);
    if (c->count > 5)
    {
        if (c->top != 0)
            Sprite_Draw(gUnknown_08000FF0, 0, 0, 1, 0, 0x94, 4);
        if (c->top + 5 != c->count)
            Sprite_Draw(gUnknown_08001000, 0, 0, 1, 0, 0x94, 0x43);
    }
}

// sub_0812BE84 @ 0x0812BE84
void sub_0812BE84(void)
{
    struct C127Block *blk = C127_BLOCK;
    struct Task *t;

    blk->unk48 = Task_Create(gUnknown_087795D8, 0xFFFF);
    blk->unk48->data.raw[0] = 0;
    t = blk->unk48;
    BattleMsg_Close();
    t->data.w[1] = -1;
}

// sub_0812BEB8 @ 0x0812BEB8
void sub_0812BEB8(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    u16 n = 0;

    task->pad1E = n;
    sub_080EA210();
    n = sub_0812B320(0xFF);
    if (n == 0)
    {
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(gUnknown_08124C38, 0));
        task->pad1E = 1;
    }
    else
    {
        blk->unk4C = TextWindow_Create(1, 0, 0x13, 0xA, 1);
        sub_081272AC();
        if (n <= 4)
            sub_08126928(4, 0, 1, n, n);
        else
            sub_08126928(4, 0x10, 1, n, 5);
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(gUnknown_08124CE6, 0));
        BattleMsg_SetDone(1);
    }
}
