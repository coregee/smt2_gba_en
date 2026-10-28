#include "global.h"
#include "battle.h"

/* BSTATE->unk78[row][slot]: six rows of per-combatant battle modifiers; slots 0-5 are the
   party, 6-13 the enemies (index from sub_080ED8C0). Row 0 is a status bit mask. */

// sub_080EFAD0 @ 0x080EFAD0
void sub_080EFAD0(s32 who, u16 mask)
{
    s16 m = mask;

    if (who < 16)
    {
        BSTATE->unk78[0][0] |= m;
        BSTATE->unk78[0][1] |= m;
        BSTATE->unk78[0][2] |= m;
        BSTATE->unk78[0][3] |= m;
        BSTATE->unk78[0][4] |= m;
        BSTATE->unk78[0][5] |= m;
    }
    else
    {
        BSTATE->unk78[0][6] |= m;
        BSTATE->unk78[0][7] |= m;
        BSTATE->unk78[0][8] |= m;
        BSTATE->unk78[0][9] |= m;
        BSTATE->unk78[0][10] |= m;
        BSTATE->unk78[0][11] |= m;
        BSTATE->unk78[0][12] |= m;
        BSTATE->unk78[0][13] |= m;
    }
}

// sub_080EFB8C @ 0x080EFB8C
void sub_080EFB8C(s32 who, s32 mask0)
{
    u16 mask = mask0;
    s16 m = mask;

    if (who < 16)
    {
        BSTATE->unk78[0][0] &= m;
        BSTATE->unk78[0][1] &= m;
        BSTATE->unk78[0][2] &= m;
        BSTATE->unk78[0][3] &= m;
        BSTATE->unk78[0][4] &= m;
        BSTATE->unk78[0][5] &= m;
    }
    else
    {
        BSTATE->unk78[0][6] &= m;
        BSTATE->unk78[0][7] &= m;
        BSTATE->unk78[0][8] &= m;
        BSTATE->unk78[0][9] &= m;
        BSTATE->unk78[0][10] &= m;
        BSTATE->unk78[0][11] &= m;
        BSTATE->unk78[0][12] &= m;
        BSTATE->unk78[0][13] &= m;
    }
}

// sub_080EFBFC @ 0x080EFBFC
s32 sub_080EFBFC(s32 who)
{
    return BSTATE->unk78[1][sub_080ED8C0(who)];
}

// Battle_AddModifierClamped @ 0x080EFC1C
/* Adds d to modifier row for who, clamped to the row's limits; returns 1 when clamped. */
s32 Battle_AddModifierClamped(s32 row, s32 who, s32 d)
{
    s32 slot = sub_080ED8C0(who);
    s32 lo, hi, v;
    s32 clamped;

    BSTATE->unk78[row][slot] += d;
    lo = (s8)gUnknown_0876F7CE[row * 2];
    hi = (s8)gUnknown_0876F7CE[row * 2 + 1];
    v = BSTATE->unk78[row][slot];
    clamped = 0;
    if (v < lo)
    {
        v = lo;
        clamped = 1;
    }
    else if (v > hi)
    {
        v = hi;
        clamped = 1;
    }
    if (clamped)
        BSTATE->unk78[row][slot] = v;
    return clamped;
}

// sub_080EFC9C @ 0x080EFC9C
s32 sub_080EFC9C(s32 row, s32 who, s32 d)
{
    s32 hit = 0;
    s32 i;

    if (who < 16)
    {
        s8 *party;

        for (i = 0, party = gUnk_030050E0; i < 6; i++)
        {
            if (*(s8 *)(i + (u32)party) != -1 && !Battle_AddModifierClamped(row, *(s8 *)(i + (u32)party), d))
                hit = 1;
        }
    }
    else
    {
        for (i = 0; i < 8; i++)
            if (!Battle_AddModifierClamped(row, i + 0x10, d))
                hit = 1;
    }
    if (hit == 1)
        return 0;
    return 1;
}

// sub_080EFD14 @ 0x080EFD14
s32 sub_080EFD14(s32 who, s32 d)
{
    return sub_080EFC9C(1, who, d);
}

// sub_080EFD28 @ 0x080EFD28
s32 sub_080EFD28(s32 who, s32 d)
{
    return Battle_AddModifierClamped(1, who, d);
}

// sub_080EFD3C @ 0x080EFD3C
s32 sub_080EFD3C(s32 who)
{
    return BSTATE->unk78[2][sub_080ED8C0(who)];
}

// sub_080EFD5C @ 0x080EFD5C
s32 sub_080EFD5C(s32 who, s32 d)
{
    return sub_080EFC9C(2, who, d);
}

// sub_080EFD70 @ 0x080EFD70
s32 sub_080EFD70(s32 who, s32 d)
{
    return Battle_AddModifierClamped(2, who, d);
}

// sub_080EFD84 @ 0x080EFD84
s32 sub_080EFD84(s32 who)
{
    return BSTATE->unk78[3][sub_080ED8C0(who)];
}

// sub_080EFDA4 @ 0x080EFDA4
s32 sub_080EFDA4(s32 who, s32 d)
{
    return sub_080EFC9C(3, who, d);
}

// sub_080EFDB8 @ 0x080EFDB8
s32 sub_080EFDB8(s32 who, s32 d)
{
    return Battle_AddModifierClamped(3, who, d);
}

// sub_080EFDCC @ 0x080EFDCC
s32 sub_080EFDCC(s32 who)
{
    return BSTATE->unk78[4][sub_080ED8C0(who)];
}

// sub_080EFDEC @ 0x080EFDEC
s32 sub_080EFDEC(s32 who, s32 d)
{
    return sub_080EFC9C(4, who, d);
}

// sub_080EFE00 @ 0x080EFE00
s32 sub_080EFE00(s32 who, s32 d)
{
    return Battle_AddModifierClamped(4, who, d);
}

// sub_080EFE14 @ 0x080EFE14
s32 sub_080EFE14(s32 who)
{
    return BSTATE->unk78[5][sub_080ED8C0(who)];
}

// sub_080EFE38 @ 0x080EFE38
s32 sub_080EFE38(s32 who, s32 d)
{
    return sub_080EFC9C(5, who, d);
}

// sub_080EFE4C @ 0x080EFE4C
s32 sub_080EFE4C(s32 who, s32 d)
{
    return Battle_AddModifierClamped(5, who, d);
}
