#!/usr/bin/env python3
"""Derive the event-VM opcode argument table by static analysis of each handler.

The text/event VM (dispatcher at 0x0813db8c) reads a u16 code at the script PC:
  index = code - 0x300; if index > 0x170 -> draw glyph; else call table[index].
The jump table is at 0x087913dc (0x171 u32 Thumb handler pointers). The dispatcher
advances the PC past the opcode word, then the handler reads its own ARG words from
the script stream, advancing `g_wScriptPc` (a u16 word-index at 0x0203db40, base
0x03006950) by the number of args it consumes.

So: arg_count(opcode) = how far its handler bumps g_wScriptPc. We extract that with
a tiny symbolic Thumb tracker: find the register holding the g_wScriptPc pointer
(0x0203db40 in the literal pool), watch ldrh/strh to it, and take the max offset
written back relative to the value first read. Validated against hand-disassembly.
"""
import json
import sys
from pathlib import Path

try:
    from text.script.tools._boot import CONFIG, ROM as ROM_PATH
except ModuleNotFoundError:
    from _boot import CONFIG, ROM as ROM_PATH

ROM = ROM_PATH.read_bytes()
ROM_BASE = 0x08000000
JUMP_TBL = 0x087913dc
N_OPCODES = 0x171
G_SCRIPTPC = 0x0203DB40   # the u16 word-index the handlers advance


def u16(off): return int.from_bytes(ROM[off:off + 2], "little")
def u32(off): return int.from_bytes(ROM[off:off + 4], "little")


def handler_arg_count(func_addr: int, max_insns: int = 220) -> int | None:
    """Symbolically execute a handler's Thumb code; return arg words consumed."""
    if func_addr == 0 or not (ROM_BASE <= func_addr < ROM_BASE + len(ROM)):
        return None
    # reg state: None=unknown, ('ptr',)=holds &g_wScriptPc, ('pc',k)=pc_index+k
    reg = [None] * 16
    args = 0
    saw_ptr = False
    pc = func_addr - ROM_BASE
    for _ in range(max_insns):
        ins = u16(pc)
        nxt = pc + 2
        # ldr Rd,[pc,#imm]  (0100 1ddd iiiiiiii)  -> literal load
        if (ins & 0xF800) == 0x4800:
            rd = (ins >> 8) & 7
            imm = (ins & 0xFF) * 4
            lit = ((pc + 4) & ~3) + imm
            val = u32(lit)
            reg[rd] = ("ptr",) if val == G_SCRIPTPC else None
        # ldrh Rd,[Rb,#imm5] (1000 1iiiii bbb ddd)
        elif (ins & 0xF800) == 0x8800:
            rb = (ins >> 3) & 7
            rd = ins & 7
            imm = ((ins >> 6) & 0x1F)
            if reg[rb] == ("ptr",) and imm == 0:
                reg[rd] = ("pc", 0)
            else:
                reg[rd] = None
        # strh Rd,[Rb,#imm5] (1000 0iiiii bbb ddd)
        elif (ins & 0xF800) == 0x8000:
            rb = (ins >> 3) & 7
            rd = ins & 7
            imm = ((ins >> 6) & 0x1F)
            if reg[rb] == ("ptr",) and imm == 0 and reg[rd] and reg[rd][0] == "pc":
                saw_ptr = True
                args = max(args, reg[rd][1])
        # adds Rd,#imm8 (00110 ddd iiiiiiii)
        elif (ins & 0xF800) == 0x3000:
            rd = (ins >> 8) & 7
            imm = ins & 0xFF
            if reg[rd] and reg[rd][0] == "pc":
                reg[rd] = ("pc", reg[rd][1] + imm)
        # adds Rd,Rn,#imm3 (0001110 iii nnn ddd)
        elif (ins & 0xFE00) == 0x1C00:
            imm = (ins >> 6) & 7
            rn = (ins >> 3) & 7
            rd = ins & 7
            if reg[rn] and reg[rn][0] == "pc":
                reg[rd] = ("pc", reg[rn][1] + imm)
            elif imm == 0:
                reg[rd] = reg[rn]
            else:
                reg[rd] = None
        # mov/cpy Rd,Rs (0001 1100 0 ... ) handled above as add #0; also
        # mov Rd,Rm hi-reg (0100 0110 DMmmmddd)
        elif (ins & 0xFF00) == 0x4600:
            rd = ((ins >> 4) & 8) | (ins & 7)
            rm = (ins >> 3) & 0xF
            reg[rd] = reg[rm]
        # movs Rd,#imm8 (00100 ddd iiiiiiii)
        elif (ins & 0xF800) == 0x2000:
            rd = (ins >> 8) & 7
            reg[rd] = None
        # pop {..,pc} (1011 1101 ...) or bx Rm (0100 0111 0mmmm000) -> return.
        # Handlers tail-return via `pop {r0}; bx r0`, not always `bx lr`.
        elif (ins & 0xFF00) == 0xBD00:
            break
        elif (ins & 0xFF87) == 0x4700:   # bx Rm (any register)
            break
        # bl/blx (prefix 1111 0...) is two halfwords -> skip the pair (call helper)
        elif (ins & 0xF800) == 0xF000:
            nxt = pc + 4
        pc = nxt
    return args if saw_ptr else 0


def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")
    table = {}
    for i in range(N_OPCODES):
        op = 0x300 + i
        h = u32(JUMP_TBL - ROM_BASE + i * 4) & ~1
        table[op] = handler_arg_count(h)

    # validate against hand-verified counts
    known = {0x303: 1, 0x304: 3, 0x305: 1, 0x307: 1, 0x308: 1, 0x309: 1,
             0x30A: 1, 0x30B: 2, 0x30C: 1, 0x30D: 2, 0x30E: 2, 0x310: 1,
             0x311: 1, 0x312: 1, 0x316: 0}
    ok = bad = 0
    for op, want in known.items():
        got = table[op]
        flag = "OK" if got == want else f"MISMATCH want {want}"
        if got == want:
            ok += 1
        else:
            bad += 1
            print(f"  {op:03X}: got {got}  {flag}")
    print(f"validation: {ok}/{len(known)} match" + (" — all good" if not bad else ""))

    out = CONFIG / "opcode_args.json"
    out.write_text(json.dumps({f"{k:03X}": v for k, v in table.items()}, indent=0))
    from collections import Counter
    dist = Counter(table.values())
    print(f"wrote {out}")
    print("arg-count distribution:", dict(sorted(dist.items(), key=lambda x: (x[0] is None, x[0]))))


if __name__ == "__main__":
    raise SystemExit(main())
