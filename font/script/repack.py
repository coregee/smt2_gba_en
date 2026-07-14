"""Build injectable font files and original/replaced atlas previews."""

from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path

from PIL import Image, ImageDraw, ImageFont

if __package__ in (None, ""):
    import sys

    sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from font.atlas import replacement_characters
from font.script.font_codec import (
    MAIN_RECORD_SIZE,
    SMALL_CELL_SIZE,
    decode_main_record,
    decode_small_cell,
    encode_main_record,
    encode_small_cell,
    inject_main_file,
    main_file_from_rom,
    main_glyph_offset,
    render_atlas,
    small_cell_offset,
)
from paths import ProjectPaths


PATHS = ProjectPaths.discover()
CONFIG_ROOT = PATHS.font_config_root
PAD = 32


def load_config(name: str) -> dict:
    path = CONFIG_ROOT / f"{name}.json"
    document = json.loads(path.read_text(encoding="utf-8"))
    if not isinstance(document, dict):
        raise ValueError(f"{path}: expected an object")
    return document


def _code(value: int | str) -> int:
    return int(value, 0) if isinstance(value, str) else value


def expand_replacements(config: dict) -> dict[int, str]:
    replacements: dict[int, str] = {}
    for row in config["replacements"]:
        if "start" in row:
            entries = enumerate(row["characters"], _code(row["start"]))
        else:
            entries = ((_code(code), character) for code, character in row["map"].items())
        for code, character in entries:
            if code in replacements:
                raise ValueError(f"duplicate replacement glyph 0x{code:04X}")
            replacements[code] = character
    return replacements


def _main_baseline_source_y(font: ImageFont.FreeTypeFont, baseline_row: int) -> int:
    image = Image.new("L", (64 + 2 * PAD, 64 + 2 * PAD), 0)
    ImageDraw.Draw(image).text((PAD, PAD), "H", fill=255, font=font)
    bounds = image.getbbox()
    if bounds is None:
        raise ValueError("main font cannot render the baseline probe")
    return bounds[3] - 1 - baseline_row


def _render_main_character(
    font: ImageFont.FreeTypeFont,
    character: str,
    options: dict,
) -> list[list[int]]:
    character = options.get("substitutions", {}).get(character, character)
    image = Image.new("L", (16 + 4 * PAD, 16 + 4 * PAD), 0)
    ImageDraw.Draw(image).text((2 * PAD, PAD), character, fill=255, font=font)
    bounds = image.getbbox()
    grid = [[0] * 16 for _ in range(16)]
    if bounds is None:
        return grid

    source_x = bounds[0] - options["left"]
    source_y = _main_baseline_source_y(font, options["baseline_row"])
    body = options["body"]
    for y in range(16):
        for x in range(16):
            sx, sy = source_x + x, source_y + y
            if 0 <= sx < image.width and 0 <= sy < image.height and image.getpixel((sx, sy)) >= 128:
                grid[y][x] = body

    shadow = options["shadow"]
    output = [row[:] for row in grid]
    for y in range(15):
        for x in range(16):
            if grid[y][x] == body and grid[y + 1][x] == 0:
                output[y + 1][x] = shadow
    return output


def build_main_font(rom: bytes | bytearray) -> bytes:
    """Repack the complete main font into code-indexed 64-byte records."""
    config = load_config("main")
    glyph_count = config["glyph_count"]
    output = bytearray(main_file_from_rom(rom, glyph_count))
    options = config["font_file"]
    source = (CONFIG_ROOT / options["source"]).resolve()
    font = ImageFont.truetype(str(source), options["size"])
    replacements = replacement_characters()

    physical_aliases: dict[int, list[int]] = {}
    for code in range(glyph_count):
        physical_aliases.setdefault(main_glyph_offset(rom, code), []).append(code)

    def put(code: int, record: bytes) -> None:
        for alias in physical_aliases[main_glyph_offset(rom, code)]:
            output[alias * MAIN_RECORD_SIZE:(alias + 1) * MAIN_RECORD_SIZE] = record

    for code in map(_code, config["blank_glyphs"]):
        put(code, encode_main_record([[0] * 16 for _ in range(16)]))
    for code, character in replacements.items():
        grid = _render_main_character(font, character, options)
        put(code, encode_main_record(grid))
    return bytes(output)


def _render_small_character(
    font: ImageFont.FreeTypeFont,
    character: str,
    options: dict,
) -> list[list[int]]:
    ascent, _ = font.getmetrics()
    baseline = (
        options["descender_baseline_row"]
        if character in options["descenders"]
        else options["baseline_row"]
    )
    pad = 16
    image = Image.new("L", (8 + 2 * pad, 8 + 2 * pad), 0)
    ImageDraw.Draw(image).text((pad, pad + baseline - ascent), character, fill=255, font=font)
    bounds = image.getbbox()
    grid = [[0] * 8 for _ in range(8)]
    if bounds is None:
        return grid
    source_x = bounds[0]
    for y in range(8):
        for x in range(8):
            sx, sy = source_x + x, pad + y
            if 0 <= sx < image.width and 0 <= sy < image.height and image.getpixel((sx, sy)) >= 128:
                grid[y][x] = options["body"]
    return grid


def original_small_font(rom: bytes | bytearray) -> bytes:
    config = load_config("small8")
    copied = config["copied_cells"]
    offset = small_cell_offset(config["source_cell"])
    return bytes(rom[offset:offset + copied * SMALL_CELL_SIZE])


def build_small_font(rom: bytes | bytearray) -> bytes:
    """Build the relocated 8px cells followed by their index-addressed widths."""
    config = load_config("small8")
    replacements = expand_replacements(config)
    glyph_count = max(config["copied_cells"], max(replacements) + 1)
    cells = bytearray(glyph_count * SMALL_CELL_SIZE)
    original = original_small_font(rom)
    cells[:len(original)] = original

    options = config["font_file"]
    source = (CONFIG_ROOT / options["source"]).resolve()
    font = ImageFont.truetype(str(source), options["size"])
    for index, character in replacements.items():
        record = encode_small_cell(_render_small_character(font, character, options))
        cells[index * SMALL_CELL_SIZE:(index + 1) * SMALL_CELL_SIZE] = record

    widths = bytearray()
    for index in range(glyph_count):
        record = cells[index * SMALL_CELL_SIZE:(index + 1) * SMALL_CELL_SIZE]
        grid = decode_small_cell(record)
        ink = [x for x in range(8) if any(row[x] for row in grid)]
        widths.append(min(ink[-1] + 2, 8) if ink else 4)
    return bytes(cells + widths)


def validate_fonts(rom: bytes | bytearray, main: bytes, small: bytes) -> None:
    main_config = load_config("main")
    glyph_count = main_config["glyph_count"]
    if len(main) != glyph_count * MAIN_RECORD_SIZE:
        raise ValueError("main font has the wrong size")
    injected = bytearray(rom)
    inject_main_file(injected, main, glyph_count)
    if main_file_from_rom(injected, glyph_count) != main:
        raise ValueError("main font did not survive ROM injection")

    small_config = load_config("small8")
    small_count = max(small_config["copied_cells"], max(expand_replacements(small_config)) + 1)
    expected = small_count * SMALL_CELL_SIZE + small_count
    if len(small) != expected:
        raise ValueError(f"small font is {len(small)} bytes; expected {expected}")


def write_outputs(rom: bytes | bytearray, main: bytes, small: bytes) -> None:
    PATHS.font_build_root.mkdir(parents=True, exist_ok=True)
    PATHS.font_atlas_root.mkdir(parents=True, exist_ok=True)
    main_config = load_config("main")
    small_config = load_config("small8")

    (PATHS.font_build_root / main_config["file"]).write_bytes(main)
    (PATHS.font_build_root / small_config["file"]).write_bytes(small)

    original_main = main_file_from_rom(rom, main_config["glyph_count"])
    main_atlas = main_config["atlas"]
    for suffix, data in (("original", original_main), ("replaced", main)):
        render_atlas(
            data,
            glyph_count=main_config["glyph_count"],
            record_size=MAIN_RECORD_SIZE,
            width=16,
            height=16,
            columns=main_atlas["columns"],
            scale=main_atlas["scale"],
            decoder=decode_main_record,
        ).save(PATHS.font_atlas_root / f"main_{suffix}.png")

    replacements = expand_replacements(small_config)
    small_count = max(small_config["copied_cells"], max(replacements) + 1)
    original_small = original_small_font(rom).ljust(small_count * SMALL_CELL_SIZE, b"\0")
    replaced_small = small[:small_count * SMALL_CELL_SIZE]
    small_atlas = small_config["atlas"]
    for suffix, data in (("original", original_small), ("replaced", replaced_small)):
        render_atlas(
            data,
            glyph_count=small_count,
            record_size=SMALL_CELL_SIZE,
            width=8,
            height=8,
            columns=small_atlas["columns"],
            scale=small_atlas["scale"],
            decoder=decode_small_cell,
        ).save(PATHS.font_atlas_root / f"small8_{suffix}.png")


def build_fonts(rom: bytes | bytearray, *, write: bool) -> dict[str, bytes]:
    main = build_main_font(rom)
    small = build_small_font(rom)
    validate_fonts(rom, main, small)
    if write:
        write_outputs(rom, main, small)
    return {"main": main, "small8": small}


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true", help="validate without writing files or atlases")
    arguments = parser.parse_args()
    try:
        rom = PATHS.source_rom.read_bytes()
        fonts = build_fonts(rom, write=not arguments.check)
        action = "validated" if arguments.check else "built"
        for name, data in fonts.items():
            digest = hashlib.sha256(data).hexdigest().upper()
            print(f"{action} {name}: {len(data)} bytes; SHA-256 {digest}")
        if not arguments.check:
            print(f"font files: {PATHS.font_build_root}")
            print(f"atlases: {PATHS.font_atlas_root}")
    except (FileNotFoundError, json.JSONDecodeError, OSError, TypeError, ValueError) as error:
        parser.error(str(error))


if __name__ == "__main__":
    main()
