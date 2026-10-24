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
#ifdef NONMATCHING
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
            *p = tile + (palette << 12);
        }
    }
}
#else
NAKED
void Tilemap_CopyRectSkipZero(const u16 (*src)[32], u16 (*dst)[32], u16 tileAdd, u16 palette, u16 x, u16 y, u16 w,
                  u16 h)
{
    asm_unified(
        ".L080AB250:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x14\n"
        "    str r0, [sp]\n"
        "    str r1, [sp, #4]\n"
        "    ldr r0, [sp, #0x34]\n"
        "    ldr r1, [sp, #0x38]\n"
        "    ldr r4, [sp, #0x3c]\n"
        "    ldr r5, [sp, #0x40]\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    mov sl, r2\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    str r3, [sp, #8]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sb, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #0xc]\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r7, r4, #0x10\n"
        "    lsls r5, r5, #0x10\n"
        "    lsrs r5, r5, #0x10\n"
        "    mov r8, r5\n"
        "    movs r1, #0\n"
        "    cmp r1, r8\n"
        "    bhs .L080AB2E4\n"
        ".L080AB290:\n"
        "    movs r2, #0\n"
        "    adds r0, r1, #1\n"
        "    mov ip, r0\n"
        "    cmp r2, r7\n"
        "    bhs .L080AB2DA\n"
        "    lsls r0, r1, #6\n"
        "    ldr r3, [sp]\n"
        "    adds r0, r0, r3\n"
        "    str r0, [sp, #0x10]\n"
        "    ldr r6, [sp, #0xc]\n"
        "    adds r0, r1, r6\n"
        "    lsls r0, r0, #6\n"
        "    ldr r1, [sp, #4]\n"
        "    adds r5, r1, r0\n"
        "    ldr r3, [sp, #8]\n"
        "    lsls r4, r3, #0xc\n"
        ".L080AB2B0:\n"
        "    lsls r0, r2, #1\n"
        "    ldr r6, [sp, #0x10]\n"
        "    adds r0, r0, r6\n"
        "    ldrh r1, [r0]\n"
        "    mov r3, sb\n"
        "    adds r0, r2, r3\n"
        "    lsls r0, r0, #1\n"
        "    adds r3, r5, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080AB2CC\n"
        "    mov r6, sl\n"
        "    adds r0, r1, r6\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        ".L080AB2CC:\n"
        "    adds r0, r1, r4\n"
        "    strh r0, [r3]\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, r7\n"
        "    blo .L080AB2B0\n"
        ".L080AB2DA:\n"
        "    mov r1, ip\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    cmp r1, r8\n"
        "    blo .L080AB290\n"
        ".L080AB2E4:\n"
        "    add sp, #0x14\n"
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
