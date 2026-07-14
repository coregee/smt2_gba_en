/* cave_msgwin.c — strip-packing renderer for the event-VM message window glyph list.
 *
 * Replaces the per-record draw loop of the hidden per-frame renderer @0x0813ded8
 * (ARM-broken Thumb region; hook = bl @0x0813dede + skip-to-second-loop branch).
 * The stock loop draws ONE OAM sprite per glyph record through the 64-cell glyph
 * sprite cache — fine for JP (<=51 glyphs/page), but a 4-line English page is
 * ~112 half-width glyphs.
 *
 * v1 (pair-packing) put TWO adjacent EN glyphs per 16x16 cell: a 4-line page
 * needed ~56 pair cells = exactly the NCELLS cap, so the cache filled mid-row-3
 * and everything after fell back to the stock path against a FULL cache —
 * garbled rows (live 2026-06-13, the Okamoto gym intro).
 *
 * v2 (this file): adjacent EN records in a row RUN compose into a STRIP of
 * cells packed by ink — each glyph OR-blits ONCE at its reflowed pixel offset.
 * A glyph whose ink crosses the 16px cell boundary lands in TWO cells with the
 * same single blit, because the staging canvas is linearly addressable across
 * a cell row — PROVIDED the spill cell is the canvas neighbour (cellB ==
 * cellA+1, same canvas row).  Font_BlitGlyph's source addressing assumes an
 * even srcX (nibble-pair reads), so two-part source-rect splits are NOT safe —
 * when adjacency can't be had (canvas row edge, fragmented pool), the glyph
 * falls back to a stock single-sprite draw and the strip re-anchors after it
 * (rare; visually identical).  One 16x16 sprite per STRIP SLICE, not per glyph
 * pair: a worst-case 4-row page is ~784px of ink ≈ 49 cells + tail slack,
 * comfortably inside NCELLS=56, and OAM weight stays at JP-page level (~50
 * sprites).  Spaces consume strip px but no cells/blits.  JP/full-width
 * records keep the stock path byte-identically.  The shop marker rows
 * (patch_shopname) keep v1's pair composer — verified live, and their
 * 8-slot-per-row state layout depends on it.
 *
 * Cell lifecycle: cells come from a per-State OWNED POOL.  A pool cell is
 * allocated once through Font_CacheGlyphSprite (then CLEARED — the engine
 * pre-expands a glyph at the cell origin, which is wrong for a strip),
 * retagged 0xFFFE in the engine code table so bare lookups never hit it, and
 * remembered in pool[].  A composition consumes pool cells in order via
 * poolCur, which PERSISTS across frames: the typewriter only ever composes
 * the newly revealed tail records, so the cursor keeps advancing append-only.
 * When a menu flow rewinds the record list and re-appends different tokens
 * over existing indexes (choice windows), the walk detects the token mismatch
 * and recomposes BOTH lists from poolCur=0 — same cells, re-cleared on take,
 * so rewinds never grow the engine cache.  The engine's own cache reset
 * (window transitions) is detected via the count watermark and drops pool
 * ownership entirely.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;

#include "rommap.h"
#include "cave_glyph.h"   /* shared engine-interface primitives (ST_GetBmp/ST_Blit/ST_Emit/ST_WIDTH) */

/* ---- engine glyph sprite cache (EWRAM ctx) ---- */
#define CTX_BASE (*(volatile u16 *)(RM_GLYPH_CACHE_CTX + 0))
#define CTX_COUNT (*(volatile u16 *)(RM_GLYPH_CACHE_CTX + 2))
#define CTX_CAP (*(volatile u16 *)(RM_GLYPH_CACHE_CTX + 4))
#define CTX_CODES ((volatile u16 *)(RM_GLYPH_CACHE_CTX + 8))
#define STAGING ((void *)RM_GLYPH_STAGING)

#define NCELLS 56       /* cells we let the engine allocate.  NOT 62: the staging->VRAM  \
                         * upload covers ceil(count/16) cell-ROWS, and cell row 3's tail \
                         * (cells ~59-63, tiles 0x256+) holds the STATIC template strip  \
                         * (shop price digits etc., uploaded once at screen init).       \
                         * preserve_tail() makes the row-3 upload extension an identity  \
                         * write; 56 keeps allocations clear of the strip itself. */
#define SENTINEL 0xFFFE /* retag for strip/pair cells in the engine code table */

/* ---- the (relocated) record list + the LIST-window record list ---- */
typedef struct
{
    u16 tok, x, y, flag;
} Rec;
#define RECS ((volatile Rec *)RM_MSG_GLYPH_LIST2)
#define COUNT (*(volatile u16 *)RM_MSG_GLYPH_COUNT)
#define CLIPY (*(volatile s16 *)RM_MSG_CLIP_Y)
#define MAXREC ((int)RM_MSG_GLYPH_REC_MAX) /* 192: a full 4-line VWF page (~140 records of
                                            * typical English) + narrow-glyph headroom.  The
                                            * appender clamp (patch_msgwin) matches. */
#define RECS2 ((volatile Rec *)RM_SHOP_GLYPH_LIST)
#define COUNT2 (*(volatile s16 *)RM_SHOP_GLYPH_COUNT)
#define MAXREC2 33

/* ---- our state (free EWRAM scratch; zero at boot; MUST fit the reserved span
 * RM_MSGWIN_STATE_SIZE — the reveal/strip cluster sits right after it; the
 * compile-time check below fails the build on overflow) ----
 *
 * chunk[i] = record i's placement in its row strip:
 *   bit 31      hasB (the glyph spilled into a second slice)
 *   bits 30-19  tok (12b — rewind/re-append detection)
 *   bits 18-15  dxA (px offset inside cellA)
 *   bits 14-8   cellB+1 (spill cell)
 *   bits  7-0   cellA+1
 * chunk2[] keeps v1's PAIR format (shop marker rows only):
 *   bit 31 hasB | tokB<<19 | tokA<<7 | (cell+1)
 */
typedef struct
{
    u32 chunk[MAXREC];
    u32 chunk2[MAXREC2];
    u8 pool[NCELLS]; /* owned cells, allocation order */
    u16 poolN;       /* pool high-water */
    u16 poolCur;     /* consumed by the current composition */
    u16 watermark;   /* engine cache count last frame (reset detector) */
    u16 lastFrame;   /* g_dwFrameCounter last cave_entry (gap detector) */
    u16 emptyRun;    /* consecutive frames with no records (dismissal debounce) */
} State;
#define S (*(State *)RM_MSGWIN_STATE)
typedef char state_fits_reserved_span[(sizeof(State) <= RM_MSGWIN_STATE_SIZE) ? 1 : -1];

#define CH_CELLA(c) ((int)((c) & 0xff) - 1)
#define CH_CELLB(c) ((int)(((c) >> 8) & 0x7f) - 1)
#define CH_DXA(c) (((c) >> 15) & 0xf)
#define CH_TOK(c) (((c) >> 19) & 0xfff)
#define CH_HASB 0x80000000u
#define CH_FBMARK 0xffu /* cellA field value: stock-drawn record (no cells) */
#define CH_ISFB(c) (((c) & 0xff) == CH_FBMARK)

/* v1 pair format (chunk2 / shop marker rows only) */
#define P_CELL(c) ((int)((c) & 0x7f) - 1)
#define P_TOKA(c) (((c) >> 7) & 0xfff)
#define P_TOKB(c) (((c) >> 19) & 0xfff)
#define P_MAKE(cell, ta) (((u32)(cell) + 1) | ((u32)(ta) << 7))

/* ---- engine entry points (Thumb) ---- */
/* GetBmp/Blit/Emit/WIDTH + their typedefs come from cave_glyph.h (ST_*); alias the local names so
 * the composer below is unchanged.  CacheGlyph/DrawEx/TMPL are msgwin-specific (pool allocation via
 * the engine cache, the cached-glyph drawer, the single-cell sprite template) and stay. */
typedef int (*cache_fn)(u16 code);
typedef void (*drawex_fn)(s16 code, u32 p2, u32 p3, u16 x, s32 y, s32 flag);

#define GetBmp ST_GetBmp
#define Blit   ST_Blit
#define Emit   ST_Emit
#define WIDTH  ST_WIDTH
#define CacheGlyph ((cache_fn)(RM_Font_CacheGlyphSprite | 1))
#define DrawEx ((drawex_fn)(RM_FontSprite_DrawCached | 1))
#define TMPL ((const u16 *)RM_SPRITE_TMPL_GLYPH)

/* The staging->VRAM upload is ONE-SHOT: CacheGlyph allocation arms it
 * (DisplayList_Add(Font_UploadGlyphSpriteTiles), dirty flag @ctx+6) and the
 * upload clears the flag.  Our composer blits into ALREADY-allocated cells
 * (typewriter tails, pool reuse), which the engine never re-arms for — those
 * pixels would sit in staging forever.  After any blit we re-arm exactly the
 * way CacheGlyph does. */
#define CTX_DIRTY (*(volatile u16 *)(RM_GLYPH_CACHE_CTX + 6))
#define FRAME_COUNTER (*(volatile u32 *)RM_FRAME_COUNTER)
typedef void (*dladd_fn)(u32 fnptr, int type);
#define DLAdd ((dladd_fn)(RM_DisplayList_Add | 1))
static void arm_upload(void)
{
    if (CTX_DIRTY == 0)
    {
        DLAdd(RM_Font_UploadGlyphSpriteTiles | 1, 1);
        CTX_DIRTY = 1;
    }
}

static inline int is_eng(u16 t) { return t >= RM_ENG_LO && t < RM_ENG_HI; }

static void emit_cell(int cell, u16 x, s16 y, int flag)
{
    s16 tile = (s16)(CTX_BASE + ((cell >> 4) << 6) + ((cell & 15) << 1));
    Emit(TMPL, 0, flag, 0, tile, x, y);
}

/* OR-blit a w-px slice of `tok` (source columns sx..sx+w-1) into cache cell
 * `cell` at pixel offset dx (engine staging canvas is 32 tiles = 256px wide;
 * cells map 2D: col=(cell&15)*16 px, row=(cell>>4)*16 px). */
static void blit_slice(u16 tok, int cell, int dx, int sx, int w)
{
    Blit(GetBmp(tok), STAGING, sx, 0, ((cell & 15) << 4) + dx, (cell >> 4) << 4,
         w, 16, 0);
    arm_upload();
}

/* Zero a cache cell's 16x16 px in the staging canvas (32 tiles wide, 4bpp:
 * cell = 2x2 tiles of 32 bytes). */
static void clear_cell(int cell)
{
    u32 *cv = (u32 *)RM_GLYPH_STAGING;
    int tx = (cell & 15) << 1, ty = (cell >> 4) << 1, r, t;
    for (r = 0; r < 2; r++)
        for (t = 0; t < 2; t++)
        {
            u32 *p = cv + ((((ty + r) << 5) + tx + t) << 3);
            p[0] = p[1] = p[2] = p[3] = p[4] = p[5] = p[6] = p[7] = 0;
        }
    arm_upload();
}

static void reset_state(void)
{
    int i;
    for (i = 0; i < MAXREC; i++)
        S.chunk[i] = 0;
    for (i = 0; i < MAXREC2; i++)
        S.chunk2[i] = 0;
    S.poolN = 0;
    S.poolCur = 0;
}

/* A rewind re-appended different tokens over existing record indexes: both
 * lists' compositions are stale.  Drop the chunks and reuse the pool from the
 * top — cells are re-cleared at take_cell time, the engine cache never grows. */
static void recompose(void)
{
    int i;
    for (i = 0; i < MAXREC; i++)
        S.chunk[i] = 0;
    for (i = 0; i < MAXREC2; i++)
        S.chunk2[i] = 0;
    S.poolCur = 0;
}

/* Lowest cell index we own (cells are allocated in increasing order, so this is
 * the allocation floor of our composition).  NCELLS+1 sentinel when empty. */
static int pool_min(void)
{
    int i, m = NCELLS + 1;
    for (i = 0; i < S.poolN; i++)
        if (S.pool[i] < m)
            m = S.pool[i];
    return m;
}

/* One past the highest cell we own.  poolHigh - poolN = HOLES (cells in our span
 * not owned by us): a fragmented pool wastes them and pushes the reclaim ceiling
 * toward the cache cap. */
static int pool_high(void)
{
    int i, m = 0;
    for (i = 0; i < S.poolN; i++)
        if (S.pool[i] + 1 > m)
            m = S.pool[i] + 1;
    return m;
}

/* The engine glyph cache was rewound under us (CTX_COUNT dropped) but our cells
 * still sit ABOVE the allocation high-water — nothing re-cached into them, so the
 * tiles they point at still hold last frame's composition.  Re-own them (re-tag
 * SENTINEL + push CTX_COUNT past them) and KEEP the composition; render_list then
 * re-EMITS via its chunk[i]!=0 path instead of re-blitting the whole page. */
static void reclaim_pool(void)
{
    int i, hi = 0;
    for (i = 0; i < S.poolN; i++)
    {
        int c = S.pool[i];
        CTX_CODES[c] = SENTINEL;
        if (c + 1 > hi)
            hi = c + 1;
    }
    if ((int)CTX_COUNT < hi)
        CTX_COUNT = (u16)hi;
}

/* The window was DISMISSED (no records for a couple of frames) but our pool cells
 * are still allocated in the engine glyph cache, holding CTX_COUNT high.  That stale
 * count is poison to the OTHER consumer of the same OBJ glyph-cache region: cave_runtext
 * derives its first usable cache row from ceil(CTX_COUNT/16), so a 39-cell leftover (the
 * gym Okamoto dialogue) pinned floorRow=3 and left the 3-line save-overwrite confirm one
 * row to thrash in -> rows 1 & 3 flickered.  Release the pool: free our cells' code tags
 * and drop CTX_COUNT back to our allocation floor so the engine cache reports its true
 * baseline.  Conservative: only lower the count when our pool is the contiguous TOP block
 * of the cache (nothing foreign sits in or above our span) — else just drop the chunk
 * bookkeeping and let the engine's own reset reclaim the cells. */
static void release_pool(void)
{
    int lo, hi, c;
    if (S.poolN == 0)
        return;
    lo = pool_min();
    hi = pool_high();
    if (hi == (int)CTX_COUNT)
    { /* we own the top of the cache */
        for (c = lo; c < hi; c++)
            if (CTX_CODES[c] != SENTINEL && CTX_CODES[c] != 0)
                goto drop; /* foreign glyph */
        for (c = lo; c < hi; c++)
            CTX_CODES[c] = 0; /* free our cells */
        CTX_COUNT = (u16)lo;  /* drop the high-water */
    }
drop:
    reset_state();
}

/* On screens that fully redraw every frame (the demon-dictionary lore) the glyph
 * cache is rewound EVERY frame, but our long composition is not actually lost.
 * Reclaim it (skip the re-blit) when our cells survived intact (lowest still above
 * the allocation high-water) AND the pool is COMPACT (few holes — else the reclaim
 * ceiling creeps to the 56-cell cap and starves DrawEx -> garbage; recompact via
 * reset_state, which recomposes contiguously).  Anything else drops the pool: a
 * frame gap (screen transition) or our lowest cell having been re-cached into.
 * Worst case degrades to the old re-blit, never to corruption. */
static void manage_glyph_pool(void)
{
    if (CTX_COUNT < S.watermark)
    {
        u16 frame = (u16)FRAME_COUNTER;
        if (COUNT > 0 /* window still alive (don't resurrect a
                       * DISMISSED composition onto the next
                       * screen — that re-inflated CTX_COUNT and
                       * starved cave_runtext's save confirm) */
            && (u16)(frame - S.lastFrame) == 1 && S.poolN > 0 && pool_min() >= (int)CTX_COUNT && pool_high() - (int)S.poolN <= 4)
            reclaim_pool();
        else
            reset_state();
    }
}

/* SHARED-CACHE integrity check.  cave_runtext (battle/menu sprite text) and the engine's own
 * stock glyph draws live in the SAME OBJ glyph cache we allocate from, but cave_runtext writes
 * its rows WITHOUT bumping CTX_COUNT.  A window transition (TALK -> stance choice) rewinds
 * CTX_COUNT under us; afterwards CacheGlyph re-hands cells we already own (duplicate pool
 * indices) and/or the engine re-caches a real glyph into one of our cells (its code tag stops
 * being our SENTINEL).  Either way our LOW cells are clobbered -> the prompt corrupts at its
 * START (it owns the lowest cells; the options sit higher and survive — the live symptom).
 * Detect it so cave_entry can drop the pool: render_list then recomposes fresh, allocating
 * ABOVE the engine's now-occupied low cells instead of fighting over them. */
static int pool_corrupted(void)
{
    int i, j;
    for (i = 0; i < S.poolN; i++)
    {
        int c = S.pool[i];
        if (CTX_CODES[c] != SENTINEL)
            return 1; /* engine re-cached a glyph (or reset the tag) in our cell */
        for (j = i + 1; j < S.poolN; j++)
            if (S.pool[j] == c)
                return 1; /* the same cell owned by two records */
    }
    return 0;
}

/* Take the next owned cell (cleared, SENTINEL-tagged), growing the pool via
 * the engine allocator when the composition outruns it.  -1 = cache full. */
static int take_cell(void)
{
    int cell;
    if (S.poolCur < S.poolN)
    {
        cell = S.pool[S.poolCur];
        clear_cell(cell);
    }
    else
    {
        if (S.poolN >= NCELLS)
            return -1;
        cell = CacheGlyph(0x00BC); /* any code; expansion cleared below */
        if (cell < 0 || cell >= NCELLS)
            return -1;
        /* SHARED-CACHE guard: cave_runtext writes its strip rows into THIS same OBJ glyph
         * cache without bumping CTX_COUNT, so after a window-transition rewind CacheGlyph can
         * re-hand a cell we already own.  Owning it twice maps two glyph records onto one cell
         * (the prompt's colliding indexes -> "How wi" garble).  Reject the duplicate: a single
         * stock-drawn glyph (render_list's cellA<0 fallback) is harmless; a shared cell is not. */
        {
            int k;
            for (k = 0; k < S.poolN; k++)
                if (S.pool[k] == (u8)cell)
                    return -1;
        }
        CTX_CODES[cell] = SENTINEL; /* never a bare lookup hit */
        clear_cell(cell);           /* drop the engine's pre-expansion */
        S.pool[S.poolN++] = (u8)cell;
    }
    S.poolCur++;
    return cell;
}

/* Mirror the STATIC template-strip tiles (cells 56..63: shop price digits,
 * cursor furniture — uploaded to VRAM once at screen init, NOT cache-managed)
 * from VRAM back into the staging canvas.  The per-frame staging->VRAM upload
 * covers ceil(count/16) cell-rows; once count crosses 48 it sweeps cell row 3
 * and would replace those tiles with empty staging.  With the mirror in place
 * the extension uploads the same pixels back — an identity write. */
static void preserve_tail(void)
{
    int c, r, t, k;
    for (c = 56; c < 64; c++)
    {
        int tx = (c & 15) << 1, ty = (c >> 4) << 1;
        for (r = 0; r < 2; r++)
            for (t = 0; t < 2; t++)
            {
                u32 *dst = (u32 *)RM_GLYPH_STAGING + ((((ty + r) << 5) + tx + t) << 3);
                const u32 *src = (const u32 *)(0x06010000u + (((u32)CTX_BASE + ((c >> 4) << 6) + ((c & 15) << 1) + (r << 5) + t) << 5));
                for (k = 0; k < 8; k++)
                    dst[k] = src[k];
            }
    }
}

/* Expand a name MARKER into a VWF strip at the record's column anchor `ax`, PAIR-packing
 * into the row's 8 chunk slots (i..i+7).  Two markers share this: the shop item-list name
 * (ITEM_TABLE[id], patch_shopname) and the negotiation demon name (NAME_TABLE[id],
 * cave_negoname).  v1 pair logic, verified live for the shop list — including the in-place
 * cell reuse on content change (shop scrolls rewrite the records without a cache reset).
 * The caller re-anchors the run state before calling, so the following record (the item
 * price column, or the negotiation message's particle) starts a fresh run.
 * Returns the screen x just past the drawn name (= ax + the name's real VWF width), so the
 * demon-name caller can close the following run up against it (VWF spacing) instead of the
 * fixed 8-slot field. */
static u16 expand_name_marker(const u16 *nm, u16 ax, s16 ya, u16 fa,
                              int i, u32 *chunk, s16 clip)
{
    u16 x = ax, a;
    int slot = i, lim = i + 8;
    if (ya < clip || !nm)
        return ax;
    while ((a = *nm) != 0x0301 && a != 0 && slot < lim)
    {
        u16 b = 0, wa;
        u32 cc;
        int cl;
        nm++;
        wa = (a < 0x1300) ? WIDTH[a] : 13;
        if (!is_eng(a))
        { /* stray non-EN: stock draw */
            DrawEx(a, 0, 0, x, ya, fa);
            x += wa;
            continue;
        }
        if (is_eng(*nm) && (int)wa + WIDTH[*nm] + 1 < 16)
        {
            b = *nm;
            nm++;
        }
        cc = chunk[slot];
        cl = P_CELL(cc);
        if (cl < 0 || P_TOKA(cc) != a || (((cc & CH_HASB) != 0) != (b != 0)) || (b && P_TOKB(cc) != b))
        { /* rebuild on any change */
            if (cl >= 0 && cl < NCELLS && CTX_CODES[cl] == SENTINEL)
            {
                clear_cell(cl); /* reuse this slot's own cell */
            }
            else
            {
                cl = take_cell();
                if (cl < 0)
                { /* cache full: stock fallback */
                    DrawEx(a, 0, 0, x, ya, fa);
                    if (b)
                        DrawEx(b, 0, 0, (u16)(x + wa), ya, fa);
                    x += wa + (b ? WIDTH[b] : 0);
                    slot++;
                    continue;
                }
            }
            blit_slice(a, cl, 0, 0, 16);
            cc = P_MAKE(cl, a);
            if (b)
            {
                blit_slice(b, cl, wa, 0, 16 - wa);
                cc |= CH_HASB | ((u32)b << 19);
            }
            chunk[slot] = cc;
        }
        emit_cell(cl, x, ya, fa);
        x += wa + (b ? WIDTH[b] : 0);
        slot++;
    }
    return x;
}

/* Render one record list (the message window's, or the shop LIST window's).
 * `chunk` = the per-record-index slots backing this list. */
static void render_list(volatile Rec *recs, int n, u32 *chunk, s16 clip)
{
    int i;
    /* ---- VWF reflow state ----
     * Every appender (RunStep prose, the choice re-append, the menu label
     * renderer, the shop/cost list builders) assigns x on the 13px JP grid.
     * Contiguous records on one row whose appender x steps by exactly 13 form
     * a RUN: the run's first record anchors at its appender x (indents and
     * right-aligned columns keep their positions) and the rest advance by the
     * VWF width table — which holds 13 for every JP glyph, so JP pages render
     * byte-identically, while EN half-width text closes up.  Any column jump
     * or row change re-anchors (an appender that doesn't step 13 degrades to
     * stock positioning, never corrupts). */
    s16 run_y = -0x7fff;
    u16 run_ax = 0xffff, cur_x = 0;
    /* ---- strip segment state (contiguous EN records of one run) ----
     * A glyph can only touch the strip's top TWO slices (px never moves
     * backwards, and one glyph spans at most one boundary), so the cells of
     * the two highest slices are tracked: s1 = the tail, s0 = the one below
     * (a glyph whose predecessor spilled usually STARTS in s0). */
    int seg_on = 0; /* a strip segment is open */
    u16 seg_x0 = 0; /* screen x of the segment origin */
    s16 seg_y = 0;
    int seg_s1 = -1;   /* tail slice index */
    int seg_c1 = -1;   /* tail slice's cell */
    int seg_c0 = -1;   /* cell of slice seg_s1-1 (-1 = none) */
    int seg_emit = -1; /* highest slice index emitted this frame */

    for (i = 0; i < n;)
    {
        u16 ta = recs[i].tok, ax = recs[i].x, fa = recs[i].flag;
        s16 ya = (s16)recs[i].y;
        u16 xa, adv;
        u32 c;
        int cont, p, sliceA, dxA, inkw, spill, cellA, cellB;
        if (ta == 0)
        {
            i++;
            continue;
        } /* cleared slot: no draw, no advance */
        if (ta >= 0xF000u)
        {
            /* name MARKER -> VWF strip.  Two disjoint marker namespaces share the
             * expander: shop item-list name 0xF000|id (id < ITEM_COUNT 0x15A,
             * ITEM_TABLE, patch_shopname) and negotiation demon name 0xF800|id
             * (id < NAME_COUNT 0x17C, NAME_TABLE, cave_negoname).  The demon name is
             * length-flexible: the JP layout reserves an 8-slot (104px) name field,
             * so an EN VWF name up to ~16 glyphs fits before the following particle
             * (the 7 trailing 0x70 pad records draw blank).  Any other 0xF000+ token
             * is not a glyph (glyphs end ~0x1300) -> skip. */
            const u16 *nm;
            int is_demon = 0;
            u16 nx;
            u32 iid = (u32)(ta - 0xF000u);
            if (iid < RM_ITEM_COUNT)
                nm = *(const u16 *const *)(RM_ITEM_TABLE + (iid << 2));
            else if (ta >= RM_NEGO_NAME_MARKER && (u32)(ta - RM_NEGO_NAME_MARKER) < RM_NAME_COUNT)
            {
                nm = *(const u16 *const *)(RM_NAME_TABLE + ((u32)(ta - RM_NEGO_NAME_MARKER) << 2));
                is_demon = 1;
            }
            else
            {
                i++;
                continue;
            }
            seg_on = 0;
            nx = expand_name_marker(nm, ax, ya, fa, i, chunk, clip);
            if (is_demon)
            {
                /* VWF the demon name: drop the trailing 0x70 pad records of the fixed
                 * 8-slot field and let the following particle reflow tight against the
                 * real name end -> proper spacing, no JP fixed-field gap.  Continuation
                 * is same-row only (run_ax = the next real record's x); a name on its
                 * own line leaves a row change, so that particle re-anchors normally. */
                int j = i + 1;
                while (j < n && recs[j].tok == 0x70)
                    j++;
                run_y = ya;
                cur_x = nx;
                run_ax = (j < n) ? recs[j].x : 0xffff;
                i = j;
            }
            else
            {
                /* shop item name: the right-aligned price column follows -> keep its position */
                run_y = ya;
                run_ax = 0xffff;
                cur_x = ax;
                i++;
            }
            continue;
        }
        /* Run continuation, two appender flavours:
         *   ax == run_ax  — 13px-grid appenders (choice re-append, menu label
         *                   renderer, shop/cost builders): we reflow.
         *   ax == cur_x   — the PROSE appender, which patch_vwf made a pixel
         *                   accumulator long ago: records arrive PRE-reflowed
         *                   with the same width table, so its x equals our
         *                   running x exactly.  (Missing this was the v1/v2
         *                   garble root cause: EN prose never packed — one
         *                   cell per glyph — and 4-line pages blew the cache.)
         * Both branches yield the same xa when ax == cur_x, so a coincidental
         * match of a re-anchored column is harmless. */
        cont = (ya == run_y && (ax == run_ax || ax == cur_x));
        if (cont)
            xa = cur_x; /* run continues: reflowed x */
        else
            xa = ax; /* re-anchor at appender x */
        adv = (ta < 0x1300) ? WIDTH[ta] : 13;
        run_y = ya;
        run_ax = ax + 13;
        cur_x = xa + adv;
        if (ta == 0x3f || ya < clip)
        {
            seg_on = 0;
            i++;
            continue;
        } /* JP space / clipped */
        if (!is_eng(ta))
        { /* JP / full-width: stock path */
            DrawEx(ta, 0, 0, xa, ya, fa);
            seg_on = 0;
            i++;
            continue;
        }

        /* ---- strip composer (EN records) ---- */
        if (!seg_on || ya != seg_y || !cont)
        {
            /* open a segment at this glyph's reflowed x (row change, first EN
             * glyph after JP/marker/clip/fallback, or a re-anchored column) */
            seg_on = 1;
            seg_x0 = xa;
            seg_y = ya;
            seg_s1 = -1;
            seg_c1 = -1;
            seg_c0 = -1;
            seg_emit = -1;
        }
        if (ta == RM_ENG_LO)
        { /* space: px only, no cell/blit
           * (cur_x already advanced; a
           * space never closes the seg) */
            if (chunk[i] != 0)
            { /* rewind put a space over a letter */
                recompose();
                i = 0;
                run_y = -0x7fff;
                run_ax = 0xffff;
                cur_x = 0;
                seg_on = 0;
                continue;
            }
            i++;
            continue;
        }
        p = (int)xa - (int)seg_x0; /* segment-relative px (>= 0) */
        sliceA = p >> 4;
        dxA = p & 15;
        inkw = (int)adv + 3; /* bearing(2) + ink + 1px pad */
        if (inkw > 16)
            inkw = 16;
        spill = (dxA + inkw > 16);

        c = chunk[i];
        if (c != 0 && (CH_TOK(c) != ta || (int)CH_DXA(c) != dxA))
        {
            /* a rewind re-appended different content at this index: stale.
             * Recompose both lists from a clean slate (same pool cells). */
            recompose();
            i = 0;
            run_y = -0x7fff;
            run_ax = 0xffff;
            cur_x = 0;
            seg_on = 0;
            continue;
        }
        if (c != 0 && CH_ISFB(c))
        { /* stock-drawn record (composed as
           * fallback): stays stock */
            DrawEx(ta, 0, 0, xa, ya, fa);
            seg_on = 0;
            i++;
            continue;
        }
        if (c == 0)
        { /* compose this glyph */
            if (sliceA == seg_s1)
                cellA = seg_c1; /* tail slice */
            else if (sliceA == seg_s1 - 1)
                cellA = seg_c0; /* below the tail
                                 * (predecessor spilled) */
            else
                cellA = take_cell(); /* new slice */
            cellB = -1;
            if (cellA >= 0 && spill)
            {
                /* spill target = slice sliceA+1.  It may already have a cell
                 * (the tail), else take a fresh one.  Either way the single
                 * blit needs canvas adjacency (cellB == cellA+1) — source-
                 * rect splits are not nibble-safe (see header). */
                if (sliceA + 1 == seg_s1)
                    cellB = seg_c1;
                else if ((cellA & 15) != 15)
                {
                    cellB = take_cell();
                    if (cellB < 0)
                        cellB = -2;
                }
                else
                    cellB = -2;
                if (cellB >= 0 && cellB != cellA + 1)
                    cellB = -2;
            }
            if (cellA < 0 || cellB == -2)
            { /* cache full / no adjacency: stock */
                chunk[i] = CH_FBMARK | ((u32)dxA << 15) | ((u32)ta << 19);
                DrawEx(ta, 0, 0, xa, ya, fa);
                seg_on = 0;
                i++;
                continue;
            }
            blit_slice(ta, cellA, dxA, 0, inkw); /* flows into cellA+1 when spilled */
            c = ((u32)(cellA + 1) & 0xff) | (((u32)(cellB + 1) & 0x7f) << 8) | ((u32)dxA << 15) | ((u32)ta << 19) | (spill ? CH_HASB : 0u);
            chunk[i] = c;
        }
        else
        {
            cellA = CH_CELLA(c);
            cellB = (c & CH_HASB) ? CH_CELLB(c) : -1;
        }
        /* emit each slice once per frame, on first touch */
        if (sliceA > seg_emit)
        {
            emit_cell(cellA, (u16)(seg_x0 + (sliceA << 4)), ya, fa);
            seg_emit = sliceA;
        }
        if (cellB >= 0 && sliceA + 1 > seg_emit)
        {
            emit_cell(cellB, (u16)(seg_x0 + ((sliceA + 1) << 4)), ya, fa);
            seg_emit = sliceA + 1;
        }
        /* walk bookkeeping: keep the top-two slice cells current */
        if (cellB >= 0 && sliceA + 1 > seg_s1)
        {
            seg_c0 = cellA;
            seg_c1 = cellB;
            seg_s1 = sliceA + 1;
        }
        else if (sliceA > seg_s1)
        {
            seg_c0 = (sliceA == seg_s1 + 1) ? seg_c1 : -1;
            seg_c1 = cellA;
            seg_s1 = sliceA;
        }
        i++;
    }
}

/* Dialogue/negotiation/tutorial/lore all render via render_list (the strip).  The per-glyph fork
 * (try_per_glyph) and its OAM-headroom test were removed 2026-06-17 along with cave_runtext's:
 * keeping ALL text on one renderer avoids the shared-OBJ-glyph-cache collisions a mixed
 * per-glyph/strip frame produced (the DDS exchange scroll garble).  marker_name went with it
 * (render_list resolves markers inline). */

void cave_entry(void) /* message-window list (loop 1 hook) */
{
    int n = COUNT;
    if (CTX_CAP > NCELLS)
        CTX_CAP = NCELLS; /* keep our compose room reserved */
    /* Window dismissed?  Release our glyph-cache pool so the next consumer of the shared
     * OBJ cache (cave_runtext's save-overwrite confirm) sees the true CTX_COUNT, not our
     * leftover.  Debounced 2 frames so a one-frame inter-page record clear doesn't drop a
     * live dialogue; guarded on COUNT2==0 so an active shop list (shares the pool) is safe. */
    if (n == 0 && COUNT2 == 0)
    {
        if (++S.emptyRun >= 2)
        {
            release_pool();
            S.emptyRun = 2;
        }
        S.lastFrame = (u16)FRAME_COUNTER;
        S.watermark = CTX_COUNT;
        return;
    }
    S.emptyRun = 0;
    manage_glyph_pool(); /* reclaim cells across a per-frame cache rewind */
    if (pool_corrupted())
        reset_state(); /* cave_runtext/engine clobbered our low cells (battle negotiation) */
    if (n > MAXREC)
        n = MAXREC;
    /* ALL text strips (the per-glyph fork was removed 2026-06-17 — see cave_runtext.c): dialogue,
     * story, negotiation and lore all render via the strip, the same renderer as the shop list. */
    render_list(RECS, n, S.chunk, CLIPY);
    /* Preserve the static template strip (cells 56-63: shop price digits, cursor
     * furniture) ONLY when render_list armed an upload THIS frame (CTX_DIRTY) AND that
     * upload reaches cell row 3 (count > 48 => ceil(count/16) >= 4 rows).  A fully-
     * revealed static page is all cache HITs -> nothing dirty -> the 256-word VRAM->
     * staging copy is skipped entirely; before, it ran EVERY frame (even with the window
     * closed and on every dialogue/negotiation frame, which has no strip to protect).
     * Safe to run after render_list: it touches cells 56-63 only, render_list touches
     * <=55, and the deferred staging->VRAM upload doesn't run until frame end. */
    if (CTX_DIRTY && CTX_COUNT > 48)
        preserve_tail();
    S.lastFrame = (u16)FRAME_COUNTER;
    S.watermark = CTX_COUNT;
}

void cave_entry2(void) /* shop LIST-window records (loop 2 hook) */
{
    int n = COUNT2;
    manage_glyph_pool(); /* entry2 can run on frames entry skips */
    if (pool_corrupted())
        reset_state();
    if (n > MAXREC2)
        n = MAXREC2;
    if (n > 0)
        render_list(RECS2, n, S.chunk2, (s16)-0x7fff); /* the list window never clips */
    S.lastFrame = (u16)FRAME_COUNTER;
    S.watermark = CTX_COUNT;
}
