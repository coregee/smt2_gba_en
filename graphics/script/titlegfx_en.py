#!/usr/bin/env python3
"""Render the English title-sequence graphics into graphics/assets/*.png.

Regenerates the editable sheets from assets/originals/ and the English text specs below,
so wording tweaks are a re-run away (the sheets stay hand-editable afterwards — this
script only overwrites the assets it owns).  The ROM build (patch_titlegfx) then
injects whatever differs from the originals.

Owned assets:
  * title_scroll — the opening narration crawl.  EN layout: 16 lines / 6 paragraphs
    in the x<200 text region (x>=200 = art tiles, untouched), ~13px pitch, 12px AA
    glyphs.  EN re-typesets the whole text region with the same paragraph rhythm.
  * title_screen — only the logo band y40..83 (the JP brush logo) is replaced with
    an EN logotype; the menu text above it is already English.

JP source (transcribed 2026-07-09 from the sheets):
    20XX年 TOKYO / 大破壊より 数十年……
    荒野を耕し 悪魔の群れと戦い / 無数の生と死をくり返しながら / 人は 生きのびていた……
    だが 頼るもの すがるもの無く / 生きていけるほど人は強くない / 人は明日への希望を探した……
    メシア教は救世主の降臨を説き / 信じた人が集い 街が出来た / かつて…… / カテドラルと呼ばれた所に……
    20XX年 / かくして トウキョウは / TOKYOミレニアムとなった
"""
import numpy as np
from PIL import Image, ImageDraw, ImageFont

try:
    from graphics.script._boot import ASSETS as GFXDIR
except ModuleNotFoundError:
    from _boot import ASSETS as GFXDIR

SERIF = r"C:\Windows\Fonts\times.ttf"
SERIF_BI = r"C:\Windows\Fonts\timesbi.ttf"   # bold italic, for the logotype

# ------------------------------------------------------------------ scroll text
# One tuple per paragraph; None = blank line inside a paragraph.  Budget: x 12..199.
SCROLL = [
    ["TOKYO, 20XX"],
    ["Several decades after the Great",
     "Destruction..."],
    ["They cultivated the wilderness, fought",
     "off the demonic hordes, and through",
     "countless lives and deaths, humanity",
     "endured..."],
    ["But nobody has the strength to live",
     "without someone or something to cling",
     "to or rely on. And so the people",
     "longed..."],
    ["The Messians preached the advent of a",
     "savior, gathered the faithful, and a new",
     "city rose atop the old Cathedral."],
    ["This city would come to be known",
     "as Tokyo Millenium."],
]
SCROLL_X = 12
SCROLL_Y0 = 4
SCROLL_PITCH = 12
SCROLL_PARA_GAP = 8
SCROLL_XMAX = 200                 # art tiles start here — never touch
SCROLL_SIZE = 11                  # Times 11px: longest line measures ~181px

# The JP brush logo (真・女神転生II) is KEPT — per the older official EN logo style the
# English appears as a small caption above the large kanji.  The logo is OBJ metasprite
# @0x0813EE88 (main band = sheet x0..223 y40..71 at screen (12,24), tail window =
# sheet(104,72) 40x16 at screen (116,56)).
#
# CRITICAL: the sheet block holds only 0x2A40 bytes = 338 TILES — tile rows 0..9 full,
# row 10 (sheet y80..87) only up to x143.  Anything drawn past tile 337 is silently
# dropped at inject time and the OAM would show stale VRAM (the "black bar" bug, hit
# 2026-07-09).  Atlus's own tail sprite ends exactly at tile 337.
#
# The 16px-tall serif caption is assembled from three free UPLOADED regions that no
# title-state metasprite displays (all 9 descs enumerated 2026-07-09): the logo band's
# dead right columns (x224..255 of rows y40..71 — the logo sprites stop at x223) give
# two 32x16 segments, and the two 8px strips (sheet(144,72) / sheet(0,80)) stack into a
# 104x16 segment.  patch_titlegfx shows them contiguously at screen (36,10)..(203,25)
# via an EXTENDED metasprite.  The logo's pixels may use ONLY the palette-ramp indices
# 11..15 (15 = fill, 11 = faintest AA edge) — bank 1's other indices are unrelated colors.
LOGO_CAPTION = "SHIN MEGAMI TENSEI II"
# (sheet x, sheet y, w, h, caption-canvas x, canvas y) — the caption is drawn on a
# 168x16 canvas and scattered into these sheet rects; the metasprite reassembles them.
LOGO_STRIPS = [
    (224, 40, 32, 16, 0, 0),
    (224, 56, 32, 16, 32, 0),
    (144, 72, 104, 8, 64, 0),
    (0, 80, 104, 8, 64, 8),
]
LOGO_CAPTION_W, LOGO_CAPTION_H = 168, 16

# ------------------------------------------------------------------ Charon (game over)
# The Charon speech is drawn as OBJ metasprite B (attrList @0x08002AB8, origin (0x78,0x64),
# 2D char mapping over the charon_text sheet; the portrait = metasprite A, untouched).
# Each rect below = (screen x, screen y, w, h, sheet x, sheet y) decoded from the OAM
# templates — EN is typeset on a 240x160 virtual screen and inverse-mapped through them.
# JP: カロン：川の向こうは 常世の国 / 死者の魂が 次の転生を 待つ所 / さあ 川を 渡るのだ… …
CHARON_RECTS = [
    (12, 100, 64, 32,  80,  0),
    (76, 100, 64, 32, 144,  0),
    (140, 100, 32, 32, 208,  0),
    (172, 100, 32, 32,   0, 32),
    (204, 100, 16, 32,  32, 32),
    (220, 100, 8, 32,   48, 32),
    (60, 132, 64, 28,   56, 32),   # h clipped at screen bottom (y132+32 > 160)
    (124, 132, 64, 28, 120, 32),
    (188, 132, 32, 28, 184, 32),
    (220, 132, 8, 8,   216, 32),
]
CHARON_LINES = [   # (x, y, text) on the virtual 240x160 screen
    (14, 103, "Charon: Beyond the river lies the afterworld,"),
    (22, 117, "where the souls of the dead await their next"),
    (64, 136, "life. Come, cross the river..."),
]


def _render_text(canvas_l, draw_l, text, xy, font):
    draw_l.text(xy, text, fill=255, font=font)


def _quantize_into(a, canvas_l, y0=0, x0=0, keep_below=1):
    """Blend an L-mode render into the indexed array: gray 0..255 -> index 0..15."""
    g = np.asarray(canvas_l, dtype=np.uint16)
    idx = ((g * 15 + 127) // 255).astype(np.uint8)
    h, w = idx.shape
    region = a[y0:y0 + h, x0:x0 + w]
    region[idx >= keep_below] = idx[idx >= keep_below]


def render_scroll():
    a = np.asarray(Image.open(GFXDIR / "originals" / "title_scroll.png")).copy()
    a[:, :SCROLL_XMAX] = 0                          # clear the JP text region
    font = ImageFont.truetype(SERIF, SCROLL_SIZE)
    canvas = Image.new("L", (SCROLL_XMAX, a.shape[0]), 0)
    d = ImageDraw.Draw(canvas)
    y = SCROLL_Y0
    for para in SCROLL:
        for line in para:
            if line:
                w = d.textbbox((0, 0), line, font=font)[2]
                if SCROLL_X + w > SCROLL_XMAX - 4:
                    raise SystemExit(f"scroll line too wide ({w}px): {line!r}")
                d.text((SCROLL_X, y), line, fill=255, font=font)
            y += SCROLL_PITCH
        y += SCROLL_PARA_GAP
    _quantize_into(a, canvas)
    _save(a, "title_scroll")


def render_logo():
    a = np.asarray(Image.open(GFXDIR / "originals" / "title_screen.png")).copy()
    # JP kanji band stays untouched; render only the EN caption into the free strips.
    S = 4                                             # supersample for smooth AA
    W, H = LOGO_CAPTION_W, LOGO_CAPTION_H
    canvas = Image.new("L", (W * S, H * S), 0)
    d = ImageDraw.Draw(canvas)
    font = ImageFont.truetype(SERIF_BI, 11 * S)
    b = d.textbbox((0, 0), LOGO_CAPTION, font=font)
    if b[2] - b[0] > W * S:
        raise SystemExit(f"logo caption too wide ({(b[2] - b[0]) // S}px > {W}px)")
    d.text(((W * S - (b[2] - b[0])) // 2 - b[0], (H * S - (b[3] - b[1])) // 2 - b[1]),
           LOGO_CAPTION, fill=255, font=font)
    canvas = canvas.resize((W, H), Image.LANCZOS)
    # quantize into the logo's OWN AA ramp: transparent below threshold, else 11..15
    g = np.asarray(canvas, dtype=np.int32)
    idx = np.where(g < 48, 0, 11 + ((g - 48) * 5 // 208).clip(0, 4)).astype(np.uint8)
    for sx, sy, w, h, cx, cy in LOGO_STRIPS:
        a[sy:sy + h, sx:sx + w] = idx[cy:cy + h, cx:cx + w]
    _save(a, "title_screen")


def render_charon():
    a = np.asarray(Image.open(GFXDIR / "originals" / "charon_text.png")).copy()
    scr = Image.new("L", (240, 160), 0)
    d = ImageDraw.Draw(scr)
    font = ImageFont.truetype(SERIF, 12)
    for x, y, text in CHARON_LINES:
        w = d.textbbox((0, 0), text, font=font)[2]
        if x + w > 228:
            raise SystemExit(f"charon line too wide ({x}+{w}px): {text!r}")
        d.text((x, y), text, fill=255, font=font)
    g = np.asarray(scr, dtype=np.uint16)
    idx = ((g * 15 + 127) // 255).astype(np.uint8)
    for sx, sy, w, h, tx, ty in CHARON_RECTS:
        a[ty:ty + h, tx:tx + w] = idx[sy:sy + h, sx:sx + w]
    _save(a, "charon_text")


def _save(a, name):
    img = Image.fromarray(a, "P")
    img.putpalette(bytes(b for i in range(16) for b in (i * 17, i * 17, i * 17)))
    img.save(GFXDIR / f"{name}.png")
    print(f"rendered graphics/assets/{name}.png")


def main() -> None:
    render_scroll()
    render_logo()
    render_charon()


if __name__ == "__main__":
    raise SystemExit(main())
