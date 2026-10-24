#!/usr/bin/env python3
"""Which strings reach the battle message buffers, and do they fit?  (translation check)

The battle message window (src/btext_*.c) keeps three u16[64] buffers back to back at
0x0203C9EC (text), 0x0203CA6C (text2) and 0x0203CAEC (compose), followed by the auto-close
fields and the window/task pointers.  The composers write `compose` without a bound;
BattleMenu_SetMode modes 4/8/9 copy into text/text2 without a bound.

This tool runs the translation build in memory (like audit_patches.py), finds every call to
a composer or to BattleMenu_SetMode* in the original code and in the translation's caves,
resolves the string argument statically in the PATCHED ROM (literal, table entry, or every
entry of a table indexed at run time), and computes the worst-case length of what lands in
the buffer: template glyphs plus 8 per inserted name and 8 per inserted number (demon and
item names that the translation turns into 1-glyph markers count as 1).

Output: build/battle-text-budget.txt; summary on stdout.
"""
from __future__ import annotations

import json
import struct
import sys
from collections import defaultdict
from pathlib import Path

import capstone

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import audit_patches  # noqa: E402

BASE = 0x08000000
SENT_NAME, SENT_VALUE = 0xFFFE, 0xFFFF
BUF = 64                      # u16 per buffer, terminator included

# function -> (template argument index, names inserted, numbers inserted, destination)
# "names" counts names the composer itself inserts around the template; markers handled
# separately.  Index "lit" = the composer loads its template from its own literal pool.
COMPOSERS = {
    0x080EAA08: ("MessageBox_ComposeRaceNameText", 1, 1, 0, "compose"),
    0x080EAAB0: ("MessageBox_ComposeNameText", 1, 1, 0, "compose"),
    0x080EAB3C: ("MessageBox_ComposeTwoNamesText", 2, 2, 0, "compose"),
    0x080EAC0C: ("MessageBox_ComposeSpeciesText", 4, 2, 2, "compose"),
    0x080EB2D4: ("Battle_BuildNamePrependText", 1, 1, 0, "compose"),
    0x080EB37C: ("Battle_BuildNamePrefixText", 1, 1, 0, "compose"),
    0x080EB71C: ("Battle_BuildActorStatusText", 1, 1, 0, "compose"),
    0x080EB454: ("Battle_BuildDamageDealtText", 2, 1, 1, "compose"),
    0x080EB810: ("sub_080EB810", 1, 1, 0, "compose"),
    0x080EB8DC: ("Battle_BuildRaceCountText", 2, 1, 1, "compose"),
    0x080EB9EC: ("Battle_BuildRewardText", 2, 1, 1, "compose"),
    0x080EBB20: ("Battle_BuildValueRewardText", 1, 0, 1, "compose"),
    0x080EBBF0: ("Battle_BuildItemDropText", 1, 1, 0, "compose"),
    0x080EBCA4: ("Menu_ExpandListTemplate", 0, 0, 0, "compose"),
    0x080EBED4: ("MessageBox_ComposeWrappedText", 0, 0, 0, "compose"),
    0x080EA37C: ("BattleMenu_SetMode", 1, 0, 0, "mode"),
    0x080EA4F8: ("BattleMenu_SetModeAutoClose", 1, 0, 0, "mode"),
}
# Composers whose template is a literal of their own (no template argument).
SELF_LITERAL = {
    0x080EAD80: ("Battle_BuildActorPrompt", 1, 0),
    0x080EB080: ("Battle_BuildActorActionText", 1, 0),
    0x080EAE30: ("sub_080EAE30", 2, 0),
    0x080EAF1C: ("sub_080EAF1C", 2, 0),
    0x080EB008: ("sub_080EB008", 1, 0),
    0x080EB16C: ("Battle_BuildStatusResultText", 1, 0),
    0x080EB220: ("Battle_BuildCombatActionList", 1, 0),
    0x080EB570: ("Battle_BuildDefeatedTargetText", 1, 0),
    0x080EB618: ("Battle_BuildDodgeText", 1, 0),
}
# Functions that return an entry of a string table: function -> address of the literal that
# holds the table pointer (read from the patched ROM, in case the translation repoints it).
GETTERS = {
    0x080EC038: 0x080EC044,      # battle message table: return gUnknown_0876FB54[id]
}
# Functions that return a record pointer: function -> (record base, stride, count).  A string
# loaded from a field of such a record is "that field of any record".
RECORD_GETTERS = {
    0x080BF418: (0x08198EB4, 32, 256),   # Action_GetRecord: 32-byte action/item records
    0x080BF5C0: (0x0819B9F4, 28, 160),   # 28-byte records up to the demon records at 0x0819CB74
}
# Template codes Menu_ExpandListTemplate (and the VM) replaces by a name or number.
EXPAND_NAME = set(range(0x31A, 0x330)) | {0x36E}


def u16s(rom, a, limit=400):
    out = []
    o = a - BASE
    while 0 <= o < len(rom) - 1 and len(out) < limit:
        v = rom[o] | rom[o + 1] << 8
        out.append(v)
        if v == 0:
            break
        o += 2
    return out


def is_text_ptr(rom, v):
    if not (BASE <= v < BASE + len(rom)) or v & 1:
        return False
    s = u16s(rom, v, 300)
    return bool(s) and len(s) > 1 and (s[-1] == 0 or 0x301 in s)


def expand_table(rom, t, allow_null=False, limit=512):
    """If t is a table of string pointers (at least two), return them all.  With allow_null,
    NULL entries are skipped (id-indexed tables with unused ids)."""
    out = []
    k = 0
    while k < limit and BASE <= t + 4 * k + 4 <= BASE + len(rom):
        v = struct.unpack_from("<I", rom, t + 4 * k - BASE)[0]
        if allow_null and v == 0:
            k += 1
            continue
        if not is_text_ptr(rom, v):
            break
        out.append(v)
        k += 1
    return out if len(out) >= 2 else []


STOP_301 = {"Menu_ExpandListTemplate", "MessageBox_ComposeSpeciesText", "typed"}


EXPAND_LEN = {                 # Menu_ExpandListTemplate, translated build (src/btext_list.c)
    0x31A: 8, 0x31B: 8, 0x31C: 8, 0x31D: 8, 0x31E: 8, 0x325: 8, 0x324: 8,   # combatant names
    0x320: 16,                 # party leader + "'s party" (patch_partyname)
    0x321: 15,                 # English item name, streamed with cap 15 (patch_battleitemname)
    0x316: 0, 0x317: 0,        # dropped
}
HANG = {0x31F, 0x322, 0x323, 0x326, 0x327, 0x328, 0x329}   # never advance: infinite loop


def measure_expand(rom, a):
    """Exact worst case for Menu_ExpandListTemplate: (total incl. terminator, note, error)."""
    s = u16s(rom, a, 400)
    total = 0
    for v in s:
        if v == 0x301:
            return total + 1, "", None
        if v in HANG:
            return total, "", f"contains code 0x{v:03X}, which Menu_ExpandListTemplate never " \
                              f"skips: the game hangs"
        total += EXPAND_LEN.get(v, 1)
    return total, "", "no 0x301 terminator: the expander runs past the end of the string"


def measure(rom, a, names_inserted, numbers_inserted, marker_names, stop301=False, typed=False):
    """Worst-case glyphs written (terminator included) for template at a."""
    s = u16s(rom, a)
    if stop301 and 0x301 in s:
        s = s[:s.index(0x301)] + [0]
    if not s or s[-1] != 0:
        return None, "no terminator within 400 glyphs"
    glyphs = 0
    names = numbers = 0
    for v in s[:-1]:
        if v == SENT_NAME:
            names += 1
        elif v == SENT_VALUE:
            numbers += 1
        elif v in EXPAND_NAME:
            names += 1
        elif v == 0x315 and typed:
            continue                          # pause token: the typewriter does not store it
        else:
            glyphs += 1
    if not names and not numbers:
        names, numbers = names_inserted, numbers_inserted
    per_name = 1 if marker_names else 8
    total = glyphs + names * per_name + numbers * 8 + 1
    return total, f"{glyphs} glyphs + {names} name(s) x{per_name} + {numbers} number(s) x8 + 0"


def main():
    base = (ROOT / "baserom.gba").read_bytes()
    new, caves, hooks = audit_patches.translated_rom()
    trace = json.loads((ROOT / "build" / "trace.json").read_text())
    syms = {}
    for ln in (ROOT / "reference" / "symbols.tsv").read_text(encoding="utf-8").splitlines()[1:]:
        f = ln.split("\t")
        syms[int(f[0], 16)] = f[1]
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB)
    md.detail = True
    u32 = lambda a: struct.unpack_from("<I", new, a - BASE)[0]

    # Code to scan: every original Thumb function (patched bytes) and every cave.
    regions = []
    for f in trace["functions"]:
        if f["mode"] == "thumb" and not f["other_mode"]:
            regions.append((f["addr"], f["end"], syms.get(f["addr"], f"sub_{f['addr']:08X}")))
    for a, s, n in caves:
        regions.append((a, a + s, f"cave:{n}"))

    # Hooks that turned `bl Builder` into `bl cave`: the cave takes the builder's arguments and
    # writes the same compose buffer (cave_resultmsg's build()), so measure it the same way.
    for lo_, hi_, owner_ in regions:
        if owner_.startswith("cave:"):
            continue
        for site in range(lo_, hi_ - 3, 2):
            o_ = site - BASE
            if (base[o_ + 1] >> 3) != 0b11110 or (new[o_ + 1] >> 3) != 0b11110:
                continue
            if base[o_:o_ + 4] == new[o_:o_ + 4]:
                continue
            def bl_target(rom):
                h1 = rom[o_] | rom[o_ + 1] << 8
                h2 = rom[o_ + 2] | rom[o_ + 3] << 8
                off = ((h1 & 0x7FF) << 12) | ((h2 & 0x7FF) << 1)
                off -= 0x800000 if off & 0x400000 else 0
                return site + 4 + off
            old_t, new_t = bl_target(base), bl_target(new)
            if old_t in COMPOSERS and new_t not in COMPOSERS:
                COMPOSERS[new_t] = (f"cave for {COMPOSERS[old_t][0]}",) + COMPOSERS[old_t][1:]
            elif old_t in SELF_LITERAL and new_t not in SELF_LITERAL:
                SELF_LITERAL[new_t] = SELF_LITERAL[old_t]

    # English string -> the Japanese string at the same place (table index / literal), to tell
    # translation-introduced problems from properties of the original data.
    en_to_jp = {}
    for g, lit in GETTERS.items():
        tn, tb = u32(lit), struct.unpack_from("<I", base, lit - BASE)[0]
        for k in range(4096):
            if tn + 4 * k + 4 > BASE + len(new) or tb + 4 * k + 4 > BASE + len(base):
                break
            en_to_jp.setdefault(u32(tn + 4 * k), struct.unpack_from("<I", base, tb + 4 * k - BASE)[0])
    for iteration in range(8):            # wrappers found in one pass become composers
        new_wrappers = {}
        rows = []
        errors = set()
        dead = []
        unresolved = defaultdict(int)
        for lo, hi, owner in regions:
            regs = {i: ("param", i, lo) for i in range(4)}
            a = lo
            while a < hi - 1:
                o = a - BASE
                n = 4 if (new[o + 1] >> 3) == 0b11110 else 2
                ins = next(md.disasm(new[o:o + n], a), None)
                if ins is None:
                    a += 2
                    regs = {}
                    continue
                h = new[o] | new[o + 1] << 8
                m = ins.mnemonic
                if h >> 11 == 0b01001:                                # ldr rd, [pc, #x]
                    lit = ((a + 4) & ~3) + (h & 0xFF) * 4
                    if lit < BASE + len(new) - 3:
                        regs[(h >> 8) & 7] = ("val", u32(lit))
                elif m == "bl":
                    tgt = ins.operands[0].imm
                    spec = COMPOSERS.get(tgt)
                    if spec:
                        name, argi, nn, nv, dest = spec[:5]
                        r = regs.get(argi) if argi < 4 else regs.get(("sp", 0))
                        cands = []
                        if r and r[0] == "val":
                            cands = expand_table(new, r[1]) or [r[1]]
                        elif r and r[0] == "table":
                            cands = expand_table(new, r[1], allow_null=True)
                        elif r and r[0] == "compose":
                            cands = []                         # composer output, measured there
                        elif r and r[0] == "ret" and r[1] in GETTERS:
                            cands = expand_table(new, u32(GETTERS[r[1]]), allow_null=True, limit=4096)
                        elif r and r[0] == "recfield":
                            _, rbase, stride, count, disp = r
                            cands = []
                            for i in range(count):
                                ea = rbase + i * stride + disp
                                if is_text_ptr(new, u32(ea)):
                                    cands.append(u32(ea))
                                    en_to_jp.setdefault(u32(ea), struct.unpack_from(
                                        "<I", base, ea - BASE)[0])
                        elif r and r[0] == "param" and not owner.startswith("cave:"):
                            if r[2] not in COMPOSERS:
                                fixed = regs.get(0)
                                fm = fixed[1] if fixed and fixed[0] == "val" else None
                                new_wrappers[r[2]] = (owner, r[1], nn, nv, dest, fm)
                            r = ("wrapper",)
                        elif r and r[0] == "ret":
                            unresolved[(owner, f"{name} <- {syms.get(r[1], f'sub_{r[1]:08X}')}()")] += 1
                        if not cands and not (r and r[0] in ("compose", "ret", "wrapper", "param")) and \
                                not (r and r[0] == "val" and r[1] == 0):
                            unresolved[(owner, name)] += 1
                        mode = regs.get(0, ("?",))
                        for c in cands:
                            if not is_text_ptr(new, c):
                                continue
                            if dest == "mode":
                                md_ = mode[1] if mode[0] == "val" else (spec[5] if len(spec) > 5 else None)
                                if c == 0x0203CAEC:
                                    continue                           # compose -> counted at the composer
                                tot, how = measure(new, c, 0, 0, True, stop301=md_ in (3, 7), typed=md_ in (3, 7))
                                buf = {4: "text", 9: "text", 8: "text2"}.get(md_)
                                # text/text2 overflow first spills into the next buffer (garbled
                                # display); only past compose does it reach the pointers.
                                limit = BUF
                                rows.append((owner, a, name + (f"(mode {md_})" if md_ is not None else ""),
                                             c, tot, how, buf or "typed (translation clamps at 63)", limit))
                            else:
                                if name == "Menu_ExpandListTemplate":
                                    tot, _, err = measure_expand(new, c)
                                    jp = en_to_jp.get(c)
                                    if err and jp is not None:
                                        en_codes = {v for v in u16s(new, c) if v in HANG}
                                        jp_codes = {v for v in u16s(base, jp) if v in HANG}
                                        jp_term = 0x301 in u16s(base, jp)
                                        if (en_codes and en_codes <= jp_codes) or \
                                                (not en_codes and not jp_term):
                                            err = None        # the Japanese entry has it too: this id
                                                              # is built by another composer
                                    if err:
                                        errors.add((name, c, err))
                                    rows.append((owner, a, name, c, tot, "exact expansion rules",
                                                 "compose", BUF, tot))
                                    continue
                                tot, how = measure(new, c, nn, nv, False, name in STOP_301)
                                tot_m, _ = measure(new, c, nn, nv, True, name in STOP_301)
                                rows.append((owner, a, name, c, tot, how, "compose", BUF, tot_m))
                    regs = {k: v for k, v in regs.items() if isinstance(k, int) and k > 3}
                    composed = (spec and spec[4] == "compose") or tgt in SELF_LITERAL
                    regs[0] = ("compose",) if composed else ("ret", tgt)
                    if tgt in RECORD_GETTERS:
                        regs[0] = ("rec",) + RECORD_GETTERS[tgt]
                elif m in ("adds", "movs") and len(ins.operands) >= 2:
                    rd = ins.operands[0]
                    if rd.type == capstone.arm.ARM_OP_REG and ins.reg_name(rd.reg).startswith("r"):
                        d = int(ins.reg_name(rd.reg)[1:])
                        src = ins.operands[1]
                        if m == "adds" and len(ins.operands) == 3 and ins.op_str.endswith("#0") and \
                                src.type == capstone.arm.ARM_OP_REG and ins.reg_name(src.reg)[1:].isdigit():
                            regs[d] = regs.get(int(ins.reg_name(src.reg)[1:]))
                        elif m == "adds" and len(ins.operands) == 3 and \
                                ins.operands[2].type == capstone.arm.ARM_OP_REG:
                            vals = [regs.get(int(ins.reg_name(x.reg)[1:])) for x in ins.operands[1:]
                                    if ins.reg_name(x.reg)[1:].isdigit()]
                            tb = next((v[1] for v in vals if v and v[0] in ("val", "table")
                                       and BASE <= v[1] < BASE + len(new)), None)
                            if tb is not None:
                                regs[d] = ("table", tb)
                            else:
                                regs.pop(d, None)
                        elif m == "movs" and src.type == capstone.arm.ARM_OP_IMM:
                            regs[d] = ("val", src.imm)
                        else:
                            regs.pop(d, None)
                elif m == "ldr" and "[r" in ins.op_str and "pc" not in ins.op_str:
                    d = int(ins.reg_name(ins.operands[0].reg)[1:]) if ins.reg_name(ins.operands[0].reg)[1:].isdigit() else None
                    mem = ins.operands[1].mem
                    b = ins.reg_name(mem.base)
                    rb = regs.get(int(b[1:])) if b[1:].isdigit() else None
                    if d is not None:
                        if rb and rb[0] == "rec" and mem.index == 0:
                            regs[d] = ("recfield",) + rb[1:] + (mem.disp,)
                        elif rb and rb[0] == "table" and mem.index == 0:
                            regs[d] = ("table", rb[1])
                        elif rb and rb[0] == "val" and mem.index == 0 and BASE <= rb[1] + mem.disp < BASE + len(new):
                            regs[d] = ("val", u32(rb[1] + mem.disp))
                        elif rb and rb[0] == "val" and mem.index != 0 and BASE <= rb[1] < BASE + len(new):
                            regs[d] = ("table", rb[1])
                        else:
                            idx = ins.reg_name(mem.index) if mem.index else ""
                            ri = regs.get(int(idx[1:])) if idx[1:].isdigit() else None
                            if ri and ri[0] == "val" and BASE <= ri[1] < BASE + len(new):
                                regs[d] = ("table", ri[1])
                            else:
                                regs.pop(d, None)
                elif m == "str" and "sp" in ins.op_str:
                    s_ = ins.reg_name(ins.operands[0].reg)
                    if s_[1:].isdigit() and ins.operands[1].mem.disp == 0:
                        regs[("sp", 0)] = regs.get(int(s_[1:]))
                else:
                    _, wr = ins.regs_access()
                    for w in wr:
                        nme = ins.reg_name(w)
                        if nme[1:].isdigit():
                            regs.pop(int(nme[1:]), None)
                if m in ("b", "bx", "pop") or (m.startswith("b") and len(m) == 3 and m != "bic") or \
                        m == "mov" and "pc" in ins.op_str:
                    regs = {k: v for k, v in regs.items() if not isinstance(k, int) or k > 7}
                a += n

        if not new_wrappers:
            break
        COMPOSERS.update(new_wrappers)

    # Self-literal composers: every string literal in their pool (patched ROM).
    for f in trace["functions"]:
        spec = SELF_LITERAL.get(f["addr"])
        if not spec:
            continue
        if f["origin"].startswith("unreferenced"):
            dead.append(spec[0])
            continue
        name, nn, nv = spec
        for l in f["literals"]:
            v = u32(l)
            for c in expand_table(new, v) or ([v] if is_text_ptr(new, v) else []):
                if c == 0x0203CAEC:
                    continue
                tot, how = measure(new, c, nn, nv, False)
                tot_m, _ = measure(new, c, nn, nv, True)
                rows.append((name, l, name + " (own literal)", c, tot, how, "compose", BUF, tot_m))

    out = ["battle text budget (worst case incl. terminator; limit 64 per buffer)", ""]
    over = []
    seen = set()
    for r in sorted(rows, key=lambda r: -(r[4] or 0)):
        key = (r[2], r[3])
        if key in seen:
            continue
        seen.add(key)
        owner, site, name, s_addr, tot, how, buf, limit = r[:8]
        tot_m = r[8] if len(r) > 8 else tot
        text = "".join(chr(v) if 0x20 <= v < 0x7F else "." for v in u16s(new, s_addr, 80)[:-1])
        flag = ""
        if limit and tot and tot > limit:
            flag = "OVER" if tot_m > limit else "over-if-8-glyph-names"
        line = (f"{flag:22s} {tot or 0:4d} (markers {tot_m or 0:3d}) / {limit or '-':>3} {buf:8s} "
                f"{name:34s} from {owner} @{site:08X}  str {s_addr:08X}  {how}")
        out.append(line)
        if flag:
            over.append(line)
    out.append("")
    out.append("errors (templates the composer cannot process safely):")
    for name, c, err in sorted(errors):
        out.append(f"  ERROR {name} str {c:08X}: {err}")
    out.append("")
    out.append("dead composers (no caller and no pointer anywhere; never run): " + ", ".join(dead))
    out.append("")
    out.append("unresolved string arguments (call sites whose string could not be determined):")
    for (owner, name), n in sorted(unresolved.items()):
        out.append(f"  {name:34s} from {owner} x{n}")
    (ROOT / "build" / "battle-text-budget.txt").write_text("\n".join(out) + "\n", encoding="utf-8")
    for name, c, err in sorted(errors):
        print(f"ERROR {name} str {c:08X}: {err}")
    print(f"{len(seen)} distinct (composer, string) pairs; {len(over)} can exceed their buffer; "
          f"{sum(unresolved.values())} unresolved call sites")
    for line in over[:40]:
        print(line)


if __name__ == "__main__":
    main()
