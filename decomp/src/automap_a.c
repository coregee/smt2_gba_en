#include "global.h"
#include "fieldevent.h"

// sub_080B447C @ 0x080B447C
u16 sub_080B447C(void)
{
    u16 dir = gFieldState.unk02;

    if (!sub_080C2BF0())
        dir = 0;
    return dir;
}

// Automap_CellToScreen @ 0x080B449C
void Automap_CellToScreen(u16 x, u16 y, u16 *outX, u16 *outY)
{
    u16 cx, cy;
    u16 px = x * 8;
    u16 py = y * 8;
    u16 dir;

    if (!sub_080C2BF0())
    {
        if (gFieldState.unk1C < 12)
        {
            cx = gFieldState.unk1A >> 1;
            cy = gFieldState.unk1C >> 1;
        }
        else
        {
            cx = gFieldState.unk1A >> 1;
            cy = gFieldState.unk14;
            if ((s16)gFieldState.unk14 < 0)
                cy = 0;
        }
    }
    else
    {
        dir = sub_080B447C();
        if ((dir == 0 || dir == 2) && gFieldState.unk1C < 12)
        {
            cx = gFieldState.unk1A >> 1;
            cy = gFieldState.unk1C >> 1;
        }
        else if (gFieldState.unk1A < 12 && gFieldState.unk1C < 12)
        {
            cx = gFieldState.unk1A >> 1;
            cy = gFieldState.unk1C >> 1;
        }
        else if (dir == 0 || dir == 2)
        {
            cx = gFieldState.unk1A >> 1;
            cy = gFieldState.unk14;
            if ((s16)gFieldState.unk14 < 0)
                cy = 0;
        }
        else
        {
            cy = gFieldState.unk1C >> 1;
            cx = gFieldState.unk12;
            if ((s16)gFieldState.unk12 < 0)
                cx = 0;
        }
    }

    switch (sub_080B447C())
    {
    case 0:
        *outX = (13 - cx) * 8;
        *outY = (5 - cy) * 8;
        *outX += px;
        *outY += py;
        *outY += gUnk_0200DFCE * 8;
        break;
    case 1:
        *outX = (13 - cy) * 8;
        *outY = (cx + 5) * 8;
        *outX += py;
        *outY -= px;
        *outY += gUnk_0200DFCE * 8;
        break;
    case 2:
        *outX = (cx + 13) * 8;
        *outY = (cy + 5) * 8;
        *outX -= px;
        *outY -= py;
        *outY += gUnk_0200DFCE * 8;
        break;
    case 3:
        *outX = (cy + 13) * 8;
        *outY = (5 - cx) * 8;
        *outX -= py;
        *outY += px;
        *outY += gUnk_0200DFCE * 8;
        break;
    }
}

// Automap_DrawMarkerSprite @ 0x080B4610
void Automap_DrawMarkerSprite(u16 x, u16 y, const void *sprite)
{
    u16 px, py;

    if (Automap_IsVisitedUnchecked(x, y))
    {
        Automap_CellToScreen(x, y, &px, &py);
        if (py < 0x58)
            Sprite_Draw(sprite, 2, 0, 2, 0x240, px + 8, py);
    }
}

// Automap_DrawSprites @ 0x080B466C
void Automap_DrawSprites(void)
{
    u32 i;
    u16 x, y;
    u16 *buf;

    if (gUnk_03003FFC == 1)
        return;

    for (i = 0; i < 8; i++)
    {
        struct MapMarker *m = &gMapMarkers[i];

        if (m->map == gUnk_03004614 && m->floor == gUnk_03004514)
            Automap_DrawMarkerSprite(m->x, m->y, gUnknown_081629E4[m->sprite]);
    }

    if (gUnk_03003FFC != 2)
    {
        if (!sub_080C2BF0())
            Automap_DrawMarkerSprite(gFieldState.unk12, gFieldState.unk14, gUnknown_081629F8[gFieldState.unk02]);
        else
            Automap_DrawMarkerSprite(gFieldState.unk12, gFieldState.unk14, gUnknown_081629F8[0]);
    }

    buf = gBgPictureBuffer;
    for (y = 0; y < gFieldState.unk1C; y++)
    {
        for (x = 0; x < gFieldState.unk1A; x++)
        {
            const void *sprite = gUnknown_08162A08[buf[y * 32 + x]];

            if (sprite != NULL)
                Automap_DrawMarkerSprite(x, y, sprite);
        }
    }

    if (gFieldState.unk1E != 0x36)
        MarkerHeader_DrawLocationName(0, 0, 0x12, 0x59, 0xC);

    if (gUnk_0200DFD2 == 0)
    {
        if (gUnk_0200DFCA == 1)
            sub_080C4A4C(2, 2, 200, 0x30);
        if (gUnk_0200DFC8 == 1)
            sub_080C4AB0(2, 2, 200, 0x48);
    }
}

// Automap_BuildAroundPlayer @ 0x080B47CC
void Automap_BuildAroundPlayer(void)
{
    u16 dir = sub_080B447C();
    u16 x, y;

    if (!sub_080C2BF0())
    {
        if (gFieldState.unk1C < 12)
            Automap_Build(dir, gFieldState.unk1A / 2, gFieldState.unk1C / 2);
        else
        {
            x = gFieldState.unk1A / 2;
            y = gFieldState.unk14;
            Automap_Build(dir, x, y);
        }
    }
    else if ((dir == 0 || dir == 2) && gFieldState.unk1C < 12)
        Automap_Build(dir, gFieldState.unk1A / 2, gFieldState.unk1C / 2);
    else if (gFieldState.unk1A < 12 && gFieldState.unk1C < 12)
        Automap_Build(dir, gFieldState.unk1A / 2, gFieldState.unk1C / 2);
    else
    {
        if (dir == 0 || dir == 2)
        {
            x = gFieldState.unk1A / 2;
            y = gFieldState.unk14;
        }
        else
        {
            x = gFieldState.unk12;
            y = gFieldState.unk1C / 2;
        }
        Automap_Build(dir, x, y);
    }
}

// Automap_BuildIconMap @ 0x080B4854
/* Fills gBgPictureBuffer (32 columns per row) with the automap icon of every map square,
   chosen from the square's records. */
void Automap_BuildIconMap(void)
{
    u16 *buf = gBgPictureBuffer;
    u32 zero = 0;
    u16 x, y;

    CpuSet(&zero, buf, 0x05000C00);
    for (y = 0; y < gFieldState.unk1C; y++)
    {
        for (x = 0; x < gFieldState.unk1A; x++)
        {
            s32 recs = FieldMap_CellRecordsAt(x, y);
            u16 *dst = &buf[y * 32 + x];
            u16 *rec;

            if ((rec = FieldMap_FindRecord(recs, 0x23)) != NULL)
                *dst = rec[1] + 1;
            else if (FieldMap_FindRecord(recs, 4) != NULL)
                *dst = 0xF;
            else if ((rec = FieldMap_FindRecord(recs, 1)) != NULL)
            {
                if (rec[1] != 0)
                    *dst = 8;
            }
            else if ((rec = FieldMap_FindRecord(recs, 2)) != NULL)
            {
                if (rec[1] != 0)
                    *dst = 9;
            }
            else if ((rec = FieldMap_FindRecord(recs, 0x1B)) != NULL)
            {
                if (rec[1] != 0)
                    *dst = 8;
            }
            else if ((rec = FieldMap_FindRecord(recs, 0x1C)) != NULL)
            {
                if (rec[1] != 0)
                    *dst = 9;
            }
            else if (FieldMap_FindRecord(recs, 0x10) != NULL)
                *dst = 0xB;
            else if (FieldMap_FindRecord(recs, 3) != NULL)
                *dst = 0xA;
            else if (FieldMap_FindRecord(recs, 0x22) != NULL)
                *dst = 0x11;
            else if (FieldMap_FindRecord(recs, 0xB) != NULL)
            {
                u16 kind = FieldMap_FindRecord(recs, 0xB)[4];

                if (kind == 7)
                    *dst = 0x14;
                else if (kind == 9)
                    *dst = 0x16;
                else if (kind == 10)
                    *dst = 0x21;
                else
                    *dst = 0x11;
            }
            else if (FieldMap_FindRecord(recs, 0xC) != NULL)
                *dst = 7;
            else if (FieldMap_FindRecord(recs, 0xD) != NULL)
            {
                if (gUnk_03004614 != 0x1A || gUnk_03004514 != 1 || Flag_Test(0x15))
                    *dst = 0xC;
            }
            else if (FieldMap_FindRecord(recs, 0xE) != NULL)
                *dst = 0xD;
            else if (FieldMap_FindRecord(recs, 0xF) != NULL)
                *dst = 0xE;
            else if (FieldMap_FindRecord(recs, 0x11) != NULL)
                *dst = 0x14;
            else if (FieldMap_FindRecord(recs, 0x25) != NULL)
                *dst = 0x22;
            else if (FieldMap_FindRecord(recs, 0x26) != NULL)
                *dst = 0x23;
            else if (FieldMap_FindRecord(recs, 0x27) != NULL)
                *dst = 0x24;
        }
    }
}

// Automap_HasCells @ 0x080B4A54
/* TRUE when any automap cell is in use. */
u32 Automap_HasCells(void)
{
    u16 w = 28;
    u16 h = 11;
    u16 x, y;

    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            if (gAutomapCells[y][x].flags != 0)
                return TRUE;
        }
    }
    return FALSE;
}

// Automap_DrawTilemap @ 0x080B4AA4
/* Draws the automap cells into the BG tilemap at 0x02000000 (column 0 left empty). */
void Automap_DrawTilemap(void)
{
    u16 w = 28, h = 11;
    u16 x, y;
    u16 (*bg)[32] = gUnk_02000000; /* base in a variable: the hoisted row address adds into it */

    sub_080B447C();
    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            if (gAutomapCells[y][x].flags != 0)
            {
                u16 *row = bg[y];
                u16 *dst = &row[x + 1];
                u16 tile = sub_080B4448(&gAutomapCells[y][x]);

                if (!(gAutomapCells[y][x].flags & 0x8000))
                    *dst = tile;
                else
                    *dst = tile | 0x6000;
            }
        }
    }
    Automap_BuildIconMap();
    VBlankTask_AddCounted(sub_080B5084, 1);
}

// sub_080B4B58 @ 0x080B4B58
void sub_080B4B58(void)
{
    DmaCopy32(3, gBgPictureBuffer, (void *)0x06014800, 0x1000);
}

// sub_080B4B7C @ 0x080B4B7C
void sub_080B4B7C(void)
{
    DmaCopy32(3, gBgPictureBuffer, (void *)0x06015800, 0x1000);
}

// sub_080B4BA0 @ 0x080B4BA0
void sub_080B4BA0(void)
{
    DmaCopy32(3, gBgPictureBuffer, (void *)0x06016800, 0x1000);
}

// sub_080B4BC4 @ 0x080B4BC4
void sub_080B4BC4(void)
{
    DmaCopy32(3, gBgPictureBuffer, (void *)0x06017800, 0x800);
}
