#include "global.h"
#include "menu2.h"

// sub_080D527C @ 0x080D527C
void sub_080D527C(void)
{
    struct SlotMenu *menu = SLOT_MENU;

    TextWindow_Close(menu->window28, 1);
    TextWindow_Close(menu->window2C, 1);
}

/* Door keypad: the entered code is digit0*1000 + ... (weights at 0x084F404C), 0xFFFF when a
   digit is still blank. Casino mode keeps the bet and starts the next task. */
// Keypad_StoreResult @ 0x080D529C
void Keypad_StoreResult(struct Task *task, u32 keepWindow)
{
    struct SlotMenu *menu = SLOT_MENU;
    u16 i;

    if (keepWindow == 0)
        Window_Close(menu->window14, 0);
    if (menu->unk0C == 0)
    {
        gYesNoResult = 0;
        for (i = 0; i < 4; i++)
        {
            if (menu->glyphs[i] == 0xFFFF)
            {
                gYesNoResult = 0xFFFF;
                return;
            }
            gYesNoResult += menu->glyphs[i] * gUnknown_084F404C[i];
        }
    }
    else
    {
        gUnk_030037F0 = Keypad_GetNumber();
        gUnk_03003FF0 = Task_Create(gUnknown_084F4028, 0xFFFF);
    }
}

// Door_KeypadInitInputState @ 0x080D5324
struct Task *Door_KeypadInitInputState(struct Task *parent)
{
    struct Task *task = Task_Create(gUnknown_084F4054, parent->id);
    struct SlotMenu *menu = SLOT_MENU;
    u32 zero = 0;

    CpuSet(&zero, menu, 0x05000200);
    menu->unk0C = 0;
    menu->glyphs[0] = 0xFFFF;
    menu->glyphs[1] = -1;
    menu->glyphs[2] = -1;
    menu->glyphs[3] = -1;
    menu->row = 1;
    menu->col = 1;
    return task;
}

/* Casino bet entry: like the keypad, in digit mode with the given bet unit. */
// Keypad_OpenNumberEntry @ 0x080D5374
void Keypad_OpenNumberEntry(u32 bet)
{
    struct Task *task = Task_Create(gUnknown_084F40D8, 0xFFFF);
    struct SlotMenu *menu = SLOT_MENU;
    u32 zero = 0;
    u32 i;

    CpuSet(&zero, menu, 0x05000200);
    menu->unk0C = 1;
    menu->bet = bet;
    for (i = 0; i < 8; i++)
        menu->digits[i] |= 0xFF;
    menu->row = 1;
    menu->col = 1;
    gUnk_030037F0 = 0;
    gUnk_03003FEC = task;
}

// sub_080D53E0 @ 0x080D53E0
u32 sub_080D53E0(void)
{
    u32 done = 0;

    if (gUnk_03003FEC->state == 0)
        done = 1;
    return done;
}

// sub_080D53FC @ 0x080D53FC
void sub_080D53FC(void)
{
    gUnk_03003FF0->wait = 1;
}

// sub_080D540C @ 0x080D540C
void sub_080D540C(void)
{
    sub_080C1450();
    gUnk_03000040 = 0;
    REG_DISPCNT &= 0xFEFF;
    REG_DISPCNT &= 0xFBFF;
    REG_DISPCNT &= 0xF7FF;
    REG_BG1CNT &= 0xFFBF;
    gUnk_0300003C = 0;
    DmaSet3(gUnk_02000000, (void *)0x06000000, 0x84001000);
    REG_IE = 0x2003;
    REG_DISPSTAT = 0x18;
    REG_IME = 1;
    Font_ResetGlyphSpriteCache(0x180);
    Task_ClearAll();
    VBlankTasks_Init();
    Task_Create(gUnknown_084F9A28, 0xFFFF);
    Music_Play(0x1C);
    gUnk_0203DB6A = 0;
    SetMainCallback(sub_080D54F0);
}

// sub_080D54E0 @ 0x080D54E0
void sub_080D54E0(void)
{
    SetMainCallback(sub_080D540C);
}

// sub_080D54F0 @ 0x080D54F0
void sub_080D54F0(void)
{
    Task_RunAll();
}

// sub_080D54FC @ 0x080D54FC
void sub_080D54FC(void)
{
    DmaSet3(gUnk_0200F874, (void *)0x06008000, 0x840012C0);
    DmaSet3(gUnk_0200F874 + 0x5000, (void *)0x06010000, 0x84000800);
    DmaSet3(gUnk_02000000, (void *)0x06001000, 0x84000140);
}

/* Loads the screen in steps (one per call): five LZ77 tile sheets, the sprites, then the
   tilemap with per-tile palettes from 0x084F8760, then fades in (7) or out (8). */
/* NONMATCHING: one scratch register (r3 instead of r0/r1) differs in the tilemap palette loop. */
// sub_080D5554 @ 0x080D5554
#ifdef NONMATCHING
void sub_080D5554(struct Task *task, u32 step)
{
    switch (step)
    {
    case 0:
        LZ77UnCompWram(gUnknown_084F4140, gUnk_0200F874);
        break;
    case 1:
        LZ77UnCompWram(gUnknown_084F5214, gUnk_0200F874 + 0x1000);
        break;
    case 2:
        LZ77UnCompWram(gUnknown_084F6108, gUnk_0200F874 + 0x2000);
        break;
    case 3:
        LZ77UnCompWram(gUnknown_084F6F7C, gUnk_0200F874 + 0x3000);
        break;
    case 4:
        LZ77UnCompWram(gUnknown_084F7C5C, gUnk_0200F874 + 0x4000);
        break;
    case 5:
        LZ77UnCompWram(gUnknown_084F89E0, gUnk_0200F874 + 0x5000);
        LZ77UnCompWram(gUnknown_084F8FF0, gUnk_0200F874 + 0x6000);
        break;
    case 6:
    {
        const u8 *pal = gUnknown_084F8760;
        u16 *map = (u16 *)gUnk_02000000;
        u16 x, y;

        Tilemap_CopyRectSkipZero(gUnknown_084F9528, gUnk_02000000, 0, 0, 0, 0, 0x1E, 0x14);
        for (y = 0; y < 0x14; y++)
        {
            for (x = 0; x < 0x1E; x++)
            {
                u16 *cell = &map[y * 32 + x];
                u8 c = *pal++;

                *cell = (*cell & 0xFFF) | ((c & 0xF) << 12);
            }
        }
        Palette_CopyWithEffect(3, gUnknown_084F93E8, gPaletteTarget, 0x100, 0x20);
        VBlankTask_AddCounted(sub_080D54FC, 1);
        break;
    }
    case 7:
        PalFade_FadeInFromBlack(4);
        break;
    case 8:
        PalFade_FadeToBlack(4);
        break;
    }
}
#else
NAKED
void sub_080D5554(struct Task *task, u32 step)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x10\n"
        "    cmp r1, #8\n"
        "    bls .L080D5566\n"
        "    b .L080D56CA\n"
        ".L080D5566:\n"
        "    lsls r0, r1, #2\n"
        "    ldr r1, .L080D5570\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        ".L080D5570: .4byte gUnknown_080D5574\n"
        "    .global gUnknown_080D5574\n"
        "gUnknown_080D5574:\n"
        ".L080D5574: @ jump table\n"
        "    .4byte .L080D5598\n"
        "    .4byte .L080D55AC\n"
        "    .4byte .L080D55C0\n"
        "    .4byte .L080D55D4\n"
        "    .4byte .L080D55E8\n"
        "    .4byte .L080D55FC\n"
        "    .4byte .L080D5624\n"
        "    .4byte .L080D56BC\n"
        "    .4byte .L080D56C4\n"
        ".L080D5598:\n"
        "    ldr r0, .L080D55A4\n"
        "    ldr r1, .L080D55A8\n"
        "    bl LZ77UnCompWram\n"
        "    b .L080D56CA\n"
        "    .byte 0x00, 0x00\n"
        ".L080D55A4: .4byte gUnknown_084F4140\n"
        ".L080D55A8: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L080D55AC:\n"
        "    ldr r0, .L080D55B8\n"
        "    ldr r1, .L080D55BC\n"
        "    bl LZ77UnCompWram\n"
        "    b .L080D56CA\n"
        "    .byte 0x00, 0x00\n"
        ".L080D55B8: .4byte gUnknown_084F5214\n"
        ".L080D55BC: .4byte 0x02010874 @ EWRAM+0x10874\n"
        ".L080D55C0:\n"
        "    ldr r0, .L080D55CC\n"
        "    ldr r1, .L080D55D0\n"
        "    bl LZ77UnCompWram\n"
        "    b .L080D56CA\n"
        "    .byte 0x00, 0x00\n"
        ".L080D55CC: .4byte gUnknown_084F6108\n"
        ".L080D55D0: .4byte 0x02011874 @ EWRAM+0x11874\n"
        ".L080D55D4:\n"
        "    ldr r0, .L080D55E0\n"
        "    ldr r1, .L080D55E4\n"
        "    bl LZ77UnCompWram\n"
        "    b .L080D56CA\n"
        "    .byte 0x00, 0x00\n"
        ".L080D55E0: .4byte gUnknown_084F6F7C\n"
        ".L080D55E4: .4byte 0x02012874 @ EWRAM+0x12874\n"
        ".L080D55E8:\n"
        "    ldr r0, .L080D55F4\n"
        "    ldr r1, .L080D55F8\n"
        "    bl LZ77UnCompWram\n"
        "    b .L080D56CA\n"
        "    .byte 0x00, 0x00\n"
        ".L080D55F4: .4byte gUnknown_084F7C5C\n"
        ".L080D55F8: .4byte 0x02013874 @ EWRAM+0x13874\n"
        ".L080D55FC:\n"
        "    ldr r0, .L080D5618\n"
        "    ldr r4, .L080D561C\n"
        "    adds r1, r4, #0\n"
        "    bl LZ77UnCompWram\n"
        "    ldr r0, .L080D5620\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #5\n"
        "    adds r4, r4, r1\n"
        "    adds r1, r4, #0\n"
        "    bl LZ77UnCompWram\n"
        "    b .L080D56CA\n"
        "    .byte 0x00, 0x00\n"
        ".L080D5618: .4byte gUnknown_084F89E0\n"
        ".L080D561C: .4byte 0x02014874 @ EWRAM+0x14874\n"
        ".L080D5620: .4byte gUnknown_084F8FF0\n"
        ".L080D5624:\n"
        "    ldr r7, .L080D56A0\n"
        "    ldr r0, .L080D56A4\n"
        "    mov sb, r0\n"
        "    ldr r0, .L080D56A8\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #0x1e\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0x14\n"
        "    str r1, [sp, #0xc]\n"
        "    mov r1, sb\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Tilemap_CopyRectSkipZero\n"
        "    movs r0, #0\n"
        "    ldr r1, .L080D56AC\n"
        "    mov sl, r1\n"
        "    movs r1, #0xf\n"
        "    mov ip, r1\n"
        "    ldr r1, .L080D56B0\n"
        "    mov r8, r1\n"
        ".L080D5652:\n"
        "    movs r4, #0\n"
        "    adds r6, r0, #1\n"
        "    lsls r5, r0, #5\n"
        ".L080D5658:\n"
        "    adds r2, r5, r4\n"
        "    lsls r2, r2, #1\n"
        "    add r2, sb\n"
        "    ldrb r1, [r7]\n"
        "    adds r7, #1\n"
        "    mov r0, ip\n"
        "    ands r1, r0\n"
        "    ldrh r3, [r2]\n"
        "    mov r0, r8\n"
        "    ands r0, r3\n"
        "    lsls r1, r1, #0xc\n"
        "    orrs r0, r1\n"
        "    strh r0, [r2]\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #0x1d\n"
        "    bls .L080D5658\n"
        "    lsls r0, r6, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #0x13\n"
        "    bls .L080D5652\n"
        "    movs r3, #0x80\n"
        "    lsls r3, r3, #1\n"
        "    movs r0, #0x20\n"
        "    str r0, [sp]\n"
        "    movs r0, #3\n"
        "    mov r1, sl\n"
        "    ldr r2, .L080D56B4\n"
        "    bl Palette_CopyWithEffect\n"
        "    ldr r0, .L080D56B8\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    b .L080D56CA\n"
        ".L080D56A0: .4byte gUnknown_084F8760\n"
        ".L080D56A4: .4byte 0x02000000 @ EWRAM\n"
        ".L080D56A8: .4byte gUnknown_084F9528\n"
        ".L080D56AC: .4byte gUnknown_084F93E8\n"
        ".L080D56B0: .4byte 0x00000FFF\n"
        ".L080D56B4: .4byte 0x030029B0 @ IWRAM+0x29B0\n"
        ".L080D56B8: .4byte sub_080D54FC\n"
        ".L080D56BC:\n"
        "    movs r0, #4\n"
        "    bl PalFade_FadeInFromBlack\n"
        "    b .L080D56CA\n"
        ".L080D56C4:\n"
        "    movs r0, #4\n"
        "    bl PalFade_FadeToBlack\n"
        ".L080D56CA:\n"
        "    add sp, #0x10\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif
