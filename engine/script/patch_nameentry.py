#!/usr/bin/env python3
"""EN-friendly name-entry screen: Uppercase / Lowercase / Symbols(+numbers) categories.

Full RE + design: docs/name-entry-rework.md.  The player name-entry grid is a table of u16 GLYPH
TOKENS at NAMEENTRY_GRID_TOKENS (11 cols x 25 rows, spacer = 0x003F), drawn by NameEntry_DrawGrid
0x080d15dc; the right-panel "categories" are just vertical scroll bookmarks (0 / 10 / 20) set by
NameEntry_HandleInput 0x080d1828.  Its A-press stores name[i] = NameEntry_TokenToCharsetIndex(grid
cell) -- but that scanner stops at the first 0-token charset entry (charset 0xD3-0xDF are 0), so it
can never return a lowercase index (0xE0+).

This patch (pure data + 4 two-byte pokes, no cave):
  1. Rewrites the token table with an EN 3-page layout: A-Z (rows 0-2, bookmark scroll 0),
     a-z (rows 10-12, scroll 10), 0-9 + symbols (rows 20-21, scroll 20).
  2. Writes a PARALLEL charset-INDEX byte table (same 11x25 layout) in far data and repoints the
     input handler's table literal to it; the A-press is switched from "read u16 token + scan" to
     "read 1 byte index" (lsl->nop, ldrh->ldrb, bl->nop;nop).  Storage is then direct and supports
     any index incl. lowercase 0xE0+; the token scanner NameEntry_TokenToCharsetIndex becomes dead.

The category list text is relabelled by the nameentry_exchange.json literal_slots section, and the
12px charset tokens for typed '-'/''' are set by patch_defaultnames (runs first).
"""
import struct

try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from engine.script import rommap

# charset index -> display glyph token (token = charset[index]); contiguous runs.
A_TOK, A_IDX = 0x00DD, 0x17        # 'A'..'Z'
LC_TOK, LC_IDX = 0x00FE, 0xE0      # 'a'..'z'
D_TOK, D_IDX = 0x00CC, 0x09        # '0'..'9'
BLANK_TOK, BLANK_IDX = 0x003F, 0x00   # spacer / blank cell: renders blank, decodes to space

# (display token, charset index) for the names-safe symbols (the 8px small sheet + the 12px charset
# fills in patch_defaultnames map these same indices).
SYMBOLS = [
    (0x00C9, 0x06),          # '-'  hyphen
    (0x00C0, 0xD3),          # '''  apostrophe
    (0x0004, 0x07),          # '.'  period
    (BLANK_TOK, BLANK_IDX),  # space (visible blank, but a real space char)
]
USABLE_COLS = [0, 1, 2, 3, 4, 6, 7, 8, 9, 10]   # col 5 is the visual spacer (the cursor skips it)

# Page layout: each block (Upper/Lower/Symbols) starts at one of these grid rows, with exactly ONE
# blank row between blocks so vertical scrolling is short.  The rows are also the category-button
# scroll bookmarks.  Upper=rows 0-2, Lower=rows 4-6, Symbols=rows 8-9.
PAGE_ROWS    = (0, 4, 8)        # scroll bookmark per category (Uppercase / Lowercase / Symbols)
MAX_SCROLL   = PAGE_ROWS[2]     # 8 — the last block sits at the top of the 4-row window
DOWN_CAP     = MAX_SCROLL + 3   # 11 — down-scroll blocks when scrollY+4 > DOWN_CAP (cap scrollY at 8)
PAGEROWS_R3  = MAX_SCROLL + 4   # 12 — the R/L page-scroll caps scrollY at (r3 - 4) = MAX_SCROLL

# Guard: the JP grid's row 0 (あいうえお [sp] はひふへほ) must still be in place when we run.
OLD_ROW0 = "1d011f012101230125013f004a014d01500153015601"


def build_tables():
    """Return (token_bytes [550], index_bytes [275]) for the EN 3-page grid."""
    cols, rows = rommap.NAMEENTRY_GRID_COLS, rommap.NAMEENTRY_GRID_ROWS
    cells = [(BLANK_TOK, BLANK_IDX)] * (cols * rows)

    def put(row, col, tok, idx):
        cells[row * cols + col] = (tok, idx & 0xFF)

    def lay_run(base_row, tok0, idx0, n):
        # left-pack n contiguous chars across the 10 usable columns, wrapping to the next row
        for i in range(n):
            put(base_row + i // len(USABLE_COLS), USABLE_COLS[i % len(USABLE_COLS)], tok0 + i, idx0 + i)

    lay_run(PAGE_ROWS[0], A_TOK,  A_IDX,  26)     # Uppercase (scroll 0): A-Z -> rows 0-2
    lay_run(PAGE_ROWS[1], LC_TOK, LC_IDX, 26)     # Lowercase (scroll 4): a-z -> rows 4-6
    lay_run(PAGE_ROWS[2], D_TOK,  D_IDX,  10)     # Symbols   (scroll 8): 0-9 -> row 8
    for i, (tok, idx) in enumerate(SYMBOLS):      # symbols on the next row (row 9)
        put(PAGE_ROWS[2] + 1, i, tok, idx)

    tokens = b"".join(struct.pack("<H", t) for t, _ in cells)
    indices = bytes(idx for _, idx in cells)
    assert len(tokens) == cols * rows * 2 and len(indices) == cols * rows
    return tokens, indices


def apply(p):
    tokens, indices = build_tables()

    # 1. token table (display) — overwrite the JP kana grid in place (guard row 0)
    p.patch(rommap.NAMEENTRY_GRID_TOKENS, OLD_ROW0, tokens, name="nameentry grid tokens")

    # 2. parallel charset-index table (input) in far data
    idx_addr = p.data(indices, at=rommap.FARDATA_NAMEGRID_IDX, name="nameentry grid indices")

    # 3. retarget the A-press: read 1 byte from the index table instead of a u16 token + scan
    p.patch(rommap.NAMEENTRY_INPUT_TBL_LITERAL, "dc2d4f08", struct.pack("<I", idx_addr),
            name="nameentry input table -> index table")
    p.patch(rommap.NAMEENTRY_APRESS_LSL, "4000", b"\xc0\x46", name="nameentry A: lsl->nop")
    p.patch(rommap.NAMEENTRY_APRESS_LDRH, "0088", b"\x00\x78", name="nameentry A: ldrh->ldrb")
    p.patch(rommap.NAMEENTRY_APRESS_BL, "eef789fd", b"\xc0\x46\xc0\x46", name="nameentry A: scan->nop")

    # 4. vertical layout: repoint the category bookmarks to the packed page rows and tighten the
    #    free-scroll clamps so scrolling stops at the symbols block (each site is a `mov/cmp rN,#imm8`).
    p.patch(rommap.NAMEENTRY_BOOKMARK_LO, "0a20", bytes([PAGE_ROWS[1], 0x20]), name="nameentry bookmark Lowercase")
    p.patch(rommap.NAMEENTRY_BOOKMARK_SY, "1420", bytes([PAGE_ROWS[2], 0x20]), name="nameentry bookmark Symbols")
    p.patch(rommap.NAMEENTRY_DOWNCAP, "1828", bytes([DOWN_CAP, 0x28]), name="nameentry down-scroll cap")
    p.patch(rommap.NAMEENTRY_PAGEROWS_R3, "1923", bytes([PAGEROWS_R3, 0x23]), name="nameentry page-scroll rows")
    # down-ARROW visibility uses the same threshold so it hides exactly when down-scroll is blocked (scrollY=8)
    p.patch(rommap.NAMEENTRY_DOWNARROW, "1828", bytes([DOWN_CAP, 0x28]), name="nameentry down-arrow cap")
