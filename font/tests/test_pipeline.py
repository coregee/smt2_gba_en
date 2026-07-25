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
from engine.script import patch_font, patch_vwf, rommap
from engine.script.rompatch import RomPatcher
from paths import ProjectPaths
from text.script import sections, tr


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

    def test_event_wrap_budget_is_shared_by_every_event_vm_section(self) -> None:
        event_sections = [
            section for section in sections.SECTIONS
            if section.page_glyphs and section.wrap_jp_pitch == 13
        ]
        self.assertTrue(event_sections)
        self.assertEqual(
            {section.wrap_px for section in event_sections},
            {rommap.EVENT_WRAP_PX},
        )

    def test_runtime_wrap_carries_width_across_negotiation_fragments(self) -> None:
        source = ProjectPaths.discover().source_rom
        if not source.is_file():
            self.skipTest("source ROM is not present")

        patcher = RomPatcher(bytearray(source.read_bytes()))
        patch_font.apply(patcher)
        advances = patch_vwf.measure_advances(patcher.rom)
        widths = bytearray([13]) * rommap.WIDTH_TABLE_SIZE
        for code, advance in advances.items():
            widths[code] = advance

        fragments = (
            "Even if you're just saying that...…",
            "I am glad. …",
        )
        encoded = tuple(
            [tr.CHAR2CODE[character] for character in fragment]
            for fragment in fragments
        )
        self.assertGreater(
            sum(widths[token] for fragment in encoded for token in fragment),
            rommap.EVENT_WRAP_PX,
        )

        placements = patch_vwf.simulate_runtime_fragments(encoded, widths)
        for token, col, _row in placements:
            self.assertLessEqual(col + widths[token], rommap.EVENT_WRAP_PX)

        glad_index = len(fragments[0]) + fragments[1].index("glad")
        glad = placements[glad_index][1:]
        self.assertEqual(glad, (0, 1))


if __name__ == "__main__":
    unittest.main()
