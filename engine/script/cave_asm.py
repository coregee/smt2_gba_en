#!/usr/bin/env python3
"""Assemble a Thumb code cave with a trailing literal pool, fixing up pc-relative loads.

keystone encodes instructions but won't manage a literal pool for us, and the cave's
length isn't known until assembled — so hardcoding `ldr [pc,#off]` offsets is fragile
(a 2-byte size change silently breaks every load). `assemble()` instead finds the
`ldr Rd,[pc,#x]` instructions (encoding 0x48xx) in order, appends `literals` 4-aligned
after the code, and rewrites each load's offset to point at the k-th literal. The asm's
own placeholder offsets are ignored; just list `literals` in the same order the loads
appear.
"""
import struct
from keystone import Ks, KS_ARCH_ARM, KS_MODE_THUMB
from capstone import Cs, CS_ARCH_ARM, CS_MODE_THUMB

_ks = Ks(KS_ARCH_ARM, KS_MODE_THUMB)
_md = Cs(CS_ARCH_ARM, CS_MODE_THUMB)


def _assert_thumb1(code, cave_addr):
    """The GBA CPU is ARM7TDMI (ARMv4T) — Thumb-1 only. keystone will happily emit
    Thumb-2 (`add.w`, `mov.w`, …) which is 4 bytes and *undefined* on hardware, decoding
    as garbage. Reject any 4-byte instruction that isn't a real bl/blx.

    ALSO reject 16-bit hi-register-format ADD/CMP/MOV with BOTH registers low
    (H1=H2=0 — encodings 0x44xx/0x45xx/0x46xx with bits 7:6 == 00).  keystone emits
    these later-architecture forms for `mov rlow, rlow` / `add rlow, rlow`; they are
    architecturally UNPREDICTABLE on ARM7TDMI and empirically misexecute on real GBA
    silicon (3DS AGB) and the MiSTer core while mGBA runs them leniently — the root
    cause of the 2026-07 hardware-only status-screen/race-name corruption (and, via
    patch_racesub's cell-pointer add, the whole battle-lockup saga).  Write the T1
    forms instead: `adds rd, rm, #0` (mov), `adds rd, rd, rm` (add), plain `cmp`."""
    pos = 0
    for ins in _md.disasm(bytes(code), cave_addr):
        if ins.size != 2 and not ins.mnemonic.startswith(("bl", "blx")):
            raise SystemExit(
                f"Thumb-2 instruction not runnable on ARM7TDMI: "
                f"'{ins.mnemonic} {ins.op_str}' ({ins.size}B) — rewrite it as Thumb-1")
        if ins.size == 2:
            hw = int.from_bytes(code[pos:pos + 2], "little")
            if (hw & 0xFC00) == 0x4400 and (hw >> 8) & 3 != 3 and (hw >> 6) & 3 == 0:
                raise SystemExit(
                    f"ARMv4T-UNPREDICTABLE encoding 0x{hw:04X} at +0x{pos:X} "
                    f"('{ins.mnemonic} {ins.op_str}': hi-register form, both regs low) — "
                    f"misexecutes on real GBA hardware. Use adds rd, rm, #0 / "
                    f"adds rd, rd, rm (T1 forms) instead")
        pos += ins.size
    if pos != len(code):
        raise SystemExit("cave failed to fully disassemble as Thumb")


def assemble(asm, cave_addr, literals):
    if cave_addr % 4:
        raise SystemExit(f"cave @0x{cave_addr:08X} not 4-byte aligned: its `ldr [pc]` literal pool "
                         "would be read rotated on ARM7TDMI")
    code = bytearray(_ks.asm(asm, cave_addr)[0])
    _assert_thumb1(code, cave_addr)
    ldrs = [i for i in range(0, len(code) - 1, 2)
            if (int.from_bytes(code[i:i + 2], "little") & 0xF800) == 0x4800]
    if len(ldrs) != len(literals):
        raise SystemExit(f"expected {len(literals)} ldr-pc loads, found {len(ldrs)}")
    while len(code) % 4:
        code += b"\x00"
    base = len(code)
    code += b"".join(struct.pack("<I", v) for v in literals)
    for k, pos in enumerate(ldrs):
        off = (base + 4 * k) - ((pos + 4) & ~3)
        if not (0 <= off < 1024 and off % 4 == 0):
            raise SystemExit(f"ldr-pc #{k} offset {off} out of range")
        hw = (int.from_bytes(code[pos:pos + 2], "little") & 0xFF00) | (off // 4)
        code[pos:pos + 2] = hw.to_bytes(2, "little")
    return bytes(code)


def thumb_bl(src, dst):
    code = bytes(_ks.asm(f"bl #{dst}", src)[0])
    assert len(code) == 4, "bl must encode to 4 bytes"
    return code
