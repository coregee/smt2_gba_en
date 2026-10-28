#include "global.h"
#include "battle.h"

// Combatant_AddHp @ 0x080F24F0
/* Adds d to a combatant's HP (+0x18) and returns the new value. */
s32 Combatant_AddHp(s32 who, s32 d)
{
    u8 *c = Battle_GetCombatant(who + 0x8000);

    *(u16 *)(c + 0x18) += d;
    return *(s16 *)(c + 0x18);
}
