#include "global.h"
#include "options.h"

// Options_DrawRow @ 0x080CF7D8
/* Draws row `row` of the options screen: label (tint 4 when selected and the screen is active)
   and the choices, the current one in palette col[3]. gMenuState.sel != 0 (battle) hides
   row 0, moves the others up 16 pixels and shows EXIT. */
void Options_DrawRow(u32 unused, u32 row)
{
    struct C0c6Status *m = &gMenuState;
    u16 tint = 0;
    u8 *canvas = gUnk_0200F874;
    u16 col[4];
    u16 shift;
    s16 y;

    col[0] = 2;
    col[1] = 2;
    col[2] = 2;
    col[3] = 8;
    if (m->mode == row)
    {
        if (m->page == 0)
            tint = 4;
        col[3] = 4;
        Options_DrawHelp(row);
    }
    if (m->sel == 0)
        shift = 0;
    else
        shift = 16;
    switch (row)
    {
    case 0:
        if (m->sel != 0)
            break;
        Canvas_FillRect(0, canvas, 0xC, 0x1B, 0xE0, 0xA);
        DigitFont_DrawAscii(gUnknown_084F18A0, 0xC, 0x1B, tint);
        DigitFont_DrawAscii(gUnknown_084F18A4, 0x2A, 0x1B, tint);
        col[Options_GetValue(0)] = col[3];
        DigitFont_DrawAscii(gUnknown_084F18AC, 0x7C, 0x1B, col[0]);
        DigitFont_DrawAscii(gUnknown_084F18B4, 0xB4, 0x1B, col[1]);
        break;
    case 1:
        y = 0x2B - shift;
        Canvas_FillRect(0, canvas, 0xC, y, 0xE0, 0xA);
        DigitFont_DrawAscii(gUnknown_084F18BC, 0xC, y, tint);
        DigitFont_DrawAscii(gUnknown_084F18A0, 0x2A, y, tint);
        DigitFont_DrawAscii(gUnknown_084F18A4, 0x48, y, tint);
        col[Options_GetValue(1)] = col[3];
        DigitFont_DrawAscii(gUnknown_084F18AC, 0x7C, y, col[0]);
        DigitFont_DrawAscii(gUnknown_084F18B4, 0xB4, y, col[1]);
        break;
    case 2:
        y = 0x3B - shift;
        Canvas_FillRect(0, canvas, 0xC, y, 0xE0, 0xA);
        DigitFont_DrawAscii(gUnknown_084F18BC, 0xC, y, tint);
        DigitFont_DrawAscii(gUnknown_084F18C0, 0x2A, y, tint);
        col[Options_GetValue(2)] = col[3];
        DigitFont_DrawAscii(gUnknown_084F18C8, 0x8C, y, col[0]);
        DigitFont_DrawAscii(gUnknown_084F18CC, 0xBC, y, col[1]);
        break;
    case 3:
        y = 0x4B - shift;
        Canvas_FillRect(0, canvas, 0xC, y, 0xE0, 0xA);
        DigitFont_DrawAscii(gUnknown_084F18D0, 0xC, y, tint);
        DigitFont_DrawAscii(gUnknown_084F18BC, 0x32, y, tint);
        col[Options_GetValue(3)] = col[3];
        DigitFont_DrawAscii(gUnknown_084F18D8, 0x5E, y, col[0]);
        DigitFont_DrawAscii(gUnknown_084F18E0, 0x8E, y, col[1]);
        DigitFont_DrawAscii(gUnknown_084F18E8, 0xBE, y, col[2]);
        break;
    case 4:
        y = 0x5B - shift;
        Canvas_FillRect(0, canvas, 0xC, y, 0xE0, 0xA);
        DigitFont_DrawAscii(gUnknown_084F18D0, 0xC, y, tint);
        DigitFont_DrawAscii(gUnknown_084F18F0, 0x32, y, tint);
        col[Options_GetValue(4)] = col[3];
        DigitFont_DrawAscii(gUnknown_084F18F4, 0x88, y, col[0]);
        DigitFont_DrawAscii(gUnknown_084F18F8, 0xB8, y, col[1]);
        break;
    case 5:
        y = 0x6B - shift;
        Canvas_FillRect(0, canvas, 0xC, y, 0xE0, 0xA);
        DigitFont_DrawAscii(gUnknown_084F18D0, 0xC, y, tint);
        DigitFont_DrawAscii(gUnknown_084F1900, 0x32, y, tint);
        col[Options_GetValue(5)] = col[3];
        DigitFont_DrawAscii(gUnknown_084F1908, 0x84, y, col[0]);
        DigitFont_DrawAscii(gUnknown_084F1910, 0xB4, y, col[1]);
        break;
    case 6:
        y = 0x7B - shift;
        Canvas_FillRect(0, canvas, 0xC, y, 0xE0, 0xA);
        DigitFont_DrawAscii(gUnknown_084F1918, 0xC, y, tint);
        col[Options_GetValue(6)] = col[3];
        DigitFont_DrawAscii(gUnknown_084F18AC, 0x5E, y, col[0]);
        DigitFont_DrawAscii(gUnknown_084F1920, 0xA2, y, col[1]);
        DigitFont_DrawAscii(gUnknown_084F1924, 0xC8, y, col[2]);
        break;
    case 7:
        if (m->sel != 0)
        {
            Canvas_FillRect(0, canvas, 0xC, 0x7B, 0xE0, 0xA);
            DigitFont_DrawAscii(gUnknown_084F1928, 0x68, 0x7B, tint);
        }
        break;
    }
}

// Options_DrawAll @ 0x080CFBE8
void Options_DrawAll(u32 a)
{
    u32 row;

    for (row = 0; row < 8; row++)
        Options_DrawRow(a, row);
}

// sub_080CFC04 @ 0x080CFC04
void sub_080CFC04(u32 a)
{
    Options_DrawAll(a);
}

// Options_Open @ 0x080CFC10
/* Opens the options (CONFIG) screen: nine windows (pointers at gMenuState+0xC..0x2C). */
void Options_Open(u32 a)
{
    struct C0cdOptions *m = &gOptions;

    m->win[0] = Window_CreateOpen(1, 0, 0x1C, 2, 1);
    m->win[1] = Window_CreateOpen(1, 2, 0x1C, 2, 1);
    m->win[2] = Window_CreateOpen(1, 4, 0x1C, 2, 1);
    m->win[3] = Window_CreateOpen(1, 6, 0x1C, 2, 1);
    m->win[4] = Window_CreateOpen(1, 8, 0x1C, 2, 1);
    m->win[5] = Window_CreateOpen(1, 0xA, 0x1C, 2, 1);
    m->win[6] = Window_CreateOpen(1, 0xC, 0x1C, 2, 1);
    m->win[7] = Window_CreateOpen(1, 0xE, 0x1C, 2, 1);
    m->win[8] = Window_CreateOpen(2, 0x10, 0x1A, 4, 1);
    DmaFill32_3(0, gUnk_0200F874, 0x85002000);
    DigitFont_DrawAscii(gUnknown_084F1930, 0x60, 0xC, 4);
    Options_DrawAll(a);
    Options_DrawHelp(0);
    VBlankTask_AddCounted(sub_080CF61C, 1);
}

// Options_HandleInput @ 0x080CFD00
/* Options screen input: gMenuState.mode is the row (7 = EXIT), .sel the scroll (row 0 hidden,
   EXIT shown), .page the blink phase. */
void Options_HandleInput(struct Task *t)
{
    struct C0c6Status *m = &gMenuState;
    u32 redraw = 0;
    const u16 *opt = gUnknown_084F1938[m->mode];
    u16 count = opt[0];
    u16 cur = Options_GetValue(m->mode);

    t->result = 0;
    if ((gKeysNew & 1) && m->mode == 7)
    {
        t->result = 1;
        Sound_Play(0x65);
    }
    else if (gKeysNew & 2)
    {
        u16 prev = m->mode;

        m->mode = 7;
        if (m->sel == 0)
        {
            m->sel = 1;
            sub_080CFC04((u32)t);
        }
        else
        {
            Options_DrawRow((u32)t, prev);
        }
        Sound_Play(0x66);
    }
    else if ((gRepeatedKeys & 0x40) && m->mode != 0)
    {
        if (m->mode == 1 && m->sel != 0)
        {
            m->mode = 0;
            m->sel = 0;
            sub_080CFC04((u32)t);
        }
        else if (m->mode != 0)
        {
            m->mode--;
            Options_DrawRow((u32)t, m->mode + 1);
        }
        else
        {
            m->mode = 7;
            Options_DrawRow((u32)t, 0);
        }
        Sound_Play(0x64);
        redraw = 1;
    }
    else if ((gRepeatedKeys & 0x80) && m->mode != 7)
    {
        /* row 6 with no scroll: the original tests both halfwords with one word load */
        if (*(u32 *)&m->mode == 6)
        {
            m->mode = 7;
            m->sel = 1;
            sub_080CFC04((u32)t);
        }
        else
        {
            m->mode++;
            Options_DrawRow((u32)t, m->mode - 1);
        }
        redraw = 1;
        Sound_Play(0x64);
    }
    else if ((gKeysNew & 0x20) && m->mode != 7)
    {
        if (cur != 0)
            cur--;
        else
            cur = count - 1;
        Options_SetValue(m->mode, opt[cur + 1]);
        redraw = 1;
        Sound_Play(0x64);
    }
    else if ((gKeysNew & 0x10) && m->mode != 7)
    {
        if (cur != count - 1)
            cur++;
        else
            cur = 0;
        Options_SetValue(m->mode, opt[cur + 1]);
        redraw = 1;
        Sound_Play(0x64);
    }
    if ((gFrameCounter & 3) == 0)
    {
        m->page = (m->page + 1) & 1;
        redraw = 1;
    }
    if (redraw == 1)
    {
        Options_DrawRow((u32)t, m->mode);
        VBlankTask_AddCounted(sub_080CF61C, 1);
    }
    if (!((gFrameCounter >> 4) & 1))
    {
        if (m->sel != 0)
            sub_080C4A4C(0, 0, 0xE8, 0xA);
        else
            sub_080C4AB0(0, 0, 0xE8, 0x80);
    }
}

// Options_Close @ 0x080CFF18
void Options_Close(void)
{
    struct C0cdOptions *m = &gOptions;

    Window_Close(m->win[0], 1);
    Window_Close(m->win[1], 1);
    Window_Close(m->win[2], 1);
    Window_Close(m->win[3], 1);
    Window_Close(m->win[4], 1);
    Window_Close(m->win[5], 1);
    Window_Close(m->win[6], 1);
    Window_Close(m->win[7], 1);
    Window_Close(m->win[8], 1);
    if (m->fromMenu != 0)
        m->fade->unkC = 1;
    else
        sub_080D5B8C(4);
}

// sub_080CFF84 @ 0x080CFF84
void sub_080CFF84(void)
{
    DmaFill16_3(0, 0x06000000, 0x81000800);
    DmaFill16_3(0, 0x06001000, 0x81000800);
    DmaFill16_3(0, 0x06002000, 0x81000800);
}

// sub_080CFFCC @ 0x080CFFCC
void sub_080CFFCC(void)
{
    VBlankTask_AddCounted(sub_080CFF84, 1);
}

// Options_Create @ 0x080CFFE0
struct Task *Options_Create(u16 fromMenu)
{
    struct Task *task = Task_Create(gUnknown_084F1970, 0xFFFF);
    struct C0cdOptions *m = &gOptions;
    vu32 zero = 0;

    CpuSet((void *)&zero, m, 0x05000200);
    m->fromMenu = fromMenu;
    return task;
}

// Options_DrawHelp @ 0x080D0020
/* Draws the help line of option row (for its current value) at (0x12, 0x8C).  The original
   passes an uninitialised canvas (whatever the caller left in r7: gUnk_0200F874 when called
   from Options_DrawRow) after clearing 0x02013C74. */
void Options_DrawHelp(u16 row)
{
    struct C0cdOptions *m = &gOptions;
    u16 cur = Options_GetValue(row);
    const u16 *str = gUnknown_084F1D5C[row][cur];
    u8 *canvas;

    if (row == 7 && m->fromMenu == 0)
        str = gUnknown_084F1D5C[7][1];
    {
        vu32 tmp = 0;
        CpuSet((void *)&tmp, gUnk_02013C74, 0x05000400);
    }
    Text_DrawString(str, canvas, 0x12, 0x8C, 0xC);
}

// sub_080D0084 @ 0x080D0084
/* Shows message msg in the shared window (created on first use), with a yes/no box when ask == 1. */
void sub_080D0084(u32 unused, const void *msg, u32 ask)
{
    struct C0cdMsgMenu *m = &gMsgMenu;

    Font_ResetGlyphSpriteCache(0x180);
    m->msg = msg;
    m->shown = 1;
    if (m->window == NULL)
        m->window = Window_CreateOpen(1, 0xD, 0x1C, 7, 0);
    if (ask == 1)
        m->yesNo = YesNo_Create(1);
}

// sub_080D00CC @ 0x080D00CC
void sub_080D00CC(void)
{
    struct C0cdMsgMenu *m = &gMsgMenu;

    m->shown = 0;
    if (m->window != NULL)
    {
        Window_Close(m->window, 1);
        m->window = NULL;
    }
}

// sub_080D00EC @ 0x080D00EC
void sub_080D00EC(struct Task *t)
{
    u32 r = Task_IsFree(gMsgMenu.yesNo);

    if (r != 1)
        r = 0;
    t->result = r;
}

// sub_080D010C @ 0x080D010C
void sub_080D010C(struct Task *t)
{
    t->pad1E = gYesNoResult;
}

// sub_080D0118 @ 0x080D0118
void sub_080D0118(void)
{
    struct C0cdMsgMenu *m = &gMsgMenu;

    if (m->sel == 2)
        Field_SetState(0x1A);
    else if (m->mode == 4)
        sub_080D5B8C(3);
    else if (m->mode != 3)
        sub_0812D0FC(1);
    else
        Field_SetState(0x19);
}

// sub_080D0154 @ 0x080D0154
void sub_080D0154(void)
{
    struct C0cdMsgMenu *m = &gMsgMenu;

    m->fade = sub_080B6B58(sub_080D0118, 0);
}

// sub_080D0170 @ 0x080D0170
void sub_080D0170(struct Task *t)
{
    struct C0cdMsgMenu *m = &gMsgMenu;

    if (m->fade->unkC == -1)
        t->result = 1;
    else
        t->result = 0;
}

// sub_080D0194 @ 0x080D0194
void sub_080D0194(void)
{
    struct C0cdMsgMenu *m = &gMsgMenu;

    m->fade->unkC = 1;
}

// sub_080D01A4 @ 0x080D01A4
void sub_080D01A4(struct Task *t)
{
    t->pad1E = gMsgMenu.mode;
}

// PlayTime_Draw @ 0x080D01B0
/* Draws a play time (time[0] hours, time[1] minutes) as "HHH:MM" in the small font. */
void PlayTime_Draw(u8 *time, u16 x, u16 y, u16 tint)
{
    u8 buf[8];
    u8 *d;

    d = NumberToDigits(time[0]);
    buf[0] = d[2] + '0';
    buf[1] = d[1] + '0';
    buf[2] = d[0] + '0';
    buf[3] = ':';
    d = NumberToDigits(time[1]);
    buf[4] = d[1] + '0';
    buf[5] = d[0] + '0';
    buf[6] = 0;
    SmallFont_DrawAsciiTinted(buf, gUnk_0200F874, x, y, tint, 8);
}

// sub_080D0238 @ 0x080D0238
void sub_080D0238(void)
{
    struct C0cdMsgMenu *m = &gMsgMenu;

    DmaSet3(gUnk_0200F874, 0x06004000, 0x84001800);
    m->vblankQueued = 0;
}

// sub_080D0264 @ 0x080D0264
void sub_080D0264(void)
{
    struct C0cdMsgMenu *m = &gMsgMenu;

    if (m->vblankQueued == 0)
    {
        VBlankTask_AddCounted(sub_080D0238, 1);
        m->vblankQueued = 1;
    }
}
