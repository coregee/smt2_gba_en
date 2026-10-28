#include "global.h"
#include "battle2.h"

// sub_080F4C48 @ 0x080F4C48
void sub_080F4C48(struct Action *a)
{
    sub_080F49D4(sub_080EFD5C(a->att, 1), a);
}

// sub_080F4C60 @ 0x080F4C60
void sub_080F4C60(struct Action *a)
{
    sub_080F49D4(sub_080EFDA4(a->att, 1), a);
}

// sub_080F4C78 @ 0x080F4C78
void sub_080F4C78(struct Action *a)
{
    sub_080F49D4(sub_080EFDEC(a->att, 1), a);
}

// sub_080F4C90 @ 0x080F4C90
/* Sets the attacker's status bit `mask` unless already set (then message 0x96, no effect);
   message `msg` (+1 for an enemy) when msg >= 0. */
void sub_080F4C90(struct Action *a, u16 mask, s32 msg)
{
    s16 m = mask;

    if ((sub_080EFAB0(a->att) & m) << 16)
    {
        a->msg = 0x96;
        a->unkC = 0;
    }
    else
    {
        sub_080EFAD0(a->att, m);
        if (msg >= 0)
        {
            a->msg = msg;
            if (a->att > 15)
                a->msg = msg + 1;
        }
    }
}

// sub_080F4CD4 @ 0x080F4CD4
void sub_080F4CD4(struct Action *a)
{
    u32 f = BattleFlags_Get();

    if (f & 0x800)
    {
        a->msg = 0x96;
        a->unkC = 0;
    }
    else
    {
        BattleFlags_Add(0x800);
        a->msg = 0xCB;
        if (a->att > 15)
            a->msg = 0xCC;
    }
}

// sub_080F4D0C @ 0x080F4D0C
void sub_080F4D0C(struct Action *a)
{
    sub_080F4C90(a, 1, 0xCD);
}

// sub_080F4D1C @ 0x080F4D1C
void sub_080F4D1C(struct Action *a)
{
    sub_080F4C90(a, 2, 0xCF);
}

// Battle_HealHp @ 0x080F4D2C
/* Adds d to a combatant's HP, capped at max HP; returns the new HP. */
s16 Battle_HealHp(s32 who, s32 d)
{
    struct Combatant *c = Battle_GetCombatant(who - 0x8000u);

    c->hp += d;
    if (c->hp > c->maxHp)
        c->hp = c->maxHp;
    return c->hp;
}

// sub_080F4D64 @ 0x080F4D64
/* Healing amount: (stat(def) / 2 + level bonus + stat(att)) << sh plus 0-7; sh = -1 heals
   fully (999). */
s32 sub_080F4D64(struct Action *a, s32 sh)
{
    s32 v;
    s32 att;
    s32 def;

    if (sh == -1)
        return 999;
    def = a->def;
    att = a->att;
    v = Combatant_GetLuck(def) >> 1;
    v += Math_DivRound(Combatant_GetIntelligence(att), 2);
    v += Combatant_GetMagic(att);
    v = (v << sh) + (Random_Byte() & 7);
    return v;
}

// sub_080F4DBC @ 0x080F4DBC
void sub_080F4DBC(struct Action *a, s32 sh)
{
    s32 who = a->def;
    s32 r;

    if (!Combatant_IsDead(who))
    {
        sub_080F40C4(Combatant_GetDemonId(who));
        if (!(Combatant_GetStatus(who) & 0x4000))
        {
            if (!Combatant_IsHpFull(who))
            {
                Battle_HealHp(who, sub_080F4D64(a, sh));
                r = 1;
                goto done;
            }
        }
        else
            Party_Remove(who, 0);
    }
    r = 0;
done:
    a->unkC = r;
}

// sub_080F4E20 @ 0x080F4E20
void sub_080F4E20(struct Action *a)
{
    sub_080F4DBC(a, 0);
}

// sub_080F4E2C @ 0x080F4E2C
void sub_080F4E2C(struct Action *a)
{
    sub_080F4DBC(a, 2);
}

// sub_080F4E38 @ 0x080F4E38
void sub_080F4E38(struct Action *a)
{
    sub_080F4DBC(a, -1);
}

// sub_080F4E48 @ 0x080F4E48
/* sub_080F4DBC on every member of the attacker side. */
void sub_080F4E48(struct Action *a, s32 sh)
{
    struct Action tmp;
    s32 n = 0;
    s32 i;

    tmp = *a;
    if (a->att > 15)
    {
        for (i = 0x10; i < 0x18; i++)
        {
            if (Combatant_IsUsed(i))
            {
                tmp.def = i;
                sub_080F4DBC(&tmp, sh);
                if (tmp.unkC)
                    n++;
            }
        }
    }
    else
    {
        for (i = 0; i < 6; i++)
        {
            tmp.def = sub_080F40EC(i);
            if (tmp.def >= 0)
            {
                sub_080F4DBC(&tmp, sh);
                if (tmp.unkC)
                    n++;
            }
        }
    }
    if (n == 0)
        a->unkC = n;
}

// sub_080F4EC0 @ 0x080F4EC0
void sub_080F4EC0(struct Action *a)
{
    sub_080F4E48(a, 0);
}

// sub_080F4ECC @ 0x080F4ECC
void sub_080F4ECC(struct Action *a)
{
    sub_080F4E48(a, 2);
}

// sub_080F4ED8 @ 0x080F4ED8
void sub_080F4ED8(struct Action *a)
{
    sub_080F4E48(a, -1);
}

// sub_080F4EE8 @ 0x080F4EE8
/* Cures the status bits of ailment `kind` (sub_080ED794) on the defender. */
#ifdef NONMATCHING
void sub_080F4EE8(struct Action *a, s32 kind)
{
    u16 mask = sub_080ED794(kind);
    s32 who = a->def;
    s32 r;

    if (!Combatant_IsDead(who))
    {
        sub_080F40C4(Combatant_GetDemonId(who));
        if (Combatant_GetStatus(who) & mask)
        {
            Combatant_ClearStatus(who, (u16)~mask);
            r = 1;
            goto done;
        }
    }
    r = 0;
done:
    a->unkC = r;
}
#else
NAKED
void sub_080F4EE8(struct Action *a, s32 kind)
{
    asm_unified(
        ".L080F4EE8:\n"
        "    push {r4, r5, r6, lr}\n"
        "    adds r5, r0, #0\n"
        "    adds r0, r1, #0\n"
        "    bl sub_080ED794\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldr r4, [r5, #4]\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_IsDead\n"
        "    cmp r0, #0\n"
        "    bne .L080F4F2E\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_GetDemonId\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    bl sub_080F40C4\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_GetStatus\n"
        "    adds r1, r6, #0\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080F4F2E\n"
        "    mvns r1, r6\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_ClearStatus\n"
        "    movs r0, #1\n"
        "    b .L080F4F30\n"
        ".L080F4F2E:\n"
        "    movs r0, #0\n"
        ".L080F4F30:\n"
        "    str r0, [r5, #0xc]\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

// sub_080F4F38 @ 0x080F4F38
void sub_080F4F38(struct Action *a)
{
    sub_080F4EE8(a, 0x31);
}

// sub_080F4F44 @ 0x080F4F44
void sub_080F4F44(struct Action *a)
{
    sub_080F4EE8(a, 0x33);
}

// sub_080F4F50 @ 0x080F4F50
void sub_080F4F50(struct Action *a)
{
    sub_080F4EE8(a, 0x34);
}

// sub_080F4F5C @ 0x080F4F5C
void sub_080F4F5C(struct Action *a)
{
    sub_080F4EE8(a, 0x35);
}

// sub_080F4F68 @ 0x080F4F68
/* sub_080F4EE8(kind 0x31) on every member of the attacker side. */
void sub_080F4F68(struct Action *a)
{
    struct Action tmp;
    s32 n = 0;
    s32 i;

    tmp = *a;
    if (a->att > 15)
    {
        for (i = 0x10; i < 0x18; i++)
        {
            if (Combatant_IsUsed(i))
            {
                tmp.def = i;
                sub_080F4EE8(&tmp, 0x31);
                if (tmp.unkC)
                    n++;
            }
        }
    }
    else
    {
        for (i = 0; i < 6; i++)
        {
            tmp.def = sub_080F40EC(i);
            if (tmp.def >= 0)
            {
                sub_080F4EE8(&tmp, 0x31);
                if (tmp.unkC)
                    n++;
            }
        }
    }
    if (n == 0)
        a->unkC = n;
}

// sub_080F4FE0 @ 0x080F4FE0
/* Revives the defender (status bit 0x8000) with HP adjusted by -75 (Combatant_ChangeHpPercent). */
void sub_080F4FE0(struct Action *a)
{
    s32 who = a->def;
    u16 f = Combatant_GetStatus(who);
    u16 r = f & 0x8000;

    if (r)
    {
        Combatant_ClearStatus(who, 1);
        Combatant_RestoreHp(who);
        Combatant_ChangeHpPercent(who, -75);
        sub_080F40C4(Combatant_GetDemonId(who));
        a->msg = 0xE5;
        if (who > 15)
            a->msg = 0xE6;
        r = 1;
    }
    a->unkC = r;
}

// sub_080F503C @ 0x080F503C
/* As sub_080F4FE0 without the HP adjustment. */
void sub_080F503C(struct Action *a)
{
    s32 who = a->def;
    u16 f = Combatant_GetStatus(who);
    u16 r = f & 0x8000;

    if (r)
    {
        a->unkC = 1;
        Combatant_ClearStatus(who, 1);
        Combatant_RestoreHp(who);
        sub_080F40C4(Combatant_GetDemonId(who));
        a->msg = 0xE5;
        if (who > 15)
            a->msg = 0xE6;
    }
    else
        a->unkC = r;
}

// sub_080F5090 @ 0x080F5090
/* The attacker dies to revive (Combatant_RestoreHp) every other member of its side. */
void sub_080F5090(struct Action *a)
{
    s32 n = 0;
    s32 who = a->att;
    s32 i;
    s32 m;

    if (who > 15)
    {
        for (i = 0x10; i < 0x18; i++)
        {
            if (Combatant_IsAlive(i) && i != who && !Combatant_IsHpFull(i))
            {
                Combatant_RestoreHp(i);
                n++;
            }
        }
    }
    else
    {
        for (i = 0; i < 6; i++)
        {
            m = sub_080F40EC(i);
            if (m >= 0 && !Combatant_IsDead(m) && m != who && !Combatant_IsHpFull(m))
            {
                Combatant_RestoreHp(m);
                n++;
            }
        }
    }
    if (n)
    {
        a->msg = 0xD9;
        if (who > 15)
            a->msg = 0xDA;
        sub_080C08E8(who, 0x8000);
        Battle_SetHp(who, 0);
        sub_080F40C4(Combatant_GetDemonId(who));
        if ((u32)(who - 4) <= 11)
            sub_080F4190(who);
        Party_FixFormation();
        a->unkC = 1;
        sub_080E760C();
    }
    else
        a->unkC = n;
}

// sub_080F5158 @ 0x080F5158
void sub_080F5158(struct Action *a)
{
    s32 r;

    if (gGameState.unkAC0 != 1 && sub_080F3DD8())
    {
        BattleFlags_Add(0x100);
        r = 1;
    }
    else
    {
        a->msg = -1;
        r = 0;
    }
    a->unkC = r;
}

// sub_080F5194 @ 0x080F5194
void sub_080F5194(struct Action *a)
{
    s32 r = sub_080C5240();

    if (r == 1)
    {
        sub_080C5224();
        a->unkC = r;
    }
    else
        a->unkC = 0;
}

// sub_080F51B4 @ 0x080F51B4
void sub_080F51B4(struct Action *a)
{
    s32 r = Encounter_IsAllowed();

    if (r == 1)
    {
        sub_080C5304();
        a->unkC = r;
    }
    else
        a->unkC = 0;
}

// sub_080F51D4 @ 0x080F51D4
void sub_080F51D4(struct Action *a)
{
    s32 r;

    if ((sub_080ED8F4() & 0x100) || Flag_Test(0x166))
        r = 0;
    else
    {
        sub_080ED90C(0x2000);
        r = 1;
    }
    a->unkC = r;
}

// sub_080F5208 @ 0x080F5208
void sub_080F5208(struct Action *a)
{
    if (BattleFlags_Get() & 0x80)
        a->msg = 0x96;
    else
    {
        BattleFlags_Add(0x80);
        gGameState.unk18BB = (Moon_GetPhase() & 0xF0) + 1;
    }
    a->unkC = 1;
}

// sub_080F5248 @ 0x080F5248
void sub_080F5248(struct Action *a)
{
}

// sub_080F524C @ 0x080F524C
void sub_080F524C(struct Action *a)
{
}

// sub_080F5250 @ 0x080F5250
void sub_080F5250(struct Action *a)
{
}

// sub_080F5254 @ 0x080F5254
/* Petrify / level-drain skill effect on the defender (skill 0x54 only hits members 1-2,
   0x5E only the hero). */
void sub_080F5254(struct Action *a)
{
    s16 skill = (u16)Combatant_GetChosenSkill(a->att);
    s32 who = a->def;
    s32 v;
    s32 x;
    s32 best;
    s32 bi;
    s32 i;

    a->unkC = 0;
    a->msg = -1;
    sub_080EFAB0(who);
    a->unkC = 0;
    if (skill == 0x54 && (u32)(who - 1) > 1)
        return;
    if (skill == 0x5E && who != 0)
        return;
    if (Combatant_GetStatus(who) & 0x1000)
    {
        u16 f;

        if (who > 3)
            return;
        if ((f = BattleFlags_Get()) & 0xC)
        {
            v = -1;
            x = Combatant_GetAlignment(who);
            if ((f & 4) && x == 2)
            {
                BattleFlags_Mask(~4);
                v = 0xE0;
            }
            if ((f & 8) && v < 0 && x == 0)
            {
                BattleFlags_Mask(~8);
                v = 0xF4;
            }
            if (v >= 0)
            {
                sub_080F3E38(v);
                a->msg = 0x138;
                return;
            }
        }
        if (BattleFlags_Get() & 0x800)
        {
            a->msg = 0x153;
            if (who <= 15)
                a->msg = 0x154;
            BattleFlags_Mask(~0x800);
            return;
        }
        v = Combatant_GetLevel(who) - 1;
        if (v <= 0)
            return;
        Combatant_SetLevel(who, v);
        sub_080C0F70(who, Exp_GetForLevel(v));
        bi = 0;
        best = 0;
        for (i = 0; i < 6; i++)
        {
            x = Combatant_GetBaseStat(who, i);
            if (x > best)
            {
                best = x;
                bi = i;
            }
        }
        Combatant_AddBaseStat(who, bi, -1);
        sub_080F40C4(Combatant_GetDemonId(who));
        a->msg = 0x119;
        sub_080EDA7C(0xFFFF);
        Combatant_ClearStatus(who, 0xEFFF);
    }
    else
    {
        a->msg = 0x39A;
        sub_080C08E8(who, 0x1000);
    }
    sub_080C6FD8();
    a->unkC = 1;
}

// sub_080F53F0 @ 0x080F53F0
void sub_080F53F0(struct Action *a)
{
    sub_080EFDA4(a->def, -1);
}

// sub_080F5400 @ 0x080F5400
/* Drain: the attacker gains the damage dealt as HP (not while status bit 0x4000). */
void sub_080F5400(struct Action *a)
{
    sub_080EFAB0(a->def);
    if (!(Combatant_GetStatus(a->att) & 0x4000))
        Battle_HealHp(a->att, a->dmg);
}

// sub_080F5428 @ 0x080F5428
void sub_080F5428(struct Action *a)
{
    sub_080F4C90(a, 8, -1);
}

// sub_080F5438 @ 0x080F5438
void sub_080F5438(struct Action *a)
{
    sub_080F4C90(a, 0x10, -1);
}

// sub_080F5448 @ 0x080F5448
void sub_080F5448(struct Action *a)
{
    sub_080C35C4(a->att, 9);
}

// sub_080F5458 @ 0x080F5458
/* The attacker leaves the battle (slot cleared, status 0x8000). */
void sub_080F5458(struct Action *a)
{
    s32 who = a->att;

    Combatant_ClearSlot(who);
    Combatant_SetStatus(who, 0x8000);
    sub_08126834(-1);
    if (!sub_080ED9F4())
        sub_080ED90C(0x200);
    sub_080E760C();
}

// sub_080F5490 @ 0x080F5490
/* Enemy call for help: 7 in 8 chance, while its side has fewer than 8 (4 when two-sided)
   units; message 0x139, else 0x11C with no effect. */
void sub_080F5490(struct Action *a)
{
    s32 msg;

    if (a->att > 15 && (Random_Byte() & 7))
    {
        s32 side = 0;
        s32 n;
        s32 lim;

        if (a->att > 0x13)
            side = 1;
        n = sub_080EDA24(side);
        lim = Battle_IsTwoSided() ? 4 : 8;
        if (n < lim && sub_080EF224(a->att, 1))
        {
            sub_080F40C4(Combatant_GetDemonId(a->att));
            msg = 0x139;
            goto done;
        }
    }
    a->unkC = 0;
    msg = 0x11C;
done:
    a->msg = msg;
}

// sub_080F54FC @ 0x080F54FC
void sub_080F54FC(struct Action *a)
{
    s32 r1 = Battle_AddModifierClamped(1, a->att, 1);
    s32 r3 = Battle_AddModifierClamped(3, a->att, 1);

    if (r1 && r3)
    {
        a->msg = 0x96;
        a->unkC = 0;
    }
}

// sub_080F552C @ 0x080F552C
void sub_080F552C(struct Action *a)
{
    s32 r2 = Battle_AddModifierClamped(2, a->att, 1);
    s32 r4 = Battle_AddModifierClamped(4, a->att, 1);

    if (r2 && r4)
    {
        a->msg = 0x96;
        a->unkC = 0;
    }
}

// sub_080F555C @ 0x080F555C
/* Inflicts status 0x10 on the whole opposing side; 1 in 16 it hits the attacker instead. */
void sub_080F555C(struct Action *a)
{
    u16 r = Random_Byte() & 0xF0;
    u32 i;
    s32 m;

    a->dmg = 0xFFFF;
    a->unkC = 0;
    if (r == 0)
    {
        Combatant_SetStatus(a->att, 0x10);
        return;
    }
    if (a->att > 15)
    {
        for (i = 0; i < 6; i++)
        {
            m = sub_080F40EC(i);
            if (m >= 0 && !Combatant_IsDead(m))
            {
                Combatant_SetStatus(m, 0x10);
                if (Combatant_GetStatus(m) & 0x10)
                    a->unkC = 1;
            }
        }
    }
    else
    {
        for (i = 0x10; i < 0x18; i++)
        {
            if (Combatant_IsAlive(i))
            {
                Combatant_SetStatus(i, 0x10);
                if (Combatant_GetStatus(i) & 0x10)
                    a->unkC = 1;
            }
        }
    }
}

// Combatant_IsAlignmentCompatible @ 0x080F55F4
/* 1 when b's alignment (Combatant_GetAlignment) is 1 (neutral) or equal to a's. */
s32 Combatant_IsAlignmentCompatible(s32 a, s32 b)
{
    s32 x = Combatant_GetAlignment(a);
    s32 y = Combatant_GetAlignment(b);
    s32 r = 0;

    if (y == 1 || y == x)
        r = 1;
    return r;
}

// sub_080F5618 @ 0x080F5618
/* Damage of an alignment-based skill: none against the same or a neutral alignment, else
   1/8 of the target's HP on the same side and 1/4 on the other side. */
void sub_080F5618(struct Action *a)
{
    s32 v;

    if (Combatant_IsAlignmentCompatible(a->att, a->def) == 1)
        v = 0;
    else if ((a->att <= 15 && a->def <= 15) || (a->att > 15 && a->def > 15))
        v = Battle_GetHp(a->def) / 8;
    else
        v = Battle_GetHp(a->def) / 4;
    a->dmg = v;
}

// sub_080F5664 @ 0x080F5664
void sub_080F5664(struct Action *a)
{
    if (!sub_080EDAD0())
    {
        s32 r = Random_Byte() & 3;

        if (r == 0)
        {
            Moon_Advance(0x40);
            a->dmg = r;
            a->unkC = r;
        }
    }
}

// sub_080F5690 @ 0x080F5690
/* Restores the attacker's HP/MP from its demon record and clears its status and modifiers. */
void sub_080F5690(struct Action *a)
{
    s32 who = a->att;
    struct Combatant *c = Battle_GetCombatant(who - 0x8000u);
    u8 *rec = Demon_GetRecord(c->demonId);
    s32 v;

    c->hp = *(u16 *)(rec + 2);
    c->maxHp = *(u16 *)(rec + 2);
    c->mp = *(u16 *)(rec + 4);
    c->maxMp = *(u16 *)(rec + 4);
    c->flags = 0;
    sub_080E760C();
    if ((v = sub_080EFBFC(who)) != 0)
        sub_080EFD14(who, -v);
    if ((v = sub_080EFD3C(who)) != 0)
        sub_080EFD5C(who, -v);
    if ((v = sub_080EFD84(who)) != 0)
        sub_080EFDA4(who, -v);
    if ((v = sub_080EFDCC(who)) != 0)
        sub_080EFDEC(who, -v);
}

// sub_080F5714 @ 0x080F5714
void sub_080F5714(struct Action *a)
{
    if (a->def <= 3)
    {
        a->dmg = 0;
        return;
    }
    if (!Party_GetRow(a->def))
        a->dmg = Battle_GetHp(a->def) / 2;
    else
        a->dmg = Battle_GetHp(a->def) / 4;
    if (a->dmg == 0)
        a->dmg = 1;
}

// sub_080F5758 @ 0x080F5758
/* Inflicts status 0x20 (level 10-19, 1 in 16) or 0x1000 (level <= 9, 1 in 8) on party
   members. */
void sub_080F5758(struct Action *a)
{
    u32 i;
    s32 m;
    s32 lvl;

    a->unkC = 0;
    for (i = 0; i < 6; i++)
    {
        m = sub_080F40EC(i);
        if (m < 0 || Combatant_IsDead(m))
            continue;
        lvl = Combatant_GetStat(m, 1);
        if (lvl > 19)
            continue;
        if (lvl > 9)
        {
            if (Random_Byte() & 0xF0)
                continue;
            if (Combatant_GetStatus(m) & 0x20)
                continue;
            Combatant_SetStatus(m, 0x20);
            if (Combatant_GetStatus(m) & 0x20)
                a->unkC = 1;
        }
        else
        {
            if (Random_Byte() & 0xE0)
                continue;
            if (Combatant_GetStatus(m) & 0x1000)
                continue;
            Combatant_SetStatus(m, 0x1000);
            if (Combatant_GetStatus(m) & 0x1000)
                a->unkC = 1;
        }
    }
    a->dmg = 0xFFFF;
}
