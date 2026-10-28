/* Menu cursors (8 slots at 0x03006480) and menu window graphics. */

#include "global.h"
#include "menucur.h"

// sub_08127258 @ 0x08127258
void sub_08127258(void)
{
    sub_081270CC(1, 0, 0x1C, 0xA, gUnknown_08770A24);
    sub_080E5668(sub_0812712C);
}

// sub_08127280 @ 0x08127280
void sub_08127280(void)
{
    u32 zero = 0;

    CpuFastSet(&zero, gWindowTilemapBuffer, 0x010000A0);
    sub_080E5668(sub_081271C0);
}

// sub_081272AC @ 0x081272AC
void sub_081272AC(void)
{
    u32 zero = 0;

    CpuFastSet(&zero, (void *)0x030000B4, 0x01000800);
}
