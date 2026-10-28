/* Battle menu drawing. */

#include "global.h"
#include "bmenu.h"

/* Row 4 is drawn into the scratch canvas 0x030002B4 and swapped with 0x03001CB4. */
// sub_081272CC @ 0x081272CC
void sub_081272CC(u16 *str, u8 row)
{
    u8 i;
    u32 zero;

    if (row == 4)
    {
        CpuFastSet(gUnk_030000B4 + 0x1C00, gUnk_030000B4 + 0x200, 0x80);
        for (i = 0; i < 8; i++)
        {
            if (str[i] != 0)
                Font_DrawGlyphTinted(str[i], gUnk_030000B4, i * 12 + 0x80, 2, 0);
        }
        CpuFastSet(gUnk_030000B4 + 0x200, gUnk_030000B4 + 0x1C00, 0x80);
        CpuFastSet(gUnk_030000B4 + 0x600, gUnk_030000B4 + 0x200, 0x80);
        zero = 0;
        CpuFastSet(&zero, gUnk_030000B4 + 0x600, 0x01000080);
    }
    else
    {
        for (i = 0; i < 8; i++)
        {
            if (str[i] != 0)
                Font_DrawGlyphTinted(str[i], gUnk_030000B4, i * 12, row * 13 + 6, 0);
        }
    }
}

// sub_08127394 @ 0x08127394
void sub_08127394(u16 *str, u8 row, u8 tint)
{
    u8 i;
    u32 zero;

    if (row == 4)
    {
        CpuFastSet(gUnk_030000B4 + 0x1C00, gUnk_030000B4 + 0x200, 0x80);
        for (i = 0; i < 8; i++)
        {
            if (str[i] != 0)
                Font_DrawGlyphTinted(str[i], gUnk_030000B4, i * 12 + 0x80, 2, tint);
        }
        CpuFastSet(gUnk_030000B4 + 0x200, gUnk_030000B4 + 0x1C00, 0x80);
        CpuFastSet(gUnk_030000B4 + 0x600, gUnk_030000B4 + 0x200, 0x80);
        zero = 0;
        CpuFastSet(&zero, gUnk_030000B4 + 0x600, 0x01000080);
    }
    else
    {
        for (i = 0; i < 8; i++)
        {
            if (str[i] != 0)
                Font_DrawGlyphTinted(str[i], gUnk_030000B4, i * 12, row * 13 + 6, tint);
        }
    }
}

// sub_0812745C @ 0x0812745C
void sub_0812745C(u16 value, u8 row)
{
    u8 *d = NumberToDigits(value);
    u32 zero;

    if (row == 4)
    {
        CpuFastSet(gUnk_030000B4 + 0x1C00, gUnk_030000B4 + 0xA00, 0x80);
        CpuFastSet(gUnk_030000B4 + 0x200, gUnk_030000B4 + 0xE00, 0x80);
        DigitFont_DrawGlyphTinted(d[0] + 0x10, gUnk_030000B4, 0xF7, 0x14, 0);
        DigitFont_DrawGlyphTinted(d[1] + 0x10, gUnk_030000B4, 0xEF, 0x14, 0);
        Font_DrawGlyphTinted(0x3E, gUnk_030000B4, 0xE3, 0x13, 0);
        CpuFastSet(gUnk_030000B4 + 0xA00, gUnk_030000B4 + 0x1C00, 0x80);
        CpuFastSet(gUnk_030000B4 + 0xE00, gUnk_030000B4 + 0x200, 0x80);
        zero = 0;
        CpuFastSet(&zero, gUnk_030000B4 + 0x600, 0x01000080);
    }
    else
    {
        DigitFont_DrawGlyphTinted(d[0] + 0x10, gUnk_030000B4, 0x77, row * 13 + 8, 0);
        DigitFont_DrawGlyphTinted(d[1] + 0x10, gUnk_030000B4, 0x6F, row * 13 + 8, 0);
        Font_DrawGlyphTinted(0x3E, gUnk_030000B4, 0x63, row * 13 + 7, 0);
    }
}

// sub_0812756C @ 0x0812756C
void sub_0812756C(u16 value, u8 row, u8 tint)
{
    u8 *d = NumberToDigits(value);
    u32 zero;

    if (row == 4)
    {
        CpuFastSet(gUnk_030000B4 + 0x1C00, gUnk_030000B4 + 0xA00, 0x80);
        CpuFastSet(gUnk_030000B4 + 0x200, gUnk_030000B4 + 0xE00, 0x80);
        DigitFont_DrawGlyphTinted(d[0] + 0x10, gUnk_030000B4, 0xF7, 0x14, tint);
        DigitFont_DrawGlyphTinted(d[1] + 0x10, gUnk_030000B4, 0xEF, 0x14, tint);
        Font_DrawGlyphTinted(0x3E, gUnk_030000B4, 0xE3, 0x13, tint);
        CpuFastSet(gUnk_030000B4 + 0xA00, gUnk_030000B4 + 0x1C00, 0x80);
        CpuFastSet(gUnk_030000B4 + 0xE00, gUnk_030000B4 + 0x200, 0x80);
        zero = 0;
        CpuFastSet(&zero, gUnk_030000B4 + 0x600, 0x01000080);
    }
    else
    {
        DigitFont_DrawGlyphTinted(d[0] + 0x10, gUnk_030000B4, 0x77, row * 13 + 8, tint);
        DigitFont_DrawGlyphTinted(d[1] + 0x10, gUnk_030000B4, 0x6F, row * 13 + 8, tint);
        Font_DrawGlyphTinted(0x3E, gUnk_030000B4, 0x63, row * 13 + 7, tint);
    }
}

// sub_08127678 @ 0x08127678
void sub_08127678(u16 value, u8 row)
{
    u8 *d = NumberToDigits(value);
    u32 zero;

    if (row == 4)
    {
        CpuFastSet(gUnk_030000B4 + 0x1C00, gUnk_030000B4 + 0xA00, 0x80);
        CpuFastSet(gUnk_030000B4 + 0x200, gUnk_030000B4 + 0xE00, 0x80);
        DigitFont_DrawGlyphTinted(d[0] + 0x10, gUnk_030000B4, 0xF7, 0x14, 0);
        d++;
        if (*d != 0)
            DigitFont_DrawGlyphTinted(*d + 0x10, gUnk_030000B4, 0xEF, 0x14, 0);
        DigitFont_DrawGlyphTinted(0x2D, gUnk_030000B4, 0xDF, 0x14, 0);
        DigitFont_DrawGlyphTinted(0x30, gUnk_030000B4, 0xE7, 0x14, 0);
        CpuFastSet(gUnk_030000B4 + 0xA00, gUnk_030000B4 + 0x1C00, 0x80);
        CpuFastSet(gUnk_030000B4 + 0xE00, gUnk_030000B4 + 0x200, 0x80);
        zero = 0;
        CpuFastSet(&zero, gUnk_030000B4 + 0x600, 0x01000080);
    }
    else
    {
        DigitFont_DrawGlyphTinted(d[0] + 0x10, gUnk_030000B4, 0x77, row * 13 + 8, 0);
        d++;
        if (*d != 0)
            DigitFont_DrawGlyphTinted(*d + 0x10, gUnk_030000B4, 0x6F, row * 13 + 8, 0);
        DigitFont_DrawGlyphTinted(0x2D, gUnk_030000B4, 0x5F, row * 13 + 8, 0);
        DigitFont_DrawGlyphTinted(0x30, gUnk_030000B4, 0x67, row * 13 + 8, 0);
    }
}

// sub_081277AC @ 0x081277AC
void sub_081277AC(u16 value, u8 row)
{
    u8 *d;
    u16 shift = 0;
    u32 zero;

    d = NumberToDigits(value);
    if (value > 99)
        shift = 8;
    if (row == 4)
    {
        CpuFastSet(gUnk_030000B4 + 0x1C00, gUnk_030000B4 + 0xA00, 0x80);
        CpuFastSet(gUnk_030000B4 + 0x200, gUnk_030000B4 + 0xE00, 0x80);
        DigitFont_DrawGlyphTinted(d[0] + 0x10, gUnk_030000B4, 0xF7, 0x14, 0);
        if (d[2] != 0 || d[1] != 0)
            DigitFont_DrawGlyphTinted(d[1] + 0x10, gUnk_030000B4, 0xEF, 0x14, 0);
        if (d[2] != 0)
            DigitFont_DrawGlyphTinted(d[2] + 0x10, gUnk_030000B4, 0xE7, 0x14, 0);
        DigitFont_DrawGlyphTinted(0x28, gUnk_030000B4, 0xDF - shift, 0x14, 0);
        DigitFont_DrawGlyphTinted(0x30, gUnk_030000B4, 0xE7 - shift, 0x14, 0);
        CpuFastSet(gUnk_030000B4 + 0xA00, gUnk_030000B4 + 0x1C00, 0x80);
        CpuFastSet(gUnk_030000B4 + 0xE00, gUnk_030000B4 + 0x200, 0x80);
        zero = 0;
        CpuFastSet(&zero, gUnk_030000B4 + 0x600, 0x01000080);
    }
    else
    {
        DigitFont_DrawGlyphTinted(d[0] + 0x10, gUnk_030000B4, 0x77, row * 13 + 8, 0);
        if (d[2] != 0 || d[1] != 0)
            DigitFont_DrawGlyphTinted(d[1] + 0x10, gUnk_030000B4, 0x6F, row * 13 + 8, 0);
        if (d[2] != 0)
            DigitFont_DrawGlyphTinted(d[2] + 0x10, gUnk_030000B4, 0x67, row * 13 + 8, 0);
        DigitFont_DrawGlyphTinted(0x28, gUnk_030000B4, 0x5F - shift, row * 13 + 8, 0);
        DigitFont_DrawGlyphTinted(0x30, gUnk_030000B4, 0x67 - shift, row * 13 + 8, 0);
    }
}

// MenuCursor_SetIndex @ 0x08127960
void MenuCursor_SetIndex(u8 id, u16 index)
{
    struct MenuCursor *c = sub_08126D1C(id);

    c->top = 0;
    c->onScreen = 0;
    c->column = 0;
    c->row = 0;
    c->index = index;
    if (c->index > c->count - 1)
        c->index = c->count - 1;
    c->column = c->index / c->perColumn;
    c->row = c->index % c->perColumn;
    if (c->index < c->top)
        c->top = c->index;
    else if (c->index > c->top + c->perColumn - 1)
        c->top = c->index + (1 - c->perColumn);
    if (c->top > c->count - c->perColumn)
        c->top = c->count - c->perColumn;
    c->onScreen = c->index - c->top;
}

// sub_081279D4 @ 0x081279D4
void sub_081279D4(void)
{
    gUnk_03000030 = gUnk_03000031 = gUnk_03000035 = gUnk_03000034 = 0;
    gUnk_03000038 = 0x3F;
    gUnk_03000032 = gUnk_03000033 = gUnk_03000037 = gUnk_03000036 = 0;
    gUnk_03000039 = 0x3F;
    gUnk_0300003A = 0x3F;
}

// sub_08127A38 @ 0x08127A38
void sub_08127A38(struct Task *task)
{
    task->result = 0;
    if ((u16)(gUnk_0200E7D4[0] - 1) > 1
     && (u16)(gUnk_0200E7D4[2] - 1) > 1
     && (u16)(gUnk_0200E7D4[3] - 1) > 1
     && (u16)(gUnk_0200E7D4[4] - 1) > 1
     && (u16)(gUnk_0200E7D4[5] - 1) > 1
     && (u16)(gUnk_0200E7D4[6] - 1) > 1)
        task->result = 1;
}

/* Builds C127_BLOCK->list (0xFFFF-terminated) of member slots for a menu; returns the count. */
// BattleMenu_BuildMemberList @ 0x08127A98
u16 BattleMenu_BuildMemberList(u8 mode)
{
    struct C127Block *blk = C127_BLOCK;
    u16 *list = blk->list;
    u16 count = 0;
    u16 i, j;
    u8 found;
    struct Combatant *c;

    switch (mode)
    {
    case 0:
        for (i = 0; i < 16; i++)
        {
            c = Party_GetMember(i + 0x8000);
            if (c->unkE != 0)
            {
                *list++ = i;
                count++;
            }
        }
        *list = 0xFFFF;
        break;
    case 1:
        for (i = 0; i < 16; i++)
        {
            c = Party_GetMember(i + 0x8000);
            if (c->unkE == 0xC000)
            {
                *list++ = i;
                count++;
            }
        }
        *list = 0xFFFF;
        break;
    case 2:
        for (i = 4; i < 16; i++)
        {
            c = Party_GetMember(i + 0x8000);
            if (c->unkE != 0)
            {
                *list++ = i;
                count++;
            }
        }
        *list = 0xFFFF;
        break;
    case 3:
        for (i = 4; i < 16; i++)
        {
            c = Party_GetMember(i + 0x8000);
            if (c->unkE == 0xC000)
            {
                *list++ = i;
                count++;
            }
        }
        *list = 0xFFFF;
        break;
    case 4:
        for (i = 4; i < 16; i++)
        {
            c = Party_GetMember(i + 0x8000);
            if (c->unkE == 0x8000)
            {
                *list++ = i;
                count++;
            }
        }
        *list = 0xFFFF;
        break;
    case 5:
        for (i = 0; i < 256; i++)
        {
            *list++ = i;
            count++;
        }
        *list = 0xFFFF;
        break;
    case 6:
        for (i = 0; i < 4; i++)
        {
            c = Party_GetMember(i + 0x8000);
            if (c->unkE == 0xC000)
            {
                *list++ = i;
                count++;
            }
        }
        *list = 0xFFFF;
        break;
    case 7:
        for (i = 4; i < 16; i++)
        {
            c = Party_GetMember(i + 0x8000);
            if (c->unkE == 0x8000 && Combatant_IsDead(i) == 0 && !Combatant_IsInParty(i))
            {
                found = 0;
                for (j = 0; j < 16; j++)
                {
                    if (blk->unkEF0[j] == i)
                        found = 1;
                }
                if (found != 1)
                {
                    *list++ = i;
                    count++;
                }
            }
        }
        *list = 0xFFFF;
        break;
    case 8:
        for (i = 4; i < 16; i++)
        {
            c = Party_GetMember(i + 0x8000);
            if (c->unkE != 0 && c->flags == 0)
            {
                *list++ = i;
                count++;
            }
        }
        *list = 0xFFFF;
        break;
    case 9:
        for (i = 4; i < 16; i++)
        {
            c = Party_GetMember(i + 0x8000);
            if (c->unkE == 0x8000 && Combatant_IsDead(i) == 1)
            {
                found = 0;
                for (j = 0; j < 16; j++)
                {
                    if (blk->unkEF0[j] == i)
                        found = 1;
                }
                if (found != 1)
                {
                    *list++ = i;
                    count++;
                }
            }
        }
        *list = 0xFFFF;
        break;
    }
    return count;
}

// sub_08127D70 @ 0x08127D70
void sub_08127D70(void)
{
    DmaSet3Wait(gWindowTilemapBuffer, 0x06001000, 0x84000200);
    DmaSet3Wait(gUnknown_08770C54, 0x06000000, 0x840000A0);
    DmaSet3Wait(gUnk_030000B4, 0x06006000, 0x84000800);
}

// sub_08127E04 @ 0x08127E04
void sub_08127E04(void)
{
    DmaSet3Wait(gWindowTilemapBuffer, 0x06001000, 0x84000200);
    DmaSet3Wait(gUnknown_08772294, 0x06000000, 0x840000A0);
    DmaSet3Wait(gUnk_030000B4, 0x06006000, 0x84000800);
}

// sub_08127E98 @ 0x08127E98
bool32 sub_08127E98(u16 id)
{
    if (id > 0x67)
        return 1;
    return 0;
}

/* Draws up to five rows of C127_BLOCK->list starting at `start`, one row per frame. */
// BattleMenu_DrawListPage @ 0x08127EAC
#ifdef NONMATCHING
void BattleMenu_DrawListPage(u8 mode, u16 start)
{
    struct C127Block *blk = C127_BLOCK;
    u16 name[8];
    u32 zero;
    u8 i;
    u16 v;
    u16 *str;
    u8 tint;
    u8 *rec;
    struct Combatant *c;
    u16 lo;

    zero = 0;
    CpuFastSet(&zero, gUnk_030000B4, 0x01000800);
    switch (mode)
    {
    case 0:
        i = 0;
        while ((v = blk->list[start + i]) != 0xFFFF)
        {
            c = Party_GetMember(v + 0x8000);
            if (c->race < 4)
            {
                Combatant_DecodeName(c, name);
                sub_081272CC(name, i);
            }
            else
            {
                sub_081272CC((u16 *)(Demon_GetRecord(c->demonId) + 0x22), i);
            }
            VBlankTask_AddCounted(sub_08127D70, 1);
            i++;
            if (i > 4)
                break;
        }
        break;
    case 1:
        i = 0;
        while ((v = blk->list[start + i]) != 0xFFFF)
        {
            if (v & 0x8000)
            {
                sub_08127394(gUnknown_08777D44, i, 2);
                VBlankTask_AddCounted(sub_08127D70, 1);
            }
            else
            {
                sub_081272CC((u16 *)(Demon_GetRecord(v) + 0x22), i);
                VBlankTask_AddCounted(sub_08127D70, 1);
            }
            i++;
            if (i > 4)
                break;
        }
        break;
    case 3:
        i = 0;
        while ((v = blk->list[start + i]) != 0xFFFF)
        {
            struct Combatant *m = Party_GetMember(v + 0x8000);

            tint = 0;
            if (sub_080C29B0(m->demonId))
                tint = 6;
            sub_08127394((u16 *)(Demon_GetRecord(m->demonId) + 0x22), i, tint);
            VBlankTask_AddCounted(sub_08127D70, 1);
            i++;
            if (i > 4)
                break;
        }
        break;
    case 4:
        i = 0;
        while ((v = blk->list[(start + i) * 2]) != 0xFFFF)
        {
            sub_081272CC((u16 *)(Action_GetRecord(v) + 0xC), i);
            sub_0812745C(blk->list[(start + i) * 2 + 1], i);
            VBlankTask_AddCounted(sub_08127E04, 1);
            i++;
            if (i > 4)
                break;
        }
        break;
    case 5:
        lo = start & 0xFF;
        start >>= 8;
        i = 0;
        while ((v = blk->list[(lo + i) * 2]) != 0xFFFF)
        {
            if (v < 0x80)
                str = (u16 *)(Item_GetRecord(v) + 0x14);
            else if (v < 0xD0)
                str = (u16 *)(Equipment_GetRecord36_MidRange(v) + 0x14);
            else if (v < 0xFF)
                str = (u16 *)(Action_GetRecord(v) + 0xC);
            tint = 0;
            if (v == start)
                tint = 2;
            sub_08127394(str, i, tint);
            sub_0812756C(blk->list[(lo + i) * 2 + 1], i, tint);
            VBlankTask_AddCounted(sub_08127E04, 1);
            i++;
            if (i > 4)
                break;
        }
        break;
    case 6:
        i = 0;
        while ((v = blk->list[(start + i) * 2]) != 0xFFFF)
        {
            if (v < 0x80)
                str = (u16 *)(Item_GetRecord(v) + 0x14);
            else if (v < 0xD0)
                str = (u16 *)(Equipment_GetRecord36_MidRange(v) + 0x14);
            else if (v < 0xFF)
                str = (u16 *)(Action_GetRecord(v) + 0xC);
            sub_081272CC(str, i);
            sub_0812745C(blk->list[(start + i) * 2 + 1], i);
            VBlankTask_AddCounted(sub_08127E04, 1);
            i++;
            if (i > 4)
                break;
        }
        break;
    case 7:
        i = 0;
        while ((v = blk->list[i + start]) != 0xFFFF)
        {
            u8 *r = sub_080BF5C0(v);

            sub_081272CC((u16 *)(r + 6), i);
            sub_08127678(r[3], i);
            VBlankTask_AddCounted(sub_08127E04, 1);
            i++;
            if (i > 4)
                break;
        }
        break;
    case 8:
        i = 0;
        while ((v = blk->list[i + start]) != 0xFFFF)
        {
            rec = sub_080BF5C0(v);
            sub_081272CC((u16 *)(rec + 6), i);
            if (sub_08127E98(v) == 1)
                sub_081277AC(gGameState.members[(u16)gGameState.order[blk->unk691]].maxHp * rec[3] / 100, i);
            else
                sub_08127678(rec[3], i);
            VBlankTask_AddCounted(sub_08127E04, 1);
            i++;
            if (i > 4)
                break;
        }
        break;
    }
}
#else
NAKED
void BattleMenu_DrawListPage(u8 mode, u16 start)
{
    asm_unified(
        ".L08127EAC:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x14\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r7, r1, #0x10\n"
        "    ldr r0, .L08127EE4\n"
        "    mov sb, r0\n"
        "    movs r0, #0\n"
        "    str r0, [sp, #0x10]\n"
        "    add r0, sp, #0x10\n"
        "    ldr r1, .L08127EE8\n"
        "    ldr r2, .L08127EEC\n"
        "    bl CpuFastSet\n"
        "    cmp r4, #8\n"
        "    bls .L08127ED8\n"
        "    b .L08128332\n"
        ".L08127ED8:\n"
        "    lsls r0, r4, #2\n"
        "    ldr r1, .L08127EF0\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        "    .byte 0x00, 0x00\n"
        ".L08127EE4: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L08127EE8: .4byte 0x030000B4 @ IWRAM+0xB4\n"
        ".L08127EEC: .4byte 0x01000800\n"
        ".L08127EF0: .4byte gUnknown_08127EF4\n"
        "    .global gUnknown_08127EF4\n"
        "gUnknown_08127EF4:\n"
        ".L08127EF4: @ jump table\n"
        "    .4byte .L08127F18\n"
        "    .4byte .L08127F98\n"
        "    .4byte .L08128332\n"
        "    .4byte .L0812801C\n"
        "    .4byte .L08128094\n"
        "    .4byte .L081280FC\n"
        "    .4byte .L081281A8\n"
        "    .4byte .L08128234\n"
        "    .4byte .L08128290\n"
        ".L08127F18:\n"
        "    movs r6, #0\n"
        "    lsls r1, r7, #1\n"
        "    movs r0, #0xb4\n"
        "    lsls r0, r0, #2\n"
        "    add r0, sb\n"
        "    adds r0, r0, r1\n"
        "    ldrh r4, [r0]\n"
        "    ldr r0, .L08127F58\n"
        "    cmp r4, r0\n"
        "    bne .L08127F2E\n"
        "    b .L08128332\n"
        ".L08127F2E:\n"
        "    adds r5, r0, #0\n"
        ".L08127F30:\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    adds r0, r4, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Party_GetMember\n"
        "    adds r1, r0, #0\n"
        "    ldrb r0, [r1, #0xc]\n"
        "    cmp r0, #3\n"
        "    bhi .L08127F5C\n"
        "    adds r0, r1, #0\n"
        "    mov r1, sp\n"
        "    bl Combatant_DecodeName\n"
        "    mov r0, sp\n"
        "    adds r1, r6, #0\n"
        "    bl sub_081272CC\n"
        "    b .L08127F6A\n"
        ".L08127F58: .4byte 0x0000FFFF\n"
        ".L08127F5C:\n"
        "    ldrh r0, [r1, #0x12]\n"
        "    bl Demon_GetRecord\n"
        "    adds r0, #0x22\n"
        "    adds r1, r6, #0\n"
        "    bl sub_081272CC\n"
        ".L08127F6A:\n"
        "    ldr r0, .L08127F94\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r6, r0, #0x18\n"
        "    cmp r6, #4\n"
        "    bls .L08127F7E\n"
        "    b .L08128332\n"
        ".L08127F7E:\n"
        "    adds r1, r6, r7\n"
        "    lsls r1, r1, #1\n"
        "    movs r0, #0xb4\n"
        "    lsls r0, r0, #2\n"
        "    add r0, sb\n"
        "    adds r0, r0, r1\n"
        "    ldrh r4, [r0]\n"
        "    cmp r4, r5\n"
        "    bne .L08127F30\n"
        "    b .L08128332\n"
        "    .byte 0x00, 0x00\n"
        ".L08127F94: .4byte sub_08127D70\n"
        ".L08127F98:\n"
        "    movs r6, #0\n"
        "    lsls r1, r7, #1\n"
        "    movs r0, #0xb4\n"
        "    lsls r0, r0, #2\n"
        "    add r0, sb\n"
        "    adds r0, r0, r1\n"
        "    ldrh r4, [r0]\n"
        "    ldr r0, .L08127FD4\n"
        "    cmp r4, r0\n"
        "    bne .L08127FAE\n"
        "    b .L08128332\n"
        ".L08127FAE:\n"
        "    adds r5, r0, #0\n"
        ".L08127FB0:\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #8\n"
        "    adds r1, r2, #0\n"
        "    adds r0, r4, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08127FE0\n"
        "    ldr r0, .L08127FD8\n"
        "    adds r1, r6, #0\n"
        "    movs r2, #2\n"
        "    bl sub_08127394\n"
        "    ldr r0, .L08127FDC\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    b .L08127FF6\n"
        "    .byte 0x00, 0x00\n"
        ".L08127FD4: .4byte 0x0000FFFF\n"
        ".L08127FD8: .4byte gUnknown_08777D44\n"
        ".L08127FDC: .4byte sub_08127D70\n"
        ".L08127FE0:\n"
        "    adds r0, r4, #0\n"
        "    bl Demon_GetRecord\n"
        "    adds r0, #0x22\n"
        "    adds r1, r6, #0\n"
        "    bl sub_081272CC\n"
        "    ldr r0, .L08128018\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        ".L08127FF6:\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r6, r0, #0x18\n"
        "    cmp r6, #4\n"
        "    bls .L08128002\n"
        "    b .L08128332\n"
        ".L08128002:\n"
        "    adds r1, r6, r7\n"
        "    lsls r1, r1, #1\n"
        "    movs r0, #0xb4\n"
        "    lsls r0, r0, #2\n"
        "    add r0, sb\n"
        "    adds r0, r0, r1\n"
        "    ldrh r4, [r0]\n"
        "    cmp r4, r5\n"
        "    bne .L08127FB0\n"
        "    b .L08128332\n"
        "    .byte 0x00, 0x00\n"
        ".L08128018: .4byte sub_08127D70\n"
        ".L0812801C:\n"
        "    movs r6, #0\n"
        "    lsls r1, r7, #1\n"
        "    movs r0, #0xb4\n"
        "    lsls r0, r0, #2\n"
        "    add r0, sb\n"
        "    adds r0, r0, r1\n"
        "    ldrh r4, [r0]\n"
        "    ldr r0, .L0812808C\n"
        "    cmp r4, r0\n"
        "    bne .L08128032\n"
        "    b .L08128332\n"
        ".L08128032:\n"
        "    mov r8, r0\n"
        ".L08128034:\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #8\n"
        "    adds r0, r4, r1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Party_GetMember\n"
        "    adds r4, r0, #0\n"
        "    movs r5, #0\n"
        "    movs r2, #0x12\n"
        "    ldrsh r0, [r4, r2]\n"
        "    bl sub_080C29B0\n"
        "    cmp r0, #0\n"
        "    beq .L08128054\n"
        "    movs r5, #6\n"
        ".L08128054:\n"
        "    ldrh r0, [r4, #0x12]\n"
        "    bl Demon_GetRecord\n"
        "    adds r0, #0x22\n"
        "    adds r1, r6, #0\n"
        "    adds r2, r5, #0\n"
        "    bl sub_08127394\n"
        "    ldr r0, .L08128090\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r6, r0, #0x18\n"
        "    cmp r6, #4\n"
        "    bls .L08128078\n"
        "    b .L08128332\n"
        ".L08128078:\n"
        "    adds r1, r6, r7\n"
        "    lsls r1, r1, #1\n"
        "    movs r0, #0xb4\n"
        "    lsls r0, r0, #2\n"
        "    add r0, sb\n"
        "    adds r0, r0, r1\n"
        "    ldrh r4, [r0]\n"
        "    cmp r4, r8\n"
        "    bne .L08128034\n"
        "    b .L08128332\n"
        ".L0812808C: .4byte 0x0000FFFF\n"
        ".L08128090: .4byte sub_08127D70\n"
        ".L08128094:\n"
        "    movs r6, #0\n"
        "    lsls r1, r7, #2\n"
        "    movs r0, #0xb4\n"
        "    lsls r0, r0, #2\n"
        "    add r0, sb\n"
        "    adds r0, r0, r1\n"
        "    ldrh r4, [r0]\n"
        "    ldr r0, .L081280F4\n"
        "    cmp r4, r0\n"
        "    bne .L081280AA\n"
        "    b .L08128332\n"
        ".L081280AA:\n"
        "    movs r5, #0xb4\n"
        "    lsls r5, r5, #2\n"
        "    add r5, sb\n"
        "    mov r8, r0\n"
        ".L081280B2:\n"
        "    adds r0, r4, #0\n"
        "    bl Action_GetRecord\n"
        "    adds r0, #0xc\n"
        "    adds r1, r6, #0\n"
        "    bl sub_081272CC\n"
        "    adds r0, r6, r7\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r5, r0\n"
        "    ldrh r0, [r0]\n"
        "    adds r1, r6, #0\n"
        "    bl sub_0812745C\n"
        "    ldr r0, .L081280F8\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r6, r0, #0x18\n"
        "    cmp r6, #4\n"
        "    bls .L081280E6\n"
        "    b .L08128332\n"
        ".L081280E6:\n"
        "    adds r0, r6, r7\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r5, r0\n"
        "    ldrh r4, [r0]\n"
        "    cmp r4, r8\n"
        "    bne .L081280B2\n"
        "    b .L08128332\n"
        ".L081280F4: .4byte 0x0000FFFF\n"
        ".L081280F8: .4byte sub_08127E04\n"
        ".L081280FC:\n"
        "    movs r0, #0xff\n"
        "    mov sl, r0\n"
        "    mov r1, sl\n"
        "    ands r1, r7\n"
        "    mov sl, r1\n"
        "    lsrs r7, r7, #8\n"
        "    movs r6, #0\n"
        "    lsls r0, r1, #2\n"
        "    movs r1, #0xb4\n"
        "    lsls r1, r1, #2\n"
        "    add r1, sb\n"
        "    adds r1, r1, r0\n"
        "    ldrh r4, [r1]\n"
        "    ldr r0, .L0812812C\n"
        "    cmp r4, r0\n"
        "    bne .L0812811E\n"
        "    b .L08128332\n"
        ".L0812811E:\n"
        "    cmp r4, #0x7f\n"
        "    bhi .L08128130\n"
        "    adds r0, r4, #0\n"
        "    bl Item_GetRecord\n"
        "    adds r0, #0x14\n"
        "    b .L0812814A\n"
        ".L0812812C: .4byte 0x0000FFFF\n"
        ".L08128130:\n"
        "    cmp r4, #0xcf\n"
        "    bhi .L0812813E\n"
        "    adds r0, r4, #0\n"
        "    bl Equipment_GetRecord36_MidRange\n"
        "    adds r0, #0x14\n"
        "    b .L0812814A\n"
        ".L0812813E:\n"
        "    cmp r4, #0xfe\n"
        "    bhi .L0812814C\n"
        "    adds r0, r4, #0\n"
        "    bl Action_GetRecord\n"
        "    adds r0, #0xc\n"
        ".L0812814A:\n"
        "    mov r8, r0\n"
        ".L0812814C:\n"
        "    movs r5, #0\n"
        "    cmp r4, r7\n"
        "    bne .L08128154\n"
        "    movs r5, #2\n"
        ".L08128154:\n"
        "    mov r0, r8\n"
        "    adds r1, r6, #0\n"
        "    adds r2, r5, #0\n"
        "    bl sub_08127394\n"
        "    mov r2, sl\n"
        "    adds r0, r6, r2\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #1\n"
        "    movs r4, #0xb4\n"
        "    lsls r4, r4, #2\n"
        "    add r4, sb\n"
        "    adds r0, r4, r0\n"
        "    ldrh r0, [r0]\n"
        "    adds r1, r6, #0\n"
        "    adds r2, r5, #0\n"
        "    bl sub_0812756C\n"
        "    ldr r0, .L081281A0\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r6, r0, #0x18\n"
        "    cmp r6, #4\n"
        "    bls .L0812818E\n"
        "    b .L08128332\n"
        ".L0812818E:\n"
        "    mov r1, sl\n"
        "    adds r0, r6, r1\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r4, r0\n"
        "    ldrh r4, [r0]\n"
        "    ldr r0, .L081281A4\n"
        "    cmp r4, r0\n"
        "    bne .L0812811E\n"
        "    b .L08128332\n"
        ".L081281A0: .4byte sub_08127E04\n"
        ".L081281A4: .4byte 0x0000FFFF\n"
        ".L081281A8:\n"
        "    movs r6, #0\n"
        "    lsls r1, r7, #2\n"
        "    movs r0, #0xb4\n"
        "    lsls r0, r0, #2\n"
        "    add r0, sb\n"
        "    adds r0, r0, r1\n"
        "    ldrh r4, [r0]\n"
        "    ldr r0, .L081281CC\n"
        "    cmp r4, r0\n"
        "    bne .L081281BE\n"
        "    b .L08128332\n"
        ".L081281BE:\n"
        "    mov r8, r0\n"
        ".L081281C0:\n"
        "    cmp r4, #0x7f\n"
        "    bhi .L081281D0\n"
        "    adds r0, r4, #0\n"
        "    bl Item_GetRecord\n"
        "    b .L081281DA\n"
        ".L081281CC: .4byte 0x0000FFFF\n"
        ".L081281D0:\n"
        "    cmp r4, #0xcf\n"
        "    bhi .L081281E0\n"
        "    adds r0, r4, #0\n"
        "    bl Equipment_GetRecord36_MidRange\n"
        ".L081281DA:\n"
        "    adds r5, r0, #0\n"
        "    adds r5, #0x14\n"
        "    b .L081281EE\n"
        ".L081281E0:\n"
        "    cmp r4, #0xfe\n"
        "    bhi .L081281EE\n"
        "    adds r0, r4, #0\n"
        "    bl Action_GetRecord\n"
        "    adds r5, r0, #0\n"
        "    adds r5, #0xc\n"
        ".L081281EE:\n"
        "    adds r0, r5, #0\n"
        "    adds r1, r6, #0\n"
        "    bl sub_081272CC\n"
        "    adds r0, r6, r7\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #1\n"
        "    movs r4, #0xb4\n"
        "    lsls r4, r4, #2\n"
        "    add r4, sb\n"
        "    adds r0, r4, r0\n"
        "    ldrh r0, [r0]\n"
        "    adds r1, r6, #0\n"
        "    bl sub_0812745C\n"
        "    ldr r0, .L08128230\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r6, r0, #0x18\n"
        "    cmp r6, #4\n"
        "    bls .L08128222\n"
        "    b .L08128332\n"
        ".L08128222:\n"
        "    adds r0, r6, r7\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r4, r0\n"
        "    ldrh r4, [r0]\n"
        "    cmp r4, r8\n"
        "    bne .L081281C0\n"
        "    b .L08128332\n"
        ".L08128230: .4byte sub_08127E04\n"
        ".L08128234:\n"
        "    movs r6, #0\n"
        "    lsls r1, r7, #1\n"
        "    movs r0, #0xb4\n"
        "    lsls r0, r0, #2\n"
        "    add r0, sb\n"
        "    adds r0, r0, r1\n"
        "    ldrh r4, [r0]\n"
        "    ldr r0, .L08128288\n"
        "    cmp r4, r0\n"
        "    beq .L08128332\n"
        "    adds r5, r0, #0\n"
        ".L0812824A:\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080BF5C0\n"
        "    adds r4, r0, #0\n"
        "    adds r0, r4, #6\n"
        "    adds r1, r6, #0\n"
        "    bl sub_081272CC\n"
        "    ldrb r0, [r4, #3]\n"
        "    adds r1, r6, #0\n"
        "    bl sub_08127678\n"
        "    ldr r0, .L0812828C\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r6, r0, #0x18\n"
        "    cmp r6, #4\n"
        "    bhi .L08128332\n"
        "    adds r1, r6, r7\n"
        "    lsls r1, r1, #1\n"
        "    movs r0, #0xb4\n"
        "    lsls r0, r0, #2\n"
        "    add r0, sb\n"
        "    adds r0, r0, r1\n"
        "    ldrh r4, [r0]\n"
        "    cmp r4, r5\n"
        "    bne .L0812824A\n"
        "    b .L08128332\n"
        ".L08128288: .4byte 0x0000FFFF\n"
        ".L0812828C: .4byte sub_08127E04\n"
        ".L08128290:\n"
        "    movs r6, #0\n"
        "    lsls r0, r7, #1\n"
        "    movs r1, #0xb4\n"
        "    lsls r1, r1, #2\n"
        "    add r1, sb\n"
        "    adds r1, r1, r0\n"
        "    ldrh r4, [r1]\n"
        "    ldr r0, .L081282F8\n"
        "    cmp r4, r0\n"
        "    beq .L08128332\n"
        "    ldr r2, .L081282FC\n"
        "    mov r8, r2\n"
        ".L081282A8:\n"
        "    adds r0, r4, #0\n"
        "    bl sub_080BF5C0\n"
        "    adds r5, r0, #0\n"
        "    adds r0, r5, #6\n"
        "    adds r1, r6, #0\n"
        "    bl sub_081272CC\n"
        "    adds r0, r4, #0\n"
        "    bl sub_08127E98\n"
        "    cmp r0, #1\n"
        "    bne .L08128304\n"
        "    ldr r1, .L08128300\n"
        "    add r1, sb\n"
        "    movs r0, #0xa2\n"
        "    lsls r0, r0, #4\n"
        "    add r0, r8\n"
        "    ldrb r1, [r1]\n"
        "    adds r0, r0, r1\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    lsls r0, r0, #0x10\n"
        "    ldrb r1, [r5, #3]\n"
        "    lsrs r0, r0, #9\n"
        "    add r0, r8\n"
        "    movs r2, #0x1a\n"
        "    ldrsh r0, [r0, r2]\n"
        "    muls r0, r1, r0\n"
        "    movs r1, #0x64\n"
        "    bl __divsi3\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    adds r1, r6, #0\n"
        "    bl sub_081277AC\n"
        "    b .L0812830C\n"
        "    .byte 0x00, 0x00\n"
        ".L081282F8: .4byte 0x0000FFFF\n"
        ".L081282FC: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L08128300: .4byte 0x00000691\n"
        ".L08128304:\n"
        "    ldrb r0, [r5, #3]\n"
        "    adds r1, r6, #0\n"
        "    bl sub_08127678\n"
        ".L0812830C:\n"
        "    ldr r0, .L08128344\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    adds r0, r6, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r6, r0, #0x18\n"
        "    cmp r6, #4\n"
        "    bhi .L08128332\n"
        "    adds r0, r6, r7\n"
        "    lsls r0, r0, #1\n"
        "    movs r1, #0xb4\n"
        "    lsls r1, r1, #2\n"
        "    add r1, sb\n"
        "    adds r1, r1, r0\n"
        "    ldrh r4, [r1]\n"
        "    ldr r0, .L08128348\n"
        "    cmp r4, r0\n"
        "    bne .L081282A8\n"
        ".L08128332:\n"
        "    add sp, #0x14\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L08128344: .4byte sub_08127E04\n"
        ".L08128348: .4byte 0x0000FFFF\n"
    );
}
#endif

// sub_0812834C @ 0x0812834C
void sub_0812834C(void)
{
    DmaFill3Wait(0, 0x06000000, 0x850000A0);
}
