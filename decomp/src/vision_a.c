#include "global.h"
#include "extras.h"

// sub_080DAAA8 @ 0x080DAAA8
void sub_080DAAA8(void)
{
    struct C0d9MenuState *ms = &gMenuState;
    u32 zero;

    ms->magic00 = 0x13240800;
    CpuSet(gUnk_03006090, ms->unk04, 0x04000002);
    ms->magic = 0;
    zero = 0;
    CpuSet(&zero, ms->flags, 0x05000002);
}

// sub_080DAAEC @ 0x080DAAEC
void sub_080DAAEC(void)
{
    sub_080DF954(12, &gMenuState, &gMenuState.magic);
}

// sub_080DAB04 @ 0x080DAB04
void sub_080DAB04(struct Task *task)
{
    if (gMenuState.magic == 0x13240800)
        task->result = 1;
    else
        task->result = 0;
}

/* Sets the vision flags (300 + i) received in gMenuState.flags and saves. */
// Vision_ApplyReceivedFlags @ 0x080DAB28
void Vision_ApplyReceivedFlags(void)
{
    struct C0d9MenuState *ms = &gMenuState;
    u8 *flags = ms->flags;
    u32 i;

    for (i = 0; i < 64; i++)
    {
        if ((flags[i >> 3] >> (i & 7)) & 1)
        {
            u16 id = i + 300;

            if (!sub_080C32D4(id))
                sub_080C3328(id);
        }
    }
    SaveSlot_Write(gGameState.saveSlot, &gGameState);
}

// sub_080DAB88 @ 0x080DAB88
void sub_080DAB88(void)
{
    union C0d9Code *code = (union C0d9Code *)gUnk_03004740;

    Vision_BuildList(1);
    sub_080AE2D0();
    if (code->w[0] == 0 && code->w[1] == 0)
    {
        code->b[0] = 0x62;
        code->b[1] = 0x7D;
        code->b[2] = 0x33;
        code->b[3] = 0x80;
        code->b[4] = 0xFF;
        code->s[5] = -1;
        code->s[6] = -1;
        code->s[7] = -1;
    }
}

/* Fills gUnk_0203B454 with vision ids (300..): mode 0 the ones seen, otherwise all except
   310, 338 and 342. Returns the count. */
// Vision_BuildList @ 0x080DABCC
#ifdef NONMATCHING
u16 Vision_BuildList(u32 all)
{
    u16 *list = gUnk_0203B454;
    u32 n = 0;
    u32 zero = 0;
    u32 i;

    CpuSet(&zero, list, 0x05000040);
    if (all == 0)
    {
        for (i = 0; i < 64; i++)
        {
            u32 id = i + 300;

            if (sub_080C2734(id))
            {
                *list++ = id;
                n++;
            }
        }
    }
    else
    {
        for (i = 0; i < 46; i++)
        {
            u32 id = i + 300;

            if (id != 310 && id != 338 && id != 342)
            {
                *list++ = id;
                n++;
            }
        }
    }
    return n;
}
#else
NAKED
u16 Vision_BuildList(u32 all)
{
    asm_unified(
        ".L080DABCC:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    sub sp, #4\n"
        "    adds r4, r0, #0\n"
        "    ldr r6, .L080DAC08\n"
        "    movs r7, #0\n"
        "    str r7, [sp]\n"
        "    ldr r2, .L080DAC0C\n"
        "    mov r0, sp\n"
        "    adds r1, r6, #0\n"
        "    bl CpuSet\n"
        "    cmp r4, #0\n"
        "    bne .L080DAC10\n"
        "    movs r5, #0\n"
        ".L080DABE8:\n"
        "    movs r0, #0x96\n"
        "    lsls r0, r0, #1\n"
        "    adds r4, r5, r0\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080C2734\n"
        "    cmp r0, #0\n"
        "    beq .L080DABFE\n"
        "    strh r4, [r6]\n"
        "    adds r6, #2\n"
        "    adds r7, #1\n"
        ".L080DABFE:\n"
        "    adds r5, #1\n"
        "    cmp r5, #0x3f\n"
        "    bls .L080DABE8\n"
        "    b .L080DAC40\n"
        "    .byte 0x00, 0x00\n"
        ".L080DAC08: .4byte 0x0203B454 @ EWRAM+0x3B454\n"
        ".L080DAC0C: .4byte 0x05000040 @ PLTT+0x40\n"
        ".L080DAC10:\n"
        "    movs r0, #0x2e\n"
        "    mov ip, r0\n"
        "    movs r5, #0\n"
        "    movs r4, #0x96\n"
        "    lsls r4, r4, #1\n"
        "    movs r3, #0x9b\n"
        "    lsls r3, r3, #1\n"
        "    movs r2, #0xa9\n"
        "    lsls r2, r2, #1\n"
        "    movs r1, #0xab\n"
        "    lsls r1, r1, #1\n"
        ".L080DAC26:\n"
        "    adds r0, r5, r4\n"
        "    cmp r0, r3\n"
        "    beq .L080DAC3A\n"
        "    cmp r0, r2\n"
        "    beq .L080DAC3A\n"
        "    cmp r0, r1\n"
        "    beq .L080DAC3A\n"
        "    strh r0, [r6]\n"
        "    adds r6, #2\n"
        "    adds r7, #1\n"
        ".L080DAC3A:\n"
        "    adds r5, #1\n"
        "    cmp r5, ip\n"
        "    blo .L080DAC26\n"
        ".L080DAC40:\n"
        "    lsls r0, r7, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    add sp, #4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

// Vision_CountListed @ 0x080DAC4C
u32 Vision_CountListed(void)
{
    u32 n = 0;
    u32 i;

    for (i = 0; i < 64; i++)
    {
        if (gUnk_0203B454[i] != 0)
            n++;
    }
    return n;
}

/* Vision list input: 6 visible rows, d->unk02 is the first row shown; L/R page. */
// sub_080DAC70 @ 0x080DAC70
#ifdef NONMATCHING
void sub_080DAC70(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    struct C0d9MenuState *ms = &gMenuState;
    u16 *list = gUnk_0203B454;
    u16 count = Vision_CountListed();
    u16 rows;

    ms->listTask = task;
    ms->listOnFrame = task->onFrame;
    task->result = 0;
    task->unk1E = 0;
    if (count > 5)
        rows = 6;
    else
        rows = count;
    if (gKeysNew & 1)
    {
        if (sub_080C2734(list[task->data.h[0] + d->unk02]))
        {
            Font_ResetGlyphSpriteCache(0x180);
            task->unk1E = task->data.h[0] + d->unk02 + 1;
            sub_080C51D4(0x65);
            task->result = 1;
        }
        else
        {
            sub_080C51D4(0x66);
        }
    }
    else if (gKeysNew & 2)
    {
        sub_080C51D4(0x66);
        task->result = 1;
    }
    else if (gRepeatedKeys & 0x40)
    {
        if (task->data.h[0] != 0)
        {
            task->data.h[0]--;
            sub_080C51D4(0x64);
        }
        else if (d->unk02 != 0)
        {
            d->unk02--;
            sub_080C51D4(0x64);
        }
        Font_ResetGlyphSpriteCache(0x180);
    }
    else
    {
        u16 down = gRepeatedKeys & 0x80;

        if (down)
        {
            if (task->data.h[0] != rows - 1)
            {
                task->data.h[0]++;
                sub_080C51D4(0x64);
            }
            else if (task->data.h[0] == 5 && task->data.h[0] + d->unk02 + 1 <= count - 1)
            {
                d->unk02++;
                sub_080C51D4(0x64);
            }
            Font_ResetGlyphSpriteCache(0x180);
        }
        else if ((gRepeatedKeys & 0x200) && count > 6)
        {
            u16 cursor = task->data.h[0];
            u16 top = d->unk02;

            if (cursor != 0)
            {
                task->data.h[0] = down;
            }
            else
            {
                u16 t = cursor;

                if (top > 4)
                    t = top - 5;
                d->unk02 = t;
            }
            if (cursor != d->cursor || top != d->unk02)
                sub_080C51D4(0x64);
            Font_ResetGlyphSpriteCache(0x180);
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
                sub_080C51D4(0x64);
            Font_ResetGlyphSpriteCache(0x180);
        }
    }
}
#else
NAKED
void sub_080DAC70(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    adds r5, r0, #0\n"
        "    adds r6, r5, #0\n"
        "    adds r6, #0x24\n"
        "    ldr r4, .L080DACDC\n"
        "    ldr r0, .L080DACE0\n"
        "    mov r8, r0\n"
        "    bl Vision_CountListed\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    movs r1, #0\n"
        "    str r5, [r4, #0x7c]\n"
        "    adds r4, #0x84\n"
        "    ldr r0, [r5, #0x20]\n"
        "    str r0, [r4]\n"
        "    strh r1, [r5, #0x1c]\n"
        "    strh r1, [r5, #0x1e]\n"
        "    mov ip, r7\n"
        "    cmp r7, #5\n"
        "    bls .L080DACA2\n"
        "    movs r1, #6\n"
        "    mov ip, r1\n"
        ".L080DACA2:\n"
        "    ldr r2, .L080DACE4\n"
        "    ldrh r1, [r2]\n"
        "    movs r4, #1\n"
        "    adds r0, r4, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080DACF0\n"
        "    ldrh r0, [r5, #0x24]\n"
        "    ldrh r1, [r6, #2]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    add r0, r8\n"
        "    ldrh r0, [r0]\n"
        "    bl sub_080C2734\n"
        "    cmp r0, #0\n"
        "    beq .L080DACE8\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #1\n"
        "    bl Font_ResetGlyphSpriteCache\n"
        "    ldrh r0, [r6, #2]\n"
        "    ldrh r1, [r5, #0x24]\n"
        "    adds r0, r0, r1\n"
        "    adds r0, #1\n"
        "    strh r0, [r5, #0x1e]\n"
        "    movs r0, #0x65\n"
        "    b .L080DACFC\n"
        "    .byte 0x00, 0x00\n"
        ".L080DACDC: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L080DACE0: .4byte 0x0203B454 @ EWRAM+0x3B454\n"
        ".L080DACE4: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L080DACE8:\n"
        "    movs r0, #0x66\n"
        "    bl sub_080C51D4\n"
        "    b .L080DADEE\n"
        ".L080DACF0:\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080DAD04\n"
        "    movs r0, #0x66\n"
        ".L080DACFC:\n"
        "    bl sub_080C51D4\n"
        "    strh r4, [r5, #0x1c]\n"
        "    b .L080DADEE\n"
        ".L080DAD04:\n"
        "    ldr r1, .L080DAD24\n"
        "    ldrh r2, [r1]\n"
        "    movs r0, #0x40\n"
        "    ands r0, r2\n"
        "    cmp r0, #0\n"
        "    beq .L080DAD34\n"
        "    ldrh r0, [r5, #0x24]\n"
        "    cmp r0, #0\n"
        "    beq .L080DAD28\n"
        "    subs r0, #1\n"
        ".L080DAD18:\n"
        "    strh r0, [r5, #0x24]\n"
        "    movs r0, #0x64\n"
        "    bl sub_080C51D4\n"
        "    b .L080DAD9A\n"
        "    .byte 0x00, 0x00\n"
        ".L080DAD24: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L080DAD28:\n"
        "    ldrh r0, [r6, #2]\n"
        "    cmp r0, #0\n"
        "    beq .L080DAD9A\n"
        "    subs r0, #1\n"
        "    strh r0, [r6, #2]\n"
        "    b .L080DAD94\n"
        ".L080DAD34:\n"
        "    movs r0, #0x80\n"
        "    ands r0, r2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    cmp r3, #0\n"
        "    beq .L080DAD64\n"
        "    ldrh r1, [r5, #0x24]\n"
        "    mov r0, ip\n"
        "    subs r0, #1\n"
        "    cmp r1, r0\n"
        "    beq .L080DAD4E\n"
        "    adds r0, r1, #1\n"
        "    b .L080DAD18\n"
        ".L080DAD4E:\n"
        "    cmp r1, #5\n"
        "    bne .L080DAD9A\n"
        "    ldrh r2, [r6, #2]\n"
        "    adds r0, r1, r2\n"
        "    adds r0, #1\n"
        "    subs r1, r7, #1\n"
        "    cmp r0, r1\n"
        "    bgt .L080DAD9A\n"
        "    adds r0, r2, #1\n"
        "    strh r0, [r6, #2]\n"
        "    b .L080DAD94\n"
        ".L080DAD64:\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #2\n"
        "    ands r0, r2\n"
        "    cmp r0, #0\n"
        "    beq .L080DADA4\n"
        "    cmp r7, #6\n"
        "    bls .L080DADA4\n"
        "    ldrh r2, [r5, #0x24]\n"
        "    ldrh r1, [r6, #2]\n"
        "    adds r0, r2, #0\n"
        "    cmp r0, #0\n"
        "    beq .L080DAD80\n"
        "    strh r3, [r5, #0x24]\n"
        "    b .L080DAD88\n"
        ".L080DAD80:\n"
        "    cmp r1, #4\n"
        "    bls .L080DAD86\n"
        "    subs r0, r1, #5\n"
        ".L080DAD86:\n"
        "    strh r0, [r6, #2]\n"
        ".L080DAD88:\n"
        "    ldrh r0, [r6]\n"
        "    cmp r2, r0\n"
        "    bne .L080DAD94\n"
        "    ldrh r6, [r6, #2]\n"
        "    cmp r1, r6\n"
        "    beq .L080DAD9A\n"
        ".L080DAD94:\n"
        "    movs r0, #0x64\n"
        "    bl sub_080C51D4\n"
        ".L080DAD9A:\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #1\n"
        "    bl Font_ResetGlyphSpriteCache\n"
        "    b .L080DADEE\n"
        ".L080DADA4:\n"
        "    ldrh r1, [r1]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080DADEE\n"
        "    cmp r7, #6\n"
        "    bls .L080DADEE\n"
        "    ldrh r2, [r6]\n"
        "    ldrh r3, [r6, #2]\n"
        "    cmp r2, #5\n"
        "    beq .L080DADC2\n"
        "    movs r0, #5\n"
        "    strh r0, [r6]\n"
        "    b .L080DADD4\n"
        ".L080DADC2:\n"
        "    adds r0, r2, r3\n"
        "    adds r0, #6\n"
        "    subs r1, r7, #1\n"
        "    cmp r0, r1\n"
        "    bge .L080DADD0\n"
        "    adds r0, r3, #6\n"
        "    b .L080DADD2\n"
        ".L080DADD0:\n"
        "    subs r0, r7, #6\n"
        ".L080DADD2:\n"
        "    strh r0, [r6, #2]\n"
        ".L080DADD4:\n"
        "    ldrh r1, [r6]\n"
        "    cmp r2, r1\n"
        "    bne .L080DADE0\n"
        "    ldrh r6, [r6, #2]\n"
        "    cmp r3, r6\n"
        "    beq .L080DADE6\n"
        ".L080DADE0:\n"
        "    movs r0, #0x64\n"
        "    bl sub_080C51D4\n"
        ".L080DADE6:\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #1\n"
        "    bl Font_ResetGlyphSpriteCache\n"
        ".L080DADEE:\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

/* Draws the six visible rows of vision names (8 glyphs each), the count seen and the
   scroll arrows. */
// Vision_DrawItemList @ 0x080DADF8
#ifdef NONMATCHING
void Vision_DrawItemList(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    u16 count = Vision_CountListed();
    u16 x = 0x6C;
    u16 y = 0x10;
    u32 row, i, n;

    Sprite_Draw(gUnknown_0800853C, 0, 7, 0, 0x100, 0x6A, task->data.h[0] * 12 + 17);
    for (row = 0; row < 6; row++)
    {
        u16 id = gUnk_0203B454[d->unk02 + row];

        if (id != 0)
        {
            const u16 *name;

            if (sub_080C2734(id))
                name = (const u16 *)(Action_GetRecord(id) + 0xC);
            else
                name = gUnknown_085829BC;
            for (i = 0; i < 8; i++)
                FontSprite_DrawGlyph(name[i], 0, 0, x + i * 12, y + row * 12);
        }
    }
    for (n = 0, i = 0; i < 46; i++)
    {
        if (sub_080C2734(i + 300))
            n++;
    }
    Sprite_DrawFraction(n, 43, x + 0x25, y + 0x5A);
    if (d->unk02 != 0)
        sub_080C4A4C(6, 1, x + 0x60, y - 4);
    if (d->unk02 + 6 <= count - 1)
        sub_080C4AB0(6, 1, x + 0x60, y + 0x4C);
}
#else
NAKED
void Vision_DrawItemList(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x1c\n"
        "    adds r4, r0, #0\n"
        "    adds r0, #0x24\n"
        "    str r0, [sp, #0xc]\n"
        "    bl Vision_CountListed\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0x10]\n"
        "    ldr r0, .L080DAE80\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #1\n"
        "    str r1, [sp]\n"
        "    movs r1, #0x6a\n"
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
        "    movs r0, #0\n"
        "    mov r8, r0\n"
        "    movs r1, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    str r1, [sp, #0x18]\n"
        ".L080DAE46:\n"
        "    ldr r2, [sp, #0xc]\n"
        "    ldrh r0, [r2, #2]\n"
        "    add r0, r8\n"
        "    lsls r0, r0, #1\n"
        "    ldr r1, .L080DAE84\n"
        "    adds r0, r0, r1\n"
        "    ldrh r4, [r0]\n"
        "    movs r2, #0x6c\n"
        "    adds r2, #0x25\n"
        "    mov sl, r2\n"
        "    movs r0, #0x10\n"
        "    adds r0, #0x5a\n"
        "    mov sb, r0\n"
        "    ldr r1, [sp, #0x10]\n"
        "    subs r1, #1\n"
        "    str r1, [sp, #0x14]\n"
        "    cmp r4, #0\n"
        "    beq .L080DAEC4\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080C2734\n"
        "    cmp r0, #0\n"
        "    beq .L080DAE88\n"
        "    adds r0, r4, #0\n"
        "    bl Action_GetRecord\n"
        "    adds r0, #0xc\n"
        "    b .L080DAE8A\n"
        "    .byte 0x00, 0x00\n"
        ".L080DAE80: .4byte gUnknown_0800853C\n"
        ".L080DAE84: .4byte 0x0203B454 @ EWRAM+0x3B454\n"
        ".L080DAE88:\n"
        "    ldr r0, .L080DAF4C\n"
        ".L080DAE8A:\n"
        "    movs r6, #0\n"
        "    movs r2, #0x6c\n"
        "    adds r2, #0x25\n"
        "    mov sl, r2\n"
        "    movs r1, #0x10\n"
        "    adds r1, #0x5a\n"
        "    mov sb, r1\n"
        "    ldr r2, [sp, #0x10]\n"
        "    subs r2, #1\n"
        "    str r2, [sp, #0x14]\n"
        "    ldr r1, [sp, #0x18]\n"
        "    lsrs r7, r1, #0x10\n"
        "    movs r2, #0x6c\n"
        "    lsls r5, r2, #0x10\n"
        "    adds r4, r0, #0\n"
        ".L080DAEA8:\n"
        "    ldrh r0, [r4]\n"
        "    lsrs r3, r5, #0x10\n"
        "    str r7, [sp]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    bl FontSprite_DrawGlyph\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #0xc\n"
        "    adds r5, r5, r0\n"
        "    adds r4, #2\n"
        "    adds r6, #1\n"
        "    cmp r6, #7\n"
        "    bls .L080DAEA8\n"
        ".L080DAEC4:\n"
        "    ldr r1, [sp, #0x18]\n"
        "    movs r2, #0xc0\n"
        "    lsls r2, r2, #0xc\n"
        "    adds r1, r1, r2\n"
        "    str r1, [sp, #0x18]\n"
        "    movs r0, #1\n"
        "    add r8, r0\n"
        "    mov r1, r8\n"
        "    cmp r1, #5\n"
        "    bls .L080DAE46\n"
        "    movs r4, #0\n"
        "    mov r8, r4\n"
        ".L080DAEDC:\n"
        "    movs r0, #0x96\n"
        "    lsls r0, r0, #1\n"
        "    add r0, r8\n"
        "    bl sub_080C2734\n"
        "    cmp r0, #0\n"
        "    beq .L080DAEEC\n"
        "    adds r4, #1\n"
        ".L080DAEEC:\n"
        "    movs r2, #1\n"
        "    add r8, r2\n"
        "    mov r0, r8\n"
        "    cmp r0, #0x2d\n"
        "    bls .L080DAEDC\n"
        "    mov r2, sl\n"
        "    mov r3, sb\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0x2b\n"
        "    bl Sprite_DrawFraction\n"
        "    ldr r1, [sp, #0xc]\n"
        "    ldrh r0, [r1, #2]\n"
        "    cmp r0, #0\n"
        "    beq .L080DAF1E\n"
        "    movs r2, #0x6c\n"
        "    adds r2, #0x60\n"
        "    movs r3, #0x10\n"
        "    subs r3, #4\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    movs r0, #6\n"
        "    movs r1, #1\n"
        "    bl sub_080C4A4C\n"
        ".L080DAF1E:\n"
        "    ldr r2, [sp, #0xc]\n"
        "    ldrh r0, [r2, #2]\n"
        "    adds r0, #6\n"
        "    ldr r1, [sp, #0x14]\n"
        "    cmp r0, r1\n"
        "    bgt .L080DAF3A\n"
        "    movs r2, #0x6c\n"
        "    adds r2, #0x60\n"
        "    movs r3, #0x10\n"
        "    adds r3, #0x4c\n"
        "    movs r0, #6\n"
        "    movs r1, #1\n"
        "    bl sub_080C4AB0\n"
        ".L080DAF3A:\n"
        "    add sp, #0x1c\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080DAF4C: .4byte gUnknown_085829BC\n"
    );
}
#endif

/* "<name>" + gUnknown_08009534 on one line, gUnknown_08009540 below (vision names stop at
   8 glyphs or a 0). */
// Vision_ComposePrompt @ 0x080DAF50
void Vision_ComposePrompt(struct Task *task)
{
    struct Task *parent = Task_GetParent(task);
    u16 x = 0x14;
    u16 y = 0x64;
    const u16 *str = (const u16 *)(Action_GetRecord(gUnk_0203B454[parent->data.h[0] + parent->data.h[1]]) + 0xC);
    u16 i;

    for (i = 0; str[i] != 0; )
    {
        FontSprite_DrawGlyphTinted(str[i], 0, 0, x, y, 2);
        x += 12;
        i++;
        if (i > 7)
            break;
    }
    str = gUnknown_08009534;
    Text_DrawSpriteString(str, 0, 0, x, y, 12);
    str = gUnknown_08009540;
    Text_DrawSpriteString(str, 0, 0, 0x14, y + 12, 12);
}

// sub_080DAFEC @ 0x080DAFEC
void sub_080DAFEC(void)
{
    gMenuState.task->onFrame = NULL;
    gMenuState.listTask->onFrame = NULL;
}

/* Starts the selected vision: clears the field state, sets the windows and loads the
   vision's script. */
// sub_080DB000 @ 0x080DB000
#ifdef NONMATCHING
void sub_080DB000(struct Task *task)
{
    DmaFill32_3(0, &gFieldState, 0x85000029);
    gUnk_03000039 = 0x3F;
    gUnk_03000030 = 0xE8;
    gUnk_03000031 = 8;
    gUnk_03000034 = 0x98;
    gUnk_03000035 = 0x60;
    gUnk_03000038 = 0x37;
    sub_080AF218(0x24, gUnknown_085829CC[gUnk_0203B454[task->data.h[0] + task->data.h[1]] - 300]);
}
#else
NAKED
void sub_080DB000(struct Task *task)
{
    asm_unified(
        "    push {lr}\n"
        "    sub sp, #4\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    ldr r2, .L080DB064\n"
        "    mov r1, sp\n"
        "    str r1, [r2]\n"
        "    ldr r1, .L080DB068\n"
        "    str r1, [r2, #4]\n"
        "    ldr r1, .L080DB06C\n"
        "    str r1, [r2, #8]\n"
        "    ldr r1, [r2, #8]\n"
        "    ldr r3, .L080DB070\n"
        "    movs r2, #0x3f\n"
        "    ldr r1, .L080DB074\n"
        "    strb r2, [r1]\n"
        "    ldr r2, .L080DB078\n"
        "    movs r1, #0xe8\n"
        "    strb r1, [r2]\n"
        "    ldr r2, .L080DB07C\n"
        "    movs r1, #8\n"
        "    strb r1, [r2]\n"
        "    ldr r2, .L080DB080\n"
        "    movs r1, #0x98\n"
        "    strb r1, [r2]\n"
        "    ldr r2, .L080DB084\n"
        "    movs r1, #0x60\n"
        "    strb r1, [r2]\n"
        "    movs r1, #0x37\n"
        "    strb r1, [r3]\n"
        "    ldr r2, .L080DB088\n"
        "    ldr r3, .L080DB08C\n"
        "    ldrh r1, [r0, #0x24]\n"
        "    ldrh r0, [r0, #0x26]\n"
        "    adds r1, r1, r0\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r2\n"
        "    ldrh r0, [r1]\n"
        "    ldr r1, .L080DB090\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r0, r3\n"
        "    ldr r1, [r0]\n"
        "    movs r0, #0x24\n"
        "    bl sub_080AF218\n"
        "    add sp, #4\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080DB064: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080DB068: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080DB06C: .4byte 0x85000029\n"
        ".L080DB070: .4byte 0x03000038 @ IWRAM+0x38\n"
        ".L080DB074: .4byte 0x03000039 @ IWRAM+0x39\n"
        ".L080DB078: .4byte 0x03000030 @ IWRAM+0x30\n"
        ".L080DB07C: .4byte 0x03000031 @ IWRAM+0x31\n"
        ".L080DB080: .4byte 0x03000034 @ IWRAM+0x34\n"
        ".L080DB084: .4byte 0x03000035 @ IWRAM+0x35\n"
        ".L080DB088: .4byte 0x0203B454 @ EWRAM+0x3B454\n"
        ".L080DB08C: .4byte gUnknown_085829CC\n"
        ".L080DB090: .4byte 0xFFFFFED4\n"
    );
}
#endif

// sub_080DB094 @ 0x080DB094
void sub_080DB094(struct Task *task)
{
    if (gFieldState.state == 0x24)
    {
        task->result = 1;
        sub_080C3818(1);
        sub_080AE2D0();
    }
    else
    {
        task->result = 0;
    }
}

// sub_080DB0BC @ 0x080DB0BC
void sub_080DB0BC(void)
{
    DmaFill32_3(0, 0x06001000, 0x85000400);
    DmaFill32_3(0, 0x06003000, 0x85000400);
}

// sub_080DB0F4 @ 0x080DB0F4
void sub_080DB0F4(void)
{
    DmaFill32_3(0, gUnk_02000000, 0x85000400);
    DmaFill32_3(0, gUnk_03002EB0, 0x85000040);
    DmaFill16_3(0, gWindowTilemapBuffer, 0x81000400);
    DmaFill32_3(0, gUnk_0201D874, 0x85001A00);
    Palette_MarkDirty();
    gUnk_0300000E = 0;
    gUnk_03000006 = 0;
    VBlankTask_AddCounted(sub_080DB0BC, 1);
}

// sub_080DB188 @ 0x080DB188
void sub_080DB188(void)
{
    struct C0d9MenuState *ms = &gMenuState;

    ms->task->onFrame = ms->onFrame;
    ms->listTask->onFrame = ms->listOnFrame;
    Tilemap_CopyRectSkipZero(gUnknown_0857F500, gUnk_02024074, 0, 0, 1, 1, 11, 5);
    VBlankTask_AddCounted(sub_080D9BAC, 1);
}
