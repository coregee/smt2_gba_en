#include "global.h"
#include "extras.h"

// sub_080DBCAC @ 0x080DBCAC
void sub_080DBCAC(struct Task *task)
{
    struct Task *parent = Task_GetParent(task);

    Text_DrawSpriteString(gUnknown_0858329C[parent->data.h[0]], 0, 0, 0x14, 0x64, 0xC);
}

/* Compendium list: six names (8 glyphs each, "?" entries for demons not met), the
   met/registered counts and the scroll arrows. */
// sub_080DBCDC @ 0x080DBCDC
#ifdef NONMATCHING
void sub_080DBCDC(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    u16 y = 0x10;
    u16 count = Dict_CountListed();
    u16 x = 0x5C;
    u32 row, i;

    if (d->unk10 != 0)
        Sprite_Draw(gUnknown_0800853C, 0, 7, 0, 0x100, 0x5A, d->unk0C * 12 + 17);
    if (gDict.unk3E == 1)
    {
        for (row = 0; row < 6; row++)
        {
            u16 v = gStatusList[d->unk0E + row];

            if (v != 0xFFFF)
            {
                u16 id = v & 0x7FFF;
                const u16 *name;

                if (sub_080C2644(id))
                    name = (const u16 *)(Demon_GetRecord(id) + 0x22);
                else
                    name = gUnknown_0858325A;
                for (i = 0; i < 8; i++)
                    FontSprite_DrawGlyph(name[i], 0, 0, x + i * 12, y + row * 12);
            }
        }
        if (d->unk0E != 0)
            sub_080C4A4C(0, 0, x + 0x60, y - 4);
        if (d->unk0E + 6 <= count - 1)
            sub_080C4AB0(0, 0, x + 0x60, y + 0x4C);
    }
    else
    {
        Text_DrawSpriteString(gUnknown_0800974E, 0, 0, x, y, 12);
    }
    Sprite_DrawFraction(sub_080DB8D4(), Dict_CountListed(), 0x81, 0x6A);
    if (d->unk10 == 0)
        Sprite_Draw(d->spr18, 0, 7, 0, 0x100, 0x10, d->cursor * 11 + 14);
    Sprite_Draw(d->spr14, 0, 7, 0, 0, 0x10, 0x10);
}
#else
NAKED
void sub_080DBCDC(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x10\n"
        "    adds r0, #0x24\n"
        "    mov sb, r0\n"
        "    movs r0, #0x10\n"
        "    mov sl, r0\n"
        "    bl Dict_CountListed\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    mov r1, sb\n"
        "    ldrh r0, [r1, #0x10]\n"
        "    cmp r0, #0\n"
        "    beq .L080DBD2A\n"
        "    ldr r0, .L080DBD70\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #1\n"
        "    str r1, [sp]\n"
        "    movs r1, #0x5a\n"
        "    str r1, [sp, #4]\n"
        "    mov r1, sb\n"
        "    ldrh r2, [r1, #0xc]\n"
        "    lsls r1, r2, #1\n"
        "    adds r1, r1, r2\n"
        "    lsls r1, r1, #0x12\n"
        "    movs r2, #0x88\n"
        "    lsls r2, r2, #0xd\n"
        "    adds r1, r1, r2\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #7\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L080DBD2A:\n"
        "    ldr r0, .L080DBD74\n"
        "    ldrh r0, [r0, #0x3e]\n"
        "    cmp r0, #1\n"
        "    bne .L080DBE00\n"
        "    movs r5, #0\n"
        "    subs r4, #1\n"
        "    str r4, [sp, #0xc]\n"
        ".L080DBD38:\n"
        "    mov r1, sb\n"
        "    ldrh r0, [r1, #0xe]\n"
        "    adds r0, r0, r5\n"
        "    lsls r0, r0, #1\n"
        "    ldr r2, .L080DBD78\n"
        "    adds r0, r0, r2\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L080DBD7C\n"
        "    adds r2, r5, #1\n"
        "    mov r8, r2\n"
        "    cmp r1, r0\n"
        "    beq .L080DBDBA\n"
        "    ldr r2, .L080DBD80\n"
        "    adds r0, r2, #0\n"
        "    adds r4, r0, #0\n"
        "    ands r4, r1\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080C2644\n"
        "    cmp r0, #0\n"
        "    beq .L080DBD84\n"
        "    adds r0, r4, #0\n"
        "    bl Demon_GetRecord\n"
        "    adds r1, r0, #0\n"
        "    adds r1, #0x22\n"
        "    b .L080DBD86\n"
        "    .byte 0x00, 0x00\n"
        ".L080DBD70: .4byte gUnknown_0800853C\n"
        ".L080DBD74: .4byte 0x020399E0 @ EWRAM+0x399E0\n"
        ".L080DBD78: .4byte 0x0203B554 @ EWRAM+0x3B554\n"
        ".L080DBD7C: .4byte 0x0000FFFF\n"
        ".L080DBD80: .4byte 0x00007FFF\n"
        ".L080DBD84:\n"
        "    ldr r1, .L080DBDFC\n"
        ".L080DBD86:\n"
        "    movs r6, #0\n"
        "    lsls r0, r5, #1\n"
        "    adds r2, r5, #1\n"
        "    mov r8, r2\n"
        "    adds r0, r0, r5\n"
        "    lsls r0, r0, #2\n"
        "    add r0, sl\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    movs r0, #0x5c\n"
        "    lsls r5, r0, #0x10\n"
        "    adds r4, r1, #0\n"
        ".L080DBD9E:\n"
        "    ldrh r0, [r4]\n"
        "    lsrs r3, r5, #0x10\n"
        "    str r7, [sp]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    bl FontSprite_DrawGlyph\n"
        "    movs r1, #0xc0\n"
        "    lsls r1, r1, #0xc\n"
        "    adds r5, r5, r1\n"
        "    adds r4, #2\n"
        "    adds r6, #1\n"
        "    cmp r6, #7\n"
        "    bls .L080DBD9E\n"
        ".L080DBDBA:\n"
        "    mov r5, r8\n"
        "    cmp r5, #5\n"
        "    bls .L080DBD38\n"
        "    mov r2, sb\n"
        "    ldrh r0, [r2, #0xe]\n"
        "    cmp r0, #0\n"
        "    beq .L080DBDDC\n"
        "    movs r2, #0x5c\n"
        "    adds r2, #0x60\n"
        "    mov r3, sl\n"
        "    subs r3, #4\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    bl sub_080C4A4C\n"
        ".L080DBDDC:\n"
        "    mov r1, sb\n"
        "    ldrh r0, [r1, #0xe]\n"
        "    adds r0, #6\n"
        "    ldr r2, [sp, #0xc]\n"
        "    cmp r0, r2\n"
        "    bgt .L080DBE14\n"
        "    movs r2, #0x5c\n"
        "    adds r2, #0x60\n"
        "    mov r3, sl\n"
        "    adds r3, #0x4c\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    bl sub_080C4AB0\n"
        "    b .L080DBE14\n"
        "    .byte 0x00, 0x00\n"
        ".L080DBDFC: .4byte gUnknown_0858325A\n"
        ".L080DBE00:\n"
        "    ldr r0, .L080DBE80\n"
        "    mov r1, sl\n"
        "    str r1, [sp]\n"
        "    movs r1, #0xc\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0x5c\n"
        "    bl Text_DrawSpriteString\n"
        ".L080DBE14:\n"
        "    bl sub_080DB8D4\n"
        "    adds r4, r0, #0\n"
        "    bl Dict_CountListed\n"
        "    adds r1, r0, #0\n"
        "    movs r2, #0x81\n"
        "    movs r3, #0x6a\n"
        "    adds r0, r4, #0\n"
        "    bl Sprite_DrawFraction\n"
        "    mov r2, sb\n"
        "    ldrh r0, [r2, #0x10]\n"
        "    cmp r0, #0\n"
        "    bne .L080DBE56\n"
        "    ldr r0, [r2, #0x18]\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #1\n"
        "    str r1, [sp]\n"
        "    movs r1, #0x10\n"
        "    str r1, [sp, #4]\n"
        "    ldrh r2, [r2]\n"
        "    movs r1, #0xb\n"
        "    muls r1, r2, r1\n"
        "    adds r1, #0xe\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #7\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L080DBE56:\n"
        "    mov r1, sb\n"
        "    ldr r0, [r1, #0x14]\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    movs r1, #0x10\n"
        "    str r1, [sp, #4]\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #7\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    add sp, #0x10\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080DBE80: .4byte gUnknown_0800974E\n"
    );
}
#endif

// sub_080DBE84 @ 0x080DBE84
void sub_080DBE84(struct Task *task)
{
    struct Task *parent = Task_GetParent(task);

    sub_080C3818(1);
    parent->wait = 1;
}

// sub_080DBE9C @ 0x080DBE9C
void sub_080DBE9C(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    u16 x = 0x54;
    u16 y = 0x10;
    u16 count = 43;
    u32 row, i;

    Sprite_Draw(gUnknown_0800853C, 0, 7, 0, 0x100, 0x52, task->data.h[0] * 12 + 17);
    for (row = 0; row < 6; row++)
    {
        u16 race = d->unk02 + row;
        const u16 *name;

        if (race > 0x28)
            race++;
        name = Race_GetName(race);
        for (i = 0; i < 8; i++)
            FontSprite_DrawGlyph(name[i], 0, 0, x + i * 12, y + row * 12);
    }
    if (d->unk02 != 0)
        sub_080C4A4C(0, 0, x + 0x60, y - 4);
    if (d->unk02 + 6 <= count - 1)
        sub_080C4AB0(0, 0, x + 0x60, y + 0x4C);
}

/* Generic scrolling list input: 6 visible rows, d->unk02 is the first row shown. */
// sub_080DBF7C @ 0x080DBF7C
#ifdef NONMATCHING
void sub_080DBF7C(struct Task *task, u32 n)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    u16 count = n;
    u16 rows = count;

    if (count > 5)
        rows = 6;
    task->result = 0;
    task->unk1E = 0;
    if (gKeysNew & 1)
    {
        task->unk1E = task->data.h[0] + 1;
        Sound_Play(0x65);
        task->result = 1;
    }
    else if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        task->result = 1;
    }
    else if (gRepeatedKeys & 0x40)
    {
        if (task->data.h[0] != 0)
        {
            task->data.h[0]--;
            Sound_Play(0x64);
        }
        else if (d->unk02 != 0)
        {
            d->unk02--;
            Sound_Play(0x64);
        }
    }
    else
    {
        u16 down = gRepeatedKeys & 0x80;

        if (down)
        {
            if (task->data.h[0] != rows - 1)
            {
                task->data.h[0]++;
                Sound_Play(0x64);
            }
            else if (task->data.h[0] == 5 && task->data.h[0] + d->unk02 + 1 <= count - 1)
            {
                d->unk02++;
                Sound_Play(0x64);
            }
        }
        else if ((gRepeatedKeys & 0x200) && count > 6)
        {
            u16 cursor = task->data.h[0];
            u16 top = d->unk02;

            u32 t = cursor;

            if (t != 0)
            {
                task->data.h[0] = down;
            }
            else
            {
                if (top > 4)
                    t = top - 5;
                d->unk02 = t;
            }
            if (cursor != d->cursor || top != d->unk02)
                Sound_Play(0x64);
        }
        else if ((gRepeatedKeys & 0x100) && count > 6)
        {
            u16 cursor = d->cursor;
            u16 top = d->unk02;

            if (cursor != 5)
                d->cursor = 5;
            else if (d->cursor + d->unk02 + 6 < count - 1)
                d->unk02 = top + 6;
            else
                d->unk02 = count - 6;
            if (cursor != d->cursor || top != d->unk02)
                Sound_Play(0x64);
        }
    }
}
#else
NAKED
void sub_080DBF7C(struct Task *task, u32 n)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    adds r4, r0, #0\n"
        "    adds r2, r4, #0\n"
        "    adds r2, #0x24\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r5, r1, #0x10\n"
        "    adds r7, r5, #0\n"
        "    cmp r5, #5\n"
        "    bls .L080DBF90\n"
        "    movs r7, #6\n"
        ".L080DBF90:\n"
        "    movs r0, #0\n"
        "    strh r0, [r4, #0x1c]\n"
        "    strh r0, [r4, #0x1e]\n"
        "    ldr r3, .L080DBFB0\n"
        "    ldrh r1, [r3]\n"
        "    movs r6, #1\n"
        "    adds r0, r6, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080DBFB4\n"
        "    ldrh r0, [r4, #0x24]\n"
        "    adds r0, #1\n"
        "    strh r0, [r4, #0x1e]\n"
        "    movs r0, #0x65\n"
        "    b .L080DBFC0\n"
        "    .byte 0x00, 0x00\n"
        ".L080DBFB0: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L080DBFB4:\n"
        "    ldrh r1, [r3]\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080DBFC8\n"
        "    movs r0, #0x66\n"
        ".L080DBFC0:\n"
        "    bl Sound_Play\n"
        "    strh r6, [r4, #0x1c]\n"
        "    b .L080DC09A\n"
        ".L080DBFC8:\n"
        "    ldr r1, .L080DBFE0\n"
        "    ldrh r3, [r1]\n"
        "    movs r0, #0x40\n"
        "    ands r0, r3\n"
        "    cmp r0, #0\n"
        "    beq .L080DBFF0\n"
        "    ldrh r0, [r4, #0x24]\n"
        "    cmp r0, #0\n"
        "    beq .L080DBFE4\n"
        "    subs r0, #1\n"
        "    strh r0, [r4, #0x24]\n"
        "    b .L080DC050\n"
        ".L080DBFE0: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L080DBFE4:\n"
        "    ldrh r0, [r2, #2]\n"
        "    cmp r0, #0\n"
        "    beq .L080DC09A\n"
        "    subs r0, #1\n"
        "    strh r0, [r2, #2]\n"
        "    b .L080DC050\n"
        ".L080DBFF0:\n"
        "    movs r0, #0x80\n"
        "    ands r0, r3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r6, #0\n"
        "    beq .L080DC020\n"
        "    ldrh r1, [r4, #0x24]\n"
        "    subs r0, r7, #1\n"
        "    cmp r1, r0\n"
        "    beq .L080DC00A\n"
        "    adds r0, r1, #1\n"
        "    strh r0, [r4, #0x24]\n"
        "    b .L080DC050\n"
        ".L080DC00A:\n"
        "    cmp r1, #5\n"
        "    bne .L080DC09A\n"
        "    ldrh r3, [r2, #2]\n"
        "    adds r0, r1, r3\n"
        "    adds r0, #1\n"
        "    subs r1, r5, #1\n"
        "    cmp r0, r1\n"
        "    bgt .L080DC09A\n"
        "    adds r0, r3, #1\n"
        "    strh r0, [r2, #2]\n"
        "    b .L080DC050\n"
        ".L080DC020:\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #2\n"
        "    ands r0, r3\n"
        "    cmp r0, #0\n"
        "    beq .L080DC058\n"
        "    cmp r5, #6\n"
        "    bls .L080DC058\n"
        "    ldrh r3, [r4, #0x24]\n"
        "    ldrh r1, [r2, #2]\n"
        "    adds r0, r3, #0\n"
        "    cmp r0, #0\n"
        "    beq .L080DC03C\n"
        "    strh r6, [r4, #0x24]\n"
        "    b .L080DC044\n"
        ".L080DC03C:\n"
        "    cmp r1, #4\n"
        "    bls .L080DC042\n"
        "    subs r0, r1, #5\n"
        ".L080DC042:\n"
        "    strh r0, [r2, #2]\n"
        ".L080DC044:\n"
        "    ldrh r0, [r2]\n"
        "    cmp r3, r0\n"
        "    bne .L080DC050\n"
        "    ldrh r2, [r2, #2]\n"
        "    cmp r1, r2\n"
        "    beq .L080DC09A\n"
        ".L080DC050:\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        "    b .L080DC09A\n"
        ".L080DC058:\n"
        "    ldrh r1, [r1]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080DC09A\n"
        "    cmp r5, #6\n"
        "    bls .L080DC09A\n"
        "    ldrh r3, [r2]\n"
        "    ldrh r4, [r2, #2]\n"
        "    cmp r3, #5\n"
        "    beq .L080DC076\n"
        "    movs r0, #5\n"
        "    strh r0, [r2]\n"
        "    b .L080DC088\n"
        ".L080DC076:\n"
        "    adds r0, r3, r4\n"
        "    adds r0, #6\n"
        "    subs r1, r5, #1\n"
        "    cmp r0, r1\n"
        "    bge .L080DC084\n"
        "    adds r0, r4, #6\n"
        "    b .L080DC086\n"
        ".L080DC084:\n"
        "    subs r0, r5, #6\n"
        ".L080DC086:\n"
        "    strh r0, [r2, #2]\n"
        ".L080DC088:\n"
        "    ldrh r0, [r2]\n"
        "    cmp r3, r0\n"
        "    bne .L080DC094\n"
        "    ldrh r2, [r2, #2]\n"
        "    cmp r4, r2\n"
        "    beq .L080DC09A\n"
        ".L080DC094:\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        ".L080DC09A:\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

// sub_080DC0A0 @ 0x080DC0A0
void sub_080DC0A0(struct Task *task, u32 mode)
{
    Dict_BuildList(task, mode, task->data.h[0] + task->data.h[1]);
}

// sub_080DC0B0 @ 0x080DC0B0
void sub_080DC0B0(struct Task *task)
{
    struct Task *parent = Task_GetParent(task);
    struct Task *grandparent = Task_GetParent(parent);

    if (task->unk06 == 0)
    {
        Task_Create(gUnknown_08583CA0, grandparent->id);
        sub_080D9B34(parent);
        Task_End(parent);
        task->result = 1;
    }
    else
    {
        task->result = 0;
    }
}

/* List of up to 3-glyph names from gUnknown_0858367C (0x0301 ends a name); 10 entries. */
// sub_080DC0F0 @ 0x080DC0F0
void sub_080DC0F0(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    u16 x = 0x54;
    u16 y = 0x10;
    u16 count = 10;
    u32 row;

    Sprite_Draw(gUnknown_0800853C, 0, 7, 0, 0x100, 0x52, task->data.h[0] * 12 + 17);
    for (row = 0; row < 6; row++)
    {
        const u16 *name = gUnknown_0858367C[d->unk02 + row];
        u32 i;

        for (i = 0; name[i] != 0x301; )
        {
            FontSprite_DrawGlyph(name[i], 0, 0, x + i * 12, y + row * 12);
            i++;
            if (i > 2)
                break;
        }
    }
    if (d->unk02 != 0)
        sub_080C4A4C(0, 0, x + 0x60, y - 4);
    if (d->unk02 + 6 <= count - 1)
        sub_080C4AB0(0, 0, x + 0x60, y + 0x4C);
}

/* Eight-glyph names from gUnknown_08583788; 11 entries. */
// sub_080DC1D8 @ 0x080DC1D8
void sub_080DC1D8(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    u16 x = 0x54;
    u16 y = 0x10;
    u16 count = 11;
    u32 row, i;

    Sprite_Draw(gUnknown_0800853C, 0, 7, 0, 0x100, 0x52, task->data.h[0] * 12 + 17);
    for (row = 0; row < 6; row++)
    {
        const u16 *name = gUnknown_08583788[d->unk02 + row];

        for (i = 0; i < 8; i++)
            FontSprite_DrawGlyph(name[i], 0, 0, x + i * 12, y + row * 12);
    }
    if (d->unk02 != 0)
        sub_080C4A4C(0, 0, x + 0x60, y - 4);
    if (d->unk02 + 6 <= count - 1)
        sub_080C4AB0(0, 0, x + 0x60, y + 0x4C);
}
