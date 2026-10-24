@ song_341: m4a song, header 0x086BE158
	.include "assets/sound/MPlayDef.inc"

	.global song_341_track1
song_341_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 89
	.byte VOL, 91
	.byte PAN, 64
	.byte N92, 60, 92
	.byte W92
	.byte W02
	.byte N68
	.byte W02
	.byte W68
	.byte W01
	.byte N48
	.byte W24
	.byte W03
	.byte W24
	.byte N36
	.byte W40
	.byte N24
	.byte W24
	.byte W02
	.byte N48
	.byte W06
	.byte W42
	.byte FINE

	.global song_341_track2
song_341_track2:
	.byte KEYSH, 0
	.byte VOICE, 89
	.byte VOL, 91
	.byte PAN, 64
	.byte W48
	.byte W02
	.byte N80, 60, 92
	.byte W44
	.byte W02
	.byte W36
	.byte W01
	.byte N56
	.byte W56
	.byte W02
	.byte N44
	.byte W01
	.byte W44
	.byte W01
	.byte N30
	.byte W32
	.byte N24
	.byte W19
	.byte W07
	.byte N64
	.byte W64
	.byte FINE

	.global song_341_track3
song_341_track3:
	.byte KEYSH, 0
	.byte VOICE, 91
	.byte VOL, 127
	.byte PAN, 64
	.byte W96
	.byte W96
	.byte W96
	.byte W18
	.byte TIE, 60, 124
	.byte W78
	.byte W96
	.byte W06
	.byte EOT
	.byte FINE

	.global song_341
song_341:
	.byte 3  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_341_track1
	.4byte song_341_track2
	.4byte song_341_track3
