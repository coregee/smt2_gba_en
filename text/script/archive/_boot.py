"""Canonical paths for archived text investigations."""

import sys
from pathlib import Path


PROJECT_ROOT = Path(__file__).resolve().parents[3]
if str(PROJECT_ROOT) not in sys.path:
    sys.path.insert(0, str(PROJECT_ROOT))

from paths import ProjectPaths


PATHS = ProjectPaths.discover()
ROOT = PATHS.project_root
ROM = PATHS.source_rom
BUILD = PATHS.build_root
CORPUS = PATHS.corpus_root
REVIEW = PATHS.text_review_root

__all__ = ["BUILD", "CORPUS", "REVIEW", "ROM", "ROOT"]
