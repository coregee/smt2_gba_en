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

/* NONMATCHING: s, a and b get r6/r5/r4 instead of r4/r6/r5. */
// sub_080B28F8 @ 0x080B28F8
#ifdef NONMATCHING
void sub_080B28F8(const struct ViewLayer *a, const struct ViewCond *b)
{
    struct Unk03004550 *s = &gFieldState;
    s32 r;

    while ((r = FieldView_DrawLayer(a, b)) != -1)
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
    s->unk0E = 0;
}
#else
NAKED
void sub_080B28F8(const struct ViewLayer *a, const struct ViewCond *b)
{
    asm_unified(
        ".L080B28F8:\n"
        "    push {r4, r5, r6, lr}\n"
        "    adds r6, r0, #0\n"
        "    adds r5, r1, #0\n"
        "    ldr r4, .L080B2904\n"
        "    b .L080B291C\n"
        "    .byte 0x00, 0x00\n"
        ".L080B2904: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B2908:\n"
        "    cmp r1, #1\n"
        "    bne .L080B2912\n"
        "    ldrh r0, [r4, #0xe]\n"
        "    adds r0, #1\n"
        "    b .L080B2930\n"
        ".L080B2912:\n"
        "    ldrh r0, [r4, #0xe]\n"
        "    adds r0, #1\n"
        "    strh r0, [r4, #0xe]\n"
        "    adds r6, #0x20\n"
        "    adds r5, #0x20\n"
        ".L080B291C:\n"
        "    adds r0, r6, #0\n"
        "    adds r1, r5, #0\n"
        "    bl FieldView_DrawLayer\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r1, r0\n"
        "    bne .L080B2908\n"
        "    movs r0, #0\n"
        ".L080B2930:\n"
        "    strh r0, [r4, #0xe]\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}

#endif

// sub_080B2938 @ 0x080B2938
/* View type of the current map variant (0-3, selects the window layout of sub_080B29A8). */
u32 sub_080B2938(void)
{
    struct MapHeader *map = sub_080C8B10(gUnk_03004614, gUnk_03004514);
    u32 r;

    if (sub_080B9750() == 0)
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
#ifdef NONMATCHING
/* Window rectangles (WIN0H/WIN1H/WIN0V/WIN1V shadows) and WININ/WINOUT for the field view. */
void sub_080B29A8(u16 mode)
{
    if (mode == 0 || mode == 2)
    {
        gUnk_03000030 = 0x5A;
        gUnk_03000031 = 0x38;
        gUnk_03000034 = 0x58;
        gUnk_03000035 = 0x18;
        gUnk_03000038 = 0x2F;
        gUnk_03000032 = 0xB8;
        gUnk_03000033 = 0x96;
        gUnk_03000036 = 0x58;
        gUnk_03000037 = 0x18;
        gUnk_03000039 = 0x2F;
        gUnk_0300003A = 0x3F;
    }
    else if (mode == 1)
    {
        gUnk_03000030 = 0x98;
        gUnk_03000031 = 0x58;
        gUnk_03000034 = 0x18;
        gUnk_03000035 = 0;
        gUnk_03000038 = 0x2F;
        gUnk_03000032 = 0x98;
        gUnk_03000033 = 0x58;
        gUnk_03000036 = 0x18;
        gUnk_03000037 = 0;
        gUnk_03000039 = 0x2F;
        gUnk_0300003A = 0x3F;
    }
    else if (mode == 3)
    {
        gUnk_03000038 = 0x3F;
        gUnk_03000039 = 0x3F;
        gUnk_0300003A = 0x3F;
    }
}
#else
NAKED
void sub_080B29A8(u16 mode)
{
    asm_unified(
        ".L080B29A8:\n"
        "    push {r4, r5, r6, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L080B29B6\n"
        "    cmp r0, #2\n"
        "    bne .L080B2A20\n"
        ".L080B29B6:\n"
        "    ldr r1, .L080B29F4\n"
        "    movs r0, #0x5a\n"
        "    strb r0, [r1]\n"
        "    ldr r1, .L080B29F8\n"
        "    movs r0, #0x38\n"
        "    strb r0, [r1]\n"
        "    ldr r0, .L080B29FC\n"
        "    movs r4, #0x58\n"
        "    strb r4, [r0]\n"
        "    ldr r0, .L080B2A00\n"
        "    movs r3, #0x18\n"
        "    strb r3, [r0]\n"
        "    ldr r0, .L080B2A04\n"
        "    movs r5, #0x3f\n"
        "    movs r2, #0x2f\n"
        "    strb r2, [r0]\n"
        "    ldr r1, .L080B2A08\n"
        "    movs r0, #0xb8\n"
        "    strb r0, [r1]\n"
        "    ldr r1, .L080B2A0C\n"
        "    movs r0, #0x96\n"
        "    strb r0, [r1]\n"
        "    ldr r0, .L080B2A10\n"
        "    strb r4, [r0]\n"
        "    ldr r0, .L080B2A14\n"
        "    strb r3, [r0]\n"
        "    ldr r0, .L080B2A18\n"
        "    strb r2, [r0]\n"
        "    ldr r0, .L080B2A1C\n"
        "    strb r5, [r0]\n"
        "    b .L080B2A9E\n"
        ".L080B29F4: .4byte 0x03000030 @ IWRAM+0x30\n"
        ".L080B29F8: .4byte 0x03000031 @ IWRAM+0x31\n"
        ".L080B29FC: .4byte 0x03000034 @ IWRAM+0x34\n"
        ".L080B2A00: .4byte 0x03000035 @ IWRAM+0x35\n"
        ".L080B2A04: .4byte 0x03000038 @ IWRAM+0x38\n"
        ".L080B2A08: .4byte 0x03000032 @ IWRAM+0x32\n"
        ".L080B2A0C: .4byte 0x03000033 @ IWRAM+0x33\n"
        ".L080B2A10: .4byte 0x03000036 @ IWRAM+0x36\n"
        ".L080B2A14: .4byte 0x03000037 @ IWRAM+0x37\n"
        ".L080B2A18: .4byte 0x03000039 @ IWRAM+0x39\n"
        ".L080B2A1C: .4byte 0x0300003A @ IWRAM+0x3A\n"
        ".L080B2A20:\n"
        "    cmp r0, #1\n"
        "    bne .L080B2A8C\n"
        "    ldr r0, .L080B2A60\n"
        "    movs r5, #0x98\n"
        "    strb r5, [r0]\n"
        "    ldr r0, .L080B2A64\n"
        "    movs r4, #0x58\n"
        "    strb r4, [r0]\n"
        "    ldr r0, .L080B2A68\n"
        "    movs r3, #0x18\n"
        "    strb r3, [r0]\n"
        "    ldr r0, .L080B2A6C\n"
        "    movs r2, #0\n"
        "    strb r2, [r0]\n"
        "    ldr r0, .L080B2A70\n"
        "    movs r6, #0x3f\n"
        "    movs r1, #0x2f\n"
        "    strb r1, [r0]\n"
        "    ldr r0, .L080B2A74\n"
        "    strb r5, [r0]\n"
        "    ldr r0, .L080B2A78\n"
        "    strb r4, [r0]\n"
        "    ldr r0, .L080B2A7C\n"
        "    strb r3, [r0]\n"
        "    ldr r0, .L080B2A80\n"
        "    strb r2, [r0]\n"
        "    ldr r0, .L080B2A84\n"
        "    strb r1, [r0]\n"
        "    ldr r0, .L080B2A88\n"
        "    strb r6, [r0]\n"
        "    b .L080B2A9E\n"
        "    .byte 0x00, 0x00\n"
        ".L080B2A60: .4byte 0x03000030 @ IWRAM+0x30\n"
        ".L080B2A64: .4byte 0x03000031 @ IWRAM+0x31\n"
        ".L080B2A68: .4byte 0x03000034 @ IWRAM+0x34\n"
        ".L080B2A6C: .4byte 0x03000035 @ IWRAM+0x35\n"
        ".L080B2A70: .4byte 0x03000038 @ IWRAM+0x38\n"
        ".L080B2A74: .4byte 0x03000032 @ IWRAM+0x32\n"
        ".L080B2A78: .4byte 0x03000033 @ IWRAM+0x33\n"
        ".L080B2A7C: .4byte 0x03000036 @ IWRAM+0x36\n"
        ".L080B2A80: .4byte 0x03000037 @ IWRAM+0x37\n"
        ".L080B2A84: .4byte 0x03000039 @ IWRAM+0x39\n"
        ".L080B2A88: .4byte 0x0300003A @ IWRAM+0x3A\n"
        ".L080B2A8C:\n"
        "    cmp r0, #3\n"
        "    bne .L080B2A9E\n"
        "    ldr r0, .L080B2AA4\n"
        "    movs r1, #0x3f\n"
        "    strb r1, [r0]\n"
        "    ldr r0, .L080B2AA8\n"
        "    strb r1, [r0]\n"
        "    ldr r0, .L080B2AAC\n"
        "    strb r1, [r0]\n"
        ".L080B2A9E:\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080B2AA4: .4byte 0x03000038 @ IWRAM+0x38\n"
        ".L080B2AA8: .4byte 0x03000039 @ IWRAM+0x39\n"
        ".L080B2AAC: .4byte 0x0300003A @ IWRAM+0x3A\n"
    );
}

#endif
