#include "global.h"
#include "btext.h"

// BattleMenu_SetMode @ 0x080EA37C
void BattleMenu_SetMode(u8 mode, u16 *src)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
    u32 zero;
    u16 *dst;

    if (msg->locked == 1)
        return;

    msg->mode = mode;
    msg->src = src;
    if ((u8)(mode - 7) <= 1)
    {
        zero = 0;
        CpuSet(&zero, b->msg.text2, 0x05000020);
    }
    else
    {
        zero = 0;
        CpuSet(&zero, b->msg.text, 0x05000020);
    }
    msg->autoClose = 0;
    msg->autoCloseTimer = 0;

    switch (mode)
    {
    case 0:
        msg->typed = 0;
        msg->delay = 0;
        break;
    case 3:
        Font_ResetGlyphSpriteCache(0x180);
        msg->delay = 1;
        msg->typed = 0;
        msg->done = 0;
        msg->mode = 2;
        msg->lines = BattleMsg_FitWindow(src);
        break;
    case 4:
        Font_ResetGlyphSpriteCache(0x180);
        msg->typed = 0;
        msg->delay = 0;
        dst = msg->text;
        msg->lines = BattleMsg_FitWindow(src);
        while (*src != 0)
            *dst++ = *src++;
        break;
    case 7:
        msg->delay = 1;
        msg->typed = 0;
        msg->done = 0;
        msg->mode = 6;
        msg->lines = 4;
        Window_SetHeight(b->window, 7);
        break;
    case 8:
        Font_ResetGlyphSpriteCache(0x180);
        msg->typed = 0;
        msg->delay = 0;
        dst = msg->text2;
        while (*src != 0)
            *dst++ = *src++;
        break;
    case 9:
        Font_ResetGlyphSpriteCache(0x180);
        msg->typed = 0;
        msg->delay = 0;
        dst = msg->text;
        for (; *src != 0; dst++)
            *dst = *src++;
        msg->mode = 4;
        break;
    }
}

// BattleMenu_SetModeAutoClose @ 0x080EA4F8
void BattleMenu_SetModeAutoClose(u8 mode, u16 *src)
{
    struct BattleMsgBlock *b = BLOCK;

    BattleMenu_SetMode(mode, src);
    b->msg.autoClose = 1;
    b->msg.autoCloseTimer = 75;
}

// BattleMenu_Reset @ 0x080EA528
void BattleMenu_Reset(void)
{
    BattleMenu_SetMode(0, NULL);
}

/* Draws text, then text2 below it, one line lower per line break in text. */
static inline void DrawTwoParts(struct BattleMsg *m)
{
    u8 n;
    u8 i;

    Text_DrawSpriteString(m->text, 0, 0, 0x10, (u16)(m->row * 16 + 0x59), 12);
    n = 0;
    for (i = 0; m->text[i] != 0; i++)
    {
        if (m->text[i] == 0x300)
            n++;
    }
    Text_DrawSpriteString(m->text2, 0, 0, 0x10, (u16)(m->row * 16 + 0x59 + n * 12), 12);
}

#define MSG_Y(m) ((u16)((m)->row * 16 + 0x59))

/* Per-frame update of the battle message window: types out msg->src at the configured
   speed (0x315 = pause), draws the text and the blinking "next" arrow. */
// BattleMsg_Update @ 0x080EA538
void BattleMsg_Update(void)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
    u16 *q;

    switch (msg->mode)
    {
    case 0:
        break;
    case 1:
        if (gKeysNew & 0xF3)
            msg->done = 1;
        if (msg->autoClose == 1 && --msg->autoCloseTimer == 0)
            msg->done = 1;
        Text_DrawSpriteString(msg->text, 0, 0, 0x10, MSG_Y(msg), 12);
        if (msg->done == 1)
            break;
        if ((gFrameCounter >> 4) & 1)
            break;
        Sprite_Draw(gUnknown_08001000, 0, 0, 0, 0, 0xD4,
                     (u16)(msg->row * 16 + 0x5F + (msg->lines - 1) * 12));
        break;
    case 2:
        if (gUnk_030031D0 & 1)
            msg->delay = 1;
        if (--msg->delay == 0)
        {
            u16 *d;
            u16 *s;
            u8 i;

            msg->delay = gBattleMsgSpeedFrames[Settings_GetBattleMsgSpeed()];
            msg->typed++;
            d = msg->text;
            s = msg->src;
            if (s[msg->typed] == 0x315)
            {
                msg->delay = 15;
                msg->typed++;
            }
            for (i = 0; i < msg->typed; i++)
            {
                if (*s != 0x315)
                    *d++ = *s++;
                else
                    s++;
            }
            if (*--s == 0)
            {
                msg->mode = 1;
                msg->typed = 0;
                msg->delay = 0;
            }
        }
        Text_DrawSpriteString(msg->text, 0, 0, 0x10, MSG_Y(msg), 12);
        break;
    case 4:
        Text_DrawSpriteString(msg->text, 0, 0, 0x10, MSG_Y(msg), 12);
        break;
    case 5:
        if (gKeysNew & 0xF3)
            msg->done = 1;
        if (msg->text[0] == 0)
        {
            q = msg->text2;
            if (*q == 0x300)
                q++;
            Text_DrawSpriteString(q, 0, 0, 0x10, MSG_Y(msg), 12);
        }
        else
        {
            DrawTwoParts(msg);
        }
        if ((gFrameCounter >> 4) & 1)
            break;
        {
            s32 t;
            Sprite_Draw(gUnknown_08001000, 0, 0, 0, 0, 0xD4,
                        (t = (msg->lines - 1) * 14, (u16)(msg->row * 16 + t + 0x5D)));
        }
        break;
    case 6:
        if (gUnk_030031D0 & 1)
            msg->delay = 1;
        if (--msg->delay == 0)
        {
            u16 *d;
            u16 *s;
            u8 i;

            msg->delay = gBattleMsgSpeedFrames[Settings_GetBattleMsgSpeed()];
            msg->typed++;
            d = msg->text2;
            s = msg->src;
            for (i = 0; i < msg->typed; i++)
                *d++ = *s++;
            if (*--s == 0)
            {
                msg->mode = 5;
                msg->typed = 0;
                msg->delay = 0;
            }
        }
        if (msg->text[0] == 0)
        {
            q = msg->text2;
            if (*q == 0x300)
                q = msg->text2 + 1;
            Text_DrawSpriteString(q, 0, 0, 0x10, MSG_Y(msg), 12);
        }
        else
        {
            DrawTwoParts(msg);
        }
        break;
    case 8:
        Text_DrawSpriteString(msg->text, 0, 0, 0x10, MSG_Y(msg), 12);
        Text_DrawSpriteString(msg->text2, 0, 0, 0x10, (u16)(msg->row * 16 + 0x69), 12);
        break;
    }
}
