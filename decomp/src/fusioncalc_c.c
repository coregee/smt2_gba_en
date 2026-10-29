#include "global.h"
#include "fusion.h"

/* Index of the result message (sub_081579A4) for demon id: from its record byte 0x21. */
// sub_0815B824 @ 0x0815B824
#ifdef NONMATCHING
u16 sub_0815B824(u16 id)
{
    u8 b = ((u8 *)Demon_GetRecord(id))[0x21];
    struct FusionCalc *c = &gUnk_0203B868;
    u8 v;

    c->unk292 = (b & 0xF0) >> 2;
    v = gUnknown_087F1CCC[(u16)((b & 0xF0) >> 2) + (b & 0xF)];
    if (v == 0xFF)
        v = 0xF;
    return v;
}
#else
NAKED
u16 sub_0815B824(u16 id)
{
    asm_unified(
        ".L0815B824:\n"
        "    push {lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Demon_GetRecord\n"
        "    adds r0, #0x21\n"
        "    ldrb r2, [r0]\n"
        "    ldr r1, .L0815B858\n"
        "    movs r0, #0xf0\n"
        "    ands r0, r2\n"
        "    lsrs r0, r0, #2\n"
        "    ldr r3, .L0815B85C\n"
        "    adds r1, r1, r3\n"
        "    strh r0, [r1]\n"
        "    movs r1, #0xf\n"
        "    ands r2, r1\n"
        "    adds r0, r0, r2\n"
        "    ldr r1, .L0815B860\n"
        "    adds r0, r0, r1\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0xff\n"
        "    bne .L0815B852\n"
        "    movs r0, #0xf\n"
        ".L0815B852:\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L0815B858: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L0815B85C: .4byte 0x00000292\n"
        ".L0815B860: .4byte gUnknown_087F1CCC\n"
    );
}
#endif

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
#ifdef NONMATCHING
void sub_0815B884(u16 a, u16 b, u16 c, u16 *out, u16 *out2)
{
    u32 r;

    gUnk_0203B868.ids[0] = Fusion_GetDemonByIndex(a);
    if (b != 0xFFFF)
        gUnk_0203B868.ids[1] = Fusion_GetDemonByIndex(b);
    else
        gUnk_0203B868.ids[1] |= b;
    gUnk_0203B868.ids[2] = c;
    Fusion_CalcItem();
    r = gUnk_0203B868.result;
    if (r != 0xFF)
        r = Fusion_GetIndexByDemon(r);
    *out = r;
    *out2 = gUnk_0203B868.result;
}
#else
NAKED
void sub_0815B884(u16 a, u16 b, u16 c, u16 *out, u16 *out2)
{
    asm_unified(
        ".L0815B884:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    adds r7, r3, #0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r4, r1, #0x10\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r6, r2, #0x10\n"
        "    bl Fusion_GetDemonByIndex\n"
        "    ldr r5, .L0815B8B4\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x90\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L0815B8B8\n"
        "    cmp r4, r0\n"
        "    beq .L0815B8BC\n"
        "    adds r0, r4, #0\n"
        "    bl Fusion_GetDemonByIndex\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x92\n"
        "    strh r0, [r1]\n"
        "    b .L0815B8C8\n"
        ".L0815B8B4: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
        ".L0815B8B8: .4byte 0x0000FFFF\n"
        ".L0815B8BC:\n"
        "    adds r2, r5, #0\n"
        "    adds r2, #0x92\n"
        "    ldrh r1, [r2]\n"
        "    adds r0, r4, #0\n"
        "    orrs r0, r1\n"
        "    strh r0, [r2]\n"
        ".L0815B8C8:\n"
        "    ldr r4, .L0815B8F4\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x94\n"
        "    strh r6, [r0]\n"
        "    bl Fusion_CalcItem\n"
        "    adds r4, #0xa0\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #0xff\n"
        "    beq .L0815B8E0\n"
        "    bl Fusion_GetIndexByDemon\n"
        ".L0815B8E0:\n"
        "    strh r0, [r7]\n"
        "    ldr r0, .L0815B8F4\n"
        "    adds r0, #0xa0\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, [sp, #0x14]\n"
        "    strh r1, [r0]\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L0815B8F4: .4byte 0x0203B868 @ EWRAM+0x3B868\n"
    );
}
#endif

/* Whether demon id may be fused: gated by the flag table 0x087F1D01, else (a == 0) by the
   exclusion list 0x087F1D72. */
// sub_0815B8F8 @ 0x0815B8F8
#ifdef NONMATCHING
u32 sub_0815B8F8(u16 id, u16 a)
{
    u16 i = 0;
    const u8 *t = gUnknown_087F1D01;

    while (t[i] != 0xFF)
    {
        if (id == t[i])
        {
            if (t[i + 1] != 0 && Flag_Test(t[i + 1]))
                return 1;
            return 0;
        }
        i += 2;
    }
    if (a == 0 && !sub_0815BA7C(id))
        return 0;
    return 1;
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
#ifdef NONMATCHING
u16 sub_0815B970(u16 x)
{
    u16 v = x & 0xFF;

    if (v <= 0x6F)
        return v << 8;
    else if (v <= 0x8F)
        return (v << 8) + 1;
    else
        return (v << 8) | 2;
}
#else
NAKED
u16 sub_0815B970(u16 x)
{
    asm_unified(
        ".L0815B970:\n"
        "    push {lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    movs r1, #0xff\n"
        "    lsls r1, r1, #0x10\n"
        "    ands r1, r0\n"
        "    lsrs r0, r1, #0x10\n"
        "    adds r1, r0, #0\n"
        "    cmp r0, #0x6f\n"
        "    bhi .L0815B986\n"
        "    lsls r0, r0, #8\n"
        "    b .L0815B99A\n"
        ".L0815B986:\n"
        "    cmp r0, #0x8f\n"
        "    bls .L0815B992\n"
        "    lsls r0, r0, #8\n"
        "    movs r1, #2\n"
        "    orrs r0, r1\n"
        "    b .L0815B99A\n"
        ".L0815B992:\n"
        "    lsls r0, r1, #8\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        ".L0815B99A:\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

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
    const u8 *t;

    if (id > 0xFE)
        return 0;
    t = gUnknown_087F1D22;
    while (t[i] != 0xFF)
    {
        if (id == t[i])
        {
            if (t[i + 1] == 0 || !Flag_Test(t[i + 1]))
                return 0;
            return 1;
        }
        i += 2;
    }
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
#ifdef NONMATCHING
u32 sub_0815BA7C(u16 id)
{
    u16 i = 0;
    const u16 *t = gUnknown_087F1D72;

    while (t[i] != 0xFFFF)
    {
        if (t[i] == id)
            return 0;
        i++;
    }
    return 1;
}
#else
NAKED
u32 sub_0815BA7C(u16 id)
{
    asm_unified(
        ".L0815BA7C:\n"
        "    push {r4, r5, r6, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    movs r2, #0\n"
        "    ldr r0, .L0815BAA4\n"
        "    ldrh r1, [r0]\n"
        "    ldr r3, .L0815BAA8\n"
        "    adds r4, r0, #0\n"
        "    cmp r1, r3\n"
        "    beq .L0815BABC\n"
        "    adds r6, r4, #0\n"
        "    adds r1, r3, #0\n"
        ".L0815BA94:\n"
        "    lsls r0, r2, #1\n"
        "    adds r0, r0, r6\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, r5\n"
        "    bne .L0815BAAC\n"
        "    movs r0, #0\n"
        "    b .L0815BABE\n"
        "    .byte 0x00, 0x00\n"
        ".L0815BAA4: .4byte gUnknown_087F1D72\n"
        ".L0815BAA8: .4byte 0x0000FFFF\n"
        ".L0815BAAC:\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    lsls r0, r2, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, r1\n"
        "    bne .L0815BA94\n"
        ".L0815BABC:\n"
        "    movs r0, #1\n"
        ".L0815BABE:\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

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
