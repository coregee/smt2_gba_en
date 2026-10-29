/* Battle: the turn of one combatant, as a phase machine (+0x97C) around the action steps. */

#include "global.h"

/* The battle EWRAM block at 0x0203C200: only the fields used here. */
struct F0434Battle
{
    u8 pad000[0x97C];
    s16 phase;          /* 0x97C */
    u8 pad97E[0x990 - 0x97E];
    u32 groups[2];      /* 0x990: demon id of each enemy group */
    u8 pad998[0xEC6 - 0x998];
    s16 anim;           /* 0xEC6: effect animation, 0xFF none, 0xF0-0xF7 summon/party effects */
    u8 padEC8[0xECA - 0xEC8];
    s16 sound;          /* 0xECA: 0xFF none */
    u8 padECC[0xF30 - 0xECC];
    s16 unkF30[16];     /* 0xF30: chosen ally target, by combatant */
    u8 padF50[0xF66 - 0xF50];
    s16 unkF66;         /* 0xF66: target-list entry being hit */
    u8 padF68[0x118C - 0xF68];
    u16 unk118C;        /* 0x118C */
    u8 pad118E[0x11AA - 0x118E];
    u16 unk11AA;        /* 0x11AA: targets hit so far (later ones are free) */
};
extern u8 gUnk_0203C200[];
#define BB ((struct F0434Battle *)gUnk_0203C200)

/* Battle state at 0x0203D16C, reached through gUnk_03006434: only the field used here. */
struct F0434State
{
    u8 pad000[0x15C];
    s32 targetCount;    /* 0x15C: number of targets, 0x8000 = all */
};
extern struct F0434State *gUnk_03006434;

/* The action being resolved (as struct Action in battle2.h). */
struct F0434Action
{
    s32 att;            /* 0x00 */
    s32 def;            /* 0x04 */
    s32 msg;            /* 0x08 */
    s32 result;         /* 0x0C */
    u8 pad10[0x18 - 0x10];
    s32 dmg;            /* 0x18 */
};
extern struct F0434Action gUnk_03000088;
extern s16 gUnk_03000080;   /* targets done */
extern s16 gUnk_030000A8;
extern s16 gUnk_030000AA;
extern u16 gUnk_030000AC;

/* One combatant (0x80 bytes): only the fields used here. */
struct F0434Combatant
{
    u8 pad00[0x10];
    u16 flags;          /* 0x10 */
    u8 pad12[0x17 - 0x12];
    s8 command;         /* 0x17 */
    u8 pad18[0x5C - 0x18];
    u8 chosen;          /* 0x5C */
};

extern const u16 gUnknown_08124264[];

struct F0434Combatant *Battle_GetCombatant(u16 idx);
s32 sub_080C35E4(s32 who);
u32 sub_080F0C18(struct F0434Combatant *c, s32 who);
s32 sub_080EF5FC(struct F0434Combatant *c, s32 who);
s16 sub_080F038C(s32 who, struct F0434Combatant *c);
void Battle_AnnounceAction(struct F0434Combatant *c, s32 who, s32 side);
u8 BattleMsg_IsDone(void);
u32 sub_080C2B6C(void);
void sub_080F4608(s32 kind, s32 arg);
s16 Battle_FindPartyPosition(s32 who);
void sub_080ECF70(s32 a);
void sub_080ECE08(s32 state);
void sub_080ECE38(s32 id, s32 x, s32 kind);
s32 Battle_IsEnemyId(s32 who);
void sub_080EC9AC(s32 anim, s32 side, s32 sound, s32 enemy);
u32 sub_080ECB10(void);
void Battle_PayActionCost(struct F0434Combatant *c, s32 who);
void Battle_ResolveActionStep(struct F0434Combatant *c, s32 who);
void Battle_CastSupportSkill(struct F0434Combatant *c, s32 who);
void Battle_UseItem(struct F0434Combatant *c, s32 who);
u32 sub_080EF0E4(s32 who);
void Combatant_ClearStatus(s32 who, u16 mask);
s32 Combatant_ChangeHp(s32 who, s32 delta);
u16 *Battle_GetMessage(s32 id);
s16 sub_080F3E44(void);
u16 *Menu_ExpandListTemplate(const u16 *tmpl, u32 arg);
void BattleMenu_SetModeAutoClose(u8 mode, const u16 *src);
u16 *Battle_BuildDefeatedTargetText(struct F0434Combatant *actor);
u16 *Battle_BuildNamePrependText(s32 idx, const u16 *suffix);
u32 Battle_IsPartyDefeated(void);
void BattleMsg_SetLocked(u8 locked);
void sub_080EF218(s32 a);
void sub_080F0344(u16 kind, u16 v);
u32 sub_080ED9F4(void);
u16 Combatant_GetStatus(s32 who);
u32 Battle_IsTwoSided(void);
s32 sub_080EFFF8(s32 who, s32 x);
u32 sub_080F03D8(s32 kind, s32 id);
u32 sub_080EDA24(s32 side);
u32 sub_080EDAD0(void);
u32 sub_080EDAEC(s32 id);
u32 sub_080E75DC(u8 slot, u8 mode);
u32 sub_080F0B78(s32 who);
void sub_080F0BEC(void);

// Battle_CombatantTurnStep @ 0x080F0434
/* One phase (+0x97C) of combatant who's turn; returns 1 when the turn is over.
    0 announce the action (Battle_AnnounceAction), 1 play its animation (party effects 0xF0-0xF7 on
      one member or all six), 2 wait for it, 3/4 pay for it (Battle_PayActionCost), 5 resolve it
      (Battle_ResolveActionStep), 7 cast a support skill, 8 use an item, 9 a target was defeated (or
      revived by an effect, message 0x171), 10 next target, 11 end of turn, 12 wait for the
      message then go to gUnk_030000AC, 13 enemy defeated: group bookkeeping, 14 sub_080F0BEC. */
#ifdef NONMATCHING
u32 Battle_CombatantTurnStep(s16 who)
{
    struct F0434Battle *b = BB;
    struct F0434Combatant *c = Battle_GetCombatant(who + 0x8000);
    u8 kind;

    if (who <= 15)
        kind = sub_080C35E4(who);
    else
        kind = c->command;
    switch (b->phase)
    {
    case 0:
    {
        s16 side;

        b->unkF66 = 0;
        b->unk11AA = 0;
        gUnk_03000080 = 0;
        if ((s16)sub_080F0C18(c, who) == 1)
            break;
        gUnk_03006434->targetCount = sub_080EF5FC(c, who);
        side = sub_080F038C(who, c);
        if (c->command == 9)
            goto endTurn;
        Battle_AnnounceAction(c, who, side);
        break;
    }
    case 1:
        if (BattleMsg_IsDone() != 1)
            break;
        if (gUnk_030000AA != 0xFF && (u16)sub_080C2B6C() != 1)
            sub_080F4608(gUnk_030000AA, 0);
        if (b->anim != 0xFF && b->anim > 0xD2)
        {
            s16 pos = Battle_FindPartyPosition(b->unkF30[who]);
            s16 i;

            if (b->sound != 0xFF)
                sub_080ECF70(b->sound);
            if (pos == -1 && (u16)(b->anim - 0xF0) <= 3)
                goto skipAnim;
            if (b->unkF30[who] == -1)
                pos = Battle_FindPartyPosition(who);
            switch ((s16)(b->anim - 0xF0))
            {
            case 0:
                sub_080ECE08(4);
                sub_080ECE38(pos, 0, 3);
                break;
            case 1:
                sub_080ECE08(4);
                sub_080ECE38(pos, 0, 0);
                break;
            case 2:
                sub_080ECE08(4);
                sub_080ECE38(pos, 0, 5);
                break;
            case 3:
                sub_080ECE08(4);
                sub_080ECE38(pos, 0, 1);
                break;
            case 4:
                sub_080ECE08(5);
                for (i = 0; i <= 5; i++)
                    sub_080ECE38(i, i * 8, 3);
                break;
            case 5:
                sub_080ECE08(5);
                for (i = 0; i <= 5; i++)
                    sub_080ECE38(i, i * 8, 0);
                break;
            case 6:
                sub_080ECE08(5);
                for (i = 0; i <= 5; i++)
                    sub_080ECE38(i, i * 8, 5);
                break;
            case 7:
                sub_080ECE08(5);
                for (i = 0; i <= 5; i++)
                    sub_080ECE38(i, i * 8, 1);
                break;
            }
            b->phase = 2;
        }
        else if (b->anim != 0xFF)
        {
            sub_080EC9AC(b->anim, gUnk_030000A8, b->sound, (s16)Battle_IsEnemyId(who));
            b->phase = 2;
        }
        else
        {
            if (b->sound != 0xFF)
                sub_080ECF70(b->sound);
        skipAnim:
            b->phase = 3;
        }
        break;
    case 2:
        if (sub_080ECB10())
            b->phase = 4;
        break;
    case 3:
    case 4:
        Battle_PayActionCost(c, who);
        break;
    case 5:
        Battle_ResolveActionStep(c, who);
        break;
    case 7:
        Battle_CastSupportSkill(c, who);
        break;
    case 8:
        Battle_UseItem(c, who);
        break;
    case 9:
    {
        u16 d = gUnk_03000088.def;
        s16 def = gUnk_03000088.def;

        if (sub_080EF0E4(def))
        {
            Combatant_ClearStatus(def, 0x7FFF);
            Combatant_ChangeHp(def, gUnk_03000088.dmg);
            BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(Battle_GetMessage(0x171), sub_080F3E44() << 16));
            goto nextTarget;
        }
        if (Battle_IsEnemyId(def) == 1)
        {
            BattleMenu_SetModeAutoClose(3, Battle_BuildDefeatedTargetText(Battle_GetCombatant(def + 0x8000)));
            sub_080ECF70(0x12F);
        }
        else
        {
            s32 se = 0x12E;
            struct F0434Combatant *u;
            u16 flags;

            if (def <= 3)
                se = 0x12D;
            u = Battle_GetCombatant(def + 0x8000);
            flags = u->flags;
            u->flags = flags | 0x8000;
            if (Battle_IsPartyDefeated() == 1)
                BattleMsg_SetLocked(0);
            u->flags = flags;
            BattleMenu_SetModeAutoClose(3, Battle_BuildNamePrependText(def + 0x8000, gUnknown_08124264));
            sub_080ECF70(se);
        }
        sub_080EF218((s16)d);
        if ((s16)d <= 15)
            goto nextTarget;
        b->phase = 13;
        break;
    }
    case 10:
    {
        u16 dead;

        if (!sub_080ED9F4() || Battle_IsPartyDefeated() == 1)
            goto endTurn;
        gUnk_03000080++;
        b->unkF66++;
        b->unk11AA++;
        b->phase = 3;
        dead = Combatant_GetStatus(who) & 0x8000;
        if (dead)
        {
            b->phase = 11;
            break;
        }
        if (Battle_IsTwoSided()
            && gUnk_03006434->targetCount > gUnk_03000080
            && sub_080EFFF8(who, b->unkF66) == -1
            && gUnk_03006434->targetCount != 0x8000)
        {
            b->unkF66 = dead;
            sub_080F038C(who, c);
            if (gUnk_03006434->targetCount <= gUnk_03000080)
                b->phase = 11;
            break;
        }
        if (((u8)(kind - 4) <= 1 || (s8)kind == 10 || sub_080F03D8((s8)kind, c->chosen) == 1)
            && gUnk_03006434->targetCount != 0x8000)
        {
            if (sub_080EFFF8(who, b->unkF66) == -1)
                b->unkF66 = 0;
        }
        else
        {
            if (gUnk_03006434->targetCount <= b->unkF66)
                b->phase = 11;
            if (sub_080EFFF8(who, b->unkF66) == -1)
                b->phase = 11;
        }
        if (gUnk_03006434->targetCount > gUnk_03000080)
            break;
    endTurn:
        b->phase = 11;
        break;
    }
    case 11:
        if (BattleMsg_IsDone() == 1)
        {
            if (Battle_IsTwoSided() && b->unk118C == 0 && (!sub_080EDA24(0) || !sub_080EDA24(1)))
            {
                b->phase = 14;
                sub_080F0344(3, 12);
            }
            else
                return 1;
        }
        break;
    case 12:
        if (BattleMsg_IsDone() == 1)
            b->phase = gUnk_030000AC;
        break;
    case 13:
        if (!sub_080EDAD0() || sub_080EDAEC(b->groups[0]))
        {
            u16 def = gUnk_03000088.def;

            if ((u8)sub_080E75DC(def - 0x10, 2))
                break;
            if (sub_080F0B78((s16)def) == 1)
            {
                b->phase = 14;
                sub_080F0344(3, 12);
                break;
            }
        }
    nextTarget:
        b->phase = 10;
        sub_080F0344(3, 12);
        break;
    case 14:
        sub_080F0BEC();
        break;
    }
    return 0;
}
#else
NAKED u32 Battle_CombatantTurnStep(s16 who)
{
    asm_unified(
        ".L080F0434:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0xc\n"
        "    lsls r0, r0, #0x10\n"
        "    ldr r1, .L080F046C\n"
        "    mov sl, r1\n"
        "    lsrs r4, r0, #0x10\n"
        "    asrs r5, r0, #0x10\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #0x18\n"
        "    adds r0, r0, r2\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    adds r6, r0, #0\n"
        "    cmp r5, #0xf\n"
        "    bgt .L080F0470\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080C35E4\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    str r0, [sp]\n"
        "    b .L080F0474\n"
        "    .byte 0x00, 0x00\n"
        ".L080F046C: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080F0470:\n"
        "    ldrb r3, [r6, #0x17]\n"
        "    str r3, [sp]\n"
        ".L080F0474:\n"
        "    ldr r0, .L080F048C\n"
        "    add r0, sl\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    cmp r0, #0xf\n"
        "    bls .L080F0482\n"
        "    b .L080F0B64\n"
        ".L080F0482:\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L080F0490\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        ".L080F048C: .4byte 0x0000097C\n"
        ".L080F0490: .4byte gUnknown_080F0494\n"
        "    .global gUnknown_080F0494\n"
        "gUnknown_080F0494:\n"
        ".L080F0494: @ jump table\n"
        "    .4byte .L080F04D4\n"
        "    .4byte .L080F0544\n"
        "    .4byte .L080F0784\n"
        "    .4byte .L080F079C\n"
        "    .4byte .L080F079C\n"
        "    .4byte .L080F07A8\n"
        "    .4byte .L080F0B64\n"
        "    .4byte .L080F07B4\n"
        "    .4byte .L080F07C0\n"
        "    .4byte .L080F07CC\n"
        "    .4byte .L080F08D4\n"
        "    .4byte .L080F0A94\n"
        "    .4byte .L080F0ADC\n"
        "    .4byte .L080F0AFC\n"
        "    .4byte .L080F0B60\n"
        "    .4byte .L080F0B64\n"
        ".L080F04D4:\n"
        "    ldr r0, .L080F0534\n"
        "    add r0, sl\n"
        "    movs r1, #0\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L080F0538\n"
        "    add r0, sl\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L080F053C\n"
        "    strh r1, [r0]\n"
        "    lsls r0, r4, #0x10\n"
        "    asrs r4, r0, #0x10\n"
        "    adds r0, r6, #0\n"
        "    adds r1, r4, #0\n"
        "    bl sub_080F0C18\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bne .L080F04FC\n"
        "    b .L080F0B64\n"
        ".L080F04FC:\n"
        "    adds r0, r6, #0\n"
        "    adds r1, r4, #0\n"
        "    bl sub_080EF5FC\n"
        "    ldr r1, .L080F0540\n"
        "    ldr r1, [r1]\n"
        "    movs r2, #0xae\n"
        "    lsls r2, r2, #1\n"
        "    adds r1, r1, r2\n"
        "    str r0, [r1]\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r6, #0\n"
        "    bl sub_080F038C\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    movs r0, #0x17\n"
        "    ldrsb r0, [r6, r0]\n"
        "    cmp r0, #9\n"
        "    bne .L080F0526\n"
        "    b .L080F0A78\n"
        ".L080F0526:\n"
        "    lsls r2, r2, #0x10\n"
        "    asrs r2, r2, #0x10\n"
        "    adds r0, r6, #0\n"
        "    adds r1, r4, #0\n"
        "    bl Battle_AnnounceAction\n"
        "    b .L080F0B64\n"
        ".L080F0534: .4byte 0x00000F66\n"
        ".L080F0538: .4byte 0x000011AA\n"
        ".L080F053C: .4byte 0x03000080 @ IWRAM+0x80\n"
        ".L080F0540: .4byte 0x03006434 @ IWRAM+0x6434\n"
        ".L080F0544:\n"
        "    bl BattleMsg_IsDone\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    beq .L080F0552\n"
        "    b .L080F0B64\n"
        ".L080F0552:\n"
        "    ldr r5, .L080F0610\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r5, r3]\n"
        "    cmp r0, #0xff\n"
        "    beq .L080F0572\n"
        "    bl sub_080C2B6C\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    beq .L080F0572\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r5, r1]\n"
        "    movs r1, #0\n"
        "    bl sub_080F4608\n"
        ".L080F0572:\n"
        "    ldr r5, .L080F0614\n"
        "    add r5, sl\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r5, r2]\n"
        "    cmp r0, #0xff\n"
        "    bne .L080F0580\n"
        "    b .L080F0760\n"
        ".L080F0580:\n"
        "    cmp r0, #0xd2\n"
        "    bgt .L080F0586\n"
        "    b .L080F0720\n"
        ".L080F0586:\n"
        "    lsls r4, r4, #0x10\n"
        "    asrs r1, r4, #0xf\n"
        "    movs r0, #0xf3\n"
        "    lsls r0, r0, #4\n"
        "    add r0, sl\n"
        "    adds r0, r0, r1\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r0, r3]\n"
        "    bl Battle_FindPartyPosition\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldr r1, .L080F0618\n"
        "    add r1, sl\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r1, r2]\n"
        "    str r4, [sp, #8]\n"
        "    cmp r0, #0xff\n"
        "    beq .L080F05B4\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r1, r3]\n"
        "    bl sub_080ECF70\n"
        ".L080F05B4:\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    movs r1, #1\n"
        "    rsbs r1, r1, #0\n"
        "    cmp r0, r1\n"
        "    bne .L080F05CE\n"
        "    ldrh r0, [r5]\n"
        "    subs r0, #0xf0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #3\n"
        "    bhi .L080F05CE\n"
        "    b .L080F0770\n"
        ".L080F05CE:\n"
        "    ldr r0, [sp, #8]\n"
        "    asrs r4, r0, #0x10\n"
        "    lsls r1, r4, #1\n"
        "    movs r0, #0xf3\n"
        "    lsls r0, r0, #4\n"
        "    add r0, sl\n"
        "    adds r0, r0, r1\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r0, r2]\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r1, r0\n"
        "    bne .L080F05F2\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_FindPartyPosition\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        ".L080F05F2:\n"
        "    ldr r0, .L080F0614\n"
        "    add r0, sl\n"
        "    ldrh r0, [r0]\n"
        "    subs r0, #0xf0\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #7\n"
        "    bls .L080F0604\n"
        "    b .L080F0748\n"
        ".L080F0604:\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L080F061C\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080F0610: .4byte 0x030000AA @ IWRAM+0xAA\n"
        ".L080F0614: .4byte 0x00000EC6\n"
        ".L080F0618: .4byte 0x00000ECA\n"
        ".L080F061C: .4byte gUnknown_080F0620\n"
        "    .global gUnknown_080F0620\n"
        "gUnknown_080F0620:\n"
        ".L080F0620: @ jump table\n"
        "    .4byte .L080F0640\n"
        "    .4byte .L080F0654\n"
        "    .4byte .L080F0668\n"
        "    .4byte .L080F067C\n"
        "    .4byte .L080F0690\n"
        "    .4byte .L080F06B4\n"
        "    .4byte .L080F06D8\n"
        "    .4byte .L080F06FC\n"
        ".L080F0640:\n"
        "    movs r0, #4\n"
        "    bl sub_080ECE08\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    movs r1, #0\n"
        "    movs r2, #3\n"
        "    bl sub_080ECE38\n"
        "    b .L080F0748\n"
        ".L080F0654:\n"
        "    movs r0, #4\n"
        "    bl sub_080ECE08\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    bl sub_080ECE38\n"
        "    b .L080F0748\n"
        ".L080F0668:\n"
        "    movs r0, #4\n"
        "    bl sub_080ECE08\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    movs r1, #0\n"
        "    movs r2, #5\n"
        "    bl sub_080ECE38\n"
        "    b .L080F0748\n"
        ".L080F067C:\n"
        "    movs r0, #4\n"
        "    bl sub_080ECE08\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    movs r1, #0\n"
        "    movs r2, #1\n"
        "    bl sub_080ECE38\n"
        "    b .L080F0748\n"
        ".L080F0690:\n"
        "    movs r0, #5\n"
        "    bl sub_080ECE08\n"
        "    movs r0, #0\n"
        ".L080F0698:\n"
        "    lsls r4, r0, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    lsls r1, r4, #3\n"
        "    adds r0, r4, #0\n"
        "    movs r2, #3\n"
        "    bl sub_080ECE38\n"
        "    adds r4, #1\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r0, r4, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    cmp r4, #5\n"
        "    ble .L080F0698\n"
        "    b .L080F0748\n"
        ".L080F06B4:\n"
        "    movs r0, #5\n"
        "    bl sub_080ECE08\n"
        "    movs r0, #0\n"
        ".L080F06BC:\n"
        "    lsls r4, r0, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    lsls r1, r4, #3\n"
        "    adds r0, r4, #0\n"
        "    movs r2, #0\n"
        "    bl sub_080ECE38\n"
        "    adds r4, #1\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r0, r4, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    cmp r4, #5\n"
        "    ble .L080F06BC\n"
        "    b .L080F0748\n"
        ".L080F06D8:\n"
        "    movs r0, #5\n"
        "    bl sub_080ECE08\n"
        "    movs r0, #0\n"
        ".L080F06E0:\n"
        "    lsls r4, r0, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    lsls r1, r4, #3\n"
        "    adds r0, r4, #0\n"
        "    movs r2, #5\n"
        "    bl sub_080ECE38\n"
        "    adds r4, #1\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r0, r4, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    cmp r4, #5\n"
        "    ble .L080F06E0\n"
        "    b .L080F0748\n"
        ".L080F06FC:\n"
        "    movs r0, #5\n"
        "    bl sub_080ECE08\n"
        "    movs r0, #0\n"
        ".L080F0704:\n"
        "    lsls r4, r0, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    lsls r1, r4, #3\n"
        "    adds r0, r4, #0\n"
        "    movs r2, #1\n"
        "    bl sub_080ECE38\n"
        "    adds r4, #1\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r0, r4, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    cmp r4, #5\n"
        "    ble .L080F0704\n"
        "    b .L080F0748\n"
        ".L080F0720:\n"
        "    cmp r0, #0xff\n"
        "    beq .L080F0760\n"
        "    lsls r0, r4, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    bl Battle_IsEnemyId\n"
        "    adds r3, r0, #0\n"
        "    movs r4, #0\n"
        "    ldrsh r0, [r5, r4]\n"
        "    ldr r1, .L080F0754\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r1, r2]\n"
        "    ldr r2, .L080F0758\n"
        "    add r2, sl\n"
        "    movs r4, #0\n"
        "    ldrsh r2, [r2, r4]\n"
        "    lsls r3, r3, #0x10\n"
        "    asrs r3, r3, #0x10\n"
        "    bl sub_080EC9AC\n"
        ".L080F0748:\n"
        "    ldr r1, .L080F075C\n"
        "    add r1, sl\n"
        "    movs r0, #2\n"
        "    strh r0, [r1]\n"
        "    b .L080F0B64\n"
        "    .byte 0x00, 0x00\n"
        ".L080F0754: .4byte 0x030000A8 @ IWRAM+0xA8\n"
        ".L080F0758: .4byte 0x00000ECA\n"
        ".L080F075C: .4byte 0x0000097C\n"
        ".L080F0760:\n"
        "    ldr r1, .L080F077C\n"
        "    add r1, sl\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r1, r2]\n"
        "    cmp r0, #0xff\n"
        "    beq .L080F0770\n"
        "    bl sub_080ECF70\n"
        ".L080F0770:\n"
        "    ldr r1, .L080F0780\n"
        "    add r1, sl\n"
        "    movs r0, #3\n"
        "    strh r0, [r1]\n"
        "    b .L080F0B64\n"
        "    .byte 0x00, 0x00\n"
        ".L080F077C: .4byte 0x00000ECA\n"
        ".L080F0780: .4byte 0x0000097C\n"
        ".L080F0784:\n"
        "    bl sub_080ECB10\n"
        "    cmp r0, #0\n"
        "    bne .L080F078E\n"
        "    b .L080F0B64\n"
        ".L080F078E:\n"
        "    ldr r1, .L080F0798\n"
        "    add r1, sl\n"
        "    movs r0, #4\n"
        "    strh r0, [r1]\n"
        "    b .L080F0B64\n"
        ".L080F0798: .4byte 0x0000097C\n"
        ".L080F079C:\n"
        "    lsls r1, r4, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    adds r0, r6, #0\n"
        "    bl Battle_PayActionCost\n"
        "    b .L080F0B64\n"
        ".L080F07A8:\n"
        "    lsls r1, r4, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    adds r0, r6, #0\n"
        "    bl Battle_ResolveActionStep\n"
        "    b .L080F0B64\n"
        ".L080F07B4:\n"
        "    lsls r1, r4, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    adds r0, r6, #0\n"
        "    bl Battle_CastSupportSkill\n"
        "    b .L080F0B64\n"
        ".L080F07C0:\n"
        "    lsls r1, r4, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    adds r0, r6, #0\n"
        "    bl Battle_UseItem\n"
        "    b .L080F0B64\n"
        ".L080F07CC:\n"
        "    ldr r5, .L080F0810\n"
        "    ldrh r6, [r5, #4]\n"
        "    movs r0, #4\n"
        "    ldrsh r4, [r5, r0]\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080EF0E4\n"
        "    cmp r0, #0\n"
        "    beq .L080F081C\n"
        "    ldr r1, .L080F0814\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_ClearStatus\n"
        "    ldr r1, [r5, #0x18]\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_ChangeHp\n"
        "    ldr r0, .L080F0818\n"
        "    bl Battle_GetMessage\n"
        "    adds r4, r0, #0\n"
        "    bl sub_080F3E44\n"
        "    adds r1, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    b .L080F0B48\n"
        "    .byte 0x00, 0x00\n"
        ".L080F0810: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F0814: .4byte 0x00007FFF\n"
        ".L080F0818: .4byte 0x00000171\n"
        ".L080F081C:\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_IsEnemyId\n"
        "    cmp r0, #1\n"
        "    bne .L080F0850\n"
        "    ldr r1, .L080F0848\n"
        "    adds r0, r4, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    bl Battle_BuildDefeatedTargetText\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    ldr r0, .L080F084C\n"
        "    bl sub_080ECF70\n"
        "    b .L080F08A8\n"
        "    .byte 0x00, 0x00\n"
        ".L080F0848: .4byte 0xFFFF8000\n"
        ".L080F084C: .4byte 0x0000012F\n"
        ".L080F0850:\n"
        "    movs r2, #0x97\n"
        "    lsls r2, r2, #1\n"
        "    mov r8, r2\n"
        "    cmp r4, #3\n"
        "    bgt .L080F085E\n"
        "    ldr r3, .L080F08C4\n"
        "    mov r8, r3\n"
        ".L080F085E:\n"
        "    ldr r1, .L080F08C8\n"
        "    adds r0, r4, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    adds r5, r0, #0\n"
        "    ldrh r7, [r5, #0x10]\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #8\n"
        "    adds r1, r2, #0\n"
        "    adds r0, r7, #0\n"
        "    orrs r0, r1\n"
        "    strh r0, [r5, #0x10]\n"
        "    bl Battle_IsPartyDefeated\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bne .L080F088C\n"
        "    movs r0, #0\n"
        "    bl BattleMsg_SetLocked\n"
        ".L080F088C:\n"
        "    strh r7, [r5, #0x10]\n"
        "    movs r3, #0x80\n"
        "    lsls r3, r3, #8\n"
        "    adds r0, r4, r3\n"
        "    ldr r1, .L080F08CC\n"
        "    bl Battle_BuildNamePrependText\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    mov r0, r8\n"
        "    bl sub_080ECF70\n"
        ".L080F08A8:\n"
        "    lsls r4, r6, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080EF218\n"
        "    cmp r4, #0xf\n"
        "    bgt .L080F08B8\n"
        "    b .L080F0B48\n"
        ".L080F08B8:\n"
        "    ldr r1, .L080F08D0\n"
        "    add r1, sl\n"
        "    movs r0, #0xd\n"
        "    strh r0, [r1]\n"
        "    b .L080F0B64\n"
        "    .byte 0x00, 0x00\n"
        ".L080F08C4: .4byte 0x0000012D\n"
        ".L080F08C8: .4byte 0xFFFF8000\n"
        ".L080F08CC: .4byte gUnknown_08124264\n"
        ".L080F08D0: .4byte 0x0000097C\n"
        ".L080F08D4:\n"
        "    bl sub_080ED9F4\n"
        "    cmp r0, #0\n"
        "    bne .L080F08DE\n"
        "    b .L080F0A78\n"
        ".L080F08DE:\n"
        "    bl Battle_IsPartyDefeated\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bne .L080F08EC\n"
        "    b .L080F0A78\n"
        ".L080F08EC:\n"
        "    ldr r1, .L080F0938\n"
        "    ldrh r0, [r1]\n"
        "    adds r0, #1\n"
        "    strh r0, [r1]\n"
        "    ldr r7, .L080F093C\n"
        "    add r7, sl\n"
        "    ldrh r0, [r7]\n"
        "    adds r0, #1\n"
        "    strh r0, [r7]\n"
        "    ldr r1, .L080F0940\n"
        "    add r1, sl\n"
        "    ldrh r0, [r1]\n"
        "    adds r0, #1\n"
        "    strh r0, [r1]\n"
        "    ldr r2, .L080F0944\n"
        "    add r2, sl\n"
        "    mov sb, r2\n"
        "    movs r0, #3\n"
        "    strh r0, [r2]\n"
        "    lsls r4, r4, #0x10\n"
        "    asrs r5, r4, #0x10\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_GetStatus\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    ands r1, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #4]\n"
        "    str r4, [sp, #8]\n"
        "    cmp r1, #0\n"
        "    beq .L080F0948\n"
        "    movs r0, #0xb\n"
        "    mov r3, sb\n"
        "    strh r0, [r3]\n"
        "    b .L080F0B64\n"
        "    .byte 0x00, 0x00\n"
        ".L080F0938: .4byte 0x03000080 @ IWRAM+0x80\n"
        ".L080F093C: .4byte 0x00000F66\n"
        ".L080F0940: .4byte 0x000011AA\n"
        ".L080F0944: .4byte 0x0000097C\n"
        ".L080F0948:\n"
        "    bl Battle_IsTwoSided\n"
        "    cmp r0, #0\n"
        "    beq .L080F09BC\n"
        "    ldr r4, .L080F09B4\n"
        "    mov r8, r4\n"
        "    ldr r0, [r4]\n"
        "    movs r4, #0xae\n"
        "    lsls r4, r4, #1\n"
        "    adds r0, r0, r4\n"
        "    ldr r2, .L080F09B8\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r2, r3]\n"
        "    ldr r0, [r0]\n"
        "    cmp r0, r1\n"
        "    ble .L080F09BC\n"
        "    movs r0, #0\n"
        "    ldrsh r1, [r7, r0]\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080EFFF8\n"
        "    movs r1, #1\n"
        "    rsbs r1, r1, #0\n"
        "    cmp r0, r1\n"
        "    bne .L080F09BC\n"
        "    mov r1, r8\n"
        "    ldr r0, [r1]\n"
        "    adds r0, r0, r4\n"
        "    ldr r0, [r0]\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #8\n"
        "    cmp r0, r2\n"
        "    beq .L080F09BC\n"
        "    mov r3, sp\n"
        "    ldrh r3, [r3, #4]\n"
        "    strh r3, [r7]\n"
        "    adds r0, r5, #0\n"
        "    adds r1, r6, #0\n"
        "    bl sub_080F038C\n"
        "    mov r1, r8\n"
        "    ldr r0, [r1]\n"
        "    adds r0, r0, r4\n"
        "    ldr r2, .L080F09B8\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r2, r3]\n"
        "    ldr r0, [r0]\n"
        "    cmp r0, r1\n"
        "    ble .L080F09AC\n"
        "    b .L080F0B64\n"
        ".L080F09AC:\n"
        "    movs r0, #0xb\n"
        "    mov r4, sb\n"
        "    strh r0, [r4]\n"
        "    b .L080F0B64\n"
        ".L080F09B4: .4byte 0x03006434 @ IWRAM+0x6434\n"
        ".L080F09B8: .4byte 0x03000080 @ IWRAM+0x80\n"
        ".L080F09BC:\n"
        "    ldr r1, [sp]\n"
        "    lsls r0, r1, #0x18\n"
        "    asrs r2, r0, #0x18\n"
        "    movs r3, #0xfc\n"
        "    lsls r3, r3, #0x18\n"
        "    adds r0, r0, r3\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bls .L080F09E2\n"
        "    cmp r2, #0xa\n"
        "    beq .L080F09E2\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x5c\n"
        "    ldrb r1, [r0]\n"
        "    adds r0, r2, #0\n"
        "    bl sub_080F03D8\n"
        "    cmp r0, #1\n"
        "    bne .L080F0A2C\n"
        ".L080F09E2:\n"
        "    ldr r6, .L080F0A20\n"
        "    ldr r0, [r6]\n"
        "    movs r5, #0xae\n"
        "    lsls r5, r5, #1\n"
        "    adds r0, r0, r5\n"
        "    ldr r1, [r0]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #8\n"
        "    cmp r1, r0\n"
        "    beq .L080F0A2C\n"
        "    ldr r4, [sp, #8]\n"
        "    asrs r0, r4, #0x10\n"
        "    ldr r4, .L080F0A24\n"
        "    add r4, sl\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r4, r2]\n"
        "    bl sub_080EFFF8\n"
        "    movs r1, #1\n"
        "    rsbs r1, r1, #0\n"
        "    cmp r0, r1\n"
        "    bne .L080F0A12\n"
        "    movs r0, #0\n"
        "    strh r0, [r4]\n"
        ".L080F0A12:\n"
        "    ldr r0, [r6]\n"
        "    adds r0, r0, r5\n"
        "    ldr r1, .L080F0A28\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r1, r3]\n"
        "    b .L080F0A72\n"
        "    .byte 0x00, 0x00\n"
        ".L080F0A20: .4byte 0x03006434 @ IWRAM+0x6434\n"
        ".L080F0A24: .4byte 0x00000F66\n"
        ".L080F0A28: .4byte 0x03000080 @ IWRAM+0x80\n"
        ".L080F0A2C:\n"
        "    ldr r5, .L080F0A84\n"
        "    ldr r0, [r5]\n"
        "    movs r4, #0xae\n"
        "    lsls r4, r4, #1\n"
        "    adds r0, r0, r4\n"
        "    ldr r2, .L080F0A88\n"
        "    add r2, sl\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r2, r3]\n"
        "    ldr r0, [r0]\n"
        "    cmp r0, r1\n"
        "    bgt .L080F0A4C\n"
        "    ldr r1, .L080F0A8C\n"
        "    add r1, sl\n"
        "    movs r0, #0xb\n"
        "    strh r0, [r1]\n"
        ".L080F0A4C:\n"
        "    ldr r1, [sp, #8]\n"
        "    asrs r0, r1, #0x10\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r2, r3]\n"
        "    bl sub_080EFFF8\n"
        "    movs r1, #1\n"
        "    rsbs r1, r1, #0\n"
        "    cmp r0, r1\n"
        "    bne .L080F0A68\n"
        "    ldr r1, .L080F0A8C\n"
        "    add r1, sl\n"
        "    movs r0, #0xb\n"
        "    strh r0, [r1]\n"
        ".L080F0A68:\n"
        "    ldr r0, [r5]\n"
        "    adds r0, r0, r4\n"
        "    ldr r1, .L080F0A90\n"
        "    movs r4, #0\n"
        "    ldrsh r1, [r1, r4]\n"
        ".L080F0A72:\n"
        "    ldr r0, [r0]\n"
        "    cmp r0, r1\n"
        "    bgt .L080F0B64\n"
        ".L080F0A78:\n"
        "    ldr r1, .L080F0A8C\n"
        "    add r1, sl\n"
        "    movs r0, #0xb\n"
        "    strh r0, [r1]\n"
        "    b .L080F0B64\n"
        "    .byte 0x00, 0x00\n"
        ".L080F0A84: .4byte 0x03006434 @ IWRAM+0x6434\n"
        ".L080F0A88: .4byte 0x00000F66\n"
        ".L080F0A8C: .4byte 0x0000097C\n"
        ".L080F0A90: .4byte 0x03000080 @ IWRAM+0x80\n"
        ".L080F0A94:\n"
        "    bl BattleMsg_IsDone\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bne .L080F0B64\n"
        "    bl Battle_IsTwoSided\n"
        "    cmp r0, #0\n"
        "    beq .L080F0AD8\n"
        "    ldr r0, .L080F0AD0\n"
        "    add r0, sl\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L080F0AD8\n"
        "    movs r0, #0\n"
        "    bl sub_080EDA24\n"
        "    cmp r0, #0\n"
        "    beq .L080F0AC6\n"
        "    movs r0, #1\n"
        "    bl sub_080EDA24\n"
        "    cmp r0, #0\n"
        "    bne .L080F0AD8\n"
        ".L080F0AC6:\n"
        "    ldr r1, .L080F0AD4\n"
        "    add r1, sl\n"
        "    movs r0, #0xe\n"
        "    b .L080F0B4E\n"
        "    .byte 0x00, 0x00\n"
        ".L080F0AD0: .4byte 0x0000118C\n"
        ".L080F0AD4: .4byte 0x0000097C\n"
        ".L080F0AD8:\n"
        "    movs r0, #1\n"
        "    b .L080F0B66\n"
        ".L080F0ADC:\n"
        "    bl BattleMsg_IsDone\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bne .L080F0B64\n"
        "    ldr r0, .L080F0AF4\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L080F0AF8\n"
        "    add r0, sl\n"
        "    strh r1, [r0]\n"
        "    b .L080F0B64\n"
        ".L080F0AF4: .4byte 0x030000AC @ IWRAM+0xAC\n"
        ".L080F0AF8: .4byte 0x0000097C\n"
        ".L080F0AFC:\n"
        "    bl sub_080EDAD0\n"
        "    cmp r0, #0\n"
        "    beq .L080F0B14\n"
        "    movs r0, #0x99\n"
        "    lsls r0, r0, #4\n"
        "    add r0, sl\n"
        "    ldr r0, [r0]\n"
        "    bl sub_080EDAEC\n"
        "    cmp r0, #0\n"
        "    beq .L080F0B48\n"
        ".L080F0B14:\n"
        "    ldr r0, .L080F0B40\n"
        "    ldrh r6, [r0, #4]\n"
        "    adds r0, r6, #0\n"
        "    subs r0, #0x10\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    movs r1, #2\n"
        "    bl sub_080E75DC\n"
        "    lsls r0, r0, #0x18\n"
        "    cmp r0, #0\n"
        "    bne .L080F0B64\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    bl sub_080F0B78\n"
        "    cmp r0, #1\n"
        "    bne .L080F0B48\n"
        "    ldr r1, .L080F0B44\n"
        "    add r1, sl\n"
        "    movs r0, #0xe\n"
        "    b .L080F0B4E\n"
        ".L080F0B40: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F0B44: .4byte 0x0000097C\n"
        ".L080F0B48:\n"
        "    ldr r1, .L080F0B5C\n"
        "    add r1, sl\n"
        "    movs r0, #0xa\n"
        ".L080F0B4E:\n"
        "    strh r0, [r1]\n"
        "    movs r0, #3\n"
        "    movs r1, #0xc\n"
        "    bl sub_080F0344\n"
        "    b .L080F0B64\n"
        "    .byte 0x00, 0x00\n"
        ".L080F0B5C: .4byte 0x0000097C\n"
        ".L080F0B60:\n"
        "    bl sub_080F0BEC\n"
        ".L080F0B64:\n"
        "    movs r0, #0\n"
        ".L080F0B66:\n"
        "    add sp, #0xc\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif
