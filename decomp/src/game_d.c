/* Field view: work buffers, window setup. */

#include "global.h"
#include "game.h"

// sub_080B2840 @ 0x080B2840
void sub_080B2840(u32 a, u32 b, u32 c)
{
    gFieldState.unk24 = a;
    gFieldState.unk28 = b;
    gFieldState.unk2A = c;
    DmaFill32(3, 0, (void *)0x02005004, 0x4000);
    gFieldState.unk0E = 1;
    gFieldState.unk2C = 0;
    gFieldState.unk0C = 0;
}

// sub_080B2880 @ 0x080B2880
void sub_080B2880(void)
{
    if (sub_080ADF40() == 0)
    {
        DmaCopy32(3, (void *)0x02005004, (void *)0x06008800, 0x3400);
    }
    else
    {
        DmaFill32(3, 0, (void *)0x06003000, 0x1000);
        DmaFill32(3, 0, (void *)0x06004000, 0x4000);
        DmaCopy32(3, (void *)0x02005004, (void *)0x06008800, 0x3400);
    }
    gFieldState.unk0C = 0;
}

// sub_080B28F8 @ 0x080B28F8
/* Draws layers until FieldView_DrawLayer returns -1 (then resets the layer counter) or 1. */
void sub_080B28F8(const struct ViewLayer *a, const struct ViewCond *b)
{
    struct Unk03004550 *s = &gFieldState;
    s32 r;

    /* The reset store sits in the loop test: its extra in-loop reference gives s the first
       callee-saved register, as in the original. The test is always false. */
    while ((r = FieldView_DrawLayer(a, b)) != -1 || (s->unk0E = 0) != 0)
    {
        if (r == 1)
        {
            s->unk0E++;
            return;
        }
        s->unk0E++;
        a = (const struct ViewLayer *)((const u8 *)a + 0x20);
        b = (const struct ViewCond *)((const u8 *)b + 0x20);
    }
}

// sub_080B2938 @ 0x080B2938
/* View type of the current map variant (0-3, selects the window layout of sub_080B29A8). */
u32 sub_080B2938(void)
{
    struct MapHeader *map = DungeonMap_GetFloor(gUnk_03004614, gUnk_03004514);
    u32 r;

    if (FieldMap_GetElevatorRecord() == 0)
        r = (u32)map->variants[gGameState.unkA38].data[52];
    else
        r = 0;
    return r;
}

// sub_080B2980 @ 0x080B2980
u32 sub_080B2980(u16 x, u16 y)
{
    s32 r = View_GetWall(0, x, y);

    return r == 2 || r == 3;
}

/* NONMATCHING: the original keeps every repeated constant (and 0x3F) in a register, perhaps from an inlined helper; cross-jumping differs. */
// sub_080B29A8 @ 0x080B29A8
/* Window rectangles (WIN0H/WIN1H/WIN0V/WIN1V shadows) and WININ/WINOUT for the field view. */
void sub_080B29A8(u16 mode)
{
    if (mode == 0 || mode == 2)
    {
        u8 v;

        gUnk_03000030 = 0x5A;
        gUnk_03000031 = 0x38;
        gUnk_03000034 = 0x58;
        gUnk_03000035 = 0x18;
        gUnk_03000038 = (v = 0x3F) & ~0x10;
        gUnk_03000032 = 0xB8;
        gUnk_03000033 = 0x96;
        gUnk_03000036 = 0x58;
        gUnk_03000037 = 0x18;
        gUnk_03000039 = 0x2F;
        gUnk_0300003A = v;
    }
    else if (mode == 1)
    {
        u8 v;

        gUnk_03000030 = 0x98;
        gUnk_03000031 = 0x58;
        gUnk_03000034 = 0x18;
        gUnk_03000035 = 0;
        gUnk_03000038 = (v = 0x3F) & ~0x10;
        gUnk_03000032 = 0x98;
        gUnk_03000033 = 0x58;
        gUnk_03000036 = 0x18;
        gUnk_03000037 = 0;
        gUnk_03000039 = 0x2F;
        gUnk_0300003A = v;
    }
    else if (mode == 3)
    {
        gUnk_03000038 = 0x3F;
        gUnk_03000039 = 0x3F;
        gUnk_0300003A = 0x3F;
    }
}
