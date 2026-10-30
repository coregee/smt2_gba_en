#include "global.h"
#include "options.h"

// sub_080E1534 @ 0x080E1534
void sub_080E1534(void)
{
    sub_081269B0(1);
}

// LinkTrade_IsDemonOffered @ 0x080E1540
/* TRUE when demon id is offered. */
u8 LinkTrade_IsDemonOffered(struct C0cdLinkData *d, u16 id)
{
    u16 i;

    for (i = 0; i < 12; i++)
    {
        if (d->demons[i] == id)
            return TRUE;
    }
    return FALSE;
}

// sub_080E156C @ 0x080E156C
/* TRUE when all twelve demon offer slots are used. */
u8 sub_080E156C(struct C0cdLinkData *d)
{
    if (d->demonCount > 11)
        return TRUE;
    return FALSE;
}

// LinkTrade_AddDemonOffer @ 0x080E1580
u8 LinkTrade_AddDemonOffer(struct C0cdLinkData *d, u16 id)
{
    u16 i;

    if (sub_080E156C(d))
        return FALSE;
    for (i = 0; i < 12; i++)
    {
        if (d->demons[i] == 0xFFFF)
        {
            d->demons[i] = id;
            d->demonCount++;
            return TRUE;
        }
    }
    return FALSE;
}

// LinkTrade_RemoveDemonOffer @ 0x080E15CC
u8 LinkTrade_RemoveDemonOffer(struct C0cdLinkData *d, u16 id)
{
    u16 i;

    for (i = 0; i < 12; i++)
    {
        if (d->demons[i] == id)
        {
            d->demons[i] |= 0xFFFF;
            d->demonCount--;
            return TRUE;
        }
    }
    return FALSE;
}

// LinkTrade_ClearDemonOffers @ 0x080E1610
void LinkTrade_ClearDemonOffers(struct C0cdLinkData *d)
{
    u16 i;

    d->demonCount = 0;
    for (i = 0; i < 12; i++)
        d->demons[i] |= 0xFFFF;
}

// sub_080E1644 @ 0x080E1644
/* Draws a page of d's offered demons (names, 8 glyphs); those whose bit is set in
   marks->unk56 are tinted with palette 2.  "NOTHING!" when there are none. */
void sub_080E1644(struct C0cdLinkData *d, struct C0cdLinkData *marks)
{
    u16 name[9];
    u16 row;
    u16 i, j;
    struct MenuCursor *menu;

    memset(name, 0, sizeof(name));
    row = 0;
    if (d->demonCount == 0)
    {
        SpriteFont_DrawAscii('N', 0xF, 0x6C, 0x2A);
        SpriteFont_DrawAscii('O', 0xF, 0x74, 0x2A);
        SpriteFont_DrawAscii('T', 0xF, 0x7C, 0x2A);
        SpriteFont_DrawAscii('H', 0xF, 0x84, 0x2A);
        SpriteFont_DrawAscii('I', 0xF, 0x8C, 0x2A);
        SpriteFont_DrawAscii('N', 0xF, 0x94, 0x2A);
        SpriteFont_DrawAscii('G', 0xF, 0x9C, 0x2A);
        SpriteFont_DrawAscii('!', 0xF, 0xA4, 0x2A);
        return;
    }
    menu = sub_08126D1C(1);
    Sprite_Draw(gUnknown_0800853C, 0, 7, 0, 0x100, 0x51, menu->onScreen * 13 + 0x14);
    if (menu->count > 5)
    {
        if (menu->top != 0)
            SpriteFont_DrawAscii('<', 10, 0xB9, 0xB);
        if (menu->top + 5 != menu->count)
            SpriteFont_DrawAscii('>', 10, 0xB9, 0x49);
    }
    for (i = menu->top; i < menu->top + 5; i++)
    {
        u16 id = d->demons[i];
        u16 *src;

        if (id == 0xFFFF)
            continue;
        src = (u16 *)(Demon_GetRecord(id) + 0x22);
        for (j = 0; j < 8; j++)
            name[j] = *src++;
        name[j] = 0;
        if ((marks->unk56 >> i) & 1)
            Text_DrawSpriteStringTinted(name, 0, 0, 0x51, row * 13 + 0x13, 0xC, 2);
        else
            Text_DrawSpriteString(name, 0, 0, 0x51, row * 13 + 0x13, 0xC);
        row++;
    }
}

// sub_080E17F4 @ 0x080E17F4
void sub_080E17F4(void)
{
    struct C0cdLinkData *d = &gLink.rec[0];

    sub_080E1644(d, d + 1);
}

// sub_080E1808 @ 0x080E1808
void sub_080E1808(void)
{
    struct C0cdLinkData *d = &gLink.rec[1];

    sub_080E1644(d, d - 1);
}

// sub_080E181C @ 0x080E181C
void sub_080E181C(struct Task *t)
{
    sub_08126D1C(1);
    sub_08126A08(1);
    t->result = 0;
    if (gKeysNew & 1)
    {
        t->result = 1;
        Sound_Play(0x65);
    }
    else if (gKeysNew & 2)
    {
        t->result = 1;
        Sound_Play(0x66);
    }
}

// sub_080E1864 @ 0x080E1864
/* Sizes the menu of d's offered demons (at most 5 rows). */
void sub_080E1864(struct C0cdLinkData *d)
{
    u8 n = d->demonCount;

    if (n == 0)
        return;
    if (n <= 4)
        sub_08126928(1, 0, 1, n, n);
    else
        sub_08126928(1, 0x10, 1, n, 5);
    sub_08126D1C(1)->seA = 0xFFFF;
}

// sub_080E18AC @ 0x080E18AC
void sub_080E18AC(void)
{
    sub_080E1864(&gLink.rec[0]);
}

// sub_080E18BC @ 0x080E18BC
void sub_080E18BC(void)
{
    sub_080E1864(&gLink.rec[1]);
}

// sub_080E18CC @ 0x080E18CC
void sub_080E18CC(void)
{
    sub_081269B0(1);
}

// sub_080E18D8 @ 0x080E18D8
/* Clears the other player's record; both unk20 = 0x1BF. */
void sub_080E18D8(void)
{
    struct C0cdLinkData *me = &gLink.rec[0];
    struct C0cdLinkData *o = me + 1;

    o->magic = 0;
    o->unk08 = 0;
    o->unk04 = 0;
    o->unk14 = 0;
    o->unk0C = 0;
    o->money = 0;
    o->mag = 0;
    o->unk1C = 0;
    o->unk20 = 0x1BF;
    me->unk20 = 0x1BF;
    LinkTrade_ClearItemOffers(o);
    LinkTrade_ClearDemonOffers(o);
}

// sub_080E1914 @ 0x080E1914
/* Five-entry menu without cancel: A returns cursor + 1 in t->pad1E. */
void sub_080E1914(struct Task *t)
{
    t->result = 0;
    if (gKeysNew & 1)
    {
        t->pad1E = t->data.h[0] + 1;
        t->result = 1;
        Sound_Play(0x65);
    }
    else if (gKeysNew & 2)
    {
    }
    else if (gRepeatedKeys & 0x40)
    {
        if (t->data.h[0] == 0)
            t->data.h[0] = 5;
        t->data.h[0]--;
        Sound_Play(0x64);
    }
    else if (gRepeatedKeys & 0x80)
    {
        if (++t->data.h[0] > 4)
            t->data.h[0] = 0;
        Sound_Play(0x64);
    }
}

// sub_080E199C @ 0x080E199C
/* Six-entry menu without cancel. */
void sub_080E199C(struct Task *t)
{
    t->result = 0;
    if (gKeysNew & 1)
    {
        t->pad1E = t->data.h[0] + 1;
        t->result = 1;
        Sound_Play(0x65);
    }
    else if (gKeysNew & 2)
    {
    }
    else if (gRepeatedKeys & 0x40)
    {
        if (t->data.h[0] == 0)
            t->data.h[0] = 6;
        t->data.h[0]--;
        Sound_Play(0x64);
    }
    else if (gRepeatedKeys & 0x80)
    {
        if (++t->data.h[0] > 5)
            t->data.h[0] = 0;
        Sound_Play(0x64);
    }
}

// sub_080E1A24 @ 0x080E1A24
/* Waits for Link_ExchangeIds(a) to succeed, counting down t->data.h[0] frames (0xFF on timeout). */
void sub_080E1A24(struct Task *t, u32 a)
{
    u8 r;

    t->pad1E = 0;
    t->result = 0;
    r = Link_ExchangeIds(a);
    if (r == 1)
    {
        t->result = r;
        gUnk_03006394 = r;
    }
    else if ((s16)--t->data.h[0] < 0)
    {
        t->pad1E = 0xFF;
        t->result = 1;
        t->data.h[0] = 0;
        gUnk_03006394 = 0;
    }
}

// sub_080E1A6C @ 0x080E1A6C
void sub_080E1A6C(struct Task *t, u32 v)
{
    Task_Create(gUnknown_0858B180, t->id)->data.h[0] = v;
}

// sub_080E1A88 @ 0x080E1A88
void sub_080E1A88(struct Task *t, u32 v)
{
    Task_Create(gUnknown_0858B1BC, t->id)->data.h[0] = v;
}

// sub_080E1AA4 @ 0x080E1AA4
void sub_080E1AA4(struct Task *t)
{
    t->pad1E = gUnk_03006394;
}

// sub_080E1AB0 @ 0x080E1AB0
/* Runs Link_Handshake once per frame: t->result on success, t->pad1E = 0xFF on failure. */
void sub_080E1AB0(struct Task *t)
{
    u8 r = Link_Handshake();

    t->result = 0;
    t->pad1E = 0;
    if (r == 1)
    {
        t->result = r;
        gUnk_03006394 = r;
    }
    else if (r == 0xFF)
    {
        t->pad1E = r;
        t->result = 1;
        gUnk_03006394 = 0;
    }
}

// sub_080E1AEC @ 0x080E1AEC
void sub_080E1AEC(struct Task *t)
{
    Task_Create(gUnknown_0858B1F8, t->id);
}

// sub_080E1B00 @ 0x080E1B00
/* Runs the block transfer (Link_TransferStep) once per frame. */
void sub_080E1B00(struct Task *t)
{
    u8 r = Link_TransferStep();

    t->result = 0;
    t->pad1E = 0;
    if (r == 1)
    {
        t->result = r;
        gUnk_03006394 = r;
    }
    else if (r == 0xFF)
    {
        t->pad1E = r;
        t->result = 1;
        gUnk_03006394 = 0;
    }
}

// sub_080E1B3C @ 0x080E1B3C
void sub_080E1B3C(struct Task *t)
{
    Task_Create(gUnknown_0858B228, t->id);
}

// sub_080E1B50 @ 0x080E1B50
/* Exchanges the 0x58-byte player records (ours -> rec[1] on the other side). */
void sub_080E1B50(void)
{
    struct C0cdLinkData *d = &gLink.rec[0];

    Link_Exchange(sizeof(struct C0cdLinkData), (const u8 *)d, (u32)(d + 1));
}

// sub_080E1B68 @ 0x080E1B68
void sub_080E1B68(void)
{
    Text_DrawSpriteString(gUnknown_0800980C, 0, 0, 0x14, 0x64, 0xC);
}

// sub_080E1B8C @ 0x080E1B8C
void sub_080E1B8C(void)
{
    Text_DrawSpriteString(gUnknown_0858B250[gUnk_03006398], 0, 0, 0x14, 0x64, 0xC);
}

// sub_080E1BBC @ 0x080E1BBC
void sub_080E1BBC(struct Task *t, u32 msg)
{
    gUnk_03006398 = msg;
}

// sub_080E1BC8 @ 0x080E1BC8
void sub_080E1BC8(struct Task *t)
{
    struct C0cdLinkData *d = &gLinkData;
    u16 v = t->pad1E;

    if (v != 0)
        v = 1;
    d->unk1C = v;
}

// sub_080E1BE0 @ 0x080E1BE0
/* t->pad1E = 1 when neither player set unk1C; otherwise picks message 10 (we did) or 3. */
void sub_080E1BE0(struct Task *t)
{
    struct C0cdLinkData *me = &gLink.rec[0];
    struct C0cdLinkData *o = me + 1;

    t->pad1E = 0;
    if (me->unk1C == 0)
    {
        if (o->unk1C == 0)
            t->pad1E = 1;
        else
            gUnk_03006398 = 3;
    }
    else
    {
        gUnk_03006398 = 10;
    }
}

// sub_080E1C20 @ 0x080E1C20
/* Checks the other player's offer against our state and sets the bits of rec[0].unk20 for
   what can be accepted: 1 checked, 2 money stays <= 999,999, 4 magnetite stays <= 99,999,
   8 no item would exceed 99 (unk54: the items that would), 0x10/0x20/0x80/0x100 demons
   (stock room, not already owned or refused, level).  t->pad1E = 0xFF on a bad record. */
/* NONMATCHING: not finished: register allocation and block order differ. */
#ifdef NONMATCHING
void sub_080E1C20(struct Task *t)
{
    struct C0cdLinkData *me = &gLink.rec[0];
    struct C0cdLinkData *o = &gLink.rec[1];
    s32 v;
    s32 amount;
    u8 i, j;

    t->pad1E = 0;
    if (o->magic != 0x15273950)
    {
        t->pad1E = 0xFF;
        return;
    }
    me->unk20 = 0;
    if (Magnetite_Get() - me->unk14 + o->unk14 <= 99999)
        me->unk20 |= 4;
    me->unk54 = 0;
    if (o->offerCount == 0)
    {
        me->unk20 |= 8;
    }
    else
    {
        u16 k;

        for (k = 0; k < 5; k++)
        {
            u16 id = o->offers[k].id;
            u16 count;
            struct C0c2InvEntry *e;

            if (id == 0xFFFF)
                continue;
            count = o->offers[k].count;
            e = sub_080E0E04(me, id);
            if (e != NULL)
                count -= e->count;
            if ((s16)(Inventory_GetCount(id) + Party_CountEquipped(0xFF, id)) + (s16)count > 99)
                me->unk54 += 1 << k;
        }
        if (me->unk54 == 0)
            me->unk20 |= 8;
    }
    me->unk56 = 0;
    if (o->demonCount == 0)
    {
        me->unk20 |= 0x10 | 0x20 | 0x80 | 0x100;
    }
    else
    {
        u32 capacity = *((u8 *)&gGameState + 0xAC3);
        u16 n = o->demonCount;
        u32 ok = 1;
        u8 extra;
        u32 low;

        /* demons we give away in exchange free their slots */
        for (i = 0; i < 12; i++)
        {
            u16 id = o->demons[i];

            if (id != 0xFFFF && LinkTrade_IsDemonOffered(me, id))
                n--;
        }
        for (j = 4; j < capacity + 4; j++)
        {
            if (Battle_GetCombatant(0x8000 + j)->unkE & 0x8000)
                n++;
        }
        if ((s32)capacity >= (s16)n)
            me->unk20 |= 0x20;
        extra = n - o->demonCount;
        for (i = 0; i < 12; i++)
        {
            u16 id = o->demons[i];

            if (id == 0xFFFF)
                continue;
            for (j = 4; j < capacity + 4; j++)
            {
                struct Combatant *c = Battle_GetCombatant(0x8000 + j);

                if ((c->unkE & 0x8000) && c->demonId == id && LinkTrade_IsDemonOffered(me, id) != 1)
                    me->unk56 += 1 << i;
            }
            if (sub_08134C3C(id) == 1)
                me->unk56 += 1 << i;
            if (sub_0815BA28(id) == 0)
            {
                me->unk56 += 1 << i;
                ok = 0;
            }
        }
        if (me->unk56 == 0)
            me->unk20 |= 0x10;
        if (ok == 1)
            me->unk20 |= 0x100;
        for (i = 0; i < 12; i++)
        {
            if (o->demons[i] == 0xFFFF)
                continue;
            if (extra > capacity)
                me->unk56 |= 1 << i;
            extra++;
        }
        low = 0;
        for (i = 0; i < 12; i++)
        {
            u16 id = o->demons[i];

            if (id != 0xFFFF && Combatant_GetLevel(0) < Demon_GetRecord(id)[1])
            {
                low = 1;
                me->unk56 |= low << i;
            }
        }
        if (low == 0)
            me->unk20 |= 0x80;
    }
    v = o->unk04;
    if (v != 0)
    {
        double d;

        me->unk20 |= 0x40;
        d = __floatsidf(v);
        if (v < 0)
            d = __adddf3(d, 4294967296.0);
        amount = __fixsfsi(__truncdfsf2(__muldf3(d, 0.08)));
    }
    else
    {
        amount = o->unk08;
    }
    if (Money_Get() - me->unk08 + amount <= 999999)
        me->unk20 |= 2;
    me->unk20 |= 1;
}
#else
NAKED
void sub_080E1C20(struct Task *t)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x18\n"
        "    adds r2, r0, #0\n"
        "    ldr r0, .L080E1C44\n"
        "    mov sl, r0\n"
        "    movs r4, #0\n"
        "    strh r4, [r2, #0x1e]\n"
        "    ldr r1, [r0, #0x58]\n"
        "    ldr r0, .L080E1C48\n"
        "    cmp r1, r0\n"
        "    beq .L080E1C4C\n"
        "    movs r0, #0xff\n"
        "    strh r0, [r2, #0x1e]\n"
        "    b .L080E1FF8\n"
        ".L080E1C44: .4byte 0x0203B554 @ EWRAM+0x3B554\n"
        ".L080E1C48: .4byte 0x15273950\n"
        ".L080E1C4C:\n"
        "    mov r1, sl\n"
        "    str r4, [r1, #0x20]\n"
        "    bl Magnetite_Get\n"
        "    mov r2, sl\n"
        "    ldr r1, [r2, #0x14]\n"
        "    subs r0, r0, r1\n"
        "    ldr r3, .L080E1C94\n"
        "    ldr r1, [r3, #0x14]\n"
        "    adds r0, r0, r1\n"
        "    ldr r1, .L080E1C98\n"
        "    cmp r0, r1\n"
        "    bhi .L080E1C6E\n"
        "    ldr r0, [r2, #0x20]\n"
        "    movs r1, #4\n"
        "    orrs r0, r1\n"
        "    str r0, [r2, #0x20]\n"
        ".L080E1C6E:\n"
        "    mov r1, sl\n"
        "    adds r1, #0x54\n"
        "    strh r4, [r1]\n"
        "    mov r0, sl\n"
        "    adds r0, #0x7d\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L080E1C9C\n"
        "    mov r1, sl\n"
        "    ldr r0, [r1, #0x20]\n"
        "    movs r1, #8\n"
        "    orrs r0, r1\n"
        "    mov r2, sl\n"
        "    str r0, [r2, #0x20]\n"
        "    movs r3, #0x7c\n"
        "    add r3, sl\n"
        "    mov sb, r3\n"
        "    b .L080E1D28\n"
        "    .byte 0x00, 0x00\n"
        ".L080E1C94: .4byte 0x0203B5AC @ EWRAM+0x3B5AC\n"
        ".L080E1C98: .4byte 0x0001869F\n"
        ".L080E1C9C:\n"
        "    movs r7, #0\n"
        "    movs r0, #0x7c\n"
        "    add r0, sl\n"
        "    mov sb, r0\n"
        "    ldr r1, .L080E1D4C\n"
        "    mov r8, r1\n"
        ".L080E1CA8:\n"
        "    lsls r0, r7, #2\n"
        "    ldr r3, .L080E1D50\n"
        "    adds r2, r3, r0\n"
        "    adds r0, r2, #0\n"
        "    adds r0, #0x40\n"
        "    ldrh r1, [r0]\n"
        "    adds r6, r1, #0\n"
        "    ldr r0, .L080E1D54\n"
        "    cmp r1, r0\n"
        "    beq .L080E1D0A\n"
        "    adds r0, r2, #0\n"
        "    adds r0, #0x42\n"
        "    ldrh r5, [r0]\n"
        "    mov r0, sl\n"
        "    bl sub_080E0E04\n"
        "    cmp r0, #0\n"
        "    beq .L080E1CD4\n"
        "    ldrh r0, [r0, #2]\n"
        "    subs r0, r5, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        ".L080E1CD4:\n"
        "    adds r0, r6, #0\n"
        "    bl Inventory_GetCount\n"
        "    adds r4, r0, #0\n"
        "    lsls r4, r4, #0x18\n"
        "    lsrs r4, r4, #0x18\n"
        "    movs r0, #0xff\n"
        "    adds r1, r6, #0\n"
        "    bl Party_CountEquipped\n"
        "    adds r0, r0, r4\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    lsls r1, r5, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #0x63\n"
        "    ble .L080E1D0A\n"
        "    movs r0, #1\n"
        "    lsls r0, r7\n"
        "    mov r1, r8\n"
        "    ldrh r1, [r1]\n"
        "    adds r0, r0, r1\n"
        "    mov r2, r8\n"
        "    strh r0, [r2]\n"
        ".L080E1D0A:\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    cmp r7, #4\n"
        "    bls .L080E1CA8\n"
        "    ldr r3, .L080E1D4C\n"
        "    ldrh r0, [r3]\n"
        "    cmp r0, #0\n"
        "    bne .L080E1D28\n"
        "    mov r1, sl\n"
        "    ldr r0, [r1, #0x20]\n"
        "    movs r1, #8\n"
        "    orrs r0, r1\n"
        "    mov r2, sl\n"
        "    str r0, [r2, #0x20]\n"
        ".L080E1D28:\n"
        "    movs r0, #0\n"
        "    ldr r3, .L080E1D58\n"
        "    strh r0, [r3]\n"
        "    mov r1, sb\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0\n"
        "    bne .L080E1D5C\n"
        "    mov r2, sl\n"
        "    ldr r0, [r2, #0x20]\n"
        "    movs r1, #0x10\n"
        "    orrs r0, r1\n"
        "    movs r1, #0x20\n"
        "    orrs r0, r1\n"
        "    movs r1, #0x80\n"
        "    orrs r0, r1\n"
        "    adds r1, #0x80\n"
        "    orrs r0, r1\n"
        "    b .L080E1F6C\n"
        ".L080E1D4C: .4byte 0x0203B5A8 @ EWRAM+0x3B5A8\n"
        ".L080E1D50: .4byte 0x0203B5AC @ EWRAM+0x3B5AC\n"
        ".L080E1D54: .4byte 0x0000FFFF\n"
        ".L080E1D58: .4byte 0x0203B5AA @ EWRAM+0x3B5AA\n"
        ".L080E1D5C:\n"
        "    ldr r0, .L080E1FA8\n"
        "    ldr r3, .L080E1FAC\n"
        "    adds r0, r0, r3\n"
        "    ldrb r0, [r0]\n"
        "    str r0, [sp]\n"
        "    mov r0, sb\n"
        "    ldrb r7, [r0]\n"
        "    movs r1, #1\n"
        "    str r1, [sp, #8]\n"
        "    movs r6, #0\n"
        "    ldr r2, .L080E1FB0\n"
        "    adds r2, #0x26\n"
        "    str r2, [sp, #0x10]\n"
        "    ldr r4, .L080E1FB4\n"
        ".L080E1D78:\n"
        "    lsls r0, r6, #1\n"
        "    ldr r3, [sp, #0x10]\n"
        "    adds r0, r3, r0\n"
        "    ldrh r5, [r0]\n"
        "    cmp r5, r4\n"
        "    beq .L080E1D9A\n"
        "    mov r0, sl\n"
        "    adds r1, r5, #0\n"
        "    bl LinkTrade_IsDemonOffered\n"
        "    lsls r0, r0, #0x18\n"
        "    cmp r0, #0\n"
        "    beq .L080E1D9A\n"
        "    lsls r0, r7, #0x10\n"
        "    ldr r1, .L080E1FB8\n"
        "    adds r0, r0, r1\n"
        "    lsrs r7, r0, #0x10\n"
        ".L080E1D9A:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r6, r0, #0x18\n"
        "    cmp r6, #0xb\n"
        "    bls .L080E1D78\n"
        "    movs r4, #4\n"
        "    ldr r2, [sp]\n"
        "    adds r2, #4\n"
        "    str r2, [sp, #0xc]\n"
        "    cmp r4, r2\n"
        "    bge .L080E1DE0\n"
        "    movs r3, #0x80\n"
        "    lsls r3, r3, #8\n"
        "    adds r5, r3, #0\n"
        ".L080E1DB6:\n"
        "    adds r0, r4, r5\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    adds r1, r0, #0\n"
        "    ldrh r0, [r1, #0xe]\n"
        "    ands r0, r5\n"
        "    cmp r0, #0\n"
        "    beq .L080E1DD4\n"
        "    lsls r0, r7, #0x10\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #9\n"
        "    adds r0, r0, r1\n"
        "    lsrs r7, r0, #0x10\n"
        ".L080E1DD4:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    ldr r2, [sp, #0xc]\n"
        "    cmp r4, r2\n"
        "    blt .L080E1DB6\n"
        ".L080E1DE0:\n"
        "    lsls r0, r7, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    ldr r3, [sp]\n"
        "    cmp r3, r0\n"
        "    blt .L080E1DF6\n"
        "    mov r1, sl\n"
        "    ldr r0, [r1, #0x20]\n"
        "    movs r1, #0x20\n"
        "    orrs r0, r1\n"
        "    mov r2, sl\n"
        "    str r0, [r2, #0x20]\n"
        ".L080E1DF6:\n"
        "    mov r3, sb\n"
        "    ldrb r0, [r3]\n"
        "    subs r0, r7, r0\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    str r0, [sp, #4]\n"
        "    movs r6, #0\n"
        "    ldr r0, .L080E1FBC\n"
        "    mov r8, r0\n"
        ".L080E1E08:\n"
        "    lsls r0, r6, #1\n"
        "    ldr r1, [sp, #0x10]\n"
        "    adds r0, r1, r0\n"
        "    ldrh r5, [r0]\n"
        "    ldr r0, .L080E1FB4\n"
        "    cmp r5, r0\n"
        "    beq .L080E1EA8\n"
        "    movs r4, #4\n"
        "    ldr r2, [sp, #0xc]\n"
        "    cmp r4, r2\n"
        "    bge .L080E1E72\n"
        "    movs r3, #0x80\n"
        "    lsls r3, r3, #8\n"
        "    mov sb, r3\n"
        "    ldr r7, .L080E1FBC\n"
        "    movs r2, #1\n"
        "    lsls r2, r6\n"
        ".L080E1E2A:\n"
        "    mov r1, sb\n"
        "    adds r0, r4, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r2, [sp, #0x14]\n"
        "    bl Battle_GetCombatant\n"
        "    adds r1, r0, #0\n"
        "    ldrh r0, [r1, #0xe]\n"
        "    mov r3, sb\n"
        "    ands r0, r3\n"
        "    ldr r2, [sp, #0x14]\n"
        "    cmp r0, #0\n"
        "    beq .L080E1E66\n"
        "    movs r3, #0x12\n"
        "    ldrsh r0, [r1, r3]\n"
        "    cmp r0, r5\n"
        "    bne .L080E1E66\n"
        "    mov r0, sl\n"
        "    adds r1, r5, #0\n"
        "    bl LinkTrade_IsDemonOffered\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    ldr r2, [sp, #0x14]\n"
        "    cmp r0, #1\n"
        "    beq .L080E1E66\n"
        "    ldrh r0, [r7]\n"
        "    adds r0, r0, r2\n"
        "    strh r0, [r7]\n"
        ".L080E1E66:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    ldr r0, [sp, #0xc]\n"
        "    cmp r4, r0\n"
        "    blt .L080E1E2A\n"
        ".L080E1E72:\n"
        "    adds r0, r5, #0\n"
        "    bl sub_08134C3C\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bne .L080E1E8C\n"
        "    lsls r0, r6\n"
        "    mov r1, r8\n"
        "    ldrh r1, [r1]\n"
        "    adds r0, r0, r1\n"
        "    mov r2, r8\n"
        "    strh r0, [r2]\n"
        ".L080E1E8C:\n"
        "    adds r0, r5, #0\n"
        "    bl sub_0815BA28\n"
        "    cmp r0, #0\n"
        "    bne .L080E1EA8\n"
        "    movs r0, #1\n"
        "    lsls r0, r6\n"
        "    mov r3, r8\n"
        "    ldrh r3, [r3]\n"
        "    adds r0, r0, r3\n"
        "    mov r1, r8\n"
        "    strh r0, [r1]\n"
        "    movs r2, #0\n"
        "    str r2, [sp, #8]\n"
        ".L080E1EA8:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r6, r0, #0x18\n"
        "    cmp r6, #0xb\n"
        "    bls .L080E1E08\n"
        "    ldr r3, .L080E1FBC\n"
        "    ldrh r0, [r3]\n"
        "    cmp r0, #0\n"
        "    bne .L080E1EC6\n"
        "    mov r1, sl\n"
        "    ldr r0, [r1, #0x20]\n"
        "    movs r1, #0x10\n"
        "    orrs r0, r1\n"
        "    mov r2, sl\n"
        "    str r0, [r2, #0x20]\n"
        ".L080E1EC6:\n"
        "    ldr r3, [sp, #8]\n"
        "    cmp r3, #1\n"
        "    bne .L080E1EDA\n"
        "    mov r1, sl\n"
        "    ldr r0, [r1, #0x20]\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #1\n"
        "    orrs r0, r1\n"
        "    mov r2, sl\n"
        "    str r0, [r2, #0x20]\n"
        ".L080E1EDA:\n"
        "    movs r6, #0\n"
        "    ldr r3, [sp, #0x10]\n"
        "    ldr r7, .L080E1FB4\n"
        "    ldr r2, .L080E1FBC\n"
        "    movs r4, #1\n"
        ".L080E1EE4:\n"
        "    lsls r0, r6, #1\n"
        "    adds r0, r3, r0\n"
        "    ldrh r5, [r0]\n"
        "    cmp r5, r7\n"
        "    beq .L080E1F0A\n"
        "    ldr r0, [sp, #4]\n"
        "    ldr r1, [sp]\n"
        "    cmp r0, r1\n"
        "    bls .L080E1F00\n"
        "    adds r0, r4, #0\n"
        "    lsls r0, r6\n"
        "    ldrh r1, [r2]\n"
        "    orrs r0, r1\n"
        "    strh r0, [r2]\n"
        ".L080E1F00:\n"
        "    ldr r0, [sp, #4]\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    str r0, [sp, #4]\n"
        ".L080E1F0A:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r6, r0, #0x18\n"
        "    cmp r6, #0xb\n"
        "    bls .L080E1EE4\n"
        "    movs r2, #0\n"
        "    mov r8, r2\n"
        "    movs r6, #0\n"
        "    ldr r3, .L080E1FB4\n"
        "    mov sb, r3\n"
        "    ldr r7, .L080E1FBC\n"
        ".L080E1F20:\n"
        "    lsls r0, r6, #1\n"
        "    ldr r1, [sp, #0x10]\n"
        "    adds r0, r1, r0\n"
        "    ldrh r5, [r0]\n"
        "    cmp r5, sb\n"
        "    beq .L080E1F52\n"
        "    movs r0, #0\n"
        "    bl Combatant_GetLevel\n"
        "    adds r4, r0, #0\n"
        "    lsls r4, r4, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    adds r0, r5, #0\n"
        "    bl Demon_GetRecord\n"
        "    ldrb r0, [r0, #1]\n"
        "    cmp r4, r0\n"
        "    bge .L080E1F52\n"
        "    movs r2, #1\n"
        "    mov r8, r2\n"
        "    mov r0, r8\n"
        "    lsls r0, r6\n"
        "    ldrh r1, [r7]\n"
        "    orrs r0, r1\n"
        "    strh r0, [r7]\n"
        ".L080E1F52:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r6, r0, #0x18\n"
        "    cmp r6, #0xb\n"
        "    bls .L080E1F20\n"
        "    mov r3, r8\n"
        "    cmp r3, #0\n"
        "    bne .L080E1F6E\n"
        "    mov r1, sl\n"
        "    ldr r0, [r1, #0x20]\n"
        "    movs r1, #0x80\n"
        "    orrs r0, r1\n"
        "    mov r2, sl\n"
        ".L080E1F6C:\n"
        "    str r0, [r2, #0x20]\n"
        ".L080E1F6E:\n"
        "    ldr r3, .L080E1FB0\n"
        "    ldr r4, [r3, #4]\n"
        "    cmp r4, #0\n"
        "    beq .L080E1FD0\n"
        "    mov r1, sl\n"
        "    ldr r0, [r1, #0x20]\n"
        "    movs r1, #0x40\n"
        "    orrs r0, r1\n"
        "    mov r2, sl\n"
        "    str r0, [r2, #0x20]\n"
        "    adds r0, r4, #0\n"
        "    bl __floatsidf\n"
        "    cmp r4, #0\n"
        "    bge .L080E1F94\n"
        "    ldr r2, .L080E1FC0\n"
        "    ldr r3, .L080E1FC4\n"
        "    bl __adddf3\n"
        ".L080E1F94:\n"
        "    ldr r2, .L080E1FC8\n"
        "    ldr r3, .L080E1FCC\n"
        "    bl __muldf3\n"
        "    bl __truncdfsf2\n"
        "    bl __fixsfsi\n"
        "    adds r4, r0, #0\n"
        "    b .L080E1FD4\n"
        ".L080E1FA8: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080E1FAC: .4byte 0x00000AC3\n"
        ".L080E1FB0: .4byte 0x0203B5AC @ EWRAM+0x3B5AC\n"
        ".L080E1FB4: .4byte 0x0000FFFF\n"
        ".L080E1FB8: .4byte 0xFFFF0000\n"
        ".L080E1FBC: .4byte 0x0203B5AA @ EWRAM+0x3B5AA\n"
        ".L080E1FC0: .4byte 0x41F00000\n"
        ".L080E1FC4: .4byte 0x00000000\n"
        ".L080E1FC8: .4byte 0x3FB47AE1\n"
        ".L080E1FCC: .4byte 0x47AE147B\n"
        ".L080E1FD0:\n"
        "    ldr r3, .L080E2008\n"
        "    ldr r4, [r3, #8]\n"
        ".L080E1FD4:\n"
        "    bl Money_Get\n"
        "    mov r2, sl\n"
        "    ldr r1, [r2, #8]\n"
        "    subs r0, r0, r1\n"
        "    adds r0, r0, r4\n"
        "    ldr r1, .L080E200C\n"
        "    cmp r0, r1\n"
        "    bgt .L080E1FEE\n"
        "    ldr r0, [r2, #0x20]\n"
        "    movs r1, #2\n"
        "    orrs r0, r1\n"
        "    str r0, [r2, #0x20]\n"
        ".L080E1FEE:\n"
        "    mov r3, sl\n"
        "    ldr r0, [r3, #0x20]\n"
        "    movs r1, #1\n"
        "    orrs r0, r1\n"
        "    str r0, [r3, #0x20]\n"
        ".L080E1FF8:\n"
        "    add sp, #0x18\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080E2008: .4byte 0x0203B5AC @ EWRAM+0x3B5AC\n"
        ".L080E200C: .4byte 0x000F423F\n"
    );
}
#endif

// sub_080E2010 @ 0x080E2010
/* t->pad1E = 1 when record who (0 ours, 1 the other player's) has any of the unk20 bits in mask. */
void sub_080E2010(struct Task *t, u32 mask, u32 who)
{
    struct C0cdLinkData *me = &gLink.rec[0];
    struct C0cdLinkData *o = me + 1;
    struct C0cdLinkData *d;

    t->pad1E = 0;
    if (who == 0)
        d = me;
    else if (who == 1)
        d = o;
    else
        return;
    if (d->unk20 & mask)
        t->pad1E = 1;
}

// sub_080E2044 @ 0x080E2044
void sub_080E2044(struct Task *t)
{
    t->result = 0;
    if (gKeysNew & 1)
    {
        t->result = 1;
        Sound_Play(0x65);
    }
    else if (gKeysNew & 2)
    {
        t->result = 1;
        Sound_Play(0x66);
    }
}

// Party_FixOrderAfterTrade @ 0x080E2080
/* Fixes the party order after a trade: fills an empty front slot from the back row and moves
   a front member with status 0x8000/0x2000 behind a healthy back-row member. */
void Party_FixOrderAfterTrade(void)
{
    u8 o[6];
    u32 i;

    for (i = 0; i < 6; i++)
        o[i] |= 0xFF;
    for (i = 0; i < 6; i++)
        o[i] = gGameState.order[i];
    for (i = 0; i < 3; i++)
    {
        s8 a = o[i];
        s8 b = o[i + 3];

        if (a == -1)
        {
            if (b != a)
            {
                o[i] = b;
                o[i + 3] = 0xFF;
            }
        }
        else if (b >= 0 && (Combatant_GetStatus(a) & 0xA000) && !(Combatant_GetStatus(b) & 0xA000))
        {
            o[i] = b;
            o[i + 3] = a;
        }
    }
    for (i = 0; i < 6; i++)
        gGameState.order[i] = o[i];
}

// LinkTrade_Execute @ 0x080E2148
/* Completes the trade for the parts both players agreed on (unk20 bits): money (we pay unk08,
   receive 8% of the other's unk04, or their unk08), magnetite, items and demons; then saves. */
/* NONMATCHING: register allocation (loop index and item id swap registers). */
#ifdef NONMATCHING
void LinkTrade_Execute(void)
{
    struct C0cdLinkData *me = &gLink.rec[0];
    struct C0cdLinkData *o = me + 1;
    u16 i, j;
    u16 count, id;

    if ((me->unk20 & 3) == 3 && (o->unk20 & 3) == 3)
    {
        s32 v;
        s32 amount;

        Money_Add(-me->unk08);
        v = o->unk04;
        if (v != 0)
        {
            /* (s32)(float)((double)(u32)v * 0.08) */
            double d = __floatsidf(v);

            if (v < 0)
                d = __adddf3(d, 4294967296.0);
            amount = __fixsfsi(__truncdfsf2(__muldf3(d, 0.08)));
        }
        else
        {
            amount = o->unk08;
        }
        Money_Add(amount);
    }
    if ((me->unk20 & 4) && (o->unk20 & 4))
    {
        Magnetite_Add(-me->unk14);
        Magnetite_Add(o->unk14);
    }
    if ((me->unk20 & 8) && (o->unk20 & 8))
    {
        for (i = 0; i < 5; i++)
        {
            id = me->offers[i].id;
            count = me->offers[i].count;

            if (id != 0xFFFF)
            {
                u16 n;

                for (n = 0; n < count; n++)
                    Inventory_RemoveItem(id);
            }
        }
        for (i = 0; i < 5; i++)
        {
            id = o->offers[i].id;
            count = o->offers[i].count;

            if (id != 0xFFFF)
            {
                u16 n;

                for (n = 0; n < count; n++)
                    Inventory_AddItem(id);
            }
        }
    }
    if ((me->unk20 & 0x10) && (o->unk20 & 0x10) && (me->unk20 & 0x20) && (o->unk20 & 0x20)
        && (me->unk20 & 0x80) && (o->unk20 & 0x80) && (me->unk20 & 0x100) && (o->unk20 & 0x100))
    {
        for (i = 0; i < 12; i++)
        {
            u16 id = me->demons[i];

            if (id != 0xFFFF)
            {
                for (j = 4; j < 16; j++)
                {
                    if (Battle_GetCombatant(0x8000 + j)->demonId == id)
                        break;
                }
                Party_Remove(j, 1);
            }
        }
        for (i = 0; i < 12; i++)
        {
            u16 id = o->demons[i];

            if (id != 0xFFFF)
            {
                Stock_AddDemon(id);
                sub_080C29E8(id);
            }
        }
        Party_FixOrderAfterTrade();
    }
    {
        u8 *gs = (u8 *)&gGameState;
        u32 off = 0x18B0;

        SaveSlot_Write(*(u32 *)(gs + off), &gGameState);
    }
}
#else
NAKED
void LinkTrade_Execute(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    ldr r0, .L080E21A8\n"
        "    mov r8, r0\n"
        "    movs r1, #0x58\n"
        "    add r1, r8\n"
        "    mov sb, r1\n"
        "    ldr r1, [r0, #0x20]\n"
        "    movs r0, #3\n"
        "    ands r1, r0\n"
        "    cmp r1, #3\n"
        "    bne .L080E21C4\n"
        "    mov r2, sb\n"
        "    ldr r0, [r2, #0x20]\n"
        "    ands r0, r1\n"
        "    cmp r0, #3\n"
        "    bne .L080E21C4\n"
        "    mov r1, r8\n"
        "    ldr r0, [r1, #8]\n"
        "    rsbs r0, r0, #0\n"
        "    bl Money_Add\n"
        "    mov r2, sb\n"
        "    ldr r4, [r2, #4]\n"
        "    cmp r4, #0\n"
        "    beq .L080E21BC\n"
        "    adds r0, r4, #0\n"
        "    bl __floatsidf\n"
        "    cmp r4, #0\n"
        "    bge .L080E2194\n"
        "    ldr r2, .L080E21AC\n"
        "    ldr r3, .L080E21B0\n"
        "    bl __adddf3\n"
        ".L080E2194:\n"
        "    ldr r2, .L080E21B4\n"
        "    ldr r3, .L080E21B8\n"
        "    bl __muldf3\n"
        "    bl __truncdfsf2\n"
        "    bl __fixsfsi\n"
        "    b .L080E21C0\n"
        "    .byte 0x00, 0x00\n"
        ".L080E21A8: .4byte 0x0203B554 @ EWRAM+0x3B554\n"
        ".L080E21AC: .4byte 0x41F00000\n"
        ".L080E21B0: .4byte 0x00000000\n"
        ".L080E21B4: .4byte 0x3FB47AE1\n"
        ".L080E21B8: .4byte 0x47AE147B\n"
        ".L080E21BC:\n"
        "    mov r1, sb\n"
        "    ldr r0, [r1, #8]\n"
        ".L080E21C0:\n"
        "    bl Money_Add\n"
        ".L080E21C4:\n"
        "    mov r2, r8\n"
        "    ldr r0, [r2, #0x20]\n"
        "    movs r1, #4\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080E21EC\n"
        "    mov r2, sb\n"
        "    ldr r0, [r2, #0x20]\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080E21EC\n"
        "    mov r1, r8\n"
        "    ldr r0, [r1, #0x14]\n"
        "    rsbs r0, r0, #0\n"
        "    bl Magnetite_Add\n"
        "    mov r2, sb\n"
        "    ldr r0, [r2, #0x14]\n"
        "    bl Magnetite_Add\n"
        ".L080E21EC:\n"
        "    mov r1, r8\n"
        "    ldr r0, [r1, #0x20]\n"
        "    movs r1, #8\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080E2272\n"
        "    mov r2, sb\n"
        "    ldr r0, [r2, #0x20]\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080E2272\n"
        "    movs r7, #0\n"
        "    ldr r0, .L080E22E0\n"
        "    mov sl, r0\n"
        ".L080E2208:\n"
        "    lsls r0, r7, #2\n"
        "    add r0, r8\n"
        "    adds r1, r0, #0\n"
        "    adds r1, #0x40\n"
        "    ldrh r6, [r1]\n"
        "    adds r0, #0x42\n"
        "    ldrh r5, [r0]\n"
        "    cmp r6, sl\n"
        "    beq .L080E2230\n"
        "    movs r4, #0\n"
        "    cmp r4, r5\n"
        "    bhs .L080E2230\n"
        ".L080E2220:\n"
        "    adds r0, r6, #0\n"
        "    bl Inventory_RemoveItem\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, r5\n"
        "    blo .L080E2220\n"
        ".L080E2230:\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    cmp r7, #4\n"
        "    bls .L080E2208\n"
        "    movs r7, #0\n"
        "    ldr r1, .L080E22E0\n"
        "    mov sl, r1\n"
        ".L080E2240:\n"
        "    lsls r0, r7, #2\n"
        "    add r0, sb\n"
        "    adds r1, r0, #0\n"
        "    adds r1, #0x40\n"
        "    ldrh r6, [r1]\n"
        "    adds r0, #0x42\n"
        "    ldrh r5, [r0]\n"
        "    adds r7, #1\n"
        "    cmp r6, sl\n"
        "    beq .L080E226A\n"
        "    movs r4, #0\n"
        "    cmp r4, r5\n"
        "    bhs .L080E226A\n"
        ".L080E225A:\n"
        "    adds r0, r6, #0\n"
        "    bl Inventory_AddItem\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, r5\n"
        "    blo .L080E225A\n"
        ".L080E226A:\n"
        "    lsls r0, r7, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    cmp r7, #4\n"
        "    bls .L080E2240\n"
        ".L080E2272:\n"
        "    mov r0, r8\n"
        "    ldr r2, [r0, #0x20]\n"
        "    movs r3, #0x10\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r3\n"
        "    cmp r0, #0\n"
        "    beq .L080E233E\n"
        "    mov r0, sb\n"
        "    ldr r1, [r0, #0x20]\n"
        "    adds r0, r1, #0\n"
        "    ands r0, r3\n"
        "    cmp r0, #0\n"
        "    beq .L080E233E\n"
        "    movs r3, #0x20\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r3\n"
        "    cmp r0, #0\n"
        "    beq .L080E233E\n"
        "    adds r0, r1, #0\n"
        "    ands r0, r3\n"
        "    cmp r0, #0\n"
        "    beq .L080E233E\n"
        "    movs r3, #0x80\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r3\n"
        "    cmp r0, #0\n"
        "    beq .L080E233E\n"
        "    adds r0, r1, #0\n"
        "    ands r0, r3\n"
        "    cmp r0, #0\n"
        "    beq .L080E233E\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    ands r2, r0\n"
        "    cmp r2, #0\n"
        "    beq .L080E233E\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080E233E\n"
        "    movs r6, #0\n"
        "    mov r7, r8\n"
        "    adds r7, #0x26\n"
        "    movs r1, #0x26\n"
        "    add r1, sb\n"
        "    mov r8, r1\n"
        "    ldr r2, .L080E22E0\n"
        "    mov sb, r2\n"
        ".L080E22D0:\n"
        "    lsls r0, r6, #1\n"
        "    adds r0, r7, r0\n"
        "    ldrh r5, [r0]\n"
        "    cmp r5, sb\n"
        "    beq .L080E230C\n"
        "    movs r4, #4\n"
        "    b .L080E22EA\n"
        "    .byte 0x00, 0x00\n"
        ".L080E22E0: .4byte 0x0000FFFF\n"
        ".L080E22E4:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        ".L080E22EA:\n"
        "    cmp r4, #0xf\n"
        "    bhi .L080E2304\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    adds r0, r4, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    movs r2, #0x12\n"
        "    ldrsh r0, [r0, r2]\n"
        "    cmp r0, r5\n"
        "    bne .L080E22E4\n"
        ".L080E2304:\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #1\n"
        "    bl Party_Remove\n"
        ".L080E230C:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r6, #0xb\n"
        "    bls .L080E22D0\n"
        "    movs r6, #0\n"
        "    ldr r4, .L080E2358\n"
        ".L080E231A:\n"
        "    lsls r0, r6, #1\n"
        "    add r0, r8\n"
        "    ldrh r5, [r0]\n"
        "    cmp r5, r4\n"
        "    beq .L080E2330\n"
        "    adds r0, r5, #0\n"
        "    bl Stock_AddDemon\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080C29E8\n"
        ".L080E2330:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r6, #0xb\n"
        "    bls .L080E231A\n"
        "    bl Party_FixOrderAfterTrade\n"
        ".L080E233E:\n"
        "    ldr r1, .L080E235C\n"
        "    ldr r2, .L080E2360\n"
        "    adds r0, r1, r2\n"
        "    ldr r0, [r0]\n"
        "    bl SaveSlot_Write\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080E2358: .4byte 0x0000FFFF\n"
        ".L080E235C: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080E2360: .4byte 0x000018B0\n"
    );
}
#endif

