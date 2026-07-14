from __future__ import annotations

import hashlib
import unittest

from font.atlas import GLYPH_MAP, replacement_characters
from font.script.font_codec import (
    decode_main_record,
    decode_small_cell,
    encode_main_record,
    encode_small_cell,
)
from font.script.repack import build_fonts
from paths import ProjectPaths


class FontPipelineTests(unittest.TestCase):
    def test_main_codec_round_trip(self) -> None:
        grid = [[(x + y) & 3 for x in range(16)] for y in range(16)]
        self.assertEqual(decode_main_record(encode_main_record(grid)), grid)

    def test_small_codec_round_trip(self) -> None:
        grid = [[(x + y) & 15 for x in range(8)] for y in range(8)]
        self.assertEqual(decode_small_cell(encode_small_cell(grid)), grid)

    def test_replacements_agree_with_atlas(self) -> None:
        replacements = replacement_characters()
        self.assertEqual(len(replacements), 75)
        for code, character in replacements.items():
            self.assertEqual(GLYPH_MAP[code], character)

    def test_repacked_font_hashes(self) -> None:
        source = ProjectPaths.discover().source_rom
        if not source.is_file():
            self.skipTest("source ROM is not present")
        fonts = build_fonts(source.read_bytes(), write=False)
        expected = {
            "main": "74E0C782912ED10D69FCD98D04264EA34BC073235D8568610A54659F0F963045",
            "small8": "47B41A624E6FDEC3BEBB582B09602444FFF33DFEFABCD0513EF5DC855A311092",
        }
        self.assertEqual(
            {name: hashlib.sha256(data).hexdigest().upper() for name, data in fonts.items()},
            expected,
        )


if __name__ == "__main__":
    unittest.main()
