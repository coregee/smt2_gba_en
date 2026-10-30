#include "global.h"
#include "fieldcmd.h"

// sub_080BD878 @ 0x080BD878
void sub_080BD878(void)
{
    u32 i;

    for (i = 0; i <= 7; i++)
    {
        if (gPalFades[i].active)
            gPalFades[i].unk04 = 8;
    }
}

// sub_080BD898 @ 0x080BD898
void sub_080BD898(void)
{
    PalFade_FadeRangeToBlack(0x1D0, 0x30, 1);
}

// sub_080BD8AC @ 0x080BD8AC
void sub_080BD8AC(void)
{
    if (gUnk_03004534 == 0x1C)
        PalFade_FadeRangeToBlack(0x70, 0x10, 1);
}

// sub_080BD8C8 @ 0x080BD8C8
void sub_080BD8C8(void)
{
    DmaFill32(3, 0, (void *)0x06001000, 0x1000);
}

// sub_080BD8F0 @ 0x080BD8F0
void sub_080BD8F0(void)
{
    if (gUnk_03004534 == 0x1C)
    {
        VBlankTask_AddCounted(sub_080BD8C8, 1);
    }
    else if (gMainCallback == sub_080D977C)
    {
        gUnk_0300000E = 0;
        gUnk_03000006 = 0;
        VBlankTask_AddCounted(sub_080BD8C8, 1);
    }
}

// sub_080BD940 @ 0x080BD940
void sub_080BD940(void)
{
    Flag_Set(0xFD);
}

// sub_080BD94C @ 0x080BD94C
void sub_080BD94C(u32 a)
{
    sub_08157EB0(1, a, 0);
}

// sub_080BD95C @ 0x080BD95C
void sub_080BD95C(struct Task *task)
{
    u16 *d = task->data.h;
    struct Task *t;

    if (gUnk_03004534 == 0x86)
        task->data.h[0] = 0x182;
    else if (gUnk_03004534 >= 0x8A && gUnk_03004534 <= 0x8E)
        task->data.h[0] = 0x18E;
    t = Char_FindById(d[0]);
    if (t != NULL)
        t->wait = 1;
}

// sub_080BD99C @ 0x080BD99C
void sub_080BD99C(struct Task *task)
{
    task->result = 0;
    if (Char_FindById(task->data.h[0]) == NULL)
        task->result = 1;
}

// sub_080BD9B8 @ 0x080BD9B8
void sub_080BD9B8(void)
{
    Inventory_RemoveItem(gScriptItemCheckId);
}

// sub_080BD9CC @ 0x080BD9CC
void sub_080BD9CC(void)
{
    Inventory_AddItem(gScriptItemCheckId);
}

// sub_080BD9E0 @ 0x080BD9E0
void sub_080BD9E0(void)
{
    gUnk_0203DB28[1] = gUnk_0203DB28[0];
}

// sub_080BD9EC @ 0x080BD9EC
void sub_080BD9EC(void)
{
    sub_080B8AE0(0x1F, 1);
}

// sub_080BD9FC @ 0x080BD9FC
void sub_080BD9FC(void)
{
    sub_080B8AE0(0x3FF, 1);
}

// sub_080BDA10 @ 0x080BDA10
void sub_080BDA10(struct Task *task, u32 on)
{
    if (on == 1)
        Flag_Set(0x108);
    else
        Flag_Clear(0x108);
    gFieldState.unk52 = 0;
}

// Wave_VBlank @ 0x080BDA38
/* VBlank half of the wavy-background effect: enables the HBlank interrupt and advances
   the wave phase every other frame. */
void Wave_VBlank(void)
{
    REG_IE |= 2;
    REG_DISPSTAT |= 0x10;
    if (!(gFrameCounter & 1))
        gFieldState.unk52 = (gFieldState.unk52 + 1) & 0x3F;
}

// Wave_Disable @ 0x080BDA7C
void Wave_Disable(void)
{
    REG_IE &= ~2;
    REG_DISPSTAT &= ~0x10;
    gIntrTable[1] = IntrDummy;
}

// Wave_HBlank @ 0x080BDAB0
#ifdef NONMATCHING
/* HBlank handler: shifts BG3 and BG1 by a sine of (phase + line) on the top 100 lines. */
void Wave_HBlank(void)
{
    u8 line = *(vu8 *)0x04000006;

    if (line <= 0x63)
    {
        REG_BG3HOFS = gSineTable[((gFieldState.unk52 + line) * 4) & 0xFF] / 32;
        REG_BG1HOFS = gSineTable[((gFieldState.unk52 + line) * 4) & 0xFF] / 32;
    }
    else
    {
        REG_BG3HOFS = 0;
        REG_BG1HOFS = 0;
    }
}
#else
NAKED
void Wave_HBlank(void)
{
    asm_unified(
        "    push {r4, r5, r6, lr}\n"
        "    ldr r0, .L080BDAFC\n"
        "    ldrb r1, [r0]\n"
        "    adds r4, r1, #0\n"
        "    cmp r1, #0x63\n"
        "    bhi .L080BDB0C\n"
        "    ldr r5, .L080BDB00\n"
        "    ldr r0, .L080BDB04\n"
        "    adds r3, r0, #0\n"
        "    adds r3, #0x52\n"
        "    ldrh r0, [r3]\n"
        "    adds r0, r0, r1\n"
        "    lsls r0, r0, #2\n"
        "    movs r2, #0xff\n"
        "    ands r0, r2\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r5\n"
        "    movs r6, #0\n"
        "    ldrsh r1, [r0, r6]\n"
        "    cmp r1, #0\n"
        "    bge .L080BDADC\n"
        "    adds r1, #0x1f\n"
        ".L080BDADC:\n"
        "    asrs r1, r1, #5\n"
        "    ldr r0, .L080BDB08\n"
        "    strh r1, [r0]\n"
        "    ldrh r0, [r3]\n"
        "    adds r0, r0, r4\n"
        "    lsls r0, r0, #2\n"
        "    ands r0, r2\n"
        "    lsls r0, r0, #1\n"
        "    adds r0, r0, r5\n"
        "    movs r1, #0\n"
        "    ldrsh r0, [r0, r1]\n"
        "    cmp r0, #0\n"
        "    bge .L080BDAF8\n"
        "    adds r0, #0x1f\n"
        ".L080BDAF8:\n"
        "    asrs r1, r0, #5\n"
        "    b .L080BDB12\n"
        ".L080BDAFC: .4byte 0x04000006 @ REG_VCOUNT\n"
        ".L080BDB00: .4byte gSineTable\n"
        ".L080BDB04: .4byte 0x03004550 @ IWRAM+0x4550\n"
        ".L080BDB08: .4byte 0x0400001C @ REG_BG3HOFS\n"
        ".L080BDB0C:\n"
        "    ldr r0, .L080BDB1C\n"
        "    movs r1, #0\n"
        "    strh r1, [r0]\n"
        ".L080BDB12:\n"
        "    ldr r0, .L080BDB20\n"
        "    strh r1, [r0]\n"
        "    pop {r4, r5, r6}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        ".L080BDB1C: .4byte 0x0400001C @ REG_BG3HOFS\n"
        ".L080BDB20: .4byte 0x04000014 @ REG_BG1HOFS\n"
    );
}
#endif

// Wave_Start @ 0x080BDB24
void Wave_Start(void)
{
    gIntrTable[1] = Wave_HBlank;
    VBlankTask_AddCountedAlways(Wave_VBlank, 1);
}

// Wave_Stop @ 0x080BDB44
void Wave_Stop(void)
{
    VBlankTask_AddCountedAlways(Wave_Disable, 1);
}

// Wave_Update @ 0x080BDB58
/* Starts or stops the wave effect to follow flag 0x108 (state in gFieldState.unk50). */
void Wave_Update(void)
{
    u32 on = Flag_Test(0x108);

    if (on)
    {
        if (gFieldState.unk50 == 0)
            gFieldState.unk50 = 1;
        if (gFieldState.unk50 == 1)
            Wave_Start();
        else
            Wave_Stop();
    }
    else if (gFieldState.unk50 != 0)
    {
        Wave_Stop();
        gFieldState.unk50 = on;
    }
}

// sub_080BDBAC @ 0x080BDBAC
void sub_080BDBAC(struct Task *task, u32 value)
{
    gUnk_0300000C = value;
}

// sub_080BDBB8 @ 0x080BDBB8
void sub_080BDBB8(void)
{
    Flag_Set(0x10F);
}

// sub_080BDBC8 @ 0x080BDBC8
void sub_080BDBC8(void)
{
    if (!Palette_IsBg13Black())
        PalFade_FadeRangeToBlackWithDuration(0x80, 0x80, 2, 6);
    else
        Flag_Set(0x10D);
}

// sub_080BDBF0 @ 0x080BDBF0
void sub_080BDBF0(void)
{
    Palette_CopyWithEffect(3, sub_080C5F60(gUnk_03004534), &gPaletteTarget[0x80], 0x100, 0x20);
    PalFade_FadeRangeWithDuration(0x80, 0x80, 1, 0x20);
}

// sub_080BDC28 @ 0x080BDC28
void sub_080BDC28(void)
{
    if (!Palette_IsBg13Black())
        PalFade_FadeRangeToBlackWithDuration(0x1D0, 0x30, 2, 6);
    else
        Flag_Set(0x10E);
}

// sub_080BDC50 @ 0x080BDC50
/* Window shadow registers: WIN0 = (8..0xE8, 0x60..0xA0), WIN1 = (8..0xE8, 0..8). */
void sub_080BDC50(void)
{
    u8 v;

    gUnk_03000030 = 0xE8;
    gUnk_03000031 = 8;
    gUnk_03000034 = 0xA0;
    gUnk_03000035 = 0x60;

    gUnk_03000038 = (v = 0x3D) & ~8;
    gUnk_03000032 = 0xE8;
    gUnk_03000033 = 8;
    gUnk_03000036 = 8;
    gUnk_03000037 = 0;
    gUnk_03000039 = v;
}

// sub_080BDCB8 @ 0x080BDCB8
void sub_080BDCB8(void)
{
    m4aSongNumStop(0x13F);
}

// sub_080BDCC8 @ 0x080BDCC8
void sub_080BDCC8(void)
{
    DmaFill32(3, 0, (void *)0x06001000, 0x1000);
    DmaFill32(3, 0, (void *)0x06003000, 0x1000);
}

// sub_080BDD00 @ 0x080BDD00
void sub_080BDD00(void)
{
    VBlankTask_AddCounted(sub_080BDCC8, 1);
    gUnk_03000006 = 0;
    gUnk_03000004 = 0;
    gUnk_0300000E = 0;
    gUnk_0300000C = 0;
}

// sub_080BDD34 @ 0x080BDD34
void sub_080BDD34(void)
{
    u32 r = Flag_Test(0xC6);

    if (!r)
    {
        Window_Close(gMsgWindow, 1);
        gMsgWindow = (void *)r;
        gMsgWindowOpen = r;
    }
}

// sub_080BDD60 @ 0x080BDD60
void sub_080BDD60(void)
{
    if (!Flag_Test(0xC6))
    {
        void *w = (void *)Window_Create(2, 0xB, 0x1A, 8, 0);

        gMsgWindow = w;
        gMsgWindowOpen = 1;
    }
}

// sub_080BDD94 @ 0x080BDD94
void sub_080BDD94(struct Task *task)
{
    u16 *d = task->data.h;
    struct Task *t = Char_FindById(0x14D);

    t->data.h[0] |= 0x20;
    task->data.h[0] = 0xFFFF;
    d[1] = 8;
    d[2] = 0x10;
    gUnk_03000042 = (d[1] << 8) | task->data.h[0];
    gUnk_03000044 = d[2];
}

// sub_080BDDDC @ 0x080BDDDC
void sub_080BDDDC(struct Task *task)
{
    u16 *d = task->data.h;

    task->data.h[0]--;
    gUnk_03000042 = task->data.h[0] | (d[1] << 8);
    gUnk_03000044 = d[2];
}

// sub_080BDE00 @ 0x080BDE00
void sub_080BDE00(struct Task *task, u32 step)
{
    if (step == 0)
        Char_EndById(task, 0x14D);
    else
        sub_080C1440();
}
