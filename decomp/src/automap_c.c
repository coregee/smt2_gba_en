/* Automap markers: the task callbacks of the marker menu (placing, moving to and removing the
   eight markers at gMapMarkers). */

#include "global.h"
#include "fieldevent.h"

// sub_080B51F0 @ 0x080B51F0
void sub_080B51F0(struct Task *task)
{
    struct MarkerMenu *d = (struct MarkerMenu *)task->data;

    d->window = Window_CreateOpen(2, 0xD, 0x1A, 7, 0);
}

// sub_080B5214 @ 0x080B5214
void sub_080B5214(struct Task *task, u32 arg)
{
    sub_080C6E30((u16)arg);
    if (arg == 1)
    {
        Font_ResetGlyphSpriteCache(0x100);
    }
    else
    {
        Font_ResetGlyphSpriteCache(0x180);
        VBlankTask_AddCounted(sub_080C8440, 1);
    }
}

// MarkerMenu_DrawCrosshair @ 0x080B5248
/* Draws the cross-hair lines through the marker cursor. */
void MarkerMenu_DrawCrosshair(struct Task *task, u16 palette)
{
    struct MarkerMenu *d = (struct MarkerMenu *)task->data;
    u32 i;

    for (i = 0; i < 7; i++)
        Sprite_Draw(gUnknown_08000508, 1, palette, 2, 0x240, i * 32 + 8, d->y * 8);
    for (i = 0; i < 3; i++)
        Sprite_Draw(gUnknown_08000518, 1, palette, 2, 0x240, d->x * 8 + 8, i * 32);
}

// MarkerMenu_Draw @ 0x080B52C4
void MarkerMenu_Draw(struct Task *task)
{
    struct MarkerMenu *d = (struct MarkerMenu *)task->data;
    u32 i;
    u16 y;

    switch (d->state)
    {
    case 0:
        MarkerHeader_DrawLocationName(0, 0, 0x12, 0x59, 0xC);
        break;
    case 1:
        if (d->busy == 0)
            Text_DrawSpriteString(gUnknown_08162B1C, 0, 0, 0x12, 0x59, 0xC);
        else
            Text_DrawSpriteString(gUnknown_08162B56, 0, 0, 0x12, 0x59, 0xC);
        MarkerMenu_DrawCrosshair(task, 0);
        break;
    case 2:
        Text_DrawSpriteString(gUnknown_08162B34, 0, 0, 0x12, 0x59, 0xC);
        Sprite_Draw(gUnknown_080004AC, 0, 0, 0, 0x240, 0x12, 0x10);
        Sprite_Draw(gUnknown_080004C4, 1, 0, 0, 0x240, 0x12, d->kind * 12 + 12);
        switch (d->kind)
        {
        case 0:
            Text_DrawSpriteString(gUnknown_08162B8E, 0, 0, 0x6C, 4, 0xC);
            Text_DrawSpriteString(gUnknown_08162B9C, 0, 0, 0x6C, 0x10, 0xC);
            break;
        case 1:
            Text_DrawSpriteString(gUnknown_08162BA8, 0, 0, 0x6C, 4, 0xC);
            Text_DrawSpriteString(gUnknown_08162BBE, 0, 0, 0x6C, 0x10, 0xC);
            break;
        case 2:
            Text_DrawSpriteString(gUnknown_08162BD0, 0, 0, 0x6C, 4, 0xC);
            Text_DrawSpriteString(gUnknown_08162BE4, 0, 0, 0x6C, 0x10, 0xC);
            break;
        case 3:
            Text_DrawSpriteString(gUnknown_08162BF6, 0, 0, 0x6C, 4, 0xC);
            Text_DrawSpriteString(gUnknown_08162C06, 0, 0, 0x6C, 0x10, 0xC);
            break;
        case 4:
            Text_DrawSpriteString(gUnknown_08162C12, 0, 0, 0x6C, 4, 0xC);
            Text_DrawSpriteString(gUnknown_08162C26, 0, 0, 0x6C, 0x10, 0xC);
            break;
        }
        MarkerMenu_DrawCrosshair(task, 0);
        break;
    case 3:
        Text_DrawSpriteString(gUnknown_08162B76, 0, 0, 0x12, 0x59, 0xC);
        MarkerMenu_DrawCrosshair(task, 2);
        break;
    }

    y = (d->cursor - d->top) * 12 + 0x68;
    Sprite_Draw(gUnknown_080004F8, 1, 0, 0, 0x240, 0x5D, y + 1);
    for (i = 0; i < 4; i++)
    {
        struct MapMarker *m = &gMapMarkers[i + d->top];

        if (m->map != 0xFF)
            MarkerList_DrawLocationName(m->map, m->floor, m->x, m->y, 1, 0, 0x12, i * 12 + 0x69);
        else
            Text_DrawSpriteString(gUnknown_08162B0C, 1, 0, 0x12, i * 12 + 0x69, 0xC);
    }
}

// MarkerMenu_SetState @ 0x080B5534
void MarkerMenu_SetState(struct Task *task, u16 state)
{
    struct MarkerMenu *d = (struct MarkerMenu *)task->data;

    d->state = state;
    if (state == 2)
        d->kind = 0;
}

// sub_080B554C @ 0x080B554C
void sub_080B554C(struct Task *task, u16 state)
{
    MarkerMenu_SetState(task, state);
}

// MarkerMenu_HandleList @ 0x080B555C
/* Marker list: A picks a marker (empty: place one), B leaves, up/down/L/R move the cursor. */
void MarkerMenu_HandleList(struct Task *task)
{
    struct MarkerMenu *d = (struct MarkerMenu *)task->data;

    task->unk1E = 0;
    if (gFieldState.unk3A & 1)
    {
        struct MapMarker *m = &gMapMarkers[d->cursor];

        Sound_Play(0x65);
        if (m->map == 0xFF)
        {
            task->unk1E = 1;
            MarkerMenu_SetState(task, 1);
            d->x = 13;
            d->y = 5;
        }
        else
        {
            task->unk1E = 3;
            gUnk_0200DFD2 = 1;
        }
    }
    else if (gFieldState.unk3A & 2)
    {
        Sound_Play(0x66);
        task->unk1E = 2;
    }
    else if (gFieldState.unk3C & 0x40)
    {
        if (d->cursor != 0)
        {
            Sound_Play(0x64);
            d->cursor--;
            if (d->top > d->cursor)
                d->top--;
        }
    }
    else if (gFieldState.unk3C & 0x80)
    {
        if (d->cursor != 7)
        {
            Sound_Play(0x64);
            d->cursor++;
            if (d->cursor - d->top > 3)
                d->top++;
        }
    }
    else if (gRepeatedKeys & 0x200)
    {
        if (d->cursor != 0)
        {
            u16 n = d->cursor - d->top;

            if (n == 0)
            {
                d->cursor = 0;
                d->top = 0;
            }
            else
            {
                d->cursor -= n;
            }
            Sound_Play(0x64);
        }
    }
    else if (gRepeatedKeys & 0x100)
    {
        if (d->cursor != 7)
        {
            u16 n = 3 - (d->cursor - d->top);

            if (n == 0)
            {
                d->cursor = 7;
                d->top = 4;
            }
            else
            {
                d->cursor += n;
            }
            Sound_Play(0x64);
        }
    }

    if (d->top != 0)
        sub_080C4A4C(0, 0, 0xD6, 0x6A);
    if (d->top != 4)
        sub_080C4AB0(0, 0, 0xD6, 0x98);
}

// Automap_CellToMap @ 0x080B56B8
/* Map coordinates of automap cell (cx, cy). */
void Automap_CellToMap(u16 cx, u16 cy, u16 *x, u16 *y)
{
    struct AutomapCell *cell = &gAutomapCells[cy][cx];

    *x = cell->x;
    *y = cell->y;
}

// MarkerMenu_CanPlace @ 0x080B56EC
/* TRUE when the cursor is on a known square that no other marker of this floor uses. */
u32 MarkerMenu_CanPlace(struct Task *task)
{
    struct MarkerMenu *d = (struct MarkerMenu *)task->data;
    u16 x, y;
    u32 i;

    if (gAutomapCells[d->y][d->x].flags == 0)
        return FALSE;
    Automap_CellToMap(d->x, d->y, &x, &y);
    for (i = 0; i < 8; i++)
    {
        if (d->cursor != i)
        {
            struct MapMarker *m = &gMapMarkers[i];

            if (m->map == gUnk_03004614 && m->floor == gUnk_03004514 && m->x == x && m->y == y)
                return FALSE;
        }
    }
    return TRUE;
}

// MarkerMenu_HandleCursor @ 0x080B577C
/* Marker placement: moves the cursor over the automap (scrolling it at the edges). */
void MarkerMenu_HandleCursor(struct Task *task)
{
    struct MarkerMenu *d = (struct MarkerMenu *)task->data;

    Font_ResetGlyphSpriteCache(0x100);
    task->unk1E = 0;
    if (d->busy == 0)
    {
        if (gFieldState.unk3A & 1)
        {
            Sound_Play(0x65);
            Automap_BuildAroundPlayer();
            if (MarkerMenu_CanPlace(task) == 1)
            {
                task->unk1E = 1;
                d->window1 = TextWindow_CreateOpen(0xD, 0, 0x10, 5, 1);
                d->window2 = TextWindow_CreateOpen(2, 1, 0xA, 9, 1);
            }
            else
            {
                d->busy = 1;
            }
        }
        else if (gFieldState.unk3A & 2)
        {
            task->unk1E = 2;
            MarkerMenu_SetState(task, 0);
            Sound_Play(0x66);
        }
        else if (gRepeatedKeys & 0x40)
        {
            if (d->y != 0)
            {
                Sound_Play(0x64);
                d->y--;
            }
            else if (gUnk_0200DFCA == 1)
            {
                if (gAutomapScroll <= 0 || Automap_HasCells() == 1)
                {
                    gAutomapScroll++;
                    Automap_BuildAroundPlayer();
                    Tilemap_CopyRectSkipZero(gUnknown_081B8D70, gUnk_02000000, 0, 0, 1, 0, 0x1C, 0xD);
                    Automap_DrawTilemap();
                    gUnk_0200DFCE = gAutomapScroll;
                    Automap_DrawSprites();
                }
            }
        }
        else if (gRepeatedKeys & 0x80)
        {
            if (d->y != 10)
            {
                Sound_Play(0x64);
                d->y++;
            }
            else if (gUnk_0200DFC8 == 1)
            {
                if (gAutomapScroll >= 0 || Automap_HasCells() == 1)
                {
                    gAutomapScroll--;
                    Automap_BuildAroundPlayer();
                    Tilemap_CopyRectSkipZero(gUnknown_081B8D70, gUnk_02000000, 0, 0, 1, 0, 0x1C, 0xD);
                    Automap_DrawTilemap();
                    gUnk_0200DFCE = gAutomapScroll;
                    Automap_DrawSprites();
                }
            }
        }
        else if (gRepeatedKeys & 0x20)
        {
            if (d->x != 0)
            {
                Sound_Play(0x64);
                d->x--;
            }
        }
        else if (gRepeatedKeys & 0x10)
        {
            if (d->x != 0x1B)
            {
                Sound_Play(0x64);
                d->x++;
            }
        }
    }
    else if ((gFieldState.unk3A & 1) || (gFieldState.unk3A & 2))
    {
        d->busy = 0;
    }
}

// MarkerMenu_Place @ 0x080B592C
/* Stores the marker under the cursor in slot d->cursor. */
void MarkerMenu_Place(struct Task *task)
{
    struct MarkerMenu *d = (struct MarkerMenu *)task->data;
    u16 x, y;
    struct MapMarker *m;

    Automap_CellToMap(d->x, d->y, &x, &y);
    m = &gMapMarkers[d->cursor];
    m->x = x;
    m->y = y;
    m->map = gUnk_03004614;
    m->floor = gUnk_03004514;
    m->sprite = d->kind;
}

// MarkerMenu_Clear @ 0x080B597C
/* Clears marker slot d->cursor. */
void MarkerMenu_Clear(struct Task *task)
{
    struct MarkerMenu *d = (struct MarkerMenu *)task->data;
    struct MapMarker *m = &gMapMarkers[d->cursor];

    m->x = 0;
    m->y = 0;
    m->map = 0xFF;
    m->sprite = 0;
}

// MarkerMenu_HandleKind @ 0x080B5998
/* Marker kind choice. */
void MarkerMenu_HandleKind(struct Task *task)
{
    struct MarkerMenu *d = (struct MarkerMenu *)task->data;

    Font_ResetGlyphSpriteCache(0x100);
    task->unk1E = 0;
    if (gFieldState.unk3A & 1)
    {
        task->unk1E = 1;
        MarkerMenu_SetState(task, 0);
        MarkerMenu_Place(task);
        Sound_Play(0x65);
    }
    else if (gFieldState.unk3A & 2)
    {
        task->unk1E = 2;
        MarkerMenu_SetState(task, 1);
        Sound_Play(0x66);
        if (d->window1 != 0)
            TextWindow_Close(d->window1, 1);
        if (d->window2 != 0)
            TextWindow_Close(d->window2, 1);
    }
    else if (gFieldState.unk3C & 0x40)
    {
        if (d->kind != 0)
        {
            Sound_Play(0x64);
            d->kind--;
        }
    }
    else if (gFieldState.unk3C & 0x80)
    {
        if (d->kind != 4)
        {
            Sound_Play(0x64);
            d->kind++;
        }
    }
}

// sub_080B5A4C @ 0x080B5A4C
void sub_080B5A4C(struct Task *task)
{
    struct MarkerMenu *d = (struct MarkerMenu *)task->data;
    u32 r;

    Font_ResetGlyphSpriteCache(0x100);
    task->unk1E = 0;
    r = Task_IsFree(d->yesNo);
    if (r == 1)
    {
        if (gYesNoResult == 0)
        {
            task->unk1E = r;
            MarkerMenu_Clear(task);
        }
        else
        {
            task->unk1E = r;
        }
        gAutomapScroll = 0;
        gUnk_0200DFCE = 0;
        d->savedScroll = 0;
        d->savedScroll2 = 0;
    }
}

// MarkerMenu_HandleEvent @ 0x080B5AA4
/* Event handler of the marker task: 2 shows the marked floor, 5 goes back to the player's. */
void MarkerMenu_HandleEvent(struct Task *task, u32 event)
{
    struct MarkerMenu *d = (struct MarkerMenu *)task->data;
    struct MapMarker *m = &gMapMarkers[d->cursor];

    task->result = 0;
    switch (event)
    {
    case 0:
        gUnk_03003FFC = 1;
        task->result = 1;
        break;
    case 2:
    {
        u16 x1, y1, x2, y2;

        d->savedMap = gUnk_03004614;
        d->savedFloor = gUnk_03004514;
        d->savedX = gFieldState.unk12;
        d->savedY = gFieldState.unk14;
        d->savedScroll = gAutomapScroll;
        d->savedScroll2 = gUnk_0200DFCE;
        gAutomapScroll = 0;
        gUnk_0200DFCE = 0;
        gUnk_03004614 = m->map;
        gUnk_03004514 = m->floor;
        gFieldState.unk12 = m->x;
        gFieldState.unk14 = m->y;
        sub_080AE234();
        Automap_CellToScreen(m->x, m->y, &x1, &y1);
        d->x = x1 >> 3;
        d->y = y1 >> 3;
        Automap_BuildAroundPlayer();
        Automap_DrawTilemap();
        MarkerMenu_SetState(task, 3);
        Automap_CellToScreen(m->x, m->y, &x2, &y2);
        d->x = x2 >> 3;
        d->y = y2 >> 3;
        gUnk_03003FFC = 2;
        d->yesNo = YesNo_CreateWithTile(0, 0x3F7);
        break;
    }
    case 3:
        gUnk_03003FFC = 1;
        break;
    case 1:
    case 4:
        sub_080C14FC();
        VBlankTask_AddCounted(sub_080C153C, 1);
        break;
    case 5:
    {
        u16 x, y;

        gUnk_0200DFD2 = 0;
        gUnk_03004614 = d->savedMap;
        gUnk_03004514 = d->savedFloor;
        gFieldState.unk12 = d->savedX;
        gFieldState.unk14 = d->savedY;
        gAutomapScroll = d->savedScroll;
        gUnk_0200DFCE = d->savedScroll2;
        gUnk_03003FFC = 0;
        sub_080AE234();
        Automap_CellToScreen(m->x, m->y, &x, &y);
        d->x = x >> 3;
        d->y = y >> 3;
        if (gUnk_03004614 == 0x42)
            gFieldState.unk50 = 2;
        Tilemap_CopyRectSkipZero(gUnknown_081B8D70, gUnk_02000000, 0, 0, 1, 0, 0x1C, 0xD);
        Automap_BuildAroundPlayer();
        Automap_DrawTilemap();
        break;
    }
    }
}

// sub_080B5CA8 @ 0x080B5CA8
void sub_080B5CA8(struct Task *task)
{
    struct MarkerMenu *d = (struct MarkerMenu *)task->data;

    if (d->window != 0)
        Window_Close(d->window, 1);
    if (d->window1 != 0)
        TextWindow_Close(d->window1, 1);
    if (d->window2 != 0)
        TextWindow_Close(d->window2, 1);
}
