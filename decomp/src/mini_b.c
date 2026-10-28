#include "global.h"
#include "extras.h"

// sub_080DE0DC @ 0x080DE0DC
void sub_080DE0DC(void)
{
    if (sub_080DE0F8())
    {
        sub_080DE208();
        Task_RunAll();
        PlayTime_Tick();
    }
}

/* Loads the mini program's graphics one piece per frame; 1 when done. */
// sub_080DE0F8 @ 0x080DE0F8
#ifdef NONMATCHING
u8 sub_080DE0F8(void)
{
    u8 *buf;

    switch (gC0d9Bg.unk36)
    {
    case 0:
        LZ77UnCompWram(gUnknown_08587130, (void *)0x02001000);
        break;
    case 1:
        buf = gUnk_02002000;
        LZ77UnCompWram(gUnknown_085874EC, buf);
        DmaSet3(buf - 0x1000, 0x06004000, 0x84000800);
        break;
    case 2:
        LZ77UnCompWram(gUnknown_08588050, gUnk_02001000);
        break;
    case 3:
        LZ77UnCompWram(gUnknown_085887D4, gUnk_02002000);
        break;
    case 4:
        LZ77UnCompWram(gUnknown_08588FA4, gUnk_02003000);
        break;
    case 5:
        buf = gUnk_02004000;
        LZ77UnCompWram(gUnknown_0858979C, buf);
        DmaSet3(buf - 0x3000, 0x06008000, 0x84000E00);
        gC0d9Bg.unk36++;
        gC0d9Bg.fade = PalFade_FadeInFromBlack(1);
    default:
        return 1;
    }
    gC0d9Bg.unk36++;
    return 0;
}
#else
NAKED
u8 sub_080DE0F8(void)
{
    asm_unified(
        ".L080DE0F8:\n"
        "    push {r4, lr}\n"
        "    ldr r0, .L080DE110\n"
        "    movs r1, #0x36\n"
        "    ldrsh r0, [r0, r1]\n"
        "    cmp r0, #5\n"
        "    bhi .L080DE1E4\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L080DE114\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080DE110: .4byte 0x020399E0 @ EWRAM+0x399E0\n"
        ".L080DE114: .4byte gUnknown_080DE118\n"
        "    .global gUnknown_080DE118\n"
        "gUnknown_080DE118:\n"
        ".L080DE118: @ jump table\n"
        "    .4byte .L080DE130\n"
        "    .4byte .L080DE140\n"
        "    .4byte .L080DE178\n"
        "    .4byte .L080DE188\n"
        "    .4byte .L080DE198\n"
        "    .4byte .L080DE1B8\n"
        ".L080DE130:\n"
        "    ldr r0, .L080DE138\n"
        "    ldr r1, .L080DE13C\n"
        "    b .L080DE19C\n"
        "    .byte 0x00, 0x00\n"
        ".L080DE138: .4byte gUnknown_08587130\n"
        ".L080DE13C: .4byte 0x02001000 @ EWRAM+0x1000\n"
        ".L080DE140:\n"
        "    ldr r0, .L080DE160\n"
        "    ldr r4, .L080DE164\n"
        "    adds r1, r4, #0\n"
        "    bl LZ77UnCompWram\n"
        "    ldr r1, .L080DE168\n"
        "    ldr r0, .L080DE16C\n"
        "    adds r4, r4, r0\n"
        "    str r4, [r1]\n"
        "    ldr r0, .L080DE170\n"
        "    str r0, [r1, #4]\n"
        "    ldr r0, .L080DE174\n"
        "    str r0, [r1, #8]\n"
        "    ldr r0, [r1, #8]\n"
        "    b .L080DE1A0\n"
        "    .byte 0x00, 0x00\n"
        ".L080DE160: .4byte gUnknown_085874EC\n"
        ".L080DE164: .4byte 0x02002000 @ EWRAM+0x2000\n"
        ".L080DE168: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080DE16C: .4byte 0xFFFFF000\n"
        ".L080DE170: .4byte 0x06004000 @ VRAM+0x4000\n"
        ".L080DE174: .4byte 0x84000800\n"
        ".L080DE178:\n"
        "    ldr r0, .L080DE180\n"
        "    ldr r1, .L080DE184\n"
        "    b .L080DE19C\n"
        "    .byte 0x00, 0x00\n"
        ".L080DE180: .4byte gUnknown_08588050\n"
        ".L080DE184: .4byte 0x02001000 @ EWRAM+0x1000\n"
        ".L080DE188:\n"
        "    ldr r0, .L080DE190\n"
        "    ldr r1, .L080DE194\n"
        "    b .L080DE19C\n"
        "    .byte 0x00, 0x00\n"
        ".L080DE190: .4byte gUnknown_085887D4\n"
        ".L080DE194: .4byte 0x02002000 @ EWRAM+0x2000\n"
        ".L080DE198:\n"
        "    ldr r0, .L080DE1AC\n"
        "    ldr r1, .L080DE1B0\n"
        ".L080DE19C:\n"
        "    bl LZ77UnCompWram\n"
        ".L080DE1A0:\n"
        "    ldr r1, .L080DE1B4\n"
        "    ldrh r0, [r1, #0x36]\n"
        "    adds r0, #1\n"
        "    strh r0, [r1, #0x36]\n"
        "    movs r0, #0\n"
        "    b .L080DE1E6\n"
        ".L080DE1AC: .4byte gUnknown_08588FA4\n"
        ".L080DE1B0: .4byte 0x02003000 @ EWRAM+0x3000\n"
        ".L080DE1B4: .4byte 0x020399E0 @ EWRAM+0x399E0\n"
        ".L080DE1B8:\n"
        "    ldr r0, .L080DE1EC\n"
        "    ldr r4, .L080DE1F0\n"
        "    adds r1, r4, #0\n"
        "    bl LZ77UnCompWram\n"
        "    ldr r1, .L080DE1F4\n"
        "    ldr r0, .L080DE1F8\n"
        "    adds r4, r4, r0\n"
        "    str r4, [r1]\n"
        "    ldr r0, .L080DE1FC\n"
        "    str r0, [r1, #4]\n"
        "    ldr r0, .L080DE200\n"
        "    str r0, [r1, #8]\n"
        "    ldr r0, [r1, #8]\n"
        "    ldr r4, .L080DE204\n"
        "    ldrh r0, [r4, #0x36]\n"
        "    adds r0, #1\n"
        "    strh r0, [r4, #0x36]\n"
        "    movs r0, #1\n"
        "    bl PalFade_FadeInFromBlack\n"
        "    str r0, [r4]\n"
        ".L080DE1E4:\n"
        "    movs r0, #1\n"
        ".L080DE1E6:\n"
        "    pop {r4}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        ".L080DE1EC: .4byte gUnknown_0858979C\n"
        ".L080DE1F0: .4byte 0x02004000 @ EWRAM+0x4000\n"
        ".L080DE1F4: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080DE1F8: .4byte 0xFFFFD000\n"
        ".L080DE1FC: .4byte 0x06008000 @ VRAM+0x8000\n"
        ".L080DE200: .4byte 0x84000E00\n"
        ".L080DE204: .4byte 0x020399E0 @ EWRAM+0x399E0\n"
    );
}
#endif

// sub_080DE208 @ 0x080DE208
void sub_080DE208(void)
{
    if (sub_080DE21C())
        sub_080DE258();
}

/* 1 when the fade is over and nothing is pending; exit 1 leaves to sub_080D9608. */
// sub_080DE21C @ 0x080DE21C
u8 sub_080DE21C(void)
{
    if (*gC0d9Bg.fade != 0)
        return 0;
    switch (gC0d9Bg.exit)
    {
    case 0:
        return 1;
    case 1:
        SetMainCallback(sub_080D9608);
        break;
    }
    gC0d9Bg.exit = 0;
    return 0;
}

/* START fades out and leaves; otherwise runs the script and the rotation. */
// sub_080DE258 @ 0x080DE258
#ifdef NONMATCHING
void sub_080DE258(void)
{
    if (gKeysNew & 8)
    {
        u16 *fade;

        REG_DISPCNT &= 0xF0FF;
        fade = gC0d9Bg.fade;
        *fade = 1;
        gC0d9Bg.exit = 1;
        memset(gPaletteTarget, 0, 0x400);
        memset(gPaletteBuffer, 0, 0x400);
        Palette_MarkDirty();
    }
    else
    {
        sub_080DE2C0();
        Mini_ZoomBg2Affine();
    }
}
#else
NAKED
void sub_080DE258(void)
{
    asm_unified(
        ".L080DE258:\n"
        "    push {r4, lr}\n"
        "    ldr r0, .L080DE29C\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #8\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080DE2B0\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #0x13\n"
        "    ldrh r1, [r2]\n"
        "    ldr r0, .L080DE2A0\n"
        "    ands r0, r1\n"
        "    strh r0, [r2]\n"
        "    ldr r2, .L080DE2A4\n"
        "    ldr r1, [r2]\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    strh r0, [r2, #4]\n"
        "    ldr r0, .L080DE2A8\n"
        "    movs r4, #0x80\n"
        "    lsls r4, r4, #3\n"
        "    movs r1, #0\n"
        "    adds r2, r4, #0\n"
        "    bl memset\n"
        "    ldr r0, .L080DE2AC\n"
        "    movs r1, #0\n"
        "    adds r2, r4, #0\n"
        "    bl memset\n"
        "    bl Palette_MarkDirty\n"
        "    b .L080DE2B8\n"
        "    .byte 0x00, 0x00\n"
        ".L080DE29C: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L080DE2A0: .4byte 0x0000F0FF\n"
        ".L080DE2A4: .4byte 0x020399E0 @ EWRAM+0x399E0\n"
        ".L080DE2A8: .4byte 0x030029B0 @ IWRAM+0x29B0\n"
        ".L080DE2AC: .4byte 0x03002DB0 @ IWRAM+0x2DB0\n"
        ".L080DE2B0:\n"
        "    bl sub_080DE2C0\n"
        "    bl Mini_ZoomBg2Affine\n"
        ".L080DE2B8:\n"
        "    pop {r4}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif
