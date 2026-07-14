"""Codecs for SMT2's banked main font and linear 8px font."""

from __future__ import annotations

from PIL import Image


ROM_BASE = 0x08000000
FONT_BANK_TABLE_ADDR = 0x0815ED88
MAIN_GLYPH_WIDTH = 16
MAIN_GLYPH_HEIGHT = 16
MAIN_RECORD_SIZE = 0x40
SMALL_SHEET_ADDR = 0x081AD7B8
SMALL_CELL_SIZE = 0x20


def _read_u32(rom: bytes | bytearray, address: int) -> int:
    offset = address - ROM_BASE
    return int.from_bytes(rom[offset:offset + 4], "little")


def main_glyph_offset(rom: bytes | bytearray, code: int) -> int:
    """Resolve one glyph code through the ROM's bank pointer table."""
    high = (code >> 8) & 0xFF
    bank = _read_u32(rom, FONT_BANK_TABLE_ADDR + high * 8)
    row = (code & 0xFF) >> 4
    column = code & 0x0F
    return bank + row * 0x400 + column * 0x20 - ROM_BASE


def decode_2bpp_tile(tile: bytes) -> list[list[int]]:
    rows = []
    for y in range(8):
        word = int.from_bytes(tile[y * 2:y * 2 + 2], "big")
        rows.append([(word >> (14 - x * 2)) & 3 for x in range(8)])
    return rows


def encode_2bpp_tile(tile: list[list[int]]) -> bytes:
    output = bytearray(16)
    for y in range(8):
        word = 0
        for x in range(8):
            word |= (tile[y][x] & 3) << (14 - x * 2)
        output[y * 2:y * 2 + 2] = word.to_bytes(2, "big")
    return bytes(output)


def decode_main_record(record: bytes) -> list[list[int]]:
    if len(record) != MAIN_RECORD_SIZE:
        raise ValueError(f"main-font record must be {MAIN_RECORD_SIZE} bytes")
    tiles = [
        decode_2bpp_tile(record[0x00:0x10]),
        decode_2bpp_tile(record[0x10:0x20]),
        decode_2bpp_tile(record[0x20:0x30]),
        decode_2bpp_tile(record[0x30:0x40]),
    ]
    grid = [[0] * 16 for _ in range(16)]
    for y in range(8):
        for x in range(8):
            grid[y][x] = tiles[0][y][x]
            grid[y][x + 8] = tiles[1][y][x]
            grid[y + 8][x] = tiles[2][y][x]
            grid[y + 8][x + 8] = tiles[3][y][x]
    return grid


def encode_main_record(grid: list[list[int]]) -> bytes:
    if len(grid) != 16 or any(len(row) != 16 for row in grid):
        raise ValueError("main-font glyph must be a 16x16 grid")
    tile = lambda y, x: [row[x:x + 8] for row in grid[y:y + 8]]
    return b"".join(
        encode_2bpp_tile(tile(y, x))
        for y, x in ((0, 0), (0, 8), (8, 0), (8, 8))
    )


def main_record_from_rom(rom: bytes | bytearray, code: int) -> bytes:
    offset = main_glyph_offset(rom, code)
    return bytes(rom[offset:offset + 0x20] + rom[offset + 0x200:offset + 0x220])


def main_file_from_rom(rom: bytes | bytearray, glyph_count: int) -> bytes:
    return b"".join(main_record_from_rom(rom, code) for code in range(glyph_count))


def inject_main_file(rom: bytearray, font_data: bytes, glyph_count: int) -> None:
    expected = glyph_count * MAIN_RECORD_SIZE
    if len(font_data) != expected:
        raise ValueError(f"main font is {len(font_data)} bytes; expected {expected}")
    for code in range(glyph_count):
        record = font_data[code * MAIN_RECORD_SIZE:(code + 1) * MAIN_RECORD_SIZE]
        offset = main_glyph_offset(rom, code)
        rom[offset:offset + 0x20] = record[:0x20]
        rom[offset + 0x200:offset + 0x220] = record[0x20:]


def decode_main_glyph(rom: bytes | bytearray, code: int) -> list[list[int]]:
    return decode_main_record(main_record_from_rom(rom, code))


def small_cell_offset(index: int) -> int:
    return SMALL_SHEET_ADDR - ROM_BASE + index * SMALL_CELL_SIZE


def decode_small_cell(data: bytes) -> list[list[int]]:
    if len(data) != SMALL_CELL_SIZE:
        raise ValueError(f"small-font cell must be {SMALL_CELL_SIZE} bytes")
    grid = [[0] * 8 for _ in range(8)]
    for y in range(8):
        for x in range(8):
            value = data[y * 4 + (x >> 1)]
            grid[y][x] = value >> 4 if x & 1 else value & 0x0F
    return grid


def encode_small_cell(grid: list[list[int]]) -> bytes:
    if len(grid) != 8 or any(len(row) != 8 for row in grid):
        raise ValueError("small-font glyph must be an 8x8 grid")
    output = bytearray(SMALL_CELL_SIZE)
    for y in range(8):
        for x in range(8):
            value = grid[y][x] & 0x0F
            offset = y * 4 + (x >> 1)
            if x & 1:
                output[offset] |= value << 4
            else:
                output[offset] |= value
    return bytes(output)


def render_atlas(
    font_data: bytes,
    *,
    glyph_count: int,
    record_size: int,
    width: int,
    height: int,
    columns: int,
    scale: int,
    decoder,
) -> Image.Image:
    """Render a canonical font file as a compact grayscale atlas."""
    rows = (glyph_count + columns - 1) // columns
    atlas = Image.new("L", (columns * width, rows * height), 255)
    levels = {0: 255, 1: 110, 2: 0, 3: 175, 15: 0}
    pixels = atlas.load()
    for index in range(glyph_count):
        record = font_data[index * record_size:(index + 1) * record_size]
        grid = decoder(record)
        x0 = index % columns * width
        y0 = index // columns * height
        for y in range(height):
            for x in range(width):
                value = grid[y][x]
                pixels[x0 + x, y0 + y] = levels.get(value, 255 - value * 17)
    if scale != 1:
        atlas = atlas.resize((atlas.width * scale, atlas.height * scale), Image.Resampling.NEAREST)
    return atlas
