#include "global.h"
#include "status.h"

// sub_080C8440 @ 0x080C8440
void sub_080C8440(void)
{
    DmaCopy32(3, gUnk_0200E8D8, (void *)0x06012000, 0xF00);
}

// sub_080C8464 @ 0x080C8464
/* Sets whether member slot shows its alternative (status) face, and reloads the face. */
void sub_080C8464(s16 slot, u16 alt)
{
    gHud->altFace[slot] = alt;
    Hud_LoadMemberFace(slot);
}

// sub_080C8480 @ 0x080C8480
void sub_080C8480(s32 slot)
{
    sub_080C8464(slot, 1);
}

// sub_080C8490 @ 0x080C8490
void sub_080C8490(s32 slot)
{
    sub_080C8464(slot, 0);
}

// sub_080C84A0 @ 0x080C84A0
void sub_080C84A0(void)
{
    u16 i;

    for (i = 0; i < 6; i++)
        sub_080C8464(i, 0);
}

// sub_080C84C0 @ 0x080C84C0
void sub_080C84C0(void)
{
    u16 i;

    for (i = 0; i < 6; i++)
        sub_080C8464(i, 1);
}

// Hud_GetStatusFace @ 0x080C84E0
/* The face of party slot 'slot' from its status bits: 0 normal, 1 dead (humans), 2 dying or
   below a quarter of its HP, other values per ailment. */
s16 Hud_GetStatusFace(s16 slot)
{
    struct Combatant *c = Party_GetMember(slot);
    u16 flags;
    u16 hp;
    u16 maxHp;
    u16 who;

    if (c == NULL)
        return 0;
    flags = c->flags;
    hp = c->hp;
    maxHp = c->maxHp;
    who = gGameState.order[slot];
    if ((s16)who <= 15)
    {
        if (flags & 0x8000)
            return 1;
    }
    else if (flags & 0x8000)
        return 2;
    if ((s16)who > 15 && (s16)hp < (s16)maxHp >> 2)
        return 2;
    if (flags & 0x2000)
        return 4;
    if (flags & 0x1000)
        return 5;
    if (flags & 0x4)
        return 0x10;
    if (flags & 0x800)
        return 6;
    if (flags & 0x400)
        return 8;
    if (flags & 0x4000)
        return 3;
    if (flags & 0x1)
        return 0x12;
    if (flags & 0x200)
        return 9;
    if (flags & 0x40)
        return 0xC;
    if (flags & 0x20)
        return 0xD;
    if (flags & 0x100)
        return 0xA;
    if (flags & 0x80)
        return 0xB;
    if (flags & 0x2)
        return 0x11;
    if (flags & 0x10)
        return 0xE;
    if (flags & 0x8)
        return 0xF;
    if ((s16)who <= 15 && (s16)hp < (s16)maxHp >> 2)
        return 2;
    return 0;
}

// Hud_GetAltFace @ 0x080C8624
/* The alternative face of party slot 'slot' by sub_080C35E4, or -1. */
s16 Hud_GetAltFace(s16 slot)
{
    struct Combatant *c = Party_GetMember(slot);
    u16 flags;
    u16 kind;

    if (c == NULL)
        return -1;
    flags = c->flags;
    kind = sub_080C35E4(gGameState.order[slot]);
    if (flags & 0xB1E0)
        return -1;
    if ((s16)kind == 4)
        return 0x13;
    if ((s16)kind == 5)
        return 0x14;
    if ((s16)kind == 0xA)
        return 0x15;
    if ((s16)kind == 6)
        return 0x1A;
    if ((s16)kind == 7)
        return 0x16;
    if ((s16)kind == 8)
        return 0x1B;
    if ((s16)kind == 9)
        return 0x18;
    if ((s16)kind == 0xB)
        return 0x17;
    if ((s16)kind == 0xC)
        return 0x19;
    return -1;
}

// Hud_GetMemberFace @ 0x080C86B4
s16 Hud_GetMemberFace(s16 slot)
{
    u16 face;

    if (gHud->altFace[slot] == 0 || (s16)(face = Hud_GetAltFace(slot)) == -1)
        face = Hud_GetStatusFace(slot);
    return face;
}

// sub_080C86F4 @ 0x080C86F4
void sub_080C86F4(u16 slot)
{
    gHud->unk48[slot] = 8;
    gHud->unk54[slot] = 0xFFFE;
}

// sub_080C8718 @ 0x080C8718
/* One step of a palette fade of colour 0x111 through row d->row of gUnknown_081B70D0; the
   task result becomes 1 after the 7th step. */
#ifdef NONMATCHING
void sub_080C8718(struct Task *t)
{
    struct C0c6CursorData *d = (struct C0c6CursorData *)t->data.raw;

    const u16 *color = (const u16 *)(((d->kind << 5) + ((d->step + 1) << 1)) + (const u8 *)gUnknown_081B70D0);

    Palette_FillWithEffect(3, *color, &gPaletteBuffer[0x111], 2, 0x20);
    Palette_MarkDirty();
    d->step += 2;
    if (d->step > 14)
        t->result = 1;
    else
        t->result = 0;
}
#else
NAKED
void sub_080C8718(struct Task *t)
{
    asm_unified(
        ".L080C8718:\n"
        "    push {r4, r5, lr}\n"
        "    sub sp, #4\n"
        "    adds r5, r0, #0\n"
        "    adds r4, r5, #0\n"
        "    adds r4, #0x24\n"
        "    ldrh r1, [r4, #2]\n"
        "    lsls r1, r1, #5\n"
        "    ldrh r0, [r4, #4]\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #1\n"
        "    adds r1, r1, r0\n"
        "    ldr r0, .L080C8758\n"
        "    adds r1, r1, r0\n"
        "    ldr r2, .L080C875C\n"
        "    ldrh r1, [r1]\n"
        "    movs r0, #0x20\n"
        "    str r0, [sp]\n"
        "    movs r0, #3\n"
        "    movs r3, #2\n"
        "    bl Palette_FillWithEffect\n"
        "    bl Palette_MarkDirty\n"
        "    ldrh r0, [r4, #4]\n"
        "    adds r0, #2\n"
        "    strh r0, [r4, #4]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #0xe\n"
        "    bls .L080C8760\n"
        "    movs r0, #1\n"
        "    b .L080C8762\n"
        ".L080C8758: .4byte gUnknown_081B70D0\n"
        ".L080C875C: .4byte 0x03002FD2 @ IWRAM+0x2FD2\n"
        ".L080C8760:\n"
        "    movs r0, #0\n"
        ".L080C8762:\n"
        "    strh r0, [r5, #0x1c]\n"
        "    add sp, #4\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

// sub_080C876C @ 0x080C876C
void sub_080C876C(void)
{
    DmaCopy32(3, gUnknown_081B3F10, (void *)0x06015000, 0x1000);
}

// sub_080C8790 @ 0x080C8790
void sub_080C8790(struct Task *t)
{
    VBlankTask_AddCounted(sub_080C876C, 1);
    sub_080C8718(t);
}

// sub_080C87AC @ 0x080C87AC
#ifdef NONMATCHING
void sub_080C87AC(struct Task *t)
{
    struct C0c6CursorData *d = (struct C0c6CursorData *)t->data.raw;
    u16 x = ((const u16 (*)[2])gUnknown_0834A750)[d->pos][0];
    u16 y = ((const u16 (*)[2])gUnknown_0834A750)[d->pos][1];

    if (d->kind == 0)
        Sprite_Draw(gUnknown_080013DC, 9, 0, 1, 0x280, x, y);
    else if (d->kind == 1)
        Sprite_Draw(gUnknown_0800143C, 9, 0, 1, 0x280, x, y);
    else if (d->kind == 2)
        Sprite_Draw(gUnknown_08001424, 9, 0, 1, 0x280, x, y);
    else if (d->kind == 3)
        Sprite_Draw(gUnknown_08001454, 9, 0, 1, 0x280, x, y);
}
#else
NAKED
void sub_080C87AC(struct Task *t)
{
    asm_unified(
        "    push {r4, r5, lr}\n"
        "    sub sp, #0xc\n"
        "    ldr r3, .L080C87D0\n"
        "    ldrh r1, [r0, #0x24]\n"
        "    lsls r1, r1, #2\n"
        "    adds r2, r1, r3\n"
        "    ldrh r4, [r2]\n"
        "    adds r5, r4, #0\n"
        "    adds r3, #2\n"
        "    adds r1, r1, r3\n"
        "    ldrh r2, [r1]\n"
        "    adds r3, r2, #0\n"
        "    ldrh r0, [r0, #0x26]\n"
        "    cmp r0, #0\n"
        "    bne .L080C87D8\n"
        "    ldr r0, .L080C87D4\n"
        "    b .L080C87EA\n"
        "    .byte 0x00, 0x00\n"
        ".L080C87D0: .4byte gUnknown_0834A750\n"
        ".L080C87D4: .4byte gUnknown_080013DC\n"
        ".L080C87D8:\n"
        "    cmp r0, #1\n"
        "    bne .L080C87E4\n"
        "    ldr r0, .L080C87E0\n"
        "    b .L080C87EA\n"
        ".L080C87E0: .4byte gUnknown_0800143C\n"
        ".L080C87E4:\n"
        "    cmp r0, #2\n"
        "    bne .L080C8804\n"
        "    ldr r0, .L080C8800\n"
        ".L080C87EA:\n"
        "    movs r1, #0xa0\n"
        "    lsls r1, r1, #2\n"
        "    str r1, [sp]\n"
        "    str r4, [sp, #4]\n"
        "    str r2, [sp, #8]\n"
        "    movs r1, #9\n"
        "    movs r2, #0\n"
        "    movs r3, #1\n"
        "    bl Sprite_Draw\n"
        "    b .L080C881E\n"
        ".L080C8800: .4byte gUnknown_08001424\n"
        ".L080C8804:\n"
        "    cmp r0, #3\n"
        "    bne .L080C881E\n"
        "    ldr r0, .L080C8828\n"
        "    movs r1, #0xa0\n"
        "    lsls r1, r1, #2\n"
        "    str r1, [sp]\n"
        "    str r5, [sp, #4]\n"
        "    str r3, [sp, #8]\n"
        "    movs r1, #9\n"
        "    movs r2, #0\n"
        "    movs r3, #1\n"
        "    bl Sprite_Draw\n"
        ".L080C881E:\n"
        "    add sp, #0xc\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080C8828: .4byte gUnknown_08001454\n"
    );
}
#endif

// sub_080C882C @ 0x080C882C
/* Task wait: result 1 after d->limit frames. */
void sub_080C882C(struct Task *t)
{
    struct C0c6CursorData *d = (struct C0c6CursorData *)t->data.raw;

    t->result = 0;
    if (d->count >= d->limit)
    {
        t->result = 1;
        d->count = 0;
        d->limit = 0;
    }
    else
        d->count++;
}

// sub_080C8858 @ 0x080C8858
struct Task *sub_080C8858(u16 pos, u16 kind, u8 limit)
{
    struct Task *t = Task_Create(gUnknown_0834A768, 0xFFFF);
    struct C0c6CursorData *d = (struct C0c6CursorData *)t->data.raw;

    d->pos = pos;
    d->kind = kind;
    d->limit = limit;
    d->count = 0;
    return t;
}

// sub_080C8890 @ 0x080C8890
struct Task *sub_080C8890(u16 pos, u8 limit)
{
    return sub_080C8858(pos, 0, limit);
}

// sub_080C88A8 @ 0x080C88A8
struct Task *sub_080C88A8(u16 pos, u8 limit)
{
    return sub_080C8858(pos, 1, limit);
}

// sub_080C88C0 @ 0x080C88C0
struct Task *sub_080C88C0(u16 pos, u8 limit)
{
    return sub_080C8858(pos, 2, limit);
}

// sub_080C88D8 @ 0x080C88D8
struct Task *sub_080C88D8(u16 pos, u8 limit)
{
    return sub_080C8858(pos, 3, limit);
}

// sub_080C88F0 @ 0x080C88F0
u32 sub_080C88F0(u16 *p)
{
    u32 r = 0;

    if (*p == 0)
        r = 1;
    return r;
}

// sub_080C8904 @ 0x080C8904
#ifdef NONMATCHING
void sub_080C8904(struct Task *t)
{
    struct C0c6CursorData *d = (struct C0c6CursorData *)t->data.raw;
    u16 x = gUnknown_0834A750[d->pos].x;
    u16 y = gUnknown_0834A750[d->pos].y;

    if (d->kind == 0)
    {
        Sprite_Draw(gUnknown_080013F4, 9, 0, 1, 0x280, x - 4, y);
        Sprite_Draw(gUnknown_080013DC, 9, 2, 1, 0x293, x, y);
    }
    else
    {
        Sprite_Draw(gUnknown_0800140C, 9, 0, 1, 0x280, x - 4, y);
        Sprite_Draw(gUnknown_080013DC, 9, 4, 1, 0x280, x, y);
    }
}
#else
NAKED
void sub_080C8904(struct Task *t)
{
    asm_unified(
        "    push {r4, r5, r6, lr}\n"
        "    sub sp, #0xc\n"
        "    ldr r3, .L080C8950\n"
        "    ldrh r1, [r0, #0x24]\n"
        "    lsls r1, r1, #2\n"
        "    adds r2, r1, r3\n"
        "    ldrh r6, [r2]\n"
        "    adds r3, #2\n"
        "    adds r1, r1, r3\n"
        "    ldrh r5, [r1]\n"
        "    ldrh r0, [r0, #0x26]\n"
        "    cmp r0, #0\n"
        "    bne .L080C8960\n"
        "    ldr r0, .L080C8954\n"
        "    movs r1, #0xa0\n"
        "    lsls r1, r1, #2\n"
        "    str r1, [sp]\n"
        "    subs r1, r6, #4\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #4]\n"
        "    str r5, [sp, #8]\n"
        "    movs r1, #9\n"
        "    movs r2, #0\n"
        "    movs r3, #1\n"
        "    bl Sprite_Draw\n"
        "    ldr r0, .L080C8958\n"
        "    ldr r1, .L080C895C\n"
        "    str r1, [sp]\n"
        "    str r6, [sp, #4]\n"
        "    str r5, [sp, #8]\n"
        "    movs r1, #9\n"
        "    movs r2, #2\n"
        "    movs r3, #1\n"
        "    bl Sprite_Draw\n"
        "    b .L080C898E\n"
        ".L080C8950: .4byte gUnknown_0834A750\n"
        ".L080C8954: .4byte gUnknown_080013F4\n"
        ".L080C8958: .4byte gUnknown_080013DC\n"
        ".L080C895C: .4byte 0x00000293\n"
        ".L080C8960:\n"
        "    ldr r0, .L080C8998\n"
        "    movs r4, #0xa0\n"
        "    lsls r4, r4, #2\n"
        "    str r4, [sp]\n"
        "    subs r1, r6, #4\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #4]\n"
        "    str r5, [sp, #8]\n"
        "    movs r1, #9\n"
        "    movs r2, #0\n"
        "    movs r3, #1\n"
        "    bl Sprite_Draw\n"
        "    ldr r0, .L080C899C\n"
        "    str r4, [sp]\n"
        "    str r6, [sp, #4]\n"
        "    str r5, [sp, #8]\n"
        "    movs r1, #9\n"
        "    movs r2, #4\n"
        "    movs r3, #1\n"
        "    bl Sprite_Draw\n"
        ".L080C898E:\n"
        "    add sp, #0xc\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080C8998: .4byte gUnknown_0800140C\n"
        ".L080C899C: .4byte gUnknown_080013DC\n"
    );
}
#endif

// sub_080C89A0 @ 0x080C89A0
/* Moves the cursor over a 3x2 grid (0-2 top row, 3-5 bottom row); A stores the position in
   gUnk_030037F0, A or B ends (result 1). */
void sub_080C89A0(struct Task *t)
{
    struct C0c6CursorData *d = (struct C0c6CursorData *)t->data.raw;
    u16 keys = gKeysNew;

    t->result = 0;
    if (d->locked != 0)
        return;
    if (keys & 1)
    {
        gUnk_030037F0 = d->pos;
        t->result = 1;
    }
    if (keys & 2)
    {
        t->result = 1;
        return;
    }
    if (keys & 0x10)
    {
        if (d->pos == 2)
            d->pos = 0;
        else if (d->pos == 5)
            d->pos = 3;
        else
            d->pos++;
    }
    else if (keys & 0x20)
    {
        if (d->pos == 0)
            d->pos = 2;
        else if (d->pos == 3)
            d->pos = 5;
        else
            d->pos--;
    }
    else if (keys & 0x80)
    {
        if (d->pos == 3)
            d->pos = 0;
        else if (d->pos == 4)
            d->pos = 1;
        else if (d->pos == 5)
            d->pos = 2;
        else
            d->pos += 3;
    }
    else if (keys & 0x40)
    {
        if (d->pos == 0)
            d->pos = 3;
        else if (d->pos == 1)
            d->pos = 4;
        else if (d->pos == 2)
            d->pos = 5;
        else
            d->pos -= 3;
    }
}

// sub_080C8A78 @ 0x080C8A78
struct Task *sub_080C8A78(u16 locked, u16 kind, u16 pos)
{
    struct Task *t = Task_Create(gUnknown_0834A7C4, 0xFFFF);
    struct C0c6CursorData *d = (struct C0c6CursorData *)t->data.raw;

    d->kind = kind;
    d->pos = pos;
    d->locked = locked;
    return t;
}

// sub_080C8AAC @ 0x080C8AAC
struct Task *sub_080C8AAC(u16 locked, u16 pos)
{
    return sub_080C8A78(locked, 0, pos);
}

// sub_080C8AC4 @ 0x080C8AC4
struct Task *sub_080C8AC4(u16 locked, u16 pos)
{
    return sub_080C8A78(locked, 1, pos);
}

// sub_080C8ADC @ 0x080C8ADC
void sub_080C8ADC(struct Task *t, u16 v)
{
    t->pad1E = v;
}

// sub_080C8AE0 @ 0x080C8AE0
u32 sub_080C8AE0(u16 *p)
{
    u32 r = 0;

    if (*p == 0)
        r = 1;
    return r;
}

// sub_080C8AF4 @ 0x080C8AF4
u16 sub_080C8AF4(struct Task *t)
{
    return t->data.h[0];
}

// sub_080C8AF8 @ 0x080C8AF8
/* Whether the HUD panels may slide on this map: always (both branches return 1). */
u32 sub_080C8AF8(u16 map)
{
    if (gGameState.unkAC0 == 1)
        return 1;
    return 1;
}

// DungeonMap_GetFloor @ 0x080C8B10
struct MapHeader *DungeonMap_GetFloor(u16 map, u16 floor)
{
    u8 *p = gDungeonMaps[map].floors;

    if (p != NULL)
        p += floor * 0x268;
    return (struct MapHeader *)p;
}

// sub_080C8B3C @ 0x080C8B3C
u32 sub_080C8B3C(u16 map)
{
    return gDungeonMaps[map].unk4;
}

// sub_080C8B54 @ 0x080C8B54
struct C0c6MapInfo *sub_080C8B54(u16 map)
{
    struct C0c6MapInfo *info = (struct C0c6MapInfo *)&gDungeonMaps[map].info;

    if (info->unk0 == 0)
        return NULL;
    return info;
}
