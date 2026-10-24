@ song_256: m4a song, header 0x086BD5A8
	.include "assets/sound/MPlayDef.inc"

	.global song_256_track1
song_256_track1:
	.byte KEYSH, 0
	.byte TEMPO, 60
	.byte VOICE, 51
	.byte VOL, 127
	.byte N04, 56, 127
	.byte W02
	.byte 52
	.byte W04
	.byte FINE

	.byte 0x00
	.global song_256
song_256:
	.byte 1  @ tracks
	.byte 0  @ blocks
	.byte 100  @ priority
	.byte 152  @ reverb
	.4byte voicegroup_003
	.4byte song_256_track1
