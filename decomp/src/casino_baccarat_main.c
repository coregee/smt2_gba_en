/* Baccarat: the per-frame step (0x08145F44). */

#include "global.h"
#include "casino2.h"

extern const u8 gUnknown_0879CA1C[];
extern const u8 gUnknown_0879C91C[];    /* card rank -> points */
extern const u8 gUnknown_08150154[], gUnknown_08150184[], gUnknown_081501C4[];
extern const u8 gUnknown_0815016C[], gUnknown_08150254[], gUnknown_081502E4[];
extern const u8 gUnknown_0815019C[];

void sub_08146EFC(void);
void sub_08146F44(void);
void Baccarat_DrawNumber8(u32 n, u16 x, u16 y, u16 priority);
void Baccarat_DrawNumber3(u32 n, u16 x, u16 y, u16 priority);
void Baccarat_CountUpCoins(void);
void Baccarat_ChangeBet(u8 x, u16 amount, u8 remove);
void sub_081473DC(void);
void sub_0814746C(void);
void sub_08147508(void);
void sub_0814760C(void);
void sub_08147820(void);
void Baccarat_DealCard(void);
void sub_08147970(void);
void Baccarat_ShowResult(void);
void Baccarat_RecordRoad(void);
void Baccarat_DrawRoad(void);

/* bytes of the state not named in struct Baccarat */
#define BYTE(s, off) (((u8 *)(s))[off])
#define LEAVE_BLINKS(s) BYTE(s, 0x23)   /* blinks of the "leave" sign before quitting */
#define TURNING(s) BYTE(s, 0x34)        /* 1 while cards are being turned */
#define CLEARED(s) BYTE(s, 0x37)        /* card slots cleared before a deal */
#define NAT_TIMER(s) BYTE(s, 0x42)      /* blink timer of a natural 8/9 */
#define NAT_COUNT(s) BYTE(s, 0x43)      /* frames the natural is shown */

/* The card positions are signed; the original reads them through s16 fields (a view of
   struct Baccarat with s16 card coordinates). */
struct BaccaratCardPos
{
    u8 suit, rank;
    s16 pos, target, home;
    u16 unk08;
    u8 unk0A, unk0B;
};
struct BaccaratPosView
{
    u8 pad[0x264];
    struct BaccaratCardPos card[6];
};
#define POS(s, i) (((struct BaccaratPosView *)(s))->card[i].pos)
#define TARGET(s, i) (((struct BaccaratPosView *)(s))->card[i].target)
#define HOME(s, i) (((struct BaccaratPosView *)(s))->card[i].home)
#define POINTS(s, i) gUnknown_0879C91C[(s)->card[i].rank]

/* The table: coins and the three bets, the two hand totals (obj[0]: cards 1/3/5, obj[1]:
   cards 0/2/4, frame = total + 1), and the phase machine (s->phase):
     0 wait for the table (then A starts a bet, from 0x18 when cards are still out; B quits)
     1, 2 bet helpers; 3 betting (up/down choose the bet, A/B add/remove 1, or 10 while
       SELECT is held; R deals once the slots are cleared)
     4-6 deal: the cards slide in (6 px a frame) and are turned
     7 which hand the player turns: 8 (3 cards), 9 (4 cards) or 10 (2 cards)
     0xB-0x13 third-card rules (0xC: naturals and the cards 0/2/4 hand, 0x10: the
       cards 1/3/5 hand by its total and the other hand's), 0x15 shows a natural
     0x14 decide and record the result, 0x16 show it, 0x17 count the coins
     0x18, 0x19 collect the cards; 99 leave (the coins are converted back, / 100) */
// Baccarat_Update @ 0x08145F44
void Baccarat_Update(void)
{
    struct Baccarat *s = gBaccarat;
    u8 i;
    s32 bank;

    if (s->state == 1)
    {
        Task_Create(gUnknown_0879CA1C, 0xFFFF);
        s->state = 0;
    }
    Sprite_Draw(gUnknown_08150154, 1, 0, 0, 0, 0xBB, 5);
    Sprite_Draw(gUnknown_08150184, 1, 0, 0, 0, 9, 5);
    Baccarat_DrawNumber8(s->coins, 0x37, 0x39, 0);
    Baccarat_DrawNumber3(s->bet[0], 0xD3, 0x20, 0);
    Baccarat_DrawNumber3(s->bet[1], 0xD3, 0x39, 0);
    Baccarat_DrawNumber3(s->bet[2], 0xD3, 0x52, 0);
    Sprite_Draw(gUnknown_0879C820[s->obj[0].frame], 1, 0, 0, 0, 0x3A, 0x25);
    Sprite_Draw(gUnknown_0879C84C[s->obj[1].frame], 1, 0, 0, 0, 0x3A, 0x4B);
    sub_08146F44();
    if (s->phase <= 3 || s->phase == 0x18 || s->phase == 0x19)
    {
        Sprite_Draw(gUnknown_081501C4, 1, 0, 0, 0, 0x68, 0x3A);
        sub_08146EFC();
    }
    if (s->unk032 == 1)
        Sprite_Draw(gUnknown_081503FC, 1, 0, 0, 0, 8, 4);
    if (TURNING(s) == 1)
        sub_08147508();
    sub_08147970();
    Baccarat_DrawRoad();

    if (s->unk2B8 == 1 && s->phase == 0)
    {
        if (s->unk032 == 0 && (gKeysNew & 0x200))
        {
            Sound_Play(0x158);
            s->phase = 99;
        }
        if (gKeysNew & 0x40)
        {
            if (s->cursor == 0x1E)
                s->cursor = 0x50;
            else
                s->cursor -= 0x19;
        }
        if (gKeysNew & 0x80)
        {
            if (s->cursor == 0x50)
                s->cursor = 0x1E;
            else
                s->cursor += 0x19;
        }
        if (s->coins != 0)
        {
            /* the cards of the last hand are collected first */
            if (POS(s, 0) != TARGET(s, 0))
            {
                if (gUnk_030031D0 & 4)
                {
                    if (gRepeatedKeys & 1)
                    {
                        Sound_Play(0x160);
                        s->phase = 1;
                        Baccarat_ChangeBet(s->cursor, 10, 0);
                    }
                }
                else if (gRepeatedKeys & 1)
                {
                    Sound_Play(0x160);
                    s->phase = 1;
                    Baccarat_ChangeBet(s->cursor, 1, 0);
                }
            }
            else
            {
                if (gUnk_030031D0 & 4)
                {
                    if (gRepeatedKeys & 1)
                    {
                        Sound_Play(0x160);
                        s->phase = 0x18;
                        Baccarat_ChangeBet(s->cursor, 10, 0);
                    }
                }
                else if (gRepeatedKeys & 1)
                {
                    Sound_Play(0x160);
                    s->phase = 0x18;
                    Baccarat_ChangeBet(s->cursor, 1, 0);
                }
            }
        }
    }
    else if (s->phase == 3)
    {
        if ((gKeysNew & 0x100) && CLEARED(s) > 5)
            s->phase = 4;
        if (gKeysNew & 0x40)
        {
            if (s->cursor == 0x1E)
                s->cursor = 0x50;
            else
                s->cursor -= 0x19;
        }
        if (gKeysNew & 0x80)
        {
            if (s->cursor == 0x50)
                s->cursor = 0x1E;
            else
                s->cursor += 0x19;
        }
        if (gUnk_030031D0 & 4)
        {
            if (s->coins > 999 && (gRepeatedKeys & 1))
            {
                Sound_Play(0x160);
                Baccarat_ChangeBet(s->cursor, 10, 0);
            }
            if (gRepeatedKeys & 2)
            {
                Sound_Play(0x160);
                Baccarat_ChangeBet(s->cursor, 10, 1);
                if (s->bet[0] == 0 && s->bet[2] == 0 && s->bet[1] == 0)
                    s->phase = 2;
            }
        }
        else
        {
            if (s->coins > 99 && (gRepeatedKeys & 1))
            {
                Sound_Play(0x160);
                Baccarat_ChangeBet(s->cursor, 1, 0);
            }
            if (gRepeatedKeys & 2)
            {
                Sound_Play(0x160);
                Baccarat_ChangeBet(s->cursor, 1, 1);
                if (s->bet[0] == 0 && s->bet[2] == 0 && s->bet[1] == 0)
                    s->phase = 2;
            }
        }
    }

    switch (s->phase)
    {
    case 0:
        if (s->unk2B9 <= 0x28)
            s->unk2B9++;
        else
            s->unk2B8 = 1;
        break;
    case 1:
        sub_0814746C();
        break;
    case 2:
        sub_081473DC();
        break;
    case 3:
        if (s->unk024 > 12)
            Sprite_Draw(gUnknown_0815016C, 0, 0, 0, 0, 0xBB, 5);
        if (s->unk024 > 24)
            s->unk024 = 0;
        s->unk024++;
        if (CLEARED(s) <= 6)
        {
            for (i = 0; i <= 5; i++)
            {
                s->card[i].unk0A = 1;
                s->card[i].unk0B = 0;
                s->card[i].pos = 0xFC;
                CLEARED(s)++;
            }
        }
        break;
    case 4:
        s->obj[1].frame = 0;
        s->obj[0].frame = 0;
        s->obj[1].unk01 = 0;
        s->obj[0].unk01 = 0;
        TURNING(s) = 1;
        s->phase = 5;
        Sound_Play(0x15A);
        break;
    case 5:
        /* slide the four first cards in, one after the other */
        if (POS(s, 3) == TARGET(s, 3))
        {
            s->unk035 = 0;
            Sound_Play(0x17C);
            s->phase = 6;
            break;
        }
        s->card[s->unk035].unk0A = 1;
        if (POS(s, s->unk035) < TARGET(s, s->unk035))
            break;
        POS(s, s->unk035) -= 6;
        if (POS(s, s->unk035) > TARGET(s, s->unk035))
            break;
        POS(s, s->unk035) = TARGET(s, s->unk035);
        Sound_Play(0x17C);
        s->unk035++;
        break;
    case 6:
        Baccarat_DealCard();
        break;
    case 7:
        if (s->bet[0] != 0)
        {
            if (s->bet[1] != 0)
            {
                s->winner = 0;
                s->unk020 = 1;
            }
            else
                s->winner = 0;
            s->phase = 8;
            break;
        }
        if (s->bet[1] != 0)
        {
            if (s->bet[2] == 0)
            {
                s->winner = 2;
                s->phase = 9;
                break;
            }
        }
        else if (s->bet[2] == 0)
            break;
        if (s->bet[1] != 0)
        {
            s->unk020 = 1;
            s->winner = 1;
        }
        else
            s->winner = 1;
        s->phase = 10;
        break;
    case 8:
        if (s->unk035 != 3)
        {
            sub_0814760C();
            break;
        }
        sub_08147820();
        if ((gKeysNew & 1) || (gKeysNew & 0x100))
            s->phase = 0xB;
        s->obj[1].frame = (POINTS(s, 0) + POINTS(s, 2)) % 10 + 1;
        break;
    case 9:
        if (s->unk035 != 4)
            sub_0814760C();
        else
            s->phase = 0xC;
        if (s->unk035 == 3)
            s->obj[1].frame = (POINTS(s, 0) + POINTS(s, 2)) % 10 + 1;
        break;
    case 10:
        if (s->unk035 != 2)
        {
            sub_0814760C();
            break;
        }
        sub_08147820();
        if ((gKeysNew & 1) || (gKeysNew & 0x100))
            s->phase = 0xB;
        break;
    case 0xB:
        if (s->unk035 != 4)
            sub_0814760C();
        else
            s->phase = 0xC;
        if (s->unk035 == 3)
            s->obj[1].frame = (POINTS(s, 0) + POINTS(s, 2)) % 10 + 1;
        break;
    case 0xC:
        /* naturals (8 or 9: frame > 8), else the cards 0/2/4 hand draws on 0-5 */
        bank = (POINTS(s, 1) + POINTS(s, 3)) % 10 + 1;
        s->obj[0].frame = bank;
        if (s->obj[1].frame > 8 || (s8)bank > 8)
        {
            if ((s8)bank == s->obj[1].frame)
                s->phase = 0x14;
            else
                s->phase = 0x15;
            break;
        }
        if (s->obj[1].frame > 6)
        {
            s->unk035 = 5;
            s->obj[1].unk01 = 5;
            s->phase = 0x11;
            break;
        }
        if (s->obj[1].frame >= 0)
        {
            s->obj[1].unk01 = 4;
            s->phase = 0xD;
        }
        break;
    case 0xD:
        if (POS(s, 4) == TARGET(s, 4))
        {
            s->phase = 0xE;
            break;
        }
        s->card[s->unk035].unk0A = 1;
        if (POS(s, s->unk035) < TARGET(s, s->unk035))
            break;
        POS(s, s->unk035) -= 6;
        if (POS(s, s->unk035) > TARGET(s, s->unk035))
            break;
        POS(s, s->unk035) = TARGET(s, s->unk035);
        Sound_Play(0x17C);
        break;
    case 0xE:
        sub_08147820();
        if ((gKeysNew & 1) || (gKeysNew & 0x100))
            s->phase = 0xF;
        break;
    case 0xF:
        if (s->unk035 != 4)
            s->phase = 0x10;
        else
            sub_0814760C();
        break;
    case 0x10:
        /* the cards 1/3/5 hand draws by its total and the other hand's */
        s->obj[1].frame = (POINTS(s, 0) + POINTS(s, 2) + POINTS(s, 4)) % 10 + 1;
        switch ((s8)(s->obj[0].frame - 1))
        {
        case 0:
            s->obj[0].unk01 = 4;
            s->phase = 0x11;
            break;
        case 1:
            s->obj[0].unk01 = 4;
            s->phase = 0x11;
            break;
        case 2:
            s->obj[0].unk01 = 4;
            s->phase = 0x11;
            break;
        case 3:
            if (s->obj[1].frame <= 8)
            {
                s->obj[0].unk01 = 4;
                s->phase = 0x11;
                break;
            }
            s->obj[0].unk01 = 5;
            s->phase = 0x14;
            break;
        case 4:
            if (s->obj[1].frame >= 3 && s->obj[1].frame <= 8)
            {
                s->obj[0].unk01 = 4;
                s->phase = 0x11;
                break;
            }
            s->phase = 0x14;
            break;
        case 5:
            if (s->obj[1].frame >= 5 && s->obj[1].frame <= 8)
            {
                s->obj[0].unk01 = 4;
                s->phase = 0x11;
                break;
            }
            s->obj[0].unk01 = 5;
            s->phase = 0x14;
            break;
        case 6:
            if (s->obj[1].frame >= 7 && s->obj[1].frame <= 8)
            {
                s->obj[0].unk01 = 4;
                s->phase = 0x11;
                break;
            }
            s->obj[0].unk01 = 5;
            s->phase = 0x14;
            break;
        case 7:
            s->obj[0].unk01 = 5;
            s->phase = 0x14;
            break;
        case 8:
        case 9:
            s->phase = 0x15;
            break;
        }
        break;
    case 0x11:
        if (POS(s, 5) == TARGET(s, 5))
        {
            s->phase = 0x12;
            break;
        }
        s->card[s->unk035].unk0A = 1;
        if (POS(s, s->unk035) < TARGET(s, s->unk035))
            break;
        POS(s, s->unk035) -= 6;
        if (POS(s, s->unk035) > TARGET(s, s->unk035))
            break;
        POS(s, s->unk035) = TARGET(s, s->unk035);
        Sound_Play(0x17C);
        break;
    case 0x12:
        sub_08147820();
        if ((gKeysNew & 1) || (gKeysNew & 0x100))
            s->phase = 0x13;
        break;
    case 0x13:
        if (s->unk035 == 5)
        {
            sub_0814760C();
            break;
        }
        s->obj[0].frame = (POINTS(s, 1) + POINTS(s, 3) + POINTS(s, 5)) % 10 + 1;
        s->phase = 0x14;
        break;
    case 0x14:
        Baccarat_RecordRoad();
        if (s->obj[0].frame > s->obj[1].frame)
        {
            s->obj[0].unk01 = 1;
            s->obj[1].unk01 = 2;
            if (s->winner == 0)
            {
                s->result = 1;
                s->phase = 0x16;
                break;
            }
            else
            {
                s->result = 2;
                s->phase = 0x16;
                break;
            }
        }
        else if (s->obj[0].frame < s->obj[1].frame)
        {
            s->obj[0].unk01 = 2;
            s->obj[1].unk01 = 1;
            if (s->winner == 1)
            {
                s->result = 1;
                s->phase = 0x16;
                break;
            }
            else
            {
                s->result = 2;
                s->phase = 0x16;
                break;
            }
        }
        else if (s->obj[0].frame == s->obj[1].frame)
        {
            s->obj[1].unk01 = 3;
            s->obj[0].unk01 = 3;
            s->result = 3;
                s->phase = 0x16;
                break;
        }
        else
            break;
        break;
    case 0x15:
        /* blink the natural hand(s) for 0x54 frames */
        if (s->obj[0].frame > 8)
        {
            if (NAT_TIMER(s) < 12)
                Sprite_Draw(gUnknown_08150254, 0, 0, 0, 0, 4, 0x24);
            else
                Sprite_Draw(gUnknown_081502E4, 0, 0, 0, 0, 4, 0x24);
            if (NAT_TIMER(s) > 24)
                NAT_TIMER(s) = 0;
        }
        if (s->obj[1].frame > 8)
        {
            if (NAT_TIMER(s) < 12)
                Sprite_Draw(gUnknown_08150254, 0, 0, 0, 0, 4, 0x4A);
            else
                Sprite_Draw(gUnknown_081502E4, 0, 0, 0, 0, 4, 0x4A);
            if (NAT_TIMER(s) > 24)
                NAT_TIMER(s) = 0;
        }
        if (NAT_COUNT(s) == 0x54)
        {
            NAT_COUNT(s) = 0;
            Sound_Play(0x181);
            s->phase = 0x14;
            break;
        }
        NAT_TIMER(s)++;
        NAT_COUNT(s)++;
        break;
    case 0x16:
        Baccarat_ShowResult();
        break;
    case 0x17:
        Baccarat_CountUpCoins();
        break;
    case 0x18:
        /* gather the turned cards back to their stack position */
        for (i = 2; i <= 5; i++)
        {
            if (s->card[i].unk0B == 1)
            {
                if (POS(s, i) != HOME(s, i))
                    POS(s, i) -= 2;
                if (POS(s, s->unk035 - 1) == HOME(s, i))
                    s->phase = 0x19;
            }
        }
        if (s->unk024 > 12)
            Sprite_Draw(gUnknown_0815016C, 0, 0, 0, 0, 0xBB, 5);
        if (s->unk024 > 24)
            s->unk024 = 0;
        s->unk024++;
        break;
    case 0x19:
        /* and off the table */
        for (i = 0; i <= 5; i++)
        {
            if (s->card[i].unk0B == 1)
            {
                if (POS(s, i) >= -0x1E)
                    POS(s, i) -= 4;
                if (POS(s, s->unk035 - 1) <= -0x1E)
                {
                    s->unk035 = 0;
                    CLEARED(s) = 0;
                    s->phase = 1;
                }
            }
        }
        if (s->unk024 > 12)
            Sprite_Draw(gUnknown_0815016C, 0, 0, 0, 0, 0xBB, 5);
        if (s->unk024 > 24)
            s->unk024 = 0;
        s->unk024++;
        break;
    case 99:
        if (LEAVE_BLINKS(s) <= 5)
        {
            if (s->unk024 > 3)
                Sprite_Draw(gUnknown_0815019C, 0, 0, 0, 0, 9, 5);
            if (s->unk024 > 6)
            {
                s->unk024 = 0;
                LEAVE_BLINKS(s)++;
            }
            s->unk024++;
            break;
        }
        sub_080C31FC(s->coins / 100);
        sub_080BE4C4();
        break;
    }
}
