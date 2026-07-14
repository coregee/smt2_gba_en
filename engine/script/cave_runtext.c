/* cave_runtext.c  —  "running buffer" replacement for the OAM sprite-text printer
 * Text_DrawSpriteString (FUN_080ac334).  Compiled by devkitARM (Thumb, armv4t), injected by
 * patch_spritebuf.py.  Hooks Text_DrawSpriteString @0x080ac360 (after the prologue unpacks
 * r6=str,r10=p2,r9=p3,r8=startX,r7=startY,r4=pitch) via a naked veneer that calls the worker
 * then jumps to the stock epilogue 0x080ac398.
 *
 * WHY: the stock printer emits ONE hardware OAM sprite per glyph; English overflows the 128-OAM
 * limit and UI sprites drop.  We render each line into a packed VWF strip in the OBJ glyph-cache
 * rows (384-639) and cover it with a few wide sprites.
 *
 * This is a THIN ADAPTER over the shared cave_strip core (cave_strip.h): split the string into
 * lines and hand each to strip_run().  The core owns cell allocation, the content-addressed cache
 * (one stable cell range per string identity -> no positional-drift flicker, and repeat draws of
 * identical text are FREE), the incremental per-glyph reveal (typewriter: O(K), pauses per-
 * character), and the sprite emit.
 *
 * ALL text strips — there is no per-glyph fork.  An earlier optimisation routed short strings back
 * through the engine glyph cache when they fit the live OAM headroom; it was REMOVED 2026-06-17.
 * Deciding per string / per row meant a multi-row LIST (DDS exchange, battle item list) could draw
 * some rows per-glyph and some via the strip in the SAME frame, and the per-glyph path's engine-
 * cache growth (bottom-up from cell 0) collided with the sibling rows' strip cells — the scroll-
 * time garble and the "× in the top-left".  One renderer for everything = no such collisions.  The
 * fork's only real win (the battle command prompt, redrawn every frame with identical content) is
 * already covered by the strip's content cache: it re-blits once, then every repeat draw is a hash
 * HIT (no re-blit) — see cave_strip.h st_slot_for step 0.
 *
 * Reveal: a battle message line buffer that cave_typewriter stamped THIS frame is revealed up to
 * REVEAL_PX (cumulative across its lines); everything else draws whole (STRIP_ALL).  0xF000|id
 * demon-name / 0xE000|id item-name markers expand via NAME_TABLE / ITEM_TABLE (STRIP_MARK below). */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

/* cave_strip config — must precede the include */
#define STRIP_STATE RM_RUNTEXT_STRIP
#define STRIP_MARK RM_NAME_TABLE /* 0xF000|id -> pooled English demon name  */
#define STRIP_MARK_N RM_NAME_COUNT
#define STRIP_MARK2 RM_ITEM_TABLE /* 0xE000|id -> pooled English item/equip name (exchange/ \
                                   * battle item lists; patch_exchangelist writes the marker) */
#define STRIP_MARK2_N RM_ITEM_COUNT
#include "cave_strip.h"

#define NEWLINE 0x0300
#define TERM 0x0301
#define REVEAL_PX_V (*(volatile u16 *)RM_REVEAL_PX)
#define REVEAL_STAMP_V (*(volatile u16 *)RM_REVEAL_STAMP)

/* Worker: same signature as Text_DrawSpriteString.  Split the string into lines, strip_run each. */
__attribute__((used, noinline)) void run_text_worker(const u16 *str, u32 p2, u32 p3,
                                                     s16 startX, s16 startY, s16 pitch)
{
    int limit, priorPx, L;
    const u16 *lineStart, *p;

    if (str[0] == 0 || str[0] == TERM)
        return; /* empty: don't disturb the cache */

    /* Reveal frontier: only a battle line buffer the typewriter stamped this frame is clipped;
     * anything else (menus, shop, static modes) draws whole. */
    limit = STRIP_ALL;
    {
        /* Clip floor depends on which line is typing (render mode @state+0: 6 = a reward line
         * in the line-2 buffer, 2 = the header in line-1).  While a reward types, clip only from
         * line 2 so the header (line 1, below this floor) stays fully drawn instead of re-wiping
         * with every reward line. */
        u32 clip_lo = (*(volatile u8 *)RM_BMSG_STATE == 6) ? RM_BMSG_LINE2 : RM_BMSG_LINE_LO;
        if ((u32)str >= clip_lo && (u32)str < RM_BMSG_LINE_HI && REVEAL_STAMP_V == ST_FRAME)
            limit = REVEAL_PX_V;
    }

    /* one strip_run per line; key by (line start ptr ^ screen Y).  The Y term is essential:
     * LIST drawers (Battle_DrawItemListPage 0x080e0b8c and its bank/exchange siblings) draw EVERY
     * visible row from ONE shared stack buffer, so the pointer alone is identical for all rows ->
     * they'd all collapse onto a single cache row (the "every option shows the same entry, cycling"
     * glitch).  Folding the row's distinct Y in gives each row its own cache row.  For a real
     * multi-line message the ptr already differs per line and Y differs too, so keys stay distinct
     * and stable across frames (the typewriter reveal still accumulates on a fixed key). */
    priorPx = 0;
    L = 0;
    lineStart = str;
    for (p = str;; ++p)
    {
        u16 c = *p;
        if (c == 0 || c == TERM || c == NEWLINE)
        {
            int nG = (int)(p - lineStart);
            int lineY = (int)startY + L * (int)pitch;
            int reveal = (limit == STRIP_ALL) ? STRIP_ALL
                                              : (limit > priorPx ? limit - priorPx : 0);
            if (nG > 0)
                strip_run((u32)lineStart ^ ((u32)(u16)lineY << 16), lineStart, nG,
                          (int)startX, lineY, reveal, p2, p3, (int)pitch, 0);
            priorPx += (int)st_measure(lineStart, nG, (int)pitch);
            ++L;
            if (c == 0 || c == TERM || L >= STRIP_ROWS)
                break;
            lineStart = p + 1;
        }
    }
}

/* Naked veneer = the cave entry (bl patched in at 0x080ac360). */
__attribute__((naked, used, section(".text.entry"))) void cave_entry(void)
{
    __asm__ volatile(
        "sub  sp, sp, #8        \n"
        "str  r7, [sp, #0]      \n" /* arg5 = startY */
        "str  r4, [sp, #4]      \n" /* arg6 = pitch  */
        "mov  r0, r6            \n" /* arg1 = str    */
        "mov  r1, r10           \n" /* arg2 = p2     */
        "mov  r2, r9            \n" /* arg3 = p3     */
        "mov  r3, r8            \n" /* arg4 = startX */
        "bl   run_text_worker   \n"
        "add  sp, sp, #8        \n"
        "ldr  r0, =0x080ac399   \n" /* stock epilogue | thumb */
        "bx   r0                \n");
}
