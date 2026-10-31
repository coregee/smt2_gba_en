/* Tilemap helpers for 32-tile-wide maps. */

#include "global.h"
#include "sys.h"

// Tilemap_OffsetRect @ 0x080AB1C4
/* Adds tileAdd to the tile numbers of a w*h rectangle at (x, y) and sets its palette. */
void Tilemap_OffsetRect(u16 (*map)[32], u16 tileAdd, u16 palette, u16 x, u16 y, u16 w, u16 h)
{
    u16 i, j;

    for (j = 0; j < h; j++)
    {
        for (i = 0; i < w; i++)
        {
            u16 *p = &map[j + y][i + x];

            *p += tileAdd;
            *p = (*p & 0xFFF) | (palette << 12);
        }
    }
}

// Tilemap_CopyRectSkipZero @ 0x080AB250
/* Copies a w*h block (row stride 32) to (x, y) of dst, offsetting non-zero tiles by tileAdd
   and setting the palette. */
void Tilemap_CopyRectSkipZero(const u16 (*src)[32], u16 (*dst)[32], u16 tileAdd, u16 palette, u16 x, u16 y, u16 w,
                  u16 h)
{
    u16 i, j;

    for (j = 0; j < h; j++)
    {
        for (i = 0; i < w; i++)
        {
            u16 tile = src[j][i];
            u16 *p = &dst[j + y][i + x];

            if (tile != 0)
                tile += tileAdd;
            tile += palette << 12;
            *p = tile;
        }
    }
}

// Tilemap_CopyRect @ 0x080AB2F4
/* Tilemap_CopyRectSkipZero that offsets every tile, including tile 0. */
void Tilemap_CopyRect(const u16 (*src)[32], u16 (*dst)[32], u16 tileAdd, u16 palette, u16 x, u16 y, u16 w,
                  u16 h)
{
    u16 i, j;

    for (j = 0; j < h; j++)
    {
        for (i = 0; i < w; i++)
        {
            u16 tile = src[j][i];
            u16 *p = &dst[j + y][i + x];

            tile += tileAdd;
            *p = tile + (palette << 12);
        }
    }
}

// Tilemap_CopyRectStride @ 0x080AB390
/* Tilemap_CopyRect with a source row stride of srcWidth tiles. */
void Tilemap_CopyRectStride(const u16 *src, u16 (*dst)[32], u16 tileAdd, u16 palette, u16 x, u16 y, u16 w,
                  u16 h, u16 srcWidth)
{
    u16 i, j;

    for (j = 0; j < h; j++)
    {
        for (i = 0; i < w; i++)
        {
            u16 tile = *(src + srcWidth * j + i);
            u16 *p = &dst[j + y][i + x];

            tile += tileAdd;
            *p = tile + (palette << 12);
        }
    }
}

// Tilemap_FillRect @ 0x080AB438
/* Fills a w*h rectangle at (x, y) with value. */
void Tilemap_FillRect(u16 value, u16 (*map)[32], u16 x, u16 y, u16 w, u16 h)
{
    u16 i, j;

    for (j = 0; j < h; j++)
    {
        for (i = 0; i < w; i++)
        {
            u16 *p = &map[j + y][i + x];

            *p = value;
        }
    }
}

// WindowMap_UploadToBg0 @ 0x080AB49C
/* Uploads the tilemap buffer gWindowMap to one of four 4 KB VRAM blocks. */
void WindowMap_UploadToBg0(void)
{
    DmaCopy32(3, gWindowMap, (void *)0x06000000, 0x1000);
}

// WindowMap_UploadToBg1 @ 0x080AB4BC
void WindowMap_UploadToBg1(void)
{
    DmaCopy32(3, gWindowMap, (void *)0x06001000, 0x1000);
}

// WindowMap_UploadToBg2 @ 0x080AB4E0
void WindowMap_UploadToBg2(void)
{
    DmaCopy32(3, gWindowMap, (void *)0x06002000, 0x1000);
}

// WindowMap_UploadToBg3 @ 0x080AB504
void WindowMap_UploadToBg3(void)
{
    DmaCopy32(3, gWindowMap, (void *)0x06003000, 0x1000);
}
