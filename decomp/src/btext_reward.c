#include "global.h"
#include "btext.h"

/* Demon name (at most 8 characters), the decimal count, tmpl[3..4], a line break, then the
   rest of tmpl from tmpl[5]. tmpl[0..2] are skipped. */
// Battle_BuildRaceCountText @ 0x080EB8DC
u16 *Battle_BuildRaceCountText(u16 id, u16 count, u16 *tmpl)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
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
    src = (u16 *)(Demon_GetRecord(id) + 0x22);
    for (i = 0; i < 8; i++)
    {
        if (*src == 0)
            break;
        *dst++ = *src++;
    }
    src = tmpl;
    src += 3;
    digits = NumberToDigits(count);
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
    *dst++ = *src++;
    *dst++ = *src++;
    *dst++ = 0x300;
    while (*src != 0)
        *dst++ = *src++;
    return BLOCK->msg.compose;
}

/* tmpl holds three zero-terminated pieces: text, [actor name], text, [value], text. */
// Battle_BuildRewardText @ 0x080EB9EC
u16 *Battle_BuildRewardText(u8 *actor, u32 value, u16 *tmpl)
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
    src = tmpl;
    while (*src != 0)
        *dst++ = *src++;
    src++;
    if (actor[0xC] < 4)
    {
        Combatant_DecodeName(actor, buf);
        name = buf;
    }
    else
    {
        name = (u16 *)(Demon_GetRecord(*(u16 *)(actor + 0x12)) + 0x22);
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
    src++;
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

/* tmpl holds two zero-terminated pieces around the decimal value. */
// Battle_BuildValueRewardText @ 0x080EBB20
u16 *Battle_BuildValueRewardText(u16 value, u16 *tmpl)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
    u16 *src;
    u16 *dst;
    u8 *digits;
    u8 j;
    u16 buf[8];
    u32 zero;

    if (msg->locked == 1)
        return b->msg.compose;

    zero = 0;
    CpuSet(&zero, b->msg.compose, 0x05000020);
    dst = b->msg.compose;
    src = tmpl;
    while (*src != 0)
        *dst++ = *src++;
    src++;
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

/* tmpl holds two zero-terminated pieces around the item name (at most 8 characters). Items
   below 0x80 and below 0xD0 come from two record tables, the rest are actions. */
// Battle_BuildItemDropText @ 0x080EBBF0
u16 *Battle_BuildItemDropText(u16 item, u16 *tmpl)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
    u16 *name;
    u16 *src;
    u16 *dst;
    u8 i;
    u32 zero;

    if (msg->locked == 1)
        return b->msg.compose;

    zero = 0;
    CpuSet(&zero, b->msg.compose, 0x05000020);
    dst = b->msg.compose;
    src = tmpl;
    while (*src != 0)
        *dst++ = *src++;
    src++;
    if (item < 0x80)
        name = (u16 *)(Item_GetRecord(item) + 0x14);
    else if (item < 0xD0)
        name = (u16 *)(Equipment_GetRecord36_MidRange(item) + 0x14);
    else
        name = (u16 *)(Action_GetRecord(item) + 0xC);
    i = 0;
    while (*name != 0)
    {
        *dst++ = *name++;
        if (++i > 7)
            goto rest;
    }
rest:
    while (*src != 0)
        *dst++ = *src++;
    return BLOCK->msg.compose;
}
