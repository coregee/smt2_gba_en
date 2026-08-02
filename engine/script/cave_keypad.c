#include <rommap.h>

/* Passcode number-pad keypad ("Enter the code:") — fix the digits-clobber-the-prompt VRAM
 * collision (patch_keypad.py).
 *
 * The keypad display object (handler 0x080d4df4, an un-disassembled Thumb pocket) draws on ONE
 * OBJ-text line (Y=89): the PROMPT via Text_DrawSpriteString (which the EN build reroutes through
 * the strip renderer cave_runtext) and the ENTERED DIGITS via raw Font_DrawGlyphSprite (the stock
 * per-glyph cache — the one text path that bypasses the strip).  Both share the OBJ glyph-cache
 * block (base tile 0x180).  The strip floats the prompt at row floorRow = (cache_used_count+15)>>4;
 * but the keypad draws the prompt while the cache is still empty (count 0) -> floorRow 0 -> the
 * prompt lands in row 0.  Then the digit loop caches its glyphs bottom-up from cell 0 (also row 0)
 * and its tiles overwrite the prompt's strip tiles -> the prompt positions render the digit glyphs
 * (the "code drawn on top of 'Enter the code:'" bug; the digits ALSO draw correctly at x=124).
 *
 * Fix: this cave REPLACES the keypad's own Font_ResetGlyphSpriteCache(0x180) call and, right after
 * the reset, PRE-WARMS the cache with the 10 digit glyphs ('0'..'9' = tokens 0xCC..0xD5).  That
 * makes the used count 10 BEFORE any strip draws this frame, so the prompt's floorRow becomes 1 and
 * the strip puts it in OBJ row 1 — leaving row 0 to the digit cells, which the keypad's digit loop
 * then REUSES (Font_DrawGlyphSprite finds them already cached).  No row shares with the prompt, so
 * no VRAM collision; the digits keep their fixed-pitch positions and the prompt stays VWF.
 * Covers both the input phase (digits @x=124) and the post-confirm phase (digits @x=76).
 * (cave_entry is the gc-sections root; bl-patched in by patch_keypad.py.) */

typedef unsigned short u16;

#define Font_ResetGlyphSpriteCache ((void (*)(u16))(RM_Font_ResetGlyphSpriteCache | 1))
#define Font_CacheGlyphSprite      ((u16  (*)(u16))(RM_Font_CacheGlyphSprite | 1))

__attribute__((used, section(".text.entry")))
void cave_entry(void)
{
    int g;
    Font_ResetGlyphSpriteCache(0x180);      /* the reset this cave replaced */
    for (g = 0xCC; g <= 0xD5; g++)           /* pre-warm '0'..'9' -> count 10 -> prompt floorRow 1 */
        Font_CacheGlyphSprite((u16)g);
}
