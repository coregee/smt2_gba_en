#include "global.h"
#include "btext.h"

/* Copies at most 8 characters of a name, then drops trailing 0x70 (blank) characters. */
// Battle_BuildActorPrompt @ 0x080EAD80
u16 *Battle_BuildActorPrompt(u8 idx)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
    u8 *actor;
    u16 *src;
    u16 *dst;
    u8 i;
    u16 name[8];
    u32 zero;

    actor = Battle_GetCombatant(idx);
    if (msg->locked == 1)
        return b->msg.compose;

    zero = 0;
    CpuSet(&zero, b->msg.compose, 0x05000020);
    dst = b->msg.compose;
    if (actor[0xC] < 4)
    {
        Combatant_DecodeName(actor, name);
        src = name;
    }
    else
    {
        src = (u16 *)(Demon_GetRecord(*(u16 *)(actor + 0x12)) + 0x22);
    }
    for (i = 0; i < 8 && *src != 0; i++)
        *dst++ = *src++;
    while (*(dst - 1) == 0x70)
        dst--;
    src = (u16 *)gUnknown_081236BC;
    while (*src != 0)
        *dst++ = *src++;
    return BLOCK->msg.compose;
}

/* Actor name, first character of gUnknown_08123708, a line break, the name from
   sub_080BF5C0(actor[0x5C]) (at most 8 characters), then the rest of gUnknown_08123708. */
// sub_080EAE30 @ 0x080EAE30
u16 *sub_080EAE30(u8 *actor)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
    u16 *src;
    u16 *dst;
    u16 *s2;
    u8 i;
    u8 j;
    u16 name[8];
    u32 zero;

    if (msg->locked == 1)
        return b->msg.compose;

    zero = 0;
    CpuSet(&zero, b->msg.compose, 0x05000020);
    dst = b->msg.compose;
    if (actor[0xC] < 4)
    {
        Combatant_DecodeName(actor, name);
        src = name;
    }
    else
    {
        src = (u16 *)(Demon_GetRecord(*(u16 *)(actor + 0x12)) + 0x22);
    }
    for (i = 0; i < 8 && *src != 0; i++)
        *dst++ = *src++;
    while (*(dst - 1) == 0x70)
        dst--;
    src = (u16 *)gUnknown_08123708;
    *dst++ = *src++;
    *dst++ = 0x300;
    s2 = (u16 *)(sub_080BF5C0(actor[0x5C]) + 6);
    for (j = 0; j < 8; j++)
    {
        if (*s2 == 0)
            break;
        *dst++ = *s2++;
    }
    while (*src != 0)
        *dst++ = *src++;
    return BLOCK->msg.compose;
}

// sub_080EAF1C @ 0x080EAF1C
u16 *sub_080EAF1C(u8 *actor, u16 id)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
    u16 *src;
    u16 *dst;
    u16 *s2;
    u8 i;
    u8 j;
    u16 name[8];
    u32 zero;

    if (msg->locked == 1)
        return b->msg.compose;

    zero = 0;
    CpuSet(&zero, b->msg.compose, 0x05000020);
    dst = b->msg.compose;
    if (actor[0xC] < 4)
    {
        Combatant_DecodeName(actor, name);
        src = name;
    }
    else
    {
        src = (u16 *)(Demon_GetRecord(*(u16 *)(actor + 0x12)) + 0x22);
    }
    for (i = 0; i < 8 && *src != 0; i++)
        *dst++ = *src++;
    while (*(dst - 1) == 0x70)
        dst--;
    src = (u16 *)gUnknown_08123708;
    *dst++ = *src++;
    *dst++ = 0x300;
    s2 = (u16 *)(sub_080BF5C0(id) + 6);
    for (j = 0; j < 8; j++)
    {
        if (*s2 == 0)
            break;
        *dst++ = *s2++;
    }
    while (*src != 0)
        *dst++ = *src++;
    return BLOCK->msg.compose;
}

// sub_080EB008 @ 0x080EB008
u16 *sub_080EB008(u16 id)
{
    struct BattleMsgBlock *b = BLOCK;
    u16 *src;
    u16 *dst;
    u8 i;
    u32 zero;

    zero = 0;
    CpuSet(&zero, b->msg.compose, 0x05000020);
    dst = b->msg.compose;
    src = (u16 *)(sub_080BF5C0(id) + 6);
    for (i = 0; i < 8; i++)
    {
        if (*src == 0)
            break;
        *dst++ = *src++;
    }
    src = (u16 *)gUnknown_0812430C;
    while (*src != 0)
        *dst++ = *src++;
    return BLOCK->msg.compose;
}

// Battle_BuildActorActionText @ 0x080EB080
u16 *Battle_BuildActorActionText(u8 *actor)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
    u16 *src;
    u16 *dst;
    u16 *s2;
    u8 i;
    u8 j;
    u16 name[8];
    u32 zero;

    if (msg->locked == 1)
        return b->msg.compose;

    zero = 0;
    CpuSet(&zero, b->msg.compose, 0x05000020);
    dst = b->msg.compose;
    if (actor[0xC] < 4)
    {
        Combatant_DecodeName(actor, name);
        src = name;
    }
    else
    {
        src = (u16 *)(Demon_GetRecord(*(u16 *)(actor + 0x12)) + 0x22);
    }
    for (i = 0; i < 8 && *src != 0; i++)
        *dst++ = *src++;
    while (*(dst - 1) == 0x70)
        dst--;
    src = (u16 *)gUnknown_081236FC;
    *dst++ = *src++;
    *dst++ = 0x300;
    s2 = (u16 *)(Action_GetRecord(actor[0x5C]) + 0xC);
    for (j = 0; j < 8; j++)
    {
        if (*s2 == 0)
            break;
        *dst++ = *s2++;
    }
    while (*src != 0)
        *dst++ = *src++;
    return BLOCK->msg.compose;
}

// Battle_BuildStatusResultText @ 0x080EB16C
u16 *Battle_BuildStatusResultText(u8 *actor)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
    const u16 *src;
    u16 *dst;
    u8 i;
    u16 name[8];
    u32 zero;

    if (msg->locked == 1)
        return b->msg.compose;

    zero = 0;
    CpuSet(&zero, b->msg.compose, 0x05000020);
    dst = b->msg.compose;
    if (actor[0xC] < 4)
    {
        Combatant_DecodeName(actor, name);
        src = name;
    }
    else
    {
        src = (u16 *)(Demon_GetRecord(*(u16 *)(actor + 0x12)) + 0x22);
    }
    for (i = 0; i < 8 && *src != 0; i++)
        *dst++ = *src++;
    while (*(dst - 1) == 0x70)
        dst--;
    src = gUnknown_086BED5C[actor[0x5C] - 0x40];
    while (*src != 0)
        *dst++ = *src++;
    return BLOCK->msg.compose;
}

// Battle_BuildCombatActionList @ 0x080EB220
u16 *Battle_BuildCombatActionList(u8 *actor, u8 action)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
    const u16 *src;
    u16 *dst;
    u8 i;
    u16 name[8];
    u32 zero;

    if (msg->locked == 1)
        return b->msg.compose;

    zero = 0;
    CpuSet(&zero, b->msg.compose, 0x05000020);
    dst = b->msg.compose;
    if (actor[0xC] < 4)
    {
        Combatant_DecodeName(actor, name);
        src = name;
    }
    else
    {
        src = (u16 *)(Demon_GetRecord(*(u16 *)(actor + 0x12)) + 0x22);
    }
    for (i = 0; i < 8 && *src != 0; i++)
        *dst++ = *src++;
    while (*(dst - 1) == 0x70)
        dst--;
    src = gUnknown_086BEF5C[action];
    while (*src != 0)
        *dst++ = *src++;
    return BLOCK->msg.compose;
}

// Battle_BuildNamePrependText @ 0x080EB2D4
u16 *Battle_BuildNamePrependText(u16 idx, u16 *suffix)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
    u8 *actor;
    u16 *src;
    u16 *dst;
    u8 i;
    u16 name[8];
    u32 zero;

    actor = Battle_GetCombatant(idx);
    if (msg->locked == 1)
        return b->msg.compose;

    zero = 0;
    CpuSet(&zero, b->msg.compose, 0x05000020);
    dst = b->msg.compose;
    if (actor[0xC] < 4)
    {
        Combatant_DecodeName(actor, name);
        src = name;
    }
    else
    {
        src = (u16 *)(Demon_GetRecord(*(u16 *)(actor + 0x12)) + 0x22);
    }
    i = 0;
    while (*src != 0)
    {
        *dst++ = *src++;
        if (++i > 7)
            goto trim; /* a break here compiles to a different loop shape */
    }
trim:
    while (*(dst - 1) == 0x70)
        dst--;
    src = suffix;
    while (*src != 0)
        *dst++ = *src++;
    return BLOCK->msg.compose;
}

/* pre[0] is the number of characters (pre[1..]) to put before the actor name; the rest of pre
   follows the name. */
// Battle_BuildNamePrefixText @ 0x080EB37C
u16 *Battle_BuildNamePrefixText(u16 idx, u16 *pre)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
    u8 *actor;
    u16 *src;
    u16 *p;
    u16 *dst;
    u16 n;
    u8 i;
    u16 name[8];
    u32 zero;

    if (msg->locked == 1)
        return b->msg.compose;
    actor = Battle_GetCombatant(idx);
    if (msg->locked == 1)
        return b->msg.compose;

    zero = 0;
    CpuSet(&zero, b->msg.compose, 0x05000020);
    dst = b->msg.compose;
    p = pre;
    for (n = *p++; n != 0; n--)
        *dst++ = *p++;
    if (actor[0xC] < 4)
    {
        Combatant_DecodeName(actor, name);
        src = name;
    }
    else
    {
        src = (u16 *)(Demon_GetRecord(*(u16 *)(actor + 0x12)) + 0x22);
    }
    i = 0;
    while (*src != 0)
    {
        *dst++ = *src++;
        if (++i > 7)
            goto trim; /* a break here compiles to a different loop shape */
    }
trim:
    while (*(dst - 1) == 0x70)
        dst--;
    while (*p != 0)
        *dst++ = *p++;
    return BLOCK->msg.compose;
}
