#include "global.h"
#include "battle.h"

struct Stats8
{
    u32 a, b;
};

// Battle_InitEnemyUnit @ 0x080F0200
/* Fills enemy unit slot from demon record id. */
#ifdef NONMATCHING
void Battle_InitEnemyUnit(s32 slot, s32 id)
{
    struct BattleFlow *b = BFLOW;
    u8 *u = (u8 *)&b->units[slot];
    u8 *rec = Demon_GetRecord(id);
    u32 zero;
    s32 i, j;
    u8 *skills;

    zero = 0;
    CpuSet(&zero, u, 0x05000020);
    u[0xC] = slot + 0x10;
    *(u16 *)(u + 0x12) = id;
    *(u16 *)(u + 0xE) = 0x8000;
    *(s16 *)(u + 0x14) = (s8)rec[0];
    *(u16 *)(u + 0x18) = *(u16 *)(rec + 2);
    *(u16 *)(u + 0x1A) = *(u16 *)(rec + 2);
    *(u16 *)(u + 0x1C) = *(u16 *)(rec + 4);
    *(u16 *)(u + 0x1E) = *(u16 *)(rec + 4);
    u[0xD] = rec[1];
    *(u16 *)(u + 0x58) = rec[0xC] << 8;
    u[0x17] = 10;
    u[0x16] = 10;
    u[0x40] = rec[6];
    u[0x41] = rec[7];
    u[0x42] = rec[8];
    u[0x43] = rec[9];
    u[0x44] = rec[0xA];
    u[0x45] = rec[0xB];
    *(struct Stats8 *)(u + 0x28) = *(struct Stats8 *)(u + 0x40);
    *(u16 *)(u + 0x58) = rec[0xC] << 8;
    skills = u + 0x5D;
    for (i = 0; i < 32; i++)
        skills[i] |= 0xFF;
    {
        u8 *src = rec + 0x11;

        for (i = 0, j = 0; j < 7; i++, j++)
            skills[i] = src[j];
    }
    Stats_CalcDerived(u[0xD], u + 0x40, u + 0x48);
    Name_Encode(rec + 0x22, u);
}
#else
NAKED void Battle_InitEnemyUnit(s32 slot, s32 id)
{
    asm_unified(
        ".L080F0200:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sb\n"
        "    mov r6, r8\n"
        "    push {r6, r7}\n"
        "    sub sp, #4\n"
        "    adds r4, r0, #0\n"
        "    adds r5, r1, #0\n"
        "    ldr r1, .L080F0304\n"
        "    lsls r0, r4, #7\n"
        "    movs r2, #0x9a\n"
        "    lsls r2, r2, #4\n"
        "    adds r0, r0, r2\n"
        "    adds r6, r0, r1\n"
        "    lsls r0, r5, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Demon_GetRecord\n"
        "    adds r7, r0, #0\n"
        "    movs r0, #0\n"
        "    str r0, [sp]\n"
        "    ldr r2, .L080F0308\n"
        "    mov r0, sp\n"
        "    adds r1, r6, #0\n"
        "    bl CpuSet\n"
        "    adds r4, #0x10\n"
        "    strb r4, [r6, #0xc]\n"
        "    strh r5, [r6, #0x12]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #8\n"
        "    strh r0, [r6, #0xe]\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r7, r0]\n"
        "    strh r0, [r6, #0x14]\n"
        "    ldrh r0, [r7, #2]\n"
        "    strh r0, [r6, #0x18]\n"
        "    ldrh r0, [r7, #2]\n"
        "    strh r0, [r6, #0x1a]\n"
        "    ldrh r0, [r7, #4]\n"
        "    strh r0, [r6, #0x1c]\n"
        "    ldrh r0, [r7, #4]\n"
        "    strh r0, [r6, #0x1e]\n"
        "    ldrb r0, [r7, #1]\n"
        "    strb r0, [r6, #0xd]\n"
        "    ldrb r0, [r7, #0xc]\n"
        "    lsls r0, r0, #8\n"
        "    adds r2, r6, #0\n"
        "    adds r2, #0x58\n"
        "    strh r0, [r2]\n"
        "    movs r0, #0xa\n"
        "    strb r0, [r6, #0x17]\n"
        "    strb r0, [r6, #0x16]\n"
        "    ldrb r1, [r7, #6]\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x40\n"
        "    strb r1, [r0]\n"
        "    ldrb r0, [r7, #7]\n"
        "    adds r1, r6, #0\n"
        "    adds r1, #0x41\n"
        "    strb r0, [r1]\n"
        "    ldrb r0, [r7, #8]\n"
        "    adds r1, #1\n"
        "    strb r0, [r1]\n"
        "    ldrb r0, [r7, #9]\n"
        "    adds r1, #1\n"
        "    strb r0, [r1]\n"
        "    ldrb r1, [r7, #0xa]\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x44\n"
        "    strb r1, [r0]\n"
        "    ldrb r0, [r7, #0xb]\n"
        "    adds r1, r6, #0\n"
        "    adds r1, #0x45\n"
        "    strb r0, [r1]\n"
        "    ldr r0, [r6, #0x40]\n"
        "    ldr r1, [r6, #0x44]\n"
        "    str r0, [r6, #0x28]\n"
        "    str r1, [r6, #0x2c]\n"
        "    ldrb r0, [r7, #0xc]\n"
        "    lsls r0, r0, #8\n"
        "    strh r0, [r2]\n"
        "    movs r3, #0\n"
        "    adds r2, #5\n"
        "    movs r4, #0xff\n"
        "    adds r5, r2, #0\n"
        ".L080F02AA:\n"
        "    adds r1, r2, r3\n"
        "    ldrb r0, [r1]\n"
        "    orrs r0, r4\n"
        "    strb r0, [r1]\n"
        "    adds r3, #1\n"
        "    cmp r3, #0x1f\n"
        "    ble .L080F02AA\n"
        "    movs r4, #0\n"
        "    movs r3, #0\n"
        "    movs r0, #0x40\n"
        "    adds r0, r0, r6\n"
        "    mov sb, r0\n"
        "    movs r2, #0x48\n"
        "    adds r2, r2, r6\n"
        "    mov ip, r2\n"
        "    movs r0, #0x22\n"
        "    adds r0, r0, r7\n"
        "    mov r8, r0\n"
        "    adds r2, r5, #0\n"
        "    adds r5, r7, #0\n"
        "    adds r5, #0x11\n"
        ".L080F02D4:\n"
        "    adds r0, r2, r4\n"
        "    adds r1, r5, r3\n"
        "    ldrb r1, [r1]\n"
        "    strb r1, [r0]\n"
        "    adds r4, #1\n"
        "    adds r3, #1\n"
        "    cmp r3, #6\n"
        "    ble .L080F02D4\n"
        "    ldrb r0, [r6, #0xd]\n"
        "    mov r1, sb\n"
        "    mov r2, ip\n"
        "    bl Stats_CalcDerived\n"
        "    mov r0, r8\n"
        "    adds r1, r6, #0\n"
        "    bl Name_Encode\n"
        "    add sp, #4\n"
        "    pop {r3, r4}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080F0304: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080F0308: .4byte 0x05000020 @ PLTT+0x20\n"
    );
}
#endif

// sub_080F030C @ 0x080F030C
#ifdef NONMATCHING
u16 sub_080F030C(u16 a, u16 b)
{
    u8 lvl = a >> 8;
    u16 n = a & 0xF;
    u16 v;

    if (n > 7)
        n = (n & 7) + 1;
    v = n * lvl;
    if (!(b & 0x80))
        v <<= 3;
    return v;
}
#else
NAKED u16 sub_080F030C(u16 a, u16 b)
{
    asm_unified(
        ".L080F030C:\n"
        "    push {lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r2, r1, #0x10\n"
        "    lsrs r3, r0, #0x18\n"
        "    movs r1, #0xf0\n"
        "    lsls r1, r1, #0xc\n"
        "    ands r1, r0\n"
        "    lsrs r1, r1, #0x10\n"
        "    cmp r1, #7\n"
        "    bls .L080F0328\n"
        "    movs r0, #7\n"
        "    ands r1, r0\n"
        "    adds r1, #1\n"
        ".L080F0328:\n"
        "    adds r0, r1, #0\n"
        "    muls r0, r3, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    movs r0, #0x80\n"
        "    ands r2, r0\n"
        "    cmp r2, #0\n"
        "    bne .L080F033C\n"
        "    lsls r0, r1, #0x13\n"
        "    lsrs r1, r0, #0x10\n"
        ".L080F033C:\n"
        "    adds r0, r1, #0\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// sub_080F0344 @ 0x080F0344
#ifdef NONMATCHING
void sub_080F0344(u16 kind, u16 v)
{
    struct BattleFlow *b = BFLOW;

    switch (kind)
    {
    case 3:
        gUnk_030000AC = b->unk97C;
        b->unk97C = v;
        break;
    case 4:
        gUnk_030000AC = b->unk97E;
        b->unk97E = v;
        break;
    }
}
#else
NAKED void sub_080F0344(u16 kind, u16 v)
{
    asm_unified(
        ".L080F0344:\n"
        "    push {lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r3, r1, #0x10\n"
        "    ldr r1, .L080F0360\n"
        "    cmp r0, #3\n"
        "    beq .L080F0364\n"
        "    cmp r0, #3\n"
        "    ble .L080F0380\n"
        "    cmp r0, #4\n"
        "    beq .L080F0374\n"
        "    b .L080F0380\n"
        "    .byte 0x00, 0x00\n"
        ".L080F0360: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080F0364:\n"
        "    ldr r2, .L080F036C\n"
        "    ldr r0, .L080F0370\n"
        "    b .L080F0378\n"
        "    .byte 0x00, 0x00\n"
        ".L080F036C: .4byte 0x030000AC @ IWRAM+0xAC\n"
        ".L080F0370: .4byte 0x0000097C\n"
        ".L080F0374:\n"
        "    ldr r2, .L080F0384\n"
        "    ldr r0, .L080F0388\n"
        ".L080F0378:\n"
        "    adds r1, r1, r0\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r2]\n"
        "    strh r3, [r1]\n"
        ".L080F0380:\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080F0384: .4byte 0x030000AC @ IWRAM+0xAC\n"
        ".L080F0388: .4byte 0x0000097E\n"
    );
}
#endif

// sub_080F038C @ 0x080F038C
s16 sub_080F038C(s16 who, u8 *c)
{
    s16 x = Battle_IsEnemyId(who);
    u16 f = *(u16 *)(c + 0x10);

    if (f & 0x200)
        x = (x == 0);
    if (x == 0)
        Battle_BuildActionTargets(who);
    else
        Battle_BuildTargetList(who);
    return x;
}

// sub_080F03D8 @ 0x080F03D8
u32 sub_080F03D8(s8 kind, s32 id)
{
    if (kind == 11
        && (id == 0x4B || id == 0x4C || id == 0x6D || id == 0x6E || id == 0x6F || id == 0x4E
            || id == 0x4F || id == 0x71 || id == 0x74 || id == 0x7C || id == 0x84 || id == 0x88
            || id == 0x8A || id == 0x8D || id == 0x8E || id == 0x90 || id == 0x91 || id == 0x92))
        return 1;
    return 0;
}
