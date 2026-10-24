#!/usr/bin/env python3
"""Drive mGBA through its GDB server to test the game at run time.

    python tools/emu/gdbdrive.py ROM WORKDIR

Starts `mGBA -g ROM`, connects to the GDB stub (port 2345) and runs the game frame by
frame.  Input is injected deterministically: a breakpoint right after Keys_Read loads
REG_KEYINPUT (0x080A9A0A) overwrites r0 with the keys we want held this frame.

Probes (each logs to WORKDIR/events.log):
  * Font_CacheGlyphSprite full path (0x080AC134): the glyph sprite cache is full and the
    caller is about to draw with slot -1 (wrong tiles).  Logged with the caller (lr), the
    requested glyph code (r6) and the cache contents.
  * Every 30 frames: the cache's count/capacity high-water mark.

Commands are JSON files dropped in WORKDIR/cmd/ (processed in name order, then deleted):
  {"run": N, "keys": ["A"], "every": K}   run N frames; press `keys` on one frame in every K
                                          (K=1: hold them); keys from A B SELECT START RIGHT
                                          LEFT UP DOWN R L
  {"shot": "name"}                        screenshot the window to WORKDIR/name.png
  {"quit": true}
Status is written to WORKDIR/status.json after each command.
"""
from __future__ import annotations

import ctypes
import json
import socket
import struct
import subprocess
import sys
import time
from ctypes import wintypes
from pathlib import Path

MGBA = r"C:\Program Files\mGBA\mGBA.exe"      # the SDL build's -g opens no GDB server
KEYS = {"A": 0, "B": 1, "SELECT": 2, "START": 3, "RIGHT": 4, "LEFT": 5, "UP": 6, "DOWN": 7,
        "R": 8, "L": 9}
BP_KEYS = 0x080A9A0A          # Keys_Read: after `ldrh r0, [REG_KEYINPUT]`
BP_FULL = 0x080AC134          # Font_CacheGlyphSprite: count == capacity -> returns -1
CACHE = 0x020360DC            # gGlyphSpriteCache {baseTile, count, capacity, pending, codes[64]}


class Gdb:
    def __init__(self, port=2345):
        for _ in range(100):
            try:
                self.s = socket.create_connection(("127.0.0.1", port), timeout=10)
                break
            except OSError:
                time.sleep(0.2)
        else:
            raise SystemExit("could not connect to the mGBA GDB server")
        self.buf = b""

    def _recv_packet(self):
        while True:
            while b"$" not in self.buf:
                self.buf += self.s.recv(65536)
            start = self.buf.index(b"$")
            while b"#" not in self.buf[start:] or len(self.buf) < self.buf.index(b"#", start) + 3:
                self.buf += self.s.recv(65536)
            end = self.buf.index(b"#", start)
            data = self.buf[start + 1:end]
            self.buf = self.buf[end + 3:]
            self.s.sendall(b"+")
            return data.decode("latin-1")

    def cmd(self, payload, expect_reply=True):
        csum = sum(payload.encode()) & 0xFF
        self.s.sendall(f"${payload}#{csum:02x}".encode())
        # ack
        while not self.buf:
            self.buf += self.s.recv(65536)
        if self.buf[:1] == b"+":
            self.buf = self.buf[1:]
        return self._recv_packet() if expect_reply else None

    def regs(self):
        r = self.cmd("g")
        vals = [struct.unpack("<I", bytes.fromhex(r[i:i + 8]))[0] for i in range(0, 16 * 8, 8)]
        return vals

    def set_reg(self, n, v):
        return self.cmd(f"P{n:x}={struct.pack('<I', v).hex()}")

    def read(self, addr, n):
        return bytes.fromhex(self.cmd(f"m{addr:x},{n:x}"))

    def wait_stop(self):
        return self._recv_packet()


def capture(title_part, path):
    """Screenshot the mGBA window (PrintWindow works even when it is covered)."""
    user32 = ctypes.windll.user32
    gdi32 = ctypes.windll.gdi32
    try:
        ctypes.windll.shcore.SetProcessDpiAwareness(2)   # real pixel sizes under display scaling
    except (AttributeError, OSError):
        user32.SetProcessDPIAware()
    found = []

    @ctypes.WINFUNCTYPE(ctypes.c_bool, wintypes.HWND, wintypes.LPARAM)
    def enum(hwnd, _):
        n = user32.GetWindowTextLengthW(hwnd)
        if n:
            b = ctypes.create_unicode_buffer(n + 1)
            user32.GetWindowTextW(hwnd, b, n + 1)
            if title_part in b.value and user32.IsWindowVisible(hwnd):
                found.append(hwnd)
        return True

    user32.EnumWindows(enum, 0)
    if not found:
        return False
    hwnd = found[0]
    rect = wintypes.RECT()
    user32.GetClientRect(hwnd, ctypes.byref(rect))
    w, h = rect.right, rect.bottom
    hdc = user32.GetDC(hwnd)
    mdc = gdi32.CreateCompatibleDC(hdc)
    bmp = gdi32.CreateCompatibleBitmap(hdc, w, h)
    gdi32.SelectObject(mdc, bmp)
    user32.PrintWindow(hwnd, mdc, 3)      # PW_CLIENTONLY | PW_RENDERFULLCONTENT
    bmi = struct.pack("<IiiHHIIiiII", 40, w, -h, 1, 32, 0, 0, 0, 0, 0, 0)
    buf = ctypes.create_string_buffer(w * h * 4)
    gdi32.GetDIBits(mdc, bmp, 0, h, buf, bmi, 0)
    gdi32.DeleteObject(bmp)
    gdi32.DeleteDC(mdc)
    user32.ReleaseDC(hwnd, hdc)
    from PIL import Image
    Image.frombuffer("RGBA", (w, h), buf.raw, "raw", "BGRA", 0, 1).convert("RGB").save(path)
    return True


def main():
    rom, work = sys.argv[1], Path(sys.argv[2])
    (work / "cmd").mkdir(parents=True, exist_ok=True)
    log = open(work / "events.log", "a", encoding="utf-8")
    proc = subprocess.Popen([MGBA, "-g", "-2", "-C", "audioSync=0", "-C", "videoSync=0",
                             "-C", "fpsTarget=600", rom])
    g = Gdb()
    g.cmd("qSupported")
    g.cmd("?")
    for bp in (BP_KEYS, BP_FULL):
        r = g.cmd(f"Z0,{bp:x},2")
        log.write(f"breakpoint {bp:08X}: {r}\n")
    # Who changes the cache capacity (gGlyphSpriteCache.capacity, +4)?
    r = g.cmd(f"Z2,{CACHE + 4:x},2")
    log.write(f"write watchpoint {CACHE + 4:08X}: {r}\n")
    log.flush()
    frame = 0
    hw_count = 0
    hw_cap = 0
    overflows = 0
    callers = {}
    cap_writers = set()

    def step_frames(n, keys, every):
        nonlocal frame, hw_count, hw_cap, overflows
        target = frame + n
        mask = 0
        for k in keys:
            mask |= 1 << KEYS[k]
        while frame < target:
            g.cmd("c", expect_reply=False)
            stop = g.wait_stop()
            pc = g.regs()[15]
            if pc == BP_KEYS:
                press = mask if (every <= 1 or frame % every == 0) else 0
                g.set_reg(0, (~press) & 0x3FF)
                frame += 1
                if frame % 30 == 0:
                    c = g.read(CACHE, 8)
                    _, count, cap, _ = struct.unpack("<HHHH", c)
                    if count > hw_count or cap != hw_cap:
                        hw_count = max(hw_count, count)
                        hw_cap = cap
                        log.write(f"frame {frame}: cache count {count}/{cap}\n")
                        log.flush()
            elif pc == BP_FULL:
                r = g.regs()
                lr = r[14] - 1
                c = g.read(CACHE, 0x88)
                _, count, cap, _ = struct.unpack("<HHHH", c[:8])
                codes = struct.unpack("<64H", c[8:])[:count]
                overflows += 1
                callers[lr] = callers.get(lr, 0) + 1
                if callers[lr] <= 5:
                    log.write(f"OVERFLOW frame {frame}: caller {lr:08X} glyph {r[6]:04X} "
                              f"count {count}/{cap} cached " +
                              " ".join(f"{x:04X}" for x in codes) + "\n")
                    log.flush()
            elif "watch" in stop:
                r = g.regs()
                cap = struct.unpack("<H", g.read(CACHE + 4, 2))[0]
                key = (pc, cap)
                if key not in cap_writers:
                    cap_writers.add(key)
                    log.write(f"CAPACITY write frame {frame}: pc {pc:08X} lr {r[14]:08X} "
                              f"-> {cap}\n")
                    log.flush()
            else:
                log.write(f"unexpected stop at {pc:08X}: {stop}\n")
                log.flush()

    def status(extra=None):
        st = {"frame": frame, "cache_high_water": hw_count, "capacity": hw_cap,
              "overflows": overflows, "callers": {f"{k:08X}": v for k, v in callers.items()}}
        if extra:
            st.update(extra)
        (work / "status.json").write_text(json.dumps(st, indent=1))

    status({"state": "ready"})
    while True:
        cmds = sorted((work / "cmd").glob("*.json"))
        if not cmds:
            time.sleep(0.1)
            if proc.poll() is not None:
                break
            continue
        c = json.loads(cmds[0].read_text())
        cmds[0].unlink()
        if c.get("quit"):
            break
        if "run" in c:
            step_frames(int(c["run"]), c.get("keys", []), int(c.get("every", 1)))
        if "shot" in c:
            ok = capture("mGBA", str(work / f"{c['shot']}.png"))
            status({"shot": c["shot"], "shot_ok": ok})
        else:
            status()
    proc.terminate()


if __name__ == "__main__":
    main()
