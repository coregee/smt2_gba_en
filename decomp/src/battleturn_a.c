/* Battle turn execution and result screens. */

#include "global.h"
#include "battledisp.h"

// sub_080E941C @ 0x080E941C
/* Runs the actions of one turn in order, then decides whether the battle continues, was won
   (escaped / ended) or lost. */
void sub_080E941C(struct Task *t)
{
    struct C15cBattle *b = BB;
    s16 actor;
    u32 r;
    s16 k;
    u8 j;

    t->result = 0;
    switch (b->substate)
    {
    case 0:
        b->unkECE = 0;
        sub_080F3120();
        sub_080F2D4C();
        Battle_BuildActionOrder();
        b->unkECC = Battle_GetLastOrderIndex();
        b->substate = 1;
        BattleFlags_Mask(~0x400);
    case 1:
        {
            u16 id = sub_080EFFC4(b->unkECE);
            u16 st;

            id += 0x8000;
            st = *(u16 *)(Battle_GetCombatant(id) + 0x10) & 0xB1E0;

            if (st != 0)
            {
                b->substate = 3;
            }
            else
            {
                b->substate = 2;
                b->phase = st;
            }
        }
        break;
    case 2:
        if (Battle_CombatantTurnStep((s16)sub_080EFFC4(b->unkECE)))
            b->substate = 3;
        break;
    case 3:
        Party_FixFormation();
        Party_BuildMemberNameTiles();
        Hud_LoadAllMemberFaces();
        for (k = 0; k < 4; k++)
            Combatant_UpdateStats(k);
        actor = sub_080EFFC4(b->unkECE);
        if (actor <= 15)
        {
            for (j = 0; j < 6; j++)
            {
                if (GS->order[j] == actor)
                    break;
            }
            if (j < 6)
                sub_080C8490(j);
        }
        r = sub_080ED9F4();
        if (r == 0)
        {
            sub_080C84A0();
            b->substate = r;
            b->state = 14;
            gUnk_030063A0.active = 4;
            t->result = 1;
            if (b->unkF6A != 0)
                gUnk_030063A0.unk0A = r;
        }
        else if (Battle_IsPartyDefeated())
        {
            sub_080ED90C(0x2000);
            b->substate = 0;
            b->state = 14;
            t->result = 1;
            sub_080C84A0();
            gUnk_030063A0.active = 3;
            b->state = 15;
            if (b->unkF6A != 0)
                gUnk_030063A0.unk0A = 0;
        }
        else if ((r = sub_080ED8F4() & 0x2200) != 0)
        {
            if ((sub_080ED8F4() & 0x2000) && gUnk_030063A0.unk0C == 2)
                gUnk_030063A0.unk14 = 1;
            t->result = 1;
            b->substate = 0;
            b->state = 14;
            for (k = 0; k < 8; k++)
                sub_080E7538(k, 0, 0);
        }
        else
        {
            b->unkECE++;
            if (b->unkECE > b->unkECC)
            {
                b->unkECE = r;
                b->unkEC0 = 1;
                b->unk11AC = 0xFFFF;
                b->unk11AE = -1;
                sub_080EF2A0();
                sub_080C84A0();
                if (++b->unk11A4 == 4)
                    b->unk11A4 = r;
                ((u16 *)gUnk_03006434)[1] = r;
                ((u16 *)gUnk_03006434)[0] &= 0xFF7F;
                if ((u16)(sub_080ED8F4() & 0x4000))
                {
                    b->substate = 1;
                    b->state = 13;
                    t->result = 1;
                }
                else
                {
                    b->substate = 0;
                    b->state = 6;
                    t->result = 1;
                }
                if (b->unkF6A != 0)
                    gUnk_030063A0.unk0A = 0;
            }
            else
            {
                b->substate = 1;
            }
        }
        break;
    case 4:
        break;
    }
}


// sub_080E9778 @ 0x080E9778
void sub_080E9778(void)
{
    struct C15cBattle *b = BB;

    b->state = 10;
    b->substate = 0;
}

// sub_080E9798 @ 0x080E9798
void sub_080E9798(struct Task *t)
{
    struct C15cBattle *b = BB;

    t->result = 0;
    switch (gUnk_030063A0.unk0A)
    {
    case 0:
        if (b->unkF6A == 0)
        {
            t->result = 1;
            break;
        }
        if (gUnk_030063A0.active == 1)
            gUnk_030063A0.unk06 = 5;
        gUnk_030063A0.unk0A = 2;
        break;
    case 1:
        if (gUnk_030063A0.unk06 == 5)
        {
            b->state = 16;
            t->result = 1;
        }
        t->result = 1;
        gUnk_030063A0.unk0A = 0;
        break;
    case 2:
        gUnk_030063A0.unk0A = 1;
        break;
    }
}

// sub_080E980C @ 0x080E980C
/* 1 when any enemy is still around (sub_080F0168, sub_080F01EC, sub_080F0194). */
u16 sub_080E980C(void)
{
    struct C15cBattle *b = BB;
    s16 n = b->unk99C;
    u16 r = sub_080F0168() != 0;
    u32 i;

    for (i = 0; i < n; i++)
    {
        if (sub_080F01EC(i) != -1)
            r = 1;
    }
    for (i = 0; i < 4; i++)
    {
        if (sub_080F0194(i))
            r = 1;
    }
    if (sub_080F0168())
        r = 1;
    return r;
}

// sub_080E9870 @ 0x080E9870
/* Victory message (or none); shows it in the message window. */
u16 *sub_080E9870(void)
{
    struct C15cBattle *b = BB;
    u16 *msg = NULL;

    if (sub_080ED8F4() & 0x200)
    {
        BattleMenu_Reset();
        return NULL;
    }
    if (Battle_IsTwoSided() == 1)
    {
        if ((s16)sub_080E980C() == 1 || Flag_Test(0xD5))
            msg = (u16 *)gUnknown_086BEC18;
    }
    else
    {
        if ((s16)sub_080E980C() == 1 || Flag_Test(0xD5))
            msg = MessageBox_ComposeRaceNameText(b->groups[0], gUnknown_08124284);
    }
    if (msg != NULL)
        BattleMenu_SetMode(3, msg);
    return msg;
}
