#include "global.h"
#include "title.h"

// sub_080D946C @ 0x080D946C
void sub_080D946C(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;

    LZ77UnCompWram(gUnknown_0853131C, gUnk_02001000);
    LZ77UnCompWram(gUnknown_08531914, gUnk_02001000 + 0x1000);
    LZ77UnCompWram(gUnknown_08532034, gUnk_02001000 + 0x2000);
    LZ77UnCompWram(gUnknown_08532744, gUnk_02001000 + 0x3000);
    Palette_CopyWithEffect(3, gUnknown_08532A9C, gUnk_03003150, 0x20, 0x20);
    Palette_MarkDirty();
    VBlankTask_AddCounted(sub_080D9448, 1);
    obj->unk24 = 0;
    obj->shown = 1;
}

// sub_080D94F0 @ 0x080D94F0
void sub_080D94F0(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    u16 layer = sub_080C4388(obj);

    Sprite_DrawBlended(gUnknown_08568C14[obj->unk24], layer, 0xD, 3, 0x180, obj->unk08 + 0x28, obj->unk0A + 0x58);
}

// sub_080D953C @ 0x080D953C
void sub_080D953C(void)
{
    DmaSet3(0x02001000, 0x06016800, 0x84000400);
}

// sub_080D9560 @ 0x080D9560
void sub_080D9560(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;

    LZ77UnCompWram(gUnknown_08550398, (void *)0x02001000);
    Palette_CopyWithEffect(3, gUnknown_08550EBC, gUnk_03003170, 0x20, 0x20);
    Palette_MarkDirty();
    VBlankTask_AddCounted(sub_080D953C, 1);
    obj->unk24 = 0;
    obj->shown = 1;
}

// sub_080D95B0 @ 0x080D95B0
void sub_080D95B0(struct Task *task)
{
    struct CharObj *obj = (struct CharObj *)&task->data;
    u16 layer = sub_080C4388(obj);

    Sprite_Draw(gUnknown_080061A0, layer, 0xE, 3, 0x340, obj->unk08 + 0x28, obj->unk0A + 0x58);
}

/* gCharGfxRecords + id * 0x2C. */
// Char_GetRecord @ 0x080D95F4
struct CharGfxRecord *Char_GetRecord(u16 id)
{
    return &gCharGfxRecords[id];
}

/* Main-callback setup that clears VRAM and the map buffers and opens the save screen in mode 4. */
// sub_080D9608 @ 0x080D9608
void sub_080D9608(void)
{
    vu16 fill;
    u32 zero;
    u32 zero2;

    sub_080C1450();
    fill = 0;
    DmaSet3(&fill, (void *)0x06000000, 0x81002000);
    Font_ResetGlyphSpriteCache(0x180);
    Windows_Init();
    sub_080C1328();
    sub_080C1384();
    zero = 0;
    CpuSet(&zero, gUnk_0201D874, 0x05001A00);
    zero2 = 0;
    CpuSet(&zero2, gUnk_02024074, 0x05001000);
    REG_IE = 0x2003;
    REG_DISPSTAT = 0x18;
    REG_IME = 1;
    Task_ClearAll();
    sub_080AE2D0();
    SaveScreen_Open(4, 3);
    sub_080C5170(0xD);
    SetMainCallback(sub_080D977C);
}

// sub_080D96BC @ 0x080D96BC
void sub_080D96BC(void)
{
    vu16 fill;
    u32 zero;
    u32 zero2;

    sub_080C1450();
    fill = 0;
    DmaSet3(&fill, (void *)0x06000000, 0x81002000);
    Font_ResetGlyphSpriteCache(0x180);
    zero = 0;
    CpuSet(&zero, gUnk_0201D874, 0x05001A00);
    zero2 = 0;
    CpuSet(&zero2, gUnk_02024074, 0x05001000);
    REG_IE = 0x2003;
    REG_DISPSTAT = 0x18;
    REG_IME = 1;
    Task_ClearAll();
    sub_080AE2D0();
    gUnk_03006098 = 0;
    Task_Create(gUnknown_085816B8, 0xFFFF);
    sub_080C5170(0xD);
    gUnk_0300609C = 0;
    SetMainCallback(sub_080D977C);
}
