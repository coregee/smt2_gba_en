/* Lucky Symbol: payout counting, reel spin and win highlight (0x08143044-0x081437E3). */

#include "global.h"
#include "casino.h"

/* Counts the win up to the payout every fourth frame (by the payout's leading digit while
   A is held). At the end, a lit pattern lamp turns into a bonus round. */
// LuckySymbol_CountWin @ 0x08143044
void LuckySymbol_CountWin(void)
{
    struct LuckySymbol *s = (struct LuckySymbol *)gMenuState;

    if ((gFrameCounter & 3) != 0)
        goto clear;
    if (gRepeatedKeys & 1)
        s->step = Number_LeadingPowerOf10(s->win);
    else
        s->step = 1;
    s->win += s->step;
    if (s->win < s->payout)
        goto clear;
    s->win = s->payout;
    s->savedCoins = s->coins;
    if (s->unk52 == 1)
    {
    switch (s->pattern)
    {
    case 0:
        if (s->lamp[7] == 1)
        {
            s->lamp[7] = 0;
            s->unk38 = 0;
            s->unk39 = 1;
        }
        break;
    case 1:
        if (s->lamp[6] == 1)
        {
            s->lamp[6] = 0;
            s->unk38 = 0;
            s->unk39 = 1;
        }
        break;
    case 2:
        if (s->lamp[5] == 1)
        {
            s->lamp[5] = 0;
            s->unk38 = 0;
            s->unk39 = 1;
        }
        break;
    case 3:
        if (s->lamp[4] == 1)
        {
            s->lamp[4] = 0;
            s->unk38 = 0;
            s->unk39 = 1;
        }
        break;
    case 4:
        if (s->lamp[3] == 1)
        {
            s->lamp[3] = 0;
            s->unk38 = 0;
            s->unk39 = 1;
        }
        break;
    case 5:
        if (s->lamp[2] == 1)
        {
            s->lamp[2] = 0;
            s->unk38 = 0;
            s->unk39 = 1;
        }
        break;
    case 6:
        if (s->lamp[1] == 1)
        {
            s->lamp[1] = 0;
            s->unk38 = 0;
            s->unk39 = 1;
        }
        break;
    case 7:
        if (s->lamp[0] == 1)
        {
            s->lamp[0] = 0;
            s->unk38 = 0;
            s->unk39 = 1;
        }
        break;
    }
    if (s->unk39 == 0)
    {
        if (s->unk32 == 0)
        {
            s->unk50 = 0;
            s->unk51 = 0;
        }
        else
        {
            s->unk33 = 1;
            s->unk51 = 0;
        }
    }
    }
    else
    {
        s->unk50 = 0;
        s->unk51 = 0;
    }
clear:
    if (s->win > 99)
    {
        s->lamp[0] = 0;
        s->lamp[1] = 0;
        s->lamp[2] = 0;
        s->lamp[3] = 0;
        s->lamp[4] = 0;
        s->lamp[5] = 0;
        s->lamp[6] = 0;
        s->lamp[7] = 0;
    }
}

/* Pays the win into the coins (after a 100-frame pause), then ends the round. */
// LuckySymbol_PayWin @ 0x081431F8
void LuckySymbol_PayWin(void)
{
    struct LuckySymbol *s = (struct LuckySymbol *)gMenuState;

    if ((gFrameCounter & 3) == 0 && s->unk51 > 100)
    {
        Sound_Play(0x159);
        if (gRepeatedKeys & 1)
            s->step = Number_LeadingPowerOf10(s->win);
        else
            s->step = 1;
        s->win -= s->step;
        s->coins += s->step;
        if (s->win > 0)
            goto tick;
        s->coins = s->savedCoins + s->payout;
        s->win = 0;
    }
    if (s->win == 0)
    {
        s->coins = s->savedCoins + s->payout;
        s->payout = s->win;
        s->mode = s->win;
    }
tick:
    if (s->unk51 <= 110)
        s->unk51++;
}

/* Reel spin phases: 0 wind-up, 1 spinning (random speed), 2-5 stop the reels one by one. */
// LuckySymbol_SpinReels @ 0x0814328C
void LuckySymbol_SpinReels(void)
{
    struct LuckySymbol *s = (struct LuckySymbol *)gMenuState;

    switch (s->phase)
    {
    case 0:
        if (s->held[0] == 0)
            s->reelOfs[0] += 2;
        if (s->held[1] == 0)
            s->reelOfs[1] += 2;
        if (s->held[2] == 0)
            s->reelOfs[2] += 2;
        if (s->held[3] == 0)
            s->reelOfs[3] += 2;
        if (s->reelOfs[0] == 40 || s->reelOfs[1] == 40 || s->reelOfs[2] == 40 || s->reelOfs[3] == 40)
        {
            s->phase = 1;
            s->reelOfs[3] = 0;
            s->reelOfs[2] = 0;
            s->reelOfs[1] = 0;
            s->reelOfs[0] = 0;
        }
        break;
    case 1:
        if (s->held[0] == 0)
        {
            s->reelPos[0] += 9;
            s->rand = Random_Byte();
            s->reelPos[0] += s->rand * 59 / 255;
        }
        if (s->held[1] == 0)
        {
            s->reelPos[1] += 9;
            s->rand = Random_Byte();
            s->reelPos[1] += s->rand * 59 / 255;
        }
        if (s->held[2] == 0)
        {
            s->reelPos[2] += 9;
            s->rand = Random_Byte();
            s->reelPos[2] += s->rand * 59 / 255;
        }
        if (s->held[3] == 0)
        {
            s->reelPos[3] += 9;
            s->rand = Random_Byte();
            s->reelPos[3] += s->rand * 59 / 255;
        }
        if (s->round == 5 && s->timer > 39)
        {
            s->phase = 2;
            s->timer = 0;
        }
        s->timer += 18;
        break;
    case 2:
        if (s->held[0] == 0)
            s->reelOfs[0] += 2;
        if (s->held[1] == 0)
            s->reelPos[1] += 9;
        if (s->held[2] == 0)
            s->reelPos[2] += 9;
        if (s->held[3] == 0)
            s->reelPos[3] += 9;
        if (s->reelOfs[0] == 60 || s->held[0] == 1)
        {
            if (s->held[0] == 0)
                Sound_Play(0x15B);
            s->phase = 3;
        }
        break;
    case 3:
        if (s->held[1] == 0)
            s->reelOfs[1] += 2;
        if (s->held[2] == 0)
            s->reelPos[2] += 9;
        if (s->held[3] == 0)
            s->reelPos[3] += 9;
        if (s->reelOfs[1] == 60 || s->held[1] == 1)
        {
            if (s->held[1] == 0)
                Sound_Play(0x15B);
            s->phase = 4;
        }
        break;
    case 4:
        if (s->held[2] == 0)
            s->reelOfs[2] += 2;
        if (s->held[3] == 0)
            s->reelPos[3] += 9;
        if (s->reelOfs[2] == 60 || s->held[2] == 1)
        {
            if (s->held[2] == 0)
                Sound_Play(0x15B);
            s->phase = 5;
        }
        break;
    case 5:
        if (s->held[3] == 0)
            s->reelOfs[3] += 2;
        break;
    }
    if (s->reelPos[0] > 478)
        s->reelPos[0] = 0;
    if (s->reelPos[1] > 478)
        s->reelPos[1] = 0;
    if (s->reelPos[2] > 478)
        s->reelPos[2] = 0;
    if (s->reelPos[3] > 478)
        s->reelPos[3] = 0;
    if (s->timer > 276)
    {
        s->timer = 0;
        s->round++;
    }
    if (s->phase == 5 && (s->reelOfs[3] > 59 || s->held[3] == 1))
    {
        if (s->held[3] == 0)
            Sound_Play(0x15B);
        s->mode = 2;
        s->timer = 0;
        s->round = 0;
        if (s->held[0] == 0)
        {
            s->sym[0][0] = s->sym[0][3];
            s->sym[0][1] = s->sym[0][4];
            s->sym[0][2] = s->sym[0][5];
        }
        if (s->held[1] == 0)
        {
            s->sym[1][0] = s->sym[1][3];
            s->sym[1][1] = s->sym[1][4];
            s->sym[1][2] = s->sym[1][5];
        }
        if (s->held[2] == 0)
        {
            s->sym[2][0] = s->sym[2][3];
            s->sym[2][1] = s->sym[2][4];
            s->sym[2][2] = s->sym[2][5];
        }
        if (s->held[3] == 0)
        {
            s->sym[3][0] = s->sym[3][3];
            s->sym[3][1] = s->sym[3][4];
            s->sym[3][2] = s->sym[3][5];
        }
        s->reelOfs[3] = 0;
        s->reelOfs[2] = 0;
        s->reelOfs[1] = 0;
        s->reelOfs[0] = 0;
        if (s->holdEnabled == 1)
        {
            s->holdEnabled = 0;
            s->heldCount = 0;
            s->held[3] = 0;
            s->held[2] = 0;
            s->held[1] = 0;
            s->held[0] = 0;
        }
    }
}

/* Blinks the winning line three times, then starts counting the payout. */
// LuckySymbol_BlinkWinLine @ 0x08143610
void LuckySymbol_BlinkWinLine(void)
{
    struct LuckySymbol *s = (struct LuckySymbol *)gMenuState;

    if (s->count <= 2)
    {
        if (s->blink > 7)
            LuckySymbol_DrawWinLine();
        if (s->blink > 10)
        {
            s->blink = 0;
            s->count++;
        }
        s->blink++;
    }
    else
    {
        s->blink = 0;
        s->unk53 = 0;
        s->count = 0;
        s->unk52 = 1;
        s->mode = 3;
    }
}

/* Lights the four winning symbols and the pattern's row on the pay board. */
// LuckySymbol_DrawWinLine @ 0x08143668
void LuckySymbol_DrawWinLine(void)
{
    struct CasinoScene *scene = (struct CasinoScene *)0x0203B554;
    struct LuckySymbol *s = (struct LuckySymbol *)gMenuState;

    Sprite_Draw(gUnknown_0879505C[scene->arg][s->lines[0].index].litSprite, s->lines[0].layer, 0, 3, 0, 0x3B, 0x2C);
    Sprite_Draw(gUnknown_08795DDC[scene->arg][s->lines[1].index].litSprite, s->lines[1].layer, 0, 3, 0, 0x5A, 0x2C);
    Sprite_Draw(gUnknown_08796B5C[scene->arg][s->lines[2].index].litSprite, s->lines[2].layer, 0, 3, 0, 0x79, 0x2C);
    Sprite_Draw(gUnknown_087978DC[scene->arg][s->line3Index].litSprite, s->line3Layer, 0, 3, 0, 0x98, 0x2C);
    Sprite_Draw(gUnknown_0879865C[s->pattern].sprite, 0, 0, 0, 0, gUnknown_0879865C[s->pattern].x, gUnknown_0879865C[s->pattern].y & 0xFF);
    switch (s->pattern)
    {
    case 0:
        Sound_Play(0x15D);
        break;
    case 1:
        Sound_Play(0x15D);
        break;
    case 2:
        Sound_Play(0x15D);
        break;
    case 3:
        Sound_Play(0x15D);
        break;
    case 4:
        Sound_Play(0x15D);
        break;
    case 5:
        Sound_Play(0x15D);
        break;
    case 6:
        Sound_Play(0x15E);
        break;
    case 7:
        Sound_Play(0x15E);
        break;
    }
}
