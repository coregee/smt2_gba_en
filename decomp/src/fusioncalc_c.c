#include "global.h"
#include "fusion.h"

/* Index of the result message (sub_081579A4) for demon id: from its record byte 0x21. */
// sub_0815B824 @ 0x0815B824
u16 sub_0815B824(u16 id)
{
    u8 b = ((u8 *)Demon_GetRecord(id))[0x21];
    struct FusionCalc *c = &gUnk_0203B868;
    u8 v;
    u32 i;

    c->unk292 = (b & 0xF0) >> 2;
    i = (u16)((b & 0xF0) >> 2) + (b & 0xF);
    v = gUnknown_087F1CCC[i];
    if (v == 0xFF)
        v = 0xF;
    return v;
}

/* Alignment class of demon id: 0 below 0x70, 1 up to 0x8F, 2 above. */
// sub_0815B864 @ 0x0815B864
u32 sub_0815B864(u32 id)
{
    u32 a = sub_080ED550(id);

    if (a <= 0x6F)
        return 0;
    else if (a <= 0x8F)
        return 1;
    else
        return 2;
}

// sub_0815B880 @ 0x0815B880
void sub_0815B880(u16 n)
{
}

/* Item (or demon index) fusion: b == 0xFFFF for two materials; result index to *out. */
// sub_0815B884 @ 0x0815B884
void sub_0815B884(u16 a, u16 b, u16 c, u16 *out, u16 *out2)
{
    u16 r;

    gUnk_0203B868.ids[0] = Fusion_GetDemonByIndex(a);
    if (b != 0xFFFF)
        gUnk_0203B868.ids[1] = Fusion_GetDemonByIndex(b);
    else
        gUnk_0203B868.ids[1] |= b;
    gUnk_0203B868.ids[2] = c;
    Fusion_CalcItem();
    r = gUnk_0203B868.result;
    if (r != 0xFF)
        *out = Fusion_GetIndexByDemon(r);
    else
        *out = r;
    *out2 = gUnk_0203B868.result;
}

/* Whether demon id may be fused: gated by the flag table 0x087F1D01, else (a == 0) by the
   exclusion list 0x087F1D72. */
// sub_0815B8F8 @ 0x0815B8F8
#ifdef NONMATCHING
u32 sub_0815B8F8(u16 id, u16 a)
{
    u16 i = 0;

    while (gUnknown_087F1D01[i] != 0xFF)
    {
        if (id == gUnknown_087F1D01[i])
            goto found;
        i += 2;
    }
    if (a == 0 && !sub_0815BA7C(id))
        return 0;
    return 1;
found:
    if (gUnknown_087F1D01[i + 1] != 0 && Flag_Test(gUnknown_087F1D01[i + 1]))
        return 1;
    return 0;
}
#else
NAKED
u32 sub_0815B8F8(u16 id, u16 a)
{
    asm_unified(
        ".L0815B8F8:\n"
        "    push {r4, r5, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r5, r1, #0x10\n"
        "    movs r2, #0\n"
        "    ldr r0, .L0815B928\n"
        "    ldrb r1, [r0]\n"
        "    adds r3, r0, #0\n"
        "    cmp r1, #0xff\n"
        "    beq .L0815B942\n"
        ".L0815B90E:\n"
        "    adds r0, r2, r3\n"
        "    ldrb r0, [r0]\n"
        "    cmp r4, r0\n"
        "    beq .L0815B92C\n"
        "    adds r0, r2, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    adds r0, r2, r3\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0xff\n"
        "    bne .L0815B90E\n"
        "    b .L0815B942\n"
        "    .byte 0x00, 0x00\n"
        ".L0815B928: .4byte gUnknown_087F1D01\n"
        ".L0815B92C:\n"
        "    adds r0, r2, #1\n"
        "    adds r1, r0, r3\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0\n"
        "    beq .L0815B93E\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L0815B950\n"
        ".L0815B93E:\n"
        "    movs r0, #0\n"
        "    b .L0815B952\n"
        ".L0815B942:\n"
        "    cmp r5, #0\n"
        "    bne .L0815B950\n"
        "    adds r0, r4, #0\n"
        "    bl sub_0815BA7C\n"
        "    cmp r0, #0\n"
        "    beq .L0815B93E\n"
        ".L0815B950:\n"
        "    movs r0, #1\n"
        ".L0815B952:\n"
        "    pop {r4, r5}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

// sub_0815B958 @ 0x0815B958
u16 sub_0815B958(u16 id)
{
    return sub_0815B970(Demon_GetRecord(id)->unkC);
}

/* Alignment byte -> (byte << 8) | class (0, 1, 2). */
// sub_0815B970 @ 0x0815B970
u16 sub_0815B970(u16 x)
{
    x &= 0xFF;

    if (x <= 0x6F)
        return x << 8;
    else if (x <= 0x8F)
        return (x << 8) + 1;
    else
        return (x << 8) | 2;
}

// Demon_GetLevel @ 0x0815B9A0
u8 Demon_GetLevel(u16 id)
{
    return Demon_GetRecord(id & 0xFF)->level;
}

// Demon_GetRaceAndAlign @ 0x0815B9B8
void Demon_GetRaceAndAlign(u16 id, u8 *align, u8 *race)
{
    *race = Demon_GetRace(id);
    *align = gUnknown_087F153D[*race];
}

/* Race of demon id (ids >= 0x100 by table 0x087F1569, else from the race start table). */
// Demon_GetRace @ 0x0815B9DC
u16 Demon_GetRace(u16 id)
{
    u16 i;

    if (id & 0xFF00)
        return gUnknown_087F1569[id & 0xFF];
    if (id == 0xFF)
        return 0xFF;
    i = 0;
    if (id >= gUnknown_087F1514[0])
    {
        do
            i++;
        while (id >= gUnknown_087F1514[i]);
    }
    return i;
}

/* Whether demon id is available as a fusion result (flag table 0x087F1D22). */
// sub_0815BA28 @ 0x0815BA28
#ifdef NONMATCHING
u32 sub_0815BA28(u16 id)
{
    u16 i = 0;

    if (id > 0xFE)
        return 0;
    while (gUnknown_087F1D22[i] != 0xFF)
    {
        if (id == gUnknown_087F1D22[i])
            goto found;
        i += 2;
    }
    return 1;
found:
    if (gUnknown_087F1D22[i + 1] == 0 || !Flag_Test(gUnknown_087F1D22[i + 1]))
        return 0;
    return 1;
}
#else
NAKED
u32 sub_0815BA28(u16 id)
{
    asm_unified(
        ".L0815BA28:\n"
        "    push {r4, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    movs r2, #0\n"
        "    cmp r4, #0xfe\n"
        "    bhi .L0815BA6E\n"
        "    ldr r0, .L0815BA58\n"
        "    ldrb r1, [r0]\n"
        "    adds r3, r0, #0\n"
        "    cmp r1, #0xff\n"
        "    beq .L0815BA72\n"
        ".L0815BA3E:\n"
        "    adds r0, r2, r3\n"
        "    ldrb r0, [r0]\n"
        "    cmp r4, r0\n"
        "    beq .L0815BA5C\n"
        "    adds r0, r2, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    adds r0, r2, r3\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0xff\n"
        "    bne .L0815BA3E\n"
        "    b .L0815BA72\n"
        "    .byte 0x00, 0x00\n"
        ".L0815BA58: .4byte gUnknown_087F1D22\n"
        ".L0815BA5C:\n"
        "    adds r0, r2, #1\n"
        "    adds r1, r0, r3\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0\n"
        "    beq .L0815BA6E\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L0815BA72\n"
        ".L0815BA6E:\n"
        "    movs r0, #0\n"
        "    b .L0815BA74\n"
        ".L0815BA72:\n"
        "    movs r0, #1\n"
        ".L0815BA74:\n"
        "    pop {r4}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// sub_0815BA7C @ 0x0815BA7C
u32 sub_0815BA7C(u16 id)
{
    u16 i;

    for (i = 0; gUnknown_087F1D72[i] != 0xFFFF; i++)
    {
        if (gUnknown_087F1D72[i] == id)
            return 0;
    }
    return 1;
}

// sub_0815BAC4 @ 0x0815BAC4
u32 sub_0815BAC4(void)
{
    return 1;
}

/* Adds n to the count of item (0x54-0xB1), capped at 255. */
// ItemStock_Add @ 0x0815BAC8
u32 ItemStock_Add(u16 item, u16 n)
{
    u16 k = ItemStock_GetIndex(item);
    u16 v;

    if (k != 0xFFFF)
    {
        v = gGameState.itemCounts[k];
        v += n;
        if (v & 0xFF00)
            v = 0xFF;
        gGameState.itemCounts[k] = v;
        return 1;
    }
    return 0;
}

/* Subtracts n from the count of item, not below 0. */
// ItemStock_Remove @ 0x0815BB18
u32 ItemStock_Remove(u16 item, u16 n)
{
    u16 k = ItemStock_GetIndex(item);
    u16 v;

    if (k != 0xFFFF)
    {
        v = gGameState.itemCounts[k];
        if (v > n)
            v = v - n;
        else
            v = 0;
        gGameState.itemCounts[k] = v;
        return 1;
    }
    return 0;
}

// ItemStock_GetIndex @ 0x0815BB70
u16 ItemStock_GetIndex(u16 item)
{
    if (item > 0x53)
    {
        if (item <= 0xB1)
            return item - 0x54;
    }
    return 0xFFFF;
}
