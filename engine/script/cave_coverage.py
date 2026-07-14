"""Collect text addresses handled directly by engine patch modules."""
from __future__ import annotations

import importlib

from paths import ProjectPaths


def covered_addrs() -> set[int]:
    """Union every patch module's declared ``COVERED_TEXT_ADDRS``."""
    engine_root = ProjectPaths.discover().engine_script_root
    out: set[int] = set()
    for path in sorted(engine_root.glob("patch_*.py")):
        try:
            module = importlib.import_module(f"engine.script.{path.stem}")
        except Exception:
            continue
        out |= {int(address) for address in (getattr(module, "COVERED_TEXT_ADDRS", ()) or ())}
    return out


def main() -> None:
    addresses = sorted(covered_addrs())
    print(f"{len(addresses)} cave/patch-covered text addresses")
    for address in addresses:
        print(f"  {address:08X}")


if __name__ == "__main__":
    main()
