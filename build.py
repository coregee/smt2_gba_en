"""Public build entry point for the SMT2 GBA translation."""

from __future__ import annotations

import argparse
import hashlib
import importlib.util
import os
from pathlib import Path
import sys
from types import ModuleType


if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parent))

from paths import ProjectPaths
from profiles import BuildProfile, load_profiles, profile_by_name


def _load_builder(paths: ProjectPaths, profile: BuildProfile) -> ModuleType:
    """Load the canonical engine with profile-specific diagnostic hooks."""

    script = paths.engine_build_script
    if not script.is_file():
        raise FileNotFoundError(f"build engine not found: {script}")

    module_name = "_smt2_gba_build"
    spec = importlib.util.spec_from_file_location(module_name, script)
    if spec is None or spec.loader is None:
        raise RuntimeError(f"cannot load build engine: {script}")

    previous_diagnostic = os.environ.get("SMT2_DIAG")
    if profile.diagnostic:
        os.environ["SMT2_DIAG"] = "1"
    else:
        os.environ.pop("SMT2_DIAG", None)

    try:
        module = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(module)
    finally:
        if previous_diagnostic is None:
            os.environ.pop("SMT2_DIAG", None)
        else:
            os.environ["SMT2_DIAG"] = previous_diagnostic

    module.BASE = paths.source_rom
    module.FONT_OUT = paths.build_path("smt2-en-font.gba")
    module.OUT = paths.build_path(profile.output)
    return module


_load_legacy_builder = _load_builder


def run_build(profile: BuildProfile, *, check: bool = False) -> tuple[bytes, object]:
    paths = ProjectPaths.discover()
    if not paths.source_rom.is_file():
        raise FileNotFoundError(f"source ROM not found: {paths.source_rom}")

    builder = _load_builder(paths, profile)
    if check:
        patcher = builder.build_patcher()
        output = bytes(builder.tr.pack(patcher.rom))
    else:
        patcher = builder.build()
        output = builder.OUT.read_bytes()
    return output, patcher


def main() -> None:
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")
    parser = argparse.ArgumentParser(
        description="Build the modular SMT2 GBA translation."
    )
    parser.add_argument(
        "--list-profiles",
        action="store_true",
        help="list configured build profiles and exit",
    )
    parser.add_argument(
        "--profile",
        default="full",
        help="named profile to build (default: full)",
    )
    parser.add_argument(
        "--check",
        action="store_true",
        help="validate and hash the selected build without writing artifacts",
    )
    arguments = parser.parse_args()

    try:
        profiles = load_profiles()
        if arguments.list_profiles:
            for profile in profiles:
                print(f"{profile.name}: {profile.description}")
            return

        profile = profile_by_name(arguments.profile, profiles)
        output, patcher = run_build(profile, check=arguments.check)
        digest = hashlib.sha256(output).hexdigest().upper()
        print(f"profile: {profile.name}")
        print(patcher.summary())
        if arguments.check:
            print(f"validated: {len(output)} bytes; SHA-256 {digest}; no files written")
        else:
            path = ProjectPaths.discover().build_path(profile.output)
            print(f"built: {path}")
            print(f"SHA-256: {digest}")
    except (FileNotFoundError, OSError, RuntimeError, TypeError, ValueError) as error:
        parser.error(str(error))


if __name__ == "__main__":
    main()
