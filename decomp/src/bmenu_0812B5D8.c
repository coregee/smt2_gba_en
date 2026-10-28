/* Battle menu: skill list cursor, skill targets, escape. */

#include "global.h"
#include "bmenu.h"

// sub_0812B5D8 @ 0x0812B5D8
void sub_0812B5D8(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct C127SortEntry *list = (struct C127SortEntry *)blk->list;
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
        task->data.raw[8] = list[c->index].id;
        task->result = 1;
        MenuCursor4_SaveRestore(0);
    }
    if (oldTop != c->top)
        BattleMenu_DrawListPage(4, c->top);
    if (oldIndex != c->index)
        BattleMenu_SetMode(8, Menu_ExpandListTemplate(*(const u16 **)(Action_GetRecord(list[c->index].id) + 0x1C), 0));
    Sprite_Draw(gUnknown_08000F8C, 0, 0, 1, 0, 0x14, c->onScreen * 13 + 6);
    if (c->count > 5)
    {
        if (c->top != 0)
            Sprite_Draw(gUnknown_08000FF0, 0, 0, 1, 0, 0x94, 4);
        if (c->top + 5 != c->count)
            Sprite_Draw(gUnknown_08001000, 0, 0, 1, 0, 0x94, 0x43);
    }
}

// sub_0812B6F4 @ 0x0812B6F4
void sub_0812B6F4(void)
{
    struct C127Block *blk = C127_BLOCK;
    u32 *w;

    if (blk->unk4C != 0)
        TextWindow_Close(blk->unk4C, 0);
    if (blk->unk50 != 0)
        Window_Close((void *)blk->unk50, 0);
    w = &blk->unk974;
    if (*w != 0)
    {
        Window_Close((void *)*w, 0);
        *w = 0;
    }
    sub_081269B0(4);
    BattleMenu_Reset();
    sub_08128388();
}

// sub_0812B740 @ 0x0812B740
void sub_0812B740(struct Task *task)
{
    u8 id = task->data.raw[8];
    u8 *rec = Action_GetRecord(id);
    u16 r;

    task->pad1E = 0;
    if (rec[3] == 0x80 || rec[3] == 0x82 || rec[3] == 0x83)
        r = 1;
    else if (id == 0xFB)
        r = 3;
    else if (id == 0xE1)
        r = 4;
    else if (rec[3] == 0)
        r = 2;
    else
        return;
    task->pad1E = r;
}

// sub_0812B784 @ 0x0812B784
void sub_0812B784(struct Task *task)
{
    task->data.w[1] = (task->pad1E << 16) + task->data.raw[8];
}

// sub_0812B794 @ 0x0812B794
#ifdef NONMATCHING
void sub_0812B794(struct Task *task)
{
    u8 *rec = Action_GetRecord(task->data.raw[8]);
    u16 n = 0;
    struct C127Block *blk = C127_BLOCK;

    task->pad1E = n;
    switch (rec[3])
    {
    case 0x80:
        if (blk->unk48->data.raw[0] == 1)
            n = BattleMenu_BuildMemberList(1);
        else
            n = BattleMenu_BuildMemberList(0);
        break;
    case 0x82:
        if (blk->unk48->data.raw[0] == 1)
            n = BattleMenu_BuildMemberList(1);
        else
            n = BattleMenu_BuildMemberList(0);
        break;
    case 0x83:
        n = BattleMenu_BuildMemberList(6);
        break;
    case 0:
    case 0x81:
        break;
    }
    if (n != 0)
    {
        Task_End((struct Task *)blk->unk4C);
        Task_End((struct Task *)blk->unk50);
        blk->unk4C = TextWindow_Create(1, 0, 0xF, 0xA, 1);
        blk->unk50 = TextWindow_Create(0x11, 0, 0xC, 6, 1);
        sub_081272AC();
        if (n <= 4)
            sub_08126928(4, 0, 1, n, n);
        else
            sub_08126928(4, 0x10, 1, n, 5);
        task->pad1E = 1;
        sub_080EA210();
        BattleMenu_SetMode(4, Menu_ExpandListTemplate(gUnknown_08124D72, 0));
    }
}
#else
NAKED
void sub_0812B794(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    sub sp, #4\n"
        "    adds r7, r0, #0\n"
        "    adds r0, #0x2c\n"
        "    ldrb r0, [r0]\n"
        "    bl Action_GetRecord\n"
        "    movs r5, #0\n"
        "    ldr r6, .L0812B7BC\n"
        "    strh r5, [r7, #0x1e]\n"
        "    ldrb r0, [r0, #3]\n"
        "    cmp r0, #0x81\n"
        "    beq .L0812B7F8\n"
        "    cmp r0, #0x81\n"
        "    bgt .L0812B7C0\n"
        "    cmp r0, #0\n"
        "    beq .L0812B7F8\n"
        "    cmp r0, #0x80\n"
        "    beq .L0812B7CA\n"
        "    b .L0812B7F8\n"
        ".L0812B7BC: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L0812B7C0:\n"
        "    cmp r0, #0x83\n"
        "    beq .L0812B7EE\n"
        "    cmp r0, #0x83\n"
        "    blt .L0812B7DC\n"
        "    b .L0812B7F8\n"
        ".L0812B7CA:\n"
        "    ldr r0, [r6, #0x48]\n"
        "    adds r0, #0x24\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #1\n"
        "    bne .L0812B7D8\n"
        "    movs r0, #1\n"
        "    b .L0812B7F0\n"
        ".L0812B7D8:\n"
        "    movs r0, #0\n"
        "    b .L0812B7F0\n"
        ".L0812B7DC:\n"
        "    ldr r0, [r6, #0x48]\n"
        "    adds r0, #0x24\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #1\n"
        "    bne .L0812B7EA\n"
        "    movs r0, #1\n"
        "    b .L0812B7F0\n"
        ".L0812B7EA:\n"
        "    movs r0, #0\n"
        "    b .L0812B7F0\n"
        ".L0812B7EE:\n"
        "    movs r0, #6\n"
        ".L0812B7F0:\n"
        "    bl BattleMenu_BuildMemberList\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        ".L0812B7F8:\n"
        "    cmp r5, #0\n"
        "    beq .L0812B86A\n"
        "    ldr r0, [r6, #0x4c]\n"
        "    bl Task_End\n"
        "    ldr r0, [r6, #0x50]\n"
        "    bl Task_End\n"
        "    movs r4, #1\n"
        "    str r4, [sp]\n"
        "    movs r0, #1\n"
        "    movs r1, #0\n"
        "    movs r2, #0xf\n"
        "    movs r3, #0xa\n"
        "    bl TextWindow_Create\n"
        "    str r0, [r6, #0x4c]\n"
        "    str r4, [sp]\n"
        "    movs r0, #0x11\n"
        "    movs r1, #0\n"
        "    movs r2, #0xc\n"
        "    movs r3, #6\n"
        "    bl TextWindow_Create\n"
        "    str r0, [r6, #0x50]\n"
        "    bl sub_081272AC\n"
        "    cmp r5, #4\n"
        "    bhi .L0812B842\n"
        "    str r5, [sp]\n"
        "    movs r0, #4\n"
        "    movs r1, #0\n"
        "    movs r2, #1\n"
        "    adds r3, r5, #0\n"
        "    bl sub_08126928\n"
        "    b .L0812B852\n"
        ".L0812B842:\n"
        "    movs r0, #5\n"
        "    str r0, [sp]\n"
        "    movs r0, #4\n"
        "    movs r1, #0x10\n"
        "    movs r2, #1\n"
        "    adds r3, r5, #0\n"
        "    bl sub_08126928\n"
        ".L0812B852:\n"
        "    movs r0, #1\n"
        "    strh r0, [r7, #0x1e]\n"
        "    bl sub_080EA210\n"
        "    ldr r0, .L0812B874\n"
        "    movs r1, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #4\n"
        "    bl BattleMenu_SetMode\n"
        ".L0812B86A:\n"
        "    add sp, #4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L0812B874: .4byte gUnknown_08124D72\n"
    );
}
#endif

// sub_0812B878 @ 0x0812B878
void sub_0812B878(void)
{
    struct MenuCursor *c = sub_08126D1C(4);

    BattleMenu_DrawListPage(0, c->top);
    sub_081283C4(0, c->index);
}

// sub_0812B898 @ 0x0812B898
void sub_0812B898(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct MenuCursor *c = sub_08126D1C(4);
    u8 old = c->index;

    sub_08126A08(4);
    task->pad1E = 0;
    task->result = 0;
    if (gKeysNew & 2)
    {
        task->pad1E = 0x100;
        task->result = 1;
    }
    else if (c->state == 3)
    {
        task->pad1E = blk->list[c->index];
        task->result = 1;
    }
    Sprite_Draw(gUnknown_08000EA4, 0, 0, 1, 0, 0xC, c->onScreen * 13 + 6);
    if (c->count > 5)
    {
        if (c->top != 0)
            Sprite_Draw(gUnknown_08000FF0, 0, 0, 1, 0, 0x74, 4);
        if (c->top + 5 != c->count)
            Sprite_Draw(gUnknown_08001000, 0, 0, 1, 0, 0x74, 0x43);
    }
    if (old != c->index)
    {
        BattleMenu_DrawListPage(0, c->top);
        sub_081283C4(0, c->index);
    }
}

// sub_0812B978 @ 0x0812B978
void sub_0812B978(void)
{
    struct C127Block *blk = C127_BLOCK;

    if (blk->unk4C != 0)
        TextWindow_Close(blk->unk4C, 0);
    if (blk->unk50 != 0)
        TextWindow_Close(blk->unk50, 0);
    sub_081269B0(4);
    BattleMenu_Reset();
    sub_08128388();
}

// sub_0812B9AC @ 0x0812B9AC
void sub_0812B9AC(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    s16 r = sub_080E6E08();
    u16 who = gGameState.order[blk->unk691];

    task->result = 0;
    task->pad1E = 0;
    switch (r)
    {
    case 3:
        task->result = 1;
        task->pad1E = sub_080EDA64(who);
        break;
    case 2:
        task->pad1E = 0x100;
        task->result = 1;
        break;
    }
}

// sub_0812BA0C @ 0x0812BA0C
void sub_0812BA0C(struct Task *task)
{
    sub_0812EE8C(1, task);
}

// sub_0812BA1C @ 0x0812BA1C
void sub_0812BA1C(struct Task *task)
{
    if (gYesNoResult == 0)
        task->result = 1;
    else
        task->result = 0;
}

/* Escape: 0 = cancel, 1 = escaped (fade unless on certain maps), else = run from battle. */
// sub_0812BA38 @ 0x0812BA38
void sub_0812BA38(struct Task *task, u32 mode)
{
    struct C127Block *blk = C127_BLOCK;

    if (mode == 0)
    {
        Task_End(blk->unk44);
    }
    else if (mode == 1)
    {
        if (!((gUnk_0200AB04 & 0x7FFF) == 0 && FieldMap_HasRecordRel(0, 0, 6) == 1)
         && !((gUnk_0200AB04 & 0x7FFF) == 0
              && (gUnk_03004614 == 2 || gUnk_03004614 == 0x27 || gUnk_03004614 == 0x41)))
        {
            sub_080B0888();
            if (gPaletteBuffer[0] != 0)
                PalFade_FadeRangeToBlackWithDuration(0, 1, 1, 4);
        }
        sub_080C700C();
    }
    else
    {
        u16 v;

        sub_080C33AC(0xFB);
        v = gGameState.unkAC0;

        if (v == 0)
            gUnk_03003BB8 = v;
        else
            gUnk_03003BB8 = 1;
        Flag_Set(0x166);
        sub_080E471C(sub_0812EEC4(), 1, 0xFFFF, 0);
    }
}

// sub_0812BB04 @ 0x0812BB04
void sub_0812BB04(void)
{
    sub_0812EF8C();
}

// sub_0812BB10 @ 0x0812BB10
void sub_0812BB10(void)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk48 = Task_Create(gUnknown_08779418, 0xFFFF);
    blk->unk48->data.raw[0] = 0;
    blk->unk48->data.w[1] = -1;
}

// sub_0812BB40 @ 0x0812BB40
void sub_0812BB40(struct Task *task, const u16 *tmpl)
{
    BattleMenu_SetMode(4, Menu_ExpandListTemplate(tmpl, 0));
}

// sub_0812BB58 @ 0x0812BB58
void sub_0812BB58(struct Task *task, const u16 *tmpl)
{
    BattleMenu_SetMode(9, Menu_ExpandListTemplate(tmpl, 0));
}

// sub_0812BB70 @ 0x0812BB70
void sub_0812BB70(struct Task *task)
{
    struct MenuCursor *c = sub_08126D1C(4);

    BattleMenu_DrawListPage(5, (task->data.raw[8] << 8) + c->top);
}

// sub_0812BB94 @ 0x0812BB94
void sub_0812BB94(struct Task *task)
{
    struct MenuCursor *c = sub_08126D1C(4);
    struct C127Block *blk = C127_BLOCK;
    struct C127SortEntry *list = (struct C127SortEntry *)blk->list;
    u16 id = list[c->index].id;

    BattleMenu_DrawListPage(5, (task->data.raw[8] << 8) + c->top);
    BattleMenu_SetMode(8, Menu_ExpandListTemplate(*(const u16 **)(Action_GetRecord(id) + 0x1C), 0));
}
