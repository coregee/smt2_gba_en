/* Task ops 14..24 (second half of gTaskOpTable): calls, a compare register, onFrame,
   spawning tasks, sound. */

#include "global.h"
#include "field.h"

// sub_080AD444 @ 0x080AD444
void sub_080AD444(struct Task *task)
{
}

/* Op 15: call func(task, 5 args). */
// TaskOp_Call5 @ 0x080AD448
void TaskOp_Call5(struct Task *task)
{
    void (*func)(struct Task *, u32, u32, u32, u32, u32) = (void *)*gTaskOpArgs++;

    task->pc += 6;
    func(task, gTaskOpArgs[0], gTaskOpArgs[1], gTaskOpArgs[2], gTaskOpArgs[3], gTaskOpArgs[4]);
}

// sub_080AD478 @ 0x080AD478
void sub_080AD478(struct Task *task)
{
}

/* Op 16: call func(task, 6 args). */
// TaskOp_Call6 @ 0x080AD47C
void TaskOp_Call6(struct Task *task)
{
    void (*func)(struct Task *, u32, u32, u32, u32, u32, u32) = (void *)*gTaskOpArgs++;

    task->pc += 7;
    func(task, gTaskOpArgs[0], gTaskOpArgs[1], gTaskOpArgs[2], gTaskOpArgs[3], gTaskOpArgs[4], gTaskOpArgs[5]);
}

// sub_080AD4B0 @ 0x080AD4B0
void sub_080AD4B0(struct Task *task)
{
}

/* Op 17: unk1E = arg. */
// TaskOp_SetCompareValue @ 0x080AD4B4
void TaskOp_SetCompareValue(struct Task *task)
{
    task->unk1E = *gTaskOpArgs++;
    task->pc++;
}

// sub_080AD4CC @ 0x080AD4CC
void sub_080AD4CC(struct Task *task)
{
}

/* Op 18 "compare unk1E and goto": cmp (0 ==, 1 !=, 2 >=, 3 <), value, label. */
// TaskOp_CompareGoto @ 0x080AD4D0
void TaskOp_CompareGoto(struct Task *task)
{
    u32 cmp = *gTaskOpArgs++;
    const u32 *args = gTaskOpArgs;
    u32 value = *gTaskOpArgs++;

    switch (cmp)
    {
    case 0:
        if (task->unk1E == (u16)value)
        {
            Task_GotoLabel(task, args[1]);
            return;
        }
        break;
    case 1:
        if (task->unk1E != (u16)value)
        {
            Task_GotoLabel(task, args[1]);
            return;
        }
        break;
    case 2:
        if (task->unk1E >= (u16)value)
        {
            Task_GotoLabel(task, args[1]);
            return;
        }
        break;
    case 3:
        if (task->unk1E < (u16)value)
        {
            Task_GotoLabel(task, args[1]);
            return;
        }
        break;
    }
    task->pc += 3;
}

// sub_080AD53C @ 0x080AD53C
void sub_080AD53C(struct Task *task)
{
}

/* Op 19: onFrame = arg. */
// TaskOp_SetOnFrame @ 0x080AD540
void TaskOp_SetOnFrame(struct Task *task)
{
    task->onFrame = (void *)*gTaskOpArgs;
    task->pc++;
}

// sub_080AD554 @ 0x080AD554
void sub_080AD554(struct Task *task)
{
}

/* Op 20: call func(task). */
// TaskOp_CallFunc @ 0x080AD558
void TaskOp_CallFunc(struct Task *task)
{
    void (*func)(struct Task *) = (void *)*gTaskOpArgs++;

    task->pc++;
    func(task);
}

// sub_080AD574 @ 0x080AD574
void sub_080AD574(struct Task *task)
{
}

/* Op 21: start a child task running the script at arg. */
// TaskOp_SpawnChild @ 0x080AD578
void TaskOp_SpawnChild(struct Task *task)
{
    Task_Create((const u32 *)*gTaskOpArgs, task->id);
    task->pc++;
}

// sub_080AD598 @ 0x080AD598
void sub_080AD598(struct Task *task)
{
}

// sub_080AD59C @ 0x080AD59C
void sub_080AD59C(struct Task *task)
{
    sub_080C5170(*(u16 *)gTaskOpArgs);
    task->pc++;
}

// sub_080AD5BC @ 0x080AD5BC
void sub_080AD5BC(struct Task *task)
{
}

/* Op 23: play sound effect arg. */
// TaskOp_PlaySe @ 0x080AD5C0
void TaskOp_PlaySe(struct Task *task)
{
    sub_080C51D4(*(u16 *)gTaskOpArgs);
    task->pc++;
}

// sub_080AD5E0 @ 0x080AD5E0
void sub_080AD5E0(struct Task *task)
{
}

/* Op 24: stop song arg. */
// TaskOp_StopSong @ 0x080AD5E4
void TaskOp_StopSong(struct Task *task)
{
    m4aSongNumStop(*(u16 *)gTaskOpArgs);
    task->pc++;
}

// sub_080AD604 @ 0x080AD604
void sub_080AD604(struct Task *task)
{
}
