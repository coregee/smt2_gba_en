/* Casino minigame on an 8x8 board of 64 numbers (0x081485A0-). */

#include "global.h"
#include "casino2.h"

/* Draws the low `digits` digits of n, most significant first, from x rightwards. */
// Keno_DrawDigits @ 0x081485A0
void Keno_DrawDigits(u32 n, u16 digits, u16 x, u16 y)
{
    u8 *d = NumberToDigits(n);
    u8 i = digits - 1;
    u32 k;

    for (k = 0; k < digits; k++)
    {
        Sprite_Draw(gUnknown_0879CE24[d[i]], 1, 0, 0, 0, x, y);
        i--;
        x += 8;
    }
}

// sub_08148618 @ 0x08148618
void sub_08148618(void)
{
    struct C145Grid *s = gGrid;
    u16 x, y;

    if (s->state == 3)
    {
        x = s->cursorX * 15 + 4;
        y = s->cursorY * 11 + 0x24;
        if (s->cursorY > 3)
            y += 0x1B;
        Sprite_Draw(gUnknown_0879CE58[s->cursorAnim], 1, 0, 0, 0, x, y);
        if ((gFrameCounter & 7) == 0)
            s->cursorAnim = (s->cursorAnim + 1) & 3;
    }
}

// sub_0814869C @ 0x0814869C
void sub_0814869C(u16 i, u16 x, u16 y)
{
    struct C145Grid *s = gGrid;
    const void *const *tbl = gUnknown_0879CEA8[i];

    if (s->sprFrame[i] != 0)
    {
        if (s->sprX[i] != 0 || s->sprY[i] != 0)
        {
            x = s->sprX[i];
            y = s->sprY[i];
        }
        Sprite_Draw(tbl[s->sprFrame[i]], 1, 0, 0, 0, x, y);
    }
}

// sub_08148718 @ 0x08148718
void sub_08148718(u16 i, u16 frame, u16 x, u16 y)
{
    struct C145Grid *s = gGrid;

    s->sprFrame[i] = frame;
    if (x != 0)
        s->sprX[i] = x;
    if (y != 0)
        s->sprY[i] = y;
}

// sub_08148754 @ 0x08148754
void sub_08148754(u16 i, u16 frame, u16 x, u16 y)
{
    struct C145Grid *s = gGrid;

    s->sprFrame[i] = frame;
    s->sprX[i] = x;
    s->sprY[i] = y;
}

// sub_08148780 @ 0x08148780
void sub_08148780(u32 unused, u16 i, u16 frame, u16 x, u16 y)
{
    sub_08148718(i, frame, x, y);
}

// sub_081487A4 @ 0x081487A4
void sub_081487A4(u32 unused, u16 i, u16 frame, u16 x, u16 y)
{
    sub_08148754(i, frame, x, y);
}

// sub_081487C8 @ 0x081487C8
void sub_081487C8(void)
{
    gUnk_03000040 = 0x2E40;
}

/* Starts the game. The draw is warmed up by sixteen rounds of sixteen numbers out of 64. */
// Keno_Init @ 0x081487D8
#ifdef NONMATCHING
void Keno_Init(void)
{
    struct C145Grid *s = gGrid;
    u32 zero = 0;
    u32 zero2;
    u32 r;
    u32 j, i;

    CpuSet(&zero, s, 0x05000200);
    zero2 = 0;
    DmaSet3(&zero2, 0x06000000, 0x85001000);
    REG_BG0CNT = 0x4008;
    gUnk_03000002 = 0;
    gDispRegs = 0xF0;
    sub_081487C8();
    s->unk198 = 8;
    s->unk19A = 8;
    s->unk19C = 0x10;
    s->unk19E = 0;
    gUnk_03000042 = 0x808;
    gUnk_03000044 = 0x10;
    s->state = 1;
    for (j = 0; j < 16; j++)
    {
        for (i = 0; i < 16; i++)
        {
        pick:
            r = Random_Byte() & 0x3F;
            if (s->cell[r] != 0)
                goto pick;
            s->cell[r] = 1;
        }
        Keno_RecordHistory();
        for (i = 0; i < 64; i++)
            s->cell[i] = 0;
    }
    sub_08148718(0, 0, 0, 0);
    sub_08148718(1, 0, 0, 0);
    sub_08148718(2, 0, 0, 0);
    sub_08148718(3, 1, 0, 0);
    sub_08148718(4, 1, 0, 0);
    s->sprX[4] = 0x87;
    s->sprY[4] = 0xA0;
    s->coins = sub_080C31F0();
}
#else
NAKED
void Keno_Init(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sb\n"
        "    mov r6, r8\n"
        "    push {r6, r7}\n"
        "    sub sp, #8\n"
        "    ldr r6, .L08148900\n"
        "    movs r4, #0\n"
        "    str r4, [sp]\n"
        "    ldr r2, .L08148904\n"
        "    mov r0, sp\n"
        "    adds r1, r6, #0\n"
        "    bl CpuSet\n"
        "    str r4, [sp, #4]\n"
        "    ldr r1, .L08148908\n"
        "    add r0, sp, #4\n"
        "    str r0, [r1]\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #0x13\n"
        "    str r0, [r1, #4]\n"
        "    ldr r0, .L0814890C\n"
        "    str r0, [r1, #8]\n"
        "    ldr r0, [r1, #8]\n"
        "    subs r1, #0xcc\n"
        "    ldr r2, .L08148910\n"
        "    adds r0, r2, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L08148914\n"
        "    strh r4, [r0]\n"
        "    ldr r1, .L08148918\n"
        "    movs r0, #0xf0\n"
        "    strh r0, [r1]\n"
        "    bl sub_081487C8\n"
        "    movs r1, #0xcc\n"
        "    lsls r1, r1, #1\n"
        "    adds r0, r6, r1\n"
        "    movs r1, #8\n"
        "    strh r1, [r0]\n"
        "    movs r2, #0xcd\n"
        "    lsls r2, r2, #1\n"
        "    adds r0, r6, r2\n"
        "    strh r1, [r0]\n"
        "    movs r0, #0xce\n"
        "    lsls r0, r0, #1\n"
        "    adds r1, r6, r0\n"
        "    movs r0, #0x10\n"
        "    strh r0, [r1]\n"
        "    movs r1, #0xcf\n"
        "    lsls r1, r1, #1\n"
        "    adds r0, r6, r1\n"
        "    strh r4, [r0]\n"
        "    ldr r1, .L0814891C\n"
        "    ldr r0, .L08148920\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L08148924\n"
        "    movs r0, #0x10\n"
        "    strh r0, [r1]\n"
        "    movs r0, #1\n"
        "    strh r0, [r6]\n"
        "    movs r0, #0\n"
        "    movs r2, #0xb4\n"
        "    adds r2, r2, r6\n"
        "    mov r8, r2\n"
        "    movs r1, #0xdc\n"
        "    adds r1, r1, r6\n"
        "    mov sb, r1\n"
        ".L0814885E:\n"
        "    movs r5, #0\n"
        "    adds r7, r0, #1\n"
        ".L08148862:\n"
        "    bl Random_Byte\n"
        "    movs r1, #0x3f\n"
        "    ands r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    movs r2, #0x81\n"
        "    lsls r2, r2, #1\n"
        "    adds r4, r6, r2\n"
        "    adds r1, r4, r0\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #0\n"
        "    bne .L08148862\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    adds r5, #1\n"
        "    cmp r5, #0xf\n"
        "    bls .L08148862\n"
        "    bl Keno_RecordHistory\n"
        "    movs r5, #0\n"
        "    movs r1, #0\n"
        "    adds r0, r4, #0\n"
        ".L0814888E:\n"
        "    strh r1, [r0]\n"
        "    adds r0, #2\n"
        "    adds r5, #1\n"
        "    cmp r5, #0x3f\n"
        "    bls .L0814888E\n"
        "    adds r0, r7, #0\n"
        "    cmp r0, #0xf\n"
        "    bls .L0814885E\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl sub_08148718\n"
        "    movs r0, #1\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl sub_08148718\n"
        "    movs r0, #2\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl sub_08148718\n"
        "    movs r0, #3\n"
        "    movs r1, #1\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl sub_08148718\n"
        "    movs r0, #4\n"
        "    movs r1, #1\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl sub_08148718\n"
        "    movs r0, #0x87\n"
        "    mov r1, r8\n"
        "    strh r0, [r1]\n"
        "    movs r0, #0xa0\n"
        "    mov r2, sb\n"
        "    strh r0, [r2]\n"
        "    bl sub_080C31F0\n"
        "    movs r2, #0xca\n"
        "    lsls r2, r2, #1\n"
        "    adds r1, r6, r2\n"
        "    str r0, [r1]\n"
        "    add sp, #8\n"
        "    pop {r3, r4}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L08148900: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L08148904: .4byte 0x05000200 @ PLTT+0x200\n"
        ".L08148908: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L0814890C: .4byte 0x85001000\n"
        ".L08148910: .4byte 0x00004008\n"
        ".L08148914: .4byte 0x03000002 @ IWRAM+0x2\n"
        ".L08148918: .4byte 0x03000000 @ IWRAM\n"
        ".L0814891C: .4byte 0x03000042 @ IWRAM+0x42\n"
        ".L08148920: .4byte 0x00000808\n"
        ".L08148924: .4byte 0x03000044 @ IWRAM+0x44\n"
    );
}
#endif

// Keno_CanStart @ 0x08148928
bool32 Keno_CanStart(void)
{
    struct C145Grid *s = gGrid;
    bool32 r;

    if (s->state != 2 && s->state != 3)
        return FALSE;
    r = FALSE;
    if (s->bet != 0 && s->marked != 0)
        r = TRUE;
    return r;
}
