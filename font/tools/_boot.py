"""Canonical paths shared by directly executable font review and OCR tools."""

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
CONFIG = PATHS.font_config_root
GENERATED = PATHS.font_generated_root
REVIEW = PATHS.font_review_root

__all__ = ["CONFIG", "GENERATED", "PATHS", "REVIEW", "ROOT", "ROM", "Path"]
