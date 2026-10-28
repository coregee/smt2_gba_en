#!/usr/bin/env python3
"""ROM assets as editable files, rebuilt byte for byte.

    python tools/assets/assets.py init      manifest from the data scan (keeps existing entries)
    python tools/assets/assets.py extract   ROM -> assets/ files (PNG, .pal, .bin)
    python tools/assets/assets.py build     assets/ files -> build/assets/*.bin (what the
                                            data sources .incbin; the ROM sha1 check proves
                                            every asset round-trips)

assets/manifest.json lists one entry per asset:
    name    file stem under assets/ (family folder + name)
    addr    ROM address;  len: bytes it occupies in the ROM (stream + zero padding)
    codec   lz77 | huff | huff+lz77 | rle | raw   (BIOS formats; huff+lz77 = an LZ77 stream
            Huffman-coded again, as the area graphics loader 0x080B3C5C reads them)
    inner_len  huff+lz77 only: length of the inner LZ77 stream as stored
    tree    Huffman only: the original serialized tree, so unedited data re-encodes exactly
    format  4bpp | 8bpp | pal | bin       content of the decompressed data
    width   4bpp/8bpp: image width in tiles
    palette name of a pal asset used for the PNG colours (else a grey ramp)
"""
from __future__ import annotations

import json
import struct
import sys
import zlib
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))
import bios  # noqa: E402

ROOT = HERE.parents[1]
MANIFEST = ROOT / "assets" / "manifest.json"
OUT = ROOT / "build" / "assets"
BASE = 0x08000000
TEXT_START, TEXT_END = 0x080A96CC, 0x0815E828


# --------------------------------------------------------------------------- PNG (indexed)

def _chunk(tag, data):
    return struct.pack(">I", len(data)) + tag + data + struct.pack(">I", zlib.crc32(tag + data))


def write_png(path: Path, pixels: list, width: int, palette: list, bits: int):
    """Indexed PNG; `pixels` rows of palette indices; palette as (r, g, b)."""
    h = len(pixels)
    raw = bytearray()
    for row in pixels:
        raw.append(0)
        if bits == 4:
            for x in range(0, width, 2):
                raw.append((row[x] << 4) | (row[x + 1] if x + 1 < width else 0))
        else:
            raw += bytes(row)
    plte = b"".join(bytes(c) for c in palette)
    png = b"\x89PNG\r\n\x1a\n" + _chunk(b"IHDR", struct.pack(">IIBBBBB", width, h, bits, 3, 0, 0, 0))
    png += _chunk(b"PLTE", plte) + _chunk(b"IDAT", zlib.compress(bytes(raw), 9)) + _chunk(b"IEND", b"")
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes(png)


def read_png(path: Path):
    """-> (width, height, rows of indices) for an indexed PNG (bit depth 4 or 8)."""
    data = path.read_bytes()
    p = 8
    idat = b""
    while p < len(data):
        ln = struct.unpack(">I", data[p:p + 4])[0]
        tag = data[p + 4:p + 8]
        body = data[p + 8:p + 8 + ln]
        if tag == b"IHDR":
            w, h, bits, ctype = struct.unpack(">IIBB", body[:10])
            if ctype != 3:
                raise ValueError(f"{path}: not an indexed PNG")
        elif tag == b"IDAT":
            idat += body
        p += 12 + ln
    raw = zlib.decompress(idat)
    stride = (w * bits + 7) // 8
    rows = []
    prev = bytearray(stride)
    q = 0
    for _ in range(h):
        f = raw[q]
        line = bytearray(raw[q + 1:q + 1 + stride])
        q += 1 + stride
        for i in range(stride):                       # undo PNG filters (editors may use them)
            a = line[i - 1] if i else 0
            b = prev[i]
            c = prev[i - 1] if i else 0
            if f == 1:
                line[i] = (line[i] + a) & 0xFF
            elif f == 2:
                line[i] = (line[i] + b) & 0xFF
            elif f == 3:
                line[i] = (line[i] + (a + b) // 2) & 0xFF
            elif f == 4:
                pa, pb, pc = abs(b - c), abs(a - c), abs(a + b - 2 * c)
                line[i] = (line[i] + (a if pa <= pb and pa <= pc else b if pb <= pc else c)) & 0xFF
        prev = line
        if bits == 4:
            row = []
            for byte in line:
                row += [byte >> 4, byte & 0xF]
            rows.append(row[:w])
        else:
            rows.append(list(line[:w]))
    return w, h, rows


# --------------------------------------------------------------------------- tiles / palettes

def tiles_to_rows(data: bytes, width_tiles: int, bpp: int):
    tsize = 8 * bpp
    n = len(data) // tsize
    htiles = (n + width_tiles - 1) // width_tiles
    W, H = width_tiles * 8, htiles * 8
    rows = [[0] * W for _ in range(H)]
    for t in range(n):
        tx, ty = (t % width_tiles) * 8, (t // width_tiles) * 8
        tile = data[t * tsize:(t + 1) * tsize]
        for y in range(8):
            for x in range(8):
                if bpp == 4:
                    b = tile[y * 4 + x // 2]
                    v = (b >> 4) if x & 1 else (b & 0xF)
                else:
                    v = tile[y * 8 + x]
                rows[ty + y][tx + x] = v
    return rows, n


def rows_to_tiles(rows, width_tiles: int, ntiles: int, bpp: int) -> bytes:
    out = bytearray()
    for t in range(ntiles):
        tx, ty = (t % width_tiles) * 8, (t // width_tiles) * 8
        for y in range(8):
            r = rows[ty + y]
            if bpp == 4:
                for x in range(0, 8, 2):
                    out.append((r[tx + x] & 0xF) | (r[tx + x + 1] & 0xF) << 4)
            else:
                out += bytes(r[tx:tx + 8])
    return bytes(out)


def bgr555(data: bytes):
    cols = []
    for i in range(0, len(data) - 1, 2):
        v = data[i] | data[i + 1] << 8
        cols.append(((v & 31) * 255 // 31, ((v >> 5) & 31) * 255 // 31, ((v >> 10) & 31) * 255 // 31,
                     v >> 15))
    return cols


def write_pal(path: Path, data: bytes):
    """JASC-PAL with the exact 15-bit values in a trailing comment column (bit 15 kept)."""
    lines = ["JASC-PAL", "0100", str(len(data) // 2)]
    for i in range(0, len(data) - 1, 2):
        v = data[i] | data[i + 1] << 8
        r, g, b = (v & 31) << 3, ((v >> 5) & 31) << 3, ((v >> 10) & 31) << 3
        lines.append(f"{r} {g} {b}" + (" ; bit15" if v & 0x8000 else ""))
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text("\n".join(lines) + "\n", newline="\n")


def read_pal(path: Path) -> bytes:
    out = bytearray()
    for ln in path.read_text().splitlines()[3:]:
        if not ln.strip():
            continue
        body, _, note = ln.partition(";")
        r, g, b = (int(x) for x in body.split())
        v = (r >> 3) | (g >> 3) << 5 | (b >> 3) << 10 | (0x8000 if "bit15" in note else 0)
        out += struct.pack("<H", v)
    return bytes(out)


GREY = [(i * 17, i * 17, i * 17) for i in range(16)]
GREY256 = [(i, i, i) for i in range(256)]


# --------------------------------------------------------------------------- manifest

def load_manifest():
    if MANIFEST.exists():
        return json.loads(MANIFEST.read_text())
    return {"assets": []}


def save_manifest(m):
    m["assets"].sort(key=lambda e: int(e["addr"], 16))
    lines = ["{", '  "assets": [']
    rows = [json.dumps(e, separators=(", ", ": ")) for e in m["assets"]]
    lines.append(",\n".join("    " + r for r in rows))
    lines += ["  ]", "}"]
    MANIFEST.parent.mkdir(parents=True, exist_ok=True)
    MANIFEST.write_text("\n".join(lines) + "\n", newline="\n")


def family(addr: int) -> str:
    return f"rom_{addr >> 16 << 16:08X}"


def init():
    rom = (ROOT / "baserom.gba").read_bytes()
    dm = json.loads((ROOT / "build" / "datamap.json").read_text())
    m = load_manifest()
    have = {int(e["addr"], 16) for e in m["assets"]}
    taken = []
    for e in m["assets"]:
        a = int(e["addr"], 16)
        taken.append((a, a + e["len"]))
    added = 0
    for s in dm["streams"]:
        a = s["addr"]
        if a in have:
            continue
        # Streams inside the text-heavy region before the program are coincidences unless the
        # code itself loads them.
        if a < TEXT_START and not s["code_refs"]:
            continue
        o = a - BASE
        clen = s["clen"]
        ln = clen
        pad = (-clen) % 4
        if not any(rom[o + clen:o + clen + pad]):
            ln += pad
        if any(lo < a + ln and a < hi for lo, hi in taken):
            continue
        t = s["type"]
        e = {"name": f"{family(a)}/{a:08X}", "addr": f"0x{a:08X}", "len": ln}
        raw = bios.decode(rom, o)[0]
        if t == 0x10:
            e["codec"] = "lz77"
            ok = bios.lz77_compress(raw)[:clen] == rom[o:o + clen]
        elif t in (0x24, 0x28):
            e["codec"] = "huff"
            e["bits"] = t & 0xF
            e["tree"] = bios.huffman_tree(rom, o).hex()
            try:
                ok = bios.huffman_compress(raw, bytes.fromhex(e["tree"]), t & 0xF)[:clen] == rom[o:o + clen]
            except (KeyError, IndexError):
                ok = False
        else:
            e["codec"] = "rle"
            ok = False
        if not ok:
            e = {"name": e["name"], "addr": e["addr"], "len": ln, "codec": "raw", "format": "bin",
                 "note": f"BIOS type 0x{t:02X} stream kept compressed (no exact re-encoder yet)"}
        elif len(raw) % 32 == 0:
            e["format"] = "4bpp"
            e["width"] = 32 if len(raw) >= 32 * 32 * 4 else 16
            e["note"] = "format guessed from size; palette unknown"
        else:
            e["format"] = "bin"
        m["assets"].append(e)
        taken.append((a, a + ln))
        added += 1
    save_manifest(m)
    print(f"{added} assets added, {len(m['assets'])} in manifest")


# --------------------------------------------------------------------------- extract / build

def asset_path(e, ext=None):
    if ext is None:
        ext = {"4bpp": ".png", "8bpp": ".png", "pal": ".pal"}.get(e["format"], ".bin")
    return ROOT / "assets" / (e["name"] + ext)


def palette_for(e, by_name, rom):
    p = e.get("palette")
    if p and p in by_name:
        pe = by_name[p]
        o = int(pe["addr"], 16) - BASE
        cols = bgr555(rom[o:o + pe["len"]])
        base = e.get("palette_index", 0) * 16
        cols = cols[base:base + (16 if e["format"] == "4bpp" else 256)]
        return [(r, g, b) for r, g, b, _ in cols]
    return GREY if e["format"] == "4bpp" else GREY256


def payload(e, rom):
    """The decompressed (or raw) bytes of an asset as it is in the base ROM."""
    o = int(e["addr"], 16) - BASE
    if e["codec"] == "raw":
        return rom[o:o + e["len"]]
    data = bios.decode(rom, o)[0]
    if e["codec"] == "huff+lz77":                  # Huffman around an LZ77 stream
        data = bios.lz77(data, 0)[0]
    return data


def extract_one(e, rom, by_name):
    data = payload(e, rom)
    fmt = e["format"]
    if fmt in ("4bpp", "8bpp"):
        bpp = 4 if fmt == "4bpp" else 8
        rows, n = tiles_to_rows(data, e["width"], bpp)
        write_png(asset_path(e), rows, e["width"] * 8, palette_for(e, by_name, rom), bpp)
    elif fmt == "pal":
        write_pal(asset_path(e), data)
    else:
        p = asset_path(e)
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_bytes(data)


def encode_one(e):
    """Asset file -> the exact bytes it occupies in the ROM."""
    fmt = e["format"]
    if fmt in ("4bpp", "8bpp"):
        bpp = 4 if fmt == "4bpp" else 8
        w, h, rows = read_png(asset_path(e))
        ntiles = e["tiles"]
        data = rows_to_tiles(rows, e["width"], ntiles, bpp)
    elif fmt == "pal":
        data = read_pal(asset_path(e))
    else:
        data = asset_path(e).read_bytes()
    c = e["codec"]
    if c == "lz77":
        out = bios.lz77_compress(data)
    elif c in ("huff", "huff+lz77"):
        if c == "huff+lz77":
            data = bios.lz77_compress(data)
            n = e["inner_len"]                     # the LZ77 stream as stored (with padding)
            data = data[:n] + bytes(max(0, n - len(data)))
        tree = bytes.fromhex(e["tree"])
        try:
            out = bios.huffman_compress(data, tree, e.get("bits", 4))
        except KeyError:
            raise SystemExit(f"{e['name']}: edited data needs a new Huffman tree (not implemented)")
    elif c == "raw":
        out = data
    else:
        raise SystemExit(f"{e['name']}: no encoder for codec {c}")
    if len(out) > e["len"]:
        if len(out) - e["len"] < 4 and not any(out[e["len"]:]):
            out = out[:e["len"]]
        else:
            raise SystemExit(f"{e['name']}: re-encoded size {len(out):#x} exceeds its slot {e['len']:#x}")
    return out + bytes(e["len"] - len(out))


def extract():
    rom = (ROOT / "baserom.gba").read_bytes()
    m = load_manifest()
    by_name = {e["name"]: e for e in m["assets"]}
    for e in m["assets"]:
        if e["format"] in ("4bpp", "8bpp"):
            e["tiles"] = len(payload(e, rom)) // (32 if e["format"] == "4bpp" else 64)
        extract_one(e, rom, by_name)
    save_manifest(m)
    print(f"extracted {len(m['assets'])} assets to {ROOT / 'assets'}")


def _build_one(e):
    dst = OUT / f"{int(e['addr'], 16):08X}.bin"
    src = asset_path(e)
    if dst.exists() and dst.stat().st_mtime >= src.stat().st_mtime and \
            dst.stat().st_mtime >= MANIFEST.stat().st_mtime:
        return None
    dst.write_bytes(encode_one(e))
    return e["name"]


def build(verify=False):
    from concurrent.futures import ProcessPoolExecutor
    m = load_manifest()
    OUT.mkdir(parents=True, exist_ok=True)
    with ProcessPoolExecutor() as ex:
        done = [n for n in ex.map(_build_one, m["assets"], chunksize=16) if n]
    print(f"built {len(done)} changed assets ({len(m['assets'])} total)")
    if verify:
        rom = (ROOT / "baserom.gba").read_bytes()
        bad = 0
        for e in m["assets"]:
            o = int(e["addr"], 16) - BASE
            got = (OUT / f"{int(e['addr'], 16):08X}.bin").read_bytes()
            if got != rom[o:o + e["len"]]:
                bad += 1
                print("  differs from base ROM:", e["name"])
        print(f"{len(m['assets']) - bad}/{len(m['assets'])} assets identical to the base ROM")


def main():
    cmd = sys.argv[1] if len(sys.argv) > 1 else "build"
    if cmd == "init":
        init()
    elif cmd == "extract":
        extract()
    elif cmd == "build":
        build(verify="--verify" in sys.argv)
    else:
        raise SystemExit(__doc__)


if __name__ == "__main__":
    main()
