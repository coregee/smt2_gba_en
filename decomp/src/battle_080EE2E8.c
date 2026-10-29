/* Battle: building the list of targets an action can hit. */

#include "global.h"

struct EE2E8SortEntry
{
    u16 id;
    s16 key;
};

/* Battle state at 0x0203D16C, reached through gUnk_03006434: only the fields used here. */
struct EE2E8State
{
    u8 pad000[0x130];
    struct EE2E8SortEntry targets[10];  /* 0x130: ended by id 0xFFFF */
    u8 pad158[0x15C - 0x158];
    u32 targetMask;                     /* 0x15C: status bits that exclude a target */
    u32 unk160[24];                     /* 0x160: per combatant */
};
extern struct EE2E8State *gUnk_03006434;

/* One combatant (0x80 bytes): only the fields used here. */
struct EE2E8Unit
{
    u8 pad00[0xC];
    u8 id;              /* 0x0C */
    u8 level;           /* 0x0D */
    u8 pad0E[0x10 - 0xE];
    u16 flags;          /* 0x10 */
    u8 pad12[0x17 - 0x12];
    s8 command;         /* 0x17 */
    s16 hp;             /* 0x18 */
    u8 pad1A[0x40 - 0x1A];
    s8 stats[6];        /* 0x40 */
    u8 pad46[0x5C - 0x46];
    u8 chosen;          /* 0x5C */
    u8 pad5D[0x80 - 0x5D];
};

/* The battle EWRAM block at 0x0203C200: only the field used here. */
struct EE2E8Battle
{
    u8 pad000[0x9A0];
    struct EE2E8Unit units[8];  /* 0x9A0: combatants 0x10-0x17 */
};
extern u8 gUnk_0203C200[];
#define BB ((struct EE2E8Battle *)gUnk_0203C200)

extern const u16 gUnknown_0876F6C4[3];

struct EE2E8Unit *Battle_GetCombatant(u16 idx);
struct EE2E8Unit *Party_GetMember(u16 id);
u32 Combatant_IsDead(s32 who);
s32 Combatant_IsUsed(s32 who);
s32 Combatant_IsAlignmentCompatible(s32 a, s32 b);
u32 sub_080ED974(s32 who);
u32 sub_080EDA24(s32 side);
u32 sub_080ED990(s32 side);
u32 Battle_IsTwoSided(void);
s32 Math_DivRound(s32 a, s32 b);
u32 Random_Byte(void);
void Battle_SortEntriesInsertion(u16 lo, u16 hi, struct EE2E8SortEntry *a);

// Battle_BuildActionTargets @ 0x080EE2E8
/* Fills the target list of combatant `who`. Skill 0x5C hits every living combatant of an
   incompatible alignment and items 0xF1/0xF2 every living party member without status 0x4000.
   Otherwise the targets are the enemy group's units not excluded by targetMask: when the
   attacker's agility/luck/level roll beats the defender's they are sorted by status and HP
   (weakest first), else in random order. */
#ifdef NONMATCHING
void Battle_BuildActionTargets(s32 who)
{
    u32 mask = gUnk_03006434->targetMask;
    s32 n = 0;
    s32 i;
    s32 side, base, slot, count;
    struct EE2E8Unit *c;

    gUnk_03006434->targets[0].id = 0xFFFF;
    c = Battle_GetCombatant(who + 0x8000);
    if (c->command == 11 && c->chosen == 0x5C)
    {
        for (i = 0; i <= 5; i++)
        {
            c = Party_GetMember(i);
            if (c != NULL && !Combatant_IsDead(c->id) && !Combatant_IsAlignmentCompatible(who, c->id))
            {
                gUnk_03006434->targets[n].id = c->id;
                n++;
            }
        }
        for (i = 0x10; i <= 0x17; i++)
        {
            c = Party_GetMember(i + 0x8000);
            if (Combatant_IsUsed(i) == 1 && !Combatant_IsDead(i) && !Combatant_IsAlignmentCompatible(who, i))
            {
                gUnk_03006434->targets[n].id = i;
                n++;
            }
        }
        gUnk_03006434->targets[n].id = 0xFFFF;
        if (n != 0)
            return;
    }
    /* c is the last member looked at when the loops above ran */
    if (c->command == 8 && (u8)(c->chosen + 0xF) <= 1)
    {
        for (i = 0; i <= 5; i++)
        {
            c = Party_GetMember(i);
            if (c != NULL && !Combatant_IsDead(c->id) && !(c->flags & 0x4000))
            {
                gUnk_03006434->targets[n].id = c->id;
                n++;
            }
        }
        gUnk_03006434->targetMask = n;
        gUnk_03006434->targets[n].id = 0xFFFF;
        if (n != 0)
            return;
    }
    if (mask + 1 <= 1)
        return;
    side = sub_080ED974(gUnk_03006434->unk160[who]);
    if (!sub_080EDA24(side))
        side ^= 1;
    base = sub_080ED990(side);
    slot = base - 0x10;
    count = 8;
    if (Battle_IsTwoSided())
        count = 4;
    sub_080EDA24(side);
    if (mask == 0x8000)
    {
        struct EE2E8Unit *u;

        base = 0x10;
        u = &BB->units[0];
        for (i = 0x10; i < base + 8; i++, u++)
        {
            if (!(mask & u->flags))
            {
                gUnk_03006434->targets[n].id = i;
                n++;
            }
        }
    }
    else
    {
        s8 *a = Party_GetMember(who + 0x8000)->stats;
        s8 *d = BB->units[slot].stats;
        s32 hit = a[1] * 2 + Math_DivRound(a[4], 2) + Math_DivRound(a[5], 4);
        s32 ev;

        if (who > 3)
        {
            hit += Random_Byte() & 7;
            ev = d[1] * 2 + Math_DivRound(d[4], 2) + Math_DivRound(d[5], 4) + (Random_Byte() & 7);
        }
        else
            ev = (BB->units[slot].level >> 1) + (Random_Byte() & 0xF) + 0xE;

        if (ev < hit)
        {
            u16 m0 = gUnknown_0876F6C4[0];

            for (i = base; i < base + count; i++)
            {
                struct EE2E8Unit *u = &BB->units[i - 0x10];
                s32 key;

                if (!(u->flags & m0))
                    key = 0;
                else if (!(u->flags & gUnknown_0876F6C4[1]))
                    key = 0x2706;
                else if (!(u->flags & gUnknown_0876F6C4[2]))
                    key = 0x4E0C;
                else
                    continue;
                key += u->hp;
                gUnk_03006434->targets[n].id = i;
                gUnk_03006434->targets[n].key = key;
                n++;
            }
        }
        else
        {
            for (i = base; i < base + count; i++)
            {
                if (!(BB->units[i - 0x10].flags & 0x8000))
                {
                    gUnk_03006434->targets[n].id = i;
                    Random_Byte();
                    gUnk_03006434->targets[n].key = Random_Byte();
                    n++;
                }
            }
        }
        Battle_SortEntriesInsertion(0, n, gUnk_03006434->targets);
    }
    gUnk_03006434->targets[n].id = 0xFFFF;
}
#else
NAKED void Battle_BuildActionTargets(s32 who)
{
    asm_unified(
        ".L080EE2E8:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #8\n"
        "    str r0, [sp]\n"
        "    ldr r0, .L080EE4DC\n"
        "    ldr r1, [r0]\n"
        "    movs r2, #0xae\n"
        "    lsls r2, r2, #1\n"
        "    adds r0, r1, r2\n"
        "    ldr r6, [r0]\n"
        "    movs r7, #0\n"
        "    movs r4, #0x98\n"
        "    lsls r4, r4, #1\n"
        "    adds r1, r1, r4\n"
        "    ldr r0, .L080EE4E0\n"
        "    strh r0, [r1]\n"
        "    ldr r1, [sp]\n"
        "    ldr r2, .L080EE4E4\n"
        "    adds r0, r1, r2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    adds r4, r0, #0\n"
        "    movs r0, #0x17\n"
        "    ldrsb r0, [r4, r0]\n"
        "    cmp r0, #0xb\n"
        "    bne .L080EE3D0\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x5c\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0x5c\n"
        "    bne .L080EE3D0\n"
        "    movs r5, #0\n"
        ".L080EE332:\n"
        "    lsls r0, r5, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Party_GetMember\n"
        "    adds r4, r0, #0\n"
        "    cmp r4, #0\n"
        "    beq .L080EE36A\n"
        "    ldrb r0, [r4, #0xc]\n"
        "    bl Combatant_IsDead\n"
        "    cmp r0, #0\n"
        "    bne .L080EE36A\n"
        "    ldrb r1, [r4, #0xc]\n"
        "    ldr r0, [sp]\n"
        "    bl Combatant_IsAlignmentCompatible\n"
        "    cmp r0, #0\n"
        "    bne .L080EE36A\n"
        "    ldr r0, .L080EE4DC\n"
        "    ldr r1, [r0]\n"
        "    lsls r0, r7, #2\n"
        "    adds r1, r1, r0\n"
        "    ldrb r0, [r4, #0xc]\n"
        "    movs r4, #0x98\n"
        "    lsls r4, r4, #1\n"
        "    adds r1, r1, r4\n"
        "    strh r0, [r1]\n"
        "    adds r7, #1\n"
        ".L080EE36A:\n"
        "    adds r5, #1\n"
        "    cmp r5, #5\n"
        "    ble .L080EE332\n"
        "    movs r5, #0x10\n"
        ".L080EE372:\n"
        "    ldr r1, .L080EE4E4\n"
        "    adds r0, r5, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Party_GetMember\n"
        "    adds r4, r0, #0\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #1\n"
        "    bne .L080EE3B2\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_IsDead\n"
        "    cmp r0, #0\n"
        "    bne .L080EE3B2\n"
        "    ldr r0, [sp]\n"
        "    adds r1, r5, #0\n"
        "    bl Combatant_IsAlignmentCompatible\n"
        "    cmp r0, #0\n"
        "    bne .L080EE3B2\n"
        "    ldr r0, .L080EE4DC\n"
        "    ldr r0, [r0]\n"
        "    lsls r1, r7, #2\n"
        "    adds r0, r0, r1\n"
        "    movs r2, #0x98\n"
        "    lsls r2, r2, #1\n"
        "    adds r0, r0, r2\n"
        "    strh r5, [r0]\n"
        "    adds r7, #1\n"
        ".L080EE3B2:\n"
        "    adds r5, #1\n"
        "    cmp r5, #0x17\n"
        "    ble .L080EE372\n"
        "    ldr r0, .L080EE4DC\n"
        "    ldr r0, [r0]\n"
        "    lsls r1, r7, #2\n"
        "    adds r0, r0, r1\n"
        "    movs r1, #0x98\n"
        "    lsls r1, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    ldr r1, .L080EE4E0\n"
        "    strh r1, [r0]\n"
        "    cmp r7, #0\n"
        "    beq .L080EE3D0\n"
        "    b .L080EE69E\n"
        ".L080EE3D0:\n"
        "    movs r0, #0x17\n"
        "    ldrsb r0, [r4, r0]\n"
        "    cmp r0, #8\n"
        "    bne .L080EE44A\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x5c\n"
        "    ldrb r0, [r0]\n"
        "    adds r0, #0xf\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bhi .L080EE44A\n"
        "    movs r5, #0\n"
        ".L080EE3EA:\n"
        "    lsls r0, r5, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Party_GetMember\n"
        "    adds r4, r0, #0\n"
        "    cmp r4, #0\n"
        "    beq .L080EE424\n"
        "    ldrb r0, [r4, #0xc]\n"
        "    bl Combatant_IsDead\n"
        "    cmp r0, #0\n"
        "    bne .L080EE424\n"
        "    ldrh r0, [r4, #0x10]\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #7\n"
        "    adds r1, r2, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L080EE424\n"
        "    ldr r0, .L080EE4DC\n"
        "    ldr r1, [r0]\n"
        "    lsls r0, r7, #2\n"
        "    adds r1, r1, r0\n"
        "    ldrb r0, [r4, #0xc]\n"
        "    movs r4, #0x98\n"
        "    lsls r4, r4, #1\n"
        "    adds r1, r1, r4\n"
        "    strh r0, [r1]\n"
        "    adds r7, #1\n"
        ".L080EE424:\n"
        "    adds r5, #1\n"
        "    cmp r5, #5\n"
        "    ble .L080EE3EA\n"
        "    ldr r0, .L080EE4DC\n"
        "    ldr r0, [r0]\n"
        "    movs r2, #0xae\n"
        "    lsls r2, r2, #1\n"
        "    adds r1, r0, r2\n"
        "    str r7, [r1]\n"
        "    lsls r1, r7, #2\n"
        "    adds r0, r0, r1\n"
        "    movs r4, #0x98\n"
        "    lsls r4, r4, #1\n"
        "    adds r0, r0, r4\n"
        "    ldr r1, .L080EE4E0\n"
        "    strh r1, [r0]\n"
        "    cmp r7, #0\n"
        "    beq .L080EE44A\n"
        "    b .L080EE69E\n"
        ".L080EE44A:\n"
        "    adds r0, r6, #1\n"
        "    cmp r0, #1\n"
        "    bhi .L080EE452\n"
        "    b .L080EE69E\n"
        ".L080EE452:\n"
        "    ldr r0, .L080EE4DC\n"
        "    mov r8, r0\n"
        "    ldr r0, [r0]\n"
        "    ldr r2, [sp]\n"
        "    lsls r1, r2, #2\n"
        "    movs r4, #0xb0\n"
        "    lsls r4, r4, #1\n"
        "    adds r0, r0, r4\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    bl sub_080ED974\n"
        "    adds r4, r0, #0\n"
        "    bl sub_080EDA24\n"
        "    cmp r0, #0\n"
        "    bne .L080EE478\n"
        "    movs r0, #1\n"
        "    eors r4, r0\n"
        ".L080EE478:\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080ED990\n"
        "    mov sl, r0\n"
        "    mov r5, sl\n"
        "    subs r5, #0x10\n"
        "    bl Battle_IsTwoSided\n"
        "    movs r1, #8\n"
        "    str r1, [sp, #4]\n"
        "    cmp r0, #0\n"
        "    beq .L080EE494\n"
        "    movs r2, #4\n"
        "    str r2, [sp, #4]\n"
        ".L080EE494:\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080EDA24\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #8\n"
        "    cmp r6, r0\n"
        "    bne .L080EE4EC\n"
        "    movs r4, #0x10\n"
        "    mov sl, r4\n"
        "    movs r5, #0x10\n"
        "    ldr r0, .L080EE4E8\n"
        "    movs r1, #0x9a\n"
        "    lsls r1, r1, #4\n"
        "    adds r2, r0, r1\n"
        "    mov r4, r8\n"
        "    movs r3, #0x98\n"
        "    lsls r3, r3, #1\n"
        ".L080EE4B6:\n"
        "    ldrh r1, [r2, #0x10]\n"
        "    adds r0, r6, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L080EE4CC\n"
        "    ldr r0, [r4]\n"
        "    lsls r1, r7, #2\n"
        "    adds r0, r0, r1\n"
        "    adds r0, r0, r3\n"
        "    strh r5, [r0]\n"
        "    adds r7, #1\n"
        ".L080EE4CC:\n"
        "    adds r2, #0x80\n"
        "    adds r5, #1\n"
        "    mov r0, sl\n"
        "    adds r0, #8\n"
        "    cmp r5, r0\n"
        "    blt .L080EE4B6\n"
        "    b .L080EE68C\n"
        "    .byte 0x00, 0x00\n"
        ".L080EE4DC: .4byte 0x03006434 @ IWRAM+0x6434\n"
        ".L080EE4E0: .4byte 0x0000FFFF\n"
        ".L080EE4E4: .4byte 0xFFFF8000\n"
        ".L080EE4E8: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080EE4EC:\n"
        "    ldr r2, [sp]\n"
        "    ldr r4, .L080EE570\n"
        "    adds r0, r2, r4\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Party_GetMember\n"
        "    adds r4, r0, #0\n"
        "    adds r4, #0x40\n"
        "    lsls r6, r5, #7\n"
        "    ldr r1, .L080EE574\n"
        "    adds r0, r6, r1\n"
        "    movs r2, #0x9e\n"
        "    lsls r2, r2, #4\n"
        "    adds r2, r2, r0\n"
        "    mov r8, r2\n"
        "    movs r0, #4\n"
        "    ldrsb r0, [r4, r0]\n"
        "    movs r1, #2\n"
        "    bl Math_DivRound\n"
        "    adds r5, r0, #0\n"
        "    movs r0, #5\n"
        "    ldrsb r0, [r4, r0]\n"
        "    movs r1, #4\n"
        "    bl Math_DivRound\n"
        "    movs r1, #1\n"
        "    ldrsb r1, [r4, r1]\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r5\n"
        "    adds r1, r1, r0\n"
        "    mov sb, r1\n"
        "    ldr r4, [sp]\n"
        "    cmp r4, #3\n"
        "    ble .L080EE578\n"
        "    bl Random_Byte\n"
        "    movs r6, #7\n"
        "    ands r0, r6\n"
        "    add sb, r0\n"
        "    mov r1, r8\n"
        "    movs r0, #4\n"
        "    ldrsb r0, [r1, r0]\n"
        "    movs r1, #2\n"
        "    bl Math_DivRound\n"
        "    adds r5, r0, #0\n"
        "    mov r2, r8\n"
        "    movs r0, #5\n"
        "    ldrsb r0, [r2, r0]\n"
        "    movs r1, #4\n"
        "    bl Math_DivRound\n"
        "    adds r4, r0, #0\n"
        "    bl Random_Byte\n"
        "    mov r2, r8\n"
        "    movs r1, #1\n"
        "    ldrsb r1, [r2, r1]\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r5\n"
        "    adds r1, r1, r4\n"
        "    ands r0, r6\n"
        "    adds r0, r1, r0\n"
        "    b .L080EE592\n"
        ".L080EE570: .4byte 0xFFFF8000\n"
        ".L080EE574: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080EE578:\n"
        "    bl Random_Byte\n"
        "    ldr r4, .L080EE5C4\n"
        "    adds r1, r4, r6\n"
        "    ldr r2, .L080EE5C8\n"
        "    adds r1, r1, r2\n"
        "    ldrb r2, [r1]\n"
        "    lsrs r2, r2, #1\n"
        "    movs r1, #0xf\n"
        "    ands r1, r0\n"
        "    adds r2, r2, r1\n"
        "    adds r0, r2, #0\n"
        "    adds r0, #0xe\n"
        ".L080EE592:\n"
        "    cmp r0, sb\n"
        "    bge .L080EE61C\n"
        "    mov r5, sl\n"
        "    ldr r4, [sp, #4]\n"
        "    adds r0, r5, r4\n"
        "    ldr r1, .L080EE5CC\n"
        "    mov r8, r1\n"
        "    cmp r5, r0\n"
        "    bge .L080EE678\n"
        "    ldr r3, .L080EE5D0\n"
        "    ldrh r6, [r3]\n"
        ".L080EE5A8:\n"
        "    lsls r0, r5, #7\n"
        "    movs r2, #0xd0\n"
        "    lsls r2, r2, #1\n"
        "    adds r0, r0, r2\n"
        "    ldr r1, .L080EE5C4\n"
        "    adds r4, r1, r0\n"
        "    ldrh r1, [r4, #0x10]\n"
        "    adds r2, r1, #0\n"
        "    adds r0, r1, #0\n"
        "    ands r0, r6\n"
        "    cmp r0, #0\n"
        "    bne .L080EE5D4\n"
        "    movs r2, #0\n"
        "    b .L080EE5EE\n"
        ".L080EE5C4: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080EE5C8: .4byte 0x000009AD\n"
        ".L080EE5CC: .4byte 0x03006434 @ IWRAM+0x6434\n"
        ".L080EE5D0: .4byte gUnknown_0876F6C4\n"
        ".L080EE5D4:\n"
        "    ldrh r0, [r3, #2]\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    bne .L080EE5E4\n"
        "    ldr r2, .L080EE5E0\n"
        "    b .L080EE5EE\n"
        ".L080EE5E0: .4byte 0x00002706\n"
        ".L080EE5E4:\n"
        "    ldrh r0, [r3, #4]\n"
        "    ands r2, r0\n"
        "    cmp r2, #0\n"
        "    bne .L080EE60C\n"
        "    ldr r2, .L080EE618\n"
        ".L080EE5EE:\n"
        "    movs r1, #0x18\n"
        "    ldrsh r0, [r4, r1]\n"
        "    adds r2, r2, r0\n"
        "    mov r4, r8\n"
        "    ldr r1, [r4]\n"
        "    lsls r0, r7, #2\n"
        "    adds r1, r1, r0\n"
        "    movs r4, #0x98\n"
        "    lsls r4, r4, #1\n"
        "    adds r0, r1, r4\n"
        "    strh r5, [r0]\n"
        "    adds r4, #2\n"
        "    adds r0, r1, r4\n"
        "    strh r2, [r0]\n"
        "    adds r7, #1\n"
        ".L080EE60C:\n"
        "    adds r5, #1\n"
        "    ldr r0, [sp, #4]\n"
        "    add r0, sl\n"
        "    cmp r5, r0\n"
        "    blt .L080EE5A8\n"
        "    b .L080EE678\n"
        ".L080EE618: .4byte 0x00004E0C\n"
        ".L080EE61C:\n"
        "    mov r5, sl\n"
        "    ldr r1, [sp, #4]\n"
        "    adds r0, r5, r1\n"
        "    cmp r5, r0\n"
        "    bge .L080EE678\n"
        "    ldr r2, .L080EE6B0\n"
        "    mov r8, r2\n"
        "    lsls r0, r5, #7\n"
        "    movs r4, #0xd0\n"
        "    lsls r4, r4, #1\n"
        "    adds r0, r0, r4\n"
        "    ldr r1, .L080EE6B4\n"
        "    adds r6, r0, r1\n"
        ".L080EE636:\n"
        "    ldrh r0, [r6, #0x10]\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #8\n"
        "    adds r1, r2, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L080EE66C\n"
        "    mov r4, r8\n"
        "    ldr r0, [r4]\n"
        "    lsls r4, r7, #2\n"
        "    adds r0, r0, r4\n"
        "    movs r1, #0x98\n"
        "    lsls r1, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    strh r5, [r0]\n"
        "    bl Random_Byte\n"
        "    bl Random_Byte\n"
        "    mov r2, r8\n"
        "    ldr r1, [r2]\n"
        "    adds r1, r1, r4\n"
        "    movs r4, #0x99\n"
        "    lsls r4, r4, #1\n"
        "    adds r1, r1, r4\n"
        "    strh r0, [r1]\n"
        "    adds r7, #1\n"
        ".L080EE66C:\n"
        "    adds r6, #0x80\n"
        "    adds r5, #1\n"
        "    ldr r0, [sp, #4]\n"
        "    add r0, sl\n"
        "    cmp r5, r0\n"
        "    blt .L080EE636\n"
        ".L080EE678:\n"
        "    lsls r1, r7, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    ldr r0, .L080EE6B0\n"
        "    ldr r2, [r0]\n"
        "    movs r0, #0x98\n"
        "    lsls r0, r0, #1\n"
        "    adds r2, r2, r0\n"
        "    movs r0, #0\n"
        "    bl Battle_SortEntriesInsertion\n"
        ".L080EE68C:\n"
        "    ldr r0, .L080EE6B0\n"
        "    ldr r0, [r0]\n"
        "    lsls r1, r7, #2\n"
        "    adds r0, r0, r1\n"
        "    movs r1, #0x98\n"
        "    lsls r1, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    ldr r1, .L080EE6B8\n"
        "    strh r1, [r0]\n"
        ".L080EE69E:\n"
        "    add sp, #8\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080EE6B0: .4byte 0x03006434 @ IWRAM+0x6434\n"
        ".L080EE6B4: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080EE6B8: .4byte 0x0000FFFF\n"
    );
}
#endif
