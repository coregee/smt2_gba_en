# Archived text investigations

These are **investigation scripts** that each chased a single problem to its conclusion.
Their findings have since been baked into the permanent pipeline (the `Section` manifest in
`text/script/sections.py`, the translation JSONs, or the coverage audit), so they are no longer part
of the active build/extract surface. Kept here (not deleted) because they document *how* a
result was reached and are occasionally worth re-running if a related area is revisited. Historical
They remain available as direct modules under `text.script.archive`.

None of these are imported by the build or canonical maintained tools (verified).

| Script | What it did (one-off) | Result is now in |
| --- | --- | --- |
| `scan_battle_literals.py` | found 90 battle-template pointer refs outside `BATTLE_MSG_TABLE` | `Section.extra_refs` (sections.py) |
| `verify_literal_consumers.py` | capstone-classified those literals SAFE/CHECK | the frozen slot lists in sections.py |
| `scan_sentinel_refs.py` | proved 37 `system_menu` entries are reference-less | the `system_menu` route split |
| `trace_help_consumers.py` | traced help-pointer arrays to `SetMode(4, …)` | the `literal_ptr`/`extra_refs` routing |
| `scan_battlelog_refs.py` | classified refs of untranslated `system_battle_log` lines | (backlog cleared) |
| `inspect_savemsgs.py` | decoded the save-screen message cluster | the `save_screen` Section |
| `fill_savescreen.py` | wrote the initial EN for save_screen + config_help | `save_screen.json` / `config_help.json` |
| `fill_locnames.py` | wrote the initial EN for the location-name table | `location_names.json` (520/520) |
| `inspect_locnames.py` | probed the `0x080A548C` location table (pad/count/end) | the `location_names` Section spec |
| `verify_locnames.py` | checked built-ROM location cells against the JSON | (build-time invariant; fold into the coverage audit if wanted) |

The `fill_*` scripts are preserved as provenance, not maintained migration commands. Do not run
them against the current corpus: they can overwrite later hand-edits, and `fill_locnames.py` also
depends on an untracked historical review input.
