/* Battle command menu, continued: item use, party target selection. */

#include "global.h"
#include "bmenu2.h"

// sub_0812BF54 @ 0x0812BF54
void sub_0812BF54(void)
{
    BattleMenu_DrawListPage(6, sub_08126D1C(4)->top);
}

// sub_0812BF68 @ 0x0812BF68
void sub_0812BF68(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct C127SortEntry *list = (struct C127SortEntry *)blk->list;
    struct MenuCursor *c = sub_08126D1C(4);
    u8 oldTop = c->top;

    sub_08126A08(4);
    task->pad1E = 0;
    task->result = 0;
    if (gKeysNew & 2)
    {
        task->pad1E = 0x100;
        task->result = 1;
    }
    else if (gKeysNew & 1)
    {
        u16 *id = &list[c->index].id;

        task->pad1E = *id;
        task->data.raw[0] = *id;
        task->result = 1;
    }
    if (oldTop != c->top)
        BattleMenu_DrawListPage(6, c->top);
    Sprite_Draw(gUnknown_08000F8C, 0, 0, 1, 0, 0x14, c->onScreen * 13 + 6);
    if (c->count > 5)
    {
        if (c->top != 0)
            Sprite_Draw(gUnknown_08000FF0, 0, 0, 1, 0, 0x94, 4);
        if (c->top + 5 != c->count)
            Sprite_Draw(gUnknown_08001000, 0, 0, 1, 0, 0x94, 0x43);
    }
}

// sub_0812C054 @ 0x0812C054
void sub_0812C054(void)
{
    struct C127Block *blk = C127_BLOCK;

    if (blk->unk4C != 0)
        TextWindow_Close(blk->unk4C, 0);
    sub_081269B0(4);
    BattleMsg_Close();
    sub_08128388();
}

// sub_0812C07C @ 0x0812C07C
void sub_0812C07C(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct C127Sub110C *s = &blk->unk110C;

    sub_080EA210();
    s->yesno = YesNo_Create(0);
    BattleMenu_SetMode(3, Battle_BuildItemDropText(task->pad1E, gUnknown_08124514));
    BattleMsg_SetDone(1);
}

// sub_0812C0BC @ 0x0812C0BC
void sub_0812C0BC(struct Task *task)
{
    sub_080C33AC(task->data.raw[0]);
    BattleMsg_Close();
}

// sub_0812C0D0 @ 0x0812C0D0
void sub_0812C0D0(void)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk48 = Task_Create(gUnknown_08779834, 0xFFFF);
    blk->unk50 = 0;
    blk->unk4C = 0;
    blk->unk691 = 1;
}

// sub_0812C104 @ 0x0812C104
void sub_0812C104(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    const u16 *tmpl;

    task->pad1E = 0;
    sub_080EA210();
    if (sub_080F31E0())
        tmpl = gUnknown_08124F82;
    else
    {
        if (sub_080F4444())
            goto choose;
        tmpl = gUnknown_08124EFA;
    }
    BattleMenu_SetMode(3, Menu_ExpandListTemplate(tmpl, 0));
    task->pad1E = 0x100;
    return;
choose:
    BattleMenu_SetMode(4, Menu_ExpandListTemplate(gUnknown_08124F12, 0));
    blk->unk4C = sub_080C8AAC(0, blk->unk691);
    sub_080C8ADC(blk->unk4C, 1);
}

// sub_0812C180 @ 0x0812C180
void sub_0812C180(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;

    task->result = 0;
    task->pad1E = 0;
    if (gKeysNew & 2)
    {
        task->pad1E = 0x100;
        task->result = 1;
        sub_080C8ADC(blk->unk4C, 0);
        sub_080ECF70(0x66);
    }
    else if (gKeysNew & 1)
    {
        u16 idx = sub_080C8AF4(blk->unk4C);
        s16 who = gGameState.order[idx];

        if (who == -1 || (Combatant_GetStatus(who) & 0x8000))
            sub_080ECF70(0x66);
        else
        {
            task->result = 1;
            sub_080C8ADC(blk->unk4C, 0);
            blk->unk691 = idx;
            task->pad1E = (u8)idx;
            BCMD->who = who;
            sub_080ECF70(0x65);
        }
    }
    else if (gKeysNew & 0xF0)
        sub_080ECF70(0x64);
}

// sub_0812C250 @ 0x0812C250
void sub_0812C250(void)
{
    struct C127Block *blk = C127_BLOCK;

    sub_08128B84(1);
    BattleMsg_Close();
    if (blk->unk50 != 0)
        Task_End((struct Task *)blk->unk50);
}

// sub_0812C274 @ 0x0812C274
void sub_0812C274(void)
{
    sub_0812C490(0, 0);
}

// sub_0812C284 @ 0x0812C284
void sub_0812C284(struct Task *task)
{
    u32 r = sub_0812C4D4();
    struct C127Block *blk = C127_BLOCK;

    task->result = 0;
    task->pad1E = 0;
    if (r != (u32)-1)
    {
        u32 hi;

        task->result = 1;
        if ((hi = r & 0xFFFF0000) == 0xFFFE0000)
            task->pad1E = 0x100;
        else
        {
            hi >>= 16;
            blk->unkF30[BCMD->who] = hi;
            BCMD->skill = r;
            BCMD->type = 7;
        }
    }
}

// sub_0812C2E4 @ 0x0812C2E4
#ifdef NONMATCHING
void sub_0812C2E4(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;

    task->result = 0;
    switch (task->pad1E)
    {
    case 0:
    {
        u16 skill = BCMD->skill;

        sub_080EA210();
        if ((u16)(skill - 0x3E) <= 1)
        {
            task->pad1E = 6;
            break;
        }
        task->pad1E = 1;
        BattleMenu_SetMode(3, sub_080EAF1C(Battle_GetCombatant((u16)BCMD->who - 0x8000), skill));
        break;
    }
    case 1:
        if (BattleMsg_IsDone() == 1)
        {
            sub_080ED6DC(BCMD->who, BCMD->skill);
            sub_0812E780(BCMD->who, blk->unkF30, gUnknown_08124D5E, 0);
            sub_080F4410(BCMD->who);
            task->pad1E = 4;
            if (BCMD->unk0 != 0)
            {
                task->result = 1;
                task->pad1E = 0xFF;
            }
        }
        break;
    case 6:
        sub_0812931C();
        sub_081293F8(2);
        task->pad1E = 3;
        break;
    case 3:
    {
        u8 r = sub_08129440();

        if (r == 0)
            break;
        if (r == 1)
        {
            task->pad1E = 5;
            sub_080ED6DC(BCMD->who, BCMD->skill);
        }
        else if (r == 0xFF)
            task->pad1E = 5;
        break;
    }
    case 4:
        if (BattleMsg_IsDone() != 1)
            break;
    case 5:
        BattleMenu_Reset();
        if (BCMD->skill == 0x38)
        {
            task->result = 1;
            task->pad1E = 0xFE;
            sub_080C366C();
            Party_BuildMemberNameTiles();
            sub_080C6FD8();
            if (!Battle_IsPartyDefeated())
                break;
            sub_080B9058();
            task->result = 0;
            task->pad1E = 2;
        }
        else if (Battle_IsPartyDefeated())
        {
            sub_080B9058();
            task->result = 0;
            task->pad1E = 2;
        }
        else
        {
            task->result = 1;
            task->pad1E = 0;
            if ((u16)(BCMD->skill - 0x3E) <= 1)
                task->pad1E = 0xFE;
        }
        break;
    }
}
#else
NAKED
void sub_0812C2E4(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, lr}\n"
        "    adds r5, r0, #0\n"
        "    ldr r6, .L0812C300\n"
        "    movs r0, #0\n"
        "    strh r0, [r5, #0x1c]\n"
        "    ldrh r0, [r5, #0x1e]\n"
        "    cmp r0, #6\n"
        "    bls .L0812C2F6\n"
        "    b .L0812C46A\n"
        ".L0812C2F6:\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L0812C304\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        ".L0812C300: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L0812C304: .4byte gUnknown_0812C308\n"
        "    .global gUnknown_0812C308\n"
        "gUnknown_0812C308:\n"
        ".L0812C308: @ jump table\n"
        "    .4byte .L0812C324\n"
        "    .4byte .L0812C368\n"
        "    .4byte .L0812C46A\n"
        "    .4byte .L0812C3C6\n"
        "    .4byte .L0812C3F8\n"
        "    .4byte .L0812C400\n"
        "    .4byte .L0812C3B8\n"
        ".L0812C324:\n"
        "    ldr r6, .L0812C33C\n"
        "    ldrh r4, [r6, #2]\n"
        "    bl sub_080EA210\n"
        "    adds r0, r4, #0\n"
        "    subs r0, #0x3e\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bhi .L0812C340\n"
        "    movs r0, #6\n"
        "    b .L0812C468\n"
        ".L0812C33C: .4byte 0x030065C0 @ IWRAM+0x65C0\n"
        ".L0812C340:\n"
        "    movs r0, #1\n"
        "    strh r0, [r5, #0x1e]\n"
        "    ldr r1, .L0812C364\n"
        "    adds r0, r1, #0\n"
        "    ldrh r6, [r6, #6]\n"
        "    adds r0, r0, r6\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    adds r1, r4, #0\n"
        "    bl sub_080EAF1C\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetMode\n"
        "    b .L0812C46A\n"
        ".L0812C364: .4byte 0xFFFF8000\n"
        ".L0812C368:\n"
        "    bl BattleMsg_IsDone\n"
        "    cmp r0, #1\n"
        "    beq .L0812C372\n"
        "    b .L0812C46A\n"
        ".L0812C372:\n"
        "    ldr r4, .L0812C3B0\n"
        "    movs r2, #6\n"
        "    ldrsh r0, [r4, r2]\n"
        "    movs r2, #2\n"
        "    ldrsh r1, [r4, r2]\n"
        "    bl sub_080ED6DC\n"
        "    movs r1, #6\n"
        "    ldrsh r0, [r4, r1]\n"
        "    movs r2, #0xf3\n"
        "    lsls r2, r2, #4\n"
        "    adds r1, r6, r2\n"
        "    ldr r2, .L0812C3B4\n"
        "    movs r3, #0\n"
        "    bl sub_0812E780\n"
        "    movs r1, #6\n"
        "    ldrsh r0, [r4, r1]\n"
        "    bl sub_080F4410\n"
        "    movs r0, #4\n"
        "    strh r0, [r5, #0x1e]\n"
        "    ldr r0, .L0812C3B0\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r0, r2]\n"
        "    cmp r0, #0\n"
        "    beq .L0812C46A\n"
        "    movs r0, #1\n"
        "    strh r0, [r5, #0x1c]\n"
        "    movs r0, #0xff\n"
        "    b .L0812C468\n"
        ".L0812C3B0: .4byte 0x030065C0 @ IWRAM+0x65C0\n"
        ".L0812C3B4: .4byte gUnknown_08124D5E\n"
        ".L0812C3B8:\n"
        "    bl sub_0812931C\n"
        "    movs r0, #2\n"
        "    bl sub_081293F8\n"
        "    movs r0, #3\n"
        "    b .L0812C468\n"
        ".L0812C3C6:\n"
        "    bl sub_08129440\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    adds r1, r0, #0\n"
        "    cmp r0, #0\n"
        "    beq .L0812C46A\n"
        "    cmp r0, #1\n"
        "    bne .L0812C3F0\n"
        "    movs r0, #5\n"
        "    strh r0, [r5, #0x1e]\n"
        "    ldr r1, .L0812C3EC\n"
        "    movs r2, #6\n"
        "    ldrsh r0, [r1, r2]\n"
        "    movs r2, #2\n"
        "    ldrsh r1, [r1, r2]\n"
        "    bl sub_080ED6DC\n"
        "    b .L0812C46A\n"
        ".L0812C3EC: .4byte 0x030065C0 @ IWRAM+0x65C0\n"
        ".L0812C3F0:\n"
        "    cmp r1, #0xff\n"
        "    bne .L0812C46A\n"
        "    movs r0, #5\n"
        "    b .L0812C468\n"
        ".L0812C3F8:\n"
        "    bl BattleMsg_IsDone\n"
        "    cmp r0, #1\n"
        "    bne .L0812C46A\n"
        ".L0812C400:\n"
        "    bl BattleMenu_Reset\n"
        "    ldr r4, .L0812C438\n"
        "    movs r1, #2\n"
        "    ldrsh r0, [r4, r1]\n"
        "    cmp r0, #0x38\n"
        "    bne .L0812C43C\n"
        "    movs r0, #1\n"
        "    strh r0, [r5, #0x1c]\n"
        "    movs r0, #0xfe\n"
        "    strh r0, [r5, #0x1e]\n"
        "    bl sub_080C366C\n"
        "    bl Party_BuildMemberNameTiles\n"
        "    bl sub_080C6FD8\n"
        "    bl Battle_IsPartyDefeated\n"
        "    cmp r0, #0\n"
        "    beq .L0812C46A\n"
        "    bl sub_080B9058\n"
        "    movs r0, #0\n"
        "    strh r0, [r5, #0x1c]\n"
        "    movs r0, #2\n"
        "    b .L0812C468\n"
        "    .byte 0x00, 0x00\n"
        ".L0812C438: .4byte 0x030065C0 @ IWRAM+0x65C0\n"
        ".L0812C43C:\n"
        "    bl Battle_IsPartyDefeated\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #0\n"
        "    beq .L0812C452\n"
        "    bl sub_080B9058\n"
        "    movs r0, #0\n"
        "    strh r0, [r5, #0x1c]\n"
        "    movs r0, #2\n"
        "    b .L0812C468\n"
        ".L0812C452:\n"
        "    movs r0, #1\n"
        "    strh r0, [r5, #0x1c]\n"
        "    strh r1, [r5, #0x1e]\n"
        "    ldrh r4, [r4, #2]\n"
        "    adds r0, r4, #0\n"
        "    subs r0, #0x3e\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bhi .L0812C46A\n"
        "    movs r0, #0xfe\n"
        ".L0812C468:\n"
        "    strh r0, [r5, #0x1e]\n"
        ".L0812C46A:\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

// sub_0812C470 @ 0x0812C470
void sub_0812C470(void)
{
    struct C127Block *blk = C127_BLOCK;

    BattleMsg_Close();
    if (blk->unk50 != 0)
        Task_End((struct Task *)blk->unk50);
    sub_081269D0();
}

// sub_0812C490 @ 0x0812C490
void sub_0812C490(u8 a, u8 b)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk48 = Task_Create(gUnknown_087799D0, 0xFFFF);
    blk->unk48->data.raw[0] = a;
    blk->unk48->data.w[1] = -1;
    if (a != 0)
        blk->unk691 = b;
}

// sub_0812C4D4 @ 0x0812C4D4
u32 sub_0812C4D4(void)
{
    return C127_BLOCK->unk48->data.w[1];
}

// sub_0812C4E0 @ 0x0812C4E0
u32 sub_0812C4E0(u16 id, u16 demon)
{
    u16 i = 0;
    u8 *rec;
    s32 j;

    while (gUnknown_087799A8[i] != 0xFFFF)
    {
        if (gUnknown_087799A8[i] == id)
            return 1;
        i++;
    }
    if (id > 0x3F)
    {
        rec = Demon_GetRecord(demon);
        for (j = 0; j <= 6; j++)
        {
            if (j == 6 && rec[0x17] == id && rec[0x16] == 0xFF)
                return 1;
        }
    }
    return 0;
}

/* Builds the skill list of party member `who` at blk->list: mode 0 = usable in battle
   (flag 0xC0), else flag 0x20; mode 2 takes only ids >= 0x40 that sub_0812C4E0 does not
   exclude. */
// BattleMenu_BuildSkillList @ 0x0812C550
u16 BattleMenu_BuildSkillList(u8 mode, u16 who)
{
    struct C127Block *blk = C127_BLOCK;
    u8 *c = (u8 *)Battle_GetCombatant(who + 0x8000);
    u8 *skills = c + 0x5D;
    u16 *out = blk->list;
    u16 count = 0;
    u8 mask = mode != 0 ? 0x20 : 0xC0;
    u16 i;
    u8 s;
    bool8 ok;

    i = 0;
    ok = FALSE;
    s = *skills;
    skills = c + 0x5E;
    while (s != 0xFF)
    {
        if (mode == 2)
        {
            if (s > 0x3F && !sub_0812C4E0(s, Battle_GetCombatant(who + 0x8000)->demonId))
                ok = TRUE;
            else
                ok = FALSE;
        }
        else if (s <= 0x3F)
            ok = TRUE;
        if ((*sub_080BF5C0(s) & mask) && ok)
        {
            *out++ = s;
            count++;
        }
        if (++i > 0x1F)
            break;
        ok = FALSE;
        s = *skills++;
    }
    *out = 0xFFFF;
    return count;
}

// sub_0812C624 @ 0x0812C624
#ifdef NONMATCHING
void sub_0812C624(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    u16 n = 0;
    u16 who = gGameState.order[blk->unk691];
    const u16 *tmpl;
    s32 r;

    task->pad1E = n;
    n = BattleMenu_BuildSkillList(task->data.raw[0], who);
    if (n == 0)
        goto none;
    if (task->data.raw[0] == 2)
        goto window;
    if (sub_080F31E0())
    {
        tmpl = gUnknown_08124F82;
        goto show;
    }
    r = sub_080F4410(who);
    if (r == 0)
    {
    none:
        tmpl = gUnknown_08124F46;
    show:
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(tmpl, 0));
        task->pad1E = 1;
    }
    else if (r == 1)
    {
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(gUnknown_08124F60, who));
        task->pad1E = 1;
    }
    else
    {
    window:
        blk->unk4C = TextWindow_Create(1, 0, 0x13, 0xA, 1);
        blk->unk50 = sub_080AB890(2, 0xD, 0x1A, 6, 0);
        sub_081272AC();
        if (n <= 4)
            sub_08126928(4, 0, 1, n, n);
        else
            sub_08126928(4, 0x10, 1, n, 5);
    }
}
#else
NAKED
void sub_0812C624(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    sub sp, #4\n"
        "    adds r7, r0, #0\n"
        "    ldr r0, .L0812C678\n"
        "    mov r8, r0\n"
        "    movs r6, #0\n"
        "    ldr r0, .L0812C67C\n"
        "    ldr r1, .L0812C680\n"
        "    add r1, r8\n"
        "    movs r2, #0xa2\n"
        "    lsls r2, r2, #4\n"
        "    adds r0, r0, r2\n"
        "    ldrb r1, [r1]\n"
        "    adds r0, r0, r1\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    strh r6, [r7, #0x1e]\n"
        "    adds r4, r7, #0\n"
        "    adds r4, #0x24\n"
        "    ldrb r0, [r4]\n"
        "    adds r1, r5, #0\n"
        "    bl BattleMenu_BuildSkillList\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r6, #0\n"
        "    beq .L0812C69A\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #2\n"
        "    beq .L0812C6CC\n"
        "    bl sub_080F31E0\n"
        "    cmp r0, #0\n"
        "    beq .L0812C688\n"
        "    ldr r0, .L0812C684\n"
        "    b .L0812C69C\n"
        "    .byte 0x00, 0x00\n"
        ".L0812C678: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L0812C67C: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L0812C680: .4byte 0x00000691\n"
        ".L0812C684: .4byte gUnknown_08124F82\n"
        ".L0812C688:\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080F4410\n"
        "    adds r4, r0, #0\n"
        "    cmp r4, #0\n"
        "    beq .L0812C69A\n"
        "    cmp r4, #1\n"
        "    beq .L0812C6B4\n"
        "    b .L0812C6CC\n"
        ".L0812C69A:\n"
        "    ldr r0, .L0812C6B0\n"
        ".L0812C69C:\n"
        "    movs r1, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetMode\n"
        "    movs r0, #1\n"
        "    strh r0, [r7, #0x1e]\n"
        "    b .L0812C71A\n"
        ".L0812C6B0: .4byte gUnknown_08124F46\n"
        ".L0812C6B4:\n"
        "    ldr r0, .L0812C6C8\n"
        "    adds r1, r5, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetMode\n"
        "    strh r4, [r7, #0x1e]\n"
        "    b .L0812C71A\n"
        ".L0812C6C8: .4byte gUnknown_08124F60\n"
        ".L0812C6CC:\n"
        "    movs r0, #1\n"
        "    str r0, [sp]\n"
        "    movs r1, #0\n"
        "    movs r2, #0x13\n"
        "    movs r3, #0xa\n"
        "    bl TextWindow_Create\n"
        "    mov r1, r8\n"
        "    str r0, [r1, #0x4c]\n"
        "    movs r0, #0\n"
        "    str r0, [sp]\n"
        "    movs r0, #2\n"
        "    movs r1, #0xd\n"
        "    movs r2, #0x1a\n"
        "    movs r3, #6\n"
        "    bl sub_080AB890\n"
        "    mov r2, r8\n"
        "    str r0, [r2, #0x50]\n"
        "    bl sub_081272AC\n"
        "    cmp r6, #4\n"
        "    bhi .L0812C70A\n"
        "    str r6, [sp]\n"
        "    movs r0, #4\n"
        "    movs r1, #0\n"
        "    movs r2, #1\n"
        "    adds r3, r6, #0\n"
        "    bl sub_08126928\n"
        "    b .L0812C71A\n"
        ".L0812C70A:\n"
        "    movs r0, #5\n"
        "    str r0, [sp]\n"
        "    movs r0, #4\n"
        "    movs r1, #0x10\n"
        "    movs r2, #1\n"
        "    adds r3, r6, #0\n"
        "    bl sub_08126928\n"
        ".L0812C71A:\n"
        "    add sp, #4\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// sub_0812C728 @ 0x0812C728
void sub_0812C728(struct Task *task)
{
    if (task->data.raw[0] != 2)
        BattleMenu_SetMode(4, Menu_ExpandListTemplate(gUnknown_08124F2C, 0));
    else
        BattleMenu_SetMode(4, Menu_ExpandListTemplate(gUnknown_08124570, 0));
}

/* Reads the cursor's entry as a byte offset into the u16 list (list + index, not
   list[index]): only right for index 0, which is where the cursor starts. */
// sub_0812C760 @ 0x0812C760
void sub_0812C760(struct Task *task)
{
    struct MenuCursor *c = sub_08126D1C(4);
    struct C127Block *blk = C127_BLOCK;
    u8 *list = (u8 *)blk->list;
    u8 id = list[c->index];

    if (task->data.raw[0] != 2)
        BattleMenu_DrawListPage(7, c->top);
    else
        BattleMenu_DrawListPage(8, c->top);
    BattleMenu_SetMode(8, Menu_ExpandListTemplate(*(const u16 **)(sub_080BF5C0(id) + 0x18), 0));
}

// sub_0812C7B4 @ 0x0812C7B4
void sub_0812C7B4(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct MenuCursor *c = sub_08126D1C(4);
    u8 oldTop = c->top;
    u8 oldIndex = c->index;

    sub_08126A08(4);
    task->pad1E = 0;
    task->result = 0;
    if (gKeysNew & 2)
    {
        task->pad1E = 0x100;
        task->result = 1;
    }
    else if (gKeysNew & 1)
    {
        u16 who;
        u16 id;
        s16 sid;

        task->result = 1;
        who = gGameState.order[blk->unk691];
        id = C12B_BLOCK_ABS->list[c->index];
        sid = id;
        sub_080ED6CC(sid);
        Battle_GetMp(who);
        sub_080ED694(sid);
        if (sub_080ED744(who, sid) == 1)
            task->data.raw[8] = id;
        else if (sub_08127E98(sid) == 1)
            task->pad1E = 2;
        else
            task->pad1E = 1;
    }
    if (oldTop != c->top)
    {
        if (task->data.raw[0] != 2)
            BattleMenu_DrawListPage(7, c->top);
        else
            BattleMenu_DrawListPage(8, c->top);
    }
    if (oldIndex != c->index)
        BattleMenu_SetMode(8, Menu_ExpandListTemplate(*(const u16 **)(sub_080BF5C0(C12B_BLOCK_ABS->list[c->index]) + 0x18), 0));
    Sprite_Draw(gUnknown_08000F8C, 0, 0, 1, 0, 0x14, c->onScreen * 13 + 6);
    if (c->count > 5)
    {
        if (c->top != 0)
            Sprite_Draw(gUnknown_08000FF0, 0, 0, 1, 0, 0x94, 4);
        if (c->top + 5 != c->count)
            Sprite_Draw(gUnknown_08001000, 0, 0, 1, 0, 0x94, 0x43);
    }
}

// sub_0812C958 @ 0x0812C958
void sub_0812C958(void)
{
    BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(0x97), 0));
}

// sub_0812C974 @ 0x0812C974
void sub_0812C974(void)
{
    BattleMenu_SetMode(3, gUnknown_081241E0);
}

// sub_0812C988 @ 0x0812C988
void sub_0812C988(void)
{
    struct C127Block *blk = C127_BLOCK;

    if (blk->unk4C != 0)
        TextWindow_Close(blk->unk4C, 0);
    if (blk->unk50 != 0)
        Window_Close((void *)blk->unk50, 0);
    sub_081269B0(4);
    BattleMenu_Reset();
    sub_08128388();
}
