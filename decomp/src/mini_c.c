#include "global.h"
#include "extras.h"

/* Zooms by unk28 per frame up to 0x100 and recomputes the BG2 rotation/scaling. */
// Mini_ZoomBg2Affine @ 0x080DE680
void Mini_ZoomBg2Affine(void)
{
    struct C0d9Bg *bg;

    VBlankTask_AddCounted(Mini_UploadBg2Affine, 1);
    bg = &gC0d9Bg;
    bg->unk1E += bg->unk28;
    bg->unk20 += bg->unk28;
    bg->unk08 = FixedMul8(gSineTable[bg->unk1C + 0x40], FixedInverse8(bg->unk1E));
    bg->unk0A = FixedMul8(gSineTable[bg->unk1C], FixedInverse8(bg->unk1E));
    bg->unk0C = FixedMul8(-gSineTable[bg->unk1C], FixedInverse8(bg->unk20));
    bg->unk0E = FixedMul8(gSineTable[bg->unk1C + 0x40], FixedInverse8(bg->unk20));
    bg->unk10 = ((bg->unk24 - bg->unk18) << 8) - bg->unk08 * bg->unk24 - bg->unk0A * bg->unk26;
    bg->unk14 = ((bg->unk26 - bg->unk1A) << 8) - bg->unk0C * bg->unk24 - bg->unk0E * bg->unk26;
    if ((u16)bg->unk1E > 0x100)
    {
        bg->unk28 = 0;
        bg->unk1E = 0x100;
        bg->unk20 = 0x100;
    }
}

/* Second mini program (entered after saving at the end, sub_080DA190): same setup as
   sub_080DDEDC with BG1 not wrapping. */
// sub_080DE78C @ 0x080DE78C
void sub_080DE78C(void)
{
    gUnk_0200AB04 = 1;
    REG_DISPCNT = 0x6701;
    REG_BG0CNT = 4;
    REG_BG1CNT = 0x0205;
    REG_BG2CNT = 0x048A;
    *(u16 *)&gUnk_03000030 = 0xF0;
    *(u16 *)&gUnk_03000032 = 0xF0;
    *(u16 *)&gUnk_03000034 = 0xA0;
    *(u16 *)&gUnk_03000036 = 0xA0;
    *(u16 *)&gUnk_03000038 = 0x404;
    *(u16 *)&gUnk_0300003A = 0x1F1F;
    DmaFill16_3(0, VRAM, 0x81002000);
    REG_IE = 0x2003;
    REG_DISPSTAT = 0x18;
    REG_IME = 1;
    Task_ClearAll();
    sub_080DE85C();
    SetMainCallback(sub_080DE98C);
}

// sub_080DE85C @ 0x080DE85C
void sub_080DE85C(void)
{
    struct C0d9Bg *bg;
    u8 *buf;

    gDispRegs = 0;
    gUnk_03000004 = 0;
    gUnk_03000008 = 0;
    gUnk_0300000C = 0;
    gUnk_03000002 = 0;
    gUnk_03000006 = 0;
    gUnk_0300000A = 0;
    gUnk_0300000E = 0;
    memset(gPaletteTarget, 0, 0x400);
    sub_08153378(gUnknown_08589C3C, 0, 0x40);
    buf = gUnk_02030C74;
    memset(buf, 0, 0x5400);
    memcpy(buf, gUnknown_0858712C, 4);
    DmaSet3(buf, VRAM, 0x84000400);
    memcpy(buf, gUnknown_08586C2C, 0x500);
    DmaSet3(buf, VRAM + 0x1000, 0x84000400);
    memcpy(buf, gUnknown_08589B3C, 0x100);
    DmaSet3(buf, VRAM + 0x2000, 0x84000400);
    bg = &gC0d9Bg;
    bg->unk06 = 4;
    bg->unk34 = 0;
    bg->unk22 = 0;
    bg->unk10 = 0;
    bg->unk14 = 0;
    bg->unk08 = 0x100;
    bg->unk0A = 0;
    bg->unk0C = 0;
    bg->unk0E = 0x100;
    bg->unk18 = 0x38;
    bg->unk1A = 8;
    bg->unk1E = 0x100;
    bg->unk20 = 0x100;
    bg->unk1C = 0;
    bg->unk24 = 0x78;
    bg->unk26 = 0x48;
    bg->unk28 = 0;
    bg->unk2A = 0x80;
    bg->unk2C = 0x200;
    bg->unk30 = 0x200;
    bg->unk36 = 0;
}

// sub_080DE98C @ 0x080DE98C
void sub_080DE98C(void)
{
    if (sub_080DE9A8())
    {
        sub_080DEA9C();
        Task_RunAll();
        PlayTime_Tick();
    }
}
