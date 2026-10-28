/* Battle: applying a chosen skill or item from the command menu (effects, sounds and the
   result message). */

#include "global.h"
#include "bmenu2.h"

/* Skill (isItem 0) or item (isItem 1, through its attribute 0xC) BCMD->skill used by `who`
   on targets[who]. Ids 0x3A/0x3B set BCMD->unk0 to 1/2. */
// sub_0812E780 @ 0x0812E780
#ifdef NONMATCHING
void sub_0812E780(u16 who, u16 *targets, const u16 *unused, u8 isItem)
{
    struct Action a;
    s32 id = BCMD->skill;
    u8 *rec;
    s16 pos;
    s16 i;

    if (isItem == 1)
        Item_GetAttribute(id, 0xC, &id);
    if ((u32)(id - 0x2B) <= 0x14)
    {
        switch (sub_080F0F68(id, 0))
        {
        case 0xF0:
            pos = Battle_FindPartyPosition(targets[(s16)who]);
            if (pos != -1)
            {
                sub_080ECE08(4);
                sub_080ECE38(pos, 0, 3);
            }
            break;
        case 0xF1:
            pos = Battle_FindPartyPosition(targets[(s16)who]);
            if (pos != -1)
            {
                sub_080ECE08(4);
                sub_080ECE38(pos, 0, 0);
            }
            break;
        case 0xF2:
            pos = Battle_FindPartyPosition(targets[(s16)who]);
            if (pos != -1)
            {
                sub_080ECE08(4);
                sub_080ECE38(pos, 0, 5);
            }
            break;
        case 0xF3:
            pos = Battle_FindPartyPosition(targets[(s16)who]);
            if (pos != -1)
            {
                sub_080ECE08(4);
                sub_080ECE38(pos, 0, 1);
            }
            break;
        case 0xF4:
            for (i = 0; i <= 5; i++)
            {
                sub_080ECE08(5);
                sub_080ECE38(i, (u8)(i << 2), 3);
            }
            break;
        case 0xF5:
            for (i = 0; i <= 5; i++)
            {
                sub_080ECE08(5);
                sub_080ECE38(i, (u8)(i << 2), 0);
            }
            break;
        case 0xF6:
            for (i = 0; i <= 5; i++)
            {
                sub_080ECE08(5);
                sub_080ECE38(i, (u8)(i << 2), 5);
            }
            break;
        case 0xF7:
            for (i = 0; i <= 5; i++)
            {
                sub_080ECE08(5);
                sub_080ECE38(i, (u8)(i << 2), 1);
            }
            break;
        }
        sub_080ECF70(sub_080F104C(id, 0));
    }
    rec = sub_080BF5C0(id);
    if (rec[2] == 0x80 || rec[2] == 0x82)
    {
        a.att = (s16)who;
        a.def = targets[(s16)who];
    }
    else
    {
        a.att = (s16)who;
        a.def = 0x10;
    }
    sub_080F4988(&a, id);
    sub_080C84A0();
    BCMD->unk0 = 0;
    if (a.unkC == 1)
    {
        u16 msg;

        if (a.msg == -1)
        {
            msg = gUnknown_0876F9CC[(s16)((id - 0x1D) * 2)];
            if (msg == 0xFFFF)
                goto done;
            msg &= 0x7FFF;
        }
        else
            msg = a.msg;
        if (msg != 0xFFFF)
            BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(msg), a.def));
    done:
        if (id == 0x3A)
            BCMD->unk0 = 1;
        if (id == 0x3B)
            BCMD->unk0 = 2;
    }
    else if (a.msg == -1)
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(gUnknown_08124534, 0));
    else
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(a.msg), 0));
}
#else
NAKED
void sub_0812E780(u16 who, u16 *targets, const u16 *unused, u8 isItem)
{
    asm_unified(
        ".L0812E780:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    sub sp, #0x24\n"
        "    adds r7, r1, #0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    lsls r3, r3, #0x18\n"
        "    lsrs r3, r3, #0x18\n"
        "    ldr r0, .L0812E7D0\n"
        "    movs r1, #2\n"
        "    ldrsh r0, [r0, r1]\n"
        "    str r0, [sp, #0x20]\n"
        "    cmp r3, #1\n"
        "    bne .L0812E7A2\n"
        "    add r2, sp, #0x20\n"
        "    movs r1, #0xc\n"
        "    bl Item_GetAttribute\n"
        ".L0812E7A2:\n"
        "    ldr r1, [sp, #0x20]\n"
        "    adds r0, r1, #0\n"
        "    subs r0, #0x2b\n"
        "    lsls r6, r4, #0x10\n"
        "    cmp r0, #0x14\n"
        "    bls .L0812E7B0\n"
        "    b .L0812E95E\n"
        ".L0812E7B0:\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    movs r1, #0\n"
        "    bl sub_080F0F68\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    subs r0, #0xf0\n"
        "    cmp r0, #7\n"
        "    bls .L0812E7C6\n"
        "    b .L0812E94A\n"
        ".L0812E7C6:\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L0812E7D4\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        ".L0812E7D0: .4byte 0x030065C0 @ IWRAM+0x65C0\n"
        ".L0812E7D4: .4byte gUnknown_0812E7D8\n"
        "    .global gUnknown_0812E7D8\n"
        "gUnknown_0812E7D8:\n"
        ".L0812E7D8: @ jump table\n"
        "    .4byte .L0812E7F8\n"
        "    .4byte .L0812E826\n"
        "    .4byte .L0812E854\n"
        "    .4byte .L0812E880\n"
        "    .4byte .L0812E8AC\n"
        "    .4byte .L0812E8D4\n"
        "    .4byte .L0812E8FC\n"
        "    .4byte .L0812E924\n"
        ".L0812E7F8:\n"
        "    lsls r4, r4, #0x10\n"
        "    asrs r0, r4, #0xf\n"
        "    adds r0, r0, r7\n"
        "    ldrh r0, [r0]\n"
        "    bl Battle_FindPartyPosition\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r5, r0, #0x10\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    adds r6, r4, #0\n"
        "    cmp r5, r0\n"
        "    bne .L0812E814\n"
        "    b .L0812E94A\n"
        ".L0812E814:\n"
        "    movs r0, #4\n"
        "    bl sub_080ECE08\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #3\n"
        "    bl sub_080ECE38\n"
        "    b .L0812E94A\n"
        ".L0812E826:\n"
        "    lsls r4, r4, #0x10\n"
        "    asrs r0, r4, #0xf\n"
        "    adds r0, r0, r7\n"
        "    ldrh r0, [r0]\n"
        "    bl Battle_FindPartyPosition\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r5, r0, #0x10\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    adds r6, r4, #0\n"
        "    cmp r5, r0\n"
        "    bne .L0812E842\n"
        "    b .L0812E94A\n"
        ".L0812E842:\n"
        "    movs r0, #4\n"
        "    bl sub_080ECE08\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    bl sub_080ECE38\n"
        "    b .L0812E94A\n"
        ".L0812E854:\n"
        "    lsls r4, r4, #0x10\n"
        "    asrs r0, r4, #0xf\n"
        "    adds r0, r0, r7\n"
        "    ldrh r0, [r0]\n"
        "    bl Battle_FindPartyPosition\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r5, r0, #0x10\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    adds r6, r4, #0\n"
        "    cmp r5, r0\n"
        "    beq .L0812E94A\n"
        "    movs r0, #4\n"
        "    bl sub_080ECE08\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #5\n"
        "    bl sub_080ECE38\n"
        "    b .L0812E94A\n"
        ".L0812E880:\n"
        "    lsls r4, r4, #0x10\n"
        "    asrs r0, r4, #0xf\n"
        "    adds r0, r0, r7\n"
        "    ldrh r0, [r0]\n"
        "    bl Battle_FindPartyPosition\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r5, r0, #0x10\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    adds r6, r4, #0\n"
        "    cmp r5, r0\n"
        "    beq .L0812E94A\n"
        "    movs r0, #4\n"
        "    bl sub_080ECE08\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #1\n"
        "    bl sub_080ECE38\n"
        "    b .L0812E94A\n"
        ".L0812E8AC:\n"
        "    movs r5, #0\n"
        "    lsls r6, r4, #0x10\n"
        ".L0812E8B0:\n"
        "    movs r0, #5\n"
        "    bl sub_080ECE08\n"
        "    lsls r4, r5, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    lsls r1, r4, #0x1a\n"
        "    lsrs r1, r1, #0x18\n"
        "    adds r0, r4, #0\n"
        "    movs r2, #3\n"
        "    bl sub_080ECE38\n"
        "    adds r4, #1\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r5, r4, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    cmp r4, #5\n"
        "    ble .L0812E8B0\n"
        "    b .L0812E94A\n"
        ".L0812E8D4:\n"
        "    movs r5, #0\n"
        "    lsls r6, r4, #0x10\n"
        ".L0812E8D8:\n"
        "    movs r0, #5\n"
        "    bl sub_080ECE08\n"
        "    lsls r4, r5, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    lsls r1, r4, #0x1a\n"
        "    lsrs r1, r1, #0x18\n"
        "    adds r0, r4, #0\n"
        "    movs r2, #0\n"
        "    bl sub_080ECE38\n"
        "    adds r4, #1\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r5, r4, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    cmp r4, #5\n"
        "    ble .L0812E8D8\n"
        "    b .L0812E94A\n"
        ".L0812E8FC:\n"
        "    movs r5, #0\n"
        "    lsls r6, r4, #0x10\n"
        ".L0812E900:\n"
        "    movs r0, #5\n"
        "    bl sub_080ECE08\n"
        "    lsls r4, r5, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    lsls r1, r4, #0x1a\n"
        "    lsrs r1, r1, #0x18\n"
        "    adds r0, r4, #0\n"
        "    movs r2, #5\n"
        "    bl sub_080ECE38\n"
        "    adds r4, #1\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r5, r4, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    cmp r4, #5\n"
        "    ble .L0812E900\n"
        "    b .L0812E94A\n"
        ".L0812E924:\n"
        "    movs r5, #0\n"
        "    lsls r6, r4, #0x10\n"
        ".L0812E928:\n"
        "    movs r0, #5\n"
        "    bl sub_080ECE08\n"
        "    lsls r4, r5, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    lsls r1, r4, #0x1a\n"
        "    lsrs r1, r1, #0x18\n"
        "    adds r0, r4, #0\n"
        "    movs r2, #1\n"
        "    bl sub_080ECE38\n"
        "    adds r4, #1\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r5, r4, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    cmp r4, #5\n"
        "    ble .L0812E928\n"
        ".L0812E94A:\n"
        "    ldr r0, [sp, #0x20]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    movs r1, #0\n"
        "    bl sub_080F104C\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl sub_080ECF70\n"
        ".L0812E95E:\n"
        "    ldr r0, [sp, #0x20]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl sub_080BF5C0\n"
        "    ldrb r0, [r0, #2]\n"
        "    cmp r0, #0x80\n"
        "    beq .L0812E972\n"
        "    cmp r0, #0x82\n"
        "    bne .L0812E97E\n"
        ".L0812E972:\n"
        "    asrs r0, r6, #0x10\n"
        "    str r0, [sp]\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r7\n"
        "    ldrh r0, [r0]\n"
        "    b .L0812E984\n"
        ".L0812E97E:\n"
        "    asrs r0, r6, #0x10\n"
        "    str r0, [sp]\n"
        "    movs r0, #0x10\n"
        ".L0812E984:\n"
        "    str r0, [sp, #4]\n"
        "    ldr r1, [sp, #0x20]\n"
        "    mov r0, sp\n"
        "    bl sub_080F4988\n"
        "    bl sub_080C84A0\n"
        "    ldr r1, .L0812E9C4\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r0, [sp, #0xc]\n"
        "    cmp r0, #1\n"
        "    bne .L0812EA14\n"
        "    ldr r1, [sp, #8]\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r1, r0\n"
        "    bne .L0812E9D4\n"
        "    ldr r0, [sp, #0x20]\n"
        "    subs r0, #0x1d\n"
        "    ldr r1, .L0812E9C8\n"
        "    lsls r0, r0, #0x11\n"
        "    asrs r0, r0, #0xf\n"
        "    adds r0, r0, r1\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L0812E9CC\n"
        "    cmp r1, r0\n"
        "    beq .L0812E9F2\n"
        "    ldr r0, .L0812E9D0\n"
        "    ands r1, r0\n"
        "    b .L0812E9D8\n"
        "    .byte 0x00, 0x00\n"
        ".L0812E9C4: .4byte 0x030065C0 @ IWRAM+0x65C0\n"
        ".L0812E9C8: .4byte gUnknown_0876F9CC\n"
        ".L0812E9CC: .4byte 0x0000FFFF\n"
        ".L0812E9D0: .4byte 0x00007FFF\n"
        ".L0812E9D4:\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        ".L0812E9D8:\n"
        "    ldr r0, .L0812EA0C\n"
        "    cmp r1, r0\n"
        "    beq .L0812E9F2\n"
        "    adds r0, r1, #0\n"
        "    bl Battle_GetMessage\n"
        "    ldr r1, [sp, #4]\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetMode\n"
        ".L0812E9F2:\n"
        "    ldr r0, [sp, #0x20]\n"
        "    adds r2, r0, #0\n"
        "    cmp r2, #0x3a\n"
        "    bne .L0812EA00\n"
        "    ldr r1, .L0812EA10\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        ".L0812EA00:\n"
        "    cmp r2, #0x3b\n"
        "    bne .L0812EA4A\n"
        "    ldr r1, .L0812EA10\n"
        "    movs r0, #2\n"
        "    strh r0, [r1]\n"
        "    b .L0812EA4A\n"
        ".L0812EA0C: .4byte 0x0000FFFF\n"
        ".L0812EA10: .4byte 0x030065C0 @ IWRAM+0x65C0\n"
        ".L0812EA14:\n"
        "    ldr r1, [sp, #8]\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r1, r0\n"
        "    bne .L0812EA34\n"
        "    ldr r0, .L0812EA30\n"
        "    movs r1, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetMode\n"
        "    b .L0812EA4A\n"
        ".L0812EA30: .4byte gUnknown_08124534\n"
        ".L0812EA34:\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetMessage\n"
        "    movs r1, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetMode\n"
        ".L0812EA4A:\n"
        "    add sp, #0x24\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

/* First of members 0-3 alive, in the party and able to act, or -1. */
// Party_FirstActiveHuman @ 0x0812EA54
s16 Party_FirstActiveHuman(void)
{
    s32 i;

    for (i = 0; i <= 3; i++)
    {
        if (Combatant_IsAlive(i) && Combatant_IsInParty(i) && !(Combatant_GetStatus(i) & 0xB060))
            return i;
    }
    return -1;
}

/* Item BCMD->skill used by `who` on blk->unkF30[who]. */
// sub_0812EA98 @ 0x0812EA98
#ifdef NONMATCHING
void sub_0812EA98(u16 who)
{
    struct C127Block *blk = C127_BLOCK;
    struct Action a;
    s32 attr;
    s32 id = BCMD->skill;
    u8 type = Action_GetRecord(id)[3];
    const struct C12BItemFx *fx;
    s32 pos;
    u16 i;

    Item_GetAttribute(id, 0xC, &attr);
    fx = &gUnknown_0876E2D8[id];
    switch (fx->kind)
    {
    case 0xF0:
        pos = Battle_FindPartyPosition(((s16 *)blk->unkF30)[(s16)who]);
        if (pos != -1)
        {
            sub_080ECE08(4);
            sub_080ECE38(pos, 0, 3);
        }
        break;
    case 0xF1:
        pos = Battle_FindPartyPosition(((s16 *)blk->unkF30)[(s16)who]);
        if (pos != -1)
        {
            sub_080ECE08(4);
            sub_080ECE38(pos, 0, 0);
        }
        break;
    case 0xF2:
        pos = Battle_FindPartyPosition(((s16 *)blk->unkF30)[(s16)who]);
        if (pos != -1)
        {
            sub_080ECE08(4);
            sub_080ECE38(pos, 0, 5);
        }
        break;
    case 0xF3:
        pos = Battle_FindPartyPosition(((s16 *)blk->unkF30)[(s16)who]);
        if (pos != -1)
        {
            sub_080ECE08(4);
            sub_080ECE38(pos, 0, 1);
        }
        break;
    case 0xF4:
        for (i = 0; i <= 5; i++)
        {
            sub_080ECE08(5);
            sub_080ECE38(i, (u8)(i << 2), 3);
        }
        break;
    case 0xF5:
        for (i = 0; i <= 5; i++)
        {
            sub_080ECE08(5);
            sub_080ECE38(i, (u8)(i << 2), 0);
        }
        break;
    case 0xF6:
        for (i = 0; i <= 5; i++)
        {
            sub_080ECE08(5);
            sub_080ECE38(i, (u8)(i << 2), 5);
        }
        break;
    case 0xF7:
        for (i = 0; i <= 5; i++)
        {
            sub_080ECE08(5);
            sub_080ECE38(i, (u8)(i << 2), 1);
        }
        break;
    }
    sub_080ECF70(fx->se);
    if (type == 0x80 || type == 0x82 || type == 0x83)
    {
        a.att = (s16)who;
        a.def = ((s16 *)blk->unkF30)[(s16)who];
        sub_080F40C4(Combatant_GetDemonId(a.def));
    }
    else
    {
        a.att = (s16)who;
        a.def = 0x10;
    }
    Item_RunUseEffect(&a, id);
    sub_080C84A0();
    if (a.unkC == 1)
    {
        u16 msg;

        sub_080F3E38(id);
        Item_GetAttribute(id, 0xC, &id);
        if (a.msg == -1)
            msg = gUnknown_0876FAE4[(s16)(id - 0x80)];
        else
            msg = a.msg;
        if (msg == 0xFFFF)
            return;
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(msg), a.def + (BCMD->skill << 16)));
    }
    else if (a.msg == -1)
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(gUnknown_08124534, 0));
    else
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(a.msg), 0));
}
#else
NAKED
void sub_0812EA98(u16 who)
{
    asm_unified(
        ".L0812EA98:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sb\n"
        "    mov r6, r8\n"
        "    push {r6, r7}\n"
        "    sub sp, #0x28\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    ldr r6, .L0812EAE4\n"
        "    ldr r0, .L0812EAE8\n"
        "    movs r1, #2\n"
        "    ldrsh r0, [r0, r1]\n"
        "    str r0, [sp, #0x24]\n"
        "    add r4, sp, #0x24\n"
        "    ldrh r0, [r4]\n"
        "    bl Action_GetRecord\n"
        "    ldrb r0, [r0, #3]\n"
        "    mov r8, r0\n"
        "    add r2, sp, #0x20\n"
        "    ldr r0, [sp, #0x24]\n"
        "    movs r1, #0xc\n"
        "    bl Item_GetAttribute\n"
        "    ldr r0, [sp, #0x24]\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L0812EAEC\n"
        "    adds r7, r0, r1\n"
        "    ldrb r0, [r7]\n"
        "    subs r0, #0xf0\n"
        "    mov sb, r4\n"
        "    cmp r0, #7\n"
        "    bls .L0812EADA\n"
        "    b .L0812EC64\n"
        ".L0812EADA:\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L0812EAF0\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        ".L0812EAE4: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L0812EAE8: .4byte 0x030065C0 @ IWRAM+0x65C0\n"
        ".L0812EAEC: .4byte gUnknown_0876E2D8\n"
        ".L0812EAF0: .4byte gUnknown_0812EAF4\n"
        "    .global gUnknown_0812EAF4\n"
        "gUnknown_0812EAF4:\n"
        ".L0812EAF4: @ jump table\n"
        "    .4byte .L0812EB14\n"
        "    .4byte .L0812EB48\n"
        "    .4byte .L0812EB7A\n"
        "    .4byte .L0812EBAC\n"
        "    .4byte .L0812EBDE\n"
        "    .4byte .L0812EC00\n"
        "    .4byte .L0812EC22\n"
        "    .4byte .L0812EC44\n"
        ".L0812EB14:\n"
        "    lsls r1, r5, #0x10\n"
        "    asrs r1, r1, #0xf\n"
        "    movs r2, #0xf3\n"
        "    lsls r2, r2, #4\n"
        "    adds r0, r6, r2\n"
        "    adds r0, r0, r1\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r0, r3]\n"
        "    bl Battle_FindPartyPosition\n"
        "    adds r4, r0, #0\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r4, r0\n"
        "    bne .L0812EB34\n"
        "    b .L0812EC64\n"
        ".L0812EB34:\n"
        "    movs r0, #4\n"
        "    bl sub_080ECE08\n"
        "    lsls r0, r4, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    movs r1, #0\n"
        "    movs r2, #3\n"
        "    bl sub_080ECE38\n"
        "    b .L0812EC64\n"
        ".L0812EB48:\n"
        "    lsls r1, r5, #0x10\n"
        "    asrs r1, r1, #0xf\n"
        "    movs r2, #0xf3\n"
        "    lsls r2, r2, #4\n"
        "    adds r0, r6, r2\n"
        "    adds r0, r0, r1\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r0, r3]\n"
        "    bl Battle_FindPartyPosition\n"
        "    adds r4, r0, #0\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r4, r0\n"
        "    beq .L0812EC64\n"
        "    movs r0, #4\n"
        "    bl sub_080ECE08\n"
        "    lsls r0, r4, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    bl sub_080ECE38\n"
        "    b .L0812EC64\n"
        ".L0812EB7A:\n"
        "    lsls r1, r5, #0x10\n"
        "    asrs r1, r1, #0xf\n"
        "    movs r2, #0xf3\n"
        "    lsls r2, r2, #4\n"
        "    adds r0, r6, r2\n"
        "    adds r0, r0, r1\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r0, r3]\n"
        "    bl Battle_FindPartyPosition\n"
        "    adds r4, r0, #0\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r4, r0\n"
        "    beq .L0812EC64\n"
        "    movs r0, #4\n"
        "    bl sub_080ECE08\n"
        "    lsls r0, r4, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    movs r1, #0\n"
        "    movs r2, #5\n"
        "    bl sub_080ECE38\n"
        "    b .L0812EC64\n"
        ".L0812EBAC:\n"
        "    lsls r1, r5, #0x10\n"
        "    asrs r1, r1, #0xf\n"
        "    movs r2, #0xf3\n"
        "    lsls r2, r2, #4\n"
        "    adds r0, r6, r2\n"
        "    adds r0, r0, r1\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r0, r3]\n"
        "    bl Battle_FindPartyPosition\n"
        "    adds r4, r0, #0\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r4, r0\n"
        "    beq .L0812EC64\n"
        "    movs r0, #4\n"
        "    bl sub_080ECE08\n"
        "    lsls r0, r4, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    movs r1, #0\n"
        "    movs r2, #1\n"
        "    bl sub_080ECE38\n"
        "    b .L0812EC64\n"
        ".L0812EBDE:\n"
        "    movs r4, #0\n"
        ".L0812EBE0:\n"
        "    movs r0, #5\n"
        "    bl sub_080ECE08\n"
        "    lsls r0, r4, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    lsls r1, r4, #0x1a\n"
        "    lsrs r1, r1, #0x18\n"
        "    movs r2, #3\n"
        "    bl sub_080ECE38\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #5\n"
        "    bls .L0812EBE0\n"
        "    b .L0812EC64\n"
        ".L0812EC00:\n"
        "    movs r4, #0\n"
        ".L0812EC02:\n"
        "    movs r0, #5\n"
        "    bl sub_080ECE08\n"
        "    lsls r0, r4, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    lsls r1, r4, #0x1a\n"
        "    lsrs r1, r1, #0x18\n"
        "    movs r2, #0\n"
        "    bl sub_080ECE38\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #5\n"
        "    bls .L0812EC02\n"
        "    b .L0812EC64\n"
        ".L0812EC22:\n"
        "    movs r4, #0\n"
        ".L0812EC24:\n"
        "    movs r0, #5\n"
        "    bl sub_080ECE08\n"
        "    lsls r0, r4, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    lsls r1, r4, #0x1a\n"
        "    lsrs r1, r1, #0x18\n"
        "    movs r2, #5\n"
        "    bl sub_080ECE38\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #5\n"
        "    bls .L0812EC24\n"
        "    b .L0812EC64\n"
        ".L0812EC44:\n"
        "    movs r4, #0\n"
        ".L0812EC46:\n"
        "    movs r0, #5\n"
        "    bl sub_080ECE08\n"
        "    lsls r0, r4, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    lsls r1, r4, #0x1a\n"
        "    lsrs r1, r1, #0x18\n"
        "    movs r2, #1\n"
        "    bl sub_080ECE38\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #5\n"
        "    bls .L0812EC46\n"
        ".L0812EC64:\n"
        "    ldrh r0, [r7, #2]\n"
        "    bl sub_080ECF70\n"
        "    mov r0, r8\n"
        "    cmp r0, #0x80\n"
        "    beq .L0812EC78\n"
        "    cmp r0, #0x82\n"
        "    beq .L0812EC78\n"
        "    cmp r0, #0x83\n"
        "    bne .L0812EC9C\n"
        ".L0812EC78:\n"
        "    lsls r1, r5, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    str r1, [sp]\n"
        "    lsls r1, r1, #1\n"
        "    movs r2, #0xf3\n"
        "    lsls r2, r2, #4\n"
        "    adds r0, r6, r2\n"
        "    adds r0, r0, r1\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r0, r3]\n"
        "    str r0, [sp, #4]\n"
        "    bl Combatant_GetDemonId\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    bl sub_080F40C4\n"
        "    b .L0812ECA6\n"
        ".L0812EC9C:\n"
        "    lsls r0, r5, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    str r0, [sp]\n"
        "    movs r0, #0x10\n"
        "    str r0, [sp, #4]\n"
        ".L0812ECA6:\n"
        "    mov r0, sp\n"
        "    ldr r1, [sp, #0x24]\n"
        "    bl Item_RunUseEffect\n"
        "    bl sub_080C84A0\n"
        "    ldr r0, [sp, #0xc]\n"
        "    cmp r0, #1\n"
        "    bne .L0812ED10\n"
        "    ldr r0, [sp, #0x24]\n"
        "    bl sub_080F3E38\n"
        "    ldr r0, [sp, #0x24]\n"
        "    movs r1, #0xc\n"
        "    mov r2, sb\n"
        "    bl Item_GetAttribute\n"
        "    ldr r1, [sp, #8]\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r1, r0\n"
        "    bne .L0812ECE8\n"
        "    ldr r0, [sp, #0x24]\n"
        "    subs r0, #0x80\n"
        "    ldr r1, .L0812ECE4\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0xf\n"
        "    adds r0, r0, r1\n"
        "    ldrh r1, [r0]\n"
        "    b .L0812ECEC\n"
        "    .byte 0x00, 0x00\n"
        ".L0812ECE4: .4byte gUnknown_0876FAE4\n"
        ".L0812ECE8:\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        ".L0812ECEC:\n"
        "    ldr r0, .L0812ED08\n"
        "    cmp r1, r0\n"
        "    beq .L0812ED46\n"
        "    adds r0, r1, #0\n"
        "    bl Battle_GetMessage\n"
        "    ldr r1, .L0812ED0C\n"
        "    movs r3, #2\n"
        "    ldrsh r2, [r1, r3]\n"
        "    lsls r2, r2, #0x10\n"
        "    ldr r1, [sp, #4]\n"
        "    adds r1, r1, r2\n"
        "    b .L0812ED1E\n"
        "    .byte 0x00, 0x00\n"
        ".L0812ED08: .4byte 0x0000FFFF\n"
        ".L0812ED0C: .4byte 0x030065C0 @ IWRAM+0x65C0\n"
        ".L0812ED10:\n"
        "    ldr r1, [sp, #8]\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r1, r0\n"
        "    bne .L0812ED30\n"
        "    ldr r0, .L0812ED2C\n"
        "    movs r1, #0\n"
        ".L0812ED1E:\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetMode\n"
        "    b .L0812ED46\n"
        ".L0812ED2C: .4byte gUnknown_08124534\n"
        ".L0812ED30:\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetMessage\n"
        "    movs r1, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetMode\n"
        ".L0812ED46:\n"
        "    add sp, #0x28\n"
        "    pop {r3, r4}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif
