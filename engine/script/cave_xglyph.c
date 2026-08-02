/* cave_xglyph.c — route the exchange/battle item-list "×NN" QUANTITY glyph through cave_runtext.
 *
 * Battle_DrawItemListPage draws the item name (a marker -> strip) and the quantity number (a strip),
 * but the "×" itself via FontSprite_DrawGlyph(token 0x3e, x=0xb9, y) @0x080e0ba2 — ONE glyph through
 * the engine's BOTTOM-UP glyph cache.  Once cave_strip fills its rows bottom-up too (early addresses
 * first, for the battle message-cursor fix), that engine × lands on the same low cell as the name
 * strip and overdraws it (the "So02" glitch).
 *
 * Fix (no menu special-case — just extend the list's coverage): redirect the × to the hooked
 * Text_DrawSpriteString as a 1-glyph string, so it occupies a managed strip cell at its own (x,y)
 * like the name and number.  No engine glyph-cache cell -> nothing for the strips to collide with.
 * Reuses the row's stack buffer (sp+0xc, free after the name draw); the × line Y differs from the
 * name's by 1px, so the strip key (buf ^ Y) stays distinct from the name's slot. */
typedef unsigned short u16;
typedef unsigned int   u32;
#include <rommap.h>

typedef void (*tdss_fn)(const u16 *str, u32 p2, u32 p3, int x, int y, int pitch);
#define Text_DrawSpriteString ((tdss_fn)(RM_Text_DrawSpriteString | 1))

__attribute__((used, noinline))
void xglyph_worker(u16 token, int x, int y, u16 *buf)
{
    buf[0] = token;
    buf[1] = 0;
    /* cave_runtext strips ALL text (no per-glyph fork), so this lone × takes a managed strip cell
     * beside the names; all rows' ×'s share ONE content-deduped tile -> no engine-cache collision. */
    Text_DrawSpriteString(buf, 0, 0, x, y, 12);   /* battle/list grid pitch = 12 */
}

/* bl'd in at 0x080e0ba2 (was `bl FontSprite_DrawGlyph`): r0 = × token, r3 = x, [sp] = y.
 * Named cave_entry: the cave_cc framework uses it as the linker ENTRY / gc-sections root. */
__attribute__((naked, used, section(".text.entry")))
void cave_entry(void)
{
    __asm__ volatile(
        "ldr  r2, [sp]         \n"   /* r2 = y (caller stack arg)             */
        "mov  r1, r3           \n"   /* r1 = x                                */
        "add  r3, sp, #0xc     \n"   /* r3 = &row buffer (sp+0xc)             */
        "push {lr}             \n"
        "bl   xglyph_worker    \n"   /* worker(token=r0, x=r1, y=r2, buf=r3)  */
        "pop  {pc}             \n"
    );
}
