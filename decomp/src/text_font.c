#include "global.h"
#include "text.h"

/* 2bpp -> 4bpp: each source byte holds 4 pixels, leftmost in the top bits. */
#define EXPAND_2BPP_BYTE(dst, w)                        \
{                                                       \
    *dst++ = (((w) & 0xC0) >> 6) | ((w) & 0x30);        \
    *dst++ = (((w) & 0x0C) >> 2) | (((w) & 0x03) << 4); \
}

/* Converts one main-font glyph to 4bpp in gGlyphBitmap and returns it. */
// Font_GetGlyphBitmap @ 0x080ABF24
#ifdef NONMATCHING
u8 *Font_GetGlyphBitmap(u16 code)
{
    u32 bank = code >> 8;
    const u8 *glyph = gFontBankTable[bank].glyphs;
    const u32 *src;
    u8 *dst;
    u32 i;
    u32 w;
    u8 *buf;

    glyph += ((code & 0xFF) >> 4) * 0x400 + (code & 0xF) * 0x20;
    src = (const u32 *)glyph;
    dst = gGlyphBitmap;

    for (i = 0, buf = dst; i < 8; i++)
    {
        w = *src++;

        EXPAND_2BPP_BYTE(dst, w);
        w >>= 8;
        EXPAND_2BPP_BYTE(dst, w);
        w >>= 8;
        EXPAND_2BPP_BYTE(dst, w);
        w >>= 8;
        EXPAND_2BPP_BYTE(dst, w);
    }

    src = (const u32 *)(glyph + 0x200);
    dst = buf + 0x400;
    for (i = 0; i < 8; i++)
    {
        w = *src++;

        EXPAND_2BPP_BYTE(dst, w);
        w >>= 8;
        EXPAND_2BPP_BYTE(dst, w);
        w >>= 8;
        EXPAND_2BPP_BYTE(dst, w);
        w >>= 8;
        EXPAND_2BPP_BYTE(dst, w);
    }

    return dst - 0x440;
}
#else
NAKED
u8 *Font_GetGlyphBitmap(u16 code)
{
    asm_unified(
        ".L080ABF24:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    lsrs r0, r0, #0x18\n"
        "    ldr r1, .L080AC0D4\n"
        "    lsls r0, r0, #3\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov sb, r0\n"
        "    movs r1, #0xff\n"
        "    ands r1, r2\n"
        "    lsrs r1, r1, #4\n"
        "    lsls r1, r1, #0xa\n"
        "    movs r0, #0xf\n"
        "    ands r0, r2\n"
        "    lsls r0, r0, #5\n"
        "    adds r1, r1, r0\n"
        "    add r1, sb\n"
        "    mov r8, r1\n"
        "    mov sb, r8\n"
        "    ldr r3, .L080AC0D8\n"
        "    movs r0, #0\n"
        "    mov ip, r0\n"
        "    mov sl, r3\n"
        "    movs r7, #0xc0\n"
        "    movs r6, #0x30\n"
        "    movs r5, #0xc\n"
        "    movs r4, #3\n"
        ".L080ABF64:\n"
        "    mov r1, r8\n"
        "    adds r1, #4\n"
        "    mov r8, r1\n"
        "    subs r1, #4\n"
        "    ldm r1!, {r2}\n"
        "    adds r1, r2, #0\n"
        "    ands r1, r7\n"
        "    lsrs r1, r1, #6\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    strb r1, [r3]\n"
        "    adds r3, #1\n"
        "    adds r1, r2, #0\n"
        "    ands r1, r5\n"
        "    lsrs r1, r1, #2\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r4\n"
        "    lsls r0, r0, #4\n"
        "    orrs r1, r0\n"
        "    strb r1, [r3]\n"
        "    adds r3, #1\n"
        "    lsrs r2, r2, #8\n"
        "    adds r1, r2, #0\n"
        "    ands r1, r7\n"
        "    lsrs r1, r1, #6\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    strb r1, [r3]\n"
        "    adds r3, #1\n"
        "    adds r1, r2, #0\n"
        "    ands r1, r5\n"
        "    lsrs r1, r1, #2\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r4\n"
        "    lsls r0, r0, #4\n"
        "    orrs r1, r0\n"
        "    strb r1, [r3]\n"
        "    adds r3, #1\n"
        "    lsrs r2, r2, #8\n"
        "    adds r1, r2, #0\n"
        "    ands r1, r7\n"
        "    lsrs r1, r1, #6\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    strb r1, [r3]\n"
        "    adds r3, #1\n"
        "    adds r1, r2, #0\n"
        "    ands r1, r5\n"
        "    lsrs r1, r1, #2\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r4\n"
        "    lsls r0, r0, #4\n"
        "    orrs r1, r0\n"
        "    strb r1, [r3]\n"
        "    adds r3, #1\n"
        "    lsrs r2, r2, #8\n"
        "    adds r1, r2, #0\n"
        "    ands r1, r7\n"
        "    lsrs r1, r1, #6\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    strb r1, [r3]\n"
        "    adds r3, #1\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r5\n"
        "    lsrs r0, r0, #2\n"
        "    ands r2, r4\n"
        "    lsls r1, r2, #4\n"
        "    orrs r0, r1\n"
        "    strb r0, [r3]\n"
        "    adds r3, #1\n"
        "    movs r0, #1\n"
        "    add ip, r0\n"
        "    mov r1, ip\n"
        "    cmp r1, #7\n"
        "    bls .L080ABF64\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #2\n"
        "    add r0, sb\n"
        "    mov r8, r0\n"
        "    movs r3, #0x80\n"
        "    lsls r3, r3, #3\n"
        "    add r3, sl\n"
        "    movs r1, #0\n"
        "    mov ip, r1\n"
        "    movs r7, #0xc0\n"
        "    movs r6, #0x30\n"
        "    movs r5, #0xc\n"
        "    movs r4, #3\n"
        ".L080AC01E:\n"
        "    mov r0, r8\n"
        "    adds r0, #4\n"
        "    mov r8, r0\n"
        "    subs r0, #4\n"
        "    ldm r0!, {r2}\n"
        "    adds r1, r2, #0\n"
        "    ands r1, r7\n"
        "    lsrs r1, r1, #6\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    strb r1, [r3]\n"
        "    adds r3, #1\n"
        "    adds r1, r2, #0\n"
        "    ands r1, r5\n"
        "    lsrs r1, r1, #2\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r4\n"
        "    lsls r0, r0, #4\n"
        "    orrs r1, r0\n"
        "    strb r1, [r3]\n"
        "    adds r3, #1\n"
        "    lsrs r2, r2, #8\n"
        "    adds r1, r2, #0\n"
        "    ands r1, r7\n"
        "    lsrs r1, r1, #6\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    strb r1, [r3]\n"
        "    adds r3, #1\n"
        "    adds r1, r2, #0\n"
        "    ands r1, r5\n"
        "    lsrs r1, r1, #2\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r4\n"
        "    lsls r0, r0, #4\n"
        "    orrs r1, r0\n"
        "    strb r1, [r3]\n"
        "    adds r3, #1\n"
        "    lsrs r2, r2, #8\n"
        "    adds r1, r2, #0\n"
        "    ands r1, r7\n"
        "    lsrs r1, r1, #6\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    strb r1, [r3]\n"
        "    adds r3, #1\n"
        "    adds r1, r2, #0\n"
        "    ands r1, r5\n"
        "    lsrs r1, r1, #2\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r4\n"
        "    lsls r0, r0, #4\n"
        "    orrs r1, r0\n"
        "    strb r1, [r3]\n"
        "    adds r3, #1\n"
        "    lsrs r2, r2, #8\n"
        "    adds r1, r2, #0\n"
        "    ands r1, r7\n"
        "    lsrs r1, r1, #6\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    strb r1, [r3]\n"
        "    adds r3, #1\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r5\n"
        "    lsrs r0, r0, #2\n"
        "    ands r2, r4\n"
        "    lsls r1, r2, #4\n"
        "    orrs r0, r1\n"
        "    strb r0, [r3]\n"
        "    adds r3, #1\n"
        "    movs r1, #1\n"
        "    add ip, r1\n"
        "    mov r0, ip\n"
        "    cmp r0, #7\n"
        "    bls .L080AC01E\n"
        "    ldr r0, .L080AC0DC\n"
        "    ldr r1, .L080AC0E0\n"
        "    adds r0, r0, r1\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L080AC0D4: .4byte gFontBankTable\n"
        ".L080AC0D8: .4byte 0x020391E0 @ EWRAM+0x391E0\n"
        ".L080AC0DC: .4byte 0x020395E0 @ EWRAM+0x395E0\n"
        ".L080AC0E0: .4byte 0xFFFFFC00\n"
    );
}
#endif

// Font_SetGlyphSpriteCacheCapacity @ 0x080AC0E4
void Font_SetGlyphSpriteCacheCapacity(u16 capacity)
{
    gGlyphSpriteCache.capacity = capacity;
}

// Font_ResetGlyphSpriteCache @ 0x080AC0F0
void Font_ResetGlyphSpriteCache(u16 baseTile)
{
    vu16 zero = 0;

    TEXT_DMA3_SET(&zero, &gGlyphSpriteCache, 0x81000000 | (sizeof(gGlyphSpriteCache) / 2));
    gGlyphSpriteCache.baseTile = baseTile;
    Font_SetGlyphSpriteCacheCapacity(64);
}

/* Adds a glyph to the OBJ cache (no lookup: callers use Font_FindGlyphSprite first).  Returns the
   slot, or -1 when the cache is full. */
// Font_CacheGlyphSprite @ 0x080AC124
#ifdef NONMATCHING
s16 Font_CacheGlyphSprite(u16 code)
{
    struct GlyphSpriteCache *cache = &gGlyphSpriteCache;
    u8 *bitmap;
    u32 slot;

    if (cache->count == cache->capacity)
        return -1;

    bitmap = Font_GetGlyphBitmap(code);
    slot = cache->count;
    Font_CopyGlyphCell(bitmap, gGlyphSpriteStaging + (slot >> 4) * 0x800 + (slot & 0xF) * 0x40);
    cache->codes[cache->count] = code;
    cache->count++;
    if (cache->uploadPending == 0)
    {
        VBlankTask_AddCounted(Font_UploadGlyphSpriteTiles, 1);
        cache->uploadPending = 1;
    }
    return cache->count - 1;
}
#else
NAKED
s16 Font_CacheGlyphSprite(u16 code)
{
    asm_unified(
        ".L080AC124:\n"
        "    push {r4, r5, r6, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldr r5, .L080AC13C\n"
        "    ldrh r0, [r5, #2]\n"
        "    ldrh r1, [r5, #4]\n"
        "    cmp r0, r1\n"
        "    bne .L080AC140\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    b .L080AC188\n"
        "    .byte 0x00, 0x00\n"
        ".L080AC13C: .4byte 0x020360DC @ EWRAM+0x360DC\n"
        ".L080AC140:\n"
        "    adds r0, r6, #0\n"
        "    bl Font_GetGlyphBitmap\n"
        "    ldr r1, .L080AC190\n"
        "    ldrh r4, [r5, #2]\n"
        "    lsrs r3, r4, #4\n"
        "    lsls r3, r3, #0xb\n"
        "    movs r2, #0xf\n"
        "    ands r2, r4\n"
        "    lsls r2, r2, #6\n"
        "    adds r3, r3, r2\n"
        "    adds r1, r3, r1\n"
        "    bl Font_CopyGlyphCell\n"
        "    ldrh r0, [r5, #2]\n"
        "    lsls r0, r0, #1\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #8\n"
        "    adds r0, r0, r1\n"
        "    strh r6, [r0]\n"
        "    ldrh r0, [r5, #2]\n"
        "    adds r0, #1\n"
        "    strh r0, [r5, #2]\n"
        "    ldrh r0, [r5, #6]\n"
        "    cmp r0, #0\n"
        "    bne .L080AC180\n"
        "    ldr r0, .L080AC194\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    movs r0, #1\n"
        "    strh r0, [r5, #6]\n"
        ".L080AC180:\n"
        "    ldrh r0, [r5, #2]\n"
        "    subs r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        ".L080AC188:\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L080AC190: .4byte 0x020361DC @ EWRAM+0x361DC\n"
        ".L080AC194: .4byte Font_UploadGlyphSpriteTiles\n"
    );
}
#endif

// Font_UploadGlyphSpriteTiles @ 0x080AC198
void Font_UploadGlyphSpriteTiles(void)
{
    u16 offset = gGlyphSpriteCache.baseTile * 32;
    u16 size = ((gGlyphSpriteCache.count >> 4) + 1) * 0x800;

    TEXT_DMA3_SET(gGlyphSpriteStaging, 0x06010000 + offset, 0x84000000 | (size / 4));
    gGlyphSpriteCache.uploadPending = 0;
}

// Font_FindGlyphSprite @ 0x080AC1DC
s16 Font_FindGlyphSprite(u16 code)
{
    s32 i;

    if (gGlyphSpriteCache.count != 0)
    {
        for (i = 0; i < gGlyphSpriteCache.count; i++)
        {
            if (gGlyphSpriteCache.codes[i] == code)
                return i;
        }
    }
    return -1;
}

/* Draws one glyph as a 16x16 OBJ through the glyph cache.  Codes 0 and 0x3F (space) draw
   nothing.  When the cache is full Font_CacheGlyphSprite returns -1 and that is used as a
   slot anyway (tile baseTile - 34): the 65th distinct glyph shows wrong tiles. */
// FontSprite_DrawGlyph @ 0x080AC218
void FontSprite_DrawGlyph(u16 code, u16 a1, u16 a2, u16 x, u16 y)
{
    s16 slot;
    s32 tile;

    if (code == 0 || code == 0x3F)
        return;

    if ((slot = Font_FindGlyphSprite(code)) == -1)
        slot = Font_CacheGlyphSprite(code);
    tile = gGlyphSpriteCache.baseTile + (slot >> 4) * 64 + (slot & 0xF) * 2;
    Sprite_DrawSingle(gGlyphSpriteTemplate, a1, 0, a2, tile, x, y);
}

// FontSprite_DrawGlyphTinted @ 0x080AC2A0
void FontSprite_DrawGlyphTinted(u16 code, u16 a1, u16 a2, u16 x, u16 y, u16 palette)
{
    s16 slot;
    s32 tile;

    if (code == 0 || code == 0x3F)
        return;

    if ((slot = Font_FindGlyphSprite(code)) == -1)
        slot = Font_CacheGlyphSprite(code);
    tile = gGlyphSpriteCache.baseTile + (slot >> 4) * 64 + (slot & 0xF) * 2;
    Sprite_DrawSingle(gGlyphSpriteTemplate, a1, palette, a2, tile, x, y);
}

/* Every glyph advances x by the same `advance`; 0x300 starts a new line `advance` pixels
   lower. */
// Text_DrawSpriteString @ 0x080AC334
void Text_DrawSpriteString(const u16 *str, u16 a1, u16 a2, u16 x, u16 y, u16 advance)
{
    u16 x0 = x;

    while (*str != TEXT_CODE_END && *str != TEXT_CODE_END2)
    {
        if (*str == TEXT_CODE_NEWLINE)
        {
            x = x0;
            y += advance;
        }
        else
        {
            FontSprite_DrawGlyph(*str, a1, a2, x, y);
            x += advance;
        }
        str++;
    }
}

// Text_DrawSpriteStringTinted @ 0x080AC3AC
void Text_DrawSpriteStringTinted(const u16 *str, u16 a1, u16 a2, u16 x, u16 y, u16 advance, u16 palette)
{
    u16 x0 = x;

    while (*str != TEXT_CODE_END && *str != TEXT_CODE_END2)
    {
        if (*str == TEXT_CODE_NEWLINE)
        {
            x = x0;
            y += advance;
        }
        else
        {
            FontSprite_DrawGlyphTinted(*str, a1, a2, x, y, palette);
            x += advance;
        }
        str++;
    }
}

/* Copies a 2x2-tile glyph between two 32-tile-wide 4bpp canvases. */
// Font_CopyGlyphCell @ 0x080AC438
void Font_CopyGlyphCell(u8 *src, u8 *dst)
{
    u32 *s = (u32 *)src;
    u32 *d = (u32 *)dst;
    s32 i;

    for (i = 15; i >= 0; i--)
        *d++ = *s++;

    s = (u32 *)(src + 0x400);
    d = (u32 *)(dst + 0x400);
    for (i = 15; i >= 0; i--)
        *d++ = *s++;
}

/* Random number: a scrambled multiply of the seed, plus frame counter x VCOUNT rotated by 3,
   12, 21 and 30 bits. */
// Random_Next @ 0x080AC468
#ifdef NONMATCHING
u32 Random_Next(void)
{
    u32 seed = gRandomSeed;
    u32 t = (seed >> 16) * 0x4E6D;
    u32 lo = seed & 0xFFFF;
    u32 a = lo * t;
    u32 r = (a + t) >> 16;
    u32 n;

    r += ((((a & 0xFFFF0000) - 0xDD3C) * lo >> 16) * lo) << 16;
    n = gFrameCounter * REG_VCOUNT;
    r += (n << 29) + (n >> 3);
    r += (n << 20) + (n >> 12);
    r += (n << 11) + (n >> 21);
    r += (n << 2) + (n >> 30);
    gRandomSeed = r;
    return r;
}
#else
NAKED
u32 Random_Next(void)
{
    asm_unified(
        ".L080AC468:\n"
        "    push {r4, r5, lr}\n"
        "    ldr r2, .L080AC4C8\n"
        "    ldr r0, [r2]\n"
        "    ldr r5, .L080AC4CC\n"
        "    ldr r1, .L080AC4D0\n"
        "    lsrs r4, r0, #0x10\n"
        "    muls r5, r4, r5\n"
        "    ldr r4, .L080AC4D4\n"
        "    ands r4, r0\n"
        "    adds r3, r4, #0\n"
        "    muls r3, r5, r3\n"
        "    adds r0, r3, r5\n"
        "    lsrs r5, r0, #0x10\n"
        "    ands r1, r3\n"
        "    ldr r0, .L080AC4D8\n"
        "    adds r3, r1, r0\n"
        "    muls r3, r4, r3\n"
        "    lsrs r0, r3, #0x10\n"
        "    muls r4, r0, r4\n"
        "    lsls r0, r4, #0x10\n"
        "    adds r4, r5, r0\n"
        "    ldr r0, .L080AC4DC\n"
        "    ldr r3, [r0]\n"
        "    ldr r0, .L080AC4E0\n"
        "    ldrh r0, [r0]\n"
        "    muls r3, r0, r3\n"
        "    lsls r0, r3, #0x1d\n"
        "    lsrs r1, r3, #3\n"
        "    adds r0, r0, r1\n"
        "    adds r4, r4, r0\n"
        "    lsls r0, r3, #0x14\n"
        "    lsrs r1, r3, #0xc\n"
        "    adds r0, r0, r1\n"
        "    adds r4, r4, r0\n"
        "    lsls r0, r3, #0xb\n"
        "    lsrs r1, r3, #0x15\n"
        "    adds r0, r0, r1\n"
        "    adds r4, r4, r0\n"
        "    lsls r0, r3, #2\n"
        "    lsrs r1, r3, #0x1e\n"
        "    adds r0, r0, r1\n"
        "    adds r4, r4, r0\n"
        "    str r4, [r2]\n"
        "    adds r0, r4, #0\n"
        "    pop {r4, r5}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L080AC4C8: .4byte 0x030020E0 @ IWRAM+0x20E0\n"
        ".L080AC4CC: .4byte 0x00004E6D\n"
        ".L080AC4D0: .4byte 0xFFFF0000\n"
        ".L080AC4D4: .4byte 0x0000FFFF\n"
        ".L080AC4D8: .4byte 0xFFFF22C4\n"
        ".L080AC4DC: .4byte 0x030031BC @ IWRAM+0x31BC\n"
        ".L080AC4E0: .4byte 0x04000006 @ REG_VCOUNT\n"
    );
}
#endif

/* ORs a w x h block of pixels from one 32-tile-wide 4bpp canvas into another.  The source
   is read a byte (two pixels) at a time, so srcX and w are assumed even; dstX may be odd,
   which is what allows placing glyphs at any pixel column. */
// Canvas_BlitOr @ 0x080AC4E4
#ifdef NONMATCHING
void Canvas_BlitOr(u8 *src, u8 *dst, u16 srcX, u16 srcY, u16 dstX, u16 dstY, u16 w, u16 h)
{
    u16 sx, dx;
    u16 row, col;

    for (row = 0; row < h; row++)
    {
        sx = srcX;
        dx = dstX;
        for (col = 0; col < w; col += 2)
        {
            u8 *d = CANVAS_PIXEL_BYTE(dst, dx, dstY);
            u8 v = *d;
            u8 s = *CANVAS_PIXEL_BYTE(src, sx, srcY);

            if (!(dx & 1))
                v |= s & 0xF;
            else
                v |= (s & 0xF) << 4;
            *d = v;
            sx++;
            dx++;

            d = CANVAS_PIXEL_BYTE(dst, dx, dstY);
            v = *d;
            if (!(dx & 1))
                v |= s >> 4;
            else
                v |= s & 0xF0;
            *d = v;
            sx++;
            dx++;
        }
        srcY++;
        dstY++;
    }
}
#else
NAKED
void Canvas_BlitOr(u8 *src, u8 *dst, u16 srcX, u16 srcY, u16 dstX, u16 dstY, u16 w, u16 h)
{
    asm_unified(
        ".L080AC4E4:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x2c\n"
        "    str r0, [sp]\n"
        "    str r1, [sp, #4]\n"
        "    ldr r5, [sp, #0x4c]\n"
        "    ldr r0, [sp, #0x50]\n"
        "    ldr r1, [sp, #0x54]\n"
        "    ldr r4, [sp, #0x58]\n"
        "    lsls r2, r2, #0x10\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    mov r8, r3\n"
        "    lsls r5, r5, #0x10\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    str r4, [sp, #0xc]\n"
        "    lsrs r2, r2, #0x10\n"
        "    str r2, [sp, #0x10]\n"
        "    lsrs r5, r5, #0x10\n"
        "    str r5, [sp, #0x14]\n"
        "    movs r0, #0\n"
        "    cmp r0, r4\n"
        "    bhs .L080AC61A\n"
        ".L080AC524:\n"
        "    ldr r7, [sp, #0x10]\n"
        "    ldr r6, [sp, #0x14]\n"
        "    movs r1, #0\n"
        "    str r1, [sp, #0x18]\n"
        "    mov r2, r8\n"
        "    adds r2, #1\n"
        "    str r2, [sp, #0x1c]\n"
        "    adds r1, r3, #1\n"
        "    str r1, [sp, #0x20]\n"
        "    adds r0, #1\n"
        "    str r0, [sp, #0x24]\n"
        "    ldr r2, [sp, #0x18]\n"
        "    ldr r0, [sp, #8]\n"
        "    cmp r2, r0\n"
        "    bhs .L080AC600\n"
        "    lsrs r0, r3, #3\n"
        "    lsls r0, r0, #0xa\n"
        "    ldr r1, [sp, #4]\n"
        "    adds r1, r1, r0\n"
        "    mov sl, r1\n"
        "    movs r2, #7\n"
        "    mov ip, r2\n"
        "    ands r3, r2\n"
        "    lsls r3, r3, #2\n"
        "    mov sb, r3\n"
        ".L080AC556:\n"
        "    lsrs r1, r6, #3\n"
        "    lsls r1, r1, #5\n"
        "    add r1, sl\n"
        "    add r1, sb\n"
        "    adds r0, r6, #0\n"
        "    mov r3, ip\n"
        "    ands r0, r3\n"
        "    lsrs r0, r0, #1\n"
        "    adds r5, r1, r0\n"
        "    ldrb r4, [r5]\n"
        "    mov r1, r8\n"
        "    lsrs r0, r1, #3\n"
        "    lsls r0, r0, #0xa\n"
        "    lsrs r3, r7, #3\n"
        "    lsls r3, r3, #5\n"
        "    str r3, [sp, #0x28]\n"
        "    mov r2, r8\n"
        "    mov r3, ip\n"
        "    ands r2, r3\n"
        "    lsls r2, r2, #2\n"
        "    adds r1, r7, #0\n"
        "    ands r1, r3\n"
        "    lsrs r1, r1, #1\n"
        "    ldr r3, [sp]\n"
        "    adds r0, r3, r0\n"
        "    ldr r3, [sp, #0x28]\n"
        "    adds r0, r0, r3\n"
        "    adds r0, r0, r2\n"
        "    adds r0, r0, r1\n"
        "    ldrb r2, [r0]\n"
        "    movs r0, #1\n"
        "    ands r0, r6\n"
        "    cmp r0, #0\n"
        "    bne .L080AC5A0\n"
        "    movs r0, #0xf\n"
        "    ands r0, r2\n"
        "    b .L080AC5A6\n"
        ".L080AC5A0:\n"
        "    movs r0, #0xf\n"
        "    ands r0, r2\n"
        "    lsls r0, r0, #4\n"
        ".L080AC5A6:\n"
        "    orrs r4, r0\n"
        "    strb r4, [r5]\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r1, r6, #1\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r6, r1, #0x10\n"
        "    lsrs r1, r1, #0x13\n"
        "    lsls r1, r1, #5\n"
        "    add r1, sl\n"
        "    add r1, sb\n"
        "    adds r0, r6, #0\n"
        "    mov r3, ip\n"
        "    ands r0, r3\n"
        "    lsrs r0, r0, #1\n"
        "    adds r5, r1, r0\n"
        "    ldrb r4, [r5]\n"
        "    movs r0, #1\n"
        "    ands r0, r6\n"
        "    cmp r0, #0\n"
        "    bne .L080AC5D8\n"
        "    lsrs r0, r2, #4\n"
        "    orrs r4, r0\n"
        "    b .L080AC5DE\n"
        ".L080AC5D8:\n"
        "    movs r0, #0xf0\n"
        "    ands r2, r0\n"
        "    orrs r4, r2\n"
        ".L080AC5DE:\n"
        "    strb r4, [r5]\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldr r1, [sp, #0x18]\n"
        "    lsls r0, r1, #0x10\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #0xa\n"
        "    adds r0, r0, r2\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0x18]\n"
        "    ldr r3, [sp, #8]\n"
        "    cmp r0, r3\n"
        "    blo .L080AC556\n"
        ".L080AC600:\n"
        "    ldr r1, [sp, #0x1c]\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        "    ldr r2, [sp, #0x20]\n"
        "    lsls r0, r2, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    ldr r1, [sp, #0x24]\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    ldr r2, [sp, #0xc]\n"
        "    cmp r0, r2\n"
        "    blo .L080AC524\n"
        ".L080AC61A:\n"
        "    add sp, #0x2c\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

/* Canvas_BlitOr with a palette shift: after ORing, a destination pixel that is nonzero gets
   `tint` added.  The test is on the merged pixel, so a pixel already drawn in the destination
   is shifted again even where the source pixel is transparent, and pixel + tint can carry
   into the neighbouring pixel. */
// Canvas_BlitOrTinted @ 0x080AC62C
#ifdef NONMATCHING
void Canvas_BlitOrTinted(u8 *src, u8 *dst, u16 srcX, u16 srcY, u16 dstX, u16 dstY, u16 w, u16 h, u8 tint)
{
    u16 row, col;
    u16 sx, dx;

    for (row = 0; row < h; row++)
    {
        sx = srcX;
        dx = dstX;
        for (col = 0; col < w; col += 2)
        {
            u8 *d = CANVAS_PIXEL_BYTE(dst, dx, dstY);
            u8 v = *d;
            u8 s = *CANVAS_PIXEL_BYTE(src, sx, srcY);

            if (!(dx & 1))
            {
                v |= s & 0xF;
                if (v & 0xF)
                    v += tint;
            }
            else
            {
                v |= (s & 0xF) << 4;
                if (v & 0xF0)
                    v += tint << 4;
            }
            *d = v;
            sx++;
            dx++;

            d = CANVAS_PIXEL_BYTE(dst, dx, dstY);
            v = *d;
            if (!(dx & 1))
            {
                v |= s >> 4;
                if (v & 0xF)
                    v += tint;
            }
            else
            {
                v |= s & 0xF0;
                if (v & 0xF0)
                    v += tint << 4;
            }
            *d = v;
            sx++;
            dx++;
        }
        srcY++;
        dstY++;
    }
}
#else
NAKED
void Canvas_BlitOrTinted(u8 *src, u8 *dst, u16 srcX, u16 srcY, u16 dstX, u16 dstY, u16 w, u16 h, u8 tint)
{
    asm_unified(
        ".L080AC62C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x30\n"
        "    str r0, [sp]\n"
        "    str r1, [sp, #4]\n"
        "    ldr r6, [sp, #0x50]\n"
        "    ldr r0, [sp, #0x54]\n"
        "    ldr r1, [sp, #0x58]\n"
        "    ldr r4, [sp, #0x5c]\n"
        "    ldr r5, [sp, #0x60]\n"
        "    lsls r2, r2, #0x10\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    mov sb, r3\n"
        "    lsls r6, r6, #0x10\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    str r4, [sp, #0xc]\n"
        "    lsls r5, r5, #0x18\n"
        "    lsrs r5, r5, #0x18\n"
        "    mov ip, r5\n"
        "    lsrs r2, r2, #0x10\n"
        "    str r2, [sp, #0x10]\n"
        "    lsrs r6, r6, #0x10\n"
        "    str r6, [sp, #0x14]\n"
        "    movs r0, #0\n"
        "    cmp r0, r4\n"
        "    blo .L080AC676\n"
        "    b .L080AC7BC\n"
        ".L080AC676:\n"
        "    ldr r7, [sp, #0x10]\n"
        "    ldr r6, [sp, #0x14]\n"
        "    movs r1, #0\n"
        "    str r1, [sp, #0x18]\n"
        "    mov r2, sb\n"
        "    adds r2, #1\n"
        "    str r2, [sp, #0x20]\n"
        "    adds r1, r3, #1\n"
        "    str r1, [sp, #0x24]\n"
        "    adds r0, #1\n"
        "    str r0, [sp, #0x28]\n"
        "    ldr r2, [sp, #0x18]\n"
        "    ldr r0, [sp, #8]\n"
        "    cmp r2, r0\n"
        "    blo .L080AC696\n"
        "    b .L080AC7A0\n"
        ".L080AC696:\n"
        "    lsrs r0, r3, #3\n"
        "    lsls r0, r0, #0xa\n"
        "    ldr r1, [sp, #4]\n"
        "    adds r0, r1, r0\n"
        "    str r0, [sp, #0x1c]\n"
        "    movs r2, #7\n"
        "    mov r8, r2\n"
        "    ands r3, r2\n"
        "    lsls r3, r3, #2\n"
        "    mov sl, r3\n"
        ".L080AC6AA:\n"
        "    lsrs r1, r6, #3\n"
        "    lsls r1, r1, #5\n"
        "    ldr r3, [sp, #0x1c]\n"
        "    adds r1, r3, r1\n"
        "    add r1, sl\n"
        "    adds r0, r6, #0\n"
        "    mov r2, r8\n"
        "    ands r0, r2\n"
        "    lsrs r0, r0, #1\n"
        "    adds r5, r1, r0\n"
        "    ldrb r4, [r5]\n"
        "    mov r3, sb\n"
        "    lsrs r0, r3, #3\n"
        "    lsls r0, r0, #0xa\n"
        "    lsrs r3, r7, #3\n"
        "    lsls r3, r3, #5\n"
        "    str r3, [sp, #0x2c]\n"
        "    mov r2, sb\n"
        "    mov r1, r8\n"
        "    ands r2, r1\n"
        "    lsls r2, r2, #2\n"
        "    adds r1, r7, #0\n"
        "    mov r3, r8\n"
        "    ands r1, r3\n"
        "    lsrs r1, r1, #1\n"
        "    ldr r3, [sp]\n"
        "    adds r0, r3, r0\n"
        "    ldr r3, [sp, #0x2c]\n"
        "    adds r0, r0, r3\n"
        "    adds r0, r0, r2\n"
        "    adds r0, r0, r1\n"
        "    ldrb r2, [r0]\n"
        "    movs r0, #1\n"
        "    ands r0, r6\n"
        "    cmp r0, #0\n"
        "    bne .L080AC708\n"
        "    adds r0, r2, #0\n"
        "    movs r1, #0xf\n"
        "    ands r0, r1\n"
        "    orrs r4, r0\n"
        "    adds r0, r4, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080AC726\n"
        "    mov r3, ip\n"
        "    adds r0, r4, r3\n"
        "    b .L080AC722\n"
        ".L080AC708:\n"
        "    adds r0, r2, #0\n"
        "    movs r1, #0xf\n"
        "    ands r0, r1\n"
        "    lsls r0, r0, #4\n"
        "    orrs r4, r0\n"
        "    adds r0, r4, #0\n"
        "    movs r3, #0xf0\n"
        "    ands r0, r3\n"
        "    cmp r0, #0\n"
        "    beq .L080AC726\n"
        "    mov r1, ip\n"
        "    lsls r0, r1, #4\n"
        "    adds r0, r4, r0\n"
        ".L080AC722:\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        ".L080AC726:\n"
        "    strb r4, [r5]\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r1, r6, #1\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r6, r1, #0x10\n"
        "    lsrs r1, r1, #0x13\n"
        "    lsls r1, r1, #5\n"
        "    ldr r3, [sp, #0x1c]\n"
        "    adds r1, r3, r1\n"
        "    add r1, sl\n"
        "    adds r0, r6, #0\n"
        "    mov r3, r8\n"
        "    ands r0, r3\n"
        "    lsrs r0, r0, #1\n"
        "    adds r5, r1, r0\n"
        "    ldrb r4, [r5]\n"
        "    movs r0, #1\n"
        "    ands r0, r6\n"
        "    cmp r0, #0\n"
        "    bne .L080AC766\n"
        "    lsrs r0, r2, #4\n"
        "    orrs r4, r0\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0xf\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080AC77E\n"
        "    mov r2, ip\n"
        "    adds r0, r4, r2\n"
        "    b .L080AC77A\n"
        ".L080AC766:\n"
        "    movs r3, #0xf0\n"
        "    ands r2, r3\n"
        "    orrs r4, r2\n"
        "    adds r0, r4, #0\n"
        "    ands r0, r3\n"
        "    cmp r0, #0\n"
        "    beq .L080AC77E\n"
        "    mov r1, ip\n"
        "    lsls r0, r1, #4\n"
        "    adds r0, r4, r0\n"
        ".L080AC77A:\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        ".L080AC77E:\n"
        "    strb r4, [r5]\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldr r2, [sp, #0x18]\n"
        "    lsls r0, r2, #0x10\n"
        "    movs r3, #0x80\n"
        "    lsls r3, r3, #0xa\n"
        "    adds r0, r0, r3\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0x18]\n"
        "    ldr r1, [sp, #8]\n"
        "    cmp r0, r1\n"
        "    blo .L080AC6AA\n"
        ".L080AC7A0:\n"
        "    ldr r2, [sp, #0x20]\n"
        "    lsls r0, r2, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sb, r0\n"
        "    ldr r3, [sp, #0x24]\n"
        "    lsls r0, r3, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    ldr r1, [sp, #0x28]\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    ldr r2, [sp, #0xc]\n"
        "    cmp r0, r2\n"
        "    bhs .L080AC7BC\n"
        "    b .L080AC676\n"
        ".L080AC7BC:\n"
        "    add sp, #0x30\n"
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

/* Fills a w x h pixel rectangle of a 32-tile-wide 4bpp canvas with one color (x, w even). */
// Canvas_FillRect @ 0x080AC7CC
#ifdef NONMATCHING
void Canvas_FillRect(u8 color, u8 *dst, u16 x, u16 y, u16 w, u16 h)
{
    u16 row, col;
    u16 px;

    for (row = 0; row < h; row++)
    {
        px = x;
        for (col = 0; col < w; col += 2)
        {
            u8 *d = CANVAS_PIXEL_BYTE(dst, px, y);
            u8 v = *d;

            if (!(px & 1))
                v = (v & 0xF0) | color;
            else
                v = (v & 0xF) | (color << 4);
            *d = v;
            px++;

            d = CANVAS_PIXEL_BYTE(dst, px, y);
            v = *d;
            if (!(px & 1))
                v = (v & 0xF0) | color;
            else
                v = (v & 0xF) | (color << 4);
            *d = v;
            px++;
        }
        y++;
    }
}
#else
NAKED
void Canvas_FillRect(u8 color, u8 *dst, u16 x, u16 y, u16 w, u16 h)
{
    asm_unified(
        ".L080AC7CC:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x18\n"
        "    str r1, [sp]\n"
        "    ldr r1, [sp, #0x38]\n"
        "    ldr r4, [sp, #0x3c]\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r5, r0, #0x18\n"
        "    lsls r2, r2, #0x10\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    mov sl, r1\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    str r4, [sp, #4]\n"
        "    lsrs r2, r2, #0x10\n"
        "    str r2, [sp, #8]\n"
        "    movs r0, #0\n"
        "    cmp r0, r4\n"
        "    bhs .L080AC8C0\n"
        ".L080AC7FE:\n"
        "    ldr r4, [sp, #8]\n"
        "    movs r7, #0\n"
        "    adds r1, r3, #1\n"
        "    str r1, [sp, #0xc]\n"
        "    adds r0, #1\n"
        "    str r0, [sp, #0x10]\n"
        "    cmp r7, sl\n"
        "    bhs .L080AC8AE\n"
        "    lsrs r0, r3, #3\n"
        "    lsls r0, r0, #0xa\n"
        "    ldr r2, [sp]\n"
        "    adds r0, r2, r0\n"
        "    str r0, [sp, #0x14]\n"
        "    movs r6, #7\n"
        "    mov ip, r6\n"
        "    ands r3, r6\n"
        "    lsls r3, r3, #2\n"
        "    movs r0, #1\n"
        "    mov sb, r0\n"
        "    movs r1, #0xf0\n"
        "    mov r8, r1\n"
        ".L080AC828:\n"
        "    lsrs r0, r4, #3\n"
        "    lsls r0, r0, #5\n"
        "    ldr r2, [sp, #0x14]\n"
        "    adds r0, r2, r0\n"
        "    adds r0, r0, r3\n"
        "    adds r1, r4, #0\n"
        "    mov r6, ip\n"
        "    ands r1, r6\n"
        "    lsrs r1, r1, #1\n"
        "    adds r2, r0, r1\n"
        "    ldrb r1, [r2]\n"
        "    adds r0, r4, #0\n"
        "    mov r6, sb\n"
        "    ands r0, r6\n"
        "    cmp r0, #0\n"
        "    bne .L080AC850\n"
        "    mov r0, r8\n"
        "    ands r1, r0\n"
        "    orrs r1, r5\n"
        "    b .L080AC85C\n"
        ".L080AC850:\n"
        "    movs r0, #0xf\n"
        "    ands r1, r0\n"
        "    lsls r0, r5, #4\n"
        "    orrs r1, r0\n"
        "    lsls r0, r1, #0x18\n"
        "    lsrs r1, r0, #0x18\n"
        ".L080AC85C:\n"
        "    strb r1, [r2]\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    lsrs r0, r0, #0x13\n"
        "    lsls r0, r0, #5\n"
        "    ldr r1, [sp, #0x14]\n"
        "    adds r0, r1, r0\n"
        "    adds r0, r0, r3\n"
        "    adds r1, r4, #0\n"
        "    mov r2, ip\n"
        "    ands r1, r2\n"
        "    lsrs r1, r1, #1\n"
        "    adds r2, r0, r1\n"
        "    ldrb r1, [r2]\n"
        "    adds r0, r4, #0\n"
        "    mov r6, sb\n"
        "    ands r0, r6\n"
        "    cmp r0, #0\n"
        "    bne .L080AC88C\n"
        "    mov r0, r8\n"
        "    ands r1, r0\n"
        "    orrs r1, r5\n"
        "    b .L080AC898\n"
        ".L080AC88C:\n"
        "    movs r0, #0xf\n"
        "    ands r1, r0\n"
        "    lsls r0, r5, #4\n"
        "    orrs r1, r0\n"
        "    lsls r0, r1, #0x18\n"
        "    lsrs r1, r0, #0x18\n"
        ".L080AC898:\n"
        "    strb r1, [r2]\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    lsls r0, r7, #0x10\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #0xa\n"
        "    adds r0, r0, r1\n"
        "    lsrs r7, r0, #0x10\n"
        "    cmp r7, sl\n"
        "    blo .L080AC828\n"
        ".L080AC8AE:\n"
        "    ldr r2, [sp, #0xc]\n"
        "    lsls r0, r2, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    ldr r6, [sp, #0x10]\n"
        "    lsls r0, r6, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    ldr r1, [sp, #4]\n"
        "    cmp r0, r1\n"
        "    blo .L080AC7FE\n"
        ".L080AC8C0:\n"
        "    add sp, #0x18\n"
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

/* Draws one main-font glyph into a BG canvas: only the 12x13 pixels at (2, 2) of the 16x16
   cell are copied, so the cell's 2-pixel left margin is dropped. */
// Font_DrawGlyph @ 0x080AC8D0
void Font_DrawGlyph(u16 code, u8 *canvas, u16 x, u16 y)
{
    Canvas_BlitOr(Font_GetGlyphBitmap(code), canvas, 2, 2, x, y, 12, 13);
}

/* Fixed pitch: every glyph advances x by `advance`, 0x300 moves down by `advance`. */
// Text_DrawString @ 0x080AC908
void Text_DrawString(const u16 *str, u8 *canvas, u16 x, u16 y, u16 advance)
{
    u16 x0 = x;

    while (*str != TEXT_CODE_END && *str != TEXT_CODE_END2)
    {
        if (*str == TEXT_CODE_NEWLINE)
        {
            x = x0;
            y += advance;
            str++;
        }
        else
        {
            Font_DrawGlyph(*str, canvas, x, y);
            str++;
            x += advance;
        }
    }
}

// Font_DrawGlyphTinted @ 0x080AC980
void Font_DrawGlyphTinted(u16 code, u8 *canvas, u16 x, u16 y, u8 tint)
{
    Canvas_BlitOrTinted(Font_GetGlyphBitmap(code), canvas, 2, 2, x, y, 12, 13, tint);
}

// Text_DrawStringTinted @ 0x080AC9C8
void Text_DrawStringTinted(const u16 *str, u8 *canvas, u16 x, u16 y, u8 tint, u16 advance)
{
    u16 x0 = x;

    while (*str != TEXT_CODE_END && *str != TEXT_CODE_END2)
    {
        if (*str == TEXT_CODE_NEWLINE)
        {
            x = x0;
            y += advance;
            str++;
        }
        else
        {
            Font_DrawGlyphTinted(*str, canvas, x, y, tint);
            str++;
            x += advance;
        }
    }
}

// SmallFont_DrawGlyph @ 0x080ACA40
void SmallFont_DrawGlyph(u16 index, u8 *canvas, u16 x, u16 y)
{
    Canvas_BlitOr(gSmallFontSheet + index * 32, canvas, 0, 0, x, y, 8, 8);
}

// SmallFont_DrawGlyphTinted @ 0x080ACA74
void SmallFont_DrawGlyphTinted(u16 index, u8 *canvas, u16 x, u16 y, u8 tint)
{
    Canvas_BlitOrTinted(gSmallFontSheet + index * 32, canvas, 0, 0, x, y, 8, 8, tint);
}

/* ASCII string in the 8x8 font; '-' uses small glyph 6. */
// SmallFont_DrawAsciiTinted @ 0x080ACAB0
void SmallFont_DrawAsciiTinted(const u8 *str, u8 *canvas, u16 x, u16 y, u8 tint, u16 advance)
{
    while (*str != 0)
    {
        if (*str == '-')
            SmallFont_DrawGlyphTinted(6, canvas, x, y, tint);
        else
            SmallFont_DrawGlyphTinted(gUnknown_0815EE20[*str - ' '], canvas, x, y, tint);
        str++;
        x += advance;
    }
}

/* 8x10 glyph (digits): rows 6..15 of an 8x16 cell in the small font sheet. */
// DigitFont_DrawGlyph @ 0x080ACB30
void DigitFont_DrawGlyph(u16 index, u8 *canvas, u16 x, u16 y)
{
    u32 row = (index >> 5) * 0x800;
    u32 col = (index & 0x1F) * 32 + 0xC00;

    Canvas_BlitOr(gSmallFontSheet + (row + col), canvas, 0, 6, x, y, 8, 10);
}

// DigitFont_DrawGlyphTinted @ 0x080ACB78
void DigitFont_DrawGlyphTinted(u16 index, u8 *canvas, u16 x, u16 y, u8 tint)
{
    u32 row = (index >> 5) * 0x800;
    u32 col = (index & 0x1F) * 32 + 0xC00;

    Canvas_BlitOrTinted(gSmallFontSheet + (row + col), canvas, 0, 6, x, y, 8, 10, tint);
}

/* Decimal digit string in the 8x10 font (characters must be '0'..'9'). */
// DigitFont_DrawStringTinted @ 0x080ACBC8
void DigitFont_DrawStringTinted(const u8 *str, u8 *canvas, u16 x, u16 y, u8 tint, u16 advance)
{
    while (*str != 0)
    {
        DigitFont_DrawGlyphTinted(gUnknown_0815EE96[*str - '0'], canvas, x, y, tint);
        str++;
        x += advance;
    }
}

/* A+B+Select+Start soft reset, unless gUnk_03003970 == 1. */
// System_CheckSoftReset @ 0x080ACC30
void System_CheckSoftReset(void)
{
    if (gUnk_03003970 != 1 && gUnk_030031D0 == 0xF)
        SoftReset(0xFF);
}

/* Fraction amount/256 of a 5-bit distance, rounded. */
#define COLOR_FX_STEP(dist, amount) ((((u16)(((dist) << 16) * (amount) / 0x1F00)) + 0x80) >> 8)

/* Applies the global color effect (gColorEffect) to one RGB555 color.  Mode 0: none.
   Mode 1: each channel moves toward 31 (r/g/b > 0) or 0 (< 0) by |r/g/b|/256 of the way.
   Other modes: the largest channel (and any middle one) goes down and the smallest up by
   desat% of half the spread, i.e. toward gray.  Color 0 is never changed. */
// Color_ApplyEffect @ 0x080ACC54
#ifdef NONMATCHING
/* Applies the global colour effect to a BGR555 colour: mode 1 brightens/darkens each channel
   by gColorEffect.r/g/b 256ths of the distance to white/black, other modes desaturate (move the
   brightest and darkest channel toward each other). */
u16 Color_ApplyEffect(u16 color)
{
    u16 dr = 0, dg = 0, db = 0;
    u16 r, g, b;

    if (color == 0)
        return 0;
    if (sub_080C2C70() == 0)
        return color;

    if (sub_080C2C70() == 1)
    {
        u16 pr, pg, pb;
        u16 m;
        u32 x;

        pg = gColorEffect.g;
        pb = gColorEffect.b;
        r = 0x1F;
        r &= color;
        g = (color & 0x3E0) >> 5;
        b = (color & 0x7C00) >> 10;
        pr = gColorEffect.r;
        if (gColorEffect.r > 0)
        {
            u16 q = ((31 - r) << 16) * pr / 0x1F00;
            dr = (q + 0x80) >> 8;
        }
        else if (gColorEffect.r < 0)
        {
            dr = -pr;
            dr = (((u16)((r << 16) * dr / 0x1F00) << 8) + 0x8000) >> 16;
        }
        if ((s16)pg > 0)
        {
            x = 31 - g;
            dg = gColorEffect.g;
            x = (s32)(x << 16) * dg / 0x1F00;
            x = ((u16)x << 8) + 0x8000;
            dg = (x >> 16) << 5;
        }
        else if ((s16)pg < 0)
        {
            dg = -gColorEffect.g;
            x = (g << 16) * dg / 0x1F00;
            x = ((u16)x << 8) + 0x8000;
            dg = (x >> 16) << 5;
        }
        if ((s16)pb > 0)
        {
            x = 31 - b;
            db = gColorEffect.b;
            x = (s32)(x << 16) * db / 0x1F00;
            x = ((u16)x << 8) + 0x8000;
            db = (x >> 16) << 10;
        }
        else if ((s16)pb < 0)
        {
            db = -gColorEffect.b;
            x = (b << 16) * db / 0x1F00;
            x = ((u16)x << 8) + 0x8000;
            db = (x >> 16) << 10;
        }

        m = 0x1F;
        m &= color;
        if (m)
        {
            if ((s16)pr > 0)
            {
                if (m + dr <= 30)
                    color += dr;
                else
                    color |= 0x1F;
            }
            else if ((s16)pr < 0)
            {
                if (dr < m)
                    color -= dr;
                else
                    color &= ~0x1F;
            }
        }
        if (color & 0x3E0)
        {
            if ((s16)pg > 0)
            {
                if ((color & 0x3E0) + dg <= 0x3DF)
                    color += dg;
                else
                    color |= 0x3E0;
            }
            else if ((s16)pg < 0)
            {
                if (dg < (color & 0x3E0))
                    color -= dg;
                else
                    color &= ~0x3E0;
            }
        }
        if (color & 0x7C00)
        {
            if ((s16)pb > 0)
            {
                if ((color & 0x7C00) + db <= 0x7BFF)
                    color += db;
                else
                    color |= 0x7C00;
            }
            else if ((s16)pb < 0)
            {
                if (db < (color & 0x7C00))
                    color -= db;
                else
                    color &= ~0x7C00;
            }
        }
    }
    else
    {
        s16 desat;
        u16 max, min, amount;

        desat = gColorEffect.desat;
        if (desat == 0)
            return color;
        min = 0xFFFF;
        r = 0x1F;
        r &= color;
        g = (color & 0x3E0) >> 5;
        b = (color & 0x7C00) >> 10;

        max = r;
        if (g >= max)
            max = g;
        if (b >= max)
            max = b;
        if (r <= min)
            min = r;
        if (g <= min)
            min = g;
        if (b <= min)
            min = b;

        amount = ((s32)(max - min) / 2) * desat / 100;
        if (amount == 0)
            return color;

        if (r == max)
        {
            if (r >= amount)
                r -= amount;
            else
                r = 0;
        }
        else if (r == min)
        {
            if (r + amount > 31)
                r = 31;
            else
                r += amount;
        }
        else
        {
            if (r >= amount)
                r -= amount;
            else
                r = 0;
        }
        if (g == max)
        {
            if (g >= amount)
                g -= amount;
            else
                g = 0;
        }
        else if (g == min)
        {
            if (g + amount > 31)
                g = 31;
            else
                g += amount;
        }
        else
        {
            if (g >= amount)
                g -= amount;
            else
                g = 0;
        }
        if (b == max)
        {
            if (b >= amount)
                b -= amount;
            else
                b = 0;
        }
        else if (b == min)
        {
            if (b + amount > 31)
                b = 31;
            else
                b += amount;
        }
        else
        {
            if (b >= amount)
                b -= amount;
            else
                b = 0;
        }
        return r + (g << 5) + (b << 10);
    }
    return color;
}
#else
NAKED
u16 Color_ApplyEffect(u16 color)
{
    asm_unified(
        ".L080ACC54:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x14\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    movs r0, #0\n"
        "    mov sb, r0\n"
        "    mov r8, r0\n"
        "    mov sl, r0\n"
        "    cmp r4, #0\n"
        "    bne .L080ACC72\n"
        "    b .L080ACF94\n"
        ".L080ACC72:\n"
        "    bl sub_080C2C70\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080ACC7E\n"
        "    b .L080ACF92\n"
        ".L080ACC7E:\n"
        "    bl sub_080C2C70\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    beq .L080ACC8C\n"
        "    b .L080ACEA4\n"
        ".L080ACC8C:\n"
        "    ldr r0, .L080ACCD4\n"
        "    ldrh r1, [r0, #2]\n"
        "    str r1, [sp, #4]\n"
        "    ldrh r2, [r0, #4]\n"
        "    str r2, [sp, #8]\n"
        "    movs r7, #0x1f\n"
        "    ands r7, r4\n"
        "    movs r1, #0xf8\n"
        "    lsls r1, r1, #2\n"
        "    ands r1, r4\n"
        "    lsrs r5, r1, #5\n"
        "    movs r1, #0xf8\n"
        "    lsls r1, r1, #7\n"
        "    ands r1, r4\n"
        "    lsrs r6, r1, #0xa\n"
        "    ldrh r1, [r0]\n"
        "    str r1, [sp]\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r0, r2]\n"
        "    cmp r1, #0\n"
        "    ble .L080ACCD8\n"
        "    movs r0, #0x1f\n"
        "    subs r0, r0, r7\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r1, [sp]\n"
        "    muls r0, r1, r0\n"
        "    movs r1, #0xf8\n"
        "    lsls r1, r1, #5\n"
        "    bl __divsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sb, r0\n"
        "    adds r0, #0x80\n"
        "    lsrs r0, r0, #8\n"
        "    b .L080ACD02\n"
        ".L080ACCD4: .4byte 0x03006080 @ IWRAM+0x6080\n"
        ".L080ACCD8:\n"
        "    cmp r1, #0\n"
        "    bge .L080ACD04\n"
        "    ldr r2, [sp]\n"
        "    rsbs r0, r2, #0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sb, r0\n"
        "    lsls r0, r7, #0x10\n"
        "    mov r1, sb\n"
        "    muls r1, r0, r1\n"
        "    adds r0, r1, #0\n"
        "    movs r1, #0xf8\n"
        "    lsls r1, r1, #5\n"
        "    bl __divsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #8\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #8\n"
        "    adds r0, r0, r2\n"
        "    lsrs r0, r0, #0x10\n"
        ".L080ACD02:\n"
        "    mov sb, r0\n"
        ".L080ACD04:\n"
        "    ldr r1, [sp, #4]\n"
        "    lsls r0, r1, #0x10\n"
        "    asrs r1, r0, #0x10\n"
        "    adds r7, r0, #0\n"
        "    cmp r1, #0\n"
        "    ble .L080ACD3C\n"
        "    movs r0, #0x1f\n"
        "    subs r0, r0, r5\n"
        "    ldr r2, .L080ACD38\n"
        "    ldrh r2, [r2, #2]\n"
        "    mov r8, r2\n"
        "    lsls r0, r0, #0x10\n"
        "    mov r1, r8\n"
        "    muls r1, r0, r1\n"
        "    adds r0, r1, #0\n"
        "    movs r1, #0xf8\n"
        "    lsls r1, r1, #5\n"
        "    bl __divsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #8\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #8\n"
        "    adds r0, r0, r2\n"
        "    b .L080ACD66\n"
        "    .byte 0x00, 0x00\n"
        ".L080ACD38: .4byte 0x03006080 @ IWRAM+0x6080\n"
        ".L080ACD3C:\n"
        "    cmp r1, #0\n"
        "    bge .L080ACD6E\n"
        "    ldr r1, .L080ACDA0\n"
        "    ldrh r0, [r1, #2]\n"
        "    rsbs r0, r0, #0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        "    lsls r0, r5, #0x10\n"
        "    mov r2, r8\n"
        "    muls r2, r0, r2\n"
        "    adds r0, r2, #0\n"
        "    movs r1, #0xf8\n"
        "    lsls r1, r1, #5\n"
        "    bl __divsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #8\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    adds r0, r0, r1\n"
        ".L080ACD66:\n"
        "    lsrs r0, r0, #0x10\n"
        "    lsls r0, r0, #0x15\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        ".L080ACD6E:\n"
        "    ldr r2, [sp, #8]\n"
        "    lsls r0, r2, #0x10\n"
        "    asrs r1, r0, #0x10\n"
        "    adds r5, r0, #0\n"
        "    cmp r1, #0\n"
        "    ble .L080ACDA4\n"
        "    movs r0, #0x1f\n"
        "    subs r0, r0, r6\n"
        "    ldr r1, .L080ACDA0\n"
        "    ldrh r1, [r1, #4]\n"
        "    mov sl, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    mov r2, sl\n"
        "    muls r2, r0, r2\n"
        "    adds r0, r2, #0\n"
        "    movs r1, #0xf8\n"
        "    lsls r1, r1, #5\n"
        "    bl __divsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #8\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    adds r0, r0, r1\n"
        "    b .L080ACDCE\n"
        ".L080ACDA0: .4byte 0x03006080 @ IWRAM+0x6080\n"
        ".L080ACDA4:\n"
        "    cmp r1, #0\n"
        "    bge .L080ACDD6\n"
        "    ldr r2, .L080ACDF4\n"
        "    ldrh r0, [r2, #4]\n"
        "    rsbs r0, r0, #0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sl, r0\n"
        "    lsls r0, r6, #0x10\n"
        "    mov r1, sl\n"
        "    muls r1, r0, r1\n"
        "    adds r0, r1, #0\n"
        "    movs r1, #0xf8\n"
        "    lsls r1, r1, #5\n"
        "    bl __divsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #8\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #8\n"
        "    adds r0, r0, r2\n"
        ".L080ACDCE:\n"
        "    lsrs r0, r0, #0x10\n"
        "    lsls r0, r0, #0x1a\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sl, r0\n"
        ".L080ACDD6:\n"
        "    movs r1, #0x1f\n"
        "    ands r1, r4\n"
        "    cmp r1, #0\n"
        "    beq .L080ACE14\n"
        "    ldr r2, [sp]\n"
        "    lsls r0, r2, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    ble .L080ACDFE\n"
        "    mov r2, sb\n"
        "    adds r0, r1, r2\n"
        "    cmp r0, #0x1e\n"
        "    bgt .L080ACDF8\n"
        "    adds r0, r4, r2\n"
        "    b .L080ACE0A\n"
        ".L080ACDF4: .4byte 0x03006080 @ IWRAM+0x6080\n"
        ".L080ACDF8:\n"
        "    movs r0, #0x1f\n"
        "    orrs r4, r0\n"
        "    b .L080ACE14\n"
        ".L080ACDFE:\n"
        "    cmp r0, #0\n"
        "    bge .L080ACE14\n"
        "    cmp sb, r1\n"
        "    bhs .L080ACE10\n"
        "    mov r1, sb\n"
        "    subs r0, r4, r1\n"
        ".L080ACE0A:\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    b .L080ACE14\n"
        ".L080ACE10:\n"
        "    ldr r0, .L080ACE34\n"
        "    ands r4, r0\n"
        ".L080ACE14:\n"
        "    movs r2, #0xf8\n"
        "    lsls r2, r2, #2\n"
        "    adds r1, r4, #0\n"
        "    ands r1, r2\n"
        "    cmp r1, #0\n"
        "    beq .L080ACE56\n"
        "    asrs r0, r7, #0x10\n"
        "    cmp r0, #0\n"
        "    ble .L080ACE40\n"
        "    add r1, r8\n"
        "    ldr r0, .L080ACE38\n"
        "    cmp r1, r0\n"
        "    bgt .L080ACE3C\n"
        "    mov r2, r8\n"
        "    adds r0, r4, r2\n"
        "    b .L080ACE4C\n"
        ".L080ACE34: .4byte 0x0000FFE0\n"
        ".L080ACE38: .4byte 0x000003DF\n"
        ".L080ACE3C:\n"
        "    orrs r4, r2\n"
        "    b .L080ACE56\n"
        ".L080ACE40:\n"
        "    cmp r0, #0\n"
        "    bge .L080ACE56\n"
        "    cmp r8, r1\n"
        "    bhs .L080ACE52\n"
        "    mov r1, r8\n"
        "    subs r0, r4, r1\n"
        ".L080ACE4C:\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    b .L080ACE56\n"
        ".L080ACE52:\n"
        "    ldr r0, .L080ACE78\n"
        "    ands r4, r0\n"
        ".L080ACE56:\n"
        "    movs r2, #0xf8\n"
        "    lsls r2, r2, #7\n"
        "    adds r1, r4, #0\n"
        "    ands r1, r2\n"
        "    cmp r1, #0\n"
        "    bne .L080ACE64\n"
        "    b .L080ACF92\n"
        ".L080ACE64:\n"
        "    asrs r0, r5, #0x10\n"
        "    cmp r0, #0\n"
        "    ble .L080ACE84\n"
        "    add r1, sl\n"
        "    ldr r0, .L080ACE7C\n"
        "    cmp r1, r0\n"
        "    bgt .L080ACE80\n"
        "    mov r2, sl\n"
        "    adds r0, r4, r2\n"
        "    b .L080ACE92\n"
        ".L080ACE78: .4byte 0x0000FC1F\n"
        ".L080ACE7C: .4byte 0x00007BFF\n"
        ".L080ACE80:\n"
        "    orrs r4, r2\n"
        "    b .L080ACF92\n"
        ".L080ACE84:\n"
        "    cmp r0, #0\n"
        "    blt .L080ACE8A\n"
        "    b .L080ACF92\n"
        ".L080ACE8A:\n"
        "    cmp sl, r1\n"
        "    bhs .L080ACE98\n"
        "    mov r1, sl\n"
        "    subs r0, r4, r1\n"
        ".L080ACE92:\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    b .L080ACF92\n"
        ".L080ACE98:\n"
        "    ldr r0, .L080ACEA0\n"
        "    ands r4, r0\n"
        "    b .L080ACF92\n"
        "    .byte 0x00, 0x00\n"
        ".L080ACEA0: .4byte 0x000083FF\n"
        ".L080ACEA4:\n"
        "    ldr r0, .L080ACF14\n"
        "    movs r1, #6\n"
        "    ldrsh r2, [r0, r1]\n"
        "    mov r8, r2\n"
        "    cmp r2, #0\n"
        "    beq .L080ACF92\n"
        "    ldr r3, .L080ACF18\n"
        "    movs r7, #0x1f\n"
        "    ands r7, r4\n"
        "    movs r0, #0xf8\n"
        "    lsls r0, r0, #2\n"
        "    ands r0, r4\n"
        "    lsrs r5, r0, #5\n"
        "    movs r0, #0xf8\n"
        "    lsls r0, r0, #7\n"
        "    ands r0, r4\n"
        "    lsrs r6, r0, #0xa\n"
        "    adds r2, r7, #0\n"
        "    cmp r5, r7\n"
        "    blo .L080ACECE\n"
        "    adds r2, r5, #0\n"
        ".L080ACECE:\n"
        "    cmp r6, r2\n"
        "    blo .L080ACED4\n"
        "    adds r2, r6, #0\n"
        ".L080ACED4:\n"
        "    cmp r7, r3\n"
        "    bhi .L080ACEDA\n"
        "    adds r3, r7, #0\n"
        ".L080ACEDA:\n"
        "    cmp r5, r3\n"
        "    bhi .L080ACEE0\n"
        "    adds r3, r5, #0\n"
        ".L080ACEE0:\n"
        "    cmp r6, r3\n"
        "    bhi .L080ACEE6\n"
        "    adds r3, r6, #0\n"
        ".L080ACEE6:\n"
        "    subs r0, r2, r3\n"
        "    lsrs r1, r0, #0x1f\n"
        "    adds r0, r0, r1\n"
        "    asrs r0, r0, #1\n"
        "    mov r1, r8\n"
        "    muls r1, r0, r1\n"
        "    adds r0, r1, #0\n"
        "    movs r1, #0x64\n"
        "    str r2, [sp, #0xc]\n"
        "    str r3, [sp, #0x10]\n"
        "    bl __divsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    ldr r2, [sp, #0xc]\n"
        "    ldr r3, [sp, #0x10]\n"
        "    cmp r1, #0\n"
        "    beq .L080ACF92\n"
        "    cmp r7, r2\n"
        "    bne .L080ACF1C\n"
        "    cmp r7, r1\n"
        "    bhs .L080ACF2E\n"
        "    b .L080ACF36\n"
        ".L080ACF14: .4byte 0x03006080 @ IWRAM+0x6080\n"
        ".L080ACF18: .4byte 0x0000FFFF\n"
        ".L080ACF1C:\n"
        "    cmp r7, r3\n"
        "    bne .L080ACF2A\n"
        "    adds r0, r7, r1\n"
        "    cmp r0, #0x1f\n"
        "    ble .L080ACF30\n"
        "    movs r7, #0x1f\n"
        "    b .L080ACF38\n"
        ".L080ACF2A:\n"
        "    cmp r7, r1\n"
        "    blo .L080ACF36\n"
        ".L080ACF2E:\n"
        "    subs r0, r7, r1\n"
        ".L080ACF30:\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    b .L080ACF38\n"
        ".L080ACF36:\n"
        "    movs r7, #0\n"
        ".L080ACF38:\n"
        "    cmp r5, r2\n"
        "    bne .L080ACF42\n"
        "    cmp r5, r1\n"
        "    bhs .L080ACF54\n"
        "    b .L080ACF5C\n"
        ".L080ACF42:\n"
        "    cmp r5, r3\n"
        "    bne .L080ACF50\n"
        "    adds r0, r5, r1\n"
        "    cmp r0, #0x1f\n"
        "    ble .L080ACF56\n"
        "    movs r5, #0x1f\n"
        "    b .L080ACF5E\n"
        ".L080ACF50:\n"
        "    cmp r5, r1\n"
        "    blo .L080ACF5C\n"
        ".L080ACF54:\n"
        "    subs r0, r5, r1\n"
        ".L080ACF56:\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    b .L080ACF5E\n"
        ".L080ACF5C:\n"
        "    movs r5, #0\n"
        ".L080ACF5E:\n"
        "    cmp r6, r2\n"
        "    bne .L080ACF68\n"
        "    cmp r6, r1\n"
        "    bhs .L080ACF7A\n"
        "    b .L080ACF82\n"
        ".L080ACF68:\n"
        "    cmp r6, r3\n"
        "    bne .L080ACF76\n"
        "    adds r0, r6, r1\n"
        "    cmp r0, #0x1f\n"
        "    ble .L080ACF7C\n"
        "    movs r6, #0x1f\n"
        "    b .L080ACF84\n"
        ".L080ACF76:\n"
        "    cmp r6, r1\n"
        "    blo .L080ACF82\n"
        ".L080ACF7A:\n"
        "    subs r0, r6, r1\n"
        ".L080ACF7C:\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    b .L080ACF84\n"
        ".L080ACF82:\n"
        "    movs r6, #0\n"
        ".L080ACF84:\n"
        "    lsls r0, r5, #5\n"
        "    adds r0, r7, r0\n"
        "    lsls r1, r6, #0xa\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    b .L080ACF94\n"
        ".L080ACF92:\n"
        "    adds r0, r4, #0\n"
        ".L080ACF94:\n"
        "    add sp, #0x14\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

/* Fill / copy palette data through the color effect.  The unused first argument and the
   byte size suggest these stand in for a fill/copy routine with the same signature. */
// Palette_FillWithEffect @ 0x080ACFA4
void Palette_FillWithEffect(void *unused, u16 color, u16 *dst, u32 size)
{
    u32 i;

    for (i = 0; i < size / 2; i++)
        dst[i] = Color_ApplyEffect(color);
}

// Palette_CopyWithEffect @ 0x080ACFCC
void Palette_CopyWithEffect(void *unused, const u16 *src, u16 *dst, u32 size)
{
    u32 i;

    for (i = 0; i < size / 2; i++)
        dst[i] = Color_ApplyEffect(src[i]);
}
