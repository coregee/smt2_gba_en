@ song_009: m4a song, header 0x086B4B1C
	.include "assets/sound/MPlayDef.inc"

	.global song_009_track1
song_009_track1:
	.byte KEYSH, 0
	.byte TEMPO, 116
	.byte VOICE, 127
	.byte VOL, 100
	.byte N01, 37, 60
	.byte N12, 43, 120
	.byte W48
	.byte N01, 37, 60
	.byte N12, 43, 120
	.byte W48
	.byte N01, 37, 60
	.byte N12, 43, 120
	.byte W48
	.byte N01, 37, 60
	.byte N12, 43, 120
	.byte W48
	.byte N01, 37, 60
	.byte N12, 43, 120
	.byte W48
	.byte N01, 37, 60
	.byte N12, 43, 120
	.byte W48
	.byte N01, 37, 60
	.byte N12, 43, 120
	.byte W48
	.byte N01, 37, 60
	.byte N12, 43, 120
	.byte W44
	.byte W03
.Lsong_009_086B4A19:
	.byte W01
.Lsong_009_086B4A1A:
	.byte N01, 37, 60
	.byte N12, 43, 120
	.byte W48
	.byte N01, 37, 60
	.byte N12, 43, 120
	.byte W48
	.byte N01, 37, 60
	.byte N12, 43, 120
	.byte W48
	.byte N01, 37, 60
	.byte N12, 43, 120
	.byte W48
	.byte PEND
	.byte PATT
	.4byte .Lsong_009_086B4A1A
	.byte PATT
	.4byte .Lsong_009_086B4A1A
	.byte N01, 37, 60
	.byte N12, 43, 120
	.byte W48
	.byte N01, 37, 60
	.byte N12, 43, 120
	.byte W48
	.byte N01, 37, 60
	.byte N12, 43, 120
	.byte W48
	.byte N01, 37, 60
	.byte N12, 43, 120
	.byte W44
	.byte W03
	.byte GOTO
	.4byte .Lsong_009_086B4A19
	.byte FINE

	.global song_009_track2
song_009_track2:
	.byte KEYSH, 0
	.byte VOICE, 100
	.byte VOL, 94
	.byte N23, 56, 120
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W23
.Lsong_009_086B4A8C:
	.byte W01
.Lsong_009_086B4A8D:
	.byte N23, 58, 120
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte PEND
	.byte PATT
	.4byte .Lsong_009_086B4A8D
	.byte N23, 56, 120
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W24
	.byte N23
	.byte W23
	.byte GOTO
	.4byte .Lsong_009_086B4A8C
	.byte FINE

	.global song_009_track3
song_009_track3:
	.byte KEYSH, 0
	.byte VOICE, 5
	.byte VOL, 78
	.byte TIE, 51, 32
	.byte TIE, 54
	.byte TIE, 63, 60
	.byte TIE, 66
	.byte W96
	.byte W96
.Lsong_009_086B4ADF:
	.byte W96
	.byte W92
	.byte W03
	.byte PEND
	.byte EOT, 51
	.byte 54
	.byte 63
	.byte 66
.Lsong_009_086B4AE8:
	.byte W01
	.byte TIE, 53, 32
	.byte TIE, 56
	.byte TIE, 65, 60
	.byte TIE, 68
	.byte W96
	.byte W96
	.byte PATT
	.4byte .Lsong_009_086B4ADF
	.byte EOT, 53
	.byte 56
	.byte 65
	.byte 68
	.byte W01
	.byte TIE, 51, 32
	.byte TIE, 54
	.byte TIE, 63, 60
	.byte TIE, 66
	.byte W96
	.byte W96
	.byte PATT
	.4byte .Lsong_009_086B4ADF
	.byte EOT, 51
	.byte 54
	.byte 63
	.byte 66
	.byte GOTO
	.4byte .Lsong_009_086B4AE8
	.byte FINE

	.global song_009
song_009:
	.byte 3  @ tracks
	.byte 0  @ blocks
	.byte 10  @ priority
	.byte 166  @ reverb
	.4byte voicegroup_000
	.4byte song_009_track1
	.4byte song_009_track2
	.4byte song_009_track3
