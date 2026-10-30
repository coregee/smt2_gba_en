#include "global.h"
#include "inventory.h"

// sub_080C5FDC @ 0x080C5FDC
void sub_080C5FDC(void)
{
    DmaFill32(3, 0, gUnk_02000000, 0x1000);
    Tilemap_CopyRectSkipZero(gUnknown_0822E52C, gUnk_02000000, 0x320, 8, 0, 0, 0x20, 0xD);
    VBlankTask_AddCounted(sub_080C5F78, 1);
}

// sub_080C6030 @ 0x080C6030
void sub_080C6030(void)
{
    Palette_CopyWithEffect(3, gUnknown_0822E174, &gPaletteTarget[0x80], 0x20, 0x20);
    sub_080B04BC();
    sub_080B2840(0, 0, 0);
}

// sub_080C6060 @ 0x080C6060
void sub_080C6060(void)
{
    gFieldState.unk1E = 8;
}

// sub_080C606C @ 0x080C606C
void sub_080C606C(struct Task *t)
{
    if (gFieldState.unk0E == 0)
    {
        VBlankTask_AddCounted(sub_080B0158, 1);
        t->result = 1;
        gUnk_0200AB04 |= 0x8000;
    }
    else
    {
        t->result = 0;
    }
}

// sub_080C60AC @ 0x080C60AC
void sub_080C60AC(void)
{
    DmaFill32(3, 0, (void *)0x06001000, 0x800);
    REG_BG1CNT = 0x8209;
}

// sub_080C60E0 @ 0x080C60E0
void sub_080C60E0(void)
{
    sub_080C1440();
    gUnk_0300000E = 0;
    gUnk_0300000C = 0;
    gUnk_03000006 = 0;
    gUnk_03000004 = 0;
    VBlankTask_AddCounted(sub_080C60AC, 1);
}

// sub_080C6118 @ 0x080C6118
void sub_080C6118(void)
{
    sub_080C7C94();
}

// sub_080C6124 @ 0x080C6124
void sub_080C6124(void)
{
    DmaCopy32(3, (void *)0x02001000, (void *)0x06004000, 0x1800);
    REG_BG1CNT = 0x8205;
}

// sub_080C6154 @ 0x080C6154
void sub_080C6154(void)
{
    const void *src = gUnknown_0824D1E4;
    u8 *buf = (u8 *)0x02001000;

    LZ77UnCompWram(src, buf);
    LZ77UnCompWram(gUnknown_0824DF94, buf + 0x1000);
    VBlankTask_AddCounted(sub_080C6124, 1);
}

// sub_080C618C @ 0x080C618C
void sub_080C618C(void)
{
    DmaCopy32(3, gUnk_02000000, (void *)0x06003000, 0x800);
}

// sub_080C61B0 @ 0x080C61B0
void sub_080C61B0(void)
{
    DmaCopy32(3, gUnk_02000000, (void *)0x06001000, 0x800);
}

// sub_080C61D4 @ 0x080C61D4
void sub_080C61D4(u32 unused, u32 mode)
{
    DmaFill32(3, 0, gUnk_02000000, 0x1000);
    if (mode == 0)
    {
        Tilemap_CopyRectSkipZero(gUnknown_0824E75C, gUnk_02000000, 0, 8, 0, 0, 0x20, 0xD);
        VBlankTask_AddCounted(sub_080C618C, 1);
        gUnk_0300000E = 0;
        gUnk_03000006 = 0;
    }
    else
    {
        Tilemap_CopyRectSkipZero(gUnknown_0824EA9C, gUnk_02000000, 0, 8, 0, 0, 0x20, 0xD);
        VBlankTask_AddCounted(sub_080C61B0, 1);
        gUnk_03000040 = 0x3C40;
    }
}

// CharObj_FindById @ 0x080C6278
/* The character object showing id, or NULL. */
struct Task *CharObj_FindById(u16 id)
{
    u32 i;

    for (i = 0; i < 6; i++)
    {
        struct Task *t = gCharTasks[i];

        if (t != NULL && ((struct ObjData *)t->data.raw)->id == id)
            return t;
    }
    return NULL;
}

// sub_080C62A8 @ 0x080C62A8
void sub_080C62A8(void)
{
    struct Task *t;

    Palette_CopyWithEffect(3, gUnknown_0824EDDC, &gPaletteTarget[0x80], 0x100, 0x20);
    t = CharObj_FindById(0xD8);
    if (t != NULL)
        ((struct ObjData *)t->data.raw)->unk10 = 0;
    t = CharObj_FindById(0x1BC);
    if (t != NULL)
        ((struct ObjData *)t->data.raw)->unk10 = 1;
}

// sub_080C62F0 @ 0x080C62F0
void sub_080C62F0(void)
{
    DmaCopy32(3, (void *)0x02001000, (void *)0x06004000, 0x2C00);
    REG_BG1CNT = 0x4207;
    REG_BG3CNT = 0x8606;
    sub_080C153C();
}

// sub_080C6334 @ 0x080C6334
void sub_080C6334(void)
{
    const void *src = gUnknown_08245B80;
    u8 *buf = (u8 *)0x02001000;

    LZ77UnCompWram(src, buf);
    LZ77UnCompWram(gUnknown_08245E28, buf + 0x1000);
    LZ77UnCompWram(gUnknown_0824696C, buf + 0x2000);
    sub_080C14FC();
    Tilemap_FillRect(0, gUnk_02000000, 1, 0, 0x1C, 0xD);
    {
        vu16 tmp = 0;
        vu32 *dma = (vu32 *)0x040000D4;
        /* DmaFill16, with the source address pinned to r2 as in the original. */
        register vu16 *p asm("r2") = &tmp;
        dma[0] = (vu32)p;
        dma[1] = (vu32)&gPaletteBuffer[0x80];
        dma[2] = 0x81000080;
        dma[2];
    }
    gUnk_0200AB04 |= 0x8000;
    VBlankTask_AddCounted(sub_080C62F0, 1);
}

// sub_080C63D0 @ 0x080C63D0
void sub_080C63D0(void)
{
    DmaCopy32(3, gUnk_02000000, (void *)0x06003000, 0x1000);
}

// sub_080C63F4 @ 0x080C63F4
void sub_080C63F4(void)
{
    DmaCopy32(3, gUnk_02000000, (void *)0x06001000, 0x1000);
}

// sub_080C6418 @ 0x080C6418
void sub_080C6418(u32 unused, u32 mode)
{
    DmaFill32(3, 0, gUnk_02000000, 0x1000);
    if (mode == 0)
    {
        Tilemap_CopyRectSkipZero(gUnknown_082483CC, gUnk_02000000, 0, 8, 0, 0, 0x20, 0x15);
        VBlankTask_AddCounted(sub_080C63D0, 1);
        gUnk_0300000E = 0x40;
    }
    else
    {
        Tilemap_CopyRectSkipZero(gUnknown_082473CC, gUnk_02000000, 0, 8, 0, 0, 0x20, 0x40);
        VBlankTask_AddCounted(sub_080C63F4, 1);
        gUnk_03000006 = 0x68;
        gUnk_03000040 = 0x3C40;
    }
}

// sub_080C64BC @ 0x080C64BC
void sub_080C64BC(void)
{
    Palette_CopyWithEffect(3, gUnknown_082472CC, &gPaletteTarget[0x80], 0x100, 0x20);
}

// sub_080C64E0 @ 0x080C64E0
void sub_080C64E0(void)
{
    DmaFill32(3, 0, (void *)0x06001000, 0x1000);
    REG_BG1CNT = 0x8209;
    REG_BG3CNT = 0x8607;
}

// sub_080C6520 @ 0x080C6520
void sub_080C6520(void)
{
    sub_080C1440();
    VBlankTask_AddCounted(sub_080C64E0, 1);
    gUnk_03000006 = 0;
    gUnk_03000004 = 0;
    gUnk_0300000E = 0;
    gUnk_0300000C = 0;
}

// sub_080C6558 @ 0x080C6558
void sub_080C6558(void)
{
    if (!Flag_Test(0xC6) && gMainCallback != sub_080D977C)
        Tilemap_CopyRectSkipZero(gUnknown_081B90B0, gWindowTilemapBuffer, 0, 0, 3, 0xC, 0x18, 1);
}

// sub_080C65A4 @ 0x080C65A4
void sub_080C65A4(void)
{
    DmaCopy32(3, gUnknown_081A7DB8, (void *)0x06011500, 0x400);
}

// sub_080C65C8 @ 0x080C65C8
void sub_080C65C8(void)
{
    u32 i;

    for (i = 0; i < 6; i++)
    {
        gUnk_0200F7D8[i][0] = 0x5000;
        gUnk_0200F7D8[i][1] = 0x5000;
    }
}
