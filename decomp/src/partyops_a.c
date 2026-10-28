/* Script VM opcode handlers 0x36F-0x389. */

#include "global.h"
#include "scriptops3.h"

#define RESTORE_HP(who)                                         \
    if (Combatant_IsUsed(who) && !Combatant_IsDead(who))        \
        Combatant_RestoreHp(who);

#define RESTORE_MP(who)                                         \
    if (Combatant_IsUsed(who) && !Combatant_IsDead(who))        \
        Combatant_RestoreMp(who);

#define EQUIP_IS_CURSED(who, slot)                                  \
    (e = Combatant_GetEquip(who, slot), e != 0xFF && e != -1       \
     && (Item_GetAttribute(e, 6, &attr), attr & 1))

// ScriptOp_36F @ 0x08135AA8
void ScriptOp_36F(void)
{
    s32 cap = Stock_GetCapacity();
    u16 lo;
    u32 target1, target2;
    u16 count;
    u16 who;

    lo = SCRIPT_READ();
    target1 = SCRIPT_READ();
    target1 = target1 << 16 | lo;
    lo = SCRIPT_READ();
    target2 = SCRIPT_READ();
    target2 = target2 << 16 | lo;
    count = 0;
    for (who = 4; who < cap + 4; who++)
    {
        if (Combatant_IsUsed(who) && !(Combatant_GetStatus(who) & 0xB160))
            count++;
    }
    if (gUnk_030068A8 == 1)
    {
        if (sub_08135A94(3) < 2)
            gScriptJumpTarget = (u16 *)target2;
    }
    else if (gUnk_030068A8 == 4)
    {
        if (count == 0)
            gScriptJumpTarget = (u16 *)target1;
        else if (sub_08135A94(2) == 0)
            gScriptJumpTarget = (u16 *)target2;
    }
    else if (gUnk_030068A8 == 5)
    {
        if (count == 0)
            gScriptJumpTarget = (u16 *)target1;
        else if (sub_08135A94(4) < 2)
            gScriptJumpTarget = (u16 *)target2;
    }
    else if (count < gUnk_030068A8)
    {
        gScriptJumpTarget = (u16 *)target1;
    }
}

// ScriptOp_372 @ 0x08135BA0
void ScriptOp_372(void)
{
    u16 op = SCRIPT_READ();
    s32 unit, price;
    u16 id;

    gScriptPc++;
    if (op == 0)
    {
        gScriptWaitState = 0x14;
        gUnk_03006954 = sub_080B7E0C(1);
        gScriptYield = 1;
    }
    else if (op == 1)
    {
        gScriptWaitState = 0x14;
        gUnk_03006954 = sub_080B7E0C(0);
        gScriptYield = op;
    }
    else if (op == 9)
    {
        sub_080B08AC();
        gScriptWaitState = 0x44;
        gScriptYield = 1;
    }
    else if (op == 10)
    {
        sub_080B0888();
        gScriptWaitState = 0x45;
        gScriptYield = 1;
    }
    else if (op == 11)
    {
        gUnk_03006954 = sub_080B9510();
        gScriptWaitState = 0x46;
        gScriptYield = 1;
    }
    else if (op == 12)
    {
        gUnk_030068A4 = sub_080D3400(2, (u16)gUnk_03006898, gShopItemIds[gUnk_0300696C + gUnk_03006940]);
        gScriptWaitState = 0;
        gScriptYield = 1;
    }
    else if (op == 13)
    {
        if (gUnk_030068A4 == 0)
        {
            gUnk_030068A4 = sub_080D3400(0, 0, 0);
            gScriptWaitState = 0;
            gScriptYield = 1;
        }
    }
    else if (op == 14)
    {
        if (gUnk_030068A4 != 0)
        {
            sub_080D34F0(gUnk_030068A4);
            gUnk_030068A4 = 0;
        }
        gScriptWaitState = 0;
        gScriptYield = 1;
    }
    else if (op == 15)
    {
        unit = price = sub_080C4C7C(gScriptItemCheckId);
        price *= Inventory_GetCount(gScriptItemCheckId);
        price += unit;
        while (Inventory_GetCount(gScriptItemCheckId))
            Inventory_RemoveItem(gScriptItemCheckId);
        id = sub_080D2268(gScriptItemCheckId);
        sub_080CDFF8(gUnk_03006898, id);
        Money_Add(price);
    }
    else if (op == 16)
    {
        unit = price = sub_080C4C7C(gScriptItemCheckId);
        price *= Inventory_GetCount(gScriptItemCheckId);
        price += unit;
        price += unit;
        while (Inventory_GetCount(gScriptItemCheckId))
            Inventory_RemoveItem(gScriptItemCheckId);
        id = sub_080D2268(gScriptItemCheckId);
        sub_080CDFF8(gUnk_03006898, id);
        sub_080CDFF8(gUnk_03006940, id);
        Money_Add(price);
    }
    else if (op == 17)
    {
        gUnk_0300699C = 0;
    }
    else if (op == 18)
    {
        gUnk_03006958 = 0;
        gUnk_0300699C = 0;
        gUnk_03006678[0] = 0;
    }
}

// ScriptOp_373 @ 0x08135E10
void ScriptOp_373(void)
{
}

// ScriptOp_374 @ 0x08135E14
#ifdef NONMATCHING
void ScriptOp_374(void)
{
    s32 cap = Stock_GetCapacity();
    u16 op = SCRIPT_READ();
    u16 who;

    if (op == 0)
    {
        RESTORE_HP(0)
    }
    else if (op == 1)
    {
        goto members12;
    }
    else if (op == 2)
    {
        RESTORE_HP(0)
    members12:
        RESTORE_HP(1)
        RESTORE_HP(2)
    }
    else
    {
        for (who = 0; who < cap + 4; who++)
        {
            RESTORE_HP(who)
        }
    }
    sub_080C84A0();
}
#else
NAKED
void ScriptOp_374(void)
{
    asm_unified(
        "    push {r4, r5, lr}\n"
        "    bl Stock_GetCapacity\n"
        "    adds r3, r0, #0\n"
        "    ldr r2, .L08135E54\n"
        "    ldrh r0, [r2]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r2]\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r1, .L08135E58\n"
        "    ldr r1, [r1]\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    adds r1, r0, #0\n"
        "    cmp r0, #0\n"
        "    bne .L08135E5C\n"
        "    movs r0, #0\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L08135EE0\n"
        "    movs r0, #0\n"
        "    bl Combatant_IsDead\n"
        "    cmp r0, #0\n"
        "    bne .L08135EE0\n"
        "    movs r0, #0\n"
        "    bl Combatant_RestoreHp\n"
        "    b .L08135EE0\n"
        "    .byte 0x00, 0x00\n"
        ".L08135E54: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L08135E58: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L08135E5C:\n"
        "    cmp r0, #1\n"
        "    beq .L08135E7E\n"
        "    cmp r1, #2\n"
        "    bne .L08135EB4\n"
        "    movs r0, #0\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L08135E7E\n"
        "    movs r0, #0\n"
        "    bl Combatant_IsDead\n"
        "    cmp r0, #0\n"
        "    bne .L08135E7E\n"
        "    movs r0, #0\n"
        "    bl Combatant_RestoreHp\n"
        ".L08135E7E:\n"
        "    movs r0, #1\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L08135E98\n"
        "    movs r0, #1\n"
        "    bl Combatant_IsDead\n"
        "    cmp r0, #0\n"
        "    bne .L08135E98\n"
        "    movs r0, #1\n"
        "    bl Combatant_RestoreHp\n"
        ".L08135E98:\n"
        "    movs r0, #2\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L08135EE0\n"
        "    movs r0, #2\n"
        "    bl Combatant_IsDead\n"
        "    cmp r0, #0\n"
        "    bne .L08135EE0\n"
        "    movs r0, #2\n"
        "    bl Combatant_RestoreHp\n"
        "    b .L08135EE0\n"
        ".L08135EB4:\n"
        "    movs r4, #0\n"
        "    adds r5, r3, #4\n"
        "    cmp r4, r5\n"
        "    bge .L08135EE0\n"
        ".L08135EBC:\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L08135ED6\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_IsDead\n"
        "    cmp r0, #0\n"
        "    bne .L08135ED6\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_RestoreHp\n"
        ".L08135ED6:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, r5\n"
        "    blt .L08135EBC\n"
        ".L08135EE0:\n"
        "    bl sub_080C84A0\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// ScriptOp_375 @ 0x08135EEC
#ifdef NONMATCHING
void ScriptOp_375(void)
{
    s32 cap = Stock_GetCapacity();
    u16 op = SCRIPT_READ();
    u16 who;

    if (op == 0)
    {
        RESTORE_MP(0)
    }
    else if (op == 1)
    {
        goto members12;
    }
    else if (op == 2)
    {
        RESTORE_MP(0)
    members12:
        RESTORE_MP(1)
        RESTORE_MP(2)
    }
    else
    {
        for (who = 0; who < cap + 4; who++)
        {
            RESTORE_MP(who)
        }
    }
    sub_080C84A0();
}
#else
NAKED
void ScriptOp_375(void)
{
    asm_unified(
        "    push {r4, r5, lr}\n"
        "    bl Stock_GetCapacity\n"
        "    adds r3, r0, #0\n"
        "    ldr r2, .L08135F2C\n"
        "    ldrh r0, [r2]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r2]\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r1, .L08135F30\n"
        "    ldr r1, [r1]\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    adds r1, r0, #0\n"
        "    cmp r0, #0\n"
        "    bne .L08135F34\n"
        "    movs r0, #0\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L08135FB8\n"
        "    movs r0, #0\n"
        "    bl Combatant_IsDead\n"
        "    cmp r0, #0\n"
        "    bne .L08135FB8\n"
        "    movs r0, #0\n"
        "    bl Combatant_RestoreMp\n"
        "    b .L08135FB8\n"
        "    .byte 0x00, 0x00\n"
        ".L08135F2C: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L08135F30: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L08135F34:\n"
        "    cmp r0, #1\n"
        "    beq .L08135F56\n"
        "    cmp r1, #2\n"
        "    bne .L08135F8C\n"
        "    movs r0, #0\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L08135F56\n"
        "    movs r0, #0\n"
        "    bl Combatant_IsDead\n"
        "    cmp r0, #0\n"
        "    bne .L08135F56\n"
        "    movs r0, #0\n"
        "    bl Combatant_RestoreMp\n"
        ".L08135F56:\n"
        "    movs r0, #1\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L08135F70\n"
        "    movs r0, #1\n"
        "    bl Combatant_IsDead\n"
        "    cmp r0, #0\n"
        "    bne .L08135F70\n"
        "    movs r0, #1\n"
        "    bl Combatant_RestoreMp\n"
        ".L08135F70:\n"
        "    movs r0, #2\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L08135FB8\n"
        "    movs r0, #2\n"
        "    bl Combatant_IsDead\n"
        "    cmp r0, #0\n"
        "    bne .L08135FB8\n"
        "    movs r0, #2\n"
        "    bl Combatant_RestoreMp\n"
        "    b .L08135FB8\n"
        ".L08135F8C:\n"
        "    movs r4, #0\n"
        "    adds r5, r3, #4\n"
        "    cmp r4, r5\n"
        "    bge .L08135FB8\n"
        ".L08135F94:\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L08135FAE\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_IsDead\n"
        "    cmp r0, #0\n"
        "    bne .L08135FAE\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_RestoreMp\n"
        ".L08135FAE:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, r5\n"
        "    blt .L08135F94\n"
        ".L08135FB8:\n"
        "    bl sub_080C84A0\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

/* TRUE when any of the six equipment slots holds an item with attribute bit 0 set
   (cursed?). */
// sub_08135FC4 @ 0x08135FC4
bool32 sub_08135FC4(s32 who)
{
    u32 e;
    s32 attr;

    if (EQUIP_IS_CURSED(who, 0) || EQUIP_IS_CURSED(who, 1) || EQUIP_IS_CURSED(who, 2)
     || EQUIP_IS_CURSED(who, 3) || EQUIP_IS_CURSED(who, 4) || EQUIP_IS_CURSED(who, 5))
        return TRUE;
    return FALSE;
}

// sub_081360D4 @ 0x081360D4
void sub_081360D4(s32 who)
{
    u32 e;
    s32 attr;

    if (EQUIP_IS_CURSED(who, 0))
        sub_080CDFF8(who, 0);
}

// sub_08136114 @ 0x08136114
void sub_08136114(void)
{
    u32 e;
    s32 attr;

    if (EQUIP_IS_CURSED(1, 0))
    {
        sub_080CDFF8(1, 0);
        Inventory_AddItem(e);
    }
}

// ScriptOp_376 @ 0x0813615C
#ifdef NONMATCHING
void ScriptOp_376(void)
{
    s32 cap = Stock_GetCapacity();
    u16 op = SCRIPT_READ();
    u16 who;

    if (op == 0)
    {
        if (Combatant_IsUsed(0))
            Combatant_ClearStatus(0, 1);
    }
    else if (op == 1)
    {
        goto members12;
    }
    else if (op == 2)
    {
        if (Combatant_IsUsed(0))
            Combatant_ClearStatus(0, 1);
    members12:
        if (Combatant_IsUsed(1))
            Combatant_ClearStatus(1, 1);
        if (Combatant_IsUsed(2))
            Combatant_ClearStatus(2, 1);
    }
    else
    {
        for (who = 0; who < cap + 4; who++)
        {
            if (Combatant_IsUsed(who))
                Combatant_ClearStatus(who, 1);
        }
    }
    sub_080C84A0();
}
#else
NAKED
void ScriptOp_376(void)
{
    asm_unified(
        "    push {r4, r5, lr}\n"
        "    bl Stock_GetCapacity\n"
        "    adds r3, r0, #0\n"
        "    ldr r2, .L0813618C\n"
        "    ldrh r0, [r2]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r2]\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r1, .L08136190\n"
        "    ldr r1, [r1]\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    adds r1, r0, #0\n"
        "    cmp r0, #0\n"
        "    bne .L08136194\n"
        "    movs r0, #0\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L081361F8\n"
        "    movs r0, #0\n"
        "    b .L081361CC\n"
        ".L0813618C: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L08136190: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L08136194:\n"
        "    cmp r0, #1\n"
        "    beq .L081361AE\n"
        "    cmp r1, #2\n"
        "    bne .L081361D4\n"
        "    movs r0, #0\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L081361AE\n"
        "    movs r0, #0\n"
        "    movs r1, #1\n"
        "    bl Combatant_ClearStatus\n"
        ".L081361AE:\n"
        "    movs r0, #1\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L081361C0\n"
        "    movs r0, #1\n"
        "    movs r1, #1\n"
        "    bl Combatant_ClearStatus\n"
        ".L081361C0:\n"
        "    movs r0, #2\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L081361F8\n"
        "    movs r0, #2\n"
        ".L081361CC:\n"
        "    movs r1, #1\n"
        "    bl Combatant_ClearStatus\n"
        "    b .L081361F8\n"
        ".L081361D4:\n"
        "    movs r4, #0\n"
        "    adds r5, r3, #4\n"
        "    cmp r4, r5\n"
        "    bge .L081361F8\n"
        ".L081361DC:\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L081361EE\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #1\n"
        "    bl Combatant_ClearStatus\n"
        ".L081361EE:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, r5\n"
        "    blt .L081361DC\n"
        ".L081361F8:\n"
        "    bl sub_080C84A0\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// sub_08136204 @ 0x08136204
s32 sub_08136204(s32 who, u32 slot, s32 val)
{
    s32 ret = 0;
    u8 *p = Battle_GetCombatant(who + 0x8000) + 0x28;

    switch (slot)
    {
    case 0:
        p[0] = val;
        ret = (s8)val;
        break;
    case 1:
        p[1] = val;
        ret = (s8)val;
        break;
    case 2:
        p[2] = val;
        ret = (s8)val;
        break;
    case 3:
        p[3] = val;
        ret = (s8)val;
        break;
    case 4:
        p[4] = val;
        ret = (s8)val;
        break;
    case 5:
        p[5] = val;
        ret = (s8)val;
        break;
    }
    return ret;
}

// sub_08136270 @ 0x08136270
s32 sub_08136270(s32 who, u32 slot, s32 val)
{
    s32 ret = 0;
    u8 *p = Battle_GetCombatant(who + 0x8000) + 0x38;

    switch (slot)
    {
    case 0:
        p[0] = val;
        ret = (s8)val;
        break;
    case 1:
        p[1] = val;
        ret = (s8)val;
        break;
    case 2:
        p[2] = val;
        ret = (s8)val;
        break;
    case 3:
        p[3] = val;
        ret = (s8)val;
        break;
    case 4:
        p[4] = val;
        ret = (s8)val;
        break;
    case 5:
        p[5] = val;
        ret = (s8)val;
        break;
    }
    return ret;
}

/* Sets up a guest party member: mode 0 = member 1 at level 18, mode 1 = member 2 at level
   24, each with fixed equipment and one of four random stat sets from gUnknown_087903EE;
   other modes drop member 1's cursed weapon (sub_08136114). */
// Party_SetupGuest @ 0x081362DC
void Party_SetupGuest(s32 mode)
{
    u16 idx;
    u16 status, mask;

    Battle_GetCombatant(0x8002);
    Battle_GetCombatant(0x8001);
    if (mode == 0)
    {
        Combatant_SetLevel(1, 18);
        sub_080C0F70(1, 9690);
        Combatant_SetEquip(1, 0, 0x06);
        Combatant_SetEquip(1, 1, 0x58);
        Combatant_SetEquip(1, 6, 0x70);
        Combatant_SetEquip(1, 2, 0x81);
        Combatant_SetEquip(1, 3, 0x96);
        Combatant_SetEquip(1, 4, 0xAA);
        Combatant_SetEquip(1, 5, 0xBF);
        idx = (Random_Byte() & 3) * 6;
        sub_08136204(1, 0, gUnknown_087903EE[idx]);
        sub_08136204(1, 1, gUnknown_087903EE[idx + 1]);
        sub_08136204(1, 2, gUnknown_087903EE[idx + 2]);
        sub_08136204(1, 3, gUnknown_087903EE[idx + 3]);
        sub_08136204(1, 4, gUnknown_087903EE[idx + 4]);
        sub_08136204(1, 5, gUnknown_087903EE[idx + 5]);
        sub_08136270(1, 0, 0);
        sub_08136270(1, 1, 0);
        sub_08136270(1, 2, 0);
        sub_08136270(1, 3, 0);
        sub_08136270(1, 4, 0);
        sub_08136270(1, 5, 0);
        Combatant_RecalcStats(1);
        sub_080CDC34();
        gGameState[1].hp = gGameState[1].maxHp;
        gGameState[1].mp = gGameState[1].maxMp;
        Party_BuildSkillList(1);
    }
    else if (mode == 1)
    {
        Combatant_SetLevel(2, 24);
        sub_080C0F70(2, 23000);
        Combatant_SetEquip(2, 0, 0x02);
        Combatant_SetEquip(2, 1, 0x58);
        Combatant_SetEquip(2, 6, 0x70);
        Combatant_SetEquip(2, 2, 0x82);
        Combatant_SetEquip(2, 3, 0x98);
        Combatant_SetEquip(2, 4, 0xAC);
        Combatant_SetEquip(2, 5, 0xBF);
        idx = (Random_Byte() & 3) * 6 + 24;
        sub_08136204(2, 0, gUnknown_087903EE[idx]);
        sub_08136204(2, 1, gUnknown_087903EE[idx + 1]);
        sub_08136204(2, 2, gUnknown_087903EE[idx + 2]);
        sub_08136204(2, 3, gUnknown_087903EE[idx + 3]);
        sub_08136204(2, 4, gUnknown_087903EE[idx + 4]);
        sub_08136204(2, 5, gUnknown_087903EE[idx + 5]);
        sub_08136270(2, 0, 0);
        sub_08136270(2, 1, 0);
        sub_08136270(2, 2, 0);
        sub_08136270(2, 3, 0);
        sub_08136270(2, 4, 0);
        sub_08136270(2, 5, 0);
        Combatant_RecalcStats(2);
        sub_080CDC34();
        gGameState[2].hp = gGameState[2].maxHp;
        gGameState[2].mp = gGameState[2].maxMp;
        Party_BuildSkillList(2);
    }
    else
    {
        status = Combatant_GetStatus(1);
        mask = 0xC01;
        if (status & mask)
        {
            Combatant_ClearStatus(1, ~mask);
            sub_081360D4(1);
        }
        Combatant_ClearStatus(1, 0);
        sub_08136114();
        gGameState[1].hp = gGameState[1].maxHp;
        gGameState[1].mp = gGameState[1].maxMp;
        Party_BuildSkillList(1);
    }
}

/* Adds a party member: operand 0-3 a human (0 -> member 1, 1 -> member 2), otherwise the
   stock demon gUnk_0203DB28[0]. When the party is full the last demon in the formation is
   removed to make room. */
// ScriptOp_377 @ 0x081365D0
void ScriptOp_377(void)
{
    u16 who = SCRIPT_READ();
    s32 i, j;
    s32 cap;
    s8 m;

    if (who <= 3)
    {
        if (who == 1)
            who = 2;
        else if (who == 0)
            who = 1;
        if ((u16)Party_Add(who) == 0)
        {
            for (i = 5; i >= 0; i--)
            {
                m = PARTY_ORDER(i);
                if (m > 3)
                {
                    /* returns without the guest setup below */
                    Party_Remove(m, 0);
                    Party_Add(who);
                    Party_BuildMemberNameTiles();
                    Hud_LoadAllMemberFaces();
                    return;
                }
            }
        }
        else
        {
            Party_BuildMemberNameTiles();
            Hud_LoadAllMemberFaces();
        }
        if (who == 1)
        {
            if (Flag_Test(0xF))
                Party_SetupGuest(2);
            else
                Party_SetupGuest(0);
        }
        else
        {
            Party_SetupGuest(1);
        }
        Flag_Clear(0xE3);
        if (!Flag_Test(0xE2))
            Flag_Clear(0xCF);
    }
    else
    {
        cap = Stock_GetCapacity();
        for (i = 4; i < cap + 4; i++)
        {
            if (Combatant_IsAlive(i) && Combatant_GetDemonId(i) == gUnk_0203DB28[0])
            {
                if ((u16)Party_Add(i) == 0)
                {
                    for (j = 5; j >= 0; j--)
                    {
                        m = PARTY_ORDER(j);
                        if (m > 3)
                        {
                            Party_Remove(m, 0);
                            Party_Add(i);
                            break;
                        }
                    }
                }
                Party_BuildMemberNameTiles();
                Hud_LoadAllMemberFaces();
                return;
            }
        }
    }
}

// ScriptOp_378 @ 0x08136718
void ScriptOp_378(void)
{
    s32 op = SCRIPT_READ();
    u16 who = op;
    s32 idx;

    if (op <= 3)
    {
        if (Combatant_IsUsed(1))
            who = 1;
        else if (Combatant_IsUsed(2))
            who = 2;
        Party_Remove(who, 0);
    }
    else
    {
        idx = Stock_FindDemonIndex(gUnk_0203DB28[op & 1]);
        if (idx >= 0)
            Party_Remove(idx, 1);
    }
    Party_FixFormation();
}

// ScriptOp_379 @ 0x08136790
void ScriptOp_379(void)
{
    u16 i;

    gUnk_030068A0 = 0;
    if (gUnk_030065FC != 0)
    {
        for (i = 0; i < gUnk_030065FC; i++)
            Inventory_AddItem(gScriptItemCheckId);
    }
    else
    {
        Inventory_AddItem(gScriptItemCheckId);
    }
}

/* Removes gUnk_030065FC of item gScriptItemCheckId; when none is in the bag, unequips it
   from the first human wearing it instead. */
// ScriptOp_37A @ 0x081367E4
void ScriptOp_37A(void)
{
    u16 i, who, slot;

    gUnk_030068A0 = 0;
    if (gUnk_030065FC > 0)
    {
        for (i = 0; i < gUnk_030065FC; i++)
        {
            if (Inventory_GetCount(gScriptItemCheckId))
            {
                Inventory_RemoveItem(gScriptItemCheckId);
            }
            else
            {
                slot = sub_080D2268(gScriptItemCheckId);
                for (who = 0; who < 4; who++)
                {
                    if (Combatant_IsUsed(who) && (u16)Combatant_GetEquip(who, slot) == gScriptItemCheckId)
                    {
                        sub_080CDFF8(who, slot);
                        break;
                    }
                }
            }
        }
    }
    else
    {
        Inventory_RemoveItem(gScriptItemCheckId);
    }
}

// ScriptOp_37B @ 0x08136888
void ScriptOp_37B(void)
{
    gUnk_030068B0 = BgPicture_StartTask(gUnk_03004534);
    gScriptWaitState = 2;
    gScriptYield = 1;
}

// ScriptOp_37D @ 0x081368B8
void ScriptOp_37D(void)
{
    u16 target = SCRIPT_READ();

    if (target == 3)
        target = 0x8000;
    else if (target == 4)
        target = 0x8001;
    else if (target == 5)
        target = 0x8002;
    gUnk_030068E0 = NameEntry_Open(target);
    gScriptWaitState = 0x17;
    gMsgGlyphCount = 0;
    gTextColumn = 0;
    gTextLine = 0;
    if (gMsgWindowOpen)
    {
        Window_Close(gMsgWindow, 1);
        gMsgWindowOpen = 0;
    }
    Font_ResetGlyphSpriteCache(0x180);
    gScriptYield = 1;
}

// ScriptOp_37F @ 0x0813695C
void ScriptOp_37F(void)
{
    u16 who = SCRIPT_READ();
    u16 mask = SCRIPT_READ();
    u16 lo;
    u32 target;

    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    if (mask & Combatant_GetStatus(who))
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_380 @ 0x081369BC
void ScriptOp_380(void)
{
    gScriptPc += 2;
}

// ScriptOp_381 @ 0x081369CC
void ScriptOp_381(void)
{
    s32 cap = Stock_GetCapacity();
    u16 a = SCRIPT_READ();
    u16 b = SCRIPT_READ();
    u16 lo;
    u32 target;
    u16 n;
    s16 i;

    lo = SCRIPT_READ();
    target = SCRIPT_READ();
    target = target << 16 | lo;
    if (a == 1)
    {
        if (b == 0)
        {
            gScriptJumpTarget = (u16 *)target;
        }
        else if (b == 3)
        {
            n = 0;
            for (i = 4; i < cap + 4; i++)
            {
                if (Combatant_IsUsed(i) && !(Combatant_GetStatus(i) & 0xB160))
                    n++;
            }
            if (n == 0)
                gScriptJumpTarget = (u16 *)target;
        }
        else
        {
            gScriptJumpTarget = (u16 *)target;
        }
    }
    else if (a == 2)
    {
        if (b == 0)
        {
            gUnk_030065E8 = b;
            sub_08135180(0);
            gUnk_0203DAC8[0] = (u16 *)target;
            gScriptWaitState = 0x40;
            gScriptYield = 1;
        }
        else
        {
            if (b == 1)
            {
                gUnk_030065E8 = b;
                sub_08135180(1);
            }
            else
            {
                gUnk_030065E8 = a;
                sub_08135180(1);
            }
            gUnk_0203DAC8[0] = (u16 *)target;
            gScriptWaitState = 0x40;
            gScriptYield = 1;
        }
    }
    else if (a == 3)
    {
        gMsgGlyphCount = 0;
        gTextColumn = 0;
        gTextLine = 0;
        gUnk_0203DB4A = 0;
        if (gMsgWindowOpen)
        {
            Window_Close(gMsgWindow, 1);
            gMsgWindowOpen = 0;
        }
        Font_ResetGlyphSpriteCache(0x180);
        gUnk_0203DAC8[0] = (u16 *)target;
        gScriptWaitState = 0x41;
        gScriptYield = 1;
    }
    else
    {
        if (b == 0)
        {
            for (i = 4; i < cap + 4; i++)
            {
                if (Combatant_IsUsed(i) && Combatant_GetDemonId(i) == Combatant_GetDemonId(gUnk_03006944))
                {
                    Party_Remove(i, 1);
                    break;
                }
            }
        }
        sub_080C84A0();
        gScriptJumpTarget = (u16 *)target;
    }
}

// ScriptOp_382 @ 0x08136BD4
#ifdef NONMATCHING
void ScriptOp_382(void)
{
    u16 idx;
    u16 *p;
    u16 lo;
    u32 hi;

    gMsgGlyphCount = gTextColumn = gTextLine = gUnk_0203DB4A = 0;
    Font_ResetGlyphSpriteCache(0x180);
    idx = SCRIPT_READ();
    idx *= 2;
    gUnk_030068D0 = gScriptBase;
    gUnk_03006610 = gScriptPc;
    gUnk_03006910 = 1;
    if (gUnk_03006914 > 0xFF)
    {
        gScriptBase = (u16 *)gUnknown_08035ABC;
        idx += (gUnk_03006914 & 0xFF) * 14;
    }
    else
    {
        gScriptBase = (u16 *)gUnknown_0803534C;
        idx += gUnk_03006914 * 28;
    }
    p = &gScriptBase[idx];
    lo = p[0];
    hi = p[1];
    hi <<= 16;
    hi |= lo;
    gScriptJumpTarget = (u16 *)hi;
}
#else
NAKED
void ScriptOp_382(void)
{
    asm_unified(
        "    push {r4, lr}\n"
        "    ldr r4, .L08136C30\n"
        "    ldr r3, .L08136C34\n"
        "    ldr r2, .L08136C38\n"
        "    ldr r1, .L08136C3C\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    strh r0, [r2]\n"
        "    strh r0, [r3]\n"
        "    strh r0, [r4]\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #1\n"
        "    bl Font_ResetGlyphSpriteCache\n"
        "    ldr r1, .L08136C40\n"
        "    ldrh r0, [r1]\n"
        "    adds r2, r0, #1\n"
        "    strh r2, [r1]\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r4, .L08136C44\n"
        "    ldr r1, [r4]\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r1\n"
        "    ldrh r3, [r0]\n"
        "    lsls r0, r3, #0x11\n"
        "    lsrs r3, r0, #0x10\n"
        "    ldr r0, .L08136C48\n"
        "    str r1, [r0]\n"
        "    ldr r0, .L08136C4C\n"
        "    strh r2, [r0]\n"
        "    ldr r1, .L08136C50\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L08136C54\n"
        "    ldrh r2, [r1]\n"
        "    cmp r2, #0xff\n"
        "    bls .L08136C5C\n"
        "    ldr r0, .L08136C58\n"
        "    str r0, [r4]\n"
        "    movs r1, #0xff\n"
        "    ands r1, r2\n"
        "    lsls r0, r1, #3\n"
        "    subs r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    b .L08136C68\n"
        "    .byte 0x00, 0x00\n"
        ".L08136C30: .4byte 0x0203DB3E @ EWRAM+0x3DB3E\n"
        ".L08136C34: .4byte 0x0203DB38 @ EWRAM+0x3DB38\n"
        ".L08136C38: .4byte 0x0203DB3A @ EWRAM+0x3DB3A\n"
        ".L08136C3C: .4byte 0x0203DB4A @ EWRAM+0x3DB4A\n"
        ".L08136C40: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L08136C44: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L08136C48: .4byte 0x030068D0 @ IWRAM+0x68D0\n"
        ".L08136C4C: .4byte 0x03006610 @ IWRAM+0x6610\n"
        ".L08136C50: .4byte 0x03006910 @ IWRAM+0x6910\n"
        ".L08136C54: .4byte 0x03006914 @ IWRAM+0x6914\n"
        ".L08136C58: .4byte gUnknown_08035ABC\n"
        ".L08136C5C:\n"
        "    ldr r0, .L08136C88\n"
        "    str r0, [r4]\n"
        "    ldrh r1, [r1]\n"
        "    lsls r0, r1, #3\n"
        "    subs r0, r0, r1\n"
        "    lsls r0, r0, #2\n"
        ".L08136C68:\n"
        "    adds r0, r3, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    ldr r0, .L08136C8C\n"
        "    ldr r1, [r0]\n"
        "    lsls r0, r3, #1\n"
        "    adds r0, r0, r1\n"
        "    ldrh r1, [r0]\n"
        "    ldrh r0, [r0, #2]\n"
        "    lsls r0, r0, #0x10\n"
        "    orrs r0, r1\n"
        "    ldr r1, .L08136C90\n"
        "    str r0, [r1]\n"
        "    pop {r4}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L08136C88: .4byte gUnknown_0803534C\n"
        ".L08136C8C: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L08136C90: .4byte 0x030068E4 @ IWRAM+0x68E4\n"
    );
}
#endif

// ScriptOp_388 @ 0x08136C94
void ScriptOp_388(void)
{
    gUnk_03006938 = sub_080B80F8();
    gScriptWaitState = 0x15;
    gScriptYield = 1;
}

// ScriptOp_389 @ 0x08136CBC
void ScriptOp_389(void)
{
    switch (gUnk_03006914)
    {
    case 0x1C:
        gScriptJumpTarget = (u16 *)gUnknown_08073C5E;
        break;
    case 0x1D:
        gScriptJumpTarget = (u16 *)gUnknown_08074C28;
        break;
    case 0x1E:
        gScriptJumpTarget = (u16 *)gUnknown_08075BE8;
        break;
    case 0x1F:
        gScriptJumpTarget = (u16 *)gUnknown_08076C3C;
        break;
    case 0x20:
        gScriptJumpTarget = (u16 *)gUnknown_08076F80;
        break;
    case 0x21:
        gScriptJumpTarget = (u16 *)gUnknown_08077338;
        break;
    }
}
