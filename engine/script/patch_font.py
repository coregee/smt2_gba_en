"""Build the canonical main font file and inject it through the ROM bank table."""

try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *

from font.atlas import replacement_characters
from font.script.font_codec import (
    MAIN_RECORD_SIZE,
    decode_main_glyph,
    decode_main_record,
    inject_main_file,
    main_file_from_rom,
)
from font.script.repack import build_main_font, load_config


def apply(p):
    config = load_config("main")
    glyph_count = config["glyph_count"]
    font_data = build_main_font(bytes(p.rom))
    inject_main_file(p.rom, font_data, glyph_count)

    if main_file_from_rom(p.rom, glyph_count) != font_data:
        raise SystemExit("patch_font: injected font did not round-trip")
    for code in replacement_characters():
        record = font_data[code * MAIN_RECORD_SIZE:(code + 1) * MAIN_RECORD_SIZE]
        if decode_main_glyph(p.rom, code) != decode_main_record(record):
            raise SystemExit(f"patch_font: glyph 0x{code:04X} did not verify")
    print(f"font injected: {config['file']} ({glyph_count} glyphs)")
