#include "global.h"
#include "fieldcmd.h"

// Item_GetAttribute @ 0x080BF468
/* Reads attribute `field` of item (< 0x80), equipment (< 0xD0) or skill id into *out
   (-1 when the record kind has no such field; field 5 unpacks 6 BCD digits). */
void Item_GetAttribute(s32 id, u32 field, s32 *out)
{
    u8 *r;
    s32 v;

    if (id & 0x8000)
        id &= 0xFF;
    if (id <= 0x7F)
    {
        r = Item_GetRecord(id);
        switch (field)
        {
        case 0:
            v = r[0] & 0xF0;
            break;
        case 1:
            v = r[0] & 0xF;
            break;
        case 2:
            v = r[1];
            break;
        case 3:
            v = r[2];
            break;
        case 4:
            v = r[3];
            break;
        case 5:
            Bcd_Unpack3(r + 4, (u8 *)out);
            return;
        case 6:
            v = *(u16 *)(r + 8);
            break;
        case 7:
            v = r[0xB];
            break;
        default:
            v = -1;
            break;
        }
    }
    else if (id <= 0xCF)
    {
        r = Equipment_GetRecord36_MidRange(id);
        switch (field)
        {
        case 0:
            v = r[0] & 0xF0;
            break;
        case 1:
            v = r[0] & 0xF;
            break;
        case 8:
            v = r[1];
            break;
        case 9:
            v = r[2];
            break;
        case 5:
            Bcd_Unpack3(r + 4, (u8 *)out);
            return;
        case 6:
            v = *(u16 *)(r + 8);
            break;
        case 7:
            v = r[3];
            break;
        default:
            v = -1;
            break;
        }
    }
    else
    {
        r = Action_GetRecord(id);
        switch (field)
        {
        case 10:
            v = r[0] & 0xF0;
            break;
        case 1:
            v = r[0] & 0xF;
            break;
        case 11:
            v = (s8)r[1];
            break;
        case 12:
            v = r[2];
            if (id == 0xF0)
                v = sub_080F6278();
            else if (id == 0xF8)
                v = sub_080F6390();
            break;
        case 5:
            Bcd_Unpack3(r + 1, (u8 *)out);
            return;
        case 13:
            v = r[3];
            break;
        default:
            v = -1;
            break;
        }
    }
    *out = v;
}

// sub_080BF5C0 @ 0x080BF5C0
const u8 *sub_080BF5C0(u16 id)
{
    return &gUnknown_0819B9F4[id * 28];
}

// sub_080BF5D8 @ 0x080BF5D8
void sub_080BF5D8(u16 id, u16 a1, u16 a2, u16 x, u16 y, u16 step)
{
    const u16 *name = ((const struct NameRecord28 *)sub_080BF5C0(id))->name;
    u32 i = 0;

    if (*name != 0)
    {
        do
        {
            FontSprite_DrawGlyph(*name, a1, a2, x, y);
            name++;
            x += step;
            i++;
            if (i > 7)
                break;
        } while (*name != 0);
    }
}

// Demon_GetRecord @ 0x080BF648
/* Demon record id; the party members' entries (0x106/0x109/0x10C, 0x108, 0x10E) get the
   player-chosen name from the combatant data, in a copy at 0x03005FC0. */
u8 *Demon_GetRecord(u16 id)
{
    const u8 *src = &gUnknown_0819CB74[id * 96];
    struct DemonRecord *buf = &gUnk_03005FC0;

    CpuSet(src, buf, 0x04000018);
    if (id == 0x106 || id == 0x109 || id == 0x10C)
    {
        Combatant_DecodeName(gUnk_030050C8, gUnk_03005FC0.name);
        return (u8 *)&gUnk_03005FC0;
    }
    if (id == 0x108)
    {
        Combatant_DecodeName(gUnk_030050D0, buf->name);
        return (u8 *)buf;
    }
    if (id == 0x10E)
    {
        Combatant_DecodeName(gUnk_030050C0, buf->name);
        return (u8 *)buf;
    }
    return (u8 *)src;
}

// Demon_DrawName @ 0x080BF6D4
void Demon_DrawName(u16 id, u16 a1, u16 a2, u16 x, u16 y, u16 step)
{
    const u16 *name = ((struct DemonRecord *)Demon_GetRecord(id))->name;
    u32 i = 0;

    if (*name != 0)
    {
        do
        {
            FontSprite_DrawGlyph(*name, a1, a2, x, y);
            name++;
            x += step;
            i++;
            if (i > 7)
                break;
        } while (*name != 0);
    }
}

// Party_InitMember @ 0x080BF748
#ifdef NONMATCHING
/* Initialises combatant record c for party member `who` (0 the hero, 1/2 with one of
   four random stat sets). */
void Party_InitMember(u8 *c, s32 who)
{
    const u8 *st;
    u32 i;

    DmaFill32(3, 0, c, 0x80);
    c[0] = gUnknown_081A5A00[who * 8 + 0];
    c[1] = gUnknown_081A5A00[who * 8 + 1];
    c[2] = gUnknown_081A5A00[who * 8 + 2];
    c[3] = gUnknown_081A5A00[who * 8 + 3];
    c[4] = gUnknown_081A5A00[who * 8 + 4];
    c[5] = gUnknown_081A5A00[who * 8 + 5];
    c[6] = gUnknown_081A5A00[who * 8 + 6];
    c[7] = gUnknown_081A5A00[who * 8 + 7];
    if (who == 0)
    {
        c[0xD] = 6;
        *(u32 *)(c + 8) = 0x15E;
        c[0x28] = 6;
        c[0x29] = 5;
        c[0x2A] = 4;
        c[0x2B] = 6;
        c[0x2C] = 6;
        c[0x2D] = 3;
    }
    else
    {
        if (who == 1)
        {
            st = &gUnknown_081A5A20[(sub_080C2244() & 3) * 6];
            c[0xD] = 0x12;
            *(u32 *)(c + 8) = 0x25DA;
        }
        else
        {
            st = &gUnknown_081A5A38[(sub_080C2244() & 3) * 6];
            c[0xD] = 0x18;
            *(u32 *)(c + 8) = 0x59D8;
        }
        c[0x28] = st[0];
        c[0x29] = st[1];
        c[0x2A] = st[2];
        c[0x2B] = st[3];
        c[0x2C] = st[4];
        c[0x2D] = st[5];
    }
    *(u32 *)(c + 0x40) = *(u32 *)(c + 0x28);
    *(u32 *)(c + 0x44) = *(u32 *)(c + 0x2C);
    c[0x21] = 0xFF;
    ((s8 *)c)[0x20] = -1;
    ((s8 *)c)[0x23] = -1;
    ((s8 *)c)[0x22] = -1;
    ((s8 *)c)[0x25] = -1;
    ((s8 *)c)[0x24] = -1;
    ((s8 *)c)[0x26] = -1;
    c[0xC] = who;
    for (i = 0; i <= 0x1F; i++)
        c[0x5D + i] |= 0xFF;
    sub_080F4260(c[0xC]);
    if (who <= 3)
    {
        *(u16 *)(c + 0x14) = gUnknown_081A59FC[who];
        *(u16 *)(c + 0x58) = gUnknown_081A59F4[who];
        *(u16 *)(c + 0x12) = who + 0x8000;
    }
}
#else
NAKED
void Party_InitMember(u8 *c, s32 who)
{
    asm_unified(
        ".L080BF748:\n"
        "    push {r4, r5, r6, lr}\n"
        "    sub sp, #4\n"
        "    adds r4, r0, #0\n"
        "    adds r6, r1, #0\n"
        "    movs r0, #0\n"
        "    str r0, [sp]\n"
        "    ldr r0, .L080BF7D8\n"
        "    mov r1, sp\n"
        "    str r1, [r0]\n"
        "    str r4, [r0, #4]\n"
        "    ldr r1, .L080BF7DC\n"
        "    str r1, [r0, #8]\n"
        "    ldr r0, [r0, #8]\n"
        "    ldr r1, .L080BF7E0\n"
        "    lsls r2, r6, #3\n"
        "    adds r0, r2, r1\n"
        "    ldrb r0, [r0]\n"
        "    strb r0, [r4]\n"
        "    adds r0, r1, #1\n"
        "    adds r0, r2, r0\n"
        "    ldrb r0, [r0]\n"
        "    strb r0, [r4, #1]\n"
        "    adds r0, r1, #2\n"
        "    adds r0, r2, r0\n"
        "    ldrb r0, [r0]\n"
        "    strb r0, [r4, #2]\n"
        "    adds r0, r1, #3\n"
        "    adds r0, r2, r0\n"
        "    ldrb r0, [r0]\n"
        "    strb r0, [r4, #3]\n"
        "    adds r0, r1, #4\n"
        "    adds r0, r2, r0\n"
        "    ldrb r0, [r0]\n"
        "    strb r0, [r4, #4]\n"
        "    adds r0, r1, #5\n"
        "    adds r0, r2, r0\n"
        "    ldrb r0, [r0]\n"
        "    strb r0, [r4, #5]\n"
        "    adds r0, r1, #6\n"
        "    adds r0, r2, r0\n"
        "    ldrb r0, [r0]\n"
        "    strb r0, [r4, #6]\n"
        "    adds r1, #7\n"
        "    adds r2, r2, r1\n"
        "    ldrb r0, [r2]\n"
        "    strb r0, [r4, #7]\n"
        "    cmp r6, #0\n"
        "    bne .L080BF7E4\n"
        "    movs r1, #6\n"
        "    strb r1, [r4, #0xd]\n"
        "    movs r0, #0xaf\n"
        "    lsls r0, r0, #1\n"
        "    str r0, [r4, #8]\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x28\n"
        "    strb r1, [r0]\n"
        "    adds r2, r4, #0\n"
        "    adds r2, #0x29\n"
        "    movs r0, #5\n"
        "    strb r0, [r2]\n"
        "    adds r2, #1\n"
        "    movs r0, #4\n"
        "    strb r0, [r2]\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x2b\n"
        "    strb r1, [r0]\n"
        "    adds r0, #1\n"
        "    strb r1, [r0]\n"
        "    adds r1, r4, #0\n"
        "    adds r1, #0x2d\n"
        "    movs r0, #3\n"
        "    b .L080BF850\n"
        ".L080BF7D8: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080BF7DC: .4byte 0x85000020\n"
        ".L080BF7E0: .4byte gUnknown_081A5A00\n"
        ".L080BF7E4:\n"
        "    cmp r6, #1\n"
        "    bne .L080BF80C\n"
        "    bl sub_080C2244\n"
        "    movs r1, #3\n"
        "    ands r0, r1\n"
        "    lsls r1, r0, #1\n"
        "    adds r1, r1, r0\n"
        "    lsls r1, r1, #1\n"
        "    ldr r0, .L080BF804\n"
        "    adds r1, r1, r0\n"
        "    movs r0, #0x12\n"
        "    strb r0, [r4, #0xd]\n"
        "    ldr r0, .L080BF808\n"
        "    b .L080BF824\n"
        "    .byte 0x00, 0x00\n"
        ".L080BF804: .4byte gUnknown_081A5A20\n"
        ".L080BF808: .4byte 0x000025DA\n"
        ".L080BF80C:\n"
        "    bl sub_080C2244\n"
        "    movs r1, #3\n"
        "    ands r0, r1\n"
        "    lsls r1, r0, #1\n"
        "    adds r1, r1, r0\n"
        "    lsls r1, r1, #1\n"
        "    ldr r0, .L080BF8C4\n"
        "    adds r1, r1, r0\n"
        "    movs r0, #0x18\n"
        "    strb r0, [r4, #0xd]\n"
        "    ldr r0, .L080BF8C8\n"
        ".L080BF824:\n"
        "    str r0, [r4, #8]\n"
        "    ldrb r2, [r1]\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x28\n"
        "    strb r2, [r0]\n"
        "    ldrb r0, [r1, #1]\n"
        "    adds r2, r4, #0\n"
        "    adds r2, #0x29\n"
        "    strb r0, [r2]\n"
        "    ldrb r0, [r1, #2]\n"
        "    adds r2, #1\n"
        "    strb r0, [r2]\n"
        "    ldrb r0, [r1, #3]\n"
        "    adds r2, #1\n"
        "    strb r0, [r2]\n"
        "    ldrb r2, [r1, #4]\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x2c\n"
        "    strb r2, [r0]\n"
        "    ldrb r0, [r1, #5]\n"
        "    adds r1, r4, #0\n"
        "    adds r1, #0x2d\n"
        ".L080BF850:\n"
        "    strb r0, [r1]\n"
        "    ldr r0, [r4, #0x28]\n"
        "    ldr r1, [r4, #0x2c]\n"
        "    str r0, [r4, #0x40]\n"
        "    str r1, [r4, #0x44]\n"
        "    adds r1, r4, #0\n"
        "    adds r1, #0x21\n"
        "    movs r0, #0xff\n"
        "    strb r0, [r1]\n"
        "    subs r1, #1\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    strb r0, [r1]\n"
        "    adds r1, #3\n"
        "    strb r0, [r1]\n"
        "    subs r1, #1\n"
        "    strb r0, [r1]\n"
        "    adds r1, #3\n"
        "    strb r0, [r1]\n"
        "    subs r1, #1\n"
        "    strb r0, [r1]\n"
        "    adds r1, #2\n"
        "    strb r0, [r1]\n"
        "    strb r6, [r4, #0xc]\n"
        "    movs r2, #0\n"
        "    adds r3, r4, #0\n"
        "    adds r3, #0x5d\n"
        "    movs r5, #0xff\n"
        ".L080BF888:\n"
        "    adds r1, r3, r2\n"
        "    ldrb r0, [r1]\n"
        "    orrs r0, r5\n"
        "    strb r0, [r1]\n"
        "    adds r2, #1\n"
        "    cmp r2, #0x1f\n"
        "    bls .L080BF888\n"
        "    ldrb r0, [r4, #0xc]\n"
        "    bl sub_080F4260\n"
        "    cmp r6, #3\n"
        "    bgt .L080BF8BC\n"
        "    ldr r0, .L080BF8CC\n"
        "    adds r0, r6, r0\n"
        "    ldrb r0, [r0]\n"
        "    strh r0, [r4, #0x14]\n"
        "    ldr r1, .L080BF8D0\n"
        "    lsls r0, r6, #1\n"
        "    adds r0, r0, r1\n"
        "    ldrh r1, [r0]\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x58\n"
        "    strh r1, [r0]\n"
        "    ldr r1, .L080BF8D4\n"
        "    adds r0, r6, r1\n"
        "    strh r0, [r4, #0x12]\n"
        ".L080BF8BC:\n"
        "    add sp, #4\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080BF8C4: .4byte gUnknown_081A5A38\n"
        ".L080BF8C8: .4byte 0x000059D8\n"
        ".L080BF8CC: .4byte gUnknown_081A59FC\n"
        ".L080BF8D0: .4byte gUnknown_081A59F4\n"
        ".L080BF8D4: .4byte 0xFFFF8000\n"
    );
}
#endif

// sub_080BF8D8 @ 0x080BF8D8
void sub_080BF8D8(s32 who)
{
    s32 i;

    for (i = 0; i <= 6; i++)
        sub_080C0074(who, i, gUnknown_081A5A50[who * 7 + i]);
    sub_080BF938(who);
}
