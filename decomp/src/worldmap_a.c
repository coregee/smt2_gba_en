#include "global.h"
#include "worldmap.h"

// sub_0815201C @ 0x0815201C
#ifdef NONMATCHING
void sub_0815201C(void)
{
    struct MapRecord *rec;
    struct MapRecord *rec2;
    u16 sx;
    u16 sy;
    u16 bx, by;
    u16 t;
    u32 win;
    const u16 *p;
    u16 *m;

    rec = FieldMap_GetArea(gWorldMap.map);
    switch (gWorldMap.state)
    {
    case 0:
        Task_Create(gUnknown_087DFBA0, 0xFFFF);
        gWorldMap.state = 0x10;
        break;
    case 1:
        WorldMap_HandleInput();
        gWorldMap.unk26 = WorldMap_GetBlocks()->blocks[(gWorldMap.x >> 4) + (gWorldMap.y >> 4) * 64] >> 4;
        break;
    case 2:
    case 13:
        WorldMap_Walk();
        break;
    case 3:
        Task_Create(gUnknown_087DFEF0, 0xFFFF);
        gWorldMap.state = 0x10;
        break;
    case 4:
        Task_Create(gUnknown_087DFF58, 0xFFFF);
        gWorldMap.state = 0x10;
        break;
    case 8:
        Task_Create(gUnknown_087DFFC0, 0xFFFF);
        gWorldMap.state = 0x10;
        break;
    case 9:
        Task_Create(gUnknown_087E0998, 0xFFFF);
        gWorldMap.state = 0x10;
        break;
    case 10:
        Task_Create(gUnknown_087E0DA0, 0xFFFF);
        gWorldMap.state = 0x10;
        gWorldMap.unk36 = 1;
        break;
    case 11:
        Task_Create(gUnknown_087E0F54, 0xFFFF);
        gWorldMap.state = 0x10;
        gWorldMap.unk36 = 1;
        break;
    case 12:
        Task_Create(gUnknown_087E0DD0, 0xFFFF);
        gWorldMap.state = 0x10;
        break;
    case 5:
        Task_Create(gUnknown_087E0028, 0xFFFF);
        gWorldMap.state = 0x10;
        break;
    case 6:
        Task_Create(gUnknown_087E0090, 0xFFFF);
        gWorldMap.state = 0x10;
        break;
    case 7:
        Task_Create(gUnknown_087E0120, 0xFFFF);
        gWorldMap.state = 0x10;
        break;
    case 14:
    case 15:
    case 16:
        break;
    }

    if (gWorldMap.x <= 0x78)
        sx = gWorldMap.x;
    else
        sx = gWorldMap.x - 0x78 < rec->width - 0xF0 ? 0x78 : gWorldMap.x + (0xF0 - rec->width);

    if (gWorldMap.y <= 0x50)
        sy = gWorldMap.y;
    else
        sy = gWorldMap.y - 0x50 < rec->height - 0xA0 ? 0x50 : gWorldMap.y + (0xA0 - rec->height);

    rec2 = FieldMap_GetArea(gWorldMap.map);
    if (gWorldMap.state == 2 || gWorldMap.state == 13)
    {
        u16 tx, ty;
        bx = gWorldMap.unk10 >> 3;
        by = gWorldMap.unk12 >> 3;
        m = sub_08151FD8(0);
        m += by * (rec2->width >> 3) + bx;
        t = *m & 0x1FF;
        tx = gWorldMap.unk14 >> 3;
        ty = gWorldMap.unk16 >> 3;
        m = sub_08151FD8(0);
        m += ty * (rec2->width >> 3) + tx;
        if ((*m & 0x1FF) == t)
        {
            bx = tx;
            by = ty;
        }
        else
        {
            bx = gWorldMap.x >> 3;
            by = gWorldMap.y >> 3;
        }
    }
    else
    {
        bx = gWorldMap.x >> 3;
        by = gWorldMap.y >> 3;
    }

    m = sub_08151FD8(0);
    m += by * (rec2->width >> 3) + bx;
    if ((*m & 0x1FF) == 0 || gWorldMap.unk1C != 0)
    {
        gUnk_03000030 = 0;
        gUnk_03000031 = 0;
        gUnk_03000034 = 0;
        gUnk_03000035 = 0;
        win = 2;
    }
    else
    {
        gUnk_03000030 = 0x88;
        gUnk_03000031 = 0x68;
        gUnk_03000034 = sy + 0x10;
        gUnk_03000035 = sy - 0x10;
        gUnk_03000038 = 0x3F;
        win = 3;
    }

    if (gWorldMap.map == 2)
    {
        for (p = gUnknown_087DF95C; p[0] != 0xFFFF; p += 2)
        {
            if (gWorldMap.x == p[0] && gWorldMap.y == p[1])
            {
                gUnk_03000030 = 0;
                gUnk_03000031 = 0;
                gUnk_03000034 = 0;
                gUnk_03000035 = 0;
                win = 2;
                break;
            }
        }
    }
    if (gWorldMap.map == 8 && gWorldMap.y < 0x60)
    {
        gUnk_03000030 = 0;
        gUnk_03000031 = 0;
        gUnk_03000034 = 0;
        gUnk_03000035 = 0;
        win = 2;
    }
    gWorldMap.unk1E = sx - 0x10;
    gWorldMap.unk20 = sy - 0x10;
    sub_080C2F44(sx, sy, win);
    WorldMap_DrawSprites();
    WorldMap_AnimateTiles();
}
#else
NAKED
void sub_0815201C(void)
{
    asm_unified(
        ".L0815201C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0xc\n"
        "    ldr r4, .L08152044\n"
        "    ldrh r0, [r4, #8]\n"
        "    bl FieldMap_GetArea\n"
        "    adds r5, r0, #0\n"
        "    ldr r0, [r4]\n"
        "    cmp r0, #0x10\n"
        "    bls .L0815203A\n"
        "    b .L0815213A\n"
        ".L0815203A:\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L08152048\n"
        "    adds r0, r0, r1\n"
        "    ldr r0, [r0]\n"
        "    mov pc, r0\n"
        ".L08152044: .4byte 0x030069F0 @ IWRAM+0x69F0\n"
        ".L08152048: .4byte gUnknown_0815204C\n"
        "    .global gUnknown_0815204C\n"
        "gUnknown_0815204C:\n"
        ".L0815204C: @ jump table\n"
        "    .4byte .L08152090\n"
        "    .4byte .L08152098\n"
        "    .4byte .L081520C4\n"
        "    .4byte .L081520CA\n"
        "    .4byte .L081520D4\n"
        "    .4byte .L0815211C\n"
        "    .4byte .L08152124\n"
        "    .4byte .L0815212C\n"
        "    .4byte .L081520DC\n"
        "    .4byte .L081520E4\n"
        "    .4byte .L081520EC\n"
        "    .4byte .L081520F4\n"
        "    .4byte .L08152114\n"
        "    .4byte .L081520C4\n"
        "    .4byte .L0815213A\n"
        "    .4byte .L0815213A\n"
        "    .4byte .L0815213A\n"
        ".L08152090:\n"
        "    ldr r0, .L08152094\n"
        "    b .L0815212E\n"
        ".L08152094: .4byte gUnknown_087DFBA0\n"
        ".L08152098:\n"
        "    bl WorldMap_HandleInput\n"
        "    bl WorldMap_GetBlocks\n"
        "    ldr r3, .L081520C0\n"
        "    ldrh r2, [r3, #0xc]\n"
        "    lsrs r2, r2, #4\n"
        "    ldrh r1, [r3, #0xe]\n"
        "    lsrs r1, r1, #4\n"
        "    lsls r1, r1, #6\n"
        "    adds r2, r2, r1\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #6\n"
        "    adds r0, r0, r1\n"
        "    adds r0, r0, r2\n"
        "    ldrb r0, [r0]\n"
        "    lsrs r0, r0, #4\n"
        "    strh r0, [r3, #0x26]\n"
        "    b .L0815213A\n"
        "    .byte 0x00, 0x00\n"
        ".L081520C0: .4byte 0x030069F0 @ IWRAM+0x69F0\n"
        ".L081520C4:\n"
        "    bl WorldMap_Walk\n"
        "    b .L0815213A\n"
        ".L081520CA:\n"
        "    ldr r0, .L081520D0\n"
        "    b .L0815212E\n"
        "    .byte 0x00, 0x00\n"
        ".L081520D0: .4byte gUnknown_087DFEF0\n"
        ".L081520D4:\n"
        "    ldr r0, .L081520D8\n"
        "    b .L0815212E\n"
        ".L081520D8: .4byte gUnknown_087DFF58\n"
        ".L081520DC:\n"
        "    ldr r0, .L081520E0\n"
        "    b .L0815212E\n"
        ".L081520E0: .4byte gUnknown_087DFFC0\n"
        ".L081520E4:\n"
        "    ldr r0, .L081520E8\n"
        "    b .L0815212E\n"
        ".L081520E8: .4byte gUnknown_087E0998\n"
        ".L081520EC:\n"
        "    ldr r0, .L081520F0\n"
        "    b .L081520F6\n"
        ".L081520F0: .4byte gUnknown_087E0DA0\n"
        ".L081520F4:\n"
        "    ldr r0, .L08152108\n"
        ".L081520F6:\n"
        "    ldr r1, .L0815210C\n"
        "    bl Task_Create\n"
        "    ldr r1, .L08152110\n"
        "    movs r0, #0x10\n"
        "    str r0, [r1]\n"
        "    movs r0, #1\n"
        "    strh r0, [r1, #0x36]\n"
        "    b .L0815213A\n"
        ".L08152108: .4byte gUnknown_087E0F54\n"
        ".L0815210C: .4byte 0x0000FFFF\n"
        ".L08152110: .4byte 0x030069F0 @ IWRAM+0x69F0\n"
        ".L08152114:\n"
        "    ldr r0, .L08152118\n"
        "    b .L0815212E\n"
        ".L08152118: .4byte gUnknown_087E0DD0\n"
        ".L0815211C:\n"
        "    ldr r0, .L08152120\n"
        "    b .L0815212E\n"
        ".L08152120: .4byte gUnknown_087E0028\n"
        ".L08152124:\n"
        "    ldr r0, .L08152128\n"
        "    b .L0815212E\n"
        ".L08152128: .4byte gUnknown_087E0090\n"
        ".L0815212C:\n"
        "    ldr r0, .L0815214C\n"
        ".L0815212E:\n"
        "    ldr r1, .L08152150\n"
        "    bl Task_Create\n"
        "    ldr r1, .L08152154\n"
        "    movs r0, #0x10\n"
        "    str r0, [r1]\n"
        ".L0815213A:\n"
        "    ldr r0, .L08152154\n"
        "    ldrh r1, [r0, #0xc]\n"
        "    mov r8, r0\n"
        "    cmp r1, #0x78\n"
        "    bhi .L08152158\n"
        "    adds r2, r1, #0\n"
        "    str r2, [sp]\n"
        "    b .L0815217E\n"
        "    .byte 0x00, 0x00\n"
        ".L0815214C: .4byte gUnknown_087E0120\n"
        ".L08152150: .4byte 0x0000FFFF\n"
        ".L08152154: .4byte 0x030069F0 @ IWRAM+0x69F0\n"
        ".L08152158:\n"
        "    mov r7, r8\n"
        "    ldrh r3, [r7, #0xc]\n"
        "    adds r0, r3, #0\n"
        "    subs r0, #0x78\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0xc8\n"
        "    ldrh r2, [r1]\n"
        "    adds r1, r2, #0\n"
        "    subs r1, #0xf0\n"
        "    cmp r0, r1\n"
        "    blt .L0815217A\n"
        "    adds r0, r3, #0\n"
        "    adds r0, #0xf0\n"
        "    subs r0, r0, r2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    b .L0815217C\n"
        ".L0815217A:\n"
        "    movs r0, #0x78\n"
        ".L0815217C:\n"
        "    str r0, [sp]\n"
        ".L0815217E:\n"
        "    mov r1, r8\n"
        "    ldrh r0, [r1, #0xe]\n"
        "    cmp r0, #0x50\n"
        "    bhi .L0815218C\n"
        "    adds r2, r0, #0\n"
        "    mov sl, r2\n"
        "    b .L081521B0\n"
        ".L0815218C:\n"
        "    mov r7, r8\n"
        "    ldrh r3, [r7, #0xe]\n"
        "    adds r0, r3, #0\n"
        "    subs r0, #0x50\n"
        "    adds r1, r5, #0\n"
        "    adds r1, #0xca\n"
        "    ldrh r2, [r1]\n"
        "    adds r1, r2, #0\n"
        "    subs r1, #0xa0\n"
        "    cmp r0, r1\n"
        "    blt .L081521AC\n"
        "    adds r0, #0xf0\n"
        "    subs r0, r0, r2\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    b .L081521AE\n"
        ".L081521AC:\n"
        "    movs r0, #0x50\n"
        ".L081521AE:\n"
        "    mov sl, r0\n"
        ".L081521B0:\n"
        "    ldr r7, .L08152220\n"
        "    ldrh r0, [r7, #8]\n"
        "    bl FieldMap_GetArea\n"
        "    mov sb, r0\n"
        "    ldr r0, [r7]\n"
        "    cmp r0, #2\n"
        "    beq .L081521C4\n"
        "    cmp r0, #0xd\n"
        "    bne .L08152232\n"
        ".L081521C4:\n"
        "    ldrh r1, [r7, #0x10]\n"
        "    lsrs r1, r1, #3\n"
        "    mov r8, r1\n"
        "    ldrh r4, [r7, #0x12]\n"
        "    lsrs r4, r4, #3\n"
        "    movs r0, #0\n"
        "    bl sub_08151FD8\n"
        "    adds r1, r0, #0\n"
        "    mov r6, sb\n"
        "    adds r6, #0xc8\n"
        "    ldrh r0, [r6]\n"
        "    lsrs r0, r0, #3\n"
        "    muls r0, r4, r0\n"
        "    add r0, r8\n"
        "    lsls r0, r0, #1\n"
        "    adds r1, r1, r0\n"
        "    ldrh r0, [r1]\n"
        "    ldr r4, .L08152224\n"
        "    adds r2, r4, #0\n"
        "    ands r2, r0\n"
        "    str r2, [sp, #4]\n"
        "    ldrh r0, [r7, #0x14]\n"
        "    lsrs r0, r0, #3\n"
        "    mov sb, r0\n"
        "    ldrh r0, [r7, #0x16]\n"
        "    lsrs r5, r0, #3\n"
        "    movs r0, #0\n"
        "    bl sub_08151FD8\n"
        "    adds r1, r0, #0\n"
        "    ldrh r0, [r6]\n"
        "    lsrs r0, r0, #3\n"
        "    muls r0, r5, r0\n"
        "    add r0, sb\n"
        "    lsls r0, r0, #1\n"
        "    adds r1, r1, r0\n"
        "    ldrh r0, [r1]\n"
        "    ands r4, r0\n"
        "    mov r8, r6\n"
        "    ldr r0, [sp, #4]\n"
        "    cmp r4, r0\n"
        "    bne .L08152228\n"
        "    mov r6, sb\n"
        "    adds r4, r5, #0\n"
        "    b .L08152240\n"
        ".L08152220: .4byte 0x030069F0 @ IWRAM+0x69F0\n"
        ".L08152224: .4byte 0x000001FF\n"
        ".L08152228:\n"
        "    ldrh r0, [r7, #0xc]\n"
        "    lsrs r6, r0, #3\n"
        "    ldrh r0, [r7, #0xe]\n"
        "    lsrs r4, r0, #3\n"
        "    b .L08152240\n"
        ".L08152232:\n"
        "    ldrh r0, [r7, #0xc]\n"
        "    lsrs r6, r0, #3\n"
        "    ldrh r0, [r7, #0xe]\n"
        "    lsrs r4, r0, #3\n"
        "    movs r1, #0xc8\n"
        "    add r1, sb\n"
        "    mov r8, r1\n"
        ".L08152240:\n"
        "    movs r0, #0\n"
        "    bl sub_08151FD8\n"
        "    adds r1, r0, #0\n"
        "    mov r2, r8\n"
        "    ldrh r0, [r2]\n"
        "    lsrs r0, r0, #3\n"
        "    muls r0, r4, r0\n"
        "    adds r0, r0, r6\n"
        "    lsls r0, r0, #1\n"
        "    adds r1, r1, r0\n"
        "    ldrh r1, [r1]\n"
        "    ldr r0, .L08152290\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L0815226A\n"
        "    ldr r0, .L08152294\n"
        "    ldrh r1, [r0, #0x1c]\n"
        "    mov r8, r0\n"
        "    cmp r1, #0\n"
        "    beq .L081522C0\n"
        ".L0815226A:\n"
        "    ldr r4, .L08152298\n"
        "    movs r0, #0\n"
        "    strb r0, [r4]\n"
        "    ldr r3, .L0815229C\n"
        "    strb r0, [r3]\n"
        "    ldr r2, .L081522A0\n"
        "    strb r0, [r2]\n"
        "    ldr r1, .L081522A4\n"
        "    strb r0, [r1]\n"
        "    movs r7, #2\n"
        "    mov sb, r7\n"
        "    ldr r0, .L08152294\n"
        "    mov r8, r0\n"
        "    mov ip, r3\n"
        "    adds r6, r2, #0\n"
        "    adds r5, r1, #0\n"
        "    mov r3, sl\n"
        "    subs r3, #0x10\n"
        "    b .L081522EC\n"
        ".L08152290: .4byte 0x000001FF\n"
        ".L08152294: .4byte 0x030069F0 @ IWRAM+0x69F0\n"
        ".L08152298: .4byte 0x03000030 @ IWRAM+0x30\n"
        ".L0815229C: .4byte 0x03000031 @ IWRAM+0x31\n"
        ".L081522A0: .4byte 0x03000034 @ IWRAM+0x34\n"
        ".L081522A4: .4byte 0x03000035 @ IWRAM+0x35\n"
        ".L081522A8:\n"
        "    movs r0, #0\n"
        "    ldr r1, .L081522BC\n"
        "    strb r0, [r1]\n"
        "    mov r2, ip\n"
        "    strb r0, [r2]\n"
        "    strb r0, [r6]\n"
        "    strb r0, [r5]\n"
        "    movs r7, #2\n"
        "    mov sb, r7\n"
        "    b .L08152320\n"
        ".L081522BC: .4byte 0x03000030 @ IWRAM+0x30\n"
        ".L081522C0:\n"
        "    ldr r6, .L08152368\n"
        "    movs r0, #0x88\n"
        "    strb r0, [r6]\n"
        "    ldr r7, .L0815236C\n"
        "    movs r0, #0x68\n"
        "    strb r0, [r7]\n"
        "    ldr r4, .L08152370\n"
        "    mov r0, sl\n"
        "    adds r0, #0x10\n"
        "    strb r0, [r4]\n"
        "    ldr r2, .L08152374\n"
        "    mov r3, sl\n"
        "    subs r3, #0x10\n"
        "    strb r3, [r2]\n"
        "    ldr r1, .L08152378\n"
        "    movs r0, #0x3f\n"
        "    strb r0, [r1]\n"
        "    movs r0, #3\n"
        "    mov sb, r0\n"
        "    mov ip, r7\n"
        "    adds r6, r4, #0\n"
        "    adds r5, r2, #0\n"
        ".L081522EC:\n"
        "    mov r1, r8\n"
        "    ldrh r0, [r1, #8]\n"
        "    ldr r4, [sp]\n"
        "    subs r4, #0x10\n"
        "    cmp r0, #2\n"
        "    bne .L08152320\n"
        "    ldr r1, .L0815237C\n"
        "    ldrh r0, [r1]\n"
        "    ldr r2, .L08152380\n"
        "    cmp r0, r2\n"
        "    beq .L08152320\n"
        "    mov r7, r8\n"
        "    ldrh r7, [r7, #0xc]\n"
        "    str r7, [sp, #8]\n"
        ".L08152308:\n"
        "    ldr r7, [sp, #8]\n"
        "    cmp r7, r0\n"
        "    bne .L08152318\n"
        "    mov r7, r8\n"
        "    ldrh r0, [r7, #0xe]\n"
        "    ldrh r7, [r1, #2]\n"
        "    cmp r0, r7\n"
        "    beq .L081522A8\n"
        ".L08152318:\n"
        "    adds r1, #4\n"
        "    ldrh r0, [r1]\n"
        "    cmp r0, r2\n"
        "    bne .L08152308\n"
        ".L08152320:\n"
        "    mov r1, r8\n"
        "    ldrh r0, [r1, #8]\n"
        "    cmp r0, #8\n"
        "    bne .L08152340\n"
        "    ldrh r0, [r1, #0xe]\n"
        "    cmp r0, #0x5f\n"
        "    bhi .L08152340\n"
        "    movs r0, #0\n"
        "    ldr r2, .L08152368\n"
        "    strb r0, [r2]\n"
        "    mov r7, ip\n"
        "    strb r0, [r7]\n"
        "    strb r0, [r6]\n"
        "    strb r0, [r5]\n"
        "    movs r0, #2\n"
        "    mov sb, r0\n"
        ".L08152340:\n"
        "    mov r1, r8\n"
        "    strh r4, [r1, #0x1e]\n"
        "    strh r3, [r1, #0x20]\n"
        "    ldr r0, [sp]\n"
        "    mov r1, sl\n"
        "    mov r2, sb\n"
        "    bl sub_080C2F44\n"
        "    bl WorldMap_DrawSprites\n"
        "    bl WorldMap_AnimateTiles\n"
        "    add sp, #0xc\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L08152368: .4byte 0x03000030 @ IWRAM+0x30\n"
        ".L0815236C: .4byte 0x03000031 @ IWRAM+0x31\n"
        ".L08152370: .4byte 0x03000034 @ IWRAM+0x34\n"
        ".L08152374: .4byte 0x03000035 @ IWRAM+0x35\n"
        ".L08152378: .4byte 0x03000038 @ IWRAM+0x38\n"
        ".L0815237C: .4byte gUnknown_087DF95C\n"
        ".L08152380: .4byte 0x0000FFFF\n"
    );
}
#endif

// WorldMap_StartWindowRaster @ 0x08152384
void WorldMap_StartWindowRaster(void)
{
    u16 v;
    REG_IE |= 4;
    REG_DISPSTAT &= 0xFF;
    v = gWorldMap.unk20;
    REG_DISPSTAT |= (v << 8) | 0x24;
    gWorldMap.unk1A = 0;
    gWorldMap.unk22 = gWorldMap.unk1E;
    gWorldMap.unk24 = v;
}

// WorldMap_WindowRasterIrq @ 0x081523C8
void WorldMap_WindowRasterIrq(void)
{
    u16 n = gWorldMap.unk1A;
    if (n != 0x20)
    {
        u16 b = gWorldMap.unk22;
        const u16 *e = gUnknown_087DFA58[*(vu16 *)&gWorldMap.unk1A];
        u16 l = b + e[0];
        u16 r = b + e[1];
        REG_WIN0H = r + (l << 8);
        gWorldMap.unk1A = n + 1;
        REG_DISPSTAT = ((gWorldMap.unk24 + (n + 1)) << 8) | (REG_DISPSTAT & 0xFF);
    }
}

// WorldMap_InstallWindowRaster @ 0x08152420
void WorldMap_InstallWindowRaster(void)
{
    gIntrTable[2] = WorldMap_WindowRasterIrq;
    VBlankTask_AddAlways(WorldMap_StartWindowRaster);
}

// WorldMap_CopyTilemapView @ 0x08152440
#ifdef NONMATCHING
void WorldMap_CopyTilemapView(const u16 *src, u16 *dst, u16 x, u16 y, u16 width, u16 height)
{
    struct MapRecord *rec = FieldMap_GetArea(gWorldMap.map);
    u16 sx, sy;
    u16 i, j;
    u32 stride = width >> 3;

    if (x > 0x78)
        sx = x - 0x78;
    else
        sx = 0;
    if (sx > rec->width - 0xF0)
        sx = rec->width - 0xF0;
    sx >>= 3;
    if (y > 0x50)
        sy = y - 0x50;
    else
        sy = 0;
    if (sy > rec->height - 0xA0)
        sy = rec->height - 0xA0;
    sy >>= 3;
    for (i = 0; i < 32; i++)
    {
        const u16 *s = &src[(sy + i) * stride + sx];
        for (j = 0; j < 32; j++)
            dst[(((sy & 31) + i) & 31) * 32 + (((sx & 31) + j) & 31)] = *s++;
    }
}
#else
NAKED
void WorldMap_CopyTilemapView(const u16 *src, u16 *dst, u16 x, u16 y, u16 width, u16 height)
{
    asm_unified(
        ".L08152440:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #8\n"
        "    str r0, [sp]\n"
        "    mov sl, r1\n"
        "    ldr r4, [sp, #0x28]\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r5, r2, #0x10\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r7, r3, #0x10\n"
        "    lsls r4, r4, #0x10\n"
        "    ldr r0, .L08152478\n"
        "    ldrh r0, [r0, #8]\n"
        "    bl FieldMap_GetArea\n"
        "    adds r1, r0, #0\n"
        "    lsrs r4, r4, #0x13\n"
        "    str r4, [sp, #4]\n"
        "    cmp r5, #0x78\n"
        "    bls .L0815247C\n"
        "    adds r0, r5, #0\n"
        "    subs r0, #0x78\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        "    b .L0815247E\n"
        ".L08152478: .4byte 0x030069F0 @ IWRAM+0x69F0\n"
        ".L0815247C:\n"
        "    movs r6, #0\n"
        ".L0815247E:\n"
        "    adds r0, r1, #0\n"
        "    adds r0, #0xc8\n"
        "    ldrh r0, [r0]\n"
        "    subs r0, #0xf0\n"
        "    cmp r6, r0\n"
        "    ble .L0815248E\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r6, r0, #0x10\n"
        ".L0815248E:\n"
        "    lsrs r6, r6, #3\n"
        "    cmp r7, #0x50\n"
        "    bls .L0815249E\n"
        "    adds r0, r7, #0\n"
        "    subs r0, #0x50\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        "    b .L081524A0\n"
        ".L0815249E:\n"
        "    movs r5, #0\n"
        ".L081524A0:\n"
        "    adds r0, r1, #0\n"
        "    adds r0, #0xca\n"
        "    ldrh r0, [r0]\n"
        "    subs r0, #0xa0\n"
        "    cmp r5, r0\n"
        "    ble .L081524B0\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r5, r0, #0x10\n"
        ".L081524B0:\n"
        "    lsrs r5, r5, #3\n"
        "    movs r0, #0x1f\n"
        "    mov ip, r6\n"
        "    mov r1, ip\n"
        "    ands r1, r0\n"
        "    mov ip, r1\n"
        "    mov r8, r5\n"
        "    mov r2, r8\n"
        "    ands r2, r0\n"
        "    mov r8, r2\n"
        "    movs r1, #0\n"
        "    movs r3, #0x1f\n"
        "    mov sb, r3\n"
        ".L081524CA:\n"
        "    adds r0, r5, r1\n"
        "    ldr r4, [sp, #4]\n"
        "    muls r0, r4, r0\n"
        "    adds r0, r0, r6\n"
        "    lsls r0, r0, #1\n"
        "    ldr r3, [sp]\n"
        "    adds r2, r3, r0\n"
        "    movs r3, #0\n"
        "    mov r4, r8\n"
        "    adds r0, r4, r1\n"
        "    adds r7, r1, #1\n"
        "    mov r1, sb\n"
        "    ands r0, r1\n"
        "    lsls r4, r0, #5\n"
        ".L081524E6:\n"
        "    mov r1, ip\n"
        "    adds r0, r1, r3\n"
        "    mov r1, sb\n"
        "    ands r0, r1\n"
        "    adds r0, r4, r0\n"
        "    lsls r0, r0, #1\n"
        "    add r0, sl\n"
        "    ldrh r1, [r2]\n"
        "    strh r1, [r0]\n"
        "    adds r2, #2\n"
        "    adds r0, r3, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r3, r0, #0x10\n"
        "    cmp r3, #0x1f\n"
        "    bls .L081524E6\n"
        "    lsls r0, r7, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    cmp r1, #0x1f\n"
        "    bls .L081524CA\n"
        "    add sp, #8\n"
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

// WorldMap_UpdateLayer @ 0x0815251C
void WorldMap_UpdateLayer(u16 a)
{
    const struct WarpEntry *e;
    u16 cx = gWorldMap.x >> 4;
    u16 cy = gWorldMap.y >> 4;

    e = gUnknown_087DFAD8;
    while (1)
    {
        if (e->map == 0xFF)
            return;
        if (e->map == gWorldMap.map && cx == e->x && cy == e->y)
        {
            if (e->kind == 0)
                gWorldMap.unk1C = e->vals[0];
            else
                gWorldMap.unk1C = e->vals[a];
            return;
        }
        e++;
    }
}

// WorldMap_SetState @ 0x08152578
void WorldMap_SetState(u32 a0, u32 state)
{
    gWorldMap.state = state;
}

// FieldMap_LoadTiles @ 0x08152584
void FieldMap_LoadTiles(u32 unused, u32 k)
{
    struct MapRecord *rec = FieldMap_GetArea(gWorldMap.map);
    u8 *dst = gUnk_02001000;
    u32 zero;
    dst += k * 0x1000;
    zero = 0;
    CpuSet(&zero, dst, 0x05000400);
    HuffUnComp(rec->gfx[k], gBgPictureBuffer);
    LZ77UnCompWram(gBgPictureBuffer, dst);
}

// FieldMap_LoadBlockData @ 0x081525D8
void FieldMap_LoadBlockData(u32 unused, u32 k)
{
    struct MapRecord *rec = FieldMap_GetArea(gWorldMap.map);
    if (rec->objGfx[k] != NULL)
    {
        HuffUnComp(rec->objGfx[k], gBgPictureBuffer);
        if (k < 4)
            LZ77UnCompWram(gBgPictureBuffer, gUnk_02005004 + k * 0x1000);
        else
            LZ77UnCompWram(gBgPictureBuffer, gUnk_02030C74 + (k - 4) * 0x1000);
    }
}

// FieldMap_LoadMapChunk @ 0x08152630
void FieldMap_LoadMapChunk(u32 unused, u32 k)
{
    struct MapRecord *rec = FieldMap_GetArea(gWorldMap.map);
    u8 *dst;
    u32 zero;
    u32 zero2;

    dst = gUnk_0200F874;
    dst += k * 0x1000;
    zero = 0;
    CpuSet(&zero, dst, 0x05000400);
    if (rec->maps[0][1] != NULL && rec->maps[0][k] != NULL)
    {
        HuffUnComp(rec->maps[0][k], gBgPictureBuffer);
        LZ77UnCompWram(gBgPictureBuffer, dst);
    }
    dst = gUnk_0200F874;
    dst += k * 0x1000 + 0x10000;
    zero2 = 0;
    CpuSet(&zero2, dst, 0x05000400);
    if (rec->maps[1][1] != NULL && rec->maps[1][k] != NULL)
    {
        HuffUnComp(rec->maps[1][k], gBgPictureBuffer);
        LZ77UnCompWram(gBgPictureBuffer, dst);
    }
}

// WorldMap_UploadTiles @ 0x081526D0
void WorldMap_UploadTiles(void)
{
    DMA3_SET(0x02001000, 0x06004000, 0x84002000);
}

// WorldMap_QueueTileUpload @ 0x081526F4
void WorldMap_QueueTileUpload(void)
{
    VBlankTask_AddCounted(WorldMap_UploadTiles, 1);
}

// sub_08152708 @ 0x08152708
void sub_08152708(void)
{
    DMA3_SET(gUnk_02000000, 0x06002000, 0x84000200);
}

// sub_0815272C @ 0x0815272C
void sub_0815272C(void)
{
    DMA3_SET(0x02000800, 0x06003000, 0x84000200);
}

// WorldMap_DrawLayer @ 0x08152750
void WorldMap_DrawLayer(u32 unused, u32 layer, u32 kind)
{
    struct MapRecord *rec = FieldMap_GetArea(gWorldMap.map);
    switch (kind)
    {
    case 2:
        WorldMap_CopyTilemapView(sub_08151FD8(layer), (u16 *)gUnk_02000000, gWorldMap.x, gWorldMap.y, rec->width, rec->height);
        VBlankTask_AddCounted(sub_08152708, 1);
        break;
    case 3:
        WorldMap_CopyTilemapView(sub_08151FD8(layer), (u16 *)gUnk_02000800, gWorldMap.x, gWorldMap.y, rec->width, rec->height);
        VBlankTask_AddCounted(sub_0815272C, 1);
        break;
    }
}

// WorldMap_LoadPalette @ 0x081527E0
void WorldMap_LoadPalette(void)
{
    struct MapRecord *rec = FieldMap_GetArea(gWorldMap.map);
    sub_080C67C0(gPaletteTarget, 12);
    Palette_CopyWithEffect(3, (const void *)rec->unkA0, &gPaletteTarget[0x80], 0x100, 0x20);
    gPaletteTarget[1] = 0;
}

// sub_08152824 @ 0x08152824
void sub_08152824(void)
{
    DMA3_SET(0x02001000, 0x06015000, 0x84000800);
}

// WorldMap_LoadObjGfx @ 0x08152848
void WorldMap_LoadObjGfx(void)
{
    HuffUnComp(gUnknown_087DDE08, gBgPictureBuffer);
    LZ77UnCompWram(gBgPictureBuffer, gUnk_02001000);
    HuffUnComp(gUnknown_087DE4C8, gBgPictureBuffer);
    LZ77UnCompWram(gBgPictureBuffer, gUnk_02001000 + 0x1000);
    Palette_CopyWithEffect(3, gUnknown_087DE8C4, &gPaletteTarget[0x1D0], 0x60, 0x10);
    VBlankTask_AddCounted(sub_08152824, 1);
}

// sub_081528B4 @ 0x081528B4
#ifdef NONMATCHING
void sub_081528B4(void)
{
    u8 a, b;

    if (Flag_Test(0x69) && !Flag_Test(0x109))
    {
        gWorldMap.state = 9;
        return;
    }
    if (gWorldMap.map == 6)
    {
        if (Flag_Test(0x61) && !Flag_Test(0x79))
        {
            gWorldMap.state = 10;
            return;
        }
        if (gWorldMap.map == 6)
        {
            if (Flag_Test(0x79) && !Flag_Test(0x63))
            {
                gWorldMap.state = 11;
                return;
            }
            if (gWorldMap.map == 6 && (gWorldMap.x >> 4) == 0x1F && (gWorldMap.y >> 4) == 0x47)
            {
                gWorldMap.state = 12;
                return;
            }
        }
    }
    a = (&gGameState.pos.x)[0];
    b = (&gGameState.pos.x)[1];
    if (gWorldMap.mode == 0)
    {
        const u16 *p;
        if (a == 4 && (b & 0x3F) == 0x3B)
            p = gUnknown_087DFB88;
        else
            p = &gUnknown_087DFB88[b >> 6];
        WorldMap_TryStep(*p);
        gWorldMap.unk18 = 1;
        gWorldMap.state = 13;
    }
    else if (gWorldMap.mode == 3)
    {
        WorldMap_TryStep(gUnknown_087DFB90[gWarpDest[4] & 7]);
        gWorldMap.unk18 = 1;
        gWorldMap.state = 13;
    }
    else
    {
        gWorldMap.state = 1;
    }
}
#else
NAKED
void sub_081528B4(void)
{
    asm_unified(
        "    push {r4, r5, lr}\n"
        "    movs r0, #0x69\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    beq .L081528DC\n"
        "    ldr r0, .L081528D4\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L081528DC\n"
        "    ldr r1, .L081528D8\n"
        "    movs r0, #9\n"
        "    str r0, [r1]\n"
        "    b .L081529D8\n"
        "    .byte 0x00, 0x00\n"
        ".L081528D4: .4byte 0x00000109\n"
        ".L081528D8: .4byte 0x030069F0 @ IWRAM+0x69F0\n"
        ".L081528DC:\n"
        "    ldr r0, .L08152900\n"
        "    ldrh r1, [r0, #8]\n"
        "    adds r5, r0, #0\n"
        "    cmp r1, #6\n"
        "    bne .L08152950\n"
        "    movs r0, #0x61\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    beq .L08152904\n"
        "    movs r0, #0x79\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L08152904\n"
        "    movs r0, #0xa\n"
        "    b .L081529D6\n"
        "    .byte 0x00, 0x00\n"
        ".L08152900: .4byte 0x030069F0 @ IWRAM+0x69F0\n"
        ".L08152904:\n"
        "    ldr r0, .L08152928\n"
        "    ldrh r1, [r0, #8]\n"
        "    adds r5, r0, #0\n"
        "    cmp r1, #6\n"
        "    bne .L08152950\n"
        "    movs r0, #0x79\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    beq .L0815292C\n"
        "    movs r0, #0x63\n"
        "    bl Flag_Test\n"
        "    cmp r0, #0\n"
        "    bne .L0815292C\n"
        "    movs r0, #0xb\n"
        "    b .L081529D6\n"
        "    .byte 0x00, 0x00\n"
        ".L08152928: .4byte 0x030069F0 @ IWRAM+0x69F0\n"
        ".L0815292C:\n"
        "    ldr r0, .L0815294C\n"
        "    ldrh r1, [r0, #8]\n"
        "    adds r5, r0, #0\n"
        "    cmp r1, #6\n"
        "    bne .L08152950\n"
        "    ldrh r0, [r5, #0xc]\n"
        "    lsrs r0, r0, #4\n"
        "    cmp r0, #0x1f\n"
        "    bne .L08152950\n"
        "    ldrh r0, [r5, #0xe]\n"
        "    lsrs r0, r0, #4\n"
        "    cmp r0, #0x47\n"
        "    bne .L08152950\n"
        "    movs r0, #0xc\n"
        "    b .L081529D6\n"
        "    .byte 0x00, 0x00\n"
        ".L0815294C: .4byte 0x030069F0 @ IWRAM+0x69F0\n"
        ".L08152950:\n"
        "    ldr r0, .L08152978\n"
        "    ldr r2, .L0815297C\n"
        "    adds r1, r0, r2\n"
        "    ldrb r1, [r1]\n"
        "    adds r2, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrb r2, [r0]\n"
        "    adds r4, r5, #0\n"
        "    ldrh r0, [r4, #4]\n"
        "    cmp r0, #0\n"
        "    bne .L081529A8\n"
        "    cmp r1, #4\n"
        "    bne .L08152984\n"
        "    movs r0, #0x3f\n"
        "    ands r0, r2\n"
        "    cmp r0, #0x3b\n"
        "    bne .L08152984\n"
        "    ldr r0, .L08152980\n"
        "    b .L0815298C\n"
        "    .byte 0x00, 0x00\n"
        ".L08152978: .4byte 0x030046C0 @ IWRAM+0x46C0\n"
        ".L0815297C: .4byte 0x000018C2\n"
        ".L08152980: .4byte gUnknown_087DFB88\n"
        ".L08152984:\n"
        "    ldr r1, .L081529A0\n"
        "    lsrs r0, r2, #6\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r1\n"
        ".L0815298C:\n"
        "    ldrh r0, [r0]\n"
        "    bl WorldMap_TryStep\n"
        "    ldr r0, .L081529A4\n"
        "    movs r1, #1\n"
        "    strh r1, [r0, #0x18]\n"
        "    movs r1, #0xd\n"
        "    str r1, [r0]\n"
        "    b .L081529D8\n"
        "    .byte 0x00, 0x00\n"
        ".L081529A0: .4byte gUnknown_087DFB88\n"
        ".L081529A4: .4byte 0x030069F0 @ IWRAM+0x69F0\n"
        ".L081529A8:\n"
        "    cmp r0, #3\n"
        "    bne .L081529D4\n"
        "    ldr r2, .L081529CC\n"
        "    ldr r0, .L081529D0\n"
        "    ldrh r1, [r0, #8]\n"
        "    movs r0, #7\n"
        "    ands r0, r1\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r2\n"
        "    ldrh r0, [r0]\n"
        "    bl WorldMap_TryStep\n"
        "    movs r0, #1\n"
        "    strh r0, [r4, #0x18]\n"
        "    movs r0, #0xd\n"
        "    str r0, [r4]\n"
        "    b .L081529D8\n"
        "    .byte 0x00, 0x00\n"
        ".L081529CC: .4byte gUnknown_087DFB90\n"
        ".L081529D0: .4byte 0x03003FD0 @ IWRAM+0x3FD0\n"
        ".L081529D4:\n"
        "    movs r0, #1\n"
        ".L081529D6:\n"
        "    str r0, [r5]\n"
        ".L081529D8:\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// WorldMap_GetBlocks @ 0x081529E0
struct FieldBlocks *WorldMap_GetBlocks(void)
{
    if (gWorldMap.unk1C == 0)
        return (struct FieldBlocks *)gUnk_02005004;
    return (struct FieldBlocks *)gUnk_02030C74;
}

/* Moves the walk target (unk14, unk16) one 16-pixel block in the direction of the d-pad keys,
   sliding diagonally around corners; returns 1 when the step is allowed. */
// WorldMap_TryStep @ 0x08152A04
u32 WorldMap_TryStep(u16 keys)
{
    struct FieldBlocks *map;
    u32 dir;
    u32 ok;
    u16 bx, by;
    u16 i;
    s32 blk[8];
    u32 n;
    u16 px, py;
    u16 ox, oy;
    u16 dx, dy;

    map = WorldMap_GetBlocks();
    dir = 0;
    ok = 0;
    bx = gWorldMap.x >> 4;
    by = gWorldMap.y >> 4;
    gWorldMap.unk14 = gWorldMap.x;
    gWorldMap.unk16 = gWorldMap.y;
    i = 0;
    if (gUnknown_087DFB90[0] != (keys & 0xF0))
    {
        do
        {
            i++;
            if (i > 7)
                break;
        } while (gUnknown_087DFB90[i] != (keys & 0xF0));
    }
    WorldMap_UpdateLayer(i);

    if ((map->walk[by - 1][bx - 1] & 0xF) == 0)
        blk[0] = 1;
    else
        blk[0] = 0;
    if ((map->walk[by - 1][bx] & 0xF) == 0)
        blk[1] = 1;
    else
        blk[1] = 0;
    if ((map->walk[by - 1][bx + 1] & 0xF) == 0)
        blk[2] = 1;
    else
        blk[2] = 0;
    if ((map->walk[by][bx + 1] & 0xF) == 0)
        blk[3] = 1;
    else
        blk[3] = 0;
    if ((map->walk[by + 1][bx + 1] & 0xF) == 0)
        blk[4] = 1;
    else
        blk[4] = 0;
    if ((map->walk[by + 1][bx] & 0xF) == 0)
        blk[5] = 1;
    else
        blk[5] = 0;
    if ((map->walk[by + 1][bx - 1] & 0xF) == 0)
        blk[6] = 1;
    else
        blk[6] = 0;
    if ((map->walk[by][bx - 1] & 0xF) == 0)
        blk[7] = 1;
    else
        blk[7] = 0;
    n = blk[0] + (blk[1] << 4) + (blk[2] << 8) + (blk[3] << 12) + (blk[4] << 16) + (blk[5] << 20)
      + (blk[6] << 24) + (blk[7] << 28);

    if (keys & 0x40)
        dir += 1;
    if (keys & 0x80)
        dir += 2;
    if (keys & 0x20)
        dir += 4;
    if (keys & 0x10)
        dir += 8;

    switch (dir)
    {
    case 1:
        switch (n & 0xF000FFFF)
        {
        case 0x110:
        case 0x1010:
        case 0x1110:
            gWorldMap.unk14 -= 16;
            gWorldMap.unk16 -= 16;
            ok = 1;
            break;
        case 0x11:
        case 0x10000010:
        case 0x10000011:
            gWorldMap.unk14 += 16;
            gWorldMap.unk16 -= 16;
            ok = 1;
            break;
        default:
            if (blk[1])
                goto end;
            gWorldMap.unk16 -= 16;
            ok = 1;
            break;
        }
        break;
    case 2:
        switch (n & 0xFFFFF000)
        {
        case 0x101000:
        case 0x110000:
        case 0x111000:
            gWorldMap.unk14 -= 16;
            gWorldMap.unk16 += 16;
            ok = 1;
            break;
        case 0x1100000:
        case 0x10100000:
        case 0x11100000:
            gWorldMap.unk14 += 16;
            gWorldMap.unk16 += 16;
            ok = 1;
            break;
        default:
            if (blk[5])
                goto end;
            gWorldMap.unk16 += 16;
            ok = 1;
            break;
        }
        break;
    case 4:
        switch (n & 0xFFF000FF)
        {
        case 0x10100000:
        case 0x11000000:
        case 0x11100000:
            gWorldMap.unk14 -= 16;
            gWorldMap.unk16 -= 16;
            ok = 1;
            break;
        case 0x10000001:
        case 0x10000010:
        case 0x10000011:
            gWorldMap.unk14 -= 16;
            gWorldMap.unk16 += 16;
            ok = 1;
            break;
        default:
            if (blk[7])
                goto end;
            gWorldMap.unk14 -= 16;
            ok = 1;
            break;
        }
        break;
    case 8:
        switch (n & 0x00FFFFF0)
        {
        case 0x1010:
        case 0x1100:
        case 0x1110:
            gWorldMap.unk14 += 16;
            gWorldMap.unk16 += 16;
            ok = 1;
            break;
        case 0x11000:
        case 0x101000:
        case 0x111000:
            gWorldMap.unk14 += 16;
            gWorldMap.unk16 -= 16;
            ok = 1;
            break;
        default:
            if (blk[3])
                goto end;
            gWorldMap.unk14 += 16;
            ok = 1;
            break;
        }
        break;
    case 5:
        if (n & 0xF)
            break;
        if ((n & 0xF0000000) && (n & 0xF0))
            break;
        gWorldMap.unk14 -= 16;
        gWorldMap.unk16 -= 16;
        ok = 1;
        break;
    case 9:
        if (n & 0xF00)
            break;
        if ((n & 0xF000) && (n & 0xF0))
            break;
        gWorldMap.unk14 += 16;
        gWorldMap.unk16 -= 16;
        ok = 1;
        break;
    case 6:
        if (n & 0xF000000)
            break;
        if ((n & 0xF0000000) && (n & 0xF00000))
            break;
        gWorldMap.unk14 -= 16;
        gWorldMap.unk16 += 16;
        ok = 1;
        break;
    case 10:
        if (n & 0xF0000)
            break;
        if ((n & 0xF000) && (n & 0xF00000))
            break;
        gWorldMap.unk14 += 16;
        gWorldMap.unk16 += 16;
        ok = 1;
        break;
    }
end:
    if (ok == 1)
    {
        if (gWorldMap.map == 2 && Flag_Test(0x68))
        {
            px = gWorldMap.unk14;
            py = gWorldMap.unk16 - 8;
            sub_08153C14(&ox, &oy);
            oy -= 0x30;
            if (ox > px)
                dx = ox - px;
            else
                dx = px - ox;
            if (oy > py)
                dy = oy - py;
            else
                dy = py - oy;
            if (dx < 0x18 && dy < 0x28)
                return 0;
        }
        gWorldMap.unk10 = gWorldMap.x;
        gWorldMap.unk12 = gWorldMap.y;
    }
    return ok;
}

// WorldMap_UpdateScroll @ 0x08152EF8
void WorldMap_UpdateScroll(void)
{
    struct MapRecord *rec = FieldMap_GetArea(gWorldMap.map);
    u16 v;

    if (gWorldMap.x > 0x78)
        v = gWorldMap.x - 0x78;
    else
        v = 0;
    if (v > rec->width - 0xF0)
        v = rec->width - 0xF0;
    gUnk_03000008 = gUnk_0300000C = v & 0xFF;
    if (gWorldMap.y > 0x50)
        v = gWorldMap.y - 0x50;
    else
        v = 0;
    if (v > rec->height - 0xA0)
        v = rec->height - 0xA0;
    gUnk_0300000A = gUnk_0300000E = v & 0xFF;
}

// WorldMap_HandleInput @ 0x08152F80
void WorldMap_HandleInput(void)
{
    FieldMap_GetArea(gWorldMap.map);
    WorldMap_GetBlocks();
    if (gKeysNew & 1)
    {
        gWorldMap.unk06 = 0;
        gWorldMap.state = 5;
    }
    else if (gKeysNew & 8)
    {
        gWorldMap.unk06 = 1;
        gWorldMap.state = 5;
    }
    else if ((gKeysNew & 0x100) && sub_0812A7C4() == 1)
    {
        gWorldMap.unk06 = 2;
        gWorldMap.state = 5;
    }
    else if (WorldMap_TryStep(gUnk_030031D0) == 1)
    {
        gWorldMap.state = 2;
        if (gUnk_030031D0 & 2)
            gWorldMap.unk18 = 2;
        else
            gWorldMap.unk18 = 1;
        WorldMap_Walk();
    }
}

// WorldMap_Walk @ 0x0815300C
void WorldMap_Walk(void)
{
    u16 bx, by;
    struct FieldEvent *ev;
    void *obj;
    u32 v;
    u16 ox, oy;
    struct WorldMap *wm;

    WorldMap_GetBlocks();
    if (gWorldMap.x > gWorldMap.unk14)
        gWorldMap.x -= gWorldMap.unk18;
    else if (gWorldMap.x < gWorldMap.unk14)
        gWorldMap.x += gWorldMap.unk18;
    if (gWorldMap.y > gWorldMap.unk16)
        gWorldMap.y -= gWorldMap.unk18;
    else if (gWorldMap.y < gWorldMap.unk16)
        gWorldMap.y += gWorldMap.unk18;
    WorldMap_UpdateScroll();
    WorldMap_DrawLayer(0, 0, 2);
    WorldMap_DrawLayer(0, 1, 3);
    if (gWorldMap.map == 6 && (gWorldMap.x >> 4) == 0x1F && (gWorldMap.y >> 4) == 0x47)
    {
        gWorldMap.state = 12;
        return;
    }
    wm = &gWorldMap;
    if (*(u32 *)&wm->x != *(u32 *)&wm->unk14)
        return;
    if (gWorldMap.state == 13)
    {
        if (WorldMap_FindEvent(gWorldMap.x >> 4, gWorldMap.y >> 4, gWorldMap.map))
            gWorldMap.state = 4;
        else
            gWorldMap.state = 1;
        return;
    }
    bx = gWorldMap.x >> 4;
    by = gWorldMap.y >> 4;
    ev = WorldMap_FindEvent(bx, by, gWorldMap.map);
    obj = sub_080C1B74(&ox, &oy);
    v = WorldMap_CheckSpecialEncounter();
    if (ev != NULL)
    {
        if (ev->script == gUnknown_0803AE54 && (Flag_Test(0x12) || (Random_Byte() & 1)))
            ev = NULL;
        if (ev != NULL)
        {
            gWorldMap.state = 4;
            return;
        }
    }
    if (sub_081537C4() == 1)
        gWorldMap.state = 9;
    else if (gWorldMap.map == 6 && (gWorldMap.x >> 4) == 0x1F && (gWorldMap.y >> 4) == 0x47)
        gWorldMap.state = 12;
    else if (WorldMap_FindLocation(bx, by, gWorldMap.map))
        gWorldMap.state = 3;
    else if (obj != NULL)
    {
        gWorldMap.unk2C = (u32)obj;
        gWorldMap.unk30 = ox;
        gWorldMap.unk32 = oy;
        gWorldMap.state = 7;
    }
    else if (v != 0)
        gWorldMap.state = 8;
    else if (Encounter_Check(1) == 1)
        gWorldMap.state = 6;
    else
    {
        sub_080C2168();
        sub_080C1DE0();
        gWorldMap.state = 1;
    }
}

/* Returns the dungeon map whose floor rectangle contains the current world-map cell. */
// WorldMap_GetDungeonAt @ 0x081531D4
u16 WorldMap_GetDungeonAt(void)
{
    u16 map = 0;
    u16 x = gGameState.pos.x & 0x7F;
    u16 y = gGameState.pos.y & 0x3F;
    u16 n, i;

    for (;; map++)
    {
        n = sub_080C8B3C(map);
        for (i = 0; i < n; i++)
        {
            u16 *f = DungeonMap_GetFloor(map, i);
            if (f[4] <= x && f[5] <= y && f[6] >= x && f[7] >= y
                && SubMap_IsOutsideExclusions(f, x, y) == 1)
                return map;
        }
    }
}

// WorldMap_EnterLocation @ 0x08153264
void WorldMap_EnterLocation(void)
{
    struct WorldPos *pos = WorldMap_FindLocation(gWorldMap.x >> 4, gWorldMap.y >> 4, gWorldMap.map);
    gGameState.pos = *pos;
    sub_080C2D78(WorldMap_GetEncounterTerrain(), WorldMap_GetDungeonAt());
}

// sub_081532B0 @ 0x081532B0
void sub_081532B0(void)
{
    struct FieldEvent *ev = WorldMap_FindEvent(gWorldMap.x >> 4, gWorldMap.y >> 4, gWorldMap.map);
    sub_080C2DE0((u16)WorldMap_GetEncounterTerrain(), ev->script);
}

// sub_081532DC @ 0x081532DC
void sub_081532DC(void)
{
    sub_080C2DE0((u16)WorldMap_GetEncounterTerrain(), gUnknown_0804AE3C);
}

// sub_081532F4 @ 0x081532F4
void sub_081532F4(void)
{
    sub_080C2E10((u16)WorldMap_GetEncounterTerrain(), gWorldMap.unk06);
}

// sub_08153310 @ 0x08153310
void sub_08153310(void)
{
    sub_080C2DC0((u16)WorldMap_GetEncounterTerrain());
}

// sub_08153324 @ 0x08153324
void sub_08153324(void)
{
    struct MapRecord *rec = FieldMap_GetArea(gWorldMap.map);
    Palette_CopyWithEffect(3, (const void *)rec->unkA4, &gPaletteTarget[0x80], 0x100, 0x20);
    PalFade_FadeRangeWithDuration(0x80, 0x80, 1, 0x20);
}

// sub_08153360 @ 0x08153360
void sub_08153360(void)
{
    sub_080C2E44((u16)WorldMap_GetEncounterTerrain(), gUnknown_081988DC);
}

// sub_08153378 @ 0x08153378
void sub_08153378(const void *src, u16 line, u16 count)
{
    Palette_CopyWithEffect(3, src, &gPaletteTarget[line * 16], count, 0x20);
}

// sub_081533A8 @ 0x081533A8
void sub_081533A8(const void *src, u16 line, u16 count)
{
    Palette_CopyWithEffect(3, src, &gPaletteBuffer[line * 16], count, 0x20);
    Palette_MarkDirty();
}

// WorldMap_FindLocation @ 0x081533DC
struct WorldPos *WorldMap_FindLocation(u16 x, u16 y, u16 map)
{
    const struct WorldPos *e = gUnknown_087DF344;

    while (1)
    {
        if (e->unk0 == 0xFF)
            return NULL;
        if (e->map == map && e->unk0 == x && e->unk1 == y)
            return (struct WorldPos *)e;
        e++;
    }
}

// WorldMap_FindLocationByWorldPos @ 0x0815341C
struct WorldPos *WorldMap_FindLocationByWorldPos(u16 x, u16 y)
{
    const struct WorldPos *e = gUnknown_087DF344;

    while (1)
    {
        if (e->x == 0xFF)
            return NULL;
        if (e->x == x && (e->y & 0x3F) == y)
            return (struct WorldPos *)e;
        e++;
    }
}

// WorldMap_FindEvent @ 0x08153458
struct FieldEvent *WorldMap_FindEvent(u16 x, u16 y, u16 map)
{
    const struct FieldEvent *e = gUnknown_087DF54C;
    struct MapRecord *rec = FieldMap_GetArea(gWorldMap.map);

    x += rec->originX;
    y += rec->originY;
    while (1)
    {
        if (e->x == 0xFF)
            return NULL;
        if (e->map == map && (e->x & 0x7F) == x && e->y == y && gWorldMap.unk1C == e->unk3
            && (u16)ScriptVM_RunAlt(e->script))
        {
            if (Flag_Test(0x69) && Flag_Test(0x109)
                && (e->script == gUnknown_080560B6 || e->script == gUnknown_08056154
                    || e->script == gUnknown_080561F2 || e->script == gUnknown_08056290
                    || e->script == gUnknown_0805632E || e->script == gUnknown_080563CC
                    || e->script == gUnknown_0805646A || e->script == gUnknown_08056508))
                return NULL;
            return (struct FieldEvent *)e;
        }
        e++;
    }
}
