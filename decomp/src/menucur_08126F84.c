/* Menu cursors (8 slots at 0x03006480) and menu window graphics. */

#include "global.h"
#include "menucur.h"


/* DMA3 transfer, then a wait written as its own block: the separate register pointer is
   what gives the original's register allocation when the source is kept live. */
#define DmaWait3()                               {                                                    vu32 *dmaRegs = (vu32 *)(REG_BASE + 0xD4);       while (dmaRegs[2] & 0x80000000)                      ;                                        }

#define DmaSet3ThenWait(src, dest, control)      {                                                    DmaSet3(src, dest, control);                     DmaWait3();                                  }

/* Two copies from the 0x030012B4 canvas to BG VRAM. */
// sub_08126F84 @ 0x08126F84
void sub_08126F84(void)
{
    DmaSet3ThenWait(gUnk_030000B4 + 0x1200, 0x0600D800, 0x84000200);
    DmaSet3ThenWait(gUnk_030000B4 + 0x1A00, 0x060010C0, 0x84000080);
}

// sub_08126FEC @ 0x08126FEC
void sub_08126FEC(void)
{
    DmaSet3ThenWait(gUnk_030000B4 + 0x1200, 0x0600D800, 0x84000200);
    DmaSet3ThenWait(gUnk_030000B4 + 0x1A00, 0x060012C0, 0x84000020);
}

// sub_08127054 @ 0x08127054
void sub_08127054(void)
{
    DmaFill3Wait(0, 0x060012C0, 0x85000020);
}

// sub_08127090 @ 0x08127090
void sub_08127090(void)
{
    DmaFill3Wait(0, 0x060010C0, 0x85000020);
}

// sub_081270CC @ 0x081270CC
void sub_081270CC(u8 x, u8 y, u8 w, u8 h, const u16 *src)
{
    const u16 *s = src;
    u8 i, j;
    u16 *dst;

    for (i = 0; i < h; i++)
    {
        dst = &gWindowTilemapBuffer[(y + i) * 32 + x];
        for (j = 0; j < w; j++)
        {
            *dst = *s;
            s++;
            dst++;
        }
    }
}


// sub_0812712C @ 0x0812712C
void sub_0812712C(void)
{
    DmaSet3Wait(gWindowTilemapBuffer, 0x06001000, 0x84000200);
    DmaSet3Wait(gUnknown_08770C54, 0x06000000, 0x840000A0);
    DmaSet3Wait(gUnk_030000B4, 0x06006000, 0x84000800);
}

// sub_081271C0 @ 0x081271C0
void sub_081271C0(void)
{
    DmaSet3Wait(gWindowTilemapBuffer, 0x06001000, 0x84000200);
    DmaFill3Wait(0, 0x06000000, 0x850000A0);
    DmaSet3Wait(gUnk_030000B4, 0x06006000, 0x84000800);
}
