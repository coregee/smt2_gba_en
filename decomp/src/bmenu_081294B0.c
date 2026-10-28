/* Battle menu: member selection lists (summon/return, talk). */

#include "global.h"
#include "bmenu.h"

// sub_081294B0 @ 0x081294B0
void sub_081294B0(struct Task *task, u32 arg)
{
    struct C127Block *blk = C127_BLOCK;
    u16 n = 0;
    u16 v;

    task->pad1E = n;
    if (Flag_Test(0xD5) && (v = gShopItemIds) == 1)
    {
        BattleMenu_SetMode(3, gUnknown_0812410A);
        task->pad1E = v;
        if (arg == 0)
            blk->unk48->data.raw[0] = 0xFF;
    }
    else if ((blk->unk694 & 1)
          && (sub_080F4504() <= Party_CountDemons() || Party_CountMembers() > 5))
    {
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(0x92), 0));
        task->pad1E = 2;
        if (arg == 0)
            blk->unk48->data.raw[0] = 0xFF;
    }
    else
    {
        if (blk->unk694 != 7)
            n = BattleMenu_BuildMemberList(7);
        else
            n = BattleMenu_BuildMemberList(9);
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
            if (n <= 4)
                sub_08126928(3, 0, 1, n, n);
            else
                sub_08126928(3, 0x10, 1, n, 5);
            BattleMenu_SetMode(4, gUnknown_081240A0);
        }
    }
}

// sub_081295D4 @ 0x081295D4
void sub_081295D4(void)
{
    struct MenuCursor *c = sub_08126D1C(3);

    BattleMenu_DrawListPage(3, c->top);
    sub_081283C4(3, c->index);
}

// sub_081295F4 @ 0x081295F4
void sub_081295F4(void)
{
    sub_080D3654(1, 0);
}

// sub_08129604 @ 0x08129604
void sub_08129604(struct Task *task, u32 arg)
{
    struct C127Block *blk = C127_BLOCK;
    struct MenuCursor *c = sub_08126D1C(3);
    u32 oldIndex = (u8)c->index;
    u16 b;
    u8 ok;
    struct Combatant *m;

    sub_08126A08(3);
    task->pad1E = 0;
    task->result = 0;
    if ((b = gKeysNew & 2) != 0)
    {
        task->pad1E = 0x100;
        task->result = 1;
        if (arg == 0)
            blk->unk48->data.raw[0] = 0xFF;
        sub_080D3688();
    }
    else if (c->state == 3)
    {
        ok = 1;
        task->result = ok;
        blk->unk692 = blk->list[c->index];
        m = Party_GetMember(blk->unk692 + 0x8000);
        task->pad1E = b;
        if (arg == 0 && !(blk->unk694 & 2) && sub_0812839C(blk->unk692) > sub_080C3100())
        {
            task->pad1E = ok;
            blk->unk48->data.raw[0] = 0xFF;
            ok = 0;
        }
        if (arg == 0 && !(blk->unk694 & 2) && Alignment_AreCompatible(0, blk->unk692) == 0)
        {
            task->pad1E = 2;
            blk->unk48->data.raw[0] = 0xFF;
            ok = 0;
        }
        if ((u16)(m->demonId - 0x16A) <= 0x11 && sub_080C5CC0() > 1)
        {
            task->pad1E = 5;
            if (arg == 0)
                blk->unk48->data.raw[0] = 0xFF;
            ok = 0;
        }
        b = ok;
        if (b == 1)
        {
            if (sub_080F4504() <= Party_CountDemons() || Party_CountMembers() > 5)
            {
                task->pad1E = 3;
            }
            else if (((u8)(b & blk->unk694)) && !sub_08129460())
            {
                task->pad1E = 4;
                if (arg == 0)
                    blk->unk48->data.raw[0] = 0xFF;
            }
        }
        sub_080D3688();
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
        BattleMenu_DrawListPage(3, c->top);
        sub_081283C4(3, c->index);
    }
}

// sub_08129838 @ 0x08129838
void sub_08129838(struct Task *task)
{
    s32 done;

    task->result = 0;
    done = BattleMsg_IsDone();
    if (done == 1)
        task->result = done;
}

// sub_08129850 @ 0x08129850
#ifdef NONMATCHING
void sub_08129850(void)
{
    switch (C127_BLOCK->unk694)
    {
    case 0:
        sub_08128EB4();
        BattleMsg_Close();
        break;
    case 1:
    case 2:
    case 3:
        break;
    }
    sub_081269B0(3);
}
#else
NAKED
void sub_08129850(void)
{
    asm_unified(
        "    push {lr}\n"
        "    ldr r0, .L08129878\n"
        "    ldr r1, .L0812987C\n"
        "    adds r0, r0, r1\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #3\n"
        "    bgt .L0812986E\n"
        "    cmp r0, #1\n"
        "    bge .L0812986E\n"
        "    cmp r0, #0\n"
        "    bne .L0812986E\n"
        "    bl sub_08128EB4\n"
        "    bl BattleMsg_Close\n"
        ".L0812986E:\n"
        "    movs r0, #3\n"
        "    bl sub_081269B0\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L08129878: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L0812987C: .4byte 0x00000694\n"
    );
}
#endif

// sub_08129880 @ 0x08129880
void sub_08129880(void)
{
    struct C127Block *blk = C127_BLOCK;

    if (blk->unk4C != 0)
        TextWindow_Close(blk->unk4C, 0);
    if (blk->unk50 != 0)
        TextWindow_Close(blk->unk50, 0);
    sub_08128388();
}

// sub_081298AC @ 0x081298AC
void sub_081298AC(void)
{
    struct C127Block *blk = C127_BLOCK;

    sub_080C8ADC(blk->unk4C = sub_080C8AAC(0, 1), 1);
    BattleMenu_SetMode(4, gUnknown_081240BC);
    sub_081269B0(3);
}
