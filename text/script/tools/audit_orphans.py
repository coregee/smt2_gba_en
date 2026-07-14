#!/usr/bin/env python3
"""Reference-ANCHORED orphan-text audit — the robust complement to audit_text_coverage.py.

WHY THIS EXISTS
---------------
`audit_text_coverage.py` builds its candidate set from `find_tables()` — *dense runs of
>=4 consecutive u32 pointers* (min_run=4). It then asks "is each pointer TABLE covered?".
It NEVER asks "is each STRING owned?". So any live text reached by

  * a single `ldr rN,=str` code-literal (a 1-word literal pool entry, not a run),
  * a sparse / null-padded pointer table (runs break below 4),
  * a struct-embedded string pointer (handler / save-state / fusion record fields),
  * an fn-pointer step record (intro steps, cutscene tables), or
  * a computed `base + idx*stride` read (no stored per-cell pointer at all)

is invisible to it — it can report AUDIT PASS while substantial text is unowned. Every
orphan the team found to date (comp_messages, save_screen, automap_markers,
intro_disclaimer, dungeon_events, config_help, …) was hand-traced because the
contiguous-ptr scan was blind to it.

WHAT THIS DOES
--------------
Inverts the question. Two passes:

PASS A — reference-anchored (the high-signal majority).
  Build a refmap: every 4-aligned word in the ROM whose value is an even in-ROM pointer.
  A `ldr` literal-pool entry and a pointer-table slot are BOTH just a u32 word holding the
  address, so one uniform scan subsumes tables + sparse tables + code-literals + embedded
  pointers. For each pointed-at address that decodes as a valid terminated JP text string
  and is NOT in a section's claimed span -> ORPHAN, reported WITH its reference sites (so
  the consumer is a one-step trace) and a decoded sample.

PASS B — computed-index / walk-reached regions (no stored per-cell pointer).
  Sweep the ROM for maximal high-density text regions (>=2 string terminators, many
  glyphs). Any such region that is unclaimed AND has ~no inbound pointers is a candidate
  fixed-stride table (the 530-cell location table, the floor-number menu) or a walk-only
  bank — report its base, length, sample, and whether the base address is referenced
  (the trace lead for finding the base+stride reader).

Output: text/review/text-orphans.csv + text/review/text-orphan-regions.csv + console summary.
Run alongside audit_text_coverage.py after any manifest/extractor change.
"""
from __future__ import annotations
import csv
import sys
from collections import Counter

try:
    from text.script.tools._boot import REVIEW, ROM
except ModuleNotFoundError:
    from _boot import REVIEW, ROM

from text.script import sections, tr  # noqa: E402
from engine.script import cave_coverage     # noqa: E402  Sections ∪ caves ∪ patches (else cave-handled text false-flags)
from text.script import vmflow  # noqa: E402

VM_BANK_LO, VM_BANK_HI = 0x08016000, 0x080A8C00
from font.generated.glyph_map import GLYPH_MAP  # noqa: E402
from text.script.tools.scan_text_banks import score_text  # noqa: E402
from text.script.tools.audit_text_coverage import claimed_spans, KNOWN  # noqa: E402

ROM_BASE = 0x08000000
CSV_ORPHANS = REVIEW / "text-orphans.csv"
CSV_REGIONS = REVIEW / "text-orphan-regions.csv"

# A string is "text" if at least this fraction of its codes decode to glyphs/controls,
# it is at least this long, AND it carries at least one true JP code unit (kana / kanji /
# fullwidth form). The JP gate kills the ASCII-misread false positives (binary data that
# decodes to runs like "BCDEFGHIJKL") that pure score_text lets through.
MIN_FRAC = 0.85
MIN_LEN = 4


# A "content" code unit = real spoken text: kana or a CJK ideograph. Deliberately EXCLUDES
# punctuation (、。「」…), fullwidth ASCII (０-９Ａ-Ｚ), '？', '□', and the '·'/'/' controls —
# so data that decodes to punctuation/symbol/□ runs (charset maps, digit tables, ？？？
# placeholders, graphics misreads) is rejected while real Japanese is kept.
def is_content(ch: str) -> bool:
    o = ord(ch)
    return (0x3040 <= o <= 0x30FF      # hiragana + katakana
            or 0x4E00 <= o <= 0x9FFF)  # CJK unified ideographs


MIN_CONTENT = 2        # >=2 kana/kanji
MIN_CONTENT_FRAC = 0.30  # and they are >=30% of the decoded run (kills symbol/□-heavy data)
MAX_CHAR_FRAC = 0.45   # no single kana/kanji may exceed this share of content (kills
#   fixed-stride DATA tables that decode to a repeated glyph: 老老老…, 噌狗相狗卒狗…, 血。。血。。)


def _content_ok(dec: str) -> bool:
    body = [c for c in dec if c not in "·/□"]          # ignore controls/unknowns for density
    content = [c for c in body if is_content(c)]
    if len(content) < MIN_CONTENT or not body or len(content) / len(body) < MIN_CONTENT_FRAC:
        return False
    if len(content) >= 6 and Counter(content).most_common(1)[0][1] / len(content) > MAX_CHAR_FRAC:
        return False
    return True


def looks_like_text(rom, addr, max_codes=80):
    frac, ln, dec = score_text(rom, addr, max_codes)
    if frac < MIN_FRAC or ln < MIN_LEN or not _content_ok(dec):
        return None
    if dec.startswith("÷÷"):     # known data-table class (0x0811xxxx/0x0872Exxx) misreads as ÷÷X愚Y愚
        return None
    return frac, ln, dec


def build_refmap(rom):
    """value(even in-ROM pointer) -> [ref-site addrs]. One 4-aligned word scan catches
    pointer-table slots AND `ldr` literal-pool entries uniformly."""
    n = len(rom)
    lo, hi = ROM_BASE, ROM_BASE + n
    refs: dict[int, list[int]] = {}
    for o in range(0, n - 3, 4):
        v = int.from_bytes(rom[o:o + 4], "little")
        if lo <= v < hi and (v & 1) == 0:
            refs.setdefault(v, []).append(ROM_BASE + o)
    return refs


def claimed_lookup(spans):
    """Set of every even byte-addr inside a claimed span (with the audit's +6 leading
    tolerance applied at query time)."""
    owned = set()
    for lo, hi, _sec in spans:
        owned.update(range(lo, hi, 2))
    def claimed(addr):
        return any((addr + d) in owned for d in (0, 2, 4, 6))
    return claimed, owned


# ---------------------------------------------------------------- pass A
def pass_a(rom, refs, claimed):
    pool_lo = tr.POOL_START
    known_tables = set(KNOWN)            # table source addrs explicitly accounted for
    orphans = []
    for addr, sites in refs.items():
        if addr >= pool_lo:              # our own build pool (not in the base ROM anyway)
            continue
        t = looks_like_text(rom, addr)
        if not t:
            continue
        if claimed(addr):
            continue
        frac, ln, dec = t
        # drop refs that sit inside a KNOWN slots/dead table source (those refs are data,
        # not consumers) — keep refs in code/elsewhere.
        real_sites = [s for s in sites if s not in known_tables]
        orphans.append(dict(addr=addr, nrefs=len(sites), sites=real_sites or sites,
                            frac=round(frac, 2), glyphs=ln, sample=dec[:48]))
    orphans.sort(key=lambda r: (-r["nrefs"], r["addr"]))
    return orphans


def cluster_orphans(orphans, ref_gap=0x40):
    """Group orphans whose PRIMARY ref site sits in the same contiguous pointer table
    (ref sites within ref_gap of each other). One cluster = one consumer table to trace,
    which is the unit handed to the auto-tracer. Strings reached only by an in-bank
    branch/jump word cluster the same way (adjacent code)."""
    items = sorted(orphans, key=lambda r: (min(r["sites"]), r["addr"]))
    clusters, cur = [], []
    last = None
    for o in items:
        ref = min(o["sites"])
        if last is not None and ref - last > ref_gap:
            clusters.append(cur); cur = []
        cur.append(o); last = ref
    if cur:
        clusters.append(cur)
    out = []
    for c in clusters:
        refs_ = sorted(min(o["sites"]) for o in c)
        tgts = sorted(o["addr"] for o in c)
        out.append(dict(n=len(c), ref_lo=refs_[0], ref_hi=refs_[-1],
                        tgt_lo=tgts[0], tgt_hi=tgts[-1],
                        samples=[o["sample"][:34] for o in c[:3]]))
    out.sort(key=lambda r: -r["n"])
    return out


# ---------------------------------------------------------------- pass B
def code_class(rom):
    """Per-even-offset class array: 'g' glyph, 'c' control(0300-031B), 't' terminator
    (0000/0301), 'x' other. Used to find dense text regions cheaply."""
    n = len(rom)
    cls = bytearray(n // 2)
    for i in range(n // 2):
        c = int.from_bytes(rom[i * 2:i * 2 + 2], "little")
        if c == 0x0000 or c == 0x0301:
            cls[i] = ord('t')
        elif c == 0x0300:
            cls[i] = ord('c')
        elif 0x0300 <= c < 0x031C:
            cls[i] = ord('c')
        elif c in GLYPH_MAP:
            cls[i] = ord('g')
        else:
            cls[i] = ord('x')
    return cls


def pass_b(rom, refs, spans, claimed, min_glyphs=40, min_terms=2, max_x_gap=1):
    """Maximal text regions (glyph/control/terminator, tolerating <=max_x_gap stray 'x'),
    that are not claimed and have ~no inbound pointers -> computed-index / walk candidates."""
    cls = code_class(rom)
    n2 = len(cls)
    G, C, T, X = ord('g'), ord('c'), ord('t'), ord('x')
    regions = []
    i = 0
    while i < n2:
        if cls[i] not in (G, C):
            i += 1
            continue
        start = i
        glyphs = terms = xs = 0
        j = i
        gap = 0
        while j < n2:
            k = cls[j]
            if k == G:
                glyphs += 1; gap = 0
            elif k == C:
                gap = 0
            elif k == T:
                terms += 1; gap = 0
            else:  # X
                gap += 1
                xs += 1
                if gap > max_x_gap:
                    xs -= gap            # don't count the trailing gap that broke us
                    j -= (gap - 1)
                    break
            j += 1
        lo = ROM_BASE + start * 2
        hi = ROM_BASE + j * 2
        i = j + 1
        if glyphs < min_glyphs or terms < min_terms:
            continue
        if any(s_lo < hi and lo < s_hi for s_lo, s_hi, _ in spans):  # overlaps claimed
            continue
        if lo >= tr.POOL_START:
            continue
        # content-density gate (same idea as pass A): sample-decode the head and require a
        # real kana/kanji presence, so stat/graphics tables that decode to symbol/□ runs drop.
        _f, _n, head = score_text(rom, lo, 120)
        if glyphs < 60 or not _content_ok(head):
            continue
        inbound = sum(1 for a in refs if lo <= a < hi)
        base_refd = lo in refs
        regions.append(dict(lo=lo, hi=hi, glyphs=glyphs, terms=terms,
                            inbound=inbound, base_refd=base_refd, sample=head[:48]))
    # the interesting ones: real text, but the pointer scan can't see them
    regions = [r for r in regions if r["inbound"] <= max(1, r["terms"] // 8)]
    regions.sort(key=lambda r: -r["glyphs"])
    return regions


def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")
    rom = ROM.read_bytes()

    spans = claimed_spans(rom)
    _claimed, _owned = claimed_lookup(spans)
    cave = cave_coverage.covered_addrs()           # text caves/patches translate (not Sections)

    def claimed(addr):                             # Sections ∪ caves/patches ∪ VM-reachable prose
        if _claimed(addr) or any((addr + d) in cave for d in (0, 2, 4, 6)):
            return True
        # In the event-VM bank a pointer often targets a dispatch prefix (cond-jump chain /
        # pointer-half) that FLOWS into already-captured prose — audit_reachability proves all
        # reachable bank prose is owned, so resolve the target to its sentence and accept it.
        if VM_BANK_LO <= addr < VM_BANK_HI:
            g = vmflow.prose_start(rom, addr, VM_BANK_LO, VM_BANK_HI, tr.GLYPH_MAP)
            if g is not None and _claimed(g):
                return True
        return False

    refs = build_refmap(rom)
    print(f"cave/patch-covered text addrs: {len(cave)}")

    orphans = pass_a(rom, refs, claimed)
    regions = pass_b(rom, refs, spans, claimed)

    CSV_ORPHANS.parent.mkdir(parents=True, exist_ok=True)
    with CSV_ORPHANS.open("w", newline="", encoding="utf-8") as fh:
        w = csv.writer(fh)
        w.writerow(["addr", "nrefs", "ref_sites", "frac", "glyphs", "sample"])
        for r in orphans:
            w.writerow([f"{r['addr']:08X}", r["nrefs"],
                        " ".join(f"{s:08X}" for s in r["sites"][:8]),
                        r["frac"], r["glyphs"], r["sample"]])
    with CSV_REGIONS.open("w", newline="", encoding="utf-8") as fh:
        w = csv.writer(fh)
        w.writerow(["lo", "hi", "bytes", "glyphs", "terms", "inbound_ptrs",
                    "base_referenced", "sample"])
        for r in regions:
            w.writerow([f"{r['lo']:08X}", f"{r['hi']:08X}", r["hi"] - r["lo"],
                        r["glyphs"], r["terms"], r["inbound"], r["base_refd"],
                        r["sample"]])

    clusters = cluster_orphans(orphans)
    print(f"claimed spans: {len(spans)}   refmap pointers: {len(refs)}")
    print(f"\nPASS A — referenced-but-UNOWNED strings: {len(orphans)} "
          f"in {len(clusters)} consumer-table clusters")
    for c in clusters:
        print(f"  table {c['ref_lo']:08X}-{c['ref_hi']:08X}  x{c['n']:<3} -> "
              f"strings {c['tgt_lo']:08X}-{c['tgt_hi']:08X}")
        for s in c["samples"]:
            print(f"        {s}")
    print(f"\nPASS B — unclaimed text regions w/ ~no inbound pointers "
          f"(computed-index / walk candidates): {len(regions)}")
    for r in regions[:30]:
        flag = "base-ref" if r["base_refd"] else "NO-ref"
        print(f"  {r['lo']:08X}-{r['hi']:08X}  {r['glyphs']:4}g {r['terms']:3}t  "
              f"{flag:8} {r['sample']}")
    if len(regions) > 30:
        print(f"  … +{len(regions) - 30} more in {CSV_REGIONS.name}")
    print(f"\nwrote {CSV_ORPHANS}\nwrote {CSV_REGIONS}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
