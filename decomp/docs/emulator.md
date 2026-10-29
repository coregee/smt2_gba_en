# Run-time checks with mGBA

`tools/emu/gdbdrive.py` runs a ROM in mGBA (installed with
`winget install JeffreyPfau.mGBA`) through its GDB server and probes it while it plays.
Use the Qt build (`mGBA.exe -g`); the SDL build's `-g` opens no GDB server.

```sh
python tools/emu/gdbdrive.py <rom> <workdir>            # starts mGBA, waits for commands
python tools/emu/send.py <workdir> run=600 keys=A every=24
python tools/emu/send.py <workdir> run=20 keys=DOWN every=20 shot=menu
```

- **Input** is injected deterministically: a breakpoint right after `Keys_Read` loads
  `REG_KEYINPUT` (`0x080A9A0A`) overwrites the loaded value, so a command holds keys on every
  frame (`every=1`) or taps them once every `every` frames.
- **Screenshots** (`shot=name`) capture the mGBA window to `<workdir>/name.png`.
- **Probes** log to `<workdir>/events.log`: the glyph sprite cache's full path
  (`Font_CacheGlyphSprite` `0x080AC134`, with caller and cache contents), the cache's
  count/capacity high-water mark every 30 frames, and every write to the cache capacity.
  Add breakpoints (`Z0`) or write watchpoints (`Z2`) in `main()` for other checks.
- **Memory**: `peek=ADDR:LEN` (hex, after any run) and `poke=ADDR:HEXBYTES` (before any run).
- **Reaching a scene** without playing to it: while any dialogue is running, poke the
  script's address into `gScriptJumpTarget` (`0x030068E4`, little-endian); `ScriptVM_Run`
  jumps there at the top of its loop. Use the translation's copy of the script (find it by
  its opcode bytes in the English ROM; most scenes are relocated to `0x088xxxxx`), or the
  original Japanese text shows. Shops also need a shop id in `0x03006914`
  (`gUnknown_0878EFB8` rows) and money at `0x03005198`.

Field controls observed: UP moves forward, B opens the field command menu, A on a dialogue
choice takes the highlighted entry. The game saves to `<rom>.sav` next to the ROM, so use a
scratch copy of the ROM.
