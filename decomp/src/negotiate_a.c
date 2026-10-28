/* Demon negotiation reactions (0x08137AF8-0x081380DB): the outcomes picked by
   Negotiate_PickReaction from the per-personality table gUnknown_08790458. */

#include "global.h"
#include "scriptops2.h"

// sub_08137AF8 @ 0x08137AF8
s32 sub_08137AF8(s32 x)
{
    x = x * 10 + (Random_Byte() & 0xF);
    if (x == 0)
        x = 1;
    return x;
}

/* Scales an amount by (1..16)/12 and adds 10. */
// sub_08137B1C @ 0x08137B1C
u16 sub_08137B1C(u16 x)
{
    u16 q = (u16)(x * (u16)((Random_Byte() & 0xF) + 1)) / 12;

    return q + 10;
}

/* Reaction: the demon gives money. */
// Negotiate_ReactGiveMoney @ 0x08137B4C
void Negotiate_ReactGiveMoney(void)
{
    u16 v = sub_0813BDCC();

    Money_Add(gUnk_0203DB2C = sub_08137B1C(v));
    sub_0813B328(0x23);
}

// sub_08137B78 @ 0x08137B78
u16 sub_08137B78(u16 a, u16 n)
{
    u16 t = a >> 3;
    u16 s = 0;

    while (n > 6)
    {
        s += t;
        n--;
    }
    return s;
}

// sub_08137BA0 @ 0x08137BA0
u16 sub_08137BA0(a, n)
    u16 a, n;
{
    return sub_08137B78(a, n);
}

// sub_08137BB8 @ 0x08137BB8
u32 sub_08137BB8(void)
{
    u32 k = Demon_GetField(gUnk_0203DB7C, 0x1A) & 0xF;
    u32 x = (Demon_GetField(gUnk_0203DB7C, 0) & 0xFF) * 4;

    if (k > 7)
        return sub_08137BA0(x, k);
    return x * k;
}

/* Reaction: the demon gives magnetite. */
// sub_08137BF4 @ 0x08137BF4
void sub_08137BF4(void)
{
    u16 v = sub_08137BB8();

    Magnetite_Add(gUnk_0203DB2C = sub_08137B1C(v));
    sub_0813B328(0x24);
}

// sub_08137C20 @ 0x08137C20
void sub_08137C20(void)
{
    gScriptItemCheckId = 0xDB;
    sub_0813B328(0x25);
}

// sub_08137C38 @ 0x08137C38
void sub_08137C38(void)
{
    sub_0813B328(0x27);
}

/* Reaction: the demon gives its item (demon field 0x19, +0x100 when field 0x1D bit 0). */
// Negotiate_ReactGiveItem @ 0x08137C44
void Negotiate_ReactGiveItem(void)
{
    u32 item = Demon_GetField(gUnk_0203DB7C, 0x19) & 0xFF;

    if (item == 0xFF)
        goto fail;
    gScriptItemCheckId = item;
    gScriptItemCheckId += (Demon_GetField(gUnk_0203DB7C, 0x1D) & 1) << 8;
    if (gScriptItemCheckId > 0x11F)
    {
        if (!sub_0813B268())
        {
        fail:
            sub_08137C38();
            return;
        }
    }
    else
    {
        if ((u8)Inventory_IsMaxed(gScriptItemCheckId) == 1)
            goto fail;
        Inventory_AddItem(gScriptItemCheckId);
    }
    sub_0813B328(0x26);
}

// sub_08137CB4 @ 0x08137CB4
void sub_08137CB4(void)
{
    u16 v = Random_Byte() % 12;

    gScriptItemCheckId = v + 0x120;
    if (sub_0813B268())
        sub_0813B328(0x26);
    else
        Negotiate_ReactGiveItem();
}

// sub_08137CEC @ 0x08137CEC
void sub_08137CEC(void)
{
    gScriptItemCheckId = 0xE5;
    if (!(u8)Inventory_IsMaxed(0xE5))
    {
        Inventory_AddItem(gScriptItemCheckId);
        sub_0813B328(0x26);
    }
    else
        sub_08137CB4();
}

// sub_08137D20 @ 0x08137D20
void sub_08137D20(void)
{
    sub_0813B328(0x28);
}

// sub_08137D2C @ 0x08137D2C
#ifdef NONMATCHING
u32 sub_08137D2C(void)
{
    u32 r = 0;
    u32 hi = (Demon_GetField(gUnk_0203DB7C, 0x18) & 0xF0) >> 4;
    u32 lv = Demon_GetField(gUnk_0203DB7C, 0) & 0xFF;
    u16 x = lv * 4;
    s16 my;
    u16 d, n, i;

    if (hi > 7)
        r = (x >> 3) * (hi - 7);
    my = Combatant_GetLevel(0);
    if (my >= (s32)lv)
    {
        d = my - lv;
        if (d > 3)
            r /= d >> 2;
    }
    else
    {
        d = lv - my;
        if (d > 3)
        {
            n = d >> 2;
            if (n > 5)
                n = 5;
            for (i = 0; i < n; i++)
            {
                r <<= 1;
                if (r & 0x8000)
                    break;
            }
        }
    }
    return r;
}
#else
NAKED
u32 sub_08137D2C(void)
{
    asm_unified(
        ".L08137D2C:\n"
        "    push {r4, r5, r6, lr}\n"
        "    movs r5, #0\n"
        "    ldr r4, .L08137D84\n"
        "    ldrh r0, [r4]\n"
        "    movs r1, #0x18\n"
        "    bl Demon_GetField\n"
        "    movs r1, #0xf0\n"
        "    ands r1, r0\n"
        "    lsrs r6, r1, #4\n"
        "    ldrh r0, [r4]\n"
        "    movs r1, #0\n"
        "    bl Demon_GetField\n"
        "    movs r1, #0xff\n"
        "    ands r1, r0\n"
        "    adds r4, r1, #0\n"
        "    lsls r0, r4, #0x12\n"
        "    cmp r6, #7\n"
        "    bls .L08137D5C\n"
        "    lsrs r1, r0, #0x13\n"
        "    subs r0, r6, #7\n"
        "    adds r5, r1, #0\n"
        "    muls r5, r0, r5\n"
        ".L08137D5C:\n"
        "    movs r0, #0\n"
        "    bl Combatant_GetLevel\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, r4\n"
        "    blt .L08137D88\n"
        "    subs r0, r1, r4\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    cmp r1, #3\n"
        "    bls .L08137DBE\n"
        "    lsrs r1, r0, #0x12\n"
        "    adds r0, r5, #0\n"
        "    bl __udivsi3\n"
        "    adds r5, r0, #0\n"
        "    b .L08137DC0\n"
        "    .byte 0x00, 0x00\n"
        ".L08137D84: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L08137D88:\n"
        "    subs r0, r4, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    cmp r1, #3\n"
        "    bls .L08137DBE\n"
        "    lsrs r1, r0, #0x12\n"
        "    adds r2, r1, #0\n"
        "    cmp r2, #5\n"
        "    bls .L08137D9C\n"
        "    movs r2, #5\n"
        ".L08137D9C:\n"
        "    movs r1, #0\n"
        "    cmp r1, r2\n"
        "    bhs .L08137DBE\n"
        "    lsls r5, r5, #1\n"
        "    movs r3, #0x80\n"
        "    lsls r3, r3, #8\n"
        "    b .L08137DB6\n"
        ".L08137DAA:\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    cmp r1, r2\n"
        "    bhs .L08137DBE\n"
        "    lsls r5, r5, #1\n"
        ".L08137DB6:\n"
        "    adds r0, r5, #0\n"
        "    ands r0, r3\n"
        "    cmp r0, #0\n"
        "    beq .L08137DAA\n"
        ".L08137DBE:\n"
        "    adds r0, r5, #0\n"
        ".L08137DC0:\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// sub_08137DC8 @ 0x08137DC8
void sub_08137DC8(void)
{
    u32 v = sub_08137D2C();

    gUnk_0203DB2C = sub_08137B1C(v) >> 1;
    v = Battle_GetCombatant(0x8000)->unk08;
    v += gUnk_0203DB2C;
    if (v > 1676500)
        v = 1676500;
    Battle_GetCombatant(0x8000)->unk08 = v;
    sub_0813B328(0x2B);
}

// sub_08137E14 @ 0x08137E14
#ifdef NONMATCHING
void sub_08137E14(void)
{
    u32 kind = Demon_GetField(gUnk_0203DB7C, 0x1F) & 0xF0;
    s32 who;

    if (kind == 0x20 || kind == 0x60)
        goto refuse;
    if (Combatant_IsUsed(1) || Combatant_IsUsed(2))
    {
        if (Combatant_IsUsed(1))
            who = 1;
        else
            who = 2;
        if (!(Combatant_GetStatus(who) & 0xB000))
            goto no;
    }
    sub_08137DC8();
    return;
no:
    sub_0813B328(0x29);
    return;
refuse:
    sub_0813B328(0x2A);
}
#else
NAKED
void sub_08137E14(void)
{
    asm_unified(
        ".L08137E14:\n"
        "    push {lr}\n"
        "    ldr r0, .L08137E50\n"
        "    ldrh r0, [r0]\n"
        "    movs r1, #0x1f\n"
        "    bl Demon_GetField\n"
        "    movs r1, #0xf0\n"
        "    ands r1, r0\n"
        "    cmp r1, #0x20\n"
        "    beq .L08137E72\n"
        "    cmp r1, #0x60\n"
        "    beq .L08137E72\n"
        "    movs r0, #1\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    bne .L08137E40\n"
        "    movs r0, #2\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L08137E64\n"
        ".L08137E40:\n"
        "    movs r0, #1\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L08137E54\n"
        "    movs r0, #1\n"
        "    b .L08137E56\n"
        "    .byte 0x00, 0x00\n"
        ".L08137E50: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L08137E54:\n"
        "    movs r0, #2\n"
        ".L08137E56:\n"
        "    bl Combatant_GetStatus\n"
        "    movs r1, #0xb0\n"
        "    lsls r1, r1, #8\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L08137E6A\n"
        ".L08137E64:\n"
        "    bl sub_08137DC8\n"
        "    b .L08137E78\n"
        ".L08137E6A:\n"
        "    movs r0, #0x29\n"
        "    bl sub_0813B328\n"
        "    b .L08137E78\n"
        ".L08137E72:\n"
        "    movs r0, #0x2a\n"
        "    bl sub_0813B328\n"
        ".L08137E78:\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

/* Reaction: heals the first member at half HP or less, else cures the first ailment,
   else restores the first member at half MP or less; gives money when nobody needs it. */
// Negotiate_ReactHeal @ 0x08137E7C
void Negotiate_ReactHeal(void)
{
    s32 n = Stock_GetCapacity();
    u16 i, id, half;

    for (i = 0; i < n + 4; i++)
    {
        if (Combatant_IsUsed(i) && !(Combatant_GetStatus(i) & 0x8000))
        {
            id = i + 0x8000;
            half = Battle_GetCombatant(id)->maxHp >> 1;
            if (half >= Battle_GetCombatant(id)->hp)
                goto heal_hp;
        }
    }
    i = 0;
    n += 4;
    for (; i < n; i++)
    {
        if (Combatant_IsUsed(i))
        {
            half = Combatant_GetStatus(i);
            if (!(half & 0xC000) && (half & 0x3FFE))
                goto cure;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (Combatant_IsUsed(i) && !(Combatant_GetStatus(i) & 0x8000))
        {
            id = i + 0x8000;
            if (Battle_GetCombatant(id)->maxMp != 0)
            {
                half = Battle_GetCombatant(id)->maxMp >> 1;
                if (half >= Battle_GetCombatant(id)->mp)
                    goto heal_mp;
            }
        }
    }
    Negotiate_ReactGiveMoney();
    return;
heal_hp:
    Battle_GetCombatant(id)->hp = Battle_GetCombatant(id)->maxHp;
    goto done;
cure:
    Battle_GetCombatant(i + 0x8000)->flags &= 0xC001;
    goto done;
heal_mp:
    Battle_GetCombatant(id)->mp = Battle_GetCombatant(id)->maxMp;
done:
    sub_0813B328(0x2C);
}

// Negotiate_DoReaction @ 0x08137FCC
void Negotiate_DoReaction(u16 reaction)
{
    u8 saved = gUnk_0300685C;

    switch (reaction)
    {
    case 0:
        Negotiate_ReactHeal();
        break;
    case 1:
        Negotiate_ReactGiveMoney();
        break;
    case 2:
        sub_08137BF4();
        break;
    case 3:
        sub_08137C20();
        break;
    case 4:
        sub_08137CEC();
        break;
    case 5:
        sub_08137CB4();
        break;
    case 6:
        Negotiate_ReactGiveItem();
        break;
    case 7:
        sub_08137C38();
        break;
    case 8:
        sub_08137D20();
        break;
    case 9:
        sub_08137E14();
        break;
    case 10:
        sub_08137DC8();
        break;
    }
    gUnk_0300685C = saved;
    sub_0815BAC8(gUnk_0203DB7C, 1);
}

/* Picks a reaction from the 11-entry cumulative table of the demon's personality. */
// Negotiate_PickReaction @ 0x08138074
void Negotiate_PickReaction(void)
{
    u8 out[2];
    u16 i;
    u8 r;

    sub_0815B9B8(gUnk_0203DB7C, &out[0], &out[1]);
    i = out[0] * 11;
    r = Random_Byte();
next:
    if (gUnknown_08790458[i] < r)
    {
        i++;
        goto next;
    }
    Negotiate_DoReaction(i % 11);
}

// sub_081380CC @ 0x081380CC
void sub_081380CC(u16 reaction)
{
    Negotiate_DoReaction(reaction);
}
