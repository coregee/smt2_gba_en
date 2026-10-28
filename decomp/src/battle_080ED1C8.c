#include "global.h"
#include "battle.h"

// sub_080ED1C8 @ 0x080ED1C8
void sub_080ED1C8(struct Task *task, s32 keep)
{
    struct BattleFlow *b = BFLOW;

    task->result = 0;
    if (BattleMsg_IsDone() == 1)
    {
        if (keep == 0)
        {
            switch (BSTATE->unk126)
            {
            case 5:
                if (sub_080ED9F4())
                    break;
            case 4:
            case 6:
            case 7:
            case 9:
            case 10:
            case 11:
                BattleMenu_Reset();
                if (b->window != NULL)
                {
                    Window_Close(b->window, 0);
                    b->window = NULL;
                }
                break;
            }
        }
        task->result = 1;
    }
}

// sub_080ED260 @ 0x080ED260
void sub_080ED260(void)
{
    u16 i;
    s32 changed = 0;
    s8 *slots;

    for (i = 0, slots = gUnk_030050E0; i < 6; i++)
    {
        s8 *slot = (s8 *)(i + (u32)slots);

        if (*slot != -1 && (Combatant_GetStatus(Party_GetMember(i)[0xC]) & 0x4000))
        {
            Party_Remove((u16)*slot, 0);
            changed = 1;
        }
    }
    if (changed == 1)
    {
        sub_080C366C();
        Party_BuildMemberNameTiles();
        sub_080C6FD8();
    }
}

// sub_080ED2D0 @ 0x080ED2D0
void sub_080ED2D0(struct Task *task)
{
    struct BattleFlow *b = BFLOW;

    task->result = 0;
    if (Battle_IsTwoSided() && b->unk118C == 0)
    {
        if (!sub_080EDA24(0) || !sub_080EDA24(1))
            task->result = 1;
    }
}
