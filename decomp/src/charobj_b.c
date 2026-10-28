#include "global.h"
#include "inventory.h"

// Char_LoadGfxHalf @ 0x080C4080
/* LZ77-expands one half of a character sprite to 0x02001000 + slot * 0x1000 + half * 0x800;
   after the second half loads the palette (unless noPal) and queues the DMA to OBJ VRAM. */
void Char_LoadGfxHalf(struct ObjData *obj, const void *src, u32 noPal, u32 half, u32 fade)
{
    const struct CharGfxRecord *rec = Char_GetRecord(obj->id);
    u16 slot = obj->palSlot;

    if (obj->hasPal == 0)
        return;
    if (slot == 0)
    {
        LZ77UnCompWram(src, (void *)(0x02001000 + (half << 11)));
        if (half != 1)
            return;
        if (noPal == 0)
            sub_080C3F4C(obj, rec->palette, 0x1E0, 0x20, fade);
        VBlankTask_AddCounted(sub_080C3EBC, 1);
    }
    else if (slot == 1)
    {
        LZ77UnCompWram(src, (void *)(0x02002000 + (half << 11)));
        if (half != 1)
            return;
        if (noPal == 0)
            sub_080C3F4C(obj, rec->palette, 0x1F0, 0x20, fade);
        VBlankTask_AddCounted(sub_080C3EE0, 1);
    }
    else if (slot == 2)
    {
        LZ77UnCompWram(src, (void *)(0x02003000 + (half << 11)));
        if (half != 1)
            return;
        if (noPal == 0)
            sub_080C3F4C(obj, rec->palette, 0x1D0, 0x20, fade);
        VBlankTask_AddCounted(sub_080C3F04, 1);
    }
    else
    {
        LZ77UnCompWram(src, (void *)(0x02004000 + (half << 11)));
        if (half != 1)
            return;
        if (noPal == 0)
            sub_080C3F4C(obj, rec->palette, 0x1C0, 0x20, fade);
        if (gMainCallback != sub_080D977C || obj->id != 0x2A)
            VBlankTask_AddCounted(sub_080C3F28, 1);
    }
}

// sub_080C41B0 @ 0x080C41B0
void sub_080C41B0(struct Task *t, u32 noPal, u32 frame, u32 half)
{
    struct ObjData *d = (struct ObjData *)Task_GetParent(t)->data.raw;

    Char_LoadGfxHalf(d, Char_GetRecord(d->id)->gfx[frame][half], noPal, half, 1);
}

// sub_080C41F4 @ 0x080C41F4
void sub_080C41F4(struct Task *t)
{
    struct ObjData *d = (struct ObjData *)t->data.raw;
    u16 slot = d->palSlot;

    if (d->hasPal == 0)
        return;
    if (slot == 0)
        PalFade_FadeRangeToBlackTagged(0x1E0, 0x10, 1, 1);
    else if (slot == 1)
        PalFade_FadeRangeToBlackTagged(0x1F0, 0x10, 1, 1);
    else if (slot == 2)
        PalFade_FadeRangeToBlackTagged(0x1D0, 0x10, 1, 1);
    else
        PalFade_FadeRangeToBlackTagged(0x1C0, 0x10, 1, 1);
}

// sub_080C423C @ 0x080C423C
u32 sub_080C423C(struct ObjData *d)
{
    return 0;
}

// Color_StepComponent @ 0x080C4240
/* One step of a colour component towards target (up) or towards 0 (down). */
u16 Color_StepComponent(u16 cur, u16 target, u16 up)
{
    if (!up)
    {
        if (!cur)
            return 0;
        cur--;
    }
    else
    {
        if (cur >= target)
            return target;
        cur++;
    }
    return cur;
}

// CharObj_UpdateGlow @ 0x080C4274
/* Glow: every 8 frames moves OBJ palette pal (colours 1-15) one step towards the record's
   palette or towards black, switching direction every 7 steps. */
void CharObj_UpdateGlow(struct ObjData *d, u16 pal)
{
    const struct CharGfxRecord *rec;
    u16 *dst;
    const u16 *src;
    u16 i;

    if (d->unk12 != 1 || (gFrameCounter & 7) != 0 || PalFade_AllDone() != 1)
        return;
    rec = Char_GetRecord(d->id);
    dst = &gPaletteBuffer[0x101 + pal * 16];
    src = rec->palette;
    src++;
    for (i = 0; i < 15; i++, dst++, src++)
    {
        u16 cr = *dst & 0x1F;
        u16 cg = (*dst & 0x3E0) >> 5;
        u16 cb = (*dst & 0x7C00) >> 10;
        u16 tr = *src & 0x1F;
        u16 tg = (*src & 0x3E0) >> 5;
        u16 tb = (*src & 0x7C00) >> 10;
        u16 r, g, b;

        r = Color_StepComponent(cr, tr, d->unk14);
        g = Color_StepComponent(cg, tg, d->unk14);
        b = Color_StepComponent(cb, tb, d->unk14);
        Palette_FillWithEffect(3, r | (g << 5) | (b << 10), dst, 2, 0x20);
    }
    Palette_MarkDirty();
    if (++d->unk16 > 6)
    {
        d->unk16 = 0;
        d->unk14 = (d->unk14 + 1) & 1;
    }
}

// sub_080C4388 @ 0x080C4388
u16 sub_080C4388(struct ObjData *d)
{
    if ((u16)(d->id - 0xAA) <= 1 || d->id == 0xF5)
        return 0;
    return 8 - (d->unk00 & 7);
}

// sub_080C43B4 @ 0x080C43B4
const void *sub_080C43B4(struct ObjData *d)
{
    const struct CharGfxRecord *rec = Char_GetRecord(d->id);

    if (!(d->unk00 & 0x10) && rec->unk02 != 0 && ((gFrameCounter >> 4) & 1))
        return gUnknown_08005028;
    return gUnknown_08004FF8;
}

// sub_080C43F8 @ 0x080C43F8
void sub_080C43F8(struct Task *t, const void *def, u32 tile, u32 pal)
{
    struct ObjData *d = (struct ObjData *)t->data.raw;
    u16 slot = d->palSlot;
    u16 tl;
    u16 pl;
    u16 layer;
    u16 y;

    layer = sub_080C4388(d);
    y = d->y;
    y -= gUnk_0300000E;
    if (tile != 0)
        tl = tile;
    else if (slot == 0)
        tl = 0;
    else if (slot == 1)
        tl = 0x80;
    else if (slot == 2)
        tl = 0xFF80;
    else
        tl = 0xFE00;
    if (pal != 0)
        pl = pal;
    else if (slot == 0)
        pl = 14;
    else if (slot == 1)
        pl = 15;
    else if (slot == 2)
        pl = 13;
    else
        pl = 12;
    if (gMainCallback == sub_080D977C && d->id == 0x2A)
        tl = 0;
    sub_080C44CC(d, def, layer, pl, d->unk10, tl, d->x, y);
}

// sub_080C44B0 @ 0x080C44B0
void sub_080C44B0(struct Task *t)
{
    sub_080C43F8(t, sub_080C43B4((struct ObjData *)t->data.raw), 0, 0);
}

// sub_080C44CC @ 0x080C44CC
void sub_080C44CC(struct ObjData *d, const void *def, u16 layer, u16 pal, u16 prio, u16 tile, u16 x, u16 y)
{
    if (sub_080C423C(d) == 1)
        return;
    CharObj_UpdateGlow(d, pal);
    if (Flag_Test(0x106))
        x += 0x8000;
    if (!(d->unk00 & 0x20))
        Sprite_Draw(def, layer, pal, prio, tile, x, y);
    else
        Sprite_DrawBlended(def, layer, pal, prio, tile, x, y);
}

// sub_080C457C @ 0x080C457C
void sub_080C457C(struct Task *t, u32 v)
{
    ((struct ObjData *)t->data.raw)->unk12 = v;
}

// sub_080C4580 @ 0x080C4580
void sub_080C4580(struct Task *t)
{
    sub_080C457C(t, 1);
}

// sub_080C458C @ 0x080C458C
void sub_080C458C(struct Task *t)
{
    sub_080C457C(t, 0);
}

// sub_080C4598 @ 0x080C4598
void sub_080C4598(struct Task *t)
{
    u32 i;

    for (i = 0; i < 8; i++)
    {
        if (gUnk_030068F0[i] == t)
        {
            gUnk_030068F0[i] = NULL;
            return;
        }
    }
}

// CharObj_FindInGroup @ 0x080C45C0
/* Finds the character task of group key & 7 showing id; one of that group showing another
   character is ended and NULL returned. */
struct Task *CharObj_FindInGroup(u16 key, u16 id)
{
    u16 grp = key & 7;
    u32 i;

    for (i = 0; i < 6; i++)
    {
        struct Task *t = gCharTasks[i];

        if (t != NULL)
        {
            struct ObjData *d = (struct ObjData *)t->data.raw;

            if ((d->unk00 & 7) == grp)
            {
                if (d->id == id)
                    return t;
                CharObj_End(t, 0);
                return NULL;
            }
        }
    }
    return NULL;
}

// sub_080C4614 @ 0x080C4614
void sub_080C4614(u16 key)
{
}
