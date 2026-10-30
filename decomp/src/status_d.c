#include "global.h"
#include "status.h"

// sub_080CB71C @ 0x080CB71C
/* The equipment page: the seven equipment slots. */
void sub_080CB71C(u32 a, struct Task *t)
{
    struct Combatant *c = Status_GetCombatant(gMenuState.sel);

    Status_DrawEquipName(c->equip[0], 0x24, 0x1C, 0);
    Status_DrawEquipName(c->equip[1], 0x24, 0x2B, 0);
    Status_DrawEquipName(c->equip[2], 0x24, 0x3A, 0);
    Status_DrawEquipName(c->equip[3], 0x24, 0x49, 0);
    Status_DrawEquipName(c->equip[4], 0x24, 0x58, 0);
    Status_DrawEquipName(c->equip[5], 0x24, 0x67, 0);
    Status_DrawEquipName(c->equip[6], 0x24, 0x76, 0);
}

// sub_080CB7A0 @ 0x080CB7A0
/* The item list page (7 rows from st->unk2E): name, a count prefix and the count; equipped
   items in palette 6, unusable ones in palette 2. Counts over 99 move the prefix left. */
#ifdef NONMATCHING
void sub_080CB7A0(u32 a, struct Task *t)
{
    u32 y = 0x1C;
    struct Combatant *c = Status_GetCombatant(gMenuState.sel);
    u32 i;
    u32 y2 = 0x1F << 16;

    for (i = 0; i < 7; i++)
    {
        u16 tint = 0;
        u16 id = gUnk_0203B454[gMenuState.unk2E + i];
        u32 cy;
        u8 n;

        if (id == 0xFFFF)
            continue;
        if (id <= 0xCF)
        {
            if ((u16)Combatant_GetEquipSlot(c, gMenuState.unk30) == id)
            {
                tint = 6;
                SmallFont_DrawAscii(gUnknown_084F019C, 2, y + 2, 6);
                cy = y + 2;
            }
            else
            {
                cy = y + 2;
                if (Equip_CanEquip(c->id, id) != 1)
                    tint = 2;
            }
            Status_DrawEquipName(id & 0x7FFF, 10, y, tint);
        }
        else
        {
            Status_DrawActionName(id, 10, y, 0);
            cy = y + 2;
        }
        n = Inventory_GetCount(id);
        if (n > 99)
            SmallFont_DrawAscii(gUnknown_084F01A0, 0x6D, y2 >> 16, tint);
        else
            SmallFont_DrawAscii(gUnknown_084F01A0, 0x75, y2 >> 16, tint);
        DigitFont_DrawNumber(n, 0x87, (u16)cy, tint);
        y2 += 15 << 16;
        y += 15;
    }
}
#else
NAKED
void sub_080CB7A0(u32 a, struct Task *t)
{
    asm_unified(
        ".L080CB7A0:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #4\n"
        "    movs r0, #0x1c\n"
        "    mov r8, r0\n"
        "    ldr r1, .L080CB808\n"
        "    ldrh r0, [r1, #2]\n"
        "    bl Status_GetCombatant\n"
        "    str r0, [sp]\n"
        "    movs r2, #0\n"
        "    mov sl, r2\n"
        "    movs r0, #0xf8\n"
        "    lsls r0, r0, #0xd\n"
        "    mov sb, r0\n"
        ".L080CB7C4:\n"
        "    movs r7, #0\n"
        "    ldr r0, .L080CB80C\n"
        "    ldr r2, .L080CB808\n"
        "    ldrh r1, [r2, #0x2e]\n"
        "    add r1, sl\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r0\n"
        "    ldrh r5, [r1]\n"
        "    ldr r0, .L080CB810\n"
        "    cmp r5, r0\n"
        "    beq .L080CB8AA\n"
        "    cmp r5, #0xcf\n"
        "    bhi .L080CB84C\n"
        "    ldrh r1, [r2, #0x30]\n"
        "    ldr r0, [sp]\n"
        "    bl Combatant_GetEquipSlot\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, r5\n"
        "    bne .L080CB818\n"
        "    movs r7, #6\n"
        "    mov r4, r8\n"
        "    adds r4, #2\n"
        "    lsls r2, r4, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    ldr r0, .L080CB814\n"
        "    movs r1, #2\n"
        "    movs r3, #6\n"
        "    bl SmallFont_DrawAscii\n"
        "    adds r6, r4, #0\n"
        "    b .L080CB82E\n"
        "    .byte 0x00, 0x00\n"
        ".L080CB808: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L080CB80C: .4byte 0x0203B454 @ EWRAM+0x3B454\n"
        ".L080CB810: .4byte 0x0000FFFF\n"
        ".L080CB814: .4byte gUnknown_084F019C\n"
        ".L080CB818:\n"
        "    ldr r1, [sp]\n"
        "    ldrb r0, [r1, #0xc]\n"
        "    lsls r1, r5, #0x18\n"
        "    lsrs r1, r1, #0x18\n"
        "    bl Equip_CanEquip\n"
        "    mov r6, r8\n"
        "    adds r6, #2\n"
        "    cmp r0, #1\n"
        "    beq .L080CB82E\n"
        "    movs r7, #2\n"
        ".L080CB82E:\n"
        "    ldr r2, .L080CB848\n"
        "    adds r1, r2, #0\n"
        "    adds r0, r5, #0\n"
        "    ands r0, r1\n"
        "    mov r1, r8\n"
        "    lsls r2, r1, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    movs r1, #0xa\n"
        "    adds r3, r7, #0\n"
        "    bl Status_DrawEquipName\n"
        "    lsls r4, r5, #0x10\n"
        "    b .L080CB862\n"
        ".L080CB848: .4byte 0x00007FFF\n"
        ".L080CB84C:\n"
        "    lsls r4, r5, #0x10\n"
        "    lsrs r0, r4, #0x10\n"
        "    mov r1, r8\n"
        "    lsls r2, r1, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    movs r1, #0xa\n"
        "    movs r3, #0\n"
        "    bl Status_DrawActionName\n"
        "    mov r6, r8\n"
        "    adds r6, #2\n"
        ".L080CB862:\n"
        "    lsrs r0, r4, #0x10\n"
        "    bl Inventory_GetCount\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    cmp r4, #0x63\n"
        "    bls .L080CB884\n"
        "    mov r0, sb\n"
        "    lsrs r2, r0, #0x10\n"
        "    ldr r0, .L080CB880\n"
        "    movs r1, #0x6d\n"
        "    adds r3, r7, #0\n"
        "    bl SmallFont_DrawAscii\n"
        "    b .L080CB892\n"
        ".L080CB880: .4byte gUnknown_084F01A0\n"
        ".L080CB884:\n"
        "    mov r1, sb\n"
        "    lsrs r2, r1, #0x10\n"
        "    ldr r0, .L080CB8C4\n"
        "    movs r1, #0x75\n"
        "    adds r3, r7, #0\n"
        "    bl SmallFont_DrawAscii\n"
        ".L080CB892:\n"
        "    lsls r2, r6, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0x87\n"
        "    adds r3, r7, #0\n"
        "    bl DigitFont_DrawNumber\n"
        "    movs r2, #0xf0\n"
        "    lsls r2, r2, #0xc\n"
        "    add sb, r2\n"
        "    movs r0, #0xf\n"
        "    add r8, r0\n"
        ".L080CB8AA:\n"
        "    movs r1, #1\n"
        "    add sl, r1\n"
        "    mov r2, sl\n"
        "    cmp r2, #6\n"
        "    bls .L080CB7C4\n"
        "    add sp, #4\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080CB8C4: .4byte gUnknown_084F01A0\n"
    );
}
#endif

// sub_080CB8C8 @ 0x080CB8C8
/* The skill list page (7 rows): name and cost. */
void sub_080CB8C8(u32 a, struct Task *t)
{
    struct C0c6Status *st = &gMenuState;
    u32 y = 0x1C;
    u32 i = 0;
    u16 *list = gUnk_0203B454;

loop:
    {
        u16 id = list[i + st->unk2E];

        if (id != 0xFFFF)
        {
            u32 skill = id & 0xFF;

            Status_DrawSkillName(skill, 10, y);
            sub_080CD260(skill, 0x6C, 0x87, y + 3);
        }
    }
    y += 15;
    i++;
    if (i <= 6)
        goto loop;
}

// sub_080CB928 @ 0x080CB928
/* The skills page: up to 7 skills below 0x40, then up to 7 others (filtered by sub_0812C4E0
   for stock demons), then blank rows up to 7. */
void sub_080CB928(u32 a, struct Task *t)
{
    struct C0c6Status *m = &gMenuState;
    struct Combatant *c = Status_GetCombatant(m->sel);
    u32 drawn = 0;
    u32 y = 0x1E;
    u32 filter = 0;
    u32 dy = 14;
    u8 *skills;
    u32 i;
    u32 y0;
    u8 s;
    u8 s0;

    if (m->mode == 7)
    {
        skills = Stock_FindByDemonId(c->demonId)->skills;
        filter = 1;
    }
    else if (m->mode != 6)
    {
        skills = c->skills;
        if (m->mode != 1)
            filter = 1;
    }
    else
    {
        skills = gUnk_0203B860;
        filter = 1;
    }
    m->unk12 = 0;
    m->unk14 = 0;
    y0 = y;
    for (i = 0; i < 7 && (s0 = skills[i]) != 0xFF; i++)
    {
        if (s0 <= 0x3F)
        {
            Status_DrawSkillName(s0, 0x24, y);
            y += dy;
            drawn++;
        }
    }
    if (y != y0)
        m->unk12 = y0 - 8;
    y0 = y;
    for (i = 0; i < 7 && (s = skills[i]) != 0xFF; i++)
    {
        if (filter == 1)
        {
            if (s > 0x3F && sub_0812C4E0(s, c->demonId) == 0)
            {
                Status_DrawSkillName(s, 0x24, y);
                y += dy;
                drawn++;
            }
        }
        else if (s > 0x3F)
        {
            Status_DrawSkillName(s, 0x24, y);
            y += dy;
            drawn++;
        }
    }
    if (y != y0)
        m->unk14 = y0 - 8;
    drawn = 7 - drawn;
    if (drawn != 0)
    {
        for (i = 0; i < drawn; i++)
        {
            Text_DrawStringTinted(gUnknown_084F01A2, gUnk_0200F874, 0x24, (u16)y, 2, 12);
            y += dy;
        }
    }
}

// Status_DrawDropItem @ 0x080CBA7C
/* The drop page: the demon's item (record +0x1A; 0xFF: a fixed 6-glyph "none" text drawn
   glyph by glyph, x 0x0C-0x54). */
void Status_DrawDropItem(u32 a, struct Task *t)
{
    struct Combatant *c = Status_GetCombatant(gMenuState.sel);
    u16 item = *(u16 *)(Demon_GetRecord(c->demonId) + 0x1A);
    u16 item2 = item;

    Status_DrawDemonDescription(c->demonId, 0xC, 0x1C);
    if ((item & 0xFF) == 0xFF)
    {
        Font_DrawGlyphTinted(0xEA, gUnk_0200F874, 0xC, 0x49, 6);
        Font_DrawGlyphTinted(0xEB, gUnk_0200F874, 0x18, 0x49, 6);
        Font_DrawGlyphTinted(0xE5, gUnk_0200F874, 0x30, 0x49, 6);
        Font_DrawGlyphTinted(0xF0, gUnk_0200F874, 0x3C, 0x49, 6);
        Font_DrawGlyphTinted(0xE1, gUnk_0200F874, 0x48, 0x49, 6);
        Font_DrawGlyphTinted(0xE9, gUnk_0200F874, 0x54, 0x49, 6);
    }
    else if (item <= 0xCF)
        Status_DrawEquipName(item & 0xFF, 0xC, 0x49, 6);
    else
        Status_DrawActionName(item2 & 0x1FF, 0xC, 0x49, 6);
}

// sub_080CBB34 @ 0x080CBB34
/* Draws the stat labels of the stats page from fixed glyph codes. */
void sub_080CBB34(void)
{
    Status_GetCombatant(gMenuState.sel);
    Font_DrawGlyph(0x8F1, gUnk_0200F874, 0xB2, 0x1C);
    Font_DrawGlyph(0x861, gUnk_0200F874, 0xBE, 0x1C);
    Font_DrawGlyph(0xFFE, gUnk_0200F874, 0xB2, 0x29);
    Font_DrawGlyph(0xCD3, gUnk_0200F874, 0xBE, 0x29);
    Font_DrawGlyph(0x8F1, gUnk_0200F874, 0xB2, 0x36);
    Font_DrawGlyph(0x861, gUnk_0200F874, 0xBE, 0x36);
    Font_DrawGlyph(0xFFE, gUnk_0200F874, 0xB2, 0x43);
    Font_DrawGlyph(0xCD3, gUnk_0200F874, 0xBE, 0x43);
    Font_DrawGlyph(0xFA9, gUnk_0200F874, 0xA4, 0x50);
    Font_DrawGlyph(0x8C3, gUnk_0200F874, 0xB0, 0x50);
    Font_DrawGlyph(0x699, gUnk_0200F874, 0xA4, 0x5D);
    Font_DrawGlyph(0xEB7, gUnk_0200F874, 0xB0, 0x5D);
    Font_DrawGlyph(0xFC3, gUnk_0200F874, 0xA4, 0x6A);
    Font_DrawGlyph(0xF81, gUnk_0200F874, 0xB0, 0x6A);
    Font_DrawGlyph(0x5BB, gUnk_0200F874, 0xBC, 0x6A);
    Font_DrawGlyph(0x10CB, gUnk_0200F874, 0xC8, 0x6A);
    Font_DrawGlyph(0xFC3, gUnk_0200F874, 0xA4, 0x77);
    Font_DrawGlyph(0xF81, gUnk_0200F874, 0xB0, 0x77);
    Font_DrawGlyph(0x8D7, gUnk_0200F874, 0xBC, 0x77);
    Font_DrawGlyph(0x672, gUnk_0200F874, 0xC8, 0x77);
}
