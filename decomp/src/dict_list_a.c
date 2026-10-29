#include "global.h"
#include "extras.h"

struct DemonAlign
{
    u16 id;
    u16 align;
};
extern const struct DemonAlign gUnknown_08585C34[];
u32 sub_080DD248(u16 id);

/* Builds the compendium list gStatusList (0x17C entries, 0xFFFF-terminated) of the listable
   demons (sub_080C2600(id) == id and sub_080DD248) for mode 0 (by id), 1 (by race, record
   byte 0, 0..0x2C), 2 (in the order of gUnknown_08585C34, by alignment) or 3 (by level,
   record byte 1, in bands of 10 from the top). In modes 1-3 the entries outside group arg
   get bit 15 and gDict.unk3C is the first entry inside it; gDict.unk3E is 1 once there is
   such an entry. NONMATCHING: same control flow, but arg is spilled to the stack instead
   of lo/arg+1 (register allocation) and a few loops rotate differently. */
// Dict_BuildList @ 0x080DB4A8
#ifdef NONMATCHING
void Dict_BuildList(struct Task *task, u32 mode, u32 arg)
{
    u16 *list = gStatusList;
    u16 fill;
    u32 i;
    u32 group;
    u16 lo, hi;

    gDict.mode = mode;
    gDict.arg = arg;
    gDict.unk3C = 0;
    gDict.unk3E = 0;
    fill = 0xFFFF;
    CpuSet(&fill, list, 0x01000180);
    if (mode == 0)
    {
        for (i = 0; i <= 0x17B; i++)
        {
            if (sub_080C2600(i) == i && sub_080DD248(i))
                *list++ = sub_080C2600(i);
        }
        gDict.unk3E = 1;
    }
    else if (mode == 1)
    {
        for (group = 0; group <= 0x2C; group++)
        {
            for (i = 0; i <= 0x17B; i++)
            {
                if ((s8)Demon_GetRecord(i)[0] == group && sub_080C2600(i) == i && sub_080DD248(i))
                    *list++ = sub_080C2600(i);
            }
        }
        list = gStatusList;
        if (arg > 0x28)
            arg++;
        {
            u16 *p = list;

            for (i = 0; i <= 0x17B; i++)
            {
                if (*p != 0xFFFF)
                {
                    if ((s8)Demon_GetRecord(*p & 0x7FFF)[0] == arg)
                    {
                        gDict.unk3C = i;
                        gDict.unk3E = 1;
                        break;
                    }
                }
                else
                {
                    gDict.unk3C = 0;
                    break;
                }
                p++;
            }
        }
        list = gStatusList;
        {
            u16 *p = list;

            for (i = 0; i <= 0x17B && *p != 0xFFFF; p++, i++)
            {
                if ((s8)Demon_GetRecord(*p & 0x7FFF)[0] != arg)
                    *p |= 0x8000;
            }
        }
    }
    else if (mode == 2)
    {
        u32 found = 0;
        u16 n = 0;
        u16 j = 0;
        u16 id = gUnknown_08585C34[0].id;

        if (id != 0xFFFF)
        {
            do
            {
                if (sub_080C2600(id) == id && sub_080DD248(id))
                {
                    u16 v = sub_080C2600(id);
                    u16 align;

                    *list = v;
                    align = gUnknown_08585C34[j].align;
                    if (align != arg)
                        *list = 0x8000 | v;
                    list++;
                    if (!found && align == arg)
                    {
                        gDict.unk3C = n;
                        gDict.unk3E = 1;
                        found = 1;
                    }
                    n++;
                }
                j++;
                if (j > 0x17B)
                    break;
                id = gUnknown_08585C34[j].id;
            } while (id != 0xFFFF);
        }
    }
    else if (mode == 3)
    {
        for (group = 0; group <= 10; group++)
        {
            hi = (11 - group) * 10 - 1;
            if (group == 10)
                lo = 1;
            else
                lo = (10 - group) * 10;
            if (hi > 100)
                hi = 200;
            for (i = 0; i <= 0x17B; i++)
            {
                u8 lv = Demon_GetRecord(i)[1];

                if (lv >= lo && lv <= hi && sub_080C2600(i) == i && sub_080DD248(i))
                    *list++ = sub_080C2600(i);
            }
        }
        list = gStatusList;
        {
            u16 *p = list;

            for (i = 0; i <= 0x17B; i++)
            {
                if (*p != 0xFFFF)
                {
                    u8 lv;

                    hi = (arg + 1) * 10 - 1;
                    lv = Demon_GetRecord(*p & 0x7FFF)[1];
                    lo = arg == 0 ? 1 : arg * 10;
                    if (hi > 100)
                        hi = 200;
                    if (lv >= lo && lv <= hi)
                    {
                        gDict.unk3C = i;
                        gDict.unk3E = 1;
                        break;
                    }
                }
                else
                {
                    gDict.unk3C = 0;
                    break;
                }
                p++;
            }
        }
        {
            u16 *p = list;

            for (i = 0; i <= 0x17B && *p != 0xFFFF; p++, i++)
            {
                hi = (arg + 1) * 10;
                if (hi > 100)
                    hi = 200;
                if (Demon_GetRecord(*p & 0x7FFF)[1] >= hi)
                    *p |= 0x8000;
                else if (arg != 0 && Demon_GetRecord(*p & 0x7FFF)[1] < arg * 10)
                    *p |= 0x8000;
            }
        }
    }
}
#else
NAKED
void Dict_BuildList(struct Task *task, u32 mode, u32 arg)
{
    asm_unified(
        ".L080DB4A8:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0xc\n"
        "    adds r4, r1, #0\n"
        "    mov sl, r2\n"
        "    ldr r0, .L080DB520\n"
        "    mov sb, r0\n"
        "    ldr r2, .L080DB524\n"
        "    adds r0, r2, #0\n"
        "    adds r0, #0x40\n"
        "    movs r1, #0\n"
        "    strh r4, [r0]\n"
        "    adds r0, #2\n"
        "    mov r3, sl\n"
        "    strh r3, [r0]\n"
        "    strh r1, [r2, #0x3c]\n"
        "    strh r1, [r2, #0x3e]\n"
        "    mov r0, sp\n"
        "    ldr r1, .L080DB528\n"
        "    mov r8, r1\n"
        "    strh r1, [r0]\n"
        "    ldr r2, .L080DB52C\n"
        "    mov r1, sb\n"
        "    bl CpuSet\n"
        "    cmp r4, #0\n"
        "    bne .L080DB534\n"
        "    movs r5, #0\n"
        ".L080DB4E6:\n"
        "    lsls r0, r5, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080C2600\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, r5\n"
        "    bne .L080DB510\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080DD248\n"
        "    cmp r0, #0\n"
        "    beq .L080DB510\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080C2600\n"
        "    mov r2, sb\n"
        "    strh r0, [r2]\n"
        "    movs r3, #2\n"
        "    add sb, r3\n"
        ".L080DB510:\n"
        "    adds r5, #1\n"
        "    ldr r0, .L080DB530\n"
        "    cmp r5, r0\n"
        "    bls .L080DB4E6\n"
        "    ldr r1, .L080DB524\n"
        "    movs r0, #1\n"
        "    strh r0, [r1, #0x3e]\n"
        "    b .L080DB88C\n"
        ".L080DB520: .4byte 0x0203B554 @ EWRAM+0x3B554\n"
        ".L080DB524: .4byte 0x020399E0 @ EWRAM+0x399E0\n"
        ".L080DB528: .4byte 0x0000FFFF\n"
        ".L080DB52C: .4byte 0x01000180\n"
        ".L080DB530: .4byte 0x0000017B\n"
        ".L080DB534:\n"
        "    cmp r4, #1\n"
        "    beq .L080DB53A\n"
        "    b .L080DB644\n"
        ".L080DB53A:\n"
        "    movs r6, #0\n"
        ".L080DB53C:\n"
        "    movs r5, #0\n"
        "    adds r0, r6, #1\n"
        "    mov r8, r0\n"
        ".L080DB542:\n"
        "    lsls r0, r5, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Demon_GetRecord\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    cmp r0, r6\n"
        "    bne .L080DB57C\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080C2600\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, r5\n"
        "    bne .L080DB57C\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080DD248\n"
        "    cmp r0, #0\n"
        "    beq .L080DB57C\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080C2600\n"
        "    mov r1, sb\n"
        "    strh r0, [r1]\n"
        "    movs r2, #2\n"
        "    add sb, r2\n"
        ".L080DB57C:\n"
        "    adds r5, #1\n"
        "    ldr r0, .L080DB5C4\n"
        "    cmp r5, r0\n"
        "    bls .L080DB542\n"
        "    mov r6, r8\n"
        "    cmp r6, #0x2c\n"
        "    bls .L080DB53C\n"
        "    ldr r3, .L080DB5C8\n"
        "    mov sb, r3\n"
        "    mov r0, sl\n"
        "    cmp r0, #0x28\n"
        "    bls .L080DB598\n"
        "    movs r1, #1\n"
        "    add sl, r1\n"
        ".L080DB598:\n"
        "    movs r5, #0\n"
        "    ldr r7, .L080DB5CC\n"
        "    ldr r6, .L080DB5D0\n"
        "    mov r4, sb\n"
        ".L080DB5A0:\n"
        "    ldrh r1, [r4]\n"
        "    cmp r1, r7\n"
        "    beq .L080DB5D8\n"
        "    ldr r2, .L080DB5D4\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r1\n"
        "    bl Demon_GetRecord\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    cmp r0, sl\n"
        "    bne .L080DB5DE\n"
        "    strh r5, [r6, #0x3c]\n"
        "    movs r0, #1\n"
        "    strh r0, [r6, #0x3e]\n"
        "    b .L080DB5E8\n"
        "    .byte 0x00, 0x00\n"
        ".L080DB5C4: .4byte 0x0000017B\n"
        ".L080DB5C8: .4byte 0x0203B554 @ EWRAM+0x3B554\n"
        ".L080DB5CC: .4byte 0x0000FFFF\n"
        ".L080DB5D0: .4byte 0x020399E0 @ EWRAM+0x399E0\n"
        ".L080DB5D4: .4byte 0x00007FFF\n"
        ".L080DB5D8:\n"
        "    movs r0, #0\n"
        "    strh r0, [r6, #0x3c]\n"
        "    b .L080DB5E8\n"
        ".L080DB5DE:\n"
        "    adds r4, #2\n"
        "    adds r5, #1\n"
        "    ldr r0, .L080DB634\n"
        "    cmp r5, r0\n"
        "    bls .L080DB5A0\n"
        ".L080DB5E8:\n"
        "    ldr r3, .L080DB638\n"
        "    mov sb, r3\n"
        "    movs r5, #0\n"
        "    ldrh r0, [r3]\n"
        "    ldr r1, .L080DB63C\n"
        "    cmp r0, r1\n"
        "    bne .L080DB5F8\n"
        "    b .L080DB88C\n"
        ".L080DB5F8:\n"
        "    adds r7, r1, #0\n"
        "    mov r4, sb\n"
        "    ldr r0, .L080DB640\n"
        "    adds r6, r0, #0\n"
        ".L080DB600:\n"
        "    ldrh r0, [r4]\n"
        "    ands r0, r6\n"
        "    bl Demon_GetRecord\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    cmp r0, sl\n"
        "    beq .L080DB61E\n"
        "    ldrh r0, [r4]\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #8\n"
        "    adds r1, r2, #0\n"
        "    orrs r0, r1\n"
        "    strh r0, [r4]\n"
        ".L080DB61E:\n"
        "    adds r4, #2\n"
        "    adds r5, #1\n"
        "    ldr r0, .L080DB634\n"
        "    cmp r5, r0\n"
        "    bls .L080DB62A\n"
        "    b .L080DB88C\n"
        ".L080DB62A:\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, r7\n"
        "    bne .L080DB600\n"
        "    b .L080DB88C\n"
        "    .byte 0x00, 0x00\n"
        ".L080DB634: .4byte 0x0000017B\n"
        ".L080DB638: .4byte 0x0203B554 @ EWRAM+0x3B554\n"
        ".L080DB63C: .4byte 0x0000FFFF\n"
        ".L080DB640: .4byte 0x00007FFF\n"
        ".L080DB644:\n"
        "    cmp r4, #2\n"
        "    bne .L080DB6E4\n"
        "    movs r7, #0\n"
        "    movs r6, #0\n"
        "    movs r5, #0\n"
        "    ldr r0, .L080DB6D0\n"
        "    ldrh r4, [r0]\n"
        "    cmp r4, r8\n"
        "    bne .L080DB658\n"
        "    b .L080DB88C\n"
        ".L080DB658:\n"
        "    mov r8, r0\n"
        ".L080DB65A:\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080C2600\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, r4\n"
        "    bne .L080DB6B2\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080DD248\n"
        "    cmp r0, #0\n"
        "    beq .L080DB6B2\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080C2600\n"
        "    adds r1, r0, #0\n"
        "    mov r3, sb\n"
        "    strh r1, [r3]\n"
        "    lsls r0, r5, #2\n"
        "    ldr r2, .L080DB6D4\n"
        "    adds r0, r0, r2\n"
        "    ldrh r2, [r0]\n"
        "    cmp r2, sl\n"
        "    beq .L080DB696\n"
        "    movs r3, #0x80\n"
        "    lsls r3, r3, #8\n"
        "    adds r0, r3, #0\n"
        "    orrs r0, r1\n"
        "    mov r1, sb\n"
        "    strh r0, [r1]\n"
        ".L080DB696:\n"
        "    movs r3, #2\n"
        "    add sb, r3\n"
        "    cmp r7, #0\n"
        "    bne .L080DB6AC\n"
        "    cmp r2, sl\n"
        "    bne .L080DB6AC\n"
        "    ldr r1, .L080DB6D8\n"
        "    strh r6, [r1, #0x3c]\n"
        "    movs r0, #1\n"
        "    strh r0, [r1, #0x3e]\n"
        "    movs r7, #1\n"
        ".L080DB6AC:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        ".L080DB6B2:\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    ldr r0, .L080DB6DC\n"
        "    cmp r5, r0\n"
        "    bls .L080DB6C0\n"
        "    b .L080DB88C\n"
        ".L080DB6C0:\n"
        "    lsls r0, r5, #2\n"
        "    add r0, r8\n"
        "    ldrh r4, [r0]\n"
        "    ldr r0, .L080DB6E0\n"
        "    cmp r4, r0\n"
        "    bne .L080DB65A\n"
        "    b .L080DB88C\n"
        "    .byte 0x00, 0x00\n"
        ".L080DB6D0: .4byte gUnknown_08585C34\n"
        ".L080DB6D4: .4byte gUnknown_08585C36\n"
        ".L080DB6D8: .4byte 0x020399E0 @ EWRAM+0x399E0\n"
        ".L080DB6DC: .4byte 0x0000017B\n"
        ".L080DB6E0: .4byte 0x0000FFFF\n"
        ".L080DB6E4:\n"
        "    cmp r4, #3\n"
        "    beq .L080DB6EA\n"
        "    b .L080DB88C\n"
        ".L080DB6EA:\n"
        "    movs r6, #0\n"
        "    mov r0, sl\n"
        "    adds r0, #1\n"
        "    str r0, [sp, #8]\n"
        ".L080DB6F2:\n"
        "    movs r1, #0xb\n"
        "    subs r1, r1, r6\n"
        "    lsls r0, r1, #2\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #0x11\n"
        "    ldr r1, .L080DB70C\n"
        "    adds r0, r0, r1\n"
        "    lsrs r7, r0, #0x10\n"
        "    cmp r6, #0xa\n"
        "    bne .L080DB710\n"
        "    movs r2, #1\n"
        "    str r2, [sp, #4]\n"
        "    b .L080DB71E\n"
        ".L080DB70C: .4byte 0xFFFF0000\n"
        ".L080DB710:\n"
        "    movs r1, #0xa\n"
        "    subs r1, r1, r6\n"
        "    lsls r0, r1, #2\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #0x11\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #4]\n"
        ".L080DB71E:\n"
        "    cmp r7, #0x64\n"
        "    bls .L080DB724\n"
        "    movs r7, #0xc8\n"
        ".L080DB724:\n"
        "    movs r5, #0\n"
        "    adds r6, #1\n"
        "    mov r8, r6\n"
        ".L080DB72A:\n"
        "    lsls r0, r5, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Demon_GetRecord\n"
        "    ldrb r0, [r0, #1]\n"
        "    ldr r3, [sp, #4]\n"
        "    cmp r0, r3\n"
        "    blo .L080DB766\n"
        "    cmp r0, r7\n"
        "    bhi .L080DB766\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080C2600\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, r5\n"
        "    bne .L080DB766\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080DD248\n"
        "    cmp r0, #0\n"
        "    beq .L080DB766\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080C2600\n"
        "    mov r1, sb\n"
        "    strh r0, [r1]\n"
        "    movs r2, #2\n"
        "    add sb, r2\n"
        ".L080DB766:\n"
        "    adds r5, #1\n"
        "    ldr r0, .L080DB7B4\n"
        "    cmp r5, r0\n"
        "    bls .L080DB72A\n"
        "    mov r6, r8\n"
        "    cmp r6, #0xa\n"
        "    bls .L080DB6F2\n"
        "    ldr r3, .L080DB7B8\n"
        "    mov sb, r3\n"
        "    movs r5, #0\n"
        "    mov r7, sb\n"
        "    ldr r6, [sp, #8]\n"
        "    mov r1, sl\n"
        "    lsls r0, r1, #2\n"
        "    add r0, sl\n"
        "    lsls r0, r0, #0x11\n"
        "    mov r8, r0\n"
        ".L080DB788:\n"
        "    ldrh r1, [r7]\n"
        "    ldr r2, .L080DB7BC\n"
        "    cmp r1, r2\n"
        "    beq .L080DB7E8\n"
        "    lsls r0, r6, #2\n"
        "    adds r0, r0, r6\n"
        "    lsls r0, r0, #0x11\n"
        "    ldr r3, .L080DB7C0\n"
        "    adds r0, r0, r3\n"
        "    lsrs r4, r0, #0x10\n"
        "    ldr r2, .L080DB7C4\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r1\n"
        "    bl Demon_GetRecord\n"
        "    ldrb r0, [r0, #1]\n"
        "    mov r3, sl\n"
        "    cmp r3, #0\n"
        "    bne .L080DB7C8\n"
        "    movs r1, #1\n"
        "    b .L080DB7CC\n"
        "    .byte 0x00, 0x00\n"
        ".L080DB7B4: .4byte 0x0000017B\n"
        ".L080DB7B8: .4byte 0x0203B554 @ EWRAM+0x3B554\n"
        ".L080DB7BC: .4byte 0x0000FFFF\n"
        ".L080DB7C0: .4byte 0xFFFF0000\n"
        ".L080DB7C4: .4byte 0x00007FFF\n"
        ".L080DB7C8:\n"
        "    mov r2, r8\n"
        "    lsrs r1, r2, #0x10\n"
        ".L080DB7CC:\n"
        "    cmp r4, #0x64\n"
        "    bls .L080DB7D2\n"
        "    movs r4, #0xc8\n"
        ".L080DB7D2:\n"
        "    cmp r0, r1\n"
        "    blo .L080DB7F4\n"
        "    cmp r0, r4\n"
        "    bhi .L080DB7F4\n"
        "    ldr r1, .L080DB7E4\n"
        "    strh r5, [r1, #0x3c]\n"
        "    movs r0, #1\n"
        "    strh r0, [r1, #0x3e]\n"
        "    b .L080DB7FE\n"
        ".L080DB7E4: .4byte 0x020399E0 @ EWRAM+0x399E0\n"
        ".L080DB7E8:\n"
        "    ldr r1, .L080DB7F0\n"
        "    movs r0, #0\n"
        "    strh r0, [r1, #0x3c]\n"
        "    b .L080DB7FE\n"
        ".L080DB7F0: .4byte 0x020399E0 @ EWRAM+0x399E0\n"
        ".L080DB7F4:\n"
        "    adds r7, #2\n"
        "    adds r5, #1\n"
        "    ldr r0, .L080DB858\n"
        "    cmp r5, r0\n"
        "    bls .L080DB788\n"
        ".L080DB7FE:\n"
        "    movs r5, #0\n"
        "    ldr r3, [sp, #8]\n"
        "    lsls r0, r3, #2\n"
        "    adds r0, r0, r3\n"
        "    lsls r0, r0, #0x11\n"
        "    lsrs r6, r0, #0x10\n"
        "    mov r1, sb\n"
        "    ldrh r0, [r1]\n"
        "    ldr r1, .L080DB85C\n"
        "    cmp r0, r1\n"
        "    beq .L080DB88C\n"
        "    mov r8, r3\n"
        "    mov r4, sb\n"
        ".L080DB818:\n"
        "    cmp r6, #0x64\n"
        "    bls .L080DB81E\n"
        "    movs r6, #0xc8\n"
        ".L080DB81E:\n"
        "    ldrh r1, [r4]\n"
        "    ldr r7, .L080DB860\n"
        "    adds r0, r7, #0\n"
        "    ands r0, r1\n"
        "    bl Demon_GetRecord\n"
        "    ldrb r0, [r0, #1]\n"
        "    cmp r0, r6\n"
        "    bhs .L080DB864\n"
        "    mov r2, sl\n"
        "    cmp r2, #0\n"
        "    beq .L080DB870\n"
        "    ldrh r1, [r4]\n"
        "    adds r0, r7, #0\n"
        "    ands r0, r1\n"
        "    bl Demon_GetRecord\n"
        "    ldrb r1, [r0, #1]\n"
        "    mov r3, sl\n"
        "    lsls r0, r3, #2\n"
        "    add r0, sl\n"
        "    lsls r0, r0, #1\n"
        "    cmp r1, r0\n"
        "    bhs .L080DB870\n"
        "    ldrh r0, [r4]\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #8\n"
        "    adds r1, r2, #0\n"
        "    b .L080DB86C\n"
        ".L080DB858: .4byte 0x0000017B\n"
        ".L080DB85C: .4byte 0x0000FFFF\n"
        ".L080DB860: .4byte 0x00007FFF\n"
        ".L080DB864:\n"
        "    ldrh r0, [r4]\n"
        "    movs r3, #0x80\n"
        "    lsls r3, r3, #8\n"
        "    adds r1, r3, #0\n"
        ".L080DB86C:\n"
        "    orrs r0, r1\n"
        "    strh r0, [r4]\n"
        ".L080DB870:\n"
        "    adds r4, #2\n"
        "    adds r5, #1\n"
        "    ldr r0, .L080DB89C\n"
        "    cmp r5, r0\n"
        "    bhi .L080DB88C\n"
        "    mov r1, r8\n"
        "    lsls r0, r1, #2\n"
        "    add r0, r8\n"
        "    lsls r0, r0, #0x11\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldrh r0, [r4]\n"
        "    ldr r2, .L080DB8A0\n"
        "    cmp r0, r2\n"
        "    bne .L080DB818\n"
        ".L080DB88C:\n"
        "    add sp, #0xc\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080DB89C: .4byte 0x0000017B\n"
        ".L080DB8A0: .4byte 0x0000FFFF\n"
    );
}
#endif
