/* OBJ list transforms, continued (see objaffine_a.c): the OBJ list at args[0] (count, then
   3 attribute words each) is copied to gUnk_03003800 and each OBJ's position is moved. */

#include "global.h"
#include "fusion.h"

struct ObjAttr
{
    u16 y:8;
    u16 affineMode:2;   /* bit 1: double-size affine OBJ */
    u16 objMode:2;
    u16 mosaic:1;
    u16 bpp:1;
    u16 shape:2;
    u16 x:9;
    u16 matrix:5;
    u16 size:2;
    u16 attr2;
};

/* Scales every OBJ's position about the screen origin: by sx/w, sy/h (w, h = half the OBJ
   size, or the full size for double-size affine OBJs), or by sx/d, sy/d when d != 0. Each
   axis works on the distance from the origin (|x| folded to 0-0x7F) and puts the sign back. */
// ObjList_ScalePositions @ 0x0815862C
#ifdef NONMATCHING
void ObjList_ScalePositions(const u16 **args, u16 sx, u16 sy, u16 d)
{
    const u16 *p = *args++;
    const u16 *src = *args;
    u16 n = *p++;
    u16 i;

    ObjAffineSet((void *)(src + 1), gUnk_03006A30, 1, 2);
    gUnk_03003800 = n;
    for (i = 0; i < n; i++)
    {
        struct ObjAttr *oam = (struct ObjAttr *)&gUnk_03003802[i * 3];
        u16 *o;
        const u16 *size;
        u16 w;
        u16 h;
        u32 x;
        u32 y;
        u16 kx;
        u16 ky;
        u8 mode;

        o = (u16 *)oam;
        *o++ = *p++;
        *o++ = *p++;
        *o = *p++;
        size = gUnknown_087F1494[oam->shape][oam->size];
        w = size[0];
        h = size[1];
        mode = oam->affineMode;
        if (!(mode & 2))
        {
            w >>= 1;
            h >>= 1;
        }
        x = (w + oam->x) & 0x1FF;
        y = (h + oam->y) & 0xFF;
        if (d == 0)
        {
            kx = sx * w / 256;
            ky = sy * h / 256;
        }
        else
        {
            kx = sx * d / 256;
            ky = sy * d / 256;
        }
        if (x & 0x100)
            x = -x & 0x7F;
        if (y & 0x80)
            y = -y & 0x7F;
        if (d == 0)
        {
            x = (s32)(kx * x) / w & 0x1FF;
            y = (s32)(ky * y) / h & 0xFF;
        }
        else
        {
            x = (s32)(kx * x) / d & 0x1FF;
            y = (s32)(ky * y) / d & 0xFF;
        }
        if ((oam->x + w) & 0x100)
            oam->x = (-x & 0x1FF) - w;
        else
            oam->x = x - w;
        if ((oam->y + h) & 0x80)
            oam->y = -y - h;
        else
            oam->y = y - h;
    }
}
#else
NAKED
void ObjList_ScalePositions(const u16 **args, u16 sx, u16 sy, u16 d)
{
    asm_unified(
        ".L0815862C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x1c\n"
        "    lsls r1, r1, #0x10\n"
        "    lsrs r1, r1, #0x10\n"
        "    str r1, [sp]\n"
        "    lsls r2, r2, #0x10\n"
        "    lsrs r2, r2, #0x10\n"
        "    str r2, [sp, #4]\n"
        "    lsls r3, r3, #0x10\n"
        "    lsrs r3, r3, #0x10\n"
        "    str r3, [sp, #8]\n"
        "    ldm r0!, {r1}\n"
        "    mov sb, r1\n"
        "    ldr r0, [r0]\n"
        "    ldrh r2, [r1]\n"
        "    str r2, [sp, #0xc]\n"
        "    movs r1, #2\n"
        "    add sb, r1\n"
        "    adds r0, #2\n"
        "    ldr r1, .L08158700\n"
        "    movs r2, #1\n"
        "    movs r3, #2\n"
        "    bl ObjAffineSet\n"
        "    ldr r0, .L08158704\n"
        "    mov r2, sp\n"
        "    ldrh r2, [r2, #0xc]\n"
        "    strh r2, [r0]\n"
        "    movs r0, #0\n"
        "    str r0, [sp, #0x10]\n"
        "    ldr r1, [sp, #0xc]\n"
        "    cmp r0, r1\n"
        "    blo .L08158678\n"
        "    b .L08158812\n"
        ".L08158678:\n"
        "    ldr r2, [sp, #0x10]\n"
        "    lsls r0, r2, #1\n"
        "    adds r0, r0, r2\n"
        "    lsls r0, r0, #1\n"
        "    ldr r1, .L08158708\n"
        "    adds r7, r0, r1\n"
        "    mov r1, sb\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r7]\n"
        "    movs r2, #2\n"
        "    add sb, r2\n"
        "    mov r1, sb\n"
        "    ldrh r0, [r1]\n"
        "    strh r0, [r7, #2]\n"
        "    add sb, r2\n"
        "    mov r2, sb\n"
        "    ldrh r0, [r2]\n"
        "    strh r0, [r7, #4]\n"
        "    movs r0, #2\n"
        "    add sb, r0\n"
        "    ldrb r2, [r7, #1]\n"
        "    lsrs r3, r2, #6\n"
        "    lsls r3, r3, #4\n"
        "    ldrb r0, [r7, #3]\n"
        "    lsrs r0, r0, #6\n"
        "    lsls r0, r0, #2\n"
        "    ldr r1, .L0815870C\n"
        "    adds r0, r0, r1\n"
        "    adds r3, r3, r0\n"
        "    ldrh r6, [r3]\n"
        "    ldrh r3, [r3, #2]\n"
        "    lsls r2, r2, #0x1e\n"
        "    lsrs r2, r2, #0x1e\n"
        "    movs r0, #2\n"
        "    ands r2, r0\n"
        "    cmp r2, #0\n"
        "    bne .L081586C6\n"
        "    lsrs r6, r6, #1\n"
        "    lsrs r3, r3, #1\n"
        ".L081586C6:\n"
        "    ldrh r2, [r7, #2]\n"
        "    lsls r0, r2, #0x17\n"
        "    lsrs r0, r0, #0x17\n"
        "    adds r4, r6, r0\n"
        "    ldr r1, .L08158710\n"
        "    adds r0, r1, #0\n"
        "    ands r4, r0\n"
        "    ldrb r1, [r7]\n"
        "    adds r5, r3, r1\n"
        "    movs r0, #0xff\n"
        "    ands r5, r0\n"
        "    mov sl, r2\n"
        "    str r1, [sp, #0x14]\n"
        "    ldr r2, [sp, #8]\n"
        "    cmp r2, #0\n"
        "    bne .L08158714\n"
        "    ldr r1, [sp]\n"
        "    adds r0, r1, #0\n"
        "    muls r0, r6, r0\n"
        "    cmp r0, #0\n"
        "    bge .L081586F2\n"
        "    adds r0, #0xff\n"
        ".L081586F2:\n"
        "    lsls r0, r0, #8\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov ip, r0\n"
        "    ldr r2, [sp, #4]\n"
        "    adds r0, r2, #0\n"
        "    muls r0, r3, r0\n"
        "    b .L08158730\n"
        ".L08158700: .4byte 0x03006A30 @ IWRAM+0x6A30\n"
        ".L08158704: .4byte 0x03003800 @ IWRAM+0x3800\n"
        ".L08158708: .4byte 0x03003802 @ IWRAM+0x3802\n"
        ".L0815870C: .4byte gUnknown_087F1494\n"
        ".L08158710: .4byte 0x000001FF\n"
        ".L08158714:\n"
        "    ldr r1, [sp]\n"
        "    ldr r2, [sp, #8]\n"
        "    adds r0, r1, #0\n"
        "    muls r0, r2, r0\n"
        "    cmp r0, #0\n"
        "    bge .L08158722\n"
        "    adds r0, #0xff\n"
        ".L08158722:\n"
        "    lsls r0, r0, #8\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov ip, r0\n"
        "    ldr r1, [sp, #4]\n"
        "    ldr r2, [sp, #8]\n"
        "    adds r0, r1, #0\n"
        "    muls r0, r2, r0\n"
        ".L08158730:\n"
        "    cmp r0, #0\n"
        "    bge .L08158736\n"
        "    adds r0, #0xff\n"
        ".L08158736:\n"
        "    lsls r0, r0, #8\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov r8, r0\n"
        "    movs r0, #0x80\n"
        "    lsls r0, r0, #1\n"
        "    adds r1, r0, #0\n"
        "    adds r0, r4, #0\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L08158750\n"
        "    rsbs r4, r4, #0\n"
        "    movs r0, #0x7f\n"
        "    ands r4, r0\n"
        ".L08158750:\n"
        "    movs r0, #0x80\n"
        "    ands r0, r5\n"
        "    cmp r0, #0\n"
        "    beq .L0815875E\n"
        "    rsbs r5, r5, #0\n"
        "    movs r0, #0x7f\n"
        "    ands r5, r0\n"
        ".L0815875E:\n"
        "    ldr r1, [sp, #8]\n"
        "    cmp r1, #0\n"
        "    bne .L08158788\n"
        "    mov r0, ip\n"
        "    muls r0, r4, r0\n"
        "    adds r1, r6, #0\n"
        "    str r3, [sp, #0x18]\n"
        "    bl __divsi3\n"
        "    adds r4, r0, #0\n"
        "    ldr r2, .L08158784\n"
        "    adds r0, r2, #0\n"
        "    ands r4, r0\n"
        "    mov r0, r8\n"
        "    muls r0, r5, r0\n"
        "    ldr r3, [sp, #0x18]\n"
        "    adds r1, r3, #0\n"
        "    b .L081587A2\n"
        "    .byte 0x00, 0x00\n"
        ".L08158784: .4byte 0x000001FF\n"
        ".L08158788:\n"
        "    mov r0, ip\n"
        "    muls r0, r4, r0\n"
        "    ldr r1, [sp, #8]\n"
        "    str r3, [sp, #0x18]\n"
        "    bl __divsi3\n"
        "    adds r4, r0, #0\n"
        "    ldr r1, .L081587CC\n"
        "    adds r0, r1, #0\n"
        "    ands r4, r0\n"
        "    mov r0, r8\n"
        "    muls r0, r5, r0\n"
        "    ldr r1, [sp, #8]\n"
        ".L081587A2:\n"
        "    bl __divsi3\n"
        "    adds r5, r0, #0\n"
        "    movs r0, #0xff\n"
        "    ands r5, r0\n"
        "    ldr r3, [sp, #0x18]\n"
        "    mov r2, sl\n"
        "    lsls r0, r2, #0x17\n"
        "    lsrs r0, r0, #0x17\n"
        "    adds r0, r0, r6\n"
        "    movs r1, #0x80\n"
        "    lsls r1, r1, #1\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L081587D0\n"
        "    rsbs r1, r4, #0\n"
        "    ldr r0, .L081587CC\n"
        "    ands r1, r0\n"
        "    subs r1, r1, r6\n"
        "    b .L081587D4\n"
        "    .byte 0x00, 0x00\n"
        ".L081587CC: .4byte 0x000001FF\n"
        ".L081587D0:\n"
        "    subs r1, r4, r6\n"
        "    ldr r0, .L081587F4\n"
        ".L081587D4:\n"
        "    ands r1, r0\n"
        "    ldr r2, .L081587F8\n"
        "    adds r0, r2, #0\n"
        "    mov r2, sl\n"
        "    ands r0, r2\n"
        "    orrs r0, r1\n"
        "    strh r0, [r7, #2]\n"
        "    ldr r1, [sp, #0x14]\n"
        "    adds r0, r1, r3\n"
        "    movs r1, #0x80\n"
        "    ands r0, r1\n"
        "    cmp r0, #0\n"
        "    beq .L081587FC\n"
        "    rsbs r0, r5, #0\n"
        "    subs r0, r0, r3\n"
        "    b .L081587FE\n"
        ".L081587F4: .4byte 0x000001FF\n"
        ".L081587F8: .4byte 0xFFFFFE00\n"
        ".L081587FC:\n"
        "    subs r0, r5, r3\n"
        ".L081587FE:\n"
        "    strb r0, [r7]\n"
        "    ldr r0, [sp, #0x10]\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    str r0, [sp, #0x10]\n"
        "    ldr r2, [sp, #0xc]\n"
        "    cmp r0, r2\n"
        "    bhs .L08158812\n"
        "    b .L08158678\n"
        ".L08158812:\n"
        "    add sp, #0x1c\n"
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

/* Rotates/scales every OBJ about the screen origin with the matrix made from args[1],
   treating positions as signed (x 9-bit, y 8-bit), from the OBJ's centre. */
// ObjList_RotatePositions @ 0x08158824
void ObjList_RotatePositions(const u16 **args)
{
    const u16 *p = *args++;
    const u16 *src = *args;
    u16 n = *p++;
    u16 i;

    ObjAffineSet((void *)(src + 1), gUnk_03006A30, 1, 2);
    gUnk_03003800 = n;
    for (i = 0; i < n; i++)
    {
        struct ObjAttr *oam = (struct ObjAttr *)&gUnk_03003802[i * 3];
        u16 *o;
        const u16 *size;
        u16 w;
        u16 h;
        s32 x;
        s32 y;
        s32 nx;
        u8 mode;
        s32 ny;

        o = (u16 *)oam;
        *o++ = *p++;
        *o++ = *p++;
        *o = *p++;
        size = gUnknown_087F1494[oam->shape][oam->size];
        w = size[0];
        h = size[1];
        mode = oam->affineMode;
        if (!(mode & 2))
        {
            w >>= 1;
            h >>= 1;
        }
        x = (oam->x + w) & 0x1FF;
        if (x & 0x100)
            x |= 0xFFFFFF00;
        y = (oam->y + h) & 0xFF;
        if (y & 0x80)
            y |= 0xFFFFFF00;
        nx = gUnk_03006A30[0] * x + gUnk_03006A30[1] * y;
        ny = gUnk_03006A30[2] * x + gUnk_03006A30[3] * y;
        oam->x = ((nx & 0xFFFFFF00) >> 8) - w;
        oam->y = ((ny & 0xFFFFFF00) >> 8) - h;
    }
}
