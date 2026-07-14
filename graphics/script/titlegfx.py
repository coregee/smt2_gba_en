#!/usr/bin/env python3
"""Dump the title-screen / intro / game-over BAKED-TEXT graphics as editable PNGs.

These screens draw their text from tile bitmaps, not the text pipeline: the opening
narration crawl ("20XX-nen TOKYO ..."), the title screen (logo / PRESS ANY BUTTON /
menu labels), the intro attract-mode DDS-NET sheets, and Charon's game-over speech.
The title blocks are RLE nested inside LZ77 (BIOS SWI 0x11 then 0x14) — that's why
they look like noise in the plain sprites.py dump, and why sprites.py skipped them
(they live inside its demon-sprite skip region).  Asset registry + codecs:
graphics/script/gbagfx.py.

  dump    : decode every registered asset into graphics/assets/<name>.png
            (16-colour indexed, greyscale placeholder palette — the pixel INDICES are
            the data, exactly like sprites.py).  Existing PNGs are NOT overwritten
            (they hold your edits) unless --force.  Pristine copies always go to
            graphics/assets/originals/ for side-by-side reference.
  test    : round-trip every asset through the RLE+LZ77 encoders and re-decode;
            asserts byte-identical raw tiles.

Repack happens in the ROM build: engine/script/patch_titlegfx.py re-encodes
any edited PNG into rom/smt2-en.gba (in place when it fits its slot, relocated to
FARDATA_TITLEGFX with literal-pool repoints when it doesn't).

Editing rules: keep the PNG indexed (16 colours max); keep the canvas size; text can
move freely WITHIN a sheet (the on-screen tilemap is unchanged, and these sheets are
laid out in visual order), but pixels must stay meaningful at their tile position.
"""
import argparse
from PIL import Image

try:
    from graphics.script._boot import ASSETS as GFXDIR, ROM as BASE
except ModuleNotFoundError:
    from _boot import ASSETS as GFXDIR, ROM as BASE

from graphics.script import gbagfx  # noqa: E402

PALETTE = bytes(b for i in range(16) for b in (i * 17, i * 17, i * 17))


def save_png(path, raw, width):
    img = gbagfx.tiles_to_image(raw, width)
    png = Image.frombytes("P", (img.shape[1], img.shape[0]), img.tobytes())
    png.putpalette(PALETTE)
    path.parent.mkdir(parents=True, exist_ok=True)
    png.save(path)


def cmd_dump(force):
    rom = BASE.read_bytes()
    for asset in gbagfx.ASSETS:
        raw, sizes, slots = gbagfx.decode_asset(rom, asset)
        save_png(GFXDIR / "originals" / f"{asset['name']}.png", raw, asset["width"])
        dest = GFXDIR / f"{asset['name']}.png"
        wrote = force or not dest.exists()
        if wrote:
            save_png(dest, raw, asset["width"])
        blocks = "+".join(f"{a:08X}" for a in asset["blocks"])
        print(f"{asset['name']:14s} {blocks}  {len(raw):#7x} raw / {sum(slots):#6x} slot "
              f"({asset['wrap']})  {'written' if wrote else 'kept (edited?)'}")
    print(f"\n-> edit graphics/assets/<name>.png (originals/ = pristine reference); "
          f"the ROM build injects any PNG that differs from the original.")


def cmd_test():
    rom = BASE.read_bytes()
    for asset in gbagfx.ASSETS:
        raw, sizes, slots = gbagfx.decode_asset(rom, asset)
        off = 0
        for addr, size, slot in zip(asset["blocks"], sizes, slots):
            part = raw[off:off + size]; off += size
            enc = gbagfx.encode_block(part, asset["wrap"])
            dec = gbagfx.lz77_decompress(enc, 0)[0]
            if asset["wrap"] == "lz77+rle":
                dec = gbagfx.rl_decompress(dec)
            assert dec == part, f"{asset['name']} @{addr:08X}: round-trip mismatch"
            fit = "fits" if len(enc) <= slot else "RELOCATES"
            print(f"{asset['name']:14s} {addr:08X}: re-encoded {len(enc):#6x} vs slot {slot:#6x} ({fit})")
        # PNG round-trip too
        img = gbagfx.tiles_to_image(raw, asset["width"])
        back = gbagfx.image_to_tiles(img, asset["width"], len(raw) // 32)
        assert back == raw, f"{asset['name']}: PNG grid round-trip mismatch"
    print("ALL OK")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    pd = sub.add_parser("dump"); pd.add_argument("--force", action="store_true",
                                                 help="overwrite existing (edited) PNGs")
    sub.add_parser("test")
    a = ap.parse_args()
    if a.cmd == "dump":
        cmd_dump(a.force)
    else:
        cmd_test()


if __name__ == "__main__":
    main()
