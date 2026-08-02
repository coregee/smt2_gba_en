/* cave_dictinfo.c -- DDS demon-dictionary FULL-INFO detail screen (RacePanel 0x080dc6d0).
 *
 * This screen draws on a BG canvas via Font_DrawGlyphTinted (0x080ac980) -- a DIFFERENT substrate
 * from the dictionary list/columns (OBJ glyph cache via FontSprite_DrawGlyph, handled in
 * cave_dictname.c), so those hooks never touched it.  Two fields stay Japanese here:
 *   - the demon NAME (record+0x22, an 8-glyph fixed-pitch loop), and
 *   - the PARENT RACE (the 族-clan family, distinct from the demon race which is already English
 *     via names_race).
 * Both are converted to pooled-English VWF on the SAME drawer (so they share the page's glyph
 * cache, no strip-substrate collision).  Kept in a SEPARATE blob from cave_dictname so the cave
 * allocator can place it in a leftover span.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#include <rommap.h>

typedef void (*fdt_fn)(u16 code, void *canvas, int x, int y, int tint); /* Font_DrawGlyphTinted */
typedef int  (*seen_fn)(u32 species);
#define Font_DrawGlyphTinted ((fdt_fn)(RM_Font_DrawGlyphTinted | 1))
#define Bitfield_CheckBit    ((seen_fn)(0x080C2644u | 1))   /* compendium "encountered" bit test */
#define WIDTH_TBL  ((const u8 *)RM_WIDTH_TABLE)
#define NAME_TABLE ((const u16 *const *)RM_NAME_TABLE)
#define DETAIL_CANVAS ((void *)0x0200F874u)                 /* full-info detail screen BG canvas */

/* gc-sections linker root (ENTRY symbol); never called.  The real entries are __attribute__((used))
 * so the linker retains them. */
__attribute__((used, section(".text.entry")))
void cave_entry(void) {}

/* shared VWF draw on the detail BG canvas: stop at NUL / 0x0301 / cap glyphs / x past the field. */
static void draw_tinted(const u16 *s, int x, int y, int cap)
{
    int i;
    if (!s) return;
    for (i = 0; i < cap; ++i) {
        u16 g = s[i];
        if (g == 0 || g == 0x0301) break;
        if (x >= 0x64) break;                          /* keep within the panel field width */
        Font_DrawGlyphTinted(g, DETAIL_CANVAS, x, y, 0);
        x += (g >= RM_ENG_LO && g < RM_ENG_HI) ? WIDTH_TBL[g] : 0xc;
    }
}

/* demon NAME: VWF the pooled English when seen+translated, else the JP/"?????" record name
 * (record+0x22).  Never reveal an unseen demon's English name. */
__attribute__((used, noinline))
void dict_name_vwf_tinted(u16 species, const u8 *rec, int x, int y)
{
    const u16 *s = (const u16 *)(rec + 0x22);
    if (species < RM_NAME_COUNT && Bitfield_CheckBit(species) && NAME_TABLE[species])
        s = NAME_TABLE[species];
    draw_tinted(s, x, y, 40);
}

/* PARENT RACE: recover parentId from the JP cell ptr (cells are 0x10 bytes), VWF the pooled English
 * (PARENTRACE_EN_PTRS, no length limit) when present, else the JP cell. */
__attribute__((used, noinline))
void dict_parentrace_vwf(const u16 *jpCell, int x, int y)
{
    const u16 *s = jpCell;
    u32 p = (u32)jpCell, d;
    if (p >= RM_PARENTRACE_NAME_TABLE &&
        p <  RM_PARENTRACE_NAME_TABLE + RM_PARENTRACE_COUNT * 0x10) {
        d = p - RM_PARENTRACE_NAME_TABLE;
        if ((d & 0xf) == 0) {
            const u16 *en = ((const u16 *const *)RM_PARENTRACE_EN_PTRS)[d >> 4];
            if (en) s = en;
        }
    }
    draw_tinted(s, x, y, 16);
}

/* demon-name veneer (bl from 0x080dc776, replacing the per-glyph loop init): r7 = combatant record;
 * species = [DICT_STATE+0x38]; draw at (4, 0x2c).  Branches PAST the dead per-glyph loop to the
 * alignment-label draw @0x080dc7a8 (r7 preserved by the AAPCS call). */
__attribute__((naked, used, section(".text.entry")))
void cave_info_name(void)
{
    __asm__ volatile(
        "ldr  r0, =0x020399E0   \n"   /* DICT_STATE            */
        "ldrh r0, [r0, #0x38]   \n"   /* arg1 = species        */
        "mov  r1, r7            \n"   /* arg2 = combatant record (C adds +0x22) */
        "movs r2, #4            \n"   /* arg3 = x              */
        "movs r3, #0x2c         \n"   /* arg4 = y              */
        "bl   dict_name_vwf_tinted \n"
        "ldr  r0, =0x080DC7A9   \n"   /* resume past the loop (Thumb) */
        "bx   r0                \n"
    );
}

/* parent-race veneer (bl from 0x080dc744, replacing `adds r0,r1,#0; mov r1,sl`): r1 = JP cell ptr.
 * Draw at (4, 0xe); branch PAST the dead Text_DrawStringTinted call to the merge point 0x080dc750. */
__attribute__((naked, used, section(".text.entry")))
void cave_info_parent(void)
{
    __asm__ volatile(
        "mov  r0, r1            \n"   /* arg1 = JP cell ptr */
        "movs r1, #4            \n"   /* arg2 = x           */
        "movs r2, #0xe          \n"   /* arg3 = y           */
        "bl   dict_parentrace_vwf \n"
        "ldr  r0, =0x080DC751   \n"   /* resume past the JP draw (Thumb) */
        "bx   r0                \n"
    );
}
