#!/usr/bin/env python3
"""Common canonical paths for the GBA patch modules."""
import sys
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parents[2]
if str(PROJECT_ROOT) not in sys.path:
    sys.path.insert(0, str(PROJECT_ROOT))

from paths import ProjectPaths  # noqa: E402

PATHS = ProjectPaths.discover()
ROOT = PATHS.project_root

from engine.script import rommap  # noqa: E402

B = rommap.ROM_BASE

__all__ = ["PATHS", "ROOT", "rommap", "B", "Path"]
