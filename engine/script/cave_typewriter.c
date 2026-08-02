/* cave_typewriter.c — pixel-paced reveal for the BATTLE message-box typewriter.
 *
 * The battle renderer's typewriter modes (BattleMenu_RenderMessageObject mode 2
 * = line 1 @0x080ea61c, mode 6 = line 2 @0x080ea7dc) revealed ONE stream TOKEN
 * per tick: state+3 (token index) advanced by 1 and the copy loop rebuilt the
 * line buffer from stream[0..idx].  Two consequences in English:
 *   1. EN half-width text packs ~2x the tokens/line of Japanese, so at one
 *      token/tick it scrolls ~2x slower in pixels.
 *   2. The demon name in "[race] [name] xN" is a SINGLE 0xF000|id marker token
 *      (patch_battlename) that cave_runtext expands to the whole name — so the
 *      name popped in on one tick instead of typing out.
 *
 * Fix: pace by PIXELS.  Each tick we copy the FULL line into the line buffer and
 * advance REVEAL_PX by REVEAL_STEP; cave_runtext clips its draw of the battle
 * line buffers at REVEAL_PX (and it expands the marker, so the name reveals
 * glyph-by-glyph).  Done when REVEAL_PX covers the drawable width.  We stamp the
 * current frame in REVEAL_STAMP so cave_runtext only clips on frames this worker
 * ran — static modes (1/5/8) draw unclipped automatically, even after an
 * interrupted message.
 *
 * The two veneers are reached by repointing the renderer's mode jump-table
 * entries (patch_typewriter): the dispatch does `mov pc, table[mode]` with r5 =
 * the state object already set, so a veneer runs in the renderer's stack frame.
 * It calls the C worker (which preserves r4-r11, so r5 survives), then reproduces
 * the EXACT register state the original handler had at its draw tail and branches
 * there — so all the Y/cursor/line-empty positioning is the stock code's.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

#include <rommap.h>

#define REVEAL_PX    ((volatile u16 *)RM_REVEAL_PX)
#define REVEAL_STAMP (*(volatile u16 *)RM_REVEAL_STAMP)
#define FRAME16      ((u16)(*(volatile u32 *)RM_FRAME_COUNTER))
#define WIDTH        ((const u8 *)RM_WIDTH_TABLE)
#define BMSG_PITCH   12               /* the battle window's fixed line pitch (0xc) */

/* Settings_GetBattleMsgSpeed() -> 0/1 index into g_bBattleMsgDelayTable {2,1}. */
typedef int (*spd_fn)(void);
#define GetMsgSpeed ((spd_fn)(RM_Settings_GetBattleMsgSpeed | 1))

/* Linker root: ENTRY(cave_entry) + --gc-sections (cave_cc) keeps the single .text
 * section this whole file compiles into — so the named entry points below
 * (veneers, ev_cave, worker) survive even though they're reached only via the
 * jump-table repoint / bl that patch_typewriter installs.  Never called. */
__attribute__((used))
void cave_entry(void) {}

/* Glyph advance — MUST match cave_runtext::glyph_width(g, pitch=12): English
 * glyphs use the VWF width table, everything else the fixed pitch. */
static inline u16 gw(u16 g)
{
    return (g >= RM_ENG_LO && g < RM_ENG_HI) ? WIDTH[g] : BMSG_PITCH;
}

/* 0xF000|id demon-name marker -> pooled English name (0-terminated), else 0. */
static const u16 EMPTY_NAME[1] = { 0 };
static inline const u16 *marker_name(u16 g)
{
    u32 id;
    const u16 *n;
    if ((g & 0xF000u) != RM_MARKER_BASE) return 0;
    id = g & 0x0FFFu;
    n = (id < RM_NAME_COUNT) ? ((const u16 *const *)RM_NAME_TABLE)[id] : 0;
    return n ? n : EMPTY_NAME;
}

/* line2 = 0 -> line-1 buffer (state+0xc, filters 0x315 pause tokens),
 * line2 = 1 -> line-2 buffer (state+0x8c, no filter).  Same source/filter rules
 * the stock mode-2/6 copy loops used. */
__attribute__((used, noinline))
volatile u16 *battle_reveal_worker(volatile u8 *st, int line2)
{
    const u16 *stream = *(const u16 *const *)(st + 8);
    volatile u16 *buf = (volatile u16 *)(st + (line2 ? 0x8c : 0xc));
    const u16 *s;
    volatile u16 *dst;
    u32 total, oldpx, wnext;
    int lines, npause, anypause;
    u8 d;

    REVEAL_STAMP = FRAME16;                 /* arm cave_runtext's clip for THIS frame */

    if (*(volatile u16 *)RM_HELD_BUTTONS & 1) st[2] = 1;   /* hold A: fast-forward */
    d = (u8)(st[2] - 1);
    st[2] = d;
    if (d) return buf;                      /* delay not expired: just redraw current reveal */

    if (st[3] == 0) { REVEAL_PX[0] = 0; st[3] = 1; }   /* first tick of this message */
    oldpx = REVEAL_PX[0];

    /* Copy the full line into the buffer and, in the same pass, measure its
     * DRAWABLE width (the width cave_runtext accumulates: markers expanded,
     * newlines 0px, only the first 4 lines) AND locate the next 0x315 PAUSE
     * group ahead of the current reveal frontier.  0x315 = `{=1503}`, the
     * 15-frame dramatic pause (e.g. the flee "...." ellipsis rhythm): it is not
     * displayed, but the reveal stops on the dot in front of it.  Consecutive
     * 0x315 stack (the JP runs 3/2/1 to accelerate), so the wait scales by the
     * count. */
    s = stream; dst = buf; total = 0; lines = 0;
    wnext = 0xffffffffu; npause = 0; anypause = 0;
    for (;;) {
        u16 t = *s++;
        if (t == 0 || t == 0x301) break;            /* terminator */
        if (t == 0x315) {                           /* pause token: not displayed */
            anypause = 1;                           /* this message has a dot/pause rhythm */
            if (npause == 0 && total > oldpx) {     /* first pause group still ahead */
                wnext = total; npause = 1;
                while (*s == 0x315) { npause++; s++; }
            }
            continue;
        }
        if (dst - buf < 63) *dst++ = t;             /* line buffer is 64 u16 incl. terminator */
        if (t == 0x300) { lines++; continue; }      /* newline: a separator, 0 width */
        if (lines < 4) {
            const u16 *n = marker_name(t);
            if (n) { for (; *n; ++n) total += gw(*n); }
            else total += gw(t);
        }
    }
    *dst = 0;

    /* A line with pause tokens (the flee "...." ellipsis) holds narrow dots clustered into one or
     * two 16px cells, so cave_runtext's default pre-blit + per-cell sprite clip would pop a whole
     * cell of dots in at once.  Flag it so the strip core reveals it PER-PIXEL (incremental blit up
     * to REVEAL_PX) -> the dots type out one at a time.  Cleared otherwise so the normal battle
     * typewriter (encounter intro / victory / damage) keeps the cheap pre-blit. */
    *(volatile u16 *)RM_REVEAL_FINE = (u16)anypause;

    /* advance: clamp to the next pause point if it is within one step, and wait
     * 15 frames per stacked pause token there; else step normally. */
    if (npause && wnext - oldpx <= (u32)RM_REVEAL_STEP) {
        u32 p = (u32)npause * 15;
        REVEAL_PX[0] = (u16)wnext;
        st[2] = (u8)(p > 255 ? 255 : p);
    } else {
        REVEAL_PX[0] = (u16)(oldpx + RM_REVEAL_STEP);
        st[2] = ((const u8 *)RM_BATTLE_MSG_DELAY_TABLE)[GetMsgSpeed() & 0xffff];
    }

    /* Complete when the reveal covers the drawable width — INCLUDING total==0
     * (a stream with no drawable ink: empty translation, pause-only line, or
     * all tokens past line 4).  Stock completed such lines immediately (its
     * token index just ran out); gating on `total &&` left the typewriter mode
     * live forever -> the message never signals done -> the battle message
     * queue stays busy = a silent livelock risk on any 0-width line. */
    if (REVEAL_PX[0] >= total) {                    /* whole line shown -> complete */
        st[0] = (u8)(line2 ? 5 : 1);                /* stock completion mode */
        st[3] = 0; st[2] = 0;
        REVEAL_PX[0] = 0xFFFF;                      /* final static draw unclipped */
    }
    return buf;
}

/* mode-2 veneer: build/advance line 1, then enter the stock line-1 draw tail
 * (0x080ea6a8) exactly as the original handler did — r4 = line-1 buffer, r5 =
 * state (preserved across the AAPCS call). */
__attribute__((naked, used))
void veneer_mode2(void)
{
    __asm__ volatile(
        "mov  r0, r5            \n"
        "movs r1, #0            \n"
        "bl   battle_reveal_worker \n"   /* returns line-1 buffer in r0; r5 preserved */
        "mov  r4, r0            \n"
        "ldr  r0, =0x080ea6a9   \n"
        "bx   r0                \n"
    );
}

/* mode-6 veneer: build/advance line 2, then enter the stock line-2 draw tail
 * (0x080ea842) with r5 = state, r6 = line-2 buffer (state+0x8c) — the exact
 * register state the original handler had falling out of its copy loop. */
__attribute__((naked, used))
void veneer_mode6(void)
{
    __asm__ volatile(
        "mov  r0, r5            \n"
        "movs r1, #1            \n"
        "bl   battle_reveal_worker \n"   /* returns line-2 buffer in r0; r5 preserved */
        "mov  r6, r0            \n"
        "ldr  r0, =0x080ea843   \n"
        "bx   r0                \n"
    );
}

/* ---- event-VM dialogue/story window: pixel-pace the per-glyph reveal ----
 * EventVM_RunStep appends one glyph record then yields state 15 for
 * g_wMsgGlyphDelay frames (one glyph/tick).  EN half-width glyphs (~6px) reveal
 * ~2x slower in pixels than JP (~13px).  This cave replaces the state-15 setup
 * (hooked at 0x0813dcd8 by patch_typewriter): it yields ONLY once REVEAL_STEP px
 * of text have been appended since the last yield, otherwise it resumes the
 * opcode-fetch loop to append the next glyph this frame — so ~REVEAL_STEP px
 * reveal per delay tick regardless of glyph width.
 *
 * g_wMsgTextCol (0x0203db38) is the pixel X accumulator (patch_vwf), so
 * px-since-last-yield = col - EV_LASTCOL.  A newline/window-reset drops col
 * below EV_LASTCOL -> we yield and re-anchor (col <= last).  Reached by `bl`, so
 * lr is free; it never returns, branching to the fetch loop (0x0813db78) or the
 * stock yield epilogue (0x0813dcf6). */
__attribute__((naked, used))
void ev_cave(void)
{
    __asm__ volatile(
        "ldr  r0, =0x0203db38   \n"   /* &g_wMsgTextCol (pixel accumulator) */
        "ldrh r2, [r0]          \n"   /* col */
        "ldr  r1, =%c0          \n"   /* &EV_LASTCOL */
        "ldrh r3, [r1]          \n"   /* last-yield col */
        "cmp  r2, r3            \n"
        "bls  1f                \n"   /* col <= last (newline / first / none) -> yield */
        "sub  r0, r2, r3        \n"   /* px since last yield */
        "cmp  r0, %1            \n"   /* REVEAL_STEP */
        "bhs  1f                \n"
        "ldr  r0, =0x0813db79   \n"   /* not enough: resume fetch loop (append next glyph) */
        "bx   r0                \n"
        "1:                     \n"
        "strh r2, [r1]          \n"   /* EV_LASTCOL = col */
        "ldr  r0, =0x0203db5a   \n"   /* &g_wScriptStateId */
        "movs r1, #0xf          \n"
        "strh r1, [r0]          \n"   /* state = 15 (typewriter delay) */
        "ldr  r0, =0x0203db5c   \n"   /* &g_wScriptStateTimer */
        "ldr  r1, =0x0203db82   \n"   /* &g_wMsgGlyphDelay */
        "ldrh r1, [r1]          \n"
        "strh r1, [r0]          \n"   /* timer = delay */
        "ldr  r0, =0x030031b0   \n"   /* held-input word */
        "ldrh r1, [r0]          \n"
        "movs r0, #2            \n"
        "and  r0, r1            \n"   /* held-B bit */
        "cmp  r0, #0            \n"
        "beq  2f                \n"
        "ldr  r0, =0x0203db48   \n"   /* &g_wMsgInstantFlag */
        "movs r1, #1            \n"
        "strh r1, [r0]          \n"   /* arm instant reveal for the rest of the page */
        "2:                     \n"
        "ldr  r0, =0x0813dcf7   \n"   /* stock yield epilogue (add sp,#8; pop ...) | thumb */
        "bx   r0                \n"
        :: "i"(RM_EV_LASTCOL), "i"(RM_REVEAL_STEP)
    );
}
