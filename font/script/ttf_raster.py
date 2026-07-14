#!/usr/bin/env python3
"""Rasterize a TTF/pixel font glyph into a value grid for injection into a game sheet.

Pixel fonts (e.g. Galmuri 7/11/14) render crisp/binary at their native px size, so the
output is mostly on/off; `levels` lets you keep antialiasing greys for the 4bpp sheet.
Pairs with `sheet8.py` (4bpp 8x8 small sheet) and `patch_font.py` (2bpp main sheet).

The grid returned is `rows x cols` of integer pixel values 0..(levels-1). Body pixels are
mapped to `body`; with `levels>2` the source coverage is quantized to intermediate greys.

Typical use (small sheet, 8x8 cell, baseline near the bottom):
    f = load("fontsrc/Galmuri7.ttf", 7)
    g = char_grid(f, "a", cell_w=8, cell_h=8, baseline_row=6, left=1, body=15)
"""
from PIL import Image, ImageFont, ImageDraw


def load(path, px):
    return ImageFont.truetype(path, px)


def char_grid(font, ch, cell_w, cell_h, baseline_row=None, left=1, thresh=128, body=15, levels=2):
    """Render `ch` into a cell_h x cell_w grid (values 0..levels-1, body pixels = `body`).

    The glyph baseline is placed on cell row `baseline_row`; ink is shifted so its left
    edge starts at cell column `left`. Pixels outside the cell are clipped (e.g. a deep
    descender in a short cell). `baseline_row=None` auto-places the cap-top on row 0
    (baseline_row = font ascent), which fits an ascent+descent-tall font exactly."""
    asc, _desc = font.getmetrics()
    if baseline_row is None:
        baseline_row = asc
    pad = cell_h + cell_w
    img = Image.new("L", (cell_w + 2 * pad, cell_h + 2 * pad), 0)
    # text() y is the top of the ascent box, so the baseline sits at y + asc.
    # Draw so that image row (pad + baseline_row) is the baseline.
    ImageDraw.Draw(img).text((pad, pad + baseline_row - asc), ch, fill=255, font=font)
    bbox = img.getbbox()
    if bbox is None:
        return [[0] * cell_w for _ in range(cell_h)]
    src_x0 = bbox[0] - left   # so the glyph's left ink (bbox[0]) lands at cell column `left`
    src_y0 = pad              # cell row y -> image row pad + y (baseline at pad + baseline_row)
    grid = [[0] * cell_w for _ in range(cell_h)]
    for y in range(cell_h):
        for x in range(cell_w):
            sx, sy = src_x0 + x, src_y0 + y
            if 0 <= sx < img.width and 0 <= sy < img.height:
                v = img.getpixel((sx, sy))
                if v >= thresh:
                    grid[y][x] = body if levels <= 2 else min(body, 1 + v * (levels - 1) // 255)
    return grid


def ink_bounds(grid):
    """(left, top, right, bottom) of inked cells, or None if blank."""
    cols = [c for c in range(len(grid[0])) if any(row[c] for row in grid)]
    rows = [r for r in range(len(grid)) if any(grid[r])]
    if not cols or not rows:
        return None
    return min(cols), min(rows), max(cols), max(rows)
