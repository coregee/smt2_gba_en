@ song_111: m4a song, header 0x086BC8C0
	.include "assets/sound/MPlayDef.inc"

	.global song_111_track1
song_111_track1:
	.byte KEYSH, 0
	.byte TEMPO, 30
	.byte VOICE, 11
	.byte VOL, 127
	.byte PAN, 64
	.byte TIE, 64, 127
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte W96
	.byte EOT
	.byte FINE

	.global song_111
song_111:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_111_track1
