/* Battle menu: item use and the skill (magic) list. */

#include "global.h"
#include "bmenu.h"

// sub_0812B028 @ 0x0812B028
void sub_0812B028(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    u16 item;
    const u16 *tmpl;
    s32 attr;
    u16 who;

    task->result = 0;
    switch (task->pad1E)
    {
    case 0:
        item = gUnk_030065C0[1];
        gUnk_03006440 = item;
        sub_080EA210();
        tmpl = gUnknown_08124D5E;
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(tmpl, (item << 16) + Party_FirstActiveHuman()));
        task->pad1E = 1;
        break;
    case 1:
        if (BattleMsg_IsDone() == 1)
        {
            item = gUnk_030065C0[1];
            sub_080F3E54(item, -1);
            Item_GetAttribute(item, 0xC, &attr);
            if (attr <= 0x7F)
            {
                sub_0812E780(gUnk_030065C0[3], blk->unkF30, gUnknown_08124D5E, 1);
                if ((u32)(attr - 0x3E) <= 1)
                {
                    who = sub_080F1678(0, 2);
                    BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(0xE9), gGameState.order[who]));
                }
            }
            else
            {
                sub_0812EA98(gUnk_030065C0[3]);
            }
            task->pad1E = 2;
        }
        break;
    case 2:
        if (BattleMsg_IsDone() == 1)
        {
            BattleMenu_Reset();
            BattleMsg_Close();
            task->pad1E = 3;
        }
        break;
    case 3:
        task->result = 1;
        break;
    }
}

// sub_0812B138 @ 0x0812B138
void sub_0812B138(struct Task *task)
{
    u16 n;
    struct MenuCursor *c;

    task->result = 1;
    if (!Inventory_GetCount(gUnk_03006440))
    {
        n = sub_0812B260(0);
        if (n != 0)
        {
            if (n <= 4)
            {
                gSavedMenuCursor.count = n;
                gSavedMenuCursor.perColumn = n;
            }
            else
            {
                gSavedMenuCursor.count = n;
                gSavedMenuCursor.perColumn = 5;
            }
            c = &gSavedMenuCursor;
            if (c->index > n - 1)
                c->index = c->index - 1;
        }
        else
        {
            task->result = n;
        }
    }
}

// sub_0812B194 @ 0x0812B194
void sub_0812B194(u8 mode, u16 value)
{
    struct C127Block *blk = C127_BLOCK;
    struct Task *t;

    gUnk_03006478 = value;
    blk->unk48 = Task_Create(gUnknown_087790C4, 0xFFFF);
    blk->unk48->data.raw[0] = mode;
    t = blk->unk48;
    BattleMsg_Close();
    t->data.w[1] = -1;
}

// sub_0812B1D4 @ 0x0812B1D4
u32 sub_0812B1D4(void)
{
    return C127_BLOCK->unk48->data.w[1];
}

/* Counts active party members (of the first n, at most 6) whose Combatant_GetChosenSkill is `who`. */
// sub_0812B1E0 @ 0x0812B1E0
#ifdef NONMATCHING
u16 sub_0812B1E0(s32 who, u8 n)
{
    u16 count = 0;
    u16 i;
    u16 m;

    if (n == 0)
        return 0;
    if (n > 6)
        n = 6;
    for (i = 0; i < n; i++)
    {
        m = gUnk_030050E0[i];
        if (Combatant_IsInParty(m) && sub_080F3040(m) && sub_080C35E4(m) == 8 && Combatant_GetChosenSkill(m) == who)
            count++;
    }
    return count;
}
#else
NAKED
u16 sub_0812B1E0(s32 who, u8 n)
{
    asm_unified(
        ".L0812B1E0:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sb\n"
        "    mov r6, r8\n"
        "    push {r6, r7}\n"
        "    mov r8, r0\n"
        "    lsls r1, r1, #0x18\n"
        "    movs r7, #0\n"
        "    lsrs r6, r1, #0x18\n"
        "    cmp r6, #0\n"
        "    bne .L0812B1F8\n"
        "    movs r0, #0\n"
        "    b .L0812B250\n"
        ".L0812B1F8:\n"
        "    cmp r6, #6\n"
        "    bls .L0812B1FE\n"
        "    movs r6, #6\n"
        ".L0812B1FE:\n"
        "    movs r5, #0\n"
        "    cmp r7, r6\n"
        "    bhs .L0812B24E\n"
        "    ldr r0, .L0812B25C\n"
        "    mov sb, r0\n"
        ".L0812B208:\n"
        "    mov r1, sb\n"
        "    adds r0, r5, r1\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_IsInParty\n"
        "    cmp r0, #0\n"
        "    beq .L0812B244\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080F3040\n"
        "    cmp r0, #0\n"
        "    beq .L0812B244\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080C35E4\n"
        "    cmp r0, #8\n"
        "    bne .L0812B244\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_GetChosenSkill\n"
        "    cmp r0, r8\n"
        "    bne .L0812B244\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        ".L0812B244:\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, r6\n"
        "    blo .L0812B208\n"
        ".L0812B24E:\n"
        "    adds r0, r7, #0\n"
        ".L0812B250:\n"
        "    pop {r3, r4}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        ".L0812B25C: .4byte 0x030050E0 @ IWRAM+0x50E0\n"
    );
}
#endif

/* Lists the skills (0xD0-0xFD) in the (id, count) table at 0x030051AC usable in this
   context; returns how many. */
// sub_0812B260 @ 0x0812B260
#ifdef NONMATCHING
u16 sub_0812B260(u8 mode)
{
    struct C127Block *blk = C127_BLOCK;
    struct C127SortEntry *out = (struct C127SortEntry *)blk->list;
    u16 n = 0;
    u32 mask;
    u16 i;
    u16 id;
    u16 cnt;
    u16 *e;

    mask = 0xC0;
    if (mode != 0)
        mask = 0x20;
    for (i = 0; i <= 0x159; i++)
    {
        e = &gInventory[i * 2];
        id = e[0];
        cnt = e[1];
        if (mode == 1)
            cnt = cnt - sub_0812B1E0(id, blk->unkF66);
        if ((u16)(id - 0xD0) <= 0x2D && cnt != 0 && (Action_GetRecord(id)[0] & mask))
        {
            out->id = id;
            out->key = cnt;
            out++;
            n++;
        }
    }
    out->id = 0xFFFF;
    out->key = -1;
    return n;
}
#else
NAKED
u16 sub_0812B260(u8 mode)
{
    asm_unified(
        ".L0812B260:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #4\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    mov r8, r0\n"
        "    ldr r0, .L0812B30C\n"
        "    mov sl, r0\n"
        "    movs r7, #0xb4\n"
        "    lsls r7, r7, #2\n"
        "    add r7, sl\n"
        "    movs r1, #0\n"
        "    mov sb, r1\n"
        "    movs r0, #0xc0\n"
        "    mov r1, r8\n"
        "    cmp r1, #0\n"
        "    beq .L0812B28A\n"
        "    movs r0, #0x20\n"
        ".L0812B28A:\n"
        "    str r0, [sp]\n"
        "    movs r6, #0\n"
        ".L0812B28E:\n"
        "    lsls r0, r6, #2\n"
        "    ldr r1, .L0812B310\n"
        "    adds r0, r0, r1\n"
        "    ldrh r2, [r0]\n"
        "    adds r5, r2, #0\n"
        "    ldrh r4, [r0, #2]\n"
        "    mov r0, r8\n"
        "    cmp r0, #1\n"
        "    bne .L0812B2B2\n"
        "    ldr r0, .L0812B314\n"
        "    add r0, sl\n"
        "    ldrb r1, [r0]\n"
        "    adds r0, r2, #0\n"
        "    bl sub_0812B1E0\n"
        "    subs r0, r4, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        ".L0812B2B2:\n"
        "    adds r0, r5, #0\n"
        "    subs r0, #0xd0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #0x2d\n"
        "    bhi .L0812B2E2\n"
        "    cmp r4, #0\n"
        "    beq .L0812B2E2\n"
        "    adds r0, r5, #0\n"
        "    bl Action_GetRecord\n"
        "    ldrb r0, [r0]\n"
        "    ldr r1, [sp]\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L0812B2E2\n"
        "    strh r5, [r7]\n"
        "    strh r4, [r7, #2]\n"
        "    adds r7, #4\n"
        "    mov r0, sb\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sb, r0\n"
        ".L0812B2E2:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldr r0, .L0812B318\n"
        "    cmp r6, r0\n"
        "    bls .L0812B28E\n"
        "    ldr r0, .L0812B31C\n"
        "    strh r0, [r7]\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    strh r0, [r7, #2]\n"
        "    mov r0, sb\n"
        "    add sp, #4\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L0812B30C: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L0812B310: .4byte 0x030051AC @ IWRAM+0x51AC\n"
        ".L0812B314: .4byte 0x00000F66\n"
        ".L0812B318: .4byte 0x00000159\n"
        ".L0812B31C: .4byte 0x0000FFFF\n"
    );
}
#endif

// sub_0812B320 @ 0x0812B320
u16 sub_0812B320(u16 limit)
{
    struct C127Block *blk = C127_BLOCK;
    u16 *e = gInventory;
    u32 *out = (u32 *)blk->list;
    u16 n = 0;
    u16 i;

    for (i = 0; i <= 0x159; i++)
    {
        if (e[0] < limit && e[1] != 0)
        {
            *out++ = *(u32 *)e;
            n++;
        }
        e += 2;
    }
    ((struct C127SortEntry *)out)->id = 0xFFFF;
    ((struct C127SortEntry *)out)->key = -1;
    return n;
}

// sub_0812B37C @ 0x0812B37C
u32 sub_0812B37C(void)
{
    u32 r = 0;

    if (Flag_Test(0xD5))
        r = gShopItemIds != 2;
    return r;
}

// sub_0812B3A4 @ 0x0812B3A4
#ifdef NONMATCHING
u16 sub_0812B3A4(u8 mode)
{
    u16 n = 0;
    u32 mask;
    u16 i;
    u16 id;
    u16 cnt;
    u16 *e;

    mask = 0xC0;
    if (mode != 0)
        mask = 0x20;
    if (sub_0812B37C())
        return 0;
    for (i = 0; i <= 0x159; i++)
    {
        e = &gInventory[i * 2];
        id = e[0];
        cnt = e[1];
        if ((u16)(id - 0xD0) <= 0x2E)
        {
            if (mode == 1)
                cnt = cnt - sub_0812B1E0(id, 0xFF);
            if ((s16)cnt > 0 && (Action_GetRecord(id)[0] & mask))
                n++;
        }
    }
    return n;
}
#else
NAKED
u16 sub_0812B3A4(u8 mode)
{
    asm_unified(
        ".L0812B3A4:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r7, r0, #0x18\n"
        "    movs r0, #0\n"
        "    mov r8, r0\n"
        "    movs r0, #0xc0\n"
        "    cmp r7, #0\n"
        "    beq .L0812B3BE\n"
        "    movs r0, #0x20\n"
        ".L0812B3BE:\n"
        "    mov sb, r0\n"
        "    bl sub_0812B37C\n"
        "    cmp r0, #0\n"
        "    beq .L0812B3CC\n"
        "    movs r0, #0\n"
        "    b .L0812B428\n"
        ".L0812B3CC:\n"
        "    movs r6, #0\n"
        "    ldr r1, .L0812B438\n"
        "    mov sl, r1\n"
        ".L0812B3D2:\n"
        "    lsls r0, r6, #2\n"
        "    ldr r1, .L0812B43C\n"
        "    adds r0, r0, r1\n"
        "    ldrh r1, [r0]\n"
        "    adds r5, r1, #0\n"
        "    ldrh r4, [r0, #2]\n"
        "    adds r0, r1, #0\n"
        "    subs r0, #0xd0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #0x2e\n"
        "    bhi .L0812B41C\n"
        "    cmp r7, #1\n"
        "    bne .L0812B3FC\n"
        "    adds r0, r1, #0\n"
        "    movs r1, #0xff\n"
        "    bl sub_0812B1E0\n"
        "    subs r0, r4, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        ".L0812B3FC:\n"
        "    lsls r0, r4, #0x10\n"
        "    cmp r0, #0\n"
        "    ble .L0812B41C\n"
        "    adds r0, r5, #0\n"
        "    bl Action_GetRecord\n"
        "    ldrb r0, [r0]\n"
        "    mov r1, sb\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L0812B41C\n"
        "    mov r0, r8\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        ".L0812B41C:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r6, sl\n"
        "    bls .L0812B3D2\n"
        "    mov r0, r8\n"
        ".L0812B428:\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L0812B438: .4byte 0x00000159\n"
        ".L0812B43C: .4byte 0x030051AC @ IWRAM+0x51AC\n"
    );
}
#endif

/* Saves cursor 4 to gSavedMenuCursor (mode 0) or restores it and its position (mode 1). */
// MenuCursor4_SaveRestore @ 0x0812B440
void MenuCursor4_SaveRestore(u16 mode)
{
    u8 *src;
    u8 *dst;
    u32 i;

    if (mode == 0)
    {
        src = (u8 *)sub_08126D1C(4);
        dst = (u8 *)&gSavedMenuCursor;
    }
    else
    {
        src = (u8 *)&gSavedMenuCursor;
        dst = (u8 *)sub_08126D1C(4);
    }
    for (i = 0; i < sizeof(struct MenuCursor); i++)
        *dst++ = *src++;
    if (mode == 1)
        MenuCursor_SetIndex(4, gSavedMenuCursor.index);
}

// sub_0812B490 @ 0x0812B490
void sub_0812B490(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    u16 n = 0;
    u32 busy;

    task->pad1E = n;
    sub_080EA210();
    busy = sub_0812B37C();
    if (busy != 0 || Party_FirstActiveHuman() == -1)
    {
        if (Flag_Test(0xD5))
            BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(0x392), 0));
        else
            BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(0x74), 0));
        task->pad1E = 1;
    }
    else
    {
        n = sub_0812B260(task->data.raw[0]);
        if (n == 0)
        {
            BattleMenu_SetMode(3, Menu_ExpandListTemplate(gUnknown_08124BD2, 0));
            task->pad1E = 1;
        }
        else
        {
            blk->unk4C = TextWindow_Create(1, 0, 0x13, 0xA, 1);
            blk->unk50 = sub_080AB890(2, 0xD, 0x1A, 6, busy);
            sub_081272AC();
            if (n <= 4)
                sub_08126928(4, 0, 1, n, n);
            else
                sub_08126928(4, 0x10, 1, n, 5);
            if (gUnk_03006478 != 0)
                MenuCursor4_SaveRestore(1);
        }
    }
}

// sub_0812B57C @ 0x0812B57C
void sub_0812B57C(void)
{
    BattleMenu_SetMode(4, Menu_ExpandListTemplate(gUnknown_08124CC8, 0));
}

// sub_0812B598 @ 0x0812B598
void sub_0812B598(void)
{
    struct MenuCursor *c = sub_08126D1C(4);
    struct C127Block *blk = C127_BLOCK;
    struct C127SortEntry *list = (struct C127SortEntry *)blk->list;
    u16 id = list[c->index].id;

    BattleMenu_DrawListPage(4, c->top);
    BattleMenu_SetMode(8, Menu_ExpandListTemplate(*(const u16 **)(Action_GetRecord(id) + 0x1C), 0));
}
