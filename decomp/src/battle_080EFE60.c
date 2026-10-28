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
        x = sub_080F3F14(who);
    lookup:
        return sub_080ED6A4(x);
    case 8:
        Item_GetAttribute(sub_080F3F14(who), 0xC, &v);
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
#ifdef NONMATCHING
s32 sub_080EFFF8(s32 who, s16 i)
{
    struct BattleFlow *b = BFLOW;

    if ((s16)BSTATE->targets[i].id != -1)
    {
        u16 kind = sub_080C35E4(who);

        if (sub_080EFFD8(kind, sub_080F3F14(who)) == 1)
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
#else
NAKED s32 sub_080EFFF8(s32 who, s16 i)
{
    asm_unified(
        ".L080EFFF8:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    adds r5, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    ldr r7, .L080F0080\n"
        "    ldr r0, .L080F0084\n"
        "    ldr r0, [r0]\n"
        "    lsrs r2, r1, #0x10\n"
        "    mov r8, r2\n"
        "    asrs r1, r1, #0xe\n"
        "    adds r0, r0, r1\n"
        "    movs r1, #0x98\n"
        "    lsls r1, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r0, r2]\n"
        "    ldr r6, .L080F0088\n"
        "    asrs r0, r6, #0x10\n"
        "    cmp r1, r0\n"
        "    beq .L080F00B0\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080C35E4\n"
        "    adds r4, r0, #0\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080F3F14\n"
        "    adds r1, r0, #0\n"
        "    lsls r4, r4, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080EFFD8\n"
        "    cmp r0, #1\n"
        "    bne .L080F00B0\n"
        "    cmp r5, #0xf\n"
        "    ble .L080F0090\n"
        "    ldr r0, .L080F008C\n"
        "    adds r4, r7, r0\n"
        "    ldrh r1, [r4]\n"
        "    lsrs r0, r6, #0x10\n"
        "    cmp r1, r0\n"
        "    beq .L080F00B0\n"
        "    adds r0, r1, #0\n"
        "    bl Combatant_IsDead\n"
        "    cmp r0, #0\n"
        "    bne .L080F00B0\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    adds r0, r1, #0\n"
        "    ldrh r2, [r4]\n"
        "    adds r0, r0, r2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Party_GetMember\n"
        "    ldrh r1, [r0, #0xe]\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #8\n"
        "    cmp r1, r0\n"
        "    bne .L080F00B0\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r4, r1]\n"
        "    b .L080F00C6\n"
        ".L080F0080: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080F0084: .4byte 0x03006434 @ IWRAM+0x6434\n"
        ".L080F0088: .4byte 0xFFFF0000\n"
        ".L080F008C: .4byte 0x000011AC\n"
        ".L080F0090:\n"
        "    ldr r2, .L080F00AC\n"
        "    adds r4, r7, r2\n"
        "    ldrh r1, [r4]\n"
        "    lsrs r0, r6, #0x10\n"
        "    cmp r1, r0\n"
        "    beq .L080F00B0\n"
        "    adds r0, r1, #0\n"
        "    bl Combatant_IsDead\n"
        "    cmp r0, #0\n"
        "    bne .L080F00B0\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r4, r1]\n"
        "    b .L080F00C6\n"
        ".L080F00AC: .4byte 0x000011AE\n"
        ".L080F00B0:\n"
        "    ldr r0, .L080F00D0\n"
        "    ldr r1, [r0]\n"
        "    mov r2, r8\n"
        "    lsls r0, r2, #0x10\n"
        "    asrs r0, r0, #0xe\n"
        "    adds r1, r1, r0\n"
        "    movs r0, #0x98\n"
        "    lsls r0, r0, #1\n"
        "    adds r1, r1, r0\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r1, r2]\n"
        ".L080F00C6:\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        ".L080F00D0: .4byte 0x03006434 @ IWRAM+0x6434\n"
    );
}
#endif

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
