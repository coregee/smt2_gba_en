#include "global.h"
#include "btext.h"

// BattleMsg_IsDone @ 0x080EA934
bool32 BattleMsg_IsDone(void)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;

    if (msg->locked != 1 && ((msg->mode != 1 && msg->mode != 5) || msg->done != 1))
        return FALSE;
    return TRUE;
}

// BattleMsg_Close @ 0x080EA964
void BattleMsg_Close(void)
{
    struct BattleMsgBlock *b = BLOCK;

    b->msg.mode = 0;
    if (b->window != NULL)
    {
        Window_Close(b->window, 1);
        b->window = NULL;
    }
    if (b->task != NULL)
    {
        Task_End(b->task);
        b->task = NULL;
    }
}

/* Declared with a return value it never sets: the original epilogue keeps r0. */
// sub_080EA9A4 @ 0x080EA9A4
u32 sub_080EA9A4(u32 unused)
{
    struct BattleMsgBlock *b = BLOCK;

    b->msg.mode = 0;
    if (b->window != NULL)
    {
        Window_Close(b->window, 0);
        b->window = NULL;
    }
    if (b->task != NULL)
    {
        Task_End(b->task);
        b->task = NULL;
    }
}

// BattleMsg_SetLocked @ 0x080EA9E8
void BattleMsg_SetLocked(u8 locked)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;

    msg->locked = locked;
}

// sub_080EA9F8 @ 0x080EA9F8
u32 sub_080EA9F8(u8 i)
{
    return gUnknown_086BEC98[i];
}
