#include "global.h"
#include "status.h"

// SmallFont_DrawAscii @ 0x080CCE5C
/* Draws an ASCII string in the small font (8 pixels per character). Only '+'..'z' map through
   gUnknown_084F01F4, plus '?' and '-'. */
void SmallFont_DrawAscii(const u8 *str, u16 x, u16 y, u16 tint)
{
    u32 i;

    for (i = 0; *str != 0; i++, str++)
    {
        u16 g = gUnknown_084F01F4[*str - 0x2B];

        if (*str == '?')
            g = 0x13;
        if (*str == '-')
            g = 6;
        SmallFont_DrawGlyphTinted(g, gUnk_0200F874, x + i * 8, y, tint);
    }
}

// DigitFont_DrawAscii @ 0x080CCEC8
/* Same with the digit font (gUnknown_084F0254); also maps '\\'. */
void DigitFont_DrawAscii(const u8 *str, u16 x, u16 y, u16 tint)
{
    u32 dx = 0;

    for (; *str != 0; dx += 8, str++)
    {
        u16 g = gUnknown_084F0254[*str - 0x2B];

        if (*str == '?')
            g = 0x1F;
        if (*str == '-')
            g = 0xD;
        if (*str == 0x5C)
            g = 0x3E;
        DigitFont_DrawGlyphTinted(g, gUnk_0200F874, x + dx, y, tint);
    }
}

// SmallFont_DrawNumber @ 0x080CCF44
/* Draws value right-aligned (8 digits ending at x, leading zeros hidden) in the small font. */
void SmallFont_DrawNumber(s32 value, u16 x, u16 y, u16 tint)
{
    u8 *digits = NumberToDigits(value);
    u32 shown = 0;
    u16 dx = x - 0x38;
    u32 i;

    for (i = 0; i < 8; i++)
    {
        u8 d = digits[7 - i];
        u16 g = gUnknown_084F01F4[d + 5];

        if (i == 7 || shown == 1 || d != 0)
        {
            SmallFont_DrawGlyphTinted(g, gUnk_0200F874, dx, y, tint);
            shown = 1;
        }
        dx += 8;
    }
}

// DigitFont_DrawNumber @ 0x080CCFC4
/* Same with the digit font. */
void DigitFont_DrawNumber(s32 value, u16 x, u16 y, u16 tint)
{
    u8 *digits = NumberToDigits(value);
    u32 shown = 0;
    u16 dx = x - 0x38;
    u32 i;

    for (i = 0; i < 8; i++)
    {
        u8 d = digits[7 - i];
        u16 g = gUnknown_084F0254[d + 5];

        if (i == 7 || shown == 1 || d != 0)
        {
            DigitFont_DrawGlyphTinted(g, gUnk_0200F874, dx, y, tint);
            shown = 1;
        }
        dx += 8;
    }
}

// sub_080CD044 @ 0x080CD044
/* Draws the race class (by race: <= 12, <= 26, others) and the alignment label of a demon. */
void sub_080CD044(u16 id, u16 x, u16 y)
{
    u32 lx = x + 0x20;
    u8 *rec = Demon_GetRecord(id);
    s32 align = sub_0815B864(id);
    s8 race = rec[0];

    if (race <= 12)
        SmallFont_DrawAscii(gUnknown_084F02B4, lx, y, 4);
    else if (race <= 26)
        SmallFont_DrawAscii(gUnknown_084F02B8, lx, y, 4);
    else
        SmallFont_DrawAscii(gUnknown_084F02BC, lx, y, 4);
    lx += 0x10;
    if (align == 0)
        SmallFont_DrawAscii(gUnknown_084F02C0, lx, y, 4);
    else if (align == 1)
        SmallFont_DrawAscii(gUnknown_084F02C4, lx, y, 4);
    else if (align == 2)
        SmallFont_DrawAscii(gUnknown_084F02C8, lx, y, 4);
}

// sub_080CD0E4 @ 0x080CD0E4
void sub_080CD0E4(u16 id)
{
    SmallFont_DrawNumber(Demon_GetRecord(id)[0x1D], 0x90, 0x78, 4);
}

// Status_DrawEquipName @ 0x080CD100
/* Draws the name of equipment id: always 8 glyphs, 12 pixels apart (empty name: 8 glyphs
   0x3C; id 0xFF: the "none" string). */
void Status_DrawEquipName(u16 id, u16 x, u16 y, u16 tint)
{
    u32 cx = x;

    if (id == 0xFF)
    {
        Text_DrawStringTinted(gUnknown_084F02CA, gUnk_0200F874, (u16)cx, y, 2, 12);
    }
    else
    {
        u16 *name = (u16 *)(Equipment_GetRecord36_MidRange(id) + 0x14);

        if (*name == 0)
        {
            s32 i;
            for (i = 0; i < 8; i++)
            {
                Font_DrawGlyphTinted(0x3C, gUnk_0200F874, cx, y, 2);
                name++;
                cx += 12;
            }
        }
        else
        {
            s32 i;
            for (i = 0; i < 8; i++)
            {
                Font_DrawGlyphTinted(*name, gUnk_0200F874, cx, y, (u8)tint);
                cx += 12;
                name++;
            }
        }
    }
}

// Status_DrawActionName @ 0x080CD1A0
/* Draws the name of item/action id (8 glyphs). */
void Status_DrawActionName(u16 id, u16 x, u16 y, u16 tint)
{
    u32 cx = x;
    u16 *name = (u16 *)(Action_GetRecord(id) + 0xC);

    if (*name != 0)
    {
        s32 i;
        for (i = 0; i < 8; i++)
        {
            Font_DrawGlyphTinted(*name, gUnk_0200F874, cx, y, (u8)tint);
            cx += 12;
            name++;
        }
    }
}

// Status_DrawSkillName @ 0x080CD1F8
/* Draws the name of skill id (8 glyphs; empty: 8 glyphs 0x3C). */
void Status_DrawSkillName(u16 id, u16 x, u16 y)
{
    u32 cx = x;
    u16 *name = (u16 *)(sub_080BF5C0(id) + 6);

    if (*name == 0)
    {
        s32 i;
        for (i = 0; i < 8; i++)
        {
            Font_DrawGlyphTinted(0x3C, gUnk_0200F874, cx, y, 2);
            cx += 12;
            name++;
        }
    }
    else
    {
        s32 i;
        for (i = 0; i < 8; i++)
        {
            Font_DrawGlyph(*name, gUnk_0200F874, cx, y);
            cx += 12;
            name++;
        }
    }
}

// sub_080CD260 @ 0x080CD260
/* Draws the cost of skill id (record +3) after a label, if any. */
#ifdef NONMATCHING
void sub_080CD260(u16 id, u16 x, u16 x2, u16 y)
{
    u8 cost = sub_080BF5C0(id)[3];

    if (cost != 0)
    {
        DigitFont_DrawAscii(gUnknown_084F00E0, x, y, 0);
        DigitFont_DrawNumber(cost, x2, y, 0);
    }
}
#else
NAKED
void sub_080CD260(u16 id, u16 x, u16 x2, u16 y)
{
    asm_unified(
        ".L080CD260:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r5, r1, #0x10\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r7, r2, #0x10\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r6, r3, #0x10\n"
        "    bl sub_080BF5C0\n"
        "    ldrb r4, [r0, #3]\n"
        "    cmp r4, #0\n"
        "    beq .L080CD294\n"
        "    ldr r0, .L080CD29C\n"
        "    adds r1, r5, #0\n"
        "    adds r2, r6, #0\n"
        "    movs r3, #0\n"
        "    bl DigitFont_DrawAscii\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r7, #0\n"
        "    adds r2, r6, #0\n"
        "    movs r3, #0\n"
        "    bl DigitFont_DrawNumber\n"
        ".L080CD294:\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080CD29C: .4byte gUnknown_084F00E0\n"
    );
}
#endif

// Status_DrawDemonDescription @ 0x080CD2A0
/* Draws the two description lines of demon id: 11 glyphs from record +0x32, then up to 11
   glyphs from +0x48 (0 ends it) 15 pixels lower. */
void Status_DrawDemonDescription(u16 id, u16 x, u16 y)
{
    u32 cx = x;
    u32 y2 = y + 15;
    u16 *line1 = (u16 *)(Demon_GetRecord(id) + 0x32);
    u16 *line2 = (u16 *)(Demon_GetRecord(id) + 0x48);
    s32 i;

    for (i = 10; i >= 0; i--)
    {
        Font_DrawGlyph(*line1, gUnk_0200F874, cx, y);
        cx += 12;
        line1++;
    }
    cx = x;
    for (i = 0; i <= 10 && *line2 != 0; i++)
    {
        Font_DrawGlyph(*line2, gUnk_0200F874, cx, y2);
        cx += 12;
        line2++;
    }
}

// sub_080CD330 @ 0x080CD330
void sub_080CD330(u16 item, u16 x, u16 y, u16 tint)
{
    u32 x2 = x + 0x18;
    u8 v = Item_GetRecord(item)[1];

    DigitFont_DrawAscii(gUnknown_084F02DC, x, y, tint);
    DigitFont_DrawNumber(v, x2, y, tint);
}

// sub_080CD38C @ 0x080CD38C
void sub_080CD38C(u16 item, u16 x, u16 y, u16 tint)
{
    u32 x2 = x + 0x18;
    u8 v = Item_GetRecord(item)[2];

    DigitFont_DrawAscii(gUnknown_084F02DC, x, y, tint);
    DigitFont_DrawNumber(v, x2, y, tint);
}
