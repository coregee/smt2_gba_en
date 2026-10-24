/* Palette buffer and palette fades. */

#include "global.h"
#include "sys.h"

// Palette_MarkDirty @ 0x080AABB0
/* Marks the palette buffer for upload at the next VBlank. */
void Palette_MarkDirty(void)
{
    gPaletteDirty = TRUE;
}

// Palette_ClearDirty @ 0x080AABBC
void Palette_ClearDirty(void)
{
    gPaletteDirty = FALSE;
}

// Palette_IsDirty @ 0x080AABC8
bool32 Palette_IsDirty(void)
{
    return gPaletteDirty;
}

// PalFade_Init @ 0x080AABD4
/* Stops all fades; unless keepPalettes, also clears the palette and target buffers. */
void PalFade_Init(u32 keepPalettes)
{
    DmaFill32(3, 0, gPalFades, sizeof(gPalFades));
    if (keepPalettes == 0)
    {
        DmaFill32(3, keepPalettes, gPaletteBuffer, 0x400);
        DmaFill32(3, keepPalettes, gPaletteTarget, 0x400);
    }
    Palette_MarkDirty();
}

// PalFade_FindTagged @ 0x080AAC34
/* Returns the running fade tagged with tag, if any. */
struct PalFade *PalFade_FindTagged(u16 tag)
{
    u32 i;

    for (i = 0; i < 8; i++)
    {
        if (gPalFades[i].active != 0 && gPalFades[i].waitTag == tag + 0x8000)
            return &gPalFades[i];
    }
    return NULL;
}

// PalFade_AccumulateSteps @ 0x080AAC70
void PalFade_AccumulateSteps(struct PalFade *fade)
{
    u32 i;

    for (i = 0; i < 32; i++)
        fade->accum[i] += gPalFadeStepTable[i];
}

// PalFade_WrapSteps @ 0x080AAC98
void PalFade_WrapSteps(struct PalFade *fade)
{
    u32 i;

    for (i = 0; i < 32; i++)
    {
        if (fade->accum[i] > 999)
            fade->accum[i] -= 1000;
    }
}

// PalFade_StepComponent @ 0x080AACC8
/* Moves one colour component towards target: down by up to 2, up by up to 2 steps of
   accum[target] / 1000. */
u16 PalFade_StepComponent(struct PalFade *fade, u16 cur, u16 target)
{
    u16 step;

    if (cur == target)
        return cur;
    if (cur > target)
    {
        cur--;
        if (cur != target)
            cur--;
    }
    else
    {
        step = fade->accum[target] / 1000;
        if (cur != target)
        {
            cur += step;
            if (cur != target)
                cur += step;
        }
    }
    return cur;
}

// PalFade_Update @ 0x080AAD1C
/* Advances one fade by a step every `delay` frames.  A fade with a waitTag (bit 15 clear)
   does nothing until a fade tagged waitTag | 0x8000 is running. */
void PalFade_Update(struct PalFade *fade)
{
    bool32 done;
    u16 *cur;
    u16 *target;
    u32 i;
    u16 start, count;

    if (fade->active == 0)
        return;
    if (fade->waitTag != 0)
    {
        u16 tagged = fade->waitTag & 0x8000;

        if (tagged == 0)
        {
            if (PalFade_FindTagged(fade->waitTag) == NULL)
                return;
            fade->waitTag = tagged;
        }
    }
    if (--fade->timer != 0)
        return;
    done = TRUE;
    fade->timer = fade->delay;
    PalFade_AccumulateSteps(fade);
    start = fade->start;
    count = fade->count;
    cur = &gPaletteBuffer[start];
    target = &gPaletteTarget[start];
    for (i = 0; i < count; i++, cur++, target++)
    {
        u16 r = *cur & 0x1F;
        u16 g = (*cur & 0x3E0) >> 5;
        u16 b = (*cur & 0x7C00) >> 10;
        u32 c;

        r = PalFade_StepComponent(fade, r, *target & 0x1F);
        g = PalFade_StepComponent(fade, g, (*target & 0x3E0) >> 5);
        b = PalFade_StepComponent(fade, b, (*target & 0x7C00) >> 10);
        c = (g << 5) | r | (b << 10);
        *cur = c;
        if ((*cur & 0x7FFF) != (*target & 0x7FFF))
            done = FALSE;
    }
    PalFade_WrapSteps(fade);
    if (fade->duration != 0xFFFF)
    {
        if (--fade->duration == 0)
            done = TRUE;
    }
    if (done == TRUE)
        fade->active = 0;
    Palette_MarkDirty();
}

// PalFade_UpdateAll @ 0x080AAE58
void PalFade_UpdateAll(void)
{
    u32 i;
    struct PalFade *fade;

    for (i = 0, fade = gPalFades; i < 8; fade++, i++)
        PalFade_Update(fade);
}

// PalFade_FindFree @ 0x080AAE78
struct PalFade *PalFade_FindFree(void)
{
    u32 i;
    struct PalFade *fade;

    for (i = 0, fade = gPalFades; i < 8; fade++, i++)
    {
        if (fade->active == 0)
            return fade;
    }
    return NULL;
}

// PalFade_Setup @ 0x080AAE9C
void PalFade_Setup(struct PalFade *fade, u16 start, u16 count, u16 delay)
{
    DmaFill32(3, 0, fade, sizeof(*fade));
    fade->delay = delay;
    fade->timer = delay;
    fade->start = start;
    fade->count = count;
    fade->duration = 0xFFFF;
    fade->active = 1;
}

// PalFade_FadeInFromBlack @ 0x080AAEDC
/* Fades all 512 colours in from black. */
struct PalFade *PalFade_FadeInFromBlack(u16 delay)
{
    struct PalFade *fade = PalFade_FindFree();

    if (fade != NULL)
    {
        Palette_FillWithEffect(3, 0, gPaletteBuffer, 0x400, 0x20);
        Palette_MarkDirty();
        PalFade_Setup(fade, 0, 0x200, delay);
    }
    return fade;
}

// sub_080AAF20 @ 0x080AAF20
void sub_080AAF20(void *unused, u16 delay)
{
    PalFade_FadeInFromBlack(delay);
}

// PalFade_FadeToWhite @ 0x080AAF30
/* Fades all colours to white. */
struct PalFade *PalFade_FadeToWhite(u16 delay)
{
    return PalFade_FadeRangeToWhite(0, 0x200, delay);
}

// PalFade_FadeToBlack @ 0x080AAF48
/* Fades all colours to black. */
struct PalFade *PalFade_FadeToBlack(u16 delay)
{
    struct PalFade *fade = PalFade_FindFree();

    if (fade != NULL)
    {
        Palette_FillWithEffect(3, 0, gPaletteTarget, 0x400, 0x20);
        PalFade_Setup(fade, 0, 0x200, delay);
    }
    return fade;
}

// sub_080AAF88 @ 0x080AAF88
void sub_080AAF88(void *unused, u16 delay)
{
    PalFade_FadeToBlack(delay);
}

// PalFade_FadeToTarget @ 0x080AAF98
/* Fades all colours to the current target palette. */
struct PalFade *PalFade_FadeToTarget(u16 delay)
{
    struct PalFade *fade = PalFade_FindFree();

    if (fade != NULL)
        PalFade_Setup(fade, 0, 0x200, delay);
    return fade;
}

// PalFade_FadeRangeInFromBlack @ 0x080AAFBC
/* Fades a range of colours in from black. */
struct PalFade *PalFade_FadeRangeInFromBlack(u16 start, u16 count, u16 delay)
{
    struct PalFade *fade = PalFade_FindFree();

    if (fade != NULL)
    {
        Palette_FillWithEffect(3, 0, &gPaletteBuffer[start], count * 2, 0x10);
        Palette_MarkDirty();
        PalFade_Setup(fade, start, count, delay);
    }
    return fade;
}

// PalFade_FadeRangeToWhite @ 0x080AB008
/* Fades a range of colours to white. */
struct PalFade *PalFade_FadeRangeToWhite(u16 start, u16 count, u16 delay)
{
    struct PalFade *fade = PalFade_FindFree();

    if (fade != NULL)
    {
        Palette_FillWithEffect(3, 0x7FFF, &gPaletteTarget[start], count * 2, 0x10);
        PalFade_Setup(fade, start, count, delay);
    }
    return fade;
}

// PalFade_FadeRangeWithDuration @ 0x080AB054
struct PalFade *PalFade_FadeRangeWithDuration(u16 start, u16 count, u16 delay, u16 duration)
{
    struct PalFade *fade = PalFade_FindFree();

    if (fade != NULL)
    {
        PalFade_Setup(fade, start, count, delay);
        fade->duration = duration;
    }
    return fade;
}

// PalFade_FadeRangeInFromBlackTagged @ 0x080AB090
/* PalFade_FadeRangeInFromBlack that waits for the fade tagged waitTag. */
struct PalFade *PalFade_FadeRangeInFromBlackTagged(u16 start, u16 count, u16 delay, u16 waitTag)
{
    struct PalFade *fade = PalFade_FindFree();

    if (fade != NULL)
    {
        Palette_FillWithEffect(3, 0, &gPaletteBuffer[start], count * 2, 0x10);
        Palette_MarkDirty();
        PalFade_Setup(fade, start, count, delay);
        fade->waitTag = waitTag;
    }
    return fade;
}

// PalFade_FadeRangeToBlack @ 0x080AB0F0
/* Fades a range of colours to black. */
struct PalFade *PalFade_FadeRangeToBlack(u16 start, u16 count, u16 delay)
{
    struct PalFade *fade = PalFade_FindFree();

    if (fade != NULL)
    {
        Palette_FillWithEffect(3, 0, &gPaletteTarget[start], count * 2, 0x10);
        PalFade_Setup(fade, start, count, delay);
    }
    return fade;
}

// PalFade_FadeRangeToBlackWithDuration @ 0x080AB138
struct PalFade *PalFade_FadeRangeToBlackWithDuration(u16 start, u16 count, u16 delay, u16 duration)
{
    struct PalFade *fade = PalFade_FadeRangeToBlack(start, count, delay);

    fade->duration = duration;
    return fade;
}

// PalFade_FadeRangeToBlackTagged @ 0x080AB158
struct PalFade *PalFade_FadeRangeToBlackTagged(u16 start, u16 count, u16 delay, u16 waitTag)
{
    struct PalFade *fade = PalFade_FadeRangeToBlack(start, count, delay);

    fade->waitTag = waitTag;
    return fade;
}

// PalFade_IsActive @ 0x080AB178
bool32 PalFade_IsActive(struct PalFade *fade)
{
    return fade->active != 0;
}

// PalFade_AllDone @ 0x080AB184
/* TRUE when no fade is running. */
u16 PalFade_AllDone(void)
{
    u32 i;
    struct PalFade *fade;

    for (i = 0, fade = gPalFades; i < 8; fade++, i++)
    {
        if (fade->active != 0)
            return FALSE;
    }
    return TRUE;
}

// sub_080AB1A8 @ 0x080AB1A8
void sub_080AB1A8(u8 *ctx)
{
    u16 done = PalFade_AllDone();

    if (done != TRUE)
        done = FALSE;
    *(u16 *)(ctx + 0x1C) = done;
}

/* The original pads the end of this unit with zeros, not the assembler's Thumb nop. */
asm(".align 2, 0");
