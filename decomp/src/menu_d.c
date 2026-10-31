#include "global.h"
#include "menu.h"

/* Value colour on the status preview: 8 when the previewed stat is higher than before, 10 when lower. */
#define DRAW_STAT(cur, old, x, y)   \
{                                   \
    color = 4;                      \
    if ((cur) > (old))              \
        color = 8;                  \
    else if ((cur) < (old))         \
        color = 10;                 \
    DigitFont_DrawNumber(cur, x, y, color); \
}

/* NONMATCHING: the mode load/copy order differs and the window+0x24 argument is built in another register. */
// sub_080D2028 @ 0x080D2028
#ifdef NONMATCHING
void sub_080D2028(void)
{
    struct StatusMenu *menu = STATUS_MENU;
    u16 mode = menu->mode;

    if (mode == 0)
        Tilemap_FillRect(0, gWindowTilemapBuffer, 1, 7, 0x1C, 4);
    else if (mode == 1)
    {
        if (menu->window18 != 0)
        {
            Tilemap_FillRect(0, gWindowTilemapBuffer, 0x13, 7, 10, 4);
            Window_Close((u32)menu->window18, 1);
            menu->window18 = 0;
        }
        if (menu->window14 == 0)
        {
            menu->window14 = (struct Window *)TextWindow_CreateOpenWithFrame(1, 7, 0x1C, 4, mode, gUnknown_084F310C);
            TextWindow_DrawFrame(menu->window14->unk24, 1, 7, 0x1C, 4);
        }
    }
    else if (mode == 2)
    {
        if (menu->window14 != 0)
        {
            Tilemap_FillRect(0, gWindowTilemapBuffer, 1, 7, 0x1C, 4);
            Window_Close((u32)menu->window14, 1);
            menu->window14 = 0;
        }
        if (menu->window18 == 0)
        {
            menu->window18 = (struct Window *)TextWindow_CreateOpenWithFrame(0x13, 7, 10, 4, 1, gUnknown_084F310C);
            TextWindow_DrawFrame(menu->window18->unk24, 0x13, 7, 10, 4);
        }
    }
    else if ((u16)(menu->mode - 3) < 2)
    {
        if (menu->window18 != 0)
        {
            Tilemap_FillRect(0, gWindowTilemapBuffer, 0x13, 7, 10, 4);
            Window_Close((u32)menu->window18, 1);
            menu->window18 = 0;
        }
        if (menu->window14 == 0)
        {
            if (menu->mode == 3)
            {
                menu->window14 = (struct Window *)TextWindow_CreateOpenWithFrame(14, 4, 15, 4, 1, gUnknown_084F310C);
                TextWindow_DrawFrame(menu->window14->unk24, 14, 4, 15, 4);
            }
            else
            {
                menu->window14 = (struct Window *)TextWindow_CreateOpenWithFrame(14, 0, 15, 11, 1, gUnknown_084F310C);
                TextWindow_DrawFrame(menu->window14->unk24, 14, 1, 15, 10);
            }
        }
    }
}
#else
NAKED
void sub_080D2028(void)
{
    asm_unified(
        ".L080D2028:\n"
        "    push {r4, r5, lr}\n"
        "    sub sp, #8\n"
        "    ldr r5, .L080D204C\n"
        "    ldrh r0, [r5]\n"
        "    adds r4, r0, #0\n"
        "    cmp r4, #0\n"
        "    bne .L080D2054\n"
        "    ldr r1, .L080D2050\n"
        "    movs r0, #0x1c\n"
        "    str r0, [sp]\n"
        "    movs r0, #4\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r2, #1\n"
        "    movs r3, #7\n"
        "    bl Tilemap_FillRect\n"
        "    b .L080D21B6\n"
        ".L080D204C: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L080D2050: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080D2054:\n"
        "    cmp r4, #1\n"
        "    bne .L080D20B8\n"
        "    ldr r0, [r5, #0x18]\n"
        "    cmp r0, #0\n"
        "    beq .L080D207E\n"
        "    ldr r1, .L080D20B0\n"
        "    movs r0, #0xa\n"
        "    str r0, [sp]\n"
        "    movs r0, #4\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r2, #0x13\n"
        "    movs r3, #7\n"
        "    bl Tilemap_FillRect\n"
        "    ldr r0, [r5, #0x18]\n"
        "    movs r1, #1\n"
        "    bl Window_Close\n"
        "    movs r0, #0\n"
        "    str r0, [r5, #0x18]\n"
        ".L080D207E:\n"
        "    ldr r0, [r5, #0x14]\n"
        "    cmp r0, #0\n"
        "    beq .L080D2086\n"
        "    b .L080D21B6\n"
        ".L080D2086:\n"
        "    str r4, [sp]\n"
        "    ldr r0, .L080D20B4\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #1\n"
        "    movs r1, #7\n"
        "    movs r2, #0x1c\n"
        "    movs r3, #4\n"
        "    bl TextWindow_CreateOpenWithFrame\n"
        "    str r0, [r5, #0x14]\n"
        "    adds r1, r0, #0\n"
        "    adds r1, #0x24\n"
        "    movs r0, #4\n"
        "    str r0, [sp]\n"
        "    adds r0, r1, #0\n"
        "    movs r1, #1\n"
        "    movs r2, #7\n"
        "    movs r3, #0x1c\n"
        "    bl TextWindow_DrawFrame\n"
        "    b .L080D21B6\n"
        ".L080D20B0: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080D20B4: .4byte gUnknown_084F310C\n"
        ".L080D20B8:\n"
        "    cmp r4, #2\n"
        "    bne .L080D211C\n"
        "    ldr r0, [r5, #0x14]\n"
        "    cmp r0, #0\n"
        "    beq .L080D20E2\n"
        "    ldr r1, .L080D2114\n"
        "    movs r0, #0x1c\n"
        "    str r0, [sp]\n"
        "    movs r0, #4\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r2, #1\n"
        "    movs r3, #7\n"
        "    bl Tilemap_FillRect\n"
        "    ldr r0, [r5, #0x14]\n"
        "    movs r1, #1\n"
        "    bl Window_Close\n"
        "    movs r0, #0\n"
        "    str r0, [r5, #0x14]\n"
        ".L080D20E2:\n"
        "    ldr r0, [r5, #0x18]\n"
        "    cmp r0, #0\n"
        "    bne .L080D21B6\n"
        "    movs r0, #1\n"
        "    str r0, [sp]\n"
        "    ldr r0, .L080D2118\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #0x13\n"
        "    movs r1, #7\n"
        "    movs r2, #0xa\n"
        "    movs r3, #4\n"
        "    bl TextWindow_CreateOpenWithFrame\n"
        "    str r0, [r5, #0x18]\n"
        "    adds r1, r0, #0\n"
        "    adds r1, #0x24\n"
        "    movs r0, #4\n"
        "    str r0, [sp]\n"
        "    adds r0, r1, #0\n"
        "    movs r1, #0x13\n"
        "    movs r2, #7\n"
        "    movs r3, #0xa\n"
        "    bl TextWindow_DrawFrame\n"
        "    b .L080D21B6\n"
        ".L080D2114: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080D2118: .4byte gUnknown_084F310C\n"
        ".L080D211C:\n"
        "    subs r0, #3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bhi .L080D21B6\n"
        "    ldr r0, [r5, #0x18]\n"
        "    cmp r0, #0\n"
        "    beq .L080D214C\n"
        "    ldr r1, .L080D2184\n"
        "    movs r0, #0xa\n"
        "    str r0, [sp]\n"
        "    movs r0, #4\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r2, #0x13\n"
        "    movs r3, #7\n"
        "    bl Tilemap_FillRect\n"
        "    ldr r0, [r5, #0x18]\n"
        "    movs r1, #1\n"
        "    bl Window_Close\n"
        "    movs r0, #0\n"
        "    str r0, [r5, #0x18]\n"
        ".L080D214C:\n"
        "    ldr r0, [r5, #0x14]\n"
        "    cmp r0, #0\n"
        "    bne .L080D21B6\n"
        "    ldrh r0, [r5]\n"
        "    cmp r0, #3\n"
        "    bne .L080D218C\n"
        "    movs r0, #1\n"
        "    str r0, [sp]\n"
        "    ldr r0, .L080D2188\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #0xe\n"
        "    movs r1, #4\n"
        "    movs r2, #0xf\n"
        "    movs r3, #4\n"
        "    bl TextWindow_CreateOpenWithFrame\n"
        "    str r0, [r5, #0x14]\n"
        "    adds r1, r0, #0\n"
        "    adds r1, #0x24\n"
        "    movs r0, #4\n"
        "    str r0, [sp]\n"
        "    adds r0, r1, #0\n"
        "    movs r1, #0xe\n"
        "    movs r2, #4\n"
        "    movs r3, #0xf\n"
        "    bl TextWindow_DrawFrame\n"
        "    b .L080D21B6\n"
        ".L080D2184: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080D2188: .4byte gUnknown_084F310C\n"
        ".L080D218C:\n"
        "    movs r0, #1\n"
        "    str r0, [sp]\n"
        "    ldr r0, .L080D21C0\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #0xe\n"
        "    movs r1, #0\n"
        "    movs r2, #0xf\n"
        "    movs r3, #0xb\n"
        "    bl TextWindow_CreateOpenWithFrame\n"
        "    str r0, [r5, #0x14]\n"
        "    adds r1, r0, #0\n"
        "    adds r1, #0x24\n"
        "    movs r0, #0xa\n"
        "    str r0, [sp]\n"
        "    adds r0, r1, #0\n"
        "    movs r1, #0xe\n"
        "    movs r2, #1\n"
        "    movs r3, #0xf\n"
        "    bl TextWindow_DrawFrame\n"
        ".L080D21B6:\n"
        "    add sp, #8\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080D21C0: .4byte gUnknown_084F310C\n"
    );
}
#endif

// sub_080D21C4 @ 0x080D21C4
void sub_080D21C4(u16 *a, u16 *b)
{
    switch (STATUS_MENU->mode)
    {
    case 0:
    case 2:
        *a = 1;
        *b = 9;
        break;
    case 1:
        *a = 1;
        *b = 5;
        break;
    }
}

// sub_080D21F8 @ 0x080D21F8
void sub_080D21F8(void)
{
    u16 x, y;

    if ((u16)(STATUS_MENU->mode - 3) > 1)
    {
        Tilemap_FillRect(0, gWindowTilemapBuffer, 1, 5, 8, 2);
        sub_080D21C4(&x, &y);
        Tilemap_CopyRectSkipZero(gUnknown_081B8170, gWindowTilemapBuffer, 0, 0, x, y, 8, 2);
        sub_080C6764();
    }
}

// sub_080D2268 @ 0x080D2268
/* Maps an ID to one of seven ranges (0..6). */
u32 sub_080D2268(u16 id)
{
    u32 ret = 0;

    if (id > 0x57)
    {
        ret = 1;
        if (id > 0x6F)
        {
            ret = 6;
            if (id > 0x7F)
            {
                ret = 2;
                if (id > 0x93)
                {
                    ret = 3;
                    if (id > 0xA7)
                    {
                        ret = 5;
                        if (id <= 0xBB)
                            ret = 4;
                    }
                }
            }
        }
    }
    return ret & 0xFF;
}

// sub_080D229C @ 0x080D229C
u32 sub_080D229C(u16 id, u8 *combatant)
{
    u16 range = sub_080D2268(id);
    u16 ret = Combatant_GetEquip(combatant[0xC], range) & 0xFF;

    return ret;
}

// StatsPage_DrawLabelGrid @ 0x080D22C0
/* The labels are drawn glyph by glyph with fixed 12-pixel spacing. */
void StatsPage_DrawLabelGrid(void)
{
    struct StatusMenu *menu = STATUS_MENU;
    u8 *c = Party_GetMember(menu->member + 0x8000);
    u16 id = menu->id;

    sub_080D229C(id, c);
    if (id < 0x80)
    {
        Font_DrawGlyph(0x8F1, gUnk_0200F874, 0x0F, 0);
        Font_DrawGlyph(0x861, gUnk_0200F874, 0x1B, 0);
        sub_080CD330(id, 0x2B, 3, 4);
        Font_DrawGlyph(0xFFE, gUnk_0200F874, 0x51, 0);
        Font_DrawGlyph(0xCD3, gUnk_0200F874, 0x5D, 0);
        sub_080CD38C(id, 0x6F, 3, 4);
        Font_DrawGlyph(0x8F1, gUnk_0200F874, 0x95, 0);
        Font_DrawGlyph(0x861, gUnk_0200F874, 0xA1, 0);
        Font_DrawGlyph(0x699, gUnk_0200F874, 0xAD, 0);
        Font_DrawGlyph(0xB67, gUnk_0200F874, 0xB9, 0);
        sub_080CD3E8(id, 0xCB, 3, 4);
        Font_DrawGlyph(0xD14, gUnk_0200F874, 0x0F, 13);
        Font_DrawGlyph(0x669, gUnk_0200F874, 0x1B, 13);
        Font_DrawGlyph(0x8D7, gUnk_0200F874, 0x27, 13);
        Font_DrawGlyph(0x672, gUnk_0200F874, 0x33, 13);
        sub_080CD50C(id, 0x50, 0x10);
        Font_DrawGlyph(0xC3E, gUnk_0200F874, 0x94, 13);
        Font_DrawGlyph(0xB7E, gUnk_0200F874, 0xA0, 13);
        sub_080CD45C(id, 0xB0, 0x10);
    }
    else
    {
        Font_DrawGlyph(0xFA9, gUnk_0200F874, 0x0F, 0);
        Font_DrawGlyph(0x8C3, gUnk_0200F874, 0x1B, 0);
        sub_080CD668(id, 0x2B, 3, 4);
        Font_DrawGlyph(0x699, gUnk_0200F874, 0x51, 0);
        Font_DrawGlyph(0xEB7, gUnk_0200F874, 0x5D, 0);
        sub_080CD6C4(id, 0x6F, 3, 4);
        Font_DrawGlyph(0xC1A, gUnk_0200F874, 0x94, 0);
        Font_DrawGlyph(0xB7E, gUnk_0200F874, 0xA0, 0);
        sub_080CD8C4(id, 0xB4, 0);
        Font_DrawGlyph(0xD14, gUnk_0200F874, 0x0F, 13);
        Font_DrawGlyph(0x669, gUnk_0200F874, 0x1B, 13);
        Font_DrawGlyph(0x8D7, gUnk_0200F874, 0x27, 13);
        Font_DrawGlyph(0x672, gUnk_0200F874, 0x33, 13);
        sub_080CD720(id, 0x50, 0x10);
        Font_DrawGlyph(0xC3E, gUnk_0200F874, 0x94, 13);
        Font_DrawGlyph(0xB7E, gUnk_0200F874, 0xA0, 13);
        sub_080CD45C(id, 0xB4, 0x10);
    }
}

// StatsPage_ApplyPreview @ 0x080D2508
/* Backs up the combatant record, then applies the stats of `id` to it for preview. */
void StatsPage_ApplyPreview(u8 *combatant, u16 id)
{
    struct StatusMenu *menu = STATUS_MENU;
    u16 range = sub_080D2268(id);

    CpuSet(combatant, &menu->backup, 0x04000020);
    Combatant_SetEquip(combatant[0xC], range, id);
    Combatant_RecalcStats(combatant[0xC]);
}

// StatsPage_RestoreCombatant @ 0x080D2554
void StatsPage_RestoreCombatant(u8 *combatant)
{
    struct StatusMenu *menu = STATUS_MENU;

    CpuSet(&menu->backup, combatant, 0x04000020);
}

// StatsPage_DrawBaseStats @ 0x080D2570
void StatsPage_DrawBaseStats(void)
{
    s32 yBias = 0x8B;  /* the original keeps this in a register; 0x8E - yBias == 3 */
    struct StatusMenu *menu = STATUS_MENU;
    struct PartyMember *c = (struct PartyMember *)Party_GetMember(menu->member + 0x8000);
    u16 id = menu->id;
    u32 color;

    sub_080D229C(id, (u8 *)c);
    StatsPage_ApplyPreview((u8 *)c, id);
    Font_DrawGlyph(0x10CB, gUnk_0200F874, 0x0F, 1);
    DRAW_STAT(c->stats[0], menu->backup.stats[0], 0x24, 0x8E - yBias);
    Font_DrawGlyph(0xCBA, gUnk_0200F874, 0x33, 0x8C - yBias);
    DRAW_STAT(c->stats[1], menu->backup.stats[1], 0x48, 0x8E - yBias);
    Font_DrawGlyph(0xFC3, gUnk_0200F874, 0x57, 0x8C - yBias);
    DRAW_STAT(c->stats[2], menu->backup.stats[2], 0x6c, 0x8E - yBias);
    Font_DrawGlyph(0xC5C, gUnk_0200F874, 0x7e, 0x8C - yBias);
    DRAW_STAT(c->stats[3], menu->backup.stats[3], 0x93, 0x8E - yBias);
    Font_DrawGlyph(0xC3C, gUnk_0200F874, 0xa2, 0x8C - yBias);
    DRAW_STAT(c->stats[4], menu->backup.stats[4], 0xb7, 0x8E - yBias);
    Font_DrawGlyph(0x606, gUnk_0200F874, 0xc6, 0x8C - yBias);
    DRAW_STAT(c->stats[5], menu->backup.stats[5], 0xdb, 0x8E - yBias);
    StatsPage_RestoreCombatant((u8 *)c);
}


// StatsPage_DrawDerivedStats @ 0x080D2788
void StatsPage_DrawDerivedStats(void)
{
    s32 yBias = 0x8B;
    struct StatusMenu *menu = STATUS_MENU;
    struct PartyMember *c = (struct PartyMember *)Party_GetMember(menu->member + 0x8000);
    u16 id = menu->id;
    u32 color;

    sub_080D229C(id, (u8 *)c);
    StatsPage_ApplyPreview((u8 *)c, id);
    Font_DrawGlyph(0x8F1, gUnk_0200F874, 0x1D, 1);
    Font_DrawGlyph(0x861, gUnk_0200F874, 0x29, 1);
    DRAW_STAT(c->unk48[0], menu->backup.unk48[0], 0x47, 0x8E - yBias);
    Font_DrawGlyph(0xFFE, gUnk_0200F874, 0x1D, 0x98 - yBias);
    Font_DrawGlyph(0xCD3, gUnk_0200F874, 0x29, 0x98 - yBias);
    DRAW_STAT(c->unk48[1], menu->backup.unk48[1], 0x47, 0x9A - yBias);
    Font_DrawGlyph(0x8F1, gUnk_0200F874, 0x68, 0x8C - yBias);
    Font_DrawGlyph(0x861, gUnk_0200F874, 0x74, 0x8C - yBias);
    DRAW_STAT(c->unk48[2], menu->backup.unk48[2], 0x92, 0x8E - yBias);
    Font_DrawGlyph(0xFFE, gUnk_0200F874, 0x68, 0x98 - yBias);
    Font_DrawGlyph(0xCD3, gUnk_0200F874, 0x74, 0x98 - yBias);
    DRAW_STAT(c->unk48[3], menu->backup.unk48[3], 0x92, 0x9A - yBias);
    StatsPage_RestoreCombatant((u8 *)c);
}

// StatsPage_DrawDerivedStats2 @ 0x080D295C
void StatsPage_DrawDerivedStats2(void)
{
    s32 yBias = 0x8B;
    struct StatusMenu *menu = STATUS_MENU;
    struct PartyMember *c = (struct PartyMember *)Party_GetMember(menu->member + 0x8000);
    u16 id = menu->id;
    u32 color;

    sub_080D229C(id, (u8 *)c);
    StatsPage_ApplyPreview((u8 *)c, id);
    Font_DrawGlyph(0xFC3, gUnk_0200F874, 0x0F, 1);
    Font_DrawGlyph(0xF81, gUnk_0200F874, 0x1B, 1);
    Font_DrawGlyph(0x5BB, gUnk_0200F874, 0x27, 1);
    Font_DrawGlyph(0x10CB, gUnk_0200F874, 0x33, 1);
    DRAW_STAT(c->unk50[2], menu->backup.unk50[2], 0x51, 0x8E - yBias);
    Font_DrawGlyph(0xFC3, gUnk_0200F874, 0x0F, 0x98 - yBias);
    Font_DrawGlyph(0xF81, gUnk_0200F874, 0x1B, 0x98 - yBias);
    Font_DrawGlyph(0x8D7, gUnk_0200F874, 0x27, 0x98 - yBias);
    Font_DrawGlyph(0x672, gUnk_0200F874, 0x33, 0x98 - yBias);
    DRAW_STAT(c->unk50[3], menu->backup.unk50[3], 0x51, 0x9A - yBias);
    Font_DrawGlyph(0xFA9, gUnk_0200F874, 0x68, 0x8C - yBias);
    Font_DrawGlyph(0x8C3, gUnk_0200F874, 0x74, 0x8C - yBias);
    DRAW_STAT(c->unk50[0], menu->backup.unk50[0], 0x92, 0x8E - yBias);
    Font_DrawGlyph(0x699, gUnk_0200F874, 0x68, 0x98 - yBias);
    Font_DrawGlyph(0xEB7, gUnk_0200F874, 0x74, 0x98 - yBias);
    DRAW_STAT(c->unk50[1], menu->backup.unk50[1], 0x92, 0x9A - yBias);
    StatsPage_RestoreCombatant((u8 *)c);
}

// Menu_DrawItemNameTriple @ 0x080D2B70
/* Item names are drawn as exactly 8 glyphs. */
void Menu_DrawItemNameTriple()
{
    struct StatusMenu *menu = STATUS_MENU;
    u16 *name;
    u16 x, y;
    u16 i, j;

    Text_DrawStringTinted(gUnknown_084F311E, gUnk_0200F874, 0, 1, 4, 12);
    for (i = 0; i < 3; i++)
    {
        u16 item = menu->items[i];

        if (item == 0xFFFF)
            continue;
        if (item < 0xD0)
            name = (u16 *)(Item_GetRecord(item) + 0x14);
        else
            name = (u16 *)(Action_GetRecord(item) + 0xC);
        switch (i)
        {
        case 0:
            x = 0;
            y = 13;
            break;
        case 1:
            x = 0x80;
            y = 0;
            break;
        case 2:
            x = 0x80;
            y = 13;
            break;
        }
        for (j = 0; j < 8; j++)
            Font_DrawGlyphTinted(name[j], gUnk_0200F874, x + j * 12, y, 0);
    }
}

// Menu_DrawSkillRowTriple @ 0x080D2C44
/* Skill names are drawn as exactly 8 glyphs. */
void Menu_DrawSkillRowTriple()
{
    struct StatusMenu *menu = STATUS_MENU;
    u16 *name;
    u16 x, y;
    u16 i, j;

    Text_DrawStringTinted(gUnknown_084F312C, gUnk_0200F874, 0, 1, 4, 12);
    for (i = 0; i < 3; i++)
    {
        u16 item = menu->items[i];

        if (item == 0xFFFF)
            continue;
        name = (u16 *)(Demon_GetRecord(item) + 0x22);
        switch (i)
        {
        case 0:
            x = 0;
            y = 13;
            break;
        case 1:
            x = 0x80;
            y = 0;
            break;
        case 2:
            x = 0x80;
            y = 13;
            break;
        }
        for (j = 0; j < 8; j++)
            Font_DrawGlyphTinted(name[j], gUnk_0200F874, x + j * 12, y, 0);
    }
}

/* Number of line breaks (0x300) in the description of action `id`. */
// Action_CountDescriptionBreaks @ 0x080D2D04
u16 Action_CountDescriptionBreaks(u16 id)
{
    u16 *desc = *(u16 **)(Action_GetRecord(id) + 0x1C);
    u16 n = 0;

    if (id <= 0xD0)
        return 0;
    if (desc == NULL)
        return 0;
    while (*desc != 0 && *desc != 0x301)
    {
        if (*desc == 0x300)
            n++;
        desc++;
    }
    return n;
}

// sub_080D2D58 @ 0x080D2D58
void sub_080D2D58(void)
{
    DigitFont_DrawAscii(gUnknown_084F313C, 0x9E, 14, 0);
    DigitFont_DrawNumber(gUnk_0203DB2C, 0xDE, 14, 0);
}

/* Page 0 of a two-page description is drawn glyph by glyph up to the second 0x300 line break;
   page 1 starts after it. Neither loop stops at 0x0000/0x0301, so a two-page description must
   contain two 0x300 codes. */
// Item_RenderDescription @ 0x080D2D80
void Item_RenderDescription(u32 arg0)
{
    struct StatusMenu *menu = STATUS_MENU;
    u32 zero = 0;
    u16 *desc;
    u16 x, y;
    u32 lineH;
    u16 n;
    u16 left;

    CpuSet(&zero, gUnk_0200F874, 0x05000400);
    sub_080D1F0C();
    gUnk_03003BB4 = 0;
    if (menu->mode == 0)
        return;
    if (menu->mode == 2)
    {
        SmallFont_DrawAscii(gUnknown_084F3140, 0x99, 2, 0);
        sub_080D2D58();
        sub_080D1F0C();
    }
    else if (menu->mode == 3)
    {
        Menu_DrawItemNameTriple(arg0);
        sub_080D1F0C();
    }
    else if (menu->mode == 4)
    {
        Menu_DrawSkillRowTriple(arg0);
        sub_080D1F0C();
    }
    else
    {
        if (menu->id < 0xD0)
        {
            switch (menu->unk02)
            {
            case 0:
                StatsPage_DrawLabelGrid();
                break;
            case 1:
                StatsPage_DrawBaseStats();
                break;
            case 2:
                StatsPage_DrawDerivedStats();
                break;
            case 3:
                StatsPage_DrawDerivedStats2();
                break;
            }
        }
        else
        {
            desc = *(u16 **)(Action_GetRecord(menu->id) + 0x1C);
            x = 9;
            y = 0;
            lineH = 12;
            if (desc != NULL)
            {
                if (menu->pageCount < 2)
                    Text_DrawString(desc, gUnk_0200F874, 9, 0, lineH);
                else if (menu->page == 0)
                {
                    n = 0;
                    left = 9;
                    if (*desc != 0x300)
                        goto draw;
                    n = 1;
                    do
                    {
                        x = left;
                        y += lineH;
                        desc++;
                        while (*desc != 0x300)
                        {
                        draw:
                            Font_DrawGlyph(*desc, gUnk_0200F874, x, y);
                            desc++;
                            x += lineH;
                        }
                        n++;
                    } while (n != 2);
                }
                else
                {
                    u16 lines = 0;

                    if (*desc == 0x300)
                        lines = 1;
                skip:
                    desc++;
                    if (*desc != 0x300)
                        goto skip;
                    if (++lines != 2)
                        goto skip;
                    desc++;
                    Text_DrawString(desc, gUnk_0200F874, x, y, lineH);
                }
            }
        }
        sub_080D1F0C();
    }
}
