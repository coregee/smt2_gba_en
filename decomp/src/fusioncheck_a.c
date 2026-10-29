#include "global.h"
#include "options.h"

// sub_080CE62C @ 0x080CE62C
/* Opens the stat allocation screen (mode 4) for member sel with points to distribute. */
struct Task *sub_080CE62C(u16 sel, u16 points)
{
    struct Task *task = Task_Create(gUnknown_084F0CBC, 0xFFFF);
    struct C0c6Status *m = &gMenuState;
    vu32 zero = 0;

    CpuSet((void *)&zero, m, 0x05000200);
    m->unk36 = points;
    /* the original sign-extends and masks again here */
    m->unk34 = (s16)points % 0x10000U;
    m->sel = sel;
    m->mode = 4;
    m->unk22 = 0;
    m->unk06 = 2;
    m->unk08 = 3;
    gUnk_03004600 = gUnk_0300000E;
    Party_BuildSkillList(gGameState.members[m->sel].id);
    return task;
}

// sub_080CE6C4 @ 0x080CE6C4
/* Same screen in mode 5. */
struct Task *sub_080CE6C4(u16 sel, u16 points)
{
    struct Task *task = Task_Create(gUnknown_084F0CBC, 0xFFFF);
    struct C0c6Status *m = &gMenuState;
    vu32 zero = 0;

    CpuSet((void *)&zero, m, 0x05000200);
    m->unk36 = points;
    m->unk34 = (s16)points % 0x10000U;
    m->sel = sel;
    m->mode = 5;
    m->unk22 = 0;
    m->unk06 = 2;
    m->unk08 = 3;
    gUnk_03004600 = gUnk_0300000E;
    return task;
}

// sub_080CE74C @ 0x080CE74C
u32 sub_080CE74C(u16 *p)
{
    u32 r = 0;

    if (*p == 0)
        r = 1;
    return r;
}

// sub_080CE760 @ 0x080CE760
/* Fusion checks and messages, one step per call (gUnk_0203B854: the three parents, the result
   demon at [3], the fusion kind at [4]).  Step 0 sets t->result when the fusion is refused and
   t->pad1E to the reason (1 already owned, 2 level too low, 3 too many items, 4 stock full). */
void sub_080CE760(struct Task *t, s32 step)
{
    struct C0c6Status *m = &gMenuState;
    struct Combatant *hero = Party_GetMember(0x8000);
    u16 *f = gUnk_0203B854;
    u16 kind = f[4];
    u16 demon;

    t->result = 0;
    if (step == 0)
    {
        demon = f[3];
        if (kind == 1 || kind == 4 || kind == 5)
        {
            u16 item = Fusion_GetDemonByIndex(gUnk_0203B854[3]);
            u8 held = Inventory_GetCount(item);

            if (held + Party_CountEquipped(0xFF, item) > 98)
            {
                t->result = 1;
                t->pad1E = 3;
            }
            return;
        }
        if (kind == 6)
        {
            u16 n, i;

            if (Stock_FindByDemonId(demon) != NULL)
                goto owned;
            n = 0;
            for (i = 0; i < 12; i++)
            {
                if (Combatant_IsUsed(i + 4))
                    n++;
            }
            if (n >= Stock_GetCapacity())
            {
                t->result = 1;
                t->pad1E = 4;
                return;
            }
        }
        else if (Stock_FindByDemonId(demon) != NULL && f[0] != demon && f[1] != demon && f[2] != demon)
        {
        owned:
            t->result = 1;
            t->pad1E = 1;
            return;
        }
        {
            u32 high;

            if (gUnk_0203B854[4] == 3 && (high = Fusion_AllHighRace(gUnk_0203B854[0], gUnk_0203B854[1], gUnk_0203B854[2])) == 1)
            {
                if (hero->level + 9 < Demon_GetRecord(demon)[1])
                {
                    t->result = high;
                    t->pad1E = 2;
                }
            }
            else if (hero->level < Demon_GetRecord(demon)[1])
            {
                t->result = 1;
                t->pad1E = 2;
            }
        }
    }
    else if (step == 1)
    {
        MENU_WINDOW50(m) = Window_CreateOpen(2, 0xB, 0x1A, 7, 0);
        Font_ResetGlyphSpriteCache(0x180);
    }
    else if (step == 2)
    {
        if (gKeysNew & 1)
        {
            t->result = 1;
            gYesNoResult = 1;
            Window_Close(MENU_WINDOW50(m), 1);
            Sound_Play(0x65);
            return;
        }
        if (t->pad1E == 1)
            Text_DrawSpriteString(gUnknown_0815BF4A, 0, 0, 0x12, 0x5B, 0xC);
        else if (t->pad1E == 2)
            Text_DrawSpriteString(gUnknown_0815BF0E, 0, 0, 0x12, 0x5B, 0xC);
        else if (t->pad1E == 3)
            Text_DrawSpriteString(gUnknown_0815BF62, 0, 0, 0x12, 0x5B, 0xC);
        else
            Text_DrawSpriteString(gUnknown_0815BF7C, 0, 0, 0x12, 0x5B, 0xC);
        if (!((gFrameCounter >> 4) & 1))
            sub_080C4AB0(0, 0, 0xD5, 0x85);
    }
    else if (step == 3)
    {
        MENU_WINDOW50(m) = Window_CreateOpen(2, 0xB, 0x1A, 7, 0);
        MENU_WINDOW4C(m) = YesNo_Create(0);
        Font_ResetGlyphSpriteCache(0x180);
    }
    else if (step == 4)
    {
        u32 r = Task_IsFree(MENU_WINDOW4C(m));

        if (r == 1)
        {
            t->result = r;
            Window_Close(MENU_WINDOW50(m), 1);
        }
        else
        {
            Text_DrawSpriteString(gUnknown_0815BED4, 0, 0, 0x12, 0x5B, 0xC);
        }
    }
    else if (step == 5)
    {
        s32 align = Combatant_GetAlignment(hero->id);
        s32 dalign = sub_0815B864(f[3]);

        if (f[4] == 1 || f[4] == 4 || f[4] == 5)
            return;
        if ((align == 0 && dalign == 2) || (align == 2 && dalign == 0))
            t->result = 1;
    }
    else if (step == 6)
    {
        u32 r = Task_IsFree(MENU_WINDOW4C(m));

        if (r == 1)
        {
            t->result = r;
            Window_Close(MENU_WINDOW50(m), 1);
        }
        else
        {
            Text_DrawSpriteString(gUnknown_0815BF36, 0, 0, 0x12, 0x5B, 0xC);
        }
    }
    else if (step == 7)
    {
        MENU_WINDOW50(m) = Window_CreateOpen(2, 0xB, 0x1A, 7, 0);
        Font_ResetGlyphSpriteCache(0x180);
    }
    else if (step == 8)
    {
        if (gKeysNew & 1)
        {
            t->result = 1;
            Window_Close(MENU_WINDOW50(m), 1);
            return;
        }
        Text_DrawSpriteString(gUnknown_0815BEFA, 0, 0, 0x12, 0x5B, 0xC);
        if (!((gFrameCounter >> 4) & 1))
            sub_080C4AB0(0, 0, 0xD5, 0x85);
    }
    else if (step == 9)
    {
        if (f[4] == 6)
            t->result = 1;
    }
    else if (step == 10)
    {
        u32 r = Task_IsFree(MENU_WINDOW4C(m));

        if (r == 1)
        {
            t->result = r;
            Window_Close(MENU_WINDOW50(m), 1);
        }
        else
        {
            u16 x;
            s32 cost;
            u16 y;

            Text_DrawSpriteString(gUnknown_0815BFBE, 0, 0, 0x12, 0x5B, 0xC);
            cost = Compendium_GetPrice(gUnk_0203B854[3]);
            y = 0x67;
            x = Comp_DrawSummonCost(cost, 0x12, y);
            Text_DrawSpriteString(gUnknown_0815BFCC, 0, 0, x + 12, y, 0xC);
            Text_DrawSpriteString(gUnknown_0815BFD6, 0, 0, 0x12, 0x73, 0xC);
        }
    }
}

// Comp_DrawSummonCost @ 0x080CEAD0
/* Draws the macca sign and value (leading zeros hidden) as 12-pixel sprite glyphs; returns the x after them. */
u16 Comp_DrawSummonCost(s32 value, u16 x, u16 y)
{
    u8 *digits = NumberToDigits(value);
    u32 shown = 0;
    s8 i;

    FontSprite_DrawGlyph(0x52, 0, 0, x, y);
    x += 12;
    for (i = 0; i < 8; i++)
    {
        if (shown == 1 || digits[7 - i] != 0)
        {
            FontSprite_DrawGlyph(gUnknown_084F0EAC[digits[7 - i]], 0, 0, x, y);
            shown = 1;
            x += 12;
        }
    }
    return x;
}

// sub_080CEB60 @ 0x080CEB60
void sub_080CEB60(struct Task *t)
{
    struct C0c6Status *m = &gMenuState;

    Status_GetCombatant(m->sel);
    sub_080C964C(0);
    t->pad1E = 0;
    if ((gKeysNew & 0x80) && gUnk_0203B854[4] != 1 && gUnk_0203B854[4] != 4 && gUnk_0203B854[4] != 5)
    {
        if (sub_080C93B4(m->sel) == 1)
        {
            Sound_Play(0x64);
            t->pad1E = 0x8001;
        }
        else if (sub_080C9388(m->sel) == 1)
        {
            Sound_Play(0x64);
            t->pad1E = 0x8002;
        }
        else
        {
            Sound_Play(0x64);
            t->pad1E = 0x8003;
        }
    }
    else if (gKeysNew & 1)
    {
        Sound_Play(0x65);
        t->pad1E = 2;
    }
    else if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        t->pad1E = 3;
        gYesNoResult = 1;
    }
    if (gUnk_0203B854[4] != 1 && gUnk_0203B854[4] != 4 && gUnk_0203B854[4] != 5)
        sub_080C4AB0(0, 0, 0x92, 0x76);
}

// sub_080CEC4C @ 0x080CEC4C
void sub_080CEC4C(struct Task *t)
{
    struct C0c6Status *m = &gMenuState;

    if (m->sprite != NULL)
    {
        DemonObj_End(m->sprite, 0);
        m->sprite = NULL;
    }
    TextWindow_Close(m->window40, 1);
    TextWindow_Close(m->window44, 1);
    TextWindow_Close(m->window48, 1);
    if (gUnk_0203B854[4] != 6)
        sub_08157EB0(0, t, m->fade);
    else
        sub_08157EB0(3, t, m->fade);
}

// sub_080CECA8 @ 0x080CECA8
void sub_080CECA8(void)
{
    struct C0c6Status *m = &gMenuState;

    if (m->sprite != NULL)
    {
        DemonObj_End(m->sprite, 0);
        m->sprite = NULL;
    }
    TextWindow_Close(m->window40, 1);
    TextWindow_Close(m->window44, 1);
    TextWindow_Close(m->window48, 1);
    Font_ResetGlyphSpriteCache(0x180);
    gUnk_030068E0 = Fusion_ResumeScreen(0);
}

// sub_080CECF4 @ 0x080CECF4
void sub_080CECF4(void)
{
    sub_080C1384();
}

// sub_080CED00 @ 0x080CED00
struct Task *sub_080CED00(void)
{
    struct Task *task = Task_Create(gUnknown_084F0EC0, 0xFFFF);
    struct C0c6Status *m = &gMenuState;
    vu32 zero = 0;

    CpuSet((void *)&zero, m, 0x05000200);
    m->sel = 0;
    m->mode = 6;
    m->unk22 = 0;
    return task;
}

// sub_080CED40 @ 0x080CED40
void sub_080CED40(void)
{
    struct C0c6Status *m = &gMenuState;
    u16 *list = gStatusList;

    LZ77UnCompWram(gUnknown_081B5870, gUnk_0200F874);
    VBlankTask_AddCounted(sub_080C93E0, 1);
    list[0] = 0x8000 + m->sel;
    m->count = 1;
    m->sel = 0;
    m->unk10 = 0;
    if (sub_080C9388(0) == 1)
        m->unk16 = 1;
    else
        m->unk16 = 0;
    m->unk18 = 1;
    m->unk1C = 0;
    m->unk1E = 0;
}

// sub_080CEDA4 @ 0x080CEDA4
void sub_080CEDA4(struct Task *t)
{
    struct C0c6Status *m = &gMenuState;
    struct Combatant *c = Status_GetCombatant(m->sel);
    u32 locked;

    sub_080C964C(0);
    locked = sub_080C92AC(c->demonId);
    t->pad1E = 0;
    if (sub_080C99B8(c) == 1)
        locked = 1;
    if ((gKeysNew & 0x80) && locked == 0)
    {
        Sound_Play(0x64);
        t->pad1E = 0x8003;
    }
    else if ((gKeysNew & 0x100) || (gKeysNew & 2))
    {
        Sound_Play(0x66);
        t->pad1E = 3;
        gYesNoResult = 1;
    }
    sub_080C981C(m->page == 0 ? m->unk20 : 0);
    sub_080C9994();
    if (locked == 0)
        sub_080C4AB0(0, 0, 0x92, 0x76);
}

// sub_080CEE4C @ 0x080CEE4C
void sub_080CEE4C(void)
{
    REG_DISPCNT |= 0x400;
}

// sub_080CEE60 @ 0x080CEE60
void sub_080CEE60(void)
{
    Status_DrawScreen();
    VBlankTask_AddCounted(sub_080CEE4C, 1);
}

// sub_080CEE78 @ 0x080CEE78
void sub_080CEE78(void)
{
    sub_08154EC0();
    DmaFill32_3(0, 0x06000000, 0x85000400);
    DmaFill32_3(0, 0x06001000, 0x85000400);
    DmaFill32_3(0, 0x06002000, 0x85000400);
}

// sub_080CEEC8 @ 0x080CEEC8
void sub_080CEEC8(void)
{
    struct C0c6Status *m = &gMenuState;

    if (m->sprite != NULL)
    {
        DemonObj_End(m->sprite, 0);
        m->sprite = NULL;
    }
}

// sub_080CEEE8 @ 0x080CEEE8
/* Closes the status windows and restores gMenuState from the copy at 0x0203AC54. */
void sub_080CEEE8(void)
{
    struct C0c6Status *m = &gMenuState;

    if (m->sprite != NULL)
    {
        DemonObj_End(m->sprite, 0);
        m->sprite = NULL;
    }
    TextWindow_Close(m->window40, 1);
    TextWindow_Close(m->window44, 1);
    TextWindow_Close(m->window48, 1);
    CpuSet(gUnk_0203AC54, m, 0x04000200);
    VBlankTask_AddCounted(sub_080CEE78, 1);
}

// sub_080CEF3C @ 0x080CEF3C
void sub_080CEF3C(void)
{
    LZ77UnCompWram(gUnknown_081B5870, gUnk_0200F874);
    VBlankTask_AddCounted(sub_080C93E0, 1);
}

// sub_080CEF60 @ 0x080CEF60
/* Builds the status list from sub_080D45F0 (modes 0xB/0xC; any other mode passes an
   uninitialised filter, as in the original). */
void sub_080CEF60(void)
{
    struct C0c6Status *m = &gMenuState;
    u16 *list = gStatusList;
    u16 filter;
    u16 n, i;

    switch (m->mode)
    {
    case 0xB:
        filter = 0;
        break;
    case 0xC:
        filter = 1;
        break;
    }
    n = sub_080D45F0(list, filter);
    for (i = 0; i < n; i++)
        list[i] |= 0x8000;
    m->count = n;
    m->unk10 = 0;
    if (sub_080C9388(m->sel) == 1)
        m->unk16 = 1;
    else
        m->unk16 = 0;
    m->unk18 = 1;
    m->unk1C = 0;
    m->unk1E = 0;
}

// sub_080CEFD4 @ 0x080CEFD4
/* Pauses every running task except t and the screen's fade task. */
void sub_080CEFD4(struct Task *t)
{
    struct C0c6Status *m = &gMenuState;
    u32 i;

    for (i = 0; i < 64; i++)
    {
        struct Task *o = &gTasks[i];

        if ((void *)m->fade != o && t != o && o->state == 1)
            Task_Pause(o);
    }
}

// sub_080CF010 @ 0x080CF010
/* Resumes the tasks paused by sub_080CEFD4 and redraws the demon when there were any. */
void sub_080CF010(struct Task *t)
{
    struct C0c6Status *m = &gMenuState;
    struct Combatant *c = Status_GetCombatant(m->sel);
    u32 resumed = 0;
    u32 i;

    for (i = 0; i < 64; i++)
    {
        struct Task *o = &gTasks[i];

        if ((void *)m->fade != o && t != o && o->state == 0xFFFF)
        {
            Task_Resume(o);
            resumed = 1;
        }
    }
    if (resumed == 1)
        sub_080D3F04(t, c->demonId, 1);
}

// sub_080CF078 @ 0x080CF078
void sub_080CF078(struct Task *t)
{
    struct C0c6Status *m = &gMenuState;
    u32 count;
    u16 key;
    u32 se;

    Status_GetCombatant(m->sel);
    count = sub_080C964C(0);
    t->pad1E = 0;
    if (sub_080C9388(m->sel) == 1)
    {
        key = 1;
        se = 0x65;
    }
    else
    {
        key = 0x80;
        se = 0x64;
        sub_080C4AB0(0, 0, 0x92, 0x76);
    }
    if (gKeysNew & 1)
    {
        Sound_Play(0x65);
        t->pad1E = 1;
    }
    else if (gKeysNew & key)
    {
        Sound_Play(se);
        t->pad1E = 0x8003;
    }
    else if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        t->pad1E = 3;
        gYesNoResult = 1;
    }
    else if ((gKeysNew & 0x200) && m->unk22 == 0 && sub_080C964C(0) != 1)
    {
        Sound_Play(0x64);
        if (m->sel != 0)
            m->sel--;
        else
            m->sel = count - 1;
        m->unk0A = 0xFFF0;
        t->pad1E = 2;
        sub_080CA684();
    }
    else if ((gKeysNew & 0x100) && m->unk22 == 0 && sub_080C964C(0) != 1)
    {
        Sound_Play(0x64);
        if (m->sel != count - 1)
            m->sel++;
        else
            m->sel = 0;
        m->unk0A = 0x10;
        t->pad1E = 2;
        sub_080CA684();
    }
}

// sub_080CF1A8 @ 0x080CF1A8
void sub_080CF1A8(void)
{
    struct C0c6Status *m = &gMenuState;

    MENU_WINDOW50(m) = Window_CreateOpen(2, 0xB, 0x1A, 8, 0);
    MENU_WINDOW4C(m) = YesNo_Create(0);
    Font_ResetGlyphSpriteCache(0x180);
}

// FontSprite_DrawNumber @ 0x080CF1DC
/* Comp_DrawSummonCost without the macca sign. */
u16 FontSprite_DrawNumber(s32 value, u16 x, u16 y)
{
    u8 *digits = NumberToDigits(value);
    u32 shown = 0;
    s8 i;

    for (i = 0; i < 8; i++)
    {
        if (shown == 1 || digits[7 - i] != 0)
        {
            FontSprite_DrawGlyph(gUnknown_084F0EAC[digits[7 - i]], 0, 0, x, y);
            shown = 1;
            x += 12;
        }
    }
    return x;
}

// sub_080CF250 @ 0x080CF250
/* Draws the confirmation message (0x300 new line, 0x301 end, 0xCC/0xCD the two prices of the
   demon) as 12-pixel sprite glyphs from (0x12, 0x5B); closes the window on yes. */
void sub_080CF250(struct Task *t)
{
    struct C0c6Status *m = &gMenuState;
    u16 demon = Status_GetCombatant(m->sel)->demonId;
    const u16 *s;
    u16 x, y, left;
    u32 r;

    t->result = 0;
    r = Task_IsFree(MENU_WINDOW4C(m));
    if (r == 1)
    {
        t->result = r;
        if (gYesNoResult == 1)
            Window_Close(MENU_WINDOW50(m), 1);
    }
    if (m->mode == 0xB)
        s = gUnknown_0815BFEA;
    else
        s = gUnknown_0815C0AA;
    x = 0x12;
    y = 0x5B;
    left = x;
    while (*s != 0x301)
    {
        if (*s == 0x300)
        {
            x = left;
            y += 12;
        }
        else if (*s == 0xCC)
        {
            x = FontSprite_DrawNumber(sub_080D45B8(demon), x, y);
        }
        else if (*s == 0xCD)
        {
            x = FontSprite_DrawNumber(Compendium_GetPrice(demon), x, y);
        }
        else
        {
            FontSprite_DrawGlyph(*s, 0, 0, x, y);
            x += 12;
        }
        s++;
    }
}

// sub_080CF324 @ 0x080CF324
/* Checks a compendium summon (mode 0xB) or purchase: t->pad1E = 1 missing item 0x11F count,
   2 not enough money, 3 stock full, 4 level too low, 5 alignment clash. */
void sub_080CF324(struct Task *t)
{
    struct C0c6Status *m = &gMenuState;
    struct Combatant *hero = Party_GetMember(0x8000);
    u16 demon = Status_GetCombatant(m->sel)->demonId;

    t->pad1E = 0;
    if (m->mode == 0xB)
    {
        s32 n, i;
        s32 align, dalign;

        if (Inventory_GetCount(0x11F) < sub_080D45B8(demon))
        {
            t->pad1E = 1;
            return;
        }
        if (Money_Get() < Compendium_GetPrice(demon))
        {
            t->pad1E = 2;
            return;
        }
        n = 0;
        for (i = 0; i < 12; i++)
        {
            if (Combatant_IsUsed(i + 4))
                n++;
        }
        if (n >= Stock_GetCapacity())
        {
            t->pad1E = 3;
            return;
        }
        if (hero->level < Demon_GetRecord(demon)[1])
        {
            t->pad1E = 4;
            return;
        }
        align = Combatant_GetAlignment(hero->id);
        dalign = sub_0815B864(demon);
        if ((align == 0 && dalign == 2) || (align == 2 && dalign == 0))
        {
            t->pad1E = 5;
            return;
        }
    }
    else if (Money_Get() < Compendium_GetPrice(demon))
    {
        t->pad1E = 2;
        return;
    }
    Window_Close(MENU_WINDOW50(m), 1);
}

// sub_080CF414 @ 0x080CF414
void sub_080CF414(struct Task *t)
{
    struct C0c6Status *m = &gMenuState;

    t->result = 0;
    if (gKeysNew & 1)
    {
        t->result = 1;
        gYesNoResult = 1;
        Window_Close(MENU_WINDOW50(m), 1);
        Sound_Play(0x65);
        return;
    }
    if (t->pad1E == 1)
        Text_DrawSpriteString(gUnknown_0815C02C, 0, 0, 0x12, 0x5B, 0xC);
    else if (t->pad1E == 2)
        Text_DrawSpriteString(gUnknown_0815C048, 0, 0, 0x12, 0x5B, 0xC);
    else if (t->pad1E == 3)
        Text_DrawSpriteString(gUnknown_0815C05A, 0, 0, 0x12, 0x5B, 0xC);
    else if (t->pad1E == 4)
        Text_DrawSpriteString(gUnknown_0815C06E, 0, 0, 0x12, 0x5B, 0xC);
    else if (t->pad1E == 5)
        Text_DrawSpriteString(gUnknown_0815C082, 0, 0, 0x12, 0x5B, 0xC);
    if (!((gFrameCounter >> 4) & 1))
        sub_080C4AB0(0, 0, 0xD5, 0x8D);
}

// sub_080CF4DC @ 0x080CF4DC
/* Ends every running task but t and resets the window/HUD state. */
void sub_080CF4DC(struct Task *t)
{
    u32 i;

    for (i = 0; i < 64; i++)
    {
        struct Task *o = &gTasks[i];

        if (t != o && o->state == 0xFFFF)
            Task_End(o);
    }
    gUnk_0203DB6A = 0;
    sub_080AE2D0();
    gWindowCount = 0;
    gOpenWindowCount = 0;
    sub_080C6E30(0);
    gHud->unk30 = 1;
    {
        vu32 tmp = 0;
        CpuSet((void *)&tmp, &gSaveSlotPreview, 0x05000200);
    }
    {
        vu32 tmp = 0;
        CpuSet((void *)&tmp, (u8 *)&gSaveSlotPreview + 0x1000, 0x05000200);
    }
    gUnk_03004534 = 0xBE;
}

// sub_080CF57C @ 0x080CF57C
void sub_080CF57C(void)
{
    struct C0c6Status *m = &gMenuState;
    struct Combatant *c = Status_GetCombatant(m->sel);
    struct Task *n;

    if (m->mode == 0xB)
    {
        Flag_Clear(0x162);
        n = Task_Create(gUnknown_084F3880, m->fade->unk2);
    }
    else
    {
        n = Task_Create(gUnknown_084F39B4, m->fade->unk2);
    }
    n->pad1E = c->demonId;
}

// sub_080CF5C0 @ 0x080CF5C0
void sub_080CF5C0(void)
{
    sub_0812D0FC(1);
}

// sub_080CF5CC @ 0x080CF5CC
void sub_080CF5CC(void)
{
    struct C0c6Status *m = &gMenuState;

    MENU_FADE08(m) = sub_080B6B58(sub_080CF5C0, 0);
}

// sub_080CF5E8 @ 0x080CF5E8
void sub_080CF5E8(struct Task *t)
{
    struct C0c6Status *m = &gMenuState;

    if (MENU_FADE08(m)->unkC == -1)
        t->result = 1;
    else
        t->result = 0;
}

// sub_080CF60C @ 0x080CF60C
void sub_080CF60C(void)
{
    struct C0c6Status *m = &gMenuState;

    MENU_FADE08(m)->unkC = 1;
}

// sub_080CF61C @ 0x080CF61C
void sub_080CF61C(void)
{
    REG_BG1CNT = 0x8205;
    REG_DISPCNT &= 0xFBFF;
    gUnk_03000040 = 0;
    DmaSet3(gUnknown_081B93B0, 0x06000000, 0x84000200);
    DmaSet3(gUnk_0200F874, 0x06004000, 0x84001800);
}

// Options_GetValue @ 0x080CF680
/* Reads option i (0-6) of the options screen. */
u16 Options_GetValue(u16 i)
{
    switch (i)
    {
    case 0:
        return sub_080C2AFC();
    case 1:
        return Settings_GetBattleMsgSpeed();
    case 2:
        return sub_080C2B6C();
    case 3:
        return sub_080C2BA4();
    case 4:
        return sub_080C2BF0();
    case 5:
        return sub_080C2C30();
    case 6:
        return sub_080C2C70();
    case 7:
        return 0;
    }
}

// Options_SetValue @ 0x080CF708
/* Sets option i; option 6 also reloads the palettes. */
void Options_SetValue(u16 i, u16 v)
{
    switch (i)
    {
    case 0:
        sub_080C2B14(v);
        break;
    case 1:
        sub_080C2B4C(v);
        break;
    case 2:
        sub_080C2B84(v);
        break;
    case 3:
        sub_080C2BCC(v);
        break;
    case 4:
        sub_080C2C0C(v);
        break;
    case 5:
        sub_080C2C4C(v);
        break;
    case 6:
        sub_080C2C9C(v);
        sub_080C1384();
        if (gUnk_0200AB04 & 0x8000)
            BgPicture_LoadPalette();
        else
            sub_080B04BC();
        Palette_CopyWithEffect(3, gPaletteTarget, gUnk_0201B874, 0x400, 0x20);
        Palette_CopyWithEffect(3, gPaletteTarget, gPaletteBuffer, 0x400, 0x20);
        Palette_MarkDirty();
        break;
    }
}
