/* Battle: the per-action step machine that resolves one attack, skill or item (damage,
   affinities, ailments, reflection, HP loss and the messages for each). */

#include "global.h"

/* The battle EWRAM block at 0x0203C200: only the fields used here. */
struct F17C0Battle
{
    u8 pad000[0x97C];
    u16 phase;          /* 0x97C: battle turn phase */
    s16 step;           /* 0x97E: step of the action being resolved */
    u8 pad980[0xEC0 - 0x980];
    u8 unkEC0;          /* 0xEC0: an enemy was hit (sprite update) */
    u8 padEC1[0xECA - 0xEC1];
    s16 sound;          /* 0xECA */
    u8 padECC[0xF66 - 0xECC];
    s16 unkF66;         /* 0xF66 */
    u8 padF68[0x1194 - 0xF68];
    u16 unk1194;        /* 0x1194: skill of item 0xF8 */
    u8 pad1196[0x11B0 - 0x1196];
    u16 critical;       /* 0x11B0: critical-hit kind of the last damage roll */
};
extern u8 gUnk_0203C200[];
#define BB ((struct F17C0Battle *)gUnk_0203C200)

/* gGameState (0x030046C0): only the field used here. */
struct F17C0GameState
{
    u8 pad000[0xA20];
    s8 order[0x20];     /* 0xA20: combatant in each formation position */
};
extern struct F17C0GameState gGameState;

/* The action being resolved (as struct Action in battle2.h). */
struct F17C0Action
{
    s32 att;            /* 0x00 */
    s32 def;            /* 0x04 */
    s32 msg;            /* 0x08: -1 = default message, 0x16E reflected */
    s32 result;         /* 0x0C */
    u8 pad10[0x18 - 0x10];
    s32 dmg;            /* 0x18: 0xFFFF = no damage, message only */
};
extern struct F17C0Action gUnk_03000088;
extern u16 gUnk_03000082;
extern u16 gUnk_030000AC;   /* step to go to once the message is done, 0xFFFF none */
extern s16 gUnk_030000AE;   /* 1 = ailment/instant-death skill */

/* One combatant (0x80 bytes): only the fields used here. */
struct F17C0Combatant
{
    u8 pad00[0x12];
    s16 demonId;        /* 0x12 */
    u8 pad14[0x17 - 0x14];
    s8 command;         /* 0x17 */
    s16 hp;             /* 0x18 */
    u8 pad1A[0x1E - 0x1A];
    s16 maxMp;          /* 0x1E */
    u8 pad20[0x5C - 0x20];
    u8 chosen;          /* 0x5C */
};

extern const u16 gUnknown_08124316[], gUnknown_081242EC[], gUnknown_081242FC[];
extern const u16 gUnknown_08124218[], gUnknown_08124234[];
extern const u16 gUnknown_081241F0[], gUnknown_08124200[];
extern const u16 gUnknown_08123BCC[], gUnknown_0812310C[];

s32 sub_080EFFF8(s32 who, s32 x);
struct F17C0Combatant *Battle_GetCombatant(u16 idx);
struct F17C0Combatant *Party_GetMember(u16 id);
void Item_GetAttribute(s32 id, s32 field, s32 *out);
void sub_080EDA7C(u32 v);
u16 sub_080EDA90(void);
u32 sub_080EDAD0(void);
u32 Combatant_IsDead(s32 who);
const u8 *sub_080BF5C0(u16 id);
s32 Battle_PhysicalDamage(s32 att, s32 def);
void Combatant_SetChosenSkill(s32 who, u16 skill);
void Battle_SkillDamage(struct F17C0Action *act);
u32 sub_080EF0E4(s32 who);
u16 *Battle_GetMessage(s32 id);
s16 sub_080F3E44(void);
u16 *Menu_ExpandListTemplate(const u16 *tmpl, u32 arg);
void BattleMenu_SetModeAutoClose(u8 mode, const u16 *src);
u32 Combatant_SetStatus(s32 who, u16 bits);
void Battle_SetHp(s32 who, s32 v);
void sub_080F4190(s32 who);
void Party_FixFormation(void);
s32 Battle_RollAilment(struct F17C0Action *a, s32 skill);
u16 Combatant_GetStatus(s32 who);
u32 sub_080EED88(struct F17C0Action *act);
u32 sub_080EFE60(s32 who);
s32 Combatant_GetAffinity(s32 who, s32 kind);
u32 BattleFlags_Get(void);
u32 sub_080EED64(u16 kind, u16 id);
s32 Battle_ApplyAffinity(s32 v, s32 aff);
s32 Battle_GetHp(s32 who);
s32 Battle_GetMaxHp(s32 who);
s32 Combatant_ChangeHp(s32 who, s32 delta);
s32 Combatant_AddHp(s32 who, s32 d);
u8 BattleMsg_IsDone(void);
void sub_080C08E8(s32 who, u16 bits);
s32 Party_FindPosition(s32 id);
s16 Hud_GetMemberFace(s16 slot);
void sub_080C8490(s32 slot);
void sub_080F0344(u16 kind, u16 v);
s32 Battle_IsEnemyId(s32 who);
u16 *Battle_BuildActorStatusText(struct F17C0Combatant *actor, const u16 *tmpl);
u16 *Battle_BuildNamePrependText(s32 idx, const u16 *suffix);
u16 *Battle_BuildDamageDealtText(struct F17C0Combatant *actor, u32 value, const u16 *tmpl);
void sub_080F2AC8(s16 who);
s32 sub_080F3214(s32 who, u16 a);
s32 sub_080C35E4(s32 who);
s32 Combatant_GetChosenSkill(s32 who);
s32 sub_080ED494(s32 id);
s16 Combatant_GetDemonId(s32 who);
u32 Battle_IsTwoSided(void);
u32 sub_080ED974(s32 who);
void sub_080E8AFC(u8 slot);
void sub_080C86F4(u16 slot);
void sub_080ECF70(s32 a);

void Battle_ReflectAction(void);
void Battle_ApplyDamage(void);

// Battle_ResolveActionStep @ 0x080F17C0
/* One step (+0x97E) of resolving combatant c's action on its target:
    0 set up gUnk_03000088; physical attacks go to 1, ailment skills (0x13-0x1C, or skills
      flagged 0x10) to 3, other skills to 2
    1 physical damage, 2 skill/item damage (0x66/0x67 instant kill, 0x63-0x65 and 0x54/0x55/0x5E
      special cases, damage 0xFFFF = message only), 3 ailment roll (Battle_RollAilment)
    4 hit check (sub_080EED88), reflection (message 0x16E -> Battle_ReflectAction)
    5 affinity: absorb (14/15) heals, null (0) misses, reflect (12/13)
    6 sub_080F2AC8, 7 wait for the message then end the action, 8 "missed", 9 "no effect"
   10 critical-hit message, 11 wait, 12 apply damage (Battle_ApplyDamage) and ailments,
   13 wait then go to the step saved in gUnk_030000AC. */
#ifdef NONMATCHING
void Battle_ResolveActionStep(struct F17C0Combatant *c, s16 who)
{
    struct F17C0Battle *b = BB;
    u16 kind = c->command;
    s32 item = c->chosen;
    s32 had;
    u16 target = sub_080EFFF8(who, b->unkF66);
    struct F17C0Combatant *d = Battle_GetCombatant(target + 0x8000);

    if (kind == 8)
    {
        if (item == 0xF8)
            item = b->unk1194;
        else
            Item_GetAttribute(item, 0xC, &item);
    }
    switch (b->step)
    {
    case 0:
        sub_080EDA7C(0);
        gUnk_03000088.att = who;
        gUnk_03000088.def = (s16)target;
        gUnk_03000088.dmg = 0;
        gUnk_03000088.result = 1;
        gUnk_03000082 = 0;
        if ((u16)((s16)kind - 4) <= 1 || (s16)kind == 10)
        {
            gUnk_030000AE = 0;
            b->step = 1;
            if (Combatant_IsDead((s16)target))
                b->phase = 10;
        }
        else if ((u32)(item - 0x13) <= 9 || (item > 0x3F && (sub_080BF5C0(item)[0] & 0x10)))
        {
            gUnk_030000AE = 1;
            b->step = 3;
        }
        else
        {
            gUnk_030000AE = 0;
            b->step = 2;
        }
        break;
    case 1:
        gUnk_03000088.dmg = Battle_PhysicalDamage(who, (s16)target);
        if (gUnk_03000088.dmg == 0)
            b->step = 8;
        else
            b->step = 4;
        break;
    case 2:
        if (kind == 8)
        {
            u8 orig;

            item = c->chosen;
            orig = item;
            if (orig == 0xF8)
                item = b->unk1194;
            else
                Item_GetAttribute(orig, 0xC, &item);
            Combatant_SetChosenSkill(who, item);
            Battle_SkillDamage(&gUnk_03000088);
            Combatant_SetChosenSkill(who, orig);
        }
        else
        {
            u8 sk;

            Battle_SkillDamage(&gUnk_03000088);
            sk = c->chosen;
            if (sk == 0x5C || sk == 0x61)
            {
                if (gUnk_03000088.dmg != 0)
                    b->step = 12;
                else
                    b->step = 8;
                break;
            }
            if ((u8)(sk - 0x66) <= 1)
            {
                b->step = 7;
                if (gUnk_03000088.result != 1)
                    break;
                if (sub_080EF0E4(gUnk_03000088.def))
                {
                    BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(Battle_GetMessage(0x171), sub_080F3E44() << 16));
                    sub_080F0344(4, 13);
                }
                else
                {
                    s32 def = gUnk_03000088.def;

                    Combatant_SetStatus(def, 0x8000);
                    Battle_SetHp(def, 0);
                    if ((u32)(def - 4) <= 0xB)
                        sub_080F4190(def);
                    Party_FixFormation();
                }
                break;
            }
            if ((u8)(sk - 0x63) <= 2)
            {
                if (gUnk_03000088.dmg != 0)
                {
                    gUnk_030000AE = 1;
                    b->step = 12;
                }
                else
                    b->step = 7;
                break;
            }
            if ((u8)(sk - 0x54) <= 1 || sk == 0x5E)
            {
                if (gUnk_03000088.msg != -1)
                    BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(Battle_GetMessage(gUnk_03000088.msg), gUnk_03000088.def));
                b->step = 7;
                break;
            }
        }
        if (gUnk_03000088.dmg == 0xFFFF)
        {
            if (gUnk_03000088.msg != -1)
            {
                s32 x = gUnk_03000088.def;

                if (x == -1)
                    x = gUnk_03000088.att;
                BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(Battle_GetMessage(gUnk_03000088.msg), x + (sub_080F3E44() << 16)));
            }
            if (gUnk_03000088.result == 1 && (u32)(item - 0x9E) <= 1)
                b->unkEC0 = 1;
            b->phase = 11;
        }
        else if (gUnk_03000088.dmg == 0)
            b->step = 8;
        else
            b->step = 4;
        break;
    case 3:
    {
        s32 def = gUnk_03000088.def;
        u16 ail;

        had = Battle_RollAilment(&gUnk_03000088, item);
        gUnk_030000AC = 0xFFFF;
        if (gUnk_03000088.msg != -1)
        {
            BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(Battle_GetMessage(gUnk_03000088.msg), def));
            gUnk_030000AC = 0;
        }
        ail = sub_080EDA90();
        if (ail == 0xFFFF)
        {
            u16 dead = Combatant_GetStatus(gUnk_03000088.def) & 0x8000;

            if (dead)
                b->phase = 10;
            else if (!had)
                b->step = 8;
            else
            {
                BattleMenu_SetModeAutoClose(3, gUnknown_08124316);
                b->step = 7;
                gUnk_030000AC = dead;
            }
        }
        else if (ail == 0)
            b->step = 9;
        else if (gUnk_03000088.msg != -1)
            b->step = 10;
        else
            b->step = 4;
        if (gUnk_030000AC != 0xFFFF)
            sub_080F0344(4, 13);
        break;
    }
    case 4:
        if (!sub_080EED88(&gUnk_03000088))
        {
            if (gUnk_030000AE == 1)
                b->step = 10;
            else
                b->step = 5;
        }
        else if (gUnk_03000088.msg == 0x16E)
        {
            Battle_ReflectAction();
            if (b->step != 9)
            {
                if (gUnk_03000088.dmg == 0)
                    b->step = 8;
                else
                    b->step = 10;
            }
            sub_080F0344(4, 13);
        }
        else
            b->step = 9;
        break;
    case 5:
    {
        s32 aff = Combatant_GetAffinity(gUnk_03000088.def, sub_080EFE60(gUnk_03000088.att));

        if (gUnk_03000088.def <= 15)
        {
            if ((BattleFlags_Get() & 0x400) && kind == 10)
            {
                if (c->demonId > 0xB1)
                    aff = 13;
            }
            else if (gUnk_03000088.def <= 15 && (BattleFlags_Get() & 0x400) && sub_080EED64(kind, item) == 1)
            {
                if (c->demonId > 0xB1)
                    aff = 13;
            }
        }
        gUnk_03000088.dmg = Battle_ApplyAffinity(gUnk_03000088.dmg, aff);
        if (d->hp < gUnk_03000088.dmg)
            gUnk_03000088.dmg = d->hp;
        gUnk_030000AC = 0xFFFF;
        switch (aff)
        {
        case 14:
        case 15:
        {
            s16 hp = Battle_GetHp(gUnk_03000088.def);
            s16 max = Battle_GetMaxHp(gUnk_03000088.def);

            if (hp + gUnk_03000088.dmg > max)
                gUnk_03000088.dmg = max - hp;
            Combatant_ChangeHp(gUnk_03000088.def, gUnk_03000088.dmg);
        }
        /* fallthrough */
        case 0:
            b->step = 9;
            break;
        case 12:
        case 13:
            Battle_ReflectAction();
            if (b->step == 9)
            {
                sub_080F0344(4, 13);
                break;
            }
            gUnk_030000AC = 0;
            /* fallthrough */
        default:
            if (gUnk_03000088.dmg == 0)
                b->step = 8;
            else
                b->step = 10;
            if (gUnk_030000AC != 0xFFFF)
                sub_080F0344(4, 13);
            break;
        }
        break;
    }
    case 11:
        if (BattleMsg_IsDone() == 1)
            b->step = 12;
        break;
    case 10:
        if (b->critical != 0)
        {
            if (b->critical == 1)
                BattleMenu_SetModeAutoClose(3, gUnknown_081242EC);
            else
                BattleMenu_SetModeAutoClose(3, gUnknown_081242FC);
            b->critical = 0;
            b->step = 11;
            break;
        }
        /* fallthrough */
    case 12:
    {
        u16 ail;

        if (Battle_GetHp(gUnk_03000088.def) <= 0 || (Combatant_GetStatus(gUnk_03000088.def) & 0x8000))
        {
            b->phase = 10;
            break;
        }
        Battle_ApplyDamage();
        ail = sub_080EDA90();
        if (ail == 0 || ail == 0xFFFF)
            b->step = 7;
        else if (sub_080EDAD0() && (ail & 0x3204) && gUnk_03000088.def > 15)
        {
            if (gUnk_030000AE == 1)
                b->step = 9;
            else
                b->step = 7;
        }
        else
        {
            sub_080C08E8(gUnk_03000088.def, ail);
            if (Battle_GetHp(gUnk_03000088.def) <= 0)
                b->step = 7;
            else
            {
                b->step = 6;
                if (gUnk_03000088.def <= 15)
                {
                    s16 p = Party_FindPosition(gUnk_03000088.def);

                    if (Hud_GetMemberFace(p) <= 0x12)
                        sub_080C8490(p);
                }
                else
                    b->unkEC0 = 1;
            }
            if (ail == 0x2000 && (u32)(gUnk_03000088.def - 4) <= 0xB)
            {
                sub_080F4190(gUnk_03000088.def);
                Party_FixFormation();
            }
        }
        sub_080F0344(4, 13);
        break;
    }
    case 8:
        if (Battle_IsEnemyId(gUnk_03000088.def) == 1)
            BattleMenu_SetModeAutoClose(3, gUnknown_08124218);
        else
            BattleMenu_SetModeAutoClose(3, Battle_BuildActorStatusText(Battle_GetCombatant(gUnk_03000088.def + 0x8000), gUnknown_08124234));
        b->step = 7;
        break;
    case 9:
    {
        s32 msg = 0x154;

        if (Battle_IsEnemyId(gUnk_03000088.def) == 1)
            msg--;
        BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(Battle_GetMessage(msg), gUnk_03000088.def));
        b->step = 7;
        break;
    }
    case 6:
        sub_080F2AC8(who);
        b->step = 7;
        break;
    case 7:
        if (BattleMsg_IsDone() == 1)
        {
            if (Combatant_GetStatus(gUnk_03000088.def) & 0x4000)
                b->phase = 10;
            else if (Battle_GetHp(gUnk_03000088.def) <= 0 || (Combatant_GetStatus(gUnk_03000088.def) & 0x8000))
                b->phase = 9;
            else
                b->phase = 10;
        }
        break;
    case 13:
        if (BattleMsg_IsDone() == 1)
            b->step = gUnk_030000AC;
        break;
    }
}
#else
NAKED void Battle_ResolveActionStep(struct F17C0Combatant *c, s16 who)
{
    asm_unified(
        ".L080F17C0:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #8\n"
        "    adds r7, r0, #0\n"
        "    lsls r0, r1, #0x10\n"
        "    ldr r6, .L080F181C\n"
        "    movs r1, #0x17\n"
        "    ldrsb r1, [r7, r1]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    mov r8, r1\n"
        "    adds r1, r7, #0\n"
        "    adds r1, #0x5c\n"
        "    ldrb r1, [r1]\n"
        "    str r1, [sp]\n"
        "    lsrs r4, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    ldr r2, .L080F1820\n"
        "    adds r1, r6, r2\n"
        "    movs r3, #0\n"
        "    ldrsh r1, [r1, r3]\n"
        "    bl sub_080EFFF8\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #0x18\n"
        "    adds r0, r0, r1\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    mov sb, r0\n"
        "    mov r2, r8\n"
        "    cmp r2, #8\n"
        "    bne .L080F1830\n"
        "    ldr r0, [sp]\n"
        "    cmp r0, #0xf8\n"
        "    bne .L080F1828\n"
        "    ldr r3, .L080F1824\n"
        "    adds r0, r6, r3\n"
        "    ldrh r0, [r0]\n"
        "    str r0, [sp]\n"
        "    b .L080F1830\n"
        ".L080F181C: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080F1820: .4byte 0x00000F66\n"
        ".L080F1824: .4byte 0x00001194\n"
        ".L080F1828:\n"
        "    movs r1, #0xc\n"
        "    mov r2, sp\n"
        "    bl Item_GetAttribute\n"
        ".L080F1830:\n"
        "    ldr r1, .L080F184C\n"
        "    adds r0, r6, r1\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r0, r2]\n"
        "    cmp r0, #0xd\n"
        "    bls .L080F1840\n"
        "    bl .L080F20C6\n"
        ".L080F1840:\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L080F1850\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080F184C: .4byte 0x0000097E\n"
        ".L080F1850: .4byte gUnknown_080F1854\n"
        "    .global gUnknown_080F1854\n"
        "gUnknown_080F1854:\n"
        ".L080F1854: @ jump table\n"
        "    .4byte .L080F188C\n"
        "    .4byte .L080F1944\n"
        "    .4byte .L080F1974\n"
        "    .4byte .L080F1B5C\n"
        "    .4byte .L080F1C4C\n"
        "    .4byte .L080F1CBC\n"
        "    .4byte .L080F2034\n"
        "    .4byte .L080F204C\n"
        "    .4byte .L080F1FB0\n"
        "    .4byte .L080F2000\n"
        "    .4byte .L080F1E48\n"
        "    .4byte .L080F1E2C\n"
        "    .4byte .L080F1E84\n"
        "    .4byte .L080F20B0\n"
        ".L080F188C:\n"
        "    movs r0, #0\n"
        "    bl sub_080EDA7C\n"
        "    ldr r1, .L080F18DC\n"
        "    lsls r0, r4, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    str r0, [r1]\n"
        "    lsls r0, r5, #0x10\n"
        "    asrs r3, r0, #0x10\n"
        "    str r3, [r1, #4]\n"
        "    movs r2, #0\n"
        "    str r2, [r1, #0x18]\n"
        "    movs r4, #1\n"
        "    str r4, [r1, #0xc]\n"
        "    ldr r0, .L080F18E0\n"
        "    strh r2, [r0]\n"
        "    mov r5, r8\n"
        "    lsls r0, r5, #0x10\n"
        "    asrs r1, r0, #0x10\n"
        "    ldr r5, .L080F18E4\n"
        "    adds r0, r0, r5\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bls .L080F18C0\n"
        "    cmp r1, #0xa\n"
        "    bne .L080F18F0\n"
        ".L080F18C0:\n"
        "    ldr r0, .L080F18E8\n"
        "    strh r2, [r0]\n"
        "    ldr r1, .L080F18EC\n"
        "    adds r0, r6, r1\n"
        "    strh r4, [r0]\n"
        "    adds r0, r3, #0\n"
        "    bl Combatant_IsDead\n"
        "    cmp r0, #0\n"
        "    bne .L080F18D8\n"
        "    bl .L080F20C6\n"
        ".L080F18D8:\n"
        "    bl .L080F20A0\n"
        ".L080F18DC: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F18E0: .4byte 0x03000082 @ IWRAM+0x82\n"
        ".L080F18E4: .4byte 0xFFFC0000\n"
        ".L080F18E8: .4byte 0x030000AE @ IWRAM+0xAE\n"
        ".L080F18EC: .4byte 0x0000097E\n"
        ".L080F18F0:\n"
        "    ldr r1, [sp]\n"
        "    adds r0, r1, #0\n"
        "    subs r0, #0x13\n"
        "    cmp r0, #9\n"
        "    bls .L080F1910\n"
        "    cmp r1, #0x3f\n"
        "    ble .L080F1928\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl sub_080BF5C0\n"
        "    ldrb r1, [r0]\n"
        "    movs r0, #0x10\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080F1928\n"
        ".L080F1910:\n"
        "    ldr r0, .L080F1920\n"
        "    strh r4, [r0]\n"
        "    ldr r3, .L080F1924\n"
        "    adds r1, r6, r3\n"
        "    movs r0, #3\n"
        "    strh r0, [r1]\n"
        "    bl .L080F20C6\n"
        ".L080F1920: .4byte 0x030000AE @ IWRAM+0xAE\n"
        ".L080F1924: .4byte 0x0000097E\n"
        ".L080F1928:\n"
        "    ldr r1, .L080F193C\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r5, .L080F1940\n"
        "    adds r1, r6, r5\n"
        "    movs r0, #2\n"
        "    strh r0, [r1]\n"
        "    bl .L080F20C6\n"
        "    .byte 0x00, 0x00\n"
        ".L080F193C: .4byte 0x030000AE @ IWRAM+0xAE\n"
        ".L080F1940: .4byte 0x0000097E\n"
        ".L080F1944:\n"
        "    lsls r0, r4, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    lsls r1, r5, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    bl Battle_PhysicalDamage\n"
        "    ldr r1, .L080F1960\n"
        "    str r0, [r1, #0x18]\n"
        "    cmp r0, #0\n"
        "    bne .L080F1968\n"
        "    ldr r0, .L080F1964\n"
        "    adds r1, r6, r0\n"
        "    b .L080F1B40\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1960: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F1964: .4byte 0x0000097E\n"
        ".L080F1968:\n"
        "    ldr r2, .L080F1970\n"
        "    adds r1, r6, r2\n"
        "    b .L080F1B50\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1970: .4byte 0x0000097E\n"
        ".L080F1974:\n"
        "    mov r3, r8\n"
        "    cmp r3, #8\n"
        "    bne .L080F19C8\n"
        "    adds r0, r7, #0\n"
        "    adds r0, #0x5c\n"
        "    ldrb r0, [r0]\n"
        "    str r0, [sp]\n"
        "    adds r5, r0, #0\n"
        "    cmp r5, #0xf8\n"
        "    bne .L080F1998\n"
        "    ldr r1, .L080F1994\n"
        "    adds r0, r6, r1\n"
        "    ldrh r0, [r0]\n"
        "    str r0, [sp]\n"
        "    b .L080F19A2\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1994: .4byte 0x00001194\n"
        ".L080F1998:\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #0xc\n"
        "    mov r2, sp\n"
        "    bl Item_GetAttribute\n"
        ".L080F19A2:\n"
        "    lsls r4, r4, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    ldr r1, [sp]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_SetChosenSkill\n"
        "    ldr r0, .L080F19C4\n"
        "    bl Battle_SkillDamage\n"
        "    adds r1, r5, #0\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_SetChosenSkill\n"
        "    b .L080F1AD2\n"
        "    .byte 0x00, 0x00\n"
        ".L080F19C4: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F19C8:\n"
        "    ldr r4, .L080F19EC\n"
        "    adds r0, r4, #0\n"
        "    bl Battle_SkillDamage\n"
        "    adds r0, r7, #0\n"
        "    adds r0, #0x5c\n"
        "    ldrb r1, [r0]\n"
        "    adds r2, r1, #0\n"
        "    cmp r2, #0x5c\n"
        "    beq .L080F19E0\n"
        "    cmp r2, #0x61\n"
        "    bne .L080F1A00\n"
        ".L080F19E0:\n"
        "    ldr r0, [r4, #0x18]\n"
        "    cmp r0, #0\n"
        "    beq .L080F19F4\n"
        "    ldr r2, .L080F19F0\n"
        "    adds r1, r6, r2\n"
        "    b .L080F1E3E\n"
        ".L080F19EC: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F19F0: .4byte 0x0000097E\n"
        ".L080F19F4:\n"
        "    ldr r3, .L080F19FC\n"
        "    adds r1, r6, r3\n"
        "    b .L080F1B40\n"
        "    .byte 0x00, 0x00\n"
        ".L080F19FC: .4byte 0x0000097E\n"
        ".L080F1A00:\n"
        "    adds r0, r1, #0\n"
        "    subs r0, #0x66\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bhi .L080F1A76\n"
        "    ldr r5, .L080F1A48\n"
        "    adds r0, r6, r5\n"
        "    movs r1, #7\n"
        "    strh r1, [r0]\n"
        "    ldr r0, [r4, #0xc]\n"
        "    cmp r0, #1\n"
        "    beq .L080F1A1C\n"
        "    b .L080F20C6\n"
        ".L080F1A1C:\n"
        "    ldr r0, [r4, #4]\n"
        "    bl sub_080EF0E4\n"
        "    cmp r0, #0\n"
        "    beq .L080F1A50\n"
        "    ldr r0, .L080F1A4C\n"
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
        "    b .L080F1FA0\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1A48: .4byte 0x0000097E\n"
        ".L080F1A4C: .4byte 0x00000171\n"
        ".L080F1A50:\n"
        "    ldr r4, [r4, #4]\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_SetStatus\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0\n"
        "    bl Battle_SetHp\n"
        "    subs r0, r4, #4\n"
        "    cmp r0, #0xb\n"
        "    bhi .L080F1A70\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080F4190\n"
        ".L080F1A70:\n"
        "    bl Party_FixFormation\n"
        "    b .L080F20C6\n"
        ".L080F1A76:\n"
        "    adds r0, r1, #0\n"
        "    subs r0, #0x63\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #2\n"
        "    bhi .L080F1AA0\n"
        "    ldr r0, [r4, #0x18]\n"
        "    cmp r0, #0\n"
        "    beq .L080F1A94\n"
        "    ldr r1, .L080F1A90\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    b .L080F1E3A\n"
        ".L080F1A90: .4byte 0x030000AE @ IWRAM+0xAE\n"
        ".L080F1A94:\n"
        "    ldr r2, .L080F1A9C\n"
        "    adds r1, r6, r2\n"
        "    b .L080F2040\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1A9C: .4byte 0x0000097E\n"
        ".L080F1AA0:\n"
        "    adds r0, r1, #0\n"
        "    subs r0, #0x54\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bls .L080F1AB0\n"
        "    cmp r2, #0x5e\n"
        "    bne .L080F1AD2\n"
        ".L080F1AB0:\n"
        "    ldr r1, [r4, #8]\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r1, r0\n"
        "    bne .L080F1ABC\n"
        "    b .L080F203C\n"
        ".L080F1ABC:\n"
        "    adds r0, r1, #0\n"
        "    bl Battle_GetMessage\n"
        "    ldr r1, [r4, #4]\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    b .L080F203C\n"
        ".L080F1AD2:\n"
        "    ldr r2, .L080F1B2C\n"
        "    ldr r1, [r2, #0x18]\n"
        "    ldr r0, .L080F1B30\n"
        "    cmp r1, r0\n"
        "    bne .L080F1B38\n"
        "    ldr r0, [r2, #8]\n"
        "    movs r1, #1\n"
        "    rsbs r1, r1, #0\n"
        "    cmp r0, r1\n"
        "    beq .L080F1B0C\n"
        "    ldr r5, [r2, #4]\n"
        "    cmp r5, r1\n"
        "    bne .L080F1AEE\n"
        "    ldr r5, [r2]\n"
        ".L080F1AEE:\n"
        "    bl Battle_GetMessage\n"
        "    adds r4, r0, #0\n"
        "    bl sub_080F3E44\n"
        "    adds r1, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    adds r1, r5, r1\n"
        "    adds r0, r4, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        ".L080F1B0C:\n"
        "    ldr r0, .L080F1B2C\n"
        "    ldr r1, [r0, #0xc]\n"
        "    cmp r1, #1\n"
        "    bne .L080F1B24\n"
        "    ldr r0, [sp]\n"
        "    subs r0, #0x9e\n"
        "    cmp r0, #1\n"
        "    bhi .L080F1B24\n"
        "    movs r5, #0xec\n"
        "    lsls r5, r5, #4\n"
        "    adds r0, r6, r5\n"
        "    strb r1, [r0]\n"
        ".L080F1B24:\n"
        "    ldr r0, .L080F1B34\n"
        "    adds r1, r6, r0\n"
        "    b .L080F1E74\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1B2C: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F1B30: .4byte 0x0000FFFF\n"
        ".L080F1B34: .4byte 0x0000097C\n"
        ".L080F1B38:\n"
        "    cmp r1, #0\n"
        "    bne .L080F1B4C\n"
        "    ldr r2, .L080F1B48\n"
        "    adds r1, r6, r2\n"
        ".L080F1B40:\n"
        "    movs r0, #8\n"
        "    strh r0, [r1]\n"
        "    b .L080F20C6\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1B48: .4byte 0x0000097E\n"
        ".L080F1B4C:\n"
        "    ldr r3, .L080F1B58\n"
        "    adds r1, r6, r3\n"
        ".L080F1B50:\n"
        "    movs r0, #4\n"
        "    strh r0, [r1]\n"
        "    b .L080F20C6\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1B58: .4byte 0x0000097E\n"
        ".L080F1B5C:\n"
        "    ldr r7, .L080F1BC0\n"
        "    ldr r5, [r7, #4]\n"
        "    ldr r1, [sp]\n"
        "    adds r0, r7, #0\n"
        "    bl Battle_RollAilment\n"
        "    str r0, [sp, #4]\n"
        "    ldr r0, .L080F1BC4\n"
        "    mov r8, r0\n"
        "    ldr r1, .L080F1BC8\n"
        "    mov sb, r1\n"
        "    strh r1, [r0]\n"
        "    ldr r0, [r7, #8]\n"
        "    movs r2, #1\n"
        "    rsbs r2, r2, #0\n"
        "    mov sl, r2\n"
        "    cmp r0, sl\n"
        "    beq .L080F1B98\n"
        "    bl Battle_GetMessage\n"
        "    adds r1, r5, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    movs r0, #0\n"
        "    mov r3, r8\n"
        "    strh r0, [r3]\n"
        ".L080F1B98:\n"
        "    bl sub_080EDA90\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, sb\n"
        "    bne .L080F1C04\n"
        "    ldr r0, [r7, #4]\n"
        "    bl Combatant_GetStatus\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    ands r1, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r4, r1, #0x10\n"
        "    cmp r4, #0\n"
        "    beq .L080F1BD0\n"
        "    ldr r5, .L080F1BCC\n"
        "    adds r1, r6, r5\n"
        "    movs r0, #0xa\n"
        "    b .L080F1C2E\n"
        ".L080F1BC0: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F1BC4: .4byte 0x030000AC @ IWRAM+0xAC\n"
        ".L080F1BC8: .4byte 0x0000FFFF\n"
        ".L080F1BCC: .4byte 0x0000097C\n"
        ".L080F1BD0:\n"
        "    ldr r0, [sp, #4]\n"
        "    cmp r0, #0\n"
        "    bne .L080F1BE4\n"
        "    ldr r2, .L080F1BE0\n"
        "    adds r1, r6, r2\n"
        "    movs r0, #8\n"
        "    b .L080F1C2E\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1BE0: .4byte 0x0000097E\n"
        ".L080F1BE4:\n"
        "    ldr r1, .L080F1BFC\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    ldr r3, .L080F1C00\n"
        "    adds r1, r6, r3\n"
        "    movs r0, #7\n"
        "    strh r0, [r1]\n"
        "    mov r5, r8\n"
        "    strh r4, [r5]\n"
        "    b .L080F1C30\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1BFC: .4byte gUnknown_08124316\n"
        ".L080F1C00: .4byte 0x0000097E\n"
        ".L080F1C04:\n"
        "    cmp r4, #0\n"
        "    bne .L080F1C14\n"
        "    ldr r0, .L080F1C10\n"
        "    adds r1, r6, r0\n"
        "    movs r0, #9\n"
        "    b .L080F1C2E\n"
        ".L080F1C10: .4byte 0x0000097E\n"
        ".L080F1C14:\n"
        "    ldr r0, [r7, #8]\n"
        "    cmp r0, sl\n"
        "    beq .L080F1C28\n"
        "    ldr r2, .L080F1C24\n"
        "    adds r1, r6, r2\n"
        "    movs r0, #0xa\n"
        "    b .L080F1C2E\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1C24: .4byte 0x0000097E\n"
        ".L080F1C28:\n"
        "    ldr r3, .L080F1C40\n"
        "    adds r1, r6, r3\n"
        "    movs r0, #4\n"
        ".L080F1C2E:\n"
        "    strh r0, [r1]\n"
        ".L080F1C30:\n"
        "    ldr r0, .L080F1C44\n"
        "    ldrh r1, [r0]\n"
        ".L080F1C34:\n"
        "    ldr r0, .L080F1C48\n"
        "    cmp r1, r0\n"
        "    bne .L080F1C3C\n"
        "    b .L080F20C6\n"
        ".L080F1C3C:\n"
        "    b .L080F1FA0\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1C40: .4byte 0x0000097E\n"
        ".L080F1C44: .4byte 0x030000AC @ IWRAM+0xAC\n"
        ".L080F1C48: .4byte 0x0000FFFF\n"
        ".L080F1C4C:\n"
        "    ldr r4, .L080F1C68\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080EED88\n"
        "    cmp r0, #0\n"
        "    bne .L080F1C84\n"
        "    ldr r0, .L080F1C6C\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r0, r5]\n"
        "    cmp r0, #1\n"
        "    bne .L080F1C74\n"
        "    ldr r0, .L080F1C70\n"
        "    adds r1, r6, r0\n"
        "    b .L080F20A4\n"
        ".L080F1C68: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F1C6C: .4byte 0x030000AE @ IWRAM+0xAE\n"
        ".L080F1C70: .4byte 0x0000097E\n"
        ".L080F1C74:\n"
        "    ldr r2, .L080F1C80\n"
        "    adds r1, r6, r2\n"
        "    movs r0, #5\n"
        "    strh r0, [r1]\n"
        "    b .L080F20C6\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1C80: .4byte 0x0000097E\n"
        ".L080F1C84:\n"
        "    ldr r1, [r4, #8]\n"
        "    movs r0, #0xb7\n"
        "    lsls r0, r0, #1\n"
        "    cmp r1, r0\n"
        "    bne .L080F1CB4\n"
        "    bl Battle_ReflectAction\n"
        "    ldr r3, .L080F1CAC\n"
        "    adds r1, r6, r3\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r1, r5]\n"
        "    cmp r0, #9\n"
        "    bne .L080F1CA0\n"
        "    b .L080F1FA0\n"
        ".L080F1CA0:\n"
        "    ldr r0, [r4, #0x18]\n"
        "    cmp r0, #0\n"
        "    bne .L080F1CB0\n"
        "    movs r0, #8\n"
        "    b .L080F1F9E\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1CAC: .4byte 0x0000097E\n"
        ".L080F1CB0:\n"
        "    movs r0, #0xa\n"
        "    b .L080F1F9E\n"
        ".L080F1CB4:\n"
        "    ldr r0, .L080F1CB8\n"
        "    b .L080F2094\n"
        ".L080F1CB8: .4byte 0x0000097E\n"
        ".L080F1CBC:\n"
        "    ldr r4, .L080F1CF0\n"
        "    ldr r0, [r4]\n"
        "    bl sub_080EFE60\n"
        "    adds r1, r0, #0\n"
        "    ldr r0, [r4, #4]\n"
        "    bl Combatant_GetAffinity\n"
        "    adds r5, r0, #0\n"
        "    ldr r0, [r4, #4]\n"
        "    cmp r0, #0xf\n"
        "    bgt .L080F1D24\n"
        "    bl BattleFlags_Get\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #3\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080F1CF4\n"
        "    mov r1, r8\n"
        "    cmp r1, #0xa\n"
        "    bne .L080F1CF4\n"
        "    movs r2, #0x12\n"
        "    ldrsh r0, [r7, r2]\n"
        "    b .L080F1D1E\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1CF0: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F1CF4:\n"
        "    ldr r0, .L080F1D54\n"
        "    ldr r0, [r0, #4]\n"
        "    cmp r0, #0xf\n"
        "    bgt .L080F1D24\n"
        "    bl BattleFlags_Get\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #3\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080F1D24\n"
        "    mov r0, r8\n"
        "    ldr r1, [sp]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    bl sub_080EED64\n"
        "    cmp r0, #1\n"
        "    bne .L080F1D24\n"
        "    movs r3, #0x12\n"
        "    ldrsh r0, [r7, r3]\n"
        ".L080F1D1E:\n"
        "    cmp r0, #0xb1\n"
        "    ble .L080F1D24\n"
        "    movs r5, #0xd\n"
        ".L080F1D24:\n"
        "    ldr r4, .L080F1D54\n"
        "    ldr r0, [r4, #0x18]\n"
        "    adds r1, r5, #0\n"
        "    bl Battle_ApplyAffinity\n"
        "    str r0, [r4, #0x18]\n"
        "    mov r2, sb\n"
        "    movs r3, #0x18\n"
        "    ldrsh r1, [r2, r3]\n"
        "    cmp r1, r0\n"
        "    bge .L080F1D3C\n"
        "    str r1, [r4, #0x18]\n"
        ".L080F1D3C:\n"
        "    ldr r1, .L080F1D58\n"
        "    ldr r2, .L080F1D5C\n"
        "    adds r0, r2, #0\n"
        "    strh r0, [r1]\n"
        "    adds r2, r1, #0\n"
        "    cmp r5, #0xf\n"
        "    bhi .L080F1DFE\n"
        "    lsls r0, r5, #2\n"
        "    ldr r1, .L080F1D60\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        ".L080F1D54: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F1D58: .4byte 0x030000AC @ IWRAM+0xAC\n"
        ".L080F1D5C: .4byte 0x0000FFFF\n"
        ".L080F1D60: .4byte gUnknown_080F1D64\n"
        "    .global gUnknown_080F1D64\n"
        "gUnknown_080F1D64:\n"
        ".L080F1D64: @ jump table\n"
        "    .4byte .L080F1DD4\n"
        "    .4byte .L080F1DFE\n"
        "    .4byte .L080F1DFE\n"
        "    .4byte .L080F1DFE\n"
        "    .4byte .L080F1DFE\n"
        "    .4byte .L080F1DFE\n"
        "    .4byte .L080F1DFE\n"
        "    .4byte .L080F1DFE\n"
        "    .4byte .L080F1DFE\n"
        "    .4byte .L080F1DFE\n"
        "    .4byte .L080F1DFE\n"
        "    .4byte .L080F1DFE\n"
        "    .4byte .L080F1DE4\n"
        "    .4byte .L080F1DE4\n"
        "    .4byte .L080F1DA4\n"
        "    .4byte .L080F1DA4\n"
        ".L080F1DA4:\n"
        "    ldr r5, .L080F1DDC\n"
        "    ldr r0, [r5, #4]\n"
        "    bl Battle_GetHp\n"
        "    adds r4, r0, #0\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    ldr r0, [r5, #4]\n"
        "    bl Battle_GetMaxHp\n"
        "    lsls r4, r4, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    ldr r1, [r5, #0x18]\n"
        "    adds r1, r4, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r1, r0\n"
        "    ble .L080F1DCC\n"
        "    subs r0, r0, r4\n"
        "    str r0, [r5, #0x18]\n"
        ".L080F1DCC:\n"
        "    ldr r0, [r5, #4]\n"
        "    ldr r1, [r5, #0x18]\n"
        "    bl Combatant_ChangeHp\n"
        ".L080F1DD4:\n"
        "    ldr r3, .L080F1DE0\n"
        "    adds r1, r6, r3\n"
        "    b .L080F2096\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1DDC: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F1DE0: .4byte 0x0000097E\n"
        ".L080F1DE4:\n"
        "    bl Battle_ReflectAction\n"
        "    ldr r5, .L080F1E10\n"
        "    adds r0, r6, r5\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    cmp r0, #9\n"
        "    bne .L080F1DF6\n"
        "    b .L080F1FA0\n"
        ".L080F1DF6:\n"
        "    ldr r1, .L080F1E14\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        "    adds r2, r1, #0\n"
        ".L080F1DFE:\n"
        "    ldr r0, .L080F1E18\n"
        "    ldr r0, [r0, #0x18]\n"
        "    cmp r0, #0\n"
        "    bne .L080F1E1C\n"
        "    ldr r3, .L080F1E10\n"
        "    adds r1, r6, r3\n"
        "    movs r0, #8\n"
        "    b .L080F1E22\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1E10: .4byte 0x0000097E\n"
        ".L080F1E14: .4byte 0x030000AC @ IWRAM+0xAC\n"
        ".L080F1E18: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F1E1C:\n"
        "    ldr r5, .L080F1E28\n"
        "    adds r1, r6, r5\n"
        "    movs r0, #0xa\n"
        ".L080F1E22:\n"
        "    strh r0, [r1]\n"
        "    ldrh r1, [r2]\n"
        "    b .L080F1C34\n"
        ".L080F1E28: .4byte 0x0000097E\n"
        ".L080F1E2C:\n"
        "    bl BattleMsg_IsDone\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    beq .L080F1E3A\n"
        "    b .L080F20C6\n"
        ".L080F1E3A:\n"
        "    ldr r0, .L080F1E44\n"
        "    adds r1, r6, r0\n"
        ".L080F1E3E:\n"
        "    movs r0, #0xc\n"
        "    strh r0, [r1]\n"
        "    b .L080F20C6\n"
        ".L080F1E44: .4byte 0x0000097E\n"
        ".L080F1E48:\n"
        "    ldr r1, .L080F1E5C\n"
        "    adds r4, r6, r1\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #0\n"
        "    beq .L080F1E84\n"
        "    cmp r0, #1\n"
        "    bne .L080F1E64\n"
        "    ldr r1, .L080F1E60\n"
        "    b .L080F1E66\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1E5C: .4byte 0x000011B0\n"
        ".L080F1E60: .4byte gUnknown_081242EC\n"
        ".L080F1E64:\n"
        "    ldr r1, .L080F1E7C\n"
        ".L080F1E66:\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    movs r0, #0\n"
        "    strh r0, [r4]\n"
        "    ldr r2, .L080F1E80\n"
        "    adds r1, r6, r2\n"
        ".L080F1E74:\n"
        "    movs r0, #0xb\n"
        "    strh r0, [r1]\n"
        "    b .L080F20C6\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1E7C: .4byte gUnknown_081242FC\n"
        ".L080F1E80: .4byte 0x0000097E\n"
        ".L080F1E84:\n"
        "    ldr r5, .L080F1EA8\n"
        "    ldr r0, [r5, #4]\n"
        "    bl Battle_GetHp\n"
        "    cmp r0, #0\n"
        "    ble .L080F1EA0\n"
        "    ldr r0, [r5, #4]\n"
        "    bl Combatant_GetStatus\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080F1EB0\n"
        ".L080F1EA0:\n"
        "    ldr r3, .L080F1EAC\n"
        "    adds r1, r6, r3\n"
        "    b .L080F20A4\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1EA8: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F1EAC: .4byte 0x0000097C\n"
        ".L080F1EB0:\n"
        "    bl Battle_ApplyDamage\n"
        "    bl sub_080EDA90\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #0\n"
        "    beq .L080F1F98\n"
        "    ldr r0, .L080F1EF0\n"
        "    cmp r4, r0\n"
        "    beq .L080F1F98\n"
        "    bl sub_080EDAD0\n"
        "    cmp r0, #0\n"
        "    beq .L080F1F14\n"
        "    ldr r0, .L080F1EF4\n"
        "    ands r0, r4\n"
        "    cmp r0, #0\n"
        "    beq .L080F1F14\n"
        "    ldr r1, [r5, #4]\n"
        "    cmp r1, #0xf\n"
        "    ble .L080F1F14\n"
        "    ldr r0, .L080F1EF8\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r0, r5]\n"
        "    cmp r0, #1\n"
        "    bne .L080F1F00\n"
        "    ldr r0, .L080F1EFC\n"
        "    adds r1, r6, r0\n"
        "    movs r0, #9\n"
        "    b .L080F1F9E\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1EF0: .4byte 0x0000FFFF\n"
        ".L080F1EF4: .4byte 0x00003204\n"
        ".L080F1EF8: .4byte 0x030000AE @ IWRAM+0xAE\n"
        ".L080F1EFC: .4byte 0x0000097E\n"
        ".L080F1F00:\n"
        "    adds r0, r1, #0\n"
        "    bl Battle_GetHp\n"
        "    cmp r0, #0\n"
        "    bgt .L080F1F98\n"
        "    ldr r2, .L080F1F10\n"
        "    adds r1, r6, r2\n"
        "    b .L080F1F9C\n"
        ".L080F1F10: .4byte 0x0000097E\n"
        ".L080F1F14:\n"
        "    ldr r5, .L080F1F34\n"
        "    ldr r0, [r5, #4]\n"
        "    adds r1, r4, #0\n"
        "    bl sub_080C08E8\n"
        "    ldr r0, [r5, #4]\n"
        "    bl Battle_GetHp\n"
        "    cmp r0, #0\n"
        "    bgt .L080F1F3C\n"
        "    ldr r5, .L080F1F38\n"
        "    adds r1, r6, r5\n"
        "    movs r0, #7\n"
        "    strh r0, [r1]\n"
        "    b .L080F1F76\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1F34: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F1F38: .4byte 0x0000097E\n"
        ".L080F1F3C:\n"
        "    ldr r0, .L080F1F68\n"
        "    adds r1, r6, r0\n"
        "    movs r0, #6\n"
        "    strh r0, [r1]\n"
        "    ldr r0, [r5, #4]\n"
        "    cmp r0, #0xf\n"
        "    bgt .L080F1F6C\n"
        "    bl Party_FindPosition\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r5, r0, #0x10\n"
        "    adds r0, r5, #0\n"
        "    bl Hud_GetMemberFace\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #0x12\n"
        "    bgt .L080F1F76\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080C8490\n"
        "    b .L080F1F76\n"
        ".L080F1F68: .4byte 0x0000097E\n"
        ".L080F1F6C:\n"
        "    movs r2, #0xec\n"
        "    lsls r2, r2, #4\n"
        "    adds r1, r6, r2\n"
        "    movs r0, #1\n"
        "    strb r0, [r1]\n"
        ".L080F1F76:\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #6\n"
        "    cmp r4, r0\n"
        "    bne .L080F1FA0\n"
        "    ldr r0, .L080F1F94\n"
        "    ldr r1, [r0, #4]\n"
        "    subs r0, r1, #4\n"
        "    cmp r0, #0xb\n"
        "    bhi .L080F1FA0\n"
        "    adds r0, r1, #0\n"
        "    bl sub_080F4190\n"
        "    bl Party_FixFormation\n"
        "    b .L080F1FA0\n"
        ".L080F1F94: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F1F98:\n"
        "    ldr r3, .L080F1FAC\n"
        "    adds r1, r6, r3\n"
        ".L080F1F9C:\n"
        "    movs r0, #7\n"
        ".L080F1F9E:\n"
        "    strh r0, [r1]\n"
        ".L080F1FA0:\n"
        "    movs r0, #4\n"
        "    movs r1, #0xd\n"
        "    bl sub_080F0344\n"
        "    b .L080F20C6\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1FAC: .4byte 0x0000097E\n"
        ".L080F1FB0:\n"
        "    ldr r4, .L080F1FC8\n"
        "    ldr r0, [r4, #4]\n"
        "    bl Battle_IsEnemyId\n"
        "    cmp r0, #1\n"
        "    bne .L080F1FD0\n"
        "    ldr r1, .L080F1FCC\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    b .L080F1FEC\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1FC8: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F1FCC: .4byte gUnknown_08124218\n"
        ".L080F1FD0:\n"
        "    ldr r0, [r4, #4]\n"
        "    ldr r5, .L080F1FF4\n"
        "    adds r0, r0, r5\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    ldr r1, .L080F1FF8\n"
        "    bl Battle_BuildActorStatusText\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        ".L080F1FEC:\n"
        "    ldr r0, .L080F1FFC\n"
        "    adds r1, r6, r0\n"
        "    b .L080F2040\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1FF4: .4byte 0xFFFF8000\n"
        ".L080F1FF8: .4byte gUnknown_08124234\n"
        ".L080F1FFC: .4byte 0x0000097E\n"
        ".L080F2000:\n"
        "    ldr r4, .L080F202C\n"
        "    ldr r0, [r4, #4]\n"
        "    bl Battle_IsEnemyId\n"
        "    movs r1, #0xaa\n"
        "    lsls r1, r1, #1\n"
        "    cmp r0, #1\n"
        "    bne .L080F2012\n"
        "    subs r1, #1\n"
        ".L080F2012:\n"
        "    adds r0, r1, #0\n"
        "    bl Battle_GetMessage\n"
        "    ldr r1, [r4, #4]\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    ldr r2, .L080F2030\n"
        "    adds r1, r6, r2\n"
        "    b .L080F2040\n"
        ".L080F202C: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F2030: .4byte 0x0000097E\n"
        ".L080F2034:\n"
        "    lsls r0, r4, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    bl sub_080F2AC8\n"
        ".L080F203C:\n"
        "    ldr r3, .L080F2048\n"
        "    adds r1, r6, r3\n"
        ".L080F2040:\n"
        "    movs r0, #7\n"
        "    strh r0, [r1]\n"
        "    b .L080F20C6\n"
        "    .byte 0x00, 0x00\n"
        ".L080F2048: .4byte 0x0000097E\n"
        ".L080F204C:\n"
        "    bl BattleMsg_IsDone\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bne .L080F20C6\n"
        "    ldr r4, .L080F2070\n"
        "    ldr r0, [r4, #4]\n"
        "    bl Combatant_GetStatus\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #7\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080F2078\n"
        "    ldr r5, .L080F2074\n"
        "    adds r1, r6, r5\n"
        "    b .L080F20A4\n"
        ".L080F2070: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F2074: .4byte 0x0000097C\n"
        ".L080F2078:\n"
        "    ldr r0, [r4, #4]\n"
        "    bl Battle_GetHp\n"
        "    cmp r0, #0\n"
        "    ble .L080F2092\n"
        "    ldr r0, [r4, #4]\n"
        "    bl Combatant_GetStatus\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080F20A0\n"
        ".L080F2092:\n"
        "    ldr r0, .L080F209C\n"
        ".L080F2094:\n"
        "    adds r1, r6, r0\n"
        ".L080F2096:\n"
        "    movs r0, #9\n"
        "    strh r0, [r1]\n"
        "    b .L080F20C6\n"
        ".L080F209C: .4byte 0x0000097C\n"
        ".L080F20A0:\n"
        "    ldr r2, .L080F20AC\n"
        "    adds r1, r6, r2\n"
        ".L080F20A4:\n"
        "    movs r0, #0xa\n"
        "    strh r0, [r1]\n"
        "    b .L080F20C6\n"
        "    .byte 0x00, 0x00\n"
        ".L080F20AC: .4byte 0x0000097C\n"
        ".L080F20B0:\n"
        "    bl BattleMsg_IsDone\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bne .L080F20C6\n"
        "    ldr r0, .L080F20D8\n"
        "    ldrh r1, [r0]\n"
        "    ldr r3, .L080F20DC\n"
        "    adds r0, r6, r3\n"
        "    strh r1, [r0]\n"
        ".L080F20C6:\n"
        "    add sp, #8\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080F20D8: .4byte 0x030000AC @ IWRAM+0xAC\n"
        ".L080F20DC: .4byte 0x0000097E\n"
    );
}
#endif

// Battle_ReflectAction @ 0x080F20E0
/* A reflected action: "<name> repels it" (enemies: gUnknown_08124200), then the action is
   redone on its own user, ailments included, with the user's affinity (absorb heals). */
void Battle_ReflectAction(void)
{
    struct F17C0Battle *b;
    u16 ail;
    s16 kind;

    if (!Battle_IsEnemyId(gUnk_03000088.def))
        BattleMenu_SetModeAutoClose(3, Battle_BuildNamePrependText(gUnk_03000088.def + 0x8000, gUnknown_081241F0));
    else
        BattleMenu_SetModeAutoClose(3, gUnknown_08124200);
    gUnk_03000088.def = gUnk_03000088.att;
    ail = sub_080EDA90();
    if (ail != 0 && ail != 0xFFFF)
    {
        sub_080EDA7C(0xFFFF);
        if (sub_080F3214(gUnk_03000088.def, ail)
            && (!(ail & 2) || Party_GetMember(gUnk_03000088.def)->maxMp != 0))
            sub_080EDA7C(ail);
    }
    b = BB;
    kind = sub_080C35E4(gUnk_03000088.att);
    if ((u16)(kind - 4) <= 1 || kind == 10)
        gUnk_03000088.dmg = Battle_PhysicalDamage(gUnk_03000088.att, gUnk_03000088.def);
    else if (kind == 8)
    {
        s32 skill = Combatant_GetChosenSkill(gUnk_03000088.att);
        s32 attr = skill;

        Item_GetAttribute(skill, 0xC, &attr);
        Combatant_SetChosenSkill(gUnk_03000088.att, attr);
        Battle_SkillDamage(&gUnk_03000088);
        Combatant_SetChosenSkill(gUnk_03000088.att, skill);
    }
    else if (kind == 7 || kind == 11)
        Battle_SkillDamage(&gUnk_03000088);
    if (gUnk_03000088.dmg != 0)
    {
        u32 el = sub_080EFE60(gUnk_03000088.att);
        s32 aff = Combatant_GetAffinity(gUnk_03000088.def, el);

        gUnk_03000088.dmg = Battle_ApplyAffinity(gUnk_03000088.dmg, aff);
        if (Battle_GetHp(gUnk_03000088.def) < gUnk_03000088.dmg)
            gUnk_03000088.dmg = Battle_GetHp(gUnk_03000088.def);
        switch (aff)
        {
        case 14:
        case 15:
        {
            s16 hp = Battle_GetHp(gUnk_03000088.def);
            s16 max = Battle_GetMaxHp(gUnk_03000088.def);

            if (hp + gUnk_03000088.dmg > max)
                gUnk_03000088.dmg = max - hp;
            Combatant_ChangeHp(gUnk_03000088.def, gUnk_03000088.dmg);
        }
        /* fallthrough */
        case 0:
            b->step = 9;
            break;
        case 12:
        case 13:
            break;
        }
    }
}

// Battle_ApplyDamage @ 0x080F22B4
/* Applies the damage of the current action: instant death (ailment 0x8000) takes all HP
   (special battles: only demons of kind 0x3F hit by element 7 or 0x3E by element 8), then
   plays the hit sound (0x12C enemy, 0x12B party, flashing the member's slot), subtracts the
   HP (clamped at 0, never raising HP above max unless it already was) and shows the damage
   text. */
#ifdef NONMATCHING
void Battle_ApplyDamage(void)
{
    struct F17C0Battle *b = BB;
    u16 def = gUnk_03000088.def;
    u32 dmg;
    s32 over;

    if (gUnk_030000AE == 1)
    {
        u16 ail = sub_080EDA90();

        if (ail == 0x8000)
        {
            if (sub_080EDAD0() && (s16)def > 15)
            {
                u32 el = sub_080EFE60(gUnk_03000088.att);
                s32 r = sub_080ED494(Combatant_GetDemonId(gUnk_03000088.def));

                if (r == 0x3F && el == 7)
                    gUnk_03000088.dmg = Battle_GetHp((s16)def);
                else if (r == 0x3E && el == 8)
                    gUnk_03000088.dmg = Battle_GetHp((s16)def);
                else
                    return;
                sub_080C08E8(gUnk_03000088.def, 0x8000);
                sub_080EDA7C(0);
            }
            else
                gUnk_03000088.dmg = Battle_GetHp((s16)def);
        }
        else
        {
            gUnk_03000088.dmg = 0;
            return;
        }
    }
    if (Battle_IsEnemyId((s16)def) == 1)
    {
        u16 two = Battle_IsTwoSided();
        u16 side = sub_080ED974((s16)def);

        if (two == 1 && side == 1)
            sub_080E8AFC(1);
        else
            sub_080E8AFC(0);
        b->sound = 0x12C;
    }
    else
    {
        u8 i;

        Party_FindPosition((s16)def);
        i = 0;
        if (gGameState.order[0] != (s16)def)
        {
            do
            {
                i++;
                if (i > 5)
                    break;
            } while (gGameState.order[i] != (s16)def);
        }
        if (i != 6)
            sub_080C86F4(i);
        b->sound = 0x12B;
    }
    sub_080ECF70(b->sound);
    dmg = gUnk_03000088.dmg;
    over = 0;
    if (Battle_GetHp((s16)def) > Battle_GetMaxHp((s16)def))
        over = 1;
    Combatant_AddHp((s16)def, -gUnk_03000088.dmg);
    if (Battle_GetHp((s16)def) < 0)
    {
        gUnk_03000088.dmg += Battle_GetHp((s16)def);
        Battle_SetHp((s16)def, 0);
    }
    if (!over && Battle_GetHp((s16)def) > Battle_GetMaxHp((s16)def))
        Battle_SetHp((s16)def, Battle_GetMaxHp((s16)def));
    if (Battle_IsEnemyId(gUnk_03000088.def) == 1)
        BattleMenu_SetModeAutoClose(3, Battle_BuildDamageDealtText(Battle_GetCombatant(gUnk_03000088.def + 0x8000), dmg, gUnknown_08123BCC));
    else
        BattleMenu_SetModeAutoClose(3, Battle_BuildDamageDealtText(Battle_GetCombatant(gUnk_03000088.def + 0x8000), dmg, gUnknown_0812310C));
}
#else
NAKED void Battle_ApplyDamage(void)
{
    asm_unified(
        ".L080F22B4:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    ldr r0, .L080F231C\n"
        "    mov sl, r0\n"
        "    ldr r4, .L080F2320\n"
        "    ldrh r7, [r4, #4]\n"
        "    ldr r0, .L080F2324\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    cmp r0, #1\n"
        "    bne .L080F2372\n"
        "    bl sub_080EDA90\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #8\n"
        "    cmp r8, r0\n"
        "    bne .L080F236C\n"
        "    bl sub_080EDAD0\n"
        "    cmp r0, #0\n"
        "    beq .L080F2358\n"
        "    lsls r0, r7, #0x10\n"
        "    asrs r6, r0, #0x10\n"
        "    cmp r6, #0xf\n"
        "    ble .L080F2358\n"
        "    ldr r0, [r4]\n"
        "    bl sub_080EFE60\n"
        "    adds r5, r0, #0\n"
        "    ldr r0, [r4, #4]\n"
        "    bl Combatant_GetDemonId\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    bl sub_080ED494\n"
        "    cmp r0, #0x3f\n"
        "    bne .L080F2328\n"
        "    cmp r5, #7\n"
        "    bne .L080F2328\n"
        "    adds r0, r6, #0\n"
        "    bl Battle_GetHp\n"
        "    str r0, [r4, #0x18]\n"
        "    ldr r0, [r4, #4]\n"
        "    b .L080F2342\n"
        ".L080F231C: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080F2320: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F2324: .4byte 0x030000AE @ IWRAM+0xAE\n"
        ".L080F2328:\n"
        "    cmp r0, #0x3e\n"
        "    beq .L080F232E\n"
        "    b .L080F24DA\n"
        ".L080F232E:\n"
        "    cmp r5, #8\n"
        "    beq .L080F2334\n"
        "    b .L080F24DA\n"
        ".L080F2334:\n"
        "    lsls r0, r7, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    bl Battle_GetHp\n"
        "    ldr r1, .L080F2354\n"
        "    str r0, [r1, #0x18]\n"
        "    ldr r0, [r1, #4]\n"
        ".L080F2342:\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    bl sub_080C08E8\n"
        "    movs r0, #0\n"
        "    bl sub_080EDA7C\n"
        "    b .L080F2372\n"
        "    .byte 0x00, 0x00\n"
        ".L080F2354: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F2358:\n"
        "    lsls r0, r7, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    bl Battle_GetHp\n"
        "    ldr r1, .L080F2368\n"
        "    str r0, [r1, #0x18]\n"
        "    b .L080F2372\n"
        "    .byte 0x00, 0x00\n"
        ".L080F2368: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F236C:\n"
        "    movs r0, #0\n"
        "    str r0, [r4, #0x18]\n"
        "    b .L080F24DA\n"
        ".L080F2372:\n"
        "    lsls r4, r7, #0x10\n"
        "    asrs r5, r4, #0x10\n"
        "    adds r0, r5, #0\n"
        "    bl Battle_IsEnemyId\n"
        "    mov sb, r4\n"
        "    cmp r0, #1\n"
        "    bne .L080F23BC\n"
        "    bl Battle_IsTwoSided\n"
        "    adds r4, r0, #0\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080ED974\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r4, #1\n"
        "    bne .L080F23A6\n"
        "    cmp r0, #1\n"
        "    bne .L080F23A6\n"
        "    movs r0, #1\n"
        "    bl sub_080E8AFC\n"
        "    b .L080F23AC\n"
        ".L080F23A6:\n"
        "    movs r0, #0\n"
        "    bl sub_080E8AFC\n"
        ".L080F23AC:\n"
        "    ldr r1, .L080F23B8\n"
        "    add r1, sl\n"
        "    movs r0, #0x96\n"
        "    lsls r0, r0, #1\n"
        "    b .L080F23FC\n"
        "    .byte 0x00, 0x00\n"
        ".L080F23B8: .4byte 0x00000ECA\n"
        ".L080F23BC:\n"
        "    adds r0, r5, #0\n"
        "    bl Party_FindPosition\n"
        "    movs r1, #0\n"
        "    ldr r0, .L080F24A4\n"
        "    movs r3, #0xa2\n"
        "    lsls r3, r3, #4\n"
        "    adds r2, r0, r3\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r2, r0]\n"
        "    cmp r0, r5\n"
        "    beq .L080F23EC\n"
        "    adds r4, r5, #0\n"
        ".L080F23D6:\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r1, r0, #0x18\n"
        "    cmp r1, #5\n"
        "    bhi .L080F23EC\n"
        "    adds r0, r1, r2\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    cmp r0, r4\n"
        "    bne .L080F23D6\n"
        ".L080F23EC:\n"
        "    cmp r1, #6\n"
        "    beq .L080F23F6\n"
        "    adds r0, r1, #0\n"
        "    bl sub_080C86F4\n"
        ".L080F23F6:\n"
        "    ldr r1, .L080F24A8\n"
        "    add r1, sl\n"
        "    ldr r0, .L080F24AC\n"
        ".L080F23FC:\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L080F24A8\n"
        "    add r0, sl\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    bl sub_080ECF70\n"
        "    ldr r6, .L080F24B0\n"
        "    ldr r3, [r6, #0x18]\n"
        "    mov r8, r3\n"
        "    movs r7, #0\n"
        "    mov r0, sb\n"
        "    asrs r5, r0, #0x10\n"
        "    adds r0, r5, #0\n"
        "    bl Battle_GetHp\n"
        "    adds r4, r0, #0\n"
        "    adds r0, r5, #0\n"
        "    bl Battle_GetMaxHp\n"
        "    cmp r4, r0\n"
        "    ble .L080F242A\n"
        "    movs r7, #1\n"
        ".L080F242A:\n"
        "    ldr r1, [r6, #0x18]\n"
        "    rsbs r1, r1, #0\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_AddHp\n"
        "    adds r0, r5, #0\n"
        "    bl Battle_GetHp\n"
        "    cmp r0, #0\n"
        "    bge .L080F2452\n"
        "    adds r0, r5, #0\n"
        "    bl Battle_GetHp\n"
        "    ldr r1, [r6, #0x18]\n"
        "    adds r1, r1, r0\n"
        "    str r1, [r6, #0x18]\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #0\n"
        "    bl Battle_SetHp\n"
        ".L080F2452:\n"
        "    cmp r7, #0\n"
        "    bne .L080F2476\n"
        "    adds r0, r5, #0\n"
        "    bl Battle_GetHp\n"
        "    adds r4, r0, #0\n"
        "    adds r0, r5, #0\n"
        "    bl Battle_GetMaxHp\n"
        "    cmp r4, r0\n"
        "    ble .L080F2476\n"
        "    adds r0, r5, #0\n"
        "    bl Battle_GetMaxHp\n"
        "    adds r1, r0, #0\n"
        "    adds r0, r5, #0\n"
        "    bl Battle_SetHp\n"
        ".L080F2476:\n"
        "    ldr r4, .L080F24B0\n"
        "    ldr r0, [r4, #4]\n"
        "    bl Battle_IsEnemyId\n"
        "    cmp r0, #1\n"
        "    bne .L080F24BC\n"
        "    ldr r0, [r4, #4]\n"
        "    ldr r1, .L080F24B4\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    ldr r2, .L080F24B8\n"
        "    mov r1, r8\n"
        "    bl Battle_BuildDamageDealtText\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    b .L080F24DA\n"
        "    .byte 0x00, 0x00\n"
        ".L080F24A4: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080F24A8: .4byte 0x00000ECA\n"
        ".L080F24AC: .4byte 0x0000012B\n"
        ".L080F24B0: .4byte 0x03000088 @ IWRAM+0x88\n"
        ".L080F24B4: .4byte 0xFFFF8000\n"
        ".L080F24B8: .4byte gUnknown_08123BCC\n"
        ".L080F24BC:\n"
        "    ldr r0, [r4, #4]\n"
        "    ldr r3, .L080F24E8\n"
        "    adds r0, r0, r3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Battle_GetCombatant\n"
        "    ldr r2, .L080F24EC\n"
        "    mov r1, r8\n"
        "    bl Battle_BuildDamageDealtText\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        ".L080F24DA:\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080F24E8: .4byte 0xFFFF8000\n"
        ".L080F24EC: .4byte gUnknown_0812310C\n"
    );
}
#endif
