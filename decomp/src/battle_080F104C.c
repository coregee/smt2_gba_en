#include "global.h"
#include "battle.h"

/* defined in battle_080ED314.c returning u16; this caller re-extends the result */
u32 sub_080ED32C(u16 i);
u8 sub_080F0F68(u16 a);

struct F104CEntry
{
    u8 id[2];
    u16 alt;
};
extern const struct F104CEntry gUnknown_0876E1D8[];

// sub_080F104C @ 0x080F104C
#ifdef NONMATCHING
u16 sub_080F104C(u16 a, u16 b)
{
    const u8 *p = &gUnknown_0876E1D8[a].id[b];
    u8 v;

    if (*p > 0xD1)
    {
        v = sub_080F0F68(a);
        if (v > 0xDB)
            return gUnknown_0876E1D8[a].alt;
    }
    else
        v = *p;
    return sub_080ED32C(v);
}
#else
NAKED u16 sub_080F104C(u16 a, u16 b)
{
    asm_unified(
        ".L080F104C:\n"
        "    push {r4, r5, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    ldr r5, .L080F1078\n"
        "    lsls r4, r3, #2\n"
        "    adds r0, r1, r4\n"
        "    adds r2, r0, r5\n"
        "    ldrb r0, [r2]\n"
        "    cmp r0, #0xd1\n"
        "    bls .L080F107C\n"
        "    adds r0, r3, #0\n"
        "    bl sub_080F0F68\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #0xdb\n"
        "    bls .L080F107E\n"
        "    adds r0, r4, r5\n"
        "    ldrh r0, [r0, #2]\n"
        "    b .L080F1086\n"
        ".L080F1078: .4byte gUnknown_0876E1D8\n"
        ".L080F107C:\n"
        "    ldrb r0, [r2]\n"
        ".L080F107E:\n"
        "    bl sub_080ED32C\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        ".L080F1086:\n"
        "    pop {r4, r5}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

