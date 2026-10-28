/* Battle command menu, continued: party order swap, the pause (system) menu. */

#include "global.h"
#include "bmenu2.h"

// sub_0812CEE4 @ 0x0812CEE4
void sub_0812CEE4(void)
{
    sub_080EA210();
}

// sub_0812CEF0 @ 0x0812CEF0
void sub_0812CEF0(void)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk4C = sub_080C8AAC(0, blk->unk691);
    blk->unk50 = sub_080C8AC4(1, blk->unk691);
    sub_080C8ADC(blk->unk4C, 1);
    sub_080C8ADC(blk->unk50, 1);
}

// sub_0812CF2C @ 0x0812CF2C
void sub_0812CF2C(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;

    task->result = 0;
    task->pad1E = 0;
    if (!(gKeysNew & 2))
    {
        u16 idx;

        if (!(gKeysNew & 1))
            goto other;
        idx = sub_080C8AF4(blk->unk4C);
        if (gGameState.order[idx] != -1)
        {
            task->result = 1;
            sub_080C8ADC(blk->unk4C, 0);
            blk->unk691 = idx;
            task->pad1E = (u8)idx;
            sub_080ECF70(0x65);
            return;
        }
    }
    else
    {
        task->pad1E = 0x100;
        task->result = 1;
        sub_080C8ADC(blk->unk4C, 0);
    }
    sub_080ECF70(0x66);
    return;
other:
    if (gKeysNew & 0xF0)
        sub_080ECF70(0x64);
}

// sub_0812CFD0 @ 0x0812CFD0
void sub_0812CFD0(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;

    task->result = 0;
    task->pad1E = 0;
    if (gKeysNew & 2)
    {
        task->pad1E = 0x100;
        task->result = 1;
        sub_080C8ADC(blk->unk4C, 0);
        sub_080C8ADC(blk->unk50, 0);
        sub_080ECF70(0x66);
    }
    else if (gKeysNew & 1)
    {
        u16 idx;

        task->result = 1;
        sub_080C8ADC(blk->unk4C, 0);
        sub_080C8ADC(blk->unk50, 0);
        task->pad1E = idx = sub_080C8AF4(blk->unk4C);
        blk->unk692 = idx;
        sub_080ECF70(0x65);
    }
    else if (gKeysNew & 0xF0)
        sub_080ECF70(0x64);
}

// sub_0812D064 @ 0x0812D064
void sub_0812D064(void)
{
    struct C127Block *blk = C127_BLOCK;

    if (blk->unk4C != 0)
    {
        Task_End((struct Task *)blk->unk4C);
        blk->unk4C = 0;
    }
    if (blk->unk50 != 0)
    {
        Task_End((struct Task *)blk->unk50);
        blk->unk50 = 0;
    }
    sub_08128B84(1);
    BattleMsg_Close();
}

// sub_0812D098 @ 0x0812D098
void sub_0812D098(void)
{
    struct C127Block *blk = C127_BLOCK;

    if (blk->unk50 != 0)
    {
        Task_End((struct Task *)blk->unk50);
        blk->unk50 = 0;
    }
}

// sub_0812D0B4 @ 0x0812D0B4
void sub_0812D0B4(void)
{
    struct C127Block *blk = C127_BLOCK;

    if (blk->unk4C != 0)
    {
        Task_End((struct Task *)blk->unk4C);
        blk->unk4C = 0;
    }
    if (blk->unk50 != 0)
    {
        Task_End((struct Task *)blk->unk50);
        blk->unk50 = 0;
    }
    Party_SwapSlots(blk->unk691, blk->unk692);
    Party_FixFormation();
}

// sub_0812D0FC @ 0x0812D0FC
void sub_0812D0FC(u8 keep)
{
    struct C127Block *blk = C127_BLOCK;

    if (keep == 0)
    {
        sub_080C6FF0();
        sub_080C7414();
        sub_080C7218();
    }
    blk->unk40 = Task_Create(gUnknown_08779EC4, 0xFFFF);
}

// sub_0812D130 @ 0x0812D130
void sub_0812D130(void)
{
    DmaSet3Wait(gUnk_030000B4, (void *)0x06015000, 0x840000C0);
}

// sub_0812D168 @ 0x0812D168
void sub_0812D168(void)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk4C = TextWindow_Create(0xB, 1, 8, 6, 1);
    Hud_RenderGlyphTiles(gUnk_030000B4, gUnknown_08779E9C);
    VBlankTask_AddCounted(sub_0812D130, 1);
    sub_08126928(0, 1, 1, 3, 3);
}

// sub_0812D1B8 @ 0x0812D1B8
void sub_0812D1B8(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct MenuCursor *c = sub_08126D1C(0);
    u16 oldRow = c->row;
    u8 i;

    sub_08126A08(0);
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
        {
            BattleMenu_Reset();
            BattleMsg_Close();
        }
        else
        {
            sub_080EA210();
            BattleMenu_SetMode(4, gUnknown_08779EB8[c->row]);
        }
    }
    else if (oldRow != c->row && blk->unk7E0 == 4)
        BattleMenu_SetMode(4, gUnknown_08779EB8[c->row]);
    Sprite_Draw(gUnknown_08000F28, 0, 0, 0, 0, 0x5C, c->row * 12 + 12);
    for (i = 0; i < 3; i++)
    {
        Sprite_DrawSingle(gUnknown_08777F60[i], 0, 0, 0, 0, 0x60, (u16)(i * 12 + 16));
        Sprite_DrawSingle(gUnknown_08777F60[i] + 8, 0, 0, 0, 0, 0x80, (u16)(i * 12 + 16));
    }
}

// sub_0812D2F8 @ 0x0812D2F8
void sub_0812D2F8(void)
{
    struct C127Block *blk = C127_BLOCK;

    sub_081269B0(0);
    if (blk->unk4C != 0)
        TextWindow_Close(blk->unk4C, 0);
    if (blk->unk7E0 == 4)
        BattleMsg_Close();
}

// sub_0812D328 @ 0x0812D328
void sub_0812D328(void)
{
    sub_081279D4();
    if (gFieldState.state == 0x1B)
    {
        Field_SetState(0x1E);
        gFieldState.unk1E = 0;
    }
    else
        Field_SetState(1);
    sub_080C700C();
    sub_080C7430();
    sub_080C7234();
}

// sub_0812D360 @ 0x0812D360
void sub_0812D360(struct Task *task)
{
    switch (task->pad1E)
    {
    case 0:
        SaveScreen_Open(2, 1);
        break;
    case 1:
        SaveScreen_Open(0, 1);
        break;
    case 2:
        sub_080CFFE0(1);
        break;
    }
}

// sub_0812D390 @ 0x0812D390
void sub_0812D390(void)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk48 = Task_Create(gUnknown_0877A078, 0xFFFF);
    blk->unk48->data.raw[0] = 0;
}

// sub_0812D3B8 @ 0x0812D3B8
void sub_0812D3B8(void)
{
    DmaSet3Wait(gUnk_030000B4, (void *)0x06015000, 0x84000180);
}

// sub_0812D3F0 @ 0x0812D3F0
void sub_0812D3F0(void)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk4C = TextWindow_Create(8, 1, 0xE, 6, 1);
    Hud_RenderGlyphTiles(gUnk_030000B4, gUnknown_08779FD0);
    VBlankTask_AddCounted(sub_0812D3B8, 1);
    sub_08126928(3, 1, 1, 3, 3);
    BattleMenu_SetMode(3, gUnknown_081232AE);
    BattleMsg_SetDone(1);
}
