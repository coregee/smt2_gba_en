/* Script message window: equipment counts. */

#include "global.h"
#include "bmenu2.h"

// sub_08131A84 @ 0x08131A84
void sub_08131A84(struct Task *task)
{
    task->result = 0;
    gUnk_030068BC = 1;
    sub_081316FC();
    gUnk_030065E4 = 0;
    gUnk_030068D4 = 10;
}

/* How many of party slots 0-2 (who 0xFF) or member `who` have `item` equipped
   (items below 0xD0 only). */
// Party_CountEquipped @ 0x08131AB0
u16 Party_CountEquipped(u16 who, u16 item)
{
    u16 n = 0;
    u16 slot;
    u16 i;

    if (item > 0xCF)
        return 0;
    slot = sub_080D2268(item);
    if ((s16)who == 0xFF)
    {
        for (i = 0; i < 3; i++)
        {
            if (Combatant_IsUsed(i) && (u16)Combatant_GetEquip(i, slot) == item)
                n++;
        }
    }
    else if ((u16)Combatant_GetEquip((s16)who, slot) == item)
        n = 1;
    return n;
}
