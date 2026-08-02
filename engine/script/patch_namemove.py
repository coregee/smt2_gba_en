#!/usr/bin/env python3
"""Movable [name] for the battle action fragments (battlefrag.json).

The three plain-fragment builders assemble  <actor name (cap 8, trailing-0x70 trim)> + <fragment>
with the name ALWAYS first — fine for Japanese (ピクシーを倒した) but English often wants the
name elsewhere ("Defeated Pixie", "Put Pixie to sleep").  tr.pack encodes a non-leading [name]
in battlefrag.json as a 0xFFFE sentinel inside the rebuilt fragment; this patch replaces each
builder's name+fragment copy section with one cave that assembles
    prefix + name + suffix      (0xFFFE present — moved name)
    name + fragment             (no sentinel — JP fragments / leading-[name] English)
so untranslated fragments behave byte-identically to the original code.

Hooked builders (verified plain copies, docs/battle-message-window.md "battlefrag builders"):
  Battle_BuildStatusResultText   0x080EB16C  frag = ACTION_TABLE[(combatant+0x5c byte) - 0x40]
                                             (status は/を pairs, skill-result strings)
  Battle_BuildCombatActionList   0x080EB220  frag = (ACTION_TABLE+0x200)[idx]   (verbs 0xC0-C5)
  Battle_BuildDefeatedTargetText 0x080EB570  frag = [0x080EB5EC] literal (を倒した)
  Battle_BuildActorPrompt        0x080EAD80  frag = [0x080EAE04] literal (はどうしますか) — the
                                             per-turn command prompt "What will [name] do?"

Each hook starts at the point where both name paths converge (rX = name ptr: player =
Combatant_DecodeName buffer, demon = patch_battlename's cave -> 1-token EN marker), resolves
the fragment pointer exactly like the original code (reusing the function's own pc-literal,
which tr.pack auto-repoints to the rebuilt English fragment), calls the cave, and branches to
the function's epilogue.  The status/defeated builders' demon-name `bl Combatant_GetRecord` +
`add r2,#0x22` are hooked by patch_battlename (SITES) — without those entries the cave would
splice the JP inline name.

Hook sites are 2-byte aligned mid-function, so code is assembled piecewise with keystone (the
pc-relative ldr is hand-encoded — keystone's literal syntax can't be trusted to hit an
EXISTING pool slot) and disasm-verified Thumb-1 like patch_battlewedge.
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

from keystone import Ks, KS_ARCH_ARM, KS_MODE_THUMB
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB
from engine.script.cave_asm import thumb_bl

_ks = Ks(KS_ARCH_ARM, KS_MODE_THUMB)
_md = Cs(CS_ARCH_ARM, CS_MODE_THUMB)

# The cave: r0 = buf cursor (line start — the engine's own name copy is part of the replaced
# region, so nothing is written yet), r1 = name ptr, r2 = fragment ptr; returns r0 = end cursor.
# No terminator is written (the dest buffers are CpuSet-zeroed by the builders' prologues).
CAVE_ASM = """
cave_entry:
    push {r4, lr}
    movs r4, #1
    lsls r4, r4, #16
    subs r4, #2              /* r4 = 0xFFFE moved-name sentinel */
    mov  ip, r2              /* fragment start */
scan:                        /* does this fragment carry a moved name? */
    ldrh r3, [r2]
    cmp  r3, r4
    beq  moved
    cmp  r3, #0
    beq  plain
    adds r2, #2
    b    scan
plain:                       /* original order: name first, then the whole fragment */
    mov  r2, ip
    bl   put_name
copy:
    ldrh r3, [r2]
    cmp  r3, #0
    beq  done
    strh r3, [r0]
    adds r0, #2
    adds r2, #2
    b    copy
moved:                       /* prefix + name (at the sentinel) + suffix */
    mov  r2, ip
mcopy:
    ldrh r3, [r2]
    cmp  r3, #0
    beq  done
    cmp  r3, r4
    beq  minsert
    strh r3, [r0]
    adds r0, #2
    adds r2, #2
    b    mcopy
minsert:
    bl   put_name
    adds r2, #2
    b    mcopy
done:
    pop  {r4, pc}

put_name:                    /* copy up to 8 name tokens (stop at 0), trim trailing 0x70 pad */
    push {r4}
    mov  ip, r0              /* name start in buf = trim floor (frag start no longer needed) */
    adds r4, r1, #0
    adds r4, #16             /* cap: 8 tokens */
pn_copy:
    cmp  r1, r4
    beq  pn_trim
    ldrh r3, [r1]
    cmp  r3, #0
    beq  pn_trim
    strh r3, [r0]
    adds r0, #2
    adds r1, #2
    b    pn_copy
pn_trim:
    mov  r3, ip
pn_t:
    cmp  r0, r3
    beq  pn_done
    subs r0, #2
    ldrh r4, [r0]
    cmp  r4, #0x70
    beq  pn_t
    adds r0, #2
pn_done:
    pop  {r4}
    bx   lr
"""


def _ldr_pc(rd, insn_addr, target):
    """Hand-encode `ldr rd, [pc, #off]` hitting an EXISTING 4-aligned literal slot."""
    off = target - ((insn_addr + 4) & ~3)
    if not (0 <= off < 1024 and off % 4 == 0):
        raise SystemExit(f"ldr-pc @0x{insn_addr:08X} -> 0x{target:08X}: offset {off} unencodable")
    return (0x4800 | (rd << 8) | (off // 4)).to_bytes(2, "little")


def _asm_at(text, addr):
    return bytes(_ks.asm(text, addr)[0])


# hook addr, original bytes (name copy preamble — guards against drift), code builder.
# Each builder fn gets (hook_addr, cave_addr) and returns the replacement bytes; the
# pc-relative ldr offsets are derived from real instruction positions, never guessed.
def _h_status(addr, cave):                       # Battle_BuildStatusResultText @0x080EB1C6
    c = _asm_at("adds r0, r4, #0; adds r1, r2, #0; movs r2, #0x5c; ldrb r2, [r5, r2]; "
                "subs r2, #0x40; lsls r2, r2, #2", addr)
    c += _ldr_pc(3, addr + len(c), 0x080EB1EC)   # r3 = ACTION_TABLE (fn's own literal)
    c += _asm_at("ldr r2, [r3, r2]", 0)
    c += thumb_bl(addr + len(c), cave)
    c += _asm_at(f"b #{0x080EB212}", addr + len(c))
    return c


def _h_action(addr, cave):                       # Battle_BuildCombatActionList @0x080EB27E
    c = _asm_at("adds r0, r4, #0; lsls r3, r6, #2", addr)   # r1 is already the name ptr
    c += _ldr_pc(2, addr + len(c), 0x080EB2A4)   # r2 = verb table (fn's own literal)
    c += _asm_at("ldr r2, [r2, r3]", 0)
    c += thumb_bl(addr + len(c), cave)
    c += _asm_at(f"b #{0x080EB2C4}", addr + len(c))
    return c


def _h_defeated(addr, cave):                     # Battle_BuildDefeatedTargetText @0x080EB5CA
    c = _asm_at("adds r0, r4, #0; adds r1, r2, #0", addr)
    c += _ldr_pc(2, addr + len(c), 0x080EB5EC)   # r2 = を倒した frag (repointed literal)
    c += thumb_bl(addr + len(c), cave)
    c += _asm_at(f"b #{0x080EB60A}", addr + len(c))
    return c


def _h_prompt(addr, cave):                       # Battle_BuildActorPrompt @0x080EADE2
    # Convergence point: r4 = dest cursor (CpuSet-zeroed), r2 = name ptr (human =
    # Combatant_DecodeName buffer; demon = record+0x22 EN marker via patch_battlename).
    # The fragment literal 0x080EAE04 sits mid-function (between code at 0x080EAE02 and
    # 0x080EAE08), so the 34-byte guard stops exactly before it and the cave reads the
    # (auto-repointed) literal directly.  Returns into the epilogue load r0 = buffer base.
    c = _asm_at("adds r0, r4, #0; adds r1, r2, #0", addr)   # r0 = dest cursor, r1 = name ptr
    c += _ldr_pc(2, addr + len(c), 0x080EAE04)   # r2 = はどうしますか frag (fn's own literal)
    c += thumb_bl(addr + len(c), cave)
    c += _asm_at(f"b #{0x080EAE22}", addr + len(c))   # -> epilogue (loads r0 = buffer base)
    return c


HOOKS = [
    (0x080EB1C6, "00201188084e2b1c5c3300290ed02180023202340130", _h_status),
    (0x080EB27E, "00200a88084db300002a0fd02280", _h_action),
    (0x080EB5CA, "00201188074b00290ed02180", _h_defeated),
    (0x080EADE2, "00201188074b00290ed021800232023401300006000e072806d811880029f4d102e0", _h_prompt),
]


def apply(p):
    cave = p.cave_asm(CAVE_ASM, name="namemove")
    for addr, old, build in HOOKS:
        code = build(addr, cave)
        for ins in _md.disasm(code, addr):       # ARM7TDMI runs Thumb-1 only
            if ins.size != 2 and not ins.mnemonic.startswith("bl"):
                raise SystemExit(f"namemove hook @{addr:08X}: Thumb-2 '{ins.mnemonic} {ins.op_str}'")
        if len(code) > len(bytes.fromhex(old)):
            raise SystemExit(f"namemove hook @{addr:08X}: {len(code)}B > {len(old) // 2}B original")
        code += b"\xc0\x46" * ((len(bytes.fromhex(old)) - len(code)) // 2)   # NOP-pad to the guard span
        p.patch(addr, old, code, name=f"namemove@{addr:08X}")
