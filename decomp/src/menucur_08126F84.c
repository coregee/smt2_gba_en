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
#ifdef NONMATCHING
void sub_081270CC(u8 x, u8 y, u8 w, u8 h, const u16 *src)
{
    u8 i, j;
    u16 *dst;

    for (i = 0; i < h; i++)
    {
        dst = &gWindowTilemapBuffer[(y + i) * 32 + x];
        for (j = 0; j < w; j++)
        {
            *dst = *src;
            src++;
            dst++;
        }
    }
}
#else
NAKED
void sub_081270CC(u8 x, u8 y, u8 w, u8 h, const u16 *src)
{
    asm_unified(
        ".L081270CC:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    mov ip, r0\n"
        "    lsls r1, r1, #0x18\n"
        "    lsrs r7, r1, #0x18\n"
        "    lsls r2, r2, #0x18\n"
        "    lsrs r5, r2, #0x18\n"
        "    lsls r3, r3, #0x18\n"
        "    lsrs r6, r3, #0x18\n"
        "    ldr r3, [sp, #0x18]\n"
        "    movs r4, #0\n"
        "    cmp r4, r6\n"
        "    bhs .L0812711E\n"
        "    ldr r0, .L08127128\n"
        "    mov r8, r0\n"
        ".L081270F0:\n"
        "    adds r0, r7, r4\n"
        "    lsls r0, r0, #5\n"
        "    add r0, ip\n"
        "    lsls r0, r0, #1\n"
        "    mov r2, r8\n"
        "    adds r1, r0, r2\n"
        "    movs r2, #0\n"
        "    adds r4, #1\n"
        "    cmp r2, r5\n"
        "    bhs .L08127116\n"
        ".L08127104:\n"
        "    ldrh r0, [r3]\n"
        "    strh r0, [r1]\n"
        "    adds r3, #2\n"
        "    adds r1, #2\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r2, r0, #0x18\n"
        "    cmp r2, r5\n"
        "    blo .L08127104\n"
        ".L08127116:\n"
        "    lsls r0, r4, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    cmp r4, r6\n"
        "    blo .L081270F0\n"
        ".L0812711E:\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L08127128: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
    );
}
#endif


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
