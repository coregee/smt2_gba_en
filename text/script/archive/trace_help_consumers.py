"""One-off: disassemble around the menu help-pointer-array consumers to see whether
the fetched help string goes through BattleMenu_SetMode 0x080EA37C (sentinel hook)."""
import struct
import capstone

try:
    from ._boot import ROM
except ImportError:
    from _boot import ROM

rom = ROM.read_bytes()
BASE = 0x08000000
SETMODE = 0x080EA37C
EXPANDER = 0x080EBCA4

LITS = [0x8128cf8, 0x8128d48, 0x812d23c, 0x812d2ec, 0x812ae78, 0x812af28,
        0x812a918, 0x812a9dc, 0x8129200]

md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB)


def find_ldr(slot):
    out = []
    for a in range(max(BASE, slot - 0x420), slot, 2):
        hw = struct.unpack_from("<H", rom, a - BASE)[0]
        if 0x4800 <= hw <= 0x4FFF and ((a + 4) & ~3) + (hw & 0xFF) * 4 == slot:
            out.append(a)
    return out


for slot in LITS:
    for a in find_ldr(slot):
        code = rom[a - BASE:a - BASE + 80]
        lines, verdict = [], []
        for insn in md.disasm(bytes(code), a):
            lines.append(f"{insn.address:08x} {insn.mnemonic} {insn.op_str}")
            if insn.mnemonic == "bl":
                t = int(insn.op_str.lstrip("#"), 16)
                verdict.append(f"SETMODE" if t == SETMODE else
                               ("EXPANDER" if t == EXPANDER else f"bl_{t:08x}"))
            if len(lines) >= 16:
                break
        print(f"\n=== lit @{slot:08X} ldr @{a:08x}  calls: {verdict}")
        for t in lines:
            print("   ", t)
