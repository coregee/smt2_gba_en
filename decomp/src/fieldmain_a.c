#include "global.h"
#include "combatant.h"

// sub_080C140C @ 0x080C140C
/* Window 0 shadow registers: WININ/WINOUT-style 0x3C42, window 0x42 = a | b << 8. */
void sub_080C140C(s16 a, s16 b)
{
    u16 v = 16;

    gUnk_03000040 = 0x3C42;
    gUnk_03000042 = a | (b << 8);
    gUnk_03000044 = v;
}

// sub_080C1440 @ 0x080C1440
void sub_080C1440(void)
{
    sub_080C140C(12, 6);
}

// sub_080C1450 @ 0x080C1450
/* Field display setup: DISPCNT, BG0-3 control, blend and scroll shadows. */
void sub_080C1450(void)
{
    REG_DISPCNT = 0x7F00;
    REG_BG0CNT = 0x8004;
    REG_BG1CNT = 0x8209;
    REG_BG2CNT = 0x840A;
    REG_BG3CNT = 0x8607;
    gUnk_03000038 = 0x3F;
    gUnk_03000039 = 0x3F;
    gUnk_0300003A = 0x3F;
    gDispRegs = 0;
    gUnk_03000002 = 0xFFFF;
    gUnk_03000004 = 0;
    gUnk_03000006 = 0;
    gUnk_03000008 = 0;
    gUnk_0300000A = 0;
    gUnk_0300000C = 0;
    gUnk_0300000E = 0;
    sub_080C1440();
}

// sub_080C14FC @ 0x080C14FC
void sub_080C14FC(void)
{
    DmaCopy32(3, gUnknown_081B8370, gUnk_02000000, 0x500);
    Tilemap_OffsetRect(gUnk_02000000, 1, 13, 1, 0, 28, 13);
}

// sub_080C153C @ 0x080C153C
void sub_080C153C(void)
{
    DmaCopy32(3, gUnk_02000000, (void *)0x06002000, 0x500);
}

// sub_080C1560 @ 0x080C1560
/* Main callback: sets up the field screen, then continues with sub_080C1630. */
void sub_080C1560(void)
{
    gUnk_0200AB04 = 0;
    sub_080C1450();
    VBlankTasks_Init();
    DmaFill32(3, 0, (void *)0x06000000, 0x4000);
    Windows_Init();
    sub_080C1328();
    gHudState[0x19] = 0;
    sub_080C1384();
    Font_ResetGlyphSpriteCache(0x180);
    sub_080C14FC();
    sub_080C153C();
    Hud_Init();
    sub_080C6734();
    sub_080AD7F0();
    if (gUnk_03004544 == 0)
    {
        sub_080AE234();
        Field_SetPosition(0, 0);
        gFieldState.unk02 = 0;
        gFieldState.unk04 = 0;
        gUnk_03004514 = 0;
        sub_080B30A0(*(u16 *)&gUnk_03004614);
    }
    SetMainCallback(sub_080C1630);
    REG_IE = 0x2003;
    REG_DISPSTAT = 0x18;
    REG_IME = 1;
}

// sub_080C1630 @ 0x080C1630
void sub_080C1630(void)
{
    u32 mode = gUnk_03004544;

    if (mode <= 1 || mode == 4 || mode == 6)
    {
        Map_LoadGraphicsStep(*(u16 *)&gUnk_03004614, *(u16 *)&gUnk_03004514, &gUnk_03003FF8);
        if (gUnk_03003FF8 == 0)
            SetMainCallback(sub_080C1684);
    }
    else
    {
        SetMainCallback(sub_080C1684);
    }
}

// sub_080C1684 @ 0x080C1684
void sub_080C1684(void)
{
    u32 zero;

    if (gUnk_03004544 == 0)
        gUnk_03004514 = gUnk_03004544;
    sub_080ADFEC(*(u16 *)&gUnk_03004544);
    Task_ClearAll();
    sub_080AE364(*(u16 *)&gUnk_03004544);
    gHudState[0x1A] = 1;
    if (gUnk_03004544 == 4
     && (FieldMap_HasRecordRel(0, 0, 0x12) == 1 || FieldMap_HasRecordRel(0, 0, 0x13) == 1
      || FieldMap_HasRecordRel(0, 0, 0x1E) == 1)
     && Field_CheckCellEvents(1, 1, 0))
    {
        gPaletteTarget[0] = 0;
        Palette_FillWithEffect(3, 0, gPaletteTarget + 0xE0, 0x40, 0x20);
        Palette_FillWithEffect(3, 0, gPaletteTarget + 0xD0, 0x20, 0x20);
    }
    if (gGameState.unkAC0 == 0)
    {
        if (sub_080D0E74() == 1)
            Music_Play(0);
        else
            Music_Play(sub_080AD608(*(u16 *)&gUnk_03004614, *(u16 *)&gUnk_03004514));
    }
    else
    {
        Music_Play(sub_080AD67C(gWorldMap[4]));
    }
    Battle_ResetGlobals();
    if (gUnk_03004544 != 5)
    {
        PalFade_FadeInFromBlack(1);
        if (gUnk_03004614 == 0 && gFieldState.x == 2 && gFieldState.y == 6)
        {
            zero = 0;
            CpuSet(&zero, gUnk_03002B50, 0x05000018);
        }
        SetMainCallback(sub_080C17F0);
    }
    else
    {
        Field_SetState(*(u16 *)&gUnk_030045FC);
        SetMainCallback(FieldMain_Loop);
    }
}

// sub_080C17F0 @ 0x080C17F0
void sub_080C17F0(void)
{
    u32 done = PalFade_AllDone();

    if (done == 1)
    {
        gHudState[0x1A] = 0;
        Field_SetState(*(u16 *)&gUnk_030045FC);
        SetMainCallback(FieldMain_Loop);
        if (gUnk_03004544 == 4 || sub_080D0E74() == 1)
        {
            gUnk_03003FF4 = done;
            Field_CheckCellEvents(1, 2, 0);
            gUnk_03003FF4 = 0;
        }
    }
    FieldMain_Loop();
}

// FieldMain_Loop @ 0x080C1850
/* Field main loop. */
void FieldMain_Loop(void)
{
    gGameState.stockMax = Stock_GetCapacity();
    sub_080E5220();
    Field_UpdateFrame();
    Task_RunAll();
    Hud_Update();
    PlayTime_Tick();
}

// sub_080C1880 @ 0x080C1880
void sub_080C1880(void)
{
    gUnk_0200AB04 = 1;
    sub_080C1450();
    VBlankTasks_Init();
    REG_DISPCNT &= 0xFEFF;
    REG_BG1CNT = 0x209;
    REG_BG2CNT = 0x406;
    REG_BG3CNT = 0x607;
    gUnk_03000002 = 0;
    gUnk_03000040 = 0x3C46;
    gUnk_03000030 = 0x88;
    gUnk_03000031 = 0x68;
    gUnk_03000034 = 0x60;
    gUnk_03000035 = 0x40;
    gUnk_03000038 = 0x3F;
    gUnk_03000032 = 0x39;
    gUnk_03000033 = 10;
    gUnk_03000036 = 0x17;
    gUnk_03000037 = 3;
    gUnk_03000039 = 0x3F;
    gUnk_0300003A = 0x1F;
    DmaFill16(3, 0x3B3, gUnk_02000000, 0x1000);
    DmaSet(3, gUnk_02000000, (void *)0x06000000, 0x84000400);
    Tilemap_CopyRectSkipZero(gUnknown_081B8270, gUnk_02000000, 0, 0, 1, 0, 7, 3);
    DmaSet(3, gUnk_02000000, (void *)0x06001000, 0x84000400);
    Windows_Init();
    sub_080C1328();
    gHudState[0x19] = 0;
    sub_080C1384();
    sub_080C2EFC();
    Font_ResetGlyphSpriteCache(0x100);
    REG_IE = 0x2003;
    REG_DISPSTAT = 0x18;
    REG_IME = 1;
    Task_ClearAll();
    sub_080C7CC8();
    sub_08151EEC(*(u16 *)&gUnk_03003FC4, *(u16 *)&gUnk_03004618, *(u16 *)&gUnk_03004624);
    Music_Play(sub_080AD67C(gWorldMap[4]));
    SetMainCallback(sub_080C1A58);
}

// sub_080C1A58 @ 0x080C1A58
void sub_080C1A58(void)
{
    if (Party_HasActiveHuman() == 0)
    {
        sub_080B9058();
        sub_080C1A9C();
        SetMainCallback(sub_080C1A9C);
    }
    gGameState.stockMax = Stock_GetCapacity();
    sub_080C7CD8();
    sub_0815201C();
    Task_RunAll();
    PlayTime_Tick();
}

// sub_080C1A9C @ 0x080C1A9C
void sub_080C1A9C(void)
{
    sub_080C7CD8();
    Task_RunAll();
    PlayTime_Tick();
}

// sub_080C1AB0 @ 0x080C1AB0
void sub_080C1AB0(void)
{
    u8 state = gGameState.unk18D4;
    u8 phase = Moon_GetPhase() & 0xF0;

    if (state == 1)
    {
        if (phase != 0)
            gGameState.unk18D4 = 2;
    }
    else if (state == 2 && phase == 0)
    {
        sub_080C245C(0xFF);
        gGameState.unk18D4 = phase;
    }
}

// sub_080C1AF4 @ 0x080C1AF4
void sub_080C1AF4(void)
{
    Moon_PhaseChanged();
    if (gGameState.unkAC0 == 1)
    {
        u32 old = Moon_GetPhase() & 0xFF;

        sub_080C1AB0();
        if (!(Moon_GetPhase() & 0xF0))
        {
            BattleFlags_Mask(~0x100);
        }
        else if (old == 0x80)
        {
            BattleFlags_Mask(~0x40);
            BattleFlags_Mask(~0x20);
        }
    }
}

// sub_080C1B50 @ 0x080C1B50
s32 sub_080C1B50(void)
{
    if (gGameState.members[1].unkE & 0x8000)
        return 1;
    return 2;
}

// sub_080C1B74 @ 0x080C1B74
#ifdef NONMATCHING
u32 sub_080C1B74(u16 *a, u16 *b)
{
    u32 r = 0;

    if ((u8)(Moon_GetPhase() & 0xF0) == 0x80)
    {
        if (Flag_Test(0xCF))
        {
            struct Combatant *c;
            u8 *p;
            u32 base;

            if (Flag_Test(0xE2))
            {
                *a = sub_080C1CAC(0);
                r = 1;
            }
            if (Flag_Test(0xE3))
            {
                *b = sub_080C1CAC(sub_080C1B50());
                r |= 2;
            }
            base = 0x8000;
            c = Battle_GetCombatant(base);
            p = c->extra.v;
            *p++ = 0;
            *p++ = 0;
            *p++ = 0;
            *p++ = 0;
            *p++ = 0;
            *p++ = 0;
            Combatant_RecalcStats(c->id);
            c = Battle_GetCombatant(sub_080C1B50() + base);
            p = c->extra.v;
            *p++ = 0;
            *p++ = 0;
            *p++ = 0;
            *p++ = 0;
            *p++ = 0;
            *p++ = 0;
            Combatant_RecalcStats(c->id);
            Flag_Clear(0xE2);
            Flag_Clear(0xE3);
            Flag_Clear(0xCF);
            Hud_InvalidateGauges();
        }
    }
    else if (Flag_Test(0xE2) || Flag_Test(0xE3))
    {
        Flag_Set(0xCF);
    }
    if (gGameState.unk18B5 != 0xFF)
    {
        u32 phase = Moon_GetPhase() & 0xF0;

        if (phase != gGameState.unk18B4)
        {
            gGameState.unk18B4 = phase;
            if (--gGameState.unk18B5 == 0)
                Flag_Set(gUnknown_081A6264[gGameState.unk18B6]);
        }
    }
    return r;
}
#else
NAKED
u32 sub_080C1B74(u16 *a, u16 *b)
{
    asm_unified(
        ".L080C1B74:\n"
        "    push {r4, r5, r6, lr}\n"
        "    adds r4, r0, #0\n"
        "    adds r5, r1, #0\n"
        "    movs r6, #0\n"
        "    bl Moon_GetPhase\n"
        "    movs r1, #0xf0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0x80\n"
        "    bne .L080C1C34\n"
        "    movs r0, #0xcf\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    beq .L080C1C4E\n"
        "    movs r0, #0xe2\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    beq .L080C1BA6\n"
        "    movs r0, #0\n"
        "    bl sub_080C1CAC\n"
        "    strh r0, [r4]\n"
        "    movs r6, #1\n"
        ".L080C1BA6:\n"
        "    movs r0, #0xe3\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    beq .L080C1BC2\n"
        "    bl sub_080C1B50\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl sub_080C1CAC\n"
        "    strh r0, [r5]\n"
        "    movs r0, #2\n"
        "    orrs r6, r0\n"
        ".L080C1BC2:\n"
        "    movs r5, #0x80\n"
        "    lsls r5, r5, #8\n"
        "    adds r0, r5, #0\n"
        "    bl Battle_GetCombatant\n"
        "    adds r1, r0, #0\n"
        "    adds r0, #0x38\n"
        "    movs r4, #0\n"
        "    strb r4, [r0]\n"
        "    adds r0, #1\n"
        "    strb r4, [r0]\n"
        "    adds r0, #1\n"
        "    strb r4, [r0]\n"
        "    adds r0, #1\n"
        "    strb r4, [r0]\n"
        "    adds r0, #1\n"
        "    strb r4, [r0]\n"
        "    adds r0, #1\n"
        "    strb r4, [r0]\n"
        "    ldrb r0, [r1, #0xc]\n"
        "    bl Combatant_RecalcStats\n"
        "    bl sub_080C1B50\n"
        "    adds r0, r0, r5\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    adds r1, r0, #0\n"
        "    adds r0, #0x38\n"
        "    strb r4, [r0]\n"
        "    adds r0, #1\n"
        "    strb r4, [r0]\n"
        "    adds r0, #1\n"
        "    strb r4, [r0]\n"
        "    adds r0, #1\n"
        "    strb r4, [r0]\n"
        "    adds r0, #1\n"
        "    strb r4, [r0]\n"
        "    adds r0, #1\n"
        "    strb r4, [r0]\n"
        "    ldrb r0, [r1, #0xc]\n"
        "    bl Combatant_RecalcStats\n"
        "    movs r0, #0xe2\n"
        "    bl Flag_Clear\n"
        "    movs r0, #0xe3\n"
        "    bl Flag_Clear\n"
        "    movs r0, #0xcf\n"
        "    bl Flag_Clear\n"
        "    bl Hud_InvalidateGauges\n"
        "    b .L080C1C4E\n"
        ".L080C1C34:\n"
        "    movs r0, #0xe2\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L080C1C48\n"
        "    movs r0, #0xe3\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    beq .L080C1C4E\n"
        ".L080C1C48:\n"
        "    movs r0, #0xcf\n"
        "    bl Flag_Set\n"
        ".L080C1C4E:\n"
        "    ldr r5, .L080C1C98\n"
        "    ldr r0, .L080C1C9C\n"
        "    adds r4, r5, r0\n"
        "    ldrb r0, [r4]\n"
        "    cmp r0, #0xff\n"
        "    beq .L080C1C90\n"
        "    bl Moon_GetPhase\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #0xf0\n"
        "    ands r1, r0\n"
        "    ldr r2, .L080C1CA0\n"
        "    adds r0, r5, r2\n"
        "    ldrb r2, [r0]\n"
        "    cmp r1, r2\n"
        "    beq .L080C1C90\n"
        "    strb r1, [r0]\n"
        "    ldrb r0, [r4]\n"
        "    subs r0, #1\n"
        "    strb r0, [r4]\n"
        "    lsls r0, r0, #0x18\n"
        "    cmp r0, #0\n"
        "    bne .L080C1C90\n"
        "    ldr r1, .L080C1CA4\n"
        "    adds r0, r5, r1\n"
        "    ldrb r0, [r0]\n"
        "    ldr r1, .L080C1CA8\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r1\n"
        "    ldrh r1, [r0]\n"
        "    adds r0, r1, #0\n"
        "    bl Flag_Set\n"
        ".L080C1C90:\n"
        "    adds r0, r6, #0\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        ".L080C1C98: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080C1C9C: .4byte 0x000018B5\n"
        ".L080C1CA0: .4byte 0x000018B4\n"
        ".L080C1CA4: .4byte 0x000018B6\n"
        ".L080C1CA8: .4byte gUnknown_081A6264\n"
    );
}
#endif

// sub_080C1CAC @ 0x080C1CAC
u16 sub_080C1CAC(u16 who)
{
    struct Combatant *c = Battle_GetCombatant(who + 0x8000);
    u16 r = Random_Byte() & 7;

    if (r != 0)
    {
        r &= 3;
        r = gUnknown_081A626A[r];
        Combatant_SetStatus(c->id, r);
    }
    else
    {
        r = 4;
        Combatant_SetStatus(c->id, 4);
    }
    sub_080C84A0();
    return r;
}
