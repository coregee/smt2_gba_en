#include "global.h"
#include "battle2.h"

// sub_080F60A4 @ 0x080F60A4
/* Alignment-keyed item/skill: a target of alignment `al` is healed and cured (result 1);
   others lose 1/2 (1/8 when neutral) of their HP (result 2, damage in a->dmg). */
#ifdef NONMATCHING
void sub_080F60A4(struct Action *a, s32 al)
{
    s32 who = a->def;
    u16 st;
    s32 d;

    a->unkC = 0;
    st = Combatant_GetStatus(who) & 0x4000;
    if (st)
        a->unkC = 3;
    else if (!Combatant_IsDead(who))
    {
        if (Combatant_GetAlignment(who) == al)
        {
            if (!Combatant_IsHpFull(who))
                Combatant_RestoreHp(who);
            if (Combatant_GetStatus(who) & 0x33FE)
                Combatant_ClearStatus(who, (u16)~0x33FE);
            a->unkC = 1;
        }
        else
        {
            if (Combatant_GetAlignment(who) == 1)
                d = Math_DivRound(Battle_GetHp(who), 8);
            else
                d = Math_DivRound(Battle_GetHp(who), 2);
            a->dmg = d;
            d = Battle_GetHp(who) - d;
            if (d > 0)
                Battle_SetHp(who, d);
            else
                a->dmg = 0;
            a->unkC = 2;
        }
    }
    else
        a->unkC = st;
}
#else
NAKED
void sub_080F60A4(struct Action *a, s32 al)
{
    asm_unified(
        ".L080F60A4:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    adds r6, r0, #0\n"
        "    adds r7, r1, #0\n"
        "    ldr r5, [r6, #4]\n"
        "    movs r0, #0\n"
        "    str r0, [r6, #0xc]\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_GetStatus\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #7\n"
        "    ands r1, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r4, r1, #0x10\n"
        "    cmp r4, #0\n"
        "    beq .L080F60CA\n"
        "    movs r0, #3\n"
        "    str r0, [r6, #0xc]\n"
        "    b .L080F615A\n"
        ".L080F60CA:\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_IsDead\n"
        "    cmp r0, #0\n"
        "    bne .L080F6158\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_GetAlignment\n"
        "    cmp r0, r7\n"
        "    bne .L080F6114\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_IsHpFull\n"
        "    cmp r0, #0\n"
        "    bne .L080F60EE\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_RestoreHp\n"
        ".L080F60EE:\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_GetStatus\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r1, .L080F610C\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080F6106\n"
        "    ldr r1, .L080F6110\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_ClearStatus\n"
        ".L080F6106:\n"
        "    movs r0, #1\n"
        "    str r0, [r6, #0xc]\n"
        "    b .L080F615A\n"
        ".L080F610C: .4byte 0x33FE0000\n"
        ".L080F6110: .4byte 0x0000CC01\n"
        ".L080F6114:\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_GetAlignment\n"
        "    cmp r0, #1\n"
        "    bne .L080F6128\n"
        "    adds r0, r5, #0\n"
        "    bl Battle_GetHp\n"
        "    movs r1, #8\n"
        "    b .L080F6130\n"
        ".L080F6128:\n"
        "    adds r0, r5, #0\n"
        "    bl Battle_GetHp\n"
        "    movs r1, #2\n"
        ".L080F6130:\n"
        "    bl Math_DivRound\n"
        "    adds r4, r0, #0\n"
        "    str r4, [r6, #0x18]\n"
        "    adds r0, r5, #0\n"
        "    bl Battle_GetHp\n"
        "    subs r4, r0, r4\n"
        "    cmp r4, #0\n"
        "    ble .L080F614E\n"
        "    adds r0, r5, #0\n"
        "    adds r1, r4, #0\n"
        "    bl Battle_SetHp\n"
        "    b .L080F6152\n"
        ".L080F614E:\n"
        "    movs r0, #0\n"
        "    str r0, [r6, #0x18]\n"
        ".L080F6152:\n"
        "    movs r0, #2\n"
        "    str r0, [r6, #0xc]\n"
        "    b .L080F615A\n"
        ".L080F6158:\n"
        "    str r4, [r6, #0xc]\n"
        ".L080F615A:\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

// sub_080F6160 @ 0x080F6160
void sub_080F6160(struct Action *a)
{
    sub_080F60A4(a, 0);
}

// sub_080F616C @ 0x080F616C
void sub_080F616C(struct Action *a)
{
    sub_080F60A4(a, 2);
}

// sub_080F6178 @ 0x080F6178
/* Sets one-shot battle flag `bit` (message `msg`); message 0x96 when already set. */
void sub_080F6178(struct Action *a, u16 bit, s32 msg)
{
    if (BattleFlags_Get() & bit)
        a->msg = 0x96;
    else
    {
        BattleFlags_Add(bit);
        a->msg = msg;
    }
}

// sub_080F61A0 @ 0x080F61A0
void sub_080F61A0(struct Action *a)
{
}

// sub_080F61A4 @ 0x080F61A4
void sub_080F61A4(struct Action *a)
{
    sub_080F6178(a, 2, 0x130);
}

// sub_080F61B4 @ 0x080F61B4
void sub_080F61B4(struct Action *a)
{
}

// sub_080F61B8 @ 0x080F61B8
void sub_080F61B8(struct Action *a)
{
    sub_080F6178(a, 8, 0x132);
}

// sub_080F61C8 @ 0x080F61C8
void sub_080F61C8(struct Action *a)
{
    sub_080F6178(a, 0x10, 0x133);
}

// sub_080F61DC @ 0x080F61DC
void sub_080F61DC(struct Action *a)
{
}

// sub_080F61E0 @ 0x080F61E0
void sub_080F61E0(struct Action *a)
{
    sub_080F6178(a, 0x40, 0x135);
}

// sub_080F61F4 @ 0x080F61F4
void sub_080F61F4(struct Action *a)
{
}

// sub_080F61F8 @ 0x080F61F8
void sub_080F61F8(struct Action *a)
{
}

// sub_080F61FC @ 0x080F61FC
/* Removes an enemy chosen by sub_080EFFF8 from the battle. */
void sub_080F61FC(struct Action *a)
{
    struct BattleFlow *b = BFLOW;

    if (!sub_080EDAD0() && !(sub_080ED8F4() & 0x100))
    {
        s32 who = sub_080EFFF8(a->att, b->unkF66);

        Combatant_ClearSlot(who);
        Combatant_SetStatus(who, 0x8000);
        sub_08126834(-1);
        if (!sub_080ED9F4())
            sub_080ED90C(0x200);
        sub_080E760C();
        a->def = who;
        a->msg = -1;
    }
    else
        a->unkC = 0;
}

// sub_080F6270 @ 0x080F6270
void sub_080F6270(struct Action *a)
{
    a->unkC = 0;
}

// sub_080F6278 @ 0x080F6278
u16 sub_080F6278(void)
{
    return gUnknown_0876FB44[Random_Byte() & 3][0];
}

// sub_080F6294 @ 0x080F6294
/* 1 in 4 (not in special battles): every living enemy is replaced by demon 0xFB at full
   HP/MP; message 0x324. */
void sub_080F6294(struct Action *a)
{
    struct BattleFlow *b = BFLOW;
    s32 i;

    if (!sub_080EDAD0() && !(sub_080ED8F4() & 0x100) && !(Random_Byte() & 3))
    {
        for (i = 0x10; i < 0x18; i++)
        {
            if (Combatant_IsAlive(i))
            {
                b->combatants[0] = 0xFB;
                b->combatants[1] = 0xFB;
                Battle_InitEnemyUnit(i - 0x10, 0xFB);
                Battle_SetHp(i, Battle_GetMaxHp(i));
                Battle_SetMp(i, Battle_GetMaxMp(i));
            }
        }
        if (Battle_IsTwoSided())
        {
            b->unk998 += b->unk99A;
            sub_080ED938(0);
        }
        sub_080EF8F8(Demon_GetRecord(b->combatants[0])[0x21]);
        Task_End(b->task04);
        sub_080E8C58(b->combatants[0], 0xFFFF, 1);
        sub_080E760C();
        a->msg = 0x324;
    }
    else
    {
        a->msg = 0x7E;
        a->unkC = 0;
    }
}

// sub_080F6378 @ 0x080F6378
void sub_080F6378(struct Action *a)
{
    sub_080F5D28(a, 0x1000);
}
