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

#define POS(s, i) (*(s16 *)&(s)->card[i].pos)
#define TARGET(s, i) (*(s16 *)&(s)->card[i].target)
#define HOME(s, i) (*(s16 *)&(s)->card[i].unk06)
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
/* NONMATCHING: same phases and rules; the original repeats the A-press and blink code per
   branch where it is merged here (0xE68 bytes against 0xFB8). */
// Baccarat_Update @ 0x08145F44
#ifdef NONMATCHING
void Baccarat_Update(void)
{
    struct Baccarat *s = gBaccarat;
    u8 i;
    s32 bank;
    s8 other;

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
        if (TARGET(s, s->unk035) < POS(s, s->unk035))
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
                s->unk020 = 1;
            s->winner = 0;
            s->phase = 8;
        }
        else if (s->bet[1] != 0 && s->bet[2] == 0)
        {
            s->winner = 2;
            s->phase = 9;
        }
        else if (s->bet[1] == 0 && s->bet[2] == 0)
            break;
        else
        {
            if (s->bet[1] != 0)
                s->unk020 = 1;
            s->winner = 1;
            s->phase = 10;
        }
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
            if ((s8)bank != s->obj[1].frame)
                s->phase = 0x15;
            else
                s->phase = 0x14;
            break;
        }
        if (s->obj[1].frame < 7)
        {
            if (s->obj[1].frame >= 0)
            {
                s->obj[1].unk01 = 4;
                s->phase = 0xD;
            }
            break;
        }
        s->unk035 = 5;
        s->obj[1].unk01 = 5;
        s->phase = 0x11;
        break;
    case 0xD:
        if (POS(s, 4) == TARGET(s, 4))
        {
            s->phase = 0xE;
            break;
        }
        s->card[s->unk035].unk0A = 1;
        goto slide;
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
        other = (POINTS(s, 0) + POINTS(s, 2) + POINTS(s, 4)) % 10;
        s->obj[1].frame = other + 1;
        switch (s->obj[0].frame - 1)
        {
        case 0:
        case 1:
        case 2:
            goto draw;
        case 3:
            if (s->obj[1].frame < 9)
                goto draw;
            s->obj[0].unk01 = 5;
            break;
        case 4:
            if ((u8)(other - 2) < 6)
                goto draw;
            break;
        case 5:
            if ((u8)(other - 4) < 4)
                goto draw;
            s->obj[0].unk01 = 5;
            break;
        case 6:
            if ((u8)(other - 6) < 2)
                goto draw;
            s->obj[0].unk01 = 5;
            break;
        case 7:
            s->obj[0].unk01 = 5;
            break;
        case 8:
        case 9:
            s->phase = 0x15;
            return;
        default:
            return;
        }
        s->phase = 0x14;
        break;
    draw:
        s->obj[0].unk01 = 4;
        s->phase = 0x11;
        break;
    case 0x11:
        if (POS(s, 5) == TARGET(s, 5))
        {
            s->phase = 0x12;
            break;
        }
        s->card[s->unk035].unk0A = 1;
    slide:
        if (TARGET(s, s->unk035) <= POS(s, s->unk035))
        {
            POS(s, s->unk035) -= 6;
            if (POS(s, s->unk035) <= TARGET(s, s->unk035))
            {
                POS(s, s->unk035) = TARGET(s, s->unk035);
                Sound_Play(0x17C);
            }
        }
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
        if (s->obj[1].frame < s->obj[0].frame)
        {
            s->obj[0].unk01 = 1;
            s->result = 2;
            s->obj[1].unk01 = 2;
            if (s->winner == 0)
                s->result = 1;
        }
        else if (s->obj[0].frame < s->obj[1].frame)
        {
            s->obj[0].unk01 = 2;
            s->obj[1].unk01 = 1;
            if (s->winner == 1)
                s->result = 1;
            else
                s->result = 2;
        }
        else if (s->obj[0].frame == s->obj[1].frame)
        {
            s->result = 3;
            s->obj[1].unk01 = 3;
            s->obj[0].unk01 = 3;
        }
        else
            break;
        s->phase = 0x16;
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
        if (LEAVE_BLINKS(s) > 5)
        {
            sub_080C31FC(s->coins / 100);
            sub_080BE4C4();
            break;
        }
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
}
#else
NAKED
void Baccarat_Update(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0xc\n"
        "    ldr r6, .L081460C4\n"
        "    ldrh r0, [r6]\n"
        "    cmp r0, #1\n"
        "    bne .L08145F64\n"
        "    ldr r0, .L081460C8\n"
        "    ldr r1, .L081460CC\n"
        "    bl Task_Create\n"
        "    movs r0, #0\n"
        "    strh r0, [r6]\n"
        ".L08145F64:\n"
        "    ldr r0, .L081460D0\n"
        "    movs r5, #0\n"
        "    str r5, [sp]\n"
        "    movs r1, #0xbb\n"
        "    str r1, [sp, #4]\n"
        "    movs r4, #5\n"
        "    str r4, [sp, #8]\n"
        "    movs r1, #1\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    ldr r0, .L081460D4\n"
        "    str r5, [sp]\n"
        "    movs r1, #9\n"
        "    str r1, [sp, #4]\n"
        "    str r4, [sp, #8]\n"
        "    movs r1, #1\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    ldr r0, [r6, #8]\n"
        "    movs r1, #0x37\n"
        "    movs r2, #0x39\n"
        "    movs r3, #0\n"
        "    bl Baccarat_DrawNumber8\n"
        "    ldr r0, [r6, #0x10]\n"
        "    movs r1, #0xd3\n"
        "    movs r2, #0x20\n"
        "    movs r3, #0\n"
        "    bl Baccarat_DrawNumber3\n"
        "    ldr r0, [r6, #0x14]\n"
        "    movs r1, #0xd3\n"
        "    movs r2, #0x39\n"
        "    movs r3, #0\n"
        "    bl Baccarat_DrawNumber3\n"
        "    ldr r0, [r6, #0x18]\n"
        "    movs r1, #0xd3\n"
        "    movs r2, #0x52\n"
        "    movs r3, #0\n"
        "    bl Baccarat_DrawNumber3\n"
        "    ldr r1, .L081460D8\n"
        "    movs r2, #0x93\n"
        "    lsls r2, r2, #2\n"
        "    adds r0, r6, r2\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    str r5, [sp]\n"
        "    movs r4, #0x3a\n"
        "    str r4, [sp, #4]\n"
        "    movs r1, #0x25\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #1\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    ldr r1, .L081460DC\n"
        "    movs r3, #0x95\n"
        "    lsls r3, r3, #2\n"
        "    adds r0, r6, r3\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    str r5, [sp]\n"
        "    str r4, [sp, #4]\n"
        "    movs r1, #0x4b\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #1\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    bl sub_08146F44\n"
        "    ldrb r0, [r6, #4]\n"
        "    cmp r0, #3\n"
        "    bls .L08146020\n"
        "    cmp r0, #0x18\n"
        "    beq .L08146020\n"
        "    cmp r0, #0x19\n"
        "    bne .L0814603C\n"
        ".L08146020:\n"
        "    ldr r0, .L081460E0\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    movs r1, #0x68\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #0x3a\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #1\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    bl sub_08146EFC\n"
        ".L0814603C:\n"
        "    adds r4, r6, #0\n"
        "    adds r4, #0x32\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #1\n"
        "    bne .L0814605E\n"
        "    ldr r0, .L081460E4\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    movs r1, #8\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #4\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #1\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L0814605E:\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x34\n"
        "    ldrb r1, [r0]\n"
        "    adds r5, r0, #0\n"
        "    cmp r1, #1\n"
        "    bne .L0814606E\n"
        "    bl sub_08147508\n"
        ".L0814606E:\n"
        "    bl sub_08147970\n"
        "    bl Baccarat_DrawRoad\n"
        "    movs r7, #0xae\n"
        "    lsls r7, r7, #2\n"
        "    adds r0, r6, r7\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #1\n"
        "    beq .L08146084\n"
        "    b .L081461E0\n"
        ".L08146084:\n"
        "    ldrb r0, [r6, #4]\n"
        "    cmp r0, #0\n"
        "    beq .L0814608C\n"
        "    b .L081461E0\n"
        ".L0814608C:\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #0\n"
        "    bne .L081460AC\n"
        "    ldr r0, .L081460E8\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L081460AC\n"
        "    movs r0, #0xac\n"
        "    lsls r0, r0, #1\n"
        "    bl Sound_Play\n"
        "    movs r0, #0x63\n"
        "    strb r0, [r6, #4]\n"
        ".L081460AC:\n"
        "    ldr r2, .L081460E8\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #0x40\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L081460F0\n"
        "    ldrb r0, [r6, #0x1c]\n"
        "    cmp r0, #0x1e\n"
        "    bne .L081460EC\n"
        "    movs r0, #0x50\n"
        "    b .L081460EE\n"
        "    .byte 0x00, 0x00\n"
        ".L081460C4: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L081460C8: .4byte gUnknown_0879CA1C\n"
        ".L081460CC: .4byte 0x0000FFFF\n"
        ".L081460D0: .4byte gUnknown_08150154\n"
        ".L081460D4: .4byte gUnknown_08150184\n"
        ".L081460D8: .4byte gUnknown_0879C820\n"
        ".L081460DC: .4byte gUnknown_0879C84C\n"
        ".L081460E0: .4byte gUnknown_081501C4\n"
        ".L081460E4: .4byte gUnknown_081503FC\n"
        ".L081460E8: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L081460EC:\n"
        "    subs r0, #0x19\n"
        ".L081460EE:\n"
        "    strb r0, [r6, #0x1c]\n"
        ".L081460F0:\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #0x80\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08146108\n"
        "    ldrb r0, [r6, #0x1c]\n"
        "    cmp r0, #0x50\n"
        "    bne .L08146104\n"
        "    movs r0, #0x1e\n"
        "    b .L08146106\n"
        ".L08146104:\n"
        "    adds r0, #0x19\n"
        ".L08146106:\n"
        "    strb r0, [r6, #0x1c]\n"
        ".L08146108:\n"
        "    ldr r0, [r6, #8]\n"
        "    cmp r0, #0\n"
        "    bne .L08146110\n"
        "    b .L081462E8\n"
        ".L08146110:\n"
        "    ldr r1, .L08146154\n"
        "    adds r0, r6, r1\n"
        "    movs r2, #0x9a\n"
        "    lsls r2, r2, #2\n"
        "    adds r1, r6, r2\n"
        "    movs r3, #0\n"
        "    ldrsh r2, [r0, r3]\n"
        "    movs r4, #0\n"
        "    ldrsh r0, [r1, r4]\n"
        "    cmp r2, r0\n"
        "    beq .L08146180\n"
        "    ldr r0, .L08146158\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #4\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08146160\n"
        "    ldr r0, .L0814615C\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L08146140\n"
        "    b .L081462E8\n"
        ".L08146140:\n"
        "    movs r0, #0xb0\n"
        "    lsls r0, r0, #1\n"
        "    bl Sound_Play\n"
        "    movs r0, #1\n"
        "    strb r0, [r6, #4]\n"
        "    ldrb r0, [r6, #0x1c]\n"
        "    movs r1, #0xa\n"
        "    b .L081461D2\n"
        "    .byte 0x00, 0x00\n"
        ".L08146154: .4byte 0x00000266\n"
        ".L08146158: .4byte 0x030031D0 @ IWRAM+0x31D0\n"
        ".L0814615C: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L08146160:\n"
        "    ldr r0, .L0814617C\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L0814616E\n"
        "    b .L081462E8\n"
        ".L0814616E:\n"
        "    movs r0, #0xb0\n"
        "    lsls r0, r0, #1\n"
        "    bl Sound_Play\n"
        "    movs r0, #1\n"
        "    b .L081461CC\n"
        "    .byte 0x00, 0x00\n"
        ".L0814617C: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L08146180:\n"
        "    ldr r0, .L081461AC\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #4\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L081461B4\n"
        "    ldr r0, .L081461B0\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L0814619A\n"
        "    b .L081462E8\n"
        ".L0814619A:\n"
        "    movs r0, #0xb0\n"
        "    lsls r0, r0, #1\n"
        "    bl Sound_Play\n"
        "    movs r0, #0x18\n"
        "    strb r0, [r6, #4]\n"
        "    ldrb r0, [r6, #0x1c]\n"
        "    movs r1, #0xa\n"
        "    b .L081461D2\n"
        ".L081461AC: .4byte 0x030031D0 @ IWRAM+0x31D0\n"
        ".L081461B0: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L081461B4:\n"
        "    ldr r0, .L081461DC\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L081461C2\n"
        "    b .L081462E8\n"
        ".L081461C2:\n"
        "    movs r0, #0xb0\n"
        "    lsls r0, r0, #1\n"
        "    bl Sound_Play\n"
        "    movs r0, #0x18\n"
        ".L081461CC:\n"
        "    strb r0, [r6, #4]\n"
        "    ldrb r0, [r6, #0x1c]\n"
        "    movs r1, #1\n"
        ".L081461D2:\n"
        "    movs r2, #0\n"
        "    bl Baccarat_ChangeBet\n"
        "    b .L081462E8\n"
        "    .byte 0x00, 0x00\n"
        ".L081461DC: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L081461E0:\n"
        "    ldrb r0, [r6, #4]\n"
        "    cmp r0, #3\n"
        "    beq .L081461E8\n"
        "    b .L081462E8\n"
        ".L081461E8:\n"
        "    ldr r2, .L08146218\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08146204\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x37\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #5\n"
        "    bls .L08146204\n"
        "    movs r0, #4\n"
        "    strb r0, [r6, #4]\n"
        ".L08146204:\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #0x40\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08146220\n"
        "    ldrb r0, [r6, #0x1c]\n"
        "    cmp r0, #0x1e\n"
        "    bne .L0814621C\n"
        "    movs r0, #0x50\n"
        "    b .L0814621E\n"
        ".L08146218: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L0814621C:\n"
        "    subs r0, #0x19\n"
        ".L0814621E:\n"
        "    strb r0, [r6, #0x1c]\n"
        ".L08146220:\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #0x80\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08146238\n"
        "    ldrb r0, [r6, #0x1c]\n"
        "    cmp r0, #0x50\n"
        "    bne .L08146234\n"
        "    movs r0, #0x1e\n"
        "    b .L08146236\n"
        ".L08146234:\n"
        "    adds r0, #0x19\n"
        ".L08146236:\n"
        "    strb r0, [r6, #0x1c]\n"
        ".L08146238:\n"
        "    ldr r0, .L08146284\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #4\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08146290\n"
        "    ldr r1, [r6, #8]\n"
        "    ldr r0, .L08146288\n"
        "    cmp r1, r0\n"
        "    bls .L0814626A\n"
        "    ldr r0, .L0814628C\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L0814626A\n"
        "    movs r0, #0xb0\n"
        "    lsls r0, r0, #1\n"
        "    bl Sound_Play\n"
        "    ldrb r0, [r6, #0x1c]\n"
        "    movs r1, #0xa\n"
        "    movs r2, #0\n"
        "    bl Baccarat_ChangeBet\n"
        ".L0814626A:\n"
        "    ldr r0, .L0814628C\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L081462E8\n"
        "    movs r0, #0xb0\n"
        "    lsls r0, r0, #1\n"
        "    bl Sound_Play\n"
        "    ldrb r0, [r6, #0x1c]\n"
        "    movs r1, #0xa\n"
        "    b .L081462CC\n"
        ".L08146284: .4byte 0x030031D0 @ IWRAM+0x31D0\n"
        ".L08146288: .4byte 0x000003E7\n"
        ".L0814628C: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L08146290:\n"
        "    ldr r0, [r6, #8]\n"
        "    cmp r0, #0x63\n"
        "    bls .L081462B4\n"
        "    ldr r0, .L081462FC\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L081462B4\n"
        "    movs r0, #0xb0\n"
        "    lsls r0, r0, #1\n"
        "    bl Sound_Play\n"
        "    ldrb r0, [r6, #0x1c]\n"
        "    movs r1, #1\n"
        "    movs r2, #0\n"
        "    bl Baccarat_ChangeBet\n"
        ".L081462B4:\n"
        "    ldr r0, .L081462FC\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L081462E8\n"
        "    movs r0, #0xb0\n"
        "    lsls r0, r0, #1\n"
        "    bl Sound_Play\n"
        "    ldrb r0, [r6, #0x1c]\n"
        "    movs r1, #1\n"
        ".L081462CC:\n"
        "    movs r2, #1\n"
        "    bl Baccarat_ChangeBet\n"
        "    ldr r0, [r6, #0x10]\n"
        "    cmp r0, #0\n"
        "    bne .L081462E8\n"
        "    ldr r0, [r6, #0x18]\n"
        "    cmp r0, #0\n"
        "    bne .L081462E8\n"
        "    ldr r0, [r6, #0x14]\n"
        "    cmp r0, #0\n"
        "    bne .L081462E8\n"
        "    movs r0, #2\n"
        "    strb r0, [r6, #4]\n"
        ".L081462E8:\n"
        "    ldrb r0, [r6, #4]\n"
        "    cmp r0, #0x63\n"
        "    bls .L081462F2\n"
        "    bl .L08146EEC\n"
        ".L081462F2:\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L08146300\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        ".L081462FC: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L08146300: .4byte gUnknown_08146304\n"
        "    .global gUnknown_08146304\n"
        "gUnknown_08146304:\n"
        ".L08146304: @ jump table\n"
        "    .4byte .L08146494\n"
        "    .4byte .L081464BA\n"
        "    .4byte .L081464C2\n"
        "    .4byte .L081464CA\n"
        "    .4byte .L08146558\n"
        "    .4byte .L08146594\n"
        "    .4byte .L08146644\n"
        "    .4byte .L0814664C\n"
        "    .4byte .L081466BE\n"
        "    .4byte .L08146728\n"
        "    .4byte .L08146780\n"
        "    .4byte .L081467B4\n"
        "    .4byte .L08146808\n"
        "    .4byte .L08146890\n"
        "    .4byte .L081468E4\n"
        "    .4byte .L0814690C\n"
        "    .4byte .L0814691E\n"
        "    .4byte .L08146A86\n"
        "    .4byte .L08146B20\n"
        "    .4byte .L08146B48\n"
        "    .4byte .L08146BA0\n"
        "    .4byte .L08146C44\n"
        "    .4byte .L08146D30\n"
        "    .4byte .L08146D36\n"
        "    .4byte .L08146D3C\n"
        "    .4byte .L08146DE4\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146EEC\n"
        "    .4byte .L08146E94\n"
        ".L08146494:\n"
        "    ldr r5, .L081464A8\n"
        "    adds r1, r6, r5\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0x28\n"
        "    bhi .L081464AC\n"
        "    adds r0, #1\n"
        "    strb r0, [r1]\n"
        "    bl .L08146EEC\n"
        "    .byte 0x00, 0x00\n"
        ".L081464A8: .4byte 0x000002B9\n"
        ".L081464AC:\n"
        "    movs r7, #0xae\n"
        "    lsls r7, r7, #2\n"
        "    adds r1, r6, r7\n"
        "    movs r0, #1\n"
        "    strb r0, [r1]\n"
        "    bl .L08146EEC\n"
        ".L081464BA:\n"
        "    bl sub_0814746C\n"
        "    bl .L08146EEC\n"
        ".L081464C2:\n"
        "    bl sub_081473DC\n"
        "    bl .L08146EEC\n"
        ".L081464CA:\n"
        "    adds r4, r6, #0\n"
        "    adds r4, #0x24\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #0xc\n"
        "    bls .L081464EC\n"
        "    ldr r0, .L08146548\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    movs r1, #0xbb\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #5\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L081464EC:\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #0x18\n"
        "    bls .L081464F6\n"
        "    movs r0, #0\n"
        "    strb r0, [r4]\n"
        ".L081464F6:\n"
        "    ldrb r0, [r4]\n"
        "    adds r0, #1\n"
        "    strb r0, [r4]\n"
        "    adds r1, r6, #0\n"
        "    adds r1, #0x37\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #6\n"
        "    bls .L0814650A\n"
        "    bl .L08146EEC\n"
        ".L0814650A:\n"
        "    movs r4, #0\n"
        "    ldr r0, .L0814654C\n"
        "    mov r8, r0\n"
        "    mov sb, r4\n"
        "    adds r2, r1, #0\n"
        "    movs r5, #1\n"
        "    ldr r3, .L08146550\n"
        ".L08146518:\n"
        "    lsls r0, r4, #1\n"
        "    adds r0, r0, r4\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r6, r0\n"
        "    mov r7, r8\n"
        "    adds r1, r0, r7\n"
        "    strb r5, [r1]\n"
        "    adds r1, r0, r3\n"
        "    mov r7, sb\n"
        "    strb r7, [r1]\n"
        "    ldr r1, .L08146554\n"
        "    adds r0, r0, r1\n"
        "    movs r1, #0xfc\n"
        "    strh r1, [r0]\n"
        "    ldrb r0, [r2]\n"
        "    adds r0, #1\n"
        "    strb r0, [r2]\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    cmp r4, #5\n"
        "    bls .L08146518\n"
        "    bl .L08146EEC\n"
        ".L08146548: .4byte gUnknown_0815016C\n"
        ".L0814654C: .4byte 0x0000026E\n"
        ".L08146550: .4byte 0x0000026F\n"
        ".L08146554: .4byte 0x00000266\n"
        ".L08146558:\n"
        "    movs r2, #0x95\n"
        "    lsls r2, r2, #2\n"
        "    adds r0, r6, r2\n"
        "    movs r1, #0\n"
        "    strb r1, [r0]\n"
        "    movs r3, #0x93\n"
        "    lsls r3, r3, #2\n"
        "    adds r0, r6, r3\n"
        "    strb r1, [r0]\n"
        "    ldr r4, .L0814658C\n"
        "    adds r0, r6, r4\n"
        "    strb r1, [r0]\n"
        "    ldr r7, .L08146590\n"
        "    adds r0, r6, r7\n"
        "    strb r1, [r0]\n"
        "    movs r0, #1\n"
        "    strb r0, [r5]\n"
        "    movs r0, #5\n"
        "    strb r0, [r6, #4]\n"
        "    movs r0, #0xad\n"
        "    lsls r0, r0, #1\n"
        "    bl Sound_Play\n"
        "    bl .L08146EEC\n"
        "    .byte 0x00, 0x00\n"
        ".L0814658C: .4byte 0x00000255\n"
        ".L08146590: .4byte 0x0000024D\n"
        ".L08146594:\n"
        "    ldr r1, .L081465C4\n"
        "    adds r0, r6, r1\n"
        "    movs r2, #0xa3\n"
        "    lsls r2, r2, #2\n"
        "    adds r1, r6, r2\n"
        "    movs r3, #0\n"
        "    ldrsh r2, [r0, r3]\n"
        "    movs r4, #0\n"
        "    ldrsh r0, [r1, r4]\n"
        "    cmp r2, r0\n"
        "    bne .L081465C8\n"
        "    adds r1, r6, #0\n"
        "    adds r1, #0x35\n"
        "    movs r0, #0\n"
        "    strb r0, [r1]\n"
        "    movs r0, #0xbe\n"
        "    lsls r0, r0, #1\n"
        "    bl Sound_Play\n"
        "    movs r0, #6\n"
        "    strb r0, [r6, #4]\n"
        "    bl .L08146EEC\n"
        "    .byte 0x00, 0x00\n"
        ".L081465C4: .4byte 0x0000028A\n"
        ".L081465C8:\n"
        "    adds r4, r6, #0\n"
        "    adds r4, #0x35\n"
        "    ldrb r1, [r4]\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r6, r0\n"
        "    ldr r5, .L0814663C\n"
        "    adds r0, r0, r5\n"
        "    movs r1, #1\n"
        "    strb r1, [r0]\n"
        "    ldrb r1, [r4]\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r6, r0\n"
        "    ldr r7, .L08146640\n"
        "    adds r2, r0, r7\n"
        "    movs r1, #0x9a\n"
        "    lsls r1, r1, #2\n"
        "    adds r0, r0, r1\n"
        "    ldrh r3, [r2]\n"
        "    movs r5, #0\n"
        "    ldrsh r1, [r2, r5]\n"
        "    movs r7, #0\n"
        "    ldrsh r0, [r0, r7]\n"
        "    cmp r1, r0\n"
        "    bge .L08146604\n"
        "    bl .L08146EEC\n"
        ".L08146604:\n"
        "    subs r0, r3, #6\n"
        "    strh r0, [r2]\n"
        "    ldrb r1, [r4]\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r6, r0\n"
        "    ldr r1, .L08146640\n"
        "    adds r2, r0, r1\n"
        "    movs r3, #0x9a\n"
        "    lsls r3, r3, #2\n"
        "    adds r0, r0, r3\n"
        "    movs r5, #0\n"
        "    ldrsh r1, [r2, r5]\n"
        "    ldrh r3, [r0]\n"
        "    movs r7, #0\n"
        "    ldrsh r0, [r0, r7]\n"
        "    cmp r1, r0\n"
        "    ble .L0814662E\n"
        "    bl .L08146EEC\n"
        ".L0814662E:\n"
        "    strh r3, [r2]\n"
        "    movs r0, #0xbe\n"
        "    lsls r0, r0, #1\n"
        "    bl Sound_Play\n"
        "    bl .L08146ED0\n"
        ".L0814663C: .4byte 0x0000026E\n"
        ".L08146640: .4byte 0x00000266\n"
        ".L08146644:\n"
        "    bl Baccarat_DealCard\n"
        "    bl .L08146EEC\n"
        ".L0814664C:\n"
        "    ldr r0, [r6, #0x10]\n"
        "    cmp r0, #0\n"
        "    beq .L08146676\n"
        "    ldr r1, [r6, #0x14]\n"
        "    cmp r1, #0\n"
        "    beq .L08146668\n"
        "    adds r1, r6, #0\n"
        "    adds r1, #0x2f\n"
        "    movs r0, #0\n"
        "    strb r0, [r1]\n"
        "    subs r1, #0xf\n"
        "    movs r0, #1\n"
        "    strb r0, [r1]\n"
        "    b .L0814666E\n"
        ".L08146668:\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x2f\n"
        "    strb r1, [r0]\n"
        ".L0814666E:\n"
        "    movs r0, #8\n"
        "    strb r0, [r6, #4]\n"
        "    bl .L08146EEC\n"
        ".L08146676:\n"
        "    ldr r1, [r6, #0x14]\n"
        "    cmp r1, #0\n"
        "    beq .L08146692\n"
        "    ldr r0, [r6, #0x18]\n"
        "    cmp r0, #0\n"
        "    bne .L0814669C\n"
        "    adds r1, r6, #0\n"
        "    adds r1, #0x2f\n"
        "    movs r0, #2\n"
        "    strb r0, [r1]\n"
        "    movs r0, #9\n"
        "    strb r0, [r6, #4]\n"
        "    bl .L08146EEC\n"
        ".L08146692:\n"
        "    ldr r0, [r6, #0x18]\n"
        "    cmp r0, #0\n"
        "    bne .L0814669C\n"
        "    bl .L08146EEC\n"
        ".L0814669C:\n"
        "    cmp r1, #0\n"
        "    beq .L081466AE\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x20\n"
        "    movs r1, #1\n"
        "    strb r1, [r0]\n"
        "    adds r0, #0xf\n"
        "    strb r1, [r0]\n"
        "    b .L081466B6\n"
        ".L081466AE:\n"
        "    adds r1, r6, #0\n"
        "    adds r1, #0x2f\n"
        "    movs r0, #1\n"
        "    strb r0, [r1]\n"
        ".L081466B6:\n"
        "    movs r0, #0xa\n"
        "    strb r0, [r6, #4]\n"
        "    bl .L08146EEC\n"
        ".L081466BE:\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x35\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #3\n"
        "    beq .L081466CA\n"
        "    b .L08146B52\n"
        ".L081466CA:\n"
        "    bl sub_08147820\n"
        "    ldr r2, .L08146718\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L081466E6\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L081466EA\n"
        ".L081466E6:\n"
        "    movs r0, #0xb\n"
        "    strb r0, [r6, #4]\n"
        ".L081466EA:\n"
        "    ldr r2, .L0814671C\n"
        "    ldr r1, .L08146720\n"
        "    adds r0, r6, r1\n"
        "    ldrb r0, [r0]\n"
        "    adds r0, r0, r2\n"
        "    ldrb r0, [r0]\n"
        "    ldr r3, .L08146724\n"
        "    adds r1, r6, r3\n"
        "    ldrb r1, [r1]\n"
        "    adds r1, r1, r2\n"
        "    ldrb r1, [r1]\n"
        "    adds r0, r0, r1\n"
        "    movs r1, #0xa\n"
        "    bl __modsi3\n"
        "    adds r0, #1\n"
        "    movs r4, #0x95\n"
        "    lsls r4, r4, #2\n"
        "    adds r1, r6, r4\n"
        "    strb r0, [r1]\n"
        "    bl .L08146EEC\n"
        "    .byte 0x00, 0x00\n"
        ".L08146718: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L0814671C: .4byte gUnknown_0879C91C\n"
        ".L08146720: .4byte 0x00000265\n"
        ".L08146724: .4byte 0x0000027D\n"
        ".L08146728:\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x35\n"
        "    ldrb r1, [r0]\n"
        "    adds r4, r0, #0\n"
        "    cmp r1, #4\n"
        "    beq .L0814673A\n"
        "    bl sub_0814760C\n"
        "    b .L0814673E\n"
        ".L0814673A:\n"
        "    movs r0, #0xc\n"
        "    strb r0, [r6, #4]\n"
        ".L0814673E:\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #3\n"
        "    beq .L08146748\n"
        "    bl .L08146EEC\n"
        ".L08146748:\n"
        "    ldr r2, .L08146774\n"
        "    ldr r5, .L08146778\n"
        "    adds r0, r6, r5\n"
        "    ldrb r0, [r0]\n"
        "    adds r0, r0, r2\n"
        "    ldrb r0, [r0]\n"
        "    ldr r7, .L0814677C\n"
        "    adds r1, r6, r7\n"
        "    ldrb r1, [r1]\n"
        "    adds r1, r1, r2\n"
        "    ldrb r1, [r1]\n"
        "    adds r0, r0, r1\n"
        "    movs r1, #0xa\n"
        "    bl __modsi3\n"
        "    adds r0, #1\n"
        "    movs r2, #0x95\n"
        "    lsls r2, r2, #2\n"
        "    adds r1, r6, r2\n"
        "    strb r0, [r1]\n"
        "    b .L08146EEC\n"
        "    .byte 0x00, 0x00\n"
        ".L08146774: .4byte gUnknown_0879C91C\n"
        ".L08146778: .4byte 0x00000265\n"
        ".L0814677C: .4byte 0x0000027D\n"
        ".L08146780:\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x35\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #2\n"
        "    beq .L0814678C\n"
        "    b .L08146B52\n"
        ".L0814678C:\n"
        "    bl sub_08147820\n"
        "    ldr r2, .L081467B0\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L081467AA\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L081467AA\n"
        "    b .L08146EEC\n"
        ".L081467AA:\n"
        "    movs r0, #0xb\n"
        "    strb r0, [r6, #4]\n"
        "    b .L08146EEC\n"
        ".L081467B0: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L081467B4:\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x35\n"
        "    ldrb r1, [r0]\n"
        "    adds r4, r0, #0\n"
        "    cmp r1, #4\n"
        "    beq .L081467C6\n"
        "    bl sub_0814760C\n"
        "    b .L081467CA\n"
        ".L081467C6:\n"
        "    movs r0, #0xc\n"
        "    strb r0, [r6, #4]\n"
        ".L081467CA:\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #3\n"
        "    beq .L081467D2\n"
        "    b .L08146EEC\n"
        ".L081467D2:\n"
        "    ldr r2, .L081467FC\n"
        "    ldr r3, .L08146800\n"
        "    adds r0, r6, r3\n"
        "    ldrb r0, [r0]\n"
        "    adds r0, r0, r2\n"
        "    ldrb r0, [r0]\n"
        "    ldr r4, .L08146804\n"
        "    adds r1, r6, r4\n"
        "    ldrb r1, [r1]\n"
        "    adds r1, r1, r2\n"
        "    ldrb r1, [r1]\n"
        "    adds r0, r0, r1\n"
        "    movs r1, #0xa\n"
        "    bl __modsi3\n"
        "    adds r0, #1\n"
        "    movs r5, #0x95\n"
        "    lsls r5, r5, #2\n"
        "    adds r1, r6, r5\n"
        "    strb r0, [r1]\n"
        "    b .L08146EEC\n"
        ".L081467FC: .4byte gUnknown_0879C91C\n"
        ".L08146800: .4byte 0x00000265\n"
        ".L08146804: .4byte 0x0000027D\n"
        ".L08146808:\n"
        "    ldr r2, .L08146854\n"
        "    ldr r7, .L08146858\n"
        "    adds r0, r6, r7\n"
        "    ldrb r0, [r0]\n"
        "    adds r0, r0, r2\n"
        "    ldrb r0, [r0]\n"
        "    ldr r3, .L0814685C\n"
        "    adds r1, r6, r3\n"
        "    ldrb r1, [r1]\n"
        "    adds r1, r1, r2\n"
        "    ldrb r1, [r1]\n"
        "    adds r0, r0, r1\n"
        "    movs r1, #0xa\n"
        "    bl __modsi3\n"
        "    adds r2, r0, #1\n"
        "    movs r4, #0x93\n"
        "    lsls r4, r4, #2\n"
        "    adds r0, r6, r4\n"
        "    strb r2, [r0]\n"
        "    movs r5, #0x95\n"
        "    lsls r5, r5, #2\n"
        "    adds r0, r6, r5\n"
        "    movs r1, #0\n"
        "    ldrsb r1, [r0, r1]\n"
        "    cmp r1, #8\n"
        "    bgt .L08146846\n"
        "    lsls r0, r2, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    cmp r0, #8\n"
        "    ble .L08146860\n"
        ".L08146846:\n"
        "    lsls r0, r2, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    cmp r0, r1\n"
        "    bne .L08146850\n"
        "    b .L08146D16\n"
        ".L08146850:\n"
        "    b .L08146A80\n"
        "    .byte 0x00, 0x00\n"
        ".L08146854: .4byte gUnknown_0879C91C\n"
        ".L08146858: .4byte 0x00000271\n"
        ".L0814685C: .4byte 0x00000289\n"
        ".L08146860:\n"
        "    cmp r1, #6\n"
        "    ble .L08146878\n"
        "    adds r1, r6, #0\n"
        "    adds r1, #0x35\n"
        "    movs r0, #5\n"
        "    strb r0, [r1]\n"
        "    ldr r7, .L08146874\n"
        "    adds r1, r6, r7\n"
        "    strb r0, [r1]\n"
        "    b .L08146A56\n"
        ".L08146874: .4byte 0x00000255\n"
        ".L08146878:\n"
        "    cmp r1, #0\n"
        "    bge .L0814687E\n"
        "    b .L08146EEC\n"
        ".L0814687E:\n"
        "    ldr r1, .L0814688C\n"
        "    adds r0, r6, r1\n"
        "    movs r1, #4\n"
        "    strb r1, [r0]\n"
        "    movs r0, #0xd\n"
        "    strb r0, [r6, #4]\n"
        "    b .L08146EEC\n"
        ".L0814688C: .4byte 0x00000255\n"
        ".L08146890:\n"
        "    ldr r2, .L081468AC\n"
        "    adds r0, r6, r2\n"
        "    movs r3, #0xa6\n"
        "    lsls r3, r3, #2\n"
        "    adds r1, r6, r3\n"
        "    movs r4, #0\n"
        "    ldrsh r2, [r0, r4]\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r1, r5]\n"
        "    cmp r2, r0\n"
        "    bne .L081468B0\n"
        "    movs r0, #0xe\n"
        "    strb r0, [r6, #4]\n"
        "    b .L08146EEC\n"
        ".L081468AC: .4byte 0x00000296\n"
        ".L081468B0:\n"
        "    adds r3, r6, #0\n"
        "    adds r3, #0x35\n"
        "    ldrb r1, [r3]\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r6, r0\n"
        "    ldr r7, .L081468DC\n"
        "    adds r0, r0, r7\n"
        "    movs r1, #1\n"
        "    strb r1, [r0]\n"
        "    ldrb r1, [r3]\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r6, r0\n"
        "    ldr r1, .L081468E0\n"
        "    adds r2, r0, r1\n"
        "    movs r4, #0x9a\n"
        "    lsls r4, r4, #2\n"
        "    adds r0, r0, r4\n"
        "    b .L08146AD2\n"
        ".L081468DC: .4byte 0x0000026E\n"
        ".L081468E0: .4byte 0x00000266\n"
        ".L081468E4:\n"
        "    bl sub_08147820\n"
        "    ldr r2, .L08146908\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L08146902\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L08146902\n"
        "    b .L08146EEC\n"
        ".L08146902:\n"
        "    movs r0, #0xf\n"
        "    strb r0, [r6, #4]\n"
        "    b .L08146EEC\n"
        ".L08146908: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L0814690C:\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x35\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #4\n"
        "    bne .L08146918\n"
        "    b .L08146B52\n"
        ".L08146918:\n"
        "    movs r0, #0x10\n"
        "    strb r0, [r6, #4]\n"
        "    b .L08146EEC\n"
        ".L0814691E:\n"
        "    ldr r2, .L08146970\n"
        "    ldr r7, .L08146974\n"
        "    adds r0, r6, r7\n"
        "    ldrb r0, [r0]\n"
        "    adds r0, r0, r2\n"
        "    ldrb r0, [r0]\n"
        "    ldr r3, .L08146978\n"
        "    adds r1, r6, r3\n"
        "    ldrb r1, [r1]\n"
        "    adds r1, r1, r2\n"
        "    ldrb r3, [r1]\n"
        "    ldr r4, .L0814697C\n"
        "    adds r1, r6, r4\n"
        "    ldrb r1, [r1]\n"
        "    adds r1, r1, r2\n"
        "    adds r0, r0, r3\n"
        "    ldrb r1, [r1]\n"
        "    adds r0, r0, r1\n"
        "    movs r1, #0xa\n"
        "    bl __modsi3\n"
        "    adds r0, #1\n"
        "    movs r5, #0x95\n"
        "    lsls r5, r5, #2\n"
        "    adds r1, r6, r5\n"
        "    strb r0, [r1]\n"
        "    subs r7, #0x19\n"
        "    adds r0, r6, r7\n"
        "    ldrb r0, [r0]\n"
        "    subs r0, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    cmp r0, #9\n"
        "    bls .L08146964\n"
        "    b .L08146EEC\n"
        ".L08146964:\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L08146980\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        "    .byte 0x00, 0x00\n"
        ".L08146970: .4byte gUnknown_0879C91C\n"
        ".L08146974: .4byte 0x00000265\n"
        ".L08146978: .4byte 0x0000027D\n"
        ".L0814697C: .4byte 0x00000295\n"
        ".L08146980: .4byte gUnknown_08146984\n"
        "    .global gUnknown_08146984\n"
        "gUnknown_08146984:\n"
        ".L08146984: @ jump table\n"
        "    .4byte .L08146A4E\n"
        "    .4byte .L081469AC\n"
        "    .4byte .L081469B8\n"
        "    .4byte .L081469C4\n"
        "    .4byte .L081469F0\n"
        "    .4byte .L08146A10\n"
        "    .4byte .L08146A3C\n"
        "    .4byte .L08146A70\n"
        "    .4byte .L08146A80\n"
        "    .4byte .L08146A80\n"
        ".L081469AC:\n"
        "    ldr r2, .L081469B4\n"
        "    adds r0, r6, r2\n"
        "    b .L08146A52\n"
        "    .byte 0x00, 0x00\n"
        ".L081469B4: .4byte 0x0000024D\n"
        ".L081469B8:\n"
        "    ldr r3, .L081469C0\n"
        "    adds r0, r6, r3\n"
        "    b .L08146A52\n"
        "    .byte 0x00, 0x00\n"
        ".L081469C0: .4byte 0x0000024D\n"
        ".L081469C4:\n"
        "    movs r4, #0x95\n"
        "    lsls r4, r4, #2\n"
        "    adds r0, r6, r4\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    cmp r0, #8\n"
        "    bgt .L081469E0\n"
        "    ldr r5, .L081469DC\n"
        "    adds r0, r6, r5\n"
        "    b .L08146A52\n"
        "    .byte 0x00, 0x00\n"
        ".L081469DC: .4byte 0x0000024D\n"
        ".L081469E0:\n"
        "    ldr r7, .L081469EC\n"
        "    adds r0, r6, r7\n"
        "    movs r1, #5\n"
        "    strb r1, [r0]\n"
        "    b .L08146D16\n"
        "    .byte 0x00, 0x00\n"
        ".L081469EC: .4byte 0x0000024D\n"
        ".L081469F0:\n"
        "    movs r1, #0x95\n"
        "    lsls r1, r1, #2\n"
        "    adds r0, r6, r1\n"
        "    ldrb r0, [r0]\n"
        "    subs r0, #3\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #5\n"
        "    bls .L08146A04\n"
        "    b .L08146D16\n"
        ".L08146A04:\n"
        "    ldr r2, .L08146A0C\n"
        "    adds r0, r6, r2\n"
        "    b .L08146A52\n"
        "    .byte 0x00, 0x00\n"
        ".L08146A0C: .4byte 0x0000024D\n"
        ".L08146A10:\n"
        "    movs r3, #0x95\n"
        "    lsls r3, r3, #2\n"
        "    adds r0, r6, r3\n"
        "    ldrb r0, [r0]\n"
        "    subs r0, #5\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #3\n"
        "    bhi .L08146A2C\n"
        "    ldr r4, .L08146A28\n"
        "    adds r0, r6, r4\n"
        "    b .L08146A52\n"
        ".L08146A28: .4byte 0x0000024D\n"
        ".L08146A2C:\n"
        "    ldr r5, .L08146A38\n"
        "    adds r0, r6, r5\n"
        "    movs r1, #5\n"
        "    strb r1, [r0]\n"
        "    b .L08146D16\n"
        "    .byte 0x00, 0x00\n"
        ".L08146A38: .4byte 0x0000024D\n"
        ".L08146A3C:\n"
        "    movs r7, #0x95\n"
        "    lsls r7, r7, #2\n"
        "    adds r0, r6, r7\n"
        "    ldrb r0, [r0]\n"
        "    subs r0, #7\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bhi .L08146A60\n"
        ".L08146A4E:\n"
        "    ldr r1, .L08146A5C\n"
        "    adds r0, r6, r1\n"
        ".L08146A52:\n"
        "    movs r1, #4\n"
        "    strb r1, [r0]\n"
        ".L08146A56:\n"
        "    movs r0, #0x11\n"
        "    strb r0, [r6, #4]\n"
        "    b .L08146EEC\n"
        ".L08146A5C: .4byte 0x0000024D\n"
        ".L08146A60:\n"
        "    ldr r2, .L08146A6C\n"
        "    adds r0, r6, r2\n"
        "    movs r1, #5\n"
        "    strb r1, [r0]\n"
        "    b .L08146D16\n"
        "    .byte 0x00, 0x00\n"
        ".L08146A6C: .4byte 0x0000024D\n"
        ".L08146A70:\n"
        "    ldr r3, .L08146A7C\n"
        "    adds r0, r6, r3\n"
        "    movs r1, #5\n"
        "    strb r1, [r0]\n"
        "    b .L08146D16\n"
        "    .byte 0x00, 0x00\n"
        ".L08146A7C: .4byte 0x0000024D\n"
        ".L08146A80:\n"
        "    movs r0, #0x15\n"
        "    strb r0, [r6, #4]\n"
        "    b .L08146EEC\n"
        ".L08146A86:\n"
        "    ldr r4, .L08146AA4\n"
        "    adds r0, r6, r4\n"
        "    movs r5, #0xa9\n"
        "    lsls r5, r5, #2\n"
        "    adds r1, r6, r5\n"
        "    movs r7, #0\n"
        "    ldrsh r2, [r0, r7]\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r1, r3]\n"
        "    cmp r2, r0\n"
        "    bne .L08146AA8\n"
        "    movs r0, #0x12\n"
        "    strb r0, [r6, #4]\n"
        "    b .L08146EEC\n"
        "    .byte 0x00, 0x00\n"
        ".L08146AA4: .4byte 0x000002A2\n"
        ".L08146AA8:\n"
        "    adds r3, r6, #0\n"
        "    adds r3, #0x35\n"
        "    ldrb r1, [r3]\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r6, r0\n"
        "    ldr r4, .L08146B18\n"
        "    adds r0, r0, r4\n"
        "    movs r1, #1\n"
        "    strb r1, [r0]\n"
        "    ldrb r1, [r3]\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r6, r0\n"
        "    ldr r5, .L08146B1C\n"
        "    adds r2, r0, r5\n"
        "    movs r7, #0x9a\n"
        "    lsls r7, r7, #2\n"
        "    adds r0, r0, r7\n"
        ".L08146AD2:\n"
        "    ldrh r4, [r2]\n"
        "    movs r5, #0\n"
        "    ldrsh r1, [r2, r5]\n"
        "    movs r7, #0\n"
        "    ldrsh r0, [r0, r7]\n"
        "    cmp r1, r0\n"
        "    bge .L08146AE2\n"
        "    b .L08146EEC\n"
        ".L08146AE2:\n"
        "    subs r0, r4, #6\n"
        "    strh r0, [r2]\n"
        "    ldrb r1, [r3]\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r6, r0\n"
        "    ldr r1, .L08146B1C\n"
        "    adds r2, r0, r1\n"
        "    movs r3, #0x9a\n"
        "    lsls r3, r3, #2\n"
        "    adds r0, r0, r3\n"
        "    movs r4, #0\n"
        "    ldrsh r1, [r2, r4]\n"
        "    ldrh r3, [r0]\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r0, r5]\n"
        "    cmp r1, r0\n"
        "    ble .L08146B0A\n"
        "    b .L08146EEC\n"
        ".L08146B0A:\n"
        "    strh r3, [r2]\n"
        "    movs r0, #0xbe\n"
        "    lsls r0, r0, #1\n"
        "    bl Sound_Play\n"
        "    b .L08146EEC\n"
        "    .byte 0x00, 0x00\n"
        ".L08146B18: .4byte 0x0000026E\n"
        ".L08146B1C: .4byte 0x00000266\n"
        ".L08146B20:\n"
        "    bl sub_08147820\n"
        "    ldr r2, .L08146B44\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L08146B3E\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L08146B3E\n"
        "    b .L08146EEC\n"
        ".L08146B3E:\n"
        "    movs r0, #0x13\n"
        "    strb r0, [r6, #4]\n"
        "    b .L08146EEC\n"
        ".L08146B44: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L08146B48:\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x35\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #5\n"
        "    bne .L08146B58\n"
        ".L08146B52:\n"
        "    bl sub_0814760C\n"
        "    b .L08146EEC\n"
        ".L08146B58:\n"
        "    ldr r2, .L08146B90\n"
        "    ldr r7, .L08146B94\n"
        "    adds r0, r6, r7\n"
        "    ldrb r0, [r0]\n"
        "    adds r0, r0, r2\n"
        "    ldrb r0, [r0]\n"
        "    ldr r3, .L08146B98\n"
        "    adds r1, r6, r3\n"
        "    ldrb r1, [r1]\n"
        "    adds r1, r1, r2\n"
        "    ldrb r3, [r1]\n"
        "    ldr r4, .L08146B9C\n"
        "    adds r1, r6, r4\n"
        "    ldrb r1, [r1]\n"
        "    adds r1, r1, r2\n"
        "    adds r0, r0, r3\n"
        "    ldrb r1, [r1]\n"
        "    adds r0, r0, r1\n"
        "    movs r1, #0xa\n"
        "    bl __modsi3\n"
        "    adds r0, #1\n"
        "    movs r5, #0x93\n"
        "    lsls r5, r5, #2\n"
        "    adds r1, r6, r5\n"
        "    strb r0, [r1]\n"
        "    b .L08146D16\n"
        "    .byte 0x00, 0x00\n"
        ".L08146B90: .4byte gUnknown_0879C91C\n"
        ".L08146B94: .4byte 0x00000271\n"
        ".L08146B98: .4byte 0x00000289\n"
        ".L08146B9C: .4byte 0x000002A1\n"
        ".L08146BA0:\n"
        "    bl Baccarat_RecordRoad\n"
        "    movs r7, #0x93\n"
        "    lsls r7, r7, #2\n"
        "    adds r0, r6, r7\n"
        "    movs r2, #0x95\n"
        "    lsls r2, r2, #2\n"
        "    adds r1, r6, r2\n"
        "    movs r2, #0\n"
        "    ldrsb r2, [r0, r2]\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r1, r0]\n"
        "    cmp r2, r0\n"
        "    ble .L08146BE8\n"
        "    ldr r3, .L08146BE0\n"
        "    adds r0, r6, r3\n"
        "    movs r2, #1\n"
        "    strb r2, [r0]\n"
        "    ldr r4, .L08146BE4\n"
        "    adds r0, r6, r4\n"
        "    movs r1, #2\n"
        "    strb r1, [r0]\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x2f\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L08146C30\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x30\n"
        "    strb r2, [r0]\n"
        "    b .L08146C36\n"
        "    .byte 0x00, 0x00\n"
        ".L08146BE0: .4byte 0x0000024D\n"
        ".L08146BE4: .4byte 0x00000255\n"
        ".L08146BE8:\n"
        "    cmp r2, r0\n"
        "    bge .L08146C1C\n"
        "    ldr r5, .L08146C0C\n"
        "    adds r0, r6, r5\n"
        "    movs r2, #2\n"
        "    strb r2, [r0]\n"
        "    ldr r7, .L08146C10\n"
        "    adds r1, r6, r7\n"
        "    movs r0, #1\n"
        "    strb r0, [r1]\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x2f\n"
        "    ldrb r1, [r0]\n"
        "    cmp r1, #1\n"
        "    bne .L08146C14\n"
        "    adds r0, #1\n"
        "    b .L08146C34\n"
        "    .byte 0x00, 0x00\n"
        ".L08146C0C: .4byte 0x0000024D\n"
        ".L08146C10: .4byte 0x00000255\n"
        ".L08146C14:\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x30\n"
        "    strb r2, [r0]\n"
        "    b .L08146C36\n"
        ".L08146C1C:\n"
        "    cmp r2, r0\n"
        "    beq .L08146C22\n"
        "    b .L08146EEC\n"
        ".L08146C22:\n"
        "    ldr r1, .L08146C3C\n"
        "    adds r0, r6, r1\n"
        "    movs r1, #3\n"
        "    strb r1, [r0]\n"
        "    ldr r2, .L08146C40\n"
        "    adds r0, r6, r2\n"
        "    strb r1, [r0]\n"
        ".L08146C30:\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x30\n"
        ".L08146C34:\n"
        "    strb r1, [r0]\n"
        ".L08146C36:\n"
        "    movs r0, #0x16\n"
        "    strb r0, [r6, #4]\n"
        "    b .L08146EEC\n"
        ".L08146C3C: .4byte 0x00000255\n"
        ".L08146C40: .4byte 0x0000024D\n"
        ".L08146C44:\n"
        "    movs r3, #0x93\n"
        "    lsls r3, r3, #2\n"
        "    adds r0, r6, r3\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    cmp r0, #8\n"
        "    ble .L08146CA2\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x42\n"
        "    ldrb r1, [r0]\n"
        "    adds r4, r0, #0\n"
        "    cmp r1, #0xb\n"
        "    bhi .L08146C80\n"
        "    ldr r0, .L08146C7C\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    movs r1, #4\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #0x24\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    b .L08146C98\n"
        "    .byte 0x00, 0x00\n"
        ".L08146C7C: .4byte gUnknown_08150254\n"
        ".L08146C80:\n"
        "    ldr r0, .L08146CD8\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    movs r1, #4\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #0x24\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L08146C98:\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #0x18\n"
        "    bls .L08146CA2\n"
        "    movs r0, #0\n"
        "    strb r0, [r4]\n"
        ".L08146CA2:\n"
        "    movs r4, #0x95\n"
        "    lsls r4, r4, #2\n"
        "    adds r0, r6, r4\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    cmp r0, #8\n"
        "    ble .L08146D02\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x42\n"
        "    ldrb r1, [r0]\n"
        "    adds r4, r0, #0\n"
        "    cmp r1, #0xb\n"
        "    bhi .L08146CE0\n"
        "    ldr r0, .L08146CDC\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    movs r1, #4\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #0x4a\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    b .L08146CF8\n"
        ".L08146CD8: .4byte gUnknown_081502E4\n"
        ".L08146CDC: .4byte gUnknown_08150254\n"
        ".L08146CE0:\n"
        "    ldr r0, .L08146D1C\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    movs r1, #4\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #0x4a\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L08146CF8:\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #0x18\n"
        "    bls .L08146D02\n"
        "    movs r0, #0\n"
        "    strb r0, [r4]\n"
        ".L08146D02:\n"
        "    adds r2, r6, #0\n"
        "    adds r2, #0x43\n"
        "    ldrb r0, [r2]\n"
        "    cmp r0, #0x54\n"
        "    bne .L08146D24\n"
        "    movs r0, #0\n"
        "    strb r0, [r2]\n"
        "    ldr r0, .L08146D20\n"
        "    bl Sound_Play\n"
        ".L08146D16:\n"
        "    movs r0, #0x14\n"
        "    strb r0, [r6, #4]\n"
        "    b .L08146EEC\n"
        ".L08146D1C: .4byte gUnknown_081502E4\n"
        ".L08146D20: .4byte 0x00000181\n"
        ".L08146D24:\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x42\n"
        "    ldrb r1, [r0]\n"
        "    adds r1, #1\n"
        "    strb r1, [r0]\n"
        "    b .L08146E7A\n"
        ".L08146D30:\n"
        "    bl Baccarat_ShowResult\n"
        "    b .L08146EEC\n"
        ".L08146D36:\n"
        "    bl Baccarat_CountUpCoins\n"
        "    b .L08146EEC\n"
        ".L08146D3C:\n"
        "    movs r4, #2\n"
        "    movs r5, #0x24\n"
        "    adds r5, r5, r6\n"
        "    mov r8, r5\n"
        ".L08146D44:\n"
        "    lsls r0, r4, #1\n"
        "    adds r0, r0, r4\n"
        "    lsls r0, r0, #2\n"
        "    adds r1, r6, r0\n"
        "    ldr r7, .L08146DD4\n"
        "    adds r0, r1, r7\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #1\n"
        "    bne .L08146D94\n"
        "    ldr r0, .L08146DD8\n"
        "    mov sb, r0\n"
        "    adds r2, r1, r0\n"
        "    ldr r3, .L08146DDC\n"
        "    adds r5, r1, r3\n"
        "    ldrh r3, [r2]\n"
        "    movs r7, #0\n"
        "    ldrsh r1, [r2, r7]\n"
        "    movs r7, #0\n"
        "    ldrsh r0, [r5, r7]\n"
        "    cmp r1, r0\n"
        "    beq .L08146D72\n"
        "    subs r0, r3, #2\n"
        "    strh r0, [r2]\n"
        ".L08146D72:\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x35\n"
        "    ldrb r1, [r0]\n"
        "    subs r1, #1\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r6, r0\n"
        "    add r0, sb\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r0, r2]\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r5, r3]\n"
        "    cmp r1, r0\n"
        "    bne .L08146D94\n"
        "    movs r0, #0x19\n"
        "    strb r0, [r6, #4]\n"
        ".L08146D94:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    cmp r4, #5\n"
        "    bls .L08146D44\n"
        "    mov r4, r8\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #0xc\n"
        "    bls .L08146DBE\n"
        "    ldr r0, .L08146DE0\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    movs r1, #0xbb\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #5\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L08146DBE:\n"
        "    mov r5, r8\n"
        "    ldrb r0, [r5]\n"
        "    cmp r0, #0x18\n"
        "    bls .L08146DCA\n"
        "    movs r0, #0\n"
        "    strb r0, [r5]\n"
        ".L08146DCA:\n"
        "    mov r7, r8\n"
        "    ldrb r0, [r7]\n"
        "    adds r0, #1\n"
        "    strb r0, [r7]\n"
        "    b .L08146EEC\n"
        ".L08146DD4: .4byte 0x0000026F\n"
        ".L08146DD8: .4byte 0x00000266\n"
        ".L08146DDC: .4byte 0x0000026A\n"
        ".L08146DE0: .4byte gUnknown_0815016C\n"
        ".L08146DE4:\n"
        "    movs r4, #0\n"
        "    movs r0, #0x24\n"
        "    adds r0, r0, r6\n"
        "    mov r8, r0\n"
        "    ldr r1, .L08146E84\n"
        "    mov sb, r1\n"
        "    mov ip, r4\n"
        ".L08146DF2:\n"
        "    lsls r0, r4, #1\n"
        "    adds r0, r0, r4\n"
        "    lsls r0, r0, #2\n"
        "    adds r1, r6, r0\n"
        "    ldr r2, .L08146E88\n"
        "    adds r0, r1, r2\n"
        "    ldrb r3, [r0]\n"
        "    cmp r3, #1\n"
        "    bne .L08146E44\n"
        "    ldr r5, .L08146E8C\n"
        "    mov sl, r5\n"
        "    add r1, sl\n"
        "    ldrh r2, [r1]\n"
        "    movs r7, #0\n"
        "    ldrsh r0, [r1, r7]\n"
        "    mov r7, sb\n"
        "    asrs r5, r7, #0x10\n"
        "    cmp r0, r5\n"
        "    blt .L08146E1C\n"
        "    subs r0, r2, #4\n"
        "    strh r0, [r1]\n"
        ".L08146E1C:\n"
        "    adds r2, r6, #0\n"
        "    adds r2, #0x35\n"
        "    ldrb r0, [r2]\n"
        "    subs r0, #1\n"
        "    lsls r1, r0, #1\n"
        "    adds r1, r1, r0\n"
        "    lsls r1, r1, #2\n"
        "    adds r1, r6, r1\n"
        "    add r1, sl\n"
        "    movs r7, #0\n"
        "    ldrsh r0, [r1, r7]\n"
        "    cmp r0, r5\n"
        "    bgt .L08146E44\n"
        "    mov r0, ip\n"
        "    strb r0, [r2]\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x37\n"
        "    mov r1, ip\n"
        "    strb r1, [r0]\n"
        "    strb r3, [r6, #4]\n"
        ".L08146E44:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    cmp r4, #5\n"
        "    bls .L08146DF2\n"
        "    mov r4, r8\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #0xc\n"
        "    bls .L08146E6E\n"
        "    ldr r0, .L08146E90\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    movs r1, #0xbb\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #5\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L08146E6E:\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #0x18\n"
        "    bls .L08146E78\n"
        "    movs r0, #0\n"
        "    strb r0, [r4]\n"
        ".L08146E78:\n"
        "    mov r2, r8\n"
        ".L08146E7A:\n"
        "    ldrb r0, [r2]\n"
        "    adds r0, #1\n"
        "    strb r0, [r2]\n"
        "    b .L08146EEC\n"
        "    .byte 0x00, 0x00\n"
        ".L08146E84: .4byte 0xFFE20000\n"
        ".L08146E88: .4byte 0x0000026F\n"
        ".L08146E8C: .4byte 0x00000266\n"
        ".L08146E90: .4byte gUnknown_0815016C\n"
        ".L08146E94:\n"
        "    adds r5, r6, #0\n"
        "    adds r5, #0x23\n"
        "    ldrb r0, [r5]\n"
        "    cmp r0, #5\n"
        "    bhi .L08146EDC\n"
        "    adds r4, r6, #0\n"
        "    adds r4, #0x24\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #3\n"
        "    bls .L08146EC0\n"
        "    ldr r0, .L08146ED8\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    movs r1, #9\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #5\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L08146EC0:\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #6\n"
        "    bls .L08146ED0\n"
        "    movs r0, #0\n"
        "    strb r0, [r4]\n"
        "    ldrb r0, [r5]\n"
        "    adds r0, #1\n"
        "    strb r0, [r5]\n"
        ".L08146ED0:\n"
        "    ldrb r0, [r4]\n"
        "    adds r0, #1\n"
        "    strb r0, [r4]\n"
        "    b .L08146EEC\n"
        ".L08146ED8: .4byte gUnknown_0815019C\n"
        ".L08146EDC:\n"
        "    ldr r0, [r6, #8]\n"
        "    movs r1, #0x64\n"
        "    bl __udivsi3\n"
        "    bl sub_080C31FC\n"
        "    bl sub_080BE4C4\n"
        ".L08146EEC:\n"
        "    add sp, #0xc\n"
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
