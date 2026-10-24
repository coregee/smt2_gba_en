"""BIOS-compatible decompressors (GBATEK): LZ77 (0x10), Huffman (0x24/0x28), RLE (0x30),
and an LZ77 compressor that reproduces the original streams where possible."""
from __future__ import annotations


def header(data: bytes, o: int):
    if o + 4 > len(data):
        return None, 0
    return data[o], data[o + 1] | data[o + 2] << 8 | data[o + 3] << 16


def lz77(data: bytes, o: int, limit=0x40000):
    """-> (out, compressed_len) or None."""
    t, size = header(data, o)
    if t != 0x10 or not 0 < size <= limit:
        return None
    out = bytearray()
    p = o + 4
    n = len(data)
    while len(out) < size:
        if p >= n:
            return None
        flags = data[p]
        p += 1
        for b in range(8):
            if len(out) >= size:
                break
            if flags & (0x80 >> b):
                if p + 1 >= n:
                    return None
                hi, lo = data[p], data[p + 1]
                p += 2
                ln = (hi >> 4) + 3
                disp = ((hi & 0xF) << 8 | lo) + 1
                if disp > len(out):
                    return None
                for _ in range(ln):
                    out.append(out[-disp])
            else:
                if p >= n:
                    return None
                out.append(data[p])
                p += 1
    if len(out) != size:
        return None
    return bytes(out), p - o


def rle(data: bytes, o: int, limit=0x40000):
    t, size = header(data, o)
    if t != 0x30 or not 0 < size <= limit:
        return None
    out = bytearray()
    p = o + 4
    n = len(data)
    while len(out) < size:
        if p >= n:
            return None
        f = data[p]
        p += 1
        if f & 0x80:
            ln = (f & 0x7F) + 3
            if p >= n:
                return None
            out += bytes([data[p]]) * ln
            p += 1
        else:
            ln = (f & 0x7F) + 1
            if p + ln > n:
                return None
            out += data[p:p + ln]
            p += ln
    if len(out) != size:
        return None
    return bytes(out), p - o


def huffman(data: bytes, o: int, limit=0x40000):
    t, size = header(data, o)
    if t not in (0x24, 0x28) or not 0 < size <= limit:
        return None
    bits = t & 0xF
    tsize = (data[o + 4] + 1) * 2
    root = o + 5
    p = o + 4 + tsize
    p = (p + 3) & ~3
    out = bytearray()
    acc = 0
    nacc = 0
    node = root
    n = len(data)
    try:
        while len(out) < size:
            if p + 4 > n:
                return None
            word = int.from_bytes(data[p:p + 4], "little")
            p += 4
            for i in range(32):
                bit = (word >> (31 - i)) & 1
                nd = data[node]
                off = nd & 0x3F
                nxt = (node & ~1) + off * 2 + 2 + bit
                if nd & (0x80 >> bit):
                    val = data[nxt] & ((1 << bits) - 1)
                    acc |= val << nacc
                    nacc += bits
                    node = root
                    if nacc == 8:
                        out.append(acc)
                        acc = nacc = 0
                        if len(out) >= size:
                            break
                else:
                    node = nxt
    except IndexError:
        return None
    if len(out) != size:
        return None
    return bytes(out), p - o


DECODERS = {0x10: lz77, 0x30: rle, 0x24: huffman, 0x28: huffman}


def decode(data: bytes, o: int):
    d = DECODERS.get(data[o]) if o < len(data) else None
    return d(data, o) if d else None


def lz77_compress(src: bytes) -> bytes:
    """Greedy LZ77 matching the encoder SMT2 was built with: at each position take the longest
    match (max 18), searching from the nearest candidate outward, never closer than distance 4.
    Reproduces the original streams byte for byte (tools/assets/check_codecs.py)."""
    out = bytearray([0x10, len(src) & 0xFF, (len(src) >> 8) & 0xFF, (len(src) >> 16) & 0xFF])
    i = 0
    n = len(src)
    while i < n:
        flag_pos = len(out)
        out.append(0)
        flags = 0
        for b in range(8):
            if i >= n:
                break
            best_len, best_disp = 0, 0
            lo = max(0, i - 0x1000)
            for j in range(i - 4, lo - 1, -1):
                k = 0
                while k < 18 and i + k < n and src[j + k] == src[i + k]:
                    k += 1
                if k > best_len:
                    best_len, best_disp = k, i - j
                    if k == 18:
                        break
            if best_len >= 3:
                flags |= 0x80 >> b
                d = best_disp - 1
                out.append(((best_len - 3) << 4) | (d >> 8))
                out.append(d & 0xFF)
                i += best_len
            else:
                out.append(src[i])
                i += 1
        out[flag_pos] = flags
    while len(out) % 4:
        out.append(0)
    return bytes(out)


def huffman_tree(data: bytes, o: int) -> bytes:
    """The serialized tree of the Huffman stream at `o` (tree-size byte included)."""
    return bytes(data[o + 4:o + 4 + (data[o + 4] + 1) * 2])


def _tree_codes(tree: bytes, bits: int):
    """symbol -> code string, walking a serialized tree (tree[0] is the size byte)."""
    codes = {}
    stack = [(1, "")]
    while stack:
        node, code = stack.pop()
        nd = tree[node]
        base = (node & ~1) + (nd & 0x3F) * 2 + 2
        for bit in (0, 1):
            nxt = base + bit
            if nd & (0x80 >> bit):
                codes[tree[nxt] & ((1 << bits) - 1)] = code + str(bit)
            else:
                stack.append((nxt, code + str(bit)))
    return codes


def huffman_compress(src: bytes, tree: bytes, bits: int = 4) -> bytes:
    """Encode with a given serialized tree (as stored beside each Huffman asset), so unedited
    assets rebuild byte for byte.  Raises KeyError if `src` uses a symbol the tree lacks."""
    codes = _tree_codes(tree, bits)
    syms = []
    for b in src:
        if bits == 4:
            syms += [b & 0xF, b >> 4]
        else:
            syms.append(b)
    bitstr = "".join(codes[s] for s in syms)
    bitstr += "0" * (-len(bitstr) % 32)
    t = 0x20 | bits
    out = bytearray([t, len(src) & 0xFF, (len(src) >> 8) & 0xFF, (len(src) >> 16) & 0xFF])
    out += tree
    while len(out) % 4:
        out.append(0)
    for i in range(0, len(bitstr), 32):
        out += int(bitstr[i:i + 32], 2).to_bytes(4, "little")
    return bytes(out)
