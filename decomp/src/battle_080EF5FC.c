#include "global.h"
#include "battle.h"

// sub_080EF5FC @ 0x080EF5FC
s32 sub_080EF5FC(u8 *c, s32 who)
{
    s32 v = c[0x5C];
    s32 kind = (s8)c[0x17];
    u32 x;

    switch (kind)
    {
    case 4:
    case 5:
        if (kind == 4)
            v = 0;
        else
            v = 1;
        v = Combatant_GetEquip(who, v);
        Item_GetAttribute(v, 4, &v);
        x = v;
    lookup:
        return sub_080EF5D0(x);
    case 7:
    case 11:
    by_skill:
        x = sub_080ED694(v);
        if (x > 0x7F)
            goto fail;
        goto lookup;
    case 8:
        if (v <= 0x57)
            return 1;
        Item_GetAttribute(v, 0xC, &v);
        if (v < 0)
            goto fail;
        if (v != 0x50 && v > 0x3F)
            return 1;
        goto by_skill;
    case 10:
        return sub_080EF5E8(*(s16 *)(c + 0x12));
    case 6:
    case 9:
    case 12:
    fail:
        return -1;
    }
    return 0;
}

// sub_080EF6B4 @ 0x080EF6B4
void sub_080EF6B4(s32 x)
{
    s32 i;

    for (i = 4; i < 16; i++)
    {
        if (Combatant_IsUsed(i) && Combatant_GetDemonId(i) == x)
        {
            Combatant_AddAlignment(0, 0x19);
            return;
        }
    }
}

// sub_080EF6E8 @ 0x080EF6E8
s32 sub_080EF6E8(s32 who, s32 i)
{
    s32 v = (u8)Combatant_GetSkill(who, i);

    if (v == 0xFF || (u8)(v - 0x40) > 0x5E)
        return -1;
    return v;
}

// sub_080EF710 @ 0x080EF710
s32 sub_080EF710(s32 who)
{
    s32 n = 0;
    s32 i;

    if (who <= 3)
        return -1;
    for (i = 0; i < 7; i++)
        if (sub_080EF6E8(who, i) >= 0)
            n++;
    return n;
}

// Battle_CanUseCommand @ 0x080EF740
/* Whether a command can be used; *msg gets the message id when it cannot. */
u32 Battle_CanUseCommand(s32 who, s32 kind, s32 *msg)
{
    s32 r;

    *msg = -1;
    switch (kind)
    {
    case 4:
        if (Combatant_GetEquip(who, 0) == 0xFF)
        {
            *msg = 0x162;
            return 0;
        }
        break;
    case 5:
        r = Combatant_GetEquip(who, 1);
        if (r == 0xFF || (Combatant_GetEquip(who, 6) == 0xFF && (u32)(r - 0x6D) > 1))
        {
            *msg = 0x162;
            return 0;
        }
        break;
    case 11:
        if (sub_080EF710(who) == 0)
        {
            *msg = 0x165;
            return 0;
        }
        break;
    case 7:
        if (!Combatant_CountSkillsWithFlags(who, 0x20))
        {
            *msg = 0x8F;
            return 0;
        }
        if (Combatant_GetStatus(who) & 0xB063)
        {
            *msg = 0x90;
            return 0;
        }
        break;
    case 6:
        if (!Flag_Test(3))
        {
            *msg = 0x393;
            return 0;
        }
        r = sub_080F3190();
        if (r != 0)
        {
            *msg = r;
            return 0;
        }
        break;
    case 12:
        break;
    }
    return 1;
}

// sub_080EF828 @ 0x080EF828
s32 sub_080EF828(void)
{
    if (Battle_ActiveSide() == 0)
        return 0x10;
    return 0x14;
}

// sub_080EF840 @ 0x080EF840
s32 sub_080EF840(void)
{
    s32 base = sub_080EF828();
    s32 n = Battle_IsTwoSided() ? 4 : 8;
    s32 i;

    for (i = 0; i < n; i++)
    {
        s32 id = base + i;

        if (Combatant_IsUsed(id))
            return id;
    }
    return base;
}

// sub_080EF878 @ 0x080EF878
s32 sub_080EF878(void)
{
    s32 base = sub_080EF828();
    s32 n = Battle_IsTwoSided() ? 4 : 8;
    s32 i;

    for (i = 0; i < n; i++)
    {
        s32 id = base + i;

        if (Combatant_IsUsed(id) && !Combatant_IsDead(id))
            return id;
    }
    return base;
}

// sub_080EF8BC @ 0x080EF8BC
void sub_080EF8BC(u32 v)
{
    BSTATE->unk120 = v;
}

// sub_080EF8D0 @ 0x080EF8D0
s32 sub_080EF8D0(void)
{
    return BSTATE->unk120;
}

// sub_080EF8E4 @ 0x080EF8E4
u16 sub_080EF8E4(void)
{
    return BSTATE->unk124;
}

// sub_080EF8F8 @ 0x080EF8F8
void sub_080EF8F8(u32 v)
{
    BSTATE->unk124 = v;
}

// sub_080EF90C @ 0x080EF90C
s32 sub_080EF90C(void)
{
    return BSTATE->unk128[Battle_ActiveSide()];
}

// sub_080EF930 @ 0x080EF930
void sub_080EF930(s32 v)
{
    BSTATE->unk128[Battle_ActiveSide()] = v;
}

// sub_080EF954 @ 0x080EF954
s32 sub_080EF954(void)
{
    return BSTATE->unk12C[Battle_ActiveSide()];
}

// sub_080EF978 @ 0x080EF978
void sub_080EF978(s32 v)
{
    BSTATE->unk12C[Battle_ActiveSide()] = v;
}

// Battle_ActiveSide @ 0x080EF99C
/* In a two-sided battle, makes unk122 follow the side whose combatant is gUnk_0203DB7C. */
s16 Battle_ActiveSide(void)
{
    if (Battle_IsTwoSided())
    {
        struct BattleFlow *b = BFLOW;

        if (BSTATE->unk122 == 0 && b->combatants[0] != gUnk_0203DB7C)
            BSTATE->unk122 = 1;
        else if (BSTATE->unk122 == 1 && b->combatants[1] != gUnk_0203DB7C)
            BSTATE->unk122 = 0;
    }
    return BSTATE->unk122;
}

// sub_080EFA20 @ 0x080EFA20
void sub_080EFA20(s32 d)
{
    s32 v = sub_080EF90C() + d;

    if (v < 0)
        v = 0;
    else if (v > 0x1F)
        v = 0x1F;
    sub_080EF930(v);
}

// sub_080EFA44 @ 0x080EFA44
void sub_080EFA44(s32 d)
{
    s32 v = sub_080EF954() + d;

    if (v < 0)
        v = 0;
    else if (v > 0x1F)
        v = 0x1F;
    sub_080EF978(v);
}

// sub_080EFA68 @ 0x080EFA68
void sub_080EFA68(s32 d)
{
    if (sub_080EF8D0() == 0)
        sub_080EFA20(d);
    else
        sub_080EFA44(d);
}

// sub_080EFA88 @ 0x080EFA88
void sub_080EFA88(u32 v)
{
    BSTATE->unk126 = v;
}

// sub_080EFA9C @ 0x080EFA9C
s16 sub_080EFA9C(void)
{
    return BSTATE->unk126;
}

// sub_080EFAB0 @ 0x080EFAB0
s32 sub_080EFAB0(s32 who)
{
    return BSTATE->unk78[0][sub_080ED8C0(who)];
}
