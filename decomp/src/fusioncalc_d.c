/* Fusion rules for three materials (race 8, race > 0x1A, dark alignment, race 0x16,
   ordinary), 0x08159A60-0x0815A6F0. */
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

/* Three materials, two of them race 8: the other one goes first. When the two race-8
   materials share an element type ((id - 0x32) & 3) both shift the first one's rank by their
   table 0x087F1611 values (0 counts as -1); otherwise the first two are fused, the result
   moves one rank down and is fused with the third. */
/* NONMATCHING: close; the 0 -> -1 test of each table value is compared on a copy in the
   original (and not folded to 0xFFFF), plus a few registers. */
// Fusion_ThreeTwoRace8 @ 0x08159A60
u32 Fusion_ThreeTwoRace8(void)
{
    struct FusionWork *c = &sCalc;
    struct FusionWork *w;
    u8 t;
    int a;
    int b;
    s16 va;
    s16 vb;
    s16 d;
    u16 x;
    int k;
    u16 y;
    u16 z;

    if (c->race[1] != 8)
    {
        t = c->ids[0];
        c->ids[0] = c->ids[1];
        c->ids[1] = t;
        t = c->race[0];
        c->race[0] = c->race[1];
        c->race[1] = t;
    }
    else if (c->race[2] != 8)
    {
        t = c->ids[0];
        c->ids[0] = c->ids[2];
        c->ids[2] = t;
        t = c->race[0];
        c->race[0] = c->race[2];
        c->race[2] = t;
    }
    w = &sCalc;
    a = sCalc.ids[1] - 0x32;
    if ((a & 3) == ((b = w->ids[2] - 0x32) & 3))
    {
        u8 race = w->race[0];
        s16 s;

        s = a;

        k = s / 2 + race * 4;
        va = gUnknown_087F1611[k];
        if (!(s & 1))
            va >>= 4;
        va &= 0xF;
        if (va == 0)
            va--;
        s = b;
        k = s / 2 + race * 4;
        vb = gUnknown_087F1611[k];
        if (!(s & 1))
            vb >>= 4;
        vb &= 0xF;
        if (vb == 0)
            vb--;
        d = (s16)va + (s16)vb + 1;
        if (d < 0)
        {
            d = -d;
            Fusion_RankUp(w->ids[0], d);
            return sub_08158CBC();
        }
        if (d > 0)
        {
            Fusion_RankDown(w->ids[0], d);
            return sub_08158CBC();
        }
        w->result = w->ids[0];
        return sub_08158CBC();
    }
    t = w->ids[0];
    w->ids[0] = w->ids[2];
    w->ids[2] = t;
    x = w->ids[0];
    y = w->ids[1];
    z = w->ids[2];
    sub_08158A34();
    w->ids[0] = x;
    w->ids[1] = y;
    w->ids[2] = z;
    if (w->resRace == 0xFF)
        return sub_08158E00();
    Fusion_RankDown(w->result, 1);
    w->ids[0] = w->result;
    w->ids[1] = w->ids[2];
    sub_08158A34();
    if (w->resRace == 0xFF)
        return sub_08158E00();
    return sub_08158CBC();
}

/* Three race-8 materials (ids 0x32-0x39, sorted). All from 0x32-0x35 or all from 0x36-0x39:
   the result comes from table 0x087F198B by the first id of that group not used. Mixed: the
   others are fused, then the result with the remaining one, one rank down (with two from the
   upper group, no result if it cannot move down). */
/* NONMATCHING: the last table store loads the value before the address. */
// Fusion_ThreeRace8 @ 0x08159BFC
#ifdef NONMATCHING
u32 Fusion_ThreeRace8(void)
{
    s16 k;
    u8 t;
    u16 x;
    u16 y;
    u16 z;
    u16 r;

    if (sCalc.ids[0] > 0x35)
    {
        k = 0x36;
        goto search;
    }
    if (sCalc.ids[1] > 0x35)
    {
        t = sCalc.ids[0];
        sCalc.ids[0] = sCalc.ids[2];
        sCalc.ids[2] = t;
        x = sCalc.ids[0];
        y = sCalc.ids[1];
        z = sCalc.ids[2];
        sub_08158A34();
        sCalc.ids[0] = x;
        sCalc.ids[1] = y;
        sCalc.ids[2] = z;
        if (sCalc.resRace == 0xFF)
            return sub_08158E00();
        sCalc.ids[0] = sCalc.result;
        sCalc.ids[1] = z;
        sub_08158A34();
        if (sCalc.resRace == 0xFF)
            return sub_08158E00();
        r = sCalc.result;
        Fusion_RankDown(r, 1);
        if (sCalc.result == r)
            sCalc.result = 0xFFFF;
        return sub_08158CBC();
    }
    if (sCalc.ids[2] > 0x35)
    {
        x = sCalc.ids[0];
        y = sCalc.ids[1];
        z = sCalc.ids[2];
        sub_08158A34();
        sCalc.ids[0] = x;
        sCalc.ids[1] = y;
        sCalc.ids[2] = z;
        if (sCalc.resRace == 0xFF)
            return sub_08158E00();
        sCalc.ids[0] = sCalc.result;
        sCalc.ids[1] = z;
        sub_08158A34();
        if (sCalc.resRace == 0xFF)
            return sub_08158E00();
        Fusion_RankDown(sCalc.result, 1);
        return sub_08158CBC();
    }
    k = 0x32;
search:
    for (; k <= 0x39; k++)
    {
        if (sCalc.ids[0] != k && sCalc.ids[1] != k && sCalc.ids[2] != k)
            break;
    }
    sCalc.result = gUnknown_087F198B[k - 0x32];
    return sub_08158CBC();
}
#else
NAKED
u32 Fusion_ThreeRace8(void)
{
    asm_unified(
        ".L08159BFC:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sb\n"
        "    mov r6, r8\n"
        "    push {r6, r7}\n"
        "    sub sp, #4\n"
        "    ldr r0, .L08159C18\n"
        "    adds r2, r0, #0\n"
        "    adds r2, #0x90\n"
        "    ldrh r1, [r2]\n"
        "    mov r8, r0\n"
        "    cmp r1, #0x35\n"
        "    bls .L08159C1C\n"
        "    movs r2, #0x36\n"
        "    b .L08159CEE\n"
        ".L08159C18: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L08159C1C:\n"
        "    movs r0, #0x92\n"
        "    add r0, r8\n"
        "    mov sb, r0\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0x35\n"
        "    bls .L08159C94\n"
        "    lsls r1, r1, #0x18\n"
        "    lsrs r1, r1, #0x18\n"
        "    mov r4, r8\n"
        "    adds r4, #0x94\n"
        "    ldrh r0, [r4]\n"
        "    strh r0, [r2]\n"
        "    strh r1, [r4]\n"
        "    ldrh r5, [r2]\n"
        "    mov r1, sb\n"
        "    ldrh r6, [r1]\n"
        "    ldrh r7, [r4]\n"
        "    str r2, [sp]\n"
        "    bl sub_08158A34\n"
        "    ldr r2, [sp]\n"
        "    strh r5, [r2]\n"
        "    mov r3, sb\n"
        "    strh r6, [r3]\n"
        "    strh r7, [r4]\n"
        "    adds r4, #0xe\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #0xff\n"
        "    bne .L08159C5C\n"
        "    bl sub_08158E00\n"
        "    b .L08159D38\n"
        ".L08159C5C:\n"
        "    mov r5, r8\n"
        "    adds r5, #0xa0\n"
        "    ldrh r0, [r5]\n"
        "    strh r0, [r2]\n"
        "    mov r0, sb\n"
        "    strh r7, [r0]\n"
        "    bl sub_08158A34\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #0xff\n"
        "    bne .L08159C78\n"
        "    bl sub_08158E00\n"
        "    b .L08159D38\n"
        ".L08159C78:\n"
        "    ldrh r4, [r5]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #1\n"
        "    bl Fusion_RankDown\n"
        "    ldrh r0, [r5]\n"
        "    cmp r0, r4\n"
        "    bne .L08159D34\n"
        "    ldr r0, .L08159C90\n"
        "    strh r0, [r5]\n"
        "    b .L08159D34\n"
        "    .byte 0x00, 0x00\n"
        ".L08159C90: .4byte 0x0000FFFF\n"
        ".L08159C94:\n"
        "    mov r4, r8\n"
        "    adds r4, #0x94\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #0x35\n"
        "    bls .L08159CEC\n"
        "    ldrh r5, [r2]\n"
        "    mov r1, sb\n"
        "    ldrh r6, [r1]\n"
        "    adds r7, r0, #0\n"
        "    str r2, [sp]\n"
        "    bl sub_08158A34\n"
        "    ldr r2, [sp]\n"
        "    strh r5, [r2]\n"
        "    mov r3, sb\n"
        "    strh r6, [r3]\n"
        "    strh r7, [r4]\n"
        "    mov r5, r8\n"
        "    adds r5, #0xa2\n"
        "    ldrb r0, [r5]\n"
        "    cmp r0, #0xff\n"
        "    bne .L08159CC6\n"
        "    bl sub_08158E00\n"
        "    b .L08159D38\n"
        ".L08159CC6:\n"
        "    mov r4, r8\n"
        "    adds r4, #0xa0\n"
        "    ldrh r0, [r4]\n"
        "    strh r0, [r2]\n"
        "    mov r0, sb\n"
        "    strh r7, [r0]\n"
        "    bl sub_08158A34\n"
        "    ldrb r0, [r5]\n"
        "    cmp r0, #0xff\n"
        "    bne .L08159CE2\n"
        "    bl sub_08158E00\n"
        "    b .L08159D38\n"
        ".L08159CE2:\n"
        "    ldrh r0, [r4]\n"
        "    movs r1, #1\n"
        "    bl Fusion_RankDown\n"
        "    b .L08159D34\n"
        ".L08159CEC:\n"
        "    movs r2, #0x32\n"
        ".L08159CEE:\n"
        "    lsls r1, r2, #0x10\n"
        "    asrs r0, r1, #0x10\n"
        "    ldr r6, .L08159D48\n"
        "    cmp r0, #0x39\n"
        "    bgt .L08159D24\n"
        "    ldr r0, .L08159D4C\n"
        "    ldrh r3, [r0]\n"
        "    adds r5, r0, #4\n"
        "    adds r4, r0, #2\n"
        ".L08159D00:\n"
        "    asrs r1, r1, #0x10\n"
        "    cmp r3, r1\n"
        "    beq .L08159D12\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, r1\n"
        "    beq .L08159D12\n"
        "    ldrh r0, [r5]\n"
        "    cmp r0, r1\n"
        "    bne .L08159D24\n"
        ".L08159D12:\n"
        "    lsls r0, r2, #0x10\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #9\n"
        "    adds r0, r0, r1\n"
        "    lsrs r2, r0, #0x10\n"
        "    lsls r1, r2, #0x10\n"
        "    asrs r0, r1, #0x10\n"
        "    cmp r0, #0x39\n"
        "    ble .L08159D00\n"
        ".L08159D24:\n"
        "    lsls r0, r2, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    subs r0, #0x32\n"
        "    adds r0, r0, r6\n"
        "    mov r1, r8\n"
        "    adds r1, #0xa0\n"
        "    ldrb r0, [r0]\n"
        "    strh r0, [r1]\n"
        ".L08159D34:\n"
        "    bl sub_08158CBC\n"
        ".L08159D38:\n"
        "    add sp, #4\n"
        "    pop {r3, r4}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L08159D48: .4byte gUnknown_087F198B\n"
        ".L08159D4C: .4byte 0x0203B8F8 @ EWRAM+0x3B8F8\n"
    );
}
#endif

/* Three materials, the third above race 0x1A: the first two are fused, the result moves one
   rank down and is fused with the third. Repeats while gUnk_03006A38 is set (by a random
   sub-result) and sub_08158CBC fails. */
// Fusion_ThreeHighRaceLast @ 0x08159D50
u32 Fusion_ThreeHighRaceLast(void)
{
    u16 a;
    u16 b;
    u16 c;
    u32 r;

retry:
    gUnk_03006A38 = 0;
    a = sCalc.ids[0];
    b = sCalc.ids[1];
    c = sCalc.ids[2];
    sub_08158A34();
    sCalc.ids[0] = a;
    sCalc.ids[1] = b;
    sCalc.ids[2] = c;
    if (sCalc.resRace == 0xFF)
        return sub_08158E00();
    Fusion_RankDown(sCalc.result, 1);
    sCalc.ids[0] = sCalc.result;
    sCalc.ids[1] = sCalc.ids[2];
    sub_08158A34();
    if (sCalc.resRace == 0xFF)
        return sub_08158E00();
    r = sub_08158CBC();
    if (gUnk_03006A38 && !r)
        goto retry;
    return r;
}

/* Three materials, the second above race 0x1A: as Fusion_ThreeHighRaceLast with the first and third
   materials swapped (the swap is redone on every retry). */
// Fusion_ThreeHighRaceMiddle @ 0x08159DF0
u32 Fusion_ThreeHighRaceMiddle(void)
{
    u16 a;
    u16 b;
    u16 c;
    u32 r;

retry:
    gUnk_03006A38 = 0;
    a = sCalc.ids[0];
    sCalc.ids[0] = sCalc.ids[2];
    sCalc.ids[2] = a;
    a = sCalc.ids[0];
    b = sCalc.ids[1];
    c = sCalc.ids[2];
    sub_08158A34();
    sCalc.ids[0] = a;
    sCalc.ids[1] = b;
    sCalc.ids[2] = c;
    if (sCalc.resRace == 0xFF)
        return sub_08158E00();
    Fusion_RankDown(sCalc.result, 1);
    sCalc.ids[0] = sCalc.result;
    sCalc.ids[1] = sCalc.ids[2];
    sub_08158A34();
    if (sCalc.resRace == 0xFF)
        return sub_08158E00();
    r = sub_08158CBC();
    if (gUnk_03006A38 && !r)
        goto retry;
    return r;
}

/* Three materials, the first above race 0x1A: the highest-level material moves down 3 ranks. */
// Fusion_ThreeHighRaceFirst @ 0x08159E9C
u32 Fusion_ThreeHighRaceFirst(void)
{
    u32 r;
    u16 *p;
    struct FusionWork *c;

retry:
    gUnk_03006A38 = 0;
    c = &sCalc;
    c->unkA4 |= 0x40;
    if (c->level[0] < c->level[1])
    {
        if (c->level[1] < c->level[2])
            goto third;
        p = &c->ids[1];
        goto shift;
    }
    if (c->level[0] < c->level[2])
    {
    third:
        p = &c->ids[2];
    shift:
        Fusion_RankDown(*p, 3);
        return sub_08158CBC();
    }
    Fusion_RankDown(c->ids[0], 3);
    r = sub_08158CBC();
    if (gUnk_03006A38 && !r)
        goto retry;
    return r;
}

/* Three materials, one of alignment 0xB (dark): it goes first, then the lower-level of the
   other two; the first two are fused (repeated until a result), the result with the third,
   one rank down. A result equal to a material or not allowed (sub_0815BA28) is an accident
   (sub_08158CA4). Two or more dark materials: no result. */
// Fusion_ThreeDark @ 0x08159F18
u32 Fusion_ThreeDark(void)
{
    u8 n = 0;
    u16 x;
    u16 y;
    u16 z;
    u32 r;

    if (sCalc.align[0] == 0xB)
        n = 1;
    if (sCalc.align[1] == 0xB)
        n++;
    if (sCalc.align[2] == 0xB)
        n++;
    if (n > 1)
        return sub_08158E00();
    sCalc.unkA4 |= 8;
    sCalc.unkA6 = (sCalc.unkA6 & 3) | 0x30;
    if (sCalc.align[0] != 0xB)
    {
        if (sCalc.align[1] == 0xB)
            Fusion_SwapMaterials(1, 0);
        else if (sCalc.align[2] == 0xB)
            Fusion_SwapMaterials(2, 0);
    }
    if (sCalc.level[1] >= sCalc.level[2])
        Fusion_SwapMaterials(1, 2);
    do
    {
        x = sCalc.ids[0];
        y = sCalc.ids[1];
        z = sCalc.ids[2];
        r = sub_08158A34();
        sCalc.ids[0] = x;
        sCalc.ids[1] = y;
        sCalc.ids[2] = z;
    } while (r == 0);
    sCalc.ids[0] = sCalc.result;
    sCalc.ids[1] = sCalc.ids[2];
    if (!sub_08158A34())
    {
        sCalc.unkA6 = 0x30;
        return sub_08158CA4();
    }
    Fusion_RankDown(sCalc.result, 1);
    if (sCalc.result != sCalc.orig[0] && sCalc.result != sCalc.orig[1]
     && sCalc.result != sCalc.orig[2])
    {
        sCalc.unkA6 = 0x30;
        if (sub_0815BA28(sCalc.result))
            return sub_08158CBC();
    }
    sCalc.unkA6 = 0x30;
    return sub_08158CA4();
}

/* Swaps materials a and b (0-2): alignment, race, level and id. */
// Fusion_SwapMaterials @ 0x0815A060
void Fusion_SwapMaterials(u16 a, u16 b)
{
    u8 *pa;
    u8 *pb;
    u16 *ha;
    u16 *hb;
    u8 t;
    u16 h;

    if (a == 0)
        pa = &sCalc.align[0];
    if (a == 1)
        pa = &sCalc.align[1];
    if (a == 2)
        pa = &sCalc.align[2];
    if (b == 0)
        pb = &sCalc.align[0];
    if (b == 1)
        pb = &sCalc.align[1];
    if (b == 2)
        pb = &sCalc.align[2];
    t = *pb;
    *pb = *pa;
    *pa = t;
    if (a == 0)
        pa = &sCalc.race[0];
    if (a == 1)
        pa = &sCalc.race[1];
    if (a == 2)
        pa = &sCalc.race[2];
    if (b == 0)
        pb = &sCalc.race[0];
    if (b == 1)
        pb = &sCalc.race[1];
    if (b == 2)
        pb = &sCalc.race[2];
    t = *pb;
    *pb = *pa;
    *pa = t;
    if (a == 0)
        pa = &sCalc.level[0];
    if (a == 1)
        pa = &sCalc.level[1];
    if (a == 2)
        pa = &sCalc.level[2];
    if (b == 0)
        pb = &sCalc.level[0];
    if (b == 1)
        pb = &sCalc.level[1];
    if (b == 2)
        pb = &sCalc.level[2];
    t = *pb;
    *pb = *pa;
    *pa = t;
    if (a == 0)
        ha = &sCalc.ids[0];
    if (a == 1)
        ha = &sCalc.ids[1];
    if (a == 2)
        ha = &sCalc.ids[2];
    if (b == 0)
        hb = &sCalc.ids[0];
    if (b == 1)
        hb = &sCalc.ids[1];
    if (b == 2)
        hb = &sCalc.ids[2];
    h = *hb;
    *hb = *ha;
    *ha = h;
}

/* Three materials, one or more of race 0x16. */
// Fusion_ThreeRace16 @ 0x0815A150
u32 Fusion_ThreeRace16(void)
{
    u8 n = 0;
    u16 a;
    u16 b;
    u16 c;

    if (sCalc.race[0] == 0x16)
        n = 1;
    if (sCalc.race[1] == 0x16)
        n++;
    if (sCalc.race[2] == 0x16)
        n++;
    if (n == 3)
        return Fusion_ThreeAllRace16();
    if (n == 2)
        return Fusion_ThreeTwoRace16();
    if (sCalc.race[0] == 0x16)
        Fusion_SwapMaterials(0, 2);
    else if (sCalc.race[1] == 0x16)
        Fusion_SwapMaterials(1, 2);
    a = sCalc.ids[0];
    b = sCalc.ids[1];
    c = sCalc.ids[2];
    sub_08158A34();
    sCalc.ids[0] = a;
    sCalc.ids[1] = b;
    sCalc.ids[2] = c;
    if (sCalc.resRace == 0xFF)
        return sub_08158E00();
    sCalc.ids[0] = sCalc.result;
    sCalc.ids[1] = sCalc.ids[2];
    sub_08158A34();
    if (sCalc.resRace == 0xFF)
        return sub_08158E00();
    Fusion_RankDown(sCalc.result, 1);
    return sub_08158CBC();
}

/* Two materials of race 0x16: they go last, the higher-level one first. */
// Fusion_ThreeTwoRace16 @ 0x0815A230
u32 Fusion_ThreeTwoRace16(void)
{
    u16 a;
    u16 b;
    u16 c;

    if (sCalc.race[0] == 0x16)
    {
        if (sCalc.race[1] != 0x16)
            Fusion_SwapMaterials(0, 1);
        else
            Fusion_SwapMaterials(0, 2);
    }
    if (sCalc.level[1] < sCalc.level[2])
        Fusion_SwapMaterials(1, 2);
    a = sCalc.ids[0];
    b = sCalc.ids[1];
    c = sCalc.ids[2];
    sub_08158A34();
    sCalc.ids[0] = a;
    sCalc.ids[1] = b;
    sCalc.ids[2] = c;
    if (sCalc.resRace == 0xFF)
        return sub_08158E00();
    sCalc.ids[0] = sCalc.result;
    sCalc.ids[1] = sCalc.ids[2];
    sub_08158A34();
    if (sCalc.resRace == 0xFF)
        return sub_08158E00();
    Fusion_RankDown(sCalc.result, 1);
    return sub_08158CBC();
}

/* Three materials of race 0x16: the result is demon 0x35. */
// Fusion_ThreeAllRace16 @ 0x0815A2F4
u32 Fusion_ThreeAllRace16(void)
{
    sCalc.result = 0x35;
    return sub_08158CBC();
}

/* Swap materials a and b (race, alignment, level, id); t and h are the caller's temporaries. */
#define SWAP_MATERIAL(a, b)                                                    \
    {                                                                          \
        t = sCalc.race[a]; sCalc.race[a] = sCalc.race[b]; sCalc.race[b] = t;     \
        t = sCalc.align[a]; sCalc.align[a] = sCalc.align[b]; sCalc.align[b] = t; \
        t = sCalc.level[a]; sCalc.level[a] = sCalc.level[b]; sCalc.level[b] = t; \
        h = sCalc.ids[a]; sCalc.ids[a] = sCalc.ids[b]; sCalc.ids[b] = h;         \
    }


/* Ordinary three-material fusion. Sorts the materials by level, high first (equal levels: lower
   id first). Unless all three share an alignment, the last two alignments pick a column of
   table 0x087F1993 and the first one's alignment the race (table 0x087F1A23); the result is
   the first demon of that race at or above the mean level + 4 x (number of materials of race
   0-0xC) - 4. A race 0xFF there is an accident: a random allowed demon below the hero's level.
   Same alignment or no column: Fusion_ThreeFallback. */
// Fusion_ThreeNormal @ 0x0815A30C
u32 Fusion_ThreeNormal(void)
{
    s16 n = 0;
    s16 lv;
    u8 t;
    u32 h;
    u8 col;
    u32 r;
    u16 id;

    if (sCalc.race[0] <= 0xC)
        n = 1;
    if (sCalc.race[1] <= 0xC)
        n++;
    if (sCalc.race[2] <= 0xC)
        n++;
    n = n * 4 - 4;
    {
        s16 mean = (sCalc.level[0] + sCalc.level[1] + sCalc.level[2]) / 3;
        lv = mean + n;
    }

    /* Sort by level, high first; equal levels: lower id first. The swap is written out twice. */
    if (sCalc.level[2] > sCalc.level[1])
        SWAP_MATERIAL(2, 1)
    else if (sCalc.level[2] == sCalc.level[1] && sCalc.ids[2] < sCalc.ids[1])
        SWAP_MATERIAL(2, 1)
    if (sCalc.level[1] > sCalc.level[0])
        SWAP_MATERIAL(1, 0)
    else if (sCalc.level[1] == sCalc.level[0] && sCalc.ids[1] < sCalc.ids[0])
        SWAP_MATERIAL(1, 0)
    if (sCalc.level[2] > sCalc.level[1])
        SWAP_MATERIAL(2, 1)
    else if (sCalc.level[2] == sCalc.level[1] && sCalc.ids[2] < sCalc.ids[1])
        SWAP_MATERIAL(2, 1)

    if (sCalc.align[0] == sCalc.align[1] && sCalc.align[0] == sCalc.align[2])
        return Fusion_ThreeFallback();
    Demon_GetRaceAndAlign(sCalc.ids[1], &sCalc.align[1], &sCalc.race[1]);
    Demon_GetRaceAndAlign(sCalc.ids[2], &sCalc.align[2], &sCalc.race[2]);
    h = sCalc.align[1] * 12 + sCalc.align[2];   /* h reused as the table index */
    col = gUnknown_087F1993[h];
    if (col == 0xFF)
        return Fusion_ThreeFallback();
    Demon_GetRaceAndAlign(sCalc.ids[0], &sCalc.align[0], &sCalc.race[0]);
    h = col + sCalc.align[0] * 0x16;
    sCalc.resRace = gUnknown_087F1A23[h];
    if (sCalc.resRace != 0xFF)
    {
    next_level:
        if (Fusion_FindRaceDemonByLevel(lv) >= 0)
            return sub_08158CBC();
        lv++;
        goto next_level;
    }

    /* Accident: a random allowed demon below the hero's level. */
    sCalc.unkA4 |= 8;
    sCalc.unkA6 = (sCalc.unkA6 & 3) | 0x30;
    for (;;)
    {
        id = sub_08159144();
        if (id == 0xFF)
            continue;
        sCalc.result = id;
        if (!sub_0815BA28(sCalc.result))
            continue;
        {
            u8 level = Demon_GetLevel(sCalc.result);
            if (level >= gGameState.members[0].level)
                continue;
        }
        r = sub_08158CBC();
        if (r == 0)
            continue;
        if (sCalc.result > 0xFE)
            continue;
        return r;
    }
}

/* Fallback of Fusion_ThreeNormal: the third and second materials are fused, then the result with
   the first; the final result moves one rank down. */
// Fusion_ThreeFallback @ 0x0815A670
u32 Fusion_ThreeFallback(void)
{
    u16 a;
    u16 b;
    u16 c;

    a = sCalc.ids[2];
    sCalc.ids[2] = sCalc.ids[0];
    sCalc.ids[0] = a;
    a = sCalc.ids[0];
    b = sCalc.ids[1];
    c = sCalc.ids[2];
    sub_08158A34();
    sCalc.ids[0] = a;
    sCalc.ids[1] = b;
    sCalc.ids[2] = c;
    if (sCalc.resRace == 0xFF)
        return sub_08158E00();
    sCalc.ids[0] = sCalc.result;
    sCalc.ids[1] = sCalc.ids[2];
    sub_08158A34();
    if (sCalc.resRace == 0xFF)
        return sub_08158E00();
    Fusion_RankDown(sCalc.result, 1);
    return sub_08158CBC();
}
