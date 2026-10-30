/* Battle menu: member status panel (HP/MP/level/status) and menu setup. */

#include "global.h"
#include "bmenu.h"

#define PANEL (gUnk_030000B4 + 0xA00)

// sub_08128388 @ 0x08128388
void sub_08128388(void)
{
    VBlankTask_AddCounted(sub_0812834C, 1);
}

// sub_0812839C @ 0x0812839C
u32 sub_0812839C(u16 id)
{
    struct Combatant *c = Party_GetMember(id + 0x8000);

    return (c->level * 32) << sub_080C29B0(c->demonId);
}

// sub_081283C4 @ 0x081283C4
void sub_081283C4(u8 mode, u16 index)
{
    u16 v = C127_BLOCK->list[index];
    u8 i;
    u32 zero;
    u8 tint;
    struct Combatant *c;
    u8 *rec;

    if (v == 0xFFFF)
        return;
    for (i = 0; i < 6; i++)
    {
        zero = 0;
        CpuFastSet(&zero, gUnk_030000B4 + ((i + 2) * 32 + 16) * 32, 0x01000080);
    }
    if (mode == 0)
    {
        c = Party_GetMember(v + 0x8000);
        BattleMenu_DrawHp(c->hp, c->maxHp);
        BattleMenu_DrawMp(c->mp, c->maxMp);
        BattleMenu_DrawStatus(c->flags, c->race);
    }
    else if (mode == 1)
    {
        rec = Demon_GetRecord(v);
        BattleMenu_DrawHp(*(u16 *)(rec + 2), *(u16 *)(rec + 2));
        BattleMenu_DrawMp(*(u16 *)(rec + 4), *(u16 *)(rec + 4));
        BattleMenu_DrawStatus(0, 4);
    }
    else if (mode == 2)
    {
        rec = Demon_GetRecord(v & 0x7FFF);
        if (v & 0x8000)
        {
            Menu_DrawLabeledName(-1);
            sub_08128AAC(0xFFFF);
        }
        else
        {
            Menu_DrawLabeledName((s8)rec[0]);
            sub_08128AAC(rec[1]);
        }
    }
    else if (mode == 3)
    {
        tint = 0;
        c = Party_GetMember(v + 0x8000);
        BattleMenu_DrawHp(c->hp, c->maxHp);
        BattleMenu_DrawMp(c->mp, c->maxMp);
        if (sub_080C29B0(c->demonId))
            tint = 6;
        sub_0812876C(sub_0812839C(v), tint);
    }
}

// BattleMenu_DrawHp @ 0x081284FC
void BattleMenu_DrawHp(u16 cur, u16 max)
{
    u8 *canvas = PANEL;
    u8 b[3];
    u8 *d;

    DigitFont_DrawGlyphTinted(0x28, canvas, 3, 6, 4);
    DigitFont_DrawGlyphTinted(0x30, canvas, 0xB, 6, 4);
    DigitFont_DrawGlyphTinted(0xF, canvas, 0x3D, 6, 0);
    d = NumberToDigits(cur);
    b[0] = *d++;
    b[1] = *d++;
    b[2] = *d++;
    DigitFont_DrawGlyphTinted(b[0] + 0x10, canvas, 0x35, 6, 0);
    if ((b[1] != 0) | (b[1] == 0 && b[2] != 0))
        DigitFont_DrawGlyphTinted(b[1] + 0x10, canvas, 0x2D, 6, 0);
    if (b[2] != 0)
        DigitFont_DrawGlyphTinted(b[2] + 0x10, canvas, 0x25, 6, 0);
    d = NumberToDigits(max);
    b[0] = *d++;
    b[1] = *d++;
    b[2] = *d++;
    DigitFont_DrawGlyphTinted(b[0] + 0x10, canvas, 0x55, 6, 0);
    if ((b[1] != 0) | (b[1] == 0 && b[2] != 0))
        DigitFont_DrawGlyphTinted(b[1] + 0x10, canvas, 0x4D, 6, 0);
    if (b[2] != 0)
        DigitFont_DrawGlyphTinted(b[2] + 0x10, canvas, 0x45, 6, 0);
}

// BattleMenu_DrawMp @ 0x08128634
void BattleMenu_DrawMp(u16 cur, u16 max)
{
    u8 *canvas = PANEL;
    u8 b[3];
    u8 *d;

    DigitFont_DrawGlyphTinted(0x2D, canvas, 3, 0x12, 4);
    DigitFont_DrawGlyphTinted(0x30, canvas, 0xB, 0x12, 4);
    DigitFont_DrawGlyphTinted(0xF, canvas, 0x3D, 0x12, 0);
    d = NumberToDigits(cur);
    b[0] = *d++;
    b[1] = *d++;
    b[2] = *d++;
    DigitFont_DrawGlyphTinted(b[0] + 0x10, canvas, 0x35, 0x12, 0);
    if ((b[1] != 0) | (b[1] == 0 && b[2] != 0))
        DigitFont_DrawGlyphTinted(b[1] + 0x10, canvas, 0x2D, 0x12, 0);
    if (b[2] != 0)
        DigitFont_DrawGlyphTinted(b[2] + 0x10, canvas, 0x25, 0x12, 0);
    d = NumberToDigits(max);
    b[0] = *d++;
    b[1] = *d++;
    b[2] = *d++;
    DigitFont_DrawGlyphTinted(b[0] + 0x10, canvas, 0x55, 0x12, 0);
    if ((b[1] != 0) | (b[1] == 0 && b[2] != 0))
        DigitFont_DrawGlyphTinted(b[1] + 0x10, canvas, 0x4D, 0x12, 0);
    if (b[2] != 0)
        DigitFont_DrawGlyphTinted(b[2] + 0x10, canvas, 0x45, 0x12, 0);
}

// sub_0812876C @ 0x0812876C
void sub_0812876C(u16 value, u8 tint)
{
    u8 *canvas = PANEL;
    u8 b[4];
    u8 *d;
    u8 n;

    DigitFont_DrawGlyphTinted(0x23, canvas, 3, 0x1E, 4);
    DigitFont_DrawGlyphTinted(0x2F, canvas, 0xB, 0x1E, 4);
    DigitFont_DrawGlyphTinted(0x33, canvas, 0x13, 0x1E, 4);
    DigitFont_DrawGlyphTinted(0x34, canvas, 0x1B, 0x1E, 4);
    d = NumberToDigits(value);
    b[0] = *d++;
    b[1] = *d++;
    b[2] = *d++;
    b[3] = *d++;
    n = 4;
    if (b[3] == 0)
    {
        if (b[2] == 0)
        {
            if (b[1] == 0)
                n = 1;
            n = 2;
        }
        else
            n = 3;
    }
    while (n != 0)
    {
        DigitFont_DrawGlyphTinted(b[n - 1] + 0x10, PANEL, (11 - n) * 8 + 5, 0x1E, tint);
        n--;
    }
}

// BattleMenu_DrawStatus @ 0x08128828
void BattleMenu_DrawStatus(u16 flags, u16 race)
{
    u8 *canvas = PANEL;
    const u8 *s;
    u8 i;

    DigitFont_DrawGlyphTinted(0x33, canvas, 3, 0x1E, 4);
    DigitFont_DrawGlyphTinted(0x34, canvas, 0xB, 0x1E, 4);
    if (flags & 0x8000)
    {
        s = gUnknown_08777D54[0];
        if (race < 4)
            s += 8;
    }
    else if (flags & 0x4000)
        s = gUnknown_08777D54[2];
    else if (flags & 0x2000)
        s = gUnknown_08777D54[3];
    else if (flags & 0x1000)
        s = gUnknown_08777D54[4];
    else if (flags & 4)
        s = gUnknown_08777D54[14];
    else if (flags & 0x800)
        s = gUnknown_08777D54[5];
    else if (flags & 0x400)
        s = gUnknown_08777D54[6];
    else if (flags & 1)
        s = gUnknown_08777D54[16];
    else if (flags & 0x200)
        s = gUnknown_08777D54[7];
    else if (flags & 0x40)
        s = gUnknown_08777D54[10];
    else if (flags & 0x20)
        s = gUnknown_08777D54[11];
    else if (flags & 0x100)
        s = gUnknown_08777D54[8];
    else if (flags & 0x80)
        s = gUnknown_08777D54[9];
    else if (flags & 2)
        s = gUnknown_08777D54[15];
    else if (flags & 0x10)
        s = gUnknown_08777D54[12];
    else if (flags & 8)
        s = gUnknown_08777D54[13];
    else
        s = gUnknown_08777D54[17];
    for (i = 0; i < 8; i++)
    {
        if (*s != 0)
            DigitFont_DrawGlyphTinted(*s++ - 0x20, PANEL, (i + 5) * 8 + 5, 0x1E, 0);
    }
}

/* Old-style definition: callers pass an int (sign-extended s8, or -1 for none). */
// Menu_DrawLabeledName @ 0x081289B8
void Menu_DrawLabeledName(id)
    u8 id;
{
    u8 *canvas = PANEL;
    const u16 *str;
    u16 n;
    u8 i;
    u16 unused[2];  /* never used; the original frame has it */

    DigitFont_DrawGlyphTinted(0x32, canvas, 3, 6, 4);
    DigitFont_DrawGlyphTinted(0x21, canvas, 0xB, 6, 4);
    DigitFont_DrawGlyphTinted(0x23, canvas, 0x13, 6, 4);
    DigitFont_DrawGlyphTinted(0x25, canvas, 0x1B, 6, 4);
    if ((s8)id == -1)
    {
        for (i = 0; i < 5; i++)
        {
            if (i > 2)
                Font_DrawGlyphTinted(0x3C, PANEL, i * 12 + 0x23, 3, 0);
        }
    }
    else
    {
        str = gUnknown_08777DE4[(s8)id];
        n = 0;
        for (i = 0; i < 5 && str[i] != 0; i++)
            n++;
        for (i = 0; i < n; i++)
            Font_DrawGlyphTinted(*str++, PANEL, (5 - n + i) * 12 + 0x23, 3, 0);
    }
}

// sub_08128AAC @ 0x08128AAC
void sub_08128AAC(u16 value)
{
    u8 *canvas = PANEL;
    u8 b[3];
    u8 *d;

    DigitFont_DrawGlyphTinted(0x2C, canvas, 3, 0x14, 4);
    DigitFont_DrawGlyphTinted(0x36, canvas, 0xB, 0x14, 4);
    if (value == 0xFFFF)
    {
        DigitFont_DrawGlyphTinted(0xD, canvas, 0x55, 0x14, 0);
        DigitFont_DrawGlyphTinted(0xD, canvas, 0x4D, 0x14, 0);
    }
    else
    {
        d = NumberToDigits(value);
    b[0] = *d++;
    b[1] = *d++;
    b[2] = *d++;
        DigitFont_DrawGlyphTinted(b[0] + 0x10, canvas, 0x55, 0x14, 0);
        if ((b[1] != 0) | (b[1] == 0 && b[2] != 0))
            DigitFont_DrawGlyphTinted(b[1] + 0x10, canvas, 0x4D, 0x14, 0);
        if (b[2] != 0)
            DigitFont_DrawGlyphTinted(b[2] + 0x10, canvas, 0x45, 0x14, 0);
    }
}

// sub_08128B84 @ 0x08128B84
void sub_08128B84(u8 mode)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk4C = blk->unk50 = 0;
    switch (mode)
    {
    case 0:
        sub_080C7218();
        sub_080C7648();
        sub_080C7C60();
        BattleMenu_Reset();
        blk->unk40 = Task_Create(gUnknown_08777EB8, 0xFFFF);
        blk->unk696 = 0;
        break;
    case 1:
        sub_080C700C();
        sub_080C7430();
        sub_080C7648();
        blk->unk40 = Task_Create(gUnknown_08777EB8, 0xFFFF);
        blk->unk696 = 0;
        break;
    case 2:
        sub_080C7C60();
        sub_0812A710();
        break;
    case 3:
        blk->unk40 = Task_Create(gUnknown_08777EB8, 0xFFFF);
        break;
    case 4:
        sub_08128EB4();
        break;
    }
}
