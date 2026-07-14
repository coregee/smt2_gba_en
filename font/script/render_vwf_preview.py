#!/usr/bin/env python3
"""Preview how English text would look with the variable-width font (VWF).

Lays out a string using the existing ROM glyphs + the measured width table
(text/data/glyph_widths.tsv): each glyph is left-trimmed to its ink (srcX=2+left,
width=ink) and the cursor advances by `adv`. Renders that next to the current
FIXED-12px layout for comparison -> text/data/vwf_preview.png. Zero ROM changes;
this is a pure visual check before designing the in-game hook.

Usage:
    python font/script/render_vwf_preview.py
    python font/script/render_vwf_preview.py "Your own sample text"
"""
import sys
from pathlib import Path
from PIL import Image, ImageDraw, ImageFont

try:
    from font.script._boot import CONFIG, GENERATED, ROM as ROM_PATH
except ModuleNotFoundError:
    from _boot import CONFIG, GENERATED, ROM as ROM_PATH

from font.script.render_glyph import render_glyph_pixels  # noqa: E402
import json

ROM = ROM_PATH.read_bytes()
LEVELS = {0: (255, 255, 255), 1: (255, 255, 255), 2: (30, 30, 40), 3: (165, 170, 185)}
SCALE = 4
CELL_H = 13            # drawn rows (2..14)
LINE_H = 16
SPACE_ADV = 5
GAP_FIXED = 12

# char -> glyph code (invert the map; prefer the lowest code per char = canonical ASCII)
CHAR2CODE = {}
for k, v in sorted(json.loads((CONFIG / "glyph_map_data.json").read_text(encoding="utf-8")).items(),
                   key=lambda kv: int(kv[0], 16)):
    CHAR2CODE.setdefault(v, int(k, 16))
# width table: code -> (left, ink, adv)
WIDTH = {}
for line in (GENERATED / "glyph_widths.tsv").read_text(encoding="utf-8").splitlines()[1:]:
    code, ch, left, ink, adv = line.split("\t")
    WIDTH[int(code, 16)] = (int(left), int(ink), int(adv))

# authored punctuation glyphs (not in the ROM yet) — overlay them
from font.script.custom_glyphs import custom_grids, custom_chars, with_shadow  # noqa: E402
CUSTOM = {c: with_shadow(g) for c, g in custom_grids().items()}
CHAR2CODE.update(custom_chars())


def get_grid(code):
    return CUSTOM.get(code) if code in CUSTOM else render_glyph_pixels(ROM, code)


def get_width(code):
    if code in WIDTH and code not in CUSTOM:
        return WIDTH[code]
    g = get_grid(code)
    cols = [c for c in range(2, 14) if any(g[r][c] for r in range(2, 15))]
    if not cols:
        return (0, 0, SPACE_ADV)
    left = min(cols) - 2
    ink = max(cols) - 2 - left + 1
    return (left, ink, ink + 1)


def lay_out(text, vwf):
    """Return (pixels dict {(x,y):val}, total_width, n_lines)."""
    px = {}
    x = y = 0
    maxx = 0
    for chx in text:
        if chx == "\n":
            x = 0
            y += LINE_H
            continue
        if chx == " ":
            x += SPACE_ADV
            maxx = max(maxx, x)
            continue
        code = CHAR2CODE.get(chx)
        if code is None:
            x += GAP_FIXED
            continue
        g = get_grid(code)
        left, ink, adv = get_width(code)
        c0 = (2 + left) if vwf else 2
        cw = ink if vwf else 12
        for row in range(CELL_H):
            for col in range(cw):
                v = g[2 + row][c0 + col]
                if v:
                    px[(x + col, y + row)] = v
        x += adv if vwf else GAP_FIXED
        maxx = max(maxx, x)
    return px, maxx, (y // LINE_H) + 1


def render_block(text, vwf):
    px, w, nlines = lay_out(text, vwf)
    h = nlines * LINE_H
    img = Image.new("RGB", (max(w, 1), h), (255, 255, 255))
    pix = img.load()
    for (x, y), v in px.items():
        pix[x, y] = LEVELS[v]
    return img.resize((img.width * SCALE, img.height * SCALE), Image.NEAREST), w


def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")
    samples = sys.argv[1:] or [
        'Punctuation: . , ! ? : ; - " ( )',
        "Aleph, will you join me?",
        "The demon attacks! HP restored.",
        '"Who are you?" he asked.',
        "Got 80000 Macca; lucky!",
    ]

    pad = 10
    label_w = 44
    blocks = []
    for s in samples:
        v_img, vw = render_block(s, vwf=True)
        f_img, fw = render_block(s, vwf=False)
        blocks.append((s, v_img, vw, f_img, fw))

    width = label_w + max(b[1].width for b in blocks) + pad * 2
    height = pad + sum(b[1].height + b[3].height + 18 + pad for b in blocks)
    sheet = Image.new("RGB", (width, height), (245, 246, 248))
    d = ImageDraw.Draw(sheet)
    f = ImageFont.truetype(r"C:\Windows\Fonts\consola.ttf", 12)
    # 240px GBA screen guide (scaled)
    screen_x = label_w + 240 * SCALE
    y = pad
    for s, v_img, vw, f_img, fw in blocks:
        d.line([(screen_x, y), (screen_x, y + v_img.height + f_img.height + 16)],
               fill=(220, 180, 180), width=1)
        d.text((4, y), "VWF", fill=(20, 120, 20), font=f)
        sheet.paste(v_img, (label_w, y))
        d.text((label_w + v_img.width + 4, y), f"{vw}px", fill=(20, 120, 20), font=f)
        y += v_img.height + 4
        d.text((4, y), "fixed", fill=(160, 90, 90), font=f)
        sheet.paste(f_img, (label_w, y))
        d.text((label_w + f_img.width + 4, y), f"{fw}px", fill=(160, 90, 90), font=f)
        y += f_img.height + 14 + pad
    d.text((screen_x + 3, height - 16), "240px screen edge", fill=(200, 120, 120), font=f)

    out = GENERATED / "vwf_preview.png"
    sheet.save(out)
    print(f"wrote {out}  ({sheet.width}x{sheet.height})")
    for s, _v, vw, _f, fw in blocks:
        print(f"  {fw:4d}px -> {vw:4d}px  ({100*(fw-vw)//max(fw,1):2d}% narrower)  {s!r}")


if __name__ == "__main__":
    raise SystemExit(main())
