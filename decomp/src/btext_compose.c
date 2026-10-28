#include "global.h"
#include "btext.h"

// MessageBox_ComposeRaceNameText @ 0x080EAA08
u16 *MessageBox_ComposeRaceNameText(u32 id, u16 *suffix)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
    u8 *demon;
    u16 *src;
    u16 *dst;
    u8 i;
    u32 zero;

    if (msg->locked == 1)
        return b->msg.compose;

    demon = Demon_GetRecord(id);
    zero = 0;
    dst = b->msg.compose;
    CpuSet(&zero, dst, 0x05000020);
    src = Race_GetName(*(s8 *)demon);
    while (*src != 0)
        *dst++ = *src++;
    src = (u16 *)(demon + 0x22);
    for (i = 0; i < 8; i++)
    {
        if (*src == 0)
            break;
        *dst++ = *src++;
    }
    src = suffix;
    while (*src != 0)
        *dst++ = *src++;
    return BLOCK->msg.compose;
}

// MessageBox_ComposeNameText @ 0x080EAAB0
u16 *MessageBox_ComposeNameText(u32 id, u16 *suffix)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
    u8 *demon;
    u16 *src;
    u16 *dst;
    u8 i;
    u32 zero;

    if (msg->locked == 1)
        return b->msg.compose;

    demon = Demon_GetRecord(id);
    zero = 0;
    CpuSet(&zero, b->msg.compose, 0x05000020);
    dst = b->msg.compose;
    src = (u16 *)(demon + 0x22);
    for (i = 0; i < 8; i++)
    {
        if (*src == 0)
            break;
        *dst++ = *src++;
    }
    src = suffix;
    while (*src != 0)
        *dst++ = *src++;
    return BLOCK->msg.compose;
}

// MessageBox_ComposeTwoNamesText @ 0x080EAB3C
u16 *MessageBox_ComposeTwoNamesText(u32 id1, u32 id2, u16 *suffix)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
    u16 *src;
    u16 *dst;
    u8 i;
    u32 zero;

    if (msg->locked == 1)
        return b->msg.compose;

    zero = 0;
    CpuSet(&zero, b->msg.compose, 0x05000020);
    dst = b->msg.compose;
    src = (u16 *)(Demon_GetRecord(id1) + 0x22);
    for (i = 0; i < 8; i++)
    {
        if (*src == 0)
            break;
        *dst++ = *src++;
    }
    *dst++ = 0x143;
    *dst++ = 0x300;
    src = (u16 *)(Demon_GetRecord(id2) + 0x22);
    for (i = 0; i < 8; i++)
    {
        if (*src == 0)
            break;
        *dst++ = *src++;
    }
    src = suffix;
    while (*src != 0)
        *dst++ = *src++;
    return BLOCK->msg.compose;
}

/* Expands a message template into the compose buffer: 0x31E = demon name (first id1, then
   id2), 0x31F = race name (likewise), 0x323 = character from gUnknown_086BED48 indexed by v1
   then v2, 0x324 = Battle_AppendCombatantName; ends at 0x301 or 0. */
// MessageBox_ComposeSpeciesText @ 0x080EAC0C
#ifdef NONMATCHING
u16 *MessageBox_ComposeSpeciesText(u32 id1, u32 id2, s32 v1, s32 v2, u16 *tmpl)
{
    struct BattleMsgBlock *b = BLOCK;
    struct BattleMsg *msg = &b->msg;
    u16 nameCount = 0;
    u16 raceCount = 0;
    u16 valCount = 0;
    u16 *src;
    u16 *dst;
    u8 *demon;
    u8 i;
    u32 zero;

    if (msg->locked == 1)
        return b->msg.compose;

    zero = 0;
    CpuSet(&zero, b->msg.compose, 0x05000020);
    dst = b->msg.compose;
    while (*tmpl != 0x301 && *tmpl != 0)
    {
        switch (*tmpl)
        {
        case 0x324:
            dst = Battle_AppendCombatantName(0, dst);
            break;
        case 0x31F:
            if (raceCount++ == 0)
                demon = Demon_GetRecord(id1);
            else
                demon = Demon_GetRecord(id2);
            src = Race_GetName(*(s8 *)demon);
            while (*src != 0)
                *dst++ = *src++;
            break;
        case 0x31E:
            if (nameCount++ == 0)
                demon = Demon_GetRecord(id1);
            else
                demon = Demon_GetRecord(id2);
            src = (u16 *)(demon + 0x22);
            for (i = 0; i < 8; i++)
            {
                if (*src == 0)
                    break;
                *dst++ = *src++;
            }
            break;
        case 0x323:
            *dst++ = gUnknown_086BED48[valCount == 0 ? v1 : v2];
            valCount++;
            break;
        default:
            *dst++ = *tmpl;
            break;
        }
        tmpl++;
    }
    *dst = 0;
    return BLOCK->msg.compose;
}
#else
NAKED
u16 *MessageBox_ComposeSpeciesText(u32 id1, u32 id2, s32 v1, s32 v2, u16 *tmpl)
{
    asm_unified(
        ".L080EAC0C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0xc\n"
        "    mov sb, r0\n"
        "    mov r8, r1\n"
        "    str r2, [sp, #4]\n"
        "    str r3, [sp, #8]\n"
        "    ldr r5, [sp, #0x2c]\n"
        "    ldr r4, .L080EAC3C\n"
        "    movs r1, #0xfc\n"
        "    lsls r1, r1, #3\n"
        "    adds r0, r4, r1\n"
        "    movs r6, #0\n"
        "    mov sl, r6\n"
        "    movs r7, #0\n"
        "    ldrb r0, [r0, #7]\n"
        "    cmp r0, #1\n"
        "    bne .L080EAC44\n"
        "    ldr r1, .L080EAC40\n"
        "    adds r0, r4, r1\n"
        "    b .L080EAD66\n"
        ".L080EAC3C: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080EAC40: .4byte 0x000008EC\n"
        ".L080EAC44:\n"
        "    str r7, [sp]\n"
        "    ldr r0, .L080EAC58\n"
        "    adds r4, r4, r0\n"
        "    ldr r2, .L080EAC5C\n"
        "    mov r0, sp\n"
        "    adds r1, r4, #0\n"
        "    bl CpuSet\n"
        "    b .L080EAD52\n"
        "    .byte 0x00, 0x00\n"
        ".L080EAC58: .4byte 0x000008EC\n"
        ".L080EAC5C: .4byte 0x05000020 @ PLTT+0x20\n"
        ".L080EAC60:\n"
        "    ldrh r1, [r5]\n"
        "    ldr r0, .L080EAC74\n"
        "    cmp r1, r0\n"
        "    beq .L080EAC94\n"
        "    cmp r1, r0\n"
        "    bgt .L080EAC78\n"
        "    subs r0, #1\n"
        "    cmp r1, r0\n"
        "    beq .L080EACE0\n"
        "    b .L080EAD48\n"
        ".L080EAC74: .4byte 0x0000031F\n"
        ".L080EAC78:\n"
        "    ldr r0, .L080EAC90\n"
        "    cmp r1, r0\n"
        "    beq .L080EAD28\n"
        "    adds r0, #1\n"
        "    cmp r1, r0\n"
        "    bne .L080EAD48\n"
        "    movs r0, #0\n"
        "    adds r1, r4, #0\n"
        "    bl Battle_AppendCombatantName\n"
        "    adds r4, r0, #0\n"
        "    b .L080EAD4E\n"
        ".L080EAC90: .4byte 0x00000323\n"
        ".L080EAC94:\n"
        "    mov r1, sl\n"
        "    cmp r1, #0\n"
        "    bne .L080EACA6\n"
        "    mov r1, sb\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Demon_GetRecord\n"
        "    b .L080EACB0\n"
        ".L080EACA6:\n"
        "    mov r1, r8\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Demon_GetRecord\n"
        ".L080EACB0:\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Race_GetName\n"
        "    adds r2, r0, #0\n"
        "    ldrh r1, [r2]\n"
        "    mov r0, sl\n"
        "    adds r0, #1\n"
        "    adds r3, r5, #2\n"
        "    cmp r1, #0\n"
        "    beq .L080EACD8\n"
        ".L080EACCC:\n"
        "    strh r1, [r4]\n"
        "    adds r2, #2\n"
        "    adds r4, #2\n"
        "    ldrh r1, [r2]\n"
        "    cmp r1, #0\n"
        "    bne .L080EACCC\n"
        ".L080EACD8:\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sl, r0\n"
        "    b .L080EAD50\n"
        ".L080EACE0:\n"
        "    cmp r6, #0\n"
        "    bne .L080EACF0\n"
        "    mov r1, sb\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Demon_GetRecord\n"
        "    b .L080EACFA\n"
        ".L080EACF0:\n"
        "    mov r1, r8\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Demon_GetRecord\n"
        ".L080EACFA:\n"
        "    adds r2, r0, #0\n"
        "    adds r2, #0x22\n"
        "    movs r1, #0\n"
        "    ldrh r0, [r0, #0x22]\n"
        "    adds r6, #1\n"
        "    adds r3, r5, #2\n"
        "    cmp r0, #0\n"
        "    beq .L080EAD22\n"
        ".L080EAD0A:\n"
        "    ldrh r0, [r2]\n"
        "    strh r0, [r4]\n"
        "    adds r2, #2\n"
        "    adds r4, #2\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r1, r0, #0x18\n"
        "    cmp r1, #7\n"
        "    bhi .L080EAD22\n"
        "    ldrh r0, [r2]\n"
        "    cmp r0, #0\n"
        "    bne .L080EAD0A\n"
        ".L080EAD22:\n"
        "    lsls r0, r6, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    b .L080EAD50\n"
        ".L080EAD28:\n"
        "    cmp r7, #0\n"
        "    bne .L080EAD30\n"
        "    ldr r1, [sp, #4]\n"
        "    b .L080EAD32\n"
        ".L080EAD30:\n"
        "    ldr r1, [sp, #8]\n"
        ".L080EAD32:\n"
        "    lsls r0, r1, #1\n"
        "    ldr r1, .L080EAD44\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r4]\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    b .L080EAD4C\n"
        ".L080EAD44: .4byte gUnknown_086BED48\n"
        ".L080EAD48:\n"
        "    ldrh r0, [r5]\n"
        "    strh r0, [r4]\n"
        ".L080EAD4C:\n"
        "    adds r4, #2\n"
        ".L080EAD4E:\n"
        "    adds r3, r5, #2\n"
        ".L080EAD50:\n"
        "    adds r5, r3, #0\n"
        ".L080EAD52:\n"
        "    ldrh r1, [r5]\n"
        "    ldr r0, .L080EAD78\n"
        "    cmp r1, r0\n"
        "    beq .L080EAD60\n"
        "    cmp r1, #0\n"
        "    beq .L080EAD60\n"
        "    b .L080EAC60\n"
        ".L080EAD60:\n"
        "    movs r0, #0\n"
        "    strh r0, [r4]\n"
        "    ldr r0, .L080EAD7C\n"
        ".L080EAD66:\n"
        "    add sp, #0xc\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L080EAD78: .4byte 0x00000301\n"
        ".L080EAD7C: .4byte 0x0203CAEC @ EWRAM+0x3CAEC\n"
    );
}
#endif
