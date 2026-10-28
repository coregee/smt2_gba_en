/* Casino prize exchange list (0x0813914C-0x0813950F). */

#include "global.h"
#include "scriptops2.h"

/* Draws up to 3 (4 with no scroll arrow) rows of the prize list starting at row `first`:
   the prize name (8 glyphs, copied into gScriptSubstBuf) at x 0x1A and the coin price
   right-aligned in 8 digit cells at x 0x8D, followed by glyph 0xFC8.
   gUnknown_0878FEA8 holds one 16-halfword record per prize set: [0] = count, then
   (item id, price) pairs; a price of 0xFFFF is shown as 100000. */
// CasinoPrize_DrawList @ 0x0813914C
#ifdef NONMATCHING
void CasinoPrize_DrawList(u16 first)
{
    u16 digits[8];
    u16 out[8];
    u16 set;
    s32 rows;
    u16 i, j, n;
    u16 id;
    u8 *rec;
    u16 *name;
    u32 price;
    s16 d;

    set = CasinoPrize_GetSet();
    gMsgGlyphCount = 0;
    gTextColumn = 0;
    gTextLine = 0;
    gUnk_0203DB4A = 0;
    Font_ResetGlyphSpriteCache(0x180);
    if (gUnk_03006844 == 1)
        MsgWindow_RestoreGlyphs();
    if (first == 0)
    {
        gUnk_03006848 = first;
        gUnk_03006680 = 1;
    }
    else if (first == gUnknown_0878FEA8[set][0] - 3 + gUnk_03006844)
    {
        gUnk_03006848 = 1;
        gUnk_03006680 = 0;
    }
    else
    {
        gUnk_03006848 = 1;
        gUnk_03006680 = 1;
    }
    rows = 3;
    if (gUnk_03006844 == 0)
        rows = 4;
    for (i = first; i < first + rows && (id = gUnknown_0878FEA8[set][i * 2 + 1]) != 0xFFFF; i++)
    {
        if (id >= 0xD0)
            name = (u16 *)(Action_GetRecord(id) + 0xC);
        else
        {
            if (id >= 0x80)
                rec = Equipment_GetRecord36_MidRange(id);
            else
                rec = Item_GetRecord(id);
            name = (u16 *)(rec + 0x14);
        }
        for (j = 0; j < 16; j++)
            gScriptSubstBuf[j] = 0;
        for (j = 0; j < 8; j++)
            gScriptSubstBuf[j] = *name++;
        MsgGlyphQueue_PushSubstClamped(0x1A, gUnknown_08790390[gUnk_03006844 + (i - first)], 0, 8);

        price = gUnknown_0878FEA8[set][i * 2 + 2];
        if (price == 0xFFFF)
            price = 100000;
        for (j = 0; j < 8; j++)
            digits[j] |= 0xFFFF;
        for (j = 0; j < 8 && price != 0; j++)
        {
            digits[j] = gScriptDigitGlyphs[price % 10];
            price /= 10;
        }
        for (n = 0, d = 7; d >= 0; d--)
            out[n++] = digits[d];

        n = 0;
        for (j = 0; j < 8; j++)
        {
            if (out[j] != 0xFFFF)
            {
                QUEUE_GLYPH(out[j], n * 10 + 0x8D, gUnknown_08790390[gUnk_03006844 + (i - first)]);
                n++;
            }
        }
        QUEUE_GLYPH(0xFC8, n * 10 + 0x8F, gUnknown_08790390[gUnk_03006844 + (i - first)]);
    }
}
#else
NAKED
void CasinoPrize_DrawList(u16 first)
{
    asm_unified(
        ".L0813914C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x3c\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0x20]\n"
        "    bl CasinoPrize_GetSet\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldr r0, .L081391A0\n"
        "    movs r4, #0\n"
        "    strh r4, [r0]\n"
        "    ldr r0, .L081391A4\n"
        "    strh r4, [r0]\n"
        "    ldr r0, .L081391A8\n"
        "    strh r4, [r0]\n"
        "    ldr r0, .L081391AC\n"
        "    strh r4, [r0]\n"
        "    movs r0, #0xc0\n"
        "    lsls r0, r0, #1\n"
        "    bl Font_ResetGlyphSpriteCache\n"
        "    ldr r5, .L081391B0\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r5, r1]\n"
        "    cmp r0, #1\n"
        "    bne .L0813918E\n"
        "    bl MsgWindow_RestoreGlyphs\n"
        ".L0813918E:\n"
        "    ldr r2, [sp, #0x20]\n"
        "    cmp r2, #0\n"
        "    bne .L081391BC\n"
        "    ldr r0, .L081391B4\n"
        "    strh r2, [r0]\n"
        "    ldr r1, .L081391B8\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    b .L081391F6\n"
        ".L081391A0: .4byte 0x0203DB3E @ EWRAM+0x3DB3E\n"
        ".L081391A4: .4byte 0x0203DB38 @ EWRAM+0x3DB38\n"
        ".L081391A8: .4byte 0x0203DB3A @ EWRAM+0x3DB3A\n"
        ".L081391AC: .4byte 0x0203DB4A @ EWRAM+0x3DB4A\n"
        ".L081391B0: .4byte 0x03006844 @ IWRAM+0x6844\n"
        ".L081391B4: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L081391B8: .4byte 0x03006680 @ IWRAM+0x6680\n"
        ".L081391BC:\n"
        "    ldr r1, .L081391E0\n"
        "    lsls r0, r6, #5\n"
        "    adds r0, r0, r1\n"
        "    ldrh r0, [r0]\n"
        "    subs r0, #3\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r5, r2]\n"
        "    adds r0, r0, r1\n"
        "    ldr r3, [sp, #0x20]\n"
        "    cmp r3, r0\n"
        "    bne .L081391EC\n"
        "    ldr r0, .L081391E4\n"
        "    movs r1, #1\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L081391E8\n"
        "    strh r4, [r0]\n"
        "    b .L081391F6\n"
        "    .byte 0x00, 0x00\n"
        ".L081391E0: .4byte gUnknown_0878FEA8\n"
        ".L081391E4: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L081391E8: .4byte 0x03006680 @ IWRAM+0x6680\n"
        ".L081391EC:\n"
        "    ldr r0, .L08139240\n"
        "    movs r1, #1\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L08139244\n"
        "    strh r1, [r0]\n"
        ".L081391F6:\n"
        "    ldr r0, .L08139248\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r0, r5]\n"
        "    movs r1, #3\n"
        "    str r1, [sp, #0x24]\n"
        "    cmp r0, #0\n"
        "    bne .L08139208\n"
        "    movs r2, #4\n"
        "    str r2, [sp, #0x24]\n"
        ".L08139208:\n"
        "    ldr r4, [sp, #0x20]\n"
        "    ldr r3, [sp, #0x24]\n"
        "    adds r0, r4, r3\n"
        "    cmp r4, r0\n"
        "    blt .L08139214\n"
        "    b .L0813947A\n"
        ".L08139214:\n"
        "    ldr r3, .L0813924C\n"
        "    lsls r0, r4, #1\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #1\n"
        "    lsls r1, r6, #5\n"
        "    adds r0, r0, r1\n"
        "    adds r0, r0, r3\n"
        "    ldrh r2, [r0]\n"
        "    ldr r0, .L08139250\n"
        "    str r1, [sp, #0x28]\n"
        "    cmp r2, r0\n"
        "    bne .L0813922E\n"
        "    b .L0813947A\n"
        ".L0813922E:\n"
        "    cmp r2, #0xcf\n"
        "    bls .L08139254\n"
        "    adds r0, r2, #0\n"
        "    bl Action_GetRecord\n"
        "    adds r2, r0, #0\n"
        "    adds r2, #0xc\n"
        "    b .L0813926A\n"
        "    .byte 0x00, 0x00\n"
        ".L08139240: .4byte 0x03006848 @ IWRAM+0x6848\n"
        ".L08139244: .4byte 0x03006680 @ IWRAM+0x6680\n"
        ".L08139248: .4byte 0x03006844 @ IWRAM+0x6844\n"
        ".L0813924C: .4byte gUnknown_0878FEA8\n"
        ".L08139250: .4byte 0x0000FFFF\n"
        ".L08139254:\n"
        "    cmp r2, #0x7f\n"
        "    bls .L08139260\n"
        "    adds r0, r2, #0\n"
        "    bl Equipment_GetRecord36_MidRange\n"
        "    b .L08139266\n"
        ".L08139260:\n"
        "    adds r0, r2, #0\n"
        "    bl Item_GetRecord\n"
        ".L08139266:\n"
        "    adds r2, r0, #0\n"
        "    adds r2, #0x14\n"
        ".L0813926A:\n"
        "    movs r6, #0\n"
        "    ldr r5, [sp, #0x20]\n"
        "    subs r5, r4, r5\n"
        "    mov sb, r5\n"
        "    lsls r5, r4, #1\n"
        "    mov r0, sp\n"
        "    adds r0, #0x10\n"
        "    str r0, [sp, #0x30]\n"
        "    adds r4, #1\n"
        "    str r4, [sp, #0x34]\n"
        "    ldr r1, [sp, #0x20]\n"
        "    ldr r3, [sp, #0x24]\n"
        "    adds r1, r1, r3\n"
        "    str r1, [sp, #0x2c]\n"
        "    ldr r3, .L0813948C\n"
        "    movs r1, #0\n"
        ".L0813928A:\n"
        "    lsls r0, r6, #1\n"
        "    adds r0, r0, r3\n"
        "    strh r1, [r0]\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r6, #0xf\n"
        "    bls .L0813928A\n"
        "    movs r6, #0\n"
        "    ldr r3, .L0813948C\n"
        ".L0813929E:\n"
        "    lsls r0, r6, #1\n"
        "    adds r0, r0, r3\n"
        "    ldrh r1, [r2]\n"
        "    strh r1, [r0]\n"
        "    adds r2, #2\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r6, #7\n"
        "    bls .L0813929E\n"
        "    ldr r7, .L08139490\n"
        "    ldr r4, .L08139494\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r4, r1]\n"
        "    add r0, sb\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r7\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x1a\n"
        "    movs r2, #0\n"
        "    movs r3, #8\n"
        "    bl MsgGlyphQueue_PushSubstClamped\n"
        "    adds r0, r5, #2\n"
        "    lsls r0, r0, #1\n"
        "    ldr r2, [sp, #0x28]\n"
        "    adds r0, r0, r2\n"
        "    ldr r3, .L08139498\n"
        "    adds r0, r0, r3\n"
        "    ldr r1, .L0813949C\n"
        "    ldrh r5, [r0]\n"
        "    cmp r5, r1\n"
        "    bne .L081392E2\n"
        "    ldr r5, .L081394A0\n"
        ".L081392E2:\n"
        "    movs r6, #0\n"
        "    adds r2, r1, #0\n"
        ".L081392E6:\n"
        "    lsls r0, r6, #1\n"
        "    mov r3, sp\n"
        "    adds r1, r3, r0\n"
        "    ldrh r0, [r1]\n"
        "    orrs r0, r2\n"
        "    strh r0, [r1]\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r6, #7\n"
        "    bls .L081392E6\n"
        "    movs r6, #0\n"
        "    cmp r5, #0\n"
        "    beq .L08139332\n"
        "    ldr r7, .L081394A4\n"
        ".L08139304:\n"
        "    lsls r0, r6, #1\n"
        "    mov r1, sp\n"
        "    adds r4, r1, r0\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #0xa\n"
        "    bl __umodsi3\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r7\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r4]\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #0xa\n"
        "    bl __udivsi3\n"
        "    adds r5, r0, #0\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r6, #7\n"
        "    bhi .L08139332\n"
        "    cmp r5, #0\n"
        "    bne .L08139304\n"
        ".L08139332:\n"
        "    movs r7, #0\n"
        "    movs r0, #7\n"
        "    ldr r3, [sp, #0x30]\n"
        ".L08139338:\n"
        "    lsls r2, r7, #1\n"
        "    adds r2, r3, r2\n"
        "    lsls r1, r0, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    lsls r0, r1, #1\n"
        "    .2byte 0x4468 @ add r0, sp, r0\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r2]\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    subs r1, #1\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r0, r1, #0x10\n"
        "    cmp r1, #0\n"
        "    bge .L08139338\n"
        "    movs r7, #0\n"
        "    movs r6, #0\n"
        "    ldr r2, .L081394A8\n"
        "    mov ip, r2\n"
        "    ldr r4, .L081394AC\n"
        "    mov sl, r6\n"
        "    mov r8, sb\n"
        ".L08139366:\n"
        "    lsls r0, r6, #1\n"
        "    ldr r3, [sp, #0x30]\n"
        "    adds r0, r3, r0\n"
        "    ldrh r2, [r0]\n"
        "    ldr r5, .L0813949C\n"
        "    cmp r2, r5\n"
        "    beq .L081393E0\n"
        "    mov r0, ip\n"
        "    ldrh r3, [r0]\n"
        "    lsls r0, r3, #0x12\n"
        "    lsrs r5, r0, #0x10\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #1\n"
        "    orrs r5, r1\n"
        "    adds r1, r5, #0\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r4\n"
        "    strh r2, [r0]\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    adds r2, r5, #0\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r4\n"
        "    lsls r0, r7, #2\n"
        "    adds r0, r0, r7\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #0x8d\n"
        "    strh r0, [r1]\n"
        "    adds r1, r2, #1\n"
        "    lsls r1, r1, #0x10\n"
        "    lsls r2, r2, #1\n"
        "    adds r2, r2, r4\n"
        "    str r2, [sp, #0x38]\n"
        "    ldr r2, .L08139494\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r2, r5]\n"
        "    add r0, r8\n"
        "    lsls r0, r0, #1\n"
        "    ldr r2, .L08139490\n"
        "    adds r0, r0, r2\n"
        "    ldrh r0, [r0]\n"
        "    ldr r5, [sp, #0x38]\n"
        "    strh r0, [r5]\n"
        "    lsrs r1, r1, #0xf\n"
        "    adds r1, r1, r4\n"
        "    mov r0, sl\n"
        "    strh r0, [r1]\n"
        "    adds r3, #1\n"
        "    mov r1, ip\n"
        "    strh r3, [r1]\n"
        "    adds r0, r7, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    cmp r3, #0x3f\n"
        "    bls .L081393E0\n"
        "    movs r0, #0x3f\n"
        "    ldr r2, .L081394A8\n"
        "    strh r0, [r2]\n"
        ".L081393E0:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    cmp r6, #7\n"
        "    bls .L08139366\n"
        "    ldr r3, .L081394A8\n"
        "    ldrh r4, [r3]\n"
        "    lsls r0, r4, #0x12\n"
        "    lsrs r5, r0, #0x10\n"
        "    adds r1, r5, #0\n"
        "    movs r0, #1\n"
        "    orrs r5, r0\n"
        "    adds r2, r5, #0\n"
        "    lsls r1, r1, #1\n"
        "    ldr r5, .L081394AC\n"
        "    adds r1, r1, r5\n"
        "    ldr r0, .L081394B0\n"
        "    strh r0, [r1]\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    adds r3, r5, #0\n"
        "    lsls r2, r2, #1\n"
        "    ldr r0, .L081394AC\n"
        "    adds r2, r2, r0\n"
        "    lsls r0, r7, #2\n"
        "    adds r0, r0, r7\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #0x8f\n"
        "    strh r0, [r2]\n"
        "    adds r1, r3, #1\n"
        "    lsls r1, r1, #0x10\n"
        "    lsls r3, r3, #1\n"
        "    ldr r2, .L081394AC\n"
        "    adds r3, r3, r2\n"
        "    ldr r5, .L08139494\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r5, r2]\n"
        "    add r0, sb\n"
        "    lsls r0, r0, #1\n"
        "    ldr r5, .L08139490\n"
        "    adds r0, r0, r5\n"
        "    ldrh r0, [r0]\n"
        "    strh r0, [r3]\n"
        "    lsrs r1, r1, #0xf\n"
        "    ldr r0, .L081394AC\n"
        "    adds r1, r1, r0\n"
        "    movs r2, #0\n"
        "    strh r2, [r1]\n"
        "    adds r4, #1\n"
        "    ldr r3, .L081394A8\n"
        "    strh r4, [r3]\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    cmp r4, #0x3f\n"
        "    bls .L08139456\n"
        "    movs r0, #0x3f\n"
        "    adds r5, r3, #0\n"
        "    strh r0, [r5]\n"
        ".L08139456:\n"
        "    ldr r1, [sp, #0x34]\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    ldr r2, [sp, #0x2c]\n"
        "    cmp r4, r2\n"
        "    bge .L0813947A\n"
        "    lsls r0, r4, #1\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #1\n"
        "    ldr r3, [sp, #0x28]\n"
        "    adds r0, r0, r3\n"
        "    ldr r5, .L08139498\n"
        "    adds r0, r0, r5\n"
        "    ldrh r2, [r0]\n"
        "    ldr r0, .L0813949C\n"
        "    cmp r2, r0\n"
        "    beq .L0813947A\n"
        "    b .L0813922E\n"
        ".L0813947A:\n"
        "    add sp, #0x3c\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L0813948C: .4byte 0x0203DB08 @ EWRAM+0x3DB08\n"
        ".L08139490: .4byte gUnknown_08790390\n"
        ".L08139494: .4byte 0x03006844 @ IWRAM+0x6844\n"
        ".L08139498: .4byte gUnknown_0878FEA8\n"
        ".L0813949C: .4byte 0x0000FFFF\n"
        ".L081394A0: .4byte 0x000186A0\n"
        ".L081394A4: .4byte gScriptDigitGlyphs\n"
        ".L081394A8: .4byte 0x0203DB3E @ EWRAM+0x3DB3E\n"
        ".L081394AC: .4byte 0x0203D800 @ EWRAM+0x3D800\n"
        ".L081394B0: .4byte 0x00000FC8\n"
    );
}
#endif

/* Prize set by story progress (flags 0xB9/0xC7/0xBC/0xC8 and item 0x157). */
// CasinoPrize_GetSet @ 0x081394B4
u16 CasinoPrize_GetSet(void)
{
    if (Flag_Test(0xB9) == 1)
    {
        if (sub_080C57CC(0x157) == 1)
            return 4;
        goto none;
    }
    if (Flag_Test(0xC7) == 1)
        return 1;
    if (Flag_Test(0xBC) == 1)
        return 2;
    if (Flag_Test(0xC8) != 1)
    {
    none:
        return 0;
    }
    return 3;
}

// ScriptOpAlt_409 @ 0x08139504
void ScriptOpAlt_409(void)
{
    gScriptPc += 6;
}

/* Operand: low byte = action (0 start, 1 open, 6 end), high byte = 0 or 1 selects the
   two screen variants (sub_080C700C/sub_080C6FF0 ...). */
// ScriptOp_40A @ 0x08139514
void ScriptOp_40A(void)
{
    u16 pc = gScriptPc++;
    u16 hi;
    u8 lo;

    hi = gScriptBase[pc];
    lo = *(u8 *)&gScriptBase[pc];
    hi >>= 8;

    if (hi == 0)
    {
        if (lo == 0)
        {
            sub_080C700C();
            gUnk_0203DB5C = 0x5A;
            gScriptWaitState = 0xF;
            gScriptYield = 1;
        }
        else if (lo == 1)
        {
            gUnk_03006954 = sub_080D3740();
            gUnk_0203DB5C = 2;
            gScriptWaitState = 0xF;
            gScriptYield = lo;
        }
        if (lo == 6)
        {
            sub_080C7648();
            gUnk_0203DB5C = 2;
            gScriptWaitState = 0xF;
            gScriptYield = 1;
        }
    }
    else
    {
        if (lo == 0)
        {
            sub_080C6FF0();
            gUnk_0203DB5C = 0x5A;
            gScriptWaitState = 0xF;
            gScriptYield = 1;
        }
        else if (lo == 1)
        {
            sub_080D3758(gUnk_03006954);
            gUnk_0203DB5C = 2;
            gScriptWaitState = 0xF;
            gScriptYield = lo;
        }
        if (lo == 6)
        {
            sub_080C762C();
            gUnk_0203DB5C = 2;
            gScriptWaitState = 0xF;
            gScriptYield = 1;
        }
    }
}

// ScriptOpAlt_40A @ 0x08139610
void ScriptOpAlt_40A(void)
{
    gScriptPc += 2;
}

// ScriptOp_40C @ 0x08139620
void ScriptOp_40C(void)
{
    u16 v = SCRIPT_READ();

    v |= 0x100;
    gScriptItemCheckId = v;
}

// ScriptOp_40B @ 0x08139650
void ScriptOp_40B(void)
{
    u16 lo = SCRIPT_READ();
    u32 t1 = SCRIPT_READ() << 16 | lo;
    u32 t2;

    lo = SCRIPT_READ();
    t2 = SCRIPT_READ();
    t2 = t2 << 16 | lo;
    if (gUnk_03006990[0] == 0xFFFF)
        gScriptJumpTarget = (u16 *)t1;
    else if (gUnk_03006990[1] == 0xFFFF)
    {
        gUnk_0203DAC8[15] = (u16 *)t2;
        gUnk_030069CC = 1;
        gScriptJumpTarget = gUnk_0203DAC8[10];
    }
}

// ScriptOpAlt_40B @ 0x081396E0
void ScriptOpAlt_40B(void)
{
    gScriptPc += 2;
}

/* Raises base stat (high byte) of member (low byte) by 1. */
// ScriptOp_40D @ 0x081396F0
void ScriptOp_40D(void)
{
    u16 who = SCRIPT_READ();
    u16 stat = who >> 8;

    who &= 0xFF;

    if (who == 1 && !Combatant_IsUsed(1))
    {
        /* tests member 1 again, so this never switches to member 2 */
        if (!Combatant_IsUsed(1))
            return;
        who = 2;
    }
    Combatant_AddBaseStat(who, stat, 1);
    Combatant_RecalcStats(who);
    if (who == 1)
    {
        Combatant_RestoreHp(1);
        Combatant_RestoreMp(1);
    }
    sub_080CDC34();
}

// ScriptOpAlt_40D @ 0x08139758
void ScriptOpAlt_40D(void)
{
    gScriptPc++;
}

// ScriptOp_40E @ 0x08139768
void ScriptOp_40E(void)
{
    u16 k = SCRIPT_READ();

    k &= 0xF;
    if (k == 2)
        Flag_Set(0x10B);
    else if (k == 4)
        Flag_Set(0x10C);
}

// ScriptOpAlt_40E @ 0x081397A8
void ScriptOpAlt_40E(void)
{
    gScriptPc++;
}

// sub_081397B8 @ 0x081397B8
void sub_081397B8(void)
{
    gScriptPc++;
}

// ScriptOpAlt_40F @ 0x081397C8
void ScriptOpAlt_40F(void)
{
    gScriptPc++;
}
