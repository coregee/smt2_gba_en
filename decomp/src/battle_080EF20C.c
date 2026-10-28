#include "global.h"
#include "battle.h"

// sub_080EF20C @ 0x080EF20C
void sub_080EF20C(s32 a)
{
    Battle_RemoveDefeated(a, 0);
}

// sub_080EF218 @ 0x080EF218
void sub_080EF218(s32 a)
{
    Battle_RemoveDefeated(a, 1);
}

// sub_080EF224 @ 0x080EF224
/* Puts up to count new enemies into free enemy slots. */
u32 sub_080EF224(s32 pos, s32 count)
{
    u32 added = 0;
    s32 base = 0x10;
    s32 i;

    if (count >= 0)
        sub_08126834(count);
    if (Battle_IsTwoSided() && pos > 0x13)
        base = 0x14;
    for (i = base; i < base + 8; i++)
    {
        if (Combatant_IsAlive(i))
            continue;
        Battle_CopyEnemyUnit(base, i);
        Combatant_SetStatus(i, 0);
        Combatant_RestoreHp(i);
        Combatant_RestoreMp(i);
        added = 1;
        if (--count == 0)
            break;
    }
    if (added == 1)
        sub_080E760C();
    return added;
}

// sub_080EF2A0 @ 0x080EF2A0
void sub_080EF2A0(void)
{
    s32 i, j, who;
    s8 *party;

    for (i = 0, party = gUnk_030050E0; i < 6; i++)
    {
        who = *(s8 *)(i + (u32)party);
        if (who >= 0)
        {
            for (j = 0; j < 4; j++)
                if (Random_Byte() < gUnknown_0876F7C6[j])
                    Combatant_ClearStatus(who, gUnknown_0876F7BE[j]);
        }
    }
    Combatant_ClearStatus(0, 0xFFBF);
    Combatant_ClearStatus(1, 0xFFBF);
    for (i = 0; i < 8; i++)
    {
        who = i + 0x10;
        for (j = 0; j < 4; j++)
            if (Random_Byte() < gUnknown_0876F7C6[j])
                Combatant_ClearStatus(who, gUnknown_0876F7BE[j]);
    }
    for (i = 0; i < 14; i++)
        BSTATE->unk78[0][i] &= ~0x23;
}

// sub_080EF364 @ 0x080EF364
void sub_080EF364(void)
{
    s32 i;
    s8 *party;

    for (i = 0, party = gUnk_030050E0; i < 6; i++)
    {
        s32 who = *(s8 *)(i + (u32)party);

        if (who >= 0)
        {
            u16 m = 0x398;

            if (who <= 3)
                m |= 0x40;
            Combatant_ClearStatus(who, m ^ 0xFFFF);
        }
    }
}

// sub_080EF3A0 @ 0x080EF3A0
s32 sub_080EF3A0(s32 a, s32 b)
{
    if (a == 0)
        return 0;
    if (a > 7)
        return b / 8 * (a - 7);
    return b * a;
}

// sub_080EF3C8 @ 0x080EF3C8
#ifdef NONMATCHING
s32 sub_080EF3C8(s32 id)
{
    u8 *rec = Demon_GetRecord(id);
    u16 v;

    if (Flag_Test(1) || Flag_Test(0xD5) || Flag_Test(0xB7))
        return -1;
    v = rec[0x19] & 0xF;
    if (v == 0)
        return -1;
    v = (u16)(v * v) >> 1;
    if (v == 0)
        v = 1;
    if ((Random_Byte() & 0xFF) >= v)
        return -1;
    v = rec[0x1F] & 1;
    v = (u16)((v << 8) | rec[0x1A]);
    return v;
}
#else
NAKED s32 sub_080EF3C8(s32 id)
{
    asm_unified(
        ".L080EF3C8:\n"
        "    push {r4, r5, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Demon_GetRecord\n"
        "    adds r5, r0, #0\n"
        "    movs r0, #1\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L080EF42A\n"
        "    movs r0, #0xd5\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L080EF42A\n"
        "    movs r0, #0xb7\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L080EF42A\n"
        "    ldrb r0, [r5, #0x19]\n"
        "    movs r4, #0xf\n"
        "    ands r4, r0\n"
        "    cmp r4, #0\n"
        "    beq .L080EF42A\n"
        "    adds r0, r4, #0\n"
        "    muls r0, r4, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x11\n"
        "    cmp r4, #0\n"
        "    bne .L080EF40A\n"
        "    movs r4, #1\n"
        ".L080EF40A:\n"
        "    bl Random_Byte\n"
        "    movs r1, #0xff\n"
        "    ands r0, r1\n"
        "    cmp r0, r4\n"
        "    bhs .L080EF42A\n"
        "    ldrb r4, [r5, #0x1f]\n"
        "    movs r0, #1\n"
        "    ands r4, r0\n"
        "    lsls r0, r4, #8\n"
        "    ldrb r4, [r5, #0x1a]\n"
        "    orrs r4, r0\n"
        "    lsls r0, r4, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    adds r0, r4, #0\n"
        "    b .L080EF42E\n"
        ".L080EF42A:\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        ".L080EF42E:\n"
        "    pop {r4, r5}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

// sub_080EF434 @ 0x080EF434
#ifdef NONMATCHING
u32 sub_080EF434(s32 id)
{
    u8 *rec = Demon_GetRecord(id);
    u8 x;
    u32 n;

    if (Flag_Test(1) || Flag_Test(0xD5) || Flag_Test(0xB7))
        return 0;
    x = rec[0x1F] & 0xF0;
    if (x == 0)
        return 0;
    x >>= 4;
    n = x * x;
    n >>= 1;
    if ((u16)((u32)(rand() & 0xFF) % 0xC0) >= n)
        return 0;
    return 1;
}
#else
NAKED u32 sub_080EF434(s32 id)
{
    asm_unified(
        ".L080EF434:\n"
        "    push {r4, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Demon_GetRecord\n"
        "    adds r4, r0, #0\n"
        "    movs r0, #1\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L080EF48C\n"
        "    movs r0, #0xd5\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L080EF48C\n"
        "    movs r0, #0xb7\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L080EF48C\n"
        "    ldrb r1, [r4, #0x1f]\n"
        "    movs r0, #0xf0\n"
        "    ands r0, r1\n"
        "    lsls r0, r0, #0x18\n"
        "    cmp r0, #0\n"
        "    beq .L080EF48C\n"
        "    lsrs r0, r0, #0x1c\n"
        "    adds r4, r0, #0\n"
        "    muls r4, r0, r4\n"
        "    lsrs r4, r4, #1\n"
        "    bl rand\n"
        "    movs r1, #0xff\n"
        "    ands r0, r1\n"
        "    movs r1, #0xc0\n"
        "    bl __umodsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, r4\n"
        "    bhs .L080EF48C\n"
        "    movs r0, #1\n"
        "    b .L080EF48E\n"
        ".L080EF48C:\n"
        "    movs r0, #0\n"
        ".L080EF48E:\n"
        "    pop {r4}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

// sub_080EF494 @ 0x080EF494
u16 sub_080EF494(u16 lvl, s32 id)
{
    u16 dlvl = sub_080ED560(id);
    u8 *rec = Demon_GetRecord(id);
    u8 b = rec[0x19];
    u16 v = b >> 4;
    u16 s;

    if (v == 0)
        return 0;
    v += dlvl << 8;
    v = sub_080F030C(v, b);
    if (lvl < dlvl)
    {
        for (s = (u16)(dlvl - lvl) >> 2; s != 0; s--)
        {
            if (v & 0x8000)
                return 0xFFFF;
            v <<= 1;
        }
    }
    else
    {
        s = (u16)(lvl - dlvl) >> 2;
        if (s != 0)
        {
            if (s > 0xFF)
                s = 0xFF;
            v /= s;
            if (v == 0)
                return 1;
        }
    }
    return v;
}

// sub_080EF538 @ 0x080EF538
u32 sub_080EF538(s32 id)
{
    u8 *rec = Demon_GetRecord(id);
    u8 b;

    if (Flag_Test(1) || Flag_Test(0xD5) || Flag_Test(0xB7))
        return 0;
    b = rec[0x1C];
    {
        u8 c = rec[1];

        return sub_080F030C((b >> 4) | (c << 8), b) * 2;
    }
}

// sub_080EF580 @ 0x080EF580
#ifdef NONMATCHING
u32 sub_080EF580(s32 id)
{
    u8 *rec = Demon_GetRecord(id);
    u8 b;

    if (Flag_Test(1) || Flag_Test(0xD5) || Flag_Test(0xB7) || id <= 0xB1)
        return 0;
    b = rec[0x1C];
    {
        u8 c = rec[1];

        return sub_080F030C((c << 8) | (b & 0xF), b << 4);
    }
}
#else
NAKED u32 sub_080EF580(s32 id)
{
    asm_unified(
        ".L080EF580:\n"
        "    push {r4, r5, lr}\n"
        "    adds r5, r0, #0\n"
        "    lsls r0, r5, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Demon_GetRecord\n"
        "    adds r4, r0, #0\n"
        "    movs r0, #1\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L080EF5B0\n"
        "    movs r0, #0xd5\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L080EF5B0\n"
        "    movs r0, #0xb7\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L080EF5B0\n"
        "    cmp r5, #0xb1\n"
        "    bgt .L080EF5B4\n"
        ".L080EF5B0:\n"
        "    movs r0, #0\n"
        "    b .L080EF5CA\n"
        ".L080EF5B4:\n"
        "    ldrb r2, [r4, #0x1c]\n"
        "    ldrb r0, [r4, #1]\n"
        "    lsls r1, r2, #4\n"
        "    movs r3, #0xf\n"
        "    lsls r0, r0, #8\n"
        "    ands r2, r3\n"
        "    orrs r0, r2\n"
        "    bl sub_080F030C\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        ".L080EF5CA:\n"
        "    pop {r4, r5}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

// sub_080EF5D0 @ 0x080EF5D0
s32 sub_080EF5D0(s32 x)
{
    if (x == 0xF)
        return 0x8000;
    return sub_080ED3FC(2, x);
}

// sub_080EF5E8 @ 0x080EF5E8
s32 sub_080EF5E8(s32 id)
{
    return sub_080EF5D0(sub_080ED4A8(id) & 0xF);
}
