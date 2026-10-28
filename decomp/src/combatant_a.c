#include "global.h"
#include "combatant.h"

// sub_080BF908 @ 0x080BF908
void sub_080BF908(s8 id, s16 *a, s16 *b)
{
    if (id != -1)
    {
        u8 *rec = Equipment_GetRecord36_MidRange(id);

        *a += rec[1];
        *b += rec[2];
    }
}

// Combatant_RecalcStats @ 0x080BF938
/* Recomputes a combatant's total stats (0x40) and derived values (0x48-0x56, max HP/MP). */
#ifdef NONMATCHING
void Combatant_RecalcStats(s32 who)
{
    struct Combatant *c = Battle_GetCombatant(who + 0x8000);
    u16 s0, s1, s2, s3, s4, s5;
    u16 f;
    u32 i;

    Equipment_SumStatBonuses(c->equip, c->bonus.v);
    sub_080BFEA8(c);
    sub_080BFF0C(c);
    f = Combatant_GetStatus(c->id) & 0x800;
    s1 = (f != 0);
    s0 = s1;
    s2 = s1;
    s3 = s1;
    s5 = s1;
    if (s1)
    {
        s4 = 40;
    }
    else
    {
        s0 = c->base.v[0] + c->bonus.v[0] + c->extra.v[0];
        s1 = c->base.v[1] + c->bonus.v[1] + c->extra.v[1];
        s2 = c->base.v[2] + c->bonus.v[2] + c->extra.v[2];
        s3 = c->base.v[3] + c->bonus.v[3] + c->extra.v[3];
        s4 = c->base.v[4] + c->bonus.v[4] + c->extra.v[4];
        s5 = c->base.v[5] + c->bonus.v[5] + c->extra.v[5];
        if (c->id == 0)
        {
            const struct C0bfStatBonus *tbl = gUnknown_081A6ED4;

            for (i = 0; i < 12; i++)
            {
                if (sub_080C32D4(i + 0x120) > 8)
                {
                    u8 v = tbl[i].b;

                    s0 += v >> 4;
                    s1 += v & 0xF;
                    v = tbl[i].c;
                    s2 += v >> 4;
                    s3 += v & 0xF;
                    v = tbl[i].d;
                    s4 += v >> 4;
                    s5 += v & 0xF;
                }
            }
        }
    }
    c->total.v[0] = s0;
    c->total.v[1] = s1;
    c->total.v[2] = s2;
    c->total.v[3] = s3;
    c->total.v[4] = s4;
    c->total.v[5] = s5;
    if (c->id > 3)
        return;

    c->derived[1] = 0;
    c->derived[0] = 0;
    if (c->equip[0] != -1)
    {
        u8 *rec = Item_GetRecord(c->equip[0]);

        c->derived[0] = s0 + rec[1];
        c->derived[0] += c->level >> 1;
        c->derived[1] = s4 + ((s0 + s5) >> 2) + rec[2];
        c->derived[1] += c->level;
    }
    c->derived[3] = 0;
    c->derived[2] = 0;
    if (c->equip[1] != -1 && c->equip[6] != -1)
    {
        u8 *r1 = Item_GetRecord(c->equip[1]);
        u8 *r2 = Item_GetRecord(c->equip[6]);

        c->derived[2] = r1[1];
        c->derived[2] += r2[1];
        c->derived[2] += c->level >> 1;
        c->derived[3] = r1[2];
        c->derived[3] += r2[2];
        c->derived[3] += s4 + ((s0 + s5) >> 2);
        c->derived[3] += c->level;
    }
    c->derived[4] = 0;
    c->derived[5] = 0;
    sub_080BF908(c->equip[2], &c->derived[4], &c->derived[5]);
    sub_080BF908(c->equip[3], &c->derived[4], &c->derived[5]);
    sub_080BF908(c->equip[4], &c->derived[4], &c->derived[5]);
    sub_080BF908(c->equip[5], &c->derived[4], &c->derived[5]);
    c->derived[4] += (s4 + s3) / 2 + (c->level >> 2);
    c->derived[5] += s4 + ((s1 + s5) >> 2) + c->level;
    if (c->id == 0)
    {
        c->maxHp = (c->level + 1) * (s0 + s3) / 4 + 14;
        c->maxMp = 0;
    }
    else
    {
        c->maxHp = (s0 + s3) * (c->level + 1) / 5 + 10;
        c->maxMp = (c->level + 4) * (s2 + s1) / 8 + 4;
    }
    if (c->maxHp > 998)
        c->maxHp = 999;
    if (c->maxMp > 998)
        c->maxMp = 999;
    if (c->hp > 998)
        c->hp = 999;
    if (c->mp > 998)
        c->mp = 999;
    c->derived[6] = s2 + (s1 >> 2);
    c->derived[7] = (s2 >> 2) + s1;
}
#else
NAKED
void Combatant_RecalcStats(s32 who)
{
    asm_unified(
        ".L080BF938:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x24\n"
        "    ldr r1, .L080BF9BC\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    adds r5, r0, #0\n"
        "    adds r0, #0x20\n"
        "    adds r4, r5, #0\n"
        "    adds r4, #0x30\n"
        "    adds r1, r4, #0\n"
        "    bl Equipment_SumStatBonuses\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080BFEA8\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080BFF0C\n"
        "    ldrb r0, [r5, #0xc]\n"
        "    bl Combatant_GetStatus\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #4\n"
        "    ands r1, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    rsbs r1, r1, #0\n"
        "    lsrs r1, r1, #0x1f\n"
        "    mov sb, r1\n"
        "    mov r2, sb\n"
        "    str r2, [sp]\n"
        "    mov r3, sb\n"
        "    str r3, [sp, #4]\n"
        "    mov r0, sb\n"
        "    str r0, [sp, #8]\n"
        "    mov sl, sb\n"
        "    cmp r0, #0\n"
        "    beq .L080BF9C0\n"
        "    movs r1, #0x28\n"
        "    str r1, [sp, #0xc]\n"
        "    adds r2, r5, #0\n"
        "    adds r2, #0x40\n"
        "    str r2, [sp, #0x10]\n"
        "    adds r3, r5, #0\n"
        "    adds r3, #0x41\n"
        "    str r3, [sp, #0x14]\n"
        "    adds r4, #0x12\n"
        "    str r4, [sp, #0x18]\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x43\n"
        "    str r0, [sp, #0x1c]\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x44\n"
        "    str r1, [sp, #0x20]\n"
        "    movs r2, #0x45\n"
        "    adds r2, r2, r5\n"
        "    mov r8, r2\n"
        "    b .L080BFAE2\n"
        "    .byte 0x00, 0x00\n"
        ".L080BF9BC: .4byte 0xFFFF8000\n"
        ".L080BF9C0:\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x28\n"
        "    ldrb r0, [r0]\n"
        "    ldrb r1, [r4]\n"
        "    adds r2, r5, #0\n"
        "    adds r2, #0x38\n"
        "    adds r0, r0, r1\n"
        "    ldrb r2, [r2]\n"
        "    adds r2, r0, r2\n"
        "    str r2, [sp]\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x29\n"
        "    ldrb r0, [r0]\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x31\n"
        "    ldrb r1, [r1]\n"
        "    adds r2, r5, #0\n"
        "    adds r2, #0x39\n"
        "    adds r0, r0, r1\n"
        "    ldrb r2, [r2]\n"
        "    adds r2, r2, r0\n"
        "    mov sb, r2\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x2a\n"
        "    ldrb r0, [r0]\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x32\n"
        "    ldrb r1, [r1]\n"
        "    adds r2, r5, #0\n"
        "    adds r2, #0x3a\n"
        "    adds r0, r0, r1\n"
        "    ldrb r2, [r2]\n"
        "    adds r2, r0, r2\n"
        "    str r2, [sp, #4]\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x2b\n"
        "    ldrb r0, [r0]\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x33\n"
        "    ldrb r1, [r1]\n"
        "    adds r2, r5, #0\n"
        "    adds r2, #0x3b\n"
        "    adds r0, r0, r1\n"
        "    ldrb r2, [r2]\n"
        "    adds r2, r0, r2\n"
        "    str r2, [sp, #8]\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x2c\n"
        "    ldrb r1, [r0]\n"
        "    adds r0, #8\n"
        "    ldrb r0, [r0]\n"
        "    adds r2, r5, #0\n"
        "    adds r2, #0x3c\n"
        "    adds r1, r1, r0\n"
        "    ldrb r2, [r2]\n"
        "    adds r2, r1, r2\n"
        "    str r2, [sp, #0xc]\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x2d\n"
        "    ldrb r0, [r0]\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x35\n"
        "    ldrb r1, [r1]\n"
        "    adds r2, r5, #0\n"
        "    adds r2, #0x3d\n"
        "    adds r0, r0, r1\n"
        "    ldrb r2, [r2]\n"
        "    adds r2, r2, r0\n"
        "    mov sl, r2\n"
        "    ldrb r0, [r5, #0xc]\n"
        "    adds r3, r5, #0\n"
        "    adds r3, #0x40\n"
        "    str r3, [sp, #0x10]\n"
        "    adds r4, r5, #0\n"
        "    adds r4, #0x41\n"
        "    str r4, [sp, #0x14]\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x42\n"
        "    str r1, [sp, #0x18]\n"
        "    adds r2, r5, #0\n"
        "    adds r2, #0x43\n"
        "    str r2, [sp, #0x1c]\n"
        "    adds r3, #4\n"
        "    str r3, [sp, #0x20]\n"
        "    movs r4, #0x45\n"
        "    adds r4, r4, r5\n"
        "    mov r8, r4\n"
        "    cmp r0, #0\n"
        "    bne .L080BFAE2\n"
        "    movs r6, #0\n"
        "    ldr r0, .L080BFC88\n"
        "    movs r7, #0xf\n"
        "    adds r4, r0, #1\n"
        ".L080BFA7A:\n"
        "    movs r1, #0x90\n"
        "    lsls r1, r1, #1\n"
        "    adds r0, r6, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl sub_080C32D4\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #8\n"
        "    bls .L080BFADA\n"
        "    ldrb r1, [r4]\n"
        "    lsrs r0, r1, #4\n"
        "    ldr r2, [sp]\n"
        "    adds r0, r2, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp]\n"
        "    ands r1, r7\n"
        "    add r1, sb\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    mov sb, r1\n"
        "    ldrb r1, [r4, #1]\n"
        "    lsrs r0, r1, #4\n"
        "    ldr r3, [sp, #4]\n"
        "    adds r0, r3, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #4]\n"
        "    ands r1, r7\n"
        "    ldr r0, [sp, #8]\n"
        "    adds r1, r0, r1\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    ldrb r1, [r4, #2]\n"
        "    lsrs r0, r1, #4\n"
        "    ldr r2, [sp, #0xc]\n"
        "    adds r0, r2, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0xc]\n"
        "    ands r1, r7\n"
        "    add r1, sl\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    mov sl, r1\n"
        ".L080BFADA:\n"
        "    adds r4, #4\n"
        "    adds r6, #1\n"
        "    cmp r6, #0xb\n"
        "    bls .L080BFA7A\n"
        ".L080BFAE2:\n"
        "    movs r1, #0\n"
        "    mov r3, sp\n"
        "    ldrb r4, [r3]\n"
        "    ldr r3, [sp, #0x10]\n"
        "    strb r4, [r3]\n"
        "    mov r2, sb\n"
        "    ldr r0, [sp, #0x14]\n"
        "    strb r2, [r0]\n"
        "    mov r3, sp\n"
        "    ldrb r4, [r3, #4]\n"
        "    ldr r3, [sp, #0x18]\n"
        "    strb r4, [r3]\n"
        "    mov r0, sp\n"
        "    ldrb r2, [r0, #8]\n"
        "    ldr r0, [sp, #0x1c]\n"
        "    strb r2, [r0]\n"
        "    mov r3, sp\n"
        "    ldrb r4, [r3, #0xc]\n"
        "    ldr r3, [sp, #0x20]\n"
        "    strb r4, [r3]\n"
        "    mov r2, sl\n"
        "    mov r0, r8\n"
        "    strb r2, [r0]\n"
        "    ldrb r0, [r5, #0xc]\n"
        "    cmp r0, #3\n"
        "    bls .L080BFB18\n"
        "    b .L080BFD02\n"
        ".L080BFB18:\n"
        "    adds r6, r5, #0\n"
        "    adds r6, #0x4a\n"
        "    strh r1, [r6]\n"
        "    adds r4, r5, #0\n"
        "    adds r4, #0x48\n"
        "    strh r1, [r4]\n"
        "    adds r2, r5, #0\n"
        "    adds r2, #0x20\n"
        "    movs r1, #0\n"
        "    ldrsb r1, [r2, r1]\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r1, r0\n"
        "    beq .L080BFB66\n"
        "    adds r0, r1, #0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Item_GetRecord\n"
        "    adds r2, r0, #0\n"
        "    ldrb r1, [r2, #1]\n"
        "    ldr r3, [sp]\n"
        "    adds r1, r3, r1\n"
        "    strh r1, [r4]\n"
        "    ldrb r0, [r5, #0xd]\n"
        "    lsrs r0, r0, #1\n"
        "    adds r1, r1, r0\n"
        "    strh r1, [r4]\n"
        "    adds r0, r3, #0\n"
        "    add r0, sl\n"
        "    asrs r0, r0, #2\n"
        "    ldr r4, [sp, #0xc]\n"
        "    adds r0, r4, r0\n"
        "    ldrb r2, [r2, #2]\n"
        "    adds r0, r0, r2\n"
        "    strh r0, [r6]\n"
        "    ldrb r1, [r5, #0xd]\n"
        "    adds r0, r0, r1\n"
        "    strh r0, [r6]\n"
        ".L080BFB66:\n"
        "    movs r0, #0x4e\n"
        "    adds r0, r0, r5\n"
        "    mov r8, r0\n"
        "    movs r0, #0\n"
        "    mov r1, r8\n"
        "    strh r0, [r1]\n"
        "    adds r6, r5, #0\n"
        "    adds r6, #0x4c\n"
        "    strh r0, [r6]\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x21\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r1, r0]\n"
        "    movs r2, #1\n"
        "    rsbs r2, r2, #0\n"
        "    cmp r0, r2\n"
        "    beq .L080BFBE2\n"
        "    adds r7, r5, #0\n"
        "    adds r7, #0x26\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r7, r0]\n"
        "    cmp r0, r2\n"
        "    beq .L080BFBE2\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r1, r0]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Item_GetRecord\n"
        "    adds r4, r0, #0\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r7, r0]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Item_GetRecord\n"
        "    ldrb r2, [r4, #1]\n"
        "    strh r2, [r6]\n"
        "    ldrb r1, [r0, #1]\n"
        "    adds r2, r2, r1\n"
        "    strh r2, [r6]\n"
        "    ldrb r1, [r5, #0xd]\n"
        "    lsrs r1, r1, #1\n"
        "    adds r2, r2, r1\n"
        "    strh r2, [r6]\n"
        "    ldrb r1, [r4, #2]\n"
        "    mov r2, r8\n"
        "    strh r1, [r2]\n"
        "    ldrb r0, [r0, #2]\n"
        "    adds r1, r1, r0\n"
        "    strh r1, [r2]\n"
        "    ldr r0, [sp]\n"
        "    add r0, sl\n"
        "    asrs r0, r0, #2\n"
        "    ldr r3, [sp, #0xc]\n"
        "    adds r0, r3, r0\n"
        "    adds r0, r1, r0\n"
        "    mov r4, r8\n"
        "    strh r0, [r4]\n"
        "    ldrb r1, [r5, #0xd]\n"
        "    adds r0, r0, r1\n"
        "    strh r0, [r4]\n"
        ".L080BFBE2:\n"
        "    adds r4, r5, #0\n"
        "    adds r4, #0x50\n"
        "    movs r0, #0\n"
        "    strh r0, [r4]\n"
        "    adds r6, r5, #0\n"
        "    adds r6, #0x52\n"
        "    strh r0, [r6]\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x22\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    adds r1, r4, #0\n"
        "    adds r2, r6, #0\n"
        "    bl sub_080BF908\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x23\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    adds r1, r4, #0\n"
        "    adds r2, r6, #0\n"
        "    bl sub_080BF908\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x24\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    adds r1, r4, #0\n"
        "    adds r2, r6, #0\n"
        "    bl sub_080BF908\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x25\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    adds r1, r4, #0\n"
        "    adds r2, r6, #0\n"
        "    bl sub_080BF908\n"
        "    ldr r0, [sp, #0xc]\n"
        "    ldr r2, [sp, #8]\n"
        "    adds r1, r0, r2\n"
        "    lsrs r0, r1, #0x1f\n"
        "    adds r1, r1, r0\n"
        "    asrs r1, r1, #1\n"
        "    ldrb r0, [r5, #0xd]\n"
        "    lsrs r0, r0, #2\n"
        "    adds r0, r0, r1\n"
        "    ldrh r3, [r4]\n"
        "    adds r0, r0, r3\n"
        "    strh r0, [r4]\n"
        "    mov r0, sb\n"
        "    add r0, sl\n"
        "    asrs r1, r0, #2\n"
        "    ldr r4, [sp, #0xc]\n"
        "    adds r1, r4, r1\n"
        "    ldrb r0, [r5, #0xd]\n"
        "    adds r1, r1, r0\n"
        "    ldrh r0, [r6]\n"
        "    adds r0, r0, r1\n"
        "    strh r0, [r6]\n"
        "    ldrb r2, [r5, #0xc]\n"
        "    cmp r2, #0\n"
        "    bne .L080BFC8C\n"
        "    ldrb r0, [r5, #0xd]\n"
        "    adds r0, #1\n"
        "    ldr r3, [sp]\n"
        "    ldr r4, [sp, #8]\n"
        "    adds r1, r3, r4\n"
        "    muls r0, r1, r0\n"
        "    cmp r0, #0\n"
        "    bge .L080BFC7C\n"
        "    adds r0, #3\n"
        ".L080BFC7C:\n"
        "    asrs r0, r0, #2\n"
        "    adds r0, #0xe\n"
        "    strh r0, [r5, #0x1a]\n"
        "    strh r2, [r5, #0x1e]\n"
        "    b .L080BFCB8\n"
        "    .byte 0x00, 0x00\n"
        ".L080BFC88: .4byte gUnknown_081A6ED4\n"
        ".L080BFC8C:\n"
        "    ldr r0, [sp]\n"
        "    ldr r2, [sp, #8]\n"
        "    adds r1, r0, r2\n"
        "    ldrb r0, [r5, #0xd]\n"
        "    adds r0, #1\n"
        "    muls r0, r1, r0\n"
        "    movs r1, #5\n"
        "    bl __divsi3\n"
        "    adds r0, #0xa\n"
        "    strh r0, [r5, #0x1a]\n"
        "    ldrb r0, [r5, #0xd]\n"
        "    adds r0, #4\n"
        "    ldr r1, [sp, #4]\n"
        "    add r1, sb\n"
        "    muls r0, r1, r0\n"
        "    cmp r0, #0\n"
        "    bge .L080BFCB2\n"
        "    adds r0, #7\n"
        ".L080BFCB2:\n"
        "    asrs r0, r0, #3\n"
        "    adds r0, #4\n"
        "    strh r0, [r5, #0x1e]\n"
        ".L080BFCB8:\n"
        "    movs r3, #0x1a\n"
        "    ldrsh r0, [r5, r3]\n"
        "    ldr r1, .L080BFD14\n"
        "    cmp r0, r1\n"
        "    ble .L080BFCC6\n"
        "    ldr r0, .L080BFD18\n"
        "    strh r0, [r5, #0x1a]\n"
        ".L080BFCC6:\n"
        "    movs r4, #0x1e\n"
        "    ldrsh r0, [r5, r4]\n"
        "    cmp r0, r1\n"
        "    ble .L080BFCD2\n"
        "    ldr r0, .L080BFD18\n"
        "    strh r0, [r5, #0x1e]\n"
        ".L080BFCD2:\n"
        "    movs r2, #0x18\n"
        "    ldrsh r0, [r5, r2]\n"
        "    cmp r0, r1\n"
        "    ble .L080BFCDE\n"
        "    ldr r0, .L080BFD18\n"
        "    strh r0, [r5, #0x18]\n"
        ".L080BFCDE:\n"
        "    movs r3, #0x1c\n"
        "    ldrsh r0, [r5, r3]\n"
        "    cmp r0, r1\n"
        "    ble .L080BFCEA\n"
        "    ldr r0, .L080BFD18\n"
        "    strh r0, [r5, #0x1c]\n"
        ".L080BFCEA:\n"
        "    mov r4, sb\n"
        "    lsrs r0, r4, #2\n"
        "    ldr r1, [sp, #4]\n"
        "    adds r0, r1, r0\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x54\n"
        "    strh r0, [r1]\n"
        "    ldr r2, [sp, #4]\n"
        "    lsrs r0, r2, #2\n"
        "    add r0, sb\n"
        "    adds r1, #2\n"
        "    strh r0, [r1]\n"
        ".L080BFD02:\n"
        "    add sp, #0x24\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080BFD14: .4byte 0x000003E6\n"
        ".L080BFD18: .4byte 0x000003E7\n"
    );
}
#endif

// Combatant_ApplyBackRow @ 0x080BFD1C
void Combatant_ApplyBackRow(s32 who, s32 mode)
{
    struct Combatant *c = Battle_GetCombatant(who + 0x8000);

    if (mode == 1)
    {
        c->derived[1] = c->derived[1] * 7 / 8;
        c->derived[3] = c->derived[3] * 7 / 8;
        c->derived[4] = c->derived[4] * 9 / 8;
        c->derived[5] = c->derived[5] * 9 / 8;
    }
}

// Combatant_UpdateStats @ 0x080BFD94
void Combatant_UpdateStats(s32 who)
{
    Battle_GetCombatant(who + 0x8000);
    Combatant_RecalcStats(who);
    Combatant_ApplyBackRow(who, Party_GetRow(who));
}

// Equipment_SumStatBonuses @ 0x080BFDC4
/* Sums the stat bonuses (item attribute 5) of the seven equipped items into out[6]. */
#ifdef NONMATCHING
void Equipment_SumStatBonuses(s8 *equip, u8 *out)
{
    s16 ids[7];
    vu16 zero;
    u8 buf[8];
    s32 i;

    zero = 0;
    DmaSet(3, &zero, out, 0x81000004);
    ids[0] = equip[0];
    ids[1] = equip[1];
    ids[2] = equip[2];
    ids[3] = equip[3];
    ids[4] = equip[4];
    ids[5] = equip[5];
    ids[6] = equip[6];
    ids[0] &= 0xFF;
    ids[1] &= 0xFF;
    ids[2] &= 0xFF;
    ids[3] &= 0xFF;
    ids[4] &= 0xFF;
    ids[5] &= 0xFF;
    ids[6] &= 0xFF;
    for (i = 0; i < 7; i++)
    {
        if (ids[i] != 0xFF)
        {
            Item_GetAttribute(ids[i], 5, buf);
            sub_080BFF8C(out, buf, out);
        }
    }
}
#else
NAKED
void Equipment_SumStatBonuses(s8 *equip, u8 *out)
{
    asm_unified(
        ".L080BFDC4:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    sub sp, #0x1c\n"
        "    adds r7, r1, #0\n"
        "    add r2, sp, #0x10\n"
        "    movs r1, #0\n"
        "    strh r1, [r2]\n"
        "    ldr r1, .L080BFE7C\n"
        "    str r2, [r1]\n"
        "    str r7, [r1, #4]\n"
        "    ldr r2, .L080BFE80\n"
        "    str r2, [r1, #8]\n"
        "    ldr r1, [r1, #8]\n"
        "    mov r2, sp\n"
        "    movs r1, #0\n"
        "    ldrsb r1, [r0, r1]\n"
        "    strh r1, [r2]\n"
        "    movs r1, #2\n"
        "    .2byte 0x4469 @ add r1, sp, r1\n"
        "    mov r8, r1\n"
        "    movs r1, #1\n"
        "    ldrsb r1, [r0, r1]\n"
        "    mov r2, r8\n"
        "    strh r1, [r2]\n"
        "    add r6, sp, #4\n"
        "    movs r1, #2\n"
        "    ldrsb r1, [r0, r1]\n"
        "    strh r1, [r6]\n"
        "    mov r5, sp\n"
        "    adds r5, #6\n"
        "    movs r1, #3\n"
        "    ldrsb r1, [r0, r1]\n"
        "    strh r1, [r5]\n"
        "    add r4, sp, #8\n"
        "    movs r1, #4\n"
        "    ldrsb r1, [r0, r1]\n"
        "    strh r1, [r4]\n"
        "    mov r3, sp\n"
        "    adds r3, #0xa\n"
        "    movs r1, #5\n"
        "    ldrsb r1, [r0, r1]\n"
        "    strh r1, [r3]\n"
        "    add r2, sp, #0xc\n"
        "    ldrb r0, [r0, #6]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    strh r0, [r2]\n"
        "    mov r1, sp\n"
        "    mov r0, sp\n"
        "    ldrb r0, [r0]\n"
        "    strh r0, [r1]\n"
        "    mov r1, r8\n"
        "    ldrb r0, [r1]\n"
        "    strh r0, [r1]\n"
        "    ldrb r0, [r6]\n"
        "    strh r0, [r6]\n"
        "    ldrb r0, [r5]\n"
        "    strh r0, [r5]\n"
        "    ldrb r0, [r4]\n"
        "    strh r0, [r4]\n"
        "    ldrb r0, [r3]\n"
        "    strh r0, [r3]\n"
        "    ldrb r0, [r2]\n"
        "    strh r0, [r2]\n"
        "    add r5, sp, #0x14\n"
        "    mov r4, sp\n"
        "    movs r6, #6\n"
        ".L080BFE4C:\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r4, r2]\n"
        "    cmp r0, #0xff\n"
        "    beq .L080BFE66\n"
        "    movs r1, #5\n"
        "    adds r2, r5, #0\n"
        "    bl Item_GetAttribute\n"
        "    adds r0, r7, #0\n"
        "    adds r1, r5, #0\n"
        "    adds r2, r7, #0\n"
        "    bl sub_080BFF8C\n"
        ".L080BFE66:\n"
        "    adds r4, #2\n"
        "    subs r6, #1\n"
        "    cmp r6, #0\n"
        "    bge .L080BFE4C\n"
        "    add sp, #0x1c\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080BFE7C: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080BFE80: .4byte 0x81000004\n"
    );
}
#endif

// Stat_CapBonus @ 0x080BFE84
/* Caps base + bonus at 70: returns the bonus that fits. */
s32 Stat_CapBonus(s32 base, s32 bonus)
{
    s32 over = base + bonus - 70;

    if (over > 0)
        bonus -= over;
    return bonus;
}

// sub_080BFE98 @ 0x080BFE98
s32 sub_080BFE98(s32 a, s32 b, s32 c)
{
    s32 over = a + b + c - 70;

    if (over > 0)
        return c;
    return c;
}

// sub_080BFEA8 @ 0x080BFEA8
void sub_080BFEA8(struct Combatant *c)
{
    s8 *base = (s8 *)c->base.v;
    s8 *bonus = (s8 *)c->bonus.v;

    bonus[0] = Stat_CapBonus(base[0], bonus[0]);
    bonus[1] = Stat_CapBonus(base[1], bonus[1]);
    bonus[2] = Stat_CapBonus(base[2], bonus[2]);
    bonus[3] = Stat_CapBonus(base[3], bonus[3]);
    bonus[4] = Stat_CapBonus(base[4], bonus[4]);
    bonus[5] = Stat_CapBonus(base[5], bonus[5]);
}

// sub_080BFF0C @ 0x080BFF0C
void sub_080BFF0C(struct Combatant *c)
{
    s8 *base = (s8 *)c->base.v;
    s8 *bonus = (s8 *)c->bonus.v;
    s8 *extra = (s8 *)c->extra.v;

    extra[0] = sub_080BFE98(base[0], bonus[0], extra[0]);
    extra[1] = sub_080BFE98(base[1], bonus[1], extra[1]);
    extra[2] = sub_080BFE98(base[2], bonus[2], extra[2]);
    extra[3] = sub_080BFE98(base[3], bonus[3], extra[3]);
    extra[4] = sub_080BFE98(base[4], bonus[4], extra[4]);
    extra[5] = sub_080BFE98(base[5], bonus[5], extra[5]);
}

// sub_080BFF8C @ 0x080BFF8C
void sub_080BFF8C(u8 *a, u8 *b, u8 *out)
{
    out[0] = a[0] + b[0];
    out[1] = a[1] + b[1];
    out[2] = a[2] + b[2];
    out[3] = a[3] + b[3];
    out[4] = a[4] + b[4];
    out[5] = a[5] + b[5];
}

// Party_FindPosition @ 0x080BFFC4
/* Position of member `id` in the active party, or -1. */
s32 Party_FindPosition(s32 id)
{
    s32 i;

    for (i = 0; i < 6; i++)
    {
        if (gGameState.order[i] == id)
            return i;
    }
    return -1;
}

// Party_GetRow @ 0x080BFFF0
/* Party row of member `id`: 0 front (positions 0-2), 1 back, -1 not in the party. */
s32 Party_GetRow(s32 id)
{
    s32 i = Party_FindPosition(id);

    if (i < 0)
        return -1;
    if (i > 2)
        return 1;
    return 0;
}

// sub_080C0010 @ 0x080C0010
/* Fills out[] with the ids of the equipped items whose attribute 6 has bit 0 set
   (out[0..3] start as 0xFFFF); returns whether any was found. */
u32 sub_080C0010(s32 who, struct C0bfIds *out)
{
    u16 *p;
    u32 found;
    u32 i;

    out->b[7] = out->b[6] = out->b[5] = out->b[4] = out->b[3] = out->b[2] = out->b[1] = out->b[0] = 0xFF;
    p = (u16 *)out;
    found = 0;
    for (i = 0; i < 7; p++, i++)
    {
        u32 id = Combatant_GetEquip(who, i);

        if (id != 0xFF && i != 6)
        {
            u32 attr;

            Item_GetAttribute(id, 6, &attr);
            if (attr & 1)
            {
                *p = id;
                found = 1;
            }
        }
    }
    return found;
}

// Combatant_SetEquip @ 0x080C0074
void Combatant_SetEquip(s32 who, s32 slot, s32 item)
{
    s8 *e = Battle_GetCombatant(who + 0x8000)->equip;

    switch (slot)
    {
    case 0:
        e[0] = item;
        break;
    case 1:
        e[1] = item;
        break;
    case 2:
        e[2] = item;
        break;
    case 3:
        e[3] = item;
        break;
    case 4:
        e[4] = item;
        break;
    case 5:
        e[5] = item;
        break;
    case 6:
        e[6] = item;
        break;
    }
}

// Combatant_GetEquip @ 0x080C00DC
u32 Combatant_GetEquip(s32 who, s32 slot)
{
    u8 *e = (u8 *)Battle_GetCombatant(who + 0x8000)->equip;

    switch (slot)
    {
    case 0:
        return e[0];
    case 1:
        return e[1];
    case 2:
        return e[2];
    case 3:
        return e[3];
    case 4:
        return e[4];
    case 5:
        return e[5];
    case 6:
        return e[6];
    }
    return 0;
}

// Party_GetMember @ 0x080C0148
/* id | 0x8000: member record id; otherwise the member at party position id (NULL if empty). */
struct Combatant *Party_GetMember(u16 id)
{
    if (!(id & 0x8000))
    {
        if (gGameState.order[id] == -1)
            return NULL;
        return &gGameState.members[gGameState.order[id]];
    }
    return &gGameState.members[id & 0x7FFF];
}

// Stock_FindDemon @ 0x080C0198
/* Stock record (members 4-15) holding demon `demonId`, or NULL. */
struct Combatant *Stock_FindDemon(u16 demonId)
{
    u16 i;

    for (i = 0; i < 12; i++)
    {
        u16 k = i + 4;

        if (Combatant_IsUsed(k) == 1 && gGameState.members[k].demonId == demonId)
            return &gGameState.members[k];
    }
    return NULL;
}

// Party_Add @ 0x080C01DC
/* Puts member `who` in the first free party position. */
u32 Party_Add(u16 who)
{
    struct Combatant *c = Party_GetMember(who + 0x8000);
    u16 i;

    for (i = 0; i < 6; i++)
    {
        if (gGameState.order[i] == -1)
        {
            gGameState.order[i] = who;
            c->unkE = 0xC000;
            if (who < 4)
            {
                c->flags = 0;
                if (who != 0)
                    c->unk58 = gGameState.members[0].unk58;
            }
            return 1;
        }
    }
    return 0;
}

// Party_AddAt @ 0x080C0248
u32 Party_AddAt(u16 who, u16 slot)
{
    struct Combatant *c = Party_GetMember(who + 0x8000);

    if (gGameState.order[slot] == -1)
    {
        gGameState.order[slot] = who;
        c->unkE = 0xC000;
        return 1;
    }
    return 0;
}

// Party_Remove @ 0x080C0290
/* Removes member `who` from the party; release != 0 frees the record. */
void Party_Remove(u16 who, u16 release)
{
    struct Combatant *c = Party_GetMember(who + 0x8000);
    u16 i;

    for (i = 0; i < 6; i++)
    {
        if (gGameState.order[i] == who)
        {
            gGameState.order[i] = -1;
            if (release == 0)
            {
                if (who < 4)
                {
                    c->unkE = release;
                    return;
                }
                c->unkE = 0x8000;
                if (Combatant_GetStatus(c->id) & 0x4000)
                {
                    Combatant_SetStatus(c->id, 0);
                    Combatant_SetStatus(c->id, 0x8000);
                }
                Combatant_ClearStatus(c->id, 0xB000);
            }
            else
            {
                c->unkE = 0;
                if (who > 3)
                    sub_080C2A1C(c->demonId);
            }
            return;
        }
    }
    if (release == 0)
    {
        if (who < 4)
            c->unkE = release;
        else
            c->unkE = 0x8000;
    }
    else
    {
        c->unkE = 0;
        if (who > 3)
            sub_080C2A1C(c->demonId);
    }
}

// Combatant_DecodeName @ 0x080C0344
void Combatant_DecodeName(const u8 *name, u16 *out)
{
    u32 i;

    for (i = 0; i < 8; i++, out++, name++)
    {
        if (*name == 0xFF)
            *out = 0;
        else
            *out = gUnknown_081A5A6C[*name];
    }
}

// sub_080C0378 @ 0x080C0378
void sub_080C0378(const u8 *name, u16 *out)
{
    while (*name != 0 && *name != 0xFF)
    {
        *out = gUnknown_081A5A6C[*name];
        out++;
        name++;
    }
}

// sub_080C03A8 @ 0x080C03A8
u8 sub_080C03A8(u16 glyph)
{
    u16 i;

    for (i = 1; gUnknown_081A5A6C[i] != 0; i++)
    {
        if (gUnknown_081A5A6C[i] == glyph)
            return i;
    }
    return 0;
}

// Name_EncodeChar @ 0x080C03E8
/* Glyph -> name character (0 -> 0xFF terminator; unknown glyphs give 0xE0). */
u8 Name_EncodeChar(u16 glyph)
{
    u8 i;

    if (glyph == 0)
        return 0xFF;
    i = 0;
    if (gUnknown_081A5A6C[0] != glyph)
    {
        do
        {
            i++;
            if (i > 0xDF)
                break;
        } while (gUnknown_081A5A6C[i] != glyph);
    }
    return i;
}

// Name_Encode @ 0x080C0420
void Name_Encode(const u16 *glyphs, u8 *out)
{
    u16 i;

    for (i = 0; i < 8; i++, glyphs++, out++)
        *out = Name_EncodeChar(*glyphs);
}

// Combatant_InitDemon @ 0x080C0444
/* Initialises combatant record c as demon `demonId` (stats, skills, name). */
void Combatant_InitDemon(struct Combatant *c, s32 who, s32 demonId)
{
    struct DemonRecord *rec = (struct DemonRecord *)Demon_GetRecord(demonId);
    s32 i, n;

    DmaFill32(3, 0, c, 0x80);
    c->id = who;
    c->demonId = demonId;
    c->unkE = 0x8000;
    c->unk14 = rec->unk0;
    c->hp = rec->hp;
    c->maxHp = rec->hp;
    c->mp = rec->mp;
    c->maxMp = rec->mp;
    c->level = rec->level;
    c->unk58 = rec->unkC << 8;
    Name_Encode(rec->name, c->name);
    sub_080C35C4(who, 10);
    sub_080C3600(who, 10);
    c->total.v[0] = rec->stats[0];
    c->total.v[1] = rec->stats[1];
    c->total.v[2] = rec->stats[2];
    c->total.v[3] = rec->stats[3];
    c->total.v[4] = rec->stats[4];
    c->total.v[5] = rec->stats[5];
    *(unsigned long long *)&c->base = *(unsigned long long *)&c->total;
    c->unk58 = rec->unkC << 8;
    for (i = 0; i < 32; i++)
        c->skills[i] |= 0xFF;
    for (n = 0, i = 0; i < 7; i++)
    {
        if (rec->skills[i] != 0xFF)
            c->skills[n++] = rec->skills[i];
    }
    Stats_CalcDerived(c->level, (s8 *)&c->total, c->derived);
}

// Member_InitDemon @ 0x080C0550
void Member_InitDemon(s32 who, s32 demonId)
{
    Combatant_InitDemon(Party_GetMember(who + 0x8000), who, demonId);
}

// Stats_CalcDerived @ 0x080C0574
/* Derived values from level and stats (st: St, In, Ma, Vi, Ag, Lu). */
void Stats_CalcDerived(s32 level, const s8 *st, s16 *out)
{
    s32 half;

    out[0] = (level + st[0]) * 2;
    half = level + level / 2;
    out[1] = st[4] + half + (st[0] + st[5]) / 4;
    out[4] = (level + st[3]) * 2;
    out[5] = st[4] + half + (st[1] + st[5]) / 4;
    out[6] = st[1] / 4 + st[2];
    out[7] = st[2] / 4 + st[1];
}

// Combatant_CalcDerived @ 0x080C05FC
void Combatant_CalcDerived(struct Combatant *c)
{
    if (!(c->flags & 0x800))
        Stats_CalcDerived(c->level, (s8 *)&c->total, c->derived);
    else
        Stats_CalcDerived(c->level, gUnknown_081A5C2C, c->derived);
}

// Stock_AddDemon @ 0x080C062C
/* Adds demon `demonId` to the first free stock record; returns its member index or -1. */
s32 Stock_AddDemon(u16 demonId)
{
    u32 i;

    if (sub_080C351C(demonId) == 0)
        return -1;
    for (i = 0; i < 12; i++)
    {
        if (Party_GetMember(i + 0x8004)->unkE == 0)
            break;
    }
    i += 4;
    Member_InitDemon(i, demonId);
    if (Flag_Test(0xE5))
        sub_080C2674(demonId);
    sub_080C28F8(demonId);
    return i;
}

// Race_GetName @ 0x080C068C
const u8 *Race_GetName(u16 race)
{
    return gUnknown_081A5C34[race];
}

// ParentRace_GetName @ 0x080C069C
const u8 *ParentRace_GetName(u16 race)
{
    return gUnknown_081A5F24[race];
}

// sub_080C06AC @ 0x080C06AC
const u8 *sub_080C06AC(u16 id)
{
    return gUnknown_081A6014[id];
}

// Combatant_GetAlignment @ 0x080C06BC
/* Alignment of `who` from the high byte of +0x58: 0 below 0x70, 2 above 0x8F, else 1. */
s32 Combatant_GetAlignment(s32 who)
{
    u32 v = Battle_GetCombatant(who + 0x8000)->unk58 >> 8;

    if (v < 0x70)
        return 0;
    if (v <= 0x8F)
        return 1;
    return 2;
}

// Combatant_AddAlignment @ 0x080C06EC
/* Adds delta to the alignment value (clamped 0-0xFFFF, unless flag 0xE0); the hero's is
   copied to members 1 and 2, who otherwise take the hero's. Returns the new alignment. */
s32 Combatant_AddAlignment(s32 who, s32 delta)
{
    struct Combatant *c = Battle_GetCombatant(who + 0x8000);

    if (!Flag_Test(0xE0))
    {
        s32 v = c->unk58;

        v += delta;
        if (v < 0)
            v = 0;
        else if (v > 0xFFFF)
            v = 0xFFFF;
        c->unk58 = v;
    }
    if (who == 0)
    {
        gGameState.members[1].unk58 = c->unk58;
        gGameState.members[2].unk58 = c->unk58;
    }
    else if (who == 1 || who == 2)
    {
        c->unk58 = gGameState.members[0].unk58;
    }
    return Combatant_GetAlignment(who);
}

// sub_080C0774 @ 0x080C0774
void sub_080C0774(s32 who, s32 v)
{
    Battle_GetCombatant(who + 0x8000)->unk58 = v;
}

// sub_080C0794 @ 0x080C0794
u16 sub_080C0794(s32 who)
{
    return Battle_GetCombatant(who + 0x8000)->unk58;
}

// Alignment_AreCompatible @ 0x080C07B0
/* 0 when a and b have opposite alignments (0 vs 2), else 1. */
s32 Alignment_AreCompatible(s32 a, s32 b)
{
    s32 x = Combatant_GetAlignment(a);
    s32 y = Combatant_GetAlignment(b);

    if (x == 0)
    {
        if (y == 2)
            return 0;
    }
    else if (x == 2 && y == 0)
    {
        return 0;
    }
    return 1;
}

// Combatant_GetDemonId @ 0x080C07E0
s16 Combatant_GetDemonId(s32 who)
{
    return Battle_GetCombatant(who + 0x8000)->demonId;
}

// sub_080C07FC @ 0x080C07FC
s16 sub_080C07FC(s32 who)
{
    return Battle_GetCombatant(who + 0x8000)->unk14;
}

// Combatant_GetStatus @ 0x080C0818
u16 Combatant_GetStatus(s32 who)
{
    return Battle_GetCombatant(who + 0x8000)->flags;
}

// Combatant_IsDead @ 0x080C0830
u32 Combatant_IsDead(s32 who)
{
    if (Combatant_GetStatus(who) & 0x8000)
        return 1;
    return 0;
}
