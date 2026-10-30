/* Script VM opcode handlers 0x445 (pre-scan) and 0x446, and the demon negotiation helpers after
   them. */

#include "global.h"
#include "scriptops3.h"

// ScriptOpAlt_445 @ 0x0813BC2C
void ScriptOpAlt_445(void)
{
    gScriptPc++;
}

/* Applies status set gUnknown_08790DFC[hi byte] to the hero (mode 0) or to demon
   gUnk_0203DB7C among the battle enemies 0x10-0x17 (2: first one, 3: all). */
// ScriptOp_446 @ 0x0813BC3C
void ScriptOp_446(void)
{
    u16 w = SCRIPT_READ();
    u16 mode = w & 0xFF;
    u16 mask;
    u16 dead;

    w >>= 8;
    mask = gUnknown_08790DFC[w];

    if (mode == 0)
    {
        sub_080C08E8(0, mask);
        if (mask & 0x8000)
            *(u16 *)(Battle_GetCombatant(0x8000) + 0x18) = mode;
        sub_080C84A0();
    }
    else if (mode == 2)
    {
        for (mode = 0x10; mode < 0x18; mode++)
        {
            if (Combatant_IsAlive(mode) && Combatant_GetDemonId(mode) == gUnk_0203DB7C)
                break;
        }
        dead = mask & 0x8000;
        if (dead)
        {
            sub_080EF20C(mode);
        }
        else
        {
            sub_080C08E8(mode, mask);
            *(u16 *)(Battle_GetCombatant(mode + 0x8000) + 0x18) = dead;
            sub_080C84A0();
        }
    }
    else if (mode == 3)
    {
        mode = 0x10;
        do
        {
            if (Combatant_IsAlive(mode) && Combatant_GetDemonId(mode) == gUnk_0203DB7C)
            {
                sub_080C08E8(mode, mask);
                if (mask & 0x8000)
                    sub_080C84A0();
            }
        } while (++mode < 0x18);
        sub_080C84A0();
    }
}

// ScriptOpAlt_446 @ 0x0813BD48
void ScriptOpAlt_446(void)
{
    gScriptPc++;
}

/* Random pick from the 4-byte threshold row of gUnknown_08790E1C for demon gUnk_0203DB7C. */
// sub_0813BD58 @ 0x0813BD58
u8 sub_0813BD58(void)
{
    u8 a[2];
    u8 n, row, r;

    Demon_GetRaceAndAlign(gUnk_0203DB7C, &a[0], &a[1]);
    row = a[0];
    row = (row & 0x3F) * 4;
    n = 0;
loop:
    r = Random_Byte();
    if (r > gUnknown_08790E1C[row + n])
    {
        n++;
        goto loop;
    }
    return n;
}

// sub_0813BDA4 @ 0x0813BDA4
void sub_0813BDA4(void)
{
    gUnk_03006690 = Random_Byte() & 0xF;
    gUnk_03006690 = (Random_Byte() & 0xF) + gUnk_03006690 + 8;
}

// sub_0813BDCC @ 0x0813BDCC
u32 sub_0813BDCC(void)
{
    u32 n = (Demon_GetField(gUnk_0203DB7C, 0x1A) & 0xF0) >> 4;
    u16 v = (Demon_GetField(gUnk_0203DB7C, 0) & 0xFF) * 8;
    u32 r;

    if (n <= 7)
        r = n * v;
    else
        r = sub_08137B78(v, n);
    return r;
}

/* Pays gUnk_0203DB2C magnetite; TRUE when there is not enough. */
// Magnetite_Pay @ 0x0813BE08
bool32 Magnetite_Pay(void)
{
    if (Magnetite_Get() >= gUnk_0203DB2C)
    {
        Magnetite_Add(-gUnk_0203DB2C);
        return FALSE;
    }
    return TRUE;
}

/* Pays gUnk_0203DB2C macca; TRUE when there is not enough. */
// Money_Pay @ 0x0813BE2C
bool32 Money_Pay(void)
{
    if (Money_Get() >= gUnk_0203DB2C)
    {
        Money_Add(-gUnk_0203DB2C);
        return FALSE;
    }
    return TRUE;
}

// sub_0813BE50 @ 0x0813BE50
void sub_0813BE50(u16 n)
{
    s32 v = sub_080EF90C() + n;

    if (v > 0x1F)
        v = 0x1F;
    sub_080EF930(v);
}

// sub_0813BE70 @ 0x0813BE70
void sub_0813BE70(void)
{
    u16 idx = (gScriptItemCheckId - 0x120) * 4;

    sub_0813BE50(gUnknown_081A6ED4[idx]);
}

// sub_0813BE98 @ 0x0813BE98
void sub_0813BE98(void)
{
    sub_0813BE50(40 / ((u8)gUnk_03006690 + 2));
}

// sub_0813BEB8 @ 0x0813BEB8
void sub_0813BEB8(void)
{
    sub_0813BE50((Random_Byte() & 3) + 1);
}

/* Opens a choice list of ids 0x120-0x12B. */
// sub_0813BECC @ 0x0813BECC
void sub_0813BECC(u16 kind)
{
    u16 i, j;

    gUnk_03006844 = kind;
    MsgWindow_SaveGlyphs();
    for (i = 0; i < 20; i++)
        gUnk_0203DB88[i] |= 0xFFFF;
    j = 0;
    for (i = 0x120; i < 300; i++)
        gUnk_0203DB88[j++] = i;
    gScriptWaitState = 0x48;
    gUnk_03006940 = 0;
    gUnk_0300696C = 0;
    sub_08133F14(0);
    Task_Create(gUnknown_0878FE64, 0xFFFF);
}

// sub_0813BF58 @ 0x0813BF58
bool32 sub_0813BF58(void)
{
    if (gUnk_0300684C & 1)
        return TRUE;
    return FALSE;
}

// sub_0813BF78 @ 0x0813BF78
bool32 sub_0813BF78(void)
{
    if (gUnk_0300684C & 2)
        return TRUE;
    return FALSE;
}
