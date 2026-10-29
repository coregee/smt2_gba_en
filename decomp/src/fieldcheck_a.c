#include "global.h"
#include "field.h"

/* An event record of the current map cell (FieldMap_FindRecord): kind, argument, script
   (or, for kind 0x1F, a key item id in the low half). */
struct FieldRec
{
    u16 kind;
    u16 arg;
    const void *script;
};

extern u16 gUnk_03004534;
extern u32 gUnk_03003B98;
extern u8 *gUnk_03003FEC;
extern const u8 gUnknown_0805A65E[], gUnknown_08073A00[];
s32 KeyItem_IsObtainable(u16 id);
s16 sub_080AF0AC(const void *script);
void sub_080B011C(u16 a);
u32 sub_080C9100(void);
const void *sub_080AF85C(u32 kind, const u32 *ev);
s32 sub_080C2480(u16 id);
void sub_080AF7E8(const u32 *a, const u32 *b, u32 c);
void sub_080AF6F8(u32 a, const u32 *b, u32 c);
void Elevator_Start(void);
void sub_080B5E50(void);
void sub_080B614C(void);
void sub_080B5FD8(void);
void Field_HandleInput(u16 keys);
u8 *sub_080B8FF0(const struct FieldRec *rec, u32 a);
u8 *Treasure_StartTask(const struct FieldRec *rec);
s32 Combatant_GetAlignment(s32 who);

#define FIND(kind) ((const struct FieldRec *)FieldMap_FindRecord(recs, kind))
#define ENTER(rec) sub_080AF6E4(recs, (const u32 *)(rec))
#define MATCHES(script) (sub_080AF0AC(script) == a || sub_080AF0AC(script) == b)

/* Checks the event records of the player's cell (and the event in front, FieldEvent_FindAt)
   in a fixed priority order and starts the first that applies: treasures and key items,
   doors and stairs (states 0xB-0xE, 0x21, 0x22), scripts run through sub_080AF178 /
   sub_080AF1D0 when a and/or b match the script's trigger (sub_080AF0AC), the elevator,
   and so on. c != 0 makes scripts run through sub_080AF1D0. Returns gUnk_03004538 (the
   records of the event started, 0 if none). NONMATCHING: same control flow; gcc's register
   choices differ, so different identical tails get cross-jumped. */
// Field_CheckCellEvents @ 0x080AF8D0
#ifdef NONMATCHING
u32 Field_CheckCellEvents(u16 a, u16 b, u16 c)
{
    u16 flag;
    s32 recs;
    const struct FieldRec *r04, *r15, *r01, *r02, *r1B, *r1C, *r10, *r13, *r1D, *r1E, *r03;
    const struct FieldRec *r09, *r08, *r19, *r05, *r0B, *r0C, *r0D, *r0E, *r0F, *r25, *r26;
    const struct FieldRec *r27, *r14, *r1F, *r16, *r17, *r18, *r1A;
    const u32 *ev;
    const void *script;
    u16 dir;
    u32 none = 0;   /* always 0; the original tests a local like this (movs/cmp) */

    recs = FieldMap_CellRecordsRel(0, 0);
    r04 = FIND(4);
    r15 = FIND(0x15);
    r01 = FIND(1);
    r02 = FIND(2);
    r1B = FIND(0x1B);
    r1C = FIND(0x1C);
    r10 = FIND(0x10);
    r13 = FIND(0x13);
    r1D = FIND(0x1D);
    r1E = FIND(0x1E);
    r03 = FIND(3);
    r09 = FIND(9);
    r08 = FIND(8);
    r19 = FIND(0x19);
    r05 = FIND(5);
    r0B = FIND(0xB);
    r0C = FIND(0xC);
    r0D = FIND(0xD);
    r0E = FIND(0xE);
    r0F = FIND(0xF);
    r25 = FIND(0x25);
    r26 = FIND(0x26);
    r27 = FIND(0x27);
    ev = (const u32 *)FieldEvent_FindAt(gFieldState.unk12, gFieldState.unk14, gFieldState.unk02, &flag);
    r14 = FIND(0x14);
    r1F = FIND(0x1F);
    r16 = FIND(0x16);
    r17 = FIND(0x17);
    r18 = FIND(0x18);
    r1A = FIND(0x1A);
    gUnk_03004538 = 0;
    if (gUnk_03003FF4 != 1)
        goto out;

    if (r1F != NULL && KeyItem_IsObtainable(((const u16 *)r1F)[2]) == 1)
    {
        if (a == 1)
        {
            if (b == 1)
            {
                gUnk_03003FEC = Treasure_StartTask(r1F);
                goto out;
            }
            if (b == 2)
            {
                ENTER(r1F);
                gUnk_03003FEC = Treasure_StartTask(r1F);
                Field_SetState(0x1A);
                goto out;
            }
        }
        if (a == 2 && b == 2)
        {
            ENTER(r1F);
            gFieldState.unk1E = 0;
            Field_SetState(0x20);
            *(u32 *)(gUnk_03003FEC + 0xC) = 1;
        }
    }
    else if (r04 != NULL)
    {
        ENTER(r04);
        Field_SetState(0xB);
        gFieldState.unk1E = 0;
    }
    else if (r15 != NULL)
    {
        ENTER(r15);
        Field_SetState(0xC);
        gFieldState.unk1E = 0;
        gUnk_03004534 = r15->arg;
    }
    else if (r01 != NULL && r01->arg != 0)
    {
        ENTER(r01);
        Field_SetState(0xD);
        gFieldState.unk1E = 0;
        gUnk_03004534 = r01->arg;
        gUnk_03003B98 = 0;
    }
    else if (r1B != NULL && !none && r13 == NULL)
    {
        ENTER(r1B);
        Field_SetState(0x21);
        gFieldState.unk1E = 0;
        gUnk_03004534 = r1B->arg;
        gUnk_03003B98 = 0;
    }
    else if (r02 != NULL)
    {
        if (r02->arg != 0)
        {
            ENTER(r02);
            Field_SetState(0xE);
            gFieldState.unk1E = 0;
            gUnk_03004534 = r02->arg;
            gUnk_03003B98 = 0;
        }
        else
        {
            ENTER(r02);
            sub_080B5FD8();
        }
    }
    else if (r1C != NULL && !none && r13 == NULL)
    {
        ENTER(r1C);
        Field_SetState(0x22);
        gFieldState.unk1E = 0;
        gUnk_03004534 = r1C->arg;
        gUnk_03003B98 = 0;
    }
    else if (r10 != NULL)
    {
        ENTER(r10);
        gFieldState.unk1E = 0;
        sub_080AF178(0xC, gUnknown_0805A65E);
    }
    else if (r13 != NULL)
    {
        if (MATCHES(r13->script))
        {
            ENTER(r13);
            gFieldState.unk1E = 0;
            if (c == 0)
            {
                if (FieldMap_HasRecordRel(0, 0, 0x28) == 1)
                    sub_080AF1D0(0xC, r13->script);
                else
                    sub_080AF178(0xC, r13->script);
            }
            else
                sub_080AF1D0(0xC, r13->script);
            if (r1A != NULL)
                sub_080B011C(r1A->arg);
        }
    }
    else if (r1D != NULL && r1D->arg == 0)
    {
        /* one script per facing direction */
        dir = sub_080B6170();
        if (dir == 0xFFFF)
            dir = gFieldState.unk02;
        script = (&r1D->script)[dir];
        if (script != NULL && MATCHES(script))
        {
            ENTER(r1D);
            gFieldState.unk1E = 0;
            if (c == 0)
                sub_080AF178(0xC, script);
            else
                sub_080AF1D0(0xC, script);
            if (r1A != NULL)
                sub_080B011C(r1A->arg);
        }
    }
    else if (r1E != NULL)
    {
        /* one script per alignment of the hero */
        script = (&r1E->script)[Combatant_GetAlignment(0)];
        if (MATCHES(script))
        {
            ENTER(r1E);
            gFieldState.unk1E = 0;
            if (c == 0)
                sub_080AF178(0xC, script);
            else
                sub_080AF1D0(0xC, script);
        }
    }
    else if (ev != NULL)
    {
        if ((const u8 *)ev[1] == gUnknown_08073A00 && !Palette_IsBg13Black())
        {
            u32 kind = sub_080C9100();

            if (kind != 0)
                sub_080AF85C(kind, ev);
        }
        else if (MATCHES((const void *)ev[1]) && flag != 0xFFFF && sub_080C2480(flag) != 1)
            sub_080AF7E8(ev, ev, 0);
    }
    else if (r16 != NULL && r16->script != NULL)
    {
        if (MATCHES(r16->script))
            sub_080AF6F8(recs, (const u32 *)r16, c);
    }
    else if (r17 != NULL && r17->script != NULL)
    {
        if (MATCHES(r17->script))
            sub_080AF6F8(recs, (const u32 *)r17, c);
    }
    else if (r18 != NULL && r18->script != NULL)
    {
        if (MATCHES(r18->script))
            sub_080AF6F8(recs, (const u32 *)r18, c);
    }
    else if (r03 != NULL)
    {
        ENTER(r03);
        Elevator_Start();
        gUnk_03003B9C = r03->arg;
    }
    else if (r09 != NULL)
    {
        ENTER(r09);
        sub_080B5E50();
    }
    else if (r08 != NULL && (r08->arg == 0 || r08->arg - 1 != gFieldState.unk02))
    {
        ENTER(r08);
        sub_080B614C();
    }
    else if (r19 != NULL)
    {
        if ((u16)(a - 1) <= 1 && b == 2)
        {
            /* walks forward: as if UP were pressed */
            /* the original reads each key field before writing it (volatile) */
            gFieldState.unk3A = 0;
            gFieldState.unk38 = 0x40;
            gFieldState.unk3C = 0;
            Field_HandleInput(gFieldState.unk38);
            ENTER(r19);
        }
    }
    else if (r05 != NULL)
    {
        if (BattleFlags_Get() & 0x50)
            goto out;
        if (a == 1)
        {
            if (b == 2)
            {
                ENTER(r05);
                sub_080B8FF0(r05, 0);
                Field_SetState(0x20);
                goto out;
            }
            if (b == 1)
            {
                gUnk_03003FEC = sub_080B8FF0(r05, 1);
                goto out;
            }
        }
        if (a == 2 && b == 2)
        {
            ENTER(r05);
            gFieldState.unk1E = 0;
            Field_SetState(0x20);
            *(u32 *)(gUnk_03003FEC + 0xC) = 1;
        }
    }
    else if (r0B != NULL)
    {
        ENTER(r0B);
        gFieldState.unk1E = 0;
        sub_080AF178(0xC, r0B->script);
    }
    else if (r0C != NULL)
    {
        if (r0C->script != NULL)
        {
            ENTER(r0C);
            gFieldState.unk1E = 0;
            sub_080AF178(0xC, r0C->script);
        }
    }
    else if (r0D != NULL)
    {
        ENTER(r0D);
        gFieldState.unk1E = 0;
        sub_080AF178(0xC, r0D->script);
    }
    else if (r0E != NULL)
    {
        ENTER(r0E);
        gFieldState.unk1E = 0;
        sub_080AF178(0xC, r0E->script);
    }
    else if (r0F != NULL)
    {
        ENTER(r0F);
        gFieldState.unk1E = 0;
        sub_080AF178(0xC, r0F->script);
    }
    else if (r25 != NULL)
    {
        ENTER(r25);
        gFieldState.unk1E = 0;
        sub_080AF178(0xC, r25->script);
    }
    else if (r26 != NULL)
    {
        ENTER(r26);
        gFieldState.unk1E = 0;
        sub_080AF178(0xC, r26->script);
    }
    else if (r27 != NULL)
    {
        ENTER(r27);
        gFieldState.unk1E = 0;
        sub_080AF178(0xC, r27->script);
    }
    else if (r14 != NULL)
    {
        if (a == 1 && b == 1)
            gUnk_03003FEC = Treasure_StartTask(r14);
        else if (a == 2 && b == 2)
        {
            ENTER(r14);
            gFieldState.unk1E = 0;
            Field_SetState(0x20);
            *(u32 *)(gUnk_03003FEC + 0xC) = 1;
        }
        else if (a == 1 && b == 2)
        {
            ENTER(r14);
            gUnk_03003FEC = Treasure_StartTask(r14);
            Field_SetState(0x1A);
        }
    }
    else if (r1A != NULL)
    {
        sub_080B011C(r1A->arg);
        gUnk_03004538 = 0;
    }
out:
    return gUnk_03004538;
}
#else
NAKED
u32 Field_CheckCellEvents(u16 a, u16 b, u16 c)
{
    asm_unified(
        ".L080AF8D0:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x70\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    mov sb, r1\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    str r2, [sp, #4]\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    bl FieldMap_CellRecordsRel\n"
        "    adds r4, r0, #0\n"
        "    movs r1, #4\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #8]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0x15\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0xc]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #1\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x10]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #2\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x14]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0x1b\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x18]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0x1c\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x1c]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0x10\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x20]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0x13\n"
        "    bl FieldMap_FindRecord\n"
        "    adds r6, r0, #0\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0x1d\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x24]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0x1e\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x28]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #3\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x2c]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #9\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x30]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #8\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x34]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0x19\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x38]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #5\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x3c]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0xb\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x40]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0xc\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x44]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0xd\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x48]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0xe\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x4c]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0xf\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x50]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0x25\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x54]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0x26\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x58]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0x27\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x5c]\n"
        "    ldr r2, .L080AFA58\n"
        "    ldrh r0, [r2, #0x12]\n"
        "    ldrh r1, [r2, #0x14]\n"
        "    ldrh r2, [r2, #2]\n"
        "    mov r3, sp\n"
        "    bl FieldEvent_FindAt\n"
        "    adds r7, r0, #0\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0x14\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x60]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0x1f\n"
        "    bl FieldMap_FindRecord\n"
        "    adds r5, r0, #0\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0x16\n"
        "    bl FieldMap_FindRecord\n"
        "    mov sl, r0\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0x17\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x64]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0x18\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x68]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0x1a\n"
        "    bl FieldMap_FindRecord\n"
        "    str r0, [sp, #0x6c]\n"
        "    ldr r0, .L080AFA5C\n"
        "    movs r1, #0\n"
        "    str r1, [r0]\n"
        "    ldr r0, .L080AFA60\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #1\n"
        "    beq .L080AFA38\n"
        "    b .L080B0102\n"
        ".L080AFA38:\n"
        "    cmp r5, #0\n"
        "    beq .L080AFA8C\n"
        "    ldrh r0, [r5, #4]\n"
        "    bl KeyItem_IsObtainable\n"
        "    cmp r0, #1\n"
        "    bne .L080AFA8C\n"
        "    mov r2, r8\n"
        "    cmp r2, #1\n"
        "    bne .L080AFA76\n"
        "    mov r3, sb\n"
        "    cmp r3, #1\n"
        "    bne .L080AFA64\n"
        "    adds r0, r5, #0\n"
        "    b .L080B0080\n"
        "    .byte 0x00, 0x00\n"
        ".L080AFA58: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080AFA5C: .4byte 0x03004538 @ IWRAM+0x4538\n"
        ".L080AFA60: .4byte 0x03003FF4 @ IWRAM+0x3FF4\n"
        ".L080AFA64:\n"
        "    mov r0, sb\n"
        "    cmp r0, #2\n"
        "    bne .L080AFA76\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r5, #0\n"
        "    bl sub_080AF6E4\n"
        "    adds r0, r5, #0\n"
        "    b .L080B00DA\n"
        ".L080AFA76:\n"
        "    mov r1, r8\n"
        "    cmp r1, #2\n"
        "    beq .L080AFA7E\n"
        "    b .L080B0102\n"
        ".L080AFA7E:\n"
        "    mov r2, sb\n"
        "    cmp r2, #2\n"
        "    beq .L080AFA86\n"
        "    b .L080B0102\n"
        ".L080AFA86:\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r5, #0\n"
        "    b .L080B00A0\n"
        ".L080AFA8C:\n"
        "    ldr r3, [sp, #8]\n"
        "    cmp r3, #0\n"
        "    beq .L080AFAAC\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r3, #0\n"
        "    bl sub_080AF6E4\n"
        "    movs r0, #0xb\n"
        "    bl Field_SetState\n"
        "    ldr r1, .L080AFAA8\n"
        "    movs r0, #0\n"
        "    strh r0, [r1, #0x1e]\n"
        "    b .L080B0102\n"
        ".L080AFAA8: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080AFAAC:\n"
        "    ldr r0, [sp, #0xc]\n"
        "    cmp r0, #0\n"
        "    beq .L080AFAD8\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, [sp, #0xc]\n"
        "    bl sub_080AF6E4\n"
        "    movs r0, #0xc\n"
        "    bl Field_SetState\n"
        "    ldr r0, .L080AFAD0\n"
        "    mov r1, sp\n"
        "    ldrh r1, [r1, #8]\n"
        "    strh r1, [r0, #0x1e]\n"
        "    ldr r1, .L080AFAD4\n"
        "    ldr r2, [sp, #0xc]\n"
        "    b .L080AFE6C\n"
        "    .byte 0x00, 0x00\n"
        ".L080AFAD0: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080AFAD4: .4byte 0x03004534 @ IWRAM+0x4534\n"
        ".L080AFAD8:\n"
        "    ldr r3, [sp, #0x10]\n"
        "    cmp r3, #0\n"
        "    beq .L080AFB14\n"
        "    ldrh r0, [r3, #2]\n"
        "    cmp r0, #0\n"
        "    beq .L080AFB14\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r3, #0\n"
        "    bl sub_080AF6E4\n"
        "    movs r0, #0xd\n"
        "    bl Field_SetState\n"
        "    ldr r0, .L080AFB08\n"
        "    mov r1, sp\n"
        "    ldrh r1, [r1, #0xc]\n"
        "    strh r1, [r0, #0x1e]\n"
        "    ldr r1, .L080AFB0C\n"
        "    ldr r2, [sp, #0x10]\n"
        "    ldrh r0, [r2, #2]\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L080AFB10\n"
        "    ldr r3, [sp, #0xc]\n"
        "    b .L080B0100\n"
        ".L080AFB08: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080AFB0C: .4byte 0x03004534 @ IWRAM+0x4534\n"
        ".L080AFB10: .4byte 0x03003B98 @ IWRAM+0x3B98\n"
        ".L080AFB14:\n"
        "    ldr r0, [sp, #0x18]\n"
        "    cmp r0, #0\n"
        "    beq .L080AFB44\n"
        "    movs r1, #0\n"
        "    cmp r1, #0\n"
        "    bne .L080AFB44\n"
        "    cmp r6, #0\n"
        "    bne .L080AFB44\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, [sp, #0x18]\n"
        "    bl sub_080AF6E4\n"
        "    movs r0, #0x21\n"
        "    bl Field_SetState\n"
        "    ldr r0, .L080AFB3C\n"
        "    strh r6, [r0, #0x1e]\n"
        "    ldr r1, .L080AFB40\n"
        "    ldr r2, [sp, #0x18]\n"
        "    b .L080AFBB4\n"
        ".L080AFB3C: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080AFB40: .4byte 0x03004534 @ IWRAM+0x4534\n"
        ".L080AFB44:\n"
        "    ldr r3, [sp, #0x14]\n"
        "    cmp r3, #0\n"
        "    beq .L080AFB8E\n"
        "    ldrh r0, [r3, #2]\n"
        "    cmp r0, #0\n"
        "    beq .L080AFB80\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r3, #0\n"
        "    bl sub_080AF6E4\n"
        "    movs r0, #0xe\n"
        "    bl Field_SetState\n"
        "    ldr r0, .L080AFB74\n"
        "    movs r2, #0\n"
        "    strh r2, [r0, #0x1e]\n"
        "    ldr r1, .L080AFB78\n"
        "    ldr r3, [sp, #0x14]\n"
        "    ldrh r0, [r3, #2]\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L080AFB7C\n"
        "    str r2, [r0]\n"
        "    b .L080B0102\n"
        "    .byte 0x00, 0x00\n"
        ".L080AFB74: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080AFB78: .4byte 0x03004534 @ IWRAM+0x4534\n"
        ".L080AFB7C: .4byte 0x03003B98 @ IWRAM+0x3B98\n"
        ".L080AFB80:\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, [sp, #0x14]\n"
        "    bl sub_080AF6E4\n"
        "    bl sub_080B5FD8\n"
        "    b .L080B0102\n"
        ".L080AFB8E:\n"
        "    ldr r0, [sp, #0x1c]\n"
        "    cmp r0, #0\n"
        "    beq .L080AFBCC\n"
        "    movs r1, #0\n"
        "    cmp r1, #0\n"
        "    bne .L080AFBCC\n"
        "    cmp r6, #0\n"
        "    bne .L080AFBCC\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, [sp, #0x1c]\n"
        "    bl sub_080AF6E4\n"
        "    movs r0, #0x22\n"
        "    bl Field_SetState\n"
        "    ldr r0, .L080AFBC0\n"
        "    strh r6, [r0, #0x1e]\n"
        "    ldr r1, .L080AFBC4\n"
        "    ldr r2, [sp, #0x1c]\n"
        ".L080AFBB4:\n"
        "    ldrh r0, [r2, #2]\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L080AFBC8\n"
        "    str r6, [r0]\n"
        "    b .L080B0102\n"
        "    .byte 0x00, 0x00\n"
        ".L080AFBC0: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080AFBC4: .4byte 0x03004534 @ IWRAM+0x4534\n"
        ".L080AFBC8: .4byte 0x03003B98 @ IWRAM+0x3B98\n"
        ".L080AFBCC:\n"
        "    ldr r3, [sp, #0x20]\n"
        "    cmp r3, #0\n"
        "    beq .L080AFBEC\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r3, #0\n"
        "    bl sub_080AF6E4\n"
        "    ldr r0, .L080AFBE4\n"
        "    movs r1, #0\n"
        "    strh r1, [r0, #0x1e]\n"
        "    ldr r1, .L080AFBE8\n"
        "    b .L080B005E\n"
        ".L080AFBE4: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080AFBE8: .4byte gUnknown_0805A65E\n"
        ".L080AFBEC:\n"
        "    cmp r6, #0\n"
        "    beq .L080AFC62\n"
        "    ldr r0, [r6, #4]\n"
        "    bl sub_080AF0AC\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, r8\n"
        "    beq .L080AFC0E\n"
        "    ldr r0, [r6, #4]\n"
        "    bl sub_080AF0AC\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, sb\n"
        "    beq .L080AFC0E\n"
        "    b .L080B0102\n"
        ".L080AFC0E:\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r6, #0\n"
        "    bl sub_080AF6E4\n"
        "    ldr r0, .L080AFC3C\n"
        "    mov r1, sp\n"
        "    ldrh r1, [r1, #0x20]\n"
        "    strh r1, [r0, #0x1e]\n"
        "    ldr r2, [sp, #4]\n"
        "    cmp r2, #0\n"
        "    bne .L080AFC4A\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #0x28\n"
        "    bl FieldMap_HasRecordRel\n"
        "    cmp r0, #1\n"
        "    bne .L080AFC40\n"
        "    ldr r1, [r6, #4]\n"
        "    movs r0, #0xc\n"
        "    bl sub_080AF1D0\n"
        "    b .L080AFC52\n"
        ".L080AFC3C: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080AFC40:\n"
        "    ldr r1, [r6, #4]\n"
        "    movs r0, #0xc\n"
        "    bl sub_080AF178\n"
        "    b .L080AFC52\n"
        ".L080AFC4A:\n"
        "    ldr r1, [r6, #4]\n"
        "    movs r0, #0xc\n"
        "    bl sub_080AF1D0\n"
        ".L080AFC52:\n"
        "    ldr r3, [sp, #0x6c]\n"
        "    cmp r3, #0\n"
        "    bne .L080AFC5A\n"
        "    b .L080B0102\n"
        ".L080AFC5A:\n"
        "    ldrh r0, [r3, #2]\n"
        "    bl sub_080B011C\n"
        "    b .L080B0102\n"
        ".L080AFC62:\n"
        "    ldr r0, [sp, #0x24]\n"
        "    cmp r0, #0\n"
        "    beq .L080AFCEC\n"
        "    ldrh r6, [r0, #2]\n"
        "    cmp r6, #0\n"
        "    bne .L080AFCEC\n"
        "    bl sub_080B6170\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    ldr r0, .L080AFCCC\n"
        "    cmp r1, r0\n"
        "    bne .L080AFC80\n"
        "    ldr r0, .L080AFCD0\n"
        "    ldrh r1, [r0, #2]\n"
        ".L080AFC80:\n"
        "    lsls r1, r1, #2\n"
        "    ldr r0, [sp, #0x24]\n"
        "    adds r0, #4\n"
        "    adds r0, r0, r1\n"
        "    ldr r5, [r0]\n"
        "    cmp r5, #0\n"
        "    bne .L080AFC90\n"
        "    b .L080B0102\n"
        ".L080AFC90:\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080AF0AC\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, r8\n"
        "    beq .L080AFCAE\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080AF0AC\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, sb\n"
        "    beq .L080AFCAE\n"
        "    b .L080B0102\n"
        ".L080AFCAE:\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, [sp, #0x24]\n"
        "    bl sub_080AF6E4\n"
        "    ldr r0, .L080AFCD0\n"
        "    strh r6, [r0, #0x1e]\n"
        "    ldr r1, [sp, #4]\n"
        "    cmp r1, #0\n"
        "    bne .L080AFCD4\n"
        "    movs r0, #0xc\n"
        "    adds r1, r5, #0\n"
        "    bl sub_080AF178\n"
        "    b .L080AFCDC\n"
        "    .byte 0x00, 0x00\n"
        ".L080AFCCC: .4byte 0x0000FFFF\n"
        ".L080AFCD0: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080AFCD4:\n"
        "    movs r0, #0xc\n"
        "    adds r1, r5, #0\n"
        "    bl sub_080AF1D0\n"
        ".L080AFCDC:\n"
        "    ldr r2, [sp, #0x6c]\n"
        "    cmp r2, #0\n"
        "    bne .L080AFCE4\n"
        "    b .L080B0102\n"
        ".L080AFCE4:\n"
        "    ldrh r0, [r2, #2]\n"
        "    bl sub_080B011C\n"
        "    b .L080B0102\n"
        ".L080AFCEC:\n"
        "    ldr r3, [sp, #0x28]\n"
        "    cmp r3, #0\n"
        "    beq .L080AFD4E\n"
        "    movs r0, #0\n"
        "    bl Combatant_GetAlignment\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, [sp, #0x28]\n"
        "    adds r1, #4\n"
        "    adds r1, r1, r0\n"
        "    ldr r5, [r1]\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080AF0AC\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, r8\n"
        "    beq .L080AFD20\n"
        "    adds r0, r5, #0\n"
        "    bl sub_080AF0AC\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, sb\n"
        "    beq .L080AFD20\n"
        "    b .L080B0102\n"
        ".L080AFD20:\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, [sp, #0x28]\n"
        "    bl sub_080AF6E4\n"
        "    ldr r1, .L080AFD40\n"
        "    movs r0, #0\n"
        "    strh r0, [r1, #0x1e]\n"
        "    ldr r0, [sp, #4]\n"
        "    cmp r0, #0\n"
        "    bne .L080AFD44\n"
        "    movs r0, #0xc\n"
        "    adds r1, r5, #0\n"
        "    bl sub_080AF178\n"
        "    b .L080B0102\n"
        "    .byte 0x00, 0x00\n"
        ".L080AFD40: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080AFD44:\n"
        "    movs r0, #0xc\n"
        "    adds r1, r5, #0\n"
        "    bl sub_080AF1D0\n"
        "    b .L080B0102\n"
        ".L080AFD4E:\n"
        "    cmp r7, #0\n"
        "    beq .L080AFDC0\n"
        "    ldr r1, [r7, #4]\n"
        "    ldr r0, .L080AFD74\n"
        "    cmp r1, r0\n"
        "    bne .L080AFD78\n"
        "    bl Palette_IsBg13Black\n"
        "    cmp r0, #0\n"
        "    bne .L080AFD78\n"
        "    bl sub_080C9100\n"
        "    cmp r0, #0\n"
        "    bne .L080AFD6C\n"
        "    b .L080B0102\n"
        ".L080AFD6C:\n"
        "    adds r1, r7, #0\n"
        "    bl sub_080AF85C\n"
        "    b .L080B0102\n"
        ".L080AFD74: .4byte gUnknown_08073A00\n"
        ".L080AFD78:\n"
        "    ldr r0, [r7, #4]\n"
        "    bl sub_080AF0AC\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, r8\n"
        "    beq .L080AFD96\n"
        "    ldr r0, [r7, #4]\n"
        "    bl sub_080AF0AC\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, sb\n"
        "    beq .L080AFD96\n"
        "    b .L080B0102\n"
        ".L080AFD96:\n"
        "    mov r0, sp\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L080AFDBC\n"
        "    cmp r1, r0\n"
        "    bne .L080AFDA2\n"
        "    b .L080B0102\n"
        ".L080AFDA2:\n"
        "    mov r0, sp\n"
        "    ldrh r0, [r0]\n"
        "    bl sub_080C2480\n"
        "    cmp r0, #1\n"
        "    bne .L080AFDB0\n"
        "    b .L080B0102\n"
        ".L080AFDB0:\n"
        "    adds r0, r7, #0\n"
        "    adds r1, r7, #0\n"
        "    movs r2, #0\n"
        "    bl sub_080AF7E8\n"
        "    b .L080B0102\n"
        ".L080AFDBC: .4byte 0x0000FFFF\n"
        ".L080AFDC0:\n"
        "    mov r1, sl\n"
        "    cmp r1, #0\n"
        "    beq .L080AFDF0\n"
        "    ldr r0, [r1, #4]\n"
        "    cmp r0, #0\n"
        "    beq .L080AFDF0\n"
        "    bl sub_080AF0AC\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, r8\n"
        "    beq .L080AFDEA\n"
        "    mov r2, sl\n"
        "    ldr r0, [r2, #4]\n"
        "    bl sub_080AF0AC\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, sb\n"
        "    beq .L080AFDEA\n"
        "    b .L080B0102\n"
        ".L080AFDEA:\n"
        "    adds r0, r4, #0\n"
        "    mov r1, sl\n"
        "    b .L080AFE4E\n"
        ".L080AFDF0:\n"
        "    ldr r3, [sp, #0x64]\n"
        "    cmp r3, #0\n"
        "    beq .L080AFE20\n"
        "    ldr r0, [r3, #4]\n"
        "    cmp r0, #0\n"
        "    beq .L080AFE20\n"
        "    bl sub_080AF0AC\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, r8\n"
        "    beq .L080AFE1A\n"
        "    ldr r1, [sp, #0x64]\n"
        "    ldr r0, [r1, #4]\n"
        "    bl sub_080AF0AC\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, sb\n"
        "    beq .L080AFE1A\n"
        "    b .L080B0102\n"
        ".L080AFE1A:\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, [sp, #0x64]\n"
        "    b .L080AFE4E\n"
        ".L080AFE20:\n"
        "    ldr r2, [sp, #0x68]\n"
        "    cmp r2, #0\n"
        "    beq .L080AFE56\n"
        "    ldr r0, [r2, #4]\n"
        "    cmp r0, #0\n"
        "    beq .L080AFE56\n"
        "    bl sub_080AF0AC\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, r8\n"
        "    beq .L080AFE4A\n"
        "    ldr r3, [sp, #0x68]\n"
        "    ldr r0, [r3, #4]\n"
        "    bl sub_080AF0AC\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, sb\n"
        "    beq .L080AFE4A\n"
        "    b .L080B0102\n"
        ".L080AFE4A:\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, [sp, #0x68]\n"
        ".L080AFE4E:\n"
        "    ldr r2, [sp, #4]\n"
        "    bl sub_080AF6F8\n"
        "    b .L080B0102\n"
        ".L080AFE56:\n"
        "    ldr r0, [sp, #0x2c]\n"
        "    cmp r0, #0\n"
        "    beq .L080AFE78\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, [sp, #0x2c]\n"
        "    bl sub_080AF6E4\n"
        "    bl Elevator_Start\n"
        "    ldr r1, .L080AFE74\n"
        "    ldr r2, [sp, #0x2c]\n"
        ".L080AFE6C:\n"
        "    ldrh r0, [r2, #2]\n"
        "    strh r0, [r1]\n"
        "    b .L080B0102\n"
        "    .byte 0x00, 0x00\n"
        ".L080AFE74: .4byte 0x03003B9C @ IWRAM+0x3B9C\n"
        ".L080AFE78:\n"
        "    ldr r3, [sp, #0x30]\n"
        "    cmp r3, #0\n"
        "    beq .L080AFE8C\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r3, #0\n"
        "    bl sub_080AF6E4\n"
        "    bl sub_080B5E50\n"
        "    b .L080B0102\n"
        ".L080AFE8C:\n"
        "    ldr r0, [sp, #0x34]\n"
        "    cmp r0, #0\n"
        "    beq .L080AFEB8\n"
        "    ldrh r0, [r0, #2]\n"
        "    cmp r0, #0\n"
        "    beq .L080AFEA6\n"
        "    ldr r1, [sp, #0x34]\n"
        "    ldrh r0, [r1, #2]\n"
        "    subs r0, #1\n"
        "    ldr r1, .L080AFEB4\n"
        "    ldrh r1, [r1, #2]\n"
        "    cmp r0, r1\n"
        "    beq .L080AFEB8\n"
        ".L080AFEA6:\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, [sp, #0x34]\n"
        "    bl sub_080AF6E4\n"
        "    bl sub_080B614C\n"
        "    b .L080B0102\n"
        ".L080AFEB4: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080AFEB8:\n"
        "    ldr r2, [sp, #0x38]\n"
        "    cmp r2, #0\n"
        "    beq .L080AFEFC\n"
        "    mov r0, r8\n"
        "    subs r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bls .L080AFECC\n"
        "    b .L080B0102\n"
        ".L080AFECC:\n"
        "    mov r3, sb\n"
        "    cmp r3, #2\n"
        "    beq .L080AFED4\n"
        "    b .L080B0102\n"
        ".L080AFED4:\n"
        "    ldr r0, .L080AFEF8\n"
        "    ldrh r1, [r0, #0x3a]\n"
        "    movs r2, #0\n"
        "    strh r2, [r0, #0x3a]\n"
        "    ldrh r1, [r0, #0x38]\n"
        "    movs r1, #0x40\n"
        "    strh r1, [r0, #0x38]\n"
        "    ldrh r1, [r0, #0x3c]\n"
        "    strh r2, [r0, #0x3c]\n"
        "    ldrh r0, [r0, #0x38]\n"
        "    bl Field_HandleInput\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, [sp, #0x38]\n"
        "    bl sub_080AF6E4\n"
        "    b .L080B0102\n"
        "    .byte 0x00, 0x00\n"
        ".L080AFEF8: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080AFEFC:\n"
        "    ldr r0, [sp, #0x3c]\n"
        "    cmp r0, #0\n"
        "    beq .L080AFF5A\n"
        "    bl BattleFlags_Get\n"
        "    movs r1, #0x50\n"
        "    ands r1, r0\n"
        "    cmp r1, #0\n"
        "    beq .L080AFF10\n"
        "    b .L080B0102\n"
        ".L080AFF10:\n"
        "    mov r1, r8\n"
        "    cmp r1, #1\n"
        "    bne .L080AFF44\n"
        "    mov r2, sb\n"
        "    cmp r2, #2\n"
        "    bne .L080AFF34\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, [sp, #0x3c]\n"
        "    bl sub_080AF6E4\n"
        "    ldr r0, [sp, #0x3c]\n"
        "    movs r1, #0\n"
        "    bl sub_080B8FF0\n"
        "    movs r0, #0x20\n"
        "    bl Field_SetState\n"
        "    b .L080B0102\n"
        ".L080AFF34:\n"
        "    mov r3, sb\n"
        "    cmp r3, #1\n"
        "    bne .L080AFF44\n"
        "    ldr r0, [sp, #0x3c]\n"
        "    movs r1, #1\n"
        "    bl sub_080B8FF0\n"
        "    b .L080B0084\n"
        ".L080AFF44:\n"
        "    mov r0, r8\n"
        "    cmp r0, #2\n"
        "    beq .L080AFF4C\n"
        "    b .L080B0102\n"
        ".L080AFF4C:\n"
        "    mov r1, sb\n"
        "    cmp r1, #2\n"
        "    beq .L080AFF54\n"
        "    b .L080B0102\n"
        ".L080AFF54:\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, [sp, #0x3c]\n"
        "    b .L080B00A0\n"
        ".L080AFF5A:\n"
        "    ldr r2, [sp, #0x40]\n"
        "    cmp r2, #0\n"
        "    beq .L080AFF7C\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r2, #0\n"
        "    bl sub_080AF6E4\n"
        "    ldr r0, .L080AFF78\n"
        "    mov r3, sp\n"
        "    ldrh r3, [r3, #0x3c]\n"
        "    strh r3, [r0, #0x1e]\n"
        "    ldr r0, [sp, #0x40]\n"
        "    ldr r1, [r0, #4]\n"
        "    b .L080B005E\n"
        "    .byte 0x00, 0x00\n"
        ".L080AFF78: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080AFF7C:\n"
        "    ldr r1, [sp, #0x44]\n"
        "    cmp r1, #0\n"
        "    beq .L080AFFA4\n"
        "    ldr r0, [r1, #4]\n"
        "    cmp r0, #0\n"
        "    bne .L080AFF8A\n"
        "    b .L080B0102\n"
        ".L080AFF8A:\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080AF6E4\n"
        "    ldr r0, .L080AFFA0\n"
        "    add r2, sp, #0x40\n"
        "    ldrh r2, [r2]\n"
        "    strh r2, [r0, #0x1e]\n"
        "    ldr r3, [sp, #0x44]\n"
        "    ldr r1, [r3, #4]\n"
        "    b .L080B005E\n"
        "    .byte 0x00, 0x00\n"
        ".L080AFFA0: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080AFFA4:\n"
        "    ldr r0, [sp, #0x48]\n"
        "    cmp r0, #0\n"
        "    beq .L080AFFC4\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, [sp, #0x48]\n"
        "    bl sub_080AF6E4\n"
        "    ldr r0, .L080AFFC0\n"
        "    add r1, sp, #0x44\n"
        "    ldrh r1, [r1]\n"
        "    strh r1, [r0, #0x1e]\n"
        "    ldr r2, [sp, #0x48]\n"
        "    b .L080B005C\n"
        "    .byte 0x00, 0x00\n"
        ".L080AFFC0: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080AFFC4:\n"
        "    ldr r3, [sp, #0x4c]\n"
        "    cmp r3, #0\n"
        "    beq .L080AFFE4\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r3, #0\n"
        "    bl sub_080AF6E4\n"
        "    ldr r0, .L080AFFE0\n"
        "    add r1, sp, #0x48\n"
        "    ldrh r1, [r1]\n"
        "    strh r1, [r0, #0x1e]\n"
        "    ldr r2, [sp, #0x4c]\n"
        "    b .L080B005C\n"
        "    .byte 0x00, 0x00\n"
        ".L080AFFE0: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080AFFE4:\n"
        "    ldr r3, [sp, #0x50]\n"
        "    cmp r3, #0\n"
        "    beq .L080B0004\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r3, #0\n"
        "    bl sub_080AF6E4\n"
        "    ldr r0, .L080B0000\n"
        "    add r1, sp, #0x4c\n"
        "    ldrh r1, [r1]\n"
        "    strh r1, [r0, #0x1e]\n"
        "    ldr r2, [sp, #0x50]\n"
        "    b .L080B005C\n"
        "    .byte 0x00, 0x00\n"
        ".L080B0000: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B0004:\n"
        "    ldr r3, [sp, #0x54]\n"
        "    cmp r3, #0\n"
        "    beq .L080B0024\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r3, #0\n"
        "    bl sub_080AF6E4\n"
        "    ldr r0, .L080B0020\n"
        "    add r1, sp, #0x50\n"
        "    ldrh r1, [r1]\n"
        "    strh r1, [r0, #0x1e]\n"
        "    ldr r2, [sp, #0x54]\n"
        "    b .L080B005C\n"
        "    .byte 0x00, 0x00\n"
        ".L080B0020: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B0024:\n"
        "    ldr r3, [sp, #0x58]\n"
        "    cmp r3, #0\n"
        "    beq .L080B0044\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r3, #0\n"
        "    bl sub_080AF6E4\n"
        "    ldr r0, .L080B0040\n"
        "    add r1, sp, #0x54\n"
        "    ldrh r1, [r1]\n"
        "    strh r1, [r0, #0x1e]\n"
        "    ldr r2, [sp, #0x58]\n"
        "    b .L080B005C\n"
        "    .byte 0x00, 0x00\n"
        ".L080B0040: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B0044:\n"
        "    ldr r3, [sp, #0x5c]\n"
        "    cmp r3, #0\n"
        "    beq .L080B006C\n"
        "    adds r0, r4, #0\n"
        "    adds r1, r3, #0\n"
        "    bl sub_080AF6E4\n"
        "    ldr r0, .L080B0068\n"
        "    add r1, sp, #0x58\n"
        "    ldrh r1, [r1]\n"
        "    strh r1, [r0, #0x1e]\n"
        "    ldr r2, [sp, #0x5c]\n"
        ".L080B005C:\n"
        "    ldr r1, [r2, #4]\n"
        ".L080B005E:\n"
        "    movs r0, #0xc\n"
        "    bl sub_080AF178\n"
        "    b .L080B0102\n"
        "    .byte 0x00, 0x00\n"
        ".L080B0068: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B006C:\n"
        "    ldr r3, [sp, #0x60]\n"
        "    cmp r3, #0\n"
        "    beq .L080B00F0\n"
        "    mov r0, r8\n"
        "    cmp r0, #1\n"
        "    bne .L080B0090\n"
        "    mov r1, sb\n"
        "    cmp r1, #1\n"
        "    bne .L080B0090\n"
        "    adds r0, r3, #0\n"
        ".L080B0080:\n"
        "    bl Treasure_StartTask\n"
        ".L080B0084:\n"
        "    ldr r1, .L080B008C\n"
        "    str r0, [r1]\n"
        "    b .L080B0102\n"
        "    .byte 0x00, 0x00\n"
        ".L080B008C: .4byte 0x03003FEC @ IWRAM+0x3FEC\n"
        ".L080B0090:\n"
        "    mov r2, r8\n"
        "    cmp r2, #2\n"
        "    bne .L080B00C4\n"
        "    mov r3, sb\n"
        "    cmp r3, #2\n"
        "    bne .L080B00C4\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, [sp, #0x60]\n"
        ".L080B00A0:\n"
        "    bl sub_080AF6E4\n"
        "    ldr r1, .L080B00BC\n"
        "    movs r0, #0\n"
        "    strh r0, [r1, #0x1e]\n"
        "    movs r0, #0x20\n"
        "    bl Field_SetState\n"
        "    ldr r0, .L080B00C0\n"
        "    ldr r1, [r0]\n"
        "    movs r0, #1\n"
        "    str r0, [r1, #0xc]\n"
        "    b .L080B0102\n"
        "    .byte 0x00, 0x00\n"
        ".L080B00BC: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B00C0: .4byte 0x03003FEC @ IWRAM+0x3FEC\n"
        ".L080B00C4:\n"
        "    mov r0, r8\n"
        "    cmp r0, #1\n"
        "    bne .L080B0102\n"
        "    mov r1, sb\n"
        "    cmp r1, #2\n"
        "    bne .L080B0102\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, [sp, #0x60]\n"
        "    bl sub_080AF6E4\n"
        "    ldr r0, [sp, #0x60]\n"
        ".L080B00DA:\n"
        "    bl Treasure_StartTask\n"
        "    ldr r1, .L080B00EC\n"
        "    str r0, [r1]\n"
        "    movs r0, #0x1a\n"
        "    bl Field_SetState\n"
        "    b .L080B0102\n"
        "    .byte 0x00, 0x00\n"
        ".L080B00EC: .4byte 0x03003FEC @ IWRAM+0x3FEC\n"
        ".L080B00F0:\n"
        "    ldr r2, [sp, #0x6c]\n"
        "    cmp r2, #0\n"
        "    beq .L080B0102\n"
        "    ldrh r0, [r2, #2]\n"
        "    bl sub_080B011C\n"
        "    ldr r0, .L080B0118\n"
        "    ldr r3, [sp, #0x60]\n"
        ".L080B0100:\n"
        "    str r3, [r0]\n"
        ".L080B0102:\n"
        "    ldr r0, .L080B0118\n"
        "    ldr r0, [r0]\n"
        "    add sp, #0x70\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
        ".L080B0118: .4byte 0x03004538 @ IWRAM+0x4538\n"
    );
}
#endif
