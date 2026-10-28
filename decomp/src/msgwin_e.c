/* Script message window: equipment window reset. */

#include "global.h"
#include "bmenu2.h"

// sub_08131694 @ 0x08131694
void sub_08131694(void)
{
    gUnk_030068AC = 0;
    gUnk_03006848 = 0;
    gUnk_03006680 = 0;
    gUnk_03006620[32] = 0;
    gUnk_03006620[24] = 0;
    gUnk_03006620[16] = 0;
    gUnk_03006620[8] = 0;
    gUnk_03006620[0] = 0;
    gUnk_03006958 = 0;
    gMsgGlyphCount = 0;
    gTextColumn = 0;
    gTextLine = 0;
    gUnk_0203DB4A = 0;
    Font_ResetGlyphSpriteCache(0x180);
}
