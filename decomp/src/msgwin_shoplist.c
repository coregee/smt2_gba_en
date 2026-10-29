/* Script message window: the shop's item list (buy and sell). */

#include "global.h"
#include "bmenu2.h"

extern u16 gShopItemIds[];     /* item ids of the list */
extern u32 gShopItemPrices[];     /* sale price of each list entry */
extern u16 gUnk_030069A8;       /* chosen item */
extern s16 gUnk_030065FC;       /* quantity */
extern u32 gUnk_0203DB2C;
extern u16 gScriptItemCheckId;
extern u16 gUnk_03006920[];
extern u16 gUnk_0300699C;
extern u16 gMsgGlyphList2Count;

void Shop_InitItemList(u16 top, u16 showOwned);
void sub_080D34A4(struct Task *task, u32 a, s16 b, u16 item);
u32 sub_080C4C60(u16 item);

#define ROW (*(s16 *)&gUnk_0300696C)
#define TOP (*(s16 *)&gUnk_03006940)
#define COUNT gUnk_03006688

/* Wait handler of the shop list (wait state 0x28 sell, else buy; 3 rows on screen, row
   0x0300696C, first entry 0x03006940, 0x03006688 entries in 0x0203BB74). Up/down move the
   cursor and scroll at the ends (wrapping when everything fits), L/R move a page; each move
   redraws the description (sub_080D34A4) and the list (Shop_InitItemList, which also draws the
   owned-count header when 0x030065E4 is set). SELECT toggles that header: see
   engine/script/patch_shopowned.py, which hooks Shop_InitItemList and sub_081305D8 for it.
   A on a sale: wait state 0x29, or 0x23 with the script's 3rd target (money would pass
   999,999). A on a purchase: wait state 0x23 and the quantity window with quantity 1 and the
   price in gUnk_0203DB2C, or the 3rd target (99 owned) / 1st target (too little money).
   B leaves (wait state 0x24, or 0 and the 2nd target when selling). */
/* NONMATCHING: the original repeats the redraw calls in most branches instead of sharing
   them (0x5A4 bytes against 0x490 here); the logic is the same. */
// Shop_ListInput @ 0x08130694
#ifdef NONMATCHING
void Shop_ListInput(struct Task *task)
{
    u16 id;
    u32 price;

    gUnk_0300689C = gUnknown_0878FCC4[ROW * 2] + 14;
    gUnk_0300695C = gUnknown_0878FCC4[ROW * 2 + 1];
    gUnk_030066A0 = 0x13;
    gUnk_03006958 = 1;
    if ((s16)gUnk_030068D4 != 0)
    {
        gUnk_030068D4--;
        return;
    }
    if (gNewKeys & 4)
    {
        gUnk_030065E4 ^= 1;
        Shop_InitItemList(gUnk_03006940, gUnk_030065E4);
        gUnk_030068D4 = 1;
        return;
    }
    if (gRepeatedKeys & 0x200)
    {
        if (ROW != 0)
        {
            ROW = 0;
            goto redraw;
        }
        if (TOP - 3 >= 0)
        {
            TOP -= 3;
            goto redraw;
        }
        if (TOP == 0)
            goto list;
        TOP = ROW;
        goto redraw;
    }
    else if (gRepeatedKeys & 0x100)
    {
        if (ROW != 2)
        {
            if (COUNT <= 2)
                ROW = COUNT - 1;
            else
                ROW = 2;
            Sound_Play(100);
            sub_080D34A4(gUnk_030068A4, 1, gUnk_03006898, gShopItemIds[ROW + TOP]);
            goto list;
        }
        if (ROW + TOP < COUNT - 3)
        {
            TOP += 3;
            goto redraw;
        }
        if (TOP == COUNT - 3)
            goto list;
        TOP = COUNT - 3;
        goto redraw;
    }
    else if (gRepeatedKeys & 0x40)
    {
        if (ROW != 0)
            ROW--;
        else if (TOP != 0)
            TOP--;
        else if (COUNT > 3)
            goto list;
        else
            ROW = COUNT - 1;
        goto redraw;
    }
    else if (gRepeatedKeys & 0x80)
    {
        if (ROW == 2)
        {
            if (COUNT == 3)
                ROW = 0;
            else if (ROW + TOP < COUNT - 1)
                TOP++;
            else
                goto list;
        }
        else if (COUNT <= 2 && ROW >= COUNT - 1)
            ROW = 0;
        else
            ROW++;
        goto redraw;
    }
    else if (gNewKeys & 1)
    {
        task->result = 1;
        sub_080D34F0(gUnk_030068A4);
        if ((s16)gScriptWaitState == 0x28)
        {
            gScriptWaitState = 0x29;
            gUnk_030069A8 = gShopItemIds[ROW + TOP];
            if (Money_Get() + gShopItemPrices[ROW + TOP] <= 999999)
            {
                Sound_Play(0x65);
                return;
            }
            gUnk_0203DAC8[4] = gUnk_0203DAC8[2];
            gScriptWaitState = 0x23;
        }
        else
        {
            gScriptWaitState = 0x23;
            id = gShopItemIds[ROW + TOP];
            if ((u8)Inventory_GetCount(id) + Party_CountEquipped(0xFF, id) > 98)
                gUnk_0203DAC8[4] = gUnk_0203DAC8[2];
            else if ((price = sub_080C4C60(id)) > Money_Get())
                gUnk_0203DAC8[4] = gUnk_0203DAC8[0];
            else
            {
                gUnk_0203DAC8[4] = 0;
                gUnk_030069A8 = id;
                gUnk_030065FC = 1;
                gUnk_0203DB2C = sub_080C4C60(gUnk_030069A8);
                gScriptItemCheckId = gUnk_030069A8;
                gUnk_03006920[8] = 0;
                gUnk_03006920[4] = 0;
                gUnk_03006920[0] = 0;
                gUnk_03006620[32] = 0;
                gUnk_03006620[24] = 0;
                gUnk_03006620[16] = 0;
                gUnk_03006620[8] = 0;
                gUnk_03006620[0] = 0;
                gUnk_0300699C = 0;
                gMsgGlyphList2Count = 0;
                sub_080D34F0(gUnk_030068A4);
                gUnk_03006958 = 0;
                Sound_Play(0x65);
                return;
            }
        }
        gUnk_03006958 = 0;
        Sound_Play(0x66);
        return;
    }
    else if (gNewKeys & 2)
    {
        task->result = 1;
        if ((s16)gScriptWaitState == 0x28)
        {
            gScriptWaitState = 0;
            gScriptJumpTarget = gUnk_0203DAC8[1];
        }
        else
            gScriptWaitState = 0x24;
        gUnk_0300699C = 0;
        gUnk_03006920[8] = 0;
        gUnk_03006920[4] = 0;
        gUnk_03006920[0] = 0;
        gUnk_03006620[32] = 0;
        gUnk_03006620[24] = 0;
        gUnk_03006620[16] = 0;
        gUnk_03006620[8] = 0;
        gUnk_03006620[0] = 0;
        gUnk_03006958 = 0;
        sub_080D34F0(gUnk_030068A4);
        Sound_Play(0x66);
        return;
    }
    else
        return;
redraw:
    sub_080D34A4(gUnk_030068A4, 1, gUnk_03006898, gShopItemIds[ROW + TOP]);
    Sound_Play(100);
list:
    Shop_InitItemList(gUnk_03006940, gUnk_030065E4);
    gUnk_030068D4 = 1;
}
#else
NAKED
void Shop_ListInput(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    adds r7, r0, #0\n"
        "    ldr r1, .L081306E8\n"
        "    ldr r2, .L081306EC\n"
        "    ldr r6, .L081306F0\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r6, r3]\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r0, r2\n"
        "    ldrh r0, [r0]\n"
        "    adds r0, #0xe\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L081306F4\n"
        "    movs r4, #0\n"
        "    ldrsh r0, [r6, r4]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L081306F8\n"
        "    movs r0, #0x13\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L081306FC\n"
        "    movs r5, #1\n"
        "    strh r5, [r1]\n"
        "    ldr r4, .L08130700\n"
        "    ldrh r2, [r4]\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r4, r3]\n"
        "    mov r8, r6\n"
        "    mov sb, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08130704\n"
        "    subs r0, r2, #1\n"
        "    strh r0, [r4]\n"
        "    b .L08130C1A\n"
        ".L081306E8: .4byte 0x0300689C @ IWRAM+0x689C\n"
        ".L081306EC: .4byte gUnknown_0878FCC4\n"
        ".L081306F0: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L081306F4: .4byte 0x0300695C @ IWRAM+0x695C\n"
        ".L081306F8: .4byte 0x030066A0 @ IWRAM+0x66A0\n"
        ".L081306FC: .4byte 0x03006958 @ IWRAM+0x6958\n"
        ".L08130700: .4byte 0x030068D4 @ IWRAM+0x68D4\n"
        ".L08130704:\n"
        "    ldr r3, .L0813072C\n"
        "    ldrh r1, [r3]\n"
        "    movs r0, #4\n"
        "    ands r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #0\n"
        "    beq .L08130738\n"
        "    ldr r1, .L08130730\n"
        "    ldrh r0, [r1]\n"
        "    eors r0, r5\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L08130734\n"
        "    ldrh r0, [r0]\n"
        "    ldrh r1, [r1]\n"
        "    bl Shop_InitItemList\n"
        "    strh r5, [r4]\n"
        "    b .L08130C1A\n"
        "    .byte 0x00, 0x00\n"
        ".L0813072C: .4byte 0x030031C4 @ IWRAM+0x31C4\n"
        ".L08130730: .4byte 0x030065E4 @ IWRAM+0x65E4\n"
        ".L08130734: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08130738:\n"
        "    ldr r0, .L08130768\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L081307C0\n"
        "    movs r4, #0\n"
        "    ldrsh r1, [r6, r4]\n"
        "    cmp r1, #0\n"
        "    beq .L0813077C\n"
        "    strh r2, [r6]\n"
        "    ldr r0, .L0813076C\n"
        "    ldr r0, [r0]\n"
        "    ldr r1, .L08130770\n"
        "    ldrh r2, [r1]\n"
        "    ldr r3, .L08130774\n"
        "    ldr r1, .L08130778\n"
        "    movs r5, #0\n"
        "    ldrsh r1, [r1, r5]\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r3\n"
        "    b .L08130990\n"
        "    .byte 0x00, 0x00\n"
        ".L08130768: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L0813076C: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L08130770: .4byte 0x03006898 @ IWRAM+0x6898\n"
        ".L08130774: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L08130778: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0813077C:\n"
        "    ldr r3, .L08130790\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r3, r2]\n"
        "    subs r0, #3\n"
        "    cmp r0, #0\n"
        "    blt .L08130794\n"
        "    ldrh r0, [r3]\n"
        "    subs r0, #3\n"
        "    b .L08130976\n"
        "    .byte 0x00, 0x00\n"
        ".L08130790: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08130794:\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r3, r2]\n"
        "    cmp r0, #0\n"
        "    bne .L0813079E\n"
        "    b .L081309FA\n"
        ".L0813079E:\n"
        "    strh r1, [r3]\n"
        "    ldr r0, .L081307B4\n"
        "    ldr r0, [r0]\n"
        "    ldr r1, .L081307B8\n"
        "    ldrh r2, [r1]\n"
        "    ldr r3, .L081307BC\n"
        "    movs r4, #0\n"
        "    ldrsh r1, [r6, r4]\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r3\n"
        "    b .L081309EC\n"
        ".L081307B4: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L081307B8: .4byte 0x03006898 @ IWRAM+0x6898\n"
        ".L081307BC: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L081307C0:\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08130880\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r6, r5]\n"
        "    cmp r0, #2\n"
        "    beq .L0813082C\n"
        "    ldr r0, .L081307E4\n"
        "    ldrh r1, [r0]\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r0, r2]\n"
        "    cmp r0, #2\n"
        "    bgt .L081307E8\n"
        "    subs r0, r1, #1\n"
        "    b .L081307EA\n"
        "    .byte 0x00, 0x00\n"
        ".L081307E4: .4byte 0x03006688 @ IWRAM+0x6688\n"
        ".L081307E8:\n"
        "    movs r0, #2\n"
        ".L081307EA:\n"
        "    strh r0, [r6]\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        "    ldr r0, .L08130818\n"
        "    ldr r0, [r0]\n"
        "    ldr r1, .L0813081C\n"
        "    ldrh r2, [r1]\n"
        "    ldr r4, .L08130820\n"
        "    ldr r1, .L08130824\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r1, r3]\n"
        "    ldr r3, .L08130828\n"
        "    movs r5, #0\n"
        "    ldrsh r3, [r3, r5]\n"
        "    adds r1, r1, r3\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r4\n"
        "    ldrh r3, [r1]\n"
        "    movs r1, #1\n"
        "    bl sub_080D34A4\n"
        "    b .L081309FA\n"
        ".L08130818: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L0813081C: .4byte 0x03006898 @ IWRAM+0x6898\n"
        ".L08130820: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L08130824: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L08130828: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0813082C:\n"
        "    movs r0, #0\n"
        "    ldrsh r1, [r6, r0]\n"
        "    ldr r3, .L0813084C\n"
        "    movs r4, #0\n"
        "    ldrsh r2, [r3, r4]\n"
        "    adds r1, r1, r2\n"
        "    ldr r4, .L08130850\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r4, r5]\n"
        "    subs r0, #3\n"
        "    cmp r1, r0\n"
        "    bge .L08130854\n"
        "    ldrh r0, [r3]\n"
        "    adds r0, #3\n"
        "    b .L08130976\n"
        "    .byte 0x00, 0x00\n"
        ".L0813084C: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08130850: .4byte 0x03006688 @ IWRAM+0x6688\n"
        ".L08130854:\n"
        "    cmp r2, r0\n"
        "    bne .L0813085A\n"
        "    b .L081309FA\n"
        ".L0813085A:\n"
        "    ldrh r0, [r4]\n"
        "    subs r0, #3\n"
        "    strh r0, [r3]\n"
        "    ldr r0, .L08130874\n"
        "    ldr r0, [r0]\n"
        "    ldr r1, .L08130878\n"
        "    ldrh r2, [r1]\n"
        "    ldr r4, .L0813087C\n"
        "    movs r5, #0\n"
        "    ldrsh r1, [r6, r5]\n"
        "    movs r6, #0\n"
        "    ldrsh r3, [r3, r6]\n"
        "    b .L081309E6\n"
        ".L08130874: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L08130878: .4byte 0x03006898 @ IWRAM+0x6898\n"
        ".L0813087C: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L08130880:\n"
        "    movs r0, #0x40\n"
        "    ands r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #0\n"
        "    beq .L0813090C\n"
        "    ldrh r1, [r6]\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r6, r2]\n"
        "    cmp r0, #0\n"
        "    beq .L081308C0\n"
        "    subs r0, r1, #1\n"
        "    strh r0, [r6]\n"
        "    ldr r0, .L081308B0\n"
        "    ldr r0, [r0]\n"
        "    ldr r1, .L081308B4\n"
        "    ldrh r2, [r1]\n"
        "    ldr r4, .L081308B8\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r6, r3]\n"
        "    ldr r3, .L081308BC\n"
        "    movs r5, #0\n"
        "    ldrsh r3, [r3, r5]\n"
        "    b .L0813098A\n"
        ".L081308B0: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L081308B4: .4byte 0x03006898 @ IWRAM+0x6898\n"
        ".L081308B8: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L081308BC: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L081308C0:\n"
        "    ldr r3, .L081308D0\n"
        "    ldrh r1, [r3]\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r3, r2]\n"
        "    cmp r0, #0\n"
        "    beq .L081308D4\n"
        "    subs r0, r1, #1\n"
        "    b .L08130976\n"
        ".L081308D0: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L081308D4:\n"
        "    ldr r0, .L081308FC\n"
        "    ldrh r1, [r0]\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r0, r2]\n"
        "    cmp r0, #3\n"
        "    ble .L081308E2\n"
        "    b .L081309FA\n"
        ".L081308E2:\n"
        "    subs r0, r1, #1\n"
        "    strh r0, [r6]\n"
        "    ldr r0, .L08130900\n"
        "    ldr r0, [r0]\n"
        "    ldr r1, .L08130904\n"
        "    ldrh r2, [r1]\n"
        "    ldr r4, .L08130908\n"
        "    movs r5, #0\n"
        "    ldrsh r1, [r6, r5]\n"
        "    movs r6, #0\n"
        "    ldrsh r3, [r3, r6]\n"
        "    b .L081309E6\n"
        "    .byte 0x00, 0x00\n"
        ".L081308FC: .4byte 0x03006688 @ IWRAM+0x6688\n"
        ".L08130900: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L08130904: .4byte 0x03006898 @ IWRAM+0x6898\n"
        ".L08130908: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L0813090C:\n"
        "    movs r0, #0x80\n"
        "    ands r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #0\n"
        "    bne .L0813091A\n"
        "    b .L08130A28\n"
        ".L0813091A:\n"
        "    ldrh r4, [r6]\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r6, r1]\n"
        "    cmp r0, #2\n"
        "    bne .L081309B0\n"
        "    ldr r4, .L08130948\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r4, r3]\n"
        "    cmp r0, #3\n"
        "    bne .L0813095C\n"
        "    strh r2, [r6]\n"
        "    ldr r0, .L0813094C\n"
        "    ldr r0, [r0]\n"
        "    ldr r1, .L08130950\n"
        "    ldrh r2, [r1]\n"
        "    ldr r3, .L08130954\n"
        "    ldr r1, .L08130958\n"
        "    movs r4, #0\n"
        "    ldrsh r1, [r1, r4]\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r3\n"
        "    b .L08130990\n"
        "    .byte 0x00, 0x00\n"
        ".L08130948: .4byte 0x03006688 @ IWRAM+0x6688\n"
        ".L0813094C: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L08130950: .4byte 0x03006898 @ IWRAM+0x6898\n"
        ".L08130954: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L08130958: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L0813095C:\n"
        "    movs r5, #0\n"
        "    ldrsh r1, [r6, r5]\n"
        "    ldr r3, .L081309A0\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r3, r2]\n"
        "    adds r1, r1, r0\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r4, r5]\n"
        "    subs r0, #1\n"
        "    cmp r1, r0\n"
        "    bge .L081309FA\n"
        "    ldrh r0, [r3]\n"
        "    adds r0, #1\n"
        ".L08130976:\n"
        "    strh r0, [r3]\n"
        "    ldr r0, .L081309A4\n"
        "    ldr r0, [r0]\n"
        "    ldr r1, .L081309A8\n"
        "    ldrh r2, [r1]\n"
        "    ldr r4, .L081309AC\n"
        "    movs r5, #0\n"
        "    ldrsh r1, [r6, r5]\n"
        "    movs r6, #0\n"
        "    ldrsh r3, [r3, r6]\n"
        ".L0813098A:\n"
        "    adds r1, r1, r3\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r4\n"
        ".L08130990:\n"
        "    ldrh r3, [r1]\n"
        "    movs r1, #1\n"
        "    bl sub_080D34A4\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        "    b .L081309FA\n"
        ".L081309A0: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L081309A4: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L081309A8: .4byte 0x03006898 @ IWRAM+0x6898\n"
        ".L081309AC: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L081309B0:\n"
        "    ldr r3, .L081309C8\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r3, r1]\n"
        "    cmp r0, #2\n"
        "    bgt .L081309CC\n"
        "    movs r5, #0\n"
        "    ldrsh r1, [r6, r5]\n"
        "    subs r0, #1\n"
        "    cmp r1, r0\n"
        "    blt .L081309CC\n"
        "    strh r2, [r6]\n"
        "    b .L081309D0\n"
        ".L081309C8: .4byte 0x03006688 @ IWRAM+0x6688\n"
        ".L081309CC:\n"
        "    adds r0, r4, #1\n"
        "    strh r0, [r6]\n"
        ".L081309D0:\n"
        "    ldr r0, .L08130A10\n"
        "    ldr r0, [r0]\n"
        "    ldr r1, .L08130A14\n"
        "    ldrh r2, [r1]\n"
        "    ldr r4, .L08130A18\n"
        "    mov r6, r8\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r6, r3]\n"
        "    ldr r3, .L08130A1C\n"
        "    movs r5, #0\n"
        "    ldrsh r3, [r3, r5]\n"
        ".L081309E6:\n"
        "    adds r1, r1, r3\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r4\n"
        ".L081309EC:\n"
        "    ldrh r3, [r1]\n"
        "    movs r1, #1\n"
        "    bl sub_080D34A4\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        ".L081309FA:\n"
        "    ldr r0, .L08130A1C\n"
        "    ldrh r0, [r0]\n"
        "    ldr r1, .L08130A20\n"
        "    ldrh r1, [r1]\n"
        "    bl Shop_InitItemList\n"
        "    ldr r1, .L08130A24\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    b .L08130C1A\n"
        "    .byte 0x00, 0x00\n"
        ".L08130A10: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L08130A14: .4byte 0x03006898 @ IWRAM+0x6898\n"
        ".L08130A18: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L08130A1C: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08130A20: .4byte 0x030065E4 @ IWRAM+0x65E4\n"
        ".L08130A24: .4byte 0x030068D4 @ IWRAM+0x68D4\n"
        ".L08130A28:\n"
        "    ldrh r0, [r3]\n"
        "    movs r1, #1\n"
        "    mov r8, r1\n"
        "    mov r2, r8\n"
        "    ands r2, r0\n"
        "    cmp r2, #0\n"
        "    bne .L08130A38\n"
        "    b .L08130BB4\n"
        ".L08130A38:\n"
        "    mov r2, r8\n"
        "    strh r2, [r7, #0x1c]\n"
        "    ldr r3, .L08130AA0\n"
        "    mov sl, r3\n"
        "    ldr r0, [r3]\n"
        "    bl sub_080D34F0\n"
        "    ldr r7, .L08130AA4\n"
        "    movs r4, #0\n"
        "    ldrsh r0, [r7, r4]\n"
        "    cmp r0, #0x28\n"
        "    bne .L08130AC0\n"
        "    movs r0, #0x29\n"
        "    strh r0, [r7]\n"
        "    ldr r0, .L08130AA8\n"
        "    mov r8, r0\n"
        "    ldr r2, .L08130AAC\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r6, r1]\n"
        "    ldr r4, .L08130AB0\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r4, r3]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r0, [r0]\n"
        "    mov r1, r8\n"
        "    strh r0, [r1]\n"
        "    bl Money_Get\n"
        "    ldr r3, .L08130AB4\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r6, r2]\n"
        "    movs r6, #0\n"
        "    ldrsh r2, [r4, r6]\n"
        "    adds r1, r1, r2\n"
        "    lsls r1, r1, #2\n"
        "    adds r1, r1, r3\n"
        "    ldr r1, [r1]\n"
        "    adds r0, r0, r1\n"
        "    ldr r1, .L08130AB8\n"
        "    cmp r0, r1\n"
        "    bls .L08130B82\n"
        "    ldr r0, .L08130ABC\n"
        "    ldr r1, [r0, #8]\n"
        "    str r1, [r0, #0x10]\n"
        "    movs r0, #0x23\n"
        "    strh r0, [r7]\n"
        "    mov r0, sb\n"
        "    strh r5, [r0]\n"
        "    b .L08130B2A\n"
        "    .byte 0x00, 0x00\n"
        ".L08130AA0: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L08130AA4: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L08130AA8: .4byte 0x030069A8 @ IWRAM+0x69A8\n"
        ".L08130AAC: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L08130AB0: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08130AB4: .4byte 0x0203BD74 @ EWRAM+0x3BD74\n"
        ".L08130AB8: .4byte 0x000F423F\n"
        ".L08130ABC: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8\n"
        ".L08130AC0:\n"
        "    movs r0, #0x23\n"
        "    strh r0, [r7]\n"
        "    ldr r2, .L08130B04\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r6, r1]\n"
        "    ldr r1, .L08130B08\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r1, r3]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r6, [r0]\n"
        "    adds r0, r6, #0\n"
        "    bl Inventory_GetCount\n"
        "    adds r4, r0, #0\n"
        "    movs r0, #0xff\n"
        "    adds r1, r6, #0\n"
        "    bl Party_CountEquipped\n"
        "    lsls r4, r4, #0x18\n"
        "    lsrs r4, r4, #0x18\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    adds r4, r4, r0\n"
        "    cmp r4, #0x62\n"
        "    ble .L08130B10\n"
        "    ldr r1, .L08130B0C\n"
        "    ldr r0, [r1, #8]\n"
        "    str r0, [r1, #0x10]\n"
        "    mov r4, sb\n"
        "    strh r5, [r4]\n"
        "    b .L08130B2A\n"
        "    .byte 0x00, 0x00\n"
        ".L08130B04: .4byte 0x0203BB74 @ EWRAM+0x3BB74\n"
        ".L08130B08: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08130B0C: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8\n"
        ".L08130B10:\n"
        "    adds r0, r6, #0\n"
        "    bl sub_080C4C60\n"
        "    adds r4, r0, #0\n"
        "    bl Money_Get\n"
        "    cmp r4, r0\n"
        "    bls .L08130B38\n"
        "    ldr r1, .L08130B34\n"
        "    ldr r0, [r1]\n"
        "    str r0, [r1, #0x10]\n"
        "    mov r6, sb\n"
        "    strh r5, [r6]\n"
        ".L08130B2A:\n"
        "    movs r0, #0x66\n"
        "    bl Sound_Play\n"
        "    b .L08130C1A\n"
        "    .byte 0x00, 0x00\n"
        ".L08130B34: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8\n"
        ".L08130B38:\n"
        "    ldr r0, .L08130B8C\n"
        "    str r5, [r0, #0x10]\n"
        "    ldr r4, .L08130B90\n"
        "    strh r6, [r4]\n"
        "    ldr r0, .L08130B94\n"
        "    mov r1, r8\n"
        "    strh r1, [r0]\n"
        "    ldrh r0, [r4]\n"
        "    bl sub_080C4C60\n"
        "    ldr r1, .L08130B98\n"
        "    str r0, [r1]\n"
        "    ldr r1, .L08130B9C\n"
        "    ldrh r0, [r4]\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L08130BA0\n"
        "    ldr r0, .L08130BA4\n"
        "    strh r5, [r0, #0x10]\n"
        "    strh r5, [r0, #8]\n"
        "    strh r5, [r0]\n"
        "    adds r0, r1, #0\n"
        "    adds r0, #0x40\n"
        "    strh r5, [r0]\n"
        "    strh r5, [r1, #0x30]\n"
        "    strh r5, [r1, #0x20]\n"
        "    strh r5, [r1, #0x10]\n"
        "    strh r5, [r1]\n"
        "    ldr r0, .L08130BA8\n"
        "    strh r5, [r0]\n"
        "    ldr r0, .L08130BAC\n"
        "    strh r5, [r0]\n"
        "    mov r2, sl\n"
        "    ldr r0, [r2]\n"
        "    bl sub_080D34F0\n"
        "    ldr r0, .L08130BB0\n"
        "    strh r5, [r0]\n"
        ".L08130B82:\n"
        "    movs r0, #0x65\n"
        "    bl Sound_Play\n"
        "    b .L08130C1A\n"
        "    .byte 0x00, 0x00\n"
        ".L08130B8C: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8\n"
        ".L08130B90: .4byte 0x030069A8 @ IWRAM+0x69A8\n"
        ".L08130B94: .4byte 0x030065FC @ IWRAM+0x65FC\n"
        ".L08130B98: .4byte 0x0203DB2C @ EWRAM+0x3DB2C\n"
        ".L08130B9C: .4byte 0x0203DB50 @ EWRAM+0x3DB50\n"
        ".L08130BA0: .4byte 0x03006620 @ IWRAM+0x6620\n"
        ".L08130BA4: .4byte 0x03006920 @ IWRAM+0x6920\n"
        ".L08130BA8: .4byte 0x0300699C @ IWRAM+0x699C\n"
        ".L08130BAC: .4byte 0x0300669C @ IWRAM+0x669C\n"
        ".L08130BB0: .4byte 0x03006958 @ IWRAM+0x6958\n"
        ".L08130BB4:\n"
        "    ldrh r1, [r3]\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08130C1A\n"
        "    mov r3, r8\n"
        "    strh r3, [r7, #0x1c]\n"
        "    ldr r1, .L08130BD8\n"
        "    movs r4, #0\n"
        "    ldrsh r0, [r1, r4]\n"
        "    cmp r0, #0x28\n"
        "    bne .L08130BE4\n"
        "    strh r2, [r1]\n"
        "    ldr r0, .L08130BDC\n"
        "    ldr r1, .L08130BE0\n"
        "    ldr r1, [r1, #4]\n"
        "    str r1, [r0]\n"
        "    b .L08130BE8\n"
        ".L08130BD8: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L08130BDC: .4byte 0x030068E4 @ IWRAM+0x68E4\n"
        ".L08130BE0: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8\n"
        ".L08130BE4:\n"
        "    movs r0, #0x24\n"
        "    strh r0, [r1]\n"
        ".L08130BE8:\n"
        "    ldr r1, .L08130C28\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r2, .L08130C2C\n"
        "    ldr r1, .L08130C30\n"
        "    movs r0, #0\n"
        "    strh r0, [r1, #0x10]\n"
        "    strh r0, [r1, #8]\n"
        "    strh r0, [r1]\n"
        "    adds r1, r2, #0\n"
        "    adds r1, #0x40\n"
        "    strh r0, [r1]\n"
        "    strh r0, [r2, #0x30]\n"
        "    strh r0, [r2, #0x20]\n"
        "    strh r0, [r2, #0x10]\n"
        "    strh r0, [r2]\n"
        "    mov r5, sb\n"
        "    strh r0, [r5]\n"
        "    ldr r0, .L08130C34\n"
        "    ldr r0, [r0]\n"
        "    bl sub_080D34F0\n"
        "    movs r0, #0x66\n"
        "    bl Sound_Play\n"
        ".L08130C1A:\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L08130C28: .4byte 0x0300699C @ IWRAM+0x699C\n"
        ".L08130C2C: .4byte 0x03006620 @ IWRAM+0x6620\n"
        ".L08130C30: .4byte 0x03006920 @ IWRAM+0x6920\n"
        ".L08130C34: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
    );
}
#endif
