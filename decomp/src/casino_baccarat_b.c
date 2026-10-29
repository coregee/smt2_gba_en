/* Baccarat: drawing helpers and betting (0x08146EFC-). */

#include "global.h"
#include "casino2.h"

// sub_08146EFC @ 0x08146EFC
void sub_08146EFC(void)
{
    struct Baccarat *s = gBaccarat;

    if (s->unk025 > 12)
        Sprite_Draw(gUnknown_081501DC, 0, 0, 0, 0, 0x68, 0x3A);
    if (s->unk025 > 24)
        s->unk025 = 0;
    s->unk025++;
}

// sub_08146F44 @ 0x08146F44
void sub_08146F44(void)
{
    struct Baccarat *s = gBaccarat;

    if (s->unk026 <= 12)
        Sprite_Draw(gUnknown_081501AC, 1, 0, 0, 0, 0xDD, s->cursor);
    else if (s->unk026 >= 13 && s->unk026 <= 24)
        Sprite_Draw(gUnknown_08150454, 1, 0, 0, 0, 0xDD, s->cursor);
    else if (s->unk026 >= 25 && s->unk026 <= 32)
    {
        Sprite_Draw(gUnknown_08150464, 1, 0, 0, 0, 0xDD, s->cursor);
        s->unk026 = 0;
    }
    s->unk026++;
}

/* Draws an 8-digit number with a thousands separator, right-aligned at x + 0x16. */
// Baccarat_DrawNumber8 @ 0x08146FC8
void Baccarat_DrawNumber8(u32 n, u16 x, u16 y, u16 priority)
{
    u8 *d = NumberToDigits(n);
    const void *const *glyphs = gUnknown_0879C7F4;

    Sprite_Draw(glyphs[d[0]], 0, 0, priority, 0, x + 0x16, y & 0xFF);
    Sprite_Draw(glyphs[d[1]], 0, 0, priority, 0, x + 0xE, y & 0xFF);
    Sprite_Draw(glyphs[10], 0, 0, priority, 0, x + 0xA, y & 0xFF);
    Sprite_Draw(glyphs[d[2]], 0, 0, priority, 0, x, y & 0xFF);
    Sprite_Draw(glyphs[d[3]], 0, 0, priority, 0, x - 8, y & 0xFF);
    Sprite_Draw(glyphs[d[4]], 0, 0, priority, 0, x - 0x10, y & 0xFF);
    Sprite_Draw(glyphs[d[5]], 0, 0, priority, 0, x - 0x18, y & 0xFF);
    Sprite_Draw(glyphs[d[6]], 0, 0, priority, 0, x - 0x20, y & 0xFF);
    Sprite_Draw(glyphs[d[7]], 0, 0, priority, 0, x - 0x28, y & 0xFF);
}

// Baccarat_DrawNumber3 @ 0x08147128
void Baccarat_DrawNumber3(u32 n, u16 x, u16 y, u16 priority)
{
    u8 *d = NumberToDigits(n);
    const void *const *glyphs = gUnknown_0879C7F4;

    Sprite_Draw(glyphs[d[0]], 0, 0, priority, 0, x, y & 0xFF);
    Sprite_Draw(glyphs[d[1]], 0, 0, priority, 0, x - 8, y & 0xFF);
    Sprite_Draw(glyphs[d[2]], 0, 0, priority, 0, x - 0x10, y & 0xFF);
}

/* Counts the coin display up to the new total after a win. */
// Baccarat_CountUpCoins @ 0x081471CC
void Baccarat_CountUpCoins(void)
{
    struct Baccarat *s = gBaccarat;

    if ((gFrameCounter & 3) == 0)
    {
        if (s->coinsTarget != s->coins)
        {
            if (s->coins > 99999899)
            {
                Sound_Play(0x159);
                s->coins = 99999900;
                s->phase = 99;
            }
            else
            {
                if (s->winner == 0)
                    s->coins += 55;
                else
                    s->coins += 500;
                if (s->coinsTarget <= s->coins)
                    s->coins = s->coinsTarget;
            }
        }
        else
        {
            s->coinsTarget = s->coins;
            s->phase = 2;
        }
    }
}

/* Adds (remove = 0) or takes back (remove = 1) `amount` x 100 coins on the bet under the
   cursor (x 0x1E player, 0x37 tie, 0x50 banker); each bet is limited to 100. Player and
   banker exclude each other. */
// Baccarat_ChangeBet @ 0x08147240
void Baccarat_ChangeBet(u8 x, u16 amount, u8 remove)
{
    struct Baccarat *s = gBaccarat;
    u32 flag;
    u32 coins;

    switch (x)
    {
    case 0x1E:
        if (remove == 0 && s->bet[0] < 100 && s->betBanker == 0)
        {
            if (s->bet[0] > 89 && amount == 10)
            {
                s->coins -= (100 - s->bet[0]) * 100;
                s->bet[0] = 100;
            }
            else
            {
                s->bet[0] += amount;
                s->coins -= amount * 100;
            }
            flag = 1;
            goto set_betPlayer;
        }
        else if (remove == 1 && s->bet[0] != 0 && s->betBanker == 0)
        {
            if (s->bet[0] <= 10 && amount == 10)
            {
                s->coins += s->bet[0] * 100;
                s->bet[0] = 0;
            }
            else
            {
                s->bet[0] -= amount;
                s->coins += amount * 100;
            }
            if ((flag = s->bet[0]) == 0)
            {
            set_betPlayer:
                s->betPlayer = flag;
            }
        }
        break;
    case 0x37:
        if (remove == 0 && s->bet[1] < 100)
        {
            if (s->bet[1] > 89 && amount == 10)
            {
                s->coins -= (100 - s->bet[1]) * 100;
                s->bet[1] = 100;
            }
            else
            {
                s->bet[1] += amount;
                coins = s->coins - amount * 100;
                goto set_coins;
            }
        }
        else if (remove == 1 && s->bet[1] != 0)
        {
            if (s->bet[1] <= 10 && amount == 10)
            {
                s->coins += s->bet[1] * 100;
                s->bet[1] = 0;
            }
            else
            {
                s->bet[1] -= amount;
                coins = s->coins + amount * 100;
            set_coins:
                s->coins = coins;
            }
        }
        break;
    case 0x50:
        if (remove == 0 && s->bet[2] < 100 && s->betPlayer == 0)
        {
            if (s->bet[2] > 89 && amount == 10)
            {
                s->coins -= (100 - s->bet[2]) * 100;
                s->bet[2] = 100;
            }
            else
            {
                s->bet[2] += amount;
                s->coins -= amount * 100;
            }
            flag = 1;
            goto set_betBanker;
        }
        else if (remove == 1 && s->bet[2] != 0 && s->betPlayer == 0)
        {
            if (s->bet[2] <= 10 && amount == 10)
            {
                s->coins += s->bet[2] * 100;
                s->bet[2] = 0;
            }
            else
            {
                s->bet[2] -= amount;
                s->coins += amount * 100;
            }
            if ((flag = s->bet[2]) == 0)
            {
            set_betBanker:
                s->betBanker = flag;
            }
        }
        break;
    default:
        return;
    }
    s->coinsTarget = s->coins;
}

// sub_081473DC @ 0x081473DC
void sub_081473DC(void)
{
    struct Baccarat *s = gBaccarat;

    s->unk032 = 0;
    if (s->unk031 <= 3)
        Sprite_Draw(gUnknown_08150414, 1, 0, 0, 0, 8, 4);
    else if (s->unk031 >= 4 && s->unk031 <= 6)
        Sprite_Draw(gUnknown_0815042C, 1, 0, 0, 0, 8, 4);
    else if (s->unk031 >= 7 && s->unk031 <= 9)
        Sprite_Draw(gUnknown_08150444, 1, 0, 0, 0, 8, 4);
    else if (s->unk031 > 9)
    {
        s->unk031 = 0;
        s->unk032 = 0;
        s->phase = 0;
    }
    s->unk031++;
}

// sub_0814746C @ 0x0814746C
void sub_0814746C(void)
{
    struct Baccarat *s = gBaccarat;

    if (s->unk031 <= 3)
        Sprite_Draw(gUnknown_08150444, 1, 0, 0, 0, 8, 4);
    else if (s->unk031 >= 4 && s->unk031 <= 6)
        Sprite_Draw(gUnknown_0815042C, 1, 0, 0, 0, 8, 4);
    else if (s->unk031 >= 7 && s->unk031 <= 9)
        Sprite_Draw(gUnknown_08150414, 1, 0, 0, 0, 8, 4);
    else if (s->unk031 > 9)
    {
        Sprite_Draw(gUnknown_081503FC, 1, 0, 0, 0, 8, 4);
        s->unk031 = 0;
        s->unk032 = 1;
        s->phase = 3;
    }
    s->unk031++;
}

// sub_08147508 @ 0x08147508
void sub_08147508(void)
{
    struct Baccarat *s = gBaccarat;
    u8 i;

    for (i = 0; i < 6; i++)
    {
        if (s->card[i].unk0A == 1)
            Sprite_Draw(gUnknown_08150348, 0, 0, 0, 0, s->card[i].pos, s->card[i].unk08 & 0xFF);
        if (s->card[i].unk0B == 1)
        {
            if (s->card[i].suit == 1 || s->card[i].suit == 3)
                Sprite_Draw(gUnknown_0879C8D4[i], 0, 0, 0, 0, s->card[i].pos, s->card[i].unk08 & 0xFF);
            if (s->card[i].suit == 0 || s->card[i].suit == 2)
                Sprite_Draw(gUnknown_0879C8D4[i], 0, 1, 0, 0, s->card[i].pos, s->card[i].unk08 & 0xFF);
        }
    }
}

/* Turns card unk035 over in six steps of six frames. */
// sub_0814760C @ 0x0814760C
void sub_0814760C(void)
{
    struct Baccarat *s = gBaccarat;

    s->card[s->unk035].unk0A = 0;
    if (s->unk036 <= 6)
        Sprite_Draw(gUnknown_08150348, 0, 0, 0, 0, s->card[s->unk035].pos, s->card[s->unk035].unk08 & 0xFF);
    else if (s->unk036 >= 7 && s->unk036 <= 12)
        Sprite_Draw(gUnknown_08150384, 0, 0, 0, 0, s->card[s->unk035].pos + 8, (s->card[s->unk035].unk08 - 2) & 0xFF);
    else if (s->unk036 >= 13 && s->unk036 <= 18)
        Sprite_Draw(gUnknown_0815039C, 0, 0, 0, 0, s->card[s->unk035].pos + 0xF, (s->card[s->unk035].unk08 - 3) & 0xFF);
    else if (s->unk036 >= 19 && s->unk036 <= 24)
        Sprite_Draw(gUnknown_081503B4, 0, 0, 0, 0, s->card[s->unk035].pos + 0x15, (s->card[s->unk035].unk08 - 9) & 0xFF);
    else if (s->unk036 >= 25 && s->unk036 <= 30)
        Sprite_Draw(gUnknown_081503CC, 0, 0, 0, 0, s->card[s->unk035].pos + 0x18, (s->card[s->unk035].unk08 - 9) & 0xFF);
    else if (s->unk036 >= 31 && s->unk036 <= 36)
        Sprite_Draw(gUnknown_081503E4, 0, 0, 0, 0, s->card[s->unk035].pos + 0xF, (s->card[s->unk035].unk08 - 4) & 0xFF);
    else if (s->unk036 > 36)
    {
        Sound_Play(0x17C);
        s->unk036 = 0;
        s->card[s->unk035].unk0B = 1;
        s->unk035++;
    }
    s->unk036++;
}

// sub_08147820 @ 0x08147820
void sub_08147820(void)
{
    struct Baccarat *s = gBaccarat;

    if (s->unk024 > 12)
    {
        Sprite_Draw(gUnknown_08150360, 0, 0, 0, 0, s->card[s->unk035].pos, s->card[s->unk035].unk08 & 0xFF);
        Sound_Play(0x17E);
    }
    if (s->unk024 > 24)
        s->unk024 = 0;
    s->unk024++;
}

/* Draws a random card that is not already on the table (suit = byte / 85, rank =
   byte * 12 / 255) into the next of the six slots. */
// Baccarat_DealCard @ 0x0814789C
void Baccarat_DealCard(void)
{
    struct Baccarat *s = gBaccarat;
    u16 i;
    s32 t;

    s->duplicate = 0;
    s->suit = Random_Byte() & 0xFF;
    t = s->suit;
    s->suit = t / 85;
    s->rank = Random_Byte() & 0xFF;
    s->rank = s->rank * 12 / 255;
    for (i = 0; i < 6; i++)
    {
        if (s->card[i].suit == s->suit && s->card[i].rank == s->rank)
            s->duplicate = 1;
    }
    if (s->duplicate == 0)
    {
        s->card[s->dealt].suit = s->suit;
        s->card[s->dealt].rank = s->rank;
        Baccarat_SetCardFace(s->dealt, s->card[s->dealt].suit, s->card[s->dealt].rank);
        s->dealt++;
    }
    if (s->dealt == 6)
    {
        s->dealt = 0;
        s->phase = 7;
    }
}

// sub_08147970 @ 0x08147970
void sub_08147970(void)
{
    struct Baccarat *s = gBaccarat;

    switch (s->obj[0].unk01)
    {
    case 1:
        Sprite_Draw(gUnknown_08150284, 1, 0, 0, 0, 4, 0x24);
        break;
    case 2:
        Sprite_Draw(gUnknown_0815029C, 1, 0, 0, 0, 4, 0x24);
        break;
    case 3:
        Sprite_Draw(gUnknown_081502CC, 1, 0, 0, 0, 4, 0x24);
        break;
    case 4:
        Sprite_Draw(gUnknown_081502B4, 1, 0, 0, 0, 4, 0x24);
        break;
    case 5:
        Sprite_Draw(gUnknown_081502FC, 1, 0, 0, 0, 4, 0x24);
        break;
    }
    switch (s->obj[1].unk01)
    {
    case 1:
        Sprite_Draw(gUnknown_08150284, 1, 0, 0, 0, 4, 0x4A);
        break;
    case 2:
        Sprite_Draw(gUnknown_0815029C, 1, 0, 0, 0, 4, 0x4A);
        break;
    case 3:
        Sprite_Draw(gUnknown_081502CC, 1, 0, 0, 0, 4, 0x4A);
        break;
    case 4:
        Sprite_Draw(gUnknown_081502B4, 1, 0, 0, 0, 4, 0x4A);
        break;
    case 5:
        Sprite_Draw(gUnknown_081502FC, 1, 0, 0, 0, 4, 0x4A);
        break;
    }
}

/* Result display and payout. A player win pays bet x 195, a banker win bet x 200, a tie
   bet x 900 plus the player and banker bets back (bets are in units of 100 coins). */
// Baccarat_ShowResult @ 0x08147A90
void Baccarat_ShowResult(void)
{
    struct Baccarat *s = gBaccarat;

    if (s->unk03A == 0 && s->unk03C <= 0xA2)
    {
        s->unk039 = 1;
        if (s->result == 1 || (s->result == 3 && s->unk020 == 1))
            Sound_Play(0x15E);
        else
            Sound_Play(0x163);
    }
    if (s->unk039 == 1 && ++s->unk03A == 20)
        s->unk039 = 0;
    if (s->result == 1 || (s->result == 3 && s->unk020 == 1))
        Sprite_Draw(gUnknown_08150314, 0, 0, 0, 0, s->unk03C - s->unk03E, 0x3F);
    else
        Sprite_Draw(gUnknown_08150330, 0, 0, 0, 0, s->unk03C - s->unk040, 0x3F);
    if (s->result == 1)
    {
        if (s->unk042 > 12)
        {
            if (s->obj[0].unk01 == 1)
                Sprite_Draw(gUnknown_081501F4, 1, 0, 0, 0, 4, 0x24);
            else if (s->obj[1].unk01 == 1)
                Sprite_Draw(gUnknown_081501F4, 1, 0, 0, 0, 4, 0x4A);
        }
        if (s->unk042 > 24)
            s->unk042 = 0;
    }
    else if (s->result == 3)
    {
        if (s->unk042 > 12)
        {
            Sprite_Draw(gUnknown_0815023C, 1, 0, 0, 0, 4, 0x24);
            Sprite_Draw(gUnknown_0815023C, 1, 0, 0, 0, 4, 0x4A);
        }
        if (s->unk042 > 24)
            s->unk042 = 0;
    }
    if (s->unk044 == 0x3D)
    {
        if ((gUnk_0300000C = s->unk248) == 15)
        {
            Baccarat_ScrollRoad();
            gUnk_0300000C -= s->unk248;
            s->unk248 = 0;
            s->unk044 -= 4;
        }
        else
        {
            s->unk248++;
        }
    }
    else if (s->obj[0].frame == s->obj[1].frame)
        sub_08147F68();
    else if (s->obj[0].frame > s->obj[1].frame)
        sub_08147DB8();
    else if (s->obj[0].frame < s->obj[1].frame)
        sub_08147E90();
    if (s->unk03C == 0 && s->unk038 == 1)
    {
        s->unk03C = 0x154;
        s->unk03A = 0;
        s->obj[0].x = 0x3A;
        s->obj[0].y = 0x25;
        s->obj[1].x = 0x3A;
        s->obj[1].y = 0x4B;
        s->obj[2].x = 0x3A;
        s->obj[2].y = 0x4B;
        s->betBanker = 0;
        s->betPlayer = 0;
        s->unk038 = 0;
        if (s->result == 1)
        {
            if (s->winner == 0)
                s->coinsTarget += s->bet[0] * 195;
            else if (s->winner == 1)
                s->coinsTarget += s->bet[2] * 200;
            s->bet[0] = s->bet[1] = s->bet[2] = 0;
            s->unk020 = 0;
            s->phase = 0x17;
        }
        else if (s->result == 3)
        {
            if (s->winner == 2 || s->unk020 == 1)
                s->coinsTarget = s->coinsTarget + s->bet[1] * 900 + (s->bet[0] + s->bet[2]) * 100;
            s->bet[0] = s->bet[1] = s->bet[2] = 0;
            s->unk020 = 0;
            s->phase = 0x17;
        }
        else
        {
            s->bet[0] = s->bet[1] = s->bet[2] = 0;
            s->coinsTarget = s->coins;
            s->unk020 = 0;
            s->phase = 2;
        }
    }
    if (s->unk039 == 0 && s->unk03C != 0)
        s->unk03C -= 4;
    s->unk042++;
}

// sub_08147DB8 @ 0x08147DB8
void sub_08147DB8(void)
{
    struct Baccarat *s = gBaccarat;

    Sprite_Draw(gUnknown_0879C820[s->obj[0].frame], 0, 0, 0, 0, s->obj[0].x, s->obj[0].y & 0xFF);
    if (gUnknown_0879C92C[s->unk044 - 1].x != s->obj[0].x)
    {
        if (gUnknown_0879C92C[s->unk044 - 1].x <= s->obj[0].x)
        {
            s->obj[0].x -= 3;
            if (gUnknown_0879C92C[s->unk044 - 1].x >= s->obj[0].x)
                s->obj[0].x = gUnknown_0879C92C[s->unk044 - 1].x;
        }
        else
        {
            s->obj[0].x += 3;
            if (gUnknown_0879C92C[s->unk044 - 1].x <= s->obj[0].x)
                s->obj[0].x = gUnknown_0879C92C[s->unk044 - 1].x;
        }
    }
    else if (gUnknown_0879C92C[s->unk044 - 1].y >= s->obj[0].y)
    {
        s->obj[0].y += 3;
        if (gUnknown_0879C92C[s->unk044 - 1].y <= s->obj[0].y)
        {
            s->obj[0].y = gUnknown_0879C92C[s->unk044 - 1].y;
            s->rec[s->unk044 - 1].unk00 = 1;
            s->unk038 = 1;
        }
    }
}

// sub_08147E90 @ 0x08147E90
void sub_08147E90(void)
{
    struct Baccarat *s = gBaccarat;

    Sprite_Draw(gUnknown_0879C84C[s->obj[1].frame], 0, 0, 0, 0, s->obj[1].x, s->obj[1].y & 0xFF);
    if (gUnknown_0879C92C[s->unk044 - 1].x != s->obj[1].x)
    {
        if (gUnknown_0879C92C[s->unk044 - 1].x <= s->obj[1].x)
        {
            s->obj[1].x -= 3;
            if (gUnknown_0879C92C[s->unk044 - 1].x >= s->obj[1].x)
                s->obj[1].x = gUnknown_0879C92C[s->unk044 - 1].x;
        }
        else
        {
            s->obj[1].x += 3;
            if (gUnknown_0879C92C[s->unk044 - 1].x <= s->obj[1].x)
                s->obj[1].x = gUnknown_0879C92C[s->unk044 - 1].x;
        }
    }
    else if (gUnknown_0879C92C[s->unk044 - 1].y >= s->obj[1].y)
    {
        s->obj[1].y += 3;
        if (gUnknown_0879C92C[s->unk044 - 1].y <= s->obj[1].y)
        {
            s->obj[1].y = gUnknown_0879C92C[s->unk044 - 1].y;
            s->rec[s->unk044 - 1].unk00 = 1;
            s->unk038 = 1;
        }
    }
}

// sub_08147F68 @ 0x08147F68
void sub_08147F68(void)
{
    struct Baccarat *s = gBaccarat;

    Sprite_Draw(gUnknown_0879C878[22], 0, 0, 0, 0, s->obj[2].x, s->obj[2].y & 0xFF);
    if (gUnknown_0879C92C[s->unk044 - 1].x != s->obj[2].x)
    {
        if (gUnknown_0879C92C[s->unk044 - 1].x <= s->obj[2].x)
        {
            s->obj[2].x -= 3;
            if (gUnknown_0879C92C[s->unk044 - 1].x >= s->obj[2].x)
                s->obj[2].x = gUnknown_0879C92C[s->unk044 - 1].x;
        }
        else
        {
            s->obj[2].x += 3;
            if (gUnknown_0879C92C[s->unk044 - 1].x <= s->obj[2].x)
                s->obj[2].x = gUnknown_0879C92C[s->unk044 - 1].x;
        }
    }
    else if (gUnknown_0879C92C[s->unk044 - 1].y >= s->obj[2].y)
    {
        s->obj[2].y += 3;
        if (gUnknown_0879C92C[s->unk044 - 1].y <= s->obj[2].y)
        {
            s->obj[2].y = gUnknown_0879C92C[s->unk044 - 1].y;
            s->rec[s->unk044 - 1].unk00 = 1;
            s->unk038 = 1;
        }
    }
}

/* Records the hand's result on the score road (rec[].unk04, 4 rows per column): player
   score 0-9, banker score + 11, or 0x16 for a tie. A result that differs from the column's
   starts the next column. */
// Baccarat_RecordRoad @ 0x08148030
void Baccarat_RecordRoad(void)
{
    struct Baccarat *s = gBaccarat;
    s32 k;
    u16 prev;

    if (s->unk044 == 0)
    {
        if (s->obj[0].frame == s->obj[1].frame)
            s->rec[s->unk044].unk04 = 0x16;
        else if (s->obj[0].frame > s->obj[1].frame)
            s->rec[s->unk044].unk04 = s->obj[0].frame;
        else if (s->obj[0].frame < s->obj[1].frame)
            s->rec[s->unk044].unk04 = s->obj[1].frame + 11;
        s->unk044++;
        s->unk046 = 1;
        return;
    }
    if (s->obj[1].frame == s->obj[0].frame)
    {
        s->rec[s->unk044].unk04 = 0x16;
        s->unk044++;
        s->unk046 = 1;
        return;
    }
    k = s->unk044 - s->unk046;
    prev = s->rec[k].unk04;
    if (prev == 0x16)
    {
        if (k - 1 >= 0)
        {
            if (s->rec[k - 1].unk04 > 11)
            {
                if (s->obj[1].frame > s->obj[0].frame)
                {
                    s->rec[s->unk044].unk04 = s->obj[1].frame + 11;
                    s->unk044++;
                    s->unk046 = 1;
                    return;
                }
                switch (s->unk044 & 3)
                {
                case 0:
                    s->rec[s->unk044].unk04 = s->obj[0].frame;
                    s->unk044 += 1;
                    s->unk046 = 1;
                    break;
                case 1:
                    s->rec[s->unk044 + 3].unk04 = s->obj[0].frame;
                    s->unk044 += 4;
                    s->unk046 = 1;
                    break;
                case 2:
                    s->rec[s->unk044 + 2].unk04 = s->obj[0].frame;
                    s->unk044 += 3;
                    s->unk046 = 1;
                    break;
                case 3:
                    s->rec[s->unk044 + 1].unk04 = s->obj[0].frame;
                    s->unk044 += 2;
                    s->unk046 = 1;
                    break;
                }
            }
            else if (s->rec[k - 1].unk04 <= 10)
            {
                if (s->obj[0].frame > s->obj[1].frame)
                {
                    s->rec[s->unk044].unk04 = s->obj[0].frame;
                    s->unk044++;
                    s->unk046 = 1;
                    return;
                }
                switch (s->unk044 & 3)
                {
                case 0:
                    s->rec[s->unk044].unk04 = s->obj[1].frame + 11;
                    s->unk044 += 1;
                    s->unk046 = 1;
                    break;
                case 1:
                    s->rec[s->unk044 + 3].unk04 = s->obj[1].frame + 11;
                    s->unk044 += 4;
                    s->unk046 = 1;
                    break;
                case 2:
                    s->rec[s->unk044 + 2].unk04 = s->obj[1].frame + 11;
                    s->unk044 += 3;
                    s->unk046 = 1;
                    break;
                case 3:
                    s->rec[s->unk044 + 1].unk04 = s->obj[1].frame + 11;
                    s->unk044 += 2;
                    s->unk046 = 1;
                    break;
                }
            }
        }
        else
        {
            if (s->obj[0].frame > s->obj[1].frame)
                s->rec[s->unk044].unk04 = s->obj[0].frame;
            else if (s->obj[0].frame < s->obj[1].frame)
                s->rec[s->unk044].unk04 = s->obj[1].frame + 11;
            else if (s->obj[0].frame == s->obj[1].frame)
                s->rec[s->unk044].unk04 = 0x16;
            s->unk044++;
            s->unk046 = 1;
        }
    }
    else if (prev > 11)
    {
        if (s->obj[1].frame > s->obj[0].frame)
        {
            s->rec[s->unk044].unk04 = s->obj[1].frame + 11;
            s->unk044++;
            s->unk046 = 1;
            return;
        }
        switch (s->unk044 & 3)
        {
        case 0:
            s->rec[s->unk044].unk04 = s->obj[0].frame;
            s->unk044 += 1;
            s->unk046 = 1;
            break;
        case 1:
            s->rec[s->unk044 + 3].unk04 = s->obj[0].frame;
            s->unk044 += 4;
            s->unk046 = 1;
            break;
        case 2:
            s->rec[s->unk044 + 2].unk04 = s->obj[0].frame;
            s->unk044 += 3;
            s->unk046 = 1;
            break;
        case 3:
            s->rec[s->unk044 + 1].unk04 = s->obj[0].frame;
            s->unk044 += 2;
            s->unk046 = 1;
            break;
        }
    }
    else if (prev <= 10)
    {
        if (s->obj[0].frame > s->obj[1].frame)
        {
            s->rec[s->unk044].unk04 = s->obj[0].frame;
            s->unk044++;
            s->unk046 = 1;
            return;
        }
        switch (s->unk044 & 3)
        {
        case 0:
            s->rec[s->unk044].unk04 = s->obj[1].frame + 11;
            s->unk044 += 1;
            s->unk046 = 1;
            break;
        case 1:
            s->rec[s->unk044 + 3].unk04 = s->obj[1].frame + 11;
            s->unk044 += 4;
            s->unk046 = 1;
            break;
        case 2:
            s->rec[s->unk044 + 2].unk04 = s->obj[1].frame + 11;
            s->unk044 += 3;
            s->unk046 = 1;
            break;
        case 3:
            s->rec[s->unk044 + 1].unk04 = s->obj[1].frame + 11;
            s->unk044 += 2;
            s->unk046 = 1;
            break;
        }
    }
}

/* Drops the first column (4 results) of the score road. */
// Baccarat_ScrollRoad @ 0x0814837C
void Baccarat_ScrollRoad(void)
{
    struct Baccarat *s = gBaccarat;
    u16 i;

    for (i = 0; i < 60; i++)
    {
        s->rec[i].unk00 = s->rec[i + 4].unk00;
        s->rec[i].unk04 = s->rec[i + 4].unk04;
    }
}

// Baccarat_DrawRoad @ 0x081483B4
void Baccarat_DrawRoad(void)
{
    struct Baccarat *s = gBaccarat;
    u16 i;

    for (i = 0; i < 60; i++)
    {
        if (s->rec[i].unk00 == 1)
            Sprite_Draw(gUnknown_0879C878[s->rec[i].unk04], 0, 0, 2, 0,
                        gUnknown_0879C92C[i].x - s->unk248, gUnknown_0879C92C[i].y & 0xFF);
    }
}

// sub_08148420 @ 0x08148420
void sub_08148420(u32 unused, u32 state)
{
    gBaccarat->state = state;
}

/* Unpacks the card faces of one suit (0x1200 bytes) to 0x0200F874 + suit * 0x1200. */
// Baccarat_LoadCards @ 0x0814842C
#ifdef NONMATCHING
void Baccarat_LoadCards(u32 unused, u32 suit)
{
    u8 *dest = (u8 *)0x0200F874 + suit * 0x1200;

    HuffUnComp(gBaccaratCardGfx[suit], (void *)0x0200AFC8);
    LZ77UnCompWram((void *)0x0200AFC8, dest);
    gUnk_03003BB4 = 0;
}
#else
NAKED
void Baccarat_LoadCards(u32 unused, u32 suit)
{
    asm_unified(
        "    push {r4, r5, lr}\n"
        "    ldr r5, .L0814845C\n"
        "    lsls r0, r1, #3\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #9\n"
        "    adds r5, r0, r5\n"
        "    ldr r0, .L08148460\n"
        "    lsls r1, r1, #2\n"
        "    adds r1, r1, r0\n"
        "    ldr r0, [r1]\n"
        "    ldr r4, .L08148464\n"
        "    adds r1, r4, #0\n"
        "    bl HuffUnComp\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r5, #0\n"
        "    bl LZ77UnCompWram\n"
        "    ldr r1, .L08148468\n"
        "    movs r0, #0\n"
        "    str r0, [r1]\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L0814845C: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L08148460: .4byte gBaccaratCardGfx\n"
        ".L08148464: .4byte 0x0200AFC8 @ EWRAM+0xAFC8\n"
        ".L08148468: .4byte 0x03003BB4 @ IWRAM+0x3BB4\n"
    );
}
#endif

/* Copies the face of card `slot` (32x40, 20 tiles) to OBJ VRAM. */
// Baccarat_UploadCardFace @ 0x0814846C
#ifdef NONMATCHING
void Baccarat_UploadCardFace(u16 slot)
{
    struct Baccarat *s = gBaccarat;

    DmaSet3((u8 *)0x0200F874 + s->gfxSuit[slot] * 0x2400 + s->gfxRank[slot] * 0x280,
            slot * 0x400 + 0x06014C00, 0x840000A0);
}
#else
NAKED
void Baccarat_UploadCardFace(u16 slot)
{
    asm_unified(
        ".L0814846C:\n"
        "    push {r4, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    ldr r3, .L081484B0\n"
        "    ldr r4, .L081484B4\n"
        "    movs r2, #0xab\n"
        "    lsls r2, r2, #2\n"
        "    adds r1, r3, r2\n"
        "    adds r1, r0, r1\n"
        "    ldrb r1, [r1]\n"
        "    lsls r2, r1, #3\n"
        "    adds r2, r2, r1\n"
        "    lsls r2, r2, #0xa\n"
        "    ldr r1, .L081484B8\n"
        "    adds r3, r3, r1\n"
        "    adds r3, r0, r3\n"
        "    ldrb r3, [r3]\n"
        "    lsls r1, r3, #2\n"
        "    adds r1, r1, r3\n"
        "    lsls r1, r1, #7\n"
        "    adds r2, r2, r1\n"
        "    adds r4, r2, r4\n"
        "    ldr r1, .L081484BC\n"
        "    str r4, [r1]\n"
        "    lsls r0, r0, #0xa\n"
        "    ldr r2, .L081484C0\n"
        "    adds r0, r0, r2\n"
        "    str r0, [r1, #4]\n"
        "    ldr r0, .L081484C4\n"
        "    str r0, [r1, #8]\n"
        "    ldr r0, [r1, #8]\n"
        "    pop {r4}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L081484B0: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L081484B4: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L081484B8: .4byte 0x000002B2\n"
        ".L081484BC: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L081484C0: .4byte 0x06014C00 @ VRAM+0x14C00\n"
        ".L081484C4: .4byte 0x840000A0\n"
    );
}
#endif

// sub_081484C8 @ 0x081484C8
void sub_081484C8(void)
{
    Baccarat_UploadCardFace(0);
}

// sub_081484D4 @ 0x081484D4
void sub_081484D4(void)
{
    Baccarat_UploadCardFace(1);
}

// sub_081484E0 @ 0x081484E0
void sub_081484E0(void)
{
    Baccarat_UploadCardFace(2);
}

// sub_081484EC @ 0x081484EC
void sub_081484EC(void)
{
    Baccarat_UploadCardFace(3);
}

// sub_081484F8 @ 0x081484F8
void sub_081484F8(void)
{
    Baccarat_UploadCardFace(4);
}

// sub_08148504 @ 0x08148504
void sub_08148504(void)
{
    Baccarat_UploadCardFace(5);
}

// Baccarat_SetCardFace @ 0x08148510
void Baccarat_SetCardFace(u16 slot, u32 suit, u32 rank)
{
    struct Baccarat *s = gBaccarat;

    s->gfxSuit[slot] = suit;
    s->gfxRank[slot] = rank;
    switch (slot)
    {
    case 0:
        VBlankTask_AddCounted(sub_081484C8, 1);
        break;
    case 1:
        VBlankTask_AddCounted(sub_081484D4, 1);
        break;
    case 2:
        VBlankTask_AddCounted(sub_081484E0, 1);
        break;
    case 3:
        VBlankTask_AddCounted(sub_081484EC, 1);
        break;
    case 4:
        VBlankTask_AddCounted(sub_081484F8, 1);
        break;
    case 5:
        VBlankTask_AddCounted(sub_08148504, 1);
        break;
    }
}
