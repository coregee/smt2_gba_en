#!/usr/bin/env python3
"""Side-by-side preview: stock ROM English glyphs vs a rasterized custom font.

Faithfully simulates the in-game look of swapping the main-sheet English block
(codes 0xBC..0x117) for a TTF/pixel font: rasterizes each char into the 16x16
cell at the 12x13 visible window, round-trips it through the real 2bpp codec
(so quantization is honest), left-trims + measures the VWF advance exactly like
patch_vwf, then lays out a sample sentence both ways and writes a scaled PNG.

    python font/script/preview_font_swap.py
    python font/script/preview_font_swap.py --font Galmuri11 --px 11 --baseline 13
"""
import argparse
import sys
from pathlib import Path

try:
    from font.script._boot import CONFIG, GENERATED, REVIEW, ROM as ROM_PATH, SOURCE
except ModuleNotFoundError:
    from _boot import CONFIG, GENERATED, REVIEW, ROM as ROM_PATH, SOURCE

from PIL import Image, ImageFont, ImageDraw
from font.script.render_glyph import render_glyph_pixels
from engine.script.patch_font import encode_glyph
from font.script import render_glyph as rg

ROM = ROM_PATH.read_bytes()
FONTSRC = SOURCE

COL0, COL1, ROW0, ROW1 = 2, 13, 2, 14   # visible window
GAP = 1
SPACE_ADV = 5

# char -> English glyph code (from the glyph map); built once
import json
_GMAP = {int(k, 16): v for k, v in json.loads((CONFIG / "glyph_map_data.json").read_text("utf-8")).items()}
CHAR2CODE = {ch: code for code, ch in _GMAP.items() if 0x00BC <= code <= 0x0117 and len(ch) == 1}


def decode_via_codec(grid):
    """Round-trip a 16x16 grid through the 2bpp encoder+decoder (honest quantization)."""
    tltr, blbr = encode_glyph(grid)
    g = [[0] * 16 for _ in range(16)]
    TL = rg.decode_2bpp_tile(tltr[0:0x10]); TR = rg.decode_2bpp_tile(tltr[0x10:0x20])
    BL = rg.decode_2bpp_tile(blbr[0:0x10]); BR = rg.decode_2bpp_tile(blbr[0x10:0x20])
    for y in range(8):
        for x in range(8):
            g[y][x] = TL[y][x]; g[y][x + 8] = TR[y][x]
            g[y + 8][x] = BL[y][x]; g[y + 8][x + 8] = BR[y][x]
    return g


def raster16(font, ch, baseline_row, body=2):
    """Rasterize ch into a 16x16 grid, baseline on row `baseline_row`, ink left at COL0."""
    asc, _ = font.getmetrics()
    pad = 24
    img = Image.new("L", (16 + 2 * pad, 16 + 2 * pad), 0)
    ImageDraw.Draw(img).text((pad, pad + baseline_row - asc), ch, fill=255, font=font)
    bb = img.getbbox()
    grid = [[0] * 16 for _ in range(16)]
    if bb is None:
        return grid
    src_x0 = bb[0] - COL0
    for y in range(16):
        for x in range(16):
            sx, sy = src_x0 + x, pad + y
            if 0 <= sx < img.width and 0 <= sy < img.height and img.getpixel((sx, sy)) >= 128:
                grid[y][x] = body
    return grid


def add_shadow(grid):
    """Add the JP-style 1px-down drop shadow: value 3 directly below each body pixel
    where the cell below is empty. Same columns -> does NOT change glyph width."""
    out = [row[:] for row in grid]
    for y in range(15):
        for x in range(16):
            if grid[y][x] == 2 and grid[y + 1][x] == 0:
                out[y + 1][x] = 3
    return out


def trim(grid):
    """(left-trimmed grid, advance) per patch_vwf: ink shifted to COL0, adv = ink+GAP."""
    cols = [c for c in range(COL0, COL1 + 1) if any(grid[r][c] for r in range(ROW0, ROW1 + 1))]
    if not cols:
        return grid, SPACE_ADV
    left = min(cols) - COL0
    ink = max(cols) - COL0 - left + 1
    ng = [[0] * 16 for _ in range(16)]
    for y in range(16):
        for x in range(16 - left):
            ng[y][x] = grid[y][x + left]
    return ng, ink + GAP


def stock_glyph(ch):
    if ch == " ":
        return [[0] * 16 for _ in range(16)], SPACE_ADV
    code = CHAR2CODE.get(ch)
    if code is None:
        return [[0] * 16 for _ in range(16)], SPACE_ADV
    return trim(render_glyph_pixels(ROM, code))


def custom_glyph(font, ch, baseline, shadow=False):
    if ch == " ":
        return [[0] * 16 for _ in range(16)], SPACE_ADV
    g = raster16(font, ch, baseline)
    if shadow:
        g = add_shadow(g)
    return trim(decode_via_codec(g))


def layout(glyphs, scale, pad=2):
    """glyphs = list of (grid, adv). Compose a single grayscale strip image."""
    total = sum(a for _g, a in glyphs) + 2 * pad
    h = 16
    img = Image.new("L", (total * scale, h * scale), 255)
    px = img.load()
    levels = {0: 255, 1: 110, 2: 0, 3: 150}
    x = pad
    for grid, adv in glyphs:
        for yy in range(16):
            for xx in range(16):
                v = grid[yy][xx]
                if v:
                    for dy in range(scale):
                        for dx in range(scale):
                            X, Y = (x + xx) * scale + dx, yy * scale + dy
                            if 0 <= X < img.width and 0 <= Y < img.height:
                                px[X, Y] = levels[v]
        x += adv
    return img


def compare(specs, text, scale, out):
    """specs = list of (label, font_path_or_None, px, baseline, shadow). None font = stock ROM."""
    strips, labels = [], []
    for label, fpath, px, baseline, shadow in specs:
        if fpath is None:
            gl = [stock_glyph(ch) for ch in text]
        else:
            font = ImageFont.truetype(fpath, px)
            gl = [custom_glyph(font, ch, baseline, shadow) for ch in text]
        strips.append(layout(gl, scale))
        labels.append(f"{label}   width={sum(a for _g, a in gl)}px")
    lh = 16 * scale // 2
    W = max(s.width for s in strips)
    H = sum(s.height for s in strips) + (lh + 6) * len(strips)
    out_img = Image.new("L", (W, H), 255)
    d = ImageDraw.Draw(out_img)
    y = 0
    for strip, lab in zip(strips, labels):
        d.text((4, y + 2), lab, fill=0)
        out_img.paste(strip, (0, y + lh))
        y += lh + strip.height + 6
    Path(out).parent.mkdir(parents=True, exist_ok=True)
    out_img.save(out)
    print(f"wrote {out}")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--font", default="Galmuri11")
    ap.add_argument("--px", type=int, default=11)
    ap.add_argument("--baseline", type=int, default=13)
    ap.add_argument("--scale", type=int, default=6)
    ap.add_argument("--text", default="Hawk, the Messian gun. WMABXYjpq 0123?")
    ap.add_argument("--out", default=str(REVIEW / "font_compare.png"))
    args = ap.parse_args()
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")

    font = ImageFont.truetype(str(FONTSRC / f"{args.font}.ttf"), args.px)
    text = args.text

    stock = [stock_glyph(ch) for ch in text]
    custom = [custom_glyph(font, ch, args.baseline) for ch in text]

    s_img = layout(stock, args.scale)
    c_img = layout(custom, args.scale)

    label_h = 16 * args.scale // 2
    W = max(s_img.width, c_img.width)
    out = Image.new("L", (W, s_img.height + c_img.height + label_h * 2 + 12), 255)
    d = ImageDraw.Draw(out)
    y = 0
    d.text((4, y + 2), f"STOCK  width={sum(a for _g,a in stock)}px", fill=0)
    out.paste(s_img, (0, label_h)); y = label_h + s_img.height + 6
    d.text((4, y + 2), f"{args.font} px={args.px}  width={sum(a for _g,a in custom)}px", fill=0)
    out.paste(c_img, (0, y + label_h))
    Path(args.out).parent.mkdir(parents=True, exist_ok=True)
    out.save(args.out)

    # width comparison table
    sw = {ch: a for ch, (_g, a) in zip(text, stock)}
    cw = {ch: a for ch, (_g, a) in zip(text, custom)}
    print(f"wrote {args.out}")
    print(f"total advance:  stock={sum(a for _g,a in stock)}px  {args.font}={sum(a for _g,a in custom)}px")
    print("per-glyph advance (stock -> custom):")
    for ch in "AMWBXYabcgmwpq0":
        s, c = stock_glyph(ch)[1], custom_glyph(font, ch, args.baseline)[1]
        print(f"  {ch!r}: {s:>2} -> {c:>2}")


if __name__ == "__main__":
    raise SystemExit(main())
