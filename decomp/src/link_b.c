#include "global.h"
#include "extras.h"

// sub_080DF2E8 @ 0x080DF2E8
#ifdef NONMATCHING
void sub_080DF2E8(void)
{
    Link_InitSerial();
    gUnk_03006380 = 200;
    gUnk_03006360 = 0;
    gUnk_03006368 = 0;
    gUnk_030062F0 = 1;
}
#else
NAKED
void sub_080DF2E8(void)
{
    asm_unified(
        ".L080DF2E8:\n"
        "    push {lr}\n"
        "    bl Link_InitSerial\n"
        "    ldr r1, .L080DF30C\n"
        "    movs r3, #0\n"
        "    movs r2, #0\n"
        "    movs r0, #0xc8\n"
        "    strh r0, [r1]\n"
        "    ldr r0, .L080DF310\n"
        "    str r2, [r0]\n"
        "    ldr r0, .L080DF314\n"
        "    strb r3, [r0]\n"
        "    ldr r1, .L080DF318\n"
        "    movs r0, #1\n"
        "    strb r0, [r1]\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .byte 0x00, 0x00\n"
        ".L080DF30C: .4byte 0x03006380 @ IWRAM+0x6380\n"
        ".L080DF310: .4byte 0x03006360 @ IWRAM+0x6360\n"
        ".L080DF314: .4byte 0x03006368 @ IWRAM+0x6368\n"
        ".L080DF318: .4byte 0x030062F0 @ IWRAM+0x62F0\n"
    );
}
#endif

// sub_080DF31C @ 0x080DF31C
void sub_080DF31C(void)
{
    sub_080DEF00();
    gUnk_03003970 = 0;
}

// sub_080DF330 @ 0x080DF330
void sub_080DF330(void)
{
    sub_080DEEE8();
    REG_IME = 0;
    REG_IE = 0x20C3;
    REG_IME = 1;
    gUnk_03003970 = 1;
}

// sub_080DF360 @ 0x080DF360
void sub_080DF360(void)
{
    MultiSio_SetSendData(&gUnk_03006380);
}

// sub_080DF370 @ 0x080DF370
void sub_080DF370(void)
{
    gUnk_03006360 = MultiSio_Main(gUnk_03006340);
}
