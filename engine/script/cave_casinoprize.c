/* cave_casinoprize.c -- casino minigame PRIZE box item name -> English VWF.
 *
 * The casino minigames draw the prize you're playing for in the PRIZE box from a per-minigame
 * INLINE Japanese name table (NOT the item record / ITEM_TABLE), via the fixed-pitch glyph-string
 * drawer FUN_0814adac -- so the prize showed Japanese (user report: Code Breaker "PRIZE: め組の纏").
 *
 * Code Breaker's prize draw is FUN_0814c318 (sole caller FUN_0814af14 @0x0814b008):
 *   - reads the prize ITEM ID from the prize-id table 0x0879EEE4 [variant*0x28 + sel*4]:
 *       +0x00 = item id, +0x02 = name X (centering), +0x26 = "at-max" label X
 *     (variant = work[5], sel = work[0x3f]; work = 0x0203A454)
 *   - if the player is at max quantity -> draws an "at-max" label (table 0x0879ECB6)
 *   - else -> draws the inline JP prize NAME (table 0x0879EC14, 9-glyph slots) fixed-pitch.
 *
 * English item/equipment names already live in ITEM_TABLE (patch_itemname mirrors BOTH the equipment
 * 0x00-0xCF and item 0xD0-0x159 ranges -> any-length pooled pointer).  We reimplement FUN_0814c318:
 * keep the at-max label path byte-for-byte, but for the prize NAME draw ITEM_TABLE[prizeId] as VWF
 * glyphs (real per-glyph widths), centered over the JP slot's footprint, falling back to the inline
 * JP name for untranslated/out-of-range ids (then it renders exactly as stock).  The `bl FUN_0814c318`
 * @0x0814b008 is repointed here.
 *
 * This is the casino TEMPLATE: the other minigames use the same prize-id-table + inline-JP-name
 * pattern in their own per-frame update functions (update table @0x0879243c) -- roll this out per game
 * once Code Breaker is BizHawk-verified.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

#include "rommap.h"

/* ROM routines, mirroring FUN_0814c318 / FUN_0814adac usage (Thumb addresses, bit0 set). */
typedef void (*rgc_fn)(int n);
#define Font_ResetGlyphSpriteCache ((rgc_fn)0x080AC0F1u)
typedef int (*maxq_fn)(u16 id);
#define Inventory_IsAtMaxQuantity ((maxq_fn)0x080C32FDu)
typedef void (*glyph_fn)(u16 g, int p2, int p3, int x, int y, int pal);
#define DrawGlyphSprite ((glyph_fn)0x080AC2A1u)            /* the per-glyph drawer FUN_0814adac calls */
typedef void (*str_fn)(const u16 *s, int p2, int p3, int x, int y, int pitch);
#define DrawStrFixed ((str_fn)0x0814ADADu)                 /* FUN_0814adac (stock fixed-pitch string) */

#define WIDTH_TBL  ((const u8 *)RM_WIDTH_TABLE)
#define ITEM_TABLE ((const u16 *const *)RM_ITEM_TABLE)

/* Code Breaker prize state (EWRAM work struct + ROM tables). */
#define CB_WORK   ((const u8 *)0x0203A454u)                /* minigame work struct */
#define CB_IDTAB  ((const u8 *)0x0879EEE4u)                /* prize-id table (id @+0, X @+2, maxX @+0x26) */
#define CB_MAXTBL ((const u8 *)0x0879ECB6u)                /* "at max quantity" label table */
#define CB_NAMTBL ((const u8 *)0x0879EC14u)                /* inline JP prize-name table (9-glyph slots) */
#define CB_BOX_CX 0x8c                                     /* PRIZE box center X.  The stock JP X is
   hardcoded PER PRIZE and inconsistent (some centered at ~141, many left-aligned at 100), so EN names
   drifted left/right by item.  Center every name here instead -- the tuned JP names converge to ~140-141
   and the widest EN prize ("Crescent Blade" 77px) centers to [102,179], inside the box. */

/* gc-sections linker root (ENTRY); never called. */
__attribute__((used, section(".text.entry")))
void cave_entry(void) {}

static int glyph_w(u16 g) { return (g >= RM_ENG_LO && g < RM_ENG_HI) ? WIDTH_TBL[g] : 0xc; }

static int name_pixw(const u16 *s) {
    int w = 0, i;
    for (i = 0; i < 18; ++i) { u16 g = s[i]; if (!g || g == 0x0301 || g == 0x300) break; w += glyph_w(g); }
    return w;
}

/* VWF-draw a name centered on a box center X (cx), so every prize is consistently centered
 * regardless of the stock per-prize JP X.  Mirrors FUN_0814adac's per-glyph DrawGlyphSprite(g,0,0,x,y,0xf). */
static void draw_centered(const u16 *s, int cx, int y) {
    int x = cx - name_pixw(s) / 2;
    int i;
    for (i = 0; i < 18; ++i) {
        u16 g = s[i];
        if (g == 0 || g == 0x0301) break;
        DrawGlyphSprite(g, 0, 0, x, y, 0xf);
        x += glyph_w(g);
    }
}

__attribute__((used, section(".text.entry")))
void cave_cbprize(void) {
    const u8 *work = CB_WORK;
    const u8 *idtab = CB_IDTAB;
    const u16 *rec;
    u16 prizeId;
    const u16 *jp, *en;
    u8 sel, variant;

    Font_ResetGlyphSpriteCache(0x380);
    sel = work[0x3f];
    variant = work[5];
    rec = (const u16 *)(idtab + sel * 4 + variant * 0x28);
    prizeId = rec[0];

    if (Inventory_IsAtMaxQuantity(prizeId) & 0xff) {
        /* at-max label: stock behavior verbatim (not an item name). */
        DrawStrFixed((const u16 *)(CB_MAXTBL + variant * 0xb4), 0, 0, rec[0x13] + 0x63, 0x1d, 0xa);
        return;
    }
    jp = (const u16 *)(CB_NAMTBL + variant * 0xb4 + sel * 0x12);
    en = (prizeId < RM_ITEM_COUNT && ITEM_TABLE[prizeId]) ? ITEM_TABLE[prizeId] : jp;
    draw_centered(en, CB_BOX_CX, 0x1d);
}

/* ----------------------------------------------------------------------------------------------
 * Big & Small (minigame group 0, update FUN_08149c7c -> FUN_0814a8b0) ALSO has an item-prize box,
 * drawn by the SAME inline-JP-name + FUN_0814adac pattern.  Its prize-id table 0x0879E2A4 (id@+0,
 * X@+2, stride outerIdx*0x2c + state*4; outerIdx = work[0x262], state = work[0x46]) parallels the
 * inline JP name table.  Rather than reimplement FUN_0814a8b0 (it also draws the board metasprites),
 * we redirect its TWO `bl FUN_0814adac` prize-name calls here: recompute the prize id from the work
 * struct, draw ITEM_TABLE[prizeId] VWF centered on the Big&Small box (0x76), JP fallback otherwise.
 * The passed `jp` (r0) is the stock inline name ptr (fallback); `y` (0x52) is the stock row.
 * -------------------------------------------------------------------------------------------- */
#define BS_WORK   ((const u8 *)0x0203A454u)
#define BS_IDTAB  ((const u8 *)0x0879E2A4u)                /* prize-id table (id@+0, X@+2) */
#define BS_BOX_CX 0x76                                     /* Big&Small PRIZE box center (tuned JP names
   converge ~118; widest EN prize "Happy Sandals" 73px -> [82,155], inside the box). */

__attribute__((used, section(".text.entry")))
void cave_bsname(const u16 *jp, int p2, int p3, int x, int y, int pitch) {
    const u8 *work = BS_WORK;
    u16 outerIdx = *(const u16 *)(work + 0x262);
    u16 state = *(const u16 *)(work + 0x46);
    const u16 *rec = (const u16 *)(BS_IDTAB + outerIdx * 0x2c + state * 4);
    u16 prizeId = rec[0];
    const u16 *en = (prizeId < RM_ITEM_COUNT && ITEM_TABLE[prizeId]) ? ITEM_TABLE[prizeId] : jp;
    (void)p2; (void)p3; (void)x; (void)pitch;
    draw_centered(en, BS_BOX_CX, y);
}
