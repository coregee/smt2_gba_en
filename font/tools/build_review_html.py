#!/usr/bin/env python3
"""Generate an interactive HTML page to review/edit the glyph map.

Data-driven: Python emits a JSON array of glyph records (code, embedded PNG,
region, confirmed char, OCR-baseline guess + confidence); the page builds the
table in JS. Per row: hex code | glyph image | region | conf | current | editable
input | (verify checkbox for low-confidence baselines).

Edits + verifications auto-save to browser localStorage. "Export TSV" downloads
the rows you edited OR verified as `code<TAB>char`, fed back via
`build_glyph_map.py --import-tsv glyph-map-reviewed.tsv --freeze`.

Usage:
    python -m font.tools.build_review_html
    python -m font.tools.build_review_html --no-unmapped
"""

from __future__ import annotations
import argparse
import base64
import io
import json
import sys
from pathlib import Path

try:
    from ._boot import CONFIG, GENERATED, REVIEW, ROOT, ROM as ROM_PATH
except ImportError:
    from _boot import CONFIG, GENERATED, REVIEW, ROOT, ROM as ROM_PATH

from font.generated.glyph_map import GLYPH_MAP
from font.script.render_glyph import render_glyph_pixels

ROM = ROM_PATH.read_bytes()
B = 0x08000000
LEVELS = {0: (255, 255, 255), 1: (150, 150, 150), 2: (0, 0, 0), 3: (190, 190, 190)}

u16 = lambda o: int.from_bytes(ROM[o:o + 2], "little")
u32 = lambda o: int.from_bytes(ROM[o:o + 4], "little")


def glyph_png_b64(code: int) -> str | None:
    from PIL import Image
    if (code >> 8) > 0x12:
        return None
    try:
        grid = render_glyph_pixels(ROM, code)
    except Exception:
        return None
    img = Image.new("RGB", (16, 16), (255, 255, 255))
    px = img.load()
    for y in range(16):
        for x in range(16):
            px[x, y] = LEVELS[grid[y][x]]
    buf = io.BytesIO()
    img.save(buf, "PNG")
    return base64.b64encode(buf.getvalue()).decode()


def region(code: int) -> str:
    if code < 0x100:
        return "punct"
    if 0x100 <= code < 0x011C or 0x01FE <= code < 0x0218:
        return "ascii-lower"
    if 0x011C <= code <= 0x016E:
        return "hiragana"
    if 0x017A <= code <= 0x01CE:
        return "katakana"
    if 0x0300 <= code < 0x0400:
        return "control/subst"
    return "kanji"


def collect_unmapped_used(mapped: set[int]) -> set[int]:
    used = set()

    def consider(c):
        if (0x0100 <= c < 0x0300 or 0x0400 <= c <= 0x12FF) and c not in mapped:
            used.add(c)

    seen = set()
    for src in range(0x08032de0 - B, 0x08035bb4 - B, 4):
        p = u32(src)
        if not (B <= p < B + len(ROM)) or (p - B) in seen:
            continue
        seen.add(p - B)
        for k in range(120):
            c = u16(p - B + k * 2)
            if c == 0 or c == 0x0301:
                break
            consider(c)
    for o in range(0x08009C00 - B, 0x08016000 - B, 2):       # demon compendium lore bank
        consider(u16(o))
    for o in range(0x08016000 - B, 0x080A8C00 - B, 2):       # early events + story/event bank
        consider(u16(o))
    for o in range(0x081236FC - B, 0x0812682E - B, 2):       # battle/menu/system message bank
        consider(u16(o))
    real = set()
    for c in used:
        if (c >> 8) > 0x12:
            continue
        try:
            g = render_glyph_pixels(ROM, c)
        except Exception:
            continue
        if sum(1 for row in g for v in row if v) > 8:
            real.add(c)
    return real


def collect_renderable_unmapped(skip):
    """Every font slot 0x0000-0x12FF that renders a real glyph (>8 ink px) but isn't in `skip`
    (mapped/baseline/used-in-text) — INCLUDING the control-range slots (0x00xx/0x03xx) the
    used-scan skips. These never appear in text, but the font may still hold a glyph; surfaced
    behind a toggle so unused-but-real slots can be confirmed/mapped."""
    out = set()
    for c in range(0x0000, 0x1300):
        if c in skip or 0x0300 <= c <= 0x0470:   # 0x300-0x470 are event-VM opcodes, not glyphs
            continue
        try:
            g = render_glyph_pixels(ROM, c)
        except Exception:
            continue
        if sum(1 for row in g for v in row if v) > 4:   # low cutoff: small marks (・=6px) count
            out.add(c)
    return out


def build_context(codes):
    """One decoded +/-7-glyph window per unmapped code (target marked 【 】) from the text
    banks, so the reviewer can confirm the rendered glyph against the word it completes."""
    want, ctx = set(codes), {}
    banks = [(0x08009C00, 0x08016000), (0x08016000, 0x080A8C00), (0x081236FC, 0x0812682E)]
    for lo, hi in banks:
        o, end = lo - B, hi - B
        while o < end and len(ctx) < len(want):
            c = u16(o)
            if c in want and c not in ctx:
                ctx[c] = "".join("【 】" if k == 0 else "/" if u16(o + k * 2) in (0, 0x0301)
                                 else GLYPH_MAP.get(u16(o + k * 2), "·") for k in range(-7, 8))
            o += 2
    return ctx


PAGE = """<!doctype html><html><head><meta charset="utf-8">
<title>SMT2 Glyph Map Review</title><style>
body{font-family:sans-serif;margin:0;background:#f4f4f4}
header{position:sticky;top:0;background:#222;color:#eee;padding:10px 16px;z-index:10}
header input#filter{font-size:15px;padding:4px 8px;width:200px}
header button{font-size:14px;padding:5px 12px;margin-left:8px;cursor:pointer}
#stats{margin-left:12px;font-size:13px;color:#9c9}
.legend{font-size:12px;color:#ccc;margin-left:10px}
.legend b{padding:1px 6px;border-radius:3px;color:#222}
table{border-collapse:collapse;width:100%;background:#fff}
th,td{border:1px solid #ddd;padding:3px 8px;text-align:left;vertical-align:middle}
th{position:sticky;top:48px;background:#eee}
img{width:48px;height:48px;image-rendering:pixelated;border:1px solid #ccc}
.code{font-family:monospace;color:#555}.reg{font-size:11px;color:#888}
.ctx{font-size:16px;color:#222}.ctx b{background:#ffe; color:#c00}
.conf{font-size:11px;color:#b80;font-family:monospace}
.cur{font-size:22px;min-width:1.4em;text-align:center}
.prop{font-size:22px;min-width:1.4em;text-align:center;color:#06c;font-weight:bold}
input.edit{font-size:20px;width:3.5em;text-align:center}
tr.changed{background:#fff6d5}tr.baseline{background:#fff0dd}
tr.unmapped{background:#ffecec}tr.verified{background:#e2f6e2}tr.extra{background:#eef0f4;opacity:.75}
</style></head><body>
<header>
<input id="filter" placeholder="filter hex or char...">
<button onclick="exportTSV()">Export TSV</button>
<button id="uvbtn" onclick="toggleUV()">Show unverified only</button>
<button id="exbtn" onclick="toggleExtra()">Show unused slots</button>
<button onclick="resetProposed()">Reset proposed rows</button>
<button onclick="clearLocal()">Clear my edits</button>
<span id="stats"></span>
<span class="legend"><b style="background:#fff0dd">OCR baseline</b>
<b style="background:#e2f6e2">verified</b> <b style="background:#fff6d5">edited</b>
<b style="background:#ffecec">no guess</b> <b style="background:#eef0f4">unused slot</b></span>
</header>
<table><thead><tr><th>code</th><th>glyph</th><th>proposed</th><th>context</th><th>region</th><th>conf</th>
<th>current</th><th>edit</th><th>✓</th></tr></thead><tbody id="tb"></tbody></table>
<script>
const DATA=__DATA__;
const EK='smt2glyph', VK='smt2verify';
let edits=JSON.parse(localStorage.getItem(EK)||'{}');
let verified=JSON.parse(localStorage.getItem(VK)||'{}');
let uvOnly=false, showExtra=false;
const tb=document.getElementById('tb');
function rowClass(g){
  if(g.code in edits && edits[g.code]!==(g.cur||g.base)) return 'changed';
  if(verified[g.code]) return 'verified';
  if(g.extra) return 'extra';
  if(g.cur==='' && g.base!=='') return 'baseline';
  if(g.cur==='' ) return 'unmapped';
  return '';
}
function build(){
  const rows=[];
  for(const g of DATA){
    const prefill = (g.code in edits)?edits[g.code]:(g.cur||g.base);
    const isBase = g.cur===''&&g.base!=='';
    const cb = (isBase||g.cur==='')?`<input type=checkbox class=vrf data-code="${g.code}" ${verified[g.code]?'checked':''}>`:'';
    const img = g.img?`<img src="data:image/png;base64,${g.img}">`:'(n/a)';
    rows.push(`<tr data-code="${g.code}" data-base="${(isBase||g.cur==='')?1:0}" data-extra="${g.extra?1:0}" data-search="${(g.code+' '+g.cur+' '+g.base).toLowerCase()}">`+
      `<td class=code>${g.code}</td><td>${img}</td>`+
      `<td class=prop title="${esc(g.conf||'')}">${esc(g.base)}</td>`+
      `<td class=ctx>${esc(g.ctx||'').replace('【 】','<b>?</b>')}</td><td class=reg>${g.reg}</td>`+
      `<td class=conf>${g.cur!==''?'✓':(g.conf||'')}</td>`+
      `<td class=cur>${esc(g.cur)}</td>`+
      `<td><input class=edit data-code="${g.code}" value="${esc(prefill)}"></td>`+
      `<td>${cb}</td></tr>`);
  }
  tb.innerHTML=rows.join('');
  for(const tr of tb.children) tr.className=rowClass(DATA.find(d=>d.code===tr.dataset.code));
  stats();
}
function esc(s){return (s||'').replace(/&/g,'&amp;').replace(/</g,'&lt;').replace(/"/g,'&quot;');}
function stats(){
  const e=Object.keys(edits).length, v=Object.values(verified).filter(Boolean).length;
  document.getElementById('stats').textContent=`${e} edited, ${v} verified`;
}
function refreshRow(code){
  const tr=tb.querySelector(`tr[data-code="${code}"]`);
  const g=DATA.find(d=>d.code===code);
  if(tr&&g) tr.className=rowClass(g);
}
tb.addEventListener('input',e=>{
  if(e.target.classList.contains('edit')){
    const c=e.target.dataset.code,g=DATA.find(d=>d.code===c);
    const def=g.cur||g.base;
    if(e.target.value===def) delete edits[c]; else edits[c]=e.target.value;
    localStorage.setItem(EK,JSON.stringify(edits)); refreshRow(c); stats();
  }
});
tb.addEventListener('change',e=>{
  if(e.target.classList.contains('vrf')){
    const c=e.target.dataset.code;
    if(e.target.checked) verified[c]=true; else delete verified[c];
    localStorage.setItem(VK,JSON.stringify(verified)); refreshRow(c); stats();
  }
});
function exportTSV(){
  // export rows that were edited OR verified -> become confirmed on import
  const lines=['code\\tchar']; const seen=new Set();
  for(const inp of tb.querySelectorAll('input.edit')){
    const c=inp.dataset.code, v=inp.value.trim();
    const edited=(c in edits), ver=!!verified[c];
    if((edited||ver)&&v){lines.push(c+'\\t'+v);seen.add(c);}
  }
  const blob=new Blob([lines.join('\\n')+'\\n'],{type:'text/tab-separated-values'});
  const a=document.createElement('a');a.href=URL.createObjectURL(blob);
  a.download='glyph-map-reviewed.tsv';a.click();
}
function toggleUV(){uvOnly=!uvOnly;document.getElementById('uvbtn').textContent=uvOnly?'Show all':'Show unverified only';applyFilter();}
function toggleExtra(){showExtra=!showExtra;document.getElementById('exbtn').textContent=showExtra?'Hide unused slots':'Show unused slots';applyFilter();}
function applyFilter(){
  const q=document.getElementById('filter').value.toLowerCase();
  for(const tr of tb.children){
    const isBase=tr.dataset.base==='1', ver=verified[tr.dataset.code], isExtra=tr.dataset.extra==='1';
    tr.style.display=(tr.dataset.search.includes(q)&&(!uvOnly||(isBase&&!ver))&&(showExtra||!isExtra))?'':'none';
  }
}
function clearLocal(){if(confirm('Discard all edits and verifications?')){localStorage.removeItem(EK);localStorage.removeItem(VK);edits={};verified={};build();}}
function resetProposed(){
  let n=0;
  for(const g of DATA){if(g.cur===''&&g.base!==''&&(g.code in edits)){delete edits[g.code];n++;}}
  localStorage.setItem(EK,JSON.stringify(edits));build();applyFilter();
  alert('Reset '+n+' proposed row(s) to my suggestion. Tick ✓ to accept, or edit.');
}
document.getElementById('filter').addEventListener('input',applyFilter);
build();applyFilter();
</script></body></html>
"""


def main():
    if hasattr(sys.stdout, "reconfigure"):
        sys.stdout.reconfigure(encoding="utf-8")
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default=str(REVIEW / "glyph_review.html"))
    ap.add_argument("--no-unmapped", action="store_true")
    args = ap.parse_args()

    confirmed = {int(k, 16): v for k, v in
                 json.loads((CONFIG / "glyph_map_data.json").read_text(encoding="utf-8")).items()}
    baselines: dict[int, tuple[str, str]] = {}
    bpath = GENERATED / "glyph_ocr_baseline.tsv"
    if bpath.exists():
        for i, line in enumerate(bpath.read_text(encoding="utf-8").splitlines()):
            if i == 0 or not line.strip():
                continue
            p = line.split("\t")
            if len(p) >= 3 and p[1].strip():
                baselines[int(p[0], 16)] = (p[1].strip(), p[2].strip())

    codes = set(confirmed) | set(baselines)
    if not args.no_unmapped:
        codes |= collect_unmapped_used(set(confirmed))
    context = build_context(codes - set(confirmed))   # incl. baselines, for review clues
    extra = set() if args.no_unmapped else collect_renderable_unmapped(codes)

    data = []
    n_conf = n_base = n_none = 0
    for code in sorted(codes | extra):
        cur = confirmed.get(code, "")
        base, conf = baselines.get(code, ("", ""))
        is_extra = code in extra
        if cur:
            n_conf += 1
        elif is_extra:
            pass
        elif base:
            n_base += 1
        else:
            n_none += 1
        data.append({"code": f"{code:04X}", "img": glyph_png_b64(code),
                     "reg": region(code), "cur": cur, "base": base, "conf": conf,
                     "ctx": context.get(code, ""), "extra": is_extra})

    page = PAGE.replace("__DATA__", json.dumps(data, ensure_ascii=False))
    output = ROOT / args.out
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(page, encoding="utf-8")
    print(f"wrote {output}  ({len(data)} rows: {n_conf} confirmed, "
          f"{n_base} OCR-baseline, {n_none} no-guess, {len(extra)} unused-but-renderable slots)")


if __name__ == "__main__":
    raise SystemExit(main())
