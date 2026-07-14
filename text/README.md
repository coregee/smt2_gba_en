# Text

`corpus/` contains the 42 editable translation JSON files. `script/sections.py` is their single
registry, and `script/tr.py` owns decoding, extraction, validation, and packing.

Run from the repository root:

```sh
python text/script/tr.py extract
python -m text.script.tools.audit_field_schema
python build.py --profile full --check
```

`config/` owns event-VM opcode metadata, `review/` owns semantic QA data and maintained audit
report snapshots, and
`script/tools/` contains maintained audits, migration helpers, dump renderers, and pack
comparators. `generated/readable/` contains reproducible text views, while `reference/` keeps
saved external English sources separate from their parsed JSON. Concluded investigations live in
`script/archive/` and are excluded from the build.

Additional commands:

```sh
python -m text.script.tools.render_dumps --section story
python -m text.reference.script.parse_wiki
```
