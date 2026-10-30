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
u32 sub_08126928(u8 id, u8 type, u16 columns, u16 rows, u16 perColumn)
{
    struct MenuCursor c;

    c.state = 1;
    c.delay = 0;
    c.mode = (type & 0xF0) >> 4;
    c.flags = type & 0xF;
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
    c.seMove = c.sePage = 0x64;
    c.seA = 0x65;
    c.seB = 0x66;
    c.seLR = c.seStart = c.seSelect = 0xFFFF;
    return ((s32 (*)(u8, struct MenuCursor *))sub_081268E4)(id, &c);
}

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

/* Copies graphics (parts bits 1 and 2 add two more blocks) and 0x40 map entries to two
   buffers, then fades in palette gUnknown_08772514. */
extern u16 gUnk_03001AB4[];
extern u16 gUnk_03002E10[];

// sub_08126E4C @ 0x08126E4C
void sub_08126E4C(u8 unused, u8 parts)
{
    u16 *dst = gUnk_03001AB4;
    u16 *dst2 = (u16 *)0x0200E294;
    u16 *src = (u16 *)gUnknown_08771ED4;
    const u8 *gfx = gUnknown_08770ED4;
    u8 i;

    CpuFastSet(gfx, (u8 *)dst - 0x800, 0x200);
    if (parts & 2)
        CpuFastSet(gfx + 0x9A0, (u8 *)dst - 0x1920, 0x20);
    if (parts & 4)
        CpuFastSet(gfx + 0xA40, (u8 *)dst - 0x1880, 0x20);
    i = 0;
    {
        u16 *pal = (u16 *)gUnknown_08772514;
        u16 *palDst = gUnk_03002E10;

        for (; i < 0x40; i++)
            *dst++ = *dst2++ = *src++;
        dst = pal;
        src = palDst;
    }
    Palette_CopyWithEffect(3, dst, src, 0x20, 0x20);
    Palette_MarkDirty();
    VBlankTask_AddCounted(sub_08126FEC, 1);
}

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

