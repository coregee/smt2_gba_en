#!/usr/bin/env python3
"""Keep the automap help legend aligned with the facility room labels.

The two-page legend opened with SELECT is not backed by the ASCII room-label
table at 0x08163444.  Its words are baked into four LZ77-compressed 4bpp OBJ
blocks loaded by the automap resource at 0x08162AB0.  Each ordinary legend
label occupies an eight-tile (64x8) strip.

Rebuild only the affected strips from glyph tiles already present in the
pristine sheets.  This preserves the stock block font, palette indices, OBJ
layout, and fixed VRAM destinations.  All four recompressed streams fit their
original padded slots, so no loader hook or repoint is needed.
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # noqa: F401,F403

from graphics.script import gbagfx


TILE_BYTES = 32
STRIP_TILES = 8
STRIP_BYTES = TILE_BYTES * STRIP_TILES

# Address -> padded compressed slot size.  The first three end exactly where
# the next block starts; the final stream is 0x23f bytes plus one pad byte.
BLOCKS = {
    0x081B33B8: 0x304,
    0x081B36BC: 0x2F8,
    0x081B39B4: 0x31C,
    0x081B3CD0: 0x240,
}

# (strip index, stock label, replacement).  Spaces are transparent tiles.
CHANGES = {
    0x081B33B8: [
        (5, "MESIA", "MESSIAN"),
        (9, "GAIA", "GAEAN"),
        (13, "KAIFUKU", "HEALER"),
    ],
    0x081B36BC: [
        (1, "JAKYOU", "FUSION"),
    ],
    0x081B39B4: [
        (8, "VIRTUALS", "VR"),
        (12, "IZUMI L", "SPRING L"),
    ],
    0x081B3CD0: [
        (0, "IZUMI N", "SPRING N"),
        (4, "IZUMI C", "SPRING C"),
    ],
}

# Canonical stock glyph occurrences: character -> (block, strip, tile).
# These cover every character in the stock/replacement labels.  Sourcing the
# pixels from the sheets avoids introducing a second rendering/font contract.
GLYPH_SOURCES = {
    "A": (0x081B33B8, 5, 4),
    "C": (0x081B39B4, 0, 0),
    "E": (0x081B33B8, 5, 1),
    "F": (0x081B33B8, 13, 3),
    "G": (0x081B33B8, 9, 0),
    "H": (0x081B33B8, 4, 1),
    "I": (0x081B33B8, 5, 3),
    "J": (0x081B36BC, 1, 0),
    "K": (0x081B33B8, 13, 0),
    "L": (0x081B33B8, 0, 1),
    "M": (0x081B33B8, 5, 0),
    "N": (0x081B33B8, 1, 5),
    "O": (0x081B33B8, 4, 2),
    "P": (0x081B33B8, 0, 0),
    "R": (0x081B33B8, 0, 5),
    "S": (0x081B33B8, 5, 2),
    "T": (0x081B33B8, 1, 0),
    "U": (0x081B33B8, 13, 4),
    "V": (0x081B39B4, 8, 0),
    "Y": (0x081B36BC, 1, 3),
    "Z": (0x081B39B4, 12, 1),
}


def _tile(raw, strip, tile):
    start = (strip * STRIP_TILES + tile) * TILE_BYTES
    return bytes(raw[start:start + TILE_BYTES])


def _encode_strip(text, glyphs):
    if len(text) > STRIP_TILES:
        raise SystemExit(f"maphelp label {text!r} exceeds its {STRIP_TILES}-tile strip")
    tiles = [glyphs[c] for c in text]
    tiles.extend([glyphs[" "]] * (STRIP_TILES - len(tiles)))
    return b"".join(tiles)


def apply(p):
    raws = {}
    for addr, slot in BLOCKS.items():
        decoded = gbagfx.lz77_decompress(p.rom, addr - B)
        if decoded is None:
            raise SystemExit(f"maphelp: invalid LZ77 stream @0x{addr:08X}")
        raw, used = decoded
        if used > slot or len(raw) % STRIP_BYTES:
            raise SystemExit(
                f"maphelp: unexpected block layout @0x{addr:08X} "
                f"(raw={len(raw):#x}, compressed={used:#x}, slot={slot:#x})"
            )
        raws[addr] = bytearray(raw)

    glyphs = {" ": bytes(TILE_BYTES)}
    for char, (addr, strip, tile) in GLYPH_SOURCES.items():
        glyphs[char] = _tile(raws[addr], strip, tile)

    changed = 0
    for addr, edits in CHANGES.items():
        raw = raws[addr]
        for strip, old, new in edits:
            start = strip * STRIP_BYTES
            got = bytes(raw[start:start + STRIP_BYTES])
            expected = _encode_strip(old, glyphs)
            if got != expected:
                raise SystemExit(
                    f"maphelp: stock strip drift @0x{addr:08X}[{strip}] "
                    f"(expected {old!r})"
                )
            raw[start:start + STRIP_BYTES] = _encode_strip(new, glyphs)
            changed += 1

    for addr, slot in BLOCKS.items():
        encoded = gbagfx.lz77_compress(bytes(raws[addr]))
        if len(encoded) > slot:
            raise SystemExit(
                f"maphelp: recompressed block @0x{addr:08X} exceeds its slot "
                f"({len(encoded):#x} > {slot:#x})"
            )
        p.write(addr, encoded.ljust(slot, b"\x00"))
        print(f"  maphelp: legend sprites @0x{addr:08X} ({len(encoded):#x}/{slot:#x})")

    print(f"  maphelp: {changed} facility labels synchronized")
