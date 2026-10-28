#include "global.h"
#include "inventory.h"

// CharObj_Create @ 0x080C4618
/* Creates (or refreshes) the character object for id in group key & 7. An existing one only
   reloads its palette (key bit 6: fades it out instead). */
struct Task *CharObj_Create(u16 key, u16 id, u16 x, u16 y, u16 e, u16 f)
{
    const struct CharGfxRecord *rec = Char_GetRecord(id);
    struct Task *t = CharObj_FindInGroup(key, id);
    struct ObjData *d;
    u16 evId;

    if (t != NULL)
    {
        d = (struct ObjData *)t->data.raw;
        if (!(key & 0x40))
        {
            const u16 *pal = Char_GetRecord(id)->palette;

            if (id == 0x1C1)
                pal = sub_080D8248(gUnk_0203DB28[0])->palette;
            else if (id == 0x1C0)
                pal = sub_080D8248(gUnk_0203DB28[1])->palette;
            if (d->palSlot == 0)
            {
                Palette_CopyWithEffect(3, pal, &gPaletteBuffer[0x1E0], 0x20, 0x20);
                Palette_CopyWithEffect(3, pal, &gPaletteTarget[0x1E0], 0x20, 0x20);
                Palette_MarkDirty();
            }
            else if (d->palSlot == 1)
            {
                Palette_CopyWithEffect(3, pal, &gPaletteBuffer[0x1F0], 0x20, 0x20);
                Palette_CopyWithEffect(3, pal, &gPaletteTarget[0x1F0], 0x20, 0x20);
                Palette_MarkDirty();
            }
            else if (d->palSlot == 2)
            {
                Palette_CopyWithEffect(3, pal, &gPaletteBuffer[0x1D0], 0x20, 0x20);
                Palette_CopyWithEffect(3, pal, &gPaletteTarget[0x1D0], 0x20, 0x20);
                Palette_MarkDirty();
            }
            else
            {
                Palette_CopyWithEffect(3, pal, &gPaletteBuffer[0x1C0], 0x20, 0x20);
                Palette_CopyWithEffect(3, pal, &gPaletteTarget[0x1C0], 0x20, 0x20);
                Palette_MarkDirty();
            }
        }
        else
        {
            if (d->palSlot == 0)
                PalFade_FadeRangeToBlackWithDuration(0x1E0, 0x10, 1, 3);
            else if (d->palSlot == 1)
                PalFade_FadeRangeToBlackWithDuration(0x1F0, 0x10, 1, 3);
            else if (d->palSlot == 2)
                PalFade_FadeRangeToBlackWithDuration(0x1D0, 0x10, 1, 3);
            else
                PalFade_FadeRangeToBlackWithDuration(0x1C0, 0x10, 1, 3);
        }
        return t;
    }

    sub_080C4614(key);
    /* kinds other than 0-3 leave t and d unset */
    if (rec->unk00 == 0)
    {
        t = Task_Create(gUnknown_081A65B8, 0xFFFF);
        d = (struct ObjData *)t->data.raw;
        d->child20 = Task_Create(gUnknown_081A64A8, t->id);
    }
    else if (rec->unk00 == 1)
    {
        t = Task_Create(gUnknown_081A65B8, 0xFFFF);
        d = (struct ObjData *)t->data.raw;
        d->child20 = Task_Create(gUnknown_081A64F8, t->id);
    }
    else if (rec->unk00 == 2)
    {
        t = Task_Create(rec->script, 0xFFFF);
        d = (struct ObjData *)t->data.raw;
    }
    else if (rec->unk00 == 3)
    {
        t = Task_Create(gUnknown_0855FB78, 0xFFFF);
        d = (struct ObjData *)t->data.raw;
    }
    d->unk00 = key;
    d->palSlot = GfxSlot_Acquire(t, id);
    if (Flag_Test(0x10B))
    {
        d->fadeIn = 1;
        Flag_Clear(0x10B);
    }
    else if (Flag_Test(0x10C))
    {
        d->fadeWhite = 1;
        Flag_Clear(0x10C);
    }
    /* fadeIn and fadeWhite read as one word */
    if (*(u32 *)&d->fadeIn == 0 && !Flag_Test(0xC6))
    {
        struct C0c2FieldEvent *ev = sub_080C9084(gFieldState.x, gFieldState.y, gFieldState.facing, &evId);

        if (ev != NULL && ScriptVM_RunAlt(ev->script) == 2)
            d->fadeIn = 1;
    }
    CharTask_Register(t);
    d->id = id;
    d->x = x;
    d->y = y;
    d->unk0C = e;
    d->unk0E = f;
    d->unk10 = 2;
    if (y > 0x3F)
        d->unk10 = 3;
    if (GfxSlot_FindShared(id) == 0xFFFF)
        d->hasPal = 1;
    return t;
}

// sub_080C48B0 @ 0x080C48B0
void sub_080C48B0(struct Task *t, u16 v)
{
    t->data.h[8] = v;
}

// sub_080C48B4 @ 0x080C48B4
void sub_080C48B4(struct Task *t, u16 dx, u16 dy)
{
    struct ObjData *d = (struct ObjData *)t->data.raw;

    d->x += dx;
    d->y += dy;
}

// sub_080C48CC @ 0x080C48CC
void sub_080C48CC(struct Task *t, u32 x, u32 y)
{
    struct ObjData *d = (struct ObjData *)t->data.raw;

    d->x = x;
    d->y = y;
}

// sub_080C48D4 @ 0x080C48D4
void sub_080C48D4(struct Task *t)
{
    struct ObjData *d = (struct ObjData *)t->data.raw;

    if (d->child20 != NULL)
    {
        Task_End(d->child20);
        d->child20 = NULL;
    }
}

// CharObj_End @ 0x080C48F0
/* Ends a character object: releases its graphics slot and child task. */
void CharObj_End(struct Task *t, u32 unused)
{
    struct ObjData *d;

    if (t == NULL || t->state == 0)
        return;
    d = (struct ObjData *)t->data.raw;
    gGfxSlots[d->palSlot][0]--;
    CharTask_Unregister(t);
    sub_080C4598(t);
    if (d->child20 != NULL)
        Task_End(d->child20);
    Task_End(t);
}

// sub_080C4938 @ 0x080C4938
/* Draws a horizontal frame of n pieces: left end (16 px), middle pieces (8 px), right end. */
void sub_080C4938(u16 n, u16 layer, u16 pal, u16 prio, u16 x, u16 y)
{
    u16 i;

    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            Sprite_DrawSingle(gUnknown_081A65DC, layer, pal, prio, i, x, y);
            x += 16;
        }
        else if (i == n - 1)
        {
            Sprite_DrawSingle(gUnknown_081A65EC, layer, pal, prio, 0, x, y);
        }
        else
        {
            Sprite_DrawSingle(gUnknown_081A65E4, layer, pal, prio, 0, x, y);
            x += 8;
        }
    }
}

// sub_080C49EC @ 0x080C49EC
void sub_080C49EC(u16 n, u16 layer, u16 prio, u16 x, u16 y)
{
    sub_080C4938(n, layer, 3, prio, x, y);
}

// sub_080C4A1C @ 0x080C4A1C
void sub_080C4A1C(u16 n, u16 layer, u16 prio, u16 x, u16 y)
{
    sub_080C4938(n, layer, 6, prio, x, y);
}

// sub_080C4A4C @ 0x080C4A4C
void sub_080C4A4C(u16 layer, u16 prio, u16 x, u16 y)
{
    if (gMainCallback != sub_080D977C)
        Sprite_Draw(gUnknown_08000FF0, layer, 0, prio, 0, x, y);
    else
        Sprite_Draw(gUnknown_08008660, layer, 0, prio, 0x100, x, y);
}

// sub_080C4AB0 @ 0x080C4AB0
void sub_080C4AB0(u16 layer, u16 prio, u16 x, u16 y)
{
    if (gMainCallback != sub_080D977C)
        Sprite_Draw(gUnknown_08001000, layer, 0, prio, 0, x, y);
    else
        Sprite_Draw(gUnknown_08008670, layer, 0, prio, 0x100, x, y);
}

// sub_080C4B14 @ 0x080C4B14
void sub_080C4B14(u16 layer, u16 prio, u16 x, u16 y)
{
    if (gMainCallback != sub_080D977C)
        Sprite_Draw(gUnknown_0800108C, layer, 0, prio, 0, x, y);
    else
        Sprite_Draw(gUnknown_0800876C, layer, 0, prio, 0x100, x, y);
}

// sub_080C4B78 @ 0x080C4B78
void sub_080C4B78(u16 layer, u16 prio, u16 x, u16 y)
{
    if (gMainCallback != sub_080D977C)
        Sprite_Draw(gUnknown_0800109C, layer, 0, prio, 0, x, y);
    else
        Sprite_Draw(gUnknown_08008750, layer, 0, prio, 0x100, x, y);
}

// sub_080C4BDC @ 0x080C4BDC
u32 sub_080C4BDC(void)
{
    return 0;
}

// sub_080C4BE0 @ 0x080C4BE0
void sub_080C4BE0(void)
{
}

// sub_080C4BE4 @ 0x080C4BE4
void sub_080C4BE4(u32 bit)
{
    gGameState.unkAC8 |= 1 << bit;
}

// sub_080C4C00 @ 0x080C4C00
/* Computes the mask with the bit cleared but never stores it (compare sub_080C4BE4). */
u16 sub_080C4C00(u32 bit)
{
    u32 mask = 1 << bit;

    return gGameState.unkAC8 & ~mask;
}
