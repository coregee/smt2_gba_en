/* Battle menu: shop-style item lists (price table at blk+0x2EC), and the after-battle
   automatic recovery. */

#include "global.h"
#include "bmenu2.h"

// sub_0812DBF0 @ 0x0812DBF0
u16 *sub_0812DBF0(void)
{
    struct C127Block *blk = C127_BLOCK;

    return blk->list;
}

/* u32 values (prices) stored after the 14 list entries. */
// BattleMenu_GetPriceList @ 0x0812DC00
u32 *BattleMenu_GetPriceList(void)
{
    struct C127Block *blk = C127_BLOCK;

    return (u32 *)((u8 *)blk + 0x2EC);
}

// sub_0812DC10 @ 0x0812DC10
u8 sub_0812DC10(void)
{
    return C127_BLOCK->unk692;
}

// sub_0812DC24 @ 0x0812DC24
void sub_0812DC24(void)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk48 = Task_Create(gUnknown_0877A310, 0xFFFF);
    blk->unk692 = 0xFE;
}

// sub_0812DC50 @ 0x0812DC50
void sub_0812DC50(void)
{
    struct C127Block *blk = C127_BLOCK;
    u16 *list = blk->list;
    u16 n;

    blk->unk4C = TextWindow_Create(1, 0, 0xF, 0xA, 1);
    blk->unk50 = TextWindow_Create(0x11, 0, 0xC, 6, 1);
    sub_081272AC();
    n = 0;
    while (*list++ != 0xFFFF)
        n++;
    if (n <= 4)
        sub_08126928(2, 0, 1, n, n);
    else
        sub_08126928(2, 0x10, 1, n, 5);
    sub_08126D1C(2)->seA = 0xFFFF;
}

// sub_0812DCE0 @ 0x0812DCE0
void sub_0812DCE0(void)
{
    struct MenuCursor *c = sub_08126D1C(2);

    BattleMenu_DrawListPage(0, c->top);
    sub_081283C4(0, c->index);
    sub_080D3654(2, *BattleMenu_GetPriceList());
}

// sub_0812DD0C @ 0x0812DD0C
void sub_0812DD0C(struct Task *task)
{
    struct MenuCursor *c = sub_08126D1C(2);
    u8 oldIndex = c->index;

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
        if (BattleMenu_GetPriceList()[c->index] > sub_080C3100())
            sub_080ECF70(0x66);
        else
            sub_080ECF70(0xE7);
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
    if (oldIndex != c->index)
    {
        sub_080D367C(BattleMenu_GetPriceList()[c->index]);
        BattleMenu_DrawListPage(0, c->top);
        sub_081283C4(0, c->index);
    }
}

// sub_0812DE10 @ 0x0812DE10
void sub_0812DE10(void)
{
    struct C127Block *blk = C127_BLOCK;

    if (blk->unk4C != 0)
        TextWindow_Close(blk->unk4C, 0);
    if (blk->unk50 != 0)
        TextWindow_Close(blk->unk50, 0);
    sub_08128388();
    sub_080D3688();
}

// sub_0812DE40 @ 0x0812DE40
void sub_0812DE40(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;

    if (task->pad1E == 0x100)
        blk->unk692 = 0xFF;
    else
        blk->unk692 = blk->list[task->pad1E];
    sub_081269B0(2);
}

// sub_0812DE88 @ 0x0812DE88
void sub_0812DE88(void)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk48 = Task_Create(gUnknown_0877A3B4, 0xFFFF);
    blk->unk692 = 0xFE;
}

// sub_0812DEB4 @ 0x0812DEB4
void sub_0812DEB4(void)
{
    struct MenuCursor *c = sub_08126D1C(2);

    BattleMenu_DrawListPage(0, c->top);
    sub_081283C4(0, c->index);
}

// sub_0812DED4 @ 0x0812DED4
void sub_0812DED4(struct Task *task)
{
    struct MenuCursor *c = sub_08126D1C(2);
    u8 oldIndex = c->index;

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
    if (oldIndex != c->index)
    {
        BattleMenu_GetPriceList();
        BattleMenu_DrawListPage(0, c->top);
        sub_081283C4(0, c->index);
    }
}

// sub_0812DFA8 @ 0x0812DFA8
void sub_0812DFA8(void)
{
    struct C127Block *blk = C127_BLOCK;

    if (blk->unk4C != 0)
        TextWindow_Close(blk->unk4C, 0);
    if (blk->unk50 != 0)
        TextWindow_Close(blk->unk50, 0);
    sub_08128388();
}

// sub_0812DFD4 @ 0x0812DFD4
void sub_0812DFD4(void)
{
    struct C127Block *blk = C127_BLOCK;
    u16 *list = blk->list;
    u16 n;

    blk->unk4C = TextWindow_Create(1, 0, 0xF, 0xA, 1);
    blk->unk50 = TextWindow_Create(0x11, 0, 0xC, 6, 1);
    sub_081272AC();
    n = 0;
    while (*list++ != 0xFFFF)
        n++;
    if (n <= 4)
        sub_08126928(2, 0, 1, n, n);
    else
        sub_08126928(2, 0x10, 1, n, 5);
    sub_08126D1C(2);
}

// sub_0812E05C @ 0x0812E05C
void sub_0812E05C(void)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk48 = Task_Create(gUnknown_0877A458, 0xFFFF);
    blk->unk692 = 0xFE;
}

/* The chosen entry, or 0xFF00 | code (0xFE nothing chosen yet, 0xFF cancelled). */
// sub_0812E088 @ 0x0812E088
u16 sub_0812E088(void)
{
    struct C127Block *blk = C127_BLOCK;
    u8 *sel = &blk->unk692;

    if (*sel > 0xFD)
        return *sel | 0xFF00;
    return blk->list[*sel];
}

// sub_0812E0BC @ 0x0812E0BC
void sub_0812E0BC(void)
{
    struct C127Block *blk = C127_BLOCK;
    u16 *list = blk->list;
    u16 n;

    blk->unk4C = TextWindow_Create(1, 0, 0xF, 0xA, 1);
    blk->unk50 = 0;
    sub_081272AC();
    n = 0;
    while (*list++ != 0xFFFF)
        n++;
    if (n <= 4)
        sub_08126928(2, 0, 1, n, n);
    else
        sub_08126928(2, 0x10, 1, n, 5);
}

// sub_0812E134 @ 0x0812E134
void sub_0812E134(void)
{
    BattleMenu_DrawListPage(1, sub_08126D1C(2)->top);
}

// sub_0812E148 @ 0x0812E148
void sub_0812E148(struct Task *task)
{
    struct MenuCursor *c = sub_08126D1C(2);
    u8 oldIndex = c->index;

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
    if (oldIndex != c->index)
        BattleMenu_DrawListPage(1, c->top);
}

// sub_0812E210 @ 0x0812E210
void sub_0812E210(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;

    if (task->pad1E == 0x100)
        blk->unk692 = 0xFF;
    else
        blk->unk692 = task->pad1E;
    sub_081269B0(2);
}

/* After-battle recovery: cure ailments, then heal HP, using party skills or items. */
// BattleMenu_AutoRecoverStep @ 0x0812E244
void BattleMenu_AutoRecoverStep(struct Task *task)
{
    u8 *st = gUnk_030065CC;
    s16 i;

    task->result = 0;
    switch (st[1])
    {
    case 0:
        for (i = 0; i < 4; i++)
        {
            if (Combatant_IsUsed(i))
                Party_BuildSkillList(i);
        }
        st[1] = 1;
        break;
    case 1:
        if (Party_AutoRecover())
        {
            sub_080C84A0();
            BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(0xD7), 0));
            sub_080ECF70(0xE7);
        }
        else
            BattleMenu_SetMode(3, Menu_ExpandListTemplate(gUnknown_08124534, 0));
        st[1] = 2;
        break;
    case 2:
        if (BattleMsg_IsDone() == 1)
        {
            BattleMenu_Reset();
            BattleMsg_Close();
            st[1] = 3;
        }
        break;
    case 3:
        task->result = 1;
        break;
    }
}

// Party_AutoRecover @ 0x0812E2FC
s16 Party_AutoRecover(void)
{
    s32 who;

    gUnk_030020B4 = 0;
    while ((who = Party_FindAilingMember()) >= 0 && sub_0812E4C0(who))
        ;
    while ((who = Party_FindHurtMember()) >= 0 && sub_0812E400(who))
        ;
    return gUnk_030020B4;
}

/* First party member (0-15) alive with HP below maximum, or -1. */
// Party_FindHurtMember @ 0x0812E334
s32 Party_FindHurtMember(void)
{
    struct Combatant *c = gGameState.members;
    s32 i;

    for (i = 0; i <= 15; i++, c++)
    {
        if (Combatant_IsInParty(i) && !(c->flags & 0x8000) && c->hp < c->maxHp)
            return i;
    }
    return -1;
}

/* Same for MP. */
// Party_FindMpShortMember @ 0x0812E37C
s32 Party_FindMpShortMember(void)
{
    struct Combatant *c = gGameState.members;
    s32 i;

    for (i = 0; i <= 15; i++, c++)
    {
        if (Combatant_IsInParty(i) && !(c->flags & 0x8000) && c->mp < c->maxMp)
            return i;
    }
    return -1;
}

/* First party member with a curable ailment (flags & 0xB3FE), or -1. */
// Party_FindAilingMember @ 0x0812E3C4
s32 Party_FindAilingMember(void)
{
    struct Combatant *c = gGameState.members;
    s32 i;

    for (i = 0; i <= 15; i++, c++)
    {
        if (Combatant_IsInParty(i) && (c->flags & 0xB3FE))
            return i;
    }
    return -1;
}

/* Tries a curing item (0x0877A4FC list), then a healing skill of a party member
   (0x0877A502 list). The loops are spelled with goto: the original's are not
   treated as loops by the compiler (no loop-invariant hoisting). */
// sub_0812E400 @ 0x0812E400
s32 sub_0812E400(s32 who)
{
    const u8 *p;
    s32 r;

    if (!(u16)sub_080C2C30())
    {
        p = gUnknown_0877A4FC;
        goto check1;
    next1:
        if (sub_080C10B4(*p))
            goto useItem;
        p++;
    check1:
        if (*p != 0xFF)
            goto next1;
    }
    if (!sub_080F31E0())
        goto start2;
    goto none;
useItem:
    Party_UseItemOn(who, 0, *p);
    return 1;
useSkill:
    Party_CastSkillOn(who, r, *p);
    return 1;
start2:
    p = gUnknown_0877A502;
    goto check2;
next2:
    r = Party_FindSkillCaster(*p);
    if (r >= 0)
        goto useSkill;
    p++;
check2:
    if (*p != 0xFF)
        goto next2;
none:
    return 0;
}
