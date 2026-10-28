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
#ifdef NONMATCHING
void sub_080C6334(void)
{
    const void *src = gUnknown_08245B80;
    u8 *buf = (u8 *)0x02001000;

    LZ77UnCompWram(src, buf);
    LZ77UnCompWram(gUnknown_08245E28, buf + 0x1000);
    LZ77UnCompWram(gUnknown_0824696C, buf + 0x2000);
    sub_080C14FC();
    Tilemap_FillRect(0, gUnk_02000000, 1, 0, 0x1C, 0xD);
    DmaFill16(3, 0, &gPaletteBuffer[0x80], 0x100);
    gUnk_0200AB04 |= 0x8000;
    VBlankTask_AddCounted(sub_080C62F0, 1);
}
#else
NAKED
void sub_080C6334(void)
{
    asm_unified(
        "    push {r4, lr}\n"
        "    sub sp, #0xc\n"
        "    ldr r0, .L080C63A8\n"
        "    ldr r4, .L080C63AC\n"
        "    adds r1, r4, #0\n"
        "    bl LZ77UnCompWram\n"
        "    ldr r0, .L080C63B0\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #5\n"
        "    adds r1, r4, r2\n"
        "    bl LZ77UnCompWram\n"
        "    ldr r0, .L080C63B4\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #6\n"
        "    adds r4, r4, r1\n"
        "    adds r1, r4, #0\n"
        "    bl LZ77UnCompWram\n"
        "    bl sub_080C14FC\n"
        "    ldr r1, .L080C63B8\n"
        "    movs r0, #0x1c\n"
        "    str r0, [sp]\n"
        "    movs r0, #0xd\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r2, #1\n"
        "    movs r3, #0\n"
        "    bl Tilemap_FillRect\n"
        "    add r1, sp, #8\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L080C63BC\n"
        "    add r2, sp, #8\n"
        "    str r2, [r1]\n"
        "    ldr r0, .L080C63C0\n"
        "    str r0, [r1, #4]\n"
        "    ldr r0, .L080C63C4\n"
        "    str r0, [r1, #8]\n"
        "    ldr r0, [r1, #8]\n"
        "    ldr r2, .L080C63C8\n"
        "    ldr r0, [r2]\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    orrs r0, r1\n"
        "    str r0, [r2]\n"
        "    ldr r0, .L080C63CC\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    add sp, #0xc\n"
        "    pop {r4}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080C63A8: .4byte gUnknown_08245B80\n"
        ".L080C63AC: .4byte 0x02001000 @ EWRAM+0x1000\n"
        ".L080C63B0: .4byte gUnknown_08245E28\n"
        ".L080C63B4: .4byte gUnknown_0824696C\n"
        ".L080C63B8: .4byte 0x02000000 @ EWRAM\n"
        ".L080C63BC: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080C63C0: .4byte 0x03002EB0 @ IWRAM+0x2EB0\n"
        ".L080C63C4: .4byte 0x81000080\n"
        ".L080C63C8: .4byte 0x0200AB04 @ EWRAM+0xAB04\n"
        ".L080C63CC: .4byte sub_080C62F0\n"
    );
}
#endif

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
