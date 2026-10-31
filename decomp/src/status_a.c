#include "global.h"
#include "status.h"

// sub_080C9100 @ 0x080C9100
/* Picks a special encounter: 0 for none, else 0x30-0x34. Unless flag 0xD8 is set, it runs
   once (flag 0xC4) and only when the moon phase differs from a randomly chosen phase (then
   with chance 1/8). Two of the eight random branches test phase 0; phase 0x40 is never
   chosen (probably a typo for 0x40 in the original). */
u32 sub_080C9100(void)
{
    u8 phase = Moon_GetPhase() & 0xF0;

    if (phase > 0x8F)
    {
        phase -= 0x80;
        phase = 0x80 - phase;
    }
    if (!Flag_Test(0xD8))
    {
        if (Flag_Test(0xC4))
            return 0;
        Flag_Set(0xC4);
        if ((Random_Byte() & 0xFF) > 0x7F)
        {
            if ((Random_Byte() & 0xFF) > 0x7F)
            {
                if ((Random_Byte() & 0xFF) > 0x7F)
                {
                    if (phase == 0)
                        return 0;
                }
                else if (phase == 0x10)
                    return 0;
            }
            else
            {
                if ((Random_Byte() & 0xFF) > 0x7F)
                {
                    if (phase == 0x20)
                        return 0;
                }
                else if (phase == 0x30)
                    return 0;
            }
        }
        else
        {
            if ((Random_Byte() & 0xFF) > 0x7F)
            {
                if ((Random_Byte() & 0xFF) > 0x7F)
                {
                    if (phase == 0)
                        return 0;
                }
                else if (phase == 0x50)
                    return 0;
            }
            else
            {
                if ((Random_Byte() & 0xFF) > 0x7F)
                {
                    if (phase == 0x60)
                        return 0;
                }
                else if (phase == 0x70)
                    return 0;
            }
        }
        if ((Random_Byte() & 0xFF) > 0x1F)
            return 0;
    }
    if ((Random_Byte() & 0xFF) > 0x7F)
    {
        if ((Random_Byte() & 0xFF) > 0x7F)
        {
            if ((Random_Byte() & 0xFF) > 0x7F)
                return 0x34;
            return 0x31;
        }
        if ((Random_Byte() & 0xFF) > 0x7F)
            return 0x32;
        return 0x33;
    }
    if (!Flag_Test(0xD8) && (Random_Byte() & 0xFF) <= 0x3F)
        return 0;
    return 0x30;
}

// sub_080C9210 @ 0x080C9210
const u16 *sub_080C9210(u16 kind)
{
    if (kind == 1)
        return gUnknown_084EEAE4;
    if (kind == 2)
        return gUnknown_084EEF28;
    if (kind == 3)
        return gUnknown_084EF368;
    return gUnknown_084EF7B0;
}

// sub_080C9248 @ 0x080C9248
/* Finds id in the (id, value) list of kind; NULL if absent. */
const u16 *sub_080C9248(u16 kind, u16 id)
{
    const u16 *p = sub_080C9210(kind);

    for (;;)
    {
        if (*p == 0xFFFF)
            return NULL;
        if (*p == id)
            return p;
        p += 2;
    }
}

// sub_080C9278 @ 0x080C9278
u16 sub_080C9278(u16 i)
{
    return gStatusList[i] & 0x7FFF;
}

// sub_080C9290 @ 0x080C9290
u16 sub_080C9290(u16 i)
{
    return gStatusList[i] & 0x8000;
}

// sub_080C92AC @ 0x080C92AC
u32 sub_080C92AC(u16 id)
{
    u32 r = 0;

    if ((u16)(id - 0x150) <= 0x19)
        r = 1;
    return r;
}

// Status_GetCombatant @ 0x080C92C8
/* The combatant of list entry i: a member, or (bit 15) a demon built in the menu state. */
struct Combatant *Status_GetCombatant(u16 i)
{
    struct C0c6Status *st = &gMenuState;

    if (sub_080C9290(i) == 0)
        return &gGameState.members[sub_080C9278(i)];
    Combatant_InitDemon(&st->demon, 4, sub_080C9278(st->sel));
    if (sub_080C92AC(st->demon.demonId) == 1)
    {
        u8 attr[8];
        u8 *p;

        Item_GetAttribute(Fusion_GetDemonByIndex(st->demon.demonId), 5, p = attr);
        st->demon.total[0] = attr[0];
        st->demon.total[1] = p[1];
        st->demon.total[2] = p[2];
        st->demon.total[3] = p[3];
        st->demon.total[4] = p[4];
        st->demon.total[5] = p[5];
        st->demon.base[0] = 0;
        st->demon.base[1] = 0;
        st->demon.base[2] = 0;
        st->demon.base[3] = 0;
        st->demon.base[4] = 0;
        st->demon.base[5] = 0;
    }
    return &st->demon;
}

// sub_080C9388 @ 0x080C9388
u32 sub_080C9388(u16 i)
{
    u32 r = 0;

    if (sub_080C9290(i) == 0 && sub_080C9278(i) <= 3)
        r = 1;
    return r;
}

// sub_080C93B4 @ 0x080C93B4
u32 sub_080C93B4(u16 i)
{
    u32 r = 0;

    if (sub_080C9290(i) == 0 && sub_080C9278(i) == 0)
        r = 1;
    return r;
}

// sub_080C93E0 @ 0x080C93E0
void sub_080C93E0(void)
{
    DmaCopy32(3, gUnk_0200F874, (void *)0x06014000, 0x1000);
}

// sub_080C9404 @ 0x080C9404
void sub_080C9404(void)
{
    Font_ResetGlyphSpriteCache(0x180);
}

// sub_080C9414 @ 0x080C9414
void sub_080C9414(void)
{
    struct C0c6Status *st = &gMenuState;

    if (st->mode == 5)
    {
        struct Combatant *c = Status_GetCombatant(st->sel);

        CpuSet(c, &st->demon, 0x04000020);
        c->equip[0] = 0xFF;
        c->equip[1] = 0xFF;
        c->equip[2] = 0xFF;
        c->equip[3] = 0xFF;
        c->equip[4] = 0xFF;
        c->equip[5] = 0xFF;
        c->equip[6] = 0xFF;
        c->pad27 = 0xFF;
        Combatant_RecalcStats(c->id);
        CpuSet(c, &st->preview, 0x04000020);
    }
}

// Status_BuildList @ 0x080C947C
/* Builds the list of combatants the status screen pages through (gStatusList; bit 15 marks
   a demon id) for the screen mode. */
void Status_BuildList(void)
{
    struct C0c6Status *st = &gMenuState;
    u16 *list = gStatusList;
    u16 n = 0;
    u16 n2 = 0;
    u16 i;
    u16 v;

    LZ77UnCompWram(gUnknown_081B5870, gUnk_0200F874);
    VBlankTask_AddCounted(sub_080C93E0, 1);
    switch (st->mode)
    {
    case 0:
        for (i = 0; i < 16; i++)
        {
            if (gGameState.members[i].unkE != 0)
            {
                list[n] = i;
                n++;
            }
        }
        st->count = n;
        break;
    case 1:
        for (i = 0; i <= 0xFF && (v = sub_0812ACCC(i)) != 0xFFFF; i++)
        {
            if (!Flag_Test(0xB6))
            {
                if (v & 0x8000)
                    continue;
                list[n] = v + 0x8000;
                n++;
                n2++;
            }
            else if (!(v & 0x8000))
            {
                list[n] = v + 0x8000;
                n++;
                n2++;
            }
            else
            {
                list[n] = v | 0x8000;
                n++;
            }
        }
        st->count = n;
        st->count2 = n2;
        break;
    case 3:
        for (i = 0; i < 4; i++)
        {
            if (gGameState.members[i].unkE != 0)
            {
                list[n] = i;
                n++;
            }
        }
        st->count = n;
        break;
    case 4:
    case 5:
        CpuSet(&gGameState.members[st->sel], &st->saved, 0x04000020);
        list[0] = st->sel;
        st->count = 1;
        st->sel = 0;
        sub_080C9414();
        break;
    case 6:
        list[0] = 0x8000 + gUnk_0203B854[3];
        st->count = 1;
        st->sel = 0;
        break;
    case 8:
    case 9:
    case 10:
        list[0] = 0x8000 + st->sel;
        st->count = 1;
        st->sel = 0;
        break;
    }
    st->unk10 = 0;
    if (sub_080C9388(st->sel) == 1)
        st->unk16 = 1;
    else
        st->unk16 = 0;
    st->unk18 = 1;
    st->unk1C = 0;
    st->unk1E = 0;
}

// sub_080C964C @ 0x080C964C
u32 sub_080C964C(u16 which)
{
    struct C0c6Status *st = &gMenuState;

    if (which == 0)
        return st->count;
    if (st->mode == 1)
        return st->count2;
    return st->count;
}

// sub_080C9670 @ 0x080C9670
void sub_080C9670(void)
{
    sub_0812CC70(0);
}

// sub_080C967C @ 0x080C967C
void sub_080C967C(void)
{
    sub_08128B84(1);
}

// sub_080C9688 @ 0x080C9688
void sub_080C9688(void)
{
    sub_08128B84(2);
}

// sub_080C9694 @ 0x080C9694
void sub_080C9694(void)
{
}

// sub_080C9698 @ 0x080C9698
void sub_080C9698(void)
{
    Field_SetState(0x19);
}

// sub_080C96A4 @ 0x080C96A4
void sub_080C96A4(void)
{
}

// sub_080C96A8 @ 0x080C96A8
/* Starts the fade-out to the screen the status screen returns to (by mode). */
void sub_080C96A8(void)
{
    struct C0c6Status *st = &gMenuState;

    switch (st->mode)
    {
    case 0:
        st->fade = sub_080B6B58(sub_080C9670, 0);
        break;
    case 1:
        st->fade = sub_080B6B58(sub_080C9688, 0);
        break;
    case 3:
        st->fade = sub_080B6B58(sub_080C967C, 0);
        break;
    case 4:
        st->fade = sub_080B6B58(sub_080EA178, 0);
        break;
    case 5:
        st->fade = sub_080B6B58(sub_080C9694, 0);
        break;
    case 6:
        st->fade = sub_080B6B58(sub_080C9698, 0);
        break;
    case 8:
    case 9:
    case 10:
        st->fade = sub_080B6B58(sub_080C9698, 0);
        break;
    case 11:
    case 12:
        st->fade = sub_080B6B58(sub_080C96A4, 0);
        break;
    }
}

// sub_080C9744 @ 0x080C9744
void sub_080C9744(struct Task *t)
{
    struct C0c6Status *st = &gMenuState;

    Status_GetCombatant(st->sel);
    if (st->fade->unkC == -1)
    {
        t->result = 1;
        if (sub_080C9388(st->sel) != 1)
        {
            gPaletteBuffer[0xD0] = 0x10;
            gPaletteBuffer[0xD1] = 0x10;
        }
    }
    else
        t->result = 0;
}

// sub_080C9794 @ 0x080C9794
void sub_080C9794(void)
{
    gMenuState.fade->unkC = 1;
}

// sub_080C97A4 @ 0x080C97A4
void sub_080C97A4(const u32 *src, u32 *dst)
{
    u32 i;

    for (i = 0; i < 24; i++)
        *dst++ = *src++;
}

// sub_080C97B8 @ 0x080C97B8
void sub_080C97B8(u32 frame)
{
    u32 off = frame * 96;
    const u8 *src = gUnknown_081B4F10;

    sub_080C97A4((const u32 *)(src + off), (u32 *)gUnk_0200FC74);
    src += 0x400;
    frame = (u32)(src + off);
    sub_080C97A4((const u32 *)frame, (u32 *)(gUnk_0200FC74 + 0x400));
}

// sub_080C97F0 @ 0x080C97F0
void sub_080C97F0(struct Task *t, u32 frame)
{
    if (gMenuState.unk22 != 1 && sub_080C964C(1) != 1)
    {
        sub_080C97B8(frame);
        sub_080C9994();
    }
}

// sub_080C981C @ 0x080C981C
void sub_080C981C(u32 frame)
{
    u32 off = frame * 96;
    const u8 *src = gUnknown_081B4FD0;

    sub_080C97A4((const u32 *)(src + off), (u32 *)gUnk_0200FFD4);
    src += 0x400;
    frame = (u32)(src + off);
    sub_080C97A4((const u32 *)frame, (u32 *)(gUnk_0200FFD4 + 0x400));
}

// sub_080C9854 @ 0x080C9854
void sub_080C9854(struct Task *t, u32 frame)
{
    if (gMenuState.unk22 != 1 && sub_080C964C(1) != 1)
    {
        sub_080C981C(frame);
        sub_080C9994();
    }
}

// sub_080C9880 @ 0x080C9880
/* Sets tile i of the BG tilemap at 0x06001000 to palette 1. */
void sub_080C9880(u16 i)
{
    u16 pal = 0x1000;
    u16 *map = (u16 *)0x06001000;

    map[i] = (map[i] & 0xFFF) | pal;
}

// sub_080C98A0 @ 0x080C98A0
void sub_080C98A0(void)
{
    REG_BG2CNT &= 0x3FFF;
    REG_BG2CNT |= 0x4000;
    REG_BG1CNT = 0x4205;
    gUnk_03000040 = 0x3844;
}

// sub_080C98E0 @ 0x080C98E0
void sub_080C98E0(void)
{
    struct C0c6Status *st = &gMenuState;

    sub_080C98A0();
    DmaCopy32(3, gUnknown_081B93B0, (void *)0x06001000, 0x800);
    DmaFill32(3, 0, (void *)0x06001800, 0x800);
    DmaCopy32(3, gUnk_0200F874, (void *)0x06004000, 0x7C00);
    sub_080C9880(0);
    sub_080C9880(1);
    sub_080C9880(2);
    sub_080C9880(0x20);
    sub_080C9880(0x21);
    sub_080C9880(0x22);
    sub_080C9880(0x1B);
    sub_080C9880(0x1C);
    sub_080C9880(0x1D);
    sub_080C9880(0x3B);
    sub_080C9880(0x3C);
    sub_080C9880(0x3D);
    st->unk0C = 0;
}

// sub_080C9994 @ 0x080C9994
void sub_080C9994(void)
{
    struct C0c6Status *st = &gMenuState;

    if (st->unk0C == 0)
    {
        VBlankTask_AddCounted(sub_080C98E0, 1);
        st->unk0C = 1;
    }
}

// sub_080C99B8 @ 0x080C99B8
/* Always 0 (both branches). */
u32 sub_080C99B8(struct Combatant *c)
{
    if (c->id == 0)
        return 0;
    return 0;
}
