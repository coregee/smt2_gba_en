/* Casino prize exchange list (0x0813914C-0x0813950F). */

#include "global.h"
#include "scriptops2.h"

/* Draws up to 3 (4 with no scroll arrow) rows of the prize list starting at row `first`:
   the prize name (8 glyphs, copied into gScriptSubstBuf) at x 0x1A and the coin price
   right-aligned in 8 digit cells at x 0x8D, followed by glyph 0xFC8.
   gUnknown_0878FEA8 holds one 16-halfword record per prize set: [0] = count, then
   (item id, price) pairs; a price of 0xFFFF is shown as 100000. */
// CasinoPrize_DrawList @ 0x0813914C
/* QUEUE_GLYPH with the count and index in function-scope variables (c, k): the block-scoped
   version lets combine fold the index narrowing, unlike the original. */
#define QUEUE_GLYPH_CK(glyph, x, y)                 \
{                                                   \
    c = gMsgGlyphCount;                             \
    k = c * 4;                                      \
    gMsgGlyphQueue[k++] = (glyph);                  \
    gMsgGlyphQueue[k++] = (x);                      \
    gMsgGlyphQueue[k++] = (y);                      \
    gMsgGlyphQueue[k] = 0;                          \
    gMsgGlyphCount = c + 1;                         \
    if (gMsgGlyphCount > 0x3F)                      \
        gMsgGlyphCount = 0x3F;                      \
}
void CasinoPrize_DrawList(u16 first)
{
    u16 digits[8];
    u16 out[8];
    u16 set;
    s32 rows;
    u16 i, j, n;
    u16 c, k;
    u32 id;
    u8 *rec;
    u16 *name;
    u32 price;
    s16 d;
    s32 row;

    set = CasinoPrize_GetSet();
    gMsgGlyphCount = 0;
    gTextColumn = 0;
    gTextLine = 0;
    gUnk_0203DB4A = 0;
    Font_ResetGlyphSpriteCache(0x180);
    if (gUnk_03006844 == 1)
        MsgWindow_RestoreGlyphs();
    if (first == 0)
    {
        gUnk_03006848 = first;
        gUnk_03006680 = 1;
    }
    else if (first == gUnknown_0878FEA8[set][0] - (3 - gUnk_03006844))
    {
        gUnk_03006848 = 1;
        gUnk_03006680 = 0;
    }
    else
    {
        gUnk_03006848 = 1;
        gUnk_03006680 = 1;
    }
    if (gUnk_03006844 == 0)
        rows = 4;
    else
        rows = 3;
    for (i = first; i < first + rows && (id = gUnknown_0878FEA8[set][i * 2 + 1]) != 0xFFFF; i++)
    {
        if (id >= 0xD0)
            name = (u16 *)(Action_GetRecord(id) + 0xC);
        else
        {
            if (id >= 0x80)
                rec = Equipment_GetRecord36_MidRange(id);
            else
                rec = Item_GetRecord(id);
            name = (u16 *)(rec + 0x14);
        }
        for (j = 0; j < 16; j++)
            gScriptSubstBuf[j] = 0;
        for (j = 0; j < 8; j++)
            gScriptSubstBuf[j] = *name++;
        MsgGlyphQueue_PushSubstClamped(0x1A, gUnknown_08790390[gUnk_03006844 + (i - first)], 0, 8);

        {
            /* compared as a u16 before widening: the 0xFFFF is loaded before the ldrh */
            u16 v = gUnknown_0878FEA8[set][i * 2 + 2];

            if (v == 0xFFFF)
                price = 100000;
            else
                price = v;
        }
        for (j = 0; j < 8; j++)
            digits[j] |= 0xFFFF;
        for (j = 0; j < 8 && price != 0; j++)
        {
            digits[j] = gScriptDigitGlyphs[price % 10];
            price /= 10;
        }
        for (n = 0, d = 7; d >= 0; d--)
        {
            out[n] = digits[d];
            n++;
        }

        n = 0;
        for (j = 0; j < 8; j++)
        {
            if (out[j] != 0xFFFF)
            {
                u16 c = gMsgGlyphCount;

                k = c * 4;
                gMsgGlyphQueue[k++] = out[j];
                gMsgGlyphQueue[k++] = n * 10 + 0x8D;
                row = i - first;
                gMsgGlyphQueue[k++] = gUnknown_08790390[gUnk_03006844 + row];
                gMsgGlyphQueue[k] = 0;
                gMsgGlyphCount = c + 1;
                n++;
                if (gMsgGlyphCount > 0x3F)
                    gMsgGlyphCount = 0x3F;
            }
        }
        QUEUE_GLYPH_CK(0xFC8, n * 10 + 0x8F, gUnknown_08790390[gUnk_03006844 + (i - first)]);
    }
}

/* Prize set by story progress (flags 0xB9/0xC7/0xBC/0xC8 and item 0x157). */
// CasinoPrize_GetSet @ 0x081394B4
u16 CasinoPrize_GetSet(void)
{
    if (Flag_Test(0xB9) == 1)
    {
        if (KeyItem_IsObtainable(0x157) == 1)
            return 4;
        goto none;
    }
    if (Flag_Test(0xC7) == 1)
        return 1;
    if (Flag_Test(0xBC) == 1)
        return 2;
    if (Flag_Test(0xC8) != 1)
    {
    none:
        return 0;
    }
    return 3;
}

// ScriptOpAlt_409 @ 0x08139504
void ScriptOpAlt_409(void)
{
    gScriptPc += 6;
}

/* Operand: low byte = action (0 start, 1 open, 6 end), high byte = 0 or 1 selects the
   two screen variants (sub_080C700C/sub_080C6FF0 ...). */
// ScriptOp_40A @ 0x08139514
void ScriptOp_40A(void)
{
    u16 pc = gScriptPc++;
    u16 hi;
    u8 lo;

    hi = gScriptBase[pc];
    lo = *(u8 *)&gScriptBase[pc];
    hi >>= 8;

    if (hi == 0)
    {
        if (lo == 0)
        {
            sub_080C700C();
            gUnk_0203DB5C = 0x5A;
            gScriptWaitState = 0xF;
            gScriptYield = 1;
        }
        else if (lo == 1)
        {
            gUnk_03006954 = sub_080D3740();
            gUnk_0203DB5C = 2;
            gScriptWaitState = 0xF;
            gScriptYield = lo;
        }
        if (lo == 6)
        {
            sub_080C7648();
            gUnk_0203DB5C = 2;
            gScriptWaitState = 0xF;
            gScriptYield = 1;
        }
    }
    else
    {
        if (lo == 0)
        {
            sub_080C6FF0();
            gUnk_0203DB5C = 0x5A;
            gScriptWaitState = 0xF;
            gScriptYield = 1;
        }
        else if (lo == 1)
        {
            sub_080D3758(gUnk_03006954);
            gUnk_0203DB5C = 2;
            gScriptWaitState = 0xF;
            gScriptYield = lo;
        }
        if (lo == 6)
        {
            sub_080C762C();
            gUnk_0203DB5C = 2;
            gScriptWaitState = 0xF;
            gScriptYield = 1;
        }
    }
}

// ScriptOpAlt_40A @ 0x08139610
void ScriptOpAlt_40A(void)
{
    gScriptPc += 2;
}

// ScriptOp_40C @ 0x08139620
void ScriptOp_40C(void)
{
    u16 v = SCRIPT_READ();

    v |= 0x100;
    gScriptItemCheckId = v;
}

// ScriptOp_40B @ 0x08139650
void ScriptOp_40B(void)
{
    u16 lo = SCRIPT_READ();
    u32 t1 = SCRIPT_READ() << 16 | lo;
    u32 t2;

    lo = SCRIPT_READ();
    t2 = SCRIPT_READ();
    t2 = t2 << 16 | lo;
    if (gUnk_03006990[0] == 0xFFFF)
        gScriptJumpTarget = (u16 *)t1;
    else if (gUnk_03006990[1] == 0xFFFF)
    {
        gUnk_0203DAC8[15] = (u16 *)t2;
        gUnk_030069CC = 1;
        gScriptJumpTarget = gUnk_0203DAC8[10];
    }
}

// ScriptOpAlt_40B @ 0x081396E0
void ScriptOpAlt_40B(void)
{
    gScriptPc += 2;
}

/* Raises base stat (high byte) of member (low byte) by 1. */
// ScriptOp_40D @ 0x081396F0
void ScriptOp_40D(void)
{
    u16 who = SCRIPT_READ();
    u16 stat = who >> 8;

    who &= 0xFF;

    if (who == 1 && !Combatant_IsUsed(1))
    {
        /* tests member 1 again, so this never switches to member 2 */
        if (!Combatant_IsUsed(1))
            return;
        who = 2;
    }
    Combatant_AddBaseStat(who, stat, 1);
    Combatant_RecalcStats(who);
    if (who == 1)
    {
        Combatant_RestoreHp(1);
        Combatant_RestoreMp(1);
    }
    Hud_InvalidateGauges();
}

// ScriptOpAlt_40D @ 0x08139758
void ScriptOpAlt_40D(void)
{
    gScriptPc++;
}

// ScriptOp_40E @ 0x08139768
void ScriptOp_40E(void)
{
    u16 k = SCRIPT_READ();

    k &= 0xF;
    if (k == 2)
        Flag_Set(0x10B);
    else if (k == 4)
        Flag_Set(0x10C);
}

// ScriptOpAlt_40E @ 0x081397A8
void ScriptOpAlt_40E(void)
{
    gScriptPc++;
}

// sub_081397B8 @ 0x081397B8
void sub_081397B8(void)
{
    gScriptPc++;
}

// ScriptOpAlt_40F @ 0x081397C8
void ScriptOpAlt_40F(void)
{
    gScriptPc++;
}
