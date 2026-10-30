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
u32 sub_0815999C(void)
{
    struct FusionCalc *c = &gUnk_0203B868;
    struct FusionCalc *w;
    u8 t;
    u16 *p0;
    u16 *p1;
    u16 *p2;
    u16 a;
    u16 b;
    u16 d;

    if (c->race[0] == 8)
    {
        t = c->ids[2];
        c->ids[2] = c->ids[0];
        c->ids[0] = t;
        t = c->race[2];
        c->race[2] = c->race[0];
        c->race[0] = t;
    }
    else if (c->race[1] == 8)
    {
        t = c->ids[2];
        c->ids[2] = c->ids[1];
        c->ids[1] = t;
        t = c->race[2];
        c->race[2] = c->race[1];
        c->race[1] = t;
    }
    w = &gUnk_0203B868;
    p0 = &w->ids[0];
    a = *p0;
    p1 = &w->ids[1];
    b = *p1;
    p2 = &w->ids[2];
    d = *p2;
    sub_08158A34();
    *p0 = a;
    *p1 = b;
    *p2 = d;
    if (w->resRace != 0xFF)
    {
        Fusion_RankDown(w->result, 1);
        *p0 = w->result;
        *p1 = *p2;
        sub_08158A34();
        if (w->resRace != 0xFF)
            return sub_08158CBC();
    }
    return sub_08158E00();
}
