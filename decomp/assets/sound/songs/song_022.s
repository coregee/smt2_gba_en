@ song_022: m4a song, header 0x086B9B24
	.include "assets/sound/MPlayDef.inc"

	.global song_022_track1
song_022_track1:
	.byte KEYSH, 0
	.byte TEMPO, 120
	.byte VOICE, 13
	.byte VOL, 86
	.byte N23, 69, 100
	.byte W24
	.byte 66
	.byte W24
	.byte 64
	.byte W24
	.byte 66
	.byte W24
	.byte 69
	.byte W24
	.byte 66
	.byte W24
	.byte 64
	.byte W24
	.byte 66
	.byte W23
.Lsong_022_086B99EA:
	.byte W01
.Lsong_022_086B99EB:
	.byte N23, 69, 100
	.byte W24
	.byte 66
	.byte W24
	.byte 64
	.byte W24
	.byte 66
	.byte W24
	.byte 69
	.byte W24
	.byte 66
	.byte W24
	.byte 64
	.byte W24
	.byte 66
	.byte W24
	.byte PEND
	.byte PATT
	.4byte .Lsong_022_086B99EB
	.byte PATT
	.4byte .Lsong_022_086B99EB
.Lsong_022_086B9A08:
	.byte N23, 70, 100
	.byte W24
	.byte 67
	.byte W24
	.byte 65
	.byte W24
	.byte 67
	.byte W24
	.byte 70
	.byte W24
	.byte 67
	.byte W24
	.byte 65
	.byte W24
	.byte 67
	.byte W24
	.byte PEND
	.byte PATT
	.4byte .Lsong_022_086B9A08
	.byte PATT
	.4byte .Lsong_022_086B9A08
	.byte PATT
	.4byte .Lsong_022_086B9A08
	.byte N23, 69, 100
	.byte W24
	.byte 66
	.byte W24
	.byte 64
	.byte W24
	.byte 66
	.byte W24
	.byte 69
	.byte W24
	.byte 66
	.byte W24
	.byte 64
	.byte W24
	.byte 66
	.byte W23
	.byte GOTO
	.4byte .Lsong_022_086B99EA
	.byte FINE

	.global song_022_track2
song_022_track2:
	.byte KEYSH, 0
	.byte VOICE, 14
	.byte VOL, 86
	.byte TIE, 60, 100
	.byte W96
	.byte W92
	.byte W03
	.byte EOT
.Lsong_022_086B9A4F:
	.byte W01
.Lsong_022_086B9A50:
	.byte TIE, 58, 100
	.byte W96
	.byte W92
	.byte W03
	.byte PEND
	.byte EOT
	.byte W01
.Lsong_022_086B9A59:
	.byte TIE, 60, 100
	.byte W96
	.byte W92
	.byte W03
	.byte PEND
	.byte EOT
	.byte W01
	.byte PATT
	.4byte .Lsong_022_086B9A50
	.byte EOT, 58
	.byte W01
.Lsong_022_086B9A6A:
	.byte TIE, 61, 100
	.byte W96
	.byte W92
	.byte W03
	.byte PEND
	.byte EOT
	.byte W01
.Lsong_022_086B9A73:
	.byte TIE, 59, 100
	.byte W96
	.byte W92
	.byte W03
	.byte PEND
	.byte EOT
	.byte W01
	.byte PATT
	.4byte .Lsong_022_086B9A6A
	.byte EOT, 61
	.byte W01
	.byte PATT
	.4byte .Lsong_022_086B9A73
	.byte EOT, 59
	.byte W01
	.byte PATT
	.4byte .Lsong_022_086B9A59
	.byte EOT, 60
	.byte GOTO
	.4byte .Lsong_022_086B9A4F
	.byte FINE

	.global song_022_track3
song_022_track3:
	.byte KEYSH, 0
	.byte W24
	.byte VOICE, 63
	.byte VOL, 62
	.byte N23, 69, 100
	.byte W24
	.byte 66
	.byte W24
	.byte 64
	.byte W24
	.byte 66
	.byte W24
	.byte 69
	.byte W24
	.byte 66
	.byte W24
	.byte 64
	.byte W24
	.byte 66
	.byte W23
.Lsong_022_086B9AB2:
	.byte W01
	.byte N23, 69, 100
	.byte W24
	.byte 66
	.byte W24
	.byte 64
	.byte W24
	.byte 66
	.byte W24
	.byte 69
	.byte W24
	.byte 66
	.byte W24
	.byte 64
	.byte W24
.Lsong_022_086B9AC3:
	.byte N23, 66, 100
	.byte W24
	.byte 69
	.byte W24
	.byte 66
	.byte W24
	.byte 64
	.byte W24
	.byte 66
	.byte W24
	.byte 69
	.byte W24
	.byte 66
	.byte W24
	.byte 64
	.byte W24
	.byte PEND
	.byte PATT
	.4byte .Lsong_022_086B9AC3
	.byte N23, 66, 100
	.byte W24
	.byte 70
	.byte W24
	.byte 67
	.byte W24
	.byte 65
	.byte W24
	.byte 67
	.byte W24
	.byte 70
	.byte W24
	.byte 67
	.byte W24
	.byte 65
	.byte W24
.Lsong_022_086B9AED:
	.byte N23, 67, 100
	.byte W24
	.byte 70
	.byte W24
	.byte 67
	.byte W24
	.byte 65
	.byte W24
	.byte 67
	.byte W24
	.byte 70
	.byte W24
	.byte 67
	.byte W24
	.byte 65
	.byte W24
	.byte PEND
	.byte PATT
	.4byte .Lsong_022_086B9AED
	.byte PATT
	.4byte .Lsong_022_086B9AED
	.byte N23, 67, 100
	.byte W24
	.byte 69
	.byte W24
	.byte 66
	.byte W24
	.byte 64
	.byte W24
	.byte 66
	.byte W24
	.byte 69
	.byte W24
	.byte 66
	.byte W24
	.byte 64
	.byte W24
	.byte 66
	.byte W23
	.byte GOTO
	.4byte .Lsong_022_086B9AB2
	.byte FINE

	.global song_022
song_022:
	.byte 3  @ tracks
	.byte 0  @ blocks
	.byte 10  @ priority
	.byte 166  @ reverb
	.4byte voicegroup_000
	.4byte song_022_track1
	.4byte song_022_track2
	.4byte song_022_track3
