/* Battle menu: confirm prompts for member actions (yes/no), demon name display. */

#include "global.h"
#include "bmenu.h"

// sub_0812A288 @ 0x0812A288
void sub_0812A288(void)
{
    BattleMenu_Reset();
    sub_081269B0(2);
}

// sub_0812A298 @ 0x0812A298
void sub_0812A298(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct C127Sub110C *s = &blk->unk110C;

    s->yesno = YesNo_Create(0);
    BattleMenu_SetMode(3, Battle_BuildNamePrependText(blk->list[task->data.raw[0]] + 0x8000, gUnknown_0812437C));
    BattleMsg_SetDone(1);
}

// sub_0812A2EC @ 0x0812A2EC
void sub_0812A2EC(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct C127Sub110C *s = &blk->unk110C;
    u16 zero = 0;
    bool32 r;

    task->result = zero;
    if ((r = Task_IsFree(s->yesno)) == 1)
    {
        if (gYesNoResult == 1)
            task->pad1E = zero;
        else if (gYesNoResult == 0)
            task->pad1E = r;
        else
            task->pad1E = zero;
        Window_Close((void *)s->yesno, 0);
        task->result = 1;
    }
}

// sub_0812A338 @ 0x0812A338
void sub_0812A338(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    u16 v = blk->list[task->data.raw[0]];
    u16 id = v + 0x8000;

    Party_GetMember(id);
    if (Combatant_IsAlive(v))
        BattleMenu_SetMode(3, Battle_BuildNamePrependText(id, gUnknown_081243C6));
    else
        BattleMenu_SetMode(3, Battle_BuildNamePrependText(id, gUnknown_081243B0));
}

// sub_0812A39C @ 0x0812A39C
void sub_0812A39C(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;
    struct MenuCursor *c = sub_08126D1C(2);
    u8 old = c->index;
    u16 x;
    u16 y;
    u16 i;
    struct C127DemonRecord *rec;

    Sprite_Draw(gUnknown_08000EA4, 0, 0, 1, 0, 0xC, c->onScreen * 13 + 6);
    if (c->count > 5)
    {
        if (c->top != 0)
            Sprite_Draw(gUnknown_08000FF0, 0, 0, 1, 0, 0x74, 4);
        if (c->top + 5 != c->count)
            Sprite_Draw(gUnknown_08001000, 0, 0, 1, 0, 0x74, 0x43);
    }
    if (old != c->index)
    {
        BattleMenu_DrawListPage(0, c->top);
        sub_081283C4(0, c->index);
    }
    if (task->unk06 == 1)
    {
        x = 0x12;
        y = 0x59;
        rec = (struct C127DemonRecord *)Demon_GetRecord(Battle_GetCombatant(blk->list[task->data.raw[0]] + 0x8000)->demonId);
        for (i = 0; i < 8 && rec->name[i] != 0; i++)
        {
            FontSprite_DrawGlyph(rec->name[i], 0, 0, x, y);
            x += 12;
        }
        Text_DrawSpriteString(gUnknown_0800354A, 0, 0, x, y, 0xC);
        Text_DrawSpriteString(gUnknown_08003556, 0, 0, 0x12, y + 0xC, 0xC);
    }
    else if (task->unk06 == 2)
    {
        Text_DrawSpriteString(gUnknown_08003568, 0, 0, 0x12, 0x59, 0xC);
    }
}

// sub_0812A50C @ 0x0812A50C
void sub_0812A50C(struct Task *task)
{
    task->result = 0;
    if ((gKeysNew & 1) || (gKeysNew & 2))
    {
        task->result = 1;
        task->unk06 = 0;
    }
}

// sub_0812A53C @ 0x0812A53C
void sub_0812A53C(void)
{
    struct C127Block *blk = C127_BLOCK;
    struct C127Sub110C *s = &blk->unk110C;

    s->yesno = YesNo_Create(0);
}

// sub_0812A55C @ 0x0812A55C
void sub_0812A55C(struct Task *task)
{
    struct C127Block *blk = C127_BLOCK;

    blk->unk118E = blk->list[task->data.raw[0]];
    sub_081269B0(2);
}

// sub_0812A588 @ 0x0812A588
void sub_0812A588(void)
{
    sub_081269B0(2);
}

// sub_0812A594 @ 0x0812A594
void sub_0812A594(void)
{
    sub_081269B0(2);
}

// sub_0812A5A0 @ 0x0812A5A0
void sub_0812A5A0(void)
{
    C127_BLOCK->unk118E = 0xFFFF;
}
