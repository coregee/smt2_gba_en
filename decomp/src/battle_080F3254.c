#include "global.h"
#include "battle2.h"

// Skill_DrawEquippedRow @ 0x080F3254
/* Draws a combatant's name (8 glyphs) into the text canvas at row `row`; row 4 is the
   bottom line of a scrolling list: the canvas rows are moved up by one first. */
void Skill_DrawEquippedRow(struct Combatant *c, u8 row)
{
    u16 name[8];
    u32 zero;
    u8 i;

    Combatant_DecodeName(c, name);
    if (row == 4)
    {
        CpuFastSet(gUnk_030000B4 + 0x1C00, gUnk_030000B4 + 0x200, 0x80);
        for (i = 0; i < 8; i++)
        {
            if (name[i])
                Font_DrawGlyph(name[i], gUnk_030000B4, i * 12 + 0x80, 4);
        }
        CpuFastSet(gUnk_030000B4 + 0x200, gUnk_030000B4 + 0x1C00, 0x80);
        CpuFastSet(gUnk_030000B4 + 0x600, gUnk_030000B4 + 0x200, 0x80);
        CpuFastSet(gUnk_030000B4 + 0xA00, gUnk_030000B4 + 0x600, 0x80);
        zero = 0;
        CpuFastSet(&zero, gUnk_030000B4 + 0xA00, 0x01000080);
    }
    else
    {
        for (i = 0; i < 8; i++)
        {
            if (name[i])
                Font_DrawGlyph(name[i], gUnk_030000B4, i * 12, row * 13 + 8);
        }
    }
}

// sub_080F332C @ 0x080F332C
u32 sub_080F332C(void)
{
    struct BattleFlow *b = BFLOW;
    s16 *state = &b->unk97E;

    switch (*state)
    {
    case 0:
        *state = 1;
        sub_081293F8();
        break;
    case 1:
        *state = 2;
        break;
    case 2:
        switch ((u8)sub_08129440())
        {
        case 0:
            break;
        case 1:
            return 1;
        case 2:
            return 2;
        case 0xFF:
            return 3;
        }
        break;
    case 3:
        return 3;
    }
    return 0;
}

// sub_080F3398 @ 0x080F3398
u32 sub_080F3398(void)
{
    struct BattleFlow *b = BFLOW;
    s16 *state = &b->unk97E;

    switch (*state)
    {
    case 0:
        sub_0812D390();
        *state = 1;
        break;
    case 1:
        if ((u8)sub_0812D5FC())
            *state = 6;
        break;
    case 6:
        return 1;
    }
    return 0;
}

// sub_080F33E8 @ 0x080F33E8
/* Battle state machine run through BattleFlow+0x97E (two-sided battle side selection). */
#ifdef NONMATCHING
u32 sub_080F33E8(void)
{
    struct BattleFlow *b = BFLOW;
    struct Portrait *p = &b->portrait;

    switch (b->unk97E)
    {
    case 0:
        b->unk1190 = 0;
        if (sub_080EDAD0())
        {
            BattleMenu_SetMode(3, Menu_ExpandListTemplate(gUnknown_08124A62, 0));
            b->unk97E = 6;
        }
        else if (Battle_IsTwoSided())
            b->unk97E = 7;
        else if (!sub_080C2554(b->combatants[b->unk1190]))
            goto refuse;
        else
            b->unk97E++;
        break;
    case 1:
        Window_SetHeight(b->window, 0);
        BattleMenu_Reset();
        b->win4C = TextWindow_Create(1, 0, 0x15, 3, 1);
        b->win50 = TextWindow_Create(1, 3, 0xB, 6, 1);
        b->win54 = TextWindow_Create(0xF, 7, 0xE, 6, 1);
        b->unk97E++;
        if (!Battle_IsTwoSided() || !sub_080EDA24(0) || !sub_080EDA24(1))
            sub_080E6DBC(0);
        break;
    case 2:
        if (EnemyInfo_IsWindowDone(0))
        {
            b->unk693 = 0;
            EnemyInfo_DrawPage(0);
            b->unk97E++;
        }
        break;
    case 3:
        if (EnemyInfo_HandleInput())
            b->unk97E++;
        break;
    case 4:
        sub_080ECB38();
        EnemyInfo_Close();
        b->unk97E++;
        break;
    case 5:
        if (EnemyInfo_IsWindowDone(1))
            return 1;
        break;
    case 6:
        if (BattleMsg_IsDone() == 1)
            return 1;
        break;
    case 7:
        if (sub_080EDA24(0) && sub_080EDA24(1))
        {
            BattleMenu_SetMode(3, gUnknown_081242CE);
            BattleMsg_SetDone(1);
            sub_080E6DBC(1);
            b->unk1190 = 0;
            b->unk695 = 0;
            b->unk97E = 8;
        }
        else
        {
            if (sub_080EDA24(0))
                b->unk1190 = 0;
            else
                b->unk1190 = 1;
            if (sub_080C2554(b->combatants[b->unk1190]))
                b->unk97E = 1;
            else
            {
            refuse:
                BattleMenu_SetMode(3, Menu_ExpandListTemplate(gUnknown_08124A50, 0));
                b->unk97E = 6;
            }
        }
        break;
    case 8:
        {
            u16 k = gKeysNew & 0x10;

            if (k)
            {
                if (b->unk695 == 1)
                    break;
                b->unk695 = 1;
                p->unkC = gUnknown_086BF72C[2];
                sub_080ECF70(0x64);
            }
            else if (gKeysNew & 0x20)
            {
                if (b->unk695 == 0)
                    break;
                b->unk695 = k;
                p->unkC = gUnknown_086BF72C[1];
                sub_080ECF70(0x64);
            }
            else if (gKeysNew & 1)
            {
                b->unk1190 = b->unk695;
                sub_080ECF70(0x65);
                if (!sub_080C2554(b->combatants[b->unk1190]))
                {
                    BattleMenu_SetMode(3, Menu_ExpandListTemplate(gUnknown_08124A50, 0));
                    b->unk97E = 6;
                    sub_080ECB38();
                }
                else
                    b->unk97E = 1;
            }
            else if (gKeysNew & 2)
            {
                sub_080ECF70(0x66);
                sub_080ECB38();
                return 1;
            }
        }
        break;
    }
    return 0;
}
#else
NAKED
u32 sub_080F33E8(void)
{
    asm_unified(
        ".L080F33E8:\n"
        "    push {r4, r5, r6, lr}\n"
        "    sub sp, #4\n"
        "    ldr r5, .L080F340C\n"
        "    movs r0, #0x8b\n"
        "    lsls r0, r0, #5\n"
        "    adds r4, r5, r0\n"
        "    ldr r1, .L080F3410\n"
        "    adds r0, r5, r1\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r0, r2]\n"
        "    cmp r0, #8\n"
        "    bls .L080F3402\n"
        "    b .L080F3734\n"
        ".L080F3402:\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L080F3414\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        ".L080F340C: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080F3410: .4byte 0x0000097E\n"
        ".L080F3414: .4byte gUnknown_080F3418\n"
        "    .global gUnknown_080F3418\n"
        "gUnknown_080F3418:\n"
        ".L080F3418: @ jump table\n"
        "    .4byte .L080F343C\n"
        "    .4byte .L080F34A2\n"
        "    .4byte .L080F351C\n"
        "    .4byte .L080F353C\n"
        "    .4byte .L080F3554\n"
        "    .4byte .L080F356C\n"
        "    .4byte .L080F357E\n"
        "    .4byte .L080F358C\n"
        "    .4byte .L080F3650\n"
        ".L080F343C:\n"
        "    ldr r0, .L080F3464\n"
        "    adds r4, r5, r0\n"
        "    movs r0, #0\n"
        "    strh r0, [r4]\n"
        "    bl sub_080EDAD0\n"
        "    cmp r0, #0\n"
        "    beq .L080F3470\n"
        "    ldr r0, .L080F3468\n"
        "    movs r1, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetMode\n"
        "    ldr r2, .L080F346C\n"
        "    adds r1, r5, r2\n"
        "    b .L080F362E\n"
        "    .byte 0x00, 0x00\n"
        ".L080F3464: .4byte 0x00001190\n"
        ".L080F3468: .4byte gUnknown_08124A62\n"
        ".L080F346C: .4byte 0x0000097E\n"
        ".L080F3470:\n"
        "    bl Battle_IsTwoSided\n"
        "    cmp r0, #0\n"
        "    beq .L080F3488\n"
        "    ldr r0, .L080F3484\n"
        "    adds r1, r5, r0\n"
        "    movs r0, #7\n"
        "    strh r0, [r1]\n"
        "    b .L080F3734\n"
        "    .byte 0x00, 0x00\n"
        ".L080F3484: .4byte 0x0000097E\n"
        ".L080F3488:\n"
        "    ldrh r1, [r4]\n"
        "    lsls r1, r1, #2\n"
        "    movs r2, #0x99\n"
        "    lsls r2, r2, #4\n"
        "    adds r0, r5, r2\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    bl sub_080C2554\n"
        "    cmp r0, #0\n"
        "    bne .L080F34A0\n"
        "    b .L080F361A\n"
        ".L080F34A0:\n"
        "    b .L080F355C\n"
        ".L080F34A2:\n"
        "    ldr r1, .L080F3514\n"
        "    adds r0, r5, r1\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #0\n"
        "    bl Window_SetHeight\n"
        "    bl BattleMenu_Reset\n"
        "    movs r4, #1\n"
        "    str r4, [sp]\n"
        "    movs r0, #1\n"
        "    movs r1, #0\n"
        "    movs r2, #0x15\n"
        "    movs r3, #3\n"
        "    bl TextWindow_Create\n"
        "    str r0, [r5, #0x4c]\n"
        "    str r4, [sp]\n"
        "    movs r0, #1\n"
        "    movs r1, #3\n"
        "    movs r2, #0xb\n"
        "    movs r3, #6\n"
        "    bl TextWindow_Create\n"
        "    str r0, [r5, #0x50]\n"
        "    str r4, [sp]\n"
        "    movs r0, #0xf\n"
        "    movs r1, #7\n"
        "    movs r2, #0xe\n"
        "    movs r3, #6\n"
        "    bl TextWindow_Create\n"
        "    str r0, [r5, #0x54]\n"
        "    ldr r2, .L080F3518\n"
        "    adds r1, r5, r2\n"
        "    ldrh r0, [r1]\n"
        "    adds r0, #1\n"
        "    strh r0, [r1]\n"
        "    bl Battle_IsTwoSided\n"
        "    cmp r0, #0\n"
        "    beq .L080F350C\n"
        "    movs r0, #0\n"
        "    bl sub_080EDA24\n"
        "    cmp r0, #0\n"
        "    beq .L080F350C\n"
        "    movs r0, #1\n"
        "    bl sub_080EDA24\n"
        "    cmp r0, #0\n"
        "    beq .L080F350C\n"
        "    b .L080F3734\n"
        ".L080F350C:\n"
        "    movs r0, #0\n"
        "    bl sub_080E6DBC\n"
        "    b .L080F3734\n"
        ".L080F3514: .4byte 0x00000974\n"
        ".L080F3518: .4byte 0x0000097E\n"
        ".L080F351C:\n"
        "    movs r0, #0\n"
        "    bl EnemyInfo_IsWindowDone\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080F352A\n"
        "    b .L080F3734\n"
        ".L080F352A:\n"
        "    ldr r0, .L080F3538\n"
        "    adds r1, r5, r0\n"
        "    movs r0, #0\n"
        "    strb r0, [r1]\n"
        "    bl EnemyInfo_DrawPage\n"
        "    b .L080F355C\n"
        ".L080F3538: .4byte 0x00000693\n"
        ".L080F353C:\n"
        "    bl EnemyInfo_HandleInput\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080F3548\n"
        "    b .L080F3734\n"
        ".L080F3548:\n"
        "    ldr r0, .L080F3550\n"
        "    adds r1, r5, r0\n"
        "    b .L080F3560\n"
        "    .byte 0x00, 0x00\n"
        ".L080F3550: .4byte 0x0000097E\n"
        ".L080F3554:\n"
        "    bl sub_080ECB38\n"
        "    bl EnemyInfo_Close\n"
        ".L080F355C:\n"
        "    ldr r2, .L080F3568\n"
        "    adds r1, r5, r2\n"
        ".L080F3560:\n"
        "    ldrh r0, [r1]\n"
        "    adds r0, #1\n"
        "    strh r0, [r1]\n"
        "    b .L080F3734\n"
        ".L080F3568: .4byte 0x0000097E\n"
        ".L080F356C:\n"
        "    movs r0, #1\n"
        "    bl EnemyInfo_IsWindowDone\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080F357A\n"
        "    b .L080F3734\n"
        ".L080F357A:\n"
        "    movs r0, #1\n"
        "    b .L080F3736\n"
        ".L080F357E:\n"
        "    bl BattleMsg_IsDone\n"
        "    cmp r0, #1\n"
        "    beq .L080F3588\n"
        "    b .L080F3734\n"
        ".L080F3588:\n"
        "    movs r0, #1\n"
        "    b .L080F3736\n"
        ".L080F358C:\n"
        "    movs r0, #0\n"
        "    bl sub_080EDA24\n"
        "    cmp r0, #0\n"
        "    beq .L080F35E0\n"
        "    movs r0, #1\n"
        "    bl sub_080EDA24\n"
        "    cmp r0, #0\n"
        "    beq .L080F35E0\n"
        "    ldr r1, .L080F35D0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetMode\n"
        "    movs r0, #1\n"
        "    bl BattleMsg_SetDone\n"
        "    movs r0, #1\n"
        "    bl sub_080E6DBC\n"
        "    ldr r0, .L080F35D4\n"
        "    adds r1, r5, r0\n"
        "    movs r2, #0\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L080F35D8\n"
        "    adds r0, r5, r1\n"
        "    strb r2, [r0]\n"
        "    ldr r2, .L080F35DC\n"
        "    adds r1, r5, r2\n"
        "    movs r0, #8\n"
        "    strh r0, [r1]\n"
        "    b .L080F3734\n"
        "    .byte 0x00, 0x00\n"
        ".L080F35D0: .4byte gUnknown_081242CE\n"
        ".L080F35D4: .4byte 0x00001190\n"
        ".L080F35D8: .4byte 0x00000695\n"
        ".L080F35DC: .4byte 0x0000097E\n"
        ".L080F35E0:\n"
        "    movs r0, #0\n"
        "    bl sub_080EDA24\n"
        "    cmp r0, #0\n"
        "    beq .L080F35F8\n"
        "    ldr r0, .L080F35F4\n"
        "    adds r1, r5, r0\n"
        "    movs r0, #0\n"
        "    b .L080F35FE\n"
        "    .byte 0x00, 0x00\n"
        ".L080F35F4: .4byte 0x00001190\n"
        ".L080F35F8:\n"
        "    ldr r2, .L080F3634\n"
        "    adds r1, r5, r2\n"
        "    movs r0, #1\n"
        ".L080F35FE:\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L080F3634\n"
        "    adds r0, r5, r1\n"
        "    ldrh r1, [r0]\n"
        "    lsls r1, r1, #2\n"
        "    movs r2, #0x99\n"
        "    lsls r2, r2, #4\n"
        "    adds r0, r5, r2\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    bl sub_080C2554\n"
        "    cmp r0, #0\n"
        "    bne .L080F3640\n"
        ".L080F361A:\n"
        "    ldr r0, .L080F3638\n"
        "    movs r1, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetMode\n"
        "    ldr r0, .L080F363C\n"
        "    adds r1, r5, r0\n"
        ".L080F362E:\n"
        "    movs r0, #6\n"
        "    strh r0, [r1]\n"
        "    b .L080F3734\n"
        ".L080F3634: .4byte 0x00001190\n"
        ".L080F3638: .4byte gUnknown_08124A50\n"
        ".L080F363C: .4byte 0x0000097E\n"
        ".L080F3640:\n"
        "    ldr r2, .L080F364C\n"
        "    adds r1, r5, r2\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    b .L080F3734\n"
        "    .byte 0x00, 0x00\n"
        ".L080F364C: .4byte 0x0000097E\n"
        ".L080F3650:\n"
        "    ldr r2, .L080F3674\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #0x10\n"
        "    ands r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    cmp r3, #0\n"
        "    beq .L080F3680\n"
        "    ldr r0, .L080F3678\n"
        "    adds r1, r5, r0\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #1\n"
        "    beq .L080F3734\n"
        "    movs r0, #1\n"
        "    strb r0, [r1]\n"
        "    ldr r0, .L080F367C\n"
        "    ldrh r0, [r0, #4]\n"
        "    b .L080F369A\n"
        ".L080F3674: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L080F3678: .4byte 0x00000695\n"
        ".L080F367C: .4byte gUnknown_086BF72C\n"
        ".L080F3680:\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #0x20\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080F36AC\n"
        "    ldr r2, .L080F36A4\n"
        "    adds r1, r5, r2\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0\n"
        "    beq .L080F3734\n"
        "    strb r3, [r1]\n"
        "    ldr r0, .L080F36A8\n"
        "    ldrh r0, [r0, #2]\n"
        ".L080F369A:\n"
        "    strh r0, [r4, #0xc]\n"
        "    movs r0, #0x64\n"
        "    bl sub_080ECF70\n"
        "    b .L080F3734\n"
        ".L080F36A4: .4byte 0x00000695\n"
        ".L080F36A8: .4byte gUnknown_086BF72C\n"
        ".L080F36AC:\n"
        "    ldrh r1, [r2]\n"
        "    movs r6, #1\n"
        "    adds r0, r6, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080F371C\n"
        "    ldr r1, .L080F3700\n"
        "    adds r0, r5, r1\n"
        "    ldrb r0, [r0]\n"
        "    ldr r2, .L080F3704\n"
        "    adds r4, r5, r2\n"
        "    strh r0, [r4]\n"
        "    movs r0, #0x65\n"
        "    bl sub_080ECF70\n"
        "    ldrh r1, [r4]\n"
        "    lsls r1, r1, #2\n"
        "    movs r2, #0x99\n"
        "    lsls r2, r2, #4\n"
        "    adds r0, r5, r2\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    bl sub_080C2554\n"
        "    cmp r0, #0\n"
        "    bne .L080F3710\n"
        "    ldr r0, .L080F3708\n"
        "    movs r1, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetMode\n"
        "    ldr r0, .L080F370C\n"
        "    adds r1, r5, r0\n"
        "    movs r0, #6\n"
        "    strh r0, [r1]\n"
        "    bl sub_080ECB38\n"
        "    b .L080F3734\n"
        "    .byte 0x00, 0x00\n"
        ".L080F3700: .4byte 0x00000695\n"
        ".L080F3704: .4byte 0x00001190\n"
        ".L080F3708: .4byte gUnknown_08124A50\n"
        ".L080F370C: .4byte 0x0000097E\n"
        ".L080F3710:\n"
        "    ldr r1, .L080F3718\n"
        "    adds r0, r5, r1\n"
        "    strh r6, [r0]\n"
        "    b .L080F3734\n"
        ".L080F3718: .4byte 0x0000097E\n"
        ".L080F371C:\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080F3734\n"
        "    movs r0, #0x66\n"
        "    bl sub_080ECF70\n"
        "    bl sub_080ECB38\n"
        "    movs r0, #1\n"
        "    b .L080F3736\n"
        ".L080F3734:\n"
        "    movs r0, #0\n"
        ".L080F3736:\n"
        "    add sp, #4\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// EnemyInfo_IsWindowDone @ 0x080F3740
u16 EnemyInfo_IsWindowDone(u8 which)
{
    struct Task *t = BFLOW->win50;
    u16 *d = t->data.h;
    u16 r = 0;

    switch (which)
    {
    case 0:
        r = t->unk1E != 0xFF;
        break;
    case 1:
        if (d[5] == 2)
            r = 1;
        break;
    case 2:
        break;
    }
    return r;
}

// EnemyInfo_UploadGfx @ 0x080F3780
void EnemyInfo_UploadGfx(void)
{
    DmaSet3Wait(gWindowTilemapBuffer, (void *)0x06001000, 0x84000200);
    DmaSet3Wait(gUnknown_08771F54, (void *)0x06000000, 0x840000D0);
    DmaSet3Wait(gUnk_030000B4, (void *)0x06006000, 0x84000800);
}

// EnemyInfo_ClearGfx @ 0x080F3814
void EnemyInfo_ClearGfx(void)
{
    DmaFill3Wait(0, (void *)0x06000000, 0x850000D0);
}

// EnemyInfo_DrawSkillNames @ 0x080F3850
/* Draws `n` skill names (8 glyphs each, or 8 x glyph 0x3C for an empty 0xFF slot). */
void EnemyInfo_DrawSkillNames(u8 *skills, u16 first, u16 n)
{
    u16 i;
    u16 j;

    for (i = 0; i < n; i++)
    {
        u8 skill = skills[i + first];

        if (skill != 0xFF)
        {
            u16 *name = (u16 *)(sub_080BF5C0(skill) + 6);

            for (j = 0; j < 8; j++)
                Font_DrawGlyphTinted(*name++, gUnk_030002B4, j * 12 + 12, i * 13 + 3, 0);
        }
        else
        {
            for (j = 0; j < 8; j++)
                Font_DrawGlyphTinted(0x3C, gUnk_030002B4, j * 12 + 12, i * 13 + 3, 0);
        }
    }
}

// EnemyInfo_DrawPage @ 0x080F390C
/* Draws the status panel of the selected combatant: labels, race class, alignment, level,
   HP, MP, then either its skills (mode 0-2: rows mode*3..) or its names and equipment. */
#ifdef NONMATCHING
void EnemyInfo_DrawPage(u8 mode)
{
    struct BattleFlow *b = BFLOW;
    u8 *rec = Demon_GetRecord(b->combatants[b->unk1190]);
    s32 align = sub_0815B864(b->combatants[b->unk1190]);
    const u8 *str;
    u8 *d;
    u16 i;
    u16 *p;
    u8 list[8];

    sub_081272AC();
    for (i = 0; i < 4; i++)
    {
        str = gUnknown_0876F81C[i];
        SmallFont_DrawAsciiTinted(str, gUnk_030000B4, 3, i * 9 + 6, 0, 8);
    }

    if ((s8)rec[0] <= 12)
        str = gUnknown_0876F83C[0];
    else if ((s8)rec[0] <= 26)
        str = gUnknown_0876F83C[1];
    else
        str = gUnknown_0876F83C[2];
    SmallFont_DrawAsciiTinted(str, gUnk_030000B4, 0x3E, 6, 0, 8);

    if (align == 0)
        str = gUnknown_0876F854[0];
    else if (align == 1)
        str = gUnknown_0876F854[1];
    else if (align == 2)
        str = gUnknown_0876F854[2];
    SmallFont_DrawAsciiTinted(str, gUnk_030000B4, 0x4E, 6, 0, 8);

    d = NumberToDigits(rec[1]);
    SmallFont_DrawGlyphTinted(d[0] + 9, gUnk_030000B4, 0x4E, 0xF, 0);
    if (d[1])
        SmallFont_DrawGlyphTinted(d[1] + 9, gUnk_030000B4, 0x46, 0xF, 0);

    d = NumberToDigits(*(s16 *)(rec + 2));
    SmallFont_DrawGlyphTinted(d[0] + 9, gUnk_030000B4, 0x4E, 0x18, 0);
    if (d[1] || d[2])
    {
        SmallFont_DrawGlyphTinted(d[1] + 9, gUnk_030000B4, 0x46, 0x18, 0);
        if (d[2])
            SmallFont_DrawGlyphTinted(d[2] + 9, gUnk_030000B4, 0x3E, 0x18, 0);
    }

    d = NumberToDigits(*(s16 *)(rec + 4));
    SmallFont_DrawGlyphTinted(d[0] + 9, gUnk_030000B4, 0x4E, 0x21, 0);
    if (d[1] || d[2])
    {
        SmallFont_DrawGlyphTinted(d[1] + 9, gUnk_030000B4, 0x46, 0x21, 0);
        if (d[2])
            SmallFont_DrawGlyphTinted(d[2] + 9, gUnk_030000B4, 0x3E, 0x21, 0);
    }

    if (mode <= 2)
    {
        u8 n = 0;
        u8 *skills = rec + 0x11;

        for (i = 0; i < 7; i++)
            list[i] |= 0xFF;
        for (i = 0; i < 7; i++)
        {
            u8 s = skills[i];

            if (s != 0xFF)
            {
                list[n] = s;
                n++;
            }
        }
        switch (mode)
        {
        case 0:
            EnemyInfo_DrawSkillNames(list, 0, 3);
            break;
        case 1:
            EnemyInfo_DrawSkillNames(list, 3, 3);
            break;
        case 2:
            EnemyInfo_DrawSkillNames(list, 6, 1);
            break;
        }
    }
    else
    {
        u16 *q;
        u16 e;

        p = (u16 *)(rec + 0x32);
        q = (u16 *)(rec + 0x48);
        for (i = 0; i < 8; i++)
            Font_DrawGlyphTinted(*p++, gUnk_030002B4, i * 12 + 12, 3, 0);
        p = q;
        for (i = 0; i < 8; i++)
            Font_DrawGlyphTinted(*p++, gUnk_030002B4, i * 12 + 12, 0x10, 0);
        e = *(u16 *)(rec + 0x1A);
        if (rec[0x1A] == 0xFF)
            p = (u16 *)gUnknown_0876F86C;
        else if (e < 0xD0)
            p = (u16 *)(Equipment_GetRecord36_MidRange(rec[0x1A]) + 0x14);
        else
            p = (u16 *)(Action_GetRecord(e & 0x1FF) + 0xC);
        for (i = 0; i < 8; i++)
            Font_DrawGlyphTinted(*p++, gUnk_030002B4, i * 12 + 12, 0x1D, 6);
    }

    p = sub_080EA9F8(rec[0]);
    for (i = 0; *p != 0; i++)
        Font_DrawGlyphTinted(*p++, gUnk_030014B4, i * 12 + 4, 4, 6);
    VBlankTask_AddCounted(EnemyInfo_UploadGfx, 1);
}
#else
NAKED
void EnemyInfo_DrawPage(u8 mode)
{
    asm_unified(
        ".L080F390C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    sub sp, #0x10\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    mov r8, r0\n"
        "    ldr r4, .L080F3980\n"
        "    ldr r0, .L080F3984\n"
        "    adds r5, r4, r0\n"
        "    ldrh r0, [r5]\n"
        "    lsls r0, r0, #2\n"
        "    movs r1, #0x99\n"
        "    lsls r1, r1, #4\n"
        "    adds r4, r4, r1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    bl Demon_GetRecord\n"
        "    adds r7, r0, #0\n"
        "    ldrh r0, [r5]\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r0, r4\n"
        "    ldr r0, [r0]\n"
        "    bl sub_0815B864\n"
        "    adds r6, r0, #0\n"
        "    bl sub_081272AC\n"
        "    movs r4, #0\n"
        ".L080F3948:\n"
        "    lsls r3, r4, #3\n"
        "    ldr r0, .L080F3988\n"
        "    adds r5, r3, r0\n"
        "    adds r3, r3, r4\n"
        "    adds r3, #6\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    movs r0, #0\n"
        "    str r0, [sp]\n"
        "    movs r0, #8\n"
        "    str r0, [sp, #4]\n"
        "    adds r0, r5, #0\n"
        "    ldr r1, .L080F398C\n"
        "    movs r2, #3\n"
        "    bl SmallFont_DrawAsciiTinted\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #3\n"
        "    bls .L080F3948\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r7, r0]\n"
        "    cmp r0, #0xc\n"
        "    bgt .L080F3994\n"
        "    ldr r5, .L080F3990\n"
        "    b .L080F399C\n"
        "    .byte 0x00, 0x00\n"
        ".L080F3980: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080F3984: .4byte 0x00001190\n"
        ".L080F3988: .4byte gUnknown_0876F81C\n"
        ".L080F398C: .4byte 0x030000B4 @ IWRAM+0xB4\n"
        ".L080F3990: .4byte gUnknown_0876F83C\n"
        ".L080F3994:\n"
        "    ldr r5, .L080F39B8\n"
        "    cmp r0, #0x1a\n"
        "    bgt .L080F399C\n"
        "    subs r5, #8\n"
        ".L080F399C:\n"
        "    ldr r1, .L080F39BC\n"
        "    movs r0, #0\n"
        "    str r0, [sp]\n"
        "    movs r0, #8\n"
        "    str r0, [sp, #4]\n"
        "    adds r0, r5, #0\n"
        "    movs r2, #0x3e\n"
        "    movs r3, #6\n"
        "    bl SmallFont_DrawAsciiTinted\n"
        "    cmp r6, #0\n"
        "    bne .L080F39C4\n"
        "    ldr r5, .L080F39C0\n"
        "    b .L080F39D6\n"
        ".L080F39B8: .4byte gUnknown_0876F84C\n"
        ".L080F39BC: .4byte 0x030000B4 @ IWRAM+0xB4\n"
        ".L080F39C0: .4byte gUnknown_0876F854\n"
        ".L080F39C4:\n"
        "    cmp r6, #1\n"
        "    bne .L080F39D0\n"
        "    ldr r5, .L080F39CC\n"
        "    b .L080F39D6\n"
        ".L080F39CC: .4byte gUnknown_0876F85C\n"
        ".L080F39D0:\n"
        "    cmp r6, #2\n"
        "    bne .L080F39D6\n"
        "    ldr r5, .L080F3B0C\n"
        ".L080F39D6:\n"
        "    ldr r6, .L080F3B10\n"
        "    movs r4, #0\n"
        "    str r4, [sp]\n"
        "    movs r0, #8\n"
        "    str r0, [sp, #4]\n"
        "    adds r0, r5, #0\n"
        "    adds r1, r6, #0\n"
        "    movs r2, #0x4e\n"
        "    movs r3, #6\n"
        "    bl SmallFont_DrawAsciiTinted\n"
        "    ldrb r0, [r7, #1]\n"
        "    bl NumberToDigits\n"
        "    adds r5, r0, #0\n"
        "    ldrb r0, [r5]\n"
        "    adds r0, #9\n"
        "    str r4, [sp]\n"
        "    adds r1, r6, #0\n"
        "    movs r2, #0x4e\n"
        "    movs r3, #0xf\n"
        "    bl SmallFont_DrawGlyphTinted\n"
        "    ldrb r0, [r5, #1]\n"
        "    cmp r0, #0\n"
        "    beq .L080F3A18\n"
        "    adds r0, #9\n"
        "    str r4, [sp]\n"
        "    adds r1, r6, #0\n"
        "    movs r2, #0x46\n"
        "    movs r3, #0xf\n"
        "    bl SmallFont_DrawGlyphTinted\n"
        ".L080F3A18:\n"
        "    movs r1, #2\n"
        "    ldrsh r0, [r7, r1]\n"
        "    bl NumberToDigits\n"
        "    adds r5, r0, #0\n"
        "    ldrb r0, [r5]\n"
        "    adds r0, #9\n"
        "    str r4, [sp]\n"
        "    adds r1, r6, #0\n"
        "    movs r2, #0x4e\n"
        "    movs r3, #0x18\n"
        "    bl SmallFont_DrawGlyphTinted\n"
        "    ldrb r0, [r5, #1]\n"
        "    cmp r0, #0\n"
        "    bne .L080F3A3E\n"
        "    ldrb r0, [r5, #2]\n"
        "    cmp r0, #0\n"
        "    beq .L080F3A62\n"
        ".L080F3A3E:\n"
        "    ldrb r0, [r5, #1]\n"
        "    adds r0, #9\n"
        "    str r4, [sp]\n"
        "    adds r1, r6, #0\n"
        "    movs r2, #0x46\n"
        "    movs r3, #0x18\n"
        "    bl SmallFont_DrawGlyphTinted\n"
        "    ldrb r0, [r5, #2]\n"
        "    cmp r0, #0\n"
        "    beq .L080F3A62\n"
        "    adds r0, #9\n"
        "    str r4, [sp]\n"
        "    adds r1, r6, #0\n"
        "    movs r2, #0x3e\n"
        "    movs r3, #0x18\n"
        "    bl SmallFont_DrawGlyphTinted\n"
        ".L080F3A62:\n"
        "    movs r1, #4\n"
        "    ldrsh r0, [r7, r1]\n"
        "    bl NumberToDigits\n"
        "    adds r5, r0, #0\n"
        "    ldrb r0, [r5]\n"
        "    adds r0, #9\n"
        "    ldr r6, .L080F3B10\n"
        "    movs r4, #0\n"
        "    str r4, [sp]\n"
        "    adds r1, r6, #0\n"
        "    movs r2, #0x4e\n"
        "    movs r3, #0x21\n"
        "    bl SmallFont_DrawGlyphTinted\n"
        "    ldrb r0, [r5, #1]\n"
        "    cmp r0, #0\n"
        "    bne .L080F3A8C\n"
        "    ldrb r0, [r5, #2]\n"
        "    cmp r0, #0\n"
        "    beq .L080F3AB0\n"
        ".L080F3A8C:\n"
        "    ldrb r0, [r5, #1]\n"
        "    adds r0, #9\n"
        "    str r4, [sp]\n"
        "    adds r1, r6, #0\n"
        "    movs r2, #0x46\n"
        "    movs r3, #0x21\n"
        "    bl SmallFont_DrawGlyphTinted\n"
        "    ldrb r0, [r5, #2]\n"
        "    cmp r0, #0\n"
        "    beq .L080F3AB0\n"
        "    adds r0, #9\n"
        "    str r4, [sp]\n"
        "    adds r1, r6, #0\n"
        "    movs r2, #0x3e\n"
        "    movs r3, #0x21\n"
        "    bl SmallFont_DrawGlyphTinted\n"
        ".L080F3AB0:\n"
        "    mov r0, r8\n"
        "    cmp r0, #2\n"
        "    bhi .L080F3B3A\n"
        "    movs r2, #0\n"
        "    movs r4, #0\n"
        "    adds r3, r7, #0\n"
        "    adds r3, #0x11\n"
        "    movs r5, #0xff\n"
        ".L080F3AC0:\n"
        "    mov r0, sp\n"
        "    adds r0, r0, r4\n"
        "    adds r0, #8\n"
        "    ldrb r1, [r0]\n"
        "    orrs r1, r5\n"
        "    strb r1, [r0]\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #6\n"
        "    bls .L080F3AC0\n"
        "    movs r4, #0\n"
        ".L080F3AD8:\n"
        "    adds r0, r3, r4\n"
        "    ldrb r1, [r0]\n"
        "    adds r0, r1, #0\n"
        "    cmp r0, #0xff\n"
        "    beq .L080F3AF0\n"
        "    mov r0, sp\n"
        "    adds r0, r0, r2\n"
        "    adds r0, #8\n"
        "    strb r1, [r0]\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r2, r0, #0x18\n"
        ".L080F3AF0:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #6\n"
        "    bls .L080F3AD8\n"
        "    mov r1, r8\n"
        "    cmp r1, #1\n"
        "    beq .L080F3B22\n"
        "    cmp r1, #1\n"
        "    bgt .L080F3B14\n"
        "    cmp r1, #0\n"
        "    beq .L080F3B1C\n"
        "    b .L080F3BF0\n"
        "    .byte 0x00, 0x00\n"
        ".L080F3B0C: .4byte gUnknown_0876F864\n"
        ".L080F3B10: .4byte 0x030000B4 @ IWRAM+0xB4\n"
        ".L080F3B14:\n"
        "    mov r0, r8\n"
        "    cmp r0, #2\n"
        "    beq .L080F3B2E\n"
        "    b .L080F3BF0\n"
        ".L080F3B1C:\n"
        "    add r0, sp, #8\n"
        "    movs r1, #0\n"
        "    b .L080F3B26\n"
        ".L080F3B22:\n"
        "    add r0, sp, #8\n"
        "    movs r1, #3\n"
        ".L080F3B26:\n"
        "    movs r2, #3\n"
        "    bl EnemyInfo_DrawSkillNames\n"
        "    b .L080F3BF0\n"
        ".L080F3B2E:\n"
        "    add r0, sp, #8\n"
        "    movs r1, #6\n"
        "    movs r2, #1\n"
        "    bl EnemyInfo_DrawSkillNames\n"
        "    b .L080F3BF0\n"
        ".L080F3B3A:\n"
        "    adds r4, r7, #0\n"
        "    adds r4, #0x32\n"
        "    movs r5, #0\n"
        "    adds r6, r7, #0\n"
        "    adds r6, #0x48\n"
        ".L080F3B44:\n"
        "    ldrh r0, [r4]\n"
        "    adds r4, #2\n"
        "    lsls r2, r5, #1\n"
        "    adds r2, r2, r5\n"
        "    lsls r2, r2, #0x12\n"
        "    movs r1, #0xc0\n"
        "    lsls r1, r1, #0xc\n"
        "    adds r2, r2, r1\n"
        "    lsrs r2, r2, #0x10\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    ldr r1, .L080F3BA4\n"
        "    movs r3, #3\n"
        "    bl Font_DrawGlyphTinted\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #7\n"
        "    bls .L080F3B44\n"
        "    adds r4, r6, #0\n"
        "    movs r5, #0\n"
        ".L080F3B70:\n"
        "    ldrh r0, [r4]\n"
        "    adds r4, #2\n"
        "    lsls r2, r5, #1\n"
        "    adds r2, r2, r5\n"
        "    lsls r2, r2, #0x12\n"
        "    movs r1, #0xc0\n"
        "    lsls r1, r1, #0xc\n"
        "    adds r2, r2, r1\n"
        "    lsrs r2, r2, #0x10\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    ldr r1, .L080F3BA4\n"
        "    movs r3, #0x10\n"
        "    bl Font_DrawGlyphTinted\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #7\n"
        "    bls .L080F3B70\n"
        "    ldrh r1, [r7, #0x1a]\n"
        "    ldrb r0, [r7, #0x1a]\n"
        "    cmp r0, #0xff\n"
        "    bne .L080F3BAC\n"
        "    ldr r4, .L080F3BA8\n"
        "    b .L080F3BC6\n"
        ".L080F3BA4: .4byte 0x030002B4 @ IWRAM+0x2B4\n"
        ".L080F3BA8: .4byte gUnknown_0876F86C\n"
        ".L080F3BAC:\n"
        "    cmp r1, #0xcf\n"
        "    bhi .L080F3BBA\n"
        "    bl Equipment_GetRecord36_MidRange\n"
        "    adds r4, r0, #0\n"
        "    adds r4, #0x14\n"
        "    b .L080F3BC6\n"
        ".L080F3BBA:\n"
        "    ldr r0, .L080F3BFC\n"
        "    ands r0, r1\n"
        "    bl Action_GetRecord\n"
        "    adds r4, r0, #0\n"
        "    adds r4, #0xc\n"
        ".L080F3BC6:\n"
        "    movs r5, #0\n"
        ".L080F3BC8:\n"
        "    ldrh r0, [r4]\n"
        "    adds r4, #2\n"
        "    lsls r2, r5, #1\n"
        "    adds r2, r2, r5\n"
        "    lsls r2, r2, #0x12\n"
        "    movs r1, #0xc0\n"
        "    lsls r1, r1, #0xc\n"
        "    adds r2, r2, r1\n"
        "    lsrs r2, r2, #0x10\n"
        "    movs r1, #6\n"
        "    str r1, [sp]\n"
        "    ldr r1, .L080F3C00\n"
        "    movs r3, #0x1d\n"
        "    bl Font_DrawGlyphTinted\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #7\n"
        "    bls .L080F3BC8\n"
        ".L080F3BF0:\n"
        "    ldrb r0, [r7]\n"
        "    bl sub_080EA9F8\n"
        "    adds r4, r0, #0\n"
        "    movs r5, #0\n"
        "    b .L080F3C28\n"
        ".L080F3BFC: .4byte 0x000001FF\n"
        ".L080F3C00: .4byte 0x030002B4 @ IWRAM+0x2B4\n"
        ".L080F3C04:\n"
        "    ldrh r0, [r4]\n"
        "    adds r4, #2\n"
        "    lsls r2, r5, #1\n"
        "    adds r2, r2, r5\n"
        "    lsls r2, r2, #0x12\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #0xb\n"
        "    adds r2, r2, r1\n"
        "    lsrs r2, r2, #0x10\n"
        "    movs r1, #6\n"
        "    str r1, [sp]\n"
        "    ldr r1, .L080F3C44\n"
        "    movs r3, #4\n"
        "    bl Font_DrawGlyphTinted\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        ".L080F3C28:\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #0\n"
        "    bne .L080F3C04\n"
        "    ldr r0, .L080F3C48\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    add sp, #0x10\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080F3C44: .4byte 0x030014B4 @ IWRAM+0x14B4\n"
        ".L080F3C48: .4byte EnemyInfo_UploadGfx\n"
    );
}
#endif

// EnemyInfo_HandleInput @ 0x080F3C4C
/* Input for the status panel: B/A closes, Up/Down page through EnemyInfo_DrawPage's pages. */
u16 EnemyInfo_HandleInput(void)
{
    struct BattleFlow *b = BFLOW;
    u8 *rec = Demon_GetRecord(b->combatants[b->unk1190]);
    u16 name[10];
    u8 i;
    u16 *src;

    memset(name, 0, sizeof(name));
    if (gKeysNew & 3)
    {
        Sound_Play(0x66);
        return 1;
    }
    if (gKeysNew & 0x40)
    {
        if (b->unk693 != 0)
        {
            b->unk693--;
            EnemyInfo_DrawPage(b->unk693);
            Sound_Play(0x64);
        }
    }
    else if (gKeysNew & 0x80)
    {
        if (b->unk693 != 3)
        {
            b->unk693++;
            EnemyInfo_DrawPage(b->unk693);
            Sound_Play(0x64);
        }
    }
    for (i = 0, src = (u16 *)(rec + 0x22); i < 8; i++)
        name[i] = *(u16 *)((u32)src + (i << 1));
    Text_DrawSpriteString(name, 0, 0, 0x4A, 3, 0xC);
    if (b->unk693 == 0)
        Sprite_Draw(gUnknown_08001000, 0, 0, 1, 0, 0xDE, 0x5C);
    else if ((u8)(b->unk693 - 1) <= 1)
    {
        Sprite_Draw(gUnknown_08001000, 0, 0, 1, 0, 0xDE, 0x5C);
        Sprite_Draw(gUnknown_08000FF0, 0, 0, 1, 0, 0xDE, 0x3C);
    }
    else
        Sprite_Draw(gUnknown_08000FF0, 0, 0, 1, 0, 0xDE, 0x3C);
    return 0;
}

// EnemyInfo_Close @ 0x080F3DA4
void EnemyInfo_Close(void)
{
    struct BattleFlow *b = BFLOW;

    TextWindow_Close(b->win4C, 0);
    TextWindow_Close(b->win50, 0);
    TextWindow_Close(b->win54, 0);
    VBlankTask_AddCounted(EnemyInfo_ClearGfx, 1);
}

// sub_080F3DD8 @ 0x080F3DD8
u32 sub_080F3DD8(void)
{
    return (Moon_GetPhase() >> 4) & 0xF;
}

// sub_080F3DE8 @ 0x080F3DE8
void sub_080F3DE8(s16 v)
{
    gUnk_03006438->unk1A = v;
}

// sub_080F3DF4 @ 0x080F3DF4
s16 sub_080F3DF4(void)
{
    return gUnk_03006438->unk1A;
}

// sub_080F3E04 @ 0x080F3E04
void sub_080F3E04(s16 v)
{
    gUnk_03006438->unk1C = v;
}

// sub_080F3E10 @ 0x080F3E10
s16 sub_080F3E10(void)
{
    return gUnk_03006438->unk1C;
}

// sub_080F3E20 @ 0x080F3E20
void sub_080F3E20(s32 a)
{
    Money_Add(a);
}

// sub_080F3E2C @ 0x080F3E2C
s32 sub_080F3E2C(s32 a)
{
    return Magnetite_Add(a);
}

// sub_080F3E38 @ 0x080F3E38
void sub_080F3E38(s32 v)
{
    gUnk_03006438->unk16 = v;
}

// sub_080F3E44 @ 0x080F3E44
s16 sub_080F3E44(void)
{
    return gUnk_03006438->unk16;
}
