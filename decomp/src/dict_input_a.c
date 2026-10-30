#include "global.h"
#include "extras.h"

/* Input of the compendium list screen. Task data: cursor (+0x24) of the top row (two
   buttons) while mode (+0x34) is 0; in mode 1, the list row (+0x30, 0-5) and scroll (+0x32)
   over gStatusList (Dict_CountListed entries). A on an entry whose demon is registered
   (sub_080C2644) gives result 3, B result 2; moving redraws through sub_080DB464. */
/* NONMATCHING: only the task-data pointer and the entry count swap r4/r5. */
// Dict_HandleListInput @ 0x080DBA1C
#ifdef NONMATCHING
void Dict_HandleListInput(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    u8 moved = 0;
    u16 n, rows;

    task->result = 0;
    task->unk1E = 0;
    if (d->unk10 == 0)
    {
        if (gKeysNew & 1)
        {
            task->unk1E = d->cursor + 1;
            Sound_Play(0x65);
            task->result = 1;
            gDict.unk44 = d->unk0C;
            gDict.unk46 = d->unk0E;
        }
        else if (gKeysNew & 2)
        {
            task->unk1E = 2;
            d->cursor = 1;
            Sound_Play(0x66);
            task->result = 1;
        }
        else if (gRepeatedKeys & 0x40)
        {
            if (d->cursor != 0)
                d->cursor--;
            else
                d->cursor = 1;
            Sound_Play(0x64);
        }
        else if (gKeysNew & 0x10)
        {
            d->unk10 = 1;
            Sound_Play(0x64);
        }
        else if (gRepeatedKeys & 0x80)
        {
            if (d->cursor != 1)
                d->cursor++;
            else
                d->cursor = 0;
            Sound_Play(0x64);
        }
    }
    else
    {
        n = Dict_CountListed();
        if (gDict.unk3E == 0)
            n = 1;
        rows = n;
        if (n > 5)
            rows = 6;
        if ((gKeysNew & 1) && gDict.unk3E == 1)
        {
            if (sub_080C2644(gStatusList[d->unk0C + d->unk0E] & 0x7FFF))
            {
                moved = 1;
                Sound_Play(0x65);
                task->unk1E = 3;
                task->result = moved;
            }
            else
                Sound_Play(0x66);
        }
        else if (gKeysNew & 2)
        {
            Sound_Play(0x66);
            task->unk1E = 2;
            task->result = 1;
        }
        else if (gRepeatedKeys & 0x40)
        {
            if (d->unk0C != 0)
            {
                d->unk0C--;
                moved = 1;
                Sound_Play(0x64);
            }
            else if (d->unk0E != 0)
            {
                d->unk0E--;
                moved = 1;
                Sound_Play(0x64);
            }
        }
        else if (gRepeatedKeys & 0x80)
        {
            if (d->unk0C != rows - 1)
            {
                d->unk0C++;
                moved = 1;
                Sound_Play(0x64);
            }
            else if (d->unk0C == 5 && d->unk0C + d->unk0E + 1 <= n - 1)
            {
                d->unk0E++;
                moved = 1;
                Sound_Play(0x64);
            }
        }
        else if (gKeysNew & 0x20)
        {
            d->unk10 = 0;
            Sound_Play(0x64);
        }
        else if ((gRepeatedKeys & 0x200) && n > 6)
        {
            u32 row = d->unk0C;
            u16 scroll = d->unk0E;
            u16 t = row;

            if (t != 0)
                d->unk0C = 0;
            else if (scroll > 4)
                d->unk0E = scroll - 5;
            else
                d->unk0E = t;
            if (row != d->unk0C || scroll != d->unk0E)
            {
                moved = 1;
                Sound_Play(0x64);
            }
        }
        else if ((gRepeatedKeys & 0x100) && n > 6)
        {
            u16 row = d->unk0C;
            u16 scroll = d->unk0E;

            if (d->unk0C != 5)
                d->unk0C = 5;
            else if (row + scroll + 6 < n - 1)
                d->unk0E = scroll + 6;
            else
                d->unk0E = n - 6;
            if (row != d->unk0C || scroll != d->unk0E)
            {
                moved = 1;
                Sound_Play(0x64);
            }
        }
    }
    if (moved == 1)
    {
        u16 idx = d->unk0C + d->unk0E;

        gDict.selected = gStatusList[idx] & 0x7FFF;
        gDict.unk3C = idx;
        gDict.unk44 = d->unk0C;
        gDict.unk46 = d->unk0E;
        sub_080DB464(task);
    }
}
#else
NAKED
void Dict_HandleListInput(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    adds r6, r0, #0\n"
        "    adds r4, r6, #0\n"
        "    adds r4, #0x24\n"
        "    movs r0, #0\n"
        "    mov r8, r0\n"
        "    mov r0, r8\n"
        "    strh r0, [r6, #0x1c]\n"
        "    strh r0, [r6, #0x1e]\n"
        "    ldrh r0, [r4, #0x10]\n"
        "    cmp r0, #0\n"
        "    bne .L080DBAD8\n"
        "    ldr r3, .L080DBA6C\n"
        "    ldrh r1, [r3]\n"
        "    movs r5, #1\n"
        "    adds r0, r5, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080DBA74\n"
        "    ldrh r0, [r6, #0x24]\n"
        "    adds r0, #1\n"
        "    strh r0, [r6, #0x1e]\n"
        "    movs r0, #0x65\n"
        "    bl Sound_Play\n"
        "    strh r5, [r6, #0x1c]\n"
        "    ldr r1, .L080DBA70\n"
        "    ldrh r2, [r4, #0xc]\n"
        "    adds r0, r1, #0\n"
        "    adds r0, #0x44\n"
        "    strh r2, [r0]\n"
        "    ldrh r0, [r4, #0xe]\n"
        "    adds r1, #0x46\n"
        "    strh r0, [r1]\n"
        "    b .L080DBC5E\n"
        "    .byte 0x00, 0x00\n"
        ".L080DBA6C: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L080DBA70: .4byte 0x020399E0 @ EWRAM+0x399E0\n"
        ".L080DBA74:\n"
        "    ldrh r1, [r3]\n"
        "    movs r2, #2\n"
        "    adds r0, r2, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080DBA8E\n"
        "    strh r2, [r6, #0x1e]\n"
        "    strh r5, [r6, #0x24]\n"
        "    movs r0, #0x66\n"
        "    bl Sound_Play\n"
        "    strh r5, [r6, #0x1c]\n"
        "    b .L080DBC5E\n"
        ".L080DBA8E:\n"
        "    ldr r0, .L080DBAA8\n"
        "    ldrh r2, [r0]\n"
        "    movs r0, #0x40\n"
        "    ands r0, r2\n"
        "    cmp r0, #0\n"
        "    beq .L080DBAB0\n"
        "    ldrh r0, [r6, #0x24]\n"
        "    cmp r0, #0\n"
        "    beq .L080DBAAC\n"
        "    subs r0, #1\n"
        "    strh r0, [r6, #0x24]\n"
        "    b .L080DBC0E\n"
        "    .byte 0x00, 0x00\n"
        ".L080DBAA8: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L080DBAAC:\n"
        "    strh r5, [r6, #0x24]\n"
        "    b .L080DBC0E\n"
        ".L080DBAB0:\n"
        "    ldrh r1, [r3]\n"
        "    movs r0, #0x10\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080DBABE\n"
        "    strh r5, [r4, #0x10]\n"
        "    b .L080DBC0E\n"
        ".L080DBABE:\n"
        "    movs r0, #0x80\n"
        "    ands r0, r2\n"
        "    cmp r0, #0\n"
        "    bne .L080DBAC8\n"
        "    b .L080DBC5E\n"
        ".L080DBAC8:\n"
        "    ldrh r0, [r6, #0x24]\n"
        "    cmp r0, #1\n"
        "    beq .L080DBAD2\n"
        "    adds r0, #1\n"
        "    b .L080DBAD4\n"
        ".L080DBAD2:\n"
        "    mov r0, r8\n"
        ".L080DBAD4:\n"
        "    strh r0, [r6, #0x24]\n"
        "    b .L080DBC0E\n"
        ".L080DBAD8:\n"
        "    bl Dict_CountListed\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    ldr r0, .L080DBB34\n"
        "    ldrh r3, [r0, #0x3e]\n"
        "    cmp r3, #0\n"
        "    bne .L080DBAEA\n"
        "    movs r5, #1\n"
        ".L080DBAEA:\n"
        "    mov ip, r5\n"
        "    cmp r5, #5\n"
        "    bls .L080DBAF4\n"
        "    movs r0, #6\n"
        "    mov ip, r0\n"
        ".L080DBAF4:\n"
        "    ldr r2, .L080DBB38\n"
        "    ldrh r1, [r2]\n"
        "    movs r0, #1\n"
        "    ands r0, r1\n"
        "    mov sb, r2\n"
        "    cmp r0, #0\n"
        "    beq .L080DBB4C\n"
        "    cmp r3, #1\n"
        "    bne .L080DBB4C\n"
        "    ldr r2, .L080DBB3C\n"
        "    ldrh r0, [r4, #0xc]\n"
        "    ldrh r1, [r4, #0xe]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L080DBB40\n"
        "    ands r0, r1\n"
        "    bl sub_080C2644\n"
        "    cmp r0, #0\n"
        "    beq .L080DBB44\n"
        "    movs r0, #1\n"
        "    mov r8, r0\n"
        "    movs r0, #0x65\n"
        "    bl Sound_Play\n"
        "    movs r0, #3\n"
        "    strh r0, [r6, #0x1e]\n"
        "    mov r0, r8\n"
        "    strh r0, [r6, #0x1c]\n"
        "    b .L080DBC5E\n"
        ".L080DBB34: .4byte 0x020399E0 @ EWRAM+0x399E0\n"
        ".L080DBB38: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L080DBB3C: .4byte 0x0203B554 @ EWRAM+0x3B554\n"
        ".L080DBB40: .4byte 0x00007FFF\n"
        ".L080DBB44:\n"
        "    movs r0, #0x66\n"
        "    bl Sound_Play\n"
        "    b .L080DBC5E\n"
        ".L080DBB4C:\n"
        "    mov r0, sb\n"
        "    ldrh r1, [r0]\n"
        "    movs r7, #2\n"
        "    adds r0, r7, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080DBB68\n"
        "    movs r0, #0x66\n"
        "    bl Sound_Play\n"
        "    strh r7, [r6, #0x1e]\n"
        "    movs r0, #1\n"
        "    strh r0, [r6, #0x1c]\n"
        "    b .L080DBC5E\n"
        ".L080DBB68:\n"
        "    ldr r1, .L080DBB84\n"
        "    ldrh r3, [r1]\n"
        "    movs r0, #0x40\n"
        "    ands r0, r3\n"
        "    mov sl, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080DBB94\n"
        "    ldrh r0, [r4, #0xc]\n"
        "    cmp r0, #0\n"
        "    beq .L080DBB88\n"
        "    subs r0, #1\n"
        "    strh r0, [r4, #0xc]\n"
        "    b .L080DBC0A\n"
        "    .byte 0x00, 0x00\n"
        ".L080DBB84: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L080DBB88:\n"
        "    ldrh r0, [r4, #0xe]\n"
        "    cmp r0, #0\n"
        "    beq .L080DBC5E\n"
        "    subs r0, #1\n"
        "    strh r0, [r4, #0xe]\n"
        "    b .L080DBC0A\n"
        ".L080DBB94:\n"
        "    movs r0, #0x80\n"
        "    ands r0, r3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, #0\n"
        "    beq .L080DBBC6\n"
        "    ldrh r1, [r4, #0xc]\n"
        "    mov r0, ip\n"
        "    subs r0, #1\n"
        "    cmp r1, r0\n"
        "    beq .L080DBBB0\n"
        "    adds r0, r1, #1\n"
        "    strh r0, [r4, #0xc]\n"
        "    b .L080DBC0A\n"
        ".L080DBBB0:\n"
        "    cmp r1, #5\n"
        "    bne .L080DBC5E\n"
        "    ldrh r2, [r4, #0xe]\n"
        "    adds r0, r1, r2\n"
        "    adds r0, #1\n"
        "    subs r1, r5, #1\n"
        "    cmp r0, r1\n"
        "    bgt .L080DBC5E\n"
        "    adds r0, r2, #1\n"
        "    strh r0, [r4, #0xe]\n"
        "    b .L080DBC0A\n"
        ".L080DBBC6:\n"
        "    mov r0, sb\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x20\n"
        "    ands r0, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        "    cmp r7, #0\n"
        "    beq .L080DBBDA\n"
        "    strh r2, [r4, #0x10]\n"
        "    b .L080DBC0E\n"
        ".L080DBBDA:\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #2\n"
        "    ands r0, r3\n"
        "    cmp r0, #0\n"
        "    beq .L080DBC16\n"
        "    cmp r5, #6\n"
        "    bls .L080DBC16\n"
        "    ldrh r2, [r4, #0xc]\n"
        "    ldrh r1, [r4, #0xe]\n"
        "    adds r0, r2, #0\n"
        "    cmp r0, #0\n"
        "    beq .L080DBBF6\n"
        "    strh r7, [r4, #0xc]\n"
        "    b .L080DBBFE\n"
        ".L080DBBF6:\n"
        "    cmp r1, #4\n"
        "    bls .L080DBBFC\n"
        "    subs r0, r1, #5\n"
        ".L080DBBFC:\n"
        "    strh r0, [r4, #0xe]\n"
        ".L080DBBFE:\n"
        "    ldrh r0, [r4, #0xc]\n"
        "    cmp r2, r0\n"
        "    bne .L080DBC0A\n"
        "    ldrh r0, [r4, #0xe]\n"
        "    cmp r1, r0\n"
        "    beq .L080DBC5E\n"
        ".L080DBC0A:\n"
        "    movs r0, #1\n"
        "    mov r8, r0\n"
        ".L080DBC0E:\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        "    b .L080DBC5E\n"
        ".L080DBC16:\n"
        "    mov r0, sl\n"
        "    ldrh r1, [r0]\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080DBC5E\n"
        "    cmp r5, #6\n"
        "    bls .L080DBC5E\n"
        "    ldrh r2, [r4, #0xc]\n"
        "    ldrh r3, [r4, #0xe]\n"
        "    cmp r2, #5\n"
        "    beq .L080DBC36\n"
        "    movs r0, #5\n"
        "    strh r0, [r4, #0xc]\n"
        "    b .L080DBC48\n"
        ".L080DBC36:\n"
        "    adds r0, r2, r3\n"
        "    adds r0, #6\n"
        "    subs r1, r5, #1\n"
        "    cmp r0, r1\n"
        "    bge .L080DBC44\n"
        "    adds r0, r3, #6\n"
        "    b .L080DBC46\n"
        ".L080DBC44:\n"
        "    subs r0, r5, #6\n"
        ".L080DBC46:\n"
        "    strh r0, [r4, #0xe]\n"
        ".L080DBC48:\n"
        "    ldrh r0, [r4, #0xc]\n"
        "    cmp r2, r0\n"
        "    bne .L080DBC54\n"
        "    ldrh r0, [r4, #0xe]\n"
        "    cmp r3, r0\n"
        "    beq .L080DBC5E\n"
        ".L080DBC54:\n"
        "    movs r0, #1\n"
        "    mov r8, r0\n"
        "    movs r0, #0x64\n"
        "    bl Sound_Play\n"
        ".L080DBC5E:\n"
        "    mov r0, r8\n"
        "    cmp r0, #1\n"
        "    bne .L080DBC90\n"
        "    ldr r1, .L080DBCA0\n"
        "    ldrh r2, [r4, #0xc]\n"
        "    ldrh r0, [r4, #0xe]\n"
        "    adds r2, r2, r0\n"
        "    lsls r0, r2, #1\n"
        "    adds r0, r0, r1\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L080DBCA4\n"
        "    ands r0, r1\n"
        "    ldr r1, .L080DBCA8\n"
        "    strh r2, [r1, #0x3c]\n"
        "    str r0, [r1, #0x38]\n"
        "    ldrh r2, [r4, #0xc]\n"
        "    adds r0, r1, #0\n"
        "    adds r0, #0x44\n"
        "    strh r2, [r0]\n"
        "    ldrh r0, [r4, #0xe]\n"
        "    adds r1, #0x46\n"
        "    strh r0, [r1]\n"
        "    adds r0, r6, #0\n"
        "    bl sub_080DB464\n"
        ".L080DBC90:\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080DBCA0: .4byte 0x0203B554 @ EWRAM+0x3B554\n"
        ".L080DBCA4: .4byte 0x00007FFF\n"
        ".L080DBCA8: .4byte 0x020399E0 @ EWRAM+0x399E0\n"
    );
}
#endif
