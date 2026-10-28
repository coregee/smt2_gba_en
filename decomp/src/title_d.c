#include "global.h"
#include "title.h"

/* Staff-roll style scroll: four sprites spaced 0x40 apart rise with a 16-bit position kept
   big-endian in task bytes 0x30/0x31. */
/* NONMATCHING: the y arguments are computed before the sprite pointer is loaded and the two position bytes load through one incremented pointer (scheduling) */
// sub_080D74D8 @ 0x080D74D8
#ifdef NONMATCHING
void sub_080D74D8(struct Task *task)
{
    u16 pos = (task->data.raw[0xC] << 8) | task->data.raw[0xD];

    if (task->data.raw[1] != 0)
    {
        task->data.raw[1]--;
        return;
    }
    if (task->data.raw[3] != 0)
    {
        task->data.raw[3]--;
        return;
    }
    if (task->data.raw[2] != 0)
    {
        task->data.raw[2]--;
    }
    else
    {
        task->data.raw[2] = 6;
        pos++;
    }
    if (pos < 0x80)
        Sprite_Draw(gUnknown_0813ECB4, 0, 0, 0, 0, 0x78, 0xA0 - pos);
    if ((u16)(pos - 0x40) < 0x80)
        Sprite_Draw(gUnknown_0813ECD0, 0, 0, 0, 0, 0x78, 0xE0 - pos);
    if ((u16)(pos - 0x80) < 0x80)
        Sprite_Draw(gUnknown_0813ECEC, 0, 0, 0, 0, 0x78, 0x120 - pos);
    if ((u16)(pos - 0xC0) < 0x76)
        Sprite_Draw(gUnknown_0813ED2C, 0, 0, 0, 0, 0x78, 0x160 - pos);
    task->data.raw[0xC] = pos >> 8;
    task->data.raw[0xD] = pos;
}
#else
NAKED
void sub_080D74D8(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, lr}\n"
        "    sub sp, #0xc\n"
        "    adds r5, r0, #0\n"
        "    adds r0, #0x30\n"
        "    ldrb r1, [r0]\n"
        "    adds r0, #1\n"
        "    ldrb r0, [r0]\n"
        "    lsls r4, r1, #8\n"
        "    orrs r4, r0\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x25\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0\n"
        "    bne .L080D74FE\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x27\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0\n"
        "    beq .L080D7504\n"
        ".L080D74FE:\n"
        "    subs r0, #1\n"
        "    strb r0, [r1]\n"
        "    b .L080D75D2\n"
        ".L080D7504:\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0x26\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0\n"
        "    beq .L080D7514\n"
        "    subs r0, #1\n"
        "    strb r0, [r1]\n"
        "    b .L080D751E\n"
        ".L080D7514:\n"
        "    movs r0, #6\n"
        "    strb r0, [r1]\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        ".L080D751E:\n"
        "    cmp r4, #0x7f\n"
        "    bhi .L080D7540\n"
        "    movs r1, #0xa0\n"
        "    subs r1, r1, r4\n"
        "    ldr r0, .L080D75DC\n"
        "    movs r2, #0\n"
        "    str r2, [sp]\n"
        "    movs r2, #0x78\n"
        "    str r2, [sp, #4]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L080D7540:\n"
        "    adds r0, r4, #0\n"
        "    subs r0, #0x40\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #0x7f\n"
        "    bhi .L080D756A\n"
        "    movs r1, #0xe0\n"
        "    subs r1, r1, r4\n"
        "    ldr r0, .L080D75E0\n"
        "    movs r2, #0\n"
        "    str r2, [sp]\n"
        "    movs r2, #0x78\n"
        "    str r2, [sp, #4]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L080D756A:\n"
        "    adds r0, r4, #0\n"
        "    subs r0, #0x80\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #0x7f\n"
        "    bhi .L080D7598\n"
        "    movs r0, #0x90\n"
        "    lsls r0, r0, #1\n"
        "    adds r1, r0, #0\n"
        "    subs r1, r1, r4\n"
        "    ldr r0, .L080D75E4\n"
        "    movs r2, #0\n"
        "    str r2, [sp]\n"
        "    movs r2, #0x78\n"
        "    str r2, [sp, #4]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L080D7598:\n"
        "    adds r0, r4, #0\n"
        "    subs r0, #0xc0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #0x75\n"
        "    bhi .L080D75C6\n"
        "    movs r0, #0xb0\n"
        "    lsls r0, r0, #1\n"
        "    adds r1, r0, #0\n"
        "    subs r1, r1, r4\n"
        "    ldr r0, .L080D75E8\n"
        "    movs r2, #0\n"
        "    str r2, [sp]\n"
        "    movs r2, #0x78\n"
        "    str r2, [sp, #4]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Sprite_Draw\n"
        ".L080D75C6:\n"
        "    lsrs r1, r4, #8\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x30\n"
        "    strb r1, [r0]\n"
        "    adds r0, #1\n"
        "    strb r4, [r0]\n"
        ".L080D75D2:\n"
        "    add sp, #0xc\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080D75DC: .4byte gUnknown_0813ECB4\n"
        ".L080D75E0: .4byte gUnknown_0813ECD0\n"
        ".L080D75E4: .4byte gUnknown_0813ECEC\n"
        ".L080D75E8: .4byte gUnknown_0813ED2C\n"
    );
}
#endif

// sub_080D75EC @ 0x080D75EC
void sub_080D75EC(struct Task *task)
{
    task->data.raw[0] = 0x20;
    task->data.raw[1] = 0;
    task->result = 0;
}

/* Every 32 frames scroll BG0/BG1/BG2 up by one line, 24 times. */
// sub_080D7600 @ 0x080D7600
void sub_080D7600(struct Task *task)
{
    if (--task->data.raw[0] == 0)
    {
        task->data.raw[0] = 0x20;
        task->data.raw[1]++;
        if (task->data.raw[1] != 0x18)
        {
            gUnk_0300000C--;
            gUnk_03000008--;
            gUnk_03000004--;
        }
        else
        {
            task->result = 1;
        }
    }
}

// sub_080D7658 @ 0x080D7658
void sub_080D7658(void)
{
    TITLE->unk0E = 0;
    gMsgWindow = Task_Create(gUnknown_08509764, 0xFFFF);
    gUnk_03006938 = Task_Create(gUnknown_085097A0, 0xFFFF);
    gUnk_03006954 = Task_Create(gUnknown_08509728, 0xFFFF);
    Task_Create(gUnknown_085097DC, 0xFFFF);
}

// sub_080D76B8 @ 0x080D76B8
void sub_080D76B8(struct Task *task)
{
    task->result = 0;
}

// sub_080D76C0 @ 0x080D76C0
void sub_080D76C0(struct Task *task)
{
    if ((s16)TITLE->unk0E == 1)
        task->result = 1;
}

// sub_080D76D8 @ 0x080D76D8
void sub_080D76D8(void)
{
    if (gUnk_030069E4->state != 0)
        Task_End(gUnk_030069E4);
}

// sub_080D76F4 @ 0x080D76F4
void sub_080D76F4(void)
{
    if (gUnk_030069E4->state == 0)
        gUnk_030069E4 = Task_Create(gUnknown_08509CD0, 0xFFFF);
}

// sub_080D771C @ 0x080D771C
void sub_080D771C(void)
{
    TITLE->unk10 = 0;
}

// sub_080D7728 @ 0x080D7728
void sub_080D7728(void)
{
    struct TitleMenu *menu = TITLE;

    if (gKeysNew & 8)
        menu->unk10 = 1;
}

// sub_080D7748 @ 0x080D7748
void sub_080D7748(struct Task *task, u32 pause)
{
    struct Task *t = gUnk_030065F4;

    if (pause == 1)
        Task_Pause(t);
    else
        Task_Resume(t);
}

/* Character sprite helpers: the task data at +0x24 is a struct CharObj. */

// sub_080D7764 @ 0x080D7764
void sub_080D7764(struct Task *task, u32 pose, u32 half)
{
    struct CharGfxRecord *rec = Char_GetRecord(task->data.h[3]);

    LZ77UnCompWram(rec->gfx[pose][half], (void *)(0x02001000 + (half << 12)));
}

// sub_080D7794 @ 0x080D7794
void sub_080D7794(void)
{
    DmaSet3(0x02001000, 0x06016000, 0x84000800);
}

// sub_080D77B8 @ 0x080D77B8
void sub_080D77B8(void)
{
    VBlankTask_AddCounted(sub_080D7794, 1);
}

// sub_080D77CC @ 0x080D77CC
void sub_080D77CC(struct Task *task, u32 palIndex)
{
    struct CharObj *obj = (struct CharObj *)&task->data;

    sub_080C3F4C(obj, Char_GetRecord(obj->id)->palette, palIndex, 0x20, 1);
}

// sub_080D77F4 @ 0x080D77F4
void sub_080D77F4(struct Task *task)
{
    task->data.h[2] = 1;
}

/* Looks the record up but loads from the table passed in (base[pose * 2 + half]). */
// sub_080D77FC @ 0x080D77FC
void sub_080D77FC(struct Task *task, const void **base, u32 a2, u32 pose, u32 half)
{
    struct CharObj *obj = (struct CharObj *)&task->data;

    Char_GetRecord(obj->id);
    Char_LoadGfxHalf(obj, base[pose * 2 + half], a2, half, 1);
}

/* Signals every character task (table at 0x02036094) whose id matches `id` -- which is never
   assigned: the comparison reads whatever the caller left in r6 (original bug). */
// Char_SignalById @ 0x080D7840
void Char_SignalById(void)
{
    u32 i;
    struct Task **p;
    u16 id;

    for (i = 0, p = gCharTasks; i < 6; p++, i++)
    {
        if (*p != NULL && (*p)->data.h[3] == id)
            Task_Signal(*p);
    }
}

// sub_080D786C @ 0x080D786C
void sub_080D786C(struct Task *task)
{
    CharObj_End(task, 0);
}

// sub_080D7878 @ 0x080D7878
void sub_080D7878(void)
{
    DmaSet3(0x02001000, 0x06016000, 0x84000200);
}

// sub_080D789C @ 0x080D789C
void sub_080D789C(void)
{
    DmaSet3(0x02001800, 0x06016800, 0x84000200);
}

// sub_080D78C0 @ 0x080D78C0
void sub_080D78C0(void)
{
    DmaSet3(0x02002000, 0x06017000, 0x84000200);
}

// sub_080D78E4 @ 0x080D78E4
void sub_080D78E4(void)
{
    DmaSet3(0x02002800, 0x06017800, 0x84000200);
}

// sub_080D7908 @ 0x080D7908
void sub_080D7908(void)
{
    DmaSet3(0x02003000, 0x06015000, 0x84000200);
}

// sub_080D792C @ 0x080D792C
void sub_080D792C(void)
{
    DmaSet3(0x02003800, 0x06015800, 0x84000200);
}

/* Decompresses one 2 KB character half into slot obj->slot's buffer, sets its palette unless
   noPalette, and queues the slot's VRAM upload. */
// sub_080D7950 @ 0x080D7950
void sub_080D7950(struct CharObj *obj, const void *src, u32 noPalette, u32 unused, u32 a4)
{
    struct CharGfxRecord *rec = Char_GetRecord(obj->id);
    u16 slot = obj->slot;

    if (obj->shown != 0)
    {
        u32 pal = gUnknown_0855FA84[slot];

        LZ77UnCompWram(src, (void *)(0x02001000 + (slot << 11)));
        if (noPalette == 0)
            sub_080C3F4C(obj, rec->palette, pal, 0x20, a4);
        VBlankTask_AddCounted(gUnknown_0855FA9C[slot], 1);
    }
}

// sub_080D79C0 @ 0x080D79C0
void sub_080D79C0(struct Task *task, u32 noPalette, u32 pose, u32 half)
{
    struct CharObj *obj = (struct CharObj *)&Task_GetParent(task)->data;
    struct CharGfxRecord *rec = Char_GetRecord(obj->id);

    sub_080D7950(obj, rec->gfx[pose][half], noPalette, half, 1);
}

/* result = 1 if the cell record of type 0x23 under the player has +2 == 4 (and gGameState
   +0xAC0 is not 1). */
// sub_080D7A04 @ 0x080D7A04
void sub_080D7A04(struct Task *task)
{
    u16 *rec = FieldMap_FindRecord(FieldMap_CellRecordsRel(0, 0), 0x23);

    if (gGameState.unkAC0 != 1 && rec != NULL && rec[1] == 4)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080D7A44 @ 0x080D7A44
void sub_080D7A44(struct Task *task)
{
    sub_080D7A04(task);
    if (task->result == 0)
    {
        sub_080C41F4(task);
    }
    else
    {
        struct CharObj *obj = (struct CharObj *)&task->data;
        u16 slot = obj->slot;

        if (obj->shown != 0)
            PalFade_FadeRangeToBlackTagged(gUnknown_0855FA84[slot], 0x10, 1, 1);
    }
}
