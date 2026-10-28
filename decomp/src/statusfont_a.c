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
#ifdef NONMATCHING
void Status_DrawEquipName(u16 id, u16 x, u16 y, u16 tint)
{
    s32 i;
    u32 cx = x;

    if (id == 0xFF)
    {
        Text_DrawStringTinted(gUnknown_084F02CA, gUnk_0200F874, cx, y, 2, 12);
    }
    else
    {
        u16 *name = (u16 *)(Equipment_GetRecord36_MidRange(id) + 0x14);

        if (*name == 0)
        {
            for (i = 7; i >= 0; i--)
            {
                Font_DrawGlyphTinted(0x3C, gUnk_0200F874, cx, y, 2);
                cx += 12;
            }
        }
        else
        {
            for (i = 7; i >= 0; i--)
            {
                Font_DrawGlyphTinted(*name, gUnk_0200F874, cx, y, (u8)tint);
                cx += 12;
                name++;
            }
        }
    }
}
#else
NAKED
void Status_DrawEquipName(u16 id, u16 x, u16 y, u16 tint)
{
    asm_unified(
        ".L080CD100:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    sub sp, #8\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r7, r2, #0x10\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r6, r3, #0x10\n"
        "    lsrs r4, r1, #0x10\n"
        "    cmp r0, #0xff\n"
        "    bne .L080CD13C\n"
        "    ldr r0, .L080CD134\n"
        "    ldr r1, .L080CD138\n"
        "    adds r2, r4, #0\n"
        "    movs r3, #2\n"
        "    str r3, [sp]\n"
        "    movs r3, #0xc\n"
        "    str r3, [sp, #4]\n"
        "    adds r3, r7, #0\n"
        "    bl Text_DrawStringTinted\n"
        "    b .L080CD190\n"
        "    .byte 0x00, 0x00\n"
        ".L080CD134: .4byte gUnknown_084F02CA\n"
        ".L080CD138: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L080CD13C:\n"
        "    bl Equipment_GetRecord36_MidRange\n"
        "    adds r5, r0, #0\n"
        "    adds r5, #0x14\n"
        "    ldrh r0, [r0, #0x14]\n"
        "    cmp r0, #0\n"
        "    bne .L080CD16C\n"
        "    movs r5, #7\n"
        ".L080CD14C:\n"
        "    lsls r2, r4, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    movs r0, #2\n"
        "    str r0, [sp]\n"
        "    movs r0, #0x3c\n"
        "    ldr r1, .L080CD168\n"
        "    adds r3, r7, #0\n"
        "    bl Font_DrawGlyphTinted\n"
        "    adds r4, #0xc\n"
        "    subs r5, #1\n"
        "    cmp r5, #0\n"
        "    bge .L080CD14C\n"
        "    b .L080CD190\n"
        ".L080CD168: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L080CD16C:\n"
        "    lsls r6, r6, #0x18\n"
        "    mov r8, r6\n"
        "    movs r6, #7\n"
        ".L080CD172:\n"
        "    ldrh r0, [r5]\n"
        "    lsls r2, r4, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    mov r3, r8\n"
        "    lsrs r1, r3, #0x18\n"
        "    str r1, [sp]\n"
        "    ldr r1, .L080CD19C\n"
        "    adds r3, r7, #0\n"
        "    bl Font_DrawGlyphTinted\n"
        "    adds r4, #0xc\n"
        "    adds r5, #2\n"
        "    subs r6, #1\n"
        "    cmp r6, #0\n"
        "    bge .L080CD172\n"
        ".L080CD190:\n"
        "    add sp, #8\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080CD19C: .4byte 0x0200F874 @ EWRAM+0xF874\n"
    );
}
#endif

// Status_DrawActionName @ 0x080CD1A0
/* Draws the name of item/action id (8 glyphs). */
#ifdef NONMATCHING
void Status_DrawActionName(u16 id, u16 x, u16 y, u16 tint)
{
    u16 *name = (u16 *)(Action_GetRecord(id) + 0xC);
    s32 i;
    u32 cx = x;

    if (*name != 0)
    {
        for (i = 7; i >= 0; i--)
        {
            Font_DrawGlyphTinted(*name, gUnk_0200F874, cx, y, (u8)tint);
            x += 12;
            name++;
        }
    }
}
#else
NAKED
void Status_DrawActionName(u16 id, u16 x, u16 y, u16 tint)
{
    asm_unified(
        ".L080CD1A0:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    sub sp, #4\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    mov r8, r2\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r6, r3, #0x10\n"
        "    lsrs r5, r1, #0x10\n"
        "    bl Action_GetRecord\n"
        "    adds r4, r0, #0\n"
        "    adds r4, #0xc\n"
        "    ldrh r0, [r0, #0xc]\n"
        "    cmp r0, #0\n"
        "    beq .L080CD1E8\n"
        "    lsls r7, r6, #0x18\n"
        "    movs r6, #7\n"
        ".L080CD1CC:\n"
        "    ldrh r0, [r4]\n"
        "    lsls r2, r5, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    lsrs r1, r7, #0x18\n"
        "    str r1, [sp]\n"
        "    ldr r1, .L080CD1F4\n"
        "    mov r3, r8\n"
        "    bl Font_DrawGlyphTinted\n"
        "    adds r5, #0xc\n"
        "    adds r4, #2\n"
        "    subs r6, #1\n"
        "    cmp r6, #0\n"
        "    bge .L080CD1CC\n"
        ".L080CD1E8:\n"
        "    add sp, #4\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080CD1F4: .4byte 0x0200F874 @ EWRAM+0xF874\n"
    );
}
#endif

// Status_DrawSkillName @ 0x080CD1F8
/* Draws the name of skill id (8 glyphs; empty: 8 glyphs 0x3C). */
#ifdef NONMATCHING
void Status_DrawSkillName(u16 id, u16 x, u16 y)
{
    u16 *name = (u16 *)(sub_080BF5C0(id) + 6);
    s32 i;
    u32 cx = x;

    if (*name == 0)
    {
        for (i = 7; i >= 0; i--)
        {
            Font_DrawGlyphTinted(0x3C, gUnk_0200F874, cx, y, 2);
            x += 12;
        }
    }
    else
    {
        for (i = 7; i >= 0; i--)
        {
            Font_DrawGlyph(*name, gUnk_0200F874, cx, y);
            x += 12;
            name++;
        }
    }
}
#else
NAKED
void Status_DrawSkillName(u16 id, u16 x, u16 y)
{
    asm_unified(
        ".L080CD1F8:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    sub sp, #4\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r7, r2, #0x10\n"
        "    lsrs r4, r1, #0x10\n"
        "    bl sub_080BF5C0\n"
        "    adds r5, r0, #6\n"
        "    ldrh r0, [r0, #6]\n"
        "    cmp r0, #0\n"
        "    bne .L080CD238\n"
        "    movs r5, #7\n"
        ".L080CD216:\n"
        "    lsls r2, r4, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    movs r0, #2\n"
        "    str r0, [sp]\n"
        "    movs r0, #0x3c\n"
        "    ldr r1, .L080CD234\n"
        "    adds r3, r7, #0\n"
        "    bl Font_DrawGlyphTinted\n"
        "    adds r4, #0xc\n"
        "    subs r5, #1\n"
        "    cmp r5, #0\n"
        "    bge .L080CD216\n"
        "    b .L080CD252\n"
        "    .byte 0x00, 0x00\n"
        ".L080CD234: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L080CD238:\n"
        "    movs r6, #7\n"
        ".L080CD23A:\n"
        "    ldrh r0, [r5]\n"
        "    lsls r2, r4, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    ldr r1, .L080CD25C\n"
        "    adds r3, r7, #0\n"
        "    bl Font_DrawGlyph\n"
        "    adds r4, #0xc\n"
        "    adds r5, #2\n"
        "    subs r6, #1\n"
        "    cmp r6, #0\n"
        "    bge .L080CD23A\n"
        ".L080CD252:\n"
        "    add sp, #4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080CD25C: .4byte 0x0200F874 @ EWRAM+0xF874\n"
    );
}
#endif

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
