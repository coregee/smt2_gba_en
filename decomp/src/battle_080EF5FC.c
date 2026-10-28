#include "global.h"
#include "battle.h"

// sub_080EF5FC @ 0x080EF5FC
#ifdef NONMATCHING
s32 sub_080EF5FC(u8 *c, s32 who)
{
    s32 v = c[0x5C];
    s32 kind = (s8)c[0x17];
    u32 x;

    switch (kind)
    {
    case 4:
    case 5:
        v = (kind == 4) ? 0 : 1;
        v = sub_080C00DC(who, v);
        Item_GetAttribute(v, 4, &v);
        x = v;
        goto lookup;
    case 8:
        if (v <= 0x57)
            return 1;
        Item_GetAttribute(v, 0xC, &v);
        if (v < 0)
            return -1;
        if (v != 0x50 && v > 0x3F)
            return 1;
    case 7:
    case 11:
        x = sub_080ED694(v);
        if (x > 0x7F)
            return -1;
    lookup:
        return sub_080EF5D0(x);
    case 10:
        return sub_080EF5E8(*(s16 *)(c + 0x12));
    case 6:
    case 9:
    case 12:
        return -1;
    }
    return 0;
}
#else
NAKED s32 sub_080EF5FC(u8 *c, s32 who)
{
    asm_unified(
        ".L080EF5FC:\n"
        "    push {r4, lr}\n"
        "    sub sp, #4\n"
        "    adds r2, r0, #0\n"
        "    adds r4, r1, #0\n"
        "    adds r0, #0x5c\n"
        "    ldrb r0, [r0]\n"
        "    str r0, [sp]\n"
        "    movs r3, #0x17\n"
        "    ldrsb r3, [r2, r3]\n"
        "    subs r0, r3, #4\n"
        "    cmp r0, #8\n"
        "    bhi .L080EF6AA\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L080EF620\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080EF620: .4byte gUnknown_080EF624\n"
        "    .global gUnknown_080EF624\n"
        "gUnknown_080EF624:\n"
        ".L080EF624: @ jump table\n"
        "    .4byte .L080EF648\n"
        "    .4byte .L080EF648\n"
        "    .4byte .L080EF6A4\n"
        "    .4byte .L080EF66E\n"
        "    .4byte .L080EF67A\n"
        "    .4byte .L080EF6A4\n"
        "    .4byte .L080EF69A\n"
        "    .4byte .L080EF66E\n"
        "    .4byte .L080EF6A4\n"
        ".L080EF648:\n"
        "    cmp r3, #4\n"
        "    bne .L080EF650\n"
        "    movs r0, #0\n"
        "    b .L080EF652\n"
        ".L080EF650:\n"
        "    movs r0, #1\n"
        ".L080EF652:\n"
        "    str r0, [sp]\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, [sp]\n"
        "    bl sub_080C00DC\n"
        "    str r0, [sp]\n"
        "    movs r1, #4\n"
        "    mov r2, sp\n"
        "    bl Item_GetAttribute\n"
        "    ldr r0, [sp]\n"
        ".L080EF668:\n"
        "    bl sub_080EF5D0\n"
        "    b .L080EF6AC\n"
        ".L080EF66E:\n"
        "    ldr r0, [sp]\n"
        "    bl sub_080ED694\n"
        "    cmp r0, #0x7f\n"
        "    bhi .L080EF6A4\n"
        "    b .L080EF668\n"
        ".L080EF67A:\n"
        "    ldr r0, [sp]\n"
        "    cmp r0, #0x57\n"
        "    ble .L080EF696\n"
        "    movs r1, #0xc\n"
        "    mov r2, sp\n"
        "    bl Item_GetAttribute\n"
        "    ldr r0, [sp]\n"
        "    cmp r0, #0\n"
        "    blt .L080EF6A4\n"
        "    cmp r0, #0x50\n"
        "    beq .L080EF66E\n"
        "    cmp r0, #0x3f\n"
        "    ble .L080EF66E\n"
        ".L080EF696:\n"
        "    movs r0, #1\n"
        "    b .L080EF6AC\n"
        ".L080EF69A:\n"
        "    movs r1, #0x12\n"
        "    ldrsh r0, [r2, r1]\n"
        "    bl sub_080EF5E8\n"
        "    b .L080EF6AC\n"
        ".L080EF6A4:\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    b .L080EF6AC\n"
        ".L080EF6AA:\n"
        "    movs r0, #0\n"
        ".L080EF6AC:\n"
        "    add sp, #4\n"
        "    pop {r4}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

// sub_080EF6B4 @ 0x080EF6B4
void sub_080EF6B4(s32 x)
{
    s32 i;

    for (i = 4; i < 16; i++)
    {
        if (sub_080C09B0(i) && sub_080C07E0(i) == x)
        {
            sub_080C06EC(0, 0x19);
            return;
        }
    }
}

// sub_080EF6E8 @ 0x080EF6E8
#ifdef NONMATCHING
s32 sub_080EF6E8(s32 who, s32 i)
{
    u8 v = sub_080F42E0(who, i);

    if (v == 0xFF)
        return -1;
    if ((u8)(v - 0x40) <= 0x5E)
        return v;
    return -1;
}
#else
NAKED s32 sub_080EF6E8(s32 who, s32 i)
{
    asm_unified(
        ".L080EF6E8:\n"
        "    push {lr}\n"
        "    bl sub_080F42E0\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r1, r0, #0x18\n"
        "    cmp r1, #0xff\n"
        "    beq .L080EF702\n"
        "    adds r0, r1, #0\n"
        "    subs r0, #0x40\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #0x5e\n"
        "    bls .L080EF708\n"
        ".L080EF702:\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    b .L080EF70A\n"
        ".L080EF708:\n"
        "    adds r0, r1, #0\n"
        ".L080EF70A:\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

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
        if (sub_080C00DC(who, 0) == 0xFF)
        {
            *msg = 0x162;
            return 0;
        }
        break;
    case 5:
        r = sub_080C00DC(who, 1);
        if (r == 0xFF || (sub_080C00DC(who, 6) == 0xFF && (u32)(r - 0x6D) > 1))
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
        if (!sub_080F4300(who, 0x20))
        {
            *msg = 0x8F;
            return 0;
        }
        if (sub_080C0818(who) & 0xB063)
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

        if (sub_080C09B0(id))
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

        if (sub_080C09B0(id) && !sub_080C0830(id))
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
