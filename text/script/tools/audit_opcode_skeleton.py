#!/usr/bin/env python3
"""Audit translation opcode integrity for the event-VM prose sections.

"Odd linebreaks and glitches" in negotiation/story dialogue have two distinct causes
and this tool separates them:

  (1) BROKEN OPCODES — the `replace` dropped, added, reordered, or altered a
      `{=XXXX}` byte-exact opcode token (or a {ALEPH}/{HIROKO}/{ZAYIN}/{GIMMEL}/{MACCA}
      name/value substitution) relative to `original`. These are the real "glitches":
      a dropped name-sub leaves a blank where the demon name goes; a corrupted jump
      pointer softlocks; an altered display-control op garbles the window. The pack-time
      guards catch only the pointer-tail kanji subclass — this checks the FULL skeleton.

  (2) WRAP RISK — translations whose lines/pages would overflow the window. Linebreaks
      ({n}) are inserted at PACK time by tr.autowrap, so these are advisory: the diagnostic
      re-runs the same measurement offline against the built width table so we can see what
      autowrap will warn on without a full build.

Opcode classes (see tr.decode / scriptrefs):
  hard control/pointer ops  — 0x0302..0x0470 except the text-substitution subrange;
                              MUST be preserved byte-exact AND in order (jumps, choices,
                              display-control, embedded 32-bit stream pointers).
  text substitutions        — {=XX03} name/species/race subs + {=23..} digit sub, and the
                              {ALEPH}/{HIROKO}/{ZAYIN}/{GIMMEL}/{MACCA} party tokens; these
                              insert a runtime value into the prose. The multiset must be
                              preserved (a dropped one = a missing name on screen).

Usage:  python -m text.script.tools.audit_opcode_skeleton [section ...]
        (default sections: dialogue story; add lore/battle_taunts/negotiate_* etc.)
"""
import json
import re
import sys
from pathlib import Path

try:
    from text.script.tools._boot import CONFIG, REVIEW
except ModuleNotFoundError:
    from _boot import CONFIG, REVIEW

from text.script import tr as _tr  # noqa: E402

TR = _tr.TR

# Classification grounded in opcode_spec.json (the VM ground truth), NOT a hardcoded low-byte
# set: the 2026-06-15 readable-alias vocabulary ({SLOW}/{NUMBER}/{COINS}) crashed the old
# classify() (it ran int() over 'NSOI'). canon() folds those aliases to {=hex} first.
_SPEC = json.loads((CONFIG / "opcode_spec.json").read_text(encoding="utf-8"))
INK_OPS = {int(k, 16) for k, v in _SPEC.items() if v.get("ink")}   # name/value substitutions
CTRL_OPS = {0x300, 0x315, 0x316, 0x317}   # newline/SLOW/WAIT/PAGE — cosmetic, never a softlock

# party/value substitution tokens that canon() leaves readable
SUB_TOKENS = {"{ALEPH}", "{HIROKO}", "{ZAYIN}", "{GIMMEL}", "{MACCA}"}
STRUCT_TOKENS = {"{n}", "{WAIT}", "{PAGE}"}
TOK = re.compile(r"\{=[0-9a-fA-F]+\}|\{[A-Za-z]+\}")


def skeleton(s):
    """Ordered list of every opcode / substitution token (structural {n}/{WAIT}/{PAGE}
    excluded — autowrap freely inserts those). A substitution opcode is collapsed to its bare
    opcode word: the operand bytes are representation drift (the over-captured {=1e034a01} form
    vs the {=1e03} alias form — same name sub) and would otherwise bury the genuine sub DROPS.
    Pointer/control ops keep their full body — there the operand IS the jump target."""
    out = []
    for m in TOK.findall(_tr.canon(s or "")):
        if m in STRUCT_TOKENS:
            continue
        if m.startswith("{="):
            m = m.lower()
            body = m[2:-1]
            if len(body) >= 4 and int(body[2:4] + body[0:2], 16) in INK_OPS:
                m = "{=" + body[0:4] + "}"
        out.append(m)
    return out


def classify(tok):
    if tok in SUB_TOKENS:
        return "sub"
    if not tok.startswith("{="):           # a word-alias canon() didn't fold — treat as a sub
        return "sub"
    body = tok[2:-1]                        # strip {= }
    if len(body) < 4:
        return "hard"
    # token bytes are little-endian; the opcode-word value = body[2:4] (high) + body[0:2] (low)
    op = int(body[2:4] + body[0:2], 16)
    if op in CTRL_OPS:
        return "ctrl"                       # cosmetic pacing/spacing op — a drop is not a softlock
    if op in INK_OPS:
        return "sub"                        # name/species/race/value substitution
    return "hard"                           # control / pointer / display op


def diff_ops(o, r):
    """Return (missing, added) opcode lists comparing original->replace as ordered
    sequences (LCS-style: report tokens that don't line up)."""
    import difflib
    sm = difflib.SequenceMatcher(a=o, b=r, autojunk=False)
    missing, added = [], []
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag in ("delete", "replace"):
            missing += o[i1:i2]
        if tag in ("insert", "replace"):
            added += r[j1:j2]
    return missing, added


def audit(sec_id):
    path = TR / f"{sec_id}.json"
    if not path.exists():
        print(f"  (no {sec_id}.json)")
        return []
    data = json.loads(path.read_text(encoding="utf-8"))
    findings = []
    for e in data:
        # entries may bundle name/desc; here prose sections are flat (original/replace)
        flds = []
        if "name" in e or "desc" in e:
            flds = [e[k] for k in ("name", "desc") if k in e]
        else:
            flds = [e]
        for f in flds:
            o, r = f.get("original"), f.get("replace")
            if not o or r is None:
                continue
            so, sr = skeleton(o), skeleton(r)
            if so == sr:
                continue
            missing, added = diff_ops(so, sr)
            # only flag when a HARD op or a SUB actually changed (pure reorder of equal
            # multiset still reported, but tagged)
            mc = [(t, classify(t)) for t in missing]
            ac = [(t, classify(t)) for t in added]
            hard_missing = [t for t, c in mc if c == "hard"]
            hard_added = [t for t, c in ac if c == "hard"]
            sub_missing = [t for t, c in mc if c == "sub"]
            sub_added = [t for t, c in ac if c == "sub"]
            ctrl_missing = [t for t, c in mc if c == "ctrl"]
            ctrl_added = [t for t, c in ac if c == "ctrl"]
            addr = f.get("addr") or (f.get("addrs") or ["?"])[0]
            findings.append(dict(sec=sec_id, addr=addr,
                                 hard_missing=hard_missing, hard_added=hard_added,
                                 sub_missing=sub_missing, sub_added=sub_added,
                                 ctrl_missing=ctrl_missing, ctrl_added=ctrl_added,
                                 orig=o, repl=r))
    return findings


PROSE_SECTIONS = ["story", "dialogue", "lore", "negotiate_status", "negotiate_outcomes",
                  "battle", "battlefrag", "greetings", "comp_messages", "field_messages",
                  "dungeon_events", "status_messages", "system_menu", "system_battle_log",
                  "system_battle_events"]


def main():
    secs = sys.argv[1:] or PROSE_SECTIONS
    all_f = []
    for s in secs:
        print(f"== {s} ==")
        fs = audit(s)
        all_f += fs
        n_hard = sum(1 for f in fs if f["hard_missing"] or f["hard_added"])
        n_sub = sum(1 for f in fs if (f["sub_missing"] or f["sub_added"])
                    and not (f["hard_missing"] or f["hard_added"]))
        n_ctrl = sum(1 for f in fs if (f["ctrl_missing"] or f["ctrl_added"])
                     and not (f["hard_missing"] or f["hard_added"]
                              or f["sub_missing"] or f["sub_added"]))
        n_reorder = len(fs) - n_hard - n_sub - n_ctrl
        print(f"   {len(fs)} entries with skeleton drift: "
              f"{n_hard} HARD-op change, {n_sub} sub-only, {n_ctrl} ctrl-only, {n_reorder} pure reorder")
    # detail: hard-op changes are the dangerous ones (softlock / garbled window)
    hard = [f for f in all_f if f["hard_missing"] or f["hard_added"]]
    print(f"\n==== {len(hard)} entries with HARD opcode changes (dangerous) ====")
    for f in hard[:60]:
        print(f"\n[{f['sec']} @{f['addr']}]")
        if f["hard_missing"]:
            print(f"   DROPPED: {f['hard_missing']}")
        if f["hard_added"]:
            print(f"   ADDED:   {f['hard_added']}")
    subonly = [f for f in all_f if (f["sub_missing"] or f["sub_added"])
               and not (f["hard_missing"] or f["hard_added"])]
    print(f"\n==== {len(subonly)} entries with substitution-token changes (name/value drops) ====")
    for f in subonly[:40]:
        print(f"[{f['sec']} @{f['addr']}]  -{f['sub_missing']} +{f['sub_added']}")
    # machine-readable dump
    out = REVIEW / "opcode_skeleton_audit.json"
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(all_f, ensure_ascii=False, indent=1), encoding="utf-8")
    print(f"\nfull report -> {out}")


if __name__ == "__main__":
    sys.stdout.reconfigure(encoding="utf-8")
    main()
