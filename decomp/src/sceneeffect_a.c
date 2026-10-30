/* Scene effects: the task callbacks used by the effect task scripts that ScriptOp_406 starts
   (SceneEffect_Start, gUnknown_08182B20) -- graphics/palette loading and VBlank uploads,
   BG scrolling, scaled sprites, screen shake, and the elevator ride (doors and scrolling). */

#include "global.h"
#include "sceneeffect.h"

// sub_080BA1AC @ 0x080BA1AC
void sub_080BA1AC(void)
{
    VBlankTask_AddCounted(sub_080BA170, 1);
}

// sub_080BA1C0 @ 0x080BA1C0
void sub_080BA1C0(void)
{
    IwramFunc func = IwramFunc_4011;
    void *saved = gUnk_03003FC0;

    gUnk_03003FC0 = (void *)0x02001000;
    func(gUnknown_08173578);
    gUnk_03003FC0 = saved;
    VBlankTask_AddCounted(sub_080B2880, 1);
}

// sub_080BA1F8 @ 0x080BA1F8
void sub_080BA1F8(void)
{
    DmaSet(3, 0x02001000, 0x06015000, 0x84000800);
}

// sub_080BA21C @ 0x080BA21C
void sub_080BA21C(void)
{
    LZ77UnCompWram(gUnknown_08165AD4, gUnk_02001000);
    LZ77UnCompWram(gUnknown_081660D4, gUnk_02001000 + 0x1000);
    VBlankTask_AddCounted(sub_080BA1F8, 1);
    Palette_CopyWithEffect(3, gUnknown_08165A54, &gPaletteTarget[0xE0], 0x40, 0x20);
    Palette_CopyWithEffect(3, gUnknown_08165A94, &gPaletteTarget[0xD0], 0x20, 0x20);
    Palette_CopyWithEffect(3, gUnknown_08165AB4, &gPaletteTarget[0x1D0], 0x20, 0x10);
    Palette_CopyWithEffect(3, gUnknown_08165A94, &gPaletteTarget[0x1E0], 0x20, 0x20);
    gUnk_0300452C = PalFade_FadeRangeInFromBlackTagged(0xD0, 0x30, 1, 0x8001);
    PalFade_FadeRangeInFromBlack(0x1D0, 0x20, 1);
}

// sub_080BA2D8 @ 0x080BA2D8
void sub_080BA2D8(void)
{
    gFieldState.unk02 = sub_080B1A1C(gFieldState.unk02);
}

// sub_080BA2F0 @ 0x080BA2F0
void sub_080BA2F0(struct Task *task)
{
    struct ElevatorData *d = (struct ElevatorData *)task->data.raw;

    if (d->unk30 != 0x8000)
    {
        Sprite_Draw(gUnknown_08002D08, 9, 0xE, 3, 0x300, 0x58, -d->unk30);
        Sprite_Draw(gUnknown_08002D44, 9, 0xE, 3, 0x300, 0x58, d->unk30 + 0x28);
    }
    if (d->unk32 != 0x8000)
    {
        Sprite_Draw(gUnknown_08002CAC, 9, 0xD, 3, 0x280, 0x58, 0x18);
        Sprite_Draw(gUnknown_08002C88, 9, 0xD, 3, 0x280, 0x58 - d->unk32, 0x18);
        Sprite_Draw(gUnknown_08002C70, 9, 0xD, 3, 0x280, d->unk32 + 0x78, 0x18);
        sub_080B29A8(0);
    }
}

// sub_080BA3B4 @ 0x080BA3B4
void sub_080BA3B4(struct Task *task)
{
    struct ElevatorData *d = (struct ElevatorData *)task->data.raw;

    d->unk30 += 2;
}

// sub_080BA3C0 @ 0x080BA3C0
void sub_080BA3C0(struct Task *task)
{
    struct ElevatorData *d = (struct ElevatorData *)task->data.raw;

    d->unk30 = 0x8000;
    d->unk32 = 0;
}

// sub_080BA3D0 @ 0x080BA3D0
void sub_080BA3D0(struct Task *task)
{
    struct ElevatorData *d = (struct ElevatorData *)task->data.raw;

    d->unk32 += 2;
}

// sub_080BA3DC @ 0x080BA3DC
void sub_080BA3DC(void)
{
    VBlankTask_AddCounted(sub_080ADF64, 1);
    gUnk_03000038 = 0x3F;
    gUnk_03000039 = 0x3F;
    gUnk_0300003A = 0x3F;
}

// Elevator_Init @ 0x080BA408
void Elevator_Init(struct Task *task)
{
    struct ElevatorData *d = (struct ElevatorData *)task->data.raw;
    struct MapHeader *from = DungeonMap_GetFloor(gUnk_03004614, d->floors[d->from]);
    struct MapHeader *to = DungeonMap_GetFloor(gUnk_03004614, d->floors[d->to]);
    s16 b = to->unk06;
    s16 a = from->unk06;
    u16 x, y;

    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    d->speed.full = 0;
    d->pos = 0;
    sub_080C1F50(gFieldState.unk12, gFieldState.unk14, &x, &y);
    if (x == 0x40 && y == 0xC)
        d->dist = (a - b) * 0xA8;
    else if (a > b)
        d->dist = (a - b) * 0xA8;
    else
        d->dist = (b - a) * 0xA8;
}

// Elevator_SetScroll @ 0x080BA4C4
void Elevator_SetScroll(struct Task *task)
{
    u16 x, y;

    /* The data pointer reuses the parameter (a separate local lets CSE fold
       d->floors into task + 0x44). */
    task = (struct Task *)task->data.raw;
#define d ((struct ElevatorData *)task)
    sub_080C1F50(gFieldState.unk12, gFieldState.unk14, &x, &y);
    if ((x == 0x40 && y == 0xC) || d->to < d->floors[d->from])
        gUnk_0300000E = 0xA8 - (d->pos % 0xA8u & 0xFF);
    else
        gUnk_0300000E = d->pos % 0xA8u & 0xFF;
#undef d
}

// Elevator_Accelerate @ 0x080BA538
void Elevator_Accelerate(struct Task *task)
{
    struct ElevatorData *d = (struct ElevatorData *)task->data.raw;

    task->result = 0;
    if ((d->speed.full += 0x1000) >> 16 > 8)
        task->result = 1;
    d->pos = d->speed.part.whole + d->pos;
    Elevator_SetScroll(task);
}

// Elevator_Cruise @ 0x080BA56C
void Elevator_Cruise(struct Task *task)
{
    struct ElevatorData *d = (struct ElevatorData *)task->data.raw;

    task->result = 0;
    d->pos = d->speed.part.whole + d->pos;
    Elevator_SetScroll(task);
    if (d->pos > d->dist - (d->dist >> 4))
        task->result = 1;
}

// Elevator_Decelerate @ 0x080BA59C
#ifdef NONMATCHING
void Elevator_Decelerate(struct Task *task)
{
    struct ElevatorData *d = (struct ElevatorData *)task->data.raw;

    task->result = 0;
    if (d->speed.full >> 16 > 2)
        d->speed.full -= 0x1000;
    if ((d->pos += d->speed.part.whole) > d->dist)
    {
        d->pos = d->dist;
        task->result = 1;
    }
    Elevator_SetScroll(task);
}
#else
NAKED
void Elevator_Decelerate(struct Task *task)
{
    asm_unified(
        "    push {r4, lr}\n"
        "    adds r3, r0, #0\n"
        "    adds r2, r3, #0\n"
        "    adds r2, #0x24\n"
        "    movs r0, #0\n"
        "    strh r0, [r3, #0x1c]\n"
        "    ldr r1, [r2, #0x34]\n"
        "    lsrs r0, r1, #0x10\n"
        "    cmp r0, #2\n"
        "    bls .L080BA5B6\n"
        "    ldr r4, .L080BA5DC\n"
        "    adds r0, r1, r4\n"
        "    str r0, [r2, #0x34]\n"
        ".L080BA5B6:\n"
        "    ldrh r1, [r2, #0x36]\n"
        "    ldrh r0, [r2, #0x38]\n"
        "    adds r0, r0, r1\n"
        "    strh r0, [r2, #0x38]\n"
        "    ldrh r1, [r2, #0x3a]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, r1\n"
        "    bls .L080BA5CE\n"
        "    strh r1, [r2, #0x38]\n"
        "    movs r0, #1\n"
        "    strh r0, [r3, #0x1c]\n"
        ".L080BA5CE:\n"
        "    adds r0, r3, #0\n"
        "    bl Elevator_SetScroll\n"
        "    pop {r4}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080BA5DC: .4byte 0xFFFFF000\n"
    );
}
#endif

// sub_080BA5E0 @ 0x080BA5E0
/* Value of the 4x13 table at the cell (dx, dy) relative to the player, rotated by the
   facing; 0 outside the table or behind the player. */
u32 sub_080BA5E0(s16 dx, s16 dy)
{
    s16 x = gFieldState.unk12;
    s16 y = gFieldState.unk14;

    switch (gFieldState.unk02)
    {
    case 0:
        x += dx;
        y += dy;
        break;
    case 1:
        if (dx > 0)
            return 0;
        x -= dy;
        y += dx;
        break;
    case 2:
        if (dy < 0)
            return 0;
        x -= dx;
        y -= dy;
        break;
    case 3:
        if (dx < 0)
            return 0;
        x += dy;
        y -= dx;
        break;
    }
    if ((u16)x > 2 || y < 0 || y > 12)
        return 0;
    return gUnknown_0817417C[y][x];
}

// sub_080BA6B4 @ 0x080BA6B4
s32 sub_080BA6B4(u16 kind)
{
    IwramFunc func = IwramFunc_3BC1;
    const struct StepEffect *e;
    s32 ret;

    if (kind == 0 || kind == 3)
        e = gUnknown_08173D04;
    else if (kind == 1)
        e = gUnknown_08173FBC;
    else if (kind == 2)
    {
        if (gFieldState.unk08 == -1)
            e = gUnknown_0817410C;
        else
            e = gUnknown_08174144;
    }
    e = &e[gFieldState.unk0E - 1];
    if (e->data == NULL)
    {
        gFieldState.unk0E = 0;
        VBlankTask_AddCounted(sub_080B2880, 1);
        ret = 1;
    }
    else
    {
        gFieldState.unk0E++;
        if (sub_080BA5E0(e->dx, e->dy))
        {
            func(e->data);
            ret = 1;
        }
        else
        {
            ret = 0;
        }
    }
    return ret;
}
