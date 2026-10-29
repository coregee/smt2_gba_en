/* Lucky Symbol: line check, bonus symbols, bonus effects and hold markers
   (0x081437E4-0x08144017). */

#include "global.h"
#include "casino.h"

/* Middle row: four of a kind pays row 1 of the pattern's pay entry, three of a kind
   (reels 0-1-2, 0-1-3, 0-2-3 or 1-2-3) row 0; the bonus symbols 8-10 never form a line. */
// LuckySymbol_CheckLine @ 0x081437E4
#ifdef NONMATCHING
void LuckySymbol_CheckLine(void)
{
    struct CasinoScene *scene = (struct CasinoScene *)0x0203B554;
    struct LuckySymbol *s = (struct LuckySymbol *)gMenuState;

    s->lineSym[0] = gUnknown_0879505C[scene->arg][s->sym[0][1]].sym;
    s->lineSym[1] = gUnknown_08795DDC[scene->arg][s->sym[1][1]].sym;
    s->lineSym[2] = gUnknown_08796B5C[scene->arg][s->sym[2][1]].sym;
    s->lineSym[3] = gUnknown_087978DC[scene->arg][s->sym[3][1]].sym;
    if (s->lineSym[0] == s->lineSym[1] && s->lineSym[0] == s->lineSym[2] && s->lineSym[0] == s->lineSym[3])
    {
        if (s->lineSym[0] >= 8 && s->lineSym[0] <= 10)
            goto special;
        s->lines[0].index = s->sym[0][1];
        s->lines[1].index = s->sym[1][1];
        s->lines[2].index = s->sym[2][1];
        s->line3Index = s->sym[3][1];
        s->lines[0].layer = 0;
        s->lines[1].layer = 0;
        s->lines[2].layer = 0;
        s->line3Layer = 0;
        s->pattern = s->lineSym[0];
        LuckySymbol_SetPayout(1);
        LuckySymbol_BlinkWinLine();
    }
    else if (s->lineSym[0] == s->lineSym[1] && s->lineSym[0] == s->lineSym[2])
    {
        if (s->lineSym[0] >= 8 && s->lineSym[0] <= 10)
            goto special;
        s->lines[0].index = s->sym[0][1];
        s->lines[1].index = s->sym[1][1];
        s->lines[2].index = s->sym[2][1];
        s->lines[0].layer = 0;
        s->lines[1].layer = 0;
        s->lines[2].layer = 0;
        s->line3Layer = 2;
        s->pattern = s->lineSym[0];
        LuckySymbol_SetPayout(0);
        LuckySymbol_BlinkWinLine();
    }
    else if (s->lineSym[0] == s->lineSym[1] && s->lineSym[0] == s->lineSym[3])
    {
        if (s->lineSym[0] >= 8 && s->lineSym[0] <= 10)
            goto special;
        s->lines[0].index = s->sym[0][1];
        s->lines[1].index = s->sym[1][1];
        s->line3Index = s->sym[3][1];
        s->lines[0].layer = 0;
        s->lines[1].layer = 0;
        s->line3Layer = 0;
        s->lines[2].layer = 2;
        s->pattern = s->lineSym[0];
        LuckySymbol_SetPayout(0);
        LuckySymbol_BlinkWinLine();
    }
    else if (s->lineSym[0] == s->lineSym[2] && s->lineSym[2] == s->lineSym[3])
    {
        if (s->lineSym[2] >= 8 && s->lineSym[2] <= 10)
            goto special;
        s->lines[0].index = s->sym[0][1];
        s->lines[2].index = s->sym[2][1];
        s->line3Index = s->sym[3][1];
        s->lines[0].layer = 0;
        s->lines[2].layer = 0;
        s->line3Layer = 0;
        s->lines[1].layer = 2;
        s->pattern = s->lineSym[0];
        LuckySymbol_SetPayout(0);
        LuckySymbol_BlinkWinLine();
    }
    else if (s->lineSym[1] == s->lineSym[2] && s->lineSym[1] == s->lineSym[3])
    {
        if (s->lineSym[1] >= 8 && s->lineSym[1] <= 10)
            goto special;
        s->lines[1].index = s->sym[1][1];
        s->lines[2].index = s->sym[2][1];
        s->line3Index = s->sym[3][1];
        s->lines[1].layer = 0;
        s->lines[2].layer = 0;
        s->line3Layer = 0;
        s->lines[0].layer = 2;
        s->pattern = s->lineSym[1];
        LuckySymbol_SetPayout(0);
        LuckySymbol_BlinkWinLine();
    }
    else
        goto none;
    return;
special:
    s->mode = 3;
    return;
none:
    s->mode = 3;
}
#else
NAKED
void LuckySymbol_CheckLine(void)
{
    asm_unified(
        ".L081437E4:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    ldr r3, .L081438D0\n"
        "    ldr r0, .L081438D4\n"
        "    mov ip, r0\n"
        "    ldr r4, .L081438D8\n"
        "    ldr r1, .L081438DC\n"
        "    ldrh r0, [r1]\n"
        "    lsls r1, r0, #1\n"
        "    adds r1, r1, r0\n"
        "    lsls r1, r1, #2\n"
        "    ldrh r2, [r3, #2]\n"
        "    lsls r0, r2, #3\n"
        "    adds r0, r0, r2\n"
        "    lsls r0, r0, #5\n"
        "    adds r1, r1, r0\n"
        "    adds r1, r1, r4\n"
        "    ldr r6, [r1]\n"
        "    mov r2, ip\n"
        "    str r6, [r2, #0x18]\n"
        "    ldr r4, .L081438E0\n"
        "    movs r0, #0x76\n"
        "    add r0, ip\n"
        "    mov sl, r0\n"
        "    ldrh r0, [r0]\n"
        "    lsls r1, r0, #1\n"
        "    adds r1, r1, r0\n"
        "    lsls r1, r1, #2\n"
        "    ldrh r2, [r3, #2]\n"
        "    lsls r0, r2, #3\n"
        "    adds r0, r0, r2\n"
        "    lsls r0, r0, #5\n"
        "    adds r1, r1, r0\n"
        "    adds r1, r1, r4\n"
        "    ldr r5, [r1]\n"
        "    mov r1, ip\n"
        "    str r5, [r1, #0x1c]\n"
        "    ldr r4, .L081438E4\n"
        "    movs r2, #0x82\n"
        "    add r2, ip\n"
        "    mov sb, r2\n"
        "    ldrh r0, [r2]\n"
        "    lsls r1, r0, #1\n"
        "    adds r1, r1, r0\n"
        "    lsls r1, r1, #2\n"
        "    ldrh r2, [r3, #2]\n"
        "    lsls r0, r2, #3\n"
        "    adds r0, r0, r2\n"
        "    lsls r0, r0, #5\n"
        "    adds r1, r1, r0\n"
        "    adds r1, r1, r4\n"
        "    ldr r7, [r1]\n"
        "    mov r0, ip\n"
        "    str r7, [r0, #0x20]\n"
        "    ldr r4, .L081438E8\n"
        "    movs r1, #0x8e\n"
        "    add r1, ip\n"
        "    mov r8, r1\n"
        "    ldrh r0, [r1]\n"
        "    lsls r1, r0, #1\n"
        "    adds r1, r1, r0\n"
        "    lsls r1, r1, #2\n"
        "    ldrh r2, [r3, #2]\n"
        "    lsls r0, r2, #3\n"
        "    adds r0, r0, r2\n"
        "    lsls r0, r0, #5\n"
        "    adds r1, r1, r0\n"
        "    adds r1, r1, r4\n"
        "    ldr r1, [r1]\n"
        "    mov r2, ip\n"
        "    str r1, [r2, #0x24]\n"
        "    cmp r6, r5\n"
        "    beq .L0814387E\n"
        "    b .L08143992\n"
        ".L0814387E:\n"
        "    cmp r6, r7\n"
        "    bne .L081438EC\n"
        "    cmp r6, r1\n"
        "    bne .L081438EC\n"
        "    adds r0, r6, #0\n"
        "    subs r0, #8\n"
        "    cmp r0, #2\n"
        "    bhi .L08143890\n"
        "    b .L08143A4C\n"
        ".L08143890:\n"
        "    mov r1, ip\n"
        "    adds r1, #0xb0\n"
        "    ldr r2, .L081438DC\n"
        "    ldrh r0, [r2]\n"
        "    str r0, [r1]\n"
        "    adds r1, #0xc\n"
        "    mov r2, sl\n"
        "    ldrh r0, [r2]\n"
        "    str r0, [r1]\n"
        "    adds r1, #0xc\n"
        "    mov r2, sb\n"
        "    ldrh r0, [r2]\n"
        "    str r0, [r1]\n"
        "    adds r1, #0xc\n"
        "    mov r2, r8\n"
        "    ldrh r0, [r2]\n"
        "    str r0, [r1]\n"
        "    mov r0, ip\n"
        "    adds r0, #0xb4\n"
        "    movs r1, #0\n"
        "    strb r1, [r0]\n"
        "    adds r0, #0xc\n"
        "    strb r1, [r0]\n"
        "    adds r0, #0xc\n"
        "    strb r1, [r0]\n"
        "    adds r0, #0xc\n"
        "    strb r1, [r0]\n"
        "    adds r0, #4\n"
        "    str r6, [r0]\n"
        "    movs r0, #1\n"
        "    b .L08143A42\n"
        "    .byte 0x00, 0x00\n"
        ".L081438D0: .4byte 0x0203B554 @ EWRAM+0x3B554\n"
        ".L081438D4: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L081438D8: .4byte gUnknown_0879505C\n"
        ".L081438DC: .4byte 0x0203A4BE @ EWRAM+0x3A4BE\n"
        ".L081438E0: .4byte gUnknown_08795DDC\n"
        ".L081438E4: .4byte gUnknown_08796B5C\n"
        ".L081438E8: .4byte gUnknown_087978DC\n"
        ".L081438EC:\n"
        "    mov r2, ip\n"
        "    ldr r1, [r2, #0x18]\n"
        "    ldr r0, [r2, #0x1c]\n"
        "    cmp r1, r0\n"
        "    bne .L08143992\n"
        "    ldr r0, [r2, #0x20]\n"
        "    cmp r1, r0\n"
        "    bne .L08143944\n"
        "    adds r0, r1, #0\n"
        "    subs r0, #8\n"
        "    cmp r0, #2\n"
        "    bhi .L08143906\n"
        "    b .L08143A4C\n"
        ".L08143906:\n"
        "    mov r1, ip\n"
        "    adds r1, #0xb0\n"
        "    mov r0, ip\n"
        "    adds r0, #0x6a\n"
        "    ldrh r0, [r0]\n"
        "    str r0, [r1]\n"
        "    adds r1, #0xc\n"
        "    mov r0, ip\n"
        "    adds r0, #0x76\n"
        "    ldrh r0, [r0]\n"
        "    str r0, [r1]\n"
        "    adds r1, #0xc\n"
        "    mov r0, ip\n"
        "    adds r0, #0x82\n"
        "    ldrh r0, [r0]\n"
        "    str r0, [r1]\n"
        "    mov r0, ip\n"
        "    adds r0, #0xb4\n"
        "    movs r1, #0\n"
        "    strb r1, [r0]\n"
        "    adds r0, #0xc\n"
        "    strb r1, [r0]\n"
        "    adds r0, #0xc\n"
        "    strb r1, [r0]\n"
        "    mov r1, ip\n"
        "    adds r1, #0xd8\n"
        "    movs r0, #2\n"
        "    strb r0, [r1]\n"
        "    adds r1, #4\n"
        "    ldr r0, [r2, #0x18]\n"
        "    b .L08143A3E\n"
        ".L08143944:\n"
        "    mov r2, ip\n"
        "    ldr r0, [r2, #0x24]\n"
        "    cmp r1, r0\n"
        "    bne .L08143992\n"
        "    adds r0, r1, #0\n"
        "    subs r0, #8\n"
        "    cmp r0, #2\n"
        "    bls .L08143A4C\n"
        "    mov r1, ip\n"
        "    adds r1, #0xb0\n"
        "    mov r0, ip\n"
        "    adds r0, #0x6a\n"
        "    ldrh r0, [r0]\n"
        "    str r0, [r1]\n"
        "    adds r1, #0xc\n"
        "    mov r0, ip\n"
        "    adds r0, #0x76\n"
        "    ldrh r0, [r0]\n"
        "    str r0, [r1]\n"
        "    adds r1, #0x18\n"
        "    mov r0, ip\n"
        "    adds r0, #0x8e\n"
        "    ldrh r0, [r0]\n"
        "    str r0, [r1]\n"
        "    mov r0, ip\n"
        "    adds r0, #0xb4\n"
        "    movs r1, #0\n"
        "    strb r1, [r0]\n"
        "    adds r0, #0xc\n"
        "    strb r1, [r0]\n"
        "    adds r0, #0x18\n"
        "    strb r1, [r0]\n"
        "    mov r1, ip\n"
        "    adds r1, #0xcc\n"
        "    movs r0, #2\n"
        "    strb r0, [r1]\n"
        "    adds r1, #0x10\n"
        "    ldr r0, [r2, #0x18]\n"
        "    b .L08143A3E\n"
        ".L08143992:\n"
        "    mov r2, ip\n"
        "    ldr r0, [r2, #0x18]\n"
        "    ldr r2, [r2, #0x20]\n"
        "    cmp r0, r2\n"
        "    bne .L081439EA\n"
        "    mov r1, ip\n"
        "    ldr r0, [r1, #0x24]\n"
        "    cmp r2, r0\n"
        "    bne .L081439EA\n"
        "    adds r0, r2, #0\n"
        "    subs r0, #8\n"
        "    cmp r0, #2\n"
        "    bls .L08143A4C\n"
        "    adds r1, #0xb0\n"
        "    mov r0, ip\n"
        "    adds r0, #0x6a\n"
        "    ldrh r0, [r0]\n"
        "    str r0, [r1]\n"
        "    adds r1, #0x18\n"
        "    mov r0, ip\n"
        "    adds r0, #0x82\n"
        "    ldrh r0, [r0]\n"
        "    str r0, [r1]\n"
        "    adds r1, #0xc\n"
        "    mov r0, ip\n"
        "    adds r0, #0x8e\n"
        "    ldrh r0, [r0]\n"
        "    str r0, [r1]\n"
        "    mov r0, ip\n"
        "    adds r0, #0xb4\n"
        "    movs r1, #0\n"
        "    strb r1, [r0]\n"
        "    adds r0, #0x18\n"
        "    strb r1, [r0]\n"
        "    adds r0, #0xc\n"
        "    strb r1, [r0]\n"
        "    mov r1, ip\n"
        "    adds r1, #0xc0\n"
        "    movs r0, #2\n"
        "    strb r0, [r1]\n"
        "    adds r1, #0x1c\n"
        "    mov r2, ip\n"
        "    ldr r0, [r2, #0x18]\n"
        "    b .L08143A3E\n"
        ".L081439EA:\n"
        "    mov r0, ip\n"
        "    ldr r1, [r0, #0x1c]\n"
        "    cmp r1, r2\n"
        "    bne .L08143A54\n"
        "    ldr r0, [r0, #0x24]\n"
        "    cmp r1, r0\n"
        "    bne .L08143A54\n"
        "    adds r0, r1, #0\n"
        "    subs r0, #8\n"
        "    cmp r0, #2\n"
        "    bls .L08143A4C\n"
        "    mov r1, ip\n"
        "    adds r1, #0xbc\n"
        "    mov r0, ip\n"
        "    adds r0, #0x76\n"
        "    ldrh r0, [r0]\n"
        "    str r0, [r1]\n"
        "    adds r1, #0xc\n"
        "    mov r0, ip\n"
        "    adds r0, #0x82\n"
        "    ldrh r0, [r0]\n"
        "    str r0, [r1]\n"
        "    adds r1, #0xc\n"
        "    mov r0, ip\n"
        "    adds r0, #0x8e\n"
        "    ldrh r0, [r0]\n"
        "    str r0, [r1]\n"
        "    mov r0, ip\n"
        "    adds r0, #0xc0\n"
        "    movs r1, #0\n"
        "    strb r1, [r0]\n"
        "    adds r0, #0xc\n"
        "    strb r1, [r0]\n"
        "    adds r0, #0xc\n"
        "    strb r1, [r0]\n"
        "    mov r1, ip\n"
        "    adds r1, #0xb4\n"
        "    movs r0, #2\n"
        "    strb r0, [r1]\n"
        "    adds r1, #0x28\n"
        "    mov r2, ip\n"
        "    ldr r0, [r2, #0x1c]\n"
        ".L08143A3E:\n"
        "    str r0, [r1]\n"
        "    movs r0, #0\n"
        ".L08143A42:\n"
        "    bl LuckySymbol_SetPayout\n"
        "    bl LuckySymbol_BlinkWinLine\n"
        "    b .L08143A5A\n"
        ".L08143A4C:\n"
        "    movs r0, #3\n"
        "    mov r1, ip\n"
        "    strb r0, [r1, #4]\n"
        "    b .L08143A5A\n"
        ".L08143A54:\n"
        "    movs r0, #3\n"
        "    mov r2, ip\n"
        "    strb r0, [r2, #4]\n"
        ".L08143A5A:\n"
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

/* Counts the bonus symbols in the three visible rows: symbol 8 scores 1, 9 scores 2,
   10 scores 3. */
// LuckySymbol_CountBonusSymbols @ 0x08143A68
void LuckySymbol_CountBonusSymbols(void)
{
    struct CasinoScene *scene = (struct CasinoScene *)0x0203B554;
    struct LuckySymbol *s = (struct LuckySymbol *)gMenuState;
    u16 i;

    s->unk2F = 1;
    for (i = 0; i < 3; i++)
    {
        switch ((u32)gUnknown_0879505C[scene->arg][s->sym[0][i]].sym)
        {
        case 8:
            s->bonus += 1;
            break;
        case 9:
            s->bonus += 2;
            break;
        case 10:
            s->bonus += 3;
            break;
        }
        switch ((u32)gUnknown_08795DDC[scene->arg][s->sym[1][i]].sym)
        {
        case 8:
            s->bonus += 1;
            break;
        case 9:
            s->bonus += 2;
            break;
        case 10:
            s->bonus += 3;
            break;
        }
        switch ((u32)gUnknown_08796B5C[scene->arg][s->sym[2][i]].sym)
        {
        case 8:
            s->bonus += 1;
            break;
        case 9:
            s->bonus += 2;
            break;
        case 10:
            s->bonus += 3;
            break;
        }
        switch ((u32)gUnknown_087978DC[scene->arg][s->sym[3][i]].sym)
        {
        case 8:
            s->bonus += 1;
            break;
        case 9:
            s->bonus += 2;
            break;
        case 10:
            s->bonus += 3;
            break;
        }
    }
    for (i = 0; i < 13; i++)
        s->marks[i] = 0;
    s->marksLeft = s->bonus;
}

/* Lights the bonus meter one mark every eight frames up to the bonus score. */
// LuckySymbol_DrawBonusMeter @ 0x08143BF8
void LuckySymbol_DrawBonusMeter(void)
{
    struct LuckySymbol *s = (struct LuckySymbol *)gMenuState;
    u16 i;

    if (s->marksDone == 0)
    {
        if (s->markTimer > 7)
        {
            s->marks[s->markIdx] = 1;
            s->markTimer = 0;
            s->markIdx++;
            if (s->marksLeft != 0)
            {
                Sound_Play(0x16B);
                s->marksLeft--;
            }
            else
            {
                Sound_Play(0x16B);
                s->markIdx = 0;
                s->marksDone = 1;
            }
        }
        s->markTimer++;
    }
    for (i = 0; i < 13; i++)
    {
        if (s->marks[i] == 1)
            Sprite_Draw(gUnknown_087986E4[i].sprite, 0, 0, 0, 0, gUnknown_087986E4[i].x, gUnknown_087986E4[i].y & 0xFF);
    }
}

/* Bonus score effects: 3 raises the bet multiplier step by step (2-5), 4-5 enable holds,
   6 lights the extra lamp, 7-8 start the bonus game, 9-12 pay 5/10/20/100 coins. */
// LuckySymbol_ApplyBonus @ 0x08143CB8
void LuckySymbol_ApplyBonus(void)
{
    struct LuckySymbol *s = (struct LuckySymbol *)gMenuState;

    switch (s->bonus)
    {
    case 0:
    case 1:
    case 2:
        break;
    case 3:
        if (s->bet == 2)
        {
            if (s->count <= 3)
            {
                if (s->blink > 7)
                    Sprite_Draw(gUnknown_0814F314, 0, 0, 0, 0, 0xA0, 0x6C);
                if (s->blink > 10)
                {
                    s->blink = 0;
                    s->count++;
                }
                s->blink++;
                return;
            }
            s->count = 0;
            s->bet = 3;
        }
        else if (s->bet == 3)
        {
            if (s->count <= 3)
            {
                if (s->blink > 7)
                    Sprite_Draw(gUnknown_0814F344, 0, 0, 0, 0, 0xA0, 0x6C);
                if (s->blink > 10)
                {
                    s->blink = 0;
                    s->count++;
                }
                s->blink++;
                return;
            }
            s->count = 0;
            s->bet = 4;
        }
        else if (s->unk38 == 0 && s->bet == 4)
        {
            if (s->count <= 3)
            {
                if (s->blink > 7)
                    Sprite_Draw(gUnknown_0814F374, 0, 0, 0, 0, 0xA0, 0x6C);
                if (s->blink > 10)
                {
                    s->blink = 0;
                    s->count++;
                }
                s->blink++;
                return;
            }
            s->count = 0;
            s->bet = 5;
            s->unk38 = 1;
            s->unk31 = 1;
            return;
        }
        break;
    case 4:
    case 5:
        s->holdEnabled = 1;
        s->unk31 = 1;
        return;
    case 6:
        if (s->unk32 == 0)
        {
            if (s->count <= 3)
            {
                if (s->blink > 7)
                    Sprite_Draw(gUnknown_0814F29C, 0, 0, 0, 0, 0xB0, 0x2B);
                if (s->blink > 10)
                {
                    s->blink = 0;
                    s->count++;
                }
                s->blink++;
                return;
            }
            s->count = 0;
            s->unk32 = 1;
            s->unk31 = 1;
            return;
        }
        break;
    case 7:
    case 8:
        if (s->unk56 == 0)
            LuckySymbol_LightLamps();
        LuckySymbol_BlinkNewLamps();
        return;
    case 9:
        s->payout = 5;
        break;
    case 10:
        s->payout = 10;
        break;
    case 11:
        s->payout = 20;
        break;
    case 12:
        s->payout = 100;
        break;
    default:
        return;
    }
    s->unk31 = 1;
}

// LuckySymbol_SetPayout @ 0x08143EA0
void LuckySymbol_SetPayout(u16 four)
{
    struct LuckySymbol *s = (struct LuckySymbol *)gMenuState;

    s->payout = gUnknown_0879865C[s->pattern].pay[four];
}

/* Hold markers under the four reels (solid when held, blinking while holds remain). */
// LuckySymbol_DrawHoldMarkers @ 0x08143ED0
void LuckySymbol_DrawHoldMarkers(void)
{
    struct LuckySymbol *s = (struct LuckySymbol *)gMenuState;

    if (s->held[0] == 1)
        Sprite_Draw(gUnknown_0814F1F4, 0, 0, 0, 0, 0x3A, 0x5B);
    if (s->held[1] == 1)
        Sprite_Draw(gUnknown_0814F204, 0, 0, 0, 0, 0x59, 0x5B);
    if (s->held[2] == 1)
        Sprite_Draw(gUnknown_0814F214, 0, 0, 0, 0, 0x78, 0x5B);
    if (s->held[3] == 1)
        Sprite_Draw(gUnknown_0814F224, 0, 0, 0, 0, 0x97, 0x5B);
    if (s->mode == 0 && s->heldCount <= 2)
    {
        if (s->held[0] == 0 && s->unk2A > 10)
            Sprite_Draw(gUnknown_0814F1F4, 0, 0, 0, 0, 0x3A, 0x5B);
        if (s->held[1] == 0 && s->unk2A > 10)
            Sprite_Draw(gUnknown_0814F204, 0, 0, 0, 0, 0x59, 0x5B);
        if (s->held[2] == 0 && s->unk2A > 10)
            Sprite_Draw(gUnknown_0814F214, 0, 0, 0, 0, 0x78, 0x5B);
        if (s->held[3] == 0 && s->unk2A > 10)
            Sprite_Draw(gUnknown_0814F224, 0, 0, 0, 0, 0x97, 0x5B);
        if (s->unk2A > 20)
            s->unk2A = 0;
        s->unk2A++;
    }
}
