import ast
import tempfile
import unittest
from pathlib import Path

import rom_layout


ROOT = Path(__file__).resolve().parents[1]
TEXT_RUNTIME_MODULES = (
    ROOT / "text" / "script" / "tr.py",
    ROOT / "text" / "script" / "sections.py",
    ROOT / "text" / "script" / "scriptrefs.py",
    ROOT / "text" / "script" / "vmflow.py",
)


def _imports(path: Path) -> set[str]:
    tree = ast.parse(path.read_text(encoding="utf-8"), filename=str(path))
    modules: set[str] = set()
    for node in ast.walk(tree):
        if isinstance(node, ast.Import):
            modules.update(alias.name for alias in node.names)
        elif isinstance(node, ast.ImportFrom) and node.module:
            modules.add(node.module)
            modules.update(f"{node.module}.{alias.name}" for alias in node.names)
    return modules


class ArchitectureTests(unittest.TestCase):
    def test_shared_layout_has_neutral_ownership(self):
        private_domains = ("engine", "font", "graphics", "text")
        imports = _imports(ROOT / "rom_layout.py")
        offenders = sorted(
            module
            for module in imports
            if module in private_domains or module.startswith(tuple(f"{d}." for d in private_domains))
        )
        self.assertEqual([], offenders)

    def test_text_runtime_does_not_depend_on_engine_internals(self):
        offenders = {
            str(path.relative_to(ROOT)): sorted(
                module
                for module in _imports(path)
                if module == "engine" or module.startswith("engine.")
            )
            for path in TEXT_RUNTIME_MODULES
        }
        self.assertEqual({}, {path: imports for path, imports in offenders.items() if imports})

    def test_removed_engine_rommap_has_no_python_callers(self):
        self.assertFalse((ROOT / "engine" / "script" / "rommap.py").exists())
        offenders: list[str] = []
        for path in ROOT.rglob("*.py"):
            imports = _imports(path)
            if "engine.script.rommap" in imports:
                offenders.append(str(path.relative_to(ROOT)))
        self.assertEqual([], offenders)

    def test_c_caves_use_only_the_generated_rommap_header(self):
        self.assertFalse((ROOT / "engine" / "script" / "rommap.h").exists())
        users = []
        quoted = []
        for pattern in ("*.c", "*.h"):
            for path in (ROOT / "engine" / "script").glob(pattern):
                source = path.read_text(encoding="utf-8")
                if "rommap.h" in source:
                    users.append(path)
                if '#include "rommap.h"' in source:
                    quoted.append(str(path.relative_to(ROOT)))
        self.assertGreater(len(users), 0)
        self.assertEqual([], quoted)

    def test_generated_rommap_header_is_deterministic(self):
        with tempfile.TemporaryDirectory() as work:
            first = Path(work) / "first.h"
            second = Path(work) / "second.h"
            rom_layout.write_header(first)
            rom_layout.write_header(second)
            self.assertEqual(first.read_bytes(), second.read_bytes())
            header = first.read_text(encoding="utf-8")
        self.assertTrue(header.startswith("/* Auto-generated from rom_layout.py"))
        self.assertIn(f"#define RM_ROM_BASE 0x{rom_layout.ROM_BASE:08X}", header)
        self.assertIn(f"#define RM_ROM_TARGET_SIZE 0x{rom_layout.ROM_TARGET_SIZE:08X}", header)


if __name__ == "__main__":
    unittest.main()
