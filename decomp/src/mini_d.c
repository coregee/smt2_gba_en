#include "global.h"
#include "extras.h"

// sub_080DEA9C @ 0x080DEA9C
void sub_080DEA9C(void)
{
    if (sub_080DEAB0())
        sub_080DEAE4();
}

/* 1 while the fade runs or nothing is pending; exit 1 goes back to the title (sub_080D5B8C(3)). */
// sub_080DEAB0 @ 0x080DEAB0
u8 sub_080DEAB0(void)
{
    if (*gC0d9Bg.fade != 0)
        return 1;
    switch (gC0d9Bg.exit)
    {
    case 0:
        return 1;
    case 1:
        sub_080D5B8C(3);
        break;
    }
    gC0d9Bg.exit = 0;
    return 0;
}

// sub_080DEAE4 @ 0x080DEAE4
#ifdef NONMATCHING
void sub_080DEAE4(void)
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
        Mini_StepTimeline2();
        Mini_UpdateBg2Affine();
    }
}
#else
NAKED
void sub_080DEAE4(void)
{
    asm_unified(
        ".L080DEAE4:\n"
        "    push {r4, lr}\n"
        "    ldr r0, .L080DEB28\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #8\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080DEB3C\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #0x13\n"
        "    ldrh r1, [r2]\n"
        "    ldr r0, .L080DEB2C\n"
        "    ands r0, r1\n"
        "    strh r0, [r2]\n"
        "    ldr r2, .L080DEB30\n"
        "    ldr r1, [r2]\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    strh r0, [r2, #4]\n"
        "    ldr r0, .L080DEB34\n"
        "    movs r4, #0x80\n"
        "    lsls r4, r4, #3\n"
        "    movs r1, #0\n"
        "    adds r2, r4, #0\n"
        "    bl memset\n"
        "    ldr r0, .L080DEB38\n"
        "    movs r1, #0\n"
        "    adds r2, r4, #0\n"
        "    bl memset\n"
        "    bl Palette_MarkDirty\n"
        "    b .L080DEB44\n"
        "    .byte 0x00, 0x00\n"
        ".L080DEB28: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L080DEB2C: .4byte 0x0000F0FF\n"
        ".L080DEB30: .4byte 0x020399E0 @ EWRAM+0x399E0\n"
        ".L080DEB34: .4byte 0x030029B0 @ IWRAM+0x29B0\n"
        ".L080DEB38: .4byte 0x03002DB0 @ IWRAM+0x2DB0\n"
        ".L080DEB3C:\n"
        "    bl Mini_StepTimeline2\n"
        "    bl Mini_UpdateBg2Affine\n"
        ".L080DEB44:\n"
        "    pop {r4}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif
