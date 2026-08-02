/* cave_menuitemname.c -- item-detail 3-up name drawer -> English VWF via ITEM_TABLE.
 *
 *  Menu_DrawItemNameTriple 0x080d2b70 (via Item_RenderDescription) draws up to 3 item/equipment names
 *  glyph-by-glyph through Font_DrawGlyphTinted at a fixed 0xc pitch, cap-8, from the JP record name
 *  (pDisplayText) -- so English never fit and it drew Japanese.  Replace its inner cap-8 loop
 *  (0x080d2bfe..0x080d2c26) with a veneer -> worker that draws ITEM_TABLE[id] variable-width (JP
 *  fallback for untranslated), then branches past the dead loop to 0x080d2c28.
 *
 *  (The sibling demon held-item draw in Demon_DrawDetailPanel is already EN+VWF via patch_skilllist
 *  HOOK17; the COMP item/equip lists in FUN_08127eac use the shared fixed-pitch Skill_DrawRowTinted,
 *  handled separately if at all.)
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef int            s32;
typedef unsigned int   u32;

#include <rommap.h>

typedef void (*fdt_fn)(u16 g, int canvas, int x, int y, int tint);   /* Font_DrawGlyphTinted */
#define Font_DrawGlyphTinted ((fdt_fn)0x080AC981u)
#define WIDTH_TBL  ((const u8 *)RM_WIDTH_TABLE)
#define ITEM_TABLE ((const u16 *const *)RM_ITEM_TABLE)

#define A1_CANVAS 0x0200F874   /* Menu_DrawItemNameTriple canvas */

/* gc-sections linker root (ENTRY); never called. */
__attribute__((used, section(".text.entry")))
void cave_entry(void) {}

static int gw(u16 g) { return (g >= RM_ENG_LO && g < RM_ENG_HI) ? WIDTH_TBL[g] : 0xc; }

/* VWF item-name draw on a BG canvas (mirrors the stock Font_DrawGlyphTinted cap-8 loop, no cap). */
static void draw_item_vwf(const u16 *s, int canvas, int x, int y, int tint) {
    int i;
    if (!s) return;
    for (i = 0; i < 18; ++i) {
        u16 g = s[i];
        if (g == 0 || g == 0x0301) break;
        Font_DrawGlyphTinted(g, canvas, x, y, tint);
        x += gw(g);
    }
}

/* id = work[0x9c+slot*2] (already past the empty-slot sentinel check); jp = stock record name. */
__attribute__((used, noinline))
void cave_triple(u16 id, const u16 *jp, int x, int y) {
    const u16 *en = (id < RM_ITEM_COUNT && ITEM_TABLE[id]) ? ITEM_TABLE[id] : jp;
    draw_item_vwf(en, A1_CANVAS, x, y, 0);
}

/* veneer (bl from 0x080d2bfe): r10=work, r5=slot, r7=jp, r9=col(X), r8=Y.  Compute id, call the
 * worker, branch past the dead cap-8 loop to 0x080d2c28. */
__attribute__((naked, used, section(".text.entry")))
void veneer_triple(void) {
    __asm__ volatile(
        "mov  r0, r10        \n"
        "lsl  r1, r5, #1     \n"
        "add  r0, r0, r1     \n"
        "add  r0, #0x9c      \n"
        "ldrh r0, [r0]       \n"   /* id = work[0x9c + slot*2] */
        "mov  r1, r7         \n"   /* jp */
        "mov  r2, r9         \n"   /* x = col */
        "mov  r3, r8         \n"   /* y */
        "bl   cave_triple    \n"
        "ldr  r0, =0x080D2C29\n"   /* resume after the loop (Thumb) */
        "bx   r0             \n"
    );
}
