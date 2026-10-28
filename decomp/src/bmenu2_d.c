/* Pause menu submenus (battle-speed / message options). */

#include "global.h"
#include "bmenu2.h"

// sub_0812D450 @ 0x0812D450
void sub_0812D450(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct MenuCursor *c = sub_08126D1C(3);
    u16 oldRow = c->row;
    u8 i;

    sub_08126A08(3);
    task->pad1E = 0;
    task->result = 0;
    if (gKeysNew & 1)
    {
        task->pad1E = c->row;
        task->result = 1;
    }
    else if (gKeysNew & 2)
    {
        task->pad1E = 0xFF;
        task->result = 1;
    }
    else if (c->state == 6)
    {
        if (blk->unk7E0 == 4)
            BattleMenu_SetMode(3, gUnknown_081232AE);
        else
            BattleMenu_SetMode(4, gUnknown_0877A004[c->row]);
    }
    else if (oldRow != c->row && blk->unk7E0 == 4)
        BattleMenu_SetMode(4, gUnknown_0877A004[c->row]);
    Sprite_Draw(gUnknown_08000E28, 0, 0, 0, 0, 0x40, c->row * 12 + 12);
    for (i = 0; i < 3; i++)
    {
        /* gUnknown_08777F60 here holds rows of four 8-byte sprite templates */
        Sprite_DrawSingle((const u8 *)gUnknown_08777F60 + i * 32, 0, 0, 0, 0, 0x44, (u16)(i * 12 + 16));
        Sprite_DrawSingle((const u8 *)gUnknown_08777F60 + 8 + i * 32, 0, 0, 0, 0, 0x64, (u16)(i * 12 + 16));
        Sprite_DrawSingle((const u8 *)gUnknown_08777F60 + 16 + i * 32, 0, 0, 0, 0, 0x84, (u16)(i * 12 + 16));
        Sprite_DrawSingle((const u8 *)gUnknown_08777F60 + 24 + i * 32, 0, 0, 0, 0, 0xA4, (u16)(i * 12 + 16));
    }
}

// sub_0812D5C8 @ 0x0812D5C8
void sub_0812D5C8(void)
{
    struct C127Block *blk = C127_BLOCK;

    sub_081269B0(3);
    if (blk->unk4C != 0)
        TextWindow_Close(blk->unk4C, 0);
    BattleMenu_Reset();
}

// sub_0812D5EC @ 0x0812D5EC
void sub_0812D5EC(void)
{
    C127_BLOCK->unk48->data.raw[0] = 1;
}

// sub_0812D5FC @ 0x0812D5FC
u8 sub_0812D5FC(void)
{
    return C127_BLOCK->unk48->data.raw[0];
}

// sub_0812D60C @ 0x0812D60C
void sub_0812D60C(void)
{
    DmaSet3Wait(gUnk_030000B4, (void *)0x06015000, 0x84000040);
}

// sub_0812D644 @ 0x0812D644
void sub_0812D644(void)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk4C = TextWindow_Create(0xC, 1, 6, 4, 1);
    sub_080C7E24(gUnk_030000B4, gUnknown_0877A010);
    VBlankTask_AddCounted(sub_0812D60C, 1);
    sub_08126928(3, 1, 1, 2, 2);
    MenuCursor_SetIndex(3, sub_080C2B6C());
    BattleMenu_SetMode(3, gUnknown_08123374);
    BattleMsg_SetDone(1);
}

// sub_0812D6B8 @ 0x0812D6B8
void sub_0812D6B8(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct MenuCursor *c = sub_08126D1C(3);
    u16 oldRow = c->row;

    sub_08126A08(3);
    task->pad1E = 0;
    task->result = 0;
    if (gKeysNew & 1)
    {
        task->pad1E = c->row;
        task->result = 1;
        sub_080C2B84(gUnknown_0877A024[c->row]);
    }
    else if (gKeysNew & 2)
    {
        task->pad1E = 0xFF;
        task->result = 1;
    }
    else if (c->state == 6)
    {
        if (blk->unk7E0 == 4)
        {
            BattleMenu_SetMode(3, gUnknown_08123374);
            BattleMsg_SetDone(1);
        }
        else
            BattleMenu_SetMode(4, gUnknown_0877A01C[c->row]);
    }
    else if (oldRow != c->row && blk->unk7E0 == 4)
        BattleMenu_SetMode(4, gUnknown_0877A01C[c->row]);
    Sprite_Draw(gUnknown_08000F00, 0, 0, 0, 0, 0x64, c->row * 12 + 10);
    Sprite_DrawSingle(gUnknown_08777F60[0], 0, 0, 0, 0, 0x6C, 0xE);
    Sprite_DrawSingle(gUnknown_08777F60[0] + 8, 0, 0, 0, 0, 0x6C, 0x1A);
}

// sub_0812D7E4 @ 0x0812D7E4
void sub_0812D7E4(void)
{
    DmaSet3Wait(gUnk_030000B4, (void *)0x06015000, 0x84000080);
}

// sub_0812D81C @ 0x0812D81C
void sub_0812D81C(void)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk4C = TextWindow_Create(0xB, 1, 8, 4, 1);
    sub_080C7E24(gUnk_030000B4, gUnknown_0877A028);
    VBlankTask_AddCounted(sub_0812D7E4, 1);
    sub_08126928(3, 1, 1, 2, 2);
    MenuCursor_SetIndex(3, Settings_GetBattleMsgSpeed());
    BattleMenu_SetMode(3, gUnknown_081233D2);
    BattleMsg_SetDone(1);
}

// sub_0812D890 @ 0x0812D890
void sub_0812D890(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct MenuCursor *c = sub_08126D1C(3);
    u16 oldRow = c->row;
    u8 i;

    sub_08126A08(3);
    task->pad1E = 0;
    task->result = 0;
    if (gKeysNew & 1)
    {
        task->pad1E = c->row;
        task->result = 1;
        sub_080C2B4C(gUnknown_0877A044[c->row]);
    }
    else if (gKeysNew & 2)
    {
        task->pad1E = 0xFF;
        task->result = 1;
    }
    else if (c->state == 6)
    {
        if (blk->unk7E0 == 4)
        {
            BattleMenu_SetMode(3, gUnknown_081233D2);
            BattleMsg_SetDone(1);
        }
        else
            BattleMenu_SetMode(4, gUnknown_0877A03C[c->row]);
    }
    else if (oldRow != c->row && blk->unk7E0 == 4)
        BattleMenu_SetMode(4, gUnknown_0877A03C[c->row]);
    Sprite_Draw(gUnknown_08000F28, 0, 0, 0, 0, 0x5C, c->row * 12 + 10);
    for (i = 0; i < 2; i++)
    {
        Sprite_DrawSingle(gUnknown_08777F60[i], 0, 0, 0, 0, 0x60, (u16)(i * 12 + 14));
        Sprite_DrawSingle(gUnknown_08777F60[i] + 8, 0, 0, 0, 0, 0x80, (u16)(i * 12 + 14));
    }
}

// sub_0812D9EC @ 0x0812D9EC
void sub_0812D9EC(void)
{
    DmaSet3Wait(gUnk_030000B4, (void *)0x06015000, 0x840000C0);
}

// sub_0812DA24 @ 0x0812DA24
void sub_0812DA24(void)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk4C = TextWindow_Create(0xB, 1, 8, 6, 1);
    sub_080C7E24(gUnk_030000B4, gUnknown_0877A048);
    VBlankTask_AddCounted(sub_0812D9EC, 1);
    sub_08126928(3, 1, 1, 3, 3);
    MenuCursor_SetIndex(3, sub_080C2BA4());
    BattleMenu_SetMode(3, gUnknown_08123444);
    BattleMsg_SetDone(1);
}

// sub_0812DA94 @ 0x0812DA94
void sub_0812DA94(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct MenuCursor *c = sub_08126D1C(3);
    u16 oldRow = c->row;
    u8 i;

    sub_08126A08(3);
    task->pad1E = 0;
    task->result = 0;
    if (gKeysNew & 1)
    {
        task->pad1E = c->row;
        task->result = 1;
        sub_080C2BCC(gUnknown_0877A070[c->row]);
    }
    else if (gKeysNew & 2)
    {
        task->pad1E = 0xFF;
        task->result = 1;
    }
    else if (c->state == 6)
    {
        if (blk->unk7E0 == 4)
        {
            BattleMenu_SetMode(3, gUnknown_08123444);
            BattleMsg_SetDone(1);
        }
        else
            BattleMenu_SetMode(4, gUnknown_0877A064[c->row]);
    }
    else if (oldRow != c->row && blk->unk7E0 == 4)
        BattleMenu_SetMode(4, gUnknown_0877A064[c->row]);
    Sprite_Draw(gUnknown_08000F28, 0, 0, 0, 0, 0x5C, c->row * 12 + 13);
    for (i = 0; i < 3; i++)
    {
        Sprite_DrawSingle(gUnknown_08777F60[i], 0, 0, 0, 0, 0x64, (u16)(i * 12 + 17));
        Sprite_DrawSingle(gUnknown_08777F60[i] + 8, 0, 0, 0, 0, 0x84, (u16)(i * 12 + 17));
    }
}
