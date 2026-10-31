/* Battle menu: member lists for talk, items and summoning (cursor menus 2 and 3). */

#include "global.h"
#include "bmenu.h"

// sub_08129D08 @ 0x08129D08
void sub_08129D08(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;

    task->result = 0;
    if (blk->unk694 == 2)
    {
        BattleMenu_SetMode(3, sub_080EAF1C(Battle_GetCombatant(gUnk_030065C0[3] - 0x8000), gUnk_030065C0[1]));
        task->result = 1;
    }
}

// sub_08129D58 @ 0x08129D58
void sub_08129D58(void)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk48 = Task_Create(gUnknown_087784CC, 0xFFFF);
}

// sub_08129D78 @ 0x08129D78
void sub_08129D78(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    u16 n = 0;

    task->pad1E = n;
    sub_080EA210();
    n = BattleMenu_BuildMemberList(3);
    if (n == 0)
    {
        BattleMenu_SetMode(3, gUnknown_0812416C);
        task->pad1E = 1;
    }
    else
    {
        blk->unk4C = TextWindow_Create(1, 0, 0xF, 0xA, 1);
        blk->unk50 = TextWindow_Create(0x11, 0, 0xC, 6, 1);
        sub_081272AC();
        sub_08126928(2, 0, 1, n, n);
        BattleMenu_SetMode(4, gUnknown_08124154);
    }
}

// sub_08129DF4 @ 0x08129DF4
void sub_08129DF4(void)
{
    struct MenuCursor *c = sub_08126D1C(2);

    BattleMenu_DrawListPage(0, c->top);
    sub_081283C4(0, c->index);
}

// sub_08129E14 @ 0x08129E14
void sub_08129E14(struct Task *task)
{
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
    else if (c->state == 3)
    {
        task->pad1E = c->index;
        task->result = 1;
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
        BattleMenu_DrawListPage(0, c->top);
        sub_081283C4(0, c->index);
    }
}

// sub_08129EE4 @ 0x08129EE4
void sub_08129EE4(struct Task *task)
{
    s32 done;

    task->result = 0;
    done = BattleMsg_IsDone();
    if (done == 1)
        task->result = done;
}

// sub_08129EFC @ 0x08129EFC
void sub_08129EFC(void)
{
    BattleMsg_Close();
    sub_08128EB4();
    sub_081269B0(2);
}

// sub_08129F10 @ 0x08129F10
void sub_08129F10(void)
{
    struct C127Block *blk = C127_BLOCK;

    if (blk->unk4C != 0)
        TextWindow_Close(blk->unk4C, 0);
    if (blk->unk50 != 0)
        TextWindow_Close(blk->unk50, 0);
    sub_08128388();
}

// sub_08129F3C @ 0x08129F3C
void sub_08129F3C(struct Task *task)
{
    task->result = 0;
    if (BattleMenu_BuildMemberList(3) != 0)
        task->result = 1;
}

/* Returns the selected demon to the stock: message names the party slot it held. */
// sub_08129F5C @ 0x08129F5C
/* Finds the party slot whose member is the selected list entry. The first test is written
   before the loop (jump2 shares its compare with the loop's), and the loop is a real do/while
   entered at its body: loop-depth weighting gives order/list the priority they have. */
void sub_08129F5C(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    u16 i;
    s8 *order;
    u16 *list;
    const u16 *tmpl;

    i = 0;
    {
        struct C127GameState *gs = &gGameState;
        order = gs->order;
    }
    if (order[i] != *(u16 *)((task->pad1E << 1) + (u32)(list = blk->list)))
    {
        tmpl = gUnknown_08124182;
        goto loop;
    }
    tmpl = gUnknown_08124182;
    goto done;
    do
    {
    loop:
        i++;
        if (i > 5)
            break;
    } while (*(s8 *)((u32)i + (u32)order) != *(u16 *)((u32)list + (task->pad1E << 1)));
done:
    BattleMenu_SetMode(3, Battle_BuildNamePrependText(i, tmpl));
    Party_Remove(blk->list[task->pad1E], 0);
    Party_FixFormation();
    sub_081269B0(2);
}

// sub_08129FDC @ 0x08129FDC
void sub_08129FDC(void)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk48 = Task_Create(gUnknown_08778614, 0xFFFF);
}

// sub_08129FFC @ 0x08129FFC
void sub_08129FFC(struct Task *task, u32 arg)
{
    struct C127Block *blk = C127_BLOCK;
    u16 n = 0;

    task->pad1E = n;
    if (arg == 0)
        sub_080EA210();
    n = BattleMenu_BuildMemberList(2);
    if (n == 0)
    {
        BattleMenu_SetMode(3, gUnknown_0812439A);
        task->pad1E = 1;
    }
    else
    {
        blk->unk4C = TextWindow_Create(1, 0, 0xF, 0xA, 1);
        blk->unk50 = TextWindow_Create(0x11, 0, 0xC, 6, 1);
        sub_081272AC();
        if (n <= 4)
            sub_08126928(2, 0, 1, n, n);
        else
            sub_08126928(2, 0x10, 1, n, 5);
        if (arg == 0)
            BattleMenu_SetMode(4, gUnknown_08124364);
    }
}

// sub_0812A09C @ 0x0812A09C
void sub_0812A09C(void)
{
    struct MenuCursor *c = sub_08126D1C(2);

    BattleMenu_DrawListPage(0, c->top);
    sub_081283C4(0, c->index);
}

// sub_0812A0BC @ 0x0812A0BC
void sub_0812A0BC(struct Task *task, u32 arg)
{
    struct MenuCursor *c = sub_08126D1C(2);
    u8 old = c->index;
    u8 *sel;

    sub_08126A08(2);
    task->pad1E = 0;
    sel = &task->data.raw[0];
    *sel = 0;
    task->result = 0;
    if (gKeysNew & 2)
    {
        task->pad1E = 0x100;
        task->result = 1;
    }
    else if (c->state == 3)
    {
        task->pad1E = c->index;
        *sel = c->index;
        task->result = 1;
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
        BattleMenu_DrawListPage(0, c->top);
        sub_081283C4(0, c->index);
    }
    if (arg == 1)
    {
        Text_DrawSpriteString(gUnknown_08124364, 0, 0, 0x12, 0x59, 0xC);
        task->unk06 = 0;
    }
}

// sub_0812A1C8 @ 0x0812A1C8
void sub_0812A1C8(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct Combatant *m;
    u8 ok;

    task->pad1E = 0;
    m = Party_GetMember(blk->list[task->data.raw[0]] + 0x8000);
    ok = sub_0815B8F8(m->demonId, 1) != 0;
    if (ok == 0)
    {
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(0x6E), 0));
        task->pad1E = 0x100;
    }
}

// sub_0812A228 @ 0x0812A228
void sub_0812A228(struct Task *task)
{
    task->result = 0;
    if (BattleMenu_BuildMemberList(2) != 0)
        task->result = 1;
}

// sub_0812A248 @ 0x0812A248
void sub_0812A248(struct Task *task)
{
    sub_080F41B0(C127_BLOCK->list[task->data.raw[0]]);
    Party_FixFormation();
    sub_081269B0(2);
}

// sub_0812A274 @ 0x0812A274
void sub_0812A274(void)
{
    BattleMsg_Close();
    sub_08128EB4();
    sub_081269B0(2);
}
