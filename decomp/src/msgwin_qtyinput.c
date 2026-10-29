/* Script message window: the shop's "How many?" quantity input. */

#include "global.h"
#include "bmenu2.h"

extern u32 gUnk_03006694;   /* unit price */
extern u16 gUnk_030069A8;   /* item id */
extern s16 gUnk_030065FC;   /* quantity */
extern u32 gUnk_0203DB2C;   /* total price */
extern u16 gUnk_030068A0;
extern u16 gScriptItemCheckId;
extern u16 gUnk_03006920[];
extern u16 gUnk_0300699C;
extern u16 gMsgGlyphList2Count;

struct MsgPriceSlot     /* gUnk_03006620: number sprites drawn by ScriptVM_DrawTask */
{
    u16 active;
    u16 pad2;
    u32 value;
    u16 unk8;
    u16 y;
    u16 attr;
    u16 padE;
};

void sub_081305D8(u16 item);
void Shop_UpdateQuantityArrows(void);
u32 sub_080C4C7C(u16 item);

#define SLOTS ((struct MsgPriceSlot *)gUnk_03006620)
#define QTY gUnk_030065FC
#define STEP (*(s16 *)&gUnk_030068BC)

/* The quantity is shown as two digit sprites, price slots 3 (ones) and 4 (tens). */
#define SET_DIGITS()                \
{                                   \
    SLOTS[3].value = QTY % 10;      \
    SLOTS[4].value = QTY / 10;      \
}

#define CLEAR_SPRITES()             \
{                                   \
    gUnk_03006920[8] = 0;           \
    gUnk_03006920[4] = 0;           \
    gUnk_03006920[0] = 0;           \
    gUnk_03006620[32] = 0;          \
    gUnk_03006620[24] = 0;          \
    gUnk_03006620[16] = 0;          \
    gUnk_03006620[8] = 0;           \
    gUnk_03006620[0] = 0;           \
}

/* Wait handler of the quantity window. Up adds the step (0x030068BC: 1, or 10 after LEFT;
   RIGHT sets 1 again), clamped to what can be done: selling (wait state 0x2A) stops at the
   items owned and at 999,999 money, buying at 99 owned in all and at the money. Down
   subtracts the step, to at least 1. SELECT toggles the owned-count header (sub_081305D8;
   see engine/script/patch_shopowned.py). The total (unit price * quantity, at most 999,999)
   goes to gUnk_0203DB2C; when selling would reach that cap the window is left with wait
   state 0x47. A confirms (wait state 0x27, or 0x35 for quantity 0; the sale total uses the
   sale price sub_080C4C7C), B cancels (wait state 0x26). */
/* NONMATCHING: same logic; register allocation and branch layout differ (0x5F0 bytes
   against 0x684). */
// Shop_QuantityInput @ 0x08131B1C
#ifdef NONMATCHING
void Shop_QuantityInput(struct Task *task)
{
    u32 money = Money_Get();
    u32 unit = gUnk_03006694;
    u16 equipped = Party_CountEquipped(0xFF, gUnk_030069A8);
    u8 owned = Inventory_GetCount(gUnk_030069A8);
    u32 t;
    u32 n;
    u16 m;

    gUnk_030066A0 = 0x15;
    gUnk_03006958 = 1;
    if ((s16)gUnk_030068D4 != 0)
    {
        gUnk_030068D4--;
        return;
    }
    if (gNewKeys & 4)
    {
        gUnk_030065E4 ^= 1;
        sub_081305D8(gUnk_030069A8);
        return;
    }
    if (gRepeatedKeys & 0x40)
    {
        if ((s16)gScriptWaitState == 0x2A)
        {
            if (QTY * unit + money > 999998)
                goto total;
            if (STEP == 1)
            {
                if (QTY + 1 > owned)
                    QTY = owned;
                else
                {
                    if (unit * (QTY + 1) + money > 999999)
                        goto total;
                    QTY++;
                    if (QTY > 99)
                        QTY = 99;
                }
                SET_DIGITS();
            }
            else if (QTY + 10 > owned)
            {
                if (unit * owned + money > 999999)
                    goto sellFill;
                QTY = owned;
                SET_DIGITS();
            }
            else if (unit * (QTY + 10) + money <= 999999)
            {
                QTY += 10;
                SET_DIGITS();
            }
            else
            {
            sellFill:
                /* as many as the money cap allows, at most 10 more */
                t = QTY * unit;
                n = 0;
                do
                {
                    if (t + money > 999999)
                    {
                        n--;
                        break;
                    }
                    t += unit;
                    n++;
                } while (n < 10);
                QTY += n;
                SET_DIGITS();
            }
            Sound_Play(100);
        }
        else if (QTY != 99)
        {
            if (STEP == 10)
            {
                s32 have = owned + equipped;

                if (have + QTY + 10 < 100)
                {
                    if (unit * (QTY + 10) <= money)
                    {
                        QTY += 10;
                        SET_DIGITS();
                    }
                    else
                        goto buyFill;
                }
                else
                {
                    m = 99 - have;
                    if (m * unit > money)
                        goto buyFill;
                    QTY = m;
                    SLOTS[3].value = (u16)(m % 10);
                    SLOTS[4].value = (u16)(m / 10);
                }
                Sound_Play(100);
                goto total;
            buyFill:
                /* as many as the money allows */
                t = QTY * unit;
                n = 0;
                do
                {
                    m = n;
                    t += unit;
                    n++;
                } while (t <= money);
                QTY += (s16)m;
                SET_DIGITS();
                Sound_Play(100);
            }
            else if (equipped + owned + QTY + STEP < 100 && unit * (QTY + STEP) <= money)
            {
                QTY += STEP;
                SET_DIGITS();
                Sound_Play(100);
            }
        }
    total:
        Shop_UpdateQuantityArrows();
        gUnk_0203DB2C = unit * QTY;
        if (gUnk_0203DB2C > 999999)
        {
            gUnk_0203DB2C = 999999;
            if ((s16)gScriptWaitState == 0x2A)
            {
                gUnk_030068A0 = 0;
                task->result = 1;
                gScriptWaitState = 0x47;
                gUnk_0300699C = 0;
                gMsgGlyphList2Count = 0;
                sub_080D34F0(gUnk_030068A4);
                CLEAR_SPRITES();
                gUnk_03006958 = 0;
                Sound_Play(0x66);
            }
        }
    }
    else if (gRepeatedKeys & 0x80)
    {
        if (STEP == 10 && QTY <= 10)
        {
            QTY = 1;
            SLOTS[3].value = 1;
            SLOTS[4].value = 0;
            Sound_Play(100);
        }
        else if (STEP == 10 || QTY - STEP > 0)
        {
            QTY -= STEP;
            SET_DIGITS();
            Sound_Play(100);
        }
        Shop_UpdateQuantityArrows();
        gUnk_0203DB2C = unit * QTY;
        if (gUnk_0203DB2C > 999999)
            gUnk_0203DB2C = 999999;
    }
    else if (gNewKeys & 0x10)
    {
        STEP = 1;
        Shop_UpdateQuantityArrows();
        Sound_Play(100);
    }
    else if (gNewKeys & 0x20)
    {
        STEP = 10;
        Shop_UpdateQuantityArrows();
        Sound_Play(100);
    }
    else if (gNewKeys & 1)
    {
        task->result = 1;
        if (QTY == 0)
        {
            gUnk_030068A0 = 0;
            gScriptWaitState = 0x35;
            Sound_Play(0x66);
        }
        else
        {
            if ((s16)gScriptWaitState == 0x2A)
            {
                gUnk_0203DB2C = QTY * sub_080C4C7C(gUnk_030069A8);
                if (gUnk_0203DB2C > 999999)
                    gUnk_0203DB2C = 999999;
            }
            else
            {
                gUnk_0203DB2C = unit * QTY;
                if (gUnk_0203DB2C > 999999)
                    gUnk_0203DB2C = 999999;
            }
            Sound_Play(0x65);
            gScriptWaitState = 0x27;
            gScriptItemCheckId = gUnk_030069A8;
        }
        gUnk_0300699C = 0;
        gMsgGlyphList2Count = 0;
        sub_080D34F0(gUnk_030068A4);
        CLEAR_SPRITES();
        gUnk_03006958 = 0;
    }
    else if (gNewKeys & 2)
    {
        gUnk_030068A0 = 0;
        task->result = 1;
        gScriptWaitState = 0x26;
        gMsgGlyphList2Count = 0;
        gUnk_0300699C = 0;
        sub_080D34F0(gUnk_030068A4);
        CLEAR_SPRITES();
        gUnk_03006958 = 0;
        Sound_Play(0x66);
    }
}
#else
NAKED
void Shop_QuantityInput(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #8\n"
        "    str r0, [sp]\n"
        "    bl Money_Get\n"
        "    adds r6, r0, #0\n"
        "    ldr r0, .L08131B78\n"
        "    ldr r7, [r0]\n"
        "    ldr r0, .L08131B7C\n"
        "    mov r8, r0\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0xff\n"
        "    bl Party_CountEquipped\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sb, r0\n"
        "    mov r1, sb\n"
        "    str r1, [sp, #4]\n"
        "    mov r2, r8\n"
        "    ldrh r0, [r2]\n"
        "    bl Inventory_GetCount\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    mov sl, r4\n"
        "    ldr r1, .L08131B80\n"
        "    movs r0, #0x15\n"
        "    strh r0, [r1]\n"
        "    movs r5, #1\n"
        "    ldr r3, .L08131B84\n"
        "    strh r5, [r3]\n"
        "    ldr r1, .L08131B88\n"
        "    ldrh r2, [r1]\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r1, r3]\n"
        "    cmp r0, #0\n"
        "    beq .L08131B8C\n"
        "    subs r0, r2, #1\n"
        "    strh r0, [r1]\n"
        "    b .L0813216E\n"
        "    .byte 0x00, 0x00\n"
        ".L08131B78: .4byte 0x03006694 @ IWRAM+0x6694\n"
        ".L08131B7C: .4byte 0x030069A8 @ IWRAM+0x69A8\n"
        ".L08131B80: .4byte 0x030066A0 @ IWRAM+0x66A0\n"
        ".L08131B84: .4byte 0x03006958 @ IWRAM+0x6958\n"
        ".L08131B88: .4byte 0x030068D4 @ IWRAM+0x68D4\n"
        ".L08131B8C:\n"
        "    ldr r3, .L08131BAC\n"
        "    ldrh r1, [r3]\n"
        "    movs r0, #4\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08131BB4\n"
        "    ldr r0, .L08131BB0\n"
        "    ldrh r1, [r0]\n"
        "    eors r1, r5\n"
        "    strh r1, [r0]\n"
        "    mov r4, r8\n"
        "    ldrh r0, [r4]\n"
        "    bl sub_081305D8\n"
        "    b .L0813216E\n"
        "    .byte 0x00, 0x00\n"
        ".L08131BAC: .4byte 0x030031C4 @ IWRAM+0x31C4\n"
        ".L08131BB0: .4byte 0x030065E4 @ IWRAM+0x65E4\n"
        ".L08131BB4:\n"
        "    ldr r0, .L08131C40\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x40\n"
        "    ands r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #0\n"
        "    bne .L08131BC6\n"
        "    b .L08131F4C\n"
        ".L08131BC6:\n"
        "    ldr r0, .L08131C44\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    cmp r0, #0x2a\n"
        "    beq .L08131BD2\n"
        "    b .L08131D68\n"
        ".L08131BD2:\n"
        "    ldr r0, .L08131C48\n"
        "    movs r2, #0\n"
        "    ldrsh r3, [r0, r2]\n"
        "    adds r1, r7, #0\n"
        "    muls r1, r3, r1\n"
        "    adds r1, r1, r6\n"
        "    ldr r2, .L08131C4C\n"
        "    mov r8, r0\n"
        "    cmp r1, r2\n"
        "    bls .L08131BE8\n"
        "    b .L08131EB4\n"
        ".L08131BE8:\n"
        "    ldr r0, .L08131C50\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    cmp r0, #1\n"
        "    bne .L08131C88\n"
        "    adds r0, r3, #1\n"
        "    cmp r0, r4\n"
        "    bgt .L08131C5C\n"
        "    muls r0, r7, r0\n"
        "    adds r0, r0, r6\n"
        "    ldr r1, .L08131C54\n"
        "    cmp r0, r1\n"
        "    bls .L08131C04\n"
        "    b .L08131EB4\n"
        ".L08131C04:\n"
        "    mov r2, r8\n"
        "    ldrh r0, [r2]\n"
        "    adds r0, #1\n"
        "    strh r0, [r2]\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #0x63\n"
        "    ble .L08131C18\n"
        "    movs r0, #0x63\n"
        "    strh r0, [r2]\n"
        ".L08131C18:\n"
        "    ldr r4, .L08131C58\n"
        "    mov r3, r8\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r3, r1]\n"
        "    movs r1, #0xa\n"
        "    bl __modsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    str r0, [r4, #0x34]\n"
        "    mov r2, r8\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r2, r3]\n"
        "    movs r1, #0xa\n"
        "    bl __divsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    b .L08131E54\n"
        "    .byte 0x00, 0x00\n"
        ".L08131C40: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L08131C44: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L08131C48: .4byte 0x030065FC @ IWRAM+0x65FC\n"
        ".L08131C4C: .4byte 0x000F423E\n"
        ".L08131C50: .4byte 0x030068BC @ IWRAM+0x68BC\n"
        ".L08131C54: .4byte 0x000F423F\n"
        ".L08131C58: .4byte 0x03006620 @ IWRAM+0x6620\n"
        ".L08131C5C:\n"
        "    mov r0, r8\n"
        "    strh r4, [r0]\n"
        "    ldr r4, .L08131C84\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    movs r1, #0xa\n"
        "    bl __modsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    str r0, [r4, #0x34]\n"
        "    mov r2, r8\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r2, r3]\n"
        "    movs r1, #0xa\n"
        "    bl __divsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    b .L08131E54\n"
        ".L08131C84: .4byte 0x03006620 @ IWRAM+0x6620\n"
        ".L08131C88:\n"
        "    adds r0, r3, #0\n"
        "    adds r0, #0xa\n"
        "    cmp r0, r4\n"
        "    bgt .L08131D2C\n"
        "    muls r0, r7, r0\n"
        "    adds r0, r0, r6\n"
        "    ldr r1, .L08131CC8\n"
        "    cmp r0, r1\n"
        "    bhi .L08131CD0\n"
        "    mov r4, r8\n"
        "    ldrh r0, [r4]\n"
        "    adds r0, #0xa\n"
        "    strh r0, [r4]\n"
        "    ldr r4, .L08131CCC\n"
        "    mov r1, r8\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r1, r2]\n"
        "    movs r1, #0xa\n"
        "    bl __modsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    str r0, [r4, #0x34]\n"
        "    mov r3, r8\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r3, r1]\n"
        "    movs r1, #0xa\n"
        "    bl __divsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    b .L08131E54\n"
        ".L08131CC8: .4byte 0x000F423F\n"
        ".L08131CCC: .4byte 0x03006620 @ IWRAM+0x6620\n"
        ".L08131CD0:\n"
        "    mov r2, r8\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r2, r3]\n"
        "    adds r2, r7, #0\n"
        "    muls r2, r0, r2\n"
        "    movs r3, #0\n"
        "    adds r1, r2, r6\n"
        "    ldr r0, .L08131CE4\n"
        "    ldr r4, .L08131CE8\n"
        "    b .L08131CF8\n"
        ".L08131CE4: .4byte 0x000F423F\n"
        ".L08131CE8: .4byte 0x03006620 @ IWRAM+0x6620\n"
        ".L08131CEC:\n"
        "    adds r2, r2, r7\n"
        "    adds r3, #1\n"
        "    cmp r3, #9\n"
        "    bhi .L08131CFE\n"
        "    adds r1, r2, r6\n"
        "    ldr r0, .L08131D28\n"
        ".L08131CF8:\n"
        "    cmp r1, r0\n"
        "    bls .L08131CEC\n"
        "    subs r3, #1\n"
        ".L08131CFE:\n"
        "    mov r1, r8\n"
        "    ldrh r0, [r1]\n"
        "    adds r0, r0, r3\n"
        "    strh r0, [r1]\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r1, r2]\n"
        "    movs r1, #0xa\n"
        "    bl __modsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    str r0, [r4, #0x34]\n"
        "    mov r3, r8\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r3, r1]\n"
        "    movs r1, #0xa\n"
        "    bl __divsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    b .L08131E54\n"
        ".L08131D28: .4byte 0x000F423F\n"
        ".L08131D2C:\n"
        "    adds r0, r4, #0\n"
        "    muls r0, r7, r0\n"
        "    adds r0, r0, r6\n"
        "    ldr r1, .L08131D60\n"
        "    cmp r0, r1\n"
        "    bhi .L08131CD0\n"
        "    mov r2, r8\n"
        "    strh r4, [r2]\n"
        "    ldr r4, .L08131D64\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r2, r3]\n"
        "    movs r1, #0xa\n"
        "    bl __modsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    str r0, [r4, #0x34]\n"
        "    mov r1, r8\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r1, r2]\n"
        "    movs r1, #0xa\n"
        "    bl __divsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    b .L08131E54\n"
        ".L08131D60: .4byte 0x000F423F\n"
        ".L08131D64: .4byte 0x03006620 @ IWRAM+0x6620\n"
        ".L08131D68:\n"
        "    ldr r0, .L08131DD0\n"
        "    ldrh r3, [r0]\n"
        "    mov ip, r3\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r0, r2]\n"
        "    mov r8, r0\n"
        "    cmp r1, #0x63\n"
        "    bne .L08131D7A\n"
        "    b .L08131EB4\n"
        ".L08131D7A:\n"
        "    ldr r1, .L08131DD4\n"
        "    ldrh r5, [r1]\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r1, r3]\n"
        "    cmp r0, #0xa\n"
        "    bne .L08131E64\n"
        "    mov r0, sb\n"
        "    adds r3, r4, r0\n"
        "    mov r4, r8\n"
        "    movs r0, #0\n"
        "    ldrsh r2, [r4, r0]\n"
        "    adds r0, r3, r2\n"
        "    movs r4, #0\n"
        "    ldrsh r1, [r1, r4]\n"
        "    adds r0, r0, r1\n"
        "    cmp r0, #0x63\n"
        "    bgt .L08131E24\n"
        "    adds r0, r2, r1\n"
        "    muls r0, r7, r0\n"
        "    cmp r0, r6\n"
        "    bhi .L08131DDC\n"
        "    mov r1, ip\n"
        "    adds r0, r1, r5\n"
        "    mov r2, r8\n"
        "    strh r0, [r2]\n"
        "    ldr r4, .L08131DD8\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r2, r3]\n"
        "    movs r1, #0xa\n"
        "    bl __modsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    str r0, [r4, #0x34]\n"
        "    mov r1, r8\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r1, r2]\n"
        "    movs r1, #0xa\n"
        "    bl __divsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    b .L08131E54\n"
        ".L08131DD0: .4byte 0x030065FC @ IWRAM+0x65FC\n"
        ".L08131DD4: .4byte 0x030068BC @ IWRAM+0x68BC\n"
        ".L08131DD8: .4byte 0x03006620 @ IWRAM+0x6620\n"
        ".L08131DDC:\n"
        "    mov r3, r8\n"
        "    movs r4, #0\n"
        "    ldrsh r0, [r3, r4]\n"
        "    adds r2, r7, #0\n"
        "    muls r2, r0, r2\n"
        "    movs r3, #0\n"
        "    ldr r4, .L08131E20\n"
        ".L08131DEA:\n"
        "    adds r3, #1\n"
        "    adds r2, r2, r7\n"
        "    cmp r2, r6\n"
        "    bls .L08131DEA\n"
        "    subs r0, r3, #1\n"
        "    mov r1, r8\n"
        "    ldrh r1, [r1]\n"
        "    adds r0, r0, r1\n"
        "    mov r2, r8\n"
        "    strh r0, [r2]\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r2, r3]\n"
        "    movs r1, #0xa\n"
        "    bl __modsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    str r0, [r4, #0x34]\n"
        "    mov r1, r8\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r1, r2]\n"
        "    movs r1, #0xa\n"
        "    bl __divsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    b .L08131E54\n"
        ".L08131E20: .4byte 0x03006620 @ IWRAM+0x6620\n"
        ".L08131E24:\n"
        "    movs r0, #0x63\n"
        "    subs r0, r0, r3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    adds r0, r7, #0\n"
        "    muls r0, r5, r0\n"
        "    cmp r0, r6\n"
        "    bhi .L08131DDC\n"
        "    mov r3, r8\n"
        "    strh r5, [r3]\n"
        "    ldr r4, .L08131E60\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #0xa\n"
        "    bl __umodsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [r4, #0x34]\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #0xa\n"
        "    bl __udivsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        ".L08131E54:\n"
        "    str r0, [r4, #0x44]\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        "    b .L08131EB4\n"
        "    .byte 0x00, 0x00\n"
        ".L08131E60: .4byte 0x03006620 @ IWRAM+0x6620\n"
        ".L08131E64:\n"
        "    ldr r0, [sp, #4]\n"
        "    add r0, sl\n"
        "    mov r4, r8\n"
        "    movs r3, #0\n"
        "    ldrsh r2, [r4, r3]\n"
        "    adds r0, r0, r2\n"
        "    movs r4, #0\n"
        "    ldrsh r1, [r1, r4]\n"
        "    adds r0, r0, r1\n"
        "    cmp r0, #0x63\n"
        "    bgt .L08131EB4\n"
        "    adds r0, r2, r1\n"
        "    muls r0, r7, r0\n"
        "    cmp r0, r6\n"
        "    bhi .L08131EB4\n"
        "    mov r1, ip\n"
        "    adds r0, r1, r5\n"
        "    mov r2, r8\n"
        "    strh r0, [r2]\n"
        "    ldr r4, .L08131F20\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r2, r3]\n"
        "    movs r1, #0xa\n"
        "    bl __modsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    str r0, [r4, #0x34]\n"
        "    mov r1, r8\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r1, r2]\n"
        "    movs r1, #0xa\n"
        "    bl __divsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    str r0, [r4, #0x44]\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        ".L08131EB4:\n"
        "    bl Shop_UpdateQuantityArrows\n"
        "    ldr r2, .L08131F24\n"
        "    ldr r0, .L08131F28\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r0, r3]\n"
        "    muls r0, r7, r0\n"
        "    str r0, [r2]\n"
        "    ldr r1, .L08131F2C\n"
        "    cmp r0, r1\n"
        "    bhi .L08131ECC\n"
        "    b .L0813216E\n"
        ".L08131ECC:\n"
        "    str r1, [r2]\n"
        "    ldr r2, .L08131F30\n"
        "    movs r4, #0\n"
        "    ldrsh r0, [r2, r4]\n"
        "    cmp r0, #0x2a\n"
        "    beq .L08131EDA\n"
        "    b .L0813216E\n"
        ".L08131EDA:\n"
        "    ldr r1, .L08131F34\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    movs r4, #0\n"
        "    movs r0, #1\n"
        "    ldr r1, [sp]\n"
        "    strh r0, [r1, #0x1c]\n"
        "    movs r0, #0x47\n"
        "    strh r0, [r2]\n"
        "    ldr r0, .L08131F38\n"
        "    strh r4, [r0]\n"
        "    ldr r0, .L08131F3C\n"
        "    strh r4, [r0]\n"
        "    ldr r0, .L08131F40\n"
        "    ldr r0, [r0]\n"
        "    bl sub_080D34F0\n"
        "    ldr r1, .L08131F20\n"
        "    ldr r0, .L08131F44\n"
        "    strh r4, [r0, #0x10]\n"
        "    strh r4, [r0, #8]\n"
        "    strh r4, [r0]\n"
        "    adds r0, r1, #0\n"
        "    adds r0, #0x40\n"
        "    strh r4, [r0]\n"
        "    strh r4, [r1, #0x30]\n"
        "    strh r4, [r1, #0x20]\n"
        "    strh r4, [r1, #0x10]\n"
        "    strh r4, [r1]\n"
        "    ldr r0, .L08131F48\n"
        "    strh r4, [r0]\n"
        "    movs r0, #0x66\n"
        "    bl Sound_Play\n"
        "    b .L0813216E\n"
        ".L08131F20: .4byte 0x03006620 @ IWRAM+0x6620\n"
        ".L08131F24: .4byte 0x0203DB2C @ EWRAM+0x3DB2C\n"
        ".L08131F28: .4byte 0x030065FC @ IWRAM+0x65FC\n"
        ".L08131F2C: .4byte 0x000F423F\n"
        ".L08131F30: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L08131F34: .4byte 0x030068A0 @ IWRAM+0x68A0\n"
        ".L08131F38: .4byte 0x0300699C @ IWRAM+0x699C\n"
        ".L08131F3C: .4byte 0x0300669C @ IWRAM+0x669C\n"
        ".L08131F40: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L08131F44: .4byte 0x03006920 @ IWRAM+0x6920\n"
        ".L08131F48: .4byte 0x03006958 @ IWRAM+0x6958\n"
        ".L08131F4C:\n"
        "    movs r0, #0x80\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08132000\n"
        "    ldr r0, .L08131F80\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r0, r3]\n"
        "    adds r3, r0, #0\n"
        "    cmp r1, #0xa\n"
        "    bne .L08131F8C\n"
        "    ldr r0, .L08131F84\n"
        "    movs r4, #0\n"
        "    ldrsh r1, [r0, r4]\n"
        "    mov r8, r0\n"
        "    cmp r1, #0xa\n"
        "    bgt .L08131F9E\n"
        "    strh r5, [r0]\n"
        "    ldr r1, .L08131F88\n"
        "    movs r0, #1\n"
        "    str r0, [r1, #0x34]\n"
        "    str r2, [r1, #0x44]\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        "    b .L08131FD4\n"
        "    .byte 0x00, 0x00\n"
        ".L08131F80: .4byte 0x030068BC @ IWRAM+0x68BC\n"
        ".L08131F84: .4byte 0x030065FC @ IWRAM+0x65FC\n"
        ".L08131F88: .4byte 0x03006620 @ IWRAM+0x6620\n"
        ".L08131F8C:\n"
        "    ldr r0, .L08131FF0\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r0, r2]\n"
        "    movs r4, #0\n"
        "    ldrsh r2, [r3, r4]\n"
        "    subs r1, r1, r2\n"
        "    mov r8, r0\n"
        "    cmp r1, #0\n"
        "    ble .L08131FD4\n"
        ".L08131F9E:\n"
        "    mov r1, r8\n"
        "    ldrh r0, [r1]\n"
        "    ldrh r1, [r3]\n"
        "    subs r0, r0, r1\n"
        "    mov r2, r8\n"
        "    strh r0, [r2]\n"
        "    ldr r4, .L08131FF4\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r2, r3]\n"
        "    movs r1, #0xa\n"
        "    bl __modsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    str r0, [r4, #0x34]\n"
        "    mov r1, r8\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r1, r2]\n"
        "    movs r1, #0xa\n"
        "    bl __divsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    str r0, [r4, #0x44]\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        ".L08131FD4:\n"
        "    bl Shop_UpdateQuantityArrows\n"
        "    ldr r2, .L08131FF8\n"
        "    ldr r0, .L08131FF0\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r0, r3]\n"
        "    muls r0, r7, r0\n"
        "    str r0, [r2]\n"
        "    ldr r1, .L08131FFC\n"
        "    cmp r0, r1\n"
        "    bhi .L08131FEC\n"
        "    b .L0813216E\n"
        ".L08131FEC:\n"
        "    str r1, [r2]\n"
        "    b .L0813216E\n"
        ".L08131FF0: .4byte 0x030065FC @ IWRAM+0x65FC\n"
        ".L08131FF4: .4byte 0x03006620 @ IWRAM+0x6620\n"
        ".L08131FF8: .4byte 0x0203DB2C @ EWRAM+0x3DB2C\n"
        ".L08131FFC: .4byte 0x000F423F\n"
        ".L08132000:\n"
        "    ldrh r1, [r3]\n"
        "    movs r0, #0x10\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08132014\n"
        "    ldr r0, .L08132010\n"
        "    strh r5, [r0]\n"
        "    b .L08132024\n"
        ".L08132010: .4byte 0x030068BC @ IWRAM+0x68BC\n"
        ".L08132014:\n"
        "    ldrh r1, [r3]\n"
        "    movs r0, #0x20\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08132034\n"
        "    ldr r1, .L08132030\n"
        "    movs r0, #0xa\n"
        "    strh r0, [r1]\n"
        ".L08132024:\n"
        "    bl Shop_UpdateQuantityArrows\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        "    b .L0813216E\n"
        ".L08132030: .4byte 0x030068BC @ IWRAM+0x68BC\n"
        ".L08132034:\n"
        "    ldrh r0, [r3]\n"
        "    movs r2, #1\n"
        "    adds r4, r2, #0\n"
        "    ands r4, r0\n"
        "    cmp r4, #0\n"
        "    beq .L08132124\n"
        "    ldr r4, [sp]\n"
        "    strh r2, [r4, #0x1c]\n"
        "    ldr r4, .L08132060\n"
        "    movs r0, #0\n"
        "    ldrsh r1, [r4, r0]\n"
        "    cmp r1, #0\n"
        "    bne .L0813206C\n"
        "    ldr r0, .L08132064\n"
        "    strh r1, [r0]\n"
        "    ldr r1, .L08132068\n"
        "    movs r0, #0x35\n"
        "    strh r0, [r1]\n"
        "    movs r0, #0x66\n"
        "    bl Sound_Play\n"
        "    b .L081320C6\n"
        ".L08132060: .4byte 0x030065FC @ IWRAM+0x65FC\n"
        ".L08132064: .4byte 0x030068A0 @ IWRAM+0x68A0\n"
        ".L08132068: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L0813206C:\n"
        "    ldr r0, .L08132094\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    cmp r0, #0x2a\n"
        "    bne .L081320A0\n"
        "    ldr r5, .L08132098\n"
        "    mov r2, r8\n"
        "    ldrh r0, [r2]\n"
        "    bl sub_080C4C7C\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r4, r3]\n"
        "    muls r0, r1, r0\n"
        "    str r0, [r5]\n"
        "    ldr r1, .L0813209C\n"
        "    cmp r0, r1\n"
        "    bls .L081320B2\n"
        "    str r1, [r5]\n"
        "    b .L081320B2\n"
        "    .byte 0x00, 0x00\n"
        ".L08132094: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L08132098: .4byte 0x0203DB2C @ EWRAM+0x3DB2C\n"
        ".L0813209C: .4byte 0x000F423F\n"
        ".L081320A0:\n"
        "    ldr r2, .L081320F8\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r4, r1]\n"
        "    muls r0, r7, r0\n"
        "    str r0, [r2]\n"
        "    ldr r1, .L081320FC\n"
        "    cmp r0, r1\n"
        "    bls .L081320B2\n"
        "    str r1, [r2]\n"
        ".L081320B2:\n"
        "    movs r0, #0x65\n"
        "    bl Sound_Play\n"
        "    ldr r1, .L08132100\n"
        "    movs r0, #0x27\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L08132104\n"
        "    ldr r0, .L08132108\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r1]\n"
        ".L081320C6:\n"
        "    ldr r0, .L0813210C\n"
        "    movs r1, #0\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L08132110\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L08132114\n"
        "    ldr r0, [r0]\n"
        "    bl sub_080D34F0\n"
        "    ldr r2, .L08132118\n"
        "    ldr r1, .L0813211C\n"
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
        "    ldr r1, .L08132120\n"
        "    strh r0, [r1]\n"
        "    b .L0813216E\n"
        ".L081320F8: .4byte 0x0203DB2C @ EWRAM+0x3DB2C\n"
        ".L081320FC: .4byte 0x000F423F\n"
        ".L08132100: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L08132104: .4byte 0x0203DB50 @ EWRAM+0x3DB50\n"
        ".L08132108: .4byte 0x030069A8 @ IWRAM+0x69A8\n"
        ".L0813210C: .4byte 0x0300699C @ IWRAM+0x699C\n"
        ".L08132110: .4byte 0x0300669C @ IWRAM+0x669C\n"
        ".L08132114: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L08132118: .4byte 0x03006620 @ IWRAM+0x6620\n"
        ".L0813211C: .4byte 0x03006920 @ IWRAM+0x6920\n"
        ".L08132120: .4byte 0x03006958 @ IWRAM+0x6958\n"
        ".L08132124:\n"
        "    ldrh r1, [r3]\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L0813216E\n"
        "    ldr r0, .L08132180\n"
        "    strh r4, [r0]\n"
        "    ldr r3, [sp]\n"
        "    strh r2, [r3, #0x1c]\n"
        "    ldr r1, .L08132184\n"
        "    movs r0, #0x26\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L08132188\n"
        "    strh r4, [r0]\n"
        "    ldr r0, .L0813218C\n"
        "    strh r4, [r0]\n"
        "    ldr r0, .L08132190\n"
        "    ldr r0, [r0]\n"
        "    bl sub_080D34F0\n"
        "    ldr r1, .L08132194\n"
        "    ldr r0, .L08132198\n"
        "    strh r4, [r0, #0x10]\n"
        "    strh r4, [r0, #8]\n"
        "    strh r4, [r0]\n"
        "    adds r0, r1, #0\n"
        "    adds r0, #0x40\n"
        "    strh r4, [r0]\n"
        "    strh r4, [r1, #0x30]\n"
        "    strh r4, [r1, #0x20]\n"
        "    strh r4, [r1, #0x10]\n"
        "    strh r4, [r1]\n"
        "    ldr r0, .L0813219C\n"
        "    strh r4, [r0]\n"
        "    movs r0, #0x66\n"
        "    bl Sound_Play\n"
        ".L0813216E:\n"
        "    add sp, #8\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L08132180: .4byte 0x030068A0 @ IWRAM+0x68A0\n"
        ".L08132184: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L08132188: .4byte 0x0300699C @ IWRAM+0x699C\n"
        ".L0813218C: .4byte 0x0300669C @ IWRAM+0x669C\n"
        ".L08132190: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L08132194: .4byte 0x03006620 @ IWRAM+0x6620\n"
        ".L08132198: .4byte 0x03006920 @ IWRAM+0x6920\n"
        ".L0813219C: .4byte 0x03006958 @ IWRAM+0x6958\n"
    );
}
#endif
