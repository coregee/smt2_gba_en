/* cave_strip.h — shared OBJ sprite-strip text core.
 *
 * One implementation of the "pack glyphs into the OBJ glyph-cache rows (tiles 384-639),
 * cache so unchanged content isn't re-blitted, cover with wide sprites" machine that
 * cave_runtext / cave_markerlist / cave_msgwin each used to hand-roll (each with its own
 * cache model + the bugs that came with it — the positional-cell flicker, the O(K^2)
 * typewriter re-render).  A renderer #includes this, defines the config macros below, and
 * drives it with one call per text run.
 *
 * Model (kills both bug classes at the source):
 *   - CONTENT-ADDRESSED, ROW-KEYED cache.  Each cache row (a 16px-tall, 256px-wide row of the
 *     OBJ region, ABOVE the engine's label cache at floorRow) is a slot keyed by a stable
 *     caller `key` (a buffer pointer, a fixed row id, ...).  A run keeps the SAME row across
 *     frames regardless of draw order -> no positional drift, no stale duplicate (the flicker).
 *     LRU when more runs than rows.
 *   - INCREMENTAL, PER-GLYPH reveal.  `reveal` is a px frontier; the core blits each glyph
 *     exactly once, when it first crosses the frontier (O(K), not O(K^2)), and a HELD frontier
 *     holds the picture -> forced pauses (the flee ellipsis) visualise per-character for free.
 *     Sprites are re-emitted each frame (OAM is rebuilt) but clipped to `reveal`.
 *
 * Config the includer defines before #include:
 *   STRIP_STATE   - address of a StripState scratch block (~0x60 B)
 *   STRIP_MARK    - marker table base (RM_NAME_TABLE / RM_ITEM_TABLE); 0 disables expansion
 *   STRIP_MARK_N  - that table's count (only if STRIP_MARK != 0)
 */
#ifndef CAVE_STRIP_H
#define CAVE_STRIP_H

#include "rommap.h"
#include "cave_glyph.h"   /* shared primitives: st_gw/st_marker/st_measure/st_hash, ST_Blit/ST_Emit, ST_TMPL* */

#define STRIP_ALL  0x7fff         /* reveal value = show the whole run */
#define STRIP_ROWS 4              /* OBJ glyph-cache is 4 rows; one cache slot per row */
#define STRIP_PAD  2              /* last glyph's left-bearing overruns the summed width */

#define ST_CTX_BASE  (*(volatile u16 *)(RM_GLYPH_CACHE_CTX + 0))   /* base OBJ tile (384) */
#define ST_CTX_COUNT (*(volatile u16 *)(RM_GLYPH_CACHE_CTX + 2))   /* live label count    */
#define ST_CTX_CAP   (*(volatile u16 *)(RM_GLYPH_CACHE_CTX + 4))   /* capacity in cells   */
#define ST_STAGING   ((void *)RM_GLYPH_STAGING)                    /* 32-tile-wide canvas */
#define ST_OBJ_VRAM  0x06010000u
#define ST_FRAME     ((u16)(*(volatile u32 *)RM_FRAME_COUNTER))
#define ST_DMA3SAD (*(volatile u32 *)0x040000D4)
#define ST_DMA3DAD (*(volatile u32 *)0x040000D8)
#define ST_DMA3CNT (*(volatile u32 *)0x040000DC)

#define STRIP_CELLS 16            /* cells across one OBJ row (256px / 16px)             */
#define STRIP_SLOTS 12            /* max concurrent runs (message lines + list rows)     */

/* A slot owns a contiguous CELL RANGE within one OBJ cache row.  A full-width message line
 * takes a whole row; several short list names PACK side-by-side into one row (each name is
 * ~4-7 of the 16 cells).  This is the key change from the old row-per-run model, which only
 * had 4 rows total and so collapsed a 5-row list onto the few rows above the engine's label
 * cache (the "every option shows the same entry, cycling" glitch). */
typedef struct {
    u32 key;        /* caller identity owning this run (0 = free)                  */
    u32 hash;       /* content hash currently blitted                             */
    u16 blitPx;     /* px up to which this run's glyphs have been blitted          */
    u16 used;       /* frame counter at last use (LRU / live test)                */
    u8  row;        /* OBJ cache row [floorRow,capRows)                           */
    u8  cell0;      /* first cell within the row                                  */
    u8  nCells;     /* width in cells (the run never draws past this)             */
    u8  _pad;
} StripSlot;

typedef struct {
    u32 magic;
    u16 frame;      /* last frame strip_begin ran (screen re-enter detect)         */
    u8  floorRow;   /* first OBJ row above the label cache; usable [floorRow,capRows) */
    u8  capRows;
    StripSlot slot[STRIP_SLOTS];
} StripState;
#define ST (*(StripState *)STRIP_STATE)
#define ST_MAGIC 0x53545232u      /* 'STR2' (layout changed: cell-packed slots) */

/* st_gw + the engine-interface primitives are in cave_glyph.h (shared).  st_marker/st_measure/
 * st_hash are used only by this allocator, so they stay here. */

/* 0xF000|id -> pooled string via STRIP_MARK (demon names); 0xE000|id -> STRIP_MARK2 (item names,
 * optional); 0 for a normal glyph.  Real glyph tokens are < 0x2467, so 0xE000/0xF000 never clash. */
static const u16 ST_EMPTY[1] = { 0 };
static inline const u16 *st_marker(u16 g)
{
#if STRIP_MARK
    if ((g & 0xF000u) == 0xF000u) {
        u32 id = g & 0x0FFFu;
        const u16 *n = (id < STRIP_MARK_N) ? ((const u16 *const *)STRIP_MARK)[id] : 0;
        return n ? n : ST_EMPTY;
    }
#endif
#if defined(STRIP_MARK2) && STRIP_MARK2
    if ((g & 0xF000u) == 0xE000u) {
        u32 id = g & 0x0FFFu;
        const u16 *n = (id < STRIP_MARK2_N) ? ((const u16 *const *)STRIP_MARK2)[id] : 0;
        return n ? n : ST_EMPTY;
    }
#endif
    (void)g;
    return 0;
}

static u16 st_measure(const u16 *g, int n, int pitch)   /* px width of a run (markers expanded) */
{
    int i;
    u32 x = 0;
    for (i = 0; i < n; ++i) {
        const u16 *m = st_marker(g[i]);
        if (m) { for (; *m; ++m) x += st_gw(*m, pitch); }
        else x += st_gw(g[i], pitch);
    }
    return (u16)x;
}

static u32 st_hash(const u16 *g, int n)      /* content only — reveal is incremental */
{
    u32 h = 2166136261u;
    int i;
    for (i = 0; i < n; ++i) h = (h ^ g[i]) * 16777619u;
    return h ? h : 1u;
}

/* Once per frame (called from strip_run; idempotent within a frame): recompute floorRow (the
 * engine label cache grows from row 0) and invalidate slots the new layout can't keep.
 * NB: this is the original wipe-on-any-gap policy.  An earlier "survive short gaps" variant was
 * tried to spare the battle command prompt's per-menu-open re-blit, but that prompt now renders
 * on the per-glyph sprite path (cave_runtext fork) and never reaches the strip -- so the hack is
 * unnecessary, and it caused mid-sentence pauses on long strip lines.  Reverted.
 *
 * Selective floor-change wipe (2026-06-21): a TRUE reset -- first run (magic mismatch) or a frame
 * gap (screen re-enter clobbered our VRAM) -- wipes ALL slots.  But a BARE floorRow/capRows change
 * (the engine label cache grew/shrank this frame, same screen, consecutive frames) only invalidates
 * slots that fall BELOW the new floor (now inside the engine's grid/label region); slots still at
 * row >= floor keep their key, so st_slot_for step 1 reuses them and strip_run skips the re-blit
 * (content unchanged).  WHY: a screen whose floor wobbles every frame -- name entry toggles floor
 * 1<->2 on each category switch because the grid caches a different unique-glyph count per page --
 * used to re-blit EVERY label glyph on each switch (key zeroed -> the content cache, which needs
 * key!=0, couldn't reuse).  ~45 software Font_BlitGlyph in one frame overran the per-VBlank budget
 * for ~5 frames, displaying a half-rendered OBJ buffer (the labels ghosting onto the grid).  Keeping
 * the above-floor slots makes a page switch blit nothing.  Strictly fewer re-blits for every strip
 * screen; cannot expose stale content (a surviving slot still re-blits via strip_run's hash check if
 * its caller draws different text, and the engine only writes the wiped below-floor cells). */
static void strip_begin(void)
{
    u16 frame = ST_FRAME;
    if (frame == ST.frame && ST.magic == ST_MAGIC) return;   /* already done this frame */
    {
        u8 cap = (u8)(ST_CTX_CAP >> 4);
        u8 floor = (u8)((ST_CTX_COUNT + 15) >> 4);
        int gap = (ST.magic != ST_MAGIC) || ((u16)(frame - ST.frame) != 1);
        int i;
        if (gap || ST.floorRow != floor || ST.capRows != cap) {
            ST.magic = ST_MAGIC; ST.floorRow = floor; ST.capRows = cap;
            for (i = 0; i < STRIP_SLOTS; ++i)
                if (gap || ST.slot[i].row < floor)    /* keep slots still above the (new) floor */
                    ST.slot[i].key = 0;
        }
        ST.frame = frame;
    }
}

/* zero a cell range [cell0,cell0+nCells) of cache `row` in the staging canvas, before re-blitting
 * new content (Font_BlitGlyph OR-blits, so stale pixels from a previous occupant must be wiped). */
static void st_clear_cells(int row, int cell0, int nCells)
{
    u32 *cv = (u32 *)RM_GLYPH_STAGING;
    int ty = row << 1, c, r, t;       /* tile-row = row*2 (a cell row is 2 tile-rows tall) */
    for (c = cell0; c < cell0 + nCells; c++)
        for (r = 0; r < 2; r++)
            for (t = 0; t < 2; t++) {
                u32 *p = cv + ((((ty + r) << 5) + (c << 1) + t) << 3);
                p[0] = p[1] = p[2] = p[3] = p[4] = p[5] = p[6] = p[7] = 0;
            }
}

/* Invalidate any OTHER slot whose cells overlap [row, cell0, cell0+nCells): the run that just
 * claimed this range overwrote that VRAM, so the old occupant's cached content is gone.  Leaving
 * its key live would let it later hit the step-1 reuse path, find its content-hash unchanged, SKIP
 * the re-blit, and emit THIS run's pixels instead -- the fixed-position selector "cursor on option
 * 1 shows option 3" alias bug (a long 2-line menu option fully overlaps the previous option's cells;
 * short list names pack non-overlapping so they were never affected). */
static void st_free_aliased(int keep, int row, int cell0, int nCells)
{
    int k, e1 = cell0 + nCells;
    for (k = 0; k < STRIP_SLOTS; ++k)
        if (k != keep && ST.slot[k].key && ST.slot[k].used != ST.frame   /* NOT drawn this frame */
            && ST.slot[k].row == row
            && ST.slot[k].cell0 < e1 && ST.slot[k].cell0 + ST.slot[k].nCells > cell0)
            ST.slot[k].key = 0;
    /* `used != ST.frame` is essential: a multi-row message (e.g. the 3-line save-overwrite prompt)
     * draws every row THIS frame; if two of its rows pack into overlapping cells, freeing the one
     * drawn earlier this frame would make them evict each other every frame -> flicker.  Only a
     * STALE occupant (a previous screen's leftover, the menu-selector alias) is safe to invalidate. */
}

/* Find or assign the slot owning `key`, sized to `nCells`.  A slot is a CELL RANGE in a usable
 * row; multiple short runs pack into one row.  Stability: a key keeps its slot across frames
 * (list rows are keyed by screen position so scrolling updates content in place, no drift).
 *
 * Rows are filled TOP-DOWN (highest usable row first).  The engine's own OBJ glyph cache (the
 * item-list `×NN` quantity glyphs, scroll arrows, etc.) grows BOTTOM-UP from cell 0, and our
 * floorRow is read at the first strip of the frame -- BEFORE those per-row `×` glyphs are cached,
 * so it reads low.  Filling bottom-up then put the first name's strip in row 0, the very tiles the
 * `×` glyph later cached into -> the quantity `×` rendered the name's first cell ("So02") and the
 * name showed the `×`.  Filling top-down leaves the low rows free for the engine cache. */
static int st_slot_for(u32 key, int nCells, u32 hash)
{
    /* Usable rows = [floorRow, STRIP_ROWS).  The glyph-cache VRAM is the FULL STRIP_ROWS rows:
     * Font_ResetGlyphSpriteCache (0x080ac0f0) DMA-clears the block and sets capacity 0x40 cells
     * = 4 rows.  capRows tracks the engine's LIVE cap, which the battle reward window reports as
     * 3 -- capping cave_strip to it left a long persistent HEADER (line 1) and a REWARD line
     * (line 2) fighting over the single free row inside the cap; being 10 cells each they could
     * not coexist in one 16-cell row, so they evicted each other into the SAME cells and both
     * screen lines emitted whichever drew last (the reward showed on both lines).  The engine
     * fills bottom-up from cell 0 and its count is stable through a reward, so every row above
     * floorRow -- including any past capRows -- is free, cleared cache VRAM.  Using the full
     * region lets the header take row floorRow and the reward row floorRow+1. */
    int i, row, lo = ST.floorRow, hi = STRIP_ROWS;
    if (lo >= hi) return -1;                         /* no usable rows (label cache full) */
    if (nCells < 1) nCells = 1;
    if (nCells > STRIP_CELLS) nCells = STRIP_CELLS;

    /* 0. CONTENT-ADDRESSED reuse: a slot whose cells ALREADY hold this exact text (matched by
     *    content hash, fully blitted) is reused as-is regardless of which caller key owns it --
     *    no clear, no re-blit, just adopt it and let strip_run emit covering sprites at this
     *    caller's (x,y).  This is what the JP hardware glyph cache gives for free.  WHY: the
     *    battle command prompt ("What will <name> do?") is composed into the shared line buffer
     *    and drawn every frame (and twice per frame by sibling draws), so the position-keyed
     *    slot was being reallocated/cleared and the full ~18 glyphs SOFTWARE-RE-BLITTED every
     *    frame -- ~25% of frames dropped while it showed (enemy animation visibly slowed when
     *    spamming the menu).  Matching by content makes repeat draws of identical text free.
     *    Guard blitPx>0 so a half-allocated slot (VRAM not yet painted) is never matched. */
    for (i = 0; i < STRIP_SLOTS; ++i)
        if (ST.slot[i].key && ST.slot[i].hash == hash && ST.slot[i].blitPx > 0
            && ST.slot[i].nCells >= nCells && ST.slot[i].row >= lo && ST.slot[i].row < hi) {
            ST.slot[i].key = key;                    /* adopt for this caller */
            return i;
        }

    /* 1. reuse this key's existing slot if it still fits in a usable row */
    for (i = 0; i < STRIP_SLOTS; ++i)
        if (ST.slot[i].key == key) {
            if (ST.slot[i].nCells >= nCells && ST.slot[i].row >= lo && ST.slot[i].row < hi)
                return i;
            ST.slot[i].key = 0;                      /* grew past its range / row gone -> realloc */
        }

    /* 2. first-fit a gap of nCells contiguous free cells, scanning rows BOTTOM-UP (early
     *    addresses 384- first; fixes the battle negotiation target-cursor corrupting the message
     *    rows).  A cell is occupied iff a LIVE slot (drawn this frame or last) covers it. */
    for (row = lo; row < hi; ++row) {
        u32 occ = 0;
        int c, runLen = 0;
        for (i = 0; i < STRIP_SLOTS; ++i)
            if (ST.slot[i].key && ST.slot[i].row == row
                && (u16)(ST.frame - ST.slot[i].used) <= 1) {
                int cc, e = ST.slot[i].cell0 + ST.slot[i].nCells;
                for (cc = ST.slot[i].cell0; cc < e; ++cc) occ |= (1u << cc);
            }
        for (c = 0; c < STRIP_CELLS; ++c) {
            if (occ & (1u << c)) { runLen = 0; continue; }
            if (++runLen >= nCells) {
                int cell0 = c - nCells + 1, j;
                for (j = 0; j < STRIP_SLOTS; ++j) if (ST.slot[j].key == 0) break;
                if (j == STRIP_SLOTS) goto evict;    /* no free slot record */
                ST.slot[j].key = key; ST.slot[j].hash = 0; ST.slot[j].blitPx = 0;
                ST.slot[j].row = (u8)row; ST.slot[j].cell0 = (u8)cell0; ST.slot[j].nCells = (u8)nCells;
                st_free_aliased(j, row, cell0, nCells);
                return j;
            }
        }
    }

evict:
    /* 3. overflow: evict the globally-LRU slot and reuse its range (the new run clips to that
     *    width — graceful degradation for a list longer than the cells can hold). */
    {
        int lru = -1; u16 oldest = 0xffff;
        for (i = 0; i < STRIP_SLOTS; ++i)
            if (ST.slot[i].key && ST.slot[i].row >= lo && ST.slot[i].row < hi
                && ST.slot[i].used <= oldest) { oldest = ST.slot[i].used; lru = i; }
        if (lru < 0) return -1;
        ST.slot[lru].key = key; ST.slot[lru].hash = 0; ST.slot[lru].blitPx = 0;
        st_free_aliased(lru, ST.slot[lru].row, ST.slot[lru].cell0, ST.slot[lru].nCells);
        return lru;                                  /* keep its row/cell0/nCells */
    }
}

/* Render ONE contiguous run (one screen row of glyphs flowing left-to-right) into its
 * content-cached cell range and emit covering sprites clipped to `reveal` px.
 *   key   : stable identity (buffer ptr ^ screen Y -> one slot per screen position)
 *   g,n   : the FULL run's glyph tokens (markers ok);  x,y : screen position
 *   reveal: px frontier (STRIP_ALL = all);  grp/prio : OAM group/priority
 *   pitch : fixed grid pitch for non-EN glyphs (battle 12 / event 13; see st_gw)
 *   palOff: OAM palette offset for the covering sprites (0 = normal; 2 = grayed/ineligible row,
 *           matching the engine's grayed glyph drawer 0x080ac2a0 — applies to the whole run)
 * Incremental: blits only glyphs newly crossing `reveal` since last frame; a held reveal
 * holds the picture (forced pauses look per-character).  All staging/DMA/emit cell indices are
 * OFFSET by the slot's cell0 so several short runs can share one cache row. */
static void strip_run(u32 key, const u16 *g, int n, int x, int y, int reveal,
                      u32 grp, u32 prio, int pitch, int palOff)
{
    int slot, i, blitFrom, blitTo, shownCells, j, row, cell0, maxCells;
    u16 base, tileTL, totalPx;
    u32 px, hash;
    StripSlot *S;

    strip_begin();
    if (n <= 0 || g[0] == 0) return;
    totalPx = st_measure(g, n, pitch);
    hash = st_hash(g, n);                           /* content key (full 32-bit) */
    slot = st_slot_for(key, (totalPx + STRIP_PAD + 15) >> 4, hash);
    if (slot < 0) return;                          /* no usable cache cells */
    S = &ST.slot[slot];
    row = S->row; cell0 = S->cell0; maxCells = S->nCells;   /* never draw past the slot */
    base   = (u16)(ST_CTX_BASE & 0x7ff);
    tileTL = (u16)(base + row * 0x40 + cell0 * 2);

    if (S->hash != hash) {                         /* content changed -> wipe + re-blit */
        st_clear_cells(row, cell0, maxCells);
        S->hash = hash;
        S->blitPx = 0;
    }
    if (reveal >= STRIP_ALL || reveal > (int)totalPx) reveal = totalPx;
    { int capPx = maxCells << 4; if (reveal > capPx) reveal = capPx; }   /* clip emit to slot width */

    /* Blit the WHOLE line as soon as its content appears (`blitTo = totalPx`), independent of
     * the reveal frontier -- then advance the typewriter with the COVERING SPRITES only (the
     * `shownCells` clip below), never re-blitting.  WHY: a software Font_BlitGlyph on every
     * reveal-advance frame dropped a frame every time, because battle scenes run right at the
     * per-VBlank CPU budget and even 2-4 blits tip them over (measured: dropped frames ==
     * blit frames).  Pre-blitting collapses all K blits into the single content-change frame
     * (one hitch hidden as the window opens) and leaves the reveal blit-free.  Still O(K) total
     * (the full-line buffer is content-stable across the reveal, so the hash matches and we
     * blit once).  For non-typewriter callers reveal==totalPx already, so blitTo==reveal -> no
     * behaviour change.
     *
     * EXCEPTION -- PER-PIXEL reveal (RM_REVEAL_FINE, set by cave_typewriter for a battle line with
     * 0x315 pause tokens, i.e. the flee "...." ellipsis): blit only up to `reveal`.  The pre-blit
     * + 16px-cell sprite clip can only reveal a whole cell at a time, so the narrow dots (~3px,
     * ~5/cell) all popped in together; blitting incrementally leaves the un-revealed part of the
     * boundary cell blank, so each dot appears exactly when REVEAL_PX crosses it.  Still O(K)
     * (blitFrom = S->blitPx -> each glyph blitted once as it crosses the frontier, content hash
     * unchanged so no re-clear); the extra cost is only blits-during-reveal, and a pause line is a
     * calm moment that reveals mostly while HELD (blitTo==blitFrom -> no blit).  Only fine + a real
     * typewriter clip (reveal<totalPx) differs; for STRIP_ALL callers reveal==totalPx either way. */
    blitTo = (*(volatile u16 *)RM_REVEAL_FINE) ? reveal : (int)totalPx;
    { int capPx = maxCells << 4; if (blitTo > capPx) blitTo = capPx; }

    blitFrom = S->blitPx;
    if (blitTo > blitFrom) {                         /* paint every not-yet-blitted glyph (once) */
        px = 0;
        for (i = 0; i < n; ++i) {
            const u16 *m = st_marker(g[i]);
            if (m) {
                for (; *m; ++m) {
                    u16 w = st_gw(*m, pitch);
                    if ((int)px >= blitTo) break;
                    if ((int)px >= blitFrom)
                        ST_Blit(ST_GetBmp(*m), ST_STAGING, 0, 0, cell0 * 16 + (int)px, row * 16, 16, 16, 0);
                    px += w;
                }
                if ((int)px >= blitTo) break;
            } else {
                u16 w = st_gw(g[i], pitch);
                if ((int)px >= blitTo) break;
                if ((int)px >= blitFrom && g[i] != 0)
                    ST_Blit(ST_GetBmp(g[i]), ST_STAGING, 0, 0, cell0 * 16 + (int)px, row * 16, 16, 16, 0);
                px += w;
            }
        }
        {   /* DMA the run-local cells just blitted (old extent .. new), top+bottom tile-rows.
             * Absolute staging/VRAM cell = cell0 + local; a cell is 2 tiles = 0x40 B wide. */
            int c0 = blitFrom >> 4, c1 = (blitTo + STRIP_PAD + 15) >> 4;
            if (c1 > maxCells) c1 = maxCells;
            if (c1 > c0) {
                u32 sstg = (u32)ST_STAGING + (u32)row * 0x800u + (u32)(cell0 + c0) * 0x40u;
                u16 wTL = (u16)(tileTL + c0 * 2), words = (u16)((c1 - c0) * 0x10);
                ST_DMA3SAD = sstg;         ST_DMA3DAD = ST_OBJ_VRAM + (u32)wTL * 0x20;
                ST_DMA3CNT = words | 0x84000000u; (void)ST_DMA3CNT;
                ST_DMA3SAD = sstg + 0x400; ST_DMA3DAD = ST_OBJ_VRAM + (u32)(wTL + 32) * 0x20;
                ST_DMA3CNT = words | 0x84000000u; (void)ST_DMA3CNT;
            }
        }
        S->blitPx = (u16)blitTo;
    }

    /* emit covering sprites clipped to the revealed extent (32x16 pairs + a 16x16 odd cell).
     * reveal<=0 -> emit no cells (STRIP_PAD must not round a gated-off line up to 1 cell). */
    shownCells = (reveal <= 0) ? 0 : (reveal + STRIP_PAD + 15) >> 4;
    if (shownCells > maxCells) shownCells = maxCells;
    for (j = 0; j + 1 < shownCells; j += 2)
        ST_Emit(ST_TMPL32, grp, palOff, prio, (s16)(tileTL + j * 2), (u16)(x + j * 16), (s16)y);
    if (shownCells & 1)
        ST_Emit(ST_TMPL16, grp, palOff, prio, (s16)(tileTL + (shownCells - 1) * 2),
                (u16)(x + (shownCells - 1) * 16), (s16)y);
    S->used = ST_FRAME;
}

#endif /* CAVE_STRIP_H */
