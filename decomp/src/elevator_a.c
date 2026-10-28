#include "global.h"
#include "fieldcmd.h"

// sub_080B9E78 @ 0x080B9E78
/* Up/down indicator of the elevator: a sprite on map 0x5A, palette colour 0xD7/0xDE
   otherwise (step 0 lights it, step 1 restores it). */
void sub_080B9E78(struct Task *task, u32 step)
{
    struct FloorMenu *d = FLOOR_MENU(task);

    if (sub_080B9764() == 0x5A)
    {
        if (step == 0)
        {
            u16 cx, cy;

            sub_080C1F50(gFieldState.unk12, gFieldState.unk14, &cx, &cy);
            if (cx == 0x40 && cy == 0xC)
                Sprite_Draw(gUnknown_08002CBC, 1, 0xD, 0, 0x300, 0x64, 8);
            else if (d->prevFloor < d->floors[d->cursor])
                Sprite_Draw(gUnknown_08002CBC, 1, 0xD, 0, 0x300, 0x64, 8);
            else
                Sprite_Draw(gUnknown_08002CCC, 1, 0xD, 0, 0x300, 0x64, 8);
        }
    }
    else
    {
        const u16 *pal = gUnknown_084C0D50;
        u16 *buf = gPaletteBuffer;
        u32 idx = d->prevFloor < FLOOR_MENU(task)->floors[d->cursor] ? 0xD7 : 0xDE;

        if (step == 0)
            buf[idx] = 0x1F;
        else
            buf[idx] = pal[idx - 0xC0];
        Palette_MarkDirty();
    }
}

// sub_080B9F4C @ 0x080B9F4C
void sub_080B9F4C(struct Task *task, u32 delta)
{
    struct FloorMenu *d = FLOOR_MENU(task);

    if (d->prevFloor < d->cursor)
        gUnk_0300000E -= delta;
    else
        gUnk_0300000E += delta;
}

// Elevator_BuildFloorList @ 0x080B9F78
/* Lists the floors of the current map that have a type-3 record with the same id as
   rec (rec[2]); the current floor becomes the initial cursor. */
void Elevator_BuildFloorList(struct FloorMenu *d, const u16 *rec)
{
    u16 oldFloor = gUnk_03004514;
    u16 oldX = gFieldState.unk12;
    u16 oldY = gFieldState.unk14;
    u16 nFloors = sub_080C8B3C(gUnk_03004614);
    u32 f;
    u16 x, y;

    gUnk_03004514 = 0;
    gFieldState.unk12 = 0;
    gFieldState.unk14 = 0;
    for (f = 0; f < nFloors; f++)
    {
        sub_080AE234();
        for (y = 0; y < gFieldState.unk1C; y++)
        {
            for (x = 0; x < gFieldState.unk1A; x++)
            {
                u16 *r = FieldMap_FindRecord(FieldMap_CellRecordsOffset(x, y), 3);

                if (r != NULL && r[2] == rec[2])
                {
                    d->floors[d->count] = gUnk_03004514;
                    if (oldFloor == gUnk_03004514)
                        d->cursorInit = d->count;
                    d->count++;
                }
            }
        }
        gUnk_03004514++;
    }
    gUnk_03004514 = oldFloor;
    gFieldState.unk12 = oldX;
    gFieldState.unk14 = oldY;
    sub_080AE234();
}

// Elevator_Start @ 0x080BA070
/* Starts the elevator task for the elevator record of the current cell. */
void Elevator_Start(void)
{
    u16 *rec = FieldMap_GetElevatorRecord();
    struct FloorMenu *d;

    if (rec[1] <= 1)
        gUnk_03003FEC = Task_Create(gUnknown_08165694, 0xFFFF);
    else
        gUnk_03003FEC = Task_Create(gUnknown_08173594, 0xFFFF);
    d = FLOOR_MENU(gUnk_03003FEC);
    if (rec[1] == 2)
    {
        d->unk30 = 0;
        d->unk32 = 0x8000;
    }
    if (rec[2] > 0x7F)
    {
        d->useTable = 1;
        d->tableId = rec[2] & 0x7F;
    }
    else
    {
        Elevator_BuildFloorList(d, rec);
    }
    Field_SetState(0x1A);
}

// sub_080BA0E0 @ 0x080BA0E0
void sub_080BA0E0(u32 unused, u32 row, u32 slot)
{
    const void *src = gUnknown_08173488[row][slot];

    if (src != NULL)
        LZ77UnCompWram(src, gUnk_02001000 + slot * 0x1000);
    src = gUnknown_081734E8[row][slot];
    if (src != NULL)
        LZ77UnCompWram(src, (u8 *)0x02005000 + slot * 0x1000);
    if (slot == 3)
    {
        gUnk_0300000E = (u32)gUnknown_081734E8[row][4];
        CpuSet(gUnknown_08173560[row], gUnk_02000000, 0x04000400);
    }
}

// sub_080BA170 @ 0x080BA170
void sub_080BA170(void)
{
    DmaCopy32(3, (void *)0x02005000, (void *)0x06004000, 0x3400);
    DmaCopy32(3, gUnk_02000000, (void *)0x06003000, 0x1000);
}
