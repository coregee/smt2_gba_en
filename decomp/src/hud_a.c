#include "global.h"
#include "inventory.h"

// Hud_Init @ 0x080C65E8
/* Sets up the field HUD state (gHudState) and its tilemap. */
void Hud_Init(void)
{
    u16 *hud;
    u16 y, w, h, nine;
    u16 *buf;   /* y, w, h and buf are the first panel's rectangle, reused for the HUD values */

    DmaFill16(3, 0, gHudState, 0x74);
    hud = gHudState;
    y = 0;
    hud[0xC] = 8;
    hud[4] = h = 3;
    hud[0xE] = w = 7;
    hud[6] = h;
    hud[0xF] = w;
    hud[7] = h;
    hud[9] = nine = 9;
    hud[1] = h;
    DmaFill16(3, y, gWindowTilemapBuffer, 0x800);
    buf = gWindowTilemapBuffer;
    if (sub_080C8AF8(*(u16 *)&gUnk_03004614) == 1)
    {
        Tilemap_CopyRectSkipZero(gUnknown_081B8270, buf, 0, 0, 1, y, w, h);
        if (gGameState.unkAC0 != 1)
        {
            Tilemap_CopyRectSkipZero(gUnknown_081B92B0, buf, 0, 0, 0xD, y, 4, 2);
        }
        else
        {
            hud[0xA] = h;
            hud[2] = h;
        }
        Tilemap_CopyRectSkipZero(gUnknown_081B8170, gWindowTilemapBuffer, 0, 0, 0x15, 0, 8, 2);
        sub_080C6558();
    }
    else
    {
        hud[8] = nine;
        hud[0] = h;
        hud[0xA] = h;
        hud[2] = h;
        hud[0xB] = nine;
        hud[3] = h;
        hud[0x18] = 1;
    }
    sub_080C65A4();
    Hud_UploadMoonTiles();
    Party_BuildMemberNameTiles();
    Hud_LoadAllMemberFaces();
    DmaFill32(3, 0, gUnk_0200E8D8, 0xF00);
    sub_080C8440();
    sub_080C65C8();
}

// sub_080C6734 @ 0x080C6734
void sub_080C6734(void)
{
    DmaCopy16(3, gWindowTilemapBuffer, (void *)0x06001000, 0x800);
    gHudState[0x36] = 0;
}

// sub_080C6764 @ 0x080C6764
void sub_080C6764(void)
{
    if (gMainCallback != sub_080D977C)
    {
        u16 *hud = gHudState;
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
    gHudState[0x1C] = gUnknown_0834A230[(u16)Encounter_GetDangerLevel()];
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

    if (gHudState[0x1B] == 1)
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
        VBlankTask_AddCounted(Hud_UploadMoonTiles, 1);
    }
    sub_080C745C();
    sub_080C76B4();
    if (!Flag_Test(0xC6) && gMainCallback != sub_080D977C)
    {
        u16 *hud = gHudState;
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
        u16 *base = gHudState;

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
