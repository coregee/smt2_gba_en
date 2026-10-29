/* Item-demon fusions, the accident roll, the result verdict and commit, 0x0815AE84-0x0815B824. */
#include "global.h"
#include "fusion.h"

/* gUnk_0203B868 as a whole (fusion.h's struct FusionCalc stops at 0xA8). */
struct FusionWork
{
    u8 cand[3];         /* 0x000 */
    u8 pad003[0xD];
    u8 candLv[3];       /* 0x010 */
    u8 pad013[0x80 - 0x13];
    u8 skillKind;       /* 0x080: skill class of the result (record byte 0x1E & 0xF) */
    s8 nA;              /* 0x081: entries in inherit[] */
    s8 nB;              /* 0x082: entries in x290.list[] */
    u8 skill;           /* 0x083: skill being looked at */
    u16 save[3];        /* 0x084 */
    u16 orig[3];        /* 0x08A: the materials as chosen */
    u16 ids[3];         /* 0x090: the materials, sorted */
    u8 race[3];         /* 0x096 */
    u8 align[3];        /* 0x099 */
    u8 level[3];        /* 0x09C */
    u8 pad09F;
    u16 result;         /* 0x0A0 */
    u8 resRace;         /* 0x0A2 */
    s8 unkA3;           /* 0x0A3 */
    u8 unkA4;           /* 0x0A4 */
    u8 unkA5;           /* 0x0A5 */
    u8 unkA6;           /* 0x0A6: result flags */
    u8 pad0A7;
    u16 unkA8;          /* 0x0A8 */
    u8 pad0AA[6];
    u8 skills[0xD0];    /* 0x0B0: the result's skills, 0xFF ends (= gUnk_0203B918) */
    u8 inherit[0xD0];   /* 0x180: inheritable skills of the result's class */
    u8 innate[0x20];    /* 0x250: the result's own skills of its class */
    u8 others[0x20];    /* 0x270: the result's other own skills */
    union
    {
        u16 index;      /* 0x290: table index, then result (item fusions) */
        u8 list[0x20];  /* 0x290: the materials' other skills (also read as others[0x20 + i]) */
    } x290;
};

#define sCalc (*(struct FusionWork *)&gUnk_0203B868)

u32 Fusion_ThreeTwoRace8(void);
u32 Fusion_ThreeRace8(void);
void Fusion_SwapMaterials(u16 a, u16 b);
u32 Fusion_ThreeTwoRace16(void);
u32 Fusion_ThreeAllRace16(void);
u32 Fusion_ThreeFallback(void);
void Fusion_BuildResultSkills(void);
void Fusion_BuildSkillsNoClass(void);
void Fusion_AppendMaterialSkills(u8 a, u8 b);
void sub_0815AAC4(void);
void SkillList_SortAscending(u8 *list);
void SkillList_SortDescending(u8 *list);
void Fusion_CollectMaterialSkills(u16 id);
u32 Fusion_HasOwnOtherSkill(u8 skill);
u32 Fusion_IsSkillInherited(void);
u32 Fusion_IsSkillCollected(void);
u16 Skill_GetClass(u16 skill);
u32 Fusion_CalcItemThree(void);
u32 Fusion_CalcItemDemon(void);
u32 Fusion_CalcItemPair(void);
void sub_0815B248(void);
struct Combatant *Fusion_FindKeptMaterial(void);

extern const u8 gUnknown_087F1C53[];   /* three-way item fusions: a, b, c, result; 30 entries */
extern const u8 gUnknown_087F1B13[];   /* [item - 0x40][10] second material (0x80 | race) */
extern const u8 gUnknown_087F1BB3[];   /* [item - 0x40][10] result */
u8 *sub_080BF5C0(u16 id);
u32 sub_0815BA28(u16 id);
extern const u8 gUnknown_087F198B[];   /* result of three race-8 materials, by the first unused id 0x32-0x39 */
extern const u8 gUnknown_087F1993[];   /* [12][12] alignment pair of the last two materials -> column */
extern const u8 gUnknown_087F1A23[];   /* [alignment of the first][0x16] -> result race, 0xFF accident */

/* Item-demon fusion (Fusion_GetDemonByIndex ids 0x40+): ids[2] == 0xFFFF two item demons
   (Fusion_CalcItemPair), ids[1] == 0xFFFF an item demon and a demon (Fusion_CalcItemDemon), else three
   (Fusion_CalcItemThree). ids[] are kept. */
// Fusion_CalcItem @ 0x0815AE84
u32 Fusion_CalcItem(void)
{
    u32 r;

    sCalc.orig[0] = sCalc.ids[0];
    sCalc.orig[1] = sCalc.ids[1];
    sCalc.orig[2] = sCalc.ids[2];
    if (sCalc.orig[2] == 0xFFFF)
        r = Fusion_CalcItemPair();
    else if (sCalc.orig[1] == 0xFFFF)
        r = Fusion_CalcItemDemon();
    else
        r = Fusion_CalcItemThree();
    sCalc.ids[0] = sCalc.orig[0];
    sCalc.ids[1] = sCalc.orig[1];
    sCalc.ids[2] = sCalc.orig[2];
    return r;
}

/* Three-material item fusion: table 0x087F1C53 {a, b, c, result}, c must match ids[2], a and
   b ids[0] and ids[1] in either order. */
// Fusion_CalcItemThree @ 0x0815AF00
u32 Fusion_CalcItemThree(void)
{
    u16 i;
    u16 a, b;

    for (i = 0; i < 0x78; i += 4)
    {
        if (gUnknown_087F1C53[i + 2] == sCalc.ids[2])
        {
            a = gUnknown_087F1C53[i];
            b = gUnknown_087F1C53[i + 1];
            if ((a == sCalc.ids[0] && b == sCalc.ids[1]) || (a == sCalc.ids[1] && b == sCalc.ids[0]))
            {
                u8 v = gUnknown_087F1C53[i + 3];
                sCalc.x290.index = v;
                sCalc.result = v;
                return 1;
            }
        }
    }
    sCalc.x290.index = 0xFF;
    sCalc.result = 0xFF;
    return 0;
}

/* Item demon ids[0] with demon ids[2]: entries 0-4 of the item demon's row in 0x087F1B13 are
   a demon id, or 0x80 | race to accept any demon of that race; the result is the same entry
   of 0x087F1BB3. */
/* NONMATCHING: register allocation of the table index and race pointer differs. */
// Fusion_CalcItemDemon @ 0x0815AFB0
#ifdef NONMATCHING
u32 Fusion_CalcItemDemon(void)
{
    u16 idx = (sCalc.ids[0] - 0x40) * 10;
    u16 i;
    u8 v;

    for (i = 0; i < 5; i++, idx++)
    {
        v = gUnknown_087F1B13[idx];
        if (v & 0x80)
        {
            sCalc.x290.index = idx;
            sCalc.resRace = v & 0x3F;
            if (Demon_GetRace(sCalc.ids[2]) != sCalc.resRace)
            {
                idx = sCalc.x290.index;
            }
            else
            {
                v = gUnknown_087F1BB3[sCalc.x290.index];
                sCalc.x290.index = v;
                sCalc.result = v;
                return 1;
            }
        }
        else if (v == sCalc.ids[2])
        {
            v = gUnknown_087F1BB3[idx];
            sCalc.x290.index = v;
            sCalc.result = v;
            return 1;
        }
    }
    sCalc.x290.index = 0xFF;
    sCalc.result = 0xFF;
    sCalc.unkA6 = 0x40;
    return 0;
}
#else
NAKED
u32 Fusion_CalcItemDemon(void)
{
    asm_unified(
        ".L0815AFB0:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sb\n"
        "    mov r6, r8\n"
        "    push {r6, r7}\n"
        "    ldr r3, .L0815B014\n"
        "    adds r0, r3, #0\n"
        "    adds r0, #0x90\n"
        "    ldrh r1, [r0]\n"
        "    subs r1, #0x40\n"
        "    lsls r0, r1, #2\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #0x11\n"
        "    lsrs r2, r0, #0x10\n"
        "    movs r6, #0\n"
        "    adds r5, r3, #0\n"
        "    mov sb, r5\n"
        "    movs r0, #0xa2\n"
        "    adds r0, r0, r5\n"
        "    mov r8, r0\n"
        "    adds r7, r5, #0\n"
        "    adds r7, #0x94\n"
        ".L0815AFDA:\n"
        "    ldr r0, .L0815B018\n"
        "    adds r0, r2, r0\n"
        "    ldrb r1, [r0]\n"
        "    movs r0, #0x80\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L0815B030\n"
        "    movs r4, #0xa4\n"
        "    lsls r4, r4, #2\n"
        "    add r4, sb\n"
        "    strh r2, [r4]\n"
        "    movs r0, #0x3f\n"
        "    ands r1, r0\n"
        "    mov r2, r8\n"
        "    strb r1, [r2]\n"
        "    ldrh r0, [r7]\n"
        "    bl Demon_GetRace\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    mov r0, r8\n"
        "    ldrb r0, [r0]\n"
        "    cmp r2, r0\n"
        "    beq .L0815B020\n"
        "    ldrh r2, [r4]\n"
        "    ldr r1, .L0815B01C\n"
        "    adds r5, r4, r1\n"
        "    b .L0815B054\n"
        "    .byte 0x00, 0x00\n"
        ".L0815B014: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L0815B018: .4byte gUnknown_087F1B13\n"
        ".L0815B01C: .4byte 0xFFFFFD70\n"
        ".L0815B020:\n"
        "    ldrh r2, [r4]\n"
        "    ldr r0, .L0815B02C\n"
        "    adds r0, r2, r0\n"
        "    ldrb r1, [r0]\n"
        "    strh r1, [r4]\n"
        "    b .L0815B044\n"
        ".L0815B02C: .4byte gUnknown_087F1BB3\n"
        ".L0815B030:\n"
        "    ldrh r0, [r7]\n"
        "    cmp r1, r0\n"
        "    bne .L0815B054\n"
        "    ldr r0, .L0815B050\n"
        "    adds r0, r2, r0\n"
        "    ldrb r1, [r0]\n"
        "    movs r2, #0xa4\n"
        "    lsls r2, r2, #2\n"
        "    adds r0, r5, r2\n"
        "    strh r1, [r0]\n"
        ".L0815B044:\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0xa0\n"
        "    strh r1, [r0]\n"
        "    movs r0, #1\n"
        "    b .L0815B07E\n"
        "    .byte 0x00, 0x00\n"
        ".L0815B050: .4byte gUnknown_087F1BB3\n"
        ".L0815B054:\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r6, #4\n"
        "    bls .L0815AFDA\n"
        "    movs r1, #0xa4\n"
        "    lsls r1, r1, #2\n"
        "    adds r0, r5, r1\n"
        "    movs r1, #0xff\n"
        "    strh r1, [r0]\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0xa0\n"
        "    strh r1, [r0]\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0xa6\n"
        "    movs r0, #0x40\n"
        "    strb r0, [r1]\n"
        "    movs r0, #0\n"
        ".L0815B07E:\n"
        "    pop {r3, r4}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

/* Two item demons: entries 5-9 of ids[0]'s row in 0x087F1B13 hold the partner ids[1], the
   result is the same entry of 0x087F1BB3. */
// Fusion_CalcItemPair @ 0x0815B08C
u32 Fusion_CalcItemPair(void)
{
    u16 base = (sCalc.ids[0] - 0x40) * 10;
    u16 i;

    for (i = 5; i < 10; i++)
    {
        if (gUnknown_087F1B13[base + i] == sCalc.ids[1])
        {
            u8 v = gUnknown_087F1BB3[base + i];
            sCalc.x290.index = v;
            sCalc.result = v;
            return 1;
        }
    }
    sCalc.x290.index = 0xFF;
    sCalc.result = 0xFF;
    sCalc.unkA6 = 0x40;
    return 0;
}

/* Fusion accident roll (sub_0815739C, modes 2 and 3): unless flag 0xD8 is set, only when
   Random_Byte() & 0xFF is 0. Picks a random allowed demon not in the stock with a level in
   [hero + 16 - 25, hero + 16) for two materials or [hero + 26 - 40, hero + 26) for three
   (cap 0x4B); after 32 misses demon 0xFB if not in the stock (else retries). 0xFFFF: none. */
/* NONMATCHING: one register copy of the random id is coalesced away. */
// Fusion_RollAccident @ 0x0815B11C
#ifdef NONMATCHING
u16 Fusion_RollAccident(void)
{
    u32 rnd = Random_Byte() & 0xFF;
    u16 i;
    u16 id;
    u8 lv;

    if (!Flag_Test(0xD8) && rnd != 0)
        return 0xFFFF;
    sCalc.unkA4 |= 4;
    lv = gGameState.members[0].level;
    if (sCalc.orig[2] == 0xFFFF)
    {
        if (lv <= 0x3A)
            sCalc.level[0] = lv + 0x10;
        else
            sCalc.level[0] = 0x4B;
        if (sCalc.level[0] > 0x19)
            sCalc.level[1] = sCalc.level[0] - 0x19;
        else
            sCalc.level[1] = 0;
    }
    else
    {
        if (lv <= 0x30)
            sCalc.level[0] = lv + 0x1A;
        else
            sCalc.level[0] = 0x4B;
        if (sCalc.level[0] > 0x28)
            sCalc.level[1] = sCalc.level[0] - 0x28;
        else
            sCalc.level[1] = 0;
    }
retry:
    for (i = 0; i < 0x20; i++)
    {
        u16 r = sub_08159144();

        if (r != 0xFF)
        {
            id = r;
            if (sub_0815BA28(id))
            {
                lv = Demon_GetLevel(id);
                if (lv < sCalc.level[0] && lv >= sCalc.level[1] && !Stock_FindByDemonId(id))
                    break;
            }
        }
    }
    if (i == 0x20)
    {
        id = 0xFB;
        if (Stock_FindByDemonId(0xFB))
            goto retry;
    }
    sCalc.result = id;
    sCalc.resRace = Demon_GetRace(sCalc.result);
    return sCalc.result;
}
#else
NAKED
u16 Fusion_RollAccident(void)
{
    asm_unified(
        ".L0815B11C:\n"
        "    push {r4, r5, r6, lr}\n"
        "    bl Random_Byte\n"
        "    adds r4, r0, #0\n"
        "    movs r0, #0xff\n"
        "    ands r4, r0\n"
        "    movs r0, #0xd8\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L0815B140\n"
        "    cmp r4, #0\n"
        "    beq .L0815B140\n"
        "    ldr r0, .L0815B13C\n"
        "    b .L0815B23C\n"
        "    .byte 0x00, 0x00\n"
        ".L0815B13C: .4byte 0x0000FFFF\n"
        ".L0815B140:\n"
        "    ldr r3, .L0815B170\n"
        "    adds r2, r3, #0\n"
        "    adds r2, #0xa4\n"
        "    ldrb r1, [r2]\n"
        "    movs r0, #4\n"
        "    orrs r0, r1\n"
        "    strb r0, [r2]\n"
        "    ldr r0, .L0815B174\n"
        "    ldrb r2, [r0, #0xd]\n"
        "    adds r0, r3, #0\n"
        "    adds r0, #0x8e\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L0815B178\n"
        "    cmp r1, r0\n"
        "    bne .L0815B194\n"
        "    cmp r2, #0x3a\n"
        "    bhi .L0815B17C\n"
        "    adds r1, r2, #0\n"
        "    adds r1, #0x10\n"
        "    adds r0, r3, #0\n"
        "    adds r0, #0x9c\n"
        "    strb r1, [r0]\n"
        "    b .L0815B184\n"
        "    .byte 0x00, 0x00\n"
        ".L0815B170: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L0815B174: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L0815B178: .4byte 0x0000FFFF\n"
        ".L0815B17C:\n"
        "    adds r1, r3, #0\n"
        "    adds r1, #0x9c\n"
        "    movs r0, #0x4b\n"
        "    strb r0, [r1]\n"
        ".L0815B184:\n"
        "    adds r0, r3, #0\n"
        "    adds r0, #0x9c\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0x19\n"
        "    bls .L0815B1C2\n"
        "    adds r1, r0, #0\n"
        "    subs r1, #0x19\n"
        "    b .L0815B1BA\n"
        ".L0815B194:\n"
        "    cmp r2, #0x30\n"
        "    bhi .L0815B1A4\n"
        "    adds r1, r2, #0\n"
        "    adds r1, #0x1a\n"
        "    adds r0, r3, #0\n"
        "    adds r0, #0x9c\n"
        "    strb r1, [r0]\n"
        "    b .L0815B1AC\n"
        ".L0815B1A4:\n"
        "    adds r1, r3, #0\n"
        "    adds r1, #0x9c\n"
        "    movs r0, #0x4b\n"
        "    strb r0, [r1]\n"
        ".L0815B1AC:\n"
        "    adds r0, r3, #0\n"
        "    adds r0, #0x9c\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0x28\n"
        "    bls .L0815B1C2\n"
        "    adds r1, r0, #0\n"
        "    subs r1, #0x28\n"
        ".L0815B1BA:\n"
        "    adds r0, r3, #0\n"
        "    adds r0, #0x9d\n"
        "    strb r1, [r0]\n"
        "    b .L0815B1CA\n"
        ".L0815B1C2:\n"
        "    adds r1, r3, #0\n"
        "    adds r1, #0x9d\n"
        "    movs r0, #0\n"
        "    strb r0, [r1]\n"
        ".L0815B1CA:\n"
        "    movs r4, #0\n"
        ".L0815B1CC:\n"
        "    bl sub_08159144\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #0xff\n"
        "    beq .L0815B20E\n"
        "    adds r6, r2, #0\n"
        "    adds r0, r6, #0\n"
        "    bl sub_0815BA28\n"
        "    cmp r0, #0\n"
        "    beq .L0815B20E\n"
        "    adds r0, r6, #0\n"
        "    bl Demon_GetLevel\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r2, r0, #0x18\n"
        "    ldr r1, .L0815B244\n"
        "    adds r0, r1, #0\n"
        "    adds r0, #0x9c\n"
        "    ldrb r0, [r0]\n"
        "    cmp r2, r0\n"
        "    bhs .L0815B20E\n"
        "    adds r0, r1, #0\n"
        "    adds r0, #0x9d\n"
        "    ldrb r0, [r0]\n"
        "    cmp r2, r0\n"
        "    blo .L0815B20E\n"
        "    adds r0, r6, #0\n"
        "    bl Stock_FindByDemonId\n"
        "    cmp r0, #0\n"
        "    beq .L0815B218\n"
        ".L0815B20E:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #0x1f\n"
        "    bls .L0815B1CC\n"
        ".L0815B218:\n"
        "    cmp r4, #0x20\n"
        "    bne .L0815B228\n"
        "    movs r6, #0xfb\n"
        "    movs r0, #0xfb\n"
        "    bl Stock_FindByDemonId\n"
        "    cmp r0, #0\n"
        "    bne .L0815B1CA\n"
        ".L0815B228:\n"
        "    ldr r4, .L0815B244\n"
        "    adds r5, r4, #0\n"
        "    adds r5, #0xa0\n"
        "    strh r6, [r5]\n"
        "    ldrh r0, [r5]\n"
        "    bl Demon_GetRace\n"
        "    adds r4, #0xa2\n"
        "    strb r0, [r4]\n"
        "    ldrh r0, [r5]\n"
        ".L0815B23C:\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L0815B244: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
    );
}
#endif

// sub_0815B248 @ 0x0815B248
void sub_0815B248(void)
{
}

/* Stock entry of the demon in unkA5 (the material kept by a 0xFB fusion), or NULL. */
// Fusion_FindKeptMaterial @ 0x0815B24C
struct Combatant *Fusion_FindKeptMaterial(void)
{
    return Stock_FindByDemonId(sCalc.unkA5);
}

/* Verdict on the fusion result (after Fusion_CalcTwo/Three): 0 none, 4 already in the stock,
   3 above the hero's level (+9 when unkA4 bit 0x40 is set, a material above race 0x1A),
   1 the alignment class (sub_0815B958) fits the hero's (equal, or either is 1), 2 it does
   not. Also builds the result's skill list (Fusion_BuildResultSkills). */
/* NONMATCHING: register allocation of the id addresses (r6/r7) differs. */
// Fusion_CheckResult @ 0x0815B260
#ifdef NONMATCHING
u32 Fusion_CheckResult(void)
{
    u16 t;
    u32 lv;
    u32 a;
    u32 h;

    sCalc.orig[0] = sCalc.ids[0];
    sCalc.orig[1] = sCalc.ids[1];
    sCalc.orig[2] = sCalc.ids[2];
    if (sCalc.orig[0] > sCalc.orig[1])
    {
        t = sCalc.ids[0];
        sCalc.ids[0] = sCalc.orig[1];
        sCalc.ids[1] = t;
    }
    if (sCalc.ids[0] > sCalc.ids[2])
    {
        t = sCalc.ids[0];
        sCalc.ids[0] = sCalc.ids[2];
        sCalc.ids[2] = t;
    }
    if (sCalc.ids[1] > sCalc.ids[2])
    {
        t = sCalc.ids[1];
        sCalc.ids[1] = sCalc.ids[2];
        sCalc.ids[2] = t;
    }
    if (sCalc.result != 0xFFFF)
    {
        Fusion_BuildResultSkills();
        sub_0815B248();
        if (Stock_FindByDemonId(sCalc.result))
            return 4;
        lv = Demon_GetRecord(sCalc.result)->level;
        h = gGameState.members[0].level;
        if (sCalc.unkA4 & 0x40)
            h += 9;
        if (h < lv)
        {
            sCalc.ids[0] = sCalc.orig[0];
            sCalc.ids[1] = sCalc.orig[1];
            sCalc.ids[2] = sCalc.orig[2];
            return 3;
        }
        a = sub_0815B958(sCalc.result) & 0xFF;
        h = sub_0815B970(gGameState.members[0].unk58 >> 8) & 0xFF;
        if (a == 1 || h == 1 || h == a)
        {
            sCalc.ids[0] = sCalc.orig[0];
            sCalc.ids[1] = sCalc.orig[1];
            sCalc.ids[2] = sCalc.orig[2];
            return 1;
        }
        sCalc.ids[0] = sCalc.orig[0];
        sCalc.ids[1] = sCalc.orig[1];
        sCalc.ids[2] = sCalc.orig[2];
        return 2;
    }
    sCalc.ids[0] = sCalc.orig[0];
    sCalc.ids[1] = sCalc.orig[1];
    sCalc.ids[2] = sCalc.orig[2];
    return 0;
}
#else
NAKED
u32 Fusion_CheckResult(void)
{
    asm_unified(
        ".L0815B260:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    ldr r5, .L0815B2E0\n"
        "    adds r6, r5, #0\n"
        "    adds r6, #0x90\n"
        "    ldrh r1, [r6]\n"
        "    ldr r0, .L0815B2E4\n"
        "    strh r1, [r0]\n"
        "    movs r2, #0x92\n"
        "    adds r2, r2, r5\n"
        "    mov r8, r2\n"
        "    ldrh r2, [r2]\n"
        "    ldr r3, .L0815B2E8\n"
        "    strh r2, [r3]\n"
        "    movs r0, #0x94\n"
        "    adds r0, r0, r5\n"
        "    mov sb, r0\n"
        "    ldrh r0, [r0]\n"
        "    ldr r3, .L0815B2EC\n"
        "    strh r0, [r3]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsls r0, r2, #0x10\n"
        "    cmp r1, r0\n"
        "    bls .L0815B29E\n"
        "    ldrh r0, [r6]\n"
        "    strh r2, [r6]\n"
        "    mov r1, r8\n"
        "    strh r0, [r1]\n"
        ".L0815B29E:\n"
        "    mov r2, sb\n"
        "    ldrh r1, [r2]\n"
        "    ldrh r0, [r6]\n"
        "    cmp r0, r1\n"
        "    bls .L0815B2AC\n"
        "    strh r1, [r6]\n"
        "    strh r0, [r2]\n"
        ".L0815B2AC:\n"
        "    mov r3, sb\n"
        "    ldrh r1, [r3]\n"
        "    mov r2, r8\n"
        "    ldrh r0, [r2]\n"
        "    cmp r0, r1\n"
        "    bls .L0815B2BC\n"
        "    strh r1, [r2]\n"
        "    strh r0, [r3]\n"
        ".L0815B2BC:\n"
        "    adds r7, r5, #0\n"
        "    adds r7, #0xa0\n"
        "    ldrh r1, [r7]\n"
        "    ldr r0, .L0815B2F0\n"
        "    cmp r1, r0\n"
        "    bne .L0815B2CA\n"
        "    b .L0815B3C0\n"
        ".L0815B2CA:\n"
        "    bl Fusion_BuildResultSkills\n"
        "    bl sub_0815B248\n"
        "    ldrh r0, [r7]\n"
        "    bl Stock_FindByDemonId\n"
        "    cmp r0, #0\n"
        "    beq .L0815B2F4\n"
        "    movs r0, #4\n"
        "    b .L0815B3D8\n"
        ".L0815B2E0: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L0815B2E4: .4byte 0x0203B8F2 @ EWRAM+0x3B8F2\n"
        ".L0815B2E8: .4byte 0x0203B8F4 @ EWRAM+0x3B8F4\n"
        ".L0815B2EC: .4byte 0x0203B8F6 @ EWRAM+0x3B8F6\n"
        ".L0815B2F0: .4byte 0x0000FFFF\n"
        ".L0815B2F4:\n"
        "    ldrh r4, [r7]\n"
        "    adds r0, r4, #0\n"
        "    bl Demon_GetRecord\n"
        "    movs r3, #0xff\n"
        "    mov sl, r3\n"
        "    ldrb r2, [r0, #1]\n"
        "    ldr r0, .L0815B334\n"
        "    ldrb r4, [r0, #0xd]\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0xa4\n"
        "    ldrb r1, [r0]\n"
        "    movs r0, #0x40\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L0815B316\n"
        "    adds r4, #9\n"
        ".L0815B316:\n"
        "    cmp r4, r2\n"
        "    bhs .L0815B344\n"
        "    ldr r1, .L0815B338\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r6]\n"
        "    ldr r2, .L0815B33C\n"
        "    ldrh r0, [r2]\n"
        "    mov r3, r8\n"
        "    strh r0, [r3]\n"
        "    ldr r1, .L0815B340\n"
        "    ldrh r0, [r1]\n"
        "    mov r2, sb\n"
        "    strh r0, [r2]\n"
        "    movs r0, #3\n"
        "    b .L0815B3D8\n"
        ".L0815B334: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L0815B338: .4byte 0x0203B8F2 @ EWRAM+0x3B8F2\n"
        ".L0815B33C: .4byte 0x0203B8F4 @ EWRAM+0x3B8F4\n"
        ".L0815B340: .4byte 0x0203B8F6 @ EWRAM+0x3B8F6\n"
        ".L0815B344:\n"
        "    ldrh r0, [r7]\n"
        "    bl sub_0815B958\n"
        "    mov r4, sl\n"
        "    ands r4, r0\n"
        "    ldr r0, .L0815B388\n"
        "    adds r0, #0x58\n"
        "    ldrh r0, [r0]\n"
        "    lsrs r2, r0, #8\n"
        "    adds r0, r2, #0\n"
        "    bl sub_0815B970\n"
        "    mov r2, sl\n"
        "    ands r2, r0\n"
        "    cmp r4, #1\n"
        "    beq .L0815B398\n"
        "    cmp r2, #1\n"
        "    beq .L0815B398\n"
        "    cmp r2, r4\n"
        "    beq .L0815B398\n"
        "    ldr r3, .L0815B38C\n"
        "    ldrh r0, [r3]\n"
        "    strh r0, [r6]\n"
        "    ldr r1, .L0815B390\n"
        "    ldrh r0, [r1]\n"
        "    mov r2, r8\n"
        "    strh r0, [r2]\n"
        "    ldr r3, .L0815B394\n"
        "    ldrh r0, [r3]\n"
        "    mov r1, sb\n"
        "    strh r0, [r1]\n"
        "    movs r0, #2\n"
        "    b .L0815B3D8\n"
        "    .byte 0x00, 0x00\n"
        ".L0815B388: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L0815B38C: .4byte 0x0203B8F2 @ EWRAM+0x3B8F2\n"
        ".L0815B390: .4byte 0x0203B8F4 @ EWRAM+0x3B8F4\n"
        ".L0815B394: .4byte 0x0203B8F6 @ EWRAM+0x3B8F6\n"
        ".L0815B398:\n"
        "    ldr r2, .L0815B3BC\n"
        "    adds r0, r2, #0\n"
        "    adds r0, #0x8a\n"
        "    ldrh r1, [r0]\n"
        "    adds r0, #6\n"
        "    strh r1, [r0]\n"
        "    subs r0, #4\n"
        "    ldrh r0, [r0]\n"
        "    adds r1, r2, #0\n"
        "    adds r1, #0x92\n"
        "    strh r0, [r1]\n"
        "    adds r0, r2, #0\n"
        "    adds r0, #0x8e\n"
        "    ldrh r1, [r0]\n"
        "    adds r0, #6\n"
        "    strh r1, [r0]\n"
        "    movs r0, #1\n"
        "    b .L0815B3D8\n"
        ".L0815B3BC: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L0815B3C0:\n"
        "    ldr r2, .L0815B3E8\n"
        "    ldrh r0, [r2]\n"
        "    strh r0, [r6]\n"
        "    ldr r3, .L0815B3EC\n"
        "    ldrh r0, [r3]\n"
        "    mov r1, r8\n"
        "    strh r0, [r1]\n"
        "    ldr r2, .L0815B3F0\n"
        "    ldrh r0, [r2]\n"
        "    mov r3, sb\n"
        "    strh r0, [r3]\n"
        "    movs r0, #0\n"
        ".L0815B3D8:\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L0815B3E8: .4byte 0x0203B8F2 @ EWRAM+0x3B8F2\n"
        ".L0815B3EC: .4byte 0x0203B8F4 @ EWRAM+0x3B8F4\n"
        ".L0815B3F0: .4byte 0x0203B8F6 @ EWRAM+0x3B8F6\n"
    );
}
#endif

/* After a fusion: the per-demon counts (ItemStock, ids 0x54-0xB1) of the materials drop by 2,
   the result's rises by 4; unless flag 0xE0 is set, the hero's alignment value (+0x58, copied
   to party members 1 and 2) moves 26 down for a result of class 0, 26 up for class 2. */
// Fusion_ApplyResult @ 0x0815B3F4
void Fusion_ApplyResult(void)
{
    u32 a;

    if (sCalc.ids[0] != 0xFFFF)
        ItemStock_Remove(sCalc.ids[0], 2);
    if (sCalc.ids[1] != 0xFFFF)
        ItemStock_Remove(sCalc.ids[1], 2);
    if (sCalc.ids[2] != 0xFFFF)
        ItemStock_Remove(sCalc.ids[2], 2);
    ItemStock_Add(sCalc.result, 4);
    if (Flag_Test(0xE0))
        return;
    a = sub_0815B958(sCalc.result) & 3;
    if (a == 0)
    {
        if (gGameState.members[0].unk58 > 0x19)
            gGameState.members[0].unk58 -= 0x1A;
        else
            gGameState.members[0].unk58 = 0;
    }
    else if (a == 2)
    {
        if (gGameState.members[0].unk58 <= 0xFFE6)
            gGameState.members[0].unk58 += 0x1A;
        else
            gGameState.members[0].unk58 = 0xFFFF;
    }
    gGameState.members[1].unk58 = gGameState.members[0].unk58;
    gGameState.members[2].unk58 = gGameState.members[0].unk58;
}

/* 1 when the materials give a random result (the fusion list then sets unkA6 = 0x30; checked
   before Fusion_CalcTwo/Three). Two materials: exactly one of alignment 0xB (dark), neither
   demon 0xFB; three materials:
   exactly one dark, or no race above 0x1A and the alignments of the highest-level material
   (top) and the other two (higher level first) are one of top 3 + {3, 2}, top 7 + {7, 5} or
   {1, 5}, top 6 + {1, 7}, top 5 + {5, 3} (either order). Leaves ids[] as they were. */
/* NONMATCHING: block layout of the alignment checks and restores differs. */
// Fusion_IsRandomResult @ 0x0815B4B4
#ifdef NONMATCHING
u32 Fusion_IsRandomResult(void)
{
    u16 t;
    u8 l0;
    u8 l1;
    u8 l2;
    u32 top;
    u32 p;
    u32 q;

    sCalc.orig[0] = sCalc.ids[0];
    sCalc.orig[1] = sCalc.ids[1];
    sCalc.orig[2] = sCalc.ids[2];
    if (sCalc.orig[0] > sCalc.orig[1])
    {
        t = sCalc.ids[0];
        sCalc.ids[0] = sCalc.orig[1];
        sCalc.ids[1] = t;
    }
    if (sCalc.ids[0] > sCalc.ids[2])
    {
        t = sCalc.ids[0];
        sCalc.ids[0] = sCalc.ids[2];
        sCalc.ids[2] = t;
    }
    if (sCalc.ids[1] > sCalc.ids[2])
    {
        t = sCalc.ids[1];
        sCalc.ids[1] = sCalc.ids[2];
        sCalc.ids[2] = t;
    }
    Demon_GetRaceAndAlign(sCalc.ids[0], &sCalc.align[0], &sCalc.race[0]);
    Demon_GetRaceAndAlign(sCalc.ids[1], &sCalc.align[1], &sCalc.race[1]);
    if (sCalc.ids[2] != 0xFFFF)
    {
        Demon_GetRaceAndAlign(sCalc.ids[2], &sCalc.align[2], &sCalc.race[2]);
        if ((sCalc.align[0] == 0xB && sCalc.align[1] != 0xB && sCalc.align[2] != 0xB)
         || (sCalc.align[0] != 0xB && sCalc.align[1] == 0xB && sCalc.align[2] != 0xB)
         || (sCalc.align[0] != 0xB && sCalc.align[1] != 0xB && sCalc.align[2] == 0xB))
        {
            sCalc.ids[0] = sCalc.orig[0];
            sCalc.ids[1] = sCalc.orig[1];
            sCalc.ids[2] = sCalc.orig[2];
            return 1;
        }
        if (sCalc.race[0] > 0x1A || sCalc.race[1] > 0x1A || sCalc.race[2] > 0x1A)
        {
            sCalc.ids[0] = sCalc.orig[0];
            sCalc.ids[1] = sCalc.orig[1];
            sCalc.ids[2] = sCalc.orig[2];
            return 0;
        }
        l0 = Demon_GetLevel(sCalc.ids[0]);
        l1 = Demon_GetLevel(sCalc.ids[1]);
        l2 = Demon_GetLevel(sCalc.ids[2]);
        if (l0 >= l1 && l0 >= l2)
        {
            top = sCalc.align[0];
            if (l1 >= l2)
            {
                p = sCalc.align[1];
                q = sCalc.align[2];
            }
            else
            {
                p = sCalc.align[2];
                q = sCalc.align[1];
            }
        }
        else if (l1 >= l0 && l1 >= l2)
        {
            top = sCalc.align[1];
            if (l0 >= l2)
            {
                p = sCalc.align[0];
                q = sCalc.align[2];
            }
            else
            {
                p = sCalc.align[2];
                q = sCalc.align[0];
            }
        }
        else if (l2 >= l0 && l2 >= l1)
        {
            top = sCalc.align[2];
            if (l0 >= l1)
            {
                p = sCalc.align[0];
                q = sCalc.align[1];
            }
            else
            {
                p = sCalc.align[1];
                q = sCalc.align[0];
            }
        }
        if ((top == 3 && ((p == 3 && q == 2) || (p == 2 && q == 3)))
         || (top == 7 && ((p == 7 && q == 5) || (p == 5 && q == 7) || (p == 1 && q == 5) || (p == 5 && q == 1)))
         || (top == 6 && ((p == 1 && q == 7) || (p == 7 && q == 1)))
         || (top == 5 && ((p == 5 && q == 3) || (p == 3 && q == 5))))
        {
            sCalc.ids[0] = sCalc.orig[0];
            sCalc.ids[1] = sCalc.orig[1];
            sCalc.ids[2] = sCalc.orig[2];
            return 1;
        }
        sCalc.ids[0] = sCalc.orig[0];
        sCalc.ids[1] = sCalc.orig[1];
        sCalc.ids[2] = sCalc.orig[2];
        return 0;
    }
    if (sCalc.ids[0] == 0xFB || sCalc.ids[1] == 0xFB)
    {
        sCalc.ids[0] = sCalc.orig[0];
        sCalc.ids[1] = sCalc.orig[1];
        sCalc.ids[2] = sCalc.orig[2];
        return 0;
    }
    if ((sCalc.align[0] == 0xB && sCalc.align[1] != 0xB) || (sCalc.align[0] != 0xB && sCalc.align[1] == 0xB))
    {
        sCalc.ids[0] = sCalc.orig[0];
        sCalc.ids[1] = sCalc.orig[1];
        sCalc.ids[2] = sCalc.orig[2];
        return 1;
    }
    sCalc.ids[0] = sCalc.orig[0];
    sCalc.ids[1] = sCalc.orig[1];
    sCalc.ids[2] = sCalc.orig[2];
    return 0;
}
#else
NAKED
u32 Fusion_IsRandomResult(void)
{
    asm_unified(
        ".L0815B4B4:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #4\n"
        "    ldr r5, .L0815B5B4\n"
        "    adds r4, r5, #0\n"
        "    adds r4, #0x90\n"
        "    ldrh r1, [r4]\n"
        "    ldr r0, .L0815B5B8\n"
        "    strh r1, [r0]\n"
        "    movs r2, #0x92\n"
        "    adds r2, r2, r5\n"
        "    mov sb, r2\n"
        "    ldrh r2, [r2]\n"
        "    ldr r3, .L0815B5BC\n"
        "    strh r2, [r3]\n"
        "    adds r6, r5, #0\n"
        "    adds r6, #0x94\n"
        "    ldrh r0, [r6]\n"
        "    ldr r3, .L0815B5C0\n"
        "    strh r0, [r3]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsls r0, r2, #0x10\n"
        "    cmp r1, r0\n"
        "    bls .L0815B4F2\n"
        "    ldrh r0, [r4]\n"
        "    strh r2, [r4]\n"
        "    mov r1, sb\n"
        "    strh r0, [r1]\n"
        ".L0815B4F2:\n"
        "    ldrh r1, [r6]\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, r1\n"
        "    bls .L0815B4FE\n"
        "    strh r1, [r4]\n"
        "    strh r0, [r6]\n"
        ".L0815B4FE:\n"
        "    ldrh r1, [r6]\n"
        "    mov r2, sb\n"
        "    ldrh r0, [r2]\n"
        "    cmp r0, r1\n"
        "    bls .L0815B50C\n"
        "    strh r1, [r2]\n"
        "    strh r0, [r6]\n"
        ".L0815B50C:\n"
        "    ldrh r0, [r4]\n"
        "    adds r2, r5, #0\n"
        "    adds r2, #0x96\n"
        "    ldr r1, .L0815B5C4\n"
        "    bl Demon_GetRaceAndAlign\n"
        "    mov r3, sb\n"
        "    ldrh r0, [r3]\n"
        "    movs r1, #0x9a\n"
        "    adds r1, r1, r5\n"
        "    mov sl, r1\n"
        "    adds r2, r5, #0\n"
        "    adds r2, #0x97\n"
        "    bl Demon_GetRaceAndAlign\n"
        "    ldrh r1, [r6]\n"
        "    ldr r0, .L0815B5C8\n"
        "    cmp r1, r0\n"
        "    bne .L0815B534\n"
        "    b .L0815B772\n"
        ".L0815B534:\n"
        "    adds r0, r1, #0\n"
        "    adds r4, r5, #0\n"
        "    adds r4, #0x9b\n"
        "    adds r2, r5, #0\n"
        "    adds r2, #0x98\n"
        "    adds r1, r4, #0\n"
        "    bl Demon_GetRaceAndAlign\n"
        "    ldr r2, .L0815B5C4\n"
        "    ldrb r0, [r2]\n"
        "    cmp r0, #0xb\n"
        "    bne .L0815B55C\n"
        "    mov r3, sl\n"
        "    ldrb r0, [r3]\n"
        "    cmp r0, #0xb\n"
        "    beq .L0815B566\n"
        "    ldrb r0, [r4]\n"
        "    adds r4, r5, #0\n"
        "    cmp r0, #0xb\n"
        "    bne .L0815B59C\n"
        ".L0815B55C:\n"
        "    mov r1, sl\n"
        "    ldrb r0, [r1]\n"
        "    adds r4, r5, #0\n"
        "    cmp r0, #0xb\n"
        "    bne .L0815B57E\n"
        ".L0815B566:\n"
        "    ldr r1, .L0815B5B4\n"
        "    adds r0, r1, #0\n"
        "    adds r0, #0x9b\n"
        "    ldrb r0, [r0]\n"
        "    adds r4, r1, #0\n"
        "    cmp r0, #0xb\n"
        "    beq .L0815B588\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x99\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0xb\n"
        "    bne .L0815B59C\n"
        ".L0815B57E:\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x9b\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0xb\n"
        "    bne .L0815B5CC\n"
        ".L0815B588:\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x99\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0xb\n"
        "    beq .L0815B5CC\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x9a\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0xb\n"
        "    beq .L0815B5CC\n"
        ".L0815B59C:\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x8a\n"
        "    ldrh r1, [r0]\n"
        "    adds r0, #6\n"
        "    strh r1, [r0]\n"
        "    subs r0, #4\n"
        "    ldrh r0, [r0]\n"
        "    adds r1, r4, #0\n"
        "    adds r1, #0x92\n"
        "    strh r0, [r1]\n"
        "    adds r0, r4, #0\n"
        "    b .L0815B7DC\n"
        ".L0815B5B4: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L0815B5B8: .4byte 0x0203B8F2 @ EWRAM+0x3B8F2\n"
        ".L0815B5BC: .4byte 0x0203B8F4 @ EWRAM+0x3B8F4\n"
        ".L0815B5C0: .4byte 0x0203B8F6 @ EWRAM+0x3B8F6\n"
        ".L0815B5C4: .4byte 0x0203B901 @ EWRAM+0x3B901\n"
        ".L0815B5C8: .4byte 0x0000FFFF\n"
        ".L0815B5CC:\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x96\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0x1a\n"
        "    bhi .L0815B5EA\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x97\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0x1a\n"
        "    bhi .L0815B5EA\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x98\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0x1a\n"
        "    bls .L0815B602\n"
        ".L0815B5EA:\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x8a\n"
        "    ldrh r1, [r0]\n"
        "    adds r0, #6\n"
        "    strh r1, [r0]\n"
        "    subs r0, #4\n"
        "    ldrh r0, [r0]\n"
        "    adds r1, r4, #0\n"
        "    adds r1, #0x92\n"
        "    strh r0, [r1]\n"
        "    adds r0, r4, #0\n"
        "    b .L0815B804\n"
        ".L0815B602:\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x90\n"
        "    ldrh r0, [r0]\n"
        "    bl Demon_GetLevel\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r6, r0, #0x18\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x92\n"
        "    ldrh r0, [r0]\n"
        "    bl Demon_GetLevel\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r5, r0, #0x18\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x94\n"
        "    ldrh r0, [r0]\n"
        "    bl Demon_GetLevel\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r6, r5\n"
        "    blo .L0815B65C\n"
        "    cmp r6, r0\n"
        "    blo .L0815B65C\n"
        "    adds r1, r4, #0\n"
        "    adds r1, #0x99\n"
        "    ldrb r1, [r1]\n"
        "    str r1, [sp]\n"
        "    cmp r5, r0\n"
        "    blo .L0815B64E\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x9a\n"
        "    ldrb r0, [r0]\n"
        "    mov r8, r0\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x9b\n"
        "    b .L0815B6C4\n"
        ".L0815B64E:\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x9b\n"
        "    ldrb r0, [r0]\n"
        "    mov r8, r0\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x9a\n"
        "    b .L0815B6C4\n"
        ".L0815B65C:\n"
        "    cmp r5, r6\n"
        "    blo .L0815B68E\n"
        "    cmp r5, r0\n"
        "    blo .L0815B68E\n"
        "    ldr r1, .L0815B684\n"
        "    adds r2, r1, #0\n"
        "    adds r2, #0x9a\n"
        "    ldrb r2, [r2]\n"
        "    str r2, [sp]\n"
        "    adds r4, r1, #0\n"
        "    cmp r6, r0\n"
        "    blo .L0815B688\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x99\n"
        "    ldrb r0, [r0]\n"
        "    mov r8, r0\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x9b\n"
        "    b .L0815B6C4\n"
        "    .byte 0x00, 0x00\n"
        ".L0815B684: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L0815B688:\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x9b\n"
        "    b .L0815B6BC\n"
        ".L0815B68E:\n"
        "    ldr r4, .L0815B6B4\n"
        "    cmp r0, r6\n"
        "    blo .L0815B6C6\n"
        "    cmp r0, r5\n"
        "    blo .L0815B6C6\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x9b\n"
        "    ldrb r0, [r0]\n"
        "    str r0, [sp]\n"
        "    cmp r6, r5\n"
        "    blo .L0815B6B8\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x99\n"
        "    ldrb r0, [r0]\n"
        "    mov r8, r0\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x9a\n"
        "    b .L0815B6C4\n"
        "    .byte 0x00, 0x00\n"
        ".L0815B6B4: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L0815B6B8:\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x9a\n"
        ".L0815B6BC:\n"
        "    ldrb r0, [r0]\n"
        "    mov r8, r0\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x99\n"
        ".L0815B6C4:\n"
        "    ldrb r7, [r0]\n"
        ".L0815B6C6:\n"
        "    ldr r2, [sp]\n"
        "    cmp r2, #3\n"
        "    bne .L0815B6E0\n"
        "    mov r3, r8\n"
        "    cmp r3, #3\n"
        "    bne .L0815B6D6\n"
        "    cmp r7, #2\n"
        "    beq .L0815B742\n"
        ".L0815B6D6:\n"
        "    mov r0, r8\n"
        "    cmp r0, #2\n"
        "    bne .L0815B6E0\n"
        "    cmp r7, #3\n"
        "    beq .L0815B742\n"
        ".L0815B6E0:\n"
        "    ldr r1, [sp]\n"
        "    cmp r1, #7\n"
        "    bne .L0815B70E\n"
        "    mov r2, r8\n"
        "    cmp r2, #7\n"
        "    bne .L0815B6F0\n"
        "    cmp r7, #5\n"
        "    beq .L0815B742\n"
        ".L0815B6F0:\n"
        "    mov r3, r8\n"
        "    cmp r3, #5\n"
        "    bne .L0815B6FA\n"
        "    cmp r7, #7\n"
        "    beq .L0815B742\n"
        ".L0815B6FA:\n"
        "    mov r0, r8\n"
        "    cmp r0, #1\n"
        "    bne .L0815B704\n"
        "    cmp r7, #5\n"
        "    beq .L0815B742\n"
        ".L0815B704:\n"
        "    mov r1, r8\n"
        "    cmp r1, #5\n"
        "    bne .L0815B70E\n"
        "    cmp r7, #1\n"
        "    beq .L0815B742\n"
        ".L0815B70E:\n"
        "    ldr r2, [sp]\n"
        "    cmp r2, #6\n"
        "    bne .L0815B728\n"
        "    mov r3, r8\n"
        "    cmp r3, #1\n"
        "    bne .L0815B71E\n"
        "    cmp r7, #7\n"
        "    beq .L0815B742\n"
        ".L0815B71E:\n"
        "    mov r0, r8\n"
        "    cmp r0, #7\n"
        "    bne .L0815B728\n"
        "    cmp r7, #1\n"
        "    beq .L0815B742\n"
        ".L0815B728:\n"
        "    ldr r1, [sp]\n"
        "    cmp r1, #5\n"
        "    bne .L0815B75A\n"
        "    mov r2, r8\n"
        "    cmp r2, #5\n"
        "    bne .L0815B738\n"
        "    cmp r7, #3\n"
        "    beq .L0815B742\n"
        ".L0815B738:\n"
        "    mov r3, r8\n"
        "    cmp r3, #3\n"
        "    bne .L0815B75A\n"
        "    cmp r7, #5\n"
        "    bne .L0815B75A\n"
        ".L0815B742:\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x8a\n"
        "    ldrh r1, [r0]\n"
        "    adds r0, #6\n"
        "    strh r1, [r0]\n"
        "    subs r0, #4\n"
        "    ldrh r0, [r0]\n"
        "    adds r1, r4, #0\n"
        "    adds r1, #0x92\n"
        "    strh r0, [r1]\n"
        "    adds r0, r4, #0\n"
        "    b .L0815B7DC\n"
        ".L0815B75A:\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x8a\n"
        "    ldrh r1, [r0]\n"
        "    adds r0, #6\n"
        "    strh r1, [r0]\n"
        "    subs r0, #4\n"
        "    ldrh r0, [r0]\n"
        "    adds r1, r4, #0\n"
        "    adds r1, #0x92\n"
        "    strh r0, [r1]\n"
        "    adds r0, r4, #0\n"
        "    b .L0815B804\n"
        ".L0815B772:\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #0xfb\n"
        "    beq .L0815B780\n"
        "    mov r1, sb\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #0xfb\n"
        "    bne .L0815B7A4\n"
        ".L0815B780:\n"
        "    ldr r2, .L0815B798\n"
        "    ldrh r0, [r2]\n"
        "    strh r0, [r4]\n"
        "    ldr r3, .L0815B79C\n"
        "    ldrh r0, [r3]\n"
        "    mov r1, sb\n"
        "    strh r0, [r1]\n"
        "    ldr r2, .L0815B7A0\n"
        "    ldrh r0, [r2]\n"
        "    strh r0, [r6]\n"
        "    b .L0815B80C\n"
        "    .byte 0x00, 0x00\n"
        ".L0815B798: .4byte 0x0203B8F2 @ EWRAM+0x3B8F2\n"
        ".L0815B79C: .4byte 0x0203B8F4 @ EWRAM+0x3B8F4\n"
        ".L0815B7A0: .4byte 0x0203B8F6 @ EWRAM+0x3B8F6\n"
        ".L0815B7A4:\n"
        "    ldr r3, .L0815B7B8\n"
        "    ldrb r0, [r3]\n"
        "    cmp r0, #0xb\n"
        "    bne .L0815B7BC\n"
        "    mov r1, sl\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0xb\n"
        "    bne .L0815B7C4\n"
        "    b .L0815B7EC\n"
        "    .byte 0x00, 0x00\n"
        ".L0815B7B8: .4byte 0x0203B901 @ EWRAM+0x3B901\n"
        ".L0815B7BC:\n"
        "    mov r2, sl\n"
        "    ldrb r0, [r2]\n"
        "    cmp r0, #0xb\n"
        "    bne .L0815B7EC\n"
        ".L0815B7C4:\n"
        "    ldr r2, .L0815B7E8\n"
        "    adds r0, r2, #0\n"
        "    adds r0, #0x8a\n"
        "    ldrh r1, [r0]\n"
        "    adds r0, #6\n"
        "    strh r1, [r0]\n"
        "    subs r0, #4\n"
        "    ldrh r0, [r0]\n"
        "    adds r1, r2, #0\n"
        "    adds r1, #0x92\n"
        "    strh r0, [r1]\n"
        "    adds r0, r2, #0\n"
        ".L0815B7DC:\n"
        "    adds r0, #0x8e\n"
        "    ldrh r1, [r0]\n"
        "    adds r0, #6\n"
        "    strh r1, [r0]\n"
        "    movs r0, #1\n"
        "    b .L0815B80E\n"
        ".L0815B7E8: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L0815B7EC:\n"
        "    ldr r2, .L0815B820\n"
        "    adds r0, r2, #0\n"
        "    adds r0, #0x8a\n"
        "    ldrh r1, [r0]\n"
        "    adds r0, #6\n"
        "    strh r1, [r0]\n"
        "    subs r0, #4\n"
        "    ldrh r0, [r0]\n"
        "    adds r1, r2, #0\n"
        "    adds r1, #0x92\n"
        "    strh r0, [r1]\n"
        "    adds r0, r2, #0\n"
        ".L0815B804:\n"
        "    adds r0, #0x8e\n"
        "    ldrh r1, [r0]\n"
        "    adds r0, #6\n"
        "    strh r1, [r0]\n"
        ".L0815B80C:\n"
        "    movs r0, #0\n"
        ".L0815B80E:\n"
        "    add sp, #4\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L0815B820: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
    );
}
#endif
