#include "global.h"
#include "inventory.h"

extern u8 gUnk_02039FE4[];   /* per-member face tiles, 0x80 bytes each */
extern u8 gUnk_020399E4[];   /* per-member name tiles, 0x100 bytes each */

// sub_080C6AD8 @ 0x080C6AD8
void sub_080C6AD8(u16 slot, u16 layer, u16 prio, u16 x, u16 y)
{
    u16 pal = sub_080C6FB8(slot) - 1;

    Sprite_Draw(gUnknown_0834A254[slot], layer, pal, prio, 0, x, y);
}

// sub_080C6B40 @ 0x080C6B40
/* Draws the face of member key & 0xF if it is in the active party. */
#ifdef NONMATCHING
void sub_080C6B40(u16 key, u16 layer, u16 prio, u16 x, u16 y)
{
    u16 who = key & 0xF;
    u32 i = 0;

    if (gGameState.order[0] != who)
    {
        do
        {
            i++;
            if (i > 5)
                break;
        } while (gGameState.order[i] != who);
    }
    if (i != 6)
        sub_080C6AD8(i, layer, prio, x, y);
}
#else
NAKED
void sub_080C6B40(u16 key, u16 layer, u16 prio, u16 x, u16 y)
{
    asm_unified(
        ".L080C6B40:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    sub sp, #4\n"
        "    ldr r4, [sp, #0x18]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    mov ip, r1\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r6, r2, #0x10\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r5, r3, #0x10\n"
        "    lsls r4, r4, #0x10\n"
        "    lsrs r4, r4, #0x10\n"
        "    movs r1, #0xf0\n"
        "    lsls r1, r1, #0xc\n"
        "    ands r1, r0\n"
        "    lsrs r3, r1, #0x10\n"
        "    movs r1, #0\n"
        "    ldr r0, .L080C6BA4\n"
        "    movs r7, #0xa2\n"
        "    lsls r7, r7, #4\n"
        "    adds r2, r0, r7\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r2, r0]\n"
        "    cmp r0, r3\n"
        "    beq .L080C6B86\n"
        ".L080C6B74:\n"
        "    adds r1, #1\n"
        "    cmp r1, #5\n"
        "    bhi .L080C6B86\n"
        "    adds r0, r1, r2\n"
        "    ldrb r0, [r0]\n"
        "    lsls r0, r0, #0x18\n"
        "    asrs r0, r0, #0x18\n"
        "    cmp r0, r3\n"
        "    bne .L080C6B74\n"
        ".L080C6B86:\n"
        "    cmp r1, #6\n"
        "    beq .L080C6B9A\n"
        "    lsls r0, r1, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r4, [sp]\n"
        "    mov r1, ip\n"
        "    adds r2, r6, #0\n"
        "    adds r3, r5, #0\n"
        "    bl sub_080C6AD8\n"
        ".L080C6B9A:\n"
        "    add sp, #4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080C6BA4: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
    );
}
#endif

// sub_080C6BA8 @ 0x080C6BA8
/* The running task whose per-frame function is sub_080D2F60, or NULL. */
struct Task *sub_080C6BA8(void)
{
    u32 i;

    for (i = 0; i < 64; i++)
    {
        struct Task *t = &gTasks[i];

        if (t->state != 0 && t->onFrame == sub_080D2F60)
            return t;
    }
    return NULL;
}

// Hud_DrawMemberPanel @ 0x080C6BE0
/* Draws party panel 'slot' of the field HUD: face, HP and MP bars, shaking while hit. */
void Hud_DrawMemberPanel(u16 slot, u16 x, u16 y)
{
    u16 *shake = &gHudState[0x24 + slot];
    u16 *dir = &gHudState[0x2A + slot];
    struct Combatant *c;

    if ((&gHudState[0x1E])[slot] == 1)
        return;
    if (gGameState.order[slot] == -1)
    {
        Sprite_Draw(gUnknown_0800082C, 7, 0, 1, 0, x + 0x10, y + 7);
        *shake = 0;
        return;
    }
    c = Party_GetMember(slot);
    /* From here x and y are the panel's shake offset. */
    x = 0;
    y = 0;
    if (*shake != 0)
    {
        if ((gFrameCounter & 3) == 0)
        {
            *dir = -*dir;
            if (--*shake == 0)
                *dir = y;
        }
        y += *dir;
    }
    if (gHudState[0x1F] != 1 || sub_080C6BA8() == NULL)
        Sprite_Draw(gUnknown_0834A23C[slot], 7, 0, 1, 0, gUnknown_0834A274[slot].x + x,
                    y + (&gUnknown_0834A274[0].y)[slot * 2]);
    if (gHudState[0x1F] != 1 || slot != 2)
        sub_080C6AD8(slot, 7, 1, gUnknown_0834A28C[slot].x + x, y + (&gUnknown_0834A28C[0].y)[slot * 2]);
    if (gHudState[0x1F] != 1 || (slot != 0 && slot != 3 && slot != 4))
        Hud_DrawGauge(slot, 0, gUnknown_0834A2BC[slot].x + x, y + (&gUnknown_0834A2BC[0].y)[slot * 2],
                     c->maxHp, c->hp);
    if (c->maxMp != 0)
        Hud_DrawGauge(slot, 1, gUnknown_0834A2D4[slot].x + x, y + (&gUnknown_0834A2D4[0].y)[slot * 2],
                     c->maxMp, c->mp);
    if (gHudState[0x1F] == 1 && (slot == 0 || slot == 2))
        return;
    if (c->maxMp != 0)
        Sprite_Draw(gUnknown_080005EC, 7, 0, 1, 0, gUnknown_0834A2A4[slot].x + x,
                    y + (&gUnknown_0834A2A4[0].y)[slot * 2]);
    else
        Sprite_DrawSingle(gUnknown_0834A26C, 7, 0, 1, 0, gUnknown_0834A2A4[slot].x + x,
                          y + (&gUnknown_0834A2A4[0].y)[slot * 2]);
}

// sub_080C6E30 @ 0x080C6E30
void sub_080C6E30(u16 v)
{
    u16 *hud = gHudState;

    hud[0x1E] = v;
    hud[0x1F] = v;
    hud[0x20] = v;
    hud[0x21] = v;
    hud[0x22] = v;
    hud[0x23] = v;
}

// sub_080C6E54 @ 0x080C6E54
void sub_080C6E54(void)
{
    DmaCopy32(3, (void *)0x020399E4, (void *)0x06010C00, 0x600);
}

// Party_BuildMemberNameTiles @ 0x080C6E78
/* Renders the names of the six active members as eight 8x8 glyph tiles each (name bytes
   index gUnknown_081AF7B8, 0xFF = blank) at 0x020399E4 + slot * 0x100, then queues the DMA
   to OBJ VRAM 0x06010C00. Names longer than 8 characters cannot be shown. */
void Party_BuildMemberNameTiles(void)
{
    s32 i, j;

    for (i = 0; i <= 5; i++)
    {
        struct Combatant *c;

        if ((c = Party_GetMember(i)) != NULL)
        {
            const u8 *name = c->name;
            u32 *p = (u32 *)&gUnk_020399E4[i << 8];

            for (j = 0; j <= 7; j++)
            {
                if (name[j] != 0xFF)
                {
                    const u32 *src = gUnknown_081AF7B8[name[j]].w;

                    *p++ = *src++;
                    *p++ = *src++;
                    *p++ = *src++;
                    *p++ = *src++;
                    *p++ = *src++;
                    *p++ = *src++;
                    *p++ = *src++;
                    *p++ = *src;
                }
                else
                {
                    *p++ = 0;
                    *p++ = 0;
                    *p++ = 0;
                    *p++ = 0;
                    *p++ = 0;
                    *p++ = 0;
                    *p++ = 0;
                    *p++ = 0;
                }
            }
        }
    }
    VBlankTask_AddCounted(sub_080C6E54, 1);
}

// sub_080C6F00 @ 0x080C6F00
void sub_080C6F00(void)
{
    u16 *hud;

    DmaCopy32(3, (void *)0x02039FE4, (void *)0x06011200, 0x300);
    hud = gHudState;
    hud[0x37] = 0;
}

// Hud_LoadMemberFace @ 0x080C6F30
/* Copies the 4 face tiles of party slot i to 0x02039FE4 + i * 0x80 and queues the DMA. */
void Hud_LoadMemberFace(u16 i)
{
    if (Party_GetMember(i) != NULL)
    {
        const u32 *src = gUnknown_081A81B8;
        u32 *dst = (u32 *)&gUnk_02039FE4[i << 7];
        u32 k;
        u16 *hud;

        src += gUnknown_0834A2EC[Hud_GetMemberFace(i)].tile;
        for (k = 0; k < 4; k++)
        {
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;
            *dst++ = *src++;
        }
        hud = gHudState;
        if (hud[0x37] == 0)
        {
            VBlankTask_AddCounted(sub_080C6F00, 1);
            hud[0x37] = 1;
        }
    }
}

// sub_080C6FB8 @ 0x080C6FB8
u32 sub_080C6FB8(u16 slot)
{
    return gUnknown_0834A2EC[Hud_GetMemberFace(slot)].palette;
}
