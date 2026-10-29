/* Staff roll: scrolling credits text with a character walking along a path, then the
   "new game plus" save prompt. */

#include "global.h"
#include "battledisp.h"

#define sRoll gUnk_0203B454
#define STAFF_CANVAS gUnk_0200F874

// sub_0815C140 @ 0x0815C140
void sub_0815C140(void)
{
    u32 zero = 0;

    CpuSet(&zero, &sRoll, 0x05000040);
    SetMainCallback(sub_0815C1A8);
}

// sub_0815C16C @ 0x0815C16C
/* VBlank: uploads the text canvas and the BG1 tilemap. */
void sub_0815C16C(void)
{
    DmaCopy32(3, STAFF_CANVAS, (void *)0x06008000, 0x8000);
    DmaCopy32(3, gUnk_02000000, (void *)0x06001000, 0x800);
}

// sub_0815C1A8 @ 0x0815C1A8
void sub_0815C1A8(void)
{
    struct StaffRoll *s = &sRoll;
    u16 i;

    CpuFill32(0, s, 0x100);
    sub_080C1450();
    REG_BG1CNT = 0x209;
    sub_080C1384();
    DmaCopy32(3, gPaletteTarget, gPaletteBuffer, 0x400);
    Palette_MarkDirty();
    DmaFill32(3, 0, (void *)0x06000000, 0x4000);
    LZ77UnCompWram(gUnknown_081B6270, STAFF_CANVAS);
    LZ77UnCompWram(gUnknown_081B6594, STAFF_CANVAS + 0x1000);
    LZ77UnCompWram(gUnknown_081B68BC, STAFF_CANVAS + 0x2000);
    DmaCopy32(3, STAFF_CANVAS, (void *)0x06010400, 0x2800);
    DmaFill32(3, 0, STAFF_CANVAS, 0x8000);
    {
        u16 *map = gUnk_02000000;
        for (i = 0; i < 0x400; i++)
            map[i] = i + 0x5000;
    }
    s->scroll = 1;
    sub_0815C16C();
    gUnk_03000006 = (s->scroll - 0xA0) & 0xFF;
    gUnk_03000040 = 0;
    gUnk_0203DB6A = 0;
    Task_ClearAll();
    Windows_Init();
    /* Copies 9 rows into the 8-row path table; the 9th lands on s->obj, set just below. */
    for (i = 0; i <= 8; i++)
    {
        s->path[i].id = gUnknown_087F2C50[i][0];
        s->path[i].x = gUnknown_087F2C50[i][1];
        s->path[i].y = gUnknown_087F2C50[i][2];
        s->path[i].arg = gUnknown_087F2C50[i][3];
        s->path[i].tx = gUnknown_087F2C50[i][4];
        s->path[i].ty = gUnknown_087F2C50[i][5];
        s->path[i].scale = gUnknown_087F2C50[i][6];
        s->path[i].scaleStep = gUnknown_087F2C50[i][7];
    }
    /* Original bug: the scale comes from path[i] (i == 9, past the table), not path[0]. */
    sub_0815C75C(s->path[0].id, s->path[0].x, s->path[0].y, s->path[0].arg, s->path[i].scale);
    s->scale = s->path[0].scale;
    SetMainCallback(sub_0815C380);
    REG_IE = 0x2003;
    REG_DISPSTAT = 0x18;
    REG_IME = 1;
}

// sub_0815C380 @ 0x0815C380
#ifdef NONMATCHING
void sub_0815C380(void)
{
    struct StaffRoll *s = &sRoll;
    struct StaffRollObj *obj = (struct StaffRollObj *)&s->obj->data;
    const struct StaffRollLine *line;
    const u16 *str;
    u32 scroll;
    u32 y, y0;
    u16 x, n;
    u16 ty;

    Task_RunAll();
    if (s->segment <= 6)
    {
        if (*(u32 *)&s->dx == 0)
        {
            s->dx = s->path[s->segment].tx - s->path[s->segment].x;
            s->dy = s->path[s->segment].ty - s->path[s->segment].y;
            if (s->dx < 0)
            {
                s->signX = -1;
                s->dx *= -1;
            }
            else
            {
                s->signX = 1;
            }
            if (s->dy < 0)
            {
                s->signY = -1;
                s->dy *= -1;
            }
            else
            {
                s->signY = 1;
            }
        }
        if (s->dx >= s->dy)
        {
            if (obj->x == (s16)s->path[s->segment].tx && obj->y == (s16)s->path[s->segment].ty)
            {
                if (s->segment == 0)
                {
                    s->segment++;
                    s->stepY = 0;
                    s->stepX = 0;
                    s->accum = 0;
                    s->dy = 0;
                    s->dx = 0;
                }
                else if (s->segment == 6)
                {
                    s->segment++;
                    sub_0815C7CC();
                    s->timer = 0;
                    s->stepY = 0;
                    s->stepX = 0;
                    s->accum = 0;
                    s->dy = 0;
                    s->dx = 0;
                    sub_0815C75C(s->path[s->segment].id, s->path[s->segment].x, s->path[s->segment].y,
                                 s->path[s->segment].arg, s->path[s->segment].scale);
                }
                else if (s->next == 0)
                {
                    sub_0815C7CC();
                    sub_0815C828();
                }
                else
                {
                    s->next = 0;
                    if (++s->segment <= 6)
                    {
                        s->timer = 0;
                        s->stepY = 0;
                        s->stepX = 0;
                        s->accum = 0;
                        s->dy = 0;
                        s->dx = 0;
                        s->scale = s->path[s->segment].scale;
                        sub_0815C75C(s->path[s->segment].id, s->path[s->segment].x, s->path[s->segment].y,
                                     s->path[s->segment].arg, s->path[s->segment].scale);
                    }
                }
            }
            else
            {
                sub_0815C7E0(s->stepX, s->stepY, s->scale);
                s->stepX = s->signX;
                s->stepY = 0;
                s->accum += s->dy;
                if (s->frame % 3 == 0)
                    s->scale += s->path[s->segment].scaleStep;
                if (s->accum >= s->dx)
                {
                    s->stepY = s->signY;
                    s->accum -= s->dx;
                }
            }
        }
        else
        {
            if (obj->x == (s16)s->path[s->segment].tx && obj->y == (s16)s->path[s->segment].ty)
            {
                if (s->segment == 0)
                {
                    s->segment++;
                    s->stepY = 0;
                    s->stepX = 0;
                    s->accum = 0;
                    s->dy = 0;
                    s->dx = 0;
                    s->next = 0;
                }
                else if (s->segment == 6)
                {
                    s->segment++;
                    sub_0815C7CC();
                    s->timer = 0;
                    s->stepY = 0;
                    s->stepX = 0;
                    s->accum = 0;
                    s->dy = 0;
                    s->dx = 0;
                    sub_0815C75C(s->path[s->segment].id, s->path[s->segment].x, s->path[s->segment].y,
                                 s->path[s->segment].arg, s->path[s->segment].scale);
                    Task_Create(gUnknown_087F2DD4, 0xFFFF);
                }
                else if (s->next == 0)
                {
                    sub_0815C7CC();
                    sub_0815C828();
                }
                else
                {
                    s->next = 0;
                    if (++s->segment <= 6)
                    {
                        s->timer = 0;
                        s->stepY = 0;
                        s->stepX = 0;
                        s->accum = 0;
                        s->dy = 0;
                        s->dx = 0;
                        s->scale = s->path[s->segment].scale;
                        sub_0815C75C(s->path[s->segment].id, s->path[s->segment].x, s->path[s->segment].y,
                                     s->path[s->segment].arg, s->path[s->segment].scale);
                    }
                }
            }
            else
            {
                sub_0815C7E0(s->stepX, s->stepY, s->scale);
                s->stepY = s->signY;
                s->stepX = 0;
                s->accum += s->dx;
                if (s->frame % 3 == 0)
                    s->scale += s->path[s->segment].scaleStep;
                if (s->accum >= s->dy)
                {
                    s->stepX = s->signX;
                    s->accum -= s->dy;
                }
            }
        }
    }

    if ((s->frame & 1) == 0)
    {
        scroll = s->scroll;
        line = &gUnknown_087F28B0[scroll >> 4];
        if (line->type == -2)
            return;
        s->scroll = scroll + 1;
        gUnk_03000006 = (scroll - 0x9F) & 0xFF;
        scroll++;
        if ((scroll & 0xF) == 0)
        {
            if (s->textDone == 0)
            {
                line = &gUnknown_087F28B0[scroll >> 4];
                if (line->type == 0)
                {
                    str = line->ptr;
                    x = 0;
                    ty = scroll & 0xFF;
                    while (*str != 0)
                    {
                        Font_DrawGlyphTinted(*str, STAFF_CANVAS, x, ty, 0);
                        str++;
                        x += 12;
                    }
                }
                else if (line->type < 0)
                {
                    s->textDone = 1;
                }
            }
            if (s->scroll > 0xAF)
            {
                u8 *dst = STAFF_CANVAS + (((s->scroll - 0xB0) & 0xFF) >> 3) * 0x400;
                DmaFill32(3, 0, dst, 0x800);
                s->row++;
            }
            VBlankTask_AddCounted(sub_0815C16C, 1);
        }
    }

    line = &gUnknown_087F28B0[s->row];
    y0 = y = ((s->row * 16 + 0xA0) - (s->scroll & 0xFF)) & 0xFF;
    n = 0;
    if (line->type != -2)
    {
        while (1)
        {
            if (line->type == 1)
                Sprite_Draw(line->ptr, 0, 0, 0, 0x20, 4, y - 4);
            else if (line->type == 2)
                Sprite_Draw(line->ptr, 0, 0, 0, 0x20, 0x78, y - 4);
            else if (line->type == 3)
                Sprite_Draw(line->ptr, 0, 0, 0, 0x20, 0x6C, y - 4);
            y = (y + 16) & 0x1FF;
            if (y0 < 0xA0 && y >= 0xA0)
                break;
            line++;
            n++;
            if (n > 10)
                break;
            if (line->type == -2)
                break;
        }
    }
    s->frame++;
}
#else
NAKED
void sub_0815C380(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sb\n"
        "    mov r6, r8\n"
        "    push {r6, r7}\n"
        "    sub sp, #0x10\n"
        "    ldr r5, .L0815C3D8\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0xac\n"
        "    ldr r0, [r0]\n"
        "    adds r6, r0, #0\n"
        "    adds r6, #0x24\n"
        "    bl Task_RunAll\n"
        "    ldrh r0, [r5, #0x28]\n"
        "    cmp r0, #6\n"
        "    bls .L0815C3A2\n"
        "    b .L0815C5C6\n"
        ".L0815C3A2:\n"
        "    ldr r0, [r5, #0x14]\n"
        "    ldrh r3, [r5, #0x28]\n"
        "    cmp r0, #0\n"
        "    bne .L0815C404\n"
        "    lsls r0, r3, #4\n"
        "    adds r0, r0, r5\n"
        "    ldrh r2, [r0, #0x34]\n"
        "    ldrh r0, [r0, #0x2e]\n"
        "    subs r2, r2, r0\n"
        "    strh r2, [r5, #0x14]\n"
        "    adds r0, r3, #0\n"
        "    lsls r0, r0, #4\n"
        "    adds r0, r0, r5\n"
        "    ldrh r1, [r0, #0x36]\n"
        "    ldrh r0, [r0, #0x30]\n"
        "    subs r1, r1, r0\n"
        "    strh r1, [r5, #0x16]\n"
        "    lsls r2, r2, #0x10\n"
        "    cmp r2, #0\n"
        "    bge .L0815C3E0\n"
        "    ldr r0, .L0815C3DC\n"
        "    strh r0, [r5, #0x1c]\n"
        "    movs r1, #0x14\n"
        "    ldrsh r0, [r5, r1]\n"
        "    rsbs r0, r0, #0\n"
        "    strh r0, [r5, #0x14]\n"
        "    b .L0815C3E4\n"
        ".L0815C3D8: .4byte 0x0203B454 @ EWRAM+0x3B454\n"
        ".L0815C3DC: .4byte 0x0000FFFF\n"
        ".L0815C3E0:\n"
        "    movs r0, #1\n"
        "    strh r0, [r5, #0x1c]\n"
        ".L0815C3E4:\n"
        "    movs r2, #0x16\n"
        "    ldrsh r0, [r5, r2]\n"
        "    cmp r0, #0\n"
        "    bge .L0815C400\n"
        "    ldr r0, .L0815C3FC\n"
        "    strh r0, [r5, #0x1e]\n"
        "    movs r4, #0x16\n"
        "    ldrsh r0, [r5, r4]\n"
        "    rsbs r0, r0, #0\n"
        "    strh r0, [r5, #0x16]\n"
        "    b .L0815C404\n"
        "    .byte 0x00, 0x00\n"
        ".L0815C3FC: .4byte 0x0000FFFF\n"
        ".L0815C400:\n"
        "    movs r0, #1\n"
        "    strh r0, [r5, #0x1e]\n"
        ".L0815C404:\n"
        "    movs r7, #0x14\n"
        "    ldrsh r1, [r5, r7]\n"
        "    movs r2, #0x16\n"
        "    ldrsh r0, [r5, r2]\n"
        "    cmp r1, r0\n"
        "    blt .L0815C4B0\n"
        "    lsls r0, r3, #4\n"
        "    adds r2, r5, r0\n"
        "    movs r4, #8\n"
        "    ldrsh r1, [r6, r4]\n"
        "    movs r7, #0x34\n"
        "    ldrsh r0, [r2, r7]\n"
        "    cmp r1, r0\n"
        "    bne .L0815C466\n"
        "    movs r0, #0xa\n"
        "    ldrsh r1, [r6, r0]\n"
        "    movs r4, #0x36\n"
        "    ldrsh r0, [r2, r4]\n"
        "    cmp r1, r0\n"
        "    bne .L0815C466\n"
        "    adds r1, r3, #0\n"
        "    cmp r1, #0\n"
        "    bne .L0815C442\n"
        "    adds r0, r3, #1\n"
        "    strh r0, [r5, #0x28]\n"
        "    strh r1, [r5, #0x1a]\n"
        "    strh r1, [r5, #0x18]\n"
        "    strh r1, [r5, #0x20]\n"
        "    strh r1, [r5, #0x16]\n"
        "    strh r1, [r5, #0x14]\n"
        "    b .L0815C5C6\n"
        ".L0815C442:\n"
        "    cmp r1, #6\n"
        "    bne .L0815C45E\n"
        "    adds r0, r3, #1\n"
        "    movs r4, #0\n"
        "    strh r0, [r5, #0x28]\n"
        "    bl sub_0815C7CC\n"
        "    strh r4, [r5, #0x24]\n"
        "    strh r4, [r5, #0x1a]\n"
        "    strh r4, [r5, #0x18]\n"
        "    strh r4, [r5, #0x20]\n"
        "    strh r4, [r5, #0x16]\n"
        "    strh r4, [r5, #0x14]\n"
        "    b .L0815C564\n"
        ".L0815C45E:\n"
        "    ldrh r0, [r5, #0x22]\n"
        "    cmp r0, #0\n"
        "    beq .L0815C532\n"
        "    b .L0815C53C\n"
        ".L0815C466:\n"
        "    ldrh r0, [r5, #0x18]\n"
        "    ldrh r1, [r5, #0x1a]\n"
        "    ldrh r2, [r5, #0x26]\n"
        "    bl sub_0815C7E0\n"
        "    ldrh r0, [r5, #0x1c]\n"
        "    movs r1, #0\n"
        "    strh r0, [r5, #0x18]\n"
        "    strh r1, [r5, #0x1a]\n"
        "    ldrh r0, [r5, #0x16]\n"
        "    ldrh r6, [r5, #0x20]\n"
        "    adds r0, r0, r6\n"
        "    strh r0, [r5, #0x20]\n"
        "    ldr r0, [r5, #0x10]\n"
        "    movs r1, #3\n"
        "    bl __umodsi3\n"
        "    cmp r0, #0\n"
        "    bne .L0815C49A\n"
        "    ldrh r0, [r5, #0x28]\n"
        "    lsls r0, r0, #4\n"
        "    adds r0, r5, r0\n"
        "    ldrh r0, [r0, #0x3a]\n"
        "    ldrh r7, [r5, #0x26]\n"
        "    adds r0, r0, r7\n"
        "    strh r0, [r5, #0x26]\n"
        ".L0815C49A:\n"
        "    ldrh r1, [r5, #0x20]\n"
        "    movs r2, #0x14\n"
        "    ldrsh r0, [r5, r2]\n"
        "    cmp r1, r0\n"
        "    bge .L0815C4A6\n"
        "    b .L0815C5C6\n"
        ".L0815C4A6:\n"
        "    ldrh r0, [r5, #0x1e]\n"
        "    strh r0, [r5, #0x1a]\n"
        "    ldrh r0, [r5, #0x20]\n"
        "    ldrh r1, [r5, #0x14]\n"
        "    b .L0815C5C2\n"
        ".L0815C4B0:\n"
        "    adds r2, r3, #0\n"
        "    lsls r0, r2, #4\n"
        "    adds r4, r5, r0\n"
        "    movs r7, #8\n"
        "    ldrsh r1, [r6, r7]\n"
        "    movs r7, #0x34\n"
        "    ldrsh r0, [r4, r7]\n"
        "    cmp r1, r0\n"
        "    bne .L0815C57C\n"
        "    movs r0, #0xa\n"
        "    ldrsh r1, [r6, r0]\n"
        "    movs r6, #0x36\n"
        "    ldrsh r0, [r4, r6]\n"
        "    cmp r1, r0\n"
        "    bne .L0815C57C\n"
        "    lsls r0, r2, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    cmp r1, #0\n"
        "    bne .L0815C4E8\n"
        "    adds r0, r2, #1\n"
        "    strh r0, [r5, #0x28]\n"
        "    strh r1, [r5, #0x1a]\n"
        "    strh r1, [r5, #0x18]\n"
        "    strh r1, [r5, #0x20]\n"
        "    strh r1, [r5, #0x16]\n"
        "    strh r1, [r5, #0x14]\n"
        "    strh r1, [r5, #0x22]\n"
        "    b .L0815C5C6\n"
        ".L0815C4E8:\n"
        "    cmp r1, #6\n"
        "    bne .L0815C52C\n"
        "    adds r0, r3, #1\n"
        "    movs r4, #0\n"
        "    strh r0, [r5, #0x28]\n"
        "    bl sub_0815C7CC\n"
        "    strh r4, [r5, #0x24]\n"
        "    strh r4, [r5, #0x1a]\n"
        "    strh r4, [r5, #0x18]\n"
        "    strh r4, [r5, #0x20]\n"
        "    strh r4, [r5, #0x16]\n"
        "    strh r4, [r5, #0x14]\n"
        "    ldrh r4, [r5, #0x28]\n"
        "    lsls r4, r4, #4\n"
        "    adds r4, r5, r4\n"
        "    ldrh r0, [r4, #0x2c]\n"
        "    ldrh r1, [r4, #0x2e]\n"
        "    ldrh r2, [r4, #0x30]\n"
        "    ldrh r3, [r4, #0x32]\n"
        "    ldrh r4, [r4, #0x38]\n"
        "    str r4, [sp]\n"
        "    bl sub_0815C75C\n"
        "    ldr r0, .L0815C524\n"
        "    ldr r1, .L0815C528\n"
        "    bl Task_Create\n"
        "    b .L0815C5C6\n"
        "    .byte 0x00, 0x00\n"
        ".L0815C524: .4byte gUnknown_087F2DD4\n"
        ".L0815C528: .4byte 0x0000FFFF\n"
        ".L0815C52C:\n"
        "    ldrh r0, [r5, #0x22]\n"
        "    cmp r0, #0\n"
        "    bne .L0815C53C\n"
        ".L0815C532:\n"
        "    bl sub_0815C7CC\n"
        "    bl sub_0815C828\n"
        "    b .L0815C5C6\n"
        ".L0815C53C:\n"
        "    movs r1, #0\n"
        "    strh r1, [r5, #0x22]\n"
        "    ldrh r0, [r5, #0x28]\n"
        "    adds r0, #1\n"
        "    strh r0, [r5, #0x28]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #6\n"
        "    bhi .L0815C5C6\n"
        "    strh r1, [r5, #0x24]\n"
        "    strh r1, [r5, #0x1a]\n"
        "    strh r1, [r5, #0x18]\n"
        "    strh r1, [r5, #0x20]\n"
        "    strh r1, [r5, #0x16]\n"
        "    strh r1, [r5, #0x14]\n"
        "    ldrh r0, [r5, #0x28]\n"
        "    lsls r0, r0, #4\n"
        "    adds r0, r5, r0\n"
        "    ldrh r0, [r0, #0x38]\n"
        "    strh r0, [r5, #0x26]\n"
        ".L0815C564:\n"
        "    ldrh r4, [r5, #0x28]\n"
        "    lsls r4, r4, #4\n"
        "    adds r4, r5, r4\n"
        "    ldrh r0, [r4, #0x2c]\n"
        "    ldrh r1, [r4, #0x2e]\n"
        "    ldrh r2, [r4, #0x30]\n"
        "    ldrh r3, [r4, #0x32]\n"
        "    ldrh r4, [r4, #0x38]\n"
        "    str r4, [sp]\n"
        "    bl sub_0815C75C\n"
        "    b .L0815C5C6\n"
        ".L0815C57C:\n"
        "    ldrh r0, [r5, #0x18]\n"
        "    ldrh r1, [r5, #0x1a]\n"
        "    ldrh r2, [r5, #0x26]\n"
        "    bl sub_0815C7E0\n"
        "    ldrh r0, [r5, #0x1e]\n"
        "    movs r1, #0\n"
        "    strh r0, [r5, #0x1a]\n"
        "    strh r1, [r5, #0x18]\n"
        "    ldrh r0, [r5, #0x14]\n"
        "    ldrh r7, [r5, #0x20]\n"
        "    adds r0, r0, r7\n"
        "    strh r0, [r5, #0x20]\n"
        "    ldr r0, [r5, #0x10]\n"
        "    movs r1, #3\n"
        "    bl __umodsi3\n"
        "    cmp r0, #0\n"
        "    bne .L0815C5B0\n"
        "    ldrh r0, [r5, #0x28]\n"
        "    lsls r0, r0, #4\n"
        "    adds r0, r5, r0\n"
        "    ldrh r0, [r0, #0x3a]\n"
        "    ldrh r1, [r5, #0x26]\n"
        "    adds r0, r0, r1\n"
        "    strh r0, [r5, #0x26]\n"
        ".L0815C5B0:\n"
        "    ldrh r1, [r5, #0x20]\n"
        "    movs r2, #0x16\n"
        "    ldrsh r0, [r5, r2]\n"
        "    cmp r1, r0\n"
        "    blt .L0815C5C6\n"
        "    ldrh r0, [r5, #0x1c]\n"
        "    strh r0, [r5, #0x18]\n"
        "    ldrh r0, [r5, #0x20]\n"
        "    ldrh r1, [r5, #0x16]\n"
        ".L0815C5C2:\n"
        "    subs r0, r0, r1\n"
        "    strh r0, [r5, #0x20]\n"
        ".L0815C5C6:\n"
        "    ldr r0, [r5, #0x10]\n"
        "    movs r4, #1\n"
        "    mov r8, r4\n"
        "    ands r0, r4\n"
        "    cmp r0, #0\n"
        "    bne .L0815C690\n"
        "    ldr r3, [r5, #4]\n"
        "    lsrs r0, r3, #4\n"
        "    lsls r0, r0, #3\n"
        "    ldr r4, .L0815C648\n"
        "    adds r6, r0, r4\n"
        "    ldr r1, [r6]\n"
        "    movs r0, #2\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r1, r0\n"
        "    bne .L0815C5E8\n"
        "    b .L0815C748\n"
        ".L0815C5E8:\n"
        "    adds r7, r3, #1\n"
        "    str r7, [r5, #4]\n"
        "    ldr r2, .L0815C64C\n"
        "    adds r0, r3, #0\n"
        "    subs r0, #0x9f\n"
        "    movs r1, #0xff\n"
        "    ands r0, r1\n"
        "    strh r0, [r2]\n"
        "    movs r0, #0xf\n"
        "    ands r0, r7\n"
        "    cmp r0, #0\n"
        "    bne .L0815C690\n"
        "    ldr r0, [r5]\n"
        "    cmp r0, #0\n"
        "    bne .L0815C65C\n"
        "    lsrs r0, r7, #4\n"
        "    lsls r0, r0, #3\n"
        "    adds r6, r0, r4\n"
        "    ldr r0, [r6]\n"
        "    cmp r0, #0\n"
        "    bne .L0815C654\n"
        "    ldr r4, [r6, #4]\n"
        "    movs r6, #0\n"
        "    movs r0, #0xff\n"
        "    mov r8, r0\n"
        "    mov r1, r8\n"
        "    ands r1, r7\n"
        "    mov r8, r1\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #0\n"
        "    beq .L0815C65C\n"
        ".L0815C626:\n"
        "    ldrh r0, [r4]\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    ldr r1, .L0815C650\n"
        "    adds r2, r6, #0\n"
        "    mov r3, r8\n"
        "    bl Font_DrawGlyphTinted\n"
        "    adds r4, #2\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0xc\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #0\n"
        "    bne .L0815C626\n"
        "    b .L0815C65C\n"
        ".L0815C648: .4byte gUnknown_087F28B0\n"
        ".L0815C64C: .4byte 0x03000006 @ IWRAM+0x6\n"
        ".L0815C650: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L0815C654:\n"
        "    cmp r0, #0\n"
        "    bge .L0815C65C\n"
        "    mov r2, r8\n"
        "    str r2, [r5]\n"
        ".L0815C65C:\n"
        "    ldr r0, [r5, #4]\n"
        "    cmp r0, #0xaf\n"
        "    bls .L0815C688\n"
        "    subs r0, #0xb0\n"
        "    movs r1, #0xff\n"
        "    ands r0, r1\n"
        "    lsrs r0, r0, #3\n"
        "    lsls r0, r0, #0xa\n"
        "    ldr r1, .L0815C6C4\n"
        "    adds r0, r0, r1\n"
        "    movs r1, #0\n"
        "    str r1, [sp, #0xc]\n"
        "    ldr r1, .L0815C6C8\n"
        "    add r4, sp, #0xc\n"
        "    str r4, [r1]\n"
        "    str r0, [r1, #4]\n"
        "    ldr r0, .L0815C6CC\n"
        "    str r0, [r1, #8]\n"
        "    ldr r0, [r1, #8]\n"
        "    ldr r0, [r5, #8]\n"
        "    adds r0, #1\n"
        "    str r0, [r5, #8]\n"
        ".L0815C688:\n"
        "    ldr r0, .L0815C6D0\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        ".L0815C690:\n"
        "    ldr r1, [r5, #8]\n"
        "    lsls r2, r1, #3\n"
        "    ldr r0, .L0815C6D4\n"
        "    adds r6, r2, r0\n"
        "    lsls r1, r1, #4\n"
        "    adds r1, #0xa0\n"
        "    movs r2, #0xff\n"
        "    ldrb r0, [r5, #4]\n"
        "    subs r4, r1, r0\n"
        "    ands r4, r2\n"
        "    mov sb, r4\n"
        "    movs r7, #0\n"
        "    mov r8, r7\n"
        "    ldr r1, [r6]\n"
        "    movs r0, #2\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r1, r0\n"
        "    beq .L0815C742\n"
        "    movs r7, #0x20\n"
        ".L0815C6B6:\n"
        "    ldr r0, [r6]\n"
        "    cmp r0, #1\n"
        "    bne .L0815C6D8\n"
        "    ldr r0, [r6, #4]\n"
        "    str r7, [sp]\n"
        "    movs r1, #4\n"
        "    b .L0815C6E2\n"
        ".L0815C6C4: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L0815C6C8: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L0815C6CC: .4byte 0x85000200\n"
        ".L0815C6D0: .4byte sub_0815C16C\n"
        ".L0815C6D4: .4byte gUnknown_087F28B0\n"
        ".L0815C6D8:\n"
        "    cmp r0, #2\n"
        "    bne .L0815C6F8\n"
        "    ldr r0, [r6, #4]\n"
        "    str r7, [sp]\n"
        "    movs r1, #0x78\n"
        ".L0815C6E2:\n"
        "    str r1, [sp, #4]\n"
        "    subs r1, r4, #4\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        "    b .L0815C716\n"
        ".L0815C6F8:\n"
        "    cmp r0, #3\n"
        "    bne .L0815C716\n"
        "    ldr r0, [r6, #4]\n"
        "    str r7, [sp]\n"
        "    movs r1, #0x6c\n"
        "    str r1, [sp, #4]\n"
        "    subs r1, r4, #4\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L0815C716:\n"
        "    adds r4, #0x10\n"
        "    ldr r1, .L0815C758\n"
        "    adds r0, r1, #0\n"
        "    ands r4, r0\n"
        "    mov r2, sb\n"
        "    cmp r2, #0x9f\n"
        "    bhi .L0815C728\n"
        "    cmp r4, #0x9f\n"
        "    bhi .L0815C742\n"
        ".L0815C728:\n"
        "    adds r6, #8\n"
        "    mov r0, r8\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        "    cmp r0, #0xa\n"
        "    bhi .L0815C742\n"
        "    ldr r1, [r6]\n"
        "    movs r0, #2\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r1, r0\n"
        "    bne .L0815C6B6\n"
        ".L0815C742:\n"
        "    ldr r0, [r5, #0x10]\n"
        "    adds r0, #1\n"
        "    str r0, [r5, #0x10]\n"
        ".L0815C748:\n"
        "    add sp, #0x10\n"
        "    pop {r3, r4}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L0815C758: .4byte 0x000001FF\n"
    );
}
#endif

// sub_0815C75C @ 0x0815C75C
/* Creates the walking character object with the given scale (capped at 0x100). */
void sub_0815C75C(u16 id, u16 x, u16 y, u16 arg, u16 scale)
{
    struct StaffRoll *s = &sRoll;
    struct ObjScale *sc;

    s->obj = CharObj_Create(0, id, x, y, arg, 0);
    sc = (struct ObjScale *)&s->obj->data.raw[0x24];
    if (scale > 0x100)
        scale = 0x100;
    sc->on = 1;
    sc->x = scale;
    sc->y = scale;
    sc->unk6 = 0;
}

// sub_0815C7CC @ 0x0815C7CC
void sub_0815C7CC(void)
{
    Task_End(sRoll.obj);
}

// sub_0815C7E0 @ 0x0815C7E0
/* Moves the character object by (dx, dy) and sets its scale. */
void sub_0815C7E0(u16 dx, u16 dy, u16 scale)
{
    struct Task *t = sRoll.obj;
    struct StaffRollObj *obj = (struct StaffRollObj *)&t->data;
    struct ObjScale *sc = (struct ObjScale *)&t->data.raw[0x24];

    obj->x += dx;
    obj->y += dy;
    if (scale > 0x100)
        scale = 0x100;
    sc->on = 1;
    sc->x = scale;
    sc->y = scale;
    sc->unk6 = 0;
}

// sub_0815C828 @ 0x0815C828
/* Pause at a path waypoint: 600 frames at segment 5, none at 6, 350 elsewhere. */
void sub_0815C828(void)
{
    struct StaffRoll *s = &sRoll;

    if (s->segment == 5)
    {
        if (s->timer == 600)
            s->next = 1;
        else
            s->timer++;
    }
    else if (s->segment == 6 || s->timer == 350)
    {
        s->next = 1;
    }
    else
    {
        s->timer++;
    }
}

// sub_0815C860 @ 0x0815C860
void sub_0815C860(void)
{
    DmaFill32(3, 0, (void *)0x06000000, 0x4000);
}

// sub_0815C884 @ 0x0815C884
void sub_0815C884(struct Task *t)
{
    t->data.w[0] = BgPicture_StartTask(0x3A);
    gUnk_03000030 = 0xE8;
    gUnk_03000031 = 8;
    gUnk_03000034 = 0x80;
    gUnk_03000035 = 0x18;
    gUnk_03000032 = 0xE8;
    gUnk_03000033 = 8;
    gUnk_03000036 = 0x80;
    gUnk_03000037 = 0x18;
    gUnk_0300003A = 0;
    gUnk_03000038 = gUnk_03000039 = 0x18;
    VBlankTask_AddCounted(sub_0815C860, 1);
}

// sub_0815C904 @ 0x0815C904
void sub_0815C904(struct Task *t)
{
    if (*(u16 *)t->data.w[0] != 0)
        t->result = 0;
    else
        t->result = 1;
}

// sub_0815C91C @ 0x0815C91C
void sub_0815C91C(void)
{
    Palette_CopyWithEffect(3, gUnknown_085426E0, gUnk_03002D50, 0x40, 0x20);
    PalFade_FadeRangeWithDuration(0x1D0, 0x10, 8, 0x20);
}

// sub_0815C94C @ 0x0815C94C
void sub_0815C94C(struct Task *t)
{
    u32 *data = t->data.w;

    t->data.w[0] = Window_CreateOpen(1, 8, 0x1C, 8, 0);
    Font_ResetGlyphSpriteCache(0x180);
    data[1] = YesNo_Create(0);
    Palette_CopyWithEffect(3, gPaletteTarget, gPaletteBuffer, 0x400, 0x20);
    Palette_MarkDirty();
}

// sub_0815C9A0 @ 0x0815C9A0
void sub_0815C9A0(struct Task *t)
{
    Window_Close(t->data.w[0], 1);
}

// sub_0815C9B0 @ 0x0815C9B0
void sub_0815C9B0(void)
{
    if (Flag_Test(0x5E))
        sub_080C2A50(0, 1);
    else if (Flag_Test(0x5F))
        sub_080C2A50(2, 1);
    else
        sub_080C2A50(1, 1);
}

// sub_0815C9E0 @ 0x0815C9E0
void sub_0815C9E0(struct Task *t)
{
    u32 r = Task_IsFree(t->data.w[1]);

    if (r == 1)
    {
        t->result = r;
        t->unk1E = gYesNoResult;
    }
    else
    {
        t->result = 0;
    }
}

// sub_0815CA08 @ 0x0815CA08
void sub_0815CA08(void)
{
    Game_NewGame();
    Flag_Set(0xEE);
    Flag_Set(2);
    Flag_Set(0x100);
    gUnk_03004614 = 0;
    gUnk_03004514 = 0;
    gFieldState[9] = 2;
    gFieldState[10] = 6;
    SaveScreen_Open(3, 4);
    SetMainCallback(sub_0815CAB4);
}

// sub_0815CA58 @ 0x0815CA58
void sub_0815CA58(void)
{
    Text_DrawSpriteString(gUnknown_087F2D50, 0, 0, 0xC, 0x46, 0xC);
}

// sub_0815CA7C @ 0x0815CA7C
void sub_0815CA7C(void)
{
    gUnk_03000038 = 0x3F;
    gUnk_03000039 = 0x3F;
    gUnk_0300003A = 0x3F;
    VBlankTask_AddCounted(sub_0815C860, 1);
}

// sub_0815CAA8 @ 0x0815CAA8
void sub_0815CAA8(void)
{
    sub_080D5B8C(0);
}

// sub_0815CAB4 @ 0x0815CAB4
void sub_0815CAB4(void)
{
    gUnk_0200AB04 = 0;
    gUnk_03000038 = 0x3F;
    gUnk_03000039 = 0x3F;
    gUnk_0300003A = 0x3F;
    SetMainCallback(sub_0815CAE8);
}

// sub_0815CAE8 @ 0x0815CAE8
void sub_0815CAE8(void)
{
    Task_RunAll();
}
