"""Create reference atlas sheets from the unmodified ROM fonts."""

from __future__ import annotations

import argparse
from pathlib import Path

if __package__ in (None, ""):
    import sys

    sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from font.script.repack import build_main_font, build_small_font, write_outputs
from paths import ProjectPaths


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    try:
        paths = ProjectPaths.discover()
        rom = paths.source_rom.read_bytes()
        # write_outputs creates both reference and replacement sheets so the two
        # atlases are always directly comparable.
        write_outputs(rom, build_main_font(rom), build_small_font(rom))
        print(f"atlases: {paths.font_atlas_root}")
    except (FileNotFoundError, OSError, TypeError, ValueError) as error:
        parser.error(str(error))


if __name__ == "__main__":
    main()
