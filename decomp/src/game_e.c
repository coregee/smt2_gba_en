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

// sub_080B2CC0 @ 0x080B2CC0
void sub_080B2CC0(void)
{
    u32 mode = gFieldState.unk24;
    const u8 *p, *t;

    View_BuildCells(gFieldState.unk02, 0);
    if (gFieldState.unk00 == 3)
        sub_080B2AB0();
    if (gFieldState.unk0E == 0)
        return;
    if (sub_080ADF40() == 0)
    {
        if (mode == 0)
        {
            const u8 *q = gUnknown_08160A0C[gFieldState.unk0E];
            sub_080B28F8(q, q);
        }
        else if (mode == 1)
        {
            sub_080B28F8(gUnknown_08160E0C[gFieldState.unk0E], gUnknown_08160A0C[gFieldState.unk0E]);
        }
        else if (mode == 2)
        {
            if (gFieldState.unk08 == -1)
            {
                p = gUnknown_0816120C[gFieldState.unk0E];
                t = gUnknown_08160A0C[0]; /* = gUnknown_08160A0C[unk0E], base loaded first */
                t += gFieldState.unk0E * 32;
                sub_080B28F8(p, t);
            }
            else
            {
                p = gUnknown_0816160C[gFieldState.unk0E];
                t = gUnknown_08160A0C[0]; /* = gUnknown_08160A0C[unk0E], base loaded first */
                t += gFieldState.unk0E * 32;
                sub_080B28F8(p, t);
            }
        }
        else if (mode == 3)
        {
            if (gFieldState.unk08 == 1)
            {
                p = gUnknown_08161E0C[gFieldState.unk0E];
                t = gUnknown_08160A0C[0]; /* = gUnknown_08160A0C[unk0E], base loaded first */
                t += gFieldState.unk0E * 32;
                sub_080B28F8(p, t);
            }
            else
            {
                p = gUnknown_08161A0C[gFieldState.unk0E];
                t = gUnknown_08160A0C[0]; /* = gUnknown_08160A0C[unk0E], base loaded first */
                t += gFieldState.unk0E * 32;
                sub_080B28F8(p, t);
            }
        }
    }
    else
    {
        while (sub_080BA6B4(mode) != 1)
            ;
    }
}

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
