typedef unsigned short u16;
typedef unsigned int   u32;

#include <rommap.h>   /* RM_* address defines, generated from rom_layout.py */

/* Battle demon-name -> a 1-u16 MARKER (the unified, length-unlimited name path).

   The battle name-copy sites used to copy the JP inline name (Combatant_GetRecord(id)+0x22) into the
   message buffer with cap-8 / fixed-length loops -> truncation ("Amateras") / garbage tails.  Instead,
   for a translated demon we return &MARKER_TABLE[id] = the 2-u16 token { 0xF000|id, 0 }.  The copy then
   emits just the 1-u16 token (it fits ANY copy loop), and the shared sprite renderer Text_DrawSpriteString
   -- consumed by patch_spritebuf -- expands 0xF000|id through NAME_TABLE and draws it VWF.
   Untranslated / boss / non-demon ids (no NAME_TABLE entry) fall back to the original JP inline name.
   patch_battlename.py repoints each site's `bl Combatant_GetRecord` here and NOPs the following `add
   rX,#0x22`, so each gets our pointer (the marker) directly.  See docs/text-pipeline-overview.md. */

typedef u32 (*rec_fn)(u32);
#define Combatant_GetRecord ((rec_fn)(RM_Combatant_GetRecord | 1))

__attribute__((used, section(".text.entry")))
u16 *cave_entry(u32 id)
{
    if (id < RM_NAME_COUNT && ((u16 *const *)RM_NAME_TABLE)[id])
        return (u16 *)(RM_MARKER_TABLE + id * 4);     /* -> { 0xF000|id, 0 }; renderer draws English */
    return (u16 *)(Combatant_GetRecord(id) + 0x22);   /* no English -> original JP inline name */
}

/* Negotiation / event-VM substitution demon-name selector ({=1e03} 0x31E and {=2203} 0x322 in
 * ScriptOp_DrawCharOrSubstitute 0x08132b40 — the two NEGO_SITES).  Returns the demon's name as a
 * pointer to REAL glyph tokens: the pooled English NAME_TABLE[id] when translated, else the JP
 * record name (record+0x22).
 *
 * The builder's inline FIXED-8 copy of this pointer into the substitution staging buffer is
 * REPLACED (patch_battlename) by a terminator-aware copy (cave_negocopy) that streams the WHOLE
 * name (cap 15, the staging field width) instead of a fixed 8.  So the name reaches the message
 * window as ordinary VWF glyphs — the prose appender (patch_vwf) advances `g_wMsgTextCol` by each
 * glyph's real width and the following word sits tight against the name end.
 *
 * This REPLACES the old 0xF800-marker + 0x70-pad scheme.  That scheme emitted one marker token
 * padded to the JP 8-token field; the pad made the appender advance the following text past the
 * full fixed field (~104px), and the renderer's reflow only re-anchored the FIRST post-pad record
 * (every later record re-diverged because the appender's accumulated x no longer matched) — a
 * persistent gap.  Real glyphs make the marker/pad/reflow machinery unnecessary: each name glyph
 * is its own record with its own true width, so nothing downstream needs special-casing. */
__attribute__((used, section(".text.entry")))
u16 *cave_negoname(u32 id)
{
    if (id < RM_NAME_COUNT && ((const u16 *const *)RM_NAME_TABLE)[id])
        return (u16 *)((const u16 *const *)RM_NAME_TABLE)[id];   /* pooled English name */
    return (u16 *)(Combatant_GetRecord(id) + 0x22);             /* JP record name */
}
