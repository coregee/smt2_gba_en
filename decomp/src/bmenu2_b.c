/* Battle command menu, continued: skill targets, party/demon selection lists. */

#include "global.h"
#include "bmenu2.h"

// sub_0812C9BC @ 0x0812C9BC
void sub_0812C9BC(struct Task *task)
{
    u8 *rec = sub_080BF5C0(task->data.raw[8]);

    task->pad1E = 0;
    if (rec[2] == 0x80 || rec[2] == 0x82 || rec[2] == 0x83)
        task->pad1E = 1;
    else if (rec[2] != 0xF && rec[2] != 0xFF)
        task->pad1E = 2;
}

// sub_0812C9F0 @ 0x0812C9F0
void sub_0812C9F0(struct Task *task)
{
    task->data.w[1] = (task->pad1E << 16) + task->data.raw[8];
}

// sub_0812CA00 @ 0x0812CA00
void sub_0812CA00(struct Task *task)
{
    u8 *rec = sub_080BF5C0(task->data.raw[8]);
    u16 n = 0;
    struct C127Block *blk = C127_BLOCK;

    task->pad1E = n;
    switch (rec[2])
    {
    case 0x80:
        if (blk->unk48->data.raw[0] == 1)
            n = BattleMenu_BuildMemberList(1);
        else
            n = BattleMenu_BuildMemberList(0);
        break;
    case 0x82:
        if (blk->unk48->data.raw[0] == 1)
            n = BattleMenu_BuildMemberList(1);
        else
            n = BattleMenu_BuildMemberList(0);
        break;
    case 0x83:
        n = BattleMenu_BuildMemberList(6);
        break;
    }
    if (n != 0)
    {
        Task_End((struct Task *)blk->unk4C);
        Task_End((struct Task *)blk->unk50);
        blk->unk4C = TextWindow_Create(1, 0, 0xF, 0xA, 1);
        blk->unk50 = TextWindow_Create(0x11, 0, 0xC, 6, 1);
        sub_081272AC();
        if (n <= 4)
            sub_08126928(4, 0, 1, n, n);
        else
            sub_08126928(4, 0x10, 1, n, 5);
        task->pad1E = 1;
        sub_080EA210();
        BattleMenu_SetMode(4, Menu_ExpandListTemplate(gUnknown_08124D72, 0));
    }
}

// sub_0812CADC @ 0x0812CADC
void sub_0812CADC(void)
{
    struct MenuCursor *c = sub_08126D1C(4);

    BattleMenu_DrawListPage(0, c->top);
    sub_081283C4(0, c->index);
}

// sub_0812CAFC @ 0x0812CAFC
void sub_0812CAFC(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct MenuCursor *c = sub_08126D1C(4);
    u8 oldIndex = c->index;

    sub_08126A08(4);
    task->pad1E = 0;
    task->result = 0;
    if (gKeysNew & 2)
    {
        task->pad1E = 0x100;
        task->result = 1;
    }
    else if (c->state == 3)
    {
        task->pad1E = blk->list[c->index];
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
    if (oldIndex != c->index)
    {
        BattleMenu_DrawListPage(0, c->top);
        sub_081283C4(0, c->index);
    }
}

// sub_0812CBDC @ 0x0812CBDC
void sub_0812CBDC(void)
{
    struct C127Block *blk = C127_BLOCK;

    if (blk->unk4C != 0)
        TextWindow_Close(blk->unk4C, 0);
    if (blk->unk50 != 0)
        TextWindow_Close(blk->unk50, 0);
    sub_081269B0(4);
    BattleMenu_Reset();
    sub_08128388();
}

// sub_0812CC10 @ 0x0812CC10
void sub_0812CC10(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    s16 r = sub_080E6E08();
    u16 who = gGameState.order[blk->unk691];

    task->result = 0;
    task->pad1E = 0;
    switch (r)
    {
    case 3:
        task->result = 1;
        task->pad1E = sub_080EDA64(who);
        break;
    case 2:
        task->pad1E = 0x100;
        task->result = 1;
        break;
    }
}

// sub_0812CC70 @ 0x0812CC70
void sub_0812CC70(u16 index)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk48 = Task_Create(gUnknown_08779CA4, 0xFFFF);
    blk->unk694 = index;
}

// sub_0812CCA0 @ 0x0812CCA0
void sub_0812CCA0(void)
{
    struct C127Block *blk = C127_BLOCK;
    u16 n;

    blk->unk4C = TextWindow_Create(1, 0, 0xF, 0xA, 1);
    blk->unk50 = TextWindow_Create(0x11, 0, 0xC, 6, 1);
    sub_081272AC();
    n = BattleMenu_BuildMemberList(0);
    if (n <= 4)
        sub_08126928(2, 0, 1, n, n);
    else
        sub_08126928(2, 0x10, 1, n, 5);
    MenuCursor_SetIndex(2, blk->unk694);
    sub_080EA210();
    BattleMenu_SetMode(4, gUnknown_08123DF0);
}

// sub_0812CD24 @ 0x0812CD24
void sub_0812CD24(void)
{
    struct MenuCursor *c = sub_08126D1C(2);

    BattleMenu_DrawListPage(0, c->top);
    sub_081283C4(0, c->index);
}

// sub_0812CD44 @ 0x0812CD44
void sub_0812CD44(struct Task *task)
{
    struct MenuCursor *c = sub_08126D1C(2);
    u8 oldIndex = c->index;
    u16 cancel;

    sub_08126A08(2);
    task->pad1E = 0;
    task->result = 0;
    if ((cancel = gKeysNew & 2) != 0)
    {
        task->pad1E = 0x100;
        task->result = 1;
    }
    else if (c->state == 3)
    {
        task->pad1E = cancel;
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
    if (oldIndex != c->index)
    {
        BattleMenu_DrawListPage(0, c->top);
        sub_081283C4(0, c->index);
    }
}

// sub_0812CE18 @ 0x0812CE18
void sub_0812CE18(void)
{
    sub_08128B84(1);
    sub_081269B0(2);
}

// sub_0812CE2C @ 0x0812CE2C
void sub_0812CE2C(void)
{
    struct C127Block *blk = C127_BLOCK;

    if (blk->unk4C != 0)
        TextWindow_Close(blk->unk4C, 0);
    if (blk->unk50 != 0)
        TextWindow_Close(blk->unk50, 0);
    sub_08128388();
    BattleMsg_Close();
}

// sub_0812CE5C @ 0x0812CE5C
void sub_0812CE5C(void)
{
    sub_080CAFD0(0, sub_08126D1C(2)->index);
    sub_081269B0(2);
}

// sub_0812CE78 @ 0x0812CE78
void sub_0812CE78(void)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk48 = Task_Create(gUnknown_08779DB8, 0xFFFF);
    blk->unk50 = 0;
    blk->unk4C = 0;
    blk->unk691 = 1;
}

// sub_0812CEAC @ 0x0812CEAC
void sub_0812CEAC(void)
{
    struct C127Block *blk = C127_BLOCK;

    BattleMenu_SetMode(4, gUnknown_08124198);
    blk->unk4C = sub_080C8AAC(0, blk->unk691);
    sub_080C8ADC(blk->unk4C, 1);
    blk->unk50 = 0;
}
