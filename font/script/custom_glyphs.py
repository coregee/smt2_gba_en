#!/usr/bin/env python3
"""English ASCII face — rasterized from the HelvetiPixel pixel font (not the ROM font).

The stock ROM Latin letterforms are wide (W ~12px) and have no native comma. This module
replaces the whole half-width English block (codes 0xBC..0x117 — space, digits, A-Z, a-z,
and the half-width punctuation slots) with HelvetiPixel (a narrow pixel face; see
`fontsrc/SOURCES.md`), rasterized into the 2bpp main-sheet format and given the JP font's
native drop shadow (one pixel straight down). VWF (`patch_vwf.py`) then auto-trims each
glyph's advance, so the proportional spacing follows the new letterforms automatically.

Pipeline contract (unchanged for every consumer):
  custom_grids()  -> {code: 16x16 grid (values 0/2, shadow-free)}   injected by patch_font
  with_shadow(g)  -> grid + JP 1px-down shadow (value 3)            applied by patch_font etc.
  custom_chars()  -> {char: code}  (punctuation + space only)        feeds the text codec
  PUNCT / GLYPH_ART / SPACE_CODE                                     compat exports

Why punctuation still lives in dedicated half-width slots (the VWF zone constraint):
  patch_vwf only proportional-spaces codes >= 0xBC; codes below that keep fixed 12px width
  so JP full-width punctuation (、。！？) stays full-width. So English punctuation must sit
  in a half-width slot (0xBD+) to get VWF spacing — `PUNCT` maps each to its slot. The codec
  (tr.CHAR2CODE / custom_chars) encodes ',' '.' '!' … to those slots.

Letters/digits are pinned to the canonical ASCII slots by the codec itself
(tr.py: upper/digit = ord+0x9C, lower = ord+0x9D); we rasterize the matching glyph into
each of those codes here.
"""
from functools import lru_cache
from PIL import Image, ImageFont, ImageDraw

try:
    from font.script._boot import SOURCE
except ModuleNotFoundError:
    from _boot import SOURCE

# --- the injected face ---------------------------------------------------------------
FONT_PATH = SOURCE / "HelvetiPixel.ttf"
FONT_PX = 15            # crisp native size for HelvetiPixel (cap height 8px)
BASELINE_ROW = 12       # grid row the cap-baseline lands on (drawn window is rows 2..14)
COL0 = 2               # leftmost drawn column (= visible window col 0); ink left-aligns here
BODY = 2               # 2bpp value for body ink (matches the ROM font); 3 = drop shadow
_PAD = 32

# half-width punctuation slot : (char, _legacy_source)  — slot codes consumed by the codec.
# The `_legacy_source` field is vestigial (punctuation is now rasterized, not derived) but
# kept so custom_chars()/GLYPH_ART/patch_vwf's `set(PUNCT)` keep their shapes.
PUNCT = {
    0xBD: ("!", None), 0xBE: ('"', None), 0xBF: ("/", None), 0xC0: ("'", None),
    0xC1: ("…", None), 0xC4: ("(", None), 0xC5: (")", None), 0xC8: (",", None),
    0xC9: ("-", None), 0xCA: (".", None), 0xD6: (":", None), 0xD7: (";", None),
    0xDB: ("?", None),
}
SPACE_CODE = 0xBC       # blank glyph; fixed advance via build_width_table SPACE_ADV

# canonical letter/digit slots (must match tr.CHAR2CODE: upper/digit = ord+0x9C, lower +0x9D)
_LETTERS_DIGITS = {ord(c) + 0x9C: c for c in "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"}
_LETTERS_DIGITS.update({ord(c) + 0x9D: c for c in "abcdefghijklmnopqrstuvwxyz"})

# code -> char for every glyph this module injects (space handled separately)
CODE2CHAR = dict(_LETTERS_DIGITS)
CODE2CHAR.update({code: ch for code, (ch, _src) in PUNCT.items()})


@lru_cache(maxsize=1)
def _font():
    return ImageFont.truetype(str(FONT_PATH), FONT_PX)


# Chars HelvetiPixel has no glyph for -> rasterize a visual substitute built only from glyphs
# the font DOES have. Without this, PIL draws the font's .notdef glyph (a hollow rectangle), so
# the missing char bakes a tofu BOX into the sheet — e.g. every '…' rendered as an empty box,
# the 2026-06-16 report ("full-stops render as boxes"). The ellipsis is three of the font's own
# periods (HelvetiPixel lacks U+2026 but has '.'); the codec still maps '…' -> 0xC1 unchanged,
# so this is a pure glyph-art fix needing no JSON edits.
_RENDER_SUBST = {"…": "..."}


@lru_cache(maxsize=1)
def _baseline_src_y():
    """Image-y that maps to grid row BASELINE_ROW: the bottom inked row of 'H' (= the
    font baseline), drawn at the fixed pen used by _render_char."""
    f = _font()
    img = Image.new("L", (64 + 2 * _PAD, 64 + 2 * _PAD), 0)
    ImageDraw.Draw(img).text((_PAD, _PAD), "H", fill=255, font=f)
    bb = img.getbbox()
    return (bb[3] - 1) - BASELINE_ROW


def _render_char(ch):
    """Rasterize ch into a 16x16 grid (values 0/BODY), ink left-aligned to COL0, baseline
    on grid row BASELINE_ROW. Out-of-cell pixels (deep descenders) clip."""
    ch = _RENDER_SUBST.get(ch, ch)          # substitute glyphs HelvetiPixel lacks (e.g. '…' -> '...')
    f = _font()
    img = Image.new("L", (16 + 4 * _PAD, 16 + 4 * _PAD), 0)
    ImageDraw.Draw(img).text((2 * _PAD, _PAD), ch, fill=255, font=f)
    bb = img.getbbox()
    grid = [[0] * 16 for _ in range(16)]
    if bb is None:
        return grid
    src_x0 = bb[0] - COL0           # glyph's leftmost ink -> grid column COL0
    src_y0 = _baseline_src_y()
    for y in range(16):
        for x in range(16):
            sx, sy = src_x0 + x, src_y0 + y
            if 0 <= sx < img.width and 0 <= sy < img.height and img.getpixel((sx, sy)) >= 128:
                grid[y][x] = BODY
    return grid


def custom_grids():
    """code -> 16x16 grid (values 0/BODY, shadow-free). Space is blank; every other English
    glyph is rasterized from HelvetiPixel. patch_font applies with_shadow() before encoding."""
    grids = {SPACE_CODE: [[0] * 16 for _ in range(16)]}
    for code, ch in CODE2CHAR.items():
        grids[code] = _render_char(ch)
    return grids


def custom_chars():
    """char -> target code (consumed by the text codec). Punctuation slots + space only;
    letters/digits are pinned to canonical slots by tr.CHAR2CODE."""
    m = {ch: code for code, (ch, _src) in PUNCT.items()}
    m[" "] = SPACE_CODE
    return m


def with_shadow(grid):
    """Add the JP font's native drop shadow: a value-3 pixel one row straight down from each
    body pixel, where the cell below is empty. Same columns -> does not change glyph width."""
    out = [row[:] for row in grid]
    for y in range(15):
        for x in range(16):
            if grid[y][x] == BODY and grid[y + 1][x] == 0:
                out[y + 1][x] = 3
    return out


# patch_font.py prints GLYPH_ART[code][0]; covers every code custom_grids() emits.
GLYPH_ART = {SPACE_CODE: (" ", None)}
GLYPH_ART.update({code: (ch, None) for code, ch in CODE2CHAR.items()})
