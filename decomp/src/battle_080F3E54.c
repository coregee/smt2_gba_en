#include "global.h"
#include "battle2.h"

// sub_080F3E54 @ 0x080F3E54
/* Calls Inventory_AddItem(id) n times, or Inventory_RemoveItem(id) -n times; returns n. */
s32 sub_080F3E54(s32 id, s32 n)
{
    s32 i;

    if (n == 0)
        return 0;
    if (n > 0)
    {
        for (i = 0; i < n; i++)
            Inventory_AddItem(id);
    }
    else
    {
        for (i = 0; i > n; i--)
            Inventory_RemoveItem(id);
    }
    return n;
}

// sub_080F3E98 @ 0x080F3E98
u32 sub_080F3E98(u32 n)
{
    if (Money_Get() >= n)
        return 1;
    return 0;
}

// sub_080F3EB0 @ 0x080F3EB0
u32 sub_080F3EB0(u32 n)
{
    if (Magnetite_Get() >= n)
        return 1;
    return 0;
}

// Combatant_IsInParty @ 0x080F3EC8
s32 Combatant_IsInParty(s32 who)
{
    if (Battle_GetCombatant(who - 0x8000u)->unkE & 0x4000)
        return 1;
    return 0;
}

// Combatant_SetChosenSkill @ 0x080F3EF4
void Combatant_SetChosenSkill(s32 who, u8 skill)
{
    Battle_GetCombatant(who - 0x8000u)->unk5C = skill;
}

// Combatant_GetChosenSkill @ 0x080F3F14
s32 Combatant_GetChosenSkill(s32 who)
{
    return Battle_GetCombatant(who - 0x8000u)->unk5C;
}

// BattleFlags_Set @ 0x080F3F30
void BattleFlags_Set(u16 f)
{
    gGameState.unk1146 = f;
}

// BattleFlags_Get @ 0x080F3F44
u32 BattleFlags_Get(void)
{
    return gGameState.unk1146;
}

// BattleFlags_Mask @ 0x080F3F58
/* K&R definition: some callers pass the mask as a negative int. */
void BattleFlags_Mask(mask)
    u16 mask;
{
    gGameState.unk1146 &= mask;
}

// BattleFlags_Add @ 0x080F3F74
void BattleFlags_Add(u16 mask)
{
    gGameState.unk1146 |= mask;
}

// Combatant_GetAffinity @ 0x080F3F90
/* Affinity code of a combatant against attack kind `kind` (see Battle_ApplyAffinity): party
   members use the best of their four armour slots (8 = neutral), others their race. */
s32 Combatant_GetAffinity(s32 who, s32 kind)
{
    s32 best = 1000;
    s32 i;
    s32 item;
    s32 r;

    if (who <= 15 && (BattleFlags_Get() & 0x200))
    {
        BattleFlags_Mask(0xFDFF);
        return 0;
    }
    if (who <= 3)
    {
        for (i = 0; i < 4; i++)
        {
            item = Combatant_GetEquip(who, i + 2);
            if (item != 0xFF)
            {
                Item_GetAttribute(item, 7, &item);
                r = sub_080ED3D0(item, kind);
                if (r > 11)
                    return r;
                if (r < best)
                    best = r;
            }
        }
        if (best == 1000)
            return 8;
        return best;
    }
    return sub_080ED3D0(sub_080ED494(Combatant_GetDemonId(who)), kind);
}

// Battle_GetHp @ 0x080F401C
s32 Battle_GetHp(s32 who)
{
    return Battle_GetCombatant(who - 0x8000u)->hp;
}

// Battle_GetMaxHp @ 0x080F4038
s32 Battle_GetMaxHp(s32 who)
{
    return Battle_GetCombatant(who - 0x8000u)->maxHp;
}

// Battle_SetHp @ 0x080F4054
void Battle_SetHp(s32 who, s32 v)
{
    Battle_GetCombatant(who - 0x8000u)->hp = v;
}

// Battle_GetMp @ 0x080F4070
s32 Battle_GetMp(s32 who)
{
    return Battle_GetCombatant(who - 0x8000u)->mp;
}

// Battle_SetMp @ 0x080F408C
void Battle_SetMp(s32 who, s32 v)
{
    Battle_GetCombatant(who - 0x8000u)->mp = v;
}

// Battle_GetMaxMp @ 0x080F40A8
s32 Battle_GetMaxMp(s32 who)
{
    return Battle_GetCombatant(who - 0x8000u)->maxMp;
}

// sub_080F40C4 @ 0x080F40C4
void sub_080F40C4(s16 v)
{
    struct BattleFlow *b = BFLOW;

    b->unk113C = v;
}

// sub_080F40D8 @ 0x080F40D8
s16 sub_080F40D8(void)
{
    struct BattleFlow *b = BFLOW;

    return b->unk113C;
}

// sub_080F40EC @ 0x080F40EC
s32 sub_080F40EC(s32 slot)
{
    return gGameState.order[slot];
}

// Combatant_ClearSlot @ 0x080F4104
void Combatant_ClearSlot(s32 who)
{
    Battle_GetCombatant(who - 0x8000u)->unkE = 0;
}

// Combatant_SetStocked @ 0x080F4120
void Combatant_SetStocked(s32 who)
{
    Battle_GetCombatant(who - 0x8000u)->unkE = 0x8000;
}

// sub_080F413C @ 0x080F413C
void sub_080F413C(void)
{
    s32 d;
    u32 m = sub_080C0794();

    if (m == 0)
        d = -25;
    else if (m == 2)
        d = 25;
    else
        return;
    Combatant_AddAlignment(0, d);
    Combatant_AddAlignment(1, d);
}

// sub_080F4168 @ 0x080F4168
void sub_080F4168(s32 who, s32 slot)
{
    sub_080F413C();
    Party_AddAt(who, slot);
    Party_BuildMemberNameTiles();
    sub_080C6FD8();
}

// sub_080F4190 @ 0x080F4190
void sub_080F4190(s32 who)
{
    Party_Remove(who, 0);
    Combatant_ClearStatus(who, 0xB000);
}

// sub_080F41B0 @ 0x080F41B0
void sub_080F41B0(s32 who)
{
    s32 d;

    Party_Remove(who, 1);
    Combatant_ClearSlot(who);
    if (Combatant_GetStatus(who))
        d = 100;
    else
        d = 25;
    Combatant_AddAlignment(0, d);
    Combatant_AddAlignment(1, d);
    Combatant_SetStatus(who, 0);
}

// Party_GetSkillCount @ 0x080F41F4
/* Number of skills a party member knows: (level * 2 + stat1 + stat2) / 8, capped per member
   by gUnknown_0876F87C (0 for the hero). */
s32 Party_GetSkillCount(s32 who)
{
    u8 caps[4];
    struct Combatant *c;
    s32 n;

    memcpy(caps, gUnknown_0876F87C, 4);
    c = Battle_GetCombatant(who - 0x8000u);
    if (who == 0)
        return 0;
    n = (c->level * 2 + c->base[1] + c->base[2]) / 8;
    if (n > caps[who])
        n = caps[who];
    return n;
}

// Party_BuildSkillList @ 0x080F4260
/* Fills a party member's skill list from gUnknown_0876F880 (same count formula as above). */
void Party_BuildSkillList(s32 who)
{
    struct Combatant *c = Battle_GetCombatant(who - 0x8000u);
    u32 i;
    s32 n;

    for (i = 0; i < 32; i++)
        c->skills[i] |= 0xFF;
    if (who != 0)
    {
        n = (c->level * 2 + c->base[1] + c->base[2]) / 8;
        i = 0;
        do
        {
            c->skills[i] = gUnknown_0876F880[i];
            if (c->skills[i] == 0xFF)
                break;
            i++;
        } while (--n != 0);
        c->skills[i] = 0xFF;
    }
}

// Combatant_GetSkill @ 0x080F42E0
u8 Combatant_GetSkill(s32 who, s32 i)
{
    return Battle_GetCombatant(who - 0x8000u)->skills[i];
}

// Combatant_CountSkillsWithFlags @ 0x080F4300
/* Counts a combatant's skills whose sub_080ED6B8 bits intersect `mask`. */
s32 Combatant_CountSkillsWithFlags(s32 who, u8 mask)
{
    s32 i = 0;
    s32 n = 0;
    u8 s;

    if (who > 3)
    {
        for (i = 0; i < 7; i++)
        {
            s = Combatant_GetSkill(who, i);
            if (s != 0xFF)
            {
                if (s < 0x40 && (sub_080ED6B8(s) & mask))
                    n++;
            }
        }
    }
    else
    {
        while ((s = Combatant_GetSkill(who, i)) != 0xFF)
        {
            if (sub_080ED6B8(s) & mask)
                n++;
            i++;
        }
    }
    return n;
}

// sub_080F4360 @ 0x080F4360
/* 1 when any used combatant 4-11 has `skill` in its list. */
u32 sub_080F4360(u8 skill)
{
    u32 i;
    u32 j;

    for (i = 4; i < 12; i++)
    {
        struct Combatant *c = Battle_GetCombatant(i + 0x8000);

        if (c->unkE)
        {
            for (j = 0; j < 32; j++)
            {
                if (c->skills[j] == skill)
                    return 1;
            }
        }
    }
    return 0;
}

// sub_080F43A4 @ 0x080F43A4
s32 sub_080F43A4(s32 x)
{
    s32 best = 0;
    s32 i;
    s8 *order;

    for (i = 0, order = gUnk_030050E0; i < 6; i++)
    {
        s32 m = *(s8 *)(i + (u32)order);

        if (m != -1)
        {
            u16 v = Combatant_GetStat(m, x);
            if (v > best)
                best = v;
        }
    }
    return best;
}

// sub_080F43E0 @ 0x080F43E0
s32 sub_080F43E0(s32 x)
{
    s32 best = Combatant_GetStat(0x10, x);

    if (Battle_IsTwoSided())
    {
        u16 v = Combatant_GetStat(0x14, x);
        if (v > best)
            best = v;
    }
    return best;
}

// sub_080F4410 @ 0x080F4410
s16 sub_080F4410(s16 who)
{
    if (!Combatant_CountSkillsWithFlags(who, 0xE0))
        return 0;
    if (Combatant_GetStatus(who) & 0xB063)
        return 1;
    return 2;
}

// sub_080F4444 @ 0x080F4444
u32 sub_080F4444(void)
{
    u32 r = 0;
    s16 i;

    for (i = 0; i < 6; i++)
    {
        s16 m = sub_080F40EC(i);

        if (m != -1)
        {
            if (m <= 3)
                Party_BuildSkillList(m);
            if (sub_080F4410(m) == 2)
                r = 1;
        }
    }
    return r;
}

// Battle_FindPartyPosition @ 0x080F4490
/* Party position of member `who` (-1 when not in the party). */
s16 Battle_FindPartyPosition(s16 who)
{
    s16 n = 0;
    s16 i;

    for (i = 0; i < 6; i++)
    {
        if (gUnk_030050E0[i] == who)
            return n;
        n++;
    }
    return -1;
}

// Battle_CopyEnemyUnit @ 0x080F44D8
/* Copies enemy unit `src` (0x10-0x17) into unit slot `dst`. */
void Battle_CopyEnemyUnit(s32 src, s32 dst)
{
    struct BattleFlow *b = BFLOW;

    /* &b->units[dst - 16] and &b->units[src - 16], spelled so the index is not folded */
    memcpy((u8 *)(((dst - 16) << 7) + (u32)b) + 0x9A0, (u8 *)(((src - 16) << 7) + (u32)b) + 0x9A0, 0x80);
}
