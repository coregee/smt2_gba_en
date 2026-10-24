# Ghidra

Ghidra's ARM auto-analysis guesses between ARM and Thumb from byte patterns and gets GBA code
wrong. Here it never guesses: `tools/ghidra/SetupFromTrace.java` builds the program from
`tools/trace.py`'s output. It sets the `TMode` context per instruction, disassembles exactly
the traced instructions without flow-following, creates every function with its name, marks
agbcc far jumps (`bl` used as a branch) as `BRANCH` flow overrides and no-return calls, and
adds switch-table references. `ApplySignatures.java` then applies argument counts and void /
value returns inferred by `tools/signatures.py` (without it, agbcc's `pop {r0}; bx r0`
epilogue makes every function "return" `lr`) and I/O register labels.
`ExportDecomp.java` writes `reference/ghidra-c/<file>.c` beside each `asm/<file>.s`.

## Running it

The project is `ghidra/SMT2.gpr` (local only). Regenerate the inputs, then run headless:

```sh
python tools/signatures.py
python tools/ghidra_input.py
analyzeHeadless ghidra SMT2 -import baserom.gba -overwrite -processor ARM:LE:32:v4t \
    -loader BinaryLoader -loader-baseAddr 0x08000000 -noanalysis -scriptPath tools/ghidra \
    -postScript SetupFromTrace.java build/ghidra_input.tsv \
    -postScript ApplySignatures.java build/signatures.tsv build/ghidra_labels.tsv \
    -postScript ExportDecomp.java layout.json reference/ghidra-c
```

`build/ghidra_labels.tsv` is the I/O register list from `tools/gbaregs.py`
(one `address<TAB>name` per line). The whole run takes about 25 minutes, mostly disassembly.

**Installed Ghidra in `C:\Program Files`:** its ARM `.sinc` files are a few milliseconds
newer than the compiled `.sla` files, so Ghidra tries to recompile the language and fails
because Program Files is read-only ("language probably did not compile properly"). Either
run Ghidra once as administrator so it can rewrite the `.sla` files, or run headless from a
copy of the install in a writable folder (a copy without the other processors and docs is
about 850 MB).

Only one process should own `ghidra/SMT2.gpr` at a time. The running Ghidra GUI instance used
by the Nocturne project is unrelated and is not touched.
