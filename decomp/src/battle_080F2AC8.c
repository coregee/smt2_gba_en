#include "global.h"
#include "battle2.h"

// sub_080F2AC8 @ 0x080F2AC8
void sub_080F2AC8(void)
{
    s16 who = gUnk_03000088.unk4;
    u16 side = Battle_IsEnemyId(gUnk_03000088.unk4);
    s16 msg;
    u16 bit = sub_080EDA90();

    switch (bit)
    {
    case 0x8000: msg = gUnknown_0876E938[(s16)side]; break;
    case 0x4000: msg = gUnknown_0876E938[(s16)side + 2]; break;
    case 0x2000: msg = gUnknown_0876E938[(s16)side + 4]; break;
    case 0x1000: msg = gUnknown_0876E938[(s16)side + 6]; break;
    case 0x800: msg = gUnknown_0876E938[(s16)side + 8]; break;
    case 0x400: msg = gUnknown_0876E938[(s16)side + 10]; break;
    case 0x200: msg = gUnknown_0876E938[(s16)side + 12]; break;
    case 0x100: msg = gUnknown_0876E938[(s16)side + 14]; break;
    case 0x80: msg = gUnknown_0876E938[(s16)side + 16]; break;
    case 0x40: msg = gUnknown_0876E938[(s16)side + 18]; break;
    case 0x20: msg = gUnknown_0876E938[(s16)side + 20]; break;
    case 0x10: msg = gUnknown_0876E938[(s16)side + 22]; break;
    case 8: msg = gUnknown_0876E938[(s16)side + 24]; break;
    case 4: msg = gUnknown_0876E938[(s16)side + 26]; break;
    case 2: msg = gUnknown_0876E938[(s16)side + 28]; break;
    case 1: msg = gUnknown_0876E938[(s16)side + 30]; break;
    }
    BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(Battle_GetMessage(msg), who));
}

// sub_080F2C9C @ 0x080F2C9C
s32 sub_080F2C9C(s16 who)
{
    u16 list[8];
    s16 n = 0;
    s16 i;

    if (who < 16)
    {
        for (i = 16; i < 24; i++)
        {
            if (Combatant_IsUsed(i) && !Combatant_IsDead(i))
            {
                list[n] = i;
                n++;
            }
        }
    }
    else
    {
        for (i = 0; i < 6; i++)
        {
            s16 id = sub_080F40EC(i);
            if (id != -1 && !Combatant_IsDead(id))
            {
                list[n] = id;
                n++;
            }
        }
    }
    /* volatile read: the original loads the u16 and sign-extends it with shifts (no ldrsh) */
    return (s16)*(vu16 *)&list[Random_Byte() % n];
}

// sub_080F2D4C @ 0x080F2D4C
/* Picks a random skill for each able enemy unit (u->unk17 = action kind, unk5C = skill). */
#ifdef NONMATCHING
void sub_080F2D4C(void)
{
    s16 i;

    for (i = 0; i < 8; i++)
    {
        struct BattleUnit *u = &BFLOW->units[i];
        s16 id;
        s32 ok;
        s16 r;
        s32 skill;
        u32 kind;

        if (u->unkE == 0 || (u->flags & 0xB1E0))
            continue;
        id = u->id;
        if (!(u16)sub_080F30F8(id))
        {
            u->unk17 = 10;
            continue;
        }
        ok = 1;
        r = Random_Byte() & 7;
        if (r > 6)
            r = 0;
        skill = (Demon_GetRecord(id) + 0x11)[r];
        kind = sub_080ED694(skill);
        if (!(*sub_080BF5C0(skill) & 0x20) || skill == 0x3E || skill == 0x3F || skill == 0x36
         || skill == 0x37 || skill == 0x3C)
            ok = 0;
        else if (skill > 0x9F)
            ok = 0;
        else if (!sub_080ED744(i + 0x10, skill))
            ok = 0;
        else
        {
            if (skill < 0x40)
            {
                if (u->flags & 2)
                    ok = 0;
                u->unk17 = 7;
            }
            else
                u->unk17 = 11;
            if (kind == 0x80 || kind == 0x82)
            {
                s32 t = Battle_PickEnemySupportTarget(skill);
                if (t == -1)
                {
                    ok = 0;
                    goto next;
                }
                BFLOW->unkF50[i] = t;
            }
            u->unk5C = skill;
        }
    next:
        if (!ok)
            u->unk17 = 10;
        else if (skill == 0x9F)
        {
            if (gUnk_0203C174)
                u->unk17 = 10;
            if (++gUnk_0203C174 > 2)
                gUnk_0203C174 = 0;
        }
    }
}
#else
NAKED
void sub_080F2D4C(void)
{
    asm_unified(
        ".L080F2D4C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    movs r1, #0\n"
        ".L080F2D58:\n"
        "    lsls r0, r1, #0x10\n"
        "    asrs r1, r0, #0x10\n"
        "    mov r8, r1\n"
        "    lsls r1, r1, #7\n"
        "    movs r2, #0x9a\n"
        "    lsls r2, r2, #4\n"
        "    adds r1, r1, r2\n"
        "    ldr r2, .L080F2DE8\n"
        "    adds r5, r2, r1\n"
        "    ldrh r1, [r5, #0xe]\n"
        "    mov sl, r0\n"
        "    cmp r1, #0\n"
        "    bne .L080F2D74\n"
        "    b .L080F2E88\n"
        ".L080F2D74:\n"
        "    ldrh r1, [r5, #0x10]\n"
        "    ldr r2, .L080F2DEC\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080F2D82\n"
        "    b .L080F2E88\n"
        ".L080F2D82:\n"
        "    ldrh r0, [r5, #0x12]\n"
        "    lsls r6, r0, #0x10\n"
        "    asrs r0, r6, #0x10\n"
        "    bl sub_080F30F8\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L080F2E5A\n"
        "    movs r7, #1\n"
        "    bl Random_Byte\n"
        "    adds r4, r0, #0\n"
        "    movs r0, #7\n"
        "    mov sb, r0\n"
        "    mov r1, sb\n"
        "    ands r4, r1\n"
        "    cmp r4, #6\n"
        "    ble .L080F2DA8\n"
        "    movs r4, #0\n"
        ".L080F2DA8:\n"
        "    lsrs r0, r6, #0x10\n"
        "    bl Demon_GetRecord\n"
        "    lsls r1, r4, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    adds r0, #0x11\n"
        "    adds r0, r0, r1\n"
        "    ldrb r4, [r0]\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080ED694\n"
        "    adds r6, r0, #0\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080BF5C0\n"
        "    ldrb r1, [r0]\n"
        "    movs r0, #0x20\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080F2DE4\n"
        "    cmp r4, #0x3e\n"
        "    beq .L080F2DE4\n"
        "    cmp r4, #0x3f\n"
        "    beq .L080F2DE4\n"
        "    cmp r4, #0x36\n"
        "    beq .L080F2DE4\n"
        "    cmp r4, #0x37\n"
        "    beq .L080F2DE4\n"
        "    cmp r4, #0x3c\n"
        "    bne .L080F2DF0\n"
        ".L080F2DE4:\n"
        "    movs r7, #0\n"
        "    b .L080F2E5A\n"
        ".L080F2DE8: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080F2DEC: .4byte 0x0000B1E0\n"
        ".L080F2DF0:\n"
        "    cmp r4, #0x9f\n"
        "    ble .L080F2DF8\n"
        "    movs r7, #0\n"
        "    b .L080F2E5A\n"
        ".L080F2DF8:\n"
        "    mov r0, r8\n"
        "    adds r0, #0x10\n"
        "    adds r1, r4, #0\n"
        "    bl sub_080ED744\n"
        "    cmp r0, #0\n"
        "    bne .L080F2E0A\n"
        "    movs r7, #0\n"
        "    b .L080F2E5A\n"
        ".L080F2E0A:\n"
        "    cmp r4, #0x3f\n"
        "    bgt .L080F2E20\n"
        "    ldrh r1, [r5, #0x10]\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080F2E1A\n"
        "    movs r7, #0\n"
        ".L080F2E1A:\n"
        "    mov r2, sb\n"
        "    strb r2, [r5, #0x17]\n"
        "    b .L080F2E24\n"
        ".L080F2E20:\n"
        "    movs r0, #0xb\n"
        "    strb r0, [r5, #0x17]\n"
        ".L080F2E24:\n"
        "    cmp r6, #0x80\n"
        "    beq .L080F2E2C\n"
        "    cmp r6, #0x82\n"
        "    bne .L080F2E50\n"
        ".L080F2E2C:\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_PickEnemySupportTarget\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r1, r0\n"
        "    bne .L080F2E40\n"
        "    movs r7, #0\n"
        "    b .L080F2E5A\n"
        ".L080F2E40:\n"
        "    mov r2, sl\n"
        "    asrs r0, r2, #0xf\n"
        "    ldr r2, .L080F2E60\n"
        "    adds r0, r2, r0\n"
        "    movs r2, #0xf5\n"
        "    lsls r2, r2, #4\n"
        "    adds r0, r0, r2\n"
        "    strh r1, [r0]\n"
        ".L080F2E50:\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x5c\n"
        "    strb r4, [r0]\n"
        "    cmp r7, #0\n"
        "    bne .L080F2E64\n"
        ".L080F2E5A:\n"
        "    movs r0, #0xa\n"
        "    strb r0, [r5, #0x17]\n"
        "    b .L080F2E88\n"
        ".L080F2E60: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080F2E64:\n"
        "    cmp r4, #0x9f\n"
        "    bne .L080F2E88\n"
        "    ldr r1, .L080F2EA8\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r1, r2]\n"
        "    cmp r0, #0\n"
        "    beq .L080F2E76\n"
        "    movs r0, #0xa\n"
        "    strb r0, [r5, #0x17]\n"
        ".L080F2E76:\n"
        "    ldrh r0, [r1]\n"
        "    adds r0, #1\n"
        "    strh r0, [r1]\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #2\n"
        "    ble .L080F2E88\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        ".L080F2E88:\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #9\n"
        "    add r0, sl\n"
        "    lsrs r1, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #7\n"
        "    bgt .L080F2E98\n"
        "    b .L080F2D58\n"
        ".L080F2E98:\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080F2EA8: .4byte 0x0203C174 @ EWRAM+0x3C174\n"
    );
}
#endif

// Battle_PickEnemySupportTarget @ 0x080F2EAC
s32 Battle_PickEnemySupportTarget(s32 skill)
{
    struct BattleFlow *b = BFLOW;
    s32 kind = sub_080ED694(skill);
    s32 i;

    if (kind == 0x80)
        kind = 0;
    else if (kind == 0x82)
        kind = 1;
    for (i = 0; i < 8; i++)
    {
        struct BattleUnit *u = &b->units[i];
        if (u->unkE == 0 || (u->flags & 0x8000))
            continue;
        if (kind != 0)
        {
            if (u->flags)
                return i + 0x10;
        }
        else if (u->hp < u->maxHp)
            return i + 0x10;
    }
    return -1;
}

// Battle_GetLastOrderIndex @ 0x080F2F14
/* Index of the last entry of the action order (-1 when empty). */
s16 Battle_GetLastOrderIndex(void)
{
    s16 n = -1;
    s16 i;

    for (i = 0; i < 13 && (s16)BSTATE->order[i].id != -1; i++)
        n++;
    return n;
}

// Battle_GetCombatant @ 0x080F2F64
struct Combatant *Battle_GetCombatant(u16 idx)
{
    u16 i = idx & 0x7FFF;
    struct Combatant *c;

    if (i > 15)
    {
        struct BattleFlow *b = BFLOW;
        c = (struct Combatant *)&b->units[i - 16];
    }
    else
        c = Party_GetMember(idx);
    return c;
}

// sub_080F2F94 @ 0x080F2F94
/* Advances *pos to the next active party slot whose member can act; *out = its member. */
void sub_080F2F94(s16 *out, s16 *pos)
{
    for ((*pos)++; *pos <= 5; (*pos)++)
    {
        *out = sub_080F30CC(*pos);
        if (*out != -1 && Combatant_IsInParty(*out) && sub_080F3040(*out))
            return;
    }
}

// sub_080F2FEC @ 0x080F2FEC
/* As sub_080F2F94, backwards. */
void sub_080F2FEC(s16 *out, s16 *pos)
{
    for ((*pos)--; *pos >= 0; (*pos)--)
    {
        *out = sub_080F30CC(*pos);
        if (*out != -1 && Combatant_IsInParty(*out) && sub_080F3040(*out))
            return;
    }
}

// sub_080F3040 @ 0x080F3040
u16 sub_080F3040(s32 who)
{
    if (Combatant_GetStatus(who) & 0xB3F0)
        return 0;
    return 1;
}

// sub_080F3060 @ 0x080F3060
/* 1 when both enemy groups (0x10-0x13 and 0x14-0x17) have someone left. */
u32 sub_080F3060(void)
{
    s16 a = 0;
    s16 b = 0;
    s16 i;

    for (i = 0; i < 4; i++)
    {
        if (Combatant_IsAlive(i + 0x10))
            a++;
    }
    for (i = 0; i < 4; i++)
    {
        if (Combatant_IsAlive(i + 0x14))
            b++;
    }
    if (a == 0 || b == 0)
        return 0;
    return 1;
}

// sub_080F30CC @ 0x080F30CC
s32 sub_080F30CC(s32 slot)
{
    return gGameState.order[slot];
}

// sub_080F30E4 @ 0x080F30E4
/* K&R definition: callers pass the id unnarrowed. */
s32 sub_080F30E4(id)
    u16 id;
{
    return (s8)Demon_GetRecord(id)[0x10];
}

// sub_080F30F8 @ 0x080F30F8
s32 sub_080F30F8(s32 id)
{
    return sub_080ED3FC(1, (s16)sub_080F30E4(id));
}

// Battle_IsEnemyId @ 0x080F3110
s32 Battle_IsEnemyId(s32 who)
{
    if (who <= 15)
        return 0;
    return 1;
}

// sub_080F3120 @ 0x080F3120
void sub_080F3120(void)
{
    s16 i;

    for (i = 0; i < 6; i++)
    {
        struct Combatant *c = Party_GetMember(i);
        c->unk16 = c->unk17;
    }
}

// Battle_IsPartyDefeated @ 0x080F3144
/* 1 when no party member (0x8000-0x8003) is present and able. */
u32 Battle_IsPartyDefeated(void)
{
    s32 i;

    for (i = 0; i < 4; i++)
    {
        struct Combatant *c = Party_GetMember(i - 0x8000u);
        if (c && (c->unkE & 0xC000) && !(c->flags & 0xA000))
            return 0;
    }
    return 1;
}

// sub_080F3190 @ 0x080F3190
s32 sub_080F3190(void)
{
    struct Combatant *c = Party_GetMember(0x8000);

    if (gGameState.unkAC0 != 1)
    {
        u16 f = sub_080C5D0C();
        if (f & 0x80)
            return 0x55;
    }
    if (c->flags & 0xB1E0)
        return 0x53;
    return 0;
}

// sub_080F31E0 @ 0x080F31E0
u32 sub_080F31E0(void)
{
    if (gGameState.unkAC0 != 1)
    {
        u16 f = sub_080C5D0C();
        if (f & 0x8000)
            return 1;
    }
    return 0;
}

// sub_080F3214 @ 0x080F3214
/* Tries Combatant_SetStatus on a combatant without keeping its flag changes; 1 when it returned 0. */
s32 sub_080F3214(s32 who, u16 a)
{
    struct Combatant *c = Battle_GetCombatant(who - 0x8000u);
    u16 flags = c->flags;
    s32 r = Combatant_SetStatus(who, a);

    c->flags = flags;
    if (!r)
        return 1;
    return 0;
}
