#include "global.h"
#include "battle.h"

// sub_080F0B78 @ 0x080F0B78
u32 sub_080F0B78(u32 who)
{
    u8 slot;
    struct BattleFlow *b = BFLOW;

    slot = who;
    slot -= 0x10;
    if (Battle_IsTwoSided() && b->unk118C == 0)
    {
        if (slot <= 3)
        {
            if (!sub_080EDA24(0))
                return 1;
        }
        else
        {
            if (!sub_080EDA24(1))
                return 1;
        }
    }
    return 0;
}

// sub_080F0BC0 @ 0x080F0BC0
void sub_080F0BC0(void)
{
    BFLOW->unk118C += 2;
}

// sub_080F0BD8 @ 0x080F0BD8
void sub_080F0BD8(void)
{
    BFLOW->unk97C = 10;
}

// sub_080F0BEC @ 0x080F0BEC
void sub_080F0BEC(void)
{
    struct BattleFlow *b = BFLOW;

    Task_Create(gUnknown_0876F7DC, 0xFFFF);
    b->unk97C = 15;
}

// sub_080F0C18 @ 0x080F0C18
/* Status effects that act before a combatant's turn (bits of the status word at +0x10). */
u32 sub_080F0C18(u8 *c, u16 who)
{
    struct BattleFlow *b = BFLOW;
    u16 f = *(u16 *)(c + 0x10);

    if (f & 0x200)
    {
        s16 w = who;

        if (w > 3)
            sub_080C35C4(w, 10);
        else if (Combatant_GetEquip(w, 0) != 0xFF)
            sub_080C35C4(w, 4);
        else
            sub_080C35C4(w, 9);
        return 0;
    }
    else if ((f & 8) && Random_Byte() % 40 <= 0x13)
    {
        BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(Battle_GetMessage(0x172), (s16)who));
        b->unk97C = 11;
        sub_080F0344(3, 12);
        return 1;
    }
    else if (f & 0x10)
    {
        u32 r = Random_Byte() & 3;

        if (r & 2)
        {
            s16 w = who;

            if (w <= 15)
            {
                if (w > 3 && !(r & 1))
                    sub_080C35C4(w, 12);
                else
                    sub_080C35C4((s16)who, 9);
            }
            else
                c[0x17] = 9;
        }
    }
    return 0;
}

