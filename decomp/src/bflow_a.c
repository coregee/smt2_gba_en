#include "global.h"
#include "bflow.h"

/* Copies a battle message into the compose buffer, inserting a line break (0x300) after
   every 17 counted glyphs. 0x320 = name of the first active party member (at most 8
   glyphs, + 0xC8F when more than one is present); 0x316/0x317/0x300 are dropped and 0x315
   is copied without being counted. The buffer holds 64 glyphs and is not bounds-checked. */
// MessageBox_ComposeWrappedText @ 0x080EBED4
#ifdef NONMATCHING
u16 *MessageBox_ComposeWrappedText(u16 *src, u32 who)
{
    struct BattleFlow *b = BFLOW;
    struct BFlowMsg *msg = &b->msg;
    u16 n = 0;
    u16 name[9];
    u32 zero;
    u16 *dst;
    u16 *p;
    u16 c;
    u8 i;

    memset(name, 0, sizeof(name));
    if (msg->locked == 1)
        return b->msg.compose;

    zero = 0;
    CpuSet(&zero, b->msg.compose, 0x05000020);
    dst = b->msg.compose;
    for (p = src; (c = *p) != 0x301;)
    {
        if (c == 0x320)
        {
            Battle_GetCombatant(who + 0x8000);
            p++;
            for (i = 0; i < 4; i++)
            {
                if (Combatant_IsInParty(i) && Combatant_IsAlive(i))
                    break;
            }
            Combatant_DecodeName(Battle_GetCombatant(i + 0x8000), name);
            for (i = 0; name[i] != 0;)
            {
                *dst++ = name[i];
                n++;
                if (++i > 7)
                    break;
            }
            if (sub_080F4968() > 1)
            {
                *dst++ = 0xC8F;
                n++;
            }
        }
        else
        {
            if ((u16)(c - 0x316) > 1 && c != 0x300)
            {
                *dst++ = c;
                if (*p != 0x315)
                {
                    n++;
                    if (n % 17 == 0)
                        *dst++ = 0x300;
                }
            }
            p++;
        }
    }
    dst--;
    if (*dst == 0x300)
        *dst = 0;
    return BFLOW->msg.compose;
}
#else
NAKED
u16 *MessageBox_ComposeWrappedText(u16 *src, u32 who)
{
    asm_unified(
        ".L080EBED4:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sb\n"
        "    mov r6, r8\n"
        "    push {r6, r7}\n"
        "    sub sp, #0x18\n"
        "    mov r8, r0\n"
        "    mov sb, r1\n"
        "    ldr r5, .L080EBF04\n"
        "    movs r0, #0xfc\n"
        "    lsls r0, r0, #3\n"
        "    adds r4, r5, r0\n"
        "    movs r7, #0\n"
        "    mov r0, sp\n"
        "    movs r1, #0\n"
        "    movs r2, #0x12\n"
        "    bl memset\n"
        "    ldrb r0, [r4, #7]\n"
        "    cmp r0, #1\n"
        "    bne .L080EBF0C\n"
        "    ldr r1, .L080EBF08\n"
        "    adds r0, r5, r1\n"
        "    b .L080EC018\n"
        "    .byte 0x00, 0x00\n"
        ".L080EBF04: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080EBF08: .4byte 0x000008EC\n"
        ".L080EBF0C:\n"
        "    str r7, [sp, #0x14]\n"
        "    add r0, sp, #0x14\n"
        "    ldr r3, .L080EBF24\n"
        "    adds r4, r5, r3\n"
        "    ldr r2, .L080EBF28\n"
        "    adds r1, r4, #0\n"
        "    bl CpuSet\n"
        "    adds r6, r4, #0\n"
        "    mov r5, r8\n"
        "    b .L080EBFFE\n"
        "    .byte 0x00, 0x00\n"
        ".L080EBF24: .4byte 0x000008EC\n"
        ".L080EBF28: .4byte 0x05000020 @ PLTT+0x20\n"
        ".L080EBF2C:\n"
        "    adds r2, r1, #0\n"
        "    movs r0, #0xc8\n"
        "    lsls r0, r0, #2\n"
        "    cmp r2, r0\n"
        "    bne .L080EBFC4\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #8\n"
        "    add r0, sb\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    movs r4, #0\n"
        "    adds r5, #2\n"
        "    b .L080EBF50\n"
        ".L080EBF4A:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        ".L080EBF50:\n"
        "    cmp r4, #3\n"
        "    bhi .L080EBF68\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_IsInParty\n"
        "    cmp r0, #0\n"
        "    beq .L080EBF4A\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_IsAlive\n"
        "    cmp r0, #0\n"
        "    beq .L080EBF4A\n"
        ".L080EBF68:\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    adds r0, r1, #0\n"
        "    adds r0, r4, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    mov r1, sp\n"
        "    bl Combatant_DecodeName\n"
        "    movs r1, #0\n"
        "    mov r0, sp\n"
        "    b .L080EBFA2\n"
        ".L080EBF84:\n"
        "    lsls r0, r1, #1\n"
        "    .2byte 0x4468 @ add r0, sp, r0\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r6]\n"
        "    adds r6, #2\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r1, r0, #0x18\n"
        "    cmp r1, #7\n"
        "    bhi .L080EBFA8\n"
        "    lsls r0, r1, #1\n"
        "    .2byte 0x4468 @ add r0, sp, r0\n"
        ".L080EBFA2:\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L080EBF84\n"
        ".L080EBFA8:\n"
        "    bl sub_080F4968\n"
        "    cmp r0, #1\n"
        "    ble .L080EBFFE\n"
        "    ldr r3, .L080EBFC0\n"
        "    adds r0, r3, #0\n"
        "    strh r0, [r6]\n"
        "    adds r6, #2\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    b .L080EBFFE\n"
        ".L080EBFC0: .4byte 0x00000C8F\n"
        ".L080EBFC4:\n"
        "    ldr r3, .L080EC028\n"
        "    adds r0, r1, r3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bls .L080EBFFC\n"
        "    movs r4, #0xc0\n"
        "    lsls r4, r4, #2\n"
        "    cmp r2, r4\n"
        "    beq .L080EBFFC\n"
        "    strh r1, [r6]\n"
        "    adds r6, #2\n"
        "    ldrh r1, [r5]\n"
        "    ldr r0, .L080EC02C\n"
        "    cmp r1, r0\n"
        "    beq .L080EBFFC\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r0, r7, #0\n"
        "    movs r1, #0x11\n"
        "    bl __umodsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080EBFFC\n"
        "    strh r4, [r6]\n"
        "    adds r6, #2\n"
        ".L080EBFFC:\n"
        "    adds r5, #2\n"
        ".L080EBFFE:\n"
        "    ldrh r1, [r5]\n"
        "    ldr r0, .L080EC030\n"
        "    cmp r1, r0\n"
        "    bne .L080EBF2C\n"
        "    subs r6, #2\n"
        "    ldrh r1, [r6]\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #2\n"
        "    cmp r1, r0\n"
        "    bne .L080EC016\n"
        "    movs r0, #0\n"
        "    strh r0, [r6]\n"
        ".L080EC016:\n"
        "    ldr r0, .L080EC034\n"
        ".L080EC018:\n"
        "    add sp, #0x18\n"
        "    pop {r3, r4}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L080EC028: .4byte 0xFFFFFCEA\n"
        ".L080EC02C: .4byte 0x00000315\n"
        ".L080EC030: .4byte 0x00000301\n"
        ".L080EC034: .4byte 0x0203CAEC @ EWRAM+0x3CAEC\n"
    );
}
#endif

// Battle_GetMessage @ 0x080EC038
u16 *Battle_GetMessage(u16 id)
{
    return (u16 *)gUnknown_0876FB54[id];
}

// sub_080EC048 @ 0x080EC048
void sub_080EC048(void)
{
    struct BattleFlow *b = BFLOW;

    sub_080EA210();
    if (gUnk_030063A0.unkC != 0)
    {
        gUnk_030063A0.unk10 = 9;
        sub_080ECF60(9);
    }
    else
    {
        sub_080EC948();
    }
    b->state = 2;
    if (b->unk1189 == 1)
        b->state = 3;
}

// sub_080EC094 @ 0x080EC094
void sub_080EC094(void)
{
    struct BattleFlow *b = BFLOW;
    u32 v1, v2;
    u16 *text;

    if (Flag_Test(0x166))
    {
        v1 = sub_080ED9F4();
        v2 = sub_080ED9F4();
        text = MessageBox_ComposeSpeciesText(b->combatants[0], b->combatants[0], v1, v2, gUnknown_081267E0);
    }
    else if (Battle_IsTwoSided() == 1)
    {
        v1 = sub_080EDA24(0);
        v2 = sub_080EDA24(1);
        text = MessageBox_ComposeSpeciesText(b->combatants[0], b->combatants[1], v1, v2, gUnknown_081267BA);
    }
    else
    {
        v1 = sub_080ED9F4();
        v2 = sub_080ED9F4();
        text = MessageBox_ComposeSpeciesText(b->combatants[0], b->combatants[0], v1, v2, gUnknown_081267A6);
    }
    BattleMenu_SetModeAutoClose(3, text);
    b->state = 3;
    b->substate = 0;
}

// sub_080EC144 @ 0x080EC144
void sub_080EC144(struct Task *task)
{
    struct BattleFlow *b = BFLOW;

    sub_080C84A0();
    task->result = 0;
    switch (b->substate)
    {
    case 0:
        if (b->unkF6A <= 1)
            gUnk_030063A0.unk16 = sub_080EDE70();
        sub_080ED920(gUnk_030063A0.unk16);
        if (gUnk_030063A0.unk16 == 0)
        {
            b->state = 5;
            b->substate = 0;
            task->result = 1;
        }
        else
        {
            b->substate = 1;
        }
        break;
    case 1:
        if (BattleMsg_IsDone() == 1)
        {
            if (gUnk_030063A0.unk16 == 0xC000)
            {
                sub_080EC948();
                BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(Battle_GetMessage(0x167), 0));
                b->state = 10;
            }
            else if (gUnk_030063A0.unk16 == 0x8000)
            {
                BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(Battle_GetMessage(0x166), 0));
                b->state = 5;
            }
            b->substate = 2;
        }
        break;
    case 2:
        if (BattleMsg_IsDone() == 1)
        {
            b->substate = 0;
            task->result = 1;
        }
        break;
    }
}

// sub_080EC25C @ 0x080EC25C
void sub_080EC25C(void)
{
    struct BattleFlow *b = BFLOW;

    BattleMenu_SetMode(3, (u16 *)gUnknown_086BE5DA);
    BattleMsg_SetDone(1);
    b->state = 7;
}

// sub_080EC288 @ 0x080EC288
void sub_080EC288(void)
{
    struct BattleFlow *b = BFLOW;

    BattleMsg_SetLocked(0);
    BattleMenu_SetMode(3, (u16 *)gUnknown_086BE5DA);
    BattleMsg_SetDone(1);
    b->state = 7;
    if (!(sub_080ED8F4() & 0x100))
    {
        if (gUnk_0200E7D4[0] != 0 && gUnk_0200E7D4[0] != 2)
            sub_080C700C();
    }
    else
    {
        sub_080C7054();
    }
}

// sub_080EC2E4 @ 0x080EC2E4
void sub_080EC2E4(void)
{
    struct BattleFlow *b = BFLOW;
    s32 r = sub_080EFA9C();

    b->unk11A8 = 0;
    switch (r)
    {
    case 1:
    case 8:
        b->unk11A8 = 1;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
    case 11:
        b->unk11A8 = 2;
        break;
    }
}

/* Battle start / escape flow (state 6/7 of the battle message machine). */
// sub_080EC35C @ 0x080EC35C
#ifdef NONMATCHING
void sub_080EC35C(struct Task *task)
{
    struct BattleFlow *b = BFLOW;
    u16 *who;
    u16 *tmpl;
    u16 *text;
    u32 id;
    u16 r;
    s32 res;

    task->result = 0;
    switch (b->substate)
    {
    case 0:
        b->unk11A8 = 0;
        if (Flag_Test(1) || Flag_Test(0xD5))
        {
            BattleMenu_SetMode(3, Menu_ExpandListTemplate((u16 *)gUnknown_081265BE, 0));
            b->state = 6;
            b->substate = 9;
            break;
        }
        if (!Flag_Test(3))
        {
            tmpl = (u16 *)gUnknown_0812490C;
            goto expand;
        }
        if (b->unkF6A != 0 || (Combatant_GetStatus(0) & 0xB160))
        {
            id = (Combatant_GetStatus(0) & 0xB160) ? 0x161 : 0x160;
            goto lookup;
        }
        if (sub_080ED8F4() & 0x80)
        {
            text = MessageBox_ComposeNameText(b->combatants[Battle_ActiveSide()], gUnknown_0812466C);
            goto show;
        }
        BattleMenu_SetMode(3, Menu_ExpandListTemplate((u16 *)gUnknown_0812634E, 0));
        b->substate = 1;
        sub_080E5A18(8);
        b->unk11A8 = 1;
        break;
    case 1:
        b->substate = 3;
        *(u16 *)(gUnk_03006434 + 0x122) = 0;
        if (Battle_IsTwoSided() == 1)
        {
            if (sub_080EDA24(0) && sub_080EDA24(1))
            {
                b->unk97E = 0;
                b->substate = 2;
                break;
            }
            if (!sub_080EDA24(0))
            {
                *(u16 *)(gUnk_03006434 + 0x122) = 1;
                who = (u16 *)&b->combatants[1];
            }
            else
            {
                *(u16 *)(gUnk_03006434 + 0x122) = 0;
                who = (u16 *)&b->combatants[0];
            }
        }
        else
        {
            who = (u16 *)&b->combatants[0];
        }
        sub_0813EB84(*who, 0xFFFF);
        break;
    case 2:
        r = sub_080E6FA0();
        if (r == 3)
        {
            s16 *sel = (s16 *)(gUnk_03006434 + 0x122);

            *sel = b->unk695;
            b->substate = r;
            if (*sel == 0)
                sub_0813EB84(*(u16 *)&b->combatants[0], *(u16 *)&b->combatants[1]);
            else
                sub_0813EB84(*(u16 *)&b->combatants[1], *(u16 *)&b->combatants[0]);
        }
        else if (r == 2)
        {
            BattleMenu_Reset();
            b->state = 6;
            b->unk11A8 = 0;
            goto finish;
        }
        break;
    case 3:
        BattleMenu_Reset();
        Window_SetHeight(b->window, 8);
        b->unk118E = 0xFFFF;
        sub_0813E914();
        sub_080C7430();
        sub_080C7648();
        b->unk11B2 = 10;
        b->substate = 4;
        /* fall through */
    case 4:
        if (--b->unk11B2 == 0)
            b->substate = 5;
        break;
    case 5:
        if (sub_0813EB60() != 0xFFFF)
        {
            sub_080EEF98();
            sub_080C7414();
            sub_080C762C();
            b->substate = 6;
        }
        break;
    case 6:
        if (sub_080ED8F4() & 0x80)
            sub_080EC948();
        res = sub_080EFA9C();
        sub_080EC2E4();
        if (res == 6 || res == 8 || res == 12 || res == 5)
            b->unkEC0 = 1;
        if (res == 4)
        {
            id = 0x2000;
            goto escape;
        }
        if ((res >= 9 && res <= 11) || (res >= 6 && res <= 7) || res == 12)
        {
            id = 0x200;
        escape:
            sub_080ED90C(id);
            b->substate = 0;
            b->state = 14;
            task->result = 1;
            if (b->window != NULL)
            {
                Window_Close(b->window, 0);
                b->window = NULL;
            }
        }
        else
        {
            Window_SetHeight(b->window, 2);
            b->substate = 7;
        }
        break;
    case 7:
        res = sub_080EFA9C();
        switch (res)
        {
        case 2:
            sub_080EC948();
            BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(0x167), 0));
            b->substate = 9;
            b->state = 10;
            if (b->unkF6A == 0)
                sub_080C6FF0();
            else
                sub_080C7038();
            break;
        case 3:
            id = 0x166;
        lookup:
            tmpl = Battle_GetMessage(id);
        expand:
            text = Menu_ExpandListTemplate(tmpl, 0);
        show:
            BattleMenu_SetMode(3, text);
            b->state = 6;
            b->substate = 9;
            break;
        case 5:
        case 8:
            b->state = 6;
            goto finish;
        default:
            b->state = 6;
        finish:
            task->result = 1;
            break;
        }
        break;
    case 8:
        if (BattleMsg_IsDone() == 1)
            sub_080E5A3C();
        break;
    case 9:
        if (BattleMsg_IsDone() == 1)
        {
            task->result = 1;
            b->substate = 0;
        }
        break;
    }
}
#else
NAKED
void sub_080EC35C(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    adds r6, r0, #0\n"
        "    ldr r5, .L080EC380\n"
        "    movs r0, #0\n"
        "    strh r0, [r6, #0x1c]\n"
        "    ldr r1, .L080EC384\n"
        "    adds r0, r5, r1\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r0, r2]\n"
        "    cmp r0, #9\n"
        "    bls .L080EC374\n"
        "    b .L080EC7F4\n"
        ".L080EC374:\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L080EC388\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080EC380: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080EC384: .4byte 0x0000097A\n"
        ".L080EC388: .4byte gUnknown_080EC38C\n"
        "    .global gUnknown_080EC38C\n"
        "gUnknown_080EC38C:\n"
        ".L080EC38C: @ jump table\n"
        "    .4byte .L080EC3B4\n"
        "    .4byte .L080EC4A8\n"
        "    .4byte .L080EC548\n"
        "    .4byte .L080EC5CC\n"
        "    .4byte .L080EC600\n"
        "    .4byte .L080EC630\n"
        "    .4byte .L080EC65C\n"
        "    .4byte .L080EC70C\n"
        "    .4byte .L080EC7CC\n"
        "    .4byte .L080EC7DE\n"
        ".L080EC3B4:\n"
        "    ldr r3, .L080EC3F0\n"
        "    adds r6, r5, r3\n"
        "    movs r0, #0\n"
        "    strh r0, [r6]\n"
        "    movs r0, #1\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L080EC3D0\n"
        "    movs r0, #0xd5\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    beq .L080EC400\n"
        ".L080EC3D0:\n"
        "    ldr r0, .L080EC3F4\n"
        "    movs r1, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetMode\n"
        "    ldr r0, .L080EC3F8\n"
        "    adds r1, r5, r0\n"
        "    movs r0, #6\n"
        "    strh r0, [r1]\n"
        "    ldr r2, .L080EC3FC\n"
        "    adds r1, r5, r2\n"
        "    b .L080EC79C\n"
        "    .byte 0x00, 0x00\n"
        ".L080EC3F0: .4byte 0x000011A8\n"
        ".L080EC3F4: .4byte gUnknown_081265BE\n"
        ".L080EC3F8: .4byte 0x00000978\n"
        ".L080EC3FC: .4byte 0x0000097A\n"
        ".L080EC400:\n"
        "    movs r0, #3\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L080EC414\n"
        "    ldr r0, .L080EC410\n"
        "    b .L080EC782\n"
        "    .byte 0x00, 0x00\n"
        ".L080EC410: .4byte gUnknown_0812490C\n"
        ".L080EC414:\n"
        "    ldr r1, .L080EC448\n"
        "    adds r0, r5, r1\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r0, r2]\n"
        "    cmp r0, #0\n"
        "    bne .L080EC42E\n"
        "    movs r0, #0\n"
        "    bl Combatant_GetStatus\n"
        "    ldr r1, .L080EC44C\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080EC450\n"
        ".L080EC42E:\n"
        "    movs r0, #0\n"
        "    bl Combatant_GetStatus\n"
        "    ldr r1, .L080EC44C\n"
        "    ands r1, r0\n"
        "    movs r0, #0xb0\n"
        "    lsls r0, r0, #1\n"
        "    cmp r1, #0\n"
        "    bne .L080EC442\n"
        "    b .L080EC77E\n"
        ".L080EC442:\n"
        "    adds r0, #1\n"
        "    b .L080EC77E\n"
        "    .byte 0x00, 0x00\n"
        ".L080EC448: .4byte 0x00000F6A\n"
        ".L080EC44C: .4byte 0x0000B160\n"
        ".L080EC450:\n"
        "    bl sub_080ED8F4\n"
        "    movs r1, #0x80\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080EC47C\n"
        "    bl Battle_ActiveSide\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0xe\n"
        "    movs r2, #0x99\n"
        "    lsls r2, r2, #4\n"
        "    adds r1, r5, r2\n"
        "    adds r1, r1, r0\n"
        "    ldr r0, [r1]\n"
        "    ldr r1, .L080EC478\n"
        "    bl MessageBox_ComposeNameText\n"
        "    b .L080EC788\n"
        "    .byte 0x00, 0x00\n"
        ".L080EC478: .4byte gUnknown_0812466C\n"
        ".L080EC47C:\n"
        "    ldr r0, .L080EC4A0\n"
        "    movs r1, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetMode\n"
        "    ldr r1, .L080EC4A4\n"
        "    adds r0, r5, r1\n"
        "    movs r4, #1\n"
        "    strh r4, [r0]\n"
        "    movs r0, #8\n"
        "    bl sub_080E5A18\n"
        "    strh r4, [r6]\n"
        "    b .L080EC7F4\n"
        "    .byte 0x00, 0x00\n"
        ".L080EC4A0: .4byte gUnknown_0812634E\n"
        ".L080EC4A4: .4byte 0x0000097A\n"
        ".L080EC4A8:\n"
        "    ldr r2, .L080EC4E8\n"
        "    adds r4, r5, r2\n"
        "    movs r6, #0\n"
        "    movs r0, #3\n"
        "    strh r0, [r4]\n"
        "    ldr r0, .L080EC4EC\n"
        "    ldr r0, [r0]\n"
        "    movs r3, #0x91\n"
        "    lsls r3, r3, #1\n"
        "    adds r0, r0, r3\n"
        "    strh r6, [r0]\n"
        "    bl Battle_IsTwoSided\n"
        "    cmp r0, #1\n"
        "    bne .L080EC534\n"
        "    movs r0, #0\n"
        "    bl sub_080EDA24\n"
        "    cmp r0, #0\n"
        "    beq .L080EC4F4\n"
        "    movs r0, #1\n"
        "    bl sub_080EDA24\n"
        "    cmp r0, #0\n"
        "    beq .L080EC4F4\n"
        "    ldr r1, .L080EC4F0\n"
        "    adds r0, r5, r1\n"
        "    strh r6, [r0]\n"
        "    movs r0, #2\n"
        "    strh r0, [r4]\n"
        "    b .L080EC7F4\n"
        "    .byte 0x00, 0x00\n"
        ".L080EC4E8: .4byte 0x0000097A\n"
        ".L080EC4EC: .4byte 0x03006434 @ IWRAM+0x6434\n"
        ".L080EC4F0: .4byte 0x0000097E\n"
        ".L080EC4F4:\n"
        "    movs r0, #0\n"
        "    bl sub_080EDA24\n"
        "    cmp r0, #0\n"
        "    beq .L080EC518\n"
        "    ldr r0, .L080EC514\n"
        "    ldr r0, [r0]\n"
        "    movs r2, #0x91\n"
        "    lsls r2, r2, #1\n"
        "    adds r1, r0, r2\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    movs r3, #0x99\n"
        "    lsls r3, r3, #4\n"
        "    adds r0, r5, r3\n"
        "    b .L080EC53A\n"
        ".L080EC514: .4byte 0x03006434 @ IWRAM+0x6434\n"
        ".L080EC518:\n"
        "    ldr r0, .L080EC52C\n"
        "    ldr r0, [r0]\n"
        "    movs r2, #0x91\n"
        "    lsls r2, r2, #1\n"
        "    adds r1, r0, r2\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    ldr r3, .L080EC530\n"
        "    adds r0, r5, r3\n"
        "    b .L080EC53A\n"
        ".L080EC52C: .4byte 0x03006434 @ IWRAM+0x6434\n"
        ".L080EC530: .4byte 0x00000994\n"
        ".L080EC534:\n"
        "    movs r1, #0x99\n"
        "    lsls r1, r1, #4\n"
        "    adds r0, r5, r1\n"
        ".L080EC53A:\n"
        "    ldrh r0, [r0]\n"
        "    ldr r1, .L080EC544\n"
        "    bl sub_0813EB84\n"
        "    b .L080EC7F4\n"
        ".L080EC544: .4byte 0x0000FFFF\n"
        ".L080EC548:\n"
        "    bl sub_080E6FA0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #3\n"
        "    bne .L080EC5A8\n"
        "    ldr r0, .L080EC580\n"
        "    ldr r1, [r0]\n"
        "    ldr r3, .L080EC584\n"
        "    adds r0, r5, r3\n"
        "    ldrb r0, [r0]\n"
        "    movs r3, #0x91\n"
        "    lsls r3, r3, #1\n"
        "    adds r1, r1, r3\n"
        "    strh r0, [r1]\n"
        "    ldr r3, .L080EC588\n"
        "    adds r0, r5, r3\n"
        "    strh r2, [r0]\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r1, r2]\n"
        "    cmp r0, #0\n"
        "    bne .L080EC590\n"
        "    adds r3, #0x16\n"
        "    adds r0, r5, r3\n"
        "    ldrh r0, [r0]\n"
        "    ldr r2, .L080EC58C\n"
        "    b .L080EC59A\n"
        "    .byte 0x00, 0x00\n"
        ".L080EC580: .4byte 0x03006434 @ IWRAM+0x6434\n"
        ".L080EC584: .4byte 0x00000695\n"
        ".L080EC588: .4byte 0x0000097A\n"
        ".L080EC58C: .4byte 0x00000994\n"
        ".L080EC590:\n"
        "    ldr r3, .L080EC5A4\n"
        "    adds r0, r5, r3\n"
        "    ldrh r0, [r0]\n"
        "    movs r2, #0x99\n"
        "    lsls r2, r2, #4\n"
        ".L080EC59A:\n"
        "    adds r1, r5, r2\n"
        "    ldrh r1, [r1]\n"
        "    bl sub_0813EB84\n"
        "    b .L080EC7F4\n"
        ".L080EC5A4: .4byte 0x00000994\n"
        ".L080EC5A8:\n"
        "    cmp r2, #2\n"
        "    beq .L080EC5AE\n"
        "    b .L080EC7F4\n"
        ".L080EC5AE:\n"
        "    bl BattleMenu_Reset\n"
        "    ldr r3, .L080EC5C4\n"
        "    adds r1, r5, r3\n"
        "    movs r2, #0\n"
        "    movs r0, #6\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L080EC5C8\n"
        "    adds r0, r5, r1\n"
        "    strh r2, [r0]\n"
        "    b .L080EC7C0\n"
        ".L080EC5C4: .4byte 0x00000978\n"
        ".L080EC5C8: .4byte 0x000011A8\n"
        ".L080EC5CC:\n"
        "    bl BattleMenu_Reset\n"
        "    ldr r2, .L080EC61C\n"
        "    adds r0, r5, r2\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #8\n"
        "    bl Window_SetHeight\n"
        "    ldr r3, .L080EC620\n"
        "    adds r1, r5, r3\n"
        "    ldr r0, .L080EC624\n"
        "    strh r0, [r1]\n"
        "    bl sub_0813E914\n"
        "    bl sub_080C7430\n"
        "    bl sub_080C7648\n"
        "    ldr r0, .L080EC628\n"
        "    adds r1, r5, r0\n"
        "    movs r0, #0xa\n"
        "    strh r0, [r1]\n"
        "    ldr r2, .L080EC62C\n"
        "    adds r1, r5, r2\n"
        "    movs r0, #4\n"
        "    strh r0, [r1]\n"
        ".L080EC600:\n"
        "    ldr r3, .L080EC628\n"
        "    adds r1, r5, r3\n"
        "    ldrh r0, [r1]\n"
        "    subs r0, #1\n"
        "    strh r0, [r1]\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L080EC612\n"
        "    b .L080EC7F4\n"
        ".L080EC612:\n"
        "    ldr r0, .L080EC62C\n"
        "    adds r1, r5, r0\n"
        "    movs r0, #5\n"
        "    strh r0, [r1]\n"
        "    b .L080EC7F4\n"
        ".L080EC61C: .4byte 0x00000974\n"
        ".L080EC620: .4byte 0x0000118E\n"
        ".L080EC624: .4byte 0x0000FFFF\n"
        ".L080EC628: .4byte 0x000011B2\n"
        ".L080EC62C: .4byte 0x0000097A\n"
        ".L080EC630:\n"
        "    bl sub_0813EB60\n"
        "    ldr r1, .L080EC654\n"
        "    cmp r0, r1\n"
        "    bne .L080EC63C\n"
        "    b .L080EC7F4\n"
        ".L080EC63C:\n"
        "    bl sub_080EEF98\n"
        "    bl sub_080C7414\n"
        "    bl sub_080C762C\n"
        "    ldr r2, .L080EC658\n"
        "    adds r1, r5, r2\n"
        "    movs r0, #6\n"
        "    strh r0, [r1]\n"
        "    b .L080EC7F4\n"
        "    .byte 0x00, 0x00\n"
        ".L080EC654: .4byte 0x0000FFFF\n"
        ".L080EC658: .4byte 0x0000097A\n"
        ".L080EC65C:\n"
        "    bl sub_080ED8F4\n"
        "    movs r1, #0x80\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080EC66C\n"
        "    bl sub_080EC948\n"
        ".L080EC66C:\n"
        "    bl sub_080EFA9C\n"
        "    adds r4, r0, #0\n"
        "    bl sub_080EC2E4\n"
        "    cmp r4, #6\n"
        "    beq .L080EC686\n"
        "    cmp r4, #8\n"
        "    beq .L080EC686\n"
        "    cmp r4, #0xc\n"
        "    beq .L080EC686\n"
        "    cmp r4, #5\n"
        "    bne .L080EC690\n"
        ".L080EC686:\n"
        "    movs r3, #0xec\n"
        "    lsls r3, r3, #4\n"
        "    adds r1, r5, r3\n"
        "    movs r0, #1\n"
        "    strb r0, [r1]\n"
        ".L080EC690:\n"
        "    cmp r4, #4\n"
        "    bne .L080EC69A\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #6\n"
        "    b .L080EC6B0\n"
        ".L080EC69A:\n"
        "    adds r0, r4, #0\n"
        "    subs r0, #9\n"
        "    cmp r0, #2\n"
        "    bls .L080EC6AC\n"
        "    subs r0, r4, #6\n"
        "    cmp r0, #1\n"
        "    bls .L080EC6AC\n"
        "    cmp r4, #0xc\n"
        "    bne .L080EC6EC\n"
        ".L080EC6AC:\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #2\n"
        ".L080EC6B0:\n"
        "    bl sub_080ED90C\n"
        "    ldr r1, .L080EC6E0\n"
        "    adds r0, r5, r1\n"
        "    movs r7, #0\n"
        "    strh r7, [r0]\n"
        "    ldr r2, .L080EC6E4\n"
        "    adds r1, r5, r2\n"
        "    movs r0, #0xe\n"
        "    strh r0, [r1]\n"
        "    movs r0, #1\n"
        "    strh r0, [r6, #0x1c]\n"
        "    ldr r3, .L080EC6E8\n"
        "    adds r4, r5, r3\n"
        "    ldr r0, [r4]\n"
        "    cmp r0, #0\n"
        "    bne .L080EC6D4\n"
        "    b .L080EC7F4\n"
        ".L080EC6D4:\n"
        "    movs r1, #0\n"
        "    bl Window_Close\n"
        "    str r7, [r4]\n"
        "    b .L080EC7F4\n"
        "    .byte 0x00, 0x00\n"
        ".L080EC6E0: .4byte 0x0000097A\n"
        ".L080EC6E4: .4byte 0x00000978\n"
        ".L080EC6E8: .4byte 0x00000974\n"
        ".L080EC6EC:\n"
        "    ldr r1, .L080EC704\n"
        "    adds r0, r5, r1\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #2\n"
        "    bl Window_SetHeight\n"
        "    ldr r2, .L080EC708\n"
        "    adds r1, r5, r2\n"
        "    movs r0, #7\n"
        "    strh r0, [r1]\n"
        "    b .L080EC7F4\n"
        "    .byte 0x00, 0x00\n"
        ".L080EC704: .4byte 0x00000974\n"
        ".L080EC708: .4byte 0x0000097A\n"
        ".L080EC70C:\n"
        "    bl sub_080EFA9C\n"
        "    adds r4, r0, #0\n"
        "    cmp r4, #3\n"
        "    beq .L080EC77A\n"
        "    cmp r4, #3\n"
        "    bgt .L080EC720\n"
        "    cmp r4, #2\n"
        "    beq .L080EC72A\n"
        "    b .L080EC7B8\n"
        ".L080EC720:\n"
        "    cmp r4, #5\n"
        "    beq .L080EC7AC\n"
        "    cmp r4, #8\n"
        "    beq .L080EC7AC\n"
        "    b .L080EC7B8\n"
        ".L080EC72A:\n"
        "    bl sub_080EC948\n"
        "    ldr r0, .L080EC764\n"
        "    bl Battle_GetMessage\n"
        "    movs r1, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetMode\n"
        "    ldr r3, .L080EC768\n"
        "    adds r1, r5, r3\n"
        "    movs r0, #9\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L080EC76C\n"
        "    adds r1, r5, r0\n"
        "    movs r0, #0xa\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L080EC770\n"
        "    adds r0, r5, r1\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r0, r2]\n"
        "    cmp r0, #0\n"
        "    bne .L080EC774\n"
        "    bl sub_080C6FF0\n"
        "    b .L080EC7F4\n"
        ".L080EC764: .4byte 0x00000167\n"
        ".L080EC768: .4byte 0x0000097A\n"
        ".L080EC76C: .4byte 0x00000978\n"
        ".L080EC770: .4byte 0x00000F6A\n"
        ".L080EC774:\n"
        "    bl sub_080C7038\n"
        "    b .L080EC7F4\n"
        ".L080EC77A:\n"
        "    movs r0, #0xb3\n"
        "    lsls r0, r0, #1\n"
        ".L080EC77E:\n"
        "    bl Battle_GetMessage\n"
        ".L080EC782:\n"
        "    movs r1, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        ".L080EC788:\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetMode\n"
        "    ldr r3, .L080EC7A4\n"
        "    adds r1, r5, r3\n"
        "    movs r0, #6\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L080EC7A8\n"
        "    adds r1, r5, r0\n"
        ".L080EC79C:\n"
        "    movs r0, #9\n"
        "    strh r0, [r1]\n"
        "    b .L080EC7F4\n"
        "    .byte 0x00, 0x00\n"
        ".L080EC7A4: .4byte 0x00000978\n"
        ".L080EC7A8: .4byte 0x0000097A\n"
        ".L080EC7AC:\n"
        "    ldr r1, .L080EC7B4\n"
        "    adds r0, r5, r1\n"
        "    b .L080EC7BC\n"
        "    .byte 0x00, 0x00\n"
        ".L080EC7B4: .4byte 0x00000978\n"
        ".L080EC7B8:\n"
        "    ldr r2, .L080EC7C8\n"
        "    adds r0, r5, r2\n"
        ".L080EC7BC:\n"
        "    movs r1, #6\n"
        "    strh r1, [r0]\n"
        ".L080EC7C0:\n"
        "    movs r0, #1\n"
        "    strh r0, [r6, #0x1c]\n"
        "    b .L080EC7F4\n"
        "    .byte 0x00, 0x00\n"
        ".L080EC7C8: .4byte 0x00000978\n"
        ".L080EC7CC:\n"
        "    bl BattleMsg_IsDone\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bne .L080EC7F4\n"
        "    bl sub_080E5A3C\n"
        "    b .L080EC7F4\n"
        ".L080EC7DE:\n"
        "    bl BattleMsg_IsDone\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bne .L080EC7F4\n"
        "    movs r1, #0\n"
        "    strh r0, [r6, #0x1c]\n"
        "    ldr r3, .L080EC7FC\n"
        "    adds r0, r5, r3\n"
        "    strh r1, [r0]\n"
        ".L080EC7F4:\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080EC7FC: .4byte 0x0000097A\n"
    );
}
#endif

/* Escape attempt: message 0x144 = escaped, 0x145 = failed, 0x146 = blocked. */

// Battle_FleeTask @ 0x080EC800
void Battle_FleeTask(struct Task *task)
{
    struct BattleFlow *b = BFLOW;
    s32 r;
    u8 done;

    task->result = 0;
    switch (b->substate)
    {
    case 0:
        r = sub_080EDF0C();
        task->data.w[0] = r;
        switch (r)
        {
        case 0x144:
            BattleMenu_SetMode(3, MessageBox_ComposeWrappedText((u16 *)gUnknown_08126254, 0));
            break;
        case 0x145:
            BattleMenu_SetMode(3, MessageBox_ComposeWrappedText((u16 *)gUnknown_081262BE, 0));
            break;
        case 0x146:
            BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(r), 0));
            break;
        }
        b->substate = 1;
        break;
    case 1:
        done = BattleMsg_IsDone();
        if (done == 1)
        {
            if (task->data.w[0] != 0x144)
            {
                sub_080EC948();
                sub_080ED920(0xC000);
                b->substate = 0;
                b->state = 10;
                b->unk1122++;
                task->result = done;
                if (b->unkF6A == 0)
                    sub_080C6FF0();
                else
                    sub_080C7038();
            }
            else
            {
                sub_080ED90C(0x2000);
                if (gUnk_030063A0.unkC == 2)
                    gUnk_030063A0.unk14 = done;
                b->substate = 0;
                b->state = 14;
                task->result = done;
            }
        }
        break;
    }
}

// sub_080EC92C @ 0x080EC92C
void sub_080EC92C(struct Task *task)
{
    u8 done;

    task->result = 0;
    done = BattleMsg_IsDone();
    if (done == 1)
        task->result = done;
}

// sub_080EC948 @ 0x080EC948
void sub_080EC948(void)
{
    struct BattleFlow *b = BFLOW;

    if (b->unkF68 == 0)
    {
        b->unkF68 = 1;
        gUnk_030063A0.unk10 = sub_080EFEDC();
        sub_080ECF60(gUnk_030063A0.unk10);
    }
}

// sub_080EC97C @ 0x080EC97C
void sub_080EC97C(struct Task *task)
{
    s32 r = Battle_IsPartyDefeated();

    if (r == 1)
    {
        sub_080B9058();
        task->result = r;
    }
    else
    {
        task->result = 0;
    }
}

// BattleMsg_SetDone @ 0x080EC99C
void BattleMsg_SetDone(u8 done)
{
    struct BattleFlow *b = BFLOW;
    struct BFlowMsg *msg = &b->msg;

    msg->done = done;
}

// sub_080EC9AC @ 0x080EC9AC
void sub_080EC9AC(u8 id, u8 side, u16 arg)
{
    struct BattleFlow *b = BFLOW;
    struct Portrait *p = &b->portrait;

    p->task = Task_Create(gUnknown_086BF734, 0xFFFF);
    p->state = 1;
    p->unk1 = 0;
    p->frame = 0;
    p->tick = 0;
    p->id = id;
    p->unk6 = arg;
    if (id >= 200)
        p->y = 0x38;
    else
        p->y = 0x30;
    p->x = gUnknown_086BF72C[side];
    if (side == 1)
        p->x += b->portraitDx;
    else if (side == 2)
        p->x -= b->portraitDx;
    p->frames = gUnknown_0876CE10[p->id].anim[1];
    if (p->id < 200)
        sub_080C140C(8, 0x10);
}

// sub_080ECA60 @ 0x080ECA60
void sub_080ECA60(u8 id, u8 side, u16 arg)
{
    struct BattleFlow *b = BFLOW;
    struct Portrait *p = &b->portrait;

    p->task = Task_Create(gUnknown_086BF734, 0xFFFF);
    p->state = 1;
    p->frame = 0;
    p->tick = 0;
    p->id = id;
    p->unk6 = arg;
    if (id >= 200)
        p->y = 0x3A;
    else
        p->y = 0x32;
    p->x = gUnknown_086BF72C[side];
    if (side == 1)
        p->x += b->portraitDx;
    else if (side == 2)
        p->x -= b->portraitDx;
    p->frames = gUnknown_0876CE10[p->id].anim[1];
    if (p->id < 200)
        sub_080C140C(8, 0x10);
}

// sub_080ECB10 @ 0x080ECB10
bool32 sub_080ECB10(void)
{
    struct BattleFlow *b = BFLOW;
    struct Portrait *p = &b->portrait;

    if (p->state == 3)
    {
        p->state = 0;
        sub_080C1440();
        return TRUE;
    }
    return FALSE;
}

// sub_080ECB38 @ 0x080ECB38
void sub_080ECB38(void)
{
    struct BattleFlow *b = BFLOW;
    struct Portrait *p = &b->portrait;

    Task_End(p->task);
    p->state = 0;
    sub_080C1440();
}

// sub_080ECB5C @ 0x080ECB5C
void sub_080ECB5C(u8 state)
{
    BFLOW->portrait.state = state;
}

// sub_080ECB6C @ 0x080ECB6C
u32 sub_080ECB6C(u16 id, u8 bank)
{
    const struct PortraitInfo *info = &gUnknown_0876CE10[id];

    HuffUnComp(info->gfx[bank], gBgPictureBuffer);
}

// sub_080ECB98 @ 0x080ECB98
#ifdef NONMATCHING
u32 sub_080ECB98(u16 id, u8 bank)
{
    const struct PortraitInfo *info = &gUnknown_0876CE10[id];

    LZ77UnCompWram(gBgPictureBuffer, gUnk_030000B4 + bank * 0x800);
    if (bank == 0)
    {
        Palette_CopyWithEffect(3, info->palette, &gPaletteBuffer[0x1C0], 0x40, 0x20);
        Palette_MarkDirty();
    }
    return 0;
}
#else
NAKED
u32 sub_080ECB98(u16 id, u8 bank)
{
    asm_unified(
        ".L080ECB98:\n"
        "    push {r4, r5, lr}\n"
        "    sub sp, #4\n"
        "    adds r4, r1, #0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    lsls r4, r4, #0x18\n"
        "    lsrs r4, r4, #0x18\n"
        "    lsls r1, r0, #1\n"
        "    adds r1, r1, r0\n"
        "    lsls r1, r1, #3\n"
        "    ldr r0, .L080ECBE0\n"
        "    adds r5, r1, r0\n"
        "    ldr r0, .L080ECBE4\n"
        "    lsls r1, r4, #0xb\n"
        "    ldr r2, .L080ECBE8\n"
        "    adds r1, r1, r2\n"
        "    bl LZ77UnCompWram\n"
        "    cmp r4, #0\n"
        "    bne .L080ECBD4\n"
        "    ldr r2, .L080ECBEC\n"
        "    ldr r1, [r5, #4]\n"
        "    movs r0, #0x20\n"
        "    str r0, [sp]\n"
        "    movs r0, #3\n"
        "    movs r3, #0x40\n"
        "    bl Palette_CopyWithEffect\n"
        "    bl Palette_MarkDirty\n"
        ".L080ECBD4:\n"
        "    movs r0, #0\n"
        "    add sp, #4\n"
        "    pop {r4, r5}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L080ECBE0: .4byte gUnknown_0876CE10\n"
        ".L080ECBE4: .4byte 0x0200AFC8 @ EWRAM+0xAFC8\n"
        ".L080ECBE8: .4byte 0x030000B4 @ IWRAM+0xB4\n"
        ".L080ECBEC: .4byte 0x03003130 @ IWRAM+0x3130\n"
    );
}
#endif

// sub_080ECBF0 @ 0x080ECBF0
void sub_080ECBF0(u32 unused, u32 bank)
{
    struct BattleFlow *b = BFLOW;
    struct Portrait *p = &b->portrait;

    if (p->id <= 0xD2)
        sub_080ECB98(p->id, bank);
}

// sub_080ECC10 @ 0x080ECC10
void sub_080ECC10(u32 unused, u32 bank)
{
    struct BattleFlow *b = BFLOW;
    struct Portrait *p = &b->portrait;

    if (p->id <= 0xD2)
        sub_080ECB6C(p->id, bank);
}

// BattleSprite_DmaBank0 @ 0x080ECC30
void BattleSprite_DmaBank0(void)
{
    vu32 *dma = (vu32 *)0x040000D4;

    dma[0] = (u32)gUnk_030000B4;
    dma[1] = 0x06014000;
    dma[2] = 0x84000400;
    dma[2];
}

// BattleSprite_DmaBank1 @ 0x080ECC54
void BattleSprite_DmaBank1(void)
{
    vu32 *dma = (vu32 *)0x040000D4;

    dma[0] = (u32)gUnk_030010B4;
    dma[1] = 0x06015000;
    dma[2] = 0x84000400;
    dma[2];
}

// sub_080ECC78 @ 0x080ECC78
void sub_080ECC78(u32 unused, u32 bank)
{
    struct BattleFlow *b = BFLOW;
    struct Portrait *p = &b->portrait;

    if (p->id <= 0xD2)
    {
        if (bank == 0)
            VBlankTask_AddCounted(BattleSprite_DmaBank0, 1);
        else
            VBlankTask_AddCounted(BattleSprite_DmaBank1, 1);
    }
}

/* Advances and draws the portrait animation. Portrait 0xD2 also cycles palette colors 1-15. */
// BattleSprite_Animate @ 0x080ECCB0
#ifdef NONMATCHING
u8 BattleSprite_Animate(struct Portrait *p)
{
    const struct PortraitFrame *frames;
    const struct PortraitFrame *f;
    const struct PortraitInfo *info;
    const u16 *pal;
    u16 *dst;
    u8 k, i;

    f = &(frames = p->frames)[p->frame];
    if (p->tick == f->duration + p->unk1)
    {
        p->frame++;
        p->tick = 0;
        f = &frames[p->frame];
        if ((s32)f->sprite == -1)
        {
            if (p->id != 0xD2)
                return 0;
            p->frame--;
            p->tick = 1;
            f = &frames[p->frame];
        }
        if (f->duration == 0x100)
        {
            p->frame -= f->loopBack;
            f = &p->frames[p->frame];
        }
    }
    if (p->id == 0xD2)
    {
        info = &gUnknown_0876CE10[p->id];
        p->palPhase = (p->palPhase + 1) & 0x1F;
        k = p->palPhase >> 1;
        dst = &gPaletteBuffer[0x1C1];
        pal = info->palette;
        for (i = 0; i < 15; i++)
        {
            if (k == 0)
                k = 1;
            *dst++ = Color_ApplyEffect(pal[k]);
            k++;
            k &= 0xF;
        }
        Palette_MarkDirty();
    }
    Sprite_DrawPlain(f->sprite, 0, 0xC, 2, 0x200, p->x, p->y);
    p->tick++;
    return 1;
}
#else
NAKED
u8 BattleSprite_Animate(struct Portrait *p)
{
    asm_unified(
        ".L080ECCB0:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    sub sp, #0x10\n"
        "    adds r5, r0, #0\n"
        "    ldrb r3, [r5, #4]\n"
        "    lsls r0, r3, #3\n"
        "    ldr r4, [r5, #0x10]\n"
        "    adds r6, r4, r0\n"
        "    ldrb r2, [r5, #5]\n"
        "    ldrh r0, [r6, #4]\n"
        "    ldrb r1, [r5, #1]\n"
        "    adds r0, r0, r1\n"
        "    cmp r2, r0\n"
        "    bne .L080ECD18\n"
        "    adds r0, r3, #1\n"
        "    movs r1, #0\n"
        "    strb r0, [r5, #4]\n"
        "    strb r1, [r5, #5]\n"
        "    ldrb r2, [r5, #4]\n"
        "    lsls r0, r2, #3\n"
        "    adds r6, r4, r0\n"
        "    ldr r1, [r6]\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r1, r0\n"
        "    bne .L080ECCFE\n"
        "    ldrb r0, [r5, #2]\n"
        "    cmp r0, #0xd2\n"
        "    beq .L080ECCF0\n"
        "    movs r0, #0\n"
        "    b .L080ECD92\n"
        ".L080ECCF0:\n"
        "    subs r0, r2, #1\n"
        "    strb r0, [r5, #4]\n"
        "    movs r0, #1\n"
        "    strb r0, [r5, #5]\n"
        "    ldrb r0, [r5, #4]\n"
        "    lsls r0, r0, #3\n"
        "    adds r6, r4, r0\n"
        ".L080ECCFE:\n"
        "    ldrh r1, [r6, #4]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    cmp r1, r0\n"
        "    bne .L080ECD18\n"
        "    ldrb r1, [r6, #6]\n"
        "    ldrb r0, [r5, #4]\n"
        "    subs r0, r0, r1\n"
        "    strb r0, [r5, #4]\n"
        "    ldrb r0, [r5, #4]\n"
        "    lsls r0, r0, #3\n"
        "    ldr r1, [r5, #0x10]\n"
        "    adds r6, r1, r0\n"
        ".L080ECD18:\n"
        "    ldrb r0, [r5, #2]\n"
        "    cmp r0, #0xd2\n"
        "    bne .L080ECD70\n"
        "    lsls r0, r0, #4\n"
        "    movs r1, #0xd2\n"
        "    lsls r1, r1, #3\n"
        "    adds r0, r0, r1\n"
        "    ldr r2, .L080ECDA0\n"
        "    adds r2, r2, r0\n"
        "    ldrb r0, [r5, #8]\n"
        "    adds r0, #1\n"
        "    movs r1, #0x1f\n"
        "    ands r0, r1\n"
        "    strb r0, [r5, #8]\n"
        "    lsrs r4, r0, #1\n"
        "    ldr r3, .L080ECDA4\n"
        "    ldr r2, [r2, #4]\n"
        "    mov r8, r2\n"
        "    movs r7, #0\n"
        ".L080ECD3E:\n"
        "    cmp r4, #0\n"
        "    bne .L080ECD44\n"
        "    movs r4, #1\n"
        ".L080ECD44:\n"
        "    lsls r0, r4, #1\n"
        "    add r0, r8\n"
        "    ldrh r0, [r0]\n"
        "    str r3, [sp, #0xc]\n"
        "    bl Color_ApplyEffect\n"
        "    ldr r3, [sp, #0xc]\n"
        "    strh r0, [r3]\n"
        "    adds r3, #2\n"
        "    adds r1, r4, #1\n"
        "    lsls r1, r1, #0x18\n"
        "    movs r0, #0xf0\n"
        "    lsls r0, r0, #0x14\n"
        "    ands r0, r1\n"
        "    lsrs r4, r0, #0x18\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r7, r0, #0x18\n"
        "    cmp r7, #0xe\n"
        "    bls .L080ECD3E\n"
        "    bl Palette_MarkDirty\n"
        ".L080ECD70:\n"
        "    ldr r0, [r6]\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #2\n"
        "    str r1, [sp]\n"
        "    ldrh r1, [r5, #0xc]\n"
        "    str r1, [sp, #4]\n"
        "    ldrh r1, [r5, #0xe]\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0xc\n"
        "    movs r3, #2\n"
        "    bl Sprite_DrawPlain\n"
        "    ldrb r0, [r5, #5]\n"
        "    adds r0, #1\n"
        "    strb r0, [r5, #5]\n"
        "    movs r0, #1\n"
        ".L080ECD92:\n"
        "    add sp, #0x10\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L080ECDA0: .4byte gUnknown_0876CE10\n"
        ".L080ECDA4: .4byte 0x03003132 @ IWRAM+0x3132\n"
    );
}
#endif

// sub_080ECDA8 @ 0x080ECDA8
void sub_080ECDA8(struct Task *task)
{
    struct BattleFlow *b = BFLOW;
    struct Portrait *p = &b->portrait;

    task->result = 0;
    if (p->id > 0xD2)
    {
        task->result = 1;
        return;
    }
    p->state = 2;
    if (BattleSprite_Animate(p) == 0)
        task->result = 1;
}

// sub_080ECDDC @ 0x080ECDDC
void sub_080ECDDC(void)
{
    BFLOW->portrait.state = 3;
}

// sub_080ECDF0 @ 0x080ECDF0
void sub_080ECDF0(void)
{
    struct BattleFlow *b = BFLOW;
    struct Portrait *p = &b->portrait;

    sub_08126D34(p->unk6);
}

// sub_080ECE08 @ 0x080ECE08
void sub_080ECE08(u8 state)
{
    struct BattleFlow *b = BFLOW;
    struct Portrait *p = &b->portrait;

    p->task = Task_Create(gUnknown_086BF840, 0xFFFF);
    p->state = state;
}

// sub_080ECE38 @ 0x080ECE38
#ifdef NONMATCHING
void sub_080ECE38(u16 id, u8 unused, u8 kind)
{
    struct BattleFlow *b = BFLOW;
    struct Portrait *p = &b->portrait;
    s16 i = id;

    if (p->state == 4)
        p->sel = i;
    switch (kind)
    {
    case 0:
        b->handles[i] = sub_080C88C0(i);
        break;
    case 3:
        b->handles[i] = sub_080C8890(i);
        break;
    case 1:
        b->handles[i] = sub_080C88A8(i);
        break;
    case 5:
        b->handles[i] = sub_080C88D8(i);
        break;
    }
}
#else
NAKED
void sub_080ECE38(u16 id, u8 unused, u8 kind)
{
    asm_unified(
        ".L080ECE38:\n"
        "    push {r4, r5, r6, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    lsls r1, r1, #0x18\n"
        "    lsrs r1, r1, #0x18\n"
        "    lsls r2, r2, #0x18\n"
        "    lsrs r2, r2, #0x18\n"
        "    adds r5, r2, #0\n"
        "    ldr r6, .L080ECE68\n"
        "    movs r0, #0x8b\n"
        "    lsls r0, r0, #5\n"
        "    adds r3, r6, r0\n"
        "    ldrb r0, [r3]\n"
        "    cmp r0, #4\n"
        "    bne .L080ECE58\n"
        "    strb r4, [r3, #3]\n"
        ".L080ECE58:\n"
        "    cmp r2, #1\n"
        "    beq .L080ECE8A\n"
        "    cmp r2, #1\n"
        "    bgt .L080ECE6C\n"
        "    cmp r2, #0\n"
        "    beq .L080ECE76\n"
        "    b .L080ECEA6\n"
        "    .byte 0x00, 0x00\n"
        ".L080ECE68: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080ECE6C:\n"
        "    cmp r5, #3\n"
        "    beq .L080ECE80\n"
        "    cmp r5, #5\n"
        "    beq .L080ECE94\n"
        "    b .L080ECEA6\n"
        ".L080ECE76:\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r0, r4, #0x10\n"
        "    bl sub_080C88C0\n"
        "    b .L080ECE9C\n"
        ".L080ECE80:\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r0, r4, #0x10\n"
        "    bl sub_080C8890\n"
        "    b .L080ECE9C\n"
        ".L080ECE8A:\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r0, r4, #0x10\n"
        "    bl sub_080C88A8\n"
        "    b .L080ECE9C\n"
        ".L080ECE94:\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r0, r4, #0x10\n"
        "    bl sub_080C88D8\n"
        ".L080ECE9C:\n"
        "    asrs r4, r4, #0xe\n"
        "    adds r1, r6, #0\n"
        "    adds r1, #0x10\n"
        "    adds r4, r4, r1\n"
        "    str r0, [r4]\n"
        ".L080ECEA6:\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

// sub_080ECEAC @ 0x080ECEAC
void sub_080ECEAC(struct Task *task)
{
    struct BattleFlow *b = BFLOW;
    struct Portrait *p = &b->portrait;
    u8 n, i;

    if (p->state == 4)
    {
        if (sub_080C88F0(b->handles[p->sel]) == 1)
            task->result = 1;
    }
    else if (p->state == 5)
    {
        n = 0;
        for (i = 0; i < 6; i++)
        {
            if (sub_080C88F0(b->handles[i]) == 1)
                n++;
        }
        if (n == 6)
            task->result = 1;
    }
    else
    {
        task->result = 1;
    }
}

// sub_080ECF10 @ 0x080ECF10
void sub_080ECF10(void)
{
    struct BattleFlow *b = BFLOW;
    struct Portrait *p = &b->portrait;
    u8 i;

    if (p->state == 4)
    {
        b->handles[p->sel] = 0;
    }
    else if (p->state == 5)
    {
        for (i = 0; i < 6; i++)
            b->handles[i] = 0;
    }
    p->state = 3;
    p->sel = 0;
}

// sub_080ECF60 @ 0x080ECF60
void sub_080ECF60(u16 se)
{
    sub_080C5170(se);
}

// sub_080ECF70 @ 0x080ECF70
void sub_080ECF70(u16 a)
{
    sub_08126D34(a);
}

// sub_080ECF80 @ 0x080ECF80
void sub_080ECF80(void)
{
    struct BattleFlow *b = BFLOW;
    struct Task *t;
    struct FadeData *d;

    t = Task_Create(gUnknown_086BF86C, 0xFFFF);
    b->fadeTask = t;
    d = (struct FadeData *)t->data.raw;
    d->a = 0;
    d->b = 0;
    d->level = 0x10;
    d->count = 0x10;
    d->tick = 0;
}

// sub_080ECFB0 @ 0x080ECFB0
void sub_080ECFB0(struct Task *task)
{
    struct FadeData *d = (struct FadeData *)task->data.raw;

    task->result = 0;
    if (d->tick == 1)
    {
        d->tick = 0;
        if (--d->count > 0)
        {
            d->level = d->count;
        }
        else
        {
            task->result = 1;
            d->a = 0;
            d->b = 0;
            d->level = 0;
            d->count = 0;
        }
    }
    else
    {
        d->tick++;
    }
    sub_080E845C(d->a, d->b, d->level);
}
