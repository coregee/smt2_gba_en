/* After-battle recovery, continued: choosing a curing item or a healing caster. The goto
   loops reproduce the original's code layout (the compiler did not treat them as loops). */

#include "global.h"
#include "bmenu2.h"

/* Uses the first owned item of the 0x0877A509 list on `who`. */
// sub_0812E47C @ 0x0812E47C
s32 sub_0812E47C(s32 who)
{
    const u8 *p;

    if (!(u16)sub_080C2C30())
        goto start;
    goto none;
useItem:
    Party_UseItemOn(who, 0, *p);
    return 1;
start:
    p = gUnknown_0877A509;
    goto check;
next:
    if (sub_080C10B4(*p))
        goto useItem;
    p++;
check:
    if (*p != 0xFF)
        goto next;
none:
    return 0;
}

/* Cures member `who`'s ailments with an owned item, else with a party member's skill. */
// sub_0812E4C0 @ 0x0812E4C0
s32 sub_0812E4C0(s32 who)
{
    const struct C12BCureEntry *p;
    s16 r;
    u16 flags = gGameState.members[who].flags;

    if (!(u16)sub_080C2C30())
    {
        for (p = gUnknown_0877A50C; p->id != 0xFF; p++)
        {
            if (sub_080C10B4(p->id) && (p->mask & flags))
            {
                Party_UseItemOn(who, 0, p->id);
                return 1;
            }
        }
    }
    if (sub_080F31E0())
        return 0;
    for (p = gUnknown_0877A52C; p->id != 0xFF; p++)
    {
        r = Party_FindSkillCaster(p->id);
        if (r >= 0 && (p->mask & flags))
        {
            Party_CastSkillOn(who, r, p->id);
            return 1;
        }
    }
    return 0;
}

/* A party member who knows `skill`, can act and has the MP for it, or -1. Demons
   (members 4-15, 8 skill slots) are tried before humans 1-3 (32 slots). */
// Party_FindSkillCaster @ 0x0812E558
#ifdef NONMATCHING
s32 Party_FindSkillCaster(u16 skill)
{
    s32 found[6];
    s32 n;
    s32 k;
    s32 i;
    s32 j;
    s32 *out;
    s32 *p;
    u8 *s;

    n = 0;
    for (k = 0; k < 6; k++)
        found[k] = -1;
    out = &found[n];
    for (i = 4; i <= 15; i++)
    {
        s = (u8 *)&gGameState.members[i] + 0x5D;
        if (Combatant_IsInParty(i) && !(Combatant_GetStatus(i) & 0xB063))
        {
            for (j = 0; j <= 7; j++)
            {
                if (s[j] != 0xFF && s[j] == skill)
                {
                    *out++ = i;
                    n++;
                    break;
                }
            }
        }
    }
    out = &found[n];
    for (i = 1; i <= 3; i++)
    {
        s = (u8 *)&gGameState.members[i] + 0x5D;
        if (Combatant_IsInParty(i) && !(Combatant_GetStatus(i) & 0xB063))
        {
            for (j = 0; j <= 31; j++)
            {
                if (s[j] != 0xFF && s[j] == skill)
                {
                    *out++ = i;
                    n++;
                    break;
                }
            }
        }
    }
    if (n != 0)
    {
        p = found;
        for (i = 0; i <= 5; i++, p++)
        {
            if (*p != -1 && gGameState.members[*p].mp >= sub_080ED6CC(skill))
                return *p;
        }
    }
    return -1;
}
#else
NAKED
s32 Party_FindSkillCaster(u16 skill)
{
    asm_unified(
        ".L0812E558:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sb\n"
        "    mov r6, r8\n"
        "    push {r6, r7}\n"
        "    sub sp, #0x18\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        "    movs r6, #0\n"
        "    movs r1, #1\n"
        "    rsbs r1, r1, #0\n"
        "    add r0, sp, #0x14\n"
        ".L0812E570:\n"
        "    str r1, [r0]\n"
        "    subs r0, #4\n"
        "    cmp r0, sp\n"
        "    bge .L0812E570\n"
        "    movs r5, #4\n"
        "    lsls r0, r6, #2\n"
        "    mov r1, sp\n"
        "    adds r7, r0, r1\n"
        ".L0812E580:\n"
        "    lsls r0, r5, #7\n"
        "    ldr r1, .L0812E5B4\n"
        "    adds r4, r0, r1\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_IsInParty\n"
        "    cmp r0, #0\n"
        "    beq .L0812E5D2\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_GetStatus\n"
        "    ldr r2, .L0812E5B8\n"
        "    adds r1, r2, #0\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    bne .L0812E5D2\n"
        "    movs r2, #0\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x5d\n"
        "    ldrb r1, [r0]\n"
        "    adds r3, r0, #0\n"
        "    cmp r1, #0xff\n"
        "    beq .L0812E5BC\n"
        "    ldrb r0, [r3]\n"
        "    b .L0812E5CA\n"
        "    .byte 0x00, 0x00\n"
        ".L0812E5B4: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L0812E5B8: .4byte 0x0000B063\n"
        ".L0812E5BC:\n"
        "    adds r2, #1\n"
        "    cmp r2, #7\n"
        "    bgt .L0812E5D2\n"
        "    adds r1, r3, r2\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0xff\n"
        "    beq .L0812E5BC\n"
        ".L0812E5CA:\n"
        "    cmp r0, r8\n"
        "    bne .L0812E5BC\n"
        "    stm r7!, {r5}\n"
        "    adds r6, #1\n"
        ".L0812E5D2:\n"
        "    adds r5, #1\n"
        "    cmp r5, #0xf\n"
        "    ble .L0812E580\n"
        "    movs r5, #1\n"
        "    lsls r0, r6, #2\n"
        "    mov r1, sp\n"
        "    adds r7, r0, r1\n"
        ".L0812E5E0:\n"
        "    lsls r0, r5, #7\n"
        "    ldr r1, .L0812E618\n"
        "    adds r4, r0, r1\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_IsInParty\n"
        "    adds r2, r5, #1\n"
        "    mov sb, r2\n"
        "    cmp r0, #0\n"
        "    beq .L0812E636\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_GetStatus\n"
        "    ldr r2, .L0812E61C\n"
        "    adds r1, r2, #0\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    bne .L0812E636\n"
        "    movs r2, #0\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x5d\n"
        "    ldrb r1, [r0]\n"
        "    adds r3, r0, #0\n"
        "    cmp r1, #0xff\n"
        "    beq .L0812E620\n"
        "    ldrb r0, [r3]\n"
        "    b .L0812E62E\n"
        "    .byte 0x00, 0x00\n"
        ".L0812E618: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L0812E61C: .4byte 0x0000B063\n"
        ".L0812E620:\n"
        "    adds r2, #1\n"
        "    cmp r2, #0x1f\n"
        "    bgt .L0812E636\n"
        "    adds r1, r3, r2\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0xff\n"
        "    beq .L0812E620\n"
        ".L0812E62E:\n"
        "    cmp r0, r8\n"
        "    bne .L0812E620\n"
        "    stm r7!, {r5}\n"
        "    adds r6, #1\n"
        ".L0812E636:\n"
        "    mov r5, sb\n"
        "    cmp r5, #3\n"
        "    ble .L0812E5E0\n"
        "    cmp r6, #0\n"
        "    bne .L0812E646\n"
        "    b .L0812E670\n"
        ".L0812E642:\n"
        "    ldr r0, [r5]\n"
        "    b .L0812E674\n"
        ".L0812E646:\n"
        "    movs r6, #0\n"
        "    mov r5, sp\n"
        ".L0812E64A:\n"
        "    ldr r1, [r5]\n"
        "    movs r7, #1\n"
        "    rsbs r7, r7, #0\n"
        "    cmp r1, r7\n"
        "    beq .L0812E668\n"
        "    lsls r1, r1, #7\n"
        "    ldr r0, .L0812E684\n"
        "    adds r4, r1, r0\n"
        "    movs r0, #0x1c\n"
        "    ldrsh r4, [r4, r0]\n"
        "    mov r0, r8\n"
        "    bl sub_080ED6CC\n"
        "    cmp r4, r0\n"
        "    bhs .L0812E642\n"
        ".L0812E668:\n"
        "    adds r5, #4\n"
        "    adds r6, #1\n"
        "    cmp r6, #5\n"
        "    ble .L0812E64A\n"
        ".L0812E670:\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        ".L0812E674:\n"
        "    add sp, #0x18\n"
        "    pop {r3, r4}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L0812E684: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
    );
}
#endif

// Party_CastSkillOn @ 0x0812E688
void Party_CastSkillOn(s16 target, s16 caster, s16 skill)
{
    struct Action a;

    a.att = caster;
    a.def = target;
    sub_080F4988(&a, skill);
    sub_080ED6DC(caster, skill);
    gUnk_030020B4 = 1;
}

/* Uses `item` on `target`; item 0xB5 is kept with probability 7/8. */
// Party_UseItemOn @ 0x0812E6C4
void Party_UseItemOn(s16 target, s16 user, u16 item)
{
    struct Action a;
    s32 attr;
    s16 used = 0xFFFF;

    a.att = user;
    a.def = target;
    Item_GetAttribute((s16)item, 0xC, &attr);
    if (attr <= 0x7F)
        sub_080F4988(&a, attr);
    else
        Item_RunUseEffect(&a, (s16)item);
    if ((s16)item == 0xB5 && (Random_Byte() & 7))
        used = 0;
    sub_080F3E54((s16)item, used);
    gUnk_030020B4 = 1;
}

// sub_0812E734 @ 0x0812E734
void sub_0812E734(void)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk48 = Task_Create(gUnknown_0877A54C, 0xFFFF);
    blk->unk692 = 0xFE;
    sub_080EA210();
    gUnk_030065CC[1] = 0;
}

// sub_0812E770 @ 0x0812E770
void sub_0812E770(void)
{
    BattleMsg_Close();
    sub_08128EB4();
}
