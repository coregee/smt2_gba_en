/* Sprite submission: copies OAM templates into the per-layer sprite lists. */

#include "global.h"
#include "sys.h"

// Sprite_DrawWithMode @ 0x080A9F04
/* Queues every OAM entry of def (last first), offset by tile/x/y/palette.  Bit 15 of x
   turns on mosaic.  With an affine table, each entry gets its own rotation/scale matrix. */
void Sprite_DrawWithMode(const u16 **def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y,
                  u16 objMode)
{
    const u16 *src = *def++;
    const u16 *affine = *def;
    u32 count = *src++;
    u16 i;
    u16 mosaic = x & 0xF000;

    x &= 0x7FFF;
    src += (count - 1) * 3;
    for (i = 0; i < count; i++)
    {
        struct OamData *oam = &Sprite_Alloc(layer)->oam;
        u16 *dst = (u16 *)oam;

        dst[0] = *src++;
        dst[1] = *src++;
        dst[2] = *src++;
        src -= 6;
        if (affine != NULL)
        {
            const u16 *a;
            u16 n;
            u16 j;
            u16 angle, scaleX, scaleY;
            struct AffineSlot *slot;
            s16 cos;
            u16 pa, pb, pc, pd;

            n = *affine;
            a = affine + 1;
            j = i;
            if (n - 1 < j)
                j = n - 1;
            a += j * 3;
            angle = *a++;
            scaleX = *a++;
            scaleY = *a;
            slot = &gAffineSlots[gAffineCount];
            cos = gSineTable[angle + 0x40];
            pa = FixedMul8(cos, FixedInverse8(scaleX));
            pb = FixedMul8(gSineTable[angle], FixedInverse8(scaleX));
            pc = FixedMul8(-gSineTable[angle], FixedInverse8(scaleY));
            pd = FixedMul8(cos, FixedInverse8(scaleY));
            slot->pa = pa;
            slot->pb = pb;
            slot->pc = pc;
            slot->pd = pd;
            oam->affineMode |= 1;
            oam->matrixNum = gAffineCount;
            gAffineCount++;
        }
        oam->x += x & 0x1FF;
        oam->y += y;
        oam->objMode = objMode;
        if (mosaic == 0x8000)
            oam->mosaic = 1;
        else
            oam->mosaic = 0;
        oam->priority = priority;
        oam->tileNum += tile;
        oam->paletteNum += palette;
    }
}

// Sprite_Draw @ 0x080AA184
void Sprite_Draw(const u16 **def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y)
{
    Sprite_DrawWithMode(def, layer, palette, priority, tile, x, y, 0);
}

// Sprite_DrawBlended @ 0x080AA1BC
/* Same as Sprite_Draw with semi-transparent OBJ mode. */
void Sprite_DrawBlended(const u16 **def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y)
{
    Sprite_DrawWithMode(def, layer, palette, priority, tile, x, y, 1);
}

// Sprite_DrawSingle @ 0x080AA1F4
/* Queues a single OAM entry. */
void Sprite_DrawSingle(const struct OamTemplate *src, u16 layer, u16 palette, u16 priority, u16 tile,
                  u16 x, u16 y)
{
    struct OamData *oam;
    u16 mosaic = x & 0xF000;

    x &= 0x7FFF;
    oam = &Sprite_Alloc(layer)->oam;
    ((vu16 *)oam)[0] = src->attr0;
    ((vu16 *)oam)[1] = src->attr1;
    ((vu16 *)oam)[2] = src->attr2;
    oam->x += x & 0x1FF;
    oam->y += y;
    oam->priority = priority;
    if (mosaic == 0x8000)
        oam->mosaic = 1;
    else
        oam->mosaic = 0;
    oam->tileNum += tile;
    oam->paletteNum += palette;
}

// Sprite_DrawPlain @ 0x080AA2DC
/* Sprite_DrawWithMode without the mosaic flag or OBJ mode. */
void Sprite_DrawPlain(const u16 **def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y)
{
    const u16 *src = *def++;
    const u16 *affine = *def;
    u32 count = *src++;
    u16 i;

    src += (count - 1) * 3;
    for (i = 0; i < count; i++)
    {
        struct OamData *oam = &Sprite_Alloc(layer)->oam;
        u16 *dst = (u16 *)oam;

        dst[0] = *src++;
        dst[1] = *src++;
        dst[2] = *src++;
        src -= 6;
        if (affine != NULL)
        {
            const u16 *a;
            u16 n;
            u16 j;
            u16 angle, scaleX, scaleY;
            struct AffineSlot *slot;
            s16 cos;
            u16 pa, pb, pc, pd;

            n = *affine;
            a = affine + 1;
            j = i;
            if (n - 1 < j)
                j = n - 1;
            a += j * 3;
            angle = *a++;
            scaleX = *a++;
            scaleY = *a;
            slot = &gAffineSlots[gAffineCount];
            cos = gSineTable[angle + 0x40];
            pa = FixedMul8(cos, FixedInverse8(scaleX));
            pb = FixedMul8(gSineTable[angle], FixedInverse8(scaleX));
            pc = FixedMul8(-gSineTable[angle], FixedInverse8(scaleY));
            pd = FixedMul8(cos, FixedInverse8(scaleY));
            slot->pa = pa;
            slot->pb = pb;
            slot->pc = pc;
            slot->pd = pd;
            oam->affineMode |= 1;
            oam->matrixNum = gAffineCount;
            gAffineCount++;
        }
        oam->x += x & 0x1FF;
        oam->y += y;
        oam->priority = priority;
        oam->tileNum += tile;
        oam->mosaic = 0;
        oam->paletteNum += palette;
    }
}

// sub_080AA514 @ 0x080AA514
void sub_080AA514(const u16 **def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y,
                  u16 objMode)
{
    const u16 *src = *def++;
    const u16 *affine = *def;
    u32 count = *src++;
    u16 i;
    u16 mosaic = x & 0xF000;

    x &= 0x7FFF;
    src += (count - 1) * 3;
    for (i = 0; i < count; i++)
    {
        struct OamData *oam = &Sprite_Alloc(layer)->oam;
        u16 *dst = (u16 *)oam;

        dst[0] = *src++;
        dst[1] = *src++;
        dst[2] = *src++;
        src -= 6;
        if (affine != NULL)
        {
            const u16 *a;
            u16 n;
            u16 j;
            u16 angle, scaleX, scaleY;
            struct AffineSlot *slot;
            s16 cos;
            u16 pa, pb, pc, pd;

            n = *affine;
            a = affine + 1;
            j = i;
            if (n - 1 < j)
                j = n - 1;
            a += j * 3;
            angle = *a++;
            scaleX = *a++;
            scaleY = *a;
            slot = &gAffineSlots[gAffineCount];
            cos = gSineTable[angle + 0x40];
            pa = FixedMul8(cos, FixedInverse8(scaleX));
            pb = FixedMul8(gSineTable[angle], FixedInverse8(scaleX));
            pc = FixedMul8(-gSineTable[angle], FixedInverse8(scaleY));
            pd = FixedMul8(cos, FixedInverse8(scaleY));
            slot->pa = pa;
            slot->pb = pb;
            slot->pc = pc;
            slot->pd = pd;
            oam->affineMode |= 1;
            oam->matrixNum = gAffineCount;
            gAffineCount++;
        }
        oam->x += x & 0x1FF;
        oam->y += y;
        oam->priority = priority;
        oam->objMode = objMode;
        oam->tileNum += tile;
        oam->mosaic = 0;
        if (mosaic == 0x8000)
            oam->mosaic = 1;
        else
            oam->mosaic = 0;
        oam->paletteNum += palette;
    }
}

// Sprite_DrawSharedAffine @ 0x080AA790
/* Queues all entries of def with one shared affine matrix (number `matrix`), built from the
   first {scaleX, scaleY, angle} of the affine table. */
void Sprite_DrawSharedAffine(const u16 **def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y,
                  u8 matrix)
{
    const u16 *src = *def++;
    const u16 *affine = *def;
    u32 count = *src++;
    u16 i;

    /* Skips the count before testing for NULL, so a sprite without an affine table would
       read its matrix from address 2. */
    affine++;
    if (affine != NULL)
    {
        u16 scaleY = affine[1];
        u16 angle = affine[2];
        struct AffineSlot *slot = &gAffineSlots[matrix];
        s16 cos = gSineTable[angle + 0x40];
        s16 scaleX = affine[0];
        u16 pa, pb, pc, pd;

        pa = FixedMul8(cos, FixedInverse8(scaleX));
        pb = FixedMul8(gSineTable[angle], FixedInverse8(scaleX));
        pc = FixedMul8(-gSineTable[angle], FixedInverse8(scaleY));
        pd = FixedMul8(cos, FixedInverse8(scaleY));
        slot->pa = pa;
        slot->pb = pb;
        slot->pc = pc;
        slot->pd = pd;
    }
    src += (count - 1) * 3;
    for (i = 0; i < count; i++)
    {
        struct OamData *oam = &Sprite_Alloc(layer)->oam;
        u16 *dst = (u16 *)oam;

        dst[0] = *src++;
        dst[1] = *src++;
        dst[2] = *src++;
        src -= 6;
        if (affine != NULL)
        {
            oam->affineMode |= 1;
            oam->matrixNum = matrix;
        }
        oam->x += x & 0x1FF;
        oam->y += y;
        oam->priority = priority;
        oam->tileNum += tile;
        oam->mosaic = 0;
        oam->paletteNum += palette;
    }
}

// Sprite_DrawSharedAffineDouble @ 0x080AA998
/* Sprite_DrawSharedAffine with double-size affine sprites and an OBJ mode. */
void Sprite_DrawSharedAffineDouble(const u16 **def, u16 layer, u16 palette, u16 priority, u16 tile, u16 x, u16 y,
                  u8 matrix, u16 objMode)
{
    const u16 *src = *def++;
    const u16 *affine = *def;
    u32 count = *src++;
    u16 i;

    affine++;
    if (affine != NULL)
    {
        u16 scaleY = affine[1];
        u16 angle = affine[2];
        struct AffineSlot *slot = &gAffineSlots[matrix];
        s16 cos = gSineTable[angle + 0x40];
        s16 scaleX = affine[0];
        u16 pa, pb, pc, pd;

        pa = FixedMul8(cos, FixedInverse8(scaleX));
        pb = FixedMul8(gSineTable[angle], FixedInverse8(scaleX));
        pc = FixedMul8(-gSineTable[angle], FixedInverse8(scaleY));
        pd = FixedMul8(cos, FixedInverse8(scaleY));
        slot->pa = pa;
        slot->pb = pb;
        slot->pc = pc;
        slot->pd = pd;
    }
    src += (count - 1) * 3;
    for (i = 0; i < count; i++)
    {
        struct OamData *oam = &Sprite_Alloc(layer)->oam;
        u16 *dst = (u16 *)oam;

        dst[0] = *src++;
        dst[1] = *src++;
        dst[2] = *src++;
        src -= 6;
        if (affine != NULL)
        {
            oam->affineMode |= 3;
            oam->matrixNum = matrix;
        }
        oam->x += x & 0x1FF;
        oam->y += y;
        oam->objMode = objMode;
        oam->priority = priority;
        oam->tileNum += tile;
        oam->mosaic = 0;
        oam->paletteNum += palette;
    }
}
