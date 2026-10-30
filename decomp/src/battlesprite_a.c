/* Battle enemy sprites. */

#include "global.h"
#include "battledisp.h"

// sub_080E7D58 @ 0x080E7D58
/* Draws the enemy group sprites while any of their units is alive (or still has an icon
   shown). */
void sub_080E7D58(void)
{
    struct C15cBattle *b = BB;
    struct C15cDemonSprite *s;
    struct C15cIcon *e;
    s16 x;
    u16 y;
    u16 dead;
    u8 i;
    u8 n;

    if (!Battle_IsTwoSided())
    {
        for (n = 0, i = 0; i < 8; i++)
        {
            dead = Combatant_IsDead(i + 16);
            if ((s16)dead == 1 && (e = &b->icons[i])->shown != 0)
                dead = 0;
            if (!dead && Combatant_IsUsed(i + 16))
                n++;
        }
        if (n == 0)
            return;
        if (!sub_080E8738(0))
            return;
        s = &b->sprites[0];
        if (s->x != 0x7FFF)
            x = s->x;
        else
            x = s->unk6 + 0x78;
        if (s->y != 0x7FFF)
            y = s->y;
        else
            y = s->unk7 + 0x56;
        sub_080AA514(s->def, s->unk11, 0xE, s->unk10, 0x300, x + b->unk118C, y - b->unk119E,
                     sub_080E7D30(b->groups[0]));
    }
    else
    {
        for (n = 0, i = 0; i < 4; i++)
        {
            dead = Combatant_IsDead(i + 16);
            if ((s16)dead == 1 && (e = &b->icons[i])->shown != 0)
                dead = 0;
            if (!dead && Combatant_IsUsed(i + 16))
                n++;
        }
        if (n != 0 && sub_080E8738(0))
        {
            s = &b->sprites[0];
            if (s->x != 0x7FFF)
                x = s->x;
            else
                x = s->unk6 + 0x50;
            if (s->y != 0x7FFF)
                y = s->y;
            else
                y = s->unk7 + 0x56;
            sub_080AA514(s->def, s->unk11, 0xE, s->unk10, 0x300, x + b->unk118C, y - b->unk119E,
                         sub_080E7D30(b->groups[0]));
        }
        for (i = 4, n = 0; i < 8; i++)
        {
            dead = Combatant_IsDead(i + 16);
            if ((s16)dead == 1 && (e = &b->icons[i])->shown != 0)
                dead = 0;
            if (!dead && Combatant_IsUsed(i + 16))
                n++;
        }
        if (n == 0)
            return;
        if (!sub_080E8738(1))
            return;
        s = &b->sprites[1];
        if (s->x != 0x7FFF)
            x = s->x;
        else
            x = s->unk6 + 0xA1;
        if (s->y != 0x7FFF)
            y = s->y;
        else
            y = s->unk7 + 0x56;
        /* Original bug: groups[2] reads counts[0], not the second group's demon id. */
        sub_080AA514(s->def, s->unk11, 0xF, s->unk10, 0x380, x - b->unk118C, y - b->unk119E,
                     sub_080E7D30(b->groups[2]));
    }
}

// sub_080E8034 @ 0x080E8034
/* Draws the (left) enemy group sprite; demon 0x12E is drawn with a pulsing blend. */
void sub_080E8034(void)
{
    struct C15cBattle *b = BB;
    struct C15cDemonSprite *s;
    struct C15cIcon *e;
    s16 x;
    u16 y;
    u16 dead;
    u8 i;
    u8 n;

    if (!Battle_IsTwoSided())
    {
        for (n = 0, i = 0; i < 8; i++)
        {
            dead = Combatant_IsDead(i + 16);
            if ((s16)dead == 1 && (e = &b->icons[i])->shown != 0)
                dead = 0;
            if (!dead && Combatant_IsUsed(i + 16))
                n++;
        }
        if (b->unkF6A != 0 && n == 0)
            n = 1;
        if (n == 0)
            return;
        if (!sub_080E8738(0))
            return;
        s = &b->sprites[0];
        if (s->x != 0x7FFF)
            x = s->x + s->unk6;
        else
            x = s->unk6 + 0x78;
        if (s->y != 0x7FFF)
            y = s->y + s->unk7;
        else
            y = s->unk7 + 0x56;
        if (b->groups[0] == 0x12E)
        {
            sub_080AA514(s->def, s->unk11, 0xE, s->unk10, 0x300, x + b->unk118C - 0x8000U,
                         y - b->unk119E, sub_080E7D30(b->groups[0]));
            if ((gFrameCounter & 7) == 0)
            {
                if (b->unk11A6 == 0)
                {
                    if ((gUnk_0300003D += 16) > 0x20)
                        b->unk11A6 = 1;
                }
                else
                {
                    if ((gUnk_0300003D -= 16) == 0)
                        b->unk11A6 = 0;
                }
            }
        }
        else
        {
            sub_080AA514(s->def, s->unk11, 0xE, s->unk10, 0x300, x + b->unk118C, y - b->unk119E,
                         sub_080E7D30(b->groups[0]));
        }
    }
    else
    {
        for (n = 0, i = 0; i < 4; i++)
        {
            dead = Combatant_IsDead(i + 16);
            if ((s16)dead == 1 && (e = &b->icons[i])->shown != 0)
                dead = 0;
            if (!dead && Combatant_IsUsed(i + 16))
                n++;
        }
        if (b->groups[0] == 0x110 && !sub_080EDA24(0))
            n = 0;
        if (n == 0)
            return;
        if (!sub_080E8738(0))
            return;
        s = &b->sprites[0];
        if (s->x != 0x7FFF)
            x = s->x + s->unk6;
        else
            x = s->unk6 + 0x50;
        if (s->y != 0x7FFF)
            y = s->y + s->unk7;
        else
            y = s->unk7 + 0x56;
        sub_080AA514(s->def, s->unk11, 0xE, s->unk10, 0x300, x + b->unk118C, y - b->unk119E,
                     sub_080E7D30(b->groups[0]));
    }
}

// sub_080E832C @ 0x080E832C
/* Draws the right enemy group sprite (two-sided battles). */
void sub_080E832C(void)
{
    struct C15cBattle *b = BB;
    struct C15cDemonSprite *s;
    struct C15cIcon *e;
    u16 x;
    u16 y;
    u16 dead;
    u8 i;
    u8 n;

    for (i = 4, n = 0; i < 8; i++)
    {
        dead = Combatant_IsDead(i + 16);
        if ((s16)dead == 1 && (e = &b->icons[i])->shown != 0)
            dead = 0;
        if (!dead && Combatant_IsUsed(i + 16))
            n++;
    }
    if (b->groups[1] == 0x10F && !sub_080EDA24(1))
        n = 0;
    if (n == 0)
        return;
    if (!sub_080E8738(1))
        return;
    s = &b->sprites[1];
    if (s->x != 0x7FFF)
        x = s->x + s->unk6;
    else
        x = s->unk6 + 0xA1;
    if (s->y != 0x7FFF)
        y = s->y + s->unk7;
    else
        y = s->unk7 + 0x56;
    sub_080AA514(s->def, s->unk11, 0xF, s->unk10, 0x380, x - b->unk118C, y - b->unk119E,
                 sub_080E7D30(b->groups[1]));
}

// sub_080E845C @ 0x080E845C
void sub_080E845C(u8 slot, s8 dx, s8 dy)
{
    struct C15cBattle *b = BB;
    struct C15cDemonSprite *s = &b->sprites[slot];

    s->unk6 = dx;
    s->unk7 = dy;
}

// sub_080E847C @ 0x080E847C
/* Steps a palette pulse and writes the tinted colours. */
#ifdef NONMATCHING
void sub_080E847C(struct C15cPulse *p)
{
    u16 c;
    u16 rr;
    u16 gg;
    u16 bb;
    u8 i;

    if ((u16)PalFade_AllDone() != 1 || Palette_IsBg13Black() == 1)
        return;
    if (p->dir == 1)
    {
        p->level++;
        if (p->level == p->max)
            p->dir = 1 - p->dir;
    }
    else
    {
        if (--p->level == 0)
            p->dir = 1 - p->dir;
    }
    for (i = 0; i < 16; i++)
    {
        rr = p->r * p->level + 0xC0;
        c = p->src[i];
        rr = (c & 0x1F) * rr;
        if (rr > 0x1F00)
            rr = 0x1F00;
        rr >>= 8;
        gg = p->g * p->level + 0xC0;
        {
            u32 m = 0x3E0;

            m &= c;
            gg = (m >> 5) * gg;
        }
        if (gg > 0x1F00)
            gg = 0x3E0;
        else
            gg = (gg & 0x1F00) >> 3;
        bb = p->b * p->level + 0xC0;
        bb = ((p->src[i] & 0x7C00) >> 10) * bb;
        if (bb > 0x1F00)
            bb = 0x7C00;
        else
            bb = (bb & 0x1F00) << 2;
        p->dst[i] = bb + (rr + gg);
    }
    Palette_MarkDirty();
}
#else
NAKED
void sub_080E847C(struct C15cPulse *p)
{
    asm_unified(
        ".L080E847C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    adds r5, r0, #0\n"
        "    bl PalFade_AllDone\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bne .L080E8580\n"
        "    bl Palette_IsBg13Black\n"
        "    cmp r0, #1\n"
        "    beq .L080E8580\n"
        "    ldrb r1, [r5, #5]\n"
        "    movs r0, #5\n"
        "    ldrsb r0, [r5, r0]\n"
        "    cmp r0, #1\n"
        "    bne .L080E84B8\n"
        "    ldrb r0, [r5, #4]\n"
        "    adds r0, #1\n"
        "    strb r0, [r5, #4]\n"
        "    movs r0, #4\n"
        "    ldrsb r0, [r5, r0]\n"
        "    ldrb r2, [r5, #3]\n"
        "    cmp r0, r2\n"
        "    bne .L080E84CA\n"
        "    b .L080E84C4\n"
        ".L080E84B8:\n"
        "    ldrb r0, [r5, #4]\n"
        "    subs r0, #1\n"
        "    strb r0, [r5, #4]\n"
        "    lsls r0, r0, #0x18\n"
        "    cmp r0, #0\n"
        "    bne .L080E84CA\n"
        ".L080E84C4:\n"
        "    movs r0, #1\n"
        "    subs r0, r0, r1\n"
        "    strb r0, [r5, #5]\n"
        ".L080E84CA:\n"
        "    movs r3, #0\n"
        "    mov r8, r3\n"
        "    ldr r0, [r5, #0x28]\n"
        "    mov sl, r0\n"
        "    movs r1, #8\n"
        "    adds r1, r1, r5\n"
        "    mov sb, r1\n"
        "    movs r2, #0xf8\n"
        "    lsls r2, r2, #5\n"
        "    mov ip, r2\n"
        ".L080E84DE:\n"
        "    ldrb r0, [r5]\n"
        "    movs r2, #4\n"
        "    ldrsb r2, [r5, r2]\n"
        "    muls r0, r2, r0\n"
        "    adds r0, #0xc0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    mov r3, r8\n"
        "    lsls r1, r3, #1\n"
        "    mov r3, sb\n"
        "    adds r0, r3, r1\n"
        "    ldrh r6, [r0]\n"
        "    movs r0, #0x1f\n"
        "    ands r0, r6\n"
        "    muls r0, r4, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    adds r7, r1, #0\n"
        "    cmp r4, ip\n"
        "    bls .L080E8508\n"
        "    mov r4, ip\n"
        ".L080E8508:\n"
        "    lsrs r4, r4, #8\n"
        "    ldrb r0, [r5, #1]\n"
        "    muls r0, r2, r0\n"
        "    adds r0, #0xc0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    movs r1, #0xf8\n"
        "    lsls r1, r1, #2\n"
        "    adds r0, r1, #0\n"
        "    ands r0, r6\n"
        "    lsrs r0, r0, #5\n"
        "    muls r0, r3, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    cmp r3, ip\n"
        "    bls .L080E852C\n"
        "    adds r3, r1, #0\n"
        "    b .L080E8532\n"
        ".L080E852C:\n"
        "    mov r0, ip\n"
        "    ands r0, r3\n"
        "    lsrs r3, r0, #3\n"
        ".L080E8532:\n"
        "    ldrb r0, [r5, #2]\n"
        "    muls r0, r2, r0\n"
        "    adds r0, #0xc0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    mov r1, sb\n"
        "    adds r0, r1, r7\n"
        "    ldrh r1, [r0]\n"
        "    movs r6, #0xf8\n"
        "    lsls r6, r6, #7\n"
        "    adds r0, r6, #0\n"
        "    ands r0, r1\n"
        "    lsrs r0, r0, #0xa\n"
        "    muls r0, r2, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    movs r1, #0xf8\n"
        "    lsls r1, r1, #0x15\n"
        "    lsrs r0, r1, #0x10\n"
        "    cmp r2, r0\n"
        "    bls .L080E8560\n"
        "    adds r2, r6, #0\n"
        "    b .L080E8564\n"
        ".L080E8560:\n"
        "    ands r2, r0\n"
        "    lsls r2, r2, #2\n"
        ".L080E8564:\n"
        "    mov r1, sl\n"
        "    adds r0, r7, r1\n"
        "    adds r1, r4, r3\n"
        "    adds r1, r2, r1\n"
        "    strh r1, [r0]\n"
        "    mov r0, r8\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    mov r8, r0\n"
        "    cmp r0, #0xf\n"
        "    bls .L080E84DE\n"
        "    bl Palette_MarkDirty\n"
        ".L080E8580:\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// sub_080E8590 @ 0x080E8590
/* As sub_080E847C, for the colours selected by mask only. */
#ifdef NONMATCHING
void sub_080E8590(struct C15cPulse *p, u16 mask)
{
    u16 c;
    u16 rr;
    u16 gg;
    u16 bb;
    u8 i;

    if ((u16)PalFade_AllDone() != 1 || Palette_IsBg13Black() == 1)
        return;
    if (p->dir == 1)
    {
        p->level++;
        if (p->level == p->max)
            p->dir = 1 - p->dir;
    }
    else
    {
        if (--p->level == 0)
            p->dir = 1 - p->dir;
    }
    for (i = 0; i < 16; i++)
    {
        if ((mask >> i) & 1)
        {
            rr = p->r * p->level + 0xC0;
            c = p->src[i];
            rr = (c & 0x1F) * rr;
            if (rr > 0x1F00)
                rr = 0x1F00;
            rr >>= 8;
            gg = p->g * p->level + 0xC0;
            gg = ((c & 0x3E0) >> 5) * gg;
            if (gg > 0x1F00)
                gg = 0x3E0;
            else
                gg = (gg & 0x1F00) >> 3;
            bb = p->b * p->level + 0xC0;
            bb = ((p->src[i] & 0x7C00) >> 10) * bb;
            if (bb > 0x1F00)
                bb = 0x7C00;
            else
                bb = (bb & 0x1F00) << 2;
            p->dst[i] = bb + (rr + gg);
        }
    }
    Palette_MarkDirty();
}
#else
NAKED
void sub_080E8590(struct C15cPulse *p, u16 mask)
{
    asm_unified(
        ".L080E8590:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #4\n"
        "    adds r5, r0, #0\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp]\n"
        "    bl PalFade_AllDone\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    cmp r0, #1\n"
        "    bne .L080E86A4\n"
        "    bl Palette_IsBg13Black\n"
        "    cmp r0, #1\n"
        "    beq .L080E86A4\n"
        "    ldrb r1, [r5, #5]\n"
        "    movs r0, #5\n"
        "    ldrsb r0, [r5, r0]\n"
        "    cmp r0, #1\n"
        "    bne .L080E85D4\n"
        "    ldrb r0, [r5, #4]\n"
        "    adds r0, #1\n"
        "    strb r0, [r5, #4]\n"
        "    movs r0, #4\n"
        "    ldrsb r0, [r5, r0]\n"
        "    ldrb r2, [r5, #3]\n"
        "    cmp r0, r2\n"
        "    bne .L080E85E6\n"
        "    b .L080E85E0\n"
        ".L080E85D4:\n"
        "    ldrb r0, [r5, #4]\n"
        "    subs r0, #1\n"
        "    strb r0, [r5, #4]\n"
        "    lsls r0, r0, #0x18\n"
        "    cmp r0, #0\n"
        "    bne .L080E85E6\n"
        ".L080E85E0:\n"
        "    movs r0, #1\n"
        "    subs r0, r0, r1\n"
        "    strb r0, [r5, #5]\n"
        ".L080E85E6:\n"
        "    movs r0, #0\n"
        "    mov sb, r0\n"
        "    movs r1, #0xf8\n"
        "    lsls r1, r1, #0x15\n"
        "    mov sl, r1\n"
        ".L080E85F0:\n"
        "    ldr r0, [sp]\n"
        "    mov r2, sb\n"
        "    asrs r0, r2\n"
        "    movs r1, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L080E8692\n"
        "    ldrb r0, [r5]\n"
        "    movs r3, #4\n"
        "    ldrsb r3, [r5, r3]\n"
        "    muls r0, r3, r0\n"
        "    adds r0, #0xc0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    lsls r1, r2, #1\n"
        "    adds r2, r5, #0\n"
        "    adds r2, #8\n"
        "    adds r0, r2, r1\n"
        "    ldrh r7, [r0]\n"
        "    movs r0, #0x1f\n"
        "    ands r0, r7\n"
        "    muls r0, r4, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    mov r0, sl\n"
        "    lsrs r6, r0, #0x10\n"
        "    mov r8, r1\n"
        "    mov ip, r2\n"
        "    cmp r4, r6\n"
        "    bls .L080E862E\n"
        "    adds r4, r6, #0\n"
        ".L080E862E:\n"
        "    lsrs r4, r4, #8\n"
        "    ldrb r0, [r5, #1]\n"
        "    muls r0, r3, r0\n"
        "    adds r0, #0xc0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    movs r1, #0xf8\n"
        "    lsls r1, r1, #2\n"
        "    adds r0, r1, #0\n"
        "    ands r0, r7\n"
        "    lsrs r0, r0, #5\n"
        "    muls r0, r2, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    cmp r2, r6\n"
        "    bls .L080E8652\n"
        "    adds r2, r1, #0\n"
        "    b .L080E8658\n"
        ".L080E8652:\n"
        "    adds r0, r6, #0\n"
        "    ands r0, r2\n"
        "    lsrs r2, r0, #3\n"
        ".L080E8658:\n"
        "    ldrb r0, [r5, #2]\n"
        "    muls r0, r3, r0\n"
        "    adds r0, #0xc0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    mov r0, ip\n"
        "    add r0, r8\n"
        "    ldrh r1, [r0]\n"
        "    movs r6, #0xf8\n"
        "    lsls r6, r6, #7\n"
        "    adds r0, r6, #0\n"
        "    ands r0, r1\n"
        "    lsrs r0, r0, #0xa\n"
        "    muls r0, r3, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    mov r1, sl\n"
        "    lsrs r0, r1, #0x10\n"
        "    cmp r3, r0\n"
        "    bls .L080E8684\n"
        "    adds r3, r6, #0\n"
        "    b .L080E8688\n"
        ".L080E8684:\n"
        "    ands r3, r0\n"
        "    lsls r3, r3, #2\n"
        ".L080E8688:\n"
        "    ldr r1, [r5, #0x28]\n"
        "    add r1, r8\n"
        "    adds r0, r4, r2\n"
        "    adds r0, r3, r0\n"
        "    strh r0, [r1]\n"
        ".L080E8692:\n"
        "    mov r0, sb\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x18\n"
        "    lsrs r0, r0, #0x18\n"
        "    mov sb, r0\n"
        "    cmp r0, #0xf\n"
        "    bls .L080E85F0\n"
        "    bl Palette_MarkDirty\n"
        ".L080E86A4:\n"
        "    add sp, #4\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
    );
}
#endif


// sub_080E86B4 @ 0x080E86B4
/* Sets up the palette pulse of a demon whose record asks for one (attr bit 7) and loads its
   palette as the pulse source. */
void sub_080E86B4(u16 *dst, struct C15cPulse *p, u16 id)
{
    const struct DemonGfxRecord *rec = Demon_GetGfxRecord(id);
    const void *pal;

    if (rec->attr & 0x80)
    {
        p->max = p->level = (rec->attr & 0x3F) * 2;
        p->dir = 0;
        p->unk6 = 0xFF;
        p->unk7 = 0x80;
        p->r = p->g = p->b = 0x80 / p->max;
        p->dst = dst;
        pal = rec->palette;
        if (gMainCallback == sub_080D977C && sub_080C2644(id) == 0)
            pal = gUnknown_086BE584;
        Palette_CopyWithEffect(3, pal, p->src, 0x20, 0x20);
    }
}

// sub_080E8738 @ 0x080E8738
/* Animates enemy group `slot`'s sprite; returns its state (0 = hidden). */
u8 sub_080E8738(u8 slot)
{
    struct C15cBattle *b = BB;
    struct C15cDemonSprite *s = &b->sprites[slot];
    const struct DemonGfxRecord *rec;
    const struct DemonAnimFrame *frame;
    const u8 *step;

    switch (s->unk4)
    {
    case 3:
        if (!DemonSprite_StepShake(s))
            break;
        DemonSprite_LoadPalette(slot, 0);
    case 2:
        s->unk4 = 1;
        break;
    case 0:
        break;
    }
    if (s->unk4 != 0)
    {
        rec = Demon_GetGfxRecord(b->groups[slot]);
        if (rec->kind == 0)
        {
            if (rec->attr & 0x80)
            {
                frame = &rec->anim->frames[s->bank];
                if (s->unk1 != 0)
                {
                    s->unk1--;
                }
                else
                {
                    s->bank++;
                    frame = &rec->anim->frames[s->bank];
                    if (frame->duration == 0xFFFF)
                    {
                        s->bank = 0;
                        frame = rec->anim->frames;
                    }
                    s->unk1 = frame->duration * 2;
                    s->upload = 0;
                }
                s->def = frame->def;
                if (s->unk4 != 3)
                {
                    if ((rec->attr & 0xC0) != 0xC0)
                    {
                        sub_080E847C(&s->pulse);
                    }
                    else
                    {
                        sub_080E8590(&s->pulse, 0);
                        s->def = frame->def;
                    }
                }
            }
            else
            {
                if (s->unk1 != 0)
                {
                    s->unk1--;
                }
                else
                {
                    s->bank++;
                    step = &gUnknown_086BE75C[rec->attr][s->bank];
                    if (*step == 0xFF)
                    {
                        s->bank = 0;
                        step = gUnknown_086BE75C[rec->attr];
                    }
                    s->unk1 = *step;
                    s->upload = 1;
                }
                s->def = gUnknown_080F649C;
            }
            s->unk10 = 2;
            s->unk11 = 1;
        }
        else if (s->unk1 != 0)
        {
            s->unk1--;
        }
        else
        {
            const struct DemonAnimFrame *next;

            if (sub_080E8AC0(b->groups[slot]) <= 1)
            {
                s->unk10 = 2;
                s->unk11 = 1;
            }
            else
            {
                s->unk10 = 3;
                s->unk11 = 9;
            }
            s->bank++;
            next = &rec->anim->frames[s->bank];
            if (next->duration == 0xFFFF)
            {
                s->bank = 0;
                next = rec->anim->frames;
            }
            s->unk1 = next->duration * 2;
            s->upload = 0;
            s->def = next->def;
        }
    }
    return s->unk4;
}

// sub_080E88C0 @ 0x080E88C0
/* As sub_080E8738 for an extra sprite slot (slot 3 = 0) showing demonId; returns 1 when the
   frame changed. */
u8 sub_080E88C0(u8 slot)
{
    struct C15cBattle *b = BB;
    struct C15cDemonSprite *s;
    const struct DemonGfxRecord *rec;
    const struct DemonAnimFrame *frame;
    const u8 *step;
    u8 updated = 0;
    u8 i = slot;

    if (i == 3)
        i = 0;
    s = &b->sprites[i];
    if (s->unk4 == 0)
        goto end;
    rec = Demon_GetGfxRecord(s->demonId);
    if (rec->kind == 0)
    {
        if (rec->attr & 0x80)
        {
            frame = &rec->anim->frames[s->bank];
            s->def = frame->def;
            if (s->unk1 != 0)
            {
                s->unk1--;
            }
            else
            {
                s->bank++;
                frame = &rec->anim->frames[s->bank];
                if (frame->duration == 0xFFFF)
                {
                    s->bank = updated;
                    frame = rec->anim->frames;
                }
                s->unk1 = frame->duration * 2;
                s->upload = updated;
                updated = 1;
                s->def = frame->def;
            }
            if (s->unk4 != 3)
            {
                if ((rec->attr & 0xC0) != 0xC0)
                {
                    sub_080E847C(&s->pulse);
                }
                else
                {
                    sub_080E8590(&s->pulse, 0);
                    s->def = frame->def;
                }
            }
        }
        else
        {
            if (s->unk1 != 0)
            {
                s->unk1--;
            }
            else
            {
                s->bank++;
                step = &gUnknown_086BE75C[rec->attr][s->bank];
                if (*step == 0xFF)
                {
                    s->bank = updated;
                    step = gUnknown_086BE75C[rec->attr];
                }
                s->unk1 = *step;
                s->upload = 1;
                updated = 1;
            }
            s->def = gUnknown_080F649C;
        }
        s->unk10 = 2;
        s->unk11 = 1;
    }
    else if (s->unk1 != 0)
    {
        s->unk1--;
    }
    else
    {
        const struct DemonAnimFrame *next;

        if (sub_080E8AC0(s->demonId) <= 1)
        {
            s->unk10 = 2;
            s->unk11 = 1;
        }
        else
        {
            s->unk10 = 3;
            s->unk11 = 9;
        }
        s->bank++;
        next = &rec->anim->frames[s->bank];
        if (next->duration == 0xFFFF)
        {
            s->bank = 0;
            next = rec->anim->frames;
        }
        s->unk1 = next->duration * 2;
        s->upload = 0;
        s->def = next->def;
        updated = 1;
    }
end:
    return updated;
}

// sub_080E8A28 @ 0x080E8A28
/* Shows demon `id` in sprite slot `slot` (3 = 0) with the palette of OBJ palette 14/15/13. */
void sub_080E8A28(u8 slot, u16 id)
{
    struct C15cBattle *b = BB;
    struct C15cDemonSprite *s;
    u16 *pal;
    u8 i = slot;

    if (i == 3)
        i = 0;
    s = &b->sprites[i];
    s->bank = 0;
    s->unk1 = 0;
    s->unk4 = 1;
    s->unk7 = 0;
    s->unk6 = 0;
    s->unk5 = 0;
    s->demonId = id;
    s->def = NULL;
    Demon_GetGfxRecord(s->demonId);
    switch (i)
    {
    case 0:
        pal = &gPaletteBuffer[0x1E0];
        break;
    case 1:
        pal = &gPaletteBuffer[0x1F0];
        break;
    case 2:
        pal = &gPaletteBuffer[0x1D0];
        break;
    }
    sub_080E86B4(pal, &s->pulse, s->demonId);
}

// sub_080E8AA0 @ 0x080E8AA0
struct C15cDemonSprite *sub_080E8AA0(u8 slot)
{
    struct C15cBattle *b = BB;
    u8 i = slot;

    if (i == 3)
        i = 0;
    return &b->sprites[i];
}

// sub_080E8AC0 @ 0x080E8AC0
u16 sub_080E8AC0(u16 id)
{
    if (gMainCallback != sub_080D977C && (!(gUnk_0200AB04 & 0x8000) || id <= 0xFF))
        return 0;
    return 3;
}

// sub_080E8AFC @ 0x080E8AFC
void sub_080E8AFC(u8 slot)
{
    struct C15cBattle *b = BB;
    struct C15cDemonSprite *s = &b->sprites[slot];

    s->unk4 = 3;
    DemonSprite_LoadPalette(slot, 1);
}

// DemonSprite_StepShake @ 0x080E8B20
/* Steps the hit shake of a sprite; returns 1 when done. */
u32 DemonSprite_StepShake(struct C15cDemonSprite *s)
{
    struct C15cShake shake = gUnknown_086BE7BC;

    if (s->unk5 >= 10)
    {
        s->unk6 = 0;
        s->unk7 = 0;
        s->unk5 = 0;
        return 1;
    }
    s->unk6 = shake.d[s->unk5].x;
    s->unk7 = shake.d[s->unk5].y;
    s->unk5++;
    return 0;
}

// DemonSprite_LoadPalette @ 0x080E8B78
/* Loads enemy group `slot`'s palette (kind 0) or flash palette `kind` into OBJ palette
   14 + slot. */
void DemonSprite_LoadPalette(u8 slot, u8 kind)
{
    struct C15cBattle *b = BB;
    u16 *dst = &gPaletteBuffer[0x100 + (slot + 14) * 16];
    const void *pal;

    switch (kind)
    {
    case 0:
        pal = Demon_GetGfxRecord(b->groups[slot])->palette;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        pal = gUnknown_086BE884[kind];
        break;
    }
    if (gMainCallback == sub_080D977C && sub_080C2644(b->groups[slot]) == 0)
        pal = gUnknown_086BE584;
    Palette_CopyWithEffect(3, pal, dst, 0x20, 0x20);
    Palette_MarkDirty();
}

// sub_080E8C10 @ 0x080E8C10
void sub_080E8C10(struct Task *t)
{
    if (((u8 *)t)[6] != 0)
        t->result = 1;
    else
        t->result = 0;
}

// sub_080E8C24 @ 0x080E8C24
void sub_080E8C24(struct Task *t)
{
    if (((u8 *)t)[6] != 0)
        sub_080E8DB4(0);
}

// sub_080E8C38 @ 0x080E8C38
void sub_080E8C38(void)
{
    struct C15cBattle *b = BB;

    b->tasks[0] = Task_Create(gUnknown_086BE89C, 0xFFFF);
}

// sub_080E8C58 @ 0x080E8C58
/* Sets up the enemy group sprites for groups g0/g1 (0xFFFF = none) and starts their tasks. */
void sub_080E8C58(u16 g0, u16 g1, u16 arg)
{
    struct C15cBattle *b = BB;
    u8 n = 0;

    gUnk_03006434 = b->bstate;
    if (b->unkF6A != 0)
        return;
    b->sprites[0].unk0 = 0;
    b->sprites[1].unk0 = 0;
    if (g0 != 0xFFFF)
    {
        b->groups[0] = g0;
        b->sprites[0].unk0 = 1;
        b->sprites[0].x = 0x7FFF;
        b->sprites[0].y = 0x7FFF;
    }
    else
    {
        n = 1;
    }
    if (g1 != 0xFFFF)
    {
        b->groups[1] = g1;
        b->sprites[1].unk0 = 1;
        b->sprites[1].x = 0x7FFF;
        b->sprites[1].y = 0x7FFF;
    }
    else
    {
        n++;
    }
    if (n == 2)
        return;
    b->vblankTask = (u16 *)VBlankTask_Add(sub_080E5528);
    b->sprites[0].upload = 0;
    b->sprites[1].upload = 0;
    sub_080E5668(sub_080E5674);
    b->tasks[0] = Task_Create(gUnknown_086BE89C, 0xFFFF);
    ((u8 *)b->tasks[0])[6] = arg;
}

// sub_080E8D64 @ 0x080E8D64
u8 sub_080E8D64(void)
{
    struct C15cBattle *b = BB;

    if (b->unkEC3 == 0)
        return TRUE;
    return FALSE;
}
