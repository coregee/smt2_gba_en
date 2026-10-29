/* Battle: announcing an action (message, animation and sound ids) and summoning a stock demon
   into the party during battle. */

#include "global.h"

/* The battle EWRAM block at 0x0203C200: only the fields used here. */
struct F108CBattle
{
    u8 pad000[0x97C];
    u16 phase;          /* 0x97C */
    u8 pad97E[0xEC6 - 0x97E];
    s16 anim;           /* 0xEC6: effect animation of the action, 0xFF = none */
    u16 unkEC8;         /* 0xEC8 */
    u16 sound;          /* 0xECA: sound of the action */
    u8 padECC[0xEF0 - 0xECC];
    u16 summonId[16];   /* 0xEF0: demon to summon, by party slot */
    u16 summonPos[16];  /* 0xF10: formation position for it */
    u16 unkF30[16];     /* 0xF30 */
    u8 padF50[0x1192 - 0xF50];
    u16 unk1192;        /* 0x1192 */
    u16 unk1194;        /* 0x1194 */
};
extern u8 gUnk_0203C200[];
#define BB ((struct F108CBattle *)gUnk_0203C200)

/* gGameState (0x030046C0): only the field used here. */
struct F108CGameState
{
    u8 pad000[0xA20];
    s8 order[0x20];     /* 0xA20: combatant in each formation position */
};
extern struct F108CGameState gGameState;

extern s16 gUnk_030000A8;   /* which side the animation plays on: 0, 1 or 2 */
extern s16 gUnk_030000AA;   /* animation kind from Battle_GetAnimKind */

/* One combatant (0x80 bytes): only the fields used here. */
struct F108CCombatant
{
    u8 pad00[0xC];
    u8 slot;            /* 0x0C */
    u8 pad0D[0x17 - 0xD];
    s8 command;         /* 0x17 */
};

struct F108CAnimEntry
{
    u8 anim;
    u8 pad;
    u16 sound;
};
extern const struct F108CAnimEntry gUnknown_0876E458[];  /* by weapon */
extern const struct F108CAnimEntry gUnknown_0876E618[];  /* by item - 0xD0 */
extern const s16 gUnknown_0876E878[];                    /* message by skill - 0x40 */

struct F108CTableEntry
{
    u8 id[2];
    u16 alt;
};
extern const struct F108CTableEntry gUnknown_0876E1D8[];

u16 *Battle_BuildCombatActionList(struct F108CCombatant *actor, u8 action);
u16 *Battle_BuildActorActionText(struct F108CCombatant *actor);
u16 *sub_080EAE30(struct F108CCombatant *actor);
void BattleMenu_SetModeAutoClose(u8 mode, u16 *src);
u32 Combatant_GetEquip(s32 who, s32 slot);
u16 sub_080ED32C(u16 i);
s32 sub_080EF5FC(struct F108CCombatant *c, s32 who);
u8 *Action_GetRecord(u16 id);
s32 Battle_IsEnemyId(s32 who);
u8 Battle_GetActionAnim(u16 a, u16 b);
u16 sub_080F104C(u16 a, u16 b);
s16 Battle_GetAnimKind(s16 a, s16 b);
u16 Battle_SummonQueuedDemon(s16 i, s16 mode);
const u8 *sub_080BF5C0(u16 id);
s32 sub_080F5938(void);
u16 *Battle_GetMessage(u16 id);
u16 *Menu_ExpandListTemplate(u16 *tmpl, u32 arg);
struct F108CCombatant *Party_GetMember(u16 id);
void Party_Remove(u16 who, u16 release);
u32 Battle_IsTwoSided(void);
u32 sub_080EDA24(s32 side);
u32 sub_080F1788(s16 i);
u32 sub_080C2B6C(void);
s32 Combatant_GetChosenSkill(s32 who);
u16 Combatant_GetStatus(s32 who);
void Item_GetAttribute(s32 id, s32 field, s32 *out);
s32 sub_080F30CC(s32 slot);
u32 Party_AddAt(u16 who, u16 slot);
u32 sub_0812839C(u16 id);
void sub_080F3E20(s32 a);
u32 Combatant_SetStatus(s32 who, u16 bits);
void Battle_SetHp(s32 who, s32 v);
void sub_080C8490(s32 slot);
void Party_FixFormation(void);
void Party_BuildMemberNameTiles(void);
s32 Party_FindPosition(s32 id);

// Battle_AnnounceAction @ 0x080F108C
/* Shows the message announcing combatant c's action and sets the animation (+0xEC6), its
   sound (+0xECA) and the side it plays on (gUnk_030000A8). Commands 4/5 attack with the
   weapon in equip slot 0/1, 8 uses an item, 7/11 cast a skill, 6 summons, 9 and 12 have
   their own action-list texts (12 also removes the member). */
#ifdef NONMATCHING
void Battle_AnnounceAction(struct F108CCombatant *c, s16 who, u16 side)
{
    struct F108CBattle *b = BB;
    s32 attr;
    u16 skill = Combatant_GetChosenSkill(who);
    u16 status = Combatant_GetStatus(who);
    s32 noAnim = 0;

    b->sound = 0xFF;
    b->anim = 0xFF;
    b->unkEC8 = 0xFF;
    gUnk_030000AA = 0xFF;
    gUnk_030000A8 = -1;
    b->phase = 1;
    switch (c->command)
    {
    case 4:
        BattleMenu_SetModeAutoClose(3, Battle_BuildCombatActionList(c, 0));
        b->anim = gUnknown_0876E458[Combatant_GetEquip(who, 0)].anim;
        b->sound = sub_080ED32C(b->anim);
        if (sub_080EF5FC(c, who) == 0x8000)
            noAnim = 1;
        break;
    case 5:
        BattleMenu_SetModeAutoClose(3, Battle_BuildCombatActionList(c, 1));
        b->anim = gUnknown_0876E458[Combatant_GetEquip(who, 1)].anim;
        b->sound = sub_080ED32C(b->anim);
        if (sub_080EF5FC(c, who) == 0x8000)
            noAnim = 1;
        break;
    case 10:
        b->sound = sub_080ED32C(0);
        BattleMenu_SetModeAutoClose(3, Battle_BuildCombatActionList(c, 2));
        break;
    case 8:
        Item_GetAttribute((s16)skill, 0xC, &attr);
        if (who <= 15 && Action_GetRecord(skill)[3] == 0xFF)
            noAnim = 1;
        if ((s16)skill == 0xF0)
        {
            b->unk1192 = attr;
            b->unkF30[who] = c->slot;
        }
        else if ((s16)skill == 0xF8)
            b->unk1194 = attr;
        if ((s16)skill <= 0xBC || (u32)(attr - 0x20) <= 0x17)
            side = Battle_IsEnemyId(who);
        if ((s16)skill == 0xF8 || (s16)skill == 0xF0)
        {
            b->anim = Battle_GetActionAnim(attr, side);
            b->sound = sub_080F104C(attr, side);
            Battle_GetAnimKind(attr, side);
        }
        else
        {
            const struct F108CAnimEntry *e = &gUnknown_0876E618[(s16)skill - 0xD0];

            b->anim = e->anim;
            if (b->anim > 0xC8)
                b->sound = e->sound;
            else
                b->sound = sub_080ED32C(b->anim);
        }
        BattleMenu_SetModeAutoClose(3, Battle_BuildActorActionText(c));
        break;
    case 7:
    case 11:
        if (who <= 15)
        {
            u8 t = sub_080BF5C0(skill)[2];

            if (t == 0xF || t == 0xFF)
                noAnim = 1;
        }
        if ((s16)skill <= 0x3F)
        {
            u16 k = (s16)skill - 0x20;

            if (k <= 0x17)
                side = Battle_IsEnemyId(who);
            if (k <= 2)
                gUnk_030000A8 = 0;
            BattleMenu_SetModeAutoClose(3, sub_080EAE30(c));
            if (status & 2)
                b->anim = 0xFF;
            else
            {
                b->anim = Battle_GetActionAnim(skill, side);
                Battle_GetAnimKind(skill, side);
            }
        }
        else
        {
            s16 msg = gUnknown_0876E878[(s16)skill - 0x40];

            if ((s16)skill == 0x66)
            {
                s32 n = sub_080F5938();

                if (n == -1)
                    n = 0;
                BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(Battle_GetMessage(msg), n));
            }
            else
            {
                u16 *t = Battle_GetMessage(msg);

                BattleMenu_SetModeAutoClose(3, Menu_ExpandListTemplate(t, who + (Combatant_GetChosenSkill(who) << 16)));
            }
            b->anim = Battle_GetActionAnim(skill, side);
            Battle_GetAnimKind(skill, side);
        }
        b->sound = sub_080F104C(skill, side);
        break;
    case 6:
        BattleMenu_SetModeAutoClose(3, Battle_BuildCombatActionList(Party_GetMember(Battle_SummonQueuedDemon(who, 0)), 3));
        b->phase = 11;
        break;
    case 9:
        BattleMenu_SetModeAutoClose(3, Battle_BuildCombatActionList(c, 4));
        b->phase = 11;
        break;
    case 12:
        Party_Remove(who, 0);
        BattleMenu_SetModeAutoClose(3, Battle_BuildCombatActionList(c, 5));
        b->phase = 11;
        break;
    }
    if (b->anim == 0x88 && c->command == 8)
        noAnim = 1;
    if (!Battle_IsTwoSided() || noAnim == 1)
        gUnk_030000A8 = 0;
    else if (who <= 15)
    {
        if (sub_080EDA24(0) && sub_080EDA24(1) && gUnk_030000A8 == 0)
            gUnk_030000A8 = 0;
        else if ((u16)sub_080F1788(who) == 0)
            gUnk_030000A8 = 1;
        else
            gUnk_030000A8 = 2;
    }
    else if (who <= 0x13)
        gUnk_030000A8 = 1;
    else
        gUnk_030000A8 = 2;
    if ((u16)sub_080C2B6C() == 1)
        b->anim = 0xFF;
}
#else
NAKED void Battle_AnnounceAction(struct F108CCombatant *c, s16 who, u16 side)
{
    asm_unified(
        ".L080F108C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x14\n"
        "    mov sl, r0\n"
        "    adds r4, r1, #0\n"
        "    lsls r4, r4, #0x10\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    str r2, [sp, #8]\n"
        "    ldr r0, .L080F110C\n"
        "    mov sb, r0\n"
        "    lsrs r1, r4, #0x10\n"
        "    str r1, [sp, #4]\n"
        "    asrs r4, r4, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_GetChosenSkill\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_GetStatus\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0xc]\n"
        "    movs r2, #0\n"
        "    str r2, [sp, #0x10]\n"
        "    ldr r0, .L080F1110\n"
        "    add r0, sb\n"
        "    movs r1, #0xff\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L080F1114\n"
        "    add r0, sb\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L080F1118\n"
        "    add r0, sb\n"
        "    strh r1, [r0]\n"
        "    ldr r0, .L080F111C\n"
        "    strh r1, [r0]\n"
        "    ldr r1, .L080F1120\n"
        "    subs r2, #1\n"
        "    adds r0, r2, #0\n"
        "    strh r0, [r1]\n"
        "    ldr r1, .L080F1124\n"
        "    add r1, sb\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        "    mov r1, sl\n"
        "    ldrb r0, [r1, #0x17]\n"
        "    subs r0, #4\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    cmp r0, #8\n"
        "    bls .L080F1100\n"
        "    b .L080F14BE\n"
        ".L080F1100:\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L080F1128\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080F110C: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080F1110: .4byte 0x00000ECA\n"
        ".L080F1114: .4byte 0x00000EC6\n"
        ".L080F1118: .4byte 0x00000EC8\n"
        ".L080F111C: .4byte 0x030000AA @ IWRAM+0xAA\n"
        ".L080F1120: .4byte 0x030000A8 @ IWRAM+0xA8\n"
        ".L080F1124: .4byte 0x0000097C\n"
        ".L080F1128: .4byte gUnknown_080F112C\n"
        "    .global gUnknown_080F112C\n"
        "gUnknown_080F112C:\n"
        ".L080F112C: @ jump table\n"
        "    .4byte .L080F1150\n"
        "    .4byte .L080F11AC\n"
        "    .4byte .L080F1480\n"
        "    .4byte .L080F1340\n"
        "    .4byte .L080F1224\n"
        "    .4byte .L080F1498\n"
        "    .4byte .L080F1208\n"
        "    .4byte .L080F1340\n"
        "    .4byte .L080F149E\n"
        ".L080F1150:\n"
        "    mov r0, sl\n"
        "    movs r1, #0\n"
        "    bl Battle_BuildCombatActionList\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    ldr r2, [sp, #4]\n"
        "    lsls r4, r2, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0\n"
        "    bl Combatant_GetEquip\n"
        "    ldr r1, .L080F11A0\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r0, r1\n"
        "    ldrb r1, [r0]\n"
        "    ldr r0, .L080F11A4\n"
        "    add r0, sb\n"
        "    strh r1, [r0]\n"
        "    ldrh r0, [r0]\n"
        "    bl sub_080ED32C\n"
        "    ldr r1, .L080F11A8\n"
        "    add r1, sb\n"
        "    strh r0, [r1]\n"
        "    mov r0, sl\n"
        "    adds r1, r4, #0\n"
        "    bl sub_080EF5FC\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    cmp r0, r1\n"
        "    beq .L080F119A\n"
        "    b .L080F14BE\n"
        ".L080F119A:\n"
        "    movs r0, #1\n"
        "    str r0, [sp, #0x10]\n"
        "    b .L080F14BE\n"
        ".L080F11A0: .4byte gUnknown_0876E458\n"
        ".L080F11A4: .4byte 0x00000EC6\n"
        ".L080F11A8: .4byte 0x00000ECA\n"
        ".L080F11AC:\n"
        "    mov r0, sl\n"
        "    movs r1, #1\n"
        "    bl Battle_BuildCombatActionList\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    ldr r1, [sp, #4]\n"
        "    lsls r4, r1, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #1\n"
        "    bl Combatant_GetEquip\n"
        "    ldr r1, .L080F11FC\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r0, r1\n"
        "    ldrb r1, [r0]\n"
        "    ldr r0, .L080F1200\n"
        "    add r0, sb\n"
        "    strh r1, [r0]\n"
        "    ldrh r0, [r0]\n"
        "    bl sub_080ED32C\n"
        "    ldr r1, .L080F1204\n"
        "    add r1, sb\n"
        "    strh r0, [r1]\n"
        "    mov r0, sl\n"
        "    adds r1, r4, #0\n"
        "    bl sub_080EF5FC\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    cmp r0, r1\n"
        "    beq .L080F11F6\n"
        "    b .L080F14BE\n"
        ".L080F11F6:\n"
        "    movs r2, #1\n"
        "    str r2, [sp, #0x10]\n"
        "    b .L080F14BE\n"
        ".L080F11FC: .4byte gUnknown_0876E458\n"
        ".L080F1200: .4byte 0x00000EC6\n"
        ".L080F1204: .4byte 0x00000ECA\n"
        ".L080F1208:\n"
        "    movs r0, #0\n"
        "    bl sub_080ED32C\n"
        "    ldr r1, .L080F1220\n"
        "    add r1, sb\n"
        "    strh r0, [r1]\n"
        "    mov r0, sl\n"
        "    movs r1, #2\n"
        "    bl Battle_BuildCombatActionList\n"
        "    b .L080F1332\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1220: .4byte 0x00000ECA\n"
        ".L080F1224:\n"
        "    lsls r4, r5, #0x10\n"
        "    asrs r0, r4, #0x10\n"
        "    movs r1, #0xc\n"
        "    mov r2, sp\n"
        "    bl Item_GetAttribute\n"
        "    ldr r1, [sp, #4]\n"
        "    lsls r0, r1, #0x10\n"
        "    asrs r1, r0, #0x10\n"
        "    adds r6, r0, #0\n"
        "    mov r8, r4\n"
        "    cmp r1, #0xf\n"
        "    bgt .L080F124E\n"
        "    lsrs r0, r4, #0x10\n"
        "    bl Action_GetRecord\n"
        "    ldrb r0, [r0, #3]\n"
        "    cmp r0, #0xff\n"
        "    bne .L080F124E\n"
        "    movs r2, #1\n"
        "    str r2, [sp, #0x10]\n"
        ".L080F124E:\n"
        "    mov r1, r8\n"
        "    asrs r0, r1, #0x10\n"
        "    cmp r0, #0xf0\n"
        "    bne .L080F1274\n"
        "    ldr r1, [sp]\n"
        "    ldr r0, .L080F1270\n"
        "    add r0, sb\n"
        "    strh r1, [r0]\n"
        "    asrs r1, r6, #0xf\n"
        "    movs r0, #0xf3\n"
        "    lsls r0, r0, #4\n"
        "    add r0, sb\n"
        "    adds r0, r0, r1\n"
        "    mov r2, sl\n"
        "    ldrb r1, [r2, #0xc]\n"
        "    b .L080F127E\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1270: .4byte 0x00001192\n"
        ".L080F1274:\n"
        "    cmp r0, #0xf8\n"
        "    bne .L080F1280\n"
        "    ldr r1, [sp]\n"
        "    ldr r0, .L080F12E8\n"
        "    add r0, sb\n"
        ".L080F127E:\n"
        "    strh r1, [r0]\n"
        ".L080F1280:\n"
        "    mov r1, r8\n"
        "    asrs r0, r1, #0x10\n"
        "    cmp r0, #0xbc\n"
        "    ble .L080F1290\n"
        "    ldr r0, [sp]\n"
        "    subs r0, #0x20\n"
        "    cmp r0, #0x17\n"
        "    bhi .L080F129C\n"
        ".L080F1290:\n"
        "    asrs r0, r6, #0x10\n"
        "    bl Battle_IsEnemyId\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #8]\n"
        ".L080F129C:\n"
        "    mov r2, r8\n"
        "    asrs r1, r2, #0x10\n"
        "    cmp r1, #0xf8\n"
        "    beq .L080F12A8\n"
        "    cmp r1, #0xf0\n"
        "    bne .L080F12F4\n"
        ".L080F12A8:\n"
        "    ldr r0, [sp]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    ldr r1, [sp, #8]\n"
        "    lsls r4, r1, #0x10\n"
        "    lsrs r5, r4, #0x10\n"
        "    adds r1, r5, #0\n"
        "    bl Battle_GetActionAnim\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    ldr r1, .L080F12EC\n"
        "    add r1, sb\n"
        "    strh r0, [r1]\n"
        "    ldr r0, [sp]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    adds r1, r5, #0\n"
        "    bl sub_080F104C\n"
        "    ldr r1, .L080F12F0\n"
        "    add r1, sb\n"
        "    strh r0, [r1]\n"
        "    ldr r0, [sp]\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    asrs r4, r4, #0x10\n"
        "    adds r1, r4, #0\n"
        "    bl Battle_GetAnimKind\n"
        "    b .L080F132C\n"
        "    .byte 0x00, 0x00\n"
        ".L080F12E8: .4byte 0x00001194\n"
        ".L080F12EC: .4byte 0x00000EC6\n"
        ".L080F12F0: .4byte 0x00000ECA\n"
        ".L080F12F4:\n"
        "    ldr r0, .L080F1314\n"
        "    subs r1, #0xd0\n"
        "    lsls r1, r1, #2\n"
        "    adds r1, r1, r0\n"
        "    ldrb r0, [r1]\n"
        "    ldr r2, .L080F1318\n"
        "    add r2, sb\n"
        "    strh r0, [r2]\n"
        "    cmp r0, #0xc8\n"
        "    ble .L080F1320\n"
        "    ldrh r1, [r1, #2]\n"
        "    ldr r0, .L080F131C\n"
        "    add r0, sb\n"
        "    strh r1, [r0]\n"
        "    b .L080F132C\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1314: .4byte gUnknown_0876E618\n"
        ".L080F1318: .4byte 0x00000EC6\n"
        ".L080F131C: .4byte 0x00000ECA\n"
        ".L080F1320:\n"
        "    ldrh r0, [r2]\n"
        "    bl sub_080ED32C\n"
        "    ldr r1, .L080F133C\n"
        "    add r1, sb\n"
        "    strh r0, [r1]\n"
        ".L080F132C:\n"
        "    mov r0, sl\n"
        "    bl Battle_BuildActorActionText\n"
        ".L080F1332:\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    b .L080F14BE\n"
        ".L080F133C: .4byte 0x00000ECA\n"
        ".L080F1340:\n"
        "    ldr r2, [sp, #4]\n"
        "    lsls r0, r2, #0x10\n"
        "    asrs r1, r0, #0x10\n"
        "    adds r6, r0, #0\n"
        "    lsls r5, r5, #0x10\n"
        "    mov r8, r5\n"
        "    cmp r1, #0xf\n"
        "    bgt .L080F1364\n"
        "    lsrs r0, r5, #0x10\n"
        "    bl sub_080BF5C0\n"
        "    ldrb r0, [r0, #2]\n"
        "    cmp r0, #0xf\n"
        "    beq .L080F1360\n"
        "    cmp r0, #0xff\n"
        "    bne .L080F1364\n"
        ".L080F1360:\n"
        "    movs r0, #1\n"
        "    str r0, [sp, #0x10]\n"
        ".L080F1364:\n"
        "    mov r1, r8\n"
        "    asrs r7, r1, #0x10\n"
        "    cmp r7, #0x3f\n"
        "    bgt .L080F13E4\n"
        "    adds r0, r7, #0\n"
        "    subs r0, #0x20\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #0x17\n"
        "    bhi .L080F1384\n"
        "    asrs r0, r6, #0x10\n"
        "    bl Battle_IsEnemyId\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #8]\n"
        ".L080F1384:\n"
        "    cmp r4, #2\n"
        "    bhi .L080F138E\n"
        "    ldr r1, .L080F13B4\n"
        "    movs r0, #0\n"
        "    strh r0, [r1]\n"
        ".L080F138E:\n"
        "    mov r0, sl\n"
        "    bl sub_080EAE30\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    movs r0, #2\n"
        "    ldr r2, [sp, #0xc]\n"
        "    ands r0, r2\n"
        "    cmp r0, #0\n"
        "    beq .L080F13BC\n"
        "    ldr r1, .L080F13B8\n"
        "    add r1, sb\n"
        "    movs r0, #0xff\n"
        "    strh r0, [r1]\n"
        "    ldr r0, [sp, #8]\n"
        "    lsls r4, r0, #0x10\n"
        "    b .L080F1466\n"
        ".L080F13B4: .4byte 0x030000A8 @ IWRAM+0xA8\n"
        ".L080F13B8: .4byte 0x00000EC6\n"
        ".L080F13BC:\n"
        "    mov r1, r8\n"
        "    lsrs r0, r1, #0x10\n"
        "    ldr r2, [sp, #8]\n"
        "    lsls r4, r2, #0x10\n"
        "    lsrs r1, r4, #0x10\n"
        "    bl Battle_GetActionAnim\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    ldr r1, .L080F13E0\n"
        "    add r1, sb\n"
        "    strh r0, [r1]\n"
        "    asrs r1, r4, #0x10\n"
        "    adds r0, r7, #0\n"
        "    bl Battle_GetAnimKind\n"
        "    b .L080F1466\n"
        "    .byte 0x00, 0x00\n"
        ".L080F13E0: .4byte 0x00000EC6\n"
        ".L080F13E4:\n"
        "    ldr r1, .L080F141C\n"
        "    adds r0, r7, #0\n"
        "    subs r0, #0x40\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r1\n"
        "    movs r1, #0\n"
        "    ldrsh r5, [r0, r1]\n"
        "    cmp r7, #0x66\n"
        "    bne .L080F1420\n"
        "    bl sub_080F5938\n"
        "    adds r4, r0, #0\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r4, r0\n"
        "    bne .L080F1406\n"
        "    movs r4, #0\n"
        ".L080F1406:\n"
        "    adds r0, r5, #0\n"
        "    bl Battle_GetMessage\n"
        "    adds r1, r4, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    b .L080F1444\n"
        ".L080F141C: .4byte gUnknown_0876E878\n"
        ".L080F1420:\n"
        "    adds r0, r5, #0\n"
        "    bl Battle_GetMessage\n"
        "    adds r5, r0, #0\n"
        "    asrs r4, r6, #0x10\n"
        "    adds r0, r4, #0\n"
        "    bl Combatant_GetChosenSkill\n"
        "    lsls r0, r0, #0x10\n"
        "    adds r4, r4, r0\n"
        "    adds r0, r5, #0\n"
        "    adds r1, r4, #0\n"
        "    bl Menu_ExpandListTemplate\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        ".L080F1444:\n"
        "    mov r2, r8\n"
        "    lsrs r0, r2, #0x10\n"
        "    ldr r1, [sp, #8]\n"
        "    lsls r4, r1, #0x10\n"
        "    lsrs r1, r4, #0x10\n"
        "    bl Battle_GetActionAnim\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    ldr r1, .L080F1478\n"
        "    add r1, sb\n"
        "    strh r0, [r1]\n"
        "    mov r2, r8\n"
        "    asrs r0, r2, #0x10\n"
        "    asrs r1, r4, #0x10\n"
        "    bl Battle_GetAnimKind\n"
        ".L080F1466:\n"
        "    mov r1, r8\n"
        "    lsrs r0, r1, #0x10\n"
        "    lsrs r1, r4, #0x10\n"
        "    bl sub_080F104C\n"
        "    ldr r1, .L080F147C\n"
        "    add r1, sb\n"
        "    b .L080F14BC\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1478: .4byte 0x00000EC6\n"
        ".L080F147C: .4byte 0x00000ECA\n"
        ".L080F1480:\n"
        "    ldr r2, [sp, #4]\n"
        "    lsls r0, r2, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    movs r1, #0\n"
        "    bl Battle_SummonQueuedDemon\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Party_GetMember\n"
        "    movs r1, #3\n"
        "    b .L080F14AA\n"
        ".L080F1498:\n"
        "    mov r0, sl\n"
        "    movs r1, #4\n"
        "    b .L080F14AA\n"
        ".L080F149E:\n"
        "    ldr r0, [sp, #4]\n"
        "    movs r1, #0\n"
        "    bl Party_Remove\n"
        "    mov r0, sl\n"
        "    movs r1, #5\n"
        ".L080F14AA:\n"
        "    bl Battle_BuildCombatActionList\n"
        "    adds r1, r0, #0\n"
        "    movs r0, #3\n"
        "    bl BattleMenu_SetModeAutoClose\n"
        "    ldr r1, .L080F14EC\n"
        "    add r1, sb\n"
        "    movs r0, #0xb\n"
        ".L080F14BC:\n"
        "    strh r0, [r1]\n"
        ".L080F14BE:\n"
        "    ldr r0, .L080F14F0\n"
        "    add r0, sb\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    cmp r0, #0x88\n"
        "    bne .L080F14D8\n"
        "    mov r2, sl\n"
        "    movs r0, #0x17\n"
        "    ldrsb r0, [r2, r0]\n"
        "    cmp r0, #8\n"
        "    bne .L080F14D8\n"
        "    movs r0, #1\n"
        "    str r0, [sp, #0x10]\n"
        ".L080F14D8:\n"
        "    bl Battle_IsTwoSided\n"
        "    cmp r0, #0\n"
        "    beq .L080F14E6\n"
        "    ldr r1, [sp, #0x10]\n"
        "    cmp r1, #1\n"
        "    bne .L080F14F8\n"
        ".L080F14E6:\n"
        "    ldr r1, .L080F14F4\n"
        "    movs r0, #0\n"
        "    b .L080F154C\n"
        ".L080F14EC: .4byte 0x0000097C\n"
        ".L080F14F0: .4byte 0x00000EC6\n"
        ".L080F14F4: .4byte 0x030000A8 @ IWRAM+0xA8\n"
        ".L080F14F8:\n"
        "    ldr r2, [sp, #4]\n"
        "    lsls r0, r2, #0x10\n"
        "    asrs r1, r0, #0x10\n"
        "    adds r6, r0, #0\n"
        "    cmp r1, #0xf\n"
        "    bgt .L080F1538\n"
        "    movs r0, #0\n"
        "    bl sub_080EDA24\n"
        "    cmp r0, #0\n"
        "    beq .L080F1522\n"
        "    movs r0, #1\n"
        "    bl sub_080EDA24\n"
        "    cmp r0, #0\n"
        "    beq .L080F1522\n"
        "    ldr r1, .L080F1534\n"
        "    movs r2, #0\n"
        "    ldrsh r0, [r1, r2]\n"
        "    cmp r0, #0\n"
        "    beq .L080F154C\n"
        ".L080F1522:\n"
        "    asrs r0, r6, #0x10\n"
        "    bl sub_080F1788\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080F1548\n"
        "    ldr r1, .L080F1534\n"
        "    movs r0, #1\n"
        "    b .L080F154C\n"
        ".L080F1534: .4byte 0x030000A8 @ IWRAM+0xA8\n"
        ".L080F1538:\n"
        "    cmp r1, #0x13\n"
        "    bgt .L080F1548\n"
        "    ldr r1, .L080F1544\n"
        "    movs r0, #1\n"
        "    b .L080F154C\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1544: .4byte 0x030000A8 @ IWRAM+0xA8\n"
        ".L080F1548:\n"
        "    ldr r1, .L080F1574\n"
        "    movs r0, #2\n"
        ".L080F154C:\n"
        "    strh r0, [r1]\n"
        "    bl sub_080C2B6C\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bne .L080F1562\n"
        "    ldr r1, .L080F1578\n"
        "    add r1, sb\n"
        "    movs r0, #0xff\n"
        "    strh r0, [r1]\n"
        ".L080F1562:\n"
        "    add sp, #0x14\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080F1574: .4byte 0x030000A8 @ IWRAM+0xA8\n"
        ".L080F1578: .4byte 0x00000EC6\n"
    );
}
#endif

// Battle_GetAnimKind @ 0x080F157C
/* Animation kind of special entry gUnknown_0876E1D8[a].id[b]: 0xDC-0xDF 4, 0xE0-0xE2 7,
   0xE3-0xE5 8, 0xE6-0xE8 5, otherwise 0xFF. */
s16 Battle_GetAnimKind(s16 a, s16 b)
{
    u8 v = gUnknown_0876E1D8[a].id[b];

    gUnk_030000AA = 0xFF;
    switch (v)
    {
    case 0xDC:
        gUnk_030000AA = 4;
        break;
    case 0xDD:
        gUnk_030000AA = 4;
        break;
    case 0xDE:
        gUnk_030000AA = 4;
        break;
    case 0xDF:
        gUnk_030000AA = 4;
        break;
    case 0xE0:
        gUnk_030000AA = 7;
        break;
    case 0xE1:
        gUnk_030000AA = 7;
        break;
    case 0xE2:
        gUnk_030000AA = 7;
        break;
    case 0xE3:
        gUnk_030000AA = 8;
        break;
    case 0xE4:
        gUnk_030000AA = 8;
        break;
    case 0xE5:
        gUnk_030000AA = 8;
        break;
    case 0xE6:
    case 0xE7:
    case 0xE8:
        gUnk_030000AA = 5;
        break;
    case 0xFF:
        break;
    }
    return gUnk_030000AA;
}

// Battle_SummonQueuedDemon @ 0x080F1678
/* Summons the demon queued for party slot i into the formation (the first free position when
   the queued one is taken). mode 2 first removes the member there, mode 0 pays the summon
   cost, mode 3 adds it dead (status 0x4000, HP 0). Returns its new party position. */
#ifdef NONMATCHING
u16 Battle_SummonQueuedDemon(s16 i, s16 mode)
{
    struct F108CBattle *b = BB;
    u16 *posp = &b->summonPos[i];
    s16 pos = *posp;
    u16 *idp = &b->summonId[i];
    s16 id = *idp;

    if (mode == 2)
    {
        if (gGameState.order[pos] != -1)
            Party_Remove(gGameState.order[pos], 0);
        *idp = 0xFFFF;
        *posp = -1;
    }
    if (sub_080F30CC(pos) != -1)
    {
        s16 j;

        for (j = 0; j <= 5; j++)
        {
            if (sub_080F30CC(j) == -1)
            {
                pos = j;
                break;
            }
        }
    }
    Party_AddAt(id, pos);
    if (mode == 0)
        sub_080F3E20(-sub_0812839C(id));
    if (mode == 3)
    {
        Combatant_SetStatus(gGameState.order[pos], 0x4000);
        Battle_SetHp(gGameState.order[pos], 0);
    }
    sub_080C8490(pos);
    Party_FixFormation();
    Party_BuildMemberNameTiles();
    return Party_FindPosition(id);
}
#else
NAKED u16 Battle_SummonQueuedDemon(s16 i, s16 mode)
{
    asm_unified(
        ".L080F1678:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, r8\n"
        "    push {r7}\n"
        "    lsls r1, r1, #0x10\n"
        "    ldr r3, .L080F16F0\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0xf\n"
        "    movs r4, #0xf1\n"
        "    lsls r4, r4, #4\n"
        "    adds r2, r3, r4\n"
        "    adds r5, r0, r2\n"
        "    ldrh r6, [r5]\n"
        "    movs r2, #0xef\n"
        "    lsls r2, r2, #4\n"
        "    adds r3, r3, r2\n"
        "    adds r4, r0, r3\n"
        "    ldrh r0, [r4]\n"
        "    mov r8, r0\n"
        "    lsrs r7, r1, #0x10\n"
        "    asrs r1, r1, #0x10\n"
        "    cmp r1, #2\n"
        "    bne .L080F16D4\n"
        "    ldr r1, .L080F16F4\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    movs r2, #0xa2\n"
        "    lsls r2, r2, #4\n"
        "    adds r1, r1, r2\n"
        "    adds r2, r0, r1\n"
        "    movs r1, #0\n"
        "    ldrsb r1, [r2, r1]\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r1, r0\n"
        "    beq .L080F16CA\n"
        "    adds r0, r1, #0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    movs r1, #0\n"
        "    bl Party_Remove\n"
        ".L080F16CA:\n"
        "    ldr r0, .L080F16F8\n"
        "    strh r0, [r4]\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    strh r0, [r5]\n"
        ".L080F16D4:\n"
        "    lsls r0, r6, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    bl sub_080F30CC\n"
        "    movs r1, #1\n"
        "    rsbs r1, r1, #0\n"
        "    lsls r7, r7, #0x10\n"
        "    mov r4, r8\n"
        "    lsls r4, r4, #0x10\n"
        "    mov r8, r4\n"
        "    cmp r0, r1\n"
        "    beq .L080F171A\n"
        "    movs r0, #0\n"
        "    b .L080F1702\n"
        ".L080F16F0: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080F16F4: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080F16F8: .4byte 0x0000FFFF\n"
        ".L080F16FC:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        ".L080F1702:\n"
        "    lsls r5, r0, #0x10\n"
        "    asrs r4, r5, #0x10\n"
        "    cmp r4, #5\n"
        "    bgt .L080F171A\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080F30CC\n"
        "    movs r1, #1\n"
        "    rsbs r1, r1, #0\n"
        "    cmp r0, r1\n"
        "    bne .L080F16FC\n"
        "    lsrs r6, r5, #0x10\n"
        ".L080F171A:\n"
        "    mov r0, r8\n"
        "    lsrs r5, r0, #0x10\n"
        "    lsls r6, r6, #0x10\n"
        "    lsrs r1, r6, #0x10\n"
        "    adds r0, r5, #0\n"
        "    bl Party_AddAt\n"
        "    asrs r4, r7, #0x10\n"
        "    cmp r4, #0\n"
        "    bne .L080F173A\n"
        "    adds r0, r5, #0\n"
        "    bl sub_0812839C\n"
        "    rsbs r0, r0, #0\n"
        "    bl sub_080F3E20\n"
        ".L080F173A:\n"
        "    asrs r5, r6, #0x10\n"
        "    cmp r4, #3\n"
        "    bne .L080F1760\n"
        "    ldr r4, .L080F1784\n"
        "    movs r1, #0xa2\n"
        "    lsls r1, r1, #4\n"
        "    adds r4, r4, r1\n"
        "    adds r4, r5, r4\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r4, r0]\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #7\n"
        "    bl Combatant_SetStatus\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r4, r0]\n"
        "    movs r1, #0\n"
        "    bl Battle_SetHp\n"
        ".L080F1760:\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080C8490\n"
        "    bl Party_FixFormation\n"
        "    bl Party_BuildMemberNameTiles\n"
        "    mov r2, r8\n"
        "    asrs r0, r2, #0x10\n"
        "    bl Party_FindPosition\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    pop {r3}\n"
        "    mov r8, r3\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        ".L080F1784: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
    );
}
#endif
