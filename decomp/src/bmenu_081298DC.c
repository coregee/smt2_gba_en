/* Battle menu: party slot selection, demon summon/return. */

#include "global.h"
#include "bmenu.h"

// sub_081298DC @ 0x081298DC
void sub_081298DC(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    u8 bad;

    task->pad1E = 0;
    task->result = 0;
    if (gKeysNew & 2)
    {
        task->pad1E = 0x100;
        task->result = 1;
        sub_080C8ADC(blk->unk4C, 0);
        sub_080ECF70(0x66);
    }
    else if (gKeysNew & 3)
    {
        bad = 0;
        task->pad1E = sub_080C8AF4(blk->unk4C);
        if (gGameState.order[task->pad1E] == -1)
        {
            if ((blk->unk694 & 1) && !sub_08129460())
                bad = 1;
            if (bad == 0)
            {
                task->result = 1;
                sub_080C8ADC(blk->unk4C, 0);
                sub_080ECF70(0x65);
                return;
            }
        }
        sub_080ECF70(0x66);
    }
    else if (gKeysNew & 0xF0)
    {
        sub_080ECF70(0x64);
    }
}

// sub_08129994 @ 0x08129994
void sub_08129994(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;

    task->result = 0;
    if (blk->unk694 == 0 && BattleMenu_BuildMemberList(7) != 0)
        task->result = 1;
}

// sub_081299C8 @ 0x081299C8
void sub_081299C8(struct Task *task, u32 arg)
{
    struct C127Block *blk = C127_BLOCK;
    s32 slot = gGameState.order[task->pad1E];
    u8 m;

    switch (blk->unk694)
    {
    case 0:
        if (slot != -1)
            Party_Remove(slot, 0);
        m = blk->unk692;
        Money_Add(-sub_0812839C(m));
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(0xE9), m));
        Party_AddAt(m, task->pad1E);
        Party_FixFormation();
        Party_BuildMemberNameTiles();
        Hud_LoadAllMemberFaces();
        task->pad1E = 1;
        break;
    case 1:
    case 3:
    case 7:
        m = blk->unk692;
        blk->unkEF0[gGameState.order[blk->unkF66]] = m;
        blk->unkF10[gGameState.order[blk->unkF66]] = task->pad1E;
        task->pad1E = 0;
        break;
    case 2:
        if (slot != -1)
            Party_Remove(slot, 0);
        m = blk->unk692;
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(0xE9), m));
        Party_AddAt(m, task->pad1E);
        Party_FixFormation();
        Party_BuildMemberNameTiles();
        Hud_LoadAllMemberFaces();
        task->pad1E = 1;
        break;
    default:
        task->pad1E = 0;
        break;
    }
    if (arg == 0)
        blk->unk48->data.raw[0] = 1;
}

// sub_08129B34 @ 0x08129B34
void sub_08129B34(struct Task *task, const u16 *msg)
{
    BattleMenu_SetMode(3, msg);
}

// sub_08129B40 @ 0x08129B40
void sub_08129B40(struct Task *task, const u16 *tmpl)
{
    BattleMenu_SetMode(3, Menu_ExpandListTemplate(tmpl, 0));
}

// sub_08129B58 @ 0x08129B58
void sub_08129B58(struct Task *task, u16 id)
{
    BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(id), 0));
}

// sub_08129B74 @ 0x08129B74
void sub_08129B74(struct Task *task, u32 arg)
{
    struct C127Block *blk = C127_BLOCK;
    u16 n = BattleMenu_BuildMemberList(3);

    if (n == 0)
    {
        BattleMenu_SetMode(3, gUnknown_081240F0);
        task->pad1E = 1;
        if (arg == 0)
            blk->unk48->data.raw[0] = 0xFF;
    }
    else
    {
        blk->unk4C = TextWindow_Create(1, 0, 0xF, 0xA, 1);
        blk->unk50 = TextWindow_Create(0x11, 0, 0xC, 6, 1);
        sub_081272AC();
        sub_08126928(4, 0, 1, n, n);
        BattleMenu_SetMode(4, Menu_ExpandListTemplate(Battle_GetMessage(0x6A), 0));
    }
}

// sub_08129C00 @ 0x08129C00
void sub_08129C00(void)
{
    struct MenuCursor *c = sub_08126D1C(4);

    BattleMenu_DrawListPage(3, c->top);
    sub_081283C4(3, c->index);
}

// sub_08129C20 @ 0x08129C20
void sub_08129C20(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct MenuCursor *c = sub_08126D1C(4);
    u32 old = (u8)c->index;
    u16 v;
    u8 i;

    sub_08126A08(4);
    task->pad1E = 0;
    task->result = 0;
    if (gKeysNew & 2)
    {
        task->pad1E = 0x100;
        task->result = 1;
        sub_080ECF70(0x66);
        sub_081269B0(4);
    }
    else if (c->state == 3)
    {
        v = blk->list[c->index];
        for (i = 0; i < 6 && gGameState.order[i] != v; i++)
            ;
        task->pad1E = i;
        task->result = 1;
        sub_080ECF70(0x65);
        sub_081269B0(4);
    }
    Sprite_Draw(gUnknown_08000EA4, 0, 0, 1, 0, 0xC, c->onScreen * 13 + 6);
    if ((u16)old != c->index)
    {
        BattleMenu_DrawListPage(3, c->top);
        sub_081283C4(3, c->index);
    }
}
