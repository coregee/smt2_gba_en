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
#ifdef NONMATCHING
/* Returns the door record for the player's cell and facing, or NULL. */
const struct DoorRec *Door_FindAtPlayer(void)
{
    u16 x, y;
    const struct DoorRec *p;

    sub_080C1F50(gFieldState.unk12, gFieldState.unk14, &x, &y);
    p = gUnknown_08198278;
    for (;;)
    {
        if (p->x == 0xFF)
            return NULL;
        if (p->x == (u8)x && (p->yDir & 0x3F) == (u8)y && (p->yDir >> 6) == (u8)gFieldState.unk02)
            break;
        p++;
    }
    return p;
}
#else
NAKED
const struct DoorRec *Door_FindAtPlayer(void)
{
    asm_unified(
        ".L080BE70C:\n"
        "    push {r4, lr}\n"
        "    sub sp, #4\n"
        "    ldr r1, .L080BE730\n"
        "    ldrh r0, [r1, #0x12]\n"
        "    ldrh r1, [r1, #0x14]\n"
        "    mov r4, sp\n"
        "    adds r4, #2\n"
        "    mov r2, sp\n"
        "    adds r3, r4, #0\n"
        "    bl sub_080C1F50\n"
        "    ldr r2, .L080BE734\n"
        ".L080BE724:\n"
        "    ldrb r1, [r2]\n"
        "    cmp r1, #0xff\n"
        "    bne .L080BE738\n"
        "    movs r0, #0\n"
        "    b .L080BE762\n"
        "    .byte 0x00, 0x00\n"
        ".L080BE730: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080BE734: .4byte gUnknown_08198278\n"
        ".L080BE738:\n"
        "    mov r0, sp\n"
        "    ldrb r0, [r0]\n"
        "    cmp r1, r0\n"
        "    bne .L080BE758\n"
        "    ldrb r1, [r2, #1]\n"
        "    movs r0, #0x3f\n"
        "    ands r0, r1\n"
        "    ldrb r1, [r4]\n"
        "    cmp r0, r1\n"
        "    bne .L080BE758\n"
        "    ldrb r0, [r2, #1]\n"
        "    ldr r1, .L080BE75C\n"
        "    lsrs r0, r0, #6\n"
        "    ldrb r1, [r1, #2]\n"
        "    cmp r0, r1\n"
        "    beq .L080BE760\n"
        ".L080BE758:\n"
        "    adds r2, #4\n"
        "    b .L080BE724\n"
        ".L080BE75C: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080BE760:\n"
        "    adds r0, r2, #0\n"
        ".L080BE762:\n"
        "    add sp, #4\n"
        "    pop {r4}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

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
#ifdef NONMATCHING
/* Alignment door: kind bit 6 lets law (< 0x7000), bit 4 neutral (< 0x9000), bit 5 chaos
   through. */
void Door_CheckAlignment(struct Task *task)
{
    u8 *e = Party_GetMember(0x8000);
    const struct DoorRec *p = Door_FindAtPlayer();
    u16 align = *(u16 *)(e + 0x58);
    u32 ok = 0;

    if (align <= 0x6FFF)
        ok = (*(u16 *)&p->kind & 0x40) != 0;
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
#else
NAKED
void Door_CheckAlignment(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, lr}\n"
        "    adds r5, r0, #0\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #8\n"
        "    bl Party_GetMember\n"
        "    adds r4, r0, #0\n"
        "    bl Door_FindAtPlayer\n"
        "    adds r1, r0, #0\n"
        "    adds r4, #0x58\n"
        "    ldrh r2, [r4]\n"
        "    movs r4, #0\n"
        "    ldr r0, .L080BE998\n"
        "    cmp r2, r0\n"
        "    bhi .L080BE99C\n"
        "    ldrh r1, [r1, #2]\n"
        "    movs r0, #0x40\n"
        "    ands r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    rsbs r0, r0, #0\n"
        "    lsrs r4, r0, #0x1f\n"
        "    b .L080BE9B8\n"
        ".L080BE998: .4byte 0x00006FFF\n"
        ".L080BE99C:\n"
        "    ldr r0, .L080BE9A8\n"
        "    cmp r2, r0\n"
        "    bhi .L080BE9AC\n"
        "    ldrh r1, [r1, #2]\n"
        "    movs r0, #0x10\n"
        "    b .L080BE9B0\n"
        ".L080BE9A8: .4byte 0x00008FFF\n"
        ".L080BE9AC:\n"
        "    ldrh r1, [r1, #2]\n"
        "    movs r0, #0x20\n"
        ".L080BE9B0:\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080BE9B8\n"
        "    movs r4, #1\n"
        ".L080BE9B8:\n"
        "    cmp r4, #1\n"
        "    bne .L080BE9CC\n"
        "    ldr r1, .L080BE9C8\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080B832C\n"
        "    strh r4, [r5, #0x1c]\n"
        "    b .L080BE9D8\n"
        ".L080BE9C8: .4byte gUnknown_08002EFE\n"
        ".L080BE9CC:\n"
        "    ldr r1, .L080BE9E0\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080B832C\n"
        "    movs r0, #0\n"
        "    strh r0, [r5, #0x1c]\n"
        ".L080BE9D8:\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080BE9E0: .4byte gUnknown_08003192\n"
    );
}
#endif

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
