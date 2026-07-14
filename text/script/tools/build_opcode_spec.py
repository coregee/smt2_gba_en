#!/usr/bin/env python3
"""P0 (opcode-representation-plan.md): ground-truth the per-opcode layout spec.

Produces `text/config/opcode_spec.json` — a superset of opcode_args.json that, unlike a
flat integer per opcode, can express the variable-length event-VM ops and carries the
pointer-word mask + the wrap metadata. The flat integer cannot represent ops whose
operand block is count-driven (ScriptOp_Choice 0x313, ScriptOp_ResponseList 0x413),
nor the under-counted fixed leakers — which is exactly why the story walker leaks the
pointer high-word as a bare `句`-class kanji (see the plan's diagnosis).

Ground truth (each fact verified two independent ways — corpus + handler disasm):

  * 0x30F Jump          fixed, ptr@+1, operand=2 words  (OPARGS=1 -> leaks hi)
  * 0x30C ConditionalJump fixed, ptr@+2, operand=3 words [flag,lo,hi] (OPARGS=2 -> leaks)
  * 0x3E1 JumpTable     fixed 4-entry, ptr@+1,+3,+5,+7, operand=8 words (OPARGS=0 -> leaks)
  * 0x313 Choice        variable: rows = (word1>>8)+1, each row=[param,lo,hi] (stride 3);
                        ScriptOp_Choice 0x08134900 lsrs r5,r1,#8 / adds r0,#1
  * 0x413 ResponseList  variable: rows = (word1>>8)+1, each row=[lo,hi] (stride 2);
                        ScriptOp_ResponseList 0x081386DC adds r7,r0,#1
  Everything else: OPARGS already bundles its pointer hi-word (0x30B/0x30E/0x360.. etc.)
  or carries no pointer. This tool VALIDATES that claim by walking the whole story bank
  and asserting zero residual optail leaks + full pointer-site coverage; any additional
  fixed leaker surfaces automatically in the residual report.

Run:  python -m text.script.tools.build_opcode_spec [--write]
      (--write emits opcode_spec.json + text/review/opcode-interior-targets.csv;
       without it, validation only.)
"""
import json
import sys
from collections import Counter, defaultdict
from pathlib import Path

try:
    from text.script.tools._boot import CONFIG, REVIEW, ROM as ROM_PATH
except ModuleNotFoundError:
    from _boot import CONFIG, REVIEW, ROM as ROM_PATH

from text.script import tr  # noqa: E402  GLYPH_MAP + codec

ROM = ROM_PATH.read_bytes()
B = 0x08000000
LO, HI = 0x08016000, 0x080A8C00            # story_vm bank (sections.py story params)
SKIP = ((0x08032DE0, 0x08035BB4), (0x080A548C, 0x080A96CC))
PHL, PHH = 0x0801, 0x080B                  # story-bank pointer high halves (the leak class)
GLYPH = tr.GLYPH_MAP
OPLO, OPHI = 0x0300, 0x0470
CTRL0 = {0x0300, 0x0316, 0x0317}           # {n}/{WAIT}/{PAGE}: 0-operand, never an op-blob
TERMS = (0x0301, 0x0000)
MIN_GLYPHS = 3                             # sections.py story min_glyphs (keep-gate)

OPARGS = {int(k, 16): (v if v is not None else 0)
          for k, v in json.loads((CONFIG / "opcode_args.json").read_text()).items()}

# --- proven structural corrections (operand WORDS, excluding the opcode word) --------
FIXED_OVERRIDE = {0x30F: 2, 0x30C: 3, 0x3E1: 8,
                  # rare conditional-branch ops the OPARGS tracker under-counted by the hi-word
                  # (handler-confirmed): 0x356 ScriptOp_CheckAlignmentRange [range,lo,hi];
                  # 0x359 jump-if-demon-not-in-party [id,lo,hi]; 0x33D 3-branch shop setup
                  0x356: 3, 0x359: 3, 0x33D: 7}
#                op    -> (fixed_prefix_words, count_word_idx, row_stride, row_ptr_offsets)
VARIABLE = {0x313: (1, 0, 3, (1,)),        # [count/default], rows of (param, lo, hi)
            0x413: (1, 0, 2, (0,))}        # [count/default], rows of (lo, hi)

# --- wrap / draw metadata (from docs/event-vm.md) -----------------------------------
# line_reset: the line accumulator resets (the runtime draws the continuation on a fresh
# line) — control-transfer jumps + {WAIT}. page_reset: the page glyph budget resets.
LINE_RESET = {0x30C, 0x30D, 0x30E, 0x30F, 0x313, 0x316, 0x3E1, 0x410, 0x411, 0x413}
PAGE_RESET = {0x317, 0x310}
# deferred to P1.5 (undocumented window-reset class — recorded, not yet wired into wrap)
WINDOW_RESET_MAYBE = {0x308, 0x310, 0x408, 0x458}
NAME_SUB = {0x31A, 0x31B, 0x31C, 0x31D, 0x31E, 0x31F, 0x320, 0x321, 0x322,
            0x323, 0x324, 0x325, 0x327, 0x328, 0x329, 0x32E, 0x32F, 0x36E}


def u16(a):
    return ROM[a - B] | (ROM[a - B + 1] << 8)


def in_skip(a):
    return any(lo <= a < hi for lo, hi in SKIP)


def is_ptr_at(o):
    h = u16(o + 2)
    if not (PHL <= h <= PHH):
        return None
    t = (h << 16) | u16(o)
    return t if (LO <= t < HI and not (t & 1)) else None


def oplen_words(op, addr, corrected):
    if corrected and op in VARIABLE:
        fixed, cwi, stride, _ro = VARIABLE[op]
        cnt = (u16(addr + 2 + 2 * cwi) >> 8) + 1
        return fixed + cnt * stride
    if corrected and op in FIXED_OVERRIDE:
        return FIXED_OVERRIDE[op]
    return OPARGS.get(op, 0)


def walk(corrected):
    """Mirror extract_story_vm with the spec-driven operand length. Returns
    (leak_total, residual_by_op, covered_ptr_lo_addrs, ptrmask_by_op, glyph_pos).

    A LEAK is an optail-class glyph (0x0801..080B) captured as text *immediately after
    an op blob* — scriptrefs's exact `optail` definition. Those same kanji (近金吟銀…)
    occur in genuine prose too (preceded by a glyph), where they are NOT leaks."""
    leaks = Counter()
    leak_total = 0
    covered = set()
    glyph_pos = set()                     # addrs captured as prose glyphs (ptr-site exclusion)
    ptrmask = defaultdict(Counter)        # op -> Counter(operand_word_offset that held a ptr-lo)
    a = LO
    while a < HI:
        sk = next((thi for tlo, thi in SKIP if tlo <= a < thi), None)
        if sk is not None:
            a = sk
            continue
        c = u16(a)
        while PHL <= c <= PHH and u16(a - 2) not in TERMS and a + 2 < HI:
            a += 2
            c = u16(a)
        if c in GLYPH and not (OPLO <= c <= OPHI):
            prev_op = None                # opcode of the previous captured token, if it was an op
            glyphs = kana = 0             # extract_story_vm keep-gate: >=MIN_GLYPHS and has kana
            pend_leak = []                # (op,) leaks pending this message's keep decision
            pend_glyph = []               # candidate prose-glyph addrs (commit iff kept)
            while a < HI:                  # capture one message
                c = u16(a)
                if c in TERMS:
                    a += 2
                    break
                if OPLO <= c <= OPHI and c not in CTRL0:
                    w = oplen_words(c, a, corrected)
                    for k in range(1, w + 1):
                        if is_ptr_at(a + 2 * k):
                            ptrmask[c][k] += 1
                            covered.add(a + 2 * k)
                    a += 2 + 2 * w
                    prev_op = c
                elif c in CTRL0:
                    a += 2
                    prev_op = None
                elif c == 0x11FE:
                    a += 2
                elif c in GLYPH:
                    nxt = u16(a + 2)
                    prose_cont = nxt in GLYPH and not (OPLO <= nxt <= OPHI)
                    if PHL <= c <= PHH and prev_op is not None and not prose_cont:
                        # an optail-range kanji right after an op blob, NOT continuing into
                        # readable prose = an under-captured operand high-word (a real leak).
                        # (A leaked pointer-hi never forms a multi-kanji run like 金剛神界.)
                        pend_leak.append(prev_op)
                    else:
                        pend_glyph.append(a)             # genuine prose glyph
                        glyphs += 1
                        ch = GLYPH[c]
                        if any("ぁ" <= k <= "ん" or "ァ" <= k <= "ヶ" for k in ch):
                            kana += 1
                    a += 2
                    prev_op = None
                else:
                    break
            if glyphs >= MIN_GLYPHS and kana:            # message is KEPT -> commit its leaks/glyphs
                for op in pend_leak:
                    leaks[op] += 1
                    leak_total += 1
                glyph_pos.update(pend_glyph)
        elif OPLO <= c <= OPHI and c not in CTRL0:
            w = oplen_words(c, a, corrected)
            for k in range(1, w + 1):
                if is_ptr_at(a + 2 * k):
                    ptrmask[c][k] += 1
                    covered.add(a + 2 * k)
            a += 2 + 2 * w
        else:
            a += 2
    return leak_total, leaks, covered, ptrmask, glyph_pos


def all_ptr_sites():
    out = []
    a = LO
    while a < HI - 2:
        if in_skip(a):
            a += 2
            continue
        t = is_ptr_at(a)
        if t is not None:
            out.append((a, t))
        a += 2
    return out


def main():
    write = "--write" in sys.argv
    sites = all_ptr_sites()
    site_lo = {a for a, _t in sites}
    print(f"story bank {LO:08X}..{HI:08X}   pointer sites: {len(sites)}")

    lt0, _l0, cov0, _m0, gp0 = walk(False)
    lt1, res1, cov1, mask1, gp1 = walk(True)
    # TRUE pointer sites exclude those whose lo-word is a captured prose glyph (the
    # 近金吟銀… kanji collide with pointer high-halves) — scriptrefs's glyph_pos filter.
    true0 = {a for a in site_lo if a not in gp0}
    true1 = {a for a in site_lo if a not in gp1}
    print(f"\n  PLAIN OPARGS  : optail leaks={lt0:<5d}  true sites consumed={sum(s in cov0 for s in true0)}/{len(true0)}")
    print(f"  CORRECTED SPEC: optail leaks={lt1:<5d}  true sites consumed={sum(s in cov1 for s in true1)}/{len(true1)}")
    if lt1:
        print("\n  !! RESIDUAL LEAKS — under-counted op that emitted the leaked hi-word:")
        for op, c in res1.most_common(20):
            print(f"       op 0x{op:03X} (OPARGS={OPARGS.get(op)}): x{c}")
        print("  (add to FIXED_OVERRIDE/VARIABLE and re-run)")
    else:
        print("\n  ✓ zero residual leaks under the corrected spec")

    # ---- assemble the spec ----------------------------------------------------------
    spec = {}
    for op in range(OPLO, OPHI + 1):
        oparg = OPARGS.get(op, 0)
        ent = {"len": oparg, "ptr": [], "var": None,
               "ink": op in NAME_SUB, "rec": 8 if op in NAME_SUB else 0,
               "line_reset": op in LINE_RESET, "page_reset": op in PAGE_RESET}
        if op in VARIABLE:
            fixed, cwi, stride, ro = VARIABLE[op]
            ent["len"] = fixed
            ent["var"] = {"count_word": cwi, "stride": stride, "row_ptr": list(ro)}
        elif op in FIXED_OVERRIDE:
            ent["len"] = FIXED_OVERRIDE[op]
        # empirically-derived pointer-word offsets (slots that held an in-bank ptr-lo)
        if op in mask1 and mask1[op]:
            tot = max(mask1[op].values())
            ptrs = sorted(k for k, c in mask1[op].items() if c >= tot * 0.5)
            if op in VARIABLE:
                # variable ops: top-level ptr lists only fixed-prefix pointers; the per-row
                # pointer lives in var.row_ptr (the offsets repeat per row, count-driven).
                ptrs = [k for k in ptrs if k <= ent["len"]]
            ent["ptr"] = ptrs
        spec[f"{op:03X}"] = ent

    # ---- interior-mid-pointer-target report (landmine #4) ---------------------------
    hi_word_addrs = {a + 2 for a, _t in sites}       # addresses of pointer HIGH words
    interior_on_hi = sorted((a, t) for a, t in sites if t in hi_word_addrs)
    print(f"\n  interior-mid-pointer landmine: {len(interior_on_hi)} branch target(s) land on a pointer HIGH word")
    for a, t in interior_on_hi[:10]:
        print(f"       site @{a:08X} -> target {t:08X} (== hi-word of another pointer)")

    if write:
        out = CONFIG / "opcode_spec.json"
        out.write_text(json.dumps(spec, indent=0), encoding="utf-8")
        print(f"\n  wrote {out}  ({len(spec)} opcodes)")
        rep = REVIEW / "opcode-interior-targets.csv"
        rep.parent.mkdir(parents=True, exist_ok=True)
        lines = ["site_addr,target_addr,note"]
        lines += [f"{a:08X},{t:08X},target-on-pointer-high-word" for a, t in interior_on_hi]
        rep.write_text("\n".join(lines) + "\n", encoding="utf-8")
        print(f"  wrote {rep}  ({len(interior_on_hi)} rows)")
    else:
        print("\n  (validation only — pass --write to emit opcode_spec.json + the report)")


if __name__ == "__main__":
    sys.stdout.reconfigure(encoding="utf-8")
    main()
