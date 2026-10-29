/* Lucky Symbol (casino game 6): setup, main loop, reels and number display
   (0x08142140-0x08143043). */

#include "global.h"
#include "casino.h"

// LuckySymbol_Init @ 0x08142140
void LuckySymbol_Init(void)
{
    struct LuckySymbol *s = (struct LuckySymbol *)gMenuState;

    CpuFill32(0, s, 0x800);
    REG_BG0CNT = 0x4008;
    gUnk_03000002 = 0;
    gUnk_03000040 = 0;
    s->init = 1;
    s->coins = sub_080C31F0();
    s->bet = 2;
    s->sym[3][0] = 0;
    s->sym[2][0] = 0;
    s->sym[1][0] = 0;
    s->sym[0][0] = 0;
    s->sym[3][1] = 1;
    s->sym[2][1] = 1;
    s->sym[1][1] = 1;
    s->sym[0][1] = 1;
    s->sym[3][2] = 2;
    s->sym[2][2] = 2;
    s->sym[1][2] = 2;
    s->sym[0][2] = 2;
    s->sym[3][3] = 3;
    s->sym[2][3] = 3;
    s->sym[1][3] = 3;
    s->sym[0][3] = 3;
    s->sym[3][4] = 4;
    s->sym[2][4] = 4;
    s->sym[1][4] = 4;
    s->sym[0][4] = 4;
    s->sym[3][5] = 5;
    s->sym[2][5] = 5;
    s->sym[1][5] = 5;
    s->sym[0][5] = 5;
}

// LuckySymbol_Update @ 0x08142200
void LuckySymbol_Update(void)
{
    struct LuckySymbol *s = (struct LuckySymbol *)gMenuState;

    if (s->init == 1)
    {
        Task_Create(gUnknown_0879874C, 0xFFFF);
        s->init = 0;
    }
    LuckySymbol_DrawReels();
    LuckySymbol_DrawNumber(s->win, 0x2F, 0x20, 0);
    LuckySymbol_DrawNumber(s->coins, 0xE5, 0x20, 0);
    Sprite_Draw(gUnknown_0814F508, 0, 0, 0, 0, 0x47, 0x25);
    if (s->unk2F == 1)
        LuckySymbol_DrawBonusMeter();
    if (*(u16 *)&s->unk32 == 1)
        Sprite_Draw(gUnknown_0814F29C, 0, 0, 0, 0, 0xB0, 0x2B);
    if (s->holdEnabled == 1)
        LuckySymbol_DrawHoldMarkers();
    LuckySymbol_DrawLamps();
    switch (s->bet)
    {
    case 2:
        Sprite_Draw(gUnknown_0814F2CC, 0, 0, 0, 0, 0xA0, 0x6C);
        break;
    case 3:
        Sprite_Draw(gUnknown_0814F2FC, 0, 0, 0, 0, 0xA0, 0x6C);
        break;
    case 4:
        Sprite_Draw(gUnknown_0814F32C, 0, 0, 0, 0, 0xA0, 0x6C);
        break;
    case 5:
        Sprite_Draw(gUnknown_0814F35C, 0, 0, 0, 0, 0xA0, 0x6C);
        break;
    }
    if (s->started == 1)
    {
        if ((gKeysNew & 0x100) && s->mode == 0 && s->coins != 0)
        {
            Sound_Play(0x15A);
            s->mode = 1;
            s->marksDone = 0;
            s->unk56 = 0;
            s->unk31 = 0;
            s->count = 0;
            s->bonus = 0;
            s->unk2F = 0;
            s->unk52 = 0;
            s->phase = 0;
            s->unk50 = 1;
            s->coins--;
        }
        if (gKeysNew & 0x200)
        {
            if (s->mode != 0)
                goto run;
            Sound_Play(0x158);
            s->mode = 10;
        }
    }
    if (s->mode == 0 && s->holdEnabled == 1)
    {
        if ((gKeysNew & 0x20) && s->held[0] == 0 && s->heldCount <= 2)
        {
            Sound_Play(0x15C);
            s->held[0] = 1;
            s->heldCount++;
        }
        else if ((gKeysNew & 0x20) && s->held[0] == 1)
        {
            s->held[0] = 0;
            s->heldCount--;
        }
        if ((gKeysNew & 0x40) && s->held[1] == 0 && s->heldCount <= 2)
        {
            Sound_Play(0x15C);
            s->held[1] = 1;
            s->heldCount++;
        }
        else if ((gKeysNew & 0x40) && s->held[1] == 1)
        {
            s->held[1] = 0;
            s->heldCount--;
        }
        if ((gKeysNew & 0x10) && s->held[2] == 0 && s->heldCount <= 2)
        {
            Sound_Play(0x15C);
            s->held[2] = 1;
            s->heldCount++;
        }
        else if ((gKeysNew & 0x10) && s->held[2] == 1)
        {
            s->held[2] = 0;
            s->heldCount--;
        }
        if ((gKeysNew & 0x80) && s->held[3] == 0 && s->heldCount <= 2)
        {
            Sound_Play(0x15C);
            s->held[3] = 1;
            s->heldCount++;
        }
        else if ((gKeysNew & 0x80) && s->held[3] == 1)
        {
            s->held[3] = 0;
            s->heldCount--;
        }
    }
run:
    switch (s->mode)
    {
    case 0:
        if (s->blink > 20)
        {
            Sprite_Draw(gUnknown_0814F1CC, 0, 0, 0, 0, 0xBB, 5);
            if (s->blink > 40)
            {
                s->blink = 0;
                if (s->started == 0)
                    s->started = 1;
            }
        }
        s->blink++;
        break;
    case 1:
        LuckySymbol_UpdateReelStrips();
        LuckySymbol_SpinReels();
        break;
    case 2:
        if (s->unk2F == 0)
            LuckySymbol_CountBonusSymbols();
        if (s->marksDone == 1)
            LuckySymbol_ApplyBonus();
        if (s->unk31 == 1)
            LuckySymbol_CheckLine();
        break;
    case 3:
        if (s->unk50 == 1)
            LuckySymbol_CountWin();
        else
            LuckySymbol_PayWin();
        LuckySymbol_ApplyMultipliers();
        break;
    case 10:
        if (s->count <= 5)
        {
            if (s->blink > 3)
                Sprite_Draw(gUnknown_0814F1E4, 0, 0, 0, 0, 9, 5);
            if (s->blink > 6)
            {
                s->blink = 0;
                s->count++;
            }
            s->blink++;
        }
        else
        {
            sub_080C31FC(s->coins);
            sub_080BE4C4();
        }
        break;
    }
}

/* Reel strips while spinning (see Super27_UpdateReelStrips), four reels. */
// LuckySymbol_UpdateReelStrips @ 0x08142618
void LuckySymbol_UpdateReelStrips(void)
{
    struct LuckySymbol *s = (struct LuckySymbol *)gMenuState;

    if (s->phase != 0)
    {
        if (s->held[0] == 0)
        {
            s->sym[0][0] = s->reelPos[0] / 20;
            s->sym[0][1] = s->reelPos[0] / 20 + 1;
            s->sym[0][2] = s->reelPos[0] / 20 + 2;
            s->sym[0][3] = s->reelPos[0] / 20 + 3;
            s->sym[0][4] = s->reelPos[0] / 20 + 4;
            s->sym[0][5] = s->reelPos[0] / 20 + 5;
        }
        if (s->phase != 0)
        {
            if (s->held[1] == 0)
            {
                s->sym[1][0] = s->reelPos[1] / 20;
                s->sym[1][1] = s->reelPos[1] / 20 + 1;
                s->sym[1][2] = s->reelPos[1] / 20 + 2;
                s->sym[1][3] = s->reelPos[1] / 20 + 3;
                s->sym[1][4] = s->reelPos[1] / 20 + 4;
                s->sym[1][5] = s->reelPos[1] / 20 + 5;
            }
            if (s->held[2] == 0)
            {
                s->sym[2][0] = s->reelPos[2] / 20;
                s->sym[2][1] = s->reelPos[2] / 20 + 1;
                s->sym[2][2] = s->reelPos[2] / 20 + 2;
                s->sym[2][3] = s->reelPos[2] / 20 + 3;
                s->sym[2][4] = s->reelPos[2] / 20 + 4;
                s->sym[2][5] = s->reelPos[2] / 20 + 5;
            }
            if (s->held[3] == 0)
            {
                s->sym[3][0] = s->reelPos[3] / 20;
                s->sym[3][1] = s->reelPos[3] / 20 + 1;
                s->sym[3][2] = s->reelPos[3] / 20 + 2;
                s->sym[3][3] = s->reelPos[3] / 20 + 3;
                s->sym[3][4] = s->reelPos[3] / 20 + 4;
                s->sym[3][5] = s->reelPos[3] / 20 + 5;
            }
        }
    }
    if (s->sym[0][5] == 24)
        s->sym[0][5] = 0;
    if (s->sym[0][4] == 24)
    {
        s->sym[0][4] = 0;
        s->sym[0][5] = 1;
    }
    if (s->sym[0][3] == 24)
    {
        s->sym[0][3] = 0;
        s->sym[0][4] = 1;
        s->sym[0][5] = 2;
    }
    if (s->sym[0][2] == 24)
    {
        s->sym[0][2] = 0;
        s->sym[0][3] = 1;
        s->sym[0][4] = 2;
        s->sym[0][5] = 3;
    }
    if (s->sym[0][1] == 24)
    {
        s->sym[0][1] = 0;
        s->sym[0][2] = 1;
        s->sym[0][3] = 2;
        s->sym[0][4] = 3;
        s->sym[0][5] = 4;
    }
    if (s->sym[1][5] == 24)
        s->sym[1][5] = 0;
    if (s->sym[1][4] == 24)
    {
        s->sym[1][4] = 0;
        s->sym[1][5] = 1;
    }
    if (s->sym[1][3] == 24)
    {
        s->sym[1][3] = 0;
        s->sym[1][4] = 1;
        s->sym[1][5] = 2;
    }
    if (s->sym[1][2] == 24)
    {
        s->sym[1][2] = 0;
        s->sym[1][3] = 1;
        s->sym[1][4] = 2;
        s->sym[1][5] = 3;
    }
    if (s->sym[1][1] == 24)
    {
        s->sym[1][1] = 0;
        s->sym[1][2] = 1;
        s->sym[1][3] = 2;
        s->sym[1][4] = 3;
        s->sym[1][5] = 4;
    }
    if (s->sym[2][5] == 24)
        s->sym[2][5] = 0;
    if (s->sym[2][4] == 24)
    {
        s->sym[2][4] = 0;
        s->sym[2][5] = 1;
    }
    if (s->sym[2][3] == 24)
    {
        s->sym[2][3] = 0;
        s->sym[2][4] = 1;
        s->sym[2][5] = 2;
    }
    if (s->sym[2][2] == 24)
    {
        s->sym[2][2] = 0;
        s->sym[2][3] = 1;
        s->sym[2][4] = 2;
        s->sym[2][5] = 3;
    }
    if (s->sym[2][1] == 24)
    {
        s->sym[2][1] = 0;
        s->sym[2][2] = 1;
        s->sym[2][3] = 2;
        s->sym[2][4] = 3;
        s->sym[2][5] = 4;
    }
    if (s->sym[3][5] == 24)
        s->sym[3][5] = 0;
    if (s->sym[3][4] == 24)
    {
        s->sym[3][4] = 0;
        s->sym[3][5] = 1;
    }
    if (s->sym[3][3] == 24)
    {
        s->sym[3][3] = 0;
        s->sym[3][4] = 1;
        s->sym[3][5] = 2;
    }
    if (s->sym[3][2] == 24)
    {
        s->sym[3][2] = 0;
        s->sym[3][3] = 1;
        s->sym[3][4] = 2;
        s->sym[3][5] = 3;
    }
    if (s->sym[3][1] == 24)
    {
        s->sym[3][1] = 0;
        s->sym[3][2] = 1;
        s->sym[3][3] = 2;
        s->sym[3][4] = 3;
        s->sym[3][5] = 4;
    }
}

/* Draws the six visible symbols of each of the four reels. */
// LuckySymbol_DrawReels @ 0x081429B4
void LuckySymbol_DrawReels(void)
{
    struct CasinoScene *scene = (struct CasinoScene *)0x0203B554;
    struct LuckySymbol *s = (struct LuckySymbol *)gMenuState;

    Sprite_Draw(gUnknown_0879505C[scene->arg][s->sym[0][5]].sprite, 1, 0, 3, 0, 0x3B, (s->reelOfs[0] + 0xFFDC) & 0xFF);
    Sprite_Draw(gUnknown_0879505C[scene->arg][s->sym[0][4]].sprite, 1, 0, 3, 0, 0x3B, (s->reelOfs[0] + 0xFFF0) & 0xFF);
    Sprite_Draw(gUnknown_0879505C[scene->arg][s->sym[0][3]].sprite, 1, 0, 3, 0, 0x3B, (s->reelOfs[0] + 4) & 0xFF);
    Sprite_Draw(gUnknown_0879505C[scene->arg][s->sym[0][2]].sprite, 1, 0, 3, 0, 0x3B, (s->reelOfs[0] + 0x18) & 0xFF);
    Sprite_Draw(gUnknown_0879505C[scene->arg][s->sym[0][1]].sprite, 1, 0, 3, 0, 0x3B, (s->reelOfs[0] + 0x2C) & 0xFF);
    Sprite_Draw(gUnknown_0879505C[scene->arg][s->sym[0][0]].sprite, 1, 0, 3, 0, 0x3B, (s->reelOfs[0] + 0x40) & 0xFF);
    Sprite_Draw(gUnknown_08795DDC[scene->arg][s->sym[1][5]].sprite, 1, 0, 3, 0, 0x5A, (s->reelOfs[1] + 0xFFDC) & 0xFF);
    Sprite_Draw(gUnknown_08795DDC[scene->arg][s->sym[1][4]].sprite, 1, 0, 3, 0, 0x5A, (s->reelOfs[1] + 0xFFF0) & 0xFF);
    Sprite_Draw(gUnknown_08795DDC[scene->arg][s->sym[1][3]].sprite, 1, 0, 3, 0, 0x5A, (s->reelOfs[1] + 4) & 0xFF);
    Sprite_Draw(gUnknown_08795DDC[scene->arg][s->sym[1][2]].sprite, 1, 0, 3, 0, 0x5A, (s->reelOfs[1] + 0x18) & 0xFF);
    Sprite_Draw(gUnknown_08795DDC[scene->arg][s->sym[1][1]].sprite, 1, 0, 3, 0, 0x5A, (s->reelOfs[1] + 0x2C) & 0xFF);
    Sprite_Draw(gUnknown_08795DDC[scene->arg][s->sym[1][0]].sprite, 1, 0, 3, 0, 0x5A, (s->reelOfs[1] + 0x40) & 0xFF);
    Sprite_Draw(gUnknown_08796B5C[scene->arg][s->sym[2][5]].sprite, 1, 0, 3, 0, 0x79, (s->reelOfs[2] + 0xFFDC) & 0xFF);
    Sprite_Draw(gUnknown_08796B5C[scene->arg][s->sym[2][4]].sprite, 1, 0, 3, 0, 0x79, (s->reelOfs[2] + 0xFFF0) & 0xFF);
    Sprite_Draw(gUnknown_08796B5C[scene->arg][s->sym[2][3]].sprite, 1, 0, 3, 0, 0x79, (s->reelOfs[2] + 4) & 0xFF);
    Sprite_Draw(gUnknown_08796B5C[scene->arg][s->sym[2][2]].sprite, 1, 0, 3, 0, 0x79, (s->reelOfs[2] + 0x18) & 0xFF);
    Sprite_Draw(gUnknown_08796B5C[scene->arg][s->sym[2][1]].sprite, 1, 0, 3, 0, 0x79, (s->reelOfs[2] + 0x2C) & 0xFF);
    Sprite_Draw(gUnknown_08796B5C[scene->arg][s->sym[2][0]].sprite, 1, 0, 3, 0, 0x79, (s->reelOfs[2] + 0x40) & 0xFF);
    Sprite_Draw(gUnknown_087978DC[scene->arg][s->sym[3][5]].sprite, 1, 0, 3, 0, 0x98, (s->reelOfs[3] + 0xFFDC) & 0xFF);
    Sprite_Draw(gUnknown_087978DC[scene->arg][s->sym[3][4]].sprite, 1, 0, 3, 0, 0x98, (s->reelOfs[3] + 0xFFF0) & 0xFF);
    Sprite_Draw(gUnknown_087978DC[scene->arg][s->sym[3][3]].sprite, 1, 0, 3, 0, 0x98, (s->reelOfs[3] + 4) & 0xFF);
    Sprite_Draw(gUnknown_087978DC[scene->arg][s->sym[3][2]].sprite, 1, 0, 3, 0, 0x98, (s->reelOfs[3] + 0x18) & 0xFF);
    Sprite_Draw(gUnknown_087978DC[scene->arg][s->sym[3][1]].sprite, 1, 0, 3, 0, 0x98, (s->reelOfs[3] + 0x2C) & 0xFF);
    Sprite_Draw(gUnknown_087978DC[scene->arg][s->sym[3][0]].sprite, 1, 0, 3, 0, 0x98, (s->reelOfs[3] + 0x40) & 0xFF);
}

// LuckySymbol_DrawNumber @ 0x08142F08
void LuckySymbol_DrawNumber(u32 value, u16 x, u16 y, u16 priority)
{
    u8 *d = NumberToDigits(value);

    Sprite_Draw(gUnknown_087986BC[d[0]], 0, 0, priority, 0, x, y & 0xFF);
    Sprite_Draw(gUnknown_087986BC[d[1]], 0, 0, priority, 0, x - 8, y & 0xFF);
    Sprite_Draw(gUnknown_087986BC[d[2]], 0, 0, priority, 0, x - 16, y & 0xFF);
    Sprite_Draw(gUnknown_087986BC[d[3]], 0, 0, priority, 0, x - 24, y & 0xFF);
    Sprite_Draw(gUnknown_087986BC[d[4]], 0, 0, priority, 0, x - 32, y & 0xFF);
    Sprite_Draw(gUnknown_087986BC[d[5]], 0, 0, priority, 0, x - 40, y & 0xFF);
}

/* Largest power of ten (up to 10000) not above n; 0 for 0. */
// Number_LeadingPowerOf10 @ 0x08143008
u32 Number_LeadingPowerOf10(u32 n)
{
    u32 p = 10000;
    u32 i;

    if (n == 0)
        return 0;
    for (i = 0; i < 5; i++)
    {
        if (n / p != 0)
            return p;
        p /= 10;
    }
    return p;
}
