/* cave_glyph.h — shared low-level glyph primitives for the OBJ sprite-text caves.
 *
 * The engine-function interface (Font_GetGlyphBitmap / Font_BlitGlyph / OAM_EmitSprite), the VWF
 * width lookup, the name-marker expansion, the run measure/hash, and the OBJ sprite templates —
 * everything the strip caves duplicated.  cave_runtext / cave_vision get these via cave_strip.h
 * (which #includes this); cave_markerlist / cave_msgwin #include it directly and keep their own
 * cell-allocation strategy (fixed Y-chunks / engine-CacheGlyph pool respectively).  Splitting these
 * out is pure dedup: NO behaviour change for the cave_strip allocator users (same symbols, same
 * code).  See memory sprite-text-running-buffer.
 *
 * The includer must typedef u8/u16/s16/u32 before #include (matches the existing cave convention).
 *
 * Scope: ONLY primitives shared by >=2 caves live here (the engine function-ptr interface, the VWF
 * width lookup st_gw, the OBJ sprite templates).  Helpers used by just ONE cave -- the strip
 * allocator's st_marker/st_measure/st_hash, msgwin's pair composer, markerlist's fixed-chunk hash --
 * stay in that cave so this header pulls no dead code into the others.
 */
#ifndef CAVE_GLYPH_H
#define CAVE_GLYPH_H

#include <rommap.h>

#define ST_WIDTH  ((const u8 *)RM_WIDTH_TABLE)                     /* VWF advance per glyph code */

typedef void *(*st_getbmp_fn)(u32 code);
typedef void  (*st_blit_fn)(void *src, void *dst, int sx, int sy, int dx, int dy,
                            int w, int h, int tint);
typedef int   (*st_emit_fn)(const u16 *tmpl, u32 p2, int palOff, u32 prio,
                            s16 tile, u16 x, s16 y);
#define ST_GetBmp ((st_getbmp_fn)(RM_Font_GetGlyphBitmap | 1))
#define ST_Blit   ((st_blit_fn)(RM_Font_BlitGlyph | 1))
#define ST_Emit   ((st_emit_fn)(RM_OAM_EmitSprite | 1))

/* 32x16 (cell pair) and 16x16 (odd boundary cell) OBJ sprite templates, 4bpp. */
static const u16 ST_TMPL32[3] = { 0x4000, 0x8000, 0x0000 };
static const u16 ST_TMPL16[3] = { 0x0000, 0x4000, 0x0000 };

/* VWF advance: an EN glyph trims to the width table; everything else (JP/full-width) takes the
 * caller's fixed grid pitch — the battle window is 12, the event window 13.  (The width table holds
 * 13 for every JP glyph too, so JP pages render byte-identically either way.) */
static inline u16 st_gw(u16 g, int pitch)
{
    return (g >= RM_ENG_LO && g < RM_ENG_HI) ? ST_WIDTH[g] : (u16)pitch;
}

#endif /* CAVE_GLYPH_H */
