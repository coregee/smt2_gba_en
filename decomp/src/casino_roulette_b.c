/* Russian Roulette, continued: which stock demons may be put up as a stake. */

#include "global.h"
#include "battle2.h"

/* 1 if stock demon `id` can be bet: not demon 0, 0xDE or 0x16A-0x17B, not dead (status
   0x8000) or 0x2000, and demon 0x8B only once flag 0x23 is set. */
// RussianRoulette_CanBetDemon @ 0x0814E844
s32 RussianRoulette_CanBetDemon(u32 id)
{
    struct Combatant *m = Party_GetMember(id + 0x8000);

    if ((u16)(m->demonId - 0x16A) <= 0x11 || m->demonId == 0xDE || m->demonId == 0
        || (Combatant_GetStatus(m->race) & 0x8000)
        || (Combatant_GetStatus(m->race) & 0x2000)
        || (m->demonId == 0x8B && !Flag_Test(0x23)))
        return 0;
    return 1;
}

/* Number of stock demons (slots 4-15) that can be bet. */
// RussianRoulette_CountBettableDemons @ 0x0814E8B0
s32 RussianRoulette_CountBettableDemons(void)
{
    s32 count = 0;
    u32 i;

    for (i = 4; i <= 15; i++)
    {
        if (Combatant_IsUsed(i) && RussianRoulette_CanBetDemon(gGameState.members[i].race) == 1)
            count++;
    }
    return count;
}
