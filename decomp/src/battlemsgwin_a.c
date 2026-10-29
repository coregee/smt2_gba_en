/* Battle message window setup. */

#include "global.h"
#include "battledisp.h"

// sub_080EA178 @ 0x080EA178
void sub_080EA178(void)
{
    struct C15cBattle *b = BB;
    struct C15cMsg *msg = &b->msg;
    s32 i = b->unkECE + 1;
    u8 any = 0;

    if (gUnk_0300005C >= Party_GetSkillCount(b->unkECE))
    {
        for (; i <= 3; i++)
        {
            if (Combatant_IsInParty(i) && Combatant_IsAlive(i))
                any = 1;
        }
        if (!any)
        {
            b->substate = 0x13;
            msg->done = 1;
            msg->mode = 1;
            return;
        }
    }
    sub_080EA210();
    sub_080E9870();
    msg->done = 1;
    msg->mode = 1;
    b->substate = 0xD;
}

// sub_080EA210 @ 0x080EA210
/* Clears the message window state and opens its task and window (two rows at y 11). */
void sub_080EA210(void)
{
    struct C15cBattle *b = BB;
    struct C15cMsg *msg = &b->msg;

    CpuFill32(0, msg, sizeof(*msg));
    if (b->unk970 == 0)
        b->unk970 = (u32)Task_Create(gUnknown_086BF708, 0xFFFF);
    if (b->unk974 == 0)
        b->unk974 = sub_080AB890(2, 0xB, 0x1A, 2, 0);
    msg->row = 0;
    Font_ResetGlyphSpriteCache(0x180);
}

// sub_080EA280 @ 0x080EA280
void sub_080EA280(void)
{
    struct C15cBattle *b = BB;
    struct C15cMsg *msg = &b->msg;

    CpuFill32(0, msg, 0x198);
    msg->row = 0;
}

// sub_080EA2AC @ 0x080EA2AC
void sub_080EA2AC(void)
{
    struct C15cBattle *b = BB;
    struct C15cMsg *msg = &b->msg;

    CpuFill32(0, msg, 0x198);
    b->unk970 = (u32)Task_Create(gUnknown_086BF708, 0xFFFF);
    b->unk974 = sub_080AB890(2, 0xD, 0x1A, 2, 0);
    msg->row = 1;
    Font_ResetGlyphSpriteCache(0x180);
}

// BattleMsg_FitWindow @ 0x080EA314
/* Sizes the message window to the number of lines (0x300 = new line) of text; 4 lines use
   a 7-row window. */
u8 BattleMsg_FitWindow(const u16 *text)
{
    struct C15cBattle *b = BB;
    const u16 *p = text;
    u8 n = 1;

    while (*p != 0 && *p != 0x301)
    {
        if (*p == 0x300)
            n++;
        p++;
    }
    if (n == 4)
        Window_SetHeight(b->unk974, 7);
    else
        Window_SetHeight(b->unk974, n * 2);
    return n;
}
