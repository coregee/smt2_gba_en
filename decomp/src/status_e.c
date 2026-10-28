#include "global.h"
#include "status.h"


// sub_080CC4B4 @ 0x080CC4B4
/* Draws the eight derived stats, coloured by comparison with old (8 higher, 10 lower). */
void sub_080CC4B4(struct Combatant *old)
{
    struct Combatant *c = Status_GetCombatant(gMenuState.sel);
    u16 tint;

    tint = 4;
    if (c->derived[0] > old->derived[0])
        tint = 8;
    else if (c->derived[0] < old->derived[0])
        tint = 10;
    DigitFont_DrawNumber(c->derived[0], 0xE6, 0x1F, tint);
    tint = 4;
    if (c->derived[1] > old->derived[1])
        tint = 8;
    else if (c->derived[1] < old->derived[1])
        tint = 10;
    DigitFont_DrawNumber(c->derived[1], 0xE6, 0x2C, tint);
    tint = 4;
    if (c->derived[2] > old->derived[2])
        tint = 8;
    else if (c->derived[2] < old->derived[2])
        tint = 10;
    DigitFont_DrawNumber(c->derived[2], 0xE6, 0x39, tint);
    tint = 4;
    if (c->derived[3] > old->derived[3])
        tint = 8;
    else if (c->derived[3] < old->derived[3])
        tint = 10;
    DigitFont_DrawNumber(c->derived[3], 0xE6, 0x46, tint);
    tint = 4;
    if (c->derived[4] > old->derived[4])
        tint = 8;
    else if (c->derived[4] < old->derived[4])
        tint = 10;
    DigitFont_DrawNumber(c->derived[4], 0xE6, 0x53, tint);
    tint = 4;
    if (c->derived[5] > old->derived[5])
        tint = 8;
    else if (c->derived[5] < old->derived[5])
        tint = 10;
    DigitFont_DrawNumber(c->derived[5], 0xE6, 0x60, tint);
    tint = 4;
    if (c->derived[6] > old->derived[6])
        tint = 8;
    else if (c->derived[6] < old->derived[6])
        tint = 10;
    DigitFont_DrawNumber(c->derived[6], 0xE6, 0x6D, tint);
    tint = 4;
    if (c->derived[7] > old->derived[7])
        tint = 8;
    else if (c->derived[7] < old->derived[7])
        tint = 10;
    DigitFont_DrawNumber(c->derived[7], 0xE6, 0x7A, tint);
}

// sub_080CC630 @ 0x080CC630
/* Previews the stats with the selected item equipped. */
#ifdef NONMATCHING
void sub_080CC630(u32 a, struct Task *t)
{
    struct C0c6Status *st = &gMenuState;
    struct Combatant *c = Status_GetCombatant(st->sel);
    struct Combatant *saved = &st->saved;

    CpuSet(c, saved, 0x04000020);
    Combatant_SetEquip(c->id, st->unk30, gUnk_0203B454[st->unk2C + st->unk2E]);
    Combatant_RecalcStats(c->id);
    sub_080CC4B4(saved);
    CpuSet(saved, c, 0x04000020);
}
#else
NAKED
void sub_080CC630(u32 a, struct Task *t)
{
    asm_unified(
        ".L080CC630:\n"
        "    push {r4, r5, r6, lr}\n"
        "    mov r6, r8\n"
        "    push {r6}\n"
        "    ldr r4, .L080CC688\n"
        "    ldrh r0, [r4, #2]\n"
        "    bl Status_GetCombatant\n"
        "    adds r5, r0, #0\n"
        "    adds r6, r4, #0\n"
        "    adds r6, #0xd4\n"
        "    ldr r0, .L080CC68C\n"
        "    mov r8, r0\n"
        "    adds r0, r5, #0\n"
        "    adds r1, r6, #0\n"
        "    mov r2, r8\n"
        "    bl CpuSet\n"
        "    ldr r2, .L080CC690\n"
        "    ldrh r0, [r4, #0x2c]\n"
        "    ldrh r1, [r4, #0x2e]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r2, [r0]\n"
        "    ldrh r1, [r4, #0x30]\n"
        "    ldrb r0, [r5, #0xc]\n"
        "    bl Combatant_SetEquip\n"
        "    ldrb r0, [r5, #0xc]\n"
        "    bl Combatant_RecalcStats\n"
        "    adds r0, r6, #0\n"
        "    bl sub_080CC4B4\n"
        "    adds r0, r6, #0\n"
        "    adds r1, r5, #0\n"
        "    mov r2, r8\n"
        "    bl CpuSet\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080CC688: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L080CC68C: .4byte 0x04000020 @ REG_BG2PA\n"
        ".L080CC690: .4byte 0x0203B454 @ EWRAM+0x3B454\n"
    );
}
#endif

// sub_080CC694 @ 0x080CC694
/* The HP/MP block: full HP/MP of the (recalculated) combatant against the saved one. */
void sub_080CC694(u32 a, struct Task *t)
{
    struct C0c6Status *st = &gMenuState;
    struct Combatant *c = Status_GetCombatant(st->sel);
    u16 tint;

    Combatant_RecalcStats(c->id);
    c->hp = c->maxHp;
    c->mp = c->maxMp;
    if (st->mode == 5)
    {
        CpuSet(c, &st->demon, 0x04000020);
        c->equip[0] = 0xFF;
        c->equip[1] = 0xFF;
        c->equip[2] = 0xFF;
        c->equip[3] = 0xFF;
        c->equip[4] = 0xFF;
        c->equip[5] = 0xFF;
        c->equip[6] = 0xFF;
        c->pad27 = 0xFF;
        Combatant_RecalcStats(c->id);
        sub_080CC4B4(&st->preview);
    }
    else
        sub_080CC4B4(&st->saved);
    Canvas_FillRect(0, gUnk_0200F874, 0x40, 0x1C, 0x60, 0x18);
    tint = 4;
    if (c->maxHp > st->saved.maxHp)
        tint = 8;
    else if (c->maxHp < st->saved.maxHp)
        tint = 10;
    SmallFont_DrawNumber(c->hp, 0x60, 0x20, tint);
    SmallFont_DrawAscii(gUnknown_084F00DC, 0x68, 0x20, tint);
    SmallFont_DrawNumber(c->maxHp, 0x80, 0x20, tint);
    tint = 4;
    if (c->maxMp > st->saved.maxMp)
        tint = 8;
    else if (c->maxMp < st->saved.maxMp)
        tint = 10;
    SmallFont_DrawNumber(c->mp, 0x60, 0x2C, tint);
    SmallFont_DrawAscii(gUnknown_084F00DC, 0x68, 0x2C, tint);
    SmallFont_DrawNumber(c->maxMp, 0x80, 0x2C, tint);
    if (st->mode == 5)
        CpuSet(&st->demon, c, 0x04000020);
}

// sub_080CC7D4 @ 0x080CC7D4
/* Draws six fixed label glyphs of the bottom window. */
void sub_080CC7D4(void)
{
    Font_DrawGlyph(0x10CB, gUnk_0200F874, 8, 0x8A);
    Font_DrawGlyph(0xCBA, gUnk_0200F874, 0x55, 0x8A);
    Font_DrawGlyph(0xFC3, gUnk_0200F874, 0xA2, 0x8A);
    Font_DrawGlyph(0xC5C, gUnk_0200F874, 8, 0x98);
    Font_DrawGlyph(0xC3C, gUnk_0200F874, 0x55, 0x98);
    Font_DrawGlyph(0x606, gUnk_0200F874, 0xA2, 0x98);
}

// sub_080CC844 @ 0x080CC844
/* The six base stats in the bottom window (palette 8 when boosted); with status bit 0x800 a
   fixed 1/1/1/1/40/1, for unknown demons "?". */
void sub_080CC844(u32 a, struct Task *t)
{
    struct Combatant *c = Status_GetCombatant(gMenuState.sel);
    u16 flags;
    u16 tint;

    sub_080CC7D4();
    if (sub_080C92AC(c->demonId) == 1 || sub_080C99B8(c) == 0)
    {
        flags = c->flags;
        if (gMenuState.mode == 7)
            flags = Stock_FindByDemonId(c->demonId)->flags;
        if (flags & 0x800)
        {
            DigitFont_DrawNumber(1, 0x48, 0x8D, 0);
            DigitFont_DrawNumber(1, 0x95, 0x8D, 0);
            DigitFont_DrawNumber(1, 0xE2, 0x8D, 0);
            DigitFont_DrawNumber(1, 0x48, 0x9A, 0);
            DigitFont_DrawNumber(0x28, 0x95, 0x9A, 0);
            DigitFont_DrawNumber(1, 0xE2, 0x9A, 0);
        }
        else
        {
            tint = (s8)c->base[0] != (s8)c->total[0] ? 8 : 0;
            DigitFont_DrawNumber((s8)c->total[0], 0x48, 0x8D, tint);
            tint = (s8)c->base[1] != (s8)c->total[1] ? 8 : 0;
            DigitFont_DrawNumber((s8)c->total[1], 0x95, 0x8D, tint);
            tint = (s8)c->base[2] != (s8)c->total[2] ? 8 : 0;
            DigitFont_DrawNumber((s8)c->total[2], 0xE2, 0x8D, tint);
            tint = (s8)c->base[3] != (s8)c->total[3] ? 8 : 0;
            DigitFont_DrawNumber((s8)c->total[3], 0x48, 0x9A, tint);
            tint = (s8)c->base[4] != (s8)c->total[4] ? 8 : 0;
            DigitFont_DrawNumber((s8)c->total[4], 0x95, 0x9A, tint);
            tint = (s8)c->base[5] != (s8)c->total[5] ? 8 : 0;
            DigitFont_DrawNumber((s8)c->total[5], 0xE2, 0x9A, tint);
        }
    }
    else
    {
        DigitFont_DrawAscii(gUnknown_084EFAD8, 0x3F, 0x8D, 0);
        DigitFont_DrawAscii(gUnknown_084EFAD8, 0x8C, 0x8D, 0);
        DigitFont_DrawAscii(gUnknown_084EFAD8, 0xD9, 0x8D, 0);
        DigitFont_DrawAscii(gUnknown_084EFAD8, 0x3F, 0x9A, 0);
        DigitFont_DrawAscii(gUnknown_084EFAD8, 0x8C, 0x9A, 0);
        DigitFont_DrawAscii(gUnknown_084EFAD8, 0xD9, 0x9A, 0);
    }
}

// sub_080CCA10 @ 0x080CCA10
/* The help lines of the bottom window for the hero (sub_080C93B4) or another human. */
void sub_080CCA10(u32 a, struct Task *t)
{
    struct C0c6Status *st = &gMenuState;

    Status_GetCombatant(st->sel);
    if (sub_080C93B4(st->sel) == 1)
    {
        SmallFont_DrawAscii(gUnknown_084F01B8, 0xA, 0x8E, 0);
        SmallFont_DrawAscii(gUnknown_084F01C0, 0x42, 0x8E, 0);
        SmallFont_DrawAscii(gUnknown_084F01C8, 0xA, 0x9A, 0);
        SmallFont_DrawAscii(gUnknown_084F01C0, 0x42, 0x9A, 0);
        SmallFont_DrawAscii(gUnknown_084F01D0, 0x88, 0x8E, 0);
        SmallFont_DrawAscii(gUnknown_084F01C0, 0xC0, 0x8E, 0);
        SmallFont_DrawAscii(gUnknown_084F01D8, 0x88, 0x9A, 0);
        st->unk2C = 0;
    }
    else if (sub_080C9388(st->sel) == 1)
    {
        SmallFont_DrawAscii(gUnknown_084F01E4, 0xA, 0x8E, 0);
        st->unk2C = 0;
    }
}

// sub_080CCAB4 @ 0x080CCAB4
/* The detail lines of the selected item: labels are fixed glyph codes. Items 0x58-0x6F show a
   fixed string instead of sub_080CD50C's value. */
void sub_080CCAB4(u32 a, struct Task *t)
{
    struct C0c6Status *st = &gMenuState;
    u16 item;

    Status_GetCombatant(st->sel);
    item = gUnk_0203B454[st->unk2C + st->unk2E];
    if (item <= 0x7F)
    {
        Font_DrawGlyph(0x8F1, gUnk_0200F874, 9, 0x8B);
        Font_DrawGlyph(0x861, gUnk_0200F874, 0x15, 0x8B);
        sub_080CD330(item, 0x24, 0x8E, 4);
        Font_DrawGlyph(0xFFE, gUnk_0200F874, 9, 0x98);
        Font_DrawGlyph(0xCD3, gUnk_0200F874, 0x15, 0x98);
        sub_080CD38C(item, 0x24, 0x9B, 4);
        Font_DrawGlyph(0x8F1, gUnk_0200F874, 0x49, 0x8B);
        Font_DrawGlyph(0x861, gUnk_0200F874, 0x55, 0x8B);
        Font_DrawGlyph(0x699, gUnk_0200F874, 0x61, 0x8B);
        Font_DrawGlyph(0xB67, gUnk_0200F874, 0x6D, 0x8B);
        sub_080CD3E8(item, 0x95, 0x8E, 4);
        if ((u16)(item - 0x58) < 0x18)
        {
            Font_DrawGlyph(0xD14, gUnk_0200F874, 0x49, 0x98);
            Font_DrawGlyph(0x669, gUnk_0200F874, 0x55, 0x98);
            Font_DrawGlyph(0x8D7, gUnk_0200F874, 0x61, 0x98);
            Font_DrawGlyph(0x672, gUnk_0200F874, 0x6D, 0x98);
            DigitFont_DrawAscii(gUnknown_084F01EC, 0x7E, 0x9B, 4);
        }
        else
        {
            Font_DrawGlyph(0xD14, gUnk_0200F874, 0x49, 0x98);
            Font_DrawGlyph(0x669, gUnk_0200F874, 0x55, 0x98);
            Font_DrawGlyph(0x8D7, gUnk_0200F874, 0x61, 0x98);
            Font_DrawGlyph(0x672, gUnk_0200F874, 0x6D, 0x98);
            sub_080CD50C(item, 0x7E, 0x9B);
        }
        Font_DrawGlyph(0xC3E, gUnk_0200F874, 0xB2, 0x8B);
        Font_DrawGlyph(0xB7E, gUnk_0200F874, 0xBE, 0x8B);
        sub_080CD45C(item, 0xCC, 0x8E);
    }
    else
    {
        Font_DrawGlyph(0xFA9, gUnk_0200F874, 9, 0x8B);
        Font_DrawGlyph(0x8C3, gUnk_0200F874, 0x15, 0x8B);
        sub_080CD668(item, 0x24, 0x8E, 4);
        Font_DrawGlyph(0x699, gUnk_0200F874, 9, 0x98);
        Font_DrawGlyph(0xEB7, gUnk_0200F874, 0x15, 0x98);
        sub_080CD6C4(item, 0x24, 0x9B, 4);
        Font_DrawGlyph(0xC1A, gUnk_0200F874, 0x49, 0x8B);
        Font_DrawGlyph(0xB7E, gUnk_0200F874, 0x55, 0x8B);
        sub_080CD87C(item, 0x65, 0x8B);
        Font_DrawGlyph(0xD14, gUnk_0200F874, 0x49, 0x98);
        Font_DrawGlyph(0x669, gUnk_0200F874, 0x55, 0x98);
        Font_DrawGlyph(0x8D7, gUnk_0200F874, 0x61, 0x98);
        Font_DrawGlyph(0x672, gUnk_0200F874, 0x6D, 0x98);
        sub_080CD720(item, 0x7E, 0x9B);
        Font_DrawGlyph(0xC3E, gUnk_0200F874, 0xB3, 0x8B);
        Font_DrawGlyph(0xB7E, gUnk_0200F874, 0xBE, 0x8B);
        sub_080CD45C(item, 0xCC, 0x8E);
    }
}

// sub_080CCD5C @ 0x080CCD5C
/* The six base stats (palette 8 when boosted), without the special cases of sub_080CC844. */
void sub_080CCD5C(u32 a, struct Task *t)
{
    struct Combatant *c = Status_GetCombatant(gMenuState.sel);
    u16 tint;

    sub_080CC7D4();
    tint = (s8)c->base[0] != (s8)c->total[0] ? 8 : 0;
    DigitFont_DrawNumber((s8)c->total[0], 0x48, 0x8D, tint);
    tint = (s8)c->base[1] != (s8)c->total[1] ? 8 : 0;
    DigitFont_DrawNumber((s8)c->total[1], 0x95, 0x8D, tint);
    tint = (s8)c->base[2] != (s8)c->total[2] ? 8 : 0;
    DigitFont_DrawNumber((s8)c->total[2], 0xE2, 0x8D, tint);
    tint = (s8)c->base[3] != (s8)c->total[3] ? 8 : 0;
    DigitFont_DrawNumber((s8)c->total[3], 0x48, 0x9A, tint);
    tint = (s8)c->base[4] != (s8)c->total[4] ? 8 : 0;
    DigitFont_DrawNumber((s8)c->total[4], 0x95, 0x9A, tint);
    tint = (s8)c->base[5] != (s8)c->total[5] ? 8 : 0;
    DigitFont_DrawNumber((s8)c->total[5], 0xE2, 0x9A, tint);
}
