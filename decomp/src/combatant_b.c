#include "global.h"
#include "combatant.h"

// Combatant_OnStatusChange @ 0x080C084C
/* Called when a combatant's status flags change: if bit 0x800 toggled, recomputes its stats
   (and refills HP/MP of a living human), then sub_080C65C8. */
void Combatant_OnStatusChange(s32 who, u16 newFlags, u16 oldFlags)
{
    struct Combatant *c = Battle_GetCombatant(who + 0x8000);

    if (newFlags & 0x800)
    {
        if (!(oldFlags & 0x800))
            goto changed;
        return;
    }
    if (!(oldFlags & 0x800))
        return;
changed:
    if (who <= 3)
        Combatant_RecalcStats(who);
    else
        Combatant_CalcDerived(c);
    if (!(newFlags & 0x8000) && who <= 3)
    {
        c->hp = c->maxHp;
        c->mp = c->maxMp;
    }
    sub_080C65C8();
}

// Combatant_ClearStatus @ 0x080C08BC
/* Clears status flags: flags &= mask. */
void Combatant_ClearStatus(s32 who, u16 mask)
{
    struct Combatant *c = Battle_GetCombatant(who + 0x8000);
    u16 old = c->flags;

    c->flags = mask & old;
    Combatant_OnStatusChange(who, c->flags, old);
}

// sub_080C08E8 @ 0x080C08E8
void sub_080C08E8(s32 who, u16 bits)
{
    Combatant_SetStatus(who, bits);
}

// Combatant_SetStatus @ 0x080C08F8
/* Sets status bits (0 clears all). For each bit: result |= 1 when already set, 2 when a
   blocking status (gUnknown_081A6044) is present; otherwise the bit is set after masking
   with gUnknown_081A6064. */
u32 Combatant_SetStatus(s32 who, u16 bits)
{
    struct Combatant *c = Battle_GetCombatant(who + 0x8000);
    u16 rest = bits;
    u32 result = 0;
    u16 old = c->flags;
    s32 i;

    if (rest == 0)
    {
        c->flags = result;
        return 0;
    }
    for (i = 15; i >= 0; i--)
    {
        if (rest & 1)
        {
            u16 f;

            rest >>= 1;
            f = c->flags;
            if (f & bits)
            {
                result |= 1;
            }
            else if (f & gUnknown_081A6044[i])
            {
                result |= 2;
            }
            else
            {
                f = (f & gUnknown_081A6064[i]) | bits;
                c->flags = f;
                Combatant_OnStatusChange(who, f, old);
            }
        }
        else
        {
            rest >>= 1;
        }
    }
    return result;
}

// Race_GetParentId @ 0x080C09A4
s32 Race_GetParentId(s32 race)
{
    return gUnknown_081A6084[race];
}

// Combatant_IsUsed @ 0x080C09B0
/* Whether record `who` is in use. */
s32 Combatant_IsUsed(s32 who)
{
    if (Battle_GetCombatant(who + 0x8000)->unkE != 0)
        return 1;
    return 0;
}

// sub_080C09D4 @ 0x080C09D4
/* In use and none of the status bits 0xB160. */
s32 sub_080C09D4(s32 who)
{
    if (Combatant_IsUsed(who) && !(Combatant_GetStatus(who) & 0xB160))
        return 1;
    return 0;
}

// Combatant_IsAlive @ 0x080C0A00
/* In use and alive (status bit 0x8000 clear). */
s32 Combatant_IsAlive(s32 who)
{
    if (Combatant_IsUsed(who) && !Combatant_IsDead(who))
        return 1;
    return 0;
}

// Combatant_IsHpFull @ 0x080C0A24
s32 Combatant_IsHpFull(s32 who)
{
    struct Combatant *c = Battle_GetCombatant(who + 0x8000);

    if (c->hp < c->maxHp)
        return 0;
    return 1;
}

// Combatant_IsMpFull @ 0x080C0A50
s32 Combatant_IsMpFull(s32 who)
{
    struct Combatant *c = Battle_GetCombatant(who + 0x8000);

    if (c->mp < c->maxMp)
        return 0;
    return 1;
}

// Combatant_RestoreHp @ 0x080C0A7C
void Combatant_RestoreHp(s32 who)
{
    struct Combatant *c = Battle_GetCombatant(who + 0x8000);

    if (c->hp < c->maxHp)
        c->hp = c->maxHp;
}

// Combatant_RestoreMp @ 0x080C0AA8
void Combatant_RestoreMp(s32 who)
{
    struct Combatant *c = Battle_GetCombatant(who + 0x8000);

    if (c->mp < c->maxMp)
        c->mp = c->maxMp;
}

// Combatant_ChangeHp @ 0x080C0AD4
/* Adds delta to HP (not raised further when already above max), floors at 0 and caps party
   records (who < 16) at 999. Returns the new HP. */
s32 Combatant_ChangeHp(s32 who, s32 delta)
{
    struct Combatant *c = Battle_GetCombatant(who + 0x8000);

    if (delta > 0 && c->hp > c->maxHp)
        return c->hp;
    c->hp += delta;
    if (c->hp < 0)
        c->hp = 0;
    else if (who < 16 && c->hp > 999)
        c->hp = 999;
    return c->hp;
}

// Combatant_ChangeHpCapped @ 0x080C0B30
/* As Combatant_ChangeHp, then caps HP at max unless it was already above. */
s32 Combatant_ChangeHpCapped(s32 who, s32 delta)
{
    struct Combatant *c = Battle_GetCombatant(who + 0x8000);
    s32 over = 0;

    if (c->hp > c->maxHp)
        over = 1;
    Combatant_ChangeHp(who, delta);
    if (c->hp < 0)
        c->hp = 0;
    else if (c->hp > c->maxHp && !over)
        c->hp = c->maxHp;
    return c->hp;
}

// Combatant_ChangeHpPercent @ 0x080C0B8C
s32 Combatant_ChangeHpPercent(s32 who, s32 percent)
{
    struct Combatant *c = Battle_GetCombatant(who + 0x8000);

    return Combatant_ChangeHp(who, c->hp * percent / 100);
}

// Combatant_ChangeMp @ 0x080C0BBC
/* MP version of Combatant_ChangeHp (always capped at 999). */
s32 Combatant_ChangeMp(s32 who, s32 delta)
{
    struct Combatant *c = Battle_GetCombatant(who + 0x8000);

    if (delta > 0 && c->mp > c->maxMp)
        return c->mp;
    c->mp += delta;
    if (c->mp < 0)
        c->mp = 0;
    else if (c->mp > 999)
        c->mp = 999;
    return c->mp;
}

// Combatant_ChangeMpCapped @ 0x080C0C14
s32 Combatant_ChangeMpCapped(s32 who, s32 delta)
{
    struct Combatant *c = Battle_GetCombatant(who + 0x8000);
    s32 over = 0;

    if (c->mp > c->maxMp)
        over = 1;
    Combatant_ChangeMp(who, delta);
    if (c->mp < 0)
        c->mp = 0;
    else if (c->mp > c->maxMp && !over)
        c->mp = c->maxMp;
    return c->mp;
}

// Combatant_Damage @ 0x080C0C70
/* Deals damage; at 0 HP sets the dead status. */
void Combatant_Damage(s32 who, s32 damage)
{
    Battle_GetHp(who);
    if (Combatant_ChangeHp(who, -damage) <= 0)
    {
        Combatant_GetStatus(who);
        Combatant_SetStatus(who, 0x8000);
        if (who > 3)
            sub_080F4190(who);
        Party_FixFormation();
    }
}

// sub_080C0CAC @ 0x080C0CAC
u16 sub_080C0CAC(s32 who, s32 second)
{
    struct Combatant *c = Battle_GetCombatant(who + 0x8000);

    if (!second)
        return c->derived[0];
    return c->derived[2];
}

// sub_080C0CD4 @ 0x080C0CD4
u16 sub_080C0CD4(s32 who, s32 second)
{
    struct Combatant *c = Battle_GetCombatant(who + 0x8000);

    if (!second)
        return c->derived[1];
    return c->derived[3];
}

// sub_080C0CFC @ 0x080C0CFC
u16 sub_080C0CFC(s32 who)
{
    return Battle_GetCombatant(who + 0x8000)->derived[6];
}

// sub_080C0D18 @ 0x080C0D18
u16 sub_080C0D18(s32 who)
{
    return Battle_GetCombatant(who + 0x8000)->derived[7];
}

// sub_080C0D34 @ 0x080C0D34
u16 sub_080C0D34(s32 who)
{
    return Battle_GetCombatant(who + 0x8000)->derived[5];
}

// sub_080C0D50 @ 0x080C0D50
u16 sub_080C0D50(s32 who)
{
    return Battle_GetCombatant(who + 0x8000)->derived[4];
}

// Combatant_GetStrength @ 0x080C0D6C
u16 Combatant_GetStrength(s32 who)
{
    return (s8)Battle_GetCombatant(who + 0x8000)->total.v[0];
}

// Combatant_GetIntelligence @ 0x080C0D90
u16 Combatant_GetIntelligence(s32 who)
{
    return (s8)Battle_GetCombatant(who + 0x8000)->total.v[1];
}

// Combatant_GetMagic @ 0x080C0DB4
u16 Combatant_GetMagic(s32 who)
{
    return (s8)Battle_GetCombatant(who + 0x8000)->total.v[2];
}

// Combatant_GetVitality @ 0x080C0DD8
u16 Combatant_GetVitality(s32 who)
{
    return (s8)Battle_GetCombatant(who + 0x8000)->total.v[3];
}

// Combatant_GetAgility @ 0x080C0DFC
u16 Combatant_GetAgility(s32 who)
{
    return (s8)Battle_GetCombatant(who + 0x8000)->total.v[4];
}

// Combatant_GetLuck @ 0x080C0E20
u16 Combatant_GetLuck(s32 who)
{
    return (s8)Battle_GetCombatant(who + 0x8000)->total.v[5];
}

// Combatant_GetStat @ 0x080C0E44
/* Total stat `stat` (0-5). Returns an uninitialised value for other stats. */
u16 Combatant_GetStat(s32 who, u32 stat)
{
    u16 v;

    switch (stat)
    {
    case 0:
        v = Combatant_GetStrength(who);
        break;
    case 1:
        v = Combatant_GetIntelligence(who);
        break;
    case 2:
        v = Combatant_GetMagic(who);
        break;
    case 3:
        v = Combatant_GetVitality(who);
        break;
    case 4:
        v = Combatant_GetAgility(who);
        break;
    case 5:
        v = Combatant_GetLuck(who);
        break;
    }
    return v;
}

// Stat_ClampBase @ 0x080C0EAC
/* Clamps a base stat to 0-40. */
s32 Stat_ClampBase(s32 v)
{
    if (v < 0)
        v = 0;
    else if (v > 40)
        v = 40;
    return v;
}

// Combatant_AddBaseStat @ 0x080C0EC0
/* Adds delta to base stat `stat` (clamped 0-40) and returns it; uninitialised for other stats. */
s32 Combatant_AddBaseStat(s32 who, u32 stat, s32 delta)
{
    s8 *base = (s8 *)Battle_GetCombatant(who + 0x8000)->base.v;
    s32 v;

    switch (stat)
    {
    case 0:
        v = base[0] = Stat_ClampBase(base[0] + delta);
        break;
    case 1:
        v = base[1] = Stat_ClampBase(base[1] + delta);
        break;
    case 2:
        v = base[2] = Stat_ClampBase(base[2] + delta);
        break;
    case 3:
        v = base[3] = Stat_ClampBase(base[3] + delta);
        break;
    case 4:
        v = base[4] = Stat_ClampBase(base[4] + delta);
        break;
    case 5:
        v = base[5] = Stat_ClampBase(base[5] + delta);
        break;
    }
    return v;
}

// Combatant_GetBaseStat @ 0x080C0F64
s32 Combatant_GetBaseStat(s32 who, u32 stat)
{
    return Combatant_AddBaseStat(who, stat, 0);
}

// sub_080C0F70 @ 0x080C0F70
void sub_080C0F70(s32 who, u32 v)
{
    Battle_GetCombatant(who + 0x8000)->unk8 = v;
}

// Combatant_GetLevel @ 0x080C0F8C
u8 Combatant_GetLevel(s32 who)
{
    return Battle_GetCombatant(who + 0x8000)->level;
}

// Combatant_SetLevel @ 0x080C0FA4
void Combatant_SetLevel(s32 who, s32 level)
{
    Battle_GetCombatant(who + 0x8000)->level = level;
}

// Party_CountMembers @ 0x080C0FC0
/* Number of occupied party positions. */
s32 Party_CountMembers(void)
{
    s32 n = 0;
    s32 i;

    for (i = 0; i < 6; i++)
    {
        if (gGameState.order[i] >= 0)
            n++;
    }
    return n;
}

// Stock_FindDemonIndex @ 0x080C0FE8
/* Stock record (4-15) holding demon `demonId`, or -1. */
s32 Stock_FindDemonIndex(s32 demonId)
{
    s32 i;

    for (i = 4; i < 16; i++)
    {
        if (Combatant_IsUsed(i) && Combatant_GetDemonId(i) == demonId)
            return i;
    }
    return -1;
}

// Stock_FindFreeSlot @ 0x080C101C
/* First free stock record within the current stock size, or -1. */
s32 Stock_FindFreeSlot(void)
{
    s32 i;
    s32 n = Stock_GetCapacity();

    for (i = 4; i < n + 4; i++)
    {
        if (!Combatant_IsUsed(i))
            return i;
    }
    return -1;
}

// Stock_GetCapacity @ 0x080C104C
/* Demon stock size: 6, 9 with flag 0xE6, plus 3 with flag 0xE7. */
s32 Stock_GetCapacity(void)
{
    s32 n = 6;

    if (Flag_Test(0xE6))
        n = 9;
    if (Flag_Test(0xE7))
        n += 3;
    return n;
}

// Exp_GetLevel @ 0x080C1070
/* Level reached with `exp` experience (table gUnknown_081A60B4, max 99). */
s32 Exp_GetLevel(s32 exp)
{
    s32 i;

    for (i = 1; i < 100; i++)
    {
        if (gUnknown_081A60B4[i] > exp)
            return i;
    }
    return 99;
}

// Exp_GetForLevel @ 0x080C1098
s32 Exp_GetForLevel(s32 level)
{
    return gUnknown_081A60B4[level - 1];
}

// sub_080C10A8 @ 0x080C10A8
s32 sub_080C10A8(s32 id)
{
    return sub_080ED560(id) << 5;
}

// sub_080C10B4 @ 0x080C10B4
s32 sub_080C10B4(s32 item)
{
    u8 n = Inventory_GetCount(item);

    return n + Party_CountEquipped(0xFF, item & 0xFF);
}

// sub_080C10E0 @ 0x080C10E0
s32 sub_080C10E0(void)
{
    return 0;
}

// sub_080C10E4 @ 0x080C10E4
u8 *sub_080C10E4(u16 i)
{
    return gGameState.names[i];
}

// Game_NewGame @ 0x080C10F4
/* New game: clears the game state and sets up the starting party and map. */
void Game_NewGame(void)
{
    u32 i, j;

    DmaFill32(3, 0, &gGameState, sizeof(gGameState));
    for (i = 0; i < 4; i++)
        Party_InitMember(&gGameState.members[i], i);
    Combatant_RecalcStats(0);
    gGameState.stockMax = Stock_GetCapacity();
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 8; j++)
            gGameState.names[i][j] = gUnknown_081A6244[i][j];
    }
    gGameState.order[5] = gGameState.order[4] = gGameState.order[3] = gGameState.order[2]
        = gGameState.order[1] = gGameState.order[0] = 0xFF;
    for (i = 0; i < 4; i++)
    {
        sub_080BF8D8(i);
        gGameState.members[i].hp = gGameState.members[i].maxHp;
        gGameState.members[i].mp = gGameState.members[i].maxMp;
    }
    Party_Add(0);
    gGameState.unk114C[0].a = 0xFF;
    gGameState.unk114C[1].a = 0xFF;
    gGameState.unk114C[2].a = 0xFF;
    gGameState.unk114C[3].a = 0xFF;
    gGameState.unk114C[4].a = 0xFF;
    gGameState.unk114C[5].a = 0xFF;
    gGameState.unk114C[6].a = 0xFF;
    gGameState.unk114C[7].a = 0xFF;
    for (i = 0; i < 12; i++)
    {
        for (j = 12; j < 16; j++)
            Automap_SetVisitedRaw(j, i);
    }
    Automap_ClearVisitedRaw(13, 1);
    Automap_ClearVisitedRaw(13, 5);
    Automap_ClearVisitedRaw(12, 10);
    Automap_ClearVisitedRaw(12, 11);
    Automap_ClearVisitedRaw(13, 11);
    gGameState.moon = 0x80;
    gGameState.unk18B4 = 0;
    gGameState.unk18B5 = 0xFF;
    gGameState.unk18B6 = 0;
    Battle_ResetCombatantStates();
    sub_080C271C();
    sub_080C27F0();
    sub_080C2968();
    ComboBits_Clear();
    gGameState.unk18A6 = 0xFFFF;
    gGameState.unkAC0 = 0;
}

// sub_080C12BC @ 0x080C12BC
void sub_080C12BC(void)
{
}

// sub_080C12C0 @ 0x080C12C0
void sub_080C12C0(u16 a, u16 b, u16 c)
{
    gUnk_03004610 = a;
    gUnk_03004514 = b;
    gUnk_03004614 = c;
    gUnk_03004544 = 0;
    SetMainCallback(sub_080C1560);
}

// sub_080C1300 @ 0x080C1300
void sub_080C1300(u16 a)
{
    gUnk_03004544 = 2;
    gUnk_030045FC = a;
    SetMainCallback(sub_080C1560);
}

// sub_080C1328 @ 0x080C1328
void sub_080C1328(void)
{
    DmaFill32(3, 0, (void *)0x06008000, 0x3C00);
    DmaCopy32(3, gUnknown_081A91B8, (void *)0x0600BC00, 0x4400);
    DmaCopy32(3, gUnknown_081B13B8, (void *)0x06010000, 0x2000);
}

// sub_080C1384 @ 0x080C1384
void sub_080C1384(void)
{
    Palette_CopyWithEffect(3, gUnknown_081B6E30, gPaletteTarget, 0x200, 0x20);
    gPaletteTarget[0] = 0;
    Palette_CopyWithEffect(3, gUnknown_081B6C30, gPaletteTarget + 0x100, 0x200, 0x20);
    gPaletteTarget[0x100] = 0;
    if (!(gUnk_0200AB04 & 0x7FFF))
        sub_080C67C0(gPaletteTarget, 7);
    else
        sub_080C67C0(gPaletteTarget, 12);
}

// sub_080C13FC @ 0x080C13FC
void sub_080C13FC(u16 *p)
{
    *p &= ~0x40;
}
