#!/usr/bin/env python3
"""Event/dialogue repointer — registers the runtime opcode that lets English dialog exceed the Japanese.

Story messages are INLINE event-VM bytecode (glyphs interleaved with opcodes, terminated by 0x0301), so
growing one in place would shift every following byte and break all jump targets.  Instead we add a
custom VM opcode 0x0350 ("expanded text", cave_dialog.c) in an unused handler-table slot: at a message's
head the script becomes `[0x0350, ptr]`, and the cave JUMPS the VM into the pooled English at `ptr`
(base=ptr, pc=0).  That string's own 0x0301 ends the message exactly as the original would, so the byte
layout — and every jump — is untouched.  See rom_layout.py (SCRIPT_*).

This module only REGISTERS the opcode (cave + handler-table slot).  The per-message repointing is done by
tr.pack: any translated story.json line that can't fit inline gets its head rewritten to `[0x0350, ptr]`
and the English pooled.  So translating story dialogue needs no code change — just set `replace`.
"""
try:
    from engine.script._boot import *
except ModuleNotFoundError:
    from _boot import *  # sys.path for sibling imports; ROOT, B, Path

from pathlib import Path
import rom_layout as rommap

SRC = Path(__file__).resolve().parent / "cave_dialog.c"
B = rommap.ROM_BASE


def apply(p):
    p.cave_c(SRC, name="dialog")
    fn = p.cave_c_syms["cave_entry"]
    # register the expanded-text handler for opcode 0x0350 (table slot 0x50, currently the nop handler)
    slot = rommap.SCRIPT_OP_TABLE + (rommap.SCRIPT_EXPAND_CODE - 0x300) * 4
    p.patch(slot, "b5211308", (fn | 1).to_bytes(4, "little"), name="dlg-op-0350")
