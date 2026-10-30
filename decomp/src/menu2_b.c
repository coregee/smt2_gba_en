#include "global.h"
#include "menu2.h"

/* Prize list input: A takes the prize under the cursor (if sub_080C5B10 allows it), B cancels,
   up/down move by one row, L/R by a page. */
// CasinoPrize_HandleInput @ 0x080D38D0
void CasinoPrize_HandleInput(struct Task *task)
{
    struct PrizeList *list = (struct PrizeList *)task->data.w;
    u16 *prizes = gUnk_0203B454;
    u16 count = list->count;
    u16 rows;

    task->result = 0;
    task->unk1E = 0;
    rows = count;
    if (count > 5)
        rows = 6;
    if (gKeysNew & 1)
    {
        u16 id = prizes[list->cursor + list->top];
        u32 blocked = sub_080C5B10(id);
        if (blocked == 0)
        {
            Sound_Play(0x65);
            task->unk1E = 1;
            task->result = 1;
            gYesNoResult = blocked;
            gScriptItemCheckId = id;
            gUnk_0203DB2C = 10000;
        }
        else
            Sound_Play(0x66);
    }
    else if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        task->result = 1;
        task->unk1E = 0xFFFF;
        gYesNoResult = 1;
    }
    else if (gRepeatedKeys & 0x40)
    {
        if (list->cursor != 0)
            list->cursor--;
        else if (list->top != 0)
            list->top--;
        else
            return;
        Sound_Play(100);
    }
    else if (gRepeatedKeys & 0x80)
    {
        if (list->cursor != rows - 1)
            list->cursor++;
        else if (list->cursor == 5 && list->cursor + list->top + 1 <= count - 1)
            list->top++;
        else
            return;
        Sound_Play(100);
    }
    else if ((gRepeatedKeys & 0x200) && count > 6)
    {
        u32 cursor = list->cursor;
        u16 top = list->top;
        u16 v = cursor;

        if (v != 0)
            list->cursor = 0;
        else if (top > 4)
            list->top = top - 5;
        else
            list->top = v;
        if (cursor != list->cursor || top != list->top)
            Sound_Play(100);
    }
    else if ((gRepeatedKeys & 0x100) && count > 6)
    {
        u16 cursor = list->cursor;
        u16 top = list->top;
        if (list->cursor != 5)
            list->cursor = 5;
        else if (list->cursor + list->top + 6 < count - 1)
            list->top += 6;
        else
            list->top = count - 6;
        if (cursor != list->cursor || top != list->top)
            Sound_Play(100);
    }
}

// sub_080D3A48 @ 0x080D3A48
void sub_080D3A48(struct Task *task)
{
    Tilemap_FillRect(0, gWindowTilemapBuffer, 0x15, 0, 8, 2);
    TextWindow_Close((struct Task *)task->data.w[0], 1);
}

// sub_080D3A78 @ 0x080D3A78
void sub_080D3A78(struct Task *task)
{
    task->result = task->unk06;
}

// sub_080D3A80 @ 0x080D3A80
void sub_080D3A80(void)
{
    gUnk_03003FEC = Task_Create(gUnknown_084F3228, 0xFFFF);
}

// sub_080D3AA0 @ 0x080D3AA0
u32 sub_080D3AA0(u32 op)
{
    if (op == 0)
    {
        Font_ResetGlyphSpriteCache(0x180);
        if (gUnk_03003FEC->unk1E != 0)
            return 1;
    }
    else if (op == 1)
    {
        Task_Signal(gUnk_03003FEC);
        gUnk_03003FEC->unk1E = 0;
        gUnk_03003FEC->unk06 = op;
    }
    else
    {
        Task_Signal(gUnk_03003FEC);
        gUnk_03003FEC->unk1E = 0;
        gUnk_03003FEC->unk06 = 0;
    }
    return 0;
}

// sub_080D3B00 @ 0x080D3B00
void sub_080D3B00(void)
{
    gUnk_03003FEC = NULL;
}

// sub_080D3B0C @ 0x080D3B0C
void sub_080D3B0C(u32 unused, u32 result)
{
    gYesNoResult = result;
}

// sub_080D3B18 @ 0x080D3B18
void sub_080D3B18(void)
{
    u32 *state = (u32 *)&gMenuState;
    u32 zero;
    u32 zero2;

    *state = 0x13240800;
    zero = 0;
    CpuSet(&zero, state + 1, 0x05000002);
    state[0x34 / 4] = 0;
    zero2 = 0;
    CpuSet(&zero2, state + 0x38 / 4, 0x05000002);
}

/* Sets `flag` and returns 0 when bit (id - 0x100) of the bitfield at gMenuState+0x38 is set;
   returns 1 otherwise. */
// sub_080D3B58 @ 0x080D3B58
s32 sub_080D3B58(u16 id, u16 flag)
{
    struct FlagState *st = FLAG_STATE;
    u8 *bits = st->bits;
    u32 n = id - 0x100;

    if ((bits[n >> 3] >> (n & 7)) & 1)
    {
        Flag_Set(flag);
        return 0;
    }
    return 1;
}

/* After a script item check: sets the flag paired with the checked item (0x13D..0x14F) when its
   bit is set, and on result 1 switches every running sub_080DA5DC task to sub_080DA608. */
// sub_080D3B94 @ 0x080D3B94
void sub_080D3B94(void)
{
    s32 result = 1;
    struct Task *task;

    switch (gScriptItemCheckId)
    {
    case 0x13D:
        result = sub_080D3B58(0x117, 0x131);
        break;
    case 0x146:
        result = sub_080D3B58(0x11E, 0x13A);
        break;
    case 0x147:
        result = sub_080D3B58(0x10F, 0x13B);
        break;
    case 0x14A:
        result = sub_080D3B58(0x101, 0x13E);
        break;
    case 0x14B:
        result = sub_080D3B58(0x116, 0x13F);
        break;
    case 0x14D:
        result = sub_080D3B58(0x115, 0x141);
        break;
    case 0x14F:
        result = sub_080D3B58(0x11B, 0x143);
        break;
    }
    gYesNoResult = result;
    if (result == 1)
    {
        u32 i;
        for (i = 0; i < 64; i++)
        {
            task = &gTasks[i];
            if (task->state != 0 && task->onFrame == sub_080DA5DC)
                task->onFrame = sub_080DA608;
        }
    }
}

// sub_080D3CAC @ 0x080D3CAC
void sub_080D3CAC(void)
{
    gUnk_03003FEC = Task_Create(gUnknown_084F32B4, 0xFFFF);
}

// sub_080D3CCC @ 0x080D3CCC
u32 sub_080D3CCC(void)
{
    u32 done = 0;

    if (gUnk_03003FEC == NULL)
        done = 1;
    return done;
}

// sub_080D3CE4 @ 0x080D3CE4
u32 sub_080D3CE4(void)
{
    return gYesNoResult;
}

// sub_080D3CF0 @ 0x080D3CF0
void sub_080D3CF0(void)
{
    u32 *state = (u32 *)&gMenuState;
    u32 zero;
    u32 zero2;

    *state = 0x10570010;
    zero = 0;
    CpuSet(&zero, state + 1, 0x0500000A);
    state[0x34 / 4] = 0;
    zero2 = 0;
    CpuSet(&zero2, state + 0x38 / 4, 0x0500000A);
}

// sub_080D3D30 @ 0x080D3D30
void sub_080D3D30(void)
{
    Link_Exchange(0x2C, &gMenuState, (u8 *)&gMenuState + 0x34);
}

// sub_080D3D48 @ 0x080D3D48
void sub_080D3D48(void)
{
    u32 result = 1;
    struct FlagState *st = FLAG_STATE;
    u8 *bits = st->bits;
    u16 i = 0;
    const struct ComboEntry *e;
    u16 bit;

    Inventory_GetCount(0x11F);
    for (e = gUnknown_084F3754; e->id != -1; i++, e++)
    {
        if (Stock_FindByDemonId(e->items[0]))
            continue;
        if (e->items[1] != 0 && Stock_FindByDemonId(e->items[1]))
            continue;
        if (e->items[2] != 0 && Stock_FindByDemonId(e->items[2]))
            continue;
        if (e->bit == 0)
            continue;
        bit = e->bit;
        if ((bits[bit >> 3] >> (bit & 7)) & 1)
        {
            ComboBits_Set(i);
            result = 0;
            Flag_Set(0x162);
        }
    }
    gYesNoResult = result;
}

// sub_080D3DF0 @ 0x080D3DF0
void sub_080D3DF0(void)
{
    gUnk_03003FEC = Task_Create(gUnknown_084F3498, 0xFFFF);
}

// ComboBits_Clear @ 0x080D3E10
void ComboBits_Clear(void)
{
    gUnk_0203BB6C[3] = 0;
    gUnk_0203BB6C[2] = 0;
    gUnk_0203BB6C[1] = 0;
    gUnk_0203BB6C[0] = 0;
}

// ComboBits_Set @ 0x080D3E24
void ComboBits_Set(u16 i)
{
    gUnk_0203BB6C[i >> 3] |= 1 << (i & 7);
}

// ComboBits_Test @ 0x080D3E44
u32 ComboBits_Test(u16 i)
{
    return (gUnk_0203BB6C[i >> 3] >> (i & 7)) & 1;
}

// sub_080D3E64 @ 0x080D3E64
void sub_080D3E64(void)
{
    DmaSet3(gUnk_0200F874, (void *)0x06006000, 0x84000800);
    DmaSet3(gUnknown_081B5810, (void *)0x06012F00, 0x84000018);
}

// sub_080D3EA0 @ 0x080D3EA0
void sub_080D3EA0(void)
{
    DmaSet3(gUnk_02000800, (void *)0x06000000, 0x84000060);
    sub_080D3E64();
}

// sub_080D3EC8 @ 0x080D3EC8
void sub_080D3EC8(void)
{
    DMA3_FILL32(0, (void *)0x06000000, 0x85000060);
    DMA3_FILL32(0, (void *)0x06006000, 0x85000800);
}
