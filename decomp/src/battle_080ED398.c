#include "global.h"
#include "battle.h"

// sub_080ED398 @ 0x080ED398
void sub_080ED398(u32 *a, s32 *b, u16 id)
{
    u8 *rec = sub_080C5D48(id);
    u8 v = rec[2];

    if (rec[1] != 0 && !Flag_Test(rec[1]))
        v = rec[3];
    if (v != 0xFF)
        sub_080ED35C(a, b, v);
}

// sub_080ED3D0 @ 0x080ED3D0
u8 sub_080ED3D0(s32 row, s32 col)
{
    u8 v = gUnknown_0872F234[row * 8 + col / 2];

    if (!(col & 1))
        v >>= 4;
    return v & 0xF;
}

// sub_080ED3FC @ 0x080ED3FC
s32 sub_080ED3FC(s32 table, s32 row)
{
    const u8 *p;
    s32 n;
    u32 r;
    n = gUnknown_0876F660[table].stride * row; p = gUnknown_0876F660[table].data + n; n = 0;
    r = sub_080C2244();

    do
    {
        if (*p != 0 && r <= *p)
            return n;
        p++;
        n++;
    } while (1);
}

// sub_080ED43C @ 0x080ED43C
s16 sub_080ED43C(s32 id)
{
    return *(s16 *)(Demon_GetRecord(id) + 2);
}

// sub_080ED450 @ 0x080ED450
s16 sub_080ED450(s32 id)
{
    return *(s16 *)(Demon_GetRecord(id) + 4);
}

// sub_080ED464 @ 0x080ED464
s32 sub_080ED464(s32 id)
{
    if (id < 0)
        return -1;
    return (s8)Demon_GetRecord(id)[0];
}

// sub_080ED484 @ 0x080ED484
s32 sub_080ED484(s32 id)
{
    return Race_GetParentId(sub_080ED464(id));
}

// sub_080ED494 @ 0x080ED494
s32 sub_080ED494(s32 id)
{
    return (s8)Demon_GetRecord(id)[0xE];
}

// sub_080ED4A8 @ 0x080ED4A8
s32 sub_080ED4A8(s32 id)
{
    return (s8)Demon_GetRecord(id)[0xF];
}

// sub_080ED4BC @ 0x080ED4BC
u32 sub_080ED4BC(s32 id)
{
    return Demon_GetRecord(id)[0xD] >> 4;
}

// sub_080ED4D0 @ 0x080ED4D0
u32 sub_080ED4D0(s32 id)
{
    return Demon_GetRecord(id)[0xD] & 0xF;
}

// sub_080ED4E4 @ 0x080ED4E4
u32 sub_080ED4E4(s32 id)
{
    return Demon_GetRecord(id)[0x19] >> 4;
}

// sub_080ED4F8 @ 0x080ED4F8
u32 sub_080ED4F8(s32 id)
{
    return Demon_GetRecord(id)[0x19] & 0xF;
}

// sub_080ED50C @ 0x080ED50C
u32 sub_080ED50C(s32 id)
{
    return Demon_GetRecord(id)[0x1C] >> 4;
}

// sub_080ED520 @ 0x080ED520
u32 sub_080ED520(s32 id)
{
    return Demon_GetRecord(id)[0x1C] & 0xF;
}

// sub_080ED534 @ 0x080ED534
u32 sub_080ED534(s32 id)
{
    return sub_080ED520(id);
}

// sub_080ED540 @ 0x080ED540
u32 sub_080ED540(s32 id)
{
    return *(u16 *)(Demon_GetRecord(id) + 0x1A);
}

// sub_080ED550 @ 0x080ED550
u32 sub_080ED550(s32 id)
{
    return Demon_GetRecord(id)[0xC];
}

// sub_080ED560 @ 0x080ED560
u32 sub_080ED560(s32 id)
{
    return Demon_GetRecord(id)[1];
}

// sub_080ED570 @ 0x080ED570
u32 sub_080ED570(s32 id)
{
    return Demon_GetRecord(id)[0x21];
}

// sub_080ED584 @ 0x080ED584
u32 sub_080ED584(s32 id)
{
    return Demon_GetRecord(id)[0x1D];
}

// sub_080ED594 @ 0x080ED594
s32 sub_080ED594(s32 id)
{
    s32 v = sub_080ED560(id) * 8;

    if (v == 0)
        v = 1;
    return v;
}

// sub_080ED5A8 @ 0x080ED5A8
s32 sub_080ED5A8(s32 id)
{
    return sub_080ED560(id) * 4;
}

