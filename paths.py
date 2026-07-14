"""Canonical paths for the SMT2 GBA translation project."""

from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path


ROM_FILENAME = "Shin Megami Tensei II (Japan).gba"


@dataclass(frozen=True, slots=True)
class ProjectPaths:
    project_root: Path
    rom_root: Path

    def __post_init__(self) -> None:
        project_root = Path(self.project_root).resolve()
        rom_root = Path(self.rom_root).resolve()

        if rom_root.parent != project_root:
            raise ValueError(f"ROM directory must be directly under the project root: {rom_root}")

        object.__setattr__(self, "project_root", project_root)
        object.__setattr__(self, "rom_root", rom_root)

    @classmethod
    def discover(cls) -> "ProjectPaths":
        project_root = Path(__file__).resolve().parent
        return cls(
            project_root=project_root,
            rom_root=project_root / "rom",
        )

    @property
    def source_rom(self) -> Path:
        return self.rom_root / ROM_FILENAME

    @property
    def build_root(self) -> Path:
        """Directory containing local source, intermediate, and built ROMs."""
        return self.rom_root

    @property
    def text_root(self) -> Path:
        return self.project_root / "text"

    @property
    def corpus_root(self) -> Path:
        return self.text_root / "corpus"

    @property
    def text_script_root(self) -> Path:
        return self.text_root / "script"

    @property
    def text_config_root(self) -> Path:
        return self.text_root / "config"

    @property
    def text_review_root(self) -> Path:
        return self.text_root / "review"

    @property
    def text_generated_root(self) -> Path:
        return self.text_root / "generated"

    @property
    def text_dump_root(self) -> Path:
        return self.text_generated_root / "readable"

    @property
    def text_reference_root(self) -> Path:
        return self.text_root / "reference"

    @property
    def text_reference_source_root(self) -> Path:
        return self.text_reference_root / "source"

    @property
    def text_reference_generated_root(self) -> Path:
        return self.text_reference_root / "generated"

    @property
    def text_archive_root(self) -> Path:
        return self.text_script_root / "archive"

    @property
    def text_tools_root(self) -> Path:
        return self.text_script_root / "tools"

    @property
    def font_root(self) -> Path:
        return self.project_root / "font"

    @property
    def font_config_root(self) -> Path:
        return self.font_root / "config"

    @property
    def font_atlas_root(self) -> Path:
        return self.font_root / "atlas"

    @property
    def font_script_root(self) -> Path:
        return self.font_root / "script"

    @property
    def font_source_root(self) -> Path:
        return self.font_root / "source"

    @property
    def font_build_root(self) -> Path:
        return self.rom_root / "font"

    @property
    def graphics_root(self) -> Path:
        return self.project_root / "graphics"

    @property
    def graphics_assets_root(self) -> Path:
        return self.graphics_root / "assets"

    @property
    def graphics_script_root(self) -> Path:
        return self.graphics_root / "script"

    @property
    def engine_root(self) -> Path:
        return self.project_root / "engine"

    @property
    def engine_script_root(self) -> Path:
        return self.engine_root / "script"

    @property
    def engine_build_script(self) -> Path:
        return self.engine_script_root / "build_rom.py"

    def build_path(self, filename: str) -> Path:
        candidate = Path(filename)
        if candidate.is_absolute() or len(candidate.parts) != 1:
            raise ValueError(f"build filename must be a single relative name: {filename}")
        return self.rom_root / candidate
