#include "global.h"
#include "extras.h"

// sub_080DB1D8 @ 0x080DB1D8
void sub_080DB1D8(struct Task *task, u32 value)
{
    gUnk_0300609C = value;
}

// sub_080DB1E4 @ 0x080DB1E4
void sub_080DB1E4(void)
{
    gDict.task = 0;
    gDict.unk44 = 0;
    gDict.unk46 = 0;
}

/* Compendium top menu: row 0 opens the list (answer 3 when it is empty). */
// sub_080DB1FC @ 0x080DB1FC
void sub_080DB1FC(struct Task *task)
{
    task->result = 0;
    task->unk1E = 0;
    if (gKeysNew & 1)
    {
        task->unk1E = task->data.h[0] + 1;
        sub_080C51D4(0x65);
        task->result = 1;
        if (task->unk1E == 1)
        {
            Dict_BuildList(task, 0, 0);
            if (Dict_CountListed() == 0)
                task->unk1E = 3;
            else
            {
                u16 *list = gUnk_0203B554;

                gDict.selected = *list & 0x7FFF;
            }
        }
    }
    else if (gKeysNew & 2)
    {
        sub_080C51D4(0x66);
        task->result = 1;
    }
    else
    {
        u16 up = gRepeatedKeys & 0x40;

        if (up)
        {
            if (task->data.h[0] != 0)
                task->data.h[0]--;
            else
                task->data.h[0] = 1;
            sub_080C51D4(0x64);
        }
        else if (gRepeatedKeys & 0x80)
        {
            if (task->data.h[0] != 1)
                task->data.h[0]++;
            else
                task->data.h[0] = up;
            sub_080C51D4(0x64);
        }
    }
}

// DDS_DrawMenuRow @ 0x080DB2C0
void DDS_DrawMenuRow(struct Task *task)
{
    struct Task *parent = Task_GetParent(task);

    Text_DrawSpriteString(gUnknown_08582D28[parent->data.h[0]], 0, 0, 0x14, 0x64, 0xC);
}

// sub_080DB2F0 @ 0x080DB2F0
void sub_080DB2F0(void)
{
    Text_DrawSpriteString(gUnknown_080095B4, 0, 0, 0x14, 0x64, 0xC);
}

// sub_080DB314 @ 0x080DB314
void sub_080DB314(void)
{
    struct C0d9MenuState *ms = &gMenuState;
    u32 zero;

    ms->magic00 = 0x10570010;
    CpuSet(gUnk_03004690, ms->unk04, 0x0400000C);
    ms->magic = 0;
    zero = 0;
    CpuSet(&zero, ms->flags, 0x0500000C);
}

// sub_080DB358 @ 0x080DB358
void sub_080DB358(void)
{
    sub_080DF954(0x34, &gMenuState, &gMenuState.magic);
}

// sub_080DB370 @ 0x080DB370
void sub_080DB370(struct Task *task)
{
    if (gMenuState.magic == 0x10570010)
        task->result = 1;
    else
        task->result = 0;
}

/* Registers the received compendium entries (one bit per demon) and saves. */
// Dict_ApplyReceivedEntries @ 0x080DB394
void Dict_ApplyReceivedEntries(void)
{
    struct C0d9MenuState *ms = &gMenuState;
    u8 *flags = ms->flags;
    u32 i;

    for (i = 0; i <= 0x17B; i++)
    {
        if ((flags[i >> 3] >> (i & 7)) & 1)
            sub_080C2674(i);
    }
    SaveSlot_Write(gGameState.saveSlot, &gGameState);
}

/* 0 if id is in the 0xFFFF-terminated gUnknown_08583258, else 0x20. */
// sub_080DB3E4 @ 0x080DB3E4
u32 sub_080DB3E4(u16 id)
{
    u16 i;

    for (i = 0; ; i++)
    {
        if (gUnknown_08583258[i] == 0xFFFF)
            return 0x20;
        if (gUnknown_08583258[i] == id)
            return 0;
    }
}

// sub_080DB41C @ 0x080DB41C
void sub_080DB41C(void)
{
    struct C0d9Dict *dict = &gDict;

    if (dict->task == 0)
    {
        u16 demon = sub_080C263C(dict->selected);

        sub_080C3818(1);
        dict->task = sub_080E8E00(0, demon);
        sub_080E8F80(0, 0x78, (u16)sub_080DB3E4(demon) + 0x58, 3);
    }
}

// sub_080DB464 @ 0x080DB464
void sub_080DB464(void)
{
    struct C0d9Dict *dict = &gDict;
    u16 demon = sub_080C263C(dict->selected);

    sub_080C3818(1);
    dict->task = sub_080E8E00(0, demon);
    sub_080E8F80(0, 0x78, (u16)sub_080DB3E4(demon) + 0x58, 3);
}
