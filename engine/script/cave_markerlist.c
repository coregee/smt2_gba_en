/* cave_markerlist.c — render the ENTIRE automap marker screen through one position-keyed
 * VWF strip renderer, so cell assignments are STABLE (no flicker on menu transitions).
 *
 * cave_runtext packs strips in CALL ORDER (a width-based bump allocator), so when a caption
 * changes width (scrolling marker types) or the drawn set changes (state transition), the
 * following strips' cells shift — the brief "jumbled" flicker on the top lines.  Here every
 * marker text element is instead mapped to a FIXED cell chunk by its SCREEN Y (its identity),
 * and re-emitted every frame from content-cached cells.  Independent of call order / content
 * width => rock stable, and
 * with nothing on this screen touching cave_runtext there's no inter-renderer conflict.
 *
 * Fixed chunk map (the screen's 7 text rows; cells in the 384-639 glyph-sprite region):
 *   y~4   caption line 1   -> cells 0..7    (row0 cols0-7)
 *   y~16  caption line 2   -> cells 8..15   (row0 cols8-15)
 *   y~89  prompt / header  -> cells 16..31  (row1, full 256px — prompts run long)
 *   y~105 slot 0           -> cells 32..39  (row2 cols0-7)
 *   y~117 slot 1           -> cells 40..47  (row2 cols8-15)
 *   y~129 slot 2           -> cells 48..55  (row3 cols0-7)
 *   y~141 slot 3           -> cells 56..63  (row3 cols8-15)
 * (location/"(No data)" names are <=117px <=8 cells; prompt/header gets a full 16-cell row.)
 *
 * cave_init still zeroes cave_runtext's cache magic each frame: not for this screen (we don't
 * use cave_runtext here), but so the FIELD's cave_runtext re-renders on exit — our direct DMA
 * clobbered its glyph cells, and a stale HIT would otherwise leave field text garbled.
 *
 * THE "(No data)" FLASH ON OPEN (root-caused 2026-06-19 via tools/bizhawk_probe_markerflicker.lua):
 * the previous screen (the automap) and this one use DIFFERENT OBJ glyph-cache bases — automap
 * 0x180, marker 0x100.  The automap's location-banner sprite (OAM[0], y=89, tile = 0x180+0x40 =
 * 0x1C0) lingers in HARDWARE OAM for ~2 frames after A is pressed (the per-frame OAM_ListReset
 * zeroes the sprite COUNT, so nothing re-emits it, and the flush doesn't clear that slot), while the
 * new screen has already painted its SLOT 2 into that same tile (marker 0x100+0xC0 = 0x1C0).  An
 * empty slot 2 = "(No data)", so the stale banner sprite shows "(No data)" on the location line.
 * Fix: record the real entry frame and stage marker-text VRAM writes across three logical frames.
 * The drawer transition stalls on its second logical frame while completing several video frames,
 * then still owns the shared tiles on the third; a two-frame all-or-nothing barrier released every
 * row together.  Phases 0-1 re-emit the old automap banner from its untouched 0x1C0 tiles.  Phase 2
 * moves only the header to its marker tiles after the party panel is gone.  Phase 3 permits slot 2
 * to reuse 0x1C0, after no location sprite points there.  The location window therefore stays
 * visible without exposing either shared range during its unsafe phase.
 * cave_entry's steady-state cache is keyed by both content and OBJ base because the automap and
 * marker screens use different bases.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

#include "rommap.h"
#include "cave_glyph.h"   /* shared: ST_GetBmp/ST_Blit/ST_Emit, ST_TMPL32, st_gw */

#define OBJ_VRAM 0x06010000u
#define CTX_BASE (*(volatile u16 *)(RM_GLYPH_CACHE_CTX + 0))   /* +0 = base OBJ tile (384) */
#define DMA3SAD (*(volatile u32 *)0x040000D4)
#define DMA3DAD (*(volatile u32 *)0x040000D8)
#define DMA3CNT (*(volatile u32 *)0x040000DC)
#define PAD_TOK 0x57u
#define INK_OVERHANG 2
#define PITCH 0xc
#define AUTOMAP_BANNER_TILE 0x1c0u

/* current-location coord globals read by the stock header drawer 0x080c8b7c */
#define LOC_A (*(volatile u16 *)0x03004614)
#define LOC_B (*(volatile u16 *)0x03004514)
#define LOC_C (*(volatile u16 *)(0x03004550 + 0x12))
#define LOC_D (*(volatile u16 *)(0x03004550 + 0x14))

/* Glyph blit/emit/width primitives + the 32x16 template come from cave_glyph.h (ST_GetBmp/ST_Blit/
 * ST_Emit/ST_TMPL32/st_gw).  GetCell (coords -> location-table name cell) is marker-screen-specific. */
typedef u16 *(*cell_fn)(u32 a, u32 b, u32 c, u32 d);
#define GetCell ((cell_fn)(RM_Location_GetNameCellFromCoords | 1))
#define gw(g)   st_gw((g), PITCH)   /* markerlist draws at the fixed 0xc pitch */

/* screen-Y -> fixed flat cell index (start of this row's chunk) */
static int chunk_start(int y)
{
    if (y < 12)  return 0;       /* caption line 1 */
    if (y < 50)  return 8;       /* caption line 2 */
    if (y < 100) return 16;      /* prompt / header */
    if (y < 111) return 32;      /* slot 0 */
    if (y < 123) return 40;      /* slot 1 */
    if (y < 135) return 48;      /* slot 2 */
    return 56;                   /* slot 3 */
}
/* prompt/header row gets a full 16-cell row (prompts run long); others 8 cells (128px). */
static int chunk_size(int y) { return (y >= 50 && y < 100) ? 16 : 8; }

/* Render one line into its fixed cell chunk (by screen Y), every frame.  `minCell` is a
 * floor on the chunk: slot rows pass 32 so a transient Y (e.g. during the open handoff)
 * can never push a slot into the banner/caption chunks (0..31) and flash there.  `grp`
 * (p2, the OAM Z-order group) and `prio` are passed through to EmitSprite so each element
 * keeps the layer the stock draw used (captions/prompts on group 0; list/header on 1) —
 * hardcoding put text on the wrong layer and the grid/crosshair drew over it. */
/* Per-chunk content cache (skip the expensive clear+blit+DMA when a row's text is
 * unchanged — the screen is static most frames; re-blitting every frame is what made the
 * marker menu lag).  cache[0] = lastFrame (frame-gap invalidation on re-enter, set by
 * cave_init); cache[1 + (cs>>3)] = the content hash currently in that chunk's cells.  Cells
 * are FIXED per chunk, so a HIT just re-emits sprites over the still-valid VRAM. */
#define MCACHE ((volatile u32 *)RM_MARKER_CACHE)

static int transition_phase(void)
{
    u32 frame = *(volatile u32 *)0x030031bcu;
    u32 phase;
    if (MCACHE[0] != frame) return -1;
    phase = (u32)(frame - MCACHE[9]);
    return phase < 3u ? (int)phase : -1;
}

/* Keep the location window alive during the no-write handoff.  The automap rendered the same
 * location string into 0x1C0 immediately before entry; only its OAM entry was dropped.  Re-emitting
 * the exact number of covering sprites is safe, while re-blitting either shared tile range is not. */
static void emit_transition_header(const u16 *str, int x, int y, u32 grp, u32 prio)
{
    const u16 *p;
    s16 px = 0;
    u16 cells, j;

    for (p = str; *p; ++p) px += gw(*p);
    cells = (u16)((px + INK_OVERHANG + 15) >> 4);
    cells = (u16)((cells + 1) & ~1u);
    if (cells > 16u) cells = 16u;
    for (j = 0; j < (u16)(cells >> 1); ++j)
        ST_Emit(ST_TMPL32, grp, 0, prio, (s16)(AUTOMAP_BANNER_TILE + j * 4),
                (u16)(x + j * 32), (s16)y);
}

static u16 render_marker(const u16 *str, int x, int y, int minCell,
                         u32 grp, u32 prio, int headerTakeover)
{
    const u16 *p;
    s16 px = 0;
    int i, cs, maxc, idx;
    u16 base, tileTL, cells, words, j, nspr, col;
    u32 h = 2166136261u;

    if (str[0] == 0) return 0;
    /* The marker header/slot rows alias location and HP/MP tiles that the previous screen still
     * displays during the drawer handoff.  cave_entry preserves the old banner separately. */
    if (transition_phase() >= 0 && !headerTakeover) return 0;
    cs   = chunk_start(y);
    if (cs < minCell) cs = minCell;             /* slot rows (minCell=32) never map below their region */
    maxc = chunk_size(y);
    if (maxc > 16 - (cs & 15)) maxc = 16 - (cs & 15);   /* never spill into the next row */

    /* measure width + hash content (cheap: no glyph blits) */
    for (p = str; *p; ++p) { px += gw(*p); h = (h ^ *p) * 16777619u; }
    h = (h ^ (u32)cs) * 16777619u;               /* fold chunk identity (moved string re-renders) */
    base = (u16)(CTX_BASE & 0x7ff);
    h = (h ^ (u32)base) * 16777619u;             /* automap/marker use different OBJ tile bases */
    h = h ? h : 1u;

    cells = (u16)((px + INK_OVERHANG + 15) >> 4);
    cells = (u16)((cells + 1) & ~1u);            /* even (32x16 pairs) */
    if (cells > (u16)maxc) cells = (u16)maxc;    /* clamp to the chunk -> never a neighbour */
    if (cells == 0) return 0;

    col    = (u16)(cs & 15);
    tileTL = (u16)(base + (cs >> 4) * 0x40 + col * 2);

    idx = (cs >> 3) + 1;                          /* cache slot (cs/8 + 1; [0] is lastFrame) */
    if (MCACHE[idx] != h) {                       /* MISS: re-blit this chunk to VRAM */
        u32 scratch[0x800 / 4];
        MCACHE[idx] = h;
        words = (u16)(cells * 0x10);
        /* Only the cells DMA'd below need clearing.  Most marker rows use <=8 cells;
         * clearing all 0x800 bytes for every row made the opening transition needlessly slow. */
        for (i = 0; i < (int)words; ++i) {
            scratch[i] = 0;
            scratch[0x100 + i] = 0;
        }
        px = 0;
        for (p = str; *p; ++p) {
            if (px > 240) break;
            ST_Blit(ST_GetBmp(*p), scratch, 0, 0, px, 0, 16, 16, 0);
            px += gw(*p);
        }
        DMA3SAD = (u32)scratch;          DMA3DAD = OBJ_VRAM + (u32)tileTL * 0x20;
        DMA3CNT = words | 0x84000000u; (void)DMA3CNT;
        DMA3SAD = (u32)scratch + 0x400;  DMA3DAD = OBJ_VRAM + (u32)(tileTL + 32) * 0x20;
        DMA3CNT = words | 0x84000000u; (void)DMA3CNT;
    }

    nspr = (u16)(cells >> 1);                     /* sprites emitted every frame (cheap) */
    for (j = 0; j < nspr; ++j)
        ST_Emit(ST_TMPL32, grp, 0, prio, (s16)(tileTL + j * 4), (u16)(x + j * 32), (s16)y);
    return cells;
}

/* Copy a location-table cell's tokens up to the 0x57 pad / terminator.  Cap 31 = the wider
 * 0x40 far-table's usable length (patch_savevwf cap-lift); was 16 for the old 0x20 cells, which
 * truncated long EN names ("Valhalla Terminal" -> "Valhalla Termina").  The header chunk is a
 * full 16-cell / 256px row, so it fits ~31 half-width glyphs; slot rows clamp to their 8-cell
 * width in render_marker. */
static void copy_cell(const u16 *cell, u16 *buf)
{
    int k;
    for (k = 0; k < 31 && cell[k] && cell[k] != PAD_TOK; k++) buf[k] = cell[k];
    buf[k] = 0;
}

/* current-location HEADER / map banner (hooks 0x080b52f0 + the 3 banner sites).
 *
 * Draw the current area's location-table cell (coords -> GetCell) into the header chunk.  The
 * content hash includes CTX_BASE, so crossing from the automap base (0x180) to the marker base
 * (0x100) causes exactly one redraw; stable frames are cache hits.
 *
 * (Was wrapped in an MCACHE[4]/[9] "freeze" that captured + re-used the cell pointer to mask the
 * "(No data)" flash — that flash is now fixed by the two-frame transition write barrier, so
 * the freeze is gone.  A plain GetCell each frame is correct: the player's coords are stable while
 * the marker screen is up, and GetCell only ever returns a location-table cell anyway.) */
__attribute__((used, section(".text.entry")))      /* must be named cave_entry: linker ENTRY */
void cave_entry(u32 a0, u32 a1, u32 startX, u32 startY, u32 pitch)
{
    u16 buf[33];   /* 31 glyphs + null (cap-lift) */
    int phase;
    (void)pitch;
    copy_cell(GetCell(LOC_A, LOC_B, LOC_C, LOC_D), buf);
    phase = transition_phase();
    if (phase >= 0 && phase < 2) {
        emit_transition_header(buf, (int)startX, (int)startY, a0, a1);
        return;
    }
    render_marker(buf, (int)startX, (int)startY, 0, a0, a1, phase == 2);
}

/* placed-marker LOCATION NAME row (hook 0x080b54f6) */
__attribute__((used))
void cave_loc(u32 f4, u32 f6, u32 f0, u32 f1,
              u32 one, u32 zero, u32 startX, u32 rowY)
{
    u16 buf[33];   /* 31 glyphs + null (cap-lift) */
    (void)one; (void)zero;
    copy_cell(GetCell(f4, f6, f0, f1), buf);
    render_marker(buf, (int)startX, (int)rowY, 32, 1, 0, 0);   /* slot row: floor at chunk 3 */
}

/* prompts / captions — replaces the prompt/caption bl Text_DrawSpriteString sites (y-keyed:
 * captions in chunks 0-1, prompts in chunk 2).  Args (AAPCS): r0=str, r1=p2, r2=p3,
 * r3=startX, [sp]=startY, [sp+4]=pitch. */
__attribute__((used))
void cave_draw(const u16 *str, u32 p2, u32 p3, u32 startX, u32 startY, u32 pitch)
{
    (void)pitch;
    render_marker(str, (int)startX, (int)startY, 0, p2, p3, 0);
}

/* empty-slot "(No data)" row — same as cave_draw but floored at chunk 3 (slot region), so
 * it can never flash in the banner/caption rows during the open handoff. */
__attribute__((used))
void cave_nodata(const u16 *str, u32 p2, u32 p3, u32 startX, u32 startY, u32 pitch)
{
    (void)pitch;
    render_marker(str, (int)startX, (int)startY, 32, p2, p3, 0);
}

/* render-handler entry (hook 0x080b52c8), once per frame.  Jobs:
 *  - frame-gap invalidate OUR per-chunk cache: keep the cache while (frame - lastFrame) <= 1,
 *    zero the 8 chunk hashes (force a full re-blit) only on a real re-enter (gap >= 2, the field
 *    ran in between and clobbered cells 384-639).  <=1 — not ==1 — because the render handler can
 *    run TWICE in one frame (2nd pass sees gap 0) and g_dwFrameCounter need not tick exactly +1
 *    per marker frame; ==1 invalidated on every such frame -> all 7 rows re-blit -> the menu lag.
 *  - zero cave_runtext's cache magic (field-on-exit safety: our direct DMA clobbered its
 *    glyph cells, so force the field to re-render rather than serve a stale HIT).
 *  - record entryFrame for the old-banner -> header-only -> full-list handoff.
 *  - restore the 2 displaced setup instrs (r6=obj, r7=obj). */
__attribute__((naked, used))
void cave_init(void)
{
    __asm__ volatile(
        "ldr  r1, =0x030031bc  \n"   /* &g_dwFrameCounter */
        "ldr  r3, [r1]         \n"   /* frame */
        "ldr  r2, =%c0         \n"   /* RM_MARKER_CACHE */
        "ldr  r1, [r2]         \n"   /* lastFrame */
        "sub  r1, r3, r1       \n"   /* frame - lastFrame */
        "cmp  r1, #1           \n"   /* <=1 -> same-frame 2nd pass (0) or next marker frame (1): keep */
        "bls  1f               \n"   /* unsigned <=: only a real re-enter (gap>=2) invalidates the cache */
        "movs r1, #0           \n"   /* re-enter: invalidate the chunk hashes */
        "str  r1, [r2, #4]     \n"
        "str  r1, [r2, #8]     \n"
        "str  r1, [r2, #0xc]   \n"
        /* offset 0x10 (idx4) has no chunk; chunk hashes are idx 1-3,5-8.  Offset 0x24
         * (idx9) stores entryFrame for the transition write barrier below. */
        "str  r1, [r2, #0x14]  \n"
        "str  r1, [r2, #0x18]  \n"
        "str  r1, [r2, #0x1c]  \n"
        "str  r1, [r2, #0x20]  \n"
        "str  r3, [r2, #0x24]  \n"   /* entryFrame for the phased marker handoff */
        "1:                    \n"
        "str  r3, [r2]         \n"   /* lastFrame = frame */
        "ldr  r1, =0x02036164  \n"   /* GLYPH_CACHE_CTX + 0x88 (cave_runtext magic) */
        "movs r3, #0           \n"
        "str  r3, [r1]         \n"
        "movs r6, r0           \n"   /* displaced: r6 = obj */
        "movs r7, r6           \n"   /* displaced: r7 = obj */
        "bx   lr               \n"
        :: "i"(RM_MARKER_CACHE)
    );
}
