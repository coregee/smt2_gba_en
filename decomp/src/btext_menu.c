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

#ifdef NONMATCHING
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
#endif

#define MSG_Y(m) ((u16)((m)->row * 16 + 0x59))

// BattleMsg_Update @ 0x080EA538
#ifdef NONMATCHING
/* Per-frame update of the battle message window: types out msg->src at the configured
   speed (0x315 = pause), draws the text and the blinking "next" arrow. Only the register
   choice for the case-5 arrow position differs from the original. */
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
        Sprite_Draw(gUnknown_08001000, 0, 0, 0, 0, 0xD4,
                     (u16)((msg->lines - 1) * 14 + msg->row * 16 + 0x5D));
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
#else
NAKED
void BattleMsg_Update(void)
{
    asm_unified(
        "    push {r4, r5, r6, lr}\n"
        "    sub sp, #0xc\n"
        "    ldr r0, .L080EA558\n"
        "    movs r1, #0xfc\n"
        "    lsls r1, r1, #3\n"
        "    adds r5, r0, r1\n"
        "    ldrb r0, [r5]\n"
        "    cmp r0, #8\n"
        "    bls .L080EA54C\n"
        "    b .L080EA92C\n"
        ".L080EA54C:\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L080EA55C\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080EA558: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080EA55C: .4byte gUnknown_080EA560\n"
        "    .global gUnknown_080EA560\n"
        "gUnknown_080EA560:\n"
        ".L080EA560: @ jump table\n"
        "    .4byte .L080EA92C\n"
        "    .4byte .L080EA584\n"
        "    .4byte .L080EA61C\n"
        "    .4byte .L080EA92C\n"
        "    .4byte .L080EA6BE\n"
        "    .4byte .L080EA6D6\n"
        "    .4byte .L080EA7DC\n"
        "    .4byte .L080EA92C\n"
        "    .4byte .L080EA8EE\n"
        ".L080EA584:\n"
        "    ldr r0, .L080EA610\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0xf3\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080EA594\n"
        "    movs r0, #1\n"
        "    strb r0, [r5, #4]\n"
        ".L080EA594:\n"
        "    movs r2, #0xc6\n"
        "    lsls r2, r2, #1\n"
        "    adds r0, r5, r2\n"
        "    ldrh r2, [r0]\n"
        "    cmp r2, #1\n"
        "    bne .L080EA5B4\n"
        "    movs r0, #0xc7\n"
        "    lsls r0, r0, #1\n"
        "    adds r1, r5, r0\n"
        "    ldrh r0, [r1]\n"
        "    subs r0, #1\n"
        "    strh r0, [r1]\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080EA5B4\n"
        "    strb r2, [r5, #4]\n"
        ".L080EA5B4:\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0xc\n"
        "    ldrb r1, [r5, #5]\n"
        "    lsls r1, r1, #0x14\n"
        "    movs r2, #0xb2\n"
        "    lsls r2, r2, #0xf\n"
        "    adds r1, r1, r2\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp]\n"
        "    movs r1, #0xc\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0x10\n"
        "    bl Text_DrawSpriteString\n"
        "    ldrb r0, [r5, #4]\n"
        "    cmp r0, #1\n"
        "    bne .L080EA5DC\n"
        "    b .L080EA92C\n"
        ".L080EA5DC:\n"
        "    ldr r0, .L080EA614\n"
        "    ldr r0, [r0]\n"
        "    lsrs r1, r0, #4\n"
        "    movs r0, #1\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080EA5EC\n"
        "    b .L080EA92C\n"
        ".L080EA5EC:\n"
        "    ldr r0, .L080EA618\n"
        "    str r1, [sp]\n"
        "    movs r1, #0xd4\n"
        "    str r1, [sp, #4]\n"
        "    ldrb r3, [r5, #5]\n"
        "    lsls r3, r3, #4\n"
        "    adds r3, #0x5f\n"
        "    ldrb r2, [r5, #6]\n"
        "    subs r2, #1\n"
        "    lsls r1, r2, #1\n"
        "    adds r1, r1, r2\n"
        "    lsls r1, r1, #2\n"
        "    adds r3, r3, r1\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    str r3, [sp, #8]\n"
        "    b .L080EA7C8\n"
        "    .byte 0x00, 0x00\n"
        ".L080EA610: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L080EA614: .4byte 0x030031BC @ IWRAM+0x31BC\n"
        ".L080EA618: .4byte gUnknown_08001000\n"
        ".L080EA61C:\n"
        "    ldr r0, .L080EA670\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080EA62C\n"
        "    movs r0, #1\n"
        "    strb r0, [r5, #2]\n"
        ".L080EA62C:\n"
        "    ldrb r0, [r5, #2]\n"
        "    subs r0, #1\n"
        "    strb r0, [r5, #2]\n"
        "    lsls r0, r0, #0x18\n"
        "    adds r4, r5, #0\n"
        "    adds r4, #0xc\n"
        "    cmp r0, #0\n"
        "    bne .L080EA6A8\n"
        "    bl Settings_GetBattleMsgSpeed\n"
        "    ldr r1, .L080EA674\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    adds r0, r0, r1\n"
        "    ldrb r0, [r0]\n"
        "    strb r0, [r5, #2]\n"
        "    ldrb r0, [r5, #3]\n"
        "    adds r1, r0, #1\n"
        "    strb r1, [r5, #3]\n"
        "    adds r3, r4, #0\n"
        "    ldr r2, [r5, #8]\n"
        "    ldrb r0, [r5, #3]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r0, [r0]\n"
        "    ldr r6, .L080EA678\n"
        "    cmp r0, r6\n"
        "    bne .L080EA66C\n"
        "    movs r0, #0xf\n"
        "    strb r0, [r5, #2]\n"
        "    adds r0, r1, #1\n"
        "    strb r0, [r5, #3]\n"
        ".L080EA66C:\n"
        "    movs r0, #0\n"
        "    b .L080EA692\n"
        ".L080EA670: .4byte 0x030031D0 @ IWRAM+0x31D0\n"
        ".L080EA674: .4byte gBattleMsgSpeedFrames\n"
        ".L080EA678: .4byte 0x00000315\n"
        ".L080EA67C:\n"
        "    ldrh r1, [r2]\n"
        "    cmp r1, r6\n"
        "    beq .L080EA68A\n"
        "    strh r1, [r3]\n"
        "    adds r2, #2\n"
        "    adds r3, #2\n"
        "    b .L080EA68C\n"
        ".L080EA68A:\n"
        "    adds r2, #2\n"
        ".L080EA68C:\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        ".L080EA692:\n"
        "    ldrb r1, [r5, #3]\n"
        "    cmp r0, r1\n"
        "    blo .L080EA67C\n"
        "    subs r2, #2\n"
        "    ldrh r1, [r2]\n"
        "    cmp r1, #0\n"
        "    bne .L080EA6A8\n"
        "    movs r0, #1\n"
        "    strb r0, [r5]\n"
        "    strb r1, [r5, #3]\n"
        "    strb r1, [r5, #2]\n"
        ".L080EA6A8:\n"
        "    ldrb r0, [r5, #5]\n"
        "    lsls r0, r0, #0x14\n"
        "    movs r2, #0xb2\n"
        "    lsls r2, r2, #0xf\n"
        "    adds r0, r0, r2\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp]\n"
        "    movs r0, #0xc\n"
        "    str r0, [sp, #4]\n"
        "    adds r0, r4, #0\n"
        "    b .L080EA8E2\n"
        ".L080EA6BE:\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0xc\n"
        "    ldrb r1, [r5, #5]\n"
        "    lsls r1, r1, #0x14\n"
        "    movs r2, #0xb2\n"
        "    lsls r2, r2, #0xf\n"
        "    adds r1, r1, r2\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp]\n"
        "    movs r1, #0xc\n"
        "    str r1, [sp, #4]\n"
        "    b .L080EA8E2\n"
        ".L080EA6D6:\n"
        "    ldr r0, .L080EA71C\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0xf3\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080EA6E6\n"
        "    movs r0, #1\n"
        "    strb r0, [r5, #4]\n"
        ".L080EA6E6:\n"
        "    ldrh r0, [r5, #0xc]\n"
        "    cmp r0, #0\n"
        "    bne .L080EA720\n"
        "    adds r2, r5, #0\n"
        "    adds r2, #0x8c\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #2\n"
        "    cmp r1, r0\n"
        "    bne .L080EA6FC\n"
        "    adds r2, #2\n"
        ".L080EA6FC:\n"
        "    ldrb r0, [r5, #5]\n"
        "    lsls r0, r0, #0x14\n"
        "    movs r1, #0xb2\n"
        "    lsls r1, r1, #0xf\n"
        "    adds r0, r0, r1\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp]\n"
        "    movs r0, #0xc\n"
        "    str r0, [sp, #4]\n"
        "    adds r0, r2, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0x10\n"
        "    bl Text_DrawSpriteString\n"
        "    b .L080EA798\n"
        ".L080EA71C: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L080EA720:\n"
        "    adds r4, r5, #0\n"
        "    adds r4, #0xc\n"
        "    ldrb r0, [r5, #5]\n"
        "    lsls r0, r0, #0x14\n"
        "    movs r2, #0xb2\n"
        "    lsls r2, r2, #0xf\n"
        "    adds r0, r0, r2\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp]\n"
        "    movs r0, #0xc\n"
        "    str r0, [sp, #4]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0x10\n"
        "    bl Text_DrawSpriteString\n"
        "    movs r2, #0\n"
        "    movs r1, #0\n"
        "    ldrh r0, [r5, #0xc]\n"
        "    adds r6, r5, #0\n"
        "    adds r6, #0x8c\n"
        "    cmp r0, #0\n"
        "    beq .L080EA774\n"
        "    movs r3, #0xc0\n"
        "    lsls r3, r3, #2\n"
        ".L080EA754:\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r4, r0\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, r3\n"
        "    bne .L080EA764\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r2, r0, #0x18\n"
        ".L080EA764:\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r1, r0, #0x18\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r4, r0\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L080EA754\n"
        ".L080EA774:\n"
        "    ldrb r0, [r5, #5]\n"
        "    lsls r0, r0, #4\n"
        "    adds r0, #0x59\n"
        "    lsls r1, r2, #1\n"
        "    adds r1, r1, r2\n"
        "    lsls r1, r1, #2\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp]\n"
        "    movs r0, #0xc\n"
        "    str r0, [sp, #4]\n"
        "    adds r0, r6, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0x10\n"
        "    bl Text_DrawSpriteString\n"
        ".L080EA798:\n"
        "    ldr r0, .L080EA7D4\n"
        "    ldr r0, [r0]\n"
        "    lsrs r1, r0, #4\n"
        "    movs r0, #1\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080EA7A8\n"
        "    b .L080EA92C\n"
        ".L080EA7A8:\n"
        "    ldr r0, .L080EA7D8\n"
        "    str r1, [sp]\n"
        "    movs r1, #0xd4\n"
        "    str r1, [sp, #4]\n"
        "    ldrb r1, [r5, #6]\n"
        "    subs r1, #1\n"
        "    lsls r2, r1, #3\n"
        "    subs r2, r2, r1\n"
        "    lsls r2, r2, #1\n"
        "    ldrb r1, [r5, #5]\n"
        "    lsls r1, r1, #4\n"
        "    adds r1, r1, r2\n"
        "    adds r1, #0x5d\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        ".L080EA7C8:\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    b .L080EA92C\n"
        ".L080EA7D4: .4byte 0x030031BC @ IWRAM+0x31BC\n"
        ".L080EA7D8: .4byte gUnknown_08001000\n"
        ".L080EA7DC:\n"
        "    ldr r0, .L080EA870\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080EA7EC\n"
        "    movs r0, #1\n"
        "    strb r0, [r5, #2]\n"
        ".L080EA7EC:\n"
        "    ldrb r0, [r5, #2]\n"
        "    subs r0, #1\n"
        "    strb r0, [r5, #2]\n"
        "    lsls r0, r0, #0x18\n"
        "    adds r6, r5, #0\n"
        "    adds r6, #0x8c\n"
        "    cmp r0, #0\n"
        "    bne .L080EA842\n"
        "    bl Settings_GetBattleMsgSpeed\n"
        "    ldr r1, .L080EA874\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    adds r0, r0, r1\n"
        "    ldrb r0, [r0]\n"
        "    strb r0, [r5, #2]\n"
        "    ldrb r0, [r5, #3]\n"
        "    adds r0, #1\n"
        "    strb r0, [r5, #3]\n"
        "    adds r3, r6, #0\n"
        "    ldr r1, [r5, #8]\n"
        "    lsls r0, r0, #0x18\n"
        "    movs r2, #0\n"
        "    cmp r0, #0\n"
        "    beq .L080EA832\n"
        ".L080EA81E:\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r3]\n"
        "    adds r1, #2\n"
        "    adds r3, #2\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r2, r0, #0x18\n"
        "    ldrb r0, [r5, #3]\n"
        "    cmp r2, r0\n"
        "    blo .L080EA81E\n"
        ".L080EA832:\n"
        "    subs r1, #2\n"
        "    ldrh r1, [r1]\n"
        "    cmp r1, #0\n"
        "    bne .L080EA842\n"
        "    movs r0, #5\n"
        "    strb r0, [r5]\n"
        "    strb r1, [r5, #3]\n"
        "    strb r1, [r5, #2]\n"
        ".L080EA842:\n"
        "    ldrh r0, [r5, #0xc]\n"
        "    cmp r0, #0\n"
        "    bne .L080EA878\n"
        "    adds r2, r6, #0\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #2\n"
        "    cmp r1, r0\n"
        "    bne .L080EA858\n"
        "    adds r2, r5, #0\n"
        "    adds r2, #0x8e\n"
        ".L080EA858:\n"
        "    ldrb r0, [r5, #5]\n"
        "    lsls r0, r0, #0x14\n"
        "    movs r1, #0xb2\n"
        "    lsls r1, r1, #0xf\n"
        "    adds r0, r0, r1\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp]\n"
        "    movs r0, #0xc\n"
        "    str r0, [sp, #4]\n"
        "    adds r0, r2, #0\n"
        "    b .L080EA8E2\n"
        "    .byte 0x00, 0x00\n"
        ".L080EA870: .4byte 0x030031D0 @ IWRAM+0x31D0\n"
        ".L080EA874: .4byte gBattleMsgSpeedFrames\n"
        ".L080EA878:\n"
        "    adds r4, r5, #0\n"
        "    adds r4, #0xc\n"
        "    ldrb r0, [r5, #5]\n"
        "    lsls r0, r0, #0x14\n"
        "    movs r2, #0xb2\n"
        "    lsls r2, r2, #0xf\n"
        "    adds r0, r0, r2\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp]\n"
        "    movs r0, #0xc\n"
        "    str r0, [sp, #4]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0x10\n"
        "    bl Text_DrawSpriteString\n"
        "    movs r2, #0\n"
        "    movs r1, #0\n"
        "    ldrh r0, [r5, #0xc]\n"
        "    cmp r0, #0\n"
        "    beq .L080EA8C8\n"
        "    movs r3, #0xc0\n"
        "    lsls r3, r3, #2\n"
        ".L080EA8A8:\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r4, r0\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, r3\n"
        "    bne .L080EA8B8\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r2, r0, #0x18\n"
        ".L080EA8B8:\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r1, r0, #0x18\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r4, r0\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L080EA8A8\n"
        ".L080EA8C8:\n"
        "    ldrb r0, [r5, #5]\n"
        "    lsls r0, r0, #4\n"
        "    adds r0, #0x59\n"
        "    lsls r1, r2, #1\n"
        "    adds r1, r1, r2\n"
        "    lsls r1, r1, #2\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp]\n"
        "    movs r0, #0xc\n"
        "    str r0, [sp, #4]\n"
        "    adds r0, r6, #0\n"
        ".L080EA8E2:\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0x10\n"
        "    bl Text_DrawSpriteString\n"
        "    b .L080EA92C\n"
        ".L080EA8EE:\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0xc\n"
        "    ldrb r1, [r5, #5]\n"
        "    lsls r1, r1, #0x14\n"
        "    movs r2, #0xb2\n"
        "    lsls r2, r2, #0xf\n"
        "    adds r1, r1, r2\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp]\n"
        "    movs r4, #0xc\n"
        "    str r4, [sp, #4]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0x10\n"
        "    bl Text_DrawSpriteString\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x8c\n"
        "    ldrb r1, [r5, #5]\n"
        "    lsls r1, r1, #0x14\n"
        "    movs r2, #0xd2\n"
        "    lsls r2, r2, #0xf\n"
        "    adds r1, r1, r2\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp]\n"
        "    str r4, [sp, #4]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0x10\n"
        "    bl Text_DrawSpriteString\n"
        ".L080EA92C:\n"
        "    add sp, #0xc\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif
