#!/usr/bin/env python3
"""Fill demon names (from the combatant sheet, missing only) and (re)translate the nested
affinity lines in names_demon.json into the canonical comma form.

Names: text/reference/generated/combatant-table.csv `name` column by id; only filled where `replace` is empty
(existing translations are kept).

Affinities: ALWAYS retranslated (overwriting). Element/relationship names follow
docs/resistance.md. Each JP resist line is `[elements・…][particle][relationship]`; the English
reverses it to `Relationship: Elem1, Elem2`. The display has two physical lines (record +0x32 /
+0x48):
  - WRAPPED (line1 is element-only and continues into line2):
        line1 "Affinity: E1, E2,"   line2 "E3, E4"
  - INDEPENDENT / SINGLE (each line carries its own relationship):
        each line "Affinity: E1, E2"
(comma-separated elements, not slashes). Re-run after `tr.py extract`.
"""
import csv
import json
import sys

try:
    from ._boot import PATHS
except ImportError:
    from _boot import PATHS

from text.script import tr

NAMES = tr.TR / "names_demon.json"
EQUIP = tr.TR / "names_equipment.json"
SHEET = PATHS.text_reference_generated_root / "combatant-table.csv"

# element / category JP -> EN (docs/resistance.md names; categories Physical/Mind/Strike/All are
# resist-text groupings, not single enum elements). Matched as whole ・-separated tokens.
ELEM = {
    "火炎": "Fire", "氷結": "Ice", "電撃": "Electric", "雷撃": "Electric", "衝撃": "Force",
    "突撃": "Charge", "神経": "Nerve", "破魔": "Expel", "呪殺": "Curse", "魔力": "Magic",
    "魔法": "Magic", "緊縛": "Bind", "剣": "Sword", "ガン": "Gun", "銃": "Gun",
    "物理": "Physical", "物理攻撃": "Physical", "打撃系技": "Strike", "精神系魔法": "Mind",
    "精神": "Mind", "全体的": "All", "他の物理": "Other Physical",
}
# relationship suffix -> EN (longest first so に強い beats 強い etc.)
REL = [("に強い", "Resist"), ("に強く", "Resist"), ("に弱い", "Weak"), ("に弱く", "Weak"),
       ("が無効", "Null"), ("を無効", "Null"), ("を吸収", "Drain"), ("を反射", "Repel"),
       ("無効", "Null"), ("吸収", "Drain"), ("反射", "Repel")]
# one-off scope phrases that aren't a plain element list
SPECIAL = {("ガン以外の", "物理攻撃に強い"): ("Resist: Physical,", "except Gun")}


def split_rel(s):
    for suf, en in REL:
        if s.endswith(suf):
            return s[:-len(suf)], en
    return s, None


def elems(s):
    out = []
    for part in s.strip("にをが・").split("・"):
        part = part.strip("にをが")
        if part:
            out.append(ELEM.get(part, f"?{part}?"))
    return out


def translate_pair(a1, a2):
    if (a1, a2) in SPECIAL:
        return SPECIAL[(a1, a2)]
    r1 = split_rel(a1) if a1 else ("", None)
    r2 = split_rel(a2) if a2 else ("", None)
    # WRAPPED: line1 has no relationship word but line2 does -> one affinity across both lines
    if a1 and r1[1] is None and a2 and r2[1] is not None:
        return f"{r2[1]}: " + ", ".join(elems(a1)) + ",", ", ".join(elems(r2[0]))
    en1 = (f"{r1[1]}: " + ", ".join(elems(r1[0]))) if a1 and r1[1] else (
        ", ".join(elems(a1)) if a1 else None)
    en2 = (f"{r2[1]}: " + ", ".join(elems(r2[0]))) if a2 and r2[1] else (
        ", ".join(elems(a2)) if a2 else None)
    return en1, en2


def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")
    sheet = {int(r["id"]): r["name"] for r in csv.DictReader(SHEET.open(encoding="utf-8")) if r["name"]}
    # sword-fusion "fake demon" stubs (combatant ids 336-361) share their name with a real
    # equipment entry; use the equipment translation so the fusion UI and item menu agree.
    equip = {x["original"]: x["replace"] for x in json.loads(EQUIP.read_text(encoding="utf-8"))
             if x.get("replace")}

    def equip_name(jp):
        if not jp:
            return None
        if jp in equip:
            return equip[jp]
        # the demon-stub name field is only 6 glyphs, so long sword names are truncated
        # (ブラフマース -> ブラフマーストラ); match the equipment whose name starts with the stub.
        if len(jp) >= 5:
            for eo, en in equip.items():
                if eo.startswith(jp) and len(eo) - len(jp) <= 3:
                    return en
        return None

    data = json.loads(NAMES.read_text(encoding="utf-8"))
    nfill = afill = 0
    unknown = set()
    for e in data:
        if not (e.get("replace") or "").strip():
            nm = sheet.get(e.get("id")) or equip_name(e.get("original"))
            if nm:
                e["replace"] = nm
                nfill += 1
        a1f, a2f = e.get("aff1"), e.get("aff2")
        if a1f or a2f:
            en1, en2 = translate_pair(a1f and a1f["original"], a2f and a2f["original"])
            if a1f and en1 is not None:
                a1f["replace"] = en1
                afill += 1
            if a2f and en2 is not None:
                a2f["replace"] = en2
                afill += 1
            for en in (en1, en2):
                if en and "?" in en:
                    unknown.add(en)
    NAMES.write_text(json.dumps(data, ensure_ascii=False, indent=1), encoding="utf-8")
    print(f"names filled (missing only): {nfill}; affinity fields translated: {afill}")
    if unknown:
        print("UNKNOWN element tokens (review):", sorted(unknown))


if __name__ == "__main__":
    raise SystemExit(main())
