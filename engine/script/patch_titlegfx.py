#!/usr/bin/env python3
"""Inject edited title/intro/game-over graphics from graphics/assets/.

Counterpart of graphics/script/titlegfx.py. For every registered asset whose
PNG differs from the ROM original, each of its blocks is
re-encoded in the asset's original wrapping (plain LZ77, or RLE-inside-LZ77 for the
title blocks — the loaders run BIOS SWI 0x11 then SWI 0x14) and written back:

  * in place when the new stream fits the original compressed slot (a shorter stream is
    fine — the BIOS stops at the decompressed size), else
  * relocated to the FARDATA_TITLEGFX bump region with every literal-pool reference
    repointed (ref sites come from the registry's whole-ROM scan; each repoint is
    guarded on the site still holding the original block address).

Pure data + guarded literal repoints: no hooks, no caves, order-independent.
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # noqa: F401,F403

import struct

import numpy as np
from PIL import Image

from graphics.script import gbagfx
from paths import ProjectPaths

_PATHS = ProjectPaths.discover()
GFXDIR = _PATHS.graphics_assets_root
BASE_ROM = _PATHS.source_rom


def _load_png_tiles(path, width, n_tiles):
    img = Image.open(path)
    if img.mode != "P":
        raise SystemExit(f"{path.name}: must stay a 16-colour INDEXED png (mode P, got {img.mode}) "
                         "— re-save without converting to RGB")
    a = np.asarray(img, dtype=np.uint8)
    need = ((n_tiles + width - 1) // width * 8, width * 8)
    if a.shape != need:
        raise SystemExit(f"{path.name}: size must stay {need[1]}x{need[0]} px, got {a.shape[1]}x{a.shape[0]}")
    if a.max() > 0xF:
        raise SystemExit(f"{path.name}: palette index {a.max()} > 15 — keep it 16 colours")
    # a block may end mid-row (title_screen = 338 of 352 tiles): ink past the block's
    # last tile would be silently dropped and the OAM would show stale VRAM there
    full = gbagfx.image_to_tiles(a, width, (a.shape[0] // 8) * width)
    if any(full[n_tiles * 32:][i] for i in range(len(full) - n_tiles * 32)):
        raise SystemExit(f"{path.name}: ink beyond the block's {n_tiles} tiles (bottom-right "
                         "of the sheet is NOT uploaded by the game) — move it into covered tiles")
    return full[:n_tiles * 32]


# Title-logo EN caption (see titlegfx_en.py): a 168x16 serif caption scattered across
# three free-but-UPLOADED sheet regions (the block holds only 338 tiles — sheet row 10
# exists only up to x143; ink past tile 337 would show stale VRAM).  Displaying them
# needs an EXTENDED logo metasprite.  Stock: attrList 0x0813EE60 (6 entries), desc
# 0x0813EE88, referenced by 4 title-state pool literals.  We append 10 sprites
# reassembling the caption at screen (36,10)..(203,25) — rel to the draw origin
# (0x78,0x18): the two 32x16 segments from the band's dead columns (sheet(224,40)/
# (224,56)), then the 104px segment as stacked 8px strips (top sheet(144,72), bottom
# sheet(0,80)), pal bank 1 (the logo ramp).
LOGO_DESC_SITES = [0x080D68BC, 0x080D69C8, 0x080D6A28, 0x080D6AF0]
LOGO_STOCK_ATTRLIST = 0x0813EE60
LOGO_STOCK_DESC = 0x0813EE88
Y = -14                    # caption box top = screen y10 (ink ~y12..23, kanji starts y24)
LOGO_CAPTION_SPRITES = [   # (yrel, xrel, shape "WxH", tile)
    (Y, -84, "32x16", 0x0BC), (Y, -52, "32x16", 0x0FC),
    (Y, -20, "32x8", 0x132), (Y, 12, "32x8", 0x136), (Y, 44, "32x8", 0x13A), (Y, 76, "8x8", 0x13E),
    (Y + 8, -20, "32x8", 0x140), (Y + 8, 12, "32x8", 0x144), (Y + 8, 44, "32x8", 0x148), (Y + 8, 76, "8x8", 0x14C),
]
OAM_SHAPE = {"32x16": (0x4000, 0x8000), "32x8": (0x4000, 0x4000), "8x8": (0x0000, 0x0000)}


def _install_logo_caption(p):
    stock = p.read(LOGO_STOCK_ATTRLIST, 2 + 6 * 6)
    n = struct.unpack_from("<H", stock)[0]
    attrs = bytearray(stock)
    for yrel, xrel, shape, tile in LOGO_CAPTION_SPRITES:
        s0, s1 = OAM_SHAPE[shape]
        attrs += struct.pack("<3H", (yrel & 0xFF) | s0, (xrel & 0x1FF) | s1, tile | 0x1000)
        n += 1
    struct.pack_into("<H", attrs, 0, n)
    attr_addr = rommap.FARDATA_TITLELOGO
    desc_addr = (attr_addr + len(attrs) + 3) & ~3
    if desc_addr + 8 > rommap.FARCAVE_POOL_SPANS[0][0]:
        raise SystemExit("titlegfx: FARDATA_TITLELOGO overflow")
    p.write(attr_addr, bytes(attrs))
    p.write(desc_addr, struct.pack("<2I", attr_addr, 0))
    old = struct.pack("<I", LOGO_STOCK_DESC).hex()
    for site in LOGO_DESC_SITES:
        p.patch(site, old, struct.pack("<I", desc_addr), name="titlegfx logo-caption repoint")
    print(f"  titlegfx: logo caption metasprite ({n} entries) @ {attr_addr:08X}, 4 sites repointed")


def apply(p):
    if not GFXDIR.is_dir():
        return
    base = BASE_ROM.read_bytes()
    far = rommap.FARDATA_TITLEGFX
    far_end = rommap.FARDATA_TITLELOGO
    changed = 0
    for asset in gbagfx.ASSETS:
        png = GFXDIR / f"{asset['name']}.png"
        if not png.exists():
            continue
        orig_raw, sizes, slots = gbagfx.decode_asset(base, asset)
        new_raw = _load_png_tiles(png, asset["width"], len(orig_raw) // 32)
        if new_raw == orig_raw:
            continue
        off = 0
        for addr, size, slot in zip(asset["blocks"], sizes, slots):
            o_part = orig_raw[off:off + size]
            n_part = new_raw[off:off + size]
            off += size
            if n_part == o_part:
                continue
            enc = gbagfx.encode_block(n_part, asset["wrap"])
            if len(enc) <= slot:
                p.write(addr, enc)
                where = f"in place ({len(enc):#x}/{slot:#x})"
            else:
                dest = (far + 3) & ~3
                if dest + len(enc) > far_end:
                    raise SystemExit(f"titlegfx: FARDATA_TITLEGFX overflow at {asset['name']}")
                p.write(dest, enc)
                old = struct.pack("<I", addr).hex()
                for site in asset["refs"][addr]:
                    p.patch(site, old, struct.pack("<I", dest), name=f"titlegfx {asset['name']} repoint")
                far = dest + len(enc)
                where = f"relocated -> {dest:08X} ({len(enc):#x} > slot {slot:#x}, {len(asset['refs'][addr])} refs)"
            print(f"  titlegfx: {asset['name']} @{addr:08X} {where}")
            changed += 1
    if changed:
        print(f"  titlegfx: {changed} block(s) injected")
    # extended logo metasprite: only when the caption strips actually carry ink
    ts = GFXDIR / "title_screen.png"
    if ts.exists():
        px = np.asarray(Image.open(ts))
        if px.shape[0] >= 88 and (px[40:72, 224:256].any() or px[72:80, 144:248].any()
                                  or px[80:88, 0:104].any()):
            _install_logo_caption(p)
