/* Script message window: member selection and item count windows (wait states of the
   script VM). */

#include "global.h"
#include "bmenu2.h"

// sub_08130158 @ 0x08130158
void sub_08130158(void)
{
    gUnk_03006958 = 0;
    gUnk_03006848 = 0;
    gUnk_03006680 = 0;
    gUnk_03006620[0] = 0;
    gUnk_03006620[8] = 0;
    gUnk_03006620[16] = 0;
}

/* Counts the used party slots 0-2 into 0x03006688. */
// sub_08130184 @ 0x08130184
void sub_08130184(struct Task *task)
{
    task->result = 0;
    gUnk_0300696C = 0;
    gUnk_03006688 = 0;
    gUnk_03006940 = 0;
    if (Combatant_IsUsed(0))
        gUnk_03006688++;
    if (Combatant_IsUsed(1))
        gUnk_03006688++;
    if (Combatant_IsUsed(2))
        gUnk_03006688++;
}

/* Member selection: up/down moves, A picks 0x030069D8[cursor] (refused when its
   flags & 0xF0), B cancels. */
// sub_081301D8 @ 0x081301D8
void sub_081301D8(struct Task *task)
{
    gUnk_0300689C = gUnknown_0878FCC4[gUnk_0300696C * 2];
    gUnk_0300695C = gUnknown_0878FCC4[gUnk_0300696C * 2 + 1];
    gUnk_030066A0 = 0x10;
    gUnk_03006958 = 1;
    if (gRepeatedKeys & 0x40)
    {
        if (gUnk_0300696C == 0)
            return;
        gUnk_0300696C--;
        Sound_Play(0x64);
    }
    else if (gRepeatedKeys & 0x80)
    {
        if (gUnk_0300696C == gUnk_03006688 - 1)
            return;
        gUnk_0300696C++;
        Sound_Play(0x64);
    }
    else if (gNewKeys & 1)
    {
        if (gUnk_030069D8[gUnk_0300696C] & 0xF0)
        {
            Sound_Play(0x68);
            return;
        }
        task->result = 1;
        gScriptWaitState = 0x21;
        gUnk_03006850 = gUnk_03006898 = gUnk_030069D8[gUnk_0300696C];
        Sound_Play(0x65);
    }
    else if (gNewKeys & 2)
    {
        task->result = 1;
        gScriptWaitState = 0x20;
        gUnk_0300699C = 0;
        Sound_Play(0x66);
    }
}

// sub_08130300 @ 0x08130300
void sub_08130300(void)
{
    gUnk_03006958 = 0;
    gMsgGlyphCount = 0;
    gTextColumn = 0;
    gTextLine = 0;
    gUnk_0203DB4A = 0;
    Font_ResetGlyphSpriteCache(0x180);
    gUnk_030069D0 = 0;
}

// sub_08130344 @ 0x08130344
void sub_08130344(struct Task *task)
{
    task->result = 0;
    gUnk_0300696C = 0;
    gUnk_03006688 = 2;
    gUnk_03006940 = 0;
}

/* Old-style definition: callers pass `who` unnarrowed. The signed stat byte of member `who` that item `item` (0x9D-0xA5) raises. */
// sub_08130364 @ 0x08130364
u16 sub_08130364(who, item)
    s16 who;
    u16 item;
{
    s8 *stats = (s8 *)Battle_GetCombatant(who + 0x8000) + 0x38;

    switch (item)
    {
    case 0x9D:
    case 0xA3:
        return stats[0];
    case 0x9E:
    case 0xA4:
        return stats[1];
    case 0x9F:
    case 0xA5:
        return stats[2];
    case 0xA0:
        return stats[3];
    case 0xA1:
        return stats[4];
    case 0xA2:
        return stats[5];
    }
    return 0;
}

// sub_081303E8 @ 0x081303E8
void sub_081303E8(struct Task *task)
{
    gUnk_0300689C = gUnknown_0878FCC4[gUnk_0300696C * 2];
    gUnk_0300695C = gUnknown_0878FCC4[gUnk_0300696C * 2 + 1];
    gUnk_030066A0 = 0x10;
    gUnk_03006958 = 1;
    if (gRepeatedKeys & 0xC0)
    {
        if (gUnk_0300696C == 0)
            gUnk_0300696C = 1;
        else
            gUnk_0300696C = 0;
        Sound_Play(0x64);
    }
    else if (gNewKeys & 1)
    {
        gMsgGlyphCount = 0;
        gTextColumn = 0;
        gTextLine = 0;
        gUnk_0203DB4A = 0;
        Font_ResetGlyphSpriteCache(0x180);
        if (gUnk_0300696C != 0)
        {
            if (Combatant_IsUsed(1))
                gUnk_03006898 = 1;
            else
                gUnk_03006898 = 2;
        }
        else
            gUnk_03006898 = 0;
        task->result = 1;
        gScriptWaitState = 0;
        if (sub_08130364(gUnk_03006898, gUnk_030065E0))
        {
            Sound_Play(0x68);
            gScriptJumpTarget = gUnk_0203DAC8[1];
        }
        else
            Sound_Play(0x65);
    }
    else if (gNewKeys & 2)
    {
        task->result = 1;
        gScriptWaitState = 0;
        gScriptJumpTarget = gUnk_0203DAC8[0];
        Sound_Play(0x66);
    }
}

// sub_08130544 @ 0x08130544
void sub_08130544(void)
{
    gUnk_03006958 = 0;
}

// sub_08130550 @ 0x08130550
void sub_08130550(struct Task *task)
{
    task->result = 0;
    gUnk_0300696C = 0;
    gUnk_03006940 = 0;
    gUnk_030065E4 = 0;
    gUnk_030068D4 = 10;
}

/* Writes the two-digit count of `item` (owned plus Party_CountEquipped) into glyphs 13-14 of the
   queue. Counts of 100 or more are not handled (first digit index 10+). */
// MsgWindow_DrawItemCount @ 0x08130578
void MsgWindow_DrawItemCount(u16 item)
{
    u16 n = Inventory_GetCount(item) + Party_CountEquipped(0xFF, item);

    gMsgGlyphQueue[13 * 4] = gScriptDigitGlyphs[(u16)(n / 10)];
    gMsgGlyphQueue[14 * 4] = gScriptDigitGlyphs[(u16)(n % 10)];
}

/* Shows (or, with 0x030065E4 clear, restores) the first 15 glyphs of the queue as a fixed
   13-glyph label followed by the count of `item`. The label's glyph codes are in this code. */
// sub_081305D8 @ 0x081305D8
void sub_081305D8(u16 item)
{
    u16 i;

    if (gUnk_030065E4 == 0)
    {
        for (i = 0; i < 15; i++)
            gMsgGlyphQueue[i * 4] = gUnk_03006820[i];
    }
    else
    {
        for (i = 0; i < 15; i++)
            gUnk_03006820[i] = gMsgGlyphQueue[i * 4];
        gMsgGlyphQueue[0 * 4] = 0xBD9;
        gMsgGlyphQueue[1 * 4] = 0xC80;
        gMsgGlyphQueue[2 * 4] = 0xCD3;
        gMsgGlyphQueue[3 * 4] = 0x149;
        gMsgGlyphQueue[4 * 4] = 0x17B;
        gMsgGlyphQueue[5 * 4] = 0x17D;
        gMsgGlyphQueue[6 * 4] = 0x19F;
        gMsgGlyphQueue[7 * 4] = 0x1BA;
        gMsgGlyphQueue[8 * 4] = 0x149;
        gMsgGlyphQueue[9 * 4] = 0xAA0;
        gMsgGlyphQueue[10 * 4] = 0x9F6;
        gMsgGlyphQueue[11 * 4] = 0xB67;
        gMsgGlyphQueue[12 * 4] = 0x3F;
        MsgWindow_DrawItemCount(item);
    }
}
