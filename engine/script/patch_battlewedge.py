#!/usr/bin/env python3
"""Battle 'wedge' rewrite — natural English word order for the item-used / skill-cast battle-log lines.

Battle_BuildCombatSkillList, FUN_080eaf1c and Battle_BuildItemActionList each build the line as
  name + frag[0] + {n} + name2 + frag[1:]   (the item/skill name2 wedged between two halves of the
fragment), so a fragment swap alone can only reach passive "Hiroko\nDia was cast".  We replace each
function's wedge section with a call to one cave (cave_battlewedge.c) that builds
  name + prefix + name2 + suffix   from a "prefix 0xFFFF suffix" fragment (tr.pack assembles those
from battlefrag.json's "[name]{n}used [item]." templates — the {n} after the name is the
template's own, no longer cave-hardcoded), giving natural "Hiroko\ncast Dia."

The fragment pointer is still whatever each function loaded from its own literal (tr.pack repoints those
to the English fragment via battlefrag.json), so the hook just forwards the register.  Each hook overwrites
14 bytes at the start of the wedge with `mov r0=buf,r1=frag,r2=arg,r3=mode; bl cave; b tail` — the rest of
the old wedge code is left in place but unreachable (the `b tail` jumps over it).  Wedge sites are 2-byte
aligned, so the hook is assembled with keystone directly (cave_asm.assemble is for 4-aligned caves).
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

from pathlib import Path
from keystone import Ks, KS_ARCH_ARM, KS_MODE_THUMB
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB

SRC = Path(__file__).resolve().parent / "cave_battlewedge.c"
_ks = Ks(KS_ARCH_ARM, KS_MODE_THUMB)
_md = Cs(CS_ARCH_ARM, CS_MODE_THUMB)

# wedge_addr, original 14 bytes, register setup (-> r0=buf, r1=frag, r2=arg, r3=mode), tail addr.
#   CombatSkillList @080eae30: buf=r5 frag=r3 arg=r6(combatant)  mode0  FUN_080eaf1c: buf=r5 frag=r2
#   arg=r7(action) mode1   ItemActionList @080eb080: buf=r5 frag=r3 arg=r6(combatant) mode2
HOOKS = [
    (0x080EAEC2, "1c1c2088288002340235c0218900", "mov r1,r3; mov r0,r5; mov r2,r6; movs r3,#0", 0x080EAF0C),
    (0x080EAFAE, "141c2088288002340235c0218900", "mov r1,r2; mov r0,r5; mov r2,r7; movs r3,#1", 0x080EAFF8),
    (0x080EB112, "1c1c2088288002340235c0218900", "mov r1,r3; mov r0,r5; mov r2,r6; movs r3,#2", 0x080EB15E),
]


def apply(p):
    p.cave_c(SRC, name="battlewedge")
    cave = p.cave_c_syms["cave_entry"]
    for addr, old, setup, tail in HOOKS:
        code = bytes(_ks.asm(f"{setup}; bl #{cave}; b #{tail}", addr)[0])
        # reject any Thumb-2 keystone might emit (ARM7TDMI runs Thumb-1 only); bl is a real 2-halfword op
        for ins in _md.disasm(code, addr):
            if ins.size != 2 and not ins.mnemonic.startswith("bl"):
                raise SystemExit(f"wedge hook @{addr:08X}: Thumb-2 '{ins.mnemonic} {ins.op_str}'")
        if len(code) != len(bytes.fromhex(old)):
            raise SystemExit(f"wedge hook @{addr:08X}: {len(code)}B != {len(old) // 2}B original")
        p.patch(addr, old, code, name=f"wedge@{addr:08X}")
