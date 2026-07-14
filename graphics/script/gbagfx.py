#!/usr/bin/env python3
"""GBA graphics codecs + the title/intro baked-image asset registry.

The title-screen / intro-attract module (module B, `0x080d6xxx..0x080dexxx`) and the
game-over (Charon) screen bake their text INTO tile graphics — they never touch the text
pipeline.  Localizing them = editing pixels.  This module holds:

  * the BIOS-compatible codecs those screens use:
      - LZ77 (SWI 0x11/0x12, type byte 0x10) — same format sprites.py handles
      - RLE  (SWI 0x14/0x15, type byte 0x30) — the title blocks are RLE *inside* LZ77
        (loader: `ldr r0,=src ; bl svc11_LZ77UnCompWram -> 0x02001000 ; bl svc14_RLUnComp
        -> 0x0200F874`, helpers @0x0815cafc/0x0815cb00/0x0815cb08)
      - 4bpp tile sheet <-> indexed pixel grid
  * ASSETS — every known baked-text block: ROM address, layering, PNG grid width, and
    the literal-pool sites that reference it (for relocation on repack).

Consumers: tools/titlegfx.py (dump to editable PNGs) and engine/script/patch_titlegfx.py
(re-encode edited PNGs into the build, relocating to FARDATA_TITLEGFX when the
recompressed stream outgrows its slot).
"""
import struct

import numpy as np

ROM_BASE = 0x08000000


# ---------------------------------------------------------------- LZ77 (BIOS type 0x10)
def lz77_decompress(rom, o):
    """Return (decompressed bytes, compressed length incl. header) for the block at
    offset `o`, or None if invalid.  Same algorithm as tools/sprites.py."""
    if o + 4 > len(rom) or rom[o] != 0x10:
        return None
    size = rom[o + 1] | (rom[o + 2] << 8) | (rom[o + 3] << 16)
    if size < 0x20 or size > 0x40000:
        return None
    out = bytearray()
    p = o + 4
    try:
        while len(out) < size:
            flags = rom[p]; p += 1
            for b in range(8):
                if len(out) >= size:
                    break
                if flags & (0x80 >> b):
                    hi, lo = rom[p], rom[p + 1]; p += 2
                    ln = (hi >> 4) + 3
                    disp = ((hi & 0xF) << 8 | lo) + 1
                    if disp > len(out):
                        return None
                    for _ in range(ln):
                        out.append(out[-disp])
                else:
                    out.append(rom[p]); p += 1
    except IndexError:
        return None
    if len(out) != size:
        return None
    return bytes(out), p - o


def lz77_compress(data):
    """Greedy LZ77 (type 0x10) with a 3-byte-prefix hash index.  Valid GBA BIOS input."""
    n = len(data)
    out = bytearray([0x10]) + struct.pack("<I", n)[:3]
    heads = {}
    i = 0
    while i < n:
        flag_at = len(out); out.append(0); flags = 0
        for b in range(8):
            if i >= n:
                break
            best_len, best_disp = 0, 0
            if i + 3 <= n:
                key = data[i:i + 3]
                cands = heads.get(key)
                if cands:
                    lo_i = i - 4096
                    for j in reversed(cands[-256:]):
                        if j < lo_i:
                            break
                        l = 0
                        m = min(18, n - i)
                        while l < m and data[j + l] == data[i + l]:
                            l += 1
                        if l > best_len:
                            best_len, best_disp = l, i - j
                            if l == 18:
                                break
            if best_len >= 3:
                hi = ((best_len - 3) << 4) | ((best_disp - 1) >> 8)
                out.append(hi); out.append((best_disp - 1) & 0xFF)
                flags |= (0x80 >> b)
                adv = best_len
            else:
                out.append(data[i]); adv = 1
            for k in range(i, i + adv):
                if k + 3 <= n:
                    heads.setdefault(data[k:k + 3], []).append(k)
            i += adv
        out[flag_at] = flags
    while len(out) % 4:
        out.append(0)
    return bytes(out)


# ---------------------------------------------------------------- RLE (BIOS type 0x30)
def rl_decompress(d):
    """Decode a BIOS RLUnComp stream (header 0x30 + 24-bit size)."""
    if d[0] & 0xF0 != 0x30:
        raise ValueError(f"not an RL stream (type byte {d[0]:#04x})")
    size = d[1] | d[2] << 8 | d[3] << 16
    out = bytearray()
    p = 4
    while len(out) < size:
        f = d[p]; p += 1
        if f & 0x80:                                   # compressed run: (len-3), value
            out += bytes([d[p]]) * ((f & 0x7F) + 3); p += 1
        else:                                          # literal run: (len-1), bytes
            n = (f & 0x7F) + 1
            out += d[p:p + n]; p += n
    return bytes(out[:size])


def rl_compress(data):
    """Encode a BIOS-compatible RLUnComp stream (runs >=3 compressed, max 130;
    literal chunks max 128), padded to 4 bytes."""
    out = bytearray([0x30]) + struct.pack("<I", len(data))[:3]
    lit = bytearray()

    def flush():
        j = 0
        while j < len(lit):
            chunk = lit[j:j + 0x80]
            out.append(len(chunk) - 1)
            out.extend(chunk)
            j += len(chunk)
        del lit[:]

    i, n = 0, len(data)
    while i < n:
        run = 1
        while i + run < n and data[i + run] == data[i] and run < 0x82:
            run += 1
        if run >= 3:
            flush()
            out.append(0x80 | (run - 3)); out.append(data[i])
        else:
            lit += data[i:i + run]
        i += run
    flush()
    while len(out) % 4:
        out.append(0)
    return bytes(out)


# ---------------------------------------------------------------- 4bpp tiles <-> grid
def tiles_to_image(data, width):
    """4bpp tile bytes -> (H*8, width*8) uint8 index array (row-major, low-nibble-first)."""
    n = len(data) // 32
    a = np.frombuffer(data[:n * 32], np.uint8).reshape(n, 8, 4)
    px = np.empty((n, 8, 8), np.uint8)
    px[:, :, 0::2] = a & 0xF
    px[:, :, 1::2] = a >> 4
    h = (n + width - 1) // width
    grid = np.zeros((h * width, 8, 8), np.uint8)
    grid[:n] = px
    return grid.reshape(h, width, 8, 8).transpose(0, 2, 1, 3).reshape(h * 8, width * 8)


def image_to_tiles(img, width, n):
    """Inverse of tiles_to_image -> 4bpp tile bytes for the first `n` tiles."""
    h = (n + width - 1) // width
    grid = img[:h * 8, :width * 8].reshape(h, 8, width, 8).transpose(0, 2, 1, 3).reshape(h * width, 8, 8)[:n]
    out = (grid[:, :, 0::2] & 0xF) | ((grid[:, :, 1::2] & 0xF) << 4)
    return out.astype(np.uint8).tobytes()


# ---------------------------------------------------------------- asset registry
# Each asset = one editable PNG.  `blocks` = the ROM LZ77 blocks that hold it, in
# concatenation order.  `wrap` = "lz77" (plain, like sprites.py) or "lz77+rle" (the
# title double-compression).  `refs` maps each block address to every literal-pool
# site holding that address (whole-ROM aligned-u32 scan, 2026-07-09) — rewritten if
# a repacked block relocates.  Widths: all these sheets read correctly at 32 tiles
# (256 px), matching their BG layout.
ASSETS = [
    dict(name="title_scroll", wrap="lz77+rle", width=32,
         blocks=[0x0850485C],
         refs={0x0850485C: [0x080D64BC]},
         note="opening narration crawl (20XX-nen TOKYO ...), 1024 tiles"),
    dict(name="title_screen", wrap="lz77+rle", width=32,
         blocks=[0x08508AC0],
         refs={0x08508AC0: [0x080D6560]},
         note="Shin Megami Tensei II logo + PRESS ANY BUTTON + menu + (c) line"),
    dict(name="title_menu", wrap="lz77", width=32,
         blocks=[0x081B5DD4],
         refs={0x081B5DD4: [0x080D66C4]},
         note="title text sheet variant (PRESS ANY BUTTON / MODE / SOUND / NEW GAME / CONTINUE)"),
    dict(name="charon_text", wrap="lz77", width=32,
         blocks=[0x084F89E0, 0x084F8FF0],
         refs={0x084F89E0: [0x080D5618], 0x084F8FF0: [0x080D5620]},
         note="game-over Charon speech (baked JP text; river scene bg = 084F4140.. is art)"),
    dict(name="intro_crawl_0", wrap="lz77", width=32,
         blocks=[0x0858689C], refs={0x0858689C: [0x080DE9F8]},
         note="intro attract: DDS-NET terminal boot text sheet"),
    dict(name="intro_crawl_1", wrap="lz77", width=32,
         blocks=[0x08587130], refs={0x08587130: [0x080DE138]},
         note="intro attract sheet"),
    dict(name="intro_crawl_2", wrap="lz77", width=32,
         blocks=[0x085874EC], refs={0x085874EC: [0x080DE160]},
         note="intro attract sheet"),
    dict(name="intro_crawl_3", wrap="lz77", width=32,
         blocks=[0x08588050], refs={0x08588050: [0x080DE180, 0x080DEA14]},
         note="intro attract sheet"),
    dict(name="intro_crawl_4", wrap="lz77", width=32,
         blocks=[0x085887D4], refs={0x085887D4: [0x080DE190, 0x080DEA24]},
         note="intro attract sheet"),
    dict(name="intro_crawl_5", wrap="lz77", width=32,
         blocks=[0x08588FA4], refs={0x08588FA4: [0x080DE1AC, 0x080DEA40]},
         note="intro attract sheet"),
    dict(name="intro_crawl_6", wrap="lz77", width=32,
         blocks=[0x0858979C], refs={0x0858979C: [0x080DE1EC, 0x080DEA80]},
         note="intro attract sheet"),
]


def decode_block(rom, addr):
    """Decode one asset block from a ROM image -> (raw tile bytes, comp slot length)."""
    r = lz77_decompress(rom, addr - ROM_BASE)
    if r is None:
        raise ValueError(f"no valid LZ77 block @{addr:08X}")
    return r


def decode_asset(rom, asset):
    """-> (concatenated raw tile bytes, [per-block raw sizes], [per-block comp slot sizes])."""
    raws, sizes, slots = [], [], []
    for addr in asset["blocks"]:
        data, comp_len = decode_block(rom, addr)
        if asset["wrap"] == "lz77+rle":
            data = rl_decompress(data)
        raws.append(data)
        sizes.append(len(data))
        slots.append(comp_len)
    return b"".join(raws), sizes, slots


def encode_block(raw, wrap):
    """Raw tile bytes -> compressed stream in the asset's wrapping."""
    if wrap == "lz77+rle":
        return lz77_compress(rl_compress(raw))
    return lz77_compress(raw)
