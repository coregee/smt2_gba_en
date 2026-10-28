/* Script message window: list window reset. */

#include "global.h"
#include "bmenu2.h"

// sub_08131364 @ 0x08131364
void sub_08131364(void)
{
    gUnk_03006848 = 0;
    gUnk_03006680 = 0;
    gUnk_03006678 = gUnk_03006620[0] = gUnk_03006620[8] = gUnk_03006620[16] = gUnk_03006620[24]
        = gUnk_03006620[32] = 0;
    gUnk_03006958 = 0;
    if ((s16)gUnk_03006844 != 1)
        sub_080D34F0(gUnk_030068A4);
    gMsgGlyphCount = 0;
    gTextColumn = 0;
    gTextLine = 0;
    gUnk_0203DB4A = 0;
    Font_ResetGlyphSpriteCache(0x180);
}

// sub_081313E8 @ 0x081313E8
void sub_081313E8(struct Task *task)
{
    task->result = 0;
    gUnk_0300696C = 0;
    gUnk_03006940 = 0;
}
