/* 8x8 number game: main loop (0x08148964). Bet up to 100 (menu item 1), mark up to 16
   numbers on the board (state 3), then start the draw. */

#include "global.h"
#include "casino2.h"

// Keno_Update @ 0x08148964
#ifdef NONMATCHING
void Keno_Update(void)
{
    struct C145Grid *s = gGrid;
    u16 i;
    u32 n;
    u16 bx, by;
    u16 x, y;
    u16 pal;
    u16 *p;

    if ((gFrameCounter & 3) == 0)
    {
        if (s->unk19E == 0)
        {
            if (++s->unk19A == 12)
                s->unk19E = 1;
        }
        else
        {
            if (--s->unk19A == 4)
                s->unk19E = 0;
        }
        gUnk_03000042 = (s->unk19A << 8) | s->unk198;
        gUnk_03000044 = s->unk19C;
    }
    switch (s->state)
    {
    case 0:
        break;
    case 1:
        Task_Create(gUnknown_0879D100, 0xFFFF);
        s->state = 0;
        break;
    case 2:
        if ((gRepeatedKeys & 1) && s->menu == 1)
        {
            if (s->coins == 0)
                break;
            n = 1;
            if (gUnk_030031D0 & 4)
                n = 10;
            if (n > s->coins)
                n = s->coins;
            if (s->bet + n > 100)
                n = 100 - s->bet;
            s->bet += n;
            s->coins -= n;
            Sound_Play(0x160);
            break;
        }
        if (gKeysNew & 1)
        {
            switch (s->menu)
            {
            case 0:
                s->cursorX = 0;
                s->cursorY = 0;
                s->state = 3;
                s->menu |= 0x8000;
                for (i = 0; i < 64; i++)
                    s->cell[i] = 0;
                gDispRegs = 0xF0;
                break;
            case 2:
                if ((s->mark[0] & 0x7FFF) == 0)
                {
                    Task_Create(gUnknown_0879D910, 0xFFFF);
                    s->state = 0;
                }
                else
                {
                    Task_Create(gUnknown_0879D9B0, 0xFFFF);
                    s->state = 0;
                }
                Sound_Play(0x164);
                break;
            case 3:
                for (i = 0; i < 64; i++)
                    s->mark[i] &= 0x7FFF;
                s->marked = 0;
                Sound_Play(0x163);
                break;
            }
            break;
        }
        if ((gKeysNew & 0x100) && Keno_CanStart() == 1)
        {
            Keno_StartRound();
            break;
        }
        if ((gKeysNew & 0x200) && s->sprFrame[0] == 0)
        {
            sub_08149640();
            break;
        }
        if ((gRepeatedKeys & 2) && s->menu == 1)
        {
            if (s->bet == 0)
                break;
            n = 1;
            if (gUnk_030031D0 & 4)
                n = 10;
            if (n > s->bet)
                n = s->bet;
            s->bet -= n;
            s->coins += n;
            Sound_Play(0x160);
            break;
        }
        if (gKeysNew & 2)
            break;
        if (gRepeatedKeys & 0x20)
        {
            if (s->menu != 0)
                s->menu--;
            else
                s->menu = 3;
        }
        else if (gRepeatedKeys & 0x10)
        {
            if (s->menu != 3)
                s->menu++;
            else
                s->menu = 0;
        }
        break;
    case 3:
        if (!sub_081490E4(2, 0xA0))
            break;
        if (gKeysNew & 1)
        {
            p = &s->mark[s->cursorY * 8 + s->cursorX];
            if (*p & 0x8000)
            {
                *p &= 0x7FFF;
                s->marked--;
            }
            else if (s->marked != 16)
            {
                *p |= 0x8000;
                s->marked++;
            }
            Sound_Play(0x164);
            break;
        }
        if (gKeysNew & 2)
        {
            s->state = 2;
            s->menu = 1;
            break;
        }
        if ((gKeysNew & 0x100) && Keno_CanStart() == 1)
        {
            Sound_Play(0x158);
            Keno_StartRound();
            break;
        }
        if ((gKeysNew & 0x200) && s->sprFrame[0] == 0)
        {
            sub_08149640();
            break;
        }
        if (gRepeatedKeys & 0x40)
        {
            if (s->cursorY != 0)
                s->cursorY--;
            else
                s->cursorY = 7;
        }
        else if (gRepeatedKeys & 0x80)
        {
            if (s->cursorY != 7)
                s->cursorY++;
            else
                s->cursorY = 0;
        }
        else if (gRepeatedKeys & 0x20)
        {
            if (s->cursorX != 0)
                s->cursorX--;
            else
                s->cursorX = 7;
        }
        else if (gRepeatedKeys & 0x10)
        {
            if (s->cursorX != 7)
                s->cursorX++;
            else
                s->cursorX = 0;
        }
        break;
    }

    /* The board: drawn numbers bright, marked ones blended, the rest coloured by how
       often they came up (gUnknown_0879DDC4). */
    bx = 8;
    by = 0x27;
    for (i = 0; i < 64; i++)
    {
        x = (i & 7) * 15 + bx;
        y = (i >> 3) * 11 + by;
        if (i > 31)
            y += 0x1B;
        if (s->cell[i] != 0)
        {
            if (s->mark[i] & 0x8000)
                Sprite_DrawBlended(gUnknown_0879CD14[i], 1, 9, 0, 0, x, y);
            else
                Sprite_Draw(gUnknown_0879CD14[i], 1, 9, 0, 0, x, y);
        }
        else if (!(s->mark[i] & 0x8000))
        {
            pal = 5;
            if (s->mark[i] & 0x7FFF)
                pal = gUnknown_0879DDC4[(s->mark[i] & 0x7FFF) - 1];
            Sprite_Draw(gUnknown_0879CD14[i], 1, pal, 0, 0, x, y);
        }
        else
        {
            pal = 11;
            if (s->mark[i] & 0x7FFF)
                pal = gUnknown_0879DDC4[(s->mark[i] & 0x7FFF) - 1];
            Sprite_DrawBlended(gUnknown_0879CD14[i], 1, pal, 0, 0, x, y);
        }
    }
    sub_08148618();
    Keno_DrawDigits(s->marked, 2, 0xF, 0x5E);
    Keno_DrawDigits(s->drawn, 2, 0x3D, 0x5E);
    Keno_DrawDigits(s->hits, 2, 0x6A, 0x5E);
    Keno_DrawDigits(s->bet, 3, 0x93, 0x1C);
    Keno_DrawDigits(s->coins, 6, 0xBA, 0x1C);
    if (!(s->menu & 0x8000))
    {
        bx = s->menu * 30 + 9;
        Sprite_Draw(gUnknown_0879CE14[s->menu], 1, 0, 0, 0, bx, 0x1B);
    }
    Keno_DrawPayTable();
    if (s->sprFrame[0] != 1)
    {
        sub_0814869C(2, 8, 6);
        if (s->state == 4)
        {
            if (((gFrameCounter / 7) & 1) == 0)
                sub_08148718(2, 1, 0, 0);
            else
                sub_08148718(2, 0, 0, 0);
        }
    }
    if ((gFrameCounter & 3) == 0)
    {
        if (s->bet != 0)
        {
            if (s->sprFrame[0] == 0)
                s->sprFrame[0] = 4;
            else if (s->sprFrame[0] != 1)
                s->sprFrame[0]--;
        }
        else if (s->sprFrame[0] != 0)
        {
            if (s->sprFrame[0] != 4)
                s->sprFrame[0]++;
            else
                s->sprFrame[0] = 0;
        }
    }
    sub_0814869C(0, 7, 4);
    sub_0814869C(3, 0xBA, 6);
    if (Keno_CanStart() == 1)
    {
        if (((gFrameCounter >> 4) & 1) == 0)
            sub_08148718(3, 1, 0, 0);
        else
            sub_08148718(3, 0, 0, 0);
    }
    else
    {
        sub_08148718(3, 0, 0, 0);
    }
    sub_0814869C(1, 0xBB, 4);
    if (s->state != 5)
    {
        sub_0814869C(4, 0xBB, 4);
        if ((gFrameCounter & 3) == 0)
        {
            if (s->sprFrame[4] != 6)
                s->sprFrame[4]++;
            else
                s->sprFrame[4] = 1;
        }
    }
}
#else
NAKED
void Keno_Update(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x14\n"
        "    ldr r5, .L081489A8\n"
        "    ldr r0, .L081489AC\n"
        "    ldr r1, [r0]\n"
        "    movs r0, #3\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    bne .L081489EA\n"
        "    movs r0, #0xcf\n"
        "    lsls r0, r0, #1\n"
        "    adds r3, r5, r0\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r3, r2]\n"
        "    cmp r0, #0\n"
        "    bne .L081489B0\n"
        "    movs r6, #0xcd\n"
        "    lsls r6, r6, #1\n"
        "    adds r1, r5, r6\n"
        "    ldrh r0, [r1]\n"
        "    adds r0, #1\n"
        "    strh r0, [r1]\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #0xc\n"
        "    bne .L081489C6\n"
        "    movs r0, #1\n"
        "    strh r0, [r3]\n"
        "    b .L081489C6\n"
        "    .byte 0x00, 0x00\n"
        ".L081489A8: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L081489AC: .4byte 0x030031BC @ IWRAM+0x31BC\n"
        ".L081489B0:\n"
        "    movs r0, #0xcd\n"
        "    lsls r0, r0, #1\n"
        "    adds r2, r5, r0\n"
        "    ldrh r0, [r2]\n"
        "    subs r0, #1\n"
        "    strh r0, [r2]\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #4\n"
        "    bne .L081489C6\n"
        "    strh r1, [r3]\n"
        ".L081489C6:\n"
        "    ldr r2, .L08148A0C\n"
        "    movs r1, #0xcd\n"
        "    lsls r1, r1, #1\n"
        "    adds r0, r5, r1\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #8\n"
        "    movs r3, #0xcc\n"
        "    lsls r3, r3, #1\n"
        "    adds r1, r5, r3\n"
        "    ldrh r1, [r1]\n"
        "    orrs r0, r1\n"
        "    strh r0, [r2]\n"
        "    ldr r1, .L08148A10\n"
        "    movs r6, #0xce\n"
        "    lsls r6, r6, #1\n"
        "    adds r0, r5, r6\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r1]\n"
        ".L081489EA:\n"
        "    ldrh r0, [r5]\n"
        "    cmp r0, #1\n"
        "    beq .L08148A14\n"
        "    adds r1, r5, #4\n"
        "    mov r8, r1\n"
        "    movs r2, #0x84\n"
        "    adds r2, r2, r5\n"
        "    mov sb, r2\n"
        "    cmp r0, #1\n"
        "    bgt .L08148A00\n"
        "    b .L08148DF6\n"
        ".L08148A00:\n"
        "    cmp r0, #2\n"
        "    beq .L08148A2C\n"
        "    cmp r0, #3\n"
        "    bne .L08148A0A\n"
        "    b .L08148C86\n"
        ".L08148A0A:\n"
        "    b .L08148DF6\n"
        ".L08148A0C: .4byte 0x03000042 @ IWRAM+0x42\n"
        ".L08148A10: .4byte 0x03000044 @ IWRAM+0x44\n"
        ".L08148A14:\n"
        "    ldr r0, .L08148A24\n"
        "    ldr r1, .L08148A28\n"
        "    bl Task_Create\n"
        "    movs r0, #0\n"
        "    strh r0, [r5]\n"
        "    b .L08148BAC\n"
        "    .byte 0x00, 0x00\n"
        ".L08148A24: .4byte gUnknown_0879D100\n"
        ".L08148A28: .4byte 0x0000FFFF\n"
        ".L08148A2C:\n"
        "    ldr r0, .L08148A80\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08148A88\n"
        "    ldrh r0, [r5, #2]\n"
        "    cmp r0, #1\n"
        "    bne .L08148A88\n"
        "    movs r0, #0xca\n"
        "    lsls r0, r0, #1\n"
        "    adds r4, r5, r0\n"
        "    ldr r2, [r4]\n"
        "    cmp r2, #0\n"
        "    bne .L08148A4C\n"
        "    b .L08148DF6\n"
        ".L08148A4C:\n"
        "    movs r3, #1\n"
        "    ldr r0, .L08148A84\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #4\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08148A5C\n"
        "    movs r3, #0xa\n"
        ".L08148A5C:\n"
        "    cmp r3, r2\n"
        "    bls .L08148A62\n"
        "    adds r3, r2, #0\n"
        ".L08148A62:\n"
        "    movs r1, #0xc8\n"
        "    lsls r1, r1, #1\n"
        "    adds r2, r5, r1\n"
        "    ldr r1, [r2]\n"
        "    adds r0, r1, r3\n"
        "    cmp r0, #0x64\n"
        "    bls .L08148A74\n"
        "    movs r0, #0x64\n"
        "    subs r3, r0, r1\n"
        ".L08148A74:\n"
        "    adds r0, r1, r3\n"
        "    str r0, [r2]\n"
        "    ldr r0, [r4]\n"
        "    subs r0, r0, r3\n"
        "    str r0, [r4]\n"
        "    b .L08148C2A\n"
        ".L08148A80: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L08148A84: .4byte 0x030031D0 @ IWRAM+0x31D0\n"
        ".L08148A88:\n"
        "    ldr r2, .L08148AB0\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L08148A96\n"
        "    b .L08148B94\n"
        ".L08148A96:\n"
        "    ldrh r1, [r5, #2]\n"
        "    cmp r1, #2\n"
        "    beq .L08148B10\n"
        "    cmp r1, #2\n"
        "    bgt .L08148AB4\n"
        "    cmp r1, #0\n"
        "    beq .L08148AC4\n"
        "    adds r2, r5, #4\n"
        "    mov r8, r2\n"
        "    movs r3, #0x84\n"
        "    adds r3, r3, r5\n"
        "    mov sb, r3\n"
        "    b .L08148DF6\n"
        ".L08148AB0: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L08148AB4:\n"
        "    cmp r1, #3\n"
        "    beq .L08148B54\n"
        "    adds r6, r5, #4\n"
        "    mov r8, r6\n"
        "    movs r0, #0x84\n"
        "    adds r0, r0, r5\n"
        "    mov sb, r0\n"
        "    b .L08148DF6\n"
        ".L08148AC4:\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0xfc\n"
        "    strh r1, [r0]\n"
        "    adds r0, #2\n"
        "    strh r1, [r0]\n"
        "    movs r0, #3\n"
        "    strh r0, [r5]\n"
        "    ldrh r1, [r5, #2]\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #8\n"
        "    adds r0, r2, #0\n"
        "    orrs r0, r1\n"
        "    strh r0, [r5, #2]\n"
        "    movs r4, #0\n"
        "    ldr r3, .L08148B0C\n"
        "    adds r6, r5, #4\n"
        "    mov r8, r6\n"
        "    movs r0, #0x84\n"
        "    adds r0, r0, r5\n"
        "    mov sb, r0\n"
        "    movs r2, #0x81\n"
        "    lsls r2, r2, #1\n"
        "    adds r1, r5, r2\n"
        "    movs r2, #0\n"
        ".L08148AF4:\n"
        "    lsls r0, r4, #1\n"
        "    adds r0, r1, r0\n"
        "    strh r2, [r0]\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #0x3f\n"
        "    bls .L08148AF4\n"
        "    movs r0, #0xf0\n"
        "    strh r0, [r3]\n"
        "    b .L08148DF6\n"
        "    .byte 0x00, 0x00\n"
        ".L08148B0C: .4byte 0x03000000 @ IWRAM\n"
        ".L08148B10:\n"
        "    ldrh r0, [r5, #4]\n"
        "    ldr r4, .L08148B28\n"
        "    ands r4, r0\n"
        "    cmp r4, #0\n"
        "    bne .L08148B34\n"
        "    ldr r0, .L08148B2C\n"
        "    ldr r1, .L08148B30\n"
        "    bl Task_Create\n"
        "    strh r4, [r5]\n"
        "    b .L08148B40\n"
        "    .byte 0x00, 0x00\n"
        ".L08148B28: .4byte 0x00007FFF\n"
        ".L08148B2C: .4byte gUnknown_0879D910\n"
        ".L08148B30: .4byte 0x0000FFFF\n"
        ".L08148B34:\n"
        "    ldr r0, .L08148B4C\n"
        "    ldr r1, .L08148B50\n"
        "    bl Task_Create\n"
        "    movs r0, #0\n"
        "    strh r0, [r5]\n"
        ".L08148B40:\n"
        "    movs r0, #0xb2\n"
        "    lsls r0, r0, #1\n"
        "    bl Sound_Play\n"
        "    b .L08148BAC\n"
        "    .byte 0x00, 0x00\n"
        ".L08148B4C: .4byte gUnknown_0879D9B0\n"
        ".L08148B50: .4byte 0x0000FFFF\n"
        ".L08148B54:\n"
        "    movs r4, #0\n"
        "    adds r0, r5, #4\n"
        "    mov r8, r0\n"
        "    movs r1, #0x84\n"
        "    adds r1, r1, r5\n"
        "    mov sb, r1\n"
        "    mov r3, r8\n"
        "    ldr r6, .L08148B8C\n"
        ".L08148B64:\n"
        "    lsls r1, r4, #1\n"
        "    adds r1, r3, r1\n"
        "    ldrh r2, [r1]\n"
        "    adds r0, r6, #0\n"
        "    ands r0, r2\n"
        "    strh r0, [r1]\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #0x3f\n"
        "    bls .L08148B64\n"
        "    movs r2, #0xc2\n"
        "    lsls r2, r2, #1\n"
        "    adds r0, r5, r2\n"
        "    movs r1, #0\n"
        "    str r1, [r0]\n"
        "    ldr r0, .L08148B90\n"
        "    bl Sound_Play\n"
        "    b .L08148DF6\n"
        ".L08148B8C: .4byte 0x00007FFF\n"
        ".L08148B90: .4byte 0x00000163\n"
        ".L08148B94:\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08148BB8\n"
        "    bl Keno_CanStart\n"
        "    cmp r0, #1\n"
        "    bne .L08148BB8\n"
        "    bl Keno_StartRound\n"
        ".L08148BAC:\n"
        "    adds r3, r5, #4\n"
        "    mov r8, r3\n"
        "    movs r6, #0x84\n"
        "    adds r6, r6, r5\n"
        "    mov sb, r6\n"
        "    b .L08148DF6\n"
        ".L08148BB8:\n"
        "    ldr r2, .L08148BDC\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #2\n"
        "    ands r0, r1\n"
        "    adds r3, r2, #0\n"
        "    movs r1, #0x84\n"
        "    adds r1, r1, r5\n"
        "    mov sb, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08148BE0\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #0\n"
        "    bne .L08148BE0\n"
        "    bl sub_08149640\n"
        "    b .L08148DC8\n"
        "    .byte 0x00, 0x00\n"
        ".L08148BDC: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L08148BE0:\n"
        "    ldr r2, .L08148C34\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08148C3C\n"
        "    ldrh r0, [r5, #2]\n"
        "    cmp r0, #1\n"
        "    bne .L08148C3C\n"
        "    movs r3, #0xc8\n"
        "    lsls r3, r3, #1\n"
        "    adds r4, r5, r3\n"
        "    ldr r2, [r4]\n"
        "    adds r6, r5, #4\n"
        "    mov r8, r6\n"
        "    cmp r2, #0\n"
        "    bne .L08148C04\n"
        "    b .L08148DF6\n"
        ".L08148C04:\n"
        "    movs r3, #1\n"
        "    ldr r0, .L08148C38\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #4\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08148C14\n"
        "    movs r3, #0xa\n"
        ".L08148C14:\n"
        "    cmp r3, r2\n"
        "    bls .L08148C1A\n"
        "    adds r3, r2, #0\n"
        ".L08148C1A:\n"
        "    subs r0, r2, r3\n"
        "    str r0, [r4]\n"
        "    movs r0, #0xca\n"
        "    lsls r0, r0, #1\n"
        "    adds r1, r5, r0\n"
        "    ldr r0, [r1]\n"
        "    adds r0, r0, r3\n"
        "    str r0, [r1]\n"
        ".L08148C2A:\n"
        "    movs r0, #0xb0\n"
        "    lsls r0, r0, #1\n"
        "    bl Sound_Play\n"
        "    b .L08148DF6\n"
        ".L08148C34: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L08148C38: .4byte 0x030031D0 @ IWRAM+0x31D0\n"
        ".L08148C3C:\n"
        "    ldrh r1, [r3]\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    adds r1, r5, #4\n"
        "    mov r8, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08148C4C\n"
        "    b .L08148DF6\n"
        ".L08148C4C:\n"
        "    ldrh r2, [r2]\n"
        "    movs r0, #0x20\n"
        "    ands r0, r2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    cmp r1, #0\n"
        "    beq .L08148C6C\n"
        "    ldrh r0, [r5, #2]\n"
        "    cmp r0, #0\n"
        "    beq .L08148C66\n"
        "    subs r0, #1\n"
        "    strh r0, [r5, #2]\n"
        "    b .L08148DF6\n"
        ".L08148C66:\n"
        "    movs r0, #3\n"
        "    strh r0, [r5, #2]\n"
        "    b .L08148DF6\n"
        ".L08148C6C:\n"
        "    movs r0, #0x10\n"
        "    ands r0, r2\n"
        "    cmp r0, #0\n"
        "    bne .L08148C76\n"
        "    b .L08148DF6\n"
        ".L08148C76:\n"
        "    ldrh r0, [r5, #2]\n"
        "    cmp r0, #3\n"
        "    beq .L08148C82\n"
        "    adds r0, #1\n"
        "    strh r0, [r5, #2]\n"
        "    b .L08148DF6\n"
        ".L08148C82:\n"
        "    strh r1, [r5, #2]\n"
        "    b .L08148DF6\n"
        ".L08148C86:\n"
        "    movs r0, #2\n"
        "    movs r1, #0xa0\n"
        "    bl sub_081490E4\n"
        "    cmp r0, #0\n"
        "    bne .L08148C94\n"
        "    b .L08148DF6\n"
        ".L08148C94:\n"
        "    ldr r2, .L08148CDC\n"
        "    ldrh r1, [r2]\n"
        "    movs r4, #1\n"
        "    adds r0, r4, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08148D04\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0xfe\n"
        "    ldrh r0, [r0]\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0xfc\n"
        "    lsls r0, r0, #3\n"
        "    ldrh r1, [r1]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #4\n"
        "    adds r3, r5, r0\n"
        "    ldrh r2, [r3]\n"
        "    movs r6, #0x80\n"
        "    lsls r6, r6, #8\n"
        "    adds r0, r6, #0\n"
        "    ands r0, r2\n"
        "    cmp r0, #0\n"
        "    beq .L08148CE4\n"
        "    ldr r0, .L08148CE0\n"
        "    ands r0, r2\n"
        "    strh r0, [r3]\n"
        "    movs r2, #0xc2\n"
        "    lsls r2, r2, #1\n"
        "    adds r1, r5, r2\n"
        "    ldr r0, [r1]\n"
        "    subs r0, #1\n"
        "    str r0, [r1]\n"
        "    b .L08148CFA\n"
        "    .byte 0x00, 0x00\n"
        ".L08148CDC: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L08148CE0: .4byte 0x00007FFF\n"
        ".L08148CE4:\n"
        "    movs r0, #0xc2\n"
        "    lsls r0, r0, #1\n"
        "    adds r4, r5, r0\n"
        "    ldr r1, [r4]\n"
        "    cmp r1, #0x10\n"
        "    beq .L08148CFA\n"
        "    adds r0, r6, #0\n"
        "    orrs r0, r2\n"
        "    strh r0, [r3]\n"
        "    adds r0, r1, #1\n"
        "    str r0, [r4]\n"
        ".L08148CFA:\n"
        "    movs r0, #0xb2\n"
        "    lsls r0, r0, #1\n"
        "    bl Sound_Play\n"
        "    b .L08148DF6\n"
        ".L08148D04:\n"
        "    ldrh r1, [r2]\n"
        "    movs r3, #2\n"
        "    adds r0, r3, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08148D16\n"
        "    strh r3, [r5]\n"
        "    strh r4, [r5, #2]\n"
        "    b .L08148DF6\n"
        ".L08148D16:\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08148D38\n"
        "    bl Keno_CanStart\n"
        "    cmp r0, #1\n"
        "    bne .L08148D38\n"
        "    movs r0, #0xac\n"
        "    lsls r0, r0, #1\n"
        "    bl Sound_Play\n"
        "    bl Keno_StartRound\n"
        "    b .L08148DF6\n"
        ".L08148D38:\n"
        "    ldr r0, .L08148D58\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #2\n"
        "    ands r0, r1\n"
        "    movs r1, #0x84\n"
        "    adds r1, r1, r5\n"
        "    mov sb, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08148D5C\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #0\n"
        "    bne .L08148D5C\n"
        "    bl sub_08149640\n"
        "    b .L08148DC8\n"
        ".L08148D58: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L08148D5C:\n"
        "    ldr r0, .L08148D7C\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x40\n"
        "    ands r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #0\n"
        "    beq .L08148D8A\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0xfe\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #0\n"
        "    beq .L08148D80\n"
        "    subs r0, #1\n"
        "    b .L08148DD0\n"
        "    .byte 0x00, 0x00\n"
        ".L08148D7C: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L08148D80:\n"
        "    movs r0, #7\n"
        "    strh r0, [r1]\n"
        "    adds r6, r5, #4\n"
        "    mov r8, r6\n"
        "    b .L08148DF6\n"
        ".L08148D8A:\n"
        "    movs r0, #0x80\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08148DAE\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0xfe\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #7\n"
        "    beq .L08148DA6\n"
        "    adds r0, #1\n"
        "    strh r0, [r1]\n"
        "    adds r0, r5, #4\n"
        "    mov r8, r0\n"
        "    b .L08148DF6\n"
        ".L08148DA6:\n"
        "    strh r2, [r1]\n"
        "    adds r1, r5, #4\n"
        "    mov r8, r1\n"
        "    b .L08148DF6\n"
        ".L08148DAE:\n"
        "    movs r0, #0x20\n"
        "    ands r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #0\n"
        "    beq .L08148DD8\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0xfc\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #0\n"
        "    beq .L08148DCE\n"
        "    subs r0, #1\n"
        "    strh r0, [r1]\n"
        ".L08148DC8:\n"
        "    adds r2, r5, #4\n"
        "    mov r8, r2\n"
        "    b .L08148DF6\n"
        ".L08148DCE:\n"
        "    movs r0, #7\n"
        ".L08148DD0:\n"
        "    strh r0, [r1]\n"
        "    adds r3, r5, #4\n"
        "    mov r8, r3\n"
        "    b .L08148DF6\n"
        ".L08148DD8:\n"
        "    movs r0, #0x10\n"
        "    ands r0, r1\n"
        "    adds r6, r5, #4\n"
        "    mov r8, r6\n"
        "    cmp r0, #0\n"
        "    beq .L08148DF6\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0xfc\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #7\n"
        "    beq .L08148DF4\n"
        "    adds r0, #1\n"
        "    strh r0, [r1]\n"
        "    b .L08148DF6\n"
        ".L08148DF4:\n"
        "    strh r2, [r1]\n"
        ".L08148DF6:\n"
        "    movs r0, #8\n"
        "    str r0, [sp, #0xc]\n"
        "    movs r1, #0x27\n"
        "    str r1, [sp, #0x10]\n"
        "    movs r4, #0\n"
        "    ldr r2, .L08148E70\n"
        "    mov sl, r2\n"
        ".L08148E04:\n"
        "    movs r1, #7\n"
        "    ands r1, r4\n"
        "    lsls r0, r1, #4\n"
        "    subs r0, r0, r1\n"
        "    ldr r3, [sp, #0xc]\n"
        "    adds r0, r3, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    mov ip, r7\n"
        "    lsrs r1, r4, #3\n"
        "    movs r0, #0xb\n"
        "    muls r0, r1, r0\n"
        "    ldr r6, [sp, #0x10]\n"
        "    adds r0, r6, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r4, #0x1f\n"
        "    bls .L08148E30\n"
        "    adds r0, r2, #0\n"
        "    adds r0, #0x1b\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        ".L08148E30:\n"
        "    lsls r1, r4, #1\n"
        "    movs r3, #0x81\n"
        "    lsls r3, r3, #1\n"
        "    adds r0, r5, r3\n"
        "    adds r0, r0, r1\n"
        "    ldrh r3, [r0]\n"
        "    cmp r3, #0\n"
        "    beq .L08148E86\n"
        "    mov r6, r8\n"
        "    adds r0, r6, r1\n"
        "    ldrh r0, [r0]\n"
        "    movs r3, #0x80\n"
        "    lsls r3, r3, #8\n"
        "    adds r1, r3, #0\n"
        "    ands r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    cmp r1, #0\n"
        "    beq .L08148E74\n"
        "    lsls r0, r4, #2\n"
        "    add r0, sl\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    str r7, [sp, #4]\n"
        "    str r2, [sp, #8]\n"
        "    movs r1, #1\n"
        "    movs r2, #9\n"
        "    movs r3, #0\n"
        "    bl Sprite_DrawBlended\n"
        "    b .L08148EFA\n"
        ".L08148E70: .4byte gUnknown_0879CD14\n"
        ".L08148E74:\n"
        "    lsls r0, r4, #2\n"
        "    add r0, sl\n"
        "    ldr r0, [r0]\n"
        "    str r1, [sp]\n"
        "    str r7, [sp, #4]\n"
        "    str r2, [sp, #8]\n"
        "    movs r1, #1\n"
        "    movs r2, #9\n"
        "    b .L08148EBE\n"
        ".L08148E86:\n"
        "    mov r6, r8\n"
        "    adds r0, r6, r1\n"
        "    ldrh r1, [r0]\n"
        "    movs r6, #0x80\n"
        "    lsls r6, r6, #8\n"
        "    adds r0, r6, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L08148ECC\n"
        "    subs r6, #1\n"
        "    adds r0, r6, #0\n"
        "    ands r0, r1\n"
        "    movs r6, #5\n"
        "    cmp r0, #0\n"
        "    beq .L08148EAE\n"
        "    subs r0, #1\n"
        "    lsls r0, r0, #1\n"
        "    ldr r1, .L08148EC8\n"
        "    adds r0, r0, r1\n"
        "    ldrh r6, [r0]\n"
        ".L08148EAE:\n"
        "    lsls r0, r4, #2\n"
        "    add r0, sl\n"
        "    ldr r0, [r0]\n"
        "    str r3, [sp]\n"
        "    str r7, [sp, #4]\n"
        "    str r2, [sp, #8]\n"
        "    movs r1, #1\n"
        "    adds r2, r6, #0\n"
        ".L08148EBE:\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    b .L08148EFA\n"
        "    .byte 0x00, 0x00\n"
        ".L08148EC8: .4byte gUnknown_0879DDC4\n"
        ".L08148ECC:\n"
        "    ldr r6, .L08148FDC\n"
        "    adds r0, r6, #0\n"
        "    ands r0, r1\n"
        "    movs r6, #0xb\n"
        "    cmp r0, #0\n"
        "    beq .L08148EE2\n"
        "    subs r0, #1\n"
        "    lsls r0, r0, #1\n"
        "    ldr r1, .L08148FE0\n"
        "    adds r0, r0, r1\n"
        "    ldrh r6, [r0]\n"
        ".L08148EE2:\n"
        "    lsls r0, r4, #2\n"
        "    add r0, sl\n"
        "    ldr r0, [r0]\n"
        "    str r3, [sp]\n"
        "    mov r3, ip\n"
        "    str r3, [sp, #4]\n"
        "    str r2, [sp, #8]\n"
        "    movs r1, #1\n"
        "    adds r2, r6, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_DrawBlended\n"
        ".L08148EFA:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #0x3f\n"
        "    bhi .L08148F06\n"
        "    b .L08148E04\n"
        ".L08148F06:\n"
        "    bl sub_08148618\n"
        "    movs r6, #0xc2\n"
        "    lsls r6, r6, #1\n"
        "    adds r0, r5, r6\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #2\n"
        "    movs r2, #0xf\n"
        "    movs r3, #0x5e\n"
        "    bl Keno_DrawDigits\n"
        "    movs r1, #0xc4\n"
        "    lsls r1, r1, #1\n"
        "    adds r0, r5, r1\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #2\n"
        "    movs r2, #0x3d\n"
        "    movs r3, #0x5e\n"
        "    bl Keno_DrawDigits\n"
        "    movs r2, #0xc6\n"
        "    lsls r2, r2, #1\n"
        "    adds r0, r5, r2\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #2\n"
        "    movs r2, #0x6a\n"
        "    movs r3, #0x5e\n"
        "    bl Keno_DrawDigits\n"
        "    movs r3, #0xc8\n"
        "    lsls r3, r3, #1\n"
        "    adds r0, r5, r3\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #3\n"
        "    movs r2, #0x93\n"
        "    movs r3, #0x1c\n"
        "    bl Keno_DrawDigits\n"
        "    adds r6, #0x10\n"
        "    adds r0, r5, r6\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #6\n"
        "    movs r2, #0xba\n"
        "    movs r3, #0x1c\n"
        "    bl Keno_DrawDigits\n"
        "    ldrh r1, [r5, #2]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #8\n"
        "    ands r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #0\n"
        "    bne .L08148FA0\n"
        "    ldrh r1, [r5, #2]\n"
        "    lsls r0, r1, #4\n"
        "    subs r0, r0, r1\n"
        "    lsls r0, r0, #0x11\n"
        "    movs r3, #0x90\n"
        "    lsls r3, r3, #0xc\n"
        "    adds r0, r0, r3\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0xc]\n"
        "    movs r6, #0x1b\n"
        "    ldr r0, .L08148FE4\n"
        "    lsls r1, r1, #2\n"
        "    adds r1, r1, r0\n"
        "    ldr r0, [r1]\n"
        "    str r2, [sp]\n"
        "    ldr r1, [sp, #0xc]\n"
        "    str r1, [sp, #4]\n"
        "    str r6, [sp, #8]\n"
        "    movs r1, #1\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L08148FA0:\n"
        "    bl Keno_DrawPayTable\n"
        "    mov r2, sb\n"
        "    ldrh r0, [r2]\n"
        "    cmp r0, #1\n"
        "    beq .L08148FF8\n"
        "    movs r0, #2\n"
        "    movs r1, #8\n"
        "    movs r2, #6\n"
        "    bl sub_0814869C\n"
        "    ldrh r0, [r5]\n"
        "    cmp r0, #4\n"
        "    bne .L08148FF8\n"
        "    ldr r0, .L08148FE8\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #7\n"
        "    bl __udivsi3\n"
        "    movs r1, #1\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    bne .L08148FEC\n"
        "    movs r0, #2\n"
        "    movs r1, #1\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl sub_08148718\n"
        "    b .L08148FF8\n"
        ".L08148FDC: .4byte 0x00007FFF\n"
        ".L08148FE0: .4byte gUnknown_0879DDC4\n"
        ".L08148FE4: .4byte gUnknown_0879CE14\n"
        ".L08148FE8: .4byte 0x030031BC @ IWRAM+0x31BC\n"
        ".L08148FEC:\n"
        "    movs r0, #2\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl sub_08148718\n"
        ".L08148FF8:\n"
        "    ldr r0, .L08149020\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #3\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L08149048\n"
        "    movs r3, #0xc8\n"
        "    lsls r3, r3, #1\n"
        "    adds r0, r5, r3\n"
        "    ldr r3, [r0]\n"
        "    cmp r3, #0\n"
        "    beq .L08149030\n"
        "    mov r6, sb\n"
        "    ldrh r0, [r6]\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #0\n"
        "    bne .L08149024\n"
        "    movs r0, #4\n"
        "    strh r0, [r6]\n"
        "    b .L08149048\n"
        ".L08149020: .4byte 0x030031BC @ IWRAM+0x31BC\n"
        ".L08149024:\n"
        "    cmp r1, #1\n"
        "    beq .L08149048\n"
        "    subs r0, #1\n"
        "    mov r1, sb\n"
        "    strh r0, [r1]\n"
        "    b .L08149048\n"
        ".L08149030:\n"
        "    mov r2, sb\n"
        "    ldrh r0, [r2]\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #0\n"
        "    beq .L08149048\n"
        "    cmp r1, #4\n"
        "    beq .L08149044\n"
        "    adds r0, #1\n"
        "    strh r0, [r2]\n"
        "    b .L08149048\n"
        ".L08149044:\n"
        "    mov r2, sb\n"
        "    strh r3, [r2]\n"
        ".L08149048:\n"
        "    movs r0, #0\n"
        "    movs r1, #7\n"
        "    movs r2, #4\n"
        "    bl sub_0814869C\n"
        "    movs r0, #3\n"
        "    movs r1, #0xba\n"
        "    movs r2, #6\n"
        "    bl sub_0814869C\n"
        "    bl Keno_CanStart\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #1\n"
        "    bne .L0814908A\n"
        "    ldr r0, .L08149078\n"
        "    ldr r0, [r0]\n"
        "    lsrs r0, r0, #4\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L0814907C\n"
        "    movs r0, #3\n"
        "    movs r1, #1\n"
        "    b .L08149080\n"
        ".L08149078: .4byte 0x030031BC @ IWRAM+0x31BC\n"
        ".L0814907C:\n"
        "    movs r0, #3\n"
        "    movs r1, #0\n"
        ".L08149080:\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl sub_08148718\n"
        "    b .L08149096\n"
        ".L0814908A:\n"
        "    movs r0, #3\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl sub_08148718\n"
        ".L08149096:\n"
        "    movs r0, #1\n"
        "    movs r1, #0xbb\n"
        "    movs r2, #4\n"
        "    bl sub_0814869C\n"
        "    ldrh r0, [r5]\n"
        "    cmp r0, #5\n"
        "    beq .L081490D4\n"
        "    movs r0, #4\n"
        "    movs r1, #0xbb\n"
        "    movs r2, #4\n"
        "    bl sub_0814869C\n"
        "    ldr r0, .L081490CC\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #3\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L081490D4\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x8c\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #6\n"
        "    beq .L081490D0\n"
        "    adds r0, #1\n"
        "    b .L081490D2\n"
        "    .byte 0x00, 0x00\n"
        ".L081490CC: .4byte 0x030031BC @ IWRAM+0x31BC\n"
        ".L081490D0:\n"
        "    movs r0, #1\n"
        ".L081490D2:\n"
        "    strh r0, [r1]\n"
        ".L081490D4:\n"
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
