#!/usr/bin/env python3
"""Preview composer: draws sprite graphics through the game's own OAM cell lists, and other
multi-part assets the way the game assembles them, into assets/previews/ (git-ignored PNGs;
nothing here feeds the build).

    python tools/assets/sprites.py demons        demon/character battle sprites (0x0872C774)
    python tools/assets/sprites.py characters    event/field character sprites (0x08568D78)

Cell list format (Sprite_DrawWithMode, src/sys_sprite.c): a sprite definition is
{u16 *cells, affine *}; cells = u16 count, then count x (attr0, attr1, attr2) OAM words.
"""
from __future__ import annotations

import struct
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import bios  # noqa: E402

ROOT = HERE.parents[1]
PREVIEWS = ROOT / "assets" / "previews"
BASE = 0x08000000

OBJ_SIZES = {  # (shape, size) -> (w, h) in pixels
    (0, 0): (8, 8), (0, 1): (16, 16), (0, 2): (32, 32), (0, 3): (64, 64),
    (1, 0): (16, 8), (1, 1): (32, 8), (1, 2): (32, 16), (1, 3): (64, 32),
    (2, 0): (8, 16), (2, 1): (8, 32), (2, 2): (16, 32), (2, 3): (32, 64),
}


class Rom:
    def __init__(self):
        self.b = (ROOT / "baserom.gba").read_bytes()

    def u32(self, a):
        return struct.unpack_from("<I", self.b, a - BASE)[0]

    def u16(self, a):
        return struct.unpack_from("<H", self.b, a - BASE)[0]

    def decode(self, a):
        """BIOS stream at `a`, unwrapping Huffman+LZ77."""
        o = a - BASE
        data = bios.decode(self.b, o)[0]
        if self.b[o] & 0xF0 == 0x20:
            data = bios.lz77(data, 0)[0]
        return data

    def palette(self, a, n=16):
        cols = []
        for i in range(n):
            v = self.u16(a + 2 * i)
            cols.append(((v & 31) * 255 // 31, ((v >> 5) & 31) * 255 // 31, ((v >> 10) & 31) * 255 // 31))
        return cols


def tile_pixels(tiles: bytes, t: int):
    """8x8 4bpp tile `t` as rows of indices (None past the end)."""
    if (t + 1) * 32 > len(tiles):
        return None
    d = tiles[t * 32:(t + 1) * 32]
    return [[(d[y * 4 + x // 2] >> 4) if x & 1 else (d[y * 4 + x // 2] & 15) for x in range(8)]
            for y in range(8)]


def cells(rom: Rom, cell_list: int):
    n = rom.u16(cell_list)
    return [tuple(rom.u16(cell_list + 2 + 6 * i + 2 * k) for k in range(3)) for i in range(n)]


def draw_cells(img, tiles: bytes, palette, objs, ox, oy, tile_base=0, stride=None):
    """Draw OAM objects (attr0, attr1, attr2) at origin (ox, oy). `stride` None = 1D tile
    mapping, else 2D mapping with `stride` tiles per row (32 for the GBA's 2D OBJ layout).
    Later entries are drawn first, as Sprite_DrawWithMode queues them back to front."""
    px = img.load()
    for a0, a1, a2 in reversed(objs):
        w, h = OBJ_SIZES.get((a0 >> 14, a1 >> 14), (8, 8))
        y = a0 & 0xFF
        y = y - 256 if y >= 128 else y
        x = a1 & 0x1FF
        x = x - 512 if x >= 256 else x
        hf = not (a0 & 0x100) and a1 & 0x1000
        vf = not (a0 & 0x100) and a1 & 0x2000
        t0 = (a2 & 0x3FF) - tile_base
        tw = w // 8
        for ty in range(h // 8):
            for tx in range(tw):
                tp = tile_pixels(tiles, t0 + ty * (stride or tw) + tx)
                if tp is None:
                    continue
                for yy in range(8):
                    for xx in range(8):
                        v = tp[yy][xx]
                        if not v:
                            continue
                        dx = tx * 8 + xx
                        dy = ty * 8 + yy
                        if hf:
                            dx = w - 1 - dx
                        if vf:
                            dy = h - 1 - dy
                        X, Y = ox + x + dx, oy + y + dy
                        if 0 <= X < img.width and 0 <= Y < img.height:
                            px[X, Y] = palette[v]


def bounds(objs):
    """Bounding box (x0, y0, x1, y1) of OAM objects relative to the sprite origin."""
    xs, ys = [0], [0]
    for a0, a1, _ in objs:
        w, h = OBJ_SIZES.get((a0 >> 14, a1 >> 14), (8, 8))
        y = a0 & 0xFF
        y = y - 256 if y >= 128 else y
        x = a1 & 0x1FF
        x = x - 512 if x >= 256 else x
        xs += [x, x + w]
        ys += [y, y + h]
    return min(xs), min(ys), max(xs), max(ys)


# --------------------------------------------------------------------------- demons

DEMON_TABLE = 0x0872C774          # 0x1C-byte records, Demon_GetGfxRecord (0x080E444C)
DEMON_RECORDS = 388               # 380 ids + the variants at 0x0872F104 (id 0x12D/0x12E)


def demon_record(rom: Rom, i: int):
    r = DEMON_TABLE + i * 0x1C
    return {"addr": r, "flags": rom.u32(r), "palette": rom.u32(r + 4), "anim": rom.u32(r + 8),
            "gfx": [rom.u32(r + 0xC + 4 * k) for k in range(4)]}


def anim_frames(rom: Rom, anim: int):
    """Animation: u16 w, u16 h, then (sprite def *, u32 duration) pairs ended by 0xFFFFFFFF.
    The +4 word points at the first pair (normally anim + 8)."""
    p = rom.u32(anim + 4)
    out = []
    while len(out) < 32:
        d = rom.u32(p)
        if d == 0xFFFFFFFF or not (BASE <= d < BASE + len(rom.b)):
            break
        out.append((d, rom.u32(p + 4)))
        p += 8
    return out


def demons():
    from PIL import Image
    rom = Rom()
    out = PREVIEWS / "demons"
    out.mkdir(parents=True, exist_ok=True)
    for i in range(DEMON_RECORDS):
        rec = demon_record(rom, i)
        pal = rom.palette(rec["palette"])
        frames = anim_frames(rom, rec["anim"])
        # +0x0C = OBJ tiles 0-127 (VRAM rows 0-3 of the 2D layout), +0x14 = tiles 128-255
        tiles = b"".join(rom.decode(g) for g in (rec["gfx"][0], rec["gfx"][2]) if g)
        x0, y0, x1, y1 = bounds([o for d, _ in frames for o in cells(rom, rom.u32(d))])
        W, H = x1 - x0 + 4, y1 - y0 + 4
        sheet = Image.new("RGB", (W * max(1, len(frames)), H), pal[0])
        for fi, (d, _) in enumerate(frames):
            draw_cells(sheet, tiles, pal, cells(rom, rom.u32(d)), fi * W + 2 - x0, 2 - y0, stride=32)
        sheet.save(out / f"demon_{i:03d}.png")
    print(f"{DEMON_RECORDS} demon previews in {out}")


# --------------------------------------------------------------------------- characters

CHAR_TABLE = 0x08568D78           # 0x2C-byte records, Char_GetRecord (0x080D95F4)
CHAR_RECORDS = 474
CHAR_DEF = 0x08004FF8             # default sprite definition (0x080C43B4): 80x96 from OBJ tile 0x300


def char_record(rom: Rom, i: int):
    r = CHAR_TABLE + i * 0x2C
    return {"addr": r, "type": rom.u32(r), "gfx": [rom.u32(r + 4 + 4 * k) for k in range(8)],
            "palette": rom.u32(r + 0x24), "extra": rom.u32(r + 0x28)}


def char_anim(rom: Rom, a: int):
    """Character animation: 0x18-byte frames {gfx half 0, gfx half 1, sprite def, u16 duration
    (0xFFFF end, 0xFFFE loop), u16 tile base, u16 palette, u16 reload flag, u16 sound}."""
    out = []
    while len(out) < 64:
        dur = rom.u16(a + 0xC)
        if dur in (0xFFFF, 0xFFFE):
            break
        out.append({"addr": a, "gfx": (rom.u32(a), rom.u32(a + 4)), "def": rom.u32(a + 8), "dur": dur})
        a += 0x18
    return out


def char_tiles(rom: Rom, halves):
    t = b""
    for g in halves:
        d = rom.decode(g) if g else b""
        t += d + bytes(max(0, 0x800 - len(d)))
    return t


def characters():
    from PIL import Image
    rom = Rom()
    out = PREVIEWS / "characters"
    out.mkdir(parents=True, exist_ok=True)
    objs = cells(rom, rom.u32(CHAR_DEF))
    x0, y0, x1, y1 = bounds(objs)
    W, H = x1 - x0 + 4, y1 - y0 + 4
    for i in range(CHAR_RECORDS):
        rec = char_record(rom, i)
        if not rec["palette"]:
            continue
        pal = rom.palette(rec["palette"])
        poses = [(rec["gfx"][2 * k], rec["gfx"][2 * k + 1]) for k in range(4) if rec["gfx"][2 * k]]
        if not poses:
            continue
        sheet = Image.new("RGB", (W * len(poses), H), pal[0])
        for k, halves in enumerate(poses):
            draw_cells(sheet, char_tiles(rom, halves), pal, objs, k * W + 2 - x0, 2 - y0,
                       tile_base=0x300, stride=32)
        sheet.save(out / f"char_{i:03d}.png")
    print(f"character previews in {out}")


def main():
    what = sys.argv[1:] or ["demons"]
    for w in what:
        {"demons": demons, "characters": characters}[w]()


if __name__ == "__main__":
    main()
