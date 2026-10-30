#include "global.h"
#include "extras.h"

/* Deals the 27 cards (1..27) into task data +0x15, shuffled when g[4] == 1, and records in
   g[0x14] where card g[2] ended up. */
// Cards_Deal @ 0x080DDE2C
void Cards_Deal(struct Task *task)
{
    struct C0d9Cards *g = (struct C0d9Cards *)&task->data;
    u8 i;

    if (g->b[4] == 1)
    {
        for (i = 0; i <= 26; i++)
            g->cards[i] = i + 1;
        for (i = 0; i <= 26; i++)
        {
            /* Random_Byte is called as returning u32 here (extras.h says u16) */
            u8 bit = ((u32 (*)(void))Random_Byte)() & 1;

            if (!bit)
            {
                u8 j = (((u32 (*)(void))Random_Byte)() & 0x1F) + 1;

                if (j <= 26)
                {
                    u8 t = g->cards[i];

                    g->cards[i] = g->cards[j];
                    g->cards[j] = t;
                }
            }
        }
        for (i = 0; i <= 26; i++)
        {
            if ((s8)g->b[2] == g->cards[i])
                g->b[0x14] = i;
        }
    }
    else
    {
        for (i = 0; i <= 26; i++)
        {
            g->cards[i] = i + 1;
            if ((s8)g->b[2] == i + 1)
                g->b[0x14] = i;
        }
    }
}

// sub_080DDEC8 @ 0x080DDEC8
void sub_080DDEC8(struct Task *task)
{
    struct C0d9Cards *g = (struct C0d9Cards *)&task->data;

    g->b[6] = 15;
}

// sub_080DDED0 @ 0x080DDED0
void sub_080DDED0(void)
{
    Music_Play(13);
}

/* Switches to a separate main loop (sub_080DE0DC): display, window and interrupt setup. */
// sub_080DDEDC @ 0x080DDEDC
void sub_080DDEDC(void)
{
    gUnk_0200AB04 = 1;
    REG_DISPCNT = 0x6301;
    REG_BG0CNT = 4;
    REG_BG1CNT = 0x8205;
    REG_BG2CNT = 0x048A;
    *(u16 *)&gUnk_03000030 = 0xF0;
    *(u16 *)&gUnk_03000032 = 0xF0;
    *(u16 *)&gUnk_03000034 = 0xA0;
    *(u16 *)&gUnk_03000036 = 0xA0;
    *(u16 *)&gUnk_03000038 = 0x404;
    *(u16 *)&gUnk_0300003A = 0x1F1F;
    DmaFill16_3(0, VRAM, 0x81002000);
    REG_IE = 0x2003;
    REG_DISPSTAT = 0x18;
    REG_IME = 1;
    Task_ClearAll();
    sub_080DDFAC();
    SetMainCallback(sub_080DE0DC);
}

// sub_080DDFAC @ 0x080DDFAC
void sub_080DDFAC(void)
{
    struct C0d9Bg *bg;
    u8 *buf;

    gDispRegs = 0;
    gUnk_03000004 = 0;
    gUnk_03000008 = 0;
    gUnk_0300000C = 0;
    gUnk_03000002 = 0;
    gUnk_03000006 = 0;
    gUnk_0300000A = 0;
    gUnk_0300000E = 0;
    memset(gPaletteTarget, 0, 0x400);
    sub_08153378(gUnknown_08589C3C, 0, 0x40);
    buf = gUnk_02030C74;
    memset(buf, 0, 0x5400);
    memcpy(buf, gUnknown_08589C7C, 4);
    DmaSet3(buf, VRAM, 0x84000400);
    memcpy(buf, gUnknown_08587830, 0x820);
    DmaSet3(buf, VRAM + 0x1000, 0x84000400);
    memcpy(buf, gUnknown_08589B3C, 0x100);
    DmaSet3(buf, VRAM + 0x2000, 0x84000400);
    bg = &gC0d9Bg;
    bg->unk06 = 4;
    bg->unk34 = 0;
    bg->unk22 = 0;
    bg->unk10 = 0;
    bg->unk14 = 0;
    bg->unk08 = 0x100;
    bg->unk0A = 0;
    bg->unk0C = 0;
    bg->unk0E = 0x100;
    bg->unk18 = 0x38;
    bg->unk1A = 8;
    bg->unk1E = 8;
    bg->unk20 = 8;
    bg->unk1C = 0;
    bg->unk24 = 0x78;
    bg->unk26 = 0x48;
    bg->unk28 = 0;
    bg->unk2A = 0x80;
    bg->unk2C = 0x200;
    bg->unk30 = 0x200;
    bg->unk36 = 0;
}
