#include "global.h"
#include "menu2.h"

/* VBlank upload for the scene selected by gMenuState.mode (0..3, 100..129). */
// sub_080D5C20 @ 0x080D5C20
void sub_080D5C20(void)
{
    switch (*(u16 *)&gMenuState)
    {
    case 100:
        DmaSet3(gUnk_0200F874, (void *)0x06004000, 0x84002000);
        break;
    case 101:
        DmaSet3(gUnk_0200F874, (void *)0x06010000, 0x84002000);
        sub_080D59E8();
        REG_BG1CNT = 0x820D;
        REG_BG2CNT = 0x840E;
        sub_080C1440();
        break;
    case 102:
        DmaSet3(gUnknown_084F9FE0, (void *)0x06000000, 0x84000140);
        break;
    case 104:
        DMA3_FILL32(0, (void *)0x06000000, 0x85000140);
        break;
    case 105:
        DmaSet3(gUnk_0200F874, (void *)0x06004000, 0x84002000);
        break;
    case 106:
        DmaSet3(gUnknown_084FA860, (void *)0x06003000, 0x84000140);
        break;
    case 113:
        DmaSet3(gUnknown_084FB760, (void *)0x06001000, 0x84000140);
        break;
    case 108:
        DmaSet3(gUnk_0200F874, (void *)0x0600C000, 0x84001000);
        break;
    case 109:
        DmaSet3(gUnknown_084FB260, (void *)0x06001000, 0x84000140);
        break;
    case 110:
        DmaSet3(gUnk_0200F874, (void *)0x06010000, 0x84002000);
        break;
    case 111:
        DmaSet3(gUnknown_084FCB60, (void *)0x06000000, 0x84000140);
        break;
    case 115:
        DmaSet3(gUnknown_084FB760, (void *)0x06002000, 0x84000140);
        break;
    case 116:
        DmaSet3(gUnknown_084FBC60, (void *)0x06001000, 0x84000140);
        break;
    case 117:
        DmaSet3(gUnknown_084FB260, (void *)0x06002000, 0x84000140);
        break;
    case 118:
        DmaSet3(gUnknown_084FBC60, (void *)0x06002000, 0x84000140);
        break;
    case 119:
        DmaSet3(gUnknown_084FC160, (void *)0x06001000, 0x84000140);
        break;
    case 120:
        Font_ResetGlyphSpriteCache(0x180);
        break;
    case 121:
        DmaSet3(gUnknown_084FC160, (void *)0x06002000, 0x84000140);
        break;
    case 122:
        REG_BG1CNT = 0x8205;
        gUnk_03000006 = 0;
        gUnk_03000004 = 0;
        DmaSet3(gUnknown_084FC660, (void *)0x06001000, 0x84000140);
        break;
    case 123:
        REG_BG2CNT = 0x8406;
        gUnk_0300000A = 0;
        gUnk_03000008 = 0;
        DmaSet3(gUnknown_084FC660, (void *)0x06002000, 0x84000140);
        break;
    case 124:
        DmaSet3(gUnknown_084FCB60, (void *)0x06001000, 0x84000140);
        break;
    case 125:
        DMA3_FILL32(0, (void *)0x06003000, 0x85000140);
        break;
    case 126:
        DMA3_FILL32(0, (void *)0x06002000, 0x85000140);
        break;
    case 128:
        DMA3_FILL32(0, (void *)0x06000000, 0x85001000);
        break;
    case 129:
        DmaSet3(gUnknown_084FAD60, (void *)0x06003800, 0x84000140);
        gUnk_0300000C = 0x18;
        gUnk_03000008 = 0xFFF8;
        gUnk_03000004 = 0xFFF8;
        break;
    case 0:
        DmaSet3(gUnk_0200F874, (void *)0x06008000, 0x84002000);
        break;
    case 1:
        DmaSet3(gUnk_0200F874, (void *)0x06010000, 0x84002000);
        break;
    case 2:
        DmaSet3(gUnknown_081B9BB0, (void *)0x06001000, 0x84000200);
        break;
    case 3:
        DmaSet3(gUnknown_081BA3B0, (void *)0x06002000, 0x84000200);
        break;
    }
}

// Task_SetDataByte @ 0x080D624C
void Task_SetDataByte(struct Task *task, u32 i, u8 value)
{
    task->data.raw[i] = value;
}

// sub_080D6254 @ 0x080D6254
void sub_080D6254(struct Task *task, u32 i, u16 value)
{
    SCENE_MENU->vars[i] = value;
}
