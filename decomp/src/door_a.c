#include "global.h"
#include "fieldcmd.h"

// sub_080BE6E0 @ 0x080BE6E0
struct Task *sub_080BE6E0(u16 id)
{
    struct Task *t = Task_Create(gUnknown_08198128, 0xFFFF);

    gSceneEffectTask = t;
    t->data.h[0] = id;
    /* no return statement: the original falls off the end of a non-void function */
}

// Door_FindAtPlayer @ 0x080BE70C
/* Returns the door record for the player's cell and facing, or NULL. The facing test indexes
   the table again; through p the compiler would reuse the yDir load. */
const struct DoorRec *Door_FindAtPlayer(void)
{
    u16 x, y;
    const struct DoorRec *p;

    sub_080C1F50(gFieldState.unk12, gFieldState.unk14, &x, &y);
    p = gUnknown_08198278;
loop:
    if (p->x == 0xFF)
        return NULL;
    if (p->x != (u8)x || (p->yDir & 0x3F) != (u8)y
        || (gUnknown_08198278[p - gUnknown_08198278].yDir >> 6) != (u8)gFieldState.unk02)
    {
        p++;
        goto loop;
    }
    return p;
}

// Door_TryOpen @ 0x080BE76C
/* Starts the door's script; keypad doors (kind 3) only while flag 0x110+id is clear.
   Assumes a door record exists (no NULL check). */
u32 Door_TryOpen(void)
{
    const struct DoorRec *p = Door_FindAtPlayer();
    const u32 *script;

    switch (p->kind & 0xF)
    {
    case 0:
        goto fail;
    case 1:
        script = gUnknown_08198554;
        break;
    case 2:
        script = gUnknown_08198648;
        break;
    case 3:
        if (Flag_Test(p->id + 0x110))
            goto fail;
        script = gUnknown_08198328;
        break;
    default:
        goto fail;
    }
    Task_Create(script, 0xFFFF);
    Field_SetState(0x1A);
    return 1;
fail:
    return 0;
}

// sub_080BE7D0 @ 0x080BE7D0
void sub_080BE7D0(struct Task *task)
{
    task->data.w[0] = (u32)Door_KeypadInitInputState();
}

// sub_080BE7E0 @ 0x080BE7E0
void sub_080BE7E0(struct Task *task)
{
    ((u32 *)task->data.w[0])[3] = 1;
}

// sub_080BE7E8 @ 0x080BE7E8
void sub_080BE7E8(void)
{
    gFieldState.unk00 = 1;
    gUnk_03003FF4 = 0;
}

// Door_CheckKeypadCode @ 0x080BE800
/* Checks the 4-digit keypad entry (gYesNoResult) against the door's code; three wrong
   tries give result 2. */
void Door_CheckKeypadCode(struct Task *task)
{
    u32 *d = task->data.w;
    const struct DoorRec *p = Door_FindAtPlayer();
    const u8 *code = &gUnknown_081982FD[p->id * 4];
    u8 *dig = NumberToDigits(gYesNoResult);

    if (dig[3] == code[0] && dig[2] == code[1] && dig[1] == code[2] && dig[0] == code[3])
    {
        task->unk1E = 0;
        Flag_Set(p->id + 0x110);
    }
    else if (++d[1] == 3)
    {
        task->unk1E = 2;
    }
    else
    {
        task->unk1E = 1;
    }
}

// sub_080BE874 @ 0x080BE874
void sub_080BE874(struct Task *task)
{
    task->unk1E = gYesNoResult;
}

// sub_080BE880 @ 0x080BE880
void sub_080BE880(struct Task *task, u32 step)
{
    if (step == 0)
    {
        gFieldState.unk02 = sub_080B1A1C(gFieldState.unk02);
        sub_080B2840(0, 0, 0);
    }
    else
    {
        VBlankTask_AddCounted(sub_080B0158, 1);
    }
}

// Door_CheckStat @ 0x080BE8B4
/* Stat door: passes when the leader's stat (kind >> 4) is at least id. With the 0x800
   status every stat counts as 1 (and the sixth as 40). */
void Door_CheckStat(struct Task *task)
{
    u8 *e = Party_GetMember(0x8000);
    const struct DoorRec *p = Door_FindAtPlayer();
    u8 stats[6];
    u32 idx;

    stats[0] = e[0x28];
    stats[1] = e[0x29];
    stats[2] = e[0x2A];
    stats[3] = e[0x2B];
    stats[4] = e[0x2C];
    stats[5] = e[0x2D];
    if (Combatant_GetStatus(e[0xC]) & 0x800)
    {
        stats[0] = 1;
        stats[1] = 1;
        stats[2] = 1;
        stats[3] = 1;
        stats[4] = 1;
        stats[5] = 0x28;
    }
    idx = (*(u16 *)&p->kind >> 4) & 0xF;
    if (stats[idx] >= (*(u16 *)&p->kind >> 8))
    {
        sub_080B832C(task, gUnknown_08002EFE);
        task->result = 1;
    }
    else
    {
        sub_080B832C(task, gUnknown_0819853C[idx]);
        task->result = 0;
    }
}

// Door_CheckAlignment @ 0x080BE968
/* Alignment door: kind bit 6 lets law (< 0x7000), bit 4 neutral (< 0x9000), bit 5 chaos
   through. */
void Door_CheckAlignment(struct Task *task)
{
    u8 *e = Party_GetMember(0x8000);
    const struct DoorRec *p = Door_FindAtPlayer();
    u16 align = *(u16 *)(e + 0x58);
    u32 ok = 0;

    if (align <= 0x6FFF)
    {
        u16 law = *(u16 *)&p->kind & 0x40;
        ok = law != 0;
    }
    else if (align <= 0x8FFF)
    {
        if (*(u16 *)&p->kind & 0x10)
            ok = 1;
    }
    else if (*(u16 *)&p->kind & 0x20)
        ok = 1;
    if (ok == 1)
    {
        sub_080B832C(task, gUnknown_08002EFE);
        task->result = ok;
    }
    else
    {
        sub_080B832C(task, gUnknown_08003192);
        task->result = 0;
    }
}

// sub_080BE9E4 @ 0x080BE9E4
void sub_080BE9E4(struct Task *task)
{
    u32 *d = task->data.w;

    d[3] = Window_Create(2, 0xB, 0x1A, 2, 0);
}

// sub_080BEA08 @ 0x080BEA08
void sub_080BEA08(struct Task *task)
{
    u16 *d = task->data.h;

    task->result = 0;
    if (!(task->data.w[0] & (1 << d[4])))
    {
        task->result = 1;
        d[4]++;
    }
}

// sub_080BEA34 @ 0x080BEA34
void sub_080BEA34(struct Task *task)
{
    u16 *d = task->data.h;

    task->result = 0;
    if (gKeysNew & 1)
    {
        d[4]++;
        task->result = 1;
    }
}
