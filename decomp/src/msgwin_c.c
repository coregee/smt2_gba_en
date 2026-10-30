/* Script message window: list windows (state reset and the entry table lookup). */

#include "global.h"
#include "bmenu2.h"

// sub_08130C38 @ 0x08130C38
void sub_08130C38(void)
{
    gUnk_03006848 = 0;
    gUnk_03006680 = 0;
}

// sub_08130C4C @ 0x08130C4C
void sub_08130C4C(struct Task *task)
{
    task->result = 0;
    gUnk_0300696C = 0;
    gUnk_03006940 = 0;
    gUnk_030068AC = 0;
}

/* Fills the five entries at 0x03006980: from table 0x0878FDEC (row = list top + cursor)
   when 0x030068D8 is 0xFF, else one entry looked up in the (limit, value) pairs at
   0x0878FDCC. */
// sub_08130C6C @ 0x08130C6C
void sub_08130C6C(void)
{
    u16 i;
    u16 n;
    u16 v;

    gUnk_03006980[0] = 0xFFFF;
    gUnk_03006980[1] = -1;
    gUnk_03006980[2] = -1;
    gUnk_03006980[3] = -1;
    gUnk_03006980[4] = -1;
    v = gUnk_030068D8;
    if (v == 0xFF)
    {
        n = gUnk_0300696C + gUnk_03006940;
        for (i = 0; i < 5; i++)
            gUnk_03006980[i] = gUnknown_0878FDEC[n * 5 + i];
    }
    else
    {
        s32 t = v - 0x120;

        t += (u16)gUnk_0300696C;
        n = gUnk_03006940 + t;
        i = 0;
        while (n >= gUnknown_0878FDCC[i])
            i += 2;
        gUnk_03006980[0] = gUnknown_0878FDCC[i + 1];
    }
}
