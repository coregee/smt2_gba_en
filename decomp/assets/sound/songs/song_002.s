@ song_002: m4a song, header 0x086B3B10
	.include "assets/sound/MPlayDef.inc"

	.global song_002_track1
song_002_track1:
	.byte KEYSH, 0
	.byte TEMPO, 94
	.byte VOICE, 2
	.byte VOL, 100
	.byte W48
	.byte TIE, 60, 127
	.byte W96
	.byte W48
	.byte W96
	.byte W96
	.byte W44
	.byte W03
	.byte EOT
.Lsong_002_086B3AAF:
	.byte W01
	.byte TIE, 60, 127
	.byte W96
	.byte W48
	.byte W96
	.byte W96
	.byte W44
	.byte W03
	.byte EOT
	.byte GOTO
	.4byte .Lsong_002_086B3AAF
	.byte FINE

	.global song_002_track2
song_002_track2:
	.byte KEYSH, 0
	.byte VOICE, 1
	.byte VOL, 78
	.byte W48
	.byte TIE, 36, 127
	.byte TIE, 48, 80
	.byte W96
	.byte W48
	.byte W96
	.byte W96
	.byte W44
	.byte W03
	.byte EOT, 36
	.byte 48
.Lsong_002_086B3AD6:
	.byte W01
	.byte TIE, 36, 127
	.byte TIE, 48, 80
	.byte W96
	.byte W48
	.byte W96
	.byte W96
	.byte W44
	.byte W03
	.byte EOT, 36
	.byte 48
	.byte GOTO
	.4byte .Lsong_002_086B3AD6
	.byte FINE

	.global song_002_track3
song_002_track3:
	.byte KEYSH, 0
	.byte VOICE, 0
	.byte VOL, 100
	.byte W48
	.byte TIE, 60, 127
	.byte W96
	.byte W48
	.byte W96
	.byte W96
	.byte W44
	.byte W03
	.byte EOT
.Lsong_002_086B3AFD:
	.byte W01
	.byte TIE, 60, 127
	.byte W96
	.byte W48
	.byte W96
	.byte W96
	.byte W44
	.byte W03
	.byte EOT
	.byte GOTO
	.4byte .Lsong_002_086B3AFD
	.byte FINE

	.byte 0x00, 0x00
	.global song_002
song_002:
	.byte 3  @ tracks
	.byte 0  @ blocks
	.byte 10  @ priority
	.byte 166  @ reverb
	.4byte voicegroup_000
	.4byte song_002_track1
	.4byte song_002_track2
	.4byte song_002_track3
