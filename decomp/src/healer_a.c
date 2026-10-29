/* Script VM opcode handlers 0x35A-0x36D: party HP/status effects and the healer. */

#include "global.h"
#include "scriptops3.h"

#define STATUS_TICK(who)                                                \
    if (Combatant_IsAlive(who))                                         \
    {                                                                   \
        sub_080C08E8(who, mask);                                        \
        if (Combatant_GetStatus(who) & 0x8000)                          \
            Combatant_ChangeHp(who, -Combatant_GetHp(who));                \
    }


// ScriptOp_35A @ 0x08134CE4
void ScriptOp_35A(void)
{
    u16 lo;
    u32 target;
    u32 n, i;

    lo = SCRIPT_READ();
    target = SCRIPT_READ();
    target = target << 16 | lo;
    n = Stock_GetCapacity();
    for (i = 0; i < n; i++)
    {
        if (!Combatant_IsUsed(i + 4))
            return;
    }
    gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_35B @ 0x08134D3C
void ScriptOp_35B(void)
{
}

// ScriptOp_35C @ 0x08134D40
void ScriptOp_35C(void)
{
    s32 n = Stock_GetCapacity();
    u16 who = SCRIPT_READ();
    u16 pct = SCRIPT_READ();

    if (who == 0xFF)
    {
        for (who = 0; who < n + 4; who++)
        {
            if (Combatant_IsUsed(who) && !Combatant_IsDead(who) && Combatant_IsInParty(who))
                Combatant_ChangeHpPercent(who, -pct);
        }
    }
    else
    {
        Combatant_ChangeHpPercent(who, -pct);
    }
    sub_080C84A0();
}

// ScriptOp_35D @ 0x08134DC4
void ScriptOp_35D(void)
{
}

// Combatant_GetHp @ 0x08134DC8
s16 Combatant_GetHp(u16 who)
{
    return *(s16 *)(Battle_GetCombatant(who + 0x8000) + 0x18);
}

// Combatant_GetMaxHp @ 0x08134DE0
s16 Combatant_GetMaxHp(u16 who)
{
    return *(s16 *)(Battle_GetCombatant(who + 0x8000) + 0x1A);
}

// Combatant_GetMp @ 0x08134DF8
s16 Combatant_GetMp(u16 who)
{
    return *(s16 *)(Battle_GetCombatant(who + 0x8000) + 0x1C);
}

// Combatant_GetMaxMp @ 0x08134E10
s16 Combatant_GetMaxMp(u16 who)
{
    return *(s16 *)(Battle_GetCombatant(who + 0x8000) + 0x1E);
}

// ScriptOp_35E @ 0x08134E28
#ifdef NONMATCHING
void ScriptOp_35E(void)
{
    s32 n = Stock_GetCapacity();
    u32 op = SCRIPT_READ();
    u16 idx = op & 0xFF;
    u16 kind = (op >> 8) & 0xFF;
    u16 mask = gUnknown_08790398[idx];
    u16 who;

    switch (kind)
    {
    case 0:
        STATUS_TICK(0)
        break;
    case 2:
        STATUS_TICK(0)
    case 1:
        STATUS_TICK(1)
        STATUS_TICK(2)
        break;
    default:
        for (who = 0; who < n + 4; who++)
        {
            if (Combatant_IsAlive(who) && Combatant_IsInParty(who))
            {
                sub_080C08E8(who, mask);
                if (Combatant_GetStatus(who) & 0x8000)
                    Combatant_ChangeHp(who, -Combatant_GetHp(who));
            }
        }
        break;
    }
    sub_080C84A0();
}
#else
NAKED
void ScriptOp_35E(void)
{
    asm_unified(
        "    push {r4, r5, r6, lr}\n"
        "    bl Stock_GetCapacity\n"
        "    adds r5, r0, #0\n"
        "    ldr r2, .L08134E68\n"
        "    ldrh r0, [r2]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r2]\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r1, .L08134E6C\n"
        "    ldr r1, [r1]\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r1\n"
        "    ldrh r3, [r0]\n"
        "    movs r1, #0xff\n"
        "    adds r0, r3, #0\n"
        "    ands r0, r1\n"
        "    lsrs r2, r3, #8\n"
        "    ands r2, r1\n"
        "    adds r3, r2, #0\n"
        "    ldr r1, .L08134E70\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r1\n"
        "    ldrh r6, [r0]\n"
        "    cmp r2, #1\n"
        "    beq .L08134EEC\n"
        "    cmp r2, #1\n"
        "    bgt .L08134E74\n"
        "    cmp r2, #0\n"
        "    beq .L08134E7A\n"
        "    b .L08134F5A\n"
        "    .byte 0x00, 0x00\n"
        ".L08134E68: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L08134E6C: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L08134E70: .4byte gUnknown_08790398\n"
        ".L08134E74:\n"
        "    cmp r3, #2\n"
        "    beq .L08134EB6\n"
        "    b .L08134F5A\n"
        ".L08134E7A:\n"
        "    movs r0, #0\n"
        "    bl Combatant_IsAlive\n"
        "    cmp r0, #0\n"
        "    bne .L08134E86\n"
        "    b .L08134FAE\n"
        ".L08134E86:\n"
        "    movs r0, #0\n"
        "    adds r1, r6, #0\n"
        "    bl sub_080C08E8\n"
        "    movs r0, #0\n"
        "    bl Combatant_GetStatus\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    bne .L08134EA0\n"
        "    b .L08134FAE\n"
        ".L08134EA0:\n"
        "    movs r0, #0\n"
        "    bl Combatant_GetHp\n"
        "    adds r1, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    rsbs r1, r1, #0\n"
        "    movs r0, #0\n"
        "    bl Combatant_ChangeHp\n"
        "    b .L08134FAE\n"
        ".L08134EB6:\n"
        "    movs r0, #0\n"
        "    bl Combatant_IsAlive\n"
        "    cmp r0, #0\n"
        "    beq .L08134EEC\n"
        "    movs r0, #0\n"
        "    adds r1, r6, #0\n"
        "    bl sub_080C08E8\n"
        "    movs r0, #0\n"
        "    bl Combatant_GetStatus\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L08134EEC\n"
        "    movs r0, #0\n"
        "    bl Combatant_GetHp\n"
        "    adds r1, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    rsbs r1, r1, #0\n"
        "    movs r0, #0\n"
        "    bl Combatant_ChangeHp\n"
        ".L08134EEC:\n"
        "    movs r0, #1\n"
        "    bl Combatant_IsAlive\n"
        "    cmp r0, #0\n"
        "    beq .L08134F22\n"
        "    movs r0, #1\n"
        "    adds r1, r6, #0\n"
        "    bl sub_080C08E8\n"
        "    movs r0, #1\n"
        "    bl Combatant_GetStatus\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L08134F22\n"
        "    movs r0, #1\n"
        "    bl Combatant_GetHp\n"
        "    adds r1, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    rsbs r1, r1, #0\n"
        "    movs r0, #1\n"
        "    bl Combatant_ChangeHp\n"
        ".L08134F22:\n"
        "    movs r0, #2\n"
        "    bl Combatant_IsAlive\n"
        "    cmp r0, #0\n"
        "    beq .L08134FAE\n"
        "    movs r0, #2\n"
        "    adds r1, r6, #0\n"
        "    bl sub_080C08E8\n"
        "    movs r0, #2\n"
        "    bl Combatant_GetStatus\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L08134FAE\n"
        "    movs r0, #2\n"
        "    bl Combatant_GetHp\n"
        "    adds r1, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    rsbs r1, r1, #0\n"
        "    movs r0, #2\n"
        "    bl Combatant_ChangeHp\n"
        "    b .L08134FAE\n"
        ".L08134F5A:\n"
        "    movs r4, #0\n"
        "    adds r5, #4\n"
        "    cmp r4, r5\n"
        "    bge .L08134FAE\n"
        ".L08134F62:\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_IsAlive\n"
        "    cmp r0, #0\n"
        "    beq .L08134FA4\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_IsInParty\n"
        "    cmp r0, #0\n"
        "    beq .L08134FA4\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r6, #0\n"
        "    bl sub_080C08E8\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_GetStatus\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #8\n"
        "    adds r1, r2, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08134FA4\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_GetHp\n"
        "    adds r1, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    rsbs r1, r1, #0\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_ChangeHp\n"
        ".L08134FA4:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, r5\n"
        "    blt .L08134F62\n"
        ".L08134FAE:\n"
        "    bl sub_080C84A0\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

// ScriptOp_35F @ 0x08134FB8
void ScriptOp_35F(void)
{
    gMsgGlyphCount = 0;
    gTextColumn = 0;
    gTextLine = 0;
    if (gMsgWindowOpen)
    {
        Window_Close(gMsgWindow, 1);
        gMsgWindowOpen = 0;
    }
    Font_ResetGlyphSpriteCache(0x180);
    gScriptPc++;
    if (gUnk_030068A8 == 2)
        gUnk_030068E0 = Fusion_StartScreen(2);
    else if (gUnk_030068A8 == 3)
        gUnk_030068E0 = Fusion_StartScreen(3);
    else if (gUnk_030068A8 == 1)
        gUnk_030068E0 = Fusion_StartScreen(4);
    else if (gUnk_030068A8 == 4)
        gUnk_030068E0 = Fusion_StartScreen(1);
    else if (gUnk_030068A8 == 5)
        gUnk_030068E0 = Fusion_StartScreen(5);
    else if (gUnk_030068A8 == 6)
        gUnk_030068E0 = Fusion_StartScreen(6);
    gScriptWaitState = 0x2C;
    gScriptYield = 1;
}

// Healer_GetCost @ 0x08135064
u32 Healer_GetCost(u16 who, u16 kind)
{
    u32 cost = 0;

    if (kind <= 1 && !(gGameState[who].flags & 0x8000))
        cost = Healer_HpMpCost(who);
    if (kind == 2 || kind == 0)
        cost += sub_081352F8(who);
    if (kind == 3 || kind == 0)
        cost += sub_08135320(who);
    if (kind == 4 || kind == 0)
        cost += sub_08135348(who);
    return cost;
}

// Healer_Apply @ 0x081350CC
#ifdef NONMATCHING
void Healer_Apply(u16 who, u16 kind)
{
    u16 status, mask;

    switch (kind)
    {
    case 2:
        Combatant_ClearStatus(who, 0x8C01);
        break;
    case 3:
        Combatant_ClearStatus(who, 0x7FFF);
    case 1:
        Combatant_RestoreHp(who);
        Combatant_RestoreMp(who);
        break;
    case 4:
        Combatant_ClearStatus(who, 0xF3FE);
        sub_081360D4(who);
        break;
    case 0:
        status = Combatant_GetStatus(who);
        mask = 0xC01;
        if (status & mask)
        {
            Combatant_ClearStatus(who, ~mask);
            sub_081360D4(who);
        }
        Combatant_ClearStatus(who, 0);
        Combatant_RestoreHp(who);
        Combatant_RestoreMp(who);
        break;
    }
}
#else
NAKED
void Healer_Apply(u16 who, u16 kind)
{
    asm_unified(
        ".L081350CC:\n"
        "    push {r4, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r0, r1, #0x10\n"
        "    cmp r0, #4\n"
        "    bhi .L08135170\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L081350E4\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        ".L081350E4: .4byte gUnknown_081350E8\n"
        "    .global gUnknown_081350E8\n"
        "gUnknown_081350E8:\n"
        ".L081350E8: @ jump table\n"
        "    .4byte .L0813513C\n"
        "    .4byte .L08135114\n"
        "    .4byte .L081350FC\n"
        "    .4byte .L0813510C\n"
        "    .4byte .L08135128\n"
        ".L081350FC:\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, .L08135108\n"
        "    bl Combatant_ClearStatus\n"
        "    b .L08135170\n"
        "    .byte 0x00, 0x00\n"
        ".L08135108: .4byte 0x00008C01\n"
        ".L0813510C:\n"
        "    ldr r1, .L08135124\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_ClearStatus\n"
        ".L08135114:\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_RestoreHp\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_RestoreMp\n"
        "    b .L08135170\n"
        "    .byte 0x00, 0x00\n"
        ".L08135124: .4byte 0x00007FFF\n"
        ".L08135128:\n"
        "    ldr r1, .L08135138\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_ClearStatus\n"
        "    adds r0, r4, #0\n"
        "    bl sub_081360D4\n"
        "    b .L08135170\n"
        ".L08135138: .4byte 0x0000F3FE\n"
        ".L0813513C:\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_GetStatus\n"
        "    ldr r2, .L08135178\n"
        "    adds r1, r2, #0\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L0813515C\n"
        "    ldr r1, .L0813517C\n"
        "    eors r1, r2\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_ClearStatus\n"
        "    adds r0, r4, #0\n"
        "    bl sub_081360D4\n"
        ".L0813515C:\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0\n"
        "    bl Combatant_ClearStatus\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_RestoreHp\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_RestoreMp\n"
        ".L08135170:\n"
        "    pop {r4}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L08135178: .4byte 0x00000C01\n"
        ".L0813517C: .4byte 0x0000FFFF\n"
    );
}
#endif

// sub_08135180 @ 0x08135180
void sub_08135180(u16 mode)
{
    u16 n = 0;
    u16 *list = sub_0812DBF0();
    s32 cap = Stock_GetCapacity();
    u16 who;

    if (mode == 0)
    {
        for (who = 4; who < cap + 4; who++)
        {
            if (Combatant_IsUsed(who) && ((u16)Combatant_GetStatus(who) & 0xB160) == 0)
            {
                list[n] = who;
                n++;
            }
        }
        list[n] = 0xFFFF;
    }
    else if (mode == 1)
    {
        list[0] = 0xFFFF;
    }
}

// Healer_HpMpCost @ 0x08135200
u32 Healer_HpMpCost(u16 who)
{
    s16 maxHp = (u16)Combatant_GetMaxHp(who);
    s16 hp = (u16)Combatant_GetHp(who);
    s16 maxMp = (u16)Combatant_GetMaxMp(who);
    s16 mp = (u16)Combatant_GetMp(who);
    u16 dHp, dMp;
    u32 k;

    if (maxHp < hp)
        dHp = 0;
    else
        dHp = maxHp - hp;
    if (maxMp < mp)
        dMp = 0;
    else
        dMp = maxMp - mp;
    k = gUnk_0203DB72 & 3;
    return (u32)(dHp * gUnknown_087903B8[k] + dMp * gUnknown_087903BE[k]) >> 8;
}

// Healer_StatusCost @ 0x08135290
u32 Healer_StatusCost(u16 bits, u16 who)
{
    u32 sum = 0;
    u16 i;
    u16 w;

    for (i = 0; i < 16; i++)
    {
        if (bits & 0x8000)
        {
            w = gUnknown_087903C4[i];
            sum += w * Combatant_GetLevel(who);
        }
        bits <<= 1;
    }
    if (sum > 99999)
        sum = 99999;
    return sum;
}

// sub_081352F8 @ 0x081352F8
u32 sub_081352F8(u16 who)
{
    u16 bits = Combatant_GetStatus(who);

    bits &= 0x33FE;
    return Healer_StatusCost(bits, who);
}

// sub_08135320 @ 0x08135320
u32 sub_08135320(u16 who)
{
    u16 bits = Combatant_GetStatus(who);

    bits &= 0x8000;
    return Healer_StatusCost(bits, who);
}

// sub_08135348 @ 0x08135348
u32 sub_08135348(u16 who)
{
    u16 bits = Combatant_GetStatus(who);

    bits &= 0xC01;
    return Healer_StatusCost(bits, who);
}

/* Healer lists: party members (and stock demons) that need the service, with prices. */
// sub_08135370 @ 0x08135370
bool32 sub_08135370(void)
{
    u16 n = 0;
    u16 *list = sub_0812DBF0();
    u32 *prices = BattleMenu_GetPriceList();
    s32 cap = Stock_GetCapacity();
    u16 who;

    for (who = 0; who < cap + 4; who++)
    {
        if (Combatant_IsAlive(who))
        {
            if (Combatant_GetMaxHp(who) > Combatant_GetHp(who) || Combatant_GetMaxMp(who) > Combatant_GetMp(who))
            {
                list[n] = who;
                prices[n] = Healer_HpMpCost(who);
                n++;
            }
        }
    }
    list[n] = 0xFFFF;
    prices[n] = -1;
    if (n == 0)
        return TRUE;
    return FALSE;
}

// sub_08135420 @ 0x08135420
bool32 sub_08135420(void)
{
    u16 n = 0;
    u16 *list = sub_0812DBF0();
    u32 *prices = BattleMenu_GetPriceList();
    s32 cap = Stock_GetCapacity();
    u16 who;

    for (who = 0; who < cap + 4; who++)
    {
        if (Combatant_IsAlive(who) && (Combatant_GetStatus(who) & 0x33FE))
        {
            list[n] = who;
            prices[n] = sub_081352F8(who);
            n++;
        }
    }
    list[n] = 0xFFFF;
    prices[n] = -1;
    if (n == 0)
        return TRUE;
    return FALSE;
}

// sub_081354B0 @ 0x081354B0
bool32 sub_081354B0(void)
{
    u16 n = 0;
    u16 *list = sub_0812DBF0();
    u32 *prices = BattleMenu_GetPriceList();
    s32 cap = Stock_GetCapacity();
    u16 who;

    for (who = 0; who < cap + 4; who++)
    {
        if (Combatant_IsUsed(who) && (Combatant_GetStatus(who) & 0x8000))
        {
            list[n] = who;
            prices[n] = sub_08135320(who);
            n++;
        }
    }
    list[n] = 0xFFFF;
    prices[n] = -1;
    if (n == 0)
        return TRUE;
    return FALSE;
}

// sub_08135540 @ 0x08135540
bool32 sub_08135540(void)
{
    u16 n = 0;
    u16 *list = sub_0812DBF0();
    u32 *prices = BattleMenu_GetPriceList();
    s32 cap = Stock_GetCapacity();
    u16 who;

    for (who = 0; who < cap + 4; who++)
    {
        if (Combatant_IsAlive(who) && (Combatant_GetStatus(who) & 0xC01))
        {
            list[n] = who;
            prices[n] = sub_08135348(who);
            n++;
        }
    }
    list[n] = 0xFFFF;
    prices[n] = -1;
    if (n == 0)
        return TRUE;
    return FALSE;
}

// Healer_TotalCost @ 0x081355D0
u32 Healer_TotalCost(u16 who)
{
    return Healer_HpMpCost(who) + sub_081352F8(who) + sub_08135320(who) + sub_08135348(who);
}

// sub_0813560C @ 0x0813560C
bool32 sub_0813560C(void)
{
    u16 n = 0;
    u16 *list = sub_0812DBF0();
    u32 *prices = BattleMenu_GetPriceList();
    s32 cap = Stock_GetCapacity();
    u16 who;

    for (who = 0; who < cap + 4; who++)
    {
        if (Combatant_IsUsed(who))
        {
            if ((u16)Combatant_GetStatus(who) != 0
             || Combatant_GetMaxHp(who) > Combatant_GetHp(who) || Combatant_GetMaxMp(who) > Combatant_GetMp(who))
            {
                list[n] = who;
                prices[n] = Healer_TotalCost(who);
                n++;
            }
        }
    }
    list[n] = 0xFFFF;
    prices[n] = -1;
    if (n == 0)
        return TRUE;
    return FALSE;
}

// ScriptOp_360 @ 0x081356C8
void ScriptOp_360(void)
{
    u16 lo;
    u32 target;

    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    gUnk_0203DAC8[0] = (u16 *)target;
    gUnk_0300668C = 1;
    sub_0812DC24();
    gScriptWaitState = 0x1E;
    gScriptYield = 1;
}

// ScriptOp_361 @ 0x08135724
void ScriptOp_361(void)
{
    u16 lo;
    u32 target;

    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    gUnk_0203DAC8[0] = (u16 *)target;
    gUnk_0300668C = 2;
    sub_0812DC24();
    gScriptWaitState = 0x1E;
    gScriptYield = 1;
}

// ScriptOp_362 @ 0x08135784
void ScriptOp_362(void)
{
    u16 lo;
    u32 target;

    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    gUnk_0203DAC8[0] = (u16 *)target;
    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    gUnk_0203DAC8[1] = (u16 *)target;
    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    gUnk_0203DAC8[2] = (u16 *)target;
    gUnk_0300668C = 3;
    sub_0812DC24();
    gScriptWaitState = 0x1E;
    gScriptYield = 1;
}

// ScriptOp_363 @ 0x08135820
void ScriptOp_363(void)
{
    u16 lo;
    u32 target;

    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    gUnk_0203DAC8[0] = (u16 *)target;
    gUnk_0300668C = 4;
    sub_0812DC24();
    gScriptWaitState = 0x1E;
    gScriptYield = 1;
}

// ScriptOp_364 @ 0x08135880
void ScriptOp_364(void)
{
}

// ScriptOp_365 @ 0x08135884
void ScriptOp_365(void)
{
    gScriptPc++;
}

// ScriptOp_370_371 @ 0x08135894
void ScriptOp_370_371(void)
{
    gScriptPc += 2;
}

// ScriptOp_366 @ 0x081358A4
void ScriptOp_366(void)
{
    u16 i = SCRIPT_READ();
    u16 lo;
    u32 target;
    u16 mask;

    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    mask = gUnknown_08790398[i];
    if (mask & Combatant_GetStatus(0))
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_367 @ 0x08135904
void ScriptOp_367(void)
{
}

// ScriptOp_368 @ 0x08135908
void ScriptOp_368(void)
{
    gUnk_0203DB74 = gUnk_0203DB72 = SCRIPT_READ();
}

// ScriptOp_369 @ 0x0813593C
void ScriptOp_369(void)
{
}

// ScriptOp_36B @ 0x08135940
void ScriptOp_36B(void)
{
    u16 pos = SCRIPT_READ();
    u16 x, y;

    gScriptPc++;
    x = pos >> 8;
    y = pos & 0xFF;
    gScriptWaitState = 0x14;
    gUnk_03006954 = Warp_ToWorldPosition(0, x, y, 0, 0);
    gScriptYield = 1;
}

// ScriptOp_36C @ 0x08135998
void ScriptOp_36C(void)
{
    u16 pos = SCRIPT_READ();

    gScriptPc++;
    gUnk_03006954 = Warp_ToWorldPosition(0, pos >> 8, pos & 0xFF, 0, 0);
}

// ScriptOp_36D @ 0x081359DC
void ScriptOp_36D(void)
{
    u16 mode = SCRIPT_READ();

    gScriptWaitState = 0x32;
    switch (mode)
    {
    case 0:
    case 2:
        if (gUnk_0200AB04 & 0x8000)
        {
            BgPicture_LoadPalette();
            sub_080B0778();
        }
        else if (sub_080B78A4() == 0)
        {
            sub_080B05A4();
        }
        break;
    case 1:
        if (gUnk_0200AB04 & 0x8000)
            sub_080B0820();
        else
            sub_080B0620();
        break;
    case 3:
        gUnk_03006964 = sub_080B8AE0(0xFFFF, 1);
        gScriptWaitState = 0x33;
        break;
    }
    gScriptYield = 1;
}

// sub_08135A94 @ 0x08135A94
u16 sub_08135A94(u8 a)
{
    return sub_08157238(a);
}
