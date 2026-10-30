#include "global.h"
#include "battle2.h"

// sub_080F4504 @ 0x080F4504
u32 sub_080F4504(void)
{
    return 5;
}

// sub_080F4508 @ 0x080F4508
void sub_080F4508(void)
{
}

// sub_080F450C @ 0x080F450C
void sub_080F450C(s32 *a, s32 *b)
{
    u8 *e = sub_080C5D98();
    u8 g = e[2];

    if (e[1] && !Flag_Test(e[1]))
        g = e[3];
    if (g == 0xFF)
    {
        *b = 0;
        *a = 0;
    }
    else
        sub_080ED35C(a, b, g);
}

// Item_GetSlotMask @ 0x080F4548
/* Equipment slot bit of an item id (1 = weapon ... 0x40), 0x200/0x400 for usable items with
   the 0xC0 / 0x20 attribute bits, 0x100 / 0x80 above 0xFE. */
s32 Item_GetSlotMask(s32 item)
{
    s32 attr;
    s32 r;

    if (item <= 0x57)
        return 1;
    if (item <= 0x6F)
        return 2;
    if (item <= 0x7F)
        return 4;
    if (item <= 0x93)
        return 8;
    if (item <= 0xA7)
        return 0x10;
    if (item <= 0xBB)
        return 0x20;
    if (item <= 0xCF)
        return 0x40;
    if (item <= 0xFE)
    {
        Item_GetAttribute(item, 10, &attr);
        r = (attr & 0xC0) ? 0x200 : 0;
        if (attr & 0x20)
            r |= 0x400;
        return r;
    }
    if (item <= 0x11B)
        return 0x100;
    return 0x80;
}

// Party_CountDemons @ 0x080F45D4
/* Number of demons (member index > 3) in the active party. */
s16 Party_CountDemons(void)
{
    s16 n = 0;
    s16 i;

    for (i = 0; i < 6; i++)
    {
        if (sub_080F40EC(i) > 3)
            n++;
    }
    return n;
}

// sub_080F4608 @ 0x080F4608
void sub_080F4608(u16 kind, u16 arg)
{
    u16 x;
    u16 y;
    s16 w = 5;
    s16 k = kind;

    if (k <= 3)
    {
        switch (k)
        {
        case 0:
            x = 0x50;
            y = 0;
            break;
        case 1:
            x = 0x50;
            y = 0;
            break;
        case 2:
            x = 0x58;
            w = 8;
            y = 0;
            break;
        case 3:
            x = 0x5A;
            y = 0xF;
            break;
        }
    }
    else
    {
        kind = k - 4;
        x = 0x50;
        y = 0xF;
    }
    Battle_StartPaletteFlash((s16)kind, (s16)x, (s16)y, w, (s16)arg);
}

// Battle_StartPaletteFlash @ 0x080F4670
void Battle_StartPaletteFlash(s32 kind_, s32 x_, s32 y_, s32 w_, s32 arg_)
{
    u16 kind = kind_;
    u16 x = x_;
    u16 y = y_;
    u16 w = w_;
    u16 arg = arg_;
    struct Task *t = Task_Create(gUnknown_0876F89C, 0xFFFF);
    u16 *d = t->data.h;

    d[1] = arg;
    {
        s32 v;
        if (kind == 3)
        {
            s32 ww = (s16)w * 2;
            v = (s16)x - ww;
        }
        else
            v = 0;
        d[2] = v;
    }
    d[0] = w;
    d[5] = y;
    d[3] = kind;
    d[4] = x;
    CpuFastSet(gPaletteBuffer, gUnk_0203D600, 0x80);
}

// Palette_CopyBrightened @ 0x080F46E0
/* Copies n colours adding (dr, dg, db) >> 3 to each channel, saturating at 31. */
#ifdef NONMATCHING
void Palette_CopyBrightened(u16 *src, u16 *dst, u16 n, u16 dr, u16 dg, u16 db)
{
    u16 i;
    u16 *s = src;
    u16 *d = dst;

    for (i = 0; i < n; i++)
    {
        u16 c;
        u16 r;
        u16 g;
        u16 b;

        c = *s++;
        r = c & 0x1F;
        g = (c & 0x3E0) >> 5;
        b = (c & 0x7C00) >> 10;

        r += dr >> 3;
        if (r > 31)
            r = 31;
        g += dg >> 3;
        if (g > 31)
            g = 31;
        b += db >> 3;
        if (b > 31)
            b = 31;
        *d++ = r + (g << 5) + (b << 10);
    }
}
#else
NAKED
void Palette_CopyBrightened(u16 *src, u16 *dst, u16 n, u16 dr, u16 dg, u16 db)
{
    asm_unified(
        ".L080F46E0:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #4\n"
        "    ldr r4, [sp, #0x24]\n"
        "    ldr r5, [sp, #0x28]\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    str r2, [sp]\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    mov sb, r3\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    mov r8, r4\n"
        "    lsls r5, r5, #0x10\n"
        "    lsrs r5, r5, #0x10\n"
        "    mov ip, r5\n"
        "    adds r5, r0, #0\n"
        "    adds r4, r1, #0\n"
        "    movs r6, #0\n"
        "    cmp r6, r2\n"
        "    bhs .L080F4774\n"
        "    movs r0, #0xf8\n"
        "    lsls r0, r0, #7\n"
        "    mov sl, r0\n"
        ".L080F4718:\n"
        "    ldrh r1, [r5]\n"
        "    adds r5, #2\n"
        "    movs r3, #0x1f\n"
        "    ands r3, r1\n"
        "    adds r0, r1, #0\n"
        "    movs r2, #0xf8\n"
        "    lsls r2, r2, #2\n"
        "    ands r0, r2\n"
        "    lsrs r2, r0, #5\n"
        "    mov r7, sl\n"
        "    ands r1, r7\n"
        "    lsrs r1, r1, #0xa\n"
        "    mov r7, sb\n"
        "    lsrs r0, r7, #3\n"
        "    adds r3, r3, r0\n"
        "    cmp r3, #0x1f\n"
        "    bls .L080F473C\n"
        "    movs r3, #0x1f\n"
        ".L080F473C:\n"
        "    mov r7, r8\n"
        "    lsrs r0, r7, #3\n"
        "    adds r0, r2, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #0x1f\n"
        "    bls .L080F474C\n"
        "    movs r2, #0x1f\n"
        ".L080F474C:\n"
        "    mov r7, ip\n"
        "    lsrs r0, r7, #3\n"
        "    adds r0, r1, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    cmp r1, #0x1f\n"
        "    bls .L080F475C\n"
        "    movs r1, #0x1f\n"
        ".L080F475C:\n"
        "    lsls r0, r2, #5\n"
        "    adds r0, r3, r0\n"
        "    lsls r1, r1, #0xa\n"
        "    adds r0, r0, r1\n"
        "    strh r0, [r4]\n"
        "    adds r4, #2\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldr r0, [sp]\n"
        "    cmp r6, r0\n"
        "    blo .L080F4718\n"
        ".L080F4774:\n"
        "    add sp, #4\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

// Battle_PaletteFlashTask @ 0x080F4784
/* Task callback of Battle_StartPaletteFlash: pulses the background palette towards a tint (by kind)
   and restores the saved palette when the level returns to 0 (t->result = 1). */
void Battle_PaletteFlashTask(struct Task *t)
{
    s16 *d = (s16 *)t->data.h;

    t->result = 0;
    if (--d[5] > 0)
        return;
    d[2] += d[0];
    if (d[2] >= d[4])
        d[0] *= -1;
    if (d[2] == 0)
    {
        t->result = 1;
        CpuFastSet(gUnk_0203D600, gPaletteBuffer, 0x80);
        Palette_MarkDirty();
        return;
    }
    switch (d[3])
    {
    case 0:
        Palette_CopyBrightened(gUnk_0203D600 + 0x80, gPaletteBuffer + 0x80, 0x80, d[2] * 3, 0, 0);
        break;
    case 1:
        Palette_CopyBrightened(gUnk_0203D600 + 0x80, gPaletteBuffer + 0x80, 0x80, d[2] >> 2, d[2] >> 2, d[2] * 3);
        break;
    case 3:
        Palette_CopyBrightened(gUnk_0203D600 + 0x80, gPaletteBuffer + 0x80, 0x80, d[2] * 2, d[2] * 2, d[2] * 2);
        break;
    case 4:
        Palette_CopyBrightened(gUnk_0203D600 + 0x80, gPaletteBuffer + 0x80, 0x80, d[2] * 8 / 10 * 3, 0, d[2] * 3);
        break;
    case 5:
        Palette_CopyBrightened(gUnk_0203D600 + 0x80, gPaletteBuffer + 0x80, 0x80, d[2] * 8 / 10 * 2, d[2] * 8 / 10 * 2, 0);
        break;
    case 2:
        if (d[2] == 0x30)
            Palette_CopyBrightened(gUnk_0203D600 + 0x80, gPaletteBuffer + 0x80, 0x80, 0xA0, 0xA0, 0xA0);
        else
            Palette_CopyBrightened(gUnk_0203D600 + 0x80, gPaletteBuffer + 0x80, 0x80, d[2] * 40 / 52 * 2, d[2] * 34 / 52 * 2, d[2] * 2);
        break;
    }
    Palette_MarkDirty();
}

// sub_080F4968 @ 0x080F4968
s32 sub_080F4968(void)
{
    s32 n = 0;
    s32 i;

    for (i = 0; i < 4; i++)
    {
        if (Combatant_IsUsed(i))
            n++;
    }
    return n;
}

// sub_080F4988 @ 0x080F4988
void sub_080F4988(struct Action *a, s32 kind)
{
    s32 k = kind - 0x1D;

    if (k >= 0)
    {
        a->msg = -1;
        a->unkC = 1;
        gUnknown_0876F940[k](a);
    }
}

// sub_080F49B4 @ 0x080F49B4
void sub_080F49B4(struct Action *a, s32 i)
{
    a->msg = -1;
    a->unkC = 1;
    gUnknown_0876F8C0[i](a);
}

// sub_080F49D4 @ 0x080F49D4
void sub_080F49D4(s32 changed, struct Action *a)
{
    if (changed)
    {
        a->msg = 0x96;
        a->unkC = 0;
    }
}

// sub_080F49E8 @ 0x080F49E8
void sub_080F49E8(struct Action *a)
{
    sub_080F40C4(Combatant_GetDemonId(a->def));
    sub_080F49D4(sub_080EFD14(a->def, -1), a);
}

// sub_080F4A10 @ 0x080F4A10
void sub_080F4A10(struct Action *a)
{
    sub_080F40C4(Combatant_GetDemonId(a->def));
    sub_080F49D4(sub_080EFD5C(a->def, -1), a);
}

// sub_080F4A38 @ 0x080F4A38
void sub_080F4A38(struct Action *a)
{
    sub_080F40C4(Combatant_GetDemonId(a->def));
    sub_080F49D4(sub_080EFDA4(a->def, -1), a);
}

// sub_080F4A60 @ 0x080F4A60
/* Cancels the positive battle modifiers (rows 1-4) of the defender's whole side. */
void sub_080F4A60(struct Action *a)
{
    s32 n = 0;
    s32 who = a->def;
    s8 *order;
    s32 i;
    s32 v;

    if (who <= 15)
    {
        for (i = 0, order = gUnk_030050E0; i < 6; i++)
        {
            if (*(s8 *)(i + (u32)order) == -1)
                continue;
            who = order[i];
            if ((v = sub_080EFBFC(who)) > 0)
            {
                n++;
                sub_080EFD28(who, -v);
            }
            if ((v = sub_080EFD3C(who)) > 0)
            {
                n++;
                sub_080EFD70(who, -v);
            }
            if ((v = sub_080EFD84(who)) > 0)
            {
                n++;
                sub_080EFDB8(who, -v);
            }
            if ((v = sub_080EFDCC(who)) > 0)
            {
                n++;
                sub_080EFDEC(who, -v);
            }
        }
    }
    else
    {
        for (i = 0; i < 8; i++)
        {
            who = i + 0x10;
            if ((v = sub_080EFBFC(who)) > 0)
            {
                n++;
                sub_080EFD28(who, -v);
            }
            if ((v = sub_080EFD3C(who)) > 0)
            {
                n++;
                sub_080EFD70(who, -v);
            }
            if ((v = sub_080EFD84(who)) > 0)
            {
                n++;
                sub_080EFDB8(who, -v);
            }
            if ((v = sub_080EFDCC(who)) > 0)
            {
                n++;
                sub_080EFE00(who, -v);
            }
        }
    }
    if (n == 0)
        a->unkC = n;
}

// sub_080F4B54 @ 0x080F4B54
/* Cancels the negative battle modifiers (rows 1-3) of the attacker's whole side. */
void sub_080F4B54(struct Action *a)
{
    s32 n = 0;
    s32 who = a->att;
    s32 i;
    s32 v;
    s8 *order;

    if (who <= 15)
    {
        for (i = 0, order = gUnk_030050E0; i < 6; i++)
        {
            if (*(s8 *)(i + (u32)order) == -1)
                continue;
            who = order[i];
            if ((v = sub_080EFBFC(who)) < 0)
            {
                n++;
                sub_080EFD28(who, -v);
            }
            if ((v = sub_080EFD3C(who)) < 0)
            {
                n++;
                sub_080EFD70(who, -v);
            }
            if ((v = sub_080EFD84(who)) < 0)
            {
                n++;
                sub_080EFDB8(who, -v);
            }
        }
    }
    else
    {
        for (i = 0; i < 8; i++)
        {
            who = i + 0x10;
            if ((v = sub_080EFBFC(who)) < 0)
            {
                n++;
                sub_080EFD28(who, -v);
            }
            if ((v = sub_080EFD3C(who)) < 0)
            {
                n++;
                sub_080EFD70(who, -v);
            }
            if ((v = sub_080EFD84(who)) < 0)
            {
                n++;
                sub_080EFDB8(who, -v);
            }
        }
    }
    if (n == 0)
        a->unkC = n;
}

// sub_080F4C20 @ 0x080F4C20
void sub_080F4C20(struct Action *a)
{
    sub_080F4C90(a, 0x20, 0x330);
}

// sub_080F4C30 @ 0x080F4C30
void sub_080F4C30(struct Action *a)
{
    sub_080F49D4(sub_080EFD14(a->att, 1), a);
}
