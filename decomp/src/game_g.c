/* Field script-task callbacks (task, arg) used by the field event scripts. */

#include "global.h"
#include "game.h"

// sub_080B3644 @ 0x080B3644
void sub_080B3644(u8 *task, VoidFunc func)
{
    sub_080AE494(func);
}

// sub_080B3650 @ 0x080B3650
void sub_080B3650(u8 *task)
{
    if (gFieldState.unk0E != 0)
        *(u16 *)(task + 0x1C) = 0;
    else
        *(u16 *)(task + 0x1C) = 1;
}

// sub_080B366C @ 0x080B366C
void sub_080B366C(void)
{
    u32 r = FieldMap_HasRecordRel(0, 0xFFFF, 4);

    if (r == 1)
    {
        if (!Flag_Test(0xAE))
        {
            gUnk_0300452C = PalFade_FadeToBlack(1);
            gUnk_0200E7D4[0x1A] = r;
        }
        else
        {
            sub_080B0620();
        }
    }
    else
    {
        sub_080B0620();
    }
}

// sub_080B36B4 @ 0x080B36B4
void sub_080B36B4(u8 *task)
{
    struct MapHeader *map = sub_080C8B10(gUnk_03004614, gUnk_03004514);
    u32 *rec;
    u16 r;
    u16 *pal;

    gUnk_0300000E = 0;
    rec = FieldMap_FindRecord(FieldMap_CellRecordsRel(0, 0xFFFF), 0x20);
    if (rec != NULL)
    {
        gGameState.unkA38 = ((u16 *)rec)[1];
        gUnk_03003BB4 = 0;
    }
    if (gUnk_03003BB4 != (u32)map->variants[gGameState.unkA38].data[16]
        || gUnk_0300462C != (u32)map->variants[gGameState.unkA38].data[40])
    {
        Map_SetGraphicsPointers(gUnk_03004614, gUnk_03004514);
        sub_080AE234();
        sub_080AD7F0();
        r = 0;
    }
    else
    {
        Map_SetGraphicsPointers(gUnk_03004614, gUnk_03004514);
        sub_080AE234();
        pal = gUnk_03004630;
        gPaletteTarget[0] = *pal;
        Palette_CopyWithEffect(3, pal, &gPaletteTarget[0xE0], 0x40, 0x20);
        Palette_CopyWithEffect(3, gUnk_03004510, &gPaletteTarget[0xD0], 0x20, 0x20);
        r = 1;
    }
    *(u16 *)(task + 0x1C) = r;
}

// sub_080B37AC @ 0x080B37AC
void sub_080B37AC(u8 *task, u32 arg)
{
    u16 r;

    if (arg == 0)
    {
        gFieldLoadStep = 0;
        return;
    }
    if (gFieldLoadStep == 0xFFFF)
    {
        r = 1;
    }
    else
    {
        VBlankTask_AddCounted(Field_LoadGraphicsStep, 1);
        r = 0;
    }
    *(u16 *)(task + 0x1C) = r;
}

// sub_080B37F0 @ 0x080B37F0
void sub_080B37F0(u8 *task, u32 arg)
{
    Field_Step(gFieldState.unk02);
    if (arg == 0)
        sub_080B2840(0, 0, 0);
}

// sub_080B3814 @ 0x080B3814
void sub_080B3814(u8 *task, u32 arg)
{
    s32 r = sub_080AF8D0(1, 1, 0);

    if (r == 0)
    {
        sub_080AE494(sub_080B0158);
        sub_080B05A4();
        gFieldState.unk2E = r;
        Field_SetState(4);
        if (FieldMap_CellRecordsRel(0, 1) == NULL)
            gFieldState.unk46 = arg;
        else
            gFieldState.unk46 = 1;
    }
}

// sub_080B3868 @ 0x080B3868
void sub_080B3868(void)
{
    gFieldState.unk5E = 0;
}

// sub_080B3878 @ 0x080B3878
void *sub_080B3878(u16 a)
{
    const void *script = gUnknown_081625D0;
    void *task;

    if (a == 0)
        script = gUnknown_08162490;
    task = Task_Create(script, 0xFFFF);
    gFieldState.unk2E = 0;
    return task;
}
