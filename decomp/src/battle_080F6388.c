/* Battle action effects at the end of the battle action table (0x080F6388-0x080F6473). */

#include "global.h"
#include "battle2.h"

/* gFieldState (0x03004550): only the fields used here. */
struct F6388FieldState
{
    u8 pad00[0x12];
    u16 x;              /* 0x12 */
    u16 y;              /* 0x14 */
};
extern struct F6388FieldState gFieldState;

void Automap_SetVisited(u16 x, u16 y);

// sub_080F6388 @ 0x080F6388
void sub_080F6388(struct Action *a)
{
    a->unkC = 0;
}

// sub_080F6390 @ 0x080F6390
u8 sub_080F6390(void)
{
    return (Random_Byte() & 0xF) | 3;
}
// sub_080F63A4 @ 0x080F63A4
/* One-shot battle flag 0x200; message 0x96 when it is already set. */
void sub_080F63A4(struct Action *a)
{
    if (BattleFlags_Get() & 0x200)
        a->msg = 0x96;
    else
        BattleFlags_Add(0x200);
}

// sub_080F63C8 @ 0x080F63C8
void sub_080F63C8(struct Action *a)
{
    sub_080F6178(a, 0x20, 0x326);
}

// Automap_RevealAroundPlayer @ 0x080F63DC
/* Marks the 5x5 squares around the player as visited on the automap. */
void Automap_RevealAroundPlayer(void)
{
    s16 x0 = gFieldState.x - 2;
    s16 y0 = gFieldState.y - 2;
    s16 i, j;

    for (i = 0; i <= 4; i++)
    {
        for (j = 0; j <= 4; j++)
        {
            s32 x = x0 + j;
            s32 y;

            if (x > -1 && (y = y0 + i) > -1)
                Automap_SetVisited(x, y);
        }
    }
}

// sub_080F6448 @ 0x080F6448
/* One-shot battle flag 0x400; message 0x96 when it is already set. */
void sub_080F6448(struct Action *a)
{
    if (BattleFlags_Get() & 0x400)
        a->msg = 0x96;
    else
        BattleFlags_Add(0x400);
}

// sub_080F646C @ 0x080F646C
void sub_080F646C(struct Action *a)
{
    a->unkC = 0;
}
