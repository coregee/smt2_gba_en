#include "global.h"
#include "text.h"

// TextWindow_UploadTilemapSbb4 @ 0x080AB9F4
void TextWindow_UploadTilemapSbb4(void)
{
    TEXT_DMA3_SET(0x0200DFD4, 0x06002000, 0x84000200);
}

// TextWindow_UploadTilemapSbb6 @ 0x080ABA18
void TextWindow_UploadTilemapSbb6(void)
{
    TEXT_DMA3_SET(0x0200DFD4, 0x06003000, 0x84000200);
}

// TextWindow_DrawFrame @ 0x080ABA3C
void TextWindow_DrawFrame(struct TextWindow *win, u16 x, u16 y, u16 w, u16 h)
{
    u16 row, col;

    for (row = 0; row < h; row++)
    {
        for (col = 0; col < w; col++)
        {
            s32 tile = 4;
            u16 *dst = &gWindowTilemapBuffer[y + row][x + col];

            if (col == 0 && row == 0)
                tile = 0;
            else if (col == 0 && row == h - 1)
                tile = 6;
            else if (col == w - 1 && row == 0)
                tile = 2;
            else if (col == w - 1 && row == h - 1)
                tile = 8;
            else if (col == 0)
                tile = 3;
            else if (row == 0)
                tile = 1;
            else if (col == w - 1)
                tile = 5;
            else if (row == h - 1)
                tile = 7;

            if (win->frame == NULL)
                *dst = gDefaultWindowFrameTiles[tile];
            else
                *dst = win->frame[tile];
        }
    }
}

// TextWindow_QueueTilemapUpload @ 0x080ABB20
void TextWindow_QueueTilemapUpload(u32 screen)
{
    switch (screen)
    {
    case 0:
        VBlankTask_AddCounted(sub_080AB9B0, 1);
        break;
    case 1:
        VBlankTask_AddCounted(sub_080AB9D0, 1);
        break;
    case 2:
        VBlankTask_AddCounted(TextWindow_UploadTilemapSbb4, 1);
        break;
    case 3:
        VBlankTask_AddCounted(TextWindow_UploadTilemapSbb6, 1);
        break;
    }
}

// TextWindow_Erase @ 0x080ABB64
void TextWindow_Erase(struct Task *task)
{
    struct TextWindow *win = &task->data.win;

    Tilemap_FillRect(0, &gWindowTilemapBuffer[0][0], task->data.win.x, win->y, win->w, win->h);
    TextWindow_QueueTilemapUpload(win->screen);
    gOpenWindowCount--;
}

// sub_080ABBA0 @ 0x080ABBA0
void sub_080ABBA0(struct Task *task, u16 val)
{
    task->unk1E = val;
}

/* Window open/close animation step: mode 0 grows to full height, 1 shrinks to the 2-row
   minimum clearing the row it leaves, other values move curH toward h.  Sets
   task->result when done. */
// TextWindow_AnimateStep @ 0x080ABBA4
void TextWindow_AnimateStep(struct Task *task, s32 mode)
{
    struct TextWindow *win = &task->data.win;

    TextWindow_DrawFrame(win, task->data.win.x, win->y, win->w, win->curH);
    TextWindow_QueueTilemapUpload(win->screen);

    if (mode == 0)
    {
        if (win->curH == win->h)
        {
            task->result = 1;
        }
        else
        {
            task->result = 0;
            win->curH++;
        }
    }
    else if (mode == 1)
    {
        Tilemap_FillRect(0, &gWindowTilemapBuffer[0][0], task->data.win.x, win->y + win->curH, win->w, 1);
        if (win->curH == 2)
        {
            task->result = 1;
        }
        else
        {
            task->result = 0;
            win->curH--;
        }
    }
    else
    {
        if (win->curH == win->h)
        {
            task->result = 1;
        }
        else
        {
            if (win->curH > win->h)
                win->curH--;
            else
                win->curH++;
            task->result = 0;
        }
    }
}

// TextWindow_Create @ 0x080ABC40
struct Task *TextWindow_Create(u16 x, u16 y, u16 w, u16 h, u16 screen)
{
    struct Task *task = Task_Create(gUnknown_0815EC40, 0xFFFF);
    struct TextWindow *win = &task->data.win;

    task->data.win.x = x;
    win->y = y;
    win->w = w;
    win->h = h;
    win->screen = screen;
    win->frame = NULL;
    win->curH = 2;
    gOpenWindowCount++;
    return task;
}

// TextWindow_CreateWithFrame @ 0x080ABCAC
struct Task *TextWindow_CreateWithFrame(u16 x, u16 y, u16 w, u16 h, const u16 *frame)
{
    struct Task *task = TextWindow_Create(x, y, w, h, 1);

    task->data.win.frame = frame;
    return task;
}

/* Like TextWindow_Create but already fully open. */
// TextWindow_CreateOpen @ 0x080ABCD4
struct Task *TextWindow_CreateOpen(u16 x, u16 y, u16 w, u16 h, u16 screen)
{
    struct Task *task = TextWindow_Create(x, y, w, h, screen);
    struct TextWindow *win = &task->data.win;

    win->curH = win->h;
    return task;
}

// TextWindow_CreateOpenWithFrame @ 0x080ABD04
struct Task *TextWindow_CreateOpenWithFrame(u16 x, u16 y, u16 w, u16 h, u16 screen, const u16 *frame)
{
    struct Task *task = TextWindow_CreateOpen(x, y, w, h, screen);

    task->data.win.frame = frame;
    return task;
}

// TextWindow_Close @ 0x080ABD30
void TextWindow_Close(struct Task *task, s32 now)
{
    if (now == 0)
    {
        task->unk1E = 1;
    }
    else
    {
        TextWindow_Erase(task);
        Task_End(task);
    }
}

// sub_080ABD50 @ 0x080ABD50
void sub_080ABD50(struct Task *task, u16 val)
{
    task->data.h[1] = val;
    task->unk1E = 2;
}

// TextWindow_IsDone @ 0x080ABD58
bool32 TextWindow_IsDone(struct Task *task)
{
    bool32 done = FALSE;

    if (task->state == 0 || task->unk1E == 0)
        done = TRUE;
    return done;
}

// YesNo_UploadCursorTiles @ 0x080ABD74
void YesNo_UploadCursorTiles(void)
{
    TEXT_DMA3_SET(gBannerTiles, 0x06010000 + gUnk_03000048 * 32, 0x84000040);
}

// YesNo_LoadCursor @ 0x080ABDA4
void YesNo_LoadCursor(struct Task *task, s32 mode)
{
    struct YesNoCursor *cur = &task->data.yesNo;

    if (mode == 0)
    {
        Hud_RenderGlyphTiles(gBannerTiles, gUnknown_0815ED28);
        gUnk_03000048 = cur->tile;
        VBlankTask_AddCounted(YesNo_UploadCursorTiles, 1);
    }
}

// YesNo_HandleInput @ 0x080ABDDC
void YesNo_HandleInput(struct Task *task)
{
    struct YesNoCursor *cur = &task->data.yesNo;

    task->result = 0;
    if (gKeysNew & 1)
    {
        gYesNoResult = cur->choice;
        task->result = 1;
        if (gYesNoResult == 0)
            Sound_Play(0x65);
        else
            Sound_Play(0x66);
    }
    else if (gRepeatedKeys & 0xC0)
    {
        cur->choice = (cur->choice + 1) & 1;
        Sound_Play(0x64);
    }
}

// sub_080ABE40 @ 0x080ABE40
void sub_080ABE40(void)
{
}

// YesNo_DrawCursor @ 0x080ABE44
void YesNo_DrawCursor(struct Task *task)
{
    struct YesNoCursor *cur = &task->data.yesNo;
    u16 a = 0;
    u16 b = 0;

    Sprite_Draw(gUnknown_08001058, 0, 0, 0, 0, 200, 0x80);
    if (cur->choice == 0)
        a = 2;
    else
        b = 2;
    Sprite_DrawSingle(gUnknown_0815ED30, 0, a, 0, cur->tile, 0xCD, 0x86);
    Sprite_DrawSingle(gUnknown_0815ED38, 0, b, 0, cur->tile, 0xCD, 0x92);
}

// YesNo_Create @ 0x080ABEB4
struct Task *YesNo_Create(u16 choice)
{
    struct Task *task = Task_Create(gUnknown_0815ED40, 0xFFFF);
    struct YesNoCursor *cur = &task->data.yesNo;

    cur->choice = choice;
    cur->tile = 0x178;
    return task;
}

// YesNo_CreateWithTile @ 0x080ABEE0
struct Task *YesNo_CreateWithTile(u16 choice, u16 tile)
{
    struct Task *task = YesNo_Create(choice);
    struct YesNoCursor *cur = &task->data.yesNo;

    cur->choice = choice;
    cur->tile = tile;
    return task;
}

// Task_IsFree @ 0x080ABF04
bool32 Task_IsFree(struct Task *task)
{
    bool32 done = FALSE;

    if (task->state == 0)
        done = TRUE;
    return done;
}

// YesNo_StoreResult @ 0x080ABF18
void YesNo_StoreResult(struct Task *task)
{
    task->unk1E = gYesNoResult;
}
