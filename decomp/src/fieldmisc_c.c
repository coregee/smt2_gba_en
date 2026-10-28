#include "global.h"
#include "inventory.h"

// sub_080C5D0C @ 0x080C5D0C
u16 sub_080C5D0C(void)
{
    u16 bx, by;

    sub_080C1F50(gFieldState.x, gFieldState.y, &bx, &by);
    return gUnknown_081A66B0[by >> 2][bx >> 2];
}

// sub_080C5D48 @ 0x080C5D48
const struct C0c2Bytes4 *sub_080C5D48(u16 zone)
{
    return &gUnknown_081A6AB0[zone];
}

// sub_080C5D58 @ 0x080C5D58
u16 sub_080C5D58(void)
{
    struct C0c2Area *area = FieldMap_GetArea(gUnk_030069F0[4]);
    u16 x = (gUnk_030069F0[6] >> 4) + area->originX;
    u16 y = (gUnk_030069F0[7] >> 4) + area->originY;

    return gUnknown_081A6CD4[y >> 3][x >> 3];
}

// sub_080C5D98 @ 0x080C5D98
const struct C0c2Bytes4 *sub_080C5D98(void)
{
    return &gUnknown_081A6C60[sub_080C5D58()];
}

// Party_SnapshotHumans @ 0x080C5DB0
/* Snapshots the four human records into members[16-19]. */
void Party_SnapshotHumans(void)
{
    u32 i;

    for (i = 0; i < 4; i++)
        CpuSet(&gGameState.members[i], &gGameState.members[i + 16], 0x04000020);
}

// Party_RestoreHumans @ 0x080C5DE0
/* Restores HP, MP and status of the humans from the snapshot (keeping status bit 0). */
#ifdef NONMATCHING
void Party_RestoreHumans(void)
{
    u32 i;

    for (i = 0; i < 4; i++)
    {
        u16 old;

        gGameState.members[i].hp = gGameState.members[i + 16].hp;
        gGameState.members[i].mp = gGameState.members[i + 16].mp;
        old = gGameState.members[i].flags;
        gGameState.members[i].flags = gGameState.members[i + 16].flags;
        if (old & 1)
            gGameState.members[i].flags |= 1;
    }
    sub_080C6FD8();
    Encounter_SetCounter(0);
    Flag_Clear(0xDF);
}
#else
NAKED
void Party_RestoreHumans(void)
{
    asm_unified(
        ".L080C5DE0:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    movs r5, #0\n"
        "    ldr r0, .L080C5E38\n"
        "    movs r7, #0\n"
        "    movs r6, #1\n"
        "    adds r3, r0, #0\n"
        "    adds r3, #0x10\n"
        "    adds r4, r0, #0\n"
        ".L080C5DF0:\n"
        "    ldr r1, .L080C5E3C\n"
        "    adds r0, r4, r1\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r3, #8]\n"
        "    ldr r2, .L080C5E40\n"
        "    adds r0, r4, r2\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r3, #0xc]\n"
        "    ldrh r1, [r3]\n"
        "    subs r2, #0xc\n"
        "    adds r0, r4, r2\n"
        "    ldrh r2, [r0]\n"
        "    strh r2, [r3]\n"
        "    movs r0, #1\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080C5E18\n"
        "    adds r0, r2, #0\n"
        "    orrs r0, r6\n"
        "    strh r0, [r3]\n"
        ".L080C5E18:\n"
        "    adds r3, #0x80\n"
        "    adds r4, #0x80\n"
        "    adds r5, #1\n"
        "    cmp r5, #3\n"
        "    bls .L080C5DF0\n"
        "    bl sub_080C6FD8\n"
        "    movs r0, #0\n"
        "    bl Encounter_SetCounter\n"
        "    movs r0, #0xdf\n"
        "    bl Flag_Clear\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080C5E38: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080C5E3C: .4byte 0x00000818\n"
        ".L080C5E40: .4byte 0x0000081C\n"
    );
}
#endif

// sub_080C5E44 @ 0x080C5E44
u16 sub_080C5E44(u16 id)
{
    return gUnknown_081A6F06[id - 0x5E];
}

// sub_080C5E58 @ 0x080C5E58
/* Value of the spot entry at the player's block position and facing, 0xFFFF if none. */
#ifdef NONMATCHING
u16 sub_080C5E58(void)
{
    const struct C0c2Spot *e = gUnknown_081A6F68;
    u16 bx, by;
    u16 dir;

    sub_080C1F50(gFieldState.x, gFieldState.y, &bx, &by);
    dir = ((e->yd >> 5) & 6) >> 1;
    while (e->x != 0xFFFF)
    {
        if (e->x == bx && (e->yd & 0x3F) == by && gFieldState.facing == dir)
        {
            /* the spot at block (0x2D, 6) needs flag 0x15 */
            if ((*(u32 *)e & 0x3FFFFF) != 0x6002D || Flag_Test(0x15))
                return e->value;
            break;
        }
        e++;
        dir = ((e->yd >> 5) & 6) >> 1;
    }
    return 0xFFFF;
}
#else
NAKED
u16 sub_080C5E58(void)
{
    asm_unified(
        ".L080C5E58:\n"
        "    push {r4, r5, lr}\n"
        "    sub sp, #4\n"
        "    ldr r5, .L080C5EBC\n"
        "    ldr r1, .L080C5EC0\n"
        "    ldrh r0, [r1, #0x12]\n"
        "    ldrh r1, [r1, #0x14]\n"
        "    mov r4, sp\n"
        "    adds r4, #2\n"
        "    mov r2, sp\n"
        "    adds r3, r4, #0\n"
        "    bl sub_080C1F50\n"
        "    ldrh r0, [r5, #2]\n"
        "    lsrs r0, r0, #5\n"
        "    movs r1, #6\n"
        "    ands r0, r1\n"
        "    lsrs r2, r0, #1\n"
        "    ldrh r0, [r5]\n"
        "    ldr r1, .L080C5EC4\n"
        "    cmp r0, r1\n"
        "    beq .L080C5EE2\n"
        "    adds r3, r1, #0\n"
        ".L080C5E84:\n"
        "    mov r1, sp\n"
        "    ldrh r0, [r5]\n"
        "    ldrh r1, [r1]\n"
        "    cmp r0, r1\n"
        "    bne .L080C5ED0\n"
        "    ldrh r1, [r5, #2]\n"
        "    movs r0, #0x3f\n"
        "    ands r0, r1\n"
        "    ldrh r1, [r4]\n"
        "    cmp r0, r1\n"
        "    bne .L080C5ED0\n"
        "    ldr r0, .L080C5EC0\n"
        "    ldrh r0, [r0, #2]\n"
        "    cmp r0, r2\n"
        "    bne .L080C5ED0\n"
        "    ldr r0, [r5]\n"
        "    ldr r1, .L080C5EC8\n"
        "    ands r0, r1\n"
        "    ldr r1, .L080C5ECC\n"
        "    cmp r0, r1\n"
        "    bne .L080C5EB8\n"
        "    movs r0, #0x15\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    beq .L080C5EE2\n"
        ".L080C5EB8:\n"
        "    ldrh r0, [r5, #4]\n"
        "    b .L080C5EE4\n"
        ".L080C5EBC: .4byte gUnknown_081A6F68\n"
        ".L080C5EC0: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080C5EC4: .4byte 0x0000FFFF\n"
        ".L080C5EC8: .4byte 0x003FFFFF\n"
        ".L080C5ECC: .4byte 0x0006002D\n"
        ".L080C5ED0:\n"
        "    adds r5, #8\n"
        "    ldrh r0, [r5, #2]\n"
        "    lsrs r0, r0, #5\n"
        "    movs r1, #6\n"
        "    ands r0, r1\n"
        "    lsrs r2, r0, #1\n"
        "    ldrh r0, [r5]\n"
        "    cmp r0, r3\n"
        "    bne .L080C5E84\n"
        ".L080C5EE2:\n"
        "    ldr r0, .L080C5EEC\n"
        ".L080C5EE4:\n"
        "    add sp, #4\n"
        "    pop {r4, r5}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        ".L080C5EEC: .4byte 0x0000FFFF\n"
    );
}
#endif

// sub_080C5EF0 @ 0x080C5EF0
struct C0c2Rec5C *sub_080C5EF0(u16 id)
{
    return (struct C0c2Rec5C *)&gUnknown_08341170[id];
}

// sub_080C5F04 @ 0x080C5F04
const void *sub_080C5F04(u16 id, u16 n)
{
    if (n <= 7)
        return gUnknown_08341170[id].a[n];
    return gUnknown_08341170[id].b[n - 8];
}

// sub_080C5F40 @ 0x080C5F40
const void *sub_080C5F40(u16 id, u16 which)
{
    struct C0c2Rec5C *r = sub_080C5EF0(id);

    if (which == 0)
        return r->unk50;
    return r->unk54;
}

// sub_080C5F60 @ 0x080C5F60
const void *sub_080C5F60(u16 id)
{
    return gUnknown_08341170[id].unk48;
}

// sub_080C5F78 @ 0x080C5F78
void sub_080C5F78(void)
{
    DmaCopy32(3, (void *)0x02001000, (void *)0x0600E400, 0xC00);
    DmaCopy32(3, gUnk_02000000, (void *)0x06001000, 0x1000);
}

// sub_080C5FB4 @ 0x080C5FB4
void sub_080C5FB4(void)
{
    LZ77UnCompWram(gUnknown_0822E194, (void *)0x02001000);
    sub_080C7C60();
    gUnk_03000040 = 0x3C40;
}
