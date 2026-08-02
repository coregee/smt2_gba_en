/* cave_skilllist.c  —  VWF + full-length names for the list-row name drawers FUN_081272cc (untinted:
 * skill list, item-use menu, party/ally list) and FUN_08127394 (tinted clone: COMP stock / fusion
 * demon lists). Compiled by devkitARM (Thumb, armv4t), injected by engine/script/patch_skilllist.py.
 *
 * Both stock drawers render each row's name with Font_DrawGlyphTinted into the IWRAM BG canvas
 * 0x030000b4 at a FIXED 12px pitch, capped at 8 glyphs.  English names are longer and want
 * proportional spacing, so we VWF-draw the full name AND resolve long names from their pool source:
 * skill names via the 0xFFFF repoint sentinel (+2 pointer), item/equipment via ITEM_TABLE[id], demon
 * names via NAME_TABLE[id] (pooled_name() maps an inline record pointer back to its id).
 *
 * `mode` is the visible row index 0..4: rows 0..3 take the normal branch; row 4 (the BOTTOM row) takes
 * a "scroll" branch that draws into the same canvas at x=128,y=2 then composites down with CpuFastSet.
 * Two entries share the workers: cave_entry (FUN_081272cc, r5=name) and cave_entry2 (FUN_08127394,
 * r6=name, r5=tint); the veneer resolves the sentinel, then for:
 *   - rows 0..3 -> VWF-draw the row, jump to the stock epilogue.
 *   - row 4     -> skilllist_row4 (replicate the stock pre-draw CpuFastSet, then VWF the name at
 *                  x=128,y=2), jump to the stock composite tail @0x08127314.
 * Run AFTER patch_vwf.py (needs the width table).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

#include <rommap.h>   /* RM_* address defines, generated from rom_layout.py */

typedef void (*draw_fn)(u32 code, void *canvas, u16 x, u16 y, u8 tint);
typedef void (*cfs_fn)(const void *src, void *dst, u32 ctrl);
#define Font_DrawGlyphTinted ((draw_fn)(RM_Font_DrawGlyphTinted | 1))
#define CpuFastSet           ((cfs_fn)(RM_CpuFastSet | 1))
#define WIDTH_TBL ((const u8 *)RM_WIDTH_TABLE)
#define CANVAS    ((void *)RM_SKILL_LIST_CANVAS)
#define ENG_LO RM_ENG_LO
#define ENG_HI RM_ENG_HI

/* maxG caps the glyph count.  In-place names live in a FIXED 8-glyph field: the stock printer hard-
 * capped at 8 and did NOT rely on a terminator, so an exactly-8 name ("Medicine", "マッスルドリンコ")
 * has no NUL after it.  The veneer passes 8 for those; a repointed POOL name is NUL-terminated and may
 * be long, so it passes 40 (read-to-NUL, width-clamped). */
static inline s16 vwf_draw(const u16 *name, s16 x, s16 y, int maxG, u8 tint)
{
    int i;
    for (i = 0; i < maxG; ++i) {
        u16 g = name[i];
        if (g == 0) break;
        if (x > 240) break;                           /* don't run off the canvas */
        Font_DrawGlyphTinted(g, CANVAS, (u16)x, (u16)y, tint);
        x += (g >= ENG_LO && g < ENG_HI) ? WIDTH_TBL[g] : 0xc;
    }
    return x;
}

#define ITEM_TABLE ((const u16 *const *)RM_ITEM_TABLE)   /* item/equip id -> pooled name (0=none) */
#define NAME_TABLE ((const u16 *const *)RM_NAME_TABLE)   /* demon id      -> pooled name (0=none) */

/* Map an INLINE record name pointer (the fixed-width field the stock menu draws) back to its id and
 * return the full-length pooled name tr.py mirrored into the matching id->ptr table, so menus show
 * long English names like the other drawers do.  Returns 0 when `name` isn't a record name (a skill
 * name / an already-resolved pool pointer) or has no pooled entry.
 *   - item-use menu   : equipment/item pDisplayText -> ITEM_TABLE
 *   - party/ally menu : demon record +0x22 name      -> NAME_TABLE  (FUN_08127eac case 0)
 * NB: no `/`/`%` here — at -Os -nostdlib the compiler would emit an unlinkable __aeabi_uidiv.  A
 * power-of-two stride is a shift; others use a reciprocal multiply (round-up 65536/stride: 36->1821,
 * 96->683) validated by multiplying the id back, so a stray pointer can't pass. */
static const u16 *pooled_name(const u16 *name)
{
    u32 p = (u32)name, d, c, id = 0xFFFFFFFFu;
    if (p >= RM_DEMON_REC_BASE + RM_DEMON_NAME_OFF &&
        p <  RM_DEMON_REC_BASE + RM_NAME_COUNT * RM_DEMON_REC_STRIDE) {    /* demon id 0..0x17B */
        d = p - (RM_DEMON_REC_BASE + RM_DEMON_NAME_OFF);
        c = (d * 683u) >> 16;                                             /* d / 96 */
        if (RM_DEMON_REC_BASE + c * RM_DEMON_REC_STRIDE + RM_DEMON_NAME_OFF == p)
            return NAME_TABLE[c];                                         /* 0 if untranslated */
        return 0;
    }
    if (p >= RM_EQUIP_REC_BASE + RM_EQUIP_NAME_OFF &&
        p <  RM_EQUIP_REC_BASE + 0xD0 * RM_EQUIP_REC_STRIDE) {            /* equipment id 0x00-0xCF */
        d = p - (RM_EQUIP_REC_BASE + RM_EQUIP_NAME_OFF);
        c = (d * 1821u) >> 16;                                            /* d / 36 */
        if (RM_EQUIP_REC_BASE + c * RM_EQUIP_REC_STRIDE + RM_EQUIP_NAME_OFF == p) id = c;
    } else if (p >= RM_ITEM_REC_BASE + RM_ITEM_NAME_OFF &&
               p <  RM_ITEM_REC_BASE + RM_ITEM_COUNT * RM_ITEM_REC_STRIDE) {  /* item id 0xD0+ */
        d = p - (RM_ITEM_REC_BASE + RM_ITEM_NAME_OFF);
        if ((d & 31u) == 0) id = d >> 5;                                 /* d / 32 */
    }
    if (id < RM_ITEM_COUNT) {
        const u16 *pl = ITEM_TABLE[id];
        if (pl) return pl;
    }
    return 0;
}

static s16 draw_name(const u16 *name, s16 x, s16 y, int maxG, u8 tint)
{
    const u16 *pooled = pooled_name(name);
    if (pooled) { name = pooled; maxG = 40; }   /* pooled item/equipment/demon name -> full length */
    return vwf_draw(name, x, y, maxG, tint);
}

__attribute__((used, noinline))
void skilllist_row(const u16 *name, u32 mode, int maxG, u8 tint)   /* rows 0..3: x=0, y=row*13+6 */
{
    draw_name(name, 0, (s16)((mode & 0xff) * 0xd + 6), maxG, tint);
}

__attribute__((used, noinline))
void skilllist_row4(const u16 *name, int maxG, u8 tint)            /* row 4 (bottom): scroll branch */
{
    /* stock case-4 pre-draw buffer step (part of the scroll composite) — replicate exactly by
     * reading the same ROM literals (@0x08127344, +4; FUN_08127394 holds identical values @+0xCC)
     * the stock body loads, then VWF the name where stock drew it fixed-pitch (x=128, y=2); the
     * veneer jumps to the composite after. */
    u32 a = *(volatile u32 *)0x08127344;
    CpuFastSet((const void *)a, (void *)(a + *(volatile u32 *)0x08127348), 0x80);
    draw_name(name, 128, 2, maxG, tint);
}

__attribute__((naked, used, section(".text.entry")))
void cave_entry(void)
{
    __asm__ volatile(
        "mov  r3, #8            \n"   /* maxG default: in-place names are a fixed 8-glyph field */
        "ldrh r0, [r5]          \n"   /* name field +0: 0xFFFF marks a repoint sentinel */
        "ldr  r2, =0xFFFF       \n"
        "cmp  r0, r2            \n"
        "bne  1f                \n"
        "add  r2, r5, #2        \n"   /* candidate pooled pointer @ record+8 */
        "ldr  r2, [r2]          \n"
        "lsr  r0, r2, #24       \n"
        "cmp  r0, #0x08         \n"   /* a real pool/ROM pointer has top byte 0x08 */
        "bne  1f                \n"
        "mov  r5, r2            \n"   /* resolved: use the pooled name */
        "mov  r3, #40           \n"   /* pooled name is NUL-terminated -> read to NUL (long names) */
        "1:                     \n"
        "cmp  r1, #4            \n"
        "bne  2f                \n"
        "mov  r0, r5            \n"   /* arg1 = name (resolved) */
        "mov  r1, r3            \n"   /* arg2 = maxG */
        "movs r2, #0            \n"   /* arg3 = tint 0 -> skilllist_row4(name, maxG, 0) */
        "bl   skilllist_row4    \n"   /* row 4: pre-draw CpuFastSet + VWF name */
        "ldr  r0, =0x08127315   \n"   /* stock case-4 composite tail (0x08127314 | thumb) */
        "bx   r0                \n"
        "2:                     \n"
        "mov  r0, r5            \n"   /* arg1 = name (r1 already = mode) */
        "mov  r2, r3            \n"   /* arg3 = maxG */
        "movs r3, #0            \n"   /* arg4 = tint 0 -> skilllist_row(name, mode, maxG, 0) */
        "bl   skilllist_row     \n"
        "ldr  r0, =0x08127387   \n"   /* stock epilogue (thumb) */
        "bx   r0                \n"
    );
}

/* Second entry: the TINTED sibling drawer FUN_08127394 (COMP stock / fusion demon-name lists).
 * Same as cave_entry but FUN_08127394's prologue puts name in r6 and tint in r5, and its case-4
 * composite tail / epilogue are at 0x081273de / 0x08127450.  Reached by a bl patched at 0x081273a2. */
__attribute__((naked, used, section(".text.entry")))
void cave_entry2(void)
{
    __asm__ volatile(
        "mov  r3, #8            \n"   /* maxG default */
        "ldrh r0, [r6]          \n"   /* name in r6 here; +0 == 0xFFFF marks a repoint sentinel */
        "ldr  r2, =0xFFFF       \n"
        "cmp  r0, r2            \n"
        "bne  3f                \n"
        "add  r2, r6, #2        \n"
        "ldr  r2, [r2]          \n"
        "lsr  r0, r2, #24       \n"
        "cmp  r0, #0x08         \n"
        "bne  3f                \n"
        "mov  r6, r2            \n"   /* resolved pooled name */
        "mov  r3, #40           \n"
        "3:                     \n"
        "cmp  r1, #4            \n"
        "bne  4f                \n"
        "mov  r0, r6            \n"   /* arg1 = name */
        "mov  r1, r3            \n"   /* arg2 = maxG */
        "mov  r2, r5            \n"   /* arg3 = tint -> skilllist_row4(name, maxG, tint) */
        "bl   skilllist_row4    \n"
        "ldr  r0, =0x081273df   \n"   /* FUN_08127394 case-4 composite tail (0x081273de | thumb) */
        "bx   r0                \n"
        "4:                     \n"
        "mov  r0, r6            \n"   /* arg1 = name (r1 = mode) */
        "mov  r2, r3            \n"   /* arg3 = maxG */
        "mov  r3, r5            \n"   /* arg4 = tint -> skilllist_row(name, mode, maxG, tint) */
        "bl   skilllist_row     \n"
        "ldr  r0, =0x08127451   \n"   /* FUN_08127394 epilogue (0x08127450 | thumb) */
        "bx   r0                \n"
    );
}

/* Third entry: the Cathedral fusion candidate list (Fusion_DrawCandidateRow @0x08154A40).  That row
 * drawer draws the race name (3 fixed glyphs at x=10+i*12 from a names_race pointer at sp+0x24 —
 * sentinel-UNAWARE, so a long race like Amatsukami rendered the raw 0xFFFF+ptr = garbage) and the demon
 * name (sp+0x2c = record+0x22 — Japanese).  We hook the pre-loop setup @0x08154ab2 and: (a) resolve the
 * race sentinel and VWF-draw the race name ourselves, pixel-truncated so it never crosses into the NAME
 * column at x=44; (b) resolve the demon name to NAME_TABLE[id] and stash it at sp+0x2c; (c) jump to the
 * demon-name loop @0x08154ae4 (cave_entry4 VWF-draws it), SKIPPING the stock 3-glyph race loop entirely.
 * Hooked at 0x08154ab2 (not 0x08154ab6 — the stock race loop branches back to 0x08154ab8, and a bl there
 * would land mid-instruction).  r7=y, r9=tint<<24, r10=record are preserved across the worker calls. */
__attribute__((used, noinline))
void fusion_race_vwf(const u16 *race, int y, u8 tint)
{
    void *canvas = (void *)(*(volatile u32 *)0x08154b2c);   /* race/name BG canvas (DAT_08154b2c) */
    s16 x = 0xa;                                            /* race column starts at x=10 */
    int i;
    for (i = 0; i < 8; ++i) {
        u16 g = race[i];
        if (g == 0) break;
        int w = (g >= ENG_LO && g < ENG_HI) ? WIDTH_TBL[g] : 0xc;
        if (x + w > 42) break;                             /* pixel-width truncate (NAME col @ x=44) */
        Font_DrawGlyphTinted(g, canvas, (u16)x, (u16)y, tint);
        x += w;
    }
}

__attribute__((naked, used, section(".text.entry")))
void cave_entry3(void)
{
    __asm__ volatile(
        "ldr  r0, [sp, #0x24]   \n"   /* race name ptr */
        "ldrh r1, [r0]          \n"
        "ldr  r2, =0xFFFF       \n"
        "cmp  r1, r2            \n"
        "bne  5f                \n"
        "ldrh r1, [r0, #2]      \n"   /* sentinel -> pooled race ptr (unaligned halfword pair) */
        "ldrh r0, [r0, #4]      \n"
        "lsl  r0, r0, #16       \n"
        "orr  r0, r1            \n"
        "5:                     \n"
        "mov  r1, r7            \n"   /* arg2 = y */
        "mov  r2, r9            \n"   /* tint<<24 (high) -> low */
        "lsr  r2, r2, #24       \n"   /* arg3 = tint -> fusion_race_vwf(race, y, tint) */
        "bl   fusion_race_vwf   \n"
        "mov  r0, r10           \n"
        "add  r0, #0x22         \n"   /* record+0x22 = demon name ptr */
        "bl   pooled_name       \n"   /* -> NAME_TABLE[id] or 0 */
        "cmp  r0, #0            \n"
        "bne  6f                \n"
        "mov  r0, r10           \n"   /* not pooled: inline record+0x22 */
        "add  r0, #0x22         \n"
        "6:                     \n"
        "str  r0, [sp, #0x2c]   \n"   /* demon name ptr -> sp+0x2c (cave_entry4 reads it) */
        "ldr  r0, =0x08154ae5   \n"   /* skip stock race loop -> demon-name loop @0x08154ae4 | thumb */
        "bx   r0                \n"
    );
}

/* Fourth entry: VWF the Cathedral fusion candidate NAME.  cave_entry3 resolved the name pointer into
 * sp+0x2c; the stock draw loop then renders it FIXED-pitch (x = 0x2c + i*10, 8-cap).  We replace that
 * loop with a variable-width draw using the same drawers (so the +0x200 font mirror still applies):
 * the normal path keeps FUN_08153fc8 (which adds 0x200), the special race 0x2c path keeps
 * Font_DrawGlyphTinted — only the X advance changes (WIDTH_TBL instead of a fixed pitch).  Hooked at
 * 0x08154ae4 (`mov r4,#0; ldr r1,[sp,#0x2c]`, the name-loop head) and jumps past the loop to the
 * mode-specific code at 0x08154b9e. */
typedef int  (*chk_fn)(int);
typedef void (*fc8_fn)(u32 code, void *canvas, int x, int y, u8 tint);
#define FUN_0815bac4 ((chk_fn)(0x0815bac4 | 1))   /* race-0x2c sub-mode select */
#define FUN_08153fc8 ((fc8_fn)(0x08153fc8 | 1))   /* name glyph drawer (Font_GetGlyphBitmap(code+0x200)) */

__attribute__((used, noinline))
void fusion_name_vwf(const u16 *name, const u16 *record, int y, u8 tint, int sid)
{
    int race = *(const signed char *)record;            /* record->race */
    int i;
    s16 x;
    if (race == 0x2c) {                                  /* special race: Font_DrawGlyphTinted path */
        int m = FUN_0815bac4(sid);
        void *canvas = (void *)(*(volatile u32 *)(m == 1 ? 0x08154b64 : 0x08154be0));
        u8 t = (m == 1) ? tint : 4;
        for (i = 0, x = 0x30; i < 40; ++i) {
            u16 g = name[i];
            if (g == 0 || x > 240) break;
            Font_DrawGlyphTinted(g, canvas, (u16)x, (u16)y, t);
            x += (g >= ENG_LO && g < ENG_HI) ? WIDTH_TBL[g] : 0xc;
        }
    } else {                                             /* normal: FUN_08153fc8 (+0x200 mirror) */
        void *canvas = (void *)(*(volatile u32 *)0x08154b2c);
        for (i = 0, x = 0x2c; i < 40; ++i) {
            u16 g = name[i];
            if (g == 0 || x > 240) break;
            FUN_08153fc8(g, canvas, x, y - 2, tint);
            x += (g >= ENG_LO && g < ENG_HI) ? WIDTH_TBL[g] : 0xa;
        }
    }
}

__attribute__((naked, used, section(".text.entry")))
void cave_entry4(void)
{
    __asm__ volatile(
        "mov  r0, r8            \n"   /* struct (high reg) -> low for ldrh */
        "ldrh r0, [r0, #0x12]   \n"   /* species id -> arg5 (for the race-0x2c sub-mode) */
        "sub  sp, sp, #8        \n"   /* reserve the 5th (stacked) argument slot */
        "str  r0, [sp, #0]      \n"
        "ldr  r0, [sp, #0x34]   \n"   /* arg1 = name ptr (sp+0x2c, shifted +8) — resolved by entry3 */
        "mov  r1, r10           \n"   /* arg2 = record */
        "mov  r2, r7            \n"   /* arg3 = y */
        "mov  r3, r9            \n"   /* tint<<24 (high reg) -> low for lsr */
        "lsr  r3, r3, #24       \n"   /* arg4 = tint */
        "bl   fusion_name_vwf   \n"
        "add  sp, sp, #8        \n"
        "ldr  r0, =0x08154b9f   \n"   /* skip the stock name loop -> mode code (0x08154b9e | thumb) */
        "bx   r0                \n"
    );
}

/* Fifth entry: VWF the fusion selected-material header + result-preview name (FUN_081547d8).  That
 * function draws a demon's name (record+0x22) + level from a demon id, used for the top "1st <name> LVnn"
 * header AND the per-row RESULT column — both still Japanese because it reads the inline name.  It has
 * the id directly (r6), so we resolve NAME_TABLE[id] and VWF-draw, replicating its three stock paths
 * (normal via FUN_08153fc8; race-0x2c special-id via FUN_08153fc8 @0x081548ac; race-0x2c other via
 * Font_DrawGlyphTinted @0x081548fc) + the level draw (FUN_081549bc).  Hooked at 0x0815480c
 * (`mov r4,#0; add r1,r5,#0`, the name-loop head); jumps to the stock epilogue @0x081548ea. */
typedef void (*lvl_fn)(int level, int x, int y, int tint);
#define FUN_081549bc ((lvl_fn)(0x081549bc | 1))   /* draws the level number */

static void fusion_hdr_glyphs(const u16 *name, void *canvas, s16 x, s16 y, u8 tint, int pitch, int viaFc8)
{
    int i;
    for (i = 0; i < 40; ++i) {
        u16 g = name[i];
        if (g == 0 || x > 240) break;
        if (viaFc8) FUN_08153fc8(g, canvas, x, y, tint);
        else        Font_DrawGlyphTinted(g, canvas, (u16)x, (u16)y, tint);
        x += (g >= ENG_LO && g < ENG_HI) ? WIDTH_TBL[g] : (s16)pitch;
    }
}

__attribute__((used, noinline))
void fusion_name2_vwf(const u16 *name, const u16 *record, int id, int x, int y, u8 tint)
{
    int race = *(const signed char *)record;
    if (id == 0xff) return;                              /* stock skips the name draw for 0xff */
    if (race == 0x2c) {
        if (id == 0x150 || id == 0x155 || id == 0x168 || id == 0x169)
            fusion_hdr_glyphs(name, (void *)(*(volatile u32 *)0x081548ac), (s16)x, (s16)(y - 1), tint, 0xa, 1);
        else
            fusion_hdr_glyphs(name, (void *)(*(volatile u32 *)0x081548fc), (s16)(x + 4), (s16)y, 4, 0xc, 0);
    } else {
        fusion_hdr_glyphs(name, (void *)(*(volatile u32 *)0x08154864), (s16)x, (s16)y, tint, 0xa, 1);
        FUN_081549bc(*(const u8 *)((const u8 *)record + 1), 0xe0, y + 5, tint);   /* level @ record+1 */
    }
}

__attribute__((naked, used, section(".text.entry")))
void cave_entry5(void)
{
    __asm__ volatile(
        "ldrh r0, [r5, #0x22]   \n"   /* name[0] (record+0x22) — empty? */
        "cmp  r0, #0            \n"
        "beq  8f                \n"
        "mov  r0, r5            \n"
        "add  r0, #0x22         \n"   /* record+0x22 = demon name ptr */
        "bl   pooled_name       \n"   /* -> NAME_TABLE[id] or 0 */
        "cmp  r0, #0            \n"
        "bne  9f                \n"
        "mov  r0, r5            \n"   /* not pooled: inline record+0x22 */
        "add  r0, #0x22         \n"
        "9:                     \n"
        "mov  r1, r5            \n"   /* arg2 = record */
        "mov  r2, r6            \n"   /* arg3 = id */
        "mov  r3, r9            \n"   /* arg4 = x (param_2) */
        "sub  sp, sp, #8        \n"
        "str  r7, [sp, #0]      \n"   /* arg5 = y (param_3) */
        "mov  r4, r10           \n"   /* tint (high reg) -> low */
        "str  r4, [sp, #4]      \n"   /* arg6 = tint */
        "bl   fusion_name2_vwf  \n"
        "add  sp, sp, #8        \n"
        "8:                     \n"
        "ldr  r0, =0x081548eb   \n"   /* stock epilogue (0x081548ea | thumb) */
        "bx   r0                \n"
    );
}

/* Sixth entry: the fusion selected-material HEADER name (Fusion_DrawMaterialHeader @0x08155998, a
 * callback Ghidra mis-decodes as ARM).  It draws "<slot> <race> <name> LVnn" of the chosen 1st/2nd/3rd
 * material; the name (record+0x22) stayed Japanese.  Its name loop loads the name base from sp+0x14
 * (set at 0x08155a74: `mov r1,r9; add r1,#0x22; str r1,[sp,#0x14]`, r9 = record) and BOTH the glyph
 * draw and the loop-continue check read that base — so a plain REDIRECT to NAME_TABLE[id] draws the
 * full English name with no truncation.  Hooked at 0x08155a4c (replacing `mov r1,r9; add r1,#0x22`); we
 * set r1 and resume at the stock str @0x08155a50.  (cave_entry7 then makes that loop VWF; the stock
 * 8-glyph cap still applies.) */
__attribute__((naked, used, section(".text.entry")))
void cave_entry6(void)
{
    __asm__ volatile(
        "mov  r0, r9            \n"   /* record (high reg) -> low */
        "add  r0, #0x22         \n"   /* record+0x22 = demon name ptr */
        "bl   pooled_name       \n"   /* -> NAME_TABLE[id] or 0 (preserves r4-r11) */
        "cmp  r0, #0            \n"
        "bne  7f                \n"
        "mov  r0, r9            \n"   /* not pooled: inline record+0x22 */
        "add  r0, #0x22         \n"
        "7:                     \n"
        "mov  r1, r0            \n"   /* r1 = name base; stock str@0x08155a50 writes it to sp+0x14 */
        "ldr  r0, =0x08155a51   \n"   /* resume at `str r1,[sp,#0x14]` (0x08155a50 | thumb) */
        "bx   r0                \n"
    );
}

/* Seventh entry: make the material-header name loop (Fusion_DrawMaterialHeader) VARIABLE-width.  The
 * stock loop advances X by a fixed 12px (`movs r7,#0xc0; lsl r7,#0xc; adds r4,r4,r7`, r4 = X<<16) at
 * 0x08155af2.  We replace the fixed advance with WIDTH_TBL[glyph]<<16 (the just-drawn glyph is [r5-2],
 * r5 being the post-increment name pointer) so the redirected English name (cave_entry6) packs tightly.
 * Hooked at 0x08155af2; resumes at the stock `adds r4,r4,r7` @0x08155af6. */
__attribute__((used, noinline))
int hdr_advance(u16 g)
{
    int w = (g >= ENG_LO && g < ENG_HI) ? WIDTH_TBL[g] : 0xc;   /* English VWF width, else 12px pitch */
    return w << 16;                                             /* r4 (X) is kept in <<16 fixed point */
}

__attribute__((naked, used, section(".text.entry")))
void cave_entry7(void)
{
    __asm__ volatile(
        "sub  r0, r5, #2        \n"   /* r5 = next glyph ptr; just-drawn glyph = [r5-2] */
        "ldrh r0, [r0]          \n"   /* glyph code */
        "bl   hdr_advance       \n"   /* -> (width << 16) in r0 (preserves r4-r11) */
        "mov  r7, r0            \n"   /* stock then does `adds r4,r4,r7` */
        "ldr  r0, =0x08155af7   \n"   /* resume at 0x08155af6 | thumb */
        "bx   r0                \n"
    );
}

/* Eighth entry: VWF + pixel-truncate the material-header RACE (Fusion_DrawMaterialHeader).  Separate
 * from the name, the header has a race loop @0x08155a56 (r7 = names_race[race] ptr, sentinel-UNAWARE)
 * drawing 3 fixed glyphs at x=30+i*12 via Font_DrawGlyphTinted; the NAME column starts at x=66.  We
 * hook the pre-loop setup @0x08155a52 (`mov r2,r10; lsl r5,r2,#0x10`), resolve the race sentinel, VWF-
 * draw the race truncated at x<64 (just shy of the name), and jump to the name setup @0x08155a7a,
 * SKIPPING the stock 3-glyph race loop.  r9=tint<<24, r10=30 are preserved for the name setup. */
__attribute__((used, noinline))
void fusion_hdr_race_vwf(const u16 *race, int y)
{
    void *canvas = (void *)RM_STATUS_TEXT_BUF;   /* 0x0200f874, the header text canvas */
    s16 x = 0x1e;                                /* race column starts at x=30 */
    int i;
    for (i = 0; i < 8; ++i) {
        u16 g = race[i];
        if (g == 0) break;
        int w = (g >= ENG_LO && g < ENG_HI) ? WIDTH_TBL[g] : 0xc;
        if (x + w > 64) break;                   /* pixel-width truncate (NAME column @ x=66) */
        Font_DrawGlyphTinted(g, canvas, (u16)x, (u16)y, 0xa);   /* race uses palette 0xa (stock) */
        x += w;
    }
}

__attribute__((naked, used, section(".text.entry")))
void cave_entry8(void)
{
    __asm__ volatile(
        "mov  r0, r7            \n"   /* race name ptr (sentinel-unaware) */
        "ldrh r1, [r0]          \n"
        "ldr  r2, =0xFFFF       \n"
        "cmp  r1, r2            \n"
        "bne  30f               \n"
        "ldrh r1, [r0, #2]      \n"   /* sentinel -> pooled race ptr (unaligned pair) */
        "ldrh r0, [r0, #4]      \n"
        "lsl  r0, r0, #16       \n"
        "orr  r0, r1            \n"
        "30:                    \n"
        "ldr  r1, [sp, #0xc]    \n"   /* arg2 = y (stock race draw used [sp+0xc]) */
        "bl   fusion_hdr_race_vwf \n"
        "ldr  r0, =0x08155a7b   \n"   /* skip stock race loop -> name setup @0x08155a7a | thumb */
        "bx   r0                \n"
    );
}

/* Ninth entry: English demon names in the Compendium (undefined callback drawer).  The demon-name loop
 * @0x08156a1c draws name[0..7] (r9 = record+0x22; demon id = r7 & 0x7fff) via FUN_080ac2a0 (the OBJ glyph
 * cache, the 384-639 sprite region) at fixed 12px.  The katakana fall in the +0x200-mirror-clobbered
 * range (0x1bc-0x1ff), which is the "partial corruption".  We hook the name-pointer setup @0x081569ce
 * (`mov r9,r0; movs r5,#0`; r0 = record+0x22) and swap r9 for NAME_TABLE[id] via pooled_name, so the loop
 * draws the English name (no katakana -> no corruption, and fewer cached glyphs -> eases the OBJ-cache
 * flicker).  Falls back to the inline JP name if not pooled.  Still fixed-pitch / 8-cap (VWF is next). */
__attribute__((naked, used, section(".text.entry")))
void cave_entry9(void)
{
    __asm__ volatile(
        "push {r0}              \n"   /* r0 = record+0x22 (inline JP name ptr) */
        "bl   pooled_name       \n"   /* pooled_name(record+0x22) -> NAME_TABLE[id] or 0 */
        "cmp  r0, #0            \n"
        "pop  {r1}              \n"
        "bne  91f               \n"
        "mov  r0, r1            \n"   /* not pooled: keep the inline record+0x22 */
        "91:                    \n"
        "mov  r9, r0            \n"   /* r9 = resolved name ptr (stock loop draws it) */
        "movs r5, #0            \n"   /* replicate stock `movs r5,#0` */
        "ldr  r0, =0x081569d3   \n"   /* resume at 0x081569d2 | thumb */
        "bx   r0                \n"
    );
}

/* Tenth entry: render the Compendium demon name as a WIDE STRIP instead of per-glyph sprites.  The screen
 * was hitting the 128-OAM ceiling (race + 6 demon names + labels all 1 sprite/glyph -> 128 active, tail of
 * the list dropped).  We render each name into a dedicated OBJ tile region (640-831, below the portrait's
 * 896 floor — see COMP_STRIP_BASE) and cover it with a few 32x16 sprites (~3/name vs ~8 per-glyph),
 * dropping the screen well under 128.  Bonus: the demon names leave the 384-639 glyph cache entirely, so
 * that cache holds only the stable race column -> its floorRow stops moving -> the cave_runtext label strips
 * above it stop being clobbered (the cursor-move flicker goes too).  Content-cached per row (6 hashes in the
 * free ctx-padding tail): re-render (blit+DMA) only when a row's name changes; emit the cover sprites every
 * frame.  Both seen/unseen paths converge at 0x08156a28 with r6=tint; r9=name (NAME_TABLE), r8=y live. */
typedef void *(*getbmp_fn)(u32 code);
typedef void  (*blit_fn)(void *src, void *dst, int sx, int sy, int dx, int dy, int w, int h, int tint);
typedef int   (*emit_fn)(const u16 *tmpl, u32 p2, int palOff, u32 prio, s16 tile, u16 x, s16 y);
#define Font_GetGlyphBitmap ((getbmp_fn)(RM_Font_GetGlyphBitmap | 1))
#define Blit                ((blit_fn)(RM_Font_BlitGlyph | 1))
#define EmitSprite          ((emit_fn)(RM_OAM_EmitSprite | 1))
#define OBJ_VRAM 0x06010000u
#define DMA3SAD (*(volatile u32 *)0x040000D4)
#define DMA3DAD (*(volatile u32 *)0x040000D8)
#define DMA3CNT (*(volatile u32 *)0x040000DC)
#define COMP_STRIP_BASE 640        /* demon strips live in OBJ tiles 640-831: BELOW the demon portrait,
                                    * which always starts at tile 896 across every captured demon (up to
                                    * ~972 for big ones).  ≤639 is too fragmented (UI tiles 534/542/576-583
                                    * split it into single lines).  2 names packed per 32-wide line
                                    * (left half cols 0-15, right half cols 16-31) -> 3 lines, 6 names. */
#define COMP_ROW_TILES  0x40       /* 64 tiles per LINE (32-wide canvas x 2 tile-rows); 2 names share a line */
/* 6 per-row content hashes in the ctx padding, just past cave_runtext's CacheState (+0x88..+0xd4). */
#define COMP_HASH ((volatile u32 *)(RM_GLYPH_CACHE_CTX + 0xD8))
static const u16 COMP_TMPL[3] = { 0x4000, 0x8000, 0x0000 };   /* 32x16 OBJ sprite (shape=horiz, size=2) */

static u32 comp_hash(const u16 *p)
{
    u32 h = 2166136261u; int i;
    for (i = 0; i < 24; ++i) { u16 g = p[i]; if (g == 0 || g == 0x0301) break; h = (h ^ g) * 16777619u; }
    return h ? h : 1u;
}

/* Blit the name into a 32-wide stack canvas (2 tile-rows) and DMA the whole row to its strip tiles
 * (full-row DMA also clears any longer previous name's tail). */
static void comp_render_strip(const u16 *name, u16 baseTile)
{
    u32 scratch[0x800 / 4];
    const u16 *p; s16 x = 0; int i;
    for (i = 0; i < (int)(sizeof scratch / 4); ++i) scratch[i] = 0;
    for (p = name; ; ++p) {
        u16 g = *p; if (g == 0 || g == 0x0301) break;
        if (x > 128) break;   /* half-line cap: 128px = 16 tiles, so 2 names fit in a 32-wide line */
        Blit(Font_GetGlyphBitmap(g), scratch, 0, 0, x, 0, 16, 16, 0);
        x += (g >= ENG_LO && g < ENG_HI) ? WIDTH_TBL[g] : 0xc;
    }
    /* DMA just this name's 16-tile half (the 32-wide scratch keeps Blit's stride correct). */
    DMA3SAD = (u32)scratch;            DMA3DAD = OBJ_VRAM + (u32)baseTile * 0x20;
    DMA3CNT = 0x80 | 0x84000000u; (void)DMA3CNT;          /* 16 tiles, top tile-row */
    DMA3SAD = (u32)scratch + 0x400;    DMA3DAD = OBJ_VRAM + (u32)(baseTile + 32) * 0x20;
    DMA3CNT = 0x80 | 0x84000000u; (void)DMA3CNT;          /* 16 tiles, bottom tile-row */
}

__attribute__((used, noinline))
void comp_name_strip(const u16 *name, int y, int flag)
{
    int row = 0, yy = y - 0x3a;
    u16 baseTile, cells, j, nspr; s16 x; const u16 *p; u32 h;
    while (yy >= 0xc && row < 6) { yy -= 0xc; ++row; }          /* row 0..5 from y = row*0xc + 0x3a */
    baseTile = (u16)(COMP_STRIP_BASE + (row >> 1) * COMP_ROW_TILES + (row & 1) * 0x10);  /* 2/line */
    h = comp_hash(name);
    if (COMP_HASH[row] != h) { comp_render_strip(name, baseTile); COMP_HASH[row] = h; }
    x = 0;                                                      /* measure width -> cover-sprite count */
    for (p = name; ; ++p) { u16 g = *p; if (g == 0 || g == 0x0301) break;
                            x += (g >= ENG_LO && g < ENG_HI) ? WIDTH_TBL[g] : 0xc; }
    cells = (u16)((x + 2 + 15) >> 4);                           /* +2 ink overhang, ceil to 16px cells */
    cells = (u16)((cells + 1) & ~1u);                          /* even (32x16 pairs) */
    if (cells > 8) cells = 8;                                  /* half-line cap (all demon names fit) */
    nspr = (u16)(cells >> 1);
    for (j = 0; j < nspr; ++j)
        EmitSprite(COMP_TMPL, 0, flag, 0, (s16)(baseTile + j * 4), (u16)(8 + j * 32), (s16)y);
}

__attribute__((naked, used, section(".text.entry")))
void cave_entry10(void)
{
    __asm__ volatile(
        "mov  r0, r9            \n"   /* r9 = resolved name ptr (NAME_TABLE, from cave_entry9) */
        "mov  r1, r8            \n"   /* arg2 = y */
        "mov  r2, r6            \n"   /* arg3 = tint/flag (seen: 0/1 owned; unseen: 0xa grey) */
        "bl   comp_name_strip   \n"
        "ldr  r0, =0x08156a53   \n"   /* skip the stock glyph loop -> row increment @0x08156a52 | thumb */
        "bx   r0                \n"
    );
}

/* Eleventh entry: VWF the Compendium RACE column.  Stock draws race[r4] via FontSprite_DrawGlyph at a
 * FIXED 12px pitch (x = r4*12 + r9) in a loop @0x08156838.  We hook the loop body, VWF-draw the whole race
 * name (still per-glyph via FontSprite_DrawGlyph, so it stays in the now-demon-free glyph cache — the demon
 * names moved to strips, so there's OAM/cache headroom), then jump past the stock loop to the outer post
 * @0x08156858.  r7=race ptr, r9=x base, r6=packed row/tint (the value the stock stored at [sp]). */
typedef void (*fsg_fn)(u16 code, u16 p2, u16 p3, u16 x, u16 packed);
#define FontSprite_DrawGlyph ((fsg_fn)(RM_FontSprite_DrawGlyph | 1))

__attribute__((used, noinline))
void comp_race_vwf(const u16 *race, int xbase, int packed)
{
    s16 x = (s16)xbase;
    int i;
    /* names_race repoints long race names (Demonoid/Shinshou) to 0xFFFF + a pool pointer at
     * field+2 (read as two halfwords - the +2 slot is not 4-aligned).  Resolve it so they don't
     * draw the sentinel as garbage; cap 16 (vs the JP 8) so the pooled names aren't truncated. */
    if (race && race[0] == 0xFFFF)
        race = (const u16 *)((u32)race[1] | ((u32)race[2] << 16));
    for (i = 0; i < 16; ++i) {
        u16 g = race[i];
        if (g == 0 || g == 0x0301) break;
        FontSprite_DrawGlyph(g, 0, 0, (u16)x, (u16)packed);
        x += (g >= ENG_LO && g < ENG_HI) ? WIDTH_TBL[g] : 0xc;
    }
}

__attribute__((naked, used, section(".text.entry")))
void cave_entry11(void)
{
    __asm__ volatile(
        "mov  r0, r7            \n"   /* race name ptr */
        "mov  r1, r9            \n"   /* x base (stock x = r4*12 + r9) */
        "mov  r2, r6            \n"   /* packed row/tint (stock [sp]) */
        "bl   comp_race_vwf     \n"
        "ldr  r0, =0x08156859   \n"   /* skip stock glyph loop -> outer post @0x08156858 | thumb */
        "bx   r0                \n"
    );
}

/* Compendium RACE/NAME/LEVEL labels via the glyph cache (NOT cave_runtext strips) — fixes the post-
 * status-screen CORRUPTION.  cave_runtext content-caches its strips and, after a status-screen round-trip,
 * the label strips render stale/foreign tiles (the text path drifting toward 640+).  Routing the labels
 * through the glyph cache instead makes them robust: that cache is rebuilt on every screen reset
 * (FUN_080ac0f0), so it can't go stale, and it never writes past its 384-511 region.  Safe now that the
 * demon names are wide strips (OAM freed): labels per-glyph (~13 sprites) keeps the screen well under 128.
 * Same signature as Text_DrawSpriteString — the 3 stock label bls are repointed straight here. */
typedef void (*spr_fn)(u16 code, u16 a, u16 b, u16 x, u16 y, u16 flag);
#define FontSprite_DrawCached ((spr_fn)(RM_FontSprite_DrawCached | 1))

__attribute__((used, noinline))
void label_str_vwf(const u16 *str, int p2, int p3, int startX, int startY, int pitch)
{
    s16 x = (s16)startX;
    int i;
    (void)p2; (void)p3;
    for (i = 0; i < 16; ++i) {
        u16 g = str[i];
        if (g == 0 || g == 0x0301) break;
        FontSprite_DrawCached(g, 0, 0, (u16)x, (u16)startY, 0);
        x += (g >= ENG_LO && g < ENG_HI) ? WIDTH_TBL[g] : (u16)pitch;
    }
}

/* Compendium LEVEL-filter categories -> English "Lv<lo>-<hi>", drawn through the glyph cache.  The level
 * ranges ("10-19" etc., ROM table @RM_LEVEL_CAT_BASE, 0xC-byte stride) are stock-drawn by
 * Text_DrawSpriteString @0x081568bc -> cave_runtext strips, which go stale after a status-screen round-
 * trip (the leftover-tile glitch).  We hook that call, map the JP string ptr back to its range index,
 * synthesize "Lv<tens>0-<tens>9" (or "Lv1-9"), and draw via FontSprite_DrawCached (robust, rebuilt every
 * screen reset).  Glyph codes: '0'..'9' = ENG_LO+0x10.. , 'L'/'v'/'-' = ENG_LO + (ascii-0x20).  Non-level
 * callers (or an unrecognized ptr) fall back to drawing the original string through the cache. */
__attribute__((used, noinline))
void comp_level_vwf(const u16 *str, int p2, int p3, int startX, int startY, int pitch)
{
    u16 buf[10];
    const u16 *draw = str;
    int n = 0, i;
    u32 d = (u32)str - RM_LEVEL_CAT_BASE;
    u32 idx = (d * 0x1556u) >> 16;                     /* d / 0xC (reciprocal, validated below) */
    s16 x;
    (void)p2; (void)p3;
    if (idx < 10 && RM_LEVEL_CAT_BASE + idx * 0xC == (u32)str) {
        buf[n++] = (u16)(ENG_LO + 0x2C);               /* 'L' (=0xe8) */
        buf[n++] = 0x113;                              /* 'v' — font isn't ASCII-contiguous past 'u'(0x112) */
        if (idx == 0) {                                /* "Lv1-9" */
            buf[n++] = (u16)(ENG_LO + 0x11);           /* '1' */
            buf[n++] = (u16)(ENG_LO + 0x0D);           /* '-' */
            buf[n++] = (u16)(ENG_LO + 0x19);           /* '9' */
        } else {                                       /* "Lv<d>0-<d>9" */
            u16 t = (u16)(ENG_LO + 0x10 + idx);        /* tens digit '1'..'9' */
            buf[n++] = t;
            buf[n++] = (u16)(ENG_LO + 0x10);           /* '0' */
            buf[n++] = (u16)(ENG_LO + 0x0D);           /* '-' */
            buf[n++] = t;
            buf[n++] = (u16)(ENG_LO + 0x19);           /* '9' */
        }
        buf[n] = 0;
        draw = buf;
    }
    x = (s16)startX;
    for (i = 0; i < 16; ++i) {
        u16 g = draw[i];
        if (g == 0 || g == 0x0301) break;
        FontSprite_DrawCached(g, 0, 0, (u16)x, (u16)startY, 0);
        x += (g >= ENG_LO && g < ENG_HI) ? WIDTH_TBL[g] : (u16)pitch;
    }
}

/* Battle ANALYZE skill list.  FUN_080f3850 draws each skill name from Action record+6 glyph-by-glyph at a
 * fixed 12px pitch, but it is NOT sentinel-aware — so our 0xFFFF+pool-repointed skill names render as
 * garbage ("all corrupt").  We hook the name-draw loop @0x080f388e, resolve the sentinel (0xFFFF then a
 * pool pointer in the next two u16s, like cave_entry), and VWF-draw the English name into the stock canvas.
 * r6 = Action record+6 (name field), r5 = y<<16; canvas comes from the stock literal @0x080f38b8. */
__attribute__((used, noinline))
void analyze_skill_vwf(const u16 *name, int y, void *canvas)
{
    s16 x = 0xc;                                            /* stock base x (index*0xc + 0xc) */
    int i;
    if (name[0] == 0xFFFF)                                  /* sentinel -> pooled English name */
        name = (const u16 *)((u32)name[1] | ((u32)name[2] << 16));
    for (i = 0; i < 40; ++i) {
        u16 g = name[i];
        if (g == 0 || g == 0x0301) break;
        if (x > 240) break;
        Font_DrawGlyphTinted(g, canvas, (u16)x, (u16)y, 0);
        x += (g >= ENG_LO && g < ENG_HI) ? WIDTH_TBL[g] : 0xc;
    }
}

__attribute__((naked, used, section(".text.entry")))
void cave_entry13(void)
{
    __asm__ volatile(
        "mov  r0, r6            \n"   /* name ptr (Action record + 6) */
        "mov  r1, r5            \n"
        "lsr  r1, r1, #16       \n"   /* y = r5 >> 16 */
        "ldr  r2, =0x080f38b8   \n"   /* address of the stock canvas literal */
        "ldr  r2, [r2]          \n"   /* r2 = canvas (0x030002b4) */
        "bl   analyze_skill_vwf \n"
        "ldr  r0, =0x080f38ef   \n"   /* skip stock glyph loop -> loop tail @0x080f38ee | thumb */
        "bx   r0                \n"
    );
}

/* Battle ANALYZE race name -> VWF.  The stock loop @0x080f3bf6 draws the race name (now English, via the
 * RACE_REDIR getter redirect) glyph-by-glyph at a fixed 12px pitch.  We hook the loop setup (r0 = race name
 * ptr from the preceding bl), VWF-draw it (x=4, y=4, tint=6, into the stock canvas @0x080f3c44), then jump
 * past the stock loop to its after-loop tail @0x080f3c2e. */
__attribute__((used, noinline))
void analyze_race_vwf(const u16 *name, void *canvas)
{
    s16 x = 4;
    int i;
    for (i = 0; i < 40; ++i) {
        u16 g = name[i];
        if (g == 0 || g == 0x0301) break;
        if (x > 240) break;
        Font_DrawGlyphTinted(g, canvas, (u16)x, 4, 6);
        x += (g >= ENG_LO && g < ENG_HI) ? WIDTH_TBL[g] : 0xc;
    }
}

__attribute__((naked, used, section(".text.entry")))
void cave_entry14(void)
{
    __asm__ volatile(
        "ldr  r1, =0x080f3c44   \n"   /* address of the stock canvas literal */
        "ldr  r1, [r1]          \n"   /* r1 = canvas (0x030014b4) */
        "bl   analyze_race_vwf  \n"   /* r0 = race name ptr (from the preceding bl) */
        "ldr  r0, =0x080f3c2f   \n"   /* skip stock loop -> after-loop tail @0x080f3c2e | thumb */
        "bx   r0                \n"
    );
}

/* Battle ANALYZE detailed panel (param_1>2): two affinity rows (combatant f30/pad) + the drop item.  The
 * affinity rows are sentinel-repointed (FFFF + pool ptr, like skills) but drawn sentinel-unaware -> garbage;
 * the drop is the raw JP item/equipment pDisplayText.  Each is a glyph loop reading r4 (name ptr) at a fixed
 * 12px pitch into canvas 0x030002b4.  We hook each loop body (`ldrh r0,[r4]; add r4,#2`): affinities reuse
 * analyze_skill_vwf (resolves the sentinel, tint 0); the drop uses pooled_name->ITEM_TABLE (tint 6). */
__attribute__((used, noinline))
void analyze_drop_vwf(const u16 *name, int y, void *canvas)
{
    const u16 *eng = pooled_name(name);
    s16 x = 0xc;
    int i;
    if (eng) name = eng;                                    /* item/equip pDisplayText -> ITEM_TABLE */
    for (i = 0; i < 40; ++i) {
        u16 g = name[i];
        if (g == 0 || g == 0x0301) break;
        if (x > 240) break;
        Font_DrawGlyphTinted(g, canvas, (u16)x, (u16)y, 6);
        x += (g >= ENG_LO && g < ENG_HI) ? WIDTH_TBL[g] : 0xc;
    }
}

__attribute__((naked, used, section(".text.entry")))
void cave_entry15(void)   /* f30 affinity row */
{
    __asm__ volatile(
        "mov  r0, r4            \n"
        "movs r1, #3            \n"
        "ldr  r2, =0x030002b4   \n"
        "bl   analyze_skill_vwf \n"
        "ldr  r0, =0x080f3b6d   \n"   /* -> pad loop setup @0x080f3b6c | thumb */
        "bx   r0                \n"
    );
}

__attribute__((naked, used, section(".text.entry")))
void cave_entry16(void)   /* pad affinity row */
{
    __asm__ volatile(
        "mov  r0, r4            \n"
        "movs r1, #0x10         \n"
        "ldr  r2, =0x030002b4   \n"
        "bl   analyze_skill_vwf \n"
        "ldr  r0, =0x080f3b99   \n"   /* -> drop setup @0x080f3b98 | thumb */
        "bx   r0                \n"
    );
}

__attribute__((naked, used, section(".text.entry")))
void cave_entry17(void)   /* drop item */
{
    __asm__ volatile(
        "mov  r0, r4            \n"
        "movs r1, #0x1d         \n"
        "ldr  r2, =0x030002b4   \n"
        "bl   analyze_drop_vwf  \n"
        "ldr  r0, =0x080f3bf1   \n"   /* -> race setup @0x080f3bf0 | thumb */
        "bx   r0                \n"
    );
}

/* Battle ANALYZE / top-bar enemy NAME -> English.  FUN_080f3c4c copies the combatant name (record+0x22)
 * into a stack buffer and draws it via Text_DrawSpriteString @0x080f3d16 (-> cave_runtext strip; that's why
 * it showed as a JP strip with clobbered katakana).  We hook that call: resolve record+0x22 -> NAME_TABLE
 * via pooled_name (r5 = the record) and pass the English name instead of the JP copy, then tail-call
 * Text_DrawSpriteString with the stack args intact and return to 0x080f3d1a.  r4 (the function's) and
 * [sp]/[sp+4] (startY/pitch) MUST be preserved -> no push; use scratch r6/r7. */
__attribute__((naked, used, section(".text.entry")))
void cave_entry18(void)
{
    __asm__ volatile(
        "mov  r6, lr            \n"   /* save return (0x080f3d1a); no sp shift keeps [sp]/[sp+4] */
        "mov  r7, r0            \n"   /* save the JP copy (fallback) */
        "mov  r0, r5            \n"   /* r5 = combatant record */
        "add  r0, #0x22         \n"   /* r0 = record+0x22 (name field) */
        "bl   pooled_name       \n"   /* -> NAME_TABLE[id] or 0 */
        "cmp  r0, #0            \n"
        "bne  1f                \n"
        "mov  r0, r7            \n"   /* not pooled -> the JP copy */
        "1:                     \n"
        "movs r1, #0            \n"   /* re-load printer args (pooled_name clobbered r1-r3) */
        "movs r2, #0            \n"
        "movs r3, #0x4a         \n"
        "ldr  r7, =0x080ac335   \n"   /* Text_DrawSpriteString | thumb */
        "bl   2f                \n"   /* tail-call trampoline (bl, no sp shift) */
        "mov  lr, r6            \n"
        "bx   lr                \n"   /* return to 0x080f3d1a */
        "2:                     \n"
        "bx   r7                \n"
    );
}

/* COMP demon-management / summon-info panel BIG selected-demon NAME (undefined func ~0x0812a3a8, draw
 * loop @0x0812a464).  Stock cap-8 FIXED-pitch via FontSprite_DrawGlyph (OAM sprite) from the JP record
 * +0x22.  Resolve record+0x22 -> NAME_TABLE[id] (pooled_name) and VWF-draw via the SAME sprite glyph
 * drawer (so it stays on the sprite substrate, unlike vwf_draw's BG-canvas path); JP fallback otherwise.
 * Stock draw position: x = r6 = 0x12, y = r7 = 0x59 (the 5th "packed" FontSprite_DrawGlyph arg). */
__attribute__((used, noinline))
void comp_bigname(const u16 *recname, u32 x, u32 y)
{
    const u16 *name = pooled_name(recname);
    int maxG = 8, i;
    if (name) maxG = 40; else name = recname;     /* pooled EN (full length) else JP record name */
    for (i = 0; i < maxG; ++i) {
        u16 g = name[i];
        if (g == 0) break;
        if (x > 240) break;
        FontSprite_DrawGlyph(g, 0, 0, (u16)x, (u16)y);
        x += (g >= ENG_LO && g < ENG_HI) ? WIDTH_TBL[g] : 0xc;
    }
}

/* veneer (bl from 0x0812a464, replacing `movs r4,#0; adds r1,r0,#0`): r0 = record (from
 * Combatant_GetRecord @0x0812a460), r6 = x (0x12), r7 = y (0x59).  Draw, then branch past the dead
 * cap-8 loop to 0x0812a4a0. */
__attribute__((naked, used, section(".text.entry")))
void cave_compname(void)
{
    __asm__ volatile(
        "add  r0, #0x22         \n"   /* record+0x22 (name field) */
        "mov  r1, r6            \n"   /* x */
        "mov  r2, r7            \n"   /* y */
        "bl   comp_bigname      \n"
        "ldr  r0, =0x0812A4A1   \n"   /* resume after the loop (Thumb) */
        "bx   r0                \n"
    );
}

/* COMP / item-detail 3-up DEMON-name row (Menu_DrawSkillRowTriple 0x080d2c44, inner loop @0x080d2cbe):
 * the DEMON twin of Menu_DrawItemNameTriple (item names, fixed by cave_menuitemname).  Cap-8 fixed-pitch
 * via Font_DrawGlyphTinted from the JP record+0x22.  Resolve record+0x22 -> NAME_TABLE[id] (pooled_name)
 * and VWF-draw on the same BG canvas (0x0200F874, distinct from SKILL_LIST_CANVAS); JP fallback. */
__attribute__((used, noinline))
void triple_demon(const u16 *recname, u32 x, u32 y)
{
    const u16 *name = pooled_name(recname);
    int maxG = 8, i;
    if (name) maxG = 40; else name = recname;
    for (i = 0; i < maxG; ++i) {
        u16 g = name[i];
        if (g == 0) break;
        if (x > 240) break;
        Font_DrawGlyphTinted(g, (void *)0x0200F874u, (u16)x, (u16)y, 0);
        x += (g >= ENG_LO && g < ENG_HI) ? WIDTH_TBL[g] : 0xc;
    }
}

/* veneer (bl from 0x080d2cbe, replacing `movs r4,#0; adds r6,r5,#1`): r7 = record+0x22, r9 = col(x),
 * r8 = y.  Draw, then branch past the dead cap-8 loop to 0x080d2ce8 (r6 = slot+1 already set @0x080d2c76). */
__attribute__((naked, used, section(".text.entry")))
void cave_tripledemon(void)
{
    __asm__ volatile(
        "mov  r0, r7            \n"   /* record+0x22 (name field) */
        "mov  r1, r9            \n"   /* x = col */
        "mov  r2, r8            \n"   /* y */
        "bl   triple_demon      \n"
        "ldr  r0, =0x080D2CE9   \n"   /* resume after the loop (Thumb) */
        "bx   r0                \n"
    );
}

/* Two-demon compare/arrange OAM panel name drawer FUN_080d2f04 (called twice by FUN_080d2f60 for the
 * [0x51]/[0x52] slots).  Identical sprite cap-8 draw as the COMP big name -> reuse comp_bigname.
 * veneer (bl from 0x080d2f20, replacing `movs r6,#0; adds r1,r0,#0`): r0 = record (from
 * Combatant_GetRecord @0x080d2f1c), r4 = x, r7 = y.  Draw, then branch to the epilogue 0x080d2f52. */
__attribute__((naked, used, section(".text.entry")))
void cave_comparedemon(void)
{
    __asm__ volatile(
        "add  r0, #0x22         \n"   /* record+0x22 (name field) */
        "mov  r1, r4            \n"   /* x */
        "mov  r2, r7            \n"   /* y */
        "bl   comp_bigname      \n"
        "ldr  r0, =0x080D2F53   \n"   /* resume at the epilogue (Thumb) */
        "bx   r0                \n"
    );
}

/* Field/menu COMP demon-list detail panel RACE field (Menu_DrawLabeledName 0x081289b8, reached via
 * FUN_081283c4 mode 2 = the COMP/summon/analyze demon-list side panel showing "RACE <name>" + "LV n").
 * Stock draws the race name from the names_race pointer table (DAT_08128aa4 = 0x08777de4, EN-repointed by
 * the names_race Mirror) glyph-by-glyph at a FIXED 0xc pitch, RIGHT-ALIGNED to a 5-glyph field AND capped
 * at 5 glyphs (so long English race names truncate too).  We hook the loop setup @0x08128a44 (r4 =
 * table[raceId] string ptr, already loaded) and VWF-draw the whole name LEFT-aligned at x=0x23, y=3,
 * tint 0, into the panel canvas (stock literal @0x08128aa8 = 0x03000ab4), then jump to the epilogue
 * @0x08128a9a.  Capped at x>0x54 to stay within the panel field (the LV digits sit at x=0x45..0x5d), which
 * matches the stock field's right extent (5th fixed glyph @0x53) so it can never overflow further. */
__attribute__((used, noinline))
void labelname_race_vwf(const u16 *name)
{
    void *canvas = *(void *const *)0x08128aa8;             /* panel canvas (0x03000ab4) */
    s16 x = 0x23;
    int i;
    for (i = 0; i < 16; ++i) {
        u16 g = name[i];
        if (g == 0 || g == 0x0301) break;
        if (x > 0x54) break;                               /* stay within the panel field */
        Font_DrawGlyphTinted(g, canvas, (u16)x, 3, 0);
        x += (g >= ENG_LO && g < ENG_HI) ? WIDTH_TBL[g] : 0xc;
    }
}

__attribute__((naked, used, section(".text.entry")))
void cave_entry19(void)
{
    __asm__ volatile(
        "mov  r0, r4            \n"   /* r4 = race name ptr (names_race table[raceId]) */
        "bl   labelname_race_vwf \n"
        "ldr  r0, =0x08128a9b   \n"   /* skip stock count+draw loops -> epilogue @0x08128a9a | thumb */
        "bx   r0                \n"
    );
}

/* Twentieth entry: VWF the SWORD sub-path of Fusion_DrawMaterialHeader's name loop — completes
 * cave_entry6/7.  That loop runs ONE iteration with two draw paths: demons (race != 0x2c) draw via
 * FUN_08153fc8 with X kept in r4<<16 (cave_entry7 already VWFs that advance @0x08155af2), while SWORDS
 * (race 0x2c — the "fake-demon" stubs 0x150-0x169) draw via Font_DrawGlyphTinted using a SEPARATE
 * plain-int X at [sp+0x18], advanced by a HARDCODED 0xc @0x08155ae8.  cave_entry7 never touched
 * [sp+0x18], so a sword's English name (NAME_TABLE[id], redirected by cave_entry6) like "Chi Sword"
 * rendered English but FIXED-PITCH.  We replace that fixed advance with WIDTH_TBL[glyph]: r5 = the
 * current glyph ptr (pre-increment — the +2 is @0x08155aee — and r5 == r1+r6, so it's the right glyph
 * for both paths; for demons the [sp+0x18] advance is unused, harmless).  hdr_advance returns the
 * width<<16 (r4 is fixed-point there); [sp+0x18] is a plain int, so >>16.  Hooked at 0x08155ae8
 * (`ldr r2,[sp,#0x18]; adds r2,#0xc`); resumes at the stock `str r2,[sp,#0x18]` @0x08155aec. */
__attribute__((naked, used, section(".text.entry")))
void cave_entry20(void)
{
    __asm__ volatile(
        "ldrh r0, [r5]          \n"   /* current glyph (same position for both paths; r5 == r1+r6) */
        "bl   hdr_advance       \n"   /* -> (width << 16) in r0 (preserves r4-r11) */
        "lsr  r0, r0, #16       \n"   /* [sp+0x18] X is a plain int -> width, not <<16 */
        "ldr  r2, [sp, #0x18]   \n"   /* current sword-path X */
        "add  r2, r2, r0        \n"   /* X += width (was a hardcoded += 0xc) */
        "ldr  r0, =0x08155aed   \n"   /* resume at `str r2,[sp,#0x18]` (0x08155aec | thumb) */
        "bx   r0                \n"
    );
}
