#include "global.h"
#include "fusion.h"

/* Material preview task: opens the name window of slot. */
// sub_081561D0 @ 0x081561D0
void sub_081561D0(struct Task *task)
{
    struct MaterialTaskData *d = MATERIAL_DATA(task);
    u16 x;
    u16 y;

    switch (d->slot)
    {
    case 0:
        x = 0;
        y = 8;
        break;
    case 1:
        x = 0x14;
        y = 8;
        break;
    case 2:
        x = 0xA;
        y = 2;
        break;
    }
    d->win = Window_CreateOpen(x, y, 10, 11, 0);
}

/* Material preview task: shows the demon's sprite. */
// sub_08156218 @ 0x08156218
void sub_08156218(struct Task *task)
{
    struct MaterialTaskData *d = MATERIAL_DATA(task);
    u16 x;
    u16 y;

    switch (d->slot)
    {
    case 0:
        x = 0;
        y = 0x40;
        break;
    case 1:
        x = 0xA0;
        y = 0x40;
        break;
    case 2:
        x = 0x50;
        y = 0x10;
        break;
    }
    d->obj = DemonObj_Create(0, d->id, x, y, 0, 0);
    sub_080C3E40(d->obj, 0);
    gPaletteBuffer[0xD0] = 0x10;
    gPaletteBuffer[0xD1] = 0x10;
}

/* Material preview task: A closes, B also takes the material back. */
// sub_0815627C @ 0x0815627C
void sub_0815627C(struct Task *task)
{
    struct FusionState *f = &sFusion;
    struct MaterialTaskData *d = MATERIAL_DATA(task);

    if (gKeysNew & 1)
    {
        task->result = 1;
    }
    else
    {
        u16 b = gKeysNew & 2;

        if (b)
        {
            task->result = 1;
            if (f->sel == d->slot)
            {
                f->unkA = 1;
                f->picks[d->slot] = NULL;
            }
        }
        else
        {
            task->result = b;
        }
    }
}

// sub_081562D0 @ 0x081562D0
void sub_081562D0(struct Task *task)
{
    struct MaterialTaskData *d = MATERIAL_DATA(task);

    Window_Close(d->win, 1);
    DemonObj_End(d->obj, 0);
}

// sub_081562EC @ 0x081562EC
void sub_081562EC(u16 slot, u16 id, struct Task *parent)
{
    struct FusionState *f;
    /* pinned: plain C leaves task in r0 and puts the 0 in r1 */
    register struct Task *task asm("r2");

    task = Task_Create(gUnknown_087E2E3C, parent->id);
    f = &sFusion;
    task->data.h[0] = id;
    task->data.h[1] = slot;
    f->unkA = 0;
}

/* Opens the status screen of the demon under the cursor (saves the fusion state first). */
// sub_0815631C @ 0x0815631C
void sub_0815631C(struct Task *task)
{
    struct FusionState *f = &sFusion;
    u16 id = f->members[f->cursor + f->top]->demonId;
    u32 zero;

    Task_Create(gUnknown_084F1368, task->id);
    CpuSet(f, &gUnk_0203AC54, 0x04000200);
    zero = 0;
    CpuSet(&zero, f, 0x05000200);
    f->unk2 = id;
    f->mode = 7;
    ((u16 *)f)[0x11] = 0;
}

// sub_0815637C @ 0x0815637C
void sub_0815637C(void)
{
    DmaSet3(gUnknown_081B93B0, 0x06000000, 0x84000200);
    DmaSet3(gUnk_0200F874, 0x06004000, 0x84001F00);
}

// sub_081563B8 @ 0x081563B8
void sub_081563B8(void)
{
    DmaFill32_3(0, 0x06000000, 0x85000400);
    DmaFill32_3(0, 0x06004000, 0x85001F00);
}

/* Mode 6 (choosing a demon from the compendium list): level, race class, alignment, cost. */
// sub_081563F4 @ 0x081563F4
void sub_081563F4(struct Task *task)
{
    struct FusionState *f = &sFusion;
    u16 id = gStatusList[f->unk66A + f->unk666] & 0x7FFF;
    u16 x = 0x82;
    u16 y = 0x45;
    struct DemonRecord *rec = Demon_GetRecord(id);
    s32 align = sub_0815B864(id);
    s32 cost = Compendium_GetPrice(id);
    u32 zero = 0;

    CpuSet(&zero, gUnk_0200F874, 0x05002000);
    SmallFont_DrawAscii(gUnknown_087E1C44, 0x82, 0x45, 4);
    if (rec->level < 10)
        SmallFont_DrawNumber(rec->level, 0xD4, 0x45, 0);
    else
        SmallFont_DrawNumber(rec->level, 0xD4, 0x45, 0);
    y += 10;
    SmallFont_DrawAscii(gUnknown_087E3250, x, y, 4);
    if (rec->race <= 12)
        SmallFont_DrawAscii(gUnknown_087E3254, x + 0x32, y, 0);
    else if (rec->race <= 26)
        SmallFont_DrawAscii(gUnknown_087E325C, x + 0x22, y, 0);
    else
        SmallFont_DrawAscii(gUnknown_087E3264, x + 0x3A, y, 0);
    y += 10;
    if (align == 0)
        SmallFont_DrawAscii(gUnknown_087E326C, x + 0x42, y, 0);
    else if (align == 1)
        SmallFont_DrawAscii(gUnknown_087E325C, x + 0x22, y, 0);
    else if (align == 2)
        SmallFont_DrawAscii(gUnknown_087E3270, x + 0x32, y, 0);
    y += 10;
    SmallFont_DrawAscii(gUnknown_087E3278, x, y, 4);
    SmallFont_DrawNumber(cost, x + 0x52, y, 0);
    VBlankTask_AddCounted(sub_0815637C, 1);
}

// sub_0815656C @ 0x0815656C
void sub_0815656C(void)
{
    DmaSet3(gUnk_02000000, 0x06001000, 0x84000400);
    REG_BG1CNT = 0x8209;
}

// sub_0815659C @ 0x0815659C
void sub_0815659C(void)
{
    VBlankTask_AddCounted(sub_0815656C, 1);
    sub_080C1440();
}

// sub_081565B4 @ 0x081565B4
void sub_081565B4(struct Task *task, u32 step)
{
    u32 zero;

    switch (step)
    {
    case 0:
        zero = 0;
        CpuSet(&zero, gUnk_02000000, 0x05000400);
        VBlankTask_AddCounted(sub_081563B8, 1);
        break;
    case 1:
        Tilemap_CopyRectSkipZero(gUnknown_087E2E84, gUnk_02000000, 0, 0, 0, 0, 10, 7);
        break;
    case 2:
        Tilemap_CopyRectSkipZero(gUnknown_087E3044, gUnk_02000000, 0, 0, 10, 0, 11, 7);
        break;
    case 3:
        break;
    case 4:
        Tilemap_CopyRectStride(gUnknown_08770A24, gUnk_02000000, 0, 0, 0, 7, 0x1C, 10, 0x1C);
        Tilemap_CopyRectSkipZero(gUnknown_081B8170, gUnk_02000000, 0, 0, 0x16, 2, 8, 2);
        Tilemap_CopyRectSkipZero(gUnknown_081B8170, gUnk_02000000, 0, 0, 0x16, 0, 8, 2);
        sub_081563F4(task);
        break;
    }
}

// sub_081566C4 @ 0x081566C4
void sub_081566C4(void)
{
    struct FusionState *f = &sFusion;

    f->fade = sub_080B6B58(sub_0815468C, 1);
}

// sub_081566E0 @ 0x081566E0
u8 sub_081566E0(void)
{
    return sFusion.unk664;
}

// sub_081566F4 @ 0x081566F4
u16 sub_081566F4(void)
{
    switch (sub_081566E0())
    {
    case 0:
        return 0x25;
    case 1:
        return 10;
    case 2:
        return 8;
    }
}

// sub_08156724 @ 0x08156724
void sub_08156724(struct Task *task)
{
    struct FusionState *f = &sFusion;

    Sprite_Draw(gUnknown_08002164, 0, 0, 0, 0, 8, f->unk664 * 16 + 4);
    Text_DrawSpriteString(gUnknown_087E327E, 0, 0, 8, 4, 0xC);
    Text_DrawSpriteString(gUnknown_087E3288, 0, 0, 8, 0x14, 0xC);
    Text_DrawSpriteString(gUnknown_087E3292, 0, 0, 8, 0x24, 0xC);
}

/* Draws the page list (races, ... ) of the compendium fusion menu. */
// sub_081567A4 @ 0x081567A4
void sub_081567A4(struct Task *task)
{
    struct FusionState *f = &sFusion;
    u8 page = sub_081566E0();
    u8 top = f->unk669;
    u16 x = 0x58;
    u16 y = 4;
    u8 i;
    u8 j;
    const u16 *name;

    sub_08156724(task);
    Sprite_Draw(gUnknown_08002198, 0, 0, 0, 0, x, f->unk665 * 16 + 4);
    switch (page)
    {
    case 0:
        for (i = 0; i < 3; i++)
        {
            name = Race_GetName(gUnknown_087E3204[top + i]);
            for (j = 0; j < 8; j++)
                FontSprite_DrawGlyph(name[j], 0, 0, x + j * 12, (i << 4) | y);
        }
        break;
    case 1:
        for (i = 0; i < 3; i++)
            Text_DrawSpriteString(gUnknown_087E32A0[top + i], 0, 0, x, (i << 4) | y, 0xC);
        break;
    case 2:
        for (i = 0; i < 3; i++)
            Text_DrawSpriteString(gUnknown_087E3340[top + i], 0, 0, x, (i << 4) | y, 0xC);
        break;
    }
    if (f->unk669 != 0)
        sub_080C4A4C(0, 0, x + 0x48, y);
    if (f->unk669 + 3 <= (u16)sub_081566F4() - 1)
        sub_080C4AB0(0, 0, x + 0x48, y + 0x28);
}

/* Draws the compendium demon list: money, magnetite and six names (grey when not affordable). */
// sub_08156924 @ 0x08156924
#ifdef NONMATCHING
void sub_08156924(struct Task *task)
{
    u16 tint;
    struct FusionState *f = &sFusion;
    u16 x = 8;
    u16 y = 0x3A;
    u16 i;
    u16 j;
    u16 entry;
    const u16 *name;
    u16 row;

    sub_08156724(task);
    sub_081567A4(task);
    Sprite_Draw(gUnknown_080021E4, 0, 0, 0, 0, 8, f->unk666 * 12 + 0x3A);
    sub_080C7664(0x16, 2, gGameState.money);
    Sprite_Draw(gUnknown_080007FC, 0, 0, 0, 0, 0xB2, 5);
    sub_080C7FD0(Magnetite_Get(), 0xB8, 5, 0, 0);
    for (i = 0; i < 6; i++)
    {
        entry = gStatusList[f->unk66A + i];
        if (entry != 0xFFFF)
        {
            name = Demon_GetRecord(entry & 0x7FFF)->name;
            j = 0;
            row = y + i * 12;
            for (; j < 8; j++)
            {
                tint = 0;
                if (!Compendium_CanSummon(entry & 0x7FFF))
                    tint = 10;
                else if (entry & 0x8000)
                    tint = 1;
                FontSprite_DrawGlyphTinted(name[j], 0, 0, x + j * 12, row, tint);
            }
        }
    }
    if (f->unk66A != 0)
        sub_080C4A4C(0, 0, x + 0x6A, y + 2);
    if (f->unk66A + 6 <= Compendium_CountList() - 1)
        sub_080C4AB0(0, 0, x + 0x6A, y + 0x44);
}
#else
NAKED
void sub_08156924(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0xc\n"
        "    adds r4, r0, #0\n"
        "    bl sub_08156724\n"
        "    adds r0, r4, #0\n"
        "    bl sub_081567A4\n"
        "    ldr r0, .L081569F0\n"
        "    movs r4, #0\n"
        "    str r4, [sp]\n"
        "    movs r1, #8\n"
        "    str r1, [sp, #4]\n"
        "    ldr r2, .L081569F4\n"
        "    ldr r3, .L081569F8\n"
        "    adds r1, r2, r3\n"
        "    ldrb r2, [r1]\n"
        "    lsls r1, r2, #1\n"
        "    adds r1, r1, r2\n"
        "    lsls r1, r1, #0x12\n"
        "    movs r2, #0xe8\n"
        "    lsls r2, r2, #0xe\n"
        "    adds r1, r1, r2\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    ldr r0, .L081569FC\n"
        "    ldr r3, .L08156A00\n"
        "    adds r0, r0, r3\n"
        "    ldr r2, [r0]\n"
        "    movs r0, #0x16\n"
        "    movs r1, #2\n"
        "    bl sub_080C7664\n"
        "    ldr r0, .L08156A04\n"
        "    str r4, [sp]\n"
        "    movs r1, #0xb2\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #5\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    bl Magnetite_Get\n"
        "    str r4, [sp]\n"
        "    movs r1, #0xb8\n"
        "    movs r2, #5\n"
        "    movs r3, #0\n"
        "    bl sub_080C7FD0\n"
        "    movs r6, #0\n"
        ".L081569A0:\n"
        "    ldr r1, .L081569F4\n"
        "    ldr r2, .L08156A08\n"
        "    adds r0, r1, r2\n"
        "    ldrb r0, [r0]\n"
        "    adds r0, r0, r6\n"
        "    lsls r0, r0, #1\n"
        "    ldr r3, .L08156A0C\n"
        "    adds r0, r0, r3\n"
        "    ldrh r7, [r0]\n"
        "    ldr r0, .L08156A10\n"
        "    adds r1, r6, #1\n"
        "    mov sl, r1\n"
        "    cmp r7, r0\n"
        "    beq .L08156A52\n"
        "    ldr r2, .L08156A14\n"
        "    adds r0, r2, #0\n"
        "    adds r4, r7, #0\n"
        "    ands r4, r0\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r0, r4, #0x10\n"
        "    bl Demon_GetRecord\n"
        "    adds r0, #0x22\n"
        "    mov sb, r0\n"
        "    movs r5, #0\n"
        "    lsls r0, r6, #1\n"
        "    adds r0, r0, r6\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, #0x3a\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        ".L081569E0:\n"
        "    movs r6, #0\n"
        "    lsrs r0, r4, #0x10\n"
        "    bl Compendium_CanSummon\n"
        "    cmp r0, #0\n"
        "    bne .L08156A18\n"
        "    movs r6, #0xa\n"
        "    b .L08156A28\n"
        ".L081569F0: .4byte gUnknown_080021E4\n"
        ".L081569F4: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L081569F8: .4byte 0x00000666\n"
        ".L081569FC: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L08156A00: .4byte 0x00000AD8\n"
        ".L08156A04: .4byte gUnknown_080007FC\n"
        ".L08156A08: .4byte 0x0000066A\n"
        ".L08156A0C: .4byte 0x0203B554 @ EWRAM+0x3B554\n"
        ".L08156A10: .4byte 0x0000FFFF\n"
        ".L08156A14: .4byte 0x00007FFF\n"
        ".L08156A18:\n"
        "    movs r3, #0x80\n"
        "    lsls r3, r3, #8\n"
        "    adds r1, r3, #0\n"
        "    adds r0, r7, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08156A28\n"
        "    movs r6, #1\n"
        ".L08156A28:\n"
        "    lsls r3, r5, #1\n"
        "    mov r1, sb\n"
        "    adds r0, r3, r1\n"
        "    ldrh r0, [r0]\n"
        "    adds r3, r3, r5\n"
        "    lsls r3, r3, #2\n"
        "    adds r3, #8\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    mov r2, r8\n"
        "    str r2, [sp]\n"
        "    str r6, [sp, #4]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    bl FontSprite_DrawGlyphTinted\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #7\n"
        "    bls .L081569E0\n"
        ".L08156A52:\n"
        "    mov r3, sl\n"
        "    lsls r0, r3, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r6, #5\n"
        "    bls .L081569A0\n"
        "    ldr r0, .L08156AA8\n"
        "    ldr r1, .L08156AAC\n"
        "    adds r4, r0, r1\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #0\n"
        "    beq .L08156A78\n"
        "    movs r2, #8\n"
        "    adds r2, #0x6a\n"
        "    movs r3, #0x3a\n"
        "    adds r3, #2\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    bl sub_080C4A4C\n"
        ".L08156A78:\n"
        "    ldrb r4, [r4]\n"
        "    adds r4, #6\n"
        "    bl Compendium_CountList\n"
        "    subs r0, #1\n"
        "    cmp r4, r0\n"
        "    bhi .L08156A96\n"
        "    movs r2, #8\n"
        "    adds r2, #0x6a\n"
        "    movs r3, #0x3a\n"
        "    adds r3, #0x44\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    bl sub_080C4AB0\n"
        ".L08156A96:\n"
        "    add sp, #0xc\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L08156AA8: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L08156AAC: .4byte 0x0000066A\n"
    );
}
#endif

// sub_08156AB0 @ 0x08156AB0
void sub_08156AB0(struct Task *task)
{
    struct FusionState *f = &sFusion;
    u8 *page = &f->unk664;

    task->result = 0;
    f->unk660 = 0;
    if (gKeysNew & 1)
    {
        f->unk665 = 0;
        f->unk669 = 0;
        task->result = 1;
        task->unk1E = 0;
        Sound_Play(0x65);
    }
    else if (gKeysNew & 2)
    {
        task->result = 1;
        task->unk1E = 1;
        Sound_Play(0x66);
        f->unk660 = 1;
    }
    else if (gRepeatedKeys & 0x40)
    {
        if (*page != 0)
            (*page)--;
        else
            *page = 2;
        Sound_Play(0x64);
    }
    else if (gRepeatedKeys & 0x80)
    {
        if (*page != 2)
            (*page)++;
        else
            *page = 0;
        Sound_Play(0x64);
    }
}

/* Cursor/scroll input of a list of count entries showing rows at a time (L/R page).
   mode 1: the compendium demon list (A refuses demons that cannot be afforded). */
// List_HandleScrollInput @ 0x08156B74
#ifdef NONMATCHING
void List_HandleScrollInput(struct Task *task, u16 count, u16 rows, u8 *cursor, u8 *top, u32 mode)
{
    u16 vis;
    u8 c0;
    u8 t0;

    vis = count;
    if (count >= rows)
        vis = rows;
    task->result = 0;
    task->unk1E = 0;
    if (gKeysNew & 1)
    {
        if (mode != 0 && !Compendium_CanSummon(gStatusList[*cursor + *top] & 0x7FFF))
        {
            Sound_Play(0x66);
        }
        else
        {
            task->unk1E = 0;
            task->result = 1;
            Sound_Play(0x65);
        }
    }
    else if (gKeysNew & 2)
    {
        task->unk1E = 1;
        Sound_Play(0x66);
        task->result = 1;
    }
    else if (gRepeatedKeys & 0x40)
    {
        Font_ResetGlyphSpriteCache(0x180);
        if (*cursor != 0)
        {
            (*cursor)--;
            Sound_Play(0x64);
            if (mode == 1)
                sub_081563F4(task);
        }
        else if (*top != 0)
        {
            (*top)--;
            Sound_Play(0x64);
            if (mode == 1)
                sub_081563F4(task);
        }
    }
    else if (gRepeatedKeys & 0x80)
    {
        Font_ResetGlyphSpriteCache(0x180);
        if (*cursor != vis - 1)
        {
            (*cursor)++;
            Sound_Play(0x64);
            if (mode == 1)
                sub_081563F4(task);
        }
        else if (*cursor == rows - 1 && *cursor + *top + 1 <= count - 1)
        {
            (*top)++;
            Sound_Play(0x64);
            if (mode == 1)
                sub_081563F4(task);
        }
    }
    else if ((gRepeatedKeys & 0x200) && count > rows)
    {
        u8 c1 = *cursor;
        u8 t1 = *top;
        Font_ResetGlyphSpriteCache(0x180);
        if (*cursor != 0)
        {
            *cursor = 0;
            if (mode == 1)
                sub_081563F4(task);
        }
        else if (*top >= rows - 1)
        {
            *top += 1 - rows;
            if (mode == 1)
                sub_081563F4(task);
        }
        else
        {
            *top = 0;
            if (mode == 1)
                sub_081563F4(task);
        }
        if (c1 != *cursor || t1 != *top)
            Sound_Play(0x64);
    }
    else if ((gRepeatedKeys & 0x100) && count > rows)
    {
        c0 = *cursor;
        t0 = *top;
        Font_ResetGlyphSpriteCache(0x180);
        if (*cursor != rows - 1)
        {
            *cursor = rows - 1;
            if (mode == 1)
                sub_081563F4(task);
        }
        else if (*cursor + *top + rows < count - 1)
        {
            *top = *top + rows;
            if (mode == 1)
                sub_081563F4(task);
        }
        else
        {
            *top = count - rows;
            if (mode == 1)
                sub_081563F4(task);
        }
        if (c0 != *cursor || t0 != *top)
            Sound_Play(0x64);
    }
}
#else
NAKED
void List_HandleScrollInput(struct Task *task, u16 count, u16 rows, u8 *cursor, u8 *top, u32 mode)
{
    asm_unified(
        ".L08156B74:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #8\n"
        "    adds r5, r0, #0\n"
        "    adds r7, r3, #0\n"
        "    ldr r0, [sp, #0x28]\n"
        "    mov sb, r0\n"
        "    ldr r3, [sp, #0x2c]\n"
        "    mov sl, r3\n"
        "    lsls r1, r1, #0x10\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r4, r2, #0x10\n"
        "    lsrs r6, r1, #0x10\n"
        "    str r6, [sp]\n"
        "    cmp r6, r4\n"
        "    blo .L08156B9C\n"
        "    str r4, [sp]\n"
        ".L08156B9C:\n"
        "    movs r0, #0\n"
        "    strh r0, [r5, #0x1c]\n"
        "    strh r0, [r5, #0x1e]\n"
        "    ldr r2, .L08156BDC\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #1\n"
        "    mov r8, r0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08156BF8\n"
        "    mov r1, sl\n"
        "    cmp r1, #0\n"
        "    beq .L08156BE8\n"
        "    ldr r2, .L08156BE0\n"
        "    ldrb r0, [r7]\n"
        "    mov r3, sb\n"
        "    ldrb r1, [r3]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L08156BE4\n"
        "    ands r0, r1\n"
        "    bl Compendium_CanSummon\n"
        "    cmp r0, #0\n"
        "    bne .L08156BE8\n"
        "    movs r0, #0x66\n"
        "    bl Sound_Play\n"
        "    b .L08156DA4\n"
        "    .byte 0x00, 0x00\n"
        ".L08156BDC: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L08156BE0: .4byte 0x0203B554 @ EWRAM+0x3B554\n"
        ".L08156BE4: .4byte 0x00007FFF\n"
        ".L08156BE8:\n"
        "    movs r0, #0\n"
        "    strh r0, [r5, #0x1e]\n"
        "    movs r0, #1\n"
        "    strh r0, [r5, #0x1c]\n"
        "    movs r0, #0x65\n"
        "    bl Sound_Play\n"
        "    b .L08156DA4\n"
        ".L08156BF8:\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08156C12\n"
        "    mov r0, r8\n"
        "    strh r0, [r5, #0x1e]\n"
        "    movs r0, #0x66\n"
        "    bl Sound_Play\n"
        "    mov r1, r8\n"
        "    strh r1, [r5, #0x1c]\n"
        "    b .L08156DA4\n"
        ".L08156C12:\n"
        "    ldr r1, .L08156C40\n"
        "    ldrh r2, [r1]\n"
        "    movs r0, #0x40\n"
        "    ands r0, r2\n"
        "    cmp r0, #0\n"
        "    beq .L08156C52\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #1\n"
        "    bl Font_ResetGlyphSpriteCache\n"
        "    ldrb r0, [r7]\n"
        "    cmp r0, #0\n"
        "    beq .L08156C44\n"
        "    subs r0, #1\n"
        "    strb r0, [r7]\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        "    mov r2, sl\n"
        "    cmp r2, #1\n"
        "    beq .L08156C3E\n"
        "    b .L08156DA4\n"
        ".L08156C3E:\n"
        "    b .L08156CA8\n"
        ".L08156C40: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L08156C44:\n"
        "    mov r3, sb\n"
        "    ldrb r0, [r3]\n"
        "    cmp r0, #0\n"
        "    bne .L08156C4E\n"
        "    b .L08156DA4\n"
        ".L08156C4E:\n"
        "    subs r0, #1\n"
        "    b .L08156C9A\n"
        ".L08156C52:\n"
        "    movs r0, #0x80\n"
        "    ands r0, r2\n"
        "    cmp r0, #0\n"
        "    beq .L08156CB0\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #1\n"
        "    bl Font_ResetGlyphSpriteCache\n"
        "    ldrb r1, [r7]\n"
        "    ldr r0, [sp]\n"
        "    subs r0, #1\n"
        "    cmp r1, r0\n"
        "    beq .L08156C80\n"
        "    adds r0, r1, #1\n"
        "    strb r0, [r7]\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        "    mov r1, sl\n"
        "    cmp r1, #1\n"
        "    beq .L08156C7E\n"
        "    b .L08156DA4\n"
        ".L08156C7E:\n"
        "    b .L08156CA8\n"
        ".L08156C80:\n"
        "    subs r0, r4, #1\n"
        "    cmp r1, r0\n"
        "    beq .L08156C88\n"
        "    b .L08156DA4\n"
        ".L08156C88:\n"
        "    mov r3, sb\n"
        "    ldrb r2, [r3]\n"
        "    adds r0, r1, r2\n"
        "    adds r0, #1\n"
        "    subs r1, r6, #1\n"
        "    cmp r0, r1\n"
        "    ble .L08156C98\n"
        "    b .L08156DA4\n"
        ".L08156C98:\n"
        "    adds r0, r2, #1\n"
        ".L08156C9A:\n"
        "    strb r0, [r3]\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        "    mov r0, sl\n"
        "    cmp r0, #1\n"
        "    bne .L08156DA4\n"
        ".L08156CA8:\n"
        "    adds r0, r5, #0\n"
        "    bl sub_081563F4\n"
        "    b .L08156DA4\n"
        ".L08156CB0:\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #2\n"
        "    ands r0, r2\n"
        "    cmp r0, #0\n"
        "    beq .L08156D28\n"
        "    cmp r6, r4\n"
        "    bls .L08156D28\n"
        "    ldrb r6, [r7]\n"
        "    mov r1, sb\n"
        "    ldrb r1, [r1]\n"
        "    mov r8, r1\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #1\n"
        "    bl Font_ResetGlyphSpriteCache\n"
        "    ldrb r0, [r7]\n"
        "    cmp r0, #0\n"
        "    beq .L08156CE0\n"
        "    movs r2, #0\n"
        "    strb r2, [r7]\n"
        "    mov r3, sl\n"
        "    cmp r3, #1\n"
        "    bne .L08156D12\n"
        "    b .L08156CF8\n"
        ".L08156CE0:\n"
        "    mov r0, sb\n"
        "    ldrb r1, [r0]\n"
        "    subs r0, r4, #1\n"
        "    cmp r1, r0\n"
        "    blt .L08156D00\n"
        "    adds r0, r1, #1\n"
        "    subs r0, r0, r4\n"
        "    mov r1, sb\n"
        "    strb r0, [r1]\n"
        "    mov r2, sl\n"
        "    cmp r2, #1\n"
        "    bne .L08156D12\n"
        ".L08156CF8:\n"
        "    adds r0, r5, #0\n"
        "    bl sub_081563F4\n"
        "    b .L08156D12\n"
        ".L08156D00:\n"
        "    movs r0, #0\n"
        "    mov r3, sb\n"
        "    strb r0, [r3]\n"
        "    mov r1, sl\n"
        "    cmp r1, #1\n"
        "    bne .L08156D12\n"
        "    adds r0, r5, #0\n"
        "    bl sub_081563F4\n"
        ".L08156D12:\n"
        "    ldrb r7, [r7]\n"
        "    cmp r6, r7\n"
        "    bne .L08156D20\n"
        "    mov r2, sb\n"
        "    ldrb r2, [r2]\n"
        "    cmp r8, r2\n"
        "    beq .L08156DA4\n"
        ".L08156D20:\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        "    b .L08156DA4\n"
        ".L08156D28:\n"
        "    ldrh r1, [r1]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08156DA4\n"
        "    cmp r6, r4\n"
        "    bls .L08156DA4\n"
        "    ldrb r3, [r7]\n"
        "    mov r8, r3\n"
        "    mov r0, sb\n"
        "    ldrb r0, [r0]\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #1\n"
        "    bl Font_ResetGlyphSpriteCache\n"
        "    ldrb r0, [r7]\n"
        "    subs r1, r4, #1\n"
        "    cmp r0, r1\n"
        "    beq .L08156D5C\n"
        "    strb r1, [r7]\n"
        "    mov r1, sl\n"
        "    cmp r1, #1\n"
        "    bne .L08156D8E\n"
        "    b .L08156D74\n"
        ".L08156D5C:\n"
        "    mov r3, sb\n"
        "    ldrb r2, [r3]\n"
        "    adds r0, r0, r2\n"
        "    adds r0, r0, r4\n"
        "    subs r1, r6, #1\n"
        "    cmp r0, r1\n"
        "    bge .L08156D7C\n"
        "    adds r0, r2, r4\n"
        "    strb r0, [r3]\n"
        "    mov r0, sl\n"
        "    cmp r0, #1\n"
        "    bne .L08156D8E\n"
        ".L08156D74:\n"
        "    adds r0, r5, #0\n"
        "    bl sub_081563F4\n"
        "    b .L08156D8E\n"
        ".L08156D7C:\n"
        "    subs r0, r6, r4\n"
        "    mov r1, sb\n"
        "    strb r0, [r1]\n"
        "    mov r2, sl\n"
        "    cmp r2, #1\n"
        "    bne .L08156D8E\n"
        "    adds r0, r5, #0\n"
        "    bl sub_081563F4\n"
        ".L08156D8E:\n"
        "    ldrb r7, [r7]\n"
        "    cmp r8, r7\n"
        "    bne .L08156D9E\n"
        "    ldr r0, [sp, #4]\n"
        "    mov r3, sb\n"
        "    ldrb r3, [r3]\n"
        "    cmp r0, r3\n"
        "    beq .L08156DA4\n"
        ".L08156D9E:\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        ".L08156DA4:\n"
        "    add sp, #8\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

// sub_08156DB4 @ 0x08156DB4
void sub_08156DB4(struct Task *task)
{
    struct FusionState *f = &sFusion;

    List_HandleScrollInput(task, sub_081566F4(), 3, &f->unk665, &f->unk669, 0);
    if (task->result != 0)
    {
        f->unk666 = 0;
        f->unk66A = 0;
        Compendium_BuildList(task, f->unk664 + 1, f->unk665 + f->unk669, 1);
    }
}

// sub_08156E2C @ 0x08156E2C
void sub_08156E2C(struct Task *task)
{
    struct FusionState *f = &sFusion;

    List_HandleScrollInput(task, Compendium_CountList(), 6, &f->unk666, &f->unk66A, 1);
}

// sub_08156E64 @ 0x08156E64
void sub_08156E64(void)
{
    u32 zero;

    gUnk_03003BB4 = 0;
    zero = 0;
    CpuSet(&zero, gUnk_0200F874, 0x05002000);
    VBlankTask_AddCounted(sub_081563B8, 1);
}

// sub_08156E98 @ 0x08156E98
void sub_08156E98(struct Task *task)
{
    struct FusionState *f = &sFusion;

    Compendium_BuildList(task, f->unk664 + 1, f->unk665 + f->unk669, 0);
}

/* Builds gStatusList for compendium page (0 all, 1 by race, 2 by alignment, 3 by level range)
   and row of that page; entries that do not fit are marked with bit 15. */
// Compendium_BuildList @ 0x08156ECC
#ifdef NONMATCHING
void Compendium_BuildList(struct Task *task, u32 page, u32 row, u32 setCursor)
{
    u16 *list = gStatusList;
    s32 first = 0;
    u32 found = 0;
    u16 end = 0xFFFF;
    u16 fill = end;
    u32 i;
    u16 n;
    u16 j;
    u16 id;
    u16 *p;
    u32 level;
    u16 lo;
    u16 hi;

    CpuSet(&fill, list, 0x01000180);
    if (page == 0)
    {
        for (i = 0; i <= 0x17B; i++)
        {
            if (sub_080C28CC(i))
                *list++ = i;
        }
    }
    else if (page == 1)
    {
        n = 0;
        i = 0;
        {
            const u16 *t = gUnknown_087E3204;
            row = (u32)&t[row];
        }
        for (; i <= 0xFE; i++)
        {
            if (sub_080C28CC(i))
            {
                if (Demon_GetRecord(i)->race == *(const u16 *)row)
                {
                    list[n] = i;
                    if (!found)
                    {
                        first = n;
                        found = 1;
                    }
                }
                else
                {
                    list[n] = i + 0x8000;
                }
                n++;
            }
        }
    }
    else if (page == 2)
    {
        u32 got = 0;
        u16 k = 0;

        j = 0;
        id = gUnknown_08585C34[0].id;
        if (id != end)
        {
            for (;;)
            {
                if (sub_080C28CC(id))
                {
                    u16 align;

                    *list = id;
                    align = (&gUnknown_08585C34[0].align)[j * 2];
                    if (align != row)
                    {
                        id |= 0x8000;
                        *list = id;
                    }
                    list++;
                    if (!got && align == row)
                    {
                        first = k;
                        got = 1;
                    }
                    k++;
                }
                if (++j > 0x17B || (id = gUnknown_08585C34[j].id) == 0xFFFF)
                    break;
            }
        }
    }
    else if (page == 3)
    {
        p = (u16 *)sub_080C9210(2);
        {
            /* the first entry is read before level is computed */
            u16 v = *p;

            level = row + 1;
            if (v != end)
            {
                do
                {
                    if (sub_080C28CC(*p))
                        *list++ = *p;
                    p += 2;
                } while (*p != 0xFFFF);
            }
        }
        list = gStatusList;
        for (i = 0; i <= 0x17B; i++)
        {
            u8 lv;

            if (list[i] != 0xFFFF)
            {
                hi = (row + 1) * 10 - 1;
                lv = Demon_GetRecord(list[i] & 0x7FFF)->level;
                lo = row == 0 ? 1 : row * 10;
                if (hi > 100)
                    hi = 200;
                if (lv >= lo && lv <= hi)
                {
                    first = (u16)i;
                    break;
                }
            }
            else
            {
                first = 0;
                break;
            }
        }
        i = 0;
        hi = level * 10;
        p = list;
        while (*p != 0xFFFF)
        {
            if (hi > 100)
                hi = 200;
            if (Demon_GetRecord(*p & 0x7FFF)->level < hi)
            {
                if (row != 0 && Demon_GetRecord(*p & 0x7FFF)->level < row * 10)
                    *p |= 0x8000;
            }
            else
                *p |= 0x8000;
            p++;
            i++;
            if (i > 0x17B)
                break;
            hi = level * 10;
        }
    }
    if (setCursor == 1)
    {
        struct FusionState *f = &sFusion;
        u16 count = Compendium_CountList();
        u8 *cur = &f->unk666;
        u8 *top = &f->unk66A;

        *cur = 0;
        *top = 0;
        if (count <= 6)
        {
            *cur = first;
            *top = 0;
        }
        else if (first > count - 7)
        {
            u16 d = first + 6 - count;

            *top = first - d;
            *cur = d;
        }
        else
        {
            *top = first;
        }
    }
}
#else
NAKED
void Compendium_BuildList(struct Task *task, u32 page, u32 row, u32 setCursor)
{
    asm_unified(
        ".L08156ECC:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x10\n"
        "    adds r4, r1, #0\n"
        "    mov r8, r2\n"
        "    str r3, [sp, #4]\n"
        "    ldr r7, .L08156F14\n"
        "    movs r0, #0\n"
        "    str r0, [sp, #8]\n"
        "    movs r5, #0\n"
        "    mov r0, sp\n"
        "    ldr r1, .L08156F18\n"
        "    mov sb, r1\n"
        "    strh r1, [r0]\n"
        "    ldr r2, .L08156F1C\n"
        "    adds r1, r7, #0\n"
        "    bl CpuSet\n"
        "    cmp r4, #0\n"
        "    bne .L08156F24\n"
        "    movs r6, #0\n"
        "    ldr r4, .L08156F20\n"
        ".L08156EFE:\n"
        "    adds r0, r6, #0\n"
        "    bl sub_080C28CC\n"
        "    cmp r0, #0\n"
        "    beq .L08156F0C\n"
        "    strh r6, [r7]\n"
        "    adds r7, #2\n"
        ".L08156F0C:\n"
        "    adds r6, #1\n"
        "    cmp r6, r4\n"
        "    bls .L08156EFE\n"
        "    b .L08157142\n"
        ".L08156F14: .4byte 0x0203B554 @ EWRAM+0x3B554\n"
        ".L08156F18: .4byte 0x0000FFFF\n"
        ".L08156F1C: .4byte 0x01000180\n"
        ".L08156F20: .4byte 0x0000017B\n"
        ".L08156F24:\n"
        "    cmp r4, #1\n"
        "    bne .L08156F86\n"
        "    movs r4, #0\n"
        "    movs r6, #0\n"
        "    ldr r1, .L08156F68\n"
        "    mov r2, r8\n"
        "    lsls r0, r2, #1\n"
        "    adds r0, r0, r1\n"
        "    mov r8, r0\n"
        ".L08156F36:\n"
        "    adds r0, r6, #0\n"
        "    bl sub_080C28CC\n"
        "    cmp r0, #0\n"
        "    beq .L08156F7E\n"
        "    lsls r0, r6, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Demon_GetRecord\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    mov r3, r8\n"
        "    ldrh r3, [r3]\n"
        "    cmp r0, r3\n"
        "    bne .L08156F6C\n"
        "    lsls r0, r4, #1\n"
        "    adds r0, r0, r7\n"
        "    strh r6, [r0]\n"
        "    cmp r5, #0\n"
        "    bne .L08156F78\n"
        "    str r4, [sp, #8]\n"
        "    movs r5, #1\n"
        "    b .L08156F78\n"
        "    .byte 0x00, 0x00\n"
        ".L08156F68: .4byte gUnknown_087E3204\n"
        ".L08156F6C:\n"
        "    lsls r0, r4, #1\n"
        "    adds r0, r0, r7\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #8\n"
        "    adds r1, r6, r2\n"
        "    strh r1, [r0]\n"
        ".L08156F78:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        ".L08156F7E:\n"
        "    adds r6, #1\n"
        "    cmp r6, #0xfe\n"
        "    bls .L08156F36\n"
        "    b .L08157142\n"
        ".L08156F86:\n"
        "    cmp r4, #2\n"
        "    bne .L08157004\n"
        "    movs r2, #0\n"
        "    movs r6, #0\n"
        "    movs r5, #0\n"
        "    ldr r0, .L08156FF4\n"
        "    ldrh r4, [r0]\n"
        "    cmp r4, sb\n"
        "    bne .L08156F9A\n"
        "    b .L08157142\n"
        ".L08156F9A:\n"
        "    mov sb, r0\n"
        "    ldr r3, .L08156FF8\n"
        "    mov sl, r3\n"
        ".L08156FA0:\n"
        "    adds r0, r4, #0\n"
        "    str r2, [sp, #0xc]\n"
        "    bl sub_080C28CC\n"
        "    ldr r2, [sp, #0xc]\n"
        "    cmp r0, #0\n"
        "    beq .L08156FDA\n"
        "    strh r4, [r7]\n"
        "    lsls r0, r5, #2\n"
        "    ldr r1, .L08156FFC\n"
        "    adds r0, r0, r1\n"
        "    ldrh r1, [r0]\n"
        "    cmp r1, r8\n"
        "    beq .L08156FC6\n"
        "    movs r3, #0x80\n"
        "    lsls r3, r3, #8\n"
        "    adds r0, r3, #0\n"
        "    orrs r4, r0\n"
        "    strh r4, [r7]\n"
        ".L08156FC6:\n"
        "    adds r7, #2\n"
        "    cmp r2, #0\n"
        "    bne .L08156FD4\n"
        "    cmp r1, r8\n"
        "    bne .L08156FD4\n"
        "    str r6, [sp, #8]\n"
        "    movs r2, #1\n"
        ".L08156FD4:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        ".L08156FDA:\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, sl\n"
        "    bls .L08156FE6\n"
        "    b .L08157142\n"
        ".L08156FE6:\n"
        "    lsls r0, r5, #2\n"
        "    add r0, sb\n"
        "    ldrh r4, [r0]\n"
        "    ldr r0, .L08157000\n"
        "    cmp r4, r0\n"
        "    bne .L08156FA0\n"
        "    b .L08157142\n"
        ".L08156FF4: .4byte gUnknown_08585C34\n"
        ".L08156FF8: .4byte 0x0000017B\n"
        ".L08156FFC: .4byte gUnknown_08585C36\n"
        ".L08157000: .4byte 0x0000FFFF\n"
        ".L08157004:\n"
        "    cmp r4, #3\n"
        "    beq .L0815700A\n"
        "    b .L08157142\n"
        ".L0815700A:\n"
        "    movs r0, #2\n"
        "    bl sub_080C9210\n"
        "    adds r4, r0, #0\n"
        "    ldrh r0, [r4]\n"
        "    mov r1, sb\n"
        "    movs r2, #1\n"
        "    add r2, r8\n"
        "    mov sb, r2\n"
        "    cmp r0, r1\n"
        "    beq .L0815703A\n"
        "    adds r5, r1, #0\n"
        ".L08157022:\n"
        "    ldrh r0, [r4]\n"
        "    bl sub_080C28CC\n"
        "    cmp r0, #0\n"
        "    beq .L08157032\n"
        "    ldrh r0, [r4]\n"
        "    strh r0, [r7]\n"
        "    adds r7, #2\n"
        ".L08157032:\n"
        "    adds r4, #4\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, r5\n"
        "    bne .L08157022\n"
        ".L0815703A:\n"
        "    ldr r7, .L0815707C\n"
        "    movs r6, #0\n"
        "    adds r2, r7, #0\n"
        "    mov r5, sb\n"
        "    mov r3, r8\n"
        "    lsls r0, r3, #2\n"
        "    add r0, r8\n"
        "    lsls r0, r0, #0x11\n"
        "    mov sl, r0\n"
        ".L0815704C:\n"
        "    ldrh r1, [r2]\n"
        "    ldr r0, .L08157080\n"
        "    cmp r1, r0\n"
        "    beq .L081570A6\n"
        "    lsls r0, r5, #2\n"
        "    adds r0, r0, r5\n"
        "    lsls r0, r0, #0x11\n"
        "    ldr r3, .L08157084\n"
        "    adds r0, r0, r3\n"
        "    lsrs r4, r0, #0x10\n"
        "    ldr r3, .L08157088\n"
        "    adds r0, r3, #0\n"
        "    ands r0, r1\n"
        "    str r2, [sp, #0xc]\n"
        "    bl Demon_GetRecord\n"
        "    ldrb r0, [r0, #1]\n"
        "    ldr r2, [sp, #0xc]\n"
        "    mov r1, r8\n"
        "    cmp r1, #0\n"
        "    bne .L0815708C\n"
        "    movs r1, #1\n"
        "    b .L08157090\n"
        "    .byte 0x00, 0x00\n"
        ".L0815707C: .4byte 0x0203B554 @ EWRAM+0x3B554\n"
        ".L08157080: .4byte 0x0000FFFF\n"
        ".L08157084: .4byte 0xFFFF0000\n"
        ".L08157088: .4byte 0x00007FFF\n"
        ".L0815708C:\n"
        "    mov r3, sl\n"
        "    lsrs r1, r3, #0x10\n"
        ".L08157090:\n"
        "    cmp r4, #0x64\n"
        "    bls .L08157096\n"
        "    movs r4, #0xc8\n"
        ".L08157096:\n"
        "    cmp r0, r1\n"
        "    blo .L081570AC\n"
        "    cmp r0, r4\n"
        "    bhi .L081570AC\n"
        "    lsls r0, r6, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #8]\n"
        "    b .L081570B6\n"
        ".L081570A6:\n"
        "    movs r0, #0\n"
        "    str r0, [sp, #8]\n"
        "    b .L081570B6\n"
        ".L081570AC:\n"
        "    adds r2, #2\n"
        "    adds r6, #1\n"
        "    ldr r0, .L08157110\n"
        "    cmp r6, r0\n"
        "    bls .L0815704C\n"
        ".L081570B6:\n"
        "    movs r6, #0\n"
        "    mov r1, sb\n"
        "    lsls r0, r1, #2\n"
        "    add r0, sb\n"
        "    lsls r0, r0, #0x11\n"
        "    lsrs r5, r0, #0x10\n"
        "    ldrh r0, [r7]\n"
        "    ldr r1, .L08157114\n"
        "    cmp r0, r1\n"
        "    beq .L08157142\n"
        "    mov sl, r1\n"
        "    adds r4, r7, #0\n"
        ".L081570CE:\n"
        "    cmp r5, #0x64\n"
        "    bls .L081570D4\n"
        "    movs r5, #0xc8\n"
        ".L081570D4:\n"
        "    ldrh r1, [r4]\n"
        "    ldr r7, .L08157118\n"
        "    adds r0, r7, #0\n"
        "    ands r0, r1\n"
        "    bl Demon_GetRecord\n"
        "    ldrb r0, [r0, #1]\n"
        "    cmp r0, r5\n"
        "    bhs .L0815711C\n"
        "    mov r2, r8\n"
        "    cmp r2, #0\n"
        "    beq .L08157128\n"
        "    ldrh r1, [r4]\n"
        "    adds r0, r7, #0\n"
        "    ands r0, r1\n"
        "    bl Demon_GetRecord\n"
        "    ldrb r1, [r0, #1]\n"
        "    mov r3, r8\n"
        "    lsls r0, r3, #2\n"
        "    add r0, r8\n"
        "    lsls r0, r0, #1\n"
        "    cmp r1, r0\n"
        "    bhs .L08157128\n"
        "    ldrh r0, [r4]\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #8\n"
        "    adds r1, r2, #0\n"
        "    b .L08157124\n"
        "    .byte 0x00, 0x00\n"
        ".L08157110: .4byte 0x0000017B\n"
        ".L08157114: .4byte 0x0000FFFF\n"
        ".L08157118: .4byte 0x00007FFF\n"
        ".L0815711C:\n"
        "    ldrh r0, [r4]\n"
        "    movs r3, #0x80\n"
        "    lsls r3, r3, #8\n"
        "    adds r1, r3, #0\n"
        ".L08157124:\n"
        "    orrs r0, r1\n"
        "    strh r0, [r4]\n"
        ".L08157128:\n"
        "    adds r4, #2\n"
        "    adds r6, #1\n"
        "    ldr r0, .L08157170\n"
        "    cmp r6, r0\n"
        "    bhi .L08157142\n"
        "    mov r1, sb\n"
        "    lsls r0, r1, #2\n"
        "    add r0, sb\n"
        "    lsls r0, r0, #0x11\n"
        "    lsrs r5, r0, #0x10\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, sl\n"
        "    bne .L081570CE\n"
        ".L08157142:\n"
        "    ldr r2, [sp, #4]\n"
        "    cmp r2, #1\n"
        "    bne .L0815719C\n"
        "    ldr r4, .L08157174\n"
        "    bl Compendium_CountList\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    adds r1, r0, #0\n"
        "    ldr r3, .L08157178\n"
        "    adds r2, r4, r3\n"
        "    movs r0, #0\n"
        "    strb r0, [r2]\n"
        "    adds r3, #4\n"
        "    adds r4, r4, r3\n"
        "    strb r0, [r4]\n"
        "    cmp r1, #6\n"
        "    bhi .L0815717C\n"
        "    mov r1, sp\n"
        "    ldrb r1, [r1, #8]\n"
        "    strb r1, [r2]\n"
        "    b .L0815719A\n"
        "    .byte 0x00, 0x00\n"
        ".L08157170: .4byte 0x0000017B\n"
        ".L08157174: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L08157178: .4byte 0x00000666\n"
        ".L0815717C:\n"
        "    subs r0, r1, #7\n"
        "    ldr r3, [sp, #8]\n"
        "    cmp r3, r0\n"
        "    ble .L08157196\n"
        "    adds r0, r3, #0\n"
        "    adds r0, #6\n"
        "    subs r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    subs r1, r3, r0\n"
        "    strb r1, [r4]\n"
        "    strb r0, [r2]\n"
        "    b .L0815719C\n"
        ".L08157196:\n"
        "    mov r0, sp\n"
        "    ldrb r0, [r0, #8]\n"
        ".L0815719A:\n"
        "    strb r0, [r4]\n"
        ".L0815719C:\n"
        "    add sp, #0x10\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

/* Number of demons in the compendium list. */
// Compendium_CountList @ 0x081571AC
u32 Compendium_CountList(void)
{
    u32 n = 0;
    u32 i;
    u16 *list = gStatusList;

    for (i = 0; i <= 0x17B; i++)
    {
        if (list[i] != 0xFFFF)
            n++;
    }
    return n;
}

/* Price of summoning demon id from the compendium. */
// Compendium_GetPrice @ 0x081571DC
s32 Compendium_GetPrice(u16 id)
{
    return sub_080C10A8(id) * 5;
}

/* TRUE when demon id can be summoned: hero level, availability and money. */
// Compendium_CanSummon @ 0x081571F0
u32 Compendium_CanSummon(u16 id)
{
    struct DemonRecord *rec = Demon_GetRecord(id);
    struct Combatant *hero = Party_GetMember(0x8000);
    u32 cost = Compendium_GetPrice(id);

    if (hero->level >= rec->level && sub_0815BA28(id) && Money_Get() >= cost)
        return TRUE;
    return FALSE;
}

/* Counts the fusion items that offer a demon in mode 2-4. */
// sub_08157238 @ 0x08157238
u16 sub_08157238(u16 mode)
{
    u16 item = 0x40;
    u16 n = 0;
    u16 col;
    u16 i;

    switch (mode)
    {
    case 2:
        col = 0;
        break;
    case 3:
        col = 2;
        break;
    case 4:
        col = 1;
        break;
    }
    for (i = 0; i < 16; i++, item++)
    {
        if (Inventory_GetCount(item) && gUnknown_087E248C[col + i * 4] != 0)
            n++;
    }
    return n;
}

/* Result demon of the chosen materials. */
// sub_081572AC @ 0x081572AC
u16 sub_081572AC(void)
{
    u16 out[2];
    u16 r;
    u16 mode = gUnk_0203B854[4];

    if (mode == 2)
    {
        gUnk_0203B868.ids[0] = gUnk_0203B854[0];
        gUnk_0203B868.ids[1] = gUnk_0203B854[1];
        gUnk_0203B868.ids[2] = 0xFFFF;
        Fusion_IsRandomResult();
        Fusion_CalcTwo();
        Fusion_CheckResult();
        return gUnk_0203B868.result;
    }
    if (mode == 3)
    {
        gUnk_0203B868.ids[0] = gUnk_0203B854[0];
        gUnk_0203B868.ids[1] = gUnk_0203B854[1];
        gUnk_0203B868.ids[2] = gUnk_0203B854[2];
        Fusion_SortMaterials();
        Fusion_IsRandomResult();
        Fusion_CalcThree();
        Fusion_CheckResult();
        return gUnk_0203B868.result;
    }
    if (mode == 1)
    {
        sub_0815B884(gUnk_0203B854[0], 0xFFFF, gUnk_0203B854[1], &out[0], &out[1]);
        return out[0];
    }
    if (mode == 4)
    {
        sub_0815B884(gUnk_0203B854[0], gUnk_0203B854[1], 0xFFFF, &out[0], &out[1]);
        return out[0];
    }
    if (mode == 5)
    {
        sub_0815B884(gUnk_0203B854[0], gUnk_0203B854[1], gUnk_0203B854[2], &out[0], &out[1]);
        return out[0];
    }
    if (mode == 6)
        r = gUnk_0203B854[3];
    return r;
}

/* Fusion room setup: special result override, animation set, hides the field characters. */
// sub_0815739C @ 0x0815739C
void sub_0815739C(void)
{
    struct FusionRoom *r = &sRoom;
    u16 mode = gUnk_0203B854[4];

    if (r->unk0 == 0 && (mode == 2 || mode == 3))
    {
        u16 id = Fusion_RollAccident();

        if (id != 0xFFFF)
        {
            r->unk82 = gUnk_0203B854[3];
            gUnk_0203B854[3] = id;
            r->unk80 = 1;
        }
    }
    if (mode == 1 || mode == 2 || mode == 4 || mode == 6)
        r->anim = gFusionRoomAnim;
    else if (mode == 3 || mode == 5)
        r->anim = gUnknown_087F01DC;
    r->savedTask = gCharTasks[0];
    gCharTasks[0] = NULL;
    r->savedSlot[0] = gGfxSlots[0][0];
    r->savedSlot[1] = gGfxSlots[0][1];
    gGfxSlots[0][0] = 0;
    gGfxSlots[0][1] = 0;
    Music_Play(0x10);
}

// sub_08157434 @ 0x08157434
void sub_08157434(void)
{
    Field_SetState(0x19);
}

// sub_08157440 @ 0x08157440
void sub_08157440(void)
{
    struct FusionRoom *r = &sRoom;

    r->fade = sub_080B6BB0(sub_08157434);
}

// sub_0815745C @ 0x0815745C
void sub_0815745C(struct Task *task)
{
    if (sRoom.fade->state == -1)
        task->result = 1;
    else
        task->result = 0;
}

// sub_08157480 @ 0x08157480
void sub_08157480(void)
{
    sRoom.fade->state = 1;
}

// Fusion_LoadRoomTiles @ 0x08157490
void Fusion_LoadRoomTiles(u32 unused, u32 k)
{
    struct FusionRoom *r = &sRoom;

    if (k <= 5)
        LZ77UnCompWram(gFusionRoomTiles[k], (void *)(0x02001000 + k * 0x1000));
    else
        LZ77UnCompWram(*(const void *const *)r->anim, (void *)0x02003920);
}

/* Decompresses the room tilemap (2-way or 3-way room) and places it at palette line 6. */
// sub_081574D0 @ 0x081574D0
void sub_081574D0(void)
{
    u16 mode = gUnk_0203B854[4];
    const u8 *src;

    if (mode == 1 || mode == 2 || mode == 4 || mode == 6)
        src = gUnknown_087EF03C;
    else
        src = gUnknown_087EF5A0;
    LZ77UnCompWram(src, &gUnk_02000000[0x800]);
    Tilemap_CopyRectSkipZero(&gUnk_02000000[0x800], gUnk_02000000, 0, 6, 0, 0, 0x1E, 0x14);
}

// sub_08157534 @ 0x08157534
void sub_08157534(void)
{
    DmaSet3(gUnk_02001000, 0x06004000, 0x84001B00);
    DmaSet3(gUnk_02000000, 0x06001000, 0x84000200);
    sub_081574D0();
    DmaSet3(gUnk_02000000, 0x06003000, 0x84000200);
    REG_BG1CNT = 0x8205;
    REG_BG2CNT = 0x8406;
    REG_BG3CNT = 0x8607;
    {
        u16 y = 0x10;   /* blend: EVA = EVB = y / 2, EVY = y (written this way to match) */
        gUnk_03000040 = 0x3C42;
        gUnk_03000042 = ((y / 2) << 8) | (y / 2);
        gUnk_03000044 = y;
    }
}
