#include "global.h"

/* Not field.h: it declares this function with a u16 dir, but the code uses the whole
   register. Only what is used here. */
struct ViewCell
{
    u16 valid;
    u16 unk2;
    u16 walls[4];
};
extern struct ViewCell gViewCells[][9];

struct FieldStatePos
{
    u16 pad00[9];
    u16 x;                       /* 0x12 */
    u16 y;                       /* 0x14 */
};
extern struct FieldStatePos gFieldState;

void View_FillCell(u16 x, u16 y, u16 col, u16 row);
u32 View_GetWall(u16 dir, u16 dx, u16 dy);
bool32 sub_080ADF40(void);

#define FIELD_DMA3_SET(src, dest, control)               \
{                                                        \
    vu32 *dmaRegs = (vu32 *)0x040000D4;                  \
    dmaRegs[0] = (u32)(src);                             \
    dmaRegs[1] = (u32)(dest);                            \
    dmaRegs[2] = (u32)(control);                         \
    dmaRegs[2];                                          \
}

#define W(dir, dx, dy) View_GetWall(dir, dx, dy)

/* Rebuilds the 9x9 view cells around the player for facing dir (View_FillCell), then, unless
   a (or sub_080ADF40), hides wall faces the first-person view cannot show: a face behind two
   walls that close the line of sight is cleared. */
// View_BuildCells @ 0x080AE574
void View_BuildCells(u32 dir, u32 a)
{
    u16 x = gFieldState.x;
    u16 y = gFieldState.y;
    u16 row, col;
    vu32 zero;
    u16 size = 9;

    zero = 0;
    FIELD_DMA3_SET(&zero, gViewCells, 0x850000F3);
    switch (dir)
    {
    case 0:
        x -= 4;
        y -= 5;
        break;
    case 1:
        x += 5;
        y -= 4;
        break;
    case 2:
        x += 4;
        y += 5;
        break;
    case 3:
        x -= 5;
        y += 4;
        break;
    }
    for (row = 0; row < size; row++)
    {
        for (col = 0; col < size; col++)
        {
            switch (dir)
            {
            case 0:
                View_FillCell((u16)(x + col), (u16)(y + row), col, row);
                break;
            case 1:
                View_FillCell((u16)(x - row), (u16)(y + col), col, row);
                break;
            case 2:
                View_FillCell((u16)(x - col), (u16)(y - row), col, row);
                break;
            case 3:
                View_FillCell((u16)(x + row), (u16)(y - col), col, row);
                break;
            }
        }
    }
    if (a == 0 && !sub_080ADF40())
    {
        if (((W(3, 0, 0) && W(3, 0, -1)) ||
            ((W(0, -1, 0) &&
             W(3, 0, -1)))) ||
           (((W(0, 0, 0) && W(3, 0, 0))
            || ((W(0, 0, 0) &&
                W(0, -1, 0)))))) {
          gViewCells[4][3].walls[0] = 0;
          gViewCells[3][3].walls[2] = 0;
        }
        if (((W(1, 0, 0) && W(1, 0, -1)) ||
            ((W(0, 1, 0) &&
             W(1, 0, -1)))) ||
           (((W(0, 0, 0) && W(1, 0, 0))
            || ((W(0, 0, 0) &&
                W(0, 1, 0)))))) {
          gViewCells[4][5].walls[0] = 0;
          gViewCells[3][5].walls[2] = 0;
        }
        if ((((W(3, 0, -1) && W(3, 0, -2)) ||
             ((W(3, 0, -1) &&
              W(0, 0, -1)))) ||
            ((W(0, 0, -1) &&
             W(0, -1, -1)))) ||
           ((W(0, -1, -1) &&
            W(3, 0, -2)))) {
          gViewCells[3][3].walls[0] = 0;
          gViewCells[2][3].walls[2] = 0;
        }
        if ((((W(3, 0, 0) && W(3, 0, -1)) ||
             ((W(0, -1, -1) &&
              W(3, 0, -1)))) ||
            (((W(3, 0, 0) &&
              W(3, 0, -1)) ||
             ((W(0, -1, 0) &&
              W(3, 0, -1)))))) ||
           ((W(0, 0, 0) &&
            W(0, -1, 0)))) {
          gViewCells[3][2].walls[0] = 0;
          gViewCells[2][2].walls[2] = 0;
        }
        if (((W(1, 0, -1) && W(1, 0, -2)) ||
            ((W(1, 0, -1) &&
             W(0, 0, -1)))) ||
           (((W(0, 0, -1) &&
             W(0, 1, -1)) ||
            ((W(0, 1, -1) &&
             W(1, 0, -2)))))) {
          gViewCells[3][5].walls[0] = 0;
          gViewCells[2][5].walls[2] = 0;
        }
        if ((((W(1, 0, 0) && W(1, 0, -1)) ||
             ((W(0, 1, -1) &&
              W(1, 0, -1)))) ||
            ((W(1, 0, 0) &&
             W(1, 0, -1)))) ||
           (((W(0, 1, 0) &&
             W(1, 0, -1)) ||
            ((W(0, 0, 0) && W(0, 1, 0)))
            ))) {
          gViewCells[3][6].walls[0] = 0;
          gViewCells[2][6].walls[2] = 0;
        }
        if (((W(0, 0, 0) && W(0, -1, 0)) ||
            ((W(0, -1, 0) &&
             W(3, 0, -1)))) ||
           ((W(3, 0, 0) &&
            W(3, 0, -1)))) {
          gViewCells[3][3].walls[3] = 0;
          gViewCells[3][2].walls[1] = 0;
        }
        if (((W(0, 0, 0) && W(0, 1, 0)) ||
            ((W(0, 1, 0) &&
             W(1, 0, -1)))) ||
           ((W(1, 0, 0) &&
            W(1, 0, -1)))) {
          gViewCells[3][5].walls[1] = 0;
          gViewCells[3][6].walls[3] = 0;
        }
        if (((W(0, 0, -1) && W(0, -1, -1)) ||
            ((W(0, -1, -1) &&
             W(3, 0, -2)))) ||
           (((W(3, 0, -1) &&
             W(3, 0, -2)) ||
            W(0, -1, -2)))) {
          gViewCells[2][3].walls[3] = 0;
          gViewCells[2][2].walls[1] = 0;
        }
        if (((W(0, 0, -1) && W(0, 1, -1)) ||
            ((W(0, 1, -1) &&
             W(1, 0, -2)))) ||
           (((W(1, 0, -1) &&
             W(1, 0, -2)) ||
            W(0, 1, -2)))) {
          gViewCells[2][5].walls[1] = 0;
          gViewCells[2][6].walls[3] = 0;
        }
        if (W(0, 0, 0) && W(3, 0, 0)) {
          gViewCells[3][3].walls[3] = 0;
          gViewCells[3][2].walls[1] = 0;
          gViewCells[3][2].walls[0] = 0;
          gViewCells[2][2].walls[2] = 0;
        }
        if (W(0, 0, 0) && W(1, 0, 0)) {
          gViewCells[3][5].walls[1] = 0;
          gViewCells[3][6].walls[3] = 0;
          gViewCells[3][6].walls[0] = 0;
          gViewCells[2][6].walls[2] = 0;
        }
        if (W(3, 0, 0)) {
          gViewCells[5][3].walls[3] = 0;
          gViewCells[5][2].walls[0] = 0;
        }
        if (W(1, 0, 0)) {
          gViewCells[5][5].walls[1] = 0;
          gViewCells[5][6].walls[0] = 0;
        }
        if (W(0, 0, -1) && W(3, 0, -1)) {
          gViewCells[2][3].walls[3] = 0;
        }
        if (W(0, 0, -1) && W(1, 0, -1)) {
          gViewCells[2][5].walls[1] = 0;
        }
    }
}
