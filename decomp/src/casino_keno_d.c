/* 8x8 number game: payout table and number statistics (0x0814971C-). */

#define CASINO2_SPRITE_DRAW_KR
#include "global.h"
#include "casino2.h"

/* Draws the payout table for the current number of marks: up to nine rows of hits (four
   nibble glyphs) and payout (eight nibbles; nibble 0xB is a separator, the nibble after
   it selects its glyph). */
// Keno_DrawPayTable @ 0x0814971C
#ifdef NONMATCHING
void Keno_DrawPayTable(void)
{
    u16 x, y;
    const u16 *a;
    const u32 *b;
    u16 k;
    u32 w, v;
    u32 sel;
    u32 r;

    if (gGrid->marked == 0 || gDispRegs == 0)
        return;
    x = 0x8C;
    y = 0x34;
    a = gUnknown_0879DA14[gGrid->marked];
    b = gUnknown_0879DB48[gGrid->marked];
    k = 0;
    while (*a != 0)
    {
        w = *a;
        sub_0814966C((w & 0xF000) >> 12, 0, x, y);
        sub_0814966C((w & 0xF00) >> 8, 0, x + 8, y);
        sub_0814966C((w & 0xF0) >> 4, 0, x + 0x10, y);
        sub_0814966C(w & 0xF, 0, x + 0x18, y);
        v = *b;
        if ((v & 0xF0000000) == 0xB0000000)
            sel = (v & 0x0F000000) >> 24;
        if ((v & 0x0F000000) == 0x0B000000)
            sel = (v & 0x00F00000) >> 20;
        if ((v & 0x00F00000) == 0x00B00000)
            sel = (v & 0x000F0000) >> 16;
        if ((v & 0x000F0000) == 0x000B0000)
            sel = (v & 0x0000F000) >> 12;
        if ((v & 0x0000F000) == 0x0000B000)
            sel = (v & 0x00000F00) >> 8;
        if ((v & 0x00000F00) == 0x00000B00)
            sel = (v & 0x000000F0) >> 4;
        if ((v & 0x000000F0) == 0x000000B0)
            sel = v & 0xF;
        r = sub_0814966C((v & 0xF0000000) >> 28, sel, x + 0x20, y);
        if (r == 0)
            r = sub_0814966C((v & 0x0F000000) >> 24, sel, x + 0x28, y);
        else
            r = 0;
        if (r == 0)
            r = sub_0814966C((v & 0x00F00000) >> 20, sel, x + 0x30, y);
        else
            r = 0;
        if ((v & 0xFFFFF) == 0)
        {
            Sprite_Draw(gUnknown_08151B68, 1, 0, 0, 0, x + 0x38, y);
            goto next;
        }
        if (r == 0)
            r = sub_0814966C((v & 0x000F0000) >> 16, sel, x + 0x38, y);
        else
            r = 0;
        if ((v & 0xFFFF) == 0)
        {
            Sprite_Draw(gUnknown_08151B50, 1, 0, 0, 0, x + 0x40, y);
            goto next;
        }
        if (r == 0)
            r = sub_0814966C((v & 0x0000F000) >> 12, sel, x + 0x40, y);
        else
            r = 0;
        if ((v & 0xFFF) == 0)
        {
            Sprite_Draw(gUnknown_08151B40, 1, 0, 0, 0, x + 0x48, y);
            goto next;
        }
        if (r == 0)
            r = sub_0814966C((v & 0x00000F00) >> 8, sel, x + 0x48, y);
        else
            r = 0;
        if ((v & 0xFF) == 0)
        {
            Sprite_Draw(gUnknown_08151B28, 1, 0, 0, 0, x + 0x50, y);
            goto next;
        }
        if (r == 0)
            r = sub_0814966C((v & 0x000000F0) >> 4, sel, x + 0x50, y);
        else
            r = 0;
        if (r == 0)
            sub_0814966C(v & 0xF, sel, x + 0x58, y);
    next:
        a++;
        b++;
        y += 11;
        if (++k > 8)
            break;
    }
}
#else
NAKED
void Keno_DrawPayTable(void)
{
    asm_unified(
        ".L0814971C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x14\n"
        "    ldr r0, .L08149884\n"
        "    movs r1, #0xc2\n"
        "    lsls r1, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    ldr r1, [r0]\n"
        "    cmp r1, #0\n"
        "    bne .L08149738\n"
        "    b .L08149A00\n"
        ".L08149738:\n"
        "    ldr r0, .L08149888\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L08149742\n"
        "    b .L08149A00\n"
        ".L08149742:\n"
        "    movs r2, #0x8c\n"
        "    mov r8, r2\n"
        "    movs r6, #0x34\n"
        "    lsls r0, r1, #3\n"
        "    adds r0, r0, r1\n"
        "    lsls r2, r0, #1\n"
        "    ldr r1, .L0814988C\n"
        "    adds r2, r2, r1\n"
        "    mov sl, r2\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L08149890\n"
        "    adds r0, r0, r1\n"
        "    str r0, [sp, #0x10]\n"
        "    movs r3, #0\n"
        "    str r3, [sp, #0xc]\n"
        "    ldrh r0, [r2]\n"
        "    cmp r0, #0\n"
        "    bne .L08149768\n"
        "    b .L08149A00\n"
        ".L08149768:\n"
        "    mov r0, sl\n"
        "    ldrh r4, [r0]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0xf0\n"
        "    lsls r1, r1, #8\n"
        "    ands r0, r1\n"
        "    lsrs r0, r0, #0xc\n"
        "    movs r1, #0\n"
        "    mov r2, r8\n"
        "    adds r3, r6, #0\n"
        "    bl sub_0814966C\n"
        "    adds r0, r4, #0\n"
        "    movs r2, #0xf0\n"
        "    lsls r2, r2, #4\n"
        "    ands r0, r2\n"
        "    lsrs r0, r0, #8\n"
        "    mov r2, r8\n"
        "    adds r2, #8\n"
        "    lsls r2, r2, #0x10\n"
        "    movs r1, #0\n"
        "    lsrs r2, r2, #0x10\n"
        "    adds r3, r6, #0\n"
        "    bl sub_0814966C\n"
        "    adds r0, r4, #0\n"
        "    movs r3, #0xf0\n"
        "    ands r0, r3\n"
        "    lsrs r0, r0, #4\n"
        "    mov r2, r8\n"
        "    adds r2, #0x10\n"
        "    lsls r2, r2, #0x10\n"
        "    movs r1, #0\n"
        "    lsrs r2, r2, #0x10\n"
        "    adds r3, r6, #0\n"
        "    bl sub_0814966C\n"
        "    movs r0, #0xf\n"
        "    ands r4, r0\n"
        "    mov r2, r8\n"
        "    adds r2, #0x18\n"
        "    lsls r2, r2, #0x10\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0\n"
        "    lsrs r2, r2, #0x10\n"
        "    adds r3, r6, #0\n"
        "    bl sub_0814966C\n"
        "    ldr r0, [sp, #0x10]\n"
        "    ldr r4, [r0]\n"
        "    movs r7, #0xf0\n"
        "    lsls r7, r7, #0x18\n"
        "    ands r7, r4\n"
        "    movs r0, #0xb0\n"
        "    lsls r0, r0, #0x18\n"
        "    cmp r7, r0\n"
        "    bne .L081497E2\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0x14\n"
        "    ands r0, r4\n"
        "    lsrs r5, r0, #0x18\n"
        ".L081497E2:\n"
        "    movs r1, #0xf0\n"
        "    lsls r1, r1, #0x14\n"
        "    mov sb, r1\n"
        "    mov r2, sb\n"
        "    ands r2, r4\n"
        "    mov sb, r2\n"
        "    movs r0, #0xb0\n"
        "    lsls r0, r0, #0x14\n"
        "    cmp sb, r0\n"
        "    bne .L081497FE\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0x10\n"
        "    ands r0, r4\n"
        "    lsrs r5, r0, #0x14\n"
        ".L081497FE:\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0x10\n"
        "    ands r0, r4\n"
        "    movs r1, #0xb0\n"
        "    lsls r1, r1, #0x10\n"
        "    cmp r0, r1\n"
        "    bne .L08149814\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0xc\n"
        "    ands r0, r4\n"
        "    lsrs r5, r0, #0x10\n"
        ".L08149814:\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0xc\n"
        "    ands r0, r4\n"
        "    movs r1, #0xb0\n"
        "    lsls r1, r1, #0xc\n"
        "    adds r2, r4, #0\n"
        "    movs r3, #0xf0\n"
        "    lsls r3, r3, #8\n"
        "    ands r2, r3\n"
        "    cmp r0, r1\n"
        "    bne .L0814982C\n"
        "    lsrs r5, r2, #0xc\n"
        ".L0814982C:\n"
        "    movs r0, #0xb0\n"
        "    lsls r0, r0, #8\n"
        "    adds r3, r4, #0\n"
        "    movs r1, #0xf0\n"
        "    lsls r1, r1, #4\n"
        "    ands r3, r1\n"
        "    cmp r2, r0\n"
        "    bne .L0814983E\n"
        "    lsrs r5, r3, #8\n"
        ".L0814983E:\n"
        "    movs r0, #0xb0\n"
        "    lsls r0, r0, #4\n"
        "    adds r1, r4, #0\n"
        "    movs r2, #0xf0\n"
        "    ands r1, r2\n"
        "    cmp r3, r0\n"
        "    bne .L0814984E\n"
        "    lsrs r5, r1, #4\n"
        ".L0814984E:\n"
        "    cmp r1, #0xb0\n"
        "    bne .L08149858\n"
        "    adds r5, r4, #0\n"
        "    movs r3, #0xf\n"
        "    ands r5, r3\n"
        ".L08149858:\n"
        "    lsrs r0, r7, #0x1c\n"
        "    mov r2, r8\n"
        "    adds r2, #0x20\n"
        "    lsls r2, r2, #0x10\n"
        "    adds r1, r5, #0\n"
        "    lsrs r2, r2, #0x10\n"
        "    adds r3, r6, #0\n"
        "    bl sub_0814966C\n"
        "    cmp r0, #0\n"
        "    bne .L08149894\n"
        "    mov r1, sb\n"
        "    lsrs r0, r1, #0x18\n"
        "    mov r2, r8\n"
        "    adds r2, #0x28\n"
        "    lsls r2, r2, #0x10\n"
        "    adds r1, r5, #0\n"
        "    lsrs r2, r2, #0x10\n"
        "    adds r3, r6, #0\n"
        "    bl sub_0814966C\n"
        "    b .L08149896\n"
        ".L08149884: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L08149888: .4byte 0x03000000 @ IWRAM\n"
        ".L0814988C: .4byte gUnknown_0879DA14\n"
        ".L08149890: .4byte gUnknown_0879DB48\n"
        ".L08149894:\n"
        "    movs r0, #0\n"
        ".L08149896:\n"
        "    cmp r0, #0\n"
        "    bne .L081498B4\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0x10\n"
        "    ands r0, r4\n"
        "    lsrs r0, r0, #0x14\n"
        "    mov r2, r8\n"
        "    adds r2, #0x30\n"
        "    lsls r2, r2, #0x10\n"
        "    adds r1, r5, #0\n"
        "    lsrs r2, r2, #0x10\n"
        "    adds r3, r6, #0\n"
        "    bl sub_0814966C\n"
        "    b .L081498B6\n"
        ".L081498B4:\n"
        "    movs r0, #0\n"
        ".L081498B6:\n"
        "    ldr r1, .L081498CC\n"
        "    ands r1, r4\n"
        "    cmp r1, #0\n"
        "    bne .L081498D4\n"
        "    str r1, [sp]\n"
        "    mov r0, r8\n"
        "    adds r0, #0x38\n"
        "    str r0, [sp, #4]\n"
        "    str r6, [sp, #8]\n"
        "    ldr r0, .L081498D0\n"
        "    b .L0814998A\n"
        ".L081498CC: .4byte 0x000FFFFF\n"
        ".L081498D0: .4byte gUnknown_08151B68\n"
        ".L081498D4:\n"
        "    cmp r0, #0\n"
        "    bne .L081498F2\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0xc\n"
        "    ands r0, r4\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r2, r8\n"
        "    adds r2, #0x38\n"
        "    lsls r2, r2, #0x10\n"
        "    adds r1, r5, #0\n"
        "    lsrs r2, r2, #0x10\n"
        "    adds r3, r6, #0\n"
        "    bl sub_0814966C\n"
        "    b .L081498F4\n"
        ".L081498F2:\n"
        "    movs r0, #0\n"
        ".L081498F4:\n"
        "    ldr r1, .L0814990C\n"
        "    ands r1, r4\n"
        "    cmp r1, #0\n"
        "    bne .L08149914\n"
        "    str r1, [sp]\n"
        "    mov r0, r8\n"
        "    adds r0, #0x40\n"
        "    str r0, [sp, #4]\n"
        "    str r6, [sp, #8]\n"
        "    ldr r0, .L08149910\n"
        "    b .L0814998A\n"
        "    .byte 0x00, 0x00\n"
        ".L0814990C: .4byte 0x0000FFFF\n"
        ".L08149910: .4byte gUnknown_08151B50\n"
        ".L08149914:\n"
        "    cmp r0, #0\n"
        "    bne .L08149934\n"
        "    adds r0, r4, #0\n"
        "    movs r2, #0xf0\n"
        "    lsls r2, r2, #8\n"
        "    ands r0, r2\n"
        "    lsrs r0, r0, #0xc\n"
        "    mov r2, r8\n"
        "    adds r2, #0x40\n"
        "    lsls r2, r2, #0x10\n"
        "    adds r1, r5, #0\n"
        "    lsrs r2, r2, #0x10\n"
        "    adds r3, r6, #0\n"
        "    bl sub_0814966C\n"
        "    b .L08149936\n"
        ".L08149934:\n"
        "    movs r0, #0\n"
        ".L08149936:\n"
        "    ldr r1, .L0814994C\n"
        "    ands r1, r4\n"
        "    cmp r1, #0\n"
        "    bne .L08149954\n"
        "    str r1, [sp]\n"
        "    mov r0, r8\n"
        "    adds r0, #0x48\n"
        "    str r0, [sp, #4]\n"
        "    str r6, [sp, #8]\n"
        "    ldr r0, .L08149950\n"
        "    b .L0814998A\n"
        ".L0814994C: .4byte 0x00000FFF\n"
        ".L08149950: .4byte gUnknown_08151B40\n"
        ".L08149954:\n"
        "    cmp r0, #0\n"
        "    bne .L08149974\n"
        "    adds r0, r4, #0\n"
        "    movs r3, #0xf0\n"
        "    lsls r3, r3, #4\n"
        "    ands r0, r3\n"
        "    lsrs r0, r0, #8\n"
        "    mov r2, r8\n"
        "    adds r2, #0x48\n"
        "    lsls r2, r2, #0x10\n"
        "    adds r1, r5, #0\n"
        "    lsrs r2, r2, #0x10\n"
        "    adds r3, r6, #0\n"
        "    bl sub_0814966C\n"
        "    b .L08149976\n"
        ".L08149974:\n"
        "    movs r0, #0\n"
        ".L08149976:\n"
        "    movs r1, #0xff\n"
        "    ands r1, r4\n"
        "    cmp r1, #0\n"
        "    bne .L0814999C\n"
        "    str r1, [sp]\n"
        "    mov r0, r8\n"
        "    adds r0, #0x50\n"
        "    str r0, [sp, #4]\n"
        "    str r6, [sp, #8]\n"
        "    ldr r0, .L08149998\n"
        ".L0814998A:\n"
        "    movs r1, #1\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    b .L081499D6\n"
        "    .byte 0x00, 0x00\n"
        ".L08149998: .4byte gUnknown_08151B28\n"
        ".L0814999C:\n"
        "    cmp r0, #0\n"
        "    bne .L081499BA\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0xf0\n"
        "    ands r0, r1\n"
        "    lsrs r0, r0, #4\n"
        "    mov r2, r8\n"
        "    adds r2, #0x50\n"
        "    lsls r2, r2, #0x10\n"
        "    adds r1, r5, #0\n"
        "    lsrs r2, r2, #0x10\n"
        "    adds r3, r6, #0\n"
        "    bl sub_0814966C\n"
        "    b .L081499BC\n"
        ".L081499BA:\n"
        "    movs r0, #0\n"
        ".L081499BC:\n"
        "    cmp r0, #0\n"
        "    bne .L081499D6\n"
        "    movs r2, #0xf\n"
        "    ands r4, r2\n"
        "    mov r2, r8\n"
        "    adds r2, #0x58\n"
        "    lsls r2, r2, #0x10\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r5, #0\n"
        "    lsrs r2, r2, #0x10\n"
        "    adds r3, r6, #0\n"
        "    bl sub_0814966C\n"
        ".L081499D6:\n"
        "    movs r3, #2\n"
        "    add sl, r3\n"
        "    ldr r0, [sp, #0x10]\n"
        "    adds r0, #4\n"
        "    str r0, [sp, #0x10]\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0xb\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldr r0, [sp, #0xc]\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0xc]\n"
        "    cmp r0, #8\n"
        "    bhi .L08149A00\n"
        "    mov r1, sl\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #0\n"
        "    beq .L08149A00\n"
        "    b .L08149768\n"
        ".L08149A00:\n"
        "    add sp, #0x14\n"
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

// sub_08149A10 @ 0x08149A10
void sub_08149A10(void)
{
    struct C145Grid *s = gGrid;
    u16 i;

    for (i = 0; i < 64; i++)
    {
        s->mark[i] &= 0x8000;
        s->cell[i] = 0;
    }
}

/* Marks each number with how often it came up in the last 16 rounds (level 1-8). */
// Keno_ShowHotNumbers @ 0x08149A4C
void Keno_ShowHotNumbers(void)
{
    struct C145Grid *s = gGrid;
    u16 i, j;
    u16 n;

    sub_08149A10();
    for (i = 0; i < 64; i++)
    {
        n = 0;
        for (j = 0; j < 16; j++)
        {
            if ((s->history[j][i >> 3] >> (i & 7)) & 1)
                n++;
        }
        switch (n)
        {
        case 0:
            s->mark[i] |= 1;
            break;
        case 1:
            s->mark[i] |= 2;
            break;
        case 2:
            s->mark[i] |= 3;
            break;
        case 3:
        case 4:
        case 5:
            s->mark[i] |= 4;
            break;
        case 6:
            s->mark[i] |= 5;
            break;
        case 7:
            s->mark[i] |= 6;
            break;
        case 8:
            s->mark[i] |= 7;
            break;
        default:
            s->mark[i] |= 8;
            break;
        }
    }
}

/* Records this round's drawn numbers in the history ring. */
// Keno_RecordHistory @ 0x08149B38
void Keno_RecordHistory(void)
{
    struct C145Grid *s = gGrid;
    u32 row = s->historyRow;
    u16 i;

    for (i = 0; i < 64; i++)
    {
        if (s->cell[i] != 0)
            s->history[row][i >> 3] |= 1 << (i & 7);
        else
            s->history[row][i >> 3] &= ~(1 << (i & 7));
    }
    s->historyRow = (s->historyRow + 1) & 0xF;
}
