@ song_114: m4a song, header 0x086BC914
	.include "assets/sound/MPlayDef.inc"

	.global song_114_track1
song_114_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 14
	.byte VOL, 127
	.byte PAN, 64
	.byte N54, 60, 88
	.byte W54
	.byte FINE

	.byte 0x00
	.global song_114
song_114:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_001
	.4byte song_114_track1
