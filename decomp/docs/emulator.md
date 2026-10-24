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

Field controls observed: UP moves forward, B opens the field command menu, A on a dialogue
choice takes the highlighted entry. The game saves to `<rom>.sav` next to the ROM, so use a
scratch copy of the ROM.
