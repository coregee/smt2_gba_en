#include "global.h"
#include "battle.h"

// Battle_FinishDamage @ 0x080EE6BC
/* Final damage: race/luck multiplier, critical hits, defender modifiers and a random cut. */
#ifdef NONMATCHING
s32 Battle_FinishDamage(u8 *a, u8 *d, s32 power)
{
    s32 r = sub_080EDB04();
    struct BattleFlow *b = BFLOW;
    s32 race;
    s32 human;
    s32 k;

    b->unk11B0 = 0;
    if (*(s16 *)(a + 0x12) & 0x8000)
        race = 0;
    else
        race = Demon_GetRecord(*(u16 *)(a + 0x12))[0xD] & 0xF;
    power = (u16)((gUnknown_0876F6CA[race * 9 + r] * power) >> 4);
    k = r;
    human = *(s16 *)(a + 0x12) & 0x8000;
    if (!human)
        k = 8 - k;
    r = k * 2;
    r += (s8)a[0x45];
    r += (s8)a[0x44];
    if (!human)
        k = Demon_GetRecord(*(u16 *)(a + 0x12))[0x18];
    else
        k = 0;
    r += k * 8;
    /* r is now the threshold a d256 roll must reach for a critical hit */
    if ((u8)(a[0x17] - 4) <= 1 || a[0x17] == 10 || sub_080EED64((s8)a[0x17], a[0x5C]) == 1)
    {
        if (Random_Byte() >= r)
        {
            k = Random_Byte();  /* k is reused for the crit roll and the result */
            if ((u32)k <= 3)
            {
                power *= 3;
                b->unk11B0 = 1;
            }
            else if ((u32)k <= 15)
            {
                power *= 2;
                b->unk11B0 = 2;
            }
        }
    }
    if ((s8)d[0x17] == 9)
        power /= 2;
    /* r is reused for the random cut */
    r = (Random_Byte() & 0x1F) * power;
    r = (u32)r >> 7;
    k = power - r;
    if (k == 0 || (k & 0x8000))
        k = Random_Byte() & 1;
    power = k;
    if (power <= 0)
        power = 1;
    if (*(u16 *)(d + 0x10) & 0x4000)
        power = 0;
    return power;
}
#else
NAKED s32 Battle_FinishDamage(u8 *a, u8 *d, s32 power)
{
    asm_unified(
        ".L080EE6BC:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    adds r6, r0, #0\n"
        "    mov r8, r1\n"
        "    adds r5, r2, #0\n"
        "    bl sub_080EDB04\n"
        "    adds r4, r0, #0\n"
        "    ldr r7, .L080EE6EC\n"
        "    ldr r0, .L080EE6F0\n"
        "    adds r1, r7, r0\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    movs r1, #0x12\n"
        "    ldrsh r0, [r6, r1]\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080EE6F4\n"
        "    movs r2, #0\n"
        "    b .L080EE700\n"
        "    .byte 0x00, 0x00\n"
        ".L080EE6EC: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080EE6F0: .4byte 0x000011B0\n"
        ".L080EE6F4:\n"
        "    ldrh r0, [r6, #0x12]\n"
        "    bl Demon_GetRecord\n"
        "    ldrb r0, [r0, #0xd]\n"
        "    movs r2, #0xf\n"
        "    ands r2, r0\n"
        ".L080EE700:\n"
        "    ldr r1, .L080EE750\n"
        "    lsls r0, r2, #3\n"
        "    adds r0, r0, r2\n"
        "    adds r0, r0, r4\n"
        "    adds r0, r0, r1\n"
        "    ldrb r0, [r0]\n"
        "    muls r0, r5, r0\n"
        "    lsls r0, r0, #0xc\n"
        "    lsrs r5, r0, #0x10\n"
        "    adds r1, r4, #0\n"
        "    movs r0, #0x12\n"
        "    ldrsh r2, [r6, r0]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #8\n"
        "    ands r2, r0\n"
        "    cmp r2, #0\n"
        "    bne .L080EE726\n"
        "    movs r0, #8\n"
        "    subs r1, r0, r1\n"
        ".L080EE726:\n"
        "    lsls r4, r1, #1\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x45\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    adds r4, r4, r0\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x44\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    adds r4, r4, r0\n"
        "    cmp r2, #0\n"
        "    bne .L080EE754\n"
        "    ldrh r0, [r6, #0x12]\n"
        "    bl Demon_GetRecord\n"
        "    ldrb r1, [r0, #0x18]\n"
        "    b .L080EE756\n"
        "    .byte 0x00, 0x00\n"
        ".L080EE750: .4byte gUnknown_0876F6CA\n"
        ".L080EE754:\n"
        "    movs r1, #0\n"
        ".L080EE756:\n"
        "    lsls r0, r1, #3\n"
        "    adds r4, r4, r0\n"
        "    ldrb r1, [r6, #0x17]\n"
        "    subs r0, r1, #4\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bls .L080EE780\n"
        "    cmp r1, #0xa\n"
        "    beq .L080EE780\n"
        "    movs r0, #0x17\n"
        "    ldrsb r0, [r6, r0]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    adds r1, r6, #0\n"
        "    adds r1, #0x5c\n"
        "    ldrb r1, [r1]\n"
        "    bl sub_080EED64\n"
        "    cmp r0, #1\n"
        "    bne .L080EE7B2\n"
        ".L080EE780:\n"
        "    bl Random_Byte\n"
        "    cmp r0, r4\n"
        "    blo .L080EE7B2\n"
        "    bl Random_Byte\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #3\n"
        "    bhi .L080EE7A4\n"
        "    lsls r0, r5, #1\n"
        "    adds r5, r0, r5\n"
        "    ldr r0, .L080EE7A0\n"
        "    adds r1, r7, r0\n"
        "    movs r0, #1\n"
        "    b .L080EE7B0\n"
        "    .byte 0x00, 0x00\n"
        ".L080EE7A0: .4byte 0x000011B0\n"
        ".L080EE7A4:\n"
        "    cmp r1, #0xf\n"
        "    bhi .L080EE7B2\n"
        "    lsls r5, r5, #1\n"
        "    ldr r0, .L080EE80C\n"
        "    adds r1, r7, r0\n"
        "    movs r0, #2\n"
        ".L080EE7B0:\n"
        "    strh r0, [r1]\n"
        ".L080EE7B2:\n"
        "    mov r1, r8\n"
        "    movs r0, #0x17\n"
        "    ldrsb r0, [r1, r0]\n"
        "    cmp r0, #9\n"
        "    bne .L080EE7C2\n"
        "    lsrs r0, r5, #0x1f\n"
        "    adds r0, r5, r0\n"
        "    asrs r5, r0, #1\n"
        ".L080EE7C2:\n"
        "    bl Random_Byte\n"
        "    movs r1, #0x1f\n"
        "    ands r1, r0\n"
        "    muls r1, r5, r1\n"
        "    lsrs r4, r1, #7\n"
        "    subs r1, r5, r4\n"
        "    cmp r1, #0\n"
        "    beq .L080EE7DE\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #8\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080EE7E8\n"
        ".L080EE7DE:\n"
        "    bl Random_Byte\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #1\n"
        "    ands r1, r0\n"
        ".L080EE7E8:\n"
        "    adds r5, r1, #0\n"
        "    cmp r5, #0\n"
        "    bgt .L080EE7F0\n"
        "    movs r5, #1\n"
        ".L080EE7F0:\n"
        "    mov r0, r8\n"
        "    ldrh r1, [r0, #0x10]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #7\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080EE800\n"
        "    movs r5, #0\n"
        ".L080EE800:\n"
        "    adds r0, r5, #0\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        ".L080EE80C: .4byte 0x000011B0\n"
    );
}
#endif

// sub_080EE810 @ 0x080EE810
s16 sub_080EE810(s32 id, s32 who)
{
    u16 i;
    u16 x = id;

    for (i = 0; i < 12; i++)
    {
        if (gUnknown_0876F75A[i][0] == x)
        {
            s32 r = Combatant_GetAffinity(who, gUnknown_0876F75A[i][1]);

            if (r == 12 || r == 13)
                return 0;
            if (r == 14 || r == 15)
                return 0;
            if (r == 0)
                return 0;
            return 1;
        }
    }
    return 0;
}

// Battle_PhysicalDamage @ 0x080EE864
/* Physical attack damage of att on def. */
s32 Battle_PhysicalDamage(s32 att, s32 def)
{
    u8 *a = Battle_GetCombatant(att + 0x8000);
    u8 *d = Battle_GetCombatant(def + 0x8000);
    s32 kind = (s8)a[0x17];
    s32 pow;
    s32 dv;
    s32 v;
    s32 i;
    u16 w;

    if (att > 3)
        pow = *(s16 *)(a + 0x48);
    else if (kind == 4)
    {
        if (Random_Byte() <= 0x3F)
        {
            v = Combatant_GetEquip(att, 0);
            if (v != 0xFF)
            {
                Item_GetAttribute(v, 6, &v);
                w = v;
                w &= 0xFFFE;
                if (w != 0 && sub_080F3214(def, w) && sub_080EE810(w, def))
                    sub_080EDA7C(w);
            }
        }
        pow = *(s16 *)(a + 0x48);
    }
    else
    {
        if (Random_Byte() <= 0x3F)
        {
            v = Combatant_GetEquip(att, 6);
            if (v != 0xFF)
            {
                Item_GetAttribute(v, 6, &v);
                w = v;
                if (sub_080F3214(def, w) && sub_080EE810(w, def))
                    sub_080EDA7C(w);
            }
        }
        pow = *(s16 *)(a + 0x4C);
    }
    if (*(u16 *)(a + 0x10) & 4)
        pow >>= 1;
    i = sub_080EFBFC(att) + 4;
    pow = pow * gUnknown_0876F78E[i] / 8;
    i = sub_080EFD3C(def) + 4;
    dv = *(s16 *)(d + 0x50) * gUnknown_0876F78E[i] / 8;
    pow *= Math_DivRound(pow, 4) + 4;
    pow /= dv;
    if (kind == 11)
        pow += sub_080BF5C0(Combatant_GetChosenSkill(att))[1] * pow / 100;
    pow = Battle_FinishDamage(a, d, pow);
    return pow;
}

// Battle_SkillDamage @ 0x080EE9F8
/* Damage of a skill: magic formula for ids up to 0x67 and 0x9B-0x9C, physical otherwise.
   The defender's magic defence term is capped at 255. */
#ifdef NONMATCHING
void Battle_SkillDamage(struct Action *act)
{
    s32 att = act->att;
    s32 def = act->def;
    s32 skill = Combatant_GetChosenSkill(att);
    u16 ailment = sub_080ED794(skill);
    u8 *a = Battle_GetCombatant(att + 0x8000);
    u8 *d = Battle_GetCombatant(def + 0x8000);
    s32 dmg;
    u32 i;
    u8 k;

    if ((u32)(skill - 0x9B) <= 1 || skill <= 0x67)
    {
        u16 dv, pw, t;

        t = *(u16 *)(d + 0x54);
        dv = (u16)((t * gUnknown_0876F78E[sub_080EFDCC(def) + 4]) >> 3);
        t = *(u16 *)(d + 0x50);
        dv += (u16)((t * gUnknown_0876F78E[sub_080EFD3C(def) + 4]) >> 3) >> 2;
        if ((u32)(skill - 0x9B) <= 1)
            t = *(u16 *)(a + 0x48);
        else
            t = *(u16 *)(a + 0x54);
        pw = (u16)((t * gUnknown_0876F78E[sub_080EFDCC(att) + 4]) >> 3);
        pw = pw * sub_080BF5C0(skill)[1];
        if (dv > 0xFF)
            dv = 0xFF;
        pw = pw / dv;
        if (pw & 0x8000)
            pw = 0;
        dmg = Battle_FinishDamage(a, d, pw);
    }
    else
        dmg = Battle_PhysicalDamage(att, def);
    if (Random_Byte() <= 0x3F && sub_080F3214(def, ailment) && sub_080EE810(ailment, def))
        sub_080EDA7C(ailment);
    k = skill - 0x5C;
    for (i = 0; i < 32; i++)
    {
        if (skill == gUnknown_0876F79E[i])
        {
            act->dmg = dmg;
            sub_080F49B4(act, i);
            dmg = act->dmg;
            if (k > 1 && (u8)skill != 0x54 && (u8)skill != 0x55 && (u8)skill != 0x5E
                && (u8)skill != 0x61 && (u8)skill != 0x98 && (u8)skill != 0x9B && (u8)skill != 0x9C)
                dmg = 0xFFFF;
        }
    }
    act->dmg = dmg;
}
#else
NAKED void Battle_SkillDamage(struct Action *act)
{
    asm_unified(
        ".L080EE9F8:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0xc\n"
        "    adds r7, r0, #0\n"
        "    ldr r0, [r7]\n"
        "    mov r8, r0\n"
        "    ldr r1, [r7, #4]\n"
        "    mov sb, r1\n"
        "    bl Combatant_GetChosenSkill\n"
        "    adds r6, r0, #0\n"
        "    bl sub_080ED794\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp]\n"
        "    ldr r2, .L080EEA94\n"
        "    adds r4, r2, #0\n"
        "    mov r1, r8\n"
        "    adds r0, r1, r4\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    str r0, [sp, #4]\n"
        "    add r4, sb\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    mov sl, r0\n"
        "    adds r2, r6, #0\n"
        "    subs r2, #0x9b\n"
        "    str r2, [sp, #8]\n"
        "    cmp r2, #1\n"
        "    bls .L080EEA4C\n"
        "    cmp r6, #0x67\n"
        "    bgt .L080EEAF4\n"
        ".L080EEA4C:\n"
        "    mov r0, sl\n"
        "    adds r0, #0x54\n"
        "    ldrh r4, [r0]\n"
        "    mov r0, sb\n"
        "    bl sub_080EFDCC\n"
        "    adds r1, r0, #4\n"
        "    ldr r2, .L080EEA98\n"
        "    adds r0, r1, r2\n"
        "    ldrb r0, [r0]\n"
        "    muls r0, r4, r0\n"
        "    lsls r0, r0, #0xd\n"
        "    lsrs r5, r0, #0x10\n"
        "    mov r0, sl\n"
        "    adds r0, #0x50\n"
        "    ldrh r4, [r0]\n"
        "    mov r0, sb\n"
        "    bl sub_080EFD3C\n"
        "    adds r1, r0, #4\n"
        "    ldr r2, .L080EEA98\n"
        "    adds r0, r1, r2\n"
        "    ldrb r0, [r0]\n"
        "    muls r0, r4, r0\n"
        "    lsls r0, r0, #0xd\n"
        "    lsrs r0, r0, #0x12\n"
        "    adds r0, r5, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    ldr r0, [sp, #8]\n"
        "    cmp r0, #1\n"
        "    bhi .L080EEA9C\n"
        "    ldr r0, [sp, #4]\n"
        "    adds r0, #0x48\n"
        "    b .L080EEAA0\n"
        "    .byte 0x00, 0x00\n"
        ".L080EEA94: .4byte 0xFFFF8000\n"
        ".L080EEA98: .4byte gUnknown_0876F78E\n"
        ".L080EEA9C:\n"
        "    ldr r0, [sp, #4]\n"
        "    adds r0, #0x54\n"
        ".L080EEAA0:\n"
        "    ldrh r4, [r0]\n"
        "    mov r0, r8\n"
        "    bl sub_080EFDCC\n"
        "    adds r1, r0, #4\n"
        "    ldr r0, .L080EEAF0\n"
        "    adds r0, r1, r0\n"
        "    ldrb r0, [r0]\n"
        "    muls r0, r4, r0\n"
        "    lsls r0, r0, #0xd\n"
        "    lsrs r4, r0, #0x10\n"
        "    lsls r0, r6, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl sub_080BF5C0\n"
        "    ldrb r0, [r0, #1]\n"
        "    muls r0, r4, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r5, #0xff\n"
        "    bls .L080EEACC\n"
        "    movs r5, #0xff\n"
        ".L080EEACC:\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r5, #0\n"
        "    bl __udivsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #8\n"
        "    ands r0, r4\n"
        "    cmp r0, #0\n"
        "    beq .L080EEAE4\n"
        "    movs r4, #0\n"
        ".L080EEAE4:\n"
        "    ldr r0, [sp, #4]\n"
        "    mov r1, sl\n"
        "    adds r2, r4, #0\n"
        "    bl Battle_FinishDamage\n"
        "    b .L080EEAFC\n"
        ".L080EEAF0: .4byte gUnknown_0876F78E\n"
        ".L080EEAF4:\n"
        "    mov r0, r8\n"
        "    mov r1, sb\n"
        "    bl Battle_PhysicalDamage\n"
        ".L080EEAFC:\n"
        "    adds r4, r0, #0\n"
        "    bl Random_Byte\n"
        "    cmp r0, #0x3f\n"
        "    bhi .L080EEB28\n"
        "    mov r0, sb\n"
        "    ldr r1, [sp]\n"
        "    bl sub_080F3214\n"
        "    lsls r0, r0, #0x18\n"
        "    cmp r0, #0\n"
        "    beq .L080EEB28\n"
        "    ldr r0, [sp]\n"
        "    mov r1, sb\n"
        "    bl sub_080EE810\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L080EEB28\n"
        "    ldr r0, [sp]\n"
        "    bl sub_080EDA7C\n"
        ".L080EEB28:\n"
        "    movs r5, #0\n"
        "    adds r0, r6, #0\n"
        "    subs r0, #0x5c\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    mov r8, r0\n"
        ".L080EEB34:\n"
        "    ldr r0, .L080EEB8C\n"
        "    adds r0, r5, r0\n"
        "    ldrb r0, [r0]\n"
        "    cmp r6, r0\n"
        "    bne .L080EEB72\n"
        "    str r4, [r7, #0x18]\n"
        "    adds r0, r7, #0\n"
        "    adds r1, r5, #0\n"
        "    bl sub_080F49B4\n"
        "    ldr r4, [r7, #0x18]\n"
        "    mov r1, r8\n"
        "    cmp r1, #1\n"
        "    bls .L080EEB72\n"
        "    lsls r0, r6, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #0x54\n"
        "    beq .L080EEB72\n"
        "    cmp r0, #0x55\n"
        "    beq .L080EEB72\n"
        "    cmp r0, #0x5e\n"
        "    beq .L080EEB72\n"
        "    cmp r0, #0x61\n"
        "    beq .L080EEB72\n"
        "    cmp r0, #0x98\n"
        "    beq .L080EEB72\n"
        "    cmp r0, #0x9b\n"
        "    beq .L080EEB72\n"
        "    cmp r0, #0x9c\n"
        "    beq .L080EEB72\n"
        "    ldr r4, .L080EEB90\n"
        ".L080EEB72:\n"
        "    adds r5, #1\n"
        "    cmp r5, #0x1f\n"
        "    bls .L080EEB34\n"
        "    str r4, [r7, #0x18]\n"
        "    add sp, #0xc\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080EEB8C: .4byte gUnknown_0876F79E\n"
        ".L080EEB90: .4byte 0x0000FFFF\n"
    );
}
#endif

