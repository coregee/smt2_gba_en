/* Battle command menus: target selection, command dispatch. */

#include "global.h"
#include "battledisp.h"

// sub_080E6408 @ 0x080E6408
void sub_080E6408(struct Task *t)
{
    struct C15cBattle *b = BB;
    struct MenuCursor *c;

    sub_08126A08(0);
    c = sub_08126D1C(0);
    t->result = 0;
    if (c->state == 3)
    {
        t->result = 1;
        b->unk690 = c->column;
    }
    Sprite_Draw(gUnknown_08000868, 0, 0, 0, 0, gUnknown_086BE5FC[c->column], 0x4A);
}

// sub_080E6468 @ 0x080E6468
/* Checks the chosen command of the acting member; shows why when it cannot be used. */
void sub_080E6468(void)
{
    struct C15cBattle *b = BB;
    u8 cmd;
    s32 msg;

    b->unk1120 = 0;
    b->phase = 0;
    b->unk97E = 0;
    cmd = sub_080C35E4(GS->order[b->unkF66]);
    if (Battle_CanUseCommand(GS->order[b->unkF66], cmd, &msg))
    {
        switch (cmd)
        {
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 10:
        case 11:
            break;
        case 9:
        case 12:
        default:
            b->substate = 3;
            break;
        }
    }
    else
    {
        b->unk1120 = 1;
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(msg), GS->order[b->unkF66]));
    }
}

// sub_080E6550 @ 0x080E6550
void sub_080E6550(struct Task *t)
{
    struct C15cBattle *b = BB;
    u8 cmd;

    t->result = 0;
    if (b->substate != 3)
    {
        cmd = sub_080C35E4(GS->order[b->unkF66]);
        if (b->unk1120 == 1)
            cmd = 13;
        cmd -= 4;
        gUnknown_086BE654[cmd]();
        if (b->substate == 0)
            t->result = 1;
    }
    else
    {
        sub_080F2F94((s16 *)&b->unkECE, &b->unkF66);
        if (b->unkF66 > 5)
        {
            b->unkF64 = 0;
            b->substate = 4;
        }
        else
        {
            b->substate = 0;
        }
        t->result = 1;
    }
}

// sub_080E6610 @ 0x080E6610
void sub_080E6610(void)
{
    struct C15cBattle *b = BB;
    s16 r;
    u16 v;

    if (sub_080EF5FC(Party_GetMember(b->unkF66), GS->order[b->unkF66]) == 0x8000)
        v = 3;
    else
        v = sub_080E6E08();
    r = v;
    if (r == 3)
        b->substate = 3;
    if (r == 2)
        b->substate = 0;
}

// sub_080E6678 @ 0x080E6678
void sub_080E6678(void)
{
    struct C15cBattle *b = BB;
    s16 r;
    u16 v;

    if (sub_080EF5FC(Party_GetMember(b->unkF66), GS->order[b->unkF66]) == 0x8000)
        v = 3;
    else
        v = sub_080E6E08();
    r = v;
    if (r == 3)
        b->substate = 3;
    if (r == 2)
        b->substate = 0;
}

// sub_080E66E0 @ 0x080E66E0
void sub_080E66E0(void)
{
    struct C15cBattle *b = BB;

    b->substate = 3;
}

// sub_080E66F4 @ 0x080E66F4
void sub_080E66F4(void)
{
    struct C15cBattle *b = BB;
    s16 r = sub_080E6E08();

    if (r == 3)
        b->substate = 3;
    if (r == 2)
        b->substate = 0;
}

// sub_080E6724 @ 0x080E6724
void sub_080E6724(void)
{
    struct C15cBattle *b = BB;

    b->substate = 3;
}

// sub_080E6738 @ 0x080E6738
void sub_080E6738(void)
{
    struct C15cBattle *b = BB;

    if (BattleMsg_IsDone() == 1)
        b->substate = 0;
}

// sub_080E6760 @ 0x080E6760
/* The COMP submenu of the battle command menu (driven by b->phase). */
void sub_080E6760(void)
{
    struct C15cBattle *b = BB;
    struct MenuCursor *c;
    u16 prev;
    u8 item;
    u8 flags;

    switch (b->phase)
    {
    case 0:
        if (Flag_Test(0xE5))
        {
            flags = 0;
            sub_08126D50(5, 0);
            sub_08126928(2, 1, 1, 3, 3);
            b->unk692 = 1;
        }
        else
        {
            flags = 0;
            sub_08126D50(6, 0);
            sub_08126928(2, 1, 1, 2, 2);
            b->unk692 = 0;
        }
        b->unk1121 = flags;
        gUnk_03000030 = 0xF0;
        gUnk_03000031 = 0xB0;
        gUnk_03000035 = 0x18;
        gUnk_03000034 = 0x58;
        sub_080C7AE0();
        BattleMenu_SetMode(3, gUnknown_0812326A);
        BattleMsg_SetDone(1);
        b->phase = 1;
        break;
    case 1:
        if (sub_080C7AF0() != 2)
            b->phase = 2;
        break;
    case 2:
        c = sub_08126D1C(2);
        prev = c->row;
        sub_08126A08(2);
        item = gUnknown_086BE67C[b->unk692][c->row];
        b->unkF62 = 0;
        if (c->state == 4)
        {
            b->phase = 6;
            sub_080C7ACC();
        }
        else if (c->state == 3)
        {
            b->phase = item;
            b->unk97E = 0;
            gUnk_03000031 = 0xF0;
            sub_080C7ACC();
        }
        else if (c->state == 6)
        {
            if (b->msg.mode == 4)
            {
                BattleMenu_SetMode(3, Battle_BuildActorPrompt(b->unkF66));
                BattleMsg_SetDone(1);
            }
            else
            {
                BattleMenu_SetMode(4, gUnknown_086BE684[item]);
            }
        }
        else if (prev != c->row && b->msg.mode == 4)
        {
            BattleMenu_SetMode(4, gUnknown_086BE684[item]);
        }
        Sprite_Draw(gUnknown_080008B0, 0, 0, 0, 0, 0xB6, gUnknown_086BE606[c->row]);
        break;
    case 3:
        if (sub_080C7AF0() == 1)
            break;
        switch (sub_080F332C(0))
        {
        case 1:
            b->phase = 8;
            sub_080C7ACC();
            break;
        case 2:
            b->phase = 0;
            break;
        case 3:
            b->phase = 0;
            break;
        }
        break;
    case 4:
        if (sub_080F33E8())
            b->phase = 0;
        break;
    case 5:
        if (sub_080C7AF0() == 1)
            break;
        if (sub_080F3398())
            b->phase = 0;
        break;
    case 6:
        sub_081269B0(2);
        b->phase = 7;
        gUnk_03000031 = 0xF0;
        break;
    case 7:
        if (sub_080C7AF0() == 1)
            break;
        b->substate = 0;
        b->phase = 0;
        break;
    case 8:
        sub_081269B0(2);
        b->phase = 9;
        gUnk_03000031 = 0xF0;
        break;
    case 9:
        if (sub_080C7AF0() == 1)
            break;
        b->substate = 3;
        b->phase = 0;
        break;
    }
}

// sub_080E6A7C @ 0x080E6A7C
/* Skill selection for the acting member. */
void sub_080E6A7C(void)
{
    struct C15cBattle *b = BB;
    u32 r;
    u32 hi;
    u8 skill;

    switch (b->phase)
    {
    case 0:
        sub_0812C490(1, b->unkF66);
        b->phase = 1;
        break;
    case 1:
        r = sub_0812C4D4();
        if (r == -1)
            break;
        hi = r & 0xFFFF0000;
        if (hi == 0xFFFE0000)
        {
            b->phase = 3;
            break;
        }
        skill = r;
        Combatant_SetChosenSkill(GS->order[b->unkF66], skill);
        b->unkF30[GS->order[b->unkF66]] = hi >> 16;
        b->phase = 2;
        if (skill == 0x3E)
        {
            b->phase = 5;
            sub_081293F8(3);
        }
        else if (skill == 0x3F)
        {
            b->phase = 5;
            sub_081293F8(7);
        }
        else
        {
            b->phase = 2;
        }
        break;
    case 5:
        {
            u8 res = sub_08129440();

            if (res == 0)
                break;
            if (res == 1)
                b->phase = 2;
            else if (res == 0xFF)
                b->phase = 3;
        }
        break;
    case 2:
        b->phase = 0;
        b->substate = 3;
        break;
    case 3:
        b->substate = 0;
        b->phase = 0;
        break;
    }
}

// sub_080E6BE4 @ 0x080E6BE4
/* Item selection for the acting member. */
void sub_080E6BE4(void)
{
    struct C15cBattle *b = BB;
    s16 *phase = &b->phase;
    u32 r;
    u32 hi;

    switch (*phase)
    {
    case 0:
        sub_0812B194(1, 0);
        *phase = 1;
        break;
    case 1:
        r = sub_0812B1D4();
        if (r == -1)
            break;
        hi = r & 0xFFFF0000;
        if (hi == 0xFFFE0000)
        {
            *phase = 3;
        }
        else
        {
            Combatant_SetChosenSkill(GS->order[b->unkF66], r);
            b->unkF30[GS->order[b->unkF66]] = hi >> 16;
            *phase = 2;
        }
        sub_080EA210();
        break;
    case 2:
        *phase = 0;
        b->substate = 3;
        break;
    case 3:
        b->substate = 0;
        *phase = 0;
        break;
    }
}

// sub_080E6CCC @ 0x080E6CCC
/* Magic selection for the acting member. */
void sub_080E6CCC(void)
{
    struct C15cBattle *b = BB;
    s16 *phase = &b->phase;
    u32 r;
    u32 hi;

    switch (*phase)
    {
    case 0:
        sub_0812C490(2, b->unkF66);
        *phase = 1;
        break;
    case 1:
        r = sub_0812C4D4();
        if (r == -1)
            break;
        hi = r & 0xFFFF0000;
        if (hi == 0xFFFE0000)
        {
            *phase = 3;
        }
        else
        {
            Combatant_SetChosenSkill(GS->order[b->unkF66], r);
            b->unkF30[GS->order[b->unkF66]] = hi >> 16;
            *phase = 2;
        }
        sub_080EA210();
        break;
    case 2:
        *phase = 0;
        b->substate = 3;
        break;
    case 3:
        b->substate = 0;
        *phase = 0;
        break;
    }
}

// sub_080E6DBC @ 0x080E6DBC
/* Shows the enemy-group cursor over group n (1 or 2; 0 = only reset the portrait). */
void sub_080E6DBC(u16 n)
{
    struct C15cBattle *b = BB;
    struct C15cPortrait *p = &b->portrait;

    sub_080EC9AC(0xD2, 0, 0xFFFF, 0);
    if (n != 0)
        b->unk695 = n - 1;
    p->y = 0x30;
    p->x = gUnknown_086BF72C[n];
}

// sub_080E6E08 @ 0x080E6E08
/* Chooses the target enemy group with left/right. Returns 2 when cancelled, 3 when done. */
s16 sub_080E6E08(void)
{
    struct C15cBattle *b = BB;
    struct C15cPortrait *p = &b->portrait;
    s16 who = b->unkECE;
    u16 right;

    switch (b->unk97E)
    {
    case 0:
        if (sub_080F3060() && Battle_IsTwoSided())
        {
            BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(0x149), 0));
            BattleMsg_SetDone(1);
            sub_080E6DBC(1);
            gUnk_03000050 = 20;
            b->unk97E = 1;
        }
        else
        {
            b->unk97E = 3;
        }
        break;
    case 4:
        if (gUnk_03000050 != 0)
            gUnk_03000050--;
        else
            b->unk97E = 1;
        break;
    case 1:
        right = gKeysNew & 0x10;
        if (right)
        {
            if (b->unk695 != 1)
            {
                b->unk695 = 1;
                p->x = gUnknown_086BF72C[2];
                sub_080ECF70(0x64);
            }
        }
        else if (gKeysNew & 0x20)
        {
            if (b->unk695 != 0)
            {
                b->unk695 = 0;
                p->x = gUnknown_086BF72C[1];
                sub_080ECF70(0x64);
            }
        }
        else if (gKeysNew & 1)
        {
            {
                s16 target = b->unk695 * 4 + 16;

                sub_080EDA4C(who, target);
            }
            sub_080ECF70(0x65);
            sub_080ECB38();
            b->unk97E = 3;
        }
        else if (gKeysNew & 2)
        {
            sub_080ECF70(0x66);
            sub_080ECB38();
            b->unk97E = 2;
        }
        break;
    case 2:
        b->unk97E = 0;
        return 2;
    case 3:
        b->unk97E = 0;
        return 3;
    }
    return 0;
}

// sub_080E6FA0 @ 0x080E6FA0
/* As sub_080E6E08, without the prompt. */
s16 sub_080E6FA0(void)
{
    struct C15cBattle *b = BB;
    struct C15cPortrait *p = &b->portrait;
    s16 who = b->unkECE;
    u16 right;

    switch (b->unk97E)
    {
    case 0:
        if (sub_080F3060() && Battle_IsTwoSided())
        {
            sub_080E6DBC(1);
            gUnk_03000051 = 20;
            b->unk97E = 1;
        }
        else
        {
            b->unk97E = 3;
        }
        break;
    case 4:
        if (gUnk_03000051 != 0)
            gUnk_03000051--;
        else
            b->unk97E = 1;
        break;
    case 1:
        right = gKeysNew & 0x10;
        if (right)
        {
            if (b->unk695 != 1)
            {
                b->unk695 = 1;
                p->x = gUnknown_086BF72C[2];
                sub_080ECF70(0x64);
            }
        }
        else if (gKeysNew & 0x20)
        {
            if (b->unk695 != 0)
            {
                b->unk695 = 0;
                p->x = gUnknown_086BF72C[1];
                sub_080ECF70(0x64);
            }
        }
        else if (gKeysNew & 1)
        {
            {
                s16 target = b->unk695 * 4 + 16;

                sub_080EDA4C(who, target);
            }
            sub_080ECF70(0x65);
            sub_080ECB38();
            b->unk97E = 3;
        }
        else if (gKeysNew & 2)
        {
            sub_080ECF70(0x66);
            sub_080ECB38();
            b->unk97E = 2;
        }
        break;
    case 2:
        b->unk97E = 0;
        return 2;
    case 3:
        b->unk97E = 0;
        return 3;
    }
    return 0;
}

// sub_080E711C @ 0x080E711C
/* Task helper: result = 1 when the selected battle state variable equals value. */
void sub_080E711C(struct Task *t, u32 which, s32 value)
{
    struct C15cBattle *b = BB;
    s16 v;

    switch (which)
    {
    case 0:
        v = b->unk690;
        break;
    case 1:
        v = b->state;
        break;
    case 2:
        v = b->substate;
        break;
    case 3:
        v = b->phase;
        break;
    case 4:
        v = b->unk97E;
        break;
    }
    t->result = 0;
    if (v == value)
        t->result = 1;
}

// sub_080E7194 @ 0x080E7194
void sub_080E7194(void)
{
    if (gUnk_030063A0.active != 3)
        gUnk_030063A0.active = 2;
    BattleMsg_Close();
    BattleMsg_SetLocked(0);
    Font_ResetGlyphSpriteCache(0x180);
    sub_080C84A0();
    sub_081269D0();
}

// sub_080E71C4 @ 0x080E71C4
void sub_080E71C4(void)
{
    if (gUnk_030063A0.active != 3)
        gUnk_030063A0.active = 2;
}
