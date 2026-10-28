/* Script VM opcode handlers 0x300-0x319 (gScriptOpTable / gScriptOpAltTable entries). */

#include "global.h"
#include "script.h"

// ScriptOp_Nop @ 0x081321B4
void ScriptOp_Nop(void)
{
}

// ScriptOpAlt_Shared_081321B8 @ 0x081321B8
void ScriptOpAlt_Shared_081321B8(void)
{
    gUnk_0203DB5E = 1;
}

// ScriptOpAlt_Shared_081321C4 @ 0x081321C4
void ScriptOpAlt_Shared_081321C4(void)
{
    gUnk_0203DB5E = 1;
    gUnk_0203DB60 = 1;
}

// ScriptOpAlt_301 @ 0x081321D8
void ScriptOpAlt_301(void)
{
    gUnk_0203DB5E = 2;
}

// ScriptOp_Newline @ 0x081321E4
void ScriptOp_Newline(void)
{
    gTextColumn = 0;
    gTextLine++;
    gUnk_0203DB4A++;
}

// ScriptOp_End @ 0x08132208
void ScriptOp_End(struct ScriptTask *task)
{
    if (gUnk_030069CC != 0)
    {
        gUnk_030069CC = 0;
        gScriptBase = gUnk_0203DAC8[15];
        gScriptPc = 0;
    }
    else if (gUnk_03006910 != 0)
    {
        gUnk_03006910 = 0;
        gScriptPc = gUnk_03006610;
        gScriptBase = gUnk_030068D0;
    }
    else if (gUnk_030065EC != 0)
    {
        gUnk_030065EC = 0;
        gScriptPc = gUnk_03006960;
        gScriptBase = gUnk_03006854;
    }
    else if (gUnk_03006600 != 0)
    {
        gUnk_03006600 = 0;
        gScriptPc = gUnk_030069E0;
        gScriptBase = gUnk_03006674;
    }
    else if (gUnk_0203DB64 != 0)
    {
        gUnk_0203DB64 = 0;
        gScriptPc = gUnk_03006818;
        gScriptBase = gUnk_030068C4;
    }
    else
    {
        gMsgGlyphCount = 0;
        gTextColumn = 0;
        gTextLine = 0;
        gScriptPc = 0;
        task->unk1C = 1;
        gUnk_0203DB46 = 1;
        sub_0813EB6C(0);
        Font_ResetGlyphSpriteCache(0x180);
        Task_End(gUnk_030069E4);
        gScriptYield = 1;
    }
}

// sub_08132350 @ 0x08132350
void sub_08132350(u16 code)
{
    if (code == 0xFF)
    {
        Music_Play(0);
        return;
    }
    if (code == 0xC4)
        code = 0x8F;
    if (code == 0xC5)
        code = 0x90;
    if (code == 0xC0)
        code = 0x91;
    if (code == 0xC2)
        code = 0x92;
    if (code < 0xC0)
    {
        code = gUnknown_08790180[code];
        if (code != 0xFFFF)
        {
            if (code < 100)
                Music_Play(code);
            else
                Sound_Play(code);
        }
    }
}

// ScriptOp_303 @ 0x081323AC
void ScriptOp_303(void)
{
    sub_08132350(SCRIPT_READ());
}
