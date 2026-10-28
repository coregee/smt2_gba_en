#include "global.h"
#include "battle.h"

/* the definition (battle_080EF20C.c) takes a u16; this caller passes it as s16 */
u32 sub_080EF494(s16 lvl, s32 id);

// sub_080EED64 @ 0x080EED64
u32 sub_080EED64(u16 kind, u16 id)
{
    if (kind == 11 && (u16)(id - 0x68) <= 0x2B)
        return 1;
    return 0;
}

// sub_080EED88 @ 0x080EED88
/* Status shields (reflect/void flags in the defender's status word) against an action.
   Returns 1 when the action was stopped. */
u32 sub_080EED88(struct Action *act)
{
    s32 att = act->att;
    s32 def = act->def;
    s32 dmg = act->dmg;
    u16 m = BSTATE->unk158;
    u16 st;
    s32 kind;
    s32 sk;
    s32 bit;

    act->msg = -1;
    st = sub_080EFAB0(def);
    kind = sub_080C35E4(att);
    if (dmg < 0 || m == 0xFFFF)
        return 0;
    sk = Combatant_GetChosenSkill(att);
    if ((kind == 7 || kind == 11) && (st & 0x20))
        goto nullify;
    if (kind == 7)
        bit = 1;
    else if ((u32)(kind - 4) <= 1 || kind == 10)
        bit = 2;
    else
        goto other;
    if (st & bit)
        goto reflect;
other:
    if (kind == 11 && sk > 0x3F && sk <= 0x67 && (st & 1))
        goto reflect;
    if (sub_080EED64(kind, sk) == 1 && (st & 2))
        goto reflect;
    if (def <= 15 && (BattleFlags_Get() & 1) && kind == 7)
    {
        BattleFlags_Mask(-2);
        goto reflect;
    }
    if (kind == 7 || kind == 11 || kind == 8)
    {
        if (kind == 8)
            Item_GetAttribute(sk, 0xC, &sk);
        if (sk > 0x7F)
            return 0;
        if ((st & 8) && sub_080ED6A4(sk) == 2)
        {
            sub_080EFB8C(def, -9);
            goto nullify;
        }
        if ((st & 0x10) && sub_080ED6A4(sk) == 3)
        {
            sub_080EFB8C(def, -17);
            goto nullify;
        }
    }
    return 0;
reflect:
    act->msg = 0x16E;
    return 1;
nullify:
    act->dmg = 0;
    BSTATE->unk158 = 0;
    return 1;
}

// Battle_ApplyAffinity @ 0x080EEEE8
/* Scales v by an affinity code: 12/14 halve, 13/15 keep, 0-8 give v*aff/8, 9-11 multiply
   (the shift cases for 1-7 in the switch are never reached). */
s32 Battle_ApplyAffinity(s32 v, s32 aff)
{
    s32 r;

    if (aff == 12)
        goto half;
    if (aff == 13)
        goto keep;
    if (aff == 14)
        goto half;
    if (aff == 15)
    {
    keep:
        return v;
    }
    if (aff <= 8)
        return v * aff / 8;
    r = v;
    switch (aff)
    {
    default:
    case 0:
        return 0;
    case 1:
        r >>= 1;
    case 2:
    c2:
        r >>= 1;
    case 4:
        r >>= 1;
        goto ret;
    case 3:
        r >>= 1;
        r += v;
        goto c2;
    case 5:
        r >>= 1;
        r += v;
        goto c6;
    case 7:
        r >>= 1;
    case 6:
    c6:
        {
            s32 q = r >> 2;
            s32 w = v - 1;

            r = w - q;
        }
        goto ret;
    case 11:
        r >>= 1;
        r += v;
        goto c10;
    case 9:
        r >>= 1;
    case 10:
    c10:
        r += v;
    case 8:
    ret:
        return r;
    case 12:
    half:
        return v / 2;
    }
}

// sub_080EEF98 @ 0x080EEF98
/* Acts on the battle-end code in unk126. */
void sub_080EEF98(void)
{
    switch (BSTATE->unk126)
    {
    case 1:
        sub_080ED90C(0x80);
        break;
    case 2:
        sub_080ED920(0xC000);
        break;
    case 3:
        sub_080ED920(0x8000);
        break;
    case 4:
        sub_080ED90C(0x2000);
        goto clear;
    case 5:
    {
        s32 id = sub_080EF878();

        Combatant_SetStatus(id, 0x8000);
        Combatant_ClearSlot(id);
        sub_08126834(-1);
        sub_080E760C();
        if (sub_080ED9F4())
            break;
        BSTATE->unk126 = 7;
    }
    case 6:
    case 7:
    case 12:
        sub_080ED90C(0x200);
        sub_080EDA04();
        sub_080E74DC();
    clear:
        BSTATE->unk4 = 0xFFFF;
        break;
    case 8:
        if ((s32)sub_080ED9F4() <= 7)
            sub_080EF224(sub_080EF828(), 1);
        break;
    case 9:
    case 10:
    case 11:
    {
        struct BattleFlow *b;

        sub_080ED90C(0x400);
        b = BFLOW;
        if (b->unk118E != 0xFFFF)
        {
            sub_080F41B0();
            Party_FixFormation();
            b->unk118E |= 0xFFFF;
        }
        Stock_AddDemon(gUnk_0203DB7C);
        Stock_FindFreeSlot();
        BSTATE->unk4 |= 0xFFFF;
        break;
    }
    case 0:
    case 13:
        break;
    }
}

// sub_080EF0E4 @ 0x080EF0E4
u32 sub_080EF0E4(s32 who)
{
    u16 f;
    s32 msg;

    if (who > 15)
        return 0;
    f = BattleFlags_Get();
    who = Combatant_GetAlignment(who);
    sub_080EDA90();
    if ((f & 2) && (u32)(who - 1) <= 1)
    {
        f &= 0xFFFD;
        msg = 0xF3;
    }
    else if ((f & 8) && who == 0)
    {
        f &= 0xFFF7;
        msg = 0xF4;
    }
    else
        return 0;
    sub_080F3E38(msg);
    BattleFlags_Set(f);
    return 1;
}

// Battle_RemoveDefeated @ 0x080EF148
/* Removes a defeated combatant; for an enemy with give == 1, awards experience to each party
   member (unk68) and the two other rewards (unk4C, unk50). */
void Battle_RemoveDefeated(s32 who, s32 give)
{
    s32 id;
    s32 slot;
    s32 i;

    if (who < 0)
        who = 0;
    Combatant_GetStatus(who);
    Combatant_SetStatus(who, 0x8000);
    id = Combatant_GetDemonId(who);
    Battle_SetHp(who, 0);
    sub_080F40C4(id);
    if (who > 15)
    {
        slot = who - 16;
        if (give == 1)
        {
            for (i = 0; i < 6; i++)
            {
                u32 p = sub_080F40EC(i);

                if (p <= 3)
                    BSTATE->unk68[p] += sub_080EF494(Combatant_GetLevel(p), id);
            }
            BSTATE->unk4C += sub_080EF538(id);
            BSTATE->unk50 += sub_080EF580(id);
        }
        sub_080EF6B4(id);
        sub_080ED8F4();
        sub_080E7538(slot, 2);
    }
    else if (who > 3)
        sub_080F4190(who);
    else
    {
        Party_FindPosition(who);
        sub_080C8490();
    }
}
