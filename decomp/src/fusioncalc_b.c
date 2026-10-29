#include "global.h"
#include "fusion.h"

/* Three-demon fusion: sorts the materials, then the special table, race-8, element and
   dark-alignment rules. */
// Fusion_CalcThree @ 0x081596F0
u32 Fusion_CalcThree(void)
{
    struct FusionCalc *c = &gUnk_0203B868;
    u32 r;
    u16 t;

    c->orig[0] = c->ids[0];
    c->orig[1] = c->ids[1];
    c->orig[2] = c->ids[2];
    c->save[0] = c->orig[0];
    c->save[1] = c->orig[1];
    c->save[2] = c->orig[2];
    c->unkA4 = 0;
    c->unkA6 = 0;
    if (c->orig[0] > c->orig[1])
    {
        t = c->ids[0];
        c->ids[0] = c->orig[1];
        c->ids[1] = t;
    }
    if (c->ids[0] > c->ids[2])
    {
        t = c->ids[0];
        c->ids[0] = c->ids[2];
        c->ids[2] = t;
    }
    if (c->ids[1] > c->ids[2])
    {
        t = c->ids[1];
        c->ids[1] = c->ids[2];
        c->ids[2] = t;
    }
    if (!sub_0815B8F8(c->ids[0], 0) || !sub_0815B8F8(c->ids[1], 0) || !sub_0815B8F8(c->ids[2], 0))
    {
        r = sub_08158E00();
    }
    else
    {
        Demon_GetRaceAndAlign(c->ids[0], &c->align[0], &c->race[0]);
        Demon_GetRaceAndAlign(c->ids[1], &c->align[1], &c->race[1]);
        Demon_GetRaceAndAlign(c->ids[2], &c->align[2], &c->race[2]);
        c->level[0] = Demon_GetLevel(c->ids[0]);
        c->level[1] = Demon_GetLevel(c->ids[1]);
        c->level[2] = Demon_GetLevel(c->ids[2]);
        if (Fusion_FindSpecialTriple())
        {
            r = sub_08158D08();
        }
        else if (c->race[0] == 8 || c->race[1] == 8 || c->race[2] == 8)
        {
            gUnk_0203B868.unkA6 &= 3;
            r = sub_0815993C();
        }
        else if (c->race[0] > 0x1A)
        {
            c->unkA6 &= 3;
            r = Fusion_ThreeHighRaceFirst();
        }
        else if (c->race[1] > 0x1A)
        {
            c->unkA6 &= 3;
            r = Fusion_ThreeHighRaceMiddle();
        }
        else if (c->race[2] > 0x1A)
        {
            c->unkA6 &= 3;
            r = Fusion_ThreeHighRaceLast();
        }
        else if (gUnk_0203B868.align[0] == 0xB || gUnk_0203B868.align[1] == 0xB || gUnk_0203B868.align[2] == 0xB)
        {
            r = Fusion_ThreeDark();
        }
        else if (c->race[0] == 0x16 || c->race[1] == 0x16 || c->race[2] == 0x16)
        {
            r = Fusion_ThreeRace16();
        }
        else
        {
            c->unkA6 &= 3;
            r = Fusion_ThreeNormal();
        }
    }
    gUnk_0203B868.ids[0] = gUnk_0203B868.orig[0];
    gUnk_0203B868.ids[1] = gUnk_0203B868.orig[1];
    gUnk_0203B868.ids[2] = gUnk_0203B868.orig[2];
    if (gUnk_0203B868.result != 0xFF && (gUnk_0203B868.unkA6 & 0x30) != 0x30)
    {
        if ((u16)(gUnk_0203B868.result - 0x32) <= 7)
            gUnk_0203B868.unkA6 = (gUnk_0203B868.unkA6 & 3) | 0x10;
        if (gUnk_0203B868.resRace > 0x1A)
            gUnk_0203B868.unkA6 = (gUnk_0203B868.unkA6 & 3) | 0x20;
    }
    return r;
}

/* Three-way fusion with race-8 materials: dispatch on how many. */
// sub_0815993C @ 0x0815993C
u32 sub_0815993C(void)
{
    u8 n = 0;
    struct FusionCalc *c = &gUnk_0203B868;

    if (c->race[0] == 8)
        n = 1;
    if (c->race[1] == 8)
        n++;
    if (c->race[2] == 8)
        n++;
    switch (n)
    {
    case 1:
        return sub_0815999C();
    case 2:
        return Fusion_ThreeTwoRace8();
    case 3:
        return Fusion_ThreeRace8();
    }
}

/* One race-8 material: fuse the other two, shift the result down a rank, then fuse it with
   the third. */
// sub_0815999C @ 0x0815999C
#ifdef NONMATCHING
u32 sub_0815999C(void)
{
    struct FusionCalc *c = &gUnk_0203B868;
    u8 *rp;
    u8 race;
    u8 t;
    u16 *p0;
    u16 *p1;
    u16 *p2;
    u16 a;
    u16 b;
    u16 d;

    rp = &c->race[0];
    race = *rp;
    if (race == 8)
    {
        t = c->ids[2];
        c->ids[2] = c->ids[0];
        c->ids[0] = t;
        t = c->race[2];
        c->race[2] = race;
        *rp = t;
    }
    else
    {
        rp = &c->race[1];
        race = *rp;
        if (race == 8)
        {
            t = c->ids[2];
            c->ids[2] = c->ids[1];
            c->ids[1] = t;
            t = c->race[2];
            c->race[2] = race;
            *rp = t;
        }
    }
    p0 = &c->ids[0];
    a = *p0;
    p1 = &c->ids[1];
    b = *p1;
    p2 = &c->ids[2];
    d = *p2;
    sub_08158A34();
    *p0 = a;
    *p1 = b;
    *p2 = d;
    if (c->resRace != 0xFF)
    {
        Fusion_RankDown(c->result, 1);
        *p0 = c->result;
        *p1 = *p2;
        sub_08158A34();
        if (c->resRace != 0xFF)
            return sub_08158CBC();
    }
    return sub_08158E00();
}
#else
NAKED
u32 sub_0815999C(void)
{
    asm_unified(
        ".L0815999C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    ldr r0, .L081599CC\n"
        "    adds r5, r0, #0\n"
        "    adds r5, #0x96\n"
        "    ldrb r4, [r5]\n"
        "    adds r7, r0, #0\n"
        "    cmp r4, #8\n"
        "    bne .L081599D0\n"
        "    adds r2, r7, #0\n"
        "    adds r2, #0x94\n"
        "    ldrb r3, [r2]\n"
        "    adds r1, r7, #0\n"
        "    adds r1, #0x90\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r2]\n"
        "    strh r3, [r1]\n"
        "    adds r0, r7, #0\n"
        "    adds r0, #0x98\n"
        "    b .L081599EC\n"
        "    .byte 0x00, 0x00\n"
        ".L081599CC: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L081599D0:\n"
        "    adds r5, r7, #0\n"
        "    adds r5, #0x97\n"
        "    ldrb r4, [r5]\n"
        "    cmp r4, #8\n"
        "    bne .L081599F2\n"
        "    adds r0, r7, #0\n"
        "    adds r0, #0x94\n"
        "    ldrb r3, [r0]\n"
        "    adds r2, r7, #0\n"
        "    adds r2, #0x92\n"
        "    ldrh r1, [r2]\n"
        "    strh r1, [r0]\n"
        "    strh r3, [r2]\n"
        "    adds r0, #4\n"
        ".L081599EC:\n"
        "    ldrb r3, [r0]\n"
        "    strb r4, [r0]\n"
        "    strb r3, [r5]\n"
        ".L081599F2:\n"
        "    movs r0, #0x90\n"
        "    adds r0, r0, r7\n"
        "    mov sb, r0\n"
        "    ldrh r6, [r0]\n"
        "    movs r1, #0x92\n"
        "    adds r1, r1, r7\n"
        "    mov sl, r1\n"
        "    ldrh r5, [r1]\n"
        "    movs r0, #0x94\n"
        "    adds r0, r0, r7\n"
        "    mov r8, r0\n"
        "    ldrh r4, [r0]\n"
        "    bl sub_08158A34\n"
        "    mov r1, sb\n"
        "    strh r6, [r1]\n"
        "    mov r0, sl\n"
        "    strh r5, [r0]\n"
        "    mov r1, r8\n"
        "    strh r4, [r1]\n"
        "    adds r5, r7, #0\n"
        "    adds r5, #0xa2\n"
        "    ldrb r0, [r5]\n"
        "    cmp r0, #0xff\n"
        "    beq .L08159A4E\n"
        "    adds r4, r7, #0\n"
        "    adds r4, #0xa0\n"
        "    ldrh r0, [r4]\n"
        "    movs r1, #1\n"
        "    bl Fusion_RankDown\n"
        "    ldrh r0, [r4]\n"
        "    mov r1, sb\n"
        "    strh r0, [r1]\n"
        "    mov r1, r8\n"
        "    ldrh r0, [r1]\n"
        "    mov r1, sl\n"
        "    strh r0, [r1]\n"
        "    bl sub_08158A34\n"
        "    ldrb r0, [r5]\n"
        "    cmp r0, #0xff\n"
        "    beq .L08159A4E\n"
        "    bl sub_08158CBC\n"
        "    b .L08159A52\n"
        ".L08159A4E:\n"
        "    bl sub_08158E00\n"
        ".L08159A52:\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif
