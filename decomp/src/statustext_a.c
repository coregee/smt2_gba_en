#include "global.h"
#include "status.h"

void sub_080CD044(u16 id, u16 x, u16 y);
void sub_080CD0E4(u16 id);

struct Task *DemonObj_Create(u16 a, u16 id, u16 x, u16 y, u16 e, u16 f);
void sub_080C3E40(struct Task *t, u16 v);
u32 Exp_GetForLevel(s32 level);
u32 sub_08157C2C(void);
extern const u8 gUnknown_084F00D8[], gUnknown_084F00DC[], gUnknown_084F00E0[], gUnknown_084F00E4[];
extern const u8 gUnknown_084F00E8[], gUnknown_084F00F0[], gUnknown_084F00F8[], gUnknown_084F0100[];
extern const u8 gUnknown_084F0108[], gUnknown_084F010C[], gUnknown_084F0114[], gUnknown_084F011C[];
extern const u8 gUnknown_084F0124[], gUnknown_084F012C[], gUnknown_084F0134[], gUnknown_084F013C[];
extern const u8 gUnknown_084F0144[], gUnknown_084F014C[], gUnknown_084F0154[], gUnknown_084F015C[];
extern const u8 gUnknown_084F0164[], gUnknown_084F0168[], gUnknown_084F0170[], gUnknown_084F0178[];
extern const u8 gUnknown_084F017C[], gUnknown_084F0184[], gUnknown_084F0188[], gUnknown_084F0190[];
extern const u8 gUnknown_084F0194[];

/* Text of the status screen's first page in the small ASCII font. Humans: HP and MP
   (current/max), ST (the worst ailment of Combatant_GetStatus, right-aligned by hand: each
   name has its own x for its length, 8 pixels per letter), EXP and NEXT, and for the hero
   (sub_080C93B4) MEMORY: demons in stock / stock size. Demons: ALI (sub_080CD044), HP, MP
   (with the bonus of sub_08157C2C in mode 6), ST and CP (sub_080CD0E4), or dashes when
   sub_080C99B8 says the entry is unknown; then the demon's picture (DemonObj_Create). */
// Status_DrawVitals @ 0x080CB0B8
void Status_DrawVitals(u32 a, struct Task *t)
{
    struct C0c6Status *st = &gMenuState;
    struct Combatant *c = Status_GetCombatant(st->sel);
    u16 status;
    u16 hp, mp;
    u16 bonus;
    s32 i, n;
    struct Combatant *stock;

    if (st->sprite != NULL)
    {
        DemonObj_End(st->sprite, 0);
        st->sprite = NULL;
    }
    if (sub_080C9388(st->sel) == 1)
    {
        u16 hstatus = Combatant_GetStatus(c->id);

        SmallFont_DrawAscii(gUnknown_084F00D8, 0xA, 0x20, 0);
        SmallFont_DrawNumber(c->hp, 0x60, 0x20, 4);
        SmallFont_DrawAscii(gUnknown_084F00DC, 0x68, 0x20, 4);
        SmallFont_DrawNumber(c->maxHp, 0x80, 0x20, 4);
        SmallFont_DrawAscii(gUnknown_084F00E0, 0xA, 0x2C, 0);
        SmallFont_DrawNumber(c->mp, 0x60, 0x2C, 4);
        SmallFont_DrawAscii(gUnknown_084F00DC, 0x68, 0x2C, 4);
        SmallFont_DrawNumber(c->maxMp, 0x80, 0x2C, 4);
        SmallFont_DrawAscii(gUnknown_084F00E4, 0xA, 0x38, 0);
        if (hstatus & 0x8000)
            SmallFont_DrawAscii(gUnknown_084F00E8, 0x60, 0x38, 4);
        else if (hstatus & 0x2000)
            SmallFont_DrawAscii(gUnknown_084F00F0, 0x60, 0x38, 4);
        else if (hstatus & 0x1000)
            SmallFont_DrawAscii(gUnknown_084F00F8, 0x58, 0x38, 4);
        else if (hstatus & 4)
            SmallFont_DrawAscii(gUnknown_084F0100, 0x58, 0x38, 4);
        else if (hstatus & 0x800)
            SmallFont_DrawAscii(gUnknown_084F0108, 0x70, 0x38, 4);
        else if (hstatus & 0x4000)
            SmallFont_DrawAscii(gUnknown_084F010C, 0x58, 0x38, 4);
        else if (hstatus & 1)
            SmallFont_DrawAscii(gUnknown_084F0114, 0x60, 0x38, 4);
        else if (hstatus & 0x200)
            SmallFont_DrawAscii(gUnknown_084F011C, 0x60, 0x38, 4);
        else if (hstatus & 0x40)
            SmallFont_DrawAscii(gUnknown_084F0124, 0x60, 0x38, 4);
        else if (hstatus & 0x20)
            SmallFont_DrawAscii(gUnknown_084F012C, 0x68, 0x38, 4);
        else if (hstatus & 0x100)
            SmallFont_DrawAscii(gUnknown_084F0134, 0x58, 0x38, 4);
        else if (hstatus & 0x80)
            SmallFont_DrawAscii(gUnknown_084F013C, 0x60, 0x38, 4);
        else if (hstatus & 2)
            SmallFont_DrawAscii(gUnknown_084F0144, 0x60, 0x38, 4);
        else if (hstatus & 0x10)
            SmallFont_DrawAscii(gUnknown_084F014C, 0x60, 0x38, 4);
        else if (hstatus & 8)
            SmallFont_DrawAscii(gUnknown_084F0154, 0x60, 0x38, 4);
        else
            SmallFont_DrawAscii(gUnknown_084F015C, 0x68, 0x38, 4);
        SmallFont_DrawAscii(gUnknown_084F0164, 0xA, 0x44, 0);
        SmallFont_DrawNumber(c->unk8, 0x80, 0x44, 4);
        SmallFont_DrawAscii(gUnknown_084F0168, 0xA, 0x50, 0);
        if (c->level != 99)
            SmallFont_DrawNumber(Exp_GetForLevel(c->level + 1) - c->unk8, 0x80, 0x50, 4);
        if (sub_080C93B4(st->sel) == 1)
        {
            SmallFont_DrawAscii(gUnknown_084F0170, 0xA, 0x5C, 0);
            SmallFont_DrawNumber(gGameState.stockMax, 0x80, 0x5C, 4);
            SmallFont_DrawAscii(gUnknown_084F00DC, 0x70, 0x5C, 4);
            n = 0;
            for (i = 4; i < 16; i++)
            {
                if (Combatant_IsUsed(i))
                    n++;
            }
            SmallFont_DrawNumber(n, 0x68, 0x5C, 4);
        }
        return;
    }
    if (sub_080C92AC(c->demonId) != 1)
    {
        if (sub_080C99B8(c) == 1)
        {
            SmallFont_DrawAscii(gUnknown_084F0178, 0x56, 0x1E, 0);
            SmallFont_DrawAscii(gUnknown_084F017C, 0x60, 0x28, 4);
            SmallFont_DrawAscii(gUnknown_084F00D8, 0x56, 0x32, 0);
            SmallFont_DrawAscii(gUnknown_084F0184, 0x62, 0x3C, 4);
            SmallFont_DrawAscii(gUnknown_084F00DC, 0x78, 0x3C, 4);
            SmallFont_DrawAscii(gUnknown_084F0184, 0x80, 0x3C, 4);
            SmallFont_DrawAscii(gUnknown_084F00E0, 0x56, 0x46, 0);
            SmallFont_DrawAscii(gUnknown_084F0184, 0x62, 0x50, 4);
            SmallFont_DrawAscii(gUnknown_084F00DC, 0x78, 0x50, 4);
            SmallFont_DrawAscii(gUnknown_084F0184, 0x80, 0x50, 4);
            SmallFont_DrawAscii(gUnknown_084F00E4, 0x56, 0x5A, 0);
            SmallFont_DrawAscii(gUnknown_084F0188, 0x78, 0x64, 4);
            SmallFont_DrawAscii(gUnknown_084F0190, 0x56, 0x6E, 0);
            SmallFont_DrawAscii(gUnknown_084F0188, 0x78, 0x78, 4);
        }
        else
        {
            stock = Stock_FindByDemonId(c->demonId);
            if (stock != NULL)
                status = Combatant_GetStatus(stock->id);
            else
                status = 0;
            SmallFont_DrawAscii(gUnknown_084F0178, 0x56, 0x1E, 0);
            sub_080CD044(c->demonId, 0x60, 0x28);
            hp = c->hp;
            mp = c->mp;
            if (st->mode == 7)
            {
                hp = Stock_FindByDemonId(c->demonId)->hp;
                mp = Stock_FindByDemonId(c->demonId)->mp;
            }
            else if (st->mode == 6 && gUnk_0203B854[4] == 2)
            {
                bonus = sub_08157C2C();
                if (bonus != 0)
                {
                    if (bonus & 1)
                    {
                        hp += c->maxHp / 4;
                        if (hp > 999)
                            hp = 999;
                    }
                    if (bonus & 2)
                    {
                        mp += c->maxMp / 4;
                        if (mp > 999)
                            mp = 999;
                    }
                }
            }
            SmallFont_DrawAscii(gUnknown_084F00D8, 0x56, 0x32, 0);
            SmallFont_DrawNumber(hp, 0x70, 0x3C, 4);
            SmallFont_DrawAscii(gUnknown_084F00DC, 0x78, 0x3C, 4);
            SmallFont_DrawNumber(c->maxHp, 0x90, 0x3C, 4);
            SmallFont_DrawAscii(gUnknown_084F00E0, 0x56, 0x46, 0);
            SmallFont_DrawNumber(mp, 0x70, 0x50, 4);
            SmallFont_DrawAscii(gUnknown_084F00DC, 0x78, 0x50, 4);
            SmallFont_DrawNumber(c->maxMp, 0x90, 0x50, 4);
            SmallFont_DrawAscii(gUnknown_084F00E4, 0x56, 0x5A, 0);
            if (status & 0x8000)
                SmallFont_DrawAscii(gUnknown_084F0194, 0x78, 0x64, 4);
            else if (status & 0x2000)
                SmallFont_DrawAscii(gUnknown_084F00F0, 0x70, 0x64, 4);
            else if (status & 0x1000)
                SmallFont_DrawAscii(gUnknown_084F00F8, 0x68, 0x64, 4);
            else if (status & 4)
                SmallFont_DrawAscii(gUnknown_084F0100, 0x68, 0x64, 4);
            else if (status & 0x800)
                SmallFont_DrawAscii(gUnknown_084F0108, 0x80, 0x64, 4);
            else if (status & 0x4000)
                SmallFont_DrawAscii(gUnknown_084F010C, 0x68, 0x64, 4);
            else if (status & 1)
                SmallFont_DrawAscii(gUnknown_084F0114, 0x70, 0x64, 4);
            else if (status & 0x200)
                SmallFont_DrawAscii(gUnknown_084F011C, 0x70, 0x64, 4);
            else if (status & 0x40)
                SmallFont_DrawAscii(gUnknown_084F0124, 0x70, 0x64, 4);
            else if (status & 0x20)
                SmallFont_DrawAscii(gUnknown_084F012C, 0x78, 0x64, 4);
            else if (status & 0x100)
                SmallFont_DrawAscii(gUnknown_084F0134, 0x68, 0x64, 4);
            else if (status & 0x80)
                SmallFont_DrawAscii(gUnknown_084F013C, 0x70, 0x64, 4);
            else if (status & 2)
                SmallFont_DrawAscii(gUnknown_084F0144, 0x70, 0x64, 4);
            else if (status & 0x10)
                SmallFont_DrawAscii(gUnknown_084F014C, 0x70, 0x64, 4);
            else if (status & 8)
                SmallFont_DrawAscii(gUnknown_084F0154, 0x70, 0x64, 4);
            else
                SmallFont_DrawAscii(gUnknown_084F015C, 0x78, 0x64, 4);
            SmallFont_DrawAscii(gUnknown_084F0190, 0x56, 0x6E, 0);
            sub_080CD0E4(c->demonId);
        }
    }
    st->sprite = DemonObj_Create(0, c->demonId, -gUnk_03000004, 0x18, 0, 0);
    sub_080C3E40(st->sprite, 1);
    gPaletteBuffer[0x1A0 / 2] = 0x10;
    gPaletteBuffer[0x1A2 / 2] = 0x10;
}
