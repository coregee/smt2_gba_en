"""Event-VM script pointer remapping for story_expand repoints.

Why this exists (found 2026-06-12 via the AI-harness live session + static
trace of the opening dream scene): the story bank's script code is full of
embedded 32-bit stream pointers — jump/branch ops (0x30B/0x30C/0x30E/0x30F,
the 0x313 in-window choice rows, the 0x410 yes/no pair, the 0x413
multi-variant response lists, plain u32 option-label tables in the
walker's skip_tables regions, …). Many of them point INTO the middle of a
walker entry (choice loops re-display a page; rejection paths re-prompt).
The 0x0350 expand head only covers the entry START, so:

  1. a branch to an interior address replayed the original Japanese bytes
     (the "answer No and the dialogue loops back in Japanese" report), and
  2. menu/choice label drawers that read a pointed-to string token-by-token
     drew the raw [0x0350][ptr] head as garbage glyphs and then ran into
     stale JP (the appraiser/VB service menus).

Fix: a pooled English blob is BOTH a valid VM stream and a valid drawable
token string, so every reference — executed or drawn — can be rewritten to
the pool. This module:

  * tokenizes original streams exactly like the story walker (so byte
    positions of every token are known),
  * scans for embedded pointer pairs (lo,hi with hi in the story-bank high
    halves 0x0801..0x080B), excluding pairs whose lo-word is a prose glyph
    of a known string (kanji 近金吟銀九倶句区狗玖苦 in dialogue would
    otherwise false-positive),
  * maps interior targets of translated entries to offsets in the encoded
    English blob by anchor alignment: the bulk-translation validator
    enforced ordered equality of all non-{n} tokens, so opcodes /
    {WAIT}/{PAGE}/name tokens pair 1:1 (autowrap-inserted {WAIT}{PAGE} are
    skipped greedily),
  * and rewrites every site whose target is remapped.

Unmappable interiors (a target mid-glyph-run has no defined EN position)
are left pointing at the original JP — the pre-fix behavior — and logged.
"""
from __future__ import annotations

import json
from engine.script import rommap
from paths import ProjectPaths

ROM_BASE = 0x08000000

_DATA = ProjectPaths.discover().text_config_root

STOK = {0x0300: "{n}", 0x0316: "{WAIT}", 0x0317: "{PAGE}", 0x031A: "{ALEPH}",
        0x031B: "{HIROKO}", 0x031C: "{ZAYIN}", 0x031D: "{GIMMEL}", 0x036E: "{MACCA}"}
STOK_REV = {v: k for k, v in STOK.items()}
# {n} is NOT an anchor: translators and autowrap both move line breaks freely.
NON_ANCHOR_STOK = {"{n}"}


class Tok:
    __slots__ = ("addr", "size", "kind", "key")

    def __init__(self, addr, size, kind, key):
        self.addr = addr      # absolute ROM address of the token
        self.size = size      # encoded byte length
        self.kind = kind      # 'glyph' | 'op' | 'stok' | 'pad'
        self.key = key        # canonical string ('{=hex}', '{WAIT}', glyph char)


def _opargs():
    return {int(k, 16): v for k, v in
            json.loads((_DATA / "opcode_args.json").read_text(encoding="utf-8")).items()}


# P0 per-opcode layout spec (docs/opcode-representation-plan.md). Supersedes the flat OPARGS
# arg count for the under-counted pointer ops whose high-word otherwise leaks as a bare kanji.
_SPEC = {int(k, 16): v for k, v in
         json.loads((_DATA / "opcode_spec.json").read_text(encoding="utf-8")).items()}
# P2 step 1: only these FIXED leakers have had their `replace` fields migrated to the folded
# form (dump/migrate_replaces.py). The walker must fold EXACTLY this set so original and replace
# token streams stay in lockstep. DEFERRED to step 2 (capture-boundary / tail_cluster changes):
# 0x3E1 (fixed but in VARIABLE_OPS) and the count-driven 0x313 / 0x413.
_FOLDED = {0x030C, 0x030F, 0x0356, 0x0359, 0x033D}


def oplen_words(c, opargs):
    """Operand words for opcode c: the corrected spec length for the migrated FIXED leakers
    (folds the leaked pointer high-word into the op blob), else the legacy OPARGS count."""
    if c in _FOLDED and c in _SPEC:
        return _SPEC[c]["len"]
    return opargs.get(c, 0) or 0


def tokenize_stream(rom, addr, glyph_map, opargs, hi_limit):
    """Token list of one original stream, mirroring extract_story_bank's grouping.
    Stops after the 0x0301/0x0000 terminator (terminator not included).

    A glyph whose code is a story-bank address high half (0x0801..0x080B —
    近金吟銀九倶句区狗玖苦) directly after an op is an under-captured operand
    tail (opcode_args under-counts some layouts); mark it 'optail' so it can
    anchor like the op itself — branch targets often sit right after one."""
    toks = []
    a = addr
    while a < hi_limit:
        c = rom[a - ROM_BASE] | (rom[a - ROM_BASE + 1] << 8)
        if c in (rommap.TERM_MSG, rommap.TERM_NUL):
            break
        if c in STOK:
            toks.append(Tok(a, 2, "stok", STOK[c]))
            a += 2
        elif c == rommap.PAD_WORD:
            toks.append(Tok(a, 2, "pad", None))
            a += 2
        elif rommap.OP_LO <= c <= rommap.VMCTRL_HI:
            n = 2 + oplen_words(c, opargs) * 2
            blob = bytes(rom[a - ROM_BASE:a - ROM_BASE + n])
            toks.append(Tok(a, n, "op", "{=" + blob.hex() + "}"))
            a += n
        elif c in glyph_map:
            kind = "glyph"
            if rommap.OPTAIL_LO <= c <= rommap.OPTAIL_HI and toks and toks[-1].kind in ("op", "optail"):
                kind = "optail"
            toks.append(Tok(a, 2, kind, glyph_map[c]))
            a += 2
        else:
            break          # non-text word: the walker stops here too
    return toks


def tokenize_rep(rep, char2code, zero_width):
    """Token list of a (post-autowrap) replace string: (key, kind, enc_len)."""
    out, i = [], 0
    while i < len(rep):
        ch = rep[i]
        if ch == "{":
            j = rep.index("}", i)
            tok = rep[i:j + 1]
            if tok.startswith("{="):
                out.append((tok, "op", len(bytes.fromhex(tok[2:-1]))))
            elif tok in STOK_REV:
                out.append((tok, "stok", 2))
            else:
                raise ValueError(f"unknown token {tok}")
            i = j + 1
        elif ord(ch) in zero_width:
            i += 1
        else:
            code = char2code.get(ch)
            if code is None:
                raise ValueError(f"no glyph for {ch!r}")
            kind = "glyph"
            if (rommap.OPTAIL_LO <= code <= rommap.OPTAIL_HI and out
                    and out[-1][1] in ("op", "optail")):
                kind = "optail"              # preserved operand-tail kanji
            out.append((ch, kind, 2))
            i += 1
    return out


def _is_anchor(kind, key):
    return (kind in ("op", "optail")
            or (kind == "stok" and key not in NON_ANCHOR_STOK))


# Every value-substitution opcode that reads its payload from RAM/an accessor and consumes NO
# stream operand — verified from ScriptOp_DrawCharOrSubstitute 0x08132b40 (the lone operand
# consumer is the `if(op==0x327) PC++` pre-dispatch; the jump-table cases all read RAM: 0x31E/22
# species, 0x31F race, 0x320/2E party, 0x321 item @[0x0203...]→Item_GetRecord32, 0x323 number
# @0x0203db2c, 0x324/25 combatant, 0x2F coins←Coins_Get, 0x328 area name @0x0203db72 / 0x329
# multi-name builder — both read from RAM/tables, never the stream).  opcode_args over-counts them
# as 1-operand, so the extractor groups the FOLLOWING token into the op ({=2103<glyph>}).  0x327
# RACE_NAME2 is the ONE genuine 1-operand sub — NOT listed (its bundled word IS its operand).
NAME_SUB_OPS = (0x031E, 0x031F, 0x0320, 0x0321, 0x0322, 0x0323,
                0x0324, 0x0325, 0x0328, 0x0329, 0x032E, 0x032F)


def _anchor_key(key):
    """Canonical anchor key for pairing. The name/value-sub opcodes (NAME_SUB_OPS) are 0-operand
    at runtime, but the extractor over-counts them as 1-operand (opcode_args), so the original
    stream groups the FOLLOWING token into the op token ({=2103<glyph>}) while a cleaned replace
    may drop that swallowed JP particle/colon/counter/newline ({=2103}). Anchor on the sub opcode
    alone so the two still pair (otherwise stripping a leaked token un-maps interior branch targets)."""
    if key.startswith("{=") and key.endswith("}"):
        h = key[2:-1]
        if len(h) >= 8 and int.from_bytes(bytes.fromhex(h)[0:2], "little") in NAME_SUB_OPS:
            return "{=" + h[:4] + "}"
    return key


def align_anchors(orig_toks, rep_toks):
    """Pair original anchors with replace anchors, allowing extra {WAIT}/{PAGE}
    in the replace (autowrap pagination inserts them). Returns a list mapping
    original anchor ordinal -> rep token index, or None on mismatch."""
    rep_anchor_idx = [i for i, (k, kind, _s) in enumerate(rep_toks)
                     if _is_anchor(kind, k)]
    out = []
    ri = 0
    for t in orig_toks:
        if not _is_anchor(t.kind, t.key):
            continue
        while True:
            if ri >= len(rep_anchor_idx):
                return None
            j = rep_anchor_idx[ri]
            key = rep_toks[j][0]
            if _anchor_key(key) == _anchor_key(t.key):
                out.append(j)
                ri += 1
                break
            if key in ("{WAIT}", "{PAGE}"):      # autowrap-inserted break
                ri += 1
                continue
            return None
    # any unconsumed rep anchors must be inserted breaks
    for k in rep_anchor_idx[ri:]:
        if rep_toks[k][0] not in ("{WAIT}", "{PAGE}"):
            return None
    return out


def map_interiors(orig_toks, rep_toks, targets):
    """For each target address, the byte offset in the encoded replace blob
    that corresponds to it (or None if unmappable)."""
    pairing = align_anchors(orig_toks, rep_toks)
    rep_off = []
    o = 0
    for (_k, _kind, s) in rep_toks:
        rep_off.append(o)
        o += s
    by_addr = {t.addr: i for i, t in enumerate(orig_toks)}
    anchor_ord = {}                          # orig token index -> anchor ordinal
    n = 0
    for i, t in enumerate(orig_toks):
        if _is_anchor(t.kind, t.key):
            anchor_ord[i] = n
            n += 1
    res = {}
    for tgt in targets:
        k = by_addr.get(tgt)
        if k is None:
            res[tgt] = None
            continue
        if pairing is None:
            res[tgt] = None
            continue
        t = orig_toks[k]
        if _is_anchor(t.kind, t.key):
            j = pairing[anchor_ord[k]]
            res[tgt] = rep_off[j]
            continue
        # glyph/pad target: resolve to the START of its glyph-run — the EN position
        # right after the run's preceding anchor (op / jump / {WAIT} / {PAGE}).  Walk
        # back over pads AND glyphs: a target landing MID-run is a shared-suffix branch
        # target — the JP compresses "<variant><shared>" by jumping PAST a short variant
        # into the shared run, which has no op boundary (e.g. the casino exchange line
        # jumps into コインにかえてあげる past ゴールド/ダーク, and the rate line jumps into
        # ...につき past the variant "10"/"100").  Such a target has no per-glyph EN
        # position (JP glyph count != EN), so it collapses onto its run start, the only
        # position the anchor pairing defines — which is exactly where the shared tail's
        # English begins.  (Was: only pads skipped, so mid-run targets returned None and
        # the jump replayed the original JP — the "…you get one コインにかえてあ" leak.)
        p = k - 1
        while p >= 0 and orig_toks[p].kind in ("pad", "glyph"):
            p -= 1
        if p < 0:
            res[tgt] = 0
        elif _is_anchor(orig_toks[p].kind, orig_toks[p].key):
            j = pairing[anchor_ord[p]]
            res[tgt] = rep_off[j] + rep_toks[j][2]
        else:
            res[tgt] = None                  # run starts after a bare {n}: undefined
    return res


def scan_pairs(buf, base_addr, lo, hi):
    """All aligned (lo,hi) halfword pairs in buf forming an even address in
    [lo,hi). Returns [(byte_offset_of_lo_word, target_address)]."""
    out = []
    for o in range(0, len(buf) - 3, 2):
        h = buf[o + 2] | (buf[o + 3] << 8)
        if rommap.OPTAIL_LO <= h <= rommap.OPTAIL_HI:
            t = (h << 16) | buf[o] | (buf[o + 1] << 8)
            if lo <= t < hi and not (t & 1):
                out.append((o, t))
    return out


class BankRefs:
    """Pre-pack analysis of the story bank: known-string token maps, candidate
    pointer sites, per-entry interior targets."""

    def __init__(self, rom, lo, hi, story_fields, other_addrs, glyph_map, char2code,
                 zero_width):
        self.lo, self.hi = lo, hi
        self.glyph_map = glyph_map
        self.char2code = char2code
        self.zero_width = zero_width
        self.opargs = _opargs()
        self.bank0 = bytes(rom[lo - ROM_BASE:hi - ROM_BASE])
        # tokenize every known string (story entries + other sections' bank
        # strings) for glyph-position exclusion and entry spans
        self.toks = {}                       # entry start addr -> [Tok]
        self.spans = []                      # (start, end, addr) story entries only
        self.clean = {}                      # entry addr -> capture ended at a real terminator
        self.stop = {}                       # entry addr -> first byte after the last token
        glyph_pos = set()
        for addr in sorted(set(story_fields) | set(other_addrs)):
            if not (lo <= addr < hi):
                continue
            ts = tokenize_stream(rom, addr, glyph_map, self.opargs, hi)
            self.toks[addr] = ts
            stop = (ts[-1].addr + ts[-1].size) if ts else addr
            w = (rom[stop - ROM_BASE] | (rom[stop - ROM_BASE + 1] << 8)
                 if stop + 1 < hi else 0xFFFF)
            self.stop[addr] = stop
            self.clean[addr] = w in (rommap.TERM_MSG, rommap.TERM_NUL)
            end = stop + (2 if self.clean[addr] else 0)
            if addr in story_fields:
                self.spans.append((addr, end, addr))
            for t in ts:
                if t.kind == "glyph":
                    glyph_pos.add(t.addr)
        self.spans.sort()
        self.span_end = {s: e for s, e, _a in self.spans}
        # candidate sites: lo-word must not be a known prose glyph
        self.sites = [(o, t) for o, t in scan_pairs(self.bank0, lo, lo, hi)
                      if (lo + o) not in glyph_pos]
        # interior targets per story entry
        import bisect
        starts = [s for s, _e, _a in self.spans]
        self.interior = {}                   # entry addr -> sorted set of targets
        for _o, t in self.sites:
            i = bisect.bisect_right(starts, t) - 1
            if i >= 0:
                s, e, a = self.spans[i]
                if s < t < e:
                    self.interior.setdefault(a, set()).add(t)

    def interiors_of(self, addr):
        return sorted(self.interior.get(addr, ()))

    def add_targets(self, targets):
        """Register branch targets discovered OUTSIDE the bank scan (4-aligned
        record fields / Thumb literal pools elsewhere in ROM — the shop-module
        revisit-prompt literal class, 2026-06-13).  Interior hits join
        self.interior so their entries force-repoint and get pool offsets;
        entry-start hits need no registration (script_remap covers them)."""
        import bisect
        starts = [s for s, _e, _a in self.spans]
        for t in targets:
            i = bisect.bisect_right(starts, t) - 1
            if i >= 0:
                s, e, a = self.spans[i]
                if s < t < e:
                    self.interior.setdefault(a, set()).add(t)

    # ops with variable-length argument blocks (choice rows / response lists /
    # jump tables / option pointer runs) — opcode_args.json under-counts them,
    # so a non-clean entry's trailing capture of one is truncated operand data
    VARIABLE_OPS = {0x0313, 0x0413, 0x03E1, 0x0410, 0x0442, 0x03C5, 0x0362,
                    0x0360, 0x0361, 0x0363, 0x0401}

    def tail_cluster(self, addr):
        """For a non-clean entry: address + token index of the trailing
        truncated-op cluster. The walker stopped mid-data, and that data
        belongs to the LAST op (a variable-length one whose operand words can
        decode as arbitrary glyphs) — so the cluster runs from the last op
        token to the end, when that op is a known variable-length opcode or
        only operand-junk (optail/pad/glyph misreads) follows it. Entries
        ending in prose return (stop_addr, len(toks))."""
        ts = self.toks[addr]
        last_op = None
        for i in range(len(ts) - 1, -1, -1):
            if ts[i].kind == "op":
                last_op = i
                break
        if last_op is not None:
            code = int(ts[last_op].key[2:6][2:4] + ts[last_op].key[2:6][0:2], 16)
            tail = ts[last_op + 1:]
            junk_only = all(t.kind in ("optail", "pad") or t.kind == "glyph"
                            for t in tail) and not any(t.kind == "stok" for t in tail)
            if code in self.VARIABLE_OPS or (junk_only and len(tail) <= 8):
                return ts[last_op].addr, last_op
        k = len(ts)
        while k > 0 and ts[k - 1].kind in ("op", "optail", "pad"):
            k -= 1
        if k == len(ts):
            return self.stop[addr], k
        return ts[k].addr, k
