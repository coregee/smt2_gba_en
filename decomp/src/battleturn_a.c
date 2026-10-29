/* Battle turn execution and result screens. */

#include "global.h"
#include "battledisp.h"

// sub_080E941C @ 0x080E941C
/* Runs the actions of one turn in order, then decides whether the battle continues, was won
   (escaped / ended) or lost. */
#ifdef NONMATCHING
void sub_080E941C(struct Task *t)
{
    struct C15cBattle *b = BB;
    s16 actor;
    u32 r;
    s16 k;
    u8 j;

    t->result = 0;
    switch (b->substate)
    {
    case 0:
        b->unkECE = 0;
        sub_080F3120();
        sub_080F2D4C();
        Battle_BuildActionOrder();
        b->unkECC = Battle_GetLastOrderIndex();
        b->substate = 1;
        BattleFlags_Mask(~0x400);
    case 1:
        {
            u16 st = *(u16 *)(Battle_GetCombatant((s16)sub_080EFFC4(b->unkECE) + 0x8000) + 0x10) & 0xB1E0;

            if (st != 0)
            {
                b->substate = 3;
            }
            else
            {
                b->substate = 2;
                b->phase = st;
            }
        }
        break;
    case 2:
        if (sub_080F0434((s16)sub_080EFFC4(b->unkECE)))
            b->substate = 3;
        break;
    case 3:
        Party_FixFormation();
        Party_BuildMemberNameTiles();
        Hud_LoadAllMemberFaces();
        for (k = 0; k < 4; k++)
            Combatant_UpdateStats(k);
        actor = sub_080EFFC4(b->unkECE);
        if (actor <= 15)
        {
            for (j = 0; j < 6; j++)
            {
                if (GS->order[j] == actor)
                    break;
            }
            if (j < 6)
                sub_080C8490(j);
        }
        r = sub_080ED9F4();
        if (r == 0)
        {
            sub_080C84A0();
            b->substate = r;
            b->state = 14;
            gUnk_030063A0.active = 4;
            t->result = 1;
            if (b->unkF6A != 0)
                gUnk_030063A0.unk0A = r;
        }
        else if (Battle_IsPartyDefeated())
        {
            sub_080ED90C(0x2000);
            b->substate = 0;
            b->state = 14;
            t->result = 1;
            sub_080C84A0();
            gUnk_030063A0.active = 3;
            b->state = 15;
            if (b->unkF6A != 0)
                gUnk_030063A0.unk0A = 0;
        }
        else if ((r = sub_080ED8F4() & 0x2200) != 0)
        {
            if ((sub_080ED8F4() & 0x2000) && gUnk_030063A0.unk0C == 2)
                gUnk_030063A0.unk14 = 1;
            t->result = 1;
            b->substate = 0;
            b->state = 14;
            for (k = 0; k < 8; k++)
                sub_080E7538(k, 0, 0);
        }
        else
        {
            b->unkECE++;
            if (b->unkECE > b->unkECC)
            {
                b->unkECE = r;
                b->unkEC0 = 1;
                b->unk11AC = 0xFFFF;
                b->unk11AE = -1;
                sub_080EF2A0();
                sub_080C84A0();
                if (++b->unk11A4 == 4)
                    b->unk11A4 = r;
                ((u16 *)gUnk_03006434)[1] = r;
                ((u16 *)gUnk_03006434)[0] &= 0xFF7F;
                if ((u16)(sub_080ED8F4() & 0x4000))
                {
                    b->substate = 1;
                    b->state = 13;
                }
                else
                {
                    b->substate = 0;
                    b->state = 6;
                }
                t->result = 1;
                if (b->unkF6A != 0)
                    gUnk_030063A0.unk0A = 0;
            }
            else
            {
                b->substate = 1;
            }
        }
        break;
    case 4:
        break;
    }
}
#else
NAKED
void sub_080E941C(struct Task *t)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    adds r7, r0, #0\n"
        "    ldr r6, .L080E9440\n"
        "    movs r0, #0\n"
        "    strh r0, [r7, #0x1c]\n"
        "    ldr r1, .L080E9444\n"
        "    adds r0, r6, r1\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r0, r2]\n"
        "    cmp r0, #4\n"
        "    bls .L080E9434\n"
        "    b .L080E976C\n"
        ".L080E9434:\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L080E9448\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080E9440: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080E9444: .4byte 0x0000097A\n"
        ".L080E9448: .4byte gUnknown_080E944C\n"
        "    .global gUnknown_080E944C\n"
        "gUnknown_080E944C:\n"
        ".L080E944C: @ jump table\n"
        "    .4byte .L080E9460\n"
        "    .4byte .L080E948C\n"
        "    .4byte .L080E94E4\n"
        "    .4byte .L080E9510\n"
        "    .4byte .L080E976C\n"
        ".L080E9460:\n"
        "    ldr r3, .L080E94B8\n"
        "    adds r1, r6, r3\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    bl sub_080F3120\n"
        "    bl sub_080F2D4C\n"
        "    bl Battle_BuildActionOrder\n"
        "    bl Battle_GetLastOrderIndex\n"
        "    ldr r4, .L080E94BC\n"
        "    adds r1, r6, r4\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L080E94C0\n"
        "    adds r1, r6, r0\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L080E94C4\n"
        "    bl BattleFlags_Mask\n"
        ".L080E948C:\n"
        "    ldr r1, .L080E94B8\n"
        "    adds r0, r6, r1\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r0, r2]\n"
        "    bl sub_080EFFC4\n"
        "    lsls r0, r0, #0x10\n"
        "    movs r3, #0x80\n"
        "    lsls r3, r3, #0x18\n"
        "    adds r0, r0, r3\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    ldrh r0, [r0, #0x10]\n"
        "    ldr r2, .L080E94C8\n"
        "    ands r2, r0\n"
        "    cmp r2, #0\n"
        "    beq .L080E94CC\n"
        "    ldr r4, .L080E94C0\n"
        "    adds r1, r6, r4\n"
        "    movs r0, #3\n"
        "    b .L080E976A\n"
        ".L080E94B8: .4byte 0x00000ECE\n"
        ".L080E94BC: .4byte 0x00000ECC\n"
        ".L080E94C0: .4byte 0x0000097A\n"
        ".L080E94C4: .4byte 0xFFFFFBFF\n"
        ".L080E94C8: .4byte 0x0000B1E0\n"
        ".L080E94CC:\n"
        "    ldr r1, .L080E94DC\n"
        "    adds r0, r6, r1\n"
        "    movs r1, #2\n"
        "    strh r1, [r0]\n"
        "    ldr r3, .L080E94E0\n"
        "    adds r0, r6, r3\n"
        "    strh r2, [r0]\n"
        "    b .L080E976C\n"
        ".L080E94DC: .4byte 0x0000097A\n"
        ".L080E94E0: .4byte 0x0000097C\n"
        ".L080E94E4:\n"
        "    ldr r4, .L080E9508\n"
        "    adds r0, r6, r4\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    bl sub_080EFFC4\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    bl sub_080F0434\n"
        "    cmp r0, #0\n"
        "    bne .L080E94FE\n"
        "    b .L080E976C\n"
        ".L080E94FE:\n"
        "    ldr r2, .L080E950C\n"
        "    adds r1, r6, r2\n"
        "    movs r0, #3\n"
        "    b .L080E976A\n"
        "    .byte 0x00, 0x00\n"
        ".L080E9508: .4byte 0x00000ECE\n"
        ".L080E950C: .4byte 0x0000097A\n"
        ".L080E9510:\n"
        "    bl Party_FixFormation\n"
        "    bl Party_BuildMemberNameTiles\n"
        "    bl Hud_LoadAllMemberFaces\n"
        "    movs r5, #0\n"
        ".L080E951E:\n"
        "    lsls r4, r5, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_UpdateStats\n"
        "    adds r4, #1\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r5, r4, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    cmp r4, #3\n"
        "    ble .L080E951E\n"
        "    ldr r3, .L080E95B4\n"
        "    adds r0, r6, r3\n"
        "    movs r4, #0\n"
        "    ldrsh r0, [r0, r4]\n"
        "    bl sub_080EFFC4\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r2, r0, #0x10\n"
        "    cmp r2, #0xf\n"
        "    bgt .L080E957A\n"
        "    movs r1, #0\n"
        "    ldr r0, .L080E95B8\n"
        "    movs r4, #0xa2\n"
        "    lsls r4, r4, #4\n"
        "    adds r3, r0, r4\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r3, r0]\n"
        "    cmp r0, r2\n"
        "    beq .L080E9570\n"
        ".L080E955A:\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r1, r0, #0x18\n"
        "    cmp r1, #5\n"
        "    bhi .L080E957A\n"
        "    adds r0, r1, r3\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    cmp r0, r2\n"
        "    bne .L080E955A\n"
        ".L080E9570:\n"
        "    cmp r1, #5\n"
        "    bhi .L080E957A\n"
        "    adds r0, r1, #0\n"
        "    bl sub_080C8490\n"
        ".L080E957A:\n"
        "    bl sub_080ED9F4\n"
        "    adds r4, r0, #0\n"
        "    cmp r4, #0\n"
        "    bne .L080E95CC\n"
        "    bl sub_080C84A0\n"
        "    ldr r1, .L080E95BC\n"
        "    adds r0, r6, r1\n"
        "    strh r4, [r0]\n"
        "    ldr r2, .L080E95C0\n"
        "    adds r1, r6, r2\n"
        "    movs r0, #0xe\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L080E95C4\n"
        "    movs r0, #4\n"
        "    strh r0, [r1]\n"
        "    movs r0, #1\n"
        "    strh r0, [r7, #0x1c]\n"
        "    ldr r3, .L080E95C8\n"
        "    adds r0, r6, r3\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r0, r2]\n"
        "    cmp r0, #0\n"
        "    bne .L080E95AE\n"
        "    b .L080E976C\n"
        ".L080E95AE:\n"
        "    strh r4, [r1, #0xa]\n"
        "    b .L080E976C\n"
        "    .byte 0x00, 0x00\n"
        ".L080E95B4: .4byte 0x00000ECE\n"
        ".L080E95B8: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080E95BC: .4byte 0x0000097A\n"
        ".L080E95C0: .4byte 0x00000978\n"
        ".L080E95C4: .4byte 0x030063A0 @ IWRAM+0x63A0\n"
        ".L080E95C8: .4byte 0x00000F6A\n"
        ".L080E95CC:\n"
        "    bl Battle_IsPartyDefeated\n"
        "    cmp r0, #0\n"
        "    beq .L080E9620\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #6\n"
        "    bl sub_080ED90C\n"
        "    ldr r3, .L080E9610\n"
        "    adds r0, r6, r3\n"
        "    movs r5, #0\n"
        "    strh r5, [r0]\n"
        "    ldr r0, .L080E9614\n"
        "    adds r4, r6, r0\n"
        "    movs r0, #0xe\n"
        "    strh r0, [r4]\n"
        "    movs r0, #1\n"
        "    strh r0, [r7, #0x1c]\n"
        "    bl sub_080C84A0\n"
        "    ldr r1, .L080E9618\n"
        "    movs r0, #3\n"
        "    strh r0, [r1]\n"
        "    movs r0, #0xf\n"
        "    strh r0, [r4]\n"
        "    ldr r2, .L080E961C\n"
        "    adds r0, r6, r2\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r0, r3]\n"
        "    cmp r0, #0\n"
        "    bne .L080E960C\n"
        "    b .L080E976C\n"
        ".L080E960C:\n"
        "    strh r5, [r1, #0xa]\n"
        "    b .L080E976C\n"
        ".L080E9610: .4byte 0x0000097A\n"
        ".L080E9614: .4byte 0x00000978\n"
        ".L080E9618: .4byte 0x030063A0 @ IWRAM+0x63A0\n"
        ".L080E961C: .4byte 0x00000F6A\n"
        ".L080E9620:\n"
        "    bl sub_080ED8F4\n"
        "    movs r4, #0x88\n"
        "    lsls r4, r4, #6\n"
        "    ands r4, r0\n"
        "    cmp r4, #0\n"
        "    beq .L080E9688\n"
        "    bl sub_080ED8F4\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #6\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080E9648\n"
        "    ldr r1, .L080E967C\n"
        "    ldrh r0, [r1, #0xc]\n"
        "    cmp r0, #2\n"
        "    bne .L080E9648\n"
        "    movs r0, #1\n"
        "    strh r0, [r1, #0x14]\n"
        ".L080E9648:\n"
        "    movs r1, #0\n"
        "    movs r0, #1\n"
        "    strh r0, [r7, #0x1c]\n"
        "    ldr r4, .L080E9680\n"
        "    adds r0, r6, r4\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L080E9684\n"
        "    adds r1, r6, r0\n"
        "    movs r0, #0xe\n"
        "    strh r0, [r1]\n"
        "    movs r5, #0\n"
        ".L080E965E:\n"
        "    lsls r0, r5, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    bl sub_080E7538\n"
        "    lsls r0, r5, #0x10\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #9\n"
        "    adds r0, r0, r1\n"
        "    lsrs r5, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #7\n"
        "    ble .L080E965E\n"
        "    b .L080E976C\n"
        ".L080E967C: .4byte 0x030063A0 @ IWRAM+0x63A0\n"
        ".L080E9680: .4byte 0x0000097A\n"
        ".L080E9684: .4byte 0x00000978\n"
        ".L080E9688:\n"
        "    ldr r3, .L080E970C\n"
        "    adds r2, r6, r3\n"
        "    ldrh r0, [r2]\n"
        "    adds r0, #1\n"
        "    strh r0, [r2]\n"
        "    subs r3, #2\n"
        "    adds r1, r6, r3\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r1, r3]\n"
        "    cmp r0, r1\n"
        "    ble .L080E9764\n"
        "    strh r4, [r2]\n"
        "    movs r1, #0xec\n"
        "    lsls r1, r1, #4\n"
        "    adds r0, r6, r1\n"
        "    movs r5, #1\n"
        "    strb r5, [r0]\n"
        "    ldr r2, .L080E9710\n"
        "    adds r1, r6, r2\n"
        "    ldr r0, .L080E9714\n"
        "    strh r0, [r1]\n"
        "    ldr r3, .L080E9718\n"
        "    adds r1, r6, r3\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    strh r0, [r1]\n"
        "    bl sub_080EF2A0\n"
        "    bl sub_080C84A0\n"
        "    ldr r0, .L080E971C\n"
        "    adds r1, r6, r0\n"
        "    ldrh r0, [r1]\n"
        "    adds r0, #1\n"
        "    strh r0, [r1]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #4\n"
        "    bne .L080E96DC\n"
        "    strh r4, [r1]\n"
        ".L080E96DC:\n"
        "    ldr r0, .L080E9720\n"
        "    ldr r1, [r0]\n"
        "    strh r4, [r1, #2]\n"
        "    ldrh r2, [r1]\n"
        "    ldr r0, .L080E9724\n"
        "    ands r0, r2\n"
        "    strh r0, [r1]\n"
        "    bl sub_080ED8F4\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #7\n"
        "    ands r1, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    cmp r1, #0\n"
        "    beq .L080E9730\n"
        "    ldr r1, .L080E9728\n"
        "    adds r0, r6, r1\n"
        "    strh r5, [r0]\n"
        "    ldr r2, .L080E972C\n"
        "    adds r1, r6, r2\n"
        "    movs r0, #0xd\n"
        "    b .L080E973C\n"
        "    .byte 0x00, 0x00\n"
        ".L080E970C: .4byte 0x00000ECE\n"
        ".L080E9710: .4byte 0x000011AC\n"
        ".L080E9714: .4byte 0x0000FFFF\n"
        ".L080E9718: .4byte 0x000011AE\n"
        ".L080E971C: .4byte 0x000011A4\n"
        ".L080E9720: .4byte 0x03006434 @ IWRAM+0x6434\n"
        ".L080E9724: .4byte 0x0000FF7F\n"
        ".L080E9728: .4byte 0x0000097A\n"
        ".L080E972C: .4byte 0x00000978\n"
        ".L080E9730:\n"
        "    ldr r3, .L080E9754\n"
        "    adds r0, r6, r3\n"
        "    strh r1, [r0]\n"
        "    ldr r4, .L080E9758\n"
        "    adds r1, r6, r4\n"
        "    movs r0, #6\n"
        ".L080E973C:\n"
        "    strh r0, [r1]\n"
        "    strh r5, [r7, #0x1c]\n"
        "    ldr r1, .L080E975C\n"
        "    adds r0, r6, r1\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r0, r2]\n"
        "    cmp r0, #0\n"
        "    beq .L080E976C\n"
        "    ldr r1, .L080E9760\n"
        "    movs r0, #0\n"
        "    strh r0, [r1, #0xa]\n"
        "    b .L080E976C\n"
        ".L080E9754: .4byte 0x0000097A\n"
        ".L080E9758: .4byte 0x00000978\n"
        ".L080E975C: .4byte 0x00000F6A\n"
        ".L080E9760: .4byte 0x030063A0 @ IWRAM+0x63A0\n"
        ".L080E9764:\n"
        "    ldr r3, .L080E9774\n"
        "    adds r1, r6, r3\n"
        "    movs r0, #1\n"
        ".L080E976A:\n"
        "    strh r0, [r1]\n"
        ".L080E976C:\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080E9774: .4byte 0x0000097A\n"
    );
}
#endif


// sub_080E9778 @ 0x080E9778
void sub_080E9778(void)
{
    struct C15cBattle *b = BB;

    b->state = 10;
    b->substate = 0;
}

// sub_080E9798 @ 0x080E9798
void sub_080E9798(struct Task *t)
{
    struct C15cBattle *b = BB;

    t->result = 0;
    switch (gUnk_030063A0.unk0A)
    {
    case 0:
        if (b->unkF6A == 0)
        {
            t->result = 1;
            break;
        }
        if (gUnk_030063A0.active == 1)
            gUnk_030063A0.unk06 = 5;
        gUnk_030063A0.unk0A = 2;
        break;
    case 1:
        if (gUnk_030063A0.unk06 == 5)
        {
            b->state = 16;
            t->result = 1;
        }
        t->result = 1;
        gUnk_030063A0.unk0A = 0;
        break;
    case 2:
        gUnk_030063A0.unk0A = 1;
        break;
    }
}

// sub_080E980C @ 0x080E980C
/* 1 when any enemy is still around (sub_080F0168, sub_080F01EC, sub_080F0194). */
u16 sub_080E980C(void)
{
    struct C15cBattle *b = BB;
    s16 n = b->unk99C;
    u16 r = sub_080F0168() != 0;
    u32 i;

    for (i = 0; i < n; i++)
    {
        if (sub_080F01EC(i) != -1)
            r = 1;
    }
    for (i = 0; i < 4; i++)
    {
        if (sub_080F0194(i))
            r = 1;
    }
    if (sub_080F0168())
        r = 1;
    return r;
}

// sub_080E9870 @ 0x080E9870
/* Victory message (or none); shows it in the message window. */
u16 *sub_080E9870(void)
{
    struct C15cBattle *b = BB;
    u16 *msg = NULL;

    if (sub_080ED8F4() & 0x200)
    {
        BattleMenu_Reset();
        return NULL;
    }
    if (Battle_IsTwoSided() == 1)
    {
        if ((s16)sub_080E980C() == 1 || Flag_Test(0xD5))
            msg = (u16 *)gUnknown_086BEC18;
    }
    else
    {
        if ((s16)sub_080E980C() == 1 || Flag_Test(0xD5))
            msg = MessageBox_ComposeRaceNameText(b->groups[0], gUnknown_08124284);
    }
    if (msg != NULL)
        BattleMenu_SetMode(3, msg);
    return msg;
}
