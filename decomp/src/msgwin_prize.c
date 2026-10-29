/* Script message window: the casino prize exchange window (opened by the script, prizes from
   gUnknown_0878FEA8, see casinoprize_a.c). gUnk_0300696C is the cursor row (0-2) and
   gUnk_03006940 the first listed prize. */

#include "global.h"
#include "bmenu2.h"

extern const u16 gUnknown_0878FBA4[][16];  /* cursor x, y per row, by window layout */
extern const u16 gUnknown_0878FEA8[][16];  /* per prize set: count, then (item, price) */
extern u16 gScriptItemCheckId;

u16 CasinoPrize_GetSet(void);
void CasinoPrize_DrawList(u16 first);
u32 sub_080C31F0(void);
void sub_080C31B4(s32 delta);
void Inventory_AddItem(u16 id);

#define sTop (*(s16 *)&gUnk_03006940)

/* Wait handler: up/down move the cursor (scrolling the list at the ends), L/R jump a page.
   A buys the prize when the coins (sub_080C31F0) cover the price (0xFFFF = 100000, never)
   and fewer than 99 are owned (inventory + equipped), jumping to the script's 3rd target;
   otherwise to the 1st (too few coins) or 2nd (too many owned). B ends the wait. */
/* NONMATCHING: the list-redraw calls of the L, R and up branches are cross-jumped into one
   here; the original keeps them apart. */
// CasinoPrize_ExchangeInput @ 0x08131400
#ifdef NONMATCHING
void CasinoPrize_ExchangeInput(struct Task *task)
{
    u32 price = 0;     /* also the zero stored below (keeps the original register use) */
    u16 set;

    set = CasinoPrize_GetSet();
    gUnk_0300689C = gUnknown_0878FBA4[(s16)gUnk_03006844][gUnk_0300696C * 2] - 2;
    gUnk_0300695C = gUnknown_0878FBA4[(s16)gUnk_03006844][gUnk_0300696C * 2 + 1];
    gUnk_030066A0 = 0x17;
    if (gUnk_0300696C == 2)
        gUnk_030066A0 = 0x16;
    gUnk_03006958 = 1;
    if (gRepeatedKeys & 0x200)
    {
        if (gUnk_0300696C != 0)
            gUnk_0300696C = price;
        else
        {
            if (sTop - 3 >= 0)
                sTop -= 3;
            else
                sTop = price;
            CasinoPrize_DrawList(gUnk_03006940);
        }
    }
    else if (gRepeatedKeys & 0x100)
    {
        if (gUnk_0300696C != 2)
        {
            gUnk_0300696C = 2;
            return;
        }
        if (gUnk_0300696C + sTop < gUnknown_0878FEA8[set][0] - 2)
            sTop += 3;
        else
            sTop = gUnknown_0878FEA8[set][0] - 2;
        CasinoPrize_DrawList(gUnk_03006940);
    }
    else if (gRepeatedKeys & 0x40)
    {
        if (gUnk_0300696C != 0)
            gUnk_0300696C--;
        else
        {
            if (sTop == 0)
                return;
            sTop--;
            CasinoPrize_DrawList(gUnk_03006940);
        }
    }
    else if (gRepeatedKeys & 0x80)
    {
        if (gUnk_0300696C == 2)
        {
            if (gUnk_0300696C + sTop >= gUnknown_0878FEA8[set][0])
                return;
            sTop++;
            CasinoPrize_DrawList(gUnk_03006940);
        }
        else
            gUnk_0300696C++;
    }
    else
        goto buttons;
    Sound_Play(100);
    return;
buttons:
    {
        if (gNewKeys & 1)
        {
            task->result = 1;
            gScriptWaitState = price;
            gScriptItemCheckId = gUnknown_0878FEA8[set][(gUnk_0300696C + sTop) * 2 + 1];
            price = gUnknown_0878FEA8[set][(gUnk_0300696C + sTop) * 2 + 2];
            if (price == 0xFFFF)
                price = 100000;
            if (sub_080C31F0() < price)
            {
                gScriptJumpTarget = gUnk_0203DAC8[0];
                Sound_Play(0x66);
            }
            else if ((u8)Inventory_GetCount(gScriptItemCheckId)
                         + Party_CountEquipped(0xFF, gScriptItemCheckId) > 98)
            {
                gScriptJumpTarget = gUnk_0203DAC8[1];
                Sound_Play(0x66);
            }
            else
            {
                Inventory_AddItem(gScriptItemCheckId);
                sub_080C31B4(-price);
                gScriptJumpTarget = gUnk_0203DAC8[2];
                Sound_Play(0x65);
            }
        }
        else if (gNewKeys & 2)
        {
            task->result = 1;
            gScriptWaitState = 0;
            Sound_Play(0x66);
        }
    }
}
#else
NAKED
void CasinoPrize_ExchangeInput(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sb\n"
        "    mov r6, r8\n"
        "    push {r6, r7}\n"
        "    mov r8, r0\n"
        "    movs r6, #0\n"
        "    bl CasinoPrize_GetSet\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    mov ip, r7\n"
        "    ldr r0, .L08131488\n"
        "    mov sb, r0\n"
        "    ldr r4, .L0813148C\n"
        "    ldr r5, .L08131490\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r5, r2]\n"
        "    lsls r1, r1, #2\n"
        "    ldr r2, .L08131494\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r2, r3]\n"
        "    lsls r0, r0, #5\n"
        "    adds r1, r1, r0\n"
        "    adds r1, r1, r4\n"
        "    ldrh r0, [r1]\n"
        "    subs r0, #2\n"
        "    mov r1, sb\n"
        "    strh r0, [r1]\n"
        "    ldr r3, .L08131498\n"
        "    mov sb, r3\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r5, r1]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #1\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r2, r3]\n"
        "    lsls r1, r1, #5\n"
        "    adds r0, r0, r1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    mov r1, sb\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L0813149C\n"
        "    movs r0, #0x17\n"
        "    strh r0, [r1]\n"
        "    ldrh r3, [r5]\n"
        "    movs r0, #0\n"
        "    ldrsh r2, [r5, r0]\n"
        "    cmp r2, #2\n"
        "    bne .L0813146A\n"
        "    movs r0, #0x16\n"
        "    strh r0, [r1]\n"
        ".L0813146A:\n"
        "    ldr r1, .L081314A0\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L081314A4\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L081314CA\n"
        "    cmp r2, #0\n"
        "    beq .L081314A8\n"
        "    strh r6, [r5]\n"
        "    b .L08131580\n"
        "    .byte 0x00, 0x00\n"
        ".L08131488: .4byte 0x0300689C @ IWRAM+0x689C\n"
        ".L0813148C: .4byte gUnknown_0878FBA4\n"
        ".L08131490: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L08131494: .4byte 0x03006844 @ IWRAM+0x6844\n"
        ".L08131498: .4byte 0x0300695C @ IWRAM+0x695C\n"
        ".L0813149C: .4byte 0x030066A0 @ IWRAM+0x66A0\n"
        ".L081314A0: .4byte 0x03006958 @ IWRAM+0x6958\n"
        ".L081314A4: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L081314A8:\n"
        "    ldr r1, .L081314BC\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r1, r2]\n"
        "    subs r0, #3\n"
        "    cmp r0, #0\n"
        "    blt .L081314C0\n"
        "    ldrh r0, [r1]\n"
        "    subs r0, #3\n"
        "    strh r0, [r1]\n"
        "    b .L081314C2\n"
        ".L081314BC: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L081314C0:\n"
        "    strh r6, [r1]\n"
        ".L081314C2:\n"
        "    ldrh r0, [r1]\n"
        "    bl CasinoPrize_DrawList\n"
        "    b .L08131580\n"
        ".L081314CA:\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08131510\n"
        "    cmp r2, #2\n"
        "    beq .L081314DE\n"
        "    movs r0, #2\n"
        "    strh r0, [r5]\n"
        "    b .L08131684\n"
        ".L081314DE:\n"
        "    movs r3, #0\n"
        "    ldrsh r2, [r5, r3]\n"
        "    ldr r3, .L08131508\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r3, r5]\n"
        "    adds r2, r2, r0\n"
        "    ldr r1, .L0813150C\n"
        "    lsls r0, r7, #5\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    subs r0, #2\n"
        "    adds r1, r3, #0\n"
        "    cmp r2, r0\n"
        "    bge .L081314FE\n"
        "    ldrh r0, [r1]\n"
        "    adds r0, #3\n"
        ".L081314FE:\n"
        "    strh r0, [r1]\n"
        "    ldrh r0, [r1]\n"
        "    bl CasinoPrize_DrawList\n"
        "    b .L08131580\n"
        ".L08131508: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0813150C: .4byte gUnknown_0878FEA8\n"
        ".L08131510:\n"
        "    movs r0, #0x40\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08131540\n"
        "    cmp r2, #0\n"
        "    beq .L08131520\n"
        "    subs r0, r3, #1\n"
        "    b .L0813157E\n"
        ".L08131520:\n"
        "    ldr r1, .L0813153C\n"
        "    ldrh r2, [r1]\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r1, r3]\n"
        "    cmp r0, #0\n"
        "    bne .L0813152E\n"
        "    b .L08131684\n"
        ".L0813152E:\n"
        "    subs r0, r2, #1\n"
        "    strh r0, [r1]\n"
        "    ldrh r0, [r1]\n"
        "    bl CasinoPrize_DrawList\n"
        "    b .L08131580\n"
        "    .byte 0x00, 0x00\n"
        ".L0813153C: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08131540:\n"
        "    movs r0, #0x80\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08131588\n"
        "    cmp r2, #2\n"
        "    bne .L0813157C\n"
        "    movs r0, #0\n"
        "    ldrsh r1, [r5, r0]\n"
        "    ldr r3, .L08131574\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r3, r2]\n"
        "    adds r1, r1, r0\n"
        "    ldr r2, .L08131578\n"
        "    lsls r0, r7, #5\n"
        "    adds r0, r0, r2\n"
        "    ldrh r0, [r0]\n"
        "    cmp r1, r0\n"
        "    blt .L08131566\n"
        "    b .L08131684\n"
        ".L08131566:\n"
        "    ldrh r0, [r3]\n"
        "    adds r0, #1\n"
        "    strh r0, [r3]\n"
        "    ldrh r0, [r3]\n"
        "    bl CasinoPrize_DrawList\n"
        "    b .L08131580\n"
        ".L08131574: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08131578: .4byte gUnknown_0878FEA8\n"
        ".L0813157C:\n"
        "    adds r0, r3, #1\n"
        ".L0813157E:\n"
        "    strh r0, [r5]\n"
        ".L08131580:\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        "    b .L08131684\n"
        ".L08131588:\n"
        "    ldr r1, .L081315EC\n"
        "    ldrh r0, [r1]\n"
        "    movs r3, #1\n"
        "    adds r2, r3, #0\n"
        "    ands r2, r0\n"
        "    cmp r2, #0\n"
        "    beq .L0813166C\n"
        "    mov r0, r8\n"
        "    strh r3, [r0, #0x1c]\n"
        "    ldr r0, .L081315F0\n"
        "    strh r6, [r0]\n"
        "    ldr r7, .L081315F4\n"
        "    ldr r4, .L081315F8\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r5, r1]\n"
        "    ldr r3, .L081315FC\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r3, r2]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #1\n"
        "    mov r1, ip\n"
        "    lsls r2, r1, #5\n"
        "    adds r0, r0, r2\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r7]\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r5, r1]\n"
        "    movs r5, #0\n"
        "    ldrsh r1, [r3, r5]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, #4\n"
        "    adds r0, r0, r2\n"
        "    adds r0, r0, r4\n"
        "    ldrh r6, [r0]\n"
        "    ldr r0, .L08131600\n"
        "    cmp r6, r0\n"
        "    bne .L081315DC\n"
        "    ldr r6, .L08131604\n"
        ".L081315DC:\n"
        "    bl sub_080C31F0\n"
        "    cmp r0, r6\n"
        "    bhs .L08131610\n"
        "    ldr r0, .L08131608\n"
        "    ldr r1, .L0813160C\n"
        "    ldr r1, [r1]\n"
        "    b .L08131634\n"
        ".L081315EC: .4byte 0x030031C4 @ IWRAM+0x31C4\n"
        ".L081315F0: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L081315F4: .4byte 0x0203DB50 @ EWRAM+0x3DB50\n"
        ".L081315F8: .4byte gUnknown_0878FEA8\n"
        ".L081315FC: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08131600: .4byte 0x0000FFFF\n"
        ".L08131604: .4byte 0x000186A0\n"
        ".L08131608: .4byte 0x030068E4 @ IWRAM+0x68E4\n"
        ".L0813160C: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8\n"
        ".L08131610:\n"
        "    ldrh r0, [r7]\n"
        "    bl Inventory_GetCount\n"
        "    adds r4, r0, #0\n"
        "    ldrh r1, [r7]\n"
        "    movs r0, #0xff\n"
        "    bl Party_CountEquipped\n"
        "    lsls r4, r4, #0x18\n"
        "    lsrs r4, r4, #0x18\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    adds r4, r4, r0\n"
        "    cmp r4, #0x62\n"
        "    ble .L08131648\n"
        "    ldr r0, .L08131640\n"
        "    ldr r1, .L08131644\n"
        "    ldr r1, [r1, #4]\n"
        ".L08131634:\n"
        "    str r1, [r0]\n"
        "    movs r0, #0x66\n"
        "    bl Sound_Play\n"
        "    b .L08131684\n"
        "    .byte 0x00, 0x00\n"
        ".L08131640: .4byte 0x030068E4 @ IWRAM+0x68E4\n"
        ".L08131644: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8\n"
        ".L08131648:\n"
        "    ldrh r0, [r7]\n"
        "    bl Inventory_AddItem\n"
        "    rsbs r0, r6, #0\n"
        "    bl sub_080C31B4\n"
        "    ldr r1, .L08131664\n"
        "    ldr r0, .L08131668\n"
        "    ldr r0, [r0, #8]\n"
        "    str r0, [r1]\n"
        "    movs r0, #0x65\n"
        "    bl Sound_Play\n"
        "    b .L08131684\n"
        ".L08131664: .4byte 0x030068E4 @ IWRAM+0x68E4\n"
        ".L08131668: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8\n"
        ".L0813166C:\n"
        "    ldrh r1, [r1]\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08131684\n"
        "    mov r0, r8\n"
        "    strh r3, [r0, #0x1c]\n"
        "    ldr r0, .L08131690\n"
        "    strh r2, [r0]\n"
        "    movs r0, #0x66\n"
        "    bl Sound_Play\n"
        ".L08131684:\n"
        "    pop {r3, r4}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L08131690: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
    );
}
#endif
