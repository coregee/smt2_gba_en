/* Battle menu: party slot selection, demon summon/return. */

#include "global.h"
#include "bmenu.h"

// sub_081298DC @ 0x081298DC
void sub_081298DC(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    u8 bad;

    task->pad1E = 0;
    task->result = 0;
    if (gKeysNew & 2)
    {
        task->pad1E = 0x100;
        task->result = 1;
        sub_080C8ADC(blk->unk4C, 0);
        sub_080ECF70(0x66);
    }
    else if (gKeysNew & 3)
    {
        bad = 0;
        task->pad1E = sub_080C8AF4(blk->unk4C);
        if (gGameState.order[task->pad1E] == -1)
        {
            if ((blk->unk694 & 1) && !sub_08129460())
                bad = 1;
            if (bad == 0)
            {
                task->result = 1;
                sub_080C8ADC(blk->unk4C, 0);
                sub_080ECF70(0x65);
                return;
            }
        }
        sub_080ECF70(0x66);
    }
    else if (gKeysNew & 0xF0)
    {
        sub_080ECF70(0x64);
    }
}

// sub_08129994 @ 0x08129994
void sub_08129994(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;

    task->result = 0;
    if (blk->unk694 == 0 && BattleMenu_BuildMemberList(7) != 0)
        task->result = 1;
}

// sub_081299C8 @ 0x081299C8
#ifdef NONMATCHING
void sub_081299C8(struct Task *task, u32 arg)
{
    struct C127Block *blk = C127_BLOCK;
    s32 slot = gGameState.order[task->pad1E];
    u8 m;
    u16 r;

    switch (blk->unk694)
    {
    case 0:
        if (slot != -1)
            Party_Remove(slot, 0);
        m = blk->unk692;
        Money_Add(-sub_0812839C(m));
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(0xE9), m));
        Party_AddAt(m, task->pad1E);
        Party_FixFormation();
        Party_BuildMemberNameTiles();
        sub_080C6FD8();
        r = 1;
        break;
    case 1:
    case 3:
    case 7:
        m = blk->unk692;
        blk->unkEF0[gGameState.order[blk->unkF66]] = m;
        blk->unkF10[gGameState.order[blk->unkF66]] = task->pad1E;
        task->pad1E = 0;
        goto done;
    case 2:
        if (slot != -1)
            Party_Remove(slot, 0);
        m = blk->unk692;
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(0xE9), m));
        Party_AddAt(m, task->pad1E);
        Party_FixFormation();
        Party_BuildMemberNameTiles();
        sub_080C6FD8();
        r = 1;
        break;
    default:
        r = 0;
        break;
    }
    task->pad1E = r;
done:
    if (arg == 0)
        blk->unk48->data.raw[0] = 1;
}
#else
NAKED
void sub_081299C8(struct Task *task, u32 arg)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    adds r6, r0, #0\n"
        "    mov r8, r1\n"
        "    ldr r7, .L081299FC\n"
        "    ldr r0, .L08129A00\n"
        "    movs r2, #0xa2\n"
        "    lsls r2, r2, #4\n"
        "    adds r1, r0, r2\n"
        "    ldrh r4, [r6, #0x1e]\n"
        "    adds r1, r1, r4\n"
        "    movs r3, #0\n"
        "    ldrsb r3, [r1, r3]\n"
        "    ldr r2, .L08129A04\n"
        "    adds r1, r7, r2\n"
        "    ldrb r1, [r1]\n"
        "    adds r2, r0, #0\n"
        "    cmp r1, #7\n"
        "    bls .L081299F2\n"
        "    b .L08129B18\n"
        ".L081299F2:\n"
        "    lsls r0, r1, #2\n"
        "    ldr r1, .L08129A08\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        ".L081299FC: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L08129A00: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L08129A04: .4byte 0x00000694\n"
        ".L08129A08: .4byte gUnknown_08129A0C\n"
        "    .global gUnknown_08129A0C\n"
        "gUnknown_08129A0C:\n"
        ".L08129A0C: @ jump table\n"
        "    .4byte .L08129A2C\n"
        "    .4byte .L08129A80\n"
        "    .4byte .L08129AD0\n"
        "    .4byte .L08129A80\n"
        "    .4byte .L08129B18\n"
        "    .4byte .L08129B18\n"
        "    .4byte .L08129B18\n"
        "    .4byte .L08129A80\n"
        ".L08129A2C:\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r3, r0\n"
        "    beq .L08129A3E\n"
        "    lsls r0, r3, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    movs r1, #0\n"
        "    bl Party_Remove\n"
        ".L08129A3E:\n"
        "    ldr r4, .L08129A7C\n"
        "    adds r0, r7, r4\n"
        "    ldrb r5, [r0]\n"
        "    adds r0, r5, #0\n"
        "    bl sub_0812839C\n"
        "    rsbs r0, r0, #0\n"
        "    bl Money_Add\n"
        "    movs r0, #0xe9\n"
        "    bl Battle_GetMessage\n"
        "    adds r1, r5, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetMode\n"
        "    ldrh r1, [r6, #0x1e]\n"
        "    adds r0, r5, #0\n"
        "    bl Party_AddAt\n"
        "    bl Party_FixFormation\n"
        "    bl Party_BuildMemberNameTiles\n"
        "    bl sub_080C6FD8\n"
        "    movs r0, #1\n"
        "    b .L08129B1A\n"
        ".L08129A7C: .4byte 0x00000692\n"
        ".L08129A80:\n"
        "    ldr r1, .L08129AC8\n"
        "    adds r0, r7, r1\n"
        "    ldrb r5, [r0]\n"
        "    ldr r4, .L08129ACC\n"
        "    adds r3, r7, r4\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r3, r1]\n"
        "    movs r4, #0xa2\n"
        "    lsls r4, r4, #4\n"
        "    adds r2, r2, r4\n"
        "    adds r0, r0, r2\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    lsls r0, r0, #1\n"
        "    movs r4, #0xef\n"
        "    lsls r4, r4, #4\n"
        "    adds r1, r7, r4\n"
        "    adds r1, r1, r0\n"
        "    movs r4, #0\n"
        "    strh r5, [r1]\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r3, r1]\n"
        "    adds r0, r0, r2\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    lsls r0, r0, #1\n"
        "    movs r2, #0xf1\n"
        "    lsls r2, r2, #4\n"
        "    adds r1, r7, r2\n"
        "    adds r1, r1, r0\n"
        "    ldrh r0, [r6, #0x1e]\n"
        "    strh r0, [r1]\n"
        "    strh r4, [r6, #0x1e]\n"
        "    b .L08129B1C\n"
        ".L08129AC8: .4byte 0x00000692\n"
        ".L08129ACC: .4byte 0x00000F66\n"
        ".L08129AD0:\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r3, r0\n"
        "    beq .L08129AE2\n"
        "    lsls r0, r3, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    movs r1, #0\n"
        "    bl Party_Remove\n"
        ".L08129AE2:\n"
        "    ldr r4, .L08129B14\n"
        "    adds r0, r7, r4\n"
        "    ldrb r5, [r0]\n"
        "    movs r0, #0xe9\n"
        "    bl Battle_GetMessage\n"
        "    adds r1, r5, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetMode\n"
        "    ldrh r1, [r6, #0x1e]\n"
        "    adds r0, r5, #0\n"
        "    bl Party_AddAt\n"
        "    bl Party_FixFormation\n"
        "    bl Party_BuildMemberNameTiles\n"
        "    bl sub_080C6FD8\n"
        "    movs r0, #1\n"
        "    b .L08129B1A\n"
        ".L08129B14: .4byte 0x00000692\n"
        ".L08129B18:\n"
        "    movs r0, #0\n"
        ".L08129B1A:\n"
        "    strh r0, [r6, #0x1e]\n"
        ".L08129B1C:\n"
        "    mov r0, r8\n"
        "    cmp r0, #0\n"
        "    bne .L08129B2A\n"
        "    ldr r0, [r7, #0x48]\n"
        "    adds r0, #0x24\n"
        "    movs r1, #1\n"
        "    strb r1, [r0]\n"
        ".L08129B2A:\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

// sub_08129B34 @ 0x08129B34
void sub_08129B34(struct Task *task, const u16 *msg)
{
    BattleMenu_SetMode(3, msg);
}

// sub_08129B40 @ 0x08129B40
void sub_08129B40(struct Task *task, const u16 *tmpl)
{
    BattleMenu_SetMode(3, Menu_ExpandListTemplate(tmpl, 0));
}

// sub_08129B58 @ 0x08129B58
void sub_08129B58(struct Task *task, u16 id)
{
    BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(id), 0));
}

// sub_08129B74 @ 0x08129B74
void sub_08129B74(struct Task *task, u32 arg)
{
    struct C127Block *blk = C127_BLOCK;
    u16 n = BattleMenu_BuildMemberList(3);

    if (n == 0)
    {
        BattleMenu_SetMode(3, gUnknown_081240F0);
        task->pad1E = 1;
        if (arg == 0)
            blk->unk48->data.raw[0] = 0xFF;
    }
    else
    {
        blk->unk4C = TextWindow_Create(1, 0, 0xF, 0xA, 1);
        blk->unk50 = TextWindow_Create(0x11, 0, 0xC, 6, 1);
        sub_081272AC();
        sub_08126928(4, 0, 1, n, n);
        BattleMenu_SetMode(4, Menu_ExpandListTemplate(Battle_GetMessage(0x6A), 0));
    }
}

// sub_08129C00 @ 0x08129C00
void sub_08129C00(void)
{
    struct MenuCursor *c = sub_08126D1C(4);

    BattleMenu_DrawListPage(3, c->top);
    sub_081283C4(3, c->index);
}

// sub_08129C20 @ 0x08129C20
void sub_08129C20(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct MenuCursor *c = sub_08126D1C(4);
    u32 old = (u8)c->index;
    u16 v;
    u8 i;

    sub_08126A08(4);
    task->pad1E = 0;
    task->result = 0;
    if (gKeysNew & 2)
    {
        task->pad1E = 0x100;
        task->result = 1;
        sub_080ECF70(0x66);
        sub_081269B0(4);
    }
    else if (c->state == 3)
    {
        v = blk->list[c->index];
        for (i = 0; i < 6 && gGameState.order[i] != v; i++)
            ;
        task->pad1E = i;
        task->result = 1;
        sub_080ECF70(0x65);
        sub_081269B0(4);
    }
    Sprite_Draw(gUnknown_08000EA4, 0, 0, 1, 0, 0xC, c->onScreen * 13 + 6);
    if ((u16)old != c->index)
    {
        BattleMenu_DrawListPage(3, c->top);
        sub_081283C4(3, c->index);
    }
}
