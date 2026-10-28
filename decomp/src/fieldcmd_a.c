#include "global.h"
#include "fieldcmd.h"

// sub_080B89B0 @ 0x080B89B0
void sub_080B89B0(struct Task *task, u32 step)
{
    if (step == 0)
    {
        Palette_FillWithEffect(3, task->data.h[0], &gPaletteBuffer[0xE0], 0x40, 0x10);
        Palette_FillWithEffect(3, task->data.h[0], &gPaletteBuffer[0xD0], 0x20, 0x10);
    }
    else if (step == 1)
    {
        if (!FieldMap_HasRecordRel(0, 0, 6))
        {
            Palette_CopyWithEffect(3, gUnk_03004630, &gPaletteBuffer[0xE0], 0x40, 0x20);
            Palette_CopyWithEffect(3, gUnk_03004510, &gPaletteBuffer[0xD0], 0x20, 0x20);
        }
        else
        {
            Palette_CopyWithEffect(3, gUnk_0200F814, &gPaletteBuffer[0xE0], 0x40, 0x20);
            Palette_CopyWithEffect(3, gUnk_0200F7F4, &gPaletteBuffer[0xD0], 0x20, 0x20);
        }
    }
    else if (step == 2)
    {
        DmaFill16(3, task->data.h[0], &gPaletteBuffer[0x80], 0x100);
    }
    else
    {
        u16 *pal = sub_080C5F60(gUnk_03004534);

        if (gUnk_03004534 == 0xDA)
            Palette_CopyWithEffect(3, pal, &gPaletteBuffer[0x70], 0x20, 0x20);
        else
            Palette_CopyWithEffect(3, pal, &gPaletteBuffer[0x80], 0x100, 0x20);
    }
    Palette_MarkDirty();
}

// sub_080B8AC0 @ 0x080B8AC0
void sub_080B8AC0(struct Task *task)
{
    u16 *d = task->data.h;

    if (--d[1] == 0)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080B8AE0 @ 0x080B8AE0
struct Task *sub_080B8AE0(u16 a, u16 b)
{
    struct Task *t = Task_Create(gUnknown_08164EDC, 0xFFFF);

    t->data.h[0] = a;
    t->data.h[1] = b;
    return t;
}

// sub_080B8B08 @ 0x080B8B08
u32 sub_080B8B08(struct Task *t)
{
    u32 done = 0;

    if (t->state == 0)
        done = 1;
    return done;
}

// sub_080B8B1C @ 0x080B8B1C
void sub_080B8B1C(struct Task *task, u32 step)
{
    u16 *dst = &gPaletteBuffer[0x1B0];

    if (step == 0)
        Palette_FillWithEffect(3, 0x3E0, dst, 0x20, 0x10);
    else if (step == 1)
        Palette_FillWithEffect(3, 0x1F, dst, 0x20, 0x10);
    else
        Palette_CopyWithEffect(3, gUnknown_081BB7B0, dst, 0x20, 0x20);
    Palette_MarkDirty();
}

// sub_080B8B68 @ 0x080B8B68
struct Task *sub_080B8B68(u16 a, u16 b)
{
    struct Task *t = Task_Create(gUnknown_08164F78, 0xFFFF);

    t->data.h[0] = a;
    t->data.h[1] = b;
    return t;
}

// sub_080B8B90 @ 0x080B8B90
void sub_080B8B90(struct Task *task)
{
    if (task->data.h[2] == 0)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080B8BA8 @ 0x080B8BA8
void sub_080B8BA8(struct Task *task)
{
    u32 color;

    switch (((u16 *)task->data.w[0])[1])
    {
    case 0:
    case 3:
    case 4:
        color = 0x7C1F;
        break;
    case 1:
        color = 0x7C00;
        break;
    case 2:
        color = 0x1F;
        break;
    }
    sub_080B8874(task, 0, color, 1);
}

// sub_080B8BF8 @ 0x080B8BF8
void sub_080B8BF8(struct Task *task)
{
    task->unk1E = ((u16 *)task->data.w[0])[1];
}

// sub_080B8C00 @ 0x080B8C00
void sub_080B8C00(struct Task *task)
{
    u32 i;

    for (i = 0; i <= 5; i++)
        task->data.h[4 + i] = 0;
}

// sub_080B8C18 @ 0x080B8C18
u32 sub_080B8C18(u16 mode)
{
    u16 min = 0x7FFF;
    u32 best = 0;
    u16 i;

    for (i = 0; i <= 5; i++)
    {
        u8 *e = Party_GetMember(i);
        u16 v;

        if (e == NULL || Combatant_IsDead(e[0xC]))
            continue;
        if (mode == 0)
            v = (s8)e[0x44];
        else
            v = (s8)e[0x40];
        if (min >= v)
        {
            min = v;
            best = e[0xC];
        }
    }
    return best;
}

// sub_080B8C7C @ 0x080B8C7C
void sub_080B8C7C(struct Task *task, u32 slot, u32 apply)
{
    u8 *e = Party_GetMember(slot);
    u32 id, id2;

    s32 v;

    task->result = 0;
    if (e == NULL)
        return;
    id = e[0xC];
    id2 = id;
    if (HEAL_DATA(task)->params[1] == 0)
    {
        v = Combatant_IsUsed(id);
        if (v != 1 || Combatant_IsDead(id) || apply)
            return;
        if ((u16)sub_080B8C18(0) != id)
            return;
        if (Combatant_GetStatus(id) & 4)
            return;
        if (!(Random_Byte() & v))
            return;
        Combatant_SetStatus(id, 4);
        sub_080C8490(slot);
        HEAL_DATA(task)->amount[slot] = v;
    }
    else if (HEAL_DATA(task)->params[1] == 1 || HEAL_DATA(task)->params[1] == 2)
    {
        v = 0;
        if (HEAL_DATA(task)->params[1] == 1)
            v = 2;
        if (Combatant_IsUsed(id) != 1 || Combatant_IsDead(id))
            return;
        if (!apply)
        {
            if (Combatant_GetAlignment(id) == v)
                return;
            v = (Battle_GetMaxHp(id) * 38) >> 7;
            if (v == 0)
                v = 1;
            if (v > Battle_GetHp(id))
                v = Battle_GetHp(id);
            HEAL_DATA(task)->amount[slot] = v;
        }
        else
        {
            v = HEAL_DATA(task)->amount[slot];
            if (v == 0)
                return;
            if (Battle_GetHp(id) == 1)
                Combatant_Damage(id, v);
            else
                Combatant_Damage(id, v);
            sub_080C8490(slot);
            sub_080C86F4(slot);
            task->result = 1;
        }
    }
    else if (HEAL_DATA(task)->params[1] == 3)
    {
        s32 ok = Combatant_IsUsed(id);

        if (ok != 1 || Combatant_IsDead(id))
            return;
        if (!apply)
        {
            HEAL_DATA(task)->amount[slot] = ok;
        }
        else
        {
            v = Battle_GetMaxHp(id);
            v = (v * 12) >> 7;
            if (v == 0)
                v = 1;
            Combatant_Damage(id, v);
            HEAL_DATA(task)->amount[slot] = v;
            task->result = ok;
            sub_080C8490(slot);
        }
    }
    else if (HEAL_DATA(task)->params[1] == 4)
    {
        s32 ok = Combatant_IsUsed(id2);

        if (ok != 1 || Combatant_IsDead(id2) || apply)
            return;
        v = (u16)sub_080B8C18(1);
        if (v != id2)
            return;
        if (Combatant_GetStatus(v) & 0x1000)
            return;
        if (!(Random_Byte() & ok))
            return;
        Combatant_SetStatus(v, 0x1000);
        sub_080C8490(slot);
        HEAL_DATA(task)->amount[slot] = ok;
    }
}

// sub_080B8E88 @ 0x080B8E88
void sub_080B8E88(struct Task *task)
{
    u16 i;

    task->result = 0;
    for (i = 0; i <= 5; i++)
    {
        if (HEAL_DATA(task)->amount[i] != 0)
        {
            task->result = 1;
            return;
        }
    }
}

// sub_080B8EB8 @ 0x080B8EB8
void sub_080B8EB8(struct Task *task, u32 slot)
{
    struct HealData *d = HEAL_DATA(task);
    u8 *e = Party_GetMember(slot);
    u16 *buf = gMenuState;

    Text_CopyToMenuBuffer(gUnknown_080034EA);
    sub_080B832C(task, buf);
    switch (e[0xC])
    {
    case 0:
        buf[0] = 0x31A;
        break;
    case 1:
        buf[0] = 0x31D;
        break;
    case 2:
        buf[0] = 0x31B;
        break;
    case 3:
        buf[0] = 0x31C;
        break;
    default:
        buf[0] = 0x31E;
        gUnk_0203DB28[0] = *(u16 *)(e + 0x12);
        break;
    }
    gUnk_0203DB2C = d->amount[slot];
}

// sub_080B8F5C @ 0x080B8F5C
void sub_080B8F5C(struct Task *task, u32 slot)
{
    struct HealData *d = HEAL_DATA(task);
    u8 *e = Party_GetMember(slot);

    switch (e[0xC])
    {
    case 0:
        sub_080B832C(task, gUnknown_08003432);
        break;
    case 1:
        sub_080B832C(task, gUnknown_08003452);
        break;
    case 2:
        sub_080B832C(task, gUnknown_08003472);
        break;
    case 3:
        sub_080B832C(task, gUnknown_08003492);
        break;
    default:
        sub_080B832C(task, gUnknown_080034B2);
        gUnk_0203DB28[0] = *(u16 *)(e + 0x12);
        break;
    }
    gUnk_0203DB2C = d->amount[slot];
}

// sub_080B8FE4 @ 0x080B8FE4
void sub_080B8FE4(void)
{
    Field_SetState(1);
}

// sub_080B8FF0 @ 0x080B8FF0
struct Task *sub_080B8FF0(u32 a, u16 b)
{
    struct Task *t = Task_Create(gUnknown_08164FD0, 0xFFFF);

    t->data.w[0] = a;
    t->data.h[2] = b;
    return t;
}

// sub_080B9014 @ 0x080B9014
struct Task *sub_080B9014(u32 a, u16 b)
{
    struct Task *t = Task_Create(gUnknown_0816514C, 0xFFFF);

    t->data.w[0] = a;
    t->data.h[2] = b;
    return t;
}

// sub_080B9038 @ 0x080B9038
void sub_080B9038(struct Task *task)
{
    u32 *d = task->data.w;

    gUnk_0200E7D4[0x1A] = 1;
    d[1] = (u32)PalFade_FadeToBlack(4);
}

// sub_080B9058 @ 0x080B9058
void sub_080B9058(void)
{
    Task_Create(gUnknown_081651B4, 0xFFFF);
}

// sub_080B9070 @ 0x080B9070
void sub_080B9070(void)
{
    sub_080AF060(gUnknown_0807CF14);
}

// sub_080B9080 @ 0x080B9080
void sub_080B9080(void)
{
    Task_Create(gUnknown_081651E8, 0xFFFF);
}

// sub_080B9098 @ 0x080B9098
void sub_080B9098(struct Task *task, u32 mask)
{
    if (gFieldState.unk5C & mask)
    {
        gFieldState.unk5C &= ~mask;
        task->result = 1;
    }
    else
    {
        task->result = 0;
    }
}

// sub_080B90C0 @ 0x080B90C0
void sub_080B90C0(void)
{
    sub_080AF1E8(0x1A);
}

// sub_080B90CC @ 0x080B90CC
void sub_080B90CC(struct Task *task)
{
    if (gFieldState.unk00 == 0x1A)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080B90E8 @ 0x080B90E8
void sub_080B90E8(void)
{
    Field_SetState(1);
}

// sub_080B90F4 @ 0x080B90F4
void sub_080B90F4(void)
{
    Task_Create(gUnknown_0816522C, 0xFFFF);
}

// sub_080B910C @ 0x080B910C
void sub_080B910C(struct Task *task)
{
    u32 *d = task->data.w;

    d[2] = Window_Create(2, 0xB, 0x1A, 2, 0);
}

// sub_080B9130 @ 0x080B9130
void sub_080B9130(struct Task *task)
{
    if (task->data.w[0] & (1 << task->data.w[1]))
        task->result = 1;
    else
        task->result = 0;
}

// sub_080B9150 @ 0x080B9150
/* Draws the name of party member data.w[1] (a combatant name or a demon record name, at
   most 8 glyphs) followed by gUnknown_081652D8 as glyph sprites; A sets the result. */
void sub_080B9150(struct Task *task)
{
    u8 *e = Party_GetMember(task->data.w[1] + 0x8000);
    u16 x = 0x12;
    u16 y = 0x59;
    u16 name[16];
    u32 i;

    task->result = 0;
    if (gKeysNew & 1)
        task->result = 1;
    if (e[0xC] <= 3)
    {
        Combatant_DecodeName(e, name);
        for (i = 0; i < 8 && name[i] != 0; i++)
        {
            FontSprite_DrawGlyph(name[i], 0, 0, x, y);
            x += 12;
        }
    }
    else
    {
        struct DemonRecord *rec = (struct DemonRecord *)Demon_GetRecord(*(u16 *)(e + 0x12));

        for (i = 0; i < 8 && rec->name[i] != 0; i++)
        {
            FontSprite_DrawGlyph(rec->name[i], 0, 0, x, y);
            x += 12;
        }
    }
    Text_DrawSpriteString(gUnknown_081652D8, 0, 0, x, y, 0xC);
}

// sub_080B921C @ 0x080B921C
void sub_080B921C(struct Task *task)
{
    u32 *d = task->data.w;

    d[1]++;
}

// sub_080B9228 @ 0x080B9228
void sub_080B9228(struct Task *task)
{
    Window_Close((void *)task->data.w[2], 0);
}

// sub_080B9238 @ 0x080B9238
void sub_080B9238(void)
{
    Field_SetState(1);
}

// sub_080B9244 @ 0x080B9244
void sub_080B9244(struct Task *task)
{
    if (Party_HasActiveHuman() == 0)
    {
        if (Flag_Test(1))
            sub_080B9080();
        else
            sub_080B9058();
        task->result = 1;
    }
    else
    {
        task->result = 0;
    }
}

// sub_080B9274 @ 0x080B9274
void sub_080B9274(u32 a)
{
    struct Task *t = Task_Create(gUnknown_081652E4, 0xFFFF);

    t->data.w[0] = a;
}

// sub_080B9290 @ 0x080B9290
void sub_080B9290(void)
{
    Field_Step(sub_080B1A1C(gFieldState.unk02));
}

// sub_080B92AC @ 0x080B92AC
void sub_080B92AC(struct Task *task)
{
    task->data.w[0] = (u32)sub_080B80F8();
}

// sub_080B92BC @ 0x080B92BC
void sub_080B92BC(struct Task *task)
{
    s32 r = sub_080B8160(task->data.w[0]);

    if (r != 1)
        r = 0;
    task->result = r;
}

// sub_080B92D4 @ 0x080B92D4
void sub_080B92D4(void)
{
    u32 wall = View_GetWall(0, 0, 0);
    u32 kind = sub_080B2938();

    if (wall == 2)
    {
        VBlankTask_AddCounted(DungeonMap_LoadDoorGfx, 1);
        if (kind == 2)
            VBlankTask_AddCounted(sub_080B34E8, 1);
        else if (kind == 3)
            VBlankTask_AddCounted(sub_080B350C, 1);
    }
    else
    {
        VBlankTask_AddCounted(sub_080AE1FC, 1);
    }
    gFieldState.unk2E = 0x21;
}

// sub_080B9334 @ 0x080B9334
void sub_080B9334(void)
{
    sub_080B2AB0();
}

// sub_080B9340 @ 0x080B9340
void sub_080B9340(struct Task *task)
{
    sub_080B343C(-2);
    if (gFieldState.unk2E == 0)
        task->result = 1;
    else
        task->result = 0;
}

// sub_080B9368 @ 0x080B9368
void sub_080B9368(void)
{
    gUnk_03000038 = 0x3F;
    gUnk_03000039 = 0x3F;
    gUnk_0300003A = 0x3F;
    Field_SetState(1);
}

// sub_080B9390 @ 0x080B9390
#ifdef NONMATCHING
/* The original computes 0x3400 - 0x400 at run time; no spelling found reproduces that. */
void sub_080B9390(void)
{
    u32 off = 0x400;

    DmaFill32(3, 0, (void *)0x06003800, 0x800);
    DmaFill32(3, 0, (void *)0x06008800, 0x3400);
    DmaCopy32(3, (u8 *)0x02005004 + off, (void *)0x06008800, 0x3400 - off);
}
#else
NAKED
void sub_080B9390(void)
{
    asm_unified(
        "    push {r4, lr}\n"
        "    sub sp, #4\n"
        "    movs r2, #0x80\n"
        "    lsls r2, r2, #3\n"
        "    ldr r4, .L080B93E0\n"
        "    adds r4, r4, r2\n"
        "    movs r3, #0\n"
        "    str r3, [sp]\n"
        "    ldr r1, .L080B93E4\n"
        "    mov r0, sp\n"
        "    str r0, [r1]\n"
        "    ldr r0, .L080B93E8\n"
        "    str r0, [r1, #4]\n"
        "    ldr r0, .L080B93EC\n"
        "    str r0, [r1, #8]\n"
        "    ldr r0, [r1, #8]\n"
        "    movs r0, #0xd0\n"
        "    lsls r0, r0, #6\n"
        "    subs r2, r0, r2\n"
        "    str r3, [sp]\n"
        "    mov r0, sp\n"
        "    str r0, [r1]\n"
        "    ldr r3, .L080B93F0\n"
        "    str r3, [r1, #4]\n"
        "    ldr r0, .L080B93F4\n"
        "    str r0, [r1, #8]\n"
        "    ldr r0, [r1, #8]\n"
        "    str r4, [r1]\n"
        "    str r3, [r1, #4]\n"
        "    lsrs r2, r2, #2\n"
        "    movs r0, #0x84\n"
        "    lsls r0, r0, #0x18\n"
        "    orrs r2, r0\n"
        "    str r2, [r1, #8]\n"
        "    ldr r0, [r1, #8]\n"
        "    add sp, #4\n"
        "    pop {r4}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080B93E0: .4byte 0x02005004 @ EWRAM+0x5004\n"
        ".L080B93E4: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080B93E8: .4byte 0x06003800 @ VRAM+0x3800\n"
        ".L080B93EC: .4byte 0x85000200\n"
        ".L080B93F0: .4byte 0x06008800 @ VRAM+0x8800\n"
        ".L080B93F4: .4byte 0x85000D00\n"
    );
}
#endif

// sub_080B93F8 @ 0x080B93F8
void sub_080B93F8(void)
{
    VBlankTask_AddCounted(sub_080B9390, 1);
    gUnk_0300000E = 8;
}

// sub_080B9414 @ 0x080B9414
#ifdef NONMATCHING
void sub_080B9414(void)
{
    u32 off = 0x400;

    DmaFill32(3, 0, (void *)0x06003800, 0x800);
    DmaFill32(3, 0, (void *)0x06008800, 0x3400);
    DmaCopy32(3, (void *)0x02005004, (u8 *)0x06008800 + off, 0x3400 - off);
}
#else
NAKED
void sub_080B9414(void)
{
    asm_unified(
        "    push {r4, lr}\n"
        "    sub sp, #4\n"
        "    movs r3, #0x80\n"
        "    lsls r3, r3, #3\n"
        "    ldr r4, .L080B9464\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    ldr r2, .L080B9468\n"
        "    mov r0, sp\n"
        "    str r0, [r2]\n"
        "    ldr r0, .L080B946C\n"
        "    str r0, [r2, #4]\n"
        "    ldr r0, .L080B9470\n"
        "    str r0, [r2, #8]\n"
        "    ldr r0, [r2, #8]\n"
        "    str r1, [sp]\n"
        "    mov r0, sp\n"
        "    str r0, [r2]\n"
        "    ldr r1, .L080B9474\n"
        "    str r1, [r2, #4]\n"
        "    ldr r0, .L080B9478\n"
        "    str r0, [r2, #8]\n"
        "    ldr r0, [r2, #8]\n"
        "    str r4, [r2]\n"
        "    adds r1, r3, r1\n"
        "    str r1, [r2, #4]\n"
        "    movs r0, #0xd0\n"
        "    lsls r0, r0, #6\n"
        "    subs r0, r0, r3\n"
        "    lsrs r0, r0, #2\n"
        "    movs r1, #0x84\n"
        "    lsls r1, r1, #0x18\n"
        "    orrs r0, r1\n"
        "    str r0, [r2, #8]\n"
        "    ldr r0, [r2, #8]\n"
        "    add sp, #4\n"
        "    pop {r4}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080B9464: .4byte 0x02005004 @ EWRAM+0x5004\n"
        ".L080B9468: .4byte 0x040000D4 @ REG_DMA3SAD\n"
        ".L080B946C: .4byte 0x06003800 @ VRAM+0x3800\n"
        ".L080B9470: .4byte 0x85000200\n"
        ".L080B9474: .4byte 0x06008800 @ VRAM+0x8800\n"
        ".L080B9478: .4byte 0x85000D00\n"
    );
}
#endif

// sub_080B947C @ 0x080B947C
void sub_080B947C(void)
{
    VBlankTask_AddCounted(sub_080B9414, 1);
    gUnk_0300000E = -8;
}

// sub_080B94A0 @ 0x080B94A0
void sub_080B94A0(void)
{
    VBlankTask_AddCounted(sub_080B2880, 1);
    gUnk_0300000E = 0;
}

// sub_080B94BC @ 0x080B94BC
void sub_080B94BC(struct Task *task)
{
    if (gUnk_0200AB04 & 0x8000)
        task->result = 0;
    else
        task->result = 1;
}
