#include "global.h"
#include "fieldcmd.h"

// Item_GetAttribute @ 0x080BF468
/* Reads attribute `field` of item (< 0x80), equipment (< 0xD0) or skill id into *out
   (-1 when the record kind has no such field; field 5 unpacks 6 BCD digits). */
void Item_GetAttribute(s32 id, u32 field, s32 *out)
{
    u8 *r;
    s32 v;

    if (id & 0x8000)
        id &= 0xFF;
    if (id <= 0x7F)
    {
        r = Item_GetRecord(id);
        switch (field)
        {
        case 0:
            v = r[0] & 0xF0;
            break;
        case 1:
            v = r[0] & 0xF;
            break;
        case 2:
            v = r[1];
            break;
        case 3:
            v = r[2];
            break;
        case 4:
            v = r[3];
            break;
        case 5:
            Bcd_Unpack3(r + 4, (u8 *)out);
            return;
        case 6:
            v = *(u16 *)(r + 8);
            break;
        case 7:
            v = r[0xB];
            break;
        default:
            v = -1;
            break;
        }
    }
    else if (id <= 0xCF)
    {
        r = Equipment_GetRecord36_MidRange(id);
        switch (field)
        {
        case 0:
            v = r[0] & 0xF0;
            break;
        case 1:
            v = r[0] & 0xF;
            break;
        case 8:
            v = r[1];
            break;
        case 9:
            v = r[2];
            break;
        case 5:
            Bcd_Unpack3(r + 4, (u8 *)out);
            return;
        case 6:
            v = *(u16 *)(r + 8);
            break;
        case 7:
            v = r[3];
            break;
        default:
            v = -1;
            break;
        }
    }
    else
    {
        r = Action_GetRecord(id);
        switch (field)
        {
        case 10:
            v = r[0] & 0xF0;
            break;
        case 1:
            v = r[0] & 0xF;
            break;
        case 11:
            v = (s8)r[1];
            break;
        case 12:
            v = r[2];
            if (id == 0xF0)
                v = sub_080F6278();
            else if (id == 0xF8)
                v = sub_080F6390();
            break;
        case 5:
            Bcd_Unpack3(r + 1, (u8 *)out);
            return;
        case 13:
            v = r[3];
            break;
        default:
            v = -1;
            break;
        }
    }
    *out = v;
}

// sub_080BF5C0 @ 0x080BF5C0
const u8 *sub_080BF5C0(u16 id)
{
    return &gUnknown_0819B9F4[id * 28];
}

// sub_080BF5D8 @ 0x080BF5D8
void sub_080BF5D8(u16 id, u16 a1, u16 a2, u16 x, u16 y, u16 step)
{
    const u16 *name = ((const struct NameRecord28 *)sub_080BF5C0(id))->name;
    u32 i = 0;

    if (*name != 0)
    {
        do
        {
            FontSprite_DrawGlyph(*name, a1, a2, x, y);
            name++;
            x += step;
            i++;
            if (i > 7)
                break;
        } while (*name != 0);
    }
}

// Demon_GetRecord @ 0x080BF648
/* Demon record id; the party members' entries (0x106/0x109/0x10C, 0x108, 0x10E) get the
   player-chosen name from the combatant data, in a copy at 0x03005FC0. */
u8 *Demon_GetRecord(u16 id)
{
    const u8 *src = &gUnknown_0819CB74[id * 96];
    struct DemonRecord *buf = &gUnk_03005FC0;

    CpuSet(src, buf, 0x04000018);
    if (id == 0x106 || id == 0x109 || id == 0x10C)
    {
        Combatant_DecodeName(gUnk_030050C8, gUnk_03005FC0.name);
        return (u8 *)&gUnk_03005FC0;
    }
    if (id == 0x108)
    {
        Combatant_DecodeName(gUnk_030050D0, buf->name);
        return (u8 *)buf;
    }
    if (id == 0x10E)
    {
        Combatant_DecodeName(gUnk_030050C0, buf->name);
        return (u8 *)buf;
    }
    return (u8 *)src;
}

// Demon_DrawName @ 0x080BF6D4
void Demon_DrawName(u16 id, u16 a1, u16 a2, u16 x, u16 y, u16 step)
{
    const u16 *name = ((struct DemonRecord *)Demon_GetRecord(id))->name;
    u32 i = 0;

    if (*name != 0)
    {
        do
        {
            FontSprite_DrawGlyph(*name, a1, a2, x, y);
            name++;
            x += step;
            i++;
            if (i > 7)
                break;
        } while (*name != 0);
    }
}

/* Same layout as include/combatant.h (which conflicts with fieldcmd.h). */
struct CombatantStats
{
    u8 v[6];
    u8 pad[2];
};

struct Combatant
{
    u8 name[8];
    u32 unk8;
    u8 id;
    u8 level;
    u16 unkE;
    u16 flags;
    s16 demonId;
    s16 unk14;
    u16 unk16;
    s16 hp, maxHp, mp, maxMp;
    s8 equip[7];
    u8 pad27;
    struct CombatantStats base;
    struct CombatantStats bonus;
    struct CombatantStats extra;
    struct CombatantStats total;
    s16 derived[8];
    u16 unk58;
    u8 pad5A[3];
    u8 skills[32];
    u8 pad7D[3];
};

/* Initialises combatant record c for party member `who` (0 the hero, 1/2 with one of
   four random stat sets). The name comes from gUnknown_081A5A00[who][8]. */
// Party_InitMember @ 0x080BF748
void Party_InitMember(struct Combatant *c, s32 who)
{
    const u8 *st;
    const u8 *st2;
    u32 i;

    DmaFill32(3, 0, c, 0x80);
    c->name[0] = gUnknown_081A5A00[who * 8];
    c->name[1] = ((const u8 (*)[8])gUnknown_081A5A00)[who][1];
    c->name[2] = ((const u8 (*)[8])gUnknown_081A5A00)[who][2];
    c->name[3] = ((const u8 (*)[8])gUnknown_081A5A00)[who][3];
    c->name[4] = ((const u8 (*)[8])gUnknown_081A5A00)[who][4];
    c->name[5] = ((const u8 (*)[8])gUnknown_081A5A00)[who][5];
    c->name[6] = ((const u8 (*)[8])gUnknown_081A5A00)[who][6];
    c->name[7] = ((const u8 (*)[8])gUnknown_081A5A00)[who][7];
    if (who == 0)
    {
        c->level = 6;
        c->unk8 = 0x15E;
        c->base.v[0] = 6;
        c->base.v[1] = 5;
        c->base.v[2] = 4;
        c->base.v[3] = 6;
        c->base.v[4] = 6;
        c->base.v[5] = 3;
    }
    else
    {
        if (who == 1)
        {
            st = &gUnknown_081A5A20[(Random_Byte() & 3) * 6];
            c->level = 0x12;
            c->unk8 = 0x25DA;
            c->base.v[0] = st[0];
            c->base.v[1] = st[1];
            c->base.v[2] = st[2];
            c->base.v[3] = st[3];
            c->base.v[4] = st[4];
            c->base.v[5] = st[5];
        }
        else
        {
            st2 = &gUnknown_081A5A38[(Random_Byte() & 3) * 6];
            c->level = 0x18;
            c->unk8 = 0x59D8;
            c->base.v[0] = st2[0];
            c->base.v[1] = st2[1];
            c->base.v[2] = st2[2];
            c->base.v[3] = st2[3];
            c->base.v[4] = st2[4];
            c->base.v[5] = st2[5];
        }
    }
    {
        u32 a = ((u32 *)&c->base)[0];
        u32 b = ((u32 *)&c->base)[1];
        ((u32 *)&c->total)[0] = a;
        ((u32 *)&c->total)[1] = b;
    }
    c->equip[1] = 0xFF;
    c->equip[0] = -1;
    c->equip[3] = -1;
    c->equip[2] = -1;
    c->equip[5] = -1;
    c->equip[4] = -1;
    c->equip[6] = -1;
    c->id = who;
    for (i = 0; i <= 0x1F; i++)
        c->skills[i] |= 0xFF;
    Party_BuildSkillList(c->id);
    if (who <= 3)
    {
        c->unk14 = gUnknown_081A59FC[who];
        c->unk58 = gUnknown_081A59F4[who];
        c->demonId = who + 0x8000;
    }
}

// sub_080BF8D8 @ 0x080BF8D8
void sub_080BF8D8(s32 who)
{
    s32 i;

    for (i = 0; i <= 6; i++)
        Combatant_SetEquip(who, i, gUnknown_081A5A50[who * 7 + i]);
    Combatant_RecalcStats(who);
}
