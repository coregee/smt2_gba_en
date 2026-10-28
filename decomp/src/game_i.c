/* Background picture (gUnk_03004534 = picture id) loading. */

#include "global.h"
#include "game.h"

// BgPicture_BeginLoad @ 0x080B3E3C
void BgPicture_BeginLoad(void)
{
    gUnk_0200AB04 |= 0x8000;
    gBgPicturePiece = 0;
    gUnk_03003BA0 = 0;
    if (sub_080C5F04(gUnk_03004534, 8) != 0)
        gUnk_03003BA0 = 1;
}

// sub_080B3E7C @ 0x080B3E7C
void sub_080B3E7C(void)
{
    sub_080C153C();
    BgPicture_BeginLoad();
}

// sub_080B3E8C @ 0x080B3E8C
void sub_080B3E8C(void)
{
    REG_DISPCNT &= ~0x800;
}

// sub_080B3EA0 @ 0x080B3EA0
void sub_080B3EA0(void)
{
}

// BgPicture_LoadStep @ 0x080B3EA4
/* One loading step; TRUE when all pieces are loaded. */
s32 BgPicture_LoadStep(u32 now)
{
    s32 done;

    if (gBgPicturePiece == 0xFFFF)
    {
        sub_080B3EA0();
        done = 1;
    }
    else
    {
        BgPicture_LoadPiece(now);
        done = 0;
    }
    return done;
}

// sub_080B3ED0 @ 0x080B3ED0
void sub_080B3ED0(void)
{
    struct BgPicture *bg = sub_080C5EF0(gUnk_03004534);
    u32 y;

    if (bg->unk4C != 0)
    {
        y = 0x50;
        if (bg->unk4C == 0x194 && Flag_Test(0x37))
            y = 0x20;
        CharObj_Create(0, bg->unk4C, y, 5, 0, 0);
    }
}

/* NONMATCHING: same structure; register allocation of the row loops differs. */
// BgPicture_BuildTilemap @ 0x080B3F1C
#ifdef NONMATCHING
/* Builds the background picture tilemap (BG3, 0x06003000): a base map from ROM plus a
   palette number per tile, (nibble + 8) << 12, from the picture's attribute tables. */
void BgPicture_BuildTilemap(void)
{
    struct BgPicture *bg = sub_080C5EF0(gUnk_03004534);
    vu32 *dma;
    const u8 *attr;
    const u8 *attr2;
    u16 *row;
    u16 *row2;
    u32 x, y;
    u16 pal;

    if (bg->kind == 0)
    {
        if (gUnk_03003BA0 == 0)
        {
            dma = (vu32 *)0x040000D4;
            dma[0] = (u32)gUnknown_081C25F0;
        }
        else
        {
            dma = (vu32 *)0x040000D4;
            dma[0] = (u32)gUnknown_081C32F4;
        }
    }
    else if (gUnk_03003BA0 == 0)
    {
        attr = sub_080C5F40(gUnk_03004534, 0);
        if ((u16)(gUnk_03004534 - 0xD9) <= 1)
        {
            pal = 8;
            if (gUnk_03004534 == 0xDA)
                pal = 7;
            DmaCopy32(3, gUnknown_081C2C74, gUnk_02000000, 0x1000);
            for (y = 0; y < 26; y++)
            {
                row = &gUnk_02000000[y * 32];
                for (x = 0; x < 30; x++)
                {
                    *row += ((*attr++ & 0xF) + pal) << 12;
                    row++;
                }
            }
        }
        else
        {
            DmaCopy32(3, gUnknown_081C25F4, gUnk_02000000, 0x1000);
            for (y = 0; y < 26; y++)
            {
                row = &gUnk_02000000[y * 32 + 1];
                for (x = 0; x < 28; x++)
                {
                    *row += ((*attr++ & 0xF) + 8) << 12;
                    row++;
                }
            }
        }
        dma = (vu32 *)0x040000D4;
        dma[0] = (u32)gUnk_02000000;
    }
    else
    {
        /* symmetric picture: the right half is the left half's attributes mirrored */
        attr = sub_080C5F40(gUnk_03004534, 0);
        attr2 = sub_080C5F40(gUnk_03004534, 1);
        DmaCopy32(3, gUnknown_081C32F8, gUnk_02000000, 0x1000);
        for (y = 0; y < 26; y++)
        {
            row = &gUnk_02000000[y * 32 + 1];
            row2 = &gUnk_02000000[y * 32 + 0x1C];
            for (x = 0; x < 14; x++)
            {
                *row += ((*attr++ & 0xF) + 8) << 12;
                *row2 += ((*attr2++ & 0xF) + 8) << 12;
                row2--;
                row++;
            }
        }
        dma = (vu32 *)0x040000D4;
        dma[0] = (u32)gUnk_02000000;
    }
    dma[1] = 0x06003000;
    dma[2] = 0x84000400;
    dma[2];
    if (gUnk_03004608 == 1)
    {
        gUnk_0300000E = gUnk_03004600;
        gUnk_03004608 = 0;
    }
    else if (gMainCallback == sub_0815C380)
    {
        gUnk_0300000E = 0x50;
    }
    else
    {
        gUnk_0300000E = bg->unk58;
    }
    sub_080BDF3C(gUnk_03004534);
}
#else
NAKED
void BgPicture_BuildTilemap(void)
{
    asm_unified(
        ".L080B3F1C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #4\n"
        "    ldr r6, .L080B3F48\n"
        "    ldrh r0, [r6]\n"
        "    bl sub_080C5EF0\n"
        "    mov sb, r0\n"
        "    ldr r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L080B3F68\n"
        "    ldr r0, .L080B3F4C\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L080B3F58\n"
        "    ldr r1, .L080B3F50\n"
        "    ldr r0, .L080B3F54\n"
        "    str r0, [r1]\n"
        "    b .L080B40B8\n"
        ".L080B3F48: .4byte 0x03004534 @ IWRAM+0x4534\n"
        ".L080B3F4C: .4byte 0x03003BA0 @ IWRAM+0x3BA0\n"
        ".L080B3F50: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080B3F54: .4byte gUnknown_081C25F0\n"
        ".L080B3F58:\n"
        "    ldr r1, .L080B3F60\n"
        "    ldr r0, .L080B3F64\n"
        "    str r0, [r1]\n"
        "    b .L080B40B8\n"
        ".L080B3F60: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080B3F64: .4byte gUnknown_081C32F4\n"
        ".L080B3F68:\n"
        "    ldr r0, .L080B3FD4\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L080B4038\n"
        "    ldrh r0, [r6]\n"
        "    movs r1, #0\n"
        "    bl sub_080C5F40\n"
        "    adds r3, r0, #0\n"
        "    ldr r7, .L080B3FD8\n"
        "    ldrh r1, [r6]\n"
        "    adds r0, r1, #0\n"
        "    subs r0, #0xd9\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bhi .L080B3FE8\n"
        "    movs r0, #8\n"
        "    mov r8, r0\n"
        "    cmp r1, #0xda\n"
        "    bne .L080B3F96\n"
        "    movs r1, #7\n"
        "    mov r8, r1\n"
        ".L080B3F96:\n"
        "    ldr r1, .L080B3FDC\n"
        "    ldr r0, .L080B3FE0\n"
        "    str r0, [r1]\n"
        "    str r7, [r1, #4]\n"
        "    ldr r0, .L080B3FE4\n"
        "    str r0, [r1, #8]\n"
        "    ldr r0, [r1, #8]\n"
        "    movs r0, #0\n"
        "    mov sl, r7\n"
        "    movs r5, #0xf\n"
        ".L080B3FAA:\n"
        "    movs r2, #0\n"
        "    adds r4, r0, #1\n"
        "    lsls r0, r0, #6\n"
        "    adds r1, r0, r7\n"
        ".L080B3FB2:\n"
        "    ldrb r0, [r3]\n"
        "    adds r3, #1\n"
        "    ands r0, r5\n"
        "    add r0, r8\n"
        "    lsls r0, r0, #0xc\n"
        "    ldrh r6, [r1]\n"
        "    adds r0, r0, r6\n"
        "    strh r0, [r1]\n"
        "    adds r1, #2\n"
        "    adds r2, #1\n"
        "    cmp r2, #0x1d\n"
        "    bls .L080B3FB2\n"
        "    adds r0, r4, #0\n"
        "    cmp r0, #0x19\n"
        "    bls .L080B3FAA\n"
        "    b .L080B4024\n"
        "    .byte 0x00, 0x00\n"
        ".L080B3FD4: .4byte 0x03003BA0 @ IWRAM+0x3BA0\n"
        ".L080B3FD8: .4byte 0x02000000 @ EWRAM\n"
        ".L080B3FDC: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080B3FE0: .4byte gUnknown_081C2C74\n"
        ".L080B3FE4: .4byte 0x84000400\n"
        ".L080B3FE8:\n"
        "    ldr r1, .L080B402C\n"
        "    ldr r0, .L080B4030\n"
        "    str r0, [r1]\n"
        "    str r7, [r1, #4]\n"
        "    ldr r0, .L080B4034\n"
        "    str r0, [r1, #8]\n"
        "    ldr r0, [r1, #8]\n"
        "    movs r0, #0\n"
        "    mov sl, r7\n"
        "    movs r5, #0xf\n"
        ".L080B3FFC:\n"
        "    movs r2, #0\n"
        "    adds r4, r0, #1\n"
        "    lsls r1, r0, #6\n"
        "    adds r0, r7, #2\n"
        "    adds r1, r1, r0\n"
        ".L080B4006:\n"
        "    ldrb r0, [r3]\n"
        "    adds r3, #1\n"
        "    ands r0, r5\n"
        "    adds r0, #8\n"
        "    lsls r0, r0, #0xc\n"
        "    ldrh r6, [r1]\n"
        "    adds r0, r0, r6\n"
        "    strh r0, [r1]\n"
        "    adds r1, #2\n"
        "    adds r2, #1\n"
        "    cmp r2, #0x1b\n"
        "    bls .L080B4006\n"
        "    adds r0, r4, #0\n"
        "    cmp r0, #0x19\n"
        "    bls .L080B3FFC\n"
        ".L080B4024:\n"
        "    ldr r1, .L080B402C\n"
        "    mov r7, sl\n"
        "    str r7, [r1]\n"
        "    b .L080B40B8\n"
        ".L080B402C: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080B4030: .4byte gUnknown_081C25F4\n"
        ".L080B4034: .4byte 0x84000400\n"
        ".L080B4038:\n"
        "    ldrh r0, [r6]\n"
        "    movs r1, #0\n"
        "    bl sub_080C5F40\n"
        "    adds r5, r0, #0\n"
        "    ldrh r0, [r6]\n"
        "    movs r1, #1\n"
        "    bl sub_080C5F40\n"
        "    adds r4, r0, #0\n"
        "    ldr r0, .L080B40D8\n"
        "    mov r8, r0\n"
        "    ldr r1, .L080B40DC\n"
        "    ldr r0, .L080B40E0\n"
        "    str r0, [r1]\n"
        "    mov r7, r8\n"
        "    str r7, [r1, #4]\n"
        "    ldr r0, .L080B40E4\n"
        "    str r0, [r1, #8]\n"
        "    ldr r0, [r1, #8]\n"
        "    movs r2, #0\n"
        "    mov sl, r8\n"
        "    movs r0, #0xf\n"
        "    mov ip, r0\n"
        ".L080B4068:\n"
        "    movs r6, #0\n"
        "    lsls r0, r2, #5\n"
        "    adds r1, r2, #1\n"
        "    str r1, [sp]\n"
        "    adds r0, #0x1c\n"
        "    lsls r2, r2, #6\n"
        "    mov r1, r8\n"
        "    adds r1, #2\n"
        "    adds r2, r2, r1\n"
        "    lsls r0, r0, #1\n"
        "    mov r7, r8\n"
        "    adds r3, r0, r7\n"
        ".L080B4080:\n"
        "    ldrb r0, [r5]\n"
        "    adds r5, #1\n"
        "    ldrb r1, [r4]\n"
        "    adds r4, #1\n"
        "    mov r7, ip\n"
        "    ands r0, r7\n"
        "    adds r0, #8\n"
        "    ands r1, r7\n"
        "    adds r1, #8\n"
        "    lsls r0, r0, #0xc\n"
        "    ldrh r7, [r2]\n"
        "    adds r0, r0, r7\n"
        "    strh r0, [r2]\n"
        "    lsls r1, r1, #0xc\n"
        "    ldrh r0, [r3]\n"
        "    adds r1, r1, r0\n"
        "    strh r1, [r3]\n"
        "    subs r3, #2\n"
        "    adds r2, #2\n"
        "    adds r6, #1\n"
        "    cmp r6, #0xd\n"
        "    bls .L080B4080\n"
        "    ldr r2, [sp]\n"
        "    cmp r2, #0x19\n"
        "    bls .L080B4068\n"
        "    ldr r1, .L080B40DC\n"
        "    mov r6, sl\n"
        "    str r6, [r1]\n"
        ".L080B40B8:\n"
        "    ldr r0, .L080B40E8\n"
        "    str r0, [r1, #4]\n"
        "    ldr r0, .L080B40E4\n"
        "    str r0, [r1, #8]\n"
        "    ldr r0, [r1, #8]\n"
        "    ldr r7, .L080B40EC\n"
        "    ldrh r0, [r7]\n"
        "    cmp r0, #1\n"
        "    bne .L080B40F8\n"
        "    ldr r0, .L080B40F0\n"
        "    ldrh r0, [r0]\n"
        "    ldr r1, .L080B40F4\n"
        "    strh r0, [r1]\n"
        "    movs r0, #0\n"
        "    strh r0, [r7]\n"
        "    b .L080B4120\n"
        ".L080B40D8: .4byte 0x02000000 @ EWRAM\n"
        ".L080B40DC: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080B40E0: .4byte gUnknown_081C32F8\n"
        ".L080B40E4: .4byte 0x84000400\n"
        ".L080B40E8: .4byte 0x06003000 @ VRAM+0x3000\n"
        ".L080B40EC: .4byte 0x03004608 @ IWRAM+0x4608\n"
        ".L080B40F0: .4byte 0x03004600 @ IWRAM+0x4600\n"
        ".L080B40F4: .4byte 0x0300000E @ IWRAM+0xE\n"
        ".L080B40F8:\n"
        "    ldr r0, .L080B410C\n"
        "    ldr r1, [r0]\n"
        "    ldr r0, .L080B4110\n"
        "    cmp r1, r0\n"
        "    bne .L080B4118\n"
        "    movs r0, #0x50\n"
        "    ldr r6, .L080B4114\n"
        "    strh r0, [r6]\n"
        "    b .L080B4120\n"
        "    .byte 0x00, 0x00\n"
        ".L080B410C: .4byte 0x030020E4 @ IWRAM+0x20E4\n"
        ".L080B4110: .4byte sub_0815C380\n"
        ".L080B4114: .4byte 0x0300000E @ IWRAM+0xE\n"
        ".L080B4118:\n"
        "    mov r7, sb\n"
        "    ldr r0, [r7, #0x58]\n"
        "    ldr r1, .L080B4138\n"
        "    strh r0, [r1]\n"
        ".L080B4120:\n"
        "    ldr r6, .L080B413C\n"
        "    ldrh r0, [r6]\n"
        "    bl sub_080BDF3C\n"
        "    add sp, #4\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080B4138: .4byte 0x0300000E @ IWRAM+0xE\n"
        ".L080B413C: .4byte 0x03004534 @ IWRAM+0x4534\n"
    );
}

#endif
