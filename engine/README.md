# Runtime patch engine

`script/` owns the GBA-specific ROM patch registry, guarded byte writes, code-cave allocator,
Thumb assembler, native cave compiler, and the C/header sources compiled into the ROM.

The public build remains:

```sh
python build.py --profile full
python build.py --profile full --check
```

`script/build_rom.py` may also be run directly for engine development. Font and graphics helpers
share the repository path model through `script/_boot.py`.
