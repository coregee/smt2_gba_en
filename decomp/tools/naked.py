#!/usr/bin/env python3
"""Print the original instructions of a function as a NAKED C body, for functions whose C does
not match yet:

    #ifdef NONMATCHING
    ...readable C...
    #else
    NAKED void Func(...) { asm_unified("..."); }
    #endif

    python tools/naked.py 0x080E2F64 [...]
"""
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
import disasm  # noqa: E402
from symbols import Symbols  # noqa: E402

ROOT = Path(__file__).resolve().parents[1]


def body(addrs):
    rom = (ROOT / "baserom.gba").read_bytes()
    trace = json.loads((ROOT / "build" / "trace.json").read_text())
    m = disasm.Model(rom, trace, Symbols.load(ROOT / "reference" / "symbols.tsv"))
    texts = disasm.Texts()
    em = disasm.Emitter(m, texts)
    items = set()
    for a in addrs:
        f = m.funcs[a]
        for i, n in f["insns"]:
            if not em.flow(i, n, f["mode"]):
                items.add((f["mode"], rom[i - 0x08000000:i - 0x08000000 + n]))
    disasm.verify_texts(texts, items, disasm.find_tool("arm-none-eabi-as"))
    targets = em.branch_targets()
    out = []
    for a in addrs:
        f = m.funcs[a]
        hi = (f["end"] + 3) & ~3
        lines = disasm.emit_code_file(None, a, hi, m, em, targets)
        keep = [ln for ln in lines
                if ln.strip() and not ln.lstrip().startswith((".include", ".syntax", ".text",
                                                               ".balign", "thumb_func_start",
                                                               ".thumb"))
                and not ln.startswith(f"{m.fname(a)}:")]
        name = m.fname(a)
        out.append(f"// {name} @ 0x{a:08X}")
        out.append(f"NAKED void {name}(void)\n{{\n    asm_unified(")
        for ln in keep:
            ln = ln.replace("\t", "    ").replace('"', '\\"')
            out.append(f'        "{ln}\\n"')
        out.append("    );\n}\n")
    return "\n".join(out)


if __name__ == "__main__":
    print(body([int(x, 16) for x in sys.argv[1:]]))
