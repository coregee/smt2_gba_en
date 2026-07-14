#!/usr/bin/env python3
"""English default human names (Hawk/Hiroko/Beth + Gimmel/Daleth/Zayin/Aleph).

Player-character names are NOT text streams: they are 8 charset-INDEX bytes at
Combatant+0x00..07 (0xFF = pad), decoded through g_wNameCharsetTable (index -> glyph
token) by Combatant_DecodeName 0x080C0344 / the until-terminator decoder 0x080C0378.
The new-game/story init code copies the defaults straight from two ROM tables of
8-byte index cells (DEFAULT_NAMES_A consumer @0x080BF7xx, DEFAULT_NAMES_B consumer
@0x080C11xx), so translating them = rewriting those cells with English indices.

The base charset only has UPPERCASE Latin (idx 0x17-0x30 -> tokens 0x00DD-0x00F6).
For mixed-case names we copy the 224-entry table to FARDATA and append lowercase
a-z (tokens 0x00FE-0x0117, the same bank-0 face as the uppercase run) at idx
0xE0-0xF9, then retarget the table's four literal pools (all inside the two
decoders + the two token->index scanners; verified the only ROM refs).  Both
decoders index unbounded, so idx >= 0xE0 decodes fine; the token->index scanners
cap at 0xDF / stop at the first 0-token entry and so never return a lowercase
index — but nothing in the game encodes lowercase tokens, ROM defaults are stored
pre-encoded.  The name-entry UI grid only shows the original 224 (player-typed
names stay uppercase-only; the grid is untouched).

Two 8px name drawers do NOT decode: they use the raw charset index directly as a
small-sheet cell (cell = 0x100 + idx; the party-panel name builder FUN_080C6E78 and
the name-preview sprite drawer FUN_080D0288, literals @SMALLSHEET_THIN_REFS).  Index
0xE0+ would hit the live UI-tile cells (0x1E0+), so we copy the thin face to
SMALLSHEET_EXT (idx 0x00-0xDF = original cells 0x100-0x1DF), append 26 lowercase
8x8 cells rasterized from Galmuri7 (body value 2 like the ROM thin face; baseline
on row 7 to match the ROM caps, descenders g/j/p/q/y squashed one row), and
retarget both literals.

Both 8px drawers are also VWF-hooked (uneven fixed-8px spacing on mixed case, and
room for longer names): a width byte per charset index (cell ink + 1px gap, blank
= 4) is appended after the relocated sheet (SMALLSHEET_EXT_WIDTHS).  The panel
strip builder's whole copy loop is replaced by cave_name8vwf.c (pixel-X blit into
the 8-tile 4bpp strip); the save-screen sprite drawer just advances X by the width
table instead of a constant 8 (tiny asm cave at its `x += 8`).
"""
import struct

try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from engine.script import rommap
from font.script.repack import build_small_font

UPPER_IDX = 0x17                                  # charset index of 'A' (B..Z follow)
LOWER_TOKENS = list(range(0x00FE, 0x0118))        # glyph tokens a..z (contiguous, verified)

# (cell address, original JP index bytes, English name).  Cells are 8 bytes, 0xFF-padded.
DEFAULTS = [
    (rommap.DEFAULT_NAMES_A + 0x00, "6bd13fffffffffff", "Hawk"),    # ホーク (hero, Colosseum name)
    (rommap.DEFAULT_NAMES_A + 0x08, "627d43ffffffffff", "Hiroko"),  # ヒロコ
    (rommap.DEFAULT_NAMES_A + 0x10, "6949ffffffffffff", "Beth"),    # ベス
    (rommap.DEFAULT_NAMES_A + 0x18, "3b394962d17dd1ff", "Chaos"),   # カオスヒーロー (SMT1 leftover slot-3 default)
    (rommap.DEFAULT_NAMES_B + 0x00, "3e717bffffffffff", "Gimmel"),  # ギメル
    (rommap.DEFAULT_NAMES_B + 0x08, "507c49ffffffffff", "Daleth"),  # ダレス
    (rommap.DEFAULT_NAMES_B + 0x10, "463380ffffffffff", "Zayin"),   # ザイン
    (rommap.DEFAULT_NAMES_B + 0x18, "317c65ffffffffff", "Aleph"),   # アレフ
]


def encode_name(name):
    out = bytearray()
    for ch in name:
        if "A" <= ch <= "Z":
            out.append(UPPER_IDX + ord(ch) - ord("A"))
        elif "a" <= ch <= "z":
            out.append(rommap.NAME_LOWER_IDX + ord(ch) - ord("a"))
        else:
            raise SystemExit(f"default name {name!r}: no charset index for {ch!r}")
    if len(out) > 8:
        raise SystemExit(f"default name {name!r} exceeds the 8-index name field")
    out += b"\xff" * (8 - len(out))
    return bytes(out)


CAVE_SRC = Path(__file__).with_name("cave_name8vwf.c")

# Party_BuildMemberNameTiles 0x080C6E78: bl cave after the push (r4-r7/lr saved), then jump
# straight to the stock epilogue @0x080C6EEC (DisplayList_Add + pop) — the cave does the
# whole 6-panel loop itself.
PANEL_HOOK      = 0x080C6E7A    # movs r4,#0 / lsls r0,r4,#0x10
PANEL_HOOK_OLD  = "00242004"
PANEL_SKIP      = 0x080C6E7E    # lsrs r0,r0,#0x10 -> b 0x080C6EEC (epilogue)
PANEL_SKIP_OLD  = "000c"
PANEL_SKIP_NEW  = bytes.fromhex("35e0")          # Thumb b +0x6a

# Menu_DrawCombatantName8px 0x080D0288 (save/file-select names, one 8x8 sprite per glyph):
# replace the fixed `x += 8<<16` advance with a width-table lookup.  At the hook r4 already
# points at the NEXT name byte and r0-r3 are dead (just returned from the sprite call).
SAVE_HOOK       = 0x080D02CA    # movs r0,#0x80 / lsls r0,r0,#0xc
SAVE_HOOK_OLD   = "80200003"
SAVE_NOP        = 0x080D02CE    # adds r5,r5,r0 -> nop (cave adds the width itself)
SAVE_NOP_OLD    = "2d18"
SAVE_CAVE_ASM = """
    subs r0, r4, #1        /* current glyph = [r4 - 1] */
    ldrb r0, [r0]
    ldr  r1, [pc, #0]      /* SMALLSHEET_EXT_WIDTHS */
    ldrb r0, [r1, r0]
    lsls r0, r0, #0x10     /* r5 = x << 16 */
    adds r5, r5, r0
    bx   lr
"""


def apply(p):
    # extended charset: base 224 entries + a-z at idx 0xE0, placed in the far data block
    base = bytearray(p.read(rommap.NAME_CHARSET_TABLE, rommap.NAME_CHARSET_COUNT * 2))
    # 12px charset tokens for the name-entry symbols page (patch_nameentry / docs/name-entry-rework.md):
    # the 8px small sheet already maps these cells ('-' 0x06, ''' 0xD3), so set the matching 12px tokens
    # for consistent rendering of typed punctuation.  '.' (idx 0x07) already = the period token 0x0004.
    struct.pack_into("<H", base, 0x06 * 2, 0x00C9)   # '-' hyphen (was 0x003C = long-vowel mark)
    struct.pack_into("<H", base, 0xD3 * 2, 0x00C0)   # ''' apostrophe (was 0x0000 = blank)
    ext = bytes(base) + b"".join(struct.pack("<H", t) for t in LOWER_TOKENS)
    addr = p.data(ext, at=rommap.FARDATA_NAMECHARSET, name="namecharset+lower")
    new_ref = struct.pack("<I", addr)
    old_ref = struct.pack("<I", rommap.NAME_CHARSET_TABLE).hex()
    for ref in rommap.NAME_CHARSET_REFS:
        p.patch(ref, old_ref, new_ref, name=f"charset ref @{ref:08X}")

    # relocated 8px thin face for the index-direct drawers (p.patch guards the 0xFF free
    # space; p.data can't host it — its zero-assert rejects 0xFF padding)
    sheet = build_small_font(p.rom)
    assert len(sheet) <= rommap.SMALLSHEET_EXT_SIZE
    p.patch(rommap.SMALLSHEET_EXT, "ff" * len(sheet), sheet, name="smallsheet ext (8px thin + lowercase)")
    thin_old = struct.pack("<I", rommap.ROM_BASE + sheet8.cell_offset(THIN_FACE_CELL0)).hex()
    thin_new = struct.pack("<I", rommap.SMALLSHEET_EXT)
    for ref in rommap.SMALLSHEET_THIN_REFS:
        p.patch(ref, thin_old, thin_new, name=f"thin-face ref @{ref:08X}")

    # VWF: party panel (C cave replaces the whole strip-build loop) + save screen (asm cave
    # swaps the fixed 8px sprite advance for the width table)
    p.cave_c(CAVE_SRC, name="name8vwf")
    p.bl(PANEL_HOOK, p.cave_c_syms["cave_entry"], PANEL_HOOK_OLD, name="panel name VWF")
    p.patch(PANEL_SKIP, PANEL_SKIP_OLD, PANEL_SKIP_NEW, name="panel name VWF skip->epilogue")
    save_cave = p.cave_asm(SAVE_CAVE_ASM, literals=[rommap.SMALLSHEET_EXT_WIDTHS], name="save name VWF")
    p.bl(SAVE_HOOK, save_cave, SAVE_HOOK_OLD, name="save name VWF")
    p.patch(SAVE_NOP, SAVE_NOP_OLD, bytes.fromhex("c046"), name="save name VWF nop")

    for cell, old_hex, name in DEFAULTS:
        p.patch(cell, old_hex, encode_name(name), name=f"default name {name}")
