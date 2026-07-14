"""Named SMT2 GBA build-profile configuration."""

from __future__ import annotations

from dataclasses import dataclass
import json
from pathlib import Path


PROJECT_ROOT = Path(__file__).resolve().parent
PROFILES_PATH = PROJECT_ROOT / "config" / "profiles.json"


@dataclass(frozen=True, slots=True)
class BuildProfile:
    name: str
    description: str
    diagnostic: bool
    output: str

    def __post_init__(self) -> None:
        if not self.name:
            raise ValueError("build profile name cannot be empty")
        if not self.description:
            raise ValueError(f"{self.name}: description cannot be empty")
        output = Path(self.output)
        if output.is_absolute() or len(output.parts) != 1 or output.suffix.lower() != ".gba":
            raise ValueError(
                f"{self.name}: output must be a single relative .gba filename"
            )


def load_profiles(path: Path = PROFILES_PATH) -> tuple[BuildProfile, ...]:
    document = json.loads(path.read_text(encoding="utf-8"))
    if document.get("version") != 1:
        raise ValueError(f"{path}: unsupported profile version")

    rows = document.get("profiles")
    if not isinstance(rows, list) or not rows:
        raise ValueError(f"{path}: profiles must be a nonempty array")

    profiles = tuple(BuildProfile(**row) for row in rows)
    names = [profile.name for profile in profiles]
    if len(names) != len(set(names)):
        raise ValueError(f"{path}: duplicate profile name")
    outputs = [profile.output.casefold() for profile in profiles]
    if len(outputs) != len(set(outputs)):
        raise ValueError(f"{path}: duplicate profile output")
    return profiles


def profile_by_name(
    name: str,
    profiles: tuple[BuildProfile, ...] | None = None,
) -> BuildProfile:
    for profile in profiles if profiles is not None else load_profiles():
        if profile.name == name:
            return profile
    raise ValueError(f"unknown build profile: {name}")
