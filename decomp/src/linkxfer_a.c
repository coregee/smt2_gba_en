#include "global.h"
#include "options.h"

// Link_Checksum @ 0x080DF6D0
/* Sum of n bytes (16-bit). */
u16 Link_Checksum(u16 n, const u8 *p)
{
    u16 sum = 0;
    u16 i;

    for (i = 0; i < n; i++)
    {
        sum += *p;
        p++;
    }
    return sum;
}

// sub_080DF6FC @ 0x080DF6FC
/* TRUE when both players' last packet carries header hdr. */
/* NONMATCHING: register allocation. */
#ifdef NONMATCHING
u8 sub_080DF6FC(u16 hdr)
{
    u8 ok[4];
    u8 i;

    for (i = 0; i < 4; i++)
    {
        if (i < 2 && gUnk_03006340[i].hdr != hdr)
            ok[i] = 0;
        else
            ok[i] = 1;
    }
    if (ok[0] == 1 && ok[1] == 1)
    {
        ok[2] = 1;
        ok[3] = 1;
        return TRUE;
    }
    return FALSE;
}
#else
NAKED
u8 sub_080DF6FC(u16 hdr)
{
    asm_unified(
        ".L080DF6FC:\n"
        "    push {r4, r5, r6, lr}\n"
        "    sub sp, #4\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    movs r1, #0\n"
        "    ldr r5, .L080DF724\n"
        "    movs r2, #1\n"
        "    movs r4, #0\n"
        ".L080DF70C:\n"
        "    cmp r1, #1\n"
        "    bhi .L080DF728\n"
        "    lsls r0, r1, #4\n"
        "    adds r0, r0, r5\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, r3\n"
        "    beq .L080DF728\n"
        "    mov r6, sp\n"
        "    adds r0, r6, r1\n"
        "    strb r4, [r0]\n"
        "    b .L080DF72E\n"
        "    .byte 0x00, 0x00\n"
        ".L080DF724: .4byte 0x03006340 @ IWRAM+0x6340\n"
        ".L080DF728:\n"
        "    mov r6, sp\n"
        "    adds r0, r6, r1\n"
        "    strb r2, [r0]\n"
        ".L080DF72E:\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r1, r0, #0x18\n"
        "    cmp r1, #3\n"
        "    bls .L080DF70C\n"
        "    mov r0, sp\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #1\n"
        "    bne .L080DF754\n"
        "    mov r0, sp\n"
        "    ldrb r0, [r0, #1]\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #1\n"
        "    bne .L080DF754\n"
        "    mov r0, sp\n"
        "    strb r1, [r0, #2]\n"
        "    strb r1, [r0, #3]\n"
        "    movs r0, #1\n"
        "    b .L080DF756\n"
        ".L080DF754:\n"
        "    movs r0, #0\n"
        ".L080DF756:\n"
        "    add sp, #4\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// sub_080DF760 @ 0x080DF760
/* Fills the send packet with header 0xE300 + block and the next 12 bytes (zero padded);
   returns 0xFF once the data is exhausted. */
u8 sub_080DF760(void)
{
    struct C0cdLink *l = &gUnk_03006300;
    const u8 *src;
    u8 *d;
    u8 end;
    u8 i;

    gUnk_03006380[0] = (u8)l->block + 0xE300;
    src = l->src;
    d = (u8 *)&gUnk_03006380[1];
    end = 0;
    for (i = 0; i < 12; i++)
    {
        if (l->size > l->sent)
        {
            *d++ = *src++;
            l->sent++;
        }
        else
        {
            *d++ = 0;
            end = 0xFF;
        }
    }
    l->src = src;
    return end;
}

// sub_080DF7B8 @ 0x080DF7B8
/* Copies the 12-byte blocks received from both players once both carry the expected header;
   0 = not yet, 1 = more to come, 0xFF = done. */
/* NONMATCHING: register allocation. */
#ifdef NONMATCHING
u32 sub_080DF7B8(void)
{
    struct C0cdLink *l = &gUnk_03006300;
    u16 recv[2];
    u32 result;
    u8 i, j;

    if (sub_080DF6FC(0xE300 + l->block) != 1)
        return 0;
    result = 1;
    for (i = 0; i < 2; i++)
    {
        const u8 *s = gUnk_03006340[i].data;
        u8 *d = l->dst[i];
        u16 *n = &recv[i];

        *n = l->recv;
        for (j = 0; j < 12; j++)
        {
            if (l->size > *n)
            {
                *d++ = *s++;
                (*n)++;
            }
            else
            {
                result = 0xFF;
            }
        }
        l->dst[i] = d;
    }
    l->recv = recv[0];
    if (result == 1)
        l->block++;
    return result;
}
#else
NAKED
u32 sub_080DF7B8(void)
{
    asm_unified(
        ".L080DF7B8:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #4\n"
        "    ldr r7, .L080DF7E4\n"
        "    movs r1, #0xe3\n"
        "    lsls r1, r1, #8\n"
        "    adds r0, r1, #0\n"
        "    ldrh r4, [r7, #2]\n"
        "    adds r0, r0, r4\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl sub_080DF6FC\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    beq .L080DF7E8\n"
        "    movs r0, #0\n"
        "    b .L080DF866\n"
        ".L080DF7E4: .4byte 0x03006300 @ IWRAM+0x6300\n"
        ".L080DF7E8:\n"
        "    movs r6, #1\n"
        "    mov r8, r6\n"
        "    movs r4, #0\n"
        "    ldr r0, .L080DF830\n"
        "    mov sb, r0\n"
        "    movs r1, #0x1c\n"
        "    adds r1, r1, r7\n"
        "    mov ip, r1\n"
        ".L080DF7F8:\n"
        "    lsls r0, r4, #4\n"
        "    mov r6, sb\n"
        "    adds r5, r0, r6\n"
        "    lsls r2, r4, #2\n"
        "    mov r1, ip\n"
        "    adds r0, r1, r2\n"
        "    ldr r3, [r0]\n"
        "    lsls r0, r4, #1\n"
        "    mov r6, sp\n"
        "    adds r1, r6, r0\n"
        "    ldrh r0, [r7, #0xa]\n"
        "    strh r0, [r1]\n"
        "    movs r6, #0\n"
        "    adds r4, #1\n"
        "    mov sl, r4\n"
        ".L080DF816:\n"
        "    ldrh r0, [r7, #6]\n"
        "    ldrh r4, [r1]\n"
        "    cmp r0, r4\n"
        "    bls .L080DF834\n"
        "    ldrb r0, [r5]\n"
        "    strb r0, [r3]\n"
        "    adds r5, #1\n"
        "    adds r3, #1\n"
        "    ldrh r0, [r1]\n"
        "    adds r0, #1\n"
        "    strh r0, [r1]\n"
        "    b .L080DF838\n"
        "    .byte 0x00, 0x00\n"
        ".L080DF830: .4byte 0x03006342 @ IWRAM+0x6342\n"
        ".L080DF834:\n"
        "    movs r0, #0xff\n"
        "    mov r8, r0\n"
        ".L080DF838:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r6, r0, #0x18\n"
        "    cmp r6, #0xb\n"
        "    bls .L080DF816\n"
        "    mov r1, ip\n"
        "    adds r0, r1, r2\n"
        "    str r3, [r0]\n"
        "    mov r4, sl\n"
        "    lsls r0, r4, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    cmp r4, #1\n"
        "    bls .L080DF7F8\n"
        "    mov r0, sp\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r7, #0xa]\n"
        "    mov r6, r8\n"
        "    cmp r6, #1\n"
        "    bne .L080DF864\n"
        "    ldrh r0, [r7, #2]\n"
        "    adds r0, #1\n"
        "    strh r0, [r7, #2]\n"
        ".L080DF864:\n"
        "    mov r0, r8\n"
        ".L080DF866:\n"
        "    add sp, #4\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// Link_StartTransfer @ 0x080DF878
/* Starts a transfer of size bytes from data; out holds the two destination pointers. */
/* NONMATCHING: register allocation. */
#ifdef NONMATCHING
void Link_StartTransfer(u16 size, const u8 *data, u32 *out)
{
    struct C0cdLink *l = &gUnk_03006300;
    u8 *buf = gShopItemIds;
    u32 *rx = (u32 *)gShopItemPrices;
    u16 i;

    for (i = 0; i < 0x100; i++)
    {
        *buf++ = 0;
        *rx++ = 0;
    }
    l->seq++;
    l->size = size;
    l->sent = 0;
    l->recv = 0;
    buf = gShopItemIds;
    for (i = 0; i < l->size; i++)
        *buf++ = *data++;
    l->sum = Link_Checksum(l->size, gShopItemIds);
    l->unk04 = 0;
    l->block = 0;
    for (i = 0; i < 2; i++)
    {
        l->unk0E[i] = 0;
        l->dst[i] = gShopItemPrices[i];
        l->out[i] = out[i];
    }
    l->src = gShopItemIds;
    gUnk_0300636C = 1;
}
#else
NAKED
void Link_StartTransfer(u16 size, const u8 *data, u32 *out)
{
    asm_unified(
        ".L080DF878:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #4\n"
        "    mov ip, r1\n"
        "    str r2, [sp]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldr r4, .L080DF944\n"
        "    ldr r1, .L080DF948\n"
        "    ldr r7, .L080DF94C\n"
        "    movs r3, #0\n"
        "    mov r8, r1\n"
        "    movs r5, #0\n"
        "    movs r2, #0\n"
        ".L080DF89A:\n"
        "    strb r5, [r1]\n"
        "    adds r1, #1\n"
        "    stm r7!, {r2}\n"
        "    adds r0, r3, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    cmp r3, #0xff\n"
        "    bls .L080DF89A\n"
        "    ldrh r0, [r4]\n"
        "    adds r0, #1\n"
        "    movs r1, #0\n"
        "    strh r0, [r4]\n"
        "    strh r6, [r4, #6]\n"
        "    strh r1, [r4, #8]\n"
        "    strh r1, [r4, #0xa]\n"
        "    mov r1, ip\n"
        "    mov r2, r8\n"
        "    movs r3, #0\n"
        "    adds r5, r4, #0\n"
        "    adds r5, #0xe\n"
        "    movs r0, #0x1c\n"
        "    adds r0, r0, r4\n"
        "    mov sb, r0\n"
        "    movs r0, #0x2c\n"
        "    adds r0, r0, r4\n"
        "    mov sl, r0\n"
        "    cmp r3, r6\n"
        "    bhs .L080DF8E6\n"
        ".L080DF8D2:\n"
        "    ldrb r0, [r1]\n"
        "    strb r0, [r2]\n"
        "    adds r1, #1\n"
        "    adds r2, #1\n"
        "    adds r0, r3, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    ldrh r0, [r4, #6]\n"
        "    cmp r3, r0\n"
        "    blo .L080DF8D2\n"
        ".L080DF8E6:\n"
        "    ldrh r0, [r4, #6]\n"
        "    ldr r1, .L080DF948\n"
        "    bl Link_Checksum\n"
        "    movs r1, #0\n"
        "    strh r0, [r4, #0xc]\n"
        "    strh r1, [r4, #4]\n"
        "    strh r1, [r4, #2]\n"
        "    movs r3, #0\n"
        "    adds r7, r5, #0\n"
        "    mov r8, r3\n"
        "    mov r6, sb\n"
        "    ldr r1, .L080DF94C\n"
        "    mov ip, r1\n"
        "    mov r5, sl\n"
        ".L080DF904:\n"
        "    lsls r0, r3, #1\n"
        "    adds r0, r7, r0\n"
        "    mov r1, r8\n"
        "    strh r1, [r0]\n"
        "    lsls r1, r3, #2\n"
        "    adds r2, r6, r1\n"
        "    lsls r0, r3, #8\n"
        "    add r0, ip\n"
        "    str r0, [r2]\n"
        "    adds r2, r5, r1\n"
        "    ldr r0, [sp]\n"
        "    adds r1, r1, r0\n"
        "    ldr r0, [r1]\n"
        "    str r0, [r2]\n"
        "    adds r0, r3, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    cmp r3, #1\n"
        "    bls .L080DF904\n"
        "    ldr r0, .L080DF948\n"
        "    str r0, [r4, #0x18]\n"
        "    ldr r1, .L080DF950\n"
        "    movs r0, #1\n"
        "    strb r0, [r1]\n"
        "    add sp, #4\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080DF944: .4byte 0x03006300 @ IWRAM+0x6300\n"
        ".L080DF948: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L080DF94C: .4byte 0x0203BD74 @ EWRAM+0x3BD74\n"
        ".L080DF950: .4byte 0x0300636C @ IWRAM+0x636C\n"
    );
}
#endif

// Link_Exchange @ 0x080DF954
/* Exchanges size bytes of data with the other player: the local copy goes to the slot of this
   machine's multiplayer id (SIOCNT bits 4-5), the other player's data to dst. */
void Link_Exchange(u16 size, const u8 *data, u32 dst)
{
    u32 out[2];

    if (((*(vu32 *)(REG_BASE + 0x128) << 26) >> 30) == 0)
    {
        out[0] = (u32)(gShopItemIds + 0x100);
        out[1] = dst;
    }
    else
    {
        out[1] = (u32)(gShopItemIds + 0x100);
        out[0] = dst;
    }
    Link_StartTransfer(size, data, out);
}

// sub_080DF990 @ 0x080DF990
/* Verifies the received data of both players against their checksums and copies it out;
   0xFF when a checksum fails. */
u32 sub_080DF990(void)
{
    struct C0cdLink *l = &gUnk_03006300;
    u8 result = 0;
    u8 i;

    for (i = 0; i < 2; i++)
    {
        u8 *s = gShopItemPrices[i];
        u16 sum = Link_Checksum(l->size, s);

        if (l->unk0E[i] == sum)
        {
            u8 *d = (u8 *)l->out[i];
            u16 j;

            for (j = 0; j < l->size; j++)
                *d++ = *s++;
        }
        else
        {
            result = 0xFF;
        }
    }
    return result;
}

// Link_TransferStep @ 0x080DFA00
/* Runs one step of the transfer started by Link_StartTransfer: header exchange (0xE100 + checksum),
   data blocks (0xE300), end (0xE400), retry on a checksum error (0xE500).  Returns 1 when done,
   0xFF after 600 frames without progress. */
/* NONMATCHING: register allocation. */
#ifdef NONMATCHING
u8 Link_TransferStep(void)
{
    u8 busy = 0;
    u8 done = 0;
    struct C0cdLink *l = &gUnk_03006300;
    u8 i;
    u8 r;

    switch (gUnk_0300636C)
    {
    case 0:
        break;
    case 1:
        gUnk_03006380[0] = 0xE100;
        gUnk_03006380[1] = l->sum;
        gUnk_0300636C = 2;
        break;
    case 2:
        busy = 1;
        if (sub_080DF6FC(0xE100) != 1)
            goto out;
        for (i = 0; i < 2; i++)
            l->unk0E[i] = *(u16 *)gUnk_03006340[i].data;
        gUnk_0300636C = 3;
        sub_080DF760();
        break;
    case 3:
        busy = 1;
        i = sub_080DF7B8();
        if (i == 0xFF)
        {
            gUnk_03006380[0] = 0xE400;
            gUnk_0300636C = 4;
        }
        else if (i == 1)
        {
            sub_080DF760();
        }
        else
        {
            goto out;
        }
        break;
    case 4:
        busy = 1;
        if (sub_080DF6FC(0xE400) == 1)
        {
            r = sub_080DF990();
            if (r == 0)
            {
                gUnk_0300636C = r;
                done = 1;
                gUnk_03006380[0] = r;
            }
            else
            {
                gUnk_0300636C = 5;
                gUnk_03006380[0] = 0xE500;
            }
        }
        goto out;
    case 5:
        busy = 1;
        if (sub_080DF6FC(0xE500) != 1)
            goto out;
        gUnk_03006380[0] = 0xE100;
        gUnk_03006380[1] = l->sum;
        gUnk_0300636C = 2;
        break;
    default:
        goto out;
    }
    busy = 0;
out:
    if (sub_080DFB98())
        busy = 1;
    if (busy)
        gUnk_03006390++;
    else
        gUnk_03006390 = busy;
    if (gUnk_03006390 > 599)
        return 0xFF;
    return done;
}
#else
NAKED
u8 Link_TransferStep(void)
{
    asm_unified(
        ".L080DFA00:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    ldr r4, .L080DFA20\n"
        "    movs r7, #0\n"
        "    movs r5, #0\n"
        "    ldr r0, .L080DFA24\n"
        "    ldrb r1, [r0]\n"
        "    adds r6, r0, #0\n"
        "    cmp r1, #5\n"
        "    bls .L080DFA14\n"
        "    b .L080DFB3E\n"
        ".L080DFA14:\n"
        "    lsls r0, r1, #2\n"
        "    ldr r1, .L080DFA28\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080DFA20: .4byte 0x03006300 @ IWRAM+0x6300\n"
        ".L080DFA24: .4byte 0x0300636C @ IWRAM+0x636C\n"
        ".L080DFA28: .4byte gUnknown_080DFA2C\n"
        "    .global gUnknown_080DFA2C\n"
        "gUnknown_080DFA2C:\n"
        ".L080DFA2C: @ jump table\n"
        "    .4byte .L080DFB3C\n"
        "    .4byte .L080DFA44\n"
        "    .4byte .L080DFA5C\n"
        "    .4byte .L080DFAA0\n"
        "    .4byte .L080DFACE\n"
        "    .4byte .L080DFB18\n"
        ".L080DFA44:\n"
        "    ldr r1, .L080DFA58\n"
        "    movs r0, #0xe1\n"
        "    lsls r0, r0, #8\n"
        "    strh r0, [r1]\n"
        "    ldrh r0, [r4, #0xc]\n"
        "    strh r0, [r1, #2]\n"
        "    movs r0, #2\n"
        "    strb r0, [r6]\n"
        "    b .L080DFB3C\n"
        "    .byte 0x00, 0x00\n"
        ".L080DFA58: .4byte 0x03006380 @ IWRAM+0x6380\n"
        ".L080DFA5C:\n"
        "    movs r5, #1\n"
        "    movs r0, #0xe1\n"
        "    lsls r0, r0, #8\n"
        "    bl sub_080DF6FC\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bne .L080DFB3E\n"
        "    movs r2, #0\n"
        "    ldr r6, .L080DFA98\n"
        "    adds r3, r4, #0\n"
        "    adds r3, #0xe\n"
        "    ldr r4, .L080DFA9C\n"
        ".L080DFA78:\n"
        "    lsls r1, r2, #1\n"
        "    adds r1, r3, r1\n"
        "    lsls r0, r2, #4\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r1]\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r2, r0, #0x18\n"
        "    cmp r2, #1\n"
        "    bls .L080DFA78\n"
        "    movs r0, #3\n"
        "    strb r0, [r6]\n"
        "    bl sub_080DF760\n"
        "    b .L080DFB3C\n"
        ".L080DFA98: .4byte 0x0300636C @ IWRAM+0x636C\n"
        ".L080DFA9C: .4byte 0x03006342 @ IWRAM+0x6342\n"
        ".L080DFAA0:\n"
        "    movs r5, #1\n"
        "    bl sub_080DF7B8\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #0xff\n"
        "    bne .L080DFAC4\n"
        "    ldr r1, .L080DFABC\n"
        "    movs r0, #0xe4\n"
        "    lsls r0, r0, #8\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L080DFAC0\n"
        "    movs r0, #4\n"
        "    b .L080DFB3A\n"
        ".L080DFABC: .4byte 0x03006380 @ IWRAM+0x6380\n"
        ".L080DFAC0: .4byte 0x0300636C @ IWRAM+0x636C\n"
        ".L080DFAC4:\n"
        "    cmp r0, #1\n"
        "    bne .L080DFB3E\n"
        "    bl sub_080DF760\n"
        "    b .L080DFB3C\n"
        ".L080DFACE:\n"
        "    movs r5, #1\n"
        "    movs r0, #0xe4\n"
        "    lsls r0, r0, #8\n"
        "    bl sub_080DF6FC\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bne .L080DFB3E\n"
        "    bl sub_080DF990\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r1, r0, #0x18\n"
        "    cmp r1, #0\n"
        "    bne .L080DFB00\n"
        "    ldr r0, .L080DFAF8\n"
        "    strb r1, [r0]\n"
        "    movs r7, #1\n"
        "    ldr r0, .L080DFAFC\n"
        "    strh r1, [r0]\n"
        "    b .L080DFB3E\n"
        ".L080DFAF8: .4byte 0x0300636C @ IWRAM+0x636C\n"
        ".L080DFAFC: .4byte 0x03006380 @ IWRAM+0x6380\n"
        ".L080DFB00:\n"
        "    ldr r1, .L080DFB10\n"
        "    movs r0, #5\n"
        "    strb r0, [r1]\n"
        "    ldr r1, .L080DFB14\n"
        "    movs r0, #0xe5\n"
        "    lsls r0, r0, #8\n"
        "    strh r0, [r1]\n"
        "    b .L080DFB3E\n"
        ".L080DFB10: .4byte 0x0300636C @ IWRAM+0x636C\n"
        ".L080DFB14: .4byte 0x03006380 @ IWRAM+0x6380\n"
        ".L080DFB18:\n"
        "    movs r5, #1\n"
        "    movs r0, #0xe5\n"
        "    lsls r0, r0, #8\n"
        "    bl sub_080DF6FC\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bne .L080DFB3E\n"
        "    ldr r1, .L080DFB5C\n"
        "    movs r0, #0xe1\n"
        "    lsls r0, r0, #8\n"
        "    strh r0, [r1]\n"
        "    ldrh r0, [r4, #0xc]\n"
        "    strh r0, [r1, #2]\n"
        "    ldr r1, .L080DFB60\n"
        "    movs r0, #2\n"
        ".L080DFB3A:\n"
        "    strb r0, [r1]\n"
        ".L080DFB3C:\n"
        "    movs r5, #0\n"
        ".L080DFB3E:\n"
        "    bl sub_080DFB98\n"
        "    lsls r0, r0, #0x18\n"
        "    cmp r0, #0\n"
        "    beq .L080DFB4A\n"
        "    movs r5, #1\n"
        ".L080DFB4A:\n"
        "    cmp r5, #0\n"
        "    beq .L080DFB68\n"
        "    ldr r1, .L080DFB64\n"
        "    ldrh r0, [r1]\n"
        "    adds r0, #1\n"
        "    strh r0, [r1]\n"
        "    adds r0, r1, #0\n"
        "    b .L080DFB6C\n"
        "    .byte 0x00, 0x00\n"
        ".L080DFB5C: .4byte 0x03006380 @ IWRAM+0x6380\n"
        ".L080DFB60: .4byte 0x0300636C @ IWRAM+0x636C\n"
        ".L080DFB64: .4byte 0x03006390 @ IWRAM+0x6390\n"
        ".L080DFB68:\n"
        "    ldr r0, .L080DFB78\n"
        "    strh r5, [r0]\n"
        ".L080DFB6C:\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L080DFB7C\n"
        "    cmp r1, r0\n"
        "    bhi .L080DFB80\n"
        "    adds r0, r7, #0\n"
        "    b .L080DFB82\n"
        ".L080DFB78: .4byte 0x03006390 @ IWRAM+0x6390\n"
        ".L080DFB7C: .4byte 0x00000257\n"
        ".L080DFB80:\n"
        "    movs r0, #0xff\n"
        ".L080DFB82:\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

// Link_GetMultiplayerId @ 0x080DFB88
/* This machine's multiplayer id (SIOCNT bits 4-5). */
u32 Link_GetMultiplayerId(void)
{
    return (*(vu32 *)(REG_BASE + 0x128) << 26) >> 30;
}

// sub_080DFB98 @ 0x080DFB98
/* Link error from the status word at 0x03006360: 0x10, 0x20, 0xFF (player count mismatch) or 0. */
u8 sub_080DFB98(void)
{
    u8 err = 0;
    u32 s = gUnk_03006360;

    if (s & 0x1000)
        err = 0x10;
    else if (s & 0x2000)
        err = 0x20;
    else if ((s & 0x8000) && ((s << 28) >> 28) != ((s << 20) >> 28))
        err = 0xFF;
    return err;
}

// sub_080DFBE0 @ 0x080DFBE0
/* TRUE after 121 frames without transfer progress. */
u32 sub_080DFBE0(void)
{
    if (gUnk_03006390 > 120)
        return TRUE;
    return FALSE;
}

// sub_080DFBFC @ 0x080DFBFC
void sub_080DFBFC(void)
{
    struct C0cdLinkData *d = &gLinkData;
    u32 zero = 0;

    {
        vu32 tmp = zero;
        CpuSet((void *)&tmp, d, 0x05000034);
    }
    d->magic = 0x15273950;
    d->unk08 = zero;
    d->unk04 = zero;
    d->unk14 = zero;
    LinkTrade_ClearItemOffers(d);
    LinkTrade_ClearDemonOffers(d);
    d->unk0C = zero;
    d->money = Money_Get();
    d->mag = Magnetite_Get();
    d->unk1C = zero;
    d->unk20 = 0xFF;
    d->unk54 = zero;
    d->unk56 = zero;
}

// sub_080DFC58 @ 0x080DFC58
void sub_080DFC58(void)
{
    DigitFont_DrawStringTinted(gUnknown_08589C94, gUnk_02001000, 0, 0, 0, 8);
    DigitFont_DrawStringTinted(gUnknown_08589C94, gUnk_02001000, 0x50, 0, 4, 8);
    DigitFont_DrawStringTinted(gUnknown_08589CA0, gUnk_02001000, 0xA0, 0, 4, 8);
}

// sub_080DFCB4 @ 0x080DFCB4
void sub_080DFCB4(void)
{
    DmaSet3(gUnk_02001000, 0x06016000, 0x84000400);
}

// sub_080DFCD8 @ 0x080DFCD8
/* Five-entry menu: A returns cursor + 1 in t->pad1E, B returns 0xFF. */
void sub_080DFCD8(struct Task *t)
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
        t->pad1E = 0xFF;
        t->result = 1;
        Sound_Play(0x66);
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

// sub_080DFD6C @ 0x080DFD6C
void sub_080DFD6C(struct Task *t)
{
    struct Task *p = Task_GetParent(t);

    Text_DrawSpriteString(gUnknown_08589CA8[p->data.h[0]], 0, 0, 0x14, 0x64, 0xC);
}

// sub_080DFD9C @ 0x080DFD9C
void sub_080DFD9C(void)
{
    Palette_CopyWithEffect(3, gUnknown_08580F80, gUnk_030030F0, 0xC0, 0x20);
    Palette_MarkDirty();
}

// SpriteFont_DrawAscii @ 0x080DFDC4
/* Draws ASCII character c (0x20-0x5F) as an 8x8 sprite (tiles from 0x2FA, 32 per row). */
void SpriteFont_DrawAscii(u16 c, u16 pal, u16 x, u16 y)
{
    u16 i = c - 0x20;
    u16 tile;

    if (i < 0x40)
    {
        tile = i + (i >> 5) * 32;
        tile += 0x2FA;
        Sprite_Draw(gUnknown_080087C8, 0, pal, 0, tile, x, y);
    }
}

// sub_080DFE14 @ 0x080DFE14
/* Sets up the six-digit entry of the two amounts (unk04, unk08) with their limits. */
void sub_080DFE14(void)
{
    struct C0cdLinkData *d = &gLinkData;
    struct C0cdLinkBet *bet = &gLink.bet;
    u32 a, b;

    bet->cursor = 5;
    bet->a = a = d->unk04;
    bet->b = b = d->unk08;
    bet->maxA = d->unk0C;
    bet->maxB = d->money;
    bet->digits[0] = a / 100000;
    bet->digits[1] = a / 10000 % 10;
    bet->digits[2] = a / 1000 % 10;
    bet->digits[3] = a / 100 % 10;
    bet->digits[4] = a / 10 % 10;
    bet->digits[5] = a % 10;
    bet->digits[6] = b / 100000;
    bet->digits[7] = b / 10000 % 10;
    bet->digits[8] = b / 1000 % 10;
    bet->digits[9] = b / 100 % 10;
    bet->digits[10] = b / 10 % 10;
    bet->digits[11] = b % 10;
}

// sub_080DFF08 @ 0x080DFF08
/* Amount entry input: A clamps both amounts to their limits and accepts, B cancels (0xFF),
   SELECT clears, left/L and right/R move the digit cursor, up/down change a digit of b. */
void sub_080DFF08(struct Task *t)
{
    struct C0cdLinkBet *bet = &gLink.bet;
    struct C0cdLinkData *d = (struct C0cdLinkData *)((u8 *)bet - 0xB0);
    u8 i;

    t->pad1E = 0;
    t->result = 0;
    if (gKeysNew & 1)
    {
        u32 a, b;

        Sound_Play(0x65);
        t->result = 1;
        if (bet->maxA < bet->a)
            bet->a = bet->maxA;
        d->unk04 = a = bet->a;
        if (bet->maxB < bet->b)
            bet->b = bet->maxB;
        d->unk08 = b = bet->b;
        bet->digits[0] = a / 100000;
        bet->digits[1] = a / 10000 % 10;
        bet->digits[2] = a / 1000 % 10;
        bet->digits[3] = a / 100 % 10;
        bet->digits[4] = a / 10 % 10;
        bet->digits[5] = a % 10;
        bet->digits[6] = b / 100000;
        bet->digits[7] = b / 10000 % 10;
        bet->digits[8] = b / 1000 % 10;
        bet->digits[9] = b / 100 % 10;
        bet->digits[10] = b / 10 % 10;
        bet->digits[11] = b % 10;
    }
    else if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        t->result = 1;
        t->pad1E = 0xFF;
    }
    else if (gKeysNew & 4)
    {
        Sound_Play(0x66);
        bet->a = 0;
        bet->b = 0;
        d->unk04 = 0;
        d->unk08 = 0;
        for (i = 0; i < 6; i++)
        {
            bet->digits[i] = 0;
            bet->digits[i + 6] = 0;
        }
    }
    else if (gRepeatedKeys & 0x220)
    {
        if (--bet->cursor < 0)
            bet->cursor = 5;
        Sound_Play(0x64);
    }
    else if (gRepeatedKeys & 0x110)
    {
        if (++bet->cursor > 5)
            bet->cursor = 0;
        Sound_Play(0x64);
    }
    else if (gRepeatedKeys & 0x40)
    {
        bet->digits[bet->cursor + 6]++;
        if (bet->digits[bet->cursor + 6] > 9)
            bet->digits[bet->cursor + 6] = 0;
        Sound_Play(0x64);
    }
    else if (gRepeatedKeys & 0x80)
    {
        bet->digits[bet->cursor + 6]--;
        if (bet->digits[bet->cursor + 6] < 0)
            bet->digits[bet->cursor + 6] = 9;
        Sound_Play(0x64);
    }
    bet->a = bet->digits[0] * 100000 + bet->digits[1] * 10000 + bet->digits[2] * 1000
           + bet->digits[3] * 100 + bet->digits[4] * 10 + bet->digits[5];
    bet->b = bet->digits[6] * 100000 + bet->digits[7] * 10000 + bet->digits[8] * 1000
           + bet->digits[9] * 100 + bet->digits[10] * 10 + bet->digits[11];
}

// sub_080E01AC @ 0x080E01AC
/* Draws the amount entry: b with the cursor digit highlighted between '>' and '<', then
   "TOTAL" and the limit maxB, as sprite characters. */
void sub_080E01AC(struct Task *t)
{
    struct C0cdLinkBet *bet;
    u8 *d;
    s8 i;

    Task_GetParent(t);
    bet = &gLink.bet;
    SpriteFont_DrawAscii('^', 10, 0x58, 0xE);
    d = NumberToDigits(bet->b);
    for (i = 5; i >= 0; i--)
    {
        if (bet->cursor == i)
        {
            u16 c = *d + '0';
            u16 x = i * 8 + 0x62;

            SpriteFont_DrawAscii(c, 0xC, x, 0xE);
            SpriteFont_DrawAscii('>', 10, x, 3);
            SpriteFont_DrawAscii('<', 10, x, 0x15);
        }
        else
        {
            SpriteFont_DrawAscii(*d + '0', 10, i * 8 + 0x62, 0xE);
        }
        d++;
    }
    SpriteFont_DrawAscii('T', 0xC, 0x56, 0x25);
    SpriteFont_DrawAscii('O', 0xC, 0x5E, 0x25);
    SpriteFont_DrawAscii('T', 0xC, 0x66, 0x25);
    SpriteFont_DrawAscii('A', 0xC, 0x6E, 0x25);
    SpriteFont_DrawAscii('L', 0xC, 0x76, 0x25);
    SpriteFont_DrawAscii('^', 10, 0x58, 0x31);
    d = NumberToDigits(bet->maxB);
    for (i = 5; i >= 0; i--)
    {
        SpriteFont_DrawAscii(*d + '0', 10, i * 8 + 0x62, 0x31);
        d++;
    }
}

// sub_080E02B0 @ 0x080E02B0
void sub_080E02B0(struct C0cdLinkData *d, struct C0cdLinkBet *bet)
{
    u32 a, b;

    bet->cursor = 0xFF;
    bet->a = a = d->unk04;
    bet->b = b = d->unk08;
    bet->maxA = d->unk0C;
    bet->maxB = d->money;
    bet->digits[0] = a / 100000;
    bet->digits[1] = a / 10000 % 10;
    bet->digits[2] = a / 1000 % 10;
    bet->digits[3] = a / 100 % 10;
    bet->digits[4] = a / 10 % 10;
    bet->digits[5] = a % 10;
    bet->digits[6] = b / 100000;
    bet->digits[7] = b / 10000 % 10;
    bet->digits[8] = b / 1000 % 10;
    bet->digits[9] = b / 100 % 10;
    bet->digits[10] = b / 10 % 10;
    bet->digits[11] = b % 10;
}

// sub_080E039C @ 0x080E039C
void sub_080E039C(void)
{
    sub_080E02B0(&gLink.rec[0], &gLink.bet);
}

// sub_080E03B0 @ 0x080E03B0
void sub_080E03B0(void)
{
    sub_080E02B0(&gLink.rec[1], &gLink.bet);
}

// sub_080E03C4 @ 0x080E03C4
/* Sets up the five-digit entry of rec[0].unk14 (limit: magnetite) in the task data. */
void sub_080E03C4(struct Task *t)
{
    struct C0cdLinkData *d = &gLinkData;
    struct C0cdLinkEntry *e = (struct C0cdLinkEntry *)&t->data.raw[0x2C];
    u32 v;

    e->cursor = 4;
    e->value = v = d->unk14;
    e->max = d->mag;
    e->digits[0] = v / 10000 % 10;
    e->digits[1] = v / 1000 % 10;
    e->digits[2] = v / 100 % 10;
    e->digits[3] = v / 10 % 10;
    e->digits[4] = v % 10;
}

// sub_080E0434 @ 0x080E0434
/* Input of that entry, like sub_080DFF08. */
void sub_080E0434(struct Task *t)
{
    struct C0cdLinkEntry *e = (struct C0cdLinkEntry *)&t->data.raw[0x2C];
    struct C0cdLinkData *d = &gLinkData;
    u8 i;

    t->pad1E = 0;
    t->result = 0;
    if (gKeysNew & 1)
    {
        u32 v;

        Sound_Play(0x65);
        t->result = 1;
        if (e->max < e->value)
            e->value = e->max;
        d->unk14 = v = e->value;
        e->digits[0] = v / 10000 % 10;
        e->digits[1] = v / 1000 % 10;
        e->digits[2] = v / 100 % 10;
        e->digits[3] = v / 10 % 10;
        e->digits[4] = v % 10;
    }
    else if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        t->result = 1;
        t->pad1E = 0xFF;
    }
    else if (gKeysNew & 4)
    {
        Sound_Play(0x66);
        e->value = 0;
        d->unk14 = 0;
        for (i = 0; i < 5; i++)
            e->digits[i] = 0;
    }
    else if (gRepeatedKeys & 0x220)
    {
        if (--e->cursor < 0)
            e->cursor = 4;
        Sound_Play(0x64);
    }
    else if (gRepeatedKeys & 0x110)
    {
        if (++e->cursor > 4)
            e->cursor = 0;
        Sound_Play(0x64);
    }
    else if (gRepeatedKeys & 0x40)
    {
        e->digits[e->cursor]++;
        if (e->digits[e->cursor] > 9)
            e->digits[e->cursor] = 0;
        Sound_Play(0x64);
    }
    else if (gRepeatedKeys & 0x80)
    {
        e->digits[e->cursor]--;
        if (e->digits[e->cursor] < 0)
            e->digits[e->cursor] = 9;
        Sound_Play(0x64);
    }
    e->value = e->digits[0] * 10000 + e->digits[1] * 1000 + e->digits[2] * 100
             + e->digits[3] * 10 + e->digits[4];
}

// sub_080E0600 @ 0x080E0600
/* Draws the five-digit entry (cursor digit between '>' and '<'), "TOTAL" and its limit. */
void sub_080E0600(struct Task *t)
{
    struct C0cdLinkEntry *e;
    u8 *d;
    s8 i;

    Task_GetParent(t);
    e = (struct C0cdLinkEntry *)&t->data.raw[0x2C];
    d = NumberToDigits(e->value);
    for (i = 4; i >= 0; i--)
    {
        if (e->cursor == i)
        {
            u16 c = *d + '0';
            u16 x = i * 8 + 0x62;

            SpriteFont_DrawAscii(c, 0xC, x, 0xE);
            SpriteFont_DrawAscii('>', 10, x, 3);
            SpriteFont_DrawAscii('<', 10, x, 0x15);
        }
        else
        {
            SpriteFont_DrawAscii(*d + '0', 10, i * 8 + 0x62, 0xE);
        }
        d++;
    }
    SpriteFont_DrawAscii('T', 0xC, 0x56, 0x25);
    SpriteFont_DrawAscii('O', 0xC, 0x5E, 0x25);
    SpriteFont_DrawAscii('T', 0xC, 0x66, 0x25);
    SpriteFont_DrawAscii('A', 0xC, 0x6E, 0x25);
    SpriteFont_DrawAscii('L', 0xC, 0x76, 0x25);
    d = NumberToDigits(e->max);
    for (i = 4; i >= 0; i--)
    {
        SpriteFont_DrawAscii(*d + '0', 10, i * 8 + 0x62, 0x31);
        d++;
    }
}

// sub_080E06EC @ 0x080E06EC
void sub_080E06EC(struct C0cdLinkData *d, struct C0cdLinkEntry *e)
{
    u32 v;

    e->cursor = 0xFF;
    e->value = v = d->unk14;
    e->max = d->mag;
    e->digits[0] = v / 10000 % 10;
    e->digits[1] = v / 1000 % 10;
    e->digits[2] = v / 100 % 10;
    e->digits[3] = v / 10 % 10;
    e->digits[4] = v % 10;
}

// sub_080E0754 @ 0x080E0754
void sub_080E0754(struct Task *t)
{
    sub_080E06EC(&gLink.rec[0], (struct C0cdLinkEntry *)&t->data.raw[0x2C]);
}

// sub_080E0768 @ 0x080E0768
void sub_080E0768(struct Task *t)
{
    sub_080E06EC(&gLink.rec[1], (struct C0cdLinkEntry *)&t->data.raw[0x2C]);
}
