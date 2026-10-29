#include "global.h"
#include "inventory.h"

// Encounter_IsAllowed @ 0x080C5320
/* Whether random encounters may happen here. */
u32 Encounter_IsAllowed(void)
{
    if (!Flag_Test(0xCB) || !Flag_Test(0x163) || gGameState.unk18A6 == 0xFFFF || Flag_Test(1)
        || Stock_FindByDemonId(0x52) != NULL || Stock_FindByDemonId(0x53) != NULL || Flag_Test(0xAE))
        return FALSE;
    if (gUnk_03004614 == 0x42 || gUnk_03004614 == 0x4A || gUnk_03004614 == 0x4B
        || gUnk_03004614 == 0xF)
        return FALSE;
    if (Flag_Test(0xD0) && (gGameState.unk18A6 == 0 || gGameState.unk18A6 == 0x10))
        return FALSE;
    if (Flag_Test(0xD1) && gGameState.unk18A6 == 0x14)
        return FALSE;
    if (Flag_Test(0x50) && gGameState.unk18A6 == 0x22)
        return FALSE;
    if (gGameState.unkAC0 == 1)
        return FALSE;
    return TRUE;
}

// sub_080C53F0 @ 0x080C53F0
void sub_080C53F0(void)
{
}

// MiniView_SampleSquare @ 0x080C53F4
/* Fills view cell (col, row) from map square (x, y): valid, and its four walls relative to
   the facing. */
#ifdef NONMATCHING
void MiniView_SampleSquare(u16 x, u16 y, u16 col, u16 row)
{
    struct MapHeader *floor = DungeonMap_GetFloor(*(u16 *)&gUnk_03004614, gUnk_03004514);
    struct C0c2ViewCell *cell = &gMiniViewCells[row][col];
    u16 ax = x + floor->originX;
    u16 ay = y + floor->originY;
    u32 v;

    if ((s16)x < 0 || x >= gFieldState.width || (s16)y < 0 || y >= gFieldState.height)
    {
        v = 0;
    }
    else
    {
        v = SubMap_IsOutsideExclusions(floor, ax, ay);
        if (v)
        {
            u16 dir = gFieldState.facing;
            u16 sq = gFieldState.squares[y * gFieldState.width + x];
            u32 i;

            for (i = 0; i < 4; i++)
            {
                cell->walls[i] = (sq >> gUnknown_0815F2E6[dir]) & 3;
                dir = (dir + 1) & 3;
            }
            v = 1;
        }
    }
    cell->valid = v;
}
#else
NAKED
void MiniView_SampleSquare(u16 x, u16 y, u16 col, u16 row)
{
    asm_unified(
        ".L080C53F4:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    adds r5, r2, #0\n"
        "    adds r4, r3, #0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    mov sl, r6\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r7, r1, #0x10\n"
        "    mov sb, r7\n"
        "    lsls r5, r5, #0x10\n"
        "    lsrs r5, r5, #0x10\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    ldr r0, .L080C5468\n"
        "    ldrh r0, [r0]\n"
        "    ldr r1, .L080C546C\n"
        "    ldrh r1, [r1]\n"
        "    bl DungeonMap_GetFloor\n"
        "    adds r3, r0, #0\n"
        "    lsls r2, r4, #3\n"
        "    adds r2, r2, r4\n"
        "    lsls r2, r2, #2\n"
        "    lsls r0, r5, #1\n"
        "    adds r0, r0, r5\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L080C5470\n"
        "    adds r0, r0, r1\n"
        "    adds r2, r2, r0\n"
        "    mov r8, r2\n"
        "    ldrh r0, [r3, #8]\n"
        "    adds r0, r6, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    ldrh r0, [r3, #0xa]\n"
        "    adds r0, r7, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    lsls r0, r6, #0x10\n"
        "    cmp r0, #0\n"
        "    blt .L080C5462\n"
        "    ldr r4, .L080C5474\n"
        "    ldrh r0, [r4, #0x1a]\n"
        "    cmp r6, r0\n"
        "    bhs .L080C5462\n"
        "    lsls r0, r7, #0x10\n"
        "    cmp r0, #0\n"
        "    blt .L080C5462\n"
        "    ldrh r0, [r4, #0x1c]\n"
        "    cmp r7, r0\n"
        "    blo .L080C5478\n"
        ".L080C5462:\n"
        "    movs r0, #0\n"
        "    b .L080C54BC\n"
        "    .byte 0x00, 0x00\n"
        ".L080C5468: .4byte 0x03004614 @ IWRAM+0x4614\n"
        ".L080C546C: .4byte 0x03004514 @ IWRAM+0x4514\n"
        ".L080C5470: .4byte 0x0200AF08 @ EWRAM+0xAF08\n"
        ".L080C5474: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080C5478:\n"
        "    adds r0, r3, #0\n"
        "    bl SubMap_IsOutsideExclusions\n"
        "    cmp r0, #0\n"
        "    beq .L080C54BC\n"
        "    ldrh r2, [r4, #2]\n"
        "    ldrh r0, [r4, #0x1a]\n"
        "    mov r1, sb\n"
        "    muls r1, r0, r1\n"
        "    adds r0, r1, #0\n"
        "    add r0, sl\n"
        "    ldr r1, [r4, #0x20]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r1\n"
        "    ldrh r6, [r0]\n"
        "    movs r4, #0\n"
        "    ldr r7, .L080C54D0\n"
        "    movs r5, #3\n"
        "    mov r3, r8\n"
        "    adds r3, #4\n"
        ".L080C54A0:\n"
        "    lsls r1, r2, #1\n"
        "    adds r1, r1, r7\n"
        "    adds r0, r6, #0\n"
        "    ldrh r1, [r1]\n"
        "    asrs r0, r1\n"
        "    ands r0, r5\n"
        "    strh r0, [r3]\n"
        "    adds r2, #1\n"
        "    ands r2, r5\n"
        "    adds r3, #2\n"
        "    adds r4, #1\n"
        "    cmp r4, #3\n"
        "    bls .L080C54A0\n"
        "    movs r0, #1\n"
        ".L080C54BC:\n"
        "    mov r1, r8\n"
        "    strh r0, [r1]\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080C54D0: .4byte gUnknown_0815F2E6\n"
    );
}
#endif

// MiniView_SampleAhead @ 0x080C54D4
/* Samples the 3x5 squares ahead of the player into gMiniViewCells. */
#ifdef NONMATCHING
void MiniView_SampleAhead(u32 dir)
{
    u16 x = gFieldState.x;
    u16 y = gFieldState.y;
    u16 row, col;

    DmaFill32(3, 0, gMiniViewCells, 0xB4);
    switch (dir)
    {
    case 0:
        x -= 1;
        y -= 2;
        break;
    case 1:
        x += 2;
        y -= 1;
        break;
    case 2:
        x += 1;
        y += 2;
        break;
    case 3:
        x -= 2;
        y += 1;
        break;
    }
    for (row = 0; row < 5; row++)
    {
        for (col = 0; col < 3; col++)
        {
            switch (dir)
            {
            case 0:
                MiniView_SampleSquare(x + col, y + row, col, row);
                break;
            case 1:
                MiniView_SampleSquare(x - row, y + col, col, row);
                break;
            case 2:
                MiniView_SampleSquare(x - col, y - row, col, row);
                break;
            case 3:
                MiniView_SampleSquare(x + row, y - col, col, row);
                break;
            }
        }
    }
}
#else
NAKED
void MiniView_SampleAhead(u32 dir)
{
    asm_unified(
        ".L080C54D4:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #8\n"
        "    mov r8, r0\n"
        "    ldr r0, .L080C5510\n"
        "    ldrh r7, [r0, #0x12]\n"
        "    ldrh r6, [r0, #0x14]\n"
        "    movs r0, #0\n"
        "    str r0, [sp]\n"
        "    ldr r1, .L080C5514\n"
        "    mov r0, sp\n"
        "    str r0, [r1]\n"
        "    ldr r0, .L080C5518\n"
        "    str r0, [r1, #4]\n"
        "    ldr r0, .L080C551C\n"
        "    str r0, [r1, #8]\n"
        "    ldr r0, [r1, #8]\n"
        "    mov r1, r8\n"
        "    cmp r1, #1\n"
        "    beq .L080C552A\n"
        "    cmp r1, #1\n"
        "    blo .L080C5520\n"
        "    cmp r1, #2\n"
        "    beq .L080C5534\n"
        "    cmp r1, #3\n"
        "    beq .L080C553E\n"
        "    b .L080C554A\n"
        ".L080C5510: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080C5514: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080C5518: .4byte 0x0200AF08 @ EWRAM+0xAF08\n"
        ".L080C551C: .4byte 0x8500002D\n"
        ".L080C5520:\n"
        "    subs r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    subs r0, r6, #2\n"
        "    b .L080C5546\n"
        ".L080C552A:\n"
        "    adds r0, r7, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    subs r0, r6, #1\n"
        "    b .L080C5546\n"
        ".L080C5534:\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r0, r6, #2\n"
        "    b .L080C5546\n"
        ".L080C553E:\n"
        "    subs r0, r7, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r0, r6, #1\n"
        ".L080C5546:\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        ".L080C554A:\n"
        "    movs r5, #0\n"
        "    cmp r5, #5\n"
        "    bhs .L080C55D0\n"
        ".L080C5550:\n"
        "    movs r4, #0\n"
        "    adds r2, r5, #1\n"
        "    str r2, [sp, #4]\n"
        "    cmp r4, #3\n"
        "    bhs .L080C55C6\n"
        "    adds r0, r6, r5\n"
        "    lsls r0, r0, #0x10\n"
        "    mov sl, r0\n"
        "    subs r0, r7, r5\n"
        "    lsls r0, r0, #0x10\n"
        "    mov sb, r0\n"
        ".L080C5566:\n"
        "    mov r0, r8\n"
        "    cmp r0, #1\n"
        "    beq .L080C5586\n"
        "    cmp r0, #1\n"
        "    blo .L080C557A\n"
        "    cmp r0, #2\n"
        "    beq .L080C5592\n"
        "    cmp r0, #3\n"
        "    beq .L080C55A8\n"
        "    b .L080C55BC\n"
        ".L080C557A:\n"
        "    adds r0, r7, r4\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r2, sl\n"
        "    lsrs r1, r2, #0x10\n"
        "    b .L080C559E\n"
        ".L080C5586:\n"
        "    adds r1, r6, r4\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    mov r2, sb\n"
        "    lsrs r0, r2, #0x10\n"
        "    b .L080C559E\n"
        ".L080C5592:\n"
        "    subs r0, r7, r4\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    subs r1, r6, r5\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        ".L080C559E:\n"
        "    adds r2, r4, #0\n"
        "    adds r3, r5, #0\n"
        "    bl MiniView_SampleSquare\n"
        "    b .L080C55BC\n"
        ".L080C55A8:\n"
        "    adds r0, r7, r5\n"
        "    lsls r0, r0, #0x10\n"
        "    subs r1, r6, r4\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    adds r2, r4, #0\n"
        "    adds r3, r5, #0\n"
        "    bl MiniView_SampleSquare\n"
        ".L080C55BC:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #3\n"
        "    blo .L080C5566\n"
        ".L080C55C6:\n"
        "    ldr r1, [sp, #4]\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #5\n"
        "    blo .L080C5550\n"
        ".L080C55D0:\n"
        "    add sp, #8\n"
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

// sub_080C55E0 @ 0x080C55E0
void sub_080C55E0(void)
{
    DmaCopy32(3, gWindowTilemapBuffer, (void *)0x06001000, 0x1000);
}

// MiniView_Draw @ 0x080C5604
/* Draws the small 3x5 view of the squares ahead (tilemap columns 25-27, rows 6-10). */
#ifdef NONMATCHING
void MiniView_Draw(void)
{
    u16 row, col, i;

    MiniView_SampleAhead(gFieldState.facing);
    for (row = 0; row < 5; row++)
    {
        u16 *line = (u16 *)(0x0200DFD4 + ((row + 6) << 6));

        for (col = 0; col < 3; col++)
        {
            struct C0c2ViewCell *cell = &gMiniViewCells[row][col];
            u16 *dst = &line[col + 25];

            if (cell->valid == 1)
            {
                for (i = 0; i < 4; i++)
                {
                    if (cell->walls[i] == 3)
                        cell->walls[i] = 2;
                }
                *dst = sub_080B4448(cell);
            }
            else
            {
                *dst = 0x3B4;
            }
        }
    }
    Sprite_Draw(gUnknown_080008C0, 0, 0, 0, 0, 0xD0, 0x40);
    gUnk_03000030 = 0xE0;
    gUnk_03000031 = 0xC8;
    gUnk_03000034 = 0x58;
    gUnk_03000035 = 0x30;
    gUnk_03000038 = 0x1F;
    VBlankTask_AddCounted(sub_080C55E0, 1);
}
#else
NAKED
void MiniView_Draw(void)
{
    asm_unified(
        ".L080C5604:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0xc\n"
        "    ldr r0, .L080C5674\n"
        "    ldrh r0, [r0, #2]\n"
        "    bl MiniView_SampleAhead\n"
        "    movs r2, #0\n"
        ".L080C561A:\n"
        "    movs r3, #0\n"
        "    lsls r0, r2, #3\n"
        "    adds r1, r2, #6\n"
        "    adds r4, r2, #1\n"
        "    mov sl, r4\n"
        "    adds r0, r0, r2\n"
        "    lsls r0, r0, #2\n"
        "    mov sb, r0\n"
        "    lsls r1, r1, #6\n"
        "    ldr r0, .L080C5678\n"
        "    adds r0, r0, r1\n"
        "    mov r8, r0\n"
        ".L080C5632:\n"
        "    lsls r2, r3, #1\n"
        "    adds r0, r2, r3\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L080C567C\n"
        "    adds r0, r0, r1\n"
        "    mov r1, sb\n"
        "    adds r4, r1, r0\n"
        "    adds r2, #0x32\n"
        "    mov r0, r8\n"
        "    adds r6, r0, r2\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #1\n"
        "    bne .L080C5680\n"
        "    movs r2, #0\n"
        "    adds r5, r3, #1\n"
        "    adds r3, r4, #4\n"
        "    movs r7, #2\n"
        ".L080C5654:\n"
        "    lsls r0, r2, #1\n"
        "    adds r1, r3, r0\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #3\n"
        "    bne .L080C5660\n"
        "    strh r7, [r1]\n"
        ".L080C5660:\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #3\n"
        "    bls .L080C5654\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080B4448\n"
        "    strh r0, [r6]\n"
        "    b .L080C568A\n"
        ".L080C5674: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080C5678: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C567C: .4byte 0x0200AF08 @ EWRAM+0xAF08\n"
        ".L080C5680:\n"
        "    movs r1, #0xed\n"
        "    lsls r1, r1, #2\n"
        "    adds r0, r1, #0\n"
        "    strh r0, [r6]\n"
        "    adds r5, r3, #1\n"
        ".L080C568A:\n"
        "    lsls r0, r5, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    cmp r3, #2\n"
        "    bls .L080C5632\n"
        "    mov r4, sl\n"
        "    lsls r0, r4, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #4\n"
        "    bls .L080C561A\n"
        "    ldr r0, .L080C56EC\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    movs r1, #0xd0\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #0x40\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    ldr r1, .L080C56F0\n"
        "    movs r0, #0xe0\n"
        "    strb r0, [r1]\n"
        "    ldr r1, .L080C56F4\n"
        "    movs r0, #0xc8\n"
        "    strb r0, [r1]\n"
        "    ldr r1, .L080C56F8\n"
        "    movs r0, #0x58\n"
        "    strb r0, [r1]\n"
        "    ldr r1, .L080C56FC\n"
        "    movs r0, #0x30\n"
        "    strb r0, [r1]\n"
        "    ldr r1, .L080C5700\n"
        "    movs r0, #0x1f\n"
        "    strb r0, [r1]\n"
        "    ldr r0, .L080C5704\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    add sp, #0xc\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080C56EC: .4byte gUnknown_080008C0\n"
        ".L080C56F0: .4byte 0x03000030 @ IWRAM+0x30\n"
        ".L080C56F4: .4byte 0x03000031 @ IWRAM+0x31\n"
        ".L080C56F8: .4byte 0x03000034 @ IWRAM+0x34\n"
        ".L080C56FC: .4byte 0x03000035 @ IWRAM+0x35\n"
        ".L080C5700: .4byte 0x03000038 @ IWRAM+0x38\n"
        ".L080C5704: .4byte sub_080C55E0\n"
    );
}
#endif

// MiniView_Clear @ 0x080C5708
#ifdef NONMATCHING
void MiniView_Clear(void)
{
    u8 *base = (u8 *)0x0200DFD4;
    u16 row, col;

    View_BuildCells(gFieldState.facing, 1);
    for (row = 0; row < 5; row++)
    {
        u16 *line = (u16 *)(base + ((row + 6) << 6));

        for (col = 0; col < 3; col++)
            line[col + 25] = 0;
    }
    gUnk_03000038 = 0x3F;
    VBlankTask_AddCounted(sub_080C55E0, 1);
    gFieldState.unk58 = 0;
}
#else
NAKED
void MiniView_Clear(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    ldr r5, .L080C575C\n"
        "    ldr r0, .L080C5760\n"
        "    ldrh r0, [r0, #2]\n"
        "    movs r1, #1\n"
        "    bl View_BuildCells\n"
        "    movs r2, #0\n"
        "    ldr r6, .L080C5764\n"
        "    ldr r7, .L080C5768\n"
        "    movs r4, #0\n"
        ".L080C571E:\n"
        "    movs r1, #0\n"
        "    adds r0, r2, #6\n"
        "    adds r3, r2, #1\n"
        "    lsls r0, r0, #6\n"
        "    adds r2, r5, r0\n"
        ".L080C5728:\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, #0x32\n"
        "    adds r0, r2, r0\n"
        "    strh r4, [r0]\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    cmp r1, #2\n"
        "    bls .L080C5728\n"
        "    lsls r0, r3, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #4\n"
        "    bls .L080C571E\n"
        "    movs r0, #0x3f\n"
        "    strb r0, [r6]\n"
        "    adds r0, r7, #0\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    ldr r1, .L080C5760\n"
        "    movs r0, #0\n"
        "    str r0, [r1, #0x58]\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080C575C: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C5760: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080C5764: .4byte 0x03000038 @ IWRAM+0x38\n"
        ".L080C5768: .4byte sub_080C55E0\n"
    );
}
#endif

// sub_080C576C @ 0x080C576C
void sub_080C576C(struct Task *t)
{
    t->result = 1;
    if (BattleFlags_Get() & 0x100)
    {
        if ((u16)(gFieldState.unk00 - 1) <= 1 || gFieldState.unk00 == 5 || gFieldState.unk00 == 6
            || gFieldState.unk00 == 7 || gFieldState.unk00 == 8)
        {
            MiniView_Draw();
            t->result = 0;
        }
    }
}

// sub_080C57B4 @ 0x080C57B4
struct Task *sub_080C57B4(void)
{
    return Task_Create(gUnknown_081A6674, 0xFFFF);
}

// KeyItem_IsObtainable @ 0x080C57CC
/* Whether key item id (300-345) is obtainable now: FALSE when already held, otherwise by
   story flags, the presence of the three heroes (sub_080C2A84) and the hero's alignment. */
#ifdef NONMATCHING
#define ANY_HERO() (sub_080C2A84(0) || sub_080C2A84(1) || sub_080C2A84(2))
u32 KeyItem_IsObtainable(u16 id)
{
    u32 ok;

    if (Inventory_GetCount(id) != 0)
        return FALSE;
    switch (id - 300)
    {
    case 0:
        ok = Flag_Test(0x5D);
        break;
    case 1:
        ok = sub_080C2A84(0);
        break;
    case 2:
        ok = ANY_HERO() && Flag_Test(0x23);
        break;
    case 3:
        ok = sub_080C2A84(0) && Combatant_GetAlignment(0) == 2 && Flag_Test(0x4E);
        break;
    case 4:
        ok = sub_080C2A84(2);
        break;
    case 5:
        ok = sub_080C2A84(0);
        break;
    case 6:
        ok = ANY_HERO() && Flag_Test(0x1E);
        break;
    case 7:
        ok = sub_080C2A84(2);
        break;
    case 8:
        ok = sub_080C2A84(2) && Combatant_GetAlignment(0) == 0 && Flag_Test(0x71);
        break;
    case 9:
    case 10:
        ok = TRUE;
        break;
    case 11:
        ok = ANY_HERO() && Combatant_GetAlignment(0) == 0;
        break;
    case 12:
        ok = ANY_HERO() && Combatant_GetAlignment(0) == 2 && Flag_Test(0x5D);
        break;
    case 13:
        ok = sub_080C2A84(1) && Flag_Test(0x23);
        break;
    case 14:
        ok = ANY_HERO() && Combatant_GetAlignment(0) == 0 && Flag_Test(0x5D);
        break;
    case 15:
        ok = ANY_HERO() && Combatant_GetAlignment(0) == 1 && Flag_Test(0x5D);
        break;
    case 16:
        ok = TRUE;
        break;
    case 17:
        ok = Flag_Test(0xE7);
        break;
    case 18:
        ok = ANY_HERO();
        break;
    case 19:
        ok = Flag_Test(0x1D);
        break;
    case 20:
        ok = Flag_Test(0xC);
        break;
    case 21:
    case 22:
        ok = TRUE;
        break;
    case 23:
        ok = Flag_Test(0x2D);
        break;
    case 24:
        ok = Flag_Test(0x48);
        break;
    case 25:
        ok = Flag_Test(0x49);
        break;
    case 26:
    case 27:
    case 28:
        ok = TRUE;
        break;
    case 29:
        ok = Flag_Test(0x2E);
        break;
    case 30:
        ok = TRUE;
        break;
    case 31:
        ok = ANY_HERO();
        break;
    case 32:
        ok = ANY_HERO() && Flag_Test(0x55);
        break;
    case 33:
        ok = ANY_HERO() && Flag_Test(0xC9);
        break;
    case 34:
        ok = ANY_HERO();
        break;
    case 35:
    case 36:
        ok = TRUE;
        break;
    case 37:
        ok = ANY_HERO();
        break;
    case 38:
        ok = TRUE;
        break;
    case 39:
        ok = Flag_Test(0x36);
        break;
    case 40:
        ok = sub_080C2A84(0);
        break;
    case 44:
        ok = ANY_HERO();
        break;
    case 45:
    default:
        ok = TRUE;
        break;
    }
    if (ok)
        return TRUE;
    return FALSE;
}
#else
NAKED
u32 KeyItem_IsObtainable(u16 id)
{
    asm_unified(
        ".L080C57CC:\n"
        "    push {r4, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Inventory_GetCount\n"
        "    lsls r0, r0, #0x18\n"
        "    cmp r0, #0\n"
        "    beq .L080C57E0\n"
        "    b .L080C5988\n"
        ".L080C57E0:\n"
        "    ldr r1, .L080C57F4\n"
        "    adds r0, r4, r1\n"
        "    cmp r0, #0x2d\n"
        "    bls .L080C57EA\n"
        "    b .L080C5B08\n"
        ".L080C57EA:\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L080C57F8\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        ".L080C57F4: .4byte 0xFFFFFED4\n"
        ".L080C57F8: .4byte gUnknown_080C57FC\n"
        "    .global gUnknown_080C57FC\n"
        "gUnknown_080C57FC:\n"
        ".L080C57FC: @ jump table\n"
        "    .4byte .L080C58B4\n"
        "    .4byte .L080C58BC\n"
        "    .4byte .L080C58C0\n"
        "    .4byte .L080C58EC\n"
        "    .4byte .L080C5AFA\n"
        "    .4byte .L080C590A\n"
        "    .4byte .L080C590E\n"
        "    .4byte .L080C5AFA\n"
        "    .4byte .L080C593A\n"
        "    .4byte .L080C5B08\n"
        "    .4byte .L080C5B08\n"
        "    .4byte .L080C5958\n"
        "    .4byte .L080C598C\n"
        "    .4byte .L080C59C2\n"
        "    .4byte .L080C59D6\n"
        "    .4byte .L080C5A0C\n"
        "    .4byte .L080C5B08\n"
        "    .4byte .L080C5A42\n"
        "    .4byte .L080C5AE2\n"
        "    .4byte .L080C5A4A\n"
        "    .4byte .L080C5A52\n"
        "    .4byte .L080C5B08\n"
        "    .4byte .L080C5B08\n"
        "    .4byte .L080C5A5A\n"
        "    .4byte .L080C5A62\n"
        "    .4byte .L080C5A6A\n"
        "    .4byte .L080C5B08\n"
        "    .4byte .L080C5B08\n"
        "    .4byte .L080C5B08\n"
        "    .4byte .L080C5A72\n"
        "    .4byte .L080C5B08\n"
        "    .4byte .L080C5AE2\n"
        "    .4byte .L080C5A7A\n"
        "    .4byte .L080C5AA8\n"
        "    .4byte .L080C5AE2\n"
        "    .4byte .L080C5B08\n"
        "    .4byte .L080C5B08\n"
        "    .4byte .L080C5AE2\n"
        "    .4byte .L080C5B08\n"
        "    .4byte .L080C5AD6\n"
        "    .4byte .L080C5ADE\n"
        "    .4byte .L080C5B08\n"
        "    .4byte .L080C5B08\n"
        "    .4byte .L080C5B08\n"
        "    .4byte .L080C5AE2\n"
        "    .4byte .L080C5B08\n"
        ".L080C58B4:\n"
        "    movs r0, #0x5d\n"
        "    bl Flag_Test\n"
        "    b .L080C5B02\n"
        ".L080C58BC:\n"
        "    movs r0, #0\n"
        "    b .L080C5AFC\n"
        ".L080C58C0:\n"
        "    movs r0, #0\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C58E4\n"
        "    movs r0, #1\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C58E4\n"
        "    movs r0, #2\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L080C5988\n"
        ".L080C58E4:\n"
        "    movs r0, #0x23\n"
        "    bl Flag_Test\n"
        "    b .L080C5B02\n"
        ".L080C58EC:\n"
        "    movs r0, #0\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L080C5988\n"
        "    movs r0, #0\n"
        "    bl Combatant_GetAlignment\n"
        "    cmp r0, #2\n"
        "    bne .L080C5988\n"
        "    movs r0, #0x4e\n"
        "    bl Flag_Test\n"
        "    b .L080C5B02\n"
        ".L080C590A:\n"
        "    movs r0, #0\n"
        "    b .L080C5AFC\n"
        ".L080C590E:\n"
        "    movs r0, #0\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C5932\n"
        "    movs r0, #1\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C5932\n"
        "    movs r0, #2\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L080C5988\n"
        ".L080C5932:\n"
        "    movs r0, #0x1e\n"
        "    bl Flag_Test\n"
        "    b .L080C5B02\n"
        ".L080C593A:\n"
        "    movs r0, #2\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L080C5988\n"
        "    movs r0, #0\n"
        "    bl Combatant_GetAlignment\n"
        "    cmp r0, #0\n"
        "    bne .L080C5988\n"
        "    movs r0, #0x71\n"
        "    bl Flag_Test\n"
        "    b .L080C5B02\n"
        ".L080C5958:\n"
        "    movs r0, #0\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C597C\n"
        "    movs r0, #1\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C597C\n"
        "    movs r0, #2\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L080C5988\n"
        ".L080C597C:\n"
        "    movs r0, #0\n"
        "    bl Combatant_GetAlignment\n"
        "    cmp r0, #0\n"
        "    bne .L080C5988\n"
        "    b .L080C5B08\n"
        ".L080C5988:\n"
        "    movs r0, #0\n"
        "    b .L080C5B0A\n"
        ".L080C598C:\n"
        "    movs r0, #0\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C59B0\n"
        "    movs r0, #1\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C59B0\n"
        "    movs r0, #2\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L080C5988\n"
        ".L080C59B0:\n"
        "    movs r0, #0\n"
        "    bl Combatant_GetAlignment\n"
        "    cmp r0, #2\n"
        "    bne .L080C5988\n"
        "    movs r0, #0x5d\n"
        "    bl Flag_Test\n"
        "    b .L080C5B02\n"
        ".L080C59C2:\n"
        "    movs r0, #1\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L080C5988\n"
        "    movs r0, #0x23\n"
        "    bl Flag_Test\n"
        "    b .L080C5B02\n"
        ".L080C59D6:\n"
        "    movs r0, #0\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C59FA\n"
        "    movs r0, #1\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C59FA\n"
        "    movs r0, #2\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L080C5988\n"
        ".L080C59FA:\n"
        "    movs r0, #0\n"
        "    bl Combatant_GetAlignment\n"
        "    cmp r0, #0\n"
        "    bne .L080C5988\n"
        "    movs r0, #0x5d\n"
        "    bl Flag_Test\n"
        "    b .L080C5B02\n"
        ".L080C5A0C:\n"
        "    movs r0, #0\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C5A30\n"
        "    movs r0, #1\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C5A30\n"
        "    movs r0, #2\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L080C5988\n"
        ".L080C5A30:\n"
        "    movs r0, #0\n"
        "    bl Combatant_GetAlignment\n"
        "    cmp r0, #1\n"
        "    bne .L080C5988\n"
        "    movs r0, #0x5d\n"
        "    bl Flag_Test\n"
        "    b .L080C5B02\n"
        ".L080C5A42:\n"
        "    movs r0, #0xe7\n"
        "    bl Flag_Test\n"
        "    b .L080C5B02\n"
        ".L080C5A4A:\n"
        "    movs r0, #0x1d\n"
        "    bl Flag_Test\n"
        "    b .L080C5B02\n"
        ".L080C5A52:\n"
        "    movs r0, #0xc\n"
        "    bl Flag_Test\n"
        "    b .L080C5B02\n"
        ".L080C5A5A:\n"
        "    movs r0, #0x2d\n"
        "    bl Flag_Test\n"
        "    b .L080C5B02\n"
        ".L080C5A62:\n"
        "    movs r0, #0x48\n"
        "    bl Flag_Test\n"
        "    b .L080C5B02\n"
        ".L080C5A6A:\n"
        "    movs r0, #0x49\n"
        "    bl Flag_Test\n"
        "    b .L080C5B02\n"
        ".L080C5A72:\n"
        "    movs r0, #0x2e\n"
        "    bl Flag_Test\n"
        "    b .L080C5B02\n"
        ".L080C5A7A:\n"
        "    movs r0, #0\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C5AA0\n"
        "    movs r0, #1\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C5AA0\n"
        "    movs r0, #2\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C5AA0\n"
        "    b .L080C5988\n"
        ".L080C5AA0:\n"
        "    movs r0, #0x55\n"
        "    bl Flag_Test\n"
        "    b .L080C5B02\n"
        ".L080C5AA8:\n"
        "    movs r0, #0\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C5ACE\n"
        "    movs r0, #1\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C5ACE\n"
        "    movs r0, #2\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C5ACE\n"
        "    b .L080C5988\n"
        ".L080C5ACE:\n"
        "    movs r0, #0xc9\n"
        "    bl Flag_Test\n"
        "    b .L080C5B02\n"
        ".L080C5AD6:\n"
        "    movs r0, #0x36\n"
        "    bl Flag_Test\n"
        "    b .L080C5B02\n"
        ".L080C5ADE:\n"
        "    movs r0, #0\n"
        "    b .L080C5AFC\n"
        ".L080C5AE2:\n"
        "    movs r0, #0\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C5B08\n"
        "    movs r0, #1\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C5B08\n"
        ".L080C5AFA:\n"
        "    movs r0, #2\n"
        ".L080C5AFC:\n"
        "    bl sub_080C2A84\n"
        "    lsls r0, r0, #0x10\n"
        ".L080C5B02:\n"
        "    cmp r0, #0\n"
        "    bne .L080C5B08\n"
        "    b .L080C5988\n"
        ".L080C5B08:\n"
        "    movs r0, #1\n"
        ".L080C5B0A:\n"
        "    pop {r4}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

// sub_080C5B10 @ 0x080C5B10
u32 sub_080C5B10(u16 id)
{
    if (*(const void **)(Action_GetRecord(id) + 4) == NULL)
        return TRUE;
    return Flag_Test((u16)(id + 0xFFF4));
}

// Party_SaveOrderHeroOnly @ 0x080C5B3C
/* Saves the party order to gPartyOrderSave and leaves only the hero in it. */
void Party_SaveOrderHeroOnly(void)
{
    u32 i;

    for (i = 0; i < 6; i++)
    {
        u8 m = gGameState.order[i];

        gPartyOrderSave[i] = m;
        if (m != 0 && m != 0xFF)
            Party_Remove(m, 0);
    }
    gGameState.order[0] = 0;
    gGameState.order[1] = -1;
    gGameState.order[2] = -1;
    gGameState.order[3] = -1;
    gGameState.order[4] = -1;
    gGameState.order[5] = -1;
    Party_BuildMemberNameTiles();
    Hud_LoadAllMemberFaces();
}

// Party_RestoreOrder @ 0x080C5BCC
/* Restores the party order saved by Party_SaveOrderHeroOnly. */
void Party_RestoreOrder(void)
{
    u32 i;

    for (i = 0; i < 6; i++)
    {
        u8 m = gPartyOrderSave[i];

        gGameState.order[i] = m;
        if (m != 0xFF)
            Party_GetMember(m + 0x8000)->unkE = 0xC000;
    }
    Party_BuildMemberNameTiles();
    Hud_LoadAllMemberFaces();
}

// sub_080C5C14 @ 0x080C5C14
u32 sub_080C5C14(u16 id)
{
    if (Inventory_GetCount(id) == 0 && !Flag_Test(gUnknown_081A66A0[id - 0x110]))
        return FALSE;
    return TRUE;
}

// Stock_HasRoom @ 0x080C5C50
/* TRUE while the demon stock has room. */
u32 Stock_HasRoom(void)
{
    u32 n = 0;
    u32 i;

    for (i = 0; i < 12; i++)
    {
        if (Combatant_IsUsed(i + 4))
            n++;
    }
    if (n >= Stock_GetCapacity())
        return FALSE;
    return TRUE;
}

// sub_080C5C7C @ 0x080C5C7C
/* Number of stocked demons with ids 0x16A-0x17B. */
u32 sub_080C5C7C(void)
{
    u32 n = 0;
    u32 i;

    for (i = 0; i < 12; i++)
    {
        if (Combatant_IsUsed(i + 4) && (u16)(Party_GetMember(i + 0x8004)->demonId - 0x16A) <= 0x11)
            n++;
    }
    return n;
}

// sub_080C5CC0 @ 0x080C5CC0
/* Number of party members with demon ids 0x16A-0x17B. */
#ifdef NONMATCHING
u32 sub_080C5CC0(void)
{
    u32 n = 0;
    u32 i;

    for (i = 0; i < 6; i++)
    {
        if (gGameState.order[i] != -1
            && (u16)(Party_GetMember(gGameState.order[i] + 0x8000)->demonId - 0x16A) <= 0x11)
            n++;
    }
    return n;
}
#else
NAKED
u32 sub_080C5CC0(void)
{
    asm_unified(
        ".L080C5CC0:\n"
        "    push {r4, r5, r6, lr}\n"
        "    movs r5, #0\n"
        "    movs r4, #0\n"
        "    ldr r6, .L080C5D04\n"
        ".L080C5CC8:\n"
        "    adds r0, r4, r6\n"
        "    movs r1, #0\n"
        "    ldrsb r1, [r0, r1]\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r1, r0\n"
        "    beq .L080C5CF6\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #8\n"
        "    adds r0, r1, r2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Party_GetMember\n"
        "    ldr r2, .L080C5D08\n"
        "    adds r1, r2, #0\n"
        "    ldrh r0, [r0, #0x12]\n"
        "    adds r1, r1, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    cmp r1, #0x11\n"
        "    bhi .L080C5CF6\n"
        "    adds r5, #1\n"
        ".L080C5CF6:\n"
        "    adds r4, #1\n"
        "    cmp r4, #5\n"
        "    bls .L080C5CC8\n"
        "    adds r0, r5, #0\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        ".L080C5D04: .4byte 0x030050E0 @ IWRAM+0x50E0\n"
        ".L080C5D08: .4byte 0xFFFFFE96\n"
    );
}
#endif
