/* Script VM opcode 0x445: negotiation and shop actions. */

#include "global.h"
#include "scriptops3.h"

extern u16 gScriptYield;
extern u16 gUnk_0203DB80;
extern u8 gUnk_030068B4;
extern u8 gUnk_030069E8;
extern u16 gShopItemIds[];     /* [0] kind, [1] mode, [2] counter, [3] */

struct Task *sub_0812EE8C(u32 mode, struct Task *parent);
s32 sub_080EF954(void);
u32 sub_080C8890(u16 a, u16 b);
void sub_0813B400(void);
void sub_0813BE70(void);
void sub_0813B438(u16 who);
u16 sub_08138CE8(void);
u32 sub_080D3AA0(u32 op);
void sub_080D4560(u16 filter);
void Party_SaveOrderHeroOnly(void);
void Party_RestoreOrder(void);
s32 Exp_GetForLevel(s32 level);
s32 Combatant_GetBaseStat(s32 who, s32 stat);
void Hud_InvalidateGauges(void);

#define HP(p) (*(s16 *)((p) + 0x18))
#define MAXHP(p) (*(s16 *)((p) + 0x1A))

/* 0x445 action: one operand, the action. gUnk_0203DB7C is the demon being talked to,
   member 0 the hero.
    3 revives / fully heals that demon in the stock (when dead, or above half hp)
    4 opens the member window (wait state 0x4F)     5 sub_080C84A0 (gauges)
    6 revives and heals the hero                     7 sub_080EF930(sub_080EF954())
    8/9/10 the demon hurts the hero by its field 0 (+ 1-8 random / * 2), leaving 1 hp
    0xB drains field 0 / 4 + 1 mp from party slot 1 or 2
    0xC/0xD toggle 0x0300684C bits 8 / 0x10, 0xE/0xF/0x10 set bits 1 / 4 / 2
    0x11 heals the first wounded living member (slots up to the stock capacity + 4)
    0x12 asks a price (field 5 of the demon) with message 0x41
    0x13 message 0x16 and a 0x1F window (wait state 0x4C)   0x14 message 0x39
    0x15 message 0x40, the hero takes gUnk_0203DB2C damage, dying ends the script
    0x17 resets the negotiation text window       0x18 pays a shop item, sets flags
    0x19 ends the script when sub_08138CE8        0x1A the hero takes gUnk_0203DB2C damage
    0x1B gUnk_0203DB7C := gUnk_0203DB80           0x1C sub_080D3AA0(1)
    0x1D/0x1E open the demon list (sub_080D4560 0/1, wait state 0x52)
    0x1F-0x21, 0x22-0x24 gShopItemIds[1] / [0] := 0-2
    0x25-0x27 counter reset / step / restore the party order (gShopItemIds[0] == 1)
    0x28 the hero loses a level (from level 7) and one point of a random stat */
/* NONMATCHING: same cases in the same order; register choice and shared tails differ
   throughout (0x6CC bytes against 0x708). */
// ScriptOp_445 @ 0x0813B524
#ifdef NONMATCHING
void ScriptOp_445(struct Task *task)
{
    u16 op = SCRIPT_READ();
    s32 cap;
    u16 i;
    u32 d;
    s32 who;
    s32 stat;
    s32 base;
    u16 level;
    u16 tries;

    if (op == 3)
    {
        cap = Stock_GetCapacity();
        for (i = 4; i < cap + 4; i++)
        {
            if (Combatant_IsUsed(i) && Combatant_GetDemonId(i) == gUnk_0203DB7C)
            {
                if (Combatant_GetStatus(i) & 0x8000)
                {
                    Combatant_ClearStatus(i, 1);
                    gGameState[i].hp = gGameState[i].maxHp;
                    goto gauges;
                }
                if (gGameState[i].maxHp / 2 < gGameState[i].hp)
                {
                    Combatant_ClearStatus(i, 1);
                    gGameState[i].hp = gGameState[i].maxHp;
                    goto gauges;
                }
                return;
            }
        }
        return;
    }
    else if (op == 4)
    {
        gUnk_030068E0 = (u32)sub_0812EE8C(0, 0);
        gScriptWaitState = 0x4F;
        goto waitWindow;
    }
    else if (op == 5)
        goto gauges;
    else if (op == 6)
    {
        Combatant_ClearStatus(0, 1);
        Combatant_RestoreHp(0);
        goto gauges;
    }
    else if (op == 7)
    {
        sub_080EF930(sub_080EF954());
        gUnk_030068B4 = gUnk_030069E8;
        return;
    }
    else if (op == 8)
    {
        gGameState[0].hp -= Demon_GetField(gUnk_0203DB7C, 0) & 0xFF;
        if ((s16)(gGameState[0].hp - 1) <= 0)
            gGameState[0].hp = 1;
        return;
    }
    else if (op == 9)
    {
        d = (Random_Byte() & 7) + 1;
        d = (u8)(d + Demon_GetField(gUnk_0203DB7C, 0));
        gGameState[0].hp -= d;
        if ((s16)(gGameState[0].hp - 1) <= 0)
            gGameState[0].hp = 1;
        return;
    }
    else if (op == 10)
    {
        d = (Demon_GetField(gUnk_0203DB7C, 0) & 0xFF) * 2;
        gGameState[0].hp -= d;
        if ((s16)(gGameState[0].hp - 1) <= 0)
            gGameState[0].hp = 1;
        return;
    }
    else if (op == 11)
    {
        d = ((Demon_GetField(gUnk_0203DB7C, 0) & 0xFF) >> 2) + 1;
        if (Combatant_IsUsed(1))
            who = 1;
        else if (Combatant_IsUsed(2))
            who = 2;
        else
            return;
        gGameState[who].mp -= d;
        if (gGameState[who].mp <= 0)
            gGameState[who].mp = 0;
        goto gauges;
    }
    else if (op == 12)
    {
        if (gUnk_0300684C & 8)
            gUnk_0300684C &= ~8;
        else
            gUnk_0300684C |= 8;
        return;
    }
    else if (op == 13)
    {
        if (gUnk_0300684C & 0x10)
            gUnk_0300684C &= ~0x10;
        else
            gUnk_0300684C |= 0x10;
        return;
    }
    else if (op == 14)
    {
        gUnk_0300684C |= 1;
        return;
    }
    else if (op == 15)
    {
        gUnk_0300684C |= 4;
        return;
    }
    else if (op == 16)
    {
        gUnk_0300684C |= 2;
        return;
    }
    else if (op == 17)
    {
        cap = Stock_GetCapacity();
        for (i = 0; i < cap + 4; i++)
        {
            if (Combatant_IsAlive(i) == 1)
            {
                u16 b = i + 0x8000;
                u8 *p = Battle_GetCombatant(b);
                if (HP(p) < MAXHP(Battle_GetCombatant(b)))
                {
                    Combatant_RestoreHp(i);
                    return;
                }
            }
        }
        return;
    }
    else if (op == 18)
    {
        gUnk_0203DB2C = Demon_GetField(gUnk_0203DB7C, 5) & 0xFF;
        sub_08132350(0x41);
        for (i = 0; (s8)PARTY_ORDER(i) != 0;)
        {
            if (++i > 4)
                break;
        }
        sub_080C8890(i, 1);
        goto waitWindow;
    }
    else if (op == 19)
    {
        sub_08132350(0x16);
        gUnk_03006964 = sub_080B8AE0(0x1F, 1);
        gScriptWaitState = 0x4C;
        goto waitWindow;
    }
    else if (op == 20)
    {
        sub_08132350(0x39);
        return;
    }
    else if (op == 21)
    {
        sub_08132350(0x40);
        if ((u32)HP(Battle_GetCombatant(0x8000)) < gUnk_0203DB2C)
            HP(Battle_GetCombatant(0x8000)) -= gUnk_0203DB2C;
        if (!(HP(Battle_GetCombatant(0x8000)) & 0x8000) && HP(Battle_GetCombatant(0x8000)) > 0)
            return;
        HP(Battle_GetCombatant(0x8000)) = 0;
        Combatant_ClearStatus(0, 1);
        sub_080C08E8(0, 0x8000);
        goto endIfDone;
    }
    else if (op == 23)
    {
        sub_0813B400();
        sub_0813BE70();
        gUnk_0300684C |= 0x40;
        gMsgGlyphCount = 0;
        gTextColumn = 0;
        gTextLine = 0;
        gUnk_0203DB4A = 0;
        Font_ResetGlyphSpriteCache(0x180);
        return;
    }
    else if (op == 24)
    {
        Money_Add(-sub_0812F188(gUnk_030065E0 - 0x9D));
        if ((Moon_GetPhase() & 0xF0) != 0x80)
            Flag_Set(0xCF);
        who = (u16)gUnk_03006898;
        sub_0813B438(who);
        if (who == 0)
            Flag_Set(0xE2);
        else
            Flag_Set(0xE3);
        return;
    }
    else if (op == 25)
    {
    endIfDone:
        if (sub_08138CE8())
            task->result = 1;
        return;
    }
    else if (op == 26)
    {
        if ((u32)HP(Battle_GetCombatant(0x8000)) <= gUnk_0203DB2C)
        {
            HP(Battle_GetCombatant(0x8000)) = 0;
            sub_080C08E8(0, 0x8000);
        }
        else
            HP(Battle_GetCombatant(0x8000)) -= gUnk_0203DB2C;
        goto gauges;
    }
    else if (op == 27)
    {
        gUnk_0203DB7C = gUnk_0203DB80;
        return;
    }
    else if (op == 28)
    {
        sub_080D3AA0(1);
        return;
    }
    else if (op == 29)
    {
        sub_080D4560(0);
        goto demonList;
    }
    else if (op == 30)
    {
        sub_080D4560(1);
    demonList:
        gScriptWaitState = 0x52;
    waitWindow:
        gScriptYield = 1;
        return;
    }
    else if (op == 31)
        gShopItemIds[1] = 0;
    else if (op == 32)
        gShopItemIds[1] = 1;
    else if (op == 33)
        gShopItemIds[1] = 2;
    else if (op == 34)
        gShopItemIds[0] = 0;
    else if (op == 35)
        gShopItemIds[0] = 1;
    else if (op == 36)
        gShopItemIds[0] = 2;
    else if (op == 37)
    {
        gShopItemIds[2] = 0;
        gShopItemIds[3] = 0xFF;
        if (gShopItemIds[0] == 1)
            Party_SaveOrderHeroOnly();
    }
    else if (op == 38)
    {
        gShopItemIds[2]++;
        gUnk_0203DB2C = gShopItemIds[2];
    }
    else if (op == 39)
    {
        if (gShopItemIds[0] == 1)
            Party_RestoreOrder();
    }
    else if (op == 40)
    {
        level = Combatant_GetLevel(0);
        if (level <= 6)
            return;
        level--;
        Combatant_SetLevel(0, level);
        sub_080C0F70(0, Exp_GetForLevel(level));
        stat = Random_Byte() & 3;
        stat += Random_Byte() & 1;
        stat += Random_Byte() & 1;
        /* lowers the first stat from `stat` on that is above its minimum */
        for (tries = 0; tries <= 5; tries++)
        {
            if (stat == 0)
            {
                if ((base = Combatant_GetBaseStat(0, 0)) > 6)
                {
                    sub_08136204(0, 0, base - 1);
                    goto heal;
                }
                stat = 1;
            }
            else if (stat == 1)
            {
                if ((base = Combatant_GetBaseStat(0, 1)) > 5)
                {
                    sub_08136204(0, 1, base - 1);
                    goto heal;
                }
                stat = 2;
            }
            else if (stat == 2)
            {
                if ((base = Combatant_GetBaseStat(0, 2)) > 4)
                {
                    sub_08136204(0, 2, base - 1);
                    goto heal;
                }
                stat = 3;
            }
            else if (stat == 3)
            {
                if ((base = Combatant_GetBaseStat(0, 3)) > 6)
                {
                    sub_08136204(0, 3, base - 1);
                    goto heal;
                }
                stat = 4;
            }
            else if (stat == 4)
            {
                if ((base = Combatant_GetBaseStat(0, 4)) > 6)
                {
                    sub_08136204(0, 4, base - 1);
                    goto heal;
                }
                stat = 5;
            }
            else
            {
                if ((base = Combatant_GetBaseStat(0, 5)) > 3)
                {
                    sub_08136204(0, 5, base - 1);
                    goto heal;
                }
                stat = 0;
            }
        }
    }
    return;
heal:
    gGameState[0].hp = gGameState[0].maxHp;
    Hud_InvalidateGauges();
    return;
gauges:
    sub_080C84A0();
}
#else
NAKED
void ScriptOp_445(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    adds r6, r0, #0\n"
        "    ldr r2, .L0813B5AC\n"
        "    ldrh r0, [r2]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r2]\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r1, .L0813B5B0\n"
        "    ldr r1, [r1]\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r1\n"
        "    ldrh r1, [r0]\n"
        "    cmp r1, #3\n"
        "    bne .L0813B5CA\n"
        "    bl Stock_GetCapacity\n"
        "    adds r7, r0, #0\n"
        "    movs r6, #4\n"
        "    adds r0, r7, #4\n"
        "    cmp r6, r0\n"
        "    blt .L0813B550\n"
        "    b .L0813BC20\n"
        ".L0813B550:\n"
        "    adds r0, r6, #0\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L0813B5BC\n"
        "    adds r0, r6, #0\n"
        "    bl Combatant_GetDemonId\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    ldr r1, .L0813B5B4\n"
        "    ldrh r1, [r1]\n"
        "    cmp r0, r1\n"
        "    bne .L0813B5BC\n"
        "    adds r0, r6, #0\n"
        "    bl Combatant_GetStatus\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #8\n"
        "    adds r1, r2, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L0813B580\n"
        "    b .L0813BBEA\n"
        ".L0813B580:\n"
        "    ldr r1, .L0813B5B8\n"
        "    lsls r0, r6, #7\n"
        "    adds r4, r0, r1\n"
        "    movs r3, #0x1a\n"
        "    ldrsh r0, [r4, r3]\n"
        "    lsrs r1, r0, #0x1f\n"
        "    adds r0, r0, r1\n"
        "    asrs r0, r0, #1\n"
        "    movs r2, #0x18\n"
        "    ldrsh r1, [r4, r2]\n"
        "    cmp r0, r1\n"
        "    blt .L0813B59A\n"
        "    b .L0813BC20\n"
        ".L0813B59A:\n"
        "    adds r0, r6, #0\n"
        "    movs r1, #1\n"
        "    bl Combatant_ClearStatus\n"
        "    ldrh r0, [r4, #0x1a]\n"
        "    strh r0, [r4, #0x18]\n"
        ".L0813B5A6:\n"
        "    bl sub_080C84A0\n"
        "    b .L0813BC20\n"
        ".L0813B5AC: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L0813B5B0: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L0813B5B4: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813B5B8: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L0813B5BC:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    adds r0, r7, #4\n"
        "    cmp r6, r0\n"
        "    blt .L0813B550\n"
        "    b .L0813BC20\n"
        ".L0813B5CA:\n"
        "    cmp r1, #4\n"
        "    bne .L0813B5E8\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    bl sub_0812EE8C\n"
        "    ldr r1, .L0813B5E0\n"
        "    str r0, [r1]\n"
        "    ldr r1, .L0813B5E4\n"
        "    movs r0, #0x4f\n"
        "    b .L0813BA0E\n"
        ".L0813B5E0: .4byte 0x030068E0 @ IWRAM+0x68E0\n"
        ".L0813B5E4: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L0813B5E8:\n"
        "    cmp r1, #5\n"
        "    beq .L0813B5A6\n"
        "    cmp r1, #6\n"
        "    bne .L0813B600\n"
        "    movs r0, #0\n"
        "    movs r1, #1\n"
        "    bl Combatant_ClearStatus\n"
        "    movs r0, #0\n"
        "    bl Combatant_RestoreHp\n"
        "    b .L0813B5A6\n"
        ".L0813B600:\n"
        "    cmp r1, #7\n"
        "    bne .L0813B620\n"
        "    bl sub_080EF954\n"
        "    adds r2, r0, #0\n"
        "    bl sub_080EF930\n"
        "    ldr r0, .L0813B618\n"
        "    ldr r1, .L0813B61C\n"
        "    ldrb r1, [r1]\n"
        "    strb r1, [r0]\n"
        "    b .L0813BC20\n"
        ".L0813B618: .4byte 0x030068B4 @ IWRAM+0x68B4\n"
        ".L0813B61C: .4byte 0x030069E8 @ IWRAM+0x69E8\n"
        ".L0813B620:\n"
        "    cmp r1, #8\n"
        "    bne .L0813B658\n"
        "    ldr r0, .L0813B650\n"
        "    ldrh r0, [r0]\n"
        "    movs r1, #0\n"
        "    bl Demon_GetField\n"
        "    movs r1, #0xff\n"
        "    ands r1, r0\n"
        "    ldr r2, .L0813B654\n"
        "    ldrh r0, [r2, #0x18]\n"
        "    subs r0, r0, r1\n"
        "    strh r0, [r2, #0x18]\n"
        "    movs r3, #0x18\n"
        "    ldrsh r0, [r2, r3]\n"
        "    subs r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    ble .L0813B648\n"
        "    b .L0813BC20\n"
        ".L0813B648:\n"
        "    movs r0, #1\n"
        "    strh r0, [r2, #0x18]\n"
        "    b .L0813BC20\n"
        "    .byte 0x00, 0x00\n"
        ".L0813B650: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813B654: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L0813B658:\n"
        "    cmp r1, #9\n"
        "    bne .L0813B694\n"
        "    bl Random_Byte\n"
        "    movs r1, #7\n"
        "    ands r0, r1\n"
        "    adds r5, r0, #1\n"
        "    ldr r0, .L0813B68C\n"
        "    ldrh r0, [r0]\n"
        "    movs r1, #0\n"
        "    bl Demon_GetField\n"
        "    adds r0, r5, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    movs r1, #0xff\n"
        "    lsls r1, r1, #0x10\n"
        "    ands r1, r0\n"
        "    lsrs r5, r1, #0x10\n"
        "    ldr r1, .L0813B690\n"
        "    ldrh r0, [r1, #0x18]\n"
        "    subs r0, r0, r5\n"
        "    strh r0, [r1, #0x18]\n"
        "    movs r2, #0x18\n"
        "    ldrsh r0, [r1, r2]\n"
        "    b .L0813B6B4\n"
        "    .byte 0x00, 0x00\n"
        ".L0813B68C: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813B690: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L0813B694:\n"
        "    cmp r1, #0xa\n"
        "    bne .L0813B6CC\n"
        "    ldr r0, .L0813B6C4\n"
        "    ldrh r0, [r0]\n"
        "    movs r1, #0\n"
        "    bl Demon_GetField\n"
        "    movs r1, #0xff\n"
        "    ands r1, r0\n"
        "    lsls r5, r1, #1\n"
        "    ldr r1, .L0813B6C8\n"
        "    ldrh r0, [r1, #0x18]\n"
        "    subs r0, r0, r5\n"
        "    strh r0, [r1, #0x18]\n"
        "    movs r3, #0x18\n"
        "    ldrsh r0, [r1, r3]\n"
        ".L0813B6B4:\n"
        "    subs r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    ble .L0813B6BE\n"
        "    b .L0813BC20\n"
        ".L0813B6BE:\n"
        "    movs r0, #1\n"
        "    strh r0, [r1, #0x18]\n"
        "    b .L0813BC20\n"
        ".L0813B6C4: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813B6C8: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L0813B6CC:\n"
        "    cmp r1, #0xb\n"
        "    bne .L0813B724\n"
        "    ldr r0, .L0813B6F0\n"
        "    ldrh r0, [r0]\n"
        "    movs r1, #0\n"
        "    bl Demon_GetField\n"
        "    movs r1, #0xff\n"
        "    ands r1, r0\n"
        "    lsrs r1, r1, #2\n"
        "    adds r5, r1, #1\n"
        "    movs r0, #1\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    beq .L0813B6F4\n"
        "    movs r6, #1\n"
        "    b .L0813B702\n"
        ".L0813B6F0: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813B6F4:\n"
        "    movs r0, #2\n"
        "    bl Combatant_IsUsed\n"
        "    cmp r0, #0\n"
        "    bne .L0813B700\n"
        "    b .L0813BC20\n"
        ".L0813B700:\n"
        "    movs r6, #2\n"
        ".L0813B702:\n"
        "    ldr r1, .L0813B720\n"
        "    lsls r0, r6, #7\n"
        "    adds r1, r0, r1\n"
        "    ldrh r0, [r1, #0x1c]\n"
        "    subs r0, r0, r5\n"
        "    strh r0, [r1, #0x1c]\n"
        "    movs r2, #0x1c\n"
        "    ldrsh r0, [r1, r2]\n"
        "    cmp r0, #0\n"
        "    ble .L0813B718\n"
        "    b .L0813B5A6\n"
        ".L0813B718:\n"
        "    movs r0, #0\n"
        "    strh r0, [r1, #0x1c]\n"
        "    b .L0813B5A6\n"
        "    .byte 0x00, 0x00\n"
        ".L0813B720: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L0813B724:\n"
        "    cmp r1, #0xc\n"
        "    bne .L0813B740\n"
        "    ldr r2, .L0813B738\n"
        "    ldrb r1, [r2]\n"
        "    movs r0, #8\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L0813B73C\n"
        "    movs r0, #0xf7\n"
        "    b .L0813B752\n"
        ".L0813B738: .4byte 0x0300684C @ IWRAM+0x684C\n"
        ".L0813B73C:\n"
        "    movs r0, #8\n"
        "    b .L0813B75E\n"
        ".L0813B740:\n"
        "    cmp r1, #0xd\n"
        "    bne .L0813B764\n"
        "    ldr r2, .L0813B758\n"
        "    ldrb r1, [r2]\n"
        "    movs r0, #0x10\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L0813B75C\n"
        "    movs r0, #0xef\n"
        ".L0813B752:\n"
        "    ands r0, r1\n"
        "    strb r0, [r2]\n"
        "    b .L0813BC20\n"
        ".L0813B758: .4byte 0x0300684C @ IWRAM+0x684C\n"
        ".L0813B75C:\n"
        "    movs r0, #0x10\n"
        ".L0813B75E:\n"
        "    orrs r0, r1\n"
        "    strb r0, [r2]\n"
        "    b .L0813BC20\n"
        ".L0813B764:\n"
        "    cmp r1, #0xe\n"
        "    bne .L0813B774\n"
        "    ldr r0, .L0813B770\n"
        "    ldrb r1, [r0]\n"
        "    movs r2, #1\n"
        "    b .L0813B78E\n"
        ".L0813B770: .4byte 0x0300684C @ IWRAM+0x684C\n"
        ".L0813B774:\n"
        "    cmp r1, #0xf\n"
        "    bne .L0813B784\n"
        "    ldr r0, .L0813B780\n"
        "    ldrb r1, [r0]\n"
        "    movs r2, #4\n"
        "    b .L0813B78E\n"
        ".L0813B780: .4byte 0x0300684C @ IWRAM+0x684C\n"
        ".L0813B784:\n"
        "    cmp r1, #0x10\n"
        "    bne .L0813B798\n"
        "    ldr r0, .L0813B794\n"
        "    ldrb r1, [r0]\n"
        "    movs r2, #2\n"
        ".L0813B78E:\n"
        "    orrs r1, r2\n"
        "    strb r1, [r0]\n"
        "    b .L0813BC20\n"
        ".L0813B794: .4byte 0x0300684C @ IWRAM+0x684C\n"
        ".L0813B798:\n"
        "    cmp r1, #0x11\n"
        "    bne .L0813B7EA\n"
        "    bl Stock_GetCapacity\n"
        "    adds r7, r0, #0\n"
        "    movs r6, #0\n"
        "    adds r0, r7, #4\n"
        "    cmp r6, r0\n"
        "    blt .L0813B7AC\n"
        "    b .L0813BC20\n"
        ".L0813B7AC:\n"
        "    adds r0, r6, #0\n"
        "    bl Combatant_IsAlive\n"
        "    cmp r0, #1\n"
        "    bne .L0813B7DC\n"
        "    movs r3, #0x80\n"
        "    lsls r3, r3, #8\n"
        "    adds r4, r6, r3\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    adds r5, r0, #0\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    movs r2, #0x18\n"
        "    ldrsh r1, [r5, r2]\n"
        "    movs r3, #0x1a\n"
        "    ldrsh r0, [r0, r3]\n"
        "    cmp r1, r0\n"
        "    bge .L0813B7DC\n"
        "    b .L0813BC04\n"
        ".L0813B7DC:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    adds r0, r7, #4\n"
        "    cmp r6, r0\n"
        "    blt .L0813B7AC\n"
        "    b .L0813BC20\n"
        ".L0813B7EA:\n"
        "    cmp r1, #0x12\n"
        "    bne .L0813B844\n"
        "    ldr r4, .L0813B838\n"
        "    ldr r0, .L0813B83C\n"
        "    ldrh r0, [r0]\n"
        "    movs r1, #5\n"
        "    bl Demon_GetField\n"
        "    movs r1, #0xff\n"
        "    ands r1, r0\n"
        "    str r1, [r4]\n"
        "    movs r0, #0x41\n"
        "    bl sub_08132350\n"
        "    movs r1, #0\n"
        "    ldr r0, .L0813B840\n"
        "    movs r3, #0xa2\n"
        "    lsls r3, r3, #4\n"
        "    adds r2, r0, r3\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r2, r0]\n"
        "    cmp r0, #0\n"
        "    beq .L0813B82E\n"
        ".L0813B818:\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    cmp r1, #4\n"
        "    bhi .L0813B82E\n"
        "    adds r0, r1, r2\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    cmp r0, #0\n"
        "    bne .L0813B818\n"
        ".L0813B82E:\n"
        "    adds r0, r1, #0\n"
        "    movs r1, #1\n"
        "    bl sub_080C8890\n"
        "    b .L0813BA10\n"
        ".L0813B838: .4byte 0x0203DB2C @ EWRAM+0x3DB2C\n"
        ".L0813B83C: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813B840: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L0813B844:\n"
        "    cmp r1, #0x13\n"
        "    bne .L0813B868\n"
        "    movs r0, #0x16\n"
        "    bl sub_08132350\n"
        "    movs r0, #0x1f\n"
        "    movs r1, #1\n"
        "    bl sub_080B8AE0\n"
        "    ldr r1, .L0813B860\n"
        "    str r0, [r1]\n"
        "    ldr r1, .L0813B864\n"
        "    movs r0, #0x4c\n"
        "    b .L0813BA0E\n"
        ".L0813B860: .4byte 0x03006964 @ IWRAM+0x6964\n"
        ".L0813B864: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L0813B868:\n"
        "    cmp r1, #0x14\n"
        "    bne .L0813B874\n"
        "    movs r0, #0x39\n"
        "    bl sub_08132350\n"
        "    b .L0813BC20\n"
        ".L0813B874:\n"
        "    cmp r1, #0x15\n"
        "    bne .L0813B8E4\n"
        "    movs r0, #0x40\n"
        "    bl sub_08132350\n"
        "    movs r4, #0x80\n"
        "    lsls r4, r4, #8\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    movs r2, #0x18\n"
        "    ldrsh r1, [r0, r2]\n"
        "    ldr r5, .L0813B8E0\n"
        "    ldr r0, [r5]\n"
        "    cmp r1, r0\n"
        "    bhs .L0813B8A2\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    ldr r2, [r5]\n"
        "    ldrh r1, [r0, #0x18]\n"
        "    subs r1, r1, r2\n"
        "    strh r1, [r0, #0x18]\n"
        ".L0813B8A2:\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    movs r3, #0x18\n"
        "    ldrsh r0, [r0, r3]\n"
        "    ands r0, r4\n"
        "    cmp r0, #0\n"
        "    bne .L0813B8C2\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    movs r1, #0x18\n"
        "    ldrsh r0, [r0, r1]\n"
        "    cmp r0, #0\n"
        "    ble .L0813B8C2\n"
        "    b .L0813BC20\n"
        ".L0813B8C2:\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    movs r1, #0\n"
        "    strh r1, [r0, #0x18]\n"
        "    movs r0, #0\n"
        "    movs r1, #1\n"
        "    bl Combatant_ClearStatus\n"
        "    movs r0, #0\n"
        "    adds r1, r4, #0\n"
        "    bl sub_080C08E8\n"
        "    b .L0813B980\n"
        "    .byte 0x00, 0x00\n"
        ".L0813B8E0: .4byte 0x0203DB2C @ EWRAM+0x3DB2C\n"
        ".L0813B8E4:\n"
        "    cmp r1, #0x17\n"
        "    bne .L0813B92C\n"
        "    bl sub_0813B400\n"
        "    bl sub_0813BE70\n"
        "    ldr r2, .L0813B918\n"
        "    ldrb r0, [r2]\n"
        "    movs r1, #0x40\n"
        "    orrs r0, r1\n"
        "    strb r0, [r2]\n"
        "    ldr r0, .L0813B91C\n"
        "    movs r1, #0\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L0813B920\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L0813B924\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L0813B928\n"
        "    strh r1, [r0]\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #1\n"
        "    bl Font_ResetGlyphSpriteCache\n"
        "    b .L0813BC20\n"
        "    .byte 0x00, 0x00\n"
        ".L0813B918: .4byte 0x0300684C @ IWRAM+0x684C\n"
        ".L0813B91C: .4byte 0x0203DB3E @ EWRAM+0x3DB3E\n"
        ".L0813B920: .4byte 0x0203DB38 @ EWRAM+0x3DB38\n"
        ".L0813B924: .4byte 0x0203DB3A @ EWRAM+0x3DB3A\n"
        ".L0813B928: .4byte 0x0203DB4A @ EWRAM+0x3DB4A\n"
        ".L0813B92C:\n"
        "    cmp r1, #0x18\n"
        "    bne .L0813B97C\n"
        "    ldr r0, .L0813B96C\n"
        "    ldrh r0, [r0]\n"
        "    subs r0, #0x9d\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl sub_0812F188\n"
        "    rsbs r0, r0, #0\n"
        "    bl Money_Add\n"
        "    bl Moon_GetPhase\n"
        "    movs r1, #0xf0\n"
        "    ands r1, r0\n"
        "    cmp r1, #0x80\n"
        "    beq .L0813B956\n"
        "    movs r0, #0xcf\n"
        "    bl Flag_Set\n"
        ".L0813B956:\n"
        "    ldr r0, .L0813B970\n"
        "    ldrh r4, [r0]\n"
        "    adds r0, r4, #0\n"
        "    bl sub_0813B438\n"
        "    cmp r4, #0\n"
        "    bne .L0813B974\n"
        "    movs r0, #0xe2\n"
        "    bl Flag_Set\n"
        "    b .L0813BC20\n"
        ".L0813B96C: .4byte 0x030065E0 @ IWRAM+0x65E0\n"
        ".L0813B970: .4byte 0x03006898 @ IWRAM+0x6898\n"
        ".L0813B974:\n"
        "    movs r0, #0xe3\n"
        "    bl Flag_Set\n"
        "    b .L0813BC20\n"
        ".L0813B97C:\n"
        "    cmp r1, #0x19\n"
        "    bne .L0813B992\n"
        ".L0813B980:\n"
        "    bl sub_08138CE8\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L0813B98C\n"
        "    b .L0813BC20\n"
        ".L0813B98C:\n"
        "    movs r0, #1\n"
        "    strh r0, [r6, #0x1c]\n"
        "    b .L0813BC20\n"
        ".L0813B992:\n"
        "    cmp r1, #0x1a\n"
        "    bne .L0813B9D4\n"
        "    movs r4, #0x80\n"
        "    lsls r4, r4, #8\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    movs r2, #0x18\n"
        "    ldrsh r1, [r0, r2]\n"
        "    ldr r5, .L0813B9C0\n"
        "    ldr r0, [r5]\n"
        "    cmp r1, r0\n"
        "    bhi .L0813B9C4\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    movs r1, #0\n"
        "    strh r1, [r0, #0x18]\n"
        "    movs r0, #0\n"
        "    adds r1, r4, #0\n"
        "    bl sub_080C08E8\n"
        "    b .L0813B5A6\n"
        ".L0813B9C0: .4byte 0x0203DB2C @ EWRAM+0x3DB2C\n"
        ".L0813B9C4:\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetCombatant\n"
        "    ldr r2, [r5]\n"
        "    ldrh r1, [r0, #0x18]\n"
        "    subs r1, r1, r2\n"
        "    strh r1, [r0, #0x18]\n"
        "    b .L0813B5A6\n"
        ".L0813B9D4:\n"
        "    cmp r1, #0x1b\n"
        "    bne .L0813B9EC\n"
        "    ldr r0, .L0813B9E4\n"
        "    ldr r1, .L0813B9E8\n"
        "    ldrh r1, [r1]\n"
        "    strh r1, [r0]\n"
        "    b .L0813BC20\n"
        "    .byte 0x00, 0x00\n"
        ".L0813B9E4: .4byte 0x0203DB7C @ EWRAM+0x3DB7C\n"
        ".L0813B9E8: .4byte 0x0203DB80 @ EWRAM+0x3DB80\n"
        ".L0813B9EC:\n"
        "    cmp r1, #0x1c\n"
        "    bne .L0813B9F8\n"
        "    movs r0, #1\n"
        "    bl sub_080D3AA0\n"
        "    b .L0813BC20\n"
        ".L0813B9F8:\n"
        "    cmp r1, #0x1d\n"
        "    bne .L0813BA00\n"
        "    movs r0, #0\n"
        "    b .L0813BA06\n"
        ".L0813BA00:\n"
        "    cmp r1, #0x1e\n"
        "    bne .L0813BA20\n"
        "    movs r0, #1\n"
        ".L0813BA06:\n"
        "    bl sub_080D4560\n"
        "    ldr r1, .L0813BA18\n"
        "    movs r0, #0x52\n"
        ".L0813BA0E:\n"
        "    strh r0, [r1]\n"
        ".L0813BA10:\n"
        "    ldr r1, .L0813BA1C\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    b .L0813BC20\n"
        ".L0813BA18: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L0813BA1C: .4byte 0x0203DB6E @ EWRAM+0x3DB6E\n"
        ".L0813BA20:\n"
        "    cmp r1, #0x1f\n"
        "    bne .L0813BA30\n"
        "    ldr r1, .L0813BA2C\n"
        "    movs r0, #0\n"
        "    strh r0, [r1, #2]\n"
        "    b .L0813BC20\n"
        ".L0813BA2C: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L0813BA30:\n"
        "    cmp r1, #0x20\n"
        "    bne .L0813BA40\n"
        "    ldr r1, .L0813BA3C\n"
        "    movs r0, #1\n"
        "    strh r0, [r1, #2]\n"
        "    b .L0813BC20\n"
        ".L0813BA3C: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L0813BA40:\n"
        "    cmp r1, #0x21\n"
        "    bne .L0813BA50\n"
        "    ldr r1, .L0813BA4C\n"
        "    movs r0, #2\n"
        "    strh r0, [r1, #2]\n"
        "    b .L0813BC20\n"
        ".L0813BA4C: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L0813BA50:\n"
        "    cmp r1, #0x22\n"
        "    bne .L0813BA60\n"
        "    ldr r1, .L0813BA5C\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    b .L0813BC20\n"
        ".L0813BA5C: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L0813BA60:\n"
        "    cmp r1, #0x23\n"
        "    bne .L0813BA70\n"
        "    ldr r1, .L0813BA6C\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    b .L0813BC20\n"
        ".L0813BA6C: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L0813BA70:\n"
        "    cmp r1, #0x24\n"
        "    bne .L0813BA80\n"
        "    ldr r1, .L0813BA7C\n"
        "    movs r0, #2\n"
        "    strh r0, [r1]\n"
        "    b .L0813BC20\n"
        ".L0813BA7C: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L0813BA80:\n"
        "    cmp r1, #0x25\n"
        "    bne .L0813BAA0\n"
        "    ldr r1, .L0813BA9C\n"
        "    movs r0, #0\n"
        "    strh r0, [r1, #4]\n"
        "    movs r0, #0xff\n"
        "    strh r0, [r1, #6]\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #1\n"
        "    beq .L0813BA96\n"
        "    b .L0813BC20\n"
        ".L0813BA96:\n"
        "    bl Party_SaveOrderHeroOnly\n"
        "    b .L0813BC20\n"
        ".L0813BA9C: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L0813BAA0:\n"
        "    cmp r1, #0x26\n"
        "    bne .L0813BABC\n"
        "    ldr r0, .L0813BAB4\n"
        "    ldrh r1, [r0, #4]\n"
        "    adds r1, #1\n"
        "    strh r1, [r0, #4]\n"
        "    ldrh r1, [r0, #4]\n"
        "    ldr r0, .L0813BAB8\n"
        "    str r1, [r0]\n"
        "    b .L0813BC20\n"
        ".L0813BAB4: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L0813BAB8: .4byte 0x0203DB2C @ EWRAM+0x3DB2C\n"
        ".L0813BABC:\n"
        "    cmp r1, #0x27\n"
        "    bne .L0813BAD4\n"
        "    ldr r0, .L0813BAD0\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #1\n"
        "    beq .L0813BACA\n"
        "    b .L0813BC20\n"
        ".L0813BACA:\n"
        "    bl Party_RestoreOrder\n"
        "    b .L0813BC20\n"
        ".L0813BAD0: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L0813BAD4:\n"
        "    cmp r1, #0x28\n"
        "    beq .L0813BADA\n"
        "    b .L0813BC20\n"
        ".L0813BADA:\n"
        "    movs r0, #0\n"
        "    bl Combatant_GetLevel\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #6\n"
        "    bhi .L0813BAEA\n"
        "    b .L0813BC20\n"
        ".L0813BAEA:\n"
        "    subs r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    movs r0, #0\n"
        "    adds r1, r4, #0\n"
        "    bl Combatant_SetLevel\n"
        "    adds r0, r4, #0\n"
        "    bl Exp_GetForLevel\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #0\n"
        "    bl sub_080C0F70\n"
        "    bl Random_Byte\n"
        "    adds r6, r0, #0\n"
        "    movs r0, #3\n"
        "    ands r6, r0\n"
        "    bl Random_Byte\n"
        "    movs r4, #1\n"
        "    ands r0, r4\n"
        "    adds r6, r6, r0\n"
        "    bl Random_Byte\n"
        "    ands r0, r4\n"
        "    adds r6, r6, r0\n"
        "    movs r5, #0\n"
        ".L0813BB24:\n"
        "    cmp r6, #0\n"
        "    bne .L0813BB46\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    bl Combatant_GetBaseStat\n"
        "    adds r2, r0, #0\n"
        "    cmp r2, #6\n"
        "    bgt .L0813BB3A\n"
        "    movs r6, #1\n"
        "    b .L0813BBDE\n"
        ".L0813BB3A:\n"
        "    subs r2, #1\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    bl sub_08136204\n"
        "    b .L0813BC16\n"
        ".L0813BB46:\n"
        "    cmp r6, #1\n"
        "    bne .L0813BB68\n"
        "    movs r0, #0\n"
        "    movs r1, #1\n"
        "    bl Combatant_GetBaseStat\n"
        "    adds r2, r0, #0\n"
        "    cmp r2, #5\n"
        "    bgt .L0813BB5C\n"
        "    movs r6, #2\n"
        "    b .L0813BBDE\n"
        ".L0813BB5C:\n"
        "    subs r2, #1\n"
        "    movs r0, #0\n"
        "    movs r1, #1\n"
        "    bl sub_08136204\n"
        "    b .L0813BC16\n"
        ".L0813BB68:\n"
        "    cmp r6, #2\n"
        "    bne .L0813BB8A\n"
        "    movs r0, #0\n"
        "    movs r1, #2\n"
        "    bl Combatant_GetBaseStat\n"
        "    adds r2, r0, #0\n"
        "    cmp r2, #4\n"
        "    bgt .L0813BB7E\n"
        "    movs r6, #3\n"
        "    b .L0813BBDE\n"
        ".L0813BB7E:\n"
        "    subs r2, #1\n"
        "    movs r0, #0\n"
        "    movs r1, #2\n"
        "    bl sub_08136204\n"
        "    b .L0813BC16\n"
        ".L0813BB8A:\n"
        "    cmp r6, #3\n"
        "    bne .L0813BBAC\n"
        "    movs r0, #0\n"
        "    movs r1, #3\n"
        "    bl Combatant_GetBaseStat\n"
        "    adds r2, r0, #0\n"
        "    cmp r2, #6\n"
        "    bgt .L0813BBA0\n"
        "    movs r6, #4\n"
        "    b .L0813BBDE\n"
        ".L0813BBA0:\n"
        "    subs r2, #1\n"
        "    movs r0, #0\n"
        "    movs r1, #3\n"
        "    bl sub_08136204\n"
        "    b .L0813BC16\n"
        ".L0813BBAC:\n"
        "    cmp r6, #4\n"
        "    bne .L0813BBCE\n"
        "    movs r0, #0\n"
        "    movs r1, #4\n"
        "    bl Combatant_GetBaseStat\n"
        "    adds r2, r0, #0\n"
        "    cmp r2, #6\n"
        "    bgt .L0813BBC2\n"
        "    movs r6, #5\n"
        "    b .L0813BBDE\n"
        ".L0813BBC2:\n"
        "    subs r2, #1\n"
        "    movs r0, #0\n"
        "    movs r1, #4\n"
        "    bl sub_08136204\n"
        "    b .L0813BC16\n"
        ".L0813BBCE:\n"
        "    movs r0, #0\n"
        "    movs r1, #5\n"
        "    bl Combatant_GetBaseStat\n"
        "    adds r2, r0, #0\n"
        "    cmp r2, #3\n"
        "    bgt .L0813BC0C\n"
        "    movs r6, #0\n"
        ".L0813BBDE:\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #5\n"
        "    bhi .L0813BC20\n"
        "    b .L0813BB24\n"
        ".L0813BBEA:\n"
        "    adds r0, r6, #0\n"
        "    movs r1, #1\n"
        "    bl Combatant_ClearStatus\n"
        "    ldr r0, .L0813BC00\n"
        "    lsls r1, r6, #7\n"
        "    adds r1, r1, r0\n"
        "    ldrh r0, [r1, #0x1a]\n"
        "    strh r0, [r1, #0x18]\n"
        "    b .L0813B5A6\n"
        "    .byte 0x00, 0x00\n"
        ".L0813BC00: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L0813BC04:\n"
        "    adds r0, r6, #0\n"
        "    bl Combatant_RestoreHp\n"
        "    b .L0813BC20\n"
        ".L0813BC0C:\n"
        "    subs r2, #1\n"
        "    movs r0, #0\n"
        "    movs r1, #5\n"
        "    bl sub_08136204\n"
        ".L0813BC16:\n"
        "    ldr r1, .L0813BC28\n"
        "    ldrh r0, [r1, #0x1a]\n"
        "    strh r0, [r1, #0x18]\n"
        "    bl Hud_InvalidateGauges\n"
        ".L0813BC20:\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L0813BC28: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
    );
}
#endif
