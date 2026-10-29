/* Lucky Symbol: pattern lamps and payout multipliers (0x08144018-0x081447E3). */

#include "global.h"
#include "casino.h"

/* Bonus game: lights the pattern lamp of each reel's middle-row symbol (symbol k lights
   lamp 7 - k) and marks it as newly lit. */
// LuckySymbol_LightLamps @ 0x08144018
void LuckySymbol_LightLamps(void)
{
    struct CasinoScene *scene = (struct CasinoScene *)0x0203B554;
    struct LuckySymbol *s = (struct LuckySymbol *)gMenuState;

    s->unk56 = 1;
    switch (gUnknown_0879505C[scene->arg][s->sym[0][1]].sym)
    {
    case 0:
        s->lamp[7] = 1;
        s->newLamp[7] = 1;
        break;
    case 1:
        s->lamp[6] = 1;
        s->newLamp[6] = 1;
        break;
    case 2:
        s->lamp[5] = 1;
        s->newLamp[5] = 1;
        break;
    case 3:
        s->lamp[4] = 1;
        s->newLamp[4] = 1;
        break;
    case 4:
        s->lamp[3] = 1;
        s->newLamp[3] = 1;
        break;
    case 5:
        s->lamp[2] = 1;
        s->newLamp[2] = 1;
        break;
    case 6:
        s->lamp[1] = 1;
        s->newLamp[1] = 1;
        break;
    case 7:
        s->lamp[0] = 1;
        s->newLamp[0] = 1;
        break;
    }
    switch (gUnknown_08795DDC[scene->arg][s->sym[1][1]].sym)
    {
    case 0:
        s->lamp[7] = 1;
        s->newLamp[7] = 1;
        break;
    case 1:
        s->lamp[6] = 1;
        s->newLamp[6] = 1;
        break;
    case 2:
        s->lamp[5] = 1;
        s->newLamp[5] = 1;
        break;
    case 3:
        s->lamp[4] = 1;
        s->newLamp[4] = 1;
        break;
    case 4:
        s->lamp[3] = 1;
        s->newLamp[3] = 1;
        break;
    case 5:
        s->lamp[2] = 1;
        s->newLamp[2] = 1;
        break;
    case 6:
        s->lamp[1] = 1;
        s->newLamp[1] = 1;
        break;
    case 7:
        s->lamp[0] = 1;
        s->newLamp[0] = 1;
        break;
    }
    switch (gUnknown_08796B5C[scene->arg][s->sym[2][1]].sym)
    {
    case 0:
        s->lamp[7] = 1;
        s->newLamp[7] = 1;
        break;
    case 1:
        s->lamp[6] = 1;
        s->newLamp[6] = 1;
        break;
    case 2:
        s->lamp[5] = 1;
        s->newLamp[5] = 1;
        break;
    case 3:
        s->lamp[4] = 1;
        s->newLamp[4] = 1;
        break;
    case 4:
        s->lamp[3] = 1;
        s->newLamp[3] = 1;
        break;
    case 5:
        s->lamp[2] = 1;
        s->newLamp[2] = 1;
        break;
    case 6:
        s->lamp[1] = 1;
        s->newLamp[1] = 1;
        break;
    case 7:
        s->lamp[0] = 1;
        s->newLamp[0] = 1;
        break;
    }
    switch (gUnknown_087978DC[scene->arg][s->sym[3][1]].sym)
    {
    case 0:
        s->lamp[7] = 1;
        s->newLamp[7] = 1;
        break;
    case 1:
        s->lamp[6] = 1;
        s->newLamp[6] = 1;
        break;
    case 2:
        s->lamp[5] = 1;
        s->newLamp[5] = 1;
        break;
    case 3:
        s->lamp[4] = 1;
        s->newLamp[4] = 1;
        break;
    case 4:
        s->lamp[3] = 1;
        s->newLamp[3] = 1;
        break;
    case 5:
        s->lamp[2] = 1;
        s->newLamp[2] = 1;
        break;
    case 6:
        s->lamp[1] = 1;
        s->newLamp[1] = 1;
        break;
    case 7:
        s->lamp[0] = 1;
        s->newLamp[0] = 1;
        break;
    }
}

/* Draws the lit pattern lamps (those not blinking as newly lit). */
// LuckySymbol_DrawLamps @ 0x08144270
void LuckySymbol_DrawLamps(void)
{
    struct LuckySymbol *s = (struct LuckySymbol *)gMenuState;

    if (s->lamp[0] == 1 && s->newLamp[0] == 0)
        Sprite_Draw(gUnknown_0814F10C, 0, 0, 0, 0, 0x45, 0x65);
    if (s->lamp[1] == 1 && s->newLamp[1] == 0)
        Sprite_Draw(gUnknown_0814F124, 0, 0, 0, 0, 0x5B, 0x65);
    if (s->lamp[2] == 1 && s->newLamp[2] == 0)
        Sprite_Draw(gUnknown_0814F13C, 0, 0, 0, 0, 0x72, 0x65);
    if (s->lamp[3] == 1 && s->newLamp[3] == 0)
        Sprite_Draw(gUnknown_0814F154, 0, 0, 0, 0, 0x88, 0x65);
    if (s->lamp[4] == 1 && s->newLamp[4] == 0)
        Sprite_Draw(gUnknown_0814F16C, 0, 0, 0, 0, 0x45, 0x72);
    if (s->lamp[5] == 1 && s->newLamp[5] == 0)
        Sprite_Draw(gUnknown_0814F184, 0, 0, 0, 0, 0x5B, 0x72);
    if (s->lamp[6] == 1 && s->newLamp[6] == 0)
        Sprite_Draw(gUnknown_0814F19C, 0, 0, 0, 0, 0x72, 0x72);
    if (s->lamp[7] == 1 && s->newLamp[7] == 0)
        Sprite_Draw(gUnknown_0814F1B4, 0, 0, 0, 0, 0x88, 0x72);
}

/* Blinks the newly lit lamps four times, then clears the "new" marks. */
// LuckySymbol_BlinkNewLamps @ 0x081443F0
void LuckySymbol_BlinkNewLamps(void)
{
    struct LuckySymbol *s = (struct LuckySymbol *)gMenuState;

    if (s->count <= 3)
    {
        if (s->newLamp[0] == 1 && s->blink > 7)
            Sprite_Draw(gUnknown_0814F10C, 0, 0, 0, 0, 0x45, 0x65);
        if (s->newLamp[1] == 1 && s->blink > 7)
            Sprite_Draw(gUnknown_0814F124, 0, 0, 0, 0, 0x5B, 0x65);
        if (s->newLamp[2] == 1 && s->blink > 7)
            Sprite_Draw(gUnknown_0814F13C, 0, 0, 0, 0, 0x72, 0x65);
        if (s->newLamp[3] == 1 && s->blink > 7)
            Sprite_Draw(gUnknown_0814F154, 0, 0, 0, 0, 0x88, 0x65);
        if (s->newLamp[4] == 1 && s->blink > 7)
            Sprite_Draw(gUnknown_0814F16C, 0, 0, 0, 0, 0x45, 0x72);
        if (s->newLamp[5] == 1 && s->blink > 7)
            Sprite_Draw(gUnknown_0814F184, 0, 0, 0, 0, 0x5B, 0x72);
        if (s->newLamp[6] == 1 && s->blink > 7)
            Sprite_Draw(gUnknown_0814F19C, 0, 0, 0, 0, 0x72, 0x72);
        if (s->newLamp[7] == 1 && s->blink > 7)
            Sprite_Draw(gUnknown_0814F1B4, 0, 0, 0, 0, 0x88, 0x72);
        if (s->blink > 10)
        {
            s->blink = 0;
            s->count++;
        }
        s->blink++;
    }
    else
    {
        Sound_Play(0x15D);
        s->newLamp[7] = 0;
        s->newLamp[6] = 0;
        s->newLamp[5] = 0;
        s->newLamp[4] = 0;
        s->newLamp[3] = 0;
        s->newLamp[2] = 0;
        s->newLamp[1] = 0;
        s->newLamp[0] = 0;
        s->count = 0;
        s->unk31 = 1;
    }
}

/* Bonus round effects on the payout: a lit lamp of the winning pattern multiplies it by
   the bet multiplier (2-5, shown blinking), lamp 6 doubles it. */
// LuckySymbol_ApplyMultipliers @ 0x081445C4
void LuckySymbol_ApplyMultipliers(void)
{
    struct LuckySymbol *s = (struct LuckySymbol *)gMenuState;

    if (s->unk39 == 1)
    {
        if (s->count <= 3)
        {
            if (s->blink > 7)
            {
                switch (s->pattern)
                {
                case 0:
                    Sprite_Draw(gUnknown_0814F1B4, 0, 0, 0, 0, 0x88, 0x72);
                    break;
                case 1:
                    Sprite_Draw(gUnknown_0814F19C, 0, 0, 0, 0, 0x72, 0x72);
                    break;
                case 2:
                    Sprite_Draw(gUnknown_0814F184, 0, 0, 0, 0, 0x5B, 0x72);
                    break;
                case 3:
                    Sprite_Draw(gUnknown_0814F16C, 0, 0, 0, 0, 0x45, 0x72);
                    break;
                case 4:
                    Sprite_Draw(gUnknown_0814F154, 0, 0, 0, 0, 0x88, 0x65);
                    break;
                case 5:
                    Sprite_Draw(gUnknown_0814F13C, 0, 0, 0, 0, 0x72, 0x65);
                    break;
                case 6:
                    Sprite_Draw(gUnknown_0814F124, 0, 0, 0, 0, 0x5B, 0x65);
                    break;
                case 7:
                    Sprite_Draw(gUnknown_0814F10C, 0, 0, 0, 0, 0x45, 0x65);
                    break;
                }
                switch (s->bet)
                {
                case 2:
                    Sprite_Draw(gUnknown_0814F2E4, 0, 0, 0, 0, 0xA0, 0x6C);
                    break;
                case 3:
                    Sprite_Draw(gUnknown_0814F314, 0, 0, 0, 0, 0xA0, 0x6C);
                    break;
                case 4:
                    Sprite_Draw(gUnknown_0814F344, 0, 0, 0, 0, 0xA0, 0x6C);
                    break;
                case 5:
                    Sprite_Draw(gUnknown_0814F374, 0, 0, 0, 0, 0xA0, 0x6C);
                    break;
                }
            }
            if (s->blink > 10)
            {
                s->blink = 0;
                s->count++;
            }
            s->blink++;
        }
        else
        {
            s->payout *= s->bet;
            s->bet = 2;
            s->unk39 = 0;
            s->count = 0;
        }
    }
    if (s->unk33 == 1)
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
        }
        else
        {
            s->unk33 = 0;
            s->unk32 = 0;
            s->payout <<= 1;
            s->count = 0;
        }
    }
}

// LuckySymbol_SetInit @ 0x081447D8
void LuckySymbol_SetInit(u32 unused, u16 value)
{
    struct LuckySymbol *s = (struct LuckySymbol *)gMenuState;

    s->init = value;
}
