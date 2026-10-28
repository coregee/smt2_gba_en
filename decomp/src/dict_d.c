#include "global.h"
#include "extras.h"

/* Compendium list (fusion variant): entries with bit 15 set are drawn tinted. */
// sub_080DC2B0 @ 0x080DC2B0
#ifdef NONMATCHING
void sub_080DC2B0(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    u16 count = Dict_CountListed();
    u16 x = 0x54;
    u16 y = 0x10;
    u32 row, i;

    Sprite_Draw(gUnknown_0800853C, 0, 7, 0, 0x100, 0x52, task->data.h[0] * 12 + 17);
    if (gDict.unk3E == 1)
    {
        for (row = 0; row < 6; row++)
        {
            u16 v = gUnk_0203B554[d->unk02 + row];

            if (v != 0xFFFF)
            {
                u16 id = v & 0x7FFF;
                const u16 *name;

                if (sub_080C2644(id))
                    name = (const u16 *)(Demon_GetRecord(id) + 0x22);
                else
                    name = gUnknown_0858325A;
                v &= 0x8000;
                for (i = 0; i < 8; i++)
                {
                    if (v == 0)
                        FontSprite_DrawGlyph(name[i], 0, 0, x + i * 12, y + row * 12);
                    else
                        FontSprite_DrawGlyphTinted(name[i], 0, 0, x + i * 12, y + row * 12, 1);
                }
            }
        }
        if (d->unk02 != 0)
            sub_080C4A4C(0, 0, x + 0x60, y - 4);
        if (d->unk02 + 6 <= count - 1)
            sub_080C4AB0(0, 0, x + 0x60, y + 0x4C);
    }
    else
    {
        Text_DrawSpriteString(gUnknown_0800974E, 0, 0, x, y, 12);
    }
}
#else
NAKED
void sub_080DC2B0(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x10\n"
        "    adds r4, r0, #0\n"
        "    movs r0, #0x24\n"
        "    adds r0, r0, r4\n"
        "    mov sl, r0\n"
        "    bl Dict_CountListed\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldr r0, .L080DC338\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #1\n"
        "    str r1, [sp]\n"
        "    movs r1, #0x52\n"
        "    str r1, [sp, #4]\n"
        "    ldrh r2, [r4, #0x24]\n"
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
        "    ldr r0, .L080DC33C\n"
        "    ldrh r0, [r0, #0x3e]\n"
        "    cmp r0, #1\n"
        "    bne .L080DC3EE\n"
        "    movs r5, #0\n"
        "    subs r6, #1\n"
        "    str r6, [sp, #0xc]\n"
        ".L080DC302:\n"
        "    mov r1, sl\n"
        "    ldrh r0, [r1, #2]\n"
        "    adds r0, r0, r5\n"
        "    lsls r0, r0, #1\n"
        "    ldr r2, .L080DC340\n"
        "    adds r0, r0, r2\n"
        "    ldrh r6, [r0]\n"
        "    ldr r0, .L080DC344\n"
        "    adds r1, r5, #1\n"
        "    mov sb, r1\n"
        "    cmp r6, r0\n"
        "    beq .L080DC3AE\n"
        "    ldr r2, .L080DC348\n"
        "    adds r0, r2, #0\n"
        "    adds r4, r6, #0\n"
        "    ands r4, r0\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080C2644\n"
        "    cmp r0, #0\n"
        "    beq .L080DC34C\n"
        "    adds r0, r4, #0\n"
        "    bl Demon_GetRecord\n"
        "    adds r0, #0x22\n"
        "    b .L080DC34E\n"
        "    .byte 0x00, 0x00\n"
        ".L080DC338: .4byte gUnknown_0800853C\n"
        ".L080DC33C: .4byte 0x020399E0 @ EWRAM+0x399E0\n"
        ".L080DC340: .4byte 0x0203B554 @ EWRAM+0x3B554\n"
        ".L080DC344: .4byte 0x0000FFFF\n"
        ".L080DC348: .4byte 0x00007FFF\n"
        ".L080DC34C:\n"
        "    ldr r0, .L080DC388\n"
        ".L080DC34E:\n"
        "    mov r8, r0\n"
        "    lsls r0, r5, #1\n"
        "    adds r1, r5, #1\n"
        "    mov sb, r1\n"
        "    adds r0, r0, r5\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, #0x10\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    movs r2, #0x54\n"
        "    lsls r5, r2, #0x10\n"
        "    mov r4, r8\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    adds r0, r1, #0\n"
        "    ands r6, r0\n"
        "    lsls r0, r6, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        ".L080DC372:\n"
        "    cmp r6, #0\n"
        "    bne .L080DC38C\n"
        "    ldrh r0, [r4]\n"
        "    lsrs r3, r5, #0x10\n"
        "    str r7, [sp]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    bl FontSprite_DrawGlyph\n"
        "    b .L080DC39E\n"
        "    .byte 0x00, 0x00\n"
        ".L080DC388: .4byte gUnknown_0858325A\n"
        ".L080DC38C:\n"
        "    ldrh r0, [r4]\n"
        "    lsrs r3, r5, #0x10\n"
        "    str r7, [sp]\n"
        "    movs r1, #1\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    bl FontSprite_DrawGlyphTinted\n"
        ".L080DC39E:\n"
        "    movs r2, #0xc0\n"
        "    lsls r2, r2, #0xc\n"
        "    adds r5, r5, r2\n"
        "    adds r4, #2\n"
        "    mov r0, r8\n"
        "    adds r0, #0xe\n"
        "    cmp r4, r0\n"
        "    bls .L080DC372\n"
        ".L080DC3AE:\n"
        "    mov r5, sb\n"
        "    cmp r5, #5\n"
        "    bls .L080DC302\n"
        "    mov r1, sl\n"
        "    ldrh r0, [r1, #2]\n"
        "    cmp r0, #0\n"
        "    beq .L080DC3D0\n"
        "    movs r2, #0x54\n"
        "    adds r2, #0x60\n"
        "    movs r3, #0x10\n"
        "    subs r3, #4\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    bl sub_080C4A4C\n"
        ".L080DC3D0:\n"
        "    mov r2, sl\n"
        "    ldrh r0, [r2, #2]\n"
        "    adds r0, #6\n"
        "    ldr r1, [sp, #0xc]\n"
        "    cmp r0, r1\n"
        "    bgt .L080DC402\n"
        "    movs r2, #0x54\n"
        "    adds r2, #0x60\n"
        "    movs r3, #0x10\n"
        "    adds r3, #0x4c\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    bl sub_080C4AB0\n"
        "    b .L080DC402\n"
        ".L080DC3EE:\n"
        "    ldr r0, .L080DC414\n"
        "    movs r2, #0x10\n"
        "    str r2, [sp]\n"
        "    movs r1, #0xc\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0x54\n"
        "    bl Text_DrawSpriteString\n"
        ".L080DC402:\n"
        "    add sp, #0x10\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080DC414: .4byte gUnknown_0800974E\n"
    );
}
#endif

/* Remembers the list position and shows the selected demon. */
// sub_080DC418 @ 0x080DC418
void sub_080DC418(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    u16 *list = gUnk_0203B554;
    struct C0d9Dict *dict = &gDict;
    u16 cursor = task->data.h[0];
    u16 top = d->unk02;

    dict->unk3C = cursor + top;
    dict->unk44 = cursor;
    dict->unk46 = top;
    dict->selected = list[task->data.h[0] + d->unk02] & 0x7FFF;
    sub_080DB464(task);
}

/* Compendium list input; moving the cursor shows the new demon (sub_080DC418). */
// sub_080DC460 @ 0x080DC460
#ifdef NONMATCHING
void sub_080DC460(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    struct Task *parent = Task_GetParent(task);
    u16 count = Dict_CountListed();
    u32 moved = 0;
    u16 rows;

    if (gDict.unk3E == 0)
        count = 1;
    rows = count;
    if (count > 5)
        rows = 6;
    task->result = moved;
    task->unk1E = moved;
    if ((gKeysNew & 1) && gDict.unk3E == 1)
    {
        moved = 1;
        Sound_Play(0x65);
        task->result = moved;
        parent->unk06 = 0;
    }
    else if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        task->result = 1;
        parent->unk06 = 1;
    }
    else if (gRepeatedKeys & 0x40)
    {
        if (d->cursor != 0)
        {
            d->cursor--;
            moved = 1;
            Sound_Play(0x64);
        }
        else if (d->unk02 != 0)
        {
            d->unk02--;
            moved = 1;
            Sound_Play(0x64);
        }
    }
    else
    {
        u16 down = gRepeatedKeys & 0x80;

        if (down)
        {
            if (d->cursor != rows - 1)
            {
                d->cursor++;
                moved = 1;
                Sound_Play(0x64);
            }
            else if (d->cursor == 5 && d->cursor + d->unk02 + 1 <= count - 1)
            {
                d->unk02++;
                moved = 1;
                Sound_Play(0x64);
            }
        }
        else if ((gRepeatedKeys & 0x200) && count > 6)
        {
            u16 cursor = d->cursor;
            u16 top = d->unk02;
            u32 t = cursor;

            if (t != 0)
            {
                d->cursor = down;
            }
            else
            {
                if (top > 4)
                    t = top - 5;
                d->unk02 = t;
            }
            if (cursor != d->cursor || top != d->unk02)
            {
                moved = 1;
                Sound_Play(0x64);
            }
        }
        else if ((gRepeatedKeys & 0x100) && count > 6)
        {
            u16 cursor = d->cursor;
            u16 top = d->unk02;

            if (cursor != 5)
                d->cursor = 5;
            else if (cursor + top + 6 < count - 1)
                d->unk02 = top + 6;
            else
                d->unk02 = count - 6;
            if (cursor != d->cursor || top != d->unk02)
            {
                moved = 1;
                Sound_Play(0x64);
            }
        }
    }
    if (moved == 1)
        sub_080DC418(task);
}
#else
NAKED
void sub_080DC460(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    adds r6, r0, #0\n"
        "    adds r4, r6, #0\n"
        "    adds r4, #0x24\n"
        "    bl Task_GetParent\n"
        "    mov r8, r0\n"
        "    bl Dict_CountListed\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    movs r7, #0\n"
        "    ldr r0, .L080DC4B8\n"
        "    ldrh r3, [r0, #0x3e]\n"
        "    cmp r3, #0\n"
        "    bne .L080DC486\n"
        "    movs r5, #1\n"
        ".L080DC486:\n"
        "    mov ip, r5\n"
        "    cmp r5, #5\n"
        "    bls .L080DC490\n"
        "    movs r0, #6\n"
        "    mov ip, r0\n"
        ".L080DC490:\n"
        "    strh r7, [r6, #0x1c]\n"
        "    strh r7, [r6, #0x1e]\n"
        "    ldr r2, .L080DC4BC\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080DC4C0\n"
        "    cmp r3, #1\n"
        "    bne .L080DC4C0\n"
        "    movs r7, #1\n"
        "    movs r0, #0x65\n"
        "    bl Sound_Play\n"
        "    strh r7, [r6, #0x1c]\n"
        "    movs r0, #0\n"
        "    mov r1, r8\n"
        "    strb r0, [r1, #6]\n"
        "    b .L080DC5B4\n"
        "    .byte 0x00, 0x00\n"
        ".L080DC4B8: .4byte 0x020399E0 @ EWRAM+0x399E0\n"
        ".L080DC4BC: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L080DC4C0:\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080DC4DC\n"
        "    movs r0, #0x66\n"
        "    bl Sound_Play\n"
        "    movs r1, #1\n"
        "    movs r0, #1\n"
        "    strh r0, [r6, #0x1c]\n"
        "    mov r0, r8\n"
        "    strb r1, [r0, #6]\n"
        "    b .L080DC5B4\n"
        ".L080DC4DC:\n"
        "    ldr r1, .L080DC4F4\n"
        "    ldrh r2, [r1]\n"
        "    movs r0, #0x40\n"
        "    ands r0, r2\n"
        "    cmp r0, #0\n"
        "    beq .L080DC504\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #0\n"
        "    beq .L080DC4F8\n"
        "    subs r0, #1\n"
        "    strh r0, [r4]\n"
        "    b .L080DC566\n"
        ".L080DC4F4: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L080DC4F8:\n"
        "    ldrh r0, [r4, #2]\n"
        "    cmp r0, #0\n"
        "    beq .L080DC5B4\n"
        "    subs r0, #1\n"
        "    strh r0, [r4, #2]\n"
        "    b .L080DC566\n"
        ".L080DC504:\n"
        "    movs r0, #0x80\n"
        "    ands r0, r2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    cmp r3, #0\n"
        "    beq .L080DC536\n"
        "    ldrh r1, [r4]\n"
        "    mov r0, ip\n"
        "    subs r0, #1\n"
        "    cmp r1, r0\n"
        "    beq .L080DC520\n"
        "    adds r0, r1, #1\n"
        "    strh r0, [r4]\n"
        "    b .L080DC566\n"
        ".L080DC520:\n"
        "    cmp r1, #5\n"
        "    bne .L080DC5B4\n"
        "    ldrh r2, [r4, #2]\n"
        "    adds r0, r1, r2\n"
        "    adds r0, #1\n"
        "    subs r1, r5, #1\n"
        "    cmp r0, r1\n"
        "    bgt .L080DC5B4\n"
        "    adds r0, r2, #1\n"
        "    strh r0, [r4, #2]\n"
        "    b .L080DC566\n"
        ".L080DC536:\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #2\n"
        "    ands r0, r2\n"
        "    cmp r0, #0\n"
        "    beq .L080DC570\n"
        "    cmp r5, #6\n"
        "    bls .L080DC570\n"
        "    ldrh r2, [r4]\n"
        "    ldrh r1, [r4, #2]\n"
        "    adds r0, r2, #0\n"
        "    cmp r0, #0\n"
        "    beq .L080DC552\n"
        "    strh r3, [r4]\n"
        "    b .L080DC55A\n"
        ".L080DC552:\n"
        "    cmp r1, #4\n"
        "    bls .L080DC558\n"
        "    subs r0, r1, #5\n"
        ".L080DC558:\n"
        "    strh r0, [r4, #2]\n"
        ".L080DC55A:\n"
        "    ldrh r0, [r4]\n"
        "    cmp r2, r0\n"
        "    bne .L080DC566\n"
        "    ldrh r4, [r4, #2]\n"
        "    cmp r1, r4\n"
        "    beq .L080DC5B4\n"
        ".L080DC566:\n"
        "    movs r7, #1\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        "    b .L080DC5B4\n"
        ".L080DC570:\n"
        "    ldrh r1, [r1]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080DC5B4\n"
        "    cmp r5, #6\n"
        "    bls .L080DC5B4\n"
        "    ldrh r2, [r4]\n"
        "    ldrh r3, [r4, #2]\n"
        "    cmp r2, #5\n"
        "    beq .L080DC58E\n"
        "    movs r0, #5\n"
        "    strh r0, [r4]\n"
        "    b .L080DC5A0\n"
        ".L080DC58E:\n"
        "    adds r0, r2, r3\n"
        "    adds r0, #6\n"
        "    subs r1, r5, #1\n"
        "    cmp r0, r1\n"
        "    bge .L080DC59C\n"
        "    adds r0, r3, #6\n"
        "    b .L080DC59E\n"
        ".L080DC59C:\n"
        "    subs r0, r5, #6\n"
        ".L080DC59E:\n"
        "    strh r0, [r4, #2]\n"
        ".L080DC5A0:\n"
        "    ldrh r1, [r4]\n"
        "    cmp r2, r1\n"
        "    bne .L080DC5AC\n"
        "    ldrh r4, [r4, #2]\n"
        "    cmp r3, r4\n"
        "    beq .L080DC5B4\n"
        ".L080DC5AC:\n"
        "    movs r7, #1\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        ".L080DC5B4:\n"
        "    cmp r7, #1\n"
        "    bne .L080DC5BE\n"
        "    adds r0, r6, #0\n"
        "    bl sub_080DC418\n"
        ".L080DC5BE:\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

/* Restores the list position saved by sub_080DC418, keeping the cursor in the window. */
// sub_080DC5C8 @ 0x080DC5C8
void sub_080DC5C8(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    struct C0d9Dict *dict = &gDict;

    if (dict->unk3E == 1)
    {
        u16 n = Dict_CountListed();

        if (n <= 6)
        {
            task->data.h[0] = dict->unk3C;
        }
        else if (dict->unk3C > n - 7)
        {
            u16 c = dict->unk3C - (n - 6);

            d->unk02 = dict->unk3C - c;
            task->data.h[0] = c;
        }
        else
        {
            d->unk02 = dict->unk3C;
        }
    }
    else
    {
        d->unk02 = 0;
    }
}

// sub_080DC618 @ 0x080DC618
void sub_080DC618(struct Task *task)
{
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
    else
    {
        u16 up = gRepeatedKeys & 0x40;

        if (up)
        {
            if (task->data.h[0] != 0)
                task->data.h[0]--;
            else
                task->data.h[0] = 2;
            Sound_Play(0x64);
        }
        else if (gRepeatedKeys & 0x80)
        {
            if (task->data.h[0] != 2)
                task->data.h[0]++;
            else
                task->data.h[0] = up;
            Sound_Play(0x64);
        }
    }
}

// sub_080DC6A4 @ 0x080DC6A4
void sub_080DC6A4(void)
{
    DmaSet3(gUnk_0200F874, 0x06010000, 0x84001400);
}

// sub_080DC6C8 @ 0x080DC6C8
u16 sub_080DC6C8(u16 id)
{
    return id;
}
