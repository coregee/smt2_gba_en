#include "global.h"
#include "battle.h"

// sub_080ED5B4 @ 0x080ED5B4
u16 sub_080ED5B4(s32 table, s32 who)
{
    const struct LevelTable *t = &gUnknown_0876EBA8[table];
    u8 level = gUnk_0203A450[who * 2];
    u8 i;
    s32 idx;

    /* idx is left unset when level is above every threshold (original bug). */
    for (i = 0; i < 8; i++)
    {
        if (level <= t->level[i])
        {
            idx = i;
            break;
        }
    }
    return t->value[idx];
}

// sub_080ED600 @ 0x080ED600
s32 sub_080ED600(s32 row)
{
    return sub_080ED3FC(0, row);
}

// sub_080ED610 @ 0x080ED610
#ifdef NONMATCHING
s16 sub_080ED610(s32 id)
{
    s16 v = Demon_GetRecord(id)[0xD] >> 4;

    if (v > 7)
        v &= 7;
    else
    {
        s16 r = (sub_080C2244() & 3) - 1;

        if (r >= 0)
            r >>= 1;
        v += r;
        if (v < 0)
            v = 0;
        else if (v > 7)
            v = 7;
    }
    if (v == 0)
        v = 1;
    else if (v > 8)
        v = 7;
    return v;
}
#else
NAKED s16 sub_080ED610(s32 id)
{
    asm_unified(
        ".L080ED610:\n"
        "    push {r4, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Demon_GetRecord\n"
        "    ldrb r0, [r0, #0xd]\n"
        "    lsrs r0, r0, #4\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r2, r0, #0x10\n"
        "    cmp r2, #7\n"
        "    ble .L080ED62C\n"
        "    movs r0, #7\n"
        "    ands r0, r2\n"
        "    b .L080ED664\n"
        ".L080ED62C:\n"
        "    lsrs r4, r0, #0x10\n"
        "    bl sub_080C2244\n"
        "    movs r1, #3\n"
        "    ands r0, r1\n"
        "    subs r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    lsls r1, r0, #0x10\n"
        "    cmp r1, #0\n"
        "    blt .L080ED648\n"
        "    asrs r0, r1, #0x11\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        ".L080ED648:\n"
        "    lsls r1, r0, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    lsls r0, r4, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    adds r1, r1, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r0, r1, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    cmp r1, #0\n"
        "    blt .L080ED662\n"
        "    cmp r1, #7\n"
        "    ble .L080ED664\n"
        "    b .L080ED674\n"
        ".L080ED662:\n"
        "    movs r0, #0\n"
        ".L080ED664:\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080ED670\n"
        "    movs r0, #1\n"
        "    b .L080ED676\n"
        ".L080ED670:\n"
        "    cmp r0, #8\n"
        "    ble .L080ED676\n"
        ".L080ED674:\n"
        "    movs r0, #7\n"
        ".L080ED676:\n"
        "    pop {r4}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

// sub_080ED67C @ 0x080ED67C
u8 sub_080ED67C(s32 id)
{
    return gUnknown_0876F688[sub_080ED464(id)];
}

// sub_080ED694 @ 0x080ED694
u32 sub_080ED694(s32 id)
{
    return sub_080BF5C0(id)[2];
}

// sub_080ED6A4 @ 0x080ED6A4
u32 sub_080ED6A4(s32 id)
{
    return sub_080BF5C0(id)[0] & 0xF;
}

// sub_080ED6B8 @ 0x080ED6B8
u32 sub_080ED6B8(s32 id)
{
    return sub_080BF5C0(id)[0] & 0xF0;
}

// sub_080ED6CC @ 0x080ED6CC
u32 sub_080ED6CC(s32 id)
{
    return sub_080BF5C0(id)[3];
}

// sub_080ED6DC @ 0x080ED6DC
void sub_080ED6DC(s32 who, s32 item)
{
    s16 v;

    if (item < 0x68)
    {
        v = sub_080F4070(who) - sub_080ED6CC(item);
        if (v < 0)
            v = 0;
        sub_080F408C(who, v);
    }
    else
    {
        s32 cur = sub_080F401C(who);
        s32 max = sub_080F4038(who);

        v = cur - sub_080ED6CC(item) * max / 100;
        if (v < 0)
            v = 0;
        sub_080F4054(who, v);
    }
}

// sub_080ED744 @ 0x080ED744
u32 sub_080ED744(s32 who, s32 item)
{
    s16 v;

    if (item < 0x68)
    {
        v = sub_080F4070(who) - sub_080ED6CC(item);
        if (v >= 0)
            return 1;
    }
    else
    {
        s32 cur = sub_080F401C(who);
        s32 max = sub_080F4038(who);

        v = cur - sub_080ED6CC(item) * max / 100;
        if (v > 0)
            return 1;
    }
    return 0;
}

// sub_080ED794 @ 0x080ED794
u32 sub_080ED794(s32 id)
{
    return *(u16 *)(sub_080BF5C0(id) + 4);
}

// sub_080ED7A4 @ 0x080ED7A4
u32 sub_080ED7A4(s32 id)
{
    return sub_080BF5C0(id)[1];
}

// sub_080ED7B4 @ 0x080ED7B4
void sub_080ED7B4(void)
{
}

// sub_080ED7B8 @ 0x080ED7B8
void sub_080ED7B8(void)
{
}

// BattleState_Init @ 0x080ED7BC
void BattleState_Init(void)
{
    u32 zero;
    s32 i;
    struct BattleFlow *b = BFLOW;

    BSTATE = (struct BattleState *)((u8 *)b + 0xF6C);
    gUnk_03006438 = (u8 *)b + 0x1128;
    zero = 0;
    CpuSet(&zero, BSTATE, 0x05000068);
    for (i = 0; i < 2; i++)
    {
        BSTATE->unk128[i] = BSTATE->unk12C[i] = 8;
    }
    for (i = 0; i < 8; i++)
        BSTATE->unk56[i] |= 0xFFFF;
}

// sub_080ED844 @ 0x080ED844
void sub_080ED844(void)
{
    s32 i;

    for (i = 0; i < 2; i++)
    {
        BSTATE->unk128[i] = BSTATE->unk12C[i] = 8;
    }
}

// sub_080ED874 @ 0x080ED874
void sub_080ED874(void)
{
}

// sub_080ED878 @ 0x080ED878
void sub_080ED878(void)
{
    s32 i, j;

    BSTATE->unk4 = 0;
    BSTATE->flags &= 0xFF7F;
    for (i = 0; i < 6; i++)
        for (j = 0; j < 14; j++)
            BSTATE->unk78[i][j] = 0;
}

// sub_080ED8C0 @ 0x080ED8C0
s32 sub_080ED8C0(s32 who)
{
    u32 i;

    if (who < 16)
    {
        for (i = 0; i < 6; i++)
            if (who == gUnk_030050E0[i])
                return i;
        return 0;
    }
    return who - 10;
}

// sub_080ED8F4 @ 0x080ED8F4
u16 sub_080ED8F4(void)
{
    return BSTATE->flags;
}

// sub_080ED900 @ 0x080ED900
void sub_080ED900(u32 v)
{
    BSTATE->flags = v;
}

// sub_080ED90C @ 0x080ED90C
void sub_080ED90C(u16 v)
{
    BSTATE->flags |= v;
}

// sub_080ED920 @ 0x080ED920
void sub_080ED920(u32 v)
{
    BSTATE->unk2 = v;
}

// sub_080ED92C @ 0x080ED92C
u32 sub_080ED92C(void)
{
    return BSTATE->unk2;
}

// sub_080ED938 @ 0x080ED938
void sub_080ED938(u32 v)
{
    BSTATE->unk6 = v;
}

// sub_080ED944 @ 0x080ED944
s16 sub_080ED944(void)
{
    return *(s16 *)(gUnk_03006438 + 0x28);
}

// Battle_IsTwoSided @ 0x080ED954
u32 Battle_IsTwoSided(void)
{
    if (BSTATE->unk6 != 0)
        return 1;
    return 0;
}

// sub_080ED974 @ 0x080ED974
u32 sub_080ED974(s32 who)
{
    if (Battle_IsTwoSided() && who > 0x13)
        return 1;
    return 0;
}

// sub_080ED990 @ 0x080ED990
u32 sub_080ED990(s32 side)
{
    if (Battle_IsTwoSided() && side == 1)
        return 0x14;
    return 0x10;
}

// Battle_CountLivingUnits @ 0x080ED9AC
s32 Battle_CountLivingUnits(s32 first, s32 count)
{
    struct BattleFlow *b = BFLOW;
    s32 n = 0;
    s32 i;

    for (i = first; i < first + count; i++)
    {
        struct BattleUnit *u = &b->units[i];

        if (u->unkE != 0 && !(u->flags & 0x8000))
            n++;
    }
    return n;
}

// sub_080ED9F4 @ 0x080ED9F4
u32 sub_080ED9F4(void)
{
    return Battle_CountLivingUnits(0, 8);
}

// sub_080EDA04 @ 0x080EDA04
void sub_080EDA04(void)
{
    s32 i;

    for (i = 0x10; i < 0x18; i++)
    {
        sub_080C08F8(i, 0x8000);
        sub_080F4104(i);
    }
}

// sub_080EDA24 @ 0x080EDA24
u32 sub_080EDA24(s32 side)
{
    s32 first = 0;
    s32 count;

    if (Battle_IsTwoSided())
    {
        count = 4;
        if (side == 1)
            first = 4;
    }
    else
        count = 8;
    return Battle_CountLivingUnits(first, count);
}

// sub_080EDA4C @ 0x080EDA4C
void sub_080EDA4C(s32 i, u32 v)
{
    BSTATE->unk160[i] = v;
}

// sub_080EDA64 @ 0x080EDA64
u32 sub_080EDA64(s32 i)
{
    return BSTATE->unk160[i];
}

// sub_080EDA7C @ 0x080EDA7C
void sub_080EDA7C(u32 v)
{
    BSTATE->unk158 = v;
}

// sub_080EDA90 @ 0x080EDA90
u16 sub_080EDA90(void)
{
    return BSTATE->unk158;
}

// sub_080EDAA4 @ 0x080EDAA4
void sub_080EDAA4(u32 v)
{
    BSTATE->unk15A = v;
}

// sub_080EDAB8 @ 0x080EDAB8
void sub_080EDAB8(s16 v)
{
    BSTATE->unk15C = v;
}

// sub_080EDAD0 @ 0x080EDAD0
u32 sub_080EDAD0(void)
{
    if (sub_080C07E0(0x10) > 0xFF)
        return 1;
    return 0;
}

// sub_080EDAEC @ 0x080EDAEC
u32 sub_080EDAEC(s32 id)
{
    u32 r = 0;

    if ((u32)(id - 0x130) <= 4)
        r = 1;
    return r;
}

// sub_080EDB04 @ 0x080EDB04
u32 sub_080EDB04(void)
{
    u8 tbl[16];

    memcpy(tbl, gUnknown_0876F6B4, 16);
    return tbl[(sub_080C1D9C() >> 4) & 0xF];
}

// sub_080EDB2C @ 0x080EDB2C
s32 sub_080EDB2C(u32 mask, s32 bit, s32 step)
{
    u32 i;

    if (mask & ~(1 << bit))
    {
        for (i = 1; i < 32; i++)
        {
            bit += step;
            if (bit > 31)
                bit = 0;
            else if (bit < 0)
                bit = 31;
            if ((1 << bit) & mask)
                break;
        }
    }
    return bit;
}
