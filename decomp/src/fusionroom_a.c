#include "global.h"
#include "fusion.h"

/* Loads the capsule tiles and the room's capsule tilemap (palette line 2, tile 0x2C0). */
// sub_081575D8 @ 0x081575D8
void sub_081575D8(void)
{
    u16 mode = gUnk_0203B854[4];
    const u8 *src;

    LZ77UnCompWram(gUnknown_087E5D48, &gUnk_02000000[0x6800]);
    if (mode == 1 || mode == 2 || mode == 4 || mode == 6)
        src = gUnknown_087EFB04;
    else
        src = gUnknown_087EFCD8;
    LZ77UnCompWram(src, &gUnk_02000000[0x800]);
    Tilemap_CopyRectSkipZero(&gUnk_02000000[0x800], gUnk_02000000, 0x2C0, 2, 0, 0, 0x1E, 0x14);
}

// sub_0815764C @ 0x0815764C
void sub_0815764C(void)
{
    sub_080C1384();
    Palette_CopyWithEffect(3, gUnknown_087EFF4C, &gPaletteTarget[0x20], 0x40, 0x20);
    Palette_CopyWithEffect(3, gUnknown_087EFFCC, &gPaletteTarget[0x60], 0x140, 0x20);
    VBlankTask_AddCounted(sub_08157534, 1);
}

// sub_08157698 @ 0x08157698
void sub_08157698(void)
{
    struct FusionRoom *r = &sRoom;

    r->palFade = PalFade_FadeRangeInFromBlackTagged(0, 0x1D0, 1, 0x8001);
}

// sub_081576BC @ 0x081576BC
void sub_081576BC(struct Task *task)
{
    if (!PalFade_IsActive(sRoom.palFade))
        task->result = 1;
    else
        task->result = 0;
}

/* Creates the sprite of material slot (0-2) or the result (3) in the fusion room. */
// sub_081576E4 @ 0x081576E4
void sub_081576E4(u32 a0, u32 slot)
{
    struct FusionRoom *r = &sRoom;
    u16 y;
    u16 x;

    if (slot == 2 && (gUnk_0203B854[4] == 1 || gUnk_0203B854[4] == 2 || gUnk_0203B854[4] == 4))
        return;
    switch (slot)
    {
    case 0:
        x = -11;
        y = 0x4A;
        break;
    case 1:
        x = 0x82;
        y = 0x4A;
        break;
    case 2:
        x = 0x46;
        y = 0x21;
        break;
    case 3:
        x = 0x3B;
        y = 0x2E;
        break;
    }
    if (gUnk_0203B854[slot] == 0x13B)
        y -= 3;
    else if (gUnk_0203B854[slot] == 0x13C)
        x++;
    else if (gUnk_0203B854[slot] == 0x13F)
        x--;
    r->objs[slot] = DemonObj_Create(0, gUnk_0203B854[slot], x, y, 0, 0);
}

// sub_081577A0 @ 0x081577A0
void sub_081577A0(u32 a0, u32 slot)
{
    struct Task *obj = sRoom.objs[slot];

    if (slot == 2 && (gUnk_0203B854[4] == 1 || gUnk_0203B854[4] == 2 || gUnk_0203B854[4] == 4))
        return;
    if (obj != NULL)
        obj->onFrame = sub_080C3C68;
    if (slot == 3)
        sub_080C3E40(obj, 0);
}

// sub_081577E8 @ 0x081577E8
void sub_081577E8(u32 a0, u32 kind, u32 line)
{
    struct FusionRoom *r = &sRoom;

    if (kind == 0)
    {
        Palette_CopyWithEffect(3, gUnknown_087EFFAC, &gPaletteTarget[0x20 + line * 16], 0x20, 0x20);
        PalFade_FadeRangeWithDuration(line * 16 + 0x50, 0x10, 1, 0x20);
    }
    else
    {
        Palette_CopyWithEffect(3, gUnknown_087EFF4C, &gPaletteTarget[0x20 + r->unk32 * 16], 0x20, 0x20);
        PalFade_FadeRangeWithDuration(r->unk32 * 16 + 0x50, 0x10, 1, 0x20);
    }
}

// sub_08157868 @ 0x08157868
void sub_08157868(u32 a0, u32 slot)
{
    struct FusionRoom *r = &sRoom;

    sub_080C3E64(r->objs[slot]);
    r->unk6 = 0;
}

/* Dissolves the sprite tiles of slot with the next of four masks; ends the sprite after. */
// FusionRoom_DissolveSprite @ 0x08157888
void FusionRoom_DissolveSprite(struct Task *task, u32 slot)
{
    struct FusionRoom *r = &sRoom;

    if (r->unk6 <= 3)
    {
        u32 *dst = (u32 *)(gUnk_02001000 + slot * 0x1000);
        u16 i;

        for (i = 0; i < 0x78; i++)
        {
            const u32 *mask = gUnknown_087F02B8[r->unk6];

            *dst++ &= *mask++;
            *dst++ &= *mask++;
            *dst++ &= *mask++;
            *dst++ &= *mask++;
            *dst++ &= *mask++;
            *dst++ &= *mask++;
            *dst++ &= *mask++;
            *dst++ &= *mask++;
        }
        switch (slot)
        {
        case 0:
            VBlankTask_AddCounted(sub_080C3EBC, 1);
            break;
        case 1:
            VBlankTask_AddCounted(sub_080C3EE0, 1);
            break;
        case 2:
            VBlankTask_AddCounted(sub_080C3F04, 1);
            break;
        }
        r->unk6++;
        task->result = 0;
    }
    else
    {
        DemonObj_End(r->objs[slot], 0);
        task->result = 1;
    }
}

// sub_0815795C @ 0x0815795C
void sub_0815795C(struct Task *parent, u32 line)
{
    struct FusionRoom *r = &sRoom;

    Task_Create(gUnknown_087F0F94, parent->id);
    r->unk30 = 0;
    r->unk32 = line;
}

// sub_08157980 @ 0x08157980
void sub_08157980(void)
{
    struct FusionRoom *r = &sRoom;

    r->win34 = Window_CreateOpen(2, 0xE, 0x1A, 6, 0);
}

// sub_081579A4 @ 0x081579A4
const u16 *sub_081579A4(u16 id)
{
    u16 k = sub_0815B824(id);

    if (id == 0x13E)
        k = 14;
    return gUnknown_087F02C8[k];
}

/* Result message window: expands 0x31F (race) and 0x31E (demon name) in the message,
   12 px per glyph, 0x300 = new line. */
// FusionRoom_DrawResultMessage @ 0x081579D4
void FusionRoom_DrawResultMessage(struct Task *task)
{
    struct FusionRoom *r = &sRoom;

    if (gKeysNew & 1)
    {
        Sound_Play(0x65);
        Window_Close(r->win34, 1);
        task->result = 1;
    }
    else
    {
        task->result = 0;
    }
    if (r->unk80 != 0)
    {
        Text_DrawSpriteString(gUnknown_0815BB90, 0, 0, 0x12, 0x72, 0xC);
    }
    else
    {
        u16 id = gUnk_0203B854[3];
        u16 mode = gUnk_0203B854[4];
        struct DemonRecord *rec = Demon_GetRecord(id);
        u16 x = 0x12;
        u16 y = 0x72;
        const u16 *s;
        const u16 *name;
        u16 i;

        if (mode == 1 || mode == 4 || mode == 5)
            s = gUnknown_0815BF92;
        else
            s = sub_081579A4(id);
        for (; *s != 0x301; s++)
        {
            if (*s == 0x316)
            {
            }
            else if (*s == 0x31F)
            {
                name = Race_GetName(rec->race);
                for (i = 0; i < 8 && name[i] != 0; i++)
                {
                    FontSprite_DrawGlyph(name[i], 0, 0, x, y);
                    x += 12;
                }
            }
            else if (*s == 0x31E)
            {
                for (i = 0; i < 8 && rec->name[i] != 0; i++)
                {
                    FontSprite_DrawGlyph(rec->name[i], 0, 0, x, y);
                    x += 12;
                }
            }
            else if (*s == 0x300)
            {
                x = 0x12;
                y += 12;
            }
            else
            {
                FontSprite_DrawGlyph(*s, 0, 0, x, y);
                x += 12;
            }
        }
    }
    if (!((gFrameCounter >> 4) & 1))
        sub_080C4AB0(0, 0, 0xD6, 0x95);
}

// sub_08157B78 @ 0x08157B78
void sub_08157B78(struct Task *task)
{
    switch (gUnk_0203B854[4])
    {
    case 1:
    case 2:
    case 4:
        task->unk1E = 2;
        break;
    case 3:
    case 5:
        task->unk1E = 3;
        break;
    }
}

/* k == 0: leaves the room (restores the hidden field character); else shows frame k of it. */
// sub_08157BB8 @ 0x08157BB8
void sub_08157BB8(u32 a0, u32 k)
{
    struct FusionRoom *r = &sRoom;

    if (k == 0)
    {
        DemonObj_End(r->objs[3], 0);
        gCharTasks[0] = r->savedTask;
        gGfxSlots[0][0] = r->savedSlot[0];
        gGfxSlots[0][1] = r->savedSlot[1];
        if (r->savedTask != NULL)
            sub_080CE580(r->savedTask, 1);
    }
    else if (gCharTasks[0] != NULL)
    {
        struct CharObj *obj = (struct CharObj *)gCharTasks[0]->data.raw;

        Char_LoadGfxHalf(obj, Char_GetRecord(obj->id)->gfx[k - 1], 0, k - 1, 0);
    }
}

/* Fusing with demon 0xFB: bit 0 when the other material has full HP, bit 1 full MP. */
// sub_08157C2C @ 0x08157C2C
u32 sub_08157C2C(void)
{
    u32 r = 0;
    struct Combatant *a = Stock_FindDemon(gUnk_0203B854[0]);
    struct Combatant *b = Stock_FindDemon(gUnk_0203B854[1]);

    if (gUnk_0203B854[0] == 0xFB)
    {
        if (b->hp >= b->maxHp)
            r = 1;
        if (b->mp >= b->maxMp)
            r |= 2;
    }
    else if (gUnk_0203B854[1] == 0xFB)
    {
        if (a->hp >= a->maxHp)
            r = 1;
        if (a->mp >= a->maxMp)
            r |= 2;
    }
    return r;
}

/* Commits the fusion (or compendium summon / item fusion): removes the materials, adds the result. */
// Fusion_Commit @ 0x08157C90
void Fusion_Commit(void)
{
    struct FusionRoom *r = &sRoom;

    if (r->unk0 == 1)
    {
        Inventory_RemoveItem(0x10A);
        Inventory_RemoveItem(0x10B);
        Inventory_RemoveItem(0x10C);
        Inventory_RemoveItem(0x10D);
        Inventory_RemoveItem(0x10E);
        Inventory_RemoveItem(0x10F);
    }
    else if (r->unk0 == 3)
    {
        Stock_AddDemon(gUnk_0203B854[3]);
        Money_Add(-Compendium_GetPrice(gUnk_0203B854[3]));
        Music_Play(0xF);
    }
    else if (gUnk_0203B854[4] == 1)
    {
        Inventory_RemoveItem(Fusion_GetDemonByIndex(gUnk_0203B854[0]));
        Party_Remove(Stock_FindDemon(gUnk_0203B854[1])->id, 1);
        Inventory_AddItem(Fusion_GetDemonByIndex(gUnk_0203B854[3]));
        Music_Play(0xF);
    }
    else if (gUnk_0203B854[4] == 4)
    {
        Inventory_RemoveItem(Fusion_GetDemonByIndex(gUnk_0203B854[0]));
        Inventory_RemoveItem(Fusion_GetDemonByIndex(gUnk_0203B854[1]));
        Inventory_AddItem(Fusion_GetDemonByIndex(gUnk_0203B854[3]));
        Music_Play(0xF);
    }
    else if (gUnk_0203B854[4] == 5)
    {
        Inventory_RemoveItem(Fusion_GetDemonByIndex(gUnk_0203B854[0]));
        Inventory_RemoveItem(Fusion_GetDemonByIndex(gUnk_0203B854[1]));
        Party_Remove(Stock_FindDemon(gUnk_0203B854[2])->id, 1);
        Inventory_AddItem(Fusion_GetDemonByIndex(gUnk_0203B854[3]));
        Music_Play(0xF);
    }
    else
    {
        u16 bonus = 0;
        struct Combatant *c;
        u16 i;

        if (gUnk_0203B854[4] == 2)
        {
            struct Combatant *a = Stock_FindDemon(gUnk_0203B854[0]);
            struct Combatant *b = Stock_FindDemon(gUnk_0203B854[1]);

            bonus = sub_08157C2C();
            Party_Remove(a->id, 1);
            Party_Remove(b->id, 1);
        }
        else if (gUnk_0203B854[4] == 3)
        {
            Party_Remove(Stock_FindDemon(gUnk_0203B854[0])->id, 1);
            Party_Remove(Stock_FindDemon(gUnk_0203B854[1])->id, 1);
            Party_Remove(Stock_FindDemon(gUnk_0203B854[2])->id, 1);
        }
        Stock_AddDemon(gUnk_0203B854[3]);
        c = Stock_FindByDemonId(gUnk_0203B854[3]);
        if (r->unk80 == 0)
        {
            for (i = 0; i < 6; i++)
                c->skills[i] = gUnk_0203B860[i];
        }
        if (bonus != 0)
        {
            if (bonus & 1)
            {
                c->hp += c->maxHp / 4;
                if (c->hp > 999)
                    c->hp = 999;
            }
            if (bonus & 2)
            {
                c->mp += c->maxMp / 4;
                if (c->mp > 999)
                    c->mp = 999;
            }
        }
        sub_080E5DA0();
        Fusion_ApplyResult();
        Music_Play(0xF);
    }
    Party_FixFormation();
    r->fade->state = 1;
}

// sub_08157E8C @ 0x08157E8C
void sub_08157E8C(void)
{
    sFusion.fade->state = 1;
    gUnk_03003BB4 = 0;
}

// sub_08157EA4 @ 0x08157EA4
u32 sub_08157EA4(void)
{
    return sub_080CED00();
}
