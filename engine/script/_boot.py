#!/usr/bin/env python3
"""Common canonical paths for the GBA patch modules."""
import sys
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parents[2]
if str(PROJECT_ROOT) not in sys.path:
    sys.path.insert(0, str(PROJECT_ROOT))

from paths import ProjectPaths  # noqa: E402
from rom_layout import ROM_BASE  # noqa: E402

PATHS = ProjectPaths.discover()
ROOT = PATHS.project_root

B = ROM_BASE

__all__ = ["PATHS", "ROOT", "B", "Path"]
