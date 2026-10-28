#include "global.h"
#include "field.h"

// sub_080AD608 @ 0x080AD608
u16 sub_080AD608(u16 unused0, u16 unused1)
{
    u16 x, y;
    u8 idx;

    sub_080C1F50(gFieldState.unk12, gFieldState.unk14, &x, &y);
    idx = gUnknown_0815EFB4[(x >> 2) + (y >> 2) * 32];
    return sub_080C5E44(gUnknown_0815F1B4[idx]);
}

// sub_080AD658 @ 0x080AD658
void sub_080AD658(void)
{
    sub_080C5170(sub_080AD608(gUnk_03004614, gUnk_03004514));
}

// sub_080AD67C @ 0x080AD67C
u16 sub_080AD67C(u16 id)
{
    u16 i;
    const struct FlagTextEntry *entry;

    for (i = 0; gUnknown_087DF93C[i] != id; i++)
        ;
    entry = &gUnknown_0815F214[i];
    return sub_080C5E44(Flag_Test(entry->flag) ? entry->ifSet : entry->ifClear);
}

// sub_080AD6C8 @ 0x080AD6C8
void sub_080AD6C8(void)
{
    sub_080C5170(sub_080AD67C(gUnk_030069F0[4]));
}

// sub_080AD6E4 @ 0x080AD6E4
void sub_080AD6E4(u16 a)
{
    s32 r = FieldMap_FindRecord(FieldMap_CellRecordsRel(0, 0), 0x21);

    if (r == 0)
    {
        gFieldState.unk32 = a;
        Field_SetState(0x10);
        gFieldState.unk1E = r;
        if (gFieldState.unk50 == 1)
            gFieldState.unk50 = 2;
        if (a == 0)
            sub_080C51D4(0x65);
    }
    else
    {
        gFieldState.unk32 = a;
        Task_Create(gUnknown_08165598, 0xFFFF);
        Field_SetState(0x1A);
        gFieldState.unk1E = 0;
    }
}

// sub_080AD750 @ 0x080AD750
bool32 sub_080AD750(void)
{
    s32 r = View_GetWall(0, 0, 0);

    return r == 2 || r == 3;
}

// sub_080AD76C @ 0x080AD76C
void sub_080AD76C(void)
{
    u16 x = sub_080C5E58();

    if (x != 0xFFFF)
        sub_080B6568(x);
}

// Field_SetState @ 0x080AD78C
void Field_SetState(u16 state)
{
    gFieldState.unk00 = state;
    if (state == 1 && sub_080AD750() == TRUE)
        sub_080AD76C();
    if (state == 0x10)
    {
        gAutomapScroll = 0;
        gUnk_0200DFCE = 0;
        gUnk_0200DFD0 = 0;
    }
    if (state == 3)
        sub_080B3878(0);
    gUnk_03003FF4 = 0;
}

// Field_GetState @ 0x080AD7E4
u16 Field_GetState(void)
{
    return gFieldState.unk00;
}

// sub_080AD7F0 @ 0x080AD7F0
void sub_080AD7F0(void)
{
    gUnk_03003FF8 = 1;
}

// sub_080AD7FC @ 0x080AD7FC
u32 sub_080AD7FC(void)
{
    return gUnk_03003FF8;
}

// sub_080AD808 @ 0x080AD808
void sub_080AD808(struct Task *task)
{
    if (sub_080AD7FC())
        task->result = 0;
    else
        task->result = 1;
}

/* Loads a map's graphics one piece per call (called every frame while *step != 0):
   clears and decompresses the tile/tilemap buffers in EWRAM, then the palettes.
   *step goes 1..39, then 0 when done; steps 37-39 repeat until sub_080B6F40 != 1. */
// Map_LoadGraphicsStep @ 0x080AD824
void Map_LoadGraphicsStep(u16 map, u16 sub, s32 *step)
{
    struct MapVariant *v = &sub_080C8B10(map, sub)->variants[gGameState.unkA38];
    u32 zero1, zero9, zero15, zero22, zero26, zero32;
    u32 zero36;
    const u8 *p;

    if (*step == 0)
        return;

    switch (*step)
    {
    case 1:
        zero1 = 0;
        CpuSet(&zero1, (void *)0x0200F874, 0x05002000);
        if (v->data[0x18] != NULL)
            LZ77UnCompWram(v->data[0x18], (void *)0x0200F874);
        break;
    case 2:
        if (v->data[0x19] != NULL)
            LZ77UnCompWram(v->data[0x19], (void *)0x02010874);
        break;
    case 3:
        if (v->data[0x1A] != NULL)
            LZ77UnCompWram(v->data[0x1A], (void *)0x02011874);
        break;
    case 4:
        if (v->data[0x1B] != NULL)
            LZ77UnCompWram(v->data[0x1B], (void *)0x02012874);
        break;
    case 5:
        if (v->data[0x1C] != NULL)
            LZ77UnCompWram(v->data[0x1C], (void *)0x02013874);
        break;
    case 6:
        if (v->data[0x1D] != NULL)
            LZ77UnCompWram(v->data[0x1D], (void *)0x02014874);
        break;
    case 7:
        if (v->data[0x1E] != NULL)
            LZ77UnCompWram(v->data[0x1E], (void *)0x02015874);
        break;
    case 8:
        if (v->data[0x1F] != NULL)
            LZ77UnCompWram(v->data[0x1F], (void *)0x02016874);
        break;
    case 9:
        zero9 = 0;
        CpuSet(&zero9, (void *)0x02017874, 0x05001800);
        if (v->data[0x20] != NULL)
            LZ77UnCompWram(v->data[0x20], (void *)0x02017874);
        break;
    case 10:
        if (v->data[0x21] != NULL)
            LZ77UnCompWram(v->data[0x21], (void *)0x02018874);
        break;
    case 11:
        if (v->data[0x22] != NULL)
            LZ77UnCompWram(v->data[0x22], (void *)0x02019874);
        break;
    case 12:
        if (v->data[0x23] != NULL)
            LZ77UnCompWram(v->data[0x23], (void *)0x0201A874);
        break;
    case 13:
        if (v->data[0x24] != NULL)
            LZ77UnCompWram(v->data[0x24], (void *)0x0201B874);
        break;
    case 14:
        if (v->data[0x25] != NULL)
            LZ77UnCompWram(v->data[0x25], (void *)0x0201C874);
        break;
    case 15:
        zero15 = 0;
        CpuSet(&zero15, (void *)0x0201D874, 0x05001A00);
        if (v->data[0] != NULL)
            LZ77UnCompWram(v->data[0], (void *)0x0201D874);
        break;
    case 16:
        if (v->data[1] != NULL)
            LZ77UnCompWram(v->data[1], (void *)0x0201E874);
        break;
    case 17:
        if (v->data[2] != NULL)
            LZ77UnCompWram(v->data[2], (void *)0x0201F874);
        break;
    case 18:
        if (v->data[3] != NULL)
            LZ77UnCompWram(v->data[3], (void *)0x02020874);
        break;
    case 19:
        if (v->data[4] != NULL)
            LZ77UnCompWram(v->data[4], (void *)0x02021874);
        break;
    case 20:
        if (v->data[5] != NULL)
            LZ77UnCompWram(v->data[5], (void *)0x02022874);
        break;
    case 21:
        if (v->data[6] != NULL)
            LZ77UnCompWram(v->data[6], (void *)0x02023874);
        break;
    case 22:
        zero22 = 0;
        CpuSet(&zero22, (void *)0x02024074, 0x05001000);
        if (v->data[8] != NULL)
            LZ77UnCompWram(v->data[8], (void *)0x02024074);
        break;
    case 23:
        if (v->data[9] != NULL)
            LZ77UnCompWram(v->data[9], (void *)0x02025074);
        break;
    case 24:
        if (v->data[10] != NULL)
            LZ77UnCompWram(v->data[10], (void *)0x02026074);
        break;
    case 25:
        if (v->data[11] != NULL)
            LZ77UnCompWram(v->data[11], (void *)0x02027074);
        break;
    case 26:
        zero26 = 0;
        CpuSet(&zero26, (void *)0x02028074, 0x05001600);
        if (v->data[0x28] != NULL)
            LZ77UnCompWram(v->data[0x28], (void *)0x02028074);
        break;
    case 27:
        if (v->data[0x29] != NULL)
            LZ77UnCompWram(v->data[0x29], (void *)0x02029074);
        break;
    case 28:
        if (v->data[0x2A] != NULL)
            LZ77UnCompWram(v->data[0x2A], (void *)0x0202A074);
        break;
    case 29:
        if (v->data[0x2B] != NULL)
            LZ77UnCompWram(v->data[0x2B], (void *)0x0202B074);
        break;
    case 30:
        if (v->data[0x2C] != NULL)
            LZ77UnCompWram(v->data[0x2C], (void *)0x0202C074);
        break;
    case 31:
        if (v->data[0x2D] != NULL)
            LZ77UnCompWram(v->data[0x2D], (void *)0x0202D074);
        break;
    case 32:
        zero32 = 0;
        CpuSet(&zero32, (void *)0x0202D874, 0x05000D00);
        if (v->data[0x10] != NULL)
            LZ77UnCompWram(v->data[0x10], (void *)0x0202D874);
        break;
    case 33:
        if (v->data[0x11] != NULL)
            LZ77UnCompWram(v->data[0x11], (void *)0x0202E874);
        break;
    case 34:
        if (v->data[0x12] != NULL)
            LZ77UnCompWram(v->data[0x12], (void *)0x0202F874);
        break;
    case 35:
        if (v->data[0x13] != NULL)
            LZ77UnCompWram(v->data[0x13], (void *)0x02030874);
        break;
    case 36:
        zero36 = 0;
        FIELD_DMA3_SET(&zero36, 0x02030C74, 0x85001500);
        gUnk_03004604 = (void *)0x0202D874;
        sub_080B6F28(gUnknown_0815F264);
        break;
    case 37:
        p = gUnknown_0815F264;
        goto wait;
    case 38:
        p = gUnknown_0815F280;
    wait:
        if (sub_080B6F40(p) == 1)
            (*step)--;
        else
            sub_080B6F28(p + 0x1C);
        break;
    case 39:
        if (sub_080B6F40(gUnknown_0815F29C) == 1)
            (*step)--;
        else
            gUnk_03003FCC = (void *)0x02030C74;
        break;
    default:
        *step = 0;
        return;
    }
    (*step)++;
}

/* Points the field's graphics pointers at the buffers Map_LoadGraphicsStep fills and at the map's
   palettes; map 0x1A uses other palette rows until flag 0x11 is set. */
// Map_SetGraphicsPointers @ 0x080ADCCC
#ifdef NONMATCHING
void Map_SetGraphicsPointers(u32 map, u32 sub)
{
    struct MapVariant *v = &sub_080C8B10(map, sub)->variants[gGameState.unkA38];
    const u16 *pal;

    gUnk_03003FC0 = (void *)0x0201D874;
    gUnk_03003BB0 = (void *)0x02024074;
    gUnk_03004604 = (void *)0x0202D874;
    gUnk_03003BB4 = v->data[0x10];
    gUnk_03003B90 = (void *)0x0200F874;
    gUnk_03004620 = (void *)0x02017874;
    if (map == 0x1A && Flag_Test(0x11) == 0)
        pal = (const u16 *)v->data[0x30] + 0x40;
    else
        pal = v->data[0x30];
    gUnk_03004510 = pal;
    gUnk_03003B94 = (void *)0x02028074;
    gUnk_0300462C = v->data[0x28];
    if (map == 0x1A && Flag_Test(0x11) == 0)
        pal = (const u16 *)v->data[0x31] + 0x80;
    else
        pal = v->data[0x31];
    gUnk_03004630 = pal;
    gUnk_0300461C = v->data[0x33];
    gUnk_03003FE4 = v->data[0x35];
    gUnk_03003FE8 = v->data[0x37];
    if (map == 0x1A && Flag_Test(0x11) == 0)
        pal = (const u16 *)v->data[0x32] + 0x40;
    else
        pal = v->data[0x32];
    gUnk_03003FC8 = pal;
    Palette_CopyDarkened(gUnk_03004510, gUnk_0200F7F4, 0x10);
    Palette_CopyDarkened(gUnk_03004630, gUnk_0200F814, 0x20);
    Palette_CopyDarkened(gUnk_03003FC8, gUnk_0200F854, 0x10);
}
#else
NAKED
void Map_SetGraphicsPointers(u32 map, u32 sub)
{
    asm_unified(
        ".L080ADCCC:\n"
        "    push {r4, r5, lr}\n"
        "    adds r5, r0, #0\n"
        "    lsls r0, r5, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    bl sub_080C8B10\n"
        "    ldr r1, .L080ADD2C\n"
        "    ldr r2, .L080ADD30\n"
        "    adds r1, r1, r2\n"
        "    ldrh r2, [r1]\n"
        "    movs r1, #0xe8\n"
        "    muls r1, r2, r1\n"
        "    adds r1, #0x98\n"
        "    adds r4, r0, r1\n"
        "    ldr r1, .L080ADD34\n"
        "    ldr r0, .L080ADD38\n"
        "    str r0, [r1]\n"
        "    ldr r1, .L080ADD3C\n"
        "    ldr r0, .L080ADD40\n"
        "    str r0, [r1]\n"
        "    ldr r1, .L080ADD44\n"
        "    ldr r0, .L080ADD48\n"
        "    str r0, [r1]\n"
        "    ldr r1, .L080ADD4C\n"
        "    ldr r0, [r4, #0x40]\n"
        "    str r0, [r1]\n"
        "    ldr r1, .L080ADD50\n"
        "    ldr r0, .L080ADD54\n"
        "    str r0, [r1]\n"
        "    ldr r1, .L080ADD58\n"
        "    ldr r0, .L080ADD5C\n"
        "    str r0, [r1]\n"
        "    cmp r5, #0x1a\n"
        "    bne .L080ADD64\n"
        "    movs r0, #0x11\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L080ADD64\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0xc0\n"
        "    ldr r1, [r0]\n"
        "    adds r1, #0x80\n"
        "    ldr r0, .L080ADD60\n"
        "    b .L080ADD6C\n"
        "    .byte 0x00, 0x00\n"
        ".L080ADD2C: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080ADD30: .4byte 0x00000A38\n"
        ".L080ADD34: .4byte 0x03003FC0 @ IWRAM+0x3FC0\n"
        ".L080ADD38: .4byte 0x0201D874 @ EWRAM+0x1D874\n"
        ".L080ADD3C: .4byte 0x03003BB0 @ IWRAM+0x3BB0\n"
        ".L080ADD40: .4byte 0x02024074 @ EWRAM+0x24074\n"
        ".L080ADD44: .4byte 0x03004604 @ IWRAM+0x4604\n"
        ".L080ADD48: .4byte 0x0202D874 @ EWRAM+0x2D874\n"
        ".L080ADD4C: .4byte 0x03003BB4 @ IWRAM+0x3BB4\n"
        ".L080ADD50: .4byte 0x03003B90 @ IWRAM+0x3B90\n"
        ".L080ADD54: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L080ADD58: .4byte 0x03004620 @ IWRAM+0x4620\n"
        ".L080ADD5C: .4byte 0x02017874 @ EWRAM+0x17874\n"
        ".L080ADD60: .4byte 0x03004510 @ IWRAM+0x4510\n"
        ".L080ADD64:\n"
        "    ldr r0, .L080ADD9C\n"
        "    adds r1, r4, #0\n"
        "    adds r1, #0xc0\n"
        "    ldr r1, [r1]\n"
        ".L080ADD6C:\n"
        "    str r1, [r0]\n"
        "    ldr r1, .L080ADDA0\n"
        "    ldr r0, .L080ADDA4\n"
        "    str r0, [r1]\n"
        "    ldr r1, .L080ADDA8\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0xa0\n"
        "    ldr r0, [r0]\n"
        "    str r0, [r1]\n"
        "    cmp r5, #0x1a\n"
        "    bne .L080ADDB0\n"
        "    movs r0, #0x11\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L080ADDB0\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0xc4\n"
        "    ldr r1, [r0]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    adds r1, r1, r0\n"
        "    ldr r0, .L080ADDAC\n"
        "    b .L080ADDB8\n"
        ".L080ADD9C: .4byte 0x03004510 @ IWRAM+0x4510\n"
        ".L080ADDA0: .4byte 0x03003B94 @ IWRAM+0x3B94\n"
        ".L080ADDA4: .4byte 0x02028074 @ EWRAM+0x28074\n"
        ".L080ADDA8: .4byte 0x0300462C @ IWRAM+0x462C\n"
        ".L080ADDAC: .4byte 0x03004630 @ IWRAM+0x4630\n"
        ".L080ADDB0:\n"
        "    ldr r0, .L080ADDF4\n"
        "    adds r1, r4, #0\n"
        "    adds r1, #0xc4\n"
        "    ldr r1, [r1]\n"
        ".L080ADDB8:\n"
        "    str r1, [r0]\n"
        "    ldr r1, .L080ADDF8\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0xcc\n"
        "    ldr r0, [r0]\n"
        "    str r0, [r1]\n"
        "    ldr r1, .L080ADDFC\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0xd4\n"
        "    ldr r0, [r0]\n"
        "    str r0, [r1]\n"
        "    ldr r1, .L080ADE00\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0xdc\n"
        "    ldr r0, [r0]\n"
        "    str r0, [r1]\n"
        "    cmp r5, #0x1a\n"
        "    bne .L080ADE08\n"
        "    movs r0, #0x11\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L080ADE08\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0xc8\n"
        "    ldr r1, [r0]\n"
        "    adds r1, #0x80\n"
        "    ldr r0, .L080ADE04\n"
        "    b .L080ADE10\n"
        "    .byte 0x00, 0x00\n"
        ".L080ADDF4: .4byte 0x03004630 @ IWRAM+0x4630\n"
        ".L080ADDF8: .4byte 0x0300461C @ IWRAM+0x461C\n"
        ".L080ADDFC: .4byte 0x03003FE4 @ IWRAM+0x3FE4\n"
        ".L080ADE00: .4byte 0x03003FE8 @ IWRAM+0x3FE8\n"
        ".L080ADE04: .4byte 0x03003FC8 @ IWRAM+0x3FC8\n"
        ".L080ADE08:\n"
        "    ldr r0, .L080ADE3C\n"
        "    adds r1, r4, #0\n"
        "    adds r1, #0xc8\n"
        "    ldr r1, [r1]\n"
        ".L080ADE10:\n"
        "    str r1, [r0]\n"
        "    ldr r0, .L080ADE40\n"
        "    ldr r0, [r0]\n"
        "    ldr r1, .L080ADE44\n"
        "    movs r2, #0x10\n"
        "    bl Palette_CopyDarkened\n"
        "    ldr r0, .L080ADE48\n"
        "    ldr r0, [r0]\n"
        "    ldr r1, .L080ADE4C\n"
        "    movs r2, #0x20\n"
        "    bl Palette_CopyDarkened\n"
        "    ldr r0, .L080ADE3C\n"
        "    ldr r0, [r0]\n"
        "    ldr r1, .L080ADE50\n"
        "    movs r2, #0x10\n"
        "    bl Palette_CopyDarkened\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080ADE3C: .4byte 0x03003FC8 @ IWRAM+0x3FC8\n"
        ".L080ADE40: .4byte 0x03004510 @ IWRAM+0x4510\n"
        ".L080ADE44: .4byte 0x0200F7F4 @ EWRAM+0xF7F4\n"
        ".L080ADE48: .4byte 0x03004630 @ IWRAM+0x4630\n"
        ".L080ADE4C: .4byte 0x0200F814 @ EWRAM+0xF814\n"
        ".L080ADE50: .4byte 0x0200F854 @ EWRAM+0xF854\n"
    );
}
#endif

/* Copies count palette colors to dst (DMA) and darkens each channel of dst by 18
   (23 on map 0x4D), clamping at 0. */
// Palette_CopyDarkened @ 0x080ADE54
void Palette_CopyDarkened(const u16 *src, u16 *dst, u16 count)
{
    u16 dark = 18;
    u32 i;
    s32 size = count * 2;

    FIELD_DMA3_SET(src, dst, 0x84000000 | (size / 4));
    if (gUnk_03004614 == 0x4D)
        dark = 23;
    for (i = 0; i < count; i++, dst++)
    {
        u16 c = *dst;

        if ((c & 0x1F) >= dark)
            c -= dark;
        else
            c &= 0xFFE0;
        if ((c & 0x3E0) >= (dark << 5))
            c -= dark << 5;
        else
            c &= 0xFC1F;
        if ((c & 0x7C00) >= (dark << 10))
            c -= dark << 10;
        else
            c &= 0x83FF;
        *dst = c;
    }
}

// sub_080ADF14 @ 0x080ADF14
bool32 sub_080ADF14(u16 map)
{
    s32 i = 0;

    while (1)
    {
        if (gUnknown_0815F2B8[i] == 0xFFFF)
            return FALSE;
        if (gUnknown_0815F2B8[i] == map)
            return TRUE;
        i++;
    }
}

// sub_080ADF40 @ 0x080ADF40
bool32 sub_080ADF40(void)
{
    bool32 ret = FALSE;

    if (gUnk_03004614 == 0x4A && gUnk_03004514 == 4)
        ret = TRUE;
    return ret;
}

/* Loads the BG tiles at VRAM 0x06003000 that depend on the map. */
// sub_080ADF64 @ 0x080ADF64
void sub_080ADF64(void)
{
    if (sub_080ADF14(gUnk_03004614) == TRUE)
        FIELD_DMA3_SET(gUnknown_081C2270, 0x06003000, 0x84000140)
    else if (sub_080ADF40() == TRUE)
        FIELD_DMA3_SET(gUnknown_0848DE60, 0x06003000, 0x84000140)
    else
        FIELD_DMA3_SET(gUnknown_081C0A70, 0x06003000, 0x84000200)
    gUnk_0300000E = 0;
}

// sub_080ADFEC @ 0x080ADFEC
void sub_080ADFEC(u16 mode)
{
    vu32 zero;

    Map_SetGraphicsPointers(gUnk_03004614, gUnk_03004514);
    zero = 0;
    FIELD_DMA3_SET(&zero, 0x02028074, 0x85000008);
    FIELD_DMA3_SET(gUnk_03003B94, 0x06004000, 0x84000800);
    {
        const u16 *pal = gUnk_03004630;
        gPaletteTarget[0] = pal[0];
        Palette_CopyWithEffect(3, pal, &gPaletteTarget[0xE0], 0x40, 0x20);
    }
    Palette_CopyWithEffect(3, gUnk_03004510, &gPaletteTarget[0xD0], 0x20, 0x20);
    sub_080ADF64();
    sub_080AE1C4();
    Palette_CopyWithEffect(3, gUnk_03003FC8, &gPaletteTarget[0x1D0], 0x20, 0x10);
    if (mode == 2 || mode == 3)
        BgPicture_LoadAll();
}

/* sub_080ADFEC spread over frames: one step per call, gFieldLoadStep = 0xFFFF when done. */
// Field_LoadGraphicsStep @ 0x080AE0BC
void Field_LoadGraphicsStep(void)
{
    vu32 zero;

    switch (gFieldLoadStep)
    {
    case 0:
        zero = 0;
        FIELD_DMA3_SET(&zero, 0x02028074, 0x85000008);
        FIELD_DMA3_SET(gUnk_03003B94, 0x06004000, 0x84000800);
        break;
    case 1:
    {
        const u16 *pal = gUnk_03004630;
        gPaletteTarget[0] = pal[0];
        Palette_CopyWithEffect(3, pal, &gPaletteTarget[0xE0], 0x40, 0x20);
        break;
    }
    case 2:
        Palette_CopyWithEffect(3, gUnk_03004510, &gPaletteTarget[0xD0], 0x20, 0x20);
        break;
    case 3:
        sub_080ADF64();
        break;
    case 4:
        sub_080AE1C4();
        break;
    case 5:
        Palette_CopyWithEffect(3, gUnk_03003FC8, &gPaletteTarget[0x1D0], 0x20, 0x10);
    default:
        gFieldLoadStep = 0xFFFF;
        return;
    }
    gFieldLoadStep++;
}

// sub_080AE1C4 @ 0x080AE1C4
void sub_080AE1C4(void)
{
    if (gUnk_0300461C != NULL)
        LZ77UnCompWram(gUnk_0300461C, (void *)0x0200AFC8);
    FIELD_DMA3_SET(0x0200AFC8, 0x06015000, 0x84000400);
}

// sub_080AE1FC @ 0x080AE1FC
void sub_080AE1FC(void)
{
    if (gUnk_03003FE4 != NULL)
        LZ77UnCompWram(gUnk_03003FE4, (void *)0x0200AFC8);
    FIELD_DMA3_SET(0x0200AFC8, 0x06015000, 0x84000400);
}

// sub_080AE234 @ 0x080AE234
void sub_080AE234(void)
{
    const u16 *p = sub_080C8B10(gUnk_03004614, gUnk_03004514)->unk90;
    u32 zero1, zero2;

    gFieldState.unk1A = *p++;
    gFieldState.unk1C = *p++;
    gFieldState.unk20 = p;
    zero1 = 0;
    CpuSet(&zero1, gFieldState.unk64, 0x05000010);
    zero2 = 0;
    CpuSet(&zero2, gUnk_0203A3E8, 0x05000014);
}

// sub_080AE294 @ 0x080AE294
void sub_080AE294(void)
{
    sub_080F3F58(-0x11);
    sub_080C2230(0);
}

// Field_SetPosition @ 0x080AE2A8
void Field_SetPosition(u16 x, u16 y)
{
    gFieldState.unk12 = x;
    gFieldState.unk16 = x;
    gFieldState.unk14 = y;
    gFieldState.unk18 = y;
}

// Field_SavePrevPosition @ 0x080AE2C0
void Field_SavePrevPosition(void)
{
    gFieldState.unk16 = gFieldState.unk12;
    gFieldState.unk18 = gFieldState.unk14;
}

// sub_080AE2D0 @ 0x080AE2D0
void sub_080AE2D0(void)
{
    u32 zero1, zero2;

    zero1 = 0;
    CpuSet(&zero1, (void *)0x02036074, 0x05000008);
    zero2 = 0;
    CpuSet(&zero2, (void *)0x02036094, 0x05000008);
}

// sub_080AE304 @ 0x080AE304
void sub_080AE304(void)
{
    sub_080B2840(0, 0, 0);
    do
        sub_080B2CC0();
    while (gFieldState.unk0E != 0);
    sub_080AE494(sub_080B2880);
}

/* Copies two ARM routines to IWRAM (0x400 and 0x500 bytes). */
// Field_CopyIwramCode @ 0x080AE330
void Field_CopyIwramCode(void)
{
    CpuSet(FieldView_BlitPixels, gUnk_03003BC0, 0x04000100);
    CpuSet(FieldView_BlitTiles, gUnk_03004010, 0x04000140);
}

/* Field start-up. Modes 0 (new game), 4 and 6 reset the field state; mode 0 starts at
   (0, 0) facing 0, the others at the position saved in gUnk_03003FD0. */
// sub_080AE364 @ 0x080AE364
void sub_080AE364(u16 mode)
{
    gUnk_03003B9C = 0;
    gUnk_03004608 = 0;
    sub_080AE2D0();
    Field_CopyIwramCode();
    if (mode == 0 || mode == 4 || mode == 6)
    {
        vu32 zero = 0;

        FIELD_DMA3_SET(&zero, &gFieldState, 0x85000000 | (sizeof(gFieldState) / 4));
        sub_080AE234();
        if (mode == 0)
        {
            Field_SetPosition(0, 0);
            gFieldState.unk02 = mode;
            gFieldState.unk04 = mode;
            sub_080B30A0(gUnk_03004614);
        }
        else
        {
            Field_SetPosition(gUnk_03003FD0[2], gUnk_03003FD0[3]);
            gFieldState.unk02 = gUnk_03003FD0[4];
            gFieldState.unk04 = gFieldState.unk02;
        }
        if (FieldMap_HasRecordRel(0, 0, 6) == 1)
        {
            const u16 *pal = gUnk_0200F814;

            gPaletteTarget[0] = pal[0];
            Palette_CopyWithEffect(3, pal, &gPaletteTarget[0xE0], 0x40, 0x20);
            Palette_CopyWithEffect(3, gUnk_0200F7F4, &gPaletteTarget[0xD0], 0x20, 0x20);
            Palette_CopyWithEffect(3, gUnk_0200F854, &gPaletteTarget[0x1D0], 0x20, 0x10);
        }
        Automap_SetVisited(gFieldState.unk12, gFieldState.unk14);
        Automap_SetVisitedAhead(gFieldState.unk12, gFieldState.unk14, gFieldState.unk02);
        gUnk_030045FC = 1;
        gFieldState.unk00 = 10;
        sub_080AE304();
        sub_080C20C8();
        sub_080C67C0(gPaletteTarget, 7);
    }
    else
    {
        gFieldState.unk00 = 10;
    }
}

// sub_080AE494 @ 0x080AE494
void sub_080AE494(void (*func)(void))
{
    VBlankTask_AddCounted(func, 1);
    gFieldState.unk0C = 1;
}

/* Fills view cell [row][col] from map square (x, y): the four 2-bit wall codes of the
   square rotated to the facing direction gFieldState.unk02. Outside the map the cell
   is marked empty. */
// View_FillCell @ 0x080AE4AC
void View_FillCell(u16 x, u16 y, u16 col, u16 row)
{
    if ((s16)x < 0 || x >= gFieldState.unk1A || (s16)y < 0 || y >= gFieldState.unk1C)
    {
        gViewCells[row][col].valid = FALSE;
    }
    else
    {
        u16 dir = gFieldState.unk02;
        u16 square = gFieldState.unk20[y * gFieldState.unk1A + x];
        u32 i;

        for (i = 0; i < 4; i++)
        {
            gViewCells[row][col].walls[i] = (square >> gUnknown_0815F2E6[dir]) & 3;
            dir = (dir + 1) & 3;
        }
        gViewCells[row][col].valid = TRUE;
    }
}
