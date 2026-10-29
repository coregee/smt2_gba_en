#include "global.h"
#include "status.h"

void sub_080CBB34(void);
extern const u8 gUnknown_084F01B4[];

#define CANVAS gUnk_0200F874
#define GLYPH(code, x, y) Font_DrawGlyph(code, CANVAS, x, y)
#define GLYPH4(code, x, y) Font_DrawGlyphTinted(code, CANVAS, x, y, 4)

/* Labels of the item-demon page: two kanji (12 pixels apart) at x 0xA4/0xB0 per row, then
   the value from the item's record (sub_080CD668.. / sub_080CD330..). */
#define ITEM_LABELS(id)                               \
{                                                               \
    GLYPH(0xFA9, 0xA4, 0x1C);                                   \
    GLYPH(0x8C3, 0xB0, 0x1C);                                   \
    sub_080CD668(id, 0xCE, 0x1F, 4);                            \
    GLYPH(0x699, 0xA4, 0x29);                                   \
    GLYPH(0xEB7, 0xB0, 0x29);                                   \
    sub_080CD6C4(id, 0xCE, 0x2C, 4);                            \
    GLYPH(0xC1A, 0xA4, 0x36);                                   \
    GLYPH(0xB7E, 0xB0, 0x36);                                   \
}

/* Second status page: the eight derived values (combatant +0x48..+0x56) for humans
   (sub_080CBB34 draws their labels); for the four item-like demons 0x93, 0xA7, 0xBB, 0xCF
   (Fusion_GetDemonByIndex) and for those sub_080C92AC accepts, labels drawn as kanji glyph
   ids and values taken from the record; dashes (gUnknown_084F01B4) when sub_080C99B8 says the
   entry is unknown; otherwise six of the derived values (in mode 7 from the stock entry). */
// Status_DrawDerivedStats @ 0x080CBC8C
void Status_DrawDerivedStats(u32 a, struct Task *t)
{
    struct C0c6Status *st = &gMenuState;
    struct Combatant *c = Status_GetCombatant(st->sel);
    u16 id;

    if (sub_080C9388(st->sel) == 1)
    {
        sub_080CBB34();
        DigitFont_DrawNumber(c->derived[0], 0xE6, 0x1F, 4);
        DigitFont_DrawNumber(c->derived[1], 0xE6, 0x2C, 4);
        DigitFont_DrawNumber(c->derived[2], 0xE6, 0x39, 4);
        DigitFont_DrawNumber(c->derived[3], 0xE6, 0x46, 4);
        DigitFont_DrawNumber(c->derived[4], 0xE6, 0x53, 4);
        DigitFont_DrawNumber(c->derived[5], 0xE6, 0x60, 4);
        DigitFont_DrawNumber(c->derived[6], 0xE6, 0x6D, 4);
        DigitFont_DrawNumber(c->derived[7], 0xE6, 0x7A, 4);
        return;
    }
    id = Fusion_GetDemonByIndex(c->demonId);
    if (id == 0x93)
    {
        ITEM_LABELS(0x93);
        GLYPH4(0xB32, 0xBE, 0x36);
        GLYPH4(0xB8C, 0xCA, 0x36);
        GLYPH4(0xFA9, 0xD6, 0x36);
        GLYPH4(0x811, 0xE2, 0x36);
        GLYPH(0xC3E, 0xA4, 0x43);
        GLYPH(0xB7E, 0xB0, 0x43);
        sub_080CD45C(0x93, 0xD6, 0x46);
    }
    else if (id == 0xA7)
    {
        ITEM_LABELS(0xA7);
        GLYPH4(0xC5E, 0xBE, 0x36);
        GLYPH4(0xD6E, 0xCA, 0x36);
        GLYPH4(5, 0xD6, 0x36);
        GLYPH4(0xAEB, 0xE2, 0x36);
        GLYPH(0xC3E, 0xA4, 0x43);
        GLYPH(0xB7E, 0xB0, 0x43);
        sub_080CD45C(0xA7, 0xD6, 0x46);
    }
    else if (id == 0xBB)
    {
        ITEM_LABELS(0xBB);
        GLYPH4(0xC5E, 0xCA, 0x36);
        GLYPH4(0xEDC, 0xD6, 0x36);
        GLYPH4(0x86A, 0xE2, 0x36);
        GLYPH(0xC3E, 0xA4, 0x43);
        GLYPH(0xB7E, 0xB0, 0x43);
        sub_080CD45C(0xBB, 0xD6, 0x46);
    }
    else if (id == 0xCF)
    {
        ITEM_LABELS(0xCF);
        GLYPH4(0xC5E, 0xCA, 0x36);
        GLYPH4(0x676, 0xD6, 0x36);
        GLYPH4(0x632, 0xE2, 0x36);
        GLYPH(0xC3E, 0xA4, 0x43);
        GLYPH(0xB7E, 0xB0, 0x43);
        sub_080CD45C(0xCF, 0xD6, 0x46);
    }
    else if (sub_080C92AC(c->demonId) == 1)
    {
        id = Fusion_GetDemonByIndex(c->demonId);
        GLYPH(0x8F1, 0xA4, 0x1C);
        GLYPH(0x861, 0xB0, 0x1C);
        sub_080CD330(id, 0xCE, 0x1F, 4);
        GLYPH(0xFFE, 0xA4, 0x29);
        GLYPH(0xCD3, 0xB0, 0x29);
        sub_080CD38C(id, 0xCE, 0x2C, 4);
        GLYPH(0x8F1, 0xA4, 0x36);
        GLYPH(0x861, 0xB0, 0x36);
        GLYPH(0x699, 0xBC, 0x36);
        GLYPH(0xB67, 0xC8, 0x36);
        sub_080CD3E8(id, 0xD6, 0x39, 4);
        GLYPH(0xC3E, 0xA4, 0x43);
        GLYPH(0xB7E, 0xB0, 0x43);
        sub_080CD45C(id, 0xD6, 0x46);
    }
    else if (sub_080C99B8(c) == 1)
    {
        GLYPH(0x8F1, 0xA4, 0x1C);
        GLYPH(0x861, 0xB0, 0x1C);
        DigitFont_DrawAscii(gUnknown_084F01B4, 0xD6, 0x1F, 4);
        GLYPH(0xFFE, 0xA4, 0x29);
        GLYPH(0xCD3, 0xB0, 0x29);
        DigitFont_DrawAscii(gUnknown_084F01B4, 0xD6, 0x2C, 4);
        GLYPH(0xFA9, 0xA4, 0x36);
        GLYPH(0x8C3, 0xB0, 0x36);
        DigitFont_DrawAscii(gUnknown_084F01B4, 0xD6, 0x39, 4);
        GLYPH(0x699, 0xA4, 0x43);
        GLYPH(0xEB7, 0xB0, 0x43);
        DigitFont_DrawAscii(gUnknown_084F01B4, 0xD6, 0x46, 4);
        GLYPH(0xFC3, 0xA4, 0x50);
        GLYPH(0xF81, 0xB0, 0x50);
        GLYPH(0x5BB, 0xBC, 0x50);
        GLYPH(0x10CB, 0xC8, 0x50);
        DigitFont_DrawAscii(gUnknown_084F01B4, 0xD6, 0x53, 4);
        GLYPH(0xFC3, 0xA4, 0x5D);
        GLYPH(0xF81, 0xB0, 0x5D);
        GLYPH(0x8D7, 0xBC, 0x5D);
        GLYPH(0x672, 0xC8, 0x5D);
        DigitFont_DrawAscii(gUnknown_084F01B4, 0xD6, 0x60, 4);
    }
    else
    {
        struct Combatant *s = c;

        if (st->mode == 7)
            s = Stock_FindByDemonId(s->demonId);
        GLYPH(0x8F1, 0xA4, 0x1C);
        GLYPH(0x861, 0xB0, 0x1C);
        DigitFont_DrawNumber(s->derived[0], 0xE6, 0x1F, 4);
        GLYPH(0xFFE, 0xA4, 0x29);
        GLYPH(0xCD3, 0xB0, 0x29);
        DigitFont_DrawNumber(s->derived[1], 0xE6, 0x2C, 4);
        GLYPH(0xFA9, 0xA4, 0x36);
        GLYPH(0x8C3, 0xB0, 0x36);
        DigitFont_DrawNumber(s->derived[4], 0xE6, 0x39, 4);
        GLYPH(0x699, 0xA4, 0x43);
        GLYPH(0xEB7, 0xB0, 0x43);
        DigitFont_DrawNumber(s->derived[5], 0xE6, 0x46, 4);
        GLYPH(0xFC3, 0xA4, 0x50);
        GLYPH(0xF81, 0xB0, 0x50);
        GLYPH(0x5BB, 0xBC, 0x50);
        GLYPH(0x10CB, 0xC8, 0x50);
        DigitFont_DrawNumber(s->derived[6], 0xE6, 0x53, 4);
        GLYPH(0xFC3, 0xA4, 0x5D);
        GLYPH(0xF81, 0xB0, 0x5D);
        GLYPH(0x8D7, 0xBC, 0x5D);
        GLYPH(0x672, 0xC8, 0x5D);
        DigitFont_DrawNumber(s->derived[7], 0xE6, 0x60, 4);
    }
}
