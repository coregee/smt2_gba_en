#include "global.h"
#include "battle.h"

// sub_080ED000 @ 0x080ED000
void sub_080ED000(struct Task *task)
{
    struct BattleFlow *b = BFLOW;

    task->result = 0;
    if (b->unk11A8 != 0)
        task->result = 1;
}

// sub_080ED024 @ 0x080ED024
void sub_080ED024(void)
{
    struct BattleFlow *b = BFLOW;

    sub_080EA210();
    switch (BSTATE->unk126)
    {
    case 1:
        BattleMenu_SetMode(3, MessageBox_ComposeNameText(b->combatants[Battle_ActiveSide()], gUnknown_0812466C));
        break;
    case 3:
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(gUnknown_0812464E, 0));
        break;
    case 2:
        BattleMenu_SetMode(3, MessageBox_ComposeNameText(b->combatants[Battle_ActiveSide()], gUnknown_0812463A));
        break;
    case 8:
        BattleMenu_SetMode(3, MessageBox_ComposeNameText(b->combatants[Battle_ActiveSide()], gUnknown_08124608));
        break;
    case 4:
    {
        u16 who = b->combatants[Battle_ActiveSide()];
        BattleMenu_SetMode(3, MessageBox_ComposeSpeciesText(who, who, 1, 1, gUnknown_081245B4));
        break;
    }
    case 5:
        BattleMenu_SetMode(3, MessageBox_ComposeNameText(b->combatants[Battle_ActiveSide()], gUnknown_081245F6));
        break;
    case 6:
        BattleMenu_SetMode(3, MessageBox_ComposeNameText(b->combatants[Battle_ActiveSide()], gUnknown_081245D2));
        break;
    case 7:
        BattleMenu_SetMode(3, MessageBox_ComposeNameText(b->combatants[Battle_ActiveSide()], gUnknown_081245F6));
        break;
    case 9:
    case 10:
        BattleMenu_SetMode(3, MessageBox_ComposeNameText(b->combatants[Battle_ActiveSide()], gUnknown_0812461A));
        break;
    case 11:
        BattleMenu_SetMode(3, MessageBox_ComposeNameText(b->combatants[Battle_ActiveSide()], gUnknown_0812461A));
        break;
    }
    b->unk11A8 = 0;
}

