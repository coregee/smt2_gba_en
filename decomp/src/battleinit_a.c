/* Battle setup after the m4a library: demon graphics records, clearing the battle block,
   and the random-encounter / scripted battle starts. */

#include "global.h"
#include "battledisp.h"

extern const struct DemonGfxRecord gDemonGfxRecords[];
extern const struct DemonGfxRecord gUnknown_0872F104[];
extern const struct DemonGfxRecord gUnknown_0872F174;

void sub_080EA280(void);
void sub_080C3600(s32 who, s32 state);
u32 sub_080C5D0C(void);
void sub_080ED398(u32 *a, u32 *b, u32 zone);
void sub_080F450C(u32 *a, u32 *b);

// Demon_GetGfxRecord @ 0x080E444C
/* Battle graphics record of demon `id`; 0x12D takes its variant from +0x11A4. */
const struct DemonGfxRecord *Demon_GetGfxRecord(u16 id)
{
    struct C15cBattle *b = BB;

    if (id == 0x12D)
        return &gUnknown_0872F104[b->unk11A4];
    if (id == 0x12E)
        return &gUnknown_0872F174;
    return &gDemonGfxRecords[id];
}

// Battle_ResetGlobals @ 0x080E44A4
void Battle_ResetGlobals(void)
{
    struct C15cBattle *b = BB;

    CpuFill32(0, &gUnk_030063A0, sizeof(gUnk_030063A0));
    b->groups[0] = b->groups[1] = 0xFFFF;
    BattleMsg_SetLocked(0);
    Battle_ClearSpriteTasks();
    sub_080EA280();
    b->unk1188 = 0;
}

// Battle_ClearSpriteTasks @ 0x080E44F8
void Battle_ClearSpriteTasks(void)
{
    struct C15cBattle *b = BB;

    b->tasks[0] = b->tasks[1] = b->tasks[2] = 0;
    ((u32 *)b)[4] = ((u32 *)b)[5] = ((u32 *)b)[6] = ((u32 *)b)[7] = ((u32 *)b)[8] = ((u32 *)b)[9] = 0;
    b->unk119E = 0;
}
// Battle_ResetCombatantStates @ 0x080E4520
void Battle_ResetCombatantStates(void)
{
    s16 i;

    for (i = 0; i < 16; i++)
    {
        s32 v = (i < 4) ? 4 : 10;

        sub_080C35C4(i, v);
        sub_080C3600(i, v);
    }
}
// Battle_StartRandomEncounter @ 0x080E4554
/* Random-encounter battle start: the encounter comes from the dungeon zone table
   (sub_080ED398) or, on the world map, from sub_080F450C. */
void Battle_StartRandomEncounter(void)
{
    struct C15cBattle *b = BB;
    u32 enc, count;
    u32 zone;
    s16 i;

    Battle_ClearSpriteTasks();
    b->unk118C = 0;
    b->unk11AC = 0xFFFF;
    b->unk11AE = -1;
    b->unk11A8 = 0;
    gUnk_030063A0.unk14 = 0;
    switch (GS->unkAC0)
    {
    case 0:
        gUnk_030063A0.unk0C = 2;
        gUnk_030063A0.unk14 = 0;
        zone = sub_080C5D0C() & 0x7F;
        if (zone > 0x6B)
            zone = 0x3E;
        sub_080ED398(&enc, &count, zone);
        b->encounter = enc;
        b->unk99C = count;
        break;
    case 1:
        gUnk_030063A0.unk0C = 1;
        sub_080F450C(&enc, &count);
        b->encounter = enc;
        b->unk99C = count;
        break;
    }
    b->unk000 = 0;
    b->unk974 = 0;
    b->unk970 = 0;
    b->unkF68 = 0;
    b->state = 0;
    b->substate = 0;
    b->phase = 0;
    b->unk97E = 0;
    BattleState_Init();
    b->unkECE = 0;
    b->unkF6A = 0;
    sub_080ED938(0);
    if (b->unkF6A > 0)
        b->unk99C = 1;
    if (b->unk99C == 0)
        b->unk99C = 1;
    b->unk99E = b->unk99C;
    sub_080E74DC();
    for (i = 0; i < 4; i++)
        Combatant_UpdateStats(i);
    gUnk_030063A0.active = 1;
    b->unkF6A = 0;
    b->unk1122 = 0;
    sub_080C7C60();
    BattleMsg_SetLocked(0);
    b->unk1123 = 0;
    gUnk_030063A0.unk06 = 1;
    gUnk_030063A0.unk0A = 0;
    sub_080E5668(sub_080E5674);
    gUnk_030063A0.task18 = Task_Create(gUnknown_086BEF88, 0xFFFF);
    Font_ResetGlyphSpriteCache(0x180);
    b->unk118A = gUnk_030031B4;
}

// Battle_StartWithGroups @ 0x080E471C
/* Scripted battle start with fixed groups (a1, a2) and counts (a3, a4). */
void Battle_StartWithGroups(u16 a1, u16 a3, u16 a2, u16 a4)
{
    struct C15cBattle *b = BB;

    Battle_StartRandomEncounter();
    b->groups[0] = a1;
    b->groups[1] = a2;
    b->counts[0] = a3;
    b->counts[1] = a4;
    b->encounter = 0;
    b->unk99C = 1;
    b->unk99E = 1;
    if (a2 != 0xFFFF)
        sub_080ED938(0xFFFF);
    else
        sub_080ED938(0);
    b->unk1123 = 1;
}
