#include "global.h"
#include "fusion.h"

/* Starts the fusion room task: kind 0 normal, 1 the four-demon special, 2 none, else two-way. */
// sub_08157EB0 @ 0x08157EB0
struct Task *sub_08157EB0(u16 kind, u32 a1, struct FadeTask *fade)
{
    struct FusionRoom *r = &sRoom;
    struct Task *task;
    u32 zero = 0;

    CpuSet(&zero, r, 0x05000200);
    if (kind == 0)
    {
        task = Task_Create(gUnknown_087F0308, 0xFFFF);
    }
    else if (kind == 1)
    {
        task = Task_Create(gUnknown_087F106C, 0xFFFF);
        gUnk_0203B854[0] = 0x13C;
        gUnk_0203B854[1] = 0x13F;
        gUnk_0203B854[2] = 0x13B;
        gUnk_0203B854[3] = 0x13E;
        gUnk_0203B854[4] = 3;
    }
    else if (kind != 2)
    {
        task = Task_Create(gUnknown_087F06D8, 0xFFFF);
        gUnk_0203B854[4] = 2;
    }
    r->unk0 = kind;
    r->unkC = a1;
    r->fade = fade;
    return task;
}

// sub_08157F5C @ 0x08157F5C
void sub_08157F5C(void)
{
    DmaSet3(gUnk_02005800, 0x06006920, 0x84000200);
    DmaSet3(gUnk_02000000, 0x06003000, 0x84000200);
}

/* Room animation frame: new tiles, and the 12x4 map patch gives each tile its palette line. */
// sub_08157F94 @ 0x08157F94
#ifdef NONMATCHING
void sub_08157F94(u32 a0, u32 frame)
{
    const u32 *entry = (const u32 *)sRoom.anim + frame * 2;
    const u8 *patch;
    u16 row;
    u16 col;

    LZ77UnCompWram((const void *)entry[0], gUnk_02005800);
    patch = (const u8 *)entry[1];
    sub_081574D0();
    for (row = 0; row < 4; row++)
    {
        for (col = 0; col < 12; col++)
        {
            u16 *p = &((u16 (*)[32])gUnk_02000000)[row][col + 0x189];

            *p = (*p & 0xFFF) | (((*patch++ & 0xF) + 6) << 12);
        }
    }
    VBlankTask_AddCounted(sub_08157F5C, 1);
}
#else
NAKED
void sub_08157F94(u32 a0, u32 frame)
{
    asm_unified(
        ".L08157F94:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    adds r4, r1, #0\n"
        "    ldr r0, .L08158018\n"
        "    ldr r0, [r0, #8]\n"
        "    lsls r4, r4, #3\n"
        "    adds r4, r4, r0\n"
        "    ldr r0, [r4]\n"
        "    ldr r1, .L0815801C\n"
        "    bl LZ77UnCompWram\n"
        "    ldr r5, [r4, #4]\n"
        "    bl sub_081574D0\n"
        "    ldr r0, .L08158020\n"
        "    mov sb, r0\n"
        "    movs r0, #0\n"
        "    ldr r1, .L08158024\n"
        "    mov sl, r1\n"
        "    ldr r1, .L08158028\n"
        "    mov r8, r1\n"
        "    ldr r1, .L0815802C\n"
        "    mov ip, r1\n"
        ".L08157FC8:\n"
        "    movs r4, #0\n"
        "    adds r7, r0, #1\n"
        "    lsls r6, r0, #5\n"
        ".L08157FCE:\n"
        "    mov r0, ip\n"
        "    adds r2, r4, r0\n"
        "    adds r2, r6, r2\n"
        "    lsls r2, r2, #1\n"
        "    add r2, sb\n"
        "    ldrb r1, [r5]\n"
        "    adds r5, #1\n"
        "    movs r0, #0xf\n"
        "    ands r1, r0\n"
        "    adds r1, #6\n"
        "    ldrh r3, [r2]\n"
        "    mov r0, r8\n"
        "    ands r0, r3\n"
        "    lsls r1, r1, #0xc\n"
        "    orrs r0, r1\n"
        "    strh r0, [r2]\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #0xb\n"
        "    bls .L08157FCE\n"
        "    lsls r0, r7, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #3\n"
        "    bls .L08157FC8\n"
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
        "    .byte 0x00, 0x00\n"
        ".L08158018: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L0815801C: .4byte 0x02005800 @ EWRAM+0x5800\n"
        ".L08158020: .4byte 0x02000000 @ EWRAM\n"
        ".L08158024: .4byte sub_08157F5C\n"
        ".L08158028: .4byte 0x00000FFF\n"
        ".L0815802C: .4byte 0x00000189\n"
    );
}
#endif

/* Alignment of the result: 0 law, 1 neutral, 2 chaos, 3 other (items by their flags). */
// sub_08158030 @ 0x08158030
#ifdef NONMATCHING
u32 sub_08158030(void)
{
    if (gUnk_0203B854[4] == 2 || gUnk_0203B854[4] == 3)
    {
        u16 id = gUnk_0203B854[3];

        if (id == 0x13E)
            return 1;
        switch (0xFF & sub_0815B958(id))
        {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        }
    }
    else
    {
        u8 flags = *Item_GetRecord(Fusion_GetDemonByIndex(gUnk_0203B854[3]));

        if ((flags & 7) == 7)
            return 0;
        if (flags & 1)
            return 0;
        if (flags & 2)
            return 1;
        return 2;
    }
    return 3;
}
#else
NAKED
u32 sub_08158030(void)
{
    asm_unified(
        ".L08158030:\n"
        "    push {lr}\n"
        "    ldr r1, .L08158064\n"
        "    ldrh r0, [r1, #8]\n"
        "    subs r0, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bhi .L08158070\n"
        "    ldrh r1, [r1, #6]\n"
        "    movs r0, #0x9f\n"
        "    lsls r0, r0, #1\n"
        "    cmp r1, r0\n"
        "    beq .L081580A0\n"
        "    adds r0, r1, #0\n"
        "    bl sub_0815B958\n"
        "    movs r1, #0xff\n"
        "    ands r1, r0\n"
        "    cmp r1, #1\n"
        "    beq .L081580A0\n"
        "    cmp r1, #1\n"
        "    bgt .L08158068\n"
        "    cmp r1, #0\n"
        "    beq .L08158090\n"
        "    b .L0815806C\n"
        "    .byte 0x00, 0x00\n"
        ".L08158064: .4byte 0x0203B854 @ EWRAM+0x3B854\n"
        ".L08158068:\n"
        "    cmp r1, #2\n"
        "    beq .L0815809C\n"
        ".L0815806C:\n"
        "    movs r0, #3\n"
        "    b .L081580A2\n"
        ".L08158070:\n"
        "    ldrh r0, [r1, #6]\n"
        "    bl Fusion_GetDemonByIndex\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Item_GetRecord\n"
        "    ldrb r1, [r0]\n"
        "    movs r0, #7\n"
        "    ands r0, r1\n"
        "    cmp r0, #7\n"
        "    beq .L08158090\n"
        "    movs r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08158094\n"
        ".L08158090:\n"
        "    movs r0, #0\n"
        "    b .L081580A2\n"
        ".L08158094:\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L081580A0\n"
        ".L0815809C:\n"
        "    movs r0, #2\n"
        "    b .L081580A2\n"
        ".L081580A0:\n"
        "    movs r0, #1\n"
        ".L081580A2:\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// sub_081580A8 @ 0x081580A8
void sub_081580A8(void)
{
    DmaSet3(gUnk_02001000, 0x06013800, 0x84000900);
}

// Fusion_LoadEffectPart @ 0x081580CC
void Fusion_LoadEffectPart(u32 a0, u32 part)
{
    struct FusionRoom *r = &sRoom;
    const struct FusionEffectSet *sets = gFusionEffectSets;

    HuffUnComp(((const void *const *)sets)[sub_08158030() * 4 + part], gBgPictureBuffer);
    LZ77UnCompWram(gBgPictureBuffer, (void *)(0x02001000 + (part << 12)));
    if (part == 2)
    {
        Palette_CopyWithEffect(3, sets[sub_08158030()].pal, &gPaletteBuffer[0x1D0], 0x20, 0x20);
        Palette_MarkDirty();
        VBlankTask_AddCounted(sub_081580A8, 1);
        r->effectTimer = sub_0815814C()->duration;
    }
}

/* Current frame of the fusion effect of the result's alignment. */
// sub_0815814C @ 0x0815814C
const struct EffectFrame *sub_0815814C(void)
{
    struct FusionRoom *r = &sRoom;

    switch (sub_08158030())
    {
    case 0:
        return &gUnknown_087F09E4[r->effectStep];
    case 1:
        return &gUnknown_087F0A9C[r->effectStep];
    case 2:
        return &gUnknown_087F0B6C[r->effectStep];
    case 3:
        return &gUnknown_087F0994[r->effectStep];
    }
}

// sub_081581C0 @ 0x081581C0
void sub_081581C0(void)
{
    const struct EffectFrame *e = sub_0815814C();

    switch (sub_08158030())
    {
    case 1:
        Sprite_Draw(e->sprite, 0, 0xD, 0, 0x1C0, 0x78, 0x20);
        break;
    case 0:
        Sprite_Draw(e->sprite, 0, 0xD, 0, 0x1C0, 0x78, 0x20);
        break;
    case 2:
        Sprite_Draw(e->sprite, 0, 0xD, 0, 0x1C0, 0x78, 0x20);
        break;
    case 3:
        Sprite_Draw(e->sprite, 0, 0xD, 0, 0x1C0, 0x54, 0x58);
        break;
    }
}

// sub_08158220 @ 0x08158220
void sub_08158220(struct Task *task)
{
    struct FusionRoom *r = &sRoom;
    const struct EffectFrame *e;

    task->result = 0;
    if (--r->effectTimer == 0)
    {
        r->effectStep++;
        e = sub_0815814C();
        r->effectTimer = e->duration;
        if (e->sprite == NULL)
        {
            r->effectStep--;
            task->result = 1;
        }
    }
}

// sub_08158268 @ 0x08158268
void sub_08158268(u32 a0)
{
    struct FusionRoom *r = &sRoom;

    if (!(gFrameCounter & 3))
    {
        if (r->unk78 == 0)
        {
            sub_08157F94(a0, 5);
        }
        else
        {
            sub_08157F94(a0, 0);
            Sound_Play(0x153);
        }
        r->unk78 = (r->unk78 + 1) & 1;
    }
}

// sub_081582BC @ 0x081582BC
void sub_081582BC(void)
{
    DmaSet3(gUnk_02008000, 0x06013800, 0x84000200);
}

/* Next frame of the capsule mist (palette loaded with the first). */
// Fusion_LoadMistFrame @ 0x081582E0
void Fusion_LoadMistFrame(void)
{
    struct FusionRoom *r = &sRoom;

    HuffUnComp(gFusionMistFrames[r->unk30], gBgPictureBuffer);
    LZ77UnCompWram(gBgPictureBuffer, gUnk_02008000);
    VBlankTask_AddCounted(sub_081582BC, 1);
    if (r->unk30 == 0)
    {
        Palette_CopyWithEffect(3, gUnknown_087F012C, &gPaletteBuffer[0x1C0], 0x20, 0x20);
        Palette_MarkDirty();
    }
    r->unk30++;
}

// sub_0815834C @ 0x0815834C
void sub_0815834C(void)
{
    u16 x;
    u16 y;

    switch (sRoom.unk32)
    {
    case 0:
        x = 0x1C;
        y = 0x45;
        break;
    case 1:
        x = 0xA5;
        y = 0x45;
        break;
    case 2:
        x = 0x60;
        y = 0x10;
        break;
    }
    Sprite_Draw(gUnknown_08002134, 1, 0xC, 2, 0x1C0, x, y);
}

/* k == 0: pauses the hidden field character and closes the message window; else restores. */
// sub_081583A0 @ 0x081583A0
void sub_081583A0(u32 a0, u32 k)
{
    struct FusionRoom *r = &sRoom;

    if (k == 0)
    {
        struct Task *t = r->savedTask;

        r->savedOnFrame = t->onFrame;
        t->onFrame = NULL;
        Window_Close((void *)gMsgWindow, 1);
    }
    else
    {
        gCharTasks[0]->onFrame = r->savedOnFrame;
        gMsgWindow = Window_Create(2, 0xB, 0x1A, 8, 0);
    }
}
