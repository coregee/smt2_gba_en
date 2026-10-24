@ song_113: m4a song, header 0x086BC8F8
	.include "assets/sound/MPlayDef.inc"

	.global song_113_track1
song_113_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 13
	.byte VOL, 127
	.byte PAN, 64
	.byte N90, 60, 88
	.byte W90
	.byte FINE

	.byte 0x00
	.global song_113
song_113:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_113_track1
