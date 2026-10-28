#include "global.h"
#include "menu2.h"

/* Prize list input: A takes the prize under the cursor (if sub_080C5B10 allows it), B cancels,
   up/down move by one row, L/R by a page. */
/* NONMATCHING: the L-button branch allocates cursor/temp in swapped registers. */
// CasinoPrize_HandleInput @ 0x080D38D0
#ifdef NONMATCHING
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
            sub_080C51D4(0x65);
            task->unk1E = 1;
            task->result = 1;
            gYesNoResult = blocked;
            gScriptItemCheckId = id;
            gUnk_0203DB2C = 10000;
        }
        else
            sub_080C51D4(0x66);
    }
    else if (gKeysNew & 2)
    {
        sub_080C51D4(0x66);
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
        sub_080C51D4(100);
    }
    else if (gRepeatedKeys & 0x80)
    {
        if (list->cursor != rows - 1)
            list->cursor++;
        else if (list->cursor == 5 && list->cursor + list->top + 1 <= count - 1)
            list->top++;
        else
            return;
        sub_080C51D4(100);
    }
    else if ((gRepeatedKeys & 0x200) && count > 6)
    {
        u16 cursor = list->cursor;
        u16 top = list->top;
        u32 v = cursor;
        if (v != 0)
            list->cursor = 0;
        else
        {
            if (top > 4)
                v = top - 5;
            list->top = v;
        }
        if (cursor != list->cursor || top != list->top)
            sub_080C51D4(100);
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
            sub_080C51D4(100);
    }
}
#else
NAKED
void CasinoPrize_HandleInput(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    adds r4, r0, #0\n"
        "    adds r2, r4, #0\n"
        "    adds r2, #0x24\n"
        "    ldr r0, .L080D392C\n"
        "    mov ip, r0\n"
        "    ldrh r5, [r2, #8]\n"
        "    movs r0, #0\n"
        "    strh r0, [r4, #0x1c]\n"
        "    strh r0, [r4, #0x1e]\n"
        "    adds r6, r5, #0\n"
        "    cmp r5, #5\n"
        "    bls .L080D38EC\n"
        "    movs r6, #6\n"
        ".L080D38EC:\n"
        "    ldr r3, .L080D3930\n"
        "    ldrh r1, [r3]\n"
        "    movs r7, #1\n"
        "    adds r0, r7, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080D394C\n"
        "    ldrh r0, [r2, #4]\n"
        "    ldrh r1, [r2, #6]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    add r0, ip\n"
        "    ldrh r6, [r0]\n"
        "    adds r0, r6, #0\n"
        "    bl sub_080C5B10\n"
        "    adds r5, r0, #0\n"
        "    cmp r5, #0\n"
        "    bne .L080D3944\n"
        "    movs r0, #0x65\n"
        "    bl sub_080C51D4\n"
        "    strh r7, [r4, #0x1e]\n"
        "    strh r7, [r4, #0x1c]\n"
        "    ldr r0, .L080D3934\n"
        "    str r5, [r0]\n"
        "    ldr r0, .L080D3938\n"
        "    strh r6, [r0]\n"
        "    ldr r1, .L080D393C\n"
        "    ldr r0, .L080D3940\n"
        "    str r0, [r1]\n"
        "    b .L080D3A42\n"
        ".L080D392C: .4byte 0x0203B454 @ EWRAM+0x3B454\n"
        ".L080D3930: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L080D3934: .4byte 0x030031CC @ IWRAM+0x31CC\n"
        ".L080D3938: .4byte 0x0203DB50 @ EWRAM+0x3DB50\n"
        ".L080D393C: .4byte 0x0203DB2C @ EWRAM+0x3DB2C\n"
        ".L080D3940: .4byte 0x00002710\n"
        ".L080D3944:\n"
        "    movs r0, #0x66\n"
        "    bl sub_080C51D4\n"
        "    b .L080D3A42\n"
        ".L080D394C:\n"
        "    ldrh r1, [r3]\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080D3970\n"
        "    movs r0, #0x66\n"
        "    bl sub_080C51D4\n"
        "    strh r7, [r4, #0x1c]\n"
        "    ldr r0, .L080D3968\n"
        "    strh r0, [r4, #0x1e]\n"
        "    ldr r0, .L080D396C\n"
        "    str r7, [r0]\n"
        "    b .L080D3A42\n"
        ".L080D3968: .4byte 0x0000FFFF\n"
        ".L080D396C: .4byte 0x030031CC @ IWRAM+0x31CC\n"
        ".L080D3970:\n"
        "    ldr r1, .L080D3988\n"
        "    ldrh r3, [r1]\n"
        "    movs r0, #0x40\n"
        "    ands r0, r3\n"
        "    cmp r0, #0\n"
        "    beq .L080D3998\n"
        "    ldrh r0, [r2, #4]\n"
        "    cmp r0, #0\n"
        "    beq .L080D398C\n"
        "    subs r0, #1\n"
        "    strh r0, [r2, #4]\n"
        "    b .L080D39F8\n"
        ".L080D3988: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L080D398C:\n"
        "    ldrh r0, [r2, #6]\n"
        "    cmp r0, #0\n"
        "    beq .L080D3A42\n"
        "    subs r0, #1\n"
        "    strh r0, [r2, #6]\n"
        "    b .L080D39F8\n"
        ".L080D3998:\n"
        "    movs r0, #0x80\n"
        "    ands r0, r3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #0\n"
        "    beq .L080D39C8\n"
        "    ldrh r1, [r2, #4]\n"
        "    subs r0, r6, #1\n"
        "    cmp r1, r0\n"
        "    beq .L080D39B2\n"
        "    adds r0, r1, #1\n"
        "    strh r0, [r2, #4]\n"
        "    b .L080D39F8\n"
        ".L080D39B2:\n"
        "    cmp r1, #5\n"
        "    bne .L080D3A42\n"
        "    ldrh r3, [r2, #6]\n"
        "    adds r0, r1, r3\n"
        "    adds r0, #1\n"
        "    subs r1, r5, #1\n"
        "    cmp r0, r1\n"
        "    bgt .L080D3A42\n"
        "    adds r0, r3, #1\n"
        "    strh r0, [r2, #6]\n"
        "    b .L080D39F8\n"
        ".L080D39C8:\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #2\n"
        "    ands r0, r3\n"
        "    cmp r0, #0\n"
        "    beq .L080D3A00\n"
        "    cmp r5, #6\n"
        "    bls .L080D3A00\n"
        "    ldrh r3, [r2, #4]\n"
        "    ldrh r1, [r2, #6]\n"
        "    adds r0, r3, #0\n"
        "    cmp r0, #0\n"
        "    beq .L080D39E4\n"
        "    strh r4, [r2, #4]\n"
        "    b .L080D39EC\n"
        ".L080D39E4:\n"
        "    cmp r1, #4\n"
        "    bls .L080D39EA\n"
        "    subs r0, r1, #5\n"
        ".L080D39EA:\n"
        "    strh r0, [r2, #6]\n"
        ".L080D39EC:\n"
        "    ldrh r0, [r2, #4]\n"
        "    cmp r3, r0\n"
        "    bne .L080D39F8\n"
        "    ldrh r2, [r2, #6]\n"
        "    cmp r1, r2\n"
        "    beq .L080D3A42\n"
        ".L080D39F8:\n"
        "    movs r0, #0x64\n"
        "    bl sub_080C51D4\n"
        "    b .L080D3A42\n"
        ".L080D3A00:\n"
        "    ldrh r1, [r1]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080D3A42\n"
        "    cmp r5, #6\n"
        "    bls .L080D3A42\n"
        "    ldrh r3, [r2, #4]\n"
        "    ldrh r4, [r2, #6]\n"
        "    cmp r3, #5\n"
        "    beq .L080D3A1E\n"
        "    movs r0, #5\n"
        "    strh r0, [r2, #4]\n"
        "    b .L080D3A30\n"
        ".L080D3A1E:\n"
        "    adds r0, r3, r4\n"
        "    adds r0, #6\n"
        "    subs r1, r5, #1\n"
        "    cmp r0, r1\n"
        "    bge .L080D3A2C\n"
        "    adds r0, r4, #6\n"
        "    b .L080D3A2E\n"
        ".L080D3A2C:\n"
        "    subs r0, r5, #6\n"
        ".L080D3A2E:\n"
        "    strh r0, [r2, #6]\n"
        ".L080D3A30:\n"
        "    ldrh r0, [r2, #4]\n"
        "    cmp r3, r0\n"
        "    bne .L080D3A3C\n"
        "    ldrh r2, [r2, #6]\n"
        "    cmp r4, r2\n"
        "    beq .L080D3A42\n"
        ".L080D3A3C:\n"
        "    movs r0, #0x64\n"
        "    bl sub_080C51D4\n"
        ".L080D3A42:\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

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

/* Sets `flag` when bit (id - 0x100) of the bitfield at gMenuState+0x38 is set. */
/* NONMATCHING: operands of the and are swapped (n & 7 computed into another register). */
// sub_080D3B58 @ 0x080D3B58
#ifdef NONMATCHING
s32 sub_080D3B58(u16 id, u16 flag)
{
    struct FlagState *st = FLAG_STATE;
    u8 *bits = st->bits;
    u32 n = id - 0x100;
    u32 bit;

    /* The original returns the bit index (garbage) when the bit is clear. */
    if ((bits[n >> 3] >> (bit = n & 7)) & 1)
    {
        Flag_Set(flag);
        bit = 0;
    }
    return bit;
}
#else
NAKED
s32 sub_080D3B58(u16 id, u16 flag)
{
    asm_unified(
        ".L080D3B58:\n"
        "    push {lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r3, r1, #0x10\n"
        "    ldr r2, .L080D3B8C\n"
        "    adds r2, #0x38\n"
        "    ldr r1, .L080D3B90\n"
        "    adds r0, r0, r1\n"
        "    lsrs r1, r0, #3\n"
        "    adds r1, r1, r2\n"
        "    ldrb r1, [r1]\n"
        "    movs r2, #7\n"
        "    ands r0, r2\n"
        "    asrs r1, r0\n"
        "    movs r0, #1\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080D3B86\n"
        "    adds r0, r3, #0\n"
        "    bl Flag_Set\n"
        "    movs r0, #0\n"
        ".L080D3B86:\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L080D3B8C: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L080D3B90: .4byte 0xFFFFFF00\n"
    );
}
#endif

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
    sub_080DF954(0x2C, &gMenuState, (u8 *)&gMenuState + 0x34);
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

    sub_080C32D4(0x11F);
    for (e = gUnknown_084F3754; e->id != -1; i++, e++)
    {
        if (sub_080C3560(e->items[0]))
            continue;
        if (e->items[1] != 0 && sub_080C3560(e->items[1]))
            continue;
        if (e->items[2] != 0 && sub_080C3560(e->items[2]))
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
