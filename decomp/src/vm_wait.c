/* Script VM wait-state handlers (table 0x08790FDC, indexed by gScriptWaitState). Each one
   sets gScriptWaitBusy to 1 while the VM must keep waiting, or clears the wait state. */

#include "global.h"
#include "vm.h"

// sub_0813D118 @ 0x0813D118
void sub_0813D118(void)
{
    if (sub_080CE74C(gUnk_030068E0) != 0)
    {
        gScriptWaitState = 15;
        gUnk_0203DB5C = 60;
    }
    gScriptWaitBusy = 1;
}

// sub_0813D14C @ 0x0813D14C
void sub_0813D14C(void)
{
    gScriptWaitBusy = 1;
}

// sub_0813D158 @ 0x0813D158
void sub_0813D158(void)
{
    gScriptWaitBusy = 1;
}

// sub_0813D164 @ 0x0813D164
void sub_0813D164(void)
{
    gScriptWaitBusy = 1;
}

// sub_0813D170 @ 0x0813D170
void sub_0813D170(void)
{
    gScriptWaitBusy = 1;
}

// sub_0813D17C @ 0x0813D17C
void sub_0813D17C(void)
{
    gScriptWaitBusy = 1;
}

// sub_0813D188 @ 0x0813D188
void sub_0813D188(void)
{
    gScriptWaitState = 0;
    gScriptJumpTarget = gUnk_0203DAC8[0];
    gScriptWaitBusy = 0;
}

// sub_0813D1AC @ 0x0813D1AC
void sub_0813D1AC(void)
{
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

// sub_0813D1C0 @ 0x0813D1C0
void sub_0813D1C0(void)
{
    if (sub_080B7DF8(gUnk_03006954) == 0)
    {
        gScriptWaitBusy = 1;
    }
    else
    {
        gUnk_03006954 = 0;
        gScriptWaitState = 0;
        gScriptWaitBusy = 0;
    }
}

// sub_0813D1F8 @ 0x0813D1F8
void sub_0813D1F8(void)
{
}

// sub_0813D1FC @ 0x0813D1FC
void sub_0813D1FC(void)
{
    if (sub_080D1EA8(gUnk_030068E0) == 0)
    {
        gScriptWaitBusy = 1;
    }
    else
    {
        gScriptWaitState = 0;
        gScriptWaitBusy = 0;
    }
}

// sub_0813D234 @ 0x0813D234
void sub_0813D234(void)
{
    if (sub_080B8160(gUnk_03006938) == 0)
    {
        gScriptWaitBusy = 1;
    }
    else
    {
        gUnk_03006938 = 0;
        gScriptWaitState = 0;
        gScriptWaitBusy = 0;
    }
}

// sub_0813D26C @ 0x0813D26C
void sub_0813D26C(void)
{
    gMsgGlyphCount = 0;
    gTextColumn = 0;
    gTextLine = 0;
    gUnk_0203DB4A = 0;
    Font_ResetGlyphSpriteCache(0x180);
    gUnk_0203DB72 = gUnk_030065E0 - 0x90;
    sub_080B7E3C(0, gUnknown_0878FFD0[gUnk_0203DB72 * 3], gUnknown_0878FFD0[gUnk_0203DB72 * 3 + 1],
                 gUnknown_0878FFD0[gUnk_0203DB72 * 3 + 2], 0);
    gScriptJumpTarget = gUnk_0203DAC8[gUnknown_08790E4C[gUnk_0203DB72] + 1];
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

// sub_0813D314 @ 0x0813D314
void sub_0813D314(void)
{
    gMsgGlyphCount = 0;
    gTextColumn = 0;
    gTextLine = 0;
    gUnk_0203DB4A = 0;
    Font_ResetGlyphSpriteCache(0x180);
    gScriptJumpTarget = gUnk_0203DAC8[0];
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

// sub_0813D368 @ 0x0813D368
void sub_0813D368(void)
{
    gScriptJumpTarget = gUnk_0203DAC8[0];
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

// sub_0813D38C @ 0x0813D38C
void sub_0813D38C(void)
{
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

// sub_0813D3A0 @ 0x0813D3A0
void sub_0813D3A0(void)
{
    gScriptWaitBusy = 1;
}

// sub_0813D3AC @ 0x0813D3AC
void sub_0813D3AC(void)
{
    gScriptWaitBusy = 1;
}

// sub_0813D3B8 @ 0x0813D3B8
void sub_0813D3B8(void)
{
    gScriptWaitBusy = 1;
}

// sub_0813D3C4 @ 0x0813D3C4
void sub_0813D3C4(void)
{
    gScriptWaitBusy = 1;
}

// sub_0813D3D0 @ 0x0813D3D0
void sub_0813D3D0(void)
{
    gScriptWaitBusy = 1;
}

// sub_0813D3DC @ 0x0813D3DC
void sub_0813D3DC(void)
{
    gScriptWaitBusy = 1;
}

// sub_0813D3E8 @ 0x0813D3E8
void sub_0813D3E8(void)
{
    gScriptWaitBusy = 1;
}

// sub_0813D3F4 @ 0x0813D3F4
#ifdef NONMATCHING
void sub_0813D3F4(void)
{
    u16 sel = 0;
    u16 open = gUnk_030065E8;

    if (open == 0)
    {
        sel = sub_0812DC10();
        if (sel == 0xFE)
        {
            gScriptWaitBusy = 1;
        }
        else
        {
            if (sel == 0xFF)
                gScriptJumpTarget = gUnk_0203DAC8[0];
            else
                gUnk_03006944 = sel;
            gScriptWaitState = open;
            *(vu16 *)&gScriptWaitBusy = open;
            gScriptWaitBusy = 0;
        }
    }
    else
    {
        gUnk_03006944 = sel;
        gScriptWaitState = sel;
        gScriptWaitBusy = sel;
    }
}
#else
NAKED
void sub_0813D3F4(void)
{
    asm_unified(
        "    push {r4, lr}\n"
        "    movs r1, #0\n"
        "    ldr r0, .L0813D414\n"
        "    ldrh r4, [r0]\n"
        "    cmp r4, #0\n"
        "    bne .L0813D454\n"
        "    bl sub_0812DC10\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    cmp r1, #0xfe\n"
        "    bne .L0813D41C\n"
        "    ldr r1, .L0813D418\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    b .L0813D460\n"
        ".L0813D414: .4byte 0x030065E8 @ IWRAM+0x65E8\n"
        ".L0813D418: .4byte 0x03006858 @ IWRAM+0x6858\n"
        ".L0813D41C:\n"
        "    cmp r1, #0xff\n"
        "    bne .L0813D434\n"
        "    ldr r1, .L0813D42C\n"
        "    ldr r0, .L0813D430\n"
        "    ldr r0, [r0]\n"
        "    str r0, [r1]\n"
        "    b .L0813D438\n"
        "    .byte 0x00, 0x00\n"
        ".L0813D42C: .4byte 0x030068E4 @ IWRAM+0x68E4\n"
        ".L0813D430: .4byte 0x0203DAC8 @ EWRAM+0x3DAC8\n"
        ".L0813D434:\n"
        "    ldr r0, .L0813D448\n"
        "    strh r1, [r0]\n"
        ".L0813D438:\n"
        "    ldr r0, .L0813D44C\n"
        "    strh r4, [r0]\n"
        "    ldr r0, .L0813D450\n"
        "    strh r4, [r0]\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    b .L0813D460\n"
        ".L0813D448: .4byte 0x03006944 @ IWRAM+0x6944\n"
        ".L0813D44C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L0813D450: .4byte 0x03006858 @ IWRAM+0x6858\n"
        ".L0813D454:\n"
        "    ldr r0, .L0813D468\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L0813D46C\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L0813D470\n"
        "    strh r1, [r0]\n"
        ".L0813D460:\n"
        "    pop {r4}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L0813D468: .4byte 0x03006944 @ IWRAM+0x6944\n"
        ".L0813D46C: .4byte 0x0203DB5A @ EWRAM+0x3DB5A\n"
        ".L0813D470: .4byte 0x03006858 @ IWRAM+0x6858\n"
    );
}
#endif

// sub_0813D474 @ 0x0813D474
void sub_0813D474(void)
{
    if (sub_080CE74C(gUnk_030068E0) == 0)
    {
        gScriptWaitBusy = 1;
    }
    else
    {
        gScriptWaitState = 0;
        if (gYesNoResult == 1)
            gScriptJumpTarget = gUnk_0203DAC8[0];
        gScriptWaitBusy = 0;
    }
}

// sub_0813D4C8 @ 0x0813D4C8
void sub_0813D4C8(void)
{
    s32 t = --gUnk_0203DB5C;

    if (t == 0)
    {
        gScriptWaitState = t;
        sub_080D34F0(gUnk_030068A4);
        gScriptWaitBusy = t;
    }
    gScriptWaitBusy = 1;
}

// sub_0813D508 @ 0x0813D508
void sub_0813D508(void)
{
    gUnk_03006954 = 0;
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

// sub_0813D524 @ 0x0813D524
void sub_0813D524(void)
{
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

// sub_0813D538 @ 0x0813D538
void sub_0813D538(void)
{
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

// sub_0813D54C @ 0x0813D54C
void sub_0813D54C(void)
{
    if (sub_080B9528(gUnk_03006954) == 0)
    {
        gScriptWaitBusy = 1;
    }
    else
    {
        gUnk_03006954 = 0;
        gScriptWaitState = 0;
        gScriptWaitBusy = 0;
    }
}

// sub_0813D584 @ 0x0813D584
void sub_0813D584(void)
{
    if (sub_080BA920() == 0)
    {
        gScriptWaitBusy = 1;
    }
    else
    {
        gUnk_03006954 = 0;
        gScriptWaitState = 0;
        gScriptWaitBusy = 0;
    }
}

// sub_0813D5BC @ 0x0813D5BC
void sub_0813D5BC(void)
{
    if (sub_080CE74C(gUnk_03006964) == 0)
    {
        gScriptWaitBusy = 1;
    }
    else
    {
        if (Battle_GetCombatant(0x8000)->hp <= gUnk_0203DB2C)
        {
            Battle_GetCombatant(0x8000)->hp = 0;
            sub_080C08E8(0, 0x8000);
        }
        else
        {
            Battle_GetCombatant(0x8000)->hp -= gUnk_0203DB2C;
        }
        sub_080C84A0();
        gScriptWaitState = 0;
        gScriptWaitBusy = 0;
    }
}

// sub_0813D638 @ 0x0813D638
void sub_0813D638(struct ScriptTask *task)
{
    s32 n;
    s16 i;

    if (sub_080B8B08(gUnk_03006964) == 0)
    {
        gScriptWaitBusy = 1;
        return;
    }
    n = sub_080C104C();
    for (i = 0; i < n + 4; i++)
    {
        if (sub_080C0A00(i) == 1 && sub_080F3EC8(i) == 1)
        {
            s16 dmg = Battle_GetCombatant(0x8000 + i)->hp >> 3;

            if (dmg <= 0)
                dmg = 1;
            if (Battle_GetCombatant(0x8000 + i)->hp <= dmg)
            {
                Battle_GetCombatant(0x8000 + i)->hp = 0;
                sub_080C08E8(i, 0x8000);
            }
            else
            {
                Battle_GetCombatant(0x8000 + i)->hp -= dmg;
            }
        }
    }
    sub_080C84A0();
    if (sub_08138CE8() != 0)
        task->unk1C = 1;
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

// sub_0813D724 @ 0x0813D724
void sub_0813D724(void)
{
    if (sub_080D53E0() != 1)
    {
        gScriptWaitBusy = 1;
        return;
    }
    if (gUnk_030037F0 != 0)
    {
        if (gUnk_030037F0 > 50000)
            gScriptJumpTarget = gUnk_0203DAC8[2];
        else if (sub_080C31F0() + gUnk_030037F0 > 999999)
            gScriptJumpTarget = gUnk_0203DAC8[1];
        else
        {
            gUnk_0203DB2C = gUnk_030037F0;
            gScriptJumpTarget = gUnk_0203DAC8[0];
        }
    }
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

// sub_0813D7B8 @ 0x0813D7B8
void sub_0813D7B8(void)
{
    if (sub_080CE74C(gUnk_030068E0) == 0)
    {
        gScriptWaitBusy = 1;
    }
    else
    {
        if (gYesNoResult != 1)
        {
            gScriptJumpTarget = gUnk_0203DAC8[0];
            gUnk_0203DB86 = 1;
        }
        gScriptWaitState = 0;
        gScriptWaitBusy = 0;
    }
}

// sub_0813D814 @ 0x0813D814
void sub_0813D814(void)
{
    u32 id;
    u16 v;
    u16 idx;
    u16 pc;
    u16 lo;
    u32 target;

    if (sub_080CE74C(gUnk_030068E0) == 0)
    {
        gScriptWaitBusy = 1;
        return;
    }
    id = sub_0812EEC4();
    v = Demon_GetField(id, 0x1F) & 0xFF;
    if (v >= 0xC0)
    {
        idx = 0x1C;
    }
    else
    {
        idx = gUnknown_08790E5A[v];
        if ((u16)(idx - 10) <= 1)
        {
            gUnk_0203DB80 = gUnk_0203DB7C;
            gUnk_0203DB7C = id;
        }
    }
    pc = idx * 2;
    gScriptBase = gUnknown_08032CD8;
    lo = gScriptBase[pc];
    target = gScriptBase[pc + 1];
    target = target << 16 | lo;
    gScriptJumpTarget = (u16 *)target;
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

// sub_0813D8B8 @ 0x0813D8B8
void sub_0813D8B8(void)
{
    if (sub_080D3AA0(0) != 1)
    {
        gScriptWaitBusy = 1;
        return;
    }
    if (gYesNoResult == 1)
        gScriptJumpTarget = gUnk_0203DAC8[0];
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

// sub_0813D904 @ 0x0813D904
void sub_0813D904(void)
{
    u32 r;

    if (sub_080D3CCC() != 1)
    {
        gScriptWaitBusy = 1;
        return;
    }
    r = sub_080D3CE4();
    if (r - 1 <= 1)
        gScriptJumpTarget = gUnk_0203DAC8[0];
    else if (r - 3 <= 1)
        gScriptJumpTarget = gUnk_0203DAC8[1];
    gScriptWaitState = 0;
    gScriptWaitBusy = 0;
}

// sub_0813D964 @ 0x0813D964
void sub_0813D964(void)
{
    if (sub_080D4594() != 1)
    {
        gScriptWaitBusy = 1;
    }
    else
    {
        gScriptWaitState = 0;
        gScriptWaitBusy = 0;
    }
}

// sub_0813D994 @ 0x0813D994
void sub_0813D994(void)
{
    gScriptWaitState = 0;
    gScriptJumpTarget = gUnk_0203DAC8[2];
    gScriptWaitBusy = 0;
}

// sub_0813D9B8 @ 0x0813D9B8
void sub_0813D9B8(void)
{
    gScriptWaitBusy = 1;
}

// sub_0813D9C4 @ 0x0813D9C4
void sub_0813D9C4(void)
{
    if (Window_IsIdle(gMsgWindow) != 0)
    {
        gUnk_0203DB5C = 10;
        gScriptWaitState = 15;
    }
    gScriptWaitBusy = 1;
}

// sub_0813D9F8 @ 0x0813D9F8
void sub_0813D9F8(void)
{
}

// sub_0813D9FC @ 0x0813D9FC
void sub_0813D9FC(void)
{
}

// sub_0813DA00 @ 0x0813DA00
void sub_0813DA00(void)
{
}

// sub_0813DA04 @ 0x0813DA04
void sub_0813DA04(void)
{
    gScriptPc += 4;
}

// sub_0813DA14 @ 0x0813DA14
#ifdef NONMATCHING
bool32 sub_0813DA14(u32 idx)
{
    s16 t = sub_080C07E0(idx);
    u32 f;
    u16 g;
    u32 mask;

    if (t == 0x75 || t == 0x20 || t == 0x21 || t == 0x22)
        return TRUE;
    f = sub_080C0818(idx);
    g = f;
    if (0x8000 & f)
        mask = 0x7F;
    else if (g & 0x8000)
        mask = 0x3F;
    else
        return TRUE;
    if (sub_080C2244() & mask)
        return TRUE;
    return FALSE;
}
#else
NAKED
bool32 sub_0813DA14(u32 idx)
{
    asm_unified(
        "    push {r4, lr}\n"
        "    adds r4, r0, #0\n"
        "    bl sub_080C07E0\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #0x75\n"
        "    beq .L0813DA62\n"
        "    cmp r0, #0x20\n"
        "    beq .L0813DA62\n"
        "    cmp r0, #0x21\n"
        "    beq .L0813DA62\n"
        "    cmp r0, #0x22\n"
        "    beq .L0813DA62\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080C0818\n"
        "    lsls r1, r0, #0x10\n"
        "    lsrs r2, r1, #0x10\n"
        "    movs r3, #0x80\n"
        "    lsls r3, r3, #8\n"
        "    adds r1, r3, #0\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L0813DA4A\n"
        "    movs r4, #0x7f\n"
        "    b .L0813DA54\n"
        ".L0813DA4A:\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r3\n"
        "    cmp r0, #0\n"
        "    beq .L0813DA62\n"
        "    movs r4, #0x3f\n"
        ".L0813DA54:\n"
        "    bl sub_080C2244\n"
        "    ands r4, r0\n"
        "    cmp r4, #0\n"
        "    bne .L0813DA62\n"
        "    movs r0, #0\n"
        "    b .L0813DA64\n"
        ".L0813DA62:\n"
        "    movs r0, #1\n"
        ".L0813DA64:\n"
        "    pop {r4}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// sub_0813DA6C @ 0x0813DA6C
bool32 sub_0813DA6C(void)
{
    u16 sel = sub_0812DC10();
    s32 money;
    s32 cost;
    s32 kind;
    u32 r;

    if (sel == 0xFE)
        return FALSE;
    if (sel == 0xFF)
        goto cancel;
    money = sub_080C3100();
    cost = sub_08135064(sel, gUnk_0300668C);
    if (money < cost)
    {
        gScriptWaitState = 0;
        gScriptJumpTarget = gUnk_0203DAC8[0];
        return TRUE;
    }
    sub_080C30AC(-cost);
    sub_081350CC(sel, gUnk_0300668C);
    sub_080C84A0();
    gUnk_0203DB34 = 1;
    kind = gUnk_0300668C;
    if (kind == 0)
    {
        if (sub_0813560C() != 0)
        {
            gScriptWaitState = kind;
            return TRUE;
        }
    }
    else
    {
        if (kind == 1)
            r = sub_08135370();
        else if (kind == 2)
            r = sub_08135420();
        else if (kind == 3)
            r = sub_081354B0();
        else
            r = sub_08135540();
        if ((u16)r != 0)
            goto cancel;
    }
    sub_0812DC24();
    return FALSE;
cancel:
    gScriptWaitState = 0;
    return TRUE;
}
