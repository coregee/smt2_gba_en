/* Menu cursors (8 slots at 0x03006480) and menu window graphics. */

#include "global.h"
#include "menucur.h"

// sub_081267F4 @ 0x081267F4
void sub_081267F4(void)
{
    sub_08126850();
}

// sub_08126800 @ 0x08126800
void sub_08126800(u16 arg)
{
    gUnk_030063A0.unk6 = 1;
    gUnk_030063A0.unk2 = 1;
    gUnk_030063A0.unk0 = 1;
    gUnk_030063A0.unk4 = 0;
    gUnk_030063A0.unk14 = 0;
    gUnk_030063A0.unkC = arg;
    gUnk_030063A0.unkE = 0;
}

// sub_0812681C @ 0x0812681C
s16 sub_0812681C(void)
{
    return gUnk_030063A0.unk2;
}

// sub_08126828 @ 0x08126828
void sub_08126828(void)
{
}

// sub_0812682C @ 0x0812682C
void sub_0812682C(void)
{
}

// sub_08126830 @ 0x08126830
void sub_08126830(void)
{
}

// sub_08126834 @ 0x08126834
void sub_08126834(u16 n)
{
    BLOCK->unk998 += n;
}

// sub_08126850 @ 0x08126850
void sub_08126850(void)
{
    sub_08126800(2);
}

// sub_0812685C @ 0x0812685C
u16 sub_0812685C(void)
{
    return gUnk_030063A0.unk6;
}

// sub_08126868 @ 0x08126868
void sub_08126868(void)
{
}

// sub_0812686C @ 0x0812686C
void sub_0812686C(void)
{
}

// sub_08126870 @ 0x08126870
void sub_08126870(void)
{
    u8 i;

    for (i = 0; i < 8; i++)
        sub_08126898(&gUnk_03006480[i]);
}

// sub_08126898 @ 0x08126898
void sub_08126898(struct MenuCursor *c)
{
    u32 zero = 0;

    CpuSet(&zero, c, 0x0500000A);
    c->state = 0;
    c->unk14 = 1;
    c->index = 1;
    c->perColumn = 1;
    c->top = 1;
    c->count = 1;
    c->rows = 1;
    c->columns = 1;
    c->seSelect = 0xFFFF;
    c->seStart = 0xFFFF;
    c->seLR = 0xFFFF;
    c->seB = 0xFFFF;
    c->seA = 0xFFFF;
    c->sePage = 0xFFFF;
    c->seMove = 0xFFFF;
}

// sub_081268E4 @ 0x081268E4
u8 sub_081268E4(u8 id, struct MenuCursor *src)
{
    struct MenuCursor *c;
    if (id > 8)
        return 0xFF;
    c = &gUnk_03006480[id];
    if (c->state != 0)
        return 0xFF;
    *c = *src;
    return id;
}

// sub_08126928 @ 0x08126928
#ifdef NONMATCHING
u8 sub_08126928(u8 id, u8 type, u16 columns, u16 rows, u16 perColumn)
{
    struct MenuCursor c;
    u8 flags;

    c.state = 1;
    c.delay = 0;
    c.mode = type >> 4;
    flags = type & 0xF;
    c.flags = flags;
    c.columns = columns;
    c.rows = rows;
    c.count = columns * rows;
    c.top = 0;
    c.onScreen = 0;
    c.perColumn = perColumn;
    c.index = 0;
    c.unk14 = 0;
    c.column = 0;
    c.row = 0;
    c.sePage = 0x64;
    c.seMove = 0x64;
    c.seA = 0x65;
    c.seB = 0x66;
    c.seSelect = 0xFFFF;
    c.seStart = 0xFFFF;
    c.seLR = 0xFFFF;
    return sub_081268E4(id, &c);
}
#else
NAKED
u8 sub_08126928(u8 id, u8 type, u16 columns, u16 rows, u16 perColumn)
{
    asm_unified(
        ".L08126928:\n"
        "    push {r4, r5, r6, lr}\n"
        "    mov r6, r8\n"
        "    push {r6}\n"
        "    sub sp, #0x28\n"
        "    ldr r4, [sp, #0x3c]\n"
        "    mov r8, r4\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    lsls r1, r1, #0x18\n"
        "    lsrs r1, r1, #0x18\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    mov r5, sp\n"
        "    movs r6, #0\n"
        "    movs r4, #1\n"
        "    strb r4, [r5]\n"
        "    mov r4, sp\n"
        "    strb r6, [r4, #1]\n"
        "    lsrs r4, r1, #4\n"
        "    strb r4, [r5, #2]\n"
        "    movs r4, #0xf\n"
        "    ands r4, r1\n"
        "    strb r4, [r5, #3]\n"
        "    mov r1, sp\n"
        "    strh r2, [r1, #6]\n"
        "    strh r3, [r1, #8]\n"
        "    mov r4, sp\n"
        "    adds r1, r2, #0\n"
        "    muls r1, r3, r1\n"
        "    strh r1, [r4, #0xa]\n"
        "    mov r1, sp\n"
        "    strh r6, [r1, #0xc]\n"
        "    strh r6, [r1, #0xe]\n"
        "    mov r2, r8\n"
        "    strh r2, [r1, #0x10]\n"
        "    strh r6, [r1, #0x12]\n"
        "    strh r6, [r1, #0x14]\n"
        "    strh r6, [r1, #0x16]\n"
        "    strh r6, [r1, #0x18]\n"
        "    mov r3, sp\n"
        "    mov r2, sp\n"
        "    movs r1, #0x64\n"
        "    strh r1, [r2, #0x1c]\n"
        "    strh r1, [r3, #0x1a]\n"
        "    movs r1, #0x65\n"
        "    strh r1, [r2, #0x1e]\n"
        "    movs r1, #0x66\n"
        "    strh r1, [r2, #0x20]\n"
        "    ldr r1, .L081269AC\n"
        "    strh r1, [r2, #0x26]\n"
        "    movs r1, #1\n"
        "    rsbs r1, r1, #0\n"
        "    strh r1, [r3, #0x24]\n"
        "    strh r1, [r4, #0x22]\n"
        "    mov r1, sp\n"
        "    bl sub_081268E4\n"
        "    add sp, #0x28\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L081269AC: .4byte 0x0000FFFF\n"
    );
}
#endif

// sub_081269B0 @ 0x081269B0
void sub_081269B0(u8 id)
{
    if (id <= 8)
        sub_08126898(&gUnk_03006480[id]);
}

// sub_081269D0 @ 0x081269D0
void sub_081269D0(void)
{
    u8 i;

    for (i = 0; i < 8; i++)
        sub_081269B0(i);
}

// sub_081269EC @ 0x081269EC
void sub_081269EC(void)
{
    u8 i;

    for (i = 0; i < 8; i++)
        sub_08126A08(i);
}

// sub_08126A08 @ 0x08126A08
/* Moves cursor `id` with the D-pad and records A/B/START/SELECT/L/R presses in state. */
void sub_08126A08(u8 id)
{
    struct MenuCursor *c = &gUnk_03006480[id];
    u16 keys = gRepeatedKeys;

    switch (c->state)
    {
    case 0:
        return;
    case 2:
        if (c->delay != 0)
        {
            c->delay--;
            return;
        }
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
        c->state = 1;
        break;
    }

    c->keys = keys;
    if (gKeysNew & 8)
    {
        c->state = 5;
        sub_08126D34(c->seStart);
        return;
    }
    if (gKeysNew & 4)
    {
        c->state = 6;
        sub_08126D34(c->seSelect);
        return;
    }
    if (gKeysNew & 1)
    {
        c->state = 3;
        sub_08126D34(c->seA);
        return;
    }
    if (gKeysNew & 2)
    {
        c->state = 4;
        sub_08126D34(c->seB);
        return;
    }
    if (c->mode == 0)
    {
        if (gKeysNew & 0x200)
        {
            c->state = 7;
            sub_08126D34(c->seLR);
            return;
        }
        if (gKeysNew & 0x100)
        {
            c->state = 8;
            sub_08126D34(c->seLR);
            return;
        }
    }

    if (keys & 0x40)
    {
        if (c->rows != 1)
        {
            if (c->row == 0)
            {
                if (c->flags & 1)
                {
                    c->row = c->rows - 1;
                }
                else
                {
                    if (c->column == 0)
                        goto moved;
                    c->column--;
                    c->row = c->perColumn - 1;
                }
                sub_08126D34(c->seMove);
            }
            else
            {
                c->row--;
                sub_08126D34(c->seMove);
            }
        moved:
            c->state = 0xD;
        }
    }
    else if (keys & 0x80)
    {
        if (c->rows != 1)
        {
            if (c->row == c->rows - 1)
            {
                if (c->flags & 1)
                {
                    c->row = 0;
                }
                else
                {
                    if (c->column == c->columns - 1)
                        goto moved2;
                    c->column++;
                    c->row = 0;
                }
                sub_08126D34(c->seMove);
            }
            else
            {
                c->row++;
                if ((u16)(c->row + c->column * c->perColumn) <= c->count - 1)
                    sub_08126D34(c->seMove);
            }
        moved2:
            c->state = 0xD;
        }
    }
    else if (keys & 0x10)
    {
        if (c->columns != 1)
        {
            c->column += c->perColumn;
            /* `|` where `&` was meant: always wraps */
            if (c->column >= c->columns && (c->flags | 2))
                c->column = 0;
            c->state = 0xD;
            sub_08126D34(c->sePage);
        }
    }
    else if (keys & 0x20)
    {
        if (c->columns != 1)
        {
            if (c->column < c->perColumn)
            {
                if (c->flags | 2)
                    c->column = c->columns - 1;
            }
            else
            {
                c->column -= c->perColumn;
            }
            c->state = 0xD;
            sub_08126D34(c->sePage);
        }
    }

    if (c->mode == 1)
    {
        if (keys & 0x200)
        {
            if (c->columns == 1)
            {
                if (c->index < c->perColumn)
                {
                    if (c->column != 0 || c->row != 0 || c->top != 0)
                        sub_08126D34(c->sePage);
                    c->column = 0;
                    c->row = 0;
                    c->top = 0;
                }
                else
                {
                    c->column--;
                    c->top -= c->perColumn;
                    sub_08126D34(c->sePage);
                }
                c->state = 0xD;
            }
        }
        else if (keys & 0x100)
        {
            if (c->columns == 1)
            {
                if ((u16)(c->column * c->perColumn + c->row) < c->count - 1)
                    sub_08126D34(c->seMove);
                c->top += c->perColumn;
                c->column++;
                c->state = 0xD;
            }
        }
    }

    c->index = c->column * c->perColumn + c->row;
    if (c->index > c->count - 1)
        c->index = c->count - 1;
    c->column = c->index / c->perColumn;
    c->row = c->index % c->perColumn;
    if (c->index < c->top)
        c->top = c->index;
    else if (c->index > c->top + c->perColumn - 1)
        c->top = c->index + (1 - c->perColumn);
    if (c->top > c->count - c->perColumn)
        c->top = c->count - c->perColumn;
    c->onScreen = c->index - c->top;
}

// sub_08126D1C @ 0x08126D1C
struct MenuCursor *sub_08126D1C(u8 id)
{
    return &gUnk_03006480[id];
}

// sub_08126D34 @ 0x08126D34
void sub_08126D34(u16 se)
{
    if (se != 0xFFFF)
        m4aSongNumStart(se);
}

// sub_08126D50 @ 0x08126D50
void sub_08126D50(u8 id, u8 parts)
{
    u32 *buf;

    if ((u8)(id - 1) > 5)
        return;
    CpuFastSet(&gUnknown_08772534[gUnknown_08777D34[id]], buf = (u32 *)0x030012B4, 0x200);
    if (parts & 1)
        CpuFastSet(&gUnknown_08772534[0x200 + gUnknown_08777D34[id]], buf, 0x30);
    if (parts & 2)
        CpuFastSet(&gUnknown_08772534[0x230 + gUnknown_08777D34[id]], buf + 0x30, 0x60);
    if (parts & 4)
        CpuFastSet(&gUnknown_08772534[0x290 + gUnknown_08777D34[id]], buf + 0x90, 0x30);
    if (parts & 8)
        CpuFastSet(&gUnknown_08772534[0x2C0 + gUnknown_08777D34[id]], buf + 0xC0, 0x60);
    if (parts & 0x10)
        CpuFastSet(&gUnknown_08772534[0x320 + gUnknown_08777D34[id]], buf + 0x120, 0x30);
    Palette_CopyWithEffect(3, gUnknown_08772514, (void *)0x03002E10, 0x20, 0x20);
    Palette_MarkDirty();
    sub_080E5668(sub_08126F84);
}

// sub_08126E4C @ 0x08126E4C
#ifdef NONMATCHING
void sub_08126E4C(u8 unused, u8 parts)
{
    u16 *dst = (u16 *)0x03001AB4;
    u16 *dst2 = (u16 *)0x0200E294;
    const u16 *src = gUnknown_08771ED4;
    const u8 *gfx = gUnknown_08770ED4;
    const u16 *pal = gUnknown_08772514;
    u16 *palDst = (u16 *)0x03002E10;
    u8 i;

    CpuFastSet(gfx, (u8 *)dst - 0x800, 0x200);
    if (parts & 2)
        CpuFastSet(gfx + 0x9A0, (u8 *)dst - 0x1920, 0x20);
    if (parts & 4)
        CpuFastSet(gfx + 0xA40, (u8 *)dst - 0x1880, 0x20);
    for (i = 0; i < 0x40; i++)
        *dst++ = *dst2++ = *src++;
    Palette_CopyWithEffect(3, pal, palDst, 0x20, 0x20);
    Palette_MarkDirty();
    VBlankTask_AddCounted(sub_08126FEC, 1);
}
#else
NAKED
void sub_08126E4C(u8 unused, u8 parts)
{
    asm_unified(
        ".L08126E4C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    sub sp, #4\n"
        "    lsls r1, r1, #0x18\n"
        "    lsrs r1, r1, #0x18\n"
        "    mov r8, r1\n"
        "    ldr r4, .L08126EEC\n"
        "    ldr r7, .L08126EF0\n"
        "    ldr r5, .L08126EF4\n"
        "    ldr r6, .L08126EF8\n"
        "    ldr r0, .L08126EFC\n"
        "    adds r1, r4, r0\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #2\n"
        "    adds r0, r6, #0\n"
        "    bl CpuFastSet\n"
        "    movs r0, #2\n"
        "    mov r1, r8\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08126E8A\n"
        "    movs r2, #0x9a\n"
        "    lsls r2, r2, #4\n"
        "    adds r0, r6, r2\n"
        "    ldr r2, .L08126F00\n"
        "    adds r1, r4, r2\n"
        "    movs r2, #0x20\n"
        "    bl CpuFastSet\n"
        ".L08126E8A:\n"
        "    movs r0, #4\n"
        "    mov r1, r8\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08126EA4\n"
        "    movs r2, #0xa4\n"
        "    lsls r2, r2, #4\n"
        "    adds r0, r6, r2\n"
        "    ldr r2, .L08126F04\n"
        "    adds r1, r4, r2\n"
        "    movs r2, #0x20\n"
        "    bl CpuFastSet\n"
        ".L08126EA4:\n"
        "    movs r1, #0\n"
        "    ldr r2, .L08126F08\n"
        "    ldr r3, .L08126F0C\n"
        ".L08126EAA:\n"
        "    ldrh r0, [r5]\n"
        "    strh r0, [r7]\n"
        "    strh r0, [r4]\n"
        "    adds r5, #2\n"
        "    adds r7, #2\n"
        "    adds r4, #2\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r1, r0, #0x18\n"
        "    cmp r1, #0x3f\n"
        "    bls .L08126EAA\n"
        "    adds r4, r2, #0\n"
        "    adds r5, r3, #0\n"
        "    movs r0, #0x20\n"
        "    str r0, [sp]\n"
        "    movs r0, #3\n"
        "    adds r1, r4, #0\n"
        "    adds r2, r5, #0\n"
        "    movs r3, #0x20\n"
        "    bl Palette_CopyWithEffect\n"
        "    bl Palette_MarkDirty\n"
        "    ldr r0, .L08126F10\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    add sp, #4\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L08126EEC: .4byte 0x03001AB4 @ IWRAM+0x1AB4\n"
        ".L08126EF0: .4byte 0x0200E294 @ EWRAM+0xE294\n"
        ".L08126EF4: .4byte gUnknown_08771ED4\n"
        ".L08126EF8: .4byte gUnknown_08770ED4\n"
        ".L08126EFC: .4byte 0xFFFFF800\n"
        ".L08126F00: .4byte 0xFFFFE6E0\n"
        ".L08126F04: .4byte 0xFFFFE780\n"
        ".L08126F08: .4byte gUnknown_08772514\n"
        ".L08126F0C: .4byte 0x03002E10 @ IWRAM+0x2E10\n"
        ".L08126F10: .4byte sub_08126FEC\n"
    );
}
#endif

// sub_08126F14 @ 0x08126F14
void sub_08126F14(void)
{
    u16 *a = (u16 *)0x03001AB4;
    u16 *b = (u16 *)0x0200E214;
    u8 i;

    for (i = 0; i < 0x40; i++)
    {
        *b = 0;
        *a = 0;
        b++;
        a++;
    }
    VBlankTask_AddCounted(sub_08127090, 1);
}

// sub_08126F4C @ 0x08126F4C
void sub_08126F4C(void)
{
    u16 *a = (u16 *)0x03001AB4;
    u16 *b = (u16 *)0x0200E294;
    u8 i;

    for (i = 0; i < 0x40; i++)
    {
        *b = 0;
        *a = 0;
        b++;
        a++;
    }
    VBlankTask_AddCounted(sub_08127054, 1);
}

