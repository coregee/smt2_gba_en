/* Battle command menu (top level and submenus): task callbacks. */

#include "global.h"
#include "bmenu.h"

// sub_08128C28 @ 0x08128C28
void sub_08128C28(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct MenuCursor *c = sub_08126D1C(0);
    u16 column = c->column;

    sub_08126A08(0);
    task->result = 0;
    if (c->state == 4)
    {
        task->result = 1;
        sub_08128E28();
    }
    else if (c->state == 3)
    {
        switch (c->column)
        {
        case 0:
            sub_08128EB4();
            blk->unk696 = 0;
            task->result = 1;
            sub_08128E80();
            break;
        case 1:
            sub_0812C0D0();
            task->result = 1;
            sub_08128E80();
            break;
        case 2:
            sub_0812AD70();
            task->result = 1;
            sub_08128E80();
            break;
        case 3:
            sub_080CE258(0, 0);
            task->result = 1;
            sub_08128E80();
            break;
        case 4:
            sub_0812CC70(0);
            task->result = 1;
            sub_08128E80();
            break;
        case 5:
            sub_0812CE78();
            task->result = 1;
            sub_08128E80();
            break;
        }
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
            sub_080EA2AC();
            BattleMenu_SetMode(4, gUnknown_08777EA0[c->column]);
        }
    }
    else if (column != c->column && blk->unk7E0 == 4)
    {
        BattleMenu_SetMode(4, gUnknown_08777EA0[c->column]);
    }
    Sprite_Draw(gUnknown_08000868, 0, 0, 0, 0, gUnknown_08777E94[c->column], 0x5B);
}

// sub_08128D54 @ 0x08128D54
void sub_08128D54(void)
{
    u8 unused[0x28];  /* never used; the original frame has it */

    sub_08126E4C(0, 0);
    sub_08126928(0, 1, 6, 1, 1);
    gUnk_03000030 = 0xF0;
    gUnk_03000031 = 0;
    gUnk_03000035 = 0x5E;
    gUnk_03000034 = 0x68;
    gUnk_03000038 = 0x1D;
    gUnk_03000032 = 0xF0;
    gUnk_03000033 = 0;
    gUnk_03000037 = 0x5E;
    gUnk_03000036 = 0x68;
    gUnk_03000039 = 0x1F;
    gUnk_0300003A = 0x3F;
}

/* Opens window 0 horizontally by 8 pixels a frame. */
// sub_08128DE0 @ 0x08128DE0
void sub_08128DE0(struct Task *task)
{
    task->result = 0;
    gUnk_03000031 += 8;
    gUnk_03000030 -= 8;
    if (gUnk_03000031 > 0x77)
    {
        gUnk_03000031 = gUnk_03000030 = 0xF0;
        gUnk_03000038 = 0x1F;
        task->result = 1;
        sub_080ECF70(0x67);
    }
}

// sub_08128E28 @ 0x08128E28
void sub_08128E28(void)
{
    struct C127Block *blk = C127_BLOCK;

    sub_081269B0(0);
    sub_08126F4C();
    if (blk->unk7E0 == 4)
        BattleMsg_Close();
    sub_081279D4();
    if (gFieldState.state == 0x1B)
    {
        Field_SetState(0x1E);
        gFieldState.unk1E = 0;
    }
    else
    {
        Field_SetState(1);
    }
    sub_080C7234();
    sub_080C762C();
    sub_080C7C94();
}

// sub_08128E80 @ 0x08128E80
void sub_08128E80(void)
{
    struct C127Block *blk = C127_BLOCK;

    sub_08126F4C();
    if (blk->unk7E0 == 4)
        BattleMsg_Close();
    sub_081279D4();
    sub_080C6FF0();
    sub_080C7414();
    sub_080C762C();
}

// sub_08128EB4 @ 0x08128EB4
void sub_08128EB4(void)
{
    struct C127Block *blk = C127_BLOCK;
    s32 msg = sub_080F3190();

    if (msg != 0)
    {
        if (blk->unk7E0 == 4)
        {
            BattleMenu_Reset();
            BattleMsg_Close();
        }
        blk->unk44 = Task_Create(gUnknown_0877812C, 0xFFFF);
        sub_080EA210();
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(msg), 0));
        Sound_Play(0x68);
    }
    else
    {
        blk->unk44 = Task_Create(gUnknown_08778000, 0xFFFF);
    }
}

// sub_08128F28 @ 0x08128F28
void sub_08128F28(void)
{
    DmaSet3Wait(gUnk_030000B4, 0x06015000, 0x84000180);
}

// sub_08128F60 @ 0x08128F60
void sub_08128F60(void)
{
    struct C127Block *blk = C127_BLOCK;
    u8 n = 0;
    u16 *p;

    Hud_RenderGlyphTiles(gUnk_030000B4, gUnknown_08777F2C);
    VBlankTask_AddCounted(sub_08128F28, 1);
    p = blk->list;
    if (Flag_Test(3))
    {
        *p++ = n;
        n = 1;
        *p++ = n;
        n = 2;
        *p++ = n;
        n = 3;
    }
    *p++ = 3;
    n++;
    *p++ = 4;
    n++;
    if (Flag_Test(0xE5))
    {
        *p++ = 5;
        n++;
    }
    *p = 0xFFFF;
    if (n == 2)
        blk->unk4C = TextWindow_Create(10, 1, 10, 5, 1);
    else
        blk->unk4C = TextWindow_Create(10, 1, 10, n + 4, 1);
    sub_08126928(1, 1, 1, n, n);
    blk->unk44->data.raw[0] = n;
}

// sub_08129030 @ 0x08129030
void sub_08129030(struct Task *task, u32 mode)
{
    struct Task *w = (struct Task *)C127_BLOCK->unk4C;
    u16 *d = w->data.h;

    task->result = 0;
    switch (mode)
    {
    case 0:
        if (w->pad1E != 0xFF)
            task->result = 1;
        break;
    case 1:
        if (d[5] == 2)
            task->result = mode;
        break;
    case 2:
        break;
    }
}

// sub_08129068 @ 0x08129068
#ifdef NONMATCHING
void sub_08129068(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    u32 top = 12;
    u8 n = blk->unk44->data.raw[0];
    struct MenuCursor *c;
    u8 row, changed;
    u8 i, j;
    u16 v;
    s32 y;

    if (n == 2)
        top = 14;
    if (n == 6)
        top = 10;
    c = sub_08126D1C(1);
    row = c->row;
    sub_08126A08(1);
    changed = (c->row ^ row) != 0;
    task->pad1E = 0;
    task->result = 0;
    if (gKeysNew & 2)
    {
        task->pad1E = 0xFF;
        task->result = 1;
    }
    else if (gKeysNew & 1)
    {
        task->pad1E = blk->list[c->row];
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
            BattleMenu_SetMode(4, gUnknown_08777FE0[blk->list[c->row]]);
        }
    }
    if (changed == 1 && blk->unk7E0 == 4)
        BattleMenu_SetMode(4, gUnknown_08777FE0[blk->list[c->row]]);
    Sprite_Draw(gUnknown_08000E58, 0, 0, 0, 0, 0x58, top + c->row * 12);
    j = 0;
    i = 0;
    while (1)
    {
        v = blk->list[i];
        if (v == 0xFFFF)
            break;
        y = top + (j * 12 + 4);
        Sprite_DrawSingle(gUnknown_08777F60[v], 0, 0, 0, 0, 0x5C, y);
        Sprite_DrawSingle(gUnknown_08777F68[v], 0, 0, 0, 0, 0x7C, y);
        j++;
        i++;
        if (i >= 6)
            break;
    }
}
#else
NAKED
void sub_08129068(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x10\n"
        "    adds r4, r0, #0\n"
        "    ldr r0, .L081290CC\n"
        "    mov r8, r0\n"
        "    movs r1, #0xc\n"
        "    str r1, [sp, #0xc]\n"
        "    ldr r0, [r0, #0x44]\n"
        "    adds r0, #0x24\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #2\n"
        "    bne .L0812908C\n"
        "    movs r2, #0xe\n"
        "    str r2, [sp, #0xc]\n"
        ".L0812908C:\n"
        "    cmp r0, #6\n"
        "    bne .L08129094\n"
        "    movs r0, #0xa\n"
        "    str r0, [sp, #0xc]\n"
        ".L08129094:\n"
        "    movs r0, #1\n"
        "    bl sub_08126D1C\n"
        "    adds r5, r0, #0\n"
        "    ldrb r6, [r5, #0x18]\n"
        "    movs r0, #1\n"
        "    bl sub_08126A08\n"
        "    ldrh r1, [r5, #0x18]\n"
        "    eors r1, r6\n"
        "    rsbs r0, r1, #0\n"
        "    orrs r0, r1\n"
        "    lsrs r6, r0, #0x1f\n"
        "    movs r0, #0\n"
        "    strh r0, [r4, #0x1e]\n"
        "    strh r0, [r4, #0x1c]\n"
        "    ldr r2, .L081290D0\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L081290D4\n"
        "    movs r0, #0xff\n"
        "    strh r0, [r4, #0x1e]\n"
        "    movs r0, #1\n"
        "    strh r0, [r4, #0x1c]\n"
        "    b .L08129130\n"
        "    .byte 0x00, 0x00\n"
        ".L081290CC: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L081290D0: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L081290D4:\n"
        "    ldrh r1, [r2]\n"
        "    movs r2, #1\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L081290F4\n"
        "    ldrh r0, [r5, #0x18]\n"
        "    lsls r0, r0, #1\n"
        "    movs r1, #0xb4\n"
        "    lsls r1, r1, #2\n"
        "    add r1, r8\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r4, #0x1e]\n"
        "    strh r2, [r4, #0x1c]\n"
        "    b .L08129130\n"
        ".L081290F4:\n"
        "    ldrb r0, [r5]\n"
        "    cmp r0, #6\n"
        "    bne .L08129130\n"
        "    movs r0, #0xfc\n"
        "    lsls r0, r0, #3\n"
        "    add r0, r8\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #4\n"
        "    bne .L08129110\n"
        "    bl BattleMenu_Reset\n"
        "    bl BattleMsg_Close\n"
        "    b .L08129130\n"
        ".L08129110:\n"
        "    bl sub_080EA210\n"
        "    ldr r2, .L08129200\n"
        "    ldrh r0, [r5, #0x18]\n"
        "    lsls r0, r0, #1\n"
        "    movs r1, #0xb4\n"
        "    lsls r1, r1, #2\n"
        "    add r1, r8\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r0, r2\n"
        "    ldr r1, [r0]\n"
        "    movs r0, #4\n"
        "    bl BattleMenu_SetMode\n"
        ".L08129130:\n"
        "    cmp r6, #1\n"
        "    bne .L0812915C\n"
        "    movs r0, #0xfc\n"
        "    lsls r0, r0, #3\n"
        "    add r0, r8\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #4\n"
        "    bne .L0812915C\n"
        "    ldr r2, .L08129200\n"
        "    ldrh r1, [r5, #0x18]\n"
        "    lsls r1, r1, #1\n"
        "    movs r0, #0xb4\n"
        "    lsls r0, r0, #2\n"
        "    add r0, r8\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r0, r2\n"
        "    ldr r1, [r0]\n"
        "    movs r0, #4\n"
        "    bl BattleMenu_SetMode\n"
        ".L0812915C:\n"
        "    ldr r0, .L08129204\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    movs r1, #0x58\n"
        "    str r1, [sp, #4]\n"
        "    ldrh r2, [r5, #0x18]\n"
        "    lsls r1, r2, #1\n"
        "    adds r1, r1, r2\n"
        "    lsls r1, r1, #2\n"
        "    ldr r2, [sp, #0xc]\n"
        "    adds r1, r2, r1\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    movs r7, #0\n"
        "    movs r6, #0\n"
        "    ldr r0, .L08129208\n"
        "    mov sl, r0\n"
        "    mov sb, r6\n"
        ".L0812918C:\n"
        "    lsls r1, r6, #1\n"
        "    movs r0, #0xb4\n"
        "    lsls r0, r0, #2\n"
        "    add r0, r8\n"
        "    adds r0, r0, r1\n"
        "    ldrh r5, [r0]\n"
        "    ldr r1, .L0812920C\n"
        "    cmp r5, r1\n"
        "    beq .L081291EE\n"
        "    lsls r5, r5, #4\n"
        "    mov r2, sl\n"
        "    adds r0, r5, r2\n"
        "    mov r1, sb\n"
        "    str r1, [sp]\n"
        "    movs r1, #0x5c\n"
        "    str r1, [sp, #4]\n"
        "    lsls r4, r7, #1\n"
        "    adds r4, r4, r7\n"
        "    lsls r4, r4, #2\n"
        "    adds r4, #4\n"
        "    ldr r2, [sp, #0xc]\n"
        "    adds r4, r2, r4\n"
        "    str r4, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_DrawSingle\n"
        "    ldr r0, .L08129210\n"
        "    adds r5, r5, r0\n"
        "    mov r1, sb\n"
        "    str r1, [sp]\n"
        "    movs r0, #0x7c\n"
        "    str r0, [sp, #4]\n"
        "    str r4, [sp, #8]\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_DrawSingle\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r7, r0, #0x18\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r6, r0, #0x18\n"
        "    cmp r6, #5\n"
        "    bls .L0812918C\n"
        ".L081291EE:\n"
        "    add sp, #0x10\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L08129200: .4byte gUnknown_08777FE0\n"
        ".L08129204: .4byte gUnknown_08000E58\n"
        ".L08129208: .4byte gUnknown_08777F60\n"
        ".L0812920C: .4byte 0x0000FFFF\n"
        ".L08129210: .4byte gUnknown_08777F68\n"
    );
}
#endif

// sub_08129214 @ 0x08129214
void sub_08129214(struct Task *task, u32 value)
{
    if (task->pad1E == value)
        task->result = 1;
    else
        task->result = 0;
}

// sub_0812922C @ 0x0812922C
void sub_0812922C(void)
{
    struct C127Block *blk = C127_BLOCK;

    if (blk->unk696 == 0)
    {
        sub_08128B84(1);
    }
    else
    {
        if (blk->unk7E0 == 4)
            BattleMsg_Close();
        sub_081279D4();
        if (gFieldState.state == 0x1B)
        {
            Field_SetState(0x1E);
            gFieldState.unk1E = 0;
        }
        else
        {
            Field_SetState(1);
        }
        sub_080C7234();
        sub_080C762C();
        sub_080C7C94();
    }
    sub_081269B0(1);
}

// sub_08129298 @ 0x08129298
void sub_08129298(void)
{
    struct C127Block *blk = C127_BLOCK;

    BattleMsg_Close();
    if (blk->unk696 == 0)
    {
        sub_08128B84(1);
    }
    else
    {
        sub_081279D4();
        if (gFieldState.state == 0x1B)
        {
            Field_SetState(0x1E);
            gFieldState.unk1E = 0;
        }
        else
        {
            Field_SetState(1);
        }
    }
    sub_081269B0(1);
}

// sub_081292EC @ 0x081292EC
void sub_081292EC(void)
{
    struct C127Block *blk = C127_BLOCK;

    if (blk->unk4C != 0)
        TextWindow_Close(blk->unk4C, 0);
    if (blk->unk7E0 == 4)
        BattleMsg_Close();
    sub_08128388();
}

// sub_0812931C @ 0x0812931C
void sub_0812931C(void)
{
    struct C127Block *blk = C127_BLOCK;
    u16 i;

    for (i = 0; i < 16; i++)
    {
        blk->unkEF0[i] |= -1;
        blk->unkF10[i] |= -1;
    }
}

// sub_0812935C @ 0x0812935C
void sub_0812935C(struct Task *task)
{
    switch (task->pad1E)
    {
    case 0:
        sub_0812931C();
        sub_081293F8(0);
        break;
    case 1:
        sub_08129D58();
        break;
    case 2:
        sub_08129FDC();
        break;
    case 3:
        if (gGameState.unkAC0 == 0)
        {
            sub_080AD6E4(1);
        }
        else
        {
            sub_080EA210();
            BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(0x5B), 0));
            task->pad1E = 0x100;
        }
        break;
    case 4:
        sub_0812E734();
        break;
    case 5:
        sub_0812A6F0();
        break;
    }
    sub_081269B0(1);
}

// sub_081293F8 @ 0x081293F8
void sub_081293F8(u8 mode)
{
    struct C127Block *blk = C127_BLOCK;
    u8 low = mode & 1;

    blk->unk48 = Task_Create(gUnknown_08778160, 0xFFFF);
    blk->unk694 = mode;
    if (low == 1)
    {
    }
    else if (low == 0)
    {
        sub_080EA210();
    }
    blk->unk48->data.raw[0] = 0;
}

// sub_08129440 @ 0x08129440
u8 sub_08129440(void)
{
    struct Task *t = C127_BLOCK->unk48;

    u8 r;

    if (t->state != 0)
        r = 0;
    else
        r = t->data.raw[0];
    return r;
}

/* TRUE when the party has room: members in use plus the 0xEF0 list stay within 5. */
// sub_08129460 @ 0x08129460
bool32 sub_08129460(void)
{
    struct C127Block *blk = C127_BLOCK;
    u16 n = Party_CountMembers();
    u16 cnt = 0;
    u16 i;

    if (n > 5)
        return FALSE;
    for (i = 0; i < 16; i++)
    {
        if (blk->unkEF0[i] != -1)
            cnt++;
    }
    if (n + cnt > 5)
        return FALSE;
    return TRUE;
}
