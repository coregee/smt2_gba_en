#include "global.h"
#include "battle.h"

u16 Combatant_GetIntelligence(s32 who);
s32 sub_080ED7A4(s32 id);
s32 Battle_ApplyAffinity(s32 v, s32 aff);
u32 sub_080EFE60(s32 who);
s32 Battle_GetMaxMp(s32 who);

// Battle_RollAilment @ 0x080EEB94
/* Ailment skill `skill` from a->att on a->def: chance (out of 32) = att INT * skill power /
   def INT, scaled by the defender's affinity. Affinity 12/13 (and 14/15/0 when the defender
   has bit 0 of sub_080EFAB0 against a kind-7 attacker or a kind-11 magic skill 0x40-0x67)
   reflects the skill back on the attacker (message 0x16F for the party, 0x16E for enemies);
   other nullifying affinities cancel it. Queues the ailment with sub_080EDA7C on success.
   Returns 1 when the target already had the ailment. */
s32 Battle_RollAilment(struct Action *a, s32 skill)
{
    s32 had = 0;
    s32 att = a->att;
    s32 def = a->def;
    s32 chance;
    s32 aff;
    s32 n;
    u16 d;
    u16 ail;

    a->msg = -1;
    n = Combatant_GetIntelligence(att) * sub_080ED7A4(skill);
    d = Combatant_GetIntelligence(def);
    if (d == 0)
        d = 1;
    chance = n / d;
    sub_080EDA7C(0xFFFF);
    aff = Combatant_GetAffinity(def, sub_080EFE60(att));
    chance = Battle_ApplyAffinity(chance, aff);
    if ((u32)(aff - 12) <= 1)
    {
    reflect:
        def = att;
        a->def = a->att;
        a->msg = 0x16E;
        if (def <= 15)
            a->msg++;
        if (sub_080ED794(skill) & 0x8000)
        {
            n = Combatant_GetIntelligence(def) * sub_080ED7A4(skill);
            d = Combatant_GetIntelligence(def);
            if (d == 0)
                d = 1;
            chance = n / d;
            aff = Combatant_GetAffinity(def, sub_080EFE60(def));
            chance = Battle_ApplyAffinity(chance, aff);
            if ((u32)(aff - 12) <= 1 || aff == 15 || aff == 14 || aff == 0)
            {
                chance = 0;
                sub_080EDA7C(0);
            }
        }
    }
    else if ((u32)(aff - 14) <= 1 || aff == 0)
    {
        s32 kind = sub_080C35E4(att);
        s32 sk = Combatant_GetChosenSkill(att);
        u16 f = sub_080EFAB0(def);

        if (kind == 7 && (f & 1))
            goto reflect;
        if (kind == 11 && sk >= 0x40 && sk <= 0x67 && (f & 1))
            goto reflect;
        chance = 0;
        sub_080EDA7C(0);
    }
    if ((u16)Combatant_GetStatus(def) & sub_080ED794(skill))
        had = 1;
    if (chance != 0 && (u32)(Random_Byte() & 0x1F) < (u32)chance)
    {
        if (sub_080ED6A4(skill) == 7 && def <= 2)
            return had;
        ail = sub_080ED794(skill);
        if (sub_080F3214(def, ail) && (!(ail & 2) || Battle_GetMaxMp(def) != 0))
            sub_080EDA7C(ail);
    }
    return had;
}
