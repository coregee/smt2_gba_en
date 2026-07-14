#!/usr/bin/env python3
"""Field-kind schema coverage audit (docs/text-hack-consolidation.md §7).

Classifies every translatable leaf field in every translation JSON via sections.kind_of and
validates its key-set via sections.check_entry.  PASS = every field maps to exactly one
FIELD_KINDS kind with a valid shape (zero unclassifiable / malformed).  This is the read-only
proof that the field-kind schema covers reality before check_entry is wired into the pack/
extract path.  Re-run after any schema or JSON change.

Usage:  python -m text.script.tools.audit_field_schema
"""
import sys
import json
import collections
try:
    from text.script.tools import _boot  # noqa: F401
except ModuleNotFoundError:
    import _boot  # noqa: F401

from text.script import sections, tr  # noqa: E402


def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")
    kinds = collections.Counter()
    per_route = collections.defaultdict(set)
    violations = []
    nfields = 0
    for sec in sections.SECTIONS:
        p = tr.TR / f"{sec.id}.json"
        if not p.exists():
            continue
        for entry in json.loads(p.read_text(encoding="utf-8")):
            for f in tr.fields(entry):
                if not isinstance(f, dict):
                    violations.append((sec.id, f"non-dict field {f!r:.50}"))
                    continue
                nfields += 1
                try:
                    k = sections.check_entry(sec, f)
                    kinds[k] += 1
                    per_route[sec.route].add(k)
                except ValueError as e:
                    violations.append((sec.id, str(e)))
    print(f"=== field-kind schema audit: {nfields} leaf fields, {len(sections.FIELD_KINDS)} kinds ===")
    for k, n in kinds.most_common():
        print(f"  {n:6d}  {k}")
    print("\n=== kinds per route (each section's allowed_kinds) ===")
    for r in sorted(per_route):
        print(f"  {r:14s} {{{', '.join(sorted(per_route[r]))}}}")
    if violations:
        print(f"\n!! {len(violations)} VIOLATION(S):")
        for sid, msg in violations[:40]:
            print(f"  {sid}: {msg}")
        return 1
    print(f"\nPASS — every field classifies + validates")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
