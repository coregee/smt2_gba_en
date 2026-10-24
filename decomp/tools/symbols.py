"""The symbol table: reference/symbols.tsv (address, name, kind, confidence, note).

kind: func | data | ram.  confidence: proven | probable | tentative (see docs/naming.md).
Names are only ever looked up by address; the emitter falls back to sub_/gUnknown_ names."""
from __future__ import annotations

import csv
from dataclasses import dataclass
from pathlib import Path


@dataclass
class Sym:
    addr: int
    name: str
    kind: str
    confidence: str
    note: str


class Symbols:
    def __init__(self, rows):
        self.by_addr = {s.addr: s for s in rows}
        self.by_name = {s.name: s for s in rows}

    @classmethod
    def load(cls, path: Path):
        rows = []
        if Path(path).exists():
            with open(path, newline="", encoding="utf-8") as fh:
                for r in csv.DictReader(fh, delimiter="\t"):
                    rows.append(Sym(int(r["address"], 16), r["name"], r["kind"],
                                    r.get("confidence", ""), r.get("note", "")))
        return cls(rows)

    def name(self, addr):
        s = self.by_addr.get(addr)
        return s.name if s else None

    @staticmethod
    def save(path: Path, rows):
        rows = sorted(rows, key=lambda s: s.addr)
        with open(path, "w", newline="", encoding="utf-8") as fh:
            w = csv.writer(fh, delimiter="\t", lineterminator="\n")
            w.writerow(["address", "name", "kind", "confidence", "note"])
            for s in rows:
                w.writerow([f"{s.addr:08X}", s.name, s.kind, s.confidence, s.note])
