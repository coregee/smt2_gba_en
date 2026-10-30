/* Battle menu: item use and the skill (magic) list. */

#include "global.h"
#include "bmenu.h"

/* The (id, count) inventory table (gInventory). sub_0812B260 and sub_0812B3A4 only match
   when it is addressed through the constant address rather than the symbol. */
struct InvSlot
{
    u16 id;
    u16 count;
};
#define INV_SLOTS ((struct InvSlot *)0x030051AC)

// sub_0812B028 @ 0x0812B028
void sub_0812B028(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    u16 item;
    const u16 *tmpl;
    s32 attr;
    u16 who;

    task->result = 0;
    switch (task->pad1E)
    {
    case 0:
        item = gUnk_030065C0[1];
        gUnk_03006440 = item;
        sub_080EA210();
        tmpl = gUnknown_08124D5E;
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(tmpl, (item << 16) + Party_FirstActiveHuman()));
        task->pad1E = 1;
        break;
    case 1:
        if (BattleMsg_IsDone() == 1)
        {
            item = gUnk_030065C0[1];
            sub_080F3E54(item, -1);
            Item_GetAttribute(item, 0xC, &attr);
            if (attr <= 0x7F)
            {
                sub_0812E780(gUnk_030065C0[3], blk->unkF30, gUnknown_08124D5E, 1);
                if ((u32)(attr - 0x3E) <= 1)
                {
                    who = Battle_SummonQueuedDemon(0, 2);
                    BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(0xE9), gGameState.order[who]));
                }
            }
            else
            {
                sub_0812EA98(gUnk_030065C0[3]);
            }
            task->pad1E = 2;
        }
        break;
    case 2:
        if (BattleMsg_IsDone() == 1)
        {
            BattleMenu_Reset();
            BattleMsg_Close();
            task->pad1E = 3;
        }
        break;
    case 3:
        task->result = 1;
        break;
    }
}

// sub_0812B138 @ 0x0812B138
void sub_0812B138(struct Task *task)
{
    u16 n;
    struct MenuCursor *c;

    task->result = 1;
    if (!Inventory_GetCount(gUnk_03006440))
    {
        n = sub_0812B260(0);
        if (n != 0)
        {
            if (n <= 4)
            {
                gSavedMenuCursor.count = n;
                gSavedMenuCursor.perColumn = n;
            }
            else
            {
                gSavedMenuCursor.count = n;
                gSavedMenuCursor.perColumn = 5;
            }
            c = &gSavedMenuCursor;
            if (c->index > n - 1)
                c->index = c->index - 1;
        }
        else
        {
            task->result = n;
        }
    }
}

// sub_0812B194 @ 0x0812B194
void sub_0812B194(u8 mode, u16 value)
{
    struct C127Block *blk = C127_BLOCK;
    struct Task *t;

    gUnk_03006478 = value;
    blk->unk48 = Task_Create(gUnknown_087790C4, 0xFFFF);
    blk->unk48->data.raw[0] = mode;
    t = blk->unk48;
    BattleMsg_Close();
    t->data.w[1] = -1;
}

// sub_0812B1D4 @ 0x0812B1D4
u32 sub_0812B1D4(void)
{
    return C127_BLOCK->unk48->data.w[1];
}

/* Counts active party members (of the first n, at most 6) whose Combatant_GetChosenSkill is `who`. */
// sub_0812B1E0 @ 0x0812B1E0
u16 sub_0812B1E0(s32 who, u8 num)
{
    u16 count = 0;
    u32 n = num;
    u16 i;
    u16 m;
    s8 *t;

    if (n == 0)
        return 0;
    if (n > 6)
        n = 6;
    i = 0;
    if (i < n)
    {
        t = gUnk_030050E0;
        do
        {
            m = *(s8 *)(i + (u32)t);
            if (Combatant_IsInParty(m) && ((u32 (*)(s32))sub_080F3040)(m) && sub_080C35E4(m) == 8 && Combatant_GetChosenSkill(m) == who)
                count++;
        } while (++i < n);
    }
    return count;
}

/* Lists the skills (0xD0-0xFD) in the (id, count) table at 0x030051AC usable in this
   context; returns how many. */
// sub_0812B260 @ 0x0812B260
u16 sub_0812B260(u8 mode)
{
    struct C127Block *blk = C127_BLOCK;
    struct C127SortEntry *out = (struct C127SortEntry *)blk->list;
    u16 n = 0;
    u8 mask;
    u16 i;
    u16 id;
    u16 cnt;

    mask = mode ? 0x20 : 0xC0;
    for (i = 0; i <= 0x159; i++)
    {
        id = INV_SLOTS[i].id;
        cnt = INV_SLOTS[i].count;
        if (mode == 1)
            cnt = cnt - sub_0812B1E0(id, blk->unkF66);
        if ((u16)(id - 0xD0) <= 0x2D && cnt != 0 && (Action_GetRecord(id)[0] & mask))
        {
            out->id = id;
            out->key = cnt;
            out++;
            n++;
        }
    }
    out->id = 0xFFFF;
    out->key = -1;
    return n;
}

// sub_0812B320 @ 0x0812B320
u16 sub_0812B320(u16 limit)
{
    struct C127Block *blk = C127_BLOCK;
    u16 *e = gInventory;
    u32 *out = (u32 *)blk->list;
    u16 n = 0;
    u16 i;

    for (i = 0; i <= 0x159; i++)
    {
        if (e[0] < limit && e[1] != 0)
        {
            *out++ = *(u32 *)e;
            n++;
        }
        e += 2;
    }
    ((struct C127SortEntry *)out)->id = 0xFFFF;
    ((struct C127SortEntry *)out)->key = -1;
    return n;
}

// sub_0812B37C @ 0x0812B37C
u32 sub_0812B37C(void)
{
    u32 r = 0;

    if (Flag_Test(0xD5))
        r = gShopItemIds[0] != 2;
    return r;
}

// sub_0812B3A4 @ 0x0812B3A4
u16 sub_0812B3A4(u8 mode)
{
    u16 n = 0;
    u8 mask;
    u16 i;
    u16 id;
    u16 cnt;

    mask = mode ? 0x20 : 0xC0;
    if (sub_0812B37C())
        return 0;
    for (i = 0; i <= 0x159; i++)
    {
        id = INV_SLOTS[i].id;
        cnt = INV_SLOTS[i].count;
        if ((u16)(id - 0xD0) <= 0x2E)
        {
            if (mode == 1)
                cnt = cnt - sub_0812B1E0(id, 0xFF);
            if ((s16)cnt > 0 && (Action_GetRecord(id)[0] & mask))
                n++;
        }
    }
    return n;
}

/* Saves cursor 4 to gSavedMenuCursor (mode 0) or restores it and its position (mode 1). */
// MenuCursor4_SaveRestore @ 0x0812B440
void MenuCursor4_SaveRestore(u16 mode)
{
    u8 *src;
    u8 *dst;
    u32 i;

    if (mode == 0)
    {
        src = (u8 *)sub_08126D1C(4);
        dst = (u8 *)&gSavedMenuCursor;
    }
    else
    {
        src = (u8 *)&gSavedMenuCursor;
        dst = (u8 *)sub_08126D1C(4);
    }
    for (i = 0; i < sizeof(struct MenuCursor); i++)
        *dst++ = *src++;
    if (mode == 1)
        MenuCursor_SetIndex(4, gSavedMenuCursor.index);
}

// sub_0812B490 @ 0x0812B490
void sub_0812B490(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    u16 n = 0;
    u32 busy;

    task->pad1E = n;
    sub_080EA210();
    busy = sub_0812B37C();
    if (busy != 0 || Party_FirstActiveHuman() == -1)
    {
        if (Flag_Test(0xD5))
            BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(0x392), 0));
        else
            BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(0x74), 0));
        task->pad1E = 1;
    }
    else
    {
        n = sub_0812B260(task->data.raw[0]);
        if (n == 0)
        {
            BattleMenu_SetMode(3, Menu_ExpandListTemplate(gUnknown_08124BD2, 0));
            task->pad1E = 1;
        }
        else
        {
            blk->unk4C = TextWindow_Create(1, 0, 0x13, 0xA, 1);
            blk->unk50 = sub_080AB890(2, 0xD, 0x1A, 6, busy);
            sub_081272AC();
            if (n <= 4)
                sub_08126928(4, 0, 1, n, n);
            else
                sub_08126928(4, 0x10, 1, n, 5);
            if (gUnk_03006478 != 0)
                MenuCursor4_SaveRestore(1);
        }
    }
}

// sub_0812B57C @ 0x0812B57C
void sub_0812B57C(void)
{
    BattleMenu_SetMode(4, Menu_ExpandListTemplate(gUnknown_08124CC8, 0));
}

// sub_0812B598 @ 0x0812B598
void sub_0812B598(void)
{
    struct MenuCursor *c = sub_08126D1C(4);
    struct C127Block *blk = C127_BLOCK;
    struct C127SortEntry *list = (struct C127SortEntry *)blk->list;
    u16 id = list[c->index].id;

    BattleMenu_DrawListPage(4, c->top);
    BattleMenu_SetMode(8, Menu_ExpandListTemplate(*(const u16 **)(Action_GetRecord(id) + 0x1C), 0));
}
