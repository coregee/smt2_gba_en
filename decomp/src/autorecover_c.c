/* Battle menu: demon/target selection list task, and the message window cursor blink. */

#include "global.h"
#include "bmenu2.h"

// sub_0812ED54 @ 0x0812ED54
void sub_0812ED54(void)
{
    sub_081269B0(2);
}

// sub_0812ED60 @ 0x0812ED60
void sub_0812ED60(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk11A2 = blk->list[task->pad1E];
    sub_081269B0(2);
}

// sub_0812ED8C @ 0x0812ED8C
void sub_0812ED8C(struct Task *task)
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
    switch (task->unk06)
    {
    case 0:
        break;
    case 1:
        sub_080EA210();
        BattleMenu_SetMode(4, Menu_ExpandListTemplate(gUnknown_08124D72, 0));
        break;
    }
}

// sub_0812EE28 @ 0x0812EE28
void sub_0812EE28(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;

    if (blk->unk4C != 0)
        TextWindow_Close(blk->unk4C, 0);
    if (blk->unk50 != 0)
        TextWindow_Close(blk->unk50, 0);
    sub_08128388();
    switch (task->unk06)
    {
    case 0:
        break;
    case 1:
        BattleMsg_Close();
        break;
    }
}

// sub_0812EE64 @ 0x0812EE64
void sub_0812EE64(struct Task *task)
{
    if (task->unk06 == 0)
    {
        sub_080C700C();
        sub_080C7430();
        sub_080C7648();
    }
    else if (task->unk06 == 1)
        Task_Signal(Task_GetParent(task));
}

// sub_0812EE8C @ 0x0812EE8C
struct Task *sub_0812EE8C(u32 mode, struct Task *parent)
{
    u32 id = 0xFFFF;
    struct Task *t;

    if (parent != NULL)
        id = parent->id;
    t = Task_Create(gUnknown_0877A580, id);
    t->unk06 = mode;
    if (mode == 0)
    {
        sub_080C6FF0();
        sub_080C7414();
        sub_080C762C();
    }
    return t;
}

// sub_0812EEC4 @ 0x0812EEC4
u16 sub_0812EEC4(void)
{
    return C127_BLOCK->unk11A2;
}

/* Stores the chosen entry (blk->unk692) and the task result for the acting member. */
// sub_0812EED8 @ 0x0812EED8
void sub_0812EED8(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    u8 sel = blk->unk692;

    switch (blk->unk694)
    {
    case 0:
        blk->unkEF0[0] = sel;
        blk->unkF10[0] = task->pad1E;
        break;
    case 1:
    case 3:
        blk->unkEF0[gGameState.order[blk->unkF66]] = sel;
        blk->unkF10[gGameState.order[blk->unkF66]] = task->pad1E;
        break;
    case 2:
        blk->unkEF0[0] = sel;
        blk->unkF10[0] = task->pad1E;
        break;
    }
    task->pad1E = 0;
}

// sub_0812EF80 @ 0x0812EF80
void sub_0812EF80(void)
{
    sub_081269B0(3);
}

// sub_0812EF8C @ 0x0812EF8C
struct Task *sub_0812EF8C(struct Task *parent)
{
    struct C127Block *blk = C127_BLOCK;
    u32 id = 0xFFFF;

    if (parent != NULL)
        id = parent->id;
    if (blk->unk48->data.raw[0] == 0)
        blk->unk694 = 0;
    else
        blk->unk694 = 1;
    return Task_Create(gUnknown_0877A774, id);
}

/* Message window: toggles the cursor (0x0203DB52) every 30 frames while 0x0203DB56 is set. */
// MsgWindow_BlinkCursor @ 0x0812EFD8
void MsgWindow_BlinkCursor(void)
{
    if (*(s16 *)&gUnk_0203DB56 != 0 && --gUnk_0203DB54 == 0)
    {
        gUnk_0203DB54 = 30;
        gUnk_0203DB52 ^= 1;
    }
}
