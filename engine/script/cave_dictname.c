/* cave_dictname.c — DDS demon-dictionary names -> pooled English, VWF, on the dictionary's OWN
 * substrate (OBJ glyph cache via FontSprite_DrawGlyph), NOT the cave_runtext strip path.
 *
 * The dictionary draws names glyph-by-glyph with FontSprite_DrawGlyph (0x080ac218) at fixed 0xc
 * pitch.  Routing names through cave_runtext strips corrupted the screen (the dictionary is
 * glyph-cache heavy, so strips collide with the cache — the same problem the compendium hit).  So
 * we keep the glyph cache and replace each per-glyph loop with a VARIABLE-width loop using the same
 * drawer: English names render proportional, no 8-glyph cap, sharing the cache like the JP glyphs.
 *
 * dict_name_vwf(species, jpName, x, y): if the demon is SEEN (Bitfield_CheckBit, the compendium
 * encountered-bitfield) and NAME_TABLE[species] is translated, draw the pooled English name; else
 * draw the caller-chosen JP pointer (the real record name when seen-but-untranslated, or the
 * "?????" default when unseen — NEVER reveal an unseen demon's English name).
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

#include <rommap.h>

typedef void (*fsg_fn)(u16 code, int p2, int p3, int x, int y);   /* FontSprite_DrawGlyph(g,_,_,x,y) */
typedef int  (*seen_fn)(u32 species);
#define FontSprite_DrawGlyph ((fsg_fn)(RM_FontSprite_DrawGlyph | 1))
#define Bitfield_CheckBit    ((seen_fn)(0x080C2644u | 1))   /* compendium "encountered" bit test */
#define WIDTH_TBL  ((const u8 *)RM_WIDTH_TABLE)
#define NAME_TABLE ((const u16 *const *)RM_NAME_TABLE)

/* generic capped VWF draw: stop at NUL / 0x0301 / off-screen / `cap` glyphs. */
static void draw_vwf_cap(const u16 *s, int x, int y, int cap, int stop_space)
{
    int i;
    if (!s) return;
    for (i = 0; i < cap; ++i) {
        u16 g = s[i];
        if (g == 0 || g == 0x0301) break;
        if (stop_space && g == RM_ENG_LO) break;       /* trim trailing pad spaces (level labels) */
        if (x > 240) break;                            /* don't run off-screen */
        FontSprite_DrawGlyph(g, 0, 0, x, y);
        x += (g >= RM_ENG_LO && g < RM_ENG_HI) ? WIDTH_TBL[g] : 0xc;
    }
}

static void draw_vwf(const u16 *name, int x, int y) { draw_vwf_cap(name, x, y, 40, 0); }

/* species + caller-chosen JP/default pointer (detail + default-list paths). */
__attribute__((used, noinline))
void dict_name_vwf(u16 species, const u16 *jp, int x, int y)
{
    const u16 *name = jp;
    if (species < RM_NAME_COUNT && Bitfield_CheckBit(species) && NAME_TABLE[species])
        name = NAME_TABLE[species];                    /* seen + translated -> pooled English */
    draw_vwf(name, x, y);
}

/* DICTIONARY RACE column (drawer @0x080dbe9c): the JP loop draws Race_GetName(id) glyph-by-glyph
 * at fixed 0xc pitch, cap-8, NOT sentinel-aware.  names_race repoints g_wRaceNameTable cells to
 * 0xFFFF + pooled-English pointer (the +2 slot is read as two halfwords — not 4-aligned), so the
 * stock loop would draw the sentinel as garbage.  Resolve it, then VWF-draw the English (or the
 * raw JP cell when untranslated).  cap 16: English race names (Amatsukami…) exceed the JP cap-8. */
__attribute__((used, noinline))
void dict_race_vwf(const u16 *cell, int x, int y)
{
    const u16 *name = cell;
    if (cell && cell[0] == 0xFFFF)
        name = (const u16 *)((u32)cell[1] | ((u32)cell[2] << 16));   /* field+2: pool ptr (2 halfwords) */
    draw_vwf_cap(name, x, y, 16, 0);
}

/* DICTIONARY LEVEL-RANGE column (drawer @0x080dc1d8): comp_levelrange already repoints each table
 * slot to a pooled English label ("Lv1-9".."Lv100"), padded to exactly 8 glyphs with NO terminator.
 * VWF-draw it (cap 8, trimming the trailing pad spaces — these labels never contain an inner space). */
__attribute__((used, noinline))
void dict_str_vwf(const u16 *s, int x, int y) { draw_vwf_cap(s, x, y, 8, 1); }

/* combatant record-name POINTER (the race/level-sorted lists draw `combatant_table[species]+0x22`
 * directly).  Map the pointer back to its species (96-byte stride via a reciprocal multiply -- no
 * `/` so -nostdlib doesn't need __aeabi_uidiv), seen-gate, then draw pooled English or the JP name. */
__attribute__((used, noinline))
void dict_name_vwf_ptr(const u16 *namePtr, int x, int y)
{
    const u16 *name = namePtr;
    u32 p = (u32)namePtr, d, c;
    if (p >= RM_DEMON_REC_BASE + RM_DEMON_NAME_OFF &&
        p <  RM_DEMON_REC_BASE + RM_NAME_COUNT * RM_DEMON_REC_STRIDE) {
        d = p - (RM_DEMON_REC_BASE + RM_DEMON_NAME_OFF);
        c = (d * 683u) >> 16;                           /* d / 96 */
        if (RM_DEMON_REC_BASE + c * RM_DEMON_REC_STRIDE + RM_DEMON_NAME_OFF == p
            && Bitfield_CheckBit(c) && NAME_TABLE[c])
            name = NAME_TABLE[c];
    }
    draw_vwf(name, x, y);
}

/* detail-panel name veneer (bl from 0x080db960): r5 = JP/default name ptr; species = [0x020399e0
 * +0x38]; draw at (0x7e, 7).  Skips the original per-glyph loop. */
__attribute__((naked, used, section(".text.entry")))
void cave_entry(void)
{
    __asm__ volatile(
        "ldr  r0, =0x020399E0   \n"   /* DICT_STATE          */
        "ldrh r0, [r0, #0x38]   \n"   /* arg1 = species      */
        "mov  r1, r5            \n"   /* arg2 = JP/default ptr */
        "movs r2, #0x7e         \n"   /* arg3 = x            */
        "movs r3, #7            \n"   /* arg4 = y            */
        "push {lr}              \n"
        "bl   dict_name_vwf     \n"
        "pop  {pc}              \n"
    );
}

/* scrollable LIST name veneer (bl from 0x080dbd86): r4 = species, r1 = JP/default ptr, r5 = row,
 * r10 = y-base.  Must set r8 = row+1 (the next-row continuation @0x080dbdba reads it) and compute
 * y = (r10 + row*12) & 0xffff; draw at (0x5c, y).  Skips the original per-glyph loop. */
__attribute__((naked, used, section(".text.entry")))
void cave_entry2(void)
{
    __asm__ volatile(
        "add  r2, r5, #1        \n"   /* row+1               */
        "mov  r8, r2            \n"   /* r8 = row+1 (next-row iter) */
        "lsl  r0, r5, #1        \n"   /* row*2               */
        "add  r0, r0, r5        \n"   /* row*3               */
        "lsl  r0, r0, #2        \n"   /* row*12              */
        "add  r0, r10           \n"   /* y-base + row*12     */
        "lsl  r0, r0, #16       \n"
        "lsr  r3, r0, #16       \n"   /* arg4 = y            */
        "mov  r2, #0x5c         \n"   /* arg3 = x            */
        "mov  r0, r4            \n"   /* arg1 = species      */
        "push {lr}              \n"   /* (arg2 = r1 = JP/default ptr, already in place) */
        "bl   dict_name_vwf     \n"
        "pop  {pc}              \n"
    );
}

/* race/level-SORTED list veneer (bl from 0x080dc364): r8 = name base (combatant record+0x22),
 * r7 = y; x = 0x54 fixed.  Skips the original 8-glyph loop. */
__attribute__((naked, used, section(".text.entry")))
void cave_entry3(void)
{
    __asm__ volatile(
        "mov  r0, r8           \n"   /* arg1 = name ptr (combatant record+0x22) */
        "mov  r2, r7           \n"   /* arg3 = y                */
        "movs r1, #0x54        \n"   /* arg2 = x                */
        "push {lr}             \n"
        "bl   dict_name_vwf_ptr \n"
        "pop  {pc}             \n"
    );
}

/* RACE-column veneer (bl from 0x080dbf10): r4 = race-name cell ptr (Race_GetName result), r7 = y,
 * x = 0x54 fixed.  Returns to the patched skip @0x080dbf14 (-> b past the dead per-glyph loop). */
__attribute__((naked, used, section(".text.entry")))
void cave_entry4(void)
{
    __asm__ volatile(
        "mov  r0, r4           \n"   /* arg1 = cell ptr  */
        "movs r1, #0x54        \n"   /* arg2 = x         */
        "mov  r2, r7           \n"   /* arg3 = y         */
        "push {lr}             \n"
        "bl   dict_race_vwf    \n"
        "pop  {pc}             \n"
    );
}

/* LEVEL-RANGE-column veneer (bl from 0x080dc23e): r4 = label string ptr, r7 = y, x = 0x54 fixed.
 * Returns to the patched skip @0x080dc242 (-> b past the dead per-glyph loop). */
__attribute__((naked, used, section(".text.entry")))
void cave_entry5(void)
{
    __asm__ volatile(
        "mov  r0, r4           \n"   /* arg1 = label ptr */
        "movs r1, #0x54        \n"   /* arg2 = x         */
        "mov  r2, r7           \n"   /* arg3 = y         */
        "push {lr}             \n"
        "bl   dict_str_vwf     \n"
        "pop  {pc}             \n"
    );
}
