/* Field event callbacks: treasure (items, money, Magnetite) and healing springs. */

#include "global.h"
#include "fieldevent.h"

#define ITEM_DATA(task) ((struct ItemTaskData *)(task)->data)

// sub_080B8354 @ 0x080B8354
void sub_080B8354(struct Task *task)
{
    u32 v = ITEM_DATA(task)->rec->u.value;

    if ((v & 0xF0000000) == 0 && v > 0x11F && v <= 0x12B)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080B8384 @ 0x080B8384
/* Message for the special items 0x120-0x12B. */
void sub_080B8384(struct Task *task)
{
    const u16 *text;

    switch (ITEM_DATA(task)->rec->u.value - 0x120)
    {
    case 5:
        text = gUnknown_0805C0BA;
        break;
    case 0:
        text = gUnknown_0805C088;
        break;
    case 1:
        text = gUnknown_0805C092;
        break;
    case 7:
        text = gUnknown_0805C0CE;
        break;
    case 2:
        text = gUnknown_0805C09C;
        break;
    case 10:
        text = gUnknown_0805C0EC;
        break;
    case 11:
        text = gUnknown_0805C0F6;
        break;
    case 3:
        text = gUnknown_0805C0A6;
        break;
    case 6:
        text = gUnknown_0805C0C4;
        break;
    case 4:
        text = gUnknown_0805C0B0;
        break;
    case 9:
        text = gUnknown_0805C0E2;
        break;
    case 8:
        text = gUnknown_0805C0D8;
        break;
    }
    sub_080B832C(task, text);
}

// sub_080B8440 @ 0x080B8440
void sub_080B8440(struct Task *task)
{
    struct ItemTaskData *d = ITEM_DATA(task);

    if ((d->rec->u.value & 0xF0000000) == 0xA0000000)
        task->unk1E = 1;
    else
        task->unk1E = 0;
    d->handle2 = sub_080C4618(1, d->rec->count + 1, 0x50, 5, 0, 0);
    sub_080C51D4(0x73);
}

// Text_CopyToMenuBuffer @ 0x080B8490
/* Copies a message (ended by 0x301) to the gMenuState buffer. */
void Text_CopyToMenuBuffer(const u16 *src)
{
    u16 *dst = gMenuState;
    u32 i;

    dst[0] = src[0];
    if (dst[0] != 0x301)
    {
        i = 0;
        do
        {
            i++;
            dst[i] = src[i];
        } while (src[i] != 0x301);
    }
}

// Treasure_Open @ 0x080B84C8
/* Treasure: 0x8xxxxxxx money, 0x9xxxxxxx Magnetite, otherwise an item ("got <item>"). */
void Treasure_Open(struct Task *task)
{
    struct ItemTaskData *d = ITEM_DATA(task);
    u32 v = ITEM_DATA(task)->rec->u.value;
    u32 kind = v & 0xF0000000;

    task->unk1E = 0;
    if (kind == 0x80000000)
    {
        sub_080C7430();
        task->unk1E = 1;
    }
    else if (kind == 0x90000000)
    {
        sub_080C7648();
        task->unk1E = 2;
    }
    else if ((u8)sub_080C32FC(v) == 1)
    {
        sub_080B832C(task, gUnknown_08003502);
        gScriptItemCheckId = v;
    }
    else
    {
        u16 *buf = gMenuState;

        Text_CopyToMenuBuffer(gUnknown_080033A0);
        buf[1] = ITEM_DATA(task)->rec->u.value;
        sub_080B832C(task, buf);
        if (ITEM_DATA(task)->rec->u.value - 0x12C > 0x2D)
        {
            sub_080C2438(ITEM_DATA(task)->rec->unk8);
            if (ITEM_DATA(task)->rec->unk8 == 0xFF)
                gGameState.unk18D4 = 1;
        }
        sub_080C3328(d->rec->u.id);
    }
}

// sub_080B8584 @ 0x080B8584
void sub_080B8584(struct Task *task)
{
    u32 v = ITEM_DATA(task)->rec->u.value;
    u32 kind = v & 0xF0000000;

    task->unk1E = 0;
    if (kind == 0x80000000)
        sub_080C3114(v & 0x0FFFFFFF);
    else if (kind == 0x90000000)
        sub_080C30AC(v & 0x0FFFFFFF);
}

// sub_080B85C8 @ 0x080B85C8
void sub_080B85C8(struct Task *task)
{
    u32 kind = ITEM_DATA(task)->rec->u.value & 0xF0000000;

    task->unk1E = 0;
    if (kind == 0x80000000)
        sub_080C7414();
    else if (kind == 0x90000000)
        sub_080C762C();
}

// sub_080B85F8 @ 0x080B85F8
#ifdef NONMATCHING
void sub_080B85F8(struct Task *task)
{
    const u16 *text;
    u32 amount;
    u32 v = ITEM_DATA(task)->rec->u.value;

    task->unk1E = 0;
    switch (v & 0xF0000000)
    {
    case 0x80000000:
        amount = v & 0x0FFFFFFF;
        text = gUnknown_080033D6;
        break;
    case 0x90000000:
        amount = v & 0x0FFFFFFF;
        text = gUnknown_080033BA;
        break;
    default:
        return;
    }
    Text_CopyToMenuBuffer(text);
    sub_080B832C(task, gMenuState);
    sub_080C2438(ITEM_DATA(task)->rec->unk8);
    gUnk_0203DB2C = amount;
}
#else
NAKED
void sub_080B85F8(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, lr}\n"
        "    adds r5, r0, #0\n"
        "    ldr r0, [r5, #0x24]\n"
        "    ldr r2, [r0, #4]\n"
        "    movs r1, #0xf0\n"
        "    lsls r1, r1, #0x18\n"
        "    ands r1, r2\n"
        "    movs r0, #0\n"
        "    strh r0, [r5, #0x1e]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #0x18\n"
        "    cmp r1, r0\n"
        "    bne .L080B8624\n"
        "    ldr r4, .L080B861C\n"
        "    ands r4, r2\n"
        "    ldr r0, .L080B8620\n"
        "    b .L080B8632\n"
        "    .byte 0x00, 0x00\n"
        ".L080B861C: .4byte 0x0FFFFFFF\n"
        ".L080B8620: .4byte gUnknown_080033D6\n"
        ".L080B8624:\n"
        "    movs r0, #0x90\n"
        "    lsls r0, r0, #0x18\n"
        "    cmp r1, r0\n"
        "    bne .L080B864A\n"
        "    ldr r4, .L080B8650\n"
        "    ands r4, r2\n"
        "    ldr r0, .L080B8654\n"
        ".L080B8632:\n"
        "    bl Text_CopyToMenuBuffer\n"
        "    ldr r1, .L080B8658\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080B832C\n"
        "    ldr r0, [r5, #0x24]\n"
        "    ldrh r0, [r0, #8]\n"
        "    bl sub_080C2438\n"
        "    ldr r0, .L080B865C\n"
        "    str r4, [r0]\n"
        ".L080B864A:\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080B8650: .4byte 0x0FFFFFFF\n"
        ".L080B8654: .4byte gUnknown_080033BA\n"
        ".L080B8658: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L080B865C: .4byte 0x0203DB2C @ EWRAM+0x3DB2C\n"
    );
}
#endif

// Spring_GetKindAt @ 0x080B8660
/* Kind of healing spring at the player's world position (table gUnknown_08164A7C), 0 if
   none. */
u16 Spring_GetKindAt(void)
{
    const u16 *p = gUnknown_08164A7C;
    u16 x, y;

    sub_080C1F50(gFieldState.unk12, gFieldState.unk14, &x, &y);
    for (; p[0] != 0xFF; p += 4)
    {
        if (p[0] == x && p[1] == y)
            return p[2];
    }
    return 0;
}

// Spring_HealMember @ 0x080B86B0
/* Heals party member `slot` at a spring: 0 restores HP/4, 1 HP/2 (front three only), 2 and 3
   cure a status. In case 2 the cure path calls sub_080C8490 twice and the result is 1 even
   when nothing was cured. */
#ifdef NONMATCHING
void Spring_HealMember(struct Task *task, u32 slot)
{
    s8 id;
    s32 ok;
    s32 n;

    sub_080C2438(ITEM_DATA(task)->rec->unk8);
    task->result = 0;
    id = gGameState.party[slot];
    if (id == -1)
        return;
    switch (Spring_GetKindAt())
    {
    case 0:
        ok = sub_080C09B0(id);
        if (ok == 1 && sub_080C0830(id) == 0)
        {
            n = sub_080F401C(id) >> 2;
            if (n == 0)
                n = 1;
            sub_080C0C70(id, n);
            ITEM_DATA(task)->healed[slot] = n;
            task->result = ok;
            sub_080C8490(slot);
        }
        break;
    case 1:
        if (slot > 2)
            break;
        ok = sub_080C09B0(id);
        if (ok == 1 && sub_080C0830(id) == 0)
        {
            n = sub_080F401C(id) >> 1;
            if (n == 0)
                n = 1;
            sub_080C0C70(id, n);
            ITEM_DATA(task)->healed[slot] = n;
            task->result = ok;
            sub_080C8490(slot);
        }
        break;
    case 2:
        if (slot > 2)
            break;
        if ((n = sub_080C09B0(id)) == 1 && sub_080C0830(id) == 0)
        {
            sub_080C08F8(id, 4);
            task->result = n;
            sub_080C8490(slot);
        }
        task->result = 1;
        sub_080C8490(slot);
        break;
    case 3:
        if (slot <= 2)
            break;
        if ((n = sub_080C09B0(id)) == 1 && sub_080C0830(id) == 0)
        {
            sub_080C08F8(id, 2);
            task->result = n;
            sub_080C8490(slot);
        }
        break;
    }
}
#else
NAKED
void Spring_HealMember(struct Task *task, u32 slot)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    adds r7, r0, #0\n"
        "    adds r6, r1, #0\n"
        "    ldr r0, [r7, #0x24]\n"
        "    ldrh r0, [r0, #8]\n"
        "    bl sub_080C2438\n"
        "    movs r0, #0\n"
        "    strh r0, [r7, #0x1c]\n"
        "    ldr r0, .L080B86F8\n"
        "    movs r1, #0xa2\n"
        "    lsls r1, r1, #4\n"
        "    adds r0, r0, r1\n"
        "    adds r2, r6, r0\n"
        "    movs r1, #0\n"
        "    ldrsb r1, [r2, r1]\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r1, r0\n"
        "    bne .L080B86DE\n"
        "    b .L080B87E0\n"
        ".L080B86DE:\n"
        "    adds r5, r1, #0\n"
        "    bl Spring_GetKindAt\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    beq .L080B8740\n"
        "    cmp r0, #1\n"
        "    bgt .L080B86FC\n"
        "    cmp r0, #0\n"
        "    beq .L080B8706\n"
        "    b .L080B87E0\n"
        "    .byte 0x00, 0x00\n"
        ".L080B86F8: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080B86FC:\n"
        "    cmp r0, #2\n"
        "    beq .L080B8780\n"
        "    cmp r0, #3\n"
        "    beq .L080B87B6\n"
        "    b .L080B87E0\n"
        ".L080B8706:\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080C09B0\n"
        "    mov r8, r0\n"
        "    cmp r0, #1\n"
        "    bne .L080B87E0\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080C0830\n"
        "    cmp r0, #0\n"
        "    bne .L080B87E0\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080F401C\n"
        "    asrs r4, r0, #2\n"
        "    cmp r4, #0\n"
        "    bne .L080B872A\n"
        "    movs r4, #1\n"
        ".L080B872A:\n"
        "    adds r0, r5, #0\n"
        "    adds r1, r4, #0\n"
        "    bl sub_080C0C70\n"
        "    lsls r1, r6, #1\n"
        "    adds r0, r7, #0\n"
        "    adds r0, #0x3c\n"
        "    adds r0, r0, r1\n"
        "    strh r4, [r0]\n"
        "    mov r0, r8\n"
        "    b .L080B87AC\n"
        ".L080B8740:\n"
        "    cmp r6, #2\n"
        "    bhi .L080B87E0\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080C09B0\n"
        "    mov r8, r0\n"
        "    cmp r0, #1\n"
        "    bne .L080B87E0\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080C0830\n"
        "    cmp r0, #0\n"
        "    bne .L080B87E0\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080F401C\n"
        "    asrs r4, r0, #1\n"
        "    cmp r4, #0\n"
        "    bne .L080B8768\n"
        "    movs r4, #1\n"
        ".L080B8768:\n"
        "    adds r0, r5, #0\n"
        "    adds r1, r4, #0\n"
        "    bl sub_080C0C70\n"
        "    lsls r1, r6, #1\n"
        "    adds r0, r7, #0\n"
        "    adds r0, #0x3c\n"
        "    adds r0, r0, r1\n"
        "    strh r4, [r0]\n"
        "    mov r1, r8\n"
        "    strh r1, [r7, #0x1c]\n"
        "    b .L080B87AE\n"
        ".L080B8780:\n"
        "    cmp r6, #2\n"
        "    bhi .L080B87E0\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080C09B0\n"
        "    adds r4, r0, #0\n"
        "    cmp r4, #1\n"
        "    bne .L080B87AA\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080C0830\n"
        "    cmp r0, #0\n"
        "    bne .L080B87AA\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #4\n"
        "    bl sub_080C08F8\n"
        "    strh r4, [r7, #0x1c]\n"
        "    adds r0, r6, #0\n"
        "    bl sub_080C8490\n"
        ".L080B87AA:\n"
        "    movs r0, #1\n"
        ".L080B87AC:\n"
        "    strh r0, [r7, #0x1c]\n"
        ".L080B87AE:\n"
        "    adds r0, r6, #0\n"
        "    bl sub_080C8490\n"
        "    b .L080B87E0\n"
        ".L080B87B6:\n"
        "    cmp r6, #2\n"
        "    bls .L080B87E0\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080C09B0\n"
        "    adds r4, r0, #0\n"
        "    cmp r4, #1\n"
        "    bne .L080B87E0\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080C0830\n"
        "    cmp r0, #0\n"
        "    bne .L080B87E0\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #2\n"
        "    bl sub_080C08F8\n"
        "    strh r4, [r7, #0x1c]\n"
        "    adds r0, r6, #0\n"
        "    bl sub_080C8490\n"
        ".L080B87E0:\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// sub_080B87EC @ 0x080B87EC
void sub_080B87EC(struct Task *task, u32 slot)
{
    struct ItemTaskData *d = ITEM_DATA(task);
    const u8 *e = sub_080C0148(slot);

    switch (e[0xC])
    {
    case 0:
        sub_080B832C(task, gUnknown_08003432);
        break;
    case 1:
        sub_080B832C(task, gUnknown_08003452);
        break;
    case 2:
        sub_080B832C(task, gUnknown_08003472);
        break;
    case 3:
        sub_080B832C(task, gUnknown_08003492);
        break;
    default:
        sub_080B832C(task, gUnknown_080034B2);
        gUnk_0203DB28 = *(const u16 *)(e + 0x12);
        break;
    }
    gUnk_0203DB2C = d->healed[slot];
}

// sub_080B8874 @ 0x080B8874
#ifdef NONMATCHING
void sub_080B8874(struct Task *task, u32 step, u32 a, u32 b)
{
    struct ItemTaskData *d = ITEM_DATA(task);

    if (step == 0)
    {
        d->unk0C = sub_080B8AE0(a, b);
    }
    else
    {
        s32 r = sub_080B8B08(d->unk0C);

        if (r != 1)
            r = 0;
        task->result = r;
    }
}
#else
NAKED
void sub_080B8874(struct Task *task, u32 step, u32 a, u32 b)
{
    asm_unified(
        ".L080B8874:\n"
        "    push {r4, r5, lr}\n"
        "    adds r4, r0, #0\n"
        "    adds r5, r4, #0\n"
        "    adds r5, #0x24\n"
        "    cmp r1, #0\n"
        "    bne .L080B8890\n"
        "    lsls r0, r2, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    lsls r1, r3, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    bl sub_080B8AE0\n"
        "    str r0, [r5, #0xc]\n"
        "    b .L080B889E\n"
        ".L080B8890:\n"
        "    ldr r0, [r5, #0xc]\n"
        "    bl sub_080B8B08\n"
        "    cmp r0, #1\n"
        "    beq .L080B889C\n"
        "    movs r0, #0\n"
        ".L080B889C:\n"
        "    strh r0, [r4, #0x1c]\n"
        ".L080B889E:\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

// sub_080B88A4 @ 0x080B88A4
void sub_080B88A4(struct Task *task)
{
    struct ItemTaskData *d = ITEM_DATA(task);

    d->unk10 = (const u16 *)sub_080C4618(5, 0xF5, 0x50, 0xFFED, 0, 0);
}

// sub_080B88CC @ 0x080B88CC
void sub_080B88CC(struct Task *task)
{
    if (*ITEM_DATA(task)->unk10 == 0)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080B88E4 @ 0x080B88E4
void sub_080B88E4(struct Task *task)
{
    struct ItemTaskData *d = ITEM_DATA(task);

    if (d->handle != 0)
    {
        sub_080C48F0(d->handle, 0);
        d->handle = 0;
    }
}

// sub_080B8900 @ 0x080B8900
void sub_080B8900(struct Task *task)
{
    if (ITEM_DATA(task)->handle2 != 0)
        sub_080C48F0(ITEM_DATA(task)->handle2, 0);
    sub_080C3818(1);
    Field_SetState(1);
}

// sub_080B8920 @ 0x080B8920
/* 1 when any side of the player's square is open. */
void sub_080B8920(struct Task *task)
{
    if (View_GetWall(0, 0, 0) == 0 || View_GetWall(1, 0, 0) == 0 || View_GetWall(3, 0, 0) == 0
        || View_GetWall(2, 0, 0) == 0)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080B896C @ 0x080B896C
void sub_080B896C(struct Task *task)
{
    if (Palette_IsBg13Black() == 0)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080B8988 @ 0x080B8988
void sub_080B8988(void)
{
    Field_SetState(0x1A);
}

// Treasure_StartTask @ 0x080B8994
/* Starts the treasure task for record `rec`. */
struct Task *Treasure_StartTask(const struct TreasureRec *rec)
{
    struct Task *task = Task_Create(gUnknown_08164AD4, 0xFFFF);

    ITEM_DATA(task)->rec = rec;
    return task;
}
