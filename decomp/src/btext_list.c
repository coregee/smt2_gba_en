#include "global.h"
#include "btext.h"

/* Expands a list template (ends at 0x301) into the compose buffer. Codes: 0x31A-0x31E and
   0x325 = fixed combatant names, 0x320 = first active party member (+ 0xC8F when more than one
   is present), 0x321 = item arg >> 16, 0x324 = combatant arg & 0xFFFF, 0x316/0x317 = ignored. */
// Menu_ExpandListTemplate @ 0x080EBCA4
u16 *Menu_ExpandListTemplate(u16 *tmpl, u32 arg)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
    u16 who = arg;
    u16 *dst;
    u16 *src;
    u16 *name;
    u16 *p;
    u16 item;
    u16 i;
    s32 n;
    u8 k;
    u32 zero;

    if (msg->locked == 1)
        return msg->compose;

    if (tmpl == NULL)
        tmpl = msg->compose;
    zero = 0;
    CpuSet(&zero, msg->compose, 0x05000020);
    dst = msg->compose;
    src = tmpl;
    while (*src != 0x301)
    {
        switch (*src)
        {
        case 0x31A:
            dst = Battle_AppendCombatantName(0, dst);
            src++;
            break;
        case 0x31B:
            dst = Battle_AppendCombatantName(2, dst);
            src++;
            break;
        case 0x31C:
            dst = Battle_AppendCombatantName(3, dst);
            src++;
            break;
        case 0x31D:
            dst = Battle_AppendCombatantName(1, dst);
            src++;
            break;
        case 0x31E:
        case 0x325:
            dst = Battle_AppendCombatantName(0x10, dst);
            src++;
            break;
        case 0x320:
            for (i = 0; i < 4; i++)
            {
                if (sub_080F3EC8(i) && sub_080C0A00(i))
                    break;
            }
            if (i >= 4)
                i = 0;
            dst = Battle_AppendCombatantName(i, dst);
            n = sub_080F4968();
            for (i = 4; i < 16; i++)
            {
                if (sub_080F3EC8(i) && sub_080C0A00(i))
                    n++;
            }
            if (n > 1)
                *dst++ = 0xC8F;
            src++;
            break;
        case 0x324:
            dst = Battle_AppendCombatantName(who, dst);
            /* fall through */
        case 0x316:
        case 0x317:
            src++;
            break;
        case 0x321:
            item = arg >> 16;
            if (item < 0x80)
                name = (u16 *)(Item_GetRecord(item) + 0x14);
            else if (item < 0xD0)
                name = (u16 *)(Equipment_GetRecord36_MidRange(item) + 0x14);
            else if (item < 0xFF)
                name = (u16 *)(Action_GetRecord(item) + 0xC);
            /* item 0xFF..0xFFFF: name is left unset (original bug) */
            p = name;
            for (k = 0; k < 8 && *p != 0; k++)
                *dst++ = *p++;
            src++;
            break;
        case 0x31F:
        case 0x322:
        case 0x323:
        case 0x326:
        case 0x327:
        case 0x328:
        case 0x329:
            /* src is not advanced: these codes hang the game if they ever occur */
            break;
        default:
            *dst++ = *src++;
            break;
        }
    }
    return BLOCK->msg.compose;
}

/* Appends the name of combatant who (at most 8 characters) and returns the new end. */
// Battle_AppendCombatantName @ 0x080EBE7C
u16 *Battle_AppendCombatantName(u16 who, u16 *dst)
{
    u8 *actor;
    u16 *name;
    u8 i;
    u16 buf[8];

    actor = Battle_GetCombatant((u16)(who + 0x8000));
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
            goto end;
    }
end:
    return dst;
}
