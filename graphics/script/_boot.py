"""Canonical paths shared by directly executable graphics tools."""

from __future__ import annotations

import sys
from pathlib import Path


PROJECT_ROOT = Path(__file__).resolve().parents[2]
if str(PROJECT_ROOT) not in sys.path:
    sys.path.insert(0, str(PROJECT_ROOT))

from paths import ProjectPaths  # noqa: E402


PATHS = ProjectPaths.discover()
ROOT = PATHS.project_root
ROM = PATHS.source_rom
ASSETS = PATHS.graphics_assets_root
ORIGINALS = ASSETS / "originals"

__all__ = ["ASSETS", "ORIGINALS", "PATHS", "ROOT", "ROM", "Path"]
