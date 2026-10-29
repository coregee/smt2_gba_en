#include "global.h"
#include "options.h"

extern u8 gUnk_030062F4, gUnk_03006370;
extern u16 gUnk_03006364;

/* The test of sub_080DF6FC, written out in each state: ok[i] is 1 when player i's last
   packet (16-byte slots at gUnk_03006340) carries header hdr. */
#define LINK_CHECK_ALL(ok, i, h)                                 \
    for (i = 0; i < 4; i++)                                      \
    {                                                            \
        if (i < 2)                                               \
        {                                                        \
            if (gUnk_03006340[i].hdr != (h))                     \
                ok[i] = 0;                                       \
            else                                                 \
                ok[i] = 1;                                       \
        }                                                        \
        else                                                     \
            ok[i] = 1;                                           \
    }

/* Link connection handshake (state gUnk_030062F4): sends 0xF100, 0xF200, 0xF300 in turn,
   each once both players echo the previous one, and reaches state 5. 60 frames without
   progress restart at state 1 (at most 20 times, then 0xFF); 600 frames of serial errors
   (sub_080DFB98) also give 0xFF. Returns 1 when connected, else 0. */
// Link_Handshake @ 0x080DF4B8
u8 Link_Handshake(void)
{
    u8 ok[4];
    u8 i;
    u32 busy;

    switch (gUnk_030062F4)
    {
    case 0:
        break;
    case 1:
        gUnk_03006380[0] = 0xF100;
        gUnk_030062F4 = 2;
        break;
    case 2:
        LINK_CHECK_ALL(ok, i, 0xF100);
        if (ok[0] == 1 && ok[1] == 1)
        {
            ok[2] = 1;
            ok[3] = 1;
            gUnk_03006380[0] = 0xF200;
            gUnk_030062F4 = 3;
        }
        else
            gUnk_03006364++;
        break;
    case 3:
        LINK_CHECK_ALL(ok, i, 0xF200);
        if (ok[0] == 1 && ok[1] == 1)
        {
            ok[2] = 1;
            ok[3] = 1;
            gUnk_03006380[0] = 0xF300;
            gUnk_030062F4 = 4;
        }
        else
            gUnk_03006364++;
        break;
    case 4:
        LINK_CHECK_ALL(ok, i, 0xF300);
        if (ok[0] == 1 && ok[1] == 1)
        {
            ok[2] = 1;
            ok[3] = 1;
            gUnk_030062F4 = 5;
            gUnk_03006380[0] = 0;
        }
        else
            gUnk_03006364++;
        break;
    case 5:
        break;
    }
    if (gUnk_03006364 > 60)
    {
        if (++gUnk_03006370 > 20)
            return 0xFF;
        gUnk_030062F4 = 1;
        gUnk_03006364 = 0;
    }
    busy = sub_080DFB98() != 0;
    if (busy)
        gUnk_03006390++;
    else
        gUnk_03006390 = busy;
    if (gUnk_03006390 > 0x257)
        return 0xFF;
    if (gUnk_030062F4 != 5)
        return 0;
    return 1;
}
