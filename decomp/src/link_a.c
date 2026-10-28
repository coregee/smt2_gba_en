#include "global.h"
#include "extras.h"

// sub_080DECEC @ 0x080DECEC
void sub_080DECEC(void)
{
    VBlankTask_AddCounted(sub_080DEDD8, 1);
    gC0d9Bg.unk08 = FixedMul8(gSineTable[gC0d9Bg.unk1C + 0x40], FixedInverse8(gC0d9Bg.unk1E));
    gC0d9Bg.unk0A = FixedMul8(gSineTable[gC0d9Bg.unk1C], FixedInverse8(gC0d9Bg.unk1E));
    gC0d9Bg.unk0C = FixedMul8(-gSineTable[gC0d9Bg.unk1C], FixedInverse8(gC0d9Bg.unk20));
    gC0d9Bg.unk0E = FixedMul8(gSineTable[gC0d9Bg.unk1C + 0x40], FixedInverse8(gC0d9Bg.unk20));
    gC0d9Bg.unk10 = ((gC0d9Bg.unk24 - gC0d9Bg.unk18) << 8) - gC0d9Bg.unk08 * gC0d9Bg.unk24 - gC0d9Bg.unk0A * gC0d9Bg.unk26;
    gC0d9Bg.unk14 = ((gC0d9Bg.unk26 - gC0d9Bg.unk1A) << 8) - gC0d9Bg.unk0C * gC0d9Bg.unk24 - gC0d9Bg.unk0E * gC0d9Bg.unk26;
}

/* VBlank: BG2 affine registers from gC0d9Bg. */
// sub_080DEDD8 @ 0x080DEDD8
#ifdef NONMATCHING
void sub_080DEDD8(void)
{
    vu16 *reg = (vu16 *)(REG_BASE + 0x20);

    *reg++ = gC0d9Bg.unk08;
    *reg++ = gC0d9Bg.unk0A;
    *reg++ = gC0d9Bg.unk0C;
    *reg++ = gC0d9Bg.unk0E;
    *reg++ = gC0d9Bg.unk10;
    *reg++ = (gC0d9Bg.unk10 & 0x0FFF0000) >> 16;
    *reg++ = gC0d9Bg.unk14;
    *reg++ = (gC0d9Bg.unk14 & 0x0FFF0000) >> 16;
}
#else
NAKED
void sub_080DEDD8(void)
{
    asm_unified(
        "    ldr r1, .L080DEE14\n"
        "    ldr r2, .L080DEE18\n"
        "    ldrh r0, [r2, #8]\n"
        "    strh r0, [r1]\n"
        "    adds r1, #2\n"
        "    ldrh r0, [r2, #0xa]\n"
        "    strh r0, [r1]\n"
        "    adds r1, #2\n"
        "    ldrh r0, [r2, #0xc]\n"
        "    strh r0, [r1]\n"
        "    adds r1, #2\n"
        "    ldrh r0, [r2, #0xe]\n"
        "    strh r0, [r1]\n"
        "    adds r1, #2\n"
        "    ldr r0, [r2, #0x10]\n"
        "    strh r0, [r1]\n"
        "    adds r1, #2\n"
        "    ldr r3, .L080DEE1C\n"
        "    ands r0, r3\n"
        "    asrs r0, r0, #0x10\n"
        "    strh r0, [r1]\n"
        "    adds r1, #2\n"
        "    ldr r0, [r2, #0x14]\n"
        "    strh r0, [r1]\n"
        "    adds r1, #2\n"
        "    ands r0, r3\n"
        "    asrs r0, r0, #0x10\n"
        "    strh r0, [r1]\n"
        "    bx lr\n"
        "    .byte 0x00, 0x00\n"
        ".L080DEE14: .4byte 0x04000020 @ REG_BG2PA\n"
        ".L080DEE18: .4byte 0x020399E0 @ EWRAM+0x399E0\n"
        ".L080DEE1C: .4byte 0x0FFF0000\n"
    );
}
#endif

/* Link cable: serial setup in normal mode and copies of the serial/timer interrupt
   handlers into IWRAM. */
// sub_080DEE20 @ 0x080DEE20
void sub_080DEE20(void)
{
    u32 zero;
    u8 *link;

    REG_IME = 0;
    REG_IE &= 0xFF3F;
    REG_IME = 1;
    REG_RCNT = 0;
    REG_SIOCNT = 0x2000;
    REG_SIOCNT |= 0x4003;
    zero = 0;
    link = gUnk_030061C0;
    CpuSet(&zero, link, 0x0500003C);
    CpuSet(arm_08032B7C, gUnk_030062B0, 0x04000010);
    CpuSet(SerialTimer3Intr, gUnk_030060A0, 0x04000048);
    *(u32 *)(link + 0x14) = 11;
    *(u32 *)(link + 0x18) = 11;
    *(u8 **)(link + 0x1C) = link + 0x30;
    *(u8 **)(link + 0x20) = link + 0x48;
    *(u8 **)(link + 0x24) = link + 0x60;
    *(u8 **)(link + 0x28) = link + 0x90;
    *(u8 **)(link + 0x2C) = link + 0xC0;
    REG_IME = 0;
    REG_IE |= 0x80;
    REG_IME = 1;
}

// sub_080DEEE8 @ 0x080DEEE8
void sub_080DEEE8(void)
{
    if (gUnk_030061C0[0] != 0)
        gUnk_030061C0[6] = 1;
}

// sub_080DEF00 @ 0x080DEF00
void sub_080DEF00(void)
{
    REG_IME = 0;
    REG_IE &= 0xFF3F;
    REG_IME = 1;
    REG_SIOCNT = 0x2003;
    *(vu32 *)(REG_BASE + 0x10C) = 0xABFB;
    REG_IF = 0xC0;
    gUnk_030061C0[6] = 0;
}
