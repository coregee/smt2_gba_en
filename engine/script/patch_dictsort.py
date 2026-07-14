#!/usr/bin/env python3
"""Repurpose the demon-dictionary NAME page: JP kana sort -> English alphabetical buckets.

The dictionary's "NAME" sort page is TABLE-DRIVEN, not a runtime sort: build-mode 2
(Dict_BuildList @0x080db4a8) copies demon ids from a precomputed {u16 id, u16 group} array
@DICT_SORT_TABLE (0x08585C34, 325 entries, 0xFFFF-terminated) in order, tags entries whose
group != the selected category with bit 0x8000, and jumps the cursor to the selected group's
first entry.  JP groups by the first KANA of each demon's Japanese name (10 groups 0-9; the
11th selector label その他 = "Other" is an empty catch-all).

For English that grouping is meaningless, so we regenerate the table at BUILD TIME (no runtime
code changes): the SAME 325 ids, re-sorted alphabetically by their ENGLISH name, with group =
a letter BUCKET.  The 10 buckets (density-balanced over the 325 dictionary demons) are:

    0 A     1 B-C   2 D-G   3 H-J   4 K-L   5 M-N   6 O-R   7 S   8 T-W   9 Y-Z   (10 Other = empty)

We also relabel the 11 selector labels (DICT_NAME_LABELS slots -> EN glyph strings in far data)
and VWF the selector drawer (the kana hook in patch_dictname reuses dict_str_vwf).  This keeps the
exact structure JP uses (10 groups + empty "Other"), so the build-mode-2 ASM is untouched.

Pure data: rewrites DICT_SORT_TABLE in place (same size), writes the EN labels to FARDATA, and
repoints the 11 selector slots.  No cave-pool use.
"""
import struct
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, rommap, B, Path

from engine.script import rommap
import json
from text.script import tr

ENG_LO = rommap.ENG_LO            # 0xBC: ASCII 0x20-space base ('A' = 0xBC + 0x21)
LOWER_LO = 0x00FE                 # lowercase 'a' (extended charset, patch_defaultnames)
TERM = 0x0301

# bucket label -> the uppercase first-letters it owns (index = group id)
BUCKETS = [
    ("A",     "A"),
    ("B-C",   "BC"),
    ("D-G",   "DEFG"),
    ("H-J",   "HIJ"),
    ("K-L",   "KL"),
    ("M-N",   "MN"),
    ("O-R",   "OPQR"),
    ("S",     "S"),
    ("T-W",   "TUVW"),
    ("Y-Z",   "XYZ"),
    ("Other", ""),                # catch-all (non-letter / untranslated); empty for SMT2's set
]
OTHER = len(BUCKETS) - 1
_LETTER2BUCKET = {ch: bi for bi, (_, letters) in enumerate(BUCKETS) for ch in letters}


def _bucket_of(name):
    c = name[:1].upper()
    return _LETTER2BUCKET.get(c, OTHER) if c.isalpha() else OTHER


def _encode(s):
    """English label -> glyph tokens + 0x0301 terminator (OBJ-cache font codes)."""
    out = bytearray()
    for ch in s:
        if "A" <= ch <= "Z":
            t = ENG_LO + (ord(ch) - 0x20)
        elif "a" <= ch <= "z":
            t = LOWER_LO + (ord(ch) - ord("a"))
        elif ch == "-":
            t = ENG_LO + 0x0D
        else:
            raise SystemExit(f"patch_dictsort: unencodable label char {ch!r}")
        out += struct.pack("<H", t)
    out += struct.pack("<H", TERM)
    return bytes(out)


def apply(p):
    # id -> English demon name
    names = {}
    for e in json.load(open(tr.TR / "names_demon.json", encoding="utf-8")):
        if isinstance(e, dict) and "id" in e:
            names[e["id"]] = (e.get("replace") or "").strip()

    # read the existing {id, group} table (defines the dictionary's demon SET + size)
    base = rommap.DICT_SORT_TABLE
    ids = []
    for i in range(512):
        idv = struct.unpack("<H", p.read(base + i * 4, 2))[0]
        if idv == 0xFFFF:
            break
        ids.append(idv)
    if not ids:
        raise SystemExit("patch_dictsort: empty/❓ sort table at DICT_SORT_TABLE")

    missing = [i for i in ids if not names.get(i)]
    if missing:
        # untranslated dictionary demons would land in "Other"; warn so it's visible
        print(f"  ! dictsort: {len(missing)} dict ids have no EN name -> Other bucket: {missing[:8]}")

    # re-sort: by bucket, then alphabetically (case-insensitive); id breaks ties for determinism
    rows = []
    for idv in ids:
        nm = names.get(idv, "")
        rows.append((_bucket_of(nm), nm.casefold(), idv))
    rows.sort(key=lambda r: (r[0], r[1], r[2]))

    new_table = b"".join(struct.pack("<HH", idv, grp) for grp, _, idv in rows)
    p.write(base, new_table)                       # in place, same size; 0xFFFF terminator untouched

    # write the 11 EN bucket labels to far data and repoint the selector slots
    blob = bytearray()
    ptrs = []
    for label, _ in BUCKETS:
        ptrs.append(rommap.FARDATA_DICTBUCKETS + len(blob))
        blob += _encode(label)
    if rommap.FARDATA_DICTBUCKETS + len(blob) > 0x0869D000:
        raise SystemExit("patch_dictsort: bucket labels overrun the 0x0869D000 far-data ceiling")
    p.write(rommap.FARDATA_DICTBUCKETS, blob)
    for i, pt in enumerate(ptrs):
        p.write(rommap.DICT_NAME_LABELS + i * 4, struct.pack("<I", pt))

    # The Cathedral-of-Shadows compendium shares DICT_SORT_TABLE (ordering already inherited) but
    # has its OWN NAME-category label table: 10 slots (ア行..ワ行, no その他).  Point them at the
    # same EN bucket labels [0..9] (the compendium VWFs the draw via patch_skilllist).
    for i in range(10):
        p.write(rommap.COMP_NAME_LABELS + i * 4, struct.pack("<I", ptrs[i]))

    hist = {}
    for grp, _, _ in rows:
        hist[grp] = hist.get(grp, 0) + 1
    summary = ", ".join(f"{BUCKETS[g][0]}:{hist.get(g, 0)}" for g in range(len(BUCKETS)))
    print(f"dictsort: {len(ids)} demons re-bucketed by EN name [{summary}]; "
          f"labels @0x{rommap.FARDATA_DICTBUCKETS:08X}")
