"""One-off (2026-06-11): for each battle-string code literal found by
scan_battle_literals.py, locate the Thumb `ldr rN, [pc, #imm]` that loads it and
disassemble forward to see where the pointer goes (safe = a BL to the template
expander FUN_080ebca4, which expands {=2403}/{=2003} subs; raw copy loops = unsafe
to repoint)."""
import struct
import capstone

try:
    from ._boot import ROM
except ImportError:
    from _boot import ROM

rom = ROM.read_bytes()
BASE = 0x08000000
EXPANDER = 0x080EBCA4

# literal slots from scan_battle_literals.py, excluding the 0x086BED5C fragment table
# and the two 0x0877xxxx data tables (no code around them to disassemble)
SLOTS = [0x80ec410, 0x8165250, 0x8165298, 0x80f3638, 0x80f3708, 0x80f3468,
         0x812a820, 0x812b514, 0x812b594, 0x812bf50, 0x812b088, 0x812b100,
         0x812c3b4, 0x812b874, 0x812cad8, 0x812ee24, 0x80b14a0, 0x80b158c,
         0x812c148, 0x812c178, 0x812c744, 0x812c6b0, 0x812c6c8,
         0x80ec85c, 0x80ec874, 0x80ec4a0, 0x80e9118]

md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB)
md.detail = False


def find_ldr(slot):
    """Find Thumb `ldr rN, [pc, #imm]` instructions targeting this literal slot."""
    out = []
    for a in range(max(BASE, slot - 0x420), slot, 2):
        hw = struct.unpack_from("<H", rom, a - BASE)[0]
        if 0x4800 <= hw <= 0x4FFF:                      # ldr rN, [pc, #imm8*4]
            imm = (hw & 0xFF) * 4
            if ((a + 4) & ~3) + imm == slot:
                out.append((a, (hw >> 8) & 7))
    return out


for slot in SLOTS:
    val = struct.unpack_from("<I", rom, slot - BASE)[0]
    ldrs = find_ldr(slot)
    if not ldrs:
        print(f"slot {slot:08X} -> {val:08X}: NO ldr found (data table?)")
        continue
    for a, reg in ldrs:
        # disassemble the next 12 instructions, note BL targets
        code = rom[a - BASE:a - BASE + 40]
        txt, bls = [], []
        for insn in md.disasm(bytes(code), a):
            txt.append(f"{insn.address:08x} {insn.mnemonic} {insn.op_str}")
            if insn.mnemonic == "bl":
                bls.append(int(insn.op_str.lstrip("#"), 16))
            if len(txt) >= 8:
                break
        safe = "SAFE(expander)" if EXPANDER in bls else "CHECK"
        print(f"slot {slot:08X} -> {val:08X}: ldr r{reg} @{a:08x} {safe}")
        if EXPANDER not in bls:
            for t in txt:
                print("   ", t)
