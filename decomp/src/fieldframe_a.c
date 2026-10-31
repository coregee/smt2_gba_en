#include "global.h"
#include "field.h"

/* 8 bytes copied from the world-map location record to gGameState + 0x18C0. */
struct WorldPos
{
    u32 a, b;
};

struct FieldRec
{
    u16 kind;
    u16 arg;
    const void *scripts[1];
};

extern u16 gUnk_030031D0;
extern vu16 gKeysNew;
extern u16 gRepeatedKeys;
extern u32 gFrameCounter;
extern u8 gUnk_0300003C, gUnk_0300003D;
extern u16 gUnk_0300000C;
extern u16 gUnk_03004540;
extern u16 gUnk_03004534;
extern u32 gUnk_03003B98;
extern u32 gYesNoResult;
extern u16 gUnk_03003BA8;
extern u32 gUnk_03004628;
extern s8 gUnk_03003FC4, gUnk_03004618;
extern u16 gPaletteBuffer[];
extern void *gUnk_0300452C;
extern u8 gHudState[];
extern const u16 gUnknown_08163258[][4];
extern const u16 gUnknown_0815F31C[];
extern const u8 gUnknown_0804C354[], gUnknown_0804C564[], gUnknown_0804CB9C[];
extern const u8 gUnknown_08124DBC[], gUnknown_08124DD8[], gUnknown_08073A00[];

void Map_LoadGraphicsStep(u16 map, u16 floor);
void sub_080B0AE0(void);
void VBlankTask_AddCountedAlways(void (*func)(void), u32 count);
void sub_080B0ABC(void);
void sub_080B0B54(void);
void sub_080B0C38(void);
void sub_080B0C7C(void);
void sub_080B2064(u16 a, u16 b);
void Field_HandleInput(u16 keys);
u32 View_IsSideOpen(u16 dir);
void sub_080B09C4(u16 dx, u16 dy);
void Field_Step(u16 dir);
u16 PalFade_AllDone(void);
u32 Field_CheckCellEvents(u16 a, u16 b, u16 c);
void sub_080B03BC(u32 a);
void sub_080B0A08(u32 a);
u32 sub_080B2090(void);
s32 sub_080C2480(u16 id);
u32 sub_080C9100(void);
const void *sub_080AF85C(u32 kind, const u32 *ev);
u16 sub_080AF0AC(const void *script);
void sub_080B011C(u16 a);
void sub_080C2CD8(s32 a, s32 b, u32 c);
const u32 *WorldMap_FindLocationByWorldPos(u16 x, u16 y);
s32 sub_080B38A8(void);
u16 sub_080B1A1C(u16 dir);
void sub_080AE294(void);
void sub_080B31C4(u16 a, u16 b, u16 c);
u32 sub_080B092C(void);
void sub_080B2030(u16 a, u16 b, u16 c);
void Automap_Update(void);
void sub_080B05A4(void);
void sub_08128B84(u32 a);
void sub_0812D0FC(u32 a);
void sub_0812A730(void);
void Battle_StartRandomEncounter(void);
void *PalFade_FadeRangeToBlackWithDuration(u16 start, u16 count, u16 a, u16 b);
void *PalFade_FadeRangeWithDuration(u16 start, u16 count, u16 a, u16 b);
void *PalFade_FadeToBlack(u16 delay);
void sub_080B0888(void);
void sub_080C7218(void);
void sub_080C7414(void);
void Music_FadeOut(u32 a);
void sub_080B1A4C(u16 a, u32 b);
void sub_080AF280(void);
void sub_080B018C(void);
void sub_080B0158(void);
void Encounter_SetCounter(u32 a);
const u32 *FieldEvent_FindAt(u16 x, u16 y, u16 dir, u16 *flag);

#define fs gFieldState

/* Steps the blinking of one palette byte between 0x10 and 0x20+ every 16 frames. */
#define BLINK(value, dir)                       \
{                                               \
    if ((gFrameCounter & 0xF) == 0)             \
    {                                           \
        if (dir == 0)                           \
        {                                       \
            value += 0x10;                      \
            if (value > 0x20)                   \
                dir = 1;                        \
        }                                       \
        else                                    \
        {                                       \
            value -= 0x10;                      \
            if (value == 0x10)                  \
                dir = 0;                        \
        }                                       \
    }                                           \
}

/* One frame of the dungeon field: copies the keys, runs the map loader or the floor's
   per-frame hook, the palette effects of flags 0x102/0x106/0x108, then the state
   gFieldState.unk00 (1 input, 2 step forward, 4 turn, 5/8 side steps, 6 examine, 0xB-0xE
   stairs and exits, 0x13/0x14 battles, 0x16 leaving the map, ...). The sub-step counter is
   unk1E; walking animations count down to 0 then 0xFFFF and check events (Field_CheckCellEvents).
   The original reads several gFieldState fields before overwriting them (volatile).
   NONMATCHING: same states and calls; branch layout, register use and those volatile
   reads differ. */
// Field_UpdateFrame @ 0x080B0C90
#ifdef NONMATCHING
void Field_UpdateFrame(void)
{
    u16 n;
    u16 flag;
    u16 x, y, wx, wy;
    s32 r;
    s32 recs;
    const struct FieldRec *rec;
    const u32 *ev;
    const void *script;
    u32 kind;
    const u16 *m;

    {
        volatile struct FieldState *keys = &gFieldState;

        keys->unk38 = gUnk_030031D0;
        keys->unk3A = gKeysNew;
        keys->unk3C = gRepeatedKeys;
    }
    if (gUnk_03003FF8 != 0)
    {
        Map_LoadGraphicsStep(gUnk_03004614, gUnk_03004514);
        return;
    }
    if ((s32)gUnk_03004514 >= 0)
    {
        struct MapHeader *hdr = DungeonMap_GetFloor(gUnk_03004614, gUnk_03004514);
        void (*hook)(void) = (void (*)(void))hdr->variants[gGameState.unkA38].data[0x39];

        if (hook != NULL)
            hook();
        else
            Flag_Clear(0x108);
    }

    if (Flag_Test(0x102))
    {
        if (fs.unk48 == 0)
            fs.unk48 = 1;
        if (fs.unk48 == 1)
        {
            BLINK(gUnk_0300003C, fs.unk4A);
            sub_080B0AE0();
        }
        else
            VBlankTask_AddCountedAlways(sub_080B0ABC, 1);
    }
    else if (fs.unk48 != 0)
    {
        sub_080B0B54();
        fs.unk48 = 0;
    }
    if (Flag_Test(0x106))
    {
        if (fs.unk4C == 0)
            fs.unk4C = 1;
        if (fs.unk4C == 1)
            BLINK(gUnk_0300003D, fs.unk4E);
    }
    else
        fs.unk4C = 0;
    if (Flag_Test(0x108))
    {
        if (fs.unk50 == 0)
            fs.unk50 = 1;
        if (fs.unk50 == 1)
            sub_080B0C38();
        else
            sub_080B0C7C();
    }
    else if (fs.unk50 != 0)
    {
        sub_080B0C7C();
        fs.unk50 = 0;
    }

    switch (fs.unk00)
    {
    case 1:
        if (fs.unk34 == 1)
        {
            if (fs.unk36 != 0)
            {
                u16 i = fs.unk36 - 1;
                u16 v = gUnknown_08163258[fs.unk02][i];

                fs.unk36 = 0;
                sub_080B2064(i, v);
                Field_SetState(6);
                return;
            }
            /* scripted walk: as if UP were held */
            {
                volatile struct FieldState *keys = &gFieldState;

                keys->unk3A = 0;
                keys->unk38 = 0x40;
                keys->unk3C = 0;
            }
        }
        Field_HandleInput(fs.unk38);
        break;
    case 2:
        n = --fs.unk1E;
        if (n == fs.unk0A >> 1)
        {
            if (fs.unk0E != 0)
            {
                fs.unk1E = n + 1;
                break;
            }
            sub_080AE494(sub_080B018C);
            if (View_IsSideOpen(0) == 1)
                sub_080B09C4(0, 0xFFFF);
        }
        else if (fs.unk1E == (fs.unk0A >> 1) - 1)
        {
            if (View_IsSideOpen(0) == 1)
                Field_Step(fs.unk02);
            else
                Sound_Play(0x69);
            sub_080B2840(0, 0, 0);
        }
        else if (fs.unk1E == 0)
        {
            if (fs.unk0E != 0)
                fs.unk1E = 1;
            else
                sub_080AE494(sub_080B0158);
        }
        else if (fs.unk1E == 0xFFFF)
        {
            if (PalFade_AllDone() != 1)
            {
                fs.unk1E++;
                break;
            }
            if (Field_CheckCellEvents(1, 2, 0) == 0)
            {
                if (fs.unk46 == 1)
                    Field_SetState(1);
                else
                    sub_080B03BC(1);
                Music_Play(sub_080AD608(gUnk_03004614, gUnk_03004514));
            }
            fs.unk46 = 0;
        }
        break;
    case 4:
        sub_080B0A08(1);
        break;
    case 5:
        n = --fs.unk1E;
        if (n == 6)
        {
            if (fs.unk0E != 0)
                fs.unk1E = n + 1;
            else if ((s16)fs.unk08 == 1)
                sub_080AE494(sub_080B018C);
        }
        else if (n == 5)
            sub_080B2840(0, 0, 0);
        else if (n == 0)
        {
            if (fs.unk0E != 0)
                fs.unk1E = n + 1;
            else
                sub_080AE494(sub_080B0158);
        }
        else if (n == 0xFFFF)
        {
            if (PalFade_AllDone() != 1)
            {
                fs.unk1E++;
                break;
            }
            if (Field_CheckCellEvents(1, 2, 1) != 0)
                break;
            if (fs.unk44 == 1)
                Field_SetState(1);
            else
                sub_080B03BC(1);
            fs.unk44 = 0;
        }
        break;
    case 6:
        r = sub_080B2090();
        if (r == 1)
        {
            recs = FieldMap_CellRecordsRel(0, 0);
            rec = (const struct FieldRec *)FieldMap_FindRecord(recs, 0x1D);
            ev = FieldEvent_FindAt(fs.unk12, fs.unk14, fs.unk02, &flag);
            script = NULL;
            kind = 0;
            if (rec != NULL)
            {
                /* one script per facing direction */
                const struct FieldRec *r1A;

                {
                    u32 k = fs.unk02 * 4;
                    const void *const *s = rec->scripts;

                    script = *(const void **)((u32)s + k);
                }
                r1A = (const struct FieldRec *)FieldMap_FindRecord(recs, 0x1A);
                if (r1A != NULL)
                    sub_080B011C(r1A->arg);
            }
            else if (ev != NULL && flag != 0xFFFF && sub_080C2480(flag) != 1)
            {
                if ((const u8 *)ev[1] == gUnknown_08073A00)
                {
                    kind = sub_080C9100();
                    if (kind != 0)
                        script = sub_080AF85C(kind, ev);
                }
                else if (sub_080AF0AC((const void *)ev[1]) != 0)
                {
                    script = (const void *)ev[1];
                    sub_080C24B8(flag);
                    fs.unk3E = 1;
                    if (ScriptVM_RunAlt((const void *)ev[1]) == 2)
                        Flag_Set(0x10B);
                }
            }
            if (script != NULL)
            {
                if (kind == 0)
                    sub_080AF178(0xC, script);
            }
            else
            {
                Field_SetState(1);
                if (Door_TryOpen() == 1)
                    Field_SetState(0x1A);
            }
        }
        else if (r == 7)
            Field_SetState(7);
        break;
    case 7:
        sub_080B2064(fs.unk06, fs.unk08);
        Field_SetState(6);
        break;
    case 8:
        n = --fs.unk1E;
        if (n == 6)
        {
            if (fs.unk0E != 0)
            {
                fs.unk1E = n + 1;
                break;
            }
            sub_080AE494(sub_080B0158);
            if ((s16)fs.unk08 == 1)
            {
                gUnk_0300000C -= gUnk_03004540;
                if (View_IsSideOpen(1) == 1)
                    sub_080B09C4(1, 0);
            }
            else
            {
                gUnk_0300000C -= gUnk_03004540;
                if (View_IsSideOpen(3) == 1)
                    sub_080B09C4(0xFFFF, 0);
            }
        }
        else if (n == 5)
        {
            if ((s16)fs.unk08 == 1)
            {
                if (View_IsSideOpen(1) == 1)
                    Field_Step(fs.unk06);
                else
                    Sound_Play(0x69);
            }
            else if (View_IsSideOpen(3) == 1)
                Field_Step(fs.unk06);
            else
                Sound_Play(0x69);
            sub_080B2840(0, 0, 0);
        }
        else if (n == 0)
        {
            if (fs.unk0E != 0)
            {
                fs.unk1E = n + 1;
                break;
            }
            sub_080AE494(sub_080B0158);
            gUnk_0300000C = 0;
        }
        else if (n == 0xFFFF)
        {
            if (PalFade_AllDone() != 1)
            {
                fs.unk1E++;
                break;
            }
            if (Field_CheckCellEvents(1, 2, 1) == 0)
                sub_080B03BC(1);
        }
        break;
    case 0xB:
        if (Flag_Test(0xAE))
        {
            if (Flag_Test(0x5E))
                script = gUnknown_0804C354;
            else if (Flag_Test(0x5F))
                script = gUnknown_0804C564;
            else
                script = gUnknown_0804CB9C;
            sub_080AF178(0xC, script);
        }
        else
        {
            const s8 *loc = (const s8 *)gUnk_03004000;

            Encounter_SetCounter(0);
            sub_080C2CD8(loc[4], loc[6], 0);
            x = fs.unk12;
            y = fs.unk14 & 0x3F;
            switch (fs.unk02)
            {
            case 0:
                y++;
                break;
            case 1:
                x--;
                break;
            case 2:
                y--;
                break;
            case 3:
                x++;
                break;
            }
            sub_080C1F50(x, y, &wx, &wy);
            m = (const u16 *)WorldMap_FindLocationByWorldPos(wx, wy);
            *(struct WorldPos *)((u8 *)&gGameState + 0x18C0) = *(const struct WorldPos *)m;
        }
        break;
    case 0xC:
        sub_080B38A8();
        break;
    case 0xD:
    case 0x21:
        /* stairs up */
        if (gUnk_03004534 == 0x97 && Flag_Test(0x11))
            gUnk_03004534 += 2;
        r = sub_080B38A8();
        m = (const u16 *)gUnk_03004000;
        if (r == -1)
        {
            if (gUnk_0300460C == 0)
                break;
            fs.unk1E = 0;
            gUnk_03004514++;
            fs.unk02 = sub_080B1A1C(fs.unk02);
            sub_080AE234();
            sub_080AE294();
            sub_080B31C4(gUnk_03004614, gUnk_0300460C, gUnk_03003BA8);
        }
        else if (r == 1)
        {
            if (gUnk_03003B98 == 0)
            {
                if (fs.unk34 == 0)
                    sub_080AF178(fs.unk00, gUnknown_08124DBC);
                else
                    gYesNoResult = 0;
                gUnk_03003B98 = 1;
            }
            else if (gYesNoResult == 0)
            {
                sub_080B0820();
                Sound_Play(0x6E);
                if (fs.unk00 == 0xD)
                {
                    fs.unk1E++;
                    gUnk_0300460C = 2;
                    gUnk_03003BA8 = m[2];
                }
                else
                {
                    fs.unk1E++;
                    gUnk_0300460C = 0x1C;
                    gUnk_03003BA8 = m[3];
                    gUnk_03004614 = m[2];
                    gUnk_03004514 = -1;
                    fs.unk02 = sub_080B1A1C(m[4]);
                }
            }
            else
            {
                sub_080B0820();
                fs.unk1E++;
                gUnk_0300460C = 0;
            }
        }
        break;
    case 0xE:
    case 0x22:
        /* stairs down */
        if (gUnk_03004534 == 0x98 && Flag_Test(0x11))
            gUnk_03004534 += 2;
        r = sub_080B38A8();
        m = (const u16 *)gUnk_03004000;
        if (r == -1)
        {
            if (gUnk_0300460C == 0)
                break;
            fs.unk1E = 0;
            gUnk_03004514--;
            fs.unk02 = sub_080B1A1C(fs.unk02);
            sub_080AE234();
            sub_080AE294();
            sub_080B31C4(gUnk_03004614, gUnk_0300460C, gUnk_03003BA8);
        }
        else if (r == 1)
        {
            if (gUnk_03003B98 == 0)
            {
                if (fs.unk34 == 0)
                    sub_080AF178(fs.unk00, gUnknown_08124DD8);
                else
                    gYesNoResult = 0;
                gUnk_03003B98 = 1;
            }
            else if (gYesNoResult == 0)
            {
                sub_080B0820();
                Sound_Play(0x6E);
                if (fs.unk00 == 0xE)
                {
                    fs.unk1E++;
                    gUnk_0300460C = 1;
                    gUnk_03003BA8 = m[2];
                }
                else
                {
                    fs.unk1E++;
                    gUnk_0300460C = 0x1B;
                    gUnk_03003BA8 = m[3];
                    gUnk_03004614 = m[2];
                    gUnk_03004514 = 1;
                    fs.unk02 = sub_080B1A1C(m[4]);
                }
            }
            else
            {
                sub_080B0820();
                fs.unk1E++;
                gUnk_0300460C = 0;
            }
        }
        break;
    case 0xF:
        if (sub_080B092C() == 0)
        {
            sub_080AE234();
            sub_080B31C4(gUnk_03004614, gUnk_0300460C, gUnk_03003BA8);
            sub_080B2030(fs.unk0A, fs.unk02, 3);
        }
        break;
    case 0x10:
        Automap_Update();
        break;
    case 0x11:
        n = --fs.unk1E;
        if (n == 4)
        {
            if (fs.unk0E != 0)
                fs.unk1E = n + 1;
            else
                sub_080AE494(sub_080B018C);
        }
        else if (n == 3)
            sub_080B2840(0, 0, 0);
        else if (n == 0)
        {
            if (fs.unk0E != 0)
                fs.unk1E = n + 1;
            else
            {
                sub_080AE494(sub_080B0158);
                sub_080B05A4();
                fs.unk2E = 0;
                Field_SetState(0x12);
            }
        }
        break;
    case 0x12:
        if (sub_080B092C() == 0)
        {
            fs.unk2E = 0;
            if (fs.unk32 == 0)
                sub_080B03BC(1);
            else
            {
                sub_08128B84(4);
                Field_SetState(0xA);
            }
        }
        break;
    case 0x13:
        if (FieldMap_HasRecordRel(0, 0, 6) == 1)
        {
            gUnk_03003BB8 = 0;
            Battle_StartRandomEncounter();
            Field_SetState(0x15);
            break;
        }
        if (fs.unk1E == 0)
        {
            gUnk_0300452C = PalFade_FadeRangeToBlackWithDuration(0xD0, 0x30, 4, 4);
            if (gPaletteBuffer[0] != 0)
                PalFade_FadeRangeToBlackWithDuration(0, 1, 4, 4);
            fs.unk1E++;
        }
        else if (sub_080B092C() == 0)
        {
            gUnk_03003BB8 = 0;
            Battle_StartRandomEncounter();
            Field_SetState(0x15);
        }
        Music_FadeOut(1);
        break;
    case 0x14:
        gUnk_03003BB8 = 1;
        Battle_StartRandomEncounter();
        sub_080B0888();
        Field_SetState(0x15);
        sub_080C7218();
        sub_080C7414();
        Music_FadeOut(1);
        break;
    case 0x16:
        if (gUnk_03003BB8 == 0)
        {
            u16 dest = gUnknown_0815F31C[fs.unk02];

            if (FieldMap_HasRecordRel(0, 0, 6) == 1)
            {
                if (fs.unk44 == 1)
                    sub_080B1A4C(dest, 1);
                else
                    Field_SetState(1);
            }
            else if (fs.unk1E == 0)
            {
                gPaletteTarget[0] = gUnk_03004630[0];
                Palette_CopyWithEffect(3, gUnk_03004630, gPaletteTarget + 0xE0, 0x40, 0x20);
                Palette_CopyWithEffect(3, gUnk_03004510, gPaletteTarget + 0xD0, 0x20, 0x20);
                Palette_CopyWithEffect(3, gUnk_03003FC8, gPaletteTarget + 0x1D0, 0x20, 0x10);
                gUnk_0300452C = PalFade_FadeRangeWithDuration(0xD0, 0x30, 1, 0x10);
                if (gPaletteTarget[0] != 0)
                    PalFade_FadeRangeWithDuration(0, 1, 1, 0x10);
                fs.unk1E++;
            }
            else if (sub_080B092C() == 0)
            {
                if (fs.unk44 == 1)
                    sub_080B1A4C(dest, 1);
                else
                    Field_SetState(1);
            }
        }
        else if (fs.unk1E == 0)
        {
            *(u16 *)(gHudState + 0x34) = 1;
            gUnk_0300452C = PalFade_FadeToBlack(1);
            fs.unk1E++;
        }
        else if (sub_080B092C() == 0)
            sub_080C2CD8(gUnk_03003FC4, gUnk_03004618, 1);
        break;
    case 0x18:
        if (sub_080B38A8() == 1 && !(fs.unk3A & 1) && (fs.unk3A & 2))
        {
            sub_080B0820();
            fs.unk1E++;
            gUnk_0300460C = 0;
        }
        break;
    case 0x1B:
        if (fs.unk1E == 0)
        {
            if (gUnk_03004628 == 0)
                sub_08128B84(0);
            else if (gUnk_03004628 == 1)
                sub_0812D0FC(0);
            else
                sub_0812A730();
            fs.unk1E++;
        }
        break;
    case 0x1C:
        gUnk_03003BB8 = 1;
        sub_080AF280();
        sub_080C7218();
        sub_080C7414();
        break;
    case 0x1D:
    case 0x1E:
        if (fs.unk1E == 0)
        {
            *(u16 *)(gHudState + 0x34) = 1;
            gUnk_0300452C = PalFade_FadeToBlack(1);
            fs.unk1E++;
        }
        else if (sub_080B092C() == 0)
            sub_080C2CD8(gUnk_03003FC4, gUnk_03004618, 1);
        break;
    case 0x1F:
        if (fs.unk1E == 0)
        {
            if (fs.unk0E == 0)
            {
                sub_080AE494(sub_080B0158);
                fs.unk1E++;
            }
        }
        else if (fs.unk1E == 1)
        {
            sub_080B05A4();
            fs.unk1E++;
        }
        else
            sub_080B0A08(0);
        break;
    case 0x25:
        if (fs.unk1E == 0)
        {
            Task_Create((const u32 *)gUnk_03004628, 0xFFFF);
            fs.unk1E = 1;
        }
        break;
    }
    sub_080B2CC0();
}
#else
NAKED
void Field_UpdateFrame(void)
{
    asm_unified(
        ".L080B0C90:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0xc\n"
        "    ldr r1, .L080B0CD0\n"
        "    ldr r0, .L080B0CD4\n"
        "    ldrh r0, [r0]\n"
        "    ldrh r2, [r1, #0x38]\n"
        "    strh r0, [r1, #0x38]\n"
        "    ldr r0, .L080B0CD8\n"
        "    ldrh r0, [r0]\n"
        "    ldrh r2, [r1, #0x3a]\n"
        "    strh r0, [r1, #0x3a]\n"
        "    ldr r0, .L080B0CDC\n"
        "    ldrh r0, [r0]\n"
        "    ldrh r2, [r1, #0x3c]\n"
        "    strh r0, [r1, #0x3c]\n"
        "    ldr r2, .L080B0CE0\n"
        "    ldr r0, [r2]\n"
        "    cmp r0, #0\n"
        "    beq .L080B0CEC\n"
        "    ldr r0, .L080B0CE4\n"
        "    ldrh r0, [r0]\n"
        "    ldr r1, .L080B0CE8\n"
        "    ldrh r1, [r1]\n"
        "    bl Map_LoadGraphicsStep\n"
        "    bl .L080B1A0A\n"
        "    .byte 0x00, 0x00\n"
        ".L080B0CD0: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B0CD4: .4byte 0x030031D0 @ IWRAM+0x31D0\n"
        ".L080B0CD8: .4byte 0x030031B8 @ IWRAM+0x31B8\n"
        ".L080B0CDC: .4byte 0x03003964 @ IWRAM+0x3964\n"
        ".L080B0CE0: .4byte 0x03003FF8 @ IWRAM+0x3FF8\n"
        ".L080B0CE4: .4byte 0x03004614 @ IWRAM+0x4614\n"
        ".L080B0CE8: .4byte 0x03004514 @ IWRAM+0x4514\n"
        ".L080B0CEC:\n"
        "    ldr r0, .L080B0D20\n"
        "    ldr r1, [r0]\n"
        "    cmp r1, #0\n"
        "    blt .L080B0D38\n"
        "    ldr r0, .L080B0D24\n"
        "    ldrh r0, [r0]\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    bl DungeonMap_GetFloor\n"
        "    ldr r1, .L080B0D28\n"
        "    ldr r2, .L080B0D2C\n"
        "    adds r1, r1, r2\n"
        "    ldrh r2, [r1]\n"
        "    movs r1, #0xe8\n"
        "    muls r1, r2, r1\n"
        "    movs r3, #0xbe\n"
        "    lsls r3, r3, #1\n"
        "    adds r0, r0, r3\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    cmp r0, #0\n"
        "    beq .L080B0D30\n"
        "    bl _call_via_r0\n"
        "    b .L080B0D38\n"
        ".L080B0D20: .4byte 0x03004514 @ IWRAM+0x4514\n"
        ".L080B0D24: .4byte 0x03004614 @ IWRAM+0x4614\n"
        ".L080B0D28: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080B0D2C: .4byte 0x00000A38\n"
        ".L080B0D30:\n"
        "    movs r0, #0x84\n"
        "    lsls r0, r0, #1\n"
        "    bl Flag_Clear\n"
        ".L080B0D38:\n"
        "    movs r0, #0x81\n"
        "    lsls r0, r0, #1\n"
        "    bl Flag_Test\n"
        "    adds r4, r0, #0\n"
        "    cmp r4, #0\n"
        "    beq .L080B0DBC\n"
        "    ldr r3, .L080B0D84\n"
        "    adds r1, r3, #0\n"
        "    adds r1, #0x48\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #0\n"
        "    bne .L080B0D56\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        ".L080B0D56:\n"
        "    ldrh r4, [r1]\n"
        "    cmp r4, #1\n"
        "    bne .L080B0DAC\n"
        "    ldr r0, .L080B0D88\n"
        "    ldr r2, [r0]\n"
        "    movs r0, #0xf\n"
        "    ands r2, r0\n"
        "    cmp r2, #0\n"
        "    bne .L080B0DA2\n"
        "    adds r3, #0x4a\n"
        "    ldrh r0, [r3]\n"
        "    cmp r0, #0\n"
        "    bne .L080B0D90\n"
        "    ldr r1, .L080B0D8C\n"
        "    ldrb r0, [r1]\n"
        "    adds r0, #0x10\n"
        "    strb r0, [r1]\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #0x20\n"
        "    bls .L080B0DA2\n"
        "    strh r4, [r3]\n"
        "    b .L080B0DA2\n"
        ".L080B0D84: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B0D88: .4byte 0x030031BC @ IWRAM+0x31BC\n"
        ".L080B0D8C: .4byte 0x0300003C @ IWRAM+0x3C\n"
        ".L080B0D90:\n"
        "    ldr r1, .L080B0DA8\n"
        "    ldrb r0, [r1]\n"
        "    subs r0, #0x10\n"
        "    strb r0, [r1]\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #0x10\n"
        "    bne .L080B0DA2\n"
        "    strh r2, [r3]\n"
        ".L080B0DA2:\n"
        "    bl sub_080B0AE0\n"
        "    b .L080B0DCE\n"
        ".L080B0DA8: .4byte 0x0300003C @ IWRAM+0x3C\n"
        ".L080B0DAC:\n"
        "    ldr r0, .L080B0DB8\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCountedAlways\n"
        "    b .L080B0DCE\n"
        "    .byte 0x00, 0x00\n"
        ".L080B0DB8: .4byte sub_080B0ABC\n"
        ".L080B0DBC:\n"
        "    ldr r0, .L080B0E1C\n"
        "    adds r5, r0, #0\n"
        "    adds r5, #0x48\n"
        "    ldrh r0, [r5]\n"
        "    cmp r0, #0\n"
        "    beq .L080B0DCE\n"
        "    bl sub_080B0B54\n"
        "    strh r4, [r5]\n"
        ".L080B0DCE:\n"
        "    movs r0, #0x83\n"
        "    lsls r0, r0, #1\n"
        "    bl Flag_Test\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #0\n"
        "    beq .L080B0E40\n"
        "    ldr r3, .L080B0E1C\n"
        "    adds r1, r3, #0\n"
        "    adds r1, #0x4c\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #0\n"
        "    bne .L080B0DEC\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        ".L080B0DEC:\n"
        "    ldrh r4, [r1]\n"
        "    cmp r4, #1\n"
        "    bne .L080B0E46\n"
        "    ldr r0, .L080B0E20\n"
        "    ldr r2, [r0]\n"
        "    movs r0, #0xf\n"
        "    ands r2, r0\n"
        "    cmp r2, #0\n"
        "    bne .L080B0E46\n"
        "    adds r3, #0x4e\n"
        "    ldrh r0, [r3]\n"
        "    cmp r0, #0\n"
        "    bne .L080B0E28\n"
        "    ldr r1, .L080B0E24\n"
        "    ldrb r0, [r1]\n"
        "    adds r0, #0x10\n"
        "    strb r0, [r1]\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #0x20\n"
        "    bls .L080B0E46\n"
        "    strh r4, [r3]\n"
        "    b .L080B0E46\n"
        "    .byte 0x00, 0x00\n"
        ".L080B0E1C: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B0E20: .4byte 0x030031BC @ IWRAM+0x31BC\n"
        ".L080B0E24: .4byte 0x0300003D @ IWRAM+0x3D\n"
        ".L080B0E28:\n"
        "    ldr r1, .L080B0E3C\n"
        "    ldrb r0, [r1]\n"
        "    subs r0, #0x10\n"
        "    strb r0, [r1]\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #0x10\n"
        "    bne .L080B0E46\n"
        "    strh r2, [r3]\n"
        "    b .L080B0E46\n"
        ".L080B0E3C: .4byte 0x0300003D @ IWRAM+0x3D\n"
        ".L080B0E40:\n"
        "    ldr r0, .L080B0E70\n"
        "    adds r0, #0x4c\n"
        "    strh r1, [r0]\n"
        ".L080B0E46:\n"
        "    movs r0, #0x84\n"
        "    lsls r0, r0, #1\n"
        "    bl Flag_Test\n"
        "    adds r4, r0, #0\n"
        "    cmp r4, #0\n"
        "    beq .L080B0E7A\n"
        "    ldr r0, .L080B0E70\n"
        "    adds r1, r0, #0\n"
        "    adds r1, #0x50\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #0\n"
        "    bne .L080B0E64\n"
        "    movs r0, #1\n"
        "    strh r0, [r1]\n"
        ".L080B0E64:\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #1\n"
        "    bne .L080B0E74\n"
        "    bl sub_080B0C38\n"
        "    b .L080B0E8C\n"
        ".L080B0E70: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B0E74:\n"
        "    bl sub_080B0C7C\n"
        "    b .L080B0E8C\n"
        ".L080B0E7A:\n"
        "    ldr r0, .L080B0EA8\n"
        "    adds r5, r0, #0\n"
        "    adds r5, #0x50\n"
        "    ldrh r0, [r5]\n"
        "    cmp r0, #0\n"
        "    beq .L080B0E8C\n"
        "    bl sub_080B0C7C\n"
        "    strh r4, [r5]\n"
        ".L080B0E8C:\n"
        "    ldr r1, .L080B0EA8\n"
        "    ldrh r0, [r1]\n"
        "    subs r0, #1\n"
        "    adds r5, r1, #0\n"
        "    cmp r0, #0x24\n"
        "    bls .L080B0E9C\n"
        "    bl .L080B1A06\n"
        ".L080B0E9C:\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L080B0EAC\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080B0EA8: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B0EAC: .4byte gUnknown_080B0EB0\n"
        "    .global gUnknown_080B0EB0\n"
        "gUnknown_080B0EB0:\n"
        ".L080B0EB0: @ jump table\n"
        "    .4byte .L080B0F44\n"
        "    .4byte .L080B0F94\n"
        "    .4byte .L080B1A06\n"
        "    .4byte .L080B1078\n"
        "    .4byte .L080B1082\n"
        "    .4byte .L080B1124\n"
        "    .4byte .L080B1242\n"
        "    .4byte .L080B1254\n"
        "    .4byte .L080B1A06\n"
        "    .4byte .L080B1A06\n"
        "    .4byte .L080B1354\n"
        "    .4byte .L080B1420\n"
        "    .4byte .L080B1426\n"
        "    .4byte .L080B14EC\n"
        "    .4byte .L080B1644\n"
        "    .4byte .L080B1680\n"
        "    .4byte .L080B1686\n"
        "    .4byte .L080B16E0\n"
        "    .4byte .L080B1712\n"
        "    .4byte .L080B1798\n"
        "    .4byte .L080B1A06\n"
        "    .4byte .L080B17C0\n"
        "    .4byte .L080B1A06\n"
        "    .4byte .L080B18D0\n"
        "    .4byte .L080B1A06\n"
        "    .4byte .L080B1A06\n"
        "    .4byte .L080B1930\n"
        "    .4byte .L080B196C\n"
        "    .4byte .L080B1984\n"
        "    .4byte .L080B1984\n"
        "    .4byte .L080B19D0\n"
        "    .4byte .L080B1A06\n"
        "    .4byte .L080B1426\n"
        "    .4byte .L080B14EC\n"
        "    .4byte .L080B1A06\n"
        "    .4byte .L080B1A06\n"
        "    .4byte .L080B1910\n"
        ".L080B0F44:\n"
        "    ldrh r0, [r5, #0x34]\n"
        "    cmp r0, #1\n"
        "    bne .L080B0F8A\n"
        "    ldrh r0, [r5, #0x36]\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #0\n"
        "    beq .L080B0F7C\n"
        "    subs r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    ldr r3, .L080B0F78\n"
        "    lsls r2, r0, #1\n"
        "    ldrh r1, [r5, #2]\n"
        "    lsls r1, r1, #3\n"
        "    adds r2, r2, r1\n"
        "    adds r2, r2, r3\n"
        "    ldrh r1, [r2]\n"
        "    movs r2, #0\n"
        "    strh r2, [r5, #0x36]\n"
        "    bl sub_080B2064\n"
        "    movs r0, #6\n"
        "    bl Field_SetState\n"
        "    bl .L080B1A0A\n"
        ".L080B0F78: .4byte gUnknown_08163258\n"
        ".L080B0F7C:\n"
        "    ldrh r0, [r5, #0x3a]\n"
        "    strh r1, [r5, #0x3a]\n"
        "    ldrh r0, [r5, #0x38]\n"
        "    movs r0, #0x40\n"
        "    strh r0, [r5, #0x38]\n"
        "    ldrh r0, [r5, #0x3c]\n"
        "    strh r1, [r5, #0x3c]\n"
        ".L080B0F8A:\n"
        "    ldrh r0, [r5, #0x38]\n"
        "    bl Field_HandleInput\n"
        "    bl .L080B1A06\n"
        ".L080B0F94:\n"
        "    ldrh r2, [r5, #0x1e]\n"
        "    subs r0, r2, #1\n"
        "    strh r0, [r5, #0x1e]\n"
        "    ldrh r1, [r5, #0xa]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    lsrs r1, r1, #1\n"
        "    cmp r0, r1\n"
        "    bne .L080B0FD8\n"
        "    ldrh r0, [r5, #0xe]\n"
        "    cmp r0, #0\n"
        "    beq .L080B0FAE\n"
        "    b .L080B10C4\n"
        ".L080B0FAE:\n"
        "    ldr r0, .L080B0FD0\n"
        "    bl sub_080AE494\n"
        "    movs r0, #0\n"
        "    bl View_IsSideOpen\n"
        "    cmp r0, #1\n"
        "    beq .L080B0FC2\n"
        "    bl .L080B1A06\n"
        ".L080B0FC2:\n"
        "    ldr r1, .L080B0FD4\n"
        "    movs r0, #0\n"
        "    bl sub_080B09C4\n"
        "    bl .L080B1A06\n"
        "    .byte 0x00, 0x00\n"
        ".L080B0FD0: .4byte sub_080B018C\n"
        ".L080B0FD4: .4byte 0x0000FFFF\n"
        ".L080B0FD8:\n"
        "    ldrh r2, [r5, #0x1e]\n"
        "    subs r0, r1, #1\n"
        "    cmp r2, r0\n"
        "    bne .L080B0FFA\n"
        "    movs r0, #0\n"
        "    bl View_IsSideOpen\n"
        "    cmp r0, #1\n"
        "    bne .L080B0FF2\n"
        "    ldrh r0, [r5, #2]\n"
        "    bl Field_Step\n"
        "    b .L080B16AC\n"
        ".L080B0FF2:\n"
        "    movs r0, #0x69\n"
        "    bl Sound_Play\n"
        "    b .L080B16AC\n"
        ".L080B0FFA:\n"
        "    adds r1, r2, #0\n"
        "    cmp r1, #0\n"
        "    bne .L080B100E\n"
        "    ldrh r0, [r5, #0xe]\n"
        "    cmp r0, #0\n"
        "    beq .L080B10B4\n"
        "    adds r0, r2, #1\n"
        "    strh r0, [r5, #0x1e]\n"
        "    bl .L080B1A06\n"
        ".L080B100E:\n"
        "    ldr r0, .L080B1048\n"
        "    cmp r1, r0\n"
        "    beq .L080B1018\n"
        "    bl .L080B1A06\n"
        ".L080B1018:\n"
        "    bl PalFade_AllDone\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    beq .L080B1028\n"
        "    bl .L080B19F8\n"
        ".L080B1028:\n"
        "    movs r0, #1\n"
        "    movs r1, #2\n"
        "    movs r2, #0\n"
        "    bl Field_CheckCellEvents\n"
        "    cmp r0, #0\n"
        "    bne .L080B1066\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x46\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #1\n"
        "    bne .L080B104C\n"
        "    movs r0, #1\n"
        "    bl Field_SetState\n"
        "    b .L080B1052\n"
        ".L080B1048: .4byte 0x0000FFFF\n"
        ".L080B104C:\n"
        "    movs r0, #1\n"
        "    bl sub_080B03BC\n"
        ".L080B1052:\n"
        "    ldr r0, .L080B106C\n"
        "    ldrh r0, [r0]\n"
        "    ldr r1, .L080B1070\n"
        "    ldrh r1, [r1]\n"
        "    bl sub_080AD608\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Music_Play\n"
        ".L080B1066:\n"
        "    ldr r0, .L080B1074\n"
        "    adds r0, #0x46\n"
        "    b .L080B1116\n"
        ".L080B106C: .4byte 0x03004614 @ IWRAM+0x4614\n"
        ".L080B1070: .4byte 0x03004514 @ IWRAM+0x4514\n"
        ".L080B1074: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B1078:\n"
        "    movs r0, #1\n"
        "    bl sub_080B0A08\n"
        "    bl .L080B1A06\n"
        ".L080B1082:\n"
        "    ldrh r2, [r5, #0x1e]\n"
        "    subs r0, r2, #1\n"
        "    strh r0, [r5, #0x1e]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    cmp r1, #6\n"
        "    bne .L080B10A4\n"
        "    ldrh r0, [r5, #0xe]\n"
        "    cmp r0, #0\n"
        "    bne .L080B10C4\n"
        "    movs r1, #8\n"
        "    ldrsh r0, [r5, r1]\n"
        "    cmp r0, #1\n"
        "    beq .L080B10A2\n"
        "    bl .L080B1A06\n"
        ".L080B10A2:\n"
        "    b .L080B169A\n"
        ".L080B10A4:\n"
        "    cmp r1, #5\n"
        "    bne .L080B10AA\n"
        "    b .L080B16AC\n"
        ".L080B10AA:\n"
        "    cmp r1, #0\n"
        "    bne .L080B10CA\n"
        "    ldrh r0, [r5, #0xe]\n"
        "    cmp r0, #0\n"
        "    bne .L080B10C4\n"
        ".L080B10B4:\n"
        "    ldr r0, .L080B10C0\n"
        "    bl sub_080AE494\n"
        "    bl .L080B1A06\n"
        "    .byte 0x00, 0x00\n"
        ".L080B10C0: .4byte sub_080B0158\n"
        ".L080B10C4:\n"
        "    strh r2, [r5, #0x1e]\n"
        "    bl .L080B1A06\n"
        ".L080B10CA:\n"
        "    ldr r0, .L080B1108\n"
        "    cmp r1, r0\n"
        "    beq .L080B10D4\n"
        "    bl .L080B1A06\n"
        ".L080B10D4:\n"
        "    bl PalFade_AllDone\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    beq .L080B10E4\n"
        "    bl .L080B19F8\n"
        ".L080B10E4:\n"
        "    movs r0, #1\n"
        "    movs r1, #2\n"
        "    movs r2, #1\n"
        "    bl Field_CheckCellEvents\n"
        "    cmp r0, #0\n"
        "    beq .L080B10F6\n"
        "    bl .L080B1A06\n"
        ".L080B10F6:\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x44\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #1\n"
        "    bne .L080B110C\n"
        "    movs r0, #1\n"
        "    bl Field_SetState\n"
        "    b .L080B1112\n"
        ".L080B1108: .4byte 0x0000FFFF\n"
        ".L080B110C:\n"
        "    movs r0, #1\n"
        "    bl sub_080B03BC\n"
        ".L080B1112:\n"
        "    ldr r0, .L080B1120\n"
        "    adds r0, #0x44\n"
        ".L080B1116:\n"
        "    movs r1, #0\n"
        "    strh r1, [r0]\n"
        "    bl .L080B1A06\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1120: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B1124:\n"
        "    bl sub_080B2090\n"
        "    adds r6, r0, #0\n"
        "    cmp r6, #1\n"
        "    beq .L080B1130\n"
        "    b .L080B1230\n"
        ".L080B1130:\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    bl FieldMap_CellRecordsRel\n"
        "    adds r7, r0, #0\n"
        "    movs r1, #0x1d\n"
        "    bl FieldMap_FindRecord\n"
        "    adds r5, r0, #0\n"
        "    ldr r2, .L080B1180\n"
        "    mov r8, r2\n"
        "    ldrh r0, [r2, #0x12]\n"
        "    ldrh r1, [r2, #0x14]\n"
        "    ldrh r2, [r2, #2]\n"
        "    add r3, sp, #4\n"
        "    bl FieldEvent_FindAt\n"
        "    adds r4, r0, #0\n"
        "    movs r3, #0\n"
        "    mov sb, r3\n"
        "    mov sl, r3\n"
        "    cmp r5, #0\n"
        "    beq .L080B1184\n"
        "    mov r0, r8\n"
        "    ldrh r1, [r0, #2]\n"
        "    lsls r1, r1, #2\n"
        "    adds r0, r5, #4\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov sb, r0\n"
        "    adds r0, r7, #0\n"
        "    movs r1, #0x1a\n"
        "    bl FieldMap_FindRecord\n"
        "    cmp r0, #0\n"
        "    beq .L080B11F4\n"
        "    ldrh r0, [r0, #2]\n"
        "    bl sub_080B011C\n"
        "    b .L080B11F4\n"
        ".L080B1180: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B1184:\n"
        "    cmp r4, #0\n"
        "    beq .L080B11F4\n"
        "    add r0, sp, #4\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L080B11BC\n"
        "    cmp r1, r0\n"
        "    beq .L080B11F4\n"
        "    add r0, sp, #4\n"
        "    ldrh r0, [r0]\n"
        "    bl sub_080C2480\n"
        "    cmp r0, #1\n"
        "    beq .L080B11F4\n"
        "    ldr r1, [r4, #4]\n"
        "    ldr r0, .L080B11C0\n"
        "    cmp r1, r0\n"
        "    bne .L080B11C4\n"
        "    bl sub_080C9100\n"
        "    mov sl, r0\n"
        "    cmp r0, #0\n"
        "    beq .L080B11F4\n"
        "    adds r1, r4, #0\n"
        "    bl sub_080AF85C\n"
        "    mov sb, r0\n"
        "    b .L080B11F4\n"
        "    .byte 0x00, 0x00\n"
        ".L080B11BC: .4byte 0x0000FFFF\n"
        ".L080B11C0: .4byte gUnknown_08073A00\n"
        ".L080B11C4:\n"
        "    adds r0, r1, #0\n"
        "    bl sub_080AF0AC\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    beq .L080B11F4\n"
        "    ldr r1, [r4, #4]\n"
        "    mov sb, r1\n"
        "    add r0, sp, #4\n"
        "    ldrh r0, [r0]\n"
        "    bl sub_080C24B8\n"
        "    mov r2, r8\n"
        "    strh r6, [r2, #0x3e]\n"
        "    ldr r0, [r4, #4]\n"
        "    bl ScriptVM_RunAlt\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    cmp r0, #2\n"
        "    bne .L080B11F4\n"
        "    ldr r0, .L080B1210\n"
        "    bl Flag_Set\n"
        ".L080B11F4:\n"
        "    mov r3, sb\n"
        "    cmp r3, #0\n"
        "    beq .L080B1214\n"
        "    mov r0, sl\n"
        "    cmp r0, #0\n"
        "    beq .L080B1204\n"
        "    bl .L080B1A06\n"
        ".L080B1204:\n"
        "    movs r0, #0xc\n"
        "    mov r1, sb\n"
        "    bl sub_080AF178\n"
        "    bl .L080B1A06\n"
        ".L080B1210: .4byte 0x0000010B\n"
        ".L080B1214:\n"
        "    movs r0, #1\n"
        "    bl Field_SetState\n"
        "    bl Door_TryOpen\n"
        "    cmp r0, #1\n"
        "    beq .L080B1226\n"
        "    bl .L080B1A06\n"
        ".L080B1226:\n"
        "    movs r0, #0x1a\n"
        "    bl Field_SetState\n"
        "    bl .L080B1A06\n"
        ".L080B1230:\n"
        "    cmp r6, #7\n"
        "    beq .L080B1238\n"
        "    bl .L080B1A06\n"
        ".L080B1238:\n"
        "    movs r0, #7\n"
        "    bl Field_SetState\n"
        "    bl .L080B1A06\n"
        ".L080B1242:\n"
        "    ldrh r0, [r5, #6]\n"
        "    ldrh r1, [r5, #8]\n"
        "    bl sub_080B2064\n"
        "    movs r0, #6\n"
        "    bl Field_SetState\n"
        "    bl .L080B1A06\n"
        ".L080B1254:\n"
        "    ldrh r1, [r5, #0x1e]\n"
        "    subs r0, r1, #1\n"
        "    strh r0, [r5, #0x1e]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, #6\n"
        "    bne .L080B12D0\n"
        "    ldrh r0, [r5, #0xe]\n"
        "    cmp r0, #0\n"
        "    beq .L080B126A\n"
        "    b .L080B16DC\n"
        ".L080B126A:\n"
        "    ldr r0, .L080B1294\n"
        "    bl sub_080AE494\n"
        "    movs r1, #8\n"
        "    ldrsh r0, [r5, r1]\n"
        "    cmp r0, #1\n"
        "    bne .L080B12A0\n"
        "    ldr r2, .L080B1298\n"
        "    ldr r1, .L080B129C\n"
        "    ldrh r0, [r2]\n"
        "    ldrh r1, [r1]\n"
        "    subs r0, r0, r1\n"
        "    strh r0, [r2]\n"
        "    movs r0, #1\n"
        "    bl View_IsSideOpen\n"
        "    cmp r0, #1\n"
        "    beq .L080B1290\n"
        "    b .L080B1A06\n"
        ".L080B1290:\n"
        "    movs r0, #1\n"
        "    b .L080B12BA\n"
        ".L080B1294: .4byte sub_080B0158\n"
        ".L080B1298: .4byte 0x0300000C @ IWRAM+0xC\n"
        ".L080B129C: .4byte 0x03004540 @ IWRAM+0x4540\n"
        ".L080B12A0:\n"
        "    ldr r2, .L080B12C4\n"
        "    ldr r1, .L080B12C8\n"
        "    ldrh r0, [r2]\n"
        "    ldrh r1, [r1]\n"
        "    subs r0, r0, r1\n"
        "    strh r0, [r2]\n"
        "    movs r0, #3\n"
        "    bl View_IsSideOpen\n"
        "    cmp r0, #1\n"
        "    beq .L080B12B8\n"
        "    b .L080B1A06\n"
        ".L080B12B8:\n"
        "    ldr r0, .L080B12CC\n"
        ".L080B12BA:\n"
        "    movs r1, #0\n"
        "    bl sub_080B09C4\n"
        "    b .L080B1A06\n"
        "    .byte 0x00, 0x00\n"
        ".L080B12C4: .4byte 0x0300000C @ IWRAM+0xC\n"
        ".L080B12C8: .4byte 0x03004540 @ IWRAM+0x4540\n"
        ".L080B12CC: .4byte 0x0000FFFF\n"
        ".L080B12D0:\n"
        "    cmp r4, #5\n"
        "    bne .L080B1308\n"
        "    movs r2, #8\n"
        "    ldrsh r0, [r5, r2]\n"
        "    cmp r0, #1\n"
        "    bne .L080B12EE\n"
        "    movs r0, #1\n"
        "    bl View_IsSideOpen\n"
        "    cmp r0, #1\n"
        "    beq .L080B12F8\n"
        "    movs r0, #0x69\n"
        "    bl Sound_Play\n"
        "    b .L080B16AC\n"
        ".L080B12EE:\n"
        "    movs r0, #3\n"
        "    bl View_IsSideOpen\n"
        "    cmp r0, #1\n"
        "    bne .L080B1300\n"
        ".L080B12F8:\n"
        "    ldrh r0, [r5, #6]\n"
        "    bl Field_Step\n"
        "    b .L080B16AC\n"
        ".L080B1300:\n"
        "    movs r0, #0x69\n"
        "    bl Sound_Play\n"
        "    b .L080B16AC\n"
        ".L080B1308:\n"
        "    cmp r4, #0\n"
        "    bne .L080B1328\n"
        "    ldrh r0, [r5, #0xe]\n"
        "    cmp r0, #0\n"
        "    beq .L080B1314\n"
        "    b .L080B16DC\n"
        ".L080B1314:\n"
        "    ldr r0, .L080B1320\n"
        "    bl sub_080AE494\n"
        "    ldr r0, .L080B1324\n"
        "    strh r4, [r0]\n"
        "    b .L080B1A06\n"
        ".L080B1320: .4byte sub_080B0158\n"
        ".L080B1324: .4byte 0x0300000C @ IWRAM+0xC\n"
        ".L080B1328:\n"
        "    ldr r0, .L080B1350\n"
        "    cmp r4, r0\n"
        "    beq .L080B1330\n"
        "    b .L080B1A06\n"
        ".L080B1330:\n"
        "    bl PalFade_AllDone\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    beq .L080B133E\n"
        "    b .L080B19F8\n"
        ".L080B133E:\n"
        "    movs r0, #1\n"
        "    movs r1, #2\n"
        "    movs r2, #1\n"
        "    bl Field_CheckCellEvents\n"
        "    cmp r0, #0\n"
        "    beq .L080B134E\n"
        "    b .L080B1A06\n"
        ".L080B134E:\n"
        "    b .L080B16F6\n"
        ".L080B1350: .4byte 0x0000FFFF\n"
        ".L080B1354:\n"
        "    movs r0, #0xae\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    beq .L080B1394\n"
        "    movs r0, #0x5e\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    beq .L080B1370\n"
        "    ldr r1, .L080B136C\n"
        "    b .L080B1386\n"
        ".L080B136C: .4byte gUnknown_0804C354\n"
        ".L080B1370:\n"
        "    movs r0, #0x5f\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    beq .L080B1384\n"
        "    ldr r1, .L080B1380\n"
        "    b .L080B1386\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1380: .4byte gUnknown_0804C564\n"
        ".L080B1384:\n"
        "    ldr r1, .L080B1390\n"
        ".L080B1386:\n"
        "    movs r0, #0xc\n"
        "    bl sub_080AF178\n"
        "    b .L080B1A06\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1390: .4byte gUnknown_0804CB9C\n"
        ".L080B1394:\n"
        "    ldr r0, .L080B13C8\n"
        "    ldr r4, [r0]\n"
        "    movs r0, #0\n"
        "    bl Encounter_SetCounter\n"
        "    movs r0, #4\n"
        "    ldrsb r0, [r4, r0]\n"
        "    movs r1, #6\n"
        "    ldrsb r1, [r4, r1]\n"
        "    movs r2, #0\n"
        "    bl sub_080C2CD8\n"
        "    ldr r0, .L080B13CC\n"
        "    ldrh r3, [r0, #0x12]\n"
        "    ldrh r1, [r0, #0x14]\n"
        "    movs r2, #0x3f\n"
        "    ands r2, r1\n"
        "    ldrh r0, [r0, #2]\n"
        "    cmp r0, #1\n"
        "    beq .L080B13DE\n"
        "    cmp r0, #1\n"
        "    bgt .L080B13D0\n"
        "    cmp r0, #0\n"
        "    beq .L080B13DA\n"
        "    b .L080B13F0\n"
        "    .byte 0x00, 0x00\n"
        ".L080B13C8: .4byte 0x03004000 @ IWRAM+0x4000\n"
        ".L080B13CC: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B13D0:\n"
        "    cmp r0, #2\n"
        "    beq .L080B13E2\n"
        "    cmp r0, #3\n"
        "    beq .L080B13EA\n"
        "    b .L080B13F0\n"
        ".L080B13DA:\n"
        "    adds r0, r2, #1\n"
        "    b .L080B13E4\n"
        ".L080B13DE:\n"
        "    subs r0, r3, #1\n"
        "    b .L080B13EC\n"
        ".L080B13E2:\n"
        "    subs r0, r2, #1\n"
        ".L080B13E4:\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    b .L080B13F0\n"
        ".L080B13EA:\n"
        "    adds r0, r3, #1\n"
        ".L080B13EC:\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        ".L080B13F0:\n"
        "    mov r4, sp\n"
        "    adds r4, #6\n"
        "    add r5, sp, #8\n"
        "    adds r0, r3, #0\n"
        "    adds r1, r2, #0\n"
        "    adds r2, r4, #0\n"
        "    adds r3, r5, #0\n"
        "    bl sub_080C1F50\n"
        "    ldrh r0, [r4]\n"
        "    ldrh r1, [r5]\n"
        "    bl WorldMap_FindLocationByWorldPos\n"
        "    ldr r2, .L080B141C\n"
        "    movs r3, #0xc6\n"
        "    lsls r3, r3, #5\n"
        "    adds r2, r2, r3\n"
        "    ldr r1, [r0, #4]\n"
        "    ldr r0, [r0]\n"
        "    str r0, [r2]\n"
        "    str r1, [r2, #4]\n"
        "    b .L080B1A06\n"
        ".L080B141C: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080B1420:\n"
        "    bl sub_080B38A8\n"
        "    b .L080B1A06\n"
        ".L080B1426:\n"
        "    ldr r4, .L080B1464\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #0x97\n"
        "    bne .L080B143E\n"
        "    movs r0, #0x11\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    beq .L080B143E\n"
        "    ldrh r0, [r4]\n"
        "    adds r0, #2\n"
        "    strh r0, [r4]\n"
        ".L080B143E:\n"
        "    bl sub_080B38A8\n"
        "    movs r5, #1\n"
        "    rsbs r5, r5, #0\n"
        "    cmp r0, r5\n"
        "    bne .L080B1474\n"
        "    ldr r5, .L080B1468\n"
        "    ldrh r0, [r5]\n"
        "    cmp r0, #0\n"
        "    bne .L080B1454\n"
        "    b .L080B1A06\n"
        ".L080B1454:\n"
        "    ldr r4, .L080B146C\n"
        "    movs r0, #0\n"
        "    strh r0, [r4, #0x1e]\n"
        "    ldr r1, .L080B1470\n"
        "    ldr r0, [r1]\n"
        "    adds r0, #1\n"
        "    b .L080B1528\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1464: .4byte 0x03004534 @ IWRAM+0x4534\n"
        ".L080B1468: .4byte 0x0300460C @ IWRAM+0x460C\n"
        ".L080B146C: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B1470: .4byte 0x03004514 @ IWRAM+0x4514\n"
        ".L080B1474:\n"
        "    cmp r0, #1\n"
        "    beq .L080B147A\n"
        "    b .L080B1A06\n"
        ".L080B147A:\n"
        "    ldr r0, .L080B1498\n"
        "    ldr r1, [r0]\n"
        "    cmp r1, #0\n"
        "    bne .L080B14A4\n"
        "    ldr r2, .L080B149C\n"
        "    ldrh r0, [r2, #0x34]\n"
        "    cmp r0, #0\n"
        "    beq .L080B148C\n"
        "    b .L080B1590\n"
        ".L080B148C:\n"
        "    ldrh r0, [r2]\n"
        "    ldr r1, .L080B14A0\n"
        "    bl sub_080AF178\n"
        "    b .L080B1594\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1498: .4byte 0x03003B98 @ IWRAM+0x3B98\n"
        ".L080B149C: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B14A0: .4byte gUnknown_08124DBC\n"
        ".L080B14A4:\n"
        "    ldr r0, .L080B14D0\n"
        "    ldr r0, [r0]\n"
        "    cmp r0, #0\n"
        "    beq .L080B14AE\n"
        "    b .L080B1628\n"
        ".L080B14AE:\n"
        "    bl sub_080B0820\n"
        "    movs r0, #0x6e\n"
        "    bl Sound_Play\n"
        "    ldr r4, .L080B14D4\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #0xd\n"
        "    bne .L080B14DC\n"
        "    ldrh r0, [r4, #0x1e]\n"
        "    adds r0, #1\n"
        "    strh r0, [r4, #0x1e]\n"
        "    ldr r1, .L080B14D8\n"
        "    movs r0, #2\n"
        "    strh r0, [r1]\n"
        "    b .L080B15C8\n"
        "    .byte 0x00, 0x00\n"
        ".L080B14D0: .4byte 0x030031CC @ IWRAM+0x31CC\n"
        ".L080B14D4: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B14D8: .4byte 0x0300460C @ IWRAM+0x460C\n"
        ".L080B14DC:\n"
        "    ldrh r0, [r4, #0x1e]\n"
        "    adds r0, #1\n"
        "    strh r0, [r4, #0x1e]\n"
        "    ldr r1, .L080B14E8\n"
        "    movs r0, #0x1c\n"
        "    b .L080B15F2\n"
        ".L080B14E8: .4byte 0x0300460C @ IWRAM+0x460C\n"
        ".L080B14EC:\n"
        "    ldr r4, .L080B154C\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #0x98\n"
        "    bne .L080B1504\n"
        "    movs r0, #0x11\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    beq .L080B1504\n"
        "    ldrh r0, [r4]\n"
        "    adds r0, #2\n"
        "    strh r0, [r4]\n"
        ".L080B1504:\n"
        "    bl sub_080B38A8\n"
        "    adds r5, r0, #0\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r5, r0\n"
        "    bne .L080B1564\n"
        "    ldr r5, .L080B1550\n"
        "    ldrh r0, [r5]\n"
        "    cmp r0, #0\n"
        "    bne .L080B151C\n"
        "    b .L080B1A06\n"
        ".L080B151C:\n"
        "    ldr r4, .L080B1554\n"
        "    movs r0, #0\n"
        "    strh r0, [r4, #0x1e]\n"
        "    ldr r1, .L080B1558\n"
        "    ldr r0, [r1]\n"
        "    subs r0, #1\n"
        ".L080B1528:\n"
        "    str r0, [r1]\n"
        "    ldrh r0, [r4, #2]\n"
        "    bl sub_080B1A1C\n"
        "    strh r0, [r4, #2]\n"
        "    bl sub_080AE234\n"
        "    bl sub_080AE294\n"
        "    ldr r0, .L080B155C\n"
        "    ldrh r0, [r0]\n"
        "    ldrh r1, [r5]\n"
        "    ldr r2, .L080B1560\n"
        "    ldrh r2, [r2]\n"
        "    bl sub_080B31C4\n"
        "    b .L080B1A06\n"
        "    .byte 0x00, 0x00\n"
        ".L080B154C: .4byte 0x03004534 @ IWRAM+0x4534\n"
        ".L080B1550: .4byte 0x0300460C @ IWRAM+0x460C\n"
        ".L080B1554: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B1558: .4byte 0x03004514 @ IWRAM+0x4514\n"
        ".L080B155C: .4byte 0x03004614 @ IWRAM+0x4614\n"
        ".L080B1560: .4byte 0x03003BA8 @ IWRAM+0x3BA8\n"
        ".L080B1564:\n"
        "    cmp r5, #1\n"
        "    beq .L080B156A\n"
        "    b .L080B1A06\n"
        ".L080B156A:\n"
        "    ldr r0, .L080B1584\n"
        "    ldr r1, [r0]\n"
        "    cmp r1, #0\n"
        "    bne .L080B15A4\n"
        "    ldr r2, .L080B1588\n"
        "    ldrh r0, [r2, #0x34]\n"
        "    cmp r0, #0\n"
        "    bne .L080B1590\n"
        "    ldrh r0, [r2]\n"
        "    ldr r1, .L080B158C\n"
        "    bl sub_080AF178\n"
        "    b .L080B1594\n"
        ".L080B1584: .4byte 0x03003B98 @ IWRAM+0x3B98\n"
        ".L080B1588: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B158C: .4byte gUnknown_08124DD8\n"
        ".L080B1590:\n"
        "    ldr r0, .L080B159C\n"
        "    str r1, [r0]\n"
        ".L080B1594:\n"
        "    ldr r1, .L080B15A0\n"
        "    movs r0, #1\n"
        "    str r0, [r1]\n"
        "    b .L080B1A06\n"
        ".L080B159C: .4byte 0x030031CC @ IWRAM+0x31CC\n"
        ".L080B15A0: .4byte 0x03003B98 @ IWRAM+0x3B98\n"
        ".L080B15A4:\n"
        "    ldr r0, .L080B15D4\n"
        "    ldr r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L080B1628\n"
        "    bl sub_080B0820\n"
        "    movs r0, #0x6e\n"
        "    bl Sound_Play\n"
        "    ldr r4, .L080B15D8\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #0xe\n"
        "    bne .L080B15E8\n"
        "    ldrh r0, [r4, #0x1e]\n"
        "    adds r0, #1\n"
        "    strh r0, [r4, #0x1e]\n"
        "    ldr r0, .L080B15DC\n"
        "    strh r5, [r0]\n"
        ".L080B15C8:\n"
        "    ldr r1, .L080B15E0\n"
        "    ldr r0, .L080B15E4\n"
        "    ldr r0, [r0]\n"
        "    ldrh r0, [r0, #4]\n"
        "    strh r0, [r1]\n"
        "    b .L080B1A06\n"
        ".L080B15D4: .4byte 0x030031CC @ IWRAM+0x31CC\n"
        ".L080B15D8: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B15DC: .4byte 0x0300460C @ IWRAM+0x460C\n"
        ".L080B15E0: .4byte 0x03003BA8 @ IWRAM+0x3BA8\n"
        ".L080B15E4: .4byte 0x03004000 @ IWRAM+0x4000\n"
        ".L080B15E8:\n"
        "    ldrh r0, [r4, #0x1e]\n"
        "    adds r0, #1\n"
        "    strh r0, [r4, #0x1e]\n"
        "    ldr r1, .L080B1614\n"
        "    movs r0, #0x1b\n"
        ".L080B15F2:\n"
        "    strh r0, [r1]\n"
        "    ldr r2, .L080B1618\n"
        "    ldr r0, .L080B161C\n"
        "    ldr r1, [r0]\n"
        "    ldrh r0, [r1, #6]\n"
        "    strh r0, [r2]\n"
        "    ldr r2, .L080B1620\n"
        "    ldrh r0, [r1, #4]\n"
        "    str r0, [r2]\n"
        "    ldr r0, .L080B1624\n"
        "    str r5, [r0]\n"
        "    ldrh r0, [r1, #8]\n"
        "    bl sub_080B1A1C\n"
        "    strh r0, [r4, #2]\n"
        "    b .L080B1A06\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1614: .4byte 0x0300460C @ IWRAM+0x460C\n"
        ".L080B1618: .4byte 0x03003BA8 @ IWRAM+0x3BA8\n"
        ".L080B161C: .4byte 0x03004000 @ IWRAM+0x4000\n"
        ".L080B1620: .4byte 0x03004614 @ IWRAM+0x4614\n"
        ".L080B1624: .4byte 0x03004514 @ IWRAM+0x4514\n"
        ".L080B1628:\n"
        "    bl sub_080B0820\n"
        "    ldr r1, .L080B163C\n"
        "    ldrh r0, [r1, #0x1e]\n"
        "    adds r0, #1\n"
        "    movs r2, #0\n"
        "    strh r0, [r1, #0x1e]\n"
        "    ldr r0, .L080B1640\n"
        "    strh r2, [r0]\n"
        "    b .L080B1A06\n"
        ".L080B163C: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B1640: .4byte 0x0300460C @ IWRAM+0x460C\n"
        ".L080B1644:\n"
        "    bl sub_080B092C\n"
        "    cmp r0, #0\n"
        "    beq .L080B164E\n"
        "    b .L080B1A06\n"
        ".L080B164E:\n"
        "    bl sub_080AE234\n"
        "    ldr r0, .L080B1670\n"
        "    ldrh r0, [r0]\n"
        "    ldr r1, .L080B1674\n"
        "    ldrh r1, [r1]\n"
        "    ldr r2, .L080B1678\n"
        "    ldrh r2, [r2]\n"
        "    bl sub_080B31C4\n"
        "    ldr r1, .L080B167C\n"
        "    ldrh r0, [r1, #0xa]\n"
        "    ldrh r1, [r1, #2]\n"
        "    movs r2, #3\n"
        "    bl sub_080B2030\n"
        "    b .L080B1A06\n"
        ".L080B1670: .4byte 0x03004614 @ IWRAM+0x4614\n"
        ".L080B1674: .4byte 0x0300460C @ IWRAM+0x460C\n"
        ".L080B1678: .4byte 0x03003BA8 @ IWRAM+0x3BA8\n"
        ".L080B167C: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B1680:\n"
        "    bl Automap_Update\n"
        "    b .L080B1A06\n"
        ".L080B1686:\n"
        "    ldrh r1, [r5, #0x1e]\n"
        "    subs r0, r1, #1\n"
        "    strh r0, [r5, #0x1e]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #4\n"
        "    bne .L080B16A8\n"
        "    ldrh r0, [r5, #0xe]\n"
        "    cmp r0, #0\n"
        "    bne .L080B16DC\n"
        ".L080B169A:\n"
        "    ldr r0, .L080B16A4\n"
        "    bl sub_080AE494\n"
        "    b .L080B1A06\n"
        "    .byte 0x00, 0x00\n"
        ".L080B16A4: .4byte sub_080B018C\n"
        ".L080B16A8:\n"
        "    cmp r0, #3\n"
        "    bne .L080B16B8\n"
        ".L080B16AC:\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    bl sub_080B2840\n"
        "    b .L080B1A06\n"
        ".L080B16B8:\n"
        "    cmp r0, #0\n"
        "    beq .L080B16BE\n"
        "    b .L080B1A06\n"
        ".L080B16BE:\n"
        "    ldrh r4, [r5, #0xe]\n"
        "    cmp r4, #0\n"
        "    bne .L080B16DC\n"
        "    ldr r0, .L080B16D8\n"
        "    bl sub_080AE494\n"
        "    bl sub_080B05A4\n"
        "    strh r4, [r5, #0x2e]\n"
        "    movs r0, #0x12\n"
        "    bl Field_SetState\n"
        "    b .L080B1A06\n"
        ".L080B16D8: .4byte sub_080B0158\n"
        ".L080B16DC:\n"
        "    strh r1, [r5, #0x1e]\n"
        "    b .L080B1A06\n"
        ".L080B16E0:\n"
        "    bl sub_080B092C\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #0\n"
        "    beq .L080B16EC\n"
        "    b .L080B1A06\n"
        ".L080B16EC:\n"
        "    ldr r0, .L080B1700\n"
        "    strh r1, [r0, #0x2e]\n"
        "    ldrh r0, [r0, #0x32]\n"
        "    cmp r0, #0\n"
        "    bne .L080B1704\n"
        ".L080B16F6:\n"
        "    movs r0, #1\n"
        "    bl sub_080B03BC\n"
        "    b .L080B1A06\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1700: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B1704:\n"
        "    movs r0, #4\n"
        "    bl sub_08128B84\n"
        "    movs r0, #0xa\n"
        "    bl Field_SetState\n"
        "    b .L080B1A06\n"
        ".L080B1712:\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #6\n"
        "    bl FieldMap_HasRecordRel\n"
        "    cmp r0, #1\n"
        "    bne .L080B1738\n"
        "    ldr r1, .L080B1734\n"
        "    movs r0, #0\n"
        "    str r0, [r1]\n"
        "    bl Battle_StartRandomEncounter\n"
        "    movs r0, #0x15\n"
        "    bl Field_SetState\n"
        "    b .L080B1A06\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1734: .4byte 0x03003BB8 @ IWRAM+0x3BB8\n"
        ".L080B1738:\n"
        "    ldr r4, .L080B176C\n"
        "    ldrh r0, [r4, #0x1e]\n"
        "    cmp r0, #0\n"
        "    bne .L080B1778\n"
        "    movs r0, #0xd0\n"
        "    movs r1, #0x30\n"
        "    movs r2, #4\n"
        "    movs r3, #4\n"
        "    bl PalFade_FadeRangeToBlackWithDuration\n"
        "    ldr r1, .L080B1770\n"
        "    str r0, [r1]\n"
        "    ldr r0, .L080B1774\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #0\n"
        "    beq .L080B1764\n"
        "    movs r0, #0\n"
        "    movs r1, #1\n"
        "    movs r2, #4\n"
        "    movs r3, #4\n"
        "    bl PalFade_FadeRangeToBlackWithDuration\n"
        ".L080B1764:\n"
        "    ldrh r0, [r4, #0x1e]\n"
        "    adds r0, #1\n"
        "    strh r0, [r4, #0x1e]\n"
        "    b .L080B17B4\n"
        ".L080B176C: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B1770: .4byte 0x0300452C @ IWRAM+0x452C\n"
        ".L080B1774: .4byte 0x03002DB0 @ IWRAM+0x2DB0\n"
        ".L080B1778:\n"
        "    bl sub_080B092C\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #0\n"
        "    bne .L080B17B4\n"
        "    ldr r0, .L080B1794\n"
        "    str r1, [r0]\n"
        "    bl Battle_StartRandomEncounter\n"
        "    movs r0, #0x15\n"
        "    bl Field_SetState\n"
        "    b .L080B17B4\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1794: .4byte 0x03003BB8 @ IWRAM+0x3BB8\n"
        ".L080B1798:\n"
        "    ldr r1, .L080B17BC\n"
        "    movs r0, #1\n"
        "    str r0, [r1]\n"
        "    bl Battle_StartRandomEncounter\n"
        "    bl sub_080B0888\n"
        "    movs r0, #0x15\n"
        "    bl Field_SetState\n"
        "    bl sub_080C7218\n"
        "    bl sub_080C7414\n"
        ".L080B17B4:\n"
        "    movs r0, #1\n"
        "    bl Music_FadeOut\n"
        "    b .L080B1A06\n"
        ".L080B17BC: .4byte 0x03003BB8 @ IWRAM+0x3BB8\n"
        ".L080B17C0:\n"
        "    ldr r0, .L080B17F0\n"
        "    ldr r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L080B18A6\n"
        "    ldr r0, .L080B17F4\n"
        "    ldrh r1, [r5, #2]\n"
        "    lsls r1, r1, #1\n"
        "    adds r1, r1, r0\n"
        "    ldrh r4, [r1]\n"
        "    adds r6, r4, #0\n"
        "    movs r0, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #6\n"
        "    bl FieldMap_HasRecordRel\n"
        "    cmp r0, #1\n"
        "    bne .L080B17F8\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x44\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #1\n"
        "    bne .L080B189E\n"
        "    adds r0, r4, #0\n"
        "    b .L080B1896\n"
        ".L080B17F0: .4byte 0x03003BB8 @ IWRAM+0x3BB8\n"
        ".L080B17F4: .4byte gUnknown_0815F31C\n"
        ".L080B17F8:\n"
        "    ldrh r0, [r5, #0x1e]\n"
        "    cmp r0, #0\n"
        "    bne .L080B1880\n"
        "    ldr r0, .L080B186C\n"
        "    ldr r1, [r0]\n"
        "    ldr r6, .L080B1870\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r6]\n"
        "    movs r0, #0xe0\n"
        "    lsls r0, r0, #1\n"
        "    adds r2, r6, r0\n"
        "    movs r4, #0x20\n"
        "    str r4, [sp]\n"
        "    movs r0, #3\n"
        "    movs r3, #0x40\n"
        "    bl Palette_CopyWithEffect\n"
        "    ldr r0, .L080B1874\n"
        "    ldr r1, [r0]\n"
        "    movs r3, #0xd0\n"
        "    lsls r3, r3, #1\n"
        "    adds r2, r6, r3\n"
        "    str r4, [sp]\n"
        "    movs r0, #3\n"
        "    movs r3, #0x20\n"
        "    bl Palette_CopyWithEffect\n"
        "    ldr r0, .L080B1878\n"
        "    ldr r1, [r0]\n"
        "    movs r0, #0xe8\n"
        "    lsls r0, r0, #2\n"
        "    adds r2, r6, r0\n"
        "    movs r0, #0x10\n"
        "    str r0, [sp]\n"
        "    movs r0, #3\n"
        "    movs r3, #0x20\n"
        "    bl Palette_CopyWithEffect\n"
        "    movs r0, #0xd0\n"
        "    movs r1, #0x30\n"
        "    movs r2, #1\n"
        "    movs r3, #0x10\n"
        "    bl PalFade_FadeRangeWithDuration\n"
        "    ldr r1, .L080B187C\n"
        "    str r0, [r1]\n"
        "    ldrh r0, [r6]\n"
        "    cmp r0, #0\n"
        "    bne .L080B185C\n"
        "    b .L080B19F8\n"
        ".L080B185C:\n"
        "    movs r0, #0\n"
        "    movs r1, #1\n"
        "    movs r2, #1\n"
        "    movs r3, #0x10\n"
        "    bl PalFade_FadeRangeWithDuration\n"
        "    b .L080B19F8\n"
        "    .byte 0x00, 0x00\n"
        ".L080B186C: .4byte 0x03004630 @ IWRAM+0x4630\n"
        ".L080B1870: .4byte 0x030029B0 @ IWRAM+0x29B0\n"
        ".L080B1874: .4byte 0x03004510 @ IWRAM+0x4510\n"
        ".L080B1878: .4byte 0x03003FC8 @ IWRAM+0x3FC8\n"
        ".L080B187C: .4byte 0x0300452C @ IWRAM+0x452C\n"
        ".L080B1880:\n"
        "    bl sub_080B092C\n"
        "    cmp r0, #0\n"
        "    beq .L080B188A\n"
        "    b .L080B1A06\n"
        ".L080B188A:\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x44\n"
        "    ldrh r0, [r0]\n"
        "    cmp r0, #1\n"
        "    bne .L080B189E\n"
        "    adds r0, r6, #0\n"
        ".L080B1896:\n"
        "    movs r1, #1\n"
        "    bl sub_080B1A4C\n"
        "    b .L080B1A06\n"
        ".L080B189E:\n"
        "    movs r0, #1\n"
        "    bl Field_SetState\n"
        "    b .L080B1A06\n"
        ".L080B18A6:\n"
        "    ldrh r0, [r5, #0x1e]\n"
        "    cmp r0, #0\n"
        "    bne .L080B18C4\n"
        "    ldr r1, .L080B18BC\n"
        "    movs r0, #1\n"
        "    strh r0, [r1, #0x34]\n"
        "    bl PalFade_FadeToBlack\n"
        "    ldr r1, .L080B18C0\n"
        "    str r0, [r1]\n"
        "    b .L080B19F8\n"
        ".L080B18BC: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
        ".L080B18C0: .4byte 0x0300452C @ IWRAM+0x452C\n"
        ".L080B18C4:\n"
        "    bl sub_080B092C\n"
        "    cmp r0, #0\n"
        "    beq .L080B18CE\n"
        "    b .L080B1A06\n"
        ".L080B18CE:\n"
        "    b .L080B19AE\n"
        ".L080B18D0:\n"
        "    bl sub_080B38A8\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #1\n"
        "    beq .L080B18DC\n"
        "    b .L080B1A06\n"
        ".L080B18DC:\n"
        "    ldr r4, .L080B1908\n"
        "    ldrh r0, [r4, #0x3a]\n"
        "    adds r5, r0, #0\n"
        "    ands r5, r1\n"
        "    cmp r5, #0\n"
        "    beq .L080B18EA\n"
        "    b .L080B1A06\n"
        ".L080B18EA:\n"
        "    ldrh r1, [r4, #0x3a]\n"
        "    movs r0, #2\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L080B18F6\n"
        "    b .L080B1A06\n"
        ".L080B18F6:\n"
        "    bl sub_080B0820\n"
        "    ldrh r0, [r4, #0x1e]\n"
        "    adds r0, #1\n"
        "    strh r0, [r4, #0x1e]\n"
        "    ldr r0, .L080B190C\n"
        "    strh r5, [r0]\n"
        "    b .L080B1A06\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1908: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B190C: .4byte 0x0300460C @ IWRAM+0x460C\n"
        ".L080B1910:\n"
        "    ldrh r0, [r5, #0x1e]\n"
        "    cmp r0, #0\n"
        "    beq .L080B1918\n"
        "    b .L080B1A06\n"
        ".L080B1918:\n"
        "    ldr r0, .L080B1928\n"
        "    ldr r0, [r0]\n"
        "    ldr r1, .L080B192C\n"
        "    bl Task_Create\n"
        "    movs r0, #1\n"
        "    strh r0, [r5, #0x1e]\n"
        "    b .L080B1A06\n"
        ".L080B1928: .4byte 0x03004628 @ IWRAM+0x4628\n"
        ".L080B192C: .4byte 0x0000FFFF\n"
        ".L080B1930:\n"
        "    ldrh r0, [r5, #0x1e]\n"
        "    cmp r0, #0\n"
        "    bne .L080B1A06\n"
        "    ldr r0, .L080B1948\n"
        "    ldr r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L080B194C\n"
        "    movs r0, #0\n"
        "    bl sub_08128B84\n"
        "    b .L080B195C\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1948: .4byte 0x03004628 @ IWRAM+0x4628\n"
        ".L080B194C:\n"
        "    cmp r0, #1\n"
        "    bne .L080B1958\n"
        "    movs r0, #0\n"
        "    bl sub_0812D0FC\n"
        "    b .L080B195C\n"
        ".L080B1958:\n"
        "    bl sub_0812A730\n"
        ".L080B195C:\n"
        "    ldr r1, .L080B1968\n"
        "    ldrh r0, [r1, #0x1e]\n"
        "    adds r0, #1\n"
        "    strh r0, [r1, #0x1e]\n"
        "    b .L080B1A06\n"
        "    .byte 0x00, 0x00\n"
        ".L080B1968: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080B196C:\n"
        "    ldr r1, .L080B1980\n"
        "    movs r0, #1\n"
        "    str r0, [r1]\n"
        "    bl sub_080AF280\n"
        "    bl sub_080C7218\n"
        "    bl sub_080C7414\n"
        "    b .L080B1A06\n"
        ".L080B1980: .4byte 0x03003BB8 @ IWRAM+0x3BB8\n"
        ".L080B1984:\n"
        "    ldrh r0, [r5, #0x1e]\n"
        "    cmp r0, #0\n"
        "    bne .L080B19A4\n"
        "    ldr r1, .L080B199C\n"
        "    movs r0, #1\n"
        "    strh r0, [r1, #0x34]\n"
        "    bl PalFade_FadeToBlack\n"
        "    ldr r1, .L080B19A0\n"
        "    str r0, [r1]\n"
        "    b .L080B19F8\n"
        "    .byte 0x00, 0x00\n"
        ".L080B199C: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
        ".L080B19A0: .4byte 0x0300452C @ IWRAM+0x452C\n"
        ".L080B19A4:\n"
        "    bl sub_080B092C\n"
        "    cmp r0, #0\n"
        "    bne .L080B1A06\n"
        "    ldrh r0, [r5]\n"
        ".L080B19AE:\n"
        "    ldr r0, .L080B19C8\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    ldr r1, .L080B19CC\n"
        "    ldrb r1, [r1]\n"
        "    lsls r1, r1, #0x18\n"
        "    asrs r1, r1, #0x18\n"
        "    movs r2, #1\n"
        "    bl sub_080C2CD8\n"
        "    b .L080B1A06\n"
        "    .byte 0x00, 0x00\n"
        ".L080B19C8: .4byte 0x03003FC4 @ IWRAM+0x3FC4\n"
        ".L080B19CC: .4byte 0x03004618 @ IWRAM+0x4618\n"
        ".L080B19D0:\n"
        "    adds r4, r5, #0\n"
        "    ldrh r0, [r4, #0x1e]\n"
        "    cmp r0, #0\n"
        "    bne .L080B19F0\n"
        "    ldrh r0, [r4, #0xe]\n"
        "    cmp r0, #0\n"
        "    bne .L080B1A06\n"
        "    ldr r0, .L080B19EC\n"
        "    bl sub_080AE494\n"
        "    ldrh r0, [r4, #0x1e]\n"
        "    adds r0, #1\n"
        "    strh r0, [r4, #0x1e]\n"
        "    b .L080B1A06\n"
        ".L080B19EC: .4byte sub_080B0158\n"
        ".L080B19F0:\n"
        "    cmp r0, #1\n"
        "    bne .L080B1A00\n"
        "    bl sub_080B05A4\n"
        ".L080B19F8:\n"
        "    ldrh r0, [r5, #0x1e]\n"
        "    adds r0, #1\n"
        "    strh r0, [r5, #0x1e]\n"
        "    b .L080B1A06\n"
        ".L080B1A00:\n"
        "    movs r0, #0\n"
        "    bl sub_080B0A08\n"
        ".L080B1A06:\n"
        "    bl sub_080B2CC0\n"
        ".L080B1A0A:\n"
        "    add sp, #0xc\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif
