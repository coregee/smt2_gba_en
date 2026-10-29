/* Script message window: the shop quantity window's up/down arrows. */

#include "global.h"
#include "bmenu2.h"

extern u32 gUnk_03006694;   /* unit price */
extern u16 gUnk_030069A8;   /* item id */
extern s16 gUnk_030065FC;   /* quantity */

#define ROW ((u16)gUnk_0300696C)

/* Places the "more" (0x03006848) and "fewer" (0x03006680) arrows of the quantity window at
   row 0x0300696C (0 = hidden). Selling (wait state 0x2A) limits the quantity by the items
   owned and the money by 999,999; buying limits it by the money and by 99 owned in all
   (inventory + equipped). 0x030068BC == 1 selects the window layout one tile higher. */
/* NONMATCHING: same logic and branch order, but unit price and money land in swapped
   registers and several arrow stores are tail-merged differently. */
// Shop_UpdateQuantityArrows @ 0x081316FC
#ifdef NONMATCHING
void Shop_UpdateQuantityArrows(void)
{
    u32 money;
    u32 unit;
    u16 equipped;
    u8 owned;

    money = Money_Get();
    unit = gUnk_03006694;
    equipped = Party_CountEquipped(0xFF, gUnk_030069A8);
    owned = Inventory_GetCount(gUnk_030069A8);

    if ((s16)gScriptWaitState == 0x2A)
    {
        if ((s16)gUnk_030068BC == 1)
        {
            if (gUnk_030065FC == 99)
            {
                gUnk_03006848 = 0;
                gUnk_03006680 = ROW * 2 + 2;
            }
            else if (gUnk_030065FC <= 1)
            {
                if ((u8)Inventory_GetCount(gUnk_030069A8) <= 1)
                    gUnk_03006848 = 0;
                else if ((gUnk_030065FC + 1) * unit + money > 999999)
                    gUnk_03006848 = 0;
                else
                    gUnk_03006848 = ROW * 2 + 2;
                gUnk_03006680 = 0;
            }
            else if (gUnk_030065FC < (u8)Inventory_GetCount(gUnk_030069A8))
            {
                if ((gUnk_030065FC + 1) * unit + money > 999999)
                    gUnk_03006848 = 0;
                else
                    gUnk_03006848 = ROW * 2 + 2;
                gUnk_03006680 = ROW * 2 + 2;
            }
            else
            {
                gUnk_03006848 = 0;
                gUnk_03006680 = ROW * 2 + 2;
            }
            return;
        }
        if (gUnk_030065FC <= 89 && gUnk_030065FC != owned
            && gUnk_030065FC + 1 <= (u8)Inventory_GetCount(gUnk_030069A8)
                                        + (u16)Party_CountEquipped(0xFF, gUnk_030069A8))
        {
            if ((gUnk_030065FC + 1) * unit + money > 999999)
                gUnk_03006848 = 0;
            else
                gUnk_03006848 = ROW * 2 + 3;
            gUnk_03006680 = ROW * 2 + 3;
        }
        else
        {
            gUnk_03006848 = 0;
            gUnk_03006680 = ROW * 2 + 3;
        }
        if (gUnk_030065FC == 1)
            gUnk_03006680 = 0;
    }
    else if ((s16)gUnk_030068BC == 1)
    {
        if (gUnk_030065FC == 99)
        {
            gUnk_03006848 = 0;
            gUnk_03006680 = ROW * 2 + 2;
        }
        else if (equipped + owned + (u16)gUnk_030065FC > 98)
        {
            gUnk_03006848 = 0;
            gUnk_03006680 = ROW * 2 + 2;
        }
        else if ((gUnk_030065FC + 1) * unit > money)
        {
            gUnk_03006848 = 0;
            gUnk_03006680 = ROW * 2 + 2;
        }
        else
        {
            gUnk_03006848 = ROW * 2 + 2;
            gUnk_03006680 = ROW * 2 + 2;
        }
        if (gUnk_030065FC <= 1)
            gUnk_03006680 = 0;
    }
    else
    {
        if (gUnk_030065FC == 99)
        {
            gUnk_03006848 = 0;
            gUnk_03006680 = ROW * 2 + 3;
        }
        else if ((gUnk_030065FC + 1) * unit > money)
        {
            gUnk_03006848 = 0;
            gUnk_03006680 = ROW * 2 + 3;
        }
        else if (equipped + owned + (u16)gUnk_030065FC > 98)
        {
            gUnk_03006848 = 0;
            gUnk_03006680 = ROW * 2 + 3;
        }
        else
        {
            gUnk_03006848 = ROW * 2 + 3;
            gUnk_03006680 = ROW * 2 + 3;
        }
        if (gUnk_030065FC == 1)
            gUnk_03006680 = 0;
    }
}
#else
NAKED
void Shop_UpdateQuantityArrows(void)
{
    asm_unified(
        ".L081316FC:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sb\n"
        "    mov r6, r8\n"
        "    push {r6, r7}\n"
        "    bl Money_Get\n"
        "    mov r8, r0\n"
        "    ldr r0, .L08131760\n"
        "    ldr r7, [r0]\n"
        "    ldr r6, .L08131764\n"
        "    ldrh r1, [r6]\n"
        "    movs r0, #0xff\n"
        "    bl Party_CountEquipped\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    adds r5, r4, #0\n"
        "    ldrh r0, [r6]\n"
        "    bl Inventory_GetCount\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r2, r0, #0x18\n"
        "    adds r3, r2, #0\n"
        "    ldr r0, .L08131768\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    cmp r0, #0x2a\n"
        "    beq .L08131736\n"
        "    b .L08131908\n"
        ".L08131736:\n"
        "    ldr r0, .L0813176C\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r0, r3]\n"
        "    cmp r0, #1\n"
        "    beq .L08131742\n"
        "    b .L08131854\n"
        ".L08131742:\n"
        "    ldr r5, .L08131770\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r5, r1]\n"
        "    cmp r0, #0x63\n"
        "    bne .L08131780\n"
        "    ldr r1, .L08131774\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L08131778\n"
        "    ldr r0, .L0813177C\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #2\n"
        "    b .L08131A68\n"
        "    .byte 0x00, 0x00\n"
        ".L08131760: .4byte 0x03006694 @ IWRAM+0x6694\n"
        ".L08131764: .4byte 0x030069A8 @ IWRAM+0x69A8\n"
        ".L08131768: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L0813176C: .4byte 0x030068BC @ IWRAM+0x68BC\n"
        ".L08131770: .4byte 0x030065FC @ IWRAM+0x65FC\n"
        ".L08131774: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L08131778: .4byte 0x03006680 @ IWRAM+0x6680\n"
        ".L0813177C: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L08131780:\n"
        "    cmp r0, #1\n"
        "    bgt .L081317D8\n"
        "    ldrh r0, [r6]\n"
        "    bl Inventory_GetCount\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bhi .L0813179C\n"
        "    ldr r1, .L08131798\n"
        "    movs r0, #0\n"
        "    b .L081317C6\n"
        ".L08131798: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L0813179C:\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r5, r2]\n"
        "    adds r0, #1\n"
        "    muls r0, r7, r0\n"
        "    add r0, r8\n"
        "    ldr r1, .L081317B4\n"
        "    cmp r0, r1\n"
        "    bls .L081317BC\n"
        "    ldr r1, .L081317B8\n"
        "    movs r0, #0\n"
        "    b .L081317C6\n"
        "    .byte 0x00, 0x00\n"
        ".L081317B4: .4byte 0x000F423F\n"
        ".L081317B8: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L081317BC:\n"
        "    ldr r1, .L081317CC\n"
        "    ldr r0, .L081317D0\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #2\n"
        ".L081317C6:\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L081317D4\n"
        "    b .L08131A66\n"
        ".L081317CC: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L081317D0: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L081317D4: .4byte 0x03006680 @ IWRAM+0x6680\n"
        ".L081317D8:\n"
        "    movs r3, #0\n"
        "    ldrsh r4, [r5, r3]\n"
        "    ldrh r0, [r6]\n"
        "    bl Inventory_GetCount\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r4, r0\n"
        "    bge .L08131834\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r5, r1]\n"
        "    adds r0, #1\n"
        "    muls r0, r7, r0\n"
        "    add r0, r8\n"
        "    ldr r1, .L08131804\n"
        "    cmp r0, r1\n"
        "    bls .L08131810\n"
        "    ldr r1, .L08131808\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L0813180C\n"
        "    b .L0813181E\n"
        ".L08131804: .4byte 0x000F423F\n"
        ".L08131808: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L0813180C: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L08131810:\n"
        "    ldr r2, .L08131828\n"
        "    ldr r1, .L0813182C\n"
        "    ldrh r0, [r1]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #2\n"
        "    strh r0, [r2]\n"
        "    adds r0, r1, #0\n"
        ".L0813181E:\n"
        "    ldr r1, .L08131830\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #2\n"
        "    b .L08131A68\n"
        ".L08131828: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L0813182C: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L08131830: .4byte 0x03006680 @ IWRAM+0x6680\n"
        ".L08131834:\n"
        "    ldr r1, .L08131848\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L0813184C\n"
        "    ldr r0, .L08131850\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #2\n"
        "    b .L08131A68\n"
        "    .byte 0x00, 0x00\n"
        ".L08131848: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L0813184C: .4byte 0x03006680 @ IWRAM+0x6680\n"
        ".L08131850: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L08131854:\n"
        "    ldr r0, .L081318A8\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r0, r3]\n"
        "    mov sb, r0\n"
        "    cmp r1, #0x59\n"
        "    bgt .L081318E8\n"
        "    mov r0, sb\n"
        "    movs r1, #0\n"
        "    ldrsh r5, [r0, r1]\n"
        "    cmp r5, r2\n"
        "    beq .L081318E8\n"
        "    adds r5, #1\n"
        "    ldrh r0, [r6]\n"
        "    bl Inventory_GetCount\n"
        "    adds r4, r0, #0\n"
        "    ldrh r1, [r6]\n"
        "    movs r0, #0xff\n"
        "    bl Party_CountEquipped\n"
        "    lsls r4, r4, #0x18\n"
        "    lsrs r4, r4, #0x18\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    adds r4, r4, r0\n"
        "    cmp r5, r4\n"
        "    bgt .L081318E8\n"
        "    mov r2, sb\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r2, r3]\n"
        "    adds r0, #1\n"
        "    muls r0, r7, r0\n"
        "    add r0, r8\n"
        "    ldr r1, .L081318AC\n"
        "    cmp r0, r1\n"
        "    bls .L081318B8\n"
        "    ldr r1, .L081318B0\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L081318B4\n"
        "    b .L081318C6\n"
        "    .byte 0x00, 0x00\n"
        ".L081318A8: .4byte 0x030065FC @ IWRAM+0x65FC\n"
        ".L081318AC: .4byte 0x000F423F\n"
        ".L081318B0: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L081318B4: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L081318B8:\n"
        "    ldr r2, .L081318D8\n"
        "    ldr r1, .L081318DC\n"
        "    ldrh r0, [r1]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #3\n"
        "    strh r0, [r2]\n"
        "    adds r0, r1, #0\n"
        ".L081318C6:\n"
        "    ldr r1, .L081318E0\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #3\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L081318E4\n"
        "    mov sb, r0\n"
        "    b .L08131A5C\n"
        "    .byte 0x00, 0x00\n"
        ".L081318D8: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L081318DC: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L081318E0: .4byte 0x03006680 @ IWRAM+0x6680\n"
        ".L081318E4: .4byte 0x030065FC @ IWRAM+0x65FC\n"
        ".L081318E8:\n"
        "    ldr r1, .L081318FC\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L08131900\n"
        "    ldr r0, .L08131904\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #3\n"
        "    b .L08131A5A\n"
        "    .byte 0x00, 0x00\n"
        ".L081318FC: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L08131900: .4byte 0x03006680 @ IWRAM+0x6680\n"
        ".L08131904: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L08131908:\n"
        "    ldr r0, .L08131930\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    cmp r0, #1\n"
        "    bne .L081319C4\n"
        "    ldr r0, .L08131934\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r0, r3]\n"
        "    mov sb, r0\n"
        "    cmp r1, #0x63\n"
        "    bne .L08131944\n"
        "    ldr r1, .L08131938\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L0813193C\n"
        "    ldr r0, .L08131940\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #2\n"
        "    b .L081319AA\n"
        ".L08131930: .4byte 0x030068BC @ IWRAM+0x68BC\n"
        ".L08131934: .4byte 0x030065FC @ IWRAM+0x65FC\n"
        ".L08131938: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L0813193C: .4byte 0x03006680 @ IWRAM+0x6680\n"
        ".L08131940: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L08131944:\n"
        "    adds r0, r4, r2\n"
        "    mov r1, sb\n"
        "    ldrh r1, [r1]\n"
        "    adds r0, r0, r1\n"
        "    cmp r0, #0x62\n"
        "    ble .L08131970\n"
        "    ldr r1, .L08131964\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L08131968\n"
        "    ldr r0, .L0813196C\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #2\n"
        "    b .L081319AA\n"
        "    .byte 0x00, 0x00\n"
        ".L08131964: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L08131968: .4byte 0x03006680 @ IWRAM+0x6680\n"
        ".L0813196C: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L08131970:\n"
        "    mov r2, sb\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r2, r3]\n"
        "    adds r0, #1\n"
        "    muls r0, r7, r0\n"
        "    cmp r0, r8\n"
        "    bls .L0813199C\n"
        "    ldr r1, .L08131990\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L08131994\n"
        "    ldr r0, .L08131998\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #2\n"
        "    b .L081319AA\n"
        ".L08131990: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L08131994: .4byte 0x03006680 @ IWRAM+0x6680\n"
        ".L08131998: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L0813199C:\n"
        "    ldr r1, .L081319B8\n"
        "    ldr r0, .L081319BC\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #2\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L081319C0\n"
        ".L081319AA:\n"
        "    strh r0, [r1]\n"
        "    mov r2, sb\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r2, r3]\n"
        "    cmp r0, #1\n"
        "    bgt .L08131A6A\n"
        "    b .L08131A66\n"
        ".L081319B8: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L081319BC: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L081319C0: .4byte 0x03006680 @ IWRAM+0x6680\n"
        ".L081319C4:\n"
        "    ldr r0, .L081319E4\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r0, r2]\n"
        "    mov sb, r0\n"
        "    cmp r1, #0x63\n"
        "    bne .L081319F4\n"
        "    ldr r1, .L081319E8\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L081319EC\n"
        "    ldr r0, .L081319F0\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #3\n"
        "    b .L08131A5A\n"
        "    .byte 0x00, 0x00\n"
        ".L081319E4: .4byte 0x030065FC @ IWRAM+0x65FC\n"
        ".L081319E8: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L081319EC: .4byte 0x03006680 @ IWRAM+0x6680\n"
        ".L081319F0: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L081319F4:\n"
        "    mov r1, sb\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r1, r2]\n"
        "    adds r0, #1\n"
        "    muls r0, r7, r0\n"
        "    cmp r0, r8\n"
        "    bls .L08131A20\n"
        "    ldr r1, .L08131A14\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L08131A18\n"
        "    ldr r0, .L08131A1C\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #3\n"
        "    b .L08131A5A\n"
        ".L08131A14: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L08131A18: .4byte 0x03006680 @ IWRAM+0x6680\n"
        ".L08131A1C: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L08131A20:\n"
        "    adds r0, r5, r3\n"
        "    mov r3, sb\n"
        "    ldrh r3, [r3]\n"
        "    adds r0, r0, r3\n"
        "    cmp r0, #0x62\n"
        "    ble .L08131A4C\n"
        "    ldr r1, .L08131A40\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L08131A44\n"
        "    ldr r0, .L08131A48\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #3\n"
        "    b .L08131A5A\n"
        "    .byte 0x00, 0x00\n"
        ".L08131A40: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L08131A44: .4byte 0x03006680 @ IWRAM+0x6680\n"
        ".L08131A48: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L08131A4C:\n"
        "    ldr r1, .L08131A78\n"
        "    ldr r0, .L08131A7C\n"
        "    ldrh r0, [r0]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #3\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L08131A80\n"
        ".L08131A5A:\n"
        "    strh r0, [r1]\n"
        ".L08131A5C:\n"
        "    mov r2, sb\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r2, r3]\n"
        "    cmp r0, #1\n"
        "    bne .L08131A6A\n"
        ".L08131A66:\n"
        "    movs r0, #0\n"
        ".L08131A68:\n"
        "    strh r0, [r1]\n"
        ".L08131A6A:\n"
        "    pop {r3, r4}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L08131A78: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L08131A7C: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L08131A80: .4byte 0x03006680 @ IWRAM+0x6680\n"
    );
}
#endif
