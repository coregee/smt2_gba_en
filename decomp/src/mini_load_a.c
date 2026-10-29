#include "global.h"
#include "extras.h"

extern const u8 gUnknown_0858689C[];

/* Loads the mini program's graphics one LZ77 block per frame (step +0x36); returns 0 while
   loading, 1 once the last block is uploaded and the fade-in started. */
// Mini_LoadGraphicsStep @ 0x080DE9A8
u8 Mini_LoadGraphicsStep(void)
{
    u8 *buf;

    switch (gC0d9Bg.unk36)
    {
    case 0:
        LZ77UnCompWram(gUnknown_0858689C, (void *)0x02001000);
        DmaSet3((void *)0x02001000, VRAM + 0x4000, 0x84000400);
        gC0d9Bg.unk36++;
        return 0;
    case 1:
        LZ77UnCompWram(gUnknown_08588050, (void *)0x02001000);
        gC0d9Bg.unk36++;
        return 0;
    case 2:
        LZ77UnCompWram(gUnknown_085887D4, (void *)0x02002000);
        gC0d9Bg.unk36++;
        return 0;
    case 3:
        LZ77UnCompWram(gUnknown_08588FA4, (void *)0x02003000);
        gC0d9Bg.unk36++;
        return 0;
    case 4:
        LZ77UnCompWram(gUnknown_0858979C, buf = (u8 *)0x02004000);
        DmaSet3(buf - 0x3000, VRAM + 0x8000, 0x84000E00);
        gC0d9Bg.unk36++;
        gC0d9Bg.fade = PalFade_FadeInFromBlack(1);
    default:
        return 1;
    }
}
