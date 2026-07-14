"""Curated glyph atlas used by every text encoder and decoder."""

from __future__ import annotations

import json
from pathlib import Path


ATLAS_ROOT = Path(__file__).resolve().parent
CONFIG_ROOT = ATLAS_ROOT.parent / "config"


def _code(value: int | str) -> int:
    if isinstance(value, bool) or not isinstance(value, (int, str)):
        raise ValueError(f"invalid glyph code: {value!r}")
    return int(value, 0) if isinstance(value, str) else value


def load_glyph_map(path: Path = ATLAS_ROOT / "main.json") -> dict[int, str]:
    """Load and validate the reviewed code-to-Unicode atlas."""
    document = json.loads(path.read_text(encoding="utf-8"))
    if not isinstance(document, dict):
        raise ValueError(f"{path}: expected an object")

    atlas: dict[int, str] = {}
    for raw_code, character in document.items():
        try:
            code = int(raw_code, 16)
        except (TypeError, ValueError) as error:
            raise ValueError(f"{path}: invalid glyph code {raw_code!r}") from error
        if not 0 <= code <= 0x11FF:
            raise ValueError(f"{path}: glyph code 0x{code:04X} is out of range")
        if not isinstance(character, str) or not character:
            raise ValueError(f"{path}: glyph 0x{code:04X} has no text")
        if code in atlas:
            raise ValueError(f"{path}: duplicate glyph code 0x{code:04X}")
        atlas[code] = character
    return atlas


def replacement_characters(path: Path = CONFIG_ROOT / "main.json") -> dict[int, str]:
    """Expand the declarative replacement ranges from the main-font config."""
    document = json.loads(path.read_text(encoding="utf-8"))
    rows = document.get("replacements")
    if not isinstance(rows, list):
        raise ValueError(f"{path}: replacements must be an array")

    replacements: dict[int, str] = {}
    for row_number, row in enumerate(rows):
        context = f"{path}: replacements[{row_number}]"
        if not isinstance(row, dict):
            raise ValueError(f"{context} must be an object")
        if set(row) == {"start", "characters"}:
            start = _code(row["start"])
            characters = row["characters"]
            if not isinstance(characters, str):
                raise ValueError(f"{context}.characters must be text")
            entries = enumerate(characters, start)
        elif set(row) == {"map"} and isinstance(row["map"], dict):
            entries = ((_code(code), character) for code, character in row["map"].items())
        else:
            raise ValueError(f"{context} must contain a range or map")

        for code, character in entries:
            if not isinstance(character, str) or not character:
                raise ValueError(f"{context}: glyph 0x{code:04X} has no text")
            if code in replacements:
                raise ValueError(f"{context}: duplicate glyph code 0x{code:04X}")
            replacements[code] = character
    return replacements


def character_codes() -> dict[str, int]:
    """Return canonical text-to-code mappings, preferring replaced Latin cells."""
    result: dict[str, int] = {}
    for code, character in sorted(GLYPH_MAP.items()):
        result.setdefault(character, code)
    # The legacy encoder only overrode authored punctuation here. Letter and
    # digit callers retain their established lowest-code behaviour; the main
    # text codec pins its canonical ASCII runs separately.
    for code, character in replacement_characters().items():
        if not character.isalnum():
            result[character] = code
    result[" "] = 0x00BC
    return result


GLYPH_MAP = load_glyph_map()


__all__ = ["ATLAS_ROOT", "GLYPH_MAP", "character_codes", "load_glyph_map", "replacement_characters"]
