#include "global.h"
#include "worldmap.h"

// sub_08153E24 @ 0x08153E24
u16 sub_08153E24(u16 id)
{
    struct FusionMenu *f = &sFusion;
    u16 i;

    for (i = 0; i < 12; i++)
    {
        if (f->members[i] != NULL && f->pairs[i][0] == id)
            return f->pairs[i][1];
    }
    return 0;
}

/* Number of living demons in the stock (combatants 4..15). */
// Stock_CountLiving @ 0x08153E70
u32 Stock_CountLiving(void)
{
    s32 n = 0;
    s32 i;

    for (i = 0; i < 12; i++)
    {
        if (Combatant_IsUsed(i + 4) && !Combatant_IsDead(i + 4))
            n++;
    }
    return n;
}

// Fusion_ClearList @ 0x08153E9C
void Fusion_ClearList(void)
{
    struct FusionMenu *f = &sFusion;
    u32 i;

    for (i = 0; i < 12; i++)
        f->members[i] = NULL;
}

// Fusion_BuildList @ 0x08153EB8
u16 Fusion_BuildList(void)
{
    struct FusionMenu *f = &sFusion;
    u16 n = 0;
    u16 i;

    for (i = 0; i < 12; i++)
    {
        if (Combatant_IsUsed(i + 4) && !Combatant_IsDead(i + 4))
        {
            f->members[n] = &gUnk_030048C0[i];
            n++;
        }
    }
    return n;
}

// sub_08153F08 @ 0x08153F08
void sub_08153F08(void)
{
    struct FusionMenu *f = &sFusion;
    u16 n;

    Fusion_ClearList();
    n = Fusion_BuildList();
    f->unk2 = 1;
    f->count = n;
    sub_0815B880(f->count);
    gUnk_03003BB4 = 0;
}

// Fusion_CountList @ 0x08153F3C
u16 Fusion_CountList(void)
{
    struct FusionMenu *f = &sFusion;
    u16 n = 0;
    u16 i;

    for (i = 0; i < 12; i++)
    {
        if (f->members[i] != NULL)
            n++;
    }
    return n;
}

// sub_08153F6C @ 0x08153F6C
void sub_08153F6C(u16 i)
{
    sFusion.picks[sFusion.sel] = sFusion.members[i];
}

// sub_08153F8C @ 0x08153F8C
void sub_08153F8C(u16 icon, u8 *dst, u16 x, u16 y, u8 tint)
{
    Canvas_BlitOrTinted(&gUnknown_087E0FE4[icon * 32], dst, 0, 0, x, y, 8, 8, tint);
}

// sub_08153FC8 @ 0x08153FC8
void sub_08153FC8(u16 glyph, u8 *dst, u16 x, u16 y, u8 tint)
{
    if (glyph == 0x1B)
        glyph = 0x101;
    if (glyph == 5)
    {
        glyph = 0x102;
        y += 2;
    }
    Canvas_BlitOrTinted(Font_GetGlyphBitmap(glyph + 0x200), dst, 2, 2, x + 2, y + 2, 14, 14, tint);
}

// sub_08154038 @ 0x08154038
void sub_08154038(u16 icon, u16 x, u16 y, u32 tint)
{
    sub_08153F8C(gUnknown_087E1BE4[icon], gUnk_0200F874, x, y, tint);
}

// Fusion_SortMaterials @ 0x08154074
void Fusion_SortMaterials(void)
{
    u16 t;

    if (gUnk_0203B868.ids[0] > gUnk_0203B868.ids[1])
    {
        t = gUnk_0203B868.ids[0];
        gUnk_0203B868.ids[0] = gUnk_0203B868.ids[1];
        gUnk_0203B868.ids[1] = t;
    }
    if (gUnk_0203B868.ids[0] > gUnk_0203B868.ids[2])
    {
        t = gUnk_0203B868.ids[0];
        gUnk_0203B868.ids[0] = gUnk_0203B868.ids[2];
        gUnk_0203B868.ids[2] = t;
    }
    if (gUnk_0203B868.ids[1] > gUnk_0203B868.ids[2])
    {
        t = gUnk_0203B868.ids[1];
        gUnk_0203B868.ids[1] = gUnk_0203B868.ids[2];
        gUnk_0203B868.ids[2] = t;
    }
}

/* Icon for fusing demon id with list slot: high nibble colour, low nibble mark. */
// Fusion_GetPairIcon @ 0x081540B8
u8 Fusion_GetPairIcon(u16 id, u16 slot)
{
    struct FusionMenu *f = &sFusion;
    struct Combatant *m = f->members[slot];
    u32 r;
    u32 good;
    u32 col;
    u32 done = 0;
    u32 mark;

    if (f->mode == 2)
    {
        gUnk_0203B868.ids[0] = id;
        gUnk_0203B868.ids[1] = m->demonId;
        gUnk_0203B868.ids[2] = 0xFFFF;
        good = Fusion_IsRandomResult();
        Fusion_CalcTwo();
        Fusion_CheckResult();
    }
    else if (f->mode == 3)
    {
        gUnk_0203B868.ids[0] = gUnk_0203B854[0];
        gUnk_0203B868.ids[1] = id;
        gUnk_0203B868.ids[2] = m->demonId;
        Fusion_SortMaterials();
        good = Fusion_IsRandomResult();
        Fusion_CalcThree();
        Fusion_CheckResult();
    }
    else if (f->mode == 1)
    {
        gUnk_0203B868.ids[0] = Fusion_GetDemonByIndex(id);
        gUnk_0203B868.ids[1] = 0xFFFF;
        gUnk_0203B868.ids[2] = gCombatants[slot + 4].demonId;
        r = Fusion_CalcItem();
        if (r != 0)
            return 0x10;
        return 0x16;
    }
    else if (f->mode == 4)
    {
        gUnk_0203B868.ids[0] = Fusion_GetDemonByIndex(id);
        gUnk_0203B868.ids[1] = Fusion_GetDemonByIndex(m->demonId);
        gUnk_0203B868.ids[2] = 0xFFFF;
        r = Fusion_CalcItem();
        if (id != m->demonId)
        {
            if (r != 0)
                return 0x10;
            return 0x16;
        }
    }
    else if (f->mode == 5)
    {
        gUnk_0203B868.ids[0] = Fusion_GetDemonByIndex(gUnk_0203B854[0]);
        gUnk_0203B868.ids[1] = Fusion_GetDemonByIndex(id);
        gUnk_0203B868.ids[2] = gCombatants[slot + 4].demonId;
        r = Fusion_CalcItem();
        if (r != 0)
            return 0x10;
        return 0x16;
    }

    if (id == m->demonId)
        return 0x18;
    if (gUnk_0203B868.unkA6 == 0x40 || gUnk_0203B868.result == 0xFF)
        return 0x16;
    if (good)
        gUnk_0203B868.unkA6 = 0x30;
    {
        s32 k = sub_0815B958(gUnk_0203B868.result);
        s32 kind = 0xFF;

        kind &= k;
        switch (kind)
        {
        case 0:
            col = 0;
            break;
        case 1:
            col = 0x10;
            break;
        case 2:
            col = 0x20;
            break;
        }
    }
    if (f->mode == 2)
    {
        switch (gUnk_0203B868.unkA6 & 0xF)
        {
        case 1:
            mark = 4;
            goto out;
        case 2:
            mark = 2;
            goto out;
        case 3:
            mark = 3;
            done = 1;
            break;
        }
    }
    if (!done)
    {
        switch (gUnk_0203B868.unkA6 >> 4)
        {
        case 1:
            mark = 1;
            goto out;
        case 2:
            mark = 7;
            goto out;
        case 3:
            mark = 5;
            col = 0x10;
            done = 1;
            break;
        }
        if (!done)
            mark = 0;
    }
out:
    return mark | col;
}

// Fusion_FindListSlot @ 0x0815430C
u16 Fusion_FindListSlot(u16 id)
{
    struct FusionMenu *f = &sFusion;
    u32 i;

    for (i = 0; i < 12; i++)
    {
        if (f->members[i] != NULL && f->members[i]->demonId == id)
            return i;
    }
    return 0;
}

// Stock_FindSlotByDemonId @ 0x08154344
u16 Stock_FindSlotByDemonId(u16 id)
{
    u32 i;

    /* gUnk_030048C0[i] is addressed through an integer: that keeps the loop from
       strength-reducing it, as in the original */
    for (i = 0; i < 12; i++)
    {
        if (Combatant_IsUsed(i + 4) && !Combatant_IsDead(i + 4)
            && ((struct Combatant *)((u32)gUnk_030048C0 + i * sizeof(struct Combatant)))->demonId == id)
            return i;
    }
    return 0;
}

// sub_0815438C @ 0x0815438C
void sub_0815438C(u16 id, u16 slot, u16 x, u16 y)
{
    s32 v = Fusion_GetPairIcon(id, slot);
    u32 icon = v & 0xF;
    u32 tint = 0;

    switch ((u8)v >> 4)
    {
    case 0:
        tint = 8;
        break;
    case 1:
        break;
    case 2:
        tint = 10;
        break;
    }
    if (icon == 6 || icon == 8 || icon == 5)
        tint = 0;
    sub_08154038(icon, x, y, tint);
}

// sub_081543E8 @ 0x081543E8
void sub_081543E8(struct FusionMenu *f, u16 sel, u16 y)
{
    u16 x = 0x96;
    u16 n = Fusion_CountList();
    u16 i;

    if (f->mode == 1 || (f->mode == 5 && f->sel == 1))
    {
        for (i = 0; i < 12; i++)
        {
            if (Combatant_IsUsed(i + 4) && !Combatant_IsDead(i + 4))
            {
                sub_0815438C(f->members[sel]->demonId, i, x, y);
                x += 6;
            }
        }
    }
    else
    {
        for (i = 0; i < n; i++, x += 6)
            sub_0815438C(f->members[sel]->demonId, Fusion_FindListSlot(f->members[i]->demonId), x, y);
    }
}

/* 1 when demon id can still be picked in the current fusion step. */
// sub_081544AC @ 0x081544AC
#ifdef NONMATCHING
u32 sub_081544AC(u16 id)
{
    struct FusionMenu *f;
    u16 n;
    u16 i;
    u8 v;

    n = Fusion_CountList();
    f = &sFusion;
    if (f->mode == 2 && f->sel == 0)
    {
        for (i = 0; i < n; i++)
        {
            v = Fusion_GetPairIcon(id, i);
            if ((v & 0xF) != 6 && (v & 0xF) != 8)
                return 1;
        }
        return 0;
    }
    if (f->mode == 3 && f->sel == 1)
    {
        for (i = 0; i < n; i++)
        {
            v = Fusion_GetPairIcon(id, Fusion_FindListSlot(f->members[i]->demonId));
            if ((v & 0xF) != 6 && (v & 0xF) != 8)
                return 1;
        }
        return 0;
    }
    if (f->mode == 3 && f->sel == 0)
        return 1;
    if (f->mode == 2 && f->sel == 1)
    {
        v = Fusion_GetPairIcon(f->picks[0]->demonId, Fusion_FindListSlot(id));
        if ((v & 0xF) == 6 || (v & 0xF) == 8)
            return 0;
        return 1;
    }
    if (f->mode == 3 && f->sel == 2)
    {
        v = Fusion_GetPairIcon(f->picks[1]->demonId, Fusion_FindListSlot(id));
        if ((v & 0xF) == 6 || (v & 0xF) == 8)
            return 0;
        return 1;
    }
    if (f->mode == 4 && f->sel == 1)
    {
        v = Fusion_GetPairIcon(gUnk_0203B854[0], Fusion_FindListSlot(id));
        if ((v & 0xF) == 6 || (v & 0xF) == 8)
            return 0;
        return 1;
    }
    if (f->mode == 1 && f->sel == 1)
    {
        v = Fusion_GetPairIcon(gUnk_0203B854[0], Stock_FindSlotByDemonId(id));
        if ((v & 0xF) == 6 || (v & 0xF) == 8)
            return 0;
        return 1;
    }
    if (f->mode == 5 && f->sel == 2)
    {
        gUnk_0203B868.ids[0] = Fusion_GetDemonByIndex(gUnk_0203B854[0]);
        gUnk_0203B868.ids[1] = Fusion_GetDemonByIndex(gUnk_0203B854[1]);
        gUnk_0203B868.ids[2] = id;
        if (Fusion_CalcItem() == 0)
            return 0;
    }
    return 1;
}
#else
NAKED
u32 sub_081544AC(u16 id)
{
    asm_unified(
        ".L081544AC:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    bl Fusion_CountList\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    ldr r5, .L081544F8\n"
        "    ldrh r0, [r5]\n"
        "    cmp r0, #2\n"
        "    bne .L081544FC\n"
        "    ldrh r0, [r5, #8]\n"
        "    cmp r0, #0\n"
        "    bne .L081544FC\n"
        "    movs r4, #0\n"
        "    cmp r4, r7\n"
        "    blo .L081544D0\n"
        "    b .L08154678\n"
        ".L081544D0:\n"
        "    adds r0, r6, #0\n"
        "    adds r1, r4, #0\n"
        "    bl Fusion_GetPairIcon\n"
        "    lsls r0, r0, #0x18\n"
        "    movs r1, #0xf0\n"
        "    lsls r1, r1, #0x14\n"
        "    ands r1, r0\n"
        "    lsrs r1, r1, #0x18\n"
        "    cmp r1, #6\n"
        "    beq .L081544EC\n"
        "    cmp r1, #8\n"
        "    beq .L081544EC\n"
        "    b .L08154684\n"
        ".L081544EC:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, r7\n"
        "    blo .L081544D0\n"
        "    b .L08154678\n"
        ".L081544F8: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L081544FC:\n"
        "    ldrh r0, [r5]\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #3\n"
        "    bne .L08154554\n"
        "    ldrh r0, [r5, #8]\n"
        "    cmp r0, #1\n"
        "    bne .L0815454E\n"
        "    movs r4, #0\n"
        "    cmp r4, r7\n"
        "    blo .L08154512\n"
        "    b .L08154678\n"
        ".L08154512:\n"
        "    lsls r1, r4, #2\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x1c\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    ldrh r0, [r0, #0x12]\n"
        "    bl Fusion_FindListSlot\n"
        "    adds r1, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    adds r0, r6, #0\n"
        "    bl Fusion_GetPairIcon\n"
        "    lsls r0, r0, #0x18\n"
        "    movs r1, #0xf0\n"
        "    lsls r1, r1, #0x14\n"
        "    ands r1, r0\n"
        "    lsrs r1, r1, #0x18\n"
        "    cmp r1, #6\n"
        "    beq .L08154542\n"
        "    cmp r1, #8\n"
        "    beq .L08154542\n"
        "    b .L08154684\n"
        ".L08154542:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, r7\n"
        "    blo .L08154512\n"
        "    b .L08154678\n"
        ".L0815454E:\n"
        "    cmp r0, #0\n"
        "    bne .L08154554\n"
        "    b .L08154684\n"
        ".L08154554:\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #2\n"
        "    bne .L0815458E\n"
        "    ldrh r0, [r5, #8]\n"
        "    cmp r0, #1\n"
        "    bne .L0815458E\n"
        "    ldr r0, [r5, #0x4c]\n"
        "    ldrh r4, [r0, #0x12]\n"
        "    adds r0, r6, #0\n"
        "    bl Fusion_FindListSlot\n"
        "    adds r1, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Fusion_GetPairIcon\n"
        "    lsls r0, r0, #0x18\n"
        "    movs r1, #0xf0\n"
        "    lsls r1, r1, #0x14\n"
        "    ands r1, r0\n"
        "    lsrs r1, r1, #0x18\n"
        "    cmp r1, #6\n"
        "    beq .L08154678\n"
        "    cmp r1, #8\n"
        "    beq .L0815458C\n"
        "    b .L08154684\n"
        ".L0815458C:\n"
        "    b .L08154678\n"
        ".L0815458E:\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #3\n"
        "    bne .L081545C6\n"
        "    ldrh r0, [r5, #8]\n"
        "    cmp r0, #2\n"
        "    bne .L081545C6\n"
        "    ldr r0, [r5, #0x50]\n"
        "    ldrh r4, [r0, #0x12]\n"
        "    adds r0, r6, #0\n"
        "    bl Fusion_FindListSlot\n"
        "    adds r1, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Fusion_GetPairIcon\n"
        "    lsls r0, r0, #0x18\n"
        "    movs r1, #0xf0\n"
        "    lsls r1, r1, #0x14\n"
        "    ands r1, r0\n"
        "    lsrs r1, r1, #0x18\n"
        "    cmp r1, #6\n"
        "    beq .L08154678\n"
        "    cmp r1, #8\n"
        "    bne .L08154684\n"
        "    b .L08154678\n"
        ".L081545C6:\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #4\n"
        "    bne .L08154604\n"
        "    ldrh r0, [r5, #8]\n"
        "    cmp r0, #1\n"
        "    bne .L08154604\n"
        "    ldr r0, .L08154600\n"
        "    ldrh r4, [r0]\n"
        "    adds r0, r6, #0\n"
        "    bl Fusion_FindListSlot\n"
        "    adds r1, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Fusion_GetPairIcon\n"
        "    lsls r0, r0, #0x18\n"
        "    movs r1, #0xf0\n"
        "    lsls r1, r1, #0x14\n"
        "    ands r1, r0\n"
        "    lsrs r1, r1, #0x18\n"
        "    cmp r1, #6\n"
        "    beq .L08154678\n"
        "    cmp r1, #8\n"
        "    bne .L08154684\n"
        "    b .L08154678\n"
        "    .byte 0x00, 0x00\n"
        ".L08154600: .4byte 0x0203B854 @ EWRAM+0x3B854\n"
        ".L08154604:\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bne .L08154640\n"
        "    ldrh r0, [r5, #8]\n"
        "    cmp r0, #1\n"
        "    bne .L08154640\n"
        "    ldr r0, .L0815463C\n"
        "    ldrh r4, [r0]\n"
        "    adds r0, r6, #0\n"
        "    bl Stock_FindSlotByDemonId\n"
        "    adds r1, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Fusion_GetPairIcon\n"
        "    lsls r0, r0, #0x18\n"
        "    movs r1, #0xf0\n"
        "    lsls r1, r1, #0x14\n"
        "    ands r1, r0\n"
        "    lsrs r1, r1, #0x18\n"
        "    cmp r1, #6\n"
        "    beq .L08154678\n"
        "    cmp r1, #8\n"
        "    bne .L08154684\n"
        "    b .L08154678\n"
        ".L0815463C: .4byte 0x0203B854 @ EWRAM+0x3B854\n"
        ".L08154640:\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #5\n"
        "    bne .L08154684\n"
        "    ldrh r0, [r5, #8]\n"
        "    cmp r0, #2\n"
        "    bne .L08154684\n"
        "    ldr r4, .L0815467C\n"
        "    ldrh r0, [r4]\n"
        "    bl Fusion_GetDemonByIndex\n"
        "    ldr r5, .L08154680\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x90\n"
        "    strh r0, [r1]\n"
        "    ldrh r0, [r4, #2]\n"
        "    bl Fusion_GetDemonByIndex\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x92\n"
        "    strh r0, [r1]\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x94\n"
        "    strh r6, [r0]\n"
        "    bl Fusion_CalcItem\n"
        "    cmp r0, #0\n"
        "    bne .L08154684\n"
        ".L08154678:\n"
        "    movs r0, #0\n"
        "    b .L08154686\n"
        ".L0815467C: .4byte 0x0203B854 @ EWRAM+0x3B854\n"
        ".L08154680: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L08154684:\n"
        "    movs r0, #1\n"
        ".L08154686:\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

// sub_0815468C @ 0x0815468C
void sub_0815468C(void)
{
    Field_SetState(0x19);
}

// sub_08154698 @ 0x08154698
void sub_08154698(void)
{
    struct FusionMenu *f = &sFusion;
    f->fade = sub_080B6B58(sub_0815468C, 0);
}

// sub_081546B4 @ 0x081546B4
void sub_081546B4(struct Task *task)
{
    if (sFusion.fade->state == -1)
        task->result = 1;
    else
        task->result = 0;
}

// sub_081546D8 @ 0x081546D8
void sub_081546D8(void)
{
    sFusion.fade->state = 1;
}

/* 1 when all three demons are of race >= 27. */
// Fusion_AllHighRace @ 0x081546E8
u32 Fusion_AllHighRace(u16 a, u16 b, u16 c)
{
    Party_GetMember(0x8000);
    if (*Demon_GetRecord(a) > 26 && *Demon_GetRecord(b) > 26 && *Demon_GetRecord(c) > 26)
        return 1;
    return 0;
}

/* 1 when the hero's level allows fusing demon id (level + 9 for three-way fusions of
   race >= 27); also when the result is already in the stock or one of the materials. */
// Fusion_CanCreate @ 0x0815473C
u32 Fusion_CanCreate(u16 a, u16 b, u16 c, u16 id)
{
    struct Combatant *hero = Party_GetMember(0x8000);
    struct FusionMenu *f = &sFusion;

    if ((Stock_FindByDemonId(id) != NULL && a != id && b != id && c != id) || sub_08134C3C(id) == 1)
        goto fail;
    if (f->mode == 3 && Fusion_AllHighRace(a, b, c) == 1)
    {
        if (hero->level + 9 >= (u8)Demon_GetRecord(id)[1])
            goto ok;
    fail:
        return 0;
    }
    if (hero->level < (u8)Demon_GetRecord(id)[1])
        goto fail;
ok:
    return 1;
}

/* Draws the demon's name (8 glyphs) and, after the first glyph, its level. */
/* Draws the demon's name (up to 8 glyphs, 10 px apart) and, after the first glyph, its level. */
// Fusion_DrawDemonName @ 0x081547D8
#ifdef NONMATCHING
void Fusion_DrawDemonName(u16 id, u16 x, u16 y, u16 tint)
{
    s8 *rec = Demon_GetRecord(id);
    u16 *name;
    u16 i;

    Race_GetName(rec[0]);
    i = 0;
    name = (u16 *)(rec + 0x22);
    for (; i < 8 && name[i] != 0; i++)
    {
        if (id == 0xFF)
            continue;
        if (rec[0] != 0x2C)
        {
            sub_08153FC8(name[i], gUnk_0200F874, i * 10 + x, y, tint);
            if (i == 0)
                Fusion_DrawLevel((u8)rec[1], 0xE0, y + 5, tint);
        }
        else if (id == 0x150 || id == 0x155 || id == 0x168 || id == 0x169)
            sub_08153FC8(((u16 *)(rec + 0x22))[i], gUnk_0200F874, i * 10 + x, y - 1, tint);
        else
            Font_DrawGlyphTinted(((u16 *)(rec + 0x22))[i], gUnk_0200F874, i * 12 + x + 4, y, tint);
    }
}
#else
NAKED
void Fusion_DrawDemonName(u16 id, u16 x, u16 y, u16 tint)
{
    asm_unified(
        ".L081547D8:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #8\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    mov sb, r1\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r7, r2, #0x10\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    mov sl, r3\n"
        "    adds r0, r6, #0\n"
        "    bl Demon_GetRecord\n"
        "    adds r5, r0, #0\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r5, r0]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Race_GetName\n"
        "    movs r4, #0\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x22\n"
        "    ldrh r0, [r5, #0x22]\n"
        "    cmp r0, #0\n"
        "    beq .L081548EA\n"
        "    mov r2, sl\n"
        "    lsls r0, r2, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    mov r8, r0\n"
        "    adds r0, r7, #5\n"
        "    lsls r0, r0, #0x10\n"
        "    str r0, [sp, #4]\n"
        ".L08154826:\n"
        "    cmp r6, #0xff\n"
        "    beq .L081548D2\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r5, r0]\n"
        "    cmp r0, #0x2c\n"
        "    beq .L08154868\n"
        "    lsls r0, r4, #1\n"
        "    adds r0, r1, r0\n"
        "    ldrh r0, [r0]\n"
        "    lsls r2, r4, #2\n"
        "    adds r2, r2, r4\n"
        "    lsls r2, r2, #1\n"
        "    add r2, sb\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    mov r3, r8\n"
        "    str r3, [sp]\n"
        "    ldr r1, .L08154864\n"
        "    adds r3, r7, #0\n"
        "    bl sub_08153FC8\n"
        "    cmp r4, #0\n"
        "    bne .L081548D2\n"
        "    ldrb r0, [r5, #1]\n"
        "    movs r1, #0xe0\n"
        "    ldr r3, [sp, #4]\n"
        "    lsrs r2, r3, #0x10\n"
        "    mov r3, sl\n"
        "    bl Fusion_DrawLevel\n"
        "    b .L081548D2\n"
        ".L08154864: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L08154868:\n"
        "    movs r0, #0xa8\n"
        "    lsls r0, r0, #1\n"
        "    cmp r6, r0\n"
        "    beq .L08154882\n"
        "    adds r0, #5\n"
        "    cmp r6, r0\n"
        "    beq .L08154882\n"
        "    adds r0, #0x13\n"
        "    cmp r6, r0\n"
        "    beq .L08154882\n"
        "    adds r0, #1\n"
        "    cmp r6, r0\n"
        "    bne .L081548B0\n"
        ".L08154882:\n"
        "    lsls r1, r4, #1\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x22\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    lsls r2, r4, #2\n"
        "    adds r2, r2, r4\n"
        "    lsls r2, r2, #1\n"
        "    add r2, sb\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    subs r3, r7, #1\n"
        "    lsls r3, r3, #0x10\n"
        "    mov r1, r8\n"
        "    str r1, [sp]\n"
        "    ldr r1, .L081548AC\n"
        "    lsrs r3, r3, #0x10\n"
        "    bl sub_08153FC8\n"
        "    b .L081548D2\n"
        "    .byte 0x00, 0x00\n"
        ".L081548AC: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L081548B0:\n"
        "    lsls r2, r4, #1\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x22\n"
        "    adds r0, r0, r2\n"
        "    ldrh r0, [r0]\n"
        "    adds r2, r2, r4\n"
        "    lsls r2, r2, #2\n"
        "    add r2, sb\n"
        "    adds r2, #4\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    mov r3, r8\n"
        "    str r3, [sp]\n"
        "    ldr r1, .L081548FC\n"
        "    adds r3, r7, #0\n"
        "    bl Font_DrawGlyphTinted\n"
        ".L081548D2:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #7\n"
        "    bhi .L081548EA\n"
        "    lsls r0, r4, #1\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x22\n"
        "    adds r0, r1, r0\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L08154826\n"
        ".L081548EA:\n"
        "    add sp, #8\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L081548FC: .4byte 0x0200F874 @ EWRAM+0xF874\n"
    );
}
#endif

// sub_08154900 @ 0x08154900
void sub_08154900(u16 x, u16 y)
{
    u16 i;

    for (i = 0; i < 8; i++)
        Font_DrawGlyphTinted(8, gUnk_0200F874, x + i * 8 + 3, y + 2, 0);
    for (i = 0; i < 2; i++)
        Font_DrawGlyphTinted(8, gUnk_0200F874, x + i * 8 + 0x55, y + 2, 0);
}

// Fusion_GetDemonByIndex @ 0x08154968
u32 Fusion_GetDemonByIndex(u16 id)
{
    return gUnknown_087E1BF6[id - 0x150];
}

// Fusion_GetIndexByDemon @ 0x08154980
u16 Fusion_GetIndexByDemon(u16 id)
{
    u16 i = 0;

    while (1)
    {
        if (gUnknown_087E1BF6[i] == 0xFFFF)
            return 0xFFFF;
        if (gUnknown_087E1BF6[i] == id)
            return i + 0x150;
        i++;
    }
}

/* Level number in the digit font; one-digit levels are shifted right by 8. */
// Fusion_DrawLevel @ 0x081549BC
void Fusion_DrawLevel(u16 n, u16 x, u16 y, u16 tint)
{
    u8 buf[4];

    NumberToDigits(n);
    if (n > 9)
    {
        buf[0] = gDigits[1] + '0';
        buf[1] = gDigits[0] + '0';
        buf[2] = 0;
    }
    else
    {
        buf[0] = gDigits[0] + '0';
        buf[1] = 0;
        x += 8;
    }
    DigitFont_DrawStringTinted(buf, gUnk_0200F874, x, y, tint, 8);
}

/* One row of the fusion list: race (3 glyphs), name (8 glyphs), level and the result
   preview for the current step. */
// Fusion_DrawListRow @ 0x08154A38
#ifdef NONMATCHING
void Fusion_DrawListRow(struct FusionMenu *f, u16 row, u16 y)
{
    struct Combatant *m = f->members[row];
    s8 *rec;
    const u16 *race;
    u16 *name;
    u8 tint = 0;
    u16 i;
    u16 lv;
    u16 out[6];

    if (m == NULL)
        return;
    rec = Demon_GetRecord(m->demonId);
    race = Race_GetName(rec[0]);
    if (!sub_081544AC(m->demonId))
        tint = 2;
    Canvas_BlitOrTinted(&gUnknown_087E13E4[row * 32], gUnk_0200F874, 0, 3, 0, y, 8, 13, 4);
    for (i = 0; i < 3; i++)
        Font_DrawGlyphTinted(race[i], gUnk_0200F874, i * 12 + 10, y, tint);
    name = (u16 *)(rec + 0x22);
    for (i = 0; i < 8 && name[i] != 0; i++)
    {
        if (rec[0] != 0x2C)
            sub_08153FC8(name[i], gUnk_0200F874, i * 10 + 0x2C, y - 2, tint);
        else if (sub_0815BAC4(m->demonId) == 1)
            Font_DrawGlyphTinted(name[i], gUnk_0200F874, i * 12 + 0x30, y, tint);
        else
            Font_DrawGlyphTinted(name[i], gUnk_0200F874, i * 12 + 0x30, y, 4);
    }

    if (((f->mode == 1 || f->mode == 4 || f->mode == 5) && (f->sel == 0 || (f->mode == 5 && f->sel == 1)))
        || (f->mode == 2 && f->sel == 0) || (f->mode == 3 && f->sel != 2))
    {
        if (rec[0] == 0x2C)
        {
            lv = Inventory_GetCount(Fusion_GetDemonByIndex(m->demonId));
            Font_DrawGlyphTinted(0x115, gUnk_0200F874, 0x76, y, 0);
        }
        else
            lv = (u8)rec[1];
        Fusion_DrawLevel(lv, 0x82, y + 3, 0);
    }

    switch (f->mode)
    {
    case 1:
        if (f->sel == 0)
            break;
        sub_0815B884(gUnk_0203B854[0], 0xFFFF, m->demonId, &out[0]);
        gUnk_0203B854[3] = out[0];
        Fusion_DrawDemonName(out[0], 0x7C, y, 0);
        if (out[0] == 0xFF)
            return;
        Font_DrawGlyphTinted(0x115, gUnk_0200F874, 0xCE, y, 0);
        Fusion_DrawLevel(Inventory_GetCount(out[1]), 0xDA, y + 3, 0);
        return;
    case 4:
        if (f->sel == 0)
            break;
        sub_0815B884(gUnk_0203B854[0], m->demonId, 0xFFFF, &out[2]);
        gUnk_0203B854[3] = out[2];
        Fusion_DrawDemonName(out[2], 0x7C, y, 0);
        if (out[2] == 0xFF)
            return;
        Font_DrawGlyphTinted(0x115, gUnk_0200F874, 0xCE, y, 0);
        Fusion_DrawLevel(Inventory_GetCount(out[3]), 0xDA, y + 3, 0);
        return;
    case 5:
        if (f->sel == 1)
            break;
        if (f->sel != 2)
            return;
        sub_0815B884(gUnk_0203B854[1], m->demonId, m->demonId, &out[4]);
        gUnk_0203B854[3] = out[4];
        Fusion_DrawDemonName(out[4], 0x7C, y, 0);
        if (out[4] == 0xFF)
            return;
        Font_DrawGlyphTinted(0x115, gUnk_0200F874, 0xCE, y, 0);
        Fusion_DrawLevel(Inventory_GetCount(out[5]), 0xDA, y + 3, 0);
        return;
    case 2:
        if (f->sel == 0)
            break;
        gUnk_0203B868.ids[0] = f->picks[0]->demonId;
        gUnk_0203B868.ids[1] = m->demonId;
        gUnk_0203B868.ids[2] = 0xFFFF;
        Fusion_IsRandomResult();
        Fusion_CalcTwo();
        gUnk_0203B854[3] = gUnk_0203B868.result;
        sub_0815438C(f->picks[0]->demonId, Fusion_FindListSlot(m->demonId), 0x82, y + 4);
        if ((Fusion_GetPairIcon(f->picks[0]->demonId, Fusion_FindListSlot(m->demonId)) & 0xF) != 5)
        {
            Fusion_DrawDemonName(gUnk_0203B868.result, 0x8A, y - 2,
                         Fusion_CanCreate(f->picks[0]->demonId, m->demonId, m->demonId, gUnk_0203B868.result) ? 0 : 4);
            return;
        }
        sub_08154900(0x8A, y - 2);
        return;
    case 3:
        if (f->sel == 1)
            break;
        if (f->sel != 2)
            return;
        i = Fusion_FindListSlot(m->demonId);
        gUnk_0203B868.ids[0] = f->picks[0]->demonId;
        gUnk_0203B868.ids[1] = f->picks[1]->demonId;
        gUnk_0203B868.ids[2] = m->demonId;
        Fusion_SortMaterials();
        Fusion_IsRandomResult();
        Fusion_CalcThree();
        gUnk_0203B854[3] = gUnk_0203B868.result;
        if (gUnk_0203B868.result > 0xFE)
            gUnk_0203B854[3] = 0xFB;
        sub_0815438C(f->picks[1]->demonId, i, 0x82, y + 4);
        if ((Fusion_GetPairIcon(f->picks[1]->demonId, i) & 0xF) != 5)
        {
            Fusion_DrawDemonName(gUnk_0203B868.result, 0x8A, y - 2,
                         Fusion_CanCreate(f->picks[0]->demonId, f->picks[1]->demonId, m->demonId,
                                      gUnk_0203B868.result) ? 0 : 4);
            return;
        }
        sub_08154900(0x8A, y - 2);
        return;
    default:
        return;
    }
    sub_081543E8(f, row, y + 4);
}
#else
NAKED
void Fusion_DrawListRow(struct FusionMenu *f, u16 row, u16 y)
{
    asm_unified(
        ".L08154A38:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x30\n"
        "    adds r5, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #0x20]\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r7, r2, #0x10\n"
        "    lsls r1, r1, #2\n"
        "    adds r0, #0x1c\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov r8, r0\n"
        "    movs r6, #0\n"
        "    cmp r0, #0\n"
        "    bne .L08154A62\n"
        "    b .L08154EB0\n"
        ".L08154A62:\n"
        "    ldrh r0, [r0, #0x12]\n"
        "    bl Demon_GetRecord\n"
        "    mov sl, r0\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Race_GetName\n"
        "    str r0, [sp, #0x24]\n"
        "    mov r1, r8\n"
        "    ldrh r0, [r1, #0x12]\n"
        "    bl sub_081544AC\n"
        "    cmp r0, #0\n"
        "    bne .L08154A88\n"
        "    movs r6, #2\n"
        ".L08154A88:\n"
        "    ldr r2, [sp, #0x20]\n"
        "    lsls r0, r2, #5\n"
        "    ldr r1, .L08154B28\n"
        "    adds r0, r0, r1\n"
        "    ldr r1, .L08154B2C\n"
        "    movs r2, #0\n"
        "    str r2, [sp]\n"
        "    str r7, [sp, #4]\n"
        "    movs r2, #8\n"
        "    str r2, [sp, #8]\n"
        "    movs r2, #0xd\n"
        "    str r2, [sp, #0xc]\n"
        "    movs r2, #4\n"
        "    str r2, [sp, #0x10]\n"
        "    movs r2, #0\n"
        "    movs r3, #3\n"
        "    bl Canvas_BlitOrTinted\n"
        "    movs r4, #0\n"
        "    lsls r6, r6, #0x18\n"
        "    mov sb, r6\n"
        "    mov r3, sl\n"
        "    adds r3, #0x22\n"
        "    str r3, [sp, #0x2c]\n"
        ".L08154AB8:\n"
        "    lsls r2, r4, #1\n"
        "    ldr r6, [sp, #0x24]\n"
        "    adds r0, r2, r6\n"
        "    ldrh r0, [r0]\n"
        "    adds r2, r2, r4\n"
        "    lsls r2, r2, #0x12\n"
        "    movs r1, #0xa0\n"
        "    lsls r1, r1, #0xc\n"
        "    adds r2, r2, r1\n"
        "    lsrs r2, r2, #0x10\n"
        "    mov r3, sb\n"
        "    lsrs r1, r3, #0x18\n"
        "    str r1, [sp]\n"
        "    ldr r1, .L08154B2C\n"
        "    adds r3, r7, #0\n"
        "    bl Font_DrawGlyphTinted\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #2\n"
        "    bls .L08154AB8\n"
        "    movs r4, #0\n"
        "    ldr r1, [sp, #0x2c]\n"
        "    mov r6, sl\n"
        "    ldrh r0, [r6, #0x22]\n"
        "    cmp r0, #0\n"
        "    beq .L08154B9E\n"
        "    subs r0, r7, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    str r0, [sp, #0x28]\n"
        ".L08154AF6:\n"
        "    mov r2, sl\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r2, r0]\n"
        "    cmp r0, #0x2c\n"
        "    beq .L08154B30\n"
        "    lsls r0, r4, #1\n"
        "    adds r0, r1, r0\n"
        "    ldrh r0, [r0]\n"
        "    lsls r2, r4, #2\n"
        "    adds r2, r2, r4\n"
        "    lsls r2, r2, #0x11\n"
        "    movs r3, #0xb0\n"
        "    lsls r3, r3, #0xe\n"
        "    adds r2, r2, r3\n"
        "    lsrs r2, r2, #0x10\n"
        "    mov r6, sb\n"
        "    lsrs r1, r6, #0x18\n"
        "    str r1, [sp]\n"
        "    ldr r1, .L08154B2C\n"
        "    ldr r6, [sp, #0x28]\n"
        "    lsrs r3, r6, #0x10\n"
        "    bl sub_08153FC8\n"
        "    b .L08154B88\n"
        "    .byte 0x00, 0x00\n"
        ".L08154B28: .4byte gUnknown_087E13E4\n"
        ".L08154B2C: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L08154B30:\n"
        "    mov r1, r8\n"
        "    movs r2, #0x12\n"
        "    ldrsh r0, [r1, r2]\n"
        "    bl sub_0815BAC4\n"
        "    cmp r0, #1\n"
        "    bne .L08154B68\n"
        "    lsls r2, r4, #1\n"
        "    ldr r3, [sp, #0x2c]\n"
        "    adds r0, r3, r2\n"
        "    ldrh r0, [r0]\n"
        "    adds r2, r2, r4\n"
        "    lsls r2, r2, #0x12\n"
        "    movs r6, #0xc0\n"
        "    lsls r6, r6, #0xe\n"
        "    adds r2, r2, r6\n"
        "    lsrs r2, r2, #0x10\n"
        "    mov r3, sb\n"
        "    lsrs r1, r3, #0x18\n"
        "    str r1, [sp]\n"
        "    ldr r1, .L08154B64\n"
        "    adds r3, r7, #0\n"
        "    bl Font_DrawGlyphTinted\n"
        "    b .L08154B88\n"
        "    .byte 0x00, 0x00\n"
        ".L08154B64: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L08154B68:\n"
        "    lsls r2, r4, #1\n"
        "    ldr r6, [sp, #0x2c]\n"
        "    adds r0, r6, r2\n"
        "    ldrh r0, [r0]\n"
        "    adds r2, r2, r4\n"
        "    lsls r2, r2, #0x12\n"
        "    movs r1, #0xc0\n"
        "    lsls r1, r1, #0xe\n"
        "    adds r2, r2, r1\n"
        "    lsrs r2, r2, #0x10\n"
        "    movs r1, #4\n"
        "    str r1, [sp]\n"
        "    ldr r1, .L08154BE0\n"
        "    adds r3, r7, #0\n"
        "    bl Font_DrawGlyphTinted\n"
        ".L08154B88:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #7\n"
        "    bhi .L08154B9E\n"
        "    lsls r0, r4, #1\n"
        "    ldr r1, [sp, #0x2c]\n"
        "    adds r0, r1, r0\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L08154AF6\n"
        ".L08154B9E:\n"
        "    ldrh r0, [r5]\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #1\n"
        "    beq .L08154BAE\n"
        "    cmp r1, #4\n"
        "    beq .L08154BAE\n"
        "    cmp r1, #5\n"
        "    bne .L08154BBC\n"
        ".L08154BAE:\n"
        "    ldrh r1, [r5, #8]\n"
        "    cmp r1, #0\n"
        "    beq .L08154BD2\n"
        "    cmp r0, #5\n"
        "    bne .L08154BBC\n"
        "    cmp r1, #1\n"
        "    beq .L08154BD2\n"
        ".L08154BBC:\n"
        "    ldrh r1, [r5]\n"
        "    cmp r1, #2\n"
        "    bne .L08154BC8\n"
        "    ldrh r0, [r5, #8]\n"
        "    cmp r0, #0\n"
        "    beq .L08154BD2\n"
        ".L08154BC8:\n"
        "    cmp r1, #3\n"
        "    bne .L08154C18\n"
        "    ldrh r0, [r5, #8]\n"
        "    cmp r0, #2\n"
        "    beq .L08154C18\n"
        ".L08154BD2:\n"
        "    mov r2, sl\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r2, r0]\n"
        "    cmp r0, #0x2c\n"
        "    beq .L08154BE4\n"
        "    ldrb r4, [r2, #1]\n"
        "    b .L08154C08\n"
        ".L08154BE0: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L08154BE4:\n"
        "    mov r3, r8\n"
        "    ldrh r0, [r3, #0x12]\n"
        "    bl Fusion_GetDemonByIndex\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Inventory_GetCount\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    ldr r0, .L08154C70\n"
        "    ldr r1, .L08154C74\n"
        "    movs r2, #0\n"
        "    str r2, [sp]\n"
        "    movs r2, #0x76\n"
        "    adds r3, r7, #0\n"
        "    bl Font_DrawGlyphTinted\n"
        ".L08154C08:\n"
        "    adds r2, r7, #3\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0x82\n"
        "    movs r3, #0\n"
        "    bl Fusion_DrawLevel\n"
        ".L08154C18:\n"
        "    ldrh r0, [r5]\n"
        "    cmp r0, #1\n"
        "    bne .L08154C80\n"
        "    ldrh r0, [r5, #8]\n"
        "    cmp r0, #0\n"
        "    bne .L08154C26\n"
        "    b .L08154DE2\n"
        ".L08154C26:\n"
        "    ldr r4, .L08154C78\n"
        "    ldrh r0, [r4]\n"
        "    ldr r1, .L08154C7C\n"
        "    mov r6, r8\n"
        "    ldrh r2, [r6, #0x12]\n"
        "    mov r5, sp\n"
        "    adds r5, #0x16\n"
        "    str r5, [sp]\n"
        "    add r3, sp, #0x14\n"
        "    bl sub_0815B884\n"
        "    add r0, sp, #0x14\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r4, #6]\n"
        "    add r0, sp, #0x14\n"
        "    ldrh r0, [r0]\n"
        "    movs r1, #0x7c\n"
        "    adds r2, r7, #0\n"
        "    movs r3, #0\n"
        "    bl Fusion_DrawDemonName\n"
        "    add r0, sp, #0x14\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0xff\n"
        "    bne .L08154C5A\n"
        "    b .L08154EB0\n"
        ".L08154C5A:\n"
        "    ldr r0, .L08154C70\n"
        "    ldr r1, .L08154C74\n"
        "    movs r2, #0\n"
        "    str r2, [sp]\n"
        "    movs r2, #0xce\n"
        "    adds r3, r7, #0\n"
        "    bl Font_DrawGlyphTinted\n"
        "    ldrh r0, [r5]\n"
        "    b .L08154CFC\n"
        "    .byte 0x00, 0x00\n"
        ".L08154C70: .4byte 0x00000115\n"
        ".L08154C74: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L08154C78: .4byte 0x0203B854 @ EWRAM+0x3B854\n"
        ".L08154C7C: .4byte 0x0000FFFF\n"
        ".L08154C80:\n"
        "    cmp r0, #4\n"
        "    bne .L08154CA8\n"
        "    ldrh r0, [r5, #8]\n"
        "    cmp r0, #0\n"
        "    bne .L08154C8C\n"
        "    b .L08154DE2\n"
        ".L08154C8C:\n"
        "    ldr r5, .L08154CA0\n"
        "    ldrh r0, [r5]\n"
        "    mov r2, r8\n"
        "    ldrh r1, [r2, #0x12]\n"
        "    ldr r2, .L08154CA4\n"
        "    add r4, sp, #0x18\n"
        "    mov r6, sp\n"
        "    adds r6, #0x1a\n"
        "    b .L08154CCA\n"
        "    .byte 0x00, 0x00\n"
        ".L08154CA0: .4byte 0x0203B854 @ EWRAM+0x3B854\n"
        ".L08154CA4: .4byte 0x0000FFFF\n"
        ".L08154CA8:\n"
        "    cmp r0, #5\n"
        "    bne .L08154D20\n"
        "    ldrh r0, [r5, #8]\n"
        "    cmp r0, #1\n"
        "    bne .L08154CB4\n"
        "    b .L08154DE2\n"
        ".L08154CB4:\n"
        "    cmp r0, #2\n"
        "    beq .L08154CBA\n"
        "    b .L08154EB0\n"
        ".L08154CBA:\n"
        "    ldr r5, .L08154D14\n"
        "    ldrh r0, [r5]\n"
        "    ldrh r1, [r5, #2]\n"
        "    mov r3, r8\n"
        "    ldrh r2, [r3, #0x12]\n"
        "    add r4, sp, #0x1c\n"
        "    mov r6, sp\n"
        "    adds r6, #0x1e\n"
        ".L08154CCA:\n"
        "    str r6, [sp]\n"
        "    adds r3, r4, #0\n"
        "    bl sub_0815B884\n"
        "    ldrh r0, [r4]\n"
        "    strh r0, [r5, #6]\n"
        "    ldrh r0, [r4]\n"
        "    movs r1, #0x7c\n"
        "    adds r2, r7, #0\n"
        "    movs r3, #0\n"
        "    bl Fusion_DrawDemonName\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #0xff\n"
        "    bne .L08154CEA\n"
        "    b .L08154EB0\n"
        ".L08154CEA:\n"
        "    ldr r0, .L08154D18\n"
        "    ldr r1, .L08154D1C\n"
        "    movs r2, #0\n"
        "    str r2, [sp]\n"
        "    movs r2, #0xce\n"
        "    adds r3, r7, #0\n"
        "    bl Font_DrawGlyphTinted\n"
        "    ldrh r0, [r6]\n"
        ".L08154CFC:\n"
        "    bl Inventory_GetCount\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    adds r2, r7, #3\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    movs r1, #0xda\n"
        "    movs r3, #0\n"
        "    bl Fusion_DrawLevel\n"
        "    b .L08154EB0\n"
        ".L08154D14: .4byte 0x0203B854 @ EWRAM+0x3B854\n"
        ".L08154D18: .4byte 0x00000115\n"
        ".L08154D1C: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L08154D20:\n"
        "    cmp r0, #2\n"
        "    bne .L08154DD8\n"
        "    ldrh r0, [r5, #8]\n"
        "    cmp r0, #0\n"
        "    beq .L08154DE2\n"
        "    ldr r4, .L08154DCC\n"
        "    ldr r0, [r5, #0x4c]\n"
        "    ldrh r1, [r0, #0x12]\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x90\n"
        "    strh r1, [r0]\n"
        "    mov r6, r8\n"
        "    ldrh r0, [r6, #0x12]\n"
        "    adds r1, r4, #0\n"
        "    adds r1, #0x92\n"
        "    strh r0, [r1]\n"
        "    adds r1, #2\n"
        "    ldr r0, .L08154DD0\n"
        "    strh r0, [r1]\n"
        "    bl Fusion_IsRandomResult\n"
        "    bl Fusion_CalcTwo\n"
        "    ldr r1, .L08154DD4\n"
        "    adds r6, r4, #0\n"
        "    adds r6, #0xa0\n"
        "    ldrh r0, [r6]\n"
        "    strh r0, [r1, #6]\n"
        "    ldr r0, [r5, #0x4c]\n"
        "    ldrh r4, [r0, #0x12]\n"
        "    mov r1, r8\n"
        "    ldrh r0, [r1, #0x12]\n"
        "    bl Fusion_FindListSlot\n"
        "    adds r1, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    adds r3, r7, #4\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    adds r0, r4, #0\n"
        "    movs r2, #0x82\n"
        "    bl sub_0815438C\n"
        "    ldr r0, [r5, #0x4c]\n"
        "    ldrh r4, [r0, #0x12]\n"
        "    mov r2, r8\n"
        "    ldrh r0, [r2, #0x12]\n"
        "    bl Fusion_FindListSlot\n"
        "    adds r1, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Fusion_GetPairIcon\n"
        "    lsls r0, r0, #0x18\n"
        "    movs r1, #0xf0\n"
        "    lsls r1, r1, #0x14\n"
        "    ands r1, r0\n"
        "    lsrs r1, r1, #0x18\n"
        "    cmp r1, #5\n"
        "    beq .L08154E6C\n"
        "    movs r4, #0\n"
        "    ldr r0, [r5, #0x4c]\n"
        "    ldrh r0, [r0, #0x12]\n"
        "    mov r3, r8\n"
        "    ldrh r2, [r3, #0x12]\n"
        "    ldrh r3, [r6]\n"
        "    adds r1, r2, #0\n"
        "    bl Fusion_CanCreate\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L08154DB8\n"
        "    movs r4, #4\n"
        ".L08154DB8:\n"
        "    ldrh r0, [r6]\n"
        "    subs r2, r7, #2\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    movs r1, #0x8a\n"
        "    adds r3, r4, #0\n"
        "    bl Fusion_DrawDemonName\n"
        "    b .L08154EB0\n"
        "    .byte 0x00, 0x00\n"
        ".L08154DCC: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L08154DD0: .4byte 0x0000FFFF\n"
        ".L08154DD4: .4byte 0x0203B854 @ EWRAM+0x3B854\n"
        ".L08154DD8:\n"
        "    cmp r0, #3\n"
        "    bne .L08154EB0\n"
        "    ldrh r0, [r5, #8]\n"
        "    cmp r0, #1\n"
        "    bne .L08154DF2\n"
        ".L08154DE2:\n"
        "    adds r2, r7, #4\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    adds r0, r5, #0\n"
        "    ldr r1, [sp, #0x20]\n"
        "    bl sub_081543E8\n"
        "    b .L08154EB0\n"
        ".L08154DF2:\n"
        "    cmp r0, #2\n"
        "    bne .L08154EB0\n"
        "    mov r6, r8\n"
        "    ldrh r0, [r6, #0x12]\n"
        "    bl Fusion_FindListSlot\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldr r4, .L08154E7C\n"
        "    ldr r0, [r5, #0x4c]\n"
        "    ldrh r1, [r0, #0x12]\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x90\n"
        "    strh r1, [r0]\n"
        "    ldr r0, [r5, #0x50]\n"
        "    ldrh r0, [r0, #0x12]\n"
        "    adds r1, r4, #0\n"
        "    adds r1, #0x92\n"
        "    strh r0, [r1]\n"
        "    mov r0, r8\n"
        "    ldrh r1, [r0, #0x12]\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x94\n"
        "    strh r1, [r0]\n"
        "    bl Fusion_SortMaterials\n"
        "    bl Fusion_IsRandomResult\n"
        "    bl Fusion_CalcThree\n"
        "    ldr r1, .L08154E80\n"
        "    adds r4, #0xa0\n"
        "    ldrh r0, [r4]\n"
        "    strh r0, [r1, #6]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #0xfe\n"
        "    bls .L08154E42\n"
        "    movs r0, #0xfb\n"
        "    strh r0, [r1, #6]\n"
        ".L08154E42:\n"
        "    ldr r0, [r5, #0x50]\n"
        "    ldrh r0, [r0, #0x12]\n"
        "    adds r3, r7, #4\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    adds r1, r6, #0\n"
        "    movs r2, #0x82\n"
        "    bl sub_0815438C\n"
        "    ldr r0, [r5, #0x50]\n"
        "    ldrh r0, [r0, #0x12]\n"
        "    adds r1, r6, #0\n"
        "    bl Fusion_GetPairIcon\n"
        "    lsls r0, r0, #0x18\n"
        "    movs r1, #0xf0\n"
        "    lsls r1, r1, #0x14\n"
        "    ands r1, r0\n"
        "    lsrs r1, r1, #0x18\n"
        "    cmp r1, #5\n"
        "    bne .L08154E84\n"
        ".L08154E6C:\n"
        "    subs r1, r7, #2\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    movs r0, #0x8a\n"
        "    bl sub_08154900\n"
        "    b .L08154EB0\n"
        "    .byte 0x00, 0x00\n"
        ".L08154E7C: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L08154E80: .4byte 0x0203B854 @ EWRAM+0x3B854\n"
        ".L08154E84:\n"
        "    movs r6, #0\n"
        "    ldr r0, [r5, #0x4c]\n"
        "    ldrh r0, [r0, #0x12]\n"
        "    ldr r1, [r5, #0x50]\n"
        "    ldrh r1, [r1, #0x12]\n"
        "    mov r3, r8\n"
        "    ldrh r2, [r3, #0x12]\n"
        "    ldrh r3, [r4]\n"
        "    bl Fusion_CanCreate\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L08154EA0\n"
        "    movs r6, #4\n"
        ".L08154EA0:\n"
        "    ldrh r0, [r4]\n"
        "    subs r2, r7, #2\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    movs r1, #0x8a\n"
        "    adds r3, r6, #0\n"
        "    bl Fusion_DrawDemonName\n"
        ".L08154EB0:\n"
        "    add sp, #0x30\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

// sub_08154EC0 @ 0x08154EC0
void sub_08154EC0(void)
{
    REG_BG1CNT = 0x8205;
    REG_DISPCNT &= 0xFBFF;
    gUnk_03000040 = 0;
}

// sub_08154EEC @ 0x08154EEC
void sub_08154EEC(void)
{
    sub_08154EC0();
    DMA3_SET(gUnknown_081B93B0, 0x06001000, 0x84000200);
    DMA3_SET(gUnk_0200F874, 0x06004000, 0x84001800);
    DMA3_SET(gUnk_0200F874 + 0x7000, 0x06012F00, 0x84000020);
}

/* Column headers (RACE, NAME, RESULT, LV) and the slot numbers of the fusion list. */
// Fusion_DrawListHeader @ 0x08154F4C
#ifdef NONMATCHING
void Fusion_DrawListHeader(void)
{
    struct FusionMenu *f;
    u16 n = Fusion_CountList();
    u16 i, j;
    const u8 *label;
    u16 x;

    f = &sFusion;
    SmallFont_DrawAsciiTinted(gUnknown_087E1C2C, gUnk_0200F874, 10, 0x44, 4, 8);
    SmallFont_DrawAsciiTinted(gUnknown_087E1C34, gUnk_0200F874, 0x32, 0x44, 4, 8);
    if (f->mode == 1)
    {
        if (f->sel == 0)
        {
            n = Stock_CountLiving();
            for (i = 0; i < n; i = j)
            {
                j = i + 1;
                sub_08153F8C(j, gUnk_0200F874, i * 6 + 0x96, 0x44, 0);
            }
            return;
        }
        label = gUnknown_087E1C3C;
        goto draw82;
    }
    if (f->mode == 4)
    {
        if (f->sel == 0)
        {
            for (i = 0; i < n; i = j)
            {
                j = i + 1;
                sub_08153F8C(j, gUnk_0200F874, i * 6 + 0x96, 0x44, 0);
            }
            return;
        }
        label = gUnknown_087E1C3C;
        goto draw82;
    }
    if (f->mode == 5)
    {
        if (f->sel == 2)
        {
            label = gUnknown_087E1C3C;
            goto draw82;
        }
        if (f->sel == 1)
        {
            n = Stock_CountLiving();
            for (i = 0; i < n; i = j)
            {
                j = i + 1;
                sub_08153F8C(j, gUnk_0200F874, i * 6 + 0x96, 0x44, 0);
            }
        }
        return;
    }
    if (f->mode == 2)
    {
        if (f->sel == 0)
        {
            SmallFont_DrawAsciiTinted(gUnknown_087E1C44, gUnk_0200F874, 0x82, 0x44, 4, 8);
            for (i = 0; i < n; i = j)
            {
                j = i + 1;
                sub_08153F8C(j, gUnk_0200F874, i * 6 + 0x96, 0x44, 0);
            }
            return;
        }
        SmallFont_DrawAsciiTinted(gUnknown_087E1C3C, gUnk_0200F874, 0x82, 0x44, 4, 8);
        label = gUnknown_087E1C44;
        x = 0xE0;
        goto draw;
    }
    if (f->mode != 3)
        return;
    if (f->sel == 0)
    {
        label = gUnknown_087E1C44;
        goto draw82;
    }
    if (f->sel == 1)
    {
        SmallFont_DrawAsciiTinted(gUnknown_087E1C44, gUnk_0200F874, 0x82, 0x44, 4, 8);
        for (i = 0; i < n; i = j)
        {
            j = i + 1;
            sub_08153F8C(j, gUnk_0200F874, i * 6 + 0x96, 0x44, 0);
        }
    }
    else if (f->sel == 2)
    {
        SmallFont_DrawAsciiTinted(gUnknown_087E1C3C, gUnk_0200F874, 0x82, 0x44, 4, 8);
        SmallFont_DrawAsciiTinted(gUnknown_087E1C44, gUnk_0200F874, 0xE0, 0x44, 4, 8);
    }
    return;
draw82:
    x = 0x82;
draw:
    SmallFont_DrawAsciiTinted(label, gUnk_0200F874, x, 0x44, 4, 8);
}
#else
NAKED
void Fusion_DrawListHeader(void)
{
    asm_unified(
        ".L08154F4C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    sub sp, #8\n"
        "    bl Fusion_CountList\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    ldr r7, .L08154F94\n"
        "    ldr r0, .L08154F98\n"
        "    ldr r1, .L08154F9C\n"
        "    mov r8, r1\n"
        "    movs r4, #4\n"
        "    str r4, [sp]\n"
        "    movs r6, #8\n"
        "    str r6, [sp, #4]\n"
        "    movs r2, #0xa\n"
        "    movs r3, #0x44\n"
        "    bl SmallFont_DrawAsciiTinted\n"
        "    ldr r0, .L08154FA0\n"
        "    str r4, [sp]\n"
        "    str r6, [sp, #4]\n"
        "    mov r1, r8\n"
        "    movs r2, #0x32\n"
        "    movs r3, #0x44\n"
        "    bl SmallFont_DrawAsciiTinted\n"
        "    ldrh r0, [r7]\n"
        "    cmp r0, #1\n"
        "    bne .L08154FE8\n"
        "    ldrh r0, [r7, #8]\n"
        "    cmp r0, #0\n"
        "    beq .L08154FA8\n"
        "    ldr r0, .L08154FA4\n"
        "    b .L08155110\n"
        ".L08154F94: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L08154F98: .4byte gUnknown_087E1C2C\n"
        ".L08154F9C: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L08154FA0: .4byte gUnknown_087E1C34\n"
        ".L08154FA4: .4byte gUnknown_087E1C3C\n"
        ".L08154FA8:\n"
        "    bl Stock_CountLiving\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    movs r0, #0\n"
        "    cmp r0, r5\n"
        "    blo .L08154FB8\n"
        "    b .L08155194\n"
        ".L08154FB8:\n"
        "    adds r4, r0, #1\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    lsls r2, r0, #1\n"
        "    adds r2, r2, r0\n"
        "    lsls r2, r2, #0x11\n"
        "    movs r0, #0x96\n"
        "    lsls r0, r0, #0x10\n"
        "    adds r2, r2, r0\n"
        "    lsrs r2, r2, #0x10\n"
        "    movs r0, #0\n"
        "    str r0, [sp]\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, .L08154FE4\n"
        "    movs r3, #0x44\n"
        "    bl sub_08153F8C\n"
        "    adds r0, r4, #0\n"
        "    cmp r0, r5\n"
        "    blo .L08154FB8\n"
        "    b .L08155194\n"
        "    .byte 0x00, 0x00\n"
        ".L08154FE4: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L08154FE8:\n"
        "    cmp r0, #4\n"
        "    bne .L08155034\n"
        "    ldrh r0, [r7, #8]\n"
        "    cmp r0, #0\n"
        "    beq .L08154FFC\n"
        "    ldr r0, .L08154FF8\n"
        "    b .L08155110\n"
        "    .byte 0x00, 0x00\n"
        ".L08154FF8: .4byte gUnknown_087E1C3C\n"
        ".L08154FFC:\n"
        "    movs r0, #0\n"
        "    cmp r0, r5\n"
        "    blo .L08155004\n"
        "    b .L08155194\n"
        ".L08155004:\n"
        "    adds r4, r0, #1\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    lsls r2, r0, #1\n"
        "    adds r2, r2, r0\n"
        "    lsls r2, r2, #0x11\n"
        "    movs r1, #0x96\n"
        "    lsls r1, r1, #0x10\n"
        "    adds r2, r2, r1\n"
        "    lsrs r2, r2, #0x10\n"
        "    movs r0, #0\n"
        "    str r0, [sp]\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, .L08155030\n"
        "    movs r3, #0x44\n"
        "    bl sub_08153F8C\n"
        "    adds r0, r4, #0\n"
        "    cmp r0, r5\n"
        "    blo .L08155004\n"
        "    b .L08155194\n"
        "    .byte 0x00, 0x00\n"
        ".L08155030: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L08155034:\n"
        "    cmp r0, #5\n"
        "    bne .L0815508C\n"
        "    ldrh r0, [r7, #8]\n"
        "    cmp r0, #2\n"
        "    bne .L08155048\n"
        "    ldr r0, .L08155044\n"
        "    b .L08155110\n"
        "    .byte 0x00, 0x00\n"
        ".L08155044: .4byte gUnknown_087E1C3C\n"
        ".L08155048:\n"
        "    cmp r0, #1\n"
        "    beq .L0815504E\n"
        "    b .L08155194\n"
        ".L0815504E:\n"
        "    bl Stock_CountLiving\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    movs r0, #0\n"
        "    cmp r0, r5\n"
        "    blo .L0815505E\n"
        "    b .L08155194\n"
        ".L0815505E:\n"
        "    adds r4, r0, #1\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    lsls r2, r0, #1\n"
        "    adds r2, r2, r0\n"
        "    lsls r2, r2, #0x11\n"
        "    movs r0, #0x96\n"
        "    lsls r0, r0, #0x10\n"
        "    adds r2, r2, r0\n"
        "    lsrs r2, r2, #0x10\n"
        "    movs r0, #0\n"
        "    str r0, [sp]\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, .L08155088\n"
        "    movs r3, #0x44\n"
        "    bl sub_08153F8C\n"
        "    adds r0, r4, #0\n"
        "    cmp r0, r5\n"
        "    blo .L0815505E\n"
        "    b .L08155194\n"
        ".L08155088: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L0815508C:\n"
        "    cmp r0, #2\n"
        "    bne .L08155104\n"
        "    ldrh r0, [r7, #8]\n"
        "    cmp r0, #0\n"
        "    bne .L081550E0\n"
        "    ldr r0, .L081550D8\n"
        "    str r4, [sp]\n"
        "    str r6, [sp, #4]\n"
        "    mov r1, r8\n"
        "    movs r2, #0x82\n"
        "    movs r3, #0x44\n"
        "    bl SmallFont_DrawAsciiTinted\n"
        "    movs r0, #0\n"
        "    cmp r0, r5\n"
        "    bhs .L08155194\n"
        ".L081550AC:\n"
        "    adds r4, r0, #1\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    lsls r2, r0, #1\n"
        "    adds r2, r2, r0\n"
        "    lsls r2, r2, #0x11\n"
        "    movs r1, #0x96\n"
        "    lsls r1, r1, #0x10\n"
        "    adds r2, r2, r1\n"
        "    lsrs r2, r2, #0x10\n"
        "    movs r0, #0\n"
        "    str r0, [sp]\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, .L081550DC\n"
        "    movs r3, #0x44\n"
        "    bl sub_08153F8C\n"
        "    adds r0, r4, #0\n"
        "    cmp r0, r5\n"
        "    blo .L081550AC\n"
        "    b .L08155194\n"
        "    .byte 0x00, 0x00\n"
        ".L081550D8: .4byte gUnknown_087E1C44\n"
        ".L081550DC: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L081550E0:\n"
        "    ldr r0, .L081550FC\n"
        "    str r4, [sp]\n"
        "    str r6, [sp, #4]\n"
        "    mov r1, r8\n"
        "    movs r2, #0x82\n"
        "    movs r3, #0x44\n"
        "    bl SmallFont_DrawAsciiTinted\n"
        "    ldr r0, .L08155100\n"
        "    str r4, [sp]\n"
        "    str r6, [sp, #4]\n"
        "    mov r1, r8\n"
        "    movs r2, #0xe0\n"
        "    b .L08155118\n"
        ".L081550FC: .4byte gUnknown_087E1C3C\n"
        ".L08155100: .4byte gUnknown_087E1C44\n"
        ".L08155104:\n"
        "    cmp r0, #3\n"
        "    bne .L08155194\n"
        "    ldrh r0, [r7, #8]\n"
        "    cmp r0, #0\n"
        "    bne .L08155124\n"
        "    ldr r0, .L08155120\n"
        ".L08155110:\n"
        "    str r4, [sp]\n"
        "    str r6, [sp, #4]\n"
        "    mov r1, r8\n"
        "    movs r2, #0x82\n"
        ".L08155118:\n"
        "    movs r3, #0x44\n"
        "    bl SmallFont_DrawAsciiTinted\n"
        "    b .L08155194\n"
        ".L08155120: .4byte gUnknown_087E1C44\n"
        ".L08155124:\n"
        "    cmp r0, #1\n"
        "    bne .L08155170\n"
        "    ldr r0, .L08155168\n"
        "    str r4, [sp]\n"
        "    str r6, [sp, #4]\n"
        "    mov r1, r8\n"
        "    movs r2, #0x82\n"
        "    movs r3, #0x44\n"
        "    bl SmallFont_DrawAsciiTinted\n"
        "    movs r0, #0\n"
        "    cmp r0, r5\n"
        "    bhs .L08155194\n"
        ".L0815513E:\n"
        "    adds r4, r0, #1\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    lsls r2, r0, #1\n"
        "    adds r2, r2, r0\n"
        "    lsls r2, r2, #0x11\n"
        "    movs r0, #0x96\n"
        "    lsls r0, r0, #0x10\n"
        "    adds r2, r2, r0\n"
        "    lsrs r2, r2, #0x10\n"
        "    movs r0, #0\n"
        "    str r0, [sp]\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, .L0815516C\n"
        "    movs r3, #0x44\n"
        "    bl sub_08153F8C\n"
        "    adds r0, r4, #0\n"
        "    cmp r0, r5\n"
        "    blo .L0815513E\n"
        "    b .L08155194\n"
        ".L08155168: .4byte gUnknown_087E1C44\n"
        ".L0815516C: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L08155170:\n"
        "    cmp r0, #2\n"
        "    bne .L08155194\n"
        "    ldr r0, .L081551A0\n"
        "    str r4, [sp]\n"
        "    str r6, [sp, #4]\n"
        "    mov r1, r8\n"
        "    movs r2, #0x82\n"
        "    movs r3, #0x44\n"
        "    bl SmallFont_DrawAsciiTinted\n"
        "    ldr r0, .L081551A4\n"
        "    str r4, [sp]\n"
        "    str r6, [sp, #4]\n"
        "    mov r1, r8\n"
        "    movs r2, #0xe0\n"
        "    movs r3, #0x44\n"
        "    bl SmallFont_DrawAsciiTinted\n"
        ".L08155194:\n"
        "    add sp, #8\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L081551A0: .4byte gUnknown_087E1C3C\n"
        ".L081551A4: .4byte gUnknown_087E1C44\n"
    );
}
#endif

/* Redraws the six visible rows of the fusion list from row top. */
// Fusion_DrawList @ 0x081551A8
void Fusion_DrawList(u16 top)
{
    struct FusionMenu *f = &sFusion;
    u16 i;

    sub_0815B880(f->count);
    for (i = 0; i < 6; i++)
        Fusion_DrawListRow(f, top + i, i * 13 + 0x4C);
    VBlankTask_AddCounted(sub_08154EEC, 1);
}
