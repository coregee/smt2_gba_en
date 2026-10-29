#include "global.h"
#include "fusion.h"

/* Copies an OBJ list (count, then 3 attribute words each) and rotates/scales every OBJ's
   position about the screen origin with the affine matrix made from args[1]. */
// sub_081583F4 @ 0x081583F4
#ifdef NONMATCHING
void sub_081583F4(const u16 **args)
{
    const u16 *p = *args++;
    const u16 *src = *args;
    u16 n = *p++;
    u16 i;

    ObjAffineSet((void *)(src + 1), gUnk_03006A30, 1, 2);
    gUnk_03003800 = n;
    for (i = 0; i < n; i++)
    {
        struct OamAttrs *oam = (struct OamAttrs *)&gUnk_03003802[i * 3];
        u16 *o;
        const u16 *size;
        u32 hw;
        s32 x;
        s32 y;
        s32 nx;
        s32 ny;

        o = (u16 *)oam;
        *o++ = *p++;
        *o++ = *p++;
        *o = *p++;
        size = gUnknown_087F1494[oam->shape][oam->size];
        oam->x = oam->x - 0x80;
        hw = size[0] >> 1;
        x = oam->x + hw;
        y = (size[1] >> 1) + oam->y;
        nx = gUnk_03006A30[0] * x + gUnk_03006A30[1] * y;
        ny = gUnk_03006A30[2] * x + gUnk_03006A30[3] * y;
        oam->x = ((nx & 0x1FF00) >> 8) - hw;
        oam->y = ((ny & 0x1FF00) >> 8) - (size[1] >> 1);
    }
}
#else
NAKED
void sub_081583F4(const u16 **args)
{
    asm_unified(
        ".L081583F4:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x10\n"
        "    ldm r0!, {r7}\n"
        "    ldr r0, [r0]\n"
        "    ldrh r1, [r7]\n"
        "    mov sl, r1\n"
        "    adds r7, #2\n"
        "    adds r0, #2\n"
        "    ldr r4, .L08158500\n"
        "    adds r1, r4, #0\n"
        "    movs r2, #1\n"
        "    movs r3, #2\n"
        "    bl ObjAffineSet\n"
        "    ldr r0, .L08158504\n"
        "    mov r2, sl\n"
        "    strh r2, [r0]\n"
        "    movs r3, #0\n"
        "    mov ip, r3\n"
        "    cmp ip, sl\n"
        "    bhs .L081584EE\n"
        "    mov sb, r4\n"
        ".L08158428:\n"
        "    mov r6, ip\n"
        "    lsls r0, r6, #1\n"
        "    add r0, ip\n"
        "    lsls r0, r0, #1\n"
        "    ldr r1, .L08158508\n"
        "    adds r0, r0, r1\n"
        "    mov r8, r0\n"
        "    ldrh r1, [r7]\n"
        "    strh r1, [r0]\n"
        "    adds r7, #2\n"
        "    adds r0, #2\n"
        "    ldrh r1, [r7]\n"
        "    strh r1, [r0]\n"
        "    adds r7, #2\n"
        "    ldrh r1, [r7]\n"
        "    strh r1, [r0, #2]\n"
        "    adds r7, #2\n"
        "    mov r2, r8\n"
        "    ldrb r5, [r2, #1]\n"
        "    lsrs r5, r5, #6\n"
        "    lsls r5, r5, #4\n"
        "    ldrb r0, [r2, #3]\n"
        "    lsrs r0, r0, #6\n"
        "    lsls r0, r0, #2\n"
        "    ldr r3, .L0815850C\n"
        "    adds r0, r0, r3\n"
        "    adds r5, r5, r0\n"
        "    ldrh r1, [r2, #2]\n"
        "    lsls r0, r1, #0x17\n"
        "    lsrs r0, r0, #0x17\n"
        "    subs r0, #0x80\n"
        "    ldr r6, .L08158510\n"
        "    ands r0, r6\n"
        "    ldr r4, .L08158514\n"
        "    ands r4, r1\n"
        "    orrs r4, r0\n"
        "    strh r4, [r2, #2]\n"
        "    lsls r2, r4, #0x17\n"
        "    lsrs r2, r2, #0x17\n"
        "    ldrh r6, [r5]\n"
        "    lsrs r6, r6, #1\n"
        "    str r6, [sp]\n"
        "    adds r2, r2, r6\n"
        "    ldrh r3, [r5, #2]\n"
        "    lsrs r3, r3, #1\n"
        "    mov r0, r8\n"
        "    ldrb r0, [r0]\n"
        "    adds r3, r3, r0\n"
        "    mov r1, sb\n"
        "    movs r6, #0\n"
        "    ldrsh r0, [r1, r6]\n"
        "    adds r1, r0, #0\n"
        "    muls r1, r2, r1\n"
        "    str r1, [sp, #4]\n"
        "    mov r6, sb\n"
        "    movs r1, #2\n"
        "    ldrsh r0, [r6, r1]\n"
        "    muls r0, r3, r0\n"
        "    ldr r6, [sp, #4]\n"
        "    adds r1, r6, r0\n"
        "    mov r0, sb\n"
        "    movs r6, #4\n"
        "    ldrsh r0, [r0, r6]\n"
        "    adds r6, r2, #0\n"
        "    muls r6, r0, r6\n"
        "    str r6, [sp, #0xc]\n"
        "    mov r2, sb\n"
        "    movs r6, #6\n"
        "    ldrsh r0, [r2, r6]\n"
        "    muls r0, r3, r0\n"
        "    ldr r3, [sp, #0xc]\n"
        "    adds r2, r3, r0\n"
        "    ldr r6, .L08158518\n"
        "    ands r1, r6\n"
        "    asrs r1, r1, #8\n"
        "    ldr r0, [sp]\n"
        "    subs r1, r1, r0\n"
        "    ldr r3, .L08158510\n"
        "    ands r1, r3\n"
        "    ldr r6, .L08158514\n"
        "    ands r4, r6\n"
        "    orrs r4, r1\n"
        "    mov r0, r8\n"
        "    strh r4, [r0, #2]\n"
        "    ldr r1, .L08158518\n"
        "    ands r2, r1\n"
        "    asrs r2, r2, #8\n"
        "    ldrh r0, [r5, #2]\n"
        "    lsrs r0, r0, #1\n"
        "    subs r2, r2, r0\n"
        "    mov r3, r8\n"
        "    strb r2, [r3]\n"
        "    mov r0, ip\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov ip, r0\n"
        "    cmp ip, sl\n"
        "    blo .L08158428\n"
        ".L081584EE:\n"
        "    add sp, #0x10\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L08158500: .4byte 0x03006A30 @ IWRAM+0x6A30\n"
        ".L08158504: .4byte 0x03003800 @ IWRAM+0x3800\n"
        ".L08158508: .4byte 0x03003802 @ IWRAM+0x3802\n"
        ".L0815850C: .4byte gUnknown_087F1494\n"
        ".L08158510: .4byte 0x000001FF\n"
        ".L08158514: .4byte 0xFFFFFE00\n"
        ".L08158518: .4byte 0x0001FF00\n"
    );
}
#endif

/* As sub_081583F4 with 8-bit wrapping of the rotated x. */
// sub_0815851C @ 0x0815851C
#ifdef NONMATCHING
void sub_0815851C(const u16 **args)
{
    const u16 *p = *args++;
    const u16 *src = *args;
    u16 n = *p++;
    u16 i;

    ObjAffineSet((void *)(src + 1), gUnk_03006A30, 1, 2);
    gUnk_03003800 = n;
    for (i = 0; i < n; i++)
    {
        struct OamAttrs *oam = (struct OamAttrs *)&gUnk_03003802[i * 3];
        u16 *o;
        const u16 *size;
        u32 hw;
        s32 x;
        s32 y;
        s32 nx;
        s32 ny;

        o = (u16 *)oam;
        *o++ = *p++;
        *o++ = *p++;
        *o = *p++;
        size = gUnknown_087F1494[oam->shape][oam->size];
        hw = size[0] >> 1;
        x = oam->x + hw;
        y = (size[1] >> 1) + oam->y;
        nx = gUnk_03006A30[0] * x + gUnk_03006A30[1] * y;
        ny = gUnk_03006A30[2] * x + gUnk_03006A30[3] * y;
        oam->x = ((nx & 0xFF00) >> 8) - hw;
        oam->y = (u32)(ny << 15) >> 23;
        oam->y -= size[1] >> 1;
    }
}
#else
NAKED
void sub_0815851C(const u16 **args)
{
    asm_unified(
        ".L0815851C:\n"
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x10\n"
        "    ldm r0!, {r7}\n"
        "    ldr r0, [r0]\n"
        "    ldrh r1, [r7]\n"
        "    mov sl, r1\n"
        "    adds r7, #2\n"
        "    adds r0, #2\n"
        "    ldr r4, .L08158614\n"
        "    adds r1, r4, #0\n"
        "    movs r2, #1\n"
        "    movs r3, #2\n"
        "    bl ObjAffineSet\n"
        "    ldr r0, .L08158618\n"
        "    mov r2, sl\n"
        "    strh r2, [r0]\n"
        "    movs r3, #0\n"
        "    mov ip, r3\n"
        "    cmp ip, sl\n"
        "    bhs .L08158604\n"
        "    mov sb, r4\n"
        ".L08158550:\n"
        "    mov r5, ip\n"
        "    lsls r0, r5, #1\n"
        "    add r0, ip\n"
        "    lsls r0, r0, #1\n"
        "    ldr r1, .L0815861C\n"
        "    adds r0, r0, r1\n"
        "    adds r6, r0, #0\n"
        "    ldrh r1, [r7]\n"
        "    strh r1, [r0]\n"
        "    adds r7, #2\n"
        "    adds r0, #2\n"
        "    ldrh r1, [r7]\n"
        "    strh r1, [r0]\n"
        "    adds r7, #2\n"
        "    ldrh r1, [r7]\n"
        "    strh r1, [r0, #2]\n"
        "    adds r7, #2\n"
        "    ldrb r4, [r6, #1]\n"
        "    lsrs r4, r4, #6\n"
        "    lsls r4, r4, #4\n"
        "    ldrb r0, [r6, #3]\n"
        "    lsrs r0, r0, #6\n"
        "    lsls r0, r0, #2\n"
        "    ldr r2, .L08158620\n"
        "    adds r0, r0, r2\n"
        "    adds r4, r4, r0\n"
        "    ldrh r3, [r6, #2]\n"
        "    mov r8, r3\n"
        "    mov r5, r8\n"
        "    lsls r2, r5, #0x17\n"
        "    lsrs r2, r2, #0x17\n"
        "    ldrh r5, [r4]\n"
        "    lsrs r5, r5, #1\n"
        "    str r5, [sp]\n"
        "    adds r2, r2, r5\n"
        "    ldrh r3, [r4, #2]\n"
        "    lsrs r3, r3, #1\n"
        "    ldrb r0, [r6]\n"
        "    adds r3, r3, r0\n"
        "    mov r1, sb\n"
        "    movs r5, #0\n"
        "    ldrsh r0, [r1, r5]\n"
        "    adds r1, r0, #0\n"
        "    muls r1, r2, r1\n"
        "    str r1, [sp, #4]\n"
        "    mov r5, sb\n"
        "    movs r1, #2\n"
        "    ldrsh r0, [r5, r1]\n"
        "    muls r0, r3, r0\n"
        "    ldr r5, [sp, #4]\n"
        "    adds r1, r5, r0\n"
        "    mov r0, sb\n"
        "    movs r5, #4\n"
        "    ldrsh r0, [r0, r5]\n"
        "    adds r5, r2, #0\n"
        "    muls r5, r0, r5\n"
        "    str r5, [sp, #0xc]\n"
        "    mov r2, sb\n"
        "    movs r5, #6\n"
        "    ldrsh r0, [r2, r5]\n"
        "    muls r0, r3, r0\n"
        "    ldr r3, [sp, #0xc]\n"
        "    adds r2, r3, r0\n"
        "    movs r0, #0xff\n"
        "    lsls r0, r0, #8\n"
        "    ands r1, r0\n"
        "    asrs r1, r1, #8\n"
        "    ldr r5, [sp]\n"
        "    subs r1, r1, r5\n"
        "    ldr r3, .L08158624\n"
        "    adds r0, r3, #0\n"
        "    ands r1, r0\n"
        "    ldr r0, .L08158628\n"
        "    mov r5, r8\n"
        "    ands r0, r5\n"
        "    orrs r0, r1\n"
        "    strh r0, [r6, #2]\n"
        "    lsls r2, r2, #0xf\n"
        "    lsrs r2, r2, #0x17\n"
        "    ldrh r0, [r4, #2]\n"
        "    lsrs r0, r0, #1\n"
        "    subs r2, r2, r0\n"
        "    strb r2, [r6]\n"
        "    mov r0, ip\n"
        "    adds r0, #1\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r0, r0, #0x10\n"
        "    mov ip, r0\n"
        "    cmp ip, sl\n"
        "    blo .L08158550\n"
        ".L08158604:\n"
        "    add sp, #0x10\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L08158614: .4byte 0x03006A30 @ IWRAM+0x6A30\n"
        ".L08158618: .4byte 0x03003800 @ IWRAM+0x3800\n"
        ".L0815861C: .4byte 0x03003802 @ IWRAM+0x3802\n"
        ".L08158620: .4byte gUnknown_087F1494\n"
        ".L08158624: .4byte 0x000001FF\n"
        ".L08158628: .4byte 0xFFFFFE00\n"
    );
}
#endif
