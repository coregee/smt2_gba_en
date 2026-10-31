/* Script VM opcode 0x447: the negotiation conditional jump. */

#include "global.h"
#include "scriptops3.h"

extern u16 gUnk_0203DB86;
extern u16 gScriptYield;

struct Task *sub_0812A640(void);
u16 sub_0812A668(u8 kind);
u16 sub_0813BD58(void);
void sub_0813BDA4(void);
u16 Money_Pay(void);
u16 Magnetite_Pay(void);
void sub_0813BE98(void);
void sub_0813BEB8(void);
u16 sub_0813BF58(void);
u16 sub_0813BF78(void);

/* 0x447 test, lo, hi: jumps to the 32-bit target when condition `test` holds, mostly about
   the demon being talked to (gUnk_0203DB7C):
    0 it is not gUnk_0203DB7E
    1 race < 0x1B and its alignment (field 0x0B) is on the other side of 0x70-0x8F from
      the hero's (sub_080C0794(0) bits 8-15)
    2 the stock is full
    3 moon phase (0x0300685C) < 0x90 and sub_0813E804
    4 one of them (battle slots 0x10-0x17) has hp <= maxHp / 4
    5 one of them has status 0x200
    6 the first of party slots 1/2 is not dead/stoned (status 0xA000)
    7, 8 sub_0813BF58 / sub_0813BF78 return 0
    9 random 0-15 + its field 7 >= stat 2 of party slot 1/2 (1 when that one has 0x800)
    0xA opens the yes/no window (target is the "yes" branch, wait state 0x4E)
    0xB party slot 1/2 cannot act, or no wounded one of them passes a 1-in-4 roll
    0xC no item 11..0 is wanted (sub_0813756C), or sub_0813BD58 is non-zero
    0xD asks with sub_0813BECC(1)
    0xE, 0x10 the demon does not want money (1) / an item (2); otherwise the asked
      amount is set in gUnk_0203DB2C (doubled when 0x0300684C & 1)
    0xF, 0x11 the money / Magnetite can be paid (otherwise 0x0300684C |= 0x40)
    0x12 the hero has no item 0xE5 (otherwise one is handed over)
    0x13 the Magnetite does not cover field 0x1B / 2 + 1 (otherwise it is paid)
    0x14 the hero lacks equipment in slot 1 or 6
    0x15 shows status message 0x2D (flag 0xE5 and sub_0812A668(0)) or 0x2E, returning to
      the target */
/* NONMATCHING: the original reuses a few u16 temporaries across the cases (and keeps a
   zero in r7); the register allocation and some branch layout differ. */
// ScriptOp_447 @ 0x0813BF98
#ifdef NONMATCHING
/* The callers saw these as returning int: the narrowing to u16/u8 is done here. */
#define INT_CALL(fn) ((u32 (*)())(fn))
void ScriptOp_447(void)
{
    s32 i = 0;
    u16 test;
    u16 lo;
    u32 target;
    s32 who;
    u16 v;
    u16 c;
    u16 r;

    test = SCRIPT_READ();
    lo = SCRIPT_READ();
    target = SCRIPT_READ();
    target = (target << 16) | lo;
    if (test == 0)
    {
        if (gUnk_0203DB7C == gUnk_0203DB7E)
            return;
        goto jump;
    }
    else if (test == 1)
    {
        u16 k;

        c = INT_CALL(Demon_GetRace)(gUnk_0203DB7C);
        if (c > 0x1A)
            goto jump2;
        {
            u32 f = INT_CALL(Demon_GetField)(gUnk_0203DB7C, 0xB);

            k = 0xFF;
            c = k;
            c &= f;
        }
        if (c > 0x6F)
        {
            if (c <= 0x8F)
                return;
            v = sub_080C0794(0) >> 8;
            v &= k;
            if (v <= 0x6F)
                goto jump2;
            return;
        }
        v = sub_080C0794(0) >> 8;
        v &= k;
        if (v <= 0x8F)
            return;
        goto jump2;
    }
    else if (test == 2)
    {
        s32 cap = Stock_GetCapacity();

        if (gUnk_0203DB86 != 0)
            return;
        for (who = 0; who < cap; who++)
        {
            if (!Combatant_IsUsed(who + 4))
                return;
        }
        goto jump;
    }
    else if (test == 3)
    {
        if (gUnk_0300685C > 0x8F)
            return;
        if ((u16)INT_CALL(sub_0813E804)(gUnk_0203DB7C) == 0)
            return;
        goto jump2;
    }
    else if (test == 4)
    {
        for (i = 0x10; i <= 0x17; i++)
        {
            if (Combatant_IsUsed(i) && Combatant_GetDemonId(i) == gUnk_0203DB7C)
            {
                v = *(s16 *)(Battle_GetCombatant(i - 0x8000) + 0x1A) >> 2;
                if (v >= *(s16 *)(Battle_GetCombatant(i - 0x8000) + 0x18))
                    goto jump;
            }
        }
        return;
    }
    else if (test == 5)
    {
        for (i = 0x10; i <= 0x17; i++)
        {
            if (Combatant_IsUsed(i) && Combatant_GetDemonId(i) == gUnk_0203DB7C
                && ((u16)INT_CALL(Combatant_GetStatus)(i) & 0x200))
                goto jump2;
        }
        return;
    }
    else if (test == 6)
    {
        if (Combatant_IsUsed(1))
        {
            if ((u16)INT_CALL(Combatant_GetStatus)(1) & 0xA000)
                return;
            goto jump;
        }
        if (!Combatant_IsUsed(2))
            goto jump;
        if ((u16)INT_CALL(Combatant_GetStatus)(2) & 0xA000)
            return;
        goto jump2;
    }
    else if (test == 7)
    {
        if ((u16)INT_CALL(sub_0813BF58)())
            return;
        goto jump2;
    }
    else if (test == 8)
    {
        if ((u16)INT_CALL(sub_0813BF78)())
            return;
        goto jump;
    }
    else if (test == 9)
    {
        if (Combatant_IsUsed(1))
            who = 1;
        else if (Combatant_IsUsed(2))
            who = 2;
        else
            return;
        if ((u16)INT_CALL(Combatant_GetStatus)(who) & 0x800)
            who = 1;
        else
        {
            who = Combatant_GetStat(who, 2);
            who &= 0xFF;
        }
        v = Random_Byte();
        v &= 0xF;
        v += Demon_GetField(gUnk_0203DB7C, 7) & 0xFF;
        if (v < (u32)who)
            return;
        goto jump2;
    }
    else if (test == 10)
    {
        gUnk_030068E0 = (u32)sub_0812A640();
        gUnk_0203DAC8[0] = (u16 *)target;
        gScriptWaitState = 0x4E;
        goto waitYesNo;
    }
    else if (test == 11)
    {
        if (Combatant_IsUsed(1))
            c = 1;
        else if (Combatant_IsUsed(2))
            c = 2;
        else
            goto jump;
        if (INT_CALL(Combatant_GetStatus)(c) & 0xC000)
            goto jump;
        for (c = 0x10; c <= 0x17; c++)
        {
            if (Combatant_IsUsed(c))
            {
                u16 id = gUnk_0203DB7C;

                if (id == Combatant_GetDemonId(c))
                {
                    u16 b = c + 0x8000;

                    v = *(s16 *)(Battle_GetCombatant(b) + 0x1A) / 4;
                    if (v >= *(s16 *)(Battle_GetCombatant(b) + 0x18))
                    {
                        r = Random_Byte() & 3;
                        goto test_r;
                    }
                }
            }
        }
        goto jump;
    }
    else if (test == 12)
    {
        s16 k;

        for (k = 11; k >= 0; k--)
        {
            if ((u8)INT_CALL(sub_0813756C)(k))
            {
                r = INT_CALL(sub_0813BD58)();
                goto test_r;
            }
        }
        goto jump;
    test_r:
        if (r == 0)
            return;
        goto jump;
    }
    else if (test == 13)
    {
        gUnk_0203DAC8[0] = (u16 *)target;
        sub_0813BECC(1);
    waitYesNo:
        gScriptYield = 1;
        return;
    }
    else if (test == 14)
    {
        r = INT_CALL(sub_0813BD58)();
        i = r;
        if (i != 1)
            goto jump;
        sub_0813BDA4();
        c = ((u16)sub_0813BDCC() << 4) / gUnk_03006690;
        c += gUnk_03006690 >> 2;
        if (gUnk_0300684C & i)
            c <<= 1;
        gUnk_0203DB2C = c;
        return;
    }
    else if (test == 15)
    {
        if ((u16)INT_CALL(Money_Pay)() == 0)
            goto cannotPay;
        goto jump2;
    }
    else if (test == 16)
    {
        if ((u16)INT_CALL(sub_0813BD58)() != 2)
            goto jump;
        sub_0813BDA4();
        c = ((u16)sub_08137BB8() << 4) / gUnk_03006690;
        c += gUnk_03006690 >> 2;
        if (gUnk_0300684C & 1)
            c <<= 1;
        gUnk_0203DB2C = c;
        return;
    }
    else if (test == 17)
    {
        if ((u16)INT_CALL(Magnetite_Pay)())
            goto jump2;
    cannotPay:
        gUnk_0300684C |= 0x40;
        sub_0813BE98();
        return;
    }
    else if (test == 18)
    {
        gScriptItemCheckId = 0xE5;
        if (!(u8)INT_CALL(Inventory_GetCount)(0xE5))
            goto jump;
        Inventory_RemoveItem(gScriptItemCheckId);
        sub_0813BEB8();
        return;
    }
    else if (test == 19)
    {
        i = ((u16)(INT_CALL(Demon_GetField)(gUnk_0203DB7C, 0x1B) & 0xFF) >> 1) + 1;
        if (Magnetite_Get() < (u32)i)
            goto jump2;
        Magnetite_Add(-i);
        return;
    }
    else if (test == 20)
        goto equip;
    else if (test == 21)
    {
        gUnk_03006840 = target;
        if (Flag_Test(0xE5) && (u16)INT_CALL(sub_0812A668)(0))
        {
            Script_JumpToStatusMessage(0x2D);
            return;
        }
        goto noFlag;
    }
    return;
equip:
    if ((u16)Combatant_GetEquip(0, 1) == 0xFF)
        goto jump;
    if ((u16)Combatant_GetEquip(0, 6) != 0xFF)
        return;
jump:
    gScriptJumpTarget = (u16 *)target;
    return;
jump2:
    gScriptJumpTarget = (u16 *)target;
    return;
noFlag:
    Script_JumpToStatusMessage(0x2E);
}
#else
NAKED
void ScriptOp_447(void)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    movs r7, #0\n"
        "    ldr r3, .L0813BFE8\n"
        "    ldrh r0, [r3]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r3]\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r2, .L0813BFEC\n"
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
        "    ldrh r0, [r0]\n"
        "    mov r8, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    orrs r0, r4\n"
        "    mov r8, r0\n"
        "    cmp r5, #0\n"
        "    bne .L0813BFF8\n"
        "    ldr r0, .L0813BFF0\n"
        "    ldr r1, .L0813BFF4\n"
        "    ldrh r0, [r0]\n"
        "    ldrh r1, [r1]\n"
        "    cmp r0, r1\n"
        "    bne .L0813BFE6\n"
        "    b .L0813C4DE\n"
        ".L0813BFE6:\n"
        "    b .L0813C4C0\n"
        ".L0813BFE8: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L0813BFEC: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L0813BFF0: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813BFF4: .4byte 0x0203DB7E @ EWRAM+0x3DB7E\n"
        ".L0813BFF8:\n"
        "    cmp r5, #1\n"
        "    bne .L0813C054\n"
        "    ldr r4, .L0813C03C\n"
        "    ldrh r0, [r4]\n"
        "    bl Demon_GetRace\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r6, #0x1a\n"
        "    bls .L0813C00E\n"
        "    b .L0813C4CC\n"
        ".L0813C00E:\n"
        "    ldrh r0, [r4]\n"
        "    movs r1, #0xb\n"
        "    bl Demon_GetField\n"
        "    movs r4, #0xff\n"
        "    adds r6, r4, #0\n"
        "    ands r6, r0\n"
        "    cmp r6, #0x6f\n"
        "    bls .L0813C040\n"
        "    cmp r6, #0x8f\n"
        "    bhi .L0813C026\n"
        "    b .L0813C4DE\n"
        ".L0813C026:\n"
        "    movs r0, #0\n"
        "    bl sub_080C0794\n"
        "    lsls r0, r0, #8\n"
        "    lsrs r5, r0, #0x10\n"
        "    ands r5, r4\n"
        "    cmp r5, #0x6f\n"
        "    bhi .L0813C038\n"
        "    b .L0813C4CC\n"
        ".L0813C038:\n"
        "    b .L0813C4DE\n"
        "    .byte 0x00, 0x00\n"
        ".L0813C03C: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813C040:\n"
        "    movs r0, #0\n"
        "    bl sub_080C0794\n"
        "    lsls r0, r0, #8\n"
        "    lsrs r5, r0, #0x10\n"
        "    ands r5, r4\n"
        "    cmp r5, #0x8f\n"
        "    bhi .L0813C052\n"
        "    b .L0813C4DE\n"
        ".L0813C052:\n"
        "    b .L0813C4CC\n"
        ".L0813C054:\n"
        "    cmp r5, #2\n"
        "    bne .L0813C088\n"
        "    bl Stock_GetCapacity\n"
        "    adds r4, r0, #0\n"
        "    ldr r0, .L0813C084\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    beq .L0813C068\n"
        "    b .L0813C4DE\n"
        ".L0813C068:\n"
        "    movs r6, #0\n"
        "    cmp r7, r4\n"
        "    blt .L0813C070\n"
        "    b .L0813C4C0\n"
        ".L0813C070:\n"
        "    adds r0, r6, #4\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    bne .L0813C07C\n"
        "    b .L0813C4DE\n"
        ".L0813C07C:\n"
        "    adds r6, #1\n"
        "    cmp r6, r4\n"
        "    blt .L0813C070\n"
        "    b .L0813C4C0\n"
        ".L0813C084: .4byte 0x0203DB86 @ EWRAM+0x3DB86\n"
        ".L0813C088:\n"
        "    cmp r5, #3\n"
        "    bne .L0813C0B0\n"
        "    ldr r0, .L0813C0A8\n"
        "    ldrb r5, [r0]\n"
        "    cmp r5, #0x8f\n"
        "    bls .L0813C096\n"
        "    b .L0813C4DE\n"
        ".L0813C096:\n"
        "    ldr r0, .L0813C0AC\n"
        "    ldrh r0, [r0]\n"
        "    bl sub_0813E804\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L0813C0A6\n"
        "    b .L0813C4DE\n"
        ".L0813C0A6:\n"
        "    b .L0813C4CC\n"
        ".L0813C0A8: .4byte 0x0300685C @ IWRAM+0x685C\n"
        ".L0813C0AC: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813C0B0:\n"
        "    cmp r5, #4\n"
        "    bne .L0813C10C\n"
        "    movs r6, #0x10\n"
        ".L0813C0B6:\n"
        "    adds r0, r6, #0\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L0813C0FA\n"
        "    adds r0, r6, #0\n"
        "    bl Combatant_GetDemonId\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    ldr r1, .L0813C104\n"
        "    ldrh r1, [r1]\n"
        "    cmp r0, r1\n"
        "    bne .L0813C0FA\n"
        "    ldr r0, .L0813C108\n"
        "    adds r4, r6, r0\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    ldrh r0, [r0, #0x1a]\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x12\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    movs r1, #0x18\n"
        "    ldrsh r0, [r0, r1]\n"
        "    cmp r5, r0\n"
        "    blt .L0813C0FA\n"
        "    b .L0813C4C0\n"
        ".L0813C0FA:\n"
        "    adds r6, #1\n"
        "    cmp r6, #0x17\n"
        "    ble .L0813C0B6\n"
        "    b .L0813C4DE\n"
        "    .byte 0x00, 0x00\n"
        ".L0813C104: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813C108: .4byte 0xFFFF8000\n"
        ".L0813C10C:\n"
        "    cmp r5, #5\n"
        "    bne .L0813C154\n"
        "    movs r6, #0x10\n"
        ".L0813C112:\n"
        "    adds r0, r6, #0\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L0813C146\n"
        "    adds r0, r6, #0\n"
        "    bl Combatant_GetDemonId\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    ldr r1, .L0813C150\n"
        "    ldrh r1, [r1]\n"
        "    cmp r0, r1\n"
        "    bne .L0813C146\n"
        "    adds r0, r6, #0\n"
        "    bl Combatant_GetStatus\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #2\n"
        "    adds r0, r2, #0\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L0813C146\n"
        "    b .L0813C4CC\n"
        ".L0813C146:\n"
        "    adds r6, #1\n"
        "    cmp r6, #0x17\n"
        "    ble .L0813C112\n"
        "    b .L0813C4DE\n"
        "    .byte 0x00, 0x00\n"
        ".L0813C150: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813C154:\n"
        "    cmp r5, #6\n"
        "    bne .L0813C19A\n"
        "    movs r0, #1\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L0813C178\n"
        "    movs r0, #1\n"
        "    bl Combatant_GetStatus\n"
        "    lsls r0, r0, #0x10\n"
        "    movs r1, #0xa0\n"
        "    lsls r1, r1, #0x18\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L0813C176\n"
        "    b .L0813C4DE\n"
        ".L0813C176:\n"
        "    b .L0813C4C0\n"
        ".L0813C178:\n"
        "    movs r0, #2\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    bne .L0813C184\n"
        "    b .L0813C4C0\n"
        ".L0813C184:\n"
        "    movs r0, #2\n"
        "    bl Combatant_GetStatus\n"
        "    lsls r0, r0, #0x10\n"
        "    movs r1, #0xa0\n"
        "    lsls r1, r1, #0x18\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L0813C198\n"
        "    b .L0813C4DE\n"
        ".L0813C198:\n"
        "    b .L0813C4CC\n"
        ".L0813C19A:\n"
        "    cmp r5, #7\n"
        "    bne .L0813C1AC\n"
        "    bl sub_0813BF58\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L0813C1AA\n"
        "    b .L0813C4DE\n"
        ".L0813C1AA:\n"
        "    b .L0813C4CC\n"
        ".L0813C1AC:\n"
        "    cmp r5, #8\n"
        "    bne .L0813C1BE\n"
        "    bl sub_0813BF78\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L0813C1BC\n"
        "    b .L0813C4DE\n"
        ".L0813C1BC:\n"
        "    b .L0813C4C0\n"
        ".L0813C1BE:\n"
        "    cmp r5, #9\n"
        "    bne .L0813C22C\n"
        "    movs r0, #1\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L0813C1D0\n"
        "    movs r6, #1\n"
        "    b .L0813C1DE\n"
        ".L0813C1D0:\n"
        "    movs r0, #2\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    bne .L0813C1DC\n"
        "    b .L0813C4DE\n"
        ".L0813C1DC:\n"
        "    movs r6, #2\n"
        ".L0813C1DE:\n"
        "    adds r0, r6, #0\n"
        "    bl Combatant_GetStatus\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #4\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L0813C1F6\n"
        "    movs r6, #1\n"
        "    b .L0813C204\n"
        ".L0813C1F6:\n"
        "    adds r0, r6, #0\n"
        "    movs r1, #2\n"
        "    bl Combatant_GetStat\n"
        "    adds r6, r0, #0\n"
        "    movs r0, #0xff\n"
        "    ands r6, r0\n"
        ".L0813C204:\n"
        "    bl Random_Byte\n"
        "    adds r5, r0, #0\n"
        "    movs r0, #0xf\n"
        "    ands r5, r0\n"
        "    ldr r0, .L0813C228\n"
        "    ldrh r0, [r0]\n"
        "    movs r1, #7\n"
        "    bl Demon_GetField\n"
        "    movs r1, #0xff\n"
        "    ands r1, r0\n"
        "    adds r5, r5, r1\n"
        "    cmp r5, r6\n"
        "    bhs .L0813C224\n"
        "    b .L0813C4DE\n"
        ".L0813C224:\n"
        "    b .L0813C4CC\n"
        "    .byte 0x00, 0x00\n"
        ".L0813C228: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813C22C:\n"
        "    cmp r5, #0xa\n"
        "    bne .L0813C254\n"
        "    bl sub_0812A640\n"
        "    ldr r1, .L0813C248\n"
        "    str r0, [r1]\n"
        "    ldr r0, .L0813C24C\n"
        "    mov r1, r8\n"
        "    str r1, [r0]\n"
        "    ldr r1, .L0813C250\n"
        "    movs r0, #0x4e\n"
        "    strh r0, [r1]\n"
        "    b .L0813C32E\n"
        "    .byte 0x00, 0x00\n"
        ".L0813C248: .4byte 0x030068E0 @ IWRAM+0x68E0\n"
        ".L0813C24C: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8\n"
        ".L0813C250: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L0813C254:\n"
        "    cmp r5, #0xb\n"
        "    bne .L0813C2EA\n"
        "    movs r0, #1\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L0813C266\n"
        "    movs r6, #1\n"
        "    b .L0813C274\n"
        ".L0813C266:\n"
        "    movs r0, #2\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    bne .L0813C272\n"
        "    b .L0813C4C0\n"
        ".L0813C272:\n"
        "    movs r6, #2\n"
        ".L0813C274:\n"
        "    adds r0, r6, #0\n"
        "    bl Combatant_GetStatus\n"
        "    movs r1, #0xc0\n"
        "    lsls r1, r1, #8\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L0813C286\n"
        "    b .L0813C4C0\n"
        ".L0813C286:\n"
        "    movs r6, #0x10\n"
        ".L0813C288:\n"
        "    adds r0, r6, #0\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L0813C2D0\n"
        "    ldr r0, .L0813C2DC\n"
        "    ldrh r4, [r0]\n"
        "    adds r0, r6, #0\n"
        "    bl Combatant_GetDemonId\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r4, r0\n"
        "    bne .L0813C2D0\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #8\n"
        "    adds r0, r6, r2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    movs r1, #0x1a\n"
        "    ldrsh r0, [r0, r1]\n"
        "    cmp r0, #0\n"
        "    bge .L0813C2BE\n"
        "    adds r0, #3\n"
        ".L0813C2BE:\n"
        "    lsls r0, r0, #0xe\n"
        "    lsrs r5, r0, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    movs r2, #0x18\n"
        "    ldrsh r0, [r0, r2]\n"
        "    cmp r5, r0\n"
        "    bge .L0813C2E0\n"
        ".L0813C2D0:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r6, #0x17\n"
        "    bls .L0813C288\n"
        "    b .L0813C4C0\n"
        ".L0813C2DC: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813C2E0:\n"
        "    bl Random_Byte\n"
        "    movs r1, #3\n"
        "    ands r0, r1\n"
        "    b .L0813C316\n"
        ".L0813C2EA:\n"
        "    cmp r5, #0xc\n"
        "    bne .L0813C31E\n"
        "    movs r1, #0xb\n"
        ".L0813C2F0:\n"
        "    lsls r4, r1, #0x10\n"
        "    lsrs r0, r4, #0x10\n"
        "    bl sub_0813756C\n"
        "    lsls r0, r0, #0x18\n"
        "    cmp r0, #0\n"
        "    bne .L0813C310\n"
        "    ldr r2, .L0813C30C\n"
        "    adds r0, r4, r2\n"
        "    lsrs r1, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L0813C2F0\n"
        "    b .L0813C4C0\n"
        "    .byte 0x00, 0x00\n"
        ".L0813C30C: .4byte 0xFFFF0000\n"
        ".L0813C310:\n"
        "    bl sub_0813BD58\n"
        "    lsls r0, r0, #0x10\n"
        ".L0813C316:\n"
        "    cmp r0, #0\n"
        "    bne .L0813C31C\n"
        "    b .L0813C4DE\n"
        ".L0813C31C:\n"
        "    b .L0813C4C0\n"
        ".L0813C31E:\n"
        "    cmp r5, #0xd\n"
        "    bne .L0813C340\n"
        "    ldr r0, .L0813C338\n"
        "    mov r2, r8\n"
        "    str r2, [r0]\n"
        "    movs r0, #1\n"
        "    bl sub_0813BECC\n"
        ".L0813C32E:\n"
        "    ldr r1, .L0813C33C\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    b .L0813C4DE\n"
        "    .byte 0x00, 0x00\n"
        ".L0813C338: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8\n"
        ".L0813C33C: .4byte 0x0203DB6E @ EWRAM+0x3DB6E\n"
        ".L0813C340:\n"
        "    cmp r5, #0xe\n"
        "    bne .L0813C38C\n"
        "    bl sub_0813BD58\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    adds r7, r5, #0\n"
        "    cmp r7, #1\n"
        "    beq .L0813C354\n"
        "    b .L0813C4C0\n"
        ".L0813C354:\n"
        "    bl sub_0813BDA4\n"
        "    bl sub_0813BDCC\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0xc\n"
        "    ldr r1, .L0813C384\n"
        "    ldrh r4, [r1]\n"
        "    adds r1, r4, #0\n"
        "    bl __divsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    lsrs r5, r4, #2\n"
        "    adds r0, r6, r5\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldr r0, .L0813C388\n"
        "    ldrb r0, [r0]\n"
        "    ands r7, r0\n"
        "    cmp r7, #0\n"
        "    beq .L0813C3E0\n"
        "    b .L0813C3DC\n"
        "    .byte 0x00, 0x00\n"
        ".L0813C384: .4byte 0x03006690 @ IWRAM+0x6690\n"
        ".L0813C388: .4byte 0x0300684C @ IWRAM+0x684C\n"
        ".L0813C38C:\n"
        "    cmp r5, #0xf\n"
        "    bne .L0813C39C\n"
        "    bl Money_Pay\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L0813C402\n"
        "    b .L0813C4CC\n"
        ".L0813C39C:\n"
        "    cmp r5, #0x10\n"
        "    bne .L0813C3F4\n"
        "    bl sub_0813BD58\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #2\n"
        "    beq .L0813C3AE\n"
        "    b .L0813C4C0\n"
        ".L0813C3AE:\n"
        "    bl sub_0813BDA4\n"
        "    bl sub_08137BB8\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0xc\n"
        "    ldr r1, .L0813C3E8\n"
        "    ldrh r4, [r1]\n"
        "    adds r1, r4, #0\n"
        "    bl __divsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    lsrs r5, r4, #2\n"
        "    adds r0, r6, r5\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldr r0, .L0813C3EC\n"
        "    ldrb r1, [r0]\n"
        "    movs r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L0813C3E0\n"
        ".L0813C3DC:\n"
        "    lsls r0, r6, #0x11\n"
        "    lsrs r6, r0, #0x10\n"
        ".L0813C3E0:\n"
        "    ldr r0, .L0813C3F0\n"
        "    str r6, [r0]\n"
        "    b .L0813C4DE\n"
        "    .byte 0x00, 0x00\n"
        ".L0813C3E8: .4byte 0x03006690 @ IWRAM+0x6690\n"
        ".L0813C3EC: .4byte 0x0300684C @ IWRAM+0x684C\n"
        ".L0813C3F0: .4byte 0x0203DB2C @ EWRAM+0x3DB2C\n"
        ".L0813C3F4:\n"
        "    cmp r5, #0x11\n"
        "    bne .L0813C418\n"
        "    bl Magnetite_Pay\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L0813C4CC\n"
        ".L0813C402:\n"
        "    ldr r0, .L0813C414\n"
        "    ldrb r1, [r0]\n"
        "    movs r2, #0x40\n"
        "    orrs r1, r2\n"
        "    strb r1, [r0]\n"
        "    bl sub_0813BE98\n"
        "    b .L0813C4DE\n"
        "    .byte 0x00, 0x00\n"
        ".L0813C414: .4byte 0x0300684C @ IWRAM+0x684C\n"
        ".L0813C418:\n"
        "    cmp r5, #0x12\n"
        "    bne .L0813C440\n"
        "    ldr r4, .L0813C43C\n"
        "    movs r0, #0xe5\n"
        "    strh r0, [r4]\n"
        "    movs r0, #0xe5\n"
        "    bl Inventory_GetCount\n"
        "    lsls r0, r0, #0x18\n"
        "    cmp r0, #0\n"
        "    beq .L0813C4C0\n"
        "    ldrh r0, [r4]\n"
        "    bl Inventory_RemoveItem\n"
        "    bl sub_0813BEB8\n"
        "    b .L0813C4DE\n"
        "    .byte 0x00, 0x00\n"
        ".L0813C43C: .4byte 0x0203DB50 @ EWRAM+0x3DB50\n"
        ".L0813C440:\n"
        "    cmp r5, #0x13\n"
        "    bne .L0813C470\n"
        "    ldr r0, .L0813C46C\n"
        "    ldrh r0, [r0]\n"
        "    movs r1, #0x1b\n"
        "    bl Demon_GetField\n"
        "    lsls r0, r0, #0x10\n"
        "    movs r1, #0xff\n"
        "    lsls r1, r1, #0x10\n"
        "    ands r1, r0\n"
        "    lsrs r7, r1, #0x11\n"
        "    adds r7, #1\n"
        "    bl Magnetite_Get\n"
        "    cmp r0, r7\n"
        "    blo .L0813C4CC\n"
        "    rsbs r0, r7, #0\n"
        "    bl Magnetite_Add\n"
        "    b .L0813C4DE\n"
        "    .byte 0x00, 0x00\n"
        ".L0813C46C: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813C470:\n"
        "    cmp r5, #0x14\n"
        "    beq .L0813C4A0\n"
        "    cmp r5, #0x15\n"
        "    bne .L0813C4DE\n"
        "    ldr r0, .L0813C49C\n"
        "    mov r2, r8\n"
        "    str r2, [r0]\n"
        "    movs r0, #0xe5\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    beq .L0813C4D8\n"
        "    movs r0, #0\n"
        "    bl sub_0812A668\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L0813C4D8\n"
        "    movs r0, #0x2d\n"
        "    bl Script_JumpToStatusMessage\n"
        "    b .L0813C4DE\n"
        ".L0813C49C: .4byte 0x03006840 @ IWRAM+0x6840\n"
        ".L0813C4A0:\n"
        "    movs r0, #0\n"
        "    movs r1, #1\n"
        "    bl Combatant_GetEquip\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #0xff\n"
        "    beq .L0813C4C0\n"
        "    movs r0, #0\n"
        "    movs r1, #6\n"
        "    bl Combatant_GetEquip\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #0xff\n"
        "    bne .L0813C4DE\n"
        ".L0813C4C0:\n"
        "    ldr r0, .L0813C4C8\n"
        "    mov r1, r8\n"
        "    str r1, [r0]\n"
        "    b .L0813C4DE\n"
        ".L0813C4C8: .4byte 0x030068E4 @ IWRAM+0x68E4\n"
        ".L0813C4CC:\n"
        "    ldr r0, .L0813C4D4\n"
        "    mov r2, r8\n"
        "    str r2, [r0]\n"
        "    b .L0813C4DE\n"
        ".L0813C4D4: .4byte 0x030068E4 @ IWRAM+0x68E4\n"
        ".L0813C4D8:\n"
        "    movs r0, #0x2e\n"
        "    bl Script_JumpToStatusMessage\n"
        ".L0813C4DE:\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif
