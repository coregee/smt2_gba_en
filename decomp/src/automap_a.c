#include "global.h"
#include "fieldevent.h"

// sub_080B447C @ 0x080B447C
u16 sub_080B447C(void)
{
    u16 dir = gFieldState.unk02;

    if (!sub_080C2BF0())
        dir = 0;
    return dir;
}

// Automap_CellToScreen @ 0x080B449C
void Automap_CellToScreen(u16 x, u16 y, u16 *outX, u16 *outY)
{
    u16 cx, cy;
    u16 px = x * 8;
    u16 py = y * 8;
    u16 dir;

    if (!sub_080C2BF0())
    {
        if (gFieldState.unk1C < 12)
        {
            cx = gFieldState.unk1A >> 1;
            cy = gFieldState.unk1C >> 1;
        }
        else
        {
            cx = gFieldState.unk1A >> 1;
            cy = gFieldState.unk14;
            if ((s16)gFieldState.unk14 < 0)
                cy = 0;
        }
    }
    else
    {
        dir = sub_080B447C();
        if ((dir == 0 || dir == 2) && gFieldState.unk1C < 12)
        {
            cx = gFieldState.unk1A >> 1;
            cy = gFieldState.unk1C >> 1;
        }
        else if (gFieldState.unk1A < 12 && gFieldState.unk1C < 12)
        {
            cx = gFieldState.unk1A >> 1;
            cy = gFieldState.unk1C >> 1;
        }
        else if (dir == 0 || dir == 2)
        {
            cx = gFieldState.unk1A >> 1;
            cy = gFieldState.unk14;
            if ((s16)gFieldState.unk14 < 0)
                cy = 0;
        }
        else
        {
            cy = gFieldState.unk1C >> 1;
            cx = gFieldState.unk12;
            if ((s16)gFieldState.unk12 < 0)
                cx = 0;
        }
    }

    switch (sub_080B447C())
    {
    case 0:
        *outX = (13 - cx) * 8;
        *outY = (5 - cy) * 8;
        *outX += px;
        *outY += py;
        *outY += gUnk_0200DFCE * 8;
        break;
    case 1:
        *outX = (13 - cy) * 8;
        *outY = (cx + 5) * 8;
        *outX += py;
        *outY -= px;
        *outY += gUnk_0200DFCE * 8;
        break;
    case 2:
        *outX = (cx + 13) * 8;
        *outY = (cy + 5) * 8;
        *outX -= px;
        *outY -= py;
        *outY += gUnk_0200DFCE * 8;
        break;
    case 3:
        *outX = (cy + 13) * 8;
        *outY = (5 - cx) * 8;
        *outX -= py;
        *outY += px;
        *outY += gUnk_0200DFCE * 8;
        break;
    }
}

// Automap_DrawMarkerSprite @ 0x080B4610
void Automap_DrawMarkerSprite(u16 x, u16 y, const void *sprite)
{
    u16 px, py;

    if (Automap_IsVisitedUnchecked(x, y))
    {
        Automap_CellToScreen(x, y, &px, &py);
        if (py < 0x58)
            Sprite_Draw(sprite, 2, 0, 2, 0x240, px + 8, py);
    }
}

// Automap_DrawSprites @ 0x080B466C
void Automap_DrawSprites(void)
{
    u32 i;
    u16 x, y;
    u16 *buf;

    if (gUnk_03003FFC == 1)
        return;

    for (i = 0; i < 8; i++)
    {
        struct MapMarker *m = &gMapMarkers[i];

        if (m->map == gUnk_03004614 && m->floor == gUnk_03004514)
            Automap_DrawMarkerSprite(m->x, m->y, gUnknown_081629E4[m->sprite]);
    }

    if (gUnk_03003FFC != 2)
    {
        if (!sub_080C2BF0())
            Automap_DrawMarkerSprite(gFieldState.unk12, gFieldState.unk14, gUnknown_081629F8[gFieldState.unk02]);
        else
            Automap_DrawMarkerSprite(gFieldState.unk12, gFieldState.unk14, gUnknown_081629F8[0]);
    }

    buf = gBgPictureBuffer;
    for (y = 0; y < gFieldState.unk1C; y++)
    {
        for (x = 0; x < gFieldState.unk1A; x++)
        {
            const void *sprite = gUnknown_08162A08[buf[y * 32 + x]];

            if (sprite != NULL)
                Automap_DrawMarkerSprite(x, y, sprite);
        }
    }

    if (gFieldState.unk1E != 0x36)
        MarkerHeader_DrawLocationName(0, 0, 0x12, 0x59, 0xC);

    if (gUnk_0200DFD2 == 0)
    {
        if (gUnk_0200DFCA == 1)
            sub_080C4A4C(2, 2, 200, 0x30);
        if (gUnk_0200DFC8 == 1)
            sub_080C4AB0(2, 2, 200, 0x48);
    }
}

// Automap_BuildAroundPlayer @ 0x080B47CC
#ifdef NONMATCHING
void Automap_BuildAroundPlayer(void)
{
    u16 dir = sub_080B447C();

    if (!sub_080C2BF0())
    {
        if (gFieldState.unk1C < 12)
            Automap_Build(dir, gFieldState.unk1A >> 1, gFieldState.unk1C >> 1);
        else
            Automap_Build(dir, gFieldState.unk1A >> 1, gFieldState.unk14);
    }
    else if ((dir == 0 || dir == 2) && gFieldState.unk1C < 12)
        Automap_Build(dir, gFieldState.unk1A >> 1, gFieldState.unk1C >> 1);
    else if (gFieldState.unk1A < 12 && gFieldState.unk1C < 12)
        Automap_Build(dir, gFieldState.unk1A >> 1, gFieldState.unk1C >> 1);
    else if (dir == 0 || dir == 2)
        Automap_Build(dir, gFieldState.unk1A >> 1, gFieldState.unk14);
    else
        Automap_Build(dir, gFieldState.unk12, gFieldState.unk1C >> 1);
}
#else
NAKED
void Automap_BuildAroundPlayer(void)
{
    asm_unified(
        ".L080B47CC:\n"
        "    push {r4, lr}\n"
        "    bl sub_080B447C\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    bl sub_080C2BF0\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080B47F4\n"
        "    ldr r2, .L080B47F0\n"
        "    ldrh r0, [r2, #0x1c]\n"
        "    cmp r0, #0xb\n"
        "    bls .L080B4820\n"
        "    ldrh r0, [r2, #0x1a]\n"
        "    lsrs r1, r0, #1\n"
        "    ldrh r2, [r2, #0x14]\n"
        "    b .L080B4828\n"
        ".L080B47F0: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B47F4:\n"
        "    cmp r4, #0\n"
        "    beq .L080B47FE\n"
        "    ldr r2, .L080B4810\n"
        "    cmp r4, #2\n"
        "    bne .L080B4814\n"
        ".L080B47FE:\n"
        "    ldr r0, .L080B4810\n"
        "    ldrh r1, [r0, #0x1c]\n"
        "    adds r2, r0, #0\n"
        "    cmp r1, #0xb\n"
        "    bhi .L080B4814\n"
        "    ldrh r1, [r2, #0x1a]\n"
        "    lsrs r1, r1, #1\n"
        "    ldrh r2, [r2, #0x1c]\n"
        "    b .L080B4826\n"
        ".L080B4810: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B4814:\n"
        "    ldrh r0, [r2, #0x1a]\n"
        "    cmp r0, #0xb\n"
        "    bhi .L080B4830\n"
        "    ldrh r0, [r2, #0x1c]\n"
        "    cmp r0, #0xb\n"
        "    bhi .L080B4830\n"
        ".L080B4820:\n"
        "    ldrh r1, [r2, #0x1a]\n"
        "    lsrs r1, r1, #1\n"
        "    adds r2, r0, #0\n"
        ".L080B4826:\n"
        "    lsrs r2, r2, #1\n"
        ".L080B4828:\n"
        "    adds r0, r4, #0\n"
        "    bl Automap_Build\n"
        "    b .L080B484C\n"
        ".L080B4830:\n"
        "    cmp r4, #0\n"
        "    beq .L080B4838\n"
        "    cmp r4, #2\n"
        "    bne .L080B4840\n"
        ".L080B4838:\n"
        "    ldrh r0, [r2, #0x1a]\n"
        "    lsrs r1, r0, #1\n"
        "    ldrh r2, [r2, #0x14]\n"
        "    b .L080B4846\n"
        ".L080B4840:\n"
        "    ldrh r1, [r2, #0x12]\n"
        "    ldrh r0, [r2, #0x1c]\n"
        "    lsrs r2, r0, #1\n"
        ".L080B4846:\n"
        "    adds r0, r4, #0\n"
        "    bl Automap_Build\n"
        ".L080B484C:\n"
        "    pop {r4}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// Automap_BuildIconMap @ 0x080B4854
/* Fills gBgPictureBuffer (32 columns per row) with the automap icon of every map square,
   chosen from the square's records. */
void Automap_BuildIconMap(void)
{
    u16 *buf = gBgPictureBuffer;
    u32 zero = 0;
    u16 x, y;

    CpuSet(&zero, buf, 0x05000C00);
    for (y = 0; y < gFieldState.unk1C; y++)
    {
        for (x = 0; x < gFieldState.unk1A; x++)
        {
            s32 recs = FieldMap_CellRecordsAt(x, y);
            u16 *dst = &buf[y * 32 + x];
            u16 *rec;

            if ((rec = FieldMap_FindRecord(recs, 0x23)) != NULL)
                *dst = rec[1] + 1;
            else if (FieldMap_FindRecord(recs, 4) != NULL)
                *dst = 0xF;
            else if ((rec = FieldMap_FindRecord(recs, 1)) != NULL)
            {
                if (rec[1] != 0)
                    *dst = 8;
            }
            else if ((rec = FieldMap_FindRecord(recs, 2)) != NULL)
            {
                if (rec[1] != 0)
                    *dst = 9;
            }
            else if ((rec = FieldMap_FindRecord(recs, 0x1B)) != NULL)
            {
                if (rec[1] != 0)
                    *dst = 8;
            }
            else if ((rec = FieldMap_FindRecord(recs, 0x1C)) != NULL)
            {
                if (rec[1] != 0)
                    *dst = 9;
            }
            else if (FieldMap_FindRecord(recs, 0x10) != NULL)
                *dst = 0xB;
            else if (FieldMap_FindRecord(recs, 3) != NULL)
                *dst = 0xA;
            else if (FieldMap_FindRecord(recs, 0x22) != NULL)
                *dst = 0x11;
            else if (FieldMap_FindRecord(recs, 0xB) != NULL)
            {
                u16 kind = FieldMap_FindRecord(recs, 0xB)[4];

                if (kind == 7)
                    *dst = 0x14;
                else if (kind == 9)
                    *dst = 0x16;
                else if (kind == 10)
                    *dst = 0x21;
                else
                    *dst = 0x11;
            }
            else if (FieldMap_FindRecord(recs, 0xC) != NULL)
                *dst = 7;
            else if (FieldMap_FindRecord(recs, 0xD) != NULL)
            {
                if (gUnk_03004614 != 0x1A || gUnk_03004514 != 1 || Flag_Test(0x15))
                    *dst = 0xC;
            }
            else if (FieldMap_FindRecord(recs, 0xE) != NULL)
                *dst = 0xD;
            else if (FieldMap_FindRecord(recs, 0xF) != NULL)
                *dst = 0xE;
            else if (FieldMap_FindRecord(recs, 0x11) != NULL)
                *dst = 0x14;
            else if (FieldMap_FindRecord(recs, 0x25) != NULL)
                *dst = 0x22;
            else if (FieldMap_FindRecord(recs, 0x26) != NULL)
                *dst = 0x23;
            else if (FieldMap_FindRecord(recs, 0x27) != NULL)
                *dst = 0x24;
        }
    }
}

// Automap_HasCells @ 0x080B4A54
/* TRUE when any automap cell is in use. */
u32 Automap_HasCells(void)
{
    u16 w = 28;
    u16 h = 11;
    u16 x, y;

    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            if (gAutomapCells[y][x].flags != 0)
                return TRUE;
        }
    }
    return FALSE;
}

// Automap_DrawTilemap @ 0x080B4AA4
/* Draws the automap cells into the BG tilemap at 0x02000000 (column 0 left empty). */
#ifdef NONMATCHING
void Automap_DrawTilemap(void)
{
    u16 w = 28;
    u16 x, y;

    sub_080B447C();
    for (y = 0; y < 11; y++)
    {
        for (x = 0; x < w; x++)
        {
            if (gAutomapCells[y][x].flags != 0)
            {
                u16 *dst = &gUnk_02000000[y][x + 1];
                u16 tile = sub_080B4448(&gAutomapCells[y][x]);

                if (!(gAutomapCells[y][x].flags & 0x8000))
                    *dst = tile;
                else
                    *dst = tile | 0x6000;
            }
        }
    }
    Automap_BuildIconMap();
    VBlankTask_AddCounted(sub_080B5084, 1);
}
#else
NAKED
void Automap_DrawTilemap(void)
{
    asm_unified(
        ".L080B4AA4:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #4\n"
        "    movs r0, #0x1c\n"
        "    mov sl, r0\n"
        "    bl sub_080B447C\n"
        "    movs r1, #0\n"
        ".L080B4ABA:\n"
        "    movs r6, #0\n"
        "    adds r2, r1, #1\n"
        "    mov sb, r2\n"
        "    cmp r6, sl\n"
        "    bhs .L080B4B2E\n"
        "    ldr r3, .L080B4B10\n"
        "    lsls r0, r1, #6\n"
        "    ldr r4, .L080B4B14\n"
        "    adds r4, r4, r0\n"
        "    mov r8, r4\n"
        "    lsls r0, r1, #2\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r0, r1\n"
        "    lsls r7, r0, #4\n"
        ".L080B4AD8:\n"
        "    lsls r1, r6, #1\n"
        "    adds r0, r1, r6\n"
        "    lsls r2, r0, #2\n"
        "    adds r0, r2, r7\n"
        "    adds r4, r0, r3\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #0\n"
        "    beq .L080B4B24\n"
        "    adds r0, r1, #2\n"
        "    mov r1, r8\n"
        "    adds r5, r1, r0\n"
        "    adds r0, r2, r3\n"
        "    adds r0, r7, r0\n"
        "    str r3, [sp]\n"
        "    bl sub_080B4448\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    ldrh r0, [r4]\n"
        "    movs r4, #0x80\n"
        "    lsls r4, r4, #8\n"
        "    adds r1, r4, #0\n"
        "    ands r0, r1\n"
        "    ldr r3, [sp]\n"
        "    cmp r0, #0\n"
        "    bne .L080B4B18\n"
        "    strh r2, [r5]\n"
        "    b .L080B4B24\n"
        ".L080B4B10: .4byte 0x02005000 @ EWRAM+0x5000\n"
        ".L080B4B14: .4byte 0x02000000 @ EWRAM\n"
        ".L080B4B18:\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #7\n"
        "    adds r1, r0, #0\n"
        "    adds r0, r2, #0\n"
        "    orrs r0, r1\n"
        "    strh r0, [r5]\n"
        ".L080B4B24:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r6, sl\n"
        "    blo .L080B4AD8\n"
        ".L080B4B2E:\n"
        "    mov r1, sb\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    cmp r1, #0xb\n"
        "    blo .L080B4ABA\n"
        "    bl Automap_BuildIconMap\n"
        "    ldr r0, .L080B4B54\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    add sp, #4\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080B4B54: .4byte sub_080B5084\n"
    );
}
#endif

// sub_080B4B58 @ 0x080B4B58
void sub_080B4B58(void)
{
    DmaCopy32(3, gBgPictureBuffer, (void *)0x06014800, 0x1000);
}

// sub_080B4B7C @ 0x080B4B7C
void sub_080B4B7C(void)
{
    DmaCopy32(3, gBgPictureBuffer, (void *)0x06015800, 0x1000);
}

// sub_080B4BA0 @ 0x080B4BA0
void sub_080B4BA0(void)
{
    DmaCopy32(3, gBgPictureBuffer, (void *)0x06016800, 0x1000);
}

// sub_080B4BC4 @ 0x080B4BC4
void sub_080B4BC4(void)
{
    DmaCopy32(3, gBgPictureBuffer, (void *)0x06017800, 0x800);
}
