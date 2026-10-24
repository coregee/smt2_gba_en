# SMT2 GBA translation

This repository contains the English translation source, text and graphics assets, font pipeline,
and GBA runtime patches. Place an unmodified Japanese ROM at
`rom/Shin Megami Tensei II (Japan).gba`. Built ROMs and intermediates are written to `rom/`; that
directory is intentionally excluded from Git.

## Build

### Dependencies

Use Python 3.11 or newer and install the Python dependencies from `requirements.txt`
(dependency installation and unit tests have been verified on Python 3.14).
A project-local virtual environment avoids conflicts with unrelated installed packages.
From the repository root on Windows (PowerShell):

```powershell
python -m venv .venv
.\.venv\Scripts\python.exe -m pip install -r requirements.txt
.\.venv\Scripts\python.exe build.py --profile full --check
.\.venv\Scripts\python.exe build.py --profile full
```

On Linux/macOS:

```sh
python3 -m venv .venv
. .venv/bin/activate
python -m pip install -r requirements.txt
```

The native C patches also require an ARM bare-metal GCC toolchain, including
`arm-none-eabi-gcc`, `arm-none-eabi-objcopy`, and `arm-none-eabi-nm`.
Install devkitARM through [devkitPro](https://devkitpro.org/wiki/Getting_Started)
or the [Arm GNU Toolchain](https://learn.arm.com/install-guides/gcc/arm-gnu/), and add
its `bin` directory to `PATH`. The build also checks
`C:/msys64/opt/devkitpro/devkitARM/bin` on Windows. These compiler tools are not
installed by pip.

On Windows, the toolchain can be installed with Windows Package Manager:

```powershell
winget install --id Arm.GnuArmEmbeddedToolchain --exact --source winget
```

Open a new terminal after installation, then check `arm-none-eabi-gcc --version`
before running the build. If the compiler is not found, add the installed toolchain's
`bin` directory to `PATH` (for version 14.2.Rel1, the default is
`C:\Program Files (x86)\Arm GNU Toolchain arm-none-eabi\14.2 rel1\bin`).
The full build and `--check` have been verified on Windows with Python 3.14 and
Arm GNU Toolchain 14.2.Rel1; both produced the same ROM hash.

If an existing environment reports `ImportError: cannot import name 'Ks' from 'keystone'`,
it may contain OpenStack's unrelated `keystone` package. The assembler's distribution is
[`keystone-engine`](https://github.com/keystone-engine/keystone/blob/master/bindings/python/README.md),
although its Python import is `keystone`. Prefer the clean virtual environment above.
To repair an environment where the OpenStack package was installed by mistake, run these
commands with that environment's Python:

```sh
python -m pip uninstall keystone
python -m pip install --force-reinstall keystone-engine==0.9.2
python -m pip install -r requirements.txt
```

### Build commands

Run from the repository root:

```sh
python build.py --profile full
python build.py --profile full --check
python build.py --profile diagnostic
python build.py --list-profiles
```

Use the virtual environment's Python for these commands (on Windows,
`.\.venv\Scripts\python.exe`), or activate the environment first.

`--check` assembles every hook and cave, packs the complete corpus, and reports the final hash
without writing build artifacts. The diagnostic profile writes `rom/smt2-en-diagnostic.gba`, so
hardware-test hooks cannot replace the normal translated ROM accidentally.

The normal build writes `rom/smt2-en.gba`; its pre-pack intermediate is
`rom/smt2-en-font.gba`.

## Layout

- `rom_layout.py` is the neutral source of truth for shared ROM/RAM addresses and C header defines.
- `text/` owns the editable corpus, codec, section registry, audits, and reference material.
- `font/` owns the curated glyph atlas, declarative font configs, source faces, codecs, and repacker.
- `graphics/` owns editable baked-text assets and their codecs.
- `engine/` owns ROM patches, code caves, and the final ROM assembly pipeline.
- `rom/` is the local-only input/output directory.

`text` and `engine` are sibling domains. Both may depend on `rom_layout.py`; text packing must not
reach through the engine package for cartridge-layout constants.

## Validation

```sh
python -B -m unittest discover -v
python -B -m text.script.tools.audit_field_schema
python -B graphics/script/titlegfx.py test
python -B -m text.script.tools.verify_cave_layout --quick
python -B build.py --profile full --check
```

The unit suite includes architecture checks for the neutral layout boundary and the generated
native-cave header. The full build check remains the byte-level release gate.
