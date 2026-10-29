/* Battle: casting a non-damage skill and using an item, with their result messages. */

#include "global.h"

/* The battle EWRAM block at 0x0203C200: only the fields used here. */
struct F2514Battle
{
    u8 pad000[0x97C];
    u16 phase;          /* 0x97C */
    u8 pad97E[0xF30 - 0x97E];
    s16 unkF30[16];     /* 0xF30: target chosen for a self/ally skill, by combatant */
    u8 padF50[0xF66 - 0xF50];
    s16 unkF66;         /* 0xF66: chosen entry of the target list */
    u8 padF68[0x1192 - 0xF68];
    u16 unk1192;        /* 0x1192: skill of item 0xF0 */
};
extern u8 gUnk_0203C200[];
#define BB ((struct F2514Battle *)gUnk_0203C200)

/* gGameState (0x030046C0): only the field used here. */
struct F2514GameState
{
    u8 pad000[0xA20];
    s8 order[0x20];     /* 0xA20: combatant in each formation position */
};
extern struct F2514GameState gGameState;

struct F2514SortEntry
{
    s16 id;
    s16 key;
};

/* Battle state at 0x0203D16C, reached through gUnk_03006434: only the field used here. */
struct F2514State
{
    u8 pad000[0x130];
    struct F2514SortEntry targets[10];  /* 0x130 */
};
extern struct F2514State *gUnk_03006434;

/* The action being resolved (as struct Action in battle2.h). */
struct F2514Action
{
    s32 att;            /* 0x00 */
    s32 def;            /* 0x04 */
    s32 msg;            /* 0x08: -1 = default message */
    s32 result;         /* 0x0C: 1 done, 2 target defeated */
    u8 pad10[0x18 - 0x10];
    s32 dmg;            /* 0x18 */
};
extern struct F2514Action gUnk_03000088;

/* One combatant (0x80 bytes): only the field used here. */
struct F2514Combatant
{
    u8 pad00[0xC];
    u8 slot;            /* 0x0C */
};

extern const u16 gUnknown_0876F9CC[];   /* message by skill - 0x1D, +side */
extern const u16 gUnknown_0876FAE4[];   /* message by item attribute - 0x80 */
extern const u16 gUnknown_08124534[];
extern const u16 gUnknown_0812310C[];

s32 Combatant_GetChosenSkill(s32 who);
s32 sub_080C35E4(s32 who);
s32 sub_080EFFF8(s32 who, s32 x);
s32 Battle_IsEnemyId(s32 who);
void Item_GetAttribute(s32 id, s32 field, s32 *out);
const u8 *sub_080BF5C0(u16 id);
u8 *Action_GetRecord(u16 id);
u32 Battle_IsTwoSided(void);
u32 Combatant_IsDead(s32 who);
u16 Combatant_GetStatus(s32 who);
void sub_080F4988(struct F2514Action *a, s32 kind);
void Item_RunUseEffect(struct F2514Action *a, s32 item);
u16 Battle_SummonQueuedDemon(s16 i, s16 mode);
u16 *Battle_GetMessage(s32 id);
u16 *Menu_ExpandListTemplate(const u16 *tmpl, u32 arg);
void BattleMenu_SetModeAutoClose(u8 mode, u16 *src);
void sub_080F0344(u16 kind, u16 v);
s32 Party_FindPosition(s32 id);
s16 Hud_GetMemberFace(s16 slot);
void sub_080C8490(s32 slot);
void sub_080F40C4(s16 v);
s16 Combatant_GetDemonId(s32 who);
void sub_080C86F4(u16 slot);
void sub_080ECF70(u16 a);
u8 *Battle_GetCombatant(u16 idx);
u16 *Battle_BuildDamageDealtText(u8 *actor, u32 value, const u16 *tmpl);
void sub_080F3E38(s32 v);
u32 sub_080ED9F4(void);

// Battle_CastSupportSkill @ 0x080F2514
/* Casts combatant c's (non-damage) skill: picks the target (the chosen ally for target kinds
   0x80/0x82, else the other side), runs the effect with sub_080F4988 and shows the result
   message (gUnknown_0876F9CC when the effect left the default -1). Skills 0x3E/0x3F summon
   the queued demon. Redraws the face of a party target whose status changed. */
#ifdef NONMATCHING
void Battle_CastSupportSkill(struct F2514Combatant *c, s16 who)
{
    struct F2514Battle *b = BB;
    s32 skill = Combatant_GetChosenSkill(who);
    u16 kind = sub_080C35E4(who);
    u16 side;
    u8 tgt;
    u16 status;
    u16 msg;

    sub_080EFFF8(who, b->unkF66);
    side = Battle_IsEnemyId(who);
    if (kind == 8)
    {
        if (Combatant_GetChosenSkill(who) == 0xF0)
            skill = b->unk1192;
        else
            Item_GetAttribute(skill, 0xC, &skill);
    }
    tgt = sub_080BF5C0(skill)[2];
    sub_080EFFF8(who, b->unkF66);
    if (tgt == 0x80 || tgt == 0x82)
    {
        gUnk_03000088.att = who;
        gUnk_03000088.def = b->unkF30[who];
    }
    else
    {
        gUnk_03000088.att = who;
        gUnk_03000088.def = (1 - (s16)side) * 16;
        if ((u32)(skill - 0x2B) <= 0xD && (s16)side != 0)
        {
            gUnk_03000088.def = 0x10;
            if (Battle_IsTwoSided() == 1 && gUnk_03000088.att > 0x13)
            {
                u8 alive = 0;
                u8 i;

                for (i = 0x10; i <= 0x13; i++)
                {
                    if (!Combatant_IsDead(i))
                        alive++;
                }
                if (alive == 0)
                    gUnk_03000088.def = 0x14;
            }
        }
    }
    if ((s16)kind == 8 && Combatant_GetChosenSkill(who) == 0xF0 && (u32)(skill - 0x2B) <= 1)
        gUnk_03000088.def = c->slot;
    status = Combatant_GetStatus(gUnk_03000088.def);
    sub_080F4988(&gUnk_03000088, skill);
    if ((u32)(skill - 0x3E) <= 1)
    {
        u16 pos = Battle_SummonQueuedDemon(who, skill == 0x3E ? 1 : 3);

        BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(Battle_GetMessage(0xE9), gGameState.order[pos]));
        b->phase = 10;
        sub_080F0344(3, 12);
        return;
    }
    if (gUnk_03000088.result == 1)
    {
        if (gUnk_03000088.msg == -1)
        {
            msg = (s16)side + gUnknown_0876F9CC[(s16)(skill - 0x1D)];
            if (msg == 0xFFFF)
                goto done;
            msg &= 0x7FFF;
        }
        else
            msg = gUnk_03000088.msg;
        if (msg != 0xFFFF)
        {
            BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(Battle_GetMessage(msg), gUnk_03000088.def));
            b->phase = 10;
            sub_080F0344(3, 12);
        }
    done:
        b->phase = 10;
        if (status != Combatant_GetStatus(gUnk_03000088.def) && gUnk_03000088.def <= 15)
        {
            s16 p = Party_FindPosition(gUnk_03000088.def);

            if (Hud_GetMemberFace(p) <= 0x12)
                sub_080C8490(p);
        }
    }
    else
    {
        if (gUnk_03000088.msg == -1)
            BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(gUnknown_08124534, 0));
        else
            BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(Battle_GetMessage(gUnk_03000088.msg), 0));
        b->phase = 10;
        sub_080F0344(3, 12);
    }
}
#else
NAKED void Battle_CastSupportSkill(struct F2514Combatant *c, s16 who)
{
    asm_unified(
        ".L080F2514:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #4\n"
        "    mov sl, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    ldr r0, .L080F2570\n"
        "    mov r8, r0\n"
        "    lsrs r4, r1, #0x10\n"
        "    asrs r5, r1, #0x10\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_GetChosenSkill\n"
        "    str r0, [sp]\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080C35E4\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    ldr r0, .L080F2574\n"
        "    add r0, r8\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r0, r2]\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080EFFF8\n"
        "    adds r0, r5, #0\n"
        "    bl Battle_IsEnemyId\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sb, r0\n"
        "    cmp r7, #8\n"
        "    bne .L080F2586\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_GetChosenSkill\n"
        "    cmp r0, #0xf0\n"
        "    bne .L080F257C\n"
        "    ldr r0, .L080F2578\n"
        "    add r0, r8\n"
        "    ldrh r0, [r0]\n"
        "    str r0, [sp]\n"
        "    b .L080F2586\n"
        ".L080F2570: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080F2574: .4byte 0x00000F66\n"
        ".L080F2578: .4byte 0x00001192\n"
        ".L080F257C:\n"
        "    ldr r0, [sp]\n"
        "    movs r1, #0xc\n"
        "    mov r2, sp\n"
        "    bl Item_GetAttribute\n"
        ".L080F2586:\n"
        "    ldr r0, [sp]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl sub_080BF5C0\n"
        "    ldrb r5, [r0, #2]\n"
        "    lsls r4, r4, #0x10\n"
        "    asrs r6, r4, #0x10\n"
        "    ldr r0, .L080F25C4\n"
        "    add r0, r8\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r0, r2]\n"
        "    adds r0, r6, #0\n"
        "    bl sub_080EFFF8\n"
        "    cmp r5, #0x80\n"
        "    beq .L080F25AC\n"
        "    cmp r5, #0x82\n"
        "    bne .L080F25CC\n"
        ".L080F25AC:\n"
        "    ldr r2, .L080F25C8\n"
        "    str r6, [r2]\n"
        "    lsls r1, r6, #1\n"
        "    movs r0, #0xf3\n"
        "    lsls r0, r0, #4\n"
        "    add r0, r8\n"
        "    adds r0, r0, r1\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    str r0, [r2, #4]\n"
        "    lsls r7, r7, #0x10\n"
        "    b .L080F2626\n"
        ".L080F25C4: .4byte 0x00000F66\n"
        ".L080F25C8: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F25CC:\n"
        "    ldr r5, .L080F2670\n"
        "    str r6, [r5]\n"
        "    mov r2, sb\n"
        "    lsls r0, r2, #0x10\n"
        "    asrs r1, r0, #0x10\n"
        "    movs r0, #1\n"
        "    subs r0, r0, r1\n"
        "    lsls r0, r0, #4\n"
        "    str r0, [r5, #4]\n"
        "    ldr r0, [sp]\n"
        "    subs r0, #0x2b\n"
        "    lsls r7, r7, #0x10\n"
        "    cmp r0, #0xd\n"
        "    bhi .L080F2626\n"
        "    cmp r1, #0\n"
        "    beq .L080F2626\n"
        "    movs r0, #0x10\n"
        "    str r0, [r5, #4]\n"
        "    bl Battle_IsTwoSided\n"
        "    cmp r0, #1\n"
        "    bne .L080F2626\n"
        "    ldr r0, [r5]\n"
        "    cmp r0, #0x13\n"
        "    ble .L080F2626\n"
        "    movs r6, #0\n"
        "    movs r5, #0x10\n"
        ".L080F2602:\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_IsDead\n"
        "    cmp r0, #0\n"
        "    bne .L080F2612\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r6, r0, #0x18\n"
        ".L080F2612:\n"
        "    adds r0, r5, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r5, r0, #0x18\n"
        "    cmp r5, #0x13\n"
        "    bls .L080F2602\n"
        "    cmp r6, #0\n"
        "    bne .L080F2626\n"
        "    ldr r1, .L080F2670\n"
        "    movs r0, #0x14\n"
        "    str r0, [r1, #4]\n"
        ".L080F2626:\n"
        "    asrs r0, r7, #0x10\n"
        "    cmp r0, #8\n"
        "    bne .L080F2646\n"
        "    asrs r0, r4, #0x10\n"
        "    bl Combatant_GetChosenSkill\n"
        "    cmp r0, #0xf0\n"
        "    bne .L080F2646\n"
        "    ldr r0, [sp]\n"
        "    subs r0, #0x2b\n"
        "    cmp r0, #1\n"
        "    bhi .L080F2646\n"
        "    ldr r1, .L080F2670\n"
        "    mov r2, sl\n"
        "    ldrb r0, [r2, #0xc]\n"
        "    str r0, [r1, #4]\n"
        ".L080F2646:\n"
        "    ldr r5, .L080F2670\n"
        "    ldr r0, [r5, #4]\n"
        "    bl Combatant_GetStatus\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    ldr r1, [sp]\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080F4988\n"
        "    ldr r1, [sp]\n"
        "    adds r0, r1, #0\n"
        "    subs r0, #0x3e\n"
        "    cmp r0, #1\n"
        "    bhi .L080F26BC\n"
        "    cmp r1, #0x3e\n"
        "    bne .L080F2674\n"
        "    asrs r0, r4, #0x10\n"
        "    movs r1, #1\n"
        "    b .L080F2678\n"
        "    .byte 0x00, 0x00\n"
        ".L080F2670: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F2674:\n"
        "    asrs r0, r4, #0x10\n"
        "    movs r1, #3\n"
        ".L080F2678:\n"
        "    bl Battle_SummonQueuedDemon\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    movs r0, #0xe9\n"
        "    bl Battle_GetMessage\n"
        "    ldr r1, .L080F26B4\n"
        "    movs r2, #0xa2\n"
        "    lsls r2, r2, #4\n"
        "    adds r1, r1, r2\n"
        "    adds r1, r4, r1\n"
        "    ldrb r1, [r1]\n"
        "    lsls r1, r1, #0x18\n"
        "    asrs r1, r1, #0x18\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    ldr r1, .L080F26B8\n"
        "    add r1, r8\n"
        "    movs r0, #0xa\n"
        "    strh r0, [r1]\n"
        "    movs r0, #3\n"
        "    movs r1, #0xc\n"
        "    bl sub_080F0344\n"
        "    b .L080F27B8\n"
        ".L080F26B4: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080F26B8: .4byte 0x0000097C\n"
        ".L080F26BC:\n"
        "    ldr r0, [r5, #0xc]\n"
        "    cmp r0, #1\n"
        "    bne .L080F2774\n"
        "    ldr r2, [r5, #8]\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r2, r0\n"
        "    bne .L080F26FC\n"
        "    subs r1, #0x1d\n"
        "    ldr r0, .L080F26F0\n"
        "    lsls r1, r1, #0x11\n"
        "    asrs r1, r1, #0xf\n"
        "    adds r1, r1, r0\n"
        "    mov r2, sb\n"
        "    lsls r0, r2, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    ldrh r1, [r1]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    ldr r0, .L080F26F4\n"
        "    cmp r4, r0\n"
        "    beq .L080F272C\n"
        "    ldr r0, .L080F26F8\n"
        "    ands r4, r0\n"
        "    b .L080F2700\n"
        ".L080F26F0: .4byte gUnknown_0876F9CC\n"
        ".L080F26F4: .4byte 0x0000FFFF\n"
        ".L080F26F8: .4byte 0x00007FFF\n"
        ".L080F26FC:\n"
        "    lsls r0, r2, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        ".L080F2700:\n"
        "    ldr r0, .L080F2768\n"
        "    cmp r4, r0\n"
        "    beq .L080F272C\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_GetMessage\n"
        "    ldr r1, .L080F276C\n"
        "    ldr r1, [r1, #4]\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    ldr r1, .L080F2770\n"
        "    add r1, r8\n"
        "    movs r0, #0xa\n"
        "    strh r0, [r1]\n"
        "    movs r0, #3\n"
        "    movs r1, #0xc\n"
        "    bl sub_080F0344\n"
        ".L080F272C:\n"
        "    ldr r1, .L080F2770\n"
        "    add r1, r8\n"
        "    movs r0, #0xa\n"
        "    strh r0, [r1]\n"
        "    ldr r4, .L080F276C\n"
        "    ldr r0, [r4, #4]\n"
        "    bl Combatant_GetStatus\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r6, r0\n"
        "    beq .L080F27B8\n"
        "    ldr r0, [r4, #4]\n"
        "    cmp r0, #0xf\n"
        "    bgt .L080F27B8\n"
        "    bl Party_FindPosition\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r4, r0, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Hud_GetMemberFace\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #0x12\n"
        "    bgt .L080F27B8\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080C8490\n"
        "    b .L080F27B8\n"
        ".L080F2768: .4byte 0x0000FFFF\n"
        ".L080F276C: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F2770: .4byte 0x0000097C\n"
        ".L080F2774:\n"
        "    ldr r1, [r5, #8]\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r1, r0\n"
        "    bne .L080F2794\n"
        "    ldr r0, .L080F2790\n"
        "    movs r1, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    b .L080F27A8\n"
        ".L080F2790: .4byte gUnknown_08124534\n"
        ".L080F2794:\n"
        "    adds r0, r1, #0\n"
        "    bl Battle_GetMessage\n"
        "    movs r1, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        ".L080F27A8:\n"
        "    ldr r1, .L080F27C8\n"
        "    add r1, r8\n"
        "    movs r0, #0xa\n"
        "    strh r0, [r1]\n"
        "    movs r0, #3\n"
        "    movs r1, #0xc\n"
        "    bl sub_080F0344\n"
        ".L080F27B8:\n"
        "    add sp, #4\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080F27C8: .4byte 0x0000097C\n"
    );
}
#endif

// Battle_UseItem @ 0x080F27CC
/* Uses combatant c's item: picks the target like Battle_CastSupportSkill (items 0xF1/0xF2 take the
   chosen entry of the target list), runs Item_RunUseEffect and shows the result. Items
   0xF1/0xF2 report a revived member (message 0x123) or a defeated one (damage text, SE 0x12B);
   other items take their message from gUnknown_0876FAE4 by attribute 0xC, 0x137 being
   suppressed in special battles. */
void Battle_UseItem(struct F2514Combatant *c, s16 who)
{
    struct F2514Battle *b = BB;
    s32 item = Combatant_GetChosenSkill(who);
    u8 tgt = Action_GetRecord((u16)item)[3];
    u16 side = Battle_IsEnemyId(who);
    u16 status;
    u16 msg;

    if (tgt == 0x80 || tgt == 0x82 || tgt == 0x83)
    {
        gUnk_03000088.att = who;
        gUnk_03000088.def = b->unkF30[who];
        sub_080F40C4(Combatant_GetDemonId(gUnk_03000088.def));
    }
    else
    {
        gUnk_03000088.att = who;
        gUnk_03000088.def = (1 - (s16)side) * 16;
    }
    status = Combatant_GetStatus(gUnk_03000088.def);
    if ((u32)(item - 0xF1) <= 1)
    {
        gUnk_03000088.att = who;
        gUnk_03000088.def = gUnk_03006434->targets[b->unkF66].id;
    }
    Item_RunUseEffect(&gUnk_03000088, item);
    if ((u32)(item - 0xF1) <= 1)
    {
        if (gUnk_03000088.result == 1)
        {
            u16 *t = Battle_GetMessage(0x123);

            BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(t, gUnk_03000088.def + (Combatant_GetChosenSkill(who) << 16)));
            b->phase = 10;
            sub_080F0344(3, 12);
        }
        else if (gUnk_03000088.result == 2)
        {
            u16 i = 0;

            if (gGameState.order[0] != gUnk_03000088.def)
            {
                do
                {
                    i++;
                    if (i > 5)
                        break;
                } while (gGameState.order[i] != gUnk_03000088.def);
            }
            if (i != 6)
                sub_080C86F4(i);
            sub_080ECF70(0x12B);
            BattleMenu_SetModeAutoClose(3, Battle_BuildDamageDealtText(Battle_GetCombatant(gUnk_03000088.def + 0x8000), gUnk_03000088.dmg, gUnknown_0812310C));
            b->phase = 10;
            sub_080F0344(3, 12);
        }
        else
            b->phase = 10;
        return;
    }
    if (gUnk_03000088.result == 1)
    {
        sub_080F3E38(item);
        Item_GetAttribute(item, 0xC, &item);
        if (gUnk_03000088.msg == -1)
        {
            s16 k = item - 0x80;

            msg = gUnknown_0876FAE4[k];
            if (msg == 0x137 && sub_080ED9F4())
                msg = 0xFFFF;
        }
        else
            msg = gUnk_03000088.msg;
        if (msg == 0x137)
        {
            BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(Battle_GetMessage(msg), gUnk_03000088.def));
            b->phase = 10;
            sub_080F0344(3, 12);
        }
        else if (msg != 0xFFFF)
        {
            u16 *t = Battle_GetMessage(msg);

            BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(t, gUnk_03000088.def + (Combatant_GetChosenSkill(who) << 16)));
            b->phase = 10;
            sub_080F0344(3, 12);
        }
        b->phase = 10;
        if (status != Combatant_GetStatus(gUnk_03000088.def) && gUnk_03000088.def <= 15)
        {
            s16 p = Party_FindPosition(gUnk_03000088.def);

            if (Hud_GetMemberFace(p) <= 0x12)
                sub_080C8490(p);
        }
    }
    else
    {
        if (gUnk_03000088.msg == -1)
            BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(gUnknown_08124534, 0));
        else
            BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(Battle_GetMessage(gUnk_03000088.msg), 0));
        b->phase = 10;
        sub_080F0344(3, 12);
    }
}
