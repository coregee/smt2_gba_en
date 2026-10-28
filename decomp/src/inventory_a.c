#include "global.h"
#include "inventory.h"

// sub_080C2D48 @ 0x080C2D48
void sub_080C2D48(u16 a, u16 b)
{
    gGameState.unk18AC = a & 0xFF;
    gGameState.unk18AE = b & 0xFF;
}

// sub_080C2D78 @ 0x080C2D78
void sub_080C2D78(s8 a, s8 b)
{
    sub_080C12C0(a, 0, b);
    gGameState.unkAC0 = 0;
    Encounter_SetCounter(0);
    sub_080C2D48(gUnk_03003FC4, b);
    sub_080C2CC0();
}

// sub_080C2DC0 @ 0x080C2DC0
void sub_080C2DC0(u32 a)
{
    gUnk_03004534 = a;
    sub_080C1300(0x14);
    gFieldState.unk1E = 0;
}

// sub_080C2DE0 @ 0x080C2DE0
void sub_080C2DE0(u32 a, u32 b)
{
    gUnk_03004534 = a;
    gUnk_0300453C = b;
    sub_080C1300(0x1C);
    gUnk_03004544 = 5;
    gFieldState.unk1E = 0;
}

// sub_080C2E10 @ 0x080C2E10
void sub_080C2E10(u32 a, u16 b)
{
    gUnk_03004534 = a;
    gUnk_03004628 = b;
    sub_080C1300(0x1B);
    gFieldState.unk1E = 0;
    gUnk_03003BB8 = 1;
}

// sub_080C2E44 @ 0x080C2E44
void sub_080C2E44(u32 a, u32 b)
{
    gUnk_03004534 = a;
    gUnk_03004628 = b;
    sub_080C1300(0x25);
    gFieldState.unk1E = 0;
    gUnk_03003BB8 = 1;
}

// sub_080C2E74 @ 0x080C2E74
void sub_080C2E74(void)
{
    DmaCopy32(3, gUnknown_081BABB0, (void *)0x06011C00, 0xC00);
    DmaCopy32(3, gUnknown_081BB850, (void *)0x06012400, 0x200);
    Palette_CopyWithEffect(3, gUnknown_081BB7B0, &gPaletteTarget[0x1B0], 0x20, 0x20);
    Palette_CopyWithEffect(3, gUnknown_081BB7D0, &gPaletteTarget[0x1C0], 0x20, 0x20);
    Palette_CopyWithEffect(3, gUnknown_081BBA50, &gPaletteTarget[0x1A0], 0x20, 0x20);
}

// sub_080C2EFC @ 0x080C2EFC
void sub_080C2EFC(void)
{
    gUnk_0203A448 = 0;
    gUnk_0203A44A = 0;
    if (Combatant_GetAlignment(0) == 1)
        gUnk_0203A448 = 4;
    gUnk_0203A44C = 9;
    sub_080C2E74();
}

// sub_080C2F34 @ 0x080C2F34
void sub_080C2F34(u32 a, u32 b)
{
    gUnk_0203A44C += b;
}

// sub_080C2F44 @ 0x080C2F44
void sub_080C2F44(u16 x, u16 y, u16 pal)
{
    u16 tile;

    if (gUnk_030069F0[0x1B] == 0)
    {
        tile = gUnknown_081A62F4[gUnk_0203A448] + 0xE0;
        if (gUnk_0203A44C != 9)
            Sprite_Draw(gUnknown_081A62B0[gUnk_0203A44C], 0, 0xB, pal, tile, x - 8, y - 8);
        if ((gFrameCounter & 3) == 0)
        {
            switch (Combatant_GetAlignment(0))
            {
            case 0:
                if ((s16)--gUnk_0203A448 < 0)
                    gUnk_0203A448 = 10;
                break;
            case 1:
                if (gUnk_0203A44A == 0)
                {
                    if (++gUnk_0203A448 > 11)
                    {
                        gUnk_0203A448 = 10;
                        gUnk_0203A44A = 1;
                    }
                }
                else
                {
                    if (--gUnk_0203A448 < 8)
                    {
                        gUnk_0203A448 = 8;
                        gUnk_0203A44A = 0;
                    }
                }
                break;
            case 2:
                if (++gUnk_0203A448 > 11)
                    gUnk_0203A448 = 0;
                break;
            }
        }
    }
    else
    {
        const u16 *tiles = gUnknown_081A630C;
        u32 f = (gFrameCounter >> 3) & 7;

        tile = tiles[f] + 0x120;
        Sprite_Draw(gUnknown_081A62D4[f], 0, 10, 0, tile, x - 8, y - 8);
    }
}

// sub_080C3098 @ 0x080C3098
u16 sub_080C3098(const void *script)
{
    return ScriptVM_RunAlt(script);
}

// sub_080C30A8 @ 0x080C30A8
u32 sub_080C30A8(void)
{
    return 0;
}

// Money_Add @ 0x080C30AC
u32 Money_Add(s32 delta)
{
    if (delta > 0)
    {
        if ((gGameState.money += delta) > 999999)
            gGameState.money = 999999;
    }
    else
    {
        if ((s32)(gGameState.money += delta) < 0)
            gGameState.money = 0;
    }
    return gGameState.money;
}

// Money_Get @ 0x080C3100
u32 Money_Get(void)
{
    return gGameState.money;
}

// Magnetite_Add @ 0x080C3114
u32 Magnetite_Add(s32 delta)
{
    if (delta > 0)
    {
        if ((gGameState.magnetite += delta) > 99999)
            gGameState.magnetite = 99999;
    }
    else
    {
        if ((s32)(gGameState.magnetite += delta) < 0)
            gGameState.magnetite = 0;
    }
    return gGameState.magnetite;
}

// Magnetite_Get @ 0x080C3168
u32 Magnetite_Get(void)
{
    return gGameState.magnetite;
}

// sub_080C317C @ 0x080C317C
#ifdef NONMATCHING
u32 *sub_080C317C(void)
{
    u32 *p = &gGameState.coins[0];

    switch (gUnk_03004614)
    {
    case 0x26:
        break;
    case 0x30:
        p = &gGameState.coins[1];
        break;
    case 0x40:
        p = &gGameState.coins[2];
        break;
    }
    return p;
}
#else
NAKED
u32 *sub_080C317C(void)
{
    asm_unified(
        ".L080C317C:\n"
        "    push {lr}\n"
        "    ldr r0, .L080C3194\n"
        "    ldr r0, [r0]\n"
        "    cmp r0, #0x26\n"
        "    beq .L080C31A8\n"
        "    cmp r0, #0x26\n"
        "    bls .L080C31A8\n"
        "    cmp r0, #0x30\n"
        "    beq .L080C3198\n"
        "    cmp r0, #0x40\n"
        "    beq .L080C31A0\n"
        "    b .L080C31A8\n"
        ".L080C3194: .4byte 0x03004614 @ IWRAM+0x4614\n"
        ".L080C3198:\n"
        "    ldr r0, .L080C319C\n"
        "    b .L080C31AA\n"
        ".L080C319C: .4byte 0x03005F8C @ IWRAM+0x5F8C\n"
        ".L080C31A0:\n"
        "    ldr r0, .L080C31A4\n"
        "    b .L080C31AA\n"
        ".L080C31A4: .4byte 0x03005F90 @ IWRAM+0x5F90\n"
        ".L080C31A8:\n"
        "    ldr r0, .L080C31B0\n"
        ".L080C31AA:\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L080C31B0: .4byte 0x03005F88 @ IWRAM+0x5F88\n"
    );
}
#endif

// sub_080C31B4 @ 0x080C31B4
u32 sub_080C31B4(s32 delta)
{
    u32 *p = sub_080C317C();

    if (delta > 0)
    {
        if ((*p += delta) > 999999)
            *p = 999999;
    }
    else
    {
        if ((s32)(*p += delta) < 0)
            *p = 0;
    }
    return *p;
}

// sub_080C31F0 @ 0x080C31F0
u32 sub_080C31F0(void)
{
    return *sub_080C317C();
}

// sub_080C31FC @ 0x080C31FC
void sub_080C31FC(u32 v)
{
    *sub_080C317C() = v;
}

// Inventory_FindEntry @ 0x080C320C
struct C0c2InvEntry *Inventory_FindEntry(u16 id)
{
    struct C0c2InvEntry *p = gInventory;
    u32 i;

    if (id & 0x8000)
        id &= 0xFF;
    for (i = 0; i < 0x15A; i++, p++)
    {
        if (p->count != 0 && p->id == id)
            return p;
    }
    return NULL;
}

// Inventory_FindIndex @ 0x080C3250
u32 Inventory_FindIndex(u16 id)
{
    u32 i;

    if (id & 0x8000)
        id &= 0xFF;
    for (i = 0; i < 0x15A; i++)
    {
        if (gGameState.inv[i].id == id && gGameState.inv[i].count != 0)
            return i;
    }
    return 0;
}

// Inventory_FindFreeEntry @ 0x080C32A8
struct C0c2InvEntry *Inventory_FindFreeEntry(void)
{
    struct C0c2InvEntry *p = gInventory;
    u32 i;

    for (i = 0; i < 0x15A; i++, p++)
    {
        if (p->count == 0)
            return p;
    }
    return NULL;
}

// Inventory_GetCount @ 0x080C32D4
u8 Inventory_GetCount(u16 id)
{
    struct C0c2InvEntry *p;

    if (id & 0x8000)
        id &= 0xFF;
    p = Inventory_FindEntry(id);
    if (p == NULL)
        return 0;
    return p->count;
}

// Inventory_IsMaxed @ 0x080C32FC
u32 Inventory_IsMaxed(u16 id)
{
    if (id & 0x8000)
        id &= 0xFF;
    return Inventory_GetCount(id) == 99;
}

// Inventory_AddItem @ 0x080C3328
/* Adds one of an item to the inventory (99 at most; items < 0xD0 count the ones equipped). */
void Inventory_AddItem(u16 id)
{
    struct C0c2InvEntry *p;

    if (id & 0x8000)
        id &= 0xFF;
    p = Inventory_FindEntry(id);
    if (p != NULL)
    {
        if (id > 0xCF)
        {
            if (p->count != 99)
                p->count++;
        }
        else
        {
            u16 n = Party_CountEquipped(0xFF, id);

            if (p->count + n <= 98)
                p->count++;
        }
    }
    else
    {
        p = Inventory_FindFreeEntry();
        p->id = id;
        p->count++;
    }
    if ((u16)(id - 300) <= 45)
        sub_080C2764(id);
    if ((u16)(id - 0x120) < 12)
        Combatant_RecalcStats(0);
}

// Inventory_RemoveItem @ 0x080C33AC
/* Removes one of an item, closing the gap when the count reaches 0. */
void Inventory_RemoveItem(u16 id)
{
    struct C0c2InvEntry *p;
    u32 idx;
    u32 i;

    if (id & 0x8000)
        id &= 0xFF;
    p = Inventory_FindEntry(id);
    idx = Inventory_FindIndex(id);
    if (p != NULL)
    {
        if (--p->count == 0)
        {
            u32 n = 0x159 - idx;

            for (i = 0; i < n; i++)


            {
                p[0].id = p[1].id;
                p[0].count = p[1].count;
                p++;
            }
            p->id = 0;
            p->count = 0;
        }
    }
    if (p == NULL)
    {
        if ((u16)(id - 300) <= 45)
            sub_080C2790(id);
    }
    if ((u16)(id - 0x120) < 12)
        Combatant_RecalcStats(0);
}

// Combatant_GetEquipSlot @ 0x080C343C
/* Slot > 6 returns nothing (the pointer still in r0). */
u32 Combatant_GetEquipSlot(struct Combatant *c, u16 slot)
{
    switch (slot)
    {
    case 0:
        return c->equip[0];
    case 1:
        return c->equip[1];
    case 2:
        return c->equip[2];
    case 3:
        return c->equip[3];
    case 4:
        return c->equip[4];
    case 5:
        return c->equip[5];
    case 6:
        return c->equip[6];
    }
}

// Combatant_SetEquipSlot @ 0x080C34B0
void Combatant_SetEquipSlot(struct Combatant *c, u16 slot, u16 v)
{
    u8 *p;

    switch (slot)
    {
    case 0:
        p = &c->equip[0];
        break;
    case 1:
        p = &c->equip[1];
        break;
    case 2:
        p = &c->equip[2];
        break;
    case 3:
        p = &c->equip[3];
        break;
    case 4:
        p = &c->equip[4];
        break;
    case 5:
        p = &c->equip[5];
        break;
    case 6:
        p = &c->equip[6];
        break;
    default:
        return;
    }
    *p = v;
}

// Stock_CanAddDemon @ 0x080C351C
/* TRUE if the stock has a free slot and no demon of this kind. */
u32 Stock_CanAddDemon(u16 demonId)
{
    struct Combatant *c = Party_GetMember(0x8004);
    s32 used = 0;
    s32 same = 0;
    u32 i;

    for (i = 0; i < 12; i++, c++)
    {
        if (c->unkE != 0)
        {
            used++;
            if (c->demonId == demonId)
                same++;
        }
    }
    return used != 12 && same == 0;

}

// Stock_FindByDemonId @ 0x080C3560
struct Combatant *Stock_FindByDemonId(u16 demonId)
{
    struct Combatant *c = Party_GetMember(0x8004);
    u32 i;

    for (i = 0; i < 12; i++, c++)
    {
        if (c->unkE != 0 && c->demonId == demonId)
            return c;
    }
    return NULL;
}

// Stock_AddCapacity @ 0x080C3598
void Stock_AddCapacity(u16 n)
{
    if ((gGameState.stockMax += n) > 12)
        gGameState.stockMax = 12;
}

// sub_080C35C4 @ 0x080C35C4
void sub_080C35C4(u32 who, u16 v)
{
    Battle_GetCombatant(who - 0x8000)->unk17 = v;
}

// sub_080C35E4 @ 0x080C35E4
s8 sub_080C35E4(u32 who)
{
    return Battle_GetCombatant(who - 0x8000)->unk17;
}

// sub_080C3600 @ 0x080C3600
void sub_080C3600(u32 who, u16 v)
{
    Battle_GetCombatant(who - 0x8000)->unk16 = v;
}

// sub_080C3620 @ 0x080C3620
s8 sub_080C3620(u32 who)
{
    return Battle_GetCombatant(who - 0x8000)->unk16;
}

// Party_SwapSlots @ 0x080C363C
/* Swaps two active-party slots. */
void Party_SwapSlots(u16 a, u16 b)
{
    s32 t = gGameState.order[b];

    gGameState.order[b] = gGameState.order[a];
    gGameState.order[a] = t;
    Party_BuildMemberNameTiles();
    sub_080C6FD8();
}
