/* Message window helpers: list paging flags and saving/restoring the glyph queue. */

#include "global.h"
#include "bmenu2.h"

#define LIST_TOP (*(s16 *)&gUnk_03006940)

/* Sets 0x03006848 (more entries above) and 0x03006680 (more below) for the item list
   0x0203DB88 at offset 0x03006940, by list layout 0x03006844. */
// sub_0812F010 @ 0x0812F010
void sub_0812F010(void)
{
    s16 mode = gUnk_03006844;

    if (mode == 0)
    {
        if (LIST_TOP == 0)
            gUnk_03006848 = 0;
        else
            gUnk_03006848 = 1;
        if (gUnk_0203DB88[LIST_TOP + 4] != 0xFFFF)
        {
            gUnk_03006680 = 1;
            return;
        }
    }
    else if (mode == 1 || mode == 4)
    {
        if (LIST_TOP == 0)
            gUnk_03006848 = 0;
        else
            gUnk_03006848 = 1;
        if (gUnk_0203DB88[LIST_TOP + 3] != 0xFFFF)
        {
            gUnk_03006680 = 1;
            return;
        }
    }
    else if (mode == 2)
    {
        if (LIST_TOP <= 1)
            gUnk_03006848 = 0;
        else
            gUnk_03006848 = 1;
        if (LIST_TOP + 8 <= 15 && gUnk_0203DB88[LIST_TOP + 8] != 0xFFFF)
        {
            gUnk_03006680 = 1;
            return;
        }
    }
    else
    {
        if (LIST_TOP <= 1)
            gUnk_03006848 = 0;
        else
            gUnk_03006848 = 1;
        if (LIST_TOP + 6 <= 15 && gUnk_0203DB88[LIST_TOP + 6] != 0xFFFF)
        {
            gUnk_03006680 = 1;
            return;
        }
    }
    gUnk_03006680 = 0;
}

// sub_0812F178 @ 0x0812F178
void sub_0812F178(struct Task *task)
{
    task->result = 0;
    gUnk_0300696C = 0;
}

// sub_0812F188 @ 0x0812F188
u16 sub_0812F188(u16 i)
{
    return gUnknown_0878FC6A[i];
}

/* Saves the glyphs of the queue (at most 16) to 0x03006870, ended by 0x301. */
// MsgWindow_SaveGlyphs @ 0x0812F198
void MsgWindow_SaveGlyphs(void)
{
    u16 i;

    for (i = 0; i < gMsgGlyphCount && i < 16; i++)
        gUnk_03006870[i] = gMsgGlyphQueue[i * 4];
    gUnk_03006870[i] = 0x301;
}

/* Queues the saved glyphs again at the current text position. */
// MsgWindow_RestoreGlyphs @ 0x0812F1E4
void MsgWindow_RestoreGlyphs(void)
{
    u16 i;
    u16 k;
    u16 g;

    for (i = 0; i < 16; i++)
    {
        k = gMsgGlyphCount * 4;
        g = gUnk_03006870[i];
        if (g == 0x301)
            break;
        gMsgGlyphQueue[k++] = g;
        gMsgGlyphQueue[k++] = gTextColumn * 13 + 0x11;
        gMsgGlyphQueue[k++] = gTextLine * 13 + gMsgTextTop;
        gMsgGlyphQueue[k++] = 0;
        if (gMsgGlyphCount <= 0x3E)
            gMsgGlyphCount++;
        gTextColumn++;
    }
}
