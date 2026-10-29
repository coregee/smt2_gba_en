/* Battle enemy sprite slots: setup and teardown. */

#include "global.h"
#include "battledisp.h"

// sub_080E8D88 @ 0x080E8D88
void sub_080E8D88(u8 v)
{
    struct C15cBattle *b = BB;

    b->unkEC3 = v;
}

// sub_080E8D9C @ 0x080E8D9C
void sub_080E8D9C(void)
{
    sub_080E8D88(1);
}

// sub_080E8DA8 @ 0x080E8DA8
void sub_080E8DA8(void)
{
    sub_080E8D88(0);
}

// sub_080E8DB4 @ 0x080E8DB4
void sub_080E8DB4(u16 group)
{
    struct C15cBattle *b = BB;

    if (b->groups[group] != 0xFFFF)
    {
        struct C15cDemonSprite *s = &b->sprites[group];

        s->unk4 = 1;
    }
}

// sub_080E8DEC @ 0x080E8DEC
void sub_080E8DEC(void)
{
    sub_080E8DB4(0);
    sub_080E8DB4(1);
}

// sub_080E8E00 @ 0x080E8E00
/* Puts demon `id` into enemy sprite slot arg & 0xF (bits 4-7: start slot 0 shifted down);
   returns the slot's task. */
#ifdef NONMATCHING
struct Task *sub_080E8E00(u16 arg, u16 id)
{
    struct C15cBattle *b = BB;
    u8 shifted = (arg & 0xF0) >> 4;
    u8 slot = arg & 0xF;
    u32 off;

    gUnk_03006434 = b->bstate;
    if (slot > 2)
        return NULL;
    CharObj_FindInGroup(slot, id);
    b->unk118C = 0;
    if (id != 0xFFFF && b->groups[slot] != id)
    {
        b->groups[slot] = id;
        if (slot == 0)
        {
            Battle_InitEnemyUnit(0, b->groups[slot]);
            sub_080ED938(0);
            b->vbl[0] = (u16 *)VBlankTask_Add(sub_080E55BC);
            sub_080E5668(sub_080E5674);
            b->sprites[0].upload = 0;
            b->tasks[0] = Task_Create(gUnknown_086BEA18, 0xFFFF);
            off = 0;
            if (shifted)
            {
                sub_080E845C(0, 0, 0x10);
                b->sprites[0].unk4 = 2;
                off = slot;
            }
        }
        else
        {
            Battle_InitEnemyUnit(4, id);
            sub_080ED938(1);
            b->vbl[slot] = (u16 *)VBlankTask_Add(sub_080E5610);
            off = slot << 6;
            ((struct C15cBattle *)((u8 *)b + off))->sprites[0].upload = 0;
            b->tasks[slot] = Task_Create(gUnknown_086BEB18, 0xFFFF);
        }
        /* off is the byte offset of the slot's sprite record (slot * 0x40). */
        ((struct C15cBattle *)((u8 *)b + off))->sprites[0].x = 0x7FFF;
        ((struct C15cBattle *)((u8 *)b + off))->sprites[0].y = 0x7FFF;
        sub_080BDE1C(id, 0);
        gCharTasks[slot + 6] = b->tasks[slot];
        Combatant_SetStatus(slot * 4 + 16, 0);
    }
    return b->tasks[slot];
}
#else
NAKED
struct Task *sub_080E8E00(u16 arg, u16 id)
{
    asm_unified(
        ".L080E8E00:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    mov r8, r1\n"
        "    ldr r5, .L080E8E34\n"
        "    movs r1, #0xf0\n"
        "    ands r1, r0\n"
        "    lsrs r1, r1, #4\n"
        "    mov sl, r1\n"
        "    movs r7, #0xf\n"
        "    ands r7, r0\n"
        "    ldr r1, .L080E8E38\n"
        "    ldr r2, .L080E8E3C\n"
        "    adds r0, r5, r2\n"
        "    str r0, [r1]\n"
        "    cmp r7, #2\n"
        "    bls .L080E8E40\n"
        "    movs r0, #0\n"
        "    b .L080E8F4E\n"
        "    .byte 0x00, 0x00\n"
        ".L080E8E34: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080E8E38: .4byte 0x03006434 @ IWRAM+0x6434\n"
        ".L080E8E3C: .4byte 0x00000F6C\n"
        ".L080E8E40:\n"
        "    adds r0, r7, #0\n"
        "    mov r1, r8\n"
        "    bl CharObj_FindInGroup\n"
        "    ldr r0, .L080E8EC0\n"
        "    adds r1, r5, r0\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L080E8EC4\n"
        "    mov sb, r1\n"
        "    lsls r6, r7, #2\n"
        "    cmp r8, sb\n"
        "    beq .L080E8F48\n"
        "    movs r2, #0x99\n"
        "    lsls r2, r2, #4\n"
        "    adds r1, r5, r2\n"
        "    adds r2, r6, r1\n"
        "    ldr r0, [r2]\n"
        "    cmp r0, r8\n"
        "    beq .L080E8F48\n"
        "    mov r0, r8\n"
        "    str r0, [r2]\n"
        "    cmp r7, #0\n"
        "    bne .L080E8EE0\n"
        "    ldr r1, [r1]\n"
        "    movs r0, #0\n"
        "    bl Battle_InitEnemyUnit\n"
        "    movs r0, #0\n"
        "    bl sub_080ED938\n"
        "    ldr r0, .L080E8EC8\n"
        "    bl VBlankTask_Add\n"
        "    ldr r2, .L080E8ECC\n"
        "    adds r1, r5, r2\n"
        "    str r0, [r1]\n"
        "    ldr r0, .L080E8ED0\n"
        "    bl sub_080E5668\n"
        "    ldr r1, .L080E8ED4\n"
        "    adds r0, r5, r1\n"
        "    movs r2, #0\n"
        "    strb r2, [r0]\n"
        "    ldr r0, .L080E8ED8\n"
        "    mov r1, sb\n"
        "    bl Task_Create\n"
        "    str r0, [r5, #4]\n"
        "    movs r4, #0\n"
        "    mov r0, sl\n"
        "    cmp r0, #0\n"
        "    beq .L080E8F16\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #0x10\n"
        "    bl sub_080E845C\n"
        "    ldr r2, .L080E8EDC\n"
        "    adds r1, r5, r2\n"
        "    movs r0, #2\n"
        "    strb r0, [r1]\n"
        "    adds r4, r7, #0\n"
        "    b .L080E8F16\n"
        ".L080E8EC0: .4byte 0x0000118C\n"
        ".L080E8EC4: .4byte 0x0000FFFF\n"
        ".L080E8EC8: .4byte sub_080E55BC\n"
        ".L080E8ECC: .4byte 0x00001118\n"
        ".L080E8ED0: .4byte sub_080E5674\n"
        ".L080E8ED4: .4byte 0x00000DA3\n"
        ".L080E8ED8: .4byte gUnknown_086BEA18\n"
        ".L080E8EDC: .4byte 0x00000DA4\n"
        ".L080E8EE0:\n"
        "    movs r0, #4\n"
        "    mov r1, r8\n"
        "    bl Battle_InitEnemyUnit\n"
        "    movs r0, #1\n"
        "    bl sub_080ED938\n"
        "    ldr r0, .L080E8F5C\n"
        "    bl VBlankTask_Add\n"
        "    ldr r2, .L080E8F60\n"
        "    adds r1, r5, r2\n"
        "    adds r1, r6, r1\n"
        "    str r0, [r1]\n"
        "    lsls r4, r7, #6\n"
        "    adds r0, r4, r5\n"
        "    ldr r1, .L080E8F64\n"
        "    adds r0, r0, r1\n"
        "    movs r2, #0\n"
        "    strb r2, [r0]\n"
        "    ldr r0, .L080E8F68\n"
        "    mov r1, sb\n"
        "    bl Task_Create\n"
        "    ldr r2, .L080E8F6C\n"
        "    adds r1, r6, r2\n"
        "    str r0, [r1]\n"
        ".L080E8F16:\n"
        "    adds r0, r5, r4\n"
        "    ldr r2, .L080E8F70\n"
        "    adds r1, r0, r2\n"
        "    ldr r2, .L080E8F74\n"
        "    strh r2, [r1]\n"
        "    ldr r1, .L080E8F78\n"
        "    adds r0, r0, r1\n"
        "    strh r2, [r0]\n"
        "    mov r0, r8\n"
        "    movs r1, #0\n"
        "    bl sub_080BDE1C\n"
        "    ldr r1, .L080E8F7C\n"
        "    adds r0, r7, #6\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r0, r1\n"
        "    ldr r2, .L080E8F6C\n"
        "    adds r1, r2, r6\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x10\n"
        "    movs r1, #0\n"
        "    bl Combatant_SetStatus\n"
        ".L080E8F48:\n"
        "    ldr r1, .L080E8F6C\n"
        "    adds r0, r1, r6\n"
        "    ldr r0, [r0]\n"
        ".L080E8F4E:\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        ".L080E8F5C: .4byte sub_080E5610\n"
        ".L080E8F60: .4byte 0x00001118\n"
        ".L080E8F64: .4byte 0x00000DA3\n"
        ".L080E8F68: .4byte gUnknown_086BEB18\n"
        ".L080E8F6C: .4byte 0x0203C204 @ EWRAM+0x3C204\n"
        ".L080E8F70: .4byte 0x00000DA8\n"
        ".L080E8F74: .4byte 0x00007FFF\n"
        ".L080E8F78: .4byte 0x00000DAA\n"
        ".L080E8F7C: .4byte 0x02036094 @ EWRAM+0x36094\n"
    );
}
#endif

// sub_080E8F80 @ 0x080E8F80
void sub_080E8F80(u8 slot, s16 x, s16 y, u8 priority)
{
    struct C15cBattle *b = BB;
    struct C15cDemonSprite *s = &b->sprites[slot];

    s->x = x;
    s->y = y;
    s->unk10 = priority;
}

// sub_080E8FA0 @ 0x080E8FA0
/* Default screen position of sprite slot `slot`. */
void sub_080E8FA0(u8 slot, u16 *x, u16 *y)
{
    switch (slot)
    {
    case 0:
        if (!Battle_IsTwoSided())
            *x = 0x78;
        else
            *x = 0x50;
        *y = 0x56;
        break;
    case 1:
        *x = 0xA1;
        *y = 0x56;
        break;
    case 2:
        *x = 0;
        *y = 0;
        break;
    }
}

// sub_080E8FE8 @ 0x080E8FE8
void sub_080E8FE8(u8 slot)
{
    struct C15cBattle *b = BB;
    struct C15cDemonSprite *s = &b->sprites[slot];

    s->x = 0x7FFF;
    s->y = 0x7FFF;
}

// sub_080E9008 @ 0x080E9008
void sub_080E9008(void)
{
    struct C15cBattle *b = BB;

    Task_End(b->tasks[0]);
    b->tasks[0] = NULL;
    b->vblankTask[1] = 1;
    b->groups[0] = b->groups[1] = 0xFFFF;
}

// sub_080E9044 @ 0x080E9044
#ifdef NONMATCHING
void sub_080E9044(struct Task *t, u16 slot)
{
    struct C15cBattle *b = BB;

    if (t != NULL)
    {
        CharTask_Unregister(t);
        Task_End(t);
    }
    b->tasks[slot] = NULL;
    b->vbl[slot][1] = 1;
    b->groups[slot] = 0xFFFF;
    b->sprites[slot].upload = 0;
    b->sprites[slot].unk4 = 0;
}
#else
NAKED
void sub_080E9044(struct Task *t, u16 slot)
{
    asm_unified(
        ".L080E9044:\n"
        "    push {r4, r5, r6, lr}\n"
        "    adds r4, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r6, r1, #0x10\n"
        "    ldr r5, .L080E9098\n"
        "    cmp r4, #0\n"
        "    beq .L080E905C\n"
        "    bl CharTask_Unregister\n"
        "    adds r0, r4, #0\n"
        "    bl Task_End\n"
        ".L080E905C:\n"
        "    lsls r2, r6, #2\n"
        "    adds r0, r5, #4\n"
        "    adds r0, r2, r0\n"
        "    movs r1, #0\n"
        "    str r1, [r0]\n"
        "    ldr r1, .L080E909C\n"
        "    adds r0, r5, r1\n"
        "    adds r0, r2, r0\n"
        "    ldr r1, [r0]\n"
        "    movs r3, #0\n"
        "    movs r0, #1\n"
        "    strh r0, [r1, #2]\n"
        "    movs r1, #0x99\n"
        "    lsls r1, r1, #4\n"
        "    adds r0, r5, r1\n"
        "    adds r2, r2, r0\n"
        "    ldr r0, .L080E90A0\n"
        "    str r0, [r2]\n"
        "    lsls r0, r6, #6\n"
        "    adds r0, r0, r5\n"
        "    ldr r2, .L080E90A4\n"
        "    adds r1, r0, r2\n"
        "    strb r3, [r1]\n"
        "    ldr r1, .L080E90A8\n"
        "    adds r0, r0, r1\n"
        "    strb r3, [r0]\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080E9098: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080E909C: .4byte 0x00001118\n"
        ".L080E90A0: .4byte 0x0000FFFF\n"
        ".L080E90A4: .4byte 0x00000DA3\n"
        ".L080E90A8: .4byte 0x00000DA4\n"
    );
}
#endif


// sub_080E90AC @ 0x080E90AC
/* Auto battle: picks every member's action (sub_080E926C / sub_080E91F0). B within the first
   frames cancels. */
void sub_080E90AC(struct Task *t)
{
    struct C15cBattle *b = BB;
    s16 *sub;
    s32 i;

    t->result = 0;
    sub = &b->substate;
    switch (*sub)
    {
    case 0:
        gUnk_03000052 = 0;
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(gUnknown_08126368, 0));
        BattleMsg_SetDone(1);
        b->unkF60 = sub_080C2BA4();
        *sub = 2;
        BattleMsg_SetLocked(1);
        break;
    case 1:
        if (gUnk_030031D0 & 2)
        {
            sub_080F00FC(0x4000);
            b->state = 6;
            t->result = 1;
        }
        if (++gUnk_03000052 > 10)
            *sub = 2;
        break;
    case 2:
        gUnk_03000052 = 0;
        sub_080ED90C(0x4000);
        for (i = 0; i < 16; i++)
        {
            if (Combatant_IsInParty(i) && sub_080F3040(i))
            {
                if (b->unkF60 != 0)
                    sub_080E926C((s16)i, (s16)b->unkF30[i], b->unkF60);
                else
                    sub_080E91F0((s16)i);
            }
        }
        sub_080C84C0();
        b->state = 10;
        b->substate = 0;
        t->result = 1;
        break;
    }
}

// sub_080E91F0 @ 0x080E91F0
/* Default auto-battle action: summon when possible (command 5), else attack (4) or, without
   a weapon, command 9; demons use command 10. Targets a random enemy group. */
void sub_080E91F0(who)
    u16 who;
{
    s32 msg;
    u32 target = (Random_Byte() & 1) * 4 + 16;

    sub_080EDA4C((s16)who, target);
    if ((s16)who <= 3)
    {
        if ((s16)sub_080C3620((s16)who) == 5 && Battle_CanUseCommand((s16)who, 5, &msg))
            sub_080C35C4((s16)who, 5);
        else if (Combatant_GetEquip((s16)who, 0) != 0xFF)
            sub_080C35C4((s16)who, 4);
        else
            sub_080C35C4((s16)who, 9);
    }
    else
    {
        sub_080C35C4((s16)who, 10);
    }
}

// sub_080E926C @ 0x080E926C
/* Auto battle with "repeat": reuses member `who`'s last command and skill when it can still
   be used (MP, items, a living ally target), else falls back to sub_080E91F0 (mode 1) or
   command 9. */
#ifdef NONMATCHING
void sub_080E926C(who, target, mode)
    u16 who;
    u16 target;
    u16 mode;
{
    u16 skill = Combatant_GetChosenSkill((s16)who);
    u16 cmd = sub_080C3620((s16)who);
    u32 dest = (Random_Byte() & 1) * 4 + 16;

    sub_080EDA4C((s16)who, dest);
    if ((s16)cmd == 8 && sub_0812B37C())
        goto fallback;
    if ((u16)((s16)cmd - 4) <= 1 || (s16)cmd == 10)
    {
        sub_080E91F0((s16)who);
        return;
    }
    if ((s16)cmd == 7)
    {
        u16 mp = Battle_GetMp((s16)who);
        u16 cost = sub_080ED6CC((s16)skill);
        u16 kind = sub_080ED694((s16)skill);

        if ((s16)skill == 0x3E || (s16)skill == 0x3F)
            goto fallback;
        if ((s16)((s16)mp - (s16)cost) < 0)
            goto fallback;
        if ((s16)kind == 0x80 || (s16)kind == 0x82)
        {
            if (target > 15 || !Combatant_IsInParty((s16)target) || !Combatant_IsAlive((s16)target))
                goto fallback;
        }
    }
    if ((s16)cmd == 8)
    {
        u8 *rec;
        u8 slot = 0;
        u8 i;

        rec = Action_GetRecord(skill - 0xD0);
        for (i = 0; i < 6; i++)
        {
            if (gUnk_030050E0[i] == (s16)who)
                slot = i;
        }
        if ((s16)(sub_080C10B4((s16)skill) - sub_0812B1E0((s16)skill, slot)) <= 0)
            goto fallback;
        if (rec[3] == 0x80 || rec[3] == 0x82)
        {
            if (target > 15 || !Combatant_IsInParty((s16)target) || !Combatant_IsAlive((s16)target))
                goto fallback;
        }
    }
    if ((s16)cmd != 6)
    {
        sub_080C35C4((s16)who, cmd);
        return;
    }
fallback:
    if (mode == 1)
        sub_080E91F0((s16)who);
    else
        sub_080C35C4((s16)who, 9);
}
#else
NAKED
void sub_080E926C(who, target, mode)
    u16 who;
    u16 target;
    u16 mode;
{
    asm_unified(
        ".L080E926C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0xc\n"
        "    lsls r0, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp]\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    str r2, [sp, #4]\n"
        "    lsrs r1, r0, #0x10\n"
        "    mov r8, r1\n"
        "    asrs r4, r0, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_GetChosenSkill\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #8]\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080C3620\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    bl Random_Byte\n"
        "    movs r1, #1\n"
        "    ands r1, r0\n"
        "    lsls r1, r1, #2\n"
        "    adds r1, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080EDA4C\n"
        "    lsls r0, r7, #0x10\n"
        "    asrs r5, r0, #0x10\n"
        "    cmp r5, #8\n"
        "    bne .L080E92C6\n"
        "    bl sub_0812B37C\n"
        "    cmp r0, #0\n"
        "    beq .L080E92C6\n"
        "    b .L080E93EC\n"
        ".L080E92C6:\n"
        "    subs r0, r5, #4\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bls .L080E92D4\n"
        "    cmp r5, #0xa\n"
        "    bne .L080E92DC\n"
        ".L080E92D4:\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080E91F0\n"
        "    b .L080E940A\n"
        ".L080E92DC:\n"
        "    cmp r5, #7\n"
        "    bne .L080E9348\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetMp\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldr r2, [sp, #8]\n"
        "    lsls r0, r2, #0x10\n"
        "    asrs r5, r0, #0x10\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080ED6CC\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080ED694\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r5, #0x3e\n"
        "    beq .L080E93EC\n"
        "    cmp r5, #0x3f\n"
        "    beq .L080E93EC\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    lsls r1, r4, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    subs r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    blt .L080E93EC\n"
        "    lsls r0, r2, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #0x80\n"
        "    beq .L080E9328\n"
        "    cmp r0, #0x82\n"
        "    bne .L080E9348\n"
        ".L080E9328:\n"
        "    ldr r0, [sp]\n"
        "    lsls r1, r0, #0x10\n"
        "    lsrs r0, r1, #0x10\n"
        "    cmp r0, #0xf\n"
        "    bhi .L080E93EC\n"
        "    asrs r5, r1, #0x10\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_IsInParty\n"
        "    cmp r0, #0\n"
        "    beq .L080E93EC\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_IsAlive\n"
        "    cmp r0, #0\n"
        "    beq .L080E93EC\n"
        ".L080E9348:\n"
        "    lsls r0, r7, #0x10\n"
        "    asrs r1, r0, #0x10\n"
        "    mov r2, r8\n"
        "    lsls r2, r2, #0x10\n"
        "    mov sl, r2\n"
        "    mov sb, r0\n"
        "    cmp r1, #8\n"
        "    bne .L080E93CE\n"
        "    movs r6, #0\n"
        "    ldr r0, [sp, #8]\n"
        "    lsls r4, r0, #0x10\n"
        "    ldr r1, .L080E93E4\n"
        "    adds r0, r4, r1\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Action_GetRecord\n"
        "    adds r7, r0, #0\n"
        "    movs r1, #0\n"
        "    ldr r3, .L080E93E8\n"
        "    mov r0, sl\n"
        "    asrs r2, r0, #0x10\n"
        ".L080E9372:\n"
        "    adds r0, r1, r3\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    cmp r0, r2\n"
        "    bne .L080E9380\n"
        "    adds r6, r1, #0\n"
        ".L080E9380:\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r1, r0, #0x18\n"
        "    cmp r1, #5\n"
        "    bls .L080E9372\n"
        "    asrs r5, r4, #0x10\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080C10B4\n"
        "    adds r4, r0, #0\n"
        "    adds r0, r5, #0\n"
        "    adds r1, r6, #0\n"
        "    bl sub_0812B1E0\n"
        "    subs r4, r4, r0\n"
        "    lsls r4, r4, #0x10\n"
        "    cmp r4, #0\n"
        "    ble .L080E93EC\n"
        "    ldrb r0, [r7, #3]\n"
        "    cmp r0, #0x80\n"
        "    beq .L080E93AE\n"
        "    cmp r0, #0x82\n"
        "    bne .L080E93CE\n"
        ".L080E93AE:\n"
        "    ldr r2, [sp]\n"
        "    lsls r1, r2, #0x10\n"
        "    lsrs r0, r1, #0x10\n"
        "    cmp r0, #0xf\n"
        "    bhi .L080E93EC\n"
        "    asrs r4, r1, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_IsInParty\n"
        "    cmp r0, #0\n"
        "    beq .L080E93EC\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_IsAlive\n"
        "    cmp r0, #0\n"
        "    beq .L080E93EC\n"
        ".L080E93CE:\n"
        "    mov r1, sb\n"
        "    asrs r0, r1, #0x10\n"
        "    cmp r0, #6\n"
        "    beq .L080E93EC\n"
        "    mov r2, sl\n"
        "    asrs r0, r2, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    bl sub_080C35C4\n"
        "    b .L080E940A\n"
        "    .byte 0x00, 0x00\n"
        ".L080E93E4: .4byte 0xFF300000\n"
        ".L080E93E8: .4byte 0x030050E0 @ IWRAM+0x50E0\n"
        ".L080E93EC:\n"
        "    ldr r0, [sp, #4]\n"
        "    cmp r0, #1\n"
        "    bne .L080E93FE\n"
        "    mov r1, r8\n"
        "    lsls r0, r1, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    bl sub_080E91F0\n"
        "    b .L080E940A\n"
        ".L080E93FE:\n"
        "    mov r2, r8\n"
        "    lsls r0, r2, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    movs r1, #9\n"
        "    bl sub_080C35C4\n"
        ".L080E940A:\n"
        "    add sp, #0xc\n"
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

