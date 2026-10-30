#include "global.h"
#include "battle.h"

// sub_080EFE60 @ 0x080EFE60
u32 sub_080EFE60(s32 who)
{
    s32 v;
    s32 x;

    switch (sub_080C35E4(who))
    {
    case 5:
        return 1;
    case 7:
    case 11:
        x = Combatant_GetChosenSkill(who);
    lookup:
        return sub_080ED6A4(x);
    case 8:
        Item_GetAttribute(Combatant_GetChosenSkill(who), 0xC, &v);
        x = v;
        if (x <= 0x7F)
            goto lookup;
    case 6:
    case 9:
    case 12:
        return 0xFFFF;
    case 4:
    case 10:
        break;
    }
    return 0;
}

// sub_080EFEDC @ 0x080EFEDC
u32 sub_080EFEDC(void)
{
    if (Combatant_GetDemonId(0x10) == 0x12D || Combatant_GetDemonId(0x10) == 0x10F || Combatant_GetDemonId(0x10) == 0x110
        || Combatant_GetDemonId(0x10) == 0x111 || Combatant_GetDemonId(0x10) == 0x12E || Combatant_GetDemonId(0x10) == 0x12F
        || Combatant_GetDemonId(0x10) == 0x127 || Combatant_GetDemonId(0x10) == 0x128 || Combatant_GetDemonId(0x10) == 0x12C
        || Combatant_GetDemonId(0x10) == 0x129 || Combatant_GetDemonId(0x10) == 0x12A || Combatant_GetDemonId(0x10) == 0x12B)
        return 0x1B;
    if (sub_080EDAD0() != 0)
        return 0x13;
    return 0xA;
}

// sub_080EFFC4 @ 0x080EFFC4
s32 sub_080EFFC4(s16 i)
{
    return (s16)BSTATE->order[i].id;
}

// sub_080EFFD8 @ 0x080EFFD8
s32 sub_080EFFD8(s16 kind, s32 x)
{
    if (kind == 7)
        return 0;
    if (kind == 8)
        return 0;
    if (kind == 11 && x <= 0x67)
        return 0;
    return 1;
}

// sub_080EFFF8 @ 0x080EFFF8
s32 sub_080EFFF8(s32 who, s16 i)
{
    struct BattleFlow *b = BFLOW;

    if ((s16)BSTATE->targets[i].id != -1)
    {
        u16 kind;
        s32 sk;

        kind = sub_080C35E4(who);
        sk = Combatant_GetChosenSkill(who);

        if (sub_080EFFD8(kind, sk) == 1)
        {
            if (who > 15)
            {
                u16 *t = &b->unk11AC;

                if (*t != 0xFFFF && !Combatant_IsDead(*t)
                    && *(u16 *)(Party_GetMember(*t + 0x8000) + 0xE) == 0xC000)
                    return (s16)*t;
            }
            else
            {
                u16 *t = &b->unk11AE;

                if (*t != 0xFFFF && !Combatant_IsDead(*t))
                    return (s16)*t;
            }
        }
    }
    return (s16)BSTATE->targets[i].id;
}

// sub_080F00D4 @ 0x080F00D4
s32 sub_080F00D4(void)
{
    return BSTATE->unk15C;
}

// sub_080F00E8 @ 0x080F00E8
void sub_080F00E8(s32 v)
{
    BSTATE->unk15C = v;
}

// sub_080F00FC @ 0x080F00FC
void sub_080F00FC(u16 m)
{
    BSTATE->flags &= ~m;
}

// sub_080F0110 @ 0x080F0110
void sub_080F0110(s16 d)
{
    BSTATE->unk4C += d;
}

// sub_080F0124 @ 0x080F0124
u32 sub_080F0124(void)
{
    return BSTATE->unk4C;
}

// sub_080F0130 @ 0x080F0130
void sub_080F0130(s16 d)
{
    BSTATE->unk50 += d;
}

// sub_080F0144 @ 0x080F0144
u32 sub_080F0144(void)
{
    return BSTATE->unk50;
}

// sub_080F0150 @ 0x080F0150
void sub_080F0150(s16 d)
{
    BSTATE->unk54 += d;
}

// sub_080F0168 @ 0x080F0168
s32 sub_080F0168(void)
{
    return BSTATE->unk54;
}

// sub_080F0178 @ 0x080F0178
void sub_080F0178(s32 i, s16 d)
{
    BSTATE->unk68[i] += d;
}

// sub_080F0194 @ 0x080F0194
u32 sub_080F0194(s32 who)
{
    if (!Flag_Test(0xD5) && !Flag_Test(0xB7) && !(Combatant_GetStatus(who) & 0x800))
        return BSTATE->unk68[who];
    return 0;
}

// sub_080F01D8 @ 0x080F01D8
void sub_080F01D8(s32 i, u32 v)
{
    BSTATE->unk56[i] = v;
}

// sub_080F01EC @ 0x080F01EC
s32 sub_080F01EC(s32 i)
{
    return (s16)BSTATE->unk56[i];
}
