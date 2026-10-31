#include "global.h"
#include "battle.h"

// Battle_SortEntriesInsertion @ 0x080EDB6C
/* Insertion sort of a[lo..hi-1] by ascending key. */
void Battle_SortEntriesInsertion(u16 lo, u16 hi, struct SortEntry *a)
{
    s32 i, j;

    for (i = lo + 1; i < hi; i++)
    {
        struct SortEntry t = a[i];
        s32 key = a[i].key;

        for (j = i - 1; j >= lo && a[j].key > key; j--)
            a[j + 1] = a[j];
        a[j + 1] = t;
    }
}

/* Quicksort (descending by key) with an explicit stack; runs of up to 10 entries are left
   for the insertion sort at the end. The pop/partition loop is a do-while entered at its
   middle: the loop notes weight r, sp and a the way the original register choice needs. */
// Battle_SortEntriesQuick @ 0x080EDBCC
void Battle_SortEntriesQuick(u16 lo, u16 n, struct SortEntry *a)
{
    u16 stackHi[32];
    u16 stackLo[32];
    s16 l, r;
    s32 sp;

    l = lo;
    r = l + n - 1;
    sp = 0;
    if (r - l > 10)
        goto partition;
    goto done;
    do
    {
        sp--;
        l = stackLo[sp];
        r = stackHi[sp];
    partition:
        {
            s32 pivot = a[(l + r) / 2].key;
            u32 i = l - 1;
            u32 j = r + 1;

            for (;;)
            {
                while (a[++i].key > pivot)
                    ;
                while (a[--j].key < pivot)
                    ;
                if (i >= j)
                    break;
                {
                    struct SortEntry t = a[i];
                    a[i] = a[j];
                    a[j] = t;
                }
            }
            if (i - l > r - j)
            {
                if (i - l > 10)
                {
                    stackLo[sp] = l;
                    stackHi[sp] = i - 1;
                    sp++;
                }
                l = j + 1;
            }
            else
            {
                if (r - j > 10)
                {
                    stackLo[sp] = j + 1;
                    stackHi[sp] = r;
                    sp++;
                }
                r = i - 1;
            }
        }
        if (r - l > 10)
            goto partition;
    } while (sp != 0);
done:
    Battle_SortEntriesInsertion(lo, n, a);
}

// Battle_RollSpeed @ 0x080EDD1C
s32 Battle_RollSpeed(s32 who)
{
    u8 *c = Battle_GetCombatant(who + 0x8000);
    s32 kind = sub_080C35E4(who);
    s32 v = (s8)c[0x44];
    s32 bonus;

    if (*(u16 *)(c + 0x10) & 0x800)
        v = 0x3C;
    bonus = 0;
    if (who < 16 && !Party_GetRow(who))
        bonus = Math_DivRound(v, 2);
    v = v * 2 + bonus + (Random_Byte() & 0xF);
    if (kind == 7)
        v += sub_080EDB04() >> 1;
    return v;
}

// Battle_BuildActionOrder @ 0x080EDD8C
/* Builds the action order: living party members and enemies, sorted by speed. */
void Battle_BuildActionOrder(void)
{
    u8 *g = gGameState;
    s8 *party = (s8 *)(g + 0xA20);
    struct SortEntry *list = BSTATE->order;
    struct SortEntry *e = list;
    u16 mode = BSTATE->unk2;
    s32 n = 0;
    s32 i;

    if (!(BSTATE->flags & 0x2000) && mode != 0xC000)
    {
        for (i = 5; i >= 0; i--)
        {
            s32 who = *party++;

            if (who != -1 && !(*(u16 *)(Party_GetMember(who + 0x8000) + 0x10) & 0xB160))
            {
                e->id = who;
                e->key = -Battle_RollSpeed(who);
                e++;
                n++;
            }
        }
    }
    if (mode != 0x8000)
    {
        for (i = 0x10; i < 0x18; i++)
        {
            if (*(u16 *)(Battle_GetCombatant(i + 0x8000) + 0xE) != 0)
            {
                /* the first roll is thrown away */
                Battle_RollSpeed(i);
                e->id = i;
                e->key = -Battle_RollSpeed(i);
                e++;
                n++;
            }
        }
    }
    e->id = 0xFFFF;
    Battle_SortEntriesInsertion(0, n, list);
}

// sub_080EDE70 @ 0x080EDE70
u32 sub_080EDE70(void)
{
    s16 r;
    s32 a, b;
    s32 d;
    u16 m;
    u32 v;

    if (!(BattleFlags_Get() & 0x20))
    {
        r = (u16)sub_080EDB04();
        a = sub_080F43A4(5) / 2 + sub_080F43A4(4) + r;
        b = sub_080F43E0(5) / 2 + sub_080F43E0(4) + (((r ^ 0xF) - 7) & 0xFF);
        d = (s16)(a - b);
        m = d;
        v = m & 0x7FFF;
        m = v;
        if (m == 0)
            return 0;
        if (d < 0)
            v = (m ^ 0x7FFF) + 1;
        if ((Random_Byte() & 0x3F) >= (s16)v)
            return 0;
        if (d < 0)
            return 0xC000;
    }
    return 0x8000;
}

// sub_080EDF0C @ 0x080EDF0C
u32 sub_080EDF0C(void)
{
    s32 count, sum, v, i, who;
    s8 *party;
    u8 *g;

    if (sub_080EDAD0() || (sub_080ED8F4() & 0x100) || Flag_Test(0x166))
        return 0x145;
    g = gGameState;
    if (*(u16 *)(g + 0xAC0) != 1 && View_GetWall(2, 0, 0) == 1)
        return 0x146;
    if (sub_080ED92C() == 0x8000)
        return 0x144;
    count = 0;
    sum = 0;
    for (i = 0, party = gUnk_030050E0; i < 6; i++)
    {
        who = *(s8 *)(i + (u32)party);

        if (who >= 0 && !Combatant_IsDead(who))
        {
            count++;
            sum += (u16)Combatant_GetAgility(who) + (u16)Combatant_GetLuck(who);
        }
    }
    /* v stays unset when no enemy is found (original bug) */
    for (i = 0; i < 8; i++)
    {
        if (Combatant_IsUsed(i + 0x10))
        {
            who = i + 0x10;
            v = (u16)Combatant_GetAgility(who) + (u16)Combatant_GetLuck(who);
            break;
        }
    }
    v *= count;
    v += Random_Byte() & 7;
    if (v >= sum && (Random_Byte() & 0xF))
        return 0x145;
    return 0x144;
}

// sub_080EE028 @ 0x080EE028
u32 sub_080EE028(s32 att, s32 def)
{
    s32 mode = BSTATE->unk15C;
    u8 *d;
    u8 *a;
    s32 kind;
    s32 v;

    if (mode == 0)
        return 0;
    if (mode == -1)
        goto ret1;
    d = Battle_GetCombatant(def + 0x8000);
    if (*(u16 *)(d + 0x10) & 0x3160)
        goto ret1;
    a = Battle_GetCombatant(att + 0x8000);
    kind = (s8)a[0x17];
    if (kind == 8)
        goto ret1;
    if (kind == 0xB || kind == 7)
    {
        s8 lv = d[0x41];
        s32 t = lv * 2 - 1;

        v = (t - *(s16 *)(a + 0x56) + 0x10) * 2;
        if (v > 0xFF)
            goto ret1;
    }
    else
    {
        v = *(s16 *)(d + 0x52);
        if (kind == 4 || kind == 0xA)
            v -= *(s16 *)(a + 0x4A);
        else
            v -= *(s16 *)(a + 0x4E);
        v += 0x10;
        if (v < 0)
            goto ret1;
        v = v * v;
        v >>= 5;
        {
            u32 k = sub_080EFD84(att) + 4;

            v = v * 8 / gUnknown_0876F78E[k];
        }
    }
    if ((s32)Random_Byte() <= v)
        goto ret0;
ret1:
    return 1;
ret0:
    return 0;
}


// Battle_BuildTargetList @ 0x080EE10C
/* Builds the target list for an attacker. */
void Battle_BuildTargetList(s32 who)
{
    s32 mode = BSTATE->unk15C;
    s32 n = 0;
    s32 i;
    s32 p;
    u8 *c;

    BSTATE->targets[0].id = 0xFFFF;
    c = Battle_GetCombatant(who + 0x8000);
    if ((s8)c[0x17] == 0xB && c[0x5C] == 0x5C)
    {
        for (i = 0; i < 6; i++)
        {
            c = Party_GetMember(i);
            if (c != NULL && !Combatant_IsDead(i) && !Combatant_IsAlignmentCompatible(who, c[0xC]))
            {
                BSTATE->targets[n].id = c[0xC];
                n++;
            }
        }
        for (i = 0x10; i < 0x18; i++)
        {
            Party_GetMember(i + 0x8000);
            if (Combatant_IsUsed(i) == 1 && !Combatant_IsDead(i) && !Combatant_IsAlignmentCompatible(who, i))
            {
                BSTATE->targets[n].id = i;
                n++;
            }
        }
        BSTATE->targets[n].id = 0xFFFF;
        if (n != 0)
            return;
    }
    if ((u32)(mode + 1) <= 1)
        return;
    if (mode == 0x8000)
    {
        for (i = 0; i < 6; i++)
        {
            p = sub_080F40EC(i);
            if (p >= 0 && !Combatant_IsDead(p))
            {
                BSTATE->targets[n].id = p;
                n++;
            }
        }
    }
    else
    {
        for (i = 0; i < 6; i++)
        {
            p = sub_080F40EC(i);
            if (p >= 0 && !Combatant_IsDead(p))
            {
                s32 r;

                BSTATE->targets[n].id = p;
                r = Random_Byte();
                if (Party_GetRow(p) == 1)
                    r = r * 75 / 100;
                BSTATE->targets[n].key = -r;
                n++;
            }
        }
        Battle_SortEntriesInsertion(0, n, BSTATE->targets);
    }
    BSTATE->targets[n].id = 0xFFFF;
}
