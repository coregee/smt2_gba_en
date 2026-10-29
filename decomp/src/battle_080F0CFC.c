/* Battle: paying for a command before it runs (MP, item, once-per-battle skills) and the
   alias table of special demon ids. */

#include "global.h"

/* The battle EWRAM block at 0x0203C200: only the fields used here. */
struct F0CFCBattle
{
    u8 pad000[0x97C];
    u16 phase;          /* 0x97C */
    u16 unk97E;         /* 0x97E */
    u8 pad980[0xF66 - 0x980];
    s16 unkF66;         /* 0xF66 */
    u8 padF68[0x11AA - 0xF68];
    u16 unk11AA;        /* 0x11AA: nonzero = commands cost nothing */
};
extern u8 gUnk_0203C200[];
#define BB ((struct F0CFCBattle *)gUnk_0203C200)

/* gUnk_03006434: the battle state, only the field used here. */
struct F0CFCState
{
    u8 pad000[0x15C];
    s16 unk15C;         /* 0x15C */
};
extern struct F0CFCState *gUnk_03006434;

/* One combatant (0x80 bytes): only the fields used here. */
struct F0CFCCombatant
{
    u8 pad00[0x10];
    u16 flags;          /* 0x10 */
    u8 pad12[0x17 - 0x12];
    s8 command;         /* 0x17: command kind */
    u8 pad18[0x1C - 0x18];
    u16 mp;             /* 0x1C */
    u8 pad1E[0x5C - 0x1E];
    u8 chosen;          /* 0x5C: chosen skill / item */
};

struct F0CFCEntry
{
    u8 id[2];
    u16 alt;
};
extern const struct F0CFCEntry gUnknown_0876E1D8[];

extern const u16 gUnknown_081241B0[], gUnknown_081241D0[], gUnknown_081241E0[];
extern const u16 gUnknown_081230A8[];

s32 sub_080F2C9C(s16 who);
s32 sub_080EFFF8(s32 who, s32 x);
s32 sub_080F3E54(s32 id, s32 n);
u32 sub_080ED6CC(s32 id);
s32 sub_080ED744(s32 who, s32 skill);
void sub_080ED6DC(s32 who, s32 item);
u32 sub_080EE028(s32 att, s32 def);
s32 Battle_IsEnemyId(s32 who);
u8 *Battle_GetCombatant(u16 idx);
u16 *Battle_BuildDodgeText(u8 *actor);
void BattleMenu_SetModeAutoClose(u8 mode, const u16 *src);
void sub_080F0344(u16 kind, u16 v);
void Item_GetAttribute(s32 id, s32 field, s32 *out);

// Battle_PayActionCost @ 0x080F0CFC
/* Pays for combatant c's command and picks the next battle phase: magic (kind 7) costs MP
   (party only; "not enough MP" / sealed messages), items (kind 8) are consumed, kind 11 skills
   are checked with sub_080ED744. A target that cannot be hit gives the dodge message. */
#ifdef NONMATCHING
void Battle_PayActionCost(struct F0CFCCombatant *c, u16 who)
{
    struct F0CFCBattle *b = BB;
    s32 item = c->chosen;
    u16 kind = c->command;
    u16 flags = c->flags;
    u16 target;

    if (gUnk_03006434->unk15C == 0)
        target = sub_080F2C9C(who);
    else
        target = sub_080EFFF8((s16)who, b->unkF66);

    if ((s16)kind == 8)
    {
        if (b->unkF66 == 0)
            sub_080F3E54(item, -1);
    }
    else if ((s16)kind == 7)
    {
        if (item <= 0x3F)
        {
            s32 res = 0;
            s16 mp = c->mp;
            s16 cost = sub_080ED6CC(item);

            if (b->unk11AA == 0 && (s16)who <= 15)
            {
                mp -= cost;
                if (mp < 0)
                    res = 1;
                else
                    c->mp = mp;
            }
            if (flags & 2)
                res = 2;
            if (res)
            {
                if (res == 2)
                    BattleMenu_SetModeAutoClose(3, gUnknown_081241B0);
                else
                    BattleMenu_SetModeAutoClose(3, gUnknown_081241D0);
                b->phase = 11;
                return;
            }
        }
    }
    else if ((s16)kind == 11)
    {
        if (b->unk11AA == 0 && (s16)who <= 15)
        {
            if (sub_080ED744((s16)who, item) != 1)
            {
                BattleMenu_SetModeAutoClose(3, gUnknown_081241E0);
                b->phase = (s16)kind;
                return;
            }
            sub_080ED6DC((s16)who, item);
        }
    }

    if ((s16)kind != 11 || (u32)(item - 0x54) > 0x13)
    {
        if (!sub_080EE028((s16)who, (s16)target))
        {
            if (!Battle_IsEnemyId((s16)who))
                BattleMenu_SetModeAutoClose(3, gUnknown_081230A8);
            else
                BattleMenu_SetModeAutoClose(3, Battle_BuildDodgeText(Battle_GetCombatant((s16)target + 0x8000)));
            b->phase = 10;
            sub_080F0344(3, 12);
            return;
        }
    }

    if ((u16)((s16)kind - 4) <= 1 || (s16)kind == 10)
    {
        b->unk97E = 0;
        b->phase = 5;
    }
    else if ((s16)kind == 8)
    {
        Item_GetAttribute(item, 0xC, &item);
        if (item > 0x7F)
            b->phase = (s16)kind;
        else if ((u32)(item - 0x1D) <= 0x22)
            b->phase = 7;
        else
        {
            b->unk97E = 0;
            b->phase = 5;
        }
    }
    else if ((u32)(item - 0x1D) <= 0x22)
        b->phase = 7;
    else
    {
        b->unk97E = 0;
        b->phase = 5;
    }
}
#else
NAKED void Battle_PayActionCost(struct F0CFCCombatant *c, u16 who)
{
    asm_unified(
        ".L080F0CFC:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #8\n"
        "    adds r6, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    ldr r7, .L080F0D40\n"
        "    adds r0, #0x5c\n"
        "    ldrb r0, [r0]\n"
        "    str r0, [sp]\n"
        "    movs r0, #0x17\n"
        "    ldrsb r0, [r6, r0]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    ldr r0, .L080F0D44\n"
        "    ldr r0, [r0]\n"
        "    movs r2, #0xae\n"
        "    lsls r2, r2, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r2, [r6, #0x10]\n"
        "    mov r8, r2\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r0, r2]\n"
        "    cmp r0, #0\n"
        "    bne .L080F0D48\n"
        "    lsls r4, r1, #0x10\n"
        "    asrs r0, r4, #0x10\n"
        "    bl sub_080F2C9C\n"
        "    b .L080F0D58\n"
        "    .byte 0x00, 0x00\n"
        ".L080F0D40: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080F0D44: .4byte 0x03006434 @ IWRAM+0x6434\n"
        ".L080F0D48:\n"
        "    lsls r4, r1, #0x10\n"
        "    asrs r0, r4, #0x10\n"
        "    ldr r2, .L080F0D84\n"
        "    adds r1, r7, r2\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r1, r2]\n"
        "    bl sub_080EFFF8\n"
        ".L080F0D58:\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #4]\n"
        "    mov sb, r4\n"
        "    lsls r0, r5, #0x10\n"
        "    asrs r5, r0, #0x10\n"
        "    mov sl, r0\n"
        "    cmp r5, #8\n"
        "    bne .L080F0D88\n"
        "    ldr r1, .L080F0D84\n"
        "    adds r0, r7, r1\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r0, r2]\n"
        "    cmp r0, #0\n"
        "    bne .L080F0E54\n"
        "    movs r1, #1\n"
        "    rsbs r1, r1, #0\n"
        "    ldr r0, [sp]\n"
        "    bl sub_080F3E54\n"
        "    b .L080F0E54\n"
        "    .byte 0x00, 0x00\n"
        ".L080F0D84: .4byte 0x00000F66\n"
        ".L080F0D88:\n"
        "    cmp r5, #7\n"
        "    bne .L080F0E0C\n"
        "    ldr r0, [sp]\n"
        "    cmp r0, #0x3f\n"
        "    bgt .L080F0E54\n"
        "    movs r5, #0\n"
        "    ldrh r4, [r6, #0x1c]\n"
        "    bl sub_080ED6CC\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    ldr r1, .L080F0DC8\n"
        "    adds r0, r7, r1\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L080F0DCE\n"
        "    mov r1, sb\n"
        "    asrs r0, r1, #0x10\n"
        "    cmp r0, #0xf\n"
        "    bgt .L080F0DCE\n"
        "    lsls r1, r4, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    lsls r0, r2, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    subs r1, r1, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r4, r1, #0x10\n"
        "    cmp r1, #0\n"
        "    bge .L080F0DCC\n"
        "    movs r5, #1\n"
        "    b .L080F0DCE\n"
        "    .byte 0x00, 0x00\n"
        ".L080F0DC8: .4byte 0x000011AA\n"
        ".L080F0DCC:\n"
        "    strh r4, [r6, #0x1c]\n"
        ".L080F0DCE:\n"
        "    movs r0, #2\n"
        "    mov r2, r8\n"
        "    ands r2, r0\n"
        "    cmp r2, #0\n"
        "    beq .L080F0DDA\n"
        "    movs r5, #2\n"
        ".L080F0DDA:\n"
        "    adds r0, r5, #0\n"
        "    cmp r0, #0\n"
        "    beq .L080F0E54\n"
        "    cmp r0, #2\n"
        "    bne .L080F0DF4\n"
        "    ldr r1, .L080F0DF0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    b .L080F0DFC\n"
        "    .byte 0x00, 0x00\n"
        ".L080F0DF0: .4byte gUnknown_081241B0\n"
        ".L080F0DF4:\n"
        "    ldr r1, .L080F0E04\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        ".L080F0DFC:\n"
        "    ldr r0, .L080F0E08\n"
        "    adds r1, r7, r0\n"
        "    movs r0, #0xb\n"
        "    b .L080F0F4E\n"
        ".L080F0E04: .4byte gUnknown_081241D0\n"
        ".L080F0E08: .4byte 0x0000097C\n"
        ".L080F0E0C:\n"
        "    cmp r5, #0xb\n"
        "    bne .L080F0E64\n"
        "    ldr r1, .L080F0E40\n"
        "    adds r0, r7, r1\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L080F0E54\n"
        "    mov r2, sb\n"
        "    asrs r4, r2, #0x10\n"
        "    cmp r4, #0xf\n"
        "    bgt .L080F0E54\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, [sp]\n"
        "    bl sub_080ED744\n"
        "    cmp r0, #1\n"
        "    beq .L080F0E4C\n"
        "    ldr r1, .L080F0E44\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    ldr r1, .L080F0E48\n"
        "    adds r0, r7, r1\n"
        "    strh r5, [r0]\n"
        "    b .L080F0F50\n"
        "    .byte 0x00, 0x00\n"
        ".L080F0E40: .4byte 0x000011AA\n"
        ".L080F0E44: .4byte gUnknown_081241E0\n"
        ".L080F0E48: .4byte 0x0000097C\n"
        ".L080F0E4C:\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, [sp]\n"
        "    bl sub_080ED6DC\n"
        ".L080F0E54:\n"
        "    mov r2, sl\n"
        "    asrs r0, r2, #0x10\n"
        "    cmp r0, #0xb\n"
        "    bne .L080F0E64\n"
        "    ldr r0, [sp]\n"
        "    subs r0, #0x54\n"
        "    cmp r0, #0x13\n"
        "    bls .L080F0EC8\n"
        ".L080F0E64:\n"
        "    mov r0, sb\n"
        "    asrs r4, r0, #0x10\n"
        "    ldr r1, [sp, #4]\n"
        "    lsls r0, r1, #0x10\n"
        "    asrs r5, r0, #0x10\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r5, #0\n"
        "    bl sub_080EE028\n"
        "    cmp r0, #0\n"
        "    bne .L080F0EC8\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_IsEnemyId\n"
        "    cmp r0, #0\n"
        "    bne .L080F0E94\n"
        "    ldr r1, .L080F0E90\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    b .L080F0EAC\n"
        "    .byte 0x00, 0x00\n"
        ".L080F0E90: .4byte gUnknown_081230A8\n"
        ".L080F0E94:\n"
        "    ldr r2, .L080F0EC0\n"
        "    adds r0, r5, r2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    bl Battle_BuildDodgeText\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        ".L080F0EAC:\n"
        "    ldr r0, .L080F0EC4\n"
        "    adds r1, r7, r0\n"
        "    movs r0, #0xa\n"
        "    strh r0, [r1]\n"
        "    movs r0, #3\n"
        "    movs r1, #0xc\n"
        "    bl sub_080F0344\n"
        "    b .L080F0F50\n"
        "    .byte 0x00, 0x00\n"
        ".L080F0EC0: .4byte 0xFFFF8000\n"
        ".L080F0EC4: .4byte 0x0000097C\n"
        ".L080F0EC8:\n"
        "    mov r1, sl\n"
        "    asrs r4, r1, #0x10\n"
        "    ldr r0, .L080F0EF8\n"
        "    add r0, sl\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bls .L080F0F40\n"
        "    cmp r4, #0xa\n"
        "    beq .L080F0F40\n"
        "    cmp r4, #8\n"
        "    bne .L080F0F2C\n"
        "    ldr r0, [sp]\n"
        "    movs r1, #0xc\n"
        "    mov r2, sp\n"
        "    bl Item_GetAttribute\n"
        "    ldr r0, [sp]\n"
        "    cmp r0, #0x7f\n"
        "    ble .L080F0F00\n"
        "    ldr r1, .L080F0EFC\n"
        "    adds r0, r7, r1\n"
        "    strh r4, [r0]\n"
        "    b .L080F0F50\n"
        "    .byte 0x00, 0x00\n"
        ".L080F0EF8: .4byte 0xFFFC0000\n"
        ".L080F0EFC: .4byte 0x0000097C\n"
        ".L080F0F00:\n"
        "    subs r0, #0x1d\n"
        "    cmp r0, #0x22\n"
        "    bhi .L080F0F14\n"
        "    ldr r2, .L080F0F10\n"
        "    adds r1, r7, r2\n"
        "    movs r0, #7\n"
        "    b .L080F0F4E\n"
        "    .byte 0x00, 0x00\n"
        ".L080F0F10: .4byte 0x0000097C\n"
        ".L080F0F14:\n"
        "    ldr r0, .L080F0F24\n"
        "    adds r1, r7, r0\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r2, .L080F0F28\n"
        "    adds r1, r7, r2\n"
        "    b .L080F0F4C\n"
        "    .byte 0x00, 0x00\n"
        ".L080F0F24: .4byte 0x0000097E\n"
        ".L080F0F28: .4byte 0x0000097C\n"
        ".L080F0F2C:\n"
        "    ldr r0, [sp]\n"
        "    subs r0, #0x1d\n"
        "    cmp r0, #0x22\n"
        "    bhi .L080F0F40\n"
        "    ldr r0, .L080F0F3C\n"
        "    adds r1, r7, r0\n"
        "    movs r0, #7\n"
        "    b .L080F0F4E\n"
        ".L080F0F3C: .4byte 0x0000097C\n"
        ".L080F0F40:\n"
        "    ldr r2, .L080F0F60\n"
        "    adds r1, r7, r2\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L080F0F64\n"
        "    adds r1, r7, r0\n"
        ".L080F0F4C:\n"
        "    movs r0, #5\n"
        ".L080F0F4E:\n"
        "    strh r0, [r1]\n"
        ".L080F0F50:\n"
        "    add sp, #8\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080F0F60: .4byte 0x0000097E\n"
        ".L080F0F64: .4byte 0x0000097C\n"
    );
}
#endif

// Battle_GetActionAnim @ 0x080F0F68
/* Entry b of row a of gUnknown_0876E1D8, with the special ids 0xDC-0xE8 mapped to skills
   (0xFF = none). */
u8 Battle_GetActionAnim(u16 a, u16 b)
{
    u8 v = gUnknown_0876E1D8[a].id[b];

    switch (v)
    {
    case 0xDD:
        v = 0x34;
        break;
    case 0xDE:
        v = 0x64;
        break;
    case 0xDF:
        v = 0x70;
        break;
    case 0xE1:
        v = 0x37;
        break;
    case 0xE2:
        v = 0x67;
        break;
    case 0xE4:
        v = 0x36;
        break;
    case 0xE5:
        v = 0x66;
        break;
    case 0xDC:
    case 0xE0:
    case 0xE3:
    case 0xE6:
        v = 0xFF;
        break;
    case 0xE7:
        v = 0x35;
        break;
    case 0xE8:
        v = 0x65;
        break;
    case 0xFE:
        break;
    }
    return v;
}
