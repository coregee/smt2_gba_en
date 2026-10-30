/* Code Breaker, part 2 (0x0814C52C-0x0814D7BB): the deduction notes. table[symbol][position].unk1
   records what the guesses so far prove: 0 unknown, 1 possible, 2 certain, 0xFF excluded;
   CodeBreaker_DrawNotes draws it. Symbol sets are bit masks (gUnknown_0879F05C = 1 << n). */

#include "global.h"
#include "casino3.h"

#define GY ((struct C14aCodeBreaker *)gMenuState)

/* Slots to skip to reach the first slot of the next row. */
// sub_0814C52C @ 0x0814C52C
u16 sub_0814C52C(u16 cursor)
{
    u16 n;

    switch (cursor % 5)
    {
    case 0:
        n = 5;
        break;
    case 1:
        n = 4;
        break;
    case 2:
        n = 3;
        break;
    case 3:
        n = 2;
        break;
    case 4:
        n = 1;
        break;
    }
    return n;
}

/* Stores the symbol set of the current row and how many different symbols it has. */
// sub_0814C580 @ 0x0814C580
void sub_0814C580(void)
{
    struct C14aCodeBreaker *s = GY;
    u8 mask = 0;
    u8 i;
    u8 count;
    u8 j;

    for (i = 0; i < s->digits; i++)
    {
        count = s->board[s->row + i].symbol;
        mask |= gUnknown_0879F05C[count];
    }
    s->rowMask[(u8)(s->row / 5)] = mask;
    count = 0;
    for (j = 0; j < s->symbols; j++)
    {
        if (mask & 1)
        {
            mask >>= 1;
            mask |= 0x80;
            count++;
        }
        else
            mask >>= 1;
    }
    s->rowCount[(u8)(s->row / 5)] = count;
}

/* Sets unk1 = value for every symbol in mask, at every position not yet excluded/certain. */
// sub_0814C624 @ 0x0814C624
void sub_0814C624(u8 mask, u8 value)
{
    struct C14aCodeBreaker *s = GY;
    u16 i, j;
    u8 t;

    for (i = 0; i < s->symbols; i++)
    {
        if (mask & 1)
        {
            mask >>= 1;
            mask |= 0x80;
            for (j = 0; j < s->digits; j++)
            {
                t = s->table[i][j].unk1;
                if (t != 0xFF && t != 2)
                    s->table[i][j].unk1 = value;
            }
        }
        else
            mask >>= 1;
    }
}

// sub_0814C6C4 @ 0x0814C6C4
void sub_0814C6C4(u8 value)
{
    struct C14aCodeBreaker *s = GY;

    sub_0814C624(s->rowMask[(u8)(s->row / 5)], value);
}

/* As sub_0814C624 for the symbols not in the current row. */
// sub_0814C6F4 @ 0x0814C6F4
void sub_0814C6F4(u8 value)
{
    struct C14aCodeBreaker *s = GY;
    u8 mask = s->rowMask[(u8)(s->row / 5)];
    u16 i, j;

    for (i = 0; i < s->symbols; i++)
    {
        if (mask & 1)
        {
            mask >>= 1;
            mask |= 0x80;
        }
        else
        {
            mask >>= 1;
            for (j = 0; j < s->digits; j++)
            {
                if (s->table[i][j].unk1 != 0xFF && s->table[i][j].unk1 != 2)
                    s->table[i][j].unk1 = value;
            }
        }
    }
}

/* For the symbols of the current row: positions where the row has that symbol get value. */
// sub_0814C7A8 @ 0x0814C7A8
void sub_0814C7A8(u8 value)
{
    struct C14aCodeBreaker *s = GY;
    u8 mask = s->rowMask[(u8)(s->row / 5)];
    u16 i, j;
    u8 t;

    for (i = 0; i < s->symbols; i++)
    {
        if (mask & 1)
        {
            mask >>= 1;
            mask |= 0x80;
            for (j = 0; j < s->digits; j++)
            {
                t = s->table[i][j].unk1;
                if (s->board[s->row + j].symbol == i && t != 0xFF && t != 2)
                    s->table[i][j].unk1 = value;
            }
        }
        else
            mask >>= 1;
    }
}

/* For the symbols of the current row: positions where the row has another symbol get value. */
// sub_0814C878 @ 0x0814C878
void sub_0814C878(u8 value)
{
    struct C14aCodeBreaker *s = GY;
    u8 mask = s->rowMask[(u8)(s->row / 5)];
    u16 i, j;
    u8 t;

    for (i = 0; i < s->symbols; i++)
    {
        if (mask & 1)
        {
            mask >>= 1;
            mask |= 0x80;
            for (j = 0; j < s->digits; j++)
            {
                t = s->table[i][j].unk1;
                if (s->board[s->row + j].symbol != i && t != 0xFF && t != 2)
                    s->table[i][j].unk1 = value;
            }
        }
        else
            mask >>= 1;
    }
}

/* unk62 = the symbols that appear more than once in the current row. */
// sub_0814C948 @ 0x0814C948
void sub_0814C948(void)
{
    struct C14aCodeBreaker *s = GY;
    u8 mask = s->rowMask[(u8)(s->row / 5)];
    u8 dups = 0;
    u16 i, j;
    u8 n;

    for (i = 0; i < s->symbols; i++)
    {
        if (mask & 1)
        {
            mask >>= 1;
            mask |= 0x80;
            n = 0;
            for (j = 0; j < s->digits; j++)
            {
                if (i == s->board[s->row + j].symbol)
                    n++;
            }
            if (n > 1)
                dups |= gUnknown_0879F05C[i];
        }
        else
            mask >>= 1;
    }
    s->unk62 = dups;
}

// sub_0814CA18 @ 0x0814CA18
void sub_0814CA18(u8 value)
{
    sub_0814C624(GY->unk62, value);
}

/* Same code as sub_0814C624. */
// sub_0814CA34 @ 0x0814CA34
void sub_0814CA34(u8 mask, u8 value)
{
    struct C14aCodeBreaker *s = GY;
    u16 i, j;
    u8 t;

    for (i = 0; i < s->symbols; i++)
    {
        if (mask & 1)
        {
            mask >>= 1;
            mask |= 0x80;
            for (j = 0; j < s->digits; j++)
            {
                t = s->table[i][j].unk1;
                if (t != 0xFF && t != 2)
                    s->table[i][j].unk1 = value;
            }
        }
        else
            mask >>= 1;
    }
}

/* unk66 = the symbols excluded at every position, unk65 = how many. */
// sub_0814CAD4 @ 0x0814CAD4
void sub_0814CAD4(void)
{
    struct C14aCodeBreaker *s = GY;
    u8 mask = 0;
    u8 n = 0;
    u16 i, j;

    for (i = 0; i < s->symbols; i++)
    {
        for (j = 0; j < s->digits && s->table[i][j].unk1 == 0xFF; j++)
            ;
        if (j == s->digits)
        {
            mask |= gUnknown_0879F05C[i];
            n++;
        }
    }
    s->unk66 = mask;
    s->unk65 = n;
}

/* unk64 = the symbols possible or certain somewhere, unk63 = how many. */
// sub_0814CB90 @ 0x0814CB90
void sub_0814CB90(void)
{
    struct C14aCodeBreaker *s = GY;
    u8 mask = 0;
    u8 n = 0;
    u16 i, j;

    for (i = 0; i < s->symbols; i++)
    {
        for (j = 0; j < s->digits; j++)
        {
            if ((u8)(s->table[i][j].unk1 - 1) <= 1)
            {
                mask |= gUnknown_0879F05C[i];
                n++;
                break;
            }
        }
    }
    s->unk64 = mask;
    s->unk63 = n;
}

/* For the guess starting at board slot row: unk63 = how many of its symbols are still possible
   somewhere (each symbol counted once), unk64 = the positions holding them. */
// sub_0814CC38 @ 0x0814CC38
#ifdef NONMATCHING
void sub_0814CC38(u8 row)
{
    struct C14aCodeBreaker *s = GY;
    u8 n = 0;
    u8 posMask = 0;
    u8 symMask = 0;
    u16 i, j;

    for (i = 0; i < s->digits; i++)
    {
        for (j = 0; j < s->digits; j++)
        {
            if ((u8)(s->table[s->board[row + i].symbol][j].unk1 - 1) <= 1)
            {
                if (symMask & gUnknown_0879F05C[s->board[row + i].symbol])
                    break;
                symMask |= gUnknown_0879F05C[s->board[row + i].symbol];
                n++;
                posMask |= gUnknown_0879F05C[i];
            }
        }
    }
    s->unk63 = n;
    s->unk64 = posMask;
}
#else
NAKED
void sub_0814CC38(u8 row)
{
    asm_unified(
        ".L0814CC38:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #8\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    str r0, [sp]\n"
        "    ldr r0, .L0814CD00\n"
        "    mov sb, r0\n"
        "    movs r1, #0\n"
        "    str r1, [sp, #4]\n"
        "    mov r8, r1\n"
        "    mov ip, r1\n"
        "    movs r5, #0\n"
        "    mov r3, sb\n"
        "    adds r3, #0x2f\n"
        "    ldrb r2, [r3]\n"
        "    cmp r8, r2\n"
        "    bhs .L0814CCE0\n"
        ".L0814CC62:\n"
        "    ldr r1, [sp]\n"
        "    adds r0, r1, r5\n"
        "    lsls r0, r0, #2\n"
        "    add r0, sb\n"
        "    adds r2, r0, #0\n"
        "    adds r2, #0x78\n"
        "    ldrb r1, [r2]\n"
        "    movs r4, #0\n"
        "    adds r0, r5, #1\n"
        "    mov sl, r0\n"
        "    ldrb r3, [r3]\n"
        "    cmp r4, r3\n"
        "    bhs .L0814CCD2\n"
        "    lsls r0, r1, #2\n"
        "    adds r0, r0, r1\n"
        "    lsls r7, r0, #2\n"
        "    adds r6, r2, #0\n"
        "    ldr r2, .L0814CD04\n"
        "    ldr r1, .L0814CD08\n"
        "    ldrb r3, [r1]\n"
        ".L0814CC8A:\n"
        "    lsls r0, r4, #2\n"
        "    adds r0, r0, r7\n"
        "    add r0, sb\n"
        "    ldr r1, .L0814CD0C\n"
        "    adds r0, r0, r1\n"
        "    ldrb r0, [r0]\n"
        "    subs r0, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #1\n"
        "    bhi .L0814CCC8\n"
        "    ldrb r0, [r6]\n"
        "    adds r0, r0, r2\n"
        "    ldrb r1, [r0]\n"
        "    mov r0, ip\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L0814CCD2\n"
        "    mov r0, ip\n"
        "    orrs r0, r1\n"
        "    mov ip, r0\n"
        "    ldr r0, [sp, #4]\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    str r0, [sp, #4]\n"
        "    adds r0, r5, r2\n"
        "    ldrb r0, [r0]\n"
        "    mov r1, r8\n"
        "    orrs r1, r0\n"
        "    mov r8, r1\n"
        ".L0814CCC8:\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    cmp r4, r3\n"
        "    blo .L0814CC8A\n"
        ".L0814CCD2:\n"
        "    mov r2, sl\n"
        "    lsls r0, r2, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    ldr r3, .L0814CD08\n"
        "    ldrb r0, [r3]\n"
        "    cmp r5, r0\n"
        "    blo .L0814CC62\n"
        ".L0814CCE0:\n"
        "    mov r0, sb\n"
        "    adds r0, #0x63\n"
        "    mov r1, sp\n"
        "    ldrb r1, [r1, #4]\n"
        "    strb r1, [r0]\n"
        "    adds r0, #1\n"
        "    mov r2, r8\n"
        "    strb r2, [r0]\n"
        "    add sp, #8\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L0814CD00: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L0814CD04: .4byte gUnknown_0879F05C\n"
        ".L0814CD08: .4byte 0x0203A483 @ EWRAM+0x3A483\n"
        ".L0814CD0C: .4byte 0x0000016D\n"
    );
}
#endif

/* The symbols at the positions in mask of the guess starting at board slot row. */
// sub_0814CD10 @ 0x0814CD10
u8 sub_0814CD10(u8 mask, u8 row)
{
    struct C14aCodeBreaker *s = GY;
    u8 result = 0;
    u16 i;

    for (i = 0; i < s->digits; i++)
    {
        if (mask & 1)
        {
            mask >>= 1;
            mask |= 0x80;
            { u8 sym = s->board[row + i].symbol; result |= gUnknown_0879F05C[sym]; }
        }
        else
            mask >>= 1;
    }
    return result;
}

/* Compares two guesses: pairs equal symbols one to one and returns how many symbols of the
   first are left unpaired (also in unk60); unk61/unk71 = unpaired positions of the first,
   unk72 = unpaired positions of the second. */
// sub_0814CD70 @ 0x0814CD70
#ifdef NONMATCHING
u8 sub_0814CD70(u8 rowA, u8 rowB)
{
    struct C14aCodeBreaker *s = GY;
    u16 i, j;
    u8 usedA, usedB, n;

    for (i = 0; i < s->digits; i++)
    {
        s->guessA[i] = s->board[rowA + i].symbol;
        s->guessB[i] = s->board[rowB + i].symbol;
    }
    i = 0;
    usedA = 0;
    usedB = 0;
    n = 0;
    for (; i < s->digits; i++)
    {
        for (j = 0; j < s->digits; j++)
        {
            u8 m = gUnknown_0879F05C[j];
            m &= usedA;
            if (!m && s->guessB[i] == s->guessA[j])
            {
                usedA |= gUnknown_0879F05C[j];
                usedB |= gUnknown_0879F05C[i];
                n++;
                break;
            }
        }
    }
    s->unk61 = ~usedA;
    s->unk71 = ~usedA;
    s->unk72 = ~usedB;
    s->unk60 = s->digits - n;
    return s->unk60;
}
#else
NAKED
u8 sub_0814CD70(u8 rowA, u8 rowB)
{
    asm_unified(
        ".L0814CD70:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x18\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r5, r0, #0x18\n"
        "    lsls r1, r1, #0x18\n"
        "    lsrs r4, r1, #0x18\n"
        "    ldr r0, .L0814CE40\n"
        "    mov ip, r0\n"
        "    movs r2, #0\n"
        "    mov r3, ip\n"
        "    adds r3, #0x2f\n"
        "    ldrb r1, [r3]\n"
        "    cmp r2, r1\n"
        "    bhs .L0814CDC4\n"
        "    mov r7, ip\n"
        "    adds r7, #0x67\n"
        "    mov r6, ip\n"
        "    adds r6, #0x6c\n"
        ".L0814CD9C:\n"
        "    adds r1, r7, r2\n"
        "    adds r0, r5, r2\n"
        "    lsls r0, r0, #2\n"
        "    add r0, ip\n"
        "    adds r0, #0x78\n"
        "    ldrb r0, [r0]\n"
        "    strb r0, [r1]\n"
        "    adds r1, r6, r2\n"
        "    adds r0, r4, r2\n"
        "    lsls r0, r0, #2\n"
        "    add r0, ip\n"
        "    adds r0, #0x78\n"
        "    ldrb r0, [r0]\n"
        "    strb r0, [r1]\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    ldrb r0, [r3]\n"
        "    cmp r2, r0\n"
        "    blo .L0814CD9C\n"
        ".L0814CDC4:\n"
        "    movs r1, #0\n"
        "    mov sb, r1\n"
        "    movs r2, #0\n"
        "    str r2, [sp]\n"
        "    mov sl, r2\n"
        "    mov r0, ip\n"
        "    adds r0, #0x2f\n"
        "    adds r6, r0, #0\n"
        "    mov r2, ip\n"
        "    adds r2, #0x61\n"
        "    str r2, [sp, #0x14]\n"
        "    adds r2, #0x10\n"
        "    str r2, [sp, #4]\n"
        "    adds r2, #1\n"
        "    str r2, [sp, #8]\n"
        "    subs r2, #0x12\n"
        "    str r2, [sp, #0x10]\n"
        "    ldrb r2, [r0]\n"
        "    cmp sl, r2\n"
        "    bhs .L0814CE60\n"
        ".L0814CDEC:\n"
        "    movs r3, #0\n"
        "    adds r2, r1, #1\n"
        "    str r2, [sp, #0xc]\n"
        "    ldrb r0, [r0]\n"
        "    cmp r3, r0\n"
        "    bhs .L0814CE52\n"
        "    ldr r0, .L0814CE44\n"
        "    mov r8, r0\n"
        "    mov r0, ip\n"
        "    adds r0, #0x6c\n"
        "    adds r5, r0, r1\n"
        "    mov r2, r8\n"
        "    adds r7, r1, r2\n"
        "    ldrb r4, [r6]\n"
        ".L0814CE08:\n"
        "    mov r1, r8\n"
        "    adds r0, r3, r1\n"
        "    ldrb r2, [r0]\n"
        "    adds r0, r2, #0\n"
        "    mov r1, sb\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L0814CE48\n"
        "    mov r0, ip\n"
        "    adds r0, #0x67\n"
        "    adds r0, r0, r3\n"
        "    ldrb r1, [r5]\n"
        "    ldrb r0, [r0]\n"
        "    cmp r1, r0\n"
        "    bne .L0814CE48\n"
        "    mov r0, sb\n"
        "    orrs r0, r2\n"
        "    mov sb, r0\n"
        "    ldrb r0, [r7]\n"
        "    ldr r1, [sp]\n"
        "    orrs r1, r0\n"
        "    str r1, [sp]\n"
        "    mov r0, sl\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    mov sl, r0\n"
        "    b .L0814CE52\n"
        ".L0814CE40: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L0814CE44: .4byte gUnknown_0879F05C\n"
        ".L0814CE48:\n"
        "    adds r0, r3, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    cmp r3, r4\n"
        "    blo .L0814CE08\n"
        ".L0814CE52:\n"
        "    ldr r2, [sp, #0xc]\n"
        "    lsls r0, r2, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    adds r0, r6, #0\n"
        "    ldrb r2, [r6]\n"
        "    cmp r1, r2\n"
        "    blo .L0814CDEC\n"
        ".L0814CE60:\n"
        "    mov r1, sb\n"
        "    mvns r0, r1\n"
        "    ldr r2, [sp, #0x14]\n"
        "    strb r0, [r2]\n"
        "    ldr r1, [sp, #4]\n"
        "    strb r0, [r1]\n"
        "    ldr r2, [sp]\n"
        "    mvns r0, r2\n"
        "    ldr r1, [sp, #8]\n"
        "    strb r0, [r1]\n"
        "    ldrb r0, [r6]\n"
        "    mov r2, sl\n"
        "    subs r0, r0, r2\n"
        "    ldr r1, [sp, #0x10]\n"
        "    strb r0, [r1]\n"
        "    ldrb r0, [r1]\n"
        "    add sp, #0x18\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

// sub_0814CE90 @ 0x0814CE90
void sub_0814CE90(u8 mask, u8 value)
{
    sub_0814C624(mask, value);
}

// sub_0814CEA4 @ 0x0814CEA4
void sub_0814CEA4(u8 mask, u8 value)
{
    sub_0814C624(mask, value);
}

// sub_0814CEB8 @ 0x0814CEB8
void sub_0814CEB8(u8 mask, u8 value)
{
    sub_0814C624(mask, value);
}

/* Per symbol: a certain position excludes the others; a single possible position with all
   others excluded becomes certain. */
// sub_0814CECC @ 0x0814CECC
void sub_0814CECC(void)
{
    struct C14aCodeBreaker *s = GY;
    u8 lastI = 0, lastJ = 0;
    u16 i, j, k;
    u8 nOne, nNone;
    u8 v;

    for (i = 0; i < s->symbols; i++)
    {
        nOne = 0;
        nNone = 0;
        for (j = 0; j < s->digits; j++)
        {
            v = s->table[i][j].unk1;
            if (v == 0xFF)
                nNone++;
            else if (v == 1)
            {
                nOne++;
                lastI = i;
                lastJ = j;
            }
            else if (v == 2)
            {
                for (k = 0; k < s->digits; k++)
                {
                    if (s->table[i][k].unk1 != 2)
                        s->table[i][k].unk1 |= 0xFF;
                }
                break;
            }
        }
        if (j == s->digits && nNone == s->digits - 1 && nOne == 1)
            s->table[lastI][lastJ].unk1 = 2;
    }
}

/* unk73 = the symbols whose note at position pos equals value, unk74 = how many. */
// sub_0814CFDC @ 0x0814CFDC
#ifdef NONMATCHING
void sub_0814CFDC(u8 pos, u8 value)
{
    struct C14aCodeBreaker *s = GY;
    u8 mask = 0;
    u8 n = 0;
    u16 i;

    for (i = 0; i < s->symbols; i++)
    {
        if (s->table[i][pos].unk1 == value)
        {
            mask |= gUnknown_0879F05C[i];
            n++;
        }
    }
    s->unk73 = mask;
    s->unk74 = n;
}
#else
NAKED
void sub_0814CFDC(u8 pos, u8 value)
{
    asm_unified(
        ".L0814CFDC:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sb\n"
        "    mov r6, r8\n"
        "    push {r6, r7}\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    lsls r1, r1, #0x18\n"
        "    lsrs r1, r1, #0x18\n"
        "    mov sb, r1\n"
        "    ldr r5, .L0814D04C\n"
        "    movs r4, #0\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    adds r3, r5, #0\n"
        "    adds r3, #0x2e\n"
        "    ldrb r3, [r3]\n"
        "    cmp r1, r3\n"
        "    bhs .L0814D034\n"
        "    lsls r6, r0, #2\n"
        "    ldr r0, .L0814D050\n"
        "    mov r8, r0\n"
        "    ldr r7, .L0814D054\n"
        "    mov ip, r7\n"
        ".L0814D00A:\n"
        "    lsls r0, r2, #2\n"
        "    adds r0, r0, r2\n"
        "    lsls r0, r0, #2\n"
        "    adds r0, r6, r0\n"
        "    adds r0, r5, r0\n"
        "    add r0, ip\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, sb\n"
        "    bne .L0814D02A\n"
        "    mov r7, r8\n"
        "    adds r0, r2, r7\n"
        "    ldrb r0, [r0]\n"
        "    orrs r4, r0\n"
        "    adds r0, r1, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r1, r0, #0x18\n"
        ".L0814D02A:\n"
        "    adds r0, r2, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, r3\n"
        "    blo .L0814D00A\n"
        ".L0814D034:\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #0x73\n"
        "    strb r4, [r0]\n"
        "    adds r0, #1\n"
        "    strb r1, [r0]\n"
        "    pop {r3, r4}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L0814D04C: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L0814D050: .4byte gUnknown_0879F05C\n"
        ".L0814D054: .4byte 0x0000016D\n"
    );
}
#endif

/* Sets the note at position pos of the symbols in mask (unless excluded or certain). */
// sub_0814D058 @ 0x0814D058
void sub_0814D058(u8 mask, u8 pos, u8 value)
{
    u8 t;
    struct C14aCodeBreaker *s = GY;
    u16 i;

    for (i = 0; i < s->symbols; i++)
    {
        if (mask & 1)
        {
            mask >>= 1;
            mask |= 0x80;
            t = s->table[i][pos].unk1;
            if (t != 0xFF && t != 2)
                s->table[i][pos].unk1 = value;
        }
        else
            mask >>= 1;
    }
}

/* Per position: if every symbol but one is excluded there, that one is certain; a certain
   symbol excludes the others. */
// sub_0814D0C4 @ 0x0814D0C4
void sub_0814D0C4(void)
{
    struct C14aCodeBreaker *s = GY;
    u8 i;

    for (i = 0; i < s->digits; i++)
    {
        sub_0814CFDC(i, 0xFF);
        if (s->unk74 == s->symbols - 1)
            sub_0814D058(~s->unk73, i, 2);
    }
    for (i = 0; i < s->digits; i++)
    {
        sub_0814CFDC(i, 2);
        if (s->unk74 != 0)
            sub_0814D058(~s->unk73, i, 0xFF);
    }
}

/* Updates the deduction notes after a row was scored (A pressed). */
// CodeBreaker_UpdateNotes @ 0x0814D150
#ifdef NONMATCHING
void CodeBreaker_UpdateNotes(void)
{
    struct C14aCodeBreaker *s = GY;
    u8 cur, n;
    s16 k;

    s->rowTotal[(u8)(s->row / 5)] = s->unk43 + s->unk42;
    sub_0814C580();
    cur = s->row / 5;
    if (s->rowCount[cur] == s->digits)
    {
        if (s->rowTotal[cur] == s->digits)
        {
            sub_0814C6C4(1);
            sub_0814C6F4(0xFF);
        }
        else if (s->level == 2 ? s->rowTotal[cur] == 2 : s->rowTotal[cur] == 1)
        {
            sub_0814C6F4(1);
        }
    }
    else
    {
        if (s->rowTotal[cur] == s->digits)
            sub_0814C6C4(1);
        else if (s->rowTotal[cur] == 0)
            sub_0814C6C4(0xFF);
        else if (s->level == 2 && s->rowCount[cur] - s->rowTotal[cur] == 3)
            sub_0814C6F4(1);
        if (s->rowCount[(u8)(s->row / 5)] == s->unk42)
        {
            sub_0814C7A8(1);
            sub_0814C878(0xFF);
        }
    }
    if (s->unk43 == 0)
    {
        if (s->unk42 != 0)
        {
            sub_0814C878(0xFF);
            if (s->rowCount[(u8)(s->row / 5)] != s->digits)
            {
                sub_0814C948();
                sub_0814CA18(0xFF);
            }
        }
    }
    if (s->unk43 != 0 && s->unk42 == 0)
        sub_0814C7A8(0xFF);

    cur = s->row / 5;
    if (cur != 0)
    {
        s->tot[0] = s->rowTotal[cur];
        if (s->row != 0)
            s->prevRow = s->row - 5;
        /* compare the current row with every earlier one */
        for (k = (u8)(s->row / 5) - 1; k >= 0; k--)
        {
            sub_0814CC38(s->row);
            if (s->unk63 == s->rowTotal[(u8)(s->row / 5)])
                sub_0814CA34(~sub_0814CD10(s->unk64, s->row) & s->rowMask[(u8)(s->row / 5)], 0xFF);
            sub_0814CC38(s->prevRow);
            if (s->unk63 == s->rowTotal[k])
                sub_0814CA34(s->rowMask[k] & ~sub_0814CD10(s->unk64, s->prevRow), 0xFF);
            s->tot[1] = s->rowTotal[k];
            sub_0814CD70(s->row, s->prevRow);
            if (s->tot[0] - s->tot[1] == s->unk60)
            {
                sub_0814CE90(sub_0814CD10(s->unk71, s->row), 1);
                sub_0814CEA4(sub_0814CD10(s->unk72, s->prevRow), 0xFF);
            }
            if (s->tot[1] - s->tot[0] == s->unk60)
            {
                sub_0814CE90(sub_0814CD10(s->unk71, s->row), 0xFF);
                sub_0814CEA4(sub_0814CD10(s->unk72, s->prevRow), 1);
            }
            if (s->rowCount[(u8)(s->row / 5)] == s->digits && s->rowCount[k] == s->rowCount[(u8)(s->row / 5)]
                && s->level != 0)
            {
                if (s->level == 1)
                {
                    if (s->unk60 == 2 && *(u16 *)s->tot == 0x303)
                    {
                        sub_0814CEB8(sub_0814CD10(~s->unk61, s->row), 1);
                        sub_0814CA34(~(s->rowMask[(u8)(s->row / 5)] | s->rowMask[k]), 0xFF);
                    }
                    if (s->unk60 == 3)
                    {
                        if (*(u16 *)s->tot == 0x202)
                            sub_0814CEB8(sub_0814CD10(~s->unk61, s->row), 0xFF);
                        if (s->unk60 == 3 && *(u16 *)s->tot == 0x203)
                            sub_0814CEB8(sub_0814CD10(~s->unk61, s->row), 1);
                    }
                }
                else
                {
                    if (s->unk60 == 3
                        && ((s->rowTotal[(u8)(s->row / 5)] == 3 && s->rowTotal[k] == 4)
                            || (s->rowTotal[(u8)(s->row / 5)] == 4 && s->rowTotal[k] == 3)))
                        sub_0814CEB8(sub_0814CD10(~s->unk61, s->row), 1);
                    if (s->unk60 == 2 && *(u16 *)s->tot == 0x404)
                    {
                        sub_0814CEB8(sub_0814CD10(~s->unk61, s->row), 1);
                        sub_0814CA34(~(s->rowMask[(u8)(s->row / 5)] | s->rowMask[k]), 0xFF);
                    }
                }
            }
            s->prevRow -= 5;
        }
        sub_0814CB90();
        if (s->unk63 == s->digits)
            sub_0814CA34(~s->unk64, 0xFF);
        sub_0814CAD4();
        if (s->unk65 == s->symbols - s->digits)
            sub_0814CA34(~s->unk66, 1);
    }
    n = 0;
    do
    {
        sub_0814CECC();
        sub_0814D0C4();
    } while (++n < 3);
}
#else
NAKED
void CodeBreaker_UpdateNotes(void)
{
    asm_unified(
        ".L0814D150:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x24\n"
        "    ldr r6, .L0814D1C0\n"
        "    adds r4, r6, #0\n"
        "    adds r4, #0x2b\n"
        "    ldrb r0, [r4]\n"
        "    movs r1, #5\n"
        "    bl __udivsi3\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    adds r5, r6, #0\n"
        "    adds r5, #0x48\n"
        "    adds r0, r0, r5\n"
        "    adds r7, r6, #0\n"
        "    adds r7, #0x42\n"
        "    adds r1, r6, #0\n"
        "    adds r1, #0x43\n"
        "    ldrb r1, [r1]\n"
        "    ldrb r2, [r7]\n"
        "    adds r1, r1, r2\n"
        "    strb r1, [r0]\n"
        "    bl sub_0814C580\n"
        "    ldrb r0, [r4]\n"
        "    movs r1, #5\n"
        "    bl __udivsi3\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r2, r0, #0x18\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x50\n"
        "    adds r3, r2, r0\n"
        "    adds r1, r6, #0\n"
        "    adds r1, #0x2f\n"
        "    ldrb r0, [r3]\n"
        "    ldrb r1, [r1]\n"
        "    cmp r0, r1\n"
        "    bne .L0814D1E0\n"
        "    adds r0, r2, r5\n"
        "    ldrb r2, [r0]\n"
        "    cmp r2, r1\n"
        "    bne .L0814D1C4\n"
        "    movs r0, #1\n"
        "    bl sub_0814C6C4\n"
        "    movs r0, #0xff\n"
        "    bl sub_0814C6F4\n"
        "    str r4, [sp, #0xc]\n"
        "    b .L0814D244\n"
        "    .byte 0x00, 0x00\n"
        ".L0814D1C0: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L0814D1C4:\n"
        "    ldrb r0, [r6, #5]\n"
        "    cmp r0, #2\n"
        "    beq .L0814D1D2\n"
        "    str r4, [sp, #0xc]\n"
        "    cmp r2, #1\n"
        "    bne .L0814D244\n"
        "    b .L0814D1D8\n"
        ".L0814D1D2:\n"
        "    str r4, [sp, #0xc]\n"
        "    cmp r2, #2\n"
        "    bne .L0814D244\n"
        ".L0814D1D8:\n"
        "    movs r0, #1\n"
        "    bl sub_0814C6F4\n"
        "    b .L0814D244\n"
        ".L0814D1E0:\n"
        "    adds r2, r2, r5\n"
        "    ldrb r0, [r2]\n"
        "    cmp r0, r1\n"
        "    bne .L0814D1F0\n"
        "    movs r0, #1\n"
        "    bl sub_0814C6C4\n"
        "    b .L0814D212\n"
        ".L0814D1F0:\n"
        "    cmp r0, #0\n"
        "    bne .L0814D1FC\n"
        "    movs r0, #0xff\n"
        "    bl sub_0814C6C4\n"
        "    b .L0814D212\n"
        ".L0814D1FC:\n"
        "    ldrb r0, [r6, #5]\n"
        "    cmp r0, #2\n"
        "    bne .L0814D212\n"
        "    ldrb r0, [r3]\n"
        "    ldrb r1, [r2]\n"
        "    subs r0, r0, r1\n"
        "    cmp r0, #3\n"
        "    bne .L0814D212\n"
        "    movs r0, #1\n"
        "    bl sub_0814C6F4\n"
        ".L0814D212:\n"
        "    adds r4, r6, #0\n"
        "    adds r4, #0x2b\n"
        "    ldrb r0, [r4]\n"
        "    movs r1, #5\n"
        "    bl __udivsi3\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    adds r1, r6, #0\n"
        "    adds r1, #0x50\n"
        "    adds r1, r1, r0\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x42\n"
        "    ldrb r1, [r1]\n"
        "    str r4, [sp, #0xc]\n"
        "    adds r7, r0, #0\n"
        "    ldrb r3, [r7]\n"
        "    cmp r1, r3\n"
        "    bne .L0814D244\n"
        "    movs r0, #1\n"
        "    bl sub_0814C7A8\n"
        "    movs r0, #0xff\n"
        "    bl sub_0814C878\n"
        ".L0814D244:\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x43\n"
        "    ldrb r1, [r0]\n"
        "    adds r5, r0, #0\n"
        "    cmp r1, #0\n"
        "    bne .L0814D28C\n"
        "    ldrb r0, [r7]\n"
        "    cmp r0, #0\n"
        "    beq .L0814D286\n"
        "    movs r0, #0xff\n"
        "    bl sub_0814C878\n"
        "    ldr r4, [sp, #0xc]\n"
        "    ldrb r0, [r4]\n"
        "    movs r1, #5\n"
        "    bl __udivsi3\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    adds r1, r6, #0\n"
        "    adds r1, #0x50\n"
        "    adds r1, r1, r0\n"
        "    adds r2, r6, #0\n"
        "    adds r2, #0x2f\n"
        "    ldrb r0, [r1]\n"
        "    ldrb r2, [r2]\n"
        "    cmp r0, r2\n"
        "    beq .L0814D286\n"
        "    bl sub_0814C948\n"
        "    movs r0, #0xff\n"
        "    bl sub_0814CA18\n"
        ".L0814D286:\n"
        "    ldrb r0, [r5]\n"
        "    cmp r0, #0\n"
        "    beq .L0814D298\n"
        ".L0814D28C:\n"
        "    ldrb r0, [r7]\n"
        "    cmp r0, #0\n"
        "    bne .L0814D298\n"
        "    movs r0, #0xff\n"
        "    bl sub_0814C7A8\n"
        ".L0814D298:\n"
        "    ldr r1, [sp, #0xc]\n"
        "    ldrb r0, [r1]\n"
        "    movs r1, #5\n"
        "    bl __udivsi3\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    cmp r0, #0\n"
        "    bne .L0814D2AC\n"
        "    b .L0814D65C\n"
        ".L0814D2AC:\n"
        "    adds r5, r6, #0\n"
        "    adds r5, #0x48\n"
        "    adds r0, r5, r0\n"
        "    ldrb r0, [r0]\n"
        "    adds r1, r6, #0\n"
        "    adds r1, #0x46\n"
        "    strb r0, [r1]\n"
        "    ldr r2, [sp, #0xc]\n"
        "    ldrb r0, [r2]\n"
        "    str r1, [sp, #0x18]\n"
        "    cmp r0, #0\n"
        "    beq .L0814D2CA\n"
        "    ldrb r0, [r2]\n"
        "    subs r0, #5\n"
        "    strh r0, [r6, #0x2c]\n"
        ".L0814D2CA:\n"
        "    ldr r3, [sp, #0xc]\n"
        "    ldrb r0, [r3]\n"
        "    movs r1, #5\n"
        "    bl __udivsi3\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #8\n"
        "    ldr r4, .L0814D548\n"
        "    adds r0, r0, r4\n"
        "    lsrs r7, r0, #0x10\n"
        "    adds r1, r6, #0\n"
        "    adds r1, #0x2f\n"
        "    str r1, [sp, #0x14]\n"
        "    adds r2, r6, #0\n"
        "    adds r2, #0x63\n"
        "    str r2, [sp, #0x1c]\n"
        "    adds r3, r6, #0\n"
        "    adds r3, #0x65\n"
        "    str r3, [sp, #0x20]\n"
        "    adds r4, r6, #0\n"
        "    adds r4, #0x2e\n"
        "    str r4, [sp, #0x10]\n"
        "    cmp r0, #0\n"
        "    bge .L0814D2FC\n"
        "    b .L0814D612\n"
        ".L0814D2FC:\n"
        "    ldr r0, [sp, #0xc]\n"
        "    mov sb, r0\n"
        "    str r2, [sp]\n"
        "    str r5, [sp, #4]\n"
        ".L0814D304:\n"
        "    mov r1, sb\n"
        "    ldrb r0, [r1]\n"
        "    bl sub_0814CC38\n"
        "    mov r2, sb\n"
        "    ldrb r5, [r2]\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #5\n"
        "    bl __udivsi3\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    ldr r3, [sp, #4]\n"
        "    adds r0, r3, r0\n"
        "    ldr r4, [sp]\n"
        "    ldrb r1, [r4]\n"
        "    ldrb r0, [r0]\n"
        "    cmp r1, r0\n"
        "    bne .L0814D360\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x64\n"
        "    ldrb r0, [r0]\n"
        "    adds r1, r5, #0\n"
        "    bl sub_0814CD10\n"
        "    lsls r0, r0, #0x18\n"
        "    movs r1, #0xff\n"
        "    lsls r1, r1, #0x18\n"
        "    eors r0, r1\n"
        "    lsrs r4, r0, #0x18\n"
        "    ldr r1, [sp, #0xc]\n"
        "    ldrb r0, [r1]\n"
        "    movs r1, #5\n"
        "    bl __udivsi3\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    adds r1, r6, #0\n"
        "    adds r1, #0x58\n"
        "    adds r1, r1, r0\n"
        "    ldrb r0, [r1]\n"
        "    ands r4, r0\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0xff\n"
        "    bl sub_0814CA34\n"
        ".L0814D360:\n"
        "    ldrh r0, [r6, #0x2c]\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    bl sub_0814CC38\n"
        "    lsls r1, r7, #0x10\n"
        "    asrs r2, r1, #0x10\n"
        "    mov sl, r2\n"
        "    ldr r3, [sp, #4]\n"
        "    add r3, sl\n"
        "    mov r8, r3\n"
        "    ldr r4, [sp]\n"
        "    ldrb r0, [r4]\n"
        "    str r1, [sp, #8]\n"
        "    ldrb r1, [r3]\n"
        "    cmp r0, r1\n"
        "    bne .L0814D3AA\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x64\n"
        "    ldrb r0, [r0]\n"
        "    ldrh r1, [r6, #0x2c]\n"
        "    lsls r1, r1, #0x18\n"
        "    lsrs r1, r1, #0x18\n"
        "    bl sub_0814CD10\n"
        "    lsls r0, r0, #0x18\n"
        "    adds r1, r6, #0\n"
        "    adds r1, #0x58\n"
        "    add r1, sl\n"
        "    ldrb r1, [r1]\n"
        "    lsrs r0, r0, #0x18\n"
        "    adds r2, r1, #0\n"
        "    bics r2, r0\n"
        "    adds r0, r2, #0\n"
        "    movs r1, #0xff\n"
        "    bl sub_0814CA34\n"
        ".L0814D3AA:\n"
        "    mov r3, r8\n"
        "    ldrb r0, [r3]\n"
        "    adds r5, r6, #0\n"
        "    adds r5, #0x47\n"
        "    strb r0, [r5]\n"
        "    mov r4, sb\n"
        "    ldrb r0, [r4]\n"
        "    ldrh r1, [r6, #0x2c]\n"
        "    lsls r1, r1, #0x18\n"
        "    lsrs r1, r1, #0x18\n"
        "    bl sub_0814CD70\n"
        "    ldr r0, [sp, #0x18]\n"
        "    ldrb r1, [r0]\n"
        "    ldrb r0, [r5]\n"
        "    subs r1, r1, r0\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x60\n"
        "    adds r7, r0, #0\n"
        "    ldrb r2, [r7]\n"
        "    cmp r1, r2\n"
        "    bne .L0814D408\n"
        "    adds r0, #0x11\n"
        "    ldrb r0, [r0]\n"
        "    ldrb r1, [r4]\n"
        "    bl sub_0814CD10\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #1\n"
        "    bl sub_0814CE90\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x72\n"
        "    ldrb r0, [r0]\n"
        "    ldrh r1, [r6, #0x2c]\n"
        "    lsls r1, r1, #0x18\n"
        "    lsrs r1, r1, #0x18\n"
        "    bl sub_0814CD10\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0xff\n"
        "    bl sub_0814CEA4\n"
        ".L0814D408:\n"
        "    ldrb r0, [r5]\n"
        "    ldr r3, [sp, #0x18]\n"
        "    ldrb r1, [r3]\n"
        "    subs r0, r0, r1\n"
        "    ldrb r4, [r7]\n"
        "    cmp r0, r4\n"
        "    bne .L0814D44C\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x71\n"
        "    ldrb r0, [r0]\n"
        "    mov r2, sb\n"
        "    ldrb r1, [r2]\n"
        "    bl sub_0814CD10\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0xff\n"
        "    bl sub_0814CE90\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x72\n"
        "    ldrb r0, [r0]\n"
        "    ldrh r1, [r6, #0x2c]\n"
        "    lsls r1, r1, #0x18\n"
        "    lsrs r1, r1, #0x18\n"
        "    bl sub_0814CD10\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #1\n"
        "    bl sub_0814CEA4\n"
        ".L0814D44C:\n"
        "    mov r3, sb\n"
        "    ldrb r5, [r3]\n"
        "    adds r0, r5, #0\n"
        "    movs r1, #5\n"
        "    bl __udivsi3\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r3, r0, #0x18\n"
        "    adds r2, r6, #0\n"
        "    adds r2, #0x50\n"
        "    adds r0, r2, r3\n"
        "    ldrb r1, [r0]\n"
        "    ldr r4, [sp, #0x14]\n"
        "    ldrb r4, [r4]\n"
        "    cmp r1, r4\n"
        "    beq .L0814D46E\n"
        "    b .L0814D5FE\n"
        ".L0814D46E:\n"
        "    mov r4, sl\n"
        "    adds r0, r2, r4\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, r1\n"
        "    beq .L0814D47A\n"
        "    b .L0814D5FE\n"
        ".L0814D47A:\n"
        "    ldrb r0, [r6, #5]\n"
        "    cmp r0, #0\n"
        "    bne .L0814D482\n"
        "    b .L0814D5FE\n"
        ".L0814D482:\n"
        "    cmp r0, #1\n"
        "    bne .L0814D55C\n"
        "    ldrb r0, [r7]\n"
        "    cmp r0, #2\n"
        "    bne .L0814D4DE\n"
        "    ldr r0, [sp, #0x18]\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L0814D54C\n"
        "    cmp r1, r0\n"
        "    bne .L0814D4DE\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x61\n"
        "    ldrb r0, [r0]\n"
        "    mvns r0, r0\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    adds r1, r5, #0\n"
        "    bl sub_0814CD10\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #1\n"
        "    bl sub_0814CEB8\n"
        "    mov r1, sb\n"
        "    ldrb r0, [r1]\n"
        "    movs r1, #5\n"
        "    bl __udivsi3\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    adds r1, r6, #0\n"
        "    adds r1, #0x58\n"
        "    adds r0, r1, r0\n"
        "    add r1, sl\n"
        "    ldrb r0, [r0]\n"
        "    ldrb r1, [r1]\n"
        "    orrs r0, r1\n"
        "    mvns r0, r0\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0xff\n"
        "    bl sub_0814CA34\n"
        ".L0814D4DE:\n"
        "    ldrb r0, [r7]\n"
        "    cmp r0, #3\n"
        "    beq .L0814D4E6\n"
        "    b .L0814D5FE\n"
        ".L0814D4E6:\n"
        "    ldr r5, .L0814D550\n"
        "    ldr r2, [sp, #0x18]\n"
        "    ldrh r1, [r2]\n"
        "    ldr r0, .L0814D554\n"
        "    cmp r1, r0\n"
        "    bne .L0814D512\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x61\n"
        "    ldrb r0, [r0]\n"
        "    mvns r0, r0\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    ldr r3, [sp, #0xc]\n"
        "    ldrb r1, [r3]\n"
        "    bl sub_0814CD10\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0xff\n"
        "    bl sub_0814CEB8\n"
        ".L0814D512:\n"
        "    ldrb r0, [r7]\n"
        "    cmp r0, #3\n"
        "    bne .L0814D5FE\n"
        "    ldr r4, [sp, #0x18]\n"
        "    ldrh r0, [r4]\n"
        "    ands r5, r0\n"
        "    ldr r0, .L0814D558\n"
        "    cmp r5, r0\n"
        "    bne .L0814D5FE\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x61\n"
        "    ldrb r0, [r0]\n"
        "    mvns r0, r0\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    ldr r2, [sp, #0xc]\n"
        "    ldrb r1, [r2]\n"
        "    bl sub_0814CD10\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #1\n"
        "    bl sub_0814CEB8\n"
        "    b .L0814D5FE\n"
        "    .byte 0x00, 0x00\n"
        ".L0814D548: .4byte 0xFFFF0000\n"
        ".L0814D54C: .4byte 0x00000303\n"
        ".L0814D550: .4byte 0x0000FFFF\n"
        ".L0814D554: .4byte 0x00000202\n"
        ".L0814D558: .4byte 0x00000203\n"
        ".L0814D55C:\n"
        "    ldrb r0, [r7]\n"
        "    cmp r0, #3\n"
        "    bne .L0814D5A0\n"
        "    ldr r4, [sp, #4]\n"
        "    adds r0, r4, r3\n"
        "    ldrb r1, [r0]\n"
        "    cmp r1, #3\n"
        "    bne .L0814D574\n"
        "    mov r2, r8\n"
        "    ldrb r0, [r2]\n"
        "    cmp r0, #4\n"
        "    beq .L0814D580\n"
        ".L0814D574:\n"
        "    cmp r1, #4\n"
        "    bne .L0814D5A0\n"
        "    mov r3, r8\n"
        "    ldrb r0, [r3]\n"
        "    cmp r0, #3\n"
        "    bne .L0814D5A0\n"
        ".L0814D580:\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x61\n"
        "    ldrb r0, [r0]\n"
        "    mvns r0, r0\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    ldr r4, [sp, #0xc]\n"
        "    ldrb r1, [r4]\n"
        "    bl sub_0814CD10\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #1\n"
        "    bl sub_0814CEB8\n"
        ".L0814D5A0:\n"
        "    ldrb r0, [r7]\n"
        "    cmp r0, #2\n"
        "    bne .L0814D5FE\n"
        "    ldr r0, [sp, #0x18]\n"
        "    ldrh r1, [r0]\n"
        "    ldr r0, .L0814D680\n"
        "    cmp r1, r0\n"
        "    bne .L0814D5FE\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x61\n"
        "    ldrb r0, [r0]\n"
        "    mvns r0, r0\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    mov r2, sb\n"
        "    ldrb r1, [r2]\n"
        "    bl sub_0814CD10\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #1\n"
        "    bl sub_0814CEB8\n"
        "    mov r3, sb\n"
        "    ldrb r0, [r3]\n"
        "    movs r1, #5\n"
        "    bl __udivsi3\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    adds r2, r6, #0\n"
        "    adds r2, #0x58\n"
        "    adds r0, r2, r0\n"
        "    ldr r4, [sp, #8]\n"
        "    asrs r1, r4, #0x10\n"
        "    adds r2, r2, r1\n"
        "    ldrb r0, [r0]\n"
        "    ldrb r1, [r2]\n"
        "    orrs r0, r1\n"
        "    mvns r0, r0\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0xff\n"
        "    bl sub_0814CA34\n"
        ".L0814D5FE:\n"
        "    ldrh r0, [r6, #0x2c]\n"
        "    subs r0, #5\n"
        "    strh r0, [r6, #0x2c]\n"
        "    ldr r1, [sp, #8]\n"
        "    ldr r2, .L0814D684\n"
        "    adds r0, r1, r2\n"
        "    lsrs r7, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    blt .L0814D612\n"
        "    b .L0814D304\n"
        ".L0814D612:\n"
        "    bl sub_0814CB90\n"
        "    ldr r3, [sp, #0x1c]\n"
        "    ldrb r0, [r3]\n"
        "    ldr r4, [sp, #0x14]\n"
        "    ldrb r4, [r4]\n"
        "    cmp r0, r4\n"
        "    bne .L0814D634\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x64\n"
        "    ldrb r0, [r0]\n"
        "    mvns r0, r0\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    movs r1, #0xff\n"
        "    bl sub_0814CA34\n"
        ".L0814D634:\n"
        "    bl sub_0814CAD4\n"
        "    ldr r1, [sp, #0x20]\n"
        "    ldrb r0, [r1]\n"
        "    ldr r2, [sp, #0x10]\n"
        "    ldrb r1, [r2]\n"
        "    ldr r3, [sp, #0x14]\n"
        "    ldrb r2, [r3]\n"
        "    subs r1, r1, r2\n"
        "    cmp r0, r1\n"
        "    bne .L0814D65C\n"
        "    adds r0, r6, #0\n"
        "    adds r0, #0x66\n"
        "    ldrb r0, [r0]\n"
        "    mvns r0, r0\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    movs r1, #1\n"
        "    bl sub_0814CA34\n"
        ".L0814D65C:\n"
        "    movs r4, #0\n"
        ".L0814D65E:\n"
        "    bl sub_0814CECC\n"
        "    bl sub_0814D0C4\n"
        "    adds r0, r4, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r4, r0, #0x18\n"
        "    cmp r4, #2\n"
        "    bls .L0814D65E\n"
        "    add sp, #0x24\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L0814D680: .4byte 0x00000404\n"
        ".L0814D684: .4byte 0xFFFF0000\n"
    );
}
#endif
