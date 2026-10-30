/* Skill inheritance of the fusion result, 0x0815A6F0-0x0815AE84. */
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

/* Builds the result's skill list (skills[], 0xFF ends): its own skills of its class
   (record byte 0x1E & 0xF), then skills of that class inherited from the materials, sorted,
   up to 6; without any own skills of its class, Fusion_BuildSkillsNoClass. */
/* NONMATCHING: close; registers of the nA / inherit[] pointers and of the last sort loop differ. */
// Fusion_BuildResultSkills @ 0x0815A6F0
#ifdef NONMATCHING
void Fusion_BuildResultSkills(void)
{
    u16 i = sCalc.result;
    u16 n;
    u16 k;
    u32 s;

    sCalc.skillKind = ((u8 *)Demon_GetRecord(i))[0x1E] & 0xF;
    sCalc.innate[0] = 0xFF;
    sCalc.innate[1] = 0xFF;
    sCalc.others[0] = 0xFF;
    sCalc.others[1] = 0xFF;
    sCalc.nA = 0;
    sCalc.nB = 0;
    for (n = 0; n < 6; n++)
    {
        sCalc.skill = Demon_GetRecord(i)->skills[n];
        if (sCalc.skill == 0xFF)
            continue;
        if (sCalc.skill >= 0x40 || (k = Skill_GetClass(sCalc.skill)) == 0xF || k != sCalc.skillKind)
        {
            sCalc.others[sCalc.nB] = sCalc.skill;
            sCalc.others[sCalc.nB + 1] = 0xFF;
            sCalc.nB++;
        }
        else
        {
            sCalc.innate[sCalc.nA] = sCalc.skill;
            sCalc.innate[sCalc.nA + 1] = 0xFF;
            sCalc.nA++;
        }
    }
    sCalc.nA = 0;
    sCalc.nB = 0;
    sCalc.skills[0] = 0xFF;
    sCalc.skills[1] = 0xFF;
    sCalc.inherit[0] = 0xFF;
    sCalc.inherit[1] = 0xFF;
    sCalc.x290.list[0] = 0xFF;
    sCalc.x290.list[1] = 0xFF;
    Fusion_CollectMaterialSkills(sCalc.ids[2]);
    Fusion_CollectMaterialSkills(sCalc.ids[1]);
    Fusion_CollectMaterialSkills(sCalc.ids[0]);
    if (sCalc.nA == 0)
    {
        Fusion_BuildSkillsNoClass();
        return;
    }
    for (i = 0; sCalc.innate[i] != 0xFF; i++)
    {
        sCalc.inherit[sCalc.nA] = sCalc.innate[i];
        sCalc.inherit[sCalc.nA + 1] |= 0xFF;
        sCalc.nA++;
    }
    SkillList_SortDescending(sCalc.inherit);
    for (i = 0, n = 0; sCalc.others[i] != 0xFF; i++, n++)
    {
        sCalc.skills[n] = sCalc.others[i];
        sCalc.skills[n + 1] |= 0xFF;
    }
    for (n = 0; sCalc.skills[n] != 0xFF; n++)
        ;
    i = 0;
    while (n != 6)
    {
        s = sCalc.inherit[i];
        if ((s & 0xFF) == 0xFF)
        {
            Fusion_AppendMaterialSkills(i, n);
            return;
        }
        gUnk_0203B918[n] = s;
        gUnk_0203B918[n + 1] |= 0xFF;
        i++;
        {
            u8 *p = gUnk_0203B918;
            SkillList_SortAscending(p);
            for (n = 0; p[n] != 0xFF; n++)
                ;
        }
    }
    sCalc.skills[n] = 0xFF;
    sub_0815AAC4();
}
#else
NAKED
void Fusion_BuildResultSkills(void)
{
    asm_unified(
        ".L0815A6F0:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #4\n"
        "    ldr r5, .L0815A7BC\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0xa0\n"
        "    ldrh r7, [r0]\n"
        "    adds r0, r7, #0\n"
        "    bl Demon_GetRecord\n"
        "    ldrb r1, [r0, #0x1e]\n"
        "    movs r0, #0xf\n"
        "    ands r0, r1\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x80\n"
        "    movs r3, #0\n"
        "    strb r0, [r1]\n"
        "    movs r0, #0x94\n"
        "    lsls r0, r0, #2\n"
        "    adds r4, r5, r0\n"
        "    movs r0, #0xff\n"
        "    strb r0, [r4]\n"
        "    ldr r2, .L0815A7C0\n"
        "    adds r1, r5, r2\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    strb r0, [r1]\n"
        "    movs r0, #0x9c\n"
        "    lsls r0, r0, #2\n"
        "    adds r2, r5, r0\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    strb r0, [r2]\n"
        "    ldr r0, .L0815A7C4\n"
        "    adds r1, r5, r0\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    strb r0, [r1]\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x81\n"
        "    strb r3, [r1]\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x82\n"
        "    strb r3, [r0]\n"
        "    movs r6, #0\n"
        "    mov sb, r5\n"
        "    movs r3, #0x83\n"
        "    add r3, sb\n"
        "    mov r8, r3\n"
        "    adds r3, r0, #0\n"
        "    mov sl, r4\n"
        "    adds r4, r2, #0\n"
        "    adds r5, r1, #0\n"
        ".L0815A760:\n"
        "    adds r0, r7, #0\n"
        "    str r3, [sp]\n"
        "    bl Demon_GetRecord\n"
        "    adds r0, #0x11\n"
        "    adds r0, r0, r6\n"
        "    ldrb r0, [r0]\n"
        "    mov r1, r8\n"
        "    strb r0, [r1]\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    ldr r3, [sp]\n"
        "    cmp r0, #0xff\n"
        "    beq .L0815A7E6\n"
        "    cmp r0, #0x3f\n"
        "    bhi .L0815A79A\n"
        "    ldrb r0, [r1]\n"
        "    bl Skill_GetClass\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    ldr r3, [sp]\n"
        "    cmp r1, #0xf\n"
        "    beq .L0815A79A\n"
        "    mov r0, sb\n"
        "    adds r0, #0x80\n"
        "    ldrb r0, [r0]\n"
        "    cmp r1, r0\n"
        "    beq .L0815A7C8\n"
        ".L0815A79A:\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r3, r0]\n"
        "    adds r0, r0, r4\n"
        "    mov r2, r8\n"
        "    ldrb r1, [r2]\n"
        "    strb r1, [r0]\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r3, r0]\n"
        "    adds r0, #1\n"
        "    adds r0, r0, r4\n"
        "    movs r1, #0xff\n"
        "    strb r1, [r0]\n"
        "    ldrb r0, [r3]\n"
        "    adds r0, #1\n"
        "    strb r0, [r3]\n"
        "    b .L0815A7E6\n"
        "    .byte 0x00, 0x00\n"
        ".L0815A7BC: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L0815A7C0: .4byte 0x00000251\n"
        ".L0815A7C4: .4byte 0x00000271\n"
        ".L0815A7C8:\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r5, r0]\n"
        "    add r0, sl\n"
        "    mov r2, r8\n"
        "    ldrb r1, [r2]\n"
        "    strb r1, [r0]\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r5, r0]\n"
        "    adds r0, #1\n"
        "    add r0, sl\n"
        "    movs r1, #0xff\n"
        "    strb r1, [r0]\n"
        "    ldrb r0, [r5]\n"
        "    adds r0, #1\n"
        "    strb r0, [r5]\n"
        ".L0815A7E6:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r6, #5\n"
        "    bls .L0815A760\n"
        "    ldr r4, .L0815A85C\n"
        "    adds r5, r4, #0\n"
        "    adds r5, #0x81\n"
        "    movs r0, #0\n"
        "    strb r0, [r5]\n"
        "    adds r1, r4, #0\n"
        "    adds r1, #0x82\n"
        "    strb r0, [r1]\n"
        "    adds r1, #0x2e\n"
        "    movs r0, #0xff\n"
        "    strb r0, [r1]\n"
        "    adds r1, #1\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    strb r0, [r1]\n"
        "    movs r3, #0xc0\n"
        "    lsls r3, r3, #1\n"
        "    adds r6, r4, r3\n"
        "    strb r0, [r6]\n"
        "    ldr r0, .L0815A860\n"
        "    adds r1, r4, r0\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    strb r0, [r1]\n"
        "    movs r2, #0xa4\n"
        "    lsls r2, r2, #2\n"
        "    adds r1, r4, r2\n"
        "    strb r0, [r1]\n"
        "    ldr r3, .L0815A864\n"
        "    adds r1, r4, r3\n"
        "    strb r0, [r1]\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x94\n"
        "    ldrh r0, [r0]\n"
        "    bl Fusion_CollectMaterialSkills\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x92\n"
        "    ldrh r0, [r0]\n"
        "    bl Fusion_CollectMaterialSkills\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x90\n"
        "    ldrh r0, [r0]\n"
        "    bl Fusion_CollectMaterialSkills\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r5, r0]\n"
        "    cmp r0, #0\n"
        "    bne .L0815A876\n"
        "    bl Fusion_BuildSkillsNoClass\n"
        "    b .L0815A984\n"
        "    .byte 0x00, 0x00\n"
        ".L0815A85C: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L0815A860: .4byte 0x00000181\n"
        ".L0815A864: .4byte 0x00000291\n"
        ".L0815A868:\n"
        "    lsls r0, r7, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    lsls r1, r6, #0x18\n"
        "    lsrs r1, r1, #0x18\n"
        "    bl Fusion_AppendMaterialSkills\n"
        "    b .L0815A984\n"
        ".L0815A876:\n"
        "    movs r7, #0\n"
        "    movs r0, #0x94\n"
        "    lsls r0, r0, #2\n"
        "    adds r1, r4, r0\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0xff\n"
        "    beq .L0815A8BA\n"
        "    adds r2, r5, #0\n"
        "    adds r4, r6, #0\n"
        "    adds r3, r1, #0\n"
        "    movs r5, #0xff\n"
        ".L0815A88C:\n"
        "    movs r1, #0\n"
        "    ldrsb r1, [r2, r1]\n"
        "    adds r1, r1, r4\n"
        "    adds r0, r7, r3\n"
        "    ldrb r0, [r0]\n"
        "    strb r0, [r1]\n"
        "    movs r1, #0\n"
        "    ldrsb r1, [r2, r1]\n"
        "    adds r1, #1\n"
        "    adds r1, r1, r4\n"
        "    ldrb r0, [r1]\n"
        "    orrs r0, r5\n"
        "    strb r0, [r1]\n"
        "    ldrb r0, [r2]\n"
        "    adds r0, #1\n"
        "    strb r0, [r2]\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r0, r7, r3\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0xff\n"
        "    bne .L0815A88C\n"
        ".L0815A8BA:\n"
        "    adds r4, r6, #0\n"
        "    adds r0, r4, #0\n"
        "    bl SkillList_SortDescending\n"
        "    movs r7, #0\n"
        "    movs r6, #0\n"
        "    adds r1, r4, #0\n"
        "    adds r1, #0xf0\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0xff\n"
        "    beq .L0815A8FA\n"
        "    subs r4, #0xd0\n"
        "    adds r3, r1, #0\n"
        "    movs r5, #0xff\n"
        ".L0815A8D6:\n"
        "    adds r1, r6, r4\n"
        "    adds r0, r7, r3\n"
        "    ldrb r0, [r0]\n"
        "    strb r0, [r1]\n"
        "    adds r2, r6, #1\n"
        "    adds r1, r2, r4\n"
        "    ldrb r0, [r1]\n"
        "    orrs r0, r5\n"
        "    strb r0, [r1]\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r6, r2, #0x10\n"
        "    adds r0, r7, r3\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0xff\n"
        "    bne .L0815A8D6\n"
        ".L0815A8FA:\n"
        "    movs r6, #0\n"
        "    ldr r0, .L0815A994\n"
        "    adds r2, r0, #0\n"
        "    adds r2, #0xb0\n"
        "    ldrb r1, [r2]\n"
        "    adds r3, r0, #0\n"
        "    cmp r1, #0xff\n"
        "    beq .L0815A91A\n"
        "    adds r1, r2, #0\n"
        ".L0815A90C:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    adds r0, r6, r1\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0xff\n"
        "    bne .L0815A90C\n"
        ".L0815A91A:\n"
        "    movs r7, #0\n"
        "    cmp r6, #6\n"
        "    beq .L0815A976\n"
        "    movs r1, #0xff\n"
        "    mov r8, r1\n"
        "    ldr r5, .L0815A998\n"
        ".L0815A926:\n"
        "    movs r2, #0xc0\n"
        "    lsls r2, r2, #1\n"
        "    adds r0, r3, r2\n"
        "    adds r0, r7, r0\n"
        "    ldrb r2, [r0]\n"
        "    adds r1, r2, #0\n"
        "    mov r3, r8\n"
        "    ands r1, r3\n"
        "    cmp r1, #0xff\n"
        "    beq .L0815A868\n"
        "    adds r0, r6, r5\n"
        "    strb r2, [r0]\n"
        "    adds r1, r6, #1\n"
        "    adds r1, r1, r5\n"
        "    ldrb r2, [r1]\n"
        "    mov r0, r8\n"
        "    orrs r0, r2\n"
        "    strb r0, [r1]\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r4, r5, #0\n"
        "    adds r0, r4, #0\n"
        "    bl SkillList_SortAscending\n"
        "    movs r6, #0\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #0xff\n"
        "    beq .L0815A970\n"
        "    adds r1, r4, #0\n"
        ".L0815A962:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    adds r0, r6, r1\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0xff\n"
        "    bne .L0815A962\n"
        ".L0815A970:\n"
        "    ldr r3, .L0815A994\n"
        "    cmp r6, #6\n"
        "    bne .L0815A926\n"
        ".L0815A976:\n"
        "    adds r0, r3, #0\n"
        "    adds r0, #0xb0\n"
        "    adds r0, r6, r0\n"
        "    movs r1, #0xff\n"
        "    strb r1, [r0]\n"
        "    bl sub_0815AAC4\n"
        ".L0815A984:\n"
        "    add sp, #4\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L0815A994: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L0815A998: .4byte 0x0203B918 @ EWRAM+0x3B918\n"
    );
}
#endif

/* The result has no skills of its own class: its other skills, then its class skills, then
   the materials' skills (Fusion_AppendMaterialSkills). */
// Fusion_BuildSkillsNoClass @ 0x0815A99C
void Fusion_BuildSkillsNoClass(void)
{
    u8 i;
    u8 n;
    u8 *others = sCalc.others;

    SkillList_SortDescending(others + 0x20);
    i = 0;
    n = 0;
    while (sCalc.others[i] != 0xFF)
    {
        sCalc.skills[n] = sCalc.others[i];
        sCalc.skills[n + 1] |= 0xFF;
        i++;
        n++;
    }
    i = 0;
    while (sCalc.innate[i] != 0xFF)
    {
        sCalc.skills[n] = sCalc.innate[i];
        sCalc.skills[n + 1] |= 0xFF;
        i++;
        n++;
    }
    Fusion_AppendMaterialSkills(i, n);
}

/* Appends the materials' skills (sorted, high first) to the result's list, up to 6. */
// Fusion_AppendMaterialSkills @ 0x0815AA30
void Fusion_AppendMaterialSkills(u8 unused0, u8 unused1)
{
    u8 j = 0;
    u8 n;
    u8 *others = sCalc.others;

    SkillList_SortDescending(others + 0x20);
    SkillList_SortAscending(sCalc.skills);
    n = 0;
    while (sCalc.skills[n] != 0xFF)
        n++;
    while (n <= 5 && sCalc.others[0x20 + j] != 0xFF)
    {
        sCalc.skills[n] = sCalc.others[0x20 + j];
        j++;
        n++;
    }
    sCalc.skills[n] = 0xFF;
    sub_0815AAC4();
}

// sub_0815AAC4 @ 0x0815AAC4
void sub_0815AAC4(void)
{
}

/* Sorts a 0xFF-terminated byte list ascending, dropping duplicates. */
/* NONMATCHING: same code, list pointer and index registers permuted. */
// SkillList_SortAscending @ 0x0815AAC8
#ifdef NONMATCHING
void SkillList_SortAscending(u8 *list)
{
    u8 i;
    u8 j;
    u8 k;
    u8 t;

    if (list[0] == 0xFF || list[1] == 0xFF)
        return;
    i = 0;
    j = 0;
    do
    {
    again:
        if (list[j + 1] != 0xFF)
        {
            do
            {
                if (list[i] == list[j + 1])
                {
                    k = j;
                    do
                    {
                        t = list[k + 2];
                        list[k + 1] = t;
                        k++;
                    } while (t != 0xFF);
                    goto again;
                }
                if (list[i] > list[j + 1])
                {
                    t = list[i];
                    list[i] = list[j + 1];
                    list[j + 1] = t;
                }
                j++;
            } while (list[j + 1] != 0xFF);
        }
        i++;
        j = i;
    } while (list[i + 1] != 0xFF);
}
#else
NAKED
void SkillList_SortAscending(u8 *list)
{
    asm_unified(
        ".L0815AAC8:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    adds r3, r0, #0\n"
        "    ldrb r0, [r3]\n"
        "    cmp r0, #0xff\n"
        "    beq .L0815AB32\n"
        "    ldrb r0, [r3, #1]\n"
        "    cmp r0, #0xff\n"
        "    beq .L0815AB32\n"
        "    movs r7, #0\n"
        "    movs r5, #0\n"
        ".L0815AADC:\n"
        "    adds r0, r5, r3\n"
        "    ldrb r0, [r0, #1]\n"
        "    adds r1, r7, #1\n"
        "    mov ip, r1\n"
        "    cmp r0, #0xff\n"
        "    beq .L0815AB22\n"
        ".L0815AAE8:\n"
        "    adds r2, r3, r7\n"
        "    adds r6, r5, r3\n"
        "    ldrb r4, [r6, #1]\n"
        "    ldrb r1, [r2]\n"
        "    adds r0, r4, #0\n"
        "    cmp r1, r0\n"
        "    bne .L0815AB0A\n"
        "    adds r2, r5, #0\n"
        ".L0815AAF8:\n"
        "    adds r0, r2, r3\n"
        "    ldrb r1, [r0, #2]\n"
        "    strb r1, [r0, #1]\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r2, r0, #0x18\n"
        "    cmp r1, #0xff\n"
        "    bne .L0815AAF8\n"
        "    b .L0815AADC\n"
        ".L0815AB0A:\n"
        "    cmp r1, r0\n"
        "    bls .L0815AB14\n"
        "    ldrb r1, [r2]\n"
        "    strb r4, [r2]\n"
        "    strb r1, [r6, #1]\n"
        ".L0815AB14:\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r5, r0, #0x18\n"
        "    adds r0, r5, r3\n"
        "    ldrb r0, [r0, #1]\n"
        "    cmp r0, #0xff\n"
        "    bne .L0815AAE8\n"
        ".L0815AB22:\n"
        "    mov r1, ip\n"
        "    lsls r0, r1, #0x18\n"
        "    lsrs r7, r0, #0x18\n"
        "    adds r5, r7, #0\n"
        "    adds r0, r7, r3\n"
        "    ldrb r0, [r0, #1]\n"
        "    cmp r0, #0xff\n"
        "    bne .L0815AADC\n"
        ".L0815AB32:\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

/* Sorts a 0xFF-terminated byte list descending, dropping duplicates. */
/* NONMATCHING: same code, list pointer and index registers permuted. */
// SkillList_SortDescending @ 0x0815AB38
#ifdef NONMATCHING
void SkillList_SortDescending(u8 *list)
{
    u8 i;
    u8 j;
    u8 k;
    u8 a;
    u8 b;

    if (list[0] == 0xFF || list[1] == 0xFF)
        return;
    i = 0;
    j = 0;
    do
    {
    again:
        while (list[j + 1] != 0xFF)
        {
            b = list[j + 1];
            a = list[i];
            if (a == b)
                goto dup;
            if (a < b)
            {
                list[i] = b;
                list[j + 1] = a;
            }
            j++;
        }
        i++;
        j = i;
    } while (list[i + 1] != 0xFF);
    return;
dup:
    k = j;
    do
    {
        a = list[k + 2];
        list[k + 1] = a;
        k++;
    } while (a != 0xFF);
    goto again;
}
#else
NAKED
void SkillList_SortDescending(u8 *list)
{
    asm_unified(
        ".L0815AB38:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    adds r3, r0, #0\n"
        "    ldrb r0, [r3]\n"
        "    cmp r0, #0xff\n"
        "    beq .L0815ABA2\n"
        "    ldrb r0, [r3, #1]\n"
        "    cmp r0, #0xff\n"
        "    beq .L0815ABA2\n"
        "    movs r7, #0\n"
        "    movs r4, #0\n"
        ".L0815AB4C:\n"
        "    adds r0, r4, r3\n"
        "    ldrb r0, [r0, #1]\n"
        "    adds r1, r7, #1\n"
        "    mov ip, r1\n"
        "    cmp r0, #0xff\n"
        "    beq .L0815AB7C\n"
        ".L0815AB58:\n"
        "    adds r2, r3, r7\n"
        "    adds r6, r4, r3\n"
        "    ldrb r5, [r6, #1]\n"
        "    ldrb r1, [r2]\n"
        "    adds r0, r5, #0\n"
        "    cmp r1, r0\n"
        "    beq .L0815AB8E\n"
        "    cmp r1, r0\n"
        "    bhs .L0815AB6E\n"
        "    strb r5, [r2]\n"
        "    strb r1, [r6, #1]\n"
        ".L0815AB6E:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    adds r0, r4, r3\n"
        "    ldrb r0, [r0, #1]\n"
        "    cmp r0, #0xff\n"
        "    bne .L0815AB58\n"
        ".L0815AB7C:\n"
        "    mov r1, ip\n"
        "    lsls r0, r1, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    adds r7, r4, #0\n"
        "    adds r0, r4, r3\n"
        "    ldrb r0, [r0, #1]\n"
        "    cmp r0, #0xff\n"
        "    bne .L0815AB4C\n"
        "    b .L0815ABA2\n"
        ".L0815AB8E:\n"
        "    adds r2, r4, #0\n"
        ".L0815AB90:\n"
        "    adds r0, r2, r3\n"
        "    ldrb r1, [r0, #2]\n"
        "    strb r1, [r0, #1]\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r2, r0, #0x18\n"
        "    cmp r1, #0xff\n"
        "    bne .L0815AB90\n"
        "    b .L0815AB4C\n"
        ".L0815ABA2:\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

/* Collects the skills of material id (a stock demon): those of the result's class into
   inherit[], the others in 0x24-0x39 into x290.list[], without duplicates. */
/* NONMATCHING: two comparisons load their operands in the other order. */
// Fusion_CollectMaterialSkills @ 0x0815ABA8
void Fusion_CollectMaterialSkills(u16 id)
{
    struct Combatant *m;
    u16 i;
    u32 kind;

    if (id == 0xFFFF)
        return;
    m = Stock_FindByDemonId(id);
    if (m == NULL)
        return;
    kind = ((u8 *)Demon_GetRecord(id & 0xFF))[0x1E];
    if (kind == sCalc.skillKind)
    {
        for (i = 0; i < 6; i++)
        {
            switch (i)
            {
            case 0:
                sCalc.skill = m->skills[0];
                break;
            case 1:
                sCalc.skill = m->skills[1];
                break;
            case 2:
                sCalc.skill = m->skills[2];
                break;
            case 3:
                sCalc.skill = m->skills[3];
                break;
            case 4:
                sCalc.skill = m->skills[4];
                break;
            case 5:
                sCalc.skill = m->skills[5];
                break;
            }
            if (sCalc.skill < 0x40 && (kind = Skill_GetClass(sCalc.skill)) == sCalc.skillKind && !Fusion_IsSkillInherited())
            {
                sCalc.inherit[sCalc.nA] = sCalc.skill;
                sCalc.inherit[sCalc.nA + 1] = 0xFF;
                sCalc.nA++;
            }
        }
    }
    for (i = 0; i < 6; i++)
    {
        switch (i)
        {
        case 0:
            sCalc.skill = m->skills[0];
            break;
        case 1:
            sCalc.skill = m->skills[1];
            break;
        case 2:
            sCalc.skill = m->skills[2];
            break;
        case 3:
            sCalc.skill = m->skills[3];
            break;
        case 4:
            sCalc.skill = m->skills[4];
            break;
        case 5:
            sCalc.skill = m->skills[5];
            break;
        }
        if ((u8)(sCalc.skill - 0x24) <= 0x15 && !Fusion_HasOwnOtherSkill(sCalc.skill) && !Fusion_IsSkillCollected())
        {
            sCalc.others[0x20 + sCalc.nB] = sCalc.skill;
            sCalc.others[0x21 + sCalc.nB] = 0xFF;
            sCalc.nB++;
        }
    }
}

/* Whether skill is among the result's other skills (others[], max 6). */
// Fusion_HasOwnOtherSkill @ 0x0815AD8C
u32 Fusion_HasOwnOtherSkill(u8 skill)
{
    u8 i = 0;
    u8 s;

    if ((s = sCalc.others[i]) != 0xFF)
    {
        do
        {
            if (s == skill)
                return 1;
            if (++i > 5)
                break;
        } while ((s = sCalc.others[i]) != 0xFF);
    }
    return 0;
}

/* Whether sCalc.skill is already in inherit[]. */
// Fusion_IsSkillInherited @ 0x0815ADCC
u32 Fusion_IsSkillInherited(void)
{
    s8 i;

    if (sCalc.nA == 0)
        return 0;
    for (i = (u8)sCalc.nA - 1; i >= 0; i--)
    {
        if (sCalc.inherit[i] == sCalc.skill)
            return 1;
    }
    return 0;
}

/* Whether sCalc.skill is already in the materials' other skills (x290.list). */
// Fusion_IsSkillCollected @ 0x0815AE18
u32 Fusion_IsSkillCollected(void)
{
    s8 i;

    if (sCalc.nB == 0)
        return 0;
    for (i = (u8)sCalc.nB - 1; i >= 0; i--)
    {
        if (sCalc.others[0x20 + i] == sCalc.skill)
            return 1;
    }
    return 0;
}

/* Skill class (sub_080BF5C0(skill)[0] & 0xF; 0xF none). */
// Skill_GetClass @ 0x0815AE68
u16 Skill_GetClass(u16 skill)
{
    return *sub_080BF5C0(skill & 0xFF) & 0xF;
}
