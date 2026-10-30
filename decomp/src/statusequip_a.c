#include "global.h"
#include "options.h"

// sub_080CD3E8 @ 0x080CD3E8
/* NONMATCHING: the last call takes y and tint from second copies (sb, r8) that no spelling tried reproduces. */
void sub_080CD3E8(u16 item, u16 x, u16 y, u16 tint)
{
    s32 x2 = x + 16;
    u8 kind = Item_GetRecord(item)[3];

    if (kind == 0xF)
        DigitFont_DrawAscii(gUnknown_084F0320, x, y, tint);
    else if (kind <= 1)
        DigitFont_DrawAscii(gUnknown_084F02DE + kind * 4, x2, y, tint);
    else
        DigitFont_DrawAscii(gUnknown_084F02DE + kind * 4, x2 - 16, y, tint); /* = x */
}

// sub_080CD45C @ 0x080CD45C
/* The separate copies of x and y used by the last case reproduce the original register use. */
void sub_080CD45C(u16 item, u16 x, u16 y)
{
    s32 attr;
    u16 x6 = x;
    u16 y6 = y;
    s32 x2 = x + 16;

    Item_GetAttribute(item, 1, &attr);
    attr &= 7;
    if (attr == 1)
        DigitFont_DrawAscii(gUnknown_084F02C0, x2, y, 4);
    else if (attr == 2)
        DigitFont_DrawAscii(gUnknown_084F02C4, x2, y, 4);
    else if (attr == 4)
        DigitFont_DrawAscii(gUnknown_084F02C8, x2, y, 4);
    else if (attr == 7)
        DigitFont_DrawAscii(gUnknown_084F0320, x, y, 4);
    else if (attr == 3)
        DigitFont_DrawAscii(gUnknown_084F0324, x + 8, y, 4);
    else if (attr == 6)
        DigitFont_DrawAscii(gUnknown_084F0328, x6 + 8, y6, 4);
}

// sub_080CD50C @ 0x080CD50C
void sub_080CD50C(u16 item, u16 x, u16 y)
{
    s32 x8 = x + 8;
    s32 x16 = x + 16;
    s32 x24 = x + 24;
    u8 *rec = Item_GetRecord(item);
    u16 *flags = (u16 *)(rec + 8);

    if (*flags & 0x8000)
        DigitFont_DrawAscii(gUnknown_084F0194, x16, y, 4);
    else if (*flags & 0x2000)
        DigitFont_DrawAscii(gUnknown_084F00F0, x8, y, 4);
    else if (*flags & 0x1000)
        DigitFont_DrawAscii(gUnknown_084F00F8, x, y, 4);
    else if (*flags & 4)
        DigitFont_DrawAscii(gUnknown_084F0100, x, y, 4);
    else if (*flags & 0x800)
        DigitFont_DrawAscii(gUnknown_084F0108, x24, y, 4);
    else if (*flags & 0x4000)
        DigitFont_DrawAscii(gUnknown_084F010C, x, y, 4);
    else if (*flags & 0x200)
        DigitFont_DrawAscii(gUnknown_084F011C, x8, y, 4);
    else if (*flags & 0x40)
        DigitFont_DrawAscii(gUnknown_084F0124, x8, y, 4);
    else if (*flags & 0x20)
        DigitFont_DrawAscii(gUnknown_084F012C, x16, y, 4);
    else if (*flags & 0x100)
        DigitFont_DrawAscii(gUnknown_084F0134, x, y, 4);
    else if (*flags & 0x80)
        DigitFont_DrawAscii(gUnknown_084F013C, x8, y, 4);
    else if (*flags & 2)
        DigitFont_DrawAscii(gUnknown_084F0144, x8, y, 4);
    else if (*flags & 0x10)
        DigitFont_DrawAscii(gUnknown_084F014C, x8, y, 4);
    else if (*flags & 8)
        DigitFont_DrawAscii(gUnknown_084F0154, x8, y, 4);
    else
        DigitFont_DrawAscii(gUnknown_084F01EC, x, y, 4);
}

// sub_080CD668 @ 0x080CD668
/* NONMATCHING: register allocation (x and the x+N temporary swap registers). */
void sub_080CD668(u16 item, u16 x, u16 y, u16 tint)
{
    s32 x2 = x + 24;
    u8 v = Equipment_GetRecord36_MidRange(item)[1];

    DigitFont_DrawAscii(gUnknown_084F02DC, x2 - 24, y, tint); /* = x */
    DigitFont_DrawNumber(v, x2, y, tint);
}

// sub_080CD6C4 @ 0x080CD6C4
/* NONMATCHING: register allocation (x and the x+N temporary swap registers). */
void sub_080CD6C4(u16 item, u16 x, u16 y, u16 tint)
{
    s32 x2 = x + 24;
    u8 v = Equipment_GetRecord36_MidRange(item)[2];

    DigitFont_DrawAscii(gUnknown_084F02DC, x2 - 24, y, tint); /* = x */
    DigitFont_DrawNumber(v, x2, y, tint);
}

// sub_080CD720 @ 0x080CD720
void sub_080CD720(u16 item, u16 x, u16 y)
{
    s32 x8 = x + 8;
    s32 x16 = x + 16;
    s32 x24 = x + 24;
    u8 *rec = Equipment_GetRecord36_MidRange(item);
    u16 *flags = (u16 *)(rec + 8);

    if (*flags & 0x8000)
        DigitFont_DrawAscii(gUnknown_084F0194, x16, y, 4);
    else if (*flags & 0x2000)
        DigitFont_DrawAscii(gUnknown_084F00F0, x8, y, 4);
    else if (*flags & 0x1000)
        DigitFont_DrawAscii(gUnknown_084F00F8, x, y, 4);
    else if (*flags & 4)
        DigitFont_DrawAscii(gUnknown_084F0100, x, y, 4);
    else if (*flags & 0x800)
        DigitFont_DrawAscii(gUnknown_084F0108, x24, y, 4);
    else if (*flags & 0x4000)
        DigitFont_DrawAscii(gUnknown_084F010C, x, y, 4);
    else if (*flags & 0x200)
        DigitFont_DrawAscii(gUnknown_084F011C, x8, y, 4);
    else if (*flags & 0x40)
        DigitFont_DrawAscii(gUnknown_084F0124, x8, y, 4);
    else if (*flags & 0x20)
        DigitFont_DrawAscii(gUnknown_084F012C, x16, y, 4);
    else if (*flags & 0x100)
        DigitFont_DrawAscii(gUnknown_084F0134, x, y, 4);
    else if (*flags & 0x80)
        DigitFont_DrawAscii(gUnknown_084F013C, x8, y, 4);
    else if (*flags & 2)
        DigitFont_DrawAscii(gUnknown_084F0144, x8, y, 4);
    else if (*flags & 0x10)
        DigitFont_DrawAscii(gUnknown_084F014C, x8, y, 4);
    else if (*flags & 8)
        DigitFont_DrawAscii(gUnknown_084F0154, x8, y, 4);
    else
        DigitFont_DrawAscii(gUnknown_084F01EC, x, y, 4);
}

// sub_080CD87C @ 0x080CD87C
void sub_080CD87C(u16 item, u16 x, u16 y)
{
    Text_DrawStringTinted(gUnknown_084F032C[Equipment_GetRecord36_MidRange(item)[3]], gUnk_0200F874, x, y, 4, 12);
}

// sub_080CD8C4 @ 0x080CD8C4
void sub_080CD8C4(u16 item, u16 x, u16 y)
{
    Text_DrawStringTinted(gUnknown_084F06D6[Equipment_GetRecord36_MidRange(item)[3]], gUnk_0200F874, x, y, 4, 12);
}

// sub_080CD90C @ 0x080CD90C
/* Draws a gauge n pixels long: n/8 full 8-pixel cells, then a partial cell. */
void sub_080CD90C(u16 n, u16 x, u16 pal, u16 y, u16 tile)
{
    u16 full, rest, i;

    if (n == 0)
        return;
    full = n >> 3;
    rest = n & 7;
    if (full != 0)
    {
        for (i = 0; i < full; i++)
        {
            Sprite_Draw(gUnknown_084F0974[7], 1, pal, 1, x + 0x200, y, tile);
            y += 8;
        }
    }
    if (rest != 0)
        Sprite_Draw(gUnknown_084F0974[rest - 1], 1, pal, 1, x + 0x200, y, tile);
}

// sub_080CD9C8 @ 0x080CD9C8
void sub_080CD9C8(u16 a, u16 b, u16 c, u16 d, u16 y, u16 tile)
{
    struct C0c6Status *m = &gMenuState;
    u16 scroll;
    u16 total = 0;

    a &= 0xFF;
    b &= 0xFF;
    c &= 0xFF;
    d &= 0xFF;
    if (m->hofs == 0)
        scroll = gUnk_03000004;
    else
        scroll = m->hofs;
    sub_080CD90C(a, 0, 0, y - scroll, tile);
    y += a;
    total += a;
    if (total + b > 0x28)
        b = 0x28 - total;
    sub_080CD90C(b, 0, 0xFFF9, y - scroll, tile);
    y += b;
    total += b;
    if (total + c > 0x28)
        c = 0x28 - total;
    sub_080CD90C(c, 0, 0xFFF8, y - scroll, tile);
    y += c;
    total += c;
    if (total + d > 0x28)
        d = 0x28 - total;
    sub_080CD90C(d, 0x20, 0xFFF9, y - scroll, tile);
}

// sub_080CDAE4 @ 0x080CDAE4
s32 sub_080CDAE4(s16 align, s32 attr)
{
    switch (attr)
    {
    case 0xC0:
        return TRUE;
    case 0x80:
        if (align == 0)
            return TRUE;
        break;
    case 0x40:
        if (align == 1)
            return TRUE;
        break;
    }
    return FALSE;
}

// sub_080CDB18 @ 0x080CDB18
s32 sub_080CDB18(u32 kind, s32 attr)
{
    switch (attr)
    {
    case 1:
        if (kind == 0)
            return TRUE;
        break;
    case 2:
        if (kind == 1)
            return TRUE;
        break;
    case 4:
        if (kind == 2)
            return TRUE;
        break;
    case 3:
        if (kind <= 1)
            return TRUE;
        break;
    case 6:
        if (kind - 1 <= 1)
            return TRUE;
        break;
    case 7:
        return TRUE;
    }
    return FALSE;
}

// Equip_CanEquip @ 0x080CDB74
s32 Equip_CanEquip(s32 who, u8 item)
{
    s32 attr0, attr1;
    u16 align;
    s32 kind;

    Item_GetAttribute(item, 0, &attr0);
    Item_GetAttribute(item, 1, &attr1);
    align = sub_080C07FC(who);
    kind = Combatant_GetAlignment(who);
    if (sub_080CDAE4(align, attr0) == TRUE && sub_080CDB18(kind, attr1 & 7) == TRUE)
        return TRUE;
    return FALSE;
}

// sub_080CDBD4 @ 0x080CDBD4
void sub_080CDBD4(void)
{
    struct C0c6Status *m = &gMenuState;
    u16 zero = 0;

    m->page = 1;
    m->unk06 = zero;
    m->unk08 = zero;
    m->unk30 = zero;
}

// sub_080CDBE8 @ 0x080CDBE8
void sub_080CDBE8(u16 lo, u16 hi)
{
    vu16 fill;
    struct C0c6Status *m = &gMenuState;

    Status_GetCombatant(m->sel);
    fill = 0xFFFF;
    CpuSet((void *)&fill, gUnk_0203B454, 0x01000080);
    m->unk28 = Inventory_ListRange(lo, hi);
}

// Hud_InvalidateGauges @ 0x080CDC34
void Hud_InvalidateGauges(void)
{
    u32 i;

    for (i = 0; i < 6; i++)
    {
        gUnk_0200F7D8[i][0] = 0x5000;
        gUnk_0200F7D8[i][1] = 0x5000;
    }
}

// sub_080CDC54 @ 0x080CDC54
/* Equipment screen input: A equips from the slot list, B leaves, L/R change member, up/down the slot. */
void sub_080CDC54(struct Task *t)
{
    struct C0c6Status *m = &gMenuState;
    struct Combatant *c = Status_GetCombatant(m->sel);
    u32 count = sub_080C964C(0);
    u16 old;
    u16 kind;
    s32 attr;

    t->pad1E = 0;
    if (gKeysNew & 1)
    {
        old = Combatant_GetEquipSlot(c, m->unk30);
        Sound_Play(0x65);
        m->unk2C = 0;
        m->unk2E = 0;
        sub_080CDBE8(gUnknown_084F0994[m->unk30][0], gUnknown_084F0994[m->unk30][1]);
        if (old != 0xFF)
        {
            kind = sub_080D2268(old);
            Item_GetAttribute(old, 6, &attr);
            if ((attr & 1) && kind != 6)
            {
                t->pad1E = 4;
                MENU_WINDOW50(m) = Window_CreateOpen(2, 0xB, 0x1A, 7, 0);
                Font_ResetGlyphSpriteCache(0x180);
                return;
            }
        }
        if (m->unk28 == 0)
        {
            Equip_ClearSlot(c->id, m->unk30);
            Hud_InvalidateGauges();
            Combatant_RecalcStats(c->id);
            if (c->maxHp < c->hp)
                c->hp = c->maxHp;
            if ((old & 0xFF) != 0xFF)
                Inventory_AddItem(old);
            sub_080C9CD8(t);
            sub_080C9BCC(t);
            sub_080C9D5C(t);
            sub_080C9D00(t);
            sub_080C9E08(t);
            sub_080C9D84(t);
        }
        else
        {
            t->pad1E = 0x8001;
            return;
        }
    }
    else if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        t->pad1E = 3;
    }
    else if ((gKeysNew & 0x200) && m->unk22 == 0 && sub_080C964C(0) != 1)
    {
        Sound_Play(0x64);
        if (m->sel != 0)
            m->sel--;
        else
            m->sel = count - 1;
        m->unk0A = 0xFFF0;
        t->pad1E = 2;
        sub_080CDBD4();
    }
    else if ((gKeysNew & 0x100) && m->unk22 == 0 && sub_080C964C(0) != 1)
    {
        Sound_Play(0x64);
        if (m->sel != count - 1)
            m->sel++;
        else
            m->sel = 0;
        m->unk0A = 0x10;
        t->pad1E = 2;
        sub_080CDBD4();
    }
    else if (gRepeatedKeys & 0x40)
    {
        Sound_Play(0x64);
        if (m->unk30 != 0)
            m->unk30--;
        else
            m->unk30 = 6;
    }
    else if (gRepeatedKeys & 0x80)
    {
        Sound_Play(0x64);
        if (m->unk30 != 6)
            m->unk30++;
        else
            m->unk30 = 0;
    }
    sub_080C49EC(0xF, 3, 2, 10, m->unk30 * 15 + 0x13);
}

// sub_080CDE84 @ 0x080CDE84
void sub_080CDE84(struct Task *t)
{
    struct C0c6Status *m = &gMenuState;

    t->result = 0;
    if (gKeysNew & 1)
    {
        Window_Close(MENU_WINDOW50(m), 1);
        t->result = 1;
    }
    Text_DrawSpriteString(gUnknown_084F09B0, 0, 0, 0x12, 0x5B, 0xC);
    if (!((gFrameCounter >> 4) & 1))
        sub_080C4AB0(0, 0, 0xD5, 0x85);
}

// Equip_EquipItem @ 0x080CDEEC
/* Equips item on member who (bit 15 of item: a stocked item id in the low byte); with keep == 0,
   equipping the item already in the slot takes it off. */
void Equip_EquipItem(u16 who, u16 item, u16 keep)
{
    struct Combatant *c = Party_GetMember(who + 0x8000);
    u16 slot;
    u16 old;
    s32 attr;

    if (item & 0x8000)
        item &= 0xFF;
    slot = sub_080D2268(item);
    old = Combatant_GetEquipSlot(c, slot);
    Item_GetAttribute(item, 6, &attr);
    if ((attr & 1) && slot != 6)
    {
        sub_080C08E8(c->id);
        sub_080C84A0();
    }
    if (item == old && keep == 0)
    {
        Equip_ClearSlot(c->id, slot);
        if ((old & 0xFF) != 0xFF)
            Inventory_AddItem(old);
    }
    else
    {
        Combatant_SetEquipSlot(c, slot, item);
        Inventory_RemoveItem(item);
        if ((old & 0xFF) != 0xFF)
            Inventory_AddItem(old);
    }
    Combatant_RecalcStats(c->id);
    if (c->maxHp < c->hp)
        c->hp = c->maxHp;
}

// sub_080CDFBC @ 0x080CDFBC
void sub_080CDFBC(u16 who, u16 item)
{
    Equip_EquipItem(who, item, 1);
}

// Equip_ClearSlot @ 0x080CDFD0
void Equip_ClearSlot(u16 who, u16 slot)
{
    Combatant_SetEquipSlot(Party_GetMember(who + 0x8000), slot, 0xFFFF);
}

// sub_080CDFF8 @ 0x080CDFF8
void sub_080CDFF8(u16 who, u16 slot)
{
    struct Combatant *c = Party_GetMember(who + 0x8000);

    Equip_ClearSlot(c->id, slot);
    Combatant_RecalcStats(c->id);
    if (c->maxHp < c->hp)
        c->hp = c->maxHp;
    Hud_InvalidateGauges();
}

// sub_080CE038 @ 0x080CE038
/* Equipment list input: A equips the highlighted item, B goes back, up/down/L/R scroll 7 rows. */
void sub_080CE038(struct Task *t)
{
    struct C0c6Status *m = &gMenuState;
    struct Combatant *c = Status_GetCombatant(m->sel);
    u16 count = m->unk28;
    u32 redraw = 0;
    u16 rows;
    u16 item;

    t->pad1E = 0;
    rows = count;
    if (rows > 6)
        rows = 7;
    if (gKeysNew & 1)
    {
        Combatant_GetEquipSlot(c, m->unk30);
        item = gUnk_0203B454[m->unk2C + m->unk2E];
        if (item == Combatant_GetEquipSlot(c, m->unk30) || Equip_CanEquip(c->id, item) == 1)
        {
            Sound_Play(0x65);
            Equip_EquipItem(c->id, item, 0);
            Hud_InvalidateGauges();
            t->pad1E = 2;
        }
        else
        {
            Sound_Play(0x66);
        }
        return;
    }
    if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        t->pad1E = 2;
    }
    else if (gRepeatedKeys & 0x40)
    {
        Sound_Play(0x64);
        if (m->unk2C != 0)
        {
            m->unk2C--;
            sub_080C9D5C(t);
            sub_080C9D00(t);
            sub_080C9E08(t);
            sub_080C9D84(t);
        }
        else if (m->unk2E != 0)
        {
            m->unk2E--;
            redraw = 1;
        }
    }
    else if (gRepeatedKeys & 0x80)
    {
        Sound_Play(0x64);
        if (m->unk2C != rows - 1)
        {
            m->unk2C++;
            sub_080C9D5C(t);
            sub_080C9D00(t);
            sub_080C9E08(t);
            sub_080C9D84(t);
        }
        else if (m->unk2C == 6 && m->unk2C + m->unk2E + 1 <= count - 1)
        {
            m->unk2E++;
            redraw = 1;
        }
    }
    else if ((gRepeatedKeys & 0x200) && count > 7)
    {
        Sound_Play(0x64);
        redraw = 1;
        if (m->unk2C != 0)
            m->unk2C = 0;
        else if (m->unk2E > 5)
            m->unk2E -= 6;
        else
            m->unk2E = 0;
    }
    else if ((gRepeatedKeys & 0x100) && count > 7)
    {
        Sound_Play(0x64);
        redraw = 1;
        if (m->unk2C != 6)
            m->unk2C = 6;
        else if (m->unk2C + m->unk2E + 7 < count - 1)
            m->unk2E += 7;
        else
            m->unk2E = count - 7;
    }
    if (redraw == 1)
    {
        sub_080C9CD8(t);
        sub_080C9BCC(t);
        sub_080C9D5C(t);
        sub_080C9D00(t);
        sub_080C9E08(t);
        sub_080C9D84(t);
    }
    sub_080C49EC(0xF, 0, 2, 10, m->unk2C * 15 + 0x14);
    if (m->unk2E != 0)
        m->unk1C = 1;
    if (m->unk2E + 7 <= count - 1)
        m->unk1E = 1;
}

// sub_080CE258 @ 0x080CE258
struct Task *sub_080CE258(u32 unused, u16 sel)
{
    struct Task *task = Task_Create(gUnknown_084F09C8, 0xFFFF);
    struct C0c6Status *m = &gMenuState;
    vu32 zero = 0;

    CpuSet((void *)&zero, m, 0x05000200);
    m->sel = sel;
    m->page = 1;
    m->mode = 3;
    m->unk22 = 0;
    return task;
}

// sub_080CE2A8 @ 0x080CE2A8
/* FALSE when all six base stats of c are 40. */
s32 sub_080CE2A8(struct Combatant *c)
{
    if (Combatant_GetBaseStat(c->id, 0) == 40 && Combatant_GetBaseStat(c->id, 1) == 40
        && Combatant_GetBaseStat(c->id, 2) == 40 && Combatant_GetBaseStat(c->id, 3) == 40
        && Combatant_GetBaseStat(c->id, 4) == 40 && Combatant_GetBaseStat(c->id, 5) == 40)
        return FALSE;
    return TRUE;
}

// sub_080CE300 @ 0x080CE300
/* Stat point allocation: A adds a point to the selected stat (max 40), B takes back one added
   this session (not below the saved value); asks for confirmation when the points run out. */
void sub_080CE300(struct Task *t)
{
    struct C0c6Status *m = &gMenuState;
    struct Combatant *c = Status_GetCombatant(m->sel);
    u32 redraw = 0;
    s32 v;
    s32 cur;

    t->pad1E = 0;
    if (gRepeatedKeys & 1)
    {
        v = Combatant_GetBaseStat(c->id, m->unk2C) & 0xFF;
        if (sub_080CE2A8(c) == 0)
        {
            t->pad1E = 1;
            MENU_WINDOW4C(m) = YesNo_Create(0);
            MENU_WINDOW50(m) = Window_CreateOpen(1, 0xC, 0x12, 4, redraw);
        }
        else if (v != 40)
        {
            Combatant_AddBaseStat(c->id, m->unk2C, 1);
            m->unk36--;
            redraw = 1;
            if (m->unk36 == 0)
            {
                t->pad1E = redraw;
                MENU_WINDOW4C(m) = YesNo_Create(0);
                MENU_WINDOW50(m) = Window_CreateOpen(1, 0xC, 0x12, 4, 0);
            }
        }
        Sound_Play(0x65);
    }
    else if (gRepeatedKeys & 2)
    {
        cur = Combatant_GetBaseStat(c->id, m->unk2C);
        switch (m->unk2C)
        {
        case 0:
            v = (s8)m->saved.base[0];
            break;
        case 1:
            v = (s8)m->saved.base[1];
            break;
        case 2:
            v = (s8)m->saved.base[2];
            break;
        case 3:
            v = (s8)m->saved.base[3];
            break;
        case 4:
            v = (s8)m->saved.base[4];
            break;
        case 5:
            v = (s8)m->saved.base[5];
            break;
        }
        if ((v & 0xFF) != (cur & 0xFF))
        {
            Combatant_AddBaseStat(c->id, m->unk2C, -1);
            m->unk36++;
            redraw = 1;
            Sound_Play(0x66);
        }
    }
    else if (gRepeatedKeys & 0x40)
    {
        if (m->unk2C > 2)
            m->unk2C -= 3;
        else
            m->unk2C += 3;
        Sound_Play(0x64);
    }
    else if (gRepeatedKeys & 0x80)
    {
        if (m->unk2C > 2)
            m->unk2C -= 3;
        else
            m->unk2C += 3;
        Sound_Play(0x64);
    }
    else if (gRepeatedKeys & 0x20)
    {
        if (m->unk2C != 0)
            m->unk2C--;
        else
            m->unk2C = 5;
        Sound_Play(0x64);
    }
    else if (gRepeatedKeys & 0x10)
    {
        if (m->unk2C != 5)
            m->unk2C++;
        else
            m->unk2C = 0;
        Sound_Play(0x64);
    }
    if (redraw == 1)
    {
        sub_080CB068();
        sub_080C9D5C(t);
        sub_080C9D00(t);
        sub_080C9E08(t);
        sub_080C9D84(t);
    }
}

// sub_080CE4D0 @ 0x080CE4D0
/* Confirmation of the stat allocation: yes keeps it, no restores the saved combatant. */
void sub_080CE4D0(struct Task *t)
{
    struct C0c6Status *m = &gMenuState;
    struct Combatant *c = Status_GetCombatant(m->sel);
    u32 free;

    t->pad1E = 0;
    free = Task_IsFree(MENU_WINDOW4C(m));
    if (free == 1)
    {
        if (gYesNoResult == 0)
        {
            t->pad1E = free;
        }
        else
        {
            t->pad1E = 2;
            m->unk36 = m->unk34;
            CpuSet(&m->saved, c, 0x04000020);
            sub_080C9414();
            sub_080CB068();
            sub_080C9D5C(t);
            sub_080C9D00(t);
            sub_080C9E08(t);
            sub_080C9D84(t);
        }
        Window_Close(MENU_WINDOW50(m), 1);
    }
    Text_DrawSpriteString(gUnknown_084F0CA0, 0, 0, 10, 0x62, 0xC);
}

// sub_080CE564 @ 0x080CE564
void sub_080CE564(struct Task *t)
{
    if (gMenuState.mode == 4)
        t->result = 1;
    else
        t->result = 0;
}

// sub_080CE580 @ 0x080CE580
/* Detaches (restore == 0) or reattaches the frame callbacks of the character object tasks. */
void sub_080CE580(u32 unused, u32 restore)
{
    u32 i = 0;
    void **saved = gUnk_020360B4;
    struct Task **tasks = gCharTasks;

    for (; i < 8; i++)
    {
        if (*tasks != NULL)
        {
            if (restore == 0)
            {
                *saved = (*tasks)->onFrame;
                (*tasks)->onFrame = (void *)restore;
            }
            else
            {
                (*tasks)->onFrame = *saved;
                *saved = 0;
            }
        }
        saved++;
        tasks++;
    }
}

// sub_080CE5BC @ 0x080CE5BC
void sub_080CE5BC(void)
{
    struct Combatant *c = Status_GetCombatant(gMenuState.sel);

    if (gMenuState.mode == 5)
        sub_080BF8D8(c->id);
}

// sub_080CE5E0 @ 0x080CE5E0
void sub_080CE5E0(void)
{
    u16 v = gGameState.unkAC0;

    if (v == 0 && (gUnk_0200AB04 & 0x8000))
        gUnk_03003BB4 = v;
}

// sub_080CE614 @ 0x080CE614
void sub_080CE614(void)
{
    gUnk_0300000E = 0;
}

// sub_080CE620 @ 0x080CE620
void sub_080CE620(void)
{
    gUnk_03004608 = 1;
}
