#include "global.h"
#include "sceneeffect.h"

// sub_080BA758 @ 0x080BA758
void sub_080BA758(void)
{
    DmaSetS(3, 0x0200AFC8, gUnk_03004638 * 0x20 + 0x06004000, 0x840000E0);
    DmaSet(3, gUnk_02000000, 0x06003800, 0x84000200);
}

// sub_080BA7A0 @ 0x080BA7A0
void sub_080BA7A0(u32 which)
{
    if (which == 0)
        LZ77UnCompWram(gUnknown_08182270, gUnk_02000000);
    else
        LZ77UnCompWram(gUnknown_08182688, gUnk_02000000);
}

// sub_080BA7CC @ 0x080BA7CC
#ifdef NONMATCHING
void sub_080BA7CC(const void *const *srcs, const u8 *rows, u32 width, s32 row, s32 mirror)
{
    u32 scroll;
    u16 idx;
    u16 *map;
    const void *src;
    const u8 *p;
    u32 i;
    u32 y;

    scroll = (u16)-gUnk_0300000E >> 3;
    idx = row - scroll - 1;
    map = gUnk_02000000;
    if ((s16)idx < 0)
        idx = 0;
    src = srcs[idx];
    p = rows + idx * width;
    LZ77UnCompWram(src, (void *)0x0200AFC8);
    y = 0x1F - scroll;
    if (mirror == 0)
    {
        for (i = 0; i < width; i++)
            map[y * 32 + 1 + i] += ((*p++ & 0xF) + 8) << 12;
    }
    else
    {
        for (i = 0; i < width; i++)
        {
            u32 v = ((*p++ & 0xF) + 8) << 12;

            map[y * 32 + 1 + i] = (map[y * 32 + 1 + i] & 0xFFF) + v;
            map[y * 32 + 0x1C - i] = (map[y * 32 + 0x1C - i] & 0xFFF) + v;
        }
    }
    gUnk_03004638 = gUnknown_08182AA0[0x1F - scroll];
    VBlankTask_AddCounted(sub_080BA758, 1);
}
#else
NAKED
void sub_080BA7CC(const void *const *srcs, const u8 *rows, u32 width, s32 row, s32 mirror)
{
    asm_unified(
        ".L080BA7CC:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    adds r5, r0, #0\n"
        "    adds r6, r1, #0\n"
        "    adds r7, r2, #0\n"
        "    ldr r0, .L080BA844\n"
        "    ldrh r0, [r0]\n"
        "    rsbs r0, r0, #0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x13\n"
        "    subs r3, r3, r4\n"
        "    subs r3, #1\n"
        "    lsls r3, r3, #0x10\n"
        "    ldr r0, .L080BA848\n"
        "    mov r8, r0\n"
        "    lsrs r1, r3, #0x10\n"
        "    cmp r3, #0\n"
        "    bge .L080BA7F8\n"
        "    movs r1, #0\n"
        ".L080BA7F8:\n"
        "    lsls r0, r1, #2\n"
        "    adds r0, r0, r5\n"
        "    ldr r0, [r0]\n"
        "    muls r1, r7, r1\n"
        "    adds r5, r6, r1\n"
        "    ldr r1, .L080BA84C\n"
        "    bl LZ77UnCompWram\n"
        "    movs r0, #0x1f\n"
        "    subs r1, r0, r4\n"
        "    ldr r0, [sp, #0x20]\n"
        "    cmp r0, #0\n"
        "    bne .L080BA854\n"
        "    movs r6, #0\n"
        "    mov sb, r4\n"
        "    ldr r3, .L080BA850\n"
        "    mov sl, r3\n"
        "    cmp r6, r7\n"
        "    bhs .L080BA8A0\n"
        "    movs r2, #0xf\n"
        "    lsls r1, r1, #6\n"
        "    mov r0, r8\n"
        "    adds r0, #2\n"
        "    adds r1, r1, r0\n"
        ".L080BA828:\n"
        "    ldrb r0, [r5]\n"
        "    adds r5, #1\n"
        "    ands r0, r2\n"
        "    adds r0, #8\n"
        "    lsls r0, r0, #0xc\n"
        "    ldrh r3, [r1]\n"
        "    adds r0, r0, r3\n"
        "    strh r0, [r1]\n"
        "    adds r1, #2\n"
        "    adds r6, #1\n"
        "    cmp r6, r7\n"
        "    blo .L080BA828\n"
        "    b .L080BA8A0\n"
        "    .byte 0x00, 0x00\n"
        ".L080BA844: .4byte 0x0300000E @ IWRAM+0xE\n"
        ".L080BA848: .4byte 0x02000000 @ EWRAM\n"
        ".L080BA84C: .4byte 0x0200AFC8 @ EWRAM+0xAFC8\n"
        ".L080BA850: .4byte sub_080BA758\n"
        ".L080BA854:\n"
        "    movs r6, #0\n"
        "    mov sb, r4\n"
        "    ldr r0, .L080BA8C8\n"
        "    mov sl, r0\n"
        "    cmp r6, r7\n"
        "    bhs .L080BA8A0\n"
        "    ldr r3, .L080BA8CC\n"
        "    mov ip, r3\n"
        "    lsls r0, r1, #5\n"
        "    adds r0, #0x1c\n"
        "    lsls r2, r1, #6\n"
        "    mov r1, r8\n"
        "    adds r1, #2\n"
        "    adds r4, r2, r1\n"
        "    lsls r0, r0, #1\n"
        "    mov r1, r8\n"
        "    adds r3, r0, r1\n"
        ".L080BA876:\n"
        "    ldrb r1, [r5]\n"
        "    adds r5, #1\n"
        "    movs r0, #0xf\n"
        "    ands r1, r0\n"
        "    adds r1, #8\n"
        "    ldrh r2, [r4]\n"
        "    mov r0, ip\n"
        "    ands r0, r2\n"
        "    lsls r1, r1, #0xc\n"
        "    adds r0, r0, r1\n"
        "    strh r0, [r4]\n"
        "    ldrh r2, [r3]\n"
        "    mov r0, ip\n"
        "    ands r0, r2\n"
        "    adds r0, r0, r1\n"
        "    strh r0, [r3]\n"
        "    subs r3, #2\n"
        "    adds r4, #2\n"
        "    adds r6, #1\n"
        "    cmp r6, r7\n"
        "    blo .L080BA876\n"
        ".L080BA8A0:\n"
        "    movs r0, #0x1f\n"
        "    mov r3, sb\n"
        "    subs r0, r0, r3\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L080BA8D0\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    ldr r3, .L080BA8D4\n"
        "    str r0, [r3]\n"
        "    mov r0, sl\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080BA8C8: .4byte sub_080BA758\n"
        ".L080BA8CC: .4byte 0x00000FFF\n"
        ".L080BA8D0: .4byte gUnknown_08182AA0\n"
        ".L080BA8D4: .4byte 0x03004638 @ IWRAM+0x4638\n"
    );
}
#endif

// SceneEffect_Start @ 0x080BA8D8
void SceneEffect_Start(u16 set, u16 id)
{
    const void *script;

    if (set == 0)
        script = gUnknown_08182B20[id];
    else
        script = gUnknown_08182B54[id];
    if (script != NULL)
        gSceneEffectTask = Task_Create(script, 0xFFFF);
    else
        gSceneEffectTask = (struct Task *)script;
}

// SceneEffect_IsDone @ 0x080BA920
s32 SceneEffect_IsDone(void)
{
    s32 done = 0;

    if (gSceneEffectTask == NULL || gSceneEffectTask->state == 0)
        done = 1;
    return done;
}

// SceneEffect_Stop @ 0x080BA940
void SceneEffect_Stop(void)
{
    if (gSceneEffectTask != NULL)
    {
        gSceneEffectTask->state = 0;
        gSceneEffectTask = NULL;
    }
}

// SceneEffect_End @ 0x080BA958
void SceneEffect_End(u16 set, u16 id)
{
    if (set == 0 && id == 2)
    {
        struct Task *t;

        if (!(gUnk_0200AB04 & 0x8000))
            VBlankTask_AddCounted(sub_080B2880, 1);
        t = gSceneEffectTask;
        gUnk_0300000E = t->data.h[0];
    }
    SceneEffect_Stop();
}

// sub_080BA9A0 @ 0x080BA9A0
void sub_080BA9A0(struct Task *task)
{
    task->data.w[0] = BgPicture_StartTask(0x1C);
}

// sub_080BA9B4 @ 0x080BA9B4
void sub_080BA9B4(struct Task *task)
{
    if (*(u16 *)task->data.w[0] != 0)
        task->result = 0;
    else
        task->result = 1;
}

// sub_080BA9CC @ 0x080BA9CC
void sub_080BA9CC(void)
{
    DmaSet(3, 0x02001000, 0x0600E000, 0x84000300);
}

// sub_080BA9F0 @ 0x080BA9F0
void sub_080BA9F0(struct Task *task)
{
    LZ77UnCompWram(gUnknown_08182F4C, (void *)0x02001000);
    VBlankTask_AddCounted(sub_080BA9CC, 1);
}

// sub_080BAA14 @ 0x080BAA14
void sub_080BAA14(struct Task *task)
{
    LZ77UnCompWram(gUnknown_081831B4, (void *)0x02001000);
    VBlankTask_AddCounted(sub_080BA9CC, 1);
}

// sub_080BAA38 @ 0x080BAA38
void sub_080BAA38(void)
{
    DmaSet(3, gUnk_02000000, 0x06001000, 0x84000400);
}

// sub_080BAA5C @ 0x080BAA5C
void sub_080BAA5C(void)
{
    u32 zero = 0;

    CpuSet(&zero, gUnk_02000000, 0x05000400);
    VBlankTask_AddCounted(sub_080BAA38, 1);
    gUnk_03000038 = 0x3F;
    gUnk_03000039 = 0x3F;
    gUnk_0300003A = 0x3F;
    gUnk_03000006 = 0;
}

// sub_080BAAAC @ 0x080BAAAC
void sub_080BAAAC(void)
{
    LZ77UnCompWram(gUnknown_08183474, (void *)0x0200BFC8);
    Tilemap_CopyRectSkipZero((void *)0x0200BFC8, gUnk_02000000, 0x300, 7, 0, 0, 0x20, 0x40);
    Palette_CopyWithEffect(3, gUnknown_08183454, &gPaletteTarget[0x70], 0x20, 0x20);
    PalFade_FadeRangeInFromBlackTagged(0x70, 0x10, 1, 1);
    VBlankTask_AddCounted(sub_080BAA38, 1);
    gUnk_03000006 = 0x78;
    gUnk_03000030 = 0xE8;
    gUnk_03000031 = 8;
    gUnk_03000034 = 0xE0;
    gUnk_03000035 = 0x68;
    gUnk_03000038 = 0x3D;
}

// sub_080BAB54 @ 0x080BAB54
void sub_080BAB54(struct Task *task, u32 delta)
{
    gUnk_03000006 += delta;
    if (!((gFrameCounter >> 3) & 1))
        sub_080BA9F0(task);
    else
        sub_080BAA14(task);
}

// sub_080BAB8C @ 0x080BAB8C
void sub_080BAB8C(struct Task *task, u32 value)
{
    gUnk_03000006 = value;
}

// sub_080BAB98 @ 0x080BAB98
void sub_080BAB98(void)
{
    DmaSet(3, 0x02001000, 0x06015000, 0x84000200);
}

// sub_080BABBC @ 0x080BABBC
void sub_080BABBC(struct Task *task)
{
    u16 *d = task->data.h;

    LZ77UnCompWram(gUnknown_08182CC4, (void *)0x02001000);
    VBlankTask_AddCounted(sub_080BAB98, 1);
    Palette_CopyWithEffect(3, gUnknown_08183434, &gPaletteTarget[0x1D0], 0x20, 0x20);
    PalFade_FadeRangeInFromBlackTagged(0x1D0, 0x10, 1, 1);
    VBlankTask_AddCounted(sub_080BAB98, 1);
    d[2] = 0x30;
}

// sub_080BAC1C @ 0x080BAC1C
void sub_080BAC1C(struct Task *task)
{
    u16 *d = task->data.h;

    if (!((gFrameCounter >> 3) & 1))
    {
        Sprite_Draw(gUnknown_0800781C, 0, 0xD, 3, 0x280, 0x40, d[2]);
        Sprite_Draw(gUnknown_0800781C, 0, 0xD, 3, 0x280, 0xB4, d[2] + 0x20);
    }
    else
    {
        Sprite_Draw(gUnknown_08007844, 0, 0xD, 3, 0x280, 0x40, d[2]);
        Sprite_Draw(gUnknown_08007844, 0, 0xD, 3, 0x280, 0xB4, d[2] + 0x20);
    }
}

// sub_080BACB8 @ 0x080BACB8
void sub_080BACB8(struct Task *task, u32 delta)
{
    u16 *d = task->data.h;

    d[2] += delta;
}

// sub_080BACC4 @ 0x080BACC4
void sub_080BACC4(void)
{
    REG_BG1CNT = 0x4209;
}

// sub_080BACD8 @ 0x080BACD8
void sub_080BACD8(void)
{
    gUnk_03000030 = 8;
    gUnk_03000031 = 0;
    gUnk_03000034 = 0x68;
    gUnk_03000035 = 0;
    gUnk_03000038 = 0x3D;
    VBlankTask_AddCounted(sub_080BACC4, 1);
    gUnk_03000004++;
}

// sub_080BAD28 @ 0x080BAD28
void sub_080BAD28(void)
{
    DMA_FILL32(3, 0, 0x06001000, 0x800);
    REG_BG1CNT = 0x8209;
}

// sub_080BAD5C @ 0x080BAD5C
void sub_080BAD5C(struct Task *task, u32 close)
{
    if (close == 0)
    {
        VBlankTask_AddCounted(sub_080BAD28, 1);
    }
    else
    {
        gUnk_03000004 = 0;
        gUnk_03000038 = 0x3F;
    }
}

// sub_080BAD88 @ 0x080BAD88
void sub_080BAD88(struct Task *task, u32 id, u32 dx, u32 dy)
{
    u32 i;

    for (i = 0; i < 8; i++)
    {
        struct Task *t = gCharTasks[i];

        if (t != NULL)
        {
            u16 *d = t->data.h;

            if (d[3] == id)
            {
                d[4] += dx;
                d[5] += dy;
            }
        }
    }
}

// sub_080BADC4 @ 0x080BADC4
void sub_080BADC4(void)
{
    u32 i;

    for (i = 0; i < 8; i++)
    {
        struct Task *t = gCharTasks[i];

        if (t != NULL && t->data.h[3] == 0x157)
            sub_080C48F0(t, 0);
    }
}

// sub_080BADF8 @ 0x080BADF8
void sub_080BADF8(struct Task *task, u32 value)
{
    if (gCharTasks[0] != NULL)
        gCharTasks[0]->pad1E = value;
}

// sub_080BAE0C @ 0x080BAE0C
void sub_080BAE0C(struct Task *task)
{
    if (gCharTasks[0] == NULL)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080BAE28 @ 0x080BAE28
void sub_080BAE28(void)
{
    Window_Close(gMsgWindow, 1);
    gMsgWindow = NULL;
    gMsgWindowOpen = 0;
}

// sub_080BAE4C @ 0x080BAE4C
void sub_080BAE4C(struct Task *task, u32 id)
{
    task->data.w[0] = BgPicture_StartTask(id);
}

// sub_080BAE60 @ 0x080BAE60
void sub_080BAE60(struct Task *task)
{
    if (*(u16 *)task->data.w[0] != 0)
        task->result = 0;
    else
        task->result = 1;
}

// sub_080BAE78 @ 0x080BAE78
void sub_080BAE78(struct Task *task, u16 a, u16 b, u16 c, u16 d)
{
    sub_080C4618(a, b, c, d, 0, 0);
}
