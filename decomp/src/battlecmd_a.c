/* Battle sprite uploads and the battle command menu. */

#include "global.h"
#include "battledisp.h"

// sub_080E5940 @ 0x080E5940
#ifdef NONMATCHING
void sub_080E5940(void)
{
    DmaSet(3, gUnk_02001000, (void *)0x06016000, 0x84000400);
    DmaSet3Wait(gUnk_02001000 + 0x2000, (void *)0x06017000, 0x84000400);
}
#else
NAKED
void sub_080E5940(void)
{
    asm_unified(
        "    push {lr}\n"
        "    ldr r0, .L080E597C\n"
        "    ldr r2, .L080E5980\n"
        "    str r2, [r0]\n"
        "    ldr r1, .L080E5984\n"
        "    str r1, [r0, #4]\n"
        "    ldr r3, .L080E5988\n"
        "    str r3, [r0, #8]\n"
        "    ldr r1, [r0, #8]\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #6\n"
        "    adds r2, r2, r1\n"
        "    str r2, [r0]\n"
        "    ldr r1, .L080E598C\n"
        "    str r1, [r0, #4]\n"
        "    str r3, [r0, #8]\n"
        "    ldr r1, [r0, #8]\n"
        "    adds r2, r0, #0\n"
        "    ldr r0, [r2, #8]\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #0x18\n"
        "    cmp r0, #0\n"
        "    bge .L080E5976\n"
        ".L080E596E:\n"
        "    ldr r0, [r2, #8]\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L080E596E\n"
        ".L080E5976:\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080E597C: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080E5980: .4byte 0x02001000 @ EWRAM+0x1000\n"
        ".L080E5984: .4byte 0x06016000 @ VRAM+0x16000\n"
        ".L080E5988: .4byte 0x84000400\n"
        ".L080E598C: .4byte 0x06017000 @ VRAM+0x17000\n"
    );
}
#endif

// sub_080E5990 @ 0x080E5990
void sub_080E5990(void)
{
    DmaSet3Wait(gUnk_02001000, (void *)0x06016000, 0x84000800);
}

// sub_080E59C8 @ 0x080E59C8
/* Queues the OBJ upload of enemy group 0: both halves when the demon has a second one. */
void sub_080E59C8(u32 unused, u32 group)
{
    struct C15cBattle *b = BB;
    u16 id = b->groups[group];

    if (id != 0xFFFF && group == 0)
    {
        if (Demon_GetGfxRecord(id)->gfx[1][0] != NULL)
            VBlankTask_AddCounted(sub_080E5990, 1);
        else
            VBlankTask_AddCounted(sub_080E5940, 1);
    }
}

// sub_080E5A18 @ 0x080E5A18
void sub_080E5A18(u16 substate)
{
    struct C15cBattle *b = BB;

    gUnk_03000058 = b->substate;
    b->substate = substate;
}

// sub_080E5A3C @ 0x080E5A3C
void sub_080E5A3C(void)
{
    struct C15cBattle *b = BB;

    b->substate = gUnk_03000058;
}

// sub_080E5A58 @ 0x080E5A58
/* Opens the battle command menu for the acting party member (mode 1) or the auto-battle
   menu (mode 2). Bits of `flags` grey out commands: 1 no weapon, 2 no gun/ammo, 4 no
   COMP/summon, 8 no items. */
void sub_080E5A58(u32 unused, u32 mode)
{
    struct C15cBattle *b = BB;
    struct C15cGameState *gs = (struct C15cGameState *)gGameState;
    s32 who;
    u8 menu;
    u8 flags;

    switch (mode)
    {
    case 1:
        who = (u8)gs->order[b->unkF66];
        if (!sub_080F3040(who))
        {
            b->substate = 3;
            return;
        }
        switch (who)
        {
        case 0:
            menu = 2;
            flags = 0;
            if (Combatant_GetEquip(0, 0) == 0xFF)
                flags = 1;
            if (Combatant_GetEquip(0, 1) == 0xFF || Combatant_GetEquip(0, 6) == 0xFF)
                flags |= 2;
            if (!Flag_Test(3) || sub_080F3190())
                flags |= 4;
            if (!sub_0812B3A4(1))
                flags |= 8;
            break;
        case 1:
        case 2:
        case 3:
            menu = 3;
            flags = 0;
            if (Combatant_GetEquip(who, 0) == 0xFF)
                flags = 1;
            if (Combatant_GetEquip(who, 1) == 0xFF || Combatant_GetEquip(who, 6) == 0xFF)
                flags |= 2;
            if (sub_080F4410(who) != 2 || sub_080F31E0())
                flags |= 4;
            if (!sub_0812B3A4(1))
                flags |= 8;
            break;
        default:
            menu = 4;
            flags = 0;
            if (!BattleMenu_BuildSkillList(2, who))
                flags = 2;
            if (sub_080F4410(who) != 2 || sub_080F31E0())
                flags |= 4;
            break;
        }
        sub_08126D50(menu, flags);
        b->unk1121 = flags;
        sub_080C7AE0();
        break;
    case 2:
        menu = 5;
        flags = 0;
        sub_08126D50(5, 0);
        b->unk1121 = flags;
        sub_080C7AE0();
        break;
    default:
        return;
    }
    b->unk693 = menu;
    gUnk_03000030 = 0xF0;
    gUnk_03000031 = 0xB0;
    gUnk_03000035 = 0x18;
    gUnk_03000034 = 0x58;
    gUnk_03000038 = 0x1F;
    gUnk_0300003A = 0x3F;
}

// sub_080E5BFC @ 0x080E5BFC
/* Opens the four-row battle command cursor. */
void sub_080E5BFC(void)
{
    struct C15cBattle *b = BB;
    struct MenuCursor c;

    sub_08126D50(1, 0);
    sub_080C7AE0();
    sub_08126870();
    CpuFill32(0, &c, sizeof(c));
    c.state = 1;
    c.delay = 0;
    c.mode = 0;
    c.flags = 1;
    c.columns = 1;
    c.rows = 4;
    c.count = 4;
    c.top = 0;
    c.onScreen = 0;
    c.perColumn = 4;
    c.index = 0;
    c.unk14 = 0;
    c.column = 0;
    c.row = 0;
    c.seMove = c.sePage = 0x64;
    c.seA = 0x65;
    c.seB = 0x66;
    c.seLR = c.seStart = c.seSelect = 0xFFFF;
    sub_081268E4(0, &c);
    gUnk_03000030 = 0xF0;
    gUnk_03000031 = 0xB0;
    gUnk_03000035 = 0x18;
    gUnk_03000034 = 0x58;
    gUnk_03000038 = 0x1F;
    gUnk_0300003A = 0x3F;
    b->unk690 = 0xFF;
}

// sub_080E5CC4 @ 0x080E5CC4
/* Opens the menu window horizontally, 8 pixels a frame. */
void sub_080E5CC4(struct Task *t)
{
    t->result = 0;
    gUnk_03000031 += 8;
    gUnk_03000030 -= 8;
    if (gUnk_03000031 >= 0x78)
    {
        gUnk_03000038 = 0x1F;
        t->result = 1;
        sub_080ECF70(0x67);
    }
}

// sub_080E5D04 @ 0x080E5D04
void sub_080E5D04(struct Task *t)
{
    t->result = 0;
    gUnk_03000034 -= 2;
    if (gUnk_03000034 <= 0x48)
    {
        gUnk_03000038 = 0x1F;
        gUnk_03000034 = 0x58;
        t->result = 1;
    }
}

// sub_080E5D38 @ 0x080E5D38
void sub_080E5D38(void)
{
    sub_080C7ACC();
    gUnk_03000030 = 0xF0;
    gUnk_03000031 = 0xF0;
    gUnk_03000034 = 0x48;
    gUnk_03000035 = 0x48;
}

// sub_080E5D68 @ 0x080E5D68
void sub_080E5D68(struct Task *t)
{
    t->result = 0;
    gUnk_03000034 += 8;
    if (gUnk_03000034 >= 0x58)
    {
        gUnk_03000038 = 0x3F;
        sub_08126F14();
        gUnk_03000034 = 0x58;
        t->result = 1;
    }
}

// sub_080E5DA0 @ 0x080E5DA0
#ifdef NONMATCHING
void sub_080E5DA0(void)
{
    struct C15cBattle *b = BB;
    u32 i;

    for (i = 0; i < 16; i++)
    {
        b->unkEF0[i] |= 0xFFFF;
        b->unkF10[i] |= 0xFFFF;
    }
}
#else
NAKED
void sub_080E5DA0(void)
{
    asm_unified(
        ".L080E5DA0:\n"
        "    push {r4, lr}\n"
        "    ldr r0, .L080E5DCC\n"
        "    movs r2, #0\n"
        "    ldr r1, .L080E5DD0\n"
        "    adds r3, r1, #0\n"
        "    movs r4, #0xef\n"
        "    lsls r4, r4, #4\n"
        "    adds r1, r0, r4\n"
        ".L080E5DB0:\n"
        "    ldrh r0, [r1]\n"
        "    orrs r0, r3\n"
        "    strh r0, [r1]\n"
        "    ldrh r0, [r1, #0x20]\n"
        "    orrs r0, r3\n"
        "    strh r0, [r1, #0x20]\n"
        "    adds r1, #2\n"
        "    adds r2, #1\n"
        "    cmp r2, #0xf\n"
        "    bls .L080E5DB0\n"
        "    pop {r4}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080E5DCC: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080E5DD0: .4byte 0x0000FFFF\n"
    );
}
#endif


// sub_080E5DD4 @ 0x080E5DD4
/* Input of the battle command menu (Fight / Talk / Escape / Auto). */
void sub_080E5DD4(struct Task *t)
{
    struct C15cBattle *b = BB;
    struct MenuCursor *c = sub_08126D1C(0);
    u16 prev = c->row;
    u8 i;

    sub_08126A08(0);
    Sprite_Draw(gUnknown_080008B0, 0, 0, 0, 0, 0xB6, gUnknown_086BE5D2[c->row]);
    t->result = 0;
    b->unkF64 = c->row;
    b->unkF62 = 0;
    if (prev != c->row && b->msg.mode == 4)
        BattleMenu_SetMode(4, gUnknown_086BE5EC[c->row]);
    if (gKeysNew & 8)
    {
        c->state = 3;
        c->row = 3;
    }
    if (c->state == 3)
    {
        switch (c->row)
        {
        case 0:
            sub_080E5DA0();
            b->state = 9;
            b->substate = 0;
            b->unkF66 = 0;
            b->unk11AA = 0;
            for (i = 0; i < 6 && sub_080F30CC(i) == -1; i++)
            {
                b->unkF66++;
                b->unk11AA++;
            }
            b->unkECE = sub_080F30CC(b->unkF66);
            if (b->unkF6A == 0)
                sub_080C6FF0();
            else
                sub_080C7038();
            sub_080EC948();
            break;
        case 1:
            b->state = 11;
            break;
        case 2:
            b->state = 12;
            break;
        case 3:
            if (b->unkF6A == 0)
                sub_080C6FF0();
            else
                sub_080C7038();
            sub_080EC948();
            b->state = 13;
            break;
        }
        b->substate = 0;
        t->result = 1;
        b->unk690 = c->row;
        sub_081269B0(0);
        BattleMenu_Reset();
    }
    else if (c->state == 6)
    {
        if (b->msg.mode == 4)
        {
            BattleMenu_SetMode(3, gUnknown_086BE5DA);
            BattleMsg_SetDone(1);
        }
        else
        {
            BattleMenu_SetMode(4, gUnknown_086BE5EC[c->row]);
        }
    }
}

// sub_080E5FF0 @ 0x080E5FF0
/* Opens the five-row action menu of the acting member, cursor on its last command. */
void sub_080E5FF0(void)
{
    struct C15cBattle *b = BB;
    struct MenuCursor c;
    struct C15cGameState *gs;
    u8 last;
    u8 kind;
    u8 i;

    CpuFill32(0, &c, sizeof(c));
    c.state = 1;
    c.delay = 0;
    c.mode = 0;
    c.flags = 1;
    c.columns = 1;
    c.rows = 5;
    c.count = 5;
    c.top = 0;
    c.onScreen = 0;
    c.perColumn = 5;
    c.index = 0;
    c.unk14 = 0;
    c.column = 0;
    c.row = 0;
    c.seMove = c.sePage = 0x64;
    c.seA = 0x65;
    c.seB = 0x66;
    c.seLR = c.seStart = c.seSelect = 0xFFFF;
    sub_081268E4(0, &c);
    gs = (struct C15cGameState *)gGameState;
    last = sub_080C3620(gs->order[b->unkF66]);
    kind = sub_080E6130(b->unkF66);
    for (i = 0; i < 5; i++)
    {
        if (last == gUnknown_086BE610[kind][i])
            break;
    }
    if (i == 5)
        i = 0;
    MenuCursor_SetIndex(0, i);
    BattleMenu_SetMode(3, Battle_BuildActorPrompt(b->unkF66));
    BattleMsg_SetDone(1);
    sub_080C8490(b->unkF66);
    b->unkEF0[GS->order[b->unkF66]] = 0xFFFF;
    b->unkF10[GS->order[b->unkF66]] = -1;
}

// sub_080E6130 @ 0x080E6130
/* 0 for the hero, 1 for the other humans (party slots 1-3), 2 for demons. */
u8 sub_080E6130(u8 slot)
{
    struct C15cGameState *gs = (struct C15cGameState *)gGameState;
    u8 r = 2;

    switch (gs->order[slot])
    {
    case 0:
        r = 0;
        break;
    case 1:
    case 2:
    case 3:
        r = 1;
        break;
    }
    return r;
}

// sub_080E6164 @ 0x080E6164
/* Input of the action menu opened by sub_080E5FF0. */
void sub_080E6164(struct Task *t)
{
    struct C15cBattle *b = BB;
    struct MenuCursor *c = sub_08126D1C(0);
    u16 prev = c->row;
    u8 cmd;

    sub_08126A08(0);
    cmd = gUnknown_086BE610[sub_080E6130(b->unkF66)][c->row];
    t->result = 0;
    b->unkF62 = 0;
    if (c->state == 4)
    {
        t->result = 1;
        sub_080F2FEC((s16 *)&b->unkECE, &b->unkF66);
        if (b->unkF66 < 0 || b->unkF62 != 0)
            b->state = 6;
        else
            b->substate = 0;
    }
    else if (c->state == 3)
    {
        t->result = 1;
        b->unk690 = c->row;
        sub_080C35C4(GS->order[b->unkF66], cmd);
        sub_080C8480(b->unkF66);
        b->substate = 2;
    }
    else if (c->state == 6)
    {
        if (b->msg.mode == 4)
        {
            BattleMenu_SetMode(3, Battle_BuildActorPrompt(b->unkF66));
            BattleMsg_SetDone(1);
        }
        else
        {
            BattleMenu_SetMode(4, gUnknown_086BE620[cmd]);
        }
    }
    else if (prev != c->row && b->msg.mode == 4)
    {
        BattleMenu_SetMode(4, gUnknown_086BE620[cmd]);
    }
    Sprite_Draw(gUnknown_080008B0, 0, 0, 0, 0, 0xB6, gUnknown_086BE606[c->row]);
}

// sub_080E62E8 @ 0x080E62E8
void sub_080E62E8(void)
{
    struct C15cBattle *b = BB;
    struct C15cWin *w = &b->win;

    w->yesno = YesNo_Create(0);
    BattleMenu_SetMode(3, gUnknown_081230DC);
    BattleMsg_SetDone(1);
}

// sub_080E6318 @ 0x080E6318
void sub_080E6318(struct Task *t)
{
    struct C15cBattle *b = BB;
    struct C15cWin *w = &b->win;
    u16 cancel;

    t->result = 0;
    cancel = gKeysNew & 2;
    if (cancel)
    {
        sub_080F2FEC((s16 *)&b->unkECE, &b->unkF66);
        if (b->unkF66 < 0)
            b->state = 6;
        b->substate = 0;
        Task_End((struct Task *)w->yesno);
        t->result = 1;
        sub_080ECF70(0x66);
    }
    else if (Task_IsFree(w->yesno) == 1)
    {
        if (gYesNoResult == 1)
        {
            sub_080F2FEC((s16 *)&b->unkECE, &b->unkF66);
            if (b->unkF66 < 0)
                b->state = 6;
        }
        else if (gYesNoResult == 0)
        {
            b->unkECE = cancel;
            b->state = 10;
        }
        else
        {
            sub_080F2FEC((s16 *)&b->unkECE, &b->unkF66);
            if (b->unkF66 < 0)
                b->state = 6;
        }
        b->substate = cancel;
        t->result = 1;
    }
}
