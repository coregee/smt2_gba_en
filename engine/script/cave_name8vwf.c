/* cave_name8vwf.c — VWF + English demon names for the party-panel 8px name strips
 * (Party_BuildMemberNameTiles 0x080C6E78).  Compiled by devkitARM (Thumb, armv4t),
 * injected by patch_defaultnames.py.
 *
 * The stock function copies 8 whole 8x8 cells (fixed 8px pitch) from the small-sheet thin
 * face into a 0x100-byte strip (8 linear 4bpp tiles) per party panel, indexing the sheet by
 * the raw NAME-CHARSET INDEX byte (Combatant+0x00..07).  This cave replaces the whole loop:
 *
 *  - HUMANS (combatant type byte +0x0C < 4): render the entered-name index bytes VWF —
 *    glyphs from the relocated SMALLSHEET_EXT (lowercase at idx 0xE0+), advance by the
 *    per-index width table at RM_SMALLSHEET_EXT_WIDTHS (ink + 1px gap).
 *  - DEMONS: look the species id (+0x12) up in NAME_TABLE (the pooled English demon names,
 *    u16 glyph tokens, NUL-terminated — same table the status-screen name cave uses) and
 *    render that VWF, mapping each TOKEN to its 8px charset cell (A-Z 0x00DD+ -> idx 0x17+,
 *    a-z 0x00FE+ -> idx 0xE0+, digits 0x00CC+ -> idx 0x09+, space/-/'/. -> their thin-face
 *    cells; unmapped tokens are skipped — only "( )" in one name).  No table entry (or
 *    id out of range) falls back to the stock katakana index bytes.
 *
 * Names clip at the strip's 64px (8 tiles — writing further would bleed into the NEXT
 * panel's strip).  Hooked via bl @0x080C6E7A (just after the push, r4-r7/lr saved) + a `b`
 * to the stock epilogue @0x080C6EEC.  Empty slots (resolve returns 0) are skipped without
 * touching their strip, matching stock.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#include <rommap.h>

typedef int (*resolve_fn)(u32 rosterPos);
#define Party_ResolveMember ((resolve_fn)(RM_PARTY_PANEL_RESOLVE | 1))
#define SHEET      ((const u8 *)RM_SMALLSHEET_EXT)
#define WIDTHS     ((const u8 *)RM_SMALLSHEET_EXT_WIDTHS)
#define NAME_TABLE ((const u32 *)RM_NAME_TABLE)

/* glyph TOKEN (pooled EN name) -> 8px charset cell index; 0x100 = no cell, skip */
static u32 tok2idx(u32 t)
{
    if (t >= 0x00DD && t <= 0x00F6) return 0x17 + (t - 0x00DD);  /* A-Z */
    if (t >= 0x00FE && t <= 0x0117) return 0xE0 + (t - 0x00FE);  /* a-z */
    if (t >= 0x00CC && t <= 0x00D5) return 0x09 + (t - 0x00CC);  /* 0-9 */
    if (t == 0x00BC) return 0x00;                                /* space (blank, 4px) */
    if (t == 0x00C9) return 0x06;                                /* - (thin flat dash) */
    if (t == 0x00C0) return 0xD3;                                /* ' */
    if (t == 0x00CA) return 0x07;                                /* . */
    return 0x100;
}

static u32 blit(u8 *strip, u32 x, u32 idx)
{
    const u8 *cell = SHEET + idx * 0x20;
    u32 col, y;
    for (col = 0; col < 8; col++) {
        u32 px = x + col;
        if (px >= 64)
            break;
        for (y = 0; y < 8; y++) {
            /* 4bpp: low nibble = even x, high = odd x (sheet cell and strip alike) */
            u32 v = (cell[y * 4 + (col >> 1)] >> ((col & 1) * 4)) & 0xF;
            u8 *b;
            if (!v)
                continue;
            b = strip + (px >> 3) * 0x20 + y * 4 + ((px & 7) >> 1);
            if (px & 1)
                *b = (u8)((*b & 0x0F) | (v << 4));
            else
                *b = (u8)((*b & 0xF0) | v);
        }
    }
    return x + WIDTHS[idx];
}

void cave_entry(void)
{
    u32 slot;
    for (slot = 0; slot < 6; slot++) {
        const u8 *c = (const u8 *)Party_ResolveMember(slot & 0xffff);
        u8 *strip = (u8 *)(RM_PARTY_NAME_CANVAS + slot * 0x100);
        const u16 *en = 0;
        u32 x = 0, k, i;
        if (!c)
            continue;                       /* empty slot: stock leaves the strip alone */
        if (c[0x0C] >= 4) {                 /* demon: pooled EN name when translated */
            u32 id = *(const u16 *)(c + 0x12);
            if (id < RM_NAME_COUNT)
                en = (const u16 *)NAME_TABLE[id];
        }
        for (i = 0; i < 0x40; i++)
            ((u32 *)strip)[i] = 0;
        if (en) {
            for (k = 0; en[k] && x < 64; k++) {
                u32 idx = tok2idx(en[k]);
                if (idx <= 0xFF)
                    x = blit(strip, x, idx);
            }
        } else {
            for (k = 0; k < 8 && x < 64; k++) {
                u32 idx = c[k];
                if (idx == 0xFF) {          /* pad/blank position: narrow space */
                    x += 4;
                    continue;
                }
                x = blit(strip, x, idx);
            }
        }
    }
}
