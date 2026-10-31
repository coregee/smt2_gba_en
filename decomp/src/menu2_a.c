#include "global.h"
#include "menu2.h"

/* Draws up to 8 glyphs of the name stored at +0x22 of record `id` (0xFFFF = none). */
/* NONMATCHING: the name pointer is copied to another register before the loop (register allocation). */
// sub_080D2F04 @ 0x080D2F04
#ifdef NONMATCHING
void sub_080D2F04(u16 id, u16 x, u16 y)
{
    /* name is held as an integer: with a pointer-typed base loop.c
       eliminates the counter i (the original keeps `cmp i, #7`). */
    u32 name;
    u32 i;

    if (id != 0xFFFF)
    {
        u8 *rec = Demon_GetRecord(id);

        i = 0;
        name = (u32)(rec + 0x22);
        for (; i < 8 && ((u16 *)name)[i] != 0; i++)
            FontSprite_DrawGlyph(((u16 *)name)[i], 0, 0, x + i * 12, y);
    }
}
#else
NAKED
void sub_080D2F04(u16 id, u16 x, u16 y)
{
    asm_unified(
        ".L080D2F04:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    sub sp, #4\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r4, r1, #0x10\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r7, r2, #0x10\n"
        "    ldr r0, .L080D2F5C\n"
        "    cmp r3, r0\n"
        "    beq .L080D2F52\n"
        "    adds r0, r3, #0\n"
        "    bl Demon_GetRecord\n"
        "    movs r6, #0\n"
        "    adds r1, r0, #0\n"
        "    adds r1, #0x22\n"
        "    ldrh r0, [r0, #0x22]\n"
        "    cmp r0, #0\n"
        "    beq .L080D2F52\n"
        "    lsls r5, r4, #0x10\n"
        "    adds r4, r1, #0\n"
        ".L080D2F30:\n"
        "    ldrh r0, [r4]\n"
        "    lsrs r3, r5, #0x10\n"
        "    str r7, [sp]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    bl FontSprite_DrawGlyph\n"
        "    adds r4, #2\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #0xc\n"
        "    adds r5, r5, r0\n"
        "    adds r6, #1\n"
        "    cmp r6, #7\n"
        "    bhi .L080D2F52\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #0\n"
        "    bne .L080D2F30\n"
        ".L080D2F52:\n"
        "    add sp, #4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080D2F5C: .4byte 0x0000FFFF\n"
    );
}
#endif

// sub_080D2F60 @ 0x080D2F60
void sub_080D2F60(void)
{
    struct StatusMenu2 *menu = STATUS_MENU2;
    u16 x, y;
    u32 i;

    x = 0;
    y = 0x3B;
    if ((u16)(menu->mode - 3) < 2)
    {
        x = 0x72;
        if (menu->mode == 3)
            y = 0x22;
        else
        {
            y = 2;
            sub_080D2F04(menu->itemA2, x - 2, 0x35);
            sub_080D2F04(menu->itemA4, x - 2, y + 0x40);
        }
        Sprite_DrawSingle(gUnknown_084F3148, 0, 0, 0, 0, x, y);
        Sprite_DrawSingle(gUnknown_084F3148, 0, 0, 0, 4, x + 0x20, y);
        Sprite_DrawSingle(gUnknown_084F3148, 0, 0, 0, 8, x + 0x40, y);
        Sprite_DrawSingle(gUnknown_084F3148, 0, 0, 0, 12, x + 0x60, y);
        Sprite_DrawSingle(gUnknown_084F3148, 0, 0, 0, 16, x, y + 0x1A);
        Sprite_DrawSingle(gUnknown_084F3148, 0, 0, 0, 20, x + 0x20, y + 0x1A);
        Sprite_DrawSingle(gUnknown_084F3148, 0, 0, 0, 24, x + 0x40, y + 0x1A);
        Sprite_DrawSingle(gUnknown_084F3148, 0, 0, 0, 28, x + 0x60, y + 0x1A);
    }
    else
    {
        if (menu->mode == 2)
        {
            Canvas_FillRect(0, gUnk_0200F874, 0x9E, 0xC, 0x40, 0x10);
            sub_080D2D58();
            sub_080D1F0C();
        }
        if (menu->mode != 0)
        {
            for (i = 0; i < 8; i++)
                Sprite_DrawSingle(gUnknown_084F3148, 0, 0, 0, i * 4, i * 32 + x, y);
        }
        sub_080D21C4(&x, &y);
        sub_080C7664(x, y, gGameState.unkAD8);
    }
}

// sub_080D3170 @ 0x080D3170
void sub_080D3170(u16 idx, u16 x, u16 y, u16 flag)
{
    if (flag == 1)
    {
        Sprite_Draw(gUnknown_084F3150[idx], 0, 0, 0, 0x240, x, y);
        Sprite_DrawSingle(gUnknown_084F316C, 0, 0, 0, 0, x + 1, y + 1);
    }
    else
        Sprite_Draw(gUnknown_084F3150[idx], 0, 0, 0, 0x240, x, y);
}

/* Draws an 8-digit number as sprites, without leading zeros. */
// Sprite_DrawNumber8 @ 0x080D31F8
void Sprite_DrawNumber8(u32 n, u16 x, u16 y, u16 palette)
{
    u8 *digits = NumberToDigits(n);
    u32 started = 0;
    u32 i;

    for (i = 0; i < 8; i++)
    {
        u8 d = digits[7 - i];
        if (started == 1 || d != 0 || i == 7)
        {
            Sprite_DrawSingle(gUnknown_084F3174, 0, palette, 0, d, x + i * 8, y);
            started = 1;
        }
    }
}

// sub_080D3264 @ 0x080D3264
void sub_080D3264(u32 arg0)
{
    struct StatusMenu2 *menu = STATUS_MENU2;
    u32 changed;
    s32 kind;

    if (menu->mode != 1)
        return;
    if (menu->id > 0xCF)
    {
        if (menu->descPageCount > 1)
        {
            if (menu->descPage == 0 && (gKeysNew & 0x10))
            {
                menu->descPage++;
                Sound_Play(100);
                Item_RenderDescription(arg0);
            }
            else if (menu->descPage == 1 && (gKeysNew & 0x20))
            {
                menu->descPage--;
                Sound_Play(100);
                Item_RenderDescription(arg0);
            }
            if (menu->descPage == 0)
            {
                sub_080C4B78(0, 0, 0xE6, 0x46);
                if (menu->descPage == 0)
                    return;
            }
            sub_080C4B14(0, 0, 2, 0x46);
        }
        return;
    }

    changed = 0;
    if (gKeysNew & 0x20)
    {
        if (menu->page != 0)
        {
            menu->page--;
            changed = 1;
        }
    }
    else if (gKeysNew & 0x10)
    {
        if (menu->page != 3)
        {
            menu->page++;
            changed = 1;
        }
    }
    if (changed == 1)
    {
        Sound_Play(100);
        Item_RenderDescription(arg0);
    }
    if (--menu->arrowTimer == 0)
    {
        menu->arrowTimer = 8;
        menu->arrowBlink = (menu->arrowBlink + 1) & 1;
    }
    if (menu->arrowBlink == 0)
    {
        if (menu->page != 0)
            sub_080C4B14(0, 0, 2, 0x46);
        if (menu->page != 3)
            sub_080C4B78(0, 0, 0xE6, 0x46);
    }
    if (menu->page == 0)
    {
        Item_GetAttribute(menu->id, 0, &kind);
        switch (kind)
        {
        case 0xC0:
            Sprite_Draw(gUnknown_080014D8, 0, 0, 0, 0x240, 0xCD, 0x46);
            break;
        case 0x80:
            Sprite_Draw(gUnknown_080014B0, 0, 0, 0, 0x240, 0xCD, 0x46);
            break;
        case 0x40:
            Sprite_Draw(gUnknown_080014C0, 0, 0, 0, 0x240, 0xCD, 0x46);
            break;
        }
    }
    else if (menu->page == 2)
    {
        sub_080D3170(0, 10, 0x3E, 0);
        sub_080D3170(1, 0x55, 0x3E, 0);
    }
}

// sub_080D3400 @ 0x080D3400
struct Task *sub_080D3400(u16 mode, u16 member, u16 id)
{
    struct Task *task = Task_Create(gUnknown_084F317C, 0xFFFF);
    struct StatusMenu2 *menu = STATUS_MENU2;
    u32 zero = 0;

    CpuSet(&zero, menu, 0x05000200);
    menu->mode = mode;
    menu->page = 0;
    menu->member = member;
    menu->id = id;
    menu->descPage = 0;
    menu->descPageCount = Action_CountDescriptionBreaks(id);
    menu->arrowTimer = 8;
    return task;
}

// sub_080D347C @ 0x080D347C
void sub_080D347C(u16 a, u16 b, u16 c, u16 d, u16 e)
{
    struct StatusMenu2 *menu = STATUS_MENU2;

    menu->unk9C = a;
    menu->unk9E = b;
    menu->unkA0 = c;
    menu->itemA2 = d;
    menu->itemA4 = e;
}

// sub_080D34A4 @ 0x080D34A4
void sub_080D34A4(u32 arg0, u16 mode, u16 member, u16 id)
{
    struct StatusMenu2 *menu = STATUS_MENU2;

    menu->member = member;
    menu->id = id;
    menu->descPage = 0;
    menu->descPageCount = Action_CountDescriptionBreaks(id);
    menu->mode = mode;
    menu->page = 0;
    menu->arrowTimer = 8;
    sub_080D2028(arg0);
    Item_RenderDescription(arg0);
    sub_080D21F8(arg0);
}

// sub_080D34F0 @ 0x080D34F0
void sub_080D34F0(struct Task *task)
{
    struct StatusMenu2 *menu = STATUS_MENU2;

    sub_080D1FFC();
    if ((u16)(menu->mode - 3) < 2)
        Tilemap_FillRect(0, gWindowTilemapBuffer, 1, 0, 0x1C, 0x10);
    else
        Tilemap_FillRect(0, gWindowTilemapBuffer, 1, 5, 0x1C, 0xF);
    sub_080C6558();
    sub_080C6764();
    if (menu->mode != 0)
    {
        Palette_FillWithEffect(3, 0, gUnk_03003150, 0x20, 0x10);
        Palette_MarkDirty();
    }
    Task_End(task);
}

// sub_080D3574 @ 0x080D3574
void sub_080D3574(void)
{
    struct Task *task = gUnk_03003FEC;

    Tilemap_CopyRectSkipZero(gUnknown_081B8170, gWindowTilemapBuffer, 0, 0, 0x15, 7, 8, 2);
    if (task->data.w[0] == 2)
        Tilemap_CopyRectSkipZero(gUnknown_081B8170, gWindowTilemapBuffer, 0, 0, 0x15, 9, 8, 2);
    sub_080C6764();
}

// sub_080D35DC @ 0x080D35DC
void sub_080D35DC(void)
{
    Tilemap_FillRect(0, gWindowTilemapBuffer, 0x15, 7, 8, 2);
    Tilemap_FillRect(0, gWindowTilemapBuffer, 0x15, 9, 8, 2);
    sub_080C6764();
}

// sub_080D3618 @ 0x080D3618
void sub_080D3618(void)
{
    u32 *data = gUnk_03003FEC->data.w;

    sub_080C7664(0x15, 7, gGameState.unkAD8);
    if (data[0] == 2)
        sub_080C7664(0x15, 9, data[1]);
}

// sub_080D3654 @ 0x080D3654
void sub_080D3654(u32 a, u32 b)
{
    struct Task *task = Task_Create(gUnknown_084F31E0, 0xFFFF);

    gUnk_03003FEC = task;
    task->data.w[0] = a;
    task->data.w[1] = b;
}

// sub_080D367C @ 0x080D367C
void sub_080D367C(u32 a)
{
    gUnk_03003FEC->data.w[1] = a;
}

// sub_080D3688 @ 0x080D3688
void sub_080D3688(void)
{
    gUnk_03003FEC->wait = 1;
}

// sub_080D3698 @ 0x080D3698
void sub_080D3698(void)
{
    DmaSet3(gBgPictureBuffer, (void *)0x06015000, 0x84000400);
}

// sub_080D36BC @ 0x080D36BC
void sub_080D36BC(struct Task *task)
{
    task->data.w[0] = (u32)TextWindow_CreateOpen(0x17, 0, 6, 3, 1);
    DmaSet3(gUnknown_081B5710, gUnk_0200BEC8, 0x84000040);
    VBlankTask_AddCounted(sub_080D3698, 1);
}

// sub_080D3708 @ 0x080D3708
void sub_080D3708(void)
{
    Sprite_Draw(gUnknown_08002A4C, 0, 0, 0, 0x2F8, 0xBA, 3);
    sub_080C8048(sub_080C31F0(), 0xB8, 0xB, 0);
}

// sub_080D3740 @ 0x080D3740
struct Task *sub_080D3740(void)
{
    return Task_Create(gUnknown_084F3204, 0xFFFF);
}

// sub_080D3758 @ 0x080D3758
void sub_080D3758(struct Task *task)
{
    TextWindow_Close((struct Task *)task->data.w[0], 1);
    Task_End(task);
}

// sub_080D3770 @ 0x080D3770
void sub_080D3770(struct Task *task)
{
    struct PrizeList *list = (struct PrizeList *)task->data.w;

    list->count = Vision_BuildList(0);
    Tilemap_CopyRectSkipZero(gUnknown_081B8170, gWindowTilemapBuffer, 0, 0, 0x15, 0, 8, 2);
    task->data.w[0] = (u32)TextWindow_CreateOpen(1, 0, 0xE, 0xB, 1);
}

/* Draws six rows of the prize list from `top`, greyed when the prize cannot be taken. */
// CasinoPrize_DrawRows @ 0x080D37BC
void CasinoPrize_DrawRows(struct Task *task)
{
    struct PrizeList *list = (struct PrizeList *)&task->data;
    u16 x = 12, y = 4;
    u16 count = list->count;
    u32 i, j;

    sub_080C49EC(0xB, 0, 0, 0xC, list->cursor * 12 + y);
    for (i = 0; i < 6; i++)
    {
        u16 id = *(gUnk_0203B454 + (list->top + i));
        if (id != 0)
        {
            u16 *name = (u16 *)(Action_GetRecord(id) + 0xC);
            for (j = 0; j < 8; j++)
            {
                if (sub_080C5B10(id) != 0)
                    FontSprite_DrawGlyph(name[j], 0, 0, x + j * 12, i * 12 + y);
                else
                    FontSprite_DrawGlyphTinted(name[j], 0, 0, x + j * 12, i * 12 + y, 2);
            }
        }
    }
    sub_080C7664(0x15, 0, gGameState.unkAD8);
    if (list->top != 0)
        sub_080C4A4C(0, 0, x + 0x60, y - 4);
    if (list->top + 6 <= count - 1)
        sub_080C4AB0(0, 0, x + 0x60, y + 0x4C);
}
