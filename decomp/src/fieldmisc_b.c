#include "global.h"
#include "fieldcmd.h"

// RandomEvent_CheckCell @ 0x080BED60
/* Random-event cells (gUnknown_08198978: x, y, facing). On a match, picks event
   gFieldState.unk62 with sub_080BECCC (minus 2) once flag 0x16 is set; returns TRUE
   when an event should run. */
u32 RandomEvent_CheckCell(void)
{
    u16 x, y;
    u32 i;

    sub_080C1F50(gFieldState.unk12, gFieldState.unk14, &x, &y);
    gFieldState.unk62 = 0;
    for (i = 0; i <= 0x2F; i++)
    {
        if (x == gUnknown_08198978[i][0] && y == gUnknown_08198978[i][1])
        {
            u32 f;

            if (gFieldState.unk02 != gUnknown_08198978[i][2])
                return 0;
            if (Flag_Test(0xAE) || Flag_Test(0x65) || (f = Flag_Test(0x9C)) != 0)
                return 1;
            if (Flag_Test(0x16))
            {
                u32 v = sub_080BECCC();

                gFieldState.unk62 = v;
                if (gFieldState.unk62 > 1)
                {
                    gFieldState.unk62 = v - 2;
                    return 1;
                }
                gFieldState.unk62 = f;
                return 0;
            }
        }
    }
    return 0;
}

// RandomEvent_Try @ 0x080BEE24
u32 RandomEvent_Try(void)
{
    u32 r = RandomEvent_CheckCell();

    if (r)
    {
        const void *script = gUnknown_08198A98[gFieldState.unk62];

        if (ScriptVM_RunAlt(script) == 1 || ScriptVM_RunAlt(script) == 2)
            sub_080AF178(0xC, script);
    }
    return r;
}

// sub_080BEE74 @ 0x080BEE74
void sub_080BEE74(void)
{
    DmaCopy32(3, (void *)0x06004040, (void *)0x0600CC00, 0x1FC0);
    DmaCopy32(3, (void *)0x06008040, (void *)0x0600EBC0, 0x1100);
}

// sub_080BEEB0 @ 0x080BEEB0
void sub_080BEEB0(void)
{
    DmaCopy32(3, (void *)0x06004040, (void *)0x0600CC00, 0x16E0);
    DmaCopy32(3, (void *)0x06008E00, (void *)0x0600E2E0, 0x16E0);
}

// sub_080BEEE8 @ 0x080BEEE8
void sub_080BEEE8(void)
{
    if (sub_080C5F04(gUnk_03004534, 8) == NULL)
        VBlankTask_AddCounted(sub_080BEE74, 1);
    else
        VBlankTask_AddCounted(sub_080BEEB0, 1);
}

// sub_080BEF1C @ 0x080BEF1C
void sub_080BEF1C(void)
{
    DmaCopy32(3, gUnk_02000000, (void *)0x06001000, 0x1000);
    REG_BG2CNT = 0x8408;
}

// sub_080BEF4C @ 0x080BEF4C
#ifdef NONMATCHING
/* Builds the BG2 map of a background picture from its palette-index lists
   (sub_080C5F40): 30x13 or 28x13 tiles, or two mirrored 14x26 halves when the picture has
   piece 8. */
void sub_080BEF4C(void)
{
    u16 *map = gUnk_02000000;
    u16 tile = 0x260;
    const u8 *a = sub_080C5F40(gUnk_03004534, 0);
    const u8 *b = sub_080C5F40(gUnk_03004534, 1);
    u32 x, y;

    DmaFill32(3, 0, map, 0x1000);
    if (sub_080C5F04(gUnk_03004534, 8) == NULL)
    {
        if (gUnk_03004534 == 0xD9 || gUnk_03004534 == 0xDA)
        {
            u32 pal = 8;

            if (gUnk_03004534 == 0xDA)
                pal = 7;
            for (y = 0; y <= 0xC; y++)
            {
                for (x = 0; x <= 0x1D; x++)
                {
                    map[y * 32 + x] = tile + (((*a++ & 0xF) + pal) << 12);
                    tile++;
                }
            }
        }
        else
        {
            for (y = 0; y <= 0xC; y++)
            {
                for (x = 0; x <= 0x1B; x++)
                {
                    map[y * 32 + x + 1] = tile + (((*a++ & 0xF) + 8) << 12);
                    tile++;
                }
            }
        }
    }
    else
    {
        for (y = 0; y <= 0x19; y++)
        {
            for (x = 0; x <= 0xD; x++)
            {
                u32 pa = *a++;
                u32 pb = *b++;

                map[y * 32 + x + 1] = tile + (((pa & 0xF) + 8) << 12);
                map[y * 32 + 0x1C - x] = tile + (((pb & 0xF) + 8) << 12) + 0x4B7;
                tile++;
            }
        }
    }
    VBlankTask_AddCounted(sub_080BEF1C, 1);
    sub_080C140C(0x10, 0);
    gUnk_03000044 = 8;
}
#else
NAKED
void sub_080BEF4C(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #8\n"
        "    ldr r0, .L080BEFE4\n"
        "    mov sb, r0\n"
        "    movs r7, #0x98\n"
        "    lsls r7, r7, #2\n"
        "    ldr r4, .L080BEFE8\n"
        "    ldrh r0, [r4]\n"
        "    movs r1, #0\n"
        "    bl sub_080C5F40\n"
        "    adds r5, r0, #0\n"
        "    ldrh r0, [r4]\n"
        "    movs r1, #1\n"
        "    bl sub_080C5F40\n"
        "    str r0, [sp, #4]\n"
        "    movs r0, #0\n"
        "    str r0, [sp]\n"
        "    ldr r0, .L080BEFEC\n"
        "    mov r1, sp\n"
        "    str r1, [r0]\n"
        "    mov r3, sb\n"
        "    str r3, [r0, #4]\n"
        "    ldr r1, .L080BEFF0\n"
        "    str r1, [r0, #8]\n"
        "    ldr r0, [r0, #8]\n"
        "    ldrh r0, [r4]\n"
        "    movs r1, #8\n"
        "    bl sub_080C5F04\n"
        "    cmp r0, #0\n"
        "    bne .L080BF034\n"
        "    ldrh r1, [r4]\n"
        "    adds r0, r1, #0\n"
        "    subs r0, #0xd9\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bhi .L080BEFF8\n"
        "    movs r4, #8\n"
        "    cmp r1, #0xda\n"
        "    bne .L080BEFAC\n"
        "    movs r4, #7\n"
        ".L080BEFAC:\n"
        "    movs r0, #0\n"
        "    ldr r6, .L080BEFF4\n"
        "    mov sl, r6\n"
        "    movs r3, #0xf\n"
        ".L080BEFB4:\n"
        "    movs r2, #0\n"
        "    adds r1, r0, #1\n"
        "    mov ip, r1\n"
        "    lsls r0, r0, #6\n"
        "    mov r6, sb\n"
        "    adds r1, r0, r6\n"
        ".L080BEFC0:\n"
        "    ldrb r0, [r5]\n"
        "    adds r5, #1\n"
        "    ands r0, r3\n"
        "    adds r0, r0, r4\n"
        "    lsls r0, r0, #0xc\n"
        "    adds r0, r7, r0\n"
        "    strh r0, [r1]\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r1, #2\n"
        "    adds r2, #1\n"
        "    cmp r2, #0x1d\n"
        "    bls .L080BEFC0\n"
        "    mov r0, ip\n"
        "    cmp r0, #0xc\n"
        "    bls .L080BEFB4\n"
        "    b .L080BF08E\n"
        ".L080BEFE4: .4byte 0x02000000 @ EWRAM\n"
        ".L080BEFE8: .4byte 0x03004534 @ IWRAM+0x4534\n"
        ".L080BEFEC: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080BEFF0: .4byte 0x85000400\n"
        ".L080BEFF4: .4byte sub_080BEF1C\n"
        ".L080BEFF8:\n"
        "    movs r0, #0\n"
        "    ldr r1, .L080BF030\n"
        "    mov sl, r1\n"
        "    movs r3, #0xf\n"
        ".L080BF000:\n"
        "    movs r2, #0\n"
        "    adds r4, r0, #1\n"
        "    mov ip, r4\n"
        "    lsls r0, r0, #6\n"
        "    mov r6, sb\n"
        "    adds r1, r0, r6\n"
        ".L080BF00C:\n"
        "    ldrb r0, [r5]\n"
        "    adds r5, #1\n"
        "    ands r0, r3\n"
        "    adds r0, #8\n"
        "    lsls r0, r0, #0xc\n"
        "    adds r0, r7, r0\n"
        "    strh r0, [r1, #2]\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r1, #2\n"
        "    adds r2, #1\n"
        "    cmp r2, #0x1b\n"
        "    bls .L080BF00C\n"
        "    mov r0, ip\n"
        "    cmp r0, #0xc\n"
        "    bls .L080BF000\n"
        "    b .L080BF08E\n"
        ".L080BF030: .4byte sub_080BEF1C\n"
        ".L080BF034:\n"
        "    movs r0, #0\n"
        "    ldr r1, .L080BF0B4\n"
        "    mov sl, r1\n"
        "    movs r3, #0xf\n"
        "    mov r8, r3\n"
        ".L080BF03E:\n"
        "    movs r2, #0\n"
        "    lsls r1, r0, #5\n"
        "    adds r4, r0, #1\n"
        "    mov ip, r4\n"
        "    adds r1, #0x1c\n"
        "    lsls r0, r0, #6\n"
        "    mov r6, sb\n"
        "    adds r4, r0, r6\n"
        "    lsls r1, r1, #1\n"
        "    adds r3, r1, r6\n"
        ".L080BF052:\n"
        "    ldrb r1, [r5]\n"
        "    adds r5, #1\n"
        "    ldr r6, [sp, #4]\n"
        "    ldrb r0, [r6]\n"
        "    adds r6, #1\n"
        "    str r6, [sp, #4]\n"
        "    mov r6, r8\n"
        "    ands r1, r6\n"
        "    adds r1, #8\n"
        "    ands r0, r6\n"
        "    adds r0, #8\n"
        "    lsls r1, r1, #0xc\n"
        "    adds r1, r7, r1\n"
        "    strh r1, [r4, #2]\n"
        "    lsls r0, r0, #0xc\n"
        "    adds r0, r7, r0\n"
        "    ldr r1, .L080BF0B8\n"
        "    adds r0, r0, r1\n"
        "    strh r0, [r3]\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    subs r3, #2\n"
        "    adds r4, #2\n"
        "    adds r2, #1\n"
        "    cmp r2, #0xd\n"
        "    bls .L080BF052\n"
        "    mov r0, ip\n"
        "    cmp r0, #0x19\n"
        "    bls .L080BF03E\n"
        ".L080BF08E:\n"
        "    mov r0, sl\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    movs r0, #0x10\n"
        "    movs r1, #0\n"
        "    bl sub_080C140C\n"
        "    ldr r1, .L080BF0BC\n"
        "    movs r0, #8\n"
        "    strh r0, [r1]\n"
        "    add sp, #8\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080BF0B4: .4byte sub_080BEF1C\n"
        ".L080BF0B8: .4byte 0x000004B7\n"
        ".L080BF0BC: .4byte 0x03000044 @ IWRAM+0x44\n"
    );
}
#endif

// Field_WarpToWorldPos @ 0x080BF0C0
/* Moves the party to world position (d[3], d[4] & 0x3F) facing (d[4] >> 6): finds the
   map and sub-map whose rectangle contains it. When none does, map/floor are left
   uninitialised. */
void Field_WarpToWorldPos(struct Task *task)
{
    u16 *d = task->data.h;
    u16 x = d[3];
    u16 y = d[4] & 0x3F;
    u16 map;
    u32 foundMap, foundFloor;
    u32 n;
    u16 i;
    struct SubMap *f;

    for (map = 0; ; map++)
    {
        n = sub_080C8B3C(map);
        f = (struct SubMap *)DungeonMap_GetFloor(map, 0);
        if (f == NULL)
            break;
        for (i = 0; i < n; i++, f++)
        {
            if (f->x0 <= x && f->y0 <= y && f->x1 >= x && f->y1 >= y && SubMap_IsOutsideExclusions(f, x, y) == 1)
            {
                foundMap = map;
                foundFloor = i;
                x -= f->x0;
                y -= f->y0;
                break;
            }
        }
        if (i != n)
            break;
    }
    gUnk_03004614 = foundMap;
    gUnk_03004514 = foundFloor;
    gFieldState.unk12 = x;
    gFieldState.unk14 = y;
    gFieldState.unk02 = ((d[4] >> 5) & 6) >> 1;
    {
        u32 zero = 0;

        CpuSet(&zero, (void *)0x02005004, 0x05001000);
    }
    sub_080AE234();
    Map_SetGraphicsPointers(gUnk_03004614, gUnk_03004514);
}

// sub_080BF1B8 @ 0x080BF1B8
void sub_080BF1B8(void)
{
    DmaFill32(3, 0, gUnk_02028074, 0x20);
    DmaCopy32(3, gUnk_03003B94, (void *)0x06004000, 0x2000);
}

// sub_080BF1FC @ 0x080BF1FC
void sub_080BF1FC(struct Task *task)
{
    if (gUnk_03003FF8 != 0)
    {
        Map_LoadGraphicsStep(gUnk_03004614, gUnk_03004514, &gUnk_03003FF8);
        task->result = 0;
    }
    else
    {
        task->result = 1;
        gFieldState.unk0E = 0;
        VBlankTask_AddCounted(sub_080ADF64, 1);
        VBlankTask_AddCounted(sub_080BF1B8, 1);
    }
}

// sub_080BF254 @ 0x080BF254
void sub_080BF254(void)
{
    DmaCopy32(3, gUnk_02000000, (void *)0x06002000, 0x500);
}

// sub_080BF278 @ 0x080BF278
void sub_080BF278(void)
{
    const u16 *src = gUnknown_081B8370;
    u16 *dst = gUnk_02000000;
    u16 x, y;

    DmaCopy32(3, gUnknown_0857D9C0, dst, 0x500);
    for (y = 0; y <= 0xB; y++)
    {
        for (x = 0; x <= 0x1B; x++)
            dst[y * 32 + x + 0x21] = src[y * 32 + x + 0x21];
    }
    Tilemap_OffsetRect((u16 (*)[32])gUnk_02000000, 1, 0xD, 1, 1, 0x1C, 0xC);
    Field_CopyIwramCode();
    VBlankTask_AddCounted(sub_080BF254, 1);
}

// sub_080BF300 @ 0x080BF300
struct Task *sub_080BF300(u16 x, u16 y)
{
    struct Task *t = Task_Create(gUnknown_08198AD0, 0xFFFF);
    u16 *d = t->data.h;

    d[3] = x;
    d[4] = y;
    return t;
}

// Item_GetRecord @ 0x080BF32C
u8 *Item_GetRecord(u16 id)
{
    if (id & 0x8000)
        id &= 0xFF;
    return (u8 *)&gUnknown_08198B74[id * 36];
}

// Equipment_GetRecord36_MidRange @ 0x080BF354
u8 *Equipment_GetRecord36_MidRange(u16 id)
{
    if (id & 0x8000)
        id &= 0xFF;
    return (u8 *)&gUnknown_08198B74[id * 36];
}

// Item_DrawName @ 0x080BF37C
/* Draws the name of item/equipment (< 0xD0) or skill (>= 0xD0) id, at most 8 glyphs. */
void Item_DrawName(u16 id, u16 a1, u16 a2, u16 x, u16 y, u16 step)
{
    const u16 *name;
    u32 i;

    if (id & 0x8000)
        id &= 0xFF;
    if (id > 0xCF)
        name = (const u16 *)(Action_GetRecord(id) + 0xC);
    else if (id > 0x7F)
        name = (const u16 *)(Equipment_GetRecord36_MidRange(id) + 0x14);
    else
        name = (const u16 *)(Item_GetRecord(id) + 0x14);
    for (i = 0; i < 8 && *name != 0; i++)
    {
        FontSprite_DrawGlyph(*name, a1, a2, x, y);
        name++;
        x += step;
    }
}

// Action_GetRecord @ 0x080BF418
u8 *Action_GetRecord(u16 id)
{
    if (id & 0x8000)
        id &= 0xFF;
    return (u8 *)&gUnknown_08198EB4[id * 32];
}

// Bcd_Unpack3 @ 0x080BF43C
/* Unpacks 3 BCD bytes into 6 digits. */
void Bcd_Unpack3(const u8 *src, u8 *dst)
{
    s32 i;

    for (i = 0; i < 3; i++)
    {
        *dst++ = (*src >> 4) & 0xF;
        *dst = *src & 0xF;
        src++;
        dst++;
    }
}
