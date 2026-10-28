/* Script VM opcode handlers 0x410 (alt) - 0x425. */

#include "global.h"
#include "scriptops2.h"

// ScriptOpAlt_410 @ 0x08139DDC
void ScriptOpAlt_410(void)
{
    gScriptPc += 5;
}

/* Jumps to the target saved by ScriptOp_3D7 (gUnk_03006840). */
// ScriptOp_411 @ 0x08139DEC
void ScriptOp_411(void)
{
    gScriptPc++;
    gScriptJumpTarget = (u16 *)gUnk_03006840;
}

// ScriptOpAlt_411 @ 0x08139E0C
void ScriptOpAlt_411(void)
{
    gScriptPc++;
}

/* Text speed: operand 3 -> 2 frames per glyph, 0-2 -> 1, n -> n - 2. */
// ScriptOp_421 @ 0x08139E1C
void ScriptOp_421(void)
{
    u16 v = SCRIPT_READ();

    if (v == 3)
        gMsgGlyphDelay = 2;
    else if (v <= 2)
        gMsgGlyphDelay = 1;
    else
        gMsgGlyphDelay = v - 2;
}

// ScriptOpAlt_421 @ 0x08139E6C
void ScriptOpAlt_421(void)
{
    gScriptPc++;
}

/* Damages member (high byte; 0x10 = the hero, 0xFF = refresh only) by low byte percent of
   sub_08134DE0 (max HP). */
// ScriptOp_422 @ 0x08139E7C
#ifdef NONMATCHING
void ScriptOp_422(void)
{
    u32 v = SCRIPT_READ();
    u16 lo = v & 0xFF;
    s16 pct = lo;
    u16 hi = (v >> 8) & 0xFF;
    u16 who = hi;
    u16 hp, d;

    gScriptYield = 1;
    if (hi == 0x10)
    {
        if (Combatant_IsAlive(0) == 1)
        {
            hp = sub_08134DE0(0);
            d = (u16)(hp * lo) / 100;
            Combatant_ChangeHp(0, -d);
        }
    }
    else if (hi == 0xFF)
        Party_FixFormation();
    else if (Combatant_IsAlive(who) == 1)
    {
        hp = sub_08134DE0(who);
        d = (u16)(hp * pct) / 100;
        Combatant_ChangeHp(who, -d);
    }
}
#else
NAKED
void ScriptOp_422(void)
{
    asm_unified(
        "    push {r4, r5, r6, lr}\n"
        "    ldr r2, .L08139ED8\n"
        "    ldrh r0, [r2]\n"
        "    adds r1, r0, #1\n"
        "    strh r1, [r2]\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r1, .L08139EDC\n"
        "    ldr r1, [r1]\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r1\n"
        "    ldrh r5, [r0]\n"
        "    movs r0, #0xff\n"
        "    adds r4, r5, #0\n"
        "    ands r4, r0\n"
        "    adds r6, r4, #0\n"
        "    lsrs r2, r5, #8\n"
        "    ands r2, r0\n"
        "    adds r5, r2, #0\n"
        "    ldr r1, .L08139EE0\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    cmp r2, #0x10\n"
        "    bne .L08139EE4\n"
        "    movs r0, #0\n"
        "    bl Combatant_IsAlive\n"
        "    cmp r0, #1\n"
        "    bne .L08139F1A\n"
        "    movs r0, #0\n"
        "    bl sub_08134DE0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    muls r0, r4, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    movs r1, #0x64\n"
        "    bl __udivsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    rsbs r1, r0, #0\n"
        "    movs r0, #0\n"
        "    bl Combatant_ChangeHp\n"
        "    b .L08139F1A\n"
        ".L08139ED8: .4byte 0x0203DB40 @ EWRAM+0x3DB40\n"
        ".L08139EDC: .4byte 0x03006950 @ IWRAM+0x6950\n"
        ".L08139EE0: .4byte 0x0203DB6E @ EWRAM+0x3DB6E\n"
        ".L08139EE4:\n"
        "    cmp r2, #0xff\n"
        "    bne .L08139EEE\n"
        "    bl Party_FixFormation\n"
        "    b .L08139F1A\n"
        ".L08139EEE:\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_IsAlive\n"
        "    cmp r0, #1\n"
        "    bne .L08139F1A\n"
        "    adds r0, r5, #0\n"
        "    bl sub_08134DE0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    muls r0, r6, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    movs r1, #0x64\n"
        "    bl __udivsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    rsbs r1, r0, #0\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_ChangeHp\n"
        ".L08139F1A:\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif

// ScriptOpAlt_422 @ 0x08139F20
void ScriptOpAlt_422(void)
{
    gScriptPc += 2;
}

/* Jumps unless the moon phase (folded to 0-8 sixteenths) equals the operand. */
// ScriptOp_423 @ 0x08139F30
void ScriptOp_423(void)
{
    u16 want = SCRIPT_READ();
    u16 lo;
    u32 target;
    u16 ph;

    want <<= 4;
    lo = SCRIPT_READ();
    target = SCRIPT_READ();
    target = target << 16 | lo;
    ph = Moon_GetPhase() & 0xF0;
    if (ph > 0x8F)
    {
        ph -= 0x80;
        ph = 0x80 - ph;
    }
    if (ph != want)
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOpAlt_423 @ 0x08139FA0
void ScriptOpAlt_423(void)
{
    gScriptPc += 3;
}

// ScriptOp_424 @ 0x08139FB0
void ScriptOp_424(void)
{
    u32 v = SCRIPT_READ();
    u16 lo = v & 0xFF;
    u16 hi = (v >> 8) & 0xFF;

    gGameState.unk18B5 = hi;
    gGameState.unk18B6 = lo;
    gGameState.moonPhase = Moon_GetPhase();
}

// ScriptOpAlt_424 @ 0x0813A008
void ScriptOpAlt_424(void)
{
    gScriptPc++;
}

// ScriptOp_425 @ 0x0813A018
void ScriptOp_425(void)
{
}

// ScriptOpAlt_425 @ 0x0813A01C
void ScriptOpAlt_425(void)
{
}
