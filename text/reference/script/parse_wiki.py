#!/usr/bin/env python3
"""Parse the saved Fandom wiki name lists (demon / item / skill) into clean per-entry JSON.

Each page is a series of <table class="table smt2"> data tables, one per category, preceded by an
<h3> heading (race / item-category / skill-element).  We read the header row for column names, then
each data row as {column: value} plus the heading as `category`.  Names lose trailing marker glyphs
(° * for fusion/special). Output is written under `reference/generated/`; these files provide the
English name source for the names track and retain Japanese names where the page supplies them.
"""
import html
import json
import re
import sys

try:
    from ._boot import GENERATED, SOURCE
except ImportError:
    from _boot import GENERATED, SOURCE

FILES = {"demon": "demon_list.htm", "item": "item_list.htm", "skill": "skill_list.html"}


def clean(cell):
    cell = re.sub(r"<br\s*/?>", " / ", cell, flags=re.I)
    cell = re.sub(r"<[^>]+>", "", cell)
    return html.unescape(cell).strip()


def parse(htm):
    rows_out = []
    # split into segments at each <h3> so we can attach the heading to the tables that follow it
    parts = re.split(r"(<h3\b[^>]*>.*?</h3>)", htm, flags=re.S)
    heading = ""
    for seg in parts:
        hm = re.match(r"<h3\b[^>]*>(.*?)</h3>", seg, re.S)
        if hm:
            # Fandom: <h3><span class="mw-headline" id="..">Heading</span></h3>
            sm = re.search(r'class="mw-headline"[^>]*>(.*?)</span>', hm.group(1), re.S)
            heading = clean(sm.group(1) if sm else hm.group(1))
            continue
        for tbl in re.findall(r'<table[^>]*class="[^"]*\bsmt2\b[^"]*"[^>]*>(.*?)</table>', seg, re.S):
            trs = re.findall(r"<tr[^>]*>(.*?)</tr>", tbl, re.S)
            if not trs:
                continue
            header = [clean(c) for c in re.findall(r"<th[^>]*>(.*?)</th>", trs[0], re.S)]
            if not header:                       # some tables lead with a <td> header row
                header = [clean(c) for c in re.findall(r"<t[hd][^>]*>(.*?)</t[hd]>", trs[0], re.S)]
            for tr in trs[1:]:
                cells = [clean(c) for c in re.findall(r"<t[hd][^>]*>(.*?)</t[hd]>", tr, re.S)]
                if not cells or not any(cells):
                    continue
                row = {"category": heading}
                for k, v in zip(header, cells):
                    row[k] = v
                rows_out.append(row)
    return rows_out


def normalized_rows(kind: str) -> list[dict[str, str]]:
    """Parse and normalize one saved reference page without writing files."""
    rows = parse((SOURCE / FILES[kind]).read_text(encoding="utf-8", errors="replace"))
    for row in rows:
        first = next((key for key in row if key != "category"), None)
        if first:
            row["name"] = re.sub(
                r"[ \t\u2020\u2021#\u00b0*\u271d]+$", "", row.pop(first)
            ).strip()
    return rows


def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")
    GENERATED.mkdir(parents=True, exist_ok=True)
    for kind in FILES:
        rows = normalized_rows(kind)
        output = GENERATED / f"{kind}_names.json"
        output.write_text(
            json.dumps(rows, ensure_ascii=False, indent=1), encoding="utf-8")
        jp = sum(1 for r in rows if r.get("Japanese"))
        cats = len({r["category"] for r in rows})
        print(f"{kind:6s}: {len(rows):4d} rows, {cats} categories, {jp} with JP "
              f"-> {output}")


if __name__ == "__main__":
    raise SystemExit(main())
