#include "global.h"
#include "battle.h"

// sub_080F0B78 @ 0x080F0B78
u32 sub_080F0B78(u32 who)
{
    u8 slot;
    struct BattleFlow *b = BFLOW;

    slot = who;
    slot -= 0x10;
    if (Battle_IsTwoSided() && b->unk118C == 0)
    {
        if (slot <= 3)
        {
            if (!sub_080EDA24(0))
                return 1;
        }
        else
        {
            if (!sub_080EDA24(1))
                return 1;
        }
    }
    return 0;
}

// sub_080F0BC0 @ 0x080F0BC0
void sub_080F0BC0(void)
{
    BFLOW->unk118C += 2;
}

// sub_080F0BD8 @ 0x080F0BD8
void sub_080F0BD8(void)
{
    BFLOW->unk97C = 10;
}

// sub_080F0BEC @ 0x080F0BEC
void sub_080F0BEC(void)
{
    struct BattleFlow *b = BFLOW;

    Task_Create(gUnknown_0876F7DC, 0xFFFF);
    b->unk97C = 15;
}

// sub_080F0C18 @ 0x080F0C18
/* Status effects that act before a combatant's turn (bits of the status word at +0x10). */
#ifdef NONMATCHING
u32 sub_080F0C18(u8 *c, u16 who)
{
    struct BattleFlow *b = BFLOW;
    u16 f = *(u16 *)(c + 0x10);

    if (f & 0x200)
    {
        s16 w = who;

        if (w > 3)
            sub_080C35C4(w, 10);
        else if (Combatant_GetEquip(w, 0) != 0xFF)
            sub_080C35C4(w, 4);
        else
            sub_080C35C4(w, 9);
    }
    else if ((f & 8) && Random_Byte() % 40 <= 0x13)
    {
        BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(Battle_GetMessage(0x172), (s16)who));
        b->unk97C = 11;
        sub_080F0344(3, 12);
        return 1;
    }
    else if (f & 0x10)
    {
        u32 r = Random_Byte() & 3;

        if (r & 2)
        {
            s16 w = who;

            if (w <= 15)
            {
                if (w > 3 && !(r & 1))
                    sub_080C35C4(w, 12);
                else
                    sub_080C35C4(w, 9);
            }
            else
                c[0x17] = 9;
        }
    }
    return 0;
}
#else
NAKED u32 sub_080F0C18(u8 *c, u16 who)
{
    asm_unified(
        ".L080F0C18:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    adds r6, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r5, r1, #0x10\n"
        "    ldr r7, .L080F0C40\n"
        "    ldrh r4, [r6, #0x10]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #2\n"
        "    ands r0, r4\n"
        "    cmp r0, #0\n"
        "    beq .L080F0C64\n"
        "    lsls r0, r5, #0x10\n"
        "    asrs r4, r0, #0x10\n"
        "    cmp r4, #3\n"
        "    ble .L080F0C44\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0xa\n"
        "    bl sub_080C35C4\n"
        "    b .L080F0CF4\n"
        ".L080F0C40: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080F0C44:\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0\n"
        "    bl Combatant_GetEquip\n"
        "    cmp r0, #0xff\n"
        "    beq .L080F0C5A\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #4\n"
        "    bl sub_080C35C4\n"
        "    b .L080F0CF4\n"
        ".L080F0C5A:\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #9\n"
        "    bl sub_080C35C4\n"
        "    b .L080F0CF4\n"
        ".L080F0C64:\n"
        "    movs r0, #8\n"
        "    ands r0, r4\n"
        "    cmp r0, #0\n"
        "    beq .L080F0CAC\n"
        "    bl Random_Byte\n"
        "    movs r1, #0x28\n"
        "    bl __umodsi3\n"
        "    cmp r0, #0x13\n"
        "    bhi .L080F0CAC\n"
        "    movs r0, #0xb9\n"
        "    lsls r0, r0, #1\n"
        "    bl Battle_GetMessage\n"
        "    lsls r1, r5, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    ldr r0, .L080F0CA8\n"
        "    adds r1, r7, r0\n"
        "    movs r0, #0xb\n"
        "    strh r0, [r1]\n"
        "    movs r0, #3\n"
        "    movs r1, #0xc\n"
        "    bl sub_080F0344\n"
        "    movs r0, #1\n"
        "    b .L080F0CF6\n"
        "    .byte 0x00, 0x00\n"
        ".L080F0CA8: .4byte 0x0000097C\n"
        ".L080F0CAC:\n"
        "    movs r0, #0x10\n"
        "    ands r4, r0\n"
        "    cmp r4, #0\n"
        "    beq .L080F0CF4\n"
        "    bl Random_Byte\n"
        "    adds r2, r0, #0\n"
        "    movs r0, #3\n"
        "    ands r2, r0\n"
        "    movs r0, #2\n"
        "    ands r0, r2\n"
        "    cmp r0, #0\n"
        "    beq .L080F0CF4\n"
        "    lsls r0, r5, #0x10\n"
        "    asrs r3, r0, #0x10\n"
        "    adds r1, r0, #0\n"
        "    cmp r3, #0xf\n"
        "    bgt .L080F0CF0\n"
        "    cmp r3, #3\n"
        "    ble .L080F0CE6\n"
        "    movs r0, #1\n"
        "    ands r2, r0\n"
        "    cmp r2, #0\n"
        "    bne .L080F0CE6\n"
        "    adds r0, r3, #0\n"
        "    movs r1, #0xc\n"
        "    bl sub_080C35C4\n"
        "    b .L080F0CF4\n"
        ".L080F0CE6:\n"
        "    asrs r0, r1, #0x10\n"
        "    movs r1, #9\n"
        "    bl sub_080C35C4\n"
        "    b .L080F0CF4\n"
        ".L080F0CF0:\n"
        "    movs r0, #9\n"
        "    strb r0, [r6, #0x17]\n"
        ".L080F0CF4:\n"
        "    movs r0, #0\n"
        ".L080F0CF6:\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

