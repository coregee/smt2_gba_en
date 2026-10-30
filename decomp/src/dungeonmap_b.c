#include "global.h"
#include "status.h"

// MarkerHeader_DrawLocationName @ 0x080C8B7C
/* Draws the name of the player's location, at most 16 glyphs (0x57 ends it), 'step' pixels
   apart. */
void MarkerHeader_DrawLocationName(u16 a1, u16 a2, u16 x, u16 y, u16 step)
{
    u16 *name = Location_GetNameCellFromCoords(gMapId, gUnk_03004514, gFieldState.x, gFieldState.y);
    u32 i = 0;

    goto check;
loop:
    FontSprite_DrawGlyph(*name, a1, a2, x, y);
    name++;
    x += step;
    if (++i > 15)
        return;
check:
    if (*name != 0x57)
        goto loop;
}

// MarkerList_DrawLocationName @ 0x080C8BFC
/* Draws the name of the location at (map, floor, cx, cy), at most 16 glyphs 12 pixels apart. */
void MarkerList_DrawLocationName(u16 map, u16 floor, u16 cx, u16 cy, u16 a1, u16 a2, u16 x, u16 y)
{
    u16 *name = Location_GetNameCellFromCoords(map, floor, cx, cy);
    u32 i = 0;

    goto check;
loop:
    FontSprite_DrawGlyph(*name, a1, a2, x, y);
    name++;
    x += 12;
    if (++i > 15)
        return;
check:
    if (*name != 0x57)
        goto loop;
}

// sub_080C8C78 @ 0x080C8C78
/* Fades palettes 13-15 from the current dungeon palettes. */
void sub_080C8C78(void)
{
    const u16 *src = gUnk_03004630;

    gPaletteTarget[0] = *src;
    Palette_CopyWithEffect(3, src, &gPaletteTarget[0xE0], 0x40, 0x20);
    Palette_CopyWithEffect(3, gUnk_03004510, &gPaletteTarget[0xD0], 0x20, 0x20);
    PalFade_Setup(gUnk_0203A3E8, 0xD0, 0x30, 3);
    gUnk_0203A3E8->duration = 0x20;
}

// sub_080C8CD4 @ 0x080C8CD4
/* Same with the alternative palette set i. */
void sub_080C8CD4(u32 i)
{
    const u16 *a = gUnk_03004630;
    const u16 *b = gUnk_03004510;

    b += i * 16;
    a += i * 32;
    Palette_CopyWithEffect(3, b, &gPaletteTarget[0xD0], 0x20, 0x20);
    Palette_CopyWithEffect(3, a, &gPaletteTarget[0xE0], 0x40, 0x20);
    PalFade_Setup(gUnk_0203A3E8, 0xD0, 0x30, 3);
    gUnk_0203A3E8->duration = 0x20;
}

// sub_080C8D30 @ 0x080C8D30
/* Cycles the dungeon palettes through four sets, one fade at a time. */
void sub_080C8D30(void)
{
    u16 *state = &gUnk_030045B4;

    if (PalFade_AllDone() == 0)
        return;
    if (gUnk_0200AB04 & 0x8000)
        return;
    if (Palette_IsBg13Black() == 1)
        return;
    if (gUnk_0203A3E8->active)
    {
        PalFade_Update(gUnk_0203A3E8);
        return;
    }
    switch (*state)
    {
    case 0:
        sub_080C8C78();
        (*state)++;
        break;
    case 1:
        sub_080C8CD4(0);
        (*state)++;
        break;
    case 2:
        sub_080C8C78();
        (*state)++;
        break;
    case 3:
        sub_080C8CD4(1);
        (*state)++;
        break;
    case 4:
        sub_080C8C78();
        (*state)++;
        break;
    case 5:
        sub_080C8CD4(2);
        (*state)++;
        break;
    case 6:
        sub_080C8C78();
        (*state)++;
        break;
    case 7:
        sub_080C8CD4(3);
        *state = 0;
        break;
    }
}

// sub_080C8E00 @ 0x080C8E00
void sub_080C8E00(void)
{
    Flag_Set(0x108);
}

// sub_080C8E10 @ 0x080C8E10
/* Enables the H-blank interrupt. */
void sub_080C8E10(void)
{
    REG_IE |= 2;
    REG_DISPSTAT |= 0x10;
}

// sub_080C8E30 @ 0x080C8E30
void sub_080C8E30(void)
{
    REG_IE &= ~2;
    REG_DISPSTAT &= ~0x10;
    gIntrTable[1] = IntrDummy;
}

#define COPY16(d, s)                                                        {                                                                               *d++ = *s++; *d++ = *s++; *d++ = *s++; *d++ = *s++;                         *d++ = *s++; *d++ = *s++; *d++ = *s++; *d++ = *s++;                         *d++ = *s++; *d++ = *s++; *d++ = *s++; *d++ = *s++;                         *d++ = *s++; *d++ = *s++; *d++ = *s++; *d++ = *s++;                     }

// sub_080C8E64 @ 0x080C8E64
/* H-blank handler: flickers colours 0xD1-0xE0 between gUnknown_083D8F78 and the buffer. */
#ifdef NONMATCHING
void sub_080C8E64(void)
{
    u16 *dst = (u16 *)(PLTT + 0x1A2);

    if (Random_Byte() & 1)
    {
        const u16 *src = gUnknown_083D8F78;

        COPY16(dst, src);
    }
    else
    {
        const u16 *buf = gPaletteBuffer;

        buf += 0xD1;

        COPY16(dst, buf);
    }
}
#else
NAKED
void sub_080C8E64(void)
{
    asm_unified(
        "    push {r4, lr}\n"
        "    ldr r4, .L080C8EF0\n"
        "    bl Random_Byte\n"
        "    movs r1, #1\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080C8EF8\n"
        "    ldr r0, .L080C8EF4\n"
        "    ldrh r1, [r0]\n"
        "    strh r1, [r4]\n"
        "    adds r0, #2\n"
        "    adds r4, #2\n"
        "    ldrh r1, [r0]\n"
        "    strh r1, [r4]\n"
        "    adds r0, #2\n"
        "    adds r4, #2\n"
        "    ldrh r1, [r0]\n"
        "    strh r1, [r4]\n"
        "    adds r0, #2\n"
        "    adds r4, #2\n"
        "    ldrh r1, [r0]\n"
        "    strh r1, [r4]\n"
        "    adds r0, #2\n"
        "    adds r4, #2\n"
        "    ldrh r1, [r0]\n"
        "    strh r1, [r4]\n"
        "    adds r0, #2\n"
        "    adds r4, #2\n"
        "    ldrh r1, [r0]\n"
        "    strh r1, [r4]\n"
        "    adds r0, #2\n"
        "    adds r4, #2\n"
        "    ldrh r1, [r0]\n"
        "    strh r1, [r4]\n"
        "    adds r0, #2\n"
        "    adds r4, #2\n"
        "    ldrh r1, [r0]\n"
        "    strh r1, [r4]\n"
        "    adds r0, #2\n"
        "    adds r4, #2\n"
        "    ldrh r1, [r0]\n"
        "    strh r1, [r4]\n"
        "    adds r0, #2\n"
        "    adds r4, #2\n"
        "    ldrh r1, [r0]\n"
        "    strh r1, [r4]\n"
        "    adds r0, #2\n"
        "    adds r4, #2\n"
        "    ldrh r1, [r0]\n"
        "    strh r1, [r4]\n"
        "    adds r0, #2\n"
        "    adds r4, #2\n"
        "    ldrh r1, [r0]\n"
        "    strh r1, [r4]\n"
        "    adds r0, #2\n"
        "    adds r4, #2\n"
        "    ldrh r1, [r0]\n"
        "    strh r1, [r4]\n"
        "    adds r0, #2\n"
        "    adds r4, #2\n"
        "    ldrh r1, [r0]\n"
        "    strh r1, [r4]\n"
        "    adds r0, #2\n"
        "    adds r4, #2\n"
        "    ldrh r1, [r0]\n"
        "    strh r1, [r4]\n"
        "    ldrh r0, [r0, #2]\n"
        "    b .L080C8F76\n"
        "    .byte 0x00, 0x00\n"
        ".L080C8EF0: .4byte 0x050001A2 @ PLTT+0x1A2\n"
        ".L080C8EF4: .4byte gUnknown_083D8F78\n"
        ".L080C8EF8:\n"
        "    ldr r1, .L080C8F80\n"
        "    movs r0, #0xd1\n"
        "    lsls r0, r0, #1\n"
        "    adds r1, r1, r0\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r4]\n"
        "    adds r1, #2\n"
        "    adds r4, #2\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r4]\n"
        "    adds r1, #2\n"
        "    adds r4, #2\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r4]\n"
        "    adds r1, #2\n"
        "    adds r4, #2\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r4]\n"
        "    adds r1, #2\n"
        "    adds r4, #2\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r4]\n"
        "    adds r1, #2\n"
        "    adds r4, #2\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r4]\n"
        "    adds r1, #2\n"
        "    adds r4, #2\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r4]\n"
        "    adds r1, #2\n"
        "    adds r4, #2\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r4]\n"
        "    adds r1, #2\n"
        "    adds r4, #2\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r4]\n"
        "    adds r1, #2\n"
        "    adds r4, #2\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r4]\n"
        "    adds r1, #2\n"
        "    adds r4, #2\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r4]\n"
        "    adds r1, #2\n"
        "    adds r4, #2\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r4]\n"
        "    adds r1, #2\n"
        "    adds r4, #2\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r4]\n"
        "    adds r1, #2\n"
        "    adds r4, #2\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r4]\n"
        "    adds r1, #2\n"
        "    adds r4, #2\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r4]\n"
        "    ldrh r0, [r1, #2]\n"
        ".L080C8F76:\n"
        "    strh r0, [r4, #2]\n"
        "    pop {r4}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080C8F80: .4byte 0x03002DB0 @ IWRAM+0x2DB0\n"
    );
}
#endif

// sub_080C8F84 @ 0x080C8F84
void sub_080C8F84(void)
{
    gIntrTable[1] = sub_080C8E64;
    VBlankTask_AddCountedAlways(sub_080C8E10, 1);
    Palette_MarkDirty();
}

// sub_080C8FA8 @ 0x080C8FA8
void sub_080C8FA8(void)
{
    VBlankTask_AddCountedAlways(sub_080C8E30, 1);
    Palette_MarkDirty();
}

// sub_080C8FC0 @ 0x080C8FC0
void sub_080C8FC0(void)
{
    const u16 *src = gUnk_03004630;

    gPaletteTarget[0] = *src;
    Palette_CopyWithEffect(3, src, &gPaletteTarget[0xE0], 0x40, 0x20);
    Palette_CopyWithEffect(3, gUnk_03004510, &gPaletteTarget[0xD0], 0x20, 0x20);
    PalFade_Setup(gUnk_0203A3E8, 0xD0, 0x30, 8);
    gUnk_0203A3E8->duration = 0x20;
}

// sub_080C901C @ 0x080C901C
void sub_080C901C(u16 i)
{
    const u16 *a = gUnk_03004630;
    const u16 *b = gUnk_03004510;

    b += i * 16;
    a += i * 32;
    Palette_CopyWithEffect(3, b, &gPaletteTarget[0xD0], 0x20, 0x20);
    Palette_CopyWithEffect(3, a, &gPaletteTarget[0xE0], 0x40, 0x20);
    PalFade_Setup(gUnk_0203A3E8, 0xD0, 0x30, 3);
    gUnk_0203A3E8->duration = 0x20;
}

// sub_080C907C @ 0x080C907C
void sub_080C907C(void)
{
}

// sub_080C9080 @ 0x080C9080
u32 sub_080C9080(void)
{
    return 0;
}

// FieldEvent_FindAt @ 0x080C9084
/* Finds the field event at map square (x, y) facing dir in gUnknown_084EDE54 (ended by
   0xFFFF); stores its id (or 0xFFFF) in *id. */
struct C0c2FieldEvent *FieldEvent_FindAt(u16 x, u16 y, u16 dir, u16 *id)
{
    const struct C0c6EventSpot *spot = gUnknown_084EDE54;
    u16 bx, by;

    sub_080C1F50(x, y, &bx, &by);
    for (;;)
    {
        u16 d = ((spot->yd >> 5) & 6) >> 1;

        if (spot->x == 0xFFFF)
        {
            *id = 0xFFFF;
            return NULL;
        }
        if (spot->x == bx && (spot->yd & 0x3F) == by && d == dir)
        {
            *id = spot->id;
            return (struct C0c2FieldEvent *)spot;
        }
        spot++;
    }
}

// sub_080C90F4 @ 0x080C90F4
u32 sub_080C90F4(void)
{
    return 1;
}

// sub_080C90F8 @ 0x080C90F8
u32 sub_080C90F8(void)
{
    return 1;
}

// sub_080C90FC @ 0x080C90FC
void sub_080C90FC(void)
{
}
