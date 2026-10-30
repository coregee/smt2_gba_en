/* Script VM opcode handlers 0x32A-0x33A and the shop/party list helpers after them. */

#include "global.h"
#include "bflow.h"

/* Appends one entry to the 64-entry glyph queue gMsgGlyphQueue (count clamped to 63). */
#define QUEUE_GLYPH(glyph, x, y)                \
{                                               \
    u16 c_ = gMsgGlyphCount;                     \
    u16 k_ = c_ * 4;                            \
    gMsgGlyphQueue[k_++] = (glyph);              \
    gMsgGlyphQueue[k_++] = (x);                  \
    gMsgGlyphQueue[k_++] = (y);                  \
    gMsgGlyphQueue[k_] = 0;                      \
    gMsgGlyphCount = c_ + 1;                     \
    if (gMsgGlyphCount > 0x3F)                   \
        gMsgGlyphCount = 0x3F;                   \
}

// ScriptOp_32A @ 0x081332BC
void ScriptOp_32A(void)
{
    gUnk_0203DB28[1] = (u8)SCRIPT_READ();
    gUnk_03006970[1] = 1;
    gUnk_0203DB68 = 1;
}

// ScriptOp_32B @ 0x081332F4
void ScriptOp_32B(void)
{
    u16 i = SCRIPT_READ();

    if (i == 0xFF)
    {
        sub_080C3818(1);
        return;
    }
    i &= 0xF;
    if (i > 1)
    {
        CharObj_End(gUnk_030068F0[i], 0);
        gUnk_030068F0[i] = 0;
    }
    else if (gUnk_030068F0[i] != 0)
    {
        CharObj_End(gUnk_030068F0[i], 0);
        gUnk_030068F0[i] = 0;
    }
    else if (gUnk_030069C0[i] != 0)
    {
        sub_080E9044(gUnk_030069C0[i], i);
        gUnk_030069C0[i] = 0;
    }
}

// sub_0813337C @ 0x0813337C
void sub_0813337C(void)
{
    gScriptWaitState = 0x13;
}

// sub_08133388 @ 0x08133388
void sub_08133388(struct Task *task)
{
    task->result = 0;
}

// sub_08133390 @ 0x08133390
void sub_08133390(struct Task *task)
{
    task->result = 1;
}

// sub_08133398 @ 0x08133398
void sub_08133398(void)
{
}

// sub_0813339C @ 0x0813339C
void sub_0813339C(struct Task *task)
{
    task->data.raw[1] = 200;
    task->result = 0;
    gScriptWaitState = 0x13;
}

/* Waits until the timer set by sub_0813339C has run out, then for an A press. */
// sub_081333B4 @ 0x081333B4
void sub_081333B4(struct Task *task)
{
    u8 *timer = &task->data.raw[1];

    if (*timer != 0 && --*timer != 0)
        return;
    if (gNewKeys & 1)
        task->result = 1;
}

/* Jumps when Money_Get() < operand. */
// ScriptOp_336 @ 0x081333E4
void ScriptOp_336(void)
{
    u16 n = SCRIPT_READ();
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ() << 16 | lo;

    if (Money_Get() < n)
        gScriptJumpTarget = (u16 *)target;
}

// ScriptOp_337 @ 0x08133434
void ScriptOp_337(void)
{
    Magnetite_Add(SCRIPT_READ());
}

// ScriptOp_338 @ 0x0813345C
void ScriptOp_338(void)
{
    u16 i = SCRIPT_READ();

    gUnk_030065F8 = 1;
    gScriptWaitState = 0x12;
    Task_Create(gUnknown_08790330[i], 0xFFFF);
    gScriptYield = 1;
}

// ScriptOp_32C @ 0x081334B4
void ScriptOp_32C(void)
{
    u16 neg = SCRIPT_READ();
    u16 v = SCRIPT_READ();

    gUnk_0203DB62 = v;
    if (neg)
        Money_Add(-v);
    else
        Money_Add(v);
}

/* Jumps when Random_Byte() < 0x80 >> operand. */
// ScriptOp_32D @ 0x08133500
void ScriptOp_32D(void)
{
    u16 n = 0x80 >> SCRIPT_READ();
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ() << 16 | lo;

    if (Random_Byte() < n)
        gScriptJumpTarget = (u16 *)target;
}

/* Opens the shop's sell list: collects every held item (ids 0-255) with its price. */
// ScriptOp_333 @ 0x0813355C
void ScriptOp_333(void)
{
    u16 lo;
    u32 target;
    u16 i, n;

    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    gUnk_0203DAC8[1] = (u16 *)target;
    lo = SCRIPT_READ();
    target = SCRIPT_READ() << 16 | lo;
    gUnk_0203DAC8[2] = (u16 *)target;
    for (i = 0; i < 256; i++)
    {
        gShopItemIds[i] |= 0xFFFF;
        gShopItemPrices[i] = -1;
    }
    n = 0;
    for (i = 0; i < 256; i++)
    {
        if (Inventory_GetCount(i))
        {
            gShopItemIds[n] = i;
            gShopItemPrices[n] = sub_080C4C7C(i);
            n++;
        }
    }
    gUnk_03006688 = n;
    gScriptWaitState = 0x28;
    for (i = 0; i < 15; i++)
        gUnk_03006820[i] = gMsgGlyphQueue[i * 4];
    gUnk_03006940 = 0;
    gUnk_0300696C = 0;
    gUnk_030065E4 = 0;
    Shop_InitItemList(0, 0);
    gUnk_030068A4 = sub_080D3400(1, 0, gShopItemIds[0]);
    Task_Create(gUnknown_0878FD58, 0xFFFF);
    gScriptYield = 1;
}

// ScriptOp_334 @ 0x081336A4
void ScriptOp_334(void)
{
    gUnk_03006914 = gScriptBase[gScriptPc];
    if (gUnknown_08790130[gUnk_03006914] == 1)
        gScriptJumpTarget = (u16 *)gUnknown_0807DED2;
    else if (gUnknown_08790130[gUnk_03006914] == 2)
        gScriptJumpTarget = (u16 *)gUnknown_0807E088;
    else if (gUnknown_08790130[gUnk_03006914] == 3)
        gScriptJumpTarget = (u16 *)gUnknown_0807D984;
    else if (gUnknown_08790130[gUnk_03006914] == 4)
        gScriptJumpTarget = (u16 *)gUnknown_0807D988;
    else
        gScriptJumpTarget = (u16 *)gUnknown_0807D984;
}

/* Queues n glyphs of gScriptSubstBuf at (x, y), 13 pixels apart, in gMsgGlyphList2.
   The count is not checked against the 25-entry queue. */
// sub_08133724 @ 0x08133724
void sub_08133724(u16 x, u16 y, u16 pal, u16 n)
{
    u16 i;

    for (i = 0; i < n; i++)
    {
        gMsgGlyphList2[gMsgGlyphList2Count * 4] = gScriptSubstBuf[i];
        gMsgGlyphList2[gMsgGlyphList2Count * 4 + 1] = x;
        gMsgGlyphList2[gMsgGlyphList2Count * 4 + 2] = y;
        gMsgGlyphList2[gMsgGlyphList2Count * 4 + 3] = pal;
        gMsgGlyphList2Count++;
        x += 13;
    }
}

/* Same for the 64-entry queue gMsgGlyphQueue; past entry 63 the last entry is overwritten. */
// MsgGlyphQueue_PushSubst @ 0x081337B4
#ifdef NONMATCHING
void MsgGlyphQueue_PushSubst(u16 x, u16 y, u16 pal, u16 n)
{
    u16 i;
    u16 c, k;

    for (i = 0; i < n; i++)
    {
        c = gMsgGlyphCount;
        k = c * 4;
        gMsgGlyphQueue[k++] = gScriptSubstBuf[i];
        gMsgGlyphQueue[k++] = x;
        gMsgGlyphQueue[k++] = y;
        gMsgGlyphQueue[k] = pal;
        if (gMsgGlyphCount < 0x3F)
            gMsgGlyphCount = c + 1;
        x += 13;
    }
}
#else
NAKED
void MsgGlyphQueue_PushSubst(u16 x, u16 y, u16 pal, u16 n)
{
    asm_unified(
        ".L081337B4:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    mov sb, r1\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    mov r8, r2\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r7, r3, #0x10\n"
        "    movs r4, #0\n"
        "    cmp r4, r7\n"
        "    bhs .L0813383A\n"
        "    ldr r0, .L08133848\n"
        "    mov ip, r0\n"
        "    ldr r5, .L0813384C\n"
        "    ldr r1, .L08133850\n"
        "    mov sl, r1\n"
        ".L081337E2:\n"
        "    mov r2, ip\n"
        "    ldrh r3, [r2]\n"
        "    lsls r1, r3, #0x12\n"
        "    lsrs r1, r1, #0x10\n"
        "    movs r2, #1\n"
        "    orrs r2, r1\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r5\n"
        "    lsls r0, r4, #1\n"
        "    add r0, sl\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r1]\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsls r2, r2, #1\n"
        "    adds r2, r2, r5\n"
        "    strh r6, [r2]\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #9\n"
        "    adds r1, r0, r2\n"
        "    lsrs r0, r0, #0xf\n"
        "    adds r0, r0, r5\n"
        "    mov r2, sb\n"
        "    strh r2, [r0]\n"
        "    lsrs r1, r1, #0xf\n"
        "    adds r1, r1, r5\n"
        "    mov r0, r8\n"
        "    strh r0, [r1]\n"
        "    lsls r0, r3, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #0x3e\n"
        "    bhi .L08133828\n"
        "    adds r0, r3, #1\n"
        "    mov r1, ip\n"
        "    strh r0, [r1]\n"
        ".L08133828:\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0xd\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, r7\n"
        "    blo .L081337E2\n"
        ".L0813383A:\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L08133848: .4byte 0x0203DB3E @ EWRAM+0x3DB3E\n"
        ".L0813384C: .4byte 0x0203D800 @ EWRAM+0x3D800\n"
        ".L08133850: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
    );
}
#endif

/* Queues the names of party members base..base+2 (glyph queue gMsgGlyphQueue, rows from
   gUnknown_0879038A). Names are cut to 8 glyphs and ended with 0x318. mode 1 skips members
   whose flags have 0xA000 set; others are counted in gUnk_030069D0. */

// Script_QueuePartyNames @ 0x08133854
#ifdef NONMATCHING
void Script_QueuePartyNames(u16 base, u16 mode)
{
    struct PartyMember *m;
    u16 slot = 0;
    u16 row = 0;
    u16 pal;
    s16 j;
    s32 idx;

    gMsgGlyphList2Count = 0;
    for (j = 0; j < 100; j++)
        gMsgGlyphList2[j] = 0;
    gUnk_030069D0 = 0;
    idx = base + slot;
    goto check;
process:
    if (mode == 1)
    {
        if (gGameState[idx].flags & 0xA000)
        {
            if (++slot > 2)
                return;
            goto load;
        }
    }
    else
    {
        gUnk_030069D0++;
    }
    gUnk_030069D8[row] = idx;
    if (gGameState[idx].flags & 0xA000)
    {
        pal = 4;
        gUnk_030069D8[row] = idx | 0xF0;
    }
    else
    {
        pal = 0;
    }
    for (j = 0; j < 16; j++)
        gScriptSubstBuf[j] = 0;
    Combatant_DecodeName((u8 *)&gGameState[idx], gScriptSubstBuf);
    gScriptSubstBuf[8] = 0;
    for (j = 14; j >= 0; j--)
    {
        if (gScriptSubstBuf[j] != 0
         && (gScriptSubstBuf[j + 1] == 0 || gScriptSubstBuf[j + 1] == 0x318))
        {
            gScriptSubstBuf[j + 1] = 0x318;
            break;
        }
    }
    MsgGlyphQueue_PushSubst(0x27, gUnknown_0879038A[row], pal, j + 1);
    row++;
    /* checks slot 3 too after a listed member (the skip path stops after slot 2) */
    if (++slot > 3)
        return;
load:
    idx = base + slot;
check:
    if (gGameState[idx].unkE != 0)
        goto process;
    if (++slot <= 2)
        goto load;
}
#else
NAKED
void Script_QueuePartyNames(u16 base, u16 mode)
{
    asm_unified(
        ".L08133854:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #4\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sl, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp]\n"
        "    movs r5, #0\n"
        "    mov r8, r5\n"
        "    ldr r0, .L081338A8\n"
        "    strh r5, [r0]\n"
        "    movs r3, #0\n"
        "    ldr r6, .L081338AC\n"
        "    ldr r0, .L081338B0\n"
        "    mov ip, r0\n"
        "    ldr r4, .L081338B4\n"
        "    movs r2, #0\n"
        ".L08133880:\n"
        "    lsls r1, r3, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r0, r4\n"
        "    strh r2, [r0]\n"
        "    adds r1, #1\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r3, r1, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    cmp r1, #0x63\n"
        "    ble .L08133880\n"
        "    movs r0, #0\n"
        "    strh r0, [r6]\n"
        "    mov r0, sl\n"
        "    adds r1, r5, r0\n"
        "    lsls r0, r1, #7\n"
        "    add r0, ip\n"
        "    ldrh r0, [r0, #0xe]\n"
        "    adds r4, r1, #0\n"
        "    b .L081339C0\n"
        ".L081338A8: .4byte 0x0300669C @ IWRAM+0x669C\n"
        ".L081338AC: .4byte 0x030069D0 @ IWRAM+0x69D0\n"
        ".L081338B0: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L081338B4: .4byte 0x0203DA00 @ EWRAM+0x3DA00\n"
        ".L081338B8:\n"
        "    ldr r1, [sp]\n"
        "    cmp r1, #1\n"
        "    bne .L081338DA\n"
        "    lsls r0, r4, #7\n"
        "    add r0, ip\n"
        "    ldrh r1, [r0, #0x10]\n"
        "    movs r0, #0xa0\n"
        "    lsls r0, r0, #8\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L081338E2\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #2\n"
        "    bhi .L081339D0\n"
        "    b .L081339B0\n"
        ".L081338DA:\n"
        "    ldr r1, .L08133910\n"
        "    ldrh r0, [r1]\n"
        "    adds r0, #1\n"
        "    strh r0, [r1]\n"
        ".L081338E2:\n"
        "    ldr r0, .L08133914\n"
        "    mov r1, r8\n"
        "    lsls r2, r1, #1\n"
        "    adds r3, r2, r0\n"
        "    movs r6, #0\n"
        "    strh r4, [r3]\n"
        "    lsls r0, r4, #7\n"
        "    add r0, ip\n"
        "    ldrh r1, [r0, #0x10]\n"
        "    movs r0, #0xa0\n"
        "    lsls r0, r0, #8\n"
        "    ands r0, r1\n"
        "    adds r7, r2, #0\n"
        "    cmp r0, #0\n"
        "    beq .L08133918\n"
        "    movs r0, #4\n"
        "    mov sb, r0\n"
        "    movs r1, #0xf0\n"
        "    adds r0, r4, #0\n"
        "    orrs r0, r1\n"
        "    strh r0, [r3]\n"
        "    b .L0813391C\n"
        "    .byte 0x00, 0x00\n"
        ".L08133910: .4byte 0x030069D0 @ IWRAM+0x69D0\n"
        ".L08133914: .4byte 0x030069D8 @ IWRAM+0x69D8\n"
        ".L08133918:\n"
        "    movs r1, #0\n"
        "    mov sb, r1\n"
        ".L0813391C:\n"
        "    movs r3, #0\n"
        "    adds r6, r5, #1\n"
        "    movs r0, #1\n"
        "    add r8, r0\n"
        "    ldr r5, .L08133978\n"
        "    movs r2, #0\n"
        ".L08133928:\n"
        "    lsls r0, r3, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    lsls r1, r0, #1\n"
        "    adds r1, r1, r5\n"
        "    strh r2, [r1]\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #0xf\n"
        "    ble .L08133928\n"
        "    lsls r0, r4, #7\n"
        "    add r0, ip\n"
        "    ldr r4, .L08133978\n"
        "    adds r1, r4, #0\n"
        "    bl Combatant_DecodeName\n"
        "    movs r0, #0\n"
        "    strh r0, [r4, #0x10]\n"
        "    movs r3, #0xe\n"
        "    movs r2, #0xc6\n"
        "    lsls r2, r2, #2\n"
        ".L08133954:\n"
        "    lsls r0, r3, #0x10\n"
        "    asrs r1, r0, #0x10\n"
        "    lsls r0, r1, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    beq .L0813397C\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r1, [r0]\n"
        "    cmp r1, #0\n"
        "    beq .L08133972\n"
        "    cmp r1, r2\n"
        "    bne .L0813397C\n"
        ".L08133972:\n"
        "    strh r2, [r0]\n"
        "    b .L08133988\n"
        "    .byte 0x00, 0x00\n"
        ".L08133978: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L0813397C:\n"
        "    lsls r0, r3, #0x10\n"
        "    ldr r1, .L081339E0\n"
        "    adds r0, r0, r1\n"
        "    lsrs r3, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bge .L08133954\n"
        ".L08133988:\n"
        "    ldr r0, .L081339E4\n"
        "    adds r0, r7, r0\n"
        "    ldrh r1, [r0]\n"
        "    lsls r3, r3, #0x10\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #9\n"
        "    adds r3, r3, r0\n"
        "    lsrs r3, r3, #0x10\n"
        "    movs r0, #0x27\n"
        "    mov r2, sb\n"
        "    bl MsgGlyphQueue_PushSubst\n"
        "    lsls r0, r6, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    mov r1, r8\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        "    cmp r5, #3\n"
        "    bhi .L081339D0\n"
        ".L081339B0:\n"
        "    ldr r1, .L081339E8\n"
        "    mov r0, sl\n"
        "    adds r2, r5, r0\n"
        "    lsls r0, r2, #7\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0, #0xe]\n"
        "    mov ip, r1\n"
        "    adds r4, r2, #0\n"
        ".L081339C0:\n"
        "    cmp r0, #0\n"
        "    beq .L081339C6\n"
        "    b .L081338B8\n"
        ".L081339C6:\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    cmp r5, #2\n"
        "    bls .L081339B0\n"
        ".L081339D0:\n"
        "    add sp, #4\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L081339E0: .4byte 0xFFFF0000\n"
        ".L081339E4: .4byte gUnknown_0879038A\n"
        ".L081339E8: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
    );
}
#endif

// ScriptOp_33A @ 0x081339EC
void ScriptOp_33A(void)
{
    u16 mode = SCRIPT_READ();
    u16 lo = SCRIPT_READ();
    u32 target = SCRIPT_READ() << 16 | lo;

    gUnk_0203DAC8[0] = (u16 *)target;
    Script_QueuePartyNames(0, mode);
    gScriptWaitState = 0x1F;
    Task_Create(gUnknown_0878FCD0, 0xFFFF);
    gScriptYield = 1;
}

// sub_08133A60 @ 0x08133A60
u16 sub_08133A60(u16 id)
{
    if (id >= 0xD0)
        return 0xFFFF;
    return sub_080D2268(id);
}

/* Queues the 8 glyphs of gScriptSubstBuf as list row `row` (entries row*8.. of gMsgGlyphList2). */
// Shop_QueueNameRow @ 0x08133A80
void Shop_QueueNameRow(u16 row, u16 pal)
{
    u16 x = 0x27;
    u16 k = row * 32;
    u16 i;

    for (i = 0; i < 8; i++)
    {
        gMsgGlyphList2[k++] = gScriptSubstBuf[i];
        gMsgGlyphList2[k++] = x;
        gMsgGlyphList2[k++] = gUnknown_0879038A[row];
        gMsgGlyphList2[k++] = pal;
        x += 13;
    }
}

/* Builds the three visible rows of the shop list starting at item `first`: names (8 glyphs
   each, gMsgGlyphList2 rows), prices, icons and the grey-out palette (4 = cannot buy/sell).
   mode != 0 also overwrites the glyphs of the first 13 entries of gMsgGlyphQueue with a fixed
   string (glyph ids hard-coded in this function); mode 0 restores 15 saved glyphs. */
// Shop_InitItemList @ 0x08133B18
void Shop_InitItemList(u16 first, u16 mode)
{
    u32 money = Money_Get();
    u16 *name;
    u16 item, row, tile, pal;
    s32 ok;
    u32 price, sum;
    u16 i, j;

    Font_ResetGlyphSpriteCache(0x180);
    if (mode != 0)
    {
        gMsgGlyphQueue[0 * 4] = 0xBD9;
        gMsgGlyphQueue[1 * 4] = 0xC80;
        gMsgGlyphQueue[2 * 4] = 0xCD3;
        gMsgGlyphQueue[3 * 4] = 0x149;
        gMsgGlyphQueue[4 * 4] = 0x17B;
        gMsgGlyphQueue[5 * 4] = 0x17D;
        gMsgGlyphQueue[6 * 4] = 0x19F;
        gMsgGlyphQueue[7 * 4] = 0x1BA;
        gMsgGlyphQueue[8 * 4] = 0x149;
        gMsgGlyphQueue[9 * 4] = 0xAA0;
        gMsgGlyphQueue[10 * 4] = 0x9F6;
        gMsgGlyphQueue[11 * 4] = 0xB67;
        gMsgGlyphQueue[12 * 4] = 0x70;
        item = gShopItemIds[first + gUnk_0300696C];
        MsgWindow_DrawItemCount(item);
    }
    else
    {
        for (i = 0; i < 15; i++)
            gMsgGlyphQueue[i * 4] = gUnk_03006820[i];
    }
    pal = 0;
    gMsgGlyphList2Count = 0x18;
    gUnk_0300699C = 1;
    if (first == 0)
    {
        gUnk_03006848 = 0;
        if (gUnk_03006688 <= 3)
            gUnk_03006680 = 0;
        else
            gUnk_03006680 = 1;
    }
    else if (first == gUnk_03006688 - 3)
    {
        gUnk_03006848 = 1;
        gUnk_03006680 = 0;
    }
    else
    {
        gUnk_03006848 = 1;
        gUnk_03006680 = 1;
    }
    for (i = 0x20; i < 100; i++)
        gMsgGlyphList2[i] = 0;
    for (i = first; i < first + 3; i++)
    {
        item = gShopItemIds[i];
        price = gShopItemPrices[i];
        if (item == 0xFFFF)
            break;
        if (gScriptWaitState == 0x22 || gScriptWaitState == 0x25)
        {
            if (money < price)
            {
                pal = 4;
            }
            else
            {
                j = Inventory_GetCount(item);
                j += Party_CountEquipped(0xFF, item);
                pal = 4;
                if (j <= 98)
                {
                    pal = 0;
                    if (item < 0xD0)
                    {
                        ok = Equip_CanEquip(gUnk_03006898, item);
                        pal = 4;
                        if (ok)
                            pal = 0;
                    }
                }
            }
        }
        else if (gScriptWaitState == 0x28 || gScriptWaitState == 0x2A)
        {
            sum = money + gShopItemPrices[i];
            if (sum > 999999)
                pal = 4;
            else
                pal = 0;
        }
        if (item >= 0xD0)
            name = (u16 *)(Action_GetRecord(item) + 0xC);
        else if (item >= 0x80)
            name = (u16 *)(Equipment_GetRecord36_MidRange(item) + 0x14);
        else
            name = (u16 *)(Item_GetRecord(item) + 0x14);
        for (j = 0; j < 8; j++)
            gScriptSubstBuf[j] = *name++;
        row = i - first;
        Shop_QueueNameRow(row, pal);
        gUnk_03006620[row].unk0 = 1;
        gUnk_03006620[row].price = gShopItemPrices[i];
        gUnk_03006620[row].unk8 = 0x80;
        gUnk_03006620[row].y = gUnknown_0878FC64[row];
        gUnk_03006620[row].palette = pal;
        tile = sub_08133A60(item);
        if (tile != 0xFFFF)
        {
            gUnk_03006920[row].tile = tile;
            gUnk_03006920[row].visible = 1;
            gUnk_03006920[row].flag = 0;
        }
        else
        {
            gUnk_03006920[row].visible = 0;
        }
        if (gScriptWaitState == 0x22 || gScriptWaitState == 0x25)
        {
            if (Party_CountEquipped(gUnk_03006898, item))
                gUnk_03006920[row].flag = 1;
        }
    }
}

/* Like MsgGlyphQueue_PushSubst, but the queue count is clamped to 63 after the increment. */

// MsgGlyphQueue_PushSubstClamped @ 0x08133E70
void MsgGlyphQueue_PushSubstClamped(u16 x, u16 y, u16 pal, u16 n)
{
    u16 i;
    u16 c, k;

    for (i = 0; i < n; i++)
    {
        c = gMsgGlyphCount;
        k = c * 4;
        gMsgGlyphQueue[k++] = gScriptSubstBuf[i];
        gMsgGlyphQueue[k++] = x;
        gMsgGlyphQueue[k++] = y;
        gMsgGlyphQueue[k] = pal;
        gMsgGlyphCount = c + 1;
        if (gMsgGlyphCount > 0x3F)
            gMsgGlyphCount = 0x3F;
        x += 13;
    }
}

/* Item list with held counts: up to 3 (4 when gUnk_03006844 & 0xF is 0) rows from the id
   list gUnk_0203DB88, starting at `first`. Each row is the 8-glyph name, glyph 0x115 at
   x 0x9A and the count in at most two digits (counts above 99 would index past the digit
   glyphs). */
// sub_08133F14 @ 0x08133F14
#ifdef NONMATCHING
void sub_08133F14(u16 first)
{
    u16 kind = gUnk_03006844 & 0xF;
    u16 *name;
    u16 id, y, n, i, j;
    u8 count;

    gMsgGlyphCount = 0;
    gTextColumn = 0;
    gTextLine = 0;
    gUnk_0203DB4A = 0;
    Font_ResetGlyphSpriteCache(0x180);
    gUnk_03006678[0] = 0;
    if (kind == 1)
        MsgWindow_RestoreGlyphs();
    if (first == 0)
    {
        gUnk_03006848 = 0;
        gUnk_03006680 = 1;
    }
    else if (first == kind + 8)
    {
        gUnk_03006848 = 1;
        gUnk_03006680 = 0;
    }
    else
    {
        gUnk_03006848 = 1;
        gUnk_03006680 = 1;
    }
    n = 3;
    if (kind == 0)
        n = 4;
    for (i = first; i < first + n; i++)
    {
        id = gUnk_0203DB88[i];
        if (id == 0xFFFF)
            break;
        name = (u16 *)(Action_GetRecord(id) + 0xC);
        for (j = 0; j < 16; j++)
            gScriptSubstBuf[j] = 0;
        for (j = 0; j < 8; j++)
            gScriptSubstBuf[j] = *name++;
        y = gUnknown_08790390[i - first + kind];
        MsgGlyphQueue_PushSubstClamped(0x27, y, 0, 8);
        QUEUE_GLYPH(0x115, 0x9A, y);
        count = Inventory_GetCount(gUnk_0203DB88[i]);
        if (count > 9)
        {
            QUEUE_GLYPH(gScriptDigitGlyphs[count / 10], 0xA7, y);
            QUEUE_GLYPH(gScriptDigitGlyphs[count % 10], 0xB4, y);
        }
        else
        {
            QUEUE_GLYPH(gScriptDigitGlyphs[count], 0xB4, y);
        }
        if (gUnk_030068D8 == id)
        {
            gUnk_03006678[0] = 1;
            gUnk_03006678[1] = gUnknown_08790390[i - first + kind];
        }
    }
}
#else
NAKED
void sub_08133F14(u16 first)
{
    asm_unified(
        ".L08133F14:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x1c\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp]\n"
        "    ldr r0, .L08133F6C\n"
        "    ldrh r0, [r0]\n"
        "    movs r1, #0xf\n"
        "    ands r1, r0\n"
        "    str r1, [sp, #8]\n"
        "    ldr r0, .L08133F70\n"
        "    movs r1, #0\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L08133F74\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L08133F78\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L08133F7C\n"
        "    strh r1, [r0]\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #1\n"
        "    bl Font_ResetGlyphSpriteCache\n"
        "    ldr r0, .L08133F80\n"
        "    movs r4, #0\n"
        "    strh r4, [r0]\n"
        "    ldr r2, [sp, #8]\n"
        "    cmp r2, #1\n"
        "    bne .L08133F5A\n"
        "    bl MsgWindow_RestoreGlyphs\n"
        ".L08133F5A:\n"
        "    ldr r3, [sp]\n"
        "    cmp r3, #0\n"
        "    bne .L08133F8C\n"
        "    ldr r0, .L08133F84\n"
        "    strh r3, [r0]\n"
        "    ldr r1, .L08133F88\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    b .L08133FB6\n"
        ".L08133F6C: .4byte 0x03006844 @ IWRAM+0x6844\n"
        ".L08133F70: .4byte 0x0203DB3E @ EWRAM+0x3DB3E\n"
        ".L08133F74: .4byte 0x0203DB38 @ EWRAM+0x3DB38\n"
        ".L08133F78: .4byte 0x0203DB3A @ EWRAM+0x3DB3A\n"
        ".L08133F7C: .4byte 0x0203DB4A @ EWRAM+0x3DB4A\n"
        ".L08133F80: .4byte 0x03006678 @ IWRAM+0x6678\n"
        ".L08133F84: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L08133F88: .4byte 0x03006680 @ IWRAM+0x6680\n"
        ".L08133F8C:\n"
        "    ldr r0, [sp, #8]\n"
        "    adds r0, #8\n"
        "    ldr r5, [sp]\n"
        "    cmp r5, r0\n"
        "    bne .L08133FAC\n"
        "    ldr r0, .L08133FA4\n"
        "    movs r1, #1\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L08133FA8\n"
        "    strh r4, [r0]\n"
        "    b .L08133FB6\n"
        "    .byte 0x00, 0x00\n"
        ".L08133FA4: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L08133FA8: .4byte 0x03006680 @ IWRAM+0x6680\n"
        ".L08133FAC:\n"
        "    ldr r0, .L08134168\n"
        "    movs r1, #1\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L0813416C\n"
        "    strh r1, [r0]\n"
        ".L08133FB6:\n"
        "    movs r0, #3\n"
        "    ldr r1, [sp, #8]\n"
        "    cmp r1, #0\n"
        "    bne .L08133FC0\n"
        "    movs r0, #4\n"
        ".L08133FC0:\n"
        "    ldr r4, [sp]\n"
        "    adds r2, r4, r0\n"
        "    cmp r4, r2\n"
        "    blt .L08133FCA\n"
        "    b .L08134226\n"
        ".L08133FCA:\n"
        "    ldr r0, .L08134170\n"
        "    lsls r1, r4, #1\n"
        "    adds r1, r1, r0\n"
        "    ldrh r1, [r1]\n"
        "    str r1, [sp, #4]\n"
        "    ldr r0, .L08134174\n"
        "    cmp r1, r0\n"
        "    bne .L08133FDC\n"
        "    b .L08134226\n"
        ".L08133FDC:\n"
        "    str r2, [sp, #0x18]\n"
        ".L08133FDE:\n"
        "    ldr r0, [sp, #4]\n"
        "    bl Action_GetRecord\n"
        "    adds r3, r0, #0\n"
        "    adds r3, #0xc\n"
        "    movs r2, #0\n"
        "    ldr r5, [sp]\n"
        "    subs r5, r4, r5\n"
        "    str r5, [sp, #0x14]\n"
        "    lsls r6, r4, #1\n"
        "    adds r4, #1\n"
        "    str r4, [sp, #0x10]\n"
        "    ldr r1, .L08134178\n"
        ".L08133FF8:\n"
        "    lsls r0, r2, #1\n"
        "    adds r0, r0, r1\n"
        "    movs r4, #0\n"
        "    strh r4, [r0]\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #0xf\n"
        "    bls .L08133FF8\n"
        "    movs r2, #0\n"
        "    ldr r5, .L0813417C\n"
        "    ldr r4, .L08134178\n"
        ".L08134010:\n"
        "    lsls r0, r2, #1\n"
        "    adds r0, r0, r4\n"
        "    ldrh r1, [r3]\n"
        "    strh r1, [r0]\n"
        "    adds r3, #2\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #7\n"
        "    bls .L08134010\n"
        "    ldr r1, [sp, #0x14]\n"
        "    ldr r2, [sp, #8]\n"
        "    adds r0, r1, r2\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r5\n"
        "    ldrh r0, [r0]\n"
        "    str r0, [sp, #0xc]\n"
        "    movs r0, #0x27\n"
        "    ldr r1, [sp, #0xc]\n"
        "    movs r2, #0\n"
        "    movs r3, #8\n"
        "    bl MsgGlyphQueue_PushSubstClamped\n"
        "    ldr r3, .L08134180\n"
        "    mov sl, r3\n"
        "    ldrh r3, [r3]\n"
        "    lsls r0, r3, #0x12\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r1, r7, #0\n"
        "    ldr r4, .L08134184\n"
        "    mov r8, r4\n"
        "    movs r0, #1\n"
        "    orrs r7, r0\n"
        "    adds r2, r7, #0\n"
        "    lsls r1, r1, #1\n"
        "    add r1, r8\n"
        "    ldr r0, .L08134188\n"
        "    strh r0, [r1]\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r1, r7, #0\n"
        "    lsls r2, r2, #1\n"
        "    add r2, r8\n"
        "    movs r0, #0x9a\n"
        "    strh r0, [r2]\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsls r1, r1, #1\n"
        "    add r1, r8\n"
        "    mov r5, sp\n"
        "    ldrh r5, [r5, #0xc]\n"
        "    strh r5, [r1]\n"
        "    lsrs r0, r0, #0xf\n"
        "    add r0, r8\n"
        "    movs r1, #0\n"
        "    strh r1, [r0]\n"
        "    adds r3, #1\n"
        "    mov r2, sl\n"
        "    strh r3, [r2]\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    cmp r3, #0x3f\n"
        "    bls .L08134094\n"
        "    movs r0, #0x3f\n"
        "    strh r0, [r2]\n"
        ".L08134094:\n"
        "    ldr r0, .L08134170\n"
        "    adds r0, r6, r0\n"
        "    ldrh r0, [r0]\n"
        "    bl Inventory_GetCount\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    mov sb, r0\n"
        "    cmp r0, #9\n"
        "    bls .L08134190\n"
        "    mov r3, sl\n"
        "    ldrh r6, [r3]\n"
        "    lsls r0, r6, #0x12\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r4, r7, #0\n"
        "    movs r0, #1\n"
        "    orrs r7, r0\n"
        "    adds r5, r7, #0\n"
        "    lsls r4, r4, #1\n"
        "    add r4, r8\n"
        "    mov r0, sb\n"
        "    movs r1, #0xa\n"
        "    bl __udivsi3\n"
        "    lsls r0, r0, #1\n"
        "    ldr r1, .L0813418C\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r4]\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r1, r7, #0\n"
        "    lsls r5, r5, #1\n"
        "    add r5, r8\n"
        "    movs r0, #0xa7\n"
        "    strh r0, [r5]\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsls r1, r1, #1\n"
        "    add r1, r8\n"
        "    mov r2, sp\n"
        "    ldrh r2, [r2, #0xc]\n"
        "    strh r2, [r1]\n"
        "    lsrs r0, r0, #0xf\n"
        "    add r0, r8\n"
        "    movs r3, #0\n"
        "    strh r3, [r0]\n"
        "    adds r6, #1\n"
        "    mov r4, sl\n"
        "    strh r6, [r4]\n"
        "    lsls r6, r6, #0x10\n"
        "    lsrs r6, r6, #0x10\n"
        "    cmp r6, #0x3f\n"
        "    bls .L08134106\n"
        "    movs r0, #0x3f\n"
        "    strh r0, [r4]\n"
        ".L08134106:\n"
        "    mov r5, sl\n"
        "    ldrh r6, [r5]\n"
        "    lsls r0, r6, #0x12\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r4, r7, #0\n"
        "    movs r0, #1\n"
        "    orrs r7, r0\n"
        "    adds r5, r7, #0\n"
        "    lsls r4, r4, #1\n"
        "    add r4, r8\n"
        "    mov r0, sb\n"
        "    movs r1, #0xa\n"
        "    bl __umodsi3\n"
        "    lsls r0, r0, #1\n"
        "    ldr r1, .L0813418C\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r4]\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r1, r7, #0\n"
        "    lsls r5, r5, #1\n"
        "    add r5, r8\n"
        "    movs r0, #0xb4\n"
        "    strh r0, [r5]\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsls r1, r1, #1\n"
        "    add r1, r8\n"
        "    mov r2, sp\n"
        "    ldrh r2, [r2, #0xc]\n"
        "    strh r2, [r1]\n"
        "    lsrs r0, r0, #0xf\n"
        "    add r0, r8\n"
        "    movs r3, #0\n"
        "    strh r3, [r0]\n"
        "    adds r6, #1\n"
        "    mov r4, sl\n"
        "    strh r6, [r4]\n"
        "    lsls r6, r6, #0x10\n"
        "    lsrs r6, r6, #0x10\n"
        "    cmp r6, #0x3f\n"
        "    bls .L081341E8\n"
        "    movs r0, #0x3f\n"
        "    strh r0, [r4]\n"
        "    b .L081341E8\n"
        "    .byte 0x00, 0x00\n"
        ".L08134168: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L0813416C: .4byte 0x03006680 @ IWRAM+0x6680\n"
        ".L08134170: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L08134174: .4byte 0x0000FFFF\n"
        ".L08134178: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L0813417C: .4byte gUnknown_08790390\n"
        ".L08134180: .4byte 0x0203DB3E @ EWRAM+0x3DB3E\n"
        ".L08134184: .4byte 0x0203D800 @ EWRAM+0x3D800\n"
        ".L08134188: .4byte 0x00000115\n"
        ".L0813418C: .4byte gScriptDigitGlyphs\n"
        ".L08134190:\n"
        "    mov r5, sl\n"
        "    ldrh r4, [r5]\n"
        "    lsls r0, r4, #0x12\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r2, r7, #0\n"
        "    movs r0, #1\n"
        "    orrs r7, r0\n"
        "    adds r3, r7, #0\n"
        "    lsls r2, r2, #1\n"
        "    add r2, r8\n"
        "    ldr r1, .L08134238\n"
        "    mov r5, sb\n"
        "    lsls r0, r5, #1\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r2]\n"
        "    adds r0, r3, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r1, r7, #0\n"
        "    lsls r3, r3, #1\n"
        "    add r3, r8\n"
        "    movs r0, #0xb4\n"
        "    strh r0, [r3]\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsls r1, r1, #1\n"
        "    add r1, r8\n"
        "    mov r2, sp\n"
        "    ldrh r2, [r2, #0xc]\n"
        "    strh r2, [r1]\n"
        "    lsrs r0, r0, #0xf\n"
        "    add r0, r8\n"
        "    movs r3, #0\n"
        "    strh r3, [r0]\n"
        "    adds r4, #1\n"
        "    mov r5, sl\n"
        "    strh r4, [r5]\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    cmp r4, #0x3f\n"
        "    bls .L081341E8\n"
        "    movs r0, #0x3f\n"
        "    strh r0, [r5]\n"
        ".L081341E8:\n"
        "    ldr r0, .L0813423C\n"
        "    ldrh r0, [r0]\n"
        "    ldr r1, [sp, #4]\n"
        "    cmp r0, r1\n"
        "    bne .L08134208\n"
        "    ldr r2, .L08134240\n"
        "    movs r0, #1\n"
        "    strh r0, [r2]\n"
        "    ldr r1, .L08134244\n"
        "    ldr r3, [sp, #0x14]\n"
        "    ldr r4, [sp, #8]\n"
        "    adds r0, r3, r4\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r2, #2]\n"
        ".L08134208:\n"
        "    ldr r5, [sp, #0x10]\n"
        "    lsls r0, r5, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    ldr r0, [sp, #0x18]\n"
        "    cmp r4, r0\n"
        "    bge .L08134226\n"
        "    ldr r0, .L08134248\n"
        "    lsls r1, r4, #1\n"
        "    adds r1, r1, r0\n"
        "    ldrh r1, [r1]\n"
        "    str r1, [sp, #4]\n"
        "    ldr r0, .L0813424C\n"
        "    cmp r1, r0\n"
        "    beq .L08134226\n"
        "    b .L08133FDE\n"
        ".L08134226:\n"
        "    add sp, #0x1c\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L08134238: .4byte gScriptDigitGlyphs\n"
        ".L0813423C: .4byte 0x030068D8 @ IWRAM+0x68D8\n"
        ".L08134240: .4byte 0x03006678 @ IWRAM+0x6678\n"
        ".L08134244: .4byte gUnknown_08790390\n"
        ".L08134248: .4byte 0x0203DB88 @ EWRAM+0x3DB88\n"
        ".L0813424C: .4byte 0x0000FFFF\n"
    );
}
#endif

