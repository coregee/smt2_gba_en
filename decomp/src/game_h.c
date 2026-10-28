/* Automap screen. */

#include "global.h"
#include "game.h"

/* NONMATCHING: only the base/value registers of the step increment in case 6 swap. */
// sub_080B38A8 @ 0x080B38A8
#ifdef NONMATCHING
/* Automap open/close steps (gFieldState.unk1E); returns 1 when open, -1 when closed. */
s32 sub_080B38A8(void)
{
    s32 result = 0;

    switch (gFieldState.unk1E)
    {
    case 0:
        sub_080C14FC();
        Tilemap_FillRect(0, gUnk_02000000, 1, 0, 0x1C, 0x0D);
        DmaFill16(3, 0, gUnk_03002EB0, 0x100);
        VBlankTask_AddCounted(BgPicture_SetupStepTask, 1);
        break;
    case 2:
        if (BgPicture_LoadStep(0) == 1)
            gFieldState.unk1E++;
        break;
    case 6:
    {
        u16 i;
        u8 *p;

        sub_080B0778();
        gFieldState.unk1E++;
        p = (u8 *)gPaletteBuffer;
        i = 0;
        goto test;
        do
        {
            i++;
            p++;
            if (i > 31)
                break;
        test:;
        } while (*p == 0);
        if (i == 32)
        {
            PalFade_FadeRangeInFromBlack(0, 0x80, 1);
            PalFade_FadeRangeInFromBlack(0x100, 0xD0, 1);
        }
        break;
    }
    case 7:
        if (PalFade_AllDone() == 1)
        {
            gFieldState.unk1E++;
            gUnk_0200E7D4[0x1A] = 0;
            if (Flag_Test(0x105))
            {
                Flag_Clear(0x102);
                Flag_Clear(0x106);
                Flag_Clear(0x105);
            }
        }
        break;
    case 8:
        result = 1;
        break;
    case 9:
        if (sub_080B092C() == 0)
        {
            sub_080C14FC();
            gFieldState.unk1E = 0x14;
            sub_080B7530(0);
        }
        break;
    case 0x1C:
        sub_080C3818(1);
        if (View_IsSideOpen(0) == 0 && View_IsSideOpen(1) == 0 && View_IsSideOpen(3) == 0)
        {
            gFieldState.unk02 = sub_080B1A1C(gFieldState.unk02);
            sub_080B2030(gFieldState.unk0A, gFieldState.unk02, 3);
        }
        else
        {
            sub_080B05A4();
            Field_SetState(0x1F);
            sub_080B2840(0, 0, 0);
            gFieldState.unk1E = 0;
        }
        result = -1;
        break;
    default:
        VBlankTask_AddCounted(BgPicture_SetupStepTask, 1);
        break;
    }
    return result;
}
#else
NAKED
s32 sub_080B38A8(void)
{
    asm_unified(
        ".L080B38A8:\n"
        "    push {r4, r5, lr}\n"
        "    sub sp, #0xc\n"
        "    movs r5, #0\n"
        "    ldr r0, .L080B38C4\n"
        "    ldrh r0, [r0, #0x1e]\n"
        "    cmp r0, #0x1c\n"
        "    bls .L080B38B8\n"
        "    b .L080B3AC4\n"
        ".L080B38B8:\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L080B38C8\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080B38C4: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B38C8: .4byte gUnknown_080B38CC\n"
        "    .global gUnknown_080B38CC\n"
        "gUnknown_080B38CC:\n"
        ".L080B38CC: @ jump table\n"
        "    .4byte .L080B3940\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B398C\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B39A8\n"
        "    .4byte .L080B39F2\n"
        "    .4byte .L080B3A3C\n"
        "    .4byte .L080B3A40\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B3AC4\n"
        "    .4byte .L080B3A60\n"
        ".L080B3940:\n"
        "    bl sub_080C14FC\n"
        "    ldr r1, .L080B3978\n"
        "    movs r0, #0x1c\n"
        "    str r0, [sp]\n"
        "    movs r0, #0xd\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r2, #1\n"
        "    movs r3, #0\n"
        "    bl Tilemap_FillRect\n"
        "    add r1, sp, #8\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L080B397C\n"
        "    add r0, sp, #8\n"
        "    str r0, [r1]\n"
        "    ldr r0, .L080B3980\n"
        "    str r0, [r1, #4]\n"
        "    ldr r0, .L080B3984\n"
        "    str r0, [r1, #8]\n"
        "    ldr r0, [r1, #8]\n"
        "    ldr r0, .L080B3988\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    b .L080B3ACC\n"
        ".L080B3978: .4byte 0x02000000 @ EWRAM\n"
        ".L080B397C: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080B3980: .4byte 0x03002EB0 @ IWRAM+0x2EB0\n"
        ".L080B3984: .4byte 0x81000080\n"
        ".L080B3988: .4byte BgPicture_SetupStepTask\n"
        ".L080B398C:\n"
        "    movs r0, #0\n"
        "    bl BgPicture_LoadStep\n"
        "    cmp r0, #1\n"
        "    beq .L080B3998\n"
        "    b .L080B3ACC\n"
        ".L080B3998:\n"
        "    ldr r1, .L080B39A4\n"
        "    ldrh r0, [r1, #0x1e]\n"
        "    adds r0, #1\n"
        "    strh r0, [r1, #0x1e]\n"
        "    b .L080B3ACC\n"
        "    .byte 0x00, 0x00\n"
        ".L080B39A4: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B39A8:\n"
        "    bl sub_080B0778\n"
        "    ldr r0, .L080B39BC\n"
        "    ldrh r1, [r0, #0x1e]\n"
        "    adds r1, #1\n"
        "    strh r1, [r0, #0x1e]\n"
        "    ldr r2, .L080B39C0\n"
        "    movs r1, #0\n"
        "    b .L080B39D0\n"
        "    .byte 0x00, 0x00\n"
        ".L080B39BC: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B39C0: .4byte 0x03002DB0 @ IWRAM+0x2DB0\n"
        ".L080B39C4:\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    adds r2, #1\n"
        "    cmp r1, #0x1f\n"
        "    bhi .L080B39D6\n"
        ".L080B39D0:\n"
        "    ldrb r0, [r2]\n"
        "    cmp r0, #0\n"
        "    beq .L080B39C4\n"
        ".L080B39D6:\n"
        "    cmp r1, #0x20\n"
        "    bne .L080B3ACC\n"
        "    movs r0, #0\n"
        "    movs r1, #0x80\n"
        "    movs r2, #1\n"
        "    bl PalFade_FadeRangeInFromBlack\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    movs r1, #0xd0\n"
        "    movs r2, #1\n"
        "    bl PalFade_FadeRangeInFromBlack\n"
        "    b .L080B3ACC\n"
        ".L080B39F2:\n"
        "    bl PalFade_AllDone\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bne .L080B3ACC\n"
        "    ldr r1, .L080B3A30\n"
        "    ldrh r0, [r1, #0x1e]\n"
        "    adds r0, #1\n"
        "    movs r2, #0\n"
        "    strh r0, [r1, #0x1e]\n"
        "    ldr r0, .L080B3A34\n"
        "    strh r2, [r0, #0x34]\n"
        "    ldr r4, .L080B3A38\n"
        "    adds r0, r4, #0\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    beq .L080B3ACC\n"
        "    movs r0, #0x81\n"
        "    lsls r0, r0, #1\n"
        "    bl Flag_Clear\n"
        "    movs r0, #0x83\n"
        "    lsls r0, r0, #1\n"
        "    bl Flag_Clear\n"
        "    adds r0, r4, #0\n"
        "    bl Flag_Clear\n"
        "    b .L080B3ACC\n"
        ".L080B3A30: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B3A34: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
        ".L080B3A38: .4byte 0x00000105\n"
        ".L080B3A3C:\n"
        "    movs r5, #1\n"
        "    b .L080B3ACC\n"
        ".L080B3A40:\n"
        "    bl sub_080B092C\n"
        "    cmp r0, #0\n"
        "    bne .L080B3ACC\n"
        "    bl sub_080C14FC\n"
        "    ldr r1, .L080B3A5C\n"
        "    movs r0, #0x14\n"
        "    strh r0, [r1, #0x1e]\n"
        "    movs r0, #0\n"
        "    bl sub_080B7530\n"
        "    b .L080B3ACC\n"
        "    .byte 0x00, 0x00\n"
        ".L080B3A5C: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B3A60:\n"
        "    movs r0, #1\n"
        "    bl sub_080C3818\n"
        "    movs r0, #0\n"
        "    bl View_IsSideOpen\n"
        "    cmp r0, #0\n"
        "    bne .L080B3AA0\n"
        "    movs r0, #1\n"
        "    bl View_IsSideOpen\n"
        "    cmp r0, #0\n"
        "    bne .L080B3AA0\n"
        "    movs r0, #3\n"
        "    bl View_IsSideOpen\n"
        "    cmp r0, #0\n"
        "    bne .L080B3AA0\n"
        "    ldr r4, .L080B3A9C\n"
        "    ldrh r0, [r4, #2]\n"
        "    bl sub_080B1A1C\n"
        "    strh r0, [r4, #2]\n"
        "    ldrh r0, [r4, #0xa]\n"
        "    ldrh r1, [r4, #2]\n"
        "    movs r2, #3\n"
        "    bl sub_080B2030\n"
        "    b .L080B3ABA\n"
        "    .byte 0x00, 0x00\n"
        ".L080B3A9C: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B3AA0:\n"
        "    bl sub_080B05A4\n"
        "    movs r0, #0x1f\n"
        "    bl Field_SetState\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    bl sub_080B2840\n"
        "    ldr r1, .L080B3AC0\n"
        "    movs r0, #0\n"
        "    strh r0, [r1, #0x1e]\n"
        ".L080B3ABA:\n"
        "    movs r5, #1\n"
        "    rsbs r5, r5, #0\n"
        "    b .L080B3ACC\n"
        ".L080B3AC0: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B3AC4:\n"
        "    ldr r0, .L080B3AD8\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        ".L080B3ACC:\n"
        "    adds r0, r5, #0\n"
        "    add sp, #0xc\n"
        "    pop {r4, r5}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L080B3AD8: .4byte BgPicture_SetupStepTask\n"
    );
}

#endif


// sub_080B3ADC @ 0x080B3ADC
void sub_080B3ADC(void)
{
    DmaCopy32S(3, gBgPictureBuffer, (void *)0x06004040, 0x1000);
}

// sub_080B3B00 @ 0x080B3B00
void sub_080B3B00(void)
{
    DmaCopy32S(3, gBgPictureBuffer, (void *)0x06005040, 0xFC0);
    DmaCopy32S(3, gBgPictureBuffer + 0xFC0, (void *)0x06008040, 0x40);
}

// sub_080B3B3C @ 0x080B3B3C
void sub_080B3B3C(void)
{
    DmaCopy32S(3, gBgPictureBuffer, (void *)0x06008080, 0x1000);
}

// sub_080B3B60 @ 0x080B3B60
void sub_080B3B60(void)
{
    u8 *src = gBgPictureBuffer;

    if (gUnk_03003BA0 == 0)
    {
        DmaCopy32S(3, src, (void *)0x06009080, 0x1000);
    }
    else
    {
        DmaCopy32S(3, src, (void *)0x06008E00, 0x1000);
    }
}

// sub_080B3BA4 @ 0x080B3BA4
void sub_080B3BA4(void)
{
    u8 *src = gBgPictureBuffer;

    if (gUnk_03003BA0 == 0)
    {
        DmaCopy32S(3, src, (void *)0x0600A080, 0x1000);
    }
    else
    {
        DmaCopy32S(3, src, (void *)0x06009E00, 0x1000);
    }
}

// sub_080B3BE8 @ 0x080B3BE8
void sub_080B3BE8(void)
{
    u8 *src = gBgPictureBuffer;

    if (gUnk_03003BA0 == 0)
    {
        DmaCopy32S(3, src, (void *)0x0600B080, 0xB00);
    }
    else
    {
        DmaCopy32S(3, src, (void *)0x0600AE00, 0xD80);
    }
}

// sub_080B3C34 @ 0x080B3C34
void sub_080B3C34(u32 idx, u32 now)
{
    VoidFunc func = gUnknown_081625D4[idx];

    if (func != NULL)
    {
        if (now == 0)
            VBlankTask_AddCounted(func, 1);
        else
            func();
    }
}

/* NONMATCHING: register allocation differs (bg/now/piece pointer) and the original cross-jumps the LZ77 call of the first branch. */
// BgPicture_LoadPiece @ 0x080B3C5C
#ifdef NONMATCHING
/* Loads the next piece (gBgPicturePiece) of the background picture into the buffer at
   0x0200AFC8 and queues its upload (sub_080B3C34). Huffman pieces take two calls: the
   Huffman stage goes to buffer+0x1000 and bit 15 of the piece index is set, the next call
   LZ77-decodes that into the buffer. gBgPicturePiece becomes 0xFFFF when all are done; with
   gUnk_03003BA0 set the pieces from 8 on are uploaded through slots 3 and up. */
void BgPicture_LoadPiece(u32 now)
{
    struct BgPicture *bg = sub_080C5EF0(gUnk_03004534);
    const void *src;
    u16 huff;
    u32 zero;

    if (gUnk_03003BA0 == 0)
    {
        huff = gBgPicturePiece & 0x8000;
        if (huff)
        {
            gBgPicturePiece &= 0x7FFF;
            LZ77UnCompWram((void *)0x0200BFC8, (void *)0x0200AFC8);
        }
        else
        {
            src = sub_080C5F04(gUnk_03004534, gBgPicturePiece);
            if (src == NULL)
            {
                gBgPicturePiece = 0xFFFF;
                return;
            }
            zero = huff;
            CpuFastSet(&zero, (void *)0x0200AFC8, 0x01000400);
            if (bg->kind == 1)
            {
                LZ77UnCompWram(src, (void *)0x0200AFC8);
            }
            else
            {
                if (bg->kind == 2)
                {
                    HuffUnComp(src, (void *)(0x0200AFC8 + 0x1000));
                    gBgPicturePiece |= 0x8000;
                }
                return;
            }
        }
        sub_080B3C34(gBgPicturePiece, now);
        gBgPicturePiece++;
        return;
    }

    huff = gBgPicturePiece & 0x8000;
    if (huff)
    {
        gBgPicturePiece &= 0x7FFF;
        LZ77UnCompWram((void *)0x0200BFC8, (void *)0x0200AFC8);
        if (gBgPicturePiece < 8)
            sub_080B3C34(gBgPicturePiece, now);
        else
            sub_080B3C34(gBgPicturePiece - 5, now);
        gBgPicturePiece++;
        return;
    }
    src = sub_080C5F04(gUnk_03004534, gBgPicturePiece);
    if (src == NULL)
    {
        if (gBgPicturePiece < 8)
            gBgPicturePiece = 8;
        else
            gBgPicturePiece = 0xFFFF;
        return;
    }
    zero = huff;
    CpuFastSet(&zero, (void *)0x0200AFC8, 0x01000400);
    if (gBgPicturePiece < 8)
    {
        if (bg->kind == 1)
        {
            LZ77UnCompWram(src, (void *)0x0200AFC8);
            sub_080B3C34(gBgPicturePiece, now);
            gBgPicturePiece++;
        }
        else if (bg->kind == 2)
        {
            HuffUnComp(src, (void *)(0x0200AFC8 + 0x1000));
            gBgPicturePiece |= 0x8000;
        }
    }
    else
    {
        if (bg->kind == 1)
        {
            LZ77UnCompWram(src, (void *)0x0200AFC8);
            sub_080B3C34(gBgPicturePiece - 5, now);
            gBgPicturePiece++;
        }
        else if (bg->kind == 2)
        {
            HuffUnComp(src, (void *)(0x0200AFC8 + 0x1000));
            gBgPicturePiece |= 0x8000;
        }
    }
}
#else
NAKED
void BgPicture_LoadPiece(u32 now)
{
    asm_unified(
        ".L080B3C5C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #4\n"
        "    mov sb, r0\n"
        "    ldr r7, .L080B3CA0\n"
        "    ldrh r0, [r7]\n"
        "    bl sub_080C5EF0\n"
        "    mov r8, r0\n"
        "    ldr r0, .L080B3CA4\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L080B3D24\n"
        "    ldr r5, .L080B3CA8\n"
        "    ldrh r1, [r5]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #8\n"
        "    mov sl, r0\n"
        "    ands r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r6, #0\n"
        "    beq .L080B3CB8\n"
        "    ldr r0, .L080B3CAC\n"
        "    ands r0, r1\n"
        "    strh r0, [r5]\n"
        "    ldr r0, .L080B3CB0\n"
        "    ldr r2, .L080B3CB4\n"
        "    adds r1, r0, r2\n"
        "    b .L080B3CE0\n"
        "    .byte 0x00, 0x00\n"
        ".L080B3CA0: .4byte 0x03004534 @ IWRAM+0x4534\n"
        ".L080B3CA4: .4byte 0x03003BA0 @ IWRAM+0x3BA0\n"
        ".L080B3CA8: .4byte 0x03003BAC @ IWRAM+0x3BAC\n"
        ".L080B3CAC: .4byte 0x00007FFF\n"
        ".L080B3CB0: .4byte 0x0200BFC8 @ EWRAM+0xBFC8\n"
        ".L080B3CB4: .4byte 0xFFFFF000\n"
        ".L080B3CB8:\n"
        "    ldrh r0, [r7]\n"
        "    ldrh r1, [r5]\n"
        "    bl sub_080C5F04\n"
        "    adds r4, r0, #0\n"
        "    cmp r4, #0\n"
        "    beq .L080B3D18\n"
        "    str r6, [sp]\n"
        "    ldr r6, .L080B3CF4\n"
        "    ldr r2, .L080B3CF8\n"
        "    mov r0, sp\n"
        "    adds r1, r6, #0\n"
        "    bl CpuFastSet\n"
        "    mov r1, r8\n"
        "    ldr r0, [r1]\n"
        "    cmp r0, #1\n"
        "    bne .L080B3CFC\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r6, #0\n"
        ".L080B3CE0:\n"
        "    bl LZ77UnCompWram\n"
        "    ldrh r0, [r5]\n"
        "    mov r1, sb\n"
        "    bl sub_080B3C34\n"
        "    ldrh r0, [r5]\n"
        "    adds r0, #1\n"
        "    strh r0, [r5]\n"
        "    b .L080B3E28\n"
        ".L080B3CF4: .4byte 0x0200AFC8 @ EWRAM+0xAFC8\n"
        ".L080B3CF8: .4byte 0x01000400\n"
        ".L080B3CFC:\n"
        "    cmp r0, #2\n"
        "    beq .L080B3D02\n"
        "    b .L080B3E28\n"
        ".L080B3D02:\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #5\n"
        "    adds r1, r6, r2\n"
        "    adds r0, r4, #0\n"
        "    bl HuffUnComp\n"
        "    ldrh r1, [r5]\n"
        "    mov r0, sl\n"
        "    orrs r0, r1\n"
        "    strh r0, [r5]\n"
        "    b .L080B3E28\n"
        ".L080B3D18:\n"
        "    ldr r1, .L080B3D20\n"
        "    adds r0, r1, #0\n"
        "    strh r0, [r5]\n"
        "    b .L080B3E28\n"
        ".L080B3D20: .4byte 0x0000FFFF\n"
        ".L080B3D24:\n"
        "    ldr r4, .L080B3D58\n"
        "    ldrh r1, [r4]\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #8\n"
        "    mov sl, r2\n"
        "    mov r0, sl\n"
        "    ands r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r6, #0\n"
        "    beq .L080B3D80\n"
        "    ldr r0, .L080B3D5C\n"
        "    ands r0, r1\n"
        "    strh r0, [r4]\n"
        "    ldr r0, .L080B3D60\n"
        "    ldr r2, .L080B3D64\n"
        "    adds r1, r0, r2\n"
        "    bl LZ77UnCompWram\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #7\n"
        "    bhi .L080B3D68\n"
        "    mov r1, sb\n"
        "    bl sub_080B3C34\n"
        "    b .L080B3D72\n"
        ".L080B3D58: .4byte 0x03003BAC @ IWRAM+0x3BAC\n"
        ".L080B3D5C: .4byte 0x00007FFF\n"
        ".L080B3D60: .4byte 0x0200BFC8 @ EWRAM+0xBFC8\n"
        ".L080B3D64: .4byte 0xFFFFF000\n"
        ".L080B3D68:\n"
        "    ldrh r0, [r4]\n"
        "    subs r0, #5\n"
        "    mov r1, sb\n"
        "    bl sub_080B3C34\n"
        ".L080B3D72:\n"
        "    ldr r1, .L080B3D7C\n"
        "    ldrh r0, [r1]\n"
        "    adds r0, #1\n"
        "    strh r0, [r1]\n"
        "    b .L080B3E28\n"
        ".L080B3D7C: .4byte 0x03003BAC @ IWRAM+0x3BAC\n"
        ".L080B3D80:\n"
        "    ldrh r0, [r7]\n"
        "    ldrh r1, [r4]\n"
        "    bl sub_080C5F04\n"
        "    adds r5, r0, #0\n"
        "    cmp r5, #0\n"
        "    beq .L080B3E18\n"
        "    str r6, [sp]\n"
        "    ldr r6, .L080B3DC0\n"
        "    ldr r2, .L080B3DC4\n"
        "    mov r0, sp\n"
        "    adds r1, r6, #0\n"
        "    bl CpuFastSet\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #7\n"
        "    bhi .L080B3DE0\n"
        "    mov r1, r8\n"
        "    ldr r0, [r1]\n"
        "    cmp r0, #1\n"
        "    bne .L080B3DC8\n"
        "    adds r0, r5, #0\n"
        "    adds r1, r6, #0\n"
        "    bl LZ77UnCompWram\n"
        "    ldrh r0, [r4]\n"
        "    mov r1, sb\n"
        "    bl sub_080B3C34\n"
        "    ldrh r0, [r4]\n"
        "    adds r0, #1\n"
        "    b .L080B3E26\n"
        ".L080B3DC0: .4byte 0x0200AFC8 @ EWRAM+0xAFC8\n"
        ".L080B3DC4: .4byte 0x01000400\n"
        ".L080B3DC8:\n"
        "    cmp r0, #2\n"
        "    bne .L080B3E28\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #5\n"
        "    adds r1, r6, r2\n"
        "    adds r0, r5, #0\n"
        "    bl HuffUnComp\n"
        "    ldrh r1, [r4]\n"
        "    mov r0, sl\n"
        "    orrs r0, r1\n"
        "    b .L080B3E26\n"
        ".L080B3DE0:\n"
        "    mov r1, r8\n"
        "    ldr r0, [r1]\n"
        "    cmp r0, #1\n"
        "    bne .L080B3E00\n"
        "    adds r0, r5, #0\n"
        "    adds r1, r6, #0\n"
        "    bl LZ77UnCompWram\n"
        "    ldrh r0, [r4]\n"
        "    subs r0, #5\n"
        "    mov r1, sb\n"
        "    bl sub_080B3C34\n"
        "    ldrh r0, [r4]\n"
        "    adds r0, #1\n"
        "    b .L080B3E26\n"
        ".L080B3E00:\n"
        "    cmp r0, #2\n"
        "    bne .L080B3E28\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #5\n"
        "    adds r1, r6, r2\n"
        "    adds r0, r5, #0\n"
        "    bl HuffUnComp\n"
        "    ldrh r1, [r4]\n"
        "    mov r0, sl\n"
        "    orrs r0, r1\n"
        "    b .L080B3E26\n"
        ".L080B3E18:\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #7\n"
        "    bhi .L080B3E22\n"
        "    movs r0, #8\n"
        "    b .L080B3E26\n"
        ".L080B3E22:\n"
        "    ldr r1, .L080B3E38\n"
        "    adds r0, r1, #0\n"
        ".L080B3E26:\n"
        "    strh r0, [r4]\n"
        ".L080B3E28:\n"
        "    add sp, #4\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080B3E38: .4byte 0x0000FFFF\n"
    );
}

#endif
