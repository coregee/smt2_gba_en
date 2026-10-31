/* Field task callbacks: turning on spinners, location name banner, screen save/restore around
   pictures. */

#include "global.h"
#include "fieldevent.h"

// sub_080B6170 @ 0x080B6170
/* Direction the player was pushed this step (record 0x28 or the last move), 0xFFFF if none
   or already facing it. */
u16 sub_080B6170(void)
{
    u16 x = gFieldState.unk12;
    u16 y = gFieldState.unk14;
    u16 px = gFieldState.unk16;
    u16 py = gFieldState.unk18;
    u16 dir = 0xFFFF;
    u16 *rec = FieldMap_FindRecord(FieldMap_CellRecordsRel(0, 0), 0x28);

    if (rec != NULL)
        dir = rec[1];
    else if (x == px && y < py)
        dir = 0;
    else if (x == px && y > py)
        dir = 2;
    else if (x < px && y == py)
        dir = 3;
    else if (x > px && y == py)
        dir = 1;

    if (gFieldState.unk02 == dir)
        return 0xFFFF;
    return dir;
}

// sub_080B61F0 @ 0x080B61F0
void sub_080B61F0(struct Task *task, u32 arg)
{
    task->result = 1;
    if (arg == 0)
    {
        u16 dir = sub_080B6170();

        if (dir != 0xFFFF)
        {
            sub_080B2064(dir, gUnknown_08163258[gFieldState.unk02][dir]);
            task->result = 0;
        }
    }
    else if (gFieldState.unk02 != gFieldState.unk06)
    {
        sub_080B2064(gFieldState.unk06, gFieldState.unk08);
        task->result = 0;
    }
    else
    {
        task->result = 1;
    }
}

// sub_080B6250 @ 0x080B6250
void sub_080B6250(struct Task *task)
{
    s32 r = sub_080B2090();

    task->result = 0;
    if (r != -1)
        task->result = 1;
}

// sub_080B626C @ 0x080B626C
void sub_080B626C(void)
{
    Field_SetState(0x13);
    sub_080C7218();
    sub_080C7414();
    gFieldState.unk1E = 0;
}

// sub_080B628C @ 0x080B628C
void sub_080B628C(void)
{
    gUnk_03003FEC = Task_Create(gUnknown_0816336C, 0xFFFF);
    Field_SetState(0x1A);
}

// sub_080B62B0 @ 0x080B62B0
void sub_080B62B0(struct Task *task)
{
    struct EventTaskData *d = (struct EventTaskData *)task->data;
    u32 zero;

    sub_080C7218();
    sub_080C7414();
    gFieldState.unk1E = 0;
    gUnk_03004530 = d->arg;
    zero = 0;
    CpuSet(&zero, (void *)0x02036094, 0x05000008);
    gUnk_0203DB7A = 0;
    sub_080AF060(d->script);
    Field_SetState(0x19);
}

// sub_080B6308 @ 0x080B6308
void sub_080B6308(u16 arg, const void *script)
{
    struct Task *task = Task_Create(gUnknown_081633D8, 0xFFFF);
    struct EventTaskData *d;

    gUnk_03003FEC = task;
    d = (struct EventTaskData *)task->data;
    d->arg = arg;
    d->script = script;
    Field_SetState(0x1A);
}

// sub_080B633C @ 0x080B633C
void sub_080B633C(void)
{
}

// sub_080B6340 @ 0x080B6340
void sub_080B6340(void)
{
    DmaCopy32(3, gBannerTiles, (void *)0x06012F00, 0x100);
}

// LocationBanner_BuildTiles @ 0x080B6364
/* Builds the location banner: one 8x8 tile per character of gUnknown_08163444[index]
   (A-Z and a few signs, ended by a space) into gBannerTiles. Only 0x100 bytes (8 tiles)
   are uploaded by sub_080B6340; a longer name runs over gUnk_0203A3E4. */
void LocationBanner_BuildTiles(struct Task *task)
{
    struct BannerData *d = (struct BannerData *)task->data;
    const u8 *s = gUnknown_08163444[d->index];
    u32 *dst = (u32 *)gBannerTiles;

    while (*s != ' ')
    {
        const u32 *src;
        u8 c = *s;

        if (c == '(')
            src = (const u32 *)gUnknown_081AE018;
        else if (c == ')')
            src = (const u32 *)(gUnknown_081AE018 + 0x20);
        else if (c == 0x27)     /* ' */
            src = (const u32 *)(gUnknown_081AE018 - 0x1E0);
        else if (c == '&')
            src = (const u32 *)(gUnknown_081AE018 - 0x7E0);
        else if (c == '_')
            src = (const u32 *)(gUnknown_081AE018 - 0x860);
        else
            src = (const u32 *)(gUnknown_081AE018 - 0x580 + (c - 'A') * 32);
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
        s++;
    }
    Tilemap_CopyRectSkipZero(gUnknown_081635B6, gWindowTilemapBuffer, 0, 0, 10, 2, 10, 2);
    VBlankTask_AddCounted(sub_080B6340, 1);
    sub_080C6764();
}

// LocationBanner_Update @ 0x080B6460
/* Reveals the banner name one letter every 4 frames as sprites, centred for 8 letters. */
#ifdef NONMATCHING
void LocationBanner_Update(struct Task *task)
{
    struct BannerData *d = (struct BannerData *)task->data;
    const u8 *s = gUnknown_08163444[d->index];
    u32 i; /* first the name length, then the letter index */
    u32 x;

    if (--d->timer == 0)
    {
        d->timer = 4;
        if (d->shown != 10)
            d->shown++;
    }
    for (i = 0; *s != ' '; s++)
        i++;
    x = ((8 - i) * 8 >> 1) + 0x57;
    s = gUnknown_08163444[d->index];
    for (i = 0; i < d->shown && *s != ' '; i++, s++)
        Sprite_DrawSingle(gUnknown_08163638, 0, 0, 0, i, x + i * 8, 0x15);
    if (gFieldState.unk00 == 1)
        task->result = 0;
    else
        task->result = 1;
}
#else
NAKED
void LocationBanner_Update(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    sub sp, #0xc\n"
        "    mov r8, r0\n"
        "    mov r7, r8\n"
        "    adds r7, #0x24\n"
        "    ldrh r1, [r0, #0x24]\n"
        "    lsls r0, r1, #2\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    ldr r1, .L080B6508\n"
        "    adds r4, r0, r1\n"
        "    ldrh r0, [r7, #4]\n"
        "    subs r0, #1\n"
        "    strh r0, [r7, #4]\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080B6494\n"
        "    movs r0, #4\n"
        "    strh r0, [r7, #4]\n"
        "    ldrh r0, [r7, #2]\n"
        "    cmp r0, #0xa\n"
        "    beq .L080B6494\n"
        "    adds r0, #1\n"
        "    strh r0, [r7, #2]\n"
        ".L080B6494:\n"
        "    movs r5, #0\n"
        "    ldrb r0, [r4]\n"
        "    ldrh r2, [r7]\n"
        "    ldrh r6, [r7, #2]\n"
        "    cmp r0, #0x20\n"
        "    beq .L080B64AA\n"
        ".L080B64A0:\n"
        "    adds r5, #1\n"
        "    adds r4, #1\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #0x20\n"
        "    bne .L080B64A0\n"
        ".L080B64AA:\n"
        "    movs r0, #8\n"
        "    subs r0, r0, r5\n"
        "    lsls r0, r0, #3\n"
        "    lsrs r0, r0, #1\n"
        "    adds r3, r0, #0\n"
        "    adds r3, #0x57\n"
        "    lsls r0, r2, #2\n"
        "    adds r0, r0, r2\n"
        "    lsls r0, r0, #1\n"
        "    adds r4, r0, r1\n"
        "    movs r5, #0\n"
        "    cmp r5, r6\n"
        "    bhs .L080B64FA\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #0x20\n"
        "    beq .L080B64FA\n"
        "    adds r6, r3, #0\n"
        ".L080B64CC:\n"
        "    lsls r0, r5, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp]\n"
        "    lsls r0, r6, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #0x15\n"
        "    str r0, [sp, #8]\n"
        "    ldr r0, .L080B650C\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_DrawSingle\n"
        "    adds r6, #8\n"
        "    adds r5, #1\n"
        "    adds r4, #1\n"
        "    ldrh r1, [r7, #2]\n"
        "    cmp r5, r1\n"
        "    bhs .L080B64FA\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #0x20\n"
        "    bne .L080B64CC\n"
        ".L080B64FA:\n"
        "    ldr r0, .L080B6510\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #1\n"
        "    bne .L080B6514\n"
        "    movs r0, #0\n"
        "    b .L080B6516\n"
        "    .byte 0x00, 0x00\n"
        ".L080B6508: .4byte gUnknown_08163444\n"
        ".L080B650C: .4byte gUnknown_08163638\n"
        ".L080B6510: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B6514:\n"
        "    movs r0, #1\n"
        ".L080B6516:\n"
        "    mov r1, r8\n"
        "    strh r0, [r1, #0x1c]\n"
        "    add sp, #0xc\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// sub_080B6528 @ 0x080B6528
void sub_080B6528(struct Task *task)
{
    u16 r = gFieldState.unk00;

    if (r != 1)
        r = 0;
    task->result = r;
}

// sub_080B6540 @ 0x080B6540
void sub_080B6540(void)
{
    Tilemap_FillRect(0, gWindowTilemapBuffer, 10, 2, 10, 2);
    sub_080C6764();
}

// LocationBanner_Start @ 0x080B6568
/* Starts the location name banner for entry `index` ('?' entries have none). */
void LocationBanner_Start(u16 index)
{
    if (((const u8 *)gUnknown_08163444)[index * 10] != '?')
    {
        struct Task *task = Task_Create(gUnknown_08163640, 0xFFFF);
        struct BannerData *d;

        DmaFill32(3, 0, gBannerTiles, 0x100);
        d = (struct BannerData *)task->data;
        d->index = index;
        d->shown = 0;
        d->timer = 1;
        gUnk_0203A3E4 = task;
    }
}

// sub_080B65D0 @ 0x080B65D0
void sub_080B65D0(struct Task *task, u32 arg)
{
    struct FadeTaskData *d = (struct FadeTaskData *)task->data;

    if (arg == 0)
        DmaCopy32(3, gPaletteBuffer, (void *)0x0201B874, 0x400);
    gHudState[0x1A] = 1;
    d->fade = PalFade_FadeToBlack(1);
}

// sub_080B6614 @ 0x080B6614
void sub_080B6614(struct Task *task)
{
    struct FadeTaskData *d = (struct FadeTaskData *)task->data;
    u16 active = PalFade_IsActive(d->fade);

    if (active == 0)
    {
        task->result = 1;
        DmaFill16(3, active, gUnk_02000000, 0x1000);
    }
    else
    {
        task->result = 0;
    }
}

// sub_080B6658 @ 0x080B6658
void sub_080B6658(struct Task *task, u32 arg)
{
    struct FadeTaskData *d = (struct FadeTaskData *)task->data;
    u8 saved[0x40];

    d->fade = PalFade_FadeInFromBlack(1);
    if (arg == 0)
    {
        CpuSet((void *)0x03002D70, saved, 0x04000010);
        sub_080C1384();
        CpuSet(saved, (void *)0x03002D70, 0x04000010);
    }
    else
    {
        gHudState[0x1B] = 0;
    }
}

// sub_080B66A8 @ 0x080B66A8
void sub_080B66A8(struct Task *task)
{
    struct FadeTaskData *d = (struct FadeTaskData *)task->data;

    if (PalFade_IsActive(d->fade) == 0)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080B66C8 @ 0x080B66C8
void sub_080B66C8(void)
{
    DmaCopy32(3, (void *)0x06000000, (void *)0x02017874, 0x800);
    DmaCopy32(3, gUnk_02000000, (void *)0x06000000, 0x800);
}

// sub_080B66F8 @ 0x080B66F8
void sub_080B66F8(void)
{
    DmaCopy32(3, (void *)0x06001000, (void *)0x02018874, 0x800);
    DmaCopy32(3, gUnk_02000000, (void *)0x06001000, 0x800);
}

// sub_080B6728 @ 0x080B6728
void sub_080B6728(void)
{
    DmaCopy32(3, (void *)0x06002000, (void *)0x02019874, 0x800);
    DmaCopy32(3, gUnk_02000000, (void *)0x06002000, 0x800);
}

// sub_080B6758 @ 0x080B6758
void sub_080B6758(void)
{
    DmaCopy32(3, gUnk_02000000, (void *)0x06003000, 0x800);
    REG_BG3CNT = 0x860B;
}

// sub_080B6788 @ 0x080B6788
void sub_080B6788(void)
{
    DmaCopy32(3, (void *)0x06003000, (void *)0x0201A874, 0x800);
    sub_080B6758();
}

// sub_080B67B4 @ 0x080B67B4
void sub_080B67B4(struct Task *task, u32 bg)
{
    switch (bg)
    {
    case 0:
        VBlankTask_AddCounted(sub_080B66C8, 1);
        break;
    case 1:
        VBlankTask_AddCounted(sub_080B66F8, 1);
        break;
    case 2:
        VBlankTask_AddCounted(sub_080B6728, 1);
        break;
    case 3:
        VBlankTask_AddCounted(sub_080B6788, 1);
        break;
    }
}

// sub_080B67F8 @ 0x080B67F8
void sub_080B67F8(struct Task *task, u32 arg)
{
    if (arg == 0)
    {
        if (((struct FadeTaskData *)task->data)->kind == 0)
        {
            DmaCopy32(3, gUnknown_081B8870, gUnk_02000000, 0x500);
        }
        else
        {
            DmaCopy32(3, gUnknown_081636E8, gUnk_02000000, 0x500);
        }
        VBlankTask_AddCounted(sub_080B6758, 1);
    }
    gHudState[0x1B] = 1;
}

// sub_080B6850 @ 0x080B6850
void sub_080B6850(struct Task *task, u32 arg)
{
    if (arg == 0)
        sub_080AD7F0();
}

// sub_080B6860 @ 0x080B6860
void sub_080B6860(struct Task *task, u32 arg)
{
    task->result = 0;
    if (arg == 0)
    {
        if (gUnk_03003FF8 > 0xE)
        {
            VBlankTask_AddCounted(sub_080C1450, 1);
            task->result = 1;
        }
    }
    else if (gFieldState.unk0E == 0)
    {
        task->result = 1;
        sub_080AE494(sub_080B0158);
    }
}

// sub_080B68AC @ 0x080B68AC
void sub_080B68AC(struct Task *task)
{
    u32 r = gUnk_0200AB04 & 0x8000;

    if (r != 0)
        task->result = 1;
    else
        task->result = r;
}

// sub_080B68D0 @ 0x080B68D0
/* Background picture shown from a script, one step per call. */
void sub_080B68D0(struct Task *task, u32 step)
{
    task->result = 0;
    switch (step)
    {
    case 0:
        sub_080C14FC();
        Tilemap_FillRect(0, gUnk_02000000, 1, 0, 0x1C, 0xD);
        VBlankTask_AddCounted(sub_080B3E7C, 1);
        break;
    case 1:
        VBlankTask_AddCounted(sub_080B3E8C, 1);
        break;
    case 2:
        if (gBgPicturePiece != 0xFFFF)
        {
            BgPicture_LoadPiece(0);
        }
        else
        {
            VBlankTask_AddCounted(sub_080B3EA0, 1);
            task->result = 1;
        }
        break;
    case 3:
        VBlankTask_AddCounted(sub_080B3ED0, 1);
        break;
    case 4:
        VBlankTask_AddCounted(BgPicture_BuildTilemap, 1);
        break;
    case 5:
        VBlankTask_AddCounted(sub_080B41B0, 1);
        break;
    }
}

// sub_080B698C @ 0x080B698C
/* Restores BG0 and the palette saved by sub_080B66C8 / sub_080B65D0. */
void sub_080B698C(void)
{
    vu32 *dma;
    u32 save;

    sub_080C8440();
    dma = (vu32 *)0x040000D4;
    save = 0x02017874;
    dma[0] = save;
    dma[1] = 0x06000000;
    dma[2] = 0x84000200;
    dma[2];
    save += 0x4000;
    dma[0] = save;
    dma[1] = (u32)gPaletteTarget;
    dma[2] = 0x84000100;
    dma[2];
}

// sub_080B69D0 @ 0x080B69D0
void sub_080B69D0(void)
{
    DmaCopy32(3, (void *)0x02018874, (void *)0x06001000, 0x800);
}

// sub_080B69F4 @ 0x080B69F4
void sub_080B69F4(void)
{
    sub_080C153C();
    DmaFill32(3, 0, (void *)0x06008000, 0x20);
}

// sub_080B6A24 @ 0x080B6A24
void sub_080B6A24(void)
{
    DmaCopy32(3, (void *)0x0201A874, (void *)0x06003000, 0x800);
    sub_080C1450();
}

// sub_080B6A50 @ 0x080B6A50
void sub_080B6A50(struct Task *task, u32 step)
{
    switch (step)
    {
    case 0:
        VBlankTask_AddCounted(sub_080B698C, 1);
        break;
    case 1:
        VBlankTask_AddCounted(sub_080B69D0, 1);
        break;
    case 2:
        VBlankTask_AddCounted(sub_080B69F4, 1);
        sub_080C14FC();
        break;
    case 3:
        VBlankTask_AddCounted(sub_080B6A24, 1);
        break;
    case 4:
        DmaFill32(3, 0, (void *)0x06008000, 0x3C00);
        DmaCopy32(3, gUnknown_081A91B8, (void *)0x0600BC00, 0x4400);
        if (gHudState[0x18] == 0)
            sub_080C6558();
        break;
    }
}

// sub_080B6B00 @ 0x080B6B00
void sub_080B6B00(void)
{
    if (gFieldState.unk48 == 2)
        gFieldState.unk48 = 1;
    if (gFieldState.unk4C == 2)
        gFieldState.unk4C = 1;
    if (gFieldState.unk50 == 2)
        gFieldState.unk50 = 1;
}

// sub_080B6B34 @ 0x080B6B34
void sub_080B6B34(struct Task *task)
{
    struct FadeTaskData *d = (struct FadeTaskData *)task->data;

    if (d->func != NULL)
        d->func();
    else
        Field_SetState(1);
    gHudState[0x1A] = 0;
}
