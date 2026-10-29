/* Battle unit status icons. */

#include "global.h"
#include "battledisp.h"

// sub_080E71DC @ 0x080E71DC
/* Sets unit `slot`'s status icon and queues the tile upload. */
void sub_080E71DC(u8 slot, u8 icon)
{
    const u8 *ic = gUnknown_086BE6A4[icon];
    const u8 *src = gUnknown_081A81B8 + ic[0] * 128;
    u8 *dst = gUnk_030010B4 + slot * 128;
    struct C15cBattle *b = BB;
    struct C15cIcon *e = &b->icons[slot];

    if (e->icon != icon)
    {
        CpuFastSet(src, dst, 0x20);
        e->icon = icon;
        e->tile = ic[0];
        e->unk3 = ic[1];
        gUnk_030063C0 = slot;
        sub_080E5668(sub_080E7318);
    }
}

// sub_080E724C @ 0x080E724C
/* Builds the status icons of all live units. */
void sub_080E724C(void)
{
    struct C15cBattle *b = BB;
    u32 zero = 0;
    u8 i;

    CpuFastSet(&zero, gUnk_030010B4, 0x01000100);
    for (i = 0; i < 8; i++)
    {
        struct C15cUnit *u = &b->units[i];

        if (u->unkE == 0x8000 && (u->unk10 & 0x8000) == 0)
        {
            u8 icon = StatusIcon_FromStatus(u->unk10);
            const u8 *ic = gUnknown_086BE6A4[icon];
            struct C15cIcon *e;

            CpuFastSet(gUnknown_081A81B8 + ic[0] * 128, gUnk_030010B4 + i * 128, 0x20);
            e = &b->icons[i];
            e->slot = i;
            e->icon = icon;
            e->tile = ic[0];
            e->unk3 = ic[1];
            e->shown = 1;
            e->unk9 = 0;
        }
    }
    VBlankTask_AddCounted(sub_080E7364, 1);
    b->unkEC0 = 0;
}

// sub_080E7318 @ 0x080E7318
#ifdef NONMATCHING
void sub_080E7318(void)
{
    DmaSet3Wait(gUnk_030010B4 + gUnk_030063C0 * 128, 0x06011500 + gUnk_030063C0 * 128, 0x84000020);
}
#else
NAKED
void sub_080E7318(void)
{
    asm_unified(
        "    push {lr}\n"
        "    ldr r2, .L080E7350\n"
        "    ldr r3, .L080E7354\n"
        "    ldrb r0, [r3]\n"
        "    lsls r0, r0, #7\n"
        "    ldr r1, .L080E7358\n"
        "    adds r0, r0, r1\n"
        "    str r0, [r2]\n"
        "    ldrb r0, [r3]\n"
        "    lsls r0, r0, #7\n"
        "    ldr r1, .L080E735C\n"
        "    adds r0, r0, r1\n"
        "    str r0, [r2, #4]\n"
        "    ldr r0, .L080E7360\n"
        "    str r0, [r2, #8]\n"
        "    ldr r0, [r2, #8]\n"
        "    ldr r0, [r2, #8]\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #0x18\n"
        "    cmp r0, #0\n"
        "    bge .L080E734A\n"
        ".L080E7342:\n"
        "    ldr r0, [r2, #8]\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L080E7342\n"
        ".L080E734A:\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080E7350: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080E7354: .4byte 0x030063C0 @ IWRAM+0x63C0\n"
        ".L080E7358: .4byte 0x030010B4 @ IWRAM+0x10B4\n"
        ".L080E735C: .4byte 0x06011500 @ VRAM+0x11500\n"
        ".L080E7360: .4byte 0x84000020\n"
    );
}
#endif

// sub_080E7364 @ 0x080E7364
void sub_080E7364(void)
{
    DmaSet3Wait(gUnk_030010B4, (void *)0x06011500, 0x84000100);
}

// StatusIcon_FromStatus @ 0x080E739C
/* Status icon index for a status word (the last matching bit wins). */
u8 StatusIcon_FromStatus(u16 status)
{
    u8 r = 0;

    if (status & 8)
        r = 1;

    if (status & 0x10)
        r = 2;
    if (status & 2)
        r = 3;
    if (status & 0x80)
        r = 4;
    if (status & 0x100)
        r = 5;
    if (status & 0x20)
        r = 6;
    if (status & 0x40)
        r = 7;
    if (status & 0x200)
        r = 8;
    if (status & 1)
        r = 9;
    if (status & 0x800)
        r = 11;
    if (status & 4)
        r = 12;
    if (status & 0x1000)
        r = 13;
    if (status & 0x2000)
        r = 14;
    if (status & 0x8000)
        r = 16;
    return r;
}

// sub_080E7444 @ 0x080E7444
void sub_080E7444(void)
{
    struct C15cBattle *b = BB;
    struct C15cIcon *e = b->icons;
    u8 i;

    for (i = 0; i < 8; i++)
    {
        e->icon |= 0xFF;
        e->slot |= 0xFF;
        e->unk3 = 0;
        e->tile = 0;
        e->unk6 = 0;
        e->unk4 = 0;
        e->shown = 0;
        e->unk9 = 0;
        e++;
    }
}

// sub_080E7484 @ 0x080E7484
/* Ends every running task whose frame handler is sub_080E7A44. */
void sub_080E7484(void)
{
    u32 i;

    for (i = 0; i < 64; i++)
    {
        struct Task *t = &gTasks[i];

        if (t->state != 0 && t->onFrame == sub_080E7A44)
            Task_End(t);
    }
}

// sub_080E74BC @ 0x080E74BC
void sub_080E74BC(void)
{
    struct C15cBattle *b = BB;

    b->tasks[2] = Task_Create(gUnknown_086BE738, 0xFFFF);
}

// sub_080E74DC @ 0x080E74DC
void sub_080E74DC(void)
{
    struct C15cBattle *b = BB;
    struct C15cIcon *e = b->icons;
    u8 i;

    for (i = 0; i < 8; i++)
    {
        e->icon |= 0xFF;
        e->slot |= 0xFF;
        e->unk3 = 0;
        e->tile = 0;
        e->unk4 = 0;
        e->unk6 = 0xFFFC;
        e->shown = 0;
        e->unk9 = 0;
        e++;
    }
    b->unkEC4 = 0;
    b->unkEC5 = 0;
}

// sub_080E7538 @ 0x080E7538
/* Sets the display mode of unit `slot`'s status icon. */
void sub_080E7538(u8 slot, u8 mode, u8 arg)
{
    struct C15cBattle *b = BB;
    struct C15cIcon *e = &b->icons[slot];

    switch (mode)
    {
    case 0:
        e->shown = 0;
        e->unkA = 0;
        break;
    case 1:
        e->unk6 = 0xFFFC;
        e->shown = 1;
        e->unkA = 0;
        break;
    case 2:
        e->shown = 2;
        b->unkEC0 = 1;
        e->unkA = 0;
        e->unkB = 0;
        break;
    case 3:
        e->shown = 3;
        e->icon = 0xFF;
        e->unk6 = 4;
        b->unkEC0 = 1;
        e->unkA = arg;
        break;
    case 4:
        e->shown = 4;
        e->unkA = 0;
        break;
    }
}

// sub_080E75DC @ 0x080E75DC
bool32 sub_080E75DC(u8 slot, u8 mode)
{
    struct C15cBattle *b = BB;
    struct C15cIcon *e = &b->icons[slot];

    if (e->shown == mode)
        return TRUE;
    return FALSE;
}

// sub_080E760C @ 0x080E760C
/* Lays out the status icons of the live units in rows under each side. */
void sub_080E760C(void)
{
    struct C15cBattle *b = BB;
    const u8 *x;
    u8 i;
    u8 j;
    u8 n;

    sub_080E74DC();
    for (i = 0; i < 8; i++)
    {
        if (!Combatant_IsDead(i + 16) && Combatant_IsUsed(i + 16))
            sub_080E7538(i, 3, i * 3);
    }
    if (!Battle_IsTwoSided())
    {
        b->unkEC4 = 0;
        for (n = 0, i = 0; i < 8; i++)
        {
            if (!Combatant_IsDead(i + 16) && Combatant_IsUsed(i + 16))
            {
                sub_080E7538(i, 3, n * 3);
                b->unkEC4++;
                n++;
            }
        }
        n = 0;
        x = &gUnknown_086BE707[b->unkEC4];
        for (j = 0; j < 8; j++)
        {
            struct C15cIcon *e = &b->icons[j];

            if (e->shown)
            {
                e->slot = j;
                e->unk4 = n * 14 + *x;
                n++;
            }
        }
    }
    else
    {
        b->unkEC4 = 0;
        b->unkEC5 = 0;
        for (n = 0, i = 0; i < 4; i++)
        {
            if (!Combatant_IsDead(i + 16) && Combatant_IsUsed(i + 16))
            {
                sub_080E7538(i, 3, n * 3);
                b->unkEC4++;
                n++;
            }
        }
        n = 0;
        x = &gUnknown_086BE70F[b->unkEC4];
        for (j = 0; j < 4; j++)
        {
            struct C15cIcon *e = &b->icons[j];

            if (e->shown)
            {
                e->slot = j;
                e->unk4 = n * 14 + *x;
                n++;
            }
        }
        for (n = 0, i = 4; i < 8; i++)
        {
            if (!Combatant_IsDead(i + 16) && Combatant_IsUsed(i + 16))
            {
                sub_080E7538(i, 3, n * 3);
                b->unkEC5++;
                n++;
            }
        }
        n = 0;
        x = &gUnknown_086BE713[b->unkEC5];
        for (j = 4; j < 8; j++)
        {
            struct C15cIcon *e = &b->icons[j];

            if (e->shown)
            {
                e->slot = j;
                e->unk4 = n * 14 + *x;
                n++;
            }
        }
    }
}

// StatusIcon_ForCombatant @ 0x080E7834
/* Status icon for combatant `who` (16-23): the highest-priority ailment, 2 when below a
   quarter of max HP. */
u8 StatusIcon_ForCombatant(u16 who)
{
    struct C15cBattle *b;
    struct C15cIcon *e;
    u16 status = Combatant_GetStatus(who);
    u16 hp = Battle_GetHp(who);
    u16 maxHp = Battle_GetMaxHp(who);

    b = BB;
    e = &b->icons[who - 16];
    if (e->shown == 2)
        return e->unkB + 0x13;
    if (status & 0x8000)
        return 1;
    if ((s16)hp < (s16)maxHp >> 2)
        return 2;
    if (status & 0x4000)
        return 3;
    if (status & 0x2000)
        return 4;
    if (status & 0x1000)
        return 5;
    if (status & 0x800)
        return 6;
    if (status & 0x400)
        return 8;
    if (status & 0x200)
        return 9;
    if (status & 0x100)
        return 10;
    if (status & 0x80)
        return 11;
    if (status & 0x40)
        return 12;
    if (status & 0x20)
        return 13;
    if (status & 0x10)
        return 14;
    if (status & 8)
        return 15;
    if (status & 4)
        return 16;
    if (status & 2)
        return 17;
    if (status & 1)
        return 18;
    return 0;
}

// sub_080E7968 @ 0x080E7968
/* Per-frame animation of the enemy status icons. */
void sub_080E7968(void)
{
    struct C15cBattle *b = BB;
    u8 i;

    for (i = 16; i < 24; i++)
    {
        struct C15cIcon *e = &b->icons[i - 16];

        Battle_GetCombatant(i);
        switch (e->shown)
        {
        case 0:
            break;
        case 1:
            if (StatusIcon_ForCombatant(i) != e->icon)
                b->unkEC0 = 1;
            break;
        case 2:
            if (e->unkA < 10)
            {
                e->unkA++;
            }
            else
            {
                e->unkA = 0;
                b->unkEC0 = 1;
                if (++e->unkB > 4)
                {
                    e->shown = 0;
                    e->unkB = 0;
                }
            }
            break;
        case 3:
            if (e->unkA != 0)
            {
                e->unkA--;
            }
            else
            {
                e->unk6 -= 2;
                if (e->unk6 < -4)
                {
                    e->unk6 = -4;
                    e->shown = 1;
                }
            }
            break;
        case 4:
            e->unk6 += 2;
            if (e->unk6 > 12)
                e->shown = 0;
            break;
        }
    }
}

// sub_080E7A44 @ 0x080E7A44
/* Task: animates and draws the status icons; result 1 once no icon is left. */
void sub_080E7A44(struct Task *t)
{
    struct C15cBattle *b = BB;
    u8 done = 0;
    u8 cnt[2];
    u8 unused[16];
    struct C15cIcon *e;
    u8 i;
    u8 j;

    memset(cnt, 0, sizeof(cnt));
    memset(unused, 0, sizeof(unused));
    sub_080E7968();
    if (!Battle_IsTwoSided())
    {
        for (i = 0, j = 0; j < 8; j++)
        {
            e = &b->icons[j];
            if (e->shown)
                i++;
        }
        cnt[0] = i;
        if (i == 0)
        {
            done = 1;
            goto end;
        }
        for (i = 0; i < 8; i++)
        {
            e = &b->icons[i];
            if (e->shown && (e->shown != 3 || e->unkA == 0))
                Sprite_Draw(gUnknown_086BE718[i], 1, e->unk3, 2, 0, e->unk4, e->unk6);
        }
    }
    else
    {
        for (i = 0, j = 0; j < 4; j++)
        {
            e = &b->icons[j];
            if (e->shown)
                i++;
        }
        cnt[0] = i;
        if (i != 0)
        {
            for (i = 0; i < 4; i++)
            {
                e = &b->icons[i];
                if (e->shown && (e->shown != 3 || e->unkA == 0))
                    Sprite_Draw(gUnknown_086BE718[i], 1, e->unk3, 2, 0, e->unk4 + b->unk118C,
                                e->unk6 - b->unk119E);
            }
        }
        else
        {
            done = 2;
        }
        for (i = 0, j = 4; j < 8; j++)
        {
            e = &b->icons[j];
            if (e->shown)
                i++;
        }
        cnt[1] = i;
        if (b->unk119C != 0)
            cnt[1] = 0;
        if (cnt[1] != 0)
        {
            for (i = 4; i < 8; i++)
            {
                e = &b->icons[i];
                if (e->shown && (e->shown != 3 || e->unkA == 0))
                    Sprite_Draw(gUnknown_086BE718[i], 1, e->unk3, 2, 0, e->unk4 - b->unk118C,
                                e->unk6 - b->unk119E);
            }
            done = 0;
        }
        else if (done == 2)
        {
            done = 1;
        }
        else
        {
            done = 0;
        }
    }
end:
    if (b->unkEC0 == 1)
    {
        sub_080E7C98();
        b->unkEC0 = 0;
    }
    t->result = 0;
    if (done == 1)
        t->result = done;
}

// sub_080E7C98 @ 0x080E7C98
/* Rebuilds the icon tiles of every shown icon. */
void sub_080E7C98(void)
{
    struct C15cBattle *b = BB;
    u32 zero = 0;
    u8 i;

    CpuFastSet(&zero, gUnk_030010B4, 0x01000100);
    for (i = 0; i < 8; i++)
    {
        struct C15cIcon *e = &b->icons[i];

        if (e->shown)
        {
            const u8 *ic;

            e->icon = StatusIcon_ForCombatant(i + 16);
            ic = gUnknown_086BE6A4[e->icon];
            CpuFastSet(gUnknown_081A81B8 + ic[0] * 128, gUnk_030010B4 + i * 128, 0x20);
            e->slot = i;
            e->tile = ic[0];
            e->unk3 = ic[1];
        }
    }
    VBlankTask_AddCounted(sub_080E7364, 1);
    b->unkEC0 = 0;
}

// sub_080E7D30 @ 0x080E7D30
bool32 sub_080E7D30(u16 id)
{
    if ((*(const u16 *)Demon_GetGfxRecord(id) & 0x80FF) == 0x8000)
        return TRUE;
    return FALSE;
}
