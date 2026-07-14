"""Direct-script bootstrap for text reference tools."""

import sys
from pathlib import Path


PROJECT_ROOT = Path(__file__).resolve().parents[3]
if str(PROJECT_ROOT) not in sys.path:
    sys.path.insert(0, str(PROJECT_ROOT))

from paths import ProjectPaths


PATHS = ProjectPaths.discover()
SOURCE = PATHS.text_reference_source_root
GENERATED = PATHS.text_reference_generated_root

__all__ = ["GENERATED", "SOURCE"]
