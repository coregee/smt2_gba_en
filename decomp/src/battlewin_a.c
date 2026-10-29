/* Battle won: the victory sequence (compendium entries, item drops, macca, magnetite,
   experience, level-ups and newly learned skills). */

#include "global.h"

/* The battle EWRAM block at 0x0203C200: only the fields used here. */
struct E98F8Battle
{
    u8 pad000[0x7E4];
    u8 unk7E4;          /* 0x7E4 */
    u8 pad7E5[0x974 - 0x7E5];
    void *window;       /* 0x974 */
    s16 state;          /* 0x978 */
    s16 substate;       /* 0x97A */
    s16 phase;          /* 0x97C */
    u8 pad97E[0x990 - 0x97E];
    u32 groups[2];      /* 0x990: demon id of each enemy group */
    u16 counts[2];      /* 0x998: enemies per group */
    u16 enemyCount;     /* 0x99C */
    s16 waves;          /* 0x99E: encounters left in this battle */
    u8 pad9A0[0xECE - 0x9A0];
    s16 index;          /* 0xECE: enemy / party member being handled */
    u8 padED0[0xF68 - 0xED0];
    s16 unkF68;         /* 0xF68 */
    s16 unkF6A;         /* 0xF6A */
    u8 padF6C[0x1178 - 0xF6C];
    u16 levelsGained;   /* 0x1178 */
};
extern u8 gUnk_0203C200[];
#define BB ((struct E98F8Battle *)gUnk_0203C200)

/* Battle IWRAM state at 0x030063A0: only the fields used here. */
struct E98F8BattleIw
{
    u16 active;         /* 0x00 */
    u8 pad02[0x10 - 0x2];
    u16 unk10;          /* 0x10 */
};
extern struct E98F8BattleIw gUnk_030063A0;

/* One combatant (0x80 bytes): only the fields used here. */
struct E98F8Combatant
{
    u8 pad00[0x8];
    s32 exp;            /* 0x08 */
    u8 id;              /* 0x0C */
    u8 pad0D[0x5D - 0xD];
    u8 skills[32];      /* 0x5D: 0xFF-terminated */
};

struct E98F8Task
{
    u8 pad00[0x1C];
    u16 result;         /* 0x1C */
};

extern u16 gUnk_0203A450[2];    /* random seeds for the next wave */
extern u16 gUnk_030031B4;
extern u16 gHudState[];
extern s16 gUnk_03000054;       /* levels gained */
extern s16 gUnk_03000056;
extern s16 gUnk_0300005C;       /* skills known before the level-up */
extern s16 gUnk_0300005E;       /* new skill being announced */
extern u8 gUnk_03000060[32];    /* copy of the skill list before the level-up */

extern const u16 gUnknown_08124270[], gUnknown_08124452[], gUnknown_0812443C[];
extern const u16 gUnknown_08124426[], gUnknown_081243EE[], gUnknown_0812440A[];
extern const u16 gUnknown_0812428E[], gUnknown_0812434A[];

u32 Flag_Test(u32 flag);
void Flag_Clear(u32 flag);
void sub_080F00FC(u16 m);
void BattleMsg_SetLocked(u8 locked);
void sub_080E51FC(void);
u16 sub_080ED8F4(void);
void sub_080EF364(void);
u32 Battle_IsTwoSided(void);
void sub_080C2584(u32 id);
u16 *Battle_BuildRaceCountText(u16 id, u16 count, const u16 *tmpl);
void BattleMenu_SetMode(u8 mode, u16 *src);
s32 sub_080EF3C8(s32 id);
s32 sub_080C10B4(void);
void sub_080F01D8(s32 i, s32 v);
u32 sub_080EF434(s32 id);
void sub_080F0150(s16 d);
void sub_080E5A18(u16 substate);
void sub_080C84A0(void);
u32 Random_Byte(void);
s32 Combatant_IsAlive(s32 who);
u16 Combatant_GetStatus(s32 who);
u32 Combatant_SetStatus(s32 who, u16 bits);
void Battle_SetHp(s32 who, s32 v);
void Battle_SetMp(s32 who, s32 v);
void sub_080E7538(u8 slot, u8 mode, u8 arg);
u16 sub_080E980C(void);
void *sub_080AB890(u16 x, u16 y, u16 w, u16 h, u16 bg);
void sub_080ECF60(u16 se);
void Music_FadeOut(u16 speed);
void BattleMenu_Reset(void);
void BattleMsg_Close(void);
void sub_080E9008(void);
void sub_080C7C60(void);
void sub_080C700C(void);
u32 sub_080E9870(void);
s32 sub_080F01EC(s32 i);
s32 sub_080F3E54(s32 id, s32 n);
u16 *Battle_BuildItemDropText(u16 item, const u16 *tmpl);
u8 BattleMsg_IsDone(void);
s32 sub_080F0168(void);
u16 *Battle_BuildValueRewardText(u16 value, const u16 *tmpl);
u32 sub_080F0124(void);
void sub_080F3E20(s32 a);
u32 sub_080F0144(void);
s32 sub_080F3E2C(s32 a);
s32 Combatant_IsInParty(s32 who);
struct E98F8Combatant *Battle_GetCombatant(u16 idx);
u32 sub_080F0194(s32 who);
s32 Exp_GetLevel(s32 exp);
u16 *Battle_BuildRewardText(struct E98F8Combatant *actor, u32 value, const u16 *tmpl);
void Combatant_SetLevel(s32 who, s32 level);
void Combatant_RecalcStats(s32 who);
u16 *Battle_BuildNamePrefixText(u16 idx, const u16 *pre);
void sub_080ECF70(u16 a);
void *sub_080CE62C(u16 sel, u16 points);
void Party_BuildSkillList(s32 who);
s32 Party_GetSkillCount(s32 who);
u16 *sub_080EB008(u16 id);
void sub_080E5A3C(void);

// Battle_VictoryStep @ 0x080E98F8
/* Victory sequence, one substate (+0x97A) per call; task->result 1 when done.
    0 compendium/"defeated N <race>" message, item table and wave setup
    1 next wave (new random seeds) or, with flag 0x200, every enemy is marked dead
    2/3 leave the battle; 4 sub_080E9870; 5/17 item drops, one per enemy (message mode 7)
    6/14 money (item 0xDB/0xE5 by 1 in 8), 7/15 macca (sub_080F3E20), 8/16 magnetite
    9 experience for party member +0xECE (exp capped at 9,999,999) and level check
   10/12 "level up" message and stat allotment (sub_080CE62C), 13/18 newly learned skills
   11/19 next party member (four), 20 sub_080E5A3C. */
#ifdef NONMATCHING
void Battle_VictoryStep(struct E98F8Task *task)
{
    struct E98F8Battle *b = BB;
    u16 n = b->enemyCount;
    s32 wait = 0;
    u16 compendium = Flag_Test(0xE5);

    task->result = 0;
    switch (b->substate)
    {
    case 0:
        sub_080F00FC(0x4000);
        BattleMsg_SetLocked(0);
        sub_080E51FC();
        Flag_Clear(0x166);
        if (sub_080ED8F4() & 0x2000)
        {
            sub_080EF364();
            b->state = 0x10;
            task->result = 1;
            goto refresh;
        }
        if (!Battle_IsTwoSided())
        {
            if (!(sub_080ED8F4() & 0x200))
            {
                if (compendium)
                    sub_080C2584(b->groups[0]);
                BattleMenu_SetMode(3, Battle_BuildRaceCountText(b->groups[0], b->counts[0], gUnknown_08124270));
                wait = 1;
            }
        }
        else if (!(sub_080ED8F4() & 0x200) && compendium)
        {
            sub_080C2584(b->groups[0]);
            sub_080C2584(b->groups[1]);
            b->unk7E4 = 1;
        }
        if (!(sub_080ED8F4() & 0x200))
        {
            s32 id = sub_080EF3C8(b->groups[0]);

            if (id != -1 && sub_080C10B4() > 0x62)
                id = -1;
            sub_080F01D8(b->waves - 1, (s16)id);
            if (sub_080EF434(b->groups[0]))
                sub_080F0150(1);
        }
        b->substate = 1;
        if (wait)
            sub_080E5A18(0x14);
        goto refresh;
    case 1:
        if (--b->waves > 0)
        {
            b->substate = 2;
            gUnk_0203A450[0] = Random_Byte();
            gUnk_0203A450[1] = Random_Byte();
            sub_080EF364();
        refresh:
            sub_080C84A0();
            break;
        }
        if (sub_080ED8F4() & 0x200)
        {
            s16 i;

            for (i = 0x10; i <= 0x17; i++)
            {
                if (Combatant_IsAlive(i))
                {
                    Combatant_GetStatus(i);
                    Combatant_SetStatus(i, 0x8000);
                    Battle_SetHp(i, 0);
                    Battle_SetMp(i, 0);
                    sub_080E7538(i - 0x10, 0, 0);
                }
            }
            if ((s16)sub_080E980C() == 1 && b->window == NULL)
                b->window = sub_080AB890(2, 0xB, 0x1A, 2, 0);
        }
        sub_080EF364();
        sub_080C84A0();
        if (b->unkF6A == 0)
            sub_080ECF60(9);
        gUnk_030063A0.unk10 = 9;
        b->substate = 4;
        break;
    case 2:
        b->unkF68 = 0;
        Music_FadeOut(4);
        gUnk_030031B4 = 0;
        BattleMenu_Reset();
        BattleMsg_Close();
        sub_080E9008();
        gUnk_030063A0.active = 1;
        sub_080C7C60();
        b->substate = 3;
        break;
    case 3:
        if (b->unkF6A == 0 && gHudState[0] != 0 && gHudState[0] != 2)
            sub_080C700C();
        b->state = 0;
        task->result = 1;
        break;
    case 4:
        if (sub_080E9870())
            wait = 1;
        b->index = 0;
        b->substate = 5;
        if (wait)
            sub_080E5A18(0x14);
        break;
    case 5:
    {
        s32 item = sub_080F01EC(b->index);

        if (item != -1)
        {
            sub_080F3E54(item, 1);
            BattleMenu_SetMode(7, Battle_BuildItemDropText(item, gUnknown_08124452));
            b->substate = 17;
        }
        else if (++b->index >= (s16)n)
            b->substate = 6;
        break;
    }
    case 17:
        if (BattleMsg_IsDone() != 1)
            break;
        b->substate = 5;
        if (++b->index >= (s16)n)
            b->substate = 6;
        break;
    case 6:
    {
        s32 v = sub_080F0168();

        b->substate = 7;
        if (v != 0)
        {
            u32 item = (Random_Byte() & 7) ? 0xE5 : 0xDB;
            const u16 *tmpl;

            tmpl = gUnknown_0812443C;
            if (item == 0xE5)
                tmpl = gUnknown_08124426;
            sub_080F3E54(item, v);
            BattleMenu_SetMode(7, Battle_BuildValueRewardText(v, tmpl));
            b->substate = 14;
        }
        break;
    }
    case 14:
        if (BattleMsg_IsDone() == 1)
            b->substate = 7;
        break;
    case 7:
    {
        u32 v = sub_080F0124();

        b->substate = 8;
        if (v != 0)
        {
            sub_080F3E20(v);
            BattleMenu_SetMode(7, Battle_BuildValueRewardText(v, gUnknown_081243EE));
            b->substate = 15;
        }
        break;
    }
    case 15:
        if (BattleMsg_IsDone() == 1)
            b->substate = 8;
        break;
    case 8:
    {
        u32 v = sub_080F0144();

        b->substate = 9;
        if (v != 0)
        {
            sub_080F3E2C(v);
            BattleMenu_SetMode(7, Battle_BuildValueRewardText(v, gUnknown_0812440A));
            b->substate = 16;
        }
        gUnk_03000056 = 0;
        b->index = 0;
        break;
    }
    case 16:
        if (BattleMsg_IsDone() == 1)
            b->substate = 9;
        break;
    case 9:
    {
        struct E98F8Combatant *c;
        u32 exp;
        s32 oldLevel, level;
        s16 i;

        if (!Combatant_IsInParty(b->index) || !Combatant_IsAlive(b->index))
        {
            b->substate = 11;
            break;
        }
        c = Battle_GetCombatant(b->index + 0x8000);
        exp = sub_080F0194(b->index);
        oldLevel = Exp_GetLevel(c->exp);
        gUnk_0300005C = 0;
        for (i = 0; i <= 0x1F; i++)
        {
            if (c->skills[i] != 0xFF)
            {
                gUnk_03000060[i] = c->skills[i];
                gUnk_0300005C++;
            }
        }
        if (exp != 0)
        {
            c->exp += exp;
            if (c->exp > 9999998)
                c->exp = 9999999;
            BattleMenu_SetMode(7, Battle_BuildRewardText(c, exp, gUnknown_0812428E));
            wait = 1;
        }
        level = Exp_GetLevel(c->exp);
        Combatant_SetLevel(b->index, level);
        gUnk_03000054 = level - oldLevel;
        if (gUnk_03000054 != 0)
        {
            gUnk_03000056 = 1;
            b->phase = 0;
            b->substate = 10;
            b->levelsGained = level - oldLevel;
            Combatant_RecalcStats(b->index);
            break;
        }
        b->substate = 11;
        if (wait)
            sub_080E5A18(0x14);
        break;
    }
    case 10:
        if (BattleMsg_IsDone() == 1)
        {
            b->substate = 12;
            BattleMenu_SetMode(7, Battle_BuildNamePrefixText(b->index + 0x8000, gUnknown_0812434A));
            sub_080ECF60(0xB);
            sub_080ECF70(0x67);
        }
        break;
    case 12:
        if (BattleMsg_IsDone() == 1)
        {
            struct E98F8Combatant *c = Battle_GetCombatant(b->index + 0x8000);

            sub_080CE62C(c->id, b->levelsGained);
            BattleMsg_Close();
            b->substate = 13;
        }
        break;
    case 13:
        if (BattleMsg_IsDone() == 1)
        {
            s16 known;

            Party_BuildSkillList(b->index);
            known = gUnk_0300005C;
            if (known < Party_GetSkillCount(b->index))
            {
                struct E98F8Combatant *c = Battle_GetCombatant(b->index + 0x8000);

                gUnk_0300005E = 0;
                BattleMenu_SetMode(3, sub_080EB008(c->skills[gUnk_0300005C]));
                b->substate = 18;
            }
            else
                b->substate = 11;
        }
        break;
    case 18:
        if (BattleMsg_IsDone() == 1)
        {
            struct E98F8Combatant *c = Battle_GetCombatant(b->index + 0x8000);
            u8 *s;

            gUnk_0300005E++;
            s = &c->skills[gUnk_0300005C + gUnk_0300005E];
            if (*s == 0xFF)
            {
                BattleMenu_Reset();
                b->substate = 11;
            }
            else
                BattleMenu_SetMode(3, sub_080EB008(*s));
        }
        break;
    case 11:
    case 19:
        if (++b->index > 3)
        {
            b->state = 0x10;
            task->result = 1;
        }
        else
            b->substate = 9;
        break;
    case 20:
        if (BattleMsg_IsDone() == 1)
            sub_080E5A3C();
        break;
    }
}
#else
NAKED void Battle_VictoryStep(struct E98F8Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #4\n"
        "    adds r4, r0, #0\n"
        "    ldr r6, .L080E993C\n"
        "    ldr r1, .L080E9940\n"
        "    adds r0, r6, r1\n"
        "    ldrh r7, [r0]\n"
        "    movs r2, #0\n"
        "    mov sb, r2\n"
        "    movs r0, #0xe5\n"
        "    bl Flag_Test\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    mov r3, sb\n"
        "    strh r3, [r4, #0x1c]\n"
        "    ldr r1, .L080E9944\n"
        "    adds r0, r6, r1\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r0, r2]\n"
        "    cmp r0, #0x14\n"
        "    bls .L080E9930\n"
        "    bl .L080EA168\n"
        ".L080E9930:\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L080E9948\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080E993C: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080E9940: .4byte 0x0000099C\n"
        ".L080E9944: .4byte 0x0000097A\n"
        ".L080E9948: .4byte gUnknown_080E994C\n"
        "    .global gUnknown_080E994C\n"
        "gUnknown_080E994C:\n"
        ".L080E994C: @ jump table\n"
        "    .4byte .L080E99A0\n"
        "    .4byte .L080E9ADC\n"
        "    .4byte .L080E9BD4\n"
        "    .4byte .L080E9C18\n"
        "    .4byte .L080E9C48\n"
        "    .4byte .L080E9C6C\n"
        "    .4byte .L080E9D0C\n"
        "    .4byte .L080E9D80\n"
        "    .4byte .L080E9DD8\n"
        "    .4byte .L080E9E3C\n"
        "    .4byte .L080E9F88\n"
        "    .4byte .L080EA120\n"
        "    .4byte .L080E9FDC\n"
        "    .4byte .L080EA02C\n"
        "    .4byte .L080E9D64\n"
        "    .4byte .L080E9DBC\n"
        "    .4byte .L080E9E24\n"
        "    .4byte .L080E9CD4\n"
        "    .4byte .L080EA0B0\n"
        "    .4byte .L080EA120\n"
        "    .4byte .L080EA158\n"
        ".L080E99A0:\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #7\n"
        "    bl sub_080F00FC\n"
        "    movs r0, #0\n"
        "    bl BattleMsg_SetLocked\n"
        "    bl sub_080E51FC\n"
        "    movs r0, #0xb3\n"
        "    lsls r0, r0, #1\n"
        "    bl Flag_Clear\n"
        "    bl sub_080ED8F4\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #6\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080E99E0\n"
        "    bl sub_080EF364\n"
        "    ldr r3, .L080E99DC\n"
        "    adds r0, r6, r3\n"
        "    movs r1, #0x10\n"
        "    strh r1, [r0]\n"
        "    movs r0, #1\n"
        "    strh r0, [r4, #0x1c]\n"
        "    b .L080E9B06\n"
        "    .byte 0x00, 0x00\n"
        ".L080E99DC: .4byte 0x00000978\n"
        ".L080E99E0:\n"
        "    bl Battle_IsTwoSided\n"
        "    cmp r0, #0\n"
        "    bne .L080E9A30\n"
        "    bl sub_080ED8F4\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #2\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    bne .L080E9A60\n"
        "    cmp r5, #0\n"
        "    beq .L080E9A06\n"
        "    movs r5, #0x99\n"
        "    lsls r5, r5, #4\n"
        "    adds r0, r6, r5\n"
        "    ldr r0, [r0]\n"
        "    bl sub_080C2584\n"
        ".L080E9A06:\n"
        "    movs r1, #0x99\n"
        "    lsls r1, r1, #4\n"
        "    adds r0, r6, r1\n"
        "    ldrh r0, [r0]\n"
        "    ldr r2, .L080E9A28\n"
        "    adds r1, r6, r2\n"
        "    ldrh r1, [r1]\n"
        "    ldr r2, .L080E9A2C\n"
        "    bl Battle_BuildRaceCountText\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetMode\n"
        "    movs r3, #1\n"
        "    mov sb, r3\n"
        "    b .L080E9A60\n"
        ".L080E9A28: .4byte 0x00000998\n"
        ".L080E9A2C: .4byte gUnknown_08124270\n"
        ".L080E9A30:\n"
        "    bl sub_080ED8F4\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #2\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    bne .L080E9A60\n"
        "    cmp r5, #0\n"
        "    beq .L080E9A60\n"
        "    movs r5, #0x99\n"
        "    lsls r5, r5, #4\n"
        "    adds r0, r6, r5\n"
        "    ldr r0, [r0]\n"
        "    bl sub_080C2584\n"
        "    ldr r1, .L080E9ACC\n"
        "    adds r0, r6, r1\n"
        "    ldr r0, [r0]\n"
        "    bl sub_080C2584\n"
        "    ldr r2, .L080E9AD0\n"
        "    adds r1, r6, r2\n"
        "    movs r0, #1\n"
        "    strb r0, [r1]\n"
        ".L080E9A60:\n"
        "    bl sub_080ED8F4\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #2\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    bne .L080E9AB6\n"
        "    movs r3, #0x99\n"
        "    lsls r3, r3, #4\n"
        "    adds r0, r6, r3\n"
        "    ldr r0, [r0]\n"
        "    bl sub_080EF3C8\n"
        "    adds r4, r0, #0\n"
        "    movs r5, #1\n"
        "    rsbs r5, r5, #0\n"
        "    cmp r4, r5\n"
        "    beq .L080E9A8E\n"
        "    bl sub_080C10B4\n"
        "    cmp r0, #0x62\n"
        "    ble .L080E9A8E\n"
        "    adds r4, r5, #0\n"
        ".L080E9A8E:\n"
        "    ldr r5, .L080E9AD4\n"
        "    adds r0, r6, r5\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    subs r0, #1\n"
        "    lsls r1, r4, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    bl sub_080F01D8\n"
        "    movs r2, #0x99\n"
        "    lsls r2, r2, #4\n"
        "    adds r0, r6, r2\n"
        "    ldr r0, [r0]\n"
        "    bl sub_080EF434\n"
        "    cmp r0, #0\n"
        "    beq .L080E9AB6\n"
        "    movs r0, #1\n"
        "    bl sub_080F0150\n"
        ".L080E9AB6:\n"
        "    ldr r3, .L080E9AD8\n"
        "    adds r1, r6, r3\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    mov r5, sb\n"
        "    cmp r5, #0\n"
        "    beq .L080E9B06\n"
        "    movs r0, #0x14\n"
        "    bl sub_080E5A18\n"
        "    b .L080E9B06\n"
        ".L080E9ACC: .4byte 0x00000994\n"
        ".L080E9AD0: .4byte 0x000007E4\n"
        ".L080E9AD4: .4byte 0x0000099E\n"
        ".L080E9AD8: .4byte 0x0000097A\n"
        ".L080E9ADC:\n"
        "    ldr r0, .L080E9B0C\n"
        "    adds r1, r6, r0\n"
        "    ldrh r0, [r1]\n"
        "    subs r0, #1\n"
        "    strh r0, [r1]\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    ble .L080E9B18\n"
        "    ldr r2, .L080E9B10\n"
        "    adds r1, r6, r2\n"
        "    movs r0, #2\n"
        "    strh r0, [r1]\n"
        "    bl Random_Byte\n"
        "    ldr r4, .L080E9B14\n"
        "    strh r0, [r4]\n"
        "    bl Random_Byte\n"
        "    strh r0, [r4, #2]\n"
        "    bl sub_080EF364\n"
        ".L080E9B06:\n"
        "    bl sub_080C84A0\n"
        "    b .L080EA168\n"
        ".L080E9B0C: .4byte 0x0000099E\n"
        ".L080E9B10: .4byte 0x0000097A\n"
        ".L080E9B14: .4byte 0x0203A450 @ EWRAM+0x3A450\n"
        ".L080E9B18:\n"
        "    bl sub_080ED8F4\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #2\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080E9B9A\n"
        "    movs r5, #0x10\n"
        "    movs r7, #0x80\n"
        "    lsls r7, r7, #8\n"
        ".L080E9B2C:\n"
        "    lsls r0, r5, #0x10\n"
        "    asrs r4, r0, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_IsAlive\n"
        "    cmp r0, #0\n"
        "    beq .L080E9B68\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_GetStatus\n"
        "    adds r1, r7, #0\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_SetStatus\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0\n"
        "    bl Battle_SetHp\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0\n"
        "    bl Battle_SetMp\n"
        "    adds r0, r5, #0\n"
        "    subs r0, #0x10\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    bl sub_080E7538\n"
        ".L080E9B68:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #0x17\n"
        "    ble .L080E9B2C\n"
        "    bl sub_080E980C\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bne .L080E9B9A\n"
        "    ldr r3, .L080E9BC4\n"
        "    adds r4, r6, r3\n"
        "    ldr r0, [r4]\n"
        "    cmp r0, #0\n"
        "    bne .L080E9B9A\n"
        "    str r0, [sp]\n"
        "    movs r0, #2\n"
        "    movs r1, #0xb\n"
        "    movs r2, #0x1a\n"
        "    movs r3, #2\n"
        "    bl sub_080AB890\n"
        "    str r0, [r4]\n"
        ".L080E9B9A:\n"
        "    bl sub_080EF364\n"
        "    bl sub_080C84A0\n"
        "    ldr r5, .L080E9BC8\n"
        "    adds r0, r6, r5\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    cmp r0, #0\n"
        "    bne .L080E9BB4\n"
        "    movs r0, #9\n"
        "    bl sub_080ECF60\n"
        ".L080E9BB4:\n"
        "    ldr r1, .L080E9BCC\n"
        "    movs r0, #9\n"
        "    strh r0, [r1, #0x10]\n"
        "    ldr r2, .L080E9BD0\n"
        "    adds r1, r6, r2\n"
        "    movs r0, #4\n"
        "    strh r0, [r1]\n"
        "    b .L080EA168\n"
        ".L080E9BC4: .4byte 0x00000974\n"
        ".L080E9BC8: .4byte 0x00000F6A\n"
        ".L080E9BCC: .4byte 0x030063A0 @ IWRAM+0x63A0\n"
        ".L080E9BD0: .4byte 0x0000097A\n"
        ".L080E9BD4:\n"
        "    ldr r3, .L080E9C08\n"
        "    adds r0, r6, r3\n"
        "    movs r4, #0\n"
        "    strh r4, [r0]\n"
        "    movs r0, #4\n"
        "    bl Music_FadeOut\n"
        "    ldr r0, .L080E9C0C\n"
        "    strh r4, [r0]\n"
        "    bl BattleMenu_Reset\n"
        "    bl BattleMsg_Close\n"
        "    bl sub_080E9008\n"
        "    ldr r1, .L080E9C10\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    bl sub_080C7C60\n"
        "    ldr r5, .L080E9C14\n"
        "    adds r1, r6, r5\n"
        "    movs r0, #3\n"
        "    strh r0, [r1]\n"
        "    b .L080EA168\n"
        "    .byte 0x00, 0x00\n"
        ".L080E9C08: .4byte 0x00000F68\n"
        ".L080E9C0C: .4byte 0x030031B4 @ IWRAM+0x31B4\n"
        ".L080E9C10: .4byte 0x030063A0 @ IWRAM+0x63A0\n"
        ".L080E9C14: .4byte 0x0000097A\n"
        ".L080E9C18:\n"
        "    ldr r1, .L080E9C3C\n"
        "    adds r0, r6, r1\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r0, r2]\n"
        "    cmp r0, #0\n"
        "    bne .L080E9C34\n"
        "    ldr r0, .L080E9C40\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    beq .L080E9C34\n"
        "    cmp r0, #2\n"
        "    beq .L080E9C34\n"
        "    bl sub_080C700C\n"
        ".L080E9C34:\n"
        "    ldr r3, .L080E9C44\n"
        "    adds r0, r6, r3\n"
        "    movs r1, #0\n"
        "    b .L080EA138\n"
        ".L080E9C3C: .4byte 0x00000F6A\n"
        ".L080E9C40: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
        ".L080E9C44: .4byte 0x00000978\n"
        ".L080E9C48:\n"
        "    bl sub_080E9870\n"
        "    cmp r0, #0\n"
        "    beq .L080E9C54\n"
        "    movs r5, #1\n"
        "    mov sb, r5\n"
        ".L080E9C54:\n"
        "    ldr r0, .L080E9C64\n"
        "    adds r1, r6, r0\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r2, .L080E9C68\n"
        "    adds r1, r6, r2\n"
        "    movs r0, #5\n"
        "    b .L080E9F66\n"
        ".L080E9C64: .4byte 0x00000ECE\n"
        ".L080E9C68: .4byte 0x0000097A\n"
        ".L080E9C6C:\n"
        "    ldr r0, .L080E9CA8\n"
        "    adds r5, r6, r0\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r5, r1]\n"
        "    bl sub_080F01EC\n"
        "    adds r4, r0, #0\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r4, r0\n"
        "    beq .L080E9CB4\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #1\n"
        "    bl sub_080F3E54\n"
        "    lsls r0, r4, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    ldr r1, .L080E9CAC\n"
        "    bl Battle_BuildItemDropText\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #7\n"
        "    bl BattleMenu_SetMode\n"
        "    ldr r2, .L080E9CB0\n"
        "    adds r1, r6, r2\n"
        "    movs r0, #0x11\n"
        "    strh r0, [r1]\n"
        "    b .L080EA168\n"
        "    .byte 0x00, 0x00\n"
        ".L080E9CA8: .4byte 0x00000ECE\n"
        ".L080E9CAC: .4byte gUnknown_08124452\n"
        ".L080E9CB0: .4byte 0x0000097A\n"
        ".L080E9CB4:\n"
        "    ldrh r0, [r5]\n"
        "    adds r0, #1\n"
        "    strh r0, [r5]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsls r1, r7, #0x10\n"
        "    cmp r0, r1\n"
        "    bge .L080E9CC4\n"
        "    b .L080EA168\n"
        ".L080E9CC4:\n"
        "    ldr r3, .L080E9CD0\n"
        "    adds r1, r6, r3\n"
        "    movs r0, #6\n"
        "    strh r0, [r1]\n"
        "    b .L080EA168\n"
        "    .byte 0x00, 0x00\n"
        ".L080E9CD0: .4byte 0x0000097A\n"
        ".L080E9CD4:\n"
        "    bl BattleMsg_IsDone\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    beq .L080E9CE2\n"
        "    b .L080EA168\n"
        ".L080E9CE2:\n"
        "    ldr r5, .L080E9D04\n"
        "    adds r2, r6, r5\n"
        "    movs r0, #5\n"
        "    strh r0, [r2]\n"
        "    ldr r0, .L080E9D08\n"
        "    adds r1, r6, r0\n"
        "    ldrh r0, [r1]\n"
        "    adds r0, #1\n"
        "    strh r0, [r1]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsls r1, r7, #0x10\n"
        "    cmp r0, r1\n"
        "    bge .L080E9CFE\n"
        "    b .L080EA168\n"
        ".L080E9CFE:\n"
        "    movs r0, #6\n"
        "    strh r0, [r2]\n"
        "    b .L080EA168\n"
        ".L080E9D04: .4byte 0x0000097A\n"
        ".L080E9D08: .4byte 0x00000ECE\n"
        ".L080E9D0C:\n"
        "    bl sub_080F0168\n"
        "    adds r4, r0, #0\n"
        "    ldr r1, .L080E9D58\n"
        "    adds r6, r6, r1\n"
        "    movs r5, #7\n"
        "    strh r5, [r6]\n"
        "    cmp r4, #0\n"
        "    bne .L080E9D20\n"
        "    b .L080EA168\n"
        ".L080E9D20:\n"
        "    bl Random_Byte\n"
        "    ands r0, r5\n"
        "    movs r1, #0xdb\n"
        "    cmp r0, #0\n"
        "    beq .L080E9D2E\n"
        "    movs r1, #0xe5\n"
        ".L080E9D2E:\n"
        "    adds r0, r1, #0\n"
        "    ldr r5, .L080E9D5C\n"
        "    cmp r0, #0xe5\n"
        "    bne .L080E9D38\n"
        "    ldr r5, .L080E9D60\n"
        ".L080E9D38:\n"
        "    adds r1, r4, #0\n"
        "    bl sub_080F3E54\n"
        "    lsls r0, r4, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    adds r1, r5, #0\n"
        "    bl Battle_BuildValueRewardText\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #7\n"
        "    bl BattleMenu_SetMode\n"
        "    movs r0, #0xe\n"
        "    strh r0, [r6]\n"
        "    b .L080EA168\n"
        "    .byte 0x00, 0x00\n"
        ".L080E9D58: .4byte 0x0000097A\n"
        ".L080E9D5C: .4byte gUnknown_0812443C\n"
        ".L080E9D60: .4byte gUnknown_08124426\n"
        ".L080E9D64:\n"
        "    bl BattleMsg_IsDone\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    beq .L080E9D72\n"
        "    b .L080EA168\n"
        ".L080E9D72:\n"
        "    ldr r2, .L080E9D7C\n"
        "    adds r1, r6, r2\n"
        "    movs r0, #7\n"
        "    strh r0, [r1]\n"
        "    b .L080EA168\n"
        ".L080E9D7C: .4byte 0x0000097A\n"
        ".L080E9D80:\n"
        "    bl sub_080F0124\n"
        "    adds r4, r0, #0\n"
        "    ldr r3, .L080E9DB4\n"
        "    adds r5, r6, r3\n"
        "    movs r0, #8\n"
        "    strh r0, [r5]\n"
        "    cmp r4, #0\n"
        "    bne .L080E9D94\n"
        "    b .L080EA168\n"
        ".L080E9D94:\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080F3E20\n"
        "    lsls r0, r4, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    ldr r1, .L080E9DB8\n"
        "    bl Battle_BuildValueRewardText\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #7\n"
        "    bl BattleMenu_SetMode\n"
        "    movs r0, #0xf\n"
        "    strh r0, [r5]\n"
        "    b .L080EA168\n"
        "    .byte 0x00, 0x00\n"
        ".L080E9DB4: .4byte 0x0000097A\n"
        ".L080E9DB8: .4byte gUnknown_081243EE\n"
        ".L080E9DBC:\n"
        "    bl BattleMsg_IsDone\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    beq .L080E9DCA\n"
        "    b .L080EA168\n"
        ".L080E9DCA:\n"
        "    ldr r5, .L080E9DD4\n"
        "    adds r1, r6, r5\n"
        "    movs r0, #8\n"
        "    strh r0, [r1]\n"
        "    b .L080EA168\n"
        ".L080E9DD4: .4byte 0x0000097A\n"
        ".L080E9DD8:\n"
        "    bl sub_080F0144\n"
        "    adds r4, r0, #0\n"
        "    ldr r0, .L080E9E14\n"
        "    adds r5, r6, r0\n"
        "    movs r7, #0\n"
        "    movs r0, #9\n"
        "    strh r0, [r5]\n"
        "    cmp r4, #0\n"
        "    beq .L080E9E08\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080F3E2C\n"
        "    lsls r0, r4, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    ldr r1, .L080E9E18\n"
        "    bl Battle_BuildValueRewardText\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #7\n"
        "    bl BattleMenu_SetMode\n"
        "    movs r0, #0x10\n"
        "    strh r0, [r5]\n"
        ".L080E9E08:\n"
        "    ldr r0, .L080E9E1C\n"
        "    strh r7, [r0]\n"
        "    ldr r1, .L080E9E20\n"
        "    adds r0, r6, r1\n"
        "    strh r7, [r0]\n"
        "    b .L080EA168\n"
        ".L080E9E14: .4byte 0x0000097A\n"
        ".L080E9E18: .4byte gUnknown_0812440A\n"
        ".L080E9E1C: .4byte 0x03000056 @ IWRAM+0x56\n"
        ".L080E9E20: .4byte 0x00000ECE\n"
        ".L080E9E24:\n"
        "    bl BattleMsg_IsDone\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    beq .L080E9E32\n"
        "    b .L080EA168\n"
        ".L080E9E32:\n"
        "    ldr r2, .L080E9E38\n"
        "    adds r1, r6, r2\n"
        "    b .L080EA14C\n"
        ".L080E9E38: .4byte 0x0000097A\n"
        ".L080E9E3C:\n"
        "    ldr r3, .L080E9F30\n"
        "    adds r5, r6, r3\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r5, r1]\n"
        "    bl Combatant_IsInParty\n"
        "    cmp r0, #0\n"
        "    bne .L080E9E4E\n"
        "    b .L080E9F7C\n"
        ".L080E9E4E:\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r5, r2]\n"
        "    bl Combatant_IsAlive\n"
        "    cmp r0, #0\n"
        "    bne .L080E9E5C\n"
        "    b .L080E9F7C\n"
        ".L080E9E5C:\n"
        "    ldr r3, .L080E9F34\n"
        "    adds r0, r3, #0\n"
        "    ldrh r1, [r5]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    adds r4, r0, #0\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r5, r2]\n"
        "    bl sub_080F0194\n"
        "    adds r7, r0, #0\n"
        "    ldr r0, [r4, #8]\n"
        "    bl Exp_GetLevel\n"
        "    mov sl, r0\n"
        "    ldr r1, .L080E9F38\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    movs r5, #0\n"
        "    movs r3, #0x5d\n"
        "    adds r3, r3, r4\n"
        "    mov ip, r3\n"
        "    ldr r0, .L080E9F3C\n"
        "    mov r8, r0\n"
        ".L080E9E92:\n"
        "    lsls r0, r5, #0x10\n"
        "    asrs r2, r0, #0x10\n"
        "    mov r3, ip\n"
        "    adds r0, r3, r2\n"
        "    ldrb r3, [r0]\n"
        "    adds r0, r3, #0\n"
        "    cmp r0, #0xff\n"
        "    beq .L080E9EAE\n"
        "    mov r5, r8\n"
        "    adds r0, r2, r5\n"
        "    strb r3, [r0]\n"
        "    ldrh r0, [r1]\n"
        "    adds r0, #1\n"
        "    strh r0, [r1]\n"
        ".L080E9EAE:\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #0x1f\n"
        "    ble .L080E9E92\n"
        "    cmp r7, #0\n"
        "    beq .L080E9EE4\n"
        "    ldr r0, [r4, #8]\n"
        "    adds r0, r0, r7\n"
        "    str r0, [r4, #8]\n"
        "    ldr r1, .L080E9F40\n"
        "    cmp r0, r1\n"
        "    ble .L080E9ECE\n"
        "    ldr r0, .L080E9F44\n"
        "    str r0, [r4, #8]\n"
        ".L080E9ECE:\n"
        "    ldr r2, .L080E9F48\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r7, #0\n"
        "    bl Battle_BuildRewardText\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #7\n"
        "    bl BattleMenu_SetMode\n"
        "    movs r0, #1\n"
        "    mov sb, r0\n"
        ".L080E9EE4:\n"
        "    ldr r0, [r4, #8]\n"
        "    bl Exp_GetLevel\n"
        "    adds r4, r0, #0\n"
        "    ldr r1, .L080E9F30\n"
        "    adds r5, r6, r1\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r5, r2]\n"
        "    adds r1, r4, #0\n"
        "    bl Combatant_SetLevel\n"
        "    ldr r0, .L080E9F4C\n"
        "    mov r3, sl\n"
        "    subs r4, r4, r3\n"
        "    strh r4, [r0]\n"
        "    lsls r0, r4, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L080E9F60\n"
        "    ldr r1, .L080E9F50\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L080E9F54\n"
        "    adds r1, r6, r0\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r2, .L080E9F58\n"
        "    adds r1, r6, r2\n"
        "    movs r0, #0xa\n"
        "    strh r0, [r1]\n"
        "    ldr r3, .L080E9F5C\n"
        "    adds r0, r6, r3\n"
        "    strh r4, [r0]\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r5, r1]\n"
        "    bl Combatant_RecalcStats\n"
        "    b .L080EA168\n"
        "    .byte 0x00, 0x00\n"
        ".L080E9F30: .4byte 0x00000ECE\n"
        ".L080E9F34: .4byte 0xFFFF8000\n"
        ".L080E9F38: .4byte 0x0300005C @ IWRAM+0x5C\n"
        ".L080E9F3C: .4byte 0x03000060 @ IWRAM+0x60\n"
        ".L080E9F40: .4byte 0x0098967E\n"
        ".L080E9F44: .4byte 0x0098967F\n"
        ".L080E9F48: .4byte gUnknown_0812428E\n"
        ".L080E9F4C: .4byte 0x03000054 @ IWRAM+0x54\n"
        ".L080E9F50: .4byte 0x03000056 @ IWRAM+0x56\n"
        ".L080E9F54: .4byte 0x0000097C\n"
        ".L080E9F58: .4byte 0x0000097A\n"
        ".L080E9F5C: .4byte 0x00001178\n"
        ".L080E9F60:\n"
        "    ldr r2, .L080E9F78\n"
        "    adds r1, r6, r2\n"
        "    movs r0, #0xb\n"
        ".L080E9F66:\n"
        "    strh r0, [r1]\n"
        "    mov r3, sb\n"
        "    cmp r3, #0\n"
        "    bne .L080E9F70\n"
        "    b .L080EA168\n"
        ".L080E9F70:\n"
        "    movs r0, #0x14\n"
        "    bl sub_080E5A18\n"
        "    b .L080EA168\n"
        ".L080E9F78: .4byte 0x0000097A\n"
        ".L080E9F7C:\n"
        "    ldr r5, .L080E9F84\n"
        "    adds r1, r6, r5\n"
        "    b .L080EA0F6\n"
        "    .byte 0x00, 0x00\n"
        ".L080E9F84: .4byte 0x0000097A\n"
        ".L080E9F88:\n"
        "    bl BattleMsg_IsDone\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    beq .L080E9F96\n"
        "    b .L080EA168\n"
        ".L080E9F96:\n"
        "    ldr r0, .L080E9FCC\n"
        "    adds r1, r6, r0\n"
        "    movs r0, #0xc\n"
        "    strh r0, [r1]\n"
        "    ldr r2, .L080E9FD0\n"
        "    adds r1, r6, r2\n"
        "    ldr r3, .L080E9FD4\n"
        "    adds r0, r3, #0\n"
        "    ldrh r1, [r1]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    ldr r1, .L080E9FD8\n"
        "    bl Battle_BuildNamePrefixText\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #7\n"
        "    bl BattleMenu_SetMode\n"
        "    movs r0, #0xb\n"
        "    bl sub_080ECF60\n"
        "    movs r0, #0x67\n"
        "    bl sub_080ECF70\n"
        "    b .L080EA168\n"
        "    .byte 0x00, 0x00\n"
        ".L080E9FCC: .4byte 0x0000097A\n"
        ".L080E9FD0: .4byte 0x00000ECE\n"
        ".L080E9FD4: .4byte 0xFFFF8000\n"
        ".L080E9FD8: .4byte gUnknown_0812434A\n"
        ".L080E9FDC:\n"
        "    bl BattleMsg_IsDone\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    beq .L080E9FEA\n"
        "    b .L080EA168\n"
        ".L080E9FEA:\n"
        "    ldr r5, .L080EA01C\n"
        "    adds r1, r6, r5\n"
        "    ldr r2, .L080EA020\n"
        "    adds r0, r2, #0\n"
        "    ldrh r1, [r1]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    adds r4, r0, #0\n"
        "    ldrb r0, [r4, #0xc]\n"
        "    ldr r3, .L080EA024\n"
        "    adds r1, r6, r3\n"
        "    ldrh r1, [r1]\n"
        "    bl sub_080CE62C\n"
        "    bl BattleMsg_Close\n"
        "    ldr r5, .L080EA028\n"
        "    adds r1, r6, r5\n"
        "    movs r0, #0xd\n"
        "    strh r0, [r1]\n"
        "    b .L080EA168\n"
        "    .byte 0x00, 0x00\n"
        ".L080EA01C: .4byte 0x00000ECE\n"
        ".L080EA020: .4byte 0xFFFF8000\n"
        ".L080EA024: .4byte 0x00001178\n"
        ".L080EA028: .4byte 0x0000097A\n"
        ".L080EA02C:\n"
        "    bl BattleMsg_IsDone\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    beq .L080EA03A\n"
        "    b .L080EA168\n"
        ".L080EA03A:\n"
        "    ldr r0, .L080EA090\n"
        "    adds r5, r6, r0\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r5, r1]\n"
        "    bl Party_BuildSkillList\n"
        "    ldr r7, .L080EA094\n"
        "    movs r2, #0\n"
        "    ldrsh r4, [r7, r2]\n"
        "    movs r3, #0\n"
        "    ldrsh r0, [r5, r3]\n"
        "    bl Party_GetSkillCount\n"
        "    cmp r4, r0\n"
        "    bge .L080EA0A4\n"
        "    ldr r1, .L080EA098\n"
        "    adds r0, r1, #0\n"
        "    ldrh r5, [r5]\n"
        "    adds r0, r0, r5\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    ldr r2, .L080EA09C\n"
        "    movs r1, #0\n"
        "    strh r1, [r2]\n"
        "    movs r2, #0\n"
        "    ldrsh r1, [r7, r2]\n"
        "    adds r0, #0x5d\n"
        "    adds r0, r0, r1\n"
        "    ldrb r0, [r0]\n"
        "    bl sub_080EB008\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetMode\n"
        "    ldr r3, .L080EA0A0\n"
        "    adds r1, r6, r3\n"
        "    movs r0, #0x12\n"
        "    strh r0, [r1]\n"
        "    b .L080EA168\n"
        "    .byte 0x00, 0x00\n"
        ".L080EA090: .4byte 0x00000ECE\n"
        ".L080EA094: .4byte 0x0300005C @ IWRAM+0x5C\n"
        ".L080EA098: .4byte 0xFFFF8000\n"
        ".L080EA09C: .4byte 0x0300005E @ IWRAM+0x5E\n"
        ".L080EA0A0: .4byte 0x0000097A\n"
        ".L080EA0A4:\n"
        "    ldr r5, .L080EA0AC\n"
        "    adds r1, r6, r5\n"
        "    b .L080EA0F6\n"
        "    .byte 0x00, 0x00\n"
        ".L080EA0AC: .4byte 0x0000097A\n"
        ".L080EA0B0:\n"
        "    bl BattleMsg_IsDone\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bne .L080EA168\n"
        "    ldr r0, .L080EA0FC\n"
        "    adds r1, r6, r0\n"
        "    ldr r2, .L080EA100\n"
        "    adds r0, r2, #0\n"
        "    ldrh r1, [r1]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    ldr r2, .L080EA104\n"
        "    ldrh r1, [r2]\n"
        "    adds r1, #1\n"
        "    strh r1, [r2]\n"
        "    ldr r1, .L080EA108\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r1, r3]\n"
        "    movs r5, #0\n"
        "    ldrsh r2, [r2, r5]\n"
        "    adds r1, r1, r2\n"
        "    adds r0, #0x5d\n"
        "    adds r1, r0, r1\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0xff\n"
        "    bne .L080EA110\n"
        "    bl BattleMenu_Reset\n"
        "    ldr r0, .L080EA10C\n"
        "    adds r1, r6, r0\n"
        ".L080EA0F6:\n"
        "    movs r0, #0xb\n"
        "    strh r0, [r1]\n"
        "    b .L080EA168\n"
        ".L080EA0FC: .4byte 0x00000ECE\n"
        ".L080EA100: .4byte 0xFFFF8000\n"
        ".L080EA104: .4byte 0x0300005E @ IWRAM+0x5E\n"
        ".L080EA108: .4byte 0x0300005C @ IWRAM+0x5C\n"
        ".L080EA10C: .4byte 0x0000097A\n"
        ".L080EA110:\n"
        "    ldrb r0, [r1]\n"
        "    bl sub_080EB008\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetMode\n"
        "    b .L080EA168\n"
        ".L080EA120:\n"
        "    ldr r2, .L080EA140\n"
        "    adds r1, r6, r2\n"
        "    ldrh r0, [r1]\n"
        "    adds r0, #1\n"
        "    strh r0, [r1]\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #3\n"
        "    ble .L080EA148\n"
        "    ldr r3, .L080EA144\n"
        "    adds r0, r6, r3\n"
        "    movs r1, #0x10\n"
        ".L080EA138:\n"
        "    strh r1, [r0]\n"
        "    movs r0, #1\n"
        "    strh r0, [r4, #0x1c]\n"
        "    b .L080EA168\n"
        ".L080EA140: .4byte 0x00000ECE\n"
        ".L080EA144: .4byte 0x00000978\n"
        ".L080EA148:\n"
        "    ldr r5, .L080EA154\n"
        "    adds r1, r6, r5\n"
        ".L080EA14C:\n"
        "    movs r0, #9\n"
        "    strh r0, [r1]\n"
        "    b .L080EA168\n"
        "    .byte 0x00, 0x00\n"
        ".L080EA154: .4byte 0x0000097A\n"
        ".L080EA158:\n"
        "    bl BattleMsg_IsDone\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bne .L080EA168\n"
        "    bl sub_080E5A3C\n"
        ".L080EA168:\n"
        "    add sp, #4\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif
