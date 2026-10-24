@ song_016: m4a song, header 0x086B7ACC
	.include "assets/sound/MPlayDef.inc"

	.global song_016_track1
song_016_track1:
	.byte KEYSH, 0
	.byte TEMPO, 112
	.byte VOICE, 13
	.byte VOL, 100
	.byte TIE, 75, 52
	.byte TIE, 79
	.byte W96
	.byte W96
.Lsong_016_086B7A0B:
	.byte W96
	.byte W92
	.byte W03
	.byte PEND
	.byte EOT, 75
	.byte 79
.Lsong_016_086B7A12:
	.byte W01
.Lsong_016_086B7A13:
	.byte TIE, 74, 52
	.byte TIE, 78
	.byte W96
	.byte W96
	.byte PEND
	.byte PATT
	.4byte .Lsong_016_086B7A0B
	.byte EOT, 74
	.byte 78
	.byte W01
.Lsong_016_086B7A24:
	.byte TIE, 75, 52
	.byte TIE, 79
	.byte W96
	.byte W96
	.byte PEND
	.byte PATT
	.4byte .Lsong_016_086B7A0B
	.byte EOT, 75
	.byte 79
	.byte W01
	.byte PATT
	.4byte .Lsong_016_086B7A13
	.byte PATT
	.4byte .Lsong_016_086B7A0B
	.byte EOT, 74
	.byte 78
	.byte W01
	.byte PATT
	.4byte .Lsong_016_086B7A24
	.byte PATT
	.4byte .Lsong_016_086B7A0B
	.byte EOT, 75
	.byte 79
	.byte GOTO
	.4byte .Lsong_016_086B7A12
	.byte FINE

	.global song_016_track2
song_016_track2:
	.byte KEYSH, 0
	.byte VOICE, 14
	.byte VOL, 100
	.byte TIE, 60, 92
	.byte TIE, 72, 52
	.byte W96
	.byte W92
	.byte W03
	.byte EOT, 60
	.byte W01
.Lsong_016_086B7A68:
	.byte TIE, 55, 92
	.byte W96
	.byte W92
	.byte W03
	.byte PEND
	.byte EOT
	.byte EOT, 72
.Lsong_016_086B7A72:
	.byte W01
	.byte TIE, 59, 92
	.byte TIE, 71, 52
	.byte W96
	.byte W92
	.byte W03
	.byte EOT, 59
	.byte W01
	.byte TIE, 62, 92
	.byte W96
	.byte W92
	.byte W03
	.byte EOT
	.byte EOT, 71
	.byte W01
.Lsong_016_086B7A89:
	.byte TIE, 60, 92
	.byte TIE, 72, 52
	.byte W96
	.byte W92
	.byte W03
	.byte PEND
	.byte EOT, 60
	.byte W01
	.byte PATT
	.4byte .Lsong_016_086B7A68
	.byte EOT, 55
	.byte 72
	.byte W01
	.byte TIE, 62, 92
	.byte TIE, 71, 52
	.byte W96
	.byte W92
	.byte W03
	.byte EOT, 62
	.byte W01
	.byte TIE, 59, 92
	.byte W96
	.byte W92
	.byte W03
	.byte EOT
	.byte EOT, 71
	.byte W01
	.byte PATT
	.4byte .Lsong_016_086B7A89
	.byte EOT, 60
	.byte W01
	.byte PATT
	.4byte .Lsong_016_086B7A68
	.byte EOT, 55
	.byte 72
	.byte GOTO
	.4byte .Lsong_016_086B7A72
	.byte FINE

	.byte 0x00
	.global song_016
song_016:
	.byte 2  @ tracks
	.byte 0  @ blocks
	.byte 10  @ priority
	.byte 166  @ reverb
	.4byte voicegroup_000
	.4byte song_016_track1
	.4byte song_016_track2
