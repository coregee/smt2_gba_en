#include "global.h"
#include "worldmap.h"

/* Direction of the last step: 0 = up, then clockwise (1 = up-right ... 7 = up-left). */
// WorldMap_GetStepDirection @ 0x08153540
u16 WorldMap_GetStepDirection(void)
{
    u16 x = gWorldMap.x;
    u16 y = gWorldMap.y;
    u16 px = gWorldMap.unk10;
    u16 py = gWorldMap.unk12;

    if (x == px && y < py)
        return 0;
    if (x > px)
    {
        if (y < py)
            return 1;
        if (y == py)
            return 2;
        if (y > py)
            return 3;
    }
    if (x == px && y > py)
        return 4;
    if (x < px)
    {
        if (y > py)
            return 5;
        if (y == py)
            return 6;
        if (y < py)
            return 7;
    }
}

/* High nibbles (terrain) of the 8 blocks around the player, NW first, one per nibble. */
// WorldMap_GetNeighbourTerrain @ 0x081535A4
u32 WorldMap_GetNeighbourTerrain(void)
{
    struct FieldBlocks *map = WorldMap_GetBlocks();
    u16 bx = gWorldMap.x >> 4;
    u16 by = gWorldMap.y >> 4;
    u8 t[8];

    t[0] = map->walk[by - 1][bx - 1] >> 4;
    t[1] = map->walk[by - 1][bx] >> 4;
    t[2] = map->walk[by - 1][bx + 1] >> 4;
    t[3] = map->walk[by][bx + 1] >> 4;
    t[4] = map->walk[by + 1][bx + 1] >> 4;
    t[5] = map->walk[by + 1][bx] >> 4;
    t[6] = map->walk[by + 1][bx - 1] >> 4;
    t[7] = map->walk[by][bx - 1] >> 4;
    return t[0] + (t[1] << 4) + (t[2] << 8) + (t[3] << 12) + (t[4] << 16) + (t[5] << 20)
         + (t[6] << 24) + (t[7] << 28);
}

/* Battle background for an encounter here: looks up the terrain behind and ahead of the
   last step in the pair table. */
// WorldMap_GetEncounterTerrain @ 0x08153668
#ifdef NONMATCHING
u32 WorldMap_GetEncounterTerrain(void)
{
    struct MapRecord *rec = FieldMap_GetArea(gWorldMap.map);
    u32 terrain = WorldMap_GetNeighbourTerrain();
    u8 *ids = rec->padD0;
    u32 s, t;
    u32 a, b;
    u32 i;

    switch (WorldMap_GetStepDirection())
    {
    case 0:
        s = 0;
        t = 8;
        break;
    case 1:
        s = 4;
        t = 12;
        break;
    case 2:
        s = 8;
        t = 16;
        break;
    case 3:
        s = 12;
        t = 20;
        break;
    case 4:
        s = 16;
        t = 24;
        break;
    case 5:
        s = 20;
        t = 28;
        break;
    case 6:
        s = 24;
        t = 0;
        break;
    case 7:
        s = 28;
        t = 4;
        break;
    }
    a = (terrain >> s) & 0xF;
    b = (terrain >> t) & 0xF;
    if (a == 0)
        a = ids[0];
    else
        a = ids[a - 1];
    if (b == 0)
        b = ids[0];
    else
        b = ids[b - 1];
    for (i = 0; i < 0xAC; i++)
    {
        if (gUnknown_087E0188[i].a == a && gUnknown_087E0188[i].b == b)
            return gUnknown_087E0188[i].bg + 0xE0;
    }
    return 0;
}
#else
NAKED
u32 WorldMap_GetEncounterTerrain(void)
{
    asm_unified(
        ".L08153668:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    ldr r0, .L08153698\n"
        "    ldrh r0, [r0, #8]\n"
        "    bl FieldMap_GetArea\n"
        "    adds r4, r0, #0\n"
        "    bl WorldMap_GetNeighbourTerrain\n"
        "    mov r8, r0\n"
        "    adds r7, r4, #0\n"
        "    adds r7, #0xd0\n"
        "    bl WorldMap_GetStepDirection\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #7\n"
        "    bhi .L081536EE\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L0815369C\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        ".L08153698: .4byte 0x030069F0 @ IWRAM+0x69F0\n"
        ".L0815369C: .4byte gUnknown_081536A0\n"
        "    .global gUnknown_081536A0\n"
        "gUnknown_081536A0:\n"
        ".L081536A0: @ jump table\n"
        "    .4byte .L081536C0\n"
        "    .4byte .L081536C6\n"
        "    .4byte .L081536CC\n"
        "    .4byte .L081536D2\n"
        "    .4byte .L081536D8\n"
        "    .4byte .L081536DE\n"
        "    .4byte .L081536E4\n"
        "    .4byte .L081536EA\n"
        ".L081536C0:\n"
        "    movs r6, #0\n"
        "    movs r5, #8\n"
        "    b .L081536EE\n"
        ".L081536C6:\n"
        "    movs r6, #4\n"
        "    movs r5, #0xc\n"
        "    b .L081536EE\n"
        ".L081536CC:\n"
        "    movs r6, #8\n"
        "    movs r5, #0x10\n"
        "    b .L081536EE\n"
        ".L081536D2:\n"
        "    movs r6, #0xc\n"
        "    movs r5, #0x14\n"
        "    b .L081536EE\n"
        ".L081536D8:\n"
        "    movs r6, #0x10\n"
        "    movs r5, #0x18\n"
        "    b .L081536EE\n"
        ".L081536DE:\n"
        "    movs r6, #0x14\n"
        "    movs r5, #0x1c\n"
        "    b .L081536EE\n"
        ".L081536E4:\n"
        "    movs r6, #0x18\n"
        "    movs r5, #0\n"
        "    b .L081536EE\n"
        ".L081536EA:\n"
        "    movs r6, #0x1c\n"
        "    movs r5, #4\n"
        ".L081536EE:\n"
        "    mov r1, r8\n"
        "    lsrs r1, r6\n"
        "    movs r0, #0xf\n"
        "    ands r1, r0\n"
        "    mov r4, r8\n"
        "    lsrs r4, r5\n"
        "    ands r4, r0\n"
        "    cmp r1, #0\n"
        "    bne .L08153704\n"
        "    ldrb r1, [r7]\n"
        "    b .L0815370A\n"
        ".L08153704:\n"
        "    adds r0, r1, r7\n"
        "    subs r0, #1\n"
        "    ldrb r1, [r0]\n"
        ".L0815370A:\n"
        "    cmp r4, #0\n"
        "    bne .L08153718\n"
        "    ldrb r4, [r7]\n"
        "    b .L0815371E\n"
        ".L08153712:\n"
        "    ldrb r0, [r5, #2]\n"
        "    adds r0, #0xe0\n"
        "    b .L0815373C\n"
        ".L08153718:\n"
        "    adds r0, r4, r7\n"
        "    subs r0, #1\n"
        "    ldrb r4, [r0]\n"
        ".L0815371E:\n"
        "    movs r3, #0\n"
        "    ldr r2, .L08153748\n"
        "    adds r5, r2, #0\n"
        ".L08153724:\n"
        "    ldrb r0, [r2]\n"
        "    cmp r0, r1\n"
        "    bne .L08153730\n"
        "    ldrb r0, [r2, #1]\n"
        "    cmp r0, r4\n"
        "    beq .L08153712\n"
        ".L08153730:\n"
        "    adds r2, #4\n"
        "    adds r5, #4\n"
        "    adds r3, #1\n"
        "    cmp r3, #0xab\n"
        "    bls .L08153724\n"
        "    movs r0, #0\n"
        ".L0815373C:\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L08153748: .4byte gUnknown_087E0188\n"
    );
}
#endif

// WorldMap_CheckSpecialEncounter @ 0x0815374C
u32 WorldMap_CheckSpecialEncounter(void)
{
    struct MapRecord *rec = FieldMap_GetArea(gWorldMap.map);
    u16 x = (gWorldMap.x >> 4) + rec->originX;
    u16 y = (gWorldMap.y >> 4) + rec->originY;
    u32 i;

    if (Flag_Test(2) && Flag_Test(0x16))
    {
        for (i = 0; i < 26; i++)
        {
            if (x == gUnknown_087E043C[i][0] && y == gUnknown_087E043C[i][1] && Random_Byte() % 5 == 0)
                return 1;
        }
    }
    return 0;
}

// sub_081537C4 @ 0x081537C4
u32 sub_081537C4(void)
{
    if (Flag_Test(0x69) && Flag_Test(0x109))
    {
        if (gWorldMap.map == 5)
        {
            if (*(u32 *)&gWorldMap.x == 0x037001C8)
                return 1;
        }
        else if (gWorldMap.map == 6)
        {
            if (*(u32 *)&gWorldMap.x == 0x07800238)
                return 1;
        }
    }
    return 0;
}

// sub_08153810 @ 0x08153810
void sub_08153810(void)
{
    DMA3_SET(gUnk_02000000, 0x06001000, 0x84000200);
}

// sub_08153834 @ 0x08153834
void sub_08153834(void)
{
    DMA3_SET(gUnk_02001000, 0x0600E000, 0x84000200);
    sub_08153810();
}

// sub_08153860 @ 0x08153860
void sub_08153860(void)
{
    DmaFill16_3(0x3B3, 0x06001000, 0x81000400);
}

// sub_08153890 @ 0x08153890
void sub_08153890(void)
{
    LZ77UnCompWram(gUnknown_087E04A4, gUnk_02001000);
    LZ77UnCompWram(gUnknown_087E0788, gUnk_02000000);
    Tilemap_OffsetRect(gUnk_02000000, 0x300, 7, 0, 0, 32, 32);
    Palette_CopyWithEffect(3, gUnknown_087E0978, &gPaletteTarget[0x70], 0x20, 0x20);
    PalFade_FadeRangeInFromBlack(0x70, 0x10, 4);
    PalFade_FadeRangeToBlackWithDuration(0x80, 0x80, 4, 8);
    PalFade_FadeRangeToBlackWithDuration(0x1D0, 0x30, 4, 8);
    gUnk_03000004 = 0xFFCC;
    gUnk_03000006 = 0xFFF0;
    VBlankTask_AddCounted(sub_08153834, 1);
}

// sub_08153938 @ 0x08153938
void sub_08153938(void)
{
    DmaFill16_3(0, 0x06002000, 0x81000800);
    DmaFill16_3(0, 0x06003000, 0x81000800);
}

// sub_08153974 @ 0x08153974
void sub_08153974(struct Task *task)
{
    u32 r = Flag_Test(0x109);
    if (r)
        r = 1;
    task->result = r;
}

// sub_08153990 @ 0x08153990
void sub_08153990(u32 unused, u32 step)
{
    switch (step)
    {
    case 0:
        PalFade_FadeRangeToBlack(0x70, 0x10, 4);
        break;
    case 1:
        VBlankTask_AddCounted(sub_08153860, 1);
        gUnk_03000004 = 0;
        gUnk_03000006 = 0;
        break;
    case 2:
        PalFade_FadeRangeToBlack(0x80, 0x80, 4);
        PalFade_FadeRangeToBlack(0x1D0, 0x30, 4);
        Music_FadeOut(2);
        break;
    case 3:
        if (gWorldMap.map == 5)
        {
            gWorldMap.map = 6;
            gWorldMap.x = gWorldMap.unk10 = 0x238;
            gWorldMap.y = gWorldMap.unk12 = 0x790;
            WorldMap_UpdateScroll();
            Music_Play(sub_080AD67C(gWorldMap.map));
        }
        else
        {
            gWorldMap.map = 5;
            gWorldMap.x = gWorldMap.unk10 = 0x1C8;
            gWorldMap.y = gWorldMap.unk12 = 0x380;
            WorldMap_UpdateScroll();
            Music_Play(sub_080AD67C(gWorldMap.map));
        }
        VBlankTask_AddCounted(sub_08153938, 1);
        break;
    case 4:
        PalFade_FadeRangeWithDuration(0x80, 0x80, 4, 0x20);
        PalFade_FadeRangeWithDuration(0x1D0, 0x30, 4, 0x20);
        break;
    }
}

// sub_08153A90 @ 0x08153A90
void sub_08153A90(u32 unused, u32 on)
{
    if (on == 0)
    {
        gWorldMap.unk34 = 1;
        VBlankTask_AddCounted(sub_08153860, 1);
    }
    else
    {
        gWorldMap.unk34 = 0;
        DmaFill16_3(0x3B3, gUnk_02000000, 0x81000800);
        Tilemap_CopyRectSkipZero(gUnknown_081B8270, gUnk_02000000, 0, 0, 1, 0, 7, 3);
        VBlankTask_AddCounted(sub_08153810, 1);
    }
}

// sub_08153B0C @ 0x08153B0C
void sub_08153B0C(void)
{
    Flag_Set(0x109);
    gWorldMap.state = 1;
}

// sub_08153B28 @ 0x08153B28
void sub_08153B28(struct Task *task, u32 dx, u32 dy, const void *script)
{
    struct FieldEvent *ev;

    WorldMap_GetBlocks();
    task->result = 0;
    gWorldMap.x += dx;
    gWorldMap.y += dy;
    WorldMap_UpdateScroll();
    WorldMap_DrawLayer(0, 0, 2);
    WorldMap_DrawLayer(0, 1, 3);
    ev = WorldMap_FindEvent(gWorldMap.x >> 4, gWorldMap.y >> 4, gWorldMap.map);
    if (ev != NULL && ev->script == script)
    {
        gWorldMap.state = 4;
        task->result = 1;
        gWorldMap.unk36 = 0;
    }
}

// sub_08153BA0 @ 0x08153BA0
void sub_08153BA0(struct Task *task, u32 dx, u32 dy, u32 x, u32 y)
{
    WorldMap_GetBlocks();
    task->result = 0;
    gWorldMap.x += dx;
    gWorldMap.y += dy;
    WorldMap_UpdateScroll();
    WorldMap_DrawLayer(0, 0, 2);
    WorldMap_DrawLayer(0, 1, 3);
    if ((gWorldMap.x >> 4) == x && (gWorldMap.y >> 4) == y)
    {
        if (WorldMap_FindLocation(gWorldMap.x >> 4, gWorldMap.y >> 4, gWorldMap.map))
            gWorldMap.state = 3;
        task->result = 1;
    }
}

// sub_08153C14 @ 0x08153C14
void sub_08153C14(u16 *x, u16 *y)
{
    const struct MapSprite *s = gUnknown_087E0F84;

    while (s->map != 0xFFFF)
    {
        if (s->map == 2 && s->flag == 0x68)
        {
            *x = s->x;
            *y = s->y;
            return;
        }
        s++;
    }
}

/* Screen position of a map point; off-screen points are parked at (300, 240). */
// WorldMap_ToScreen @ 0x08153C50
void WorldMap_ToScreen(u16 x, u16 y, u16 *sx, u16 *sy)
{
    *sx = x - gWorldMap.x;
    if ((u16)(*sx + 0x20) > 0x14C)
        *sx = 300;
    *sy = y - gWorldMap.y;
    if ((u16)(*sy + 0x20) > 0x110)
        *sy = 240;
}

// WorldMap_DrawSprites @ 0x08153C98
void WorldMap_DrawSprites(void)
{
    const struct MapSprite *s = gUnknown_087E0F84;
    u16 sx, sy;

    while (s->map != 0xFFFF)
    {
        if (s->map == gWorldMap.map && Flag_Test(s->flag))
        {
            const void *def = s->sprite;
            if (def == gUnknown_0800790C)
                def = gUnknown_087E0FD4[(gFrameCounter >> 2) & 3];
            WorldMap_ToScreen(s->x + 0x78, s->y + 0x50, &sx, &sy);
            Sprite_Draw(def, 4, s->palette, 2, 0x280, sx, sy);
        }
        s++;
    }
}

// sub_08153D40 @ 0x08153D40
void sub_08153D40(void)
{
    DMA3_SET(0x02034C74, 0x06008000, 0x84000400);
}

// sub_08153D64 @ 0x08153D64
void sub_08153D64(void)
{
    DMA3_SET(0x0202F874, 0x06008000, 0x84000400);
}

// WorldMap_AnimateTiles @ 0x08153D88
void WorldMap_AnimateTiles(void)
{
    if (gWorldMap.map == 6 && !Flag_Test(0x65) && (gFrameCounter & 0xF) == 0)
    {
        if ((gFrameCounter >> 4) & 1)
            VBlankTask_AddCounted(sub_08153D40, 1);
        else
            VBlankTask_AddCounted(sub_08153D64, 1);
    }
}

/* Area 6 animates BG tile set 4: both frames are decoded to EWRAM for WorldMap_AnimateTiles. */
// WorldMap_LoadAnimTiles @ 0x08153DD8
void WorldMap_LoadAnimTiles(void)
{
    if (gWorldMap.map == 6)
    {
        HuffUnComp(gUnknown_087C5E10, gBgPictureBuffer);
        LZ77UnCompWram(gBgPictureBuffer, (void *)0x02034C74);
        HuffUnComp(gUnknown_087C6358, gBgPictureBuffer);
        LZ77UnCompWram(gBgPictureBuffer, (void *)0x0202F874);
    }
}
