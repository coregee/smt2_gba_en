#include "global.h"
#include "status.h"

void sub_080CD9C8(u16 a, u16 b, u16 c, u16 d, u16 x, u16 y);
extern const u8 gUnknown_0800146C[], gUnknown_080014A0[], gUnknown_08001630[], gUnknown_08001780[];
extern const u8 gUnknown_08001620[], gUnknown_080014B0[], gUnknown_080014C0[], gUnknown_080014D8[];
extern const u8 gUnknown_08001770[];
extern const u8 gUnknown_081A6ED4[];   /* per incense item: two 4-bit bonuses per byte */

#define STAT_SPRITE(def, layer, prio, x, y) Sprite_Draw(def, layer, 0, prio, 0x200, x, y)

/* Per-frame sprites of the status screen: markers, the six stat bars of the shown
   combatant (sub_080CD9C8: base, equipment, extra and, for the hero, the bonus of the
   incense items 0x120-0x12B held more than 8 times; or the totals for demons that
   sub_080C92AC accepts, with their alignment icon), the alignment icon of +0x32, the
   animated portrait (sub_080C97F0/sub_080C9854, every 8 frames) and the cursor of the
   six-entry menu in modes 4-5. */
// Status_DrawSprites @ 0x080C9F98
void Status_DrawSprites(struct Task *task)
{
    struct C0c6Status *st = &gMenuState;
    struct Combatant *c = Status_GetCombatant(st->sel);
    u16 b0, b1, b2, b3, b4, b5;
    u16 i;
    u8 v;
    u16 flags;
    u16 scroll;
    s32 attr;
    u16 x, y;
    u16 frame;

    if (st->unk16 == 1)
        STAT_SPRITE(gUnknown_0800146C, 0, 1, 0xA0 - gUnk_03000004, 0x18);
    if (st->unk1C == 1)
        sub_080C4A4C(0, 0, 0x92, 0x14);
    if (st->unk1E == 1)
        sub_080C4AB0(0, 0, 0x92, 0x76);
    if (sub_080C9388(st->sel) == 1)
    {
        if (st->unk10 == 1)
            STAT_SPRITE(gUnknown_080014A0, 1, 2, 8 - gUnk_03000004, 0x11);
    }
    else if (st->unk10 == 1)
    {
        if (st->unk12 != 0)
            STAT_SPRITE(gUnknown_08001630, 0, 1, 8 - gUnk_03000004, st->unk12);
        if (st->unk14 != 0)
            STAT_SPRITE(gUnknown_08001780, 0, 1, 8 - gUnk_03000004, st->unk14);
    }
    if (st->unk18 == 1)
    {
        if (st->hofs == 0)
            scroll = gUnk_03000004;
        else
            scroll = st->hofs;
        STAT_SPRITE(gUnknown_08001620, 3, 2, 0x77 - scroll, 0x81);
        if (sub_080C92AC(c->demonId) == 1)
        {
            sub_080CD9C8(0, (s8)c->total[0], 0, 0, 0x16, 0x86);
            sub_080CD9C8(0, (s8)c->total[1], 0, 0, 0x63, 0x86);
            sub_080CD9C8(0, (s8)c->total[2], 0, 0, 0xB0, 0x86);
            sub_080CD9C8(0, (s8)c->total[3], 0, 0, 0x16, 0x93);
            sub_080CD9C8(0, (s8)c->total[4], 0, 0, 0x63, 0x93);
            sub_080CD9C8(0, (s8)c->total[5], 0, 0, 0xB0, 0x93);
            Item_GetAttribute(Fusion_GetDemonByIndex(c->demonId), 0, &attr);
            switch (attr)
            {
            case 0xC0:
                STAT_SPRITE(gUnknown_080014D8, 0, 1, 0xD8 - gUnk_03000004, 0x45);
                break;
            case 0x80:
                STAT_SPRITE(gUnknown_080014B0, 0, 1, 0xD8 - gUnk_03000004, 0x45);
                break;
            case 0x40:
                STAT_SPRITE(gUnknown_080014C0, 0, 1, 0xD8 - gUnk_03000004, 0x45);
                break;
            }
        }
        else if (sub_080C99B8(c) != 1)
        {
            b0 = 0;
            b1 = 0;
            b2 = 0;
            b3 = 0;
            b4 = 0;
            b5 = 0;
            if ((gUnk_03000004 & 0x1FF) == 0 && c->id == 0)
            {
                for (i = 0; i < 12; i++)
                {
                    if (Inventory_GetCount(i + 0x120) > 8)
                    {
                        v = gUnknown_081A6ED4[i * 4 + 1];
                        b0 += v >> 4;
                        b1 += v & 0xF;
                        v = gUnknown_081A6ED4[i * 4 + 2];
                        b2 += v >> 4;
                        b3 += v & 0xF;
                        v = gUnknown_081A6ED4[i * 4 + 3];
                        b4 += v >> 4;
                        b5 += v & 0xF;
                    }
                }
            }
            flags = c->flags;
            if (st->mode == 7)
                flags = Stock_FindByDemonId(c->demonId)->flags;
            if (flags & 0x800)
            {
                sub_080CD9C8(1, (s8)c->bonus[0], (s8)c->extra[0], b0, 0x16, 0x86);
                sub_080CD9C8(1, (s8)c->bonus[1], (s8)c->extra[1], b1, 0x63, 0x86);
                sub_080CD9C8(1, (s8)c->bonus[2], (s8)c->extra[2], b2, 0xB0, 0x86);
                sub_080CD9C8(1, (s8)c->bonus[3], (s8)c->extra[3], b3, 0x16, 0x93);
                sub_080CD9C8(0x28, (s8)c->bonus[4], (s8)c->extra[4], b4, 0x63, 0x93);
                sub_080CD9C8(1, (s8)c->bonus[5], (s8)c->extra[5], b5, 0xB0, 0x93);
            }
            else
            {
                sub_080CD9C8((s8)c->base[0], (s8)c->bonus[0], (s8)c->extra[0], b0, 0x16, 0x86);
                sub_080CD9C8((s8)c->base[1], (s8)c->bonus[1], (s8)c->extra[1], b1, 0x63, 0x86);
                sub_080CD9C8((s8)c->base[2], (s8)c->bonus[2], (s8)c->extra[2], b2, 0xB0, 0x86);
                sub_080CD9C8((s8)c->base[3], (s8)c->bonus[3], (s8)c->extra[3], b3, 0x16, 0x93);
                sub_080CD9C8((s8)c->base[4], (s8)c->bonus[4], (s8)c->extra[4], b4, 0x63, 0x93);
                sub_080CD9C8((s8)c->base[5], (s8)c->bonus[5], (s8)c->extra[5], b5, 0xB0, 0x93);
            }
        }
    }
    switch (st->unk32)
    {
    case 0xC0:
        STAT_SPRITE(gUnknown_080014D8, 0, 1, 0xD0 - gUnk_03000004, 0x8C);
        break;
    case 0x80:
        STAT_SPRITE(gUnknown_080014B0, 0, 1, 0xD0 - gUnk_03000004, 0x8C);
        break;
    case 0x40:
        STAT_SPRITE(gUnknown_080014C0, 0, 1, 0xD0 - gUnk_03000004, 0x8C);
        break;
    }
    if ((gFrameCounter & 7) == 0)
    {
        if (st->mode != 3)
        {
            if (st->page == 0)
            {
                frame = st->unk20;
                st->unk20 = (frame + 1) & 1;
            }
            else
                frame = 0;
        }
        else if (st->page == 1)
        {
            frame = st->unk20;
            st->unk20 = (frame + 1) & 1;
        }
        else
            frame = 0;
        sub_080C97F0(task, frame);
        sub_080C9854(task, frame);
    }
    if ((u16)(st->mode - 4) <= 1)
    {
        switch (st->unk2C)
        {
        case 0:
            x = 5;
            y = 0x82;
            break;
        case 1:
            x = 0x52;
            y = 0x82;
            break;
        case 2:
            x = 0x9F;
            y = 0x82;
            break;
        case 3:
            x = 5;
            y = 0x8F;
            break;
        case 4:
            x = 0x52;
            y = 0x8F;
            break;
        case 5:
            x = 0x9F;
            y = 0x8F;
            break;
        }
        STAT_SPRITE(gUnknown_08001770, 2, 2, x, y + 2);
    }
}
