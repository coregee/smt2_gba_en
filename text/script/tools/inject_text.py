#!/usr/bin/env python3
"""Overwrite a message in the ROM with English text (for in-game font testing).

Encodes an ASCII string to the game's u16 glyph codes (ASCII letters/digits from
the map, authored punctuation from custom_glyphs, space -> 0x00BC) and writes it
in place + a 0x0000 terminator, refusing to exceed the original message's byte
span. Patches rom/smt2-en-font.gba (which already has the injected font) so the
result has both the font and the test text.

Usage:
    python text/script/tools/inject_text.py            # default: load-screen test
    python text/script/tools/inject_text.py 0x08123E22 "Load OK! 123?" 28
"""
import sys
from pathlib import Path

try:
    from text.script.tools._boot import PATHS
except ModuleNotFoundError:
    from _boot import PATHS

from font.atlas import GLYPH_MAP, character_codes  # noqa: E402

ROM_IN = PATHS.build_path("smt2-en-font.gba")
ROM_BASE = 0x08000000

CHAR2CODE = character_codes()


def encode(text: str, fill_to: int | None = None) -> bytes:
    """Encode text to u16 codes. fill_to=None -> append a 0x0000 terminator;
    fill_to=N -> pad with spaces to exactly N bytes (for mid-message in-place
    replacement that must flow into a following [WAIT]/opcode, no terminator)."""
    out = bytearray()
    for ch in text:
        code = CHAR2CODE.get(ch)
        if code is None:
            raise SystemExit(f"no glyph for {ch!r} — add it to custom_glyphs.py")
        out += code.to_bytes(2, "little")
    if fill_to is None:
        out += b"\x00\x00"
    else:
        while len(out) < fill_to:
            out += CHAR2CODE[" "].to_bytes(2, "little")
    return bytes(out)


def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")
    args = [a for a in sys.argv[1:] if a != "--fill"]
    fill = "--fill" in sys.argv
    addr = int(args[0], 16) if len(args) > 0 else 0x08123E22
    text = args[1] if len(args) > 1 else "Load OK! 123?"
    budget = int(args[2]) if len(args) > 2 else 28   # original span in bytes

    blob = encode(text, fill_to=budget if fill else None)
    if len(blob) > budget:
        raise SystemExit(f"{len(blob)} bytes > {budget}-byte budget; shorten the text or repoint.")

    rom = bytearray(ROM_IN.read_bytes())
    off = addr - ROM_BASE
    rom[off:off + len(blob)] = blob
    ROM_IN.write_bytes(rom)

    # verify: decode it back with the runtime map
    codes = [int.from_bytes(blob[i:i + 2], "little") for i in range(0, len(blob), 2)]
    codes = [c for c in codes if c != 0]          # drop terminator if present
    decoded = "".join(" " if c == 0x00BC else GLYPH_MAP.get(c, f"<{c:04X}>") for c in codes)
    print(f"injected at 0x{addr:08X}: {text!r}  ({len(blob)} bytes / {budget} budget)")
    print(f"  codes: {' '.join(f'{c:04X}' for c in codes)}")
    print(f"  round-trip decode: {decoded!r}")
    print(f"wrote {ROM_IN}")


if __name__ == "__main__":
    raise SystemExit(main())
