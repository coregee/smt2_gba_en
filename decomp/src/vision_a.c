#include "global.h"
#include "extras.h"

// sub_080DAAA8 @ 0x080DAAA8
void sub_080DAAA8(void)
{
    struct C0d9MenuState *ms = &gMenuState;
    u32 zero;

    ms->magic00 = 0x13240800;
    CpuSet(gUnk_03006090, ms->unk04, 0x04000002);
    ms->magic = 0;
    zero = 0;
    CpuSet(&zero, ms->flags, 0x05000002);
}

// sub_080DAAEC @ 0x080DAAEC
void sub_080DAAEC(void)
{
    Link_Exchange(12, &gMenuState, &gMenuState.magic);
}

// sub_080DAB04 @ 0x080DAB04
void sub_080DAB04(struct Task *task)
{
    if (gMenuState.magic == 0x13240800)
        task->result = 1;
    else
        task->result = 0;
}

/* Sets the vision flags (300 + i) received in gMenuState.flags and saves. */
// Vision_ApplyReceivedFlags @ 0x080DAB28
void Vision_ApplyReceivedFlags(void)
{
    struct C0d9MenuState *ms = &gMenuState;
    u8 *flags = ms->flags;
    u32 i;

    for (i = 0; i < 64; i++)
    {
        if ((flags[i >> 3] >> (i & 7)) & 1)
        {
            u16 id = i + 300;

            if (!Inventory_GetCount(id))
                Inventory_AddItem(id);
        }
    }
    SaveSlot_Write(gGameState.saveSlot, &gGameState);
}

// sub_080DAB88 @ 0x080DAB88
void sub_080DAB88(void)
{
    union C0d9Code *code = (union C0d9Code *)gUnk_03004740;

    Vision_BuildList(1);
    sub_080AE2D0();
    if (code->w[0] == 0 && code->w[1] == 0)
    {
        code->b[0] = 0x62;
        code->b[1] = 0x7D;
        code->b[2] = 0x33;
        code->b[3] = 0x80;
        code->b[4] = 0xFF;
        code->s[5] = -1;
        code->s[6] = -1;
        code->s[7] = -1;
    }
}

/* Fills gUnk_0203B454 with vision ids (300..): mode 0 the ones seen, otherwise all except
   310, 338 and 342. Returns the count. */
// Vision_BuildList @ 0x080DABCC
u16 Vision_BuildList(u32 all)
{
    u16 *list = gUnk_0203B454;
    u32 n = 0;
    u32 zero = 0;
    u32 i;

    CpuSet(&zero, list, 0x05000040);
    if (all == 0)
    {
        for (i = 0; i < 64; i++)
        {
            u32 id = i + 300;

            if (sub_080C2734(id))
            {
                *list++ = id;
                n++;
            }
        }
    }
    else
    {
        u32 lim = 46;
        for (i = 0; i < lim; i++)
        {
            u32 id = i + 300;

            if (id != 310 && id != 338 && id != 342)
            {
                *list++ = id;
                n++;
            }
        }
    }
    return n;
}

// Vision_CountListed @ 0x080DAC4C
u32 Vision_CountListed(void)
{
    u32 n = 0;
    u32 i;

    for (i = 0; i < 64; i++)
    {
        if (gUnk_0203B454[i] != 0)
            n++;
    }
    return n;
}

/* Vision list input: 6 visible rows, d->unk02 is the first row shown; L/R page. */
// sub_080DAC70 @ 0x080DAC70
void sub_080DAC70(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    struct C0d9MenuState *ms = &gMenuState;
    u16 *list = gUnk_0203B454;
    u16 count = Vision_CountListed();
    u16 rows;
    u32 zero = 0;

    ms->listTask = task;
    ms->listOnFrame = task->onFrame;
    task->result = zero;
    task->unk1E = zero;
    rows = count;
    if (count > 5)
        rows = 6;
    if (gKeysNew & 1)
    {
        if (sub_080C2734(list[task->data.h[0] + d->unk02]))
        {
            Font_ResetGlyphSpriteCache(0x180);
            task->unk1E = task->data.h[0] + d->unk02 + 1;
            Sound_Play(0x65);
            task->result = 1;
        }
        else
        {
            Sound_Play(0x66);
        }
    }
    else if (gKeysNew & 2)
    {
        Sound_Play(0x66);
        task->result = 1;
    }
    else if (gRepeatedKeys & 0x40)
    {
        if (task->data.h[0] != 0)
        {
            task->data.h[0]--;
            Sound_Play(0x64);
        }
        else if (d->unk02 != 0)
        {
            d->unk02--;
            Sound_Play(0x64);
        }
        Font_ResetGlyphSpriteCache(0x180);
    }
    else
    {
        u16 down = gRepeatedKeys & 0x80;

        if (down)
        {
            if (task->data.h[0] != rows - 1)
            {
                task->data.h[0]++;
                Sound_Play(0x64);
            }
            else if (task->data.h[0] == 5 && task->data.h[0] + d->unk02 + 1 <= count - 1)
            {
                d->unk02++;
                Sound_Play(0x64);
            }
            Font_ResetGlyphSpriteCache(0x180);
        }
        else if ((gRepeatedKeys & 0x200) && count > 6)
        {
            u32 cursor = task->data.h[0];
            u16 top = d->unk02;
            u16 t = cursor;

            if (t != 0)
            {
                task->data.h[0] = down;
            }
            else
            {
                if (top > 4)
                    d->unk02 = top - 5;
                else
                    d->unk02 = t;
            }
            if (cursor != d->cursor || top != d->unk02)
                Sound_Play(0x64);
            Font_ResetGlyphSpriteCache(0x180);
        }
        else if ((gRepeatedKeys & 0x100) && count > 6)
        {
            u16 cursor = d->cursor;
            u16 top = d->unk02;

            if (d->cursor != 5)
                d->cursor = 5;
            else if (cursor + top + 6 < count - 1)
                d->unk02 = top + 6;
            else
                d->unk02 = count - 6;
            if (cursor != d->cursor || top != d->unk02)
                Sound_Play(0x64);
            Font_ResetGlyphSpriteCache(0x180);
        }
    }
}

/* Draws the six visible rows of vision names (8 glyphs each), the count seen and the
   scroll arrows. */
// Vision_DrawItemList @ 0x080DADF8
void Vision_DrawItemList(struct Task *task)
{
    struct C0d9Menu *d = (struct C0d9Menu *)&task->data;
    u16 count = Vision_CountListed();
    u16 x = 0x6C;
    u16 y = 0x10;
    u32 i, j, n;

    Sprite_Draw(gUnknown_0800853C, 0, 7, 0, 0x100, 0x6A, task->data.h[0] * 12 + 17);
    for (i = 0; i < 6; i++)
    {
        u16 id = ((u16 *)0x0203B454)[d->unk02 + i];

        if (id != 0)
        {
            const u16 *name;

            if (sub_080C2734(id))
                name = (const u16 *)(Action_GetRecord(id) + 0xC);
            else
                name = gUnknown_085829BC;
            for (j = 0; j < 8; j++)
                FontSprite_DrawGlyph(name[j], 0, 0, x + j * 12, y + i * 12);
        }
    }
    for (n = 0, i = 0; i < 46; i++)
    {
        if (sub_080C2734(i + 300))
            n++;
    }
    Sprite_DrawFraction(n, 43, x + 0x25, y + 0x5A);
    if (d->unk02 != 0)
        sub_080C4A4C(6, 1, x + 0x60, y - 4);
    if (d->unk02 + 6 <= count - 1)
        sub_080C4AB0(6, 1, x + 0x60, y + 0x4C);
}

/* "<name>" + gUnknown_08009534 on one line, gUnknown_08009540 below (vision names stop at
   8 glyphs or a 0). */
// Vision_ComposePrompt @ 0x080DAF50
void Vision_ComposePrompt(struct Task *task)
{
    struct Task *parent = Task_GetParent(task);
    u16 x = 0x14;
    u16 y = 0x64;
    const u16 *str = (const u16 *)(Action_GetRecord(gUnk_0203B454[parent->data.h[0] + parent->data.h[1]]) + 0xC);
    u16 i;

    for (i = 0; str[i] != 0; )
    {
        FontSprite_DrawGlyphTinted(str[i], 0, 0, x, y, 2);
        x += 12;
        i++;
        if (i > 7)
            break;
    }
    str = gUnknown_08009534;
    Text_DrawSpriteString(str, 0, 0, x, y, 12);
    str = gUnknown_08009540;
    Text_DrawSpriteString(str, 0, 0, 0x14, y + 12, 12);
}

// sub_080DAFEC @ 0x080DAFEC
void sub_080DAFEC(void)
{
    gMenuState.task->onFrame = NULL;
    gMenuState.listTask->onFrame = NULL;
}

/* Starts the selected vision: clears the field state, sets the windows and loads the
   vision's script. */
// sub_080DB000 @ 0x080DB000
void sub_080DB000(struct Task *task)
{
    u8 *p;

    DmaFill32_3(0, &gFieldState, 0x85000029);
    p = &gUnk_03000038;
    {
        u8 v = 0x3F;
        gUnk_03000039 = v;
    }
    gUnk_03000030 = 0xE8;
    gUnk_03000031 = 8;
    gUnk_03000034 = 0x98;
    gUnk_03000035 = 0x60;
    *p = 0x37;
    {
        u16 *t = gUnk_0203B454;
        sub_080AF218(0x24, gUnknown_085829CC[t[task->data.h[0] + task->data.h[1]] - 300]);
    }
}

// sub_080DB094 @ 0x080DB094
void sub_080DB094(struct Task *task)
{
    if (gFieldState.state == 0x24)
    {
        task->result = 1;
        sub_080C3818(1);
        sub_080AE2D0();
    }
    else
    {
        task->result = 0;
    }
}

// sub_080DB0BC @ 0x080DB0BC
void sub_080DB0BC(void)
{
    DmaFill32_3(0, 0x06001000, 0x85000400);
    DmaFill32_3(0, 0x06003000, 0x85000400);
}

// sub_080DB0F4 @ 0x080DB0F4
void sub_080DB0F4(void)
{
    DmaFill32_3(0, gUnk_02000000, 0x85000400);
    DmaFill32_3(0, gUnk_03002EB0, 0x85000040);
    DmaFill16_3(0, gWindowTilemapBuffer, 0x81000400);
    DmaFill32_3(0, gUnk_0201D874, 0x85001A00);
    Palette_MarkDirty();
    gUnk_0300000E = 0;
    gUnk_03000006 = 0;
    VBlankTask_AddCounted(sub_080DB0BC, 1);
}

// sub_080DB188 @ 0x080DB188
void sub_080DB188(void)
{
    struct C0d9MenuState *ms = &gMenuState;

    ms->task->onFrame = ms->onFrame;
    ms->listTask->onFrame = ms->listOnFrame;
    Tilemap_CopyRectSkipZero(gUnknown_0857F500, gUnk_02024074, 0, 0, 1, 1, 11, 5);
    VBlankTask_AddCounted(sub_080D9BAC, 1);
}
