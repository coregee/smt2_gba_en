#include "global.h"
#include "extras.h"

// sub_080DD160 @ 0x080DD160
void sub_080DD160(struct Task *task)
{
    task->result = 0;
    task->unk1E = 0;
    if (gKeysNew & 1)
    {
        task->unk1E = task->data.h[0];
        sub_080C51D4(0x65);
        task->result = 1;
    }
    else if (gKeysNew & 2)
    {
        sub_080C51D4(0x66);
        task->result = 1;
    }
    else
    {
        u16 up = gRepeatedKeys & 0x40;

        if (up)
        {
            if (task->data.h[0] != 0)
                task->data.h[0]--;
            else
                task->data.h[0] = 1;
            sub_080C51D4(0x64);
        }
        else if (gRepeatedKeys & 0x80)
        {
            if (task->data.h[0] != 1)
                task->data.h[0]++;
            else
                task->data.h[0] = up;
            sub_080C51D4(0x64);
        }
    }
}

// sub_080DD1E4 @ 0x080DD1E4
void sub_080DD1E4(struct Task *task)
{
    struct Task *parent = Task_GetParent(task);
    struct Task *grandparent = Task_GetParent(parent);

    sub_080C3818(1);
    Task_End(parent);
    grandparent->wait = 1;
}

// sub_080DD208 @ 0x080DD208
void sub_080DD208(void)
{
    PalFade_FadeRangeToBlack(0x1E0, 0x10, 1);
}

/* The map record's event script for a demon id, or NULL past the table. */
// Dict_GetMapScript @ 0x080DD21C
#ifdef NONMATCHING
const void *Dict_GetMapScript(u16 id)
{
    const void *script;

    if (id <= 0x17B)
        script = (gUnknown_08583E84 + id)->script;
    else
        script = NULL;
    return script;
}
#else
NAKED
const void *Dict_GetMapScript(u16 id)
{
    asm_unified(
        ".L080DD21C:\n"
        "    push {lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r2, r0, #0x10\n"
        "    ldr r0, .L080DD238\n"
        "    cmp r2, r0\n"
        "    bhi .L080DD240\n"
        "    ldr r0, .L080DD23C\n"
        "    lsls r1, r2, #2\n"
        "    adds r1, r1, r2\n"
        "    lsls r1, r1, #2\n"
        "    adds r1, r1, r0\n"
        "    ldr r0, [r1]\n"
        "    b .L080DD242\n"
        "    .byte 0x00, 0x00\n"
        ".L080DD238: .4byte 0x0000017B\n"
        ".L080DD23C: .4byte gUnknown_08583E84\n"
        ".L080DD240:\n"
        "    movs r0, #0\n"
        ".L080DD242:\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

/* Whether a demon can be listed: always for ids up to 0xFE after sub_080C2600, otherwise
   only when it has a map record script. */
// sub_080DD248 @ 0x080DD248
#ifdef NONMATCHING
u32 sub_080DD248(u16 id)
{
    u16 v;

    if (id > 0x17B)
        return 0;
    v = sub_080C2600(id);
    if (v <= 0xFE)
        return 1;
    /* called without a prototype in the original: v is passed unnarrowed */
    return ((u32 (*)())Dict_GetMapScript)(v);
}
#else
NAKED
u32 sub_080DD248(u16 id)
{
    asm_unified(
        ".L080DD248:\n"
        "    push {lr}\n"
        "    lsls r0, r0, #0x10\n"
        "    lsrs r1, r0, #0x10\n"
        "    ldr r0, .L080DD258\n"
        "    cmp r1, r0\n"
        "    bls .L080DD25C\n"
        "    movs r0, #0\n"
        "    b .L080DD272\n"
        ".L080DD258: .4byte 0x0000017B\n"
        ".L080DD25C:\n"
        "    adds r0, r1, #0\n"
        "    bl sub_080C2600\n"
        "    adds r1, r0, #0\n"
        "    cmp r1, #0xfe\n"
        "    bls .L080DD270\n"
        "    adds r0, r1, #0\n"
        "    bl Dict_GetMapScript\n"
        "    b .L080DD272\n"
        ".L080DD270:\n"
        "    movs r0, #1\n"
        ".L080DD272:\n"
        "    pop {r1}\n"
        "    bx r1\n"
        "    .byte 0x00, 0x00\n"
    );
}
#endif

// sub_080DD278 @ 0x080DD278
#ifdef NONMATCHING
void sub_080DD278(struct Task *task)
{
    u8 *g = task->data.raw;
    u32 zero = 0;

    g[0] = zero;
    g[1] = 1;
    g[2] = 1;
    *(u16 *)(g + 0x12) = 0xFF;
    g[3] = 0;
    g[4] = 0;
    g[5] = 0;
    g[6] = 0;
    g[7] = 0;
    g[8] = 0;
    g[9] = 0;
    g[10] = 0;
    g[11] = 0;
    g[14] = 0;
    g[13] = 0;
    g[12] = 0;
    *(u16 *)(g + 0x10) = zero;
    g[0x30] = 0;
    m4aMPlayAllStop();
    gUnk_030031B4 = zero;
    Cards_Deal(task);
}
#else
NAKED
void sub_080DD278(struct Task *task)
{
    asm_unified(
        "    push {r4, r5, lr}\n"
        "    adds r5, r0, #0\n"
        "    adds r0, #0x24\n"
        "    movs r4, #0\n"
        "    strb r4, [r0]\n"
        "    movs r1, #1\n"
        "    strb r1, [r0, #1]\n"
        "    strb r1, [r0, #2]\n"
        "    movs r1, #0\n"
        "    movs r2, #0xff\n"
        "    strh r2, [r0, #0x12]\n"
        "    strb r1, [r0, #3]\n"
        "    strb r1, [r0, #4]\n"
        "    strb r1, [r0, #5]\n"
        "    strb r1, [r0, #6]\n"
        "    strb r1, [r0, #7]\n"
        "    strb r1, [r0, #8]\n"
        "    strb r1, [r0, #9]\n"
        "    strb r1, [r0, #0xa]\n"
        "    strb r1, [r0, #0xb]\n"
        "    strb r1, [r0, #0xe]\n"
        "    strb r1, [r0, #0xd]\n"
        "    strb r1, [r0, #0xc]\n"
        "    strh r4, [r0, #0x10]\n"
        "    adds r0, #0x30\n"
        "    strb r1, [r0]\n"
        "    bl m4aMPlayAllStop\n"
        "    ldr r0, .L080DD2C0\n"
        "    strh r4, [r0]\n"
        "    adds r0, r5, #0\n"
        "    bl Cards_Deal\n"
        "    pop {r4, r5}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080DD2C0: .4byte 0x030031B4 @ IWRAM+0x31B4\n"
    );
}
#endif

// sub_080DD2C4 @ 0x080DD2C4
void sub_080DD2C4(void)
{
    Palette_CopyWithEffect(3, gUnknown_08580E40, gPaletteTarget + 0x1E0, 0x40, 0x20);
}

// sub_080DD2E8 @ 0x080DD2E8
void sub_080DD2E8(void)
{
    DmaSet3(gUnk_02001000, 0x06012800, 0x84001200);
}
