/* Script VM opcode handlers 0x447 (pre-scan)-0x44C and the first wait-state handlers (table
   0x08790FDC). */

#include "global.h"
#include "scriptops3.h"

// ScriptOpAlt_447 @ 0x0813C4E8
void ScriptOpAlt_447(void)
{
    gScriptPc += 3;
}

// sub_0813C4F8 @ 0x0813C4F8
void sub_0813C4F8(void)
{
}

/* Random check against sub_0813E854(gUnk_0203DB7C); the threshold depends on `kind`. */
// sub_0813C4FC @ 0x0813C4FC
bool32 sub_0813C4FC(u16 kind)
{
    u32 v;

    if (kind == 1)
    {
        v = Random_Byte();
        v &= 0x1F;
        v += 0x3B;
    }
    else if (kind == 2)
    {
        v = Random_Byte();
        v &= 0x1F;
        v += 0x54;
    }
    else
    {
        v = Random_Byte();
        v &= 0xF;
        v += 0x77;
    }
    if (sub_0813E854(gUnk_0203DB7C) < v)
        return TRUE;
    return FALSE;
}

/* Negotiation tests on demon gUnk_0203DB7C (high byte = test, low byte = argument);
   jumps to the operand pointer when the test fails. Tests 6/7 give an item instead. */
// ScriptOp_448 @ 0x0813C554
#ifdef NONMATCHING
void ScriptOp_448(void)
{
    u16 op = SCRIPT_READ();
    u16 lo;
    u32 target;
    u16 kind, arg;
    u16 v, stat, d;

    lo = SCRIPT_READ();
    target = SCRIPT_READ();
    target = target << 16 | lo;
    kind = op >> 8;
    arg = op & 0xFF;
    if (kind == 0)
    {
        if (gUnk_0300685C == arg)
            return;
    }
    else if (kind == 1)
    {
        Combatant_GetStat(0, 1);
        if (arg == 1)
            v = Demon_GetField(gUnk_0203DB7C, 6) + (Random_Byte() & 3) - 1;
        else if (arg == 2)
        {
            v = Random_Byte() & 7;
            v += Demon_GetField(gUnk_0203DB7C, 6) - (Random_Byte() & 3);
        }
        else
        {
            v = Random_Byte() & 7;
            v += Demon_GetField(gUnk_0203DB7C, 6);
        }
        v &= 0xFF;
        if (v < Combatant_GetStat(0, 1))
            return;
    }
    else if (kind == 2)
    {
        stat = Combatant_GetStat(0, 2);
        d = Demon_GetField(gUnk_0203DB7C, 7);
        if (arg == 1)
        {
            v = (Random_Byte() & 3) + d;
            if (v > 2)
                v -= 2;
            if (v < stat)
                return;
        }
        else if (arg == 2)
        {
            v = Random_Byte() & 7;
            v += d - (Random_Byte() & 7);
            if (v & 0x8000)
                return;
            if (v != 0)
                v--;
            if (v < stat)
                return;
        }
        else if (arg == 3)
        {
            v = (Random_Byte() & 7) + d;
            if (v < stat)
                return;
        }
        else
        {
            return;
        }
    }
    else if (kind == 3)
    {
        if ((u16)sub_0813C4FC(arg) == 0)
            return;
    }
    else if (kind == 4)
    {
        if (gUnk_03006690 < 12)
        {
            if (arg == 0)
                v = sub_0813BDCC();
            else
                v = sub_08137BB8();
            if (gUnk_03006690 != 0)
                v /= gUnk_03006690;
            if (v > 2)
                return;
        }
    }
    else if (kind == 5)
    {
        if (arg == 1)
        {
            if (!(gUnk_0300684C & 8))
                return;
        }
        else if (arg == 2)
        {
            if (!(gUnk_0300684C & 0x10))
                return;
        }
        else
        {
            return;
        }
    }
    else if (kind == 6)
    {
        gScriptItemCheckId = arg;
        if (!Inventory_IsMaxed(arg))
        {
            Inventory_AddItem(arg);
            gScriptJumpTarget = (u16 *)gUnknown_080A0BC6;
            gUnk_03006840 = target;
        }
        else
        {
            gScriptJumpTarget = (u16 *)gUnknown_080A0C0A;
            gUnk_03006840 = target;
        }
        return;
    }
    else if (kind == 7)
    {
        arg |= 0x100;
        gScriptItemCheckId = arg;
        if (sub_080C5C14(arg) != 0)
            return;
    }
    else
    {
        return;
    }
    gScriptJumpTarget = (u16 *)target;
}
#else
NAKED
void ScriptOp_448(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    ldr r3, .L0813C5A4\n"
        "    ldrh r0, [r3]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r3]\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r2, .L0813C5A8\n"
        "    ldr r2, [r2]\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r2\n"
        "    ldrh r5, [r0]\n"
        "    adds r0, r1, #1\n"
        "    strh r0, [r3]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0xf\n"
        "    adds r1, r1, r2\n"
        "    ldrh r4, [r1]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r3]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r2\n"
        "    ldrh r7, [r0]\n"
        "    lsls r7, r7, #0x10\n"
        "    orrs r7, r4\n"
        "    lsrs r0, r5, #8\n"
        "    adds r1, r0, #0\n"
        "    movs r4, #0xff\n"
        "    ands r4, r5\n"
        "    cmp r0, #0\n"
        "    bne .L0813C5B0\n"
        "    ldr r0, .L0813C5AC\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, r4\n"
        "    bne .L0813C5A0\n"
        "    b .L0813C7DA\n"
        ".L0813C5A0:\n"
        "    b .L0813C7D6\n"
        "    .byte 0x00, 0x00\n"
        ".L0813C5A4: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L0813C5A8: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L0813C5AC: .4byte 0x0300685C @ IWRAM+0x685C\n"
        ".L0813C5B0:\n"
        "    cmp r0, #1\n"
        "    bne .L0813C644\n"
        "    movs r0, #0\n"
        "    movs r1, #1\n"
        "    bl Combatant_GetStat\n"
        "    cmp r4, #1\n"
        "    bne .L0813C5E0\n"
        "    ldr r0, .L0813C5DC\n"
        "    ldrh r0, [r0]\n"
        "    movs r1, #6\n"
        "    bl Demon_GetField\n"
        "    adds r4, r0, #0\n"
        "    bl Random_Byte\n"
        "    movs r1, #3\n"
        "    ands r0, r1\n"
        "    adds r4, r4, r0\n"
        "    subs r4, #1\n"
        "    b .L0813C606\n"
        "    .byte 0x00, 0x00\n"
        ".L0813C5DC: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813C5E0:\n"
        "    cmp r4, #2\n"
        "    bne .L0813C610\n"
        "    bl Random_Byte\n"
        "    adds r5, r0, #0\n"
        "    movs r0, #7\n"
        "    ands r5, r0\n"
        "    ldr r0, .L0813C60C\n"
        "    ldrh r0, [r0]\n"
        "    movs r1, #6\n"
        "    bl Demon_GetField\n"
        "    adds r4, r0, #0\n"
        "    bl Random_Byte\n"
        "    movs r1, #3\n"
        "    ands r0, r1\n"
        "    subs r4, r4, r0\n"
        "    adds r4, r5, r4\n"
        ".L0813C606:\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r5, r4, #0x10\n"
        "    b .L0813C62A\n"
        ".L0813C60C: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813C610:\n"
        "    bl Random_Byte\n"
        "    adds r5, r0, #0\n"
        "    movs r0, #7\n"
        "    ands r5, r0\n"
        "    ldr r0, .L0813C640\n"
        "    ldrh r0, [r0]\n"
        "    movs r1, #6\n"
        "    bl Demon_GetField\n"
        "    adds r0, r5, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        ".L0813C62A:\n"
        "    movs r0, #0xff\n"
        "    ands r5, r0\n"
        "    movs r0, #0\n"
        "    movs r1, #1\n"
        "    bl Combatant_GetStat\n"
        "    cmp r5, r0\n"
        "    bge .L0813C63C\n"
        "    b .L0813C7DA\n"
        ".L0813C63C:\n"
        "    b .L0813C7D6\n"
        "    .byte 0x00, 0x00\n"
        ".L0813C640: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813C644:\n"
        "    cmp r0, #2\n"
        "    bne .L0813C6EA\n"
        "    movs r0, #0\n"
        "    movs r1, #2\n"
        "    bl Combatant_GetStat\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        "    ldr r0, .L0813C68C\n"
        "    ldrh r0, [r0]\n"
        "    movs r1, #7\n"
        "    bl Demon_GetField\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r4, #1\n"
        "    bne .L0813C694\n"
        "    bl Random_Byte\n"
        "    movs r1, #3\n"
        "    ands r0, r1\n"
        "    adds r0, r0, r6\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #2\n"
        "    bls .L0813C682\n"
        "    lsls r0, r5, #0x10\n"
        "    ldr r1, .L0813C690\n"
        "    adds r0, r0, r1\n"
        "    lsrs r5, r0, #0x10\n"
        ".L0813C682:\n"
        "    cmp r5, r8\n"
        "    bhs .L0813C688\n"
        "    b .L0813C7DA\n"
        ".L0813C688:\n"
        "    b .L0813C7D6\n"
        "    .byte 0x00, 0x00\n"
        ".L0813C68C: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813C690: .4byte 0xFFFE0000\n"
        ".L0813C694:\n"
        "    cmp r4, #2\n"
        "    bne .L0813C6CE\n"
        "    bl Random_Byte\n"
        "    adds r5, r0, #0\n"
        "    movs r4, #7\n"
        "    ands r5, r4\n"
        "    bl Random_Byte\n"
        "    ands r0, r4\n"
        "    subs r0, r6, r0\n"
        "    adds r0, r5, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #8\n"
        "    ands r0, r5\n"
        "    cmp r0, #0\n"
        "    beq .L0813C6BC\n"
        "    b .L0813C7DA\n"
        ".L0813C6BC:\n"
        "    cmp r5, #0\n"
        "    beq .L0813C6C6\n"
        "    subs r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        ".L0813C6C6:\n"
        "    cmp r5, r8\n"
        "    bhs .L0813C6CC\n"
        "    b .L0813C7DA\n"
        ".L0813C6CC:\n"
        "    b .L0813C7D6\n"
        ".L0813C6CE:\n"
        "    cmp r4, #3\n"
        "    beq .L0813C6D4\n"
        "    b .L0813C7DA\n"
        ".L0813C6D4:\n"
        "    bl Random_Byte\n"
        "    movs r1, #7\n"
        "    ands r0, r1\n"
        "    adds r0, r0, r6\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, r8\n"
        "    bhs .L0813C6E8\n"
        "    b .L0813C7DA\n"
        ".L0813C6E8:\n"
        "    b .L0813C7D6\n"
        ".L0813C6EA:\n"
        "    cmp r0, #3\n"
        "    bne .L0813C6FC\n"
        "    adds r0, r4, #0\n"
        "    bl sub_0813C4FC\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L0813C7DA\n"
        "    b .L0813C7D6\n"
        ".L0813C6FC:\n"
        "    cmp r0, #4\n"
        "    bne .L0813C73C\n"
        "    ldr r0, .L0813C714\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0xb\n"
        "    bhi .L0813C7D6\n"
        "    cmp r4, #0\n"
        "    bne .L0813C718\n"
        "    bl sub_0813BDCC\n"
        "    b .L0813C71C\n"
        "    .byte 0x00, 0x00\n"
        ".L0813C714: .4byte 0x03006690 @ IWRAM+0x6690\n"
        ".L0813C718:\n"
        "    bl sub_08137BB8\n"
        ".L0813C71C:\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    ldr r0, .L0813C738\n"
        "    ldrh r1, [r0]\n"
        "    cmp r1, #0\n"
        "    beq .L0813C732\n"
        "    adds r0, r5, #0\n"
        "    bl __udivsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        ".L0813C732:\n"
        "    cmp r5, #2\n"
        "    bhi .L0813C7DA\n"
        "    b .L0813C7D6\n"
        ".L0813C738: .4byte 0x03006690 @ IWRAM+0x6690\n"
        ".L0813C73C:\n"
        "    cmp r0, #5\n"
        "    bne .L0813C770\n"
        "    cmp r4, #1\n"
        "    bne .L0813C758\n"
        "    ldr r0, .L0813C754\n"
        "    ldrb r1, [r0]\n"
        "    movs r0, #8\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L0813C7DA\n"
        "    b .L0813C7D6\n"
        "    .byte 0x00, 0x00\n"
        ".L0813C754: .4byte 0x0300684C @ IWRAM+0x684C\n"
        ".L0813C758:\n"
        "    cmp r4, #2\n"
        "    bne .L0813C7DA\n"
        "    ldr r0, .L0813C76C\n"
        "    ldrb r1, [r0]\n"
        "    movs r0, #0x10\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L0813C7DA\n"
        "    b .L0813C7D6\n"
        "    .byte 0x00, 0x00\n"
        ".L0813C76C: .4byte 0x0300684C @ IWRAM+0x684C\n"
        ".L0813C770:\n"
        "    cmp r0, #6\n"
        "    bne .L0813C7BC\n"
        "    ldr r0, .L0813C794\n"
        "    strh r4, [r0]\n"
        "    adds r0, r4, #0\n"
        "    bl Inventory_IsMaxed\n"
        "    lsls r0, r0, #0x18\n"
        "    cmp r0, #0\n"
        "    bne .L0813C7A4\n"
        "    adds r0, r4, #0\n"
        "    bl Inventory_AddItem\n"
        "    ldr r0, .L0813C798\n"
        "    ldr r1, .L0813C79C\n"
        "    str r1, [r0]\n"
        "    ldr r0, .L0813C7A0\n"
        "    b .L0813C7D8\n"
        ".L0813C794: .4byte 0x0203DB50 @ EWRAM+0x3DB50\n"
        ".L0813C798: .4byte 0x030068E4 @ IWRAM+0x68E4\n"
        ".L0813C79C: .4byte gUnknown_080A0BC6\n"
        ".L0813C7A0: .4byte 0x03006840 @ IWRAM+0x6840\n"
        ".L0813C7A4:\n"
        "    ldr r0, .L0813C7B0\n"
        "    ldr r1, .L0813C7B4\n"
        "    str r1, [r0]\n"
        "    ldr r0, .L0813C7B8\n"
        "    b .L0813C7D8\n"
        "    .byte 0x00, 0x00\n"
        ".L0813C7B0: .4byte 0x030068E4 @ IWRAM+0x68E4\n"
        ".L0813C7B4: .4byte gUnknown_080A0C0A\n"
        ".L0813C7B8: .4byte 0x03006840 @ IWRAM+0x6840\n"
        ".L0813C7BC:\n"
        "    cmp r1, #7\n"
        "    bne .L0813C7DA\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #1\n"
        "    adds r0, r1, #0\n"
        "    orrs r4, r0\n"
        "    ldr r0, .L0813C7E4\n"
        "    strh r4, [r0]\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080C5C14\n"
        "    cmp r0, #0\n"
        "    bne .L0813C7DA\n"
        ".L0813C7D6:\n"
        "    ldr r0, .L0813C7E8\n"
        ".L0813C7D8:\n"
        "    str r7, [r0]\n"
        ".L0813C7DA:\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L0813C7E4: .4byte 0x0203DB50 @ EWRAM+0x3DB50\n"
        ".L0813C7E8: .4byte 0x030068E4 @ IWRAM+0x68E4\n"
    );
}
#endif

// ScriptOp_44A @ 0x0813C7EC
void ScriptOp_44A(void)
{
    u16 n = SCRIPT_READ();

    if (n >= 0xF0)
    {
        n = 0x100 - n;
        ItemStock_Remove(gUnk_0203DB7C, n);
    }
    else
    {
        ItemStock_Add(gUnk_0203DB7C, n);
    }
}

// ScriptOpAlt_44A @ 0x0813C838
void ScriptOpAlt_44A(void)
{
    gScriptPc++;
}

/* Moves the hero's alignment one step: 0 toward 0, 2+ toward 0xFF, 1 toward the middle. */
// ScriptOp_44B @ 0x0813C848
#ifdef NONMATCHING
void ScriptOp_44B(void)
{
    u16 op = SCRIPT_READ();
    u16 sign, m;
    u32 v;
    s32 d;

    if (Flag_Test(0xE0))
        return;
    op--;
    sign = 0x8000;
    if (op & sign)
        goto down;
    if ((u16)(op - 1) & sign)
        goto middle;
up:
    v = sub_080C0794(0);
    m = 0xFF00;
    if ((v & m) == m)
        return;
    d = 0x100;
    goto add;
down:
    v = sub_080C0794(0);
    m = 0xFF00;
    if (!(v & m))
        return;
    d = -0x100;
add:
    Combatant_AddAlignment(0, d);
    return;
middle:
    v = sub_080C0794(0);
    m = 0xFF00;
    if (v & m & sign)
        goto down;
    goto up;
}
#else
NAKED
void ScriptOp_44B(void)
{
    asm_unified(
        "    push {r4, lr}\n"
        "    ldr r2, .L0813C89C\n"
        "    ldrh r0, [r2]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r2]\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r1, .L0813C8A0\n"
        "    ldr r1, [r1]\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r1\n"
        "    ldrh r4, [r0]\n"
        "    movs r0, #0xe0\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L0813C8DA\n"
        "    subs r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    movs r4, #0x80\n"
        "    lsls r4, r4, #8\n"
        "    adds r0, r1, #0\n"
        "    ands r0, r4\n"
        "    cmp r0, #0\n"
        "    bne .L0813C8A4\n"
        "    subs r0, r1, #1\n"
        "    ands r0, r4\n"
        "    cmp r0, #0\n"
        "    bne .L0813C8C4\n"
        ".L0813C882:\n"
        "    movs r0, #0\n"
        "    bl sub_080C0794\n"
        "    movs r2, #0xff\n"
        "    lsls r2, r2, #8\n"
        "    adds r1, r2, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, r1\n"
        "    beq .L0813C8DA\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #1\n"
        "    b .L0813C8B8\n"
        "    .byte 0x00, 0x00\n"
        ".L0813C89C: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L0813C8A0: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L0813C8A4:\n"
        "    movs r0, #0\n"
        "    bl sub_080C0794\n"
        "    movs r2, #0xff\n"
        "    lsls r2, r2, #8\n"
        "    adds r1, r2, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L0813C8DA\n"
        "    ldr r1, .L0813C8C0\n"
        ".L0813C8B8:\n"
        "    movs r0, #0\n"
        "    bl Combatant_AddAlignment\n"
        "    b .L0813C8DA\n"
        ".L0813C8C0: .4byte 0xFFFFFF00\n"
        ".L0813C8C4:\n"
        "    movs r0, #0\n"
        "    bl sub_080C0794\n"
        "    movs r2, #0xff\n"
        "    lsls r2, r2, #8\n"
        "    adds r1, r2, #0\n"
        "    ands r0, r1\n"
        "    ands r0, r4\n"
        "    cmp r0, #0\n"
        "    bne .L0813C8A4\n"
        "    b .L0813C882\n"
        ".L0813C8DA:\n"
        "    pop {r4}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

// ScriptOpAlt_44B @ 0x0813C8E0
void ScriptOpAlt_44B(void)
{
    gScriptPc++;
}

// sub_0813C8F0 @ 0x0813C8F0
void sub_0813C8F0(void)
{
    gScriptPc++;
}

// ScriptOpAlt_44C @ 0x0813C900
void ScriptOpAlt_44C(void)
{
    gScriptPc++;
}

// sub_0813C910 @ 0x0813C910
void sub_0813C910(void)
{
    gScriptWaitBusy = 0;
}

// sub_0813C91C @ 0x0813C91C
void sub_0813C91C(void)
{
    if (!Window_IsIdle(gMsgWindow))
    {
        gScriptWaitBusy = 1;
    }
    else
    {
        gScriptWaitState = 0;
        gScriptWaitBusy = 0;
    }
}

// sub_0813C954 @ 0x0813C954
void sub_0813C954(void)
{
    s32 state = Task_GetState(gUnk_030068B0);

    if (state != 0)
    {
        gScriptWaitBusy = 1;
    }
    else
    {
        gScriptWaitState = state;
        gScriptWaitBusy = state;
    }
}

// sub_0813C988 @ 0x0813C988
void sub_0813C988(void)
{
    gScriptJumpTarget = gUnk_0203DAC8[0];
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

// sub_0813C9AC @ 0x0813C9AC
void sub_0813C9AC(void)
{
    gUnk_0203DB56 = 0;
    gUnk_0203DB52 = 0;
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

// sub_0813C9D0 @ 0x0813C9D0
void sub_0813C9D0(void)
{
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

// sub_0813C9E4 @ 0x0813C9E4
void sub_0813C9E4(void)
{
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

/* Waits for the yes/no box; "yes" (no in battle) jumps to gUnk_0203DAC8[0]. */
// ScriptWait_YesNo @ 0x0813C9F8
void ScriptWait_YesNo(void)
{
    if (!Task_IsFree(gUnk_030068E0))
    {
        gScriptWaitBusy = 1;
        return;
    }
    gScriptWaitState = 0;
    gMsgGlyphCount = 0;
    gTextColumn = 0;
    gTextLine = 0;
    gUnk_0203DB4A = 0;
    Font_ResetGlyphSpriteCache(0x180);
    gUnk_0203DB48 = ScriptVM_GetTextSpeed();
    if (gUnk_03006670 == 0)
    {
        if (gYesNoResult != 0)
            gScriptJumpTarget = gUnk_0203DAC8[0];
    }
    else
    {
        if (gYesNoResult == 0)
            gScriptJumpTarget = gUnk_0203DAC8[0];
    }
    gScriptWaitBusy = 0;
}

// sub_0813CA98 @ 0x0813CA98
void sub_0813CA98(void)
{
    if (--gUnk_0203DB5C == 0)
    {
        gUnk_0203DB5C = gUnk_030068C8;
        gScriptWaitState = 0x39;
    }
    gScriptWaitBusy = 1;
}

/* Drains 1000 macca per frame until the counter runs out. */
// sub_0813CAD0 @ 0x0813CAD0
void sub_0813CAD0(void)
{
    gUnk_0203DB5C--;
    Money_Add(-1000);
    if (gUnk_0203DB5C == 0)
    {
        if (Money_Get() != 0)
        {
            gUnk_0203DB5C = 1;
            gScriptWaitBusy = 1;
            return;
        }
        gScriptWaitState = 0x3A;
        gUnk_0203DB5C = 60;
    }
    gScriptWaitBusy = 1;
}

// sub_0813CB28 @ 0x0813CB28
void sub_0813CB28(void)
{
    if (--gUnk_0203DB5C == 0)
    {
        sub_080C762C();
        gScriptWaitState = 15;
        gUnk_0203DB5C = 60;
    }
    gScriptWaitBusy = 1;
}

// sub_0813CB60 @ 0x0813CB60
void sub_0813CB60(void)
{
    if (--gUnk_0203DB5C == 0)
    {
        gScriptWaitState = 0x11;
        Money_Add((s16)gUnk_0203DB62);
        gUnk_0203DB5C = 30;
    }
    gScriptWaitBusy = 1;
}

// sub_0813CBA0 @ 0x0813CBA0
void sub_0813CBA0(void)
{
    if (--gUnk_0203DB5C == 0)
    {
        sub_080C762C();
        gScriptWaitState = 15;
        gUnk_0203DB5C = 60;
    }
    gScriptWaitBusy = 1;
}

// sub_0813CBD8 @ 0x0813CBD8
void sub_0813CBD8(void)
{
    s32 n = (s16)--gUnk_0203DB5C;

    if (n == 0)
    {
        gScriptWaitState = n;
        gScriptWaitBusy = n;
    }
    gScriptWaitBusy = 1;
}

// sub_0813CC08 @ 0x0813CC08
void sub_0813CC08(void)
{
    switch (sub_0812685C())
    {
    case 4:
        gScriptWaitState = 0;
        gScriptWaitBusy = 0;
        break;
    case 5:
        sub_08132890();
    default:
        gScriptWaitBusy = 1;
        break;
    }
}

// sub_0813CC44 @ 0x0813CC44
void sub_0813CC44(void)
{
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

/* Choice made: the shop's buy list (kind 4) jumps when the price is too high; other lists
   jump to the chosen entry's pointer. */
// sub_0813CC58 @ 0x0813CC58
void sub_0813CC58(void)
{
    gMsgGlyphCount = 0;
    gTextColumn = 0;
    gTextLine = 0;
    gUnk_0203DB4A = 0;
    Font_ResetGlyphSpriteCache(0x180);
    if (gUnk_03006844 == 4)
    {
        if (Money_Get() < sub_0812F188(gUnk_030065E0 - 0x9D))
            gScriptJumpTarget = gUnk_0203DAC8[0];
    }
    else if (gUnk_030069CC != 0)
    {
        gScriptJumpTarget = gUnk_0203DAC8[gUnk_03006940 + gUnk_0300696C + 10];
    }
    else
    {
        gScriptJumpTarget = gUnk_0203DAC8[gUnk_03006940 + gUnk_0300696C];
    }
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

/* Choice cancelled. */
// sub_0813CD38 @ 0x0813CD38
void sub_0813CD38(void)
{
    gMsgGlyphCount = 0;
    gTextColumn = 0;
    gTextLine = 0;
    gUnk_0203DB4A = 0;
    Font_ResetGlyphSpriteCache(0x180);
    if (gUnk_03006844 == 4)
    {
        gScriptJumpTarget = gUnk_0203DAC8[1];
    }
    else if (gUnk_030069CC != 0)
    {
        gScriptJumpTarget = gUnk_0203DAC8[14];
        gUnk_030069CC = 0;
    }
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

// sub_0813CDBC @ 0x0813CDBC
void sub_0813CDBC(void)
{
    if ((u16)sub_0813DA6C())
        gScriptWaitBusy = 0;
    else
        gScriptWaitBusy = 1;
}

// sub_0813CDE4 @ 0x0813CDE4
void sub_0813CDE4(void)
{
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

// sub_0813CDF8 @ 0x0813CDF8
void sub_0813CDF8(void)
{
    gScriptWaitState = 0;
    if (gUnk_0203DAC8[4] != NULL)
    {
        gScriptJumpTarget = gUnk_0203DAC8[4];
        gUnk_03006620[0].unk0 = gUnk_03006620[1].unk0 = gUnk_03006620[2].unk0
            = gUnk_03006620[3].unk0 = gUnk_03006620[4].unk0 = gUnk_03006920[0].visible
            = gUnk_03006920[1].visible = gUnk_03006920[2].visible = 0;
        gUnk_0300699C = 0;
        gMsgGlyphList2Count = 0;
        sub_080D34F0(gUnk_030068A4);
    }
    gScriptWaitBusy = 0;
}

// sub_0813CE64 @ 0x0813CE64
void sub_0813CE64(void)
{
    u16 n;

    gScriptWaitState = 0;
    n = 0;
    if (Combatant_IsAlive(0) == 1)
        n = 1;
    if (Combatant_IsAlive(1) == 1)
        n++;
    if (Combatant_IsAlive(2) == 1)
        n++;
    if (n == 1)
        gScriptJumpTarget = gUnk_0203DAC8[3];
    else
        gScriptJumpTarget = gUnk_0203DAC8[1];
    gScriptWaitBusy = 0;
}

// sub_0813CED4 @ 0x0813CED4
void sub_0813CED4(void)
{
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

// sub_0813CEE8 @ 0x0813CEE8
void sub_0813CEE8(void)
{
    gScriptWaitState = 0;
    gScriptJumpTarget = gUnk_0203DAC8[1];
    gScriptWaitBusy = 0;
}

// sub_0813CF0C @ 0x0813CF0C
void sub_0813CF0C(void)
{
    gScriptWaitState = 0;
    gScriptJumpTarget = gUnk_0203DAC8[0];
    gScriptWaitBusy = 0;
}

// sub_0813CF30 @ 0x0813CF30
void sub_0813CF30(void)
{
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

// sub_0813CF44 @ 0x0813CF44
void sub_0813CF44(void)
{
    gScriptWaitState = 0;
    gScriptJumpTarget = gUnk_0203DAC8[0];
    gScriptWaitBusy = 0;
}

// sub_0813CF68 @ 0x0813CF68
void sub_0813CF68(void)
{
    gScriptWaitBusy = 1;
}

// sub_0813CF74 @ 0x0813CF74
void sub_0813CF74(void)
{
    gScriptWaitBusy = 1;
}

/* Plays the enemy leader's negotiation reply 0 with field 0x1F of "no demon" (0xFFFF). */
// sub_0813CF80 @ 0x0813CF80
void sub_0813CF80(void)
{
    u16 id = 0xFFFF;
    u8 saved;

    gScriptWaitBusy = 1;
    saved = gUnk_0300685C;
    gUnk_0203DB7E = id;
    gUnk_0300685C = Demon_GetField(id, 0x1F);
    Negotiate_CallReply(0);
    gUnk_0300685C = saved;
    gScriptWaitState = 0;
    gScriptWaitBusy = 1;
}

// sub_0813CFD0 @ 0x0813CFD0
void sub_0813CFD0(void)
{
    gScriptWaitBusy = 1;
}

// sub_0813CFDC @ 0x0813CFDC
void sub_0813CFDC(void)
{
    if (!sub_080CE74C(gUnk_030068E0))
    {
        gScriptWaitBusy = 1;
    }
    else
    {
        gScriptWaitState = 0;
        gScriptWaitBusy = 0;
    }
}

// sub_0813D014 @ 0x0813D014
void sub_0813D014(void)
{
    if (!sub_080CE74C(gUnk_030068E0))
    {
        gScriptWaitBusy = 1;
    }
    else
    {
        gScriptWaitState = 0;
        gScriptWaitBusy = 0;
    }
}

// sub_0813D04C @ 0x0813D04C
void sub_0813D04C(void)
{
    if (!sub_080CE74C(gUnk_03006964))
    {
        gScriptWaitBusy = 1;
    }
    else
    {
        gScriptWaitState = 0;
        gScriptWaitBusy = 0;
    }
}

// sub_0813D084 @ 0x0813D084
void sub_0813D084(void)
{
    if (!sub_080CE74C(gUnk_03006964))
    {
        gScriptWaitBusy = 1;
    }
    else
    {
        gScriptWaitState = 0;
        gScriptWaitBusy = 0;
    }
}

// sub_0813D0BC @ 0x0813D0BC
void sub_0813D0BC(void)
{
    if (!sub_080CE74C(gUnk_03006964))
    {
        gScriptWaitBusy = 1;
    }
    else
    {
        gScriptWaitState = 0;
        gScriptWaitBusy = 0;
    }
}
