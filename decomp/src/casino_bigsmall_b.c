/* Casino minigame started by 0x08149BBC: main loop (0x08149C7C). Each play costs 10
   coins; a won guess doubles the stake (big = card 5 and up, small = card 0-4). */

#include "global.h"
#include "casino2.h"

// BigSmall_Update @ 0x08149C7C
void BigSmall_Update(void)
{
    struct C145Game5 *s = gGame5;
    u16 i;

    if (s->state == 1)
    {
        Task_Create(gUnknown_0879E354, 0xFFFF);
        s->state = 0;
    }
    if (s->unk01B == 0)
    {
        Sprite_Draw(gUnknown_0814F824, 1, 0, 0, 0, 0xBB, 5);
        Sprite_Draw(gUnknown_0814F7F4, 1, 0, 0, 0, 9, 5);
    }
    else
    {
        Sprite_Draw(gUnknown_0814F888, 1, 0, 0, 0, 0xBB, 5);
        Sprite_Draw(gUnknown_0814F858, 1, 0, 0, 0, 9, 5);
    }
    BigSmall_DrawNumber6(s->shown, 0x30, 0x21, 0);
    BigSmall_DrawNumber6(s->coins, 0xE3, 0x21, 0);
    Sprite_Draw(gUnknown_0879DDFC[s->card], 0, 0, 0, 0, 0x4B, 0x1A);
    if (s->unk018 == 1 || s->unk019 == 1)
        sub_0814A1FC();
    if (s->unk018 == 2)
        Sprite_Draw(gUnknown_0814F790, 0, 0, 0, 0, 0x82, 0x19);
    else if (s->unk019 == 2)
        Sprite_Draw(gUnknown_0814F7A8, 0, 0, 0, 0, 0x82, 0x38);
    if (s->unk026 == 1)
        Sprite_Draw(gUnknown_0814F958, 0, 0, 0, 0, 0xBA, 5);
    if (s->unk027 == 1)
        Sprite_Draw(gUnknown_0814F958, 0, 0, 0, 0, 7, 5);
    sub_0814A8B0();
    sub_0814AA04();
    if (s->unk264 == 1 && s->phase == 0)
    {
        if (gKeysNew & 0x100)
        {
            s->unk00C = 0;
            s->unk05C = 0;
            s->unk05A = 0;
            if (s->unk01B == 0 && s->coins > 9)
            {
                s->phase = 4;
                s->coins -= 10;
                s->shown = s->target = 10;
            }
            else if (s->unk01B == 1)
            {
                s->phase = 4;
            }
            if (s->pickBig == 1)
                s->unk018 = 2;
            else if (s->pickSmall == 1)
                s->unk019 = 2;
        }
        if (gKeysNew & 0x200)
        {
            if (s->unk01B == 0)
            {
                Sound_Play(0x158);
                s->phase = 10;
            }
            else
            {
                s->phase = 9;
            }
        }
        if ((gKeysNew & 0x40) && s->pickBig == 0)
        {
            s->pickBig = 1;
            s->unk018 = 2;
            s->pickSmall = 0;
            s->unk019 = 0;
        }
        if ((gKeysNew & 0x80) && s->pickSmall == 0)
        {
            s->pickSmall = 1;
            s->unk019 = 2;
            s->pickBig = 0;
            s->unk018 = 0;
        }
    }
    switch (s->phase)
    {
    case 0:
        if (s->unk01B == 0)
        {
            if (s->unk00A > 20)
            {
                Sprite_Draw(gUnknown_0814F83C, 0, 0, 0, 0, 0xBB, 5);
                if (s->unk00A > 40)
                {
                    s->unk00A = 0;
                    if (s->unk264 == 0)
                        s->unk264 = 1;
                }
            }
        }
        else if (s->unk00A > 20)
        {
            Sprite_Draw(gUnknown_0814F8A0, 0, 0, 0, 0, 0xBB, 5);
            if (s->unk00A > 40)
                s->unk00A = 0;
        }
        if (s->unk014 > 10)
        {
            Sprite_Draw(gUnknown_0814F768, 0, 0, 0, 0, 0x92, 0x25);
            Sprite_Draw(gUnknown_0814F778, 0, 0, 0, 0, 0x92, 0x31);
            if (s->unk014 > 20)
                s->unk014 = 0;
        }
        s->unk00A++;
        s->unk014++;
        break;
    case 4:
        if (s->unk027 == 0)
            sub_0814A684();
        else
        {
            s->phase = 1;
            s->unk022 = 0;
        }
        break;
    case 5:
        if (s->unk025 == 0)
            sub_0814A568();
        else
        {
            s->phase = 8;
            s->unk01E = 0;
        }
        break;
    case 7:
        if (s->streak == 99 || s->streak == 1)
        {
            if (s->unk027 == 0)
            {
                sub_0814A684();
                sub_0814A5F0();
            }
            else
            {
                s->phase = 6;
                s->unk022 = 0;
                if (s->unk01B == 0)
                    s->unk01B = 1;
                else
                    s->unk01B = 0;
                if (s->streak == 99)
                {
                    for (i = 0; i < 10; i++)
                        s->unk04A[i] = 0;
                }
            }
        }
        else
        {
            s->phase = 6;
        }
        break;
    case 6:
        if (s->streak == 99 || s->streak == 1)
        {
            if (s->unk025 == 0)
            {
                sub_0814A568();
                sub_0814A4DC();
            }
            else
            {
                s->phase = 0;
                s->unk01E = 0;
                if (s->streak != 1)
                    s->streak = 0;
            }
        }
        else
        {
            s->phase = 0;
        }
        break;
    case 1:
        switch (s->unk010)
        {
        case 0:
            if (s->timer <= 5)
            {
                if (s->unk00E > s->unk00F)
                {
                    BigSmall_NextNumber();
                    s->unk00E = 0;
                    s->unk00F--;
                    Sound_Play(0x15A);
                }
                s->unk00E++;
            }
            else
            {
                s->unk010 = 1;
            }
            break;
        case 1:
            if (s->timer <= 0x50)
            {
                if (s->unk00E > 1)
                {
                    BigSmall_NextNumber();
                    s->unk00E = 0;
                    Sound_Play(0x15A);
                }
                s->unk00E++;
            }
            else
            {
                s->unk010 = 2;
            }
            break;
        case 2:
            if (s->timer <= 0x5A)
            {
                if (s->unk00E > s->unk00F)
                {
                    BigSmall_NextNumber();
                    s->unk00E = 0;
                    s->unk00F++;
                    Sound_Play(0x15A);
                }
                s->unk00E++;
            }
            else
            {
                BigSmall_AddResult();
                s->unk00F = 8;
                s->timer = 0;
                s->phase = 2;
            }
            break;
        }
        break;
    case 2:
        s->unk010 = 0;
        s->phase = 5;
        if (s->card > 4)
        {
            if (s->pickBig == 1)
            {
                s->streak++;
                s->target <<= 1;
            }
            else if (s->unk01B == 0)
                s->streak = 0;
            else
                s->streak = 99;
        }
        else
        {
            if (s->pickSmall == 1)
            {
                s->streak++;
                s->target <<= 1;
            }
            else
            {
                if (s->unk01B != 0)
                    s->streak = 99;
                else
                    s->streak = 0;
            }
        }
        if (s->pickBig == 1)
            s->unk018 = 1;
        else if (s->pickSmall == 1)
            s->unk019 = 1;
        break;
    case 8:
        sub_0814A718();
        break;
    case 3:
        BigSmall_CountUpCoins();
        break;
    case 9:
        if (s->unk00C <= 5)
        {
            if (s->unk00A > 3)
                Sprite_Draw(gUnknown_0814F870, 0, 0, 0, 0, 9, 5);
            if (s->unk00A > 6)
            {
                s->unk00A = 0;
                s->unk00C++;
            }
            s->unk00A++;
        }
        else
        {
            sub_0814A414();
        }
        break;
    case 10:
        if (s->unk00C <= 5)
        {
            if (s->unk00A > 3)
                Sprite_Draw(gUnknown_0814F80C, 0, 0, 0, 0, 9, 5);
            if (s->unk00A > 6)
            {
                s->unk00A = 0;
                s->unk00C++;
            }
            s->unk00A++;
        }
        else
        {
            sub_080C31FC(s->coins);
            sub_080BE4C4();
        }
        break;
    }
}
