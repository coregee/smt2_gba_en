#include "global.h"
#include "sceneeffect.h"

// sub_080BB964 @ 0x080BB964
void sub_080BB964(void)
{
    u16 *map = gUnk_02000000;
    s32 i;

    LZ77UnCompWram(gUnknown_08181238, (void *)0x02001000);
    LZ77UnCompWram(gUnknown_08181F84, map);
    for (i = 0; i < 0x800; i++, map++)
    {
        if (*map != 0)
        {
            u16 tile = *map + 0x300;

            *map = tile + 0x8000;
        }
    }
    gUnk_03000040 = 0;
    gUnk_03000006 = 8;
    gUnk_03000030 = 0xF0;
    gUnk_03000031 = 0;
    gUnk_03000034 = 0xE0;
    gUnk_03000035 = 0x68;
    gUnk_03000038 = 0x3D;
    if (Flag_Test(0xC6))
    {
        gUnk_03000034 = 0x68;
        gUnk_0300003B = 0;
    }
    VBlankTask_AddCounted(sub_080BB928, 1);
}

// sub_080BBA1C @ 0x080BBA1C
void sub_080BBA1C(void)
{
    DmaSet(3, 0x02005000, 0x06004000, 0x84001000);
    DmaSet(3, gUnk_02000000, 0x06003000, 0x84000400);
    REG_BG3CNT = 0x8607;
}

// sub_080BBA64 @ 0x080BBA64
#ifdef NONMATCHING
void sub_080BBA64(struct Task *task)
{
    u16 *d = task->data.h;
    u16 n = d[0];
    u16 y = d[1];
    u16 c = d[2];

    sub_080BB868(gUnknown_0818B2E0[n].gfx, gUnknown_0818B2E0[n].pals, &gAutomapCells[c * 0x400 + 0x20], &gUnk_02000000[y * 32]);
    if (d[0] != 0)
        d[0]--;
    d[2] = (d[2] - 1) & 0xF;
    d[1] = (d[1] - 1) & 0x3F;
}
#else
NAKED
void sub_080BBA64(struct Task *task)
{
    asm_unified(
        ".L080BBA64:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    adds r7, r0, #0\n"
        "    adds r6, r7, #0\n"
        "    adds r6, #0x24\n"
        "    ldrh r4, [r7, #0x24]\n"
        "    ldrh r5, [r6, #2]\n"
        "    ldrh r1, [r6, #4]\n"
        "    lsls r4, r4, #3\n"
        "    ldr r0, .L080BBAB4\n"
        "    adds r4, r4, r0\n"
        "    ldr r2, .L080BBAB8\n"
        "    ldr r3, .L080BBABC\n"
        "    lsls r1, r1, #0xa\n"
        "    adds r1, #0x20\n"
        "    adds r2, r1, r2\n"
        "    lsls r5, r5, #6\n"
        "    adds r3, r5, r3\n"
        "    ldr r0, [r4]\n"
        "    ldr r1, [r4, #4]\n"
        "    bl sub_080BB868\n"
        "    ldrh r0, [r7, #0x24]\n"
        "    cmp r0, #0\n"
        "    beq .L080BBA98\n"
        "    subs r0, #1\n"
        "    strh r0, [r7, #0x24]\n"
        ".L080BBA98:\n"
        "    ldrh r0, [r6, #4]\n"
        "    subs r0, #1\n"
        "    movs r1, #0xf\n"
        "    ands r0, r1\n"
        "    strh r0, [r6, #4]\n"
        "    ldrh r0, [r6, #2]\n"
        "    subs r0, #1\n"
        "    movs r1, #0x3f\n"
        "    ands r0, r1\n"
        "    strh r0, [r6, #2]\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080BBAB4: .4byte gUnknown_0818B2E0\n"
        ".L080BBAB8: .4byte 0x02005000 @ EWRAM+0x5000\n"
        ".L080BBABC: .4byte 0x02000000 @ EWRAM\n"
    );
}
#endif

// sub_080BBAC0 @ 0x080BBAC0
void sub_080BBAC0(struct Task *task)
{
    u16 *d = task->data.h;
    u32 zero1 = 0;
    u32 zero2;
    u16 i;

    CpuSet(&zero1, (void *)0x02005000, 0x05001000);
    zero2 = 0;
    CpuSet(&zero2, gUnk_02000000, 0x05000400);
    LZ77UnCompWram(gUnknown_08180BA0, gUnk_02000000);
    d[0] = 0x61;
    d[1] = 0x3F;
    d[2] = 0xF;
    for (i = 0; i < 16; i++)
        sub_080BBA64(task);
    gUnk_0300000E = 0x198;
    VBlankTask_AddCounted(sub_080BBA1C, 1);
    gUnk_0200AB04 |= 0x8000;
    gUnk_03004534 = 0x66;
    Palette_CopyWithEffect(3, gUnknown_08181138, &gPaletteTarget[0x80], 0x100, 0x20);
    gPaletteTarget[0] = 0;
    gPaletteBuffer[0] = 0;
    gUnk_0300452C = PalFade_FadeRangeInFromBlackTagged(0x80, 0x80, 1, 0x8001);
}

// sub_080BBBA4 @ 0x080BBBA4
void sub_080BBBA4(struct Task *task)
{
    u32 *d = task->data.w;
    u16 *d2;

    task->result = 0;
    gUnk_0300000E--;
    if ((s16)gUnk_03000006 > -0xA0)
        gUnk_03000006--;
    if (!(gUnk_0300000E & 7))
    {
        sub_080BBA64(task);
        VBlankTask_AddCounted(sub_080BBA1C, 1);
    }
    d2 = ((struct Task *)d[3])->data.h;
    if (d2[2] != 0x40)
        d2[2]++;
    if (task->data.h[0] == 0)
        task->result = 1;
}

// sub_080BBC10 @ 0x080BBC10
/* Every 8 frames toggles BG1/BG3 between their rest offsets and one pixel off (H: 0/-1,
   V: 8/7 and 0x198/0x197 in the shadows at 0x03000004..0x0300000E): a screen shake. */
void sub_080BBC10(struct Task *task)
{
    struct ShakeData *d = (struct ShakeData *)task->data.raw;

    if (!(gFrameCounter & 7))
    {
        if (d->shakeY == 0)
        {
            gUnk_0300000C = 0xFFFF;
            gUnk_03000004 = 0xFFFF;
            d->shakeY = -1;
        }
        else
        {
            gUnk_0300000C = 0;
            gUnk_03000004 = 0;
            d->shakeY = 0;
        }
        if (d->shakeX == 0)
        {
            gUnk_0300000E = 0x197;
            gUnk_03000006 = 7;
            d->shakeX = -1;
        }
        else
        {
            gUnk_0300000E = 0x198;
            gUnk_03000006 = 8;
            d->shakeX = 0;
        }
    }
}

// sub_080BBCB8 @ 0x080BBCB8
void sub_080BBCB8(struct Task *task)
{
    gUnk_0300000E = 0x198;
    gUnk_03000006 = 8;
    task->onFrame = NULL;
}

// sub_080BBCD8 @ 0x080BBCD8
void sub_080BBCD8(void)
{
    DmaSet(3, 0x02001000, 0x06013000, 0x84000D00);
}
