#include "global.h"
#include "inventory.h"

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
#ifdef NONMATCHING
struct Task *sub_080C6BA8(void)
{
    u32 i;

    for (i = 0; i < 64; i++)
    {
        if (gTasks[i].state != 0 && gTasks[i].onFrame == sub_080D2F60)
            return &gTasks[i];
    }
    return NULL;
}
#else
NAKED
struct Task *sub_080C6BA8(void)
{
    asm_unified(
        ".L080C6BA8:\n"
        "    push {r4, lr}\n"
        "    ldr r4, .L080C6BC4\n"
        "    ldr r1, .L080C6BC8\n"
        "    adds r2, r1, #0\n"
        "    ldr r0, .L080C6BCC\n"
        "    adds r3, r1, r0\n"
        ".L080C6BB4:\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, #0\n"
        "    beq .L080C6BD0\n"
        "    ldr r0, [r1, #0x20]\n"
        "    cmp r0, r4\n"
        "    bne .L080C6BD0\n"
        "    adds r0, r2, #0\n"
        "    b .L080C6BDA\n"
        ".L080C6BC4: .4byte sub_080D2F60\n"
        ".L080C6BC8: .4byte 0x02009004 @ EWRAM+0x9004\n"
        ".L080C6BCC: .4byte 0x0000189C\n"
        ".L080C6BD0:\n"
        "    adds r1, #0x64\n"
        "    adds r2, #0x64\n"
        "    cmp r1, r3\n"
        "    bls .L080C6BB4\n"
        "    movs r0, #0\n"
        ".L080C6BDA:\n"
        "    pop {r4}\n"
        "    pop {r1}\n"
        "    bx r1\n"
    );
}
#endif

// Hud_DrawMemberPanel @ 0x080C6BE0
/* Draws party panel 'slot' of the field HUD: face, HP and MP bars, shaking while hit. */
#ifdef NONMATCHING
void Hud_DrawMemberPanel(u16 slot, u16 x, u16 y)
{
    u16 *shake = &gHudState[0x24 + slot];
    u16 *dir = &gHudState[0x2A + slot];
    struct Combatant *c;
    u16 dx, dy;

    if (gHudState[0x1E + slot] == 1)
        return;
    if (gGameState.order[slot] == -1)
    {
        Sprite_Draw(gUnknown_0800082C, 7, 0, 1, 0, x + 0x10, y + 7);
        *shake = 0;
        return;
    }
    c = Party_GetMember(slot);
    dx = 0;
    dy = 0;
    if (*shake != 0)
    {
        if ((gFrameCounter & 3) == 0)
        {
            *dir = -*dir;
            if (--*shake == 0)
                *dir = dy;
        }
        dy += *dir;
    }
    if (gHudState[0x1F] != 1 || sub_080C6BA8() == NULL)
        Sprite_Draw(gUnknown_0834A23C[slot], 7, 0, 1, 0, gUnknown_0834A274[slot].x + dx,
                    dy + gUnknown_0834A274[slot].y);
    if (gHudState[0x1F] != 1 || slot != 2)
        sub_080C6AD8(slot, 7, 1, gUnknown_0834A28C[slot].x + dx, dy + gUnknown_0834A28C[slot].y);
    if (gHudState[0x1F] != 1 || (slot != 0 && slot != 3 && slot != 4))
        Hud_DrawGauge(slot, 0, gUnknown_0834A2BC[slot].x + dx, dy + gUnknown_0834A2BC[slot].y,
                     c->maxHp, c->hp);
    if (c->maxMp != 0)
        Hud_DrawGauge(slot, 1, gUnknown_0834A2D4[slot].x + dx, dy + gUnknown_0834A2D4[slot].y,
                     c->maxMp, c->mp);
    if (gHudState[0x1F] == 1 && (slot == 0 || slot == 2))
        return;
    if (c->maxMp != 0)
        Sprite_Draw(gUnknown_080005EC, 7, 0, 1, 0, gUnknown_0834A2A4[slot].x + dx,
                    dy + gUnknown_0834A2A4[slot].y);
    else
        Sprite_DrawSingle(gUnknown_0834A26C, 7, 0, 1, c->maxMp, gUnknown_0834A2A4[slot].x + dx,
                          dy + gUnknown_0834A2A4[slot].y);
}
#else
NAKED
void Hud_DrawMemberPanel(u16 slot, u16 x, u16 y)
{
    asm_unified(
        ".L080C6BE0:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sb\n"
        "    mov r6, r8\n"
        "    push {r6, r7}\n"
        "    sub sp, #0xc\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r4, r0, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    mov r8, r1\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r7, r2, #0x10\n"
        "    lsls r2, r4, #1\n"
        "    ldr r0, .L080C6C4C\n"
        "    adds r6, r2, r0\n"
        "    adds r1, r0, #0\n"
        "    adds r1, #0xc\n"
        "    adds r5, r2, r1\n"
        "    subs r0, #0xc\n"
        "    adds r2, r2, r0\n"
        "    ldrh r0, [r2]\n"
        "    cmp r0, #1\n"
        "    bne .L080C6C10\n"
        "    b .L080C6E18\n"
        ".L080C6C10:\n"
        "    ldr r0, .L080C6C50\n"
        "    movs r1, #0xa2\n"
        "    lsls r1, r1, #4\n"
        "    adds r0, r0, r1\n"
        "    adds r0, r4, r0\n"
        "    movs r1, #0\n"
        "    ldrsb r1, [r0, r1]\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    cmp r1, r0\n"
        "    bne .L080C6C58\n"
        "    ldr r0, .L080C6C54\n"
        "    movs r4, #0\n"
        "    str r4, [sp]\n"
        "    mov r1, r8\n"
        "    adds r1, #0x10\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #4]\n"
        "    adds r1, r7, #7\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #7\n"
        "    movs r2, #0\n"
        "    movs r3, #1\n"
        "    bl Sprite_Draw\n"
        "    strh r4, [r6]\n"
        "    b .L080C6E18\n"
        ".L080C6C4C: .4byte 0x0200E81C @ EWRAM+0xE81C\n"
        ".L080C6C50: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L080C6C54: .4byte gUnknown_0800082C\n"
        ".L080C6C58:\n"
        "    adds r0, r4, #0\n"
        "    bl Party_GetMember\n"
        "    mov sb, r0\n"
        "    movs r2, #0\n"
        "    mov r8, r2\n"
        "    movs r7, #0\n"
        "    ldrh r0, [r6]\n"
        "    cmp r0, #0\n"
        "    beq .L080C6C94\n"
        "    ldr r0, .L080C6DC8\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #3\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    bne .L080C6C8C\n"
        "    ldrh r0, [r5]\n"
        "    rsbs r0, r0, #0\n"
        "    strh r0, [r5]\n"
        "    ldrh r0, [r6]\n"
        "    subs r0, #1\n"
        "    strh r0, [r6]\n"
        "    lsls r0, r0, #0x10\n"
        "    cmp r0, #0\n"
        "    bne .L080C6C8C\n"
        "    strh r7, [r5]\n"
        ".L080C6C8C:\n"
        "    ldrh r0, [r5]\n"
        "    adds r0, r7, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r7, r0, #0x10\n"
        ".L080C6C94:\n"
        "    ldr r0, .L080C6DCC\n"
        "    ldrh r0, [r0, #0x3e]\n"
        "    cmp r0, #1\n"
        "    bne .L080C6CA4\n"
        "    bl sub_080C6BA8\n"
        "    cmp r0, #0\n"
        "    bne .L080C6CD6\n"
        ".L080C6CA4:\n"
        "    ldr r0, .L080C6DD0\n"
        "    lsls r3, r4, #2\n"
        "    adds r0, r3, r0\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    ldr r2, .L080C6DD4\n"
        "    adds r1, r3, r2\n"
        "    ldrh r1, [r1]\n"
        "    add r1, r8\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #4]\n"
        "    adds r2, #2\n"
        "    adds r3, r3, r2\n"
        "    ldrh r1, [r3]\n"
        "    adds r1, r7, r1\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #7\n"
        "    movs r2, #0\n"
        "    movs r3, #1\n"
        "    bl Sprite_Draw\n"
        ".L080C6CD6:\n"
        "    ldr r0, .L080C6DCC\n"
        "    ldrh r0, [r0, #0x3e]\n"
        "    cmp r0, #1\n"
        "    bne .L080C6CE2\n"
        "    cmp r4, #2\n"
        "    beq .L080C6D08\n"
        ".L080C6CE2:\n"
        "    ldr r1, .L080C6DD8\n"
        "    lsls r2, r4, #2\n"
        "    adds r0, r2, r1\n"
        "    ldrh r3, [r0]\n"
        "    add r3, r8\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    adds r1, #2\n"
        "    adds r2, r2, r1\n"
        "    ldrh r0, [r2]\n"
        "    adds r0, r7, r0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #7\n"
        "    movs r2, #1\n"
        "    bl sub_080C6AD8\n"
        ".L080C6D08:\n"
        "    ldr r0, .L080C6DCC\n"
        "    ldrh r0, [r0, #0x3e]\n"
        "    cmp r0, #1\n"
        "    bne .L080C6D1C\n"
        "    cmp r4, #0\n"
        "    beq .L080C6D48\n"
        "    cmp r4, #3\n"
        "    beq .L080C6D48\n"
        "    cmp r4, #4\n"
        "    beq .L080C6D48\n"
        ".L080C6D1C:\n"
        "    ldr r1, .L080C6DDC\n"
        "    lsls r3, r4, #2\n"
        "    adds r0, r3, r1\n"
        "    ldrh r2, [r0]\n"
        "    add r2, r8\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    adds r1, #2\n"
        "    adds r3, r3, r1\n"
        "    ldrh r3, [r3]\n"
        "    adds r3, r7, r3\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    mov r1, sb\n"
        "    ldrh r0, [r1, #0x1a]\n"
        "    str r0, [sp]\n"
        "    ldrh r0, [r1, #0x18]\n"
        "    str r0, [sp, #4]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #0\n"
        "    bl Hud_DrawGauge\n"
        ".L080C6D48:\n"
        "    mov r2, sb\n"
        "    movs r1, #0x1e\n"
        "    ldrsh r0, [r2, r1]\n"
        "    cmp r0, #0\n"
        "    beq .L080C6D7E\n"
        "    ldr r1, .L080C6DE0\n"
        "    lsls r3, r4, #2\n"
        "    adds r0, r3, r1\n"
        "    ldrh r2, [r0]\n"
        "    add r2, r8\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    adds r1, #2\n"
        "    adds r3, r3, r1\n"
        "    ldrh r3, [r3]\n"
        "    adds r3, r7, r3\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    mov r1, sb\n"
        "    ldrh r0, [r1, #0x1e]\n"
        "    str r0, [sp]\n"
        "    ldrh r0, [r1, #0x1c]\n"
        "    str r0, [sp, #4]\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #1\n"
        "    bl Hud_DrawGauge\n"
        ".L080C6D7E:\n"
        "    ldr r0, .L080C6DCC\n"
        "    ldrh r0, [r0, #0x3e]\n"
        "    cmp r0, #1\n"
        "    bne .L080C6D8E\n"
        "    cmp r4, #0\n"
        "    beq .L080C6E18\n"
        "    cmp r4, #2\n"
        "    beq .L080C6E18\n"
        ".L080C6D8E:\n"
        "    mov r2, sb\n"
        "    movs r0, #0x1e\n"
        "    ldrsh r1, [r2, r0]\n"
        "    cmp r1, #0\n"
        "    beq .L080C6DEC\n"
        "    ldr r0, .L080C6DE4\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    ldr r2, .L080C6DE8\n"
        "    lsls r3, r4, #2\n"
        "    adds r1, r3, r2\n"
        "    ldrh r1, [r1]\n"
        "    add r1, r8\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #4]\n"
        "    adds r2, #2\n"
        "    adds r3, r3, r2\n"
        "    ldrh r1, [r3]\n"
        "    adds r1, r7, r1\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #7\n"
        "    movs r2, #0\n"
        "    movs r3, #1\n"
        "    bl Sprite_Draw\n"
        "    b .L080C6E18\n"
        ".L080C6DC8: .4byte 0x030031BC @ IWRAM+0x31BC\n"
        ".L080C6DCC: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
        ".L080C6DD0: .4byte gUnknown_0834A23C\n"
        ".L080C6DD4: .4byte gUnknown_0834A274\n"
        ".L080C6DD8: .4byte gUnknown_0834A28C\n"
        ".L080C6DDC: .4byte gUnknown_0834A2BC\n"
        ".L080C6DE0: .4byte gUnknown_0834A2D4\n"
        ".L080C6DE4: .4byte gUnknown_080005EC\n"
        ".L080C6DE8: .4byte gUnknown_0834A2A4\n"
        ".L080C6DEC:\n"
        "    ldr r0, .L080C6E28\n"
        "    str r1, [sp]\n"
        "    ldr r2, .L080C6E2C\n"
        "    lsls r3, r4, #2\n"
        "    adds r1, r3, r2\n"
        "    ldrh r1, [r1]\n"
        "    add r1, r8\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #4]\n"
        "    adds r2, #2\n"
        "    adds r3, r3, r2\n"
        "    ldrh r1, [r3]\n"
        "    adds r1, r7, r1\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp, #8]\n"
        "    movs r1, #7\n"
        "    movs r2, #0\n"
        "    movs r3, #1\n"
        "    bl Sprite_DrawSingle\n"
        ".L080C6E18:\n"
        "    add sp, #0xc\n"
        "    pop {r3, r4}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080C6E28: .4byte gUnknown_0834A26C\n"
        ".L080C6E2C: .4byte gUnknown_0834A2A4\n"
    );
}
#endif

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
#ifdef NONMATCHING
void Party_BuildMemberNameTiles(void)
{
    s32 i, j;

    for (i = 0; i <= 5; i++)
    {
        struct Combatant *c = Party_GetMember(i);

        if (c != NULL)
        {
            u32 *p = (u32 *)((i << 8) + 0x020399E4);

            for (j = 0; j <= 7; j++)
            {
                u8 ch = c->name[j];

                if (ch != 0xFF)
                {
                    const u32 *src = gUnknown_081AF7B8[ch].w;

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
#else
NAKED
void Party_BuildMemberNameTiles(void)
{
    asm_unified(
        ".L080C6E78:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    movs r4, #0\n"
        ".L080C6E7C:\n"
        "    lsls r0, r4, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Party_GetMember\n"
        "    adds r6, r4, #1\n"
        "    cmp r0, #0\n"
        "    beq .L080C6EE6\n"
        "    adds r5, r0, #0\n"
        "    lsls r1, r4, #8\n"
        "    ldr r0, .L080C6EC8\n"
        "    adds r2, r1, r0\n"
        "    movs r4, #0\n"
        "    movs r3, #0\n"
        "    ldr r7, .L080C6ECC\n"
        ".L080C6E98:\n"
        "    adds r1, r5, r4\n"
        "    ldrb r0, [r1]\n"
        "    cmp r0, #0xff\n"
        "    beq .L080C6ED0\n"
        "    adds r1, r0, #0\n"
        "    lsls r1, r1, #5\n"
        "    adds r1, r1, r7\n"
        "    ldm r1!, {r0}\n"
        "    stm r2!, {r0}\n"
        "    ldm r1!, {r0}\n"
        "    stm r2!, {r0}\n"
        "    ldm r1!, {r0}\n"
        "    stm r2!, {r0}\n"
        "    ldm r1!, {r0}\n"
        "    stm r2!, {r0}\n"
        "    ldm r1!, {r0}\n"
        "    stm r2!, {r0}\n"
        "    ldm r1!, {r0}\n"
        "    stm r2!, {r0}\n"
        "    ldm r1!, {r0}\n"
        "    stm r2!, {r0}\n"
        "    ldr r0, [r1]\n"
        "    stm r2!, {r0}\n"
        "    b .L080C6EE0\n"
        ".L080C6EC8: .4byte 0x020399E4 @ EWRAM+0x399E4\n"
        ".L080C6ECC: .4byte gUnknown_081AF7B8\n"
        ".L080C6ED0:\n"
        "    stm r2!, {r3}\n"
        "    stm r2!, {r3}\n"
        "    stm r2!, {r3}\n"
        "    stm r2!, {r3}\n"
        "    stm r2!, {r3}\n"
        "    stm r2!, {r3}\n"
        "    stm r2!, {r3}\n"
        "    stm r2!, {r3}\n"
        ".L080C6EE0:\n"
        "    adds r4, #1\n"
        "    cmp r4, #7\n"
        "    ble .L080C6E98\n"
        ".L080C6EE6:\n"
        "    adds r4, r6, #0\n"
        "    cmp r4, #5\n"
        "    ble .L080C6E7C\n"
        "    ldr r0, .L080C6EFC\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080C6EFC: .4byte sub_080C6E54\n"
    );
}
#endif

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
#ifdef NONMATCHING
void Hud_LoadMemberFace(u16 i)
{
    if (Party_GetMember(i) != NULL)
    {
        const u32 *src = gUnknown_081A81B8;
        u32 *dst = (u32 *)((i << 7) + 0x02039FE4);
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
#else
NAKED
void Hud_LoadMemberFace(u16 i)
{
    asm_unified(
        ".L080C6F30:\n"
        "    push {r4, r5, r6, lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    adds r0, r5, #0\n"
        "    bl Party_GetMember\n"
        "    cmp r0, #0\n"
        "    beq .L080C6F9E\n"
        "    ldr r6, .L080C6FA4\n"
        "    lsls r1, r5, #7\n"
        "    ldr r0, .L080C6FA8\n"
        "    adds r4, r1, r0\n"
        "    lsls r0, r5, #0x10\n"
        "    asrs r0, r0, #0x10\n"
        "    bl Hud_GetMemberFace\n"
        "    ldr r1, .L080C6FAC\n"
        "    lsls r0, r0, #0x10\n"
        "    asrs r0, r0, #0xd\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    lsls r0, r0, #2\n"
        "    adds r6, r0, r6\n"
        "    movs r1, #0\n"
        ".L080C6F60:\n"
        "    ldm r6!, {r0}\n"
        "    stm r4!, {r0}\n"
        "    ldm r6!, {r0}\n"
        "    stm r4!, {r0}\n"
        "    ldm r6!, {r0}\n"
        "    stm r4!, {r0}\n"
        "    ldm r6!, {r0}\n"
        "    stm r4!, {r0}\n"
        "    ldm r6!, {r0}\n"
        "    stm r4!, {r0}\n"
        "    ldm r6!, {r0}\n"
        "    stm r4!, {r0}\n"
        "    ldm r6!, {r0}\n"
        "    stm r4!, {r0}\n"
        "    ldm r6!, {r0}\n"
        "    stm r4!, {r0}\n"
        "    adds r1, #1\n"
        "    cmp r1, #3\n"
        "    bls .L080C6F60\n"
        "    ldr r0, .L080C6FB0\n"
        "    adds r4, r0, #0\n"
        "    adds r4, #0x6e\n"
        "    ldrh r0, [r4]\n"
        "    cmp r0, #0\n"
        "    bne .L080C6F9E\n"
        "    ldr r0, .L080C6FB4\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    movs r0, #1\n"
        "    strh r0, [r4]\n"
        ".L080C6F9E:\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080C6FA4: .4byte gUnknown_081A81B8\n"
        ".L080C6FA8: .4byte 0x02039FE4 @ EWRAM+0x39FE4\n"
        ".L080C6FAC: .4byte gUnknown_0834A2EC\n"
        ".L080C6FB0: .4byte 0x0200E7D4 @ EWRAM+0xE7D4\n"
        ".L080C6FB4: .4byte sub_080C6F00\n"
    );
}
#endif

// sub_080C6FB8 @ 0x080C6FB8
u32 sub_080C6FB8(u16 slot)
{
    return gUnknown_0834A2EC[Hud_GetMemberFace(slot)].palette;
}
