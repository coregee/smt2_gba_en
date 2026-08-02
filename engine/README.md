# Runtime patch engine

`script/` owns the GBA-specific ROM patch registry, guarded byte writes, code-cave allocator,
Thumb assembler, native cave compiler, and the C sources compiled into the ROM. Shared cartridge
and RAM addresses are owned by the root `rom_layout.py` module.

The public build remains:

```sh
python build.py --profile full
python build.py --profile full --check
```

`script/build_rom.py` may also be run directly for engine development. Font and graphics helpers
share the repository path model through `script/_boot.py`.

`script/cave_cc.py` generates `rommap.h` in its isolated compiler directory for every native cave.
Do not check in a second copy beside the C sources: quoted local includes would shadow the generated
header and allow its constants to drift.
