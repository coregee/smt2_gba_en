/* Super 27: payout, bonus cards and number display (0x08140AD8-0x0814213F). */

#include "global.h"
#include "casino.h"

/* Super 27 bonus line scan, one of the 27 lines (one row per reel) per call: when the
   first reel shows symbol 8 in a row (unk2E = 3/2/1 for rows 0/1/2), every line through
   that row is checked; a win records the line (y 0x40/0x2C/0x18 per row) and sets the
   payout. A win on the last line advances the step counter twice. */
// Super27_ScanBonusLine @ 0x08140AD8
void Super27_ScanBonusLine(void)
{
    struct CasinoScene *scene = (struct CasinoScene *)0x0203B554;
    struct Super27 *s = (struct Super27 *)gMenuState;

    s->lineSym[0] = gUnknown_0879245C[scene->arg][s->sym[0][0]].sym;
    s->lineSym[1] = gUnknown_0879245C[scene->arg][s->sym[0][1]].sym;
    s->lineSym[2] = gUnknown_0879245C[scene->arg][s->sym[0][2]].sym;
    s->cardFound = 0;
    if (s->unk2C == 0 && s->unk2A == 0)
    {
        if (s->unk2E < 2)
        {
            if (s->lineSym[2] == gUnknown_087931DC[scene->arg][s->sym[1][2]].sym
                && s->lineSym[2] == gUnknown_08793F5C[scene->arg][s->sym[2][2]].sym)
            {
                s->lines[0].index = s->sym[0][2];
                s->lines[1].index = s->sym[1][2];
                s->lines[2].index = s->sym[2][2];
                s->winSym = s->lineSym[2];
                s->lines[2].y = 0x18;
                s->lines[1].y = 0x18;
                s->lines[0].y = 0x18;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 1;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 1 && s->unk2A == 0)
    {
        if (s->unk2E < 2)
        {
            if (s->lineSym[2] == gUnknown_087931DC[scene->arg][s->sym[1][2]].sym
                && s->lineSym[2] == gUnknown_08793F5C[scene->arg][s->sym[2][1]].sym)
            {
                s->lines[0].index = s->sym[0][2];
                s->lines[1].index = s->sym[1][2];
                s->lines[2].index = s->sym[2][1];
                s->winSym = s->lineSym[2];
                s->lines[1].y = 0x18;
                s->lines[0].y = 0x18;
                s->lines[2].y = 0x2C;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 1;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 2 && s->unk2A == 0)
    {
        if (s->unk2E < 2)
        {
            if (s->lineSym[2] == gUnknown_087931DC[scene->arg][s->sym[1][2]].sym
                && s->lineSym[2] == gUnknown_08793F5C[scene->arg][s->sym[2][0]].sym)
            {
                s->lines[0].index = s->sym[0][2];
                s->lines[1].index = s->sym[1][2];
                s->lines[2].index = s->sym[2][0];
                s->winSym = s->lineSym[2];
                s->lines[1].y = 0x18;
                s->lines[0].y = 0x18;
                s->lines[2].y = 0x40;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 1;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 3 && s->unk2A == 0)
    {
        if (s->unk2E < 2)
        {
            if (s->lineSym[2] == gUnknown_087931DC[scene->arg][s->sym[1][1]].sym
                && s->lineSym[2] == gUnknown_08793F5C[scene->arg][s->sym[2][2]].sym)
            {
                s->lines[0].index = s->sym[0][2];
                s->lines[1].index = s->sym[1][1];
                s->lines[2].index = s->sym[2][2];
                s->winSym = s->lineSym[2];
                s->lines[2].y = 0x18;
                s->lines[0].y = 0x18;
                s->lines[1].y = 0x2C;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 1;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 4 && s->unk2A == 0)
    {
        if (s->unk2E < 2)
        {
            if (s->lineSym[2] == gUnknown_087931DC[scene->arg][s->sym[1][1]].sym
                && s->lineSym[2] == gUnknown_08793F5C[scene->arg][s->sym[2][1]].sym)
            {
                s->lines[0].index = s->sym[0][2];
                s->lines[1].index = s->sym[1][1];
                s->lines[2].index = s->sym[2][1];
                s->winSym = s->lineSym[2];
                s->lines[2].y = 0x2C;
                s->lines[1].y = 0x2C;
                s->lines[0].y = 0x18;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 1;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 5 && s->unk2A == 0)
    {
        if (s->unk2E < 2)
        {
            if (s->lineSym[2] == gUnknown_087931DC[scene->arg][s->sym[1][1]].sym
                && s->lineSym[2] == gUnknown_08793F5C[scene->arg][s->sym[2][0]].sym)
            {
                s->lines[0].index = s->sym[0][2];
                s->lines[1].index = s->sym[1][1];
                s->lines[2].index = s->sym[2][0];
                s->winSym = s->lineSym[2];
                s->lines[0].y = 0x18;
                s->lines[1].y = 0x2C;
                s->lines[2].y = 0x40;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 1;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 6 && s->unk2A == 0)
    {
        if (s->unk2E < 2)
        {
            if (s->lineSym[2] == gUnknown_087931DC[scene->arg][s->sym[1][0]].sym
                && s->lineSym[2] == gUnknown_08793F5C[scene->arg][s->sym[2][2]].sym)
            {
                s->lines[0].index = s->sym[0][2];
                s->lines[1].index = s->sym[1][0];
                s->lines[2].index = s->sym[2][2];
                s->winSym = s->lineSym[2];
                s->lines[2].y = 0x18;
                s->lines[0].y = 0x18;
                s->lines[1].y = 0x40;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 1;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 7 && s->unk2A == 0)
    {
        if (s->unk2E < 2)
        {
            if (s->lineSym[2] == gUnknown_087931DC[scene->arg][s->sym[1][0]].sym
                && s->lineSym[2] == gUnknown_08793F5C[scene->arg][s->sym[2][1]].sym)
            {
                s->lines[0].index = s->sym[0][2];
                s->lines[1].index = s->sym[1][0];
                s->lines[2].index = s->sym[2][1];
                s->winSym = s->lineSym[2];
                s->lines[0].y = 0x18;
                s->lines[1].y = 0x40;
                s->lines[2].y = 0x2C;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 1;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 8 && s->unk2A == 0)
    {
        if (s->unk2E < 2)
        {
            if (s->lineSym[2] == gUnknown_087931DC[scene->arg][s->sym[1][0]].sym
                && s->lineSym[2] == gUnknown_08793F5C[scene->arg][s->sym[2][0]].sym)
            {
                s->lines[0].index = s->sym[0][2];
                s->lines[1].index = s->sym[1][0];
                s->lines[2].index = s->sym[2][0];
                s->winSym = s->lineSym[2];
                s->lines[2].y = 0x40;
                s->lines[1].y = 0x40;
                s->lines[0].y = 0x18;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 1;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 9 && s->unk2A == 0)
    {
        if (s->unk2E == 0 || s->unk2E == 2)
        {
            if (s->lineSym[1] == gUnknown_087931DC[scene->arg][s->sym[1][2]].sym
                && s->lineSym[1] == gUnknown_08793F5C[scene->arg][s->sym[2][2]].sym)
            {
                s->lines[0].index = s->sym[0][1];
                s->lines[1].index = s->sym[1][2];
                s->lines[2].index = s->sym[2][2];
                s->winSym = s->lineSym[1];
                s->lines[0].y = 0x2C;
                s->lines[2].y = 0x18;
                s->lines[1].y = 0x18;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 2;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 10 && s->unk2A == 0)
    {
        if (s->unk2E == 0 || s->unk2E == 2)
        {
            if (s->lineSym[1] == gUnknown_087931DC[scene->arg][s->sym[1][2]].sym
                && s->lineSym[1] == gUnknown_08793F5C[scene->arg][s->sym[2][1]].sym)
            {
                s->lines[0].index = s->sym[0][1];
                s->lines[1].index = s->sym[1][2];
                s->lines[2].index = s->sym[2][1];
                s->winSym = s->lineSym[1];
                s->lines[2].y = 0x2C;
                s->lines[0].y = 0x2C;
                s->lines[1].y = 0x18;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 2;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 11 && s->unk2A == 0)
    {
        if (s->unk2E == 0 || s->unk2E == 2)
        {
            if (s->lineSym[1] == gUnknown_087931DC[scene->arg][s->sym[1][2]].sym
                && s->lineSym[1] == gUnknown_08793F5C[scene->arg][s->sym[2][0]].sym)
            {
                s->lines[0].index = s->sym[0][1];
                s->lines[1].index = s->sym[1][2];
                s->lines[2].index = s->sym[2][0];
                s->winSym = s->lineSym[1];
                s->lines[0].y = 0x2C;
                s->lines[1].y = 0x18;
                s->lines[2].y = 0x40;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 2;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 12 && s->unk2A == 0)
    {
        if (s->unk2E == 0 || s->unk2E == 2)
        {
            if (s->lineSym[1] == gUnknown_087931DC[scene->arg][s->sym[1][1]].sym
                && s->lineSym[1] == gUnknown_08793F5C[scene->arg][s->sym[2][2]].sym)
            {
                s->lines[0].index = s->sym[0][1];
                s->lines[1].index = s->sym[1][1];
                s->lines[2].index = s->sym[2][2];
                s->winSym = s->lineSym[1];
                s->lines[1].y = 0x2C;
                s->lines[0].y = 0x2C;
                s->lines[2].y = 0x18;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 2;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 13 && s->unk2A == 0)
    {
        if (s->unk2E == 0 || s->unk2E == 2)
        {
            if (s->lineSym[1] == gUnknown_087931DC[scene->arg][s->sym[1][1]].sym
                && s->lineSym[1] == gUnknown_08793F5C[scene->arg][s->sym[2][1]].sym)
            {
                s->lines[0].index = s->sym[0][1];
                s->lines[1].index = s->sym[1][1];
                s->lines[2].index = s->sym[2][1];
                s->winSym = s->lineSym[1];
                s->lines[2].y = 0x2C;
                s->lines[1].y = 0x2C;
                s->lines[0].y = 0x2C;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 2;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 14 && s->unk2A == 0)
    {
        if (s->unk2E == 0 || s->unk2E == 2)
        {
            if (s->lineSym[1] == gUnknown_087931DC[scene->arg][s->sym[1][1]].sym
                && s->lineSym[1] == gUnknown_08793F5C[scene->arg][s->sym[2][0]].sym)
            {
                s->lines[0].index = s->sym[0][1];
                s->lines[1].index = s->sym[1][1];
                s->lines[2].index = s->sym[2][0];
                s->winSym = s->lineSym[1];
                s->lines[1].y = 0x2C;
                s->lines[0].y = 0x2C;
                s->lines[2].y = 0x40;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 2;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 15 && s->unk2A == 0)
    {
        if (s->unk2E == 0 || s->unk2E == 2)
        {
            if (s->lineSym[1] == gUnknown_087931DC[scene->arg][s->sym[1][0]].sym
                && s->lineSym[1] == gUnknown_08793F5C[scene->arg][s->sym[2][2]].sym)
            {
                s->lines[0].index = s->sym[0][1];
                s->lines[1].index = s->sym[1][0];
                s->lines[2].index = s->sym[2][2];
                s->winSym = s->lineSym[1];
                s->lines[0].y = 0x2C;
                s->lines[1].y = 0x40;
                s->lines[2].y = 0x18;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 2;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 16 && s->unk2A == 0)
    {
        if (s->unk2E == 0 || s->unk2E == 2)
        {
            if (s->lineSym[1] == gUnknown_087931DC[scene->arg][s->sym[1][0]].sym
                && s->lineSym[1] == gUnknown_08793F5C[scene->arg][s->sym[2][1]].sym)
            {
                s->lines[0].index = s->sym[0][1];
                s->lines[1].index = s->sym[1][0];
                s->lines[2].index = s->sym[2][1];
                s->winSym = s->lineSym[1];
                s->lines[2].y = 0x2C;
                s->lines[0].y = 0x2C;
                s->lines[1].y = 0x40;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 2;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 17 && s->unk2A == 0)
    {
        if (s->unk2E == 0 || s->unk2E == 2)
        {
            if (s->lineSym[1] == gUnknown_087931DC[scene->arg][s->sym[1][0]].sym
                && s->lineSym[1] == gUnknown_08793F5C[scene->arg][s->sym[2][0]].sym)
            {
                s->lines[0].index = s->sym[0][1];
                s->lines[1].index = s->sym[1][0];
                s->lines[2].index = s->sym[2][0];
                s->winSym = s->lineSym[1];
                s->lines[0].y = 0x2C;
                s->lines[2].y = 0x40;
                s->lines[1].y = 0x40;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 2;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 18 && s->unk2A == 0)
    {
        if (s->unk2E == 0 || s->unk2E == 3)
        {
            if (s->lineSym[0] == gUnknown_087931DC[scene->arg][s->sym[1][2]].sym
                && s->lineSym[0] == gUnknown_08793F5C[scene->arg][s->sym[2][2]].sym)
            {
                s->lines[0].index = s->sym[0][0];
                s->lines[1].index = s->sym[1][2];
                s->lines[2].index = s->sym[2][2];
                s->winSym = s->lineSym[0];
                s->lines[0].y = 0x40;
                s->lines[2].y = 0x18;
                s->lines[1].y = 0x18;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 3;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 19 && s->unk2A == 0)
    {
        if (s->unk2E == 0 || s->unk2E == 3)
        {
            if (s->lineSym[0] == gUnknown_087931DC[scene->arg][s->sym[1][2]].sym
                && s->lineSym[0] == gUnknown_08793F5C[scene->arg][s->sym[2][1]].sym)
            {
                s->lines[0].index = s->sym[0][0];
                s->lines[1].index = s->sym[1][2];
                s->lines[2].index = s->sym[2][1];
                s->winSym = s->lineSym[0];
                s->lines[0].y = 0x40;
                s->lines[1].y = 0x18;
                s->lines[2].y = 0x2C;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 3;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 20 && s->unk2A == 0)
    {
        if (s->unk2E == 0 || s->unk2E == 3)
        {
            if (s->lineSym[0] == gUnknown_087931DC[scene->arg][s->sym[1][2]].sym
                && s->lineSym[0] == gUnknown_08793F5C[scene->arg][s->sym[2][0]].sym)
            {
                s->lines[0].index = s->sym[0][0];
                s->lines[1].index = s->sym[1][2];
                s->lines[2].index = s->sym[2][0];
                s->winSym = s->lineSym[0];
                s->lines[2].y = 0x40;
                s->lines[0].y = 0x40;
                s->lines[1].y = 0x18;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 3;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 21 && s->unk2A == 0)
    {
        if (s->unk2E == 0 || s->unk2E == 3)
        {
            if (s->lineSym[0] == gUnknown_087931DC[scene->arg][s->sym[1][1]].sym
                && s->lineSym[0] == gUnknown_08793F5C[scene->arg][s->sym[2][2]].sym)
            {
                s->lines[0].index = s->sym[0][0];
                s->lines[1].index = s->sym[1][1];
                s->lines[2].index = s->sym[2][2];
                s->winSym = s->lineSym[0];
                s->lines[0].y = 0x40;
                s->lines[1].y = 0x2C;
                s->lines[2].y = 0x18;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 3;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 22 && s->unk2A == 0)
    {
        if (s->unk2E == 0 || s->unk2E == 3)
        {
            if (s->lineSym[0] == gUnknown_087931DC[scene->arg][s->sym[1][1]].sym
                && s->lineSym[0] == gUnknown_08793F5C[scene->arg][s->sym[2][1]].sym)
            {
                s->lines[0].index = s->sym[0][0];
                s->lines[1].index = s->sym[1][1];
                s->lines[2].index = s->sym[2][1];
                s->winSym = s->lineSym[0];
                s->lines[0].y = 0x40;
                s->lines[2].y = 0x2C;
                s->lines[1].y = 0x2C;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 3;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 23 && s->unk2A == 0)
    {
        if (s->unk2E == 0 || s->unk2E == 3)
        {
            if (s->lineSym[0] == gUnknown_087931DC[scene->arg][s->sym[1][1]].sym
                && s->lineSym[0] == gUnknown_08793F5C[scene->arg][s->sym[2][0]].sym)
            {
                s->lines[0].index = s->sym[0][0];
                s->lines[1].index = s->sym[1][1];
                s->lines[2].index = s->sym[2][0];
                s->winSym = s->lineSym[0];
                s->lines[2].y = 0x40;
                s->lines[0].y = 0x40;
                s->lines[1].y = 0x2C;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 3;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 24 && s->unk2A == 0)
    {
        if (s->unk2E == 0 || s->unk2E == 3)
        {
            if (s->lineSym[0] == gUnknown_087931DC[scene->arg][s->sym[1][0]].sym
                && s->lineSym[0] == gUnknown_08793F5C[scene->arg][s->sym[2][2]].sym)
            {
                s->lines[0].index = s->sym[0][0];
                s->lines[1].index = s->sym[1][0];
                s->lines[2].index = s->sym[2][2];
                s->winSym = s->lineSym[0];
                s->lines[1].y = 0x40;
                s->lines[0].y = 0x40;
                s->lines[2].y = 24;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 3;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 25 && s->unk2A == 0)
    {
        if (s->unk2E == 0 || s->unk2E == 3)
        {
            if (s->lineSym[0] == gUnknown_087931DC[scene->arg][s->sym[1][0]].sym
                && s->lineSym[0] == gUnknown_08793F5C[scene->arg][s->sym[2][1]].sym)
            {
                s->lines[0].index = s->sym[0][0];
                s->lines[1].index = s->sym[1][0];
                s->lines[2].index = s->sym[2][1];
                s->winSym = s->lineSym[0];
                s->lines[1].y = 0x40;
                s->lines[0].y = 0x40;
                s->lines[2].y = 0x2C;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 3;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
    if (s->unk2C == 26 && s->unk2A == 0)
    {
        if (s->unk2E == 0 || s->unk2E == 3)
        {
            if (s->lineSym[0] == gUnknown_087931DC[scene->arg][s->sym[1][0]].sym
                && s->lineSym[0] == gUnknown_08793F5C[scene->arg][s->sym[2][0]].sym)
            {
                s->lines[0].index = s->sym[0][0];
                s->lines[1].index = s->sym[1][0];
                s->lines[2].index = s->sym[2][0];
                s->winSym = s->lineSym[0];
                s->lines[2].y = 0x40;
                s->lines[1].y = 0x40;
                s->lines[0].y = 0x40;
                s->unk2C++;
                s->unk2A = 1;
                s->unk1E = 1;
                s->line = 3;
                Super27_SetPayout();
            }
        }
        s->unk2C++;
    }
}

/* Highlights the three winning symbols and the payout row of the winning symbol. */
// Super27_DrawWinHighlight @ 0x08141B08
void Super27_DrawWinHighlight(void)
{
    struct CasinoScene *scene = (struct CasinoScene *)0x0203B554;
    struct Super27 *s = (struct Super27 *)gMenuState;

    Sprite_Draw(gUnknown_0879245C[scene->arg][s->lines[0].index].litSprite, 0, 0, 3, 0, s->lines[0].x, s->lines[0].y & 0xFF);
    Sprite_Draw(gUnknown_087931DC[scene->arg][s->lines[1].index].litSprite, 0, 0, 3, 0, s->lines[1].x, s->lines[1].y & 0xFF);
    Sprite_Draw(gUnknown_08793F5C[scene->arg][s->lines[2].index].litSprite, 0, 0, 3, 0, s->lines[2].x, s->lines[2].y & 0xFF);
    Sprite_Draw(gUnknown_08794CDC[s->winSym].sprite, 0, 0, 0, 0, gUnknown_08794CDC[s->winSym].x, gUnknown_08794CDC[s->winSym].y & 0xFF);
}

/* Bonus cards: marks the first unmarked card showing the winning symbol (one per call). */
// Super27_MarkCard @ 0x08141C08
void Super27_MarkCard(void)
{
    struct Super27 *s = (struct Super27 *)gMenuState;

    if (s->cards[0].marked == 0 && s->cardFound == 0 && gUnknown_08794D90[s->cards[0].value].sym == s->winSym)
    {
        s->cards[0].marked = 1;
        s->cardFound = 1;
        s->cardCount++;
    }
    if (s->cards[1].marked == 0 && s->cardFound == 0 && gUnknown_08794D90[s->cards[1].value].sym == s->winSym)
    {
        s->cards[1].marked = 1;
        s->cardFound = 1;
        s->cardCount++;
    }
    if (s->cards[2].marked == 0 && s->cardFound == 0 && gUnknown_08794D90[s->cards[2].value].sym == s->winSym)
    {
        s->cards[2].marked = 1;
        s->cardFound = 1;
        s->cardCount++;
    }
    if (s->cards[3].marked == 0 && s->cardFound == 0 && gUnknown_08794D90[s->cards[3].value].sym == s->winSym)
    {
        s->cards[3].marked = 1;
        s->cardFound = 1;
        s->cardCount++;
    }
    if (s->cards[4].marked == 0 && s->cardFound == 0 && gUnknown_08794D90[s->cards[4].value].sym == s->winSym)
    {
        s->cards[4].marked = 1;
        s->cardFound = 1;
        s->cardCount++;
    }
    if (s->cards[5].marked == 0 && s->cardFound == 0 && gUnknown_08794D90[s->cards[5].value].sym == s->winSym)
    {
        s->cards[5].marked = 1;
        s->cardFound = 1;
        s->cardCount++;
    }
}

// Super27_DrawMarkedCards @ 0x08141D90
void Super27_DrawMarkedCards(void)
{
    struct Super27 *s = (struct Super27 *)gMenuState;

    if (s->cards[0].marked == 1)
        Sprite_Draw(gUnknown_08794D90[s->cards[0].value].litSprite, 0, 0, 0, 0, s->scroll + 0x39, 0x5A);
    if (s->cards[1].marked == 1)
        Sprite_Draw(gUnknown_08794D90[s->cards[1].value].litSprite, 0, 0, 0, 0, s->scroll + 0x4E, 0x5A);
    if (s->cards[2].marked == 1)
        Sprite_Draw(gUnknown_08794D90[s->cards[2].value].litSprite, 0, 0, 0, 0, s->scroll + 0x63, 0x5A);
    if (s->cards[3].marked == 1)
        Sprite_Draw(gUnknown_08794D90[s->cards[3].value].litSprite, 0, 0, 0, 0, s->scroll + 0x78, 0x5A);
    if (s->cards[4].marked == 1)
        Sprite_Draw(gUnknown_08794D90[s->cards[4].value].litSprite, 0, 0, 0, 0, s->scroll + 0x8D, 0x5A);
    if (s->cards[5].marked == 1)
        Sprite_Draw(gUnknown_08794D90[s->cards[5].value].litSprite, 0, 0, 0, 0, s->scroll + 0xA2, 0x5A);
}

/* Releases all holds and stops the reels. */
// Super27_ClearHolds @ 0x08141F04
void Super27_ClearHolds(void)
{
    struct Super27 *s = (struct Super27 *)gMenuState;

    s->unk18 = 0;
    s->heldCount = 0;
    s->held[2] = 0;
    s->held[1] = 0;
    s->held[0] = 0;
    s->phase = 0;
}

/* Sets the payout target: bet display + the winning symbol's payout from the pay table
   0x08794CDC, capped at 1000. Symbol 8 pays a random bonus from its row, but `& 4` only
   picks entry 0 or 4 (5 or 100 coins); entries 1-3 (10, 20, 50) are never chosen. */
// Super27_SetPayout @ 0x08141F24
void Super27_SetPayout(void)
{
    struct Super27 *s = (struct Super27 *)gMenuState;
    u32 win = s->win;
    s32 sym;
    u16 r;

    s->target = win;
    if (s->line == 1)
    {
        sym = s->lineSym[2];
        if (sym == 8)
        {
            r = Random_Byte() & 4;
            s->target += gUnknown_08794CDC[8].pay[r];
            goto clamp;
        }
    }
    else if (s->line == 2)
    {
        sym = s->lineSym[1];
        if (sym == 8)
        {
            r = Random_Byte() & 4;
            s->target += gUnknown_08794CDC[8].pay[r];
            goto clamp;
        }
    }
    else if (s->line == 3)
    {
        sym = s->lineSym[0];
        if (sym == 8)
        {
            r = Random_Byte() & 4;
            s->target += gUnknown_08794CDC[8].pay[r];
            goto clamp;
        }
    }
    else
        goto clamp;
    s->target = win + gUnknown_08794CDC[sym].pay[0];
clamp:
    if (s->target > 999)
        s->target = 1000;
}

/* Draws a number as six digit sprites, right-aligned at x (8 pixels per digit). */
// Super27_DrawNumber @ 0x08141FE0
void Super27_DrawNumber(u32 value, u16 x, u16 y, u16 priority)
{
    u8 *d = NumberToDigits(value);

    Sprite_Draw(gUnknown_08794DFC[d[0]], 0, 0, priority, 0, x, y & 0xFF);
    Sprite_Draw(gUnknown_08794DFC[d[1]], 0, 0, priority, 0, x - 8, y & 0xFF);
    Sprite_Draw(gUnknown_08794DFC[d[2]], 0, 0, priority, 0, x - 16, y & 0xFF);
    Sprite_Draw(gUnknown_08794DFC[d[3]], 0, 0, priority, 0, x - 24, y & 0xFF);
    Sprite_Draw(gUnknown_08794DFC[d[4]], 0, 0, priority, 0, x - 32, y & 0xFF);
    Sprite_Draw(gUnknown_08794DFC[d[5]], 0, 0, priority, 0, x - 40, y & 0xFF);
}

/* Counts the win display up to the target every fourth frame; a full 1000 is paid out
   at once and ends the round. */
// Super27_CountPayout @ 0x081420E0
void Super27_CountPayout(void)
{
    struct Super27 *s = (struct Super27 *)gMenuState;

    if ((gFrameCounter & 3) == 0)
    {
        if (s->win != s->target)
        {
            Sound_Play(0x159);
            s->win++;
        }
        else if (s->win == 1000)
        {
            s->coins += 1000;
            s->win = 0;
            s->mode = 6;
        }
        else
            s->mode = 4;
    }
}

// Super27_SetInit @ 0x08142134
void Super27_SetInit(u32 unused, u16 value)
{
    struct Super27 *s = (struct Super27 *)gMenuState;

    s->init = value;
}
