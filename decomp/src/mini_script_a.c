#include "global.h"
#include "extras.h"

struct C0d9Scroll
{
    u8 x, y;
    u16 pad;
};
extern const struct C0d9Scroll gUnknown_085864B0[];
void *PalFade_FadeToBlack(u16 delay);

/* Timeline of the first mini program (see Mini_StepTimeline2): step +0x34 advances when the
   counter +0x06 runs out (8 frames, longer at some steps) and reloads gUnk_03000031/35 and
   the BG0 offsets from gUnknown_085864B0[step]; the listed steps set gUnk_03000037, 0x4F
   starts a zoom (+0x28 = 2) and shows BG2, 0x50 waits for the scale +0x1E to pass 0xFF,
   0x62 slides gUnk_03000006 down, 0x63 turns window 1 off, 0x6F fades out and exits. */
// Mini_StepTimeline1 @ 0x080DE2C0
void Mini_StepTimeline1(void)
{
    switch (gC0d9Bg.unk34)
    {
    case 0:
        gUnk_03000037 = 9;
        break;
    case 11:
        gUnk_03000037 = 0x11;
        break;
    case 24:
        gUnk_03000037 = 0x1F;
        break;
    case 34:
        gUnk_03000037 = 0x27;
        break;
    case 46:
        gUnk_03000037 = 0x2E;
        break;
    case 55:
        gUnk_03000037 = 0x3C;
        break;
    case 64:
        gUnk_03000037 = 0x4A;
        break;
    case 0x4F:
        gUnk_03000037 = 0x51;
        gC0d9Bg.unk28 = 2;
        REG_DISPCNT |= 0x400;
        gC0d9Bg.unk06 = 1;
        break;
    case 0x59:
        gUnk_03000037 = 0x5C;
        break;
    case 0x63:
        REG_DISPCNT &= 0xBFFF;
        break;
    case 0x50:
        if ((u16)gC0d9Bg.unk1E > 0xFF)
            break;
        gC0d9Bg.unk06 = 0x50;
        return;
    case 0x51:
    case 0x5A:
        if (gC0d9Bg.unk22 == 1)
        {
            gC0d9Bg.unk22 = 0;
            gC0d9Bg.unk06 = 0x28;
        }
        if (((s16)gC0d9Bg.unk06 >> 2) & 1)
            *(u16 *)&gUnk_03000038 |= 1;
        else
            *(u16 *)&gUnk_03000038 &= 0xFFFE;
        break;
    case 0x6E:
        if (gC0d9Bg.unk22 == 1)
        {
            gC0d9Bg.unk22 = 0;
            gC0d9Bg.unk06 = 0x78;
        }
        if (((s16)gC0d9Bg.unk06 >> 2) & 1)
            *(u16 *)&gUnk_03000038 |= 1;
        else
            *(u16 *)&gUnk_03000038 &= 0xFFFE;
        break;
    case 0x64:
        if (gC0d9Bg.unk22 == 1)
        {
            gC0d9Bg.unk22 = 0;
            gC0d9Bg.unk06 = 0x50;
        }
        break;
    case 0x62:
        if (gUnk_03000006 == 0)
        {
            gUnk_03000037 = 0x9F;
            gUnk_03000035 = 0x9F;
            gUnk_03000002 = 0xFF61;
        }
        if (gUnk_03000006 > 0x9F)
            break;
        gUnk_03000006 += 0x14;
        if (gUnk_03000006 > 0x50)
            gUnk_03000037 -= 0x14;
        return;
    case 0x6F:
        gC0d9Bg.fade = PalFade_FadeToBlack(1);
        gC0d9Bg.exit = 1;
        return;
    default:
        if (((s16)gC0d9Bg.unk06 >> 2) & 1)
            *(u16 *)&gUnk_03000038 |= 1;
        else
            *(u16 *)&gUnk_03000038 &= 0xFFFE;
        break;
    }
    if (--gC0d9Bg.unk06 == 0)
    {
        gC0d9Bg.unk06 = 8;
        gC0d9Bg.unk22 = 1;
        gC0d9Bg.unk34++;
        gUnk_03000031 = gUnknown_085864B0[gC0d9Bg.unk34].x;
        gUnk_03000035 = gUnknown_085864B0[gC0d9Bg.unk34].y;
        gDispRegs = -gUnknown_085864B0[gC0d9Bg.unk34].x;
        gUnk_03000002 = -gUnknown_085864B0[gC0d9Bg.unk34].y;
    }
}
