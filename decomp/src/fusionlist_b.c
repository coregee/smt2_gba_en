#include "global.h"
#include "fusion.h"

/* Draws the fusion list screen: windows, "LV" of the hero, header and visible rows. */
// sub_081551F8 @ 0x081551F8
void sub_081551F8(void)
{
    struct FusionState *f = &sFusion;
    vu32 zero;
    u8 buf[8];
    u32 tint;

    if (f->win10 == NULL)
        f->win10 = Window_CreateOpen(3, 0, 0x12, 2, 0);
    if (f->win14 == NULL)
        f->win14 = Window_CreateOpen(0x15, 0, 9, 3, 0);
    zero = 0;
    DmaSet3(&zero, gUnk_0200F874, 0x85002000);
    memset(buf, 0, 8);
    NumberToDigits(gGameState.members[0].level);
    buf[0] = 'L';
    buf[1] = 'V';
    if (gGameState.members[0].level < 10)
    {
        buf[2] = gDigits[0] + '0';
        buf[3] = ' ';
    }
    else
    {
        buf[2] = gDigits[1] + '0';
        buf[3] = gDigits[0] + '0';
    }
    switch (Combatant_GetAlignment(0))
    {
    case 0:
        tint = 8;
        break;
    case 1:
        tint = 0;
        break;
    case 2:
        tint = 10;
        break;
    }
    SmallFont_DrawAsciiTinted(buf, gUnk_02016874, 0, 0, tint, 8);
    Fusion_DrawListHeader();
    Fusion_DrawList(f->top);
}

// sub_081552E8 @ 0x081552E8
void sub_081552E8(struct Task *task, u32 arg1, const u16 *str)
{
    struct FusionState *f = &sFusion;

    task->result = 0;
    if (arg1 == 0)
    {
        f->win18 = Window_CreateOpen(2, 0xB, 0x1A, 7, arg1);
        Font_ResetGlyphSpriteCache(0x180);
    }
    else if (gKeysNew & 1)
    {
        task->result = 1;
        Window_Close(f->win18, 1);
        sub_0815565C(1);
    }
    else
    {
        Text_DrawSpriteString(str, 0, 0, 0x12, 0x5B, 0xC);
        if (!((gFrameCounter >> 4) & 1))
            sub_080C4AB0(0, 0, 0xD5, 0x8D);
    }
}

// sub_08155374 @ 0x08155374
#ifdef NONMATCHING
void sub_08155374(void)
{
    s8 *flags;
    const void *const *defs;
    struct FusionState *f = &sFusion;
    u16 y = f->cursor * 13 + 0x44;
    u16 n = Fusion_CountList();
    u16 i;
    u16 *src;
    u16 *dst;

    for (i = 0, flags = gUnk_030050E0, defs = gUnknown_0834A23C; i < 6; i++)
    {
        if (flags[i] == 0)
        {
            Sprite_Draw(defs[i], 0, 0, 0, 0, 0xAA, 4);
            break;
        }
    }
    Sprite_DrawSingle(gUnknown_087E1C68, 0, 0, 0, 0, 0xD0, 0xE);
    src = &gPaletteBuffer[0x50];
    dst = &gPaletteBuffer[0x1B0];
    for (i = 0; i < 16; i++)
        *dst++ = *src++;
    src = &gPaletteTarget[0x50];
    dst = &gPaletteTarget[0x1B0];
    for (i = 0; i < 16; i++)
        *dst++ = *src++;
    Palette_MarkDirty();
    switch (f->unk2)
    {
    case 1:
        if ((u16)(f->mode - 2) <= 1)
            Text_DrawSpriteString(gUnknown_0815BE50, 0, 0, 0x1A, 1, 0xC);
        else
            Text_DrawSpriteString(gUnknown_0815BE92, 0, 0, 0x1A, 1, 0xC);
        break;
    case 2:
        if ((u16)(f->mode - 2) <= 1)
            Text_DrawSpriteString(gUnknown_0815BE68, 0, 0, 0x1A, 1, 0xC);
        else if ((u16)(f->mode - 4) <= 1)
            Text_DrawSpriteString(gUnknown_0815BEA6, 0, 0, 0x1A, 1, 0xC);
        else
            Text_DrawSpriteString(gUnknown_0815BEBE, 0, 0, 0x1A, 1, 0xC);
        break;
    case 3:
        if (f->mode == 3)
            Text_DrawSpriteString(gUnknown_0815BE7E, 0, 0, 0x1A, 1, 0xC);
        else
            Text_DrawSpriteString(gUnknown_0815BEBE, 0, 0, 0x1A, 1, 0xC);
        break;
    }
    sub_080C49EC(0x1A, 4, 2, 0, y);
    if (f->top != 0)
        sub_080C4A4C(4, 2, 0xE0, 0x34);
    if (f->top + 6 <= n - 1)
        sub_080C4AB0(4, 2, 0xE0, 0x92);
}
#else
NAKED
void sub_08155374(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    sub sp, #0xc\n"
        "    ldr r5, .L08155398\n"
        "    ldrh r1, [r5, #4]\n"
        "    movs r0, #0xd\n"
        "    muls r0, r1, r0\n"
        "    adds r0, #0x44\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    bl Fusion_CountList\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    movs r2, #0\n"
        "    ldr r3, .L0815539C\n"
        "    ldr r4, .L081553A0\n"
        "    b .L081553AA\n"
        "    .byte 0x00, 0x00\n"
        ".L08155398: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L0815539C: .4byte 0x030050E0 @ IWRAM+0x50E0\n"
        ".L081553A0: .4byte gUnknown_0834A23C\n"
        ".L081553A4:\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        ".L081553AA:\n"
        "    cmp r2, #5\n"
        "    bhi .L081553D2\n"
        "    adds r0, r2, r3\n"
        "    movs r1, #0\n"
        "    ldrsb r1, [r0, r1]\n"
        "    cmp r1, #0\n"
        "    bne .L081553A4\n"
        "    lsls r0, r2, #2\n"
        "    adds r0, r0, r4\n"
        "    ldr r0, [r0]\n"
        "    str r1, [sp]\n"
        "    movs r1, #0xaa\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #4\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L081553D2:\n"
        "    ldr r0, .L08155438\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    movs r1, #0xd0\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #0xe\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_DrawSingle\n"
        "    ldr r1, .L0815543C\n"
        "    movs r0, #0xb0\n"
        "    lsls r0, r0, #2\n"
        "    adds r3, r1, r0\n"
        "    movs r2, #0\n"
        "    subs r4, r6, #1\n"
        ".L081553F6:\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r3]\n"
        "    adds r1, #2\n"
        "    adds r3, #2\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #0xf\n"
        "    bls .L081553F6\n"
        "    ldr r1, .L08155440\n"
        "    movs r0, #0xb0\n"
        "    lsls r0, r0, #2\n"
        "    adds r3, r1, r0\n"
        "    movs r2, #0\n"
        ".L08155412:\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r3]\n"
        "    adds r1, #2\n"
        "    adds r3, #2\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #0xf\n"
        "    bls .L08155412\n"
        "    bl Palette_MarkDirty\n"
        "    ldrh r1, [r5, #2]\n"
        "    cmp r1, #2\n"
        "    beq .L08155468\n"
        "    cmp r1, #2\n"
        "    bgt .L08155444\n"
        "    cmp r1, #1\n"
        "    beq .L0815544A\n"
        "    b .L081554CC\n"
        ".L08155438: .4byte gUnknown_087E1C68\n"
        ".L0815543C: .4byte 0x03002E50 @ IWRAM+0x2E50\n"
        ".L08155440: .4byte 0x03002A50 @ IWRAM+0x2A50\n"
        ".L08155444:\n"
        "    cmp r1, #3\n"
        "    beq .L08155498\n"
        "    b .L081554CC\n"
        ".L0815544A:\n"
        "    ldrh r0, [r5]\n"
        "    subs r0, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bhi .L08155460\n"
        "    ldr r0, .L0815545C\n"
        "    b .L081554A2\n"
        "    .byte 0x00, 0x00\n"
        ".L0815545C: .4byte gUnknown_0815BE50\n"
        ".L08155460:\n"
        "    ldr r0, .L08155464\n"
        "    b .L081554A2\n"
        ".L08155464: .4byte gUnknown_0815BE92\n"
        ".L08155468:\n"
        "    ldrh r1, [r5]\n"
        "    subs r0, r1, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bhi .L0815547C\n"
        "    ldr r0, .L08155478\n"
        "    b .L081554A0\n"
        ".L08155478: .4byte gUnknown_0815BE68\n"
        ".L0815547C:\n"
        "    subs r0, r1, #4\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bhi .L08155490\n"
        "    ldr r0, .L0815548C\n"
        "    b .L081554A0\n"
        "    .byte 0x00, 0x00\n"
        ".L0815548C: .4byte gUnknown_0815BEA6\n"
        ".L08155490:\n"
        "    ldr r0, .L08155494\n"
        "    b .L081554A0\n"
        ".L08155494: .4byte gUnknown_0815BEBE\n"
        ".L08155498:\n"
        "    ldrh r0, [r5]\n"
        "    cmp r0, #3\n"
        "    bne .L081554B8\n"
        "    ldr r0, .L081554B4\n"
        ".L081554A0:\n"
        "    movs r1, #1\n"
        ".L081554A2:\n"
        "    str r1, [sp]\n"
        "    movs r1, #0xc\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0x1a\n"
        "    bl Text_DrawSpriteString\n"
        "    b .L081554CC\n"
        ".L081554B4: .4byte gUnknown_0815BE7E\n"
        ".L081554B8:\n"
        "    ldr r0, .L08155508\n"
        "    movs r1, #1\n"
        "    str r1, [sp]\n"
        "    movs r1, #0xc\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0x1a\n"
        "    bl Text_DrawSpriteString\n"
        ".L081554CC:\n"
        "    str r7, [sp]\n"
        "    movs r0, #0x1a\n"
        "    movs r1, #4\n"
        "    movs r2, #2\n"
        "    movs r3, #0\n"
        "    bl sub_080C49EC\n"
        "    ldrh r0, [r5, #6]\n"
        "    cmp r0, #0\n"
        "    beq .L081554EC\n"
        "    movs r0, #4\n"
        "    movs r1, #2\n"
        "    movs r2, #0xe0\n"
        "    movs r3, #0x34\n"
        "    bl sub_080C4A4C\n"
        ".L081554EC:\n"
        "    ldrh r0, [r5, #6]\n"
        "    adds r0, #6\n"
        "    cmp r0, r4\n"
        "    bgt .L08155500\n"
        "    movs r0, #4\n"
        "    movs r1, #2\n"
        "    movs r2, #0xe0\n"
        "    movs r3, #0x92\n"
        "    bl sub_080C4AB0\n"
        ".L08155500:\n"
        "    add sp, #0xc\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L08155508: .4byte gUnknown_0815BEBE\n"
    );
}
#endif

// sub_0815550C @ 0x0815550C
void sub_0815550C(struct Task *task)
{
    task->unk1E = sFusion.unkA;
}

/* Lists the fusion results except the first pick; returns how many. */
// sub_08155518 @ 0x08155518
u16 sub_08155518(void)
{
    struct FusionState *f = &sFusion;
    u16 n = 0;
    struct Combatant *c = f->results;
    u32 i;

    for (i = 0; i < 12; i++, c++)
    {
        if (c->unkE != 0 && c != f->picks[0])
        {
            f->members[n] = c;
            n++;
        }
    }
    return n;
}

/* Rebuilds the list of demons that can still be picked (not already a material). */
// Fusion_BuildMaterialList @ 0x08155554
void Fusion_BuildMaterialList(void)
{
    struct FusionState *f = &sFusion;
    u16 n;
    u16 id0;
    u16 id1;
    u16 id2;
    u32 i;
    struct Combatant *p;

    n = 0;
    p = f->picks[0];
    id0 = 0xFFFF;
    if (p != NULL)
        id0 = p->demonId;
    p = f->picks[1];
    id1 = 0xFFFF;
    if (p != NULL)
        id1 = p->demonId;
    p = f->picks[2];
    id2 = 0xFFFF;
    if (p != NULL)
        id2 = p->demonId;
    Fusion_ClearList();
    if (f->mode == 2 || f->mode == 3)
    {
        for (i = 0; i < 12; i++)
        {
            struct Combatant *c = &gUnk_030048C0[i];

            if (Combatant_IsUsed(i + 4) && !Combatant_IsDead(i + 4)
             && c->demonId != id0 && c->demonId != id1 && c->demonId != id2)
            {
                f->members[n] = c;
                n++;
            }
        }
    }
    else if (f->mode == 4 || (f->mode == 5 && f->sel == 0))
    {
        struct Combatant *c = f->results;

        for (i = 0; i < 12; i++, c++)
        {
            if (c->unkE != 0 && c->demonId != id0 && c->demonId != id1 && c->demonId != id2)
            {
                f->members[n] = c;
                n++;
            }
        }
    }
    else if (f->mode == 5 && f->sel == 1)
    {
        sub_08155518();
    }
}

// sub_0815565C @ 0x0815565C
void sub_0815565C(u16 n)
{
    struct FusionState *f = &sFusion;
    u16 x;
    u16 y;

    f->picks[n - 1] = NULL;
    f->sel = n - 1;
    Fusion_BuildMaterialList();
    f->cursor = 0;
    f->top = 0;
    switch (n)
    {
    case 1:
        x = 0;
        y = 0x24;
        break;
    case 2:
        x = 0;
        y = 0x32;
        break;
    }
    Canvas_FillRect(0, gUnk_0200F874, x, y, 0xF0, 0xD);
}

// sub_081556C4 @ 0x081556C4
void sub_081556C4(void)
{
    struct FusionState *f = &sFusion;
    u32 zero = 0;

    CpuSet(&zero, gUnk_02011874, 0x05000C00);
    Fusion_DrawListHeader();
    Fusion_DrawList(f->top);
}

// sub_081556F8 @ 0x081556F8
void sub_081556F8(void)
{
    DmaSet3(gUnknown_081B4F10, 0x06015000, 0x84000200);
}

/* Input on the material list: A picks the demon under the cursor, B steps back. */
// sub_0815571C @ 0x0815571C
#ifdef NONMATCHING
void sub_0815571C(struct Task *task, u32 sel)
{
    struct FusionState *f = &sFusion;
    u16 n = Fusion_CountList();
    u16 rows;
    u32 redraw = 0;
    u16 idx;
    struct Combatant *c;
    u16 i;

    rows = n;
    if (rows > 5)
        rows = 6;
    f->unk2 = sel + 1;
    f->sel = sel;
    f->unk660 = redraw;
    task->result = redraw;
    task->unk1E = redraw;
    if (gKeysNew & 1)
    {
        idx = f->cursor + f->top;
        c = f->members[idx];
        if (sub_081544AC(c->demonId) == 1)
        {
            if (sel == 0)
            {
                for (i = 0; i < 12; i++)
                {
                    if (gUnk_0203A470[i] != NULL)
                    {
                        f->pairs[i][0] = gUnk_0203A470[i]->demonId;
                        f->pairs[i][1] = Random_Byte();
                    }
                    else
                    {
                        f->pairs[i][0] = 0xFFFF;
                        f->pairs[i][1] = 0;
                    }
                }
            }
            gUnk_0203B854[sel] = c->demonId;
            sub_08153F6C(idx);
            for (i = 0; i < 3; i++)
            {
                if (gUnk_0203A4A0[i] != NULL)
                    sub_081562EC(i, gUnk_0203B854[i], task);
            }
            task->result = 1;
            gYesNoResult = 0;
            Sound_Play(0x65);
        }
        else
        {
            Sound_Play(0x65);
        }
    }
    else if (gKeysNew & 2)
    {
        if (sel != 0)
        {
            sub_0815565C(sel);
            redraw = 1;
            task->unk1E = 1;
        }
        else
        {
            gYesNoResult = 1;
            task->unk1E = 1;
            f->unk660 = 1;
        }
        Sound_Play(0x66);
    }
    else if (gKeysNew & 0x200)
    {
        task->unk1E = 2;
        Sound_Play(0x65);
    }
    else if (gRepeatedKeys & 0x40)
    {
        if (f->cursor != 0)
        {
            f->cursor--;
            Sound_Play(0x64);
        }
        else if (f->top != 0)
        {
            f->top--;
            redraw = 1;
            Sound_Play(0x64);
        }
    }
    else if (gRepeatedKeys & 0x80)
    {
        if (f->cursor != rows - 1)
        {
            f->cursor++;
            Sound_Play(0x64);
        }
        else if (f->cursor == 5 && f->cursor + f->top + 1 <= n - 1)
        {
            f->top++;
            redraw = 1;
            Sound_Play(0x64);
        }
    }
    if (!((gFrameCounter >> 3) & 1))
        Sprite_Draw(gUnknown_080018C0, 0, 0xC, 0, 0x280, 0, 0);
    else
        Sprite_Draw(gUnknown_080018D8, 0, 0xC, 0, 0x280, 0, 0);
    Palette_CopyWithEffect(3, gUnknown_081B6E50, &gPaletteBuffer[0x1D0], 0x20, 0x20);
    Palette_MarkDirty();
    VBlankTask_AddCounted(sub_081556F8, 1);
    if (redraw == 1)
        sub_081556C4();
}
#else
NAKED
void sub_0815571C(struct Task *task, u32 sel)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x18\n"
        "    mov r8, r0\n"
        "    adds r6, r1, #0\n"
        "    ldr r7, .L081557D0\n"
        "    bl Fusion_CountList\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    adds r4, r0, #0\n"
        "    movs r0, #0\n"
        "    str r0, [sp, #0xc]\n"
        "    mov sl, r4\n"
        "    cmp r4, #5\n"
        "    bls .L08155746\n"
        "    movs r1, #6\n"
        "    mov sl, r1\n"
        ".L08155746:\n"
        "    adds r0, r6, #1\n"
        "    strh r0, [r7, #2]\n"
        "    strh r6, [r7, #8]\n"
        "    movs r2, #0xcc\n"
        "    lsls r2, r2, #3\n"
        "    adds r2, r2, r7\n"
        "    mov sb, r2\n"
        "    mov r0, sp\n"
        "    ldrh r0, [r0, #0xc]\n"
        "    strh r0, [r2]\n"
        "    mov r1, sp\n"
        "    ldrh r2, [r1, #0xc]\n"
        "    mov r1, r8\n"
        "    strh r2, [r1, #0x1c]\n"
        "    mov r0, sp\n"
        "    ldrh r0, [r0, #0xc]\n"
        "    strh r0, [r1, #0x1e]\n"
        "    ldr r2, .L081557D4\n"
        "    ldrh r1, [r2]\n"
        "    movs r3, #1\n"
        "    adds r0, r3, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08155850\n"
        "    ldrh r0, [r7, #6]\n"
        "    ldrh r1, [r7, #4]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0x10]\n"
        "    lsls r0, r0, #2\n"
        "    adds r4, r7, #0\n"
        "    adds r4, #0x1c\n"
        "    adds r0, r0, r4\n"
        "    ldr r0, [r0]\n"
        "    mov sl, r0\n"
        "    ldrh r0, [r0, #0x12]\n"
        "    bl sub_081544AC\n"
        "    cmp r0, #1\n"
        "    beq .L0815579A\n"
        "    b .L0815589C\n"
        ".L0815579A:\n"
        "    lsls r2, r6, #1\n"
        "    mov sb, r2\n"
        "    cmp r6, #0\n"
        "    bne .L081557F8\n"
        "    movs r5, #0\n"
        "    mov sb, r6\n"
        "    ldr r0, .L081557D8\n"
        "    adds r3, r7, r0\n"
        "    ldr r1, .L081557DC\n"
        "    adds r6, r7, r1\n"
        ".L081557AE:\n"
        "    lsls r4, r5, #2\n"
        "    ldr r2, .L081557E0\n"
        "    adds r0, r2, r4\n"
        "    ldr r2, [r0]\n"
        "    cmp r2, #0\n"
        "    beq .L081557E4\n"
        "    adds r1, r3, r4\n"
        "    ldrh r0, [r2, #0x12]\n"
        "    strh r0, [r1]\n"
        "    str r3, [sp, #0x14]\n"
        "    bl Random_Byte\n"
        "    adds r1, r6, r4\n"
        "    strh r0, [r1]\n"
        "    ldr r3, [sp, #0x14]\n"
        "    b .L081557EE\n"
        "    .byte 0x00, 0x00\n"
        ".L081557D0: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L081557D4: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L081557D8: .4byte 0x0000066C\n"
        ".L081557DC: .4byte 0x0000066E\n"
        ".L081557E0: .4byte 0x0203A470 @ EWRAM+0x3A470\n"
        ".L081557E4:\n"
        "    adds r0, r3, r4\n"
        "    ldr r1, .L08155840\n"
        "    strh r1, [r0]\n"
        "    adds r0, r6, r4\n"
        "    strh r2, [r0]\n"
        ".L081557EE:\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #0xb\n"
        "    bls .L081557AE\n"
        ".L081557F8:\n"
        "    ldr r4, .L08155844\n"
        "    mov r0, sb\n"
        "    adds r1, r0, r4\n"
        "    mov r2, sl\n"
        "    ldrh r0, [r2, #0x12]\n"
        "    strh r0, [r1]\n"
        "    ldr r0, [sp, #0x10]\n"
        "    bl sub_08153F6C\n"
        "    movs r5, #0\n"
        ".L0815580C:\n"
        "    lsls r0, r5, #2\n"
        "    ldr r1, .L08155848\n"
        "    adds r0, r1, r0\n"
        "    ldr r0, [r0]\n"
        "    cmp r0, #0\n"
        "    beq .L08155826\n"
        "    lsls r0, r5, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r1, [r0]\n"
        "    adds r0, r5, #0\n"
        "    mov r2, r8\n"
        "    bl sub_081562EC\n"
        ".L08155826:\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #2\n"
        "    bls .L0815580C\n"
        "    movs r0, #0\n"
        "    movs r1, #1\n"
        "    mov r2, r8\n"
        "    strh r1, [r2, #0x1c]\n"
        "    ldr r1, .L0815584C\n"
        "    str r0, [r1]\n"
        "    b .L0815589C\n"
        "    .byte 0x00, 0x00\n"
        ".L08155840: .4byte 0x0000FFFF\n"
        ".L08155844: .4byte 0x0203B854 @ EWRAM+0x3B854\n"
        ".L08155848: .4byte 0x0203A4A0 @ EWRAM+0x3A4A0\n"
        ".L0815584C: .4byte 0x030031CC @ IWRAM+0x31CC\n"
        ".L08155850:\n"
        "    ldrh r1, [r2]\n"
        "    movs r5, #2\n"
        "    adds r0, r5, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L0815588C\n"
        "    cmp r6, #0\n"
        "    beq .L08155872\n"
        "    lsls r0, r6, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl sub_0815565C\n"
        "    movs r0, #1\n"
        "    str r0, [sp, #0xc]\n"
        "    mov r1, r8\n"
        "    strh r0, [r1, #0x1e]\n"
        "    b .L0815587E\n"
        ".L08155872:\n"
        "    ldr r0, .L08155888\n"
        "    str r3, [r0]\n"
        "    mov r2, r8\n"
        "    strh r3, [r2, #0x1e]\n"
        "    mov r0, sb\n"
        "    strh r3, [r0]\n"
        ".L0815587E:\n"
        "    movs r0, #0x66\n"
        "    bl Sound_Play\n"
        "    b .L0815590C\n"
        "    .byte 0x00, 0x00\n"
        ".L08155888: .4byte 0x030031CC @ IWRAM+0x31CC\n"
        ".L0815588C:\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L081558A4\n"
        "    mov r1, r8\n"
        "    strh r5, [r1, #0x1e]\n"
        ".L0815589C:\n"
        "    movs r0, #0x65\n"
        "    bl Sound_Play\n"
        "    b .L0815590C\n"
        ".L081558A4:\n"
        "    ldr r0, .L081558BC\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x40\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L081558D0\n"
        "    ldrh r0, [r7, #4]\n"
        "    cmp r0, #0\n"
        "    beq .L081558C0\n"
        "    subs r0, #1\n"
        "    b .L081558E4\n"
        "    .byte 0x00, 0x00\n"
        ".L081558BC: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L081558C0:\n"
        "    ldrh r0, [r7, #6]\n"
        "    cmp r0, #0\n"
        "    beq .L0815590C\n"
        "    subs r0, #1\n"
        "    strh r0, [r7, #6]\n"
        "    movs r2, #1\n"
        "    str r2, [sp, #0xc]\n"
        "    b .L081558E6\n"
        ".L081558D0:\n"
        "    movs r0, #0x80\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L0815590C\n"
        "    ldrh r1, [r7, #4]\n"
        "    mov r0, sl\n"
        "    subs r0, #1\n"
        "    cmp r1, r0\n"
        "    beq .L081558EE\n"
        "    adds r0, r1, #1\n"
        ".L081558E4:\n"
        "    strh r0, [r7, #4]\n"
        ".L081558E6:\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        "    b .L0815590C\n"
        ".L081558EE:\n"
        "    cmp r1, #5\n"
        "    bne .L0815590C\n"
        "    ldrh r2, [r7, #6]\n"
        "    adds r0, r1, r2\n"
        "    adds r0, #1\n"
        "    subs r1, r4, #1\n"
        "    cmp r0, r1\n"
        "    bgt .L0815590C\n"
        "    adds r0, r2, #1\n"
        "    strh r0, [r7, #6]\n"
        "    movs r0, #1\n"
        "    str r0, [sp, #0xc]\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        ".L0815590C:\n"
        "    ldr r4, .L08155934\n"
        "    ldr r0, .L08155938\n"
        "    ldr r0, [r0]\n"
        "    lsrs r2, r0, #3\n"
        "    movs r0, #1\n"
        "    ands r2, r0\n"
        "    cmp r2, #0\n"
        "    bne .L08155940\n"
        "    ldr r0, .L0815593C\n"
        "    movs r1, #0xa0\n"
        "    lsls r1, r1, #2\n"
        "    str r1, [sp]\n"
        "    str r2, [sp, #4]\n"
        "    str r2, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0xc\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    b .L08155956\n"
        ".L08155934: .4byte gUnknown_081B6E50\n"
        ".L08155938: .4byte 0x030031BC @ IWRAM+0x31BC\n"
        ".L0815593C: .4byte gUnknown_080018C0\n"
        ".L08155940:\n"
        "    ldr r0, .L0815598C\n"
        "    movs r1, #0xa0\n"
        "    lsls r1, r1, #2\n"
        "    str r1, [sp]\n"
        "    movs r1, #0\n"
        "    str r1, [sp, #4]\n"
        "    str r1, [sp, #8]\n"
        "    movs r2, #0xc\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L08155956:\n"
        "    ldr r2, .L08155990\n"
        "    movs r0, #0x20\n"
        "    str r0, [sp]\n"
        "    movs r0, #3\n"
        "    adds r1, r4, #0\n"
        "    movs r3, #0x20\n"
        "    bl Palette_CopyWithEffect\n"
        "    bl Palette_MarkDirty\n"
        "    ldr r0, .L08155994\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    ldr r1, [sp, #0xc]\n"
        "    cmp r1, #1\n"
        "    bne .L0815597C\n"
        "    bl sub_081556C4\n"
        ".L0815597C:\n"
        "    add sp, #0x18\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L0815598C: .4byte gUnknown_080018D8\n"
        ".L08155990: .4byte 0x03003150 @ IWRAM+0x3150\n"
        ".L08155994: .4byte sub_081556F8\n"
    );
}
#endif

/* Draws the race, name and level of material slot (0 or 1) above the list. */
// Fusion_DrawMaterialHeader @ 0x08155998
#ifdef NONMATCHING
void Fusion_DrawMaterialHeader(u32 unused, u32 slot)
{
    struct DemonRecord *rec = Demon_GetRecord(sFusion.picks[slot]->demonId);
    const u16 *race = Race_GetName(rec->race);
    u16 x = 6;
    u16 y;
    u32 i;
    const u16 *name;
    u8 lv[3];

    switch (slot)
    {
    case 0:
        y = 0x24;
        DigitFont_DrawStringTinted(gUnknown_087E1C70, gUnk_0200F874, 6, 0x26, 10, 8);
        SmallFont_DrawAsciiTinted(gUnknown_087E1C74, gUnk_0200F874, 0xE, 0x28, 10, 8);
        break;
    case 1:
        y = 0x32;
        DigitFont_DrawStringTinted(gUnknown_087E1C78, gUnk_0200F874, 6, 0x34, 10, 8);
        SmallFont_DrawAsciiTinted(gUnknown_087E1C7C, gUnk_0200F874, 0xE, 0x36, 10, 8);
        break;
    }
    x += 0x18;
    for (i = 0; i < 3; i++)
        Font_DrawGlyphTinted(race[i], gUnk_0200F874, x + i * 12, y, 10);
    x += 0x24;
    name = rec->name;
    for (i = 0; i < 8 && name[i] != 0; i++)
    {
        if (rec->race != 0x2C)
            sub_08153FC8(rec->name[i], gUnk_0200F874, x + i * 12, y - 2, 10);
        else
            Font_DrawGlyphTinted(name[i], gUnk_0200F874, x + 4 + i * 12, y, 10);
    }
    if (sFusion.mode != 1 && sFusion.mode != 4 && sFusion.mode != 5)
    {
        x += 0x62;
        DigitFont_DrawStringTinted(gUnknown_087E1C44, gUnk_0200F874, x, y + 2, 10, 8);
        NumberToDigits(rec->level);
        if (rec->level > 9)
        {
            lv[0] = gDigits[1] + '0';
            lv[1] = gDigits[0] + '0';
            lv[2] = 0;
        }
        else
        {
            lv[0] = gDigits[0] + '0';
            lv[1] = 0;
        }
        DigitFont_DrawStringTinted(lv, gUnk_0200F874, 0xB4, y + 2, 10, 8);
    }
}
#else
NAKED
void Fusion_DrawMaterialHeader(u32 unused, u32 slot)
{
    asm_unified(
        ".L08155998:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x1c\n"
        "    adds r4, r1, #0\n"
        "    lsls r0, r4, #2\n"
        "    ldr r1, .L081559D8\n"
        "    adds r1, #0x4c\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    ldrh r0, [r0, #0x12]\n"
        "    bl Demon_GetRecord\n"
        "    mov sb, r0\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Race_GetName\n"
        "    adds r7, r0, #0\n"
        "    movs r0, #6\n"
        "    mov sl, r0\n"
        "    cmp r4, #0\n"
        "    beq .L081559DC\n"
        "    cmp r4, #1\n"
        "    beq .L08155A14\n"
        "    b .L08155A3E\n"
        "    .byte 0x00, 0x00\n"
        ".L081559D8: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L081559DC:\n"
        "    movs r1, #0x24\n"
        "    str r1, [sp, #0xc]\n"
        "    ldr r0, .L08155A08\n"
        "    ldr r6, .L08155A0C\n"
        "    movs r5, #0xa\n"
        "    str r5, [sp]\n"
        "    movs r4, #8\n"
        "    str r4, [sp, #4]\n"
        "    adds r1, r6, #0\n"
        "    movs r2, #6\n"
        "    movs r3, #0x26\n"
        "    bl DigitFont_DrawStringTinted\n"
        "    ldr r0, .L08155A10\n"
        "    str r5, [sp]\n"
        "    str r4, [sp, #4]\n"
        "    adds r1, r6, #0\n"
        "    movs r2, #0xe\n"
        "    movs r3, #0x28\n"
        "    bl SmallFont_DrawAsciiTinted\n"
        "    b .L08155A3E\n"
        ".L08155A08: .4byte gUnknown_087E1C70\n"
        ".L08155A0C: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L08155A10: .4byte gUnknown_087E1C74\n"
        ".L08155A14:\n"
        "    movs r2, #0x32\n"
        "    str r2, [sp, #0xc]\n"
        "    ldr r0, .L08155AC8\n"
        "    ldr r6, .L08155ACC\n"
        "    movs r5, #0xa\n"
        "    str r5, [sp]\n"
        "    movs r4, #8\n"
        "    str r4, [sp, #4]\n"
        "    adds r1, r6, #0\n"
        "    movs r2, #6\n"
        "    movs r3, #0x34\n"
        "    bl DigitFont_DrawStringTinted\n"
        "    ldr r0, .L08155AD0\n"
        "    str r5, [sp]\n"
        "    str r4, [sp, #4]\n"
        "    adds r1, r6, #0\n"
        "    movs r2, #0xe\n"
        "    movs r3, #0x36\n"
        "    bl SmallFont_DrawAsciiTinted\n"
        ".L08155A3E:\n"
        "    mov r0, sl\n"
        "    adds r0, #0x18\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sl, r0\n"
        "    movs r0, #0\n"
        "    mov r8, r0\n"
        "    mov r1, sb\n"
        "    adds r1, #0x22\n"
        "    str r1, [sp, #0x14]\n"
        "    mov r2, sl\n"
        "    lsls r5, r2, #0x10\n"
        "    adds r4, r7, #0\n"
        ".L08155A58:\n"
        "    ldrh r0, [r4]\n"
        "    lsrs r2, r5, #0x10\n"
        "    movs r1, #0xa\n"
        "    str r1, [sp]\n"
        "    ldr r1, .L08155ACC\n"
        "    ldr r3, [sp, #0xc]\n"
        "    bl Font_DrawGlyphTinted\n"
        "    movs r7, #0xc0\n"
        "    lsls r7, r7, #0xc\n"
        "    adds r5, r5, r7\n"
        "    adds r4, #2\n"
        "    movs r0, #1\n"
        "    add r8, r0\n"
        "    mov r1, r8\n"
        "    cmp r1, #2\n"
        "    bls .L08155A58\n"
        "    mov r0, sl\n"
        "    adds r0, #0x24\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sl, r0\n"
        "    movs r2, #0\n"
        "    mov r8, r2\n"
        "    ldr r1, [sp, #0x14]\n"
        "    mov r7, sb\n"
        "    ldrh r0, [r7, #0x22]\n"
        "    cmp r0, #0\n"
        "    beq .L08155B0C\n"
        "    mov r0, sl\n"
        "    adds r0, #4\n"
        "    str r0, [sp, #0x18]\n"
        "    adds r5, r1, #0\n"
        "    movs r6, #0\n"
        "    mov r2, sl\n"
        "    lsls r4, r2, #0x10\n"
        "    ldr r0, [sp, #0xc]\n"
        "    subs r0, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    str r0, [sp, #0x10]\n"
        ".L08155AA8:\n"
        "    mov r7, sb\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r7, r0]\n"
        "    cmp r0, #0x2c\n"
        "    beq .L08155AD4\n"
        "    adds r0, r1, r6\n"
        "    ldrh r0, [r0]\n"
        "    lsrs r2, r4, #0x10\n"
        "    movs r1, #0xa\n"
        "    str r1, [sp]\n"
        "    ldr r1, .L08155ACC\n"
        "    ldr r7, [sp, #0x10]\n"
        "    lsrs r3, r7, #0x10\n"
        "    bl sub_08153FC8\n"
        "    b .L08155AE8\n"
        ".L08155AC8: .4byte gUnknown_087E1C78\n"
        ".L08155ACC: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L08155AD0: .4byte gUnknown_087E1C7C\n"
        ".L08155AD4:\n"
        "    ldrh r0, [r5]\n"
        "    ldr r1, [sp, #0x18]\n"
        "    lsls r2, r1, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    movs r1, #0xa\n"
        "    str r1, [sp]\n"
        "    ldr r1, .L08155B68\n"
        "    ldr r3, [sp, #0xc]\n"
        "    bl Font_DrawGlyphTinted\n"
        ".L08155AE8:\n"
        "    ldr r2, [sp, #0x18]\n"
        "    adds r2, #0xc\n"
        "    str r2, [sp, #0x18]\n"
        "    adds r5, #2\n"
        "    adds r6, #2\n"
        "    movs r7, #0xc0\n"
        "    lsls r7, r7, #0xc\n"
        "    adds r4, r4, r7\n"
        "    movs r0, #1\n"
        "    add r8, r0\n"
        "    mov r1, r8\n"
        "    cmp r1, #7\n"
        "    bhi .L08155B0C\n"
        "    ldr r1, [sp, #0x14]\n"
        "    adds r0, r1, r6\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L08155AA8\n"
        ".L08155B0C:\n"
        "    ldr r2, .L08155B6C\n"
        "    ldrh r1, [r2]\n"
        "    cmp r1, #1\n"
        "    beq .L08155B9E\n"
        "    cmp r1, #4\n"
        "    beq .L08155B9E\n"
        "    cmp r1, #5\n"
        "    beq .L08155B9E\n"
        "    mov r0, sl\n"
        "    adds r0, #0x62\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sl, r0\n"
        "    ldr r0, .L08155B70\n"
        "    ldr r1, .L08155B68\n"
        "    ldr r4, [sp, #0xc]\n"
        "    adds r4, #2\n"
        "    lsls r3, r4, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    movs r2, #0xa\n"
        "    str r2, [sp]\n"
        "    movs r2, #8\n"
        "    str r2, [sp, #4]\n"
        "    mov r2, sl\n"
        "    bl DigitFont_DrawStringTinted\n"
        "    mov r7, sb\n"
        "    ldrb r0, [r7, #1]\n"
        "    bl NumberToDigits\n"
        "    ldrb r0, [r7, #1]\n"
        "    cmp r0, #9\n"
        "    bls .L08155B78\n"
        "    add r1, sp, #8\n"
        "    ldr r2, .L08155B74\n"
        "    ldrb r0, [r2, #1]\n"
        "    adds r0, #0x30\n"
        "    movs r3, #0\n"
        "    strb r0, [r1]\n"
        "    ldrb r0, [r2]\n"
        "    adds r0, #0x30\n"
        "    strb r0, [r1, #1]\n"
        "    adds r0, r1, #0\n"
        "    strb r3, [r0, #2]\n"
        "    b .L08155B88\n"
        "    .byte 0x00, 0x00\n"
        ".L08155B68: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L08155B6C: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L08155B70: .4byte gUnknown_087E1C44\n"
        ".L08155B74: .4byte 0x030020E8 @ IWRAM+0x20E8\n"
        ".L08155B78:\n"
        "    add r2, sp, #8\n"
        "    ldr r0, .L08155BB0\n"
        "    ldrb r0, [r0]\n"
        "    adds r0, #0x30\n"
        "    movs r1, #0\n"
        "    strb r0, [r2]\n"
        "    adds r0, r2, #0\n"
        "    strb r1, [r0, #1]\n"
        ".L08155B88:\n"
        "    ldr r1, .L08155BB4\n"
        "    movs r2, #0xb4\n"
        "    lsls r3, r4, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    movs r0, #0xa\n"
        "    str r0, [sp]\n"
        "    movs r0, #8\n"
        "    str r0, [sp, #4]\n"
        "    add r0, sp, #8\n"
        "    bl DigitFont_DrawStringTinted\n"
        ".L08155B9E:\n"
        "    add sp, #0x1c\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L08155BB0: .4byte 0x030020E8 @ IWRAM+0x20E8\n"
        ".L08155BB4: .4byte 0x0200F874 @ EWRAM+0xF874\n"
    );
}
#endif

// sub_08155BB8 @ 0x08155BB8
void sub_08155BB8(u32 a0, u32 slot, u32 step)
{
    struct FusionState *f = &sFusion;
    u32 zero;

    if (f->mode == 2 && slot == 1)
        return;
    if (f->mode == 1 && slot == 1)
        return;
    if (f->mode == 4 && slot == 1)
        return;
    if (f->mode == 3 && slot == 2)
        return;
    if (f->mode == 5 && slot == 2)
        return;
    if (step == 0)
    {
        f->cursor = step;
        f->top = step;
    }
    if (slot <= 1)
        Fusion_DrawMaterialHeader(a0, slot);
    if (step == 0)
    {
        Fusion_BuildMaterialList();
        f->sel++;
        if (f->mode != 1 && f->mode != 4 && f->mode != 5)
        {
            zero = 0;
            CpuSet(&zero, gUnk_02011874, 0x05000C00);
            Fusion_DrawListHeader();
            Fusion_DrawList(f->top);
        }
    }
}

// sub_08155C40 @ 0x08155C40
void sub_08155C40(struct Task *task)
{
    switch (sFusion.mode)
    {
    case 1:
    case 2:
    case 4:
        task->unk1E = 2;
        break;
    case 3:
    case 5:
        task->unk1E = 3;
        break;
    }
}

/* Leaves the material list: works out the fusion result, saves the state, fades out. */
// sub_08155C80 @ 0x08155C80
void sub_08155C80(void)
{
    struct FusionState *f = &sFusion;
    u16 out[2];
    u32 i;

    if (f->win10 != NULL)
    {
        Window_Close(f->win10, 1);
        f->win10 = NULL;
    }
    if (f->win14 != NULL)
    {
        Window_Close(f->win14, 1);
        f->win14 = NULL;
    }
    if (f->mode == 1)
    {
        sub_0815B884(gUnk_0203B854[0], 0xFFFF, gUnk_0203B854[1], &out[0], &out[1]);
        gUnk_0203B854[3] = out[0];
    }
    else if (f->mode == 4)
    {
        sub_0815B884(gUnk_0203B854[0], gUnk_0203B854[1], 0xFFFF, &out[0], &out[1]);
        gUnk_0203B854[3] = out[0];
    }
    else if (f->mode == 5)
    {
        sub_0815B884(gUnk_0203B854[0], gUnk_0203B854[1], gUnk_0203B854[2], &out[0], &out[1]);
        gUnk_0203B854[3] = out[0];
    }
    else if (f->mode == 2 || f->mode == 3)
    {
        sub_0815B260();
        gUnk_0203B854[3] = sub_081572AC();
        if (gUnk_0203B854[3] > 0xFE)
            gUnk_0203B854[3] = 0xFB;
        for (i = 0; i < 7; i++)
            gUnk_0203B860[i] = gUnk_0203B918[i];
    }
    else if (f->mode == 6)
    {
        u16 *list = gStatusList;
        u16 n = 0;

        gUnk_0203B854[3] = list[f->unk666 + f->unk66A] & 0x7FFF;
        for (i = 0; i < 7; i++)
            gUnk_0203B860[i] |= 0xFF;
        for (i = 0; i < 7; i++)
        {
            u8 skill = Demon_GetRecord(gUnk_0203B854[3])->skills[i];

            if (skill != 0xFF)
            {
                gUnk_0203B860[n] = skill;
                n++;
            }
        }
    }
    CpuSet(gMenuState, &gUnk_0203AC54, 0x04000200);
    if (f->unk660 == 1)
        f->fade->state = 1;
    else
        PalFade_FadeToBlack(1);
}

// sub_08155DF4 @ 0x08155DF4
void sub_08155DF4(void)
{
    struct FusionState *copy = &gUnk_0203AC54;

    if (copy->unk660 == 0)
    {
        u32 r = sub_080CED00();

        /* gMenuState now belongs to the next screen */
        sFusion.members[7] = (struct Combatant *)copy->fade;
        gUnk_030068E0 = r;
    }
}

/* Moves the cursor down to the next row, scrolling at the bottom. */
// sub_08155E24 @ 0x08155E24
void sub_08155E24(struct Task *task)
{
    struct FusionState *f = &sFusion;
    u32 redraw = 0;
    u16 n = Fusion_CountList();
    u16 rows = n;
    s32 idx;

    if (rows > 5)
        rows = 6;
    task->result = redraw;
    idx = f->cursor + f->top;
    if (f->members[idx]->demonId == f->unk65C)
    {
        task->result = 1;
    }
    else if (f->cursor != rows - 1)
    {
        f->cursor++;
        Sound_Play(0x64);
    }
    else if (f->cursor == 5 && idx + 1 <= n - 1)
    {
        f->top++;
        redraw = 1;
        Sound_Play(0x64);
    }
    if (redraw == 1)
        sub_081556C4();
}

// sub_08155EC0 @ 0x08155EC0
void sub_08155EC0(u32 a0)
{
    struct FusionState *f = &sFusion;

    Window_Close(f->win10, 1);
    Window_Close(f->win14, 1);
    sub_08157EB0(1, a0, f->fade);
    gYesNoResult = 1;
}

// sub_08155EF4 @ 0x08155EF4
void sub_08155EF4(void)
{
    sub_080C98A0();
    DmaFill32_3(0, 0x06000000, 0x85000400);
    DmaFill32_3(0, 0x06001000, 0x85000400);
    DmaFill32_3(0, 0x06002000, 0x85000400);
}

// sub_08155F44 @ 0x08155F44
void sub_08155F44(void)
{
    struct FusionState *f = &sFusion;

    Window_Close(f->win10, 1);
    Window_Close(f->win14, 1);
    f->win10 = NULL;
    f->win14 = NULL;
    VBlankTask_AddCounted(sub_08155EF4, 1);
}

// sub_08155F74 @ 0x08155F74
void sub_08155F74(struct Task *task)
{
    u16 r = sFusion.unk660;

    if (r != 1)
        r = 0;
    task->result = r;
}

/* Starts the fusion screen task for mode (1-6). */
// Fusion_StartScreen @ 0x08155F94
struct Task *Fusion_StartScreen(u16 mode)
{
    struct FusionState *f = &sFusion;
    struct Task *task;
    u32 zero;

    if (mode == 1 || mode == 4 || mode == 5)
        task = Task_Create(gUnknown_087E24CC, 0xFFFF);
    else if (mode == 6)
        task = Task_Create(gUnknown_087E3360, 0xFFFF);
    else
        task = Task_Create(gUnknown_087E1C80, 0xFFFF);
    zero = 0;
    CpuSet(&zero, gMenuState, 0x05000200);
    f->mode = mode;
    gUnk_0203B854[4] = mode;
    return task;
}

/* Resumes the fusion screen after the result screen, restoring the saved state. */
// Fusion_ResumeScreen @ 0x08156000
struct Task *Fusion_ResumeScreen(void)
{
    struct FusionState *f = &sFusion;
    struct Task *task;
    u16 mode = gUnk_0203B854[4];

    if (mode == 1 || mode == 4 || mode == 5)
        task = Task_Create(gUnknown_087E2974, 0xFFFF);
    else if (mode == 6)
        task = Task_Create(gUnknown_087E35F4, 0xFFFF);
    else
        task = Task_Create(gUnknown_087E2094, 0xFFFF);
    CpuSet(&gUnk_0203AC54, gMenuState, 0x04000200);
    if (f->mode == 1 || f->mode == 2 || f->mode == 4)
        f->picks[1] = NULL;
    else if (f->mode == 3 || f->mode == 5)
        f->picks[2] = NULL;
    return task;
}

/* Fills the list with the demons that can be made from fusion items (0x40-0x4F). */
// sub_08156088 @ 0x08156088
u16 sub_08156088(u32 a0, u32 a1, u32 a2)
{
    struct FusionState *f = &sFusion;
    u16 n = 0;
    u16 item = 0x40;
    u16 id = 0x156;
    u16 col;
    u16 i;

    switch (f->mode)
    {
    case 1:
        col = 0;
        break;
    case 4:
        col = 2;
        break;
    case 5:
        col = 1;
        break;
    }
    for (i = 0; i < 16; i++, item++, id++)
    {
        if (Inventory_GetCount(item) && gUnknown_087E248C[i * 4 + col] != 0)
        {
            struct Combatant *c = &f->results[n];

            Combatant_InitDemon(c, 1, id);
            f->members[n] = c;
            n++;
        }
    }
    return n;
}

// sub_08156134 @ 0x08156134
void sub_08156134(void)
{
    struct FusionState *f = &sFusion;
    u16 n;

    Fusion_ClearList();
    n = sub_08156088(0, 0, 0);
    f->unk2 = 1;
    f->count = n;
    sub_0815B880(f->count);
    gUnk_03003BB4 = 0;
}

// sub_08156170 @ 0x08156170
void sub_08156170(struct Task *task)
{
    struct FusionState *f = &sFusion;

    task->result = 0;
    if (f->mode == 1)
    {
        Fusion_ClearList();
        if (Fusion_BuildList())
            task->result = 1;
    }
    else if (f->mode == 4)
    {
        task->result = 1;
    }
    else if (f->mode == 5)
    {
        if (f->sel == 0)
        {
            task->result = 1;
        }
        else if (f->sel == 1)
        {
            Fusion_ClearList();
            if (sub_08155518())
                task->result = 1;
        }
        else if (f->sel == 2)
        {
            Fusion_ClearList();
            if (Fusion_BuildList())
                task->result = 1;
        }
    }
}
