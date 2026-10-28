#include "global.h"
#include "inventory.h"

// sub_080C4C18 @ 0x080C4C18
u32 sub_080C4C18(u32 n)
{
    return (gGameState.bitsACA[n >> 3] >> (n & 7)) & 1;
}

// sub_080C4C3C @ 0x080C4C3C
void sub_080C4C3C(u32 n)
{
    gGameState.bitsACA[n >> 3] |= 1 << (n & 7);
}

// sub_080C4C60 @ 0x080C4C60
const void *sub_080C4C60(u16 id)
{
    const void *p;

    if (id < 0xD0)
        p = *(const void **)(Item_GetRecord(id) + 0xC);
    else
        p = *(const void **)(Action_GetRecord(id) + 4);
    return p;
}

// sub_080C4C7C @ 0x080C4C7C
const void *sub_080C4C7C(u16 id)
{
    const void *p;

    if (id < 0xD0)
        p = *(const void **)(Item_GetRecord(id) + 0x10);
    else
        p = *(const void **)(Action_GetRecord(id) + 8);
    return p;
}

// sub_080C4C98 @ 0x080C4C98
/* Stocked demons outside the party regain level / 4 + 1 HP. */
void sub_080C4C98(void)
{
    s32 i;

    for (i = 4; i <= 15; i++)
    {
        if (!Combatant_IsInParty(i) && !Combatant_IsDead(i))
        {
            Battle_GetCombatant((u32)i - 0x8000);
            Combatant_ChangeHpCapped(i, Combatant_GetLevel(i) / 4 + 1);
        }
    }
}

// Party_DrainHpFromStrongest @ 0x080C4CE8
/* Moves 1 HP to who from the living party member with the most HP; returns that member or
   0xFFFF. */
u16 Party_DrainHpFromStrongest(u16 who)
{
    u16 best = 0;
    u16 from = 0xFFFF;
    u16 i;
    struct Combatant *c;

    for (i = 0; i < 6; i++)
    {
        c = Party_GetMember(i);

        if (c != NULL && c->id != who && !Combatant_IsDead(c->id) && c->hp > best)
        {
            best = c->hp;
            from = c->id;
        }
    }
    if (from != 0xFFFF)
    {
        c = Party_GetMember(who + 0x8000);
        if (++c->hp > c->maxHp)
            c->hp = c->maxHp;
        Combatant_Damage(from, 1);
        sub_080C84A0();
    }
    return from;
}

// sub_080C4D74 @ 0x080C4D74
/* Chance per step to recover from status 0x40 (by stat total[1]) and 0x20 (by the moon). */
#ifdef NONMATCHING
void sub_080C4D74(u16 who)
{
    struct Combatant *c = Party_GetMember(who + 0x8000);
    u16 st = Combatant_GetStatus(who);

    if (st & 0x40)
    {
        if (Random_ChanceIn16((s8)c->total[1] / 4 + 2))
        {
            Combatant_ClearStatus(who, ~0x40);
            sub_080C84A0();
        }
    }
    if (st & 0x20)
    {
        if (Random_ChanceIn16(12 - Moon_GetFullness()))
        {
            Combatant_ClearStatus(who, ~0x20);
            sub_080C84A0();
        }
    }
}
#else
NAKED
void sub_080C4D74(u16 who)
{
    asm_unified(
        ".L080C4D74:\n"
        "    push {r4, r5, r6, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #0x18\n"
        "    adds r0, r0, r1\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Party_GetMember\n"
        "    adds r4, r0, #0\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_GetStatus\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    movs r0, #0x40\n"
        "    ands r0, r6\n"
        "    cmp r0, #0\n"
        "    beq .L080C4DC8\n"
        "    adds r0, r4, #0\n"
        "    adds r0, #0x41\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    cmp r0, #0\n"
        "    bge .L080C4DAA\n"
        "    adds r0, #3\n"
        ".L080C4DAA:\n"
        "    asrs r0, r0, #2\n"
        "    adds r0, #2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Random_ChanceIn16\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L080C4DC8\n"
        "    ldr r1, .L080C4DF8\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_ClearStatus\n"
        "    bl sub_080C84A0\n"
        ".L080C4DC8:\n"
        "    movs r0, #0x20\n"
        "    ands r0, r6\n"
        "    cmp r0, #0\n"
        "    beq .L080C4DF2\n"
        "    bl Moon_GetFullness\n"
        "    movs r1, #0xc\n"
        "    subs r1, r1, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r0, r1, #0x10\n"
        "    bl Random_ChanceIn16\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L080C4DF2\n"
        "    ldr r1, .L080C4DFC\n"
        "    adds r0, r5, #0\n"
        "    bl Combatant_ClearStatus\n"
        "    bl sub_080C84A0\n"
        ".L080C4DF2:\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080C4DF8: .4byte 0x0000FFBF\n"
        ".L080C4DFC: .4byte 0x0000FFDF\n"
    );
}
#endif

// Random_ChanceIn16 @ 0x080C4E00
/* TRUE with probability (chance + 1) / 16. */
u16 Random_ChanceIn16(u16 chance)
{
    if (chance > 14 || chance >= (Random_Byte() & 0xF))
        return TRUE;
    return FALSE;
}

// Moon_GetFullness @ 0x080C4E24
/* Distance of the moon phase from new moon, 0-8. */
u32 Moon_GetFullness(void)
{
    u16 p = Moon_GetPhase();

    p = (p & 0xFF) >> 4;

    if (p > 8)
        p = 16 - p;
    return p;
}

// Field_ApplyStepStatusDamage @ 0x080C4E48
/* Field step damage from status: 0x400 drains 1 HP from an ally, 0x1000 every other step,
   4 and 1 every fourth step. Bits of members brought to 0 HP are set in *mask. */
u32 Field_ApplyStepStatusDamage(u32 step, u32 *mask)
{
    u32 hurt;
    s32 i;

    step &= 0xFF;
    hurt = 0;
    for (i = 0; i <= 5; i++)
    {
        struct Combatant *c = Party_GetMember(i);
        u32 id;
        u32 used;
        u16 st;

        if (c == NULL)
            continue;
        id = c->id;
        used = Combatant_IsUsed(id);
        if (used != 1 || Combatant_IsDead(id))
            continue;
        st = Combatant_GetStatus(id);
        if (st & 0x8000)
            continue;
        if (st & 0x400)
        {
            u16 from = Party_DrainHpFromStrongest(id);

            if (from != 0xFFFF)
            {
                if (Battle_GetHp(from) == 0)
                    *mask |= used << from;
                hurt = 1;
            }
        }
        else if ((st & 0x1000) && (used & step))
        {
            if (Battle_GetHp(id) == 1)
                *mask |= 1 << id;
            Combatant_Damage(id, 1);
            sub_080C8490(i);
            hurt = 1;
        }
        else if ((st & 4) && (step & 3) == 3)
        {
            if (Battle_GetHp(id) == 1)
                *mask |= 1 << id;
            Combatant_Damage(id, 1);
            sub_080C8490(i);
            hurt = 1;
        }
        else if ((st & 1) && (step & 3) == 3)
        {
            if (Battle_GetHp(id) == 1)
                *mask |= 1 << id;
            Combatant_Damage(id, 1);
            sub_080C8490(i);
            hurt = 1;
        }
        if (Battle_GetHp(id) != 0)
            sub_080C4D74(id);
    }
    if (hurt == 1)
    {
        sub_080B8AE0(0x7C1F, 1);
        Sound_Play(0x12B);
    }
    return hurt;
}

// Field_ApplyStepStatusDamageKill @ 0x080C4F88
/* As Field_ApplyStepStatusDamage but kills members at 0 HP: result bit 0 someone hurt, bit 1 a demon died,
   bit 2 a human died. */
s16 Field_ApplyStepStatusDamageKill(u32 step)
{
    u32 dead = 0;
    u32 res;
    s32 i;

    step &= 0xFF;
    res = 0;
    for (i = 0; i <= 5; i++)
    {
        struct Combatant *c = Party_GetMember(i);
        u32 id;
        u16 st;

        if (c == NULL)
            continue;
        id = c->id;
        if (Combatant_IsUsed(id) != 1 || Combatant_IsDead(id))
            continue;
        st = Combatant_GetStatus(id);
        if (st & 0x8000)
            continue;
        if (st & 0x400)
        {
            u16 from = Party_DrainHpFromStrongest(id);

            if (from != 0xFFFF)
            {
                if (Battle_GetHp(from) == 0)
                    dead |= 1 << from;
                res |= 1;
            }
        }
        else if ((st & 0x1000) && (step & 1))
        {
            Combatant_ChangeHp(id, -1);
            res |= 1;
        }
        else if ((st & 5) && (step & 3) == 3)
        {
            Combatant_ChangeHp(id, -1);
            res |= 1;
        }
        if (Battle_GetHp(id) <= 0)
        {
            Combatant_GetStatus(id);
            Combatant_SetStatus(id, 0x8000);
            if ((s32)id > 3)
            {
                sub_080F4190(id);
                Party_FixFormation();
                res |= 2;
            }
            else
            {
                res |= 4;
            }
        }
        else
        {
            sub_080C4D74(id);
        }
    }
    for (i = 0; i <= 15; i++)
    {
        struct Combatant *c = Party_GetMember((u32)i - 0x8000);

        if ((1 << i) & dead)
        {
            Combatant_SetStatus(c->id, 0x8000);
            if (c->id > 3)
            {
                sub_080F4190(c->id);
                Party_FixFormation();
                res |= 2;
            }
            else
            {
                res |= 4;
            }
        }
    }
    return res;
}

// Party_HasActiveHuman @ 0x080C5108
/* FALSE when every human in the party is dead or stoned. */
u32 Party_HasActiveHuman(void)
{
    u32 any = 0;
    s32 i;

    for (i = 0; i <= 3; i++)
    {
        struct Combatant *c = Party_GetMember((u32)i - 0x8000);

        if (c != NULL && c->unkE != 0)
        {
            if (!(c->flags & 0xA000) && c->hp != 0)
                return TRUE;
            any = 1;
        }
    }
    if (any == 0)
        return TRUE;
    return FALSE;
}

// sub_080C5158 @ 0x080C5158
void sub_080C5158(struct Task *t)
{
    u32 r = Party_HasActiveHuman();

    if (r != 1)
        r = 0;
    t->result = r;
}

// Music_Play @ 0x080C5170
void Music_Play(u16 song)
{
    if (song != gUnk_030031B4)
    {
        gUnk_030031EC = gUnk_030031B4;
        gUnk_030031B4 = song;
        m4aSongNumStart(song);
    }
}

// Music_Stop @ 0x080C5198
void Music_Stop(void)
{
    m4aSongNumStop(gUnk_030031B4);
    gUnk_030031EC = gUnk_030031B4;
    gUnk_030031B4 = 0;
}

// Music_FadeOut @ 0x080C51BC
void Music_FadeOut(u16 speed)
{
    m4aMPlayFadeOut(gUnk_0203F2E0, speed);
}

// Sound_Play @ 0x080C51D4
void Sound_Play(u16 se)
{
    m4aSongNumStart(se);
}

// sub_080C51E4 @ 0x080C51E4
void sub_080C51E4(void)
{
    gHudState[0x1A] = 1;
}

// sub_080C51F0 @ 0x080C51F0
void sub_080C51F0(void)
{
    gGameState.unkA38 = 0;
    sub_080C2D78(gGameState.unk18AC, gGameState.unk18AE);
}

// sub_080C5224 @ 0x080C5224
void sub_080C5224(void)
{
    Task_Create(gUnknown_081A65F4, 0xFFFF);
    Field_SetState(0x1A);
}

// sub_080C5240 @ 0x080C5240
u32 sub_080C5240(void)
{
    if (Flag_Test(1) || Flag_Test(0xAE))
        return FALSE;
    if (gUnk_03004614 == 0x42 || gUnk_03004614 == 0x4A || gUnk_03004614 == 0x4B
        || gUnk_03004614 == 0xF)
        return FALSE;
    if (gGameState.unkAC0 == 1)
        return FALSE;
    return TRUE;
}

// sub_080C528C @ 0x080C528C
void sub_080C528C(void)
{
    gHudState[0x1A] = 1;
}

// sub_080C5298 @ 0x080C5298
void sub_080C5298(void)
{
    u8 v;

    gGameState.unkA38 = gGameState.unk18AA;
    v = gGameState.unkAC2;
    if (v == 0)
        sub_080B710C(gGameState.unk18A6, gGameState.unk18A8, gGameState.unk18A2,
                     gGameState.unk18A4, gGameState.unk18A0, v);
    else
        sub_080D0BA0();
}

// sub_080C5304 @ 0x080C5304
void sub_080C5304(void)
{
    Task_Create(gUnknown_081A6634, 0xFFFF);
    Field_SetState(0x1A);
}
