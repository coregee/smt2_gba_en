#!/usr/bin/env python3
"""SMT2's m4a (MusicPlayer2000) sound data as pret-style source.

    python tools/assets/m4a.py extract   ROM -> assets/sound/ (songs .s, voicegroups .s,
                                         samples .wav + .json, wave tables .bin, includes.json)
    python tools/assets/m4a.py build     samples .wav -> build/sound/samples/*.pcm (the signed
                                         8-bit data the sample .s files .incbin)
    python tools/assets/m4a.py check     build, then assemble every span at its ROM address
                                         and compare with baserom.gba
    python tools/assets/m4a.py midi      one-way MIDI export to assets/sound/midi/ (listening)

Layout (base ROM):
    0x0858BE94-0x0858D354  voicegroups (12-byte ToneData grid; drum kit, CGB wave tables)
    0x0858D354-0x0858E000  gMPlayTable, gSongTable (399 x {song, ms, me}), dummy song header
    0x0858E000-0x086B3878  DirectSound samples (three blocks)
    0x086B3878-0x086BE5xx  song track bytecode, each song's tracks followed by its header

Spans written to assets/sound/includes.json are consumed by tools/disasm.py (emit_data):
each .s is .include'd at its address inside the ROM data section.
"""
from __future__ import annotations

import json
import shutil
import struct
import subprocess
import sys
import tempfile
import wave
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
SND = ROOT / "assets" / "sound"
PCM_OUT = ROOT / "build" / "sound" / "samples"
B = 0x08000000

VG_START, VG_END = 0x0858BE94, 0x0858D354
MPLAY_TABLE = 0x0858D354
SONG_TABLE, SONG_COUNT = 0x0858D384, 399
DUMMY_SONG = 0x0858DFFC

CLOCK = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
         28, 30, 32, 36, 40, 42, 44, 48, 52, 54, 56, 60, 64, 66, 68, 72, 76, 78, 80, 84, 88, 90,
         92, 96]
CMDS = {0xB1: "FINE", 0xB2: "GOTO", 0xB3: "PATT", 0xB4: "PEND", 0xB5: "REPT", 0xB9: "MEMACC",
        0xBA: "PRIO", 0xBB: "TEMPO", 0xBC: "KEYSH", 0xBD: "VOICE", 0xBE: "VOL", 0xBF: "PAN",
        0xC0: "BEND", 0xC1: "BENDR", 0xC2: "LFOS", 0xC3: "LFODL", 0xC4: "MOD", 0xC5: "MODT",
        0xC8: "TUNE", 0xCD: "XCMD", 0xCE: "EOT", 0xCF: "TIE"}
ONE_ARG = {0xBA, 0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC8}


def cmd_name(c):
    if 0x80 <= c <= 0xB0:
        return f"W{CLOCK[c - 0x80]:02d}"
    if c >= 0xD0:
        return f"N{CLOCK[c - 0xCF]:02d}"
    return CMDS[c]


class Rom:
    def __init__(self, data):
        self.d = data

    def u8(self, a):
        return self.d[a - B]

    def u16(self, a):
        return struct.unpack_from("<H", self.d, a - B)[0]

    def u32(self, a):
        return struct.unpack_from("<I", self.d, a - B)[0]

    def bytes(self, a, n):
        return self.d[a - B:a - B + n]


def inrom(v):
    return B <= v < B + 0x800000


# --------------------------------------------------------------------------- tracks

def parse_track(r: Rom, start: int, stop: int):
    """Walk one track from `start` until FINE (or `stop`).  Returns (items, end, targets, voices)
    where items are (addr, kind, payload) for emission:
        ("cmd", [cmd, args...])   a command byte with its argument bytes
        ("run", [args...])        running-status arguments (no command byte)
        ("ptr", target)           a 4-byte pointer operand
    """
    items = []
    targets = set()
    voices = set()
    a = start
    running = None
    while a < stop:
        b = r.u8(a)
        if b >= 0x80:
            cmd = b
            line = [cmd]
            p = a + 1
            if cmd >= 0xBD:
                running = cmd
        else:
            if running is None:
                raise ValueError(f"running status without command at {a:08X}")
            cmd = running
            line = []
            p = a
        if 0x80 <= cmd <= 0xB0 or cmd in (0xB1, 0xB4):
            pass
        elif cmd in (0xB2, 0xB3):
            items.append((a, "cmd" if line else "run", line))
            t = r.u32(p)
            if not inrom(t):
                raise ValueError(f"bad pointer {t:08X} at {p:08X}")
            items.append((p, "ptr", t))
            targets.add(t)
            a = p + 4
            continue
        elif cmd == 0xB5:
            line.append(r.u8(p))
            items.append((a, "cmd" if line[:1] == [cmd] else "run", line))
            t = r.u32(p + 1)
            items.append((p + 1, "ptr", t))
            targets.add(t)
            a = p + 5
            continue
        elif cmd == 0xB9:
            op = r.u8(p)
            line += [op, r.u8(p + 1), r.u8(p + 2)]
            p += 3
            if op >= 6:
                items.append((a, "cmd", line))
                t = r.u32(p)
                items.append((p, "ptr", t))
                targets.add(t)
                a = p + 4
                continue
        elif cmd in ONE_ARG:
            line.append(r.u8(p))
            if cmd == 0xBD:
                voices.add(r.u8(p))
            p += 1
        elif cmd == 0xCD:
            xt = r.u8(p)
            line.append(xt)
            p += 1
            if xt == 1:
                raise ValueError(f"xwave not supported at {a:08X}")
            line.append(r.u8(p))
            p += 1
        elif cmd == 0xCE:
            if r.u8(p) < 0x80:
                line.append(r.u8(p))
                p += 1
        elif cmd >= 0xCF:
            for _ in range(3):
                if r.u8(p) < 0x80:
                    line.append(r.u8(p))
                    p += 1
                else:
                    break
        else:
            raise ValueError(f"unknown command {cmd:02X} at {a:08X}")
        items.append((a, "cmd" if line[:1] == [cmd] and b >= 0x80 else "run", line))
        a = p
        if b == 0xB1:
            return items, a, targets, voices
    raise ValueError(f"track at {start:08X} runs past {stop:08X}")


# --------------------------------------------------------------------------- discovery

class Sound:
    def __init__(self, rom: bytes):
        self.r = Rom(rom)
        r = self.r
        self.table = [(r.u32(SONG_TABLE + 8 * i), r.u16(SONG_TABLE + 8 * i + 4),
                       r.u16(SONG_TABLE + 8 * i + 6)) for i in range(SONG_COUNT)]
        self.song_name = {}
        for i, (h, _, _) in enumerate(self.table):
            if h == DUMMY_SONG:
                self.song_name.setdefault(h, "song_dummy")
            else:
                self.song_name.setdefault(h, f"song_{i:03d}")
        self.songs = {}
        for h in sorted(self.song_name):
            if h == DUMMY_SONG:
                continue
            n = r.u8(h)
            self.songs[h] = [r.u32(h + 8 + 4 * k) for k in range(n)]
        self.vg_used = {}                      # voicegroup -> set(program)
        for h, trks in self.songs.items():
            vg = r.u32(h + 4)
            self.vg_used.setdefault(vg, set())
        self.samples = self._samples()

    def _cells(self):
        a = VG_START
        while a + 12 <= VG_END:
            yield a
            a += 12

    def _samples(self):
        r = self.r
        ptrs = set()
        for a in self._cells():
            t = r.u8(a)
            p = r.u32(a + 4)
            if t in (0x00, 0x08, 0x10, 0x18) and inrom(p):
                typ, fr, ls, sz = struct.unpack_from("<4I", r.d, p - B)
                if typ in (0, 0x40000000) and fr and 0 < sz < 0x100000 and p >= 0x0858E000:
                    ptrs.add(p)
        ptrs = sorted(ptrs)
        out = {}
        for i, p in enumerate(ptrs):
            sz = r.u32(p + 12)
            end = p + 16 + sz
            nxt = ptrs[i + 1] if i + 1 < len(ptrs) else None
            if nxt is not None and 0 <= nxt - end <= 4:
                tail = nxt - end
            else:
                tail = 1
            out[p] = (end, tail)
        return out


# --------------------------------------------------------------------------- emission

def byte_lines(data: bytes, per=16):
    return ["\t.byte " + ", ".join(f"0x{x:02X}" for x in data[i:i + per])
            for i in range(0, len(data), per)]


def write(path: Path, lines):
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text("\n".join(lines) + "\n", newline="\n")


def emit_song(s: Sound, h: int, spans: list, names: dict):
    r = s.r
    name = s.song_name[h]
    trks = s.songs[h]
    parsed = []
    stops = sorted(trks) + [h]
    for t in sorted(trks):
        nxt = min(x for x in stops if x > t)
        items, end, targets, voices = parse_track(r, t, nxt)
        parsed.append((t, items, end, targets))
        s.vg_used[r.u32(h + 4)] |= voices
    start = min(trks) if trks else h
    lines = [f"@ {name}: m4a song, header 0x{h:08X}", '	.include "assets/sound/MPlayDef.inc"', ""]
    labels = {}
    for k, t in enumerate(trks):
        labels.setdefault(t, f"{name}_track{k + 1}")
    alltargets = set()
    for t, items, end, targets in parsed:
        alltargets |= targets
    for x in alltargets:
        labels.setdefault(x, f".L{name}_{x:08X}")
    pos = start
    for t, items, end, targets in sorted(parsed):
        if t < pos:
            raise ValueError(f"{name}: tracks overlap at {t:08X}")
        lines += byte_lines(r.bytes(pos, t - pos))
        pos = t
        for a, kind, payload in items:
            if a in labels:
                lab = labels[a]
                if not lab.startswith(".L"):
                    lines.append(f"\t.global {lab}")
                lines.append(f"{lab}:")
            if kind == "ptr":
                if payload not in labels:
                    raise ValueError(f"{name}: pointer {payload:08X} outside song")
                lines.append(f"\t.4byte {labels[payload]}")
                pos = a + 4
                continue
            if kind == "cmd":
                parts = [cmd_name(payload[0])] + [str(x) for x in payload[1:]]
                n = len(payload)
            else:
                parts = [str(x) for x in payload]
                n = len(payload)
            if parts:
                lines.append("\t.byte " + ", ".join(parts))
            pos = a + n
        if pos != end:
            raise ValueError(f"{name}: parse ended at {pos:08X}, track end {end:08X}")
        lines.append("")
    for x in alltargets:
        if not any(t <= x < e for t, _, e, _ in parsed):
            raise ValueError(f"{name}: jump target {x:08X} outside its tracks")
        if not any(a == x for _, items, _, _ in parsed for a, _, _ in items):
            raise ValueError(f"{name}: jump target {x:08X} not at an item boundary")
    lines += byte_lines(r.bytes(pos, h - pos))           # alignment padding before the header
    n = r.u8(h)
    vg = r.u32(h + 4)
    lines += [f"\t.global {name}", f"{name}:",
              f"\t.byte {n}  @ tracks", f"\t.byte {r.u8(h + 1)}  @ blocks",
              f"\t.byte {r.u8(h + 2)}  @ priority", f"\t.byte {r.u8(h + 3)}  @ reverb",
              f"\t.4byte {names[vg]}"]
    for k in range(n):
        lines.append(f"\t.4byte {name}_track{k + 1}")
    path = SND / "songs" / f"{name}.s"
    write(path, lines)
    spans.append((start, h + 8 + 4 * n, path))


def emit_voicegroups(s: Sound, names: dict, wave_labels: dict, spans: list):
    r = s.r
    vg_labels = {a: n for a, n in names.items() if VG_START <= a < VG_END}
    lines = ["@ m4a voicegroups (ToneData, 12 bytes each).  Voicegroups overlap: each label",
             "@ starts a 128-entry program table that runs into the following ones.",
             '\t.include "assets/sound/MPlayDef.inc"', ""]
    a = VG_START
    raw = bytearray()
    raw_at = a

    def flush():
        nonlocal raw, raw_at
        lines.extend(byte_lines(bytes(raw)))
        raw = bytearray()

    def label(x):
        flush()
        n = vg_labels.get(x) or wave_labels.get(x)
        lines.append(f"\t.global {n}")
        lines.append(f"{n}: @ 0x{x:08X}")

    while a < VG_END:
        lab_inside = [x for x in list(vg_labels) + list(wave_labels) if a < x < a + 12]
        if a in vg_labels or a in wave_labels:
            label(a)
        cell = r.bytes(a, 12) if a + 12 <= VG_END else b""
        text = None
        if cell and not lab_inside:
            text = tone_text(s, cell, names, wave_labels)
        if text is None:
            take = min(12, VG_END - a)
            for k in range(take):
                if k and (a + k) in vg_labels or k and (a + k) in wave_labels:
                    label(a + k)
                raw.append(r.u8(a + k))
            a += take
            continue
        flush()
        lines.append(text)
        a += 12
    flush()
    path = SND / "voicegroups.s"
    write(path, lines)
    spans.append((VG_START, VG_END, path))


def tone_text(s: Sound, c: bytes, names: dict, wave_labels: dict):
    t, key, ln, ps = c[0], c[1], c[2], c[3]
    p = struct.unpack_from("<I", c, 4)[0]
    adsr = ", ".join(str(x) for x in c[8:12])
    head = f"\t.byte 0x{t:02X}, {key}, {ln}, {ps}"
    if t in (0x00, 0x08, 0x10, 0x18):
        if p in s.samples:
            return f"{head}\n\t.4byte {names[p]}\n\t.byte {adsr}  @ DirectSound"
        if inrom(p) and not any(s.r.bytes(p, 16)):
            # Silent placeholder: points at an all-zero "sample header" outside the sound data.
            return (f"{head}\n\t.4byte 0x{p:08X}  @ all-zero header (no sample) outside sound data"
                    f"\n\t.byte {adsr}  @ DirectSound")
        return None
    if t in (0x03, 0x0B):
        if p in wave_labels:
            return f"{head}\n\t.4byte {wave_labels[p]}\n\t.byte {adsr}  @ CGB wave"
        return None
    if t in (0x01, 0x02, 0x04, 0x09, 0x0A, 0x0C):
        if inrom(p):
            return None
        kind = {1: "square 1", 2: "square 2", 4: "noise"}[t & 7]
        return f"{head}\n\t.4byte 0x{p:08X}\n\t.byte {adsr}  @ CGB {kind}"
    if t == 0x80:
        if p in names:
            return f"{head}\n\t.4byte {names[p]}\n\t.byte {adsr}  @ rhythm (drum kit)"
        return None
    if t == 0x40:
        q = struct.unpack_from("<I", c, 8)[0]
        if p in names and q in names:
            return f"{head}\n\t.4byte {names[p]}\n\t.4byte {names[q]}  @ keysplit"
        return None
    return None


def emit_samples(s: Sound, names: dict, spans: list, meta: dict):
    r = s.r
    for p, (end, tail) in sorted(s.samples.items()):
        typ, fr, ls, sz = struct.unpack_from("<4I", r.d, p - B)
        name = names[p]
        pcm = r.bytes(p + 16, sz)
        wav = SND / "samples" / f"{name}.wav"
        wav.parent.mkdir(parents=True, exist_ok=True)
        with wave.open(str(wav), "wb") as w:
            w.setnchannels(1)
            w.setsampwidth(1)
            w.setframerate(max(1, round(fr / 1024)))
            w.writeframes(bytes((x + 0x80) & 0xFF for x in pcm))
        meta[name] = {"addr": f"0x{p:08X}", "type": typ, "freq": fr, "loop_start": ls,
                      "size": sz, "tail": r.bytes(end, tail).hex()}
        lines = [f"@ {name}: DirectSound sample (header: type, pitch, loop start, size)",
                 f"\t.global {name}", f"{name}:",
                 f"\t.4byte 0x{typ:08X}, 0x{fr:08X}, 0x{ls:08X}, 0x{sz:08X}",
                 f'\t.incbin "build/sound/samples/{name}.pcm"']
        lines += byte_lines(r.bytes(end, tail))
        path = SND / "samples" / f"{name}.s"
        write(path, lines)
        spans.append((p, end + tail, path))


def emit_tables(s: Sound, spans: list):
    r = s.r
    lines = ["@ gMPlayTable: {MusicPlayerInfo*, MusicPlayerTrack*, u8 trackCount, u8 unk, u16 unk}"]
    for i in range(4):
        a = MPLAY_TABLE + 12 * i
        lines.append(f"\t.4byte 0x{r.u32(a):08X}, 0x{r.u32(a + 4):08X}")
        lines.append(f"\t.2byte {r.u16(a + 8)}, {r.u16(a + 10)}")
    lines += ["", "@ gSongTable: {SongHeader*, u16 music player, u16 me}"]
    for i, (h, ms, me) in enumerate(s.table):
        lines.append(f"\t.4byte {s.song_name[h]}")
        lines.append(f"\t.2byte {ms}, {me}  @ {i:03d}")
    lines += ["", "@ Header of the empty song used by unassigned slots.  Its voicegroup word",
              "@ is the first word of the next sample's header (0), so only 4 bytes are its own.",
              "\t.global song_dummy", "song_dummy:"]
    lines += byte_lines(r.bytes(DUMMY_SONG, 4))
    path = SND / "song_table.s"
    write(path, lines)
    spans.append((MPLAY_TABLE, DUMMY_SONG + 4, path))


MPLAYDEF = """@ m4a (MusicPlayer2000) track command bytes, after pret's MPlayDef.s.
	.equ FINE, 0xB1
	.equ GOTO, 0xB2
	.equ PATT, 0xB3
	.equ PEND, 0xB4
	.equ REPT, 0xB5
	.equ MEMACC, 0xB9
	.equ PRIO, 0xBA
	.equ TEMPO, 0xBB
	.equ KEYSH, 0xBC
	.equ VOICE, 0xBD
	.equ VOL, 0xBE
	.equ PAN, 0xBF
	.equ BEND, 0xC0
	.equ BENDR, 0xC1
	.equ LFOS, 0xC2
	.equ LFODL, 0xC3
	.equ MOD, 0xC4
	.equ MODT, 0xC5
	.equ TUNE, 0xC8
	.equ XCMD, 0xCD
	.equ EOT, 0xCE
	.equ TIE, 0xCF
"""


def mplaydef():
    out = MPLAYDEF
    for i, c in enumerate(CLOCK):
        out += f"\t.equ W{c:02d}, 0x{0x80 + i:02X}\n"
    for i, c in enumerate(CLOCK[1:], 1):
        out += f"\t.equ N{c:02d}, 0x{0xCF + i:02X}\n"
    return out


def extract():
    rom = (ROOT / "baserom.gba").read_bytes()
    s = Sound(rom)
    r = s.r
    if SND.exists():
        for sub in ("songs", "samples"):
            shutil.rmtree(SND / sub, ignore_errors=True)
    SND.mkdir(parents=True, exist_ok=True)
    (SND / "MPlayDef.inc").write_text(mplaydef(), newline="\n")
    names = {}
    # Voicegroups: every header's group, the drum kits/keysplit groups they reference.
    vgs = sorted({r.u32(h + 4) for h in s.songs} | {r.u32(DUMMY_SONG + 4)} - {0})
    for i, v in enumerate(vgs):
        names[v] = f"voicegroup_{i:03d}"
    names[0] = "0"
    for a in range(VG_START, VG_END - 11, 12):
        t = r.u8(a)
        p = r.u32(a + 4)
        if t in (0x40, 0x80) and VG_START <= p < VG_END and p not in names:
            names[p] = f"voicegroup_kit_{p:08X}"
    for p in s.samples:
        names[p] = f"sample_{p:08X}"
    wave_labels = {}
    for a in range(VG_START, VG_END - 11, 12):
        t = r.u8(a)
        p = r.u32(a + 4)
        if t in (0x03, 0x0B) and VG_START <= p < VG_END:
            wave_labels[p] = f"cgb_wave_{p:08X}"
    for p, n in wave_labels.items():
        (SND / "waves").mkdir(parents=True, exist_ok=True)
        (SND / "waves" / f"{n}.bin").write_bytes(r.bytes(p, 16))
    spans = []
    meta = {}
    for h in sorted(s.songs):
        emit_song(s, h, spans, names)
    emit_voicegroups(s, names, wave_labels, spans)
    emit_samples(s, names, spans, meta)
    emit_tables(s, spans)
    (SND / "samples" / "samples.json").write_text(json.dumps(meta, indent=1) + "\n", newline="\n")
    spans.sort()
    for (a0, e0, _), (a1, _, p1) in zip(spans, spans[1:]):
        if a1 < e0:
            raise SystemExit(f"spans overlap: {p1} at {a1:08X} < {e0:08X}")
    inc = [{"addr": f"0x{a:08X}", "len": e - a, "file": p.relative_to(ROOT).as_posix()}
           for a, e, p in spans]
    (SND / "includes.json").write_text(
        "[\n" + ",\n".join("  " + json.dumps(x) for x in inc) + "\n]\n", newline="\n")
    used = {names[v]: sorted(p) for v, p in s.vg_used.items()}
    (SND / "voicegroups_used.json").write_text(json.dumps(used, indent=1) + "\n", newline="\n")
    tot = sum(e - a for a, e, _ in spans)
    print(f"{len(s.songs)} songs (+ dummy), {len(vgs)} voicegroups, "
          f"{len([n for n in names.values() if n.startswith('voicegroup_kit')])} drum kits, "
          f"{len(s.samples)} samples, {len(wave_labels)} CGB waves; "
          f"{len(spans)} spans, {tot:#x} bytes")


# --------------------------------------------------------------------------- build / check

def build():
    meta = json.loads((SND / "samples" / "samples.json").read_text())
    PCM_OUT.mkdir(parents=True, exist_ok=True)
    n = 0
    for name, m in meta.items():
        wav = SND / "samples" / f"{name}.wav"
        dst = PCM_OUT / f"{name}.pcm"
        if dst.exists() and dst.stat().st_mtime >= wav.stat().st_mtime:
            continue
        with wave.open(str(wav), "rb") as w:
            if w.getsampwidth() != 1 or w.getnchannels() != 1:
                raise SystemExit(f"{wav}: must be 8-bit mono")
            frames = w.readframes(w.getnframes())
        if len(frames) != m["size"]:
            raise SystemExit(f"{wav}: {len(frames)} frames, header size field says {m['size']} "
                             "(edit samples.json and the .s header together)")
        dst.write_bytes(bytes((x - 0x80) & 0xFF for x in frames))
        n += 1
    print(f"built {n} sample .pcm files")


def check():
    sys.path.insert(0, str(ROOT / "tools"))
    from disasm import find_tool
    build()
    rom = (ROOT / "baserom.gba").read_bytes()
    spans = json.loads((SND / "includes.json").read_text())
    asm, ld, objcopy = (find_tool(t) for t in
                        ("arm-none-eabi-as", "arm-none-eabi-ld", "arm-none-eabi-objcopy"))
    with tempfile.TemporaryDirectory() as td:
        td = Path(td)
        src = ['\t.include "assets/sound/MPlayDef.inc"']
        lds = ["SECTIONS {"]
        for i, e in enumerate(spans):
            src += [f'\t.section .s{i}, "a"', f'\t.include "{e["file"]}"']
            lds.append(f"  .s{i} {e['addr']} : {{ *(.s{i}) }}")
        lds.append("}")
        (td / "t.s").write_text("\n".join(src) + "\n")
        (td / "t.ld").write_text("\n".join(lds) + "\n")
        for cmd in ([asm, "-mcpu=arm7tdmi", "-I", str(ROOT), "-o", str(td / "t.o"), str(td / "t.s")],
                    [ld, "-T", str(td / "t.ld"), "-o", str(td / "t.elf"), str(td / "t.o")],
                    [objcopy, "-O", "binary", str(td / "t.elf"), str(td / "t.bin")]):
            res = subprocess.run(cmd, capture_output=True, text=True, cwd=ROOT)
            if res.returncode:
                raise SystemExit(res.stderr[:4000])
        blob = (td / "t.bin").read_bytes()
    lo = int(spans[0]["addr"], 16)
    bad = 0
    for e in spans:
        a = int(e["addr"], 16)
        got = blob[a - lo:a - lo + e["len"]]
        if got != rom[a - B:a - B + e["len"]]:
            bad += 1
            i = next(i for i in range(e["len"]) if got[i:i + 1] != rom[a - B + i:a - B + i + 1])
            print(f"  MISMATCH {e['file']} at 0x{a + i:08X}")
    tot = sum(e["len"] for e in spans)
    print(f"{len(spans) - bad}/{len(spans)} spans identical to the base ROM ({tot:#x} bytes)")
    return bad


# --------------------------------------------------------------------------- MIDI (one-way)

def midi():
    rom = (ROOT / "baserom.gba").read_bytes()
    s = Sound(rom)
    r = s.r
    out = SND / "midi"
    out.mkdir(parents=True, exist_ok=True)
    for h, trks in sorted(s.songs.items()):
        name = s.song_name[h]
        mtrks = []
        for ch, t in enumerate(trks):
            mtrks.append(track_to_midi(r, t, ch % 16))
        hdr = b"MThd" + struct.pack(">IHHH", 6, 1, len(mtrks), 24)
        body = b"".join(b"MTrk" + struct.pack(">I", len(x)) + x for x in mtrks)
        (out / f"{name}.mid").write_bytes(hdr + body)
    print(f"wrote {len(s.songs)} MIDI files to {out}")


def _vlq(n):
    b = [n & 0x7F]
    n >>= 7
    while n:
        b.append(0x80 | (n & 0x7F))
        n >>= 7
    return bytes(reversed(b))


def track_to_midi(r: Rom, start: int, ch: int, max_ticks=96 * 400):
    """Follow PATT/PEND/REPT, stop at FINE or the first backwards GOTO (the loop point)."""
    ev = []
    t = 0
    a = start
    running = None
    key, vel = 60, 100
    stack = []
    rept = {}
    seen_goto = False
    while t < max_ticks:
        b = r.u8(a)
        if b >= 0x80:
            cmd = b
            a += 1
            if cmd >= 0xBD:
                running = cmd
        else:
            cmd = running
        if 0x80 <= cmd <= 0xB0:
            t += CLOCK[cmd - 0x80]
        elif cmd == 0xB1:
            break
        elif cmd == 0xB2:
            if seen_goto:
                break
            seen_goto = True
            break
        elif cmd == 0xB3:
            stack.append(a + 4)
            a = r.u32(a)
        elif cmd == 0xB4:
            if stack:
                a = stack.pop()
        elif cmd == 0xB5:
            n = r.u8(a)
            tgt = r.u32(a + 1)
            c = rept.get(a, 0) + 1
            if n == 0 or c < n:
                rept[a] = c
                a = tgt
            else:
                rept.pop(a, None)
                a += 5
        elif cmd == 0xB9:
            op = r.u8(a)
            a += 3 + (4 if op >= 6 else 0)
        elif cmd in ONE_ARG:
            v = r.u8(a)
            a += 1
            if cmd == 0xBB:
                us = int(60_000_000 / max(1, v * 2))
                ev.append((t, b"\xff\x51\x03" + us.to_bytes(3, "big")))
            elif cmd == 0xBD:
                ev.append((t, bytes([0xC0 | ch, v & 0x7F])))
            elif cmd == 0xBE:
                ev.append((t, bytes([0xB0 | ch, 7, v])))
            elif cmd == 0xBF:
                ev.append((t, bytes([0xB0 | ch, 10, v])))
        elif cmd == 0xCD:
            a += 2
        elif cmd == 0xCE:
            if r.u8(a) < 0x80:
                key = r.u8(a)
                a += 1
            ev.append((t, bytes([0x80 | ch, key, 0])))
        elif cmd >= 0xCF:
            args = []
            for _ in range(3):
                if r.u8(a) < 0x80:
                    args.append(r.u8(a))
                    a += 1
                else:
                    break
            if args:
                key = args[0]
            if len(args) > 1:
                vel = args[1]
            gate = (CLOCK[cmd - 0xCF] if cmd > 0xCF else 0) + (args[2] if len(args) > 2 else 0)
            ev.append((t, bytes([0x90 | ch, key, vel])))
            if cmd > 0xCF:
                ev.append((t + gate, bytes([0x80 | ch, key, 0])))
    ev.sort(key=lambda e: e[0])
    out = bytearray()
    last = 0
    for tt, data in ev:
        out += _vlq(tt - last) + data
        last = tt
    out += b"\x00\xff\x2f\x00"
    return bytes(out)


def main():
    cmd = sys.argv[1] if len(sys.argv) > 1 else "check"
    if cmd == "extract":
        extract()
    elif cmd == "build":
        build()
    elif cmd == "check":
        sys.exit(1 if check() else 0)
    elif cmd == "midi":
        midi()
    else:
        raise SystemExit(__doc__)


if __name__ == "__main__":
    main()
