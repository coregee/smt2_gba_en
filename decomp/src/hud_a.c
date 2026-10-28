#include "global.h"
#include "inventory.h"

// Hud_Init @ 0x080C65E8
/* Sets up the field HUD state (gUnk_0200E7D4) and its tilemap. */
#ifdef NONMATCHING
void Hud_Init(void)
{
    u16 *hud = gUnk_0200E7D4;

    DmaFill16(3, 0, hud, 0x74);
    hud[0xC] = 8;
    hud[4] = 3;
    hud[0xE] = 7;
    hud[6] = 3;
    hud[0xF] = 7;
    hud[7] = 3;
    hud[9] = 9;
    hud[1] = 3;
    DmaFill16(3, 0, gWindowTilemapBuffer, 0x800);
    if (sub_080C8AF8(*(u16 *)&gUnk_03004614) == 1)
    {
        Tilemap_CopyRectSkipZero(gUnknown_081B8270, gWindowTilemapBuffer, 0, 0, 1, 0, 7, 3);
        if (gGameState.unkAC0 != 1)
        {
            Tilemap_CopyRectSkipZero(gUnknown_081B92B0, gWindowTilemapBuffer, 0, 0, 0xD, 0, 4, 2);
        }
        else
        {
            hud[0xA] = 3;
            hud[2] = 3;
        }
        Tilemap_CopyRectSkipZero(gUnknown_081B8170, gWindowTilemapBuffer, 0, 0, 0x15, 0, 8, 2);
        sub_080C6558();
    }
    else
    {
        hud[8] = 9;
        hud[0] = 3;
        hud[0xA] = 3;
        hud[2] = 3;
        hud[0xB] = 9;
        hud[3] = 3;
        hud[0x18] = 1;
    }
    sub_080C65A4();
    sub_080C7EFC();
    Party_BuildMemberNameTiles();
    sub_080C6FD8();
    DmaFill32(3, 0, gUnk_0200E8D8, 0xF00);
    sub_080C8440();
    sub_080C65C8();
}
#else
NAKED
void Hud_Init(void)
{
    asm_unified(
        ".L080C65E8:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sb\n"
        "    mov r6, r8\n"
        "    push {r6, r7}\n"
        "    sub sp, #0x18\n"
        "    add r1, sp, #0x10\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L080C6688\n"
        "    add r0, sp, #0x10\n"
        "    str r0, [r1]\n"
        "    ldr r4, .L080C668C\n"
        "    str r4, [r1, #4]\n"
        "    ldr r0, .L080C6690\n"
        "    str r0, [r1, #8]\n"
        "    ldr r0, [r1, #8]\n"
        "    movs r2, #0\n"
        "    mov sb, r2\n"
        "    movs r0, #8\n"
        "    strh r0, [r4, #0x18]\n"
        "    movs r5, #3\n"
        "    strh r5, [r4, #8]\n"
        "    movs r7, #7\n"
        "    strh r7, [r4, #0x1c]\n"
        "    strh r5, [r4, #0xc]\n"
        "    strh r7, [r4, #0x1e]\n"
        "    strh r5, [r4, #0xe]\n"
        "    movs r6, #9\n"
        "    strh r6, [r4, #0x12]\n"
        "    strh r5, [r4, #2]\n"
        "    add r0, sp, #0x10\n"
        "    mov r2, sb\n"
        "    strh r2, [r0]\n"
        "    str r0, [r1]\n"
        "    ldr r0, .L080C6694\n"
        "    mov r8, r0\n"
        "    str r0, [r1, #4]\n"
        "    ldr r0, .L080C6698\n"
        "    str r0, [r1, #8]\n"
        "    ldr r0, [r1, #8]\n"
        "    ldr r0, .L080C669C\n"
        "    ldrh r0, [r0]\n"
        "    bl sub_080C8AF8\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #1\n"
        "    bne .L080C66DC\n"
        "    ldr r0, .L080C66A0\n"
        "    str r1, [sp]\n"
        "    mov r1, sb\n"
        "    str r1, [sp, #4]\n"
        "    str r7, [sp, #8]\n"
        "    str r5, [sp, #0xc]\n"
        "    mov r1, r8\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Tilemap_CopyRectSkipZero\n"
        "    ldr r0, .L080C66A4\n"
        "    movs r2, #0xac\n"
        "    lsls r2, r2, #4\n"
        "    adds r0, r0, r2\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #1\n"
        "    beq .L080C66AC\n"
        "    ldr r0, .L080C66A8\n"
        "    movs r1, #0xd\n"
        "    str r1, [sp]\n"
        "    mov r1, sb\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #4\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #2\n"
        "    str r1, [sp, #0xc]\n"
        "    mov r1, r8\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Tilemap_CopyRectSkipZero\n"
        "    b .L080C66B0\n"
        ".L080C6688: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080C668C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
        ".L080C6690: .4byte 0x8100003A\n"
        ".L080C6694: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C6698: .4byte 0x81000400\n"
        ".L080C669C: .4byte 0x03004614 @ IWRAM+0x4614\n"
        ".L080C66A0: .4byte gUnknown_081B8270\n"
        ".L080C66A4: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080C66A8: .4byte gUnknown_081B92B0\n"
        ".L080C66AC:\n"
        "    strh r5, [r4, #0x14]\n"
        "    strh r5, [r4, #4]\n"
        ".L080C66B0:\n"
        "    ldr r0, .L080C66D4\n"
        "    ldr r1, .L080C66D8\n"
        "    movs r2, #0x15\n"
        "    str r2, [sp]\n"
        "    movs r2, #0\n"
        "    str r2, [sp, #4]\n"
        "    movs r2, #8\n"
        "    str r2, [sp, #8]\n"
        "    movs r2, #2\n"
        "    str r2, [sp, #0xc]\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Tilemap_CopyRectSkipZero\n"
        "    bl sub_080C6558\n"
        "    b .L080C66EC\n"
        "    .byte 0x00, 0x00\n"
        ".L080C66D4: .4byte gUnknown_081B8170\n"
        ".L080C66D8: .4byte 0x0200DFD4 @ EWRAM+0xDFD4\n"
        ".L080C66DC:\n"
        "    strh r6, [r4, #0x10]\n"
        "    strh r5, [r4]\n"
        "    strh r5, [r4, #0x14]\n"
        "    strh r5, [r4, #4]\n"
        "    strh r6, [r4, #0x16]\n"
        "    strh r5, [r4, #6]\n"
        "    movs r0, #1\n"
        "    strh r0, [r4, #0x30]\n"
        ".L080C66EC:\n"
        "    bl sub_080C65A4\n"
        "    bl sub_080C7EFC\n"
        "    bl Party_BuildMemberNameTiles\n"
        "    bl sub_080C6FD8\n"
        "    movs r0, #0\n"
        "    str r0, [sp, #0x14]\n"
        "    ldr r1, .L080C6728\n"
        "    add r0, sp, #0x14\n"
        "    str r0, [r1]\n"
        "    ldr r0, .L080C672C\n"
        "    str r0, [r1, #4]\n"
        "    ldr r0, .L080C6730\n"
        "    str r0, [r1, #8]\n"
        "    ldr r0, [r1, #8]\n"
        "    bl sub_080C8440\n"
        "    bl sub_080C65C8\n"
        "    add sp, #0x18\n"
        "    pop {r3, r4}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080C6728: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080C672C: .4byte 0x0200E8D8 @ EWRAM+0xE8D8\n"
        ".L080C6730: .4byte 0x850003C0\n"
    );
}
#endif

// sub_080C6734 @ 0x080C6734
void sub_080C6734(void)
{
    DmaCopy16(3, gWindowTilemapBuffer, (void *)0x06001000, 0x800);
    gUnk_0200E7D4[0x36] = 0;
}

// sub_080C6764 @ 0x080C6764
void sub_080C6764(void)
{
    if (gMainCallback != sub_080D977C)
    {
        u16 *hud = gUnk_0200E7D4;
        u16 *pending = &hud[0x36];

        if (*pending == 0)
        {
            VBlankTask_AddCounted(sub_080C6734, 1);
            *pending = 1;
        }
    }
}

// sub_080C67A0 @ 0x080C67A0
void sub_080C67A0(void)
{
    gUnk_0200E7D4[0x1C] = gUnknown_0834A230[(u16)Encounter_GetDangerLevel()];
}

// sub_080C67C0 @ 0x080C67C0
/* Copies the danger-level palette row into palette row 'row' (colours 15..) of pal. */
#ifdef NONMATCHING
void sub_080C67C0(u16 *pal, u16 row)
{
    u16 lvl = Encounter_GetDangerLevel();
    u16 *dst = &pal[(u16)(row << 4)] + 0x10F;

    sub_080C7EB4((const u8 *)gUnknown_081B7030 + gUnknown_0834A224[lvl], dst);
    sub_080C67A0();
}
#else
NAKED
void sub_080C67C0(u16 *pal, u16 row)
{
    asm_unified(
        ".L080C67C0:\n"
        "    push {r4, r5, lr}\n"
        "    adds r5, r0, #0\n"
        "    lsls r4, r1, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    bl Encounter_GetDangerLevel\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    lsls r0, r4, #0x14\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r5\n"
        "    ldr r1, .L080C67F8\n"
        "    adds r3, r0, r1\n"
        "    ldr r1, .L080C67FC\n"
        "    lsls r0, r2, #1\n"
        "    adds r0, r0, r1\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L080C6800\n"
        "    adds r0, r1, r0\n"
        "    adds r1, r3, #0\n"
        "    bl sub_080C7EB4\n"
        "    bl sub_080C67A0\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080C67F8: .4byte 0x0000021E\n"
        ".L080C67FC: .4byte gUnknown_0834A224\n"
        ".L080C6800: .4byte gUnknown_081B7030\n"
    );
}
#endif

// Hud_Update @ 0x080C6804
/* Field HUD per-frame update; party member panels are drawn in a rotating order. */
void Hud_Update(void)
{
    u16 *p;

    if (gUnk_0200E7D4[0x1B] == 1)
        return;
    if (gFieldState.unk00 == 1)
    {
        sub_080C700C();
        sub_080C7234();
        sub_080C7430();
    }
    else if (gFieldState.unk00 == 0x19)
    {
        sub_080C6FF0();
        sub_080C7218();
        sub_080C7414();
    }
    sub_080C726C();
    sub_080C7880();
    sub_080C7AFC();
    sub_080C71EC();
    if ((gFrameCounter & 0xF) == 0)
    {
        gGameState.unkA27 = (gGameState.unkA27 + 1) & 7;
        VBlankTask_AddCounted(sub_080C7EFC, 1);
    }
    sub_080C745C();
    sub_080C76B4();
    if (!Flag_Test(0xC6) && gMainCallback != sub_080D977C)
    {
        u16 *hud = gUnk_0200E7D4;
        u16 t = hud[0x18];

        if (t == 0)
            Sprite_Draw(gUnknown_080005DC, 1, 0, 1, t, 0x78, 0x60);
        if (hud[0x1C] == 0 || --hud[0x1C] == 0)
        {
            u16 v = hud[0x1A];

            if (v == 0)
            {
                u16 n;

                sub_080C67C0(gPaletteBuffer, 7);
                n = sub_080C7E90();
                hud[0x19]++;
                if (*(vu16 *)&hud[0x19] == n)
                    hud[0x19] = v;
                Palette_MarkDirty();
            }
        }
    }
    gUnk_0200F7F0 = 0;
    {
        u16 *base = gUnk_0200E7D4;

        p = &base[0x39];
    }
    if (++*p > 5)
        *p = 0;
    switch (*p)
    {
    case 0:
        Hud_DrawMemberPanel(0, 0x0C, 0x6B);
        Hud_DrawMemberPanel(1, 0x59, 0x6B);
        Hud_DrawMemberPanel(2, 0xA6, 0x6B);
        Hud_DrawMemberPanel(3, 0x0C, 0x87);
        Hud_DrawMemberPanel(4, 0x59, 0x87);
        Hud_DrawMemberPanel(5, 0xA6, 0x87);
        break;
    case 1:
        Hud_DrawMemberPanel(1, 0x59, 0x6B);
        Hud_DrawMemberPanel(2, 0xA6, 0x6B);
        Hud_DrawMemberPanel(3, 0x0C, 0x87);
        Hud_DrawMemberPanel(4, 0x59, 0x87);
        Hud_DrawMemberPanel(5, 0xA6, 0x87);
        Hud_DrawMemberPanel(0, 0x0C, 0x6B);
        break;
    case 2:
        Hud_DrawMemberPanel(2, 0xA6, 0x6B);
        Hud_DrawMemberPanel(3, 0x0C, 0x87);
        Hud_DrawMemberPanel(4, 0x59, 0x87);
        Hud_DrawMemberPanel(5, 0xA6, 0x87);
        Hud_DrawMemberPanel(0, 0x0C, 0x6B);
        Hud_DrawMemberPanel(1, 0x59, 0x6B);
        break;
    case 3:
        Hud_DrawMemberPanel(3, 0x0C, 0x87);
        Hud_DrawMemberPanel(4, 0x59, 0x87);
        Hud_DrawMemberPanel(5, 0xA6, 0x87);
        Hud_DrawMemberPanel(0, 0x0C, 0x6B);
        Hud_DrawMemberPanel(1, 0x59, 0x6B);
        Hud_DrawMemberPanel(2, 0xA6, 0x6B);
        break;
    case 4:
        Hud_DrawMemberPanel(4, 0x59, 0x87);
        Hud_DrawMemberPanel(5, 0xA6, 0x87);
        Hud_DrawMemberPanel(0, 0x0C, 0x6B);
        Hud_DrawMemberPanel(1, 0x59, 0x6B);
        Hud_DrawMemberPanel(2, 0xA6, 0x6B);
        Hud_DrawMemberPanel(3, 0x0C, 0x87);
        break;
    case 5:
        Hud_DrawMemberPanel(5, 0xA6, 0x87);
        Hud_DrawMemberPanel(0, 0x0C, 0x6B);
        Hud_DrawMemberPanel(1, 0x59, 0x6B);
        Hud_DrawMemberPanel(2, 0xA6, 0x6B);
        Hud_DrawMemberPanel(3, 0x0C, 0x87);
        Hud_DrawMemberPanel(4, 0x59, 0x87);
        break;
    }
    if (gUnk_0200F7F0 == 1)
        VBlankTask_AddCounted(sub_080C8440, 1);
}
