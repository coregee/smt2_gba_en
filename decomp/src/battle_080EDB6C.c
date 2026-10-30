#include "global.h"
#include "battle.h"

// Battle_SortEntriesInsertion @ 0x080EDB6C
/* Insertion sort of a[lo..hi-1] by ascending key. */
void Battle_SortEntriesInsertion(u16 lo, u16 hi, struct SortEntry *a)
{
    s32 i, j;

    for (i = lo + 1; i < hi; i++)
    {
        struct SortEntry t = a[i];
        s32 key = a[i].key;

        for (j = i - 1; j >= lo && a[j].key > key; j--)
            a[j + 1] = a[j];
        a[j + 1] = t;
    }
}

// Battle_SortEntriesQuick @ 0x080EDBCC
#ifdef NONMATCHING
/* Quicksort (descending by key) with an explicit stack; runs of up to 10 entries are left
   for the insertion sort at the end. */
void Battle_SortEntriesQuick(u16 lo, u16 n, struct SortEntry *a)
{
    u16 stackHi[32];
    u16 stackLo[32];
    s16 l, r;
    s32 sp;

    l = lo;
    r = lo + n - 1;
    sp = 0;
    if (r - l > 10)
    {
        do
        {
            do
            {
                s32 pivot = a[(l + r) / 2].key;
                u32 i = l - 1;
                u32 j = r + 1;

                for (;;)
                {
                    while (a[++i].key > pivot)
                        ;
                    while (a[--j].key < pivot)
                        ;
                    if (i >= j)
                        break;
                    {
                        struct SortEntry t = a[i];
                        a[i] = a[j];
                        a[j] = t;
                    }
                }
                if (i - l > r - j)
                {
                    if (i - l > 10)
                    {
                        stackLo[sp] = l;
                        stackHi[sp] = i - 1;
                        sp++;
                    }
                    l = j + 1;
                }
                else
                {
                    if (r - j > 10)
                    {
                        stackLo[sp] = j + 1;
                        stackHi[sp] = r;
                        sp++;
                    }
                    r = i - 1;
                }
            } while (r - l > 10);
            if (sp == 0)
                break;
            sp--;
            l = stackLo[sp];
            r = stackHi[sp];
        } while (1);
    }
    Battle_SortEntriesInsertion(lo, n, a);
}
#else
NAKED void Battle_SortEntriesQuick(u16 lo, u16 n, struct SortEntry *a)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x88\n"
        "    mov sb, r2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0x80]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    mov sl, r1\n"
        "    str r0, [sp, #0x84]\n"
        "    adds r1, r0, #0\n"
        "    add r1, sl\n"
        "    subs r1, #1\n"
        "    lsls r1, r1, #0x10\n"
        "    movs r0, #0\n"
        "    mov r8, r0\n"
        "    lsrs r2, r1, #0x10\n"
        "    mov ip, r2\n"
        "    asrs r1, r1, #0x10\n"
        "    ldr r3, [sp, #0x84]\n"
        "    lsls r0, r3, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    subs r1, r1, r0\n"
        "    cmp r1, #0xa\n"
        "    bgt .L080EDC22\n"
        "    b .L080EDD00\n"
        ".L080EDC08:\n"
        "    movs r7, #1\n"
        "    rsbs r7, r7, #0\n"
        "    add r8, r7\n"
        "    add r0, sp, #0x40\n"
        "    mov r2, r8\n"
        "    lsls r1, r2, #1\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    str r0, [sp, #0x84]\n"
        "    mov r3, sp\n"
        "    adds r0, r3, r1\n"
        "    ldrh r0, [r0]\n"
        "    mov ip, r0\n"
        ".L080EDC22:\n"
        "    ldr r7, [sp, #0x84]\n"
        "    lsls r3, r7, #0x10\n"
        "    asrs r3, r3, #0x10\n"
        "    mov r0, ip\n"
        "    lsls r2, r0, #0x10\n"
        "    asrs r2, r2, #0x10\n"
        "    adds r0, r3, r2\n"
        "    lsrs r1, r0, #0x1f\n"
        "    adds r0, r0, r1\n"
        "    asrs r0, r0, #1\n"
        "    lsls r0, r0, #2\n"
        "    add r0, sb\n"
        "    movs r1, #2\n"
        "    ldrsh r6, [r0, r1]\n"
        "    subs r4, r3, #1\n"
        "    adds r5, r2, #1\n"
        "    lsls r0, r5, #2\n"
        "    mov r2, sb\n"
        "    adds r3, r0, r2\n"
        "    lsls r0, r4, #2\n"
        "    adds r2, r0, r2\n"
        "    b .L080EDC56\n"
        ".L080EDC4E:\n"
        "    ldr r1, [r2]\n"
        "    ldr r0, [r3]\n"
        "    str r0, [r2]\n"
        "    str r1, [r3]\n"
        ".L080EDC56:\n"
        "    adds r2, #4\n"
        "    adds r4, #1\n"
        "    movs r7, #2\n"
        "    ldrsh r0, [r2, r7]\n"
        "    cmp r0, r6\n"
        "    ble .L080EDC74\n"
        "    lsls r1, r4, #2\n"
        "    add r1, sb\n"
        ".L080EDC66:\n"
        "    adds r1, #4\n"
        "    adds r2, #4\n"
        "    adds r4, #1\n"
        "    movs r7, #2\n"
        "    ldrsh r0, [r1, r7]\n"
        "    cmp r0, r6\n"
        "    bgt .L080EDC66\n"
        ".L080EDC74:\n"
        "    lsls r1, r5, #2\n"
        "    add r1, sb\n"
        ".L080EDC78:\n"
        "    subs r1, #4\n"
        "    subs r3, #4\n"
        "    subs r5, #1\n"
        "    movs r7, #2\n"
        "    ldrsh r0, [r1, r7]\n"
        "    cmp r0, r6\n"
        "    blt .L080EDC78\n"
        "    cmp r4, r5\n"
        "    blo .L080EDC4E\n"
        "    ldr r1, [sp, #0x84]\n"
        "    lsls r0, r1, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    subs r1, r4, r0\n"
        "    mov r2, ip\n"
        "    lsls r0, r2, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    subs r0, r0, r5\n"
        "    cmp r1, r0\n"
        "    bls .L080EDCC4\n"
        "    cmp r1, #0xa\n"
        "    bls .L080EDCBA\n"
        "    add r0, sp, #0x40\n"
        "    mov r3, r8\n"
        "    lsls r1, r3, #1\n"
        "    adds r0, r0, r1\n"
        "    add r7, sp, #0x84\n"
        "    ldrh r7, [r7]\n"
        "    strh r7, [r0]\n"
        "    .2byte 0x4469 @ add r1, sp, r1\n"
        "    subs r0, r4, #1\n"
        "    strh r0, [r1]\n"
        "    movs r0, #1\n"
        "    add r8, r0\n"
        ".L080EDCBA:\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0x84]\n"
        "    b .L080EDCE8\n"
        ".L080EDCC4:\n"
        "    cmp r0, #0xa\n"
        "    bls .L080EDCE0\n"
        "    add r1, sp, #0x40\n"
        "    mov r3, r8\n"
        "    lsls r2, r3, #1\n"
        "    adds r1, r1, r2\n"
        "    adds r0, r5, #1\n"
        "    strh r0, [r1]\n"
        "    mov r7, sp\n"
        "    adds r0, r7, r2\n"
        "    mov r1, ip\n"
        "    strh r1, [r0]\n"
        "    movs r2, #1\n"
        "    add r8, r2\n"
        ".L080EDCE0:\n"
        "    subs r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov ip, r0\n"
        ".L080EDCE8:\n"
        "    mov r3, ip\n"
        "    lsls r1, r3, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    ldr r7, [sp, #0x84]\n"
        "    lsls r0, r7, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    subs r1, r1, r0\n"
        "    cmp r1, #0xa\n"
        "    bgt .L080EDC22\n"
        "    mov r0, r8\n"
        "    cmp r0, #0\n"
        "    bne .L080EDC08\n"
        ".L080EDD00:\n"
        "    ldr r0, [sp, #0x80]\n"
        "    mov r1, sl\n"
        "    mov r2, sb\n"
        "    bl Battle_SortEntriesInsertion\n"
        "    add sp, #0x88\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// Battle_RollSpeed @ 0x080EDD1C
s32 Battle_RollSpeed(s32 who)
{
    u8 *c = Battle_GetCombatant(who + 0x8000);
    s32 kind = sub_080C35E4(who);
    s32 v = (s8)c[0x44];
    s32 bonus;

    if (*(u16 *)(c + 0x10) & 0x800)
        v = 0x3C;
    bonus = 0;
    if (who < 16 && !Party_GetRow(who))
        bonus = Math_DivRound(v, 2);
    v = v * 2 + bonus + (Random_Byte() & 0xF);
    if (kind == 7)
        v += sub_080EDB04() >> 1;
    return v;
}

// Battle_BuildActionOrder @ 0x080EDD8C
/* Builds the action order: living party members and enemies, sorted by speed. */
void Battle_BuildActionOrder(void)
{
    u8 *g = gGameState;
    s8 *party = (s8 *)(g + 0xA20);
    struct SortEntry *list = BSTATE->order;
    struct SortEntry *e = list;
    u16 mode = BSTATE->unk2;
    s32 n = 0;
    s32 i;

    if (!(BSTATE->flags & 0x2000) && mode != 0xC000)
    {
        for (i = 5; i >= 0; i--)
        {
            s32 who = *party++;

            if (who != -1 && !(*(u16 *)(Party_GetMember(who + 0x8000) + 0x10) & 0xB160))
            {
                e->id = who;
                e->key = -Battle_RollSpeed(who);
                e++;
                n++;
            }
        }
    }
    if (mode != 0x8000)
    {
        for (i = 0x10; i < 0x18; i++)
        {
            if (*(u16 *)(Battle_GetCombatant(i + 0x8000) + 0xE) != 0)
            {
                /* the first roll is thrown away */
                Battle_RollSpeed(i);
                e->id = i;
                e->key = -Battle_RollSpeed(i);
                e++;
                n++;
            }
        }
    }
    e->id = 0xFFFF;
    Battle_SortEntriesInsertion(0, n, list);
}

// sub_080EDE70 @ 0x080EDE70
#ifdef NONMATCHING
u32 sub_080EDE70(void)
{
    s16 r;
    s32 a, b;
    s16 d;
    u16 m;
    s32 v;

    if (!(BattleFlags_Get() & 0x20))
    {
        r = (u16)sub_080EDB04();
        a = sub_080F43A4(5) / 2 + sub_080F43A4(4) + r;
        b = sub_080F43E0(5) / 2 + sub_080F43E0(4) + (((r ^ 0xF) - 7) & 0xFF);
        d = a - b;
        v = m = d & 0x7FFF;
        if (m == 0)
            return 0;
        if (d < 0)
            v = (m ^ 0x7FFF) + 1;
        if ((Random_Byte() & 0x3F) >= (s16)v)
            return 0;
        if (d < 0)
            return 0xC000;
    }
    return 0x8000;
}
#else
NAKED u32 sub_080EDE70(void)
{
    asm_unified(
        ".L080EDE70:\n"
        "    push {r4, r5, r6, lr}\n"
        "    bl BattleFlags_Get\n"
        "    movs r1, #0x20\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    bne .L080EDF02\n"
        "    bl sub_080EDB04\n"
        "    adds r4, r0, #0\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    movs r0, #5\n"
        "    bl sub_080F43A4\n"
        "    adds r6, r0, #0\n"
        "    movs r0, #4\n"
        "    bl sub_080F43A4\n"
        "    lsrs r1, r6, #0x1f\n"
        "    adds r6, r6, r1\n"
        "    asrs r6, r6, #1\n"
        "    adds r6, r6, r0\n"
        "    lsls r4, r4, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    adds r6, r6, r4\n"
        "    movs r0, #5\n"
        "    bl sub_080F43E0\n"
        "    adds r5, r0, #0\n"
        "    movs r0, #4\n"
        "    bl sub_080F43E0\n"
        "    lsrs r1, r5, #0x1f\n"
        "    adds r5, r5, r1\n"
        "    asrs r5, r5, #1\n"
        "    adds r5, r5, r0\n"
        "    movs r0, #0xf\n"
        "    eors r4, r0\n"
        "    subs r4, #7\n"
        "    movs r0, #0xff\n"
        "    ands r4, r0\n"
        "    adds r5, r5, r4\n"
        "    subs r6, r6, r5\n"
        "    lsls r6, r6, #0x10\n"
        "    asrs r4, r6, #0x10\n"
        "    ldr r1, .L080EDEF4\n"
        "    lsrs r6, r6, #0x10\n"
        "    ands r6, r1\n"
        "    adds r0, r6, #0\n"
        "    cmp r0, #0\n"
        "    beq .L080EDEF0\n"
        "    cmp r4, #0\n"
        "    bge .L080EDEE0\n"
        "    eors r0, r1\n"
        "    adds r6, r0, #1\n"
        ".L080EDEE0:\n"
        "    bl Random_Byte\n"
        "    movs r1, #0x3f\n"
        "    ands r1, r0\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r1, r0\n"
        "    blo .L080EDEF8\n"
        ".L080EDEF0:\n"
        "    movs r0, #0\n"
        "    b .L080EDF06\n"
        ".L080EDEF4: .4byte 0x00007FFF\n"
        ".L080EDEF8:\n"
        "    cmp r4, #0\n"
        "    bge .L080EDF02\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #8\n"
        "    b .L080EDF06\n"
        ".L080EDF02:\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #8\n"
        ".L080EDF06:\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

// sub_080EDF0C @ 0x080EDF0C
u32 sub_080EDF0C(void)
{
    s32 count, sum, v, i, who;
    s8 *party;
    u8 *g;

    if (sub_080EDAD0() || (sub_080ED8F4() & 0x100) || Flag_Test(0x166))
        return 0x145;
    g = gGameState;
    if (*(u16 *)(g + 0xAC0) != 1 && View_GetWall(2, 0, 0) == 1)
        return 0x146;
    if (sub_080ED92C() == 0x8000)
        return 0x144;
    count = 0;
    sum = 0;
    for (i = 0, party = gUnk_030050E0; i < 6; i++)
    {
        who = *(s8 *)(i + (u32)party);

        if (who >= 0 && !Combatant_IsDead(who))
        {
            count++;
            sum += (u16)Combatant_GetAgility(who) + (u16)Combatant_GetLuck(who);
        }
    }
    /* v stays unset when no enemy is found (original bug) */
    for (i = 0; i < 8; i++)
    {
        if (Combatant_IsUsed(i + 0x10))
        {
            who = i + 0x10;
            v = (u16)Combatant_GetAgility(who) + (u16)Combatant_GetLuck(who);
            break;
        }
    }
    v *= count;
    v += Random_Byte() & 7;
    if (v >= sum && (Random_Byte() & 0xF))
        return 0x145;
    return 0x144;
}

// sub_080EE028 @ 0x080EE028
#ifdef NONMATCHING
u32 sub_080EE028(s32 att, s32 def)
{
    s32 mode = BSTATE->unk15C;
    u8 *d;
    u8 *a;
    s32 kind;
    s32 v;

    if (mode == 0)
        return 0;
    if (mode == -1)
        goto ret1;
    d = Battle_GetCombatant(def + 0x8000);
    if (*(u16 *)(d + 0x10) & 0x3160)
        goto ret1;
    a = Battle_GetCombatant(att + 0x8000);
    kind = (s8)a[0x17];
    if (kind == 8)
        goto ret1;
    if (kind == 0xB || kind == 7)
    {
        s8 lv = d[0x41];

        v = lv * 2 - 1;
        v = (v - *(s16 *)(a + 0x56) + 0x10) * 2;
        if (v > 0xFF)
            goto ret1;
    }
    else
    {
        v = *(s16 *)(d + 0x52);
        if (kind == 4 || kind == 0xA)
            v -= *(s16 *)(a + 0x4A);
        else
            v -= *(s16 *)(a + 0x4E);
        v += 0x10;
        if (v < 0)
            goto ret1;
        v = v * v;
        v >>= 5;
        {
            u32 k = sub_080EFD84(att) + 4;

            v = v * 8 / gUnknown_0876F78E[k];
        }
    }
    if ((s32)Random_Byte() <= v)
        goto ret0;
ret1:
    return 1;
ret0:
    return 0;
}
#else
NAKED u32 sub_080EE028(s32 att, s32 def)
{
    asm_unified(
        ".L080EE028:\n"
        "    push {r4, r5, r6, lr}\n"
        "    adds r6, r0, #0\n"
        "    ldr r0, .L080EE09C\n"
        "    ldr r0, [r0]\n"
        "    movs r2, #0xae\n"
        "    lsls r2, r2, #1\n"
        "    adds r0, r0, r2\n"
        "    ldr r2, [r0]\n"
        "    cmp r2, #0\n"
        "    beq .L080EE104\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r2, r0\n"
        "    beq .L080EE0FA\n"
        "    ldr r0, .L080EE0A0\n"
        "    adds r5, r0, #0\n"
        "    adds r0, r1, r5\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    adds r4, r0, #0\n"
        "    ldrh r1, [r4, #0x10]\n"
        "    ldr r0, .L080EE0A4\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L080EE0FA\n"
        "    adds r0, r6, r5\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    adds r1, r0, #0\n"
        "    movs r3, #0x17\n"
        "    ldrsb r3, [r1, r3]\n"
        "    cmp r3, #8\n"
        "    beq .L080EE0FA\n"
        "    cmp r3, #0xb\n"
        "    beq .L080EE07A\n"
        "    cmp r3, #7\n"
        "    bne .L080EE0A8\n"
        ".L080EE07A:\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x41\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    lsls r0, r0, #1\n"
        "    subs r0, #1\n"
        "    adds r1, #0x56\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r1, r2]\n"
        "    subs r0, r0, r1\n"
        "    adds r0, #0x10\n"
        "    lsls r4, r0, #1\n"
        "    cmp r4, #0xff\n"
        "    bgt .L080EE0FA\n"
        "    b .L080EE0F2\n"
        "    .byte 0x00, 0x00\n"
        ".L080EE09C: .4byte 0x03006434 @ IWRAM+0x6434\n"
        ".L080EE0A0: .4byte 0xFFFF8000\n"
        ".L080EE0A4: .4byte 0x00003160\n"
        ".L080EE0A8:\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x52\n"
        "    movs r2, #0\n"
        "    ldrsh r4, [r0, r2]\n"
        "    cmp r3, #4\n"
        "    beq .L080EE0B8\n"
        "    cmp r3, #0xa\n"
        "    bne .L080EE0C2\n"
        ".L080EE0B8:\n"
        "    adds r0, r1, #0\n"
        "    adds r0, #0x4a\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    b .L080EE0CA\n"
        ".L080EE0C2:\n"
        "    adds r0, r1, #0\n"
        "    adds r0, #0x4e\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r0, r2]\n"
        ".L080EE0CA:\n"
        "    subs r4, r4, r0\n"
        "    adds r4, #0x10\n"
        "    cmp r4, #0\n"
        "    blt .L080EE0FA\n"
        "    adds r0, r4, #0\n"
        "    muls r0, r4, r0\n"
        "    adds r4, r0, #0\n"
        "    asrs r4, r4, #5\n"
        "    adds r0, r6, #0\n"
        "    bl sub_080EFD84\n"
        "    adds r0, #4\n"
        "    lsls r2, r4, #3\n"
        "    ldr r1, .L080EE100\n"
        "    adds r0, r0, r1\n"
        "    ldrb r1, [r0]\n"
        "    adds r0, r2, #0\n"
        "    bl __divsi3\n"
        "    adds r4, r0, #0\n"
        ".L080EE0F2:\n"
        "    bl Random_Byte\n"
        "    cmp r0, r4\n"
        "    ble .L080EE104\n"
        ".L080EE0FA:\n"
        "    movs r0, #1\n"
        "    b .L080EE106\n"
        "    .byte 0x00, 0x00\n"
        ".L080EE100: .4byte gUnknown_0876F78E\n"
        ".L080EE104:\n"
        "    movs r0, #0\n"
        ".L080EE106:\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif


// Battle_BuildTargetList @ 0x080EE10C
/* Builds the target list for an attacker. */
void Battle_BuildTargetList(s32 who)
{
    s32 mode = BSTATE->unk15C;
    s32 n = 0;
    s32 i;
    s32 p;
    u8 *c;

    BSTATE->targets[0].id = 0xFFFF;
    c = Battle_GetCombatant(who + 0x8000);
    if ((s8)c[0x17] == 0xB && c[0x5C] == 0x5C)
    {
        for (i = 0; i < 6; i++)
        {
            c = Party_GetMember(i);
            if (c != NULL && !Combatant_IsDead(i) && !Combatant_IsAlignmentCompatible(who, c[0xC]))
            {
                BSTATE->targets[n].id = c[0xC];
                n++;
            }
        }
        for (i = 0x10; i < 0x18; i++)
        {
            Party_GetMember(i + 0x8000);
            if (Combatant_IsUsed(i) == 1 && !Combatant_IsDead(i) && !Combatant_IsAlignmentCompatible(who, i))
            {
                BSTATE->targets[n].id = i;
                n++;
            }
        }
        BSTATE->targets[n].id = 0xFFFF;
        if (n != 0)
            return;
    }
    if ((u32)(mode + 1) <= 1)
        return;
    if (mode == 0x8000)
    {
        for (i = 0; i < 6; i++)
        {
            p = sub_080F40EC(i);
            if (p >= 0 && !Combatant_IsDead(p))
            {
                BSTATE->targets[n].id = p;
                n++;
            }
        }
    }
    else
    {
        for (i = 0; i < 6; i++)
        {
            p = sub_080F40EC(i);
            if (p >= 0 && !Combatant_IsDead(p))
            {
                s32 r;

                BSTATE->targets[n].id = p;
                r = Random_Byte();
                if (Party_GetRow(p) == 1)
                    r = r * 75 / 100;
                BSTATE->targets[n].key = -r;
                n++;
            }
        }
        Battle_SortEntriesInsertion(0, n, BSTATE->targets);
    }
    BSTATE->targets[n].id = 0xFFFF;
}
