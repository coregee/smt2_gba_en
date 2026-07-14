"""Canonical paths shared by directly executable text tools."""

from __future__ import annotations

import sys
from pathlib import Path


PROJECT_ROOT = Path(__file__).resolve().parents[3]
if str(PROJECT_ROOT) not in sys.path:
    sys.path.insert(0, str(PROJECT_ROOT))

from paths import ProjectPaths  # noqa: E402


PATHS = ProjectPaths.discover()
ROOT = PATHS.project_root
ROM = PATHS.source_rom
CONFIG = PATHS.text_config_root
CORPUS = PATHS.corpus_root
REVIEW = PATHS.text_review_root

__all__ = ["CONFIG", "CORPUS", "PATHS", "REVIEW", "ROOT", "ROM", "Path"]
