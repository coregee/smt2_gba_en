#include "global.h"
#include "inventory.h"

// Party_FixFormation @ 0x080C366C
/* Moves back-row members forward into empty front slots, and swaps a dead or stoned front
   member (status 0xA000) with a healthy one behind. */
void Party_FixFormation(void)
{
    u8 buf[6];
    u32 i;

    for (i = 0; i < 6; i++)
        buf[i] |= 0xFF;
    for (i = 0; i < 6; i++)
        buf[i] = gGameState.order[i];
    for (i = 0; i < 3; i++)
    {
        s8 front = buf[i];
        s8 back = buf[i + 3];

        if (front == -1)
        {
            if (back != front)
            {
                buf[i] = back;
                buf[i + 3] = 0xFF;
            }
        }
        else if (back >= 0 && (Combatant_GetStatus(front) & 0xA000)
                 && !(Combatant_GetStatus(back) & 0xA000))
        {
            buf[i] = back;
            buf[i + 3] = front;
        }
    }
    for (i = 0; i < 6; i++)
        gGameState.order[i] = buf[i];
    Party_BuildMemberNameTiles();
    sub_080C6FD8();
}

// GfxSlot_Acquire @ 0x080C373C
/* Finds the slot already holding id (adding a user) or claims a free one; 0 if none. */
u32 GfxSlot_Acquire(struct Task *t, u16 id)
{
    u16 i;
    u16 start;

    for (i = 0; i < 8; i++)
    {
        if (gGfxSlots[i][0] != 0 && gGfxSlots[i][1] == id)
        {
            gGfxSlots[i][0]++;
            return i;
        }
    }
    start = (gCharTasks[6] != NULL);
    if (gCharTasks[7] != NULL)
        start++;
    for (i = start; i < 6; i++)

    {
        if (gGfxSlots[i][0] == 0)
        {
            gGfxSlots[i][0]++;
            gGfxSlots[i][1] = id;
            return i;
        }
    }
    return 0;
}

// CharTask_Register @ 0x080C37C0
void CharTask_Register(struct Task *t)
{
    u16 i;

    for (i = 0; i < 8; i++)
    {
        if (gCharTasks[i] == NULL)
        {
            gCharTasks[i] = t;
            return;
        }
    }
}

// CharTask_Unregister @ 0x080C37EC
void CharTask_Unregister(struct Task *t)
{
    u16 i;

    for (i = 0; i < 8; i++)
    {
        if (gCharTasks[i] == t)
        {
            gCharTasks[i] = NULL;
            return;
        }
    }
}

// sub_080C3818 @ 0x080C3818
void sub_080C3818(u16 mode)
{
    u32 i;

    if (mode == 0)
    {
        for (i = 0; i < 8; i++)
        {
            if (i - 6 <= 1)
            {
                if (gCharTasks[i] != NULL)
                {
                    sub_080E9044(gCharTasks[i], i - 6);
                    if (gUnk_030069C0[i - 6] != 0)
                        gUnk_030069C0[i - 6] = 0;
                    gCharTasks[i] = NULL;
                }
            }
            else
            {
                struct Task *t = gCharTasks[i];

                if ((u16)(((struct ObjData *)t->data.h)->id - 0x1C2) <= 1)
                    PalFade_FadeRangeToBlackTagged(0x1D0, 0x10, 1, 1);
                else if (t != NULL)
                    t->wait = 1;
            }
        }
    }
    else
    {
        for (i = 0; i < 8; i++)
        {
            if (i - 6 <= 1)
            {
                if (gCharTasks[i] != NULL)
                {
                    sub_080E9044(gCharTasks[i], i - 6);
                    gCharTasks[i] = NULL;
                }
            }
            else if (gCharTasks[i] != NULL)
            {
                CharObj_End(gCharTasks[i], 0);
            }
        }
    }
}

// GfxSlot_FindShared @ 0x080C38D4
u16 GfxSlot_FindShared(u16 id)
{
    u32 i;

    for (i = 0; i < 8; i++)
    {
        if (gGfxSlots[i][0] > 1 && gGfxSlots[i][1] == id)
            return i;
    }
    return 0xFFFF;
}

// sub_080C3910 @ 0x080C3910
void sub_080C3910(void)
{
    DmaCopy32(3, (void *)0x02001000, (void *)0x06016000, 0x1000);
}

// sub_080C3934 @ 0x080C3934
void sub_080C3934(void)
{
    DmaCopy32(3, (void *)0x02002000, (void *)0x06017000, 0x1000);
}

// sub_080C3958 @ 0x080C3958
void sub_080C3958(void)
{
    DmaCopy32(3, (void *)0x02003000, (void *)0x06015000, 0x1000);
}

// Demon_LoadGfxForTask @ 0x080C397C
/* step 0 Huffman-decodes a demon sprite half into 0x0200AFC8 + slot * 0x1000, step 1
   LZ77-expands it to 0x02001000 + slot * 0x1000, loads the palette and queues the DMA. */
void Demon_LoadGfxForTask(struct Task *t, u32 noPal, u32 half, u32 step)
{
    struct ObjData *d = (struct ObjData *)Task_GetParent(t)->data.raw;
    const struct DemonGfxRecord *rec = &gDemonGfxRecords[d->id];
    const void *src = rec->gfx[half][step];
    u16 slot = d->palSlot;

    if (d->hasPal == 0)
        return;
    if (slot == 0 || slot == 3)
    {
        if (step == 0)
            HuffUnComp(src, (void *)0x0200AFC8);
        else
            LZ77UnCompWram((void *)0x0200AFC8, (void *)0x02001000);
        if (step != 1)
            return;
        if (noPal == 0)
        {
            if (!Palette_IsBg13Black())
            {
                Palette_CopyWithEffect(3, rec->palette, &gPaletteTarget[0x1E0], 0x20, 0x20);
                Palette_CopyWithEffect(3, rec->palette, &gPaletteBuffer[0x1E0], 0x20, 0x20);
                Palette_MarkDirty();
            }
            else
            {
                Palette_CopyWithEffect(3, rec->palette, &gPaletteTarget[0x1E0], 0x20, 0x20);
                PalFade_FadeRangeInFromBlackTagged(0x1E0, 0x10, 1, 1);
            }
        }
        VBlankTask_AddCounted(sub_080C3910, 1);
    }
    else if (slot == 1)
    {
        if (step == 0)
            HuffUnComp(src, (void *)0x0200BFC8);
        else
            LZ77UnCompWram((void *)0x0200BFC8, (void *)0x02002000);
        if (step != 1)
            return;
        if (noPal == 0)
        {
            if (!Palette_IsBg13Black())
            {
                Palette_CopyWithEffect(3, rec->palette, &gPaletteTarget[0x1F0], 0x20, 0x20);
                Palette_CopyWithEffect(3, rec->palette, &gPaletteBuffer[0x1F0], 0x20, 0x20);
                Palette_MarkDirty();
            }
            else
            {
                Palette_CopyWithEffect(3, rec->palette, &gPaletteTarget[0x1F0], 0x20, 0x20);
                PalFade_FadeRangeInFromBlackTagged(0x1F0, 0x10, 1, 1);
            }
        }
        VBlankTask_AddCounted(sub_080C3934, 1);
    }
    else if (slot == 2)
    {
        if (step == 0)
            HuffUnComp(src, (void *)0x0200CFC8);
        else
            LZ77UnCompWram((void *)0x0200CFC8, (void *)0x02003000);
        if (step != 1)
            return;
        if (noPal == 0)
        {
            if (!Palette_IsBg13Black())
            {
                Palette_CopyWithEffect(3, rec->palette, &gPaletteTarget[0x1D0], 0x20, 0x20);
                Palette_CopyWithEffect(3, rec->palette, &gPaletteBuffer[0x1D0], 0x20, 0x20);
                Palette_MarkDirty();
            }
            else
            {
                Palette_CopyWithEffect(3, rec->palette, &gPaletteTarget[0x1D0], 0x20, 0x20);
                PalFade_FadeRangeInFromBlackTagged(0x1D0, 0x10, 1, 1);
            }
        }
        VBlankTask_AddCounted(sub_080C3958, 1);
    }
}

// sub_080C3B80 @ 0x080C3B80
void sub_080C3B80(struct Task *t)
{
    struct ObjData *d = (struct ObjData *)t->data.raw;
    u16 slot = d->palSlot;

    if (d->hasPal == 0)
        return;
    if (slot == 0 || slot == 3)
        PalFade_FadeRangeToBlackTagged(0x1E0, 0x10, 1, 1);
    else if (slot == 1)
        PalFade_FadeRangeToBlackTagged(0x1F0, 0x10, 1, 1);
    else if (slot == 2)
        PalFade_FadeRangeToBlackTagged(0x1D0, 0x10, 1, 1);
}

// sub_080C3BC4 @ 0x080C3BC4
void sub_080C3BC4(struct Task *t)
{
    struct ObjData *d = (struct ObjData *)t->data.raw;
    u16 slot = d->palSlot;
    const void *def = sub_080E8AA0(d->palSlot)->def;

    if (def == NULL)
        return;
    if (slot == 0 || slot == 3)
        Sprite_Draw(def, 1, 14, d->unk10, 0x300, d->x + 0x28, d->y + 0x58);
    else if (slot == 1)
        Sprite_Draw(def, 1, 15, d->unk10, 0x380, d->x + 0x28, d->y + 0x58);
    else if (slot == 2)
        Sprite_Draw(def, 1, 13, d->unk10, 0x280, d->x + 0x28, d->y + 0x58);
}

// sub_080C3C68 @ 0x080C3C68
void sub_080C3C68(struct Task *t)
{
    struct ObjData *d = (struct ObjData *)t->data.raw;
    u16 slot = d->palSlot;
    struct C0c2DemonSprite *s = sub_080E8AA0(slot);
    const struct DemonGfxRecord *rec;
    const void *def[2];
    const void *const *tbl;

    if (s->def == NULL)
        return;
    rec = Demon_GetGfxRecord(s->demonId);
    s->unk1 = 1;
    s->unk2 = 0;
    s->def = rec->anim->frames[0];
    tbl = gUnknown_08002C20;
    if (slot == 2)
        tbl = gUnknown_08002C58;
    def[0] = *(const void **)s->def;
    def[1] = tbl[1];
    sub_081583F4(def);
    tbl = gUnknown_08002C20;
    if (slot == 2)
        tbl = gUnknown_08002C58;
    def[0] = (const void *)0x03003800;
    def[1] = tbl[1];
    if (slot == 0)
        Sprite_DrawSharedAffine(def, 1, 14, d->unk10, 0x300, d->x - 0xD5, d->y + 0x88, slot);
    else if (slot == 1)
        Sprite_DrawSharedAffine(def, 1, 15, d->unk10, 0x380, d->x - 0xD9, d->y + 0x88, slot);
    else
        Sprite_DrawSharedAffine(def, 1, 13, d->unk10, 0x280, d->x - 0xD6, d->y + 0x88, 2);
}

// sub_080C3D5C @ 0x080C3D5C
void sub_080C3D5C(struct Task *t)
{
    u16 slot = ((struct ObjData *)Task_GetParent(t)->data.raw)->palSlot;

    t->result = 0;
    if ((u8)sub_080E88C0(slot))
        t->result = 1;
}

// DemonObj_Create @ 0x080C3D84
/* Creates a demon object task (gUnknown_081A647C) with its graphics slot and child task. */
#ifdef NONMATCHING
struct Task *DemonObj_Create(u16 a, u16 id, u16 x, u16 y, u16 e, u16 f)
{
    struct Task *t = Task_Create(gUnknown_081A647C, 0xFFFF);
    struct ObjData *d = (struct ObjData *)t->data.raw;
    const void *script;

    d->palSlot = GfxSlot_Acquire(t, id);
    CharTask_Register(t);
    d->unk00 = a;
    d->id = id;
    d->x = x;
    d->y = y;
    d->unk0C = e;
    d->unk0E = f;
    d->unk10 = 2;
    d->hasPal = 1;
    if (sub_080E8AC0(id) == 0xFFFF)
        script = gUnknown_081A631C;
    else
        script = gUnknown_081A6420;
    OBJ_CHILD(d) = Task_Create(script, t->id);
    sub_080E8A28(d->palSlot, id);
    return t;
}
#else
NAKED
struct Task *DemonObj_Create(u16 a, u16 id, u16 x, u16 y, u16 e, u16 f)
{
    asm_unified(
        ".L080C3D84:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #4\n"
        "    adds r4, r0, #0\n"
        "    adds r5, r2, #0\n"
        "    adds r6, r3, #0\n"
        "    ldr r0, [sp, #0x24]\n"
        "    ldr r2, [sp, #0x28]\n"
        "    mov sb, r2\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp]\n"
        "    lsls r5, r5, #0x10\n"
        "    lsrs r5, r5, #0x10\n"
        "    lsls r6, r6, #0x10\n"
        "    lsrs r6, r6, #0x10\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        "    mov r1, sb\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    mov sb, r1\n"
        "    ldr r0, .L080C3E08\n"
        "    ldr r1, .L080C3E0C\n"
        "    bl Task_Create\n"
        "    mov sl, r0\n"
        "    mov r7, sl\n"
        "    adds r7, #0x24\n"
        "    ldr r1, [sp]\n"
        "    bl GfxSlot_Acquire\n"
        "    strh r0, [r7, #2]\n"
        "    mov r0, sl\n"
        "    bl CharTask_Register\n"
        "    mov r2, sl\n"
        "    strh r4, [r2, #0x24]\n"
        "    mov r0, sp\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r7, #6]\n"
        "    strh r5, [r7, #8]\n"
        "    strh r6, [r7, #0xa]\n"
        "    mov r1, r8\n"
        "    strh r1, [r7, #0xc]\n"
        "    mov r2, sb\n"
        "    strh r2, [r7, #0xe]\n"
        "    movs r0, #2\n"
        "    strh r0, [r7, #0x10]\n"
        "    movs r0, #1\n"
        "    strh r0, [r7, #4]\n"
        "    ldr r0, [sp]\n"
        "    bl sub_080E8AC0\n"
        "    ldr r1, .L080C3E0C\n"
        "    cmp r0, r1\n"
        "    bne .L080C3E14\n"
        "    ldr r0, .L080C3E10\n"
        "    b .L080C3E16\n"
        "    .byte 0x00, 0x00\n"
        ".L080C3E08: .4byte gUnknown_081A647C\n"
        ".L080C3E0C: .4byte 0x0000FFFF\n"
        ".L080C3E10: .4byte gUnknown_081A631C\n"
        ".L080C3E14:\n"
        "    ldr r0, .L080C3E3C\n"
        ".L080C3E16:\n"
        "    mov r2, sl\n"
        "    ldrh r1, [r2, #2]\n"
        "    bl Task_Create\n"
        "    str r0, [r7, #0x14]\n"
        "    ldrb r0, [r7, #2]\n"
        "    ldr r1, [sp]\n"
        "    bl sub_080E8A28\n"
        "    mov r0, sl\n"
        "    add sp, #4\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L080C3E3C: .4byte gUnknown_081A6420\n"
    );
}
#endif

// sub_080C3E40 @ 0x080C3E40
void sub_080C3E40(struct Task *t, u16 v)
{
    t->data.h[8] = v;
}

// sub_080C3E44 @ 0x080C3E44
void sub_080C3E44(struct Task *t, u16 dx, u16 dy)
{
    struct ObjData *d = (struct ObjData *)t->data.raw;

    d->x += dx;
    d->y += dy;
}

// sub_080C3E5C @ 0x080C3E5C
void sub_080C3E5C(struct Task *t, u32 x, u32 y)
{
    struct ObjData *d = (struct ObjData *)t->data.raw;

    d->x = x;
    d->y = y;
}

// sub_080C3E64 @ 0x080C3E64
void sub_080C3E64(struct Task *t)
{
    struct ObjData *d = (struct ObjData *)t->data.raw;

    if (OBJ_CHILD(d) != NULL)
    {
        Task_End(OBJ_CHILD(d));
        OBJ_CHILD(d) = NULL;
    }
}

// DemonObj_End @ 0x080C3E80
void DemonObj_End(struct Task *t)
{
    struct ObjData *d = (struct ObjData *)t->data.raw;

    if (gGfxSlots[d->palSlot][0] != 0)
        gGfxSlots[d->palSlot][0]--;
    CharTask_Unregister(t);
    if (OBJ_CHILD(d) != NULL)
        Task_End(OBJ_CHILD(d));
    Task_End(t);
}

// sub_080C3EBC @ 0x080C3EBC
void sub_080C3EBC(void)
{
    DmaCopy32(3, (void *)0x02001000, (void *)0x06016000, 0x1000);
}

// sub_080C3EE0 @ 0x080C3EE0
void sub_080C3EE0(void)
{
    DmaCopy32(3, (void *)0x02002000, (void *)0x06017000, 0x1000);
}

// sub_080C3F04 @ 0x080C3F04
void sub_080C3F04(void)
{
    DmaCopy32(3, (void *)0x02003000, (void *)0x06015000, 0x1000);
}

// sub_080C3F28 @ 0x080C3F28
void sub_080C3F28(void)
{
    DmaCopy32(3, (void *)0x02004000, (void *)0x06012000, 0x1000);
}

// sub_080C3F4C @ 0x080C3F4C
/* Loads an object palette range: fade in from black, fade in from white (mode +0x1E), or a
   direct copy. With flag 0xFD set it writes the fade's delay even when no fade was started
   (f == NULL). */
void sub_080C3F4C(struct ObjData *mode, const void *pal, u32 start, u32 size, u32 fade)
{
    struct PalFade *f = NULL;

    if (!Palette_IsBg13Black())
    {
        if (mode->fadeIn != 0)
        {
            Palette_CopyWithEffect(3, pal, &gPaletteTarget[start], size, 0x20);
            if (fade == 1)
                f = PalFade_FadeRangeInFromBlack(start, size / 2, 3);
        }
        else if (mode->fadeWhite != 0)
        {
            Palette_CopyWithEffect(3, pal, &gPaletteTarget[start], size, 0x20);
            if (fade == 1)
            {
                f = PalFade_FadeRangeInFromBlack(start, size / 2, 3);
                Palette_FillWithEffect(3, 0x7FFF, &gPaletteBuffer[start], size, 0x10);
                Palette_MarkDirty();
            }
        }
        else
        {
            Palette_CopyWithEffect(3, pal, &gPaletteBuffer[start], size, 0x20);
            Palette_MarkDirty();
        }
    }
    else
    {
        Palette_CopyWithEffect(3, pal, &gPaletteTarget[start], size, 0x20);
        if (fade == 1)
            f = PalFade_FadeRangeInFromBlackTagged(start, size / 2, 1, 1);
    }
    if (f != NULL && Flag_Test(0x10E))
    {
        f->duration = 8;
        Flag_Clear(0x10E);
    }
    if (Flag_Test(0xFD))
    {
        f->delay = 10;
        f->timer = 10;
    }
}
