#include "global.h"
#include "fusion.h"

/* Two-demon fusion: works out gUnk_0203B868.result from the sorted pair. */
// Fusion_CalcTwo @ 0x08158970
u32 Fusion_CalcTwo(void)
{
    struct FusionCalc *c = &gUnk_0203B868;
    u32 r;
    u16 t;

    c->orig[0] = c->ids[0];
    c->orig[1] = c->ids[1];
    c->orig[2] = c->ids[2];
    c->unkA4 = 0;
    c->unkA6 = 0;
    if (c->orig[0] > c->orig[1])
    {
        t = c->ids[0];
        c->ids[0] = c->orig[1];
        c->ids[1] = t;
    }
    r = Fusion_CalcPair();
    c->ids[0] = c->orig[0];
    c->ids[1] = c->orig[1];
    c->ids[2] = c->orig[2];
    if ((c->unkA6 & 0x30) != 0x30 && !(c->unkA6 & 0x40))
    {
        if ((u16)(c->result - 0x32) <= 7)
            c->unkA6 = (c->unkA6 & 3) | 0x10;
        if (c->resRace > 0x1A)
            c->unkA6 = (c->unkA6 & 3) | 0x20;
    }
    return r;
}

// sub_08158A34 @ 0x08158A34
u32 sub_08158A34(void)
{
    return Fusion_CalcPair();
}

/* Fusion rule dispatch for two materials. */
// Fusion_CalcPair @ 0x08158A40
u32 Fusion_CalcPair(void)
{
    struct FusionCalc *c = &gUnk_0203B868;

    c->save[0] = c->ids[0];
    c->save[1] = c->ids[1];
    c->save[2] = c->ids[2];
    if (c->save[0] == 0xFF || c->save[1] == 0xFF || !sub_0815B8F8(c->ids[0], 0)
     || !sub_0815B8F8(c->ids[1], 0))
    {
        gUnk_0203B868.result = 0xFF;
        gUnk_0203B868.resRace = 0xFF;
        gUnk_0203B868.unkA3 = -1;
        gUnk_0203B868.unkA6 = 0x40;
        return 0;
    }
    Demon_GetRaceAndAlign(c->ids[0], &c->align[0], &c->race[0]);
    Demon_GetRaceAndAlign(c->ids[1], &c->align[1], &c->race[1]);
    c->level[0] = Demon_GetLevel(c->ids[0]);
    c->level[1] = Demon_GetLevel(c->ids[1]);
    if (Fusion_FindSpecialPair())
        return sub_08158D08();
    if (c->ids[0] == 0xFB || c->ids[1] == 0xFB)
        return sub_081593EC();
    if (c->race[0] == c->race[1])
        return sub_08158E78();
    if (c->align[0] == c->align[1])
        return sub_081590CC();
    if (c->align[0] == 0xB || c->align[1] == 0xB)
        return sub_0815915C();
    if (c->race[0] == 8 || c->race[1] == 8)
    {
        c->unkA6 &= 3;
        return sub_081592AC();
    }
    if (c->race[0] > 0x1A || c->race[1] > 0x1A)
    {
        c->unkA6 &= 3;
        return sub_08158FA4();
    }
    c->unkA6 &= 3;
    return sub_0815937C();
}

/* Special two-way fusions (table 0x087F1AD3). */
// Fusion_FindSpecialPair @ 0x08158B9C
#ifdef NONMATCHING
u32 Fusion_FindSpecialPair(void)
{
    u32 i = 0;
    const u8 *t = gUnknown_087F1AD3;

    for (; t[i] != 0xFF; i += 3)
    {
        if ((t[i] == gUnk_0203B868.ids[0] || t[i] == gUnk_0203B868.ids[1])
         && (t[i + 1] == gUnk_0203B868.ids[0] || t[i + 1] == gUnk_0203B868.ids[1]))
        {
            gUnk_0203B868.result = t[i + 2];
            return 1;
        }
    }
    return 0;
}
#else
NAKED
u32 Fusion_FindSpecialPair(void)
{
    asm_unified(
        ".L08158B9C:\n"
        "    push {r4, r5, r6, lr}\n"
        "    movs r2, #0\n"
        "    ldr r0, .L08158BDC\n"
        "    ldrb r1, [r0]\n"
        "    adds r4, r0, #0\n"
        "    cmp r1, #0xff\n"
        "    beq .L08158BEE\n"
        "    ldr r0, .L08158BE0\n"
        "    ldrh r3, [r0]\n"
        "    adds r5, r0, #2\n"
        "    adds r6, r0, #0\n"
        "    adds r6, #0x10\n"
        ".L08158BB4:\n"
        "    cmp r1, r3\n"
        "    beq .L08158BBE\n"
        "    ldrh r0, [r5]\n"
        "    cmp r1, r0\n"
        "    bne .L08158BE4\n"
        ".L08158BBE:\n"
        "    adds r0, r2, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrb r1, [r0]\n"
        "    cmp r1, r3\n"
        "    beq .L08158BCE\n"
        "    ldrh r0, [r5]\n"
        "    cmp r1, r0\n"
        "    bne .L08158BE4\n"
        ".L08158BCE:\n"
        "    adds r0, r2, #2\n"
        "    adds r0, r0, r4\n"
        "    ldrb r0, [r0]\n"
        "    strh r0, [r6]\n"
        "    movs r0, #1\n"
        "    b .L08158BF0\n"
        "    .byte 0x00, 0x00\n"
        ".L08158BDC: .4byte gUnknown_087F1AD3\n"
        ".L08158BE0: .4byte 0x0203B8F8 @ EWRAM+0x3B8F8\n"
        ".L08158BE4:\n"
        "    adds r2, #3\n"
        "    adds r0, r2, r4\n"
        "    ldrb r1, [r0]\n"
        "    cmp r1, #0xff\n"
        "    bne .L08158BB4\n"
        ".L08158BEE:\n"
        "    movs r0, #0\n"
        ".L08158BF0:\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

/* Special three-way fusions (table 0x087F1AF2). */
// Fusion_FindSpecialTriple @ 0x08158BF8
#ifdef NONMATCHING
u32 Fusion_FindSpecialTriple(void)
{
    u8 i = 0;
    const u8 *t = gUnknown_087F1AF2;
    struct FusionCalc *c = &gUnk_0203B868;

    for (; t[i] != 0xFF; i += 4)
    {
        if ((t[i] == c->ids[0] || t[i] == c->ids[1] || t[i] == c->ids[2])
         && (t[i + 1] == c->ids[0] || t[i + 1] == c->ids[1] || t[i + 1] == c->ids[2])
         && (t[i + 2] == c->ids[0] || t[i + 2] == c->ids[1] || t[i + 2] == c->ids[2]))
        {
            c->result = t[i + 3];
            return 1;
        }
    }
    c->unkA6 = 0x40;
    return 0;
}
#else
NAKED
u32 Fusion_FindSpecialTriple(void)
{
    asm_unified(
        ".L08158BF8:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sb\n"
        "    mov r6, r8\n"
        "    push {r6, r7}\n"
        "    movs r1, #0\n"
        "    ldr r2, .L08158C78\n"
        "    ldrb r0, [r2]\n"
        "    ldr r3, .L08158C7C\n"
        "    cmp r0, #0xff\n"
        "    beq .L08158C8E\n"
        "    adds r5, r3, #0\n"
        "    adds r5, #0x90\n"
        "    ldrh r4, [r5]\n"
        "    mov r8, r4\n"
        "    movs r6, #0x92\n"
        "    adds r6, r6, r3\n"
        "    mov ip, r6\n"
        "    adds r4, r3, #0\n"
        "    adds r4, #0x94\n"
        "    movs r7, #0xa0\n"
        "    adds r7, r7, r3\n"
        "    mov sb, r7\n"
        ".L08158C24:\n"
        "    cmp r0, r8\n"
        "    beq .L08158C36\n"
        "    mov r6, ip\n"
        "    ldrh r6, [r6]\n"
        "    cmp r0, r6\n"
        "    beq .L08158C36\n"
        "    ldrh r7, [r4]\n"
        "    cmp r0, r7\n"
        "    bne .L08158C80\n"
        ".L08158C36:\n"
        "    adds r0, r1, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrb r0, [r0]\n"
        "    ldrh r6, [r5]\n"
        "    cmp r0, r6\n"
        "    beq .L08158C50\n"
        "    mov r7, ip\n"
        "    ldrh r7, [r7]\n"
        "    cmp r0, r7\n"
        "    beq .L08158C50\n"
        "    ldrh r6, [r4]\n"
        "    cmp r0, r6\n"
        "    bne .L08158C80\n"
        ".L08158C50:\n"
        "    adds r0, r1, #2\n"
        "    adds r0, r0, r2\n"
        "    ldrb r0, [r0]\n"
        "    ldrh r7, [r5]\n"
        "    cmp r0, r7\n"
        "    beq .L08158C6A\n"
        "    mov r6, ip\n"
        "    ldrh r6, [r6]\n"
        "    cmp r0, r6\n"
        "    beq .L08158C6A\n"
        "    ldrh r7, [r4]\n"
        "    cmp r0, r7\n"
        "    bne .L08158C80\n"
        ".L08158C6A:\n"
        "    adds r0, r1, #3\n"
        "    adds r0, r0, r2\n"
        "    ldrb r0, [r0]\n"
        "    mov r1, sb\n"
        "    strh r0, [r1]\n"
        "    movs r0, #1\n"
        "    b .L08158C98\n"
        ".L08158C78: .4byte gUnknown_087F1AF2\n"
        ".L08158C7C: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L08158C80:\n"
        "    adds r0, r1, #4\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r1, r0, #0x18\n"
        "    adds r0, r1, r2\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0xff\n"
        "    bne .L08158C24\n"
        ".L08158C8E:\n"
        "    adds r1, r3, #0\n"
        "    adds r1, #0xa6\n"
        "    movs r0, #0x40\n"
        "    strb r0, [r1]\n"
        "    movs r0, #0\n"
        ".L08158C98:\n"
        "    pop {r3, r4}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

// sub_08158CA4 @ 0x08158CA4
u32 sub_08158CA4(void)
{
    gUnk_0203B868.result = 0xFB;
    return sub_08158CBC();
}

// sub_08158CBC @ 0x08158CBC
u32 sub_08158CBC(void)
{
    struct FusionCalc *c = &gUnk_0203B868;

    u32 r;

    c->unkA4 &= 0xFC;
    if (c->result != 0xFFFF)
    {
        c->unkA4 &= 0x7F;
        c->unkA8 = 1;
        r = sub_08158D20();
    }
    else
    {
        sub_08158E00();
        c->unkA6 = 0x40;
        r = 0;
    }
    return r;
}

// sub_08158D08 @ 0x08158D08
u32 sub_08158D08(void)
{
    gUnk_0203B868.unkA8 = 0;
    return sub_08158D20();
}

/* Checks the result found: must be valid and differ from the materials. */
// sub_08158D20 @ 0x08158D20
u32 sub_08158D20(void)
{
    struct FusionCalc *c = &gUnk_0203B868;

    c->result &= 0xFF;
    Demon_GetRaceAndAlign(c->result, (u8 *)&c->unkA3, &c->resRace);
    if (!sub_0815BA28(c->result))
    {
        c->result = 0xFF;
        c->resRace = 0xFF;
        c->unkA3 = -1;
        gUnk_0203B868.unkA6 = 0x40;
        return 0;
    }
    c->ids[0] = c->orig[0];
    c->ids[1] = c->orig[1];
    c->ids[2] = c->orig[2];
    if (c->unkA4 & 0x80)
        return 1;
    if (c->unkA8 != 0 && c->result == c->ids[2])
    {
        c->result = 0xFF;
        c->resRace = 0xFF;
        c->unkA3 = -1;
        gUnk_0203B868.unkA6 = 0x40;
        return 0;
    }
    if (gUnk_0203B868.result == gUnk_0203B868.ids[1] || gUnk_0203B868.result == gUnk_0203B868.ids[0])
    {
        gUnk_0203B868.result = 0xFF;
        gUnk_0203B868.resRace = 0xFF;
        gUnk_0203B868.unkA3 = -1;
        gUnk_0203B868.unkA6 = 0x40;
        return 0;
    }
    return 1;
}

// sub_08158E00 @ 0x08158E00
u32 sub_08158E00(void)
{
    u32 r;

    if (gUnk_0203B868.unkA4 & 8)
    {
        gUnk_0203B868.result = 0xFB;
        gUnk_0203B868.unkA4 &= 0x7F;
        gUnk_0203B868.unkA8 = 1;
        r = sub_08158D20();
    }
    else
    {
        gUnk_0203B868.result = 0xFF;
        gUnk_0203B868.resRace = 0xFF;
        gUnk_0203B868.unkA3 = -1;
        gUnk_0203B868.unkA6 = 0x40;
        r = 0;
    }
    return r;
}

/* No result. */
// Fusion_SetNoResult @ 0x08158E54
u32 Fusion_SetNoResult(void)
{
    gUnk_0203B868.result = 0xFF;
    gUnk_0203B868.resRace = 0xFF;
    gUnk_0203B868.unkA3 = -1;
    gUnk_0203B868.unkA6 = 0x40;
    return 0;
}

/* Two materials of the same race. */
// sub_08158E78 @ 0x08158E78
u32 sub_08158E78(void)
{
    struct FusionCalc *c = &gUnk_0203B868;

    if (c->race[0] > 0x1A)
        return sub_08158F48(c->race[0]);
    if (gUnknown_087F15E0[c->race[0]] == 0)
        return sub_08158ED0();
    if (gUnknown_087F15E0[c->race[0]] == 0xFF)
    {
        Fusion_SetNoResult();
        c->unkA6 = 0x40;
        return 0;
    }
    c->result = gUnknown_087F15E0[c->race[0]];
    return sub_08158D08();
}

/* Element fusion table (ids 0x32-0x39 pairs) -> race, then the highest demon of that race
   not above the hero's level. */
// sub_08158ED0 @ 0x08158ED0
u32 sub_08158ED0(void)
{
    struct FusionCalc *c = &gUnk_0203B868;
    u16 a = c->ids[0] - 0x32;
    u16 b = c->ids[1] - 0x32;
    u32 idx = a * 8 + b;
    const u8 *p = &gUnknown_087F15A0[idx];
    s32 lv;

    if (*p == 0xFF)
    {
        Fusion_SetNoResult();
        c->unkA6 = 0x40;
        return 0;
    }
    c->resRace = *p;
    for (lv = gGameState.members[0].level; lv > 0; lv--)
    {
        if (Fusion_FindRaceDemonByLevel(lv) >= 0)
            break;
    }
    if (lv == 0)
        return sub_08158CA4();
    return sub_08158D08();
}

/* Two elementals/special races of the same kind: next demon of the race above their mean level. */
// sub_08158F48 @ 0x08158F48
u32 sub_08158F48(u32 race)
{
    struct FusionCalc *c = &gUnk_0203B868;
    s32 lv;
    u16 *res;

    c->resRace = gUnknown_087F15E0[race];
    lv = ((c->level[0] + c->level[1]) >> 1) + 2;
    res = &c->result;
    for (; lv <= 0x62; lv++)
    {
        s32 id = Fusion_FindRaceDemonByLevel(lv);

        if (id >= 0)
        {
            *res = id;
            break;
        }
    }
    if (lv == 0x63)
        return sub_08158CA4();
    return sub_08158D08();
}

/* A demon and an element: the element shifts the demon within its race. */
// sub_08158FA4 @ 0x08158FA4
u32 sub_08158FA4(void)
{
    struct FusionCalc *c = &gUnk_0203B868;
    u8 id;
    u8 lv;
    u8 other;
    const u8 *olv;
    s32 sum;
    struct FusionCalc *w;

    if (c->race[0] <= 0x1A)
    {
        id = c->ids[0];
        lv = c->level[0];
        other = c->ids[1];
        olv = &c->level[1];
    }
    else if (c->race[1] > 0x1A)
    {
        return sub_08159098();
    }
    else
    {
        id = c->ids[1];
        lv = c->level[1];
        other = c->ids[0];
        olv = &c->level[0];
    }
    w = &gUnk_0203B868;
    if (*olv > lv)
    {
        if ((w->level[0] + w->level[1]) & 1)
            return sub_08158CA4();
        Fusion_RankDown(other, 1);
        return sub_08158D08();
    }
    w->result = id;
    sum = w->level[0] + w->level[1];
    if (sum % 7 == 0)
    {
        Fusion_RankDown(w->result, 2);
        return sub_08158D08();
    }
    if (sum % 5 == 0)
    {
        Fusion_RankDown(w->result, 1);
        return sub_08158D08();
    }
    if (sum % 3 == 0)
    {
        Fusion_RankUp(w->result, 1);
        return sub_08158D08();
    }
    if (sum & 1)
        return sub_08158CA4();
    Fusion_RankDown(other, 1);
    return sub_08158D08();
}

// sub_08159098 @ 0x08159098
u32 sub_08159098(void)
{
    struct FusionCalc *c = &gUnk_0203B868;

    Fusion_RankDown(c->level[0] >= c->level[1] ? c->ids[0] : c->ids[1], 1);
    return sub_08158D08();
}

/* Two materials of the same alignment. */
// sub_081590CC @ 0x081590CC
u32 sub_081590CC(void)
{
    struct FusionCalc *c = &gUnk_0203B868;
    s32 lv;

    if (c->race[0] > 0x1A || c->race[1] > 0x1A)
        return sub_08158FA4();
    c->unkA3 = c->align[0];
    for (lv = ((c->level[0] + c->level[1]) >> 1) + 3; lv <= 0x62; lv++)
    {
        if (sub_081594B4(lv) >= 0)
            return sub_08158D08();
    }
    Fusion_SetNoResult();
    gUnk_0203B868.unkA6 = 0x40;
    return 0;
}

/* Random demon id (0xFF -> 0xFB). */
// sub_08159144 @ 0x08159144
u32 sub_08159144(void)
{
    u32 r = Random_Byte() & 0xFF;

    if (r == 0xFF)
        r = 0xFB;
    return r;
}

/* Fusion with a dark (alignment 0xB) demon: a random demon of a given alignment below a
   level cap ("accident"-style result). */
// sub_0815915C @ 0x0815915C
u32 sub_0815915C(void)
{
    struct FusionCalc *c;
    s32 maxLv;
    u16 a;
    u16 b;
    u32 x;
    u32 want;
    s32 k;
    s32 j;

    gUnk_03006A38 = 1;
    c = &gUnk_0203B868;
    c->unkA4 |= 8;
    c->unkA6 = (c->unkA6 & 3) | 0x30;
    maxLv = (c->level[0] + c->level[1] + gGameState.members[0].level) / 3 + 4;
    if (c->align[0] == 0xB)
    {
        a = c->ids[0];
        b = c->ids[1];
    }
    else
    {
        a = c->ids[1];
        b = c->ids[0];
    }
    x = sub_0815B958(a) & 3;
    if (x != 0)
        x = 1;
    a = x * 3;
    k = (sub_0815B958(b) & 3) + a;
    want = gUnknown_087F160B[k] & 3;
    for (k = 0; k <= 0x1F; k++)
    {
        for (j = 0; j <= 999; j++)
        {
            x = sub_08159144();
            if (x != 0xFF)
            {
                gUnk_0203B868.result = x;
                if (sub_0815BA28(gUnk_0203B868.result) && gUnk_0203B868.result != gUnk_0203B868.ids[0]
                 && gUnk_0203B868.result != gUnk_0203B868.ids[1])
                    break;
            }
        }
        if ((u8)Demon_GetLevel(gUnk_0203B868.result) < maxLv
         && (sub_0815B958(gUnk_0203B868.result) & 3) == want
         && gUnk_0203B868.result != gUnk_0203B868.ids[0] && gUnk_0203B868.result != gUnk_0203B868.ids[1])
            return sub_08158D08();
    }
    return sub_08158CA4();
}

/* A demon and a race-8 material (table 0x087F1611): shifts the demon by rank or level. */
// sub_081592AC @ 0x081592AC
u32 sub_081592AC(void)
{
    struct FusionCalc *c = &gUnk_0203B868;
    u16 e;
    u32 d;
    u8 dr;
    const u8 *p;
    s32 v;
    s32 m;

    if (c->race[0] == 8)
    {
        e = c->ids[0];
        d = c->ids[1];
        dr = c->race[1];
    }
    else
    {
        e = c->ids[1];
        d = c->ids[0];
        dr = c->race[0];
    }
    v = (e - 0x32) >> 1;
    p = &gUnknown_087F1611[dr * 4 + v];
    if (*p == 0xFF)
    {
        Fusion_SetNoResult();
        gUnk_0203B868.unkA6 = 0x40;
        return 0;
    }
    v = *p;
    if (!(e & 1))
        v >>= 4;
    m = 3;
    m &= v;
    if (m)
    {
        Fusion_RankDown(d, v &= 3);
        gUnk_0203B868.unkA4 |= ++v;
        gUnk_0203B868.unkA6 = (gUnk_0203B868.unkA6 & 0xF0) | v;
    }
    else
    {
        Fusion_RankUp(d, (v &= 0xF) + 1);
        gUnk_0203B868.unkA4 |= 1;
        gUnk_0203B868.unkA6 = (gUnk_0203B868.unkA6 & 0xF0) | 1;
    }
    return sub_08158D08();
}

/* Two demons of different races and alignments: race table, then the first demon of that
   race at or above the mean level + 3. */
// sub_0815937C @ 0x0815937C
u32 sub_0815937C(void)
{
    const u8 *tbl = gUnknown_087F16BD;
    struct FusionCalc *c = &gUnk_0203B868;
    u32 row = c->race[0] * 0x1A;
    u8 race = tbl[row + c->race[1]];

    if (race == 0xFF)
    {
        Fusion_SetNoResult();
        c->unkA6 = 0x40;
        return 0;
    }
    c->resRace = race;
    c->level[0] = ((c->level[0] + c->level[1]) >> 1) + 3;
    while (Fusion_FindRaceDemonByLevel(c->level[0]) < 0)
        c->level[0]++;
    return sub_08158D08();
}

/* Fusion with demon 0xFB: the result is the other material, keeping its skills. */
// sub_081593EC @ 0x081593EC
u32 sub_081593EC(void)
{
    struct FusionCalc *c = &gUnk_0203B868;
    c->result = c->ids[0] & 0xFF;
    if (c->ids[0] == 0xFB)
        c->result = c->ids[1] & 0xFF;
    c->unkA5 = c->result;
    c->unkA4 |= 0x80;
    return sub_08158D08();
}

/* Demon of race gUnk_0203B868.resRace for level: the race's first demon if it is below level,
   else the one of exactly that level; -1 if none. */
// Fusion_FindRaceDemonByLevel @ 0x08159438
s16 Fusion_FindRaceDemonByLevel(u16 level)
{
    u32 n = gUnk_0203B868.resRace; /* the race, then the low byte of id */
    u16 end = gUnknown_087F1514[n];
    u16 id = gUnknown_087F1514[n - 1];

    if (n == 1 || n == 0x23)
        id++;
    n = id & 0xFF;
    if (Demon_GetRecord(n)->level >= level)
    {
        do
        {
            if (Demon_GetRecord(n)->level == level)
                break;
            id++;
            n = id & 0xFF;
        } while (id != end);
        if (id == end)
            return -1;
    }
    gUnk_0203B868.result = id & 0xFF;
    return gUnk_0203B868.result;
}

/* Same-alignment fusion: up to three candidate races (table 0x087F1961 by alignment). */
// sub_081594B4 @ 0x081594B4
#ifdef NONMATCHING
s16 sub_081594B4(u16 level)
{
    u32 n = 0;
    struct FusionCalc *c = &gUnk_0203B868;
    s32 k;
    s32 cnt;
    u16 lv;

    c->cand[0] = 0xFF;
    c->cand[1] = -1;
    c->cand[2] = -1;
    c->candLv[0] = -1;
    c->candLv[1] = -1;
    c->candLv[2] = -1;
    k = (u8)c->unkA3 * 3;
    cnt = 0;
    while (gUnknown_087F1961[k] != 0xFF)
    {
        c->resRace = gUnknown_087F1961[k];
        for (lv = level; lv <= 0x62; lv++)
        {
            s16 id = Fusion_FindRaceDemonByLevel(lv);

            if (id >= 0)
            {
                gUnk_0203B868.cand[n] = id;
                n++;
                break;
            }
        }
        k++;
        cnt++;
        c = &gUnk_0203B868;
        if (cnt > 2)
            break;
    }
    if (c->cand[0] == 0xFF)
        return -1;
    return sub_08159568(level);
}
#else
NAKED
s16 sub_081594B4(u16 level)
{
    asm_unified(
        ".L081594B4:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        "    movs r7, #0\n"
        "    ldr r2, .L08159518\n"
        "    movs r0, #0xff\n"
        "    strb r0, [r2]\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    strb r0, [r2, #1]\n"
        "    strb r0, [r2, #2]\n"
        "    strb r0, [r2, #0x10]\n"
        "    strb r0, [r2, #0x11]\n"
        "    strb r0, [r2, #0x12]\n"
        "    adds r0, r2, #0\n"
        "    adds r0, #0xa3\n"
        "    ldrb r1, [r0]\n"
        "    lsls r0, r1, #1\n"
        "    adds r3, r0, r1\n"
        "    movs r6, #0\n"
        "    ldr r1, .L0815951C\n"
        "    adds r0, r3, r1\n"
        "    ldrb r0, [r0]\n"
        "    adds r4, r1, #0\n"
        "    cmp r0, #0xff\n"
        "    beq .L0815953E\n"
        ".L081594EE:\n"
        "    adds r0, r3, r4\n"
        "    ldrb r1, [r0]\n"
        "    adds r0, r2, #0\n"
        "    adds r0, #0xa2\n"
        "    strb r1, [r0]\n"
        "    mov r4, r8\n"
        "    adds r5, r3, #1\n"
        "    adds r6, #1\n"
        ".L081594FE:\n"
        "    adds r0, r4, #0\n"
        "    bl Fusion_FindRaceDemonByLevel\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r1, r0, #0x10\n"
        "    cmp r1, #0\n"
        "    blt .L08159520\n"
        "    ldr r0, .L08159518\n"
        "    adds r0, r7, r0\n"
        "    strb r1, [r0]\n"
        "    adds r7, #1\n"
        "    b .L0815952A\n"
        "    .byte 0x00, 0x00\n"
        ".L08159518: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L0815951C: .4byte gUnknown_087F1961\n"
        ".L08159520:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #0x62\n"
        "    bls .L081594FE\n"
        ".L0815952A:\n"
        "    adds r3, r5, #0\n"
        "    ldr r2, .L08159550\n"
        "    cmp r6, #2\n"
        "    bgt .L0815953E\n"
        "    ldr r0, .L08159554\n"
        "    adds r1, r5, r0\n"
        "    ldrb r1, [r1]\n"
        "    adds r4, r0, #0\n"
        "    cmp r1, #0xff\n"
        "    bne .L081594EE\n"
        ".L0815953E:\n"
        "    ldrb r0, [r2]\n"
        "    cmp r0, #0xff\n"
        "    beq .L08159558\n"
        "    mov r0, r8\n"
        "    bl sub_08159568\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    b .L0815955C\n"
        ".L08159550: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L08159554: .4byte gUnknown_087F1961\n"
        ".L08159558:\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        ".L0815955C:\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

/* Sorts the candidates by level and takes the first at or above level. */
// sub_08159568 @ 0x08159568
#ifdef NONMATCHING
s16 sub_08159568(u16 level)
{
    struct FusionCalc *c = &gUnk_0203B868;
    struct FusionCalc *w;
    u32 i;

    c->candLv[0] = Demon_GetLevel(c->cand[0]);
    if (c->cand[1] != 0xFF)
    {
        c->candLv[1] = Demon_GetLevel(c->cand[1]);
        if (c->cand[2] != 0xFF)
            c->candLv[2] = Demon_GetLevel(c->cand[2]);
    }
    w = &gUnk_0203B868;
    if (w->candLv[1] < w->candLv[0])
        sub_08159604(1, 0);
    if (w->candLv[2] < w->candLv[1])
        sub_08159604(2, 1);
    if (w->candLv[1] < w->candLv[0])
        sub_08159604(1, 0);
    i = 0;
    if (w->candLv[0] < level && w->candLv[1] != 0xFF)
    {
        i = 1;
        if (w->candLv[1] < level && w->candLv[2] != 0xFF)
        {
            i = 2;
            if (w->candLv[2] < level)
                return -1;
        }
    }
    gUnk_0203B868.result = gUnk_0203B868.cand[i];
    return gUnk_0203B868.result;
}
#else
NAKED
s16 sub_08159568(u16 level)
{
    asm_unified(
        ".L08159568:\n"
        "    push {r4, r5, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    ldr r4, .L081595E8\n"
        "    ldrb r0, [r4]\n"
        "    bl Demon_GetLevel\n"
        "    strb r0, [r4, #0x10]\n"
        "    ldrb r0, [r4, #1]\n"
        "    cmp r0, #0xff\n"
        "    beq .L08159590\n"
        "    bl Demon_GetLevel\n"
        "    strb r0, [r4, #0x11]\n"
        "    ldrb r0, [r4, #2]\n"
        "    cmp r0, #0xff\n"
        "    beq .L08159590\n"
        "    bl Demon_GetLevel\n"
        "    strb r0, [r4, #0x12]\n"
        ".L08159590:\n"
        "    ldr r4, .L081595E8\n"
        "    ldrb r0, [r4, #0x11]\n"
        "    ldrb r1, [r4, #0x10]\n"
        "    cmp r0, r1\n"
        "    bhs .L081595A2\n"
        "    movs r0, #1\n"
        "    movs r1, #0\n"
        "    bl sub_08159604\n"
        ".L081595A2:\n"
        "    ldrb r0, [r4, #0x12]\n"
        "    ldrb r1, [r4, #0x11]\n"
        "    cmp r0, r1\n"
        "    bhs .L081595B2\n"
        "    movs r0, #2\n"
        "    movs r1, #1\n"
        "    bl sub_08159604\n"
        ".L081595B2:\n"
        "    ldrb r0, [r4, #0x11]\n"
        "    ldrb r1, [r4, #0x10]\n"
        "    cmp r0, r1\n"
        "    bhs .L081595C2\n"
        "    movs r0, #1\n"
        "    movs r1, #0\n"
        "    bl sub_08159604\n"
        ".L081595C2:\n"
        "    movs r1, #0\n"
        "    ldrb r0, [r4, #0x10]\n"
        "    cmp r0, r5\n"
        "    bhs .L081595EC\n"
        "    ldrb r0, [r4, #0x11]\n"
        "    cmp r0, #0xff\n"
        "    beq .L081595EC\n"
        "    movs r1, #1\n"
        "    cmp r0, r5\n"
        "    bhs .L081595EC\n"
        "    ldrb r0, [r4, #0x12]\n"
        "    cmp r0, #0xff\n"
        "    beq .L081595EC\n"
        "    movs r1, #2\n"
        "    cmp r0, r5\n"
        "    bhs .L081595EC\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    b .L081595FA\n"
        ".L081595E8: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L081595EC:\n"
        "    ldr r0, .L08159600\n"
        "    adds r1, r1, r0\n"
        "    adds r0, #0xa0\n"
        "    ldrb r1, [r1]\n"
        "    strh r1, [r0]\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        ".L081595FA:\n"
        "    pop {r4, r5}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        ".L08159600: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
    );
}
#endif

// sub_08159604 @ 0x08159604
void sub_08159604(u32 a, u32 b)
{
    struct FusionCalc *c = &gUnk_0203B868;
    u8 t;

    /* candLv[i] is addressed as cand[0x10 + i]: that is what matches */
    t = c->cand[b + 0x10];
    c->cand[b + 0x10] = c->cand[a + 0x10];
    c->cand[a + 0x10] = t;
    t = c->cand[b];
    c->cand[b] = c->cand[a];
    c->cand[a] = t;
}

/* Result = id moved down n ranks within its race (not past the race's first demon). */
// Fusion_RankDown @ 0x08159634
void Fusion_RankDown(u16 id, u16 n)
{
    struct FusionCalc *c = &gUnk_0203B868;
    u8 first;

    c->result = id & 0xFF;
    first = gUnknown_087F1514[Demon_GetRace(c->result) - 1];
    while (n != 0 && c->result != first)
    {
        c->result--;
        n--;
    }
}

/* Result = id moved up n ranks within its race. */
// Fusion_RankUp @ 0x08159690
void Fusion_RankUp(u16 id, u16 n)
{
    struct FusionCalc *c = &gUnk_0203B868;
    u8 last;

    c->result = id & 0xFF;
    last = gUnknown_087F1514[Demon_GetRace(c->result)] - 1;
    while (n != 0 && c->result != last)
    {
        c->result++;
        n--;
    }
}
