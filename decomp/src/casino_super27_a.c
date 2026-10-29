/* Super 27 (casino game 5): setup, main loop and reel handling (0x0813F168-0x08140AD7). */

#include "global.h"
#include "casino.h"

#define SCENE ((struct CasinoScene *)0x0203B554)

// Super27_Init @ 0x0813F168
void Super27_Init(void)
{
    struct Super27 *s = (struct Super27 *)gMenuState;

    CpuFill32(0, s, 0x800);
    REG_BG0CNT = 0x4008;
    gUnk_03000002 = 0;
    gUnk_03000040 = 0;
    s->init = 1;
    s->unk28 = 0x111;
    s->coins = sub_080C31F0();
    s->sym[2][0] = 0;
    s->sym[1][0] = 0;
    s->sym[0][0] = 0;
    s->sym[2][1] = 1;
    s->sym[1][1] = 1;
    s->sym[0][1] = 1;
    s->sym[2][2] = 2;
    s->sym[1][2] = 2;
    s->sym[0][2] = 2;
    s->sym[2][3] = 3;
    s->sym[1][3] = 3;
    s->sym[0][3] = 3;
    s->sym[2][4] = 4;
    s->sym[1][4] = 4;
    s->sym[0][4] = 4;
    s->sym[2][5] = 5;
    s->sym[1][5] = 5;
    s->sym[0][5] = 5;
    s->lines[0].x = 0x44;
    s->lines[1].x = 0x69;
    s->lines[2].x = 0x8E;
}

/* Super 27 main loop. Modes: 0 idle (holds, double-up choice), 1 coin insert animation,
   2 reels spinning, 3 no-win animation, 4 evaluate, 6 bonus card screen scroll,
   7 win display, 8 payout count, 9 quit. R starts (1 coin; from the double-up choice it
   costs 5), L quits; Left/Up/Right hold reels 1-3 (at most two). */
// Super27_Update @ 0x0813F22C
void Super27_Update(void)
{
    struct CasinoScene *scene = (struct CasinoScene *)0x0203B554;
    struct Super27 *s = (struct Super27 *)gMenuState;
    u16 i;

    if (s->init == 1)
    {
        Task_Create(gUnknown_08794E24, 0xFFFF);
        s->init = 0;
    }
    if (s->lines[2].unk8 == 1)
    {
        if ((gKeysNew & 0x100) && s->mode == 0 && s->coins != 0)
        {
            if (s->unk26 == 1 || s->unk1E == 1)
            {
                if (s->unk26 == 0 && s->unk20 == 1)
                    s->mode = 6;
                else if (s->unk26 == 0 && s->unk20 == 2)
                {
                    s->mode = 0;
                    s->unk20 = 0;
                    s->unk1E = 0;
                    Super27_ClearHolds();
                    s->coins += s->win;
                    s->win = 0;
                }
                else if (s->unk26 == 1 && s->unk20 == 2)
                {
                    s->mode = 6;
                    s->coins += s->win;
                    s->win = 0;
                }
                else
                {
                    Sound_Play(0x15A);
                    s->mode = 2;
                    s->unk1E = 0;
                    s->unk20 = 0;
                    s->win -= 5;
                }
            }
            else
            {
                s->mode = 1;
                s->coins--;
            }
        }
        if ((gKeysNew & 0x200) && s->mode == 0 && s->unk26 == 0 && s->unk20 == 0)
        {
            Sound_Play(0x158);
            s->mode = 9;
        }
    }
    if (s->mode == 1)
    {
        if (s->anim <= 3)
            Sprite_Draw(gUnknown_0814EE00, 0, 0, 0, 0, 8, 4);
        if (s->anim >= 4 && s->anim <= 6)
            Sprite_Draw(gUnknown_0814EDE8, 0, 0, 0, 0, 8, 4);
        if (s->anim >= 7 && s->anim <= 9)
            Sprite_Draw(gUnknown_0814EDD0, 0, 0, 0, 0, 8, 4);
        if (s->anim > 9)
        {
            Sprite_Draw(gUnknown_0814EDB8, 0, 0, 0, 0, 8, 4);
            Sound_Play(0x15A);
            s->mode = 2;
            s->anim = 0;
        }
        Super27_DrawReels();
        Super27_DrawNumber(s->win, 0xE4, 0x21, 2);
        Super27_DrawNumber(s->coins, 0xE4, 0x4A, 2);
        s->anim++;
    }
    else if (s->mode == 6)
    {
        if (s->unk24 == 0 && s->scroll < 0xF0)
            s->unk24 = 1;
        else if (s->unk24 == 1 && s->scroll > 0xEF)
        {
            s->unk24 = 2;
            s->scroll = 0xF0;
            if (s->unk26 == 0)
            {
                CasinoScene_LoadBgMap(0, gUnknown_087A4FA8, 0);
                for (i = 0; i < 6; i++)
                {
                    s->cards[i].value = Random_Byte() & 0xFF;
                    s->cards[i].value = (u32)(s->cards[i].value * 8) / 0xFF;
                    s->cards[i].marked = 0;
                }
            }
            else
                CasinoScene_LoadBgMap(0, gUnknown_087A51AC, 0);
        }
        else if (s->unk24 == 2 && s->scroll == 0)
        {
            s->scroll = 0;
            s->unk24 = 0;
            s->unk20 = 0;
            s->unk1E = 0;
            s->mode = 0;
            if (s->unk26 == 0)
                s->unk26 = 1;
            else
            {
                s->unk26 = 0;
                s->cardCount = 0;
            }
        }
        gDispRegs = -s->scroll;
        Sound_Play(0x15F);
        Sprite_Draw(gUnknown_0814EDB8, 0, 0, 0, 0, 8, 4);
        Super27_DrawReels();
        Super27_DrawNumber(s->win, 0xE4, 0x21, 2);
        Super27_DrawNumber(s->coins, 0xE4, 0x4A, 2);
        if (s->unk1E == 1)
            Super27_DrawWinHighlight();
        if (s->unk20 == 1)
            Sprite_Draw(gUnknown_0814EC40, 0, 0, 0, 0, 0xA, 0x1B);
        else if (s->unk20 == 2)
            Sprite_Draw(gUnknown_0814EC58, 0, 0, 0, 0, 0xA, 0x43);
        if (s->blink > 20)
        {
            Sprite_Draw(gUnknown_0814EC90, 0, 0, 0, 0, 0x19, 0x2C);
            Sprite_Draw(gUnknown_0814EC80, 0, 0, 0, 0, 0x19, 0x3B);
        }
        if (s->blink > 40)
            s->blink = 0;
        if (s->unk24 == 1)
        {
            if (s->unk26 == 1)
            {
                Super27_DrawCards();
                Super27_DrawMarkedCards();
            }
            s->scroll += 2;
        }
        else if (s->unk24 == 2)
        {
            if (s->unk26 == 0)
                Super27_DrawCards();
            s->scroll -= 2;
        }
        s->blink++;
    }
    else if (s->mode == 2)
    {
        Super27_UpdateReelStrips();
        Sprite_Draw(gUnknown_0814EDB8, 0, 0, 0, 0, 8, 4);
        Super27_DrawReels();
        Super27_DrawNumber(s->win, 0xE4, 0x21, 2);
        Super27_DrawNumber(s->coins, 0xE4, 0x4A, 2);
        if (s->unk26 == 1)
        {
            Super27_DrawCards();
            Super27_DrawMarkedCards();
        }
        if (s->phase == 0)
        {
            if (s->held[0] == 0)
                s->reelOfs[0] += 2;
            if (s->held[1] == 0)
                s->reelOfs[1] += 2;
            if (s->held[2] == 0)
                s->reelOfs[2] += 2;
            s->timer += 4;
        }
        else if (s->phase == 1)
        {
            if (s->held[0] == 0)
            {
                s->reelPos[0] += 9;
                s->rand = Random_Byte() & 0xFF;
                s->reelPos[0] += s->rand * 59 / 255;
            }
            if (s->held[1] == 0)
            {
                s->reelPos[1] += 9;
                s->rand = Random_Byte() & 0xFF;
                s->reelPos[1] += s->rand * 59 / 255;
            }
            if (s->held[2] == 0)
            {
                s->reelPos[2] += 9;
                s->rand = Random_Byte() & 0xFF;
                s->reelPos[2] += s->rand * 59 / 255;
            }
            s->timer += 18;
        }
        else if (s->phase == 2)
        {
            if (s->held[0] == 0)
                s->reelOfs[0] += 2;
            if (s->held[1] == 0)
                s->reelPos[1] += 9;
            if (s->held[2] == 0)
                s->reelPos[2] += 9;
        }
        else if (s->phase == 3)
        {
            if (s->held[1] == 0)
                s->reelOfs[1] += 2;
            if (s->held[2] == 0)
                s->reelPos[2] += 9;
        }
        else if (s->phase == 4)
        {
            if (s->held[2] == 0)
                s->reelOfs[2] += 2;
        }
        if (s->phase == 0 && (s->reelOfs[0] == 40 || s->reelOfs[1] == 40 || s->reelOfs[2] == 40))
        {
            s->phase = 1;
            s->reelOfs[2] = 0;
            s->reelOfs[1] = 0;
            s->reelOfs[0] = 0;
        }
        if (s->phase == 1 && s->round == 5 && s->timer > 39)
        {
            s->phase = 2;
            s->timer = 0;
        }
        if (s->phase == 2 && (s->reelOfs[0] == 60 || s->held[0] == 1))
        {
            if (s->held[0] == 0)
                Sound_Play(0x15B);
            s->phase = 3;
        }
        if (s->phase == 3 && (s->reelOfs[1] == 60 || s->held[1] == 1))
        {
            if (s->held[1] == 0)
                Sound_Play(0x15B);
            s->phase = 4;
        }
        if (s->unk26 == 1)
        {
            Sprite_Draw(gUnknown_0814EC40, 0, 0, 0, 0, 0xA, 0x1B);
            if (s->blink > 20)
            {
                Sprite_Draw(gUnknown_0814EC90, 0, 0, 0, 0, 0x19, 0x2C);
                Sprite_Draw(gUnknown_0814EC80, 0, 0, 0, 0, 0x19, 0x3B);
            }
            if (s->blink > 40)
                s->blink = 0;
            s->blink++;
        }
        if (s->reelPos[0] > 478)
            s->reelPos[0] = 0;
        if (s->reelPos[1] > 478)
            s->reelPos[1] = 0;
        if (s->reelPos[2] > 478)
            s->reelPos[2] = 0;
        if (s->timer > 276)
        {
            s->timer = 0;
            s->round++;
        }
        if ((s->round == 5 && s->reelOfs[2] > 59) || (s->phase == 4 && s->held[2] == 1))
        {
            if (s->held[2] == 0)
                Sound_Play(0x15B);
            s->mode = 4;
            s->unk20 = 0;
            s->round = 0;
            s->timer = 0;
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
            s->reelOfs[2] = 0;
            s->reelOfs[1] = 0;
            s->reelOfs[0] = 0;
            if (s->unk26 == 0)
            {
                if (s->unk18 == 0)
                    s->unk18 = 1;
                else if (s->heldCount != 0)
                {
                    s->unk18 = 0;
                    s->heldCount = 0;
                    s->held[2] = 0;
                    s->held[1] = 0;
                    s->held[0] = 0;
                }
            }
        }
    }
    else if (s->mode == 4)
    {
        if (s->unk26 == 1)
        {
            Super27_ScanBonusLine();
            Sprite_Draw(gUnknown_0814EC40, 0, 0, 0, 0, 0xA, 0x1B);
        }
        else
        {
            if (gUnknown_0879245C[scene->arg][s->sym[0][0]].sym == 8)
            {
                s->unk2E = 3;
                Super27_ScanBonusLine();
            }
            if (gUnknown_0879245C[scene->arg][s->sym[0][1]].sym == 8)
            {
                s->unk2E = 2;
                Super27_ScanBonusLine();
            }
            else if (s->unk1E == 0)
                Super27_CheckMiddleLine();
            if (gUnknown_0879245C[scene->arg][s->sym[0][2]].sym == 8)
            {
                s->unk2E = 1;
                Super27_ScanBonusLine();
            }
        }
        Sprite_Draw(gUnknown_0814EDB8, 0, 0, 0, 0, 8, 4);
        Super27_DrawReels();
        Super27_DrawNumber(s->win, 0xE4, 0x21, 2);
        Super27_DrawNumber(s->coins, 0xE4, 0x4A, 2);
        if (s->unk26 == 1)
        {
            Super27_DrawCards();
            Super27_DrawMarkedCards();
        }
        if (s->unk2A == 1)
            s->mode = 7;
        else if (s->unk26 == 0)
        {
            s->unk2C = 0;
            s->unk2E = 0;
            if (s->unk1E == 0)
                s->mode = 3;
            else
                s->mode = 0;
        }
        else
        {
            Super27_ClearHolds();
            s->unk2C = 0;
            s->unk2E = 0;
            if (s->win == 0)
                s->mode = 6;
            else if (s->cardCount == 6)
            {
                s->mode = 6;
                s->coins += s->win;
                s->win = 0;
            }
            else
                s->mode = 0;
        }
    }
    else if (s->mode == 7)
    {
        Sprite_Draw(gUnknown_0814EDB8, 0, 0, 0, 0, 8, 4);
        Super27_DrawReels();
        Super27_DrawNumber(s->win, 0xE4, 0x21, 2);
        Super27_DrawNumber(s->coins, 0xE4, 0x4A, 2);
        if (s->unk26 == 1)
        {
            Sprite_Draw(gUnknown_0814EC40, 0, 0, 0, 0, 0xA, 0x1B);
            Super27_DrawCards();
            Super27_DrawMarkedCards();
        }
        if (s->unk14 <= 2)
        {
            if (s->blink > 5)
            {
                Super27_DrawWinHighlight();
                if (s->unk26 == 1)
                    Sprite_Draw(gUnknown_0814ECD8, 0, 0, 0, 0, 0x62, 0xD);
                switch (s->winSym)
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
                case 7:
                    Sound_Play(0x15E);
                    break;
                case 8:
                    Sound_Play(0x15E);
                    break;
                }
            }
            if (s->blink > 10)
            {
                s->blink = 0;
                s->unk14++;
            }
            s->blink++;
        }
        else
        {
            s->unk14 = 0;
            s->unk2A = 0;
            s->blink = 0;
            Super27_DrawWinHighlight();
            Super27_ClearHolds();
            if (s->unk26 == 1)
                Super27_MarkCard();
            s->mode = 8;
        }
    }
    else if (s->mode == 3)
    {
        if (s->anim <= 3)
            Sprite_Draw(gUnknown_0814EDD0, 0, 0, 0, 0, 8, 4);
        if (s->anim >= 4 && s->anim <= 6)
            Sprite_Draw(gUnknown_0814EDE8, 0, 0, 0, 0, 8, 4);
        if (s->anim >= 7 && s->anim <= 9)
            Sprite_Draw(gUnknown_0814EE00, 0, 0, 0, 0, 8, 4);
        if (s->anim > 9)
        {
            s->mode = 0;
            s->anim = 0;
        }
        Super27_DrawReels();
        Super27_DrawNumber(s->win, 0xE4, 0x21, 2);
        Super27_DrawNumber(s->coins, 0xE4, 0x4A, 2);
        s->phase = 0;
        s->anim++;
    }
    else if (s->mode == 8)
    {
        Sprite_Draw(gUnknown_0814EDB8, 0, 0, 0, 0, 8, 4);
        Super27_DrawReels();
        Super27_DrawWinHighlight();
        if (s->unk26 == 1)
        {
            Sprite_Draw(gUnknown_0814EC40, 0, 0, 0, 0, 0xA, 0x1B);
            Super27_DrawCards();
            Super27_DrawMarkedCards();
        }
        Super27_DrawNumber(s->win, 0xE4, 0x21, 2);
        Super27_DrawNumber(s->coins, 0xE4, 0x4A, 2);
        Super27_CountPayout();
    }
    else if (s->mode == 0)
    {
        if (s->blink > 20)
        {
            Sprite_Draw(gUnknown_0814EC10, 0, 0, 0, 0, 0xBB, 5);
            if (s->unk26 == 0)
                Sprite_Draw(gUnknown_0814ECE8, 0, 0, 0, 0, 0xC4, 0x33);
            else
                Sprite_Draw(gUnknown_0814ED00, 0, 0, 0, 0, 0xC1, 0x31);
            if (s->blink > 40)
            {
                s->blink = 0;
                if (s->lines[2].unk8 == 0)
                    s->lines[2].unk8 = 1;
            }
        }
        if (s->unk18 == 1)
        {
            Sprite_Draw(gUnknown_0814EC70, 0, 0, 0, 0, 0xB, 0x5B);
            if ((gKeysNew & 0x20) && s->held[0] == 0 && s->heldCount <= 1)
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
            if ((gKeysNew & 0x40) && s->held[1] == 0 && s->heldCount <= 1)
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
            if ((gKeysNew & 0x10) && s->held[2] == 0 && s->heldCount <= 1)
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
            Super27_DrawHoldMarkers();
        }
        Super27_DrawReels();
        Super27_DrawNumber(s->win, 0xE4, 0x21, 2);
        Super27_DrawNumber(s->coins, 0xE4, 0x4A, 2);
        if (s->unk26 == 1)
        {
            Sprite_Draw(gUnknown_0814EDB8, 0, 0, 0, 0, 8, 4);
            Super27_DrawCards();
            Super27_DrawMarkedCards();
            if (s->unk20 == 0 || (gKeysNew & 0x40))
                s->unk20 = 1;
            if (gKeysNew & 0x80)
                s->unk20 = 2;
            if (s->unk20 == 1)
                Sprite_Draw(gUnknown_0814EC40, 0, 0, 0, 0, 0xA, 0x1B);
            else if (s->unk20 == 2)
                Sprite_Draw(gUnknown_0814EC58, 0, 0, 0, 0, 0xA, 0x43);
            if (s->blink > 20)
            {
                Sprite_Draw(gUnknown_0814EC90, 0, 0, 0, 0, 0x19, 0x2C);
                Sprite_Draw(gUnknown_0814EC80, 0, 0, 0, 0, 0x19, 0x3B);
            }
            if (s->blink > 40)
                s->blink = 0;
        }
        if (s->unk1E == 1)
        {
            Sprite_Draw(gUnknown_0814EDB8, 0, 0, 0, 0, 8, 4);
            Super27_DrawWinHighlight();
            if (s->unk20 == 0 || (gKeysNew & 0x40))
                s->unk20 = 1;
            if (gKeysNew & 0x80)
                s->unk20 = 2;
            if (s->unk20 == 1)
                Sprite_Draw(gUnknown_0814EC40, 0, 0, 0, 0, 0xA, 0x1B);
            else if (s->unk20 == 2)
                Sprite_Draw(gUnknown_0814EC58, 0, 0, 0, 0, 0xA, 0x43);
            if (s->blink > 20)
            {
                Sprite_Draw(gUnknown_0814EC90, 0, 0, 0, 0, 0x19, 0x2C);
                Sprite_Draw(gUnknown_0814EC80, 0, 0, 0, 0, 0x19, 0x3B);
            }
            if (s->blink > 40)
                s->blink = 0;
        }
        s->blink++;
    }
    else if (s->mode == 9)
    {
        Super27_DrawReels();
        Super27_DrawNumber(s->win, 0xE4, 0x21, 2);
        Super27_DrawNumber(s->coins, 0xE4, 0x4A, 2);
        if (s->unk14 <= 5)
        {
            if (s->blink > 3)
                Sprite_Draw(gUnknown_0814EC28, 0, 0, 0, 0, 8, 5);
            if (s->blink > 6)
            {
                s->blink = 0;
                s->unk14++;
            }
            s->blink++;
        }
        else
        {
            sub_080C31FC(s->coins);
            sub_080BE4C4();
        }
    }
}

/* Reel strips: while spinning, recompute each moving reel's six strip indices from its
   position (20 pixels per symbol), then wrap indices past the 24th symbol. */
// Super27_UpdateReelStrips @ 0x08140104
void Super27_UpdateReelStrips(void)
{
    struct Super27 *s = (struct Super27 *)gMenuState;

    if (s->phase != 0 && s->held[0] == 0)
    {
        s->sym[0][0] = s->reelPos[0] / 20;
        s->sym[0][1] = s->reelPos[0] / 20 + 1;
        s->sym[0][2] = s->reelPos[0] / 20 + 2;
        s->sym[0][3] = s->reelPos[0] / 20 + 3;
        s->sym[0][4] = s->reelPos[0] / 20 + 4;
        s->sym[0][5] = s->reelPos[0] / 20 + 5;
    }
    if (s->phase != 0 && s->held[1] == 0)
    {
        s->sym[1][0] = s->reelPos[1] / 20;
        s->sym[1][1] = s->reelPos[1] / 20 + 1;
        s->sym[1][2] = s->reelPos[1] / 20 + 2;
        s->sym[1][3] = s->reelPos[1] / 20 + 3;
        s->sym[1][4] = s->reelPos[1] / 20 + 4;
        s->sym[1][5] = s->reelPos[1] / 20 + 5;
    }
    if (s->phase != 0 && s->held[2] == 0)
    {
        s->sym[2][0] = s->reelPos[2] / 20;
        s->sym[2][1] = s->reelPos[2] / 20 + 1;
        s->sym[2][2] = s->reelPos[2] / 20 + 2;
        s->sym[2][3] = s->reelPos[2] / 20 + 3;
        s->sym[2][4] = s->reelPos[2] / 20 + 4;
        s->sym[2][5] = s->reelPos[2] / 20 + 5;
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
}


/* Draws the six visible symbols of each reel (x 0x44/0x69/0x8E, 20 pixels apart). */
// Super27_DrawReels @ 0x081403C0
void Super27_DrawReels(void)
{
    struct CasinoScene *scene = (struct CasinoScene *)0x0203B554;
    struct Super27 *s = (struct Super27 *)gMenuState;

    Sprite_Draw(gUnknown_0879245C[scene->arg][s->sym[0][5]].sprite, 1, 0, 3, 0, 0x44, (s->reelOfs[0] + 0xFFDC) & 0xFF);
    Sprite_Draw(gUnknown_0879245C[scene->arg][s->sym[0][4]].sprite, 1, 0, 3, 0, 0x44, (s->reelOfs[0] + 0xFFF0) & 0xFF);
    Sprite_Draw(gUnknown_0879245C[scene->arg][s->sym[0][3]].sprite, 1, 0, 3, 0, 0x44, (s->reelOfs[0] + 4) & 0xFF);
    Sprite_Draw(gUnknown_0879245C[scene->arg][s->sym[0][2]].sprite, 1, 0, 3, 0, 0x44, (s->reelOfs[0] + 0x18) & 0xFF);
    Sprite_Draw(gUnknown_0879245C[scene->arg][s->sym[0][1]].sprite, 1, 0, 3, 0, 0x44, (s->reelOfs[0] + 0x2C) & 0xFF);
    Sprite_Draw(gUnknown_0879245C[scene->arg][s->sym[0][0]].sprite, 1, 0, 3, 0, 0x44, (s->reelOfs[0] + 0x40) & 0xFF);
    Sprite_Draw(gUnknown_087931DC[scene->arg][s->sym[1][5]].sprite, 1, 0, 3, 0, 0x69, (s->reelOfs[1] + 0xFFDC) & 0xFF);
    Sprite_Draw(gUnknown_087931DC[scene->arg][s->sym[1][4]].sprite, 1, 0, 3, 0, 0x69, (s->reelOfs[1] + 0xFFF0) & 0xFF);
    Sprite_Draw(gUnknown_087931DC[scene->arg][s->sym[1][3]].sprite, 1, 0, 3, 0, 0x69, (s->reelOfs[1] + 4) & 0xFF);
    Sprite_Draw(gUnknown_087931DC[scene->arg][s->sym[1][2]].sprite, 1, 0, 3, 0, 0x69, (s->reelOfs[1] + 0x18) & 0xFF);
    Sprite_Draw(gUnknown_087931DC[scene->arg][s->sym[1][1]].sprite, 1, 0, 3, 0, 0x69, (s->reelOfs[1] + 0x2C) & 0xFF);
    Sprite_Draw(gUnknown_087931DC[scene->arg][s->sym[1][0]].sprite, 1, 0, 3, 0, 0x69, (s->reelOfs[1] + 0x40) & 0xFF);
    Sprite_Draw(gUnknown_08793F5C[scene->arg][s->sym[2][5]].sprite, 1, 0, 3, 0, 0x8E, (s->reelOfs[2] + 0xFFDC) & 0xFF);
    Sprite_Draw(gUnknown_08793F5C[scene->arg][s->sym[2][4]].sprite, 1, 0, 3, 0, 0x8E, (s->reelOfs[2] + 0xFFF0) & 0xFF);
    Sprite_Draw(gUnknown_08793F5C[scene->arg][s->sym[2][3]].sprite, 1, 0, 3, 0, 0x8E, (s->reelOfs[2] + 4) & 0xFF);
    Sprite_Draw(gUnknown_08793F5C[scene->arg][s->sym[2][2]].sprite, 1, 0, 3, 0, 0x8E, (s->reelOfs[2] + 0x18) & 0xFF);
    Sprite_Draw(gUnknown_08793F5C[scene->arg][s->sym[2][1]].sprite, 1, 0, 3, 0, 0x8E, (s->reelOfs[2] + 0x2C) & 0xFF);
    Sprite_Draw(gUnknown_08793F5C[scene->arg][s->sym[2][0]].sprite, 1, 0, 3, 0, 0x8E, (s->reelOfs[2] + 0x40) & 0xFF);
}

/* Hold markers under the reels: solid for held reels, blinking for the others while fewer
   than two are held. */
// Super27_DrawHoldMarkers @ 0x08140810
void Super27_DrawHoldMarkers(void)
{
    struct Super27 *s = (struct Super27 *)gMenuState;

    if (s->held[0] == 1)
        Sprite_Draw(gUnknown_0814ECA0, 0, 0, 0, 0, 0x44, 0x5B);
    if (s->held[1] == 1)
        Sprite_Draw(gUnknown_0814ECB0, 0, 0, 0, 0, 0x69, 0x5B);
    if (s->held[2] == 1)
        Sprite_Draw(gUnknown_0814ECC0, 0, 0, 0, 0, 0x8F, 0x5B);
    if (s->heldCount < 2)
    {
        if (s->held[0] == 0 && s->unk1C > 10)
            Sprite_Draw(gUnknown_0814ECA0, 0, 0, 0, 0, 0x44, 0x5B);
        if (s->held[1] == 0 && s->unk1C > 10)
            Sprite_Draw(gUnknown_0814ECB0, 0, 0, 0, 0, 0x69, 0x5B);
        if (s->held[2] == 0 && s->unk1C > 10)
            Sprite_Draw(gUnknown_0814ECC0, 0, 0, 0, 0, 0x8F, 0x5B);
        if (s->unk1C > 20)
            s->unk1C = 0;
        s->unk1C++;
    }
}

// Super27_DrawCards @ 0x08140914
void Super27_DrawCards(void)
{
    struct Super27 *s = (struct Super27 *)gMenuState;

    Sprite_Draw(gUnknown_08794D90[s->cards[0].value].sprite, 1, 0, 0, 0, s->scroll + 0x39, 0x5A);
    Sprite_Draw(gUnknown_08794D90[s->cards[1].value].sprite, 1, 0, 0, 0, s->scroll + 0x4E, 0x5A);
    Sprite_Draw(gUnknown_08794D90[s->cards[2].value].sprite, 1, 0, 0, 0, s->scroll + 0x63, 0x5A);
    Sprite_Draw(gUnknown_08794D90[s->cards[3].value].sprite, 1, 0, 0, 0, s->scroll + 0x78, 0x5A);
    Sprite_Draw(gUnknown_08794D90[s->cards[4].value].sprite, 1, 0, 0, 0, s->scroll + 0x8D, 0x5A);
    Sprite_Draw(gUnknown_08794D90[s->cards[5].value].sprite, 1, 0, 0, 0, s->scroll + 0xA2, 0x5A);
}

/* Checks the middle row: the same symbol on all three reels is a win. */
// Super27_CheckMiddleLine @ 0x08140A24
void Super27_CheckMiddleLine(void)
{
    struct CasinoScene *scene = (struct CasinoScene *)0x0203B554;
    struct Super27 *s = (struct Super27 *)gMenuState;
    s32 sym;

    sym = s->lineSym[1] = gUnknown_0879245C[scene->arg][s->sym[0][1]].sym;
    if (sym == gUnknown_087931DC[scene->arg][s->sym[1][1]].sym
        && sym == gUnknown_08793F5C[scene->arg][s->sym[2][1]].sym)
    {
        s->lines[0].index = s->sym[0][1];
        s->lines[1].index = s->sym[1][1];
        s->lines[2].index = s->sym[2][1];
        s->winSym = sym;
        s->lines[2].y = 0x2C;
        s->lines[1].y = 0x2C;
        s->lines[0].y = 0x2C;
        s->unk2A = 1;
        s->unk1E = 1;
        s->line = 2;
        Super27_SetPayout();
    }
}
