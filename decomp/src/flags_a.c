#include "global.h"
#include "combatant.h"

/* Story flags and other bit arrays, their SRAM copies, and the options word. */

#define BIT_TEST(a, i)  (((a)[(i) >> 3] >> ((i) & 7)) & 1)

// Flag_Test @ 0x080C2340
u32 Flag_Test(u32 flag)
{
    return BIT_TEST(gGameState.flags, flag);
}

// Flag_Set @ 0x080C2364
/* Flags 0x120-0x14D are mirrored in gUnk_03004680 (kept in SRAM across games). */
void Flag_Set(u32 flag)
{
    gGameState.flags[flag >> 3] |= 1 << (flag & 7);
    sub_080C90FC(flag);
    flag -= 0x120;
    if (flag <= 0x2D)
        gUnk_03004680[flag >> 3] |= 1 << (flag & 7);
}

// Flag_Clear @ 0x080C23BC
void Flag_Clear(u32 flag)
{
    gGameState.flags[flag >> 3] &= ~(1 << (flag & 7));
    sub_080C90FC(flag);
    flag -= 0x120;
    if (flag <= 0x2D)
        gUnk_03004680[flag >> 3] &= ~(1 << (flag & 7));
}

// sub_080C2414 @ 0x080C2414
u32 sub_080C2414(u32 i)
{
    return BIT_TEST(gGameState.bits1750, i);
}

// sub_080C2438 @ 0x080C2438
void sub_080C2438(u32 i)
{
    gGameState.bits1750[i >> 3] |= 1 << (i & 7);
}

// sub_080C245C @ 0x080C245C
void sub_080C245C(u32 i)
{
    gGameState.bits1750[i >> 3] &= ~(1 << (i & 7));
}

// sub_080C2480 @ 0x080C2480
u32 sub_080C2480(u32 i)
{
    if (i & 0x8000)
        return 0;
    return BIT_TEST(gGameState.bits10D4, i);
}

// sub_080C24B8 @ 0x080C24B8
/* i | 0x8000 clears bit i; otherwise sets it when sub_080C90F8(i) allows. */
void sub_080C24B8(u32 i)
{
    if (i & 0x8000)
    {
        i &= 0x7FFF;
        gGameState.bits10D4[i >> 3] &= ~(1 << (i & 7));
    }
    else if (sub_080C90F8(i))
    {
        gGameState.bits10D4[i >> 3] |= 1 << (i & 7);
    }
}

// sub_080C2520 @ 0x080C2520
void sub_080C2520(u32 i)
{
    if (!(i & 0x8000))
        gGameState.bits10D4[i >> 3] &= ~(1 << (i & 7));
}

// sub_080C2554 @ 0x080C2554
/* Demon `id` seen (compendium-style bit array, ids 0-255). */
u32 sub_080C2554(u32 id)
{
    if (id > 0xFF)
        return 0;
    return BIT_TEST(gGameState.bits1054, id);
}

// sub_080C2584 @ 0x080C2584
void sub_080C2584(u32 id)
{
    s8 *rec = (s8 *)Demon_GetRecord(id);

    if (id > 0xFF)
    {
        sub_080C2674(id);
        return;
    }
    if (rec[0] > 0x1A)
        sub_080C2674(id);
    gGameState.bits1054[id >> 3] |= 1 << (id & 7);
}

// sub_080C25D4 @ 0x080C25D4
void sub_080C25D4(u32 id)
{
    if (id <= 0xFF)
        gGameState.bits1054[id >> 3] &= ~(1 << (id & 7));
}

// sub_080C2600 @ 0x080C2600
/* Maps id through the pair table gUnknown_081A6272 (ends with 0xFFFF). */
u16 sub_080C2600(u16 id)
{
    u16 i;

    for (i = 0;; i++)
    {
        if (gUnknown_081A6272[i][0] == 0xFFFF)
            return id;
        if (gUnknown_081A6272[i][0] == id)
            return gUnknown_081A6272[i][1];
    }
}

// sub_080C263C @ 0x080C263C
u16 sub_080C263C(u16 id)
{
    return id;
}

// sub_080C2644 @ 0x080C2644
u32 sub_080C2644(u32 id)
{
    if (id > 0x17B)
        return 0;
    return BIT_TEST(gUnk_03004690, id);
}

// sub_080C2674 @ 0x080C2674
void sub_080C2674(u32 id)
{
    if (id <= 0x17B)
    {
        id = sub_080C2600(id);
        if (Dict_GetMapScript(id))
            gUnk_03004690[id >> 3] |= 1 << (id & 7);
    }
}

// sub_080C26B8 @ 0x080C26B8
void sub_080C26B8(u32 id)
{
    if (id <= 0x17B)
    {
        gUnk_03004690[id >> 3] &= ~(1 << (id & 7));
        id = sub_080C2600(id);
        gUnk_03004690[id >> 3] &= ~(1 << (id & 7));
    }
}

// sub_080C2704 @ 0x080C2704
void sub_080C2704(void)
{
    Sram_WriteVerified(gUnk_03004690, (void *)0x0E000014, 0x30);
}

// sub_080C271C @ 0x080C271C
void sub_080C271C(void)
{
    Sram_ReadVerified((void *)0x0E000014, gUnk_03004690, 0x30);
}

// sub_080C2734 @ 0x080C2734
u32 sub_080C2734(u32 i)
{
    i -= 0x12C;
    if (i > 0x3F)
        return 0;
    return BIT_TEST(gUnk_03006090, i);
}

// sub_080C2764 @ 0x080C2764
void sub_080C2764(u32 i)
{
    i -= 0x12C;
    if (i <= 0x3F)
        gUnk_03006090[i >> 3] |= 1 << (i & 7);
}

// sub_080C2790 @ 0x080C2790
void sub_080C2790(u32 i)
{
    i -= 0x12C;
    if (i <= 0x3F)
        gUnk_03006090[i >> 3] &= ~(1 << (i & 7));
}

// sub_080C27BC @ 0x080C27BC
void sub_080C27BC(void)
{
    u8 *sram = (u8 *)0x0E000000;

    Sram_WriteVerified(gUnk_03006090, sram + 0x44, 8);
    Sram_WriteVerified(gUnk_03004680, sram + 0x6CAC, 8);
}

// sub_080C27F0 @ 0x080C27F0
/* Loads the cross-game bits from SRAM and applies them (items 0x12C-0x16B, flags
   0x120-0x15F). */
void sub_080C27F0(void)
{
    u8 *sram = (u8 *)0x0E000000;
    u32 i;

    Sram_ReadVerified(sram + 0x44, gUnk_03006090, 8);
    for (i = 0; i < 64; i++)
    {
        if (sub_080C2734(i + 0x12C) && !sub_080C32D4(i + 0x12C))
            sub_080C3328(i + 0x12C);
    }
    Sram_ReadVerified(sram + 0x6CAC, gUnk_03004680, 8);
    for (i = 0; i < 64; i++)
    {
        if (BIT_TEST(gUnk_03004680, i))
            Flag_Set(i + 0x120);
    }
}

// sub_080C287C @ 0x080C287C
u32 sub_080C287C(u32 id)
{
    if (id > 0xFE)
        return 0;
    if (id == 0)
        return 0;
    if (id == 0xDE)
        return 0;
    if ((s8)Demon_GetRecord(id)[0] == 0x1D)
        return 0;
    if ((s8)Demon_GetRecord(id)[0] == 0x1E)
        return 0;
    if ((s8)Demon_GetRecord(id)[0] == 0x28)
        return 0;
    return 1;
}

// sub_080C28CC @ 0x080C28CC
u32 sub_080C28CC(u32 id)
{
    u32 r = sub_080C287C(id);

    if (r == 1)
        return (gUnk_03004650[id >> 3] >> (id & 7)) & r;
    return 0;
}

// sub_080C28F8 @ 0x080C28F8
void sub_080C28F8(u32 id)
{
    u32 r = sub_080C287C(id);

    if (r == 1)
        gUnk_03004650[id >> 3] |= r << (id & 7);
}

// sub_080C2924 @ 0x080C2924
void sub_080C2924(u32 id)
{
    if (id <= 0x17B)
        gUnk_03004650[id >> 3] &= ~(1 << (id & 7));
}

// sub_080C2950 @ 0x080C2950
void sub_080C2950(void)
{
    Sram_WriteVerified(gUnk_03004650, (void *)0x0E00004C, 0x30);
}

// sub_080C2968 @ 0x080C2968
void sub_080C2968(void)
{
    Sram_ReadVerified((void *)0x0E00004C, gUnk_03004650, 0x30);
}

// sub_080C2980 @ 0x080C2980
void sub_080C2980(void)
{
    Sram_WriteVerified(&gColorEffect, (void *)0x0E006C9C, 0x10);
}

// sub_080C2998 @ 0x080C2998
void sub_080C2998(void)
{
    Sram_ReadVerified((void *)0x0E006C9C, &gColorEffect, 0x10);
}

// sub_080C29B0 @ 0x080C29B0
u32 sub_080C29B0(u32 id)
{
    if (id > 0x17B)
        return 0;
    return BIT_TEST(gGameState.bits1106, id);
}

// sub_080C29E8 @ 0x080C29E8
void sub_080C29E8(u32 id)
{
    if (id <= 0x17B)
        gGameState.bits1106[id >> 3] |= 1 << (id & 7);
}

// sub_080C2A1C @ 0x080C2A1C
void sub_080C2A1C(u32 id)
{
    if (id <= 0x17B)
        gGameState.bits1106[id >> 3] &= ~(1 << (id & 7));
}

// sub_080C2A50 @ 0x080C2A50
void sub_080C2A50(s32 i, u16 v)
{
    u16 buf[4];

    Sram_ReadVerified((void *)0x0E000008, buf, 8);
    buf[i] = v;
    Sram_WriteVerified(buf, (void *)0x0E000008, 8);
}

// sub_080C2A84 @ 0x080C2A84
u16 sub_080C2A84(s32 i)
{
    u16 buf[4];

    Sram_ReadVerified((void *)0x0E000008, buf, 8);
    return buf[i];
}

// Options_Load @ 0x080C2AA8
/* Reads the options word from SRAM. */
u32 Options_Load(void)
{
    u32 v;

    Sram_ReadVerified((void *)0x0E000010, &v, 4);
    gOptions = v;
    return v;
}

// Options_Get @ 0x080C2ACC
u32 Options_Get(void)
{
    return gOptions;
}

// Options_Save @ 0x080C2AD8
void Options_Save(u32 v)
{
    Sram_WriteVerified(&v, (void *)0x0E000010, 4);
    gOptions = v;
}

// sub_080C2AFC @ 0x080C2AFC
u32 sub_080C2AFC(void)
{
    if (Options_Load() & 1)
        return 0;
    return 1;
}

// sub_080C2B14 @ 0x080C2B14
void sub_080C2B14(u16 v)
{
    Options_Save(v | (Options_Load() & ~3));
}

// Settings_GetBattleMsgSpeed @ 0x080C2B34
u32 Settings_GetBattleMsgSpeed(void)
{
    if (Options_Load() & 4)
        return 0;
    return 1;
}

// sub_080C2B4C @ 0x080C2B4C
void sub_080C2B4C(u16 v)
{
    Options_Save(v | (Options_Load() & ~0xC));
}

// sub_080C2B6C @ 0x080C2B6C
u32 sub_080C2B6C(void)
{
    if (Options_Load() & 0x10)
        return 0;
    return 1;
}

// sub_080C2B84 @ 0x080C2B84
void sub_080C2B84(u16 v)
{
    Options_Save(v | (Options_Load() & ~0x30));
}

// sub_080C2BA4 @ 0x080C2BA4
u32 sub_080C2BA4(void)
{
    u32 v = Options_Load();

    if (v & 0x40)
        return 0;
    if (v & 0x80)
        return 1;
    return 2;
}

// sub_080C2BCC @ 0x080C2BCC
void sub_080C2BCC(u16 v)
{
    Options_Save(v | (Options_Load() & ~0x1C0));
}

// sub_080C2BF0 @ 0x080C2BF0
u32 sub_080C2BF0(void)
{
    if (Options_Load() & 0x200)
        return 0;
    return 1;
}

// sub_080C2C0C @ 0x080C2C0C
void sub_080C2C0C(u16 v)
{
    Options_Save(v | (Options_Load() & ~0x600));
}

// sub_080C2C30 @ 0x080C2C30
u32 sub_080C2C30(void)
{
    if (Options_Load() & 0x800)
        return 0;
    return 1;
}

// sub_080C2C4C @ 0x080C2C4C
void sub_080C2C4C(u16 v)
{
    Options_Save(v | (Options_Load() & ~0x1800));
}

// sub_080C2C70 @ 0x080C2C70
u32 sub_080C2C70(void)
{
    u32 v = Options_Get();

    if (v & 0x2000)
        return 0;
    if (v & 0x4000)
        return 1;
    return 2;
}

// sub_080C2C9C @ 0x080C2C9C
void sub_080C2C9C(u16 v)
{
    Options_Save(v | (Options_Load() & ~0xE000));
}

// sub_080C2CC0 @ 0x080C2CC0
void sub_080C2CC0(void)
{
    if (Moon_GetPhase() & 1)
        Moon_Advance(0xFF);
}

// sub_080C2CD8 @ 0x080C2CD8
void sub_080C2CD8(s8 a, s8 b, s8 c)
{
    u32 zero;

    gUnk_03003FC4 = a;
    gUnk_03004618 = b;
    gUnk_03004624 = c;
    SetMainCallback(sub_080C1880);
    zero = 0;
    CpuSet(&zero, gPaletteBuffer, 0x05000100);
    Palette_MarkDirty();
    sub_080C2CC0();
    if (c == 0)
        gGameState.unkAC0 = 1;
}
