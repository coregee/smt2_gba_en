#include "global.h"
#include "menu.h"

/* NONMATCHING: the grid loop keeps the table base and y in an extra high register. */
// NameEntry_DrawGrid @ 0x080D15DC
#ifdef NONMATCHING
void NameEntry_DrawGrid(void)
{
    struct SaveMenu *menu = &gMenuState;
    u32 x, y;
    u32 i, j;

    if (menu->unk02 == 0)
    {
        x = menu->unk04 * 12 + 12;
        y = menu->cursor * 12 + 0x6A;
        Sprite_Draw(gUnknown_084F3040[menu->u.name.delay], 1, 13, 0, 0x280, x, y);
    }
    else
    {
        x = menu->unk0A * 12 + 0xB0;
        y = menu->u.name.menuCursor * 12 + 0x6A;
        Sprite_Draw(gUnknown_0800276C, 1, 13, 0, 0x280, x, y);
    }
    for (i = 0; i < 2; i++)
        Sprite_Draw(gUnknown_080027CC, 1, 13, 0, 0x280, x, 0x68 + i * 0x20);
    for (i = 0; i < 7; i++)
        Sprite_Draw(gUnknown_080027BC, 1, 13, 0, 0x280, 8 + i * 0x20, y);

    Font_ResetGlyphSpriteCache(0x180);
    for (i = 0; i < 4; i++)
    {
        u16 gy = 0x6A + i * 12;

        for (j = 0; j < 11; j++)
            FontSprite_DrawGlyph(gNameEntryCharGrid[(i + menu->unk08) * 11 + j], 0, 0, 12 + j * 12, gy);
    }

    Text_DrawSpriteString(gUnknown_084F3002, 0, 0, 0xB0, 0x6A, 12);
    Text_DrawSpriteString(gUnknown_084F302A, 0, 0, 0x10, 0x59, 12);
    for (i = 0; i < 8; i++)
        Sprite_DrawSingle(gUnknown_084F3038, 0, 0, 0, i * 2, 0x4C + i * 12, 0x59);
    if (menu->unk08 != 0)
        sub_080C4A4C(0, 0, 0x96, 0x6A);
    if (menu->unk08 + 4 <= 24)
        sub_080C4AB0(0, 0, 0x96, 0x96);
}
#else
NAKED
void NameEntry_DrawGrid(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sb\n"
        "    mov r6, r8\n"
        "    push {r6, r7}\n"
        "    sub sp, #0xc\n"
        "    ldr r0, .L080D1634\n"
        "    mov sb, r0\n"
        "    ldrh r0, [r0, #2]\n"
        "    cmp r0, #0\n"
        "    bne .L080D163C\n"
        "    mov r2, sb\n"
        "    ldrh r1, [r2, #4]\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #2\n"
        "    adds r5, r0, #0\n"
        "    adds r5, #0xc\n"
        "    ldrh r1, [r2, #6]\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #2\n"
        "    adds r4, r0, #0\n"
        "    adds r4, #0x6a\n"
        "    ldr r1, .L080D1638\n"
        "    ldrh r0, [r2, #0xe]\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #0xa0\n"
        "    lsls r1, r1, #2\n"
        "    str r1, [sp]\n"
        "    lsls r1, r5, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #4]\n"
        "    lsls r1, r4, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #1\n"
        "    movs r2, #0xd\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    b .L080D1676\n"
        "    .byte 0x00, 0x00\n"
        ".L080D1634: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L080D1638: .4byte gUnknown_084F3040\n"
        ".L080D163C:\n"
        "    mov r0, sb\n"
        "    ldrh r1, [r0, #0xa]\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #2\n"
        "    adds r5, r0, #0\n"
        "    adds r5, #0xb0\n"
        "    mov r2, sb\n"
        "    ldrh r1, [r2, #0xc]\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #2\n"
        "    adds r4, r0, #0\n"
        "    adds r4, #0x6a\n"
        "    ldr r0, .L080D17B0\n"
        "    movs r1, #0xa0\n"
        "    lsls r1, r1, #2\n"
        "    str r1, [sp]\n"
        "    lsls r1, r5, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #4]\n"
        "    lsls r1, r4, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #1\n"
        "    movs r2, #0xd\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L080D1676:\n"
        "    movs r6, #0\n"
        "    lsls r5, r5, #0x10\n"
        "    lsls r7, r4, #0x10\n"
        "    movs r4, #0xd0\n"
        "    lsls r4, r4, #0xf\n"
        ".L080D1680:\n"
        "    movs r0, #0xa0\n"
        "    lsls r0, r0, #2\n"
        "    str r0, [sp]\n"
        "    lsrs r0, r5, #0x10\n"
        "    str r0, [sp, #4]\n"
        "    lsrs r0, r4, #0x10\n"
        "    str r0, [sp, #8]\n"
        "    ldr r0, .L080D17B4\n"
        "    movs r1, #1\n"
        "    movs r2, #0xd\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #0xe\n"
        "    adds r4, r4, r0\n"
        "    adds r6, #1\n"
        "    cmp r6, #1\n"
        "    bls .L080D1680\n"
        "    movs r6, #0\n"
        "    movs r4, #0x80\n"
        "    lsls r4, r4, #0xc\n"
        ".L080D16AC:\n"
        "    movs r0, #0xa0\n"
        "    lsls r0, r0, #2\n"
        "    str r0, [sp]\n"
        "    lsrs r0, r4, #0x10\n"
        "    str r0, [sp, #4]\n"
        "    lsrs r0, r7, #0x10\n"
        "    str r0, [sp, #8]\n"
        "    ldr r0, .L080D17B8\n"
        "    movs r1, #1\n"
        "    movs r2, #0xd\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #0xe\n"
        "    adds r4, r4, r1\n"
        "    adds r6, #1\n"
        "    cmp r6, #6\n"
        "    bls .L080D16AC\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #1\n"
        "    bl Font_ResetGlyphSpriteCache\n"
        "    movs r4, #0\n"
        ".L080D16DC:\n"
        "    movs r5, #0\n"
        "    lsls r0, r4, #1\n"
        "    adds r2, r4, #1\n"
        "    mov r8, r2\n"
        "    adds r0, r0, r4\n"
        "    lsls r0, r0, #0x12\n"
        "    movs r1, #0xd4\n"
        "    lsls r1, r1, #0xf\n"
        "    adds r0, r0, r1\n"
        "    lsrs r7, r0, #0x10\n"
        "    movs r6, #0xc0\n"
        "    lsls r6, r6, #0xc\n"
        ".L080D16F4:\n"
        "    mov r2, sb\n"
        "    ldrh r0, [r2, #8]\n"
        "    adds r0, r4, r0\n"
        "    movs r1, #0xb\n"
        "    muls r0, r1, r0\n"
        "    adds r0, r0, r5\n"
        "    lsls r0, r0, #1\n"
        "    ldr r1, .L080D17BC\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    lsrs r3, r6, #0x10\n"
        "    str r7, [sp]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    bl FontSprite_DrawGlyph\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #0xc\n"
        "    adds r6, r6, r0\n"
        "    adds r5, #1\n"
        "    cmp r5, #0xa\n"
        "    bls .L080D16F4\n"
        "    mov r4, r8\n"
        "    cmp r4, #3\n"
        "    bls .L080D16DC\n"
        "    ldr r0, .L080D17C0\n"
        "    movs r1, #0x6a\n"
        "    str r1, [sp]\n"
        "    movs r4, #0xc\n"
        "    str r4, [sp, #4]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0xb0\n"
        "    bl Text_DrawSpriteString\n"
        "    ldr r0, .L080D17C4\n"
        "    movs r1, #0x59\n"
        "    str r1, [sp]\n"
        "    str r4, [sp, #4]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0x10\n"
        "    bl Text_DrawSpriteString\n"
        "    movs r6, #0\n"
        "    movs r4, #0x98\n"
        "    lsls r4, r4, #0xf\n"
        ".L080D1752:\n"
        "    lsls r0, r6, #0x11\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp]\n"
        "    lsrs r0, r4, #0x10\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #0x59\n"
        "    str r0, [sp, #8]\n"
        "    ldr r0, .L080D17C8\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_DrawSingle\n"
        "    movs r1, #0xc0\n"
        "    lsls r1, r1, #0xc\n"
        "    adds r4, r4, r1\n"
        "    adds r6, #1\n"
        "    cmp r6, #7\n"
        "    bls .L080D1752\n"
        "    mov r2, sb\n"
        "    ldrh r0, [r2, #8]\n"
        "    cmp r0, #0\n"
        "    beq .L080D178C\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #0x96\n"
        "    movs r3, #0x6a\n"
        "    bl sub_080C4A4C\n"
        ".L080D178C:\n"
        "    mov r1, sb\n"
        "    ldrh r0, [r1, #8]\n"
        "    adds r0, #4\n"
        "    cmp r0, #0x18\n"
        "    bgt .L080D17A2\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #0x96\n"
        "    movs r3, #0x96\n"
        "    bl sub_080C4AB0\n"
        ".L080D17A2:\n"
        "    add sp, #0xc\n"
        "    pop {r3, r4}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080D17B0: .4byte gUnknown_0800276C\n"
        ".L080D17B4: .4byte gUnknown_080027CC\n"
        ".L080D17B8: .4byte gUnknown_080027BC\n"
        ".L080D17BC: .4byte gNameEntryCharGrid\n"
        ".L080D17C0: .4byte gUnknown_084F3002\n"
        ".L080D17C4: .4byte gUnknown_084F302A\n"
        ".L080D17C8: .4byte gUnknown_084F3038\n"
    );
}
#endif

// NameEntry_Backspace @ 0x080D17CC
/* Name entry: delete the last character. */
void NameEntry_Backspace(struct MenuTask *task)
{
    struct SaveMenu *menu = &gMenuState;

    sub_080C51D4(0x66);
    if (menu->u.name.nameLen != 7)
    {
        if (menu->u.name.nameLen != 0)
            menu->u.name.nameLen--;
        menu->u.name.name[menu->u.name.nameLen] = 0xFF;
    }
    else
    {
        if (menu->u.name.name[menu->u.name.nameLen] == 0xFF)
        {
            menu->u.name.nameLen--;
            menu->u.name.name[menu->u.name.nameLen] = 0xFF;
        }
        else
            menu->u.name.name[menu->u.name.nameLen] |= 0xFF;
    }
    NameEntry_RenderName(task);
}

/* NONMATCHING: the original keeps (keys & 0x20) as a u16 in r2 and reuses it as the 0 stored on Right at column 10; everything else matches. */
// NameEntry_HandleInput @ 0x080D1828
#ifdef NONMATCHING
void NameEntry_HandleInput(struct MenuTask *task)
{
    struct SaveMenu *menu = &gMenuState;
    s32 numRows = 25;
    u32 moved = FALSE;

    task->unk1C = 0;
    if (menu->u.name.delay != 0)
    {
        if (--menu->u.name.delay == 0 && menu->u.name.done == 1)
        {
            menu->unk0A = 0;
            menu->u.name.menuCursor = 3;
            menu->unk02 = menu->u.name.done;
            menu->u.name.done = 0;
        }
        return;
    }

    if (menu->unk02 == 0)
    {
        /* cursor in the character grid */
        if (gKeysNew & 1)
        {
            sub_080C51D4(0x65);
            menu->u.name.name[menu->u.name.nameLen] =
                sub_080C03A8(gNameEntryCharGrid[(menu->cursor + menu->unk08) * 11 + menu->unk04]);
            NameEntry_RenderName(task);
            if (menu->u.name.nameLen != 7)
                menu->u.name.nameLen++;
            else
                menu->u.name.done = 1;
            menu->u.name.delay = 7;
        }
        else if (gKeysNew & 2)
            goto backspace;
        else if (gKeysNew & 8)
        {
            sub_080C51D4(0x65);
            menu->unk0A = 0;
            menu->u.name.menuCursor = 3;
            menu->unk02 = 1;
        }
        else if (gRepeatedKeys & 0x40)
        {
            if (menu->cursor != 0)
            {
                menu->cursor--;
                moved = TRUE;
            }
            else if (menu->unk08 != 0)
            {
                menu->unk08--;
                moved = TRUE;
            }
        }
        else if (gRepeatedKeys & 0x80)
        {
            if (menu->cursor != 3)
            {
                menu->cursor++;
                moved = TRUE;
            }
            else if (menu->unk08 + 4 <= 24)
            {
                menu->unk08++;
                moved = TRUE;
            }
        }
        else if (gRepeatedKeys & 0x20)
        {
            if (menu->unk04 != 0)
            {
                menu->unk04--;
                moved = TRUE;
                if (menu->unk04 == 5)
                    menu->unk04 = 4;
            }
            else
            {
                menu->unk0A = 0;
                menu->u.name.menuCursor = menu->cursor;
                menu->unk02 = 1;
                moved = TRUE;
            }
        }
        else if (gRepeatedKeys & 0x10)
        {
            if (menu->unk04 != 10)
            {
                menu->unk04++;
                if (menu->unk04 == 5)
                    menu->unk04 = 6;
            }
            else
            {
                menu->unk0A = 0;
                menu->u.name.menuCursor = menu->cursor;
                menu->unk02 = 1;
            }
            moved = TRUE;
        }
        else if (gRepeatedKeys & 0x200)
        {
            if (menu->cursor != 0)
            {
                menu->cursor = 0;
                moved = TRUE;
            }
            else if (menu->unk08 > 2)
            {
                menu->unk08 -= 3;
                moved = TRUE;
            }
            else
            {
                if (menu->unk08 != 0)
                    moved = TRUE;
                menu->unk08 = 0;
            }
        }
        else if (gRepeatedKeys & 0x100)
        {
            if (menu->cursor != 3)
            {
                menu->cursor = 3;
                moved = TRUE;
            }
            else if (menu->cursor + menu->unk08 + 4 < numRows - 1)
            {
                menu->unk08 += 4;
                moved = TRUE;
            }
            else
            {
                if (menu->unk08 != numRows - 4)
                    moved = TRUE;
                menu->unk08 = numRows - 4;
            }
        }
    }
    else
    {
        /* cursor in the side menu */
        if (gKeysNew & 1)
        {
            sub_080C51D4(0x65);
            if (menu->unk0A == 0)
            {
                if (menu->u.name.menuCursor == 0)
                    menu->unk08 = 0;
                else if (menu->u.name.menuCursor == 1)
                    menu->unk08 = 10;
                else if (menu->u.name.menuCursor == 2)
                    menu->unk08 = 20;
                else if (menu->u.name.menuCursor == 3)
                    task->unk1C = 1;
            }
        }
        else if (gKeysNew & 2)
        {
        backspace:
            NameEntry_Backspace(task);
        }
        else if (gKeysNew & 8)
        {
            sub_080C51D4(0x65);
            menu->unk0A = 0;
            menu->u.name.menuCursor = 3;
        }
        else if (gRepeatedKeys & 0x40)
        {
            if (menu->u.name.menuCursor != 0)
                menu->u.name.menuCursor--;
            else
                menu->u.name.menuCursor = 3;
            moved = TRUE;
        }
        else if (gRepeatedKeys & 0x80)
        {
            if (menu->u.name.menuCursor != 3)
                menu->u.name.menuCursor++;
            else
                menu->u.name.menuCursor = 0;
            moved = TRUE;
        }
        else if (gRepeatedKeys & 0x20)
        {
            menu->unk04 = 10;
            menu->cursor = menu->u.name.menuCursor;
            menu->unk02 = 0;
            moved = TRUE;
        }
        else if (gRepeatedKeys & 0x10)
        {
            menu->unk04 = 0;
            menu->cursor = menu->u.name.menuCursor;
            menu->unk02 = 0;
            moved = TRUE;
        }
    }
    if (moved == TRUE)
        sub_080C51D4(0x64);
}
#else
NAKED
void NameEntry_HandleInput(struct MenuTask *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    adds r6, r0, #0\n"
        "    ldr r4, .L080D185C\n"
        "    movs r3, #0x19\n"
        "    movs r5, #0\n"
        "    strh r5, [r6, #0x1c]\n"
        "    ldrh r0, [r4, #0xe]\n"
        "    cmp r0, #0\n"
        "    beq .L080D1860\n"
        "    subs r0, #1\n"
        "    strh r0, [r4, #0xe]\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L080D1846\n"
        "    b .L080D1AD0\n"
        ".L080D1846:\n"
        "    ldrh r1, [r4, #0x10]\n"
        "    cmp r1, #1\n"
        "    beq .L080D184E\n"
        "    b .L080D1AD0\n"
        ".L080D184E:\n"
        "    strh r5, [r4, #0xa]\n"
        "    movs r0, #3\n"
        "    strh r0, [r4, #0xc]\n"
        "    strh r1, [r4, #2]\n"
        "    strh r5, [r4, #0x10]\n"
        "    b .L080D1AD0\n"
        "    .byte 0x00, 0x00\n"
        ".L080D185C: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L080D1860:\n"
        "    ldrh r0, [r4, #2]\n"
        "    cmp r0, #0\n"
        "    beq .L080D1868\n"
        "    b .L080D19FA\n"
        ".L080D1868:\n"
        "    ldr r2, .L080D18B4\n"
        "    ldrh r1, [r2]\n"
        "    movs r7, #1\n"
        "    adds r0, r7, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080D18C4\n"
        "    movs r0, #0x65\n"
        "    bl sub_080C51D4\n"
        "    ldr r2, .L080D18B8\n"
        "    ldrh r0, [r4, #6]\n"
        "    ldrh r1, [r4, #8]\n"
        "    adds r0, r0, r1\n"
        "    movs r1, #0xb\n"
        "    muls r0, r1, r0\n"
        "    ldrh r1, [r4, #4]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r0, [r0]\n"
        "    bl sub_080C03A8\n"
        "    adds r1, r4, #0\n"
        "    adds r1, #0x1a\n"
        "    ldrh r2, [r4, #0x14]\n"
        "    adds r1, r1, r2\n"
        "    strb r0, [r1]\n"
        "    adds r0, r6, #0\n"
        "    bl NameEntry_RenderName\n"
        "    ldrh r0, [r4, #0x14]\n"
        "    cmp r0, #7\n"
        "    beq .L080D18BC\n"
        "    adds r0, #1\n"
        "    strh r0, [r4, #0x14]\n"
        "    b .L080D18BE\n"
        "    .byte 0x00, 0x00\n"
        ".L080D18B4: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L080D18B8: .4byte gNameEntryCharGrid\n"
        ".L080D18BC:\n"
        "    strh r7, [r4, #0x10]\n"
        ".L080D18BE:\n"
        "    movs r0, #7\n"
        "    strh r0, [r4, #0xe]\n"
        "    b .L080D1AC6\n"
        ".L080D18C4:\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080D18D0\n"
        "    b .L080D1A4A\n"
        ".L080D18D0:\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #8\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080D18EA\n"
        "    movs r0, #0x65\n"
        "    bl sub_080C51D4\n"
        "    strh r5, [r4, #0xa]\n"
        "    movs r0, #3\n"
        "    strh r0, [r4, #0xc]\n"
        "    strh r7, [r4, #2]\n"
        "    b .L080D1AC6\n"
        ".L080D18EA:\n"
        "    ldr r0, .L080D1904\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x40\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080D1916\n"
        "    ldrh r0, [r4, #6]\n"
        "    cmp r0, #0\n"
        "    beq .L080D1908\n"
        "    subs r0, #1\n"
        "    strh r0, [r4, #6]\n"
        "    b .L080D1AC4\n"
        "    .byte 0x00, 0x00\n"
        ".L080D1904: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L080D1908:\n"
        "    ldrh r0, [r4, #8]\n"
        "    cmp r0, #0\n"
        "    bne .L080D1910\n"
        "    b .L080D1AC6\n"
        ".L080D1910:\n"
        "    subs r0, #1\n"
        "    strh r0, [r4, #8]\n"
        "    b .L080D1AC4\n"
        ".L080D1916:\n"
        "    movs r0, #0x80\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080D193A\n"
        "    ldrh r0, [r4, #6]\n"
        "    cmp r0, #3\n"
        "    beq .L080D192A\n"
        "    adds r0, #1\n"
        "    strh r0, [r4, #6]\n"
        "    b .L080D1AC4\n"
        ".L080D192A:\n"
        "    ldrh r1, [r4, #8]\n"
        "    adds r0, r1, #4\n"
        "    cmp r0, #0x18\n"
        "    ble .L080D1934\n"
        "    b .L080D1AC6\n"
        ".L080D1934:\n"
        "    adds r0, r1, #1\n"
        "    strh r0, [r4, #8]\n"
        "    b .L080D1AC4\n"
        ".L080D193A:\n"
        "    movs r0, #0x20\n"
        "    ands r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #0\n"
        "    beq .L080D196C\n"
        "    ldrh r0, [r4, #4]\n"
        "    cmp r0, #0\n"
        "    beq .L080D1962\n"
        "    subs r0, #1\n"
        "    strh r0, [r4, #4]\n"
        "    movs r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #5\n"
        "    beq .L080D195C\n"
        "    b .L080D1AC6\n"
        ".L080D195C:\n"
        "    movs r0, #4\n"
        "    strh r0, [r4, #4]\n"
        "    b .L080D1AC6\n"
        ".L080D1962:\n"
        "    strh r5, [r4, #0xa]\n"
        "    ldrh r0, [r4, #6]\n"
        "    strh r0, [r4, #0xc]\n"
        "    strh r7, [r4, #2]\n"
        "    b .L080D1AC4\n"
        ".L080D196C:\n"
        "    movs r0, #0x10\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080D1998\n"
        "    ldrh r0, [r4, #4]\n"
        "    cmp r0, #0xa\n"
        "    beq .L080D198E\n"
        "    adds r0, #1\n"
        "    strh r0, [r4, #4]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #5\n"
        "    beq .L080D1988\n"
        "    b .L080D1AC4\n"
        ".L080D1988:\n"
        "    movs r0, #6\n"
        "    strh r0, [r4, #4]\n"
        "    b .L080D1AC4\n"
        ".L080D198E:\n"
        "    strh r2, [r4, #0xa]\n"
        "    ldrh r0, [r4, #6]\n"
        "    strh r0, [r4, #0xc]\n"
        "    strh r7, [r4, #2]\n"
        "    b .L080D1AC4\n"
        ".L080D1998:\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080D19C4\n"
        "    ldrh r2, [r4, #6]\n"
        "    cmp r2, #0\n"
        "    beq .L080D19AC\n"
        "    strh r5, [r4, #6]\n"
        "    b .L080D1AC4\n"
        ".L080D19AC:\n"
        "    ldrh r0, [r4, #8]\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #2\n"
        "    bls .L080D19BA\n"
        "    subs r0, #3\n"
        "    strh r0, [r4, #8]\n"
        "    b .L080D1AC4\n"
        ".L080D19BA:\n"
        "    cmp r1, #0\n"
        "    beq .L080D19C0\n"
        "    movs r5, #1\n"
        ".L080D19C0:\n"
        "    strh r2, [r4, #8]\n"
        "    b .L080D1AC6\n"
        ".L080D19C4:\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080D1AC6\n"
        "    ldrh r0, [r4, #6]\n"
        "    cmp r0, #3\n"
        "    beq .L080D19DA\n"
        "    movs r0, #3\n"
        "    strh r0, [r4, #6]\n"
        "    b .L080D1AC4\n"
        ".L080D19DA:\n"
        "    ldrh r0, [r4, #6]\n"
        "    ldrh r2, [r4, #8]\n"
        "    adds r0, r0, r2\n"
        "    adds r0, #4\n"
        "    subs r1, r3, #1\n"
        "    cmp r0, r1\n"
        "    bge .L080D19EE\n"
        "    adds r0, r2, #4\n"
        "    strh r0, [r4, #8]\n"
        "    b .L080D1AC4\n"
        ".L080D19EE:\n"
        "    subs r1, r3, #4\n"
        "    cmp r2, r1\n"
        "    beq .L080D19F6\n"
        "    movs r5, #1\n"
        ".L080D19F6:\n"
        "    strh r1, [r4, #8]\n"
        "    b .L080D1AC6\n"
        ".L080D19FA:\n"
        "    ldr r2, .L080D1A20\n"
        "    ldrh r1, [r2]\n"
        "    movs r7, #1\n"
        "    adds r0, r7, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080D1A40\n"
        "    movs r0, #0x65\n"
        "    bl sub_080C51D4\n"
        "    ldrh r0, [r4, #0xa]\n"
        "    cmp r0, #0\n"
        "    bne .L080D1AC6\n"
        "    ldrh r0, [r4, #0xc]\n"
        "    cmp r0, #0\n"
        "    bne .L080D1A24\n"
        "    strh r5, [r4, #8]\n"
        "    b .L080D1AC6\n"
        "    .byte 0x00, 0x00\n"
        ".L080D1A20: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L080D1A24:\n"
        "    cmp r0, #1\n"
        "    bne .L080D1A2E\n"
        "    movs r0, #0xa\n"
        "    strh r0, [r4, #8]\n"
        "    b .L080D1AC6\n"
        ".L080D1A2E:\n"
        "    cmp r0, #2\n"
        "    bne .L080D1A38\n"
        "    movs r0, #0x14\n"
        "    strh r0, [r4, #8]\n"
        "    b .L080D1AC6\n"
        ".L080D1A38:\n"
        "    cmp r0, #3\n"
        "    bne .L080D1AC6\n"
        "    strh r7, [r6, #0x1c]\n"
        "    b .L080D1AC6\n"
        ".L080D1A40:\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080D1A52\n"
        ".L080D1A4A:\n"
        "    adds r0, r6, #0\n"
        "    bl NameEntry_Backspace\n"
        "    b .L080D1AC6\n"
        ".L080D1A52:\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #8\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080D1A6A\n"
        "    movs r0, #0x65\n"
        "    bl sub_080C51D4\n"
        "    strh r5, [r4, #0xa]\n"
        "    movs r0, #3\n"
        "    strh r0, [r4, #0xc]\n"
        "    b .L080D1AC6\n"
        ".L080D1A6A:\n"
        "    ldr r0, .L080D1A84\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x40\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080D1A8E\n"
        "    ldrh r0, [r4, #0xc]\n"
        "    cmp r0, #0\n"
        "    beq .L080D1A88\n"
        "    subs r0, #1\n"
        "    strh r0, [r4, #0xc]\n"
        "    b .L080D1AC4\n"
        "    .byte 0x00, 0x00\n"
        ".L080D1A84: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L080D1A88:\n"
        "    movs r0, #3\n"
        "    strh r0, [r4, #0xc]\n"
        "    b .L080D1AC4\n"
        ".L080D1A8E:\n"
        "    movs r0, #0x80\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080D1AA6\n"
        "    ldrh r0, [r4, #0xc]\n"
        "    cmp r0, #3\n"
        "    beq .L080D1AA2\n"
        "    adds r0, #1\n"
        "    strh r0, [r4, #0xc]\n"
        "    b .L080D1AC4\n"
        ".L080D1AA2:\n"
        "    strh r5, [r4, #0xc]\n"
        "    b .L080D1AC4\n"
        ".L080D1AA6:\n"
        "    movs r0, #0x20\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080D1AB4\n"
        "    movs r0, #0xa\n"
        "    strh r0, [r4, #4]\n"
        "    b .L080D1ABE\n"
        ".L080D1AB4:\n"
        "    movs r0, #0x10\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080D1AC6\n"
        "    strh r5, [r4, #4]\n"
        ".L080D1ABE:\n"
        "    ldrh r0, [r4, #0xc]\n"
        "    strh r0, [r4, #6]\n"
        "    strh r5, [r4, #2]\n"
        ".L080D1AC4:\n"
        "    movs r5, #1\n"
        ".L080D1AC6:\n"
        "    cmp r5, #1\n"
        "    bne .L080D1AD0\n"
        "    movs r0, #0x64\n"
        "    bl sub_080C51D4\n"
        ".L080D1AD0:\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// Name_Equals8 @ 0x080D1AD8
/* Compares two 8-byte names; returns 0 when equal. */
u32 Name_Equals8(const u8 *a, const u8 *b)
{
    if (a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3]
        && a[4] == b[4] && a[5] == b[5] && a[6] == b[6] && a[7] == b[7])
        return 0;
    return 1;
}

// NameEntry_ValidateName @ 0x080D1B28
/* Name entry: accept the name only if it is not empty and differs from every other name. */
void NameEntry_ValidateName(struct MenuTask *task)
{
    struct SaveMenu *menu = &gMenuState;
    u8 *name;
    u8 *self;
    u8 (*names)[8];
    u32 valid;
    u32 i;

    task->unk1C = 0;
    Flag_Set(0x164);
    if (menu->u.name.name[0] == 0xFF)
        return;
    valid = FALSE;
    i = 0;
    name = menu->u.name.name;
    for (; i < 8; i++)
    {
        if (menu->u.name.name[i] != 0 && menu->u.name.name[i] != 0xFF)
            valid = TRUE;
    }
    if (!valid)
        return;

    if (!(menu->mode & 0x8000))
    {
        self = Party_GetMember(menu->mode + 0x8000);
        for (i = 0; i < 3; i++)
        {
            u8 *other = Party_GetMember(i + 0x8000);

            if (self[0xC] != i && Name_Equals8(name, other) == 0)
                return;
        }
        names = gGameState.names;
        if (Name_Equals8(name, names[0]) == 0)
            return;
        if (Name_Equals8(name, names[1]) == 0)
            return;
        if (Name_Equals8(name, names[2]) == 0)
            return;
        if (self[0xC] != 0 && Name_Equals8(name, names[3]) == 0)
            return;
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            if (Name_Equals8(name, Party_GetMember(i + 0x8000)) == 0)
                return;
        }
        if (menu->mode != 0x8000 && Name_Equals8(name, gGameState.names[0]) == 0)
            return;
        if (menu->mode != 0x8001 && Name_Equals8(name, gGameState.names[1]) == 0)
            return;
        if (menu->mode != 0x8002 && Name_Equals8(name, gGameState.names[2]) == 0)
            return;
        if (menu->mode != 0x8003 && Name_Equals8(name, gGameState.names[3]) == 0)
            return;
    }
    Flag_Clear(0x164);
    task->unk1C = 1;
}

// sub_080D1C98 @ 0x080D1C98
void sub_080D1C98(void)
{
    struct SaveMenu *menu = &gMenuState;
    u16 unused[10];
    u32 i;

    for (i = 0; i < 9; i++)
        Font_CopyGlyphCell(Font_GetGlyphBitmap(gUnknown_084F3060[i]), gUnk_02000000 + i * 0x40);
    menu->u.name.msgShown = 1;
    VBlankTask_AddCounted(sub_080D1538, 1);
}

// sub_080D1CE0 @ 0x080D1CE0
void sub_080D1CE0(struct MenuTask *task)
{
    struct SaveMenu *menu = &gMenuState;

    if (gKeysNew & 1)
    {
        menu->u.name.msgShown = 0;
        NameEntry_RenderName(task);
        task->unk1C = 1;
    }
    else
        task->unk1C = 0;
}

// NameEntry_StoreName @ 0x080D1D14
/* Name entry finished: store the name (0xFF gaps inside it become 0). */
void NameEntry_StoreName(void)
{
    struct SaveMenu *menu = &gMenuState;
    u8 *dst;
    u32 seen, isHero;
    u32 i;
    u8 c;

    Window_Close(menu->u.name.window, 0);
    if (!Flag_Test(0x164))
    {
        seen = FALSE;
        isHero = FALSE;
        if (!(menu->mode & 0x8000))
        {
            dst = Party_GetMember(menu->mode + 0x8000);
            if (dst[0xC] == 0)
                isHero = TRUE;
        }
        else
            dst = gGameState.names[menu->mode & 0x7FFF];
        for (i = 0; i < 8; i++)
        {
            c = menu->u.name.name[7 - i];
            if (c != 0xFF)
                seen = TRUE;
            else if (seen == TRUE)
                c = 0;
            dst[7 - i] = c;
            if (isHero == TRUE)
                gGameState.names[3][7 - i] = c;
        }
    }
    sub_080C1440();
    gUnk_03000004 = 0;
    sub_080C6E30(0);
    gUnk_0200F7D8[2] = 0x5000;
    gUnk_0200F7D8[3] = 0x5000;
    gUnk_0200F7D8[4] = 0x5000;
    gUnk_0200F7D8[5] = 0x5000;
    Party_BuildMemberNameTiles();
    sub_080C6FD8();
    Font_ResetGlyphSpriteCache(0x180);
}

// sub_080D1DF4 @ 0x080D1DF4
void sub_080D1DF4(void)
{
    vu32 zero;

    DmaSet3(gUnknown_081B13B8, 0x06010000, 0x84000800);
    zero = 0;
    DmaSet3(&zero, 0x06001340, 0x85000070);
}

// sub_080D1E34 @ 0x080D1E34
void sub_080D1E34(void)
{
    VBlankTask_AddCounted(sub_080D1DF4, 1);
}

// NameEntry_Open @ 0x080D1E48
u32 NameEntry_Open(u16 target)
{
    struct SaveMenu *menu;
    u32 ret = Task_Create(NameEntry_InitAllyNameInput, 0xFFFF);
    u32 zero;
    u32 i;

    menu = &gMenuState;
    zero = 0;
    CpuSet(&zero, menu, 0x05000200);
    menu->mode = target;
    menu->u.name.unk12 = 4;
    Flag_Clear(0x164);
    for (i = 0; i < 8; i++)
        menu->u.name.name[i] |= 0xFF;
    return ret;
}

// sub_080D1EA8 @ 0x080D1EA8
u32 sub_080D1EA8(u16 *arg0)
{
    u32 ret = 0;

    if (*arg0 == 0)
        ret = 1;
    return ret;
}

// sub_080D1EBC @ 0x080D1EBC
void sub_080D1EBC(void)
{
    struct SaveMenu *menu = &gMenuState;

    DmaSet3(gUnk_0200F874, 0x06015000, 0x84000400);
    menu->unk08 = 0;
}

// sub_080D1EE8 @ 0x080D1EE8
void sub_080D1EE8(void)
{
    DmaSet3(gUnk_0200F874, 0x06014800, 0x84000200);
}

// sub_080D1F0C @ 0x080D1F0C
void sub_080D1F0C(void)
{
    struct SaveMenu *menu = &gMenuState;

    if (menu->mode != 0 && menu->unk08 == 0)
    {
        VBlankTask_AddCounted(sub_080D1EBC, 1);
        menu->unk08 = 1;
    }
}

// sub_080D1F38 @ 0x080D1F38
void sub_080D1F38(void)
{
    LZ77UnCompWram(gUnknown_081B5870, gUnk_0200F874);
    DmaSet3(gUnk_0200F874 + 0x980, gUnk_0200F874 + 0x2A0, 0x84000008);
    DmaSet3(gUnknown_081AE5B8, gUnk_0200F874 + 0x2C0, 0x84000050);
    DmaSet3(gUnknown_081AE5B8 + 0x400, gUnk_0200F874 + 0x6C0, 0x84000050);
    VBlankTask_AddCounted(sub_080D1EE8, 1);
}

// sub_080D1FAC @ 0x080D1FAC
void sub_080D1FAC(void)
{
    struct SaveMenu *menu = &gMenuState;
    u32 zero = 0;

    CpuSet(&zero, gUnk_0200F874, 0x05000400);
    if (menu->mode != 0)
    {
        Palette_CopyWithEffect(3, gUnknown_081B6ED0, &gUnk_03002E10[0x1A0], 0x20, 0x20);
        Palette_MarkDirty();
    }
    sub_080D1F0C();
}

// sub_080D1FFC @ 0x080D1FFC
void sub_080D1FFC(void)
{
    struct StatusMenu *menu = STATUS_MENU;

    if (menu->window14 != 0)
        Window_Close((u32)menu->window14, 1);
    if (menu->window18 != 0)
        Window_Close((u32)menu->window18, 1);
    menu->window14 = 0;
    menu->window18 = 0;
}
