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
    struct MsgPriceSlot *s = SLOTS; \
    s[3].value = QTY % 10;          \
    s[4].value = QTY / 10;          \
}

#define CLEAR_SPRITES()             \
{                                   \
    u16 *s = gUnk_03006620;         \
    gUnk_03006920[8] = 0;           \
    gUnk_03006920[4] = 0;           \
    gUnk_03006920[0] = 0;           \
    s[32] = 0;                      \
    s[24] = 0;                      \
    s[16] = 0;                      \
    s[8] = 0;                       \
    s[0] = 0;                       \
}

/* Wait handler of the quantity window. Up adds the step (0x030068BC: 1, or 10 after LEFT;
   RIGHT sets 1 again), clamped to what can be done: selling (wait state 0x2A) stops at the
   items owned and at 999,999 money, buying at 99 owned in all and at the money. Down
   subtracts the step, to at least 1. SELECT toggles the owned-count header (sub_081305D8;
   see engine/script/patch_shopowned.py). The total (unit price * quantity, at most 999,999)
   goes to gUnk_0203DB2C; when selling would reach that cap the window is left with wait
   state 0x47. A confirms (wait state 0x27, or 0x35 for quantity 0; the sale total uses the
   sale price sub_080C4C7C), B cancels (wait state 0x26). */
// Shop_QuantityInput @ 0x08131B1C
void Shop_QuantityInput(struct Task *task)
{
    u32 money = Money_Get();
    u32 unit = gUnk_03006694;
    u16 equipped = Party_CountEquipped(0xFF, gUnk_030069A8);
    u8 owned = Inventory_GetCount(gUnk_030069A8);
    u16 keys;
    u32 t;
    u32 n;
    u16 m;
    s32 have;

    gUnk_030066A0 = 0x15;
    gUnk_03006958 = 1;
    if (*(s16 *)&gUnk_030068D4 != 0)
    {
        (*(s16 *)&gUnk_030068D4)--;
        return;
    }
    if (gNewKeys & 4)
    {
        gUnk_030065E4 ^= 1;
        sub_081305D8(gUnk_030069A8);
        return;
    }
    keys = gRepeatedKeys & 0x40;
    if (keys)
    {
        if ((s16)gScriptWaitState == 0x2A)
        {
            if (unit * QTY + money > 999998)
                goto total;
            if (STEP == 1)
            {
                if (QTY + 1 <= owned)
                {
                    if ((QTY + 1) * unit + money > 999999)
                        goto total;
                    QTY++;
                    if (QTY > 99)
                        QTY = 99;
                    SET_DIGITS();
                    Sound_Play(100);
                    goto total;
                }
                else
                {
                    QTY = owned;
                    SET_DIGITS();
                    Sound_Play(100);
                    goto total;
                }
            }
            else if (QTY + 10 <= owned)
            {
                if ((QTY + 10) * unit + money <= 999999)
                {
                    QTY += 10;
                    SET_DIGITS();
                    Sound_Play(100);
                    goto total;
                }
                else
                {
                sellFill:
                {
                    /* register pin (last resort): the original has the sum and the limit in r1/r0 */
                    register u32 s asm("r1");
                    register u32 lim asm("r0");

                    t = unit * QTY;
                    n = 0;
                    s = t + money;
                    lim = 999999;
                    goto test;
                loop:
                    t += unit;
                    n++;
                    if (n > 9)
                        goto filled;
                    s = t + money;
                    lim = 999999;
                test:
                    if (s <= lim)
                        goto loop;
                    n--;
                }
                filled:
                    QTY += n;
                    SET_DIGITS();
                    Sound_Play(100);
                    goto total;
                }
            }
            else
            {
                if (owned * unit + money > 999999)
                    goto sellFill;
                QTY = owned;
                SET_DIGITS();
                Sound_Play(100);
                goto total;
            }
        }
        else if (QTY != 99)
        {
            if (STEP == 10)
            {
                have = owned + equipped;
                if (have + QTY + STEP < 100)
                {
                    if ((QTY + STEP) * unit <= money)
                    {
                        QTY += STEP;
                        SET_DIGITS();
                        Sound_Play(100);
                        goto total;
                    }
                    else
                    {
                    buyFill:
                        t = unit * QTY;
                        n = 0;
                        do
                        {
                            n++;
                            t += unit;
                        } while (t <= money);
                        n--;
                        QTY += n;
                        SET_DIGITS();
                        Sound_Play(100);
                        goto total;
                    }
                }
                else
                {
                    m = 99 - have;
                    if (unit * m > money)
                        goto buyFill;
                    QTY = m;
                    {
                        struct MsgPriceSlot *s = SLOTS;
                        s[3].value = (u16)(m % 10);
                        s[4].value = (u16)(m / 10);
                    }
                    Sound_Play(100);
                    goto total;
                }
            }
            else if (equipped + owned + QTY + STEP < 100 && (QTY + STEP) * unit <= money)
            {
                QTY += STEP;
                SET_DIGITS();
                Sound_Play(100);
            }
        }
    total:
        Shop_UpdateQuantityArrows();
        gUnk_0203DB2C = QTY * unit;
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
        if (STEP == 10)
        {
            if (QTY > 10)
                goto sub;
            QTY = 1;
            {
                struct MsgPriceSlot *s = SLOTS;
                s[3].value = 1;
                s[4].value = 0;
            }
            Sound_Play(100);
        }
        else if (QTY - STEP > 0)
        {
        sub:
            QTY -= STEP;
            SET_DIGITS();
            Sound_Play(100);
        }
        Shop_UpdateQuantityArrows();
        gUnk_0203DB2C = QTY * unit;
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
                gUnk_0203DB2C = sub_080C4C7C(gUnk_030069A8) * QTY;
                if (gUnk_0203DB2C > 999999)
                    gUnk_0203DB2C = 999999;
            }
            else
            {
                gUnk_0203DB2C = QTY * unit;
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
        gUnk_0300699C = 0;
        gMsgGlyphList2Count = 0;
        sub_080D34F0(gUnk_030068A4);
        CLEAR_SPRITES();
        gUnk_03006958 = 0;
        Sound_Play(0x66);
    }
}
