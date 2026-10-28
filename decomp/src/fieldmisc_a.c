#include "global.h"
#include "fieldcmd.h"

// Status_ShowAfflictionMessage @ 0x080BEA60
/* Draws "<name><ailment message>" for the ailment bit d[2] (leader, data.w[0] bit 0) or
   d[3] (member sub_080C1B50, bit 1). Names longer than 8 glyphs are cut. */
void Status_ShowAfflictionMessage(struct Task *task)
{
    u16 *d = task->data.h;
    u16 flag;
    u8 *c;
    const u16 *msg;
    u16 x;
    u16 i;
    u16 name[16];

    if (d[4] == 0)
    {
        flag = d[2];
        if (!(task->data.w[0] & 1))
            return;
        c = Battle_GetCombatant(0x8000);
    }
    else
    {
        flag = d[3];
        if (!(task->data.w[0] & 2))
            return;
        c = Battle_GetCombatant(sub_080C1B50() + 0x8000);
    }
    switch (flag)
    {
    case 0x8000:
        msg = gUnknown_0819873C;
        break;
    case 0x4000:
        msg = gUnknown_08198748;
        break;
    case 0x2000:
        msg = gUnknown_0819875E;
        break;
    case 0x1000:
        msg = gUnknown_0819876C;
        break;
    case 0x800:
        msg = gUnknown_08198780;
        break;
    case 0x400:
        msg = gUnknown_08198794;
        break;
    case 0x200:
        msg = gUnknown_081987A8;
        break;
    case 0x100:
        msg = gUnknown_081987BA;
        break;
    case 0x80:
        msg = gUnknown_081987C8;
        break;
    case 0x40:
        msg = gUnknown_081987D4;
        break;
    case 0x20:
        msg = gUnknown_081987E6;
        break;
    case 0x10:
        msg = gUnknown_081987FC;
        break;
    case 8:
        msg = gUnknown_0819880E;
        break;
    case 4:
        msg = gUnknown_08198822;
        break;
    case 2:
        msg = gUnknown_08198834;
        break;
    }
    x = 0x10;
    Combatant_DecodeName(c, name);
    for (i = 0; name[i] != 0; )
    {
        FontSprite_DrawGlyph(name[i], 0, 0, x, 0x59);
        x += 12;
        i++;
        if (i > 7)
            break;
    }
    Text_DrawSpriteString(msg, 0, 0, x, 0x59, 0xC);
    if (!((gFrameCounter >> 4) & 1))
        sub_080C4AB0(0, 0, 0xD6, 0x61);
}

// sub_080BEC28 @ 0x080BEC28
void sub_080BEC28(struct Task *task)
{
    Window_Close((void *)task->data.w[3], 1);
    Field_SetState(1);
}

// sub_080BEC3C @ 0x080BEC3C
void sub_080BEC3C(u32 flags, u16 leader, u16 member)
{
    struct Task *t = Task_Create(gUnknown_08198848, 0xFFFF);
    u16 *d = t->data.h;

    t->data.w[0] = flags;
    d[2] = leader;
    d[3] = member;
}

// sub_080BEC6C @ 0x080BEC6C
void sub_080BEC6C(struct Task *task)
{
    u16 *d = task->data.h;

    task->data.w[0] = gWorldMap.unk2C;
    d[2] = gWorldMap.unk30;
    d[3] = gWorldMap.unk32;
}

// sub_080BEC84 @ 0x080BEC84
void sub_080BEC84(struct Task *task)
{
    Window_Close((void *)task->data.w[3], 1);
    gFieldState.unk1E = 0;
    Field_SetState(0x1E);
}

// sub_080BECA4 @ 0x080BECA4
/* Moon phase 0..0x80 (rises to full at 0x80, then falls back). */
u32 sub_080BECA4(void)
{
    u8 phase = Moon_GetPhase() & 0xF0;

    if (phase > 0x8F)
    {
        phase += 0x80;
        phase = 0x80 - phase;
    }
    return phase;
}

// sub_080BECCC @ 0x080BECCC
/* Picks 1-4 from the moon phase, story flags and a random byte (Random_Byte). */
u32 sub_080BECCC(void)
{
    u8 phase = sub_080BECA4();

    if (!Flag_Test(0x1D))
    {
        if (phase == 0x80 || (Random_Byte() & 0xFF) <= 0x1F)
            goto two;
        goto one;
    }
    if (!Flag_Test(0x23))
    {
        if ((Random_Byte() & 0xFF) > 0x7F)
            goto one;
    two:
        return 2;
    }
    if (!Flag_Test(0x68))
    {
        if ((Random_Byte() & 0xFF) <= 0x7F)
            goto three;
        goto one;
    }
    if (!Flag_Test(0x96) && !Flag_Test(0x7D))
    {
        if ((Random_Byte() & 0xFF) > 0x1F)
            goto one;
    three:
        return 3;
    }
    if ((Random_Byte() & 0xFF) > 0x3F)
    {
    one:
        return 1;
    }
    return 4;
}
