/* cave_victory.c — the victory line (MessageBox_ComposeRaceNameText call site).
 * Split from cave_resultmsg.c so each blob fits a cave-pool span.  See that file's
 * header for the sentinel/marker conventions. */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#include <rommap.h>

typedef u32 (*rec_fn)(u32);
typedef u16 *(*racename_fn)(u32 id, const u16 *suffix);
typedef u16 *(*racenm_fn)(int race);

#define GetRecord   ((rec_fn)(RM_Combatant_GetRecord | 1))
#define OrigRaceNm  ((racename_fn)(RM_MessageBox_ComposeRaceNameText | 1))
#define RaceName    ((racenm_fn)(RM_Race_GetNamePtr | 1))
#define BUF         ((u16 *)RM_COMPOSE_BUF)

/* RACE + ' ' + species name (EN marker / JP inline) + suffix.  The suffix is
 * 08124284's pooled " was defeated!" — its first token being an EN glyph is the
 * translation signal.  Race cells over the 7-token budget hold the names_race
 * sentinel (0xFFFF + pool ptr): resolve it. */
__attribute__((used, section(".text.entry")))
u16 *cave_entry(u32 speciesId, const u16 *suffix)
{
    u16 *o = BUF;
    const u16 *r;
    int k;
    u32 id = speciesId & 0xFFFF;
    /* Stock composers no-op (return COMPOSE_BUF untouched) while the msg-window
     * done flag is latched -- see cave_resultmsg.c's MSG_LOCKED note.  Without
     * this, composing here would clobber a locked on-screen message whose live
     * stream is COMPOSE_BUF (the auto-battle banner). */
    if (*(volatile u8 *)(RM_BMSG_STATE + 7) == 1)
        return BUF;
    if (suffix[0] < 0xBC || suffix[0] >= 0x118)
        return OrigRaceNm(id, suffix);                /* JP suffix: stock path */
    r = (const u16 *)RaceName(*(signed char *)GetRecord(id));
    if (r[0] == 0xFFFF) {                             /* sentinel'd over-budget race */
        u32 lo = r[1], hi = r[2];                     /* cell+2 is only 2-aligned, so an */
        r = (const u16 *)(lo | (hi << 16));           /* LDR would ARM7TDMI-rotate — read */
    }                                                 /* as two halfwords (cf. patch_race.py) */
    for (k = 0; k < 16 && r[k]; k++) *o++ = r[k];
    *o++ = 0xBC;                                      /* space */
    if (id < RM_NAME_COUNT && ((u16 *const *)RM_NAME_TABLE)[id]) {
        *o++ = (u16)(0xF000u | id);                   /* marker: renderer draws English */
    } else {
        const u16 *n = (const u16 *)(GetRecord(id) + 0x22);
        u16 *lo = o;
        for (k = 0; k < 8 && n[k]; k++) *o++ = n[k];
        while (o > lo && o[-1] == 0x70) o--;
    }
    /* Keep the whole defeat on ONE line — a SPACE before the suffix, not a newline.  VWF
     * English ("RACE name was defeated!") fits the window; the old JP fixed-pitch assumption
     * that race+name+suffix overflows doesn't hold (user request 2026-06-14). */
    *o++ = 0xBC;                                      /* space (was a 0x300 newline split) */
    for (k = 0; k < 48 && suffix[k]; k++) *o++ = suffix[k];
    /* The reward lines (EXP/Macca/Magnetite) are drawn as SEPARATE messages dropped below
     * this (line-1) stream by its 0x300-newline count.  With the defeat now ONE line, this
     * single trailing newline puts the reward on line 2, directly under the defeat.  EN-only:
     * we are already past the JP-suffix early return. */
    *o++ = 0x300;
    *o = 0;
    return BUF;
}
