#!/usr/bin/env python3
"""Queue commands for gdbdrive.py and wait until they are processed.

    python tools/emu/send.py WORKDIR run=600 keys=A every=20
    python tools/emu/send.py WORKDIR shot=title
    python tools/emu/send.py WORKDIR run=60 keys=DOWN,A every=1 shot=menu
"""
import json
import sys
import time
from pathlib import Path


def main():
    work = Path(sys.argv[1])
    cmd = {}
    for a in sys.argv[2:]:
        k, v = a.split("=", 1)
        if k == "keys":
            cmd[k] = [x for x in v.split(",") if x]
        elif k in ("run", "every"):
            cmd[k] = int(v)
        else:
            cmd[k] = v
    st = work / "status.json"
    for _ in range(600):                      # wait for the driver to be up
        if st.exists():
            break
        time.sleep(0.1)
    before = st.stat().st_mtime_ns
    name = work / "cmd" / f"{time.time_ns()}.json"
    name.write_text(json.dumps(cmd))
    deadline = time.time() + 3600
    while time.time() < deadline:
        if not name.exists() and st.stat().st_mtime_ns != before:
            time.sleep(0.05)
            print(st.read_text())
            return
        time.sleep(0.1)
    raise SystemExit("timed out")


if __name__ == "__main__":
    main()
