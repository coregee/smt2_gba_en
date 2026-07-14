#!/usr/bin/env python3
"""Translation source pipeline: extract editable string files, pack them into a ROM.

Source files: text/corpus/<section>.json, a list of entries. Each entry holds
one or more translatable FIELDS:
  inline  { "addr","max","term","original","replace" }              # in place, budget-capped
  repoint { "ptrs":[…],"addr","max","term","original","replace" }   # dedup'd ptr-table string
  desc    { "ptr","addr","term","original","replace" }              # single pointer -> always repoint
  label   { "kind":"label","slots":[[lit,x],…],"original","replace" }   # menu glyph literals
A paired entry bundles fields under keys (e.g. skills: {"name":{…},"desc":{…}}).

Translate by setting "replace" (null = keep Japanese). Tokens usable in replace:
  {n}=newline, {ALEPH}/{HIROKO}/{ZAYIN}/{GIMMEL}=party names, {MACCA}=macca amount.

`pack` writes every non-null replace; `extract` (re)generates and MERGES (keeps your
replace, by field key). Inline writes in place when it fits, else (if a pointer exists)
repoints to a free POOL that auto-grows the ROM. `desc`/single-`ptr` always repoint.

Usage:  python text/script/tr.py extract | pack in.gba out.gba
"""
import argparse
import bisect
import hashlib
import json
import os
import re
import sys
from collections import namedtuple
from pathlib import Path

if __package__ in (None, ""):
    sys.path.insert(0, str(Path(__file__).resolve().parents[2]))

from paths import ProjectPaths

_PATHS = ProjectPaths.discover()
ROOT = _PATHS.project_root

from font.atlas import GLYPH_MAP, character_codes  # noqa: E402
from engine.script import rommap    # noqa: E402
from text.script import sections    # noqa: E402  the section manifest (single registry)
from text.script import scriptrefs  # noqa: E402  used by 3 pack phases

DATA = _PATHS.text_config_root
TR = _PATHS.corpus_root
ROM_BASE = rommap.ROM_BASE
u16 = lambda rom, a: int.from_bytes(rom[a - ROM_BASE:a - ROM_BASE + 2], "little")
u32 = lambda rom, a: int.from_bytes(rom[a - ROM_BASE:a - ROM_BASE + 4], "little")
POOL_START = rommap.POOL_START          # pool/table layout — single source of truth in rommap.py
NAME_TABLE = rommap.NAME_TABLE
NAME_TABLE_SIZE = rommap.NAME_TABLE_SIZE
ITEM_TABLE = rommap.ITEM_TABLE
ITEM_TABLE_SIZE = rommap.ITEM_TABLE_SIZE
MARKER_TABLE = rommap.MARKER_TABLE
MARKER_TABLE_SIZE = rommap.MARKER_TABLE_SIZE
MARKER_BASE = rommap.MARKER_BASE
NAME_COUNT = rommap.NAME_COUNT
SCRIPT_EXPAND_CODE = rommap.SCRIPT_EXPAND_CODE   # event-VM opcode 0x0350 "expanded text" (patch_dialog.py)
BATTLE_MSG_TABLE = rommap.BATTLE_MSG_TABLE       # FUN_080ec038 table[id] -> battle template ptr

TOKENS = {"n": 0x0300, "ALEPH": 0x031A, "HIROKO": 0x031B, "ZAYIN": 0x031C,
          "GIMMEL": 0x031D, "MACCA": 0x036E, "WAIT": 0x0316, "PAGE": 0x0317}
REV = {v: "{" + k + "}" for k, v in TOKENS.items()}

# Ink-producing substitution opcodes (name/race/item/count/area/macca subs + party names),
# from opcode_spec.json `ink:True`. A story message can BEGIN with one of these — e.g. the
# negotiation reaction line "{DEMON_NAME}は{n}ニコリと笑った" opens with the demon-name sub.
# The walker must treat them as message starts, not just inter-message control; otherwise the
# leading "{name}は{n}" prefix is dropped and the engine renders an orphan "Nameは" before the
# isolated predicate chunk (the recurring negotiation particle glitch).
INK_SUB_OPS = frozenset(
    int(k, 16) for k, v in
    json.loads((DATA / "opcode_spec.json").read_text(encoding="utf-8")).items()
    if v.get("ink"))

# --- readable substitution-token aliases (2026-06-15) ----------------------------------
# The name/value substitution opcodes (the 0x31A-0x32F family — species, race, item, count,
# enemy, … — see docs/event-vm.md "name/value substitution sub-codes") are stored in the
# translation JSONs under readable names for legibility, e.g. {DEMON_NAME}/{RACE_NAME}.
# They are expanded back to the canonical {=hex} form on load (`canon`) BEFORE encode/
# autowrap/scriptrefs ever see them, so those subsystems are unchanged. Only the BARE 2-byte
# forms carry an alias — story's operand-bundled {=XX03YYYY} forms stay raw, because
# scriptrefs anchors on the whole token (splitting them would desync the branch-remap).
ALIAS_OPC = {"DEMON_NAME": 0x031E, "RACE_NAME": 0x031F, "PARTY_NAME": 0x0320,
             "ITEM_NAME": 0x0321, "DEMON_NAME2": 0x0322, "NUMBER": 0x0323,
             "ACTOR_NAME": 0x0324, "ENEMY_NAME": 0x0325, "RACE_NAME2": 0x0327,
             "COINS": 0x032F,
             # inline control ops (0-arg, no ink) — aliased for legibility like {WAIT}/{PAGE}:
             "SLOW": 0x0315}   # ScriptOp_SlowReveal: slow per-character text reveal (20-frame delay)
ALIAS_TO_HEX = {"{%s}" % k: "{=%s}" % v.to_bytes(2, "little").hex() for k, v in ALIAS_OPC.items()}
HEX_TO_ALIAS = {h: a for a, h in ALIAS_TO_HEX.items()}

# --- control-op legibility aliases (2026-06-23) -----------------------------------------------------
# The event-VM CONTROL opcodes (jumps, flags, menus, effects, …) are stored in the JSONs under readable
# names instead of raw {=hex}, e.g. {=0f03402c} -> {JUMP:402c}, {=1104} -> {RET}.  PREFIX-SPLIT: only the
# 2-byte opcode prefix is renamed; the operand hex is kept VERBATIM, so the round-trip is byte-exact and
# the token COUNT is unchanged -> canon() reproduces the IDENTICAL {=hex} stream encode/autowrap/scriptrefs
# see (anchor-neutral — the property the variable-op fold lacked).  EXCLUDES the name/value sub ops
# (0x31A-0x32F, aliased bare via ALIAS_OPC) and sentinels (0xFFFF/0xFFFE) — their raw form is load-bearing.
# Names from the Ghidra-grounded opcode-name workflow (handlers documented in docs/event-vm.md).
CTRL_OPC = {
    0x0303: 'SOUND', 0x0304: 'SPAWNOBJ', 0x0305: 'SHOWEVTOBJ', 0x0307: 'DESPAWN',
    0x0308: 'SETACTOR', 0x0309: 'ENEMYTYPE', 0x030A: 'ITEMPARAM', 0x030B: 'GIVEITEMBR',
    0x030C: 'CJUMP', 0x030D: 'CJALLY', 0x030E: 'SUBMENU', 0x030F: 'JUMP', 0x0310: 'SETF_D5',
    0x0311: 'MSGPARAM', 0x0312: 'SETFLAG', 0x0313: 'CHOICE', 0x0319: 'CLRFLAG',
    0x032B: 'DESPAWNSLOT', 0x032C: 'ADJMACCA', 0x032D: 'CJRAND', 0x0334: 'SELJMP',
    0x0336: 'MACCALT', 0x0338: 'SPAWNSCN', 0x033A: 'OPENMENU', 0x033B: 'ITEMLIST',
    0x033C: 'CJCANEQ', 0x033E: 'CJEQUIP', 0x033F: 'GIVESTAGED', 0x0341: 'ALLOCOBJ',
    0x0352: 'PLAYSOUND', 0x0353: 'ALIGN', 0x0355: 'CJALIGN', 0x0356: 'CKALIGN',
    0x0357: 'LVLSET', 0x0358: 'DELAY', 0x0359: 'JNODEMON', 0x035A: 'COMPFULL',
    0x035C: 'DRAINHP', 0x035E: 'INFLICT', 0x035F: 'ENDPAGE', 0x0360: 'MENU1', 0x0361: 'MENU2',
    0x0362: 'MENU3_OPEN', 0x0363: 'MENUSEL', 0x0366: 'CJSTATUS', 0x0368: 'SETVAR2',
    0x036B: 'WARP', 0x036F: 'CJPARTY', 0x0372: 'SHOP', 0x0374: 'HEALPARTY', 0x0375: 'PARTYMP',
    0x0376: 'MASKSTAT', 0x0377: 'PARTYMOD', 0x0378: 'REMOVECMB', 0x0379: 'GIVEITEM',
    0x037A: 'TAKEITEM', 0x037B: 'SHOWEVT', 0x037D: 'NAMEENT', 0x0382: 'RSTSEL',
    0x0388: 'SPAWN', 0x038D: 'CJITEMCNT', 0x0392: 'MSGCLOSE', 0x0395: 'CALLFX',
    0x03A3: 'SPENDMAC', 0x03AC: 'OPENUI', 0x03B6: 'IFITEM', 0x03C0: 'SETGOT', 0x03C5: 'MENU3',
    0x03C6: 'CJEQUIPB', 0x03C7: 'ALIGNSET', 0x03CE: 'RANDJUMP', 0x03CF: 'CJLVL',
    0x03D0: 'HPLEJMP', 0x03D1: 'LUCKJMP', 0x03D2: 'CKSTAT', 0x03D3: 'LUCKBR', 0x03D5: 'CJNEGO',
    0x03D6: 'NEGOBR', 0x03D7: 'MODEDISP', 0x03DF: 'NEGOMETER', 0x03E0: 'NEGLUCK',
    0x03E1: 'NEGOJUMP', 0x03E2: 'NEGOT', 0x03E3: 'AGICHECK', 0x03E6: 'NEGOUT',
    0x0401: 'SETACTOR_B', 0x0402: 'MENU3_B', 0x0403: 'MINIGAME', 0x0404: 'SPAWNDMN',
    0x0405: 'DELDEMON', 0x0406: 'CUTSCENE', 0x0407: 'CUTSTOP', 0x0408: 'CUTSCENEB',
    0x0409: 'CHOICE3', 0x040A: 'SNDFADE', 0x040B: 'CMPJMP', 0x040C: 'SETSCENE',
    0x040D: 'SETSTAT', 0x040E: 'SETFLAG_B', 0x040F: 'NEGOT_B', 0x0410: 'CASEBR', 0x0411: 'RET',
    0x0412: 'NEGOSCR', 0x0413: 'NEGRESP', 0x0421: 'SETVAR3', 0x0422: 'DMGPCT',
    0x0423: 'CJMOON', 0x0424: 'MOONSCRATCH', 0x0425: 'NOP', 0x0426: 'SPAWNGRP',
    0x0429: 'WARP_B', 0x042D: 'NOP_C', 0x042E: 'NOP_D', 0x042F: 'NOP_B', 0x0430: 'PARTYRST',
    0x0432: 'SETSKILLS', 0x0433: 'VRAMCOPY', 0x0434: 'PAYMACCA', 0x0435: 'CASINO',
    0x0438: 'ITEMCALC', 0x043A: 'SKIP1', 0x043D: 'CJDEMON', 0x043F: 'CHOICE4',
    0x0440: 'CJFLAG35', 0x0441: 'SELLIST', 0x0442: 'NEGOEVAL', 0x0443: 'FUSEOUT',
    0x0445: 'EFFECT', 0x0446: 'APPLYSTAT', 0x0447: 'CHKJUMP', 0x0448: 'CHKCOND',
    0x044A: 'NEGOADJ', 0x044B: 'ALIGNADJ', 0x044C: 'STARTNEGO',
}
_CTRL_PFX2NAME = {"%02x%02x" % (op & 0xFF, op >> 8): n for op, n in CTRL_OPC.items()}   # LE op hex -> NAME
_CTRL_NAME2PFX = {n: p for p, n in _CTRL_PFX2NAME.items()}
_CTRL_HEX_RE = re.compile(r"\{=([0-9a-fA-F]+)\}")
_CTRL_NAME_RE = re.compile(r"\{([A-Z][A-Z0-9_]*)(:[0-9a-fA-F]*)?\}")


def _ctrl_to_hex(m):
    pfx = _CTRL_NAME2PFX.get(m.group(1))
    if pfx is None:
        return m.group(0)                            # sub/structural/unknown name — leave for the sub pass
    return "{=%s%s}" % (pfx, (m.group(2)[1:] if m.group(2) else "").lower())


def _ctrl_to_name(m):
    hexs = m.group(1)
    name = _CTRL_PFX2NAME.get(hexs[:4].lower())
    if name is None:
        return m.group(0)                            # not a control op (sub/sentinel/unknown) — leave raw
    rest = hexs[4:]
    return "{%s}" % name if not rest else "{%s:%s}" % (name, rest)


def canon(s):
    """Expand readable aliases -> canonical {=hex}: control-op names ({JUMP:..}/{RET}) via prefix-join,
    then the bare name/value subs ({DEMON_NAME}…). Idempotent; structural tokens ({WAIT}/{ALEPH}/…) and
    non-control names pass through untouched, so encode/autowrap/scriptrefs see the exact original {=hex}."""
    if not s or "{" not in s:
        return s
    s = _CTRL_NAME_RE.sub(_ctrl_to_hex, s)
    for a, h in ALIAS_TO_HEX.items():
        if a in s:
            s = s.replace(a, h)
    return s


def aliasify(s):
    """Reverse of canon: {=hex} control ops -> {NAME}/{NAME:operand}, then bare subs -> {DEMON_NAME}….
    Operand hex preserved verbatim; the sub ops (0x31A-0x32F) stay raw when bundled (load-bearing)."""
    if not s or "{=" not in s:
        return s
    s = _CTRL_HEX_RE.sub(_ctrl_to_name, s)
    for h, a in HEX_TO_ALIAS.items():
        if h in s:
            s = s.replace(h, a)
    return s


CHAR2CODE = character_codes()
# Canonical half-width ASCII slots win for letters/digits (ascii+0x9C upper/digit, +0x9D lower).
# The base font has a stray 'S' at 0x00CB (= '/'+0x9C), so
# encoding 'S' to its lowest map code (0x00CB) printed '/'; pin letters/digits to the real slots.
for _ch in "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ":
    CHAR2CODE[_ch] = ord(_ch) + 0x9C
for _ch in "abcdefghijklmnopqrstuvwxyz":
    CHAR2CODE[_ch] = ord(_ch) + 0x9D
CHAR2CODE[" "] = 0x00BC
for _ascii, _fw in [(">", "＞"), ("<", "＜"), ("'", "’"), ("\"", "”")]:
    if _fw in CHAR2CODE:
        CHAR2CODE.setdefault(_ascii, CHAR2CODE[_fw])
# The heart glyph (0x0119) decodes as "❤︎⁠" (heart + VS-15 + word-joiner), so its only CHAR2CODE
# key is that 3-codepoint string; map the bare ❤ to it and drop the zero-width marks in encode().
# ♥ (0x0219) is a single codepoint and already keyed by the loop above.
CHAR2CODE.setdefault("❤", 0x0119)
ZERO_WIDTH = {0xFE0E, 0xFE0F, 0x2060, 0x200B, 0x200C, 0x200D, 0xFEFF}  # VS-15/16, WJ, ZWSP/NJ/J, BOM

# Every section's ROM source spec (bank addresses, strides, pointer tables, walk
# ranges) lives in sections.py — the manifest is the single registry. The per-bank
# layout notes (record formats, count rationale, the element wide/narrow split,
# item id-0xD0 boundary, demon-record +0x22 name field, …) moved there with them.


def decode(rom, addr, maxc, stops={rommap.TERM_NUL, rommap.TERM_MSG}):
    out, codes = [], []
    for i in range(maxc):
        c = u16(rom, addr + i * 2)
        if c in stops:
            break
        codes.append(c)
        if c in REV:
            out.append(REV[c])
        elif c == 0x00BC:
            out.append(" ")
        elif c in GLYPH_MAP:
            out.append(GLYPH_MAP[c])
        elif rommap.TOK_NEWLINE <= c <= rommap.VMCTRL_HI:  # VM control / name-value substitution
            out.append("{=" + c.to_bytes(2, "little").hex() + "}")   # byte-exact, round-trips
        else:
            out.append(f"<{c:04X}>")                     # unmapped glyph / over-read -> flag, not a token
    return "".join(out), codes


def encode(s):
    s = canon(s)                                     # accept readable aliases from any caller
    out, i = bytearray(), 0
    while i < len(s):
        if s[i] == "{":
            j = s.index("}", i)
            tok = s[i + 1:j]
            if tok.startswith("="):                  # {=hex} byte-exact passthrough (control codes / opcodes+args)
                out += bytes.fromhex(tok[1:])
            elif tok in TOKENS:
                out += TOKENS[tok].to_bytes(2, "little")
            else:
                raise ValueError(f"unknown token {{{tok}}}")
            i = j + 1
        elif ord(s[i]) in ZERO_WIDTH:    # variation selectors / joiners ride along with some glyph
            i += 1                       # decodings (e.g. ❤︎⁠) but have no glyph of their own — drop them
        else:
            c = CHAR2CODE.get(s[i])
            if c is None:
                raise ValueError(f"no glyph for {s[i]!r} (add to custom_glyphs.PUNCT, "
                                 f"deriving from a base-font code, or to a half-width VWF slot)")
            out += c.to_bytes(2, "little")
            i += 1
    return bytes(out)


def fields(entry):
    """Yield translatable field dicts: the entry (or its name/desc sub-fields), plus any
    nested per-demon resist lines (aff1/aff2)."""
    if "name" in entry or "desc" in entry:
        for k in ("name", "desc"):
            if k in entry:
                yield entry[k]
    else:
        yield entry
    for k in ("aff1", "aff2"):
        if k in entry:
            yield entry[k]


# --- pipeline guard: opcode pointer-tail kanji must survive translation -------------------------
# Story/dialogue jump & pointer opcodes (0x30B/30C/30E/30F, the choice/branch ops, …) carry a 32-bit
# stream pointer whose HIGH word is the story bank top byte 0x0801..0x080B — and the extractor leaves
# that word in the translatable text as the glyph 近/金/吟/銀/九/倶/句/区/狗/玖 ("optail" anchors,
# bank words 0x0801-0x080A; see scriptrefs.py — 0x080B has no glyph so it leaks as a visible {=80b}
# escape, not the invisible-trap kanji class, so it needs no guard), sitting RIGHT AFTER its
# `{=opcode}`.  A translator who edits one (the live bug:
# 金->? in the corrupted-vision cond-jumps) silently corrupts the jump target -> the event VM jumps
# to a garbage address -> softlock.  So every `{=opcode}<optail-kanji>` pair in `original` MUST
# survive verbatim in `replace`.  (Loose name-sub particles like {=1e03}が are NOT optail kanji and
# are free to drop.)
import re as _re                                       # noqa: E402
from collections import Counter as _Counter            # noqa: E402

_OPTAIL = "".join(GLYPH_MAP[t] for t in range(0x0801, 0x080C) if t in GLYPH_MAP)
_OPTAIL_PAIR = _re.compile(r"\{=[0-9a-fA-F]+\}[" + _re.escape(_OPTAIL) + r"]")


_OPTAIL_OP = _re.compile(r"(\{=[0-9a-fA-F]+\})([" + _re.escape(_OPTAIL) + r"])")


def _is_folded_complete(optoken):
    """True if optoken is one of the P0-folded fixed pointer ops carrying its FULL operand
    (so a following optail-range kanji is genuine prose, not a leaked pointer high-word)."""
    b = bytes.fromhex(optoken[2:-1])
    if len(b) < 2:
        return False
    op = b[0] | (b[1] << 8)
    s = scriptrefs._SPEC.get(op)
    return op in scriptrefs._FOLDED and s is not None and len(b) == 2 + s["len"] * 2


def _leaked_optail_pairs(s):
    """Multiset of {=op}<kanji> pairs where the kanji is a genuine leaked pointer high-word —
    i.e. it follows an op that has NOT absorbed it (the still-unfolded variable/jump-table ops
    and the name-sub over-count). Pairs after a folded-complete fixed op are prose -> excluded."""
    return _Counter(op + k for op, k in _OPTAIL_OP.findall(s or "")
                    if not _is_folded_complete(op))


def check_optail_preserved(field, ctx):
    """Raise if `replace` dropped a pointer-tail kanji that `original` carries after an opcode."""
    if not isinstance(field, dict):
        return
    o, r = field.get("original"), field.get("replace")
    if not o or not r:
        return
    missing = _leaked_optail_pairs(o) - _leaked_optail_pairs(r)
    if missing:
        raise SystemExit(
            f"opcode pointer-tail corrupted in {ctx}: replace dropped {dict(missing)} -- a "
            f"近/金/吟/… kanji right after an opcode is a script-pointer high word; it MUST be kept "
            f"verbatim in the translation or the event VM jumps to garbage (softlock). Restore it.")


# --- pipeline guard: branch-selector opcode operands --------------------------------------------
# A second softlock class (found 2026-06-21, the biotech-lab "...One moment, please" page): opcode
# 0x0334 is a multi-way branch whose handler (0x081336a4) reads the NEXT stream word as a case
# selector v, looks up g_pfnBranchCaseTable 0x08790130[v] (-> 1/2/3/4/default), and latches one of
# four hardcoded weapon/item-shop streams as the next stream.  It never bumps g_wScriptPc, so
# extract_opcode_args (count = how far a handler bumps the PC) records it as 0-operand -> the
# extractor exposes that selector word as an EDITABLE GLYPH right after the {=3403} token (it decodes
# to the full-width ？ = 0x0008, and table[8] = 4).  A translator "corrected" ？ to a half-width ?
# (= 0x00DB), so the selector became 0x00DB -> table[0xDB] is out of bounds -> garbage case -> wrong
# branch (a JP weapon menu) -> softlock.  So the word a branch-selector op reads MUST survive
# translation byte-for-byte.  (Folding it into the {=hex} blob like scriptrefs._FOLDED is the proper
# long-term representation; this guard makes the corruption a build error meanwhile.)
BRANCH_SELECTOR_OPS = {0x0334}
_BRANCHOP_RE = _re.compile(
    r"\{=(?:" + "|".join(f"{op & 0xff:02x}{op >> 8:02x}" for op in BRANCH_SELECTOR_OPS) + r")\}"
    r"(\{=[0-9a-fA-F]+\}|.)", _re.DOTALL)


def _branch_operands(s):
    """Encoded operand bytes (the case selector) following each branch-selector op, in order."""
    return [encode(operand) for operand in _BRANCHOP_RE.findall(s or "")]


def check_branchop_operand_preserved(field, ctx):
    """Raise if `replace` changed the word a branch-selector opcode reads as its case index."""
    if not isinstance(field, dict):
        return
    o, r = field.get("original"), field.get("replace")
    if not o or not r:
        return
    oo, rr = _branch_operands(o), _branch_operands(r)
    if oo != rr:
        raise SystemExit(
            f"branch-selector operand corrupted in {ctx}: the word after a {{=3403}} branch opcode "
            f"is its case index (NOT display text); replace changed {[b.hex() for b in oo]} -> "
            f"{[b.hex() for b in rr]}. Keep it verbatim (e.g. full-width ？ = 0x0008, not ? = "
            f"0x00DB) or the event VM takes a garbage branch (softlock).")


# A real resist line is clean Japanese from a closed vocabulary; records past the real-demon
# range (id >= ~380) hold non-text data at +0x32/+0x48 that decodes to junk (<XXXX>, {=..}, or
# binary misread as sequential kana / ASCII runs like "BCDEFGHIJKL"). Keep only strings with NO
# ASCII that carry an affinity marker: a relationship word (強弱無効吸収反射), an element-list dot
# (・), or a scope word (全/外/系).
_AFF_ASCII = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
_AFF_MARK = "強弱無効吸収反射・全外系"


def is_affinity(t):
    return ("<" not in t and "{=" not in t
            and not any(ch in _AFF_ASCII for ch in t)
            and any(ch in _AFF_MARK for ch in t))


def fkey(f):
    # Merge identity, dispatched on the field-kind (sections.kind_of is the single
    # classifier — no parallel branching here).  Route is irrelevant to identity, so
    # kind_of is called without it (block fields key on addr, same as the else arm).
    k = sections.kind_of(f)
    if k == "label":
        return f["slots"][0][0]
    if k == "repoint":
        return ",".join(f["ptrs"])
    if k == "story":
        return ",".join(f["addrs"])
    return f.get("ptr") or f.get("addr")


# ---------------------------------------------------------------- extract
# One extractor per Source.kind (the manifest in sections.py selects them); each takes
# (rom, sec) and returns the section's fresh entry list. extract() runs every
# non-curated section and merges via write_section (keeps your `replace`).

def extract_name_bank(rom, sec):
    """Fixed-stride record sweep over an inline name field. Section route decides the
    per-entry mechanism flags (sentinel / name_table+aff nests / item_table)."""
    p = sec.source.params
    pad = p.get("pad")
    rows = []
    for i in range(p["count"]):
        a = p["start"] + i * p["stride"] + p["name_off"]
        t, c = decode(rom, a, p["name_max"])
        if pad is not None:
            # fixed unterminated cells (location names): strip the trailing pad run
            # ('@' 0x57 / full-width space 0x3F) for readability; pack() re-pads the
            # English to exactly name_max tokens. All-pad cells are blank -> skipped.
            while c and c[-1] in (pad, 0x003F):
                c.pop()
                t = t[:-1]
        if not c:
            continue
        e = {"addr": f"{a:08X}", "max": p["name_max"],
             "term": "" if pad is not None else "0000",
             "original": t, "replace": None}
        if sec.route == "sentinel":
            e["sentinel"] = True
        if sec.route == "name_table":
            e["name_table"] = True
            e["id"] = i
            # nest the demon's two resist lines (drawn by FUN_080cd2a0 at +0x32/+0x48;
            # over-budget English repoints to the pool via patch_resist.py). Skip junk
            # records (id >= ~380) whose fields aren't real affinity text.
            for key, (aoff, amax) in zip(("aff1", "aff2"), p.get("aff_offsets", ())):
                aa = p["start"] + i * p["stride"] + aoff
                at, ac = decode(rom, aa, amax)
                if len(ac) >= 2 and is_affinity(at):
                    e[key] = {"addr": f"{aa:08X}", "max": amax, "term": "0000",
                              "sentinel": True, "aff": True, "original": at,
                              "replace": None}
        if sec.route == "item_table":
            e["item_table"] = True
            e["id"] = i
        rows.append(e)
    return rows


def extract_paired_records(rom, sec):
    """Record sweep with an inline name + a description pointer (skills, item records)."""
    p = sec.source.params
    rows = []
    for i in range(p["count"]):
        rec = p["start"] + i * p["stride"]
        nt, nc = decode(rom, rec + p["name_off"], p["name_max"])
        if p.get("skip_empty") and not nc:
            continue
        nf = {"addr": f"{rec + p['name_off']:08X}", "max": p["name_max"], "term": "0000",
              "original": nt, "replace": None}
        if sec.route == "sentinel":
            nf["sentinel"] = True
        if sec.route == "item_table":
            nf["item_table"] = True
            nf["id"] = p["id_base"] + i
        ent = {"id": p["id_base"] + i, "name": nf}
        dp = u32(rom, rec + p["desc_ptr_off"])
        if ROM_BASE <= dp < ROM_BASE + len(rom):
            dt, dc = decode(rom, dp, p["desc_max"])
            if dc or not p.get("skip_empty"):
                ent["desc"] = {"ptr": f"{rec + p['desc_ptr_off']:08X}", "addr": f"{dp:08X}",
                               "term": "0301", "original": dt, "replace": None}
        rows.append(ent)
    return rows


# Source(ws_fold=True): dedup near-identical lines that differ ONLY by cosmetic whitespace —
# a manual {n} (0x0300 newline) or a full-width space (　 U+3000) — into ONE entry.  The game
# stores many shop/greeting variants that differ only in line-break/padding ("では　" vs "では　{n}",
# "{ITEM_NAME}は{n}ћ{NUMBER}　になる…" vs the same sans the interior 　); they read identically once
# autowrap re-flows the English (the dialogue window sets strip_manual_n=True, so JP break/space
# placement has ZERO effect on the EN output), so keeping them as separate entries is redundant work
# AND wastes a duplicate pooled blob per variant at pack time.  The key strips {n}/　 so the variants
# collapse; the stored `original` is the first-seen (lowest-src-slot) member, so the fold is
# deterministic.  Distinct JP (different kana/kanji) never collapses — voice-variants stay separate.
_WS_FOLD_RE = re.compile(r"\{n\}|　")


def _ws_dedup_key(t):
    return _WS_FOLD_RE.sub("", t)


def extract_ptr_table(rom, sec):
    """Pointer-table slots into terminated strings, aggregated by TEXT — one entry per
    unique line, carrying every pointer slot and string copy that holds it (translate
    once, lands everywhere).  With Source(ws_fold=True) the dedup is whitespace-insensitive
    (see _ws_dedup_key) — cosmetic {n}/full-width-space variants fold into one entry."""
    p = sec.source.params
    keyf = _ws_dedup_key if p.get("ws_fold") else (lambda t: t)
    by_str = {}
    for lo, hi in p["tables"]:
        for src in range(lo, hi, 4):
            ptr = u32(rom, src)
            if ROM_BASE <= ptr < ROM_BASE + len(rom):
                by_str.setdefault(ptr, []).append(src)
    by_text = {}
    for ptr, slots in by_str.items():
        t, c = decode(rom, ptr, p["str_max"])
        if len(c) < 2:
            continue
        # key folds cosmetic-whitespace variants together; `original` keeps the first-seen
        # (lowest src slot, by ascending-src scan order) member's exact text for display.
        e = by_text.setdefault(keyf(t), {"ptrs": set(), "addrs": set(), "max": 9999,
                                         "original": t})
        e["ptrs"].update(f"{s:08X}" for s in slots)
        e["addrs"].add(f"{ptr:08X}")
        e["max"] = min(e["max"], len(c))
        # sec.term == "": per-entry terminator from the ROM (mixed-term tables)
        e.setdefault("term", "0301" if u16(rom, ptr + len(c) * 2) == 0x0301 else "0000")
    rows = [{"ptrs": sorted(e["ptrs"]), "addrs": sorted(e["addrs"]),
             "max": e["max"], "term": sec.term or e["term"], "original": e["original"],
             "replace": None}
            for e in by_text.values()]
    rows.sort(key=lambda e: e["addrs"][0])
    return rows


def extract_bank_walk(rom, sec):
    """Sweep a glyph bank capturing maximal clean terminated strings, stepping over the
    interleaved jump tables / ARM-Thumb code: a candidate starts at a real glyph, must
    terminate (0x0000/0x0301) with >=2 mapped glyphs and no >=0x1300 word (those are
    code). Code regions get skipped 2B at a time."""
    p = sec.source.params
    rows = []
    a = p["lo"]
    while a < p["hi"]:
        if u16(rom, a) in GLYPH_MAP:
            t, c = decode(rom, a, p.get("str_max", 200))
            end = u16(rom, a + len(c) * 2)
            if (c and end in (0x0000, 0x0301) and not any(code >= 0x1300 for code in c)
                    and sum(1 for code in c if code in GLYPH_MAP) >= 2):
                rows.append({"addr": f"{a:08X}", "max": len(c),
                             "term": "0301" if end == 0x0301 else "0000",
                             "original": t, "replace": None})
                a += (len(c) + 1) * 2
                continue
        a += 2
    # Partition AFTER the walk (every section sharing a bank sees identical strings):
    # drop strings another section already owns (one source, one owner — translating a
    # string twice through two mechanisms is the double-claim hazard), then apply the
    # declarative filter (addr_ge + term, optionally negated — how one bank splits
    # into route-pure files).
    excl_ranges = owned_addrs(rom, p.get("exclude_owned_by", ()))
    flt = p.get("filter")
    kept = []
    for r in rows:
        ra = int(r["addr"], 16)
        rb = ra + (r["max"] + 1) * 2
        # overlap, not exact-start: an owned string often begins with a substitution /
        # control code, so the start-at-glyph walk captures it 2+ bytes in
        if any(lo < rb and ra < hi for lo, hi in excl_ranges):
            continue
        if flt:
            match = (ra >= flt.get("addr_ge", 0)
                     and r["term"] == flt.get("term", r["term"]))
            if match == bool(flt.get("negate")):
                continue
        kept.append(r)
    return kept


def owned_addrs(rom, sec_ids):
    """The string byte-spans [(lo, hi)] the given sections own, derived from their
    manifest source specs — or, for curated sections, from their JSON entries. Used by
    bank walks (and the coverage audit) so no string is ever claimed by two sections."""
    ranges = []

    def add_span(sa):
        _t, c = decode(rom, sa, 800)
        ranges.append((sa, sa + (len(c) + 1) * 2))

    for sid in sec_ids:
        osec = sections.by_id(sid)
        kind = osec.source.kind
        if kind == "literal_slots":
            for sa, _slots in osec.source.params["slots"]:
                add_span(sa)
        elif kind == "msg_id_table":
            q = osec.source.params
            for i in range(q["count"]):
                ptr = u32(rom, q["table"] + i * 4)
                if q["target_lo"] <= ptr < q["target_hi"]:
                    add_span(ptr)
        elif osec.route == "block_rebuild":
            # Each fragment owns ONLY its own bytes (its string addr .. the 0x0000 after it),
            # NOT the bounding box first..last. The block is NOT gap-free: a 0x66a hole
            # (0x08123054..0x081236BC) between fragment 0x08123052 and the main fragment run holds
            # OTHER sections' strings — the system_battle_log battle-log lines (Bound!/Evaded!/
            # command-menu/CONFIG-help), the menu_comp confirm prompt, and the names_race
            # battle-copy race names. Claiming the bounding box wrongly EXCLUDED those from the
            # battle-log bank-walk (orphaning their translations on re-extract, so `tr.py extract`
            # aborted on merge-key drift) and DOUBLE-CLAIMED menu_comp in the coverage audit.
            # The rebuild reads battlefrag.json directly and never consults owned_addrs, so this
            # precision does not change pack output (verified byte-identical).
            frs = json.loads((TR / f"{osec.id}.json").read_text(encoding="utf-8"))
            for e in frs:
                add_span(int(e["addr"], 16))
        else:                       # curated JSON sections: their entries' addrs
            for e in json.loads((TR / f"{osec.id}.json").read_text(encoding="utf-8")):
                for f in fields(e):
                    if f.get("addr"):
                        add_span(int(f["addr"], 16))
    return ranges


def extract_literal_slots(rom, sec):
    """Hand-declared (string addr -> code-literal slot addrs) entries: streams the
    battle-event composers copy via pointers baked in code literals. Fully
    deterministic — re-extraction regenerates the same entries from the manifest's
    slot list, so the pointer metadata can never be lost to a bank re-walk again."""
    rows = []
    for sa, slots in sec.source.params["slots"]:
        t, c = decode(rom, sa, sec.source.params.get("str_max", 200))
        end = u16(rom, sa + len(c) * 2)
        rows.append({"addr": f"{sa:08X}", "ptrs": [f"{s:08X}" for s in slots],
                     "max": len(c), "term": "0301" if end == 0x0301 else "0000",
                     "original": t, "replace": None})
    return rows


def extract_msg_id_table(rom, sec):
    """id -> template-pointer table (battle message templates, FUN_080ec038): the visible
    combat-log / encounter / battle-menu / prompt messages (full templates with
    substitution codes). Dedup by text (one entry, all ids); packed by repointing
    table[id] -> pooled English (no runtime hook)."""
    p = sec.source.params
    bt = {}
    for i in range(p["count"]):
        ptr = u32(rom, p["table"] + i * 4)
        if not (p["target_lo"] <= ptr < p["target_hi"]):
            continue
        t, c = decode(rom, ptr, p["str_max"])      # stops at 0x0301 (the expander terminator)
        if c and u16(rom, ptr + len(c) * 2) == 0x0301:
            e = bt.setdefault(t, {"ids": [], "addr": f"{ptr:08X}"})
            e["ids"].append(i)
    rows = [{"ids": e["ids"], "addr": e["addr"], "term": "0301", "original": t,
             "replace": None}
            for t, e in bt.items()]
    rows.sort(key=lambda e: e["ids"][0])
    return rows


def extract_lore_table(rom, sec):
    """Demon compendium lore: per-demon table, lore-string PTR @+0 -> contiguous bank.
    Entries end ...{WAIT}(0x0316) 0x0301 (0x0300 newlines inside); the dictionary/
    compendium reader stops + returns to the list on that 0x0301 — a 0x0000 terminator
    is NOT honoured, so the next pooled entry would flow straight in (the DDS dictionary
    overflow bug). Preserve the real per-entry terminator. Repointable like descriptions
    -> any-length English. The story walker appends the compendium entries that live
    inline in the event bank (no table pointer) so all compendium text stays together."""
    p = sec.source.params
    rows = []
    for i in range(p["count"]):
        rec = p["table"] + i * p["stride"]
        lp = u32(rom, rec)
        if not (ROM_BASE <= lp < ROM_BASE + len(rom)):
            continue
        t, c = decode(rom, lp, p["str_max"])
        if len(c) >= 3:
            term = "0301" if u16(rom, lp + len(c) * 2) == 0x0301 else "0000"
            rows.append({"id": i, "ptr": f"{rec:08X}", "addr": f"{lp:08X}", "term": term,
                         "original": t, "replace": None})
    return rows


EXTRACTORS = {"name_bank": extract_name_bank, "paired_records": extract_paired_records,
              "ptr_table": extract_ptr_table, "bank_walk": extract_bank_walk,
              "msg_id_table": extract_msg_id_table, "literal_slots": extract_literal_slots}


def extract_all(rom):
    """Run every non-curated section's extractor; returns {sec_id: fresh entries}.
    Shared by extract() and the coverage audit, so 'what the audit calls covered' is
    BY CONSTRUCTION 'what extraction actually extracts'."""
    secs = [s for s in sections.SECTIONS if not s.curated]
    out = {}
    for sec in secs:
        if sec.source.kind in EXTRACTORS:
            out[sec.id] = EXTRACTORS[sec.source.kind](rom, sec)
    # The story walk and the lore table are coupled (inline compendium entries found in
    # the event bank are appended to lore), and the walker must skip every string a
    # ptr_table section already owns (negotiation dialogue overlaps the bank).
    lore_sec = next(s for s in secs if s.source.kind == "lore_table")
    story_sec = next(s for s in secs if s.source.kind == "story_vm")
    lore = extract_lore_table(rom, lore_sec)
    seen = {int(x, 16) for s in secs if s.source.kind == "ptr_table"
            for e in out[s.id] for x in e["addrs"]}
    seen |= {int(e["addr"], 16) for e in lore}
    out[story_sec.id] = extract_story_vm(rom, story_sec, seen, lore)
    out[lore_sec.id] = lore        # incl. inline compendium entries appended by the walk
    return out


def extract(rom):
    TR.mkdir(parents=True, exist_ok=True)
    secs = [s for s in sections.SECTIONS if not s.curated]
    out = extract_all(rom)
    for sec in secs:
        write_section(sec.id, out[sec.id])


def extract_story_vm(rom, sec, seen, lore):
    """Walk the event-VM bank into messages (glyphs..0x0301), keeping ALL control as
    tokens ({n}/{WAIT}/{PAGE}/names/{MACCA}; {=hex} = any other opcode + its args,
    byte-exact so the Phase-2 rebuild packer can round-trip + recompute jumps). DEDUP
    by text. The packer is a separate rebuild step (inline + jump-addressed) — not
    wired yet; this makes text editable. `seen` = string addrs other sections already
    own (negotiation dialogue overlaps the bank @0x08040E2C+, compendium lore too);
    inline compendium entries found mid-walk are APPENDED to `lore`."""
    p = sec.source.params
    STORY_LO, STORY_HI = p["lo"], p["hi"]
    # Owned strings must be skipped as SPANS, not just start addrs: a dialogue string
    # usually opens with control codes ({PAGE}…), so a start-at-glyph walker entering
    # it would begin capture a few words in and emit a phantom near-duplicate entry
    # (318 of them before this fix — each a double-claim against dialogue/lore).
    seen_spans = []
    for sa in sorted(seen):
        _t, c = decode(rom, sa, 800)
        seen_spans.append((sa, sa + (len(c) + 1) * 2))
    seen_starts = [lo_ for lo_, _hi in seen_spans]

    def owned_end(addr):
        i = bisect.bisect_right(seen_starts, addr) - 1
        if i >= 0 and addr < seen_spans[i][1]:
            return seen_spans[i][1]
        return None
    OPARGS = {int(k, 16): v for k, v in
              json.loads((DATA / "opcode_args.json").read_text(encoding="utf-8")).items()}
    STOK = {0x0300: "{n}", 0x0316: "{WAIT}", 0x0317: "{PAGE}", 0x031A: "{ALEPH}",
            0x031B: "{HIROKO}", 0x031C: "{ZAYIN}", 0x031D: "{GIMMEL}", 0x036E: "{MACCA}"}
    # A run is only real script if it's glyphs + known control tokens + opcodes. The bank also
    # holds ARM/Thumb code, jump tables and pointers; treating those data words as glyphs is what
    # produced the old <XXXX> garbage. So: start a run ONLY at a mapped glyph, and STOP (without
    # emitting it) at the first non-text word — a code >=0x0471 that isn't a glyph (font ends at
    # 0x11FF; >=0x1300 is pure code) or a stray low control. We never emit <XXXX>; a run is kept
    # only if it has >=MIN real glyphs AND at least one kana — Japanese prose always carries kana
    # (particles/okurigana), whereas the bank's pointer/branch tables decode to bare kanji+ASCII
    # runs (玖X玖…, 吟b;, 区区…) with none, so the kana test drops them with no real-text loss.
    # 0x11FE is dead-space padding after jumps -> skipped, not text.
    MIN_GLYPHS = p["min_glyphs"]
    is_kana = lambda ch: any("ぁ" <= k <= "ん" or "ァ" <= k <= "ヶ" for k in ch)
    by_msg, msg_clean = {}, {}      # text -> [addrs]; text -> ended at a real terminator (packable in place)
    cap_spans = []                  # (start, end) of every captured run (for the label pass below)
    a = STORY_LO
    while a < STORY_HI:
        skip_to = next((thi for tlo, thi in p["skip_tables"] if tlo <= a < thi), None)
        if skip_to is not None:                         # jump over owned pointer tables (not VM code)
            a = skip_to
            continue
        end = owned_end(a)
        if end is not None:                             # inside a string another section owns
            a = end
            continue
        c = u16(rom, a)
        # A ROM pointer that abuts a string leaves its high u16 (0x0801-0x080B =
        # 近金吟銀九倶句区狗玖苦, the story-bank address high halves) sitting right before the
        # text, so the walker would read it as a spurious leading kanji ("吟そなたは…"). Skip such
        # leading words; a message that genuinely starts with one of these follows a 0x0301/0x0000
        # terminator, so only skip when the preceding word isn't a terminator.
        while 0x0801 <= c <= 0x080B and u16(rom, a - 2) not in (0x0301, 0x0000) and a + 2 < STORY_HI:
            a += 2
            c = u16(rom, a)
        # A message starts at a real glyph, OR at an ink-producing substitution opcode sitting
        # at a clean message boundary (the "{DEMON_NAME}は{n}…" prefix of negotiation/reaction
        # lines). The boundary is a terminator (0x0301/0x0000) OR a page/wait control
        # (0x0317 {PAGE} / 0x0316 {WAIT}) — a new page that opens with a name sub, e.g. the
        # gem-taming "{PAGE}{DEMON_NAME}は{n}大人しくなった" calm/rage outcomes, whose name op the
        # walker otherwise skipped (over-counted operand ate the は), orphaning "Nameは" before
        # the repointed predicate (Garm-settled-down glitch). Page/wait are display boundaries,
        # not jumps/flags, so this does not mistake inter-message control ops for message starts.
        if c in GLYPH_MAP or (c in INK_SUB_OPS and u16(rom, a - 2) in (0x0301, 0x0000, 0x0316, 0x0317)):
            start, parts, glyphs, kana, ended_clean = a, [], 0, 0, False
            while a < STORY_HI:
                if owned_end(a) is not None:             # ran into a string another
                    break                                # section owns -> stop, don't eat it
                c = u16(rom, a)
                if c in (0x0301, 0x0000):                # clean message terminator
                    a += 2
                    ended_clean = True
                    break
                if c in STOK:
                    parts.append(STOK[c]); a += 2
                elif c == 0x11FE:                          # dead-space padding after jumps
                    a += 2
                elif 0x0302 <= c <= 0x0470:                # opcode + args -> opaque, byte-exact
                    blob = rom[a - ROM_BASE:a - ROM_BASE + 2 + scriptrefs.oplen_words(c, OPARGS) * 2]
                    parts.append("{=" + blob.hex() + "}"); a += len(blob)
                elif c in GLYPH_MAP:
                    ch = GLYPH_MAP[c]
                    parts.append(ch); glyphs += 1
                    if is_kana(ch):
                        kana += 1
                    a += 2
                else:                                      # non-text word (code/data) -> stop, don't consume it
                    break
            if glyphs >= MIN_GLYPHS and kana and start not in seen:  # real prose (has kana); skip negotiation/lore
                cap_spans.append((start, a))
                msg = "".join(parts)
                if "出身地　　：" in msg:                   # demon compendium entry inline in the event bank
                    lt, lc = decode(rom, start, 600)        # re-decode with shared decoder for lore-section format
                    lterm = "0301" if u16(rom, start + len(lc) * 2) == 0x0301 else "0000"
                    lore.append({"addr": f"{start:08X}", "max": len(lc), "term": lterm,
                                 "original": lt, "replace": None})
                else:
                    by_msg.setdefault(msg, []).append(f"{start:08X}")
                    msg_clean.setdefault(msg, ended_clean)
        elif 0x0302 <= c <= 0x0470:                        # between messages: skip opcode args
            a += 2 + scriptrefs.oplen_words(c, OPARGS) * 2
        else:
            a += 2
    # ---- referenced short labels (second pass, 2026-06-13) --------------------------
    # The script code embeds u32 pointers to standalone label strings (service-menu rows,
    # negotiation TALK actions, debug-menu items). The prose walk above drops them: kanji-
    # only labels fail the kana test (記録/転送/武器…), 1-2 glyph ones fail MIN_GLYPHS —
    # so the gym menu drew JP 記録 between its translated siblings (user report
    # 2026-06-13). Being the TARGET of an embedded script pointer is stronger evidence of
    # real text than either heuristic: capture every referenced pure-glyph run that starts
    # a string (preceding word is a terminator / non-prose) and ends at a clean 0x0301.
    # They pack like any story entry (inline if the English fits, else the 0x0350 head —
    # which fits any >=2-glyph span — and the remap pass rewrites the referencing sites).
    cap_spans.sort()
    cap_starts = [s for s, _e in cap_spans]

    def in_captured(t):
        i = bisect.bisect_right(cap_starts, t) - 1
        return i >= 0 and t < cap_spans[i][1]

    bank = rom[STORY_LO - ROM_BASE:STORY_HI - ROM_BASE]
    ref_targets = set()
    for o in range(0, len(bank) - 3, 2):
        if any(lo_ <= STORY_LO + o < hi_ for lo_, hi_ in p["skip_tables"]):
            continue
        h = bank[o + 2] | (bank[o + 3] << 8)
        if 0x0801 <= h <= 0x080B:
            t = (h << 16) | bank[o] | (bank[o + 1] << 8)
            if STORY_LO <= t < STORY_HI and not (t & 1):
                ref_targets.add(t)
    n_labels = 0
    for t in sorted(ref_targets):
        if (in_captured(t) or owned_end(t) is not None
                or any(lo_ <= t < hi_ for lo_, hi_ in p["skip_tables"])):
            continue
        prev = u16(rom, t - 2)
        # mid-string targets (interior branch destinations) are the remap pass's job,
        # not new entries: require a string BOUNDARY before the target — a terminator,
        # non-text data, or a pointer high-half (0x0801-0x080B decode as kanji but are
        # the tail of an abutting pointer, same skip as the walker's leading-word rule)
        if not (prev in (0x0301, 0x0000) or prev not in GLYPH_MAP
                or 0x0801 <= prev <= 0x080B):
            continue
        a2, chars = t, []
        while a2 < min(t + 32, STORY_HI):
            c2 = u16(rom, a2)
            if c2 == 0x0301:
                break
            ch2 = GLYPH_MAP.get(c2)
            if ch2 is None or c2 in STOK or c2 == 0x11FE or 0x0302 <= c2 <= 0x0470:
                chars = []
                break
            chars.append(ch2)
            a2 += 2
        if not chars or u16(rom, a2) != 0x0301:
            continue
        msg = "".join(chars)
        by_msg.setdefault(msg, []).append(f"{t:08X}")
        msg_clean.setdefault(msg, True)
        cap_spans.append((t, a2 + 2))        # not re-sorted: only dedup vs earlier labels matters
        cap_starts.append(t)                 # (targets iterate sorted, so appends stay ordered)
        n_labels += 1
    if n_labels:
        print(f"  story: +{n_labels} pointer-referenced label strings")

    # NB the event-VM bank's reachable prose is already 100% captured by the linear walk +
    # label pass above (proven by dump/audit_reachability.py: 273/273 reachable prose-starts
    # owned).  A control-flow reachability capture (vmflow.find_leaf_gaps) adds nothing here —
    # the genuine read-side gaps live in the field-event / battle mechanisms OUTSIDE this bank.

    # In-place packing for story: a clean-terminated message can be overwritten within its own
    # byte span (budget = JP content length; English must fit). Messages that ran into data have
    # no real terminator slot, so they stay unpackable. Length-unconstrained story needs the
    # Phase-2 jump-aware repoint rebuild (not wired); inline covers fitting lines for now.
    story = []
    for t, ads in sorted(by_msg.items(), key=lambda kv: kv[1][0]):
        e = {"addrs": ads, "term": "0301", "original": t, "replace": None}
        if msg_clean.get(t):
            try:
                e["max"] = len(encode(t)) // 2
            except ValueError:
                pass
        story.append(e)
    return story


def _merge_keys(f):
    """Every key a field's translation can be found under: the primary fkey first, then
    each component pointer slot / string addr. The fallbacks are what keep a `replace`
    alive when an entry gains or loses pointer metadata across re-extractions (e.g. a
    plain addr entry becoming a {ptrs:[…]} literal-slot entry re-keys its fkey, but the
    string addr still matches)."""
    keys = [fkey(f)]
    for k in ("addrs", "ptrs"):
        keys += [x for x in (f.get(k) or ()) if x != keys[0]]
    for k in ("addr", "ptr"):
        if f.get(k) and f[k] not in keys:
            keys.append(f[k])
    return keys


def write_section(sec_id, fresh):
    """(Re)write <sec_id>.json, carrying every existing `replace` over to the fresh
    entries. A previously-translated field that NO fresh field claims is a hard error —
    silent merge-key drift is how translations get lost (it already nearly happened to
    the hand-added system.json `ptrs` entries)."""
    path = TR / f"{sec_id}.json"
    old, primary_of = {}, {}
    if path.exists():
        for e in json.loads(path.read_text(encoding="utf-8")):
            for f in fields(e):
                if f.get("replace") is not None:
                    keys = _merge_keys(f)
                    for k in keys:
                        if k not in old:
                            old[k] = f["replace"]
                            primary_of[k] = keys[0]
    expected = set(primary_of.values())          # own-file translations that must survive
    n, consumed = 0, set()
    for e in fresh:
        for f in fields(e):
            if f.get("replace") is None:
                for k in _merge_keys(f):
                    if old.get(k) is not None:
                        f["replace"] = old[k]
                        consumed.add(primary_of[k])
                        break
            if f.get("replace") is not None:
                n += 1
    dropped = expected - consumed
    if dropped:
        raise SystemExit(f"!! {sec_id}: {len(dropped)} previously-translated field(s) would be "
                         f"dropped by this re-extraction (merge-key drift): "
                         f"{sorted(dropped)[:8]}{' …' if len(dropped) > 8 else ''}")
    path.write_text(aliasify(json.dumps(fresh, ensure_ascii=False, indent=1)), encoding="utf-8")
    print(f"  {sec_id}: {len(fresh)} entries ({n} fields translated)")
    return n


# ---------------------------------------------------------------- auto-wrap
# Build-time pixel-width line splitter: English runs longer than the JP it replaces, and no
# one is hand-checking every story line for horizontal overflow.  At pack time we measure
# each translated line with the SAME advance widths the VWF uses (the width table patch_vwf
# already wrote into the ROM: English = trimmed ink+gap, everything else = the window's JP
# pitch) and insert {n} at the last space whenever a line would overrun the window.
# Explicit {n}/{PAGE} are respected (we only ADD breaks).  Runtime-substituted content
# can't be measured exactly, so placeholders reserve a conservative width:
# names ([name]/[item]/[skill], {ALEPH}.., {=1e03}-family subs) 60px, numbers ([damage],
# {=23..}, {MACCA}) 30px.  A spaceless overlong line, or a page that ends up with more
# lines than the window shows, is left alone and WARNED for manual attention.
# Per-window px budgets and JP pitches live on the Section manifest (sections.py:
# story/dialogue 198px @13, battle/battlefrag 194px @12).  These are ~10px under the widest
# clean JP line (218/204): EN VWF glyphs carry a left bearing whose ink overhangs the summed
# advance, so a line packed flush to the JP max still nudged a glyph or two off the right edge —
# the margin keeps the last glyph inside the window.
WRAP_WARN_LINES = 4           # max lines/page seen in JP data (both windows)
NAME_RESERVE_PX = 60
DIGIT_RESERVE_PX = 30
_NAME_TOKENS = {"{ALEPH}", "{HIROKO}", "{ZAYIN}", "{GIMMEL}"}
# {=XX03..} inline value-substitution opcodes that reserve width for autowrap.  DERIVED from
# scriptrefs.NAME_SUB_OPS so the wrap measurement can't silently drift from the canonical
# 0-operand sub set again (the 0x328 area / 0x329 multi-name / 0x32E party / 0x32F coins subs
# were measured as 0px, so lines with e.g. the {=2e03} party-name ran off the window unwrapped).
# Number/coins subs reserve a digit width; the rest (species/race/party/item/area) a name width.
# The FIXED party tokens 0x31A-0x31D appear aliased as {ALEPH}.. (handled by _NAME_TOKENS above).
_DIGIT_SUB_OPS = {0x0323, 0x032F}                            # number @0x0203db2c, coins<-Coins_Get
_DIGIT_SUB_LOW = {f"{op & 0xFF:02x}" for op in _DIGIT_SUB_OPS}
_NAME_SUB_LOW = {f"{op & 0xFF:02x}" for op in scriptrefs.NAME_SUB_OPS} - _DIGIT_SUB_LOW
_WRAP_ATOM = re.compile(r"\{[^}]*\}|\[(?:name|item|skill|damage)\]|.", re.S)

# {WAIT} (0x316) ends the current utterance, so the line-width accumulator resets across it
# (a new LINE — the "Now, begin!{WAIT}…Hey, good work." report that motivated this).  Jumps
# (0x30C ConditionalJump / 0x30D JumpIfAllyStatus / 0x30F Jump / 0x411 JumpToSavedStream) do
# NOT reset it: text only ever FOLLOWS a jump in a replace string for an INLINE branch — the
# casino gold/dark-coin rate line ("your Macca -{=30C}{=30C}10{=30F}for every 10, you get…",
# extractor 08041E78) where the conditional variants converge and the continuation flows on
# the SAME rendered line (the JP DID flow one line across that jump).  An end-of-utterance
# jump is the LAST atom in its entry (the walker terminates there, nothing follows), so not
# resetting is moot.  Resetting on the inline-branch jumps made autowrap UNDER-measure the
# line and skip the break -> the EN text ran off the right edge of the casino window.  Across
# a jump the linear text over-counts mutually-exclusive branch variants, which can only ADD
# breaks, never remove them -> always safe (no horizontal overflow).
_LINE_RESET_OPS = {0x0316}

# Opcodes that begin a fresh WINDOW (so _paginate's per-window line/glyph budget restarts).  A
# {PAGE}-block's branch targets are MUTUALLY-EXCLUSIVE paths the player never sees together, and
# a jump/UI hand-off draws its continuation in a freshly-cleared window — counting their lines as
# one page phantom-splits a later utterance ("His name is{n}{ZAYIN}, then..." over two pages).
# = the jump/branch ops above (incl. stage-branch 0x30E) + name-entry UI 0x37D, but NOT {WAIT}:
# per docs/event-vm.md, ScriptOp_WaitTimed (state 3) does NOT clear the window — only {PAGE}
# (-> state 10 ResetTextWindow) does — so content after {WAIT} genuinely accumulates and must
# keep counting toward the budget.  Empirically (boundary_analysis) this set caps the worst JP
# window at 5 lines; {PAGE}-only leaves phantom 6-9 line "windows" from merged branch variants.
_WINDOW_RESET_OPS = {0x030C, 0x030D, 0x030E, 0x030F, 0x0411, 0x037D}


def _atom_opcode(a):
    """Opcode word of a {=hex} op atom (first two bytes, little-endian), else None."""
    if a.startswith("{=") and len(a) >= 6:
        try:
            return int(a[4:6] + a[2:4], 16)
        except ValueError:
            return None
    return None


def _is_line_reset(a):
    return a == "{WAIT}" or _atom_opcode(a) in _LINE_RESET_OPS


def _atom_width(a, jp_pitch, widths):
    if a.startswith("{"):
        if a in _NAME_TOKENS:
            return NAME_RESERVE_PX
        if a == "{MACCA}":
            return DIGIT_RESERVE_PX
        if a.startswith("{="):
            low, grp = a[2:4], a[4:6]
            if grp == "03":           # text subs are 0xXX03 only — {=2104..} etc. are
                if low in _NAME_SUB_LOW:   # 0x04xx-group engine opcodes with no ink
                    return NAME_RESERVE_PX
                if low in _DIGIT_SUB_LOW:
                    return DIGIT_RESERVE_PX
        return 0                                  # {n}/{WAIT}/{PAGE}/other opcodes: no ink
    if a.startswith("["):
        return DIGIT_RESERVE_PX if a == "[damage]" else NAME_RESERVE_PX
    if ord(a) in ZERO_WIDTH:
        return 0
    if a in _OPTAIL:           # leaked pointer high-word kanji (近金吟銀…): consumed by the
        return 0               # abutting jump/branch op as an operand, never drawn -> no ink
    c = CHAR2CODE.get(a)
    if c is not None and rommap.ENG_LO <= c < rommap.ENG_HI:
        return widths[c]                          # English: the VWF advance
    return jp_pitch                               # everything else: the window pitch


def _atom_glyphs(a):
    """g_MsgGlyphList records an atom consumes when the event-VM window draws it.
    Plain chars (incl. spaces) append one record; substitutions reserve their runtime
    expansion cap — player-name tokens and digit subs up to 8 (8 charset slots / 6-7
    digits), the {=XX03} name-family subs up to 15 (cave_negocopy streams demon/item
    names cap-15; area names can run long) — so a page measured at the section budget
    can't overrun the runtime record list even after expansion; control tokens
    ({n}/{WAIT}/{PAGE}/opcodes) append none."""
    if a.startswith("{"):
        if a in _NAME_TOKENS or a == "{MACCA}":
            return 8
        if a.startswith("{=") and a[4:6] == "03":
            if a[2:4] in _NAME_SUB_LOW:
                return 15
            if a[2:4] in _DIGIT_SUB_LOW:
                return 8
        return 0
    if ord(a[0]) in ZERO_WIDTH:
        return 0
    if a in _OPTAIL:           # leaked pointer high-word kanji: never appended to g_MsgGlyphList
        return 0
    return 1


def _paginate(s, budget, max_lines=WRAP_WARN_LINES):
    """Split a page into {WAIT}{PAGE} sub-pages whenever it would exceed EITHER budget:
      * `budget` glyph records — the g_MsgGlyphList capacity (sections.PAGE_GLYPHS backstop
        under the 192-record runtime list); the engine truncates the page at capacity.
        Since the 2026-07-02 capacity lift this should essentially never fire — window
        geometry bounds a physically-fitting 4-line page at ~140-160 records — so the
        `max_lines` rule below is the one that actually paginates.
      * `max_lines` rows — the window is only this tall (the max lines/page in JP data).
        A page of many SHORT lines stays under the glyph cap yet overflows vertically
        (consolidation can't merge utterances split by {WAIT}/control ops), so cap the
        row count too. Both split at a line break ({n} -> {WAIT}{PAGE}), the JP idiom.
    Pages within both budgets are returned unchanged (byte-identical build for them)."""
    out_pages = []
    for pg in s.split("{PAGE}"):
        parts, cur, cost, nlines, last_brk = [], [], 0, 1, -1
        for a in _WRAP_ATOM.findall(pg):
            if a == "{n}":
                if nlines >= max_lines:               # this {n} would open an (max+1)th row
                    parts.append("".join(cur))        # -> page-break here, drop the {n}
                    cur, cost, nlines, last_brk = [], 0, 1, -1
                    continue
                last_brk = len(cur)
                nlines += 1
            cur.append(a)
            cost += _atom_glyphs(a)
            if _atom_opcode(a) in _WINDOW_RESET_OPS:      # branch/jump/name-entry: a fresh window
                cost, nlines, last_brk = 0, 1, -1         # starts here -> restart the budget (the
                continue                                  # op itself stays in the stream)
            if cost > budget and last_brk >= 0:
                parts.append("".join(cur[:last_brk]))     # drop the {n} itself
                cur = cur[last_brk + 1:]
                cost = sum(_atom_glyphs(x) for x in cur)
                nlines = cur.count("{n}") + 1
                last_brk = next((i for i in range(len(cur) - 1, -1, -1)
                                 if cur[i] == "{n}"), -1)
        parts.append("".join(cur))
        out_pages.append("{WAIT}{PAGE}".join(parts))
    return "{PAGE}".join(out_pages)


def _max_window_lines(s):
    """Rendered line count of the TALLEST single window in `s`.  A window ends at {PAGE} or a
    control-transfer op (_WINDOW_RESET_OPS); {WAIT} does NOT clear the window so it keeps counting.
    Used for the vertical-overflow warning so branch-pages (mutually-exclusive variants the player
    never sees together) aren't flagged for the sum of their alternatives."""
    worst = 0
    for pg in s.split("{PAGE}"):
        lines = 1
        for a in _WRAP_ATOM.findall(pg):
            if a == "{n}":
                lines += 1
            elif _atom_opcode(a) in _WINDOW_RESET_OPS:
                worst, lines = max(worst, lines), 1
        worst = max(worst, lines)
    return worst


_SOFT_SUB_LOW = _NAME_SUB_LOW | _DIGIT_SUB_LOW | {"1a", "1b", "1c", "1d"}   # +char/female subs


def _atom_is_hard(a):
    """A manual {n} adjacent to this atom must be KEPT (a meaningful break), vs a soft prose
    neighbour where the {n} may dissolve into a space and let autowrap re-flow.  Hard =
    {WAIT}/{PAGE} or any structural opcode; soft = inline name/number text subs and glyphs."""
    if a in ("{WAIT}", "{PAGE}"):
        return True
    if a in _NAME_TOKENS:
        # Player-named story characters ({ALEPH}/{ZAYIN}/...): runtime substitutions of
        # UNKNOWN width.  autowrap can only reserve a conservative NAME_RESERVE_PX (60) for
        # them, which over-estimates the common default name (~27px) by 2x — so re-flowing a
        # line across one wraps at the wrong place and spills onto a second page (the Zayin
        # naming-confirm "...Zayin...{n}Zayin is his name?" report).  Keep the translator's
        # authored break (it mirrors JP's known-good layout); never dissolve across a name.
        return True
    if a == "{MACCA}":
        return False
    if a.startswith("{="):                       # 0xXX03 text sub -> soft; any other opcode -> hard
        return not (a[4:6] == "03" and a[2:4] in _SOFT_SUB_LOW)
    return False                                 # glyph / space


def _dissolve_manual_breaks(rep):
    """Replace each hand-authored {n} sitting between two SOFT (prose / text-sub) atoms with a
    space so autowrap's px-budget pass re-decides every line break.  The bulk translation placed
    manual {n} mimicking JP line structure; autowrap only ADDS breaks, so those manual ones STACK
    with the px breaks (the user's '...collect{n}the Pillars' double-break).  A {n} is KEPT only
    when a neighbour (nearest non-space atom either side) is a structural opcode / {WAIT} / {PAGE}
    / another {n} (blank line) / the stream boundary — the breaks that carry meaning.  Crucially a
    trailing {WAIT} at the END of the next line is NOT an immediate neighbour, so it no longer
    pins the break (the bug that made the old consolidate() pass a no-op)."""
    atoms = _WRAP_ATOM.findall(rep)
    out = []
    for i, a in enumerate(atoms):
        if a != "{n}":
            out.append(a)
            continue
        p = next((atoms[k] for k in range(i - 1, -1, -1) if atoms[k] != " "), None)
        nx = next((atoms[k] for k in range(i + 1, len(atoms)) if atoms[k] != " "), None)
        if (p is None or nx is None or p == "{n}" or nx == "{n}"
                or p in (":", "：")              # speaker-name line ("Name:" + break) — the JP
                                                 # "Speaker：{n}line" idiom; keep the break, don't inline
                or _atom_is_hard(p) or _atom_is_hard(nx)):
            out.append(a)
        else:
            out.append(" ")
    return re.sub(r" {2,}", " ", "".join(out))


def autowrap(rep, sec, rom, ctx="", orig=None):
    """Insert {n} breaks so no rendered line exceeds the window width.  Returns rep unchanged
    when the section has no width budget, the entry is a padded table ('@'), or the width
    table is not in the ROM yet (raw base ROM).

    `orig` (the JP source string) enables the extra-page check: a build-time warning when the
    English ends up in MORE {WAIT}{PAGE} pages than the JP original — i.e. it grew too long for
    the window and autowrap had to split it.  Those are the entries worth condensing (page_glyphs
    is the sections.PAGE_GLYPHS backstop; the 4-line cap is what actually splits since the
    2026-07-02 record-capacity lift).  Costs no bytes."""
    limit = sec.wrap_px
    if not limit or "@" in rep:
        return rep
    o = rommap.WIDTH_TABLE - ROM_BASE
    widths = rom[o:o + rommap.WIDTH_TABLE_SIZE]
    if widths[CHAR2CODE["a"]] > 16:               # table unwritten (0xFF) -> can't measure
        return rep
    if getattr(sec, "strip_manual_n", False):     # prose windows: dissolve manual breaks first
        rep = _dissolve_manual_breaks(rep)
    jp_pitch = sec.wrap_jp_pitch
    out, w = [], 0
    brk, spaceless = -1, False                    # last breakable space on this line
    for a in _WRAP_ATOM.findall(rep):
        if a == "{n}" or a == "{PAGE}":
            out.append(a)
            w, brk = 0, -1
            continue
        if a == " ":
            brk = len(out)
        out.append(a)
        w += _atom_width(a, jp_pitch, widths)
        if _is_line_reset(a):             # {WAIT}/jump: the continuation draws on a fresh
            w, brk = 0, -1                # line, so don't carry this line's width across it
            continue
        if w > limit:
            if brk < 0:
                spaceless = True                  # can't break: leave it, warn below
                continue
            out[brk] = "{n}"                      # break at the last space (the space's
            w = 0                                 # width disappears with it)
            for b in out[brk + 1:]:
                w += _atom_width(b, jp_pitch, widths)
            brk = -1
    s = "".join(out)
    if spaceless:
        print(f"  ! wrap {ctx}: spaceless line exceeds {limit}px — left unwrapped")
    if getattr(sec, "page_glyphs", 0):
        authored = s.count("{PAGE}") + 1          # EN pages the translator wrote (line-wrap adds none)
        s = _paginate(s, sec.page_glyphs)
        if orig:
            en = s.count("{PAGE}") + 1            # EN pages after pagination
            jp = orig.count("{PAGE}") + 1         # JP pages as authored in the source
            if en > jp:
                added = en - authored             # how many of the extra pages autowrap inserted
                tail = f"; autowrap split {added}" if added > 0 else "; authored"
                print(f"  ! pages {ctx}: EN {en} pages vs JP {jp}{tail} — condense to keep JP paging")
    ml = _max_window_lines(s)
    if ml > WRAP_WARN_LINES:
        print(f"  ! wrap {ctx}: a window has {ml} lines (> {WRAP_WARN_LINES}) — check vertical fit")
    return s


# ---------------------------------------------------------------- pack
class PackState:
    """Mutable state shared across pack()'s phase functions (was closure-captured locals + the
    alloc/logw/logp closures).

    self.rom is the working bytearray: set ONCE in __init__, only ever .extend()'d or slice-assigned
    (alloc's grow loop + the final pad mutate THIS object), NEVER reassigned — so a phase function may
    safely alias `rom = st.rom`.  Likewise every cross-phase list/dict is mutated in place (never
    rebound), so phases alias them too; the reassigned scalars (story_sec/refs and the per-phase
    accumulators) are the only ones written back through `st.`.  pool[0] became self.pool_cursor (the
    1-element-list boxing only existed so a closure could rebind it; a method rebinds it directly)."""

    def __init__(self, rom):
        # ---- shared infra (formerly the closure captures) ----
        self.rom = bytearray(rom)
        self.pool_cursor = POOL_START - ROM_BASE        # was pool[0]
        # TR_PACK_LOG=<path>: append a JSONL record of every semantic ROM write — pool blobs by
        # content hash, pointer-slot writes by (slot, target-blob hash), direct writes by (addr,
        # bytes).  Pool ADDRESSES are deliberately absent, so two builds whose pool layout differs
        # (e.g. a section split reordered allocations) compare semantically with compare_pack_logs.py.
        self.log_path = os.environ.get("TR_PACK_LOG")
        self.events = [] if self.log_path else None
        self.pool_sha = {}
        # ---- cross-phase data (produced in one phase, consumed in a later one) ----
        self.secdata = {}                  # P3 validate -> P4,P5,P7,P8
        self.story_sec = None              # P4 -> P5
        self.refs = None                   # P4 -> P5,P6  (None when no story_expand section exists)
        self.script_remap = {}             # original stream addr -> pooled English addr  (P5 -> P6)
        self.ext_sites = []                # 4-aligned out-of-bank sites (offset, jp target)  (P4 -> P6)
        self.script_blobs = []             # (written_addr, blob) — rescanned for embedded refs (P5 -> P6)
        self.script_heads = []             # entry starts that received a 6-byte 0x0350 head  (P5 -> P6)
        self.inline_spans = []             # story spans overwritten in place (stale bank sites) (P5 -> P6)
        self.unmapped_interiors = []       # (P5 -> P6)
        # ---- accumulators (counted in P5/P7/P8, reported in P9) ----
        self.applied = 0
        self.warned = 0
        self.repointed = 0
        self.deferred = []                 # translated, over-budget, no mechanism yet (walk-reached)

    def alloc(self, blob):
        o = self.pool_cursor
        while o + len(blob) > len(self.rom):
            self.rom.extend(b"\xFF" * 0x10000)
        self.rom[o:o + len(blob)] = blob
        self.pool_cursor = (o + len(blob) + 1) & ~1
        if self.events is not None:
            h = hashlib.sha1(bytes(blob)).hexdigest()[:16]
            self.pool_sha[ROM_BASE + o] = h
            self.events.append(["pool", h])
        return ROM_BASE + o

    def logw(self, o, data):          # content written at a fixed ROM offset
        if self.events is not None:
            self.events.append(["write", f"{ROM_BASE + o:08X}", bytes(data).hex()])

    def logp(self, o, target):        # pool pointer written into slot at offset o
        if self.events is not None:
            self.events.append(["ptr", f"{ROM_BASE + o:08X}",
                                self.pool_sha.get(target, f"{target:08X}")])


def _reserve_tables(st):
    """Reserve + fill the three id->ptr pool tables at POOL_START.  These three allocs MUST run
    first and in order (NAME -> ITEM -> MARKER) — the asserts enforce the rommap table layout."""
    rom = st.rom
    nt = st.alloc(b"\x00" * NAME_TABLE_SIZE)   # reserve demon-name id->ptr table at POOL_START
    assert nt == NAME_TABLE, f"name table landed at {nt:08X}, not {NAME_TABLE:08X}"
    it = st.alloc(b"\x00" * ITEM_TABLE_SIZE)   # reserve equipment-name id->ptr table next
    assert it == ITEM_TABLE, f"item table landed at {it:08X}, not {ITEM_TABLE:08X}"
    mt = st.alloc(b"\x00" * MARKER_TABLE_SIZE)  # reserve + fill the battle demon-name MARKER table
    assert mt == MARKER_TABLE, f"marker table landed at {mt:08X}, not {MARKER_TABLE:08X}"
    for _i in range(NAME_COUNT):             # marker[id] = [MARKER_BASE|id, 0] (renderer expands via NAME_TABLE)
        _o = MARKER_TABLE - ROM_BASE + _i * 4
        rom[_o:_o + 2] = (MARKER_BASE | _i).to_bytes(2, "little")


# ---- ellipsis normalization (applied to REPLACE fields at load) --------------------------
# User pref: EN text uses "..." everywhere — never a JP-style ellipsis next to an EN one.  Done
# at load so every pack phase (scriptrefs remap, the field loop, battlefrag) sees ONE consistent
# string; ORIGINALS are never touched (they must round-trip).  '・' (U+30FB) is deliberately NOT
# mapped — in the EN replaces it is a bullet/legend separator (the status & fusion glossaries),
# not an ellipsis.
_ELLIPSIS_CHARS = {"…": "...", "‥": ".."}      # U+2026 horizontal ellipsis, U+2025 two-dot leader
_JP_ELLIPSIS_WORDS = {0x0023, 0x0024}           # ROM glyph codes for …/‥ bundled into a name sub
_SUB_ATOM_RE = re.compile(r"\{=([0-9a-fA-F]+)\}")


def _normalize_ellipsis(rep):
    """Map every JP ellipsis form in an EN replace to the canonical EN '...' / '..'."""
    def _strip(m):
        # Drop a JP-ellipsis glyph swallowed into a 0-operand name sub ({=2e032300} -> {=2e03}):
        # the surrounding EN '...' carries the ellipsis.  This mirrors how a cleaned replace already
        # drops bundled JP tails, and scriptrefs anchors on the sub opcode alone (NAME_SUB_OPS), so
        # interior branch targets still map.  Non-ellipsis tails (item-name '”', '×', ':' ...) stay.
        h = m.group(1)
        if len(h) < 8:
            return m.group(0)
        op = int.from_bytes(bytes.fromhex(h[:4]), "little")
        if op not in scriptrefs.NAME_SUB_OPS:
            return m.group(0)
        words = [int.from_bytes(bytes.fromhex(h[i:i + 4]), "little")
                 for i in range(4, len(h) - 3, 4)]
        if not any(w in _JP_ELLIPSIS_WORDS for w in words):
            return m.group(0)
        kept = "".join(w.to_bytes(2, "little").hex() for w in words if w not in _JP_ELLIPSIS_WORDS)
        return "{=" + h[:4] + kept + "}"
    rep = _SUB_ATOM_RE.sub(_strip, rep)
    for k, v in _ELLIPSIS_CHARS.items():
        rep = rep.replace(k, v)
    return rep


def _normalize_replaces(obj):
    """Recursively apply _normalize_ellipsis to every 'replace' string in a loaded entry
    (entry-level or nested under name/desc/aff1/aff2).  'original' is never touched."""
    if isinstance(obj, dict):
        for k, v in obj.items():
            if k == "replace" and isinstance(v, str):
                obj[k] = _normalize_ellipsis(v)
            else:
                _normalize_replaces(v)
    elif isinstance(obj, list):
        for x in obj:
            _normalize_replaces(x)


def _validate_manifest(st):
    """Manifest guard + load secdata.  Runs BEFORE any ROM write (its SystemExits must fire first).

    Every file in text/corpus/ must be a registered section and vice versa — an unregistered
    JSON would silently not build, a missing one is a broken checkout.  Then load once and validate
    per-field flags against each section's declared route (a flag implying a different mechanism is
    an error, not a fallthrough)."""
    secdata = st.secdata
    on_disk = {p.name for p in TR.glob("*.json")}
    expected = sections.filenames()
    if on_disk != expected:
        extra, missing = sorted(on_disk - expected), sorted(expected - on_disk)
        raise SystemExit("translation dir out of sync with the sections.py manifest"
                         + (f"; unregistered files: {extra}" if extra else "")
                         + (f"; missing files: {missing}" if missing else ""))
    for sec in sections.in_pack_order():
        secdata[sec.id] = json.loads(canon((TR / f"{sec.id}.json").read_text(encoding="utf-8")))
        for entry in secdata[sec.id]:
            _normalize_replaces(entry)      # JP ellipsis -> EN "..." (replace fields only)
            if "name" in entry or "desc" in entry:
                if "name" in entry:
                    sections.check_field_flags(sec, entry["name"])
                if "desc" in entry:
                    sections.check_field_flags(sec, entry["desc"], is_desc=True)
            else:
                sections.check_field_flags(sec, entry)
            for k in ("aff1", "aff2"):
                if k in entry:
                    sections.check_field_flags(sec, entry[k])
            for _f in fields(entry):        # per-field guards (fail loud before any ROM write):
                sections.check_entry(sec, _f)   # field-kind shape schema (sections.FIELD_KINDS, §7)
                _ctx = f"{sec.id} @{_f.get('addr', _f.get('addrs', '?'))}"
                check_optail_preserved(_f, _ctx)    # dropped pointer-tail kanji = corrupted jump
                check_branchop_operand_preserved(   # changed branch-selector word = garbage branch
                    _f, _ctx)                       # both -> softlock
    for sec in sections.in_pack_order():    # every declared extra ref must belong to a
        if not sec.extra_refs:              # real entry (a stale key = a slot silently
            continue                        # left pointing at JP — fail loud instead)
        have = {int(a, 16) for e in secdata[sec.id]
                for f in map(Field, fields(e)) for a in f.all_addrs}
        stale = set(sec.extra_refs) - have
        if stale:
            raise SystemExit(f"{sec.id}: extra_refs keys with no matching entry addr: "
                             f"{[f'{x:08X}' for x in sorted(stale)]}")


def _remap_prepass(st):
    """Script pointer remap pre-pass (lib/scriptrefs.py).

    The story bank's script code embeds 32-bit stream pointers (branch / choice rows / yes-no pairs /
    response lists / menu-label tables).  For a repointed entry those still aim at the original JP: an
    interior branch replayed Japanese (the "answer No and the dialogue loops back in JP" report,
    2026-06-12), and label drawers rendered the 0x0350 head as garbage glyphs.  A pooled English blob
    is both a valid VM stream and a valid drawable token string, so every reference can be rewritten to
    the pool: pre-scan the pristine bank here, force entries with interior targets to repoint (inline
    packing would shift their offsets), record pool addresses + anchor-mapped interior offsets during
    the main loop, and rewrite all sites afterwards.

    Builds st.refs (or leaves it the None sentinel when there is no story_expand section) and st.ext_sites;
    the rest of the remap state is initialized in PackState.__init__."""
    rom = st.rom
    secdata = st.secdata
    ext_sites = st.ext_sites
    st.story_sec = next((s for s in sections.in_pack_order()
                         if s.route == "story_expand"), None)
    story_sec = st.story_sec
    if story_sec is not None:
        _sp = story_sec.source.params
        _addrs_of = lambda f: (f.get("addrs") or ([f["addr"]] if "addr" in f else []))
        story_addrs, other_addrs = set(), set()
        for _sid, _data in secdata.items():
            for _e in _data:
                for _f in fields(_e):
                    for _a in _addrs_of(_f):
                        _v = int(_a, 16)
                        if _sp["lo"] <= _v < _sp["hi"]:
                            (story_addrs if _sid == story_sec.id
                             else other_addrs).add(_v)
        st.refs = scriptrefs.BankRefs(rom, _sp["lo"], _sp["hi"], story_addrs,
                                      other_addrs, GLYPH_MAP, CHAR2CODE, ZERO_WIDTH)
        refs = st.refs
        # ---- out-of-bank references (2026-06-13) -------------------------------
        # Shop/map-event record fields and Thumb literal pools elsewhere in ROM
        # hold 4-aligned pointers into the bank — e.g. the junk-shop revisit
        # prompt literal 0x081336E0 -> 0x0807DED2 (mid-entry) drew the JP
        # どうしますか？ while the entry's first-visit flow drew English.  The
        # incoming `rom` already carries every hook/cave (pack runs last), so
        # sites are discovered on the PRISTINE base ROM — cave bytes can't
        # false-positive — and rewritten only if the build still holds the
        # original value (a site overwritten by a patch no longer exists).
        #
        # SITES ARE WHITELISTED BY REGION (lesson of 2026-06-13: a blind
        # whole-ROM scan rewrote 4-byte runs of TILE PIXEL DATA whose bytes
        # happened to form a remapped bank address — e.g. 0x08487678 sits in a
        # F003F003... tile-row run — and the user saw glitched dungeon sprite
        # tiles).  Only ranges with verified pointer semantics qualify; a real
        # pointer outside them just stays JP (the pre-existing behavior):
        #   1-2. engine code (Thumb literal pools) — the bank splits it in two;
        #   3. map/NPC event-trigger records ({type, id, script_ptr,
        #      0xFFFFFFFE...} shape verified at 0x084C74B8/0x084D27EC; the
        #      0x084EE region is 0xC-stride spawn records sharing one script);
        #   4. the compendium lore table (ptr@+0, stride 0x14) — its
        #      walker-appended inline entries are ptr-less in lore.json, so
        #      this is what repoints their slots to the pooled English.
        EXT_SITE_RANGES = (
            (0x08000000, _sp["lo"]),         # 1. engine code before the bank
            (_sp["hi"], 0x08166000),         # 2. code after the bank (incl. 0x080AF/0x08133/0x0813E literals + 0x080B8/0x08165 task records)
            (0x084C0000, 0x084F0000),        # 3. map/NPC event-trigger record region
            (0x08583E84, 0x08586000),        # 4. lore table ptr slots — runs PAST the
                                             #    section's count=0x148 (slots @0x08585ACC+
                                             #    are stride-0x14 slot-0 hits on appended
                                             #    entries that carry 0x0350 heads; leaving
                                             #    them bank-side would draw head garbage)
            (0x087DF550, 0x087DF938),        # 5. field map-event / warp trigger table
                                             #    (elevators, NPCs, doors): 125 {script_ptr,
                                             #    coords} records. Most script_ptrs hit entry
                                             #    starts (already redirect via the 0x0350 head),
                                             #    but a few point INTERIOR to a big entry — e.g.
                                             #    the elevator embedded in 0804CBC0 (site
                                             #    0x087DF580 -> 0804D26C) drew JP. word1 is small
                                             #    coords (never a 0x08xxxxxx value -> can't
                                             #    false-positive); the run is framed by FFFFFFFF
                                             #    / 00000000 sentinels.  Interior targets get the
                                             #    anchor-mapped pool offset; header/gap targets
                                             #    (not inside any captured span) are left as-is
                                             #    and keep working via their own 0x0350 head.
        )
        _base = rommap.ROM_PATH
        if _base.exists():
            rom0 = _base.read_bytes()
            for _rlo, _rhi in EXT_SITE_RANGES:
                for _o in range(_rlo - ROM_BASE, min(_rhi - ROM_BASE, len(rom0) - 3), 4):
                    _v = int.from_bytes(rom0[_o:_o + 4], "little")
                    if _sp["lo"] <= _v < _sp["hi"] and not (_v & 1):
                        ext_sites.append((_o, _v))
            refs.add_targets(t for _o, t in ext_sites)
        else:
            print("  ! script refs: base ROM not found — out-of-bank sites skipped")


# Per-field shared-setup bundle passed to the cascade route handlers (built once per field, after
# the guards, before the cascade).  Immutable: _arm_story_expand rebinds only its own local `blob`
# alias when it splices a 0x030F jump-back tail; it never writes pf back.
PackField = namedtuple("PackField", "term blob addrs ptrs budget force_repoint fits")


class Field(dict):
    """Typed read accessor over a translation leaf-field dict (doc §7).  A dict SUBCLASS, so all
    existing dict access (f[...], f.get(), 'x' in f) keeps working — it just adds named,
    intention-revealing reads for the pack path.  Wrap once: `for f in map(Field, fields(entry))`.
    The is_* booleans mirror the per-field flags; all_addrs/all_ptrs fold the recurring
    "the addrs list, or [addr] if it's a single-addr field" pattern."""
    @property
    def replace(self):       return self.get("replace")
    @property
    def term(self):          return self.get("term")
    @property
    def addr(self):          return self.get("addr")
    @property
    def addrs(self):         return self.get("addrs")
    @property
    def ids(self):           return self.get("ids")
    @property
    def has_max(self):       return "max" in self
    @property
    def has_ptr(self):       return "ptr" in self
    @property
    def is_item_table(self): return bool(self.get("item_table"))
    @property
    def is_name_table(self): return bool(self.get("name_table"))
    @property
    def is_sentinel(self):   return bool(self.get("sentinel"))
    @property
    def is_aff(self):        return bool(self.get("aff"))
    @property
    def is_label(self):      return self.get("kind") == "label"
    @property
    def all_addrs(self):     return self.get("addrs") or ([self["addr"]] if "addr" in self else [])
    @property
    def all_ptrs(self):      return self.get("ptrs") or ([self["ptr"]] if "ptr" in self else [])


# ---- route handlers: one per dispatch arm of _pack_fields, bodies extracted verbatim -----------
# Field-flag GUARDS take (st, sec, f, rep) and return ((applied, warned, repointed), done) — done
# True = "field fully handled, continue the field loop".  CASCADE arms take (st, sec, f, rep, pf)
# and return (applied, warned, repointed) deltas, except _arm_story_expand which also returns a done
# flag for its over-budget skip.  Counters are local and folded by the driver, as in the original.
# To add a route: write a handler + add its predicate arm to _pack_fields (the dispatch ORDER is
# load-bearing — arms are not mutually exclusive, so the first matching elif wins).

def _guard_item_table(st, sec, f, rep):
    """G0: mirror item/equipment name to the id->ptr pool table (any length); the hooked menu
    (patch_itemname) + status (patch_drop) draw from it.  NO continue — the field FALLS THROUGH to
    the cascade (where the inline write feeds non-hooked drawers if it fits, else the C6 no-op)."""
    rom, alloc, logp = st.rom, st.alloc, st.logp
    applied = warned = repointed = 0
    try:
        p = alloc(encode(rep) + b"\x00\x00")
        o = ITEM_TABLE - ROM_BASE + f["id"] * 4
        rom[o:o + 4] = p.to_bytes(4, "little")
        logp(o, p)
        repointed += 1
    except ValueError:
        pass
    return (applied, warned, repointed), False


def _guard_label(st, sec, f, rep):
    """G1: menu glyph-literal label -> per-glyph in place when it fits, else a pool pointer (menu
    hook draws it)."""
    rom, alloc, logw, logp = st.rom, st.alloc, st.logw, st.logp
    applied = warned = repointed = 0
    slots = f["slots"]
    if len(rep) <= len(slots):              # fits -> per-glyph (no menu hook needed)
        for (lit, _x), ch in zip(slots, rep):
            o = int(lit, 16) - ROM_BASE
            rom[o:o + 2] = CHAR2CODE.get(ch, CHAR2CODE[" "]).to_bytes(2, "little")
            logw(o, rom[o:o + 2])
        for (lit, _x) in slots[len(rep):]:  # blank any leftover slots
            o = int(lit, 16) - ROM_BASE
            rom[o:o + 2] = (0x00BC).to_bytes(2, "little")
            logw(o, rom[o:o + 2])
    else:                                   # too long -> pool pointer (menu hook draws it)
        try:
            blob = encode(rep) + b"\x00\x00"
        except ValueError as e:
            print(f"  ! {sec.id} {rep!r}: {e} — skipped")
            warned += 1
            return (applied, warned, repointed), True
        new = alloc(blob)
        o0 = int(slots[0][0], 16) - ROM_BASE
        rom[o0:o0 + 4] = new.to_bytes(4, "little")   # slot0 literal -> pool pointer (u32)
        logp(o0, new)
        for (lit, _x) in slots[1:]:                  # blank the rest (space = no ink)
            o = int(lit, 16) - ROM_BASE
            rom[o:o + 2] = (0x00BC).to_bytes(2, "little")
            logw(o, rom[o:o + 2])
        repointed += 1
    applied += 1
    return (applied, warned, repointed), True


def _guard_name_table(st, sec, f, rep):
    """G2: demon name -> pooled string + id->ptr table (no +0x22 write)."""
    rom, alloc, logp = st.rom, st.alloc, st.logp
    applied = warned = repointed = 0
    try:
        blob = encode(rep) + b"\x00\x00"
    except ValueError as e:
        print(f"  ! {sec.id} {rep!r}: {e} — skipped")
        warned += 1
        return (applied, warned, repointed), True
    p = alloc(blob)
    o = NAME_TABLE - ROM_BASE + f["id"] * 4
    rom[o:o + 4] = p.to_bytes(4, "little")
    logp(o, p)
    applied += 1
    repointed += 1
    return (applied, warned, repointed), True


def _guard_ids(st, sec, f, rep):
    """G3: battle template -> repoint FUN_080ec038 table[id] (+ declared extra_refs) to pooled EN."""
    rom, alloc, logp = st.rom, st.alloc, st.logp
    applied = warned = repointed = 0
    try:
        blob = encode(rep) + b"\x01\x03"   # template terminator = 0x0301
    except ValueError as e:
        print(f"  ! {sec.id} {rep!r}: {e} — skipped"); warned += 1
        return (applied, warned, repointed), True
    if len(blob) > 0x80:                    # FUN_080ebca4 buffer is 128B (subs expand further)
        print(f"  ! battle id {f['ids'][0]:#x}: {rep!r} {len(blob)}B may overflow the box")
    bp = alloc(blob)
    for i in f["ids"]:
        rom[BATTLE_MSG_TABLE - ROM_BASE + i * 4:BATTLE_MSG_TABLE - ROM_BASE + i * 4 + 4] = \
            bp.to_bytes(4, "little")
        logp(BATTLE_MSG_TABLE - ROM_BASE + i * 4, bp)
    # declared out-of-table refs (code literals / handler-record fields) that bypass the table —
    # rewrite them to the same pooled English (sections.py Section.extra_refs; consumers verified)
    for s in sec.extra_refs.get(int(f["addr"], 16), ()):
        o = s - ROM_BASE
        rom[o:o + 4] = bp.to_bytes(4, "little")
        logp(o, bp)
        repointed += 1
    applied += 1
    repointed += 1
    return (applied, warned, repointed), True


def _arm_inline_single(st, sec, f, rep, pf):
    """C1: single copy that fits -> write in place."""
    rom, logw = st.rom, st.logw
    refs, story_sec, inline_spans, script_blobs = st.refs, st.story_sec, st.inline_spans, st.script_blobs
    blob, addrs = pf.blob, pf.addrs
    applied = warned = repointed = 0
    o = int(addrs[0], 16) - ROM_BASE          # single copy, fits -> in place
    rom[o:o + len(blob)] = blob
    logw(o, blob)
    if refs is not None and sec.id == story_sec.id:
        ai = int(addrs[0], 16)
        inline_spans.append((ai, refs.span_end.get(ai, ai + len(blob))))
        script_blobs.append((ai, blob))
    applied += 1
    return applied, warned, repointed


def _arm_repoint(st, sec, f, rep, pf):
    """C2: repoint once, retarget every pointer (desc / shared ptr-table string)."""
    rom, alloc, logp = st.rom, st.alloc, st.logp
    refs, script_blobs = st.refs, st.script_blobs
    blob, ptrs, addrs = pf.blob, pf.ptrs, pf.addrs
    applied = warned = repointed = 0
    new = alloc(blob)
    for p in ptrs:
        o = int(p, 16) - ROM_BASE
        rom[o:o + 4] = new.to_bytes(4, "little")
        logp(o, new)
    # A repointed table string can ALSO be reached through hardcoded code literals that
    # bypass the table (e.g. negotiate_status entry 0, the "...手に入れた" item-get template:
    # the negotiation gift reaches it via the table slot, but the generic give-item opcode
    # paths load it as a code literal). Rewrite those declared slots to the same pooled EN
    # so every reference follows -- the inline JP stays intact for any undeclared reader.
    for s in (sec.extra_refs.get(int(addrs[0], 16), ()) if addrs else ()):
        o = s - ROM_BASE
        rom[o:o + 4] = new.to_bytes(4, "little")
        logp(o, new)
    if refs is not None and sec.id == "dialogue":
        # negotiation streams carry ops too — rescan for embedded refs
        script_blobs.append((new, blob))
    applied += 1
    repointed += 1
    return applied, warned, repointed


def _arm_inline_multi(st, sec, f, rep, pf):
    """C3: inline, multiple copies -> write each."""
    rom, logw = st.rom, st.logw
    refs, story_sec, inline_spans, script_blobs = st.refs, st.story_sec, st.inline_spans, st.script_blobs
    blob, addrs = pf.blob, pf.addrs
    applied = warned = repointed = 0
    for a in addrs:
        o = int(a, 16) - ROM_BASE
        rom[o:o + len(blob)] = blob
        logw(o, blob)
        if refs is not None and sec.id == story_sec.id:
            ai = int(a, 16)
            inline_spans.append((ai, refs.span_end.get(ai, ai + len(blob))))
            script_blobs.append((ai, blob))
    applied += 1
    return applied, warned, repointed


def _arm_extra_refs(st, sec, f, rep, pf):
    """C4: over budget, but the section declares this string's pointer slots / code literals
    (Section.extra_refs, each consumer verified): pool the English and rewrite the slots.  The
    original inline JP stays intact — never a sentinel — so any undeclared reader degrades to JP."""
    rom, alloc, logp = st.rom, st.alloc, st.logp
    blob, addrs = pf.blob, pf.addrs
    applied = warned = repointed = 0
    new = alloc(blob)
    for s in sec.extra_refs[int(addrs[0], 16)]:
        o = s - ROM_BASE
        rom[o:o + 4] = new.to_bytes(4, "little")
        logp(o, new)
    applied += 1
    repointed += 1
    return applied, warned, repointed


def _arm_sentinel(st, sec, f, rep, pf):
    """C5: over budget -> 0xFFFF sentinel at field[0] + pooled-string pointer at field+2 (the hooked
    drawer resolves the sentinel)."""
    rom, alloc, logw, logp = st.rom, st.alloc, st.logw, st.logp
    blob, addrs = pf.blob, pf.addrs
    applied = warned = repointed = 0
    new = alloc(blob)
    for a in addrs:
        o = int(a, 16) - ROM_BASE
        rom[o:o + 2] = b"\xff\xff"            # 0xFFFF sentinel at field[0]
        rom[o + 2:o + 6] = new.to_bytes(4, "little")   # pooled-string pointer at field+2
        logw(o, b"\xff\xff")
        logp(o + 2, new)
    applied += 1
    repointed += 1
    return applied, warned, repointed


def _arm_item_table_noop(st, sec, f, rep, pf):
    """C6: over budget inline, but the pool table (written by the G0 guard) already covers it
    (menu + status draw from the table) — not a real skip."""
    applied = warned = repointed = 0
    applied += 1
    return applied, warned, repointed


def _arm_story_expand(st, sec, f, rep, pf):
    """C7: inline event-VM message -> 0x0350 jump to pooled English.

    The message head becomes [0x0350, ptr]; the cave (patch_dialog) redirects the VM to `blob`
    (English + its controls + 0x0301) which ends the message exactly as the JP did.  The 6-byte head
    fits any clean entry of >=2 tokens (budget includes the terminator slot); a 1-glyph referenced
    label (4-byte span) cannot take it.  Returns (counts, done) — done True on the over-budget skip."""
    rom, alloc, logw, logp = st.rom, st.alloc, st.logw, st.logp
    refs = st.refs
    script_remap, script_heads = st.script_remap, st.script_heads
    unmapped_interiors, script_blobs = st.unmapped_interiors, st.script_blobs
    term, blob, addrs = pf.term, pf.blob, pf.addrs
    applied = warned = repointed = 0
    if "max" in f and (f["max"] + 1) * 2 < 6:
        print(f"  ! {sec.id} {addrs[:1]}: {rep!r} over budget and span "
              f"too small for a 0x0350 head — skipped (stays JP)")
        warned += 1
        return (applied, warned, repointed), True
    # Truncated-capture entries (no real terminator — typically a variable-length 0x313 choice-row
    # block the walker stopped inside): the re-encoded op cluster would feed the choice handler
    # garbage rows (live bug: appraiser menu rows 1+ jumped junk slots). Drop the truncated cluster
    # from the English and jump (0x030F) back to the original bytes, which stay intact in the bank —
    # their row pointers are then rewritten to the pool by the remap pass like any other site.
    nc_tail = None
    enc_len = len(blob) - len(term)   # encoded rep length pre-truncation
    if (refs is not None and addrs):
        _ai0 = int(addrs[0], 16)
        if (refs.lo <= _ai0 < refs.hi and _ai0 in refs.toks
                and not refs.clean.get(_ai0, True)):
            _tgt, _k = refs.tail_cluster(_ai0)
            _off = None
            if _k == len(refs.toks[_ai0]):
                _off = len(blob) - len(term)   # prose tail: keep all EN
            else:
                try:
                    _rt = scriptrefs.tokenize_rep(rep, CHAR2CODE, ZERO_WIDTH)
                    _m = scriptrefs.map_interiors(
                        refs.toks[_ai0], _rt, [_tgt])
                    _off = _m.get(_tgt)
                except ValueError:
                    _off = None
            if _off is None:
                print(f"  ! {sec.id} {addrs[0]}: truncated-capture "
                      f"entry, tail unmappable — kept terminator "
                      f"(a choice op may misread)")
            else:
                blob = (blob[:_off] + b"\x0f\x03"
                        + (_tgt & 0xFFFF).to_bytes(2, "little")
                        + (_tgt >> 16).to_bytes(2, "little"))
                nc_tail = _k
    new = alloc(blob)
    rep_toks = None
    for a in addrs:
        o = int(a, 16) - ROM_BASE
        rom[o:o + 2] = SCRIPT_EXPAND_CODE.to_bytes(2, "little")
        rom[o + 2:o + 6] = new.to_bytes(4, "little")
        logw(o, rom[o:o + 2])
        logp(o + 2, new)
        if refs is None:
            continue
        ai = int(a, 16)
        if not (refs.lo <= ai < refs.hi):
            continue
        script_remap[ai] = new
        script_heads.append(ai)
        ints = refs.interiors_of(ai)
        if nc_tail is not None:
            # targets inside the dropped tail stay JP-side (correct:
            # those bytes remain live in the bank)
            _cut, _ = refs.tail_cluster(ai)
            ints = [t for t in ints if t < _cut]
        if ints and ai in refs.toks:
            if rep_toks is None:
                try:
                    rep_toks = scriptrefs.tokenize_rep(
                        rep, CHAR2CODE, ZERO_WIDTH)
                    if sum(s for _k, _kd, s in rep_toks) != enc_len:
                        rep_toks = []      # size mismatch: don't trust offsets
                except ValueError:
                    rep_toks = []
            if rep_toks:
                m = scriptrefs.map_interiors(refs.toks[ai], rep_toks, ints)
            else:
                m = {t: None for t in ints}
            for t, off in sorted(m.items()):
                if off is None or off >= len(blob):
                    unmapped_interiors.append((ai, t))
                else:
                    script_remap[t] = new + off
    if refs is not None:
        script_blobs.append((new, blob))
    applied += 1
    repointed += 1
    return (applied, warned, repointed), False


def _arm_literal_ptr_deferred(st, sec, f, rep, pf):
    """C8: translated but unreachable — no slots declared and over the inline budget (walk/
    composition-reached strings awaiting the deferred repoint mechanism).  Stay JP; summarized once
    in _finalize instead of per-line warning noise."""
    deferred = st.deferred
    addrs = pf.addrs
    applied = warned = repointed = 0
    deferred.append(f"{sec.id} {addrs[0]}")
    return applied, warned, repointed


def _arm_warn_skip(st, sec, f, rep, pf):
    """C9: no mechanism matched and over budget -> warn-skip (stays JP)."""
    blob, addrs, budget = pf.blob, pf.addrs, pf.budget
    applied = warned = repointed = 0
    print(f"  ! {sec.id} {addrs[:1]}: {rep!r} {len(blob)}>{budget}B — skipped")
    warned += 1
    return applied, warned, repointed


def _pack_fields(st):
    """The main phase-1 field loop: per-section, per-field route DISPATCH.  Each arm's body lives in
    a named _guard_*/_arm_* handler above; this driver keeps the loop, the shared per-field setup,
    and the load-bearing dispatch ORDER (the 4 field-flag guards then the priority elif cascade —
    arms are NOT mutually exclusive, so order disambiguates; item_table FALLS THROUGH the guard into
    the cascade).  Accumulators are local, folded into st below (P7/P8 also count)."""
    rom = st.rom
    refs = st.refs
    story_sec = st.story_sec
    secdata = st.secdata

    applied = warned = repointed = 0
    # NB: resist lines are NOT propagated across demons. English reverses the JP order (the
    # relationship word moves to the front, so a demon's two display lines must be authored
    # together and a single JP line has no demon-independent English) — each aff1/aff2 is its own
    # per-demon (addr-keyed) field, translated individually.
    for sec in sections.in_pack_order():
        if sec.phase != 1:                  # block rebuilds (battlefrag) run in phase 2 below
            continue
        for entry in secdata[sec.id]:
            for f in map(Field, fields(entry)):
                rep = f.replace
                if rep is None:
                    continue
                if sec.wrap_px:             # prose windows: auto-insert {n} at the px budget
                    rep = autowrap(rep, sec, rom,
                                   ctx=f"{sec.id} {f.addr or f.addrs or f.ids}",
                                   orig=f.get("original"))
                # ---- field-flag guards (ordered; item_table falls through, the rest continue) ----
                if f.is_item_table:
                    (a, w, r), _done = _guard_item_table(st, sec, f, rep)
                    applied += a; warned += w; repointed += r
                if f.is_label:
                    (a, w, r), done = _guard_label(st, sec, f, rep)
                    applied += a; warned += w; repointed += r
                    if done:
                        continue
                if f.is_name_table:
                    (a, w, r), done = _guard_name_table(st, sec, f, rep)
                    applied += a; warned += w; repointed += r
                    if done:
                        continue
                if "ids" in f:
                    (a, w, r), done = _guard_ids(st, sec, f, rep)
                    applied += a; warned += w; repointed += r
                    if done:
                        continue
                # ---- shared per-field setup (term / blob / pad / addrs / ptrs / budget / fits) ----
                term = {"0000": b"\x00\x00", "0301": b"\x01\x03"}.get(f.term, b"")
                try:
                    blob = encode(rep) + term
                except ValueError as e:
                    print(f"  ! {sec.id} {rep!r}: {e} — skipped")
                    warned += 1
                    continue
                pad_tok = sec.source.params.get("pad")
                if pad_tok is not None:
                    # fixed unterminated cell (location names): pad to exactly `max`
                    # tokens with the table's pad glyph, never write a terminator
                    # (readers index by map id and render the full cell).
                    if len(blob) > f["max"] * 2:
                        print(f"  ! {sec.id} {f['addr']} {rep!r}: {len(blob) // 2} tokens "
                              f"> {f['max']}-token cell — skipped")
                        warned += 1
                        continue
                    blob += pad_tok.to_bytes(2, "little") * (f["max"] - len(blob) // 2)
                addrs = f.all_addrs
                ptrs = f.all_ptrs
                budget = (f["max"] + 1) * 2 if f.has_max else 0
                force_repoint = f.has_ptr           # desc: shared string -> always repoint
                # Resist/affinity lines (aff) have a SINGLE reader (FUN_080cd2a0) whose inline-draw
                # fallback is fixed-12px, so an English line that *fits* the budget would draw
                # fixed-width while a longer one drew VWF. Force every translated aff line to repoint
                # (0xFFFF + pool pointer) so the hooked drawer always takes the VWF path; untranslated
                # JP stays inline-fixed. NB: scope this to `aff` ONLY — skill names also carry
                # `sentinel` but their +0x06 field is read by SEVERAL drawers (some unhooked, e.g. the
                # magic-select menu), so forcing them to repoint renders the raw 0xFFFF+ptr as garbage
                # glyphs there. Skill/race names stay inline-when-fits (their hooks draw inline VWF).
                fits = budget and len(blob) <= budget and not f.is_aff
                if (fits and refs is not None and sec.id == story_sec.id
                        and (any(int(a, 16) in refs.interior for a in addrs)
                             or not refs.clean.get(int(addrs[0], 16), True))):
                    # interior branch targets need pool offsets, and truncated-
                    # capture entries need a jump-back tail -> repoint either way
                    fits = False
                pf = PackField(term, blob, addrs, ptrs, budget, force_repoint, fits)
                # ---- priority cascade (predicates verbatim; first match wins; bodies are arms) ----
                if not force_repoint and len(addrs) == 1 and fits:
                    a, w, r = _arm_inline_single(st, sec, f, rep, pf)
                elif ptrs:
                    a, w, r = _arm_repoint(st, sec, f, rep, pf)
                elif fits:
                    a, w, r = _arm_inline_multi(st, sec, f, rep, pf)
                elif addrs and sec.extra_refs.get(int(addrs[0], 16)):
                    a, w, r = _arm_extra_refs(st, sec, f, rep, pf)
                elif (f.is_sentinel or sec.route == "sentinel"
                      # The mixed legacy `system` section scopes the sentinel arm via its
                      # manifest sentinel_gate: menu/command/error text (>=0x08123800,
                      # 0x0000-terminated) routes through BattleMenu_SetMode, whose entry hook
                      # (patch_battlemenu) resolves the 0xFFFF sentinel. Battle-log frags
                      # (<0x08123800) and battle-event lines (0x0301-term) use other copy
                      # paths and are NOT repointed here.
                      or (sec.sentinel_gate and addrs
                          and int(addrs[0], 16) >= sec.sentinel_gate["min_addr"]
                          and f.term == sec.sentinel_gate["term"])):
                    a, w, r = _arm_sentinel(st, sec, f, rep, pf)
                elif f.is_item_table:
                    a, w, r = _arm_item_table_noop(st, sec, f, rep, pf)
                elif (sec.route == "story_expand"
                      # Story-walker-appended entries in other sections (lore's inline
                      # compendium texts, appended_by="story") are event-VM messages too:
                      # ptr-less, max+term=0301. Same mechanism — without this they have
                      # no over-budget arm and warn-skip (hit when lore was translated,
                      # 2026-06-11; they packed fine back when they lived in story.json).
                      or (not ptrs and "max" in f
                          and sec.source.params.get("appended_by") == "story")):
                    (a, w, r), done = _arm_story_expand(st, sec, f, rep, pf)
                    applied += a; warned += w; repointed += r
                    if done:
                        continue
                    a = w = r = 0                   # already folded above; avoid double count at tail
                elif sec.route == "literal_ptr" and not ptrs:
                    a, w, r = _arm_literal_ptr_deferred(st, sec, f, rep, pf)
                else:
                    a, w, r = _arm_warn_skip(st, sec, f, rep, pf)
                applied += a; warned += w; repointed += r
    st.applied += applied
    st.warned += warned
    st.repointed += repointed


def _remap_rewrite(st):
    """Script pointer remap rewrite (see _remap_prepass).  Rewrites every embedded bank / blob /
    out-of-bank pointer site whose target was repointed to the pool during _pack_fields.  A no-op
    when there is no story section (refs is None) or nothing was repointed."""
    rom = st.rom
    refs = st.refs
    script_remap = st.script_remap
    inline_spans = st.inline_spans
    script_heads = st.script_heads
    script_blobs = st.script_blobs
    ext_sites = st.ext_sites
    unmapped_interiors = st.unmapped_interiors
    logp = st.logp
    if refs is not None and script_remap:
        inline_spans.sort()
        _isp_starts = [s for s, _e in inline_spans]

        def _in_inline(site):
            i = bisect.bisect_right(_isp_starts, site) - 1
            return i >= 0 and site < inline_spans[i][1]

        _heads = sorted(script_heads)

        def _hits_head(site):                # site is 4 bytes, a head is 6
            i = bisect.bisect_right(_heads, site + 3) - 1
            return i >= 0 and _heads[i] + 6 > site

        rw_bank = rw_blob = 0
        for o, t in refs.sites:
            new = script_remap.get(t)
            if new is None:
                continue
            site = refs.lo + o
            if _in_inline(site) or _hits_head(site):
                continue                     # stale (entry re-encoded) / inside a head
            fo = site - ROM_BASE
            rom[fo:fo + 4] = new.to_bytes(4, "little")
            logp(fo, new)
            rw_bank += 1
        for base_addr, blob in script_blobs:
            for o, t in scriptrefs.scan_pairs(blob, base_addr, refs.lo, refs.hi):
                new = script_remap.get(t)
                if new is None:
                    continue
                fo = base_addr - ROM_BASE + o
                rom[fo:fo + 4] = new.to_bytes(4, "little")
                logp(fo, new)
                rw_blob += 1
        rw_ext = 0
        _ext_verbose = os.environ.get("TR_REFS_VERBOSE")
        for fo, t in ext_sites:
            new = script_remap.get(t)
            if new is None:
                continue
            if int.from_bytes(rom[fo:fo + 4], "little") != t:
                continue                     # a patch overwrote the site: pointer gone
            rom[fo:fo + 4] = new.to_bytes(4, "little")
            logp(fo, new)
            rw_ext += 1
            if _ext_verbose:
                print(f"    ext rewrite: site {ROM_BASE + fo:08X} {t:08X} -> {new:08X}")
        n_int = sum(len(v) for v in refs.interior.values())
        print(f"  script refs: {len(refs.sites)} sites + {len(ext_sites)} out-of-bank, "
              f"{n_int} interior targets, "
              f"{len(script_remap)} addrs remapped "
              f"({rw_bank} bank + {rw_blob} blob + {rw_ext} out-of-bank rewrites); "
              f"{len(unmapped_interiors)} interiors unmappable (stay JP)")
        if unmapped_interiors and os.environ.get("TR_REFS_VERBOSE"):
            for ai, t in unmapped_interiors:
                print(f"    unmapped: entry {ai:08X} target {t:08X}")


def _rebuild_battlefrag(st):
    """Battle action fragments (enemy/special actions + item-used / skill-cast).  Independent of the
    remap state — uses only secdata + the pool.  Accumulators are local, folded into st below."""
    rom = st.rom
    secdata = st.secdata
    events = st.events
    alloc = st.alloc
    applied = warned = repointed = 0
    # Short fragments copied into a buffer with the actor name PREPENDED, then drawn.  Reached by a PATCHWORK:
    # small tables (BATTLEFRAG_ACTION_TABLE 0x086BED5C: status-result は/を pairs + verbs), code literals
    # (cast/used/prompt/defeated/damage), and skip-null WALKS from a table base for the long unreferenced
    # runs (enemy special actions, status).
    # English is longer than the JP, so we rebuild the WHOLE contiguous block (battlefrag.json, in addr order)
    # in the pool, then AUTO-REPOINT every pointer that targets a fragment start to its rebuilt copy — so
    # tables + literals are covered without hand-listing, and walk-reached fragments work by contiguity (the
    # rebuilt block keeps addr order, so a skip-null walk from any repointed base lands correctly).
    #
    # PLACEHOLDER SYNTAX (every translated fragment is a full template):
    #   [name]               REQUIRED, exactly once — the actor/target name.
    #                        At the very start: stripped (the engine/wedge-cave prepends it) —
    #                        valid for EVERY fragment.
    #                        Anywhere else: encoded as the 0xFFFE name sentinel, spliced in by
    #                        cave_namemove — valid ONLY for fragments reached through the hooked
    #                        builders (the BATTLEFRAG_ACTION_TABLE slots + the defeated code literal
    #                        + the actor-prompt literal; the movable set is read from the ROM below).
    #   [item]/[skill]/[damage]  the one code-inserted value — encoded as the 0xFFFF insertion
    #                        sentinel.  cave_battlewedge (item/skill) and patch_battlename's
    #                        dmgsplit cave (damage digits) copy the prefix up to it, insert the
    #                        value, then the engine copies the suffix.  ({NAME} accepted as a
    #                        legacy spelling of the same sentinel.)  Cannot combine with a
    #                        moved [name] (no builder handles both sentinels).
    #   "standalone": true   entry whose addr is INSIDE another fragment (a table slot pointing
    #                        mid-string, e.g. 08123A7E = slot 0xA9 skipping the dead 0x1200
    #                        token).  Allocated as its own pool string — never part of the
    #                        contiguous blob, so skip-null walk contiguity is preserved.
    #                        Untranslated: skipped entirely (the slot keeps its JP target).
    for bf_sec in (s for s in sections.in_pack_order() if s.route == "block_rebuild"):
        bfrags = secdata[bf_sec.id]
        # movable-[name] set: every fragment the hooked builders reach.  Read from the ROM
        # before any repointing touches the table.
        t = rommap.BATTLEFRAG_ACTION_TABLE - ROM_BASE
        movable = {int.from_bytes(rom[t + i * 4:t + i * 4 + 4], "little")
                   for i in range(rommap.BATTLEFRAG_ACTION_TABLE_COUNT)}
        d = rommap.BATTLEFRAG_DEFEATED_SLOT - ROM_BASE
        movable.add(int.from_bytes(rom[d:d + 4], "little"))
        # Battle_BuildActorPrompt reads はどうしますか via its own code literal; patch_namemove now
        # hooks it too, so the prompt's mid-string [name] ("What will [name] do?") can be spliced.
        pr = rommap.BATTLEFRAG_PROMPT_SLOT - ROM_BASE
        movable.add(int.from_bytes(rom[pr:pr + 4], "little"))
        blob = b""
        newaddr = {}                       # orig fragment addr -> rebuilt absolute addr
        newoff = {}                        # orig fragment addr -> offset in the rebuilt block
        prev_addr = 0
        for fr in bfrags:
            addr = int(fr["addr"], 16)
            rep = fr.get("replace")
            enc = None
            if rep:
                try:
                    rep = autowrap(rep, bf_sec, rom,
                                   ctx=f"{bf_sec.id} {fr.get('role', fr['addr'])}")
                    body = rep.replace("{NAME}", "[item]")           # legacy spelling
                    if body.count("[name]") != 1:
                        raise ValueError("exactly one [name] (the actor/target) is required")
                    if body.startswith("[name]"):
                        nparts = [body[6:]]                          # engine/hook prepends it
                    elif addr not in movable:
                        raise ValueError("[name] may only move on fragments reached via the "
                                         "hooked builders (action-table slots / defeated literal)")
                    else:
                        nparts = body.split("[name]")
                    parts = re.split(r"\[(?:item|skill|damage)\]", nparts[-1])
                    if len(nparts) == 2 and (len(parts) == 2
                                             or re.search(r"\[(?:item|skill|damage)\]", nparts[0])):
                        raise ValueError("a moved [name] can't combine with [item]/[skill]/[damage]")
                    if len(parts) > 2:
                        raise ValueError("at most one [item]/[skill]/[damage] placeholder")
                    if len(nparts) == 2:                             # moved name insertion point
                        enc = encode(nparts[0]) + b"\xfe\xff" + encode(nparts[1])
                    elif len(parts) == 2:                            # value insertion point
                        enc = encode(parts[0]) + b"\xff\xff" + encode(parts[1])
                    else:
                        enc = encode(parts[0])
                except ValueError as e:
                    print(f"  ! {bf_sec.id} {fr.get('role', fr['addr'])}: {e} — kept JP"); warned += 1
                    enc = None
            if fr.get("standalone"):       # off-blob fragment (slot pointing mid-string)
                if enc is not None:
                    newaddr[addr] = alloc(enc + b"\x00\x00")
                continue
            if addr <= prev_addr:          # blob order IS walk order — never reorder entries
                raise SystemExit(f"{bf_sec.id}: entries out of addr order at {fr['addr']}")
            prev_addr = addr
            if enc is None:                # untranslated/failed: copy the raw JP fragment (preserve the walk)
                a = addr - ROM_BASE
                j = a
                while rom[j:j + 2] != b"\x00\x00":
                    j += 2
                enc = bytes(rom[a:j])
            newoff[addr] = len(blob)
            blob += enc + b"\x00\x00"
        base = alloc(blob)
        newaddr.update({orig: base + off for orig, off in newoff.items()})
        limit = POOL_START - ROM_BASE      # repoint only original ROM pointers, never the rebuilt pool copy
        for orig, new in newaddr.items():
            pat = orig.to_bytes(4, "little"); nb = new.to_bytes(4, "little"); i = 0
            while True:
                i = rom.find(pat, i)
                if i < 0 or i >= limit:
                    break
                rom[i:i + 4] = nb; repointed += 1
                if events is not None:      # target keyed by block offset (block sha is its pool event)
                    off = new - base
                    events.append(["ptr", f"{ROM_BASE + i:08X}",
                                   f"bf+{off:x}" if 0 <= off < len(blob) else f"bf@{new:08X}"])
                i += 4
        applied += 1
    st.applied += applied
    st.warned += warned
    st.repointed += repointed


def _apply_mirrors(st):
    """Mirrored JP-only copies (phase 3; declared per-section in the manifest).

    e.g. names_race: the encounter / ID battle lines look up race names via two 27-entry tables
    (086BECDC, 08777E28) that point at a JP copy @0x08123602+ — NOT the copy the section translates.
    Reuse the section's translations (matched by JP text) and repoint every table slot to freshly-
    pooled English (dedup per string); `extra` supplies strings that exist only in the mirrored copy
    (ガイア -> "Gaian")."""
    rom = st.rom
    secdata = st.secdata
    alloc, logp = st.alloc, st.logp
    repointed = 0
    for sec in sections.in_pack_order():
        for m in sec.mirrors:
            en_map = {}
            for e in secdata[sec.id]:
                for f in fields(e):
                    if f.get("replace"):
                        en_map[f["original"]] = f["replace"]
            for jp, en in m.extra:
                en_map.setdefault(jp, en)
            rpool = {}
            for tbl in m.tables:
                for i in range(m.count):
                    o = tbl - ROM_BASE + i * 4
                    ptr = int.from_bytes(rom[o:o + 4], "little")
                    jp, _ = decode(rom, ptr, 20, stops={0x0000})
                    en = en_map.get(jp)
                    if not en:
                        continue
                    if jp not in rpool:
                        try:
                            rpool[jp] = alloc(encode(en) + b"\x00\x00")
                        except ValueError:
                            continue
                    rom[o:o + 4] = rpool[jp].to_bytes(4, "little")
                    logp(o, rpool[jp])
                    repointed += 1
    st.repointed += repointed


def _finalize(st):
    """Pad the ROM to a power-of-two size, write the TR_PACK_LOG, print the summary, return bytes."""
    rom = st.rom
    events = st.events
    log_path = st.log_path
    data_kb = (len(rom) + 1023) // 1024
    target = 0x1000000                       # pad to a clean 16MB (power-of-2; room for EN script)
    while len(rom) > target:
        target <<= 1                         # 32MB+ if the pool ever outgrows 16MB
    if len(rom) < target:
        rom.extend(b"\xFF" * (target - len(rom)))
    if log_path:
        Path(log_path).write_text("\n".join(json.dumps(e) for e in events) + "\n",
                                  encoding="utf-8")
        print(f"pack log: {len(events)} events -> {log_path}")
    print(f"packed {st.applied} translations ({st.repointed} repointed)"
          + (f"; {st.warned} over budget" if st.warned else "")
          + (f"; {len(st.deferred)} deferred (walk-reached, no mechanism — stay JP)"
             if st.deferred else "")
          + f"; data {data_kb}K, ROM padded to {len(rom) // 1024 // 1024}MB")
    return bytes(rom)


def pack(rom):
    st = PackState(rom)
    _reserve_tables(st)        # reserve the NAME/ITEM/MARKER id->ptr pool tables
    _validate_manifest(st)     # manifest gate + load secdata (SystemExits fire before any ROM write)
    _remap_prepass(st)         # scriptrefs setup + out-of-bank pointer-site scan
    _pack_fields(st)           # the main per-section/per-field route loop (phase 1)
    _remap_rewrite(st)         # rewrite embedded script pointers to the pool
    _rebuild_battlefrag(st)    # rebuild + auto-repoint the battle-fragment block (phase 2)
    _apply_mirrors(st)         # repoint mirrored JP-only table slots (phase 3)
    return _finalize(st)       # pad, write log, print summary, return bytes


def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")
    ap = argparse.ArgumentParser(prog="tr.py", description=__doc__.splitlines()[0])
    sub = ap.add_subparsers(dest="cmd")
    sub.add_parser("extract", help="(re)generate text/corpus/*.json from the base ROM")
    pk = sub.add_parser("pack", help="write every non-null replace into a ROM")
    pk.add_argument("in_rom", help="input ROM (e.g. rom/smt2-en-font.gba)")
    pk.add_argument("out_rom", help="output ROM to write")
    args = ap.parse_args()
    if (args.cmd or "extract") == "extract":
        extract(rommap.load_rom())
    else:
        out = Path(args.out_rom)
        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_bytes(pack(Path(args.in_rom).read_bytes()))
        print(f"wrote {args.out_rom}")


if __name__ == "__main__":
    raise SystemExit(main())
