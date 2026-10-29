/* Casino minigame (end of the game started in asm/code_08145784.s): 0x0814A414-0x0814AE27. */

#include "global.h"
#include "casino3.h"

#define GX ((struct C14aGameX *)gMenuState)

void CasinoText_DrawString(const u16 *str, u16 a1, u16 a2, u16 x, u16 y, u16 step);

// sub_0814A414 @ 0x0814A414
void sub_0814A414(void)
{
    struct C14aGameX *s = GX;

    if ((gFrameCounter & 3) == 0)
    {
        Sound_Play(0x159);
        if (gRepeatedKeys & 1)
            s->unk38 = BigSmall_GetCountStep(s->unk2C);
        else
            s->unk38 = 5;
        s->unk2C -= s->unk38;
        s->unk28 += s->unk38;
        if (s->unk2C <= 0)
        {
            s->unk28 = s->unk34 + s->unk30;
            s->unk30 = 0;
            s->unk0C = 0;
            Inventory_AddItem(gUnknown_0879E2A4[s->unk262][s->unk46].item);
            s->unk46 = 0;
            s->unk1A = 99;
            s->state = 7;
        }
    }
}

// BigSmall_NextNumber @ 0x0814A4AC
void BigSmall_NextNumber(void)
{
    struct C14aGameX *s = GX;

    s->unk54 = Random_Byte() & 5;
    if (s->number + s->unk54 > 9)
        s->number = s->number + s->unk54 - 10;
    else
        s->number = s->number + s->unk54;
    s->timer++;
}

// sub_0814A4DC @ 0x0814A4DC
void sub_0814A4DC(void)
{
    struct C14aGameX *s = GX;

    s->unk26 = 0;
    if (s->unk1C <= 3)
        Sprite_Draw(gUnknown_0814F970, 0, 0, 0, 0, 0xBA, 5);
    else if ((u16)(s->unk20 - 4) <= 2)
        Sprite_Draw(gUnknown_0814F988, 0, 0, 0, 0, 0xBA, 5);
    else if (s->unk1C > 6 && s->unk20 <= 9)
        Sprite_Draw(gUnknown_0814F9A0, 0, 0, 0, 0, 0xBA, 5);
    else if (s->unk1C > 9)
        s->unk24 = 1;
    s->unk20++;
}

// sub_0814A568 @ 0x0814A568
void sub_0814A568(void)
{
    struct C14aGameX *s = GX;

    s->unk27 = 0;
    if (s->unk1E <= 3)
        Sprite_Draw(gUnknown_0814F970, 1, 0, 0, 0, 7, 5);
    else if ((u16)(s->unk1E - 4) <= 2)
        Sprite_Draw(gUnknown_0814F988, 1, 0, 0, 0, 7, 5);
    else if ((u16)(s->unk1E - 7) <= 2)
        Sprite_Draw(gUnknown_0814F9A0, 1, 0, 0, 0, 7, 5);
    else if (s->unk1E > 9)
        s->unk25 = 1;
    s->unk1E++;
}

// sub_0814A5F0 @ 0x0814A5F0
void sub_0814A5F0(void)
{
    struct C14aGameX *s = GX;

    if (s->unk20 <= 3)
        Sprite_Draw(gUnknown_0814F9A0, 0, 0, 0, 0, 0xBA, 5);
    else if ((u16)(s->unk20 - 4) <= 2)
        Sprite_Draw(gUnknown_0814F988, 0, 0, 0, 0, 0xBA, 5);
    else if ((u16)(s->unk20 - 7) <= 2)
        Sprite_Draw(gUnknown_0814F970, 0, 0, 0, 0, 0xBA, 5);
    else if (s->unk20 > 9)
    {
        Sprite_Draw(gUnknown_0814F958, 0, 0, 0, 0, 0xBA, 5);
        s->unk26 = 1;
        s->unk24 = 0;
    }
    s->unk20++;
}

// sub_0814A684 @ 0x0814A684
void sub_0814A684(void)
{
    struct C14aGameX *s = GX;

    if (s->unk22 <= 3)
        Sprite_Draw(gUnknown_0814F9A0, 1, 0, 0, 0, 7, 5);
    else if ((u16)(s->unk22 - 4) <= 2)
        Sprite_Draw(gUnknown_0814F988, 1, 0, 0, 0, 7, 5);
    else if ((u16)(s->unk22 - 7) <= 2)
        Sprite_Draw(gUnknown_0814F970, 1, 0, 0, 0, 7, 5);
    else if (s->unk22 > 9)
    {
        Sprite_Draw(gUnknown_0814F958, 1, 0, 0, 0, 7, 5);
        s->unk27 = 1;
        s->unk25 = 0;
    }
    s->unk22++;
}

// sub_0814A718 @ 0x0814A718
void sub_0814A718(void)
{
    struct C14aGameX *s = GX;

    if (s->unk3E == 0 && s->unk40 <= 0xA2)
    {
        s->unk3C = 1;
        if (s->unk1A == 0 || s->unk1A == 99)
            Sound_Play(0x163);
        else
            Sound_Play(0x15E);
    }
    if (s->unk3C == 1 && ++s->unk3E == 0x14)
        s->unk3C = 0;
    if (s->unk1A == 0 || s->unk1A == 99)
        Sprite_Draw(gUnknown_0814F7DC, 0, 0, 0, 0, s->unk40 - s->unk44, 0x3F);
    else
    {
        Sprite_Draw(gUnknown_0814F7C0, 0, 0, 0, 0, s->unk40 - s->unk42, 0x3F);
        sub_0814A9A4();
    }
    if (s->count == 0x3D)
    {
        gUnk_0300000C = s->unk260;
        if (gUnk_0300000C == 0xF)
        {
            sub_0814AD74();
            gUnk_0300000C -= s->unk260;
            s->unk260 = 0;
            s->count -= 4;
        }
        else
            s->unk260++;
    }
    else if (s->entries[s->count - s->unk58].value > 4)
        sub_0814AA70();
    else
        sub_0814AB5C();
    if (s->unk40 == 0)
    {
        s->unk40 = 0x154;
        s->unk3E = 0;
        if (s->unk1A == 0 || s->unk1A == 99)
        {
            s->unk2C = 0;
            s->unk30 = 0;
            s->unk46 = 0;
            s->state = 7;
        }
        else
        {
            s->state = 3;
            s->unk4A[s->unk46] = 1;
            s->unk46++;
        }
    }
    if (s->unk3C == 0)
        s->unk40 -= 4;
}

// sub_0814A8B0 @ 0x0814A8B0
void sub_0814A8B0(void)
{
    struct C14aGameX *s = GX;
    u16 i;

    for (i = 0; i < 10; i++)
    {
        if (s->unk4A[i] == 1)
            Sprite_Draw(gUnknown_0879DE24[i].def, 0, 0, 0, 0, gUnknown_0879DE24[i].x, gUnknown_0879DE24[i].y);
    }
    Font_ResetGlyphSpriteCache(0x3A0);
    if (s->unk46 == 2 || s->unk46 == 7)
        CasinoText_DrawString(gUnknown_0879DF8C[s->unk262][s->unk46], 0, 0,
                     gUnknown_0879E2A4[s->unk262][s->unk46].value + 0x46, 0x52, 0xC);
    else
        CasinoText_DrawString(gUnknown_0879DF8C[s->unk262][s->unk46], 0, 0,
                     gUnknown_0879E2A4[s->unk262][s->unk46].value + 0x4D, 0x52, 0xA);
}

// sub_0814A9A4 @ 0x0814A9A4
void sub_0814A9A4(void)
{
    struct C14aGameX *s = GX;

    if (s->unk48 > 3)
        Sprite_Draw(gUnknown_0879DE24[s->unk46].def, 0, 0, 0, 0, gUnknown_0879DE24[s->unk46].x,
                    gUnknown_0879DE24[s->unk46].y);
    if (s->unk48 > 6)
        s->unk48 = 0;
    s->unk48++;
}

// sub_0814AA04 @ 0x0814AA04
void sub_0814AA04(void)
{
    struct C14aGameX *s = GX;
    u16 i;

    for (i = 0; i < 60; i++)
    {
        if (s->entries[i].shown == 1)
            Sprite_Draw(gUnknown_0879DE74[s->entries[i].value], 0, 0, 2, 0,
                        gUnknown_0879DE9C[i].x - s->unk260, gUnknown_0879DE9C[i].y);
    }
}

// sub_0814AA70 @ 0x0814AA70
void sub_0814AA70(void)
{
    struct C14aGameX *s = GX;

    if (s->unk5A <= 3)
        Sprite_Draw(gUnknown_0814F900, 0, 0, 0, 0, gUnknown_0879DE9C[s->count - 1].x, gUnknown_0879DE9C[s->count - 1].y);
    else if ((u16)(s->unk5A - 4) <= 2)
        Sprite_Draw(gUnknown_0814F910, 0, 0, 0, 0, gUnknown_0879DE9C[s->count - 1].x, gUnknown_0879DE9C[s->count - 1].y);
    else if ((u16)(s->unk5A - 7) <= 2)
        Sprite_Draw(gUnknown_0814F920, 0, 0, 0, 0, gUnknown_0879DE9C[s->count - 1].x, gUnknown_0879DE9C[s->count - 1].y);
    else if ((u16)(s->unk5A - 10) <= 2)
        Sprite_Draw(gUnknown_0814F930, 0, 0, 0, 0, gUnknown_0879DE9C[s->count - 1].x, gUnknown_0879DE9C[s->count - 1].y);
    else if ((u16)(s->unk5A - 13) <= 1)
    {
        Sprite_Draw(gUnknown_0814F940, 0, 0, 0, 0, gUnknown_0879DE9C[s->count - 1].x, gUnknown_0879DE9C[s->count - 1].y);
        s->entries[s->count - 1].shown = 1;
    }
    s->unk5A++;
}

// sub_0814AB5C @ 0x0814AB5C
void sub_0814AB5C(void)
{
    struct C14aGameX *s = GX;

    if (s->unk5C <= 3)
        Sprite_Draw(gUnknown_0814F8B0, 0, 0, 0, 0, gUnknown_0879DE9C[s->count - 1].x, gUnknown_0879DE9C[s->count - 1].y);
    else if ((u16)(s->unk5C - 4) <= 2)
        Sprite_Draw(gUnknown_0814F8C0, 0, 0, 0, 0, gUnknown_0879DE9C[s->count - 1].x, gUnknown_0879DE9C[s->count - 1].y);
    else if ((u16)(s->unk5C - 7) <= 2)
        Sprite_Draw(gUnknown_0814F8D0, 0, 0, 0, 0, gUnknown_0879DE9C[s->count - 1].x, gUnknown_0879DE9C[s->count - 1].y);
    else if ((u16)(s->unk5C - 10) <= 2)
        Sprite_Draw(gUnknown_0814F8E0, 0, 0, 0, 0, gUnknown_0879DE9C[s->count - 1].x, gUnknown_0879DE9C[s->count - 1].y);
    else if ((u16)(s->unk5C - 13) <= 1)
    {
        Sprite_Draw(gUnknown_0814F8F0, 0, 0, 0, 0, gUnknown_0879DE9C[s->count - 1].x, gUnknown_0879DE9C[s->count - 1].y);
        s->entries[s->count - 1].shown = 1;
    }
    s->unk5C++;
}

/* Adds the current number to the result board: four slots per column, a new column whenever
   the number changes between low (0-4) and high (5-9). */
// BigSmall_AddResult @ 0x0814AC48
void BigSmall_AddResult(void)
{
    struct C14aGameX *s = GX;
    u16 n;

    if (s->count == 0)
    {
        s->entries[s->count].value = s->number;
        s->count++;
        s->unk58 = 1;
        return;
    }
    n = s->count;
    if (s->entries[n - s->unk58].value > 4)
    {
        if (s->number > 4)
        {
            s->entries[n].value = s->number;
            s->count++;
            s->unk58 = 1;
        }
        else
        {
            switch (n & 3)
            {
            case 0:
                s->entries[n].value = s->number;
                s->count++;
                s->unk58 = 1;
                break;
            case 1:
                s->entries[n + 3].value = s->number;
                s->count += 4;
                s->unk58 = 1;
                break;
            case 2:
                s->entries[n + 2].value = s->number;
                s->count += 3;
                s->unk58 = 1;
                break;
            case 3:
                s->entries[n + 1].value = s->number;
                s->count += 2;
                s->unk58 = 1;
                break;
            }
        }
    }
    else
    {
        if (s->number <= 4)
        {
            s->entries[n].value = s->number;
            s->count++;
            s->unk58 = 1;
        }
        else
        {
            switch (n & 3)
            {
            case 0:
                s->entries[n].value = s->number;
                s->count++;
                s->unk58 = 1;
                break;
            case 1:
                s->entries[n + 3].value = s->number;
                s->count += 4;
                s->unk58 = 1;
                break;
            case 2:
                s->entries[n + 2].value = s->number;
                s->count += 3;
                s->unk58 = 1;
                break;
            case 3:
                s->entries[n + 1].value = s->number;
                s->count += 2;
                s->unk58 = 1;
                break;
            }
        }
    }
}

// sub_0814AD74 @ 0x0814AD74
void sub_0814AD74(void)
{
    struct C14aGameX *s = GX;
    u16 i;

    for (i = 0; i < 60; i++)
    {
        s->entries[i].shown = s->entries[i + 4].shown;
        s->entries[i].value = s->entries[i + 4].value;
    }
}

/* Draws a 0-terminated glyph string; 0x300 starts a new line. */
// CasinoText_DrawString @ 0x0814ADAC
void CasinoText_DrawString(const u16 *str, u16 a1, u16 a2, u16 x, u16 y, u16 step)
{
    u16 x0 = x;

    for (; *str != 0; str++)
    {
        if (*str == 0x300)
        {
            x = x0;
            y += step;
        }
        else
        {
            FontSprite_DrawGlyphTinted(*str, a1, a2, x, y, 0xF);
            x += step;
        }
    }
}
