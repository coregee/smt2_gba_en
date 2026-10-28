/* Battle menu: yes/no results, item/command lists and the tactics (auto) menu. */

#include "global.h"
#include "bmenu.h"

// sub_0812A5B8 @ 0x0812A5B8
void sub_0812A5B8(struct Task *task, u32 value)
{
    gYesNoResult = value;
}

// sub_0812A5C4 @ 0x0812A5C4
void sub_0812A5C4(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct Combatant *m;
    u8 r;
    u8 ok;

    task->pad1E = 0;
    m = Party_GetMember(blk->list[task->data.raw[0]] + 0x8000);
    ok = sub_0815B8F8(m->demonId, 1) != 0;
    if (ok == 0)
    {
        task->pad1E = 0x100;
        r = 2;
    }
    else
    {
        r = 1;
    }
    task->unk06 = r;
}

// sub_0812A61C @ 0x0812A61C
void sub_0812A61C(struct Task *task, u32 arg)
{
    if (arg == 0)
    {
        sub_080C6FF0();
        sub_080C7414();
        sub_080C762C();
    }
    else
    {
        sub_080C700C();
        sub_080C7430();
        sub_080C7648();
    }
}

// sub_0812A640 @ 0x0812A640
struct Task *sub_0812A640(void)
{
    C127_BLOCK->unk118E = 0xFFFF;
    return Task_Create(gUnknown_087787F8, 0xFFFF);
}

/* Builds C127_BLOCK->list from the usable entries of sub_080C9210(kind); returns the count. */
// sub_0812A668 @ 0x0812A668
u16 sub_0812A668(u8 kind)
{
    struct C127Block *blk = C127_BLOCK;
    u16 *list = blk->list;
    u16 n = 0;
    u16 *p = sub_080C9210(kind);
    u16 v;

    while ((v = p[0]) != 0xFFFF)
    {
        if (Flag_Test(0xB6))
        {
            if (p[1] == 0)
            {
                if (sub_080C2554(v))
                    *list = v;
                else
                    *list = v + 0x8000;
                list++;
                n++;
            }
        }
        else if (p[1] == 0 && sub_080C2554(v))
        {
            *list = v;
            list++;
            n++;
        }
        p += 2;
    }
    *list = 0xFFFF;
    return n;
}

// sub_0812A6F0 @ 0x0812A6F0
void sub_0812A6F0(void)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk48 = Task_Create(gUnknown_08778ADC, 0xFFFF);
}

// sub_0812A710 @ 0x0812A710
void sub_0812A710(void)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk48 = Task_Create(gUnknown_08778CB4, 0xFFFF);
}

// sub_0812A730 @ 0x0812A730
u32 sub_0812A730(void)
{
    struct C127Block *blk = C127_BLOCK;
    u32 f;
    s32 msg;

    if ((f = Flag_Test(0xE5)) == 1)
    {
        blk->unk696 = f;
        BattleMenu_Reset();
        msg = sub_080F3190();
        if (msg == 0)
        {
            blk->unk48 = Task_Create(gUnknown_08778ADC, 0xFFFF);
            sub_080C6FF0();
            sub_080C7414();
            sub_080C7218();
            sub_080C7C60();
            return 1;
        }
        blk->unk44 = Task_Create(gUnknown_0877812C, 0xFFFF);
        sub_080EA210();
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(Battle_GetMessage(msg), 0));
        sub_080B1BC4();
        Sound_Play(0x68);
    }
    return 0;
}

// sub_0812A7C4 @ 0x0812A7C4
u32 sub_0812A7C4(void)
{
    if (Flag_Test(0xE5) == 1 && sub_080F3190() == 0)
        return 1;
    return 0;
}

// sub_0812A7E4 @ 0x0812A7E4
void sub_0812A7E4(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;

    task->pad1E = 0;
    if (sub_0812A668(0) == 0)
    {
        sub_080EA210();
        BattleMenu_SetMode(3, Menu_ExpandListTemplate(gUnknown_08124A62, 0));
        Sound_Play(0x68);
        task->pad1E = 1;
    }
    else
    {
        blk->unk4C = TextWindow_Create(9, 1, 0xC, 7, 1);
        Hud_RenderGlyphTiles(gUnk_030000B4, gUnknown_08778A9C);
        VBlankTask_AddCounted(sub_08128F28, 1);
        sub_08126928(2, 1, 1, 4, 4);
    }
}
