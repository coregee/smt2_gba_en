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
s32 sub_080EF3C8(s32 id)
{
    u8 *rec = Demon_GetRecord(id);
    u16 v;
    u16 r;

    if (Flag_Test(1) || Flag_Test(0xD5) || Flag_Test(0xB7))
        return -1;
    v = rec[0x19] & 0xF;
    if (v == 0)
        return -1;
    v = (u16)(v * v) >> 1;
    if (v == 0)
        v = 1;
    r = Random_Byte() & 0xFF;
    if (r >= v)
        return -1;
    v = rec[0x1F];
    v &= 1;
    r = v << 8;
    v = rec[0x1A];
    v |= r;
    return v;
}

// sub_080EF434 @ 0x080EF434
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
    {
        u16 v = rand() & 0xFF;

        if ((u16)((u32)v % 0xC0) >= n)
            return 0;
    }
    return 1;
}

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
u32 sub_080EF580(s32 id)
{
    u8 *rec = Demon_GetRecord(id);
    u32 b;
    u32 c;
    u32 y;
    u32 mask;

    if (Flag_Test(1) || Flag_Test(0xD5) || Flag_Test(0xB7) || id <= 0xB1)
        return 0;
    b = rec[0x1C];
    c = rec[1];
    y = b << 4;
    mask = 0xF;
    c <<= 8;
    b &= mask;
    return sub_080F030C(c | b, y);
}

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
