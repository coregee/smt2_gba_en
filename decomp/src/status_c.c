#include "global.h"
#include "status.h"

// sub_080CA684 @ 0x080CA684
void sub_080CA684(void)
{
    struct C0c6Status *st = &gMenuState;

    st->page = 0;
    st->unk06 = 0;
    st->unk08 = 0;
}

// sub_080CA694 @ 0x080CA694
/* Steps the shown entry forwards (dir > 0) or backwards through the count entries; in mode 1
   with flag 0xB6 it skips entries sub_080C2554 rejects. */
void sub_080CA694(s16 dir, u32 count)
{
    struct C0c6Status *st = &gMenuState;

    if (dir > 0)
    {
    next:
        if (st->sel != count - 1)
            st->sel++;
        else
            st->sel = 0;
        if (st->mode != 1)
            return;
        if (!Flag_Test(0xB6) || sub_080C2554(Status_GetCombatant(st->sel)->demonId) != 0)
            goto done;
        goto next;
    }
    else
    {
    prev:
        if (st->sel != 0)
            st->sel--;
        else
            st->sel = count - 1;
        if (st->mode != 1)
            return;
        if (Flag_Test(0xB6) && sub_080C2554(Status_GetCombatant(st->sel)->demonId) == 0)
            goto prev;
    }
done:
    gSavedMenuCursor[9] = st->sel;
}

// sub_080CA718 @ 0x080CA718
/* Input on the status screen: A (or Down for demons) picks, B leaves, L/R step through the
   list. The result goes to t->pad1E. */
void sub_080CA718(struct Task *t)
{
    struct C0c6Status *st = &gMenuState;
    u32 count;
    u32 count1;
    u16 key;
    u16 se;

    Status_GetCombatant(st->sel);
    count = sub_080C964C(0);
    count1 = sub_080C964C(1);
    t->pad1E = 0;
    if (sub_080C9388(st->sel) == 1)
    {
        key = 1;
        se = 0x65;
    }
    else
    {
        key = 0x80;
        se = 0x64;
        sub_080C4AB0(0, 0, 0x92, 0x76);
    }
    if (gKeysNew & key)
    {
        if (sub_080C93B4(st->sel) == 1)
        {
            Sound_Play(se);
            t->pad1E = 0x8001;
        }
        else if (sub_080C9388(st->sel) == 1)
        {
            Sound_Play(se);
            t->pad1E = 0x8002;
        }
        else
        {
            Sound_Play(se);
            t->pad1E = 0x8003;
        }
    }
    else if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        t->pad1E = 3;
    }
    else if ((gKeysNew & 0x200) && st->unk22 == 0 && count1 != 1)
    {
        Sound_Play(0x64);
        sub_080CA694(-1, count);
        st->unk0A = 0xFFF0;
        t->pad1E = 2;
        sub_080CA684();
    }
    else if ((gKeysNew & 0x100) && st->unk22 == 0 && count1 != 1)
    {
        Sound_Play(0x64);
        sub_080CA694(1, count);
        st->unk0A = 0x10;
        t->pad1E = 2;
        sub_080CA684();
    }
}

// Inventory_ListRange @ 0x080CA84C
/* Lists the ids in [lo, hi] of the held inventory entries into gUnk_0203B454; returns the count. */
u16 Inventory_ListRange(u16 lo, u16 hi)
{
    u16 *out = gUnk_0203B454;
    u16 n = 0;
    u16 i;

    for (i = 0; i < 0x15A; i++)
    {
        struct C0c2InvEntry *e = &gInventory[i];

        if (e->count != 0 && e->id >= lo && e->id <= hi)
        {
            out[n] = e->id;
            n++;
        }
    }
    return n;
}

// sub_080CA8A4 @ 0x080CA8A4
void sub_080CA8A4(u16 lo, u16 hi)
{
    struct C0c6Status *st = &gMenuState;
    vu16 fill = 0xFFFF;

    CpuSet((void *)&fill, gUnk_0203B454, 0x01000080);
    st->unk28 = Inventory_ListRange(lo, hi);
}

// sub_080CA8EC @ 0x080CA8EC
/* The item category grid (2x2): A lists the category's items, B leaves. */
void sub_080CA8EC(struct Task *t)
{
    struct C0c6Status *st = &gMenuState;
    u16 x;
    u16 y;

    t->pad1E = 0;
    if (gKeysNew & 1)
    {
        switch (st->unk2C)
        {
        case 0:
            sub_080CA8A4(0x120, 0x12B);
            break;
        case 1:
            sub_080CA8A4(0x100, 0x11F);
            break;
        case 2:
            sub_080CA8A4(0xD0, 0xFF);
            break;
        case 3:
            sub_080CA8A4(0x12C, 0x159);
            break;
        }
        if (st->unk28 == 0)
            Sound_Play(0x68);
        else
        {
            Sound_Play(0x65);
            t->pad1E = 1;
            st->unk2E = 0;
            st->unk2C = 0;
        }
        return;
    }
    if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        t->pad1E = 2;
    }
    else if ((gKeysNew & 0x40) || (gKeysNew & 0x80))
    {
        Sound_Play(0x64);
        if (st->unk2C == 0)
            st->unk2C = 2;
        else if (st->unk2C == 1)
            st->unk2C = 3;
        else if (st->unk2C == 2)
            st->unk2C = 0;
        else if (st->unk2C == 3)
            st->unk2C = 1;
    }
    else if (gKeysNew & 0x20)
    {
        Sound_Play(0x64);
        if (st->unk2C != 0)
            st->unk2C--;
        else
            st->unk2C = 3;
    }
    else if (gKeysNew & 0x10)
    {
        Sound_Play(0x64);
        if (st->unk2C != 3)
            st->unk2C++;
        else
            st->unk2C = 0;
    }
    switch (st->unk2C)
    {
    case 0:
        x = 6;
        y = 0x82;
        break;
    case 1:
        x = 0x84;
        y = 0x82;
        break;
    case 2:
        x = 6;
        y = 0x8E;
        break;
    case 3:
        x = 0x84;
        y = 0x8E;
        break;
    }
    sub_080C49EC(10, 0, 2, x, y);
}

// sub_080CAA78 @ 0x080CAA78
/* The item list (7 rows): Up/Down move, L/R page (L by 6 rows, R by 7). */
void sub_080CAA78(struct Task *t)
{
    struct C0c6Status *st = &gMenuState;
    u16 n = st->unk28;
    u32 redraw = 0;
    u16 rows;

    t->pad1E = 0;
    rows = n;
    if (n > 6)
        rows = 7;
    if (gKeysNew & 1)
    {
        Sound_Play(0x65);
        t->pad1E = 1;
        st->unk1C = 0;
        st->unk1E = 0;
    }
    else if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        t->pad1E = 2;
    }
    else if (gRepeatedKeys & 0x40)
    {
        Sound_Play(0x64);
        if (st->unk2C != 0)
            st->unk2C--;
        else if (st->unk2E != 0)
        {
            st->unk2E--;
            redraw = 1;
        }
    }
    else if (gRepeatedKeys & 0x80)
    {
        Sound_Play(0x64);
        if (st->unk2C != rows - 1)
            st->unk2C++;
        else if (st->unk2C == 6 && st->unk2C + st->unk2E + 1 <= n - 1)
        {
            st->unk2E++;
            redraw = 1;
        }
    }
    else if ((gRepeatedKeys & 0x200) && n > 7)
    {
        Sound_Play(0x64);
        if (st->unk2C != 0)
            st->unk2C = 0;
        else
        {
            redraw = 1;
            if (st->unk2E > 5)
                st->unk2E -= 6;
            else
                st->unk2E = 0;
        }
    }
    else if ((gRepeatedKeys & 0x100) && n > 7)
    {
        Sound_Play(0x64);
        if (st->unk2C != 6)
            st->unk2C = 6;
        else
        {
            redraw = 1;
            if (st->unk2C + st->unk2E + 7 < n - 1)
                st->unk2E += 7;
            else
                st->unk2E = n - 7;
        }
    }
    if (redraw == 1)
    {
        sub_080C9CD8(t);
        sub_080C9BCC(t);
    }
    sub_080C49EC(0xF, 0, 2, 10, st->unk2C * 15 + 0x14);
    if (st->unk2E != 0)
        st->unk1C = 1;
    if (st->unk2E + 7 <= n - 1)
        st->unk1E = 1;
}

// sub_080CAC00 @ 0x080CAC00
/* The skill page: A lists the combatant's skills (at most 32, 0xFF ends them). */
#ifdef NONMATCHING
void sub_080CAC00(struct Task *t)
{
    struct C0c6Status *st = &gMenuState;
    struct Combatant *c = Status_GetCombatant(st->sel);
    u16 n = 0;

    t->pad1E = n;
    if (gKeysNew & 1)
    {
        vu16 fill = 0xFFFF;
        u16 i;

        CpuSet((void *)&fill, gUnk_0203B454, 0x01000080);
        for (i = 0; c->skills[i] != 0xFF; )
        {
            gUnk_0203B454[n] = c->skills[i];
            n++;
            st->unk28 = n;
            i++;
            if (i > 0x1F)
                break;
        }
        if (st->unk28 != 0)
        {
            Sound_Play(0x65);
            t->pad1E = 1;
            st->unk2E = 0;
            st->unk2C = 0;
        }
        return;
    }
    if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        t->pad1E = 2;
    }
    sub_080C49EC(10, 0, 2, 6, 0x82);
}
#else
NAKED
void sub_080CAC00(struct Task *t)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    sub sp, #8\n"
        "    adds r7, r0, #0\n"
        "    ldr r0, .L080CAC90\n"
        "    mov r8, r0\n"
        "    ldrh r0, [r0, #2]\n"
        "    bl Status_GetCombatant\n"
        "    adds r6, r0, #0\n"
        "    movs r5, #0\n"
        "    strh r5, [r7, #0x1e]\n"
        "    ldr r2, .L080CAC94\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080CACA4\n"
        "    add r1, sp, #4\n"
        "    ldr r2, .L080CAC98\n"
        "    adds r0, r2, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r4, .L080CAC9C\n"
        "    ldr r2, .L080CACA0\n"
        "    adds r0, r1, #0\n"
        "    adds r1, r4, #0\n"
        "    bl CpuSet\n"
        "    movs r2, #0\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x5d\n"
        "    ldrb r1, [r0]\n"
        "    adds r3, r0, #0\n"
        "    cmp r1, #0xff\n"
        "    beq .L080CAC74\n"
        "    adds r6, r3, #0\n"
        "    mov ip, r4\n"
        ".L080CAC4C:\n"
        "    lsls r1, r5, #1\n"
        "    adds r1, r1, r4\n"
        "    adds r0, r6, r2\n"
        "    ldrb r0, [r0]\n"
        "    strh r0, [r1]\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    mov r0, r8\n"
        "    strh r5, [r0, #0x28]\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #0x1f\n"
        "    bhi .L080CAC74\n"
        "    mov r4, ip\n"
        "    adds r0, r3, r2\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0xff\n"
        "    bne .L080CAC4C\n"
        ".L080CAC74:\n"
        "    mov r1, r8\n"
        "    ldrh r0, [r1, #0x28]\n"
        "    cmp r0, #0\n"
        "    beq .L080CACC8\n"
        "    movs r0, #0x65\n"
        "    bl Sound_Play\n"
        "    movs r1, #0\n"
        "    movs r0, #1\n"
        "    strh r0, [r7, #0x1e]\n"
        "    mov r2, r8\n"
        "    strh r1, [r2, #0x2e]\n"
        "    strh r1, [r2, #0x2c]\n"
        "    b .L080CACC8\n"
        ".L080CAC90: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L080CAC94: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L080CAC98: .4byte 0x0000FFFF\n"
        ".L080CAC9C: .4byte 0x0203B454 @ EWRAM+0x3B454\n"
        ".L080CACA0: .4byte 0x01000080\n"
        ".L080CACA4:\n"
        "    ldrh r1, [r2]\n"
        "    movs r4, #2\n"
        "    adds r0, r4, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080CACB8\n"
        "    movs r0, #0x66\n"
        "    bl Sound_Play\n"
        "    strh r4, [r7, #0x1e]\n"
        ".L080CACB8:\n"
        "    movs r0, #0x82\n"
        "    str r0, [sp]\n"
        "    movs r0, #0xa\n"
        "    movs r1, #0\n"
        "    movs r2, #2\n"
        "    movs r3, #6\n"
        "    bl sub_080C49EC\n"
        ".L080CACC8:\n"
        "    add sp, #8\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

// sub_080CACD4 @ 0x080CACD4
/* The skill list: like sub_080CAA78 without clearing the arrows on A. */
void sub_080CACD4(struct Task *t)
{
    struct C0c6Status *st = &gMenuState;
    u16 n = st->unk28;
    u32 redraw = 0;
    u16 rows;

    t->pad1E = redraw;
    rows = n;
    if (n > 6)
        rows = 7;
    if (gKeysNew & 1)
    {
        Sound_Play(0x65);
        t->pad1E = 1;
    }
    else if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        t->pad1E = 2;
    }
    else if (gRepeatedKeys & 0x40)
    {
        Sound_Play(0x64);
        if (st->unk2C != 0)
            st->unk2C--;
        else if (st->unk2E != 0)
        {
            st->unk2E--;
            redraw = 1;
        }
    }
    else if (gRepeatedKeys & 0x80)
    {
        Sound_Play(0x64);
        if (st->unk2C != rows - 1)
            st->unk2C++;
        else if (st->unk2C == 6 && st->unk2C + st->unk2E + 1 <= n - 1)
        {
            st->unk2E++;
            redraw = 1;
        }
    }
    else if ((gRepeatedKeys & 0x200) && n > 7)
    {
        Sound_Play(0x64);
        if (st->unk2C != 0)
            st->unk2C = 0;
        else
        {
            redraw = 1;
            if (st->unk2E > 5)
                st->unk2E -= 6;
            else
                st->unk2E = 0;
        }
    }
    else if ((gRepeatedKeys & 0x100) && n > 7)
    {
        Sound_Play(0x64);
        if (st->unk2C != 6)
            st->unk2C = 6;
        else
        {
            redraw = 1;
            if (st->unk2C + st->unk2E + 7 < n - 1)
                st->unk2E += 7;
            else
                st->unk2E = n - 7;
        }
    }
    if (redraw == 1)
    {
        sub_080C9CD8(t);
        sub_080C9BCC(t);
    }
    sub_080C49EC(0xF, 0, 2, 10, st->unk2C * 15 + 0x14);
    if (st->unk2E != 0)
        st->unk1C = 1;
    if (st->unk2E + 7 <= n - 1)
        st->unk1E = 1;
}

// sub_080CAE68 @ 0x080CAE68
void sub_080CAE68(struct Task *t)
{
    t->pad1E = 0;
    if (gKeysNew & 0x80)
    {
        Sound_Play(0x64);
        t->pad1E = 1;
    }
    else if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        t->pad1E = 2;
    }
    else if (gKeysNew & 0x40)
    {
        Sound_Play(0x64);
        t->pad1E = 2;
    }
    sub_080C4A4C(0, 0, 0x92, 0x14);
}

// sub_080CAEC0 @ 0x080CAEC0
void sub_080CAEC0(struct Task *t)
{
    t->pad1E = 0;
    if (gKeysNew & 1)
        return;
    if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        t->pad1E = 2;
    }
    else if (gKeysNew & 0x40)
    {
        Sound_Play(0x64);
        t->pad1E = 3;
    }
}

// sub_080CAF0C @ 0x080CAF0C
/* Scrolls BG0/BG1 by st->unk0A and moves the demon sprite along. */
void sub_080CAF0C(void)
{
    struct C0c6Status *st = &gMenuState;
    struct Task *sprite = st->sprite;

    gUnk_03000004 += st->unk0A;
    gUnk_03000008 += st->unk0A;
    if (sprite != NULL)
        sub_080C3E5C(sprite, -gUnk_03000004, 0x18);
}

// sub_080CAF48 @ 0x080CAF48
void sub_080CAF48(struct Task *t, u16 v)
{
    gMenuState.page = v;
}

// sub_080CAF54 @ 0x080CAF54
void sub_080CAF54(struct Task *t, u16 v)
{
    gMenuState.unk06 = v;
}

// sub_080CAF60 @ 0x080CAF60
void sub_080CAF60(struct Task *t, u16 v)
{
    gMenuState.unk08 = v;
}

// Status_Close @ 0x080CAF6C
/* Closes the status screen: removes the demon sprite and the windows. */
void Status_Close(void)
{
    struct C0c6Status *st = &gMenuState;

    if (st->sprite != NULL)
    {
        DemonObj_End(st->sprite, 0);
        st->sprite = NULL;
    }
    TextWindow_Close(st->window40, 1);
    TextWindow_Close(st->window44, 1);
    TextWindow_Close(st->window48, 1);
    st->fade->unkC = 1;
    Font_ResetGlyphSpriteCache(0x180);
}

// sub_080CAFB0 @ 0x080CAFB0
void sub_080CAFB0(struct Task *t)
{
    if (gMenuState.fade->unk0 != 0)
        t->result = 0;
    else
        t->result = 1;
}

// sub_080CAFD0 @ 0x080CAFD0
/* Opens the status screen in mode 0 on list entry sel. */
struct Task *sub_080CAFD0(struct Task *parent, u16 sel)
{
    struct Task *t = Task_Create(gUnknown_084EFB44, 0xFFFF);
    struct C0c6Status *st = &gMenuState;
    u32 zero = 0;

    CpuSet(&zero, st, 0x05000200);
    st->sel = sel;
    st->mode = 0;
    st->unk22 = 0;
    return t;
}

// sub_080CB01C @ 0x080CB01C
/* Same in mode 1. */
struct Task *sub_080CB01C(struct Task *parent, u16 sel)
{
    struct Task *t = Task_Create(gUnknown_084EFB44, 0xFFFF);
    struct C0c6Status *st = &gMenuState;
    u32 zero = 0;

    CpuSet(&zero, st, 0x05000200);
    st->sel = sel;
    st->mode = 1;
    st->unk22 = 0;
    return t;
}

// sub_080CB068 @ 0x080CB068
void sub_080CB068(void)
{
    struct C0c6Status *st = &gMenuState;

    Canvas_FillRect(0, gUnk_0200F874, 0x30, 0x74, 0x6C, 0xE);
    Text_DrawString(gUnknown_084F00C8, gUnk_0200F874, 0x30, 0x74, 12);
    DigitFont_DrawNumber(st->unk36, 0x88, 0x77, 0);
    sub_080C9994();
}
