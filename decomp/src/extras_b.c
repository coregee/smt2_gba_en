#include "global.h"
#include "extras.h"

// sub_080D9F7C @ 0x080D9F7C
void sub_080D9F7C(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;

    Sprite_Draw(d->spr04, 0, 7, 0, 0, 0xB8, 0x78);
    Sprite_Draw(gUnknown_080083DC, 0, 7, 0, 0x100, 0xBD, task->data.h[0] * 11 + 0x7A);
    if (d->spr08 == gUnknown_080083C4)
        Sprite_Draw(d->spr08, 0, 7, 0, 0, 0xBB, 0x79);
    else
        Sprite_Draw(d->spr08, 0, 7, 0, 0, 0xBB, 0x7D);
}

/* Yes/no input: up/down toggles, A confirms the cursor, B answers 1 (no). */
// sub_080DA00C @ 0x080DA00C
void sub_080DA00C(struct Task *task)
{
    u16 cursor;

    task->result = 0;
    if (gKeysNew & 1)
    {
        gYesNoResult = cursor = task->data.h[0];
        task->result = 1;
        if (cursor == 0)
        {
            Sound_Play(0x65);
            return;
        }
        Sound_Play(0x66);
    }
    else if (gKeysNew & 2)
    {
        gYesNoResult = 1;
        task->result = 1;
        Sound_Play(0x66);
    }
    else if (gRepeatedKeys & 0xC0)
    {
        task->data.h[0] = (task->data.h[0] + 1) & 1;
        Sound_Play(0x64);
    }
}

// sub_080DA084 @ 0x080DA084
void sub_080DA084(struct Task *task, const void *spr04, const void *spr08)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&Task_Create(gUnknown_08581568, task->id)->data;

    d->spr04 = spr04;
    d->spr08 = spr08;
}

// sub_080DA0A4 @ 0x080DA0A4
void sub_080DA0A4(struct Task *task)
{
    task->unk1E = gYesNoResult;
}

/* Menu input over d->items: A returns the item id, B selects the last row and returns 5. */
// sub_080DA0B0 @ 0x080DA0B0
void sub_080DA0B0(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    u8 count = d->count;
    u16 last = count;

    task->result = 0;
    if (gKeysNew & 1)
    {
        task->unk1E = d->items[task->data.h[0]];
        Sound_Play(0x65);
        task->result = 1;
    }
    else if (gKeysNew & 2)
    {
        task->data.h[0] = d->count - 1;
        task->unk1E = 5;
        Sound_Play(0x66);
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
                task->data.h[0] = count - 1;
            Sound_Play(0x64);
        }
        else if (gRepeatedKeys & 0x80)
        {
            if (task->data.h[0] != last - 1)
                task->data.h[0]++;
            else
                task->data.h[0] = up;
            Sound_Play(0x64);
        }
    }
}

// sub_080DA150 @ 0x080DA150
void sub_080DA150(struct Task *task)
{
    struct Task *parent = Task_GetParent(task);
    u16 cursor = parent->data.h[0];
    u16 item = ((struct C0d9Menu *)&parent->data)->items[cursor] - 1;

    Text_DrawSpriteString(gUnknown_08581598[item * 5 + cursor], 0, 0, 0x14, 0x64, 0xC);
}

// sub_080DA190 @ 0x080DA190
void sub_080DA190(void)
{
    SaveSlot_Write(gGameState.saveSlot, &gGameState);
    SetMainCallback(sub_080DE78C);
}

/* Builds the extra menu's rows from what the save has unlocked; the last row (5) is always there. */
// ExtraMenu_BuildRows @ 0x080DA1B4
void ExtraMenu_BuildRows(struct Task *task)
{
    u32 n;
    struct C0d9Menu *d;
    u32 i;

    n = 0;
    d = (struct C0d9Menu *)&task->data;
    if (sub_080C2A84(0) == 1 || sub_080C2A84(1) == 1 || sub_080C2A84(2) == 1)
        d->items[n++] = 1;
    for (i = 0; i <= 0x17B; i++)
    {
        if (sub_080C2644(i))
        {
            d->items[n++] = 2;
            break;
        }
    }
    for (i = 0; i <= 0x3F; i++)
    {
        if (sub_080C2734(i + 300))
        {
            d->items[n++] = 3;
            break;
        }
    }
    if (sub_080C2A84(0) == 1 || sub_080C2A84(1) == 1 || sub_080C2A84(2) == 1)
        d->items[n++] = 4;
    d->items[n++] = 5;
    d->count = n;
}

// sub_080DA290 @ 0x080DA290
void sub_080DA290(void)
{
    DmaSet3(0x0600CC00, 0x06012800, 0x84000800);
}

// sub_080DA2B4 @ 0x080DA2B4
void sub_080DA2B4(void)
{
    Palette_CopyWithEffect(3, gUnknown_08580880, gPaletteTarget + 0x3A0, 0x20, 0x20);
    Palette_MarkDirty();
    VBlankTask_AddCounted(sub_080DA290, 1);
}

// sub_080DA2E8 @ 0x080DA2E8
void sub_080DA2E8(struct Task *task, u8 top, u8 bottom, u8 left, u8 right)
{
    gUnk_03000030 = right;
    gUnk_03000031 = left;
    gUnk_03000034 = bottom;
    gUnk_03000035 = top;
    gUnk_03000038 = 0x2F;
}

// sub_080DA31C @ 0x080DA31C
void sub_080DA31C(void)
{
    gUnk_03000038 = 0x3F;
}

// sub_080DA328 @ 0x080DA328
void sub_080DA328(struct Task *task, u8 top, u8 bottom, u8 left, u8 right)
{
    gUnk_03000032 = right;
    gUnk_03000033 = left;
    gUnk_03000036 = bottom;
    gUnk_03000037 = top;
    gUnk_03000039 = 0x2F;
}

// sub_080DA35C @ 0x080DA35C
void sub_080DA35C(void)
{
    gUnk_03000039 = 0x3F;
}

// sub_080DA368 @ 0x080DA368
void sub_080DA368(void)
{
    gUnk_03006098 = NULL;
}

// sub_080DA374 @ 0x080DA374
void sub_080DA374(struct Task *task, const u32 *script)
{
    gUnk_03006098 = Task_Create(script, task->id);
}

// sub_080DA38C @ 0x080DA38C
void sub_080DA38C(struct Task *task)
{
    if (gUnk_03006098 != NULL && gUnk_03006098->wait == -1)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080DA3B4 @ 0x080DA3B4
void sub_080DA3B4(void)
{
    struct Task *t = gUnk_03006098;

    if (t != NULL && t->wait == -1)
        t->wait = 1;
}

// sub_080DA3D4 @ 0x080DA3D4
void sub_080DA3D4(void)
{
    if (gUnk_03006098 != NULL)
    {
        Task_End(gUnk_03006098);
        gUnk_03006098 = NULL;
        gUnk_03000038 = 0x3F;
        gUnk_03000039 = 0x3F;
    }
}

// sub_080DA404 @ 0x080DA404
void sub_080DA404(void)
{
    if (((gFrameCounter >> 4) & 1) == 0)
        Sprite_Draw(gUnknown_08008D28, 0, 10, 0, 0x140, 0x12, 0x63);
    else
        Sprite_Draw(gUnknown_08008E20, 0, 10, 0, 0x140, 0x12, 0x63);
}

// sub_080DA460 @ 0x080DA460
void sub_080DA460(void)
{
    if (((gFrameCounter >> 4) & 1) == 0)
        Sprite_Draw(gUnknown_08008DA4, 0, 10, 0, 0x140, 0x12, 0x63);
    else
        Sprite_Draw(gUnknown_08008EC8, 0, 10, 0, 0x140, 0x12, 0x63);
}

// sub_080DA4BC @ 0x080DA4BC
void sub_080DA4BC(void)
{
    if (((gFrameCounter >> 4) & 1) == 0)
        Sprite_Draw(gUnknown_08008DD8, 0, 10, 0, 0x140, 0x12, 0x63);
    else
        Sprite_Draw(gUnknown_08008F10, 0, 10, 0, 0x140, 0x12, 0x63);
}
