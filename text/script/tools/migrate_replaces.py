#!/usr/bin/env python3
"""P2 migrator: fold the leaked pointer high-words of the under-counted event-VM ops
INTO their `{=hex}` opcode token, across every translation JSON.

The fold is byte-neutral by construction — `{=0f03402c}句` and `{=0f03402c0807}` encode
to the identical bytes `2c 40 03 0f 07 08` (句 = 0x0807 = bytes 07 08). It only moves the
leaked operand high-word OUT of the translatable text (where a translator could clobber it
and softlock a jump) and INTO the opcode blob. Only the P0-identified leaker ops are folded;
name-substitution ops (0x31E/0x31F/…) are left exactly as-is (their over-count is load-bearing
for scriptrefs anchor alignment — plan landmine #5).

This is the JSON half of the atomic P2 change; the walker half (spec-driven slicing in
extract_story_vm + scriptrefs.tokenize_stream) lands together. Each field is checked
`encode(folded) == encode(original)` — a failure means a translator dropped/moved an operand
word and the field is reported, never silently rewritten.

Run:  python -m text.script.tools.migrate_replaces          # validate only
      python -m text.script.tools.migrate_replaces --apply  # rewrite JSON
"""
import json
import re
import sys
from pathlib import Path

try:
    from text.script.tools._boot import CONFIG, ROOT
except ModuleNotFoundError:
    from _boot import CONFIG, ROOT

from text.script import tr  # noqa: E402

TR = tr.TR
SPEC = {int(k, 16): v for k, v in
        json.loads((CONFIG / "opcode_spec.json").read_text()).items()}

# P2 step 1 (this commit): the FIXED, fully-captured pointer leakers — single- or
# triple-pointer conditional/unconditional jumps that are NOT in scriptrefs.VARIABLE_OPS
# and therefore don't touch the truncated-tail (tail_cluster) machinery. Expressible as a
# flat OPARGS bump, so the fold is a clean byte-neutral sidecar change.
FOLD_OPS = {0x30C, 0x30F, 0x356, 0x359, 0x33D}
# DEFERRED to P2 step 2 (the genuinely count-driven ops + the jump table, which change
# message-capture boundaries / interact with tail_cluster): 0x313, 0x413, 0x3E1.

_TOK = re.compile(r"\{[^}]*\}")


def _opcode_of(hexstr):
    """opcode word of a {=hex} body, or None if too short."""
    b = bytes.fromhex(hexstr)
    return (b[0] | (b[1] << 8)) if len(b) >= 2 else None


def _operand_bytes(op, blob):
    """Full operand byte length the spec says this op owns (variable: count from blob)."""
    s = SPEC[op]
    if s["var"]:
        v = s["var"]
        word1 = blob[2 + 2 * v["count_word"]] | (blob[3 + 2 * v["count_word"]] << 8)
        cnt = (word1 >> 8) + 1
        return (s["len"] + cnt * v["stride"]) * 2
    return s["len"] * 2


def _atoms(s):
    """(text, encoded_bytes) per atom of an already-canon'd string — mirrors tr.encode."""
    out, i = [], 0
    while i < len(s):
        if s[i] == "{":
            j = s.index("}", i)
            tok = s[i:j + 1]
            body = tok[1:-1]
            if body.startswith("="):
                out.append((tok, bytes.fromhex(body[1:])))
            elif body in tr.TOKENS:
                out.append((tok, tr.TOKENS[body].to_bytes(2, "little")))
            else:
                raise ValueError(f"unknown token {tok}")
            i = j + 1
        elif ord(s[i]) in tr.ZERO_WIDTH:
            i += 1
        else:
            c = tr.CHAR2CODE.get(s[i])
            if c is None:
                raise ValueError(f"no glyph for {s[i]!r}")
            out.append((s[i], c.to_bytes(2, "little")))
            i += 1
    return out


def _has_fold_op(s):
    for m in _TOK.findall(s or ""):
        if m.startswith("{=") and _opcode_of(m[2:-1]) in FOLD_OPS:
            return True
    return False


def fold(s):
    """Return (folded_string, deferred) — every FOLD_OP's trailing operand words absorbed into
    its {=hex} token. An op whose operand words can't be cleanly absorbed from the captured text
    (truncated capture, or a translator edit) is LEFT unfolded and counted in `deferred`."""
    if not s or not _has_fold_op(canon := tr.canon(s)):
        return s, []
    atoms = _atoms(canon)
    out, i, deferred = [], 0, []
    while i < len(atoms):
        txt, b = atoms[i]
        op = _opcode_of(txt[2:-1]) if txt.startswith("{=") else None
        if op in FOLD_OPS:
            target = _operand_bytes(op, b)
            if len(b) - 2 >= target:        # already folded (idempotent) — pass through
                out.append(txt)
                i += 1
                continue
            blob = bytearray(b)
            j = i + 1
            ok = True
            while len(blob) - 2 < target and j < len(atoms):
                nt, nb = atoms[j]
                if nt.startswith("{") and not nt.startswith("{="):  # name/control token mid-operand
                    ok = False
                    break
                blob += nb
                j += 1
            if not ok or len(blob) - 2 != target:
                deferred.append(f"0x{op:03X}")     # truncated/edited — leave unfolded
                out.append(txt)
                i += 1
                continue
            out.append("{=" + blob.hex() + "}")
            i = j
        else:
            out.append(txt)
            i += 1
    return tr.aliasify("".join(out)), deferred


def migrate_field(f, stats):
    changed = False
    addr = f.get("addr") or (f.get("addrs") or ["?"])[0]
    for key in ("original", "replace"):
        v = f.get(key)
        if not v or not _has_fold_op(tr.canon(v)):
            continue
        try:
            nv, deferred = fold(v)
        except ValueError as e:
            stats["fail"].append((addr, key, str(e), v))
            continue
        for d in deferred:
            stats["deferred"][d] = stats["deferred"].get(d, 0) + 1
        if tr.encode(nv) != tr.encode(v):
            stats["encfail"].append((addr, key))
            continue
        if nv != v:
            stats[f"{key}_changed"] += 1
            f[key] = nv
            changed = True
    return changed


def main():
    apply = "--apply" in sys.argv
    stats = {"replace_changed": 0, "original_changed": 0, "fail": [], "encfail": [], "deferred": {}}
    touched_files = []
    for jf in sorted(TR.glob("*.json")):
        data = json.loads(jf.read_text(encoding="utf-8"))
        file_changed = False
        for e in data:
            for f in tr.fields(e):
                if migrate_field(f, stats):
                    file_changed = True
        if file_changed:
            touched_files.append(jf.name)
            if apply:                          # tr.py extract's exact write form (round-trips)
                jf.write_text(tr.aliasify(json.dumps(data, ensure_ascii=False, indent=1)),
                              encoding="utf-8")
    print(f"fold ops: {sorted(hex(o) for o in FOLD_OPS)}")
    print(f"replace fields folded: {stats['replace_changed']}")
    print(f"original fields folded: {stats['original_changed']}")
    print(f"files touched: {len(touched_files)}  {touched_files}")
    if stats["deferred"]:
        print(f"deferred ops (truncated/edited capture, left unfolded): {stats['deferred']}")
    if stats["encfail"]:
        print(f"\n!! ENCODE-EQUALITY FAILURES ({len(stats['encfail'])}) — fold not byte-neutral:")
        for addr, key in stats["encfail"][:30]:
            print(f"     {addr} {key}")
    else:
        print("\n  ✓ every folded field is byte-identical under encode()")
    if stats["fail"]:
        print(f"\n!! UNFOLDABLE ({len(stats['fail'])}) — translator dropped/moved an operand word:")
        for addr, key, why, v in stats["fail"][:30]:
            print(f"     {addr} {key}: {why}")
            print(f"        {v[:80]}")
    print(f"\n{'APPLIED — JSONs rewritten' if apply else 'DRY-RUN — no files written (pass --apply to write)'}")


if __name__ == "__main__":
    sys.stdout.reconfigure(encoding="utf-8")
    main()
