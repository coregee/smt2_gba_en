/* Script message window: the 11-entry list window with a description pane. */

#include "global.h"
#include "bmenu2.h"

extern const u16 gUnknown_0878FBA4[][16];  /* cursor x, y per row, by window layout */
extern const u16 gUnknown_0878FDB4[];      /* the 11 entries described in the pane */
extern u16 gScriptItemCheckId;

void sub_08133F14(u16 top);
void sub_080D347C(u16 a, u16 b, u16 c, u16 d, u16 e);
void sub_080D34A4(struct Task *task, u16 a, u16 b, u16 item);
void sub_08130C6C(void);

#define ROW (*(s16 *)&gUnk_0300696C)
#define TOP (*(s16 *)&gUnk_03006940)

/* Redescribe the entry under the cursor (or the 0x03006980 preview). */
#define DESCRIBE()                                                                          \
{                                                                                           \
    if (!(gUnk_03006844 & 0xF0))                                                            \
    {                                                                                       \
        sub_080D347C(gUnknown_0878FDB4[ROW + TOP], 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF);         \
        sub_080D34A4(gUnk_030068A4, 3, 0, gUnknown_0878FDB4[ROW + TOP]);                    \
    }                                                                                       \
    else                                                                                    \
    {                                                                                       \
        sub_08130C6C();                                                                     \
        sub_080D347C(gUnk_03006980[0], gUnk_03006980[1], gUnk_03006980[2],                  \
            gUnk_03006980[3], gUnk_03006980[4]);                                            \
        sub_080D34A4(gUnk_030068A4, 4, 0, 0);                                               \
    }                                                                                       \
}

/* Wait handler of the 11-entry list (layout 0x03006844 & 0xF: 0 = 4 rows, 1 = 3 rows; row
   0x0300696C, first entry 0x03006940). Up/down move and scroll, L/R move a page; scrolling
   blocks A for 3 frames (0x030068AC). In the 4-row layout every move redescribes the entry
   (gUnknown_0878FDB4[row + top]) in the pane, or shows the 0x03006980 preview when
   0x03006844 & 0xF0. A picks the entry when one is owned (Inventory_GetCount of
   0x0203DB88[row + top]): wait state 0x30 with gScriptItemCheckId set; with none owned the
   4-row layout takes the script's 2nd target, the 3-row one only buzzes (SE 0x68).
   B: wait state 0x2F. */
/* NONMATCHING: same instructions and layout (0x640 bytes); 27 lines still differ, all register
   choices: the zero stored by ROW = 0 (r2 in the original), the scratch registers of a few
   ldrsh reloads, and the low register that the copies in r8/sl are moved into. The
   `register ... asm("r0")` zero stops CSE from storing the ROW value known to be 0. */
// MsgWindow_DescListInput @ 0x08130D24
#ifdef NONMATCHING
void MsgWindow_DescListInput(struct Task *task)
{
    u16 mode = gUnk_03006844 & 0xF;
    s16 d;

    gUnk_0300689C = gUnknown_0878FBA4[mode][ROW * 2] + 8;
    gUnk_0300695C = gUnknown_0878FBA4[mode][ROW * 2 + 1];
    gUnk_030066A0 = 0x13;
    gUnk_03006958 = 1;
    if (gUnk_030068AC != 0)
        gUnk_030068AC--;
    if (gRepeatedKeys & 0x200)
    {
        if (ROW != 0)
        {
            ROW = 0;
            if (mode != 0)
                Sound_Play(100);
            else
            {
                DESCRIBE();
                Sound_Play(100);
            }
        }
        else
        {
            if (TOP == 0)
                return;
            gUnk_030068AC = 3;
            if (mode == 1)
            {
                if (TOP - 3 >= 0)
                    TOP -= 3;
                else
                    { register u32 zero asm("r0") = 0; TOP = zero; }   /* TOP = 0 */
            }
            else
            {
                if (TOP - 4 >= 0)
                    TOP -= 4;
                else
                    { register u32 zero asm("r0") = 0; TOP = zero; }   /* TOP = 0 */
                DESCRIBE();
            }
            sub_08133F14(TOP);
            Sound_Play(100);
        }
    }
    else if (gRepeatedKeys & 0x100)
    {
        if (mode == 1)
        {
            if (ROW == 2)
            {
                if (ROW + TOP + 3 <= 10)
                {
                    gUnk_030068AC = 3;
                    TOP += 3;
                    sub_08133F14(TOP);
                    Sound_Play(100);
                }
                else
                {
                    d = 11 - (ROW + TOP);
                    if (d == 0)
                        return;
                    gUnk_030068AC = 3;
                    TOP += d;
                    sub_08133F14(TOP);
                    Sound_Play(100);
                }
            }
            else
            {
                ROW = 2;
                Sound_Play(100);
            }
        }
        else if (ROW == 3)
        {
            if (ROW + TOP + 4 <= 10)
            {
                gUnk_030068AC = 3;
                TOP += 4;
                sub_08133F14(TOP);
                DESCRIBE();
                Sound_Play(100);
            }
            else
            {
                d = 11 - (ROW + TOP);
                if (d == 0)
                    return;
                gUnk_030068AC = 3;
                TOP += d;
                sub_08133F14(TOP);
                DESCRIBE();
                Sound_Play(100);
            }
        }
        else
        {
            ROW = 3;
            DESCRIBE();
            Sound_Play(100);
        }
    }
    else if (gRepeatedKeys & 0x40)
    {
        if (ROW != 0)
        {
            ROW--;
            if (mode != 0)
                Sound_Play(100);
            else
            {
                DESCRIBE();
                Sound_Play(100);
            }
        }
        else
        {
            if (TOP == 0)
                return;
            gUnk_030068AC = 3;
            TOP--;
            sub_08133F14(TOP);
            if (mode != 0)
                Sound_Play(100);
            else
            {
                DESCRIBE();
                Sound_Play(100);
            }
        }
    }
    else if (gRepeatedKeys & 0x80)
    {
        if ((mode == 1 && ROW == 2) || (mode == 0 && ROW == 3))
        {
            if (ROW + TOP > 10)
                return;
            gUnk_030068AC = 3;
            TOP++;
            sub_08133F14(TOP);
            if (mode != 0)
                Sound_Play(100);
            else
            {
                DESCRIBE();
                Sound_Play(100);
            }
        }
        else
        {
            ROW++;
            if (mode != 0)
                Sound_Play(100);
            else
            {
                DESCRIBE();
                Sound_Play(100);
            }
        }
    }
    else if (gNewKeys & 1)
    {
        if (gUnk_030068AC != 0)
            return;
        if ((u8)Inventory_GetCount(gUnk_0203DB88[ROW + TOP]) == 0)
        {
            if (mode == 0)
            {
                gScriptJumpTarget = gUnk_0203DAC8[1];
                task->result = 1;
                gScriptWaitState = 0x30;
                Sound_Play(0x66);
            }
            else
                Sound_Play(0x68);
        }
        else
        {
            task->result = 1;
            gScriptWaitState = 0x30;
            gScriptItemCheckId = gUnk_0203DB88[ROW + TOP];
            Sound_Play(0x65);
        }
    }
    else if (gNewKeys & 2)
    {
        task->result = 1;
        gScriptWaitState = 0x2F;
        Sound_Play(0x66);
    }
}
#else
NAKED
void MsgWindow_DescListInput(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #4\n"
        "    mov sb, r0\n"
        "    ldr r4, .L08130DDC\n"
        "    ldrh r5, [r4]\n"
        "    movs r7, #0xf\n"
        "    ands r7, r5\n"
        "    mov sl, r7\n"
        "    ldr r2, .L08130DE0\n"
        "    ldr r3, .L08130DE4\n"
        "    ldr r6, .L08130DE8\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r6, r1]\n"
        "    lsls r0, r0, #2\n"
        "    lsls r1, r7, #5\n"
        "    adds r0, r0, r1\n"
        "    adds r0, r0, r3\n"
        "    ldrh r0, [r0]\n"
        "    adds r0, #8\n"
        "    strh r0, [r2]\n"
        "    ldr r2, .L08130DEC\n"
        "    mov r8, r2\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r6, r2]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r1\n"
        "    adds r0, r0, r3\n"
        "    ldrh r0, [r0]\n"
        "    mov r3, r8\n"
        "    strh r0, [r3]\n"
        "    ldr r1, .L08130DF0\n"
        "    movs r0, #0x13\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L08130DF4\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L08130DF8\n"
        "    mov ip, r0\n"
        "    ldrh r0, [r0]\n"
        "    mov r8, r6\n"
        "    mov r2, ip\n"
        "    cmp r0, #0\n"
        "    beq .L08130D8A\n"
        "    subs r0, #1\n"
        "    strh r0, [r2]\n"
        ".L08130D8A:\n"
        "    ldr r0, .L08130DFC\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L08130D9A\n"
        "    b .L08130EEC\n"
        ".L08130D9A:\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r6, r1]\n"
        "    cmp r0, #0\n"
        "    beq .L08130E10\n"
        "    movs r2, #0\n"
        "    strh r2, [r6]\n"
        "    cmp r7, #0\n"
        "    beq .L08130DAC\n"
        "    b .L08131280\n"
        ".L08130DAC:\n"
        "    movs r0, #0xf0\n"
        "    ands r0, r5\n"
        "    cmp r0, #0\n"
        "    beq .L08130DB6\n"
        "    b .L0813125C\n"
        ".L08130DB6:\n"
        "    ldr r5, .L08130E00\n"
        "    ldr r4, .L08130E04\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r4, r3]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r5\n"
        "    ldrh r0, [r0]\n"
        "    ldr r3, .L08130E08\n"
        "    str r3, [sp]\n"
        "    adds r1, r3, #0\n"
        "    adds r2, r3, #0\n"
        "    bl sub_080D347C\n"
        "    ldr r0, .L08130E0C\n"
        "    ldr r0, [r0]\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r6, r2]\n"
        "    b .L08131234\n"
        "    .byte 0x00, 0x00\n"
        ".L08130DDC: .4byte 0x03006844 @ IWRAM+0x6844\n"
        ".L08130DE0: .4byte 0x0300689C @ IWRAM+0x689C\n"
        ".L08130DE4: .4byte gUnknown_0878FBA4\n"
        ".L08130DE8: .4byte 0x0300696C @ IWRAM+0x696C\n"
        ".L08130DEC: .4byte 0x0300695C @ IWRAM+0x695C\n"
        ".L08130DF0: .4byte 0x030066A0 @ IWRAM+0x66A0\n"
        ".L08130DF4: .4byte 0x03006958 @ IWRAM+0x6958\n"
        ".L08130DF8: .4byte 0x030068AC @ IWRAM+0x68AC\n"
        ".L08130DFC: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L08130E00: .4byte gUnknown_0878FDB4\n"
        ".L08130E04: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08130E08: .4byte 0x0000FFFF\n"
        ".L08130E0C: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L08130E10:\n"
        "    ldr r1, .L08130E38\n"
        "    ldrh r2, [r1]\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r1, r3]\n"
        "    cmp r0, #0\n"
        "    bne .L08130E1E\n"
        "    b .L0813134E\n"
        ".L08130E1E:\n"
        "    movs r0, #3\n"
        "    mov r3, ip\n"
        "    strh r0, [r3]\n"
        "    cmp r7, #1\n"
        "    bne .L08130E42\n"
        "    movs r4, #0\n"
        "    ldrsh r0, [r1, r4]\n"
        "    subs r0, #3\n"
        "    cmp r0, #0\n"
        "    blt .L08130E3C\n"
        "    subs r0, r2, #3\n"
        "    strh r0, [r1]\n"
        "    b .L08130ED4\n"
        ".L08130E38: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08130E3C:\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    b .L08130ED4\n"
        ".L08130E42:\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r1, r3]\n"
        "    subs r0, #4\n"
        "    cmp r0, #0\n"
        "    blt .L08130E50\n"
        "    subs r0, r2, #4\n"
        "    b .L08130E52\n"
        ".L08130E50:\n"
        "    movs r0, #0\n"
        ".L08130E52:\n"
        "    strh r0, [r1]\n"
        "    ldrh r1, [r4]\n"
        "    movs r0, #0xf0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L08130EB0\n"
        "    ldr r5, .L08130EA0\n"
        "    mov r1, r8\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r1, r2]\n"
        "    ldr r4, .L08130EA4\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r4, r3]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r5\n"
        "    ldrh r0, [r0]\n"
        "    ldr r3, .L08130EA8\n"
        "    str r3, [sp]\n"
        "    adds r1, r3, #0\n"
        "    adds r2, r3, #0\n"
        "    bl sub_080D347C\n"
        "    ldr r0, .L08130EAC\n"
        "    ldr r0, [r0]\n"
        "    mov r2, r8\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r2, r3]\n"
        "    movs r3, #0\n"
        "    ldrsh r2, [r4, r3]\n"
        "    adds r1, r1, r2\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r5\n"
        "    ldrh r3, [r1]\n"
        "    movs r1, #3\n"
        "    movs r2, #0\n"
        "    bl sub_080D34A4\n"
        "    b .L08130ED4\n"
        ".L08130EA0: .4byte gUnknown_0878FDB4\n"
        ".L08130EA4: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08130EA8: .4byte 0x0000FFFF\n"
        ".L08130EAC: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L08130EB0:\n"
        "    bl sub_08130C6C\n"
        "    ldr r4, .L08130EE0\n"
        "    ldrh r0, [r4]\n"
        "    ldrh r1, [r4, #2]\n"
        "    ldrh r2, [r4, #4]\n"
        "    ldrh r3, [r4, #6]\n"
        "    ldrh r4, [r4, #8]\n"
        "    str r4, [sp]\n"
        "    bl sub_080D347C\n"
        "    ldr r0, .L08130EE4\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #4\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl sub_080D34A4\n"
        ".L08130ED4:\n"
        "    ldr r0, .L08130EE8\n"
        "    ldrh r0, [r0]\n"
        "    bl sub_08133F14\n"
        "    b .L08131280\n"
        "    .byte 0x00, 0x00\n"
        ".L08130EE0: .4byte 0x03006980 @ IWRAM+0x6980\n"
        ".L08130EE4: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L08130EE8: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08130EEC:\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L08130EF8\n"
        "    b .L08131078\n"
        ".L08130EF8:\n"
        "    cmp r7, #1\n"
        "    bne .L08130F4E\n"
        "    ldrh r4, [r6]\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r6, r1]\n"
        "    cmp r0, #2\n"
        "    bne .L08130F48\n"
        "    ldr r2, .L08130F28\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r2, r3]\n"
        "    adds r0, r0, r1\n"
        "    adds r0, #3\n"
        "    cmp r0, #0xa\n"
        "    bgt .L08130F2C\n"
        "    movs r0, #3\n"
        "    mov r4, ip\n"
        "    strh r0, [r4]\n"
        "    ldrh r0, [r2]\n"
        "    adds r0, #3\n"
        ".L08130F1E:\n"
        "    strh r0, [r2]\n"
        "    ldrh r0, [r2]\n"
        "    bl sub_08133F14\n"
        "    b .L08131280\n"
        ".L08130F28: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08130F2C:\n"
        "    ldrh r3, [r2]\n"
        "    adds r1, r4, r3\n"
        "    movs r0, #0xb\n"
        "    subs r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r1, r0, #0x10\n"
        "    cmp r1, #0\n"
        "    bne .L08130F3E\n"
        "    b .L0813134E\n"
        ".L08130F3E:\n"
        "    movs r0, #3\n"
        "    mov r4, ip\n"
        "    strh r0, [r4]\n"
        "    adds r0, r1, r3\n"
        "    b .L08130F1E\n"
        ".L08130F48:\n"
        "    movs r0, #2\n"
        "    strh r0, [r6]\n"
        "    b .L08131280\n"
        ".L08130F4E:\n"
        "    ldrh r7, [r6]\n"
        "    movs r0, #0\n"
        "    ldrsh r2, [r6, r0]\n"
        "    cmp r2, #3\n"
        "    bne .L08131034\n"
        "    adds r0, r2, #0\n"
        "    ldr r5, .L08130FB8\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r5, r3]\n"
        "    adds r0, r0, r1\n"
        "    adds r0, #4\n"
        "    cmp r0, #0xa\n"
        "    bgt .L08130FC8\n"
        "    mov r0, ip\n"
        "    strh r2, [r0]\n"
        "    ldrh r0, [r5]\n"
        "    adds r0, #4\n"
        "    strh r0, [r5]\n"
        "    ldrh r0, [r5]\n"
        "    bl sub_08133F14\n"
        "    ldrh r1, [r4]\n"
        "    movs r0, #0xf0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08130F84\n"
        "    b .L0813125C\n"
        ".L08130F84:\n"
        "    ldr r4, .L08130FBC\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r6, r1]\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r5, r2]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    ldr r3, .L08130FC0\n"
        "    str r3, [sp]\n"
        "    adds r1, r3, #0\n"
        "    adds r2, r3, #0\n"
        "    bl sub_080D347C\n"
        "    ldr r0, .L08130FC4\n"
        "    ldr r0, [r0]\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r6, r3]\n"
        "    movs r3, #0\n"
        "    ldrsh r2, [r5, r3]\n"
        "    adds r1, r1, r2\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r4\n"
        "    b .L0813123E\n"
        "    .byte 0x00, 0x00\n"
        ".L08130FB8: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08130FBC: .4byte gUnknown_0878FDB4\n"
        ".L08130FC0: .4byte 0x0000FFFF\n"
        ".L08130FC4: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L08130FC8:\n"
        "    ldrh r3, [r5]\n"
        "    adds r1, r7, r3\n"
        "    movs r0, #0xb\n"
        "    subs r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L08130FDA\n"
        "    b .L0813134E\n"
        ".L08130FDA:\n"
        "    mov r1, ip\n"
        "    strh r2, [r1]\n"
        "    adds r0, r0, r3\n"
        "    strh r0, [r5]\n"
        "    ldrh r0, [r5]\n"
        "    bl sub_08133F14\n"
        "    ldrh r1, [r4]\n"
        "    movs r0, #0xf0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08130FF4\n"
        "    b .L0813125C\n"
        ".L08130FF4:\n"
        "    ldr r4, .L08131028\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r6, r2]\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r5, r3]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    ldr r3, .L0813102C\n"
        "    str r3, [sp]\n"
        "    adds r1, r3, #0\n"
        "    adds r2, r3, #0\n"
        "    bl sub_080D347C\n"
        "    ldr r0, .L08131030\n"
        "    ldr r0, [r0]\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r6, r2]\n"
        "    movs r3, #0\n"
        "    ldrsh r2, [r5, r3]\n"
        "    adds r1, r1, r2\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r4\n"
        "    b .L0813123E\n"
        "    .byte 0x00, 0x00\n"
        ".L08131028: .4byte gUnknown_0878FDB4\n"
        ".L0813102C: .4byte 0x0000FFFF\n"
        ".L08131030: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L08131034:\n"
        "    movs r0, #3\n"
        "    strh r0, [r6]\n"
        "    movs r0, #0xf0\n"
        "    ands r0, r5\n"
        "    cmp r0, #0\n"
        "    beq .L08131042\n"
        "    b .L0813125C\n"
        ".L08131042:\n"
        "    ldr r5, .L08131068\n"
        "    ldr r4, .L0813106C\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r4, r1]\n"
        "    adds r0, #3\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r5\n"
        "    ldrh r0, [r0]\n"
        "    ldr r3, .L08131070\n"
        "    str r3, [sp]\n"
        "    adds r1, r3, #0\n"
        "    adds r2, r3, #0\n"
        "    bl sub_080D347C\n"
        "    ldr r0, .L08131074\n"
        "    ldr r0, [r0]\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r6, r2]\n"
        "    b .L08131234\n"
        ".L08131068: .4byte gUnknown_0878FDB4\n"
        ".L0813106C: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08131070: .4byte 0x0000FFFF\n"
        ".L08131074: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L08131078:\n"
        "    movs r0, #0x40\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L0813114C\n"
        "    ldrh r1, [r6]\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r6, r2]\n"
        "    cmp r0, #0\n"
        "    beq .L081310D8\n"
        "    subs r0, r1, #1\n"
        "    strh r0, [r6]\n"
        "    cmp r7, #0\n"
        "    beq .L08131094\n"
        "    b .L08131280\n"
        ".L08131094:\n"
        "    movs r0, #0xf0\n"
        "    ands r0, r5\n"
        "    cmp r0, #0\n"
        "    beq .L0813109E\n"
        "    b .L0813125C\n"
        ".L0813109E:\n"
        "    ldr r5, .L081310C8\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r6, r3]\n"
        "    ldr r4, .L081310CC\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r4, r2]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r5\n"
        "    ldrh r0, [r0]\n"
        "    ldr r3, .L081310D0\n"
        "    str r3, [sp]\n"
        "    adds r1, r3, #0\n"
        "    adds r2, r3, #0\n"
        "    bl sub_080D347C\n"
        "    ldr r0, .L081310D4\n"
        "    ldr r0, [r0]\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r6, r3]\n"
        "    b .L08131234\n"
        ".L081310C8: .4byte gUnknown_0878FDB4\n"
        ".L081310CC: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L081310D0: .4byte 0x0000FFFF\n"
        ".L081310D4: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L081310D8:\n"
        "    ldr r5, .L0813113C\n"
        "    ldrh r1, [r5]\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r5, r2]\n"
        "    cmp r0, #0\n"
        "    bne .L081310E6\n"
        "    b .L0813134E\n"
        ".L081310E6:\n"
        "    movs r0, #3\n"
        "    mov r3, ip\n"
        "    strh r0, [r3]\n"
        "    subs r0, r1, #1\n"
        "    strh r0, [r5]\n"
        "    ldrh r0, [r5]\n"
        "    bl sub_08133F14\n"
        "    cmp r7, #0\n"
        "    beq .L081310FC\n"
        "    b .L08131280\n"
        ".L081310FC:\n"
        "    ldrh r1, [r4]\n"
        "    movs r0, #0xf0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08131108\n"
        "    b .L0813125C\n"
        ".L08131108:\n"
        "    ldr r4, .L08131140\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r6, r1]\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r5, r2]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    ldr r3, .L08131144\n"
        "    str r3, [sp]\n"
        "    adds r1, r3, #0\n"
        "    adds r2, r3, #0\n"
        "    bl sub_080D347C\n"
        "    ldr r0, .L08131148\n"
        "    ldr r0, [r0]\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r6, r3]\n"
        "    movs r3, #0\n"
        "    ldrsh r2, [r5, r3]\n"
        "    adds r1, r1, r2\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r4\n"
        "    b .L0813123E\n"
        "    .byte 0x00, 0x00\n"
        ".L0813113C: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08131140: .4byte gUnknown_0878FDB4\n"
        ".L08131144: .4byte 0x0000FFFF\n"
        ".L08131148: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L0813114C:\n"
        "    movs r0, #0x80\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L08131156\n"
        "    b .L08131290\n"
        ".L08131156:\n"
        "    cmp r7, #1\n"
        "    bne .L08131162\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r6, r1]\n"
        "    cmp r0, #2\n"
        "    beq .L0813116E\n"
        ".L08131162:\n"
        "    cmp r7, #0\n"
        "    bne .L081311F0\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r6, r3]\n"
        "    cmp r0, #3\n"
        "    bne .L081311F0\n"
        ".L0813116E:\n"
        "    mov r4, r8\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r4, r1]\n"
        "    ldr r5, .L081311DC\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r5, r3]\n"
        "    adds r0, r0, r1\n"
        "    cmp r0, #0xa\n"
        "    ble .L08131182\n"
        "    b .L0813134E\n"
        ".L08131182:\n"
        "    movs r0, #3\n"
        "    strh r0, [r2]\n"
        "    ldrh r0, [r5]\n"
        "    adds r0, #1\n"
        "    strh r0, [r5]\n"
        "    ldrh r0, [r5]\n"
        "    bl sub_08133F14\n"
        "    mov r4, sl\n"
        "    cmp r4, #0\n"
        "    bne .L08131280\n"
        "    ldr r0, .L081311E0\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0xf0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L0813125C\n"
        "    ldr r4, .L081311E4\n"
        "    mov r1, r8\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r1, r2]\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r5, r3]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    ldr r3, .L081311E8\n"
        "    str r3, [sp]\n"
        "    adds r1, r3, #0\n"
        "    adds r2, r3, #0\n"
        "    bl sub_080D347C\n"
        "    ldr r0, .L081311EC\n"
        "    ldr r0, [r0]\n"
        "    mov r2, r8\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r2, r3]\n"
        "    movs r3, #0\n"
        "    ldrsh r2, [r5, r3]\n"
        "    adds r1, r1, r2\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r4\n"
        "    b .L0813123E\n"
        "    .byte 0x00, 0x00\n"
        ".L081311DC: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L081311E0: .4byte 0x03006844 @ IWRAM+0x6844\n"
        ".L081311E4: .4byte gUnknown_0878FDB4\n"
        ".L081311E8: .4byte 0x0000FFFF\n"
        ".L081311EC: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L081311F0:\n"
        "    mov r1, r8\n"
        "    ldrh r0, [r1]\n"
        "    adds r0, #1\n"
        "    strh r0, [r1]\n"
        "    mov r2, sl\n"
        "    cmp r2, #0\n"
        "    bne .L08131280\n"
        "    ldrh r1, [r4]\n"
        "    movs r0, #0xf0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L0813125C\n"
        "    ldr r5, .L0813124C\n"
        "    mov r3, r8\n"
        "    movs r4, #0\n"
        "    ldrsh r0, [r3, r4]\n"
        "    ldr r4, .L08131250\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r4, r2]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r5\n"
        "    ldrh r0, [r0]\n"
        "    ldr r3, .L08131254\n"
        "    str r3, [sp]\n"
        "    adds r1, r3, #0\n"
        "    adds r2, r3, #0\n"
        "    bl sub_080D347C\n"
        "    ldr r0, .L08131258\n"
        "    ldr r0, [r0]\n"
        "    mov r3, r8\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r3, r2]\n"
        ".L08131234:\n"
        "    movs r3, #0\n"
        "    ldrsh r2, [r4, r3]\n"
        "    adds r1, r1, r2\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r5\n"
        ".L0813123E:\n"
        "    ldrh r3, [r1]\n"
        "    movs r1, #3\n"
        "    movs r2, #0\n"
        "    bl sub_080D34A4\n"
        "    b .L08131280\n"
        "    .byte 0x00, 0x00\n"
        ".L0813124C: .4byte gUnknown_0878FDB4\n"
        ".L08131250: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L08131254: .4byte 0x0000FFFF\n"
        ".L08131258: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L0813125C:\n"
        "    bl sub_08130C6C\n"
        "    ldr r4, .L08131288\n"
        "    ldrh r0, [r4]\n"
        "    ldrh r1, [r4, #2]\n"
        "    ldrh r2, [r4, #4]\n"
        "    ldrh r3, [r4, #6]\n"
        "    ldrh r4, [r4, #8]\n"
        "    str r4, [sp]\n"
        "    bl sub_080D347C\n"
        "    ldr r0, .L0813128C\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #4\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl sub_080D34A4\n"
        ".L08131280:\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        "    b .L0813134E\n"
        ".L08131288: .4byte 0x03006980 @ IWRAM+0x6980\n"
        ".L0813128C: .4byte 0x030068A4 @ IWRAM+0x68A4\n"
        ".L08131290:\n"
        "    ldr r2, .L081312E4\n"
        "    ldrh r1, [r2]\n"
        "    movs r4, #1\n"
        "    adds r0, r4, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08131334\n"
        "    mov r1, ip\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #0\n"
        "    bne .L0813134E\n"
        "    ldr r7, .L081312E8\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r6, r2]\n"
        "    ldr r5, .L081312EC\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r5, r3]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r7\n"
        "    ldrh r0, [r0]\n"
        "    bl Inventory_GetCount\n"
        "    lsls r0, r0, #0x18\n"
        "    cmp r0, #0\n"
        "    bne .L08131304\n"
        "    mov r0, sl\n"
        "    cmp r0, #0\n"
        "    bne .L081312FC\n"
        "    ldr r1, .L081312F0\n"
        "    ldr r0, .L081312F4\n"
        "    ldr r0, [r0, #4]\n"
        "    str r0, [r1]\n"
        "    mov r1, sb\n"
        "    strh r4, [r1, #0x1c]\n"
        "    ldr r1, .L081312F8\n"
        "    movs r0, #0x30\n"
        "    strh r0, [r1]\n"
        "    movs r0, #0x66\n"
        "    bl Sound_Play\n"
        "    b .L0813134E\n"
        ".L081312E4: .4byte 0x030031C4 @ IWRAM+0x31C4\n"
        ".L081312E8: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L081312EC: .4byte 0x03006940 @ IWRAM+0x6940\n"
        ".L081312F0: .4byte 0x030068E4 @ IWRAM+0x68E4\n"
        ".L081312F4: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8\n"
        ".L081312F8: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L081312FC:\n"
        "    movs r0, #0x68\n"
        "    bl Sound_Play\n"
        "    b .L0813134E\n"
        ".L08131304:\n"
        "    mov r2, sb\n"
        "    strh r4, [r2, #0x1c]\n"
        "    ldr r1, .L0813132C\n"
        "    movs r0, #0x30\n"
        "    strh r0, [r1]\n"
        "    ldr r2, .L08131330\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r6, r3]\n"
        "    movs r4, #0\n"
        "    ldrsh r1, [r5, r4]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r7\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r2]\n"
        "    movs r0, #0x65\n"
        "    bl Sound_Play\n"
        "    b .L0813134E\n"
        "    .byte 0x00, 0x00\n"
        ".L0813132C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L08131330: .4byte 0x0203DB50 @ EWRAM+0x3DB50\n"
        ".L08131334:\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L0813134E\n"
        "    mov r0, sb\n"
        "    strh r4, [r0, #0x1c]\n"
        "    ldr r1, .L08131360\n"
        "    movs r0, #0x2f\n"
        "    strh r0, [r1]\n"
        "    movs r0, #0x66\n"
        "    bl Sound_Play\n"
        ".L0813134E:\n"
        "    add sp, #4\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L08131360: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
    );
}
#endif
