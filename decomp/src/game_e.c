/* Field view frame update. */

#include "global.h"
#include "game.h"

// sub_080B2AB0 @ 0x080B2AB0
void sub_080B2AB0(void)
{
    u16 side = 0;
    u16 xo = 0;
    u32 kind;

    if (Field_GetState() == 5 && gFieldState.unk24 == 1 && gFieldState.unk0C == 0)
        side = 0xFFFF;
    if (sub_080B2980(0, side) != 1)
        return;
    if (gFieldState.unk2E < 0x22 && gUnk_0300461C != 0)
        Sprite_Draw(gUnknown_08002CAC, 1, 13, 0, 0x280, 0x58, 0x18);
    if (gFieldState.unk2E > 0x20)
        return;
    kind = sub_080B2938();
    if (gFieldState.unk2E != 0)
        sub_080B29A8(kind);
    if (gUnk_0300461C == 0)
        return;
    if (kind == 0)
    {
        Sprite_Draw(gUnknown_08002C88, 1, 13, 0, 0x280, xo + (0x58 - gFieldState.unk2E), 0x18);
        Sprite_Draw(gUnknown_08002C70, 1, 13, 0, 0x280, gFieldState.unk2E + 0x78, 0x18);
    }
    else if (kind == 1)
    {
        Sprite_Draw(gUnknown_08002C88, 1, 13, 0, 0x280, 0x58, 0x18 - gFieldState.unk2E * 2);
        Sprite_Draw(gUnknown_08002C70, 1, 13, 0, 0x280, 0x78, 0x18 - gFieldState.unk2E * 2);
    }
    else if (kind == 2)
    {
        Sprite_Draw(gUnknown_08002D78, 1, 13, 0, 0x300, xo - gFieldState.unk2E + 0x78, 0x18);
        Sprite_Draw(gUnknown_08002DAC, 1, 13, 0, 0x300, xo + (gFieldState.unk2E + 0x78) - 8, 0x18);
        Sprite_Draw(gUnknown_08002C88, 1, 13, 0, 0x280, xo + (0x58 - gFieldState.unk2E), 0x18);
        Sprite_Draw(gUnknown_08002C70, 1, 13, 0, 0x280, gFieldState.unk2E + 0x78, 0x18);
    }
    else if (kind == 3)
    {
        Sprite_Draw(gUnknown_08002C88, 1, 13, 0, 0x280, xo + (0x58 - gFieldState.unk2E), 0x18);
        Sprite_Draw(gUnknown_08002C70, 1, 13, 0, 0x280, gFieldState.unk2E + 0x78, 0x18);
        Sprite_Draw(gUnknown_08002DE8, 1, 13, 0, 0x300, 0x3A, 0x18);
        Sprite_Draw(gUnknown_08002E24, 1, 13, 0, 0x300, 0x96, 0x18);
    }
}

/* NONMATCHING: the original does not cross-jump the mode 1 call into the shared tail, and its mode 2/3 tail computes offset+base. */
// sub_080B2CC0 @ 0x080B2CC0
#ifdef NONMATCHING
void sub_080B2CC0(void)
{
    u32 mode = gFieldState.unk24;

    View_BuildCells(gFieldState.unk02, 0);
    if (gFieldState.unk00 == 3)
        sub_080B2AB0();
    if (gFieldState.unk0E == 0)
        return;
    if (sub_080ADF40() == 0)
    {
        if (mode == 0)
        {
            const u8 *p = gUnknown_08160A0C[gFieldState.unk0E];
            sub_080B28F8(p, p);
        }
        else if (mode == 1)
        {
            sub_080B28F8(gUnknown_08160E0C[gFieldState.unk0E], gUnknown_08160A0C[gFieldState.unk0E]);
        }
        else if (mode == 2)
        {
            if (gFieldState.unk08 == -1)
                sub_080B28F8(gUnknown_0816120C[gFieldState.unk0E], gUnknown_08160A0C[gFieldState.unk0E]);
            else
                sub_080B28F8(gUnknown_0816160C[gFieldState.unk0E], gUnknown_08160A0C[gFieldState.unk0E]);
        }
        else if (mode == 3)
        {
            if (gFieldState.unk08 == 1)
                sub_080B28F8(gUnknown_08161E0C[gFieldState.unk0E], gUnknown_08160A0C[gFieldState.unk0E]);
            else
                sub_080B28F8(gUnknown_08161A0C[gFieldState.unk0E], gUnknown_08160A0C[gFieldState.unk0E]);
        }
    }
    else
    {
        while (sub_080BA6B4(mode) != 1)
            ;
    }
}
#else
NAKED
void sub_080B2CC0(void)
{
    asm_unified(
        ".L080B2CC0:\n"
        "    push {r4, r5, lr}\n"
        "    ldr r5, .L080B2CFC\n"
        "    ldr r4, [r5, #0x24]\n"
        "    ldrh r0, [r5, #2]\n"
        "    movs r1, #0\n"
        "    bl View_BuildCells\n"
        "    ldrh r0, [r5]\n"
        "    cmp r0, #3\n"
        "    bne .L080B2CD8\n"
        "    bl sub_080B2AB0\n"
        ".L080B2CD8:\n"
        "    ldrh r0, [r5, #0xe]\n"
        "    cmp r0, #0\n"
        "    beq .L080B2D8C\n"
        "    bl sub_080ADF40\n"
        "    cmp r0, #0\n"
        "    bne .L080B2D80\n"
        "    cmp r4, #0\n"
        "    bne .L080B2D04\n"
        "    ldrh r1, [r5, #0xe]\n"
        "    lsls r1, r1, #5\n"
        "    ldr r0, .L080B2D00\n"
        "    adds r1, r1, r0\n"
        "    adds r0, r1, #0\n"
        "    bl sub_080B28F8\n"
        "    b .L080B2D8C\n"
        "    .byte 0x00, 0x00\n"
        ".L080B2CFC: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B2D00: .4byte gUnknown_08160A0C\n"
        ".L080B2D04:\n"
        "    cmp r4, #1\n"
        "    bne .L080B2D24\n"
        "    ldrh r1, [r5, #0xe]\n"
        "    lsls r1, r1, #5\n"
        "    ldr r0, .L080B2D1C\n"
        "    adds r0, r1, r0\n"
        "    ldr r2, .L080B2D20\n"
        "    adds r1, r1, r2\n"
        "    bl sub_080B28F8\n"
        "    b .L080B2D8C\n"
        "    .byte 0x00, 0x00\n"
        ".L080B2D1C: .4byte gUnknown_08160E0C\n"
        ".L080B2D20: .4byte gUnknown_08160A0C\n"
        ".L080B2D24:\n"
        "    cmp r4, #2\n"
        "    bne .L080B2D4C\n"
        "    movs r0, #8\n"
        "    ldrsh r1, [r5, r0]\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r1, r0\n"
        "    bne .L080B2D40\n"
        "    ldrh r0, [r5, #0xe]\n"
        "    lsls r0, r0, #5\n"
        "    ldr r1, .L080B2D3C\n"
        "    b .L080B2D6A\n"
        ".L080B2D3C: .4byte gUnknown_0816120C\n"
        ".L080B2D40:\n"
        "    ldrh r0, [r5, #0xe]\n"
        "    lsls r0, r0, #5\n"
        "    ldr r1, .L080B2D48\n"
        "    b .L080B2D6A\n"
        ".L080B2D48: .4byte gUnknown_0816160C\n"
        ".L080B2D4C:\n"
        "    cmp r4, #3\n"
        "    bne .L080B2D8C\n"
        "    movs r1, #8\n"
        "    ldrsh r0, [r5, r1]\n"
        "    cmp r0, #1\n"
        "    bne .L080B2D64\n"
        "    ldrh r0, [r5, #0xe]\n"
        "    lsls r0, r0, #5\n"
        "    ldr r1, .L080B2D60\n"
        "    b .L080B2D6A\n"
        ".L080B2D60: .4byte gUnknown_08161E0C\n"
        ".L080B2D64:\n"
        "    ldrh r0, [r5, #0xe]\n"
        "    lsls r0, r0, #5\n"
        "    ldr r1, .L080B2D78\n"
        ".L080B2D6A:\n"
        "    adds r2, r0, r1\n"
        "    ldr r1, .L080B2D7C\n"
        "    adds r1, r0, r1\n"
        "    adds r0, r2, #0\n"
        "    bl sub_080B28F8\n"
        "    b .L080B2D8C\n"
        ".L080B2D78: .4byte gUnknown_08161A0C\n"
        ".L080B2D7C: .4byte gUnknown_08160A0C\n"
        ".L080B2D80:\n"
        "    lsls r4, r4, #0x10\n"
        ".L080B2D82:\n"
        "    lsrs r0, r4, #0x10\n"
        "    bl sub_080BA6B4\n"
        "    cmp r0, #1\n"
        "    bne .L080B2D82\n"
        ".L080B2D8C:\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}

#endif

// FieldView_DrawLayer @ 0x080B2D94
s32 FieldView_DrawLayer(const struct ViewLayer *layer, const struct ViewCond *cond)
{
    const void *src;
    IwramFunc func;
    u16 kind;
    u16 kind2; /* never assigned: the original reads an uninitialised register (r8) here */

    DungeonMap_GetFloor(gUnk_03004614, gUnk_03004514);
    if (layer->data == (const void *)-1)
        return (s32)layer->data;
    if (layer->data == NULL)
        return 0;
    if (cond->b != NULL && *cond->b != 0)
        return 0;
    if (cond->c != NULL && *cond->c != 0)
        return 0;
    if (cond->d != NULL && *cond->d != 0)
        return 0;
    kind = *cond->a;
    if (kind == 0)
        return 0;
    if (gUnk_03003FE8 != 0 && (kind == 3 || kind2 == 3) && layer->mode == 0)
    {
        src = layer->extra;
        func = IwramFunc_3BC1;
        func(src);
    }
    if (kind == 3 || kind2 == 3)
        src = layer->alt;
    else if (kind == 2 || kind2 == 2)
        src = layer->alt;
    else
        src = layer->data;
    if (layer->mode == 0)
    {
        func = IwramFunc_3BC1;
        func(src);
        if (gUnk_030045F4 == 0)
            return 0;
    }
    else if (layer->mode == 1)
    {
        func = IwramFunc_4011;
        func(src);
        if (src == gUnknown_0815FD7C[0])
            func(gUnknown_0815FDD0);
        else if (src == gUnknown_0815FD7C[1])
            func(gUnknown_0815FDEC);
        else if (src == gUnknown_0815FD7C[2])
            func(gUnknown_0815FE08);
    }
    else
    {
        Picture_ScaleStep(src);
    }
    if (gUnk_03003FE8 != 0 && (kind == 3 || kind2 == 3) && layer->mode == 1)
    {
        src = layer->extra;
        func = IwramFunc_4011;
        func(src);
    }
    if (gFieldState.unk2C != 0)
        return 0;
    return 1;
}
