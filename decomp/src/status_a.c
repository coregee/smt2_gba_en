#include "global.h"
#include "status.h"

// sub_080C9100 @ 0x080C9100
/* Picks a special encounter: 0 for none, else 0x30-0x34. Unless flag 0xD8 is set, it runs
   once (flag 0xC4) and only when the moon phase differs from a randomly chosen phase (then
   with chance 1/8). Two of the eight random branches test phase 0; phase 0x40 is never
   chosen (probably a typo for 0x40 in the original). */
u32 sub_080C9100(void)
{
    u8 phase = Moon_GetPhase() & 0xF0;

    if (phase > 0x8F)
    {
        phase -= 0x80;
        phase = 0x80 - phase;
    }
    if (!Flag_Test(0xD8))
    {
        if (Flag_Test(0xC4))
            return 0;
        Flag_Set(0xC4);
        if ((Random_Byte() & 0xFF) > 0x7F)
        {
            if ((Random_Byte() & 0xFF) > 0x7F)
            {
                if ((Random_Byte() & 0xFF) > 0x7F)
                {
                    if (phase == 0)
                        return 0;
                }
                else if (phase == 0x10)
                    return 0;
            }
            else
            {
                if ((Random_Byte() & 0xFF) > 0x7F)
                {
                    if (phase == 0x20)
                        return 0;
                }
                else if (phase == 0x30)
                    return 0;
            }
        }
        else
        {
            if ((Random_Byte() & 0xFF) > 0x7F)
            {
                if ((Random_Byte() & 0xFF) > 0x7F)
                {
                    if (phase == 0)
                        return 0;
                }
                else if (phase == 0x50)
                    return 0;
            }
            else
            {
                if ((Random_Byte() & 0xFF) > 0x7F)
                {
                    if (phase == 0x60)
                        return 0;
                }
                else if (phase == 0x70)
                    return 0;
            }
        }
        if ((Random_Byte() & 0xFF) > 0x1F)
            return 0;
    }
    if ((Random_Byte() & 0xFF) > 0x7F)
    {
        if ((Random_Byte() & 0xFF) > 0x7F)
        {
            if ((Random_Byte() & 0xFF) > 0x7F)
                return 0x34;
            return 0x31;
        }
        if ((Random_Byte() & 0xFF) > 0x7F)
            return 0x32;
        return 0x33;
    }
    if (!Flag_Test(0xD8) && (Random_Byte() & 0xFF) <= 0x3F)
        return 0;
    return 0x30;
}

// sub_080C9210 @ 0x080C9210
const u16 *sub_080C9210(u16 kind)
{
    if (kind == 1)
        return gUnknown_084EEAE4;
    if (kind == 2)
        return gUnknown_084EEF28;
    if (kind == 3)
        return gUnknown_084EF368;
    return gUnknown_084EF7B0;
}

// sub_080C9248 @ 0x080C9248
/* Finds id in the (id, value) list of kind; NULL if absent. */
const u16 *sub_080C9248(u16 kind, u16 id)
{
    const u16 *p = sub_080C9210(kind);

    for (;;)
    {
        if (*p == 0xFFFF)
            return NULL;
        if (*p == id)
            return p;
        p += 2;
    }
}

// sub_080C9278 @ 0x080C9278
u16 sub_080C9278(u16 i)
{
    return gStatusList[i] & 0x7FFF;
}

// sub_080C9290 @ 0x080C9290
u16 sub_080C9290(u16 i)
{
    return gStatusList[i] & 0x8000;
}

// sub_080C92AC @ 0x080C92AC
u32 sub_080C92AC(u16 id)
{
    u32 r = 0;

    if ((u16)(id - 0x150) <= 0x19)
        r = 1;
    return r;
}

// Status_GetCombatant @ 0x080C92C8
/* The combatant of list entry i: a member, or (bit 15) a demon built in the menu state. */
#ifdef NONMATCHING
struct Combatant *Status_GetCombatant(u16 i)
{
    struct C0c6Status *st = &gMenuState;

    if (sub_080C9290(i) == 0)
        return &gGameState.members[sub_080C9278(i)];
    Combatant_InitDemon(&st->demon, 4, sub_080C9278(st->sel));
    if (sub_080C92AC(st->demon.demonId) == 1)
    {
        u8 attr[8];

        Item_GetAttribute(Fusion_GetDemonByIndex(st->demon.demonId), 5, attr);
        st->demon.total[0] = attr[0];
        st->demon.total[1] = attr[1];
        st->demon.total[2] = attr[2];
        st->demon.total[3] = attr[3];
        st->demon.total[4] = attr[4];
        st->demon.total[5] = attr[5];
        st->demon.base[0] = 0;
        st->demon.base[1] = 0;
        st->demon.base[2] = 0;
        st->demon.base[3] = 0;
        st->demon.base[4] = 0;
        st->demon.base[5] = 0;
    }
    return &st->demon;
}
#else
NAKED
struct Combatant *Status_GetCombatant(u16 i)
{
    asm_unified(
        ".L080C92C8:\n"
        "    push {r4, r5, r6, lr}\n"
        "    sub sp, #8\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    ldr r5, .L080C92F0\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080C9290\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C92F8\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080C9278\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #9\n"
        "    ldr r1, .L080C92F4\n"
        "    adds r0, r0, r1\n"
        "    b .L080C937E\n"
        "    .byte 0x00, 0x00\n"
        ".L080C92F0: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L080C92F4: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080C92F8:\n"
        "    adds r6, r5, #0\n"
        "    adds r6, #0x54\n"
        "    ldrh r0, [r5, #2]\n"
        "    bl sub_080C9278\n"
        "    adds r2, r0, #0\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    adds r0, r6, #0\n"
        "    movs r1, #4\n"
        "    bl Combatant_InitDemon\n"
        "    adds r4, r5, #0\n"
        "    adds r4, #0x66\n"
        "    ldrh r0, [r4]\n"
        "    bl sub_080C92AC\n"
        "    cmp r0, #1\n"
        "    bne .L080C937C\n"
        "    ldrh r0, [r4]\n"
        "    bl Fusion_GetDemonByIndex\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r4, sp\n"
        "    movs r1, #5\n"
        "    mov r2, sp\n"
        "    bl Item_GetAttribute\n"
        "    mov r0, sp\n"
        "    ldrb r1, [r0]\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x94\n"
        "    movs r2, #0\n"
        "    strb r1, [r0]\n"
        "    ldrb r0, [r4, #1]\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x95\n"
        "    strb r0, [r1]\n"
        "    ldrb r0, [r4, #2]\n"
        "    adds r1, #1\n"
        "    strb r0, [r1]\n"
        "    ldrb r0, [r4, #3]\n"
        "    adds r1, #1\n"
        "    strb r0, [r1]\n"
        "    ldrb r1, [r4, #4]\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x98\n"
        "    strb r1, [r0]\n"
        "    ldrb r0, [r4, #5]\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x99\n"
        "    strb r0, [r1]\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x7c\n"
        "    strb r2, [r0]\n"
        "    adds r0, #1\n"
        "    strb r2, [r0]\n"
        "    adds r0, #1\n"
        "    strb r2, [r0]\n"
        "    adds r0, #1\n"
        "    strb r2, [r0]\n"
        "    adds r0, #1\n"
        "    strb r2, [r0]\n"
        "    adds r0, #1\n"
        "    strb r2, [r0]\n"
        ".L080C937C:\n"
        "    adds r0, r6, #0\n"
        ".L080C937E:\n"
        "    add sp, #8\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// sub_080C9388 @ 0x080C9388
u32 sub_080C9388(u16 i)
{
    u32 r = 0;

    if (sub_080C9290(i) == 0 && sub_080C9278(i) <= 3)
        r = 1;
    return r;
}

// sub_080C93B4 @ 0x080C93B4
u32 sub_080C93B4(u16 i)
{
    u32 r = 0;

    if (sub_080C9290(i) == 0 && sub_080C9278(i) == 0)
        r = 1;
    return r;
}

// sub_080C93E0 @ 0x080C93E0
void sub_080C93E0(void)
{
    DmaCopy32(3, gUnk_0200F874, (void *)0x06014000, 0x1000);
}

// sub_080C9404 @ 0x080C9404
void sub_080C9404(void)
{
    Font_ResetGlyphSpriteCache(0x180);
}

// sub_080C9414 @ 0x080C9414
void sub_080C9414(void)
{
    struct C0c6Status *st = &gMenuState;

    if (st->mode == 5)
    {
        struct Combatant *c = Status_GetCombatant(st->sel);

        CpuSet(c, &st->demon, 0x04000020);
        c->equip[0] = 0xFF;
        c->equip[1] = 0xFF;
        c->equip[2] = 0xFF;
        c->equip[3] = 0xFF;
        c->equip[4] = 0xFF;
        c->equip[5] = 0xFF;
        c->equip[6] = 0xFF;
        c->pad27 = 0xFF;
        Combatant_RecalcStats(c->id);
        CpuSet(c, &st->preview, 0x04000020);
    }
}

// Status_BuildList @ 0x080C947C
/* Builds the list of combatants the status screen pages through (gStatusList; bit 15 marks
   a demon id) for the screen mode. */
#ifdef NONMATCHING
void Status_BuildList(void)
{
    struct C0c6Status *st = &gMenuState;
    u16 *list = gStatusList;
    u16 n = 0;
    u16 n2 = 0;
    u16 i;
    u16 v;

    LZ77UnCompWram(gUnknown_081B5870, gUnk_0200F874);
    VBlankTask_AddCounted(sub_080C93E0, 1);
    switch (st->mode)
    {
    case 0:
        for (i = 0; i < 16; i++)
        {
            if (gGameState.members[i].unkE != 0)
                list[n] = i;
                n++;
        }
        st->count = n;
        break;
    case 1:
        i = 0;
        goto check;
    body:
        if (!Flag_Test(0xB6))
        {
            if (v & 0x8000)
                goto next;
        }
        else if (v & 0x8000)
        {
            list[n] = v | 0x8000;
            n++;
            goto next;
        }
        list[n] = v + 0x8000;
        n++;
        n2++;
    next:
        i++;
    check:
        if (i <= 0xFF && (v = sub_0812ACCC(i)) != 0xFFFF)
            goto body;
        st->count = n;
        st->count2 = n2;
        break;
    case 3:
        for (i = 0; i < 4; i++)
        {
            if (gGameState.members[i].unkE != 0)
                list[n] = i;
                n++;
        }
        st->count = n;
        break;
    case 4:
    case 5:
        CpuSet(&gGameState.members[st->sel], &st->saved, 0x04000020);
        list[0] = st->sel;
        st->count = 1;
        st->sel = 0;
        sub_080C9414();
        break;
    case 6:
        list[0] = 0x8000 + gUnk_0203B854[3];
        st->count = 1;
        st->sel = 0;
        break;
    case 8:
    case 9:
    case 10:
        list[0] = 0x8000 + st->sel;
        st->count = 1;
        st->sel = 0;
        break;
    }
    st->unk10 = 0;
    if (sub_080C9388(st->sel) == 1)
        st->unk16 = 1;
    else
        st->unk16 = 0;
    st->unk18 = 1;
    st->unk1C = 0;
    st->unk1E = 0;
}
#else
NAKED
void Status_BuildList(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sb\n"
        "    mov r6, r8\n"
        "    push {r6, r7}\n"
        "    ldr r7, .L080C94B0\n"
        "    ldr r0, .L080C94B4\n"
        "    mov sb, r0\n"
        "    movs r5, #0\n"
        "    mov r8, r5\n"
        "    ldr r0, .L080C94B8\n"
        "    ldr r1, .L080C94BC\n"
        "    bl LZ77UnCompWram\n"
        "    ldr r0, .L080C94C0\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    ldrh r0, [r7]\n"
        "    cmp r0, #0xa\n"
        "    bls .L080C94A6\n"
        "    b .L080C9622\n"
        ".L080C94A6:\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L080C94C4\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        ".L080C94B0: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L080C94B4: .4byte 0x0203B554 @ EWRAM+0x3B554\n"
        ".L080C94B8: .4byte gUnknown_081B5870\n"
        ".L080C94BC: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L080C94C0: .4byte sub_080C93E0\n"
        ".L080C94C4: .4byte gUnknown_080C94C8\n"
        "    .global gUnknown_080C94C8\n"
        "gUnknown_080C94C8:\n"
        ".L080C94C8: @ jump table\n"
        "    .4byte .L080C94F4\n"
        "    .4byte .L080C9520\n"
        "    .4byte .L080C9622\n"
        "    .4byte .L080C9598\n"
        "    .4byte .L080C95C4\n"
        "    .4byte .L080C95C4\n"
        "    .4byte .L080C95F4\n"
        "    .4byte .L080C9622\n"
        "    .4byte .L080C960C\n"
        "    .4byte .L080C960C\n"
        "    .4byte .L080C960C\n"
        ".L080C94F4:\n"
        "    movs r6, #0\n"
        "    ldr r1, .L080C951C\n"
        ".L080C94F8:\n"
        "    lsls r0, r6, #7\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0, #0xe]\n"
        "    cmp r0, #0\n"
        "    beq .L080C950E\n"
        "    lsls r0, r5, #1\n"
        "    add r0, sb\n"
        "    strh r6, [r0]\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        ".L080C950E:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r6, #0xf\n"
        "    bls .L080C94F8\n"
        "    strh r5, [r7, #0x24]\n"
        "    b .L080C9622\n"
        ".L080C951C: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080C9520:\n"
        "    movs r6, #0\n"
        "    b .L080C9576\n"
        ".L080C9524:\n"
        "    movs r0, #0xb6\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L080C953C\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    adds r0, r4, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L080C9570\n"
        "    b .L080C9548\n"
        ".L080C953C:\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    adds r0, r4, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L080C9562\n"
        ".L080C9548:\n"
        "    lsls r0, r5, #1\n"
        "    add r0, sb\n"
        "    adds r1, r4, r1\n"
        "    strh r1, [r0]\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    mov r0, r8\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        "    b .L080C9570\n"
        ".L080C9562:\n"
        "    lsls r0, r5, #1\n"
        "    add r0, sb\n"
        "    orrs r4, r1\n"
        "    strh r4, [r0]\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        ".L080C9570:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        ".L080C9576:\n"
        "    cmp r6, #0xff\n"
        "    bhi .L080C958A\n"
        "    adds r0, r6, #0\n"
        "    bl sub_0812ACCC\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    ldr r0, .L080C9594\n"
        "    cmp r4, r0\n"
        "    bne .L080C9524\n"
        ".L080C958A:\n"
        "    strh r5, [r7, #0x24]\n"
        "    mov r1, r8\n"
        "    strh r1, [r7, #0x26]\n"
        "    b .L080C9622\n"
        "    .byte 0x00, 0x00\n"
        ".L080C9594: .4byte 0x0000FFFF\n"
        ".L080C9598:\n"
        "    movs r6, #0\n"
        "    ldr r1, .L080C95C0\n"
        ".L080C959C:\n"
        "    lsls r0, r6, #7\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0, #0xe]\n"
        "    cmp r0, #0\n"
        "    beq .L080C95B2\n"
        "    lsls r0, r5, #1\n"
        "    add r0, sb\n"
        "    strh r6, [r0]\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        ".L080C95B2:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r6, #3\n"
        "    bls .L080C959C\n"
        "    strh r5, [r7, #0x24]\n"
        "    b .L080C9622\n"
        ".L080C95C0: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080C95C4:\n"
        "    ldrh r0, [r7, #2]\n"
        "    lsls r0, r0, #7\n"
        "    ldr r1, .L080C95EC\n"
        "    adds r0, r0, r1\n"
        "    adds r1, r7, #0\n"
        "    adds r1, #0xd4\n"
        "    ldr r2, .L080C95F0\n"
        "    bl CpuSet\n"
        "    ldrh r0, [r7, #2]\n"
        "    mov r2, sb\n"
        "    strh r0, [r2]\n"
        "    movs r1, #0\n"
        "    movs r0, #1\n"
        "    strh r0, [r7, #0x24]\n"
        "    strh r1, [r7, #2]\n"
        "    bl sub_080C9414\n"
        "    b .L080C9622\n"
        "    .byte 0x00, 0x00\n"
        ".L080C95EC: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080C95F0: .4byte 0x04000020 @ REG_BG2PA\n"
        ".L080C95F4:\n"
        "    ldr r1, .L080C9608\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #8\n"
        "    adds r0, r2, #0\n"
        "    ldrh r1, [r1, #6]\n"
        "    adds r0, r0, r1\n"
        "    mov r1, sb\n"
        "    strh r0, [r1]\n"
        "    b .L080C961A\n"
        "    .byte 0x00, 0x00\n"
        ".L080C9608: .4byte 0x0203B854 @ EWRAM+0x3B854\n"
        ".L080C960C:\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #8\n"
        "    adds r0, r2, #0\n"
        "    ldrh r1, [r7, #2]\n"
        "    adds r0, r0, r1\n"
        "    mov r2, sb\n"
        "    strh r0, [r2]\n"
        ".L080C961A:\n"
        "    movs r1, #0\n"
        "    movs r0, #1\n"
        "    strh r0, [r7, #0x24]\n"
        "    strh r1, [r7, #2]\n"
        ".L080C9622:\n"
        "    movs r4, #0\n"
        "    strh r4, [r7, #0x10]\n"
        "    ldrh r0, [r7, #2]\n"
        "    bl sub_080C9388\n"
        "    cmp r0, #1\n"
        "    bne .L080C9634\n"
        "    strh r0, [r7, #0x16]\n"
        "    b .L080C9636\n"
        ".L080C9634:\n"
        "    strh r4, [r7, #0x16]\n"
        ".L080C9636:\n"
        "    movs r1, #0\n"
        "    movs r0, #1\n"
        "    strh r0, [r7, #0x18]\n"
        "    strh r1, [r7, #0x1c]\n"
        "    strh r1, [r7, #0x1e]\n"
        "    pop {r3, r4}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

// sub_080C964C @ 0x080C964C
u32 sub_080C964C(u16 which)
{
    struct C0c6Status *st = &gMenuState;

    if (which == 0)
        return st->count;
    if (st->mode == 1)
        return st->count2;
    return st->count;
}

// sub_080C9670 @ 0x080C9670
void sub_080C9670(void)
{
    sub_0812CC70(0);
}

// sub_080C967C @ 0x080C967C
void sub_080C967C(void)
{
    sub_08128B84(1);
}

// sub_080C9688 @ 0x080C9688
void sub_080C9688(void)
{
    sub_08128B84(2);
}

// sub_080C9694 @ 0x080C9694
void sub_080C9694(void)
{
}

// sub_080C9698 @ 0x080C9698
void sub_080C9698(void)
{
    Field_SetState(0x19);
}

// sub_080C96A4 @ 0x080C96A4
void sub_080C96A4(void)
{
}

// sub_080C96A8 @ 0x080C96A8
/* Starts the fade-out to the screen the status screen returns to (by mode). */
void sub_080C96A8(void)
{
    struct C0c6Status *st = &gMenuState;

    switch (st->mode)
    {
    case 0:
        st->fade = sub_080B6B58(sub_080C9670, 0);
        break;
    case 1:
        st->fade = sub_080B6B58(sub_080C9688, 0);
        break;
    case 3:
        st->fade = sub_080B6B58(sub_080C967C, 0);
        break;
    case 4:
        st->fade = sub_080B6B58(sub_080EA178, 0);
        break;
    case 5:
        st->fade = sub_080B6B58(sub_080C9694, 0);
        break;
    case 6:
        st->fade = sub_080B6B58(sub_080C9698, 0);
        break;
    case 8:
    case 9:
    case 10:
        st->fade = sub_080B6B58(sub_080C9698, 0);
        break;
    case 11:
    case 12:
        st->fade = sub_080B6B58(sub_080C96A4, 0);
        break;
    }
}

// sub_080C9744 @ 0x080C9744
void sub_080C9744(struct Task *t)
{
    struct C0c6Status *st = &gMenuState;

    Status_GetCombatant(st->sel);
    if (st->fade->unkC == -1)
    {
        t->result = 1;
        if (sub_080C9388(st->sel) != 1)
        {
            gPaletteBuffer[0xD0] = 0x10;
            gPaletteBuffer[0xD1] = 0x10;
        }
    }
    else
        t->result = 0;
}

// sub_080C9794 @ 0x080C9794
void sub_080C9794(void)
{
    gMenuState.fade->unkC = 1;
}

// sub_080C97A4 @ 0x080C97A4
void sub_080C97A4(const u32 *src, u32 *dst)
{
    u32 i;

    for (i = 0; i < 24; i++)
        *dst++ = *src++;
}

// sub_080C97B8 @ 0x080C97B8
#ifdef NONMATCHING
void sub_080C97B8(u32 frame)
{
    u32 off = frame * 96;
    const u8 *src = gUnknown_081B4F10;
    u8 *dst = gUnk_0200FC74;

    sub_080C97A4((const u32 *)(src + off), (u32 *)dst);
    src += 0x400;
    dst += 0x400;
    sub_080C97A4((const u32 *)(src + off), (u32 *)dst);
}
#else
NAKED
void sub_080C97B8(u32 frame)
{
    asm_unified(
        ".L080C97B8:\n"
        "    push {r4, r5, r6, lr}\n"
        "    lsls r5, r0, #1\n"
        "    adds r5, r5, r0\n"
        "    lsls r5, r5, #5\n"
        "    ldr r4, .L080C97E8\n"
        "    adds r0, r5, r4\n"
        "    ldr r6, .L080C97EC\n"
        "    adds r1, r6, #0\n"
        "    bl sub_080C97A4\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #3\n"
        "    adds r4, r4, r0\n"
        "    adds r0, r5, r4\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #3\n"
        "    adds r6, r6, r1\n"
        "    adds r1, r6, #0\n"
        "    bl sub_080C97A4\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080C97E8: .4byte gUnknown_081B4F10\n"
        ".L080C97EC: .4byte 0x0200FC74 @ EWRAM+0xFC74\n"
    );
}
#endif

// sub_080C97F0 @ 0x080C97F0
void sub_080C97F0(struct Task *t, u32 frame)
{
    if (gMenuState.unk22 != 1 && sub_080C964C(1) != 1)
    {
        sub_080C97B8(frame);
        sub_080C9994();
    }
}

// sub_080C981C @ 0x080C981C
#ifdef NONMATCHING
void sub_080C981C(u32 frame)
{
    u32 off = frame * 96;
    const u8 *src = gUnknown_081B4FD0;
    u8 *dst = gUnk_0200FFD4;

    sub_080C97A4((const u32 *)(src + off), (u32 *)dst);
    src += 0x400;
    dst += 0x400;
    sub_080C97A4((const u32 *)(src + off), (u32 *)dst);
}
#else
NAKED
void sub_080C981C(u32 frame)
{
    asm_unified(
        ".L080C981C:\n"
        "    push {r4, r5, r6, lr}\n"
        "    lsls r5, r0, #1\n"
        "    adds r5, r5, r0\n"
        "    lsls r5, r5, #5\n"
        "    ldr r4, .L080C984C\n"
        "    adds r0, r5, r4\n"
        "    ldr r6, .L080C9850\n"
        "    adds r1, r6, #0\n"
        "    bl sub_080C97A4\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #3\n"
        "    adds r4, r4, r0\n"
        "    adds r0, r5, r4\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #3\n"
        "    adds r6, r6, r1\n"
        "    adds r1, r6, #0\n"
        "    bl sub_080C97A4\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080C984C: .4byte gUnknown_081B4FD0\n"
        ".L080C9850: .4byte 0x0200FFD4 @ EWRAM+0xFFD4\n"
    );
}
#endif

// sub_080C9854 @ 0x080C9854
void sub_080C9854(struct Task *t, u32 frame)
{
    if (gMenuState.unk22 != 1 && sub_080C964C(1) != 1)
    {
        sub_080C981C(frame);
        sub_080C9994();
    }
}

// sub_080C9880 @ 0x080C9880
/* Sets tile i of the BG tilemap at 0x06001000 to palette 1. */
void sub_080C9880(u16 i)
{
    u16 pal = 0x1000;
    u16 *map = (u16 *)0x06001000;

    map[i] = (map[i] & 0xFFF) | pal;
}

// sub_080C98A0 @ 0x080C98A0
void sub_080C98A0(void)
{
    REG_BG2CNT &= 0x3FFF;
    REG_BG2CNT |= 0x4000;
    REG_BG1CNT = 0x4205;
    gUnk_03000040 = 0x3844;
}

// sub_080C98E0 @ 0x080C98E0
void sub_080C98E0(void)
{
    struct C0c6Status *st = &gMenuState;

    sub_080C98A0();
    DmaCopy32(3, gUnknown_081B93B0, (void *)0x06001000, 0x800);
    DmaFill32(3, 0, (void *)0x06001800, 0x800);
    DmaCopy32(3, gUnk_0200F874, (void *)0x06004000, 0x7C00);
    sub_080C9880(0);
    sub_080C9880(1);
    sub_080C9880(2);
    sub_080C9880(0x20);
    sub_080C9880(0x21);
    sub_080C9880(0x22);
    sub_080C9880(0x1B);
    sub_080C9880(0x1C);
    sub_080C9880(0x1D);
    sub_080C9880(0x3B);
    sub_080C9880(0x3C);
    sub_080C9880(0x3D);
    st->unk0C = 0;
}

// sub_080C9994 @ 0x080C9994
void sub_080C9994(void)
{
    struct C0c6Status *st = &gMenuState;

    if (st->unk0C == 0)
    {
        VBlankTask_AddCounted(sub_080C98E0, 1);
        st->unk0C = 1;
    }
}

// sub_080C99B8 @ 0x080C99B8
/* Always 0 (both branches). */
u32 sub_080C99B8(struct Combatant *c)
{
    if (c->id == 0)
        return 0;
    return 0;
}
