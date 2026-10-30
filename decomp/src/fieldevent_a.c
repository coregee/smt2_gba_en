/* Field task callbacks (map change, fall, door and step events). */

#include "global.h"
#include "fieldevent.h"

extern u8 gUnk_02005004[];

// sub_080B5CD8 @ 0x080B5CD8
void sub_080B5CD8(void)
{
    gFieldState.unk1E = 0x34;
}

// sub_080B5CE4 @ 0x080B5CE4
void sub_080B5CE4(void)
{
    MarkerHeader_DrawLocationName(0, 0, 0x12, 0x59, 0xC);
}

// sub_080B5D00 @ 0x080B5D00
void sub_080B5D00(void)
{
    Task_Create(gUnknown_08162C34, 0xFFFF);
}

// sub_080B5D18 @ 0x080B5D18
void sub_080B5D18(void)
{
    sub_080B31C4(gUnk_03004614, 10, gUnk_03004000[1]);
}

// sub_080B5D38 @ 0x080B5D38
void sub_080B5D38(void)
{
    sub_080B2840(0, 0, 0);
}

// sub_080B5D48 @ 0x080B5D48
/* Result 1 when the graphics of the map variant under the player are already loaded;
   otherwise starts loading them. */
void sub_080B5D48(struct Task *task)
{
    struct MapHeader *h = DungeonMap_GetFloor(gUnk_03004614, gUnk_03004514);
    u16 *rec;
    u16 r;

    gUnk_0300000E = 0;
    rec = FieldMap_FindRecord(FieldMap_CellRecordsRel(0, 0), 0x20);
    if (rec != NULL)
    {
        gGameState.unkA38 = rec[1];
        gUnk_03003BB4 = NULL;
    }
    if (gUnk_03003BB4 != h->variants[gGameState.unkA38].data[0x10])
    {
        Map_SetGraphicsPointers(gUnk_03004614, gUnk_03004514);
        sub_080AE234();
        sub_080AD7F0();
        r = 0;
    }
    else
    {
        r = 1;
    }
    task->result = r;
}

// sub_080B5DD8 @ 0x080B5DD8
void sub_080B5DD8(struct Task *task)
{
    u16 r;

    if (gFieldState.unk0E == 0)
    {
        sub_080AE494(sub_080B0158);
        r = 1;
    }
    else
    {
        r = 0;
    }
    task->result = r;
}

// sub_080B5E04 @ 0x080B5E04
void sub_080B5E04(void)
{
    Field_SetState(1);
}

// sub_080B5E10 @ 0x080B5E10
void sub_080B5E10(struct Task *task, u32 arg)
{
    if (arg == 1)
        Flag_Set(0x102);
    else
        Flag_Clear(0x102);
}

// sub_080B5E2C @ 0x080B5E2C
void sub_080B5E2C(void)
{
    if (FieldMap_FindRecord(FieldMap_CellRecordsRel(0, 0), 9) == NULL)
        Field_Step(gFieldState.unk02);
}

// sub_080B5E50 @ 0x080B5E50
void sub_080B5E50(void)
{
    gUnk_03003FEC = Task_Create(gUnknown_08162EAC, 0xFFFF);
    Field_SetState(0x1A);
}

// sub_080B5E74 @ 0x080B5E74
/* VBlank: copies the wall tiles from row gUnk_0300000E/8 on and clears the rows above. */
void sub_080B5E74(void)
{
    u32 off = (gUnk_0300000E >> 3) * 0x400;
    u8 *src = gUnk_02005004; /* symbol, not a cast address: keeps 0x3400 - off at run time */

    src += off;
    off = 0x3400 - off;
    if (off != 0)
    {
        DmaFill32(3, 0, (void *)0x06008800, 0x3400);
        DmaCopy32(3, src, (void *)0x06008800, off);
    }
}

// sub_080B5ED0 @ 0x080B5ED0
void sub_080B5ED0(void)
{
    sub_080AE494(sub_080B5E74);
    gUnk_0300000E += 8;
}

// sub_080B5EEC @ 0x080B5EEC
void sub_080B5EEC(void)
{
    Map_SetGraphicsPointers(gUnk_03004614, gUnk_03004514);
    sub_080AE234();
    sub_080AE294();
    sub_080B31C4(gUnk_03004614, 1, gUnk_03004000[2]);
}

// sub_080B5F24 @ 0x080B5F24
void sub_080B5F24(void)
{
    sub_080B2840(0, 0, 0);
    gUnk_0300000E = 0;
    gFieldLoadStep = 0;
}

// sub_080B5F48 @ 0x080B5F48
void sub_080B5F48(struct Task *task)
{
    VBlankTask_AddCounted(Field_LoadGraphicsStep, 1);
    if (gFieldLoadStep == 0xFFFF)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080B5F7C @ 0x080B5F7C
void sub_080B5F7C(struct Task *task)
{
    u16 r;

    if (gFieldState.unk0E == 0)
    {
        sub_080AE494(sub_080B0158);
        r = 1;
    }
    else
    {
        r = 0;
    }
    task->result = r;
}

// sub_080B5FA8 @ 0x080B5FA8
void sub_080B5FA8(void)
{
    Field_SetState(1);
}

// sub_080B5FB4 @ 0x080B5FB4
void sub_080B5FB4(void)
{
    if (FieldMap_FindRecord(FieldMap_CellRecordsRel(0, 0), 2) == NULL)
        Field_Step(gFieldState.unk02);
}

// sub_080B5FD8 @ 0x080B5FD8
void sub_080B5FD8(void)
{
    gUnk_03003FEC = Task_Create(gUnknown_08163060, 0xFFFF);
    Field_SetState(0x1A);
}

// sub_080B5FFC @ 0x080B5FFC
/* Spin: 0 turns the player (randomly, or as the floor's record says); otherwise turns back
   and reports 1 once the original facing is restored. */
void sub_080B5FFC(struct Task *task, u32 arg)
{
    if (arg == 0)
    {
        u16 dir = gFieldState.unk02;
        u16 v = gUnknown_08163250[Random_Next() & 3];

        if (gUnk_03004000[1] == 0)
        {
            dir = (dir + v) & 3;
            Sound_Play(0x72);
        }
        else
        {
            dir = gUnk_03004000[1] - 1;
            v = gUnknown_08163258[gFieldState.unk02][dir];
        }
        sub_080B2064(dir, v);
    }
    else
    {
        u16 r;

        if (gFieldState.unk02 != gFieldState.unk06)
        {
            sub_080B2064(gFieldState.unk06, gFieldState.unk08);
            r = 0;
        }
        else
        {
            r = 1;
        }
        task->result = r;
    }
}

// sub_080B6088 @ 0x080B6088
void sub_080B6088(struct Task *task)
{
    s32 r = sub_080B2090();

    task->result = 0;
    if (r != -1)
        task->result = 1;
}

// sub_080B60A4 @ 0x080B60A4
void sub_080B60A4(struct Task *task)
{
    s32 recs = FieldMap_CellRecordsRel(0, 0);
    u16 *a = FieldMap_FindRecord(recs, 0x19);
    u16 *b = FieldMap_FindRecord(recs, 0x14);

    if (a != NULL)
    {
        gFieldState.unk3A = 0;
        gFieldState.unk38 = 0x40;
        gFieldState.unk3C = 0;
        Field_HandleInput(gFieldState.unk38);
        task->result = 1;
    }
    else if (b != NULL)
    {
        gUnk_03003FEC = Treasure_StartTask((const struct TreasureRec *)b);
        Field_SetState(0x1A);
        task->result = 1;
    }
    else
    {
        task->result = 0;
    }
}

// sub_080B6104 @ 0x080B6104
void sub_080B6104(void)
{
    Field_SetState(1);
}

// sub_080B6110 @ 0x080B6110
void sub_080B6110(void)
{
    sub_080B2840(0, 0, 0);
}

// sub_080B6120 @ 0x080B6120
void sub_080B6120(struct Task *task)
{
    u16 r;

    if (gFieldState.unk0E == 0)
    {
        sub_080AE494(sub_080B0158);
        r = 1;
    }
    else
    {
        r = 0;
    }
    task->result = r;
}

// sub_080B614C @ 0x080B614C
void sub_080B614C(void)
{
    gUnk_03003FEC = Task_Create(gUnknown_08163278, 0xFFFF);
    Field_SetState(0x1A);
}
