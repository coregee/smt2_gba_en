#include "global.h"
#include "battle2.h"

// Party_FindLowestStatTarget @ 0x080F57F4
/* Party member with the lowest stat `stat` (below 100) on whom status `mask` would take
   (sub_080F3214); -1 when none. */
s32 Party_FindLowestStatTarget(s32 stat, u16 mask)
{
    s32 best = 100;
    s32 who = -1;
    u32 i;

    for (i = 0; i < 6; i++)
    {
        s32 m = sub_080F40EC(i);

        if (m >= 0 && !Combatant_IsDead(m))
        {
            s32 v = Combatant_GetStat(m, stat);

            if (best > v && sub_080F3214(m, mask) == 1)
            {
                best = v;
                who = m;
            }
        }
    }
    return who;
}

// sub_080F5858 @ 0x080F5858
void sub_080F5858(struct Action *a)
{
    s32 m = Party_FindLowestStatTarget(0, 0x20);

    a->unkC = 0;
    if (m != -1 && !(Combatant_GetStatus(m) & 0x20))
    {
        sub_080EDA7C(0x20);
        a->def = m;
        a->dmg = 0xFFFF;
        a->unkC = 1;
    }
    else
        a->dmg = 0;
}

// sub_080F58A0 @ 0x080F58A0
void sub_080F58A0(struct Action *a)
{
    s32 m = Party_FindLowestStatTarget(4, 0x1000);

    a->unkC = 0;
    if (m != -1 && !(Combatant_GetStatus(m) & 0x1000))
    {
        sub_080EDA7C(0x1000);
        a->def = m;
        a->dmg = 0xFFFF;
        a->unkC = 1;
    }
    else
        a->dmg = 0;
}

// sub_080F58EC @ 0x080F58EC
void sub_080F58EC(struct Action *a)
{
    s32 m = Party_FindLowestStatTarget(5, 0x2000);

    a->unkC = 0;
    if (m != -1 && !(Combatant_GetStatus(m) & 0x2000))
    {
        sub_080EDA7C(0x2000);
        a->def = m;
        a->dmg = 0xFFFF;
        a->unkC = 1;
    }
    else
        a->dmg = 0;
}

// sub_080F5938 @ 0x080F5938
s32 sub_080F5938(void)
{
    return Party_FindLowestStatTarget(2, 0x8000);
}

// sub_080F5948 @ 0x080F5948
void sub_080F5948(struct Action *a)
{
    s32 m = sub_080F5938();

    a->unkC = 0;
    if (m != -1 && !(Combatant_GetStatus(m) & 0x8000))
    {
        sub_080EDA7C(0x8000);
        a->def = m;
        a->unkC = 1;
    }
    a->dmg = 0xFFFF;
}

// sub_080F5988 @ 0x080F5988
void sub_080F5988(struct Action *a)
{
    s32 m = Party_FindLowestStatTarget(1, 0x8000);

    a->unkC = 0;
    if (m != -1 && !(Combatant_GetStatus(m) & 0x8000))
    {
        sub_080EDA7C(0x8000);
        a->def = m;
        a->unkC = 1;
    }
    a->dmg = 0xFFFF;
}

// sub_080F59CC @ 0x080F59CC
/* Halves the party's money-like counter Magnetite_Get (at least 1 lost). */
void sub_080F59CC(struct Action *a)
{
    s32 n = Magnetite_Get();

    if (n)
    {
        n /= 2;
        if (n == 0)
            n = 1;
        Magnetite_Add(-n);
    }
    else
        a->unkC = n;
}

// sub_080F59F8 @ 0x080F59F8
/* Claims the side's one-per-turn slot (BattleFlow+0x11AC party / +0x11AE enemies); message
   0x7E with no effect when already taken. */
#ifdef NONMATCHING
void sub_080F59F8(struct Action *a)
{
    s32 who = a->att;
    struct BattleFlow *b = BFLOW;
    u16 *p;

    if (who <= 15)
        p = &b->unk11AC;
    else
        p = &b->unk11AE;
    if (*p == 0xFFFF)
        *p = who;
    else
    {
        a->msg = 0x7E;
        a->unkC = 0;
    }
}
#else
NAKED
void sub_080F59F8(struct Action *a)
{
    asm_unified(
        "    push {r4, lr}\n"
        "    adds r3, r0, #0\n"
        "    ldr r2, [r3]\n"
        "    ldr r0, .L080F5A08\n"
        "    cmp r2, #0xf\n"
        "    bgt .L080F5A10\n"
        "    ldr r1, .L080F5A0C\n"
        "    b .L080F5A12\n"
        ".L080F5A08: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080F5A0C: .4byte 0x000011AC\n"
        ".L080F5A10:\n"
        "    ldr r1, .L080F5A20\n"
        ".L080F5A12:\n"
        "    adds r4, r0, r1\n"
        "    ldrh r1, [r4]\n"
        "    ldr r0, .L080F5A24\n"
        "    cmp r1, r0\n"
        "    bne .L080F5A28\n"
        "    strh r2, [r4]\n"
        "    b .L080F5A30\n"
        ".L080F5A20: .4byte 0x000011AE\n"
        ".L080F5A24: .4byte 0x0000FFFF\n"
        ".L080F5A28:\n"
        "    movs r0, #0x7e\n"
        "    str r0, [r3, #8]\n"
        "    movs r0, #0\n"
        "    str r0, [r3, #0xc]\n"
        ".L080F5A30:\n"
        "    pop {r4}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// sub_080F5A38 @ 0x080F5A38
/* Enemy merge: 1 in 8, with at least two enemies left, the attacker absorbs another living
   enemy of the same demon id (HP and MP added, capped). */
void sub_080F5A38(struct Action *a)
{
    s32 who = a->att;
    s32 r = Random_Byte() & 7;
    s32 i;
    s16 hp;
    s16 mp;

    if (sub_080ED9F4() <= 1 || r != 0)
    {
        a->msg = 0x7E;
        a->unkC = 0;
        return;
    }
    for (i = 0x10; i < 0x18; i++)
    {
        if (i == who || !Combatant_IsAlive(i))
            continue;
        if (Combatant_GetDemonId(who) != Combatant_GetDemonId(i))
            continue;
        hp = Battle_GetHp(who) + Battle_GetHp(i);
        mp = Battle_GetMp(who) + Battle_GetMp(i);
        if (hp > Battle_GetMaxHp(who))
            hp = Battle_GetMaxHp(who);
        if (mp > Battle_GetMaxMp(who))
            mp = Battle_GetMaxMp(who);
        Battle_SetHp(who, hp);
        Battle_SetMp(who, mp);
        Combatant_ClearSlot(i);
        Combatant_SetStatus(i, 0x8000);
        sub_08126834(-1);
        sub_080E760C();
        return;
    }
    a->unkC = 0;
    a->msg = 0x7E;
}

// sub_080F5B30 @ 0x080F5B30
void sub_080F5B30(struct Action *a)
{
    s32 who;

    sub_080F51D4(a);
    if (a->unkC == 1)
        a->msg = 0x389;
    who = a->att;
    Combatant_SetStatus(who, 0x8000);
    Battle_SetHp(who, 0);
    if ((u32)(who - 4) <= 11)
        sub_080F4190(who);
}

// sub_080F5B6C @ 0x080F5B6C
void sub_080F5B6C(struct Action *a)
{
    s32 d = a->dmg / 2;

    if (!(Combatant_GetStatus(a->att) & 0x4000))
        Battle_HealHp(a->att, d);
}

// sub_080F5B98 @ 0x080F5B98
/* Removes a demon defender from the battle (party demons are stocked). */
void sub_080F5B98(struct Action *a)
{
    s32 who;

    if (!(sub_080ED8F4() & 0x100) && (who = a->def) > 3 && !Combatant_IsDead(who))
    {
        if ((u32)(who - 4) <= 11)
        {
            sub_080F4190(who);
            Party_FixFormation();
        }
        else
        {
            Combatant_ClearSlot(who);
            Combatant_SetStatus(who, 0x8000);
            sub_08126834(-1);
            if (!sub_080ED9F4())
                sub_080ED90C(0x200);
            sub_080E760C();
        }
        return;
    }
    a->unkC = 0;
}

// sub_080F5C04 @ 0x080F5C04
/* Heals the attacker by 3 x byte 3 of its skill record; 1 in 16 it gets status 0x40 instead. */
#ifdef NONMATCHING
void sub_080F5C04(struct Action *a)
{
    s32 who = a->att;
    s32 skill = Combatant_GetChosenSkill(who);
    s32 r;

    if (Random_Byte() & 0xF)
    {
        sub_080F40C4(Combatant_GetDemonId(who));
        if (Combatant_IsHpFull(who) || (Combatant_GetStatus(who) & 0x4000))
            r = 0;
        else
        {
            Battle_HealHp(who, sub_080BF5C0(skill)[3] * 3);
            r = 1;
        }
    }
    else
    {
        sub_080C08E8(who, 0x40);
        r = 0;
    }
    a->unkC = r;
}
#else
NAKED
void sub_080F5C04(struct Action *a)
{
    asm_unified(
        "    push {r4, r5, r6, lr}\n"
        "    adds r5, r0, #0\n"
        "    ldr r4, [r5]\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_GetChosenSkill\n"
        "    adds r6, r0, #0\n"
        "    bl Random_Byte\n"
        "    movs r1, #0xf\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080F5C5E\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_GetDemonId\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    bl sub_080F40C4\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_IsHpFull\n"
        "    cmp r0, #0\n"
        "    bne .L080F5C66\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_GetStatus\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #7\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    bne .L080F5C66\n"
        "    lsls r0, r6, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl sub_080BF5C0\n"
        "    ldrb r0, [r0, #3]\n"
        "    lsls r1, r0, #1\n"
        "    adds r1, r1, r0\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_HealHp\n"
        "    movs r0, #1\n"
        "    b .L080F5C68\n"
        ".L080F5C5E:\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0x40\n"
        "    bl sub_080C08E8\n"
        ".L080F5C66:\n"
        "    movs r0, #0\n"
        ".L080F5C68:\n"
        "    str r0, [r5, #0xc]\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

// sub_080F5C70 @ 0x080F5C70
void sub_080F5C70(struct Action *a)
{
    s32 d = a->dmg >> 1;

    Combatant_ChangeMpCapped(a->def, -d);
    a->unkC = 0;
}

// sub_080F5C8C @ 0x080F5C8C
void sub_080F5C8C(struct Action *a)
{
}

// Item_RunUseEffect @ 0x080F5C90
/* Runs the use effect of an item: attribute 12 minus 0x80 indexes gUnknown_0876FA58. */
void Item_RunUseEffect(struct Action *a, s32 item)
{
    s32 v;
    s32 k;

    Item_GetAttribute(item, 0xC, &v);
    k = v - 0x80;
    if (k >= 0)
    {
        a->msg = -1;
        a->unkC = 1;
        a->unk10 = k;
        gUnknown_0876FA58[k](a);
    }
}

// sub_080F5CD0 @ 0x080F5CD0
/* Item: heals a quarter of max HP. */
void sub_080F5CD0(struct Action *a)
{
    s32 who = a->def;

    if (Combatant_GetStatus(who) & 0x4000)
        Party_Remove(who, 0);
    else if (!Combatant_IsDead(who) && !Combatant_IsHpFull(who))
    {
        Combatant_ChangeHpCapped(who, Battle_GetMaxHp(who) / 4);
        return;
    }
    a->unkC = 0;
}

// sub_080F5D28 @ 0x080F5D28
/* Item: heals ((rand & 7) + 1) * 4 (kind 4) or * 6 (others) + level / 2 HP; past 998 or
   twice max HP the target is set to half max HP and gets status `kind`. */
#ifdef NONMATCHING
void sub_080F5D28(struct Action *a, u16 kind)
{
    s32 who = a->def;
    s32 max = Battle_GetMaxHp(who);
    u16 st;
    s32 hp;

    st = Combatant_GetStatus(who) & 0x4000;
    if (st)
    {
        Party_Remove(who, 0);
        a->unkC = 0;
        return;
    }
    if (!Combatant_IsDead(who))
    {
        if (kind == 4)
            hp = ((Random_Byte() & 7) + 1) * 4 + Battle_GetHp(who) + Math_DivRound(Combatant_GetLevel(who), 2);
        else
            hp = ((Random_Byte() & 7) + 1) * 6 + Battle_GetHp(who) + Math_DivRound(Combatant_GetLevel(who), 2);
        if (hp > 998 || hp > max * 2)
        {
            hp = max / 2;
            sub_080C08E8(who, kind);
        }
        Battle_SetHp(who, hp);
    }
    else
        a->unkC = st;
}
#else
NAKED
void sub_080F5D28(struct Action *a, u16 kind)
{
    asm_unified(
        ".L080F5D28:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    adds r5, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    mov r8, r1\n"
        "    ldr r6, [r5, #4]\n"
        "    adds r0, r6, #0\n"
        "    bl Battle_GetMaxHp\n"
        "    adds r7, r0, #0\n"
        "    adds r0, r6, #0\n"
        "    bl Combatant_GetStatus\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #7\n"
        "    ands r1, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r4, r1, #0x10\n"
        "    cmp r4, #0\n"
        "    beq .L080F5D64\n"
        "    lsls r0, r6, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    movs r1, #0\n"
        "    bl Party_Remove\n"
        "    movs r0, #0\n"
        "    str r0, [r5, #0xc]\n"
        "    b .L080F5DF6\n"
        ".L080F5D64:\n"
        "    adds r0, r6, #0\n"
        "    bl Combatant_IsDead\n"
        "    cmp r0, #0\n"
        "    bne .L080F5DF4\n"
        "    mov r0, r8\n"
        "    cmp r0, #4\n"
        "    bne .L080F5D9C\n"
        "    bl Random_Byte\n"
        "    adds r4, r0, #0\n"
        "    adds r0, r6, #0\n"
        "    bl Battle_GetHp\n"
        "    adds r5, r0, #0\n"
        "    adds r0, r6, #0\n"
        "    bl Combatant_GetLevel\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    movs r1, #2\n"
        "    bl Math_DivRound\n"
        "    movs r1, #7\n"
        "    ands r1, r4\n"
        "    adds r1, #1\n"
        "    lsls r1, r1, #2\n"
        "    b .L080F5DC6\n"
        ".L080F5D9C:\n"
        "    bl Random_Byte\n"
        "    adds r4, r0, #0\n"
        "    adds r0, r6, #0\n"
        "    bl Battle_GetHp\n"
        "    adds r5, r0, #0\n"
        "    adds r0, r6, #0\n"
        "    bl Combatant_GetLevel\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    movs r1, #2\n"
        "    bl Math_DivRound\n"
        "    movs r2, #7\n"
        "    ands r2, r4\n"
        "    adds r2, #1\n"
        "    lsls r1, r2, #1\n"
        "    adds r1, r1, r2\n"
        "    lsls r1, r1, #1\n"
        ".L080F5DC6:\n"
        "    adds r1, r1, r5\n"
        "    adds r4, r1, r0\n"
        "    ldr r0, .L080F5DF0\n"
        "    cmp r4, r0\n"
        "    bgt .L080F5DD6\n"
        "    lsls r0, r7, #1\n"
        "    cmp r4, r0\n"
        "    ble .L080F5DE4\n"
        ".L080F5DD6:\n"
        "    lsrs r0, r7, #0x1f\n"
        "    adds r0, r7, r0\n"
        "    asrs r4, r0, #1\n"
        "    adds r0, r6, #0\n"
        "    mov r1, r8\n"
        "    bl sub_080C08E8\n"
        ".L080F5DE4:\n"
        "    adds r0, r6, #0\n"
        "    adds r1, r4, #0\n"
        "    bl Battle_SetHp\n"
        "    b .L080F5DF6\n"
        "    .byte 0x00, 0x00\n"
        ".L080F5DF0: .4byte 0x000003E6\n"
        ".L080F5DF4:\n"
        "    str r4, [r5, #0xc]\n"
        ".L080F5DF6:\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

// sub_080F5E00 @ 0x080F5E00
void sub_080F5E00(struct Action *a)
{
    sub_080F5D28(a, 4);
}

// sub_080F5E0C @ 0x080F5E0C
void sub_080F5E0C(struct Action *a)
{
}

// sub_080F5E10 @ 0x080F5E10
/* Item: restores some HP (max/8 + 0-7) and MP (level/4 + 0-14). */
void sub_080F5E10(struct Action *a)
{
    s32 who = a->def;
    s32 n = 0;

    if (Combatant_GetStatus(who) & 0x4000)
    {
        Party_Remove(who, 0);
        goto store;
    }
    if (!Combatant_IsDead(who))
    {
        if (!Combatant_IsHpFull(who))
        {
            n = Random_Byte() & 7;
            n += Math_DivRound(Battle_GetMaxHp(who), 8);
            n += Battle_GetHp(who);
            if (n > Battle_GetMaxHp(who))
                n = Battle_GetMaxHp(who);
            Battle_SetHp(who, n);
        }
        if (!Combatant_IsMpFull(who))
        {
            n = Random_Byte() & 0xE;
            n += Math_DivRound(Combatant_GetLevel(who), 4);
            n += Battle_GetMp(who);
            if (n > Battle_GetMaxMp(who))
                n = Battle_GetMaxMp(who);
            Battle_SetMp(who, n);
        }
    }
    if (n == 0)
    {
    store:
        a->unkC = n;
    }
}

// sub_080F5ED8 @ 0x080F5ED8
/* Item: full HP and MP, cures status bits 0x73FE. */
#ifdef NONMATCHING
void sub_080F5ED8(struct Action *a)
{
    s32 who = a->def;
    s32 n = 0;

    if (Combatant_GetStatus(who) & 0x4000)
    {
        Party_Remove(who, 0);
        goto store;
    }
    if (!Combatant_IsDead(who))
    {
        if (!Combatant_IsHpFull(who))
        {
            Combatant_RestoreHp(who);
            n = 1;
        }
        if (!Combatant_IsMpFull(who))
        {
            Combatant_RestoreMp(who);
            n++;
        }
        if ((Combatant_GetStatus(who) << 16) & (0x73FE << 16))
        {
            Combatant_ClearStatus(who, (u16)~0x73FE);
            n++;
        }
    }
    if (n == 0)
    {
    store:
        a->unkC = n;
    }
}
#else
NAKED
void sub_080F5ED8(struct Action *a)
{
    asm_unified(
        "    push {r4, r5, r6, lr}\n"
        "    adds r6, r0, #0\n"
        "    ldr r4, [r6, #4]\n"
        "    movs r5, #0\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_GetStatus\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #7\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080F5EFC\n"
        "    lsls r0, r4, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    movs r1, #0\n"
        "    bl Party_Remove\n"
        "    b .L080F5F48\n"
        ".L080F5EFC:\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_IsDead\n"
        "    cmp r0, #0\n"
        "    bne .L080F5F44\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_IsHpFull\n"
        "    cmp r0, #0\n"
        "    bne .L080F5F18\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_RestoreHp\n"
        "    movs r5, #1\n"
        ".L080F5F18:\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_IsMpFull\n"
        "    cmp r0, #0\n"
        "    bne .L080F5F2A\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_RestoreMp\n"
        "    adds r5, #1\n"
        ".L080F5F2A:\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_GetStatus\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r1, .L080F5F50\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080F5F44\n"
        "    ldr r1, .L080F5F54\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_ClearStatus\n"
        "    adds r5, #1\n"
        ".L080F5F44:\n"
        "    cmp r5, #0\n"
        "    bne .L080F5F4A\n"
        ".L080F5F48:\n"
        "    str r5, [r6, #0xc]\n"
        ".L080F5F4A:\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080F5F50: .4byte 0x73FE0000\n"
        ".L080F5F54: .4byte 0x00008C01\n"
    );
}
#endif

// sub_080F5F58 @ 0x080F5F58
/* Item: revives with 1/8 of max HP; 1 in 64 it fails and the target stays dead. */
void sub_080F5F58(struct Action *a)
{
    s32 who = a->def;
    u16 f = Combatant_GetStatus(who);
    u16 st = f & 0x8000;

    if (st)
    {
        if (Random_Byte() & 0x3F)
        {
            s32 hp;

            Combatant_ClearStatus(who, 1);
            hp = Battle_GetMaxHp(who) / 8;
            if (hp == 0)
                hp = 1;
            Battle_SetHp(who, hp);
            sub_080F40C4(Combatant_GetDemonId(who));
            a->msg = 0x124;
        }
        else
        {
            sub_080C08E8(who, 0x8000);
            a->msg = 0x95;
        }
    }
    else
        a->unkC = st;
}

// sub_080F5FD0 @ 0x080F5FD0
/* Item: revives with full HP. */
void sub_080F5FD0(struct Action *a)
{
    s32 who = a->def;
    s32 d = Combatant_IsDead(who);

    if (d)
    {
        Combatant_ClearStatus(who, 1);
        Combatant_RestoreHp(who);
        sub_080F40C4(Combatant_GetDemonId(who));
        a->msg = 0x125;
    }
    else
        a->unkC = d;
}

// sub_080F6010 @ 0x080F6010
void sub_080F6010(struct Action *a)
{
}

// sub_080F6014 @ 0x080F6014
/* Item: raises a base stat (gUnknown_0876FB2C[effect - 8]) by 1 up to 40 and heals fully. */
void sub_080F6014(struct Action *a)
{
    s32 who = a->def;
    s32 healed = 0;
    s32 raised = 0;

    if (!Combatant_IsDead(who))
    {
        s32 stat = gUnknown_0876FB2C[a->unk10 - 8];

        if (Combatant_GetBaseStat(who, stat) <= 39)
        {
            Combatant_AddBaseStat(who, stat, 1);
            Combatant_UpdateStats(who);
            raised = 1;
        }
        if (!Combatant_IsHpFull(who))
        {
            Combatant_RestoreHp(who);
            sub_080F40C4(Combatant_GetDemonId(who));
            healed = 1;
        }
    }
    if (!raised)
    {
        if (healed == 1)
            a->msg = 0x11F;
        if (healed == 0)
            a->unkC = healed;
    }
    sub_080C65C8();
}
