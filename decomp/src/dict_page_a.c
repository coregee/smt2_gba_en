#include "global.h"
#include "extras.h"

void SmallFont_DrawAscii(const void *str, u32 x, u32 y, u32 a3);
s32 Race_GetParentId(s32 race);
const void *ParentRace_GetName(u16 race);
void Text_DrawStringTinted(const void *str, void *dst, u32 x, u32 y, u32 tint, u32 lineH);
void Font_DrawGlyphTinted(u16 code, void *canvas, u16 x, u16 y, u32 tint);
s32 sub_0815B864(u32 id);
const void *sub_080C06AC(u16 id);
void Status_DrawSkillName(u32 id, u32 x, u16 y);
void Canvas_BlitOr(const void *src, void *dst, u32 a2, u32 a3, u32 x, u32 y, u32 w, u32 h);
void Combatant_InitDemon(void *c, s32 who, u16 demonId);
void DigitFont_DrawAscii(const void *str, u32 x, u32 y, u32 a3);
void DigitFont_DrawNumber(s32 value, u32 x, u32 y, u32 color);
u16 sub_080DC6C8(u16 id);
void sub_080DC6A4(void);
extern const u8 gUnknown_08583A58[], gUnknown_08583A60[], gUnknown_08583A68[];
extern const u8 gUnknown_08583A70[], gUnknown_08583A74[], gUnknown_08583A78[], gUnknown_08583A7C[];
extern const u8 gUnknown_08583A28[3][16];
extern const u8 gUnknown_081B1DB8[], gUnknown_081B1D98[], gUnknown_081B6ED0[];
extern u8 gUnk_030030B0[];

#define CANVAS gUnk_0200F874

/* Draws the compendium page of the selected demon (gDict.selected through sub_080DC6C8) into
   the sprite canvas gUnk_0200F874, uploaded by sub_080DC6A4. Page 0: parent race and race
   names, the demon's name (8 glyphs of 12 pixels from record +0x22), a race-group label
   (race < 13, < 27, else), the sub_080C06AC text and up to 7 skills (record +0x11, 0xFF =
   none, drawn as 8 dashes). Page 1: level, HP, MP and record +0x1D, the six stats (record
   +6..+0xB, kanji labels as glyph ids), and four values computed by Combatant_InitDemon into
   the combatant at gMenuState + 0x88. */
/* NONMATCHING: same code shape; gcc keeps different constants (4, 0x96) in callee-saved
   registers, so the combatant pointer is not spilled and registers shift. */
// Dict_DrawDemonPage @ 0x080DC6D0
#ifdef NONMATCHING
void Dict_DrawDemonPage(struct Task *task, u32 page)
{
    u16 y = 0;
    s8 *rec;
    u8 *skills;
    u32 zero;
    u32 i, j;
    u32 x, ny;
    u16 *name;
    const void *str;

    rec = (s8 *)Demon_GetRecord(sub_080DC6C8(gDict.selected));
    skills = (u8 *)rec + 0x11;
    gUnk_03000038 |= 0x3F;
    zero = y;
    CpuSet(&zero, CANVAS, 0x05002000);
    if (page == 0)
    {
        SmallFont_DrawAscii(gUnknown_08583A58, 0, 2, 4);
        str = ParentRace_GetName(Race_GetParentId(rec[0]));
        if (str != NULL)
            Text_DrawStringTinted(str, CANVAS, 4, 0xE, y, 12);
        str = Race_GetName(rec[0]);
        if (str != NULL)
            Text_DrawStringTinted(str, CANVAS, 4, 0x1D, y, 12);
        ny = 0x2C;
        x = 4;
        name = (u16 *)(rec + 0x22);
        for (i = 0; i < 8; i++)
        {
            Font_DrawGlyphTinted(*name, CANVAS, x, ny, 0);
            x += 12;
            name++;
        }
        if (rec[0] <= 12)
            str = gUnknown_08583A28[0];
        else if (rec[0] <= 26)
            str = gUnknown_08583A28[1];
        else
            str = gUnknown_08583A28[2];
        Text_DrawStringTinted(str, CANVAS, 4, 0x3B, 0, 12);
        str = sub_080C06AC(sub_0815B864(gDict.selected));
        if (str != NULL)
            Text_DrawStringTinted(str, CANVAS, 4, 0x4B, 0, 12);
        SmallFont_DrawAscii(gUnknown_08583A60, 0x6A, 2, 4);
        for (i = 0; i < 7; i++)
        {
            if (skills[i] != 0xFF)
            {
                Status_DrawSkillName(skills[i], 0x6E, y + 14);
                y += 15;
            }
        }
        for (i = 0; i < 7; i++)
        {
            if (skills[i] == 0xFF)
            {
                for (j = 0; j < 8; j++)
                    Font_DrawGlyphTinted(0x3C, CANVAS, 0x6E + j * 12, y + 14, 0);
                y += 15;
            }
        }
        Canvas_BlitOr(gUnknown_081B1DB8, CANVAS, 0, 0, 0x96, 0x80, 8, 8);
    }
    else
    {
        u8 *c = (u8 *)&gMenuState;

        Combatant_InitDemon(c + 0x88, 4, sub_080DC6C8(gDict.selected));
        SmallFont_DrawAscii(gUnknown_08583A68, 0, 2, 4);
        DigitFont_DrawAscii(gUnknown_08583A70, 4, 0x10, 4);
        DigitFont_DrawNumber(((u8 *)rec)[1], 0x45, 0x10, 0);
        DigitFont_DrawAscii(gUnknown_08583A74, 4, 0x1F, 4);
        DigitFont_DrawNumber(*(s16 *)(rec + 2), 0x45, 0x1F, 0);
        DigitFont_DrawAscii(gUnknown_08583A78, 4, 0x2E, 4);
        DigitFont_DrawNumber(*(s16 *)(rec + 4), 0x45, 0x2E, 0);
        DigitFont_DrawAscii(gUnknown_08583A7C, 4, 0x3D, 4);
        DigitFont_DrawNumber(((u8 *)rec)[0x1D], 0x45, 0x3D, 0);
        Font_DrawGlyphTinted(0x10CB, CANVAS, 0x55, 0xE, 4);
        DigitFont_DrawNumber(rec[6], 0x6D, 0x11, 0);
        Font_DrawGlyphTinted(0xCBA, CANVAS, 0x7E, 0xE, 4);
        DigitFont_DrawNumber(rec[7], 0x96, 0x11, 0);
        Font_DrawGlyphTinted(0xFC3, CANVAS, 0x55, 0x1D, 4);
        DigitFont_DrawNumber(rec[8], 0x6D, 0x20, 0);
        Font_DrawGlyphTinted(0xC5C, CANVAS, 0x7E, 0x1D, 4);
        DigitFont_DrawNumber(rec[9], 0x96, 0x20, 0);
        Font_DrawGlyphTinted(0xC3C, CANVAS, 0x55, 0x2C, 4);
        DigitFont_DrawNumber(rec[10], 0x6D, 0x2F, 0);
        Font_DrawGlyphTinted(0x606, CANVAS, 0x7E, 0x2C, 4);
        DigitFont_DrawNumber(rec[11], 0x96, 0x2F, 0);
        Font_DrawGlyphTinted(0x8F1, CANVAS, 4, 0x50, 4);
        Font_DrawGlyphTinted(0x861, CANVAS, 0x10, 0x50, 4);
        DigitFont_DrawNumber(*(s16 *)(c + 0xD0), 0x45, 0x52, 0);
        Font_DrawGlyphTinted(0xFFE, CANVAS, 4, 0x5F, 4);
        Font_DrawGlyphTinted(0xCD3, CANVAS, 0x10, 0x5F, 4);
        DigitFont_DrawNumber(*(s16 *)(c + 0xD2), 0x45, 0x61, 0);
        Font_DrawGlyphTinted(0xFA9, CANVAS, 4, 0x6E, 4);
        Font_DrawGlyphTinted(0x8C3, CANVAS, 0x10, 0x6E, 4);
        DigitFont_DrawNumber(*(s16 *)(c + 0xD8), 0x45, 0x70, 0);
        Font_DrawGlyphTinted(0x699, CANVAS, 4, 0x7D, 4);
        Font_DrawGlyphTinted(0xEB7, CANVAS, 0x10, 0x7D, 4);
        DigitFont_DrawNumber(*(s16 *)(c + 0xDA), 0x45, 0x7F, 0);
        Font_DrawGlyphTinted(0xFC3, CANVAS, 0x55, 0x50, 4);
        Font_DrawGlyphTinted(0xF81, CANVAS, 0x61, 0x50, 4);
        Font_DrawGlyphTinted(0x5BB, CANVAS, 0x6D, 0x50, 4);
        Font_DrawGlyphTinted(0x10CB, CANVAS, 0x79, 0x50, 4);
        DigitFont_DrawNumber(*(s16 *)(c + 0xDC), 0x96, 0x52, 0);
        Font_DrawGlyphTinted(0xFC3, CANVAS, 0x55, 0x5F, 4);
        Font_DrawGlyphTinted(0xF81, CANVAS, 0x61, 0x5F, 4);
        Font_DrawGlyphTinted(0x8D7, CANVAS, 0x6D, 0x5F, 4);
        Font_DrawGlyphTinted(0x672, CANVAS, 0x79, 0x5F, 4);
        DigitFont_DrawNumber(*(s16 *)(c + 0xDE), 0x96, 0x61, 0);
        Canvas_BlitOr(gUnknown_081B1D98, CANVAS, 0, 0, 0x96, 5, 8, 8);
    }
    Palette_CopyWithEffect(3, gUnknown_081B6ED0, gUnk_030030B0, 0x20, 0x20);
    Palette_MarkDirty();
    VBlankTask_AddCounted(sub_080DC6A4, 1);
}
#else
NAKED
void Dict_DrawDemonPage(struct Task *task, u32 page)
{
    asm_unified(
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x1c\n"
        "    adds r4, r1, #0\n"
        "    movs r0, #0\n"
        "    mov sb, r0\n"
        "    ldr r5, .L080DC7B4\n"
        "    ldrh r0, [r5, #0x38]\n"
        "    bl sub_080DC6C8\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Demon_GetRecord\n"
        "    adds r7, r0, #0\n"
        "    adds r1, r7, #0\n"
        "    adds r1, #0x11\n"
        "    str r1, [sp, #0x14]\n"
        "    ldr r2, .L080DC7B8\n"
        "    ldrb r0, [r2]\n"
        "    movs r1, #0x3f\n"
        "    orrs r0, r1\n"
        "    strb r0, [r2]\n"
        "    mov r6, sb\n"
        "    str r6, [sp, #0x10]\n"
        "    ldr r0, .L080DC7BC\n"
        "    mov sl, r0\n"
        "    ldr r2, .L080DC7C0\n"
        "    add r0, sp, #0x10\n"
        "    mov r1, sl\n"
        "    bl CpuSet\n"
        "    cmp r4, #0\n"
        "    beq .L080DC71C\n"
        "    b .L080DC8C4\n"
        ".L080DC71C:\n"
        "    ldr r0, .L080DC7C4\n"
        "    movs r1, #0\n"
        "    movs r2, #2\n"
        "    movs r3, #4\n"
        "    bl SmallFont_DrawAscii\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r7, r0]\n"
        "    bl Race_GetParentId\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl ParentRace_GetName\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #0\n"
        "    beq .L080DC750\n"
        "    str r6, [sp]\n"
        "    movs r0, #0xc\n"
        "    str r0, [sp, #4]\n"
        "    adds r0, r1, #0\n"
        "    mov r1, sl\n"
        "    movs r2, #4\n"
        "    movs r3, #0xe\n"
        "    bl Text_DrawStringTinted\n"
        ".L080DC750:\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r7, r0]\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl Race_GetName\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #0\n"
        "    beq .L080DC776\n"
        "    mov r6, sb\n"
        "    str r6, [sp]\n"
        "    movs r0, #0xc\n"
        "    str r0, [sp, #4]\n"
        "    adds r0, r1, #0\n"
        "    mov r1, sl\n"
        "    movs r2, #4\n"
        "    movs r3, #0x1d\n"
        "    bl Text_DrawStringTinted\n"
        ".L080DC776:\n"
        "    movs r5, #0\n"
        "    movs r0, #0xb0\n"
        "    lsls r0, r0, #0xe\n"
        "    mov r8, r0\n"
        "    movs r1, #4\n"
        "    mov sl, r1\n"
        "    adds r4, r7, #0\n"
        "    adds r4, #0x22\n"
        ".L080DC786:\n"
        "    ldrh r0, [r4]\n"
        "    mov r6, sl\n"
        "    lsls r2, r6, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    movs r1, #0\n"
        "    str r1, [sp]\n"
        "    ldr r1, .L080DC7BC\n"
        "    mov r6, r8\n"
        "    lsrs r3, r6, #0x10\n"
        "    bl Font_DrawGlyphTinted\n"
        "    movs r0, #0xc\n"
        "    add sl, r0\n"
        "    adds r4, #2\n"
        "    adds r5, #1\n"
        "    cmp r5, #7\n"
        "    bls .L080DC786\n"
        "    movs r0, #0\n"
        "    ldrsb r0, [r7, r0]\n"
        "    cmp r0, #0xc\n"
        "    bgt .L080DC7CC\n"
        "    ldr r1, .L080DC7C8\n"
        "    b .L080DC7D4\n"
        ".L080DC7B4: .4byte 0x020399E0 @ EWRAM+0x399E0\n"
        ".L080DC7B8: .4byte 0x03000038 @ IWRAM+0x38\n"
        ".L080DC7BC: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L080DC7C0: .4byte 0x05002000\n"
        ".L080DC7C4: .4byte gUnknown_08583A58\n"
        ".L080DC7C8: .4byte gUnknown_08583A28\n"
        ".L080DC7CC:\n"
        "    ldr r1, .L080DC8B0\n"
        "    cmp r0, #0x1a\n"
        "    bgt .L080DC7D4\n"
        "    subs r1, #0x10\n"
        ".L080DC7D4:\n"
        "    ldr r7, .L080DC8B4\n"
        "    movs r4, #4\n"
        "    movs r3, #0x3b\n"
        "    movs r6, #0\n"
        "    str r6, [sp]\n"
        "    movs r5, #0xc\n"
        "    str r5, [sp, #4]\n"
        "    adds r0, r1, #0\n"
        "    adds r1, r7, #0\n"
        "    adds r2, r4, #0\n"
        "    bl Text_DrawStringTinted\n"
        "    ldr r0, .L080DC8B8\n"
        "    ldr r0, [r0, #0x38]\n"
        "    bl sub_0815B864\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    bl sub_080C06AC\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #0\n"
        "    beq .L080DC810\n"
        "    movs r3, #0x4b\n"
        "    str r6, [sp]\n"
        "    str r5, [sp, #4]\n"
        "    adds r1, r7, #0\n"
        "    adds r2, r4, #0\n"
        "    bl Text_DrawStringTinted\n"
        ".L080DC810:\n"
        "    ldr r0, .L080DC8BC\n"
        "    movs r1, #0x6a\n"
        "    movs r2, #2\n"
        "    movs r3, #4\n"
        "    bl SmallFont_DrawAscii\n"
        "    movs r5, #0\n"
        ".L080DC81E:\n"
        "    ldr r1, [sp, #0x14]\n"
        "    adds r0, r1, r5\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0xff\n"
        "    beq .L080DC840\n"
        "    mov r2, sb\n"
        "    adds r2, #0xe\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    movs r1, #0x6e\n"
        "    bl Status_DrawSkillName\n"
        "    mov r0, sb\n"
        "    adds r0, #0xf\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sb, r0\n"
        ".L080DC840:\n"
        "    adds r5, #1\n"
        "    cmp r5, #6\n"
        "    bls .L080DC81E\n"
        "    movs r5, #0\n"
        "    ldr r2, .L080DC8B4\n"
        ".L080DC84A:\n"
        "    ldr r6, [sp, #0x14]\n"
        "    adds r0, r6, r5\n"
        "    ldrb r0, [r0]\n"
        "    adds r5, #1\n"
        "    mov r8, r5\n"
        "    cmp r0, #0xff\n"
        "    bne .L080DC88C\n"
        "    movs r5, #0\n"
        "    mov r0, sb\n"
        "    adds r0, #0xe\n"
        "    mov r7, sb\n"
        "    adds r7, #0xf\n"
        "    lsls r6, r0, #0x10\n"
        "    movs r0, #0x6e\n"
        "    lsls r4, r0, #0x10\n"
        ".L080DC868:\n"
        "    lsrs r2, r4, #0x10\n"
        "    movs r0, #0\n"
        "    str r0, [sp]\n"
        "    movs r0, #0x3c\n"
        "    ldr r1, .L080DC8B4\n"
        "    lsrs r3, r6, #0x10\n"
        "    bl Font_DrawGlyphTinted\n"
        "    movs r1, #0xc0\n"
        "    lsls r1, r1, #0xc\n"
        "    adds r4, r4, r1\n"
        "    adds r5, #1\n"
        "    cmp r5, #7\n"
        "    bls .L080DC868\n"
        "    lsls r0, r7, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov sb, r0\n"
        "    ldr r2, .L080DC8B4\n"
        ".L080DC88C:\n"
        "    mov r5, r8\n"
        "    cmp r5, #6\n"
        "    bls .L080DC84A\n"
        "    ldr r0, .L080DC8C0\n"
        "    movs r1, #0x96\n"
        "    str r1, [sp]\n"
        "    movs r1, #0x80\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #8\n"
        "    str r1, [sp, #8]\n"
        "    str r1, [sp, #0xc]\n"
        "    adds r1, r2, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Canvas_BlitOr\n"
        "    b .L080DCB68\n"
        "    .byte 0x00, 0x00\n"
        ".L080DC8B0: .4byte gUnknown_08583A48\n"
        ".L080DC8B4: .4byte 0x0200F874 @ EWRAM+0xF874\n"
        ".L080DC8B8: .4byte 0x020399E0 @ EWRAM+0x399E0\n"
        ".L080DC8BC: .4byte gUnknown_08583A60\n"
        ".L080DC8C0: .4byte gUnknown_081B1DB8\n"
        ".L080DC8C4:\n"
        "    ldr r6, .L080DCB94\n"
        "    str r6, [sp, #0x18]\n"
        "    adds r4, r6, #0\n"
        "    adds r4, #0x88\n"
        "    ldrh r0, [r5, #0x38]\n"
        "    bl sub_080DC6C8\n"
        "    adds r2, r0, #0\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    adds r0, r4, #0\n"
        "    movs r1, #4\n"
        "    bl Combatant_InitDemon\n"
        "    ldr r0, .L080DCB98\n"
        "    movs r1, #0\n"
        "    movs r2, #2\n"
        "    movs r3, #4\n"
        "    bl SmallFont_DrawAscii\n"
        "    ldr r0, .L080DCB9C\n"
        "    movs r4, #4\n"
        "    movs r1, #4\n"
        "    movs r2, #0x10\n"
        "    movs r3, #4\n"
        "    bl DigitFont_DrawAscii\n"
        "    ldrb r0, [r7, #1]\n"
        "    movs r1, #0x45\n"
        "    movs r2, #0x10\n"
        "    movs r3, #0\n"
        "    bl DigitFont_DrawNumber\n"
        "    ldr r0, .L080DCBA0\n"
        "    movs r1, #4\n"
        "    movs r2, #0x1f\n"
        "    movs r3, #4\n"
        "    bl DigitFont_DrawAscii\n"
        "    movs r1, #2\n"
        "    ldrsh r0, [r7, r1]\n"
        "    movs r1, #0x45\n"
        "    movs r2, #0x1f\n"
        "    movs r3, #0\n"
        "    bl DigitFont_DrawNumber\n"
        "    ldr r0, .L080DCBA4\n"
        "    movs r1, #4\n"
        "    movs r2, #0x2e\n"
        "    movs r3, #4\n"
        "    bl DigitFont_DrawAscii\n"
        "    movs r6, #4\n"
        "    ldrsh r0, [r7, r6]\n"
        "    movs r1, #0x45\n"
        "    movs r2, #0x2e\n"
        "    movs r3, #0\n"
        "    bl DigitFont_DrawNumber\n"
        "    ldr r0, .L080DCBA8\n"
        "    movs r1, #4\n"
        "    movs r2, #0x3d\n"
        "    movs r3, #4\n"
        "    bl DigitFont_DrawAscii\n"
        "    ldrb r0, [r7, #0x1d]\n"
        "    movs r1, #0x45\n"
        "    movs r2, #0x3d\n"
        "    movs r3, #0\n"
        "    bl DigitFont_DrawNumber\n"
        "    ldr r0, .L080DCBAC\n"
        "    mov r8, r0\n"
        "    str r4, [sp]\n"
        "    mov r1, sl\n"
        "    movs r2, #0x55\n"
        "    movs r3, #0xe\n"
        "    bl Font_DrawGlyphTinted\n"
        "    movs r0, #6\n"
        "    ldrsb r0, [r7, r0]\n"
        "    movs r1, #0x6d\n"
        "    movs r2, #0x11\n"
        "    movs r3, #0\n"
        "    bl DigitFont_DrawNumber\n"
        "    ldr r0, .L080DCBB0\n"
        "    str r4, [sp]\n"
        "    mov r1, sl\n"
        "    movs r2, #0x7e\n"
        "    movs r3, #0xe\n"
        "    bl Font_DrawGlyphTinted\n"
        "    movs r0, #7\n"
        "    ldrsb r0, [r7, r0]\n"
        "    movs r1, #0x96\n"
        "    mov sb, r1\n"
        "    movs r2, #0x11\n"
        "    movs r3, #0\n"
        "    bl DigitFont_DrawNumber\n"
        "    ldr r6, .L080DCBB4\n"
        "    str r4, [sp]\n"
        "    adds r0, r6, #0\n"
        "    mov r1, sl\n"
        "    movs r2, #0x55\n"
        "    movs r3, #0x1d\n"
        "    bl Font_DrawGlyphTinted\n"
        "    movs r0, #8\n"
        "    ldrsb r0, [r7, r0]\n"
        "    movs r1, #0x6d\n"
        "    movs r2, #0x20\n"
        "    movs r3, #0\n"
        "    bl DigitFont_DrawNumber\n"
        "    ldr r0, .L080DCBB8\n"
        "    str r4, [sp]\n"
        "    mov r1, sl\n"
        "    movs r2, #0x7e\n"
        "    movs r3, #0x1d\n"
        "    bl Font_DrawGlyphTinted\n"
        "    movs r0, #9\n"
        "    ldrsb r0, [r7, r0]\n"
        "    movs r1, #0x96\n"
        "    movs r2, #0x20\n"
        "    movs r3, #0\n"
        "    bl DigitFont_DrawNumber\n"
        "    ldr r0, .L080DCBBC\n"
        "    str r4, [sp]\n"
        "    mov r1, sl\n"
        "    movs r2, #0x55\n"
        "    movs r3, #0x2c\n"
        "    bl Font_DrawGlyphTinted\n"
        "    movs r0, #0xa\n"
        "    ldrsb r0, [r7, r0]\n"
        "    movs r1, #0x6d\n"
        "    movs r2, #0x2f\n"
        "    movs r3, #0\n"
        "    bl DigitFont_DrawNumber\n"
        "    ldr r0, .L080DCBC0\n"
        "    str r4, [sp]\n"
        "    mov r1, sl\n"
        "    movs r2, #0x7e\n"
        "    movs r3, #0x2c\n"
        "    bl Font_DrawGlyphTinted\n"
        "    movs r0, #0xb\n"
        "    ldrsb r0, [r7, r0]\n"
        "    movs r1, #0x96\n"
        "    movs r2, #0x2f\n"
        "    movs r3, #0\n"
        "    bl DigitFont_DrawNumber\n"
        "    ldr r0, .L080DCBC4\n"
        "    str r4, [sp]\n"
        "    mov r1, sl\n"
        "    movs r2, #4\n"
        "    movs r3, #0x50\n"
        "    bl Font_DrawGlyphTinted\n"
        "    ldr r0, .L080DCBC8\n"
        "    str r4, [sp]\n"
        "    mov r1, sl\n"
        "    movs r2, #0x10\n"
        "    movs r3, #0x50\n"
        "    bl Font_DrawGlyphTinted\n"
        "    ldr r0, [sp, #0x18]\n"
        "    adds r0, #0xd0\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    movs r1, #0x45\n"
        "    movs r2, #0x52\n"
        "    movs r3, #0\n"
        "    bl DigitFont_DrawNumber\n"
        "    ldr r0, .L080DCBCC\n"
        "    str r4, [sp]\n"
        "    mov r1, sl\n"
        "    movs r2, #4\n"
        "    movs r3, #0x5f\n"
        "    bl Font_DrawGlyphTinted\n"
        "    ldr r0, .L080DCBD0\n"
        "    str r4, [sp]\n"
        "    mov r1, sl\n"
        "    movs r2, #0x10\n"
        "    movs r3, #0x5f\n"
        "    bl Font_DrawGlyphTinted\n"
        "    ldr r0, [sp, #0x18]\n"
        "    adds r0, #0xd2\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    movs r1, #0x45\n"
        "    movs r2, #0x61\n"
        "    movs r3, #0\n"
        "    bl DigitFont_DrawNumber\n"
        "    ldr r0, .L080DCBD4\n"
        "    str r4, [sp]\n"
        "    mov r1, sl\n"
        "    movs r2, #4\n"
        "    movs r3, #0x6e\n"
        "    bl Font_DrawGlyphTinted\n"
        "    ldr r0, .L080DCBD8\n"
        "    str r4, [sp]\n"
        "    mov r1, sl\n"
        "    movs r2, #0x10\n"
        "    movs r3, #0x6e\n"
        "    bl Font_DrawGlyphTinted\n"
        "    ldr r0, [sp, #0x18]\n"
        "    adds r0, #0xd8\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    movs r1, #0x45\n"
        "    movs r2, #0x70\n"
        "    movs r3, #0\n"
        "    bl DigitFont_DrawNumber\n"
        "    ldr r0, .L080DCBDC\n"
        "    str r4, [sp]\n"
        "    mov r1, sl\n"
        "    movs r2, #4\n"
        "    movs r3, #0x7d\n"
        "    bl Font_DrawGlyphTinted\n"
        "    ldr r0, .L080DCBE0\n"
        "    str r4, [sp]\n"
        "    mov r1, sl\n"
        "    movs r2, #0x10\n"
        "    movs r3, #0x7d\n"
        "    bl Font_DrawGlyphTinted\n"
        "    ldr r0, [sp, #0x18]\n"
        "    adds r0, #0xda\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    movs r1, #0x45\n"
        "    movs r2, #0x7f\n"
        "    movs r3, #0\n"
        "    bl DigitFont_DrawNumber\n"
        "    str r4, [sp]\n"
        "    adds r0, r6, #0\n"
        "    mov r1, sl\n"
        "    movs r2, #0x55\n"
        "    movs r3, #0x50\n"
        "    bl Font_DrawGlyphTinted\n"
        "    ldr r5, .L080DCBE4\n"
        "    str r4, [sp]\n"
        "    adds r0, r5, #0\n"
        "    mov r1, sl\n"
        "    movs r2, #0x61\n"
        "    movs r3, #0x50\n"
        "    bl Font_DrawGlyphTinted\n"
        "    ldr r0, .L080DCBE8\n"
        "    str r4, [sp]\n"
        "    mov r1, sl\n"
        "    movs r2, #0x6d\n"
        "    movs r3, #0x50\n"
        "    bl Font_DrawGlyphTinted\n"
        "    str r4, [sp]\n"
        "    mov r0, r8\n"
        "    mov r1, sl\n"
        "    movs r2, #0x79\n"
        "    movs r3, #0x50\n"
        "    bl Font_DrawGlyphTinted\n"
        "    ldr r0, [sp, #0x18]\n"
        "    adds r0, #0xdc\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    movs r1, #0x96\n"
        "    movs r2, #0x52\n"
        "    movs r3, #0\n"
        "    bl DigitFont_DrawNumber\n"
        "    str r4, [sp]\n"
        "    adds r0, r6, #0\n"
        "    mov r1, sl\n"
        "    movs r2, #0x55\n"
        "    movs r3, #0x5f\n"
        "    bl Font_DrawGlyphTinted\n"
        "    str r4, [sp]\n"
        "    adds r0, r5, #0\n"
        "    mov r1, sl\n"
        "    movs r2, #0x61\n"
        "    movs r3, #0x5f\n"
        "    bl Font_DrawGlyphTinted\n"
        "    ldr r0, .L080DCBEC\n"
        "    str r4, [sp]\n"
        "    mov r1, sl\n"
        "    movs r2, #0x6d\n"
        "    movs r3, #0x5f\n"
        "    bl Font_DrawGlyphTinted\n"
        "    ldr r0, .L080DCBF0\n"
        "    str r4, [sp]\n"
        "    mov r1, sl\n"
        "    movs r2, #0x79\n"
        "    movs r3, #0x5f\n"
        "    bl Font_DrawGlyphTinted\n"
        "    ldr r0, [sp, #0x18]\n"
        "    adds r0, #0xde\n"
        "    movs r6, #0\n"
        "    ldrsh r0, [r0, r6]\n"
        "    movs r1, #0x96\n"
        "    movs r2, #0x61\n"
        "    movs r3, #0\n"
        "    bl DigitFont_DrawNumber\n"
        "    ldr r0, .L080DCBF4\n"
        "    mov r1, sb\n"
        "    str r1, [sp]\n"
        "    movs r1, #5\n"
        "    str r1, [sp, #4]\n"
        "    movs r1, #8\n"
        "    str r1, [sp, #8]\n"
        "    str r1, [sp, #0xc]\n"
        "    mov r1, sl\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl Canvas_BlitOr\n"
        ".L080DCB68:\n"
        "    ldr r1, .L080DCBF8\n"
        "    ldr r2, .L080DCBFC\n"
        "    movs r0, #0x20\n"
        "    str r0, [sp]\n"
        "    movs r0, #3\n"
        "    movs r3, #0x20\n"
        "    bl Palette_CopyWithEffect\n"
        "    bl Palette_MarkDirty\n"
        "    ldr r0, .L080DCC00\n"
        "    movs r1, #1\n"
        "    bl VBlankTask_AddCounted\n"
        "    add sp, #0x1c\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080DCB94: .4byte 0x0203A454 @ EWRAM+0x3A454\n"
        ".L080DCB98: .4byte gUnknown_08583A68\n"
        ".L080DCB9C: .4byte gUnknown_08583A70\n"
        ".L080DCBA0: .4byte gUnknown_08583A74\n"
        ".L080DCBA4: .4byte gUnknown_08583A78\n"
        ".L080DCBA8: .4byte gUnknown_08583A7C\n"
        ".L080DCBAC: .4byte 0x000010CB\n"
        ".L080DCBB0: .4byte 0x00000CBA\n"
        ".L080DCBB4: .4byte 0x00000FC3\n"
        ".L080DCBB8: .4byte 0x00000C5C\n"
        ".L080DCBBC: .4byte 0x00000C3C\n"
        ".L080DCBC0: .4byte 0x00000606\n"
        ".L080DCBC4: .4byte 0x000008F1\n"
        ".L080DCBC8: .4byte 0x00000861\n"
        ".L080DCBCC: .4byte 0x00000FFE\n"
        ".L080DCBD0: .4byte 0x00000CD3\n"
        ".L080DCBD4: .4byte 0x00000FA9\n"
        ".L080DCBD8: .4byte 0x000008C3\n"
        ".L080DCBDC: .4byte 0x00000699\n"
        ".L080DCBE0: .4byte 0x00000EB7\n"
        ".L080DCBE4: .4byte 0x00000F81\n"
        ".L080DCBE8: .4byte 0x000005BB\n"
        ".L080DCBEC: .4byte 0x000008D7\n"
        ".L080DCBF0: .4byte 0x00000672\n"
        ".L080DCBF4: .4byte gUnknown_081B1D98\n"
        ".L080DCBF8: .4byte gUnknown_081B6ED0\n"
        ".L080DCBFC: .4byte 0x030030B0 @ IWRAM+0x30B0\n"
        ".L080DCC00: .4byte sub_080DC6A4\n"
    );
}
#endif
