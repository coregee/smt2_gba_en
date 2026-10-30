#include "global.h"
#include "combatant.h"

s16 Combatant_GetLevel(s32 who);

// Moon_Advance @ 0x080C1D00
/* Advances the moon phase counter by n (wrapping at 0x100) and updates the moon events. */
void Moon_Advance(u16 n)
{
    gGameState.moonPrev = gGameState.moon;
    gGameState.moon += n;
    if (gGameState.moon > 0xFF)
        gGameState.moon &= 0xFF;
    sub_080C1AF4();
    if (BattleFlags_Get() & 0x80)
    {
        u8 c = gGameState.unk18BB;

        if (!(c & 1))
        {
            if ((Moon_GetPhase() & 0xF0) == (c & 0xF0))
            {
                c = 0;
                BattleFlags_Mask(~0x80);
            }
        }
        else
        {
            if ((Moon_GetPhase() & 0xF0) != (c & 0xF0))
                c++;
        }
        gGameState.unk18BB = c;
    }
}

// Moon_GetPhase @ 0x080C1D9C
/* Moon phase (high nibble: 0 = new moon, 0x80 = full moon). */
u32 Moon_GetPhase(void)
{
    return gGameState.moon;
}

// Moon_PhaseChanged @ 0x080C1DB0
/* Whether the last advance changed the moon phase. */
u32 Moon_PhaseChanged(void)
{
    if ((gGameState.moonPrev & 0xF0) != (Moon_GetPhase() & 0xF0))
        return 1;
    return 0;
}

// sub_080C1DE0 @ 0x080C1DE0
void sub_080C1DE0(void)
{
    Moon_Advance(2);
    if (Field_ApplyStepStatusDamageKill(gGameState.unkA3E))
    {
        sub_080B8B68(0x1F, 1);
        Sound_Play(0x12B);
    }
    gGameState.unkA3E++;
}

// sub_080C1E20 @ 0x080C1E20
/* One step on the field: advances the moon, applies poison etc. Returns the mask of party
   members affected. */
u32 sub_080C1E20(void)
{
    u32 mask = 0;

    Moon_Advance(1);
    sub_080C1E60(&mask);
    Field_ApplyStepStatusDamage(gGameState.unkA36, &mask);
    gGameState.unkA36++;
    sub_080C4C98();
    return mask;
}

// sub_080C1E60 @ 0x080C1E60
void sub_080C1E60(u32 *mask)
{
    s32 i;
    s32 who;

    if (Magnetite_Get())
    {
        s32 sum = gGameState.unkAC4;

        for (i = 0; i < 6; i++)
        {
            who = gGameState.order[i];
            if (who != -1)
            {
                if (who > 3)
                    sum += sub_080ED584(Combatant_GetDemonId(who));
            }
        }
        gGameState.unkAC4 = sum % 10;
        sum /= 10;
        sum = -sum;
        if (Magnetite_Add(sum) == 0)
            gGameState.unkAC4 = 0;
    }
    else
    {
        for (i = 0; i < 6; i++)
        {
            who = gGameState.order[i];
            if (who != -1)
            {
                if (who > 3)
                {
                    u32 r = Battle_GetHp(who);

                    if (r == 1)
                        *mask |= r << who;
                    Combatant_Damage(who, 1);
                    sub_080C8490(i);
                    gHudState[0x38] = 1;
                }
            }
        }
        if (gHudState[0x38])
            Sound_Play(0x12B);
    }
}

// sub_080C1F50 @ 0x080C1F50
/* Map cell (x, y) of the current floor to absolute coordinates. */
void sub_080C1F50(u16 x, u16 y, u16 *ox, u16 *oy)
{
    u16 *floor = DungeonMap_GetFloor(*(u16 *)&gUnk_03004614, *(u16 *)&gUnk_03004514);

    *ox = x + floor[4];
    *oy = y + floor[5];
}

// Math_DivRound @ 0x080C1F94
/* a / b rounded to nearest (b = 0 treated as 1). */
s32 Math_DivRound(s32 a, s32 b)
{
    s32 round;

    if (b == 0)
        b = 1;
    if (a % b >= b / 2)
        round = 1;
    else
        round = 0;
    return a / b + round;
}

// sub_080C1FC8 @ 0x080C1FC8
void sub_080C1FC8(u16 *x, u16 *y)
{
    u16 zero = 0;

    switch (gUnk_03003FC4)
    {
    case 0:
        *y = zero;
        *x = 0x28;
        break;
    case 1:
        *y = zero;
        *x = 0x48;
        break;
    case 2:
        *x = zero;
        *y = zero;
        break;
    case 3:
        *x = zero;
        *y = zero;
        break;
    }
}

// sub_080C2000 @ 0x080C2000
/* With field flag 0x80: whether the hero outlevels both demons of the encounter that would
   be rolled (so it is skipped). */
u32 sub_080C2000(s32 mode)
{
    u32 enc[2];
    u16 d0, d1;

    if (!(BattleFlags_Get() & 0x80))
        return 0;
    if (mode == 0)
    {
        u32 zone = ((u16 (*)(void))sub_080C5D0C)() & 0x7F; /* defined as u16; combatant.h says u32 */

        if (zone > 0x6B)
            zone = 0x3E;
        sub_080ED398(&enc[0], &enc[1], zone);
    }
    else
    {
        sub_080F450C(&enc[0], &enc[1]);
    }
    d0 = sub_080ED5B4(enc[0], 0);
    d1 = sub_080ED5B4(enc[0], 1);
    if (Combatant_GetLevel(0) > Demon_GetRecord(d0)[1] || Combatant_GetLevel(0) > Demon_GetRecord(d1)[1])
        return 1;
    return 0;
}

// sub_080C2090 @ 0x080C2090
u32 sub_080C2090(void)
{
    u8 *floor = (u8 *)DungeonMap_GetFloor(*(u16 *)&gUnk_03004614, *(u16 *)&gUnk_03004514);

    floor += gGameState.unkA38 * 0xE8;
    return *(u16 *)(floor + 0x178);
}

// sub_080C20C8 @ 0x080C20C8
u32 sub_080C20C8(void)
{
    if (Flag_Test(0xFF) || sub_080C2090() == 1)
    {
        Encounter_SetCounter(0);
        return 0;
    }
    return 1;
}

// sub_080C20EC @ 0x080C20EC
/* Encounter counter step for the current zone (dungeon). */
void sub_080C20EC(void)
{
    u32 v = ((u16 (*)(void))sub_080C5D0C)() & 0x7F; /* defined as u16; combatant.h says u32 */
    u8 *rec;
    u8 t;

    gUnk_0203A450[0] = Random_Byte();
    gUnk_0203A450[1] = Random_Byte();
    if (v > 0x6B)
        v = 0x3E;
    rec = sub_080C5D48(v & 0x7F);
    v = rec[0];
    v *= 2;
    if (v == 0 || Flag_Test(0xFF))
        goto none;
    if (rec[1] == 0)
        goto add;
    if (Flag_Test(rec[1]))
        t = rec[2];
    else
        t = rec[3];
    if (t != 0xFF)
        goto add;
none:
    Encounter_SetCounter(0);
    return;
add:
    {
        u32 c = Encounter_GetCounter();
        Encounter_SetCounter(c + v);
    }
}

// sub_080C2168 @ 0x080C2168
/* As sub_080C20EC for the zone record of sub_080C5D98. */
void sub_080C2168(void)
{
    u8 *rec = sub_080C5D98();
    u32 rate;
    u8 t;

    rate = rec[0];
    rate *= 2;
    gUnk_0203A450[0] = Random_Byte();
    gUnk_0203A450[1] = Random_Byte();
    if (rate == 0 || Flag_Test(0xFF))
        goto none;
    if (rec[1] == 0)
        goto add;
    if (Flag_Test(rec[1]))
        t = rec[2];
    else
        t = rec[3];
    if (t != 0xFF)
        goto add;
none:
    Encounter_SetCounter(0);
    return;
add:
    {
        u32 c = Encounter_GetCounter();
        Encounter_SetCounter(c + rate);
    }
}

// Encounter_GetDangerLevel @ 0x080C21D0
/* Encounter counter level: 0, 1-250 -> 1, 251-500 -> 2, 501-750 -> 3, else 4. */
u32 Encounter_GetDangerLevel(void)
{
    u16 v = Encounter_GetCounter();
    u32 r;

    if (v == 0)
        r = 0;
    else if (v >= 1 && v <= 250)
        r = 1;
    else if (v >= 251 && v <= 500)
        r = 2;
    else if (v >= 501 && v <= 750)
        r = 3;
    else
        r = 4;
    return r;
}

// Encounter_GetCounter @ 0x080C221C
u16 Encounter_GetCounter(void)
{
    return gGameState.encounter;
}

// Encounter_SetCounter @ 0x080C2230
void Encounter_SetCounter(u16 v)
{
    gGameState.encounter = v;
}

// Random_Byte @ 0x080C2244
u32 Random_Byte(void)
{
    return Random_Next() & 0xFF;
}

// sub_080C2254 @ 0x080C2254
u32 sub_080C2254(s32 base, s32 level)
{
    s32 v = Math_DivRound(level + 3, 4);

    v += 10;
    v *= Random_Byte() & 0xF;
    v += base;
    if (v > 0xFE)
        return 1;
    return 0;
}

// Encounter_Check @ 0x080C2280
/* Whether a random encounter happens now (mode 0: field, else dungeon). */
u32 Encounter_Check(u16 mode)
{
    u16 v;
    s32 x;

    if (Flag_Test(0xFF))
        return 0;
    if (mode == 0)
    {
        if (sub_080C2000(0))
            return 0;
    }
    else if (sub_080C2000(1))
        return 0;
    v = Encounter_GetCounter();
    if (mode == 0)
    {
        if ((s16)v > Random_Byte() * 10)
            return 1;
        return 0;
    }
    return sub_080C2254((s16)((s16)v / 10), 1);
}

// PlayTime_Tick @ 0x080C22E4
/* Play time tick (frames, seconds, minutes, hours); stops at 255:59:59. */
void PlayTime_Tick(void)
{
    u8 *t = gGameState.playTime.raw;
    u32 zero, v;

    v = t[3] + 1;
    zero = 0;
    t[3] = v;
    if ((u8)v > 59)
    {
        t[3] = zero;
        t[2]++;
    }
    if (t[2] > 59)
    {
        t[2] = zero;
        t[1]++;
    }
    if (t[1] > 59)
    {
        t[1] = zero;
        t[0]++;
    }
    if (*(u32 *)t == 0)
    {
        t[3] = 59;
        t[2] = 59;
        t[1] = 59;
        t[0] = 255;
    }
}

// PlayTime_Get @ 0x080C2338
union PlayTime *PlayTime_Get(void)
{
    return &gGameState.playTime;
}
