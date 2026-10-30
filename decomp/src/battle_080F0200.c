#include "global.h"
#include "battle.h"

struct Stats8
{
    u32 a, b;
};

struct EnemyUnit
{
    u8 name[0xC];
    u8 slot;            /* 0x0C */
    u8 race;            /* 0x0D */
    u16 flags;          /* 0x0E */
    u16 unk10;
    u16 id;             /* 0x12 */
    s16 level;          /* 0x14 */
    u8 unk16;
    u8 unk17;
    u16 hp;             /* 0x18 */
    u16 maxHp;
    u16 mp;             /* 0x1C */
    u16 maxMp;
    u8 filler20[8];
    struct Stats8 cur;  /* 0x28 */
    u8 filler30[0x10];
    u8 stats[8];        /* 0x40 */
    u8 derived[0x10];   /* 0x48 */
    u16 unk58;
    u8 filler5A[3];
    u8 skills[32];      /* 0x5D */
};

struct EnemyRecord
{
    s8 level;
    u8 race;
    u16 hp;
    u16 mp;
    u8 stats[6];
    u8 unkC;
    u8 fillerD[4];
    u8 skills[0x11];    /* 0x11 */
    u8 name[1];         /* 0x22 */
};

/* Fills enemy unit slot from demon record id. */
// Battle_InitEnemyUnit @ 0x080F0200
void Battle_InitEnemyUnit(s32 slot, s32 id)
{
    struct BattleFlow *b = BFLOW;
    struct EnemyUnit *u = (struct EnemyUnit *)&b->units[slot];
    struct EnemyRecord *rec = (struct EnemyRecord *)Demon_GetRecord(id);
    u32 zero;
    s32 i, j;

    zero = 0;
    CpuSet(&zero, u, 0x05000020);
    u->slot = slot + 0x10;
    u->id = id;
    u->flags = 0x8000;
    u->level = rec->level;
    u->hp = rec->hp;
    u->maxHp = rec->hp;
    u->mp = rec->mp;
    u->maxMp = rec->mp;
    u->race = rec->race;
    u->unk58 = rec->unkC << 8;
    u->unk17 = 10;
    u->unk16 = 10;
    u->stats[0] = rec->stats[0];
    u->stats[1] = rec->stats[1];
    u->stats[2] = rec->stats[2];
    u->stats[3] = rec->stats[3];
    u->stats[4] = rec->stats[4];
    u->stats[5] = rec->stats[5];
    u->cur = *(struct Stats8 *)u->stats;
    u->unk58 = rec->unkC << 8;
    for (i = 0; i < 32; i++)
        u->skills[i] |= 0xFF;
    for (j = 0, i = 0; i < 7; j++, i++)
        u->skills[j] = rec->skills[i];
    Stats_CalcDerived(u->race, u->stats, u->derived);
    Name_Encode(rec->name, (u8 *)u);
}

// sub_080F030C @ 0x080F030C
u16 sub_080F030C(u16 a, u16 b)
{
    u8 lvl = a >> 8;
    u16 n = a & 0xF;
    u16 v;

    if (n > 7)
    {
        n &= 7;
        n++;
    }
    v = n * lvl;
    if (!(b & 0x80))
        v <<= 3;
    return v;
}

// sub_080F0344 @ 0x080F0344
void sub_080F0344(u16 kind, u16 v)
{
    struct BattleFlow *b = BFLOW;

    switch (kind)
    {
    case 3:
        gUnk_030000AC = b->unk97C;
        b->unk97C = v;
        break;
    case 4:
        gUnk_030000AC = b->unk97E;
        b->unk97E = v;
        break;
    case 0:
        break;
    }
}

// sub_080F038C @ 0x080F038C
s16 sub_080F038C(s16 who, u8 *c)
{
    s16 x = Battle_IsEnemyId(who);
    u16 f = *(u16 *)(c + 0x10);

    if (f & 0x200)
        x = (x == 0);
    if (x == 0)
        Battle_BuildActionTargets(who);
    else
        Battle_BuildTargetList(who);
    return x;
}

// sub_080F03D8 @ 0x080F03D8
u32 sub_080F03D8(s8 kind, s32 id)
{
    if (kind == 11
        && (id == 0x4B || id == 0x4C || id == 0x6D || id == 0x6E || id == 0x6F || id == 0x4E
            || id == 0x4F || id == 0x71 || id == 0x74 || id == 0x7C || id == 0x84 || id == 0x88
            || id == 0x8A || id == 0x8D || id == 0x8E || id == 0x90 || id == 0x91 || id == 0x92))
        return 1;
    return 0;
}
