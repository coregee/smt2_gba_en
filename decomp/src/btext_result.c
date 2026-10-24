#include "global.h"
#include "btext.h"

/* Actor name, the first two characters of tmpl, the decimal value (digits from
   NumberToDigits, least significant first, at most 8), then the rest of tmpl. */
// Battle_BuildDamageDealtText @ 0x080EB454
u16 *Battle_BuildDamageDealtText(u8 *actor, u32 value, u16 *tmpl)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
    u16 *name;
    u16 *src;
    u16 *dst;
    u8 *digits;
    u8 i;
    u8 j;
    u16 buf[8];
    u32 zero;

    if (msg->locked == 1)
        return b->msg.compose;

    zero = 0;
    CpuSet(&zero, b->msg.compose, 0x05000020);
    dst = b->msg.compose;
    if (actor[0xC] < 4)
    {
        Combatant_DecodeName(actor, buf);
        name = buf;
    }
    else
    {
        name = (u16 *)(sub_080BF648(*(u16 *)(actor + 0x12)) + 0x22);
    }
    i = 0;
    while (*name != 0)
    {
        *dst++ = *name++;
        if (++i > 7)
            goto trim;
    }
trim:
    while (*(dst - 1) == 0x70)
        dst--;
    src = tmpl;
    *dst++ = *src++;
    *dst++ = *src++;
    digits = NumberToDigits(value);
    for (j = 0; j < 8; j++, digits++)
        buf[j] = *digits;
    j = 8;
    do
    {
        if (buf[j - 1] != 0)
            break;
        j--;
    } while (j != 1);
    while (j != 0)
    {
        *dst++ = gBattleDigitGlyphs[buf[j - 1]];
        j--;
    }
    while (*src != 0)
        *dst++ = *src++;
    return BLOCK->msg.compose;
}

// Battle_BuildDefeatedTargetText @ 0x080EB570
u16 *Battle_BuildDefeatedTargetText(u8 *actor)
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
        src = (u16 *)(sub_080BF648(*(u16 *)(actor + 0x12)) + 0x22);
    }
    for (i = 0; i < 8 && *src != 0; i++)
        *dst++ = *src++;
    while (*(dst - 1) == 0x70)
        dst--;
    src = gUnknown_08123BC2;
    while (*src != 0)
        *dst++ = *src++;
    return BLOCK->msg.compose;
}

/* Five characters of gUnknown_081230BE, the actor name, then the next five (no terminator is
   copied; the cleared buffer provides it). */
// Battle_BuildDodgeText @ 0x080EB618
u16 *Battle_BuildDodgeText(u8 *actor)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
    const u16 *src;
    u16 *name;
    u16 *dst;
    u8 i;
    u16 buf[8];
    u32 zero;

    if (msg->locked == 1)
        return b->msg.compose;

    zero = 0;
    CpuSet(&zero, b->msg.compose, 0x05000020);
    dst = b->msg.compose;
    src = gUnknown_081230BE;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    if (actor[0xC] < 4)
    {
        Combatant_DecodeName(actor, buf);
        name = buf;
    }
    else
    {
        name = (u16 *)(sub_080BF648(*(u16 *)(actor + 0x12)) + 0x22);
    }
    for (i = 0; i < 8 && *name != 0; i++)
        *dst++ = *name++;
    while (*(dst - 1) == 0x70)
        dst--;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = *src++;
    return BLOCK->msg.compose;
}

/* Five characters of tmpl, the actor name, then the next four. */
// Battle_BuildActorStatusText @ 0x080EB71C
u16 *Battle_BuildActorStatusText(u8 *actor, u16 *tmpl)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
    u16 *name;
    u16 *dst;
    u8 i;
    u16 buf[8];
    u32 zero;

    if (msg->locked == 1)
        return b->msg.compose;

    zero = 0;
    CpuSet(&zero, b->msg.compose, 0x05000020);
    dst = b->msg.compose;
    *dst++ = *tmpl++;
    *dst++ = *tmpl++;
    *dst++ = *tmpl++;
    *dst++ = *tmpl++;
    *dst++ = *tmpl++;
    if (actor[0xC] < 4)
    {
        Combatant_DecodeName(actor, buf);
        name = buf;
    }
    else
    {
        name = (u16 *)(sub_080BF648(*(u16 *)(actor + 0x12)) + 0x22);
    }
    for (i = 0; i < 8 && *name != 0; i++)
        *dst++ = *name++;
    while (*(dst - 1) == 0x70)
        dst--;
    *dst++ = *tmpl++;
    *dst++ = *tmpl++;
    *dst++ = *tmpl++;
    *dst++ = *tmpl++;
    return BLOCK->msg.compose;
}

/* tmpl up to and including its first line break (0x300), the actor name, then the rest. */
// sub_080EB810 @ 0x080EB810
u16 *sub_080EB810(u8 *actor, u16 *tmpl)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
    u16 *name;
    u16 *src;
    u16 *dst;
    u8 i;
    u16 buf[8];
    u32 zero;

    if (msg->locked == 1)
        return b->msg.compose;

    zero = 0;
    CpuSet(&zero, b->msg.compose, 0x05000020);
    dst = b->msg.compose;
    src = tmpl;
    while (*src != 0x300)
        *dst++ = *src++;
    *dst++ = *src++;
    if (actor[0xC] < 4)
    {
        Combatant_DecodeName(actor, buf);
        name = buf;
    }
    else
    {
        name = (u16 *)(sub_080BF648(*(u16 *)(actor + 0x12)) + 0x22);
    }
    i = 0;
    while (*name != 0)
    {
        *dst++ = *name++;
        if (++i > 7)
            goto trim;
    }
trim:
    while (*(dst - 1) == 0x70)
        dst--;
    while (*src != 0)
        *dst++ = *src++;
    return BLOCK->msg.compose;
}
