/* Battle start and the encounter-introduction state machine. */

#include "global.h"
#include "battledisp.h"

// Battle_Start @ 0x080E47A8
/* Starts a battle. flags: bits 0-3 kind, bit 4 stored at +0x1189. */
void Battle_Start(s16 flags, u16 a1, u16 a2, u16 a3, u16 a4)
{
    struct C15cBattle *b = BB;
    struct C15cBattleArgs *args = &b->args;
    u16 kind = flags & 0xF;
    s16 i;

    b->unk1189 = (s16)(flags & 0x10) >> 4;
    Battle_ClearSpriteTasks();
    gUnk_030063A0.unk14 = 0;
    if (gUnk_030063A0.active == 1)
    {
        gUnk_030063A0.unk06 = 1;
        if (kind == 0)
        {
            args->kind = 1;
            b->unkF6A = 1;
        }
        else
        {
            args->kind = kind;
            b->unkF6A = kind;
        }
        return;
    }
    args->kind = kind;
    b->unkF6A = kind;
    args->a1 = a1;
    args->a2 = a2;
    args->a3 = a3;
    args->a4 = a4;
    b->groups[0] = a1;
    b->groups[1] = a2;
    b->counts[0] = a3;
    b->counts[1] = a4;
    b->unk11A4 = 0;
    b->unk11A6 = 0;
    gUnk_0300003D = 0;
    b->unk118C = 0;
    b->unk11AC = 0xFFFF;
    b->unk11AE = -1;
    b->unk11A8 = 0;
    switch ((s16)kind)
    {
    case 1:
        gUnk_030063A0.unk16 = 0;
        break;
    case 3:
        gUnk_030063A0.unk16 = 0x8000;
        break;
    case 2:
        gUnk_030063A0.unk16 = 0xC000;
        break;
    default:
        gUnk_030063A0.unk16 = 0;
        break;
    }
    b->unk000 = 0;
    b->unk974 = 0;
    b->unk970 = 0;
    b->unkF68 = 0;
    b->state = 0;
    b->substate = 0;
    b->phase = 0;
    b->unk97E = 0;
    b->unkECE = 0;
    BattleState_Init();
    if (a2 != 0xFFFF)
        sub_080ED938(0xFFFF);
    else
        sub_080ED938(0);
    if (b->unkF6A > 0)
    {
        b->unk99C = 1;
        sub_080ED90C(0x100);
    }
    if (b->unk99C == 0)
        b->unk99C = 1;
    b->unk99E = b->unk99C;
    sub_080E74DC();
    for (i = 0; i < 4; i++)
        Combatant_UpdateStats(i);
    gUnk_030063A0.active = 1;
    b->unk1122 = 0;
    gUnk_030063A0.unk0C = 0;
    sub_080C7C60();
    BattleMsg_SetLocked(0);
    b->unk1123 = 0;
    gUnk_030063A0.unk06 = 1;
    gUnk_030063A0.unk0A = 0;
    sub_080E5668(sub_080E5674);
    gUnk_030063A0.task18 = Task_Create(gUnknown_086BEF88, 0xFFFF);
    Font_ResetGlyphSpriteCache(0x180);
    if (gUnk_030031B4 == 9)
        b->unk118A = gUnk_030031EC;
    else
        b->unk118A = gUnk_030031B4;
    sub_080B0888();
    sub_080C7054();
}

// Battle_LoadGroupPalette @ 0x080E4A40
/* Loads the palette of enemy group `group` (unknown demons in the compendium screen use a
   placeholder palette) and fades it in. */
void Battle_LoadGroupPalette(u16 group)
{
    struct C15cBattle *b = BB;
    const void *pal = Demon_GetGfxRecord(b->groups[group])->palette;

    if (gMainCallback == sub_080D977C && sub_080C2644(b->groups[group]) == 0)
        pal = gUnknown_086BE584;
    if (group == 0)
    {
        Palette_CopyWithEffect(3, pal, gUnk_03002D70, 0x20, 0x20);
        PalFade_FadeRangeInFromBlack(0x1E0, 0x10, 2);
    }
    else
    {
        Palette_CopyWithEffect(3, pal, gUnk_03002D90, 0x20, 0x20);
        PalFade_FadeRangeInFromBlack(0x1F0, 0x10, 2);
    }
}

// Battle_IntroTask @ 0x080E4AD0
/* Encounter introduction: picks the enemy groups, creates the units and shows each group. */
void Battle_IntroTask(struct Task *t)
{
    struct C15cBattle *b = BB;
    s16 i;
    u32 r;

    t->result = 0;
    switch (b->state)
    {
    case 0:
        for (i = 0; i < 8; i++)
        {
            struct C15cUnit *u = &b->units[i];

            u->unkE = 0;
            u->unk10 = 0x8000;
            u->unk18 = 0;
        }
        sub_080ED878();
        sub_080ED900(0);
        BattleFlags_Mask(~2);
        BattleFlags_Mask(~4);
        BattleFlags_Mask(~8);
        BattleFlags_Mask(~0x200);
        BattleFlags_Mask(~0x400);
        BattleFlags_Mask(~0x800);
        if (b->unkF6A == 0)
        {
            gUnk_030063A0.unk12 = 999;
            b->unk118C = 0;
            b->unk119E = 0;
            b->unk119C = 0;
            if (b->unk1123 != 1)
            {
                u32 odds = b->unk984 & 0xF0;

                if (odds != 0)
                {
                    b->pick[0] = sub_080ED5B4(b->encounter, 0);
                    b->pick[1] = sub_080ED5B4(b->encounter, 1);
                    if (b->pick[0] != b->pick[1] && odds <= (Random_Byte() & 0xF0))
                        sub_080ED938(0xFFFF);
                }
                if (Battle_IsTwoSided() && b->pick[0] == b->pick[1])
                    sub_080ED938(0);
                if (!Battle_IsTwoSided())
                {
                    b->groups[0] = sub_080ED5B4(b->encounter, 0);
                    b->groups[1] = 0xFFFF;
                    b->state = 1;
                }
                else
                {
                    b->groups[0] = b->pick[0];
                    b->groups[1] = b->pick[1];
                    b->group = 0;
                    b->state = 5;
                    b->unk119C = 1;
                }
                b->counts[0] = sub_080ED610(b->groups[0]);
                b->counts[1] = sub_080ED610(b->groups[1]);
            }
            else
            {
                if (!Battle_IsTwoSided())
                {
                    b->state = 1;
                }
                else
                {
                    b->group = 0;
                    b->state = 5;
                    b->unk119C = 1;
                }
                b->unk1123 = 0;
            }
            sub_0813E908(b->groups[0], b->groups[1]);
        }
        else
        {
            sub_080ED67C(b->groups[0]);
            gUnk_030063A0.unk12 = 0;
            sub_080ED90C(0x100);
            b->state = 4;
        }
        if (!Battle_IsTwoSided())
        {
            for (i = 0; i < b->counts[0]; i++)
                Battle_InitEnemyUnit(i, b->groups[0]);
        }
        else
        {
            for (i = 0; i < b->counts[0]; i++)
                Battle_InitEnemyUnit(i, b->groups[0]);
            for (i = 0; i < b->counts[1]; i++)
                Battle_InitEnemyUnit(i + 4, b->groups[1]);
        }
        sub_080EF8F8(Demon_GetRecord(b->groups[0])[0x21]);
        if (b->unkF6A == 0)
            sub_080E8C58(b->groups[0], b->groups[1], 0);
        break;
    case 1:
        if (!sub_080E8D64())
            break;
        r = sub_080ED67C(b->groups[0]);
        if (r > 1)
        {
            sub_080EC9AC(r, 0, sub_080ED32C(r), 0);
            sub_080ECF70(sub_080ED32C(r));
        }
        b->state = 2;
        break;
    case 2:
        r = sub_080ED67C(b->groups[0]);
        if (b->groups[0] > 0xFF || r == 1)
        {
            b->state = 4;
        }
        else if (r == 0)
        {
            b->step = 0;
            b->state = 3;
            Battle_LoadGroupPalette(0);
        }
        else if (sub_080ECB10())
        {
            b->state = 4;
        }
        break;
    case 3:
        if (b->step > 7)
        {
            b->state = 4;
        }
        else
        {
            sub_080E8DEC();
            sub_080E845C(0, 0, gUnknown_086BE5A4[b->step >> 1][0]);
            b->step++;
        }
        break;
    case 4:
        r = sub_080ED67C(b->groups[0]);
        sub_080E8DEC();
        if (sub_080EDAD0() == 0 || sub_080EDAEC(b->groups[0]) == 1)
        {
            if (r != 0)
                Battle_LoadGroupPalette(0);
            sub_080E760C();
            sub_080E7C98();
            b->tasks[2] = Task_Create(gUnknown_086BE738, 0xFFFF);
        }
        b->state = 0;
        t->result = 1;
        break;
    case 5:
        if (b->group == 0 && !sub_080E8D64())
            break;
        r = sub_080ED67C(b->groups[b->group]);
        if (r > 1)
        {
            sub_080EC9AC(r, 0, sub_080ED32C(r), 0);
            {
                struct C15cPortrait *p = &b->portrait;
                p->x = gUnknown_086BF72C[b->group + 1];
            }
            sub_080ECF70(sub_080ED32C(r));
        }
        b->state = 6;
        break;
    case 6:
        r = sub_080ED67C(b->groups[b->group]);
        if (b->groups[b->group] > 0xFF || r == 1)
        {
            b->state = 8;
        }
        else if (r == 0)
        {
            b->step = 0;
            b->state = 7;
            Battle_LoadGroupPalette(b->group);
        }
        else if (sub_080ECB10())
        {
            b->state = 8;
        }
        break;
    case 7:
        if (b->step > 7)
        {
            b->state = 8;
        }
        else
        {
            sub_080E8DB4(b->group);
            sub_080E845C(b->group, 0, gUnknown_086BE5A4[b->step >> 1][0]);
            b->step++;
        }
        break;
    case 8:
        r = sub_080ED67C(b->groups[b->group]);
        sub_080E8DB4(b->group);
        if (r != 0)
            Battle_LoadGroupPalette(b->group);
        if (b->group == 0)
        {
            if (sub_080EDAD0() == 0 || sub_080EDAEC(b->groups[0]) == 1)
            {
                sub_080E760C();
                sub_080E7C98();
                b->tasks[2] = Task_Create(gUnknown_086BE738, 0xFFFF);
            }
        }
        else
        {
            b->unk119C = 0;
        }
        if (b->group != 0)
        {
            b->state = 0;
            t->result = 1;
        }
        else
        {
            b->state = 9;
            b->timer = 30;
        }
        break;
    case 9:
        if (--b->timer == 0)
        {
            b->state = 5;
            b->group++;
        }
        break;
    }
}

// sub_080E51BC @ 0x080E51BC
void sub_080E51BC(void)
{
    struct C15cBattle *b = BB;

    DmaSet3Wait(b->tiles77A, (void *)0x06000300, 0x84000010);
}

// sub_080E51FC @ 0x080E51FC
void sub_080E51FC(void)
{
    struct C15cBattle *b = BB;

    if (b->tasks[2] != NULL)
    {
        Task_End(b->tasks[2]);
        b->tasks[2] = NULL;
    }
    else
    {
        sub_080E7484();
    }
}

// sub_080E5220 @ 0x080E5220
/* Per-frame battle end handling, driven by gUnk_030063A0.active. */
void sub_080E5220(void)
{
    struct C15cBattle *b = BB;
    u8 i;

    switch (gUnk_030063A0.active)
    {
    case 0:
        break;
    case 1:
        if (b->unk1188 == 1)
        {
            sub_080C8048(sub_080EF90C(), 0x10, 0x30, 0);
            sub_080C8048(sub_080EF954(), 0x10, 0x3C, 0);
        }
        break;
    case 2:
        gUnk_030063A0.active = 0;
        Task_End(gUnk_030063A0.task18);
        sub_080E51FC();
        sub_08126F14();
        for (i = 0; i < 4; i++)
            Combatant_RecalcStats(i);
        if (gUnk_030063A0.unk14 == 1)
        {
            sub_080AF018();
        }
        else if (b->unkF6A == 0)
        {
            if (Flag_Test(0xDF))
                sub_080B9080();
            else
                sub_080AEFFC();
        }
        else
        {
            if (Flag_Test(0xDF))
            {
                b->unkF6A = 0;
                gUnk_0203DB6A = 0;
                Task_ClearAll();
                sub_080B9080();
            }
            else
            {
                sub_080B08AC();
            }
        }
        if (b->unkF6A == 0)
        {
            if (gHudState[0] != 0 && gHudState[0] != 2 && !Flag_Test(0xDF))
                sub_080C700C();
        }
        if (b->unkF6A != 0)
        {
            gUnk_030063A0.active = 6;
            if (Flag_Test(0x14F))
                gUnk_030063A0.active = 8;
        }
        else
        {
            sub_080E9008();
        }
        sub_080C7C94();
        if (b->groups[0] == 0x106 || b->groups[0] == 0x116 || b->groups[0] == 0x113)
            break;
        if (b->groups[0] == 0x109)
        {
            Music_Play(0x14);
        }
        else if (((struct C15cGameState *)gGameState)->unkAC0 == 0)
        {
            if (b->unk118A == (u16)sub_080AD608(gUnk_03004614, gUnk_03004514) || Flag_Test(0xD5))
                Music_Play(b->unk118A);
            else
                Music_FadeOut(4);
        }
        else
        {
            if (b->unk118A == (u16)sub_080AD67C(gWorldMap.map))
                Music_Play(b->unk118A);
        }
        break;
    case 3:
        if (Flag_Test(1))
        {
            gUnk_030063A0.active = 7;
            Flag_Set(0xDF);
        }
        else if (Flag_Test(0xD5))
        {
            gUnk_030063A0.active = 7;
            Flag_Set(0x14F);
        }
        else
        {
            sub_080B9058();
        }
        break;
    case 6:
        if ((u16)PalFade_AllDone() == 1)
        {
            if ((Flag_Test(1) && Flag_Test(0xDF)) || (Flag_Test(0xD5) && Flag_Test(0x14F)))
            {
                gUnk_030063A0.active = 2;
            }
            else
            {
                gUnk_030063A0.unk06 = 4;
                gUnk_030063A0.active = 0;
            }
        }
        break;
    case 8:
        if ((u16)PalFade_AllDone() == 1)
        {
            gUnk_030063A0.unk06 = 4;
            gUnk_030063A0.active = 0;
        }
        break;
    }
}

// sub_080E54D4 @ 0x080E54D4
bool32 sub_080E54D4(void)
{
    if (gUnk_030063A0.active != 0)
        return TRUE;
    return FALSE;
}

// sub_080E54F0 @ 0x080E54F0
#ifdef NONMATCHING
void sub_080E54F0(u16 song)
{
    struct C15cBattle *b = BB;

    b->unk118A = song;
}
#else
NAKED
void sub_080E54F0(u16 song)
{
    asm_unified(
        "    adds r2, r0, #0\n"
        "    ldr r1, .L080E54FC\n"
        "    ldr r3, .L080E5500\n"
        "    adds r1, r1, r3\n"
        "    strh r2, [r1]\n"
        "    bx lr\n"
        ".L080E54FC: .4byte 0x0203C200 @ EWRAM+0x3C200\n"
        ".L080E5500: .4byte 0x0000118A\n"
    );
}
#endif

// sub_080E5504 @ 0x080E5504
void sub_080E5504(void)
{
    DmaCopy32(3, gUnk_030000B4, (void *)0x06016000, 0x1000);
}

// sub_080E5528 @ 0x080E5528
/* VBlank: uploads the demon graphics banks flagged by the two sprite slots. */
void sub_080E5528(void)
{
    struct C15cBattle *b = BB;
    struct C15cDemonSprite *s;

    s = &b->sprites[0];
    if (s->upload == 1)
    {
        DmaSet3Wait(gUnk_02001000 + s->bank * 0x1000, (void *)0x06016000, 0x84000400);
        s->upload = 0;
    }
    s = &b->sprites[1];
    if (s->upload == 1)
    {
        DmaSet3Wait(gUnk_02001000 + (s->bank + 2) * 0x1000, (void *)0x06017000, 0x84000400);
        s->upload = 0;
    }
}

// sub_080E55BC @ 0x080E55BC
void sub_080E55BC(void)
{
    struct C15cBattle *b = BB;
    struct C15cDemonSprite *s = &b->sprites[0];

    if (s->upload == 1)
    {
        DmaSet3Wait(gUnk_02001000 + s->bank * 0x1000, (void *)0x06016000, 0x84000400);
        s->upload = 0;
    }
}

// sub_080E5610 @ 0x080E5610
void sub_080E5610(void)
{
    struct C15cBattle *b = BB;
    struct C15cDemonSprite *s = &b->sprites[1];

    if (s->upload == 1)
    {
        DmaSet3Wait(gUnk_02001000 + (s->bank + 2) * 0x1000, (void *)0x06017000, 0x84000400);
        s->upload = 0;
    }
}

// sub_080E5668 @ 0x080E5668
void sub_080E5668(VoidFunc func)
{
    VBlankTask_AddCounted(func, 1);
}

// sub_080E5674 @ 0x080E5674
void sub_080E5674(void)
{
}

// Demon_LoadGfx @ 0x080E5678
/* Decodes demon `id`'s graphics (half 0/1, step 0 = Huffman stage into gBgPictureBuffer,
   1-2 = LZ77 stage into 0x030000B4 + 0x800 * (step - 1)) and, unless pal is 0xFF, loads its
   palette into OBJ palette `pal` (faded in when the screen is black). Returns 0xFF for ids
   past 0x17B. */
u8 Demon_LoadGfx(u16 id, u8 half, u8 step, u8 pal)
{
    const struct DemonGfxRecord *rec;
    const void *palette;
    const void *src;

    if (id > 0x17B)
        return 0xFF;
    rec = Demon_GetGfxRecord(id);
    palette = rec->palette;
    if (half == 0)
    {
        if (step == 0)
        {
            src = rec->gfx[0][0];
            if (src != NULL)
                HuffUnComp(src, gBgPictureBuffer);
        }
        else
        {
            LZ77UnCompWram(gBgPictureBuffer, gUnk_030000B4 + (step - 1) * 0x800);
        }
    }
    else if (step == 0)
    {
        src = rec->gfx[half][0];
        if (src != NULL)
            HuffUnComp(src, gBgPictureBuffer);
    }
    else if ((src = rec->gfx[half][step - 1]) != NULL)
    {
        LZ77UnCompWram(gBgPictureBuffer, gUnk_030000B4 + (step - 1) * 0x800);
    }
    if (pal != 0xFF)
    {
        u16 *dst = &gPaletteBuffer[0x100 + pal * 16];

        if (gMainCallback == sub_080D977C && sub_080C2644(id) == 0)
        {
            palette = gUnknown_086BE584;
            Palette_CopyWithEffect(3, palette, dst, 0x20, 0x20);
            Palette_MarkDirty();
        }
        else if (!Palette_IsBg13Black())
        {
            Palette_CopyWithEffect(3, palette, dst, 0x20, 0x20);
            Palette_MarkDirty();
        }
        else
        {
            Palette_CopyWithEffect(3, palette, &gPaletteTarget[0x100 + pal * 16], 0x20, 0x20);
            PalFade_FadeRangeInFromBlackTagged(0x100 + pal * 16, 0x10, 1, 1);
        }
    }
    BB->unk11A4 = 0;
    return 0;
}

// sub_080E57CC @ 0x080E57CC
void sub_080E57CC(u8 slot)
{
    struct C15cBattle *b = BB;
    struct C15cDemonSprite *s = &b->sprites[slot];

    if (s->unk1 != 0)
        s->unk1--;
}

// sub_080E57F0 @ 0x080E57F0
void sub_080E57F0(void)
{
    struct C15cBattle *b = BB;
    u32 id = b->groups[0];
    struct C15cDemonSprite *s = &b->sprites[0];

    s->bank = 0;
    s->unk1 = 0;
    s->unk5 = 0;
    if (s->unk4 != 2)
    {
        s->unk7 = 0;
        s->unk6 = 0;
    }
    s->unk4 = 0;
    Demon_LoadGfx(id, 0, 0, 0xE);
    Demon_GetGfxRecord(id);
    sub_080E86B4(&gPaletteBuffer[0x1E0], &b->sprites[0].pulse, id);
}

// sub_080E584C @ 0x080E584C
void sub_080E584C(void)
{
    struct C15cBattle *b = BB;

    Demon_LoadGfx(b->groups[0], 0, 1, 0xFF);
}

// sub_080E586C @ 0x080E586C
void sub_080E586C(void)
{
    struct C15cBattle *b = BB;
    u32 id = b->groups[1];

    if (id != 0xFF)
    {
        struct C15cDemonSprite *s = &b->sprites[1];

        s->bank = 0;
        s->unk1 = 0;
        s->unk4 = 0;
        s->unk7 = 0;
        s->unk6 = 0;
        s->unk5 = 0;
        Demon_LoadGfx(id, 0, 0, 0xF);
        Demon_GetGfxRecord(id);
        sub_080E86B4(&gPaletteBuffer[0x1F0], &b->sprites[1].pulse, id);
    }
}

// sub_080E58C8 @ 0x080E58C8
void sub_080E58C8(void)
{
    struct C15cBattle *b = BB;

    if (b->groups[1] != 0xFF)
        Demon_LoadGfx(b->groups[1], 0, 1, 0xFF);
}

// sub_080E58F0 @ 0x080E58F0
void sub_080E58F0(u32 unused, u8 bank)
{
    CpuFastSet(gUnk_030000B4, gUnk_02001000 + bank * 0x1000, 0x400);
}

// sub_080E5910 @ 0x080E5910
void sub_080E5910(u32 unused, u8 group, u8 half, u8 step)
{
    struct C15cBattle *b = BB;

    Demon_LoadGfx(b->groups[group], half, step, 0xFF);
}
