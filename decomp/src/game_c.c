/* Field helpers after the field main loop. */

#include "global.h"
#include "game.h"

// sub_080B1A1C @ 0x080B1A1C
u16 sub_080B1A1C(u16 a)
{
    return gUnknown_0815F2FC[a][1];
}

// sub_080B1A30 @ 0x080B1A30
void sub_080B1A30(u16 a, u16 b)
{
    gFieldState.unk0A = a;
    sub_080B2030(a, b, 3);
}

// sub_080B1A4C @ 0x080B1A4C
void sub_080B1A4C(u16 a, u16 b)
{
    s32 r = View_IsSideOpen(2);
    u16 saved;

    if (r == 1)
    {
        sub_080B09C4(0, 1);
        Field_Step(a);
        sub_080B2840(1, 0, 0);
        gFieldState.unk08 = r;
        gFieldState.unk3E = 0;
    }
    else if (b == 1)
    {
        Task_Create(gUnknown_08165380, 0xFFFF);
        Field_SetState(0x1A);
        return;
    }
    else
    {
        gFieldState.unk08 = 0;
        sub_080C51D4(0x69);
        gFieldState.unk3E = 1;
    }
    gFieldState.unk1E = 12;
    gFieldState.unk06 = a;
    saved = gUnk_03003FF4;
    Field_SetState(5);
    gUnk_03003FF4 = saved;
}

// sub_080B1AD8 @ 0x080B1AD8
void sub_080B1AD8(u16 a, u16 b)
{
    struct Unk03004550 *s = &gFieldState;
    s32 r = View_GetWall(0, 0, 0);

    if (r == 3)
    {
        sub_080B1A30(a, b);
    }
    else if (r == 2)
    {
        s->unk0A = a;
        sub_080B2030(a, b, 3);
    }
    else
    {
        s->unk0A = a;
        sub_080B2030(a, b, 2);
    }
    if (r != 1)
        gFieldState.unk3E = 0;
    else
        gFieldState.unk3E = r;
}

// sub_080B1B58 @ 0x080B1B58
s32 sub_080B1B58(void)
{
    if (sub_080C8AF8(gUnk_03004614) == 1 && gUnk_0200E7D4[2] != 0)
        return 0;
    if (sub_080C8AF8(gUnk_03004614) == 1 && gUnk_0200E7D4[0] != 0)
        return 0;
    if (sub_080C8AF8(gUnk_03004614) == 1 && gUnk_0200E7D4[3] != 0)
        return 0;
    if (sub_080B78A4() != 0)
        return 0;
    if (Palette_IsBg13Black() == 1)
        return 0;
    if (PalFade_AllDone() == 0)
        return 0;
    return 1;
}

// sub_080B1BC4 @ 0x080B1BC4
void sub_080B1BC4(void)
{
    Field_SetState(10);
    gUnk_03003BB8 = 0;
}

// sub_080B1BDC @ 0x080B1BDC
void sub_080B1BDC(void)
{
    if (sub_080B953C() == 1)
    {
        sub_080AD6E4(0);
        gFieldState.unk1E = 0;
        gFieldState.unk2E = 0x22;
        sub_080C7218();
        sub_080C6FF0();
        sub_080C7414();
    }
    else if (sub_080F3190() != 0)
    {
        sub_0812A730();
    }
}

/* NONMATCHING: keys stays in a stack slot and unk3A is reloaded in the original; registers differ. */
// Field_HandleInput @ 0x080B1C18
#ifdef NONMATCHING
/* Field input: events under the player, menu/map keys, then movement from the D-pad. */
void Field_HandleInput(u16 keys)
{
    u16 dest = 0xFFFF;
    u16 dir = gFieldState.unk02;
    s16 move = 0;
    u8 stairs = FALSE;
    struct FieldEvent *ev;
    u16 id;
    u16 unused;

    Automap_SetVisited(gFieldState.unk12, gFieldState.unk14);
    if (gFieldState.unk40 == 0 && gFieldState.unk3E == 0
        && (ev = sub_080C9084(gFieldState.unk12, gFieldState.unk14, gFieldState.unk02, &id)) != NULL
        && id != 0xFFFF
        && sub_080C2480(id) == 1
        && sub_080AF0AC(ev->script) != 0)
    {
        gFieldState.unk40 = sub_080B828C();
        return;
    }
    if (sub_080B1B58() == 1)
    {
        if (gFieldState.unk3A & 1)
        {
            if (gFieldState.unk40 != 0)
            {
                if (*(u16 *)(gFieldState.unk40 + 0x1E) != 0)
                {
                    struct FieldEvent *ev2 = sub_080C9084(gFieldState.unk12, gFieldState.unk14, gFieldState.unk02, &unused);
                    sub_080AF7E8(ev2, ev2, 0);
                }
            }
            else if (!Flag_Test(0xAE))
            {
                sub_08128B84(0);
                Field_SetState(10);
            }
            return;
        }
        if ((gFieldState.unk3A & 8) && sub_080B9568() == 1)
        {
            sub_080C51D4(0x67);
            sub_0812D0FC(0);
            Field_SetState(10);
            gUnk_03003BB8 = 0;
            if (FieldMap_HasRecordRel(0, 0, 6) != 1)
            {
                gUnk_0300452C = PalFade_FadeRangeToBlackWithDuration(0xD0, 0x30, 4, 4);
                if (gPaletteBuffer[0] != 0)
                    PalFade_FadeRangeToBlackWithDuration(0, 1, 4, 4);
            }
            return;
        }
        if (gFieldState.unk3A & 0x100)
        {
            if (sub_0812A730() != 0)
            {
                if (sub_080F3190() == 0)
                    sub_080C51D4(0x65);
                sub_080B1BC4();
            }
            return;
        }
    }
    if ((sub_080F3F44() & 0x100) && gFieldState.unk58 == 0)
        gFieldState.unk58 = sub_080C57B4();
    if (sub_080B1B58() == 1)
    {
        if (keys & 2)
        {
            if (keys & 0x10)
            {
                dest = gUnknown_0815F324[dir][0];
                move = 1;
            }
            else if (keys & 0x20)
            {
                dest = gUnknown_0815F324[dir][1];
                move = 2;
            }
            else if (keys & 0x80)
            {
                dest = gUnknown_0815F31C[dir];
                stairs = TRUE;
            }
            else if (keys & 0x40)
            {
                dest = gUnknown_0815F2FC[dir][0];
                gFieldState.unk0A = 8;
            }
            else if (keys & 0x200)
            {
                sub_080B1BDC();
            }
        }
        else
        {
            if (keys & 0x10)
            {
                dest = gUnknown_0815F2FC[dir][3];
            }
            else if (keys & 0x20)
            {
                dest = gUnknown_0815F2FC[dir][2];
            }
            else if (keys & 0x80)
            {
                dest = gUnknown_0815F2FC[dir][1];
            }
            else if (keys & 0x40)
            {
                dest = gUnknown_0815F2FC[dir][0];
                gFieldState.unk0A = 12;
            }
            else if (keys & 0x200)
            {
                sub_080B1BDC();
            }
        }
    }
    if (dest == 0xFFFF)
        return;
    if (move != 0)
    {
        gFieldState.unk1E = 12;
        gFieldState.unk08 = move;
        gFieldState.unk06 = dest;
        Field_SetState(8);
        gFieldState.unk3E = 0;
        if (gFieldState.unk08 == 1)
        {
            if (View_IsSideOpen(1) == 1)
            {
                gUnk_03004540 = -16;
            }
            else
            {
                gUnk_03004540 = -8;
                gFieldState.unk3E = 1;
            }
        }
        else
        {
            if (View_IsSideOpen(3) == 1)
            {
                gUnk_03004540 = 16;
            }
            else
            {
                gUnk_03004540 = 8;
                gFieldState.unk3E = 1;
            }
        }
        sub_080B2840(3, gUnk_03004540, 0);
    }
    else if (stairs == TRUE)
    {
        sub_080B1A4C(dest, 0);
    }
    else if (dest != gFieldState.unk02)
    {
        if (keys & 0x10)
            move = 1;
        else if (keys & 0x20)
            move = -1;
        else if (keys & 0x80)
            move = 1;
        sub_080B2064(dest, move);
        Field_SetState(6);
        gFieldState.unk3E = 0;
    }
    else
    {
        sub_080B1AD8(gFieldState.unk0A, gFieldState.unk02);
    }
}
#else
NAKED
void Field_HandleInput(u16 keys)
{
    asm_unified(
        ".L080B1C18:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #8\n"
        "    mov r1, sp\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L080B1C84\n"
        "    mov r8, r0\n"
        "    ldr r5, .L080B1C88\n"
        "    ldrh r7, [r5, #2]\n"
        "    movs r2, #0\n"
        "    mov sb, r2\n"
        "    mov sl, r2\n"
        "    ldrh r0, [r5, #0x12]\n"
        "    ldrh r1, [r5, #0x14]\n"
        "    bl Automap_SetVisited\n"
        "    ldr r0, [r5, #0x40]\n"
        "    cmp r0, #0\n"
        "    bne .L080B1C8C\n"
        "    ldrh r0, [r5, #0x3e]\n"
        "    cmp r0, #0\n"
        "    bne .L080B1C8C\n"
        "    ldrh r0, [r5, #0x12]\n"
        "    ldrh r1, [r5, #0x14]\n"
        "    ldrh r2, [r5, #2]\n"
        "    mov r4, sp\n"
        "    adds r4, #2\n"
        "    adds r3, r4, #0\n"
        "    bl sub_080C9084\n"
        "    adds r6, r0, #0\n"
        "    cmp r6, #0\n"
        "    beq .L080B1C8C\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, r8\n"
        "    beq .L080B1C8C\n"
        "    bl sub_080C2480\n"
        "    cmp r0, #1\n"
        "    bne .L080B1C8C\n"
        "    ldr r0, [r6, #4]\n"
        "    bl sub_080AF0AC\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L080B1C8C\n"
        "    bl sub_080B828C\n"
        "    str r0, [r5, #0x40]\n"
        "    b .L080B1FFC\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1C84: .4byte 0x0000FFFF\n"
        ".L080B1C88: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B1C8C:\n"
        "    bl sub_080B1B58\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #1\n"
        "    bne .L080B1D88\n"
        "    ldr r2, .L080B1CC8\n"
        "    ldrh r0, [r2, #0x3a]\n"
        "    adds r4, r0, #0\n"
        "    ands r4, r1\n"
        "    cmp r4, #0\n"
        "    beq .L080B1CE6\n"
        "    ldr r0, [r2, #0x40]\n"
        "    cmp r0, #0\n"
        "    beq .L080B1CCC\n"
        "    ldrh r0, [r0, #0x1e]\n"
        "    cmp r0, #0\n"
        "    bne .L080B1CB0\n"
        "    b .L080B1FFC\n"
        ".L080B1CB0:\n"
        "    ldrh r0, [r2, #0x12]\n"
        "    ldrh r1, [r2, #0x14]\n"
        "    ldrh r2, [r2, #2]\n"
        "    add r3, sp, #4\n"
        "    bl sub_080C9084\n"
        "    adds r1, r0, #0\n"
        "    movs r2, #0\n"
        "    bl sub_080AF7E8\n"
        "    b .L080B1FFC\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1CC8: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B1CCC:\n"
        "    movs r0, #0xae\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    beq .L080B1CD8\n"
        "    b .L080B1FFC\n"
        ".L080B1CD8:\n"
        "    movs r0, #0\n"
        "    bl sub_08128B84\n"
        "    movs r0, #0xa\n"
        "    bl Field_SetState\n"
        "    b .L080B1FFC\n"
        ".L080B1CE6:\n"
        "    ldrh r1, [r2, #0x3a]\n"
        "    movs r0, #8\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080B1D54\n"
        "    bl sub_080B9568\n"
        "    cmp r0, #1\n"
        "    bne .L080B1D54\n"
        "    movs r0, #0x67\n"
        "    bl sub_080C51D4\n"
        "    movs r0, #0\n"
        "    bl sub_0812D0FC\n"
        "    movs r0, #0xa\n"
        "    bl Field_SetState\n"
        "    ldr r0, .L080B1D48\n"
        "    str r4, [r0]\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #6\n"
        "    bl FieldMap_HasRecordRel\n"
        "    cmp r0, #1\n"
        "    bne .L080B1D1E\n"
        "    b .L080B1FFC\n"
        ".L080B1D1E:\n"
        "    movs r0, #0xd0\n"
        "    movs r1, #0x30\n"
        "    movs r2, #4\n"
        "    movs r3, #4\n"
        "    bl PalFade_FadeRangeToBlackWithDuration\n"
        "    ldr r1, .L080B1D4C\n"
        "    str r0, [r1]\n"
        "    ldr r0, .L080B1D50\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L080B1D38\n"
        "    b .L080B1FFC\n"
        ".L080B1D38:\n"
        "    movs r0, #0\n"
        "    movs r1, #1\n"
        "    movs r2, #4\n"
        "    movs r3, #4\n"
        "    bl PalFade_FadeRangeToBlackWithDuration\n"
        "    b .L080B1FFC\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1D48: .4byte 0x03003BB8 @ IWRAM+0x3BB8\n"
        ".L080B1D4C: .4byte 0x0300452C @ IWRAM+0x452C\n"
        ".L080B1D50: .4byte 0x03002DB0 @ IWRAM+0x2DB0\n"
        ".L080B1D54:\n"
        "    ldr r0, .L080B1D84\n"
        "    ldrh r1, [r0, #0x3a]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080B1D88\n"
        "    bl sub_0812A730\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080B1D6E\n"
        "    b .L080B1FFC\n"
        ".L080B1D6E:\n"
        "    bl sub_080F3190\n"
        "    cmp r0, #0\n"
        "    bne .L080B1D7C\n"
        "    movs r0, #0x65\n"
        "    bl sub_080C51D4\n"
        ".L080B1D7C:\n"
        "    bl sub_080B1BC4\n"
        "    b .L080B1FFC\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1D84: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B1D88:\n"
        "    bl sub_080F3F44\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #1\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080B1DA4\n"
        "    ldr r4, .L080B1DD8\n"
        "    ldr r0, [r4, #0x58]\n"
        "    cmp r0, #0\n"
        "    bne .L080B1DA4\n"
        "    bl sub_080C57B4\n"
        "    str r0, [r4, #0x58]\n"
        ".L080B1DA4:\n"
        "    bl sub_080B1B58\n"
        "    cmp r0, #1\n"
        "    beq .L080B1DAE\n"
        "    b .L080B1EEA\n"
        ".L080B1DAE:\n"
        "    mov r0, sp\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080B1E60\n"
        "    mov r0, sp\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x10\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080B1DE0\n"
        "    ldr r1, .L080B1DDC\n"
        "    lsls r0, r7, #2\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    mov r8, r0\n"
        "    movs r0, #1\n"
        "    mov sb, r0\n"
        "    b .L080B1EEA\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1DD8: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B1DDC: .4byte gUnknown_0815F324\n"
        ".L080B1DE0:\n"
        "    mov r0, sp\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x20\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080B1E04\n"
        "    ldr r0, .L080B1E00\n"
        "    lsls r1, r7, #2\n"
        "    adds r0, #2\n"
        "    adds r1, r1, r0\n"
        "    ldrh r1, [r1]\n"
        "    mov r8, r1\n"
        "    movs r2, #2\n"
        "    mov sb, r2\n"
        "    b .L080B1EEA\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1E00: .4byte gUnknown_0815F324\n"
        ".L080B1E04:\n"
        "    mov r0, sp\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x80\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080B1E24\n"
        "    ldr r1, .L080B1E20\n"
        "    lsls r0, r7, #1\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    mov r8, r0\n"
        "    movs r0, #1\n"
        "    mov sl, r0\n"
        "    b .L080B1EEA\n"
        ".L080B1E20: .4byte gUnknown_0815F31C\n"
        ".L080B1E24:\n"
        "    mov r0, sp\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x40\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080B1E4C\n"
        "    ldr r1, .L080B1E44\n"
        "    lsls r0, r7, #3\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    mov r8, r0\n"
        "    ldr r1, .L080B1E48\n"
        "    movs r0, #8\n"
        "    strh r0, [r1, #0xa]\n"
        "    b .L080B1EEA\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1E44: .4byte gUnknown_0815F2FC\n"
        ".L080B1E48: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B1E4C:\n"
        "    mov r0, sp\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080B1EEA\n"
        "    bl sub_080B1BDC\n"
        "    b .L080B1EEA\n"
        ".L080B1E60:\n"
        "    mov r0, sp\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x10\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080B1E78\n"
        "    ldr r0, .L080B1E74\n"
        "    lsls r1, r7, #3\n"
        "    adds r0, #6\n"
        "    b .L080B1EA2\n"
        ".L080B1E74: .4byte gUnknown_0815F2FC\n"
        ".L080B1E78:\n"
        "    mov r0, sp\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x20\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080B1E90\n"
        "    ldr r0, .L080B1E8C\n"
        "    lsls r1, r7, #3\n"
        "    adds r0, #4\n"
        "    b .L080B1EA2\n"
        ".L080B1E8C: .4byte gUnknown_0815F2FC\n"
        ".L080B1E90:\n"
        "    mov r0, sp\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x80\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080B1EB0\n"
        "    ldr r0, .L080B1EAC\n"
        "    lsls r1, r7, #3\n"
        "    adds r0, #2\n"
        ".L080B1EA2:\n"
        "    adds r1, r1, r0\n"
        "    ldrh r1, [r1]\n"
        "    mov r8, r1\n"
        "    b .L080B1EEA\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1EAC: .4byte gUnknown_0815F2FC\n"
        ".L080B1EB0:\n"
        "    mov r0, sp\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x40\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080B1ED8\n"
        "    ldr r1, .L080B1ED0\n"
        "    lsls r0, r7, #3\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    mov r8, r0\n"
        "    ldr r1, .L080B1ED4\n"
        "    movs r0, #0xc\n"
        "    strh r0, [r1, #0xa]\n"
        "    b .L080B1EEA\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1ED0: .4byte gUnknown_0815F2FC\n"
        ".L080B1ED4: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B1ED8:\n"
        "    mov r0, sp\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080B1EEA\n"
        "    bl sub_080B1BDC\n"
        ".L080B1EEA:\n"
        "    ldr r2, .L080B1F2C\n"
        "    cmp r8, r2\n"
        "    bne .L080B1EF2\n"
        "    b .L080B1FFC\n"
        ".L080B1EF2:\n"
        "    mov r0, sb\n"
        "    cmp r0, #0\n"
        "    beq .L080B1F88\n"
        "    ldr r5, .L080B1F30\n"
        "    movs r4, #0\n"
        "    movs r0, #0xc\n"
        "    strh r0, [r5, #0x1e]\n"
        "    mov r2, sb\n"
        "    strh r2, [r5, #8]\n"
        "    mov r0, r8\n"
        "    strh r0, [r5, #6]\n"
        "    movs r0, #8\n"
        "    bl Field_SetState\n"
        "    strh r4, [r5, #0x3e]\n"
        "    movs r2, #8\n"
        "    ldrsh r4, [r5, r2]\n"
        "    cmp r4, #1\n"
        "    bne .L080B1F54\n"
        "    movs r0, #1\n"
        "    bl View_IsSideOpen\n"
        "    cmp r0, #1\n"
        "    bne .L080B1F3C\n"
        "    ldr r1, .L080B1F34\n"
        "    ldr r2, .L080B1F38\n"
        "    adds r0, r2, #0\n"
        "    b .L080B1F62\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1F2C: .4byte 0x0000FFFF\n"
        ".L080B1F30: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B1F34: .4byte 0x03004540 @ IWRAM+0x4540\n"
        ".L080B1F38: .4byte 0x0000FFF0\n"
        ".L080B1F3C:\n"
        "    ldr r1, .L080B1F4C\n"
        "    ldr r2, .L080B1F50\n"
        "    adds r0, r2, #0\n"
        "    strh r0, [r1]\n"
        "    strh r4, [r5, #0x3e]\n"
        "    adds r0, r1, #0\n"
        "    b .L080B1F76\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1F4C: .4byte 0x03004540 @ IWRAM+0x4540\n"
        ".L080B1F50: .4byte 0x0000FFF8\n"
        ".L080B1F54:\n"
        "    movs r0, #3\n"
        "    bl View_IsSideOpen\n"
        "    cmp r0, #1\n"
        "    bne .L080B1F6C\n"
        "    ldr r1, .L080B1F68\n"
        "    movs r0, #0x10\n"
        ".L080B1F62:\n"
        "    strh r0, [r1]\n"
        "    adds r0, r1, #0\n"
        "    b .L080B1F76\n"
        ".L080B1F68: .4byte 0x03004540 @ IWRAM+0x4540\n"
        ".L080B1F6C:\n"
        "    ldr r0, .L080B1F84\n"
        "    movs r1, #8\n"
        "    strh r1, [r0]\n"
        "    movs r1, #1\n"
        "    strh r1, [r5, #0x3e]\n"
        ".L080B1F76:\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #3\n"
        "    movs r2, #0\n"
        "    bl sub_080B2840\n"
        "    b .L080B1FFC\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1F84: .4byte 0x03004540 @ IWRAM+0x4540\n"
        ".L080B1F88:\n"
        "    mov r0, sl\n"
        "    cmp r0, #1\n"
        "    bne .L080B1F98\n"
        "    mov r0, r8\n"
        "    movs r1, #0\n"
        "    bl sub_080B1A4C\n"
        "    b .L080B1FFC\n"
        ".L080B1F98:\n"
        "    ldr r1, .L080B1FB4\n"
        "    ldrh r0, [r1, #2]\n"
        "    cmp r8, r0\n"
        "    beq .L080B1FF4\n"
        "    mov r0, sp\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x10\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080B1FB8\n"
        "    movs r2, #1\n"
        "    mov sb, r2\n"
        "    b .L080B1FD8\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1FB4: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B1FB8:\n"
        "    mov r0, sp\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x20\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080B1FC8\n"
        "    mov sb, r2\n"
        "    b .L080B1FD8\n"
        ".L080B1FC8:\n"
        "    mov r0, sp\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x80\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080B1FD8\n"
        "    movs r0, #1\n"
        "    mov sb, r0\n"
        ".L080B1FD8:\n"
        "    mov r0, r8\n"
        "    mov r1, sb\n"
        "    bl sub_080B2064\n"
        "    movs r0, #6\n"
        "    bl Field_SetState\n"
        "    ldr r1, .L080B1FF0\n"
        "    movs r0, #0\n"
        "    strh r0, [r1, #0x3e]\n"
        "    b .L080B1FFC\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1FF0: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B1FF4:\n"
        "    ldrh r0, [r1, #0xa]\n"
        "    ldrh r1, [r1, #2]\n"
        "    bl sub_080B1AD8\n"
        ".L080B1FFC:\n"
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

// Field_SetFacing @ 0x080B200C
/* Turns to dir; returns 1 when already facing it. */
u32 Field_SetFacing(u16 dir)
{
    if (dir != gFieldState.unk02)
    {
        gFieldState.unk04 = gFieldState.unk02;
        gFieldState.unk02 = dir;
        return 0;
    }
    return 1;
}

// sub_080B2030 @ 0x080B2030
void sub_080B2030(u16 a, u16 b, u16 state)
{
    sub_080B2840(1, 0, 0);
    gFieldState.unk1E = a;
    gFieldState.unk06 = b;
    Field_SetState(state);
}

// sub_080B2064 @ 0x080B2064
void sub_080B2064(u16 a, u16 b)
{
    sub_080B2840(2, 0, 0);
    gFieldState.unk1E = 0x10;
    gFieldState.unk08 = b;
    gFieldState.unk06 = a;
}

// sub_080B2090 @ 0x080B2090
s32 sub_080B2090(void)
{
    struct Unk03004550 *s = &gFieldState;
    u16 step = s->unk1E;
    u16 busy;

    s->unk1E--;
    if (s->unk1E == 8)
    {
        if (s->unk0E != 0)
            goto wait;
        sub_080AE494(sub_080B01C8);
        s->unk2E = 0x22;
    }
    else if (s->unk1E == 7)
    {
        Field_SetFacing((s->unk02 + s->unk08) & 3);
        sub_080B2840(0, 0, 0);
    }
    else if (s->unk1E == 0)
    {
        if ((busy = s->unk0E) != 0)
            goto wait;
        sub_080AE494(sub_080B0158);
        s->unk2E = busy;
        if (s->unk02 == s->unk06)
            return 1;
        return 7;
    }
    return -1;
wait:
    s->unk1E = step;
    return -1;
}

/* NONMATCHING: readable C only (708 bytes); not matched. */
// FieldView_BlitPixels @ 0x080B210C
#ifdef NONMATCHING
/* Draws a 4bpp sprite layer into the field view's tile buffer, pixel by pixel, skipping
   transparent (0) pixels of the destination: srcX/srcY/dstX/dstY in pixels, the buffers are
   32-byte tiles in rows of 0x400 bytes. dir = 1 copies left to right, otherwise mirrored. The
   destination x is shifted by the view scroll (unk28) and clipped to columns 8..0xE7. */
void FieldView_BlitPixels(const struct ViewBlit *b)
{
    u32 srcX = b->srcX;
    u32 srcY = b->srcY;
    u32 dstX = b->dstX;
    u32 dstY = b->dstY;
    u32 w = b->w;
    u16 h = b->h;
    u32 dir = b->dir;
    const u8 *src = *b->src;
    u8 *dst = b->dst;
    u32 cut;
    u16 row, col;
    u32 sx, dx, next;
    u8 pix, *p;

    gUnk_030045F4 = 1;
    if (gUnk_03004614 != 0x4A || gUnk_03004514 != 4)
    {
        dstX = (u16)(dstX + gFieldState.unk28);
        if (dir == 1)
        {
            if ((s16)dstX < 8)
            {
                cut = (u16)(8 - dstX);
                dstX = (u16)(dstX + cut);
                srcX = (u16)(srcX + cut);
                w = (u16)(w - cut);
            }
            else if (dstX + w > 0xE8)
            {
                w = (u16)(w - (u16)(dstX + w - 0xE8));
            }
        }
        else
        {
            if ((s16)(dstX - w) < 8)
            {
                w = (u16)(w - (u16)(8 - (dstX - w)));
            }
            else if (dstX > 0xE8)
            {
                cut = (u16)(dstX - 0xE8);
                dstX = (u16)(dstX - cut);
                srcX = (u16)(srcX + cut);
                w = (u16)(w - cut);
            }
        }
    }
    if (w == 0 || (s16)w < 0)
        return;
    for (row = 0; row < h; row++)
    {
        sx = srcX;
        dx = dstX;
        for (col = 0; col < w; col += 2)
        {
            pix = src[(srcY >> 3) * 0x400 + (sx >> 3) * 0x20 + (srcY & 7) * 4 + ((sx & 7) >> 1)];
            if (!(dx & 1))
            {
                p = &dst[(dstY >> 3) * 0x400 + (dx >> 3) * 0x20 + (dstY & 7) * 4 + ((dx & 7) >> 1)];
                if (!(*p & 0xF))
                {
                    *p |= pix & 0xF;
                    gUnk_030045F4 = 1;
                }
                next = (u16)(dx + dir);
                p = &dst[(dstY >> 3) * 0x400 + (next >> 3) * 0x20 + (dstY & 7) * 4 + ((next & 7) >> 1)];
                if (!(*p & 0xF0))
                {
                    *p |= pix & 0xF0;
                    gUnk_030045F4 = 1;
                }
            }
            else
            {
                p = &dst[(dstY >> 3) * 0x400 + (dx >> 3) * 0x20 + (dstY & 7) * 4 + ((dx & 7) >> 1)];
                if (!(*p & 0xF0))
                {
                    *p |= pix << 4;
                    gUnk_030045F4 = 1;
                }
                next = (u16)(dx + dir);
                p = &dst[(dstY >> 3) * 0x400 + (next >> 3) * 0x20 + (dstY & 7) * 4 + ((next & 7) >> 1)];
                if (!(*p & 0xF))
                {
                    *p |= pix >> 4;
                    gUnk_030045F4 = 1;
                }
            }
            sx = (u16)(sx + 2);
            dx = (u16)(next + dir);
        }
        srcY = (u16)(srcY + 1);
        dstY = (u16)(dstY + 1);
    }
    gFieldState.unk2C = 0;
}
#else
NAKED
void FieldView_BlitPixels(const struct ViewBlit *b)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x34\n"
        "    ldrh r1, [r0, #8]\n"
        "    str r1, [sp]\n"
        "    ldrh r2, [r0, #0xa]\n"
        "    str r2, [sp, #4]\n"
        "    ldrh r3, [r0, #0xc]\n"
        "    str r3, [sp, #8]\n"
        "    ldrh r5, [r0, #0xe]\n"
        "    str r5, [sp, #0xc]\n"
        "    ldrh r1, [r0, #0x10]\n"
        "    mov sl, r1\n"
        "    ldrh r2, [r0, #0x12]\n"
        "    str r2, [sp, #0x10]\n"
        "    ldrh r3, [r0, #0x14]\n"
        "    str r3, [sp, #0x14]\n"
        "    ldr r1, [r0]\n"
        "    ldr r1, [r1]\n"
        "    str r1, [sp, #0x18]\n"
        "    ldr r0, [r0, #4]\n"
        "    str r0, [sp, #0x1c]\n"
        "    ldr r1, .L080B2194\n"
        "    movs r0, #1\n"
        "    str r0, [r1]\n"
        "    ldr r0, .L080B2198\n"
        "    ldr r0, [r0]\n"
        "    cmp r0, #0x4a\n"
        "    bne .L080B2154\n"
        "    ldr r0, .L080B219C\n"
        "    ldr r0, [r0]\n"
        "    cmp r0, #4\n"
        "    beq .L080B21FC\n"
        ".L080B2154:\n"
        "    ldr r0, .L080B21A0\n"
        "    ldrh r0, [r0, #0x28]\n"
        "    ldr r5, [sp, #8]\n"
        "    adds r0, r5, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #8]\n"
        "    ldr r0, [sp, #0x14]\n"
        "    cmp r0, #1\n"
        "    bne .L080B21B8\n"
        "    ldr r1, [sp, #8]\n"
        "    lsls r0, r1, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #7\n"
        "    bgt .L080B21A4\n"
        "    movs r0, #8\n"
        "    subs r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    adds r1, r1, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    ldr r2, [sp]\n"
        "    adds r1, r2, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp]\n"
        "    mov r3, sl\n"
        "    subs r0, r3, r0\n"
        "    b .L080B21F6\n"
        "    .byte 0x00, 0x00\n"
        ".L080B2194: .4byte 0x030045F4 @ IWRAM+0x45F4\n"
        ".L080B2198: .4byte 0x03004614 @ IWRAM+0x4614\n"
        ".L080B219C: .4byte 0x03004514 @ IWRAM+0x4514\n"
        ".L080B21A0: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B21A4:\n"
        "    ldr r0, [sp, #8]\n"
        "    add r0, sl\n"
        "    cmp r0, #0xe8\n"
        "    ble .L080B21FC\n"
        "    subs r0, #0xe8\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r5, sl\n"
        "    subs r0, r5, r0\n"
        "    b .L080B21F6\n"
        ".L080B21B8:\n"
        "    ldr r0, [sp, #8]\n"
        "    mov r2, sl\n"
        "    subs r1, r0, r2\n"
        "    lsls r0, r1, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #7\n"
        "    bgt .L080B21D2\n"
        "    movs r0, #8\n"
        "    subs r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    subs r0, r2, r0\n"
        "    b .L080B21F6\n"
        ".L080B21D2:\n"
        "    ldr r3, [sp, #8]\n"
        "    cmp r3, #0xe8\n"
        "    bls .L080B21FC\n"
        "    adds r0, r3, #0\n"
        "    subs r0, #0xe8\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    subs r1, r3, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    ldr r5, [sp]\n"
        "    adds r1, r5, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp]\n"
        "    mov r1, sl\n"
        "    subs r0, r1, r0\n"
        ".L080B21F6:\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sl, r0\n"
        ".L080B21FC:\n"
        "    mov r2, sl\n"
        "    lsls r0, r2, #0x10\n"
        "    cmp r0, #0\n"
        "    bgt .L080B2206\n"
        "    b .L080B23B8\n"
        ".L080B2206:\n"
        "    movs r0, #0\n"
        "    ldr r3, [sp, #0x10]\n"
        "    cmp r0, r3\n"
        "    blo .L080B2210\n"
        "    b .L080B23B2\n"
        ".L080B2210:\n"
        "    ldr r7, [sp]\n"
        "    ldr r4, [sp, #8]\n"
        "    movs r5, #0\n"
        "    mov sb, r5\n"
        "    ldr r1, [sp, #4]\n"
        "    adds r1, #1\n"
        "    str r1, [sp, #0x28]\n"
        "    ldr r2, [sp, #0xc]\n"
        "    adds r2, #1\n"
        "    str r2, [sp, #0x2c]\n"
        "    adds r0, #1\n"
        "    str r0, [sp, #0x30]\n"
        "    cmp sb, sl\n"
        "    blo .L080B222E\n"
        "    b .L080B2394\n"
        ".L080B222E:\n"
        "    ldr r3, [sp, #4]\n"
        "    lsrs r0, r3, #3\n"
        "    lsls r0, r0, #0xa\n"
        "    ldr r5, [sp, #0x18]\n"
        "    adds r0, r5, r0\n"
        "    str r0, [sp, #0x20]\n"
        "    ldr r1, [sp, #0xc]\n"
        "    lsrs r0, r1, #3\n"
        "    lsls r0, r0, #0xa\n"
        "    str r0, [sp, #0x24]\n"
        ".L080B2242:\n"
        "    adds r0, r4, #0\n"
        "    movs r2, #1\n"
        "    ands r0, r2\n"
        "    cmp r0, #0\n"
        "    bne .L080B22D8\n"
        "    lsls r1, r7, #0xd\n"
        "    lsrs r1, r1, #0x10\n"
        "    lsls r1, r1, #5\n"
        "    movs r3, #7\n"
        "    mov r8, r3\n"
        "    ldr r2, [sp, #4]\n"
        "    ands r2, r3\n"
        "    lsls r2, r2, #2\n"
        "    adds r0, r7, #0\n"
        "    ands r0, r3\n"
        "    lsrs r0, r0, #1\n"
        "    ldr r5, [sp, #0x20]\n"
        "    adds r1, r5, r1\n"
        "    adds r1, r1, r2\n"
        "    adds r1, r1, r0\n"
        "    ldrb r6, [r1]\n"
        "    ldr r0, [sp, #0x1c]\n"
        "    ldr r1, [sp, #0x24]\n"
        "    adds r0, r0, r1\n"
        "    mov ip, r0\n"
        "    lsls r1, r4, #0xd\n"
        "    lsrs r1, r1, #0x10\n"
        "    lsls r1, r1, #5\n"
        "    add r1, ip\n"
        "    ldr r0, [sp, #0xc]\n"
        "    ands r0, r3\n"
        "    lsls r5, r0, #2\n"
        "    adds r1, r1, r5\n"
        "    adds r0, r4, #0\n"
        "    ands r0, r3\n"
        "    lsrs r0, r0, #1\n"
        "    adds r1, r1, r0\n"
        "    ldrb r2, [r1]\n"
        "    movs r3, #0xf\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r3\n"
        "    cmp r0, #0\n"
        "    bne .L080B22A4\n"
        "    adds r0, r6, #0\n"
        "    ands r0, r3\n"
        "    orrs r2, r0\n"
        "    movs r3, #1\n"
        "    ldr r0, .L080B22D4\n"
        "    str r3, [r0]\n"
        ".L080B22A4:\n"
        "    strb r2, [r1]\n"
        "    ldr r1, [sp, #0x14]\n"
        "    adds r0, r4, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    lsrs r0, r0, #0x13\n"
        "    lsls r0, r0, #5\n"
        "    add r0, ip\n"
        "    adds r0, r0, r5\n"
        "    adds r1, r4, #0\n"
        "    mov r2, r8\n"
        "    ands r1, r2\n"
        "    lsrs r1, r1, #1\n"
        "    adds r1, r0, r1\n"
        "    ldrb r2, [r1]\n"
        "    movs r3, #0xf0\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r3\n"
        "    cmp r0, #0\n"
        "    bne .L080B2364\n"
        "    ands r6, r3\n"
        "    orrs r2, r6\n"
        "    b .L080B235E\n"
        "    .byte 0x00, 0x00\n"
        ".L080B22D4: .4byte 0x030045F4 @ IWRAM+0x45F4\n"
        ".L080B22D8:\n"
        "    lsls r1, r7, #0xd\n"
        "    lsrs r1, r1, #0x10\n"
        "    lsls r1, r1, #5\n"
        "    movs r0, #7\n"
        "    mov r8, r0\n"
        "    ldr r2, [sp, #4]\n"
        "    ands r2, r0\n"
        "    lsls r2, r2, #2\n"
        "    adds r0, r7, #0\n"
        "    mov r3, r8\n"
        "    ands r0, r3\n"
        "    lsrs r0, r0, #1\n"
        "    ldr r5, [sp, #0x20]\n"
        "    adds r1, r5, r1\n"
        "    adds r1, r1, r2\n"
        "    adds r1, r1, r0\n"
        "    ldrb r6, [r1]\n"
        "    ldr r0, [sp, #0x1c]\n"
        "    ldr r1, [sp, #0x24]\n"
        "    adds r0, r0, r1\n"
        "    mov ip, r0\n"
        "    lsls r1, r4, #0xd\n"
        "    lsrs r1, r1, #0x10\n"
        "    lsls r1, r1, #5\n"
        "    add r1, ip\n"
        "    ldr r0, [sp, #0xc]\n"
        "    ands r0, r3\n"
        "    lsls r3, r0, #2\n"
        "    adds r1, r1, r3\n"
        "    adds r0, r4, #0\n"
        "    mov r2, r8\n"
        "    ands r0, r2\n"
        "    lsrs r0, r0, #1\n"
        "    adds r1, r1, r0\n"
        "    ldrb r2, [r1]\n"
        "    movs r0, #0xf0\n"
        "    ands r0, r2\n"
        "    cmp r0, #0\n"
        "    bne .L080B2334\n"
        "    movs r0, #0xf\n"
        "    ands r0, r6\n"
        "    lsls r0, r0, #4\n"
        "    orrs r2, r0\n"
        "    movs r5, #1\n"
        "    ldr r0, .L080B23C8\n"
        "    str r5, [r0]\n"
        ".L080B2334:\n"
        "    strb r2, [r1]\n"
        "    ldr r1, [sp, #0x14]\n"
        "    adds r0, r4, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    lsrs r0, r0, #0x13\n"
        "    lsls r0, r0, #5\n"
        "    add r0, ip\n"
        "    adds r0, r0, r3\n"
        "    adds r1, r4, #0\n"
        "    mov r2, r8\n"
        "    ands r1, r2\n"
        "    lsrs r1, r1, #1\n"
        "    adds r1, r0, r1\n"
        "    ldrb r2, [r1]\n"
        "    movs r0, #0xf\n"
        "    ands r0, r2\n"
        "    cmp r0, #0\n"
        "    bne .L080B2364\n"
        "    lsrs r0, r6, #4\n"
        "    orrs r2, r0\n"
        ".L080B235E:\n"
        "    movs r3, #1\n"
        "    ldr r5, .L080B23C8\n"
        "    str r3, [r5]\n"
        ".L080B2364:\n"
        "    strb r2, [r1]\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    mov r0, sb\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sb, r0\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    ldr r1, [sp, #0x14]\n"
        "    adds r0, r4, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    mov r0, sb\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sb, r0\n"
        "    cmp sb, sl\n"
        "    bhs .L080B2394\n"
        "    b .L080B2242\n"
        ".L080B2394:\n"
        "    ldr r2, [sp, #0x28]\n"
        "    lsls r0, r2, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #4]\n"
        "    ldr r3, [sp, #0x2c]\n"
        "    lsls r0, r3, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0xc]\n"
        "    ldr r5, [sp, #0x30]\n"
        "    lsls r0, r5, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    ldr r1, [sp, #0x10]\n"
        "    cmp r0, r1\n"
        "    bhs .L080B23B2\n"
        "    b .L080B2210\n"
        ".L080B23B2:\n"
        "    movs r0, #0\n"
        "    ldr r2, .L080B23CC\n"
        "    strh r0, [r2, #0x2c]\n"
        ".L080B23B8:\n"
        "    add sp, #0x34\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080B23C8: .4byte 0x030045F4 @ IWRAM+0x45F4\n"
        ".L080B23CC: .4byte 0x03004550 @ IWRAM+0x4550\n"
    );
}

#endif


/* NONMATCHING: readable C only (1136 bytes, unrolled tile copies); not matched. */
// FieldView_BlitTiles @ 0x080B23D0
#ifdef NONMATCHING
/* Copies whole 8x8 tiles of a view layer into the tile buffer (dir = 1), or mirrored
   (each 4bpp row reversed nibble by nibble), with the same x clipping as FieldView_BlitPixels.
   unk2C counts the frames since the last change (0 -> 1 -> 2 -> 3 -> 0). */
void FieldView_BlitTiles(const struct ViewBlit *b)
{
    u16 w = b->w;
    u32 cols = w >> 3;
    u32 rows = b->h >> 3;
    u16 dstX = gFieldState.unk28 + b->dstX;
    u32 x = dstX;
    u32 srcOff = ((b->srcX >> 3) & 0x7FF) * 0x20;
    u32 dstOff = ((dstX >> 3) & 0x7FF) * 0x20;
    const u8 *src = *b->src;
    u8 *dst = b->dst;
    s32 cut;
    u32 r, c, v;
    const u32 *s;
    u32 *d;

    if (w & 7)
        cols++;
    if (b->h & 7)
        rows++;
    if ((s16)b->dir == 1)
    {
        if ((s16)dstX < 8)
        {
            cut = (s16)(8 - x) / 8;
            dstOff = (u16)(dstOff + cut * 0x20);
            srcOff = (u16)(srcOff + cut * 0x20);
            cols -= cut;
        }
        else
        {
            x += w;
            if (x < 0xE9)
                goto draw;
            cols -= (s16)(x - 0xE8) / 8;
        }
    }
    else
    {
        cut = x - w;
        if ((s16)cut < 8)
        {
            cols -= (s16)(8 - cut) / 8;
        }
        else
        {
            if (x < 0xE9)
                goto draw;
            cut = (s16)(x - 0xE8) / 8;
            dstOff = (u16)(dstOff - cut * 0x20);
            srcOff = (u16)(srcOff + cut * 0x20);
            cols -= cut;
        }
    }
    cols = (u16)cols;
draw:
    if ((s16)cols <= 0)
        return;
    for (r = 0; r < rows; r++)
    {
        s = (const u32 *)(src + ((b->srcY + r * 8) >> 3) * 0x400 + srcOff);
        d = (u32 *)(dst + ((b->dstY + r * 8) >> 3) * 0x400 + dstOff);
        for (c = 0; c < cols; c++)
        {
            if ((s16)b->dir == 1)
            {
                d[0] = s[0];
                d[1] = s[1];
                d[2] = s[2];
                d[3] = s[3];
                d[4] = s[4];
                d[5] = s[5];
                d[6] = s[6];
                d[7] = s[7];
                d += 8;
            }
            else
            {
                u32 i;

                for (i = 0; i < 8; i++)
                {
                    v = s[i];
                    d[i] = v << 28 | (v & 0xF0) << 20 | (v & 0xF00) << 12 | (v & 0xF000) << 4
                         | (v >> 4 & 0xF000) | (v >> 12 & 0xF00) | (v >> 20 & 0xF0) | v >> 28;
                }
                d -= 8;
            }
            s += 8;
        }
    }
    if (gFieldState.unk2C == 0)
        gFieldState.unk2C = 1;
    else if (gFieldState.unk2C < 3)
        gFieldState.unk2C++;
    else
        gFieldState.unk2C = 0;
}
#else
NAKED
void FieldView_BlitTiles(const struct ViewBlit *b)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x24\n"
        "    str r0, [sp]\n"
        "    ldrh r5, [r0, #0x10]\n"
        "    lsrs r0, r5, #3\n"
        "    str r0, [sp, #4]\n"
        "    ldr r1, [sp]\n"
        "    ldrh r3, [r1, #0x12]\n"
        "    lsrs r2, r3, #3\n"
        "    str r2, [sp, #8]\n"
        "    ldr r2, .L080B247C\n"
        "    ldrh r1, [r2, #0x28]\n"
        "    ldr r4, [sp]\n"
        "    ldrh r4, [r4, #0xc]\n"
        "    adds r1, r1, r4\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r4, r1, #0x10\n"
        "    adds r6, r4, #0\n"
        "    ldr r7, [sp]\n"
        "    ldrh r0, [r7, #8]\n"
        "    lsrs r0, r0, #3\n"
        "    lsls r0, r0, #0x15\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0x10]\n"
        "    lsrs r1, r1, #0x13\n"
        "    lsls r1, r1, #0x15\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #0x14]\n"
        "    ldr r0, [r7]\n"
        "    ldr r0, [r0]\n"
        "    str r0, [sp, #0x18]\n"
        "    ldr r0, [r7, #4]\n"
        "    str r0, [sp, #0x1c]\n"
        "    movs r1, #7\n"
        "    adds r0, r5, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080B242A\n"
        "    ldr r2, [sp, #4]\n"
        "    adds r2, #1\n"
        "    str r2, [sp, #4]\n"
        ".L080B242A:\n"
        "    ands r3, r1\n"
        "    cmp r3, #0\n"
        "    beq .L080B243A\n"
        "    ldr r0, [sp, #8]\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #8]\n"
        ".L080B243A:\n"
        "    ldr r3, [sp]\n"
        "    ldrh r0, [r3, #0x14]\n"
        "    adds r7, r0, #0\n"
        "    cmp r7, #1\n"
        "    bne .L080B249A\n"
        "    lsls r0, r4, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #7\n"
        "    bgt .L080B2480\n"
        "    movs r0, #8\n"
        "    subs r0, r0, r4\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r1, r0, #0x10\n"
        "    adds r0, r1, #0\n"
        "    cmp r1, #0\n"
        "    bge .L080B245C\n"
        "    adds r0, r1, #7\n"
        ".L080B245C:\n"
        "    asrs r3, r0, #3\n"
        "    lsls r2, r3, #5\n"
        "    ldr r4, [sp, #0x14]\n"
        "    adds r0, r4, r2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0x14]\n"
        "    ldr r4, [sp, #0x10]\n"
        "    adds r0, r4, r2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0x10]\n"
        "    ldr r1, [sp, #4]\n"
        "    subs r0, r1, r3\n"
        "    b .L080B24EA\n"
        "    .byte 0x00, 0x00\n"
        ".L080B247C: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B2480:\n"
        "    adds r0, r4, r5\n"
        "    cmp r0, #0xe8\n"
        "    ble .L080B24F0\n"
        "    subs r0, #0xe8\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L080B2492\n"
        "    adds r0, #7\n"
        ".L080B2492:\n"
        "    asrs r0, r0, #3\n"
        "    ldr r2, [sp, #4]\n"
        "    subs r0, r2, r0\n"
        "    b .L080B24EA\n"
        ".L080B249A:\n"
        "    subs r1, r4, r5\n"
        "    lsls r0, r1, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #7\n"
        "    bgt .L080B24BA\n"
        "    movs r0, #8\n"
        "    subs r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L080B24B2\n"
        "    adds r0, #7\n"
        ".L080B24B2:\n"
        "    asrs r0, r0, #3\n"
        "    ldr r3, [sp, #4]\n"
        "    subs r0, r3, r0\n"
        "    b .L080B24EA\n"
        ".L080B24BA:\n"
        "    cmp r6, #0xe8\n"
        "    bls .L080B24F0\n"
        "    adds r0, r6, #0\n"
        "    subs r0, #0xe8\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r2, r0, #0x10\n"
        "    adds r0, r2, #0\n"
        "    cmp r2, #0\n"
        "    bge .L080B24CE\n"
        "    adds r0, r2, #7\n"
        ".L080B24CE:\n"
        "    asrs r1, r0, #3\n"
        "    lsls r3, r1, #5\n"
        "    ldr r4, [sp, #0x14]\n"
        "    subs r0, r4, r3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0x14]\n"
        "    ldr r4, [sp, #0x10]\n"
        "    adds r0, r4, r3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0x10]\n"
        "    ldr r2, [sp, #4]\n"
        "    subs r0, r2, r1\n"
        ".L080B24EA:\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #4]\n"
        ".L080B24F0:\n"
        "    ldr r3, [sp, #4]\n"
        "    lsls r0, r3, #0x10\n"
        "    cmp r0, #0\n"
        "    bgt .L080B24FA\n"
        "    b .L080B282C\n"
        ".L080B24FA:\n"
        "    cmp r7, #1\n"
        "    bne .L080B2578\n"
        "    movs r4, #0\n"
        "    ldr r7, [sp, #8]\n"
        "    cmp r4, r7\n"
        "    blo .L080B2508\n"
        "    b .L080B2806\n"
        ".L080B2508:\n"
        "    ldr r1, [sp]\n"
        "    ldrh r0, [r1, #0xa]\n"
        "    lsls r2, r4, #3\n"
        "    adds r0, r0, r2\n"
        "    asrs r0, r0, #3\n"
        "    lsls r0, r0, #0xa\n"
        "    ldr r3, [sp, #0x18]\n"
        "    adds r0, r3, r0\n"
        "    ldrh r1, [r1, #0xe]\n"
        "    adds r1, r1, r2\n"
        "    asrs r1, r1, #3\n"
        "    lsls r1, r1, #0xa\n"
        "    ldr r7, [sp, #0x1c]\n"
        "    adds r1, r7, r1\n"
        "    ldr r2, [sp, #0x10]\n"
        "    adds r3, r0, r2\n"
        "    ldr r7, [sp, #0x14]\n"
        "    adds r1, r1, r7\n"
        "    movs r0, #0\n"
        "    str r0, [sp, #0xc]\n"
        "    adds r4, #1\n"
        "    str r4, [sp, #0x20]\n"
        "    ldr r2, [sp, #4]\n"
        "    cmp r0, r2\n"
        "    bhs .L080B256A\n"
        ".L080B253A:\n"
        "    ldm r3!, {r0}\n"
        "    stm r1!, {r0}\n"
        "    ldm r3!, {r0}\n"
        "    stm r1!, {r0}\n"
        "    ldm r3!, {r0}\n"
        "    stm r1!, {r0}\n"
        "    ldm r3!, {r0}\n"
        "    stm r1!, {r0}\n"
        "    ldm r3!, {r0}\n"
        "    stm r1!, {r0}\n"
        "    ldm r3!, {r0}\n"
        "    stm r1!, {r0}\n"
        "    ldm r3!, {r0}\n"
        "    stm r1!, {r0}\n"
        "    ldm r3!, {r0}\n"
        "    stm r1!, {r0}\n"
        "    ldr r0, [sp, #0xc]\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0xc]\n"
        "    ldr r4, [sp, #4]\n"
        "    cmp r0, r4\n"
        "    blo .L080B253A\n"
        ".L080B256A:\n"
        "    ldr r7, [sp, #0x20]\n"
        "    lsls r0, r7, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    ldr r0, [sp, #8]\n"
        "    cmp r4, r0\n"
        "    blo .L080B2508\n"
        "    b .L080B2806\n"
        ".L080B2578:\n"
        "    movs r4, #0\n"
        "    ldr r1, [sp, #8]\n"
        "    cmp r4, r1\n"
        "    blo .L080B2582\n"
        "    b .L080B2806\n"
        ".L080B2582:\n"
        "    ldr r2, [sp]\n"
        "    ldrh r0, [r2, #0xa]\n"
        "    lsls r2, r4, #3\n"
        "    adds r0, r0, r2\n"
        "    asrs r0, r0, #3\n"
        "    lsls r0, r0, #0xa\n"
        "    ldr r3, [sp, #0x18]\n"
        "    adds r0, r3, r0\n"
        "    ldr r7, [sp]\n"
        "    ldrh r1, [r7, #0xe]\n"
        "    adds r1, r1, r2\n"
        "    asrs r1, r1, #3\n"
        "    lsls r1, r1, #0xa\n"
        "    ldr r2, [sp, #0x1c]\n"
        "    adds r1, r2, r1\n"
        "    ldr r3, [sp, #0x10]\n"
        "    adds r5, r0, r3\n"
        "    ldr r7, [sp, #0x14]\n"
        "    adds r2, r1, r7\n"
        "    movs r0, #0\n"
        "    str r0, [sp, #0xc]\n"
        "    adds r4, #1\n"
        "    str r4, [sp, #0x20]\n"
        "    ldr r1, [sp, #4]\n"
        "    cmp r0, r1\n"
        "    blo .L080B25B8\n"
        "    b .L080B27F8\n"
        ".L080B25B8:\n"
        "    movs r3, #0xf0\n"
        "    lsls r3, r3, #0x14\n"
        "    mov sl, r3\n"
        "    movs r4, #0xf0\n"
        "    lsls r4, r4, #0x10\n"
        "    mov sb, r4\n"
        "    movs r7, #0xf0\n"
        "    lsls r7, r7, #0xc\n"
        "    mov r8, r7\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #8\n"
        "    mov ip, r0\n"
        "    movs r6, #0xf0\n"
        "    movs r4, #0xf\n"
        ".L080B25D4:\n"
        "    ldm r5!, {r3}\n"
        "    lsls r1, r3, #0x1c\n"
        "    movs r7, #0xf0\n"
        "    lsls r7, r7, #0x18\n"
        "    ands r1, r7\n"
        "    lsls r0, r3, #0x14\n"
        "    mov r7, sl\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #0xc\n"
        "    mov r7, sb\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #4\n"
        "    mov r7, r8\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #4\n"
        "    mov r7, ip\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0xc\n"
        "    movs r7, #0xf0\n"
        "    lsls r7, r7, #4\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x14\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x1c\n"
        "    ands r0, r4\n"
        "    orrs r1, r0\n"
        "    stm r2!, {r1}\n"
        "    ldm r5!, {r3}\n"
        "    lsls r1, r3, #0x1c\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0x18\n"
        "    ands r1, r0\n"
        "    lsls r0, r3, #0x14\n"
        "    mov r7, sl\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #0xc\n"
        "    mov r7, sb\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #4\n"
        "    mov r7, r8\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #4\n"
        "    mov r7, ip\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0xc\n"
        "    movs r7, #0xf0\n"
        "    lsls r7, r7, #4\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x14\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x1c\n"
        "    ands r0, r4\n"
        "    orrs r1, r0\n"
        "    stm r2!, {r1}\n"
        "    ldm r5!, {r3}\n"
        "    lsls r1, r3, #0x1c\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0x18\n"
        "    ands r1, r0\n"
        "    lsls r0, r3, #0x14\n"
        "    mov r7, sl\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #0xc\n"
        "    mov r7, sb\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #4\n"
        "    mov r7, r8\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #4\n"
        "    mov r7, ip\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0xc\n"
        "    movs r7, #0xf0\n"
        "    lsls r7, r7, #4\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x14\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x1c\n"
        "    ands r0, r4\n"
        "    orrs r1, r0\n"
        "    stm r2!, {r1}\n"
        "    ldm r5!, {r3}\n"
        "    lsls r1, r3, #0x1c\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0x18\n"
        "    ands r1, r0\n"
        "    lsls r0, r3, #0x14\n"
        "    mov r7, sl\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #0xc\n"
        "    mov r7, sb\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #4\n"
        "    mov r7, r8\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #4\n"
        "    mov r7, ip\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0xc\n"
        "    movs r7, #0xf0\n"
        "    lsls r7, r7, #4\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x14\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x1c\n"
        "    ands r0, r4\n"
        "    orrs r1, r0\n"
        "    stm r2!, {r1}\n"
        "    ldm r5!, {r3}\n"
        "    lsls r1, r3, #0x1c\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0x18\n"
        "    ands r1, r0\n"
        "    lsls r0, r3, #0x14\n"
        "    mov r7, sl\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #0xc\n"
        "    mov r7, sb\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #4\n"
        "    mov r7, r8\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #4\n"
        "    mov r7, ip\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0xc\n"
        "    movs r7, #0xf0\n"
        "    lsls r7, r7, #4\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x14\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x1c\n"
        "    ands r0, r4\n"
        "    orrs r1, r0\n"
        "    stm r2!, {r1}\n"
        "    ldm r5!, {r3}\n"
        "    lsls r1, r3, #0x1c\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0x18\n"
        "    ands r1, r0\n"
        "    lsls r0, r3, #0x14\n"
        "    mov r7, sl\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #0xc\n"
        "    mov r7, sb\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #4\n"
        "    mov r7, r8\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #4\n"
        "    mov r7, ip\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0xc\n"
        "    movs r7, #0xf0\n"
        "    lsls r7, r7, #4\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x14\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x1c\n"
        "    ands r0, r4\n"
        "    orrs r1, r0\n"
        "    stm r2!, {r1}\n"
        "    ldm r5!, {r3}\n"
        "    lsls r1, r3, #0x1c\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0x18\n"
        "    ands r1, r0\n"
        "    lsls r0, r3, #0x14\n"
        "    mov r7, sl\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #0xc\n"
        "    mov r7, sb\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #4\n"
        "    mov r7, r8\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #4\n"
        "    mov r7, ip\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0xc\n"
        "    movs r7, #0xf0\n"
        "    lsls r7, r7, #4\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x14\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x1c\n"
        "    ands r0, r4\n"
        "    orrs r1, r0\n"
        "    stm r2!, {r1}\n"
        "    ldm r5!, {r3}\n"
        "    lsls r1, r3, #0x1c\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0x18\n"
        "    ands r1, r0\n"
        "    lsls r0, r3, #0x14\n"
        "    mov r7, sl\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #0xc\n"
        "    mov r7, sb\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsls r0, r3, #4\n"
        "    mov r7, r8\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #4\n"
        "    mov r7, ip\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0xc\n"
        "    movs r7, #0xf0\n"
        "    lsls r7, r7, #4\n"
        "    ands r0, r7\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x14\n"
        "    ands r0, r6\n"
        "    orrs r1, r0\n"
        "    lsrs r0, r3, #0x1c\n"
        "    ands r0, r4\n"
        "    orrs r1, r0\n"
        "    stm r2!, {r1}\n"
        "    subs r2, #0x40\n"
        "    ldr r0, [sp, #0xc]\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0xc]\n"
        "    ldr r1, [sp, #4]\n"
        "    cmp r0, r1\n"
        "    bhs .L080B27F8\n"
        "    b .L080B25D4\n"
        ".L080B27F8:\n"
        "    ldr r2, [sp, #0x20]\n"
        "    lsls r0, r2, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    ldr r3, [sp, #8]\n"
        "    cmp r4, r3\n"
        "    bhs .L080B2806\n"
        "    b .L080B2582\n"
        ".L080B2806:\n"
        "    ldr r2, .L080B2818\n"
        "    ldrh r0, [r2, #0x2c]\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #0\n"
        "    bne .L080B281C\n"
        "    adds r0, #1\n"
        "    strh r0, [r2, #0x2c]\n"
        "    b .L080B282C\n"
        "    .byte 0x00, 0x00\n"
        ".L080B2818: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B281C:\n"
        "    cmp r1, #2\n"
        "    bls .L080B2826\n"
        "    movs r0, #0\n"
        "    strh r0, [r2, #0x2c]\n"
        "    b .L080B282C\n"
        ".L080B2826:\n"
        "    adds r0, #1\n"
        "    ldr r4, .L080B283C\n"
        "    strh r0, [r4, #0x2c]\n"
        ".L080B282C:\n"
        "    add sp, #0x24\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080B283C: .4byte 0x03004550 @ IWRAM+0x4550\n"
    );
}

#endif
