#include "global.h"
#include "status.h"

// Status_DrawDemonInfo @ 0x080C99C4
/* Draws the race (or one of five fixed 3-glyph titles), the level and the name of the shown
   combatant into the status canvas. Names are always 8 glyphs, 12 pixels apart (x 0x78-0xCC). */
void Status_DrawDemonInfo(struct Task *t)
{
    struct C0c6Status *st = &gMenuState;
    struct Combatant *c = Status_GetCombatant(st->sel);
    u8 *rec = Demon_GetRecord(c->demonId);
    const u16 *race = Race_GetName((s8)rec[0]);
    u16 y = 8;
    u16 name[16];
    u32 zero;
    u32 zero2;
    u32 i;
    u32 x;
    u16 *glyph;

    zero = 0;
    CpuSet(&zero, gUnk_0200F874, 0x05002000);
    zero2 = 0;
    CpuSet(&zero2, name, 0x05000008);
    if (sub_080C9388(st->sel) == 0)
    {
        u16 id = Fusion_GetDemonByIndex(c->demonId);

        if (id == 0x6F)
        {
            Font_DrawGlyphTinted(0x923, gUnk_0200F874, 0x18, 8, 6);
            Font_DrawGlyphTinted(0xC5C, gUnk_0200F874, 0x24, 8, 6);
            Font_DrawGlyphTinted(0xA7B, gUnk_0200F874, 0x30, 8, 6);
        }
        else if (id == 0x93)
        {
            Font_DrawGlyphTinted(0xDB4, gUnk_0200F874, 0x18, 8, 6);
            Font_DrawGlyphTinted(0xFA9, gUnk_0200F874, 0x24, 8, 6);
            Font_DrawGlyphTinted(0x811, gUnk_0200F874, 0x30, 8, 6);
        }
        else if (id == 0xA7)
        {
            Font_DrawGlyphTinted(0xDC1, gUnk_0200F874, 0x18, 8, 6);
            Font_DrawGlyphTinted(0xFA9, gUnk_0200F874, 0x24, 8, 6);
            Font_DrawGlyphTinted(0x811, gUnk_0200F874, 0x30, 8, 6);
        }
        else if (id == 0xBB)
        {
            Font_DrawGlyphTinted(0x112D, gUnk_0200F874, 0x18, 8, 6);
            Font_DrawGlyphTinted(0xFA9, gUnk_0200F874, 0x24, 8, 6);
            Font_DrawGlyphTinted(0x811, gUnk_0200F874, 0x30, 8, 6);
        }
        else if (id == 0xCF)
        {
            Font_DrawGlyphTinted(0x794, gUnk_0200F874, 0x18, 8, 6);
            Font_DrawGlyphTinted(0xFA9, gUnk_0200F874, 0x24, 8, 6);
            Font_DrawGlyphTinted(0x811, gUnk_0200F874, 0x30, 8, 6);
        }
        else
            Text_DrawStringTinted(race, gUnk_0200F874, 0x18, 8, 6, 12);
    }
level:
    if (sub_080C92AC(c->demonId) != 1)
    {
        if (sub_080C99B8(c) == 1)
        {
            DigitFont_DrawAscii(gUnknown_084EFAD4, 0x54, y + 2, 0);
            DigitFont_DrawAscii(gUnknown_084EFAD8, 0x64, y + 2, 4);
        }
        else
        {
            DigitFont_DrawAscii(gUnknown_084EFAD4, 0x54, y + 2, 0);
            if (c->level <= 9)
                DigitFont_DrawNumber(c->level, 0x64, y + 2, 4);
            else
                DigitFont_DrawNumber(c->level, 0x6C, y + 2, 4);
        }
    }
    if (c->id <= 3)
    {
        Combatant_DecodeName(c, name);
        for (i = 0, x = 0x78 << 16, glyph = name; i < 8; x += 12 << 16, glyph++, i++)
            Font_DrawGlyphTinted(*glyph, gUnk_0200F874, x >> 16, y, 0);
    }
    else
    {
        for (i = 0, x = 0x78 << 16, glyph = (u16 *)(rec + 0x22); i < 8; x += 12 << 16, glyph++, i++)
            Font_DrawGlyphTinted(*glyph, gUnk_0200F874, x >> 16, y, 0);
    }
}


// sub_080C9BCC @ 0x080C9BCC
/* Draws the current page (st->page) of the status screen. */
void sub_080C9BCC(struct Task *t)
{
    struct C0c6Status *st = &gMenuState;

    st->unk10 = 0;
    st->unk1C = 0;
    st->unk1E = 0;
    sub_080C97F0(t, 0);
    sub_080C9854(t, 0);
    switch (st->page)
    {
    case 0:
        Status_DrawVitals(0, t);
        if (st->sprite != NULL)
            sub_080C3E5C(st->sprite, -gUnk_03000004, 0x18);
        break;
    case 1:
        sub_080CB71C(0, t);
        st->unk10 = 1;
        break;
    case 2:
        sub_080CB7A0(0, t);
        break;
    case 3:
        sub_080CB8C8(0, t);
        break;
    case 4:
        sub_080CB928(0, t);
        if (st->sprite != NULL)
            sub_080C3E5C(st->sprite, -gUnk_03000004 - 0x100, 0x18);
        st->unk1E = 1;
        st->unk10 = 1;
        break;
    case 5:
        Status_DrawDropItem(0, t);
        if (st->sprite != NULL)
            sub_080C3E5C(st->sprite, -gUnk_03000004 - 0x100, 0x18);
        st->unk1C = 1;
        break;
    }
    sub_080C9994();
}

// sub_080C9CD8 @ 0x080C9CD8
void sub_080C9CD8(struct Task *t)
{
    Canvas_FillRect(0, gUnk_0200F874, 0, 0x1C, 0xA0, 0x6A);
    sub_080C9994();
}

// sub_080C9D00 @ 0x080C9D00
void sub_080C9D00(struct Task *t)
{
    struct C0c6Status *st = &gMenuState;
    u32 r;

    Status_GetCombatant(st->sel);
    switch (st->unk06)
    {
    case 0:
        Status_DrawDerivedStats(0, t);
        break;
    case 1:
        sub_080CC630(0, t);
        break;
    case 2:
        sub_080CC694(0, t);
        break;
    }
    r = sub_080C9388(st->sel);
    if (r != 1)
        r = 0;
    st->unk16 = r;
    sub_080C9994();
}

// sub_080C9D5C @ 0x080C9D5C
void sub_080C9D5C(void)
{
    Canvas_FillRect(0, gUnk_0200F874, 0xD4, 0x1C, 0x1C, 0x6A);
    sub_080C9994();
}

// sub_080C9D84 @ 0x080C9D84
void sub_080C9D84(struct Task *t)
{
    struct C0c6Status *st = &gMenuState;
    u16 item = gUnk_0203B454[st->unk2C + st->unk2E];
    s32 attr;

    st->unk32 = 0;
    st->unk18 = 0;
    switch (st->unk08)
    {
    case 0:
        sub_080CC844(0, t);
        st->unk18 = 1;
        break;
    case 1:
        sub_080CCA10(0, t);
        break;
    case 2:
        sub_080CCAB4(0, t);
        Item_GetAttribute(item, 0, &attr);
        st->unk32 = attr;
        break;
    case 3:
        sub_080CCD5C(0, t);
        st->unk18 = 1;
        break;
    }
    sub_080C9994();
}

// sub_080C9E08 @ 0x080C9E08
void sub_080C9E08(void)
{
    Canvas_FillRect(0, gUnk_0200F874, 0, 0x88, 0xF0, 0x20);
    sub_080C9994();
}

// Status_DrawScreen @ 0x080C9E30
/* Opens the three status windows and draws every part of the screen. */
void Status_DrawScreen(struct Task *t)
{
    struct C0c6Status *st = &gMenuState;
    u32 zero = 0;

    CpuSet(&zero, gWindowTilemapBuffer, 0x05000200);
    st->window40 = TextWindow_CreateOpenWithFrame(0, 2, 0x14, 0xE, 2, gUnknown_084EFA9C);
    st->window44 = TextWindow_CreateOpenWithFrame(0x14, 2, 0xA, 0xE, 2, gUnknown_084EFAAE);
    st->window48 = TextWindow_CreateOpenWithFrame(0, 0x10, 0x1E, 4, 2, gUnknown_084EFAC0);
    Status_DrawDemonInfo(t);
    sub_080C9BCC(t);
    sub_080C9D00(t);
    sub_080C9D84(t);
}

// sub_080C9EBC @ 0x080C9EBC
/* Enables the V-count interrupt at line 0x80 and clears the BG1/BG2 scroll. */
void sub_080C9EBC(void)
{
    REG_IE |= 4;
    REG_DISPSTAT &= 0xFF;
    REG_DISPSTAT |= 0x8024;
    REG_BG1HOFS = 0;
    REG_BG2HOFS = 0;
}

// sub_080C9EF8 @ 0x080C9EF8
void sub_080C9EF8(void)
{
    struct C0c6Status *st = &gMenuState;

    REG_BG1HOFS = st->hofs;
    REG_BG2HOFS = st->hofs;
}

// sub_080C9F14 @ 0x080C9F14
void sub_080C9F14(struct Task *t, s32 dx)
{
    struct C0c6Status *st = &gMenuState;

    gIntrTable[2] = sub_080C9EF8;
    st->hofs += dx;
    VBlankTask_AddCountedAlways(sub_080C9EBC, 1);
}

// sub_080C9F40 @ 0x080C9F40
void sub_080C9F40(void)
{
    REG_IE &= ~4;
    REG_DISPSTAT &= ~0x24;
    REG_BG1HOFS = 0;
    REG_BG2HOFS = 0;
    gIntrTable[2] = IntrDummy;
}

// sub_080C9F84 @ 0x080C9F84
void sub_080C9F84(void)
{
    VBlankTask_AddCountedAlways(sub_080C9F40, 1);
}
