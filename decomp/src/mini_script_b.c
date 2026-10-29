#include "global.h"
#include "extras.h"

struct C0d9Scroll
{
    u8 x, y;
    u16 pad;
};
extern const struct C0d9Scroll gUnknown_08586670[];
void *PalFade_FadeToBlack(u16 delay);

/* Timeline of the second mini program, like Mini_StepTimeline1: step +0x34 advances when the
   counter +0x06 runs out (8 frames) and reloads gUnk_03000031/35 and the BG0 offsets from
   gUnknown_08586670[step]; the listed steps set gUnk_03000037, 0x6E turns window 1 off,
   0x8A fades out and exits. Elsewhere bit 0 of the u16 at gUnk_03000038 follows bit 2 of the
   counter (blinking). */
// Mini_StepTimeline2 @ 0x080DEB4C
void Mini_StepTimeline2(void)
{
    switch (gC0d9Bg.unk34)
    {
    case 0:
        gUnk_03000037 = 9;
        break;
    case 0x13:
        gUnk_03000037 = 0x10;
        break;
    case 0x20:
        gUnk_03000037 = 0x17;
        break;
    case 0x2F:
        gUnk_03000037 = 0x1E;
        break;
    case 0x32:
        gUnk_03000037 = 0x2C;
        break;
    case 0x41:
        gUnk_03000037 = 0x33;
        break;
    case 0x4E:
        gUnk_03000037 = 0x3A;
        break;
    case 0x58:
        gUnk_03000037 = 0x48;
        break;
    case 0x65:
        gUnk_03000037 = 0x4F;
        break;
    case 0x6E:
        REG_DISPCNT &= 0xBFFF;
        break;
    case 0x89:
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
    case 0x8A:
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
        gUnk_03000031 = gUnknown_08586670[gC0d9Bg.unk34].x;
        gUnk_03000035 = gUnknown_08586670[gC0d9Bg.unk34].y;
        gDispRegs = -gUnknown_08586670[gC0d9Bg.unk34].x;
        gUnk_03000002 = -gUnknown_08586670[gC0d9Bg.unk34].y;
    }
}
