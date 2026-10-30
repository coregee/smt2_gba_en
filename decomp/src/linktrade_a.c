#include "global.h"
#include "options.h"

// sub_080E077C @ 0x080E077C
void sub_080E077C(struct Task *t)
{
    struct C0cdLinkData *me = &gLink.rec[0];
    struct C0cdLinkSel *s = (struct C0cdLinkSel *)&t->data.raw[0x2C];
    struct C0cdLinkData *other;
    u8 i;

    s->cursor = 1;
    s->unk6 = 0xFFFF;
    s->unk4 = 0xFFFF;
    i = 0;
    other = me + 1;
    for (; i < 2; i++)
        s->digits[i] = 0;
    me->unk54 = 0;
    me->unk56 = 0;
    other->unk54 = 0;
    other->unk56 = 0;
}

// sub_080E07D0 @ 0x080E07D0
/* Six-entry menu: A returns cursor + 1 in t->pad1E, B returns 0xFF. */
void sub_080E07D0(struct Task *t)
{
    t->result = 0;
    if (gKeysNew & 1)
    {
        t->pad1E = t->data.h[0] + 1;
        t->result = 1;
        Sound_Play(0x65);
    }
    else if (gKeysNew & 2)
    {
        t->pad1E = 0xFF;
        t->result = 1;
        Sound_Play(0x66);
    }
    else if (gRepeatedKeys & 0x40)
    {
        if (t->data.h[0] == 0)
            t->data.h[0] = 6;
        t->data.h[0]--;
        Sound_Play(0x64);
    }
    else if (gRepeatedKeys & 0x80)
    {
        if (++t->data.h[0] > 5)
            t->data.h[0] = 0;
        Sound_Play(0x64);
    }
}

// sub_080E0864 @ 0x080E0864
/* Lists the held inventory entries whose slot mask matches mask (0x80: ids 0x120-0x12B,
   otherwise ids up to 0xFE) at 0x0203C4D0; returns the count. */
/* NONMATCHING: register allocation (the two branches use separate copies of id and count). */
u16 sub_080E0864(u32 mask)
{
    u8 *blk = gUnk_0203C200;
    u32 off = 0x2D0;
    struct C0c2InvEntry *out = (struct C0c2InvEntry *)(blk + off);
    u16 n = 0;
    u16 i;

    for (i = 0; i < 0x15A; i++)
    {
        u16 id = ((struct C0c2InvEntry *)0x030051AC)[i].id;
        u16 count = ((struct C0c2InvEntry *)0x030051AC)[i].count;

        if (count == 0)
            continue;
        if (mask == 0x80)
        {
            if ((Item_GetSlotMask(id) & mask) && (u16)(id - 0x120) <= 0xB)
            {
                out->id = id;
                out->count = count;
                out++;
                n++;
            }
        }
        else if ((Item_GetSlotMask(id) & mask) && id <= 0xFE)
        {
            out->id = id;
            out->count = count;
            out++;
            n++;
        }
    }
    out->id = 0xFFFF;
    out->count = 0xFFFF;
    return n;
}


// sub_080E0928 @ 0x080E0928
/* Builds the item list for filter gUnknown_0858A818[t->data.h[0]] and sizes its menu (at most
   5 rows); t->pad1E = 0xFF when nothing qualifies. */
void sub_080E0928(struct Task *t)
{
    u16 n;

    t->pad1E = 0;
    n = sub_080E0864(gUnknown_0858A818[t->data.h[0]]);
    if (n == 0)
        t->pad1E = 0xFF;
    else if (n <= 4)
        sub_08126928(1, 0, 1, n, n);
    else
        sub_08126928(1, 0x10, 1, n, 5);
}

// sub_080E0980 @ 0x080E0980
/* "NOTHING!" message: waits for A or B. */
void sub_080E0980(struct Task *t)
{
    t->result = 0;
    if (gKeysNew & 1)
    {
        t->result = 1;
        Sound_Play(0x65);
    }
    else if (gKeysNew & 2)
    {
        t->result = 1;
        Sound_Play(0x66);
    }
    SpriteFont_DrawAscii('N', 0xF, 0x7C, 0x28);
    SpriteFont_DrawAscii('O', 0xF, 0x84, 0x28);
    SpriteFont_DrawAscii('T', 0xF, 0x8C, 0x28);
    SpriteFont_DrawAscii('H', 0xF, 0x94, 0x28);
    SpriteFont_DrawAscii('I', 0xF, 0x9C, 0x28);
    SpriteFont_DrawAscii('N', 0xF, 0xA4, 0x28);
    SpriteFont_DrawAscii('G', 0xF, 0xAC, 0x28);
    SpriteFont_DrawAscii('!', 0xF, 0xB4, 0x28);
}

// LinkTrade_DrawItemListPage @ 0x080E0A1C
/* Draws a page (5 rows) of the item list built by sub_080E0864: name (8 glyphs, greyed via
   palette 1 when LinkTrade_IsItemOffered says it was already chosen), "x" and a two-digit count. */
void LinkTrade_DrawItemListPage(struct Task *t)
{
    u8 *data = t->data.raw;
    u16 name[9];
    struct C0cdLinkData *l;
    struct MenuCursor *menu;
    u8 rows, i, j;

    memset(name, 0, sizeof(name));
    l = &gLinkData;
    Sprite_Draw(*(const void **)(data + 0x18), 0, 7, 0, 0x100, 0x10, t->data.h[0] * 11 + 0xE);
    Sprite_Draw(*(const void **)(data + 0x14), 0, 7, 0, 0, 0x10, 0x10);
    menu = sub_08126D1C(1);
    Sprite_Draw(gUnknown_0800853C, 0, 7, 0, 0x100, 0x52, menu->onScreen * 13 + 0x14);
    if (menu->count > 5)
    {
        if (menu->top != 0)
            SpriteFont_DrawAscii('<', 10, 0xD9, 0xB);
        if (menu->top + 5 != menu->count)
            SpriteFont_DrawAscii('>', 10, 0xD9, 0x49);
    }
    if (menu->count > 5)
        rows = 5;
    else
        rows = menu->count;
    for (i = 0; i < rows; i++)
    {
        struct C0c2InvEntry *e = (struct C0c2InvEntry *)(gUnk_0203C200 + 0x2D0) + (i + menu->top);
        u16 id = e->id;
        u16 count = e->count;
        u16 *src;

        if (id <= 0x7F)
            src = (u16 *)(Item_GetRecord(id) + 0x14);
        else if (id <= 0xCF)
            src = (u16 *)(Equipment_GetRecord36_MidRange(id) + 0x14);
        else
            src = (u16 *)(Action_GetRecord(id) + 0xC);
        for (j = 0; j < 8; j++)
            name[j] = *src++;
        name[j] = 0;
        if (LinkTrade_IsItemOffered(l, id))
            Text_DrawSpriteStringTinted(name, 0, 0, 0x52, i * 13 + 0x13, 0xC, 1);
        else
            Text_DrawSpriteString(name, 0, 0, 0x52, i * 13 + 0x13, 0xC);
        FontSprite_DrawGlyph(0x3E, 0, 0, 0xB9, i * 13 + 0x14);
        SpriteFont_DrawAscii(count / 10 + '0', 10, 0xC6, i * 13 + 0x12);
        SpriteFont_DrawAscii(count % 10 + '0', 10, 0xCE, i * 13 + 0x12);
    }
}

// sub_080E0BF4 @ 0x080E0BF4
/* Item list input: B cancels; A on an item already offered withdraws it, otherwise (when
   fewer than five are offered) selects it for the count entry. */
void sub_080E0BF4(struct Task *t)
{
    struct MenuCursor *menu = sub_08126D1C(1);
    struct C0c2InvEntry *list;
    struct C0cdLinkSel *s;
    struct C0cdLinkData *d;
    u16 b;
    u8 r, full;
    u8 i;

    sub_08126A08(1);
    t->pad1E = 0;
    t->result = 0;
    if ((b = gKeysNew & 2))
    {
        t->pad1E = 0xFF;
        t->result = 1;
        return;
    }
    if (menu->state != 3)
        return;
    t->result = 1;
    list = (struct C0c2InvEntry *)gUnk_0203C200;
    list += 0xB4;
    s = (struct C0cdLinkSel *)&t->data.raw[0x2C];
    d = &gLinkData;
    s->unk4 = list[menu->index].id;
    if ((r = LinkTrade_IsItemOffered(d, s->unk4)))
    {
        LinkTrade_RemoveItemOffer(d, s->unk4);
        t->result = b;
    }
    else if ((full = sub_080E0D08(d)))
    {
        Sound_Play(0x66);
        t->result = r;
    }
    else
    {
        s->unk6 = full;
        for (i = 0; i < 2; i++)
            s->digits[i] = 0;
    }
}

// sub_080E0CB0 @ 0x080E0CB0
void sub_080E0CB0(struct Task *t)
{
    t->onFrame = sub_080D9B64;
    sub_081269B0(1);
}

// sub_080E0CC4 @ 0x080E0CC4
void sub_080E0CC4(struct Task *t)
{
    struct C0cdLinkData *d = &gLinkData;
    struct C0cdLinkSel *s = (struct C0cdLinkSel *)&t->data.raw[0x2C];

    LinkTrade_AddItemOffer(d, s->unk4, s->unk6);
}

// LinkTrade_IsItemOffered @ 0x080E0CDC
/* TRUE when id is among the offered items. */
u8 LinkTrade_IsItemOffered(struct C0cdLinkData *d, u16 id)
{
    u16 i;

    for (i = 0; i < 5; i++)
    {
        if (d->offers[i].id == id)
            return TRUE;
    }
    return FALSE;
}

// sub_080E0D08 @ 0x080E0D08
/* TRUE when all five offer slots are used. */
u8 sub_080E0D08(struct C0cdLinkData *d)
{
    if (d->offerCount > 4)
        return TRUE;
    return FALSE;
}

// LinkTrade_AddItemOffer @ 0x080E0D1C
/* Adds count of id to the first free offer slot. */
u8 LinkTrade_AddItemOffer(struct C0cdLinkData *d, u16 id, u16 count)
{
    u16 i;

    if (sub_080E0D08(d))
        return FALSE;
    for (i = 0; i < 5; i++)
    {
        if (d->offers[i].id == 0xFFFF)
        {
            d->offers[i].id = id;
            d->offers[i].count = count;
            d->offerCount++;
            return TRUE;
        }
    }
    return FALSE;
}

// LinkTrade_RemoveItemOffer @ 0x080E0D74
/* Withdraws the offer of id. */
u8 LinkTrade_RemoveItemOffer(struct C0cdLinkData *d, u16 id)
{
    u16 i;

    for (i = 0; i < 5; i++)
    {
        if (d->offers[i].id == id)
        {
            d->offers[i].count |= 0xFFFF;
            d->offers[i].id |= 0xFFFF;
            d->offerCount--;
            return TRUE;
        }
    }
    return FALSE;
}

// LinkTrade_ClearItemOffers @ 0x080E0DC8
/* Clears the five offer slots. */
void LinkTrade_ClearItemOffers(struct C0cdLinkData *d)
{
    u16 i;

    d->offerCount = 0;
    for (i = 0; i < 5; i++)
    {
        d->offers[i].count |= 0xFFFF;
        d->offers[i].id |= 0xFFFF;
    }
}

// sub_080E0E04 @ 0x080E0E04
struct C0c2InvEntry *sub_080E0E04(struct C0cdLinkData *d, u16 id)
{
    u16 i;

    for (i = 0; i < 5; i++)
    {
        if (d->offers[i].id == id)
            return &d->offers[i];
    }
    return NULL;
}

// sub_080E0E34 @ 0x080E0E34
/* Count entry (two digits) for the item chosen in the parent task's list; A accepts (clamped
   to the held count), B cancels. */
void sub_080E0E34(struct Task *t)
{
    struct Task *p = Task_GetParent(t);
    struct C0cdLinkSel *s = (struct C0cdLinkSel *)&p->data.raw[0x2C];
    struct MenuCursor *menu = sub_08126D1C(1);
    struct C0c2InvEntry *base = (struct C0c2InvEntry *)gUnk_0203C200;
    struct C0c2InvEntry *list = base + 0xB4;

    t->pad1E = 0;
    t->result = 0;
    p->pad1E = 0;
    if (gKeysNew & 1)
    {
        if (s->unk6 == 0)
        {
            Sound_Play(0x66);
        }
        else
        {
            u16 max;

            Sound_Play(0x65);
            t->result = 1;
            max = list[menu->index].count;
            if (s->unk6 > max)
            {
                s->unk6 = max;
                s->digits[0] = s->unk6 / 10;
                s->digits[1] = s->unk6 % 10;
            }
            p->pad1E = 0;
        }
    }
    else if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        t->result = 1;
        p->pad1E = 0xFF;
        t->pad1E = 0xFF;
        s->unk4 = 0xFFFF;
    }
    else if (gRepeatedKeys & 0x220)
    {
        if (--s->cursor < 0)
            s->cursor = 1;
        Sound_Play(0x64);
    }
    else if (gRepeatedKeys & 0x110)
    {
        if (++s->cursor > 1)
            s->cursor = 0;
        Sound_Play(0x64);
    }
    else if (gRepeatedKeys & 0x40)
    {
        s->digits[s->cursor]++;
        if (s->digits[s->cursor] > 9)
            s->digits[s->cursor] = 0;
        Sound_Play(0x64);
    }
    else if (gRepeatedKeys & 0x80)
    {
        s->digits[s->cursor]--;
        if (s->digits[s->cursor] < 0)
            s->digits[s->cursor] = 9;
        Sound_Play(0x64);
    }
    s->unk6 = s->digits[0] * 10 + s->digits[1];
}

// sub_080E0FA0 @ 0x080E0FA0
/* Draws the two-digit count of the parent's entry, the cursor digit between '>' and '<'. */
void sub_080E0FA0(struct Task *t)
{
    struct C0cdLinkSel *s = (struct C0cdLinkSel *)&Task_GetParent(t)->data.raw[0x2C];
    s8 i;

    for (i = 0; i <= 1; i++)
    {
        if (s->cursor == 1 - i)
        {
            u16 c = s->digits[1 - i] + '0';
            u16 x = (1 - i) * 8 + 0xD2;

            SpriteFont_DrawAscii(c, 0xC, x, 0x61);
            SpriteFont_DrawAscii('>', 10, x, 0x56);
            SpriteFont_DrawAscii('<', 10, x, 0x68);
        }
        else
        {
            SpriteFont_DrawAscii(s->digits[1 - i] + '0', 10, (1 - i) * 8 + 0xD2, 0x61);
        }
    }
}

// sub_080E1030 @ 0x080E1030
/* Draws the offered items of d (name, "x", count); entries whose bit is set in
   marks->unk54 are tinted with palette 2.  "NOTHING!" when there are none. */
void sub_080E1030(struct C0cdLinkData *d, struct C0cdLinkData *marks)
{
    u16 name[9];
    u16 row;
    u16 i, j;

    memset(name, 0, sizeof(name));
    row = 0;
    if (d->offerCount == 0)
    {
        SpriteFont_DrawAscii('N', 0xF, 0x7C, 0x28);
        SpriteFont_DrawAscii('O', 0xF, 0x84, 0x28);
        SpriteFont_DrawAscii('T', 0xF, 0x8C, 0x28);
        SpriteFont_DrawAscii('H', 0xF, 0x94, 0x28);
        SpriteFont_DrawAscii('I', 0xF, 0x9C, 0x28);
        SpriteFont_DrawAscii('N', 0xF, 0xA4, 0x28);
        SpriteFont_DrawAscii('G', 0xF, 0xAC, 0x28);
        SpriteFont_DrawAscii('!', 0xF, 0xB4, 0x28);
        return;
    }
    for (i = 0; i < 5; i++)
    {
        u16 id = d->offers[i].id;
        u16 count = d->offers[i].count;
        u16 *src;

        if (id == 0xFFFF)
            continue;
        if (id <= 0x7F)
            src = (u16 *)(Item_GetRecord(id) + 0x14);
        else if (id <= 0xCF)
            src = (u16 *)(Equipment_GetRecord36_MidRange(id) + 0x14);
        else
            src = (u16 *)(Action_GetRecord(id) + 0xC);
        for (j = 0; j < 8; j++)
            name[j] = *src++;
        name[j] = 0;
        if ((marks->unk54 >> i) & 1)
            Text_DrawSpriteStringTinted(name, 0, 0, 0x52, row * 13 + 0x13, 0xC, 2);
        else
            Text_DrawSpriteString(name, 0, 0, 0x52, row * 13 + 0x13, 0xC);
        FontSprite_DrawGlyph(0x3E, 0, 0, 0xB9, row * 13 + 0x14);
        SpriteFont_DrawAscii(count / 10 + '0', 10, 0xC6, row * 13 + 0x12);
        SpriteFont_DrawAscii(count % 10 + '0', 10, 0xCE, row * 13 + 0x12);
        row++;
    }
}

// sub_080E11F0 @ 0x080E11F0
void sub_080E11F0(void)
{
    struct C0cdLinkData *d = &gLink.rec[0];

    sub_080E1030(d, d + 1);
}

// sub_080E1204 @ 0x080E1204
void sub_080E1204(void)
{
    struct C0cdLinkData *d = &gLink.rec[1];

    sub_080E1030(d, d - 1);
}

// sub_080E1218 @ 0x080E1218
void sub_080E1218(struct Task *t)
{
    struct C0cdLinkPick *p = (struct C0cdLinkPick *)t->data.raw;

    p->unk0 = 0;
    p->id = 0xFFFF;
}

// sub_080E1228 @ 0x080E1228
/* Builds the demon list (BattleMenu_BuildMemberList(8)) and sizes its menu (at most 5 rows);
   t->pad1E = 0xFF when it is empty. */
void sub_080E1228(struct Task *t)
{
    u16 n;

    t->pad1E = 0;
    n = BattleMenu_BuildMemberList(8);
    if (n == 0)
    {
        t->pad1E = 0xFF;
        return;
    }
    if (n <= 4)
        sub_08126928(1, 0, 1, n, n);
    else
        sub_08126928(1, 0x10, 1, n, 5);
    sub_08126D1C(1)->seA = 0xFFFF;
}

// sub_080E1280 @ 0x080E1280
/* Demon list input: A toggles the offer of the selected demon (refused when sub_0815B8F8
   says it cannot be traded or five are already offered), B cancels. */
void sub_080E1280(struct Task *t)
{
    struct C0cdLinkPick *p = (struct C0cdLinkPick *)t->data.raw;
    u16 *base = (u16 *)gUnk_0203C200;
    u16 *list = base + 0x168;
    struct MenuCursor *menu;

    menu = sub_08126D1C(1);

    sub_08126A08(1);
    t->pad1E = 0;
    t->result = 0;
    if (gKeysNew & 2)
    {
        t->pad1E = 0xFF;
        t->result = 1;
        return;
    }
    if (menu->state == 3)
    {
        struct Combatant *c = Battle_GetCombatant(0x8000 + list[menu->index]);
        u16 demon = c->demonId;

        u8 ok = sub_0815B8F8(c->demonId, 0) != 0;

        if (ok)
        {
            struct C0cdLinkData *d;

            p->id = demon;
            d = &gLinkData;
            if (LinkTrade_IsDemonOffered(d, p->id))
            {
                LinkTrade_RemoveDemonOffer(d, p->id);
            }
            else if (sub_080E156C(d))
            {
                Sound_Play(0x66);
                return;
            }
            else
            {
                LinkTrade_AddDemonOffer(d, p->id);
            }
            Sound_Play(0x65);
        }
        else
        {
            Sound_Play(0x66);
        }
    }
}

// sub_080E1348 @ 0x080E1348
/* "NOTHING!" message (demon list): waits for A or B. */
void sub_080E1348(struct Task *t)
{
    t->result = 0;
    if (gKeysNew & 1)
    {
        t->result = 1;
        Sound_Play(0x65);
    }
    else if (gKeysNew & 2)
    {
        t->result = 1;
        Sound_Play(0x66);
    }
    SpriteFont_DrawAscii('N', 0xF, 0x6C, 0x2A);
    SpriteFont_DrawAscii('O', 0xF, 0x74, 0x2A);
    SpriteFont_DrawAscii('T', 0xF, 0x7C, 0x2A);
    SpriteFont_DrawAscii('H', 0xF, 0x84, 0x2A);
    SpriteFont_DrawAscii('I', 0xF, 0x8C, 0x2A);
    SpriteFont_DrawAscii('N', 0xF, 0x94, 0x2A);
    SpriteFont_DrawAscii('G', 0xF, 0x9C, 0x2A);
    SpriteFont_DrawAscii('!', 0xF, 0xA4, 0x2A);
}

// sub_080E13E4 @ 0x080E13E4
/* Draws a page (5 rows) of the demon list: names (8 glyphs), offered ones tinted with palette 1. */
void sub_080E13E4(void)
{
    u16 *base = (u16 *)gUnk_0203C200;
    u16 *list = base + 0x168;
    u16 name[9];
    struct C0cdLinkData *d;
    struct MenuCursor *menu;
    u8 rows, i, j;

    memset(name, 0, sizeof(name));
    d = &gLinkData;
    menu = sub_08126D1C(1);
    Sprite_Draw(gUnknown_0800853C, 0, 7, 0, 0x100, 0x51, menu->onScreen * 13 + 0x14);
    if (menu->count > 5)
    {
        if (menu->top != 0)
            SpriteFont_DrawAscii('<', 10, 0xB9, 0xB);
        if (menu->top + 5 != menu->count)
            SpriteFont_DrawAscii('>', 10, 0xB9, 0x49);
    }
    if (menu->count > 4)
        rows = 5;
    else
        rows = menu->count;
    for (i = 0; i < rows; i++)
    {
        u16 demon = Battle_GetCombatant(0x8000 + list[i + menu->top])->demonId;
        u16 *src = (u16 *)(Demon_GetRecord(demon) + 0x22);

        for (j = 0; j < 8; j++)
            name[j] = *src++;
        name[j] = 0;
        if (LinkTrade_IsDemonOffered(d, demon))
            Text_DrawSpriteStringTinted(name, 0, 0, 0x51, i * 13 + 0x13, 0xC, 1);
        else
            Text_DrawSpriteString(name, 0, 0, 0x51, i * 13 + 0x13, 0xC);
    }
}
