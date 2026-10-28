/* Framed windows drawn into the tilemap buffer gWindowMap. */

#include "global.h"
#include "sys.h"

// Window_DrawFrame @ 0x080AB528
/* Draws a w*h window frame at (x, y): corners 0/2/6/8, edges 1/3/5/7, fill 4. */
void Window_DrawFrame(struct WinRect *rect, u16 x, u16 y, u16 w, u16 h)
{
    u16 i, j;

    for (j = 0; j < h; j++)
    {
        for (i = 0; i < w; i++)
        {
            s32 piece = 4;
            u16 *p = &gWindowMap[y + j][x + i];

            if (i == 0 && j == 0)
                piece = 0;
            else if (i == 0 && j == h - 1)
                piece = 6;
            else if (i == w - 1 && j == 0)
                piece = 2;
            else if (i == w - 1 && j == h - 1)
                piece = 8;
            else if (i == 0)
                piece = 3;
            else if (j == 0)
                piece = 1;
            else if (i == w - 1)
                piece = 5;
            else if (j == h - 1)
                piece = 7;
            if (rect->h == 4 && rect->altFrame == 1)
                *p = gWindowFrameTilesAlt[piece];
            else
                *p = gWindowFrameTiles[piece];
        }
    }
}

// WindowMap_QueueUpload @ 0x080AB61C
/* Uploads the map buffer to the given background's VRAM block at the next VBlank. */
void WindowMap_QueueUpload(u32 bg)
{
    switch (bg)
    {
    case 0:
        VBlankTask_AddCounted(WindowMap_UploadToBg0, 1);
        break;
    case 1:
        VBlankTask_AddCounted(WindowMap_UploadToBg1, 1);
        break;
    case 2:
        VBlankTask_AddCounted(WindowMap_UploadToBg2, 1);
        break;
    case 3:
        VBlankTask_AddCounted(WindowMap_UploadToBg3, 1);
        break;
    }
}

// Window_Erase @ 0x080AB660
/* Erases a window. */
void Window_Erase(struct WindowObj *win)
{
    struct WinRect *rect = &win->rect;

    Tilemap_FillRect(0, gWindowMap, win->rect.x, rect->y, rect->w, rect->h);
    WindowMap_QueueUpload(rect->bg);
    gWindowCount--;
}

// sub_080AB69C @ 0x080AB69C
void sub_080AB69C(struct WindowObj *win, u16 cmd)
{
    win->cmd = cmd;
}

// Window_Animate @ 0x080AB6A0
/* One step of opening (mode 0), closing (1) or resizing (2) a window; sets done when
   finished. */
void Window_Animate(struct WindowObj *win, u32 mode)
{
    struct WinRect *rect = &win->rect;

    Window_DrawFrame(rect, win->rect.x, rect->y, rect->w, rect->curH);
    WindowMap_QueueUpload(rect->bg);
    if (mode == 0)
    {
        if (rect->curH == rect->h)
        {
            win->done = 1;
        }
        else
        {
            win->done = 0;
            rect->curH++;
        }
    }
    else if (mode == 1)
    {
        Tilemap_FillRect(0, gWindowMap, win->rect.x, rect->y + rect->curH, rect->w, 1);
        if (rect->curH == 2)
        {
            win->done = 1;
        }
        else
        {
            win->done = 0;
            rect->curH--;
        }
    }
    else
    {
        Tilemap_FillRect(0, gWindowMap, win->rect.x, rect->y + rect->curH, rect->w, 1);
        if (rect->curH == rect->h)
        {
            win->done = 1;
        }
        else
        {
            if (rect->curH > rect->h)
                rect->curH--;
            else
                rect->curH++;
            win->done = 0;
        }
    }
}

// sub_080AB758 @ 0x080AB758
void sub_080AB758(struct WindowObj *win)
{
    struct WinRect *rect = &win->rect;

    if (rect->h == 8 && rect->y == 11 && gMainCallback == FieldMain_Loop)
    {
        gUnk_0200E7D4[0x18] = 1;
        gUnk_0200E7D4[0x1F] = 1;
    }
}

// Windows_Init @ 0x080AB78C
void Windows_Init(void)
{
    DmaFill16(3, 0, gWindowMap, sizeof(gWindowMap));
    DmaFill16(3, 0, gWindowTilemapBuffer, sizeof(gWindowTilemapBuffer));
    gWindowCount = 0;
}

// Window_Create @ 0x080AB7D4
/* Creates a window object; the first open window clears the map buffer. */
struct WindowObj *Window_Create(u16 x, u16 y, u16 w, u16 h, u16 bg)
{
    struct WindowObj *win = Task_Create(gUnknown_0815EB44, 0xFFFF);
    struct WinRect *rect = &win->rect;

    win->rect.x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
    rect->bg = bg;
    rect->altFrame = 0;
    rect->curH = 2;
    if (gWindowCount == 0)
        DmaFill16(3, 0, gWindowMap, sizeof(gWindowMap));
    gWindowCount++;
    return win;
}

// Window_CreateOpen @ 0x080AB860
/* Creates a window that is already fully open. */
struct WindowObj *Window_CreateOpen(u16 x, u16 y, u16 w, u16 h, u16 bg)
{
    struct WindowObj *win = Window_Create(x, y, w, h, bg);
    struct WinRect *rect = &win->rect;

    rect->curH = rect->h;
    return win;
}

// sub_080AB890 @ 0x080AB890
struct WindowObj *sub_080AB890(u16 x, u16 y, u16 w, u16 h, u16 bg)
{
    struct WindowObj *win = Window_Create(x, y, w, h, bg);

    win->rect.altFrame = 1;
    return win;
}

// sub_080AB8BC @ 0x080AB8BC
struct WindowObj *sub_080AB8BC(u16 x, u16 y, u16 w, u16 h, u16 bg)
{
    struct WindowObj *win = Window_Create(x, y, w, h, bg);
    struct WinRect *rect = &win->rect;

    rect->altFrame = 1;
    rect->curH = rect->h;
    return win;
}

// sub_080AB8F0 @ 0x080AB8F0
/* Uploads row 13 of the text map buffer. */
void sub_080AB8F0(void)
{
    u16 *src = gWindowTilemapBuffer;
    u16 *dst = (u16 *)0x06001000;

    src += 13 * 32;
    dst += 13 * 32;
    DmaCopy16(3, src, dst, 0x40);
}

// Window_Close @ 0x080AB91C
/* Closes a window: with animate, sets the close command; otherwise erases and frees it. */
void Window_Close(struct WindowObj *win, u32 erase)
{
    struct WinRect *rect;

    if (win == NULL)
        return;
    rect = &win->rect;
    if (rect->h == 8 && rect->y == 11 && gMainCallback == FieldMain_Loop
        && gUnk_0200E7D4[0x1E] == 0)
    {
        gUnk_0200E7D4[0x1F] = 0;
        if (sub_080C8AF8(gUnk_03004614) == 1 && gUnk_0200E7D4[5] == 0)
            gUnk_0200E7D4[0x18] = 0;
    }
    if (erase == 0)
    {
        win->cmd = 1;
    }
    else
    {
        Window_Erase(win);
        Task_End(win);
    }
}

// Window_SetHeight @ 0x080AB98C
void Window_SetHeight(struct WindowObj *win, u16 h)
{
    win->rect.h = h;
    win->cmd = 2;
}

// Window_IsIdle @ 0x080AB994
bool32 Window_IsIdle(struct WindowObj *win)
{
    bool32 idle = FALSE;

    if (win->active == 0 || win->cmd == 0)
        idle = TRUE;
    return idle;
}

// sub_080AB9B0 @ 0x080AB9B0
void sub_080AB9B0(void)
{
    DmaCopy32(3, gWindowTilemapBuffer, (void *)0x06000000, sizeof(gWindowTilemapBuffer));
}

// sub_080AB9D0 @ 0x080AB9D0
void sub_080AB9D0(void)
{
    DmaCopy32(3, gWindowTilemapBuffer, (void *)0x06001000, sizeof(gWindowTilemapBuffer));
}
