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
   records of the event started, 0 if none). */
// Field_CheckCellEvents @ 0x080AF8D0
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
        {
            u32 k = dir * 4;
            const void *const *s = &r1D->script;
            script = *(const void **)((u32)s + k);
        }
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
        {
            u32 k = Combatant_GetAlignment(0) * 4;
            const void *const *s = &r1E->script;
            script = *(const void **)((u32)s + k);
        }
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
            /* walks forward: as if UP were pressed. Written through a volatile pointer: agbcc
               then reads each key field before storing it, as the original does. */
            {
                volatile struct FieldState *fs = &gFieldState;

                fs->unk3A = 0;
                fs->unk38 = 0x40;
                fs->unk3C = 0;
                Field_HandleInput(fs->unk38);
            }
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
