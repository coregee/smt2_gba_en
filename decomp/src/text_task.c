/* Script tasks: 64 slots that each run a word-coded script (ops in gTaskOpTable).
   Text windows and the yes/no cursor in text_window.c are tasks. */

#include "global.h"
#include "text.h"

// Task_ClearAll @ 0x080ACFF4
void Task_ClearAll(void)
{
    vu32 zero = 0;

    TEXT_DMA3_SET(&zero, gTasks, 0x85000000 | (sizeof(gTasks) / 4));
}

/* Runs every task for one frame: fetches and starts ops until one leaves task->wait
   nonzero (or the task ends), or runs the pending op's update. */
// Task_RunAll @ 0x080AD01C
void Task_RunAll(void)
{
    u32 i;

    for (i = 0; i < TASK_COUNT; i++)
    {
        struct Task *task = &gTasks[i];

        if (task->state != TASK_STATE_FREE && !Task_IsPaused(task))
        {
            for (;;)
            {
                if (task->wait == 0)
                {
                    {
                        const u32 *s = task->script;
                        gTaskOpArgs = s + task->pc;
                    }
                    task->op = *gTaskOpArgs++;
                    task->pc++;
                    if (task->op != TASK_OP_LABEL)
                        gTaskOpTable[task->op].start(task);
                    else
                        task->pc++;
                }
                else
                {
                    const u32 *s = task->script;
                    gTaskOpArgs = s + task->pc;
                    gTaskOpTable[task->op].update(task);
                }
                if (task->wait != 0 || task->state == TASK_STATE_FREE)
                    break;
            }

            if (task->state != TASK_STATE_FREE && task->onFrame != NULL)
                task->onFrame(task);
        }
    }
}

/* Slot 0 is never handed out. */
// Task_FindFreeSlot @ 0x080AD0D4
s32 Task_FindFreeSlot(void)
{
    u32 i;

    for (i = 1; i < TASK_COUNT; i++)
    {
        if (gTasks[i].state == TASK_STATE_FREE)
            return i;
    }
    return -1;
}

// Task_Create @ 0x080AD0FC
struct Task *Task_Create(const u32 *script, u32 parent)
{
    s32 id = Task_FindFreeSlot();
    struct Task *task;

    if (id == -1)
        return NULL;

    task = &gTasks[id];
    {
        vu32 zero = 0;

        TEXT_DMA3_SET(&zero, task, 0x85000000 | (sizeof(struct Task) / 4));
    }
    task->script = script;
    task->id = id;
    task->parent = parent;
    task->state = TASK_STATE_RUN;
    return task;
}

// Task_Pause @ 0x080AD150
void Task_Pause(struct Task *task)
{
    task->state = TASK_STATE_PAUSED;
}

// Task_IsPaused @ 0x080AD15C
bool32 Task_IsPaused(struct Task *task)
{
    bool32 paused = FALSE;

    if (task->state == TASK_STATE_PAUSED)
        paused = TRUE;
    return paused;
}

// Task_Resume @ 0x080AD174
void Task_Resume(struct Task *task)
{
    task->state = TASK_STATE_RUN;
}

/* Op 0 "wait N frames" (N = -1: until signalled, see Task_Signal); update below. */
// TaskOp_Wait @ 0x080AD17C
void TaskOp_Wait(struct Task *task)
{
    task->wait = *gTaskOpArgs;
    task->pc++;
}

// TaskOp_WaitUpdate @ 0x080AD190
void TaskOp_WaitUpdate(struct Task *task)
{
    if (task->wait != -1)
        task->wait--;
}

/* Jumps to the TASK_OP_LABEL with this id (scans from the start; never stops if missing). */
// Task_GotoLabel @ 0x080AD1A8
void Task_GotoLabel(struct Task *task, u32 label)
{
    task->pc = 0;
    gTaskOpArgs = task->script;
    while (!(gTaskOpArgs[0] == TASK_OP_LABEL && label == gTaskOpArgs[1]))
    {
        gTaskOpArgs++;
        task->pc++;
    }
}

/* Op 1 "goto label". */
// TaskOp_Goto @ 0x080AD1E4
void TaskOp_Goto(struct Task *task)
{
    Task_GotoLabel(task, *gTaskOpArgs);
}

// sub_080AD1F8 @ 0x080AD1F8
void sub_080AD1F8(struct Task *task)
{
}

// Task_End @ 0x080AD1FC
void Task_End(struct Task *task)
{
    if (task != NULL)
        task->state = TASK_STATE_FREE;
}

// Task_GetState @ 0x080AD20C
u16 Task_GetState(struct Task *task)
{
    return task->state;
}

// Task_EndById @ 0x080AD210
void Task_EndById(struct Task *unused, s32 id)
{
    struct Task *tasks = gTasks;
    struct Task *task = &tasks[id];

    if (task->state != TASK_STATE_FREE)
        Task_End(task);
}

/* Ends every task except `self`. */
// Task_EndAllExcept @ 0x080AD230
void Task_EndAllExcept(struct Task *self)
{
    s32 i;

    for (i = 0; i < TASK_COUNT; i++)
    {
        struct Task *task = &gTasks[i];

        if (task->state != TASK_STATE_FREE && task != self)
            Task_End(task);
    }
}

/* Ends the children of `self`. */
// Task_EndChildren @ 0x080AD260
void Task_EndChildren(struct Task *self)
{
    s32 i;

    for (i = 0; i < TASK_COUNT; i++)
    {
        struct Task *task = &gTasks[i];

        if (task->state != TASK_STATE_FREE && task != self && task->parent == self->id)
            Task_End(task);
    }
}

/* Op 2 "end". */
// TaskOp_End @ 0x080AD298
void TaskOp_End(struct Task *task)
{
    Task_End(task);
}

// sub_080AD2A4 @ 0x080AD2A4
void sub_080AD2A4(struct Task *task)
{
}

/* Op 3 "loop N": the ops up to op 4 run N times (N = 0 runs 65536 times). */
// TaskOp_Loop @ 0x080AD2A8
void TaskOp_Loop(struct Task *task)
{
    task->loopCount = *gTaskOpArgs;
    task->pc++;
    task->loopStart = task->pc;
}

// sub_080AD2C0 @ 0x080AD2C0
void sub_080AD2C0(struct Task *task)
{
}

/* Op 4 "end loop". */
// TaskOp_EndLoop @ 0x080AD2C4
void TaskOp_EndLoop(struct Task *task)
{
    if (--task->loopCount != 0)
        task->pc = task->loopStart;
}

// sub_080AD2DC @ 0x080AD2DC
void sub_080AD2DC(struct Task *task)
{
}

/* Ops 5 and 6 do nothing. */
// sub_080AD2E0 @ 0x080AD2E0
void sub_080AD2E0(struct Task *task)
{
}

// sub_080AD2E4 @ 0x080AD2E4
void sub_080AD2E4(struct Task *task)
{
}

// sub_080AD2E8 @ 0x080AD2E8
void sub_080AD2E8(struct Task *task)
{
}

// sub_080AD2EC @ 0x080AD2EC
void sub_080AD2EC(struct Task *task)
{
}

/* Op 7 "if result goto label". */
// TaskOp_IfResultGoto @ 0x080AD2F0
void TaskOp_IfResultGoto(struct Task *task)
{
    if (task->result != 0)
        Task_GotoLabel(task, *gTaskOpArgs);
    else
        task->pc++;
}

// sub_080AD318 @ 0x080AD318
void sub_080AD318(struct Task *task)
{
}

/* Op 8 "unless result goto label". */
// TaskOp_UnlessResultGoto @ 0x080AD31C
void TaskOp_UnlessResultGoto(struct Task *task)
{
    if (task->result == 0)
        Task_GotoLabel(task, *gTaskOpArgs);
    else
        task->pc++;
}

// sub_080AD344 @ 0x080AD344
void sub_080AD344(struct Task *task)
{
}

/* Releases a task waiting forever (wait == -1) on the next frame. */
// Task_Signal @ 0x080AD348
void Task_Signal(struct Task *task)
{
    if (task->state != TASK_STATE_FREE && task->wait == -1)
        task->wait = 1;
}

// Task_GetParent @ 0x080AD364
struct Task *Task_GetParent(struct Task *task)
{
    return &gTasks[task->parent];
}

/* Op 9 "signal parent". */
// TaskOp_SignalParent @ 0x080AD374
void TaskOp_SignalParent(struct Task *task)
{
    Task_Signal(Task_GetParent(task));
}

// sub_080AD384 @ 0x080AD384
void sub_080AD384(struct Task *task)
{
}

/* Ops 10..14 "call func(task, args...)" with 0 to 4 argument words. */
// TaskOp_Call0 @ 0x080AD388
void TaskOp_Call0(struct Task *task)
{
    void (*func)(struct Task *) = (void *)*gTaskOpArgs++;

    task->pc += 1;
    func(task);
}

// sub_080AD3A4 @ 0x080AD3A4
void sub_080AD3A4(struct Task *task)
{
}

// TaskOp_Call1 @ 0x080AD3A8
void TaskOp_Call1(struct Task *task)
{
    void (*func)(struct Task *, u32) = (void *)*gTaskOpArgs++;

    task->pc += 2;
    func(task, gTaskOpArgs[0]);
}

// sub_080AD3C8 @ 0x080AD3C8
void sub_080AD3C8(struct Task *task)
{
}

// TaskOp_Call2 @ 0x080AD3CC
void TaskOp_Call2(struct Task *task)
{
    void (*func)(struct Task *, u32, u32) = (void *)*gTaskOpArgs++;

    task->pc += 3;
    func(task, gTaskOpArgs[0], gTaskOpArgs[1]);
}

// sub_080AD3EC @ 0x080AD3EC
void sub_080AD3EC(struct Task *task)
{
}

// TaskOp_Call3 @ 0x080AD3F0
void TaskOp_Call3(struct Task *task)
{
    void (*func)(struct Task *, u32, u32, u32) = (void *)*gTaskOpArgs++;

    task->pc += 4;
    func(task, gTaskOpArgs[0], gTaskOpArgs[1], gTaskOpArgs[2]);
}

// sub_080AD414 @ 0x080AD414
void sub_080AD414(struct Task *task)
{
}

// TaskOp_Call4 @ 0x080AD418
void TaskOp_Call4(struct Task *task)
{
    void (*func)(struct Task *, u32, u32, u32, u32) = (void *)*gTaskOpArgs++;

    task->pc += 5;
    func(task, gTaskOpArgs[0], gTaskOpArgs[1], gTaskOpArgs[2], gTaskOpArgs[3]);
}
